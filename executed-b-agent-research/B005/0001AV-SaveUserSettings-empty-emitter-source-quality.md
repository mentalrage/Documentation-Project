** TARGET-REPORT-UID:0001AV **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001AV SaveUserSettings Ownership / Split Research

## Finalized Report / Current Recommendation

- Implemented disposition: [UID:0001AV] is one reconstructable global `void SaveUserSettings()` function at exact half-open range `[0x0050aba0,0x0050b078)`, owned and emitted by [UID:0000MS][ProfileStorage](../../../../../by-file/ProfileStorage.md). Destination 1 replaced the former generated Empty Emitter Marker.
- Final target state: only the target changed from `86/90` to `92/93`; owner/emitter `0000MS`, `RECONSTRUCTABLE:TRUE`, blank position, `Nested:-4`, path, title, UID, and range are preserved. No target split or child was created.
- Callback result: C01-C35 and Destinations 1-6 were applied or verified. The inverse reader and four caller formals are corrected, complete eight-section format/failure/caller/source-placement evidence is synchronized, and the raw OptionPane callsite remains no-route support rather than an owner/emitter. The focused Gate 2 repair also corrected UID0002AA's filename-stem-only use and replaced two inaccurate RegistryConfig inventory summaries with the exact eight-section writer order.
- Confidence: very strong for bytes, range, ABI, control flow, serialization order/types, failure behavior, callers, helper targets, and ProfileStorage placement; high but capped for descriptive member/helper spelling and the exact original filename.

## Supporting Research

- Assignment source: validator-refreshed not-covered reconstructable and genuine Empty Emitter Marker queue. Evidence-time `auto-generated/NexusTK/profile/ProfileStorage.cpp` contained UID0001AV as an Empty Emitter Marker at `86/90` under by-file UID0000MS.
- Mandatory IDA evidence was collected on 2026-07-14 from database session `1feab207`, discovered by a fresh `idb_list`. A later fresh transport initialization and `idb_list` at approximately 09:42 ET reconfirmed that same adopted NexusTK IDB session, worker PID `20008`, `is_analyzing:false`; `server_health` returned `status=ok`, imagebase `0x400000`, and ready auto-analysis, Hex-Rays, and strings cache. These are evidence-time facts, not a claim that the session remains alive after review or archival.
- PE baseline: `E:\NTK\Resources\NexusTK\NexusTK.exe`, SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Exact old-report search terms were `0001AV`, `0x0050aba0`, `0x0050ABA0`, `SaveUserSettings`, `SaveUserSettings_50ABA0`, `sub_50ABA0`, `ProfileStorage`, `ProfileLoadAndLegacyImport`, `RegistryConfigUserProfileBlock`, `MacroHotkeyRecord`, `OptionPane`, `SpellMacroDialog`, `NewMacroDialog`, `FriendListDialog`, `IntegrateMacroDialog`, and `TargetOptionDialog`.
- Search roots actually checked were central `executed-b-agent-research`, every active `tools/leaser/Agents/Agent-B*/research` folder, `tools/leaser/Agents/SpecialReports`, `tools/leaser/Agents/Older-Research`, legacy `archived/b-agent-reports-20260623/**/research` and `research/executed`, plus current by-memory/by-file/by-class/by-type/by-meta documentation. No direct target report exists in active research, SpecialReports, Older-Research, or the legacy archived B-report root.
- Matching central reports opened and classified:
  - `executed-b-agent-research/B013/00019T-ProfileLoadAndLegacyImport-source-quality.md`: direct inverse-reader support, executed/current as evidence; it resolves the loader/importer and field roles, but is not a direct UID0001AV report. Its current by-memory formal has three source inconsistencies corrected by Destination 2.
  - `executed-b-agent-research/B005/0002UA-WideFormatWrapper-source-quality.md`: direct formatting dependency support, executed; it proves `0x004236e0` is reviewed non-emitting CRT/template support and caller-local `swprintf_s`, not a project `WideFormatWrapper` API.
  - `executed-b-agent-research/B001/B001-MEMTOOL-00506970-MapPaneInputPacketRenderCore.md`: direct range/ownership support, executed; it isolates UID0001AV as the ProfileStorage island and preserves the surrounding MapPane children.
  - `executed-b-agent-research/B002/00007Q-MapPane-class-source-quality.md`: incidental MapPane class support, executed; one historical coverage example uses the stale wrong SaveUserSettings address `0x00508e10-0x0050902c`, rejected in favor of the current exact page/range.
  - `executed-b-agent-research/B002/0002QH-0002QI-0002QO-0002QP-0002QQ-000231-MapPaneTeardownObjectPacket-source-quality.md`: direct caller support, executed; it preserves `SaveCompressedMapFile(); SaveUserSettings();` ordering in MapPane exit teardown.
  - `executed-b-agent-research/B010/0001DR-MacroDialogs-source-quality.md`: direct caller-family support, executed but partially stale for this target; its `g_userSettingsDirty` gates are superseded by current direct reads of `g_activeMapPane` at `0x0067a764`.
  - `executed-b-agent-research/B008/00045G-IntegrateMacroDialogOnButtonClick-empty-emitter-source-quality.md`: direct Integrate caller support, executed but stale only for the same dirty-flag interpretation.
  - `executed-b-agent-research/B001/0001E1-IntegrateMacroDialog-source-quality.md`: incidental class-family caller support, executed; useful for command ordering, stale for the `dword_67A764` meaning.
  - `executed-b-agent-research/B001/0001DS-FriendListDialog-source-quality.md`: direct caller support, executed; useful for the optional friend-list send ordering and exact final target call, while its earlier conditional naming caveat is now closed.
  - `executed-b-agent-research/B001/0002AS-WideApiDispatchPointerTable-source-quality.md`: direct helper-prototype support, executed; independently resolves the `_wfopen`, `CreateDirectoryW`, and `DeleteFileW` dispatch slots.
  - `executed-b-agent-research/B003/0002RT-StringBaseReleaseAndCapacity-source-quality.md`: incidental StringBase support, executed; confirms target use of wide formatting and pointer-backed string helpers.
  - `executed-b-agent-research/B009/00039S-ScreenPanePresentationModeFlagSetters-source-quality.md`: incidental MapPane teardown support only.
  - `executed-b-agent-research/B014/00037Q-MapPaneObjectLookupHelpers-source-quality.md`: negative ownership support; it rejects the ProfileStorage island from MapPane helper ownership.
  - `executed-b-agent-research/B009/00045K-IntegrateMacroDialogRetreatMacroPageRaw-source-quality.md`, `B010/00045J-IntegrateMacroDialogAdvanceMacroPageRaw-empty-emitter-source-quality.md`, and `B015/00045L-IntegrateMacroDialogRefreshMacroEditFields-empty-emitter-source-quality.md`: incidental Integrate sibling reports; they confirm the caller-family context but add no UID0001AV body evidence.
- Legacy direct match opened: `by-memory/-report.old.md`, section `0x0050ABA0 - SaveUserSettings_50ABA0`. It is not a countable B report. Useful retained facts are the free zero-argument writer role and ProfileStorage-style `.usr` format. Its Wave2 lifecycle, imported-source status, `MapPane::HandleServerMessage` caller label, and incomplete generalized group description are historical/superseded.
- Evidence-based conclusion: no prior direct UID0001AV B-agent source-quality report exists. Current executed matches are support or incidental evidence only; all adopted claims were independently rechecked with current MCP/current docs.
- No Wave2/Wave3 artifact was used as authority. The only Wave2 material encountered is the historical `-report.old.md` record above.

## Target

- Target UID: `0001AV`.
- Target path: `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md`.
- Historical source queue/report row: not-covered reconstructable, `86/90`, with a generated Empty Emitter Marker before this callback.
- Current supervisor classification: accepted same-report implementation callback and focused Gate 2 repair completed by B005. All B005 content, scoped-validation, generated-verification, and lease-release responsibilities are complete; supervisor execution and archival remain external lifecycle state that this artifact does not assert.
- Current scores and parent state: target `92/93`, owner/emitter UID0000MS ProfileStorage (`88/87`), reconstructable true, populated Destination 1 formal body, blank position, `Nested:-4`.

## Current Target State

- Current metadata has the correct UID, path, title, exact range, owner/emitter UID0000MS, reconstructable state, blank position, cumulative nesting, `92/93` score, exact Item Summary, and populated Destination 1 formal C++. The historical `86/90` blank-emitter/parent-gate state is retained only as superseded history.
- Current prose enumerates all eight sections, exact size/count widths, loop bounds, invalid-state behavior, destructive replacement, ignored write/close outcomes, complete caller semantics, ownership negatives, and score rationale.
- Current target name is retained. Direct symbols are stripped, but the historical free-helper label, inverse loader, eight UI/settings callers, and behavior all support descriptive source-facing `SaveUserSettings()`; the address suffix is rejected from human source.
- Historical pre-callback generated `ProfileStorage.cpp`, read-only evidence at validator command `000000011243`, refresh `2026-07-14T09:41:09-04:00`, SHA-256 `BE0215B5A73B8477278FBB9D12875ECAB5E60885F70262EADED5EB66F3B20776`, had one UID0001AV Empty Emitter Marker and no target definition. The original callback waited refresh was command `000000011476`. B005's final focused-repair waited refresh was command `000000011508`, timestamp `2026-07-14T11:55:32-04:00`, SHA-256 `93C2A9FAD1CBF4F8288DDE690AB0A0561F8198C1056CB76311C36A7D014C605B`; its evidence-time output had exactly one `void SaveUserSettings()` definition and zero UID0001AV Empty Emitter Markers. A later read-only observation after concurrent validator refresh `000000011513` at `2026-07-14T11:59:27-04:00`, SHA-256 `9609C6AC280141888EC93CE09FAC76BBA23BA3A20A270BBF69FB042D7946029B`, reconfirmed the same one-definition/zero-target-marker result.
- Related target/support docs checked: UID0000MS, UID00019T, UID0001QL, UID0001VR, UID0001V1, UID0000BW, UID00028Q, UID0002UA, UID0002AS, UID0002A6, UID0002AA, UID0001AT, UID0002QH, UID0001DO, UID00040H, UID0001DR, UID00049H, UID00049L, UID0001DS, UID00045G, UID0001E1, UID0001E2, MacroDialog/SpellMacroDialog/IntegrateMacroDialog/FriendListDialog/TargetOptionDialog classes and files, `g_activeMapPane`, SimpleUString/StringBase/SimpleUStringVector support, `client_profile_storage`, generated ProfileStorage.cpp, manual coverage, `-ignored`, and legacy `-report.old`.
- Current artifact/lifecycle status: accepted implementation callback and focused Gate 2 repair completed. Thirty ordinary by-* pages were edited in the original callback; the repair re-edited only UID0002AA plus the RegistryConfig class/file pages. Every ordinary edit used a serial short lease, scoped validation, and immediate release. The validator refreshed generated output and generated metadata as an authorized side effect. B005 did not manually edit coverage, generated output, tracker, audit, validator state, lifecycle state, or IDA, and did not run/probe `execute_report` or any lifecycle action.

## Executive Recommendation

- The callback emits one global zero-argument `void SaveUserSettings()` in `NexusTK/profile/ProfileStorage.cpp`. It is not a MapPane method, RegistryConfig method, dialog method, namespace-only API, or mixed aggregate.
- Preserve UID0000MS as owner/emitter and the current source root. `ProfileStorage.cpp` is descriptive but strongly supported by the existing load/import/sidecar/writer grouping; exact original filename uncertainty caps confidence rather than blocking source.
- Destination 1 is applied and the target is `92/93`. No new child, range change, position, owner, emitter, reconstructable, or nesting change occurred.
- Destination 2 is applied so the inverse reader is type-correct and consistent with current formatting/type names. Destinations 3-6 are applied, removing the fictitious dirty flag and wrong `SaveConfig()` call from exact caller formals.
- The raw OptionPane span, profile layout/meta/file pages, caller family pages, and helper/global pages are synchronized without support score/route changes. Exact manual coverage text remains in this report for supervisor-owned application; B005 did not edit coverage.

## Supervisor Active Recheck

- Supervisor Gate 1 accepted the exact report-only artifact SHA-256 `29A310D0858FC33595BB5AD86FD0E0276AE15FC8922DF3E3F649E05EF3A1E828` and authorized this same-report callback. B005 completed the accepted implementation scope without running report execution or lifecycle commands.
- The first post-callback Gate 2 review found three support-prose defects only: UID0002AA incorrectly called its local filename stem serialized section 1, and RegistryConfig class/file pages repeated an inaccurate older writer sequence. B005 repaired exactly those three ordinary pages under validators `000000011503`, `000000011504`, and `000000011507`, then completed waited target refresh `000000011508`; no other accepted implementation content changed.
- Split repair is not required for UID0001AV: current function inventory, exact bytes, entry/end xrefs, EH chunks, and adjacent padding prove one source-authored function.
- All source-bearing destinations are the accepted literal destination-specific blocks below and were applied exactly. The raw OptionPane callsite remains no-route retained source-shaped evidence and did not create another emitter.

