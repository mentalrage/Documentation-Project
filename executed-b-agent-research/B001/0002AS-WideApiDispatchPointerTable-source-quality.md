** TARGET-REPORT-UID:0002AS **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# 0002AS WideApiDispatchPointerTable Source-Quality Report

Agent: Agent-B001  
Assignment: UID0002AS implementation callback after supervisor Gate 1 acceptance  
Mode: implementation callback complete; original report-only research preserved with implementation delta applied  
Target: [UID:0002AS] `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`  
Report path: `tools/leaser/Agents/Agent-B001/research/0002AS-WideApiDispatchPointerTable-source-quality.md`  
MCP endpoint used: `http://127.0.0.1:13337/mcp`  
Active IDB session used for implementation callback: `ba171fe4`  
Historical Gate 1 research session: `cbc24146` is stale/superseded and was not reused after the supervisor MCP incident notice.

## Finalized Report / Current Recommendation

Current recommendation: promote [UID:0002AS] from an empty PlatformApi dispatch-storage marker to a source-ready first-draft declaration block for the main wide API dispatch pointer body.

Final disposition: keep the existing target range `0x0069be14-0x0069bec4`, keep canonical owner [UID:0000TQ] `WideApiDispatchTable`, keep emitter route through [UID:0000TQ] to [UID:0000ML] `PlatformApi`, and populate only the target's formal `RECONSTRUCTION_CPP CODE` block with grouped PlatformApi function-pointer globals for the 44 dword slots in this exact range.

Implementation outcome after supervisor acceptance:

- Applied target `COMPLETION:90`, `CONFIDENCE:90`.
- Preserved `CANONICAL_OWNER:0000TQ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000TQ`, and blank `EMITTER_POSITION_OPTIONAL`.
- Inserted the exact formal C++ block from this report into the target formal `RECONSTRUCTION_CPP CODE` block.
- Incorporated current MCP session `ba171fe4` evidence for zero-initialized storage, exact initializer writes, live consumers, split boundary, and no source type/global symbol proof. Historical `cbc24146` evidence remains report provenance only.
- Updated stale/incomplete support docs and left [UID:0000FE] `by-class/UniAPIInit.md` unchanged because it already had equal-or-better source-shape detail.

Confidence: high for range, owner, slot identities, and zero-initialized storage; medium-high for final source-facing global names because the binary has no original global/typedef symbols.

## Supporting Research

- Lifecycle/status notes: no current UID0002AS report artifact existed in the active Agent-B001 research folder before this report. Stale prior worker messages for other UIDs were ignored.
- The target is now current in generated reports after validator refresh: `auto-generated/-ag-research-tracker.md` lists UID0002AS as `90/90`, average `90.0`, reconstructable `true`; `auto-generated/-ag-memory-coverage.md` lists it as `coded`, routed through generated output `auto-generated/NexusTK/platform/PlatformApi.cpp`.
- Existing by-* docs already establish the broad owner chain: [UID:0002AS] -> [UID:0000TQ] `WideApiDispatchTable` -> [UID:0000ML] `PlatformApi`.
- Pre-callback generated `auto-generated/NexusTK/platform/PlatformApi.cpp` was read-only evidence only: command id `000000006525`, refreshed `2026-07-04T19:41:02-04:00`, and still had `// UID:0002AS ... Completion:87 | Confidence:87 | Empty Emitter Marker`.
- Post-callback generated output was inspected read-only after scoped validators. `auto-generated/NexusTK/platform/PlatformApi.cpp` header reports validator command id `000000006629`, refreshed `2026-07-04T21:06:45-04:00`; UID0002AS emits the accepted declarations at generated lines 16-60, including `g_pfnWideOpenFile` and `g_pfnImmGetCandidateListW`, and no UID0002AS empty marker remains.
- Prior executed reports used as support, not as substitutes for current MCP proof: B007 UID0000FE `UniAPIInit` source-quality, B014 UID0001KE `UniAPIInit` raw aggregate, B002 UID000249 PlatformStringConversionHelpers, B001 UID00018E InputMan, B013 UID00019T ProfileLoadAndLegacyImport, and B007 UID0002H2 ApplicationRunMessageLoop.
- An unexecuted/current Agent-B015 research report for UID0000WD was found in the tree but was not treated as authoritative for this UID0002AS recommendation.

## Target

- Target UID: `0002AS`.
- Target path: `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`.
- Source queue/report row after validator refresh: `auto-generated/-ag-research-tracker.md` UID0002AS row at `90/90`; `auto-generated/-ag-memory-coverage.md` marks UID0002AS `coded`.
- Supervisor classification: Gate 1 accepted; implementation callback applied. No `execute_report`, execute dry-run/probe/status variant, lifecycle/archive command, report move, or registry lifecycle command was run.
- Current scores and parent state after callback: target `90/90`, direct parent [UID:0000TQ] `WideApiDispatchTable` `90/86`, source file [UID:0000ML] `PlatformApi` `88/85`. [UID:0000WD] was later touched by B015 after B001 released leases and currently reads `87/91`; B001 did not revert or edit under B015's lease.

## Current Target State

- Applied metadata: `COMPLETION:90`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000TQ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000TQ`, blank `EMITTER_POSITION_OPTIONAL`.
- Owner/emitter/reconstructable state remains correct. The target is PlatformApi dispatch storage owned through [UID:0000TQ], not consumer-owned storage.
- C++/emitter state after callback: target formal `RECONSTRUCTION_CPP CODE` block contains the exact accepted grouped declarations. Generated PlatformApi output emits the declarations and no UID0002AS empty marker remains.
- Remaining open questions/blockers: exact original typedef names and some final global spellings remain inferred; this is documented as the reason for `90/90` rather than a blocker to first-draft formal declarations.
- Related target/support docs checked: [UID:0000TQ] `by-global/WideApiDispatchTable.md`, [UID:0000ML] `by-file/PlatformApi.md`, [UID:0000FE] `by-class/UniAPIInit.md`, [UID:0000WD] `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`, [UID:0001Q1] `by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md`, [UID:0002A6] `by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md`, and current generated `auto-generated/NexusTK/platform/PlatformApi.cpp`.
- Current artifact/lifecycle status: implementation callback is complete in the same live Agent-B001 report artifact. This report is ready for supervisor Gate 2 review; implementation was performed only after Gate 1 acceptance.

## Heuristic / Inference Reanalysis And Validation

The existing owner/emitter route is valid. The table is data storage in the PlatformApi dispatch cluster, is initialized by [UID:0000WD] `sub_41A280`, and is consumed by many file, registry, window, message-loop, version, and IME paths. Consumer xrefs do not transfer ownership because they read or call individual slots and do not initialize the cluster.

The source declaration style should be grouped PlatformApi function-pointer globals. Current docs already reject raw `dword_69BE*` names and consumer-local declarations, and MCP still shows direct absolute slot references rather than base-plus-index access. That means a forced runtime `struct WideApiDispatchTable` is weaker than grouped globals for source C++.

The formal C++ block should cover only `0x0069be14-0x0069bec4`. It must not include the sibling `0x0069bec4` `SendMessageW` slot or the tail slots `0x0069bec8`/`0x0069becc`; those are separate exact memory pages. The target can still mention the neighboring split to prevent accidental merge.

The range is 44 dword slots: `0x0069bec4 - 0x0069be14 = 0xb0`, and MCP `int_convert` confirms `0xb0` is decimal `176`; `176 / 4 = 44`, with `44` confirmed as `0x2c`.

The binary storage is zero-initialized. MCP `get_bytes` for `0x0069be14` size `176` returned all zero bytes, and `get_bytes` for `0x0069bec4` size `12` also returned zero bytes for the adjacent sibling/tail region. Therefore the C++ declarations should not use sentinel `-1` initializers.

Final source-facing global names remain inferred where no generated consumer already fixed a name. For already accepted names, use the existing project spellings: `g_pfnWideOpenFile`, `g_pfnWideStat`, `g_pfnReadUtf16CodeUnitFromFile`, `g_pfnPeekMessage`, `g_pfnDefWindowProcW`, `g_pfnPostMessageW`, `g_pfnImmGetCompositionStringW`, and `g_pfnImmGetCandidateListW`. For the remaining slots, use the same `g_pfn<NameW>` pattern already used in table docs and generated consumers.

Rejected alternatives:

- Do not leave C++ blank solely because exact typedef names are not proven. Direct slot identities, zero-initialized data, owner route, and accepted `g_pfn*` naming convention are now sufficient for first-draft declarations.
- Do not emit raw `dword_69BE*` declarations. The slots are named dispatch pointers with known installed targets.
- Do not move declarations to StdioFile, Application, Browser, InputMan, RegistryConfig, ProfileStorage, or other consumer docs. Those are consumers.
- Do not move ownership to raw/generated [UID:0001KE] `0x005995b0-0x00599a34.UniAPIInit`. Current MCP says `0x005995b0` is not a function, and existing accepted reports treat it as a projection/raw aggregate rather than the source owner.
- Do not merge UID0001Q1 or UID0002A6 into this target during this pass. The split pages are intentional high-risk neighboring storage pages.

## Evidence Standards Used

- IDA MCP active-session proof: `idb_list` and `server_health`.
- IDA MCP function/range proof: `lookup_funcs`, `decompile`, `disasm`.
- IDA MCP storage proof: `get_bytes`, `int_convert`.
- IDA MCP xref proof: `xrefs_to` for representative slots and neighboring split slots.
- IDA MCP import/name/type proof: `entity_query` for imports, globals, names, and `type_query` for missing original source symbols.
- Documentation proof: current target/support by-* docs, generated read-only output, generated tracker rows, and prior executed B-agent reports.
- Negative evidence: no IDA names/globals/types matching `WideApi`, `g_pfn`, or `UniAPI` in the checked catalogs; `0x005995b0` is not a function; `0x0069bec4`/tail are separate sibling targets; consumer xrefs do not own storage.

The evidence is strong enough for `90/90` because every slot target in the target range is directly installed by the initializer and the storage bytes are current-IDB verified. It is not higher because original source typedef/global spellings are still inferred and the full dispatch family remains split across neighboring docs.

## Evidence Checked

### MCP Health And Session State

- Implementation callback current session: `idb_list` returned one active session `ba171fe4`, filename `NexusTK.exe.i64`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, backend `worker`, worker pid `12196`.
- `server_health(database=ba171fe4)` returned `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- Historical Gate 1 research session: `cbc24146` previously returned active/healthy proof, but the supervisor reported it stale before implementation. It was not reused for callback edits or verification.

