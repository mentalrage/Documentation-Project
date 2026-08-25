# UID0000MS ProfileStorage Whole-File Source-Quality Report
** TARGET-REPORT-UID:0000MS **
** TARGET-REPORT-ADDITIONAL-UIDS:00019T,0001AV **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

- Keep [UID:0000MS] `ProfileStorage` as the narrow file owner for exactly three source functions: file-local `ImportLegacyUserProfileData`, public `LoadUserProfileData`, and public `SaveUserSettings`.
- Keep [UID:00019T] as the aggregate child for importer plus loader and [UID:0001AV] as the writer child. Preserve both owner/emitter routes to [UID:0000MS]. No new by-memory split is required.
- The accepted ordinary callback now emits one global C++03-era `ProfileStorage.cpp` and one complete guarded `ProfileStorage.h`. [UID:0001AV]'s own H channel remains blank because [UID:00019T] supplies the shared header once.
- Preserve binary behavior, including malformed-input behavior: the selected-profile read is not bounded, fixed-slot oversize returns without closing the file, optional row counts are not clamped, an oversized macro row does not consume its payload, unknown macro state handling remains asymmetric, and write failures are ignored.
- Use direct `Config` fields for storage. Only the nonvirtual `InitializeUserDataDefaults` call needs a `RegistryConfig` cast. Replace stale `m_profileStringSlots` with current source-facing `m_friendNames`.
- Exclude `MapPane::RefreshSelectedProfileData`, its sidecar table, and its filename literals from this source file. They remain MapPane-owned dependencies and must not be duplicated into ProfileStorage.
- Recommend `94/94` for [UID:0000MS], `94/94` for [UID:00019T], and `94/95` for [UID:0001AV]. The remaining gap is lexical/source-tree uncertainty, not unresolved behavior or missing draft source.
- Gate 2B receives exactly seven concise supervisor-owned endpoint recommendations: importer rename/type/comment, loader rename/type/comment, and writer comment. B005 performed no IDA action. Runtime selection, backup, session, save, persistence, rollback, reopen, promotion, and physical-receipt mechanics remain dynamically supervisor-owned and are intentionally absent from this report.
- Fresh supervisor-owned readback at `2026-08-25T20:25:11Z` establishes the current importer prestate as `sub_4F9280 / int()` with complete F-I unchanged, all four comment channels blank, exact bytes, one inbound call, and `ImportLegacyUserProfileData` absent. A01 must rename while preserving `int()`; A02 must then change that exact `int()` state directly to the evidence-backed final `void __cdecl ImportLegacyUserProfileData(void)` signature. No intermediate `FILE *()` state is required or authorized.
- Dated read-only evidence separately established one importer analysis-materialization behavior: an initial item type `int()` became `FILE *()` after decompilation first declared `FILE *sub_4F9280()`, with the complete frame unchanged. This remains historical analysis behavior only, not current authority, a prescribed transaction stage, or a mutation recommendation.
- Each A03/A06/A07 comment action must return exactly one `result` row containing mandatory request-preserving `addr` and optional `error` only. `addr` must parse as unsigned hexadecimal and equal the action target; optional `error` must be absent or the exact empty string. `function_addr`, every other extra field, null/non-string/nonempty `error`, missing/extra rows, parse failure, or address mismatch fails closed.

## Supporting Research