## Inference Research Guidance Check

- `by-structure.md` was applied as a range/ownership/source graph: half-open endpoints, owner/emitter separation, cumulative `Nested`, ignored padding, mixed aggregate exclusion, and formal-only C++ rules.
- Existing labels were treated as hypotheses. Direct facts are addresses, bytes, calls, globals, offsets, Win32/CRT targets, branch conditions, and xrefs. `SaveUserSettings`, field roles, helper names, and ProfileStorage filename are source-facing inference corroborated by current docs and inverse behavior.
- Stale assumptions explicitly rejected are `g_userSettingsDirty` at `0x0067a764`, `SaveConfig()` for the FriendList target call, `WideFormatWrapper` as a NexusTK source API, MapPane ownership, RegistryConfig member ownership, and the old wrong target address in one executed MapPane report.
- Wave2/Wave3 import state was ignored. Historical useful facts were retained only after current independent verification.

## Heuristic / Inference Reanalysis And Validation

- **Function identity/ABI:** MCP models one `sub_50ABA0` function of size `0x4d8`, no parameters, no return value, ordinary cdecl-style global callsites, and a plain `ret`. No caller consumes a return. Best source shape is `void SaveUserSettings()`.
- **Range/split:** all 1,240 target bytes (decimal verified with `int_convert.py`) form one CFG plus compiler EH/security scaffolding. Cleanup chunks at `0x006026d4` and `0x006026df` are target EH metadata/codegen, not independent human helpers. There is no alternate target entry and no xref to the exclusive end.
- **Object route:** `g_pConfig` storage is declared as `Config*`, but startup constructs a derived `RegistryConfig` runtime object. The writer directly accesses the derived user-profile slice. Type-correct source is `RegistryConfig &config = *static_cast<RegistryConfig *>(g_pConfig);`; a null guard would invent behavior because the target immediately dereferences the global.
- **Path helper:** `0x004236e0` is compiler/UCRT wide-format array support. Calls carry fixed `0x104` capacity and reconstruct as caller-local `swprintf_s`, not `WideFormatWrapper`.
- **User-name helper:** `0x005a2da0` is exactly `errno_t GetLocalPlayerName(wchar_t *destination, size_t capacity)` behavior over `wcscpy_s`; the writer passes capacity `0x28` and ignores the result. `CopyLocalPlayerName` is semantically precise, but accepted project usage `GetLocalPlayerName` is retained for consistency.
- **Platform pointer helpers:** current PlatformApi declarations prove `_wfopen`, `CreateDirectoryW`, `DeleteFileW`, and `SetFileAttributesW` signatures. These are process-wide dependencies, not ProfileStorage-owned globals.
- **String helpers:** `0x00582b20`/`0x00582b70` construct/destroy the pointer-backed wide string handle; `0x00583700` formats it; `0x00584540` returns wide data; `0x00584cf0` returns 32-bit character length. The fixed/profile-string paths narrow lengths to unsigned 16-bit exactly; the vector preserves unsigned 32-bit length.
- **Directory failure semantics:** `SHGetFolderPathW` must return exactly `S_OK`. Each `CreateDirectoryW` failure is accepted only when immediate `GetLastError()` equals `ERROR_ALREADY_EXISTS`; all other failures return before file mutation.
- **Destructive replacement:** the writer ignores SetFileAttributesW and DeleteFileW results, deletes the old path before `_wfopen(..., L"wb")`, and has no temporary/rename rollback. An open failure can therefore leave no profile file.
- **Write failures:** all 14 `fwrite`, six per-category `fputwc` call groups, and `fclose` results are ignored. Mid-stream failure continues through remaining sections and can leave a partial/truncated stream. Source must not add exceptions, retries, atomic replacement, rollback, or a status return.
- **Section boundaries:** all eight groups are exact and inverse-compatible. Group 6 begins with literal/presence dword `1`, not a row count; the loader uses it only as optional-tail success and always reads 20 records. Group 7 count is 30. Group 8 count is 2.
- **Macro invalid state:** states 1/2/3 emit `T`/`S`/`I`. Any other state emits no type wchar but still emits a uint16 length and payload, deliberately preserving the original malformed-stream hazard. Adding a default type would change behavior.
- **Trailing booleans:** each of four bytes emits `L'1'` only when exactly equal to byte value `1`; every other value emits `L'0'`. Treating any nonzero as true would change behavior.
- **Raw caller:** `[0x0053dd70,0x0053dda6)` is an 18-instruction, no-function-record, `this`-receiving OptionPane body. It calls `g_pConfig` virtual slot `+0x0c` when non-null, calls SaveUserSettings only when `g_activeMapPane` is non-null, closes/removes the pane, and returns. No direct code/data/pointer/immediate route targets its start. Best disposition is retained no-route source-shaped evidence inside the non-emitting OptionPane split index, plus ignored `[0x0053dda6,0x0053ddb0)` padding; it is not a proven live caller or a new emitter.
- **Caller gates:** `0x0067a764` is `g_activeMapPane`, not a dirty flag. SpellMacro, NewMacro, IntegrateMacro, and TargetOption call SaveUserSettings only while an active map exists; FriendList and MapPane exit call unconditionally; OptionPane apply/raw paths combine config registry save with the active-map gate.
- **Source ownership:** the body is profile path/serialization logic shared across unrelated panes. RegistryConfig owns storage layout; PlatformApi/StringBase own dependencies; UI classes own trigger methods; MapPane's broad physical aggregate only surrounds the function. ProfileStorage is the only candidate that explains both writer and inverse loader without consumer-local ownership.
- **Score blockers:** helper prototypes, group boundaries, widths, counts, names/types, failure paths, raw callsite, caller ordering, object type, source placement, split, and C++ body were all resolved to implementation-ready recommendations. Remaining exact original spelling/file-name uncertainty is lexical only and explains `92/93` rather than a higher score.

## Evidence Standards Used

- Direct evidence: healthy IDA MCP `lookup_funcs`, `get_bytes`, `decompile`, `disasm`, `analyze_function`, `basic_blocks`, `xrefs_to`, caller/callee and bounded byte/pointer searches; executable SHA; current generated output.
- Corroborating evidence: current by-* pages, accepted executed reports, inverse loader formal/body, PlatformApi declarations, RegistryConfig profile layout, manual coverage, and exact ignored padding.
- Negative evidence: no target alternate entry/end xref, no absolute VA/RVA target pointer bytes, no vtable/data callback route, no target split, no raw OptionPane start route, no status-return consumption, no temp/rename/retry/error-reporting path, and no direct prior B report.
- Evidence ladder: binary control/data flow is authoritative; current accepted docs establish project vocabulary and source graph; contextual names are explicitly marked descriptive where stripped symbols prevent original-name proof.

## Evidence Checked

- MCP availability/provenance: fresh `initialize -> tools/list/tools/call`, `idb_list`, and `server_health` against session `1feab207`; no IDA mutation.
- Target calls: `lookup_funcs(0x0050aba0)`, full `get_bytes([0x0050aba0,0x0050b078))`, `decompile`, paged `disasm`, `analyze_function`, basic blocks, callees, xrefs to start/end, and bounded adjacent lookups/bytes.
- Reachability: xrefs for all eight callsites; bounded VA/RVA pointer-byte and immediate searches for target start/end; raw OptionPane start xrefs and disassembly; helper/global xrefs; EH cleanup refs.
- Support decompilation: `0x005a2da0`, `0x0053f830`, `0x005424b0`, `0x0053dd70`, MapPane teardown, OptionPane handler, Spell/New/Integrate callers, and PlatformApi initializer/support pages.
- Raw/manual checks: PE SHA-256, target byte SHA-256, generated ProfileStorage.cpp header/hash/marker, exact manual coverage rows, ignored padding, current metadata/formals, old report roots, and `int_convert.py` for `0x4d8=1240`, `0x108=264`, `0x1e=30`, `0x28de9c=2678428`, and `0x2918fc=2693372`.
- No failed mandatory check remains. One initial direct JSON-RPC helper invocation serialized PowerShell's automatic `$args` as an array and returned schema errors; it was immediately corrected by using an explicit object parameter, followed by successful fresh `idb_list`, `server_health`, and bounded calls. This was a client argument-shape error, not MCP downtime and contributed no evidence.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Exact target is `[0x0050aba0,0x0050b078)`, 1,240 bytes, SHA-256 `0108F81842E9AD6A537622A52E799A65751424BA0237EF70F8AA566D0240BE14`. | very high | MCP bytes/lookup; int_convert | UID0001AV Evidence/Boundaries | incorporate | applied |
| C02 | One global `void()` source function; 363 in-range instructions, 43 blocks, complexity 20, SEH/security cleanup only. | very high | disasm/analyze/decompile | UID0001AV ABI/CFG | incorporate | applied |
| C03 | Predecessor ends `0x0050ab95`; `[0x0050ab95,0x0050aba0)` is 11-byte `0xcc` padding. | very high | lookup/get_bytes/-ignored | UID0001AV Boundaries | already-present | already-present |
| C04 | Target end is exact; `[0x0050b078,0x0050b080)` is eight-byte padding before `sub_50B080`; no split/child. | very high | lookup/get_bytes/xrefs | UID0001AV Boundaries/Split | incorporate | applied |
| C05 | Owner/emitter/source route is UID0000MS `profile/ProfileStorage.cpp`, not MapPane/RegistryConfig/UI. | high | behavior, caller spread, inverse loader, aggregate exclusion | UID0001AV; UID0000MS | incorporate | applied |
| C06 | Runtime object is RegistryConfig through base-typed `g_pConfig`; source requires explicit derived cast and no null guard. | high | startup/global docs, direct fields | UID0001AV; UID00019T; UID00028Q | incorporate | applied |
| C07 | Exact dispatch prototypes are `_wfopen`, CreateDirectoryW, DeleteFileW, SetFileAttributesW. | very high | UID0002AS/UID0002A6 formals and initializer | UID0001AV; PlatformApi support verify | already-present | already-present |
| C08 | `GetLocalPlayerName(wchar_t*, size_t)` copies with `wcscpy_s`; capacity `0x28`, return ignored. | very high | decompile 0x005a2da0 | UID0001AV; UID0002AA | incorporate | applied |
| C09 | String ctor/dtor/Format/c_str/length identities and 16-bit versus 32-bit length narrowing are exact. | high | target calls; StringBase docs | UID0001AV; UID0001QL/UID0001VR | incorporate | applied |
| C10 | Exact S_OK and ERROR_ALREADY_EXISTS directory gates precede all file mutation. | very high | target branch flow | UID0001AV; UID0000MS/UID0001QL | incorporate | applied |
| C11 | Set attributes/delete results ignored; old file deleted before `wb`; open failure can leave no file. | very high | target call/branch order | UID0001AV; storage docs | incorporate | applied |
| C12 | Section 1 is 10 fixed wchar arrays, uint16 length then byte-size payload. | very high | decompile/disasm/inverse reader | UID0001AV; profile layout docs | incorporate | applied |
| C13 | Section 2 is exactly 10 first wchar values from legacy shortcut rows, no header/terminator. | very high | target loop | same | incorporate | applied |
| C14 | Section 3 is 20 pointer-backed strings with narrowed uint16 lengths and byte-size payloads. | very high | target loop/helpers | same | incorporate | applied |
| C15 | Section 4 is selected-profile wchar array with uint16 length/payload. | very high | target loop/inverse | same | incorporate | applied |
| C16 | Section 5 is uint32 vector count; each row uint32 length and `fwrite(size=2,count=length)`. | very high | pointer-difference/loop | same | incorporate | applied |
| C17 | Section 6 is literal dword 1 plus 20 code/mode pairs; mode is S for nonzero, I for zero; byte +3 not serialized. | very high | target compact loop | same | incorporate | applied |
| C18 | Section 7 is dword 30 plus 30 macro rows; T/S/I states; invalid state omits type but still writes uint16 text. | very high | switch/loop | same; UID0001V1 | incorporate | applied |
| C19 | Section 8 is dword 2 plus four wchar booleans; only byte exactly 1 emits `1`. | very high | target final loop | same | incorporate | applied |
| C20 | All write/close results ignored; partial/truncated file and no rollback are preserved behavior. | very high | return-use/CFG check | UID0001AV; meta/file docs | incorporate | applied |
| C21 | Eight exact target xrefs/callsite semantics are fully inventoried. | very high | xrefs/decompile | UID0001AV caller table; support docs | incorporate | applied |
| C22 | Raw `[0x53dd70,0x53dda6)` OptionPane body has no start route and is support-only; following 10 bytes are padding. | high | disasm/xrefs/pointer searches | UID0001DO; OptionPane class/file; -ignored | incorporate | applied |
| C23 | MapPane exit calls SaveUserSettings unconditionally after disabling presentation/saving map and before later teardown/logout work. | very high | current UID0002QH body | UID0002QH verify-only; UID0001AV caller table | already-present | already-present |
| C24 | OptionPane apply/raw paths call registry save, gate user-file save on g_activeMapPane, then close/remove. | very high | decompile/disasm | UID00040H/UID0001DO support | incorporate | applied |
| C25 | SpellMacro confirm's gate is g_activeMapPane, not dirty state. | very high | direct data ref/caller body | UID00049H; Spell class/Macro file/aggregate | incorporate | applied |
| C26 | NewMacro confirm's gate is g_activeMapPane, not dirty state. | very high | direct data ref/caller body | UID00049L; Macro file/aggregate | incorporate | applied |
| C27 | FriendList sends optional sync first, then unconditionally calls SaveUserSettings, then closes/removes. | very high | fresh decompile 0x53f830 | UID0001DS; Friend class/file | incorporate | applied |
| C28 | IntegrateMacro confirm's gate is g_activeMapPane, not dirty state. | very high | direct caller body | UID00045G; Integrate class/file/aggregate | incorporate | applied |
| C29 | TargetOption writes two rows, closes/removes, then gates SaveUserSettings on g_activeMapPane. | very high | fresh decompile 0x5424b0 | UID0001E2; class/file | incorporate | applied |
| C30 | Inverse loader formal must cast g_pConfig, use swprintf_s, and use MacroHotkeyRecord::text. | high | current declarations and UID0002UA | UID00019T Destination 2 | incorporate | applied |
| C31 | Profile file/meta/layout/type docs require complete eight-section/failure/history synchronization without score/route loss. | high | current docs vs target | UID0000MS/UID0001QL/UID0001VR/UID0001V1/RegistryConfig | incorporate | applied |
| C32 | Negative ownership/reachability/history alternatives remain explicit. | high | binary negative searches/current graph | target/support Rejections/History | historicalize | applied |
| C33 | Target becomes `92/93` with exact Item Summary and Destination 1; all other metadata/scores remain unless listed. | high | blocker closure | UID0001AV metadata/formal | incorporate | applied |
| C34 | Manual coverage target and stale related rows require exact supervisor-owned replacements; B005 must not edit coverage. | very high | read-only current coverage matrix | coverage text section | incorporate | applied |
| C35 | Accepted callback validation requirement was one scoped validator per changed ordinary page plus a final waited refresh and read-only inspection of generated ProfileStorage and affected caller files; no execute_report. | very high | workflow/generated state | checklist/Validator Results | incorporate | applied |