### Implementation MCP Refresh On `ba171fe4`

- `lookup_funcs` on `ba171fe4`: `0x0041a280` -> `sub_41A280`, size `0x228`; `0x0041a4a8`, `0x005995b0`, `0x0069be14`, `0x0069bec4`, and `0x0069bec8` -> not functions.
- `get_bytes` on `ba171fe4`: `0x0069be14` size `176` returned all zero bytes; `0x0069bec4` size `12` returned all zero bytes for the sibling `SendMessageW` slot and tail dwords.
- `decompile 0x0041a280` on `ba171fe4` reconfirmed the full dispatch assignment sequence, including `ReadUtf16CodeUnitFromFile` at `0x0069be1c`, wide Win32 API slots through `SetCurrentDirectoryW`, `_wfopen` at `0x0069be14`, `_wstat64i32` at `0x0069be18`, version/IME thunks through `0x0069bec0`, sibling `SendMessageW` at `0x0069bec4`, tail `GetLocaleInfoW` and `SetFileAttributesW`, and final `atexit(sub_60C440)`.
- Wrapper lookups on `ba171fe4`: `__wfopen` `0x005d253a`, `__wstat64i32` `0x005e25aa`, `GetFileVersionInfoSizeW` `0x005c5c8d`, `GetFileVersionInfoW` `0x005c5c93`, `VerQueryValueW` `0x005c5c99`, `ImmGetCompositionStringW` `0x005c5cc9`, `ImmGetCandidateListW` `0x005c5ce7`, cleanup wrapper `sub_60C440` `0x0060c440`.
- Name/type negative checks on `ba171fe4`: zero globals and zero names in `0x0069be14-0x0069bed0`; zero `type_query` hits for `*WideApi*`, `*g_pfn*`, and `*UniAPI*`.
- Representative current xrefs on `ba171fe4` include initializer refs plus live consumers for `_wfopen` `0x0069be14`, `_wstat64i32` `0x0069be18`, reader `0x0069be1c`, `CreateFileW` `0x0069be34`, `CreateDirectoryW` `0x0069be5c`, `DeleteFileW` `0x0069be60`, `GetCurrentDirectoryW` `0x0069be70`, `PeekMessageW` `0x0069be8c`, `PostMessageW` `0x0069be90`, version/IME slots, sibling `SendMessageW`, and tail slots.

### MCP Target And Initializer Evidence

- `lookup_funcs`:
  - `0x0041a280` -> `sub_41A280`, size `0x228`.
  - `0x0041a4a8` -> not a function, confirming exclusive end.
  - `0x00599570` -> `sub_599570`, size `0x37`.
  - `0x005995b0` -> not a function, supporting raw/projection exclusion.
  - `0x0069be14`, `0x0069bec4`, and `0x0069bec8` -> not functions, confirming data storage.
- `decompile 0x0041a280` confirms `GetVersionExA`, unconditional `unk_69BE1C = sub_599570`, NT branch `dwPlatformId == 2`, all main-table writes from `0x0069be20` through `0x0069bec0`, neighboring `unk_69BEC4 = SendMessageW`, tail `unk_69BEC8 = GetLocaleInfoW`, `unk_69BECC = SetFileAttributesW`, and final `atexit(sub_60C440)`.
- `disasm 0x0041a280` confirms the same exact store addresses, including:
  - `0x0041a2b1` -> `unk_69BE1C = sub_599570`.
  - `0x0041a2c6` through `0x0041a424` -> imported wide Win32 entries through `SetCurrentDirectoryW`.
  - `0x0041a42e` -> `unk_69BE14 = __wfopen`.
  - `0x0041a438` -> `unk_69BE18 = __wstat64i32`.
  - `0x0041a442` through `0x0041a46a` -> version and IME thunk slots.
  - `0x0041a474` -> neighboring `unk_69BEC4 = SendMessageW`.
  - `0x0041a47e` and `0x0041a488` -> tail `GetLocaleInfoW` and `SetFileAttributesW`.
- `get_bytes 0x0069be14 size 176` returned all zero bytes. `get_bytes 0x0069bec4 size 12` returned all zero bytes for neighboring split storage.
- `int_convert` confirms `0xb0 == 176` and `44 == 0x2c`.
- `decompile 0x00599570` reports `sub_599570(FILE *Stream)` returning a 16-bit value, checking `feof(Stream)`, reading two bytes with `fread`, and returning the read value. Existing generated PlatformApi already names this helper `ReadUtf16CodeUnitFromFile`.

### MCP Slot Assignment Evidence

Initializer/decompiler slot map for this target range:

| Slot | Store address | Installed target |
| --- | ---: | --- |
| `0x0069be14` | `0x0041a42e` | `__wfopen` / `_wfopen` wrapper |
| `0x0069be18` | `0x0041a438` | `__wstat64i32` / `_wstat64i32` wrapper |
| `0x0069be1c` | `0x0041a2b1` | `sub_599570` / `ReadUtf16CodeUnitFromFile` |
| `0x0069be20` | `0x0041a2c6` | `FindWindowW` |
| `0x0069be24` | `0x0041a2d0` | `OpenFileMappingW` |
| `0x0069be28` | `0x0041a2da` | `CreateMutexW` |
| `0x0069be2c` | `0x0041a2e4` | `CreateDialogParamW` |
| `0x0069be30` | `0x0041a2ee` | `LoadLibraryW` |
| `0x0069be34` | `0x0041a2f8` | `CreateFileW` |
| `0x0069be38` | `0x0041a302` | `CreateProcessW` |
| `0x0069be3c` | `0x0041a30c` | `CreateEventW` |
| `0x0069be40` | `0x0041a316` | `RegisterClassW` |
| `0x0069be44` | `0x0041a320` | `CreateWindowExW` |
| `0x0069be48` | `0x0041a32a` | `CreateFileMappingW` |
| `0x0069be4c` | `0x0041a334` | `CreateSemaphoreW` |
| `0x0069be50` | `0x0041a33e` | `DefWindowProcW` |
| `0x0069be54` | `0x0041a348` | `RegisterClipboardFormatW` |
| `0x0069be58` | `0x0041a352` | `CharUpperBuffW` |
| `0x0069be5c` | `0x0041a35c` | `CreateDirectoryW` |
| `0x0069be60` | `0x0041a366` | `DeleteFileW` |
| `0x0069be64` | `0x0041a370` | `DispatchMessageW` |
| `0x0069be68` | `0x0041a37a` | `FindFirstFileW` |
| `0x0069be6c` | `0x0041a384` | `FormatMessageW` |
| `0x0069be70` | `0x0041a38e` | `GetCurrentDirectoryW` |
| `0x0069be74` | `0x0041a398` | `GetModuleFileNameW` |
| `0x0069be78` | `0x0041a3a2` | `GetModuleHandleW` |
| `0x0069be7c` | `0x0041a3ac` | `GetWindowsDirectoryW` |
| `0x0069be80` | `0x0041a3b6` | `GlobalGetAtomNameW` |
| `0x0069be84` | `0x0041a3c0` | `LoadCursorW` |
| `0x0069be88` | `0x0041a3ca` | `LoadIconW` |
| `0x0069be8c` | `0x0041a3d4` | `PeekMessageW` |
| `0x0069be90` | `0x0041a3de` | `PostMessageW` |
| `0x0069be94` | `0x0041a3e8` | `RegCreateKeyExW` |
| `0x0069be98` | `0x0041a3f2` | `RegDeleteKeyW` |
| `0x0069be9c` | `0x0041a3fc` | `RegEnumValueW` |
| `0x0069bea0` | `0x0041a406` | `RegQueryInfoKeyW` |
| `0x0069bea4` | `0x0041a410` | `RegQueryValueExW` |
| `0x0069bea8` | `0x0041a41a` | `RegSetValueExW` |
| `0x0069beac` | `0x0041a424` | `SetCurrentDirectoryW` |
| `0x0069beb0` | `0x0041a442` | `GetFileVersionInfoSizeW` thunk |
| `0x0069beb4` | `0x0041a44c` | `GetFileVersionInfoW` thunk |
| `0x0069beb8` | `0x0041a456` | `VerQueryValueW` thunk |
| `0x0069bebc` | `0x0041a460` | `ImmGetCompositionStringW` thunk |
| `0x0069bec0` | `0x0041a46a` | `ImmGetCandidateListW` thunk |