- Current primary and child pages: `by-file/ProfileStorage.md`, `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md`, and `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md`.
- Current support pages include [UID:000031] `Config`, [UID:0000BW] `RegistryConfig`, [UID:0001QL] `client_profile_storage`, [UID:0001VR] `RegistryConfigUserProfileBlock`, [UID:0001V1] `MacroHotkeyRecord`, [UID:0000ML] `PlatformApi`, `StringBase`, and `SimpleUStringVector`.
- Matching historical reports were searched by UID, addresses, `ProfileStorage`, `LoadUserProfileData`, `SaveUserSettings`, `.usr`, `.cfg`, and selected-profile terms. Relevant leads were B013's UID00019T report, B005's UID0001AV report, B003's UID0001AS report, and B005's UID0001DU report. Their valid binary facts were rechecked; stale namespace, derived-field-cast, field-name, and MCP-unavailable conclusions were not retained as current authority.
- The pre-callback generated baseline was `ProfileStorage.cpp` command `000000028021`, refreshed `2026-08-25T02:38:39-04:00`, SHA256 `0BA83DFAA07C6F10979F11EA1577DA254D785E97C00158B6EB84C2E7037BCB1F`, 12,343 bytes, 375 LF, zero CR, with no sibling header. This is historical defect evidence, not current generated authority.
- The first accepted ordinary callback physical output was `ProfileStorage.cpp` command `000000028053`, refreshed `2026-08-25T04:20:02-04:00`, SHA256 `01F32C56AB67EC0636C8DC0AC8123CF908DB00B300B154F346ED4B5D89D2E492`, 12,709 bytes, 397 LF, zero CR; and `ProfileStorage.h` command `000000028053`, SHA256 `CD0E585E80AB82677FCA05A17072C2B1209908010810A24A65777F79386B2381`, 565 bytes, 14 LF, zero CR. Those receipts remain labeled historical callback evidence.
- Dated callback receipt only: command `000000028127` refreshed `ProfileStorage.cpp` and `ProfileStorage.h` at `2026-08-25T08:16:29-04:00` with SHA256 `4F83D13DBAE05567A3473E52136BFAF95446448D0D41FC0E61000964E5F1722E` and `7E89ABDA7487830A337721EBE815AD2DBAD69BCA0974CC42205CAC489D1D651F`. These hashes preserve the C0000MS-104 through C0000MS-106 callback history but have no current generated-authority status after later refreshes.
- The bounded CKF-031 Gate 2A repair passed scoped validator command `000000028153` at `2026-08-25T09:33:17-04:00` with exit 0 and `ok:1`; generated refresh was deferred because the proposed-tree page is non-emitting. Its then-current command-`000000028127` reread is now historical only. The dated physical command-`000000028163` snapshot in Sections 31-33 is the latest observed generated state, remains mutable rather than permanent authority, and must be physically replaced by a new snapshot if any relevant artifact identifies a newer command during future Gate 2A.
- Current manual rows are `89%` for [UID:0000MS], `88%` for [UID:00019T], and `92%` for [UID:0001AV]. They are read-only evidence; Section 28 supplies exact supervisor-owned replacements.
- Dated 2026-08-25 research observation: live IDA evidence was collected from then-canonical session `supervisor_uid0003l5_final_20260825_0540`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`. Health, Hex-Rays, and string services were available. One broad combined query timed out; bounded retries succeeded while the listener remained healthy. This preserves valid bounded research evidence, but that session is historical and is not current canonical/runtime authority after later canonical transactions.
- At that dated observation, the final read-only availability recheck returned `status:ok`, uptime `4516.444` seconds, `hexrays_ready:true`, `strings_cache_ready:true`, and the same then-current paths/image base. `auto_analysis_ready:false` did not block bounded live queries, and a three-address lookup returned `sub_4F9280` size `0x322`, `sub_4F95B0` size `0x778`, and `SaveUserSettings` size `0x4d8`. No dated session or path claim is current authority; the supervisor must establish current runtime and physical authority dynamically under the controlling workflow before acting.
- Historical failed Gate 2B namespace `uid0000ms_20260825T103249Z_80381fae` stopped during an initial importer read before any rename/type/comment action or save. Its canonical and disposable files remained byte-equal at 143,211,870 bytes with SHA256 `A7E3E828ECF5AB37A9D2134692BB658266CCC34601F1EF550C4C1B9EABD01144`; the save destination remained absent and the worker was stopped/inactive. This dated incident is zero-mutation evidence only, has no current operational authority, and supplies no completion credit.
- Fresh Gate 2B current-state readback at `2026-08-25T20:25:11Z` used supervisor-selected canonical session `supervisor_uid0003a1_canonical_20260825_1704`, exact IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, healthy public runtime attestation, and found `0x004f9280` as `sub_4F9280 / int()`. The supervisor stopped before dry run or mutation because the prior A01 `FILE *()` precondition did not match. This is current-prestate evidence for the repaired handoff, not completion credit or permission for B005 to operate IDA.

## Target

- Primary target: [UID:0000MS] `by-file/ProfileStorage.md`.
- Additional target: [UID:00019T] `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md`.
- Additional target: [UID:0001AV] `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md`.
- Whole-file scope contains three modeled source functions, 3,954 code bytes, one internal 14-byte padding interval, and two post-function 8-byte padding intervals.
- The direct file-owned source range is noncontiguous: importer/loader at `[0x004f9280,0x004f9d28)` and writer at `[0x0050aba0,0x0050b078)`. That is a valid source-file aggregation rather than permission to absorb intervening MapPane/login code.

## Current Target State

- [UID:0000MS] is now `94/94`, `CANONICAL_OWNER:FILE`, reconstructable, and routed under `NexusTK/profile/`.
- [UID:00019T] is now `94/94`, owned/emitted by [UID:0000MS], reconstructable, with complete CPP and shared H.
- [UID:0001AV] is now `94/95`, owned/emitted by [UID:0000MS], reconstructable, with complete CPP and an intentionally blank H covered by [UID:00019T].
- The three target pages are now internally reconciled. [UID:0000MS] active score rationale is `94/94`; [UID:00019T] active owner-boundary prose limits ProfileStorage to importer/loader/writer and its active score rationale is `94/94`; [UID:0001AV] active status/assignment/score prose is `94/95` and its active owner-boundary prose keeps selected-profile sidecar helpers in MapPane/ProfileDialog cross-module support. All cited dated score/ownership entries remain labeled history.
- The current proposed source tree now records importer interval `0x004f9280-0x004f95a2`, the non-emitting 14-byte `[0x004f95a2,0x004f95b0)` compiler-padding interval, and the exact legacy behavior: successful import closes and deletes the quoted UTF-16 `.cfg` and does not directly write the modern `.usr` file.
- Dated physical command-`000000028163` snapshot: generated `ProfileStorage.cpp` contains the complete accepted flat C++03-era importer, loader, and writer source. It uses direct Config fields, contains no `ProfileStorage` namespace, `m_profileStringSlots`, `constexpr`, `nullptr`, stale writer suffix, or selected-sidecar function, and preserves the accepted malformed-input behavior.
- In that same command-`000000028163` snapshot, generated `ProfileStorage.h` declares `LoadUserProfileData` and `SaveUserSettings` exactly once; MainMenuPane, MapPane, FriendListDialog, MacroDialogs, and TargetOptionDialog each include that header exactly once; the old TargetOptionDialog ad hoc declaration is absent.
- In that same command-`000000028163` snapshot, generated PlatformApi/StringBase/StringUtil support headers expose the four required profile I/O dispatch pointers, both required StringBase wide-buffer methods, and the three-pointer SimpleUStringVector facade. These generated facts are mutable: future Gate 2A must reread all ten relevant artifacts and supersede this snapshot if any identifies a command newer than `000000028163`.

## Executive Recommendation

- The accepted ordinary callback implemented the corrected [UID:00019T] CPP/H and [UID:0001AV] CPP through their formal channels.
- The five caller translation units now include `ProfileStorage.h` once each, and TargetOptionDialog's ad hoc declaration is removed.
- PlatformApi, StringBase, and SimpleUStringVector owner documentation now supplies the required formal declarations while preserving the 12-byte vector layout.
- The proposed source-tree inventory now names exactly the three ProfileStorage-owned functions and explicitly excludes the MapPane/ProfileDialog sidecar family.
- C0000MS-104 through C0000MS-106 are implemented and validated. After fresh Gate 1 and Gate 2A verify the exact report and all 49 checked B005 rows, Section 21 supplies seven item-by-item IDA recommendations with literal requests, prestates, response contracts, safety constraints, and immediate readbacks. The supervisor independently controls all runtime, backup, persistence, and recovery mechanics. Do not mutate the broad Config UDT in this narrow handoff.
- Use the fresh `sub_4F9280 / int()` prestate for the importer chain: A01 preserves `int()` during the pure rename and A02 directly replaces `int()` with the evidence-backed final `void __cdecl` type. Treat the dated `int()` to `FILE *()` decompile-induced materialization only as historical analysis behavior, not an action precondition, required intermediate state, or permission for an unlisted delta.

## Supervisor Active Recheck

- Reconfirm the exact post-callback report hash and all 33 headings during fresh Gate 1 and Gate 2A.
- Verify the ledger and checklist each contain exactly 63 exact ordered twins: all 49 B005 rows checked and all 14 supervisor rows unchecked, with exactly one terminal readiness marker.
- Re-read the current generated CPP/H/caller receipts below and the three manual coverage rows; generated and manual files remain separate authorities.
- Treat the seven structured IDA rows as recommendations only. Gate 1 must verify each literal prestate/action/response/readback contract, including the importer sequence `sub_4F9280 / int()` -> renamed function still typed `int()` -> final `void __cdecl`, globally collision-free rename targets, and the one-row comment response containing `addr` plus optional `error` only. B005 made no IDA mutation, save, process-management, coverage, lifecycle, or report-execution action.
- Preserve the dated failed-attempt facts only as historical zero-mutation evidence. Runtime/session/file/save/recovery policy is supplied dynamically by the supervisor and is not encoded as report actions.
- Preserve the physically verified one-shared-header-include-per-caller result during Gate 2A and later lifecycle work.

## Inference Research Guidance Check

- Binary facts, documentation facts, and source-shape inference are separated.
- Missing original lexical symbols did not justify retaining `sub_`, raw offsets, or decompiler temporaries in proposed source. Names were selected from behavior, caller role, existing subsystem naming, and current project conventions.
- Exact runtime behavior has priority over stylistic cleanup. Human-looking C++03-era source shape has priority over cosmetic consistency. Project-wide naming consistency is applied only after those two requirements.
- Stale Wave2/Wave3 material was ignored.

## Heuristic / Inference Reanalysis And Validation

- `ProfileStorage.cpp` is the strongest file inference because load, legacy import, and save share the same profile schema, path root, player-name helper, Config slice, and inverse serialization contract. No UI receiver owns all callers.
- A namespace is not supported by symbols, callers, or neighboring project source shape. A flat source file with one anonymous/file-local helper region is more plausible for the era and current codebase.
- `ImportLegacyUserProfileData` is file-local: it has one inbound call from the loader and no external caller. `LoadUserProfileData` and `SaveUserSettings` are public globals because independent translation units call them.
- `m_friendNames` is preferred over stale `m_profileStringSlots`: the current Config declaration and cross-feature friend-list use establish the semantic role. Original spelling is inferred, but the role is no longer unresolved.
- The migration state expression must be `(isSpellMode != 1) + 2`, not a truthy ternary. This preserves the binary distinction where only byte value exactly one means Spell.
- The loader's selected-name read must remain unchecked. Adding a 256-character guard would be safer but would not be behaviorally faithful.
- The high-blast-radius Config UDT gap is not a reason to leave source raw. Source documentation can use the current typed Config fields while the supervisor preserves the coarse IDA member until a dedicated overlapping-layout assignment is available.

## Evidence Standards Used

- Function identity: modeled start/end, byte count, SHA256, bounded disassembly/decompilation, and xrefs.
- Source ownership: caller spread, data dependencies, shared serialization schema, file-local reachability, source-tree context, and negative candidate analysis.
- Source names/types: current docs, current generated declarations, exact binary role, caller ABI, field offsets, and era-appropriate coding patterns.
- Failure semantics: branch-level decompilation and inverse writer/loader comparison; no defensive checks were invented.
- Registry-name state: independent globally anchored exact-regex `entity_query(kind:"names")` calls are authoritative. Address/default-name `lookup_funcs` is display/range evidence only and cannot prove registration or global collision absence.
- Generated state: physical CPP/H path and embedded validator command metadata, treated as dated evidence.

## Evidence Checked

- Read all three target pages and their current CPP/H blocks, then reread the exact active/historical score and ownership regions before and after callback. Historical callback prestates were [UID:0000MS] SHA256 `394DEBC94B2CD7AE420804948E29823A62BF5F187A2FA013E71098D551E755A0`, [UID:00019T] `FC7FED9C39BEDB4EE44978E73E3933B3D9113EF064EA9709650DF53539612397`, and [UID:0001AV] `CFA15F45E19EF601F450BEE1AA09A4BC343965A84DBAA9FE57ED516F383FA75A`. Post-validation receipts are respectively `2904793AC11AA9F450219C1095D468BCF83289FC31E2D7FB798B54E481A5DC3B`, `C8CEDB21C310482FB1D4806A30BCE4329643435B3E6E1632A0E59C2594ADB194`, and `4039E395D512653C97AD1D6EED4E2B79BF98B4894EBA8608AC0C75261C5894CB`; all active prose is current and cited historical lines remain intact.
- Read Config/RegistryConfig/profile-schema/type/PlatformApi/string/vector support documentation and relevant generated headers/sources.
- Read current generated ProfileStorage output and every generated caller found by `LoadUserProfileData`/`SaveUserSettings` search.
- Read `by-project-structure/proposed-source-tree.md` ProfileStorage section and the relevant file/memory/class/type manual coverage rows read-only.
- Searched executed reports with `0000MS`, `00019T`, `0001AV`, `004f9280`, `004f95b0`, `0050aba0`, `ProfileStorage`, `.usr`, `.cfg`, and `RefreshSelectedProfileData`.
- Queried live IDA for function records, exact bytes/hashes, bounded xrefs, decompilation, stack frames, comments, adjacent padding, globally anchored exact registered names, and current Config UDT/type visibility; address lookup was kept separate from name-registry authority.
- Incorporated the fresh supervisor-owned `2026-08-25T20:25:11Z` canonical readback: `0x004f9280` currently displays `sub_4F9280`, has item/prototype type `int()`, complete F-I unchanged, all four comments blank, exact first 32 bytes, one inbound call from `0x004f974a`, and no `ImportLegacyUserProfileData` registration. No mutation was attempted after the old report contract failed closed.
- Compared current generated output against binary behavior and current support declarations line by line for the six material defects listed in Current Target State.

## Claim And Incorporation Ledger

The accepted callbacks completed all 49 `B005` rows, including C0000MS-104 through C0000MS-106 and the bounded CKF-031 Gate 2A repair. The 14 surviving `SUPERVISOR` coverage, concise IDA-action, Gate, and lifecycle rows remain unchecked and supervisor-owned. CKF-049 preserves the historical callback shapes while identifying the current authoritative 63-row/49-checked allocation and one terminal marker recorded below.

| ID | Allocation | Claim / required edit | Destination | Verification |
| --- | --- | --- | --- | --- |
| CKF-001 | B005 | Replace the file summary with the exact three-function whole-file inventory and noncontiguous range explanation. | `by-file/ProfileStorage.md` | Applied: `ProfileStorage.md` lists exactly importer, loader, and writer across the two noncontiguous owned ranges. |
| CKF-002 | B005 | Document flat global source placement with a file-local importer; reject the unsupported `ProfileStorage` namespace. | `by-file/ProfileStorage.md` | Applied: source placement is flat global C++03; the importer is file-local and no `ProfileStorage` namespace remains. |
| CKF-003 | B005 | Record the exact importer, loader, and writer byte counts and SHA256 values. | `by-file/ProfileStorage.md` | Applied: the page records 802/1,912/1,240-byte functions and exact SHA256 values `AF24E728...`, `C99D8F24...`, and `0108F818...`. |
| CKF-004 | B005 | Record all internal/pre/post padding boundaries without absorbing adjacent functions. | `by-file/ProfileStorage.md` | Applied: pre/importer-loader/internal/writer/post padding fences are recorded exactly without absorbing adjacent functions. |
| CKF-005 | B005 | Record the complete caller/xref inventory and public/file-local linkage. | `by-file/ProfileStorage.md` | Applied: importer and loader each have one inbound caller and writer has all eight exact inbound xrefs with linkage dispositions. |
| CKF-006 | B005 | Record modern `.usr` section order, widths, optional-tail behavior, and inverse load/save contract. | `by-file/ProfileStorage.md` | Applied: the `.usr` table records all eight sections, widths, fixed/persisted counts, optional tails, and inverse load/save order. |
| CKF-007 | B005 | Record legacy `.cfg` quoted UTF-16 import, truncation, close, and delete behavior. | `by-file/ProfileStorage.md` | Applied: legacy `.cfg` quoted UTF-16 reads, selected-name truncation, close, delete, and open-failure no-op are documented. |
| CKF-008 | B005 | Preserve exact malformed-input and ignored-I/O-result behavior rather than adding safety checks. | `by-file/ProfileStorage.md` | Applied: fixed-slot leak return, unchecked selected length, unclamped counts, oversized-macro desync, and ignored I/O results are preserved. |
| CKF-009 | B005 | Document direct Config field storage and the narrow RegistryConfig cast for default initialization only. | `by-file/ProfileStorage.md` | Applied: storage uses direct `Config` fields; only `InitializeUserDataDefaults` uses the narrow `RegistryConfig` cast. |
| CKF-010 | B005 | Replace stale `m_profileStringSlots` with `m_friendNames` throughout current source-facing recommendations. | `by-file/ProfileStorage.md` | Applied: current target/formal source uses `m_friendNames`; stale `m_profileStringSlots` is retained only as historical defect text. |
| CKF-011 | B005 | Record PlatformApi, StringBase, and SimpleUStringVector declaration dependencies. | `by-file/ProfileStorage.md` | Applied: PlatformApi dispatches, StringBase wide-buffer methods, and the SimpleUStringVector facade have explicit owner/header dispositions. |
| CKF-012 | B005 | Record MapPane selected-profile sidecar/table/literal exclusion and dependency-only relationship. | `by-file/ProfileStorage.md` | Applied: UID0001AS, UID00027P, UID0003IV, and UID0001DU are explicitly excluded with their MapPane/ProfileDialog routes. |
| CKF-013 | B005 | Raise primary metadata to `94/94` without changing file ownership or reconstructability. | `by-file/ProfileStorage.md` | Applied: primary metadata is `94/94`, `CANONICAL_OWNER:FILE`, reconstructable, with the same source path. |
| CKF-014 | B005 | Replace [UID:00019T] CPP with corrected C++03-era importer/loader source from Section 22. | `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` | Applied: UID00019T formal CPP exactly carries the accepted C++03 importer/loader source and file-local helpers. |
| CKF-015 | B005 | Populate [UID:00019T] H with the complete guarded `ProfileStorage.h` from Section 22. | `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` | Applied: UID00019T formal H contains the complete `NEXUSTK_PROFILE_PROFILESTORAGE_H` guard and both public declarations. |
| CKF-016 | B005 | Correct selected-profile unchecked read, fixed-slot leak path, unbounded optional counts, oversized macro desync, and exact migration state expression. | `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` | Applied: UID00019T prose and CPP preserve unchecked selected-name read, leak return, unbounded tails, macro desync, and `(isSpellMode != 1) + 2`. |
| CKF-017 | B005 | Record exact function split, hashes, xrefs, comments, and name-registry baseline. | `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` | Applied: UID00019T records exact split, hashes, one importer/loader xref each, blank comments, and autogenerated-name registry baseline. |
| CKF-018 | B005 | Raise [UID:00019T] metadata to `94/94`; retain owner/emitter [UID:0000MS]. | `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` | Applied: UID00019T is `94/94`, reconstructable, with owner/emitter UID0000MS unchanged. |
| CKF-019 | B005 | Replace [UID:0001AV] CPP with corrected direct-Config C++03-era writer source from Section 22. | `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md` | Applied: UID0001AV formal CPP exactly carries the accepted direct-Config C++03 writer source. |
| CKF-020 | B005 | Keep [UID:0001AV] H blank with explicit covered-by proof pointing to [UID:00019T]'s shared header. | `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md` | Applied: UID0001AV formal H is blank and prose identifies UID00019T as the sole shared-header provider. |
| CKF-021 | B005 | Correct writer friend-name field, exact compact mode byte handling, malformed macro-state output, and ignored I/O results. | `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md` | Applied: writer uses `m_friendNames`, exact compact-mode bytes, asymmetric unknown macro state, and original ignored I/O results. |
| CKF-022 | B005 | Raise [UID:0001AV] metadata to `94/95`; retain owner/emitter [UID:0000MS]. | `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md` | Applied: UID0001AV is `94/95`, reconstructable, with owner/emitter UID0000MS unchanged. |
| CKF-023 | B005 | Synchronize the eight-section binary layout and malformed-input semantics. | `by-meta/client_profile_storage.md` | Applied: `client_profile_storage.md` now carries the exact eight-section layout, legacy migration, and malformed-input contract. |
| CKF-024 | B005 | Synchronize current Config field names, offsets, counts, and direct-storage rule. | `by-type/by-struct/RegistryConfigUserProfileBlock.md` | Applied: the profile-block page records current field names, offsets, counts, direct Config storage, and the narrow default-call cast. |
| CKF-025 | B005 | Preserve `CompactShortcutRecord` as 4 bytes and document exact byte-one spell-mode semantics. | `by-type/by-struct/RegistryConfigUserProfileBlock.md`; existing declaration owner `by-file/Config.md` | Applied: the existing Config declaration and profile-block owner document exact four-byte layout and `(isSpellMode != 1) + 2`; no duplicate aggregate was created. |
| CKF-026 | B005 | Preserve `MacroHotkeyRecord` as 264 bytes and document states 1/2/3 plus unknown-state behavior. | `by-type/by-struct/MacroHotkeyRecord.md` | Applied: `MacroHotkeyRecord` remains 264 bytes and documents states 1/2/3 plus unknown-state read/write asymmetry. |
| CKF-027 | B005 | Document direct Config profile fields and narrow runtime-derived cast for `InitializeUserDataDefaults` only. | `by-class/Config.md` and `by-class/RegistryConfig.md` | Applied: Config and RegistryConfig pages both state direct base storage and the one narrow `InitializeUserDataDefaults` derived call. |
| CKF-028 | B005 | Add extern declarations for read-UTF16, CreateDirectoryW, DeleteFileW, and SetFileAttributesW dispatch pointers. | `by-file/PlatformApi.md` owner H channel | Applied: generated `PlatformApi.h` command `000000028060` exposes all four required dispatch-pointer declarations. |
| CKF-029 | B005 | Add declarations for already-emitted `SetLengthWideAndDetach` and `LockWideBuffer`. | `StringBase` owner H documentation | Applied: generated `StringBase.h` command `000000028061` declares `SetLengthWideAndDetach` and `LockWideBuffer` once. |
| CKF-030 | B005 | Close the minimal 12-byte SimpleUStringVector source facade used by Clear/count/index/PushBack callers. | `SimpleUStringVector` owner docs | Applied: generated `StringUtil.h` command `000000028062` exposes Clear/Size/index/PushBack while retaining three pointers and 12-byte layout; no build was run. |
| CKF-031 | B005 | Correct the ProfileStorage proposed-tree inventory with exactly three owned functions, the exact importer interval and padding, no direct modern write, and explicit MapPane exclusion. | `by-project-structure/proposed-source-tree.md` | Applied and Gate 2A-repaired: importer is exactly `0x004f9280-0x004f95a2`; `[0x004f95a2,0x004f95b0)` is explicitly 14 bytes of non-emitting compiler padding; successful quoted UTF-16 `.cfg` import closes/deletes the legacy file and does not directly write `.usr`; all four sidecar/forwarder candidates remain excluded. Scoped validator `000000028153` returned exit 0 and `ok:1`; post-validation SHA256 is `D1CEA8AC4EA51F00E756E2ACF8CCACCA2FAFA1D4F5B5816A2C55F8ADAE0B6B33` (335,375 bytes, 2,187 LF, zero CR), with one corrected importer line, one padding line, and zero stale range/rewrite text. |
| CKF-032 | B005 | Add one `ProfileStorage.h` include for the loader caller. | [UID:00019K] MainMenu generated-owner by-* channel | Applied: generated `MainMenuPane.cpp` contains one `../profile/ProfileStorage.h` include and the loader call. |
| CKF-033 | B005 | Add one `ProfileStorage.h` include for the MapPane writer caller. | [UID:0002QH] MapPane generated-owner by-* channel | Applied: generated `MapPane.cpp` contains one `../profile/ProfileStorage.h` include and the writer call. |
| CKF-034 | B005 | Add one `ProfileStorage.h` include for the friend-list writer caller. | [UID:0001DS] FriendListDialog generated-owner by-* channel | Applied: generated `FriendListDialog.cpp` contains one `../profile/ProfileStorage.h` include and the writer call. |
| CKF-035 | B005 | Add one shared `ProfileStorage.h` include covering all three MacroDialogs writer callers. | [UID:00045G] MacroDialogs translation-unit head/first emitter | Applied: generated `MacroDialogs.cpp` contains one shared `../../profile/ProfileStorage.h` include covering all three writer calls. |
| CKF-036 | B005 | Add one shared header include and remove the ad hoc `void SaveUserSettings();` declaration. | [UID:0004QU] TargetOptionDialog generated-owner by-* channel | Applied: generated `TargetOptionDialog.cpp` contains one shared header include and zero ad hoc `void SaveUserSettings();` declarations. |
| CKF-037 | B005 | Preserve UID0001AS MapPane ownership and non-ProfileStorage emitter route. | `by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md` | Applied: UID0001AS remains owner/emitter UID00007Q and explicitly excludes the MapPane member from ProfileStorage. |
| CKF-038 | B005 | Preserve UID00027P MapPane sidecar table ownership and non-ProfileStorage route. | UID00027P support page | Applied: UID00027P remains owner/emitter UID0000L3 at position 1 and emits the table once through MapPane. |
| CKF-039 | B005 | Preserve UID0003IV MapPane sidecar literals ownership and non-ProfileStorage route. | UID0003IV support page | Applied: UID0003IV remains owner UID0000L3, nonreconstructable, non-emitting covered-by MapPane literal evidence. |
| CKF-040 | B005 | Preserve UID0001DU ProfileDialog forwarder ownership and non-ProfileStorage route. | UID0001DU support page | Applied: UID0001DU remains owner/emitter UID0000MR at position 40 as the ProfileDialog-local forwarder. |
| CKF-041 | SUPERVISOR | Replace the [UID:0000MS] manual file coverage row with the exact Section 28 payload if current text still differs. | `by-file/-coverage-report.md` | Exact row occurs once. |
| CKF-042 | SUPERVISOR | Replace the [UID:00019T] manual memory coverage row with the exact Section 28 payload if current text still differs. | `by-memory/-coverage-report.md` | Exact row occurs once. |
| CKF-043 | SUPERVISOR | Replace the [UID:0001AV] manual memory coverage row with the exact Section 28 payload if current text still differs. | `by-memory/-coverage-report.md` | Exact row occurs once. |
| CKF-044 | B005 | Run scoped validation for every changed ordinary by-* page only after callback authorization. | Each changed by-* page | Applied: all 22 changed ordinary pages passed scoped validation with command IDs `000000028050`, `000000028052` through `000000028072`, exit 0 and `ok:1`. |
| CKF-045 | B005 | Physically verify generated `ProfileStorage.cpp` against all three functions and behavior after callback validation. | `auto-generated/NexusTK/profile/ProfileStorage.cpp` read-only | Applied: generated `ProfileStorage.cpp` command `000000028053`, SHA256 `01F32C56AB67EC0636C8DC0AC8123CF908DB00B300B154F346ED4B5D89D2E492`, physically contains the accepted importer, loader, and writer once each. |
| CKF-046 | B005 | Physically verify generated `ProfileStorage.h` exists and exactly declares both public globals after callback validation. | `auto-generated/NexusTK/profile/ProfileStorage.h` read-only | Applied: generated `ProfileStorage.h` command `000000028053`, SHA256 `CD0E585E80AB82677FCA05A17072C2B1209908010810A24A65777F79386B2381`, has one complete guard and exactly both public declarations. |
| CKF-047 | B005 | Physically verify all caller translation units include the shared header and contain no ad hoc declaration. | Generated callers read-only | Applied: MainMenuPane, MapPane, FriendListDialog, MacroDialogs, and TargetOptionDialog each contain one `ProfileStorage.h` include; the ad hoc declaration count is zero. |
| CKF-048 | B005 | Record dated validator receipts and physically snapshot mutable generated authority, requiring a fresh reread when a newer command appears. | Sections 31-33 | Applied and refreshed: historical callback/repair commands remain dated receipts only. A physical `2026-08-25T10:16:06-04:00` snapshot verifies all ten relevant generated artifacts identify command `000000028163`, records their current hashes/shape and target-specific semantics, and requires future Gate 2A to reread and replace this snapshot if any relevant artifact identifies a newer command. |
| CKF-049 | B005 | Reconcile all ledger/checklist rows after callback without checking supervisor-owned IDA/coverage/lifecycle work. | This report | Historical accepted-callback state: both tables held 103 exact twins with 46 checked B005 rows and 57 unchecked supervisor rows. A later rejected operational-handoff artifact held 106 twins with 49 checked B005 rows and 57 unchecked supervisor rows. Current reconciled state: 63 exact ordered twins; all 49 B005 rows, including C0000MS-104 through C0000MS-106 and CKF-031, are checked; all 14 surviving supervisor rows remain unchecked; Section 21 contains exactly seven concise action rows with row-local protections/readbacks and no B-authored transaction program; exactly one terminal `READY_FOR_SUPERVISOR_EXECUTE` marker is present. |
| C0000MS-104 | B005 | During the later authorized callback, replace only the active [UID:0000MS] `## Score Rationale` paragraph currently at line 177: change stale present-tense `89/90` to current `94/94`, explain that the complete three-function inventory, exact ranges/hashes/xrefs, modern/legacy behavior, dependencies, exclusions, and formal CPP/H close completion while lexical naming and final build equivalence cap the score, and retain every valid dated score/ownership entry as labeled history. | `by-file/ProfileStorage.md` | Applied and verified: active line 177 is current `94/94`; dated `89/90` evidence remains labeled history; owner/reconstructability/source route and formal content are unchanged. Scoped validator `000000028125` returned `ok:1`; post-validation SHA256 is `2904793AC11AA9F450219C1095D468BCF83289FC31E2D7FB798B54E481A5DC3B` (28,850 bytes, 222 LF, zero CR). |
| C0000MS-105 | B005 | During the later authorized callback, update [UID:00019T] active Reconstruction Notes line 398 so ProfileStorage owns only importer, loader, and writer while selected-profile refresh remains MapPane/ProfileDialog cross-module support; update active Score Rationale line 413 from stale `88/90` to current `94/94`; preserve historical line 435 and every other valid old evidence statement as labeled history. | `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` | Applied and verified: active lines 398/413 carry the exact three-function boundary, MapPane/ProfileDialog cross-module sidecar route, and current `94/94`; historical line 435 remains `88/90`; owner/emitter and formal CPP/H are unchanged. Scoped validator `000000028126` returned `ok:1`; post-validation SHA256 is `C8CEDB21C310482FB1D4806A30BCE4329643435B3E6E1632A0E59C2594ADB194` (29,784 bytes, 439 LF, zero CR). |
| C0000MS-106 | B005 | During the later authorized callback, update [UID:0001AV] active Status line 166, Assignment line 248, and Score Rationale line 252 from stale `92/93` to current `94/95`; update active Ownership line 241 so ProfileStorage pairs only modern load, legacy import, and writer while selected-profile sidecar helpers remain MapPane/ProfileDialog cross-module support; preserve historical lines 264/266/270/273 and all other valid history. | `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md` | Applied and verified: active lines 166/241/248/252 carry current `94/95`, the exact three-function owner boundary, and cross-module sidecar route; historical lines 264/266/270/273 remain intact; owner/emitter and formal CPP/covered-by H route are unchanged. Scoped validator `000000028127` returned `ok:1`; post-validation SHA256 is `4039E395D512653C97AD1D6EED4E2B79BF98B4894EBA8608AC0C75261C5894CB` (25,011 bytes, 275 LF, zero CR). Command `000000028127` CPP/H hashes `4F83D13DBAE05567A3473E52136BFAF95446448D0D41FC0E61000964E5F1722E` / `7E89ABDA7487830A337721EBE815AD2DBAD69BCA0974CC42205CAC489D1D651F` are dated callback receipts only and have no current generated-authority status; CKF-048 carries the later physical snapshot. |
| IDA-A01 | SUPERVISOR | Apply the importer pure rename exactly as Section 21 specifies. | Supervisor-selected current IDA target | Require fresh current `sub_4F9280 / int()` and global desired-name absence; accept only the endpoint-native rename response; reread `ImportLegacyUserProfileData / int()` with exact F-I bytes/frame/edges/comments preserved. |
| IDA-A02 | SUPERVISOR | Apply the importer function-type edit exactly as Section 21 specifies. | Supervisor-selected current IDA target | Require renamed `ImportLegacyUserProfileData / int()` with complete F-I; apply the direct final type edit without a `FILE *()` intermediate; reread `void __cdecl()` with exact F-I frame and all non-type state preserved. |
| IDA-A03 | SUPERVISOR | Apply the importer function-regular comment edit exactly as Section 21 specifies. | Supervisor-selected current IDA target | Require final `ImportLegacyUserProfileData / void __cdecl()` and exact F-I; accept one result row with target `addr` plus optional empty-string `error` only; reread only the requested function-regular comment delta. |
| IDA-A04 | SUPERVISOR | Apply the loader pure rename exactly as Section 21 specifies. | Supervisor-selected current IDA target | Verify the literal prestate and global desired-name absence; accept only the endpoint-native rename response; reread the desired name with exact F-L bytes/frame/type/edges/comments preserved. |
| IDA-A05 | SUPERVISOR | Apply the loader function-type edit exactly as Section 21 specifies. | Supervisor-selected current IDA target | Verify the complete F-L prestate; accept only the endpoint-native set-type response; reread `void __cdecl()` with exact F-L frame, including `arg_4`, and all non-type state preserved. |
| IDA-A06 | SUPERVISOR | Apply the loader function-regular comment edit exactly as Section 21 specifies. | Supervisor-selected current IDA target | Accept exactly one result row containing target `addr` plus optional empty-string `error` only; reread only the requested function-regular comment delta. |
| IDA-A07 | SUPERVISOR | Apply the writer function-regular comment edit exactly as Section 21 specifies. | Supervisor-selected current IDA target | Accept exactly one result row containing target `addr` plus optional empty-string `error` only; preserve `SaveUserSettings`, `void __cdecl()`, complete F-S, and every non-comment state. |
| WF-001 | SUPERVISOR | Fresh Gate 1 audit the exact report hash, 33 headings, content sufficiency, and twin mechanics. | Supervisor audit ledger | Current exact artifact accepted. |
| WF-002 | SUPERVISOR | After callback, complete Gate 2A claim-by-claim against docs and generated output. | Supervisor audit | All B005 rows independently verified. |
| WF-003 | SUPERVISOR | Complete Gate 2B and supervisor-owned manual coverage validation before report execution. | Supervisor audit | IDA and coverage dispositions recorded. |
| WF-004 | SUPERVISOR | Execute/archive only through the documented validator lifecycle and audit the exact archived artifact. | Validator lifecycle | Archived report and tracker reconcile. |