### Callback Verification Notes

| Claim | Final proof |
| --- | --- |
| C01 | UID0001AV exact-range/byte/hash evidence is preserved in the target; scoped validator `000000011446` passed. |
| C02 | UID0001AV ABI/instruction/CFG/EH evidence and global `void()` source shape are preserved; `000000011446` passed and generated `ProfileStorage.cpp` contains one definition. |
| C03 | Existing predecessor padding remained unchanged in `by-memory/-ignored.md`; the callback added no duplicate target padding entry. |
| C04 | UID0001AV exact end/successor/no-split evidence is present; `000000011446` passed with no child allocation. |
| C05 | UID0001AV and UID0000MS retain the ProfileStorage owner/emitter route; validators `000000011446` and `000000011452` passed. |
| C06 | Explicit derived casts/no-null-guard contract is applied to UID0001AV, UID00019T, RegistryConfig class/file, and UID00028Q; validators `000000011446`, `000000011447`, and `000000011456`-`000000011458` passed. |
| C07 | UID0002AS/UID0002A6/Wide API declarations were verified without edits; generated target source uses the accepted dispatch names. |
| C08 | UID0002AA records exact `errno_t GetLocalPlayerName(wchar_t *, size_t)`, direct `wcscpy_s` result, local `wchar_t[40]`, capacity `0x28`, and ignored return. Gate 2 repair now states exactly that this local value is only the `%s/%s.usr` `<user-id>` filename stem and is not serialized; section 1 is `m_profileTextSlots[10]`. Original validator `000000011459` and repair validator `000000011503` passed. |
| C09 | UID0001QL/UID0001VR and target preserve StringBase/SimpleUString width behavior; validators `000000011446`, `000000011453`, and `000000011454` passed. |
| C10 | Target/file/meta docs preserve exact S_OK/ERROR_ALREADY_EXISTS gates; validators `000000011446`, `000000011452`, and `000000011453` passed. |
| C11 | Target/file/meta docs preserve attributes/delete/open ordering and destructive failure behavior; validators `000000011446`, `000000011452`, and `000000011453` passed. |
| C12 | Section 1 exact ten-row uint16/byte-size contract is present in target/file/meta/layout docs and generated source; validators `000000011446`, `000000011452`-`000000011454` passed. |
| C13 | Section 2 exact ten first-wchar contract is present in the same destinations and generated source. |
| C14 | Section 3 exact 20 pointer-backed string contract is present in the same destinations and generated source. |
| C15 | Section 4 selected-profile uint16/payload contract is present in the same destinations and generated source. |
| C16 | Section 5 uint32 vector count/length and `size=2,count=length` contract is present in target/meta/layout and generated source. |
| C17 | Section 6 literal dword `1`, 20 code/mode pairs, and unpersisted byte `+3` are present in target/meta/layout and generated source. |
| C18 | Section 7 count `30`, T/S/I switch, invalid-state omission, and `.text` member are present; UID0001V1 validator `000000011455` passed. |
| C19 | Section 8 count `2` and equality-to-one four-wchar encoding are present in target/meta/layout and generated source. |
| C20 | Ignored write/close results and partial/truncated/no-rollback behavior are preserved in target/file/meta; no status path was added. |
| C21 | Target's eight-callsite table is preserved; caller support validators `000000011448`-`000000011451` and `000000011460`-`000000011475` passed as applicable. |
| C22 | UID0001DO, OptionPane class/file, and `-ignored` contain the no-route `[0x53dd70,0x53dda6)` plus ten-byte padding disposition; validators `000000011460`-`000000011463` passed. |
| C23 | UID0002QH remained verify-only; generated MapPane SHA-256 `22EE3A4B735F726D098BE4261C3A3B144EBF649D0D26A8EA2A4044C327F223F3` retains one unconditional SaveUserSettings call after presentation disable. |
| C24 | UID00040H/UID0001DO/OptionPane class/file record SaveToRegistry -> active-map-gated save -> close/remove; validators `000000011460`-`000000011464` passed and UID00040H formal remained unchanged. |
| C25 | Destination 3 and Spell class/Macro aggregate/file use `g_activeMapPane`, not dirty state; validators `000000011448`, `000000011465`-`000000011467` passed. |
| C26 | Destination 4 and Macro aggregate/file use `g_activeMapPane`; validators `000000011449`, `000000011466`, and `000000011467` passed. |
| C27 | Destination 5 plus Friend class/file preserve optional sync -> unconditional save -> close/remove; validators `000000011450`, `000000011469`, and `000000011470` passed. |
| C28 | Destination 6 plus Integrate class/aggregate/Macro file preserve clear -> close/remove -> active-map-gated save; validators `000000011451`, `000000011467`, `000000011471`, and `000000011472` passed. |
| C29 | UID0001E2/class/file record two-row write -> close/remove -> active-map-gated save while preserving blank formals; validators `000000011473`-`000000011475` passed. |
| C30 | Destination 2 applies explicit casts, `swprintf_s`, and `.text`; validator `000000011447` passed. |
| C31 | UID0000MS/UID0001QL/UID0001VR/UID0001V1 and RegistryConfig support are synchronized without score/route changes. Gate 2 repair validators `000000011504` and `000000011507` replaced the two inaccurate RegistryConfig summaries with all eight exact ordered groups, widths/counts/state branches, nonserialized byte `+3`, invalid-state output, and equality-to-one target booleans; both pages retain base-typed `Config *g_pConfig`, runtime `RegistryConfig`, explicit derived cast, no null guard, ProfileStorage ownership, destructive replacement/failure semantics, and the rejected old sequence as superseded history. |
| C32 | Target/support rejection and superseded-history sections retain MapPane/member/dialog ownership, dirty flag, SaveConfig, wrapper, payload, and raw-liveness negatives. |
| C33 | UID0001AV is `92/93` with exact Item Summary/Destination 1 and preserved metadata; original scoped validator `000000011446`, original waited refresh `000000011476`, and repair waited refresh `000000011508` passed. |
| C34 | Exact manual coverage replacement text below remains unchanged and supervisor-owned; B005 did not edit any `-coverage-report.md`. Validator-generated coverage metadata refresh was an authorized `000000011476`/`000000011508` side effect only. |
| C35 | Thirty original scoped page validators `000000011446`-`000000011475`, three focused repair validators `000000011503`/`000000011504`/`000000011507`, and waited refreshes `000000011476`/`000000011508` passed; generated hashes/counts are recorded below; no execute/lifecycle command ran and all leases were released. |

## Positive Evidence Summary

- Exact path literals, PlatformApi calls, g_pConfig profile-slice reads, repeated fwrite/fputwc sequence, inverse loader, and caller spread independently converge on the selected role and source root.
- Every section has direct loop-bound/stride/type evidence. The resulting C++ contains no raw addresses, offsets, `sub_`, `dword_`, decompiler temporaries, or omitted branch.
- The target's free/global ABI is supported by all eight direct calls and historical naming; no receiver is set before calls and no caller consumes a return.
- UID0000MS already groups the inverse loader/importer and sidecar helper, while the broad MapPane physical parent explicitly excludes this exact island.

## IDA MCP Facts

- Function: `sub_50ABA0`, start `0x0050aba0`, end `0x0050b078`, size `0x4d8`, prototype `void()`, 43 blocks, complexity 20.
- Bytes: target SHA-256 `0108F81842E9AD6A537622A52E799A65751424BA0237EF70F8AA566D0240BE14`; first 16 bytes `55 8B EC 6A FF 68 DF 26 60 00 64 A1 00 00 00 00`; last 16 bytes `5E 5B 8B 4D F0 33 CD E8 BB C6 0B 00 8B E5 5D C3`.
- Instructions: 363 in-range decoded instructions. Paged disassembly additionally reports 12 EH chunk instructions outside the half-open range; these are not separate source children.
- Cleanup: EH table ref `0x0065ff88` reaches cleanup `0x006026d4` for the local string destructor; `0x006026df` is security/CxxFrameHandler support.
- Calls by frequency: `fwrite` 14, `fputwc` six source callsites/loop bodies, c_str/data five, length two, wide-format support two, CreateDirectoryW two, GetLastError two, and one each SHGetFolderPathW, GetLocalPlayerName, string ctor/Format/dtor, SetFileAttributesW, DeleteFileW, wide open, fclose, and security check.
- Padding: 11 `0xcc` bytes before the target after `sub_50AB70`; eight `0xcc` bytes after before `sub_50B080`.
- Negative: no xref to `0x0050b078`; no absolute target VA/RVA pointer-byte match; no target-end pointer match; no vtable/data callback route.

## Exact Serialization Inventory