### MCP Xref Evidence

Representative `xrefs_to` summary:

- `0x0069be14`: initializer `0x0041a42e`; at least 40 xrefs with more results, including `sub_422020`, `sub_4225A0`, `sub_4229F0`, `sub_454150`, `sub_456540`, `sub_456A90`, `sub_48FCA0`, and others. This confirms broad live `_wfopen` consumption.
- `0x0069be18`: 5 xrefs, including initializer `0x0041a438`, `sub_5820D0`, and `sub_582460`.
- `0x0069be1c`: 11 xrefs, including initializer `0x0041a2b1` and multiple `sub_4F9280` reads, plus raw/projection refs near `0x5995ea`/`0x599821`.
- `0x0069be34`: 27 xrefs, including initializer `0x0041a2f8` and consumers `sub_41A750`, `sub_453AA0`, `sub_4639D0`, `sub_47CD80`, `sub_49BE80`, `sub_507C90`.
- `0x0069be5c`: at least 40 xrefs with more results, including initializer `0x0041a35c` and profile/screenshot/path consumers.
- `0x0069be60`: 9 xrefs, including initializer `0x0041a366`, `sub_41A750`, `sub_453AA0`, `sub_4AB510`, `sub_4F9280`, `sub_50ABA0`.
- `0x0069be70`: 11 xrefs, including initializer `0x0041a38e`, `_WinMain@16`, `sub_4F9280`, `sub_4F95B0`, `sub_50FEB0`.
- `0x0069be8c`: 8 xrefs, including initializer `0x0041a3d4`, `sub_464CD0` calls at `0x00464d63`/`0x00464de1`, `sub_4F5710`, and `sub_596E10`.
- `0x0069be50`: 6 xrefs, including initializer `0x0041a33e`, `sub_465F20`, `sub_46FCB0`, `sub_4E8DE0`.
- `0x0069be90`: 17 xrefs, including initializer `0x0041a3de`, `sub_46F010`, `sub_4AA1D0`, `sub_4E8CF0`, browser thread/message consumers, and InputMan/Event consumers.
- `0x0069beb0`: 5 xrefs, including initializer `0x0041a442` and version helper consumers `sub_465320`, `sub_465430`.
- `0x0069bebc`: 5 xrefs, including initializer `0x0041a460` and InputMan composition helper `sub_4E9510`.
- `0x0069bec0`: 6 xrefs, including initializer `0x0041a46a` and InputMan candidate-list helper `sub_4E8DE0`.
- Neighbor `0x0069bec4`: 17 xrefs, including initializer `0x0041a474`, browser/message consumers, and raw/projection refs; this remains separate [UID:0001Q1].
- Neighbor tail `0x0069bec8`: 4 xrefs, including initializer `0x0041a47e`; this remains separate [UID:0002A6].
- Neighbor tail `0x0069becc`: 4 xrefs, including initializer `0x0041a488`; this remains separate [UID:0002A6].

### MCP Import / Local Wrapper Evidence

- `entity_query imports` for the relevant wide API names found 39 imports, including ADVAPI32 registry entries, KERNEL32 file/path/event entries, and USER32 window/message entries. Examples: `RegSetValueExW` at `0x60d000` ADVAPI32; `CreateFileW` at `0x60d274` KERNEL32; `PeekMessageW` at `0x60d380` USER32; `SendMessageW` at `0x60d384` USER32; `FindWindowW` at `0x60d410` USER32.
- `lookup_funcs` for local wrappers/thunks:
  - `0x005d253a` -> `__wfopen`, size `0x17`.
  - `0x005e25aa` -> `__wstat64i32`, size `0x0b`.
  - `0x005c5c8d` -> `GetFileVersionInfoSizeW`, size `0x06`.
  - `0x005c5c93` -> `GetFileVersionInfoW`, size `0x06`.
  - `0x005c5c99` -> `VerQueryValueW`, size `0x06`.
  - `0x005c5cc9` -> `ImmGetCompositionStringW`, size `0x06`.
  - `0x005c5ce7` -> `ImmGetCandidateListW`, size `0x06`.
  - `0x0060c440` -> `sub_60C440`, size `0x0b`, atexit cleanup registered by the initializer.

### Negative Checks Performed