## Positive Evidence Summary

- The importer and loader are contiguous except for 14 bytes of `0xcc` padding, share the same Config profile slice, and have a strict one-call relation.
- The writer is the exact inverse of the modern loader's eight serialized groups and is called from multiple independent UI/settings modules.
- Path literals, API dispatches, local-player-name retrieval, and `.usr`/`.cfg` behavior consistently identify one profile persistence module.
- Current Config declarations provide semantic field names and exact counts for every serialized group.
- Live hashes, modeled ranges, and xrefs agree with the current target pages; no undiscovered fourth ProfileStorage function was found in callers, callees, adjacent ranges, docs, generated output, or matching reports.

## IDA MCP Facts

| Address | Observed display | Range / size | SHA256 | Observed type evidence | Registered-name evidence |
| --- | --- | --- | --- | --- | --- |
| `0x004f9280` | fresh current `sub_4F9280` at `2026-08-25T20:25:11Z` | `[0x004f9280,0x004f95a2)`, 802 bytes | `AF24E728DFA8B0C28A9DF1A4D29A60BF9055680C2877421F0759B102088F0808` | fresh current item/prototype `int()`; separately dated decompile-only evidence observed first declaration `FILE *sub_4F9280()` and later materialized item `FILE *()` | fresh desired `ImportLegacyUserProfileData` absent; dated globally anchored old `^sub_4F9280$`: 0 and desired `^ImportLegacyUserProfileData$`: 0 |
| `0x004f95b0` | `sub_4F95B0` | `[0x004f95b0,0x004f9d28)`, 1,912 bytes | `C99D8F24811DFD5BCC2BA70D93B266F663ADB162A65750C4A684D18FC202DBD4` | `void __fastcall(unsigned int)` artifact | globally anchored old `^sub_4F95B0$`: 0; desired `^LoadUserProfileData$`: 0 |
| `0x0050aba0` | `SaveUserSettings` | `[0x0050aba0,0x0050b078)`, 1,240 bytes | `0108F81842E9AD6A537622A52E799A65751424BA0237EF70F8AA566D0240BE14` | `void __cdecl()` | desired: exactly 1 at target |

- Importer and loader comments are blank in all checked channels. Save has one regular function comment and otherwise blank channels.
- `Config` exists at size `0x291918`; several profile fields are typed, while target-option/friend/selected-profile storage is still hidden inside a coarse overlapping tail member. `RegistryConfig` and `TargetOptionRow` were not present as standalone IDA types.
- Padding is exactly all `0xcc`: `0x004f95a2-0x004f95b0` (14), `0x004f9d28-0x004f9d30` (8), `0x0050ab95-0x0050aba0` (11), and `0x0050b078-0x0050b080` (8). Three `0xcc` bytes precede the importer at `0x004f927d-0x004f9280`.

## Function / Child Inventory

| Source order | UID / address | Source-facing disposition | Behavior / ownership | CPP/H disposition |
| --- | --- | --- | --- | --- |
| 1 | [UID:00019T] `0x004f9280` | `static void ImportLegacyUserProfileData()` | Current-directory legacy `.cfg` quoted-string importer; sole caller is loader. | File-local CPP; no public H declaration. |
| 2 | [UID:00019T] `0x004f95b0` | `void LoadUserProfileData()` | Defaults Config, opens Documents/current-directory `.usr`, imports legacy on miss, deserializes and migrates. | Global CPP plus shared H declaration. |
| 3 | [UID:0001AV] `0x0050aba0` | `void SaveUserSettings()` | Recreates Documents `.usr` and serializes all eight sections. | Global CPP plus declaration supplied once by [UID:00019T] H. |

- File-owned code totals 3 functions and 3,954 bytes. No owned thunk, EH helper, global storage, vtable, RTTI, resource, or static data table was discovered.
- Imported CRT/Win32/project helpers remain dependencies, not ProfileStorage-owned children.
- Excluded MapPane inventory: UID0001AS selected-profile refresh member, UID00027P sidecar table, UID0003IV sidecar literals, and UID0001DU ProfileDialog forwarder.

Source-level helper/constant disposition:

| Proposed source item | Evidence / compilation disposition |
| --- | --- |
| `ReadLegacyQuotedString` | Human source helper for four repeated legacy quoted-field loops; expected to inline/fold into importer, so it is not a new binary child. |
| `CreateProfileDirectory` | Human source helper for the two identical CreateDirectory/GetLastError gates; expected to inline/fold into loader. |
| `ReadProfileString` | Human source helper for repeated length/StringBase allocation/read/lock operations; expected to inline/fold into loader. |
| `MigrateLegacyShortcuts` | Human source helper for the two post-load migration loops; expected to inline/fold into loader. |
| `k*` counts/lengths | CPP-local integral constants represented by immediates; no owned data allocation or by-global page is required. |

Modern `.usr` stream inventory:

| Section | Writer shape | Loader shape / exact edge behavior |
| --- | --- | --- |
| 1 | 10 repetitions of `uint16 length` plus UTF-16 payload. | Length `>0x7f` returns immediately without `fclose`; otherwise read and append NUL. |
| 2 | 10 single UTF-16 legacy shortcut characters. | Reads exactly 10 characters and appends a local NUL after each. |
| 3 | 20 repetitions of `uint16 length` plus friend-name UTF-16 payload. | Rebuilds 20 `StringBase<wchar_t>` values through detach/read/lock. |
| 4 | `uint16 length` plus selected-profile UTF-16 payload. | Performs direct unchecked read into the 0x100-wide field and writes NUL at file-provided index. |
| 5 | `uint32 count`; each row is `uint32 length` plus UTF-16 payload. | Optional on successful count read; clears vector, trusts count/length, and appends each value. |
| 6 | Literal dword `1`, then 20 code/mode UTF-16 pairs. | Any successfully read dword enables exactly 20 rows; the value is not used as a count. |
| 7 | Dword `30`; each row has type wchar, uint16 length, and payload. | Trusts file count; T/S/I map to 1/2/3; unknown keeps default. Length `>=0x80` leaves payload unread and desynchronizes following input. |
| 8 | Dword `2`; each row has user/monster `L'1'` or `L'0'`. | Trusts file count; character equality produces the two booleans. |

Legacy `.cfg` inventory: the importer obtains current directory and local player name, opens `users\\<player>.cfg`, reads 10 profile-text, 10 legacy-shortcut, 20 friend-name, and one selected-profile quoted UTF-16 fields through a 512-wide scratch buffer, truncates only the selected-profile copy at index 255, closes the stream, and deletes the migrated file. Failure to open is a no-op.

## Direct Xref / Caller Inventory

- Importer: exactly one inbound code xref, loader call at `0x004f974a`.
- Loader: exactly one inbound code xref, [UID:00019K] `InitializeMainUiGraph` call at `0x004f8a83`.
- Writer: eight inbound code xrefs at `0x00504850`, `0x0053dd8c` (raw/no containing function), `0x0053dfb8`, `0x0053ed6e`, `0x0053f15c`, `0x0053f8f8`, `0x005420a7`, and `0x0054252a`.
- Generated owner routes identify writer callers in MapPane, FriendListDialog, MacroDialogs, and TargetOptionDialog. The broad spread rejects ownership by any one caller class.

## Documentation Evidence And IDA Status

- The target metadata headers, formal CPP/H channels, generated output, high-level owner/emitter routes, and active score/ownership prose now agree. [UID:0000MS] line 177 is current `94/94`; [UID:00019T] lines 398/413 enforce the three-function boundary and current `94/94`; [UID:0001AV] lines 166/241/248/252 enforce the three-function boundary, cross-module sidecar route, and current `94/95`. The cited dated history remains intact and explicitly historical.
- [UID:0001QL] and [UID:0001VR] provide the schema/layout authority; [UID:000031] provides the current direct Config declaration.
- IDA names for importer/loader remain autogenerated display labels, but separate globally anchored exact-name queries return zero old and zero desired registrations anywhere in the catalog. That is a normal autogenerated-name baseline, not a collision; address/default-name lookup behavior is not registry evidence.
- Fresh current evidence resolves the importer staging contradiction: the operative type is `int()`, so pure rename A01 preserves `int()` and type action A02 moves directly from `int()` to final `void __cdecl`. The dated decompile-induced `FILE *()` materialization is not required to occur and is not used as a precondition.
- Live evidence closes the former MCP-availability and source-signature blockers. The remaining Config UDT coarseness is explicitly protected from unsafe narrow-pass mutation.

## Ranked Ownership Analysis

1. **ProfileStorage file owner: very strong.** All three functions implement one persistence schema and have cross-module callers.
2. **Config/RegistryConfig owner: rejected.** They own storage/default initialization, not path selection, file lifecycle, serialization, or migration.
3. **MainMenuPane owner: rejected.** It calls load once but does not own save or schema logic.
4. **MapPane owner: rejected.** It contains one save caller and separate selected-profile sidecar logic, but does not own load/import or the shared caller spread.
5. **Per-dialog ownership: rejected.** Dialogs trigger writes; none owns the global persistence contract.

## Source Placement

- Recommended source: `NexusTK/profile/ProfileStorage.cpp` and `NexusTK/profile/ProfileStorage.h`.
- Source order: includes/constants and file-local helpers, file-local importer, global loader, global writer.
- No namespace. Use ordinary C++03 `NULL`, `static const`, and explicit loops/types.
- Header owns only the two public global declarations. Internal constants/helpers/importer remain CPP-local.

## Range / Split / Padding / Reclassification Analysis

- [UID:00019T] is a valid two-function aggregate because both functions share source owner and behavior and the only internal gap is 14 bytes of alignment padding.
- The aggregate ends exactly at `0x004f9d28`; eight bytes of post-padding end at the next function `0x004f9d30` and must not be emitted.
- [UID:0001AV] is an exact single-function child ending at `0x0050b078`; its eight-byte post-padding ends at the next function `0x0050b080` and must not be emitted.
- The 11-byte pre-writer padding remains with neighboring range documentation, not source.
- No new split improves source emission. Splitting the importer and loader would add routing overhead without changing ownership or source placement.

## Negative Evidence Summary