| Order | Source-facing field | Exact storage | Encoding and count | Edge behavior |
| --- | --- | --- | --- | --- |
| 1 | `m_profileTextSlots[10][0x80]` | `+0x28de9c`, stride `0x100` bytes | uint16 `wcslen`, then `fwrite(text, 2*length, 1)` | length narrows/truncates to uint16; no NUL |
| 2 | `m_legacyShortcutText[10][0x80]` | `+0x28e89c`, stride `0x100` | one `fputwc(row[0])` each | no count/length/terminator |
| 3 | `m_profileStringSlots[20]` | `+0x2911e0`, stride 4 | uint16 narrowed `.length()`, then byte-size payload | pointer-backed wide string |
| 4 | `m_selectedProfileName[0x100]` | `+0x2912b8` | uint16 `wcslen`, then byte-size payload | no NUL |
| 5 | `m_blockListenNames` | begin/end/capacity `+0x2918fc/+0x291900/+0x291904` | uint32 count; each uint32 length then `fwrite(text,2,length)` | 4-byte pointer-backed slots |
| 6 | `m_compactShortcutRecords[20]` | `+0x28f29c`, stride 4 | dword literal 1; wchar code plus `S`/`I` per row | byte +2 nonzero -> S; zero -> I; byte +3 omitted |
| 7 | `m_macroHotkeys[30]` | row `+0x28f2ec`, stride `0x108`; state `+4`, text `+8` | dword 30; type wchar; uint16 length; byte-size text | invalid state emits no type wchar but still length/text |
| 8 | `m_targetOptionRows[2]` | `+0x2911dc`, stride 2 | dword 2; two wchar booleans per row | exactly byte 1 -> `1`, all else -> `0` |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0050aba0-0x0050b078` | UID0001AV | one free ProfileStorage writer | true | UID0000MS | `86/90 -> 92/93` | populate Destination 1 |
| `0x0050ab95-0x0050aba0` | UID0000VN `-ignored` | preceding alignment | false/ignored | physical aggregate context | `100` | already exact |
| `0x0050b078-0x0050b080` | UID0000VN `-ignored` | following alignment | false/ignored | physical aggregate context | `100` | already exact |
| `0x006026d4`, `0x006026df` | no source child | compiler EH/security chunks | no handwritten source | generated from target local lifetime | n/a | no child/no C++ |
| `0x0053dd70-0x0053dda6` | retained inside UID0001DO | raw OptionPane commit/close body containing one target call | not a target child | OptionPane split index | n/a | prose evidence only |

## Direct Xref / Caller Inventory

| Callsite | Caller/source route | Exact target-call meaning |
| --- | --- | --- |
| `0x00504850` | UID0002QH `MapPane::ExitToMenu(bool)` | unconditional after map/presentation save stage and before later teardown/logout processing |
| `0x0053dd8c` | raw OptionPane `[0x0053dd70,0x0053dda6)` | active-map gated after RegistryConfig virtual SaveToRegistry; no inbound route to raw start |
| `0x0053dfb8` | UID00040H `OptionPane::OnOptionCommand` command 1 apply | active-map gated in legacy option apply/close route |
| `0x0053ed6e` | UID00049H `SpellMacroDialog::OnConfirm` | active-map gated after writing 10 legacy shortcut keys and closing/removing |
| `0x0053f15c` | UID00049L `NewMacroDialog::OnCommand` | active-map gated after save rows and close/remove |
| `0x0053f8f8` | UID0001DS `FriendListDialog::OnOkCommand` | unconditional after optional friend-list sync and before close/remove |
| `0x005420a7` | UID00045G `IntegrateMacroDialog::OnButtonClick` | active-map gated after clear/close/remove |
| `0x0054252a` | UID0001E2 `TargetOptionDialog::OnConfirm` | active-map gated after two-row write and close/remove |

## Documentation Evidence And IDA Status

- UID00019T is the exact inverse reader/importer and confirms source route plus optional-tail behavior. Its current formal is already detailed but uses three inconsistent source expressions fixed by Destination 2.
- UID0001QL and UID0001VR have the correct field-group backbone but lack complete writer-specific failure/width/count distinctions and still carry stale open-name wording.
- UID0001V1 already emits the exact `MacroHotkeyRecord` declaration with `.text`; the loader's `.payload` spelling is therefore invalid current source.
- UID0002AS/UID0002A6 already carry exact PlatformApi declarations, so their metadata/formals remain verify-only. Add only consumer prose if accepted and absent.
- Current caller pages prove the target's shared use, but four formal bodies and several class/file/aggregate summaries misclassify `g_activeMapPane` as a dirty flag. FriendList calls the right address under the wrong `SaveConfig()` name.
- Current manual coverage is stale for UID0001AV and several directly synchronized support rows; exact supervisor-owned replacement text appears below.

## Ranked Ownership Analysis

### 1. UID0000MS ProfileStorage

- Evidence for: exact modern `.usr` path, inverse loader/importer, shared UI callers, serialization-only body, current source tree, existing owner/emitter link, and explicit MapPane aggregate exclusion.
- Evidence against: exact original filename is stripped and could have been `UserProfile.cpp` or similar.
- Decision: retain as direct owner/emitter. Filename uncertainty is lexical and does not outweigh the complete module relationship.

### 2. UID0000BW RegistryConfig / Config source

- Evidence for: all serialized state resides in RegistryConfig and `g_pConfig` provides the object.
- Evidence against: writer is a free global, does no registry persistence, is called by unrelated UI modules, and is paired with free loader/import helpers already under ProfileStorage.
- Decision: storage/type owner and dependency only, not function source owner.

### 3. MapPane or caller UI classes

- Evidence for: target lies physically inside a broad MapPane address aggregate and several callers gate on active MapPane.
- Evidence against: no receiver, no MapPane fields, eight unrelated callers, profile path/format behavior, and current exact aggregate exclusion.
- Decision: reject. MapPane and dialogs are consumers/triggers only.

### Proposed new file/grouping, if applicable

- No new by-file page. Retain UID0000MS and `NexusTK/profile/ProfileStorage.cpp` containing ImportLegacyUserProfileData, LoadUserProfileData, RefreshSelectedProfileData, and SaveUserSettings.
- Do not move PlatformApi dispatch globals, RegistryConfig declarations, string infrastructure, or caller UI methods into this source root.

## Source Placement

- Recommended placement: global definition in `NexusTK/profile/ProfileStorage.cpp`, through by-file UID0000MS, alongside loader/import/sidecar helpers.
- Header-facing declaration is conceptually `void SaveUserSettings();`; current documentation emission is definition-oriented, so no separate by-file formal block is invented.
- Rejected: `MapPane.cpp`, `RegistryConfig.cpp`, `MacroDialogs.cpp`, `OptionPane.cpp`, `TargetOptionDialog.cpp`, and a new one-function source file.
- Remaining uncertainty: exact original filename/namespace and exact member spellings. Existing callers and generated placement support an unqualified global, so wrapping only this function in `namespace ProfileStorage` is rejected.

## Range / Split / Padding / Reclassification Analysis

- Exact target bytes are one modeled function. No internal code/data/padding split, alternate entry, raw successor, or child is required.
- Preserve parent physical overlap/exclusion with UID0001AT. UID0001AV remains directly attached to by-file UID0000MS, not to the mixed MapPane aggregate.
- Preserve current `Nested:-4`; it is cumulative relative sort depth, not a child count.
- Existing ignored ranges `[0x0050ab95,0x0050aba0)` and `[0x0050b078,0x0050b080)` are exact and require no duplicate entry.
- Add support-only OptionPane gap evidence: `[0x0053dd70,0x0053dda6)` is retained source-shaped code in UID0001DO; `[0x0053dda6,0x0053ddb0)` is ten `0xcc` bytes to add once to `by-memory/-ignored.md`. Do not create a source emitter or pretend the raw start is live.

## Negative Evidence Summary

- No target data/vtable callback pointer, alternate entry, end xref, split child, return consumer, status result, retry, temporary path, rename, rollback, exception report, or write-result check exists.
- No target behavior reads MapPane state or caller object state; active-map checks occur in callers, not inside SaveUserSettings.
- No evidence supports `g_userSettingsDirty`; exact storage `0x0067a764` is the active MapPane singleton pointer.
- No evidence supports `SaveConfig()` at `0x0053f8f8`; the call target is exactly UID0001AV.
- No evidence supports emitting `WideFormatWrapper`; current UID0002UA proves caller-local formatting support.
- No prior direct B report exists. Legacy Wave2 status and old imported source are not authority.

## IDA Rename / Type / Comment Recommendations

- Source-facing target: `SaveUserSettings`, global `void(void)`. Do not retain `_50ABA0` in source.
- Locals: `documentsPath`, `usersDirectory`, `userName`, `profilePath`, `file`, `length`, `count`; descriptive, not PDB-proven.
- Helpers/globals: `g_pfnWideOpenFile`, `g_pfnCreateDirectoryW`, `g_pfnDeleteFileW`, `g_pfnSetFileAttributesW`, `GetLocalPlayerName`, `g_pConfig`, and `g_activeMapPane` per current accepted docs.
- Fields: `m_profileTextSlots`, `m_legacyShortcutText`, `m_profileStringSlots`, `m_selectedProfileName`, `m_blockListenNames`, `m_compactShortcutRecords`, `m_macroHotkeys`, and `m_targetOptionRows`; role-accurate descriptive names.
- No IDA rename/type/comment mutation is requested or authorized. These recommendations are for documentation/formal source only.

## First-Draft C++ Recommendation

- Applied scope: UID0001AV and the five exact existing support formals whose former C++ was contradicted by accepted current evidence.
- Exactly six destination-specific managed blocks follow and were applied byte-for-byte. No C++ or declaration edit was made outside these blocks.

### Destination 1 - UID0001AV `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SaveUserSettings()
{
    RegistryConfig &config = *static_cast<RegistryConfig *>(g_pConfig);

    wchar_t documentsPath[MAX_PATH];
    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) != S_OK)
        return;

    wchar_t usersDirectory[MAX_PATH];
    swprintf_s(usersDirectory, L"%s\\NexusTK", documentsPath);
    if (!g_pfnCreateDirectoryW(usersDirectory, NULL) &&
        GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    swprintf_s(usersDirectory, L"%s\\NexusTK\\users", documentsPath);
    if (!g_pfnCreateDirectoryW(usersDirectory, NULL) &&
        GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    wchar_t userName[0x28];
    GetLocalPlayerName(userName, 0x28);

    SimpleUString profilePath;
    profilePath.Format(L"%s/%s.usr", usersDirectory, userName);

    g_pfnSetFileAttributesW(profilePath.c_str(), FILE_ATTRIBUTE_NORMAL);
    g_pfnDeleteFileW(profilePath.c_str());

    FILE *file = g_pfnWideOpenFile(profilePath.c_str(), L"wb");
    if (file == NULL)
        return;

    for (unsigned int i = 0; i < 10; ++i)
    {
        unsigned short length =
            static_cast<unsigned short>(wcslen(config.m_profileTextSlots[i]));
        fwrite(&length, sizeof(length), 1, file);
        fwrite(config.m_profileTextSlots[i], sizeof(wchar_t) * length, 1, file);
    }

    for (unsigned int i = 0; i < 10; ++i)
        fputwc(config.m_legacyShortcutText[i][0], file);

    for (unsigned int i = 0; i < 20; ++i)
    {
        unsigned short length = static_cast<unsigned short>(
            config.m_profileStringSlots[i].length());
        fwrite(&length, sizeof(length), 1, file);
        fwrite(config.m_profileStringSlots[i].c_str(),
               sizeof(wchar_t) * length,
               1,
               file);
    }

    unsigned short selectedProfileLength = static_cast<unsigned short>(
        wcslen(config.m_selectedProfileName));
    fwrite(&selectedProfileLength, sizeof(selectedProfileLength), 1, file);
    fwrite(config.m_selectedProfileName,
           sizeof(wchar_t) * selectedProfileLength,
           1,
           file);

    unsigned int count = static_cast<unsigned int>(config.m_blockListenNames.size());
    fwrite(&count, sizeof(count), 1, file);
    for (unsigned int i = 0; i < count; ++i)
    {
        const SimpleUString &name = config.m_blockListenNames[i];
        unsigned int length = name.length();
        fwrite(&length, sizeof(length), 1, file);
        fwrite(name.c_str(), sizeof(wchar_t), length, file);
    }

    unsigned int compactShortcutSectionPresent = 1;
    fwrite(&compactShortcutSectionPresent,
           sizeof(compactShortcutSectionPresent),
           1,
           file);
    for (unsigned int i = 0; i < 20; ++i)
    {
        fputwc(config.m_compactShortcutRecords[i].code, file);
        fputwc(config.m_compactShortcutRecords[i].isSpellMode ? L'S' : L'I', file);
    }

    count = 30;
    fwrite(&count, sizeof(count), 1, file);
    for (unsigned int i = 0; i < count; ++i)
    {
        const MacroHotkeyRecord &macro = config.m_macroHotkeys[i];
        switch (macro.state)
        {
        case MacroHotkeyRecord::Text:
            fputwc(L'T', file);
            break;
        case MacroHotkeyRecord::Spell:
            fputwc(L'S', file);
            break;
        case MacroHotkeyRecord::Item:
            fputwc(L'I', file);
            break;
        }

        unsigned short length = static_cast<unsigned short>(wcslen(macro.text));
        fwrite(&length, sizeof(length), 1, file);
        fwrite(macro.text, sizeof(wchar_t) * length, 1, file);
    }

    count = 2;
    fwrite(&count, sizeof(count), 1, file);
    for (unsigned int i = 0; i < count; ++i)
    {
        fputwc(config.m_targetOptionRows[i].userEnabled == 1 ? L'1' : L'0', file);
        fputwc(config.m_targetOptionRows[i].monsterEnabled == 1 ? L'1' : L'0', file);
    }

    fclose(file);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2 - UID00019T `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md`

The block below preserves the complete accepted current formal and changes only both `g_pConfig` bindings to explicit `RegistryConfig *` casts, both caller-local directory format calls to `swprintf_s`, and every stale macro `.payload` member to the declared `.text` member.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace ProfileStorage {
namespace {

constexpr unsigned int kLocalPlayerNameCch = 0x28;
constexpr unsigned int kLegacyPathCch = 0x80;
constexpr unsigned int kProfilePathCch = 0x104;
constexpr unsigned int kFixedProfileSlotCount = 10;
constexpr unsigned int kFixedProfileSlotCch = 0x80;
constexpr unsigned int kProfileStringSlotCount = 20;
constexpr unsigned int kSelectedProfileCch = 0x100;
constexpr unsigned int kCompactShortcutCount = 20;
constexpr unsigned int kMacroPayloadCch = 0x80;

void ReadLegacyQuotedWideString(FILE* file, wchar_t* out, size_t outCch)
{
    wchar_t scratch[512];
    unsigned short count = 0;
    unsigned int index = 0;

    int ch;
    do {
        ch = g_pfnReadUtf16CodeUnitFromFile(file);
    } while (ch != L'"' && ch != WEOF);

    for (;;) {
        ch = g_pfnReadUtf16CodeUnitFromFile(file);
        index = count;
        scratch[index] = static_cast<wchar_t>(ch);
        if (ch == L'"' || ch == WEOF) {
            break;
        }
        ++count;
    }

    if (index >= 512) {
        __report_rangecheckfailure(index * sizeof(wchar_t));
    }

    scratch[count] = L'\0';
    if (outCch == kSelectedProfileCch && count >= kSelectedProfileCch) {
        scratch[kSelectedProfileCch - 1] = L'\0';
    }
    wcscpy_s(out, outCch, scratch);
}

void ImportLegacyUserProfileData()
{
    wchar_t path[kLegacyPathCch];
    wchar_t userId[kLocalPlayerNameCch];

    g_pfnGetCurrentDirectoryW(kLegacyPathCch, path);
    GetLocalPlayerName(userId, kLocalPlayerNameCch);
    wcscat_s(path, kLegacyPathCch, L"\\users\\");
    wcscat_s(path, kLegacyPathCch, userId);
    wcscat_s(path, kLegacyPathCch, L".cfg");

    FILE* file = g_pfnWideOpenFile(path, L"rb");
    if (file == nullptr) {
        return;
    }

    RegistryConfig& cfg = *static_cast<RegistryConfig *>(g_pConfig);
    for (unsigned int i = 0; i < kFixedProfileSlotCount; ++i) {
        ReadLegacyQuotedWideString(file, cfg.m_profileTextSlots[i], kFixedProfileSlotCch);
    }
    for (unsigned int i = 0; i < kFixedProfileSlotCount; ++i) {
        ReadLegacyQuotedWideString(file, cfg.m_legacyShortcutText[i], kFixedProfileSlotCch);
    }
    for (unsigned int i = 0; i < kProfileStringSlotCount; ++i) {
        wchar_t scratch[512];
        ReadLegacyQuotedWideString(file, scratch, sizeof(scratch) / sizeof(scratch[0]));
        cfg.m_profileStringSlots[i].AssignWideCString(scratch);
    }

    ReadLegacyQuotedWideString(file, cfg.m_selectedProfileName, kSelectedProfileCch);

    fclose(file);
    g_pfnDeleteFileW(path);
}

bool EnsureDirectoryExists(const wchar_t* path)
{
    if (g_pfnCreateDirectoryW(path, nullptr)) {
        return true;
    }
    return GetLastError() == ERROR_ALREADY_EXISTS;
}

bool ReadLengthPrefixedWide(FILE* file, wchar_t* out, size_t outCch, unsigned int maxChars)
{
    unsigned short length = 0;
    fread(&length, sizeof(length), 1, file);
    if (length > maxChars || length >= outCch) {
        return false;
    }
    fread(out, sizeof(wchar_t), length, file);
    out[length] = L'\0';
    return true;
}

void ReadProfileStringSlot(FILE* file, SimpleUString& out)
{
    unsigned short length = 0;
    fread(&length, sizeof(length), 1, file);
    out.Remove(0, npos);
    wchar_t* buffer = out.SetLengthWideAndDetach(length);
    fread(buffer, sizeof(wchar_t), length, file);
    out.LockWideBuffer();
}

void MigrateLegacyShortcuts(RegistryConfig& cfg)
{
    for (unsigned int i = 0; i < kFixedProfileSlotCount; ++i) {
        const wchar_t code = cfg.m_legacyShortcutText[i][0];
        if (code == L'\0') {
            continue;
        }

        cfg.m_compactShortcutRecords[i].code = code;
        cfg.m_compactShortcutRecords[i].isSpellMode = true;
        cfg.m_legacyShortcutText[i][0] = L'\0';
    }

    for (unsigned int i = 0; i < kCompactShortcutCount; ++i) {
        CompactShortcutRecord& shortcut = cfg.m_compactShortcutRecords[i];
        if (shortcut.code == L'\0') {
            continue;
        }

        MacroHotkeyRecord& macro = cfg.m_macroHotkeys[i];
        macro.state = shortcut.isSpellMode ? 2 : 3;
        macro.text[0] = shortcut.code;
        macro.text[1] = L'\0';
        shortcut.code = L'\0';
    }
}

} // namespace

void LoadUserProfileData()
{
    RegistryConfig& cfg = *static_cast<RegistryConfig *>(g_pConfig);
    cfg.InitializeUserDataDefaults();

    wchar_t documents[MAX_PATH];
    if (SHGetFolderPathW(nullptr, CSIDL_PERSONAL, nullptr, 0, documents) != S_OK) {
        return;
    }

    wchar_t path[kProfilePathCch];
    swprintf_s(path, L"%s\\NexusTK", documents);
    if (!EnsureDirectoryExists(path)) {
        return;
    }

    swprintf_s(path, L"%s\\NexusTK\\users", documents);
    if (!EnsureDirectoryExists(path)) {
        return;
    }

    wchar_t userId[kLocalPlayerNameCch];
    GetLocalPlayerName(userId, kLocalPlayerNameCch);

    SimpleUString profilePath;
    profilePath.Format(L"%s/%s.usr", path, userId);

    FILE* file = g_pfnWideOpenFile(profilePath.c_str(), L"rb");
    if (file == nullptr) {
        g_pfnGetCurrentDirectoryW(kLegacyPathCch, path);
        profilePath.Format(L"%s/users/%s.usr", path, userId);
        file = g_pfnWideOpenFile(profilePath.c_str(), L"rb");
        if (file == nullptr) {
            ImportLegacyUserProfileData();
            return;
        }
    }

    for (unsigned int i = 0; i < kFixedProfileSlotCount; ++i) {
        if (!ReadLengthPrefixedWide(file, cfg.m_profileTextSlots[i], kFixedProfileSlotCch, 0x7f)) {
            return;
        }
    }

    for (unsigned int i = 0; i < kFixedProfileSlotCount; ++i) {
        cfg.m_legacyShortcutText[i][0] = static_cast<wchar_t>(fgetwc(file));
        cfg.m_legacyShortcutText[i][1] = L'\0';
    }

    for (unsigned int i = 0; i < kProfileStringSlotCount; ++i) {
        ReadProfileStringSlot(file, cfg.m_profileStringSlots[i]);
    }

    ReadLengthPrefixedWide(file, cfg.m_selectedProfileName, kSelectedProfileCch, 0xffff);

    uint32_t count = 0;
    if (fread(&count, sizeof(count), 1, file) == 1) {
        cfg.m_blockListenNames.clear();
        for (uint32_t i = 0; i < count; ++i) {
            uint32_t length = 0;
            fread(&length, sizeof(length), 1, file);
            SimpleUString value;
            wchar_t* data = value.SetLengthWideAndDetach(length);
            fread(data, sizeof(wchar_t), length, file);
            value.LockWideBuffer();
            cfg.m_blockListenNames.push_back(value);
        }
    }

    uint32_t present = 0;
    if (fread(&present, sizeof(present), 1, file) == 1) {
        for (unsigned int i = 0; i < kCompactShortcutCount; ++i) {
            cfg.m_compactShortcutRecords[i].code = static_cast<wchar_t>(fgetwc(file));
            cfg.m_compactShortcutRecords[i].isSpellMode = (fgetwc(file) == L'S');
        }
    }

    count = 0;
    if (fread(&count, sizeof(count), 1, file) == 1 && count != 0) {
        for (uint32_t i = 0; i < count; ++i) {
            const wint_t type = fgetwc(file);
            if (type == L'I') {
                cfg.m_macroHotkeys[i].state = 3;
            } else if (type == L'S') {
                cfg.m_macroHotkeys[i].state = 2;
            } else if (type == L'T') {
                cfg.m_macroHotkeys[i].state = 1;
            }

            unsigned short length = 0;
            fread(&length, sizeof(length), 1, file);
            if (length < kMacroPayloadCch) {
                fread(cfg.m_macroHotkeys[i].text, sizeof(wchar_t), length, file);
                cfg.m_macroHotkeys[i].text[length] = L'\0';
            }
        }
    }

    count = 0;
    if (fread(&count, sizeof(count), 1, file) == 1 && count != 0) {
        for (uint32_t i = 0; i < count; ++i) {
            cfg.m_targetOptionRows[i].userEnabled = (fgetwc(file) == L'1');
            cfg.m_targetOptionRows[i].monsterEnabled = (fgetwc(file) == L'1');
        }
    }

    MigrateLegacyShortcuts(cfg);
    fclose(file);
}

} // namespace ProfileStorage
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3 - UID00049H `by-memory/0x0053ecf0-0x0053ed7a.SpellMacroDialogOnConfirm.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SpellMacroDialog::OnConfirm(int commandId, int /*controlId*/)
{
    if (commandId != kDialogCommandOk)
        return;

    for (int row = 0; row < 10; ++row)
    {
        SpellMacroEditControlPane *edit = GetChild<SpellMacroEditControlPane>(2 + row);
        g_pConfig->m_legacyShortcutText[row][0] = edit->GetSpellKey();
        g_pConfig->m_legacyShortcutText[row][1] = 0;
    }

    Close();
    g_pGeneralPurposePanel->RemoveDialog(this);

    if (g_activeMapPane != NULL)
        SaveUserSettings();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - UID00049L `by-memory/0x0053f0a0-0x0053f166.NewMacroDialogOnCommand.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewMacroDialog::OnCommand(int commandId, int controlId)
{
    switch (commandId)
    {
    case kDialogCommandOk:
        SaveMacroEntries();
        Close();
        g_pGeneralPurposePanel->RemoveDialog(this);
        if (g_activeMapPane != NULL)
            SaveUserSettings();
        break;

    case kMacroFirstPageCommand:
        GetChild<ImageButtonControlPane>(kMacroFirstPageCommand)->Disable();
        GetChild<ImageButtonControlPane>(kMacroSecondPageCommand)->Enable();
        SaveMacroEntries();
        LoadMacroPage(0);
        break;

    case kMacroSecondPageCommand:
        GetChild<ImageButtonControlPane>(kMacroFirstPageCommand)->Enable();
        GetChild<ImageButtonControlPane>(kMacroSecondPageCommand)->Disable();
        SaveMacroEntries();
        LoadMacroPage(1);
        break;

    default:
        (void)controlId;
        break;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5 - UID0001DS `by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {
constexpr int kFriendNameSlotCount = 20;
constexpr int kFriendNameRowsPerColumn = 10;
constexpr int kFriendNameFirstControlId = 2;
constexpr int kFriendNameTextCapacity = 64;

constexpr wchar_t kFriendListTitle[] = L"Friend List";
constexpr wchar_t kFriendPalette[] = L"FRIEND.PAL";
constexpr wchar_t kFriendListEpf[] = L"FRIEND.EPF";
constexpr wchar_t kFriendListEpd[] = L"FRIEND.EPD";
constexpr wchar_t kNpal8Palette[] = L"NPAL8.PAL";
constexpr wchar_t kWideTrimWhitespace[] = L" \t\n\r";

struct FriendListLayout {
    const wchar_t *panelArt;
    const wchar_t *palette;
    Rect panelRect;
    Rect okButtonRect;
    int leftX;
    int rightX;
    int firstY;
    int rowStep;
    int editWidth;
    int editHeight;
    Rect dialogRect;
    bool centerOnScreen;
};

const FriendListLayout kFriendListModernLayout = {
    kFriendListEpf,
    kFriendPalette,
    Rect(0, 0, 332, 399),
    Rect(138, 363, 201, 387),
    49,
    199,
    60,
    29,
    84,
    12,
    Rect(0, 0, 332, 399),
    true,
};

const FriendListLayout kFriendListClassicLayout = {
    kFriendListEpd,
    kNpal8Palette,
    Rect(0, 0, 407, 391),
    Rect(168, 341, 240, 357),
    104,
    246,
    94,
    21,
    78,
    12,
    Rect(130, 10, 537, 401),
    false,
};
}

FriendListDialog::FriendListDialog()
    : DialogPane(kFriendListTitle, 11, true)
{
    const FriendListLayout &layout =
        g_useFriendListEpfLayout ? kFriendListModernLayout : kFriendListClassicLayout;

    AddChild(new ImagePane(layout.panelRect, layout.panelArt, layout.palette));
    AddChild(new ButtonPane(kFriendNameFirstControlId - 1, layout.okButtonRect));

    for (int row = 0; row < kFriendNameRowsPerColumn; ++row) {
        const int y = layout.firstY + row * layout.rowStep;

        AddChild(new TextEditPane(
            kFriendNameFirstControlId + row,
            Rect(layout.leftX, y, layout.leftX + layout.editWidth, y + layout.editHeight),
            g_pConfig->m_friendNames[row]));

        AddChild(new TextEditPane(
            kFriendNameFirstControlId + kFriendNameRowsPerColumn + row,
            Rect(layout.rightX, y, layout.rightX + layout.editWidth, y + layout.editHeight),
            g_pConfig->m_friendNames[kFriendNameRowsPerColumn + row]));
    }

    SetInitialControl(kFriendNameFirstControlId);
    EnableDialogInput(true);
    SetDialogResourceName(layout.panelArt);

    Rect dialogRect = layout.dialogRect;
    if (layout.centerOnScreen) {
        dialogRect.Offset((g_screenWidth - layout.panelRect.Width()) / 2,
                          (g_screenHeight - layout.panelRect.Height()) / 2);
    }

    SetBounds(dialogRect);
    AttachToDialogRoot(g_dialogRoot);
    SetPalette(g_dialogPalette);
    Show();
}

FriendListDialog::~FriendListDialog()
{
}

void FriendListDialog::OnOkCommand(int commandId, int controlId)
{
    if (commandId != 1) {
        return;
    }

    wchar_t text[kFriendNameTextCapacity];

    for (int slot = 0; slot < kFriendNameSlotCount; ++slot) {
        TextEditPane *edit = static_cast<TextEditPane *>(
            m_childControls->GetControl(kFriendNameFirstControlId + slot));

        edit->GetText(text, kFriendNameTextCapacity);

        WideString &friendName = g_pConfig->m_friendNames[slot];
        friendName.Assign(text);
        friendName.TrimLeft(kWideTrimWhitespace);
        friendName.TrimRight(kWideTrimWhitespace);
    }

    if (g_friendNameListSyncEnabled) {
        BuildAndSendFriendNameListSync(g_packetSender);
    }

    SaveUserSettings();
    CloseDialog(this);
    g_dialogManager->RemoveDialog(this);
}

void FriendListDialog::OnFocusStateChanged(int focusState)
{
    DialogPane::OnFocusStateChanged(focusState);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6 - UID00045G `by-memory/0x00541fa0-0x005420b1.IntegrateMacroDialogOnButtonClick.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void IntegrateMacroDialog::OnButtonClick(int commandId, int /*controlId*/)
{
    switch (commandId)
    {
    case kDialogCommandOk:
        ClearMacroEditFields();
        Close();
        g_pGeneralPurposePanel->RemoveDialog(this);
        if (g_activeMapPane != NULL)
            SaveUserSettings();
        break;

    case kMacroPreviousPageCommand:
        ClearMacroEditFields();
        if (m_currentPage <= 0)
            break;

        --m_currentPage;

        GetChild<ImageButtonControlPane>(kMacroNextPageCommand)->Enable();
        GetChild<ImageButtonControlPane>(kMacroPreviousPageCommand)->Deactivate();

        if (m_currentPage == 0)
            GetChild<ImageButtonControlPane>(kMacroPreviousPageCommand)->Disable();

        RefreshMacroEditFields();
        break;

    case kMacroNextPageCommand:
        ClearMacroEditFields();
        if (m_currentPage >= m_pageCount - 1)
            break;

        ++m_currentPage;

        GetChild<ImageButtonControlPane>(kMacroPreviousPageCommand)->Enable();
        GetChild<ImageButtonControlPane>(kMacroNextPageCommand)->Deactivate();

        if (m_currentPage == m_pageCount - 1)
            GetChild<ImageButtonControlPane>(kMacroNextPageCommand)->Disable();

        RefreshMacroEditFields();
        break;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 1 preserves exact early returns, mutation order, widths, loops, unknown-state omission, equality-to-one booleans, and ignored results. It deliberately does not add a g_pConfig guard, temporary file, error return, write checks, fallback path, or source-level EH mechanics.
- Destination 2 is independently verifiable as the complete existing block plus only the listed corrections. No loader behavior or optional-tail logic is otherwise changed.
- Destinations 3-6 preserve their complete accepted existing bodies and change only the contradicted target-call gate/name expression.
- Third-party import directive: not applicable. All six blocks are NexusTK/project source, not vetted static third-party source.

## Final Recommendation

- C01-C35 and all six literal blocks are applied/verified. UID0001AV is `92/93`, its former blank body and Item Summary are replaced, and all other target metadata is preserved.
- Preserve direct parent/emitter UID0000MS and global source placement. Do not split UID0001AV or add a position.
- Complete format/failure/caller/negative/history evidence is applied to the target and listed support pages at report-level detail.
- Focused Gate 2 repair is complete: UID0002AA now distinguishes the local-player-name filename stem from serialization section 1, and both RegistryConfig pages carry the exact ordered eight-section consumer inventory while retaining the rejected older sequence only as superseded history.
- UID0002AS, UID0002A6, UID0002UA, UID0002QH, UID0001AT, g_activeMapPane, and current ignored target padding were verified without edits.
- Exact work outside this assignment: original PDB/source spelling recovery only. It is not a blocker and should not be presented as pending B005 implementation work.

## Recommended Target Doc Changes

- Applied/verified status: complete in scoped validator `000000011446`, original waited refresh `000000011476`, and latest focused-repair waited refresh `000000011508`.
- The detailed change language below is retained as the accepted implementation specification and completed callback record, not as future B005 work.
- Path: `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md`.
- Applied `COMPLETION:92`, `CONFIDENCE:93`; preserved UID, title/path/range, owner `0000MS`, reconstructable true, emitter `0000MS`, blank position, and `Nested:-4`.
- Exact Item Summary: `Source-ready global ProfileStorage .usr writer with exact range/hash/CFG and eight caller routes; constructs Documents\\NexusTK\\users, destructively replaces the current user file, serializes all eight fixed/string/vector/shortcut/macro/target-option sections with exact widths/counts/edge behavior, preserves ignored write failures and malformed unknown macro states, and emits complete human C++.`
- Destination 1 is inserted exactly.
- Exact byte/hash/instruction/CFG/ABI/EH, predecessor/successor/padding, all eight groups, caller table, helper prototypes, field map, failure paths, ignored results, source placement, negative searches, ranked alternatives, and historical corrections are present.
- The old parent-gate/unassigned sentence is historicalized; UID0000MS remains the accepted parent.

## Recommended Support Doc Changes

- Applied/verified status: every accepted ordinary support page below was updated under its recorded scoped validator, while listed verify-only dependencies remained unchanged.
- The detailed bullets below retain the accepted destination specification for auditability; all stated callback actions are complete.
- `by-file/ProfileStorage.md` UID0000MS: keep `88/87`, path, owner, and lack of formal block. Replace `SaveUserSettings_50ABA0` with source-facing `SaveUserSettings`, add the exact eight-section writer/failure/caller inventory, clarify global/unqualified placement, correct seven-caller wording to eight xrefs including the raw no-route span, and retain exact-filename uncertainty as the confidence cap.
- `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` UID00019T: preserve `88/90`, range, owner/emitter, nesting, all research, and apply Destination 2 exactly. Add inverse writer cross-check and historicalize `WideFormatWrapper`/`.payload`/uncast binding as superseded source expressions.
- `by-meta/client_profile_storage.md` UID0001QL: preserve `-1/-1`; add exact writer operation order, destructive replacement/open/write failure consequences, group 6 presence-versus-count distinction, invalid macro-state stream hazard, equality-to-one trailing flags, eight callers, and resolved descriptive field names.
- `by-type/by-struct/RegistryConfigUserProfileBlock.md` UID0001VR: preserve `88/88`, comment-only formal, owner/emitter, and complete existing evidence. Add every exact writer group, compact byte +3 non-serialization, vector uint32 widths, target row byte roles, and close stale statements that these profile member roles still block source.
- `by-type/by-struct/MacroHotkeyRecord.md` UID0001V1: preserve `88/90`, declaration/formal/owner/emitter. Add writer-specific invalid-state omission and confirm `.text`, not `.payload`, is the synchronized formal member.
- `by-class/RegistryConfig.md`, `by-file/RegistryConfig.md`, and `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` UID00028Q: scores/routes/formals unchanged; retain base-typed `Config *g_pConfig`, runtime `RegistryConfig`, explicit derived cast, no null guard, and ProfileStorage ownership. The class/file pages now state the exact writer inventory in order: (1) ten fixed `m_profileTextSlots` wchar rows with narrowed `uint16_t` length and byte-size payload/no NUL; (2) ten legacy first-wchar values with no header/length/terminator; (3) twenty pointer-backed strings with narrowed `uint16_t` length and byte-size payload; (4) selected-profile wchar array with `uint16_t` length and payload/no NUL; (5) `uint32_t` block-listen count and per-row `uint32_t` length plus `fwrite(text, 2, length)`; (6) literal dword `1` and twenty compact code/mode pairs, `S` for nonzero byte `+2`, `I` for zero, with byte `+3` not serialized; (7) dword `30` and thirty macro rows, `T`/`S`/`I` for states `1`/`2`/`3`, while invalid state omits the type wchar but still writes `uint16_t` length/text; and (8) dword `2` plus two target-option rows/four wchar booleans where only source byte exactly `1` emits `L'1'`. The displaced compact-target/macro/spell/inventory/friend/options sequence remains only as explicitly superseded/rejected history. Destructive replacement, ignored write/close results, partial/truncated output, malformed invalid-state output, and no rollback remain ProfileStorage behavior.
- `by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md` UID0002AA: preserve metadata/formal; record exact `errno_t GetLocalPlayerName(wchar_t *destination, size_t capacity)` copy-out contract at `0x005a2da0`, its direct `wcscpy_s` result, the writer's local `wchar_t[40]`, capacity `0x28`, and ignored return. The local result is only the `<user-id>` filename stem for `%s/%s.usr`, not a serialized field; section 1 is the ten `RegistryConfig::m_profileTextSlots` rows.
- `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`, `by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md`, and `by-global/WideApiDispatchTable.md`: verify-only unless consumer prose lacks UID0001AV. Their exact function-pointer declarations, scores, owners, and formals already satisfy C07.
- `by-memory/0x004236e0-0x00423710.WideFormatWrapper.md` UID0002UA: verify-only; it already proves caller-local `swprintf_s` and non-emitting compiler/UCRT disposition.
- `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md`, `by-class/MapPane.md`, `by-file/MapPane.md`, and UID0002QH teardown: verify-only. Preserve exact ProfileStorage exclusion and call order; do not revive the stale wrong address in an old executed report.
- `by-memory/0x0053d820-0x0053e520.OptionPane.md` UID0001DO, `by-class/OptionPane.md`, and `by-file/OptionPane.md`: scores/routes/formals unchanged. Add exact `[0x0053dd70,0x0053dda6)` raw commit/close body, active-map gate, zero start xrefs/pointer route, and no-emitter disposition. Add `[0x0053dda6,0x0053ddb0)` once to `by-memory/-ignored.md` as ten `0xcc` bytes. UID00040H keeps its formal unchanged because `ApplyLegacyOptionSelections()` is the accepted source abstraction; add exact apply-path SaveToRegistry/active-map/close sequencing in prose.
- `by-memory/0x0053ecf0-0x0053ed7a.SpellMacroDialogOnConfirm.md` UID00049H: preserve `88/91`/metadata and apply Destination 3; replace all current dirty-state prose/Item Summary with active-map pointer wording. Synchronize `by-class/SpellMacroDialog.md`, `by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md`, and `by-file/MacroDialogs.md` at the same detail.
- `by-memory/0x0053f0a0-0x0053f166.NewMacroDialogOnCommand.md` UID00049L: preserve `89/91`/metadata and apply Destination 4; correct dirty-state prose to active-map pointer gating. Keep NewMacro class/aggregate/file unrelated content.
- `by-class/MacroDialog.md`: correct the stale statement that UID00049E saves dirty settings. UID00049E copies ten profile text rows and closes/removes but does not call UID0001AV; no formal change.
- `by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md` UID0001DS: preserve `90/91`/metadata and apply Destination 5; replace `SaveConfig()` with exact `SaveUserSettings()` and retain optional sync -> save -> close/remove ordering. Synchronize FriendList class/file without score changes.
- `by-memory/0x00541fa0-0x005420b1.IntegrateMacroDialogOnButtonClick.md` UID00045G: preserve `91/92`/metadata and apply Destination 6; replace dirty-state prose/table/Item Summary with active-map pointer wording. Synchronize Integrate class, UID0001E1 aggregate, and MacroDialogs file without score changes.
- `by-memory/0x00542270-0x0054259f.TargetOptionDialog.md` UID0001E2, class UID0000EE, and file UID0000OG: preserve all metadata/scores/formal blanks. Correct behavior order to write two rows -> close/remove -> active-map-gated SaveUserSettings; close the target-call name/gate blocker. Keep the mixed aggregate blank because it still contains constructor, destructor helper, confirm, padding, and raw config-save helper; this callback does not emit a partial aggregate body.
- Generated/coverage/tracker/supervisor files remain read-only. No support destination beyond Destinations 2-6 receives C++.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/90`, owner/emitter 0000MS, reconstructable true, blank position/formal, `Nested:-4`.
- Current applied target: `92/93`, same owner/emitter/reconstructable/position/nesting/range/path/title, populated Destination 1 and exact Item Summary.
- Completion rises because every body/group/failure/caller/helper/type/source blocker is closed and formal source is complete. Confidence rises to 93 because direct MCP, inverse reader, support declarations, and caller bodies converge.
- Not higher: original source filename/namespace and exact local/member/helper spellings are not symbol-proven; SimpleUStringVector public accessor spelling remains source-level inference even though its pointer-triplet behavior and stream output are exact.
- UID0000MS stays `88/87`; this pass strengthens its writer inventory but does not recover exact filename. All other support scores and metadata remain unchanged.
- No split, rename, new UID, owner/emitter, reconstructable, position, or nesting change was made.

## Open Questions With Attempted Resolution

- Was the original filename exactly `ProfileStorage.cpp`? Checked address locality, current source graph, inverse loader/importer/sidecar grouping, callers, old reports, and generated route. Best supported placement is UID0000MS; exact spelling remains lexical and caps confidence only.
- Is SaveUserSettings a RegistryConfig member? Checked all calls for receiver setup, prototype/return use, object accesses, and owner graph. No receiver exists; resolved as global free helper.
- Is `0x0067a764` a dirty flag? Checked global docs, caller decompilation, and MapPane lifecycle. Resolved as `g_activeMapPane`; dirty interpretation rejected.
- What is group 6's leading dword? Checked writer literal and loader behavior. Resolved as presence/version-style optional-tail marker `1`, not 20-row count.
- What happens for invalid macro state? Checked switch fallthrough and subsequent writes. Resolved exactly: omit type wchar, still write length/text, yielding malformed stream.
- Is raw `0x0053dd70` live? Checked function record, direct xrefs, code/data refs, VA/RVA pointer bytes, and surrounding bytes. No route exists; retained support-only source-shaped body, not a proven runtime caller/emitter.
- Do file/write failures propagate? Checked every call return consumer and all exits. Only pre-open path/directory/open failures return early; write/close failures are ignored and function always returns void.
- No unresolved question blocks target score, metadata, source placement, or C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- B005 read the evidence-time manual rows in `by-memory/-coverage-report.md`, `by-file/-coverage-report.md`, `by-class/-coverage-report.md`, `by-meta/-coverage-report.md`, and `by-type/by-struct/-coverage-report.md` for every accepted target/support destination. B005 did not edit these files.
- Exact replacement for `by-memory/-coverage-report.md` UID0001AV row:

```text
    - [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) 0x0050aba0-0x0050b078 | global function | SaveUserSettings : reconstructable : 92% : very strong : Source-ready ProfileStorage .usr writer with exact range/hash/CFG and eight caller routes; constructs Documents\NexusTK\users, destructively replaces the current user file, serializes all eight fixed/string/vector/shortcut/macro/target-option sections with exact widths/counts/edge behavior, preserves ignored write failures and malformed unknown macro states, and emits complete human C++ through [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md).
```

- Exact replacement for `by-memory/-coverage-report.md` UID00019T row:

```text
    - [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md) 0x004f9280-0x004f9d28 | function-pair aggregate | ProfileLoadAndLegacyImport : reconstructable : 88% : strong : Parent-attached ProfileStorage loader/importer with exact function/padding boundaries, modern Documents and current-directory .usr paths, legacy quoted .cfg import/delete flow, all profile sections and optional tails, migration behavior, type-correct RegistryConfig access, caller-local swprintf_s formatting, MacroHotkeyRecord::text synchronization, and complete formal source.
```

- Exact replacement for `by-memory/-coverage-report.md` UID0001DO row and exact following insertion for ignored padding:

```text
    - [UID:0001DO][0x0053d820-0x0053e520.OptionPane](by-memory/0x0053d820-0x0053e520.OptionPane.md) 0x0053d820-0x0053e520 | non-emitting split index | OptionPane : not_reconstructable : 89% : very strong : Old OptionPane split index with exact constructor/destructor/command/server/helper/data children, vtable/resource/field evidence, and retained no-route commit/close body at 0x0053dd70-0x0053dda6; that raw body saves RegistryConfig, gates SaveUserSettings on g_activeMapPane, closes/removes the pane, and remains support-only because no start xref or pointer route exists.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0053dda6-0x0053ddb0 | padding | OptionPane raw commit/close body to OnOptionCommand alignment : ignored : 100% : strong : Confirmed ten 0xcc bytes after the retained no-route 0x0053dd70-0x0053dda6 body and before modeled OnOptionCommand at 0x0053ddb0.
```

- Exact replacement for `by-memory/-coverage-report.md` UID0001DR row:

```text
    - [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md) 0x0053e520-0x0053f2b6 | non-emitting class-method split index | MacroDialogs : not_reconstructable : 90% : very strong : Exact MacroDialog, SpellMacroDialog, and NewMacroDialog child inventory with boundaries/padding, class/file/vtable/destructor routes, profile-field consumers, complete child-owned formal C++, no duplicate aggregate source, and corrected SaveUserSettings caller semantics: MacroDialog SaveMacros is not a caller, while Spell/New confirm paths gate persistence on g_activeMapPane rather than a dirty flag.
```

- Exact replacement for `by-memory/-coverage-report.md` UID0001DS row:

```text
    - [UID:0001DS][0x0053f2c0-0x0053f939.FriendListDialog](by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md) 0x0053f2c0-0x0053f939 | class-method cluster | FriendListDialog : reconstructable : 90% : very strong : Complete 20-slot friend editor with EPF/EPD layouts, exact boundaries/callers, config string trim/store behavior, optional opcode 0x77 friend-name sync, unconditional SaveUserSettings after that optional send, close/remove ordering, destructor support, class/file ownership, and complete formal source.
```

- Exact replacement for `by-memory/-coverage-report.md` UID0001E1 row:

```text
    - [UID:0001E1][0x00541b30-0x00542265.IntegrateMacroDialog](by-memory/0x00541b30-0x00542265.IntegrateMacroDialog.md) 0x00541b30-0x00542265 | non-emitting class-method split index | IntegrateMacroDialog : not_reconstructable : 90% : very strong : Exact integrated macro dialog child inventory with constructor/draw/button/key/clear/refresh methods, vtable/destructor/resource/profile-row routes, child-owned source, no aggregate duplication, and corrected command-1 persistence gate on g_activeMapPane rather than a dirty flag.
```

- Exact replacement for `by-memory/-coverage-report.md` UID0001E2 row:

```text
    - [UID:0001E2][0x00542270-0x0054259f.TargetOptionDialog](by-memory/0x00542270-0x0054259f.TargetOptionDialog.md) 0x00542270-0x0054259f | class-helper cluster | TargetOptionDialog : reconstructable : 86% : strong : TargetOptionDialog constructor/destructor/confirm/raw-save aggregate with exact two child rows, ARROW/SHIFT+ARROW user/monster bytes, config writeback, corrected write -> close/remove -> g_activeMapPane-gated SaveUserSettings ordering, padding/thunk boundaries, and preserved blank aggregate formal pending independent child splitting rather than partial duplicate source.
```

- Exact replacement for `by-file/-coverage-report.md` UID0000MS row:

```text
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md) : reconstructable : 88% : strong : Profile persistence source root for modern .usr load/save, legacy .cfg import, selected-profile sidecar refresh, exact field/layout dependencies, complete SaveUserSettings eight-section writer and failure semantics, eight caller routes, and rejected MapPane/RegistryConfig/UI ownership; exact original filename remains the confidence cap.
```

- Exact replacement for `by-meta/-coverage-report.md` UID0001QL row:

```text
- [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md) : reconstructable : 50% : medium : Complete modern .usr and legacy .cfg profile-storage contract: exact paths/fallbacks, eight writer/loader sections and widths, optional-tail/migration behavior, destructive save/open/write failure semantics, macro invalid-state hazard, target-option equality encoding, selected-profile sidecars, field roles, and caller/source ownership.
```

- Exact replacements for `by-type/by-struct/-coverage-report.md` UID0001V1 and UID0001VR rows:

```text
- [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) : reconstructable : 88% : very strong : Exact 0x108-byte 30-row macro/hotkey record with ordinal/reserved/state/text layout, Text/Spell/Item states 1/2/3 and T/S/I serialization, defaults/load/save/UI/runtime consumers, declared text member, and preserved malformed-stream behavior when the writer encounters an invalid state.
- [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) : reconstructable : 88% : strong : Comment-only RegistryConfig profile-layout slice with resolved role-accurate fixed strings, legacy shortcuts, compact records, 30 macro rows, two target-option rows, 20 pointer-backed strings, selected-profile text, and block-listen vector; complete default/load/save/UI/runtime evidence and exact eight-section writer widths/counts are documented while exact original member spelling remains inferred.
```

- Exact replacements for changed by-class rows:

```text
- [UID:00007I][MacroDialog](by-class/MacroDialog.md) : reconstructable : 88% : very strong : Older keyboard macro dialog with exact constructor/save/destructor children, vtable/file ownership, profile-text rows and complete source; SaveMacros copies rows and closes/removes but does not call SaveUserSettings.
- [UID:0000DP][SpellMacroDialog](by-class/SpellMacroDialog.md) : reconstructable : 88% : very strong : Spell macro dialog with exact constructor/confirm/visibility/destructor children, ten legacy shortcut rows, complete source, and corrected g_activeMapPane-gated SaveUserSettings persistence after close/remove.
- [UID:00005J][FriendListDialog](by-class/FriendListDialog.md) : reconstructable : 85% : strong : Friend-list dialog class with 20 config-backed text rows, dual asset layouts, optional friend sync, unconditional SaveUserSettings, close/remove ordering, and exact memory/file/destructor support.
- [UID:00006L][IntegrateMacroDialog](by-class/IntegrateMacroDialog.md) : reconstructable : 88% : very strong : Integrated macro dialog class with exact constructor/draw/button/key/clear/refresh children, three-page MacroHotkeyRecord binding, complete source, and corrected g_activeMapPane-gated persistence on command 1.
```

- Current by-class OptionPane/TargetOptionDialog and by-file OptionPane/MacroDialogs/FriendListDialog/TargetOptionDialog rows were inspected. Their paths/scores/states remain unchanged; their broad descriptions do not assert the contradicted dirty flag or wrong SaveConfig name, so they are verify-only and need no mandatory row change beyond the exact replacements above. Child UID00049H/UID00049L/UID00045G/UID00040H rows are absent from the current manual by-memory coverage matrix; no new page/path/state/score is created, so no insertion is required.
- Reason B005 did not apply any text above: all `-coverage-report.md` files and tracker state are supervisor-owned/manual or validator-owned lifecycle surfaces outside B005's ordinary-document callback scope.

## Follow-Up Actions

- B005's accepted research and implementation responsibilities are complete: C01-C35/Destinations 1-6 are applied/verified, ordinary pages passed scoped validation, the waited refresh completed, generated output was inspected read-only, and all leases were released.
- Exact manual coverage replacement text remains preserved above as supervisor-owned external state. B005 did not edit coverage, and this artifact does not assert whether that external lifecycle step has occurred.
- Fresh post-callback Gate 1/Gate 2 review, report execution, coverage application, and archival are supervisor-owned lifecycle state outside this report; none is a pending B005 content task.

## Confidence

- Recommendation confidence: 93/100.
- Score confidence: high for `92/93`; body completeness is exact, with only source spelling/file-name uncertainty remaining.
- Remaining uncertainty: exact original source/member/helper spellings and vector accessor API. These are explicitly descriptive and do not affect serialized bytes, branch behavior, ABI, ownership, or emission eligibility.

## Validator Results

- All commands below ran from `source-3/project-documentation` with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`; each scoped command exited `0` with `ok:1`. The final command added `--wait-generated`.

| Command | Timestamp | Scoped page/result |
| --- | --- | --- |
| `000000011446` | `2026-07-14T11:10:53-04:00` | UID0001AV target; pass. |
| `000000011447` | `2026-07-14T11:11:45-04:00` | UID00019T inverse loader; pass. |
| `000000011448` | `2026-07-14T11:12:28-04:00` | UID00049H Spell caller; pass. |
| `000000011449` | `2026-07-14T11:13:04-04:00` | UID00049L NewMacro caller; pass. |
| `000000011450` | `2026-07-14T11:13:57-04:00` | UID0001DS Friend caller; pass. |
| `000000011451` | `2026-07-14T11:14:44-04:00` | UID00045G Integrate caller; pass. |
| `000000011452` | `2026-07-14T11:15:51-04:00` | `by-file/ProfileStorage.md`; pass. |
| `000000011453` | `2026-07-14T11:16:55-04:00` | `by-meta/client_profile_storage.md`; pass. |
| `000000011454` | `2026-07-14T11:17:59-04:00` | UID0001VR profile layout; pass. |
| `000000011455` | `2026-07-14T11:18:38-04:00` | UID0001V1 MacroHotkeyRecord; pass. |
| `000000011456` | `2026-07-14T11:20:40-04:00` | `by-class/RegistryConfig.md`; pass. |
| `000000011457` | `2026-07-14T11:21:17-04:00` | `by-file/RegistryConfig.md`; pass. |
| `000000011458` | `2026-07-14T11:21:50-04:00` | UID00028Q `g_pConfig`; pass. |
| `000000011459` | `2026-07-14T11:22:42-04:00` | UID0002AA local-player name; pass. |
| `000000011460` | `2026-07-14T11:23:22-04:00` | UID0001DO OptionPane split index; pass. |
| `000000011461` | `2026-07-14T11:24:00-04:00` | `by-class/OptionPane.md`; pass. |
| `000000011462` | `2026-07-14T11:24:37-04:00` | `by-file/OptionPane.md`; pass. |
| `000000011463` | `2026-07-14T11:25:10-04:00` | `by-memory/-ignored.md`; pass. |
| `000000011464` | `2026-07-14T11:26:00-04:00` | UID00040H OptionPane command handler; pass. |
| `000000011465` | `2026-07-14T11:26:38-04:00` | `by-class/SpellMacroDialog.md`; pass. |
| `000000011466` | `2026-07-14T11:27:22-04:00` | UID0001DR MacroDialogs split index; pass. |
| `000000011467` | `2026-07-14T11:28:11-04:00` | `by-file/MacroDialogs.md`; pass. |
| `000000011468` | `2026-07-14T11:28:47-04:00` | `by-class/MacroDialog.md`; pass. |
| `000000011469` | `2026-07-14T11:29:18-04:00` | `by-class/FriendListDialog.md`; pass. |
| `000000011470` | `2026-07-14T11:29:50-04:00` | `by-file/FriendListDialog.md`; pass. |
| `000000011471` | `2026-07-14T11:30:39-04:00` | `by-class/IntegrateMacroDialog.md`; pass. |
| `000000011472` | `2026-07-14T11:31:17-04:00` | UID0001E1 Integrate split index; pass. |
| `000000011473` | `2026-07-14T11:32:05-04:00` | UID0001E2 TargetOption aggregate; pass. |
| `000000011474` | `2026-07-14T11:32:37-04:00` | `by-class/TargetOptionDialog.md`; pass. |
| `000000011475` | `2026-07-14T11:33:16-04:00` | `by-file/TargetOptionDialog.md`; pass. |
| `000000011476` | `2026-07-14T11:33:34-04:00` | Final UID0001AV waited refresh; exit `0`, `ok:1`, generated refresh completed. |
| `000000011503` | `2026-07-14T11:54:06-04:00` | Gate 2 repair, UID0002AA local-player-name buffer; exit `0`, `ok:1`, pass. |
| `000000011504` | `2026-07-14T11:54:39-04:00` | Gate 2 repair, `by-class/RegistryConfig.md`; exit `0`, `ok:1`, pass. |
| `000000011507` | `2026-07-14T11:55:18-04:00` | Gate 2 repair, `by-file/RegistryConfig.md`; exit `0`, `ok:1`, pass. |
| `000000011508` | `2026-07-14T11:55:32-04:00` | Final Gate 2 repair UID0001AV waited refresh; exit `0`, `ok:1`, generated refresh completed. |

- Scoped side effects were validator-owned autogen registry/reference-index/projected-stats updates with generated refresh deferred. Pre-existing missing-reference warnings were reported by `000000011452` (UID0003IV), `000000011454`/`000000011458` (UID0003UJ/UID0003UA), `000000011460` (UID00038F), `000000011463` (313 historical missing references in `-ignored`), and `000000011465` (UID00038H); none failed validation or arose from an accepted new UID.
- Repair scoped commands `000000011503`, `000000011504`, and `000000011507` each updated validator-owned projected stats and deferred generated refresh; they produced no warning or failure. Each repaired page was reread after lease acquisition, validated while leased, and immediately released.
- Final command `000000011508` rebuilt validator autogen metadata, refreshed 281 generated metadata artifacts, and refreshed generated coverage metadata as a validator side effect. B005 did not manually edit any generated or coverage file.
- At B005's immediate post-refresh inspection, all generated files below carried command id `000000011508` and refresh timestamp `2026-07-14T11:55:32-04:00`; the hashes are evidence-time hashes for that completed B005 refresh, not assertions that no later concurrent validator refreshed metadata headers.
- `ProfileStorage.cpp` SHA-256 `93C2A9FAD1CBF4F8288DDE690AB0A0561F8198C1056CB76311C36A7D014C605B`: exactly one UID0001AV `void SaveUserSettings()` definition, zero UID0001AV Empty Emitter Markers, exact eight sections/counts/order, direct cast, path/failure gates, invalid macro-state omission, equality-to-one flags, and no added error/ABI mechanics.
- `MacroDialogs.cpp` SHA-256 `E2662A9A3CA5133B4F699F99AFECB52E864FA73E17C234BB96EACCA12F1EADA0`: one each UID00049H/UID00049L/UID00045G body, three `g_activeMapPane != NULL` gates, zero `g_userSettingsDirty` names, and correct close/remove ordering.
- `FriendListDialog.cpp` SHA-256 `D46E7A1D740292CC7A7BF6C021247A9AE7F167130A2D1D958385BF0342A77D78`: one unconditional `SaveUserSettings()` after optional sync, zero `SaveConfig` names, then close/remove.
- `OptionPane.cpp` SHA-256 `2B928860634983A95B56D0A3E171BDB9B10A1706F40FD0D297C7322027316B0C`: one UID00040H body and one accepted `ApplyLegacyOptionSelections()` abstraction; no raw no-route body was emitted.
- `TargetOptionDialog.cpp` SHA-256 `71F2EC500F52C1FA2CA4D79F53B75021B9E901F7715FE27F1E6A1466E5FF8079`: UID0001E2 remains one expected Empty Emitter Marker with zero partial SaveUserSettings body, matching the accepted mixed-aggregate blank-formal disposition.
- `MapPane.cpp` SHA-256 `425C7671E2AC908204A934F8BF100E8D477BE88F991CE3A919DF71A53FB95015`: one unconditional `SaveUserSettings()` in the existing exit path after `SaveCompressedMapFile()` and presentation disable.
- Later read-only `ProfileStorage.cpp` observation after concurrent validator command `000000011513`, refreshed `2026-07-14T11:59:27-04:00`, SHA-256 `9609C6AC280141888EC93CE09FAC76BBA23BA3A20A270BBF69FB042D7946029B`, again found exactly one target definition and zero target Empty Emitter Markers. The concurrent metadata refresh did not invalidate B005 command `000000011508` or require another ordinary-document edit.
- Read-only support verification after `000000011508` confirmed UID0002AA says the local `wchar_t[40]` is only the `%s/%s.usr` filename stem and section 1 is `m_profileTextSlots[10]`; both RegistryConfig pages retain all eight exact groups, the explicit cast/no-null-guard/ProfileStorage boundary, and the old sequence only as superseded/rejected history.
- Mandatory MCP research evidence remains complete; callback verification required no IDA calls or mutation.

## Changed Files

- Modified ordinary documentation pages (30 in the accepted callback; the focused Gate 2 repair re-edited only three pages already in this list):

```text
by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md
by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md
by-memory/0x0053ecf0-0x0053ed7a.SpellMacroDialogOnConfirm.md
by-memory/0x0053f0a0-0x0053f166.NewMacroDialogOnCommand.md
by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md
by-memory/0x00541fa0-0x005420b1.IntegrateMacroDialogOnButtonClick.md
by-file/ProfileStorage.md
by-meta/client_profile_storage.md
by-type/by-struct/RegistryConfigUserProfileBlock.md
by-type/by-struct/MacroHotkeyRecord.md
by-class/RegistryConfig.md
by-file/RegistryConfig.md
by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md
by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md
by-memory/0x0053d820-0x0053e520.OptionPane.md
by-class/OptionPane.md
by-file/OptionPane.md
by-memory/-ignored.md
by-memory/0x0053ddb0-0x0053e191.OptionPaneOnOptionCommand.md
by-class/SpellMacroDialog.md
by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md
by-file/MacroDialogs.md
by-class/MacroDialog.md
by-class/FriendListDialog.md
by-file/FriendListDialog.md
by-class/IntegrateMacroDialog.md
by-memory/0x00541b30-0x00542265.IntegrateMacroDialog.md
by-memory/0x00542270-0x0054259f.TargetOptionDialog.md
by-class/TargetOptionDialog.md
by-file/TargetOptionDialog.md
```

- Focused Gate 2 repair ordinary paths and scoped proof:
  - `by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md` - validator `000000011503`, pass.
  - `by-class/RegistryConfig.md` - validator `000000011504`, pass.
  - `by-file/RegistryConfig.md` - validator `000000011507`, pass.
- Modified callback artifact: `tools/leaser/Agents/Agent-B005/research/0001AV-SaveUserSettings-empty-emitter-source-quality.md`.
- Verify-only ordinary dependencies remained unchanged: UID0002AS, UID0002A6, UID0002UA, UID0002QH, UID0001AT, g_activeMapPane, Wide API pages, MapPane pages, NewMacro class, and existing target-adjacent ignored padding.
- Validator-owned side effects: projected stats, reference/autogen registry state, generated metadata/coverage metadata, and generated C++ refresh, most recently under waited command `000000011508`. These are not manual B005 edits.
- Renamed/moved/deleted: none. All ordinary page leases were released immediately after validation; no B005 lease remains.
- Report execution: not run or probed. B005 did not run lifecycle, move, archive, deletion, registry, or execution commands.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact report-only SHA and authorized implementation.
- [x] Updated UID0001AV and every accepted support page; verified listed no-change dependencies.
- [x] Preserved complete research, all eight groups, caller routes, negative evidence, and old-report classifications.
- [x] Updated C01-C35 to legal callback verification states with destination/validator/generated proof.
- [x] Changed only UID0001AV `86/90 -> 92/93`; kept all support scores/routes unchanged.
- [x] Preserved owner/emitter UID0000MS, reconstructable true, blank position, `Nested:-4`; created no target child.
- [x] Added only support padding `[0x0053dda6,0x0053ddb0)`; created no raw OptionPane emitter/UID.
- [x] Confirmed ProfileStorage placement, exact target/adjacent ranges, no split, and no IDA mutation.
- [x] Applied Destinations 1-6 exactly; kept every other formal block unchanged.
- [x] Confirmed third-party import is not applicable; no import directive or external source was used.
- [x] Incorporated target/support facts at report-level detail without compressing evidence tables.
- [x] Preserved Wave2/wrong-address/dirty/SaveConfig/wrapper/payload/parent-gate/consumer assumptions as rejected or superseded history.
- [x] Used no Wave2/Wave3 artifact as current authority.
- [x] Kept all substantive questions closed; retained only lexical uncertainty with explicit score impact.
- [x] Leased/reread/edited/scoped-validated/released each ordinary page serially.
- [x] Ran final `--wait-generated` refresh and inspected generated ProfileStorage/caller files read-only.
- [x] Preserved exact supervisor-owned coverage text and did not edit coverage/tracker files.

Implementation callback pass:
- [x] Exact report-only artifact was accepted by supervisor for implementation.
- [x] All accepted target/support details are incorporated at report-level detail.
- [x] C01-C35 ledger has legal final states and claim-specific proof.
- [x] Metadata/score/formal/support changes are applied or verified unchanged with reason.
- [x] Historical assumptions, rejected alternatives, and negative evidence are preserved.
- [x] Open questions remain closed with archive-neutral current wording.
- [x] One scoped validator per changed ordinary page is recorded with command ID/timestamp/exit/ok/side effects; all leases are released.
- [x] Final waited generated refresh and exact ProfileStorage/caller assertions are recorded; manual coverage text remains preserved for supervisor-owned use.
- [x] No accepted item is blocked or unapplied; no execute_report/lifecycle/move/archive action was run by B005.

Focused Gate 2 repair pass:
- [x] Corrected UID0002AA so the exact `errno_t GetLocalPlayerName(wchar_t *, size_t)` direct-copy contract, local `wchar_t[40]`, capacity `0x28`, and ignored return are preserved while the result is identified only as the `%s/%s.usr` filename stem, not serialization section 1.
- [x] Corrected `by-class/RegistryConfig.md` and `by-file/RegistryConfig.md` to the exact ordered eight-section writer inventory with every required width, count, branch, nonserialized byte, invalid-state consequence, and equality-to-one boolean rule.
- [x] Preserved base-typed `Config *g_pConfig`, runtime `RegistryConfig`, explicit derived cast, no null guard, ProfileStorage ownership, destructive replacement, ignored write/close results, partial/truncated output, malformed invalid-state output, and no rollback.
- [x] Retained the inaccurate compact-target/macro/spell/inventory/friend/options sequence only as explicitly superseded/rejected historical wording and corrected all three July 14 change-log entries.
- [x] Leased, reread, scoped-validated, and immediately released only the three repaired ordinary pages; commands `000000011503`, `000000011504`, and `000000011507` each exited `0` with `ok:1`.
- [x] Ran final waited target refresh `000000011508`; generated `ProfileStorage.cpp` has exactly one UID0001AV definition and zero target Empty Emitter Markers, and the repaired support prose remains present.
- [x] Updated C08/C31 proof, support recommendations, validator results, changed files, current state, and checklist without altering any other accepted implementation content.
- [x] No coverage/generated/tracker/audit/lifecycle/supervisor/validator-state file was manually edited; no IDA mutation, execute_report probe/action, report move, or archive occurred; no B005 lease remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000011521","destination_path":"executed-b-agent-research/B005/0001AV-SaveUserSettings-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0001AV-SaveUserSettings-empty-emitter-source-quality.md","timestamp":"2026-07-14T12:15:48-04:00","uid":"0001AV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