- `entity_query` for names and globals in `0x0069be14-0x0069bed0` returned zero named entries. IDA has `unk_69BE*` references in decompiler output, not source names.
- `type_query` filters `*WideApi*`, `*g_pfn*`, and `*UniAPI*` returned zero type catalog entries. No original typedef names were found.
- `lookup_funcs 0x005995b0` returned not a function; do not route UID0002AS to that raw projection body.
- No MCP failure occurred. `int_convert` was first called with a wrong parameter name (`values`) and returned a schema error; the live schema was checked and the call was rerun successfully with `inputs`.
- Initial Gate 1 report-only validators were intentionally skipped because the assignment forbade by-* implementation edits before supervisor acceptance. Implementation callback validators were later run and are recorded in `## Validator Results`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Target remains [UID:0002AS] `0x0069be14-0x0069bec4`, the main wide API dispatch pointer body. | High | `ba171fe4` `get_bytes` size 176 all zero; target range and sibling split docs. | Target Summary/Evidence; report Target/Range sections | Applied | Verified in target lines 64-82 and validator command `000000006620` |
| C02 | Target metadata is `COMPLETION:90`, `CONFIDENCE:90`, owner/emitter/reconstructable unchanged. | High | Target header after edit; validator output completion/confidence updates in command `000000006619`. | Target header | Applied | Verified target header `90/90`, `CANONICAL_OWNER:0000TQ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000TQ`, blank optional position |
| C03 | Formal C++ must be exact grouped function-pointer global declarations, not a body-only sample. | High | Accepted report formal block; target formal block; generated output lines 16-60. | Target formal `RECONSTRUCTION_CPP CODE`; generated PlatformApi | Applied | Verified generated `PlatformApi.cpp` contains `g_pfnWideOpenFile` through `g_pfnImmGetCandidateListW` and no UID0002AS empty marker |
| C04 | Storage is zero-initialized; declarations should not use `-1` or sentinel initializers. | High | `ba171fe4` `get_bytes 0x0069be14 size 176` and `0x0069bec4 size 12` all zero. | Target Evidence; UID0001Q1 Neighboring Storage; UID0002A6 Evidence | Applied | Verified target, UID0001Q1, and UID0002A6 now record current zero bytes and historicalize older `ff`/`0xffffffff` text |
| C05 | Initializer is [UID:0000WD] `sub_41A280`, range `0x0041a280-0x0041a4a8`, size `0x228`. | High | `ba171fe4` `lookup_funcs`; B001 and later B015 support evidence on UID0000WD. | Target Evidence; by-global IDA MCP Evidence; by-file Evidence; UID0000WD Evidence | Applied/already-present | Verified in target/by-global/by-file; UID0000WD currently also has B015 stronger current-session evidence and B001 callback note |
| C06 | `0x0069be14` is `_wfopen`, source-facing `g_pfnWideOpenFile`. | High | `ba171fe4` decompile store `0x0041a42e`, wrapper lookup `0x005d253a`, generated declaration. | Target C++/Evidence; generated PlatformApi | Applied | Verified generated line for `g_pfnWideOpenFile` |
| C07 | `0x0069be18` is `_wstat64i32`, source-facing `g_pfnWideStat`. | High | `ba171fe4` decompile store `0x0041a438`, wrapper lookup `0x005e25aa`, generated declaration. | Target C++/Evidence; generated PlatformApi | Applied | Verified generated `g_pfnWideStat` declaration |
| C08 | `0x0069be1c` is `ReadUtf16CodeUnitFromFile`, installed unconditionally after `GetVersionExA`. | High | `ba171fe4` decompile `0x0041a2b1`; helper decompile `0x00599570`; existing PlatformStringConversionHelpers naming. | Target C++/Evidence; UID0000WD Evidence | Applied | Verified target declaration and evidence; UID0000WD keeps assignment evidence |
| C09 | Slots `0x0069be20-0x0069beac` are the listed imported wide Win32 APIs through `SetCurrentDirectoryW`. | High | `ba171fe4` `decompile 0x0041a280` and representative xrefs. | Target formal C++; target/by-global evidence | Applied | Verified target C++ contains the full ordered slot declaration sequence |
| C10 | Slots `0x0069beb0-0x0069bec0` are version/IME local thunks. | High | `ba171fe4` decompile and wrapper lookups `0x005c5c8d`, `0x005c5c93`, `0x005c5c99`, `0x005c5cc9`, `0x005c5ce7`. | Target formal C++; target/by-global evidence | Applied | Verified target C++ includes version and IME declarations through `g_pfnImmGetCandidateListW` |
| C11 | `0x0069bec4` is neighboring `SendMessageW` and remains separate [UID:0001Q1]. | High | `ba171fe4` decompile store `0x0041a474`; UID0001Q1 doc. | Target split notes; UID0001Q1 Neighboring Storage/Evidence | Applied/preserved | Verified UID0001Q1 remains separate and now records zero-initialized current bytes |
| C12 | `0x0069bec8-0x0069bed0` tail remains separate [UID:0002A6]. | High | `ba171fe4` decompile stores `0x0041a47e`/`0x0041a488`; UID0002A6 doc. | Target split notes; UID0002A6 Evidence | Applied/preserved | Verified UID0002A6 remains separate and records current zero-initialized tail |
| C13 | Consumer modules do not own this storage. | High | Representative xrefs show broad consumers; initializer and source route are PlatformApi. | Target Rebuild Notes; by-global/by-file support | Applied | Verified target and support docs preserve PlatformApi/WideApiDispatchTable ownership |
| C14 | Raw `dword_69BE*` source names should be rejected in final source. | High | Existing by-global source declaration style; known installed targets; generated `g_pfn*` declarations. | Target Rebuild Notes; by-global Source Declaration Style | Applied | Verified no raw `dword_69BE*` declarations were added to target formal C++ |
| C15 | Forced runtime `struct WideApiDispatchTable` should not be emitted without base-pointer indexing evidence. | Medium-high | Direct absolute slot refs; by-global existing rejection. | Target Rebuild Notes; by-global Source Declaration Style | Applied/preserved | Verified grouped globals emitted; no struct/table object added |
| C16 | Original typedef/global spellings remain inferred. | High | `ba171fe4` names/globals/type queries returned zero. | Target Evidence/Rebuild Notes; report score rationale | Applied/preserved | Verified target remains capped at `90/90` and documents final typedef-name caveat |
| C17 | Raw `0x005995b0` projection is not the source owner and has no function route. | High | `ba171fe4` `lookup_funcs 0x005995b0` not a function; UID0001KE prior support. | Target Evidence/Changes; by-global/by-file/UID0000WD support | Applied | Verified docs record raw projection rejection and keep UID0001KE out of ownership |
| C18 | Generated PlatformApi output must remove UID0002AS empty marker and emit declarations after validator refresh. | High | Target validator `000000006619` updated PlatformApi; rerun `000000006620` waited generated; generated file header later `000000006629`. | Generated-output notes; report Validator Results | Applied/verified | Read-only generated check shows UID0002AS at lines 16-60, declarations present, no UID0002AS empty marker |
| C19 | No generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers should be manually edited. | High | Boundary constraints; shell history; generated changes only through validator. | Report Changed Files/checklist | Observed | Verified no manual generated/coverage/validator-state/lifecycle/supervisor-ledger edits and no forbidden lifecycle command |
| C20 | Scoped validators must run for every changed by-* file. | High | Validator commands `000000006614` through `000000006620`. | Report Validator Results | Applied | Verified all six changed by-* files validated; target final run used `--wait-generated` |
| C21 | Support docs should update only if stale; equal-or-better docs should be marked already-present. | Medium-high | Current support doc inspection; by-class UniAPIInit already stronger; B015 later strengthened UID0000WD. | by-global, by-file, UID0000WD, UID0001Q1, UID0002A6; report support notes | Applied/conditional | Edited stale/incomplete support docs; did not edit by-class UniAPIInit; UID0000WD now also has B015 current evidence after B001 release |
| C22 | Stale `cbc24146` must not be reused after MCP incident; current implementation evidence must use `ba171fe4`. | High | Supervisor incident notice; fresh `idb_list`/`server_health` on `ba171fe4`. | Report evidence; target/support docs | Applied | Verified callback docs/report cite `ba171fe4` for current evidence and mark `cbc24146` historical/superseded |
| C23 | Short leases must be used only for immediate by-* edits and released after validation. | High | `leaser.py B001 lease` success for six by-* files; `leaser.py B001 unlease`; current leases show no B001 active leases. | Report Changed Files/checklist | Applied | Verified `B001: No active leases`; current lease list only shows B015 on UID0000WD after B001 release |

## Positive Evidence Summary

- Direct MCP initializer evidence identifies every slot in the target range and the neighboring split slots.
- Direct MCP bytes show the table region is zero-initialized.
- Direct MCP xrefs show the slots are live dispatch storage used by many consumers, not unused padding or a stale generated artifact.
- Existing docs already converge on [UID:0000TQ] `WideApiDispatchTable` and [UID:0000ML] `PlatformApi` as owner/source route.
- Generated output now emits UID0002AS declarations and no UID0002AS empty marker remains; before the callback, that empty marker was the missing implementation step.

## IDA MCP Facts