- No symbol, caller, or data evidence supports a `ProfileStorage` namespace or class.
- No fourth ProfileStorage-owned function, global, table, resource, or static object was found.
- No evidence places selected-profile sidecar refresh/table/literals in this file; existing MapPane member/table/literal routes and receiver use oppose that move.
- No evidence supports clamping optional counts, consuming oversized macro payloads, closing on the fixed-slot oversize branch, or bounding selected-profile reads. Those would be behavioral changes.
- No evidence supports retaining IDA labels, decompiler argument/return guesses, stale `m_profileStringSlots`, or broad RegistryConfig field casts in final source.

## IDA Rename / Type / Comment Recommendations

This is a concise supervisor-only Gate 2B handoff. B005 performed no dry run, mutation, save, process action, copy, reopen, attestation, or lifecycle action. The seven `IDA-A` rows below are the complete report-authored mutation set. The supervisor dynamically selects and proves the current IDA target, backup/persistence/recovery method, runtime route, and physical receipts under the controlling workflow; none of those mechanics is encoded as an action, prerequisite program, or completion claim here.

The dated failed attempt `uid0000ms_20260825T103249Z_80381fae` is retained only as zero-mutation evidence that an initially imported `int()` item type may materialize to `FILE *()` when decompilation first declares `FILE *sub_4F9280()`, while complete frame F-I remains unchanged. It supplies no current-state authority, transaction instruction, or completion credit. Fresh supervisor-owned canonical readback at `2026-08-25T20:25:11Z` instead established the current importer as `sub_4F9280 / int()` and caused the old `FILE *()`-based A01 contract to fail closed before dry run or mutation. The repaired sequence uses that exact current state directly; no decompile/materialization step is required or authorized. Every future attempt must still obtain current read-only item-by-item evidence, and any new mismatch returns the report for repair rather than being normalized by an unlisted mutation.

### Shared Endpoint-Native Response Contracts

- Pure rename: each literal one-function request uses `dry_run:false`, `pure:true`, `allow_overwrite:false`, and `stop_on_error:true`. The response must contain exactly one `func` row with request-preserving target `addr`, exact `old`, and exact `name`; row `error` and `dir_error` may be absent or exact empty strings only. `dir`, `func_addr`, `new`, `pure`, row-scope `allow_overwrite`, `stopped`, `stop_on_error`, and `stopped_at` are forbidden. The summary must be exactly `total:1,ok:1,failed:0`; optional summary `dry_run`, `stopped`, and `allow_overwrite` may be absent or false, optional `stop_on_error` may be absent or true, and `stopped_at` must be absent.
- Function type: each `set_type` response must contain exactly one `result` row with `kind:"function"`, `ok:true`, and optional `error` absent or exact empty string. Optional `edit`, if present, must reproduce only the requested semantic address, function kind, and signature. Missing/extra rows, an unrequested target, false `ok`, null/non-string/nonempty `error`, or any other field mismatch fails closed.
- Function comment: each `set_function_comments` response must contain exactly one `result` row whose mandatory `addr` parses as unsigned hexadecimal and equals the action target. The only permitted additional field is optional `error`, which must be the exact empty string; absent `error` is accepted. `function_addr` and every other extra field are forbidden. Missing/extra rows, parse failure, target mismatch, or null/non-string/nonempty `error` fails closed.
- Readback: after each action, use bounded read-only public endpoints to re-establish the addressed function identity/range, item/type, complete frame, four comment channels, bytes/padding, exact xrefs/callees, and applicable globally anchored desired-name state. The corresponding F-I/F-L/F-S seal is the literal protection baseline. Only the row-authorized delta is permitted.

### Seven Atomic Action Recommendations

| ID | Literal prestate and one endpoint action | Evidence and safety/no-change constraints | Exact immediate response and readback |
| --- | --- | --- | --- |
| IDA-A01 | At `0x004f9280`, require fresh current F-I bounds/hash/bytes/padding/frame/edges/comments, display `sub_4F9280`, globally anchored desired name `ImportLegacyUserProfileData` absent, and exact item/prototype type `int()`. Issue `rename({database:DB,batch:{func:[{addr:"0x004f9280",name:"ImportLegacyUserProfileData"}],dry_run:false,pure:true,allow_overwrite:false,stop_on_error:true}})`. | One loader caller, exact importer behavior, and the file-local owner route support the source-facing name. Permit only the function-name delta; preserve `int()` exactly plus range, bytes/hash, padding/items, F-I frame, comments, xrefs/callees, and unrelated catalog/type state. Do not decompile or materialize `FILE *()` as an intermediate requirement. | Require the shared rename response with `addr:"0x004f9280"`, `old:"sub_4F9280"`, and `name:"ImportLegacyUserProfileData"`. Readback must show the desired display/name exactly once at the target, old registered total zero, item/prototype type still exactly `int()`, and every protected F-I field unchanged. |
| IDA-A02 | At `0x004f9280`, require desired name `ImportLegacyUserProfileData`, exact current item/prototype type `int()` preserved by A01, complete F-I frame, and exact F-I bytes/padding/edges/comments, then issue `set_type({database:DB,edits:[{addr:"0x004f9280",kind:"function",signature:"void __cdecl ImportLegacyUserProfileData(void)"}]})`. | Call ABI and decompiled behavior establish a no-argument `void __cdecl` file-local helper. Permit one direct type/decompiler-declaration delta from `int()` to the final signature; preserve desired name, range, bytes/hash, padding/items, complete F-I frame, comments, xrefs/callees, and unrelated state. No `FILE *()` intermediate stage is needed or authorized. | Require the shared set-type response. Readback must show item type `void __cdecl()`, first declaration `void __cdecl ImportLegacyUserProfileData()`, complete F-I unchanged, and every non-type field exact. |
| IDA-A03 | At `0x004f9280`, require desired name/type, exact F-I state, and all four comment channels blank, then issue `set_function_comments({database:DB,items:[{addr:"0x004f9280",comment:"File-local legacy profile importer. Reads quoted UTF-16 fields from users\\\\<player>.cfg into Config profile storage, closes the stream, and deletes the migrated file; source name and locals are evidence-backed reconstruction."}]})`. | Binary behavior and accepted documentation support the sentence. Permit only function-regular comment; preserve name/type/range/bytes/hash/padding/items/F-I frame/xrefs/callees and the other three comment channels. | Require one result row with mandatory `addr:"0x004f9280"` plus optional exact-empty-string `error` only. Readback must show exactly the requested function-regular text; address regular/repeatable and function repeatable remain empty; every other F-I field remains exact. |
| IDA-A04 | At `0x004f95b0`, require F-L bounds/hash/bytes/padding/frame/edges/comments, display `sub_4F95B0`, item type `void __fastcall(unsigned int)`, and globally anchored desired name `LoadUserProfileData` absent. Issue `rename({database:DB,batch:{func:[{addr:"0x004f95b0",name:"LoadUserProfileData"}],dry_run:false,pure:true,allow_overwrite:false,stop_on_error:true}})`. | MainMenuPane caller and complete profile-load behavior support the global source-facing name. Permit only the function-name delta; preserve range, bytes/hash, padding/items, F-L frame/type, comments, xrefs/callees, and unrelated state. | Require the shared rename response with `addr:"0x004f95b0"`, `old:"sub_4F95B0"`, and `name:"LoadUserProfileData"`. Readback must show the desired display/name exactly once at the target, old registered total zero, original type and complete F-L unchanged. |
| IDA-A05 | At `0x004f95b0`, require desired name `LoadUserProfileData`, item type `void __fastcall(unsigned int)`, complete F-L including retained analysis artifact `arg_4`, and exact F-L non-type state, then issue `set_type({database:DB,edits:[{addr:"0x004f95b0",kind:"function",signature:"void __cdecl LoadUserProfileData(void)"}]})`. | Caller ABI and body establish a no-argument global `void __cdecl` loader; the apparent argument is an analysis artifact. Permit only the function-type/decompiler-declaration delta and no frame/local change. | Require the shared set-type response. Readback must show item type `void __cdecl()`, declaration `void __cdecl LoadUserProfileData()`, complete F-L including `arg_4` unchanged, and every non-type field exact. |
| IDA-A06 | At `0x004f95b0`, require desired name/type, exact F-L state, and all four comment channels blank, then issue `set_function_comments({database:DB,items:[{addr:"0x004f95b0",comment:"Global ProfileStorage loader. Initializes user defaults, loads Documents/current-directory .usr data, imports legacy .cfg on miss, and performs exact shortcut migration; malformed-file behavior is intentionally preserved."}]})`. | Exact loader behavior and accepted source ownership support the sentence. Permit only function-regular comment; preserve name/type/range/bytes/hash/padding/items/F-L frame/xrefs/callees and the other three comment channels. | Require one result row with mandatory `addr:"0x004f95b0"` plus optional exact-empty-string `error` only. Readback must show exactly the requested function-regular text; the other three channels and every non-comment F-L field remain exact. |
| IDA-A07 | At `0x0050aba0`, require exact F-S identity `SaveUserSettings`, type `void __cdecl()`, bounds/hash/bytes/padding/frame/edges, the dated baseline function-regular sentence in F-S, and the other three comment channels blank. Issue `set_function_comments({database:DB,items:[{addr:"0x0050aba0",comment:"Global ProfileStorage writer. Recreates Documents\\\\NexusTK\\\\users\\\\<player>.usr and serializes fixed text, legacy shortcut, friend-name, selected-profile, block-listen, compact shortcut, macro, and target-option sections with original ignored-I/O and malformed-state behavior."}]})`. | Exact inverse serialization behavior supports the replacement sentence. Permit only function-regular comment; no writer rename/type/frame/boundary/edge/byte/padding/item or unrelated-state delta is authorized. | Require one result row with mandatory `addr:"0x0050aba0"` plus optional exact-empty-string `error` only. Readback must preserve `SaveUserSettings`, `void __cdecl()`, complete F-S, and every non-comment field while changing only function-regular text to the requested sentence. |

No additional rename, type, comment, local, frame, item, boundary, byte, padding, xref, callee, global, or UDT mutation is recommended by this report.


### Exact Function, Frame, Comment, Xref, And Callee Seals

| Seal | Exact immutable state except authorized A-row deltas |
| --- | --- |
| F-I importer | `[0x004f9280,0x004f95a2)`, 802 bytes, SHA256 `AF24E728DFA8B0C28A9DF1A4D29A60BF9055680C2877421F0759B102088F0808`; fresh current `2026-08-25T20:25:11Z` display/type `sub_4F9280 / int()`; xrefs exactly `0x4f974a code` from `0x4f95b0`; callees in returned order `0x69be70 external`, `0x5a2da0 GetLocalPlayerName`, `0x5de0f0 _wcscat_s`, `0x69be14 external`, `0x69be1c unk_69BE1C external`, `0x5cd657 _wcscpy_s`, `0x582d20 sub_582D20`, `0x5d266c _fclose`, `0x69be60 external`, `0x5c772f @__security_check_cookie@4`, `0x5c7655 ___report_rangecheckfailure`; four baseline comment channels empty. A01 changes only the name and must preserve `int()`; A02 changes that exact `int()` directly to final `void __cdecl`; A03 changes only function-regular comment. Dated read-only decompilation once materialized `FILE *()`, with frame unchanged, but that is historical analysis behavior and not part of the authorized sequence. |
| F-L loader | `[0x004f95b0,0x004f9d28)`, 1,912 bytes, SHA256 `C99D8F24811DFD5BCC2BA70D93B266F663ADB162A65750C4A684D18FC202DBD4`; baseline `sub_4F95B0 / void __fastcall(unsigned int)`; xrefs exactly `0x4f8a83 code` from `MainMenuPane_InitializeMainUiGraph`; callees in order `0x48ebc0 sub_48EBC0`, `0x60d340 SHGetFolderPathW external`, `0x4236e0 sub_4236E0`, `0x69be5c external`, `0x5a2da0 GetLocalPlayerName`, `0x582b20 sub_582B20`, `0x583700 sub_583700`, `0x584540 sub_584540`, `0x69be14 external`, `0x69be70 external`, `0x4f9280 importer`, `0x5d28b8 _fread`, `0x5dfcc7 _fgetwc`, `0x584600 sub_584600`, `0x5835c0 sub_5835C0`, `0x584040 sub_584040`, `0x582b70 sub_582B70`, `0x582a90 sub_582A90`, `0x49cc40 sub_49CC40`, `0x5d266c _fclose`, `0x5c772f @__security_check_cookie@4`; comments blank. Authorized deltas are A04 name, A05 type/decompiler declaration, and A06 function-regular comment only. Importer callee display may reflect A01 while address/order remains exact. |
| F-S writer | `[0x0050aba0,0x0050b078)`, 1,240 bytes, SHA256 `0108F81842E9AD6A537622A52E799A65751424BA0237EF70F8AA566D0240BE14`; exact name/type `SaveUserSettings / void __cdecl()`; xrefs in order `0x504850`, `0x53dd8c` raw/no function, `0x53dfb8`, `0x53ed6e`, `0x53f15c`, `0x53f8f8`, `0x5420a7`, `0x54252a`, all code; callees in order `0x60d340 SHGetFolderPathW`, `0x4236e0 sub_4236E0`, `0x69be5c external`, `0x5a2da0 GetLocalPlayerName`, `0x582b20 sub_582B20`, `0x583700 sub_583700`, `0x584540 sub_584540`, `0x69becc external`, `0x69be60 external`, `0x69be14 external`, `0x5d3458 _fwrite`, `0x5dff38 _fputwc`, `0x584cf0 sub_584CF0`, `0x5d266c _fclose`, `0x582b70 sub_582B70`, `0x5c772f @__security_check_cookie@4`. Baseline function-regular comment is `Global ProfileStorage writer SaveUserSettings. Builds Documents\\NexusTK\\users profile path, recreates the .usr file, and serializes Config profile text/string/list/shortcut/macro/target-option records exactly. Local and field names are source-facing descriptive inference.`; other channels blank. Only A07 function-regular delta is authorized. |

Complete frame F-I, required unchanged around A01-A03:

| Name | Offset | Size | Type |
| --- | --- | --- | --- |
| `var_558` | `0x4` | `0x4` | `_DWORD` |
| `Source` | `0x8` | `0x2` | `wchar_t` |
| `var_356` | `0x206` | `0x2` | `_WORD` |
| `Destination` | `0x408` | `0x2` | `wchar_t` |
| `userName` | `0x508` | `0x2` | `wchar_t` |
| `var_4` | `0x558` | `0x4` | `_DWORD` |
| `__saved_registers` | `0x55c` | `0x4` | `_DWORD` |
| `__return_address` | `0x560` | `0x4` | `_UNKNOWN *` |

Complete frame F-L, required unchanged around A04-A06 (the final `arg_4` is a retained analysis artifact, not a source argument):

| Name | Offset | Size | Type |
| --- | --- | --- | --- |
| `var_494` | `0x10` | `0x4` | `_DWORD` |
| `var_490` | `0x14` | `0x4` | `_DWORD` |
| `var_48C` | `0x18` | `0x4` | `_DWORD` |
| `ElementCount` | `0x1c` | `0x4` | `size_t` |
| `var_484` | `0x20` | `0x4` | `_DWORD` |
| `var_480` | `0x24` | `0x4` | `_DWORD` |
| `var_47C` | `0x28` | `0x4` | `_DWORD` |
| `var_478` | `0x2c` | `0x4` | `_DWORD` |
| `Buffer` | `0x30` | `0x2` | `_WORD` |
| `pszPath` | `0x34` | `0x2` | `WCHAR` |
| `var_268` | `0x23c` | `0x2` | `wchar_t` |
| `Destination` | `0x444` | `0x2` | `wchar_t` |
| `var_10` | `0x494` | `0x4` | `_DWORD` |
| `var_C` | `0x498` | `0x4` | `_DWORD` |
| `var_4` | `0x4a0` | `0x4` | `_DWORD` |
| `__saved_registers` | `0x4a4` | `0x4` | `_DWORD` |
| `__return_address` | `0x4a8` | `0x4` | `_UNKNOWN *` |
| `arg_4` | `0x4b0` | `0x4` | `_DWORD` |

Complete frame F-S, immutable throughout:

| Name | Offset | Size | Type |
| --- | --- | --- | --- |
| `var_48C` | `0x10` | `0x4` | `void *` |
| `var_488` | `0x14` | `0x4` | `_DWORD` |
| `var_484` | `0x18` | `0x4` | `_DWORD` |
| `ElementCount` | `0x1c` | `0x4` | `size_t` |
| `var_47C` | `0x20` | `0x4` | `_DWORD` |
| `var_478` | `0x24` | `0x4` | `_DWORD` |
| `Buffer` | `0x28` | `0x4` | `_DWORD` |
| `pszPath` | `0x2c` | `0x2` | `WCHAR` |
| `var_268` | `0x234` | `0x2` | `wchar_t` |
| `Destination` | `0x43c` | `0x2` | `wchar_t` |
| `var_10` | `0x48c` | `0x4` | `_DWORD` |
| `var_C` | `0x490` | `0x4` | `_DWORD` |
| `var_4` | `0x498` | `0x4` | `_DWORD` |
| `__saved_registers` | `0x49c` | `0x4` | `_DWORD` |
| `__return_address` | `0x4a0` | `0x4` | `_UNKNOWN *` |
| `arg_4` | `0x4a8` | `0x4` | `_DWORD` |

### Explicit No-Action Type Disposition

The broad Config UDT and the absent `RegistryConfig` and `TargetOptionRow` types receive no action in this handoff. Read-only evidence found Config as a UDT of size 2,693,400 (`0x291918`) with 51 ordered members matching the C-seal below; `RegistryConfig` and `TargetOptionRow` were absent. The accepted source reconstruction can use documented source-facing declarations without mutating this high-blast-radius IDA type state. Any future Config layout edit requires a separate dedicated report and supervisor authorization.


Config C-seal ordered member tuples (name@offset/size/type), all 51 required exactly: `_configPrefixToStartupChannel@0x0/2677216/unsigned __int8[2677216]`; `m_startupChannel@0x28d9e0/304/ConfigStartupChannelData`; `_configStartupChannelToOptionCluster@0x28db10/824/unsigned __int8[824]`; `m_soundEffectsEnabled@0x28de48/1/unsigned __int8`; `_configToOptionCluster@0x28de49/15/unsigned __int8[15]`; `m_mapEffectEnabled@0x28de58/1/unsigned __int8`; `m_sayWithEnter@0x28de59/1/unsigned __int8`; `m_doubleClickEnabled@0x28de5a/1/unsigned __int8`; `m_autoMoveEnabled@0x28de5b/1/unsigned __int8`; `m_balloonFillEnabled@0x28de5c/1/unsigned __int8`; `m_staticObjectTransparencyEnabled@0x28de5d/1/unsigned __int8`; `m_shadowEnabled@0x28de5e/1/unsigned __int8`; `m_showUserName@0x28de5f/1/unsigned __int8`; `m_selfLookTopButtonSelected@0x28de60/1/unsigned __int8`; `m_selfLookBottomButtonSelected@0x28de61/1/unsigned __int8`; `m_targetSelectionSuppressed@0x28de62/1/unsigned __int8`; `m_tabVSwap@0x28de63/1/unsigned __int8`; `m_showDamage@0x28de64/1/unsigned __int8`; `m_groupBarEnabled@0x28de65/1/unsigned __int8`; `m_carnageColorEnabled@0x28de66/1/unsigned __int8`; `_alignment_28DE67@0x28de67/1/unsigned __int8`; `m_graphicsSetting@0x28de68/4/unsigned int`; `m_orbTargetShare@0x28de6c/1/unsigned __int8`; `m_f1Swap@0x28de6d/1/unsigned __int8`; `m_whisperEnabled@0x28de6e/1/unsigned __int8`; `m_shoutEnabled@0x28de6f/1/unsigned __int8`; `m_adviceEnabled@0x28de70/1/unsigned __int8`; `m_hearSnoreMode@0x28de71/1/unsigned __int8`; `m_magicEffectsEnabled@0x28de72/1/unsigned __int8`; `m_weatherEffectsEnabled@0x28de73/1/unsigned __int8`; `m_fixedMovementEnabled@0x28de74/1/unsigned __int8`; `m_mapMovementStatusOption@0x28de75/1/unsigned __int8`; `m_seeThroughEnabled@0x28de76/1/unsigned __int8`; `m_hearEmotions@0x28de77/1/unsigned __int8`; `m_chatVisibleLineCount@0x28de78/4/unsigned int`; `m_chatHandleModeIndex@0x28de7c/4/unsigned int`; `m_secondaryChatEnabled@0x28de80/1/unsigned __int8`; `m_chatHandleLeftToggle@0x28de81/1/unsigned __int8`; `m_chatColorPairs@0x28de82/12/ChatColorPair[6]`; `m_clickMoveEnabled@0x28de8e/1/unsigned __int8`; `m_clickLookEnabled@0x28de8f/1/unsigned __int8`; `m_systemMessageHeight@0x28de90/4/unsigned int`; `m_powerDialogThresholdDefaults@0x28de94/8/unsigned __int16[4]`; `m_profileTextSlots@0x28de9c/2560/wchar_t[10][128]`; `m_legacyShortcutText@0x28e89c/2560/wchar_t[10][128]`; `m_compactShortcutRecords@0x28f29c/80/CompactShortcutRecord[20]`; `m_macroHotkeys@0x28f2ec/7920/MacroHotkeyRecord[30]`; `_configAfterMacroHotkeys@0x2911dc/1824/unsigned __int8[1824]`; `m_blockListenNames@0x2918fc/12/SimpleUStringVector`; `m_musicSourceMode@0x291908/4/unsigned int`; `_configTail@0x29190c/12/unsigned __int8[12]`.

The seven A rows are the entire report-authored IDA handoff. Their row order preserves dependencies between each rename, type, and comment, but the supervisor remains responsible for current-target authority, backups, persistence, recovery, and final verification under the controlling workflow.

## First-Draft C++ Recommendation

The following blocks are exact formal recommendations, not illustrative snippets. Definitions go to CPP channels and declarations to H channels.

### [UID:00019T] `RECONSTRUCTION_CPP CODE`

```cpp
#include "ProfileStorage.h"

#include <shlobj.h>
#include <stdio.h>
#include <wchar.h>

#include "../config/Config.h"
#include "../config/RegistryConfig.h"
#include "../platform/PlatformApi.h"
#include "../string/SimpleUString.h"

namespace
{
    static const unsigned int kLocalPlayerNameLength = 0x28;
    static const unsigned int kLegacyPathLength = 0x80;
    static const unsigned int kProfilePathLength = 0x104;
    static const unsigned int kProfileTextCount = 10;
    static const unsigned int kProfileTextLength = 0x80;
    static const unsigned int kFriendNameCount = 20;
    static const unsigned int kSelectedProfileLength = 0x100;
    static const unsigned int kShortcutCount = 20;
    static const unsigned int kMacroTextLength = 0x80;

    static void ReadLegacyQuotedString(FILE *file, wchar_t *destination,
                                       size_t destinationLength)
    {
        wchar_t buffer[512];
        unsigned short length = 0;
        wint_t ch;

        do
        {
            ch = g_pfnReadUtf16CodeUnitFromFile(file);
        }
        while (ch != L'"' && ch != WEOF);

        do
        {
            ch = g_pfnReadUtf16CodeUnitFromFile(file);
            buffer[length] = static_cast<wchar_t>(ch);
            if (ch == L'"' || ch == WEOF)
                break;
            ++length;
        }
        while (true);

        buffer[length] = L'\0';
        if (destinationLength == kSelectedProfileLength &&
            length >= kSelectedProfileLength)
        {
            buffer[kSelectedProfileLength - 1] = L'\0';
        }
        wcscpy_s(destination, destinationLength, buffer);
    }

    static void ImportLegacyUserProfileData()
    {
        wchar_t path[kLegacyPathLength];
        wchar_t playerName[kLocalPlayerNameLength];

        g_pfnGetCurrentDirectoryW(kLegacyPathLength, path);
        GetLocalPlayerName(playerName, kLocalPlayerNameLength);
        wcscat_s(path, kLegacyPathLength, L"\\users\\");
        wcscat_s(path, kLegacyPathLength, playerName);
        wcscat_s(path, kLegacyPathLength, L".cfg");

        FILE *file = g_pfnWideOpenFile(path, L"rb");
        if (file == NULL)
            return;

        Config &config = *g_pConfig;
        unsigned int i;

        for (i = 0; i < kProfileTextCount; ++i)
            ReadLegacyQuotedString(file, config.m_profileTextSlots[i],
                                   kProfileTextLength);

        for (i = 0; i < kProfileTextCount; ++i)
            ReadLegacyQuotedString(file, config.m_legacyShortcutText[i],
                                   kProfileTextLength);

        for (i = 0; i < kFriendNameCount; ++i)
        {
            wchar_t value[512];
            ReadLegacyQuotedString(file, value,
                                   sizeof(value) / sizeof(value[0]));
            config.m_friendNames[i] = value;
        }

        ReadLegacyQuotedString(file, config.m_selectedProfileName,
                               kSelectedProfileLength);

        fclose(file);
        g_pfnDeleteFileW(path);
    }

    static bool CreateProfileDirectory(const wchar_t *path)
    {
        if (g_pfnCreateDirectoryW(path, NULL))
            return true;
        return GetLastError() == ERROR_ALREADY_EXISTS;
    }

    static void ReadProfileString(FILE *file,
                                  mystr::StringBase<wchar_t> &value)
    {
        unsigned short length = 0;
        fread(&length, sizeof(length), 1, file);

        wchar_t *buffer = value.SetLengthWideAndDetach(length);
        fread(buffer, sizeof(wchar_t), length, file);
        value.LockWideBuffer();
    }

    static void MigrateLegacyShortcuts(Config &config)
    {
        unsigned int i;

        for (i = 0; i < kProfileTextCount; ++i)
        {
            wchar_t code = config.m_legacyShortcutText[i][0];
            if (code == L'\0')
                continue;

            config.m_compactShortcutRecords[i].code = code;
            config.m_compactShortcutRecords[i].isSpellMode = 1;
            config.m_legacyShortcutText[i][0] = L'\0';
        }

        for (i = 0; i < kShortcutCount; ++i)
        {
            CompactShortcutRecord &shortcut =
                config.m_compactShortcutRecords[i];
            if (shortcut.code == L'\0')
                continue;

            MacroHotkeyRecord &macro = config.m_macroHotkeys[i];
            macro.state = (shortcut.isSpellMode != 1) + 2;
            macro.text[0] = shortcut.code;
            macro.text[1] = L'\0';
            shortcut.code = L'\0';
        }
    }
}

void LoadUserProfileData()
{
    static_cast<RegistryConfig *>(g_pConfig)->InitializeUserDataDefaults();
    Config &config = *g_pConfig;

    wchar_t documentsPath[MAX_PATH];
    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) != S_OK)
        return;

    wchar_t path[kProfilePathLength];
    swprintf_s(path, L"%s\\NexusTK", documentsPath);
    if (!CreateProfileDirectory(path))
        return;

    swprintf_s(path, L"%s\\NexusTK\\users", documentsPath);
    if (!CreateProfileDirectory(path))
        return;

    wchar_t playerName[kLocalPlayerNameLength];
    GetLocalPlayerName(playerName, kLocalPlayerNameLength);

    SimpleUString profilePath;
    profilePath.Format(L"%s/%s.usr", path, playerName);

    FILE *file = g_pfnWideOpenFile(profilePath.c_str(), L"rb");
    if (file == NULL)
    {
        g_pfnGetCurrentDirectoryW(kLegacyPathLength, path);
        profilePath.Format(L"%s/users/%s.usr", path, playerName);
        file = g_pfnWideOpenFile(profilePath.c_str(), L"rb");
        if (file == NULL)
        {
            ImportLegacyUserProfileData();
            return;
        }
    }

    unsigned int i;
    for (i = 0; i < kProfileTextCount; ++i)
    {
        unsigned short length = 0;
        fread(&length, sizeof(length), 1, file);
        if (length > 0x7f)
            return;

        fread(config.m_profileTextSlots[i], sizeof(wchar_t), length, file);
        config.m_profileTextSlots[i][length] = L'\0';
    }

    for (i = 0; i < kProfileTextCount; ++i)
    {
        config.m_legacyShortcutText[i][0] =
            static_cast<wchar_t>(fgetwc(file));
        config.m_legacyShortcutText[i][1] = L'\0';
    }

    for (i = 0; i < kFriendNameCount; ++i)
        ReadProfileString(file, config.m_friendNames[i]);

    unsigned short selectedLength = 0;
    fread(&selectedLength, sizeof(selectedLength), 1, file);
    fread(config.m_selectedProfileName, sizeof(wchar_t), selectedLength, file);
    config.m_selectedProfileName[selectedLength] = L'\0';

    unsigned int count = 0;
    if (fread(&count, sizeof(count), 1, file) == 1)
    {
        config.m_blockListenNames.Clear();
        for (i = 0; i < count; ++i)
        {
            unsigned int length = 0;
            fread(&length, sizeof(length), 1, file);

            mystr::StringBase<wchar_t> name;
            wchar_t *buffer = name.SetLengthWideAndDetach(length);
            fread(buffer, sizeof(wchar_t), length, file);
            name.LockWideBuffer();
            config.m_blockListenNames.PushBack(name);
        }
    }

    unsigned int present = 0;
    if (fread(&present, sizeof(present), 1, file) == 1)
    {
        for (i = 0; i < kShortcutCount; ++i)
        {
            config.m_compactShortcutRecords[i].code =
                static_cast<wchar_t>(fgetwc(file));
            config.m_compactShortcutRecords[i].isSpellMode =
                fgetwc(file) == L'S';
        }
    }

    count = 0;
    if (fread(&count, sizeof(count), 1, file) == 1 && count != 0)
    {
        for (i = 0; i < count; ++i)
        {
            wint_t type = fgetwc(file);
            if (type == L'T')
                config.m_macroHotkeys[i].state = 1;
            else if (type == L'S')
                config.m_macroHotkeys[i].state = 2;
            else if (type == L'I')
                config.m_macroHotkeys[i].state = 3;

            unsigned short length = 0;
            fread(&length, sizeof(length), 1, file);
            if (length < kMacroTextLength)
            {
                fread(config.m_macroHotkeys[i].text,
                      sizeof(wchar_t), length, file);
                config.m_macroHotkeys[i].text[length] = L'\0';
            }
        }
    }

    count = 0;
    if (fread(&count, sizeof(count), 1, file) == 1 && count != 0)
    {
        for (i = 0; i < count; ++i)
        {
            config.m_targetOptionRows[i].userEnabled = fgetwc(file) == L'1';
            config.m_targetOptionRows[i].monsterEnabled = fgetwc(file) == L'1';
        }
    }

    MigrateLegacyShortcuts(config);
    fclose(file);
}
```

### [UID:00019T] `RECONSTRUCTION_H CODE`

```cpp
#ifndef NEXUSTK_PROFILE_PROFILESTORAGE_H
#define NEXUSTK_PROFILE_PROFILESTORAGE_H

void LoadUserProfileData();
void SaveUserSettings();

#endif
```

### [UID:0001AV] `RECONSTRUCTION_CPP CODE`

