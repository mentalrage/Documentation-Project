** TARGET-REPORT-UID:00028O **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00028O MsvcLocaleFacetStaticStorage Source-Quality Reanalysis

Assignment: `B011-goal2-msvc-locale-facet-static-storage-source-quality-00028O-20260619`

Target: [UID:00028O] `by-memory/0x0067a79c-0x0067a7c4.MsvcLocaleFacetStaticStorage.md`

Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B011\research\00028O-MsvcLocaleFacetStaticStorage-source-quality.md`

Report-only status: no `by-*` documentation file and no `by-memory/-coverage-report.md` file was edited.

## Executive Decision

Keep [UID:00028O] as a non-reconstructable MSVC/Dinkumware runtime-data page.

The runtime/non-reconstructable classification remains correct. The target range is a zero-initialized writable data cluster used only by MSVC standard-library locale, numeric facet, ctype facet, iostream error-category, and one-time initialization helpers. It is not a NexusTK-authored game global, not a source-owned static object that should be declared in a product `.cpp`, and not a split child of the adjacent JsonCpp or MiniMap data.

Recommended metadata if the supervisor accepts implementation:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `90` |
| `CONFIDENCE` | `85` | `91` |
| `CANONICAL_OWNER` | `NONE` | `NONE` |
| `RECONSTRUCTABLE` | `FALSE` | `FALSE` |
| `EMITTER_UIDS` | blank | blank |
| `RECONSTRUCTION_CPP CODE` | blank | blank |

The score can rise because the dword-level layout, callback payload, xrefs, neighbor boundaries, runtime owner, and no-code proof are now much better supported. It should stay below `95` because IDA MCP was unavailable for a fresh live database query in this session and because exact Dinkumware decorated names for two facet helper functions remain best-supported inferences from vtable/data-flow evidence rather than direct symbol proof in the current session.

## Evidence Checked

Project and assignment constraints checked:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B011/goal.md`
- `tools/leaser/Agents/Agent-B011/notes.md`
- `by-structure.md`
- `inference_research.md`

Target and coverage docs checked:

- [UID:00028O] `by-memory/0x0067a79c-0x0067a7c4.MsvcLocaleFacetStaticStorage.md`
- `by-memory/-coverage-report.md` current row for [UID:00028O] and neighbor rows [UID:00028N]/[UID:00028P]
- `auto-generated/-ag-memory-coverage.md` rows for [UID:00028O], [UID:00028N], and [UID:00028P]
- `by-memory/-ignored.md` ignored-ledger entry for `0x0067a79c-0x0067a7c4`

Neighbor boundary docs checked:

- [UID:00028N] `by-memory/0x0067a770-0x0067a79c.JsonCppStaticValueData.md`
- [UID:00028P] `by-memory/0x0067a7c4-0x0067a7c8.g_pMiniMapDialog.md`
- [UID:0001Z8] `by-memory/0x0066d000-0x0069d000.DataSection.md`

Runtime/support docs checked:

- [UID:0001QE] `by-meta/client_libraries.md`
- [UID:0001ZT] `by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md`
- [UID:0001ZV] `by-memory/0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md`
- [UID:0001ZX] `by-memory/0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport.md`
- [UID:00024B] `by-memory/0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport.md`
- [UID:00024N] `by-memory/0x0060e174-0x0060e2b0.MsvcStlLocaleIostreamRdata.md`
- [UID:00024P] `by-memory/0x0060f038-0x0060f4c0.MsvcStlNumericRdata.md`
- [UID:00024J] `by-memory/0x0060c45a-0x0060c4ac.StaticRuntimeCleanupWrappersAfterUserPanePool.md`
- [UID:0002AJ] `by-memory/0x0069c044-0x0069d000.MsvcRuntimeMutableDataTail.md`

Searches checked:

- `rg` over `project-documentation` for `00028O`, `MsvcLocaleFacetStaticStorage`, `0067a79c`, `67A79C`, `0067a7a8`, `67A7A8`, `0067a7c4`, and `g_pMiniMapDialog`.
- `rg` over `project-documentation` for `dword_67A79C`, `dword_67A7A0`, `dword_67A7A4`, `unk_67A7A8`, `dword_67A7B4`, `dword_67A7B8`, `dword_67A7BC`, `dword_67A7C0`, `_Execute_once`, `once_flag`, `_Getctype`, `_Lockit`, and `facet`.
- `rg` over `Agent-B001/research`, `Agent-B002/research`, and `Agent-B011/research` for this UID/range/generated names. No prior B-agent source-quality report for this target was found.
- `rg` over `source-3/simroot_v2`, `core/data/readonly/wave2`, and `core/data/cache` for this range/name. No stronger project-owned source or generated source placement evidence was found.