- Function/range facts: `sub_41A280` at `0x0041a280`, size `0x228`; exclusive end `0x0041a4a8` not a function; `sub_599570` at `0x00599570`, size `0x37`; `0x005995b0` not a function.
- Data/table facts: `0x0069be14`, `0x0069bec4`, and `0x0069bec8` are not functions; `0x0069be14-0x0069bec4` is 176 bytes / 44 dwords; bytes are zero-initialized.
- Xref facts: representative slots have initializer writes plus live consumers; `0x0069be14` and `0x0069be5c` each reached the page limit with more results, while targeted slots like `0x0069be8c`, `0x0069bebc`, and `0x0069bec0` have focused consumer sets matching existing docs.
- Vtable/global/type facts: no source globals or typedefs were found in IDA's entity/type catalog for `WideApi`, `g_pfn`, or `UniAPI`.
- Negative IDA facts: no active evidence supports consumer-local ownership, raw projection ownership at `0x005995b0`, or a forced table-struct source declaration.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0069be14-0x0069bec4` | [UID:0002AS] `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md` | Main wide dispatch pointer body, 44 dwords | TRUE | [UID:0000TQ] | `90/90` applied | Target |
| `0x0069bec4-0x0069bec8` | [UID:0001Q1] `by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md` | Neighbor `SendMessageW` slot with stale alias risk | TRUE | [UID:0000ML] | `88/90` | Preserve separate |
| `0x0069bec8-0x0069bed0` | [UID:0002A6] `by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md` | Tail `GetLocaleInfoW` and `SetFileAttributesW` slots | TRUE | [UID:0000TQ] | `88/88` | Preserve separate |
| `0x0041a280-0x0041a4a8` | [UID:0000WD] `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md` | Real initializer / UniAPIInit constructor logic | TRUE | [UID:0000ML] | `85/90` | Support |
| `0x00599570-0x005995a7` subset | [UID:000249] `PlatformStringConversionHelpers` | Local UTF-16 file code-unit reader installed at `0x0069be1c` | TRUE | [UID:0000ML] | `88/91` support from executed report | Support |
| `0x005995b0-0x00599a34` | [UID:0001KE] `UniAPIInit` raw aggregate | Generated/raw projection refs, no source-function route | TRUE/no-code raw aggregate | [UID:0000ML] | `87/89` | Exclude as owner |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041a42e -> 0x0069be14` | `sub_41A280` data store | Installs `_wfopen` wrapper into first target slot |
| `0x0048fd7f -> 0x0069be14` | `sub_48FCA0` data xref in xref set | Thrunet startup auth parser consumes `_wfopen` slot |
| `0x0041a438 -> 0x0069be18` | `sub_41A280` data store | Installs `_wstat64i32` |
| `0x0041a2b1 -> 0x0069be1c` | `sub_41A280` data store | Installs `ReadUtf16CodeUnitFromFile` unconditionally |
| `0x0041a2ee -> 0x0069be30` | `sub_41A280` data store | Installs `LoadLibraryW`; known parser consumer at `0x004902b5` from docs |
| `0x0041a35c -> 0x0069be5c` | `sub_41A280` data store | Installs `CreateDirectoryW`; profile/screenshot consumers |
| `0x0041a366 -> 0x0069be60` | `sub_41A280` data store | Installs `DeleteFileW`; profile/minimap cleanup consumers |
| `0x0041a38e -> 0x0069be70` | `sub_41A280` data store | Installs `GetCurrentDirectoryW`; WinMain/profile consumers |
| `0x0041a3d4 -> 0x0069be8c` | `sub_41A280` data store | Installs `PeekMessageW` |
| `0x00464d63`, `0x00464de1 -> 0x0069be8c` | `sub_464CD0` xrefs | Application message loop consumes `g_pfnPeekMessage` |
| `0x0041a33e -> 0x0069be50` | `sub_41A280` data store | Installs `DefWindowProcW`; Browser/InputMan consumers |
| `0x0041a3de -> 0x0069be90` | `sub_41A280` data store | Installs `PostMessageW`; Browser/InputMan/Event consumers |
| `0x0041a460 -> 0x0069bebc` | `sub_41A280` data store | Installs `ImmGetCompositionStringW`; InputMan consumer |
| `0x0041a46a -> 0x0069bec0` | `sub_41A280` data store | Installs `ImmGetCandidateListW`; InputMan consumer |
| `0x0041a474 -> 0x0069bec4` | `sub_41A280` data store | Neighbor `SendMessageW`, split to UID0001Q1 |
| `0x0041a47e`, `0x0041a488` | `sub_41A280` tail stores | Neighbor tail slots, split to UID0002A6 |

## Documentation Evidence And IDA Status

- [UID:0000TQ] `WideApiDispatchTable` already documents the full dispatch family, the split into UID0002AS / UID0001Q1 / UID0002A6, the grouped PlatformApi file-scope function-pointer-global style, and the full startup assignment sequence.
- [UID:0000ML] `PlatformApi` already recognizes grouped `g_pfn*` dispatch globals as PlatformApi-owned, not raw dwords or consumer-local storage.
- [UID:0000FE] `UniAPIInit` already accepts the source shape `class UniAPIInit` and `static UniAPIInit s_uniAPIInit`.
- [UID:0000WD] `WideApiDispatchInit` already documents the real initializer, startup xref, version gate, and atexit cleanup.
- [UID:0001Q1] and [UID:0002A6] already document the neighboring split slots, so UID0002AS should not widen.
- Generated PlatformApi output is current for UID0002AS after validator refresh: the accepted declarations emit into `auto-generated/NexusTK/platform/PlatformApi.cpp`, and the prior UID0002AS empty marker is gone.

## Ranked Ownership Analysis

### 1. [UID:0000TQ] WideApiDispatchTable / [UID:0000ML] PlatformApi

- Evidence for: exact table parent already assigned; initializer is PlatformApi/UniAPIInit; source file route is PlatformApi; storage is a contiguous dispatch-global cluster; generated output routes this UID to `NexusTK/platform/PlatformApi.cpp`.
- Evidence against: original source may have been declarations plus an initializer helper rather than a named table object, but that affects declaration style, not owner.
- Decision: keep owner/emitter route.

### 2. [UID:0000WD] WideApiDispatchInit / [UID:0000FE] UniAPIInit

- Evidence for: this initializer writes every slot and belongs to the same PlatformApi source family.
- Evidence against: UID0000WD owns constructor/initializer behavior, not the storage declarations. UID0002AS is data storage that the initializer writes.
- Decision: support only. Do not move target owner.

### 3. Consumer modules: StdioFile, Application, Browser, InputMan, Registry/Profile/Map/Midi helpers

- Evidence for: xrefs show many direct calls/reads from these modules.
- Evidence against: consumers do not initialize or declare the storage cluster; they only call individual entries.
- Decision: reject as owners; mention only as consumer evidence.

### 4. [UID:0001KE] Raw/generated UniAPIInit projection

- Evidence for: raw/projection refs near `0x5995ea`, `0x599821`, and related addresses mention slots.
- Evidence against: `lookup_funcs 0x005995b0` says not a function; prior accepted reports identify it as a raw aggregate/projection, not source owner; live initializer is `0x0041a280`.
- Decision: reject as owner and preserve no-route/raw-projection caveat.

## Source Placement

Recommended source placement: `NexusTK/platform/PlatformApi.cpp`, through target [UID:0002AS] under parent [UID:0000TQ].

Why this fits: the storage is PlatformApi dispatch state, initialized by `UniAPIInit`, consumed across subsystems, and currently emitted in generated PlatformApi output. The code block should be grouped global function-pointer definitions, not a class method and not a consumer-local declaration.

Rejected placements:

- `InputMan.cpp`: consumes IME/window slots only.
- `Application.cpp`: consumes `g_pfnPeekMessage` only.
- `Browser.cpp`: consumes message/window slots only.
- `RegistryConfig.cpp` / ProfileStorage / file I/O modules: consume file/path slots only.
- `by-global/WideApiDispatchTable.md` formal C++: parent can summarize, but this exact child owns the main-body storage range and now removes the UID0002AS child empty marker through generated output.

Remaining placement uncertainty: final project may later add `extern` declarations in a platform header for cross-file consumers. That does not block this target's PlatformApi.cpp storage definitions.

## Range / Split / Padding / Reclassification Analysis

- Exact range: keep `0x0069be14-0x0069bec4` half-open. It is 176 bytes / 44 dwords.
- Lower boundary: `0x0069be14` is the first `_wfopen` dispatch slot; predecessor range is not part of this table body.
- Upper boundary: `0x0069bec4` is the next dword and belongs to [UID:0001Q1] as `SendMessageW` stale-alias high-risk slot.
- Tail boundary: `0x0069bec8-0x0069bed0` belongs to [UID:0002A6] with `GetLocaleInfoW` and `SetFileAttributesW`.
- Padding/data/code distinction: the entire target is data storage, not code. `lookup_funcs` confirms table addresses are not functions.
- Reclassification: none. Keep as `source-declared/generated-binary` reconstructable platform-support data.

## Negative Evidence Summary

- IDA did not expose original source symbols or typedef names for the table. Use inferred source-facing `g_pfn*` names, not overconfident original-name claims.
- Consumer xrefs are broad but do not prove consumer ownership.
- Neighbor `0x0069bec4` is not part of this target despite being initialized in the same branch.
- Raw/generated refs around `0x005995b0` do not create a source-function route.
- No base-pointer indexing or table-pointer use was found, so a forced `struct WideApiDispatchTable g_table` remains a weaker source model.
- No validators were run during the initial report-only pass. Implementation callback validators were run for every changed by-* file and are recorded below.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are requested. Source-facing names/types for documentation and C++ are:

- `g_pfnWideOpenFile`, `FILE *(__cdecl *)(const wchar_t *, const wchar_t *)`.
- `g_pfnWideStat`, `int (__cdecl *)(const wchar_t *, struct _stat64i32 *)`.
- `g_pfnReadUtf16CodeUnitFromFile`, `wchar_t (__cdecl *)(FILE *)`.
- `g_pfnPeekMessage`, `BOOL (WINAPI *)(LPMSG, HWND, UINT, UINT, UINT)`, preserving the already accepted no-`W` project spelling for this slot.
- Existing accepted InputMan names and types: `g_pfnDefWindowProcW`, `g_pfnPostMessageW`, `g_pfnImmGetCompositionStringW`, `g_pfnImmGetCandidateListW`.
- Remaining names follow the same `g_pfn<NameW>` project convention because original names are not present in IDA.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The target is reconstructable, has a valid owner/emitter route, current MCP proves exact data range and slot identities, storage is zero-initialized, and the callback replaced the generated UID0002AS empty marker with formal declarations.