```cpp
void SaveUserSettings()
{
    Config &config = *g_pConfig;

    wchar_t documentsPath[MAX_PATH];
    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) != S_OK)
        return;

    wchar_t usersDirectory[MAX_PATH];
    swprintf_s(usersDirectory, L"%s\\NexusTK", documentsPath);
    if (!g_pfnCreateDirectoryW(usersDirectory, NULL) &&
        GetLastError() != ERROR_ALREADY_EXISTS)
    {
        return;
    }

    swprintf_s(usersDirectory, L"%s\\NexusTK\\users", documentsPath);
    if (!g_pfnCreateDirectoryW(usersDirectory, NULL) &&
        GetLastError() != ERROR_ALREADY_EXISTS)
    {
        return;
    }

    wchar_t playerName[0x28];
    GetLocalPlayerName(playerName, 0x28);

    SimpleUString profilePath;
    profilePath.Format(L"%s/%s.usr", usersDirectory, playerName);

    g_pfnSetFileAttributesW(profilePath.c_str(), FILE_ATTRIBUTE_NORMAL);
    g_pfnDeleteFileW(profilePath.c_str());

    FILE *file = g_pfnWideOpenFile(profilePath.c_str(), L"wb");
    if (file == NULL)
        return;

    unsigned int i;
    for (i = 0; i < 10; ++i)
    {
        unsigned short length = static_cast<unsigned short>(
            wcslen(config.m_profileTextSlots[i]));
        fwrite(&length, sizeof(length), 1, file);
        fwrite(config.m_profileTextSlots[i], sizeof(wchar_t), length, file);
    }

    for (i = 0; i < 10; ++i)
        fputwc(config.m_legacyShortcutText[i][0], file);

    for (i = 0; i < 20; ++i)
    {
        unsigned short length = static_cast<unsigned short>(
            config.m_friendNames[i].length());
        fwrite(&length, sizeof(length), 1, file);
        fwrite(config.m_friendNames[i].c_str(), sizeof(wchar_t), length, file);
    }

    unsigned short selectedLength = static_cast<unsigned short>(
        wcslen(config.m_selectedProfileName));
    fwrite(&selectedLength, sizeof(selectedLength), 1, file);
    fwrite(config.m_selectedProfileName,
           sizeof(wchar_t), selectedLength, file);

    unsigned int count = config.m_blockListenNames.Size();
    fwrite(&count, sizeof(count), 1, file);
    for (i = 0; i < count; ++i)
    {
        const mystr::StringBase<wchar_t> &name =
            config.m_blockListenNames[i];
        unsigned int length = name.length();
        fwrite(&length, sizeof(length), 1, file);
        fwrite(name.c_str(), sizeof(wchar_t), length, file);
    }

    unsigned int compactSectionPresent = 1;
    fwrite(&compactSectionPresent, sizeof(compactSectionPresent), 1, file);
    for (i = 0; i < 20; ++i)
    {
        fputwc(config.m_compactShortcutRecords[i].code, file);
        fputwc(config.m_compactShortcutRecords[i].isSpellMode != 0
                   ? L'S' : L'I',
               file);
    }

    count = 30;
    fwrite(&count, sizeof(count), 1, file);
    for (i = 0; i < count; ++i)
    {
        const MacroHotkeyRecord &macro = config.m_macroHotkeys[i];
        if (macro.state == 1)
            fputwc(L'T', file);
        else if (macro.state == 2)
            fputwc(L'S', file);
        else if (macro.state == 3)
            fputwc(L'I', file);

        unsigned short length = static_cast<unsigned short>(
            wcslen(macro.text));
        fwrite(&length, sizeof(length), 1, file);
        fwrite(macro.text, sizeof(wchar_t), length, file);
    }

    count = 2;
    fwrite(&count, sizeof(count), 1, file);
    for (i = 0; i < count; ++i)
    {
        fputwc(config.m_targetOptionRows[i].userEnabled == 1 ? L'1' : L'0',
               file);
        fputwc(config.m_targetOptionRows[i].monsterEnabled == 1 ? L'1' : L'0',
               file);
    }

    fclose(file);
}
```

### [UID:0001AV] `RECONSTRUCTION_H CODE`

Leave blank. [UID:00019T]'s shared `ProfileStorage.h` owns the single public declaration for `SaveUserSettings`; duplicating it in a second H emitter would produce two competing header fragments.

## Final Recommendation

- Accept all three declared targets as one whole-file report.
- Preserve the existing owner/emitter graph and the now-implemented corrected CPP/H, support declarations, caller includes, source-tree inventory, and detailed behavioral documentation.
- Retain the now-validated `94/94`, `94/94`, and `94/95` scores; scoped validation and physical generated reread demonstrate complete CPP/H output.
- Preserve the sidecar exclusions and the high-blast-radius Config UDT protection.
- Preserve the concise Section 21 handoff as exactly seven supervisor-owned actions. Each row contains one literal endpoint action plus target-specific prestate, evidence, no-change constraints, endpoint-native response, and immediate readback; no B-authored runtime, backup, session, save, reopen, promotion, or rollback program is part of the report.
- Enforce the shared pure-rename and set-type envelopes and the current comment response contract: exactly one result row with mandatory target `addr` plus optional exact-empty-string `error` only. `function_addr` is forbidden. Preserve exact F-I/F-L/F-S ranges, hashes, frames, edge lists, padding, and unaffected comment/type/name state around each authorized delta.
- Preserve the fresh importer `sub_4F9280 / int()` readback as the current handoff baseline: A01 renames without changing `int()`, and A02 directly changes `int()` to final `void __cdecl`. Preserve the dated `int()` to `FILE *()` decompile-induced materialization and historical failed namespace only as zero-mutation evidence; neither historical observation dictates a stage or earns completion credit.
- C0000MS-104 through C0000MS-106 are implemented, scoped-validated, physically reread, checked in both twins, and reconciled with one terminal marker. Advance only to fresh Supervisor Gate 1 and Gate 2A on this exact artifact; B005 does not enter coverage, Gate 2B, or lifecycle execution.

## Recommended Target Doc Changes

- [UID:0000MS]: contains the complete inventory, ownership alternatives, exact ranges/hashes/xrefs, behavior, dependency, historical generated-defect record, CPP/H route, exclusion analysis, and current active `94/94` rationale; dated `89/90` evidence remains history.
- [UID:00019T]: contains every loader/importer fact, exact formal CPP/H, active three-function owner boundary, cross-module MapPane/ProfileDialog sidecar route, and current active `94/94` rationale; historical line 435 remains intact.
- [UID:0001AV]: contains every writer fact, exact formal CPP with shared-header disposition, active three-function owner boundary, cross-module sidecar route, and current active `94/95` status/assignment/rationale; historical lines 264/266/270/273 remain intact.

## Recommended Support Doc Changes

- Synchronize profile schema/layout and current Config field spelling in [UID:0001QL], [UID:0001VR], [UID:0001V1], and CompactShortcutRecord support.
- Clarify direct Config storage versus the one narrow RegistryConfig initialization call in Config/RegistryConfig support.
- Add the missing PlatformApi and StringBase declarations and the minimal SimpleUStringVector facade.
- Add one shared header include to each calling translation unit through its owning by-* page; remove the TargetOptionDialog ad hoc declaration.
- Update the proposed-source-tree ProfileStorage subsection to exactly three functions and preserve MapPane sidecar ownership.
- Preserve all four excluded sidecar/forwarder owner routes unchanged while enriching their cross-module dependency prose where needed.

## Score And Metadata Recommendation

| UID | Pre-callback historical | Current post-callback | Owner / emitter | Rationale |
| --- | --- | --- | --- | --- |
| `0000MS` | `89/90` | `94/94` | File owner; existing source root | Whole-file inventory, exact source shape, dependencies, exclusions, and complete CPP/H are closed. |
| `00019T` | `88/90` | `94/94` | `0000MS` / `0000MS` | Exact behaviors and failure semantics plus corrected importer/loader CPP and shared H are complete. |
| `0001AV` | `92/93` | `94/95` | `0000MS` / `0000MS` | Writer is already strongly proven; corrected direct-field source and shared-header disposition close remaining implementation defects. |

- Reconstructability stays true for all three declared targets.
- Scores stay below 95 completion because exact original filename/helper/member spellings and final build-level equivalence remain to be demonstrated. This is not a blocker to human source-facing draft code.

## Open Questions With Attempted Resolution

- **Exact original file name:** no original symbol/path survives. `ProfileStorage` is the strongest current project-wide name from cohesive behavior and existing routing. This is lexical uncertainty only.
- **Exact helper/member spellings:** no PDB symbols survive. Current Config declarations and subsystem conventions support the proposed human names; retaining raw labels would be lower quality.
- **Config IDA tail layout:** bounded live inspection found an overlapping coarse member. A narrow report cannot safely replace it. Source docs remain implementable; a dedicated UDT pass is the only deferred type improvement.
- **Legacy scratch overflow compiler shape:** the fixed local array and checked copy explain the observed compiler range-check path. The proposed source avoids inventing a new external helper and retains the source-level fixed-buffer operation.
- **Header location:** generated callers require declarations and the file has two public globals, so a sibling `ProfileStorage.h` is required. Leaving it absent is not defensible.
- **Selected-profile sidecar placement:** resolved to MapPane by receiver/table/literal and existing owner routes; it is not an open ProfileStorage item.
- **Importer analysis-materialization type:** resolved for the handoff. Fresh current authority is `int()`. Pure rename preserves it, and the following explicit type action changes it directly to final `void __cdecl`; the dated decompile-induced `FILE *()` state is neither required nor authorized as an intermediate stage.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Read-only comparison found all three current rows stale. The supervisor should replace each exact row below only if a fresh pre-edit reread still differs.

`by-file/-coverage-report.md` replacement for [UID:0000MS]:

```text
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md) : reconstructable : 94% : very strong : Complete three-function profile persistence source root for file-local legacy .cfg import, public modern .usr load, and shared .usr save; records exact ranges/hashes/xrefs, eight-section layout and malformed-file semantics, direct Config storage, complete C++03 CPP/H, caller header routes, and explicit MapPane selected-profile sidecar exclusion.
```

`by-memory/-coverage-report.md` replacement for [UID:00019T]:

```text
    - [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md) 0x004f9280-0x004f9d28 | function-pair aggregate | ProfileLoadAndLegacyImport : reconstructable : 94% : very strong : Exact ProfileStorage legacy importer and modern loader with function hashes, caller chain, internal/post padding, Documents/current-directory fallback, all eight deserialization sections, original malformed-input and leak behavior, exact shortcut migration semantics, direct Config fields, and complete human C++03 CPP/shared H.
```

`by-memory/-coverage-report.md` replacement for [UID:0001AV]:

```text
    - [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) 0x0050aba0-0x0050b078 | global function | SaveUserSettings : reconstructable : 94% : very strong : Exact inverse ProfileStorage writer with range/hash/eight callers, destructive Documents file recreation, all eight serialized sections, original ignored-I/O and malformed-state behavior, current Config field names, complete human C++03 CPP, and one shared declaration through [UID:00019T].
```

No tracker text should be edited manually. Generated tracker/coverage state remains validator-owned.

## Follow-Up Actions

1. Supervisor performs wholly fresh Gate 1 and Gate 2A on this exact 63-row callback artifact and independently verifies all 49 checked B005 rows against ordinary pages, validator receipts, and generated output.
2. Supervisor applies or confirms the three manual coverage rows in Section 28; B005 did not edit either coverage file.
3. Supervisor establishes current IDA/runtime/physical authority under the controlling workflow, then evaluates the seven Section 21 actions item by item. For the importer, A01 requires current `sub_4F9280 / int()` and preserves `int()`; A02 requires the renamed function still typed `int()` and directly applies final `void __cdecl`; A03 requires that final name/type. Each literal endpoint response, row-local safety constraint, and immediate readback must match; A03/A06/A07 accept mandatory target `addr` plus optional exact-empty-string `error` only and reject `function_addr`. Any mismatch fails closed for same-report repair before execution/archive.
4. Supervisor alone executes and archives the report through validator lifecycle, then audits the exact archived artifact.
5. The Config UDT tail may receive a separate future dedicated type-layout assignment; it does not block the now-complete ordinary source implementation.

## Confidence

- Very strong: three-function inventory, ranges, hashes, xrefs, public/file-local linkage, path behavior, serialization order, failure semantics, ownership, sidecar exclusion, and physical post-callback generated closure.
- Very strong: concise supervisor-only seven-action IDA handoff with literal endpoint requests, exact target prestates, strict rename/type/comment response contracts, complete F-I/F-L/F-S frame and edge seals, globally collision-free rename requirements, row-local no-change protections, and immediate readbacks. The importer chain is explicitly current `int()` -> rename preserving `int()` -> direct final `void __cdecl`, without a decompile-materialization dependency. Comment results require mandatory target `addr` plus optional exact-empty-string `error` only; `function_addr` is explicitly rejected. Runtime, backup, persistence, and recovery mechanics remain supervisor-owned outside the report.
- Strong: inferred source filename, helper/member lexical spellings, include-path spelling, and exact original local-variable style.
- Current post-callback confidence: [UID:0000MS] 94, [UID:00019T] 94, [UID:0001AV] 95.

## Validator Results

- The accepted prior callback ran one scoped file validator for every then-changed ordinary destination; all 22 commands exited `0` with `ok:1`. Validator-owned generated/projected state refreshed as a side effect; no generated or project-level file was edited directly.
- The C0000MS-104 through C0000MS-106 callback ran exactly three additional scoped validators. All returned exit `0` and `ok:1`; final queue-status command `000000028129` reported zero queued/processing ordinary or generated-refresh jobs.
- The bounded CKF-031 Gate 2A repair ran exactly one additional scoped validator against `by-project-structure/proposed-source-tree.md`; command `000000028153` returned exit 0 and `ok:1`, updated projected stats as a validator-owned side effect, and deferred generated refresh. Its command-`000000028127` physical reread is a dated historical receipt with no current authority after command `000000028163`.

| Callback / repair command ID | Timestamp | Scoped ordinary page | Result |
| --- | --- | --- | --- |
| `000000028125` | `2026-08-25T08:16:06-04:00` | `by-file/ProfileStorage.md` | exit 0, `ok:1`; generated refresh deferred |
| `000000028126` | `2026-08-25T08:16:14-04:00` | `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` | exit 0, `ok:1`; two UID-link normalizations; generated refresh deferred |
| `000000028127` | `2026-08-25T08:16:29-04:00` | `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md` | exit 0, `ok:1`; dated callback generated-refresh receipt, historical and not current authority |
| `000000028153` | `2026-08-25T09:33:17-04:00` | `by-project-structure/proposed-source-tree.md` | exit 0, `ok:1`; projected stats updated; generated refresh deferred |

| Command ID | Timestamp | Scoped ordinary page | Result |
| --- | --- | --- | --- |
| `000000028050` | `2026-08-25T04:16:45-04:00` | `by-file/ProfileStorage.md` | exit 0, `ok:1` |
| `000000028052` | `2026-08-25T04:18:54-04:00` | `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` | exit 0, `ok:1` |
| `000000028053` | `2026-08-25T04:20:02-04:00` | `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md` | exit 0, `ok:1` |
| `000000028054` | `2026-08-25T04:20:46-04:00` | `by-meta/client_profile_storage.md` | exit 0, `ok:1` |
| `000000028055` | `2026-08-25T04:21:51-04:00` | `by-type/by-struct/RegistryConfigUserProfileBlock.md` | exit 0, `ok:1` |
| `000000028056` | `2026-08-25T04:22:25-04:00` | `by-type/by-struct/MacroHotkeyRecord.md` | exit 0, `ok:1` |
| `000000028057` | `2026-08-25T04:23:01-04:00` | `by-class/Config.md` | exit 0, `ok:1` |
| `000000028058` | `2026-08-25T04:23:30-04:00` | `by-class/RegistryConfig.md` | exit 0, `ok:1` |
| `000000028059` | `2026-08-25T04:24:33-04:00` | `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md` | exit 0, `ok:1` |
| `000000028060` | `2026-08-25T04:25:02-04:00` | `by-file/PlatformApi.md` | exit 0, `ok:1` |
| `000000028061` | `2026-08-25T04:25:44-04:00` | `by-type/by-template/StringBaseTemplate.md` | exit 0, `ok:1` |
| `000000028062` | `2026-08-25T04:29:28-04:00` | `by-class/SimpleUStringVector.md` | exit 0, `ok:1` |
| `000000028063` | `2026-08-25T04:30:34-04:00` | `by-project-structure/proposed-source-tree.md` | exit 0, `ok:1` |
| `000000028064` | `2026-08-25T04:31:49-04:00` | `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md` | exit 0, `ok:1` |
| `000000028065` | `2026-08-25T04:31:51-04:00` | `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md` | exit 0, `ok:1` |
| `000000028066` | `2026-08-25T04:31:54-04:00` | `by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md` | exit 0, `ok:1` |
| `000000028067` | `2026-08-25T04:31:57-04:00` | `by-memory/0x00541fa0-0x005420b1.IntegrateMacroDialogOnControlCommand.md` | exit 0, `ok:1` |
| `000000028068` | `2026-08-25T04:32:00-04:00` | `by-memory/0x005424b0-0x00542534.TargetOptionDialogOnControlCommand.md` | exit 0, `ok:1` |
| `000000028069` | `2026-08-25T04:33:16-04:00` | `by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md` | exit 0, `ok:1` |
| `000000028070` | `2026-08-25T04:33:19-04:00` | `by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md` | exit 0, `ok:1` |
| `000000028071` | `2026-08-25T04:33:22-04:00` | `by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md` | exit 0, `ok:1` |
| `000000028072` | `2026-08-25T04:33:38-04:00` | `by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md` | exit 0, `ok:1` |