IDA MCP check:

- Command attempted a JSON-RPC `tools/list` request to `http://127.0.0.1:13337/mcp`.
- Result: `IDA_MCP_UNAVAILABLE: Unable to connect to the remote server`.
- Consequence: this report relies on existing live-IDA documentation plus direct read-only PE byte/disassembly checks from `NexusTK.exe`. Claims from current-session binary analysis are marked as PE/Capstone evidence rather than fresh IDA MCP evidence.

Read-only PE evidence:

- Executable: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- PE image base: `0x00400000`
- Sections relevant to this target:
  - `.text`: `0x00401000-0x0060c600`, raw `0x400+0x20b600`
  - `.rdata`: `0x0060d000-0x0066c200`, raw `0x20ba00+0x5f200`
  - `.data`: virtual `0x0066d000-0x0069ce24`, raw `0x26ac00+0xd800`
- Target bytes `0x0067a79c-0x0067a7c4`: 40 bytes, all `00`.
- Context bytes `0x0067a770-0x0067a7d4`: 100 bytes, all `00`.
- Raw `.data` file content reaches `0x0067a800`; the target and immediate successor globals are inside file-backed zero bytes. Later runtime state such as `0x0069c110` and `0x0069c128` is virtual zero-initialized `.data`/BSS-style storage outside the raw file payload.

Current coverage row text checked:

```text
    - [UID:00028O][0x0067a79c-0x0067a7c4.MsvcLocaleFacetStaticStorage](by-memory/0x0067a79c-0x0067a7c4.MsvcLocaleFacetStaticStorage.md) 0x0067a79c-0x0067a7c4 | runtime static data | MsvcLocaleFacetStaticStorage : ignored : 85% : strong : MSVC STL locale/facet IDs, cached facet pointers, and once-flag payload.
```

## Raw PE Facts

All target dwords are initially zero:

| Address | Initial dword |
| --- | --- |
| `0x0067a79c` | `0x00000000` |
| `0x0067a7a0` | `0x00000000` |
| `0x0067a7a4` | `0x00000000` |
| `0x0067a7a8` | `0x00000000` |
| `0x0067a7ac` | `0x00000000` |
| `0x0067a7b0` | `0x00000000` |
| `0x0067a7b4` | `0x00000000` |
| `0x0067a7b8` | `0x00000000` |
| `0x0067a7bc` | `0x00000000` |
| `0x0067a7c0` | `0x00000000` |

Absolute-VA reference scan across `.text`, `.rdata`, and `.data` found these exact references:

| Target dword | Exact absolute refs found | Referencing addresses |
| --- | ---: | --- |
| `0x0067a79c` | 4 | `0x0043a773`, `0x0043a795`, `0x0043a7a8`, `0x0043a7b6` |
| `0x0067a7a0` | 4 | `0x00438e98`, `0x00438eb6`, `0x00438ec8`, `0x00438ed6` |
| `0x0067a7a4` | 2 | `0x00438d1f`, `0x00438e36` |
| `0x0067a7a8` | 1 | `0x0044240e` |
| `0x0067a7ac` | 2 | `0x00442404`, `0x0044242d` |
| `0x0067a7b0` | 0 | none as an immediate address; it is written indirectly as `[payload+4]` by callback `0x00437e20` |
| `0x0067a7b4` | 2 | `0x0043a778`, `0x0043a85e` |
| `0x0067a7b8` | 4 | `0x00436e8e`, `0x00436ead`, `0x00436ebf`, `0x00436ecd` |
| `0x0067a7bc` | 2 | `0x00438e9d`, `0x00438fb4` |
| `0x0067a7c0` | 2 | `0x00436e93`, `0x00436f75` |
| `0x0067a7c4` | 8 | `0x00450cf7`, `0x00450cff`, `0x00451776`, `0x00453662`, `0x005a59a2`, `0x005a607e`, `0x005a8130`, `0x005ac025` |

No RVA encodings for target dwords were found in the scanned sections. The only exact absolute references to `0x0067a7c4` belong to the separate `g_pMiniMapDialog` successor row, not to the runtime facet helpers.

Decoded current-session PE/Capstone target-reference instructions:

```asm
; 0x00436dd0 runtime numeric/facet helper
00436e8c: mov     ebx, dword ptr [0x67a7b8]
00436e92: mov     eax, dword ptr [0x67a7c0]
00436eab: cmp     dword ptr [0x67a7b8], ebx
00436ebe: mov     dword ptr [0x67a7b8], eax
00436ecb: mov     ebx, dword ptr [0x67a7b8]
00436f73: mov     dword ptr [0x67a7c0], esi

; 0x00438ce0 runtime ctype/facet helper
00438d1e: mov     eax, dword ptr [0x67a7a4]
00438e34: mov     dword ptr [0x67a7a4], esi

; 0x00438e60 runtime numeric punctuation/facet helper
00438e96: mov     edi, dword ptr [0x67a7a0]
00438e9c: mov     eax, dword ptr [0x67a7bc]
00438eb4: cmp     dword ptr [0x67a7a0], edi
00438ec7: mov     dword ptr [0x67a7a0], eax
00438ed4: mov     edi, dword ptr [0x67a7a0]
00438fb2: mov     dword ptr [0x67a7bc], esi

; 0x0043a6c0 runtime num_put/facet helper
0043a771: mov     ecx, dword ptr [0x67a79c]
0043a777: mov     eax, dword ptr [0x67a7b4]
0043a793: cmp     dword ptr [0x67a79c], 0
0043a7a7: mov     dword ptr [0x67a79c], eax
0043a7b4: mov     ecx, dword ptr [0x67a79c]
0043a85c: mov     dword ptr [0x67a7b4], esi

; 0x00442400 once wrapper
00442403: push    0x67a7ac
0044240d: push    0x67a7a8
0044242a: mov     dword ptr [eax + 4], 0x67a7ac
```

The callback passed to `std::_Execute_once`-style runtime code is visible at `0x00437e20`:

```asm
00437e20: push    ebp
00437e21: mov     ebp, esp
00437e23: mov     eax, dword ptr [ebp + 0xc]
00437e26: mov     dword ptr [eax], 0x60e214
00437e2c: mov     dword ptr [eax + 4], 5
00437e33: mov     eax, 1
00437e38: pop     ebp
00437e39: ret     0xc
```

The `0x00442400` wrapper is small and decisive:

```asm
00442400: push    ebp
00442401: mov     ebp, esp
00442403: push    0x67a7ac
00442408: push    0x437e20
0044240d: push    0x67a7a8
00442412: call    0x5c6650
00442417: add     esp, 0xc
0044241a: test    eax, eax
0044241c: je      0x5dce60
00442422: mov     eax, dword ptr [ebp + 8]
00442425: mov     ecx, dword ptr [ebp + 0xc]
00442428: mov     dword ptr [eax], ecx
0044242a: mov     dword ptr [eax + 4], 0x67a7ac
00442431: pop     ebp
00442432: ret
```

This proves the interpretation of `0x0067a7a8` as once-control storage and `0x0067a7ac-0x0067a7b4` as the lazily initialized category payload used as an `std::error_category`-style pointer in the returned object. The callback writes `0x0060e214` as a vtable pointer and `5` as the second category field. The absence of a direct absolute xref to `0x0067a7b0` is expected because it is reached as `payload+4`, not by an immediate address.

Relevant rdata checked from the read-only PE:

- `0x0060e214` lies inside the STL locale/iostream rdata range [UID:00024N]. The bytes at `0x0060e214` begin with function pointers including `0x0043b560`, `0x004424c0`, `0x00442440`, `0x0043f930`, `0x00441500`, and `0x00441530`, followed by the `iostream` and `iostream stream error` strings. This supports identifying the callback payload as the static iostream error-category object rather than arbitrary callback scratch.
- `0x0060f038` is documented by [UID:00024P] as the Dinkumware `num_put` vtable. Function `0x0043a6c0` constructs fallback facet storage with vptr `0x0060f038`.
- `0x0060f0d8` is documented by [UID:00024P] as the Dinkumware `num_get` vtable. Function `0x00436dd0` constructs fallback facet storage with vptr `0x0060f0d8`.
- `0x0060f07c` lies inside the numeric facet rdata group and is reached by function `0x00438e60` when constructing a size-`0x18` numeric-punctuation facet object. Its surrounding strings/constants include numeric punctuation and formatting evidence (`%p`, `Lu`, `Ld`, `lu`, `ld`, `eE`, `pP`, `.`), supporting the `std::numpunct<char>` role.
- `0x0060e1c8` lies inside the locale/iostream rdata group and is used by function `0x00438ce0` when constructing a size-`0x18` ctype facet object, with a table copied into the object. This supports the `std::ctype<char>` cached-facet role.