Recommended code: insert exactly this formal `RECONSTRUCTION_CPP CODE` text into the target after supervisor acceptance. This is intentionally declaration-only storage C++; the runtime assignments belong to [UID:0000WD] `WideApiDispatchInit`.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
FILE *(__cdecl *g_pfnWideOpenFile)(const wchar_t *path, const wchar_t *mode);
int (__cdecl *g_pfnWideStat)(const wchar_t *path, struct _stat64i32 *buffer);
wchar_t (__cdecl *g_pfnReadUtf16CodeUnitFromFile)(FILE *stream);
HWND (WINAPI *g_pfnFindWindowW)(LPCWSTR className, LPCWSTR windowName);
HANDLE (WINAPI *g_pfnOpenFileMappingW)(DWORD desiredAccess, BOOL inheritHandle, LPCWSTR name);
HANDLE (WINAPI *g_pfnCreateMutexW)(LPSECURITY_ATTRIBUTES attributes, BOOL initialOwner, LPCWSTR name);
HWND (WINAPI *g_pfnCreateDialogParamW)(HINSTANCE instance, LPCWSTR templateName, HWND parent, DLGPROC dialogProc, LPARAM initParam);
HMODULE (WINAPI *g_pfnLoadLibraryW)(LPCWSTR fileName);
HANDLE (WINAPI *g_pfnCreateFileW)(LPCWSTR fileName, DWORD desiredAccess, DWORD shareMode, LPSECURITY_ATTRIBUTES securityAttributes, DWORD creationDisposition, DWORD flagsAndAttributes, HANDLE templateFile);
BOOL (WINAPI *g_pfnCreateProcessW)(LPCWSTR applicationName, LPWSTR commandLine, LPSECURITY_ATTRIBUTES processAttributes, LPSECURITY_ATTRIBUTES threadAttributes, BOOL inheritHandles, DWORD creationFlags, LPVOID environment, LPCWSTR currentDirectory, LPSTARTUPINFOW startupInfo, LPPROCESS_INFORMATION processInformation);
HANDLE (WINAPI *g_pfnCreateEventW)(LPSECURITY_ATTRIBUTES attributes, BOOL manualReset, BOOL initialState, LPCWSTR name);
ATOM (WINAPI *g_pfnRegisterClassW)(const WNDCLASSW *windowClass);
HWND (WINAPI *g_pfnCreateWindowExW)(DWORD exStyle, LPCWSTR className, LPCWSTR windowName, DWORD style, int x, int y, int width, int height, HWND parent, HMENU menu, HINSTANCE instance, LPVOID param);
HANDLE (WINAPI *g_pfnCreateFileMappingW)(HANDLE file, LPSECURITY_ATTRIBUTES attributes, DWORD protect, DWORD maximumSizeHigh, DWORD maximumSizeLow, LPCWSTR name);
HANDLE (WINAPI *g_pfnCreateSemaphoreW)(LPSECURITY_ATTRIBUTES attributes, LONG initialCount, LONG maximumCount, LPCWSTR name);
LRESULT (WINAPI *g_pfnDefWindowProcW)(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
UINT (WINAPI *g_pfnRegisterClipboardFormatW)(LPCWSTR format);
DWORD (WINAPI *g_pfnCharUpperBuffW)(LPWSTR text, DWORD length);
BOOL (WINAPI *g_pfnCreateDirectoryW)(LPCWSTR pathName, LPSECURITY_ATTRIBUTES securityAttributes);
BOOL (WINAPI *g_pfnDeleteFileW)(LPCWSTR fileName);
LRESULT (WINAPI *g_pfnDispatchMessageW)(const MSG *message);
HANDLE (WINAPI *g_pfnFindFirstFileW)(LPCWSTR fileName, LPWIN32_FIND_DATAW findFileData);
DWORD (WINAPI *g_pfnFormatMessageW)(DWORD flags, LPCVOID source, DWORD messageId, DWORD languageId, LPWSTR buffer, DWORD size, va_list *arguments);
DWORD (WINAPI *g_pfnGetCurrentDirectoryW)(DWORD bufferLength, LPWSTR buffer);
DWORD (WINAPI *g_pfnGetModuleFileNameW)(HMODULE module, LPWSTR fileName, DWORD size);
HMODULE (WINAPI *g_pfnGetModuleHandleW)(LPCWSTR moduleName);
UINT (WINAPI *g_pfnGetWindowsDirectoryW)(LPWSTR buffer, UINT size);
UINT (WINAPI *g_pfnGlobalGetAtomNameW)(ATOM atom, LPWSTR buffer, int size);
HCURSOR (WINAPI *g_pfnLoadCursorW)(HINSTANCE instance, LPCWSTR cursorName);
HICON (WINAPI *g_pfnLoadIconW)(HINSTANCE instance, LPCWSTR iconName);
BOOL (WINAPI *g_pfnPeekMessage)(LPMSG message, HWND hwnd, UINT filterMin, UINT filterMax, UINT removeMsg);
BOOL (WINAPI *g_pfnPostMessageW)(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LONG (WINAPI *g_pfnRegCreateKeyExW)(HKEY key, LPCWSTR subKey, DWORD reserved, LPWSTR className, DWORD options, REGSAM samDesired, LPSECURITY_ATTRIBUTES securityAttributes, PHKEY resultKey, LPDWORD disposition);
LONG (WINAPI *g_pfnRegDeleteKeyW)(HKEY key, LPCWSTR subKey);
LONG (WINAPI *g_pfnRegEnumValueW)(HKEY key, DWORD index, LPWSTR valueName, LPDWORD valueNameLength, LPDWORD reserved, LPDWORD type, LPBYTE data, LPDWORD dataLength);
LONG (WINAPI *g_pfnRegQueryInfoKeyW)(HKEY key, LPWSTR className, LPDWORD classLength, LPDWORD reserved, LPDWORD subKeyCount, LPDWORD maxSubKeyLength, LPDWORD maxClassLength, LPDWORD valueCount, LPDWORD maxValueNameLength, LPDWORD maxValueLength, LPDWORD securityDescriptorLength, PFILETIME lastWriteTime);
LONG (WINAPI *g_pfnRegQueryValueExW)(HKEY key, LPCWSTR valueName, LPDWORD reserved, LPDWORD type, LPBYTE data, LPDWORD dataLength);
LONG (WINAPI *g_pfnRegSetValueExW)(HKEY key, LPCWSTR valueName, DWORD reserved, DWORD type, const BYTE *data, DWORD dataLength);
BOOL (WINAPI *g_pfnSetCurrentDirectoryW)(LPCWSTR pathName);
DWORD (WINAPI *g_pfnGetFileVersionInfoSizeW)(LPCWSTR fileName, LPDWORD handle);
BOOL (WINAPI *g_pfnGetFileVersionInfoW)(LPCWSTR fileName, DWORD handle, DWORD length, LPVOID data);
BOOL (WINAPI *g_pfnVerQueryValueW)(LPCVOID block, LPCWSTR subBlock, LPVOID *buffer, PUINT length);
LONG (WINAPI *g_pfnImmGetCompositionStringW)(HIMC context, DWORD index, LPVOID buffer, DWORD bufferSize);
DWORD (WINAPI *g_pfnImmGetCandidateListW)(HIMC context, DWORD index, LPCANDIDATELIST candidateList, DWORD bufferSize);
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves exact original behavior: global function-pointer definitions are zero-initialized before `UniAPIInit` assigns real wide API targets. The declaration order follows the contiguous binary slot order, including the late `_wfopen` and `_wstat64i32` writes at `0x0041a42e`/`0x0041a438` while leaving their storage addresses at the beginning of the table.

Reason it matches plausible source shape: existing PlatformApi, UniAPIInit, and consumer docs already use `g_pfn*` PlatformApi globals. The compiler laid them out contiguously in `.data`, but current code uses direct absolute references, which is consistent with adjacent global declarations rather than required struct indexing.

Inferred source-facing names/types: all `g_pfn*` names not already accepted by generated consumers are descriptive, evidence-backed project names, not proven original PDB/source names. Exact typedef names remain deliberately omitted to avoid inventing original typedefs.

Third-party import directive: not applicable.

Exact no-code proof if not eligible: not applicable; target is eligible and code is recommended.

## Final Recommendation

Exact accepted changes applied:

- Updated UID0002AS target metadata to `90/90` with owner/emitter/reconstructable fields unchanged.
- Populated target formal C++ with the exact block above.
- Added current MCP session `ba171fe4` evidence, including active session/health, initializer size/range, zero bytes, complete slot map, representative xrefs, import/wrapper facts, and negative type/name evidence. Historical `cbc24146` is retained only as Gate 1 provenance.
- Preserved split notes for UID0001Q1 `SendMessageW` and UID0002A6 tail slots.
- Preserved raw/projection exclusion for UID0001KE / `0x005995b0`.
- Updated support docs only where stale or missing these facts.

Exact parent assignment applied: kept [UID:0000TQ] `WideApiDispatchTable` as canonical owner and emitter.

Exact items left no-owner/non-emitting: none in UID0002AS. Neighboring UID0001Q1/UID0002A6 remain their own targets.

Future work outside this assignment: later passes may standardize a PlatformApi header with `extern` declarations or prove original typedef names. That should not block UID0002AS first-draft storage definitions.

## Recommended Target Doc Changes

Target path: `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`.

Exact report facts to incorporate:

- MCP session `ba171fe4`, active IDB `NexusTK.exe.i64`, worker pid `12196`, health `ok`. Historical session `cbc24146` is stale/superseded and not current callback evidence.
- Exact range `0x0069be14-0x0069bec4`, 176 bytes / 44 dwords, zero-initialized.
- Initializer `sub_41A280` at `0x0041a280`, size `0x228`, exclusive end `0x0041a4a8`.
- Complete slot map with store addresses and installed targets.
- Representative xrefs proving live consumers for `_wfopen`, `_wstat64i32`, `ReadUtf16CodeUnitFromFile`, CreateFile/CreateDirectory/DeleteFile/GetCurrentDirectory, `PeekMessageW`, `DefWindowProcW`, `PostMessageW`, version, and IME slots.
- Import/wrapper evidence and local thunk addresses.
- Negative evidence: no IDA source names/types/globals; no function at `0x005995b0`; no struct-indexing proof.

Metadata/score/owner/emitter/reconstructable/C++ changes:

- `COMPLETION:90`.
- `CONFIDENCE:90`.
- Preserve `CANONICAL_OWNER:0000TQ`.
- Preserve `RECONSTRUCTABLE:TRUE`.
- Preserve `EMITTER_UIDS:0000TQ`.
- Preserve blank `EMITTER_POSITION_OPTIONAL`.
- Replace blank formal C++ with the exact block in this report.

Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:

- Historical stale generated aliases around `0x0069bec4` explain why UID0001Q1 remains separate, but current fact is `SendMessageW`.
- Exact typedef/global spellings remain inferred.
- Raw `dword_69BE*` names are rejected for source.
- Consumer ownership is rejected.
- Forced runtime table struct is rejected unless future base-index evidence appears.

## Recommended Support Doc Changes

Support path: `by-global/WideApiDispatchTable.md`.

- Incorporate that UID0002AS now has an implementation-ready formal C++ declaration block for the main body and should move from blank child marker to source-ready child after callback.
- Added/refreshed MCP session `ba171fe4` proof for zero-initialized storage and representative xrefs where this doc lacked current evidence.
- Keep score unless supervisor wants parent score sync; current `90/86` already clears the gate, and remaining parent confidence caveat is final typedef/source-name proof.

Support path: `by-file/PlatformApi.md`.

- Recorded that UID0002AS first-draft storage definitions belong in `NexusTK/platform/PlatformApi.cpp`; generated output now removes the UID0002AS empty marker after validator refresh.
- Preserve grouped `g_pfn*` PlatformApi globals and do not move storage to consumers.

Support path: `by-class/UniAPIInit.md`.

- No required score or C++ change. If touched, only mention that UID0002AS declarations are storage while `UniAPIInit` / `sub_41A280` owns the assignment behavior.

Support path: `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`.

- Added current MCP session `ba171fe4` confirmation of `sub_41A280` size `0x228`, complete store sequence, `GetVersionExA`, NT branch, and `atexit(sub_60C440)`. B015 later added stronger same-session initializer evidence after B001 released leases.
- Do not move target storage declarations into UID0000WD; its C++ body remains a separate initializer/constructor issue.

Support path: `by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md`.

- No required edit if current text already states this is `SendMessageW`. If stale browser/transport wording remains, clarify as historical alias only.

Support path: `by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md`.

- No required edit unless it still lacks current sibling-boundary proof. Preserve tail as separate `GetLocaleInfoW`/`SetFileAttributesW`.

Generated files and coverage reports: not edited manually. Generated PlatformApi refreshed only through scoped validator/autogen.

## Score And Metadata Recommendation

Current score/metadata:

- `COMPLETION:87`.
- `CONFIDENCE:87`.
- `CANONICAL_OWNER:0000TQ`.
- `RECONSTRUCTABLE:TRUE`.
- `EMITTER_UIDS:0000TQ`.
- Blank formal C++.

Recommended score/metadata:

- `COMPLETION:90`.
- `CONFIDENCE:90`.
- `CANONICAL_OWNER:0000TQ`.
- `RECONSTRUCTABLE:TRUE`.
- `EMITTER_UIDS:0000TQ`.
- Blank optional position preserved.
- Formal C++ populated exactly as above.

Score rationale and reason not higher/lower:

- Higher than current because current MCP proves full slot map, zero-initialized storage, live consumers, and a valid PlatformApi declaration style sufficient for formal C++.
- Not higher than 90 because original source typedef names and some global spellings are still inferred, and sibling slots remain split across separate pages.
- Not lower because leaving C++ blank would now ignore strong current evidence and would reintroduce the pre-callback generated empty-marker state.

Score-improvement attempt:

- Blocker: exact range and split. Resolved by MCP `int_convert`, `lookup_funcs`, `get_bytes`, initializer decompile/disasm, and sibling xrefs.
- Blocker: source owner. Resolved by existing owner chain plus initializer/source-file route; consumers rejected.
- Blocker: source C++ style. Resolved to grouped global function-pointer declarations; struct/table object rejected due no base-index evidence.
- Blocker: initial values. Resolved by MCP bytes: zero-initialized.
- Blocker: original typedef/global spelling. Not fully resolved; preserved as score cap but no longer blocks first-draft declarations.

## Open Questions With Attempted Resolution

- Open question: exact original typedef names. Evidence checked: IDA `type_query` filters `*WideApi*`, `*g_pfn*`, `*UniAPI*`; existing docs and generated output. Resolution: no typedef proof found; omit typedefs in formal block and use explicit function pointer declarations.
- Open question: exact original global names for every slot. Evidence checked: IDA names/globals query for range, project docs, generated consumers, prior executed reports. Resolution: use already accepted `g_pfn*` spellings where present and descriptive `g_pfn<NameW>` for the rest; mark as inferred.
- Open question: struct table versus grouped globals. Evidence checked: current xrefs, by-global declaration-style note, initializer direct stores. Resolution: grouped globals are best; forced struct rejected until base-index evidence appears.
- Open question: whether UID0002AS should include `SendMessageW` or tail slots. Evidence checked: sibling docs and current MCP stores/xrefs. Resolution: no; preserve split.
- Open question: whether raw `0x005995b0` projection owns declarations. Evidence checked: `lookup_funcs 0x005995b0`, prior B014 report, current target/parent docs. Resolution: no; raw/projection only.

## Validator Results

Commands run from `source-3/project-documentation`:

| Command ID | Timestamp | File | Flags | Result | Notes |
| --- | --- | --- | --- | --- | --- |
| `000000006614` | `2026-07-04T20:59:16-04:00` | `by-global/WideApiDispatchTable.md` | `--mode file --apply --queue-timeout 900` | exit `0`, `ok: 1` | Generated refresh deferred. |
| `000000006615` | `2026-07-04T20:59:24-04:00` | `by-file/PlatformApi.md` | `--mode file --apply --queue-timeout 900` | exit `0`, `ok: 1` | Existing `missing_ref_uid 0003OT` reported three times; not introduced by this callback and not fatal. Generated refresh deferred. |
| `000000006616` | `2026-07-04T20:59:26-04:00` | `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md` | `--mode file --apply --queue-timeout 900` | exit `0`, `ok: 1` | Generated refresh deferred. B015 later edited this file after B001 released leases. |
| `000000006617` | `2026-07-04T20:59:34-04:00` | `by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md` | `--mode file --apply --queue-timeout 900` | exit `0`, `ok: 1` | Generated refresh deferred. |
| `000000006618` | `2026-07-04T20:59:36-04:00` | `by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md` | `--mode file --apply --queue-timeout 900` | exit `0`, `ok: 1` | Generated refresh deferred. |
| `000000006619` | `2026-07-04T20:59:43-04:00` | `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md` | `--mode file --apply --queue-timeout 900 --wait-generated` | exit `0`, `ok: 1` | `completion_update 0002AS 90`, `confidence_update 0002AS 90`, `autogen_cpp_update 0000ML auto-generated/NexusTK/platform/PlatformApi.cpp`, `generated_refresh: completed`. |
| `000000006620` | `2026-07-04T21:00:37-04:00` | `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md` | `--mode file --apply --queue-timeout 900 --wait-generated` | exit `0`, `ok: 1` | Target rerun to remove ambiguity after deferred generated jobs; `generated_refresh: completed`. |

Generated-output verification:

- Read-only check of `auto-generated/NexusTK/platform/PlatformApi.cpp` after validators: header command id `000000006629`, refreshed `2026-07-04T21:06:45-04:00`, refresh source `deferred-generated-refresh`, last write `2026-07-04T21:06:50-04:00`, SHA256 `8594BC06D20BFAF76432148999C3CB6C9BFA3534F4ED6394FD96423E8A06A481`.
- UID0002AS emits at generated lines 16-60 with `Completion:90 | Confidence:90`; declarations from `g_pfnWideOpenFile` through `g_pfnImmGetCandidateListW` are present.
- No UID0002AS `Empty Emitter Marker` remains. Other empty markers for sibling/parent items are outside this callback.
- `auto-generated/-ag-research-tracker.md` lists UID0002AS as `90/90`, average `90.0`, reconstructable `true`.
- `auto-generated/-ag-memory-coverage.md` lists UID0002AS as `coded`, routed to `auto-generated/NexusTK/platform/PlatformApi.cpp`.

Unresolved validator warnings/errors:

- `by-file/PlatformApi.md` reports pre-existing `missing_ref_uid 0003OT` three times. The callback did not create or attempt to repair that registry/reference issue because it is outside UID0002AS scope.

## Changed Files

Modified by B001 in the implementation callback:

- `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`
- `by-global/WideApiDispatchTable.md`
- `by-file/PlatformApi.md`
- `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`
- `by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md`
- `by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md`
- `tools/leaser/Agents/Agent-B001/research/0002AS-WideApiDispatchPointerTable-source-quality.md`

Intentionally not modified:

- `by-class/UniAPIInit.md`: equal-or-better detail was already present; marked already-present in the ledger.
- Generated files, generated reports, coverage reports, validator state, lifecycle/archive files, supervisor ledgers, and unrelated docs were not manually edited. Validator-owned generated output and validator state changed only through scoped validator commands.

Lease state:

- B001 leased the six changed by-* files immediately before edits and released them after validation.
- `leaser.py B001 unlease` returned `B001: No active leases`.
- Current lease read-back showed no B001 active leases. A later B015 lease on `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md` exists after B001 release; B001 did not edit under that lease or revert B015 changes.

Report execution/lifecycle boundary:

- Not run: `execute_report`, execute dry-run/probe/status variants, registry lifecycle commands, manual report moves, archive commands, or lifecycle/archive commands.
- Current lifecycle state: `READY_FOR_SUPERVISOR_GATE2_REVIEW`.
- Remaining blockers: none for UID0002AS implementation. Residual caveat remains exact original typedef/global spellings, already documented as the reason for `90/90`.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Gate 1 accepted this report at SHA256 `E40A46F4CD297AFA9F2609E0861F6D63A106D10462175D4172D843B8D893DBAC`.
- [x] Target/support docs to update identified: target UID0002AS; stale/incomplete supports by-global WideApiDispatchTable, by-file PlatformApi, UID0000WD, UID0001Q1, UID0002A6; by-class UniAPIInit marked already-present.
- [x] Initial target state and evidence recorded: target `87/87`, blank C++, generated empty marker, Gate 1 MCP session `cbc24146`, full slot map, bytes, xrefs, imports/wrappers, negative type/name checks.
- [x] Claim And Incorporation Ledger created for Gate 1 and updated for callback with C01-C23 applied/already-present/excluded states.
- [x] Metadata/score recommendation researched: target `90/90`, owner/emitter/reconstructable unchanged.
- [x] Score-limiting blockers researched: range/split/source-owner/C++ style/initial bytes resolved; exact original typedef/global spelling remains documented score cap.
- [x] Owner/emitter/reconstructable changes confirmed unnecessary: preserve `0000TQ`, `TRUE`, `0000TQ`, blank optional position.
- [x] Split/rename/new-child changes confirmed unnecessary: preserve UID0001Q1 and UID0002A6 sibling splits.
- [x] Source placement confirmed: `NexusTK/platform/PlatformApi.cpp`; no IDA rename/type/comment edit was required or performed.
- [x] First-draft C++ supplied as exact formal `RECONSTRUCTION_CPP CODE` insertion text with header/BEGIN/END markers.
- [x] Third-party import directive confirmed not applicable; direct formal C++ block is required and now nonblank.
- [x] Historical/stale assumptions and negative evidence preserved: stale `SendMessageW` alias history, raw `dword_69BE*` rejection, consumer ownership rejection, forced struct rejection, raw UID0001KE/`0x005995b0` projection exclusion.
- [x] Open questions documented as evidence-backed unresolved: exact original typedef/global names and possible future header/extern standardization.
- [x] Initial report lifecycle boundary observed: no by-* implementation edits, validators, generated edits, or lifecycle commands before Gate 1 acceptance.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation callback.
- [x] Fresh MCP session `ba171fe4` used for callback checks; stale `cbc24146` not reused.
- [x] Short leases acquired for only the six by-* files edited and released after validator step.
- [x] All accepted target details incorporated at report-level specificity.
- [x] Target metadata applied: `COMPLETION:90`, `CONFIDENCE:90`, owner/emitter/reconstructable preserved, blank optional position preserved.
- [x] Target formal `RECONSTRUCTION_CPP` block populated with exactly the accepted formal block, including managed header, BEGIN marker, code, and END marker.
- [x] Target stale blank-C++ blocker wording removed or historicalized while preserving exact typedef/global-name caveat.
- [x] Target range/split facts incorporated: 44 dwords, zero-initialized storage, UID0001Q1 and UID0002A6 preserved.
- [x] Target/support docs incorporate current MCP session `ba171fe4`, exact `sub_41A280` range/size, slot map, local wrapper addresses, xrefs, imports/wrappers, and negative name/type/raw-projection evidence.
- [x] Support docs updated only where stale: by-global WideApiDispatchTable, by-file PlatformApi, UID0000WD, UID0001Q1, UID0002A6.
- [x] Equal-or-better support doc left unchanged: by-class UniAPIInit.
- [x] Historical/stale notes preserved and corrected: `cbc24146` historical only; older `ff ff ff ff`/`0xffffffff` initial-byte notes superseded by current zero bytes; stale browser/transport aliases preserved as historical aliases.
- [x] Negative evidence preserved: no IDA source names/types/globals, no function at `0x005995b0`, no consumer ownership, no forced struct.
- [x] Scoped validators run for every changed by-* file; command IDs, timestamps, exit codes, `ok` counts, warnings, and generated refresh state recorded above.
- [x] Target/emitter generated refresh verified with `--wait-generated`; second target run `000000006620` completed generated refresh.
- [x] Generated PlatformApi output inspected read-only: UID0002AS declarations present, UID0002AS empty marker gone, generated reports mark UID0002AS `90/90` and `coded`.
- [x] Generated files/project-level generated files/manual `-coverage-report.md` files/validator state/supervisor ledgers/lifecycle/archive files/unrelated docs not manually edited.
- [x] B001 lease release confirmed; no active B001 leases remain.
- [x] Remaining unapplied accepted items: none.
- [x] Stop at `READY_FOR_SUPERVISOR_GATE2_REVIEW`; do not run `execute_report`, execute dry-run/probe/status variants, registry lifecycle commands, manual report moves, or archive/lifecycle commands.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000006640","destination_path":"executed-b-agent-research/B001/0002AS-WideApiDispatchPointerTable-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002AS-WideApiDispatchPointerTable-source-quality.md","timestamp":"2026-07-04T21:15:27-04:00","uid":"0002AS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