- Queue status command `000000028075` at `2026-08-25T04:34:35-04:00` showed zero queued/processing ordinary or generated-refresh jobs. Current generated receipts were then read physically.
- Dated physical generated snapshot: all ten relevant artifacts identify validator command `000000028163`, refreshed `2026-08-25T10:16:06-04:00` from a foreground generated refresh. This is the latest observed mutable generated state, not permanent authority; if any artifact identifies a newer command during future Gate 2A, all ten must be reread and this snapshot superseded before acceptance.
- `ProfileStorage.cpp`: SHA256 `70FDBC0C1B50548581224F878FB7F408CD7445210951CFFB5DED26B76073DE3A`, 12,711 bytes, 397 LF, zero CR; exactly one file-local `ImportLegacyUserProfileData` definition, one `LoadUserProfileData` definition, and one `SaveUserSettings` definition; legacy import calls delete after close and has no direct writer call; direct `m_friendNames` use remains; stale namespace/field/C++11/sidecar tokens are absent; UID00019T/UID0001AV metadata remains `94/94` and `94/95`.
- `ProfileStorage.h`: SHA256 `25EB637F70DB331DC2262118A1A74121F88D7196DBACD84C23BE143438BF5A6C`, 567 bytes, 14 LF, zero CR; one complete `NEXUSTK_PROFILE_PROFILESTORAGE_H` guard and exactly one declaration each for `LoadUserProfileData` and `SaveUserSettings`, with UID00019T metadata `94/94`.
- Five caller outputs: `MainMenuPane.cpp` SHA256 `3812D307F772DF5B5A4ED948402F71FBE61E4EE383874A1B91F4DBA11F22A2C9` (31,607 bytes, 862 LF), `MapPane.cpp` `2AC433E9DEA58D7E4E1A091761FB949550297FF87F0FD49D5A0B699C65EE6809` (166,735 bytes, 4,988 LF), `FriendListDialog.cpp` `37A5DE3E46E3FDB3BC4B67779364BA1062D89058C6BCFE81B793F65E50269EB5` (5,087 bytes, 157 LF), `MacroDialogs.cpp` `A85FF423BC71B185B8901112AFD1175CD6D6D75B970EE735339ABAF241A601EB` (35,519 bytes, 1,067 LF), and `TargetOptionDialog.cpp` `3CE0E2DF4316470C023F576599F1DACF161B5701F3A260A479E150E9B182B9E6` (4,451 bytes, 137 LF), all zero CR. Each contains exactly one shared `ProfileStorage.h` include; function-name call counts are respectively `1/1/1/3/1`; all five contain zero ad hoc public declarations.
- Three support headers: `PlatformApi.h` SHA256 `1BBB48199303AA86B8CA192BEE62C1CCBBD11F8960FB946E02483C17372E811A` (1,399 bytes, 31 LF) contains the required `g_pfnReadUtf16CodeUnitFromFile`, `g_pfnCreateDirectoryW`, `g_pfnDeleteFileW`, and `g_pfnSetFileAttributesW` declarations; `StringBase.h` `F1EC1B9155A462E6E7EE8A395E3EA57EBE7B7528F2861038DEF229D4C0845557` (2,618 bytes, 77 LF) declares `SetLengthWideAndDetach` and `LockWideBuffer`; `StringUtil.h` `EF2BAD499E9C096B18ECA386637D5127B2F4FCD4010D1FC8E8E151624C9049F3` (2,663 bytes, 102 LF) exposes `SimpleUStringVector::Clear`, `Size`, both index operators, both `PushBack` forms, and exactly the three pointer fields supporting the 12-byte target layout. All have zero CR.
- No `execute_report`, lifecycle, coverage, tracker, registry, audit, generated-file direct edit, or IDA mutation/save/manage action occurred.

## Changed Files

- The C0000MS-104 through C0000MS-106 callback changed exactly three authorized ordinary target pages and this report. The bounded Gate 2A repair additionally changed only `by-project-structure/proposed-source-tree.md` and this report; the remaining 18 ordinary table rows are unchanged historical receipts from the prior accepted callback. Validator-owned generated/projected files changed only as tool side effects and were not edited directly.
- This Gate 2B current-prestate repair changes only this report. It records the fresh `2026-08-25T20:25:11Z` zero-mutation failure and repairs the importer action chain from current `int()` directly to final `void __cdecl`; command-`000000028163` generated artifacts remain dated read-only observations, are not changed-file claims, and were not edited directly.

| Ordinary destination | SHA256 | Bytes | LF |
| --- | --- | ---: | ---: |
| `by-file/ProfileStorage.md` | `2904793AC11AA9F450219C1095D468BCF83289FC31E2D7FB798B54E481A5DC3B` | 28,850 | 222 |
| `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` | `C8CEDB21C310482FB1D4806A30BCE4329643435B3E6E1632A0E59C2594ADB194` | 29,784 | 439 |
| `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md` | `4039E395D512653C97AD1D6EED4E2B79BF98B4894EBA8608AC0C75261C5894CB` | 25,011 | 275 |
| `by-meta/client_profile_storage.md` | `5ADC0792447B6BEAE0DE5471658221AA6DDEE15F275893881CA44178E83689C0` | 17,968 | 168 |
| `by-type/by-struct/RegistryConfigUserProfileBlock.md` | `80476D6A88C57A3B5F4072E54D0F5A386456A36FCA73EB08AC1F7BADEAD54478` | 51,931 | 309 |
| `by-type/by-struct/MacroHotkeyRecord.md` | `0BBFAE9E1E9F95A984E9F9DD124847DD574DE86E20413CFDFCC8173177756319` | 19,495 | 148 |
| `by-class/Config.md` | `CCB4EF4D996B1428CBB710CB4B1D1FFB01BDDDD87CCF6EC6A5F44745EF40C55E` | 57,937 | 600 |
| `by-class/RegistryConfig.md` | `3F634497AAC0998EF6FA6224362D17B957635458FBDC7716364F2EBDF9CBEC19` | 84,725 | 416 |
| `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md` | `9CF5216495581EC8E3958C7804C995C895D318E8D2F201429CF2C0EA2773019D` | 31,079 | 208 |
| `by-file/PlatformApi.md` | `4BC59B0ACC7A9A3270ACD49173EBF926E6DC056B316715AA615B07F9C4FE4AED` | 33,270 | 178 |
| `by-type/by-template/StringBaseTemplate.md` | `64E47FB84923E07AE9C7CDF08C4231921F9AB42DD70ADB658E0AA0AAA1B1BB07` | 54,475 | 307 |
| `by-class/SimpleUStringVector.md` | `22DE59948F26AF52D4E8DE83BF74C188E982401604EFCDFF2FB0A3905B77509B` | 15,051 | 150 |
| `by-project-structure/proposed-source-tree.md` | `D1CEA8AC4EA51F00E756E2ACF8CCACCA2FAFA1D4F5B5816A2C55F8ADAE0B6B33` | 335,375 | 2,187 |
| `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md` | `8ACEDE104DD89E864AD49AF40995B9E57B7788AE33780D169A4078CEFD4E7EBC` | 42,693 | 453 |
| `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md` | `C765E686F73178F21B1AB0F9B151E8C324D08488611D8035BFE0403A79B876B2` | 35,476 | 280 |
| `by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md` | `3E47CE2D87AC95AA5EDCEA2D6A61CE939E95868E16D8C34B3E44032255883067` | 26,140 | 317 |
| `by-memory/0x00541fa0-0x005420b1.IntegrateMacroDialogOnControlCommand.md` | `DF8854F1734FD5295632C4F4AC77A15B65D13C97E5C0C26BD1F022390D255F87` | 15,851 | 189 |
| `by-memory/0x005424b0-0x00542534.TargetOptionDialogOnControlCommand.md` | `5FA5EE1BFACC7DCD7A7CA275E4CD1FF2279AEDF2C3D402C4F03C7A592D0CADE8` | 6,124 | 86 |
| `by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md` | `D93D44467D45BB74205671B927C79541862103B90C825F3651901A638337BACB` | 21,609 | 287 |
| `by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md` | `56B1E99497E78380E66CE90E87F4F798E430253ADC16848D2257BA9441B92355` | 16,443 | 132 |
| `by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md` | `03484FA95DB4DFCE4E66E07D6EB920D5AABE05FEBF7A24C64CDC5F8EB4D4C4B7` | 7,514 | 70 |
| `by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md` | `D3355DA3B422C50675776A62D755958DFC63B6361F190E6ABC8F50676260E574` | 10,059 | 106 |

- Validator-owned generated/project-level files changed only as earlier callback/repair tool side effects and were not edited directly. The command-`000000028163` snapshot was read-only. Manual coverage, IDA, lifecycle, audit, registry, other reports, goal, notes, and every ordinary file outside the three callback targets plus the bounded proposed-tree repair remained untouched.

## Implementation Tracking Checklist

The rows below remain exact Section 11 twins. All 49 B005 rows are checked after implementation, scoped validation, target reread, and generated CPP/H verification; all 14 surviving supervisor-owned rows remain unchecked.