## Heuristic / Inference Reanalysis And Validation

### Classification

Best-supported classification: `third-party/runtime`, specifically MSVC/Dinkumware C++ standard-library locale/facet and iostream support static storage.

Reasons:

- Every direct reference into the target range comes from known MSVC STL/runtime helper islands or from a once-wrapper immediately adjacent to documented iostream support.
- Runtime code pages already classify the surrounding functions as non-reconstructable MSVC/Dinkumware support:
  - [UID:0001ZT] covers `0x004361b0-0x00439df9` and includes the `0x00436dd0`, `0x00438ce0`, and `0x00438e60` helper area as STL iostream/template support.
  - [UID:0001ZV] covers `0x00439ee0-0x0043e0a3` and records `0x0043a6c0` as an iostream-state/formatting helper with runtime diagnostic xrefs.
  - [UID:0001ZX] covers `0x00442090-0x00443a55` and records `0x00442400`, `0x00442440`, and `0x004424c0` as iostream/string support tied to `iostream` and `iostream stream error` literals.
- [UID:0001QE] already records the binary as statically embedding MSVC CRT/STL/Dinkumware support and says rebuilds should use a compatible MSVC-era toolchain/runtime model rather than reconstructing helper internals as NexusTK source.
- No project constructor, project destructor, UI class, packet handler, or NexusTK source-owned global writes the target range.
- The next project-owned dword starts at `0x0067a7c4` and has separate MiniMap lifecycle xrefs.

Rejected alternatives:

- `JsonCpp` static data: rejected. The preceding [UID:00028N] JsonCpp static value storage ends at `0x0067a79c`, and target xrefs are from MSVC locale/facet helpers rather than JsonCpp value/parser static initialization. JsonCpp uses standard-library streams and strings, but that does not make this runtime storage JsonCpp source.
- `MiniMapDialog` or nearby game globals: rejected. `g_pMiniMapDialog` starts at the successor dword `0x0067a7c4` and has eight separate MiniMap constructor/destructor/packet/UI refs. No MiniMap refs land inside `0x0067a79c-0x0067a7c4`.
- A source-authored NexusTK global object: rejected. The fields are all standard-library locale ids, cached facet pointers, once-control state, and iostream error-category payload. They are regenerated by runtime/template instantiation, not by hand-authored game code.
- Padding: rejected. Every dword except `0x0067a7b0` has direct or indirect runtime data-flow evidence. `0x0067a7b0` is not padding because the callback writes `[payload+4] = 5`.

### Dword-Level Layout And Source-Quality Names

Recommended source-quality layout:

| Range | Current generated name | Best-supported role | Evidence and caveats |
| --- | --- | --- | --- |
| `0x0067a79c-0x0067a7a0` | `dword_67A79C` | `std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::id` style locale facet id | Function `0x0043a6c0` reads/checks this id, initializes it from runtime counter `0x0069c110` under `_Lockit`, indexes the locale facet vector by it, and constructs/stores a fallback object with vptr `0x0060f038`. [UID:00024P] documents `0x0060f038` as the `num_put` vtable. Exact decorated template spelling should be copied from IDA if available in a future live session; this role is already very strong. |
| `0x0067a7a0-0x0067a7a4` | `dword_67A7A0` | `std::numpunct<char>::id` style locale facet id | Function `0x00438e60` reads/checks this id, initializes it from `0x0069c110` under `_Lockit`, indexes a locale facet vector, and constructs a size-`0x18` fallback object with vptr `0x0060f07c`. Numeric punctuation strings/constants in [UID:00024P] support the `numpunct<char>` inference. Direct decorated name was not available without IDA MCP, so record as best-supported rather than absolute. |
| `0x0067a7a4-0x0067a7a8` | `dword_67A7A4` | cached `std::ctype<char>` facet pointer | Function `0x00438ce0` reads this pointer, consults facet id storage at `0x0069c128`, indexes locale facet arrays, allocates size `0x18` when missing, sets vptr `0x0060e1c8`, copies ctype table/state into the object, and stores the result back to `0x0067a7a4`. The target dword is the cached pointer, not the id; the corresponding id is outside this target range. |
| `0x0067a7a8-0x0067a7ac` | `unk_67A7A8` | `std::once_flag` / once-control word for lazy iostream category initialization | Function `0x00442400` pushes `0x0067a7a8` as the first argument to runtime helper `0x005c6650`, with callback `0x00437e20` and payload `0x0067a7ac`. Existing target doc identifies this call as `std::_Execute_once`. |
| `0x0067a7ac-0x0067a7b0` | `unk_67A7AC` | first dword of static iostream error-category object; vptr set to `0x0060e214` | Callback `0x00437e20` writes `0x0060e214` to `[payload]`. Function `0x00442400` returns `&0x0067a7ac` as the category pointer in an error-code-like `{value, category}` pair. Rdata at `0x0060e214` is in the iostream error-category rdata region and is followed by `iostream`/`iostream stream error` literals. |
| `0x0067a7b0-0x0067a7b4` | unnamed/previously padding-like | second dword of static iostream error-category object; value/identifier initialized to `5` | Callback `0x00437e20` writes `5` to `[payload+4]`. No direct immediate xref exists because this is reached by pointer arithmetic from `0x0067a7ac`. Do not describe this dword as padding. |
| `0x0067a7b4-0x0067a7b8` | `dword_67A7B4` | cached fallback `std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > > *` facet pointer | Function `0x0043a6c0` reads this cache before constructing fallback storage and stores the allocated/facet object back at `0x0043a85c`. The object vptr is `0x0060f038`, documented as `num_put`. |
| `0x0067a7b8-0x0067a7bc` | `dword_67A7B8` | `std::num_get<char, std::istreambuf_iterator<char, std::char_traits<char> > >::id` style locale facet id | Function `0x00436dd0` reads/checks this id, initializes it from `0x0069c110` under `_Lockit`, indexes the locale facet vector, and constructs fallback storage with vptr `0x0060f0d8`. [UID:00024P] documents `0x0060f0d8` as the `num_get` vtable. |
| `0x0067a7bc-0x0067a7c0` | `dword_67A7BC` | cached fallback `std::numpunct<char> *` facet pointer | Function `0x00438e60` reads this cache, constructs a size-`0x18` numeric punctuation facet object when needed, and stores the result at `0x00438fb2`. |
| `0x0067a7c0-0x0067a7c4` | `dword_67A7C0` | cached fallback `std::num_get<char, std::istreambuf_iterator<char, std::char_traits<char> > > *` facet pointer | Function `0x00436dd0` reads this cache before fallback construction and stores the `num_get` object at `0x00436f73`. The object vptr is `0x0060f0d8`, documented as `num_get`. |

The best source-quality page name `MsvcLocaleFacetStaticStorage` remains adequate. A more precise but longer title such as `MsvcLocaleFacetAndIostreamErrorCategoryStaticStorage` would be accurate, but a rename is optional because the current title already covers the dominant locale/facet role and the page body can explain the once/category substructure. If a rename is desired later, use the validator workflow rather than hand-changing references.

### Locale/Facet ID Policy

The target range does not contain only facet ids. It contains a mixed, linker-adjacent runtime cluster:

- IDs inside target:
  - `0x0067a79c`: `num_put` id.
  - `0x0067a7a0`: `numpunct<char>` id.
  - `0x0067a7b8`: `num_get` id.
- Cached facet pointers inside target:
  - `0x0067a7a4`: cached `ctype<char>` pointer.
  - `0x0067a7b4`: cached `num_put` pointer.
  - `0x0067a7bc`: cached `numpunct<char>` pointer.
  - `0x0067a7c0`: cached `num_get` pointer.
- Runtime one-time category storage:
  - `0x0067a7a8`: once flag/control word.
  - `0x0067a7ac`: category object vptr.
  - `0x0067a7b0`: category object second field, initialized to `5`.

The `ctype<char>` facet id itself is not a target dword; function `0x00438ce0` uses `0x0069c128` as the id and `0x0067a7a4` as the cached pointer. This should be stated explicitly in any target-page update to avoid overstating the current page's title/table.

### `std::once_flag` And Callback Payload

The existing page correctly says `sub_442400` decompiles to an execute-once call, but it should be sharpened:

- `0x0067a7a8` is the once-control storage passed to runtime helper `0x005c6650`.
- `0x00437e20` is the once callback.
- `0x0067a7ac` is the callback payload and the object whose address is returned as the category pointer.
- The callback initializes:
  - `[0x0067a7ac] = 0x0060e214`
  - `[0x0067a7b0] = 5`
- `0x00442400` then writes an output pair:
  - output first dword = caller's error value argument at `[ebp+0xc]`
  - output second dword = `0x0067a7ac`

Best-supported source-facing interpretation: this is static MSVC/Dinkumware iostream error-category storage used to build an `std::error_code`-like pair, not a NexusTK callback payload. The exact decorated category class name should be taken from a future IDA MCP symbol query if available. The current evidence strongly supports `_Iostream_error_category` because the rdata vtable/string block contains `iostream` and `iostream stream error`, and support docs already classify the `0x00442400` family as iostream support.

### Caller Routes And Reachability

Runtime helper routes into the target:

- `0x00436dd0`: numeric input facet route. Uses `0x0067a7b8` and `0x0067a7c0`, initializes id under `_Lockit`, constructs fallback `num_get` with vptr `0x0060f0d8`, and caches it.
- `0x00438ce0`: ctype facet route. Uses `0x0067a7a4` cache and `0x0069c128` id, constructs fallback ctype with vptr `0x0060e1c8`, and caches it.
- `0x00438e60`: numeric punctuation facet route. Uses `0x0067a7a0` and `0x0067a7bc`, initializes id under `_Lockit`, constructs fallback `numpunct<char>`-style object with vptr `0x0060f07c`, and caches it.
- `0x0043a6c0`: numeric output facet route. Uses `0x0067a79c` and `0x0067a7b4`, initializes id under `_Lockit`, constructs fallback `num_put` with vptr `0x0060f038`, and caches it.
- `0x00442400`: execute-once route for static iostream error-category payload at `0x0067a7ac`.
- `0x00437e20`: once callback that writes the payload object.

Support documentation already records that the functions are reached by JsonCpp/STL stream/numeric consumers. This is runtime/template support reachability, not game source ownership. No direct caller route from MiniMap, UI singleton initialization, packet code, or game-specific constructor writes into the target.

### Owner And Source Placement

Recommended documentation owner: keep `CANONICAL_OWNER:NONE`.

Rationale:

- This page is not owned by any NexusTK class, global page, or by-file source root.
- It belongs to the external/toolchain dependency policy recorded in [UID:0001QE] `client_libraries.md` and the ignored-ledger treatment in [UID:0000VN] `by-memory/-ignored.md`.
- Existing analogous runtime pages use `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, and blank C++.
- Assigning a by-file owner such as `JsonCpp` would be misleading. JsonCpp may be a major consumer of iostream/string/locale support, but this exact storage is MSVC STL runtime state.
- Assigning `MiniMapDialog` or any UI/global owner would be wrong because the successor MiniMap singleton starts after the half-open end.

Recommended rebuild handling wording: `third-party/runtime`, regenerated by compatible C++ standard-library/runtime support.

### Split And Range Decision

Keep the half-open range as `0x0067a79c-0x0067a7c4`.

Boundary evidence:

- Predecessor [UID:00028N] ends at `0x0067a79c`; its page records the successor as a separate MSVC locale/facet static slot with xrefs in `0x0043a6c0`.
- Target starts exactly at the first runtime `num_put` id dword, `0x0067a79c`.
- Target ends immediately before `0x0067a7c4`.
- Successor [UID:00028P] starts at `0x0067a7c4`, has eight MiniMap-specific xrefs, and is reconstructable project singleton storage.
- The next dword after successor, `0x0067a7c8`, has many `g_pConfig` references and is separate again.

Do not split the target into child by-memory pages. A field-level layout table is better than page-level fragmentation because all target subranges are non-reconstructable runtime support, no subrange has a NexusTK owner/emitter, and the static objects are interleaved by compiler/linker layout rather than by a project source module. If a future final-audit pass wants even finer runtime pages, the only defensible internal grouping would be:

- `0x0067a79c-0x0067a7a8`: numeric/ctype id/cache dwords.
- `0x0067a7a8-0x0067a7b4`: once flag plus iostream error-category static object.
- `0x0067a7b4-0x0067a7c4`: numeric facet id/cache dwords.

That split is not recommended now because it would add three non-emitting runtime pages without improving reconstruction readiness.

### Open Questions Closed

- Whether runtime/non-reconstructable classification remains correct: closed as yes.
- Whether target should emit NexusTK C++: closed as no.
- Whether owner should be a NexusTK class/file/global: closed as no; keep `NONE`.
- Whether `0x0067a7b0` is padding: closed as no; it is written by the once callback as payload field `+4`.
- Whether `0x0067a7c4` belongs to this target: closed as no; it is [UID:00028P] `g_pMiniMapDialog`.
- Whether a child split is needed: closed as no for current documentation quality; field table is sufficient.
- Whether `dword_67A7A4` is an id: closed as no; it is a cached ctype facet pointer, with the related id at `0x0069c128` outside target.
- Whether exact Dinkumware decorated names are all directly proven in this session: partially closed. `num_put` and `num_get` are directly supported by existing rdata docs and vtable addresses. `numpunct<char>` and `ctype<char>` are very strong from vtable/constructor/data-flow evidence but should still be described as best-supported unless a future IDA MCP `list_globals` or names query confirms exact decorated symbol names.

### Negative Evidence

- No prior B001/B002/B011 source-quality report for this target was found.
- No `simroot_v2`, Wave2 readonly, or Wave3 cache source file evidence tied this target to NexusTK-owned source.
- No exact RVA references to target dwords were found in the scanned PE sections.
- No `.rdata` or `.data` pointer tables were found that make this a vtable, game callback table, or project-owned object table.
- No project-owned constructor/destructor/helper writes any dword inside `0x0067a79c-0x0067a7c4`.
- `0x0067a7c4` references are separate MiniMap singleton xrefs; they validate the half-open end rather than expanding the runtime target.

## C++ Readiness And No-Code Proof

First-draft C++ eligibility: not eligible.

Exact no-code/runtime proof:

1. [UID:00028O] is `RECONSTRUCTABLE:FALSE`.
2. The page has no valid source owner and should keep `CANONICAL_OWNER:NONE`.
3. The page has no emitter route and should keep `EMITTER_UIDS` blank.
4. The target is compiler/runtime standard-library mutable static storage, not a NexusTK-authored source object.
5. Equivalent data is created by MSVC/Dinkumware runtime/template support when the rebuilt project links or statically embeds compatible standard-library code.
6. Handwriting these exact dwords in NexusTK source would freeze compiler-emitted runtime internals into product source and would conflict with the documentation policy in [UID:0001QE] and by-structure runtime handling.
7. Comment-only emitters are not appropriate here. This is not an eligible reconstructable page with a special no-code emitter; it is an ignored runtime data page.

No `RECONSTRUCTION_CPP CODE` should be added. The correct source-level action is to preserve ordinary use of iostreams/locales/numeric conversion/error categories in JsonCpp/runtime-consuming code and let the selected toolchain provide the corresponding storage.

## Support Docs Needing Incorporation

Target page [UID:00028O] should incorporate:

- The refined dword-level layout table above.
- The PE byte facts: all target bytes zero, file-backed raw `.data` bytes through `0x0067a800`, target size `0x28`.
- The exact xref counts per target dword.
- The fact that `0x0067a7b0` is indirectly initialized and should not be called padding.
- The `0x00442400`/`0x00437e20` once-wrapper/callback proof.
- The boundary evidence against [UID:00028P] `g_pMiniMapDialog`.
- The no-code proof and current IDA MCP unavailability caveat.

Support pages that would benefit from small cross-reference additions if a supervisor implementation pass touches them:

- [UID:00024N] `MsvcStlLocaleIostreamRdata`: optionally add [UID:00028O] as the mutable static-storage counterpart for the iostream error-category and ctype/locale data.
- [UID:00024P] `MsvcStlNumericRdata`: optionally add [UID:00028O] as the mutable static-storage counterpart for `num_put`, `numpunct`, and `num_get` facet ids/caches.
- [UID:0001ZT] and [UID:0001ZV]: no required change, but they are support xrefs for the runtime helper functions that access this data.
- [UID:0001ZX]: no required change, but it is the support xref for the `0x00442400` once/category helper.
- `by-memory/-ignored.md`: optionally refine the existing `0x0067a79c-0x0067a7c4` entry to mention the iostream error-category payload and the exact non-padding role of `0x0067a7b0`.
- `by-memory/-coverage-report.md`: supervisor-owned row update proposed below.

No support doc needs a reconstructable code route as a result of this target.

## Target/Support Implementation Checklist

Target page [UID:00028O]:

- Set `COMPLETION:90`.
- Set `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:NONE`.
- Keep `RECONSTRUCTABLE:FALSE`.
- Keep `EMITTER_UIDS:` blank.
- Keep `RECONSTRUCTION_CPP CODE` blank.
- Update the summary to say this is MSVC/Dinkumware locale/facet static storage plus lazy iostream error-category storage.
- Replace the current broad layout with the dword-level layout from this report.
- Add evidence bullets for the PE raw bytes, xref counts, disassembly route summaries, and once callback.
- Explicitly state that `0x0067a7b0` is part of the error-category payload and not padding.
- Explicitly state that `0x0067a7a4` is a cached ctype pointer while its id is outside the target at `0x0069c128`.
- Keep the range unchanged at `0x0067a79c-0x0067a7c4`.
- Add or keep cross-references to [UID:00028N], [UID:00028P], [UID:0001Z8], [UID:0001QE], [UID:0001ZT], [UID:0001ZV], [UID:0001ZX], [UID:00024N], and [UID:00024P].

Support docs:

- Update `by-memory/-ignored.md` only if the implementation pass is allowed to touch support by-memory docs; add the refined field roles and no-code proof in the existing ignored entry.
- Update [UID:00024N] and [UID:00024P] only if adding reciprocal cross-references is in scope.
- Do not edit `by-memory/-coverage-report.md` directly from a B-agent report pass; use the supervisor-owned replacement row below.
- Do not add an emitter or generated code route to any support page because of this target.

Validator after implementation:

- Run scoped validator on the target page.
- If support docs are edited, run scoped validators on each edited support page.
- If a supervisor applies the coverage row, run scoped validator on `by-memory/-coverage-report.md` or the applicable coverage refresh command according to supervisor workflow.

## Exact Supervisor-Owned Coverage Row Text

Current row:

```text
    - [UID:00028O][0x0067a79c-0x0067a7c4.MsvcLocaleFacetStaticStorage](by-memory/0x0067a79c-0x0067a7c4.MsvcLocaleFacetStaticStorage.md) 0x0067a79c-0x0067a7c4 | runtime static data | MsvcLocaleFacetStaticStorage : ignored : 85% : strong : MSVC STL locale/facet IDs, cached facet pointers, and once-flag payload.