| Done | ID | Allocation | Claim / required edit | Destination | Verification |
| --- | --- | --- | --- | --- | --- |
| [x] | CKF-001 | B005 | Replace the file summary with the exact three-function whole-file inventory and noncontiguous range explanation. | `by-file/ProfileStorage.md` | Applied: `ProfileStorage.md` lists exactly importer, loader, and writer across the two noncontiguous owned ranges. |
| [x] | CKF-002 | B005 | Document flat global source placement with a file-local importer; reject the unsupported `ProfileStorage` namespace. | `by-file/ProfileStorage.md` | Applied: source placement is flat global C++03; the importer is file-local and no `ProfileStorage` namespace remains. |
| [x] | CKF-003 | B005 | Record the exact importer, loader, and writer byte counts and SHA256 values. | `by-file/ProfileStorage.md` | Applied: the page records 802/1,912/1,240-byte functions and exact SHA256 values `AF24E728...`, `C99D8F24...`, and `0108F818...`. |
| [x] | CKF-004 | B005 | Record all internal/pre/post padding boundaries without absorbing adjacent functions. | `by-file/ProfileStorage.md` | Applied: pre/importer-loader/internal/writer/post padding fences are recorded exactly without absorbing adjacent functions. |
| [x] | CKF-005 | B005 | Record the complete caller/xref inventory and public/file-local linkage. | `by-file/ProfileStorage.md` | Applied: importer and loader each have one inbound caller and writer has all eight exact inbound xrefs with linkage dispositions. |
| [x] | CKF-006 | B005 | Record modern `.usr` section order, widths, optional-tail behavior, and inverse load/save contract. | `by-file/ProfileStorage.md` | Applied: the `.usr` table records all eight sections, widths, fixed/persisted counts, optional tails, and inverse load/save order. |
| [x] | CKF-007 | B005 | Record legacy `.cfg` quoted UTF-16 import, truncation, close, and delete behavior. | `by-file/ProfileStorage.md` | Applied: legacy `.cfg` quoted UTF-16 reads, selected-name truncation, close, delete, and open-failure no-op are documented. |
| [x] | CKF-008 | B005 | Preserve exact malformed-input and ignored-I/O-result behavior rather than adding safety checks. | `by-file/ProfileStorage.md` | Applied: fixed-slot leak return, unchecked selected length, unclamped counts, oversized-macro desync, and ignored I/O results are preserved. |
| [x] | CKF-009 | B005 | Document direct Config field storage and the narrow RegistryConfig cast for default initialization only. | `by-file/ProfileStorage.md` | Applied: storage uses direct `Config` fields; only `InitializeUserDataDefaults` uses the narrow `RegistryConfig` cast. |
| [x] | CKF-010 | B005 | Replace stale `m_profileStringSlots` with `m_friendNames` throughout current source-facing recommendations. | `by-file/ProfileStorage.md` | Applied: current target/formal source uses `m_friendNames`; stale `m_profileStringSlots` is retained only as historical defect text. |
| [x] | CKF-011 | B005 | Record PlatformApi, StringBase, and SimpleUStringVector declaration dependencies. | `by-file/ProfileStorage.md` | Applied: PlatformApi dispatches, StringBase wide-buffer methods, and the SimpleUStringVector facade have explicit owner/header dispositions. |
| [x] | CKF-012 | B005 | Record MapPane selected-profile sidecar/table/literal exclusion and dependency-only relationship. | `by-file/ProfileStorage.md` | Applied: UID0001AS, UID00027P, UID0003IV, and UID0001DU are explicitly excluded with their MapPane/ProfileDialog routes. |
| [x] | CKF-013 | B005 | Raise primary metadata to `94/94` without changing file ownership or reconstructability. | `by-file/ProfileStorage.md` | Applied: primary metadata is `94/94`, `CANONICAL_OWNER:FILE`, reconstructable, with the same source path. |
| [x] | CKF-014 | B005 | Replace [UID:00019T] CPP with corrected C++03-era importer/loader source from Section 22. | `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` | Applied: UID00019T formal CPP exactly carries the accepted C++03 importer/loader source and file-local helpers. |
| [x] | CKF-015 | B005 | Populate [UID:00019T] H with the complete guarded `ProfileStorage.h` from Section 22. | `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` | Applied: UID00019T formal H contains the complete `NEXUSTK_PROFILE_PROFILESTORAGE_H` guard and both public declarations. |
| [x] | CKF-016 | B005 | Correct selected-profile unchecked read, fixed-slot leak path, unbounded optional counts, oversized macro desync, and exact migration state expression. | `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` | Applied: UID00019T prose and CPP preserve unchecked selected-name read, leak return, unbounded tails, macro desync, and `(isSpellMode != 1) + 2`. |
| [x] | CKF-017 | B005 | Record exact function split, hashes, xrefs, comments, and name-registry baseline. | `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` | Applied: UID00019T records exact split, hashes, one importer/loader xref each, blank comments, and autogenerated-name registry baseline. |
| [x] | CKF-018 | B005 | Raise [UID:00019T] metadata to `94/94`; retain owner/emitter [UID:0000MS]. | `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` | Applied: UID00019T is `94/94`, reconstructable, with owner/emitter UID0000MS unchanged. |
| [x] | CKF-019 | B005 | Replace [UID:0001AV] CPP with corrected direct-Config C++03-era writer source from Section 22. | `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md` | Applied: UID0001AV formal CPP exactly carries the accepted direct-Config C++03 writer source. |
| [x] | CKF-020 | B005 | Keep [UID:0001AV] H blank with explicit covered-by proof pointing to [UID:00019T]'s shared header. | `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md` | Applied: UID0001AV formal H is blank and prose identifies UID00019T as the sole shared-header provider. |
| [x] | CKF-021 | B005 | Correct writer friend-name field, exact compact mode byte handling, malformed macro-state output, and ignored I/O results. | `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md` | Applied: writer uses `m_friendNames`, exact compact-mode bytes, asymmetric unknown macro state, and original ignored I/O results. |
| [x] | CKF-022 | B005 | Raise [UID:0001AV] metadata to `94/95`; retain owner/emitter [UID:0000MS]. | `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md` | Applied: UID0001AV is `94/95`, reconstructable, with owner/emitter UID0000MS unchanged. |
| [x] | CKF-023 | B005 | Synchronize the eight-section binary layout and malformed-input semantics. | `by-meta/client_profile_storage.md` | Applied: `client_profile_storage.md` now carries the exact eight-section layout, legacy migration, and malformed-input contract. |
| [x] | CKF-024 | B005 | Synchronize current Config field names, offsets, counts, and direct-storage rule. | `by-type/by-struct/RegistryConfigUserProfileBlock.md` | Applied: the profile-block page records current field names, offsets, counts, direct Config storage, and the narrow default-call cast. |
| [x] | CKF-025 | B005 | Preserve `CompactShortcutRecord` as 4 bytes and document exact byte-one spell-mode semantics. | `by-type/by-struct/RegistryConfigUserProfileBlock.md`; existing declaration owner `by-file/Config.md` | Applied: the existing Config declaration and profile-block owner document exact four-byte layout and `(isSpellMode != 1) + 2`; no duplicate aggregate was created. |
| [x] | CKF-026 | B005 | Preserve `MacroHotkeyRecord` as 264 bytes and document states 1/2/3 plus unknown-state behavior. | `by-type/by-struct/MacroHotkeyRecord.md` | Applied: `MacroHotkeyRecord` remains 264 bytes and documents states 1/2/3 plus unknown-state read/write asymmetry. |
| [x] | CKF-027 | B005 | Document direct Config profile fields and narrow runtime-derived cast for `InitializeUserDataDefaults` only. | `by-class/Config.md` and `by-class/RegistryConfig.md` | Applied: Config and RegistryConfig pages both state direct base storage and the one narrow `InitializeUserDataDefaults` derived call. |
| [x] | CKF-028 | B005 | Add extern declarations for read-UTF16, CreateDirectoryW, DeleteFileW, and SetFileAttributesW dispatch pointers. | `by-file/PlatformApi.md` owner H channel | Applied: generated `PlatformApi.h` command `000000028060` exposes all four required dispatch-pointer declarations. |
| [x] | CKF-029 | B005 | Add declarations for already-emitted `SetLengthWideAndDetach` and `LockWideBuffer`. | `StringBase` owner H documentation | Applied: generated `StringBase.h` command `000000028061` declares `SetLengthWideAndDetach` and `LockWideBuffer` once. |
| [x] | CKF-030 | B005 | Close the minimal 12-byte SimpleUStringVector source facade used by Clear/count/index/PushBack callers. | `SimpleUStringVector` owner docs | Applied: generated `StringUtil.h` command `000000028062` exposes Clear/Size/index/PushBack while retaining three pointers and 12-byte layout; no build was run. |
| [x] | CKF-031 | B005 | Correct the ProfileStorage proposed-tree inventory with exactly three owned functions, the exact importer interval and padding, no direct modern write, and explicit MapPane exclusion. | `by-project-structure/proposed-source-tree.md` | Applied and Gate 2A-repaired: importer is exactly `0x004f9280-0x004f95a2`; `[0x004f95a2,0x004f95b0)` is explicitly 14 bytes of non-emitting compiler padding; successful quoted UTF-16 `.cfg` import closes/deletes the legacy file and does not directly write `.usr`; all four sidecar/forwarder candidates remain excluded. Scoped validator `000000028153` returned exit 0 and `ok:1`; post-validation SHA256 is `D1CEA8AC4EA51F00E756E2ACF8CCACCA2FAFA1D4F5B5816A2C55F8ADAE0B6B33` (335,375 bytes, 2,187 LF, zero CR), with one corrected importer line, one padding line, and zero stale range/rewrite text. |
| [x] | CKF-032 | B005 | Add one `ProfileStorage.h` include for the loader caller. | [UID:00019K] MainMenu generated-owner by-* channel | Applied: generated `MainMenuPane.cpp` contains one `../profile/ProfileStorage.h` include and the loader call. |
| [x] | CKF-033 | B005 | Add one `ProfileStorage.h` include for the MapPane writer caller. | [UID:0002QH] MapPane generated-owner by-* channel | Applied: generated `MapPane.cpp` contains one `../profile/ProfileStorage.h` include and the writer call. |
| [x] | CKF-034 | B005 | Add one `ProfileStorage.h` include for the friend-list writer caller. | [UID:0001DS] FriendListDialog generated-owner by-* channel | Applied: generated `FriendListDialog.cpp` contains one `../profile/ProfileStorage.h` include and the writer call. |
| [x] | CKF-035 | B005 | Add one shared `ProfileStorage.h` include covering all three MacroDialogs writer callers. | [UID:00045G] MacroDialogs translation-unit head/first emitter | Applied: generated `MacroDialogs.cpp` contains one shared `../../profile/ProfileStorage.h` include covering all three writer calls. |
| [x] | CKF-036 | B005 | Add one shared header include and remove the ad hoc `void SaveUserSettings();` declaration. | [UID:0004QU] TargetOptionDialog generated-owner by-* channel | Applied: generated `TargetOptionDialog.cpp` contains one shared header include and zero ad hoc `void SaveUserSettings();` declarations. |
| [x] | CKF-037 | B005 | Preserve UID0001AS MapPane ownership and non-ProfileStorage emitter route. | `by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md` | Applied: UID0001AS remains owner/emitter UID00007Q and explicitly excludes the MapPane member from ProfileStorage. |
| [x] | CKF-038 | B005 | Preserve UID00027P MapPane sidecar table ownership and non-ProfileStorage route. | UID00027P support page | Applied: UID00027P remains owner/emitter UID0000L3 at position 1 and emits the table once through MapPane. |
| [x] | CKF-039 | B005 | Preserve UID0003IV MapPane sidecar literals ownership and non-ProfileStorage route. | UID0003IV support page | Applied: UID0003IV remains owner UID0000L3, nonreconstructable, non-emitting covered-by MapPane literal evidence. |
| [x] | CKF-040 | B005 | Preserve UID0001DU ProfileDialog forwarder ownership and non-ProfileStorage route. | UID0001DU support page | Applied: UID0001DU remains owner/emitter UID0000MR at position 40 as the ProfileDialog-local forwarder. |
| [ ] | CKF-041 | SUPERVISOR | Replace the [UID:0000MS] manual file coverage row with the exact Section 28 payload if current text still differs. | `by-file/-coverage-report.md` | Exact row occurs once. |
| [ ] | CKF-042 | SUPERVISOR | Replace the [UID:00019T] manual memory coverage row with the exact Section 28 payload if current text still differs. | `by-memory/-coverage-report.md` | Exact row occurs once. |
| [ ] | CKF-043 | SUPERVISOR | Replace the [UID:0001AV] manual memory coverage row with the exact Section 28 payload if current text still differs. | `by-memory/-coverage-report.md` | Exact row occurs once. |
| [x] | CKF-044 | B005 | Run scoped validation for every changed ordinary by-* page only after callback authorization. | Each changed by-* page | Applied: all 22 changed ordinary pages passed scoped validation with command IDs `000000028050`, `000000028052` through `000000028072`, exit 0 and `ok:1`. |
| [x] | CKF-045 | B005 | Physically verify generated `ProfileStorage.cpp` against all three functions and behavior after callback validation. | `auto-generated/NexusTK/profile/ProfileStorage.cpp` read-only | Applied: generated `ProfileStorage.cpp` command `000000028053`, SHA256 `01F32C56AB67EC0636C8DC0AC8123CF908DB00B300B154F346ED4B5D89D2E492`, physically contains the accepted importer, loader, and writer once each. |
| [x] | CKF-046 | B005 | Physically verify generated `ProfileStorage.h` exists and exactly declares both public globals after callback validation. | `auto-generated/NexusTK/profile/ProfileStorage.h` read-only | Applied: generated `ProfileStorage.h` command `000000028053`, SHA256 `CD0E585E80AB82677FCA05A17072C2B1209908010810A24A65777F79386B2381`, has one complete guard and exactly both public declarations. |
| [x] | CKF-047 | B005 | Physically verify all caller translation units include the shared header and contain no ad hoc declaration. | Generated callers read-only | Applied: MainMenuPane, MapPane, FriendListDialog, MacroDialogs, and TargetOptionDialog each contain one `ProfileStorage.h` include; the ad hoc declaration count is zero. |
| [x] | CKF-048 | B005 | Record dated validator receipts and physically snapshot mutable generated authority, requiring a fresh reread when a newer command appears. | Sections 31-33 | Applied and refreshed: historical callback/repair commands remain dated receipts only. A physical `2026-08-25T10:16:06-04:00` snapshot verifies all ten relevant generated artifacts identify command `000000028163`, records their current hashes/shape and target-specific semantics, and requires future Gate 2A to reread and replace this snapshot if any relevant artifact identifies a newer command. |
| [x] | CKF-049 | B005 | Reconcile all ledger/checklist rows after callback without checking supervisor-owned IDA/coverage/lifecycle work. | This report | Historical accepted-callback state: both tables held 103 exact twins with 46 checked B005 rows and 57 unchecked supervisor rows. A later rejected operational-handoff artifact held 106 twins with 49 checked B005 rows and 57 unchecked supervisor rows. Current reconciled state: 63 exact ordered twins; all 49 B005 rows, including C0000MS-104 through C0000MS-106 and CKF-031, are checked; all 14 surviving supervisor rows remain unchecked; Section 21 contains exactly seven concise action rows with row-local protections/readbacks and no B-authored transaction program; exactly one terminal `READY_FOR_SUPERVISOR_EXECUTE` marker is present. |
| [x] | C0000MS-104 | B005 | During the later authorized callback, replace only the active [UID:0000MS] `## Score Rationale` paragraph currently at line 177: change stale present-tense `89/90` to current `94/94`, explain that the complete three-function inventory, exact ranges/hashes/xrefs, modern/legacy behavior, dependencies, exclusions, and formal CPP/H close completion while lexical naming and final build equivalence cap the score, and retain every valid dated score/ownership entry as labeled history. | `by-file/ProfileStorage.md` | Applied and verified: active line 177 is current `94/94`; dated `89/90` evidence remains labeled history; owner/reconstructability/source route and formal content are unchanged. Scoped validator `000000028125` returned `ok:1`; post-validation SHA256 is `2904793AC11AA9F450219C1095D468BCF83289FC31E2D7FB798B54E481A5DC3B` (28,850 bytes, 222 LF, zero CR). |
| [x] | C0000MS-105 | B005 | During the later authorized callback, update [UID:00019T] active Reconstruction Notes line 398 so ProfileStorage owns only importer, loader, and writer while selected-profile refresh remains MapPane/ProfileDialog cross-module support; update active Score Rationale line 413 from stale `88/90` to current `94/94`; preserve historical line 435 and every other valid old evidence statement as labeled history. | `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` | Applied and verified: active lines 398/413 carry the exact three-function boundary, MapPane/ProfileDialog cross-module sidecar route, and current `94/94`; historical line 435 remains `88/90`; owner/emitter and formal CPP/H are unchanged. Scoped validator `000000028126` returned `ok:1`; post-validation SHA256 is `C8CEDB21C310482FB1D4806A30BCE4329643435B3E6E1632A0E59C2594ADB194` (29,784 bytes, 439 LF, zero CR). |
| [x] | C0000MS-106 | B005 | During the later authorized callback, update [UID:0001AV] active Status line 166, Assignment line 248, and Score Rationale line 252 from stale `92/93` to current `94/95`; update active Ownership line 241 so ProfileStorage pairs only modern load, legacy import, and writer while selected-profile sidecar helpers remain MapPane/ProfileDialog cross-module support; preserve historical lines 264/266/270/273 and all other valid history. | `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md` | Applied and verified: active lines 166/241/248/252 carry current `94/95`, the exact three-function owner boundary, and cross-module sidecar route; historical lines 264/266/270/273 remain intact; owner/emitter and formal CPP/covered-by H route are unchanged. Scoped validator `000000028127` returned `ok:1`; post-validation SHA256 is `4039E395D512653C97AD1D6EED4E2B79BF98B4894EBA8608AC0C75261C5894CB` (25,011 bytes, 275 LF, zero CR). Command `000000028127` CPP/H hashes `4F83D13DBAE05567A3473E52136BFAF95446448D0D41FC0E61000964E5F1722E` / `7E89ABDA7487830A337721EBE815AD2DBAD69BCA0974CC42205CAC489D1D651F` are dated callback receipts only and have no current generated-authority status; CKF-048 carries the later physical snapshot. |
| [ ] | IDA-A01 | SUPERVISOR | Apply the importer pure rename exactly as Section 21 specifies. | Supervisor-selected current IDA target | Require fresh current `sub_4F9280 / int()` and global desired-name absence; accept only the endpoint-native rename response; reread `ImportLegacyUserProfileData / int()` with exact F-I bytes/frame/edges/comments preserved. |
| [ ] | IDA-A02 | SUPERVISOR | Apply the importer function-type edit exactly as Section 21 specifies. | Supervisor-selected current IDA target | Require renamed `ImportLegacyUserProfileData / int()` with complete F-I; apply the direct final type edit without a `FILE *()` intermediate; reread `void __cdecl()` with exact F-I frame and all non-type state preserved. |
| [ ] | IDA-A03 | SUPERVISOR | Apply the importer function-regular comment edit exactly as Section 21 specifies. | Supervisor-selected current IDA target | Require final `ImportLegacyUserProfileData / void __cdecl()` and exact F-I; accept one result row with target `addr` plus optional empty-string `error` only; reread only the requested function-regular comment delta. |
| [ ] | IDA-A04 | SUPERVISOR | Apply the loader pure rename exactly as Section 21 specifies. | Supervisor-selected current IDA target | Verify the literal prestate and global desired-name absence; accept only the endpoint-native rename response; reread the desired name with exact F-L bytes/frame/type/edges/comments preserved. |
| [ ] | IDA-A05 | SUPERVISOR | Apply the loader function-type edit exactly as Section 21 specifies. | Supervisor-selected current IDA target | Verify the complete F-L prestate; accept only the endpoint-native set-type response; reread `void __cdecl()` with exact F-L frame, including `arg_4`, and all non-type state preserved. |
| [ ] | IDA-A06 | SUPERVISOR | Apply the loader function-regular comment edit exactly as Section 21 specifies. | Supervisor-selected current IDA target | Accept exactly one result row containing target `addr` plus optional empty-string `error` only; reread only the requested function-regular comment delta. |
| [ ] | IDA-A07 | SUPERVISOR | Apply the writer function-regular comment edit exactly as Section 21 specifies. | Supervisor-selected current IDA target | Accept exactly one result row containing target `addr` plus optional empty-string `error` only; preserve `SaveUserSettings`, `void __cdecl()`, complete F-S, and every non-comment state. |
| [ ] | WF-001 | SUPERVISOR | Fresh Gate 1 audit the exact report hash, 33 headings, content sufficiency, and twin mechanics. | Supervisor audit ledger | Current exact artifact accepted. |
| [ ] | WF-002 | SUPERVISOR | After callback, complete Gate 2A claim-by-claim against docs and generated output. | Supervisor audit | All B005 rows independently verified. |
| [ ] | WF-003 | SUPERVISOR | Complete Gate 2B and supervisor-owned manual coverage validation before report execution. | Supervisor audit | IDA and coverage dispositions recorded. |
| [ ] | WF-004 | SUPERVISOR | Execute/archive only through the documented validator lifecycle and audit the exact archived artifact. | Validator lifecycle | Archived report and tracker reconcile. |

Terminal self-audit: 33 H2 headings; 63 ledger rows and 63 exact ordered checklist twins; all 49 B005 rows, including C0000MS-104 through C0000MS-106 and CKF-031, are checked; all 14 surviving supervisor rows are unchecked; exactly one terminal `READY_FOR_SUPERVISOR_EXECUTE` marker is present. Historical 103-row/46-checked and rejected 106-row/49-checked mechanics remain labeled history only. Section 21 contains exactly seven one-endpoint supervisor action recommendations and zero separate `IDA-R`, `IDA-P`, or `IDA-W` rows; every action carries literal current-prestate requirements, evidence, row-local no-change constraints, endpoint-native response, and immediate readback. Fresh `2026-08-25T20:25:11Z` importer authority is `sub_4F9280 / int()`: A01 preserves `int()` during rename, A02 changes that exact state directly to final `void __cdecl`, and A03 requires the final name/type. A03/A06/A07 require one result row with mandatory target `addr` plus optional exact-empty-string `error` only and explicitly reject `function_addr`. F-I/F-L/F-S ranges, hashes, frames, padding, xrefs, callees, and unaffected state remain sealed; desired rename names must be globally absent before their action and unique at the exact target afterward. The dated importer `int()` -> first declaration `FILE *sub_4F9280()` -> materialized `FILE *()` observation and namespace `uid0000ms_20260825T103249Z_80381fae` remain zero-mutation historical evidence only, not current authority, a required stage, or a transaction program. The Config UDT and two absent types have an explicit no-action disposition. CKF-031 records exact importer interval `0x004f9280-0x004f95a2`, 14-byte non-emitting `[0x004f95a2,0x004f95b0)` padding, close/delete-without-direct-write behavior, target SHA256 `D1CEA8AC4EA51F00E756E2ACF8CCACCA2FAFA1D4F5B5816A2C55F8ADAE0B6B33`, and validator command `000000028153`; command `000000028127` remains a dated callback receipt without current authority; CKF-048 records the latest observed mutable command-`000000028163` ten-artifact snapshot and requires a fresh Gate 2A reread if any newer command appears. Accepted ordinary implementation, formal CPP/H, scores, target hashes, validator receipts, manual coverage payloads, and lifecycle-neutral current-state language remain preserved; zero executable transaction fences, status locks, or conflict markers.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"additional_uids":["00019T","0001AV"],"agent":"B005","command_id":"000000028254","destination_path":"executed-b-agent-research/B005/0000MS-ProfileStorage-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0000MS-ProfileStorage-file-source-quality.md","timestamp":"2026-08-25T18:01:01-04:00","uid":"0000MS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