```

Recommended replacement row:

```text
    - [UID:00028O][0x0067a79c-0x0067a7c4.MsvcLocaleFacetStaticStorage](by-memory/0x0067a79c-0x0067a7c4.MsvcLocaleFacetStaticStorage.md) 0x0067a79c-0x0067a7c4 | runtime static data | MsvcLocaleFacetStaticStorage : ignored : 90% : very strong : MSVC/Dinkumware locale/facet static storage: num_put/numpunct/num_get facet ids and cached pointers, ctype cached pointer with id outside range, std::once_flag plus lazy iostream error-category payload; PE xref scan confirms only runtime helper refs and exact boundary before g_pMiniMapDialog.
```

## Scoped Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00028O-MsvcLocaleFacetStaticStorage-source-quality-removed.md](00028O-MsvcLocaleFacetStaticStorage-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`
- `mode: file`
- `apply: False`
- `scanned markdown files: 1`
- `ok: 1`
- Target line: `ok           00028O by-memory/0x0067a79c-0x0067a7c4.MsvcLocaleFacetStaticStorage.md UID header exists`
- Dry-run note: `stats_incremental_skip 00028O project-level/-auto-completion-stats.md dry run; pass --apply to update generated stats rows`
- No target-page validation error was reported. The validator also printed existing autogen no-op/emitter status lines unrelated to this target.

## Final Recommendation

[UID:00028O] should be updated as a higher-quality ignored runtime-data page, not promoted to reconstructable source. The best-supported source-quality names are runtime/descriptive names for documentation only:

- `std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::id` style id at `0x0067a79c`
- `std::numpunct<char>::id` style id at `0x0067a7a0`
- cached `std::ctype<char> *` at `0x0067a7a4`
- `std::once_flag` at `0x0067a7a8`
- static iostream error-category object at `0x0067a7ac-0x0067a7b4`
- cached `std::num_put *` at `0x0067a7b4`
- `std::num_get<char, std::istreambuf_iterator<char, std::char_traits<char> > >::id` style id at `0x0067a7b8`
- cached `std::numpunct<char> *` at `0x0067a7bc`
- cached `std::num_get *` at `0x0067a7c0`

Keep `0x0067a7c4` outside the range as [UID:00028P] `g_pMiniMapDialog`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/00028O-MsvcLocaleFacetStaticStorage-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00028O"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00028O-MsvcLocaleFacetStaticStorage-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/00028O-MsvcLocaleFacetStaticStorage-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00028O"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
