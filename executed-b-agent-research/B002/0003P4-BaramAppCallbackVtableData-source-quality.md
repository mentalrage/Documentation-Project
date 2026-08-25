** TARGET-REPORT-UID:0003P4 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003P4 BaramApp Callback Vtable Data Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: retain [UID:0003P4] as a BaramApp-owned, reconstructable, compiler-generated RTTI-locator-pointer/vtable child. The accepted ordinary callback has replaced its generic marker and stale score rationale with the exact `PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp>` specialization, exact five-slot table, sole construction route, and resolved source declaration/placement decision below.
- Final disposition: authored source declares a private zero-argument `void` BaramApp callback member named `OpenTerminalPaneAfterStartupLogo` in the BaramApp declaration carried by `app/Application.h`, defines it in `app/Application.cpp`, and binds it in `Application::Startup`; the compiler and shared `util/FunctionObjects.h` template regenerate this exact `.rdata` child. No raw RTTI pointer or vtable array is handwritten.
- Applied supervisor closure: Gate 2A/2B independently verified the eight ordinary artifacts, applied/read back I3P4-001 through I3P4-011, applied and validated the four exact manual coverage operations, and refreshed/verified generated output. This report records those results without asserting a pending or completed lifecycle state.
- Confidence: very strong for range, bytes, ABI, specialization, slots, reachability, owner, rebuild mechanism, and current source route; strong for the inferred original member spelling/access because it is the only established source-facing name, precisely describes the sole behavior/use, and matches current accepted startup/body source without placeholder leakage.

## Supporting Research

- This is a fresh 2026-07-30 report-only pass, not a restatement of the 2026-06-29 empty-emitter reports. The old B009/B013 evidence was treated as historical input and independently rechecked against the current IDB and current docs.
- Current report lifecycle truth is supervisor-owned and derives from the current report path plus validator-owned status/history metadata. This body does not claim a pending, completed, or executed lifecycle state.
- Current authoritative saved database after supervisor Gate 2B: physical `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `836ABCFA986AF47A3CAC9EC1D46A31BE6B9B29DA83B6BCA797E7817F2CCF489F`, 143,194,721 bytes, saved `2026-07-30T12:01:56.5937670-04:00`. `idb_save` succeeded and the supervisor's post-save readback and health checks passed.
- Historical Gate-2B prestate: `D7D29DEB8CDA07A6693B36BEF32A544ABD1921D3A0C9B306A47DFCC350D08CCA`, 143,194,156 bytes. Exact backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B002-UID0003P4-20260730_120046.i64` has that same prestate identity. The bounded `2026-07-30T11:48:36.1778101-04:00` prestate reconciliation remains dated evidence, not current IDB state.
- Earlier saved-IDB checkpoint `3892BDA899A18612985539399C9AC1C97B5AE6F7F9FD5D1DF2859C96472798D1`, 143,194,020 bytes, last write `2026-07-30T10:38:13.8949946-04:00`, and its `2026-07-30T11:00:27.9546103-04:00` no-drift pass are retained as dated research/callback evidence only.
- MCP `idb_list` reported one active/adopted worker, PID `11900`, `is_analyzing:false`; `server_health` was `ok`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, and strings cache ready with 2,068 entries. `auto_analysis_ready:false` was not treated as an outage because the database was idle, reads succeeded, Hex-Rays was ready, and every target query completed consistently.

## Target

- Target UID: `0003P4`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:0003P4] `by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md`, the exact 24-byte callback specialization COL-pointer/vtable range.
- Target path: `source-3/project-documentation/by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md`.
- Historical pre-callback source-queue observation: `auto-generated/-ag-research-tracker.md` command `000000019933`, SHA256 `A1FA9680D296AF86A2BDBB7C6994413256035E5292ADECB4FB42E985B04958D1`, 1,679,360 bytes / 6,633 lines, listed UID0003P4 at line 1724 with then-current `86/91`, reconstructable `true`, and direct/additional/total report counts `0/0/0`. Commands 19972-19979 intentionally skipped generated refresh, so this checkpoint is dated evidence rather than current tracker or lifecycle truth.
- Historical assignment/evidence-time checkpoint: command `000000019928`, SHA256 `5D7DA3EA2FFD3E3C201142EAADAF5A5C753877A84D296E911BC2F827898C378B`, 1,678,833 bytes / 6,633 lines, listed UID0003P4 at line 1725 with the same `86/91`, `true`, `0/0/0` semantics. It is preserved only as dated assignment provenance.
- Current supervisor classification: post-Gate-2 same-report reconciliation for a fresh exact-artifact audit. Ordinary, manual coverage, IDA, and generated closure facts are applied and verified; lifecycle truth remains external validator/path metadata rather than report-body prose.
- Current scores and parent state after the ordinary callback: target `92/94`, owner/emitter [UID:00000V] BaramApp, reconstructable true; physical parent [UID:00025P] remains a non-emitting `86/92` mixed index with `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank emitter.

## Current Target State

- Current metadata after the accepted ordinary callback: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:00000V`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000V`, blank optional position, `Nested:0`.
- Current C++ state: CPP contains the exact four-line compiler-generated specialization marker; H remains blank because this data child owns no declaration. The target does not emit raw table data.
- Resolved ordinary blocker: callback spelling/access/source placement now use private `OpenTerminalPaneAfterStartupLogo` in `app/Application.h`, with definition/binding in `app/Application.cpp`. Historical PDB/file-name uncertainty is preserved as provenance rather than an active source direction.
- Supervisor-owned manual coverage is applied and verified: current by-memory coverage SHA256 `82A918D06B56759FB52713751D1BD4E171379BBC4239229C5616168CB49F0C8E`, 2,108,263 bytes / 4,769 lines, contains exact UID0002Q0 at line 2115, UID00025P at line 4262, and nested UID0003P4 at line 4263; current by-class coverage SHA256 `396DAD20C73A2A54EAF045320B17ECA1FF877B02D36FF4CE204D4BA0D8D0A9E9`, 272,277 bytes / 625 lines, contains exact BaramApp at line 57. By-file and by-vtable remain independently confirmed exact no-ops.
- Current target artifact identity: SHA256 `37CEE1CE47127F6179980C08EBD4610C3ECE7030B799FD7755D406F4B51149D9`, 11,227 bytes, 99 lines; pre-callback identity was `7C58B5F76939566CFED13F5A5C91D69EF894EBB1264DB4FD73BD694402C5F7C2`, 6,161 bytes, 75 lines.
- Current ordinary support identities were rehashed after the external coverage updates and remain unchanged: UID0002Q0 `A3A1D67CB8E6D782C8AC119DF32AFB21E1613356D2B54DD89BCD1C1F0CD854CD` (23,183 bytes / 137 lines); UID0002H7 `800FFF00D1CF1CF48D6E7513AC94C7059425D1DA06BBBAD513B4D2D8D247C8F4` (35,249 / 269); BaramApp `D1E2C70FBCD2AEAFDA3091FDAE5AE371E1124849D5A881604E40D609E74A0C6C` (53,489 / 256); Application `99F4E990F1092F76DA520D5148ED0309F2FB84A01440F4157BEA8F6B08AC0E81` (160,411 / 524); FunctionObjectTemplates `B4F7FEA76D72C598CF89854DBA0973E37F279349B20D0A044DC6EC72296E5AB6` (71,973 / 545); FunctionObjects `80B8650B2E4D41849475CD17F2C9C50825F159C092ADBEFE9F14430D5FDC650A` (77,899 / 336); UID00025P `E481F144156119D01758A80BD0CD8DA58DB59B028529D7DBB50FE99D7DBFF034` (21,926 / 142).
- Current manual-coverage identities are by-memory `82A918D06B56759FB52713751D1BD4E171379BBC4239229C5616168CB49F0C8E` (2,108,263 bytes / 4,769 lines), by-class `396DAD20C73A2A54EAF045320B17ECA1FF877B02D36FF4CE204D4BA0D8D0A9E9` (272,277 / 625), by-file `736B2900338FDFE34C44CD18CF9DF0C7791820D28D42DAB7B5E9DD0691EB6BFE` (162,964 / 317), and by-type/by-vtable `D68E24B090F48570D17727658EE3020292D544C0866DFE1D1CB784EECB6E9571` (67,386 / 146). Historical pre-Gate-2 identities `C5E4E81C...2BAC5` and `64862329...5BC03` are retained only as dated prestates.
- Historical pre-callback support identities were UID0002Q0 `2524FBEA...595E`, UID0002H7 `6F26EB43...592A`, BaramApp `41E1C2F4...30D1`, Application `910F4FD4...547B`, FunctionObjectTemplates `4B88FCAC...255`, FunctionObjects `06326604...149A`, and UID00025P `FF2F5791...0AC7`.
- Current generated closure from supervisor command `000000019993`: `auto-generated/NexusTK/app/Application.cpp` SHA256 `739C98D2FFE9F0F9982796EA5C9219E3F09F45884FA9780774EB2AE1031B0C50`, 35,024 bytes / 901 lines, contains exactly one UID0003P4 contribution, one exact specialization marker, one binding, one callback definition, zero target empty markers, and no raw table definition. Current tracker SHA256 `69EEECA87A63E245662EAC7CE72D3EA46C0C41712DC513FE8F805AFBA19F76FA`, 1,679,725 bytes / 6,634 lines, records UID0003P4 at line 3323 as `92/94`, reconstructable `true`, counts `0/0/0`. Historical command `000000019926` Application.cpp SHA `6BA2F488...0A7A2` and commands 19972-19979 generated-skip state remain dated prestates only.
- Current artifact/lifecycle status: this exact artifact exists only at `tools/leaser/Agents/Agent-B002/research/0003P4-BaramAppCallbackVtableData-source-quality.md`; lifecycle status is not asserted in durable prose and remains authoritative only from its current path plus validator-owned metadata.

## Executive Recommendation

- Keep [UID:0003P4] directly owned/emitted by BaramApp. It is compiler output caused jointly by the shared FunctionObjects template declaration and one BaramApp member binding; Application owns the construction site/file route, not the specialization's semantic type.
- Accept `OpenTerminalPaneAfterStartupLogo` as the project source name rather than treating lack of PDB text as permission to preserve `sub_4F5F50`. The name describes the only observed behavior and use, has already been used consistently in accepted source, and has no conflicting symbol or semantic candidate.
- Resolve placement to `app/Application.h` for the BaramApp class/member declaration and `app/Application.cpp` for its out-of-line definition and binding. A separate `BaramApp.h/.cpp` remains a historical possibility, but is rejected for current reconstruction because no binary/document/source-root evidence requires it and current application-shell docs already provide a coherent route used by WinMain and Application.
- Keep target H blank: this data child owns no header declaration. Do not place an orphan method declaration or raw template specialization table in UID0003P4. The BaramApp member declaration belongs to class support, while the shared template declaration belongs to `util/FunctionObjects.h`.
- Raise target to `92/94`; raise UID0002Q0 to `92/94`; raise broad BaramApp class modestly to `87/91`. Leave UID0002H7, UID00025P, Application file, FunctionObjectTemplates, and FunctionObjects scores unchanged because their remaining caps are broader than this callback table.

## Supervisor Active Recheck

- Supervisor callback history rechecked: exact Gate-1-passed artifact `896BFEAB8F1286383FBE093EDDBFB67601D2C96EB51B11B5779FDE3F8C114B1B` authorized ordinary claims only, and B002 honored those boundaries. Supervisor Gate 2A/2B subsequently applied and independently verified the manual coverage, IDA, and generated closure recorded here; this same report is now reconciled for a fresh exact-artifact audit.
- Split repair is not required. The exact `0x0061d234-0x0061d24c` child is already correctly split from UID00025P and fenced by the preceding updater string tail and following logo path literal.
- Every source-bearing dependency was traced: shared template declaration UID0001WQ/UID0000JO, concrete binding UID0002H7, callback body UID0002Q0, BaramApp class UID00000V, Application file UID0000HG, and mixed physical parent UID00025P.
- No source-bearing child remains blocked. The remaining broad BaramApp field/base-layout work is outside this exact table's source cause and does not justify carrying the callback spelling/placement caveat forward.

## Inference Research Guidance Check

- Binary facts, documentation facts, and inference are separated throughout. Decorated names, dwords, xrefs, function bodies, RTTI graph, and item boundaries are direct IDA facts. Existing routes and accepted names are documentation facts. Access level, original source file choice, and human member spelling are source-shape inferences.
- Current `by-structure.md`/skill rules classify compiler-generated vtable/RTTI bytes as source-declared/generated-binary products: the target may carry an exact formal proof marker, but authored declarations/bindings must remain on the owning class/template/source documents and no raw table may be emitted.
- Existing documentation was not assumed correct: the old callback-spelling/source-split caveat, the generic formal marker, the stale parent coverage row, and the prior B009/B013 score decisions were all rechecked.
- The inference standard requires a best defensible human-source answer when symbol text was stripped. It does not require raw `sub_4F5F50` leakage or permanent indecision. The selected name/access/file route is the highest-probability source reconstruction under current evidence.
- Wave2/Wave3 mentions encountered in historical docs were ignored as stale. No Wave2/Wave3 artifact was used as evidence.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and result | Classification |
| --- | --- | --- |
| Callback type | The exact decorated vtable and RTTI type descriptor encode `PlainMemberFunctionObject0<void (BaramApp::*)(void), BaramApp>`. Hex-Rays' incidental `_DWORD *` return for `sub_4F5F50` is rejected. | Original compiler proof |
| Member name | `OpenTerminalPaneAfterStartupLogo` is accepted. It names the sole behavior: after the logo path, show the cursor and construct TerminalPane. It is already used by UID0002H7/UID0002Q0 and has no competing symbol. | High-probability inferred source spelling |
| Access level | `private` is selected. The callback has one address-taken store inside Application startup, no ordinary callers, and no subclass/external API evidence. Public/protected adds unsupported interface surface. | High-probability inferred source access |
| Header placement | BaramApp's declaration is placed in `app/Application.h`, the existing proposed application-shell header needed by separate WinMain and Application source units. | High-probability source placement |
| Definition placement | `app/Application.cpp` is selected. Current exact children already emit there and the callback is constructed by Application startup. | Strong project route plus binary locality/context |
| Separate BaramApp file | Rejected. It is historically possible but no current evidence requires a separate source/header; introducing one would create a new route solely from uncertainty. | Rejected alternative |
| WinMain-local class declaration | Rejected. WinMain instantiates BaramApp, but activation/deactivation, startup, callback, and application-shell behavior are documented outside entry-point ownership. | Rejected alternative |
| Vtable authoring | Rejected raw array/dword source. Shared template plus concrete member binding regenerate the table and RTTI. | Compiler-generated disposition |
| Formal H on UID0003P4 | Rejected. A data child cannot own the BaramApp method declaration or FunctionObjects template declaration. | Exact no-header disposition |
| RTTI/data types in IDA | No `RTTICompleteObjectLocator` or BaramApp UDT exists in the current IDA type catalog. Data boundary/type changes are therefore rejected; exact repeatable comments are safe. | Tool-aware no-type decision |
| Callback IDA name/type | `sub_4F5F50` and `_DWORD *()` were source-poor and contradicted by the decorated member-pointer type. Gate 2B applied the source-facing name and `void __thiscall(void *this)` type without inventing a missing BaramApp UDT. | Applied/verified Gate 2B result |
| Range/split | Six exact dwords constitute one COL pointer plus five vtable slots; successor `const wchar_t[]` begins exactly at `0x0061d24c`. No padding or mixed owner exists inside the target. | Direct binary fact |
| Score blockers | All target-local blockers were investigated. Spelling/access/placement receive a selected high-probability answer; no in-scope blocker remains to justify `86/91`. | Resolved |

## Evidence Standards Used

- Highest-weight evidence: MSVC decorated vtable/RTTI names, exact dword table, RTTI graph, exact construction stores, exact callback target store, sole xrefs, function disassembly/decompilation, and physical boundaries.
- Corroboration: current by-memory/by-class/by-file/by-template docs, accepted historical B007/B009/B013 reports, current generated Application source, and current by-memory/by-class/by-file/by-vtable manual coverage inventories.
- Negative evidence: no xref to hidden COL cell, no other callback target xref/caller, no target-start pointer byte match, no competing source symbol, no BaramApp/RTTI locator UDT in IDA, no evidence for a separate BaramApp source root, and no interior/successor ownership overlap.
- Evidence ladder result: exact ABI/data facts are direct; source spelling/access/file route are accepted inference backed by the unique behavior/use and established project architecture. Those inferences remain below original-source/PDB proof, which is reflected in scores below `95/95`, not in placeholder code or an unresolved direction.

## Evidence Checked

- Live MCP: `idb_list`, `server_health`, `entity_query`, `lookup_funcs`, `inspect_items`, `get_comments`, `get_bytes`, `xref_query`, `find_bytes`, `decompile`, instruction/disassembly windows, and `type_query`.
- Exact ranges: target and boundaries `0x0061d220-0x0061d264`; RTTI `0x0064a028-0x0064a07c` and type descriptor `0x00677108`; callback `0x004f5f50-0x004f5faf`; startup construction `0x004f63c0-0x004f643c`; all five slot targets.
- Current docs: UID0003P4, UID0002Q0, UID0002H7, UID00025P, BaramApp class, Application class/file, FunctionObjectTemplates, FunctionObjects file, WinMain/Application generated source, manual by-memory/by-class/by-file/by-type-by-vtable coverage, and generated research tracker.
- Historical reports: B007 UID0002H7, B009 UID0002Q0, B013 Application empty-emitter family, B012 BaramApp vtable, B003 BaramApp/Application aggregate and constructor reports. Historical conclusions were accepted only where current evidence agreed.
- Failed/unavailable checks: no source/PDB symbol for the private member and no concrete BaramApp UDT are present. These absences prevent original-text certainty but do not prevent a defensible source-facing reconstruction. No mutation tool was invoked.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C3P4-001 | 0003P4 | Exact target range is six dwords at `0x0061d234-0x0061d24c`. | exact | current bytes/items | `by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md` Range/Layout | incorporate | applied |
| C3P4-002 | 0003P4 | `0x0061d234` is the hidden vftable[-1] pointer to COL `0x0064a028`. | exact | dword, RTTI xref | target Layout/Evidence | incorporate | applied |
| C3P4-003 | 0003P4 | Vtable type is exactly `PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp>`. | exact | decorated vtable/type descriptor names | target Summary/Evidence | incorporate | applied |
| C3P4-004 | 0003P4 | Five slots resolve to scalar deleting destructor, inherited runtime class, inherited change message, invoke, and object size. | exact | dwords, function lookup/decompile | target Layout | incorporate | applied |
| C3P4-005 | 0003P4 | Sole vtable reference is startup store `0x004f63e6`. | exact | xref query | target Reachability | incorporate | applied |
| C3P4-006 | 0003P4 | Sole callback target reference is `0x004f63ec -> 0x004f5f50`. | exact | xref query | target Reconstruction Notes | incorporate | applied |
| C3P4-007 | 0003P4 | Successor begins at `0x0061d24c` as separate `const wchar_t[]` logo-path data. | exact | item/bytes/xrefs | target Boundary Analysis | incorporate | applied |
| C3P4-008 | 0003P4 | Raw RTTI/vtable authoring is rejected; shared template and binding regenerate bytes. | very strong | specialization, construction, template docs | target Rebuild Handling | incorporate | applied |
| C3P4-009 | 0003P4 | Replace generic CPP marker with exact four-line formal marker. | very strong | exact source cause | target formal CPP block | incorporate | applied |
| C3P4-010 | 0003P4 | Formal H remains blank because the data page owns no declaration. | very strong | source ownership rules | target formal H block | already-present | already-present |
| C3P4-011 | 0003P4 | Owner/emitter/reconstructable remain `00000V/00000V/TRUE`. | very strong | decorated BaramApp specialization | target metadata | already-present | already-present |
| C3P4-012 | 0003P4 | Raise target score to `92/94`. | strong | all target-local blockers resolved | target metadata/Score Rationale | incorporate | applied |
| C3P4-013 | 0003P4 | Replace target Item Summary with exact specialization/use/rebuild summary. | very strong | current full pass | target Item Summary | incorporate | applied |
| C3P4-014 | 0002Q0 | Accept member name `OpenTerminalPaneAfterStartupLogo` as current source spelling. | strong | unique behavior/use and accepted source | `by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md` | incorporate | applied |
| C3P4-015 | 0002Q0 | Source signature is zero-argument `void` member, not pointer-returning helper. | exact | decorated member-pointer type | UID0002Q0 Behavior/Score | already-present | already-present |
| C3P4-016 | 0002Q0 | Member declaration belongs to private BaramApp declaration in `app/Application.h`; definition remains `app/Application.cpp`. | strong | one internal binding, current file/header route | UID0002Q0 Reconstruction/Source Placement | incorporate | applied |
| C3P4-017 | 0002Q0 | Existing formal CPP body remains exact; formal H stays blank until complete BaramApp class H is emitted, avoiding an orphan declaration. | strong | current class/header topology | UID0002Q0 formal CPP/H rationale | already-present | already-present |
| C3P4-018 | 0002Q0 | Raise UID0002Q0 score to `92/94`. | strong | former only named caps resolved by accepted inference | UID0002Q0 metadata/Score | incorporate | applied |
| C3P4-019 | 0002H7 | Startup wrapper allocation/layout and callback typedef/binding remain exact. | exact | instructions, decompile, existing formal | `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md` | already-present | already-present |
| C3P4-020 | 0002H7 | Historical wording that original callback spelling remains an active cap must be replaced by the accepted source decision. | strong | current exhaustive pass | UID0002H7 callback evidence/notes | historicalize | applied |
| C3P4-021 | 00000V | BaramApp class docs must record private callback declaration in Application.h and definition in Application.cpp. | strong | source route and reachability | `by-class/BaramApp.md` Source Structure/Open Questions | incorporate | applied |
| C3P4-022 | 00000V | Historical callback spelling/source split uncertainty must not remain a current blocker. | strong | current inference resolution | `by-class/BaramApp.md` Summary/Score/Open Questions | historicalize | applied |
| C3P4-023 | 00000V | Raise broad BaramApp score modestly to `87/91`; unrelated class-layout caps remain. | strong | one broad blocker removed, other caps preserved | `by-class/BaramApp.md` metadata | incorporate | applied |
| C3P4-024 | 0000HG | Application file docs must record Application.h declaration/Application.cpp definition for this callback. | strong | current file route | `by-file/Application.md` contents/migration notes | incorporate | applied |
| C3P4-025 | 0001WQ | FunctionObjectTemplates docs must add the exact BaramApp zero-argument specialization and 24-byte layout evidence. | exact | decorated type and wrapper stores | `by-type/by-template/FunctionObjectTemplates.md` evidence | incorporate | applied |
| C3P4-026 | 0000JO | FunctionObjects file inventory must add the BaramApp specialization, UID0003P4 table, and UID0002Q0/UID0002H7 binding route. | very strong | shared template/source split | `by-file/FunctionObjects.md` Proposed Contents/Evidence | incorporate | applied |
| C3P4-027 | 00025P | Parent remains non-emitting mixed index `86/92`, but its child description gains current exact UID0003P4 resolution. | very strong | existing exact split | `by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md` | incorporate | applied |
| C3P4-028 | 00025P | Replace stale manual parent coverage row (`reconstructable`, `80%`) with current ignored `86%` row. | exact | current metadata versus manual row | `by-memory/-coverage-report.md` UID00025P line 4262 | incorporate | applied |
| C3P4-029 | 0003P4 | Insert exact nested manual child coverage row at `92%`. | exact | target recommendation | `by-memory/-coverage-report.md` UID0003P4 line 4263 | incorporate | applied |
| C3P4-030 | 0002Q0 | Replace UID0002Q0 manual coverage row with `92%` and resolved source declaration wording. | exact | support score recommendation | `by-memory/-coverage-report.md` UID0002Q0 line 2115 | incorporate | applied |
| C3P4-031 | 00000V | Replace BaramApp manual class coverage row with `87%` and resolved callback route wording. | exact | class score recommendation | `by-class/-coverage-report.md` BaramApp line 57 | incorporate | applied |
| C3P4-032 | 0003P4 | Rename IDA function `sub_4F5F50` to `BaramApp__OpenTerminalPaneAfterStartupLogo`. | strong | exact callback type/behavior/one binding | IDA `0x004f5f50` name | incorporate | applied |
| C3P4-033 | 0003P4 | Correct IDA callback type from `_DWORD *()` to `void __thiscall(void *this)`. | exact ABI, conservative object type | decorated type; absent BaramApp UDT | IDA `0x004f5f50` type | incorporate | applied |
| C3P4-034 | 0003P4 | Add exact callback function comment. | very strong | body/binding | IDA `0x004f5f50` function comment | incorporate | applied |
| C3P4-035 | 0003P4 | Add exact hidden-COL-cell comment. | exact | dword/xref | IDA `0x0061d234` repeatable comment | incorporate | applied |
| C3P4-036 | 0003P4 | Add exact vtable-head/slot-0 comment. | exact | name/slot target | IDA `0x0061d238` repeatable comment | incorporate | applied |
| C3P4-037 | 0003P4 | Add exact inherited runtime-class slot comment. | exact | slot target | IDA `0x0061d23c` repeatable comment | incorporate | applied |
| C3P4-038 | 0003P4 | Add exact inherited change-message slot comment. | exact | slot target | IDA `0x0061d240` repeatable comment | incorporate | applied |
| C3P4-039 | 0003P4 | Add exact invoke slot comment. | exact | invoke decompile/layout | IDA `0x0061d244` repeatable comment | incorporate | applied |
| C3P4-040 | 0003P4 | Add exact object-size slot comment. | exact | return-24 body | IDA `0x0061d248` repeatable comment | incorporate | applied |
| C3P4-041 | 0003P4 | Add exact COL semantic repeatable comment while preserving decorated name and regular `signature` comment. | exact | RTTI graph | IDA `0x0064a028` repeatable comment | incorporate | applied |
| C3P4-042 | 0003P4 | Add exact specialization type-descriptor repeatable comment while preserving existing compiler name/regular comment. | exact | RTTI type descriptor | IDA `0x00677108` repeatable comment | incorporate | applied |
| C3P4-043 | 0003P4 | Preserve all shared slot function identities and target/successor data boundaries; supervisor readback found no change. | exact | folded/shared functions and item fences; `NO_CHANGE_VERIFIED` | IDA protected entities/negative constraints | already-present | already-present |
| C3P4-044 | 0003P4 | Generated Application.cpp contains one exact new marker, one binding, one callback body, and no raw table definition. | very strong | command19993 generated topology | generated Application.cpp | incorporate | applied |

- Ledger reconciliation after supervisor Gate 2A/2B: 38 claims are `applied`, six are `already-present`, and zero are blocked. C3P4-028 through C3P4-031 are `APPLIED_VERIFIED` coverage operations; C3P4-032 through C3P4-042 are `APPLIED_VERIFIED` IDA operations; C3P4-043 is `NO_CHANGE_VERIFIED`; C3P4-044 is `APPLIED_VERIFIED` generated closure.

## Positive Evidence Summary

- The exact vtable name and RTTI type descriptor independently encode the full template specialization, including `void (BaramApp::*)()` and `BaramApp` object type.
- The table's only inbound reference is the `Application::Startup` vptr store. The callback function's only inbound reference is the adjacent target store in the same 24-byte wrapper construction.
- Startup stores target at `+8`, zero this-adjust at `+0x0c`, and live BaramApp object at `+0x10`; the shared invoke slot applies the adjustment and invokes that member pointer.
- The callback body uniquely restores cursor visibility and constructs TerminalPane after/without startup logo playback, making `OpenTerminalPaneAfterStartupLogo` a precise human source name.
- Current Application source already uses the exact binding/body. This report aligns docs/IDA/formal marker with that accepted source rather than inventing a new spelling.

## IDA MCP Facts

- Current saved-IDB authority after supervisor Gate 2B is `836ABCFA986AF47A3CAC9EC1D46A31BE6B9B29DA83B6BCA797E7817F2CCF489F`, 143,194,721 bytes, saved `2026-07-30T12:01:56.5937670-04:00`. `idb_save` succeeded and post-save readback/health passed. Prestate `D7D29DEB...D08CCA` and earlier `3892BDA8...798D1` are dated history.
- Current table bytes at `0x0061d234`: `28 a0 64 00 f0 71 46 00 10 4b 4f 00 c0 b6 41 00 a0 71 46 00 f0 73 46 00`.
- Dwords: `0x0064a028`, `0x004671f0`, `0x004f4b10`, `0x0041b6c0`, `0x004671a0`, `0x004673f0`.
- Target items remain six separate four-byte data items. Only `0x0061d238` retains the exact decorated compiler vftable name; all names, types, values, item fences, bytes, and xrefs are preserved. Exact repeatable semantic comments are now present at all six target cells.
- RTTI COL `0x0064a028` points to type descriptor `0x00677108` and class hierarchy descriptor `0x0064a03c`; the hierarchy has three bases and routes through base array `0x0064a04c` and concrete BCD `0x0064a05c`.
- Type descriptor name at `0x00677108` is `??_R0?AV?$PlainMemberFunctionObject0@P8BaramApp@@AEXXZV1@@@@8`; its string is `.?AV?$PlainMemberFunctionObject0@P8BaramApp@@AEXXZV1@@@`.
- Slot functions: `0x004671f0` 24-byte callback scalar deleting destructor; `0x004f4b10` `LObject__GetRuntimeClass`; `0x0041b6c0` `LObject__OnChangeMessage`; `0x004671a0` shared zero-argument member invoke; `0x004673f0` returns object size 24.
- `find_bytes` found no encoded pointer to hidden cell `0x0061d234`; one match for vtable base `0x0061d238` at `0x004f63e8`; one callback target match for `0x004f5f50` at `0x004f63ef`; and two successor-path matches for `0x0061d24c` at `0x004f6402`/`0x004f6436`.
- Callback `0x004f5f50` is now named `BaramApp__OpenTerminalPaneAfterStartupLogo`, typed `void __thiscall BaramApp__OpenTerminalPaneAfterStartupLogo(void *this)`, and has the exact accepted regular function comment; its sole xref remains preserved. No speculative BaramApp UDT or CompleteObjectLocator type was introduced.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061d234-0x0061d24c` | UID0003P4 target | callback COL pointer + five-slot vtable | true | UID00025P physical / UID00000V semantic | `86/91 -> 92/94` | exact compiler-generated child |
| `0x004f5f50-0x004f5faf` | UID0002Q0 | BaramApp callback target/body | true | UID00000V | `90/92 -> 92/94` | source-authored member definition |
| `0x004f5fb0-0x004f6490` | UID0002H7 | Application startup and callback construction | true | UID00000D | `90/91` | existing source binding remains exact |
| `0x0061d118-0x0061d264` | UID00025P | mixed physical index | false | none | `86/92` | non-emitting index, score unchanged |
| `0x004671f0` | UID000327 family | shared scalar deleting destructor variant | false | FunctionObject0 semantic family | current support score | shared compiler glue, no ownership transfer |
| `0x004671a0` | UID000324 family | shared `PlainMemberFunctionObject0::Invoke` | true/marker | shared FunctionObjects | current support score | no concrete BaramApp body authored here |
| `0x004673f0` | UID00032C family | shared callback object-size slot | true/marker | shared FunctionObjects | current support score | returns 24, no ownership transfer |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061d234` | no inbound xref | normal hidden vftable[-1] COL cell; reached relative to vtable base |
| `0x0061d238` | data xref `0x004f63e6` in `sub_4F5FB0` | sole concrete specialization construction |
| `0x004f5f50` | data xref `0x004f63ec` in `sub_4F5FB0`; no ordinary caller | sole stored member callback target |
| `0x0061d24c` | refs `0x004f6401`, `0x004f6435` in startup | successor logo path is separate data used by same startup decision |
| `0x0064a028` | xref from `0x0061d234` | exact callback specialization COL |
| `0x00677108` | xrefs from `0x0064a034`, `0x0064a05c` | concrete specialization RTTI type descriptor |
| `0x004f5f50` body | callees no-argument cursor show, allocator, TerminalPane constructor | behavior supports selected member name |

## Documentation Evidence And IDA Status

- UID0002Q0 now preserves the accepted body, rejects pointer-return source, and records the accepted member spelling/header placement rather than carrying that decision as an active cap.
- UID0002H7 retains the human source binding with `BaramAppCallback0` and `&BaramApp::OpenTerminalPaneAfterStartupLogo`; the superseded spelling caveat is historicalized.
- BaramApp class/file docs now make the current `app/Application.h`/`app/Application.cpp` callback declaration/definition route explicit while preserving unrelated broad class blockers.
- FunctionObjectTemplates/FunctionObjects now inventory the exact BaramApp specialization, 24-byte layout, table, body, and startup binding route at their respective ownership levels.
- IDA retains the correct compiler names for the vtable/RTTI while the callback now has the source-facing name/type/comment and all eight data/RTTI repeatable comments accepted by Gate 2B. Protected compiler names, regular comments, items, fences, bytes, and xrefs are unchanged.
- Historical pre-callback generated Application.cpp was semantically correct for binding/body but used the old generic target marker and old scores. Supervisor command19993 replaced that dated topology with the verified current one-marker/one-binding/one-definition/no-raw-table result.

## Ranked Ownership Analysis

### 1. BaramApp class through Application file root

- Evidence for: decorated template object type is BaramApp; stored target is a BaramApp member pointer; wrapper captures BaramApp; callback body is BaramApp-specific UI startup transition; current class/file route already emits the body.
- Evidence against: the construction occurs inside an Application-named startup method and shared template code owns the generic wrapper implementation.
- Decision: selected semantic owner/emitter `00000V`; Application remains source-file/construction context, and FunctionObjects remains generic template owner.

### 2. FunctionObjects shared template

- Evidence for: vtable slots and object layout are emitted from `PlainMemberFunctionObject0` template code; invoke/destructor/object-size helpers are shared across specializations.
- Evidence against: the concrete member pointer/object type and startup binding are feature-specific; generic template docs cannot own BaramApp's member declaration/body.
- Decision: supporting declaration owner only, not direct target owner.

### 3. Application class or WinMain

- Evidence for: Application startup constructs the wrapper; WinMain instantiates BaramApp and requires its declaration.
- Evidence against: decorated type and callback member are BaramApp, not Application/WinMain; neither owns the concrete member behavior.
- Decision: rejected as semantic owner; retain Application file/header route.

### Proposed new file/grouping, if applicable

- Not applicable. Do not create `BaramApp.cpp`, `BaramApp.h`, a concrete template-class by-class page, or a raw RTTI source file from this evidence.
- Existing `app/Application.h`, `app/Application.cpp`, and `util/FunctionObjects.h` grouping is sufficient and least speculative.

## Source Placement

- Recommended declaration placement: private zero-argument void callback member in the BaramApp class declaration carried by `app/Application.h`.
- Recommended definition placement: [UID:0002Q0] out-of-line body in `app/Application.cpp`.
- Recommended binding placement: [UID:0002H7] `Application::Startup` in `app/Application.cpp`.
- Recommended template placement: reusable `PlainMemberFunctionObject0<TMember,TObject>` declaration in `util/FunctionObjects.h`; no concrete raw vtable source.
- Why this fits: WinMain needs a complete BaramApp type across a separate source unit, the project already proposes Application.h, and all BaramApp exact method children currently route through Application.cpp.
- Rejected: separate BaramApp source/header has no direct support; WinMain-local declaration conflicts with non-entry-point BaramApp methods; FunctionObjects.cpp ownership conflates generic template implementation with feature callback declaration.
- Remaining placement uncertainty: exact historical filenames are unrecoverable without original source/PDB, but the current reconstruction direction is resolved rather than left open. Later original-source proof could rehome files without changing target semantics or formal data disposition.

## Range / Split / Padding / Reclassification Analysis

- Exact target length is `0x18` / 24 bytes. It contains no padding: one four-byte COL pointer plus five four-byte vtable slots.
- Predecessor named string `aNexusupdaterEx` ends before `0x0061d234`; zero-fill/alignment between it and target is outside this exact child.
- Successor `0x0061d24c` is a separate `const wchar_t[]` item (`aNe_5` in current IDA) beginning the `NEXON.LGO` path child. It must not be absorbed or retyped.
- No split/merge/reclassification is recommended. UID00025P remains a mixed, non-emitting physical index; UID0003P4 remains exact reconstructable compiler data.

## Negative Evidence Summary

- No ordinary caller reaches `0x004f5f50`; this rejects a general helper/public API interpretation but supports private callback membership.
- No pointer pattern targets `0x0061d234`; this is expected for an MSVC hidden COL cell and does not imply dead data.
- No second vtable construction or callback target store exists; there is no evidence for multiple source callbacks or a generic exported specialization object.
- No source/PDB member symbol exists. Lack of exact text is not evidence that `sub_4F5F50` is acceptable source spelling.
- No BaramApp UDT or RTTI locator UDT exists in IDA; applying speculative data types could damage correct item/xref boundaries, so only the callback function type and exact comments are recommended.
- Shared slot function addresses appear in other vtables; they must not be renamed as BaramApp-specific functions.
- Nearby logo string use does not make the table string-owned; shared startup use merely explains adjacency.

## IDA Rename / Type / Comment Recommendations

| IDA ID | Address | Entity | Exact current pre-state | Proposed supervisor action | Evidence / safety | Expected readback | Classification |
| --- | --- | --- | --- | --- | --- | --- | --- |
| I3P4-001 | `0x004f5f50` | callback function name | name `sub_4F5F50`; type `_DWORD *()`; regular comment absent; repeatable comment absent; function regular/repeatable comments absent | rename to `BaramApp__OpenTerminalPaneAfterStartupLogo` | unique callback target; no name collision; exact BaramApp member-pointer RTTI | same `0x5f` function, new name exactly | applied-verified |
| I3P4-002 | `0x004f5f50` | callback function type | name `sub_4F5F50`; type `_DWORD *()`; address regular comment absent; address repeatable comment absent; function regular comment absent; function repeatable comment absent | apply `void __thiscall(void *this)` after rename | return is exactly void; `this` is BaramApp but current type catalog has no BaramApp UDT, so `void *` is the conservative IDA-valid object type | type reads `void __thiscall(void *this)` with bytes/xrefs unchanged | applied-verified |
| I3P4-003 | `0x004f5f50` | function regular comment | name `sub_4F5F50`; type `_DWORD *()`; address regular comment absent; address repeatable comment absent; function regular comment absent; function repeatable comment absent | set function regular comment to `BaramApp startup-logo completion callback: restores cursor visibility and constructs TerminalPane; bound once by Application::Startup through PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp>.` | exact body and sole binding | exact function regular comment present; function repeatable comment remains absent; name/type reflect I3P4-001/I3P4-002 | applied-verified |
| I3P4-004 | `0x0061d234` | hidden COL-pointer cell | unnamed four-byte data; type absent; regular/repeatable comments absent; value `0x0064a028`; zero inbound xrefs | set repeatable comment to `MSVC vftable[-1] complete-object-locator pointer for PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp>.` | exact dword/RTTI route | name/type/size/value unchanged; exact repeatable comment present | applied-verified |
| I3P4-005 | `0x0061d238` | vtable head / slot 0 | decorated name `??_7?$PlainMemberFunctionObject0@P8BaramApp@@AEXXZV1@@@6B@`; four-byte data; type absent; comments absent; value `0x004671f0`; one xref | set repeatable comment to `PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp> vftable slot 0: 24-byte scalar deleting destructor.` | decorated type and slot body | compiler name/item/value/xref unchanged; exact repeatable comment present | applied-verified |
| I3P4-006 | `0x0061d23c` | vtable slot 1 | unnamed four-byte data; type absent; comments absent; value `0x004f4b10`; no direct cell xref | set repeatable comment to `Inherited LObject::GetRuntimeClass slot for the BaramApp startup callback wrapper.` | named inherited target | item/value unchanged; exact repeatable comment present | applied-verified |
| I3P4-007 | `0x0061d240` | vtable slot 2 | unnamed four-byte data; type absent; comments absent; value `0x0041b6c0`; no direct cell xref | set repeatable comment to `Inherited LObject::OnChangeMessage slot for the BaramApp startup callback wrapper.` | named inherited target | item/value unchanged; exact repeatable comment present | applied-verified |
| I3P4-008 | `0x0061d244` | vtable slot 3 | unnamed four-byte data; type absent; comments absent; value `0x004671a0`; no direct cell xref | set repeatable comment to `PlainMemberFunctionObject0::Invoke slot; dispatches the stored void (BaramApp::*)() callback after this adjustment.` | exact invoke body/object layout | item/value unchanged; exact repeatable comment present | applied-verified |
| I3P4-009 | `0x0061d248` | vtable slot 4 | unnamed four-byte data; type absent; comments absent; value `0x004673f0`; no direct cell xref | set repeatable comment to `PlainMemberFunctionObject0::GetObjectSize slot; returns 24 bytes for this callback wrapper.` | exact return-24 body | item/value unchanged; exact repeatable comment present | applied-verified |
| I3P4-010 | `0x0064a028` | complete-object locator | decorated name `??_R4?$PlainMemberFunctionObject0@P8BaramApp@@AEXXZV1@@@6B@`; four-byte head with type absent; regular comment `signature`; repeatable comment absent | preserve name/type/regular comment and set repeatable comment to `MSVC complete-object locator for PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp>; referenced by vftable[-1] at 0x0061D234.` | exact RTTI graph | existing regular comment preserved; exact repeatable comment added | applied-verified |
| I3P4-011 | `0x00677108` | RTTI type descriptor | decorated name `??_R0?AV?$PlainMemberFunctionObject0@P8BaramApp@@AEXXZV1@@@@8`; four-byte head with type absent; regular comment `reference to RTTI's vftable`; repeatable comment absent | preserve name/type/regular comment and set repeatable comment to `MSVC RTTI type descriptor for PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp>.` | exact type descriptor string and RTTI refs | existing regular comment preserved; exact repeatable comment added | applied-verified |

- Applied/verified poststate for I3P4-001 through I3P4-011 under `836ABCFA...CCF489F`: `0x004f5f50` is `BaramApp__OpenTerminalPaneAfterStartupLogo`, size `0x5f`, type `void __thiscall BaramApp__OpenTerminalPaneAfterStartupLogo(void *this)`, with exact function regular comment `BaramApp startup-logo completion callback: restores cursor visibility and constructs TerminalPane; bound once by Application::Startup through PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp>.`, blank function repeatable comment, and sole data xref from `0x004f63ec`. Target cells remain six separate four-byte items with exact values/fences and the decorated vtable head only at `0x0061d238`; their exact repeatable comments are applied. COL `0x0064a028` and type descriptor `0x00677108` retain compiler names, blank types, regular comments `signature` / `reference to RTTI's vftable`, exact applied repeatable comments, and preserved one/two RTTI refs.
- Exact applied repeatable comments: `0x0061d234` `MSVC vftable[-1] complete-object-locator pointer for PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp>.`; `0x0061d238` `PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp> vftable slot 0: 24-byte scalar deleting destructor.`; `0x0061d23c` `Inherited LObject::GetRuntimeClass slot for the BaramApp startup callback wrapper.`; `0x0061d240` `Inherited LObject::OnChangeMessage slot for the BaramApp startup callback wrapper.`; `0x0061d244` `PlainMemberFunctionObject0::Invoke slot; dispatches the stored void (BaramApp::*)() callback after this adjustment.`; `0x0061d248` `PlainMemberFunctionObject0::GetObjectSize slot; returns 24 bytes for this callback wrapper.`; `0x0064a028` `MSVC complete-object locator for PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp>; referenced by vftable[-1] at 0x0061D234.`; `0x00677108` `MSVC RTTI type descriptor for PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp>.`.
- Protected dependencies/no-action: do not rename or retype shared slot functions `0x004671f0`, `0x004f4b10`, `0x0041b6c0`, `0x004671a0`, or `0x004673f0` from this target. Do not create a target-wide array item, RTTI UDT, BaramApp UDT, interior names, or new function boundaries.
- Protected fences: predecessor `aNexusupdaterEx` at `0x0061d220` and successor `aNe_5` at `0x0061d24c` retain exact names, item types, bytes, comments, and xrefs.
- Historical Gate-2B mutation order was followed: snapshot all rows/fences; rename/type/comment the callback; add target/RTTI repeatable comments; re-read every row plus protected fences; save once after exact readback. `idb_save` succeeded, current saved identity is `836ABCFA...CCF489F`, and post-save readback/health passed without a guessed BaramApp UDT.

## First-Draft C++ Recommendation

- Eligible for target draft C++: yes, as an exact compiler-generated proof marker only.
- CPP block disposition, exact target formal insertion text:

```cpp
// Compiler-generated RTTI locator pointer and vtable for
// PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp>;
// regenerated from FunctionObjects template declarations and the
// BaramApp::OpenTerminalPaneAfterStartupLogo binding in Application::Startup().
```

- H block disposition: exact blank block. UID0003P4 is data and owns no source declaration.
- Reason it preserves behavior: the shared template class and concrete member binding produce the exact 24-byte wrapper ABI, five virtual slots, COL/type descriptor, and startup dispatch without handwritten binary tables.
- Source-shape rationale: mid-2000s MSVC C++ developers would author the template, class member, and `new PlainMemberFunctionObject0<...>` binding; vtables/RTTI were linker/compiler products.
- Inferred source-facing names: `OpenTerminalPaneAfterStartupLogo` is accepted; no `sub_`, `dword_`, address, decompiler return type, or decorated symbol leaks into authored source.
- Naming style: PascalCase member naming follows current Application/BaramApp source (`Startup`, `Shutdown`, `OnActivate`, `OnDeactivate`) and the already accepted callback body/binding.
- Third-party import directive: not applicable; this is NexusTK application/template compiler output, not a third-party embed.

## Final Recommendation

- Ordinary callback result: C3P4-001 through C3P4-027 are applied or independently confirmed already present across the eight exact ordinary destinations; UID0003P4 owner/emitter/reconstructable metadata remains unchanged while its score, formal marker, Item Summary, and full evidence are updated.
- UID00025P remains a non-emitting ownerless mixed index. Its ordinary child description is synchronized, and exact manual coverage operations C3P4-028 through C3P4-031 are applied and verified in the current by-memory/by-class coverage artifacts.
- Callback spelling/access/placement are resolved in current reconstruction as a private BaramApp member in Application.h with definition/binding in Application.cpp. The historical lack of original PDB/file-name proof remains provenance, not an active target blocker.
- Do not author raw vtable/RTTI data, create a separate BaramApp source root, or transfer semantic ownership to Application/FunctionObjects.
- Supervisor Gate 2B applied and verified IDA changes C3P4-032 through C3P4-042, verified protected state unchanged for C3P4-043, applied/validated manual coverage C3P4-028 through C3P4-031, and verified generated closure C3P4-044. Report lifecycle authority remains external to this body.

## Recommended Target Doc Changes

- Target path applied: `by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md`.
- Metadata applied: `86/91 -> 92/94`; owner/emitter/reconstructable/position/Nested remain unchanged.
- Formal CPP applied: the old generic marker is replaced by the exact four-line marker above. Formal H remains blank.
- Item Summary applied: `Compiler-generated MSVC RTTI locator pointer and five-slot PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp> callback vtable; sole Application::Startup binding targets BaramApp::OpenTerminalPaneAfterStartupLogo, and source declarations regenerate the table without raw data.`
- Applied documentation includes the exact evidence-time IDB identity, bytes, six-dword layout, RTTI hierarchy, slot semantics, xref/pointer-pattern results, source regeneration mechanism, resolved declaration/access/file placement, negative evidence, and score rationale.
- The old 2026-06-29 `86/91` no-score-change decision and unresolved spelling/source-placement cap are preserved as dated history rather than deleted.

## Recommended Support Doc Changes

- Applied `by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md`: `90/92 -> 92/94`; exact CPP body preserved; H remains blank with explicit no-orphan-header rationale; member name/private declaration/Application.h+Application.cpp placement accepted; evidence identity updated and old cap historicalized.
- Applied `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md`: score/formals preserved; callback evidence now records the accepted name/placement and historicalizes the old "exact spelling remains cap" statement.
- Applied `by-class/BaramApp.md`: `86/90 -> 87/91`; private declaration in Application.h/definition in Application.cpp and UID0002Q0/UID0003P4 child rows are current; unrelated field/secondary-base/full-class caps and blank broad H remain.
- Applied `by-file/Application.md`: `89/92` preserved; exact Application.h/Application.cpp callback declaration/definition route and FunctionObjects dependency added.
- Applied `by-type/by-template/FunctionObjectTemplates.md`: `88/90` preserved; concrete BaramApp specialization, exact 24-byte layout, five slots, and startup construction evidence added.
- Applied `by-file/FunctionObjects.md`: `90/89` preserved; concrete BaramApp specialization inventory and exact feature binding/source split added.
- Applied `by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md`: `86/92` and ownerless/non-reconstructable/non-emitting metadata preserved; exact child resolution and evidence-time IDB identity synchronized.
- Manual coverage was an exact supervisor-only operation and is now applied/verified using the payloads below; by-file and by-vtable remained exact no-ops.

## Score And Metadata Recommendation

- UID0003P4 is now `92/94` from historical `86/91`. Reason not lower: every byte, slot, RTTI relationship, owner, source cause, construction route, callback target, boundary, and no-raw-data disposition is exact. Reason not higher: original source/PDB spelling and historical file split are not directly recovered, and the current IDA lacks a BaramApp UDT; selected inference is strong but not original-text proof.
- UID0002Q0 is now `92/94` from historical `90/92`. Its behavior/body/signature are exact and its former spelling/placement cap is resolved by a high-probability reconstruction. It remains below 95 because the member spelling is inferred, not symbol-proven.
- BaramApp is now `87/91` from historical `86/90`. One broad callback declaration/file-route blocker is removed, but unrelated full class fields, secondary base spelling, and complete declaration remain incomplete.
- UID0002H7 stays `90/91`; UID00025P stays `86/92`; Application stays `89/92`; FunctionObjectTemplates stays `88/90`; FunctionObjects stays `90/89`.
- Metadata fields unchanged for UID0003P4: `CANONICAL_OWNER:00000V`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000V`, blank optional position, `Nested:0`.
- Score-improvement attempt: inspected exact original-name evidence, all decorated RTTI, callback behavior, every route/caller, source module docs, generated topology, sibling template specializations, archived reports, and negative alternatives. Result: selected source name/access/file route and eliminated all target-local open blockers; score moves six completion and three confidence points.

## Open Questions With Attempted Resolution

- Callback spelling: checked symbols, names, strings, RTTI, callback body, unique binding, accepted docs/generated source, and alternatives. Resolution: `OpenTerminalPaneAfterStartupLogo` is accepted as the best source spelling; no in-scope open question remains.
- Access: checked all xrefs/callers and class use. Resolution: private; no evidence supports public/protected API exposure.
- Declaration/source placement: checked Application/BaramApp/WinMain file routes, proposed Application.h, separate source needs, physical/function context, and generated source. Resolution: declaration in Application.h, definition/binding in Application.cpp; no separate BaramApp file in current reconstruction.
- Vtable source: checked shared template declaration, object layout, slots, RTTI, and construction. Resolution: compiler-generated, exact target marker only.
- Data types in IDA: checked type catalog. Resolution applied by supervisor: no RTTI/BaramApp UDT was invented; exact comments and the conservative callback function type were applied and independently read back.
- Questions remaining unresolved in target scope: none. Exact historical PDB spelling/file names remain unavailable provenance, but a high-probability source direction is selected and scored accordingly rather than deferred.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Current applied/verified by-memory coverage: SHA256 `82A918D06B56759FB52713751D1BD4E171379BBC4239229C5616168CB49F0C8E`, 2,108,263 bytes / 4,769 lines. Exact current rows are UID0002Q0 line 2115, UID00025P line 4262, and nested UID0003P4 line 4263. Supervisor command `000000019992` validated this artifact with exit `0`, `ok: 1`, only pre-existing `missing_ref_uid` warnings `00039L`/`0003T6`, and completed generated refresh.
- Historical pre-Gate-2 by-memory checkpoint `C5E4E81C9EBC12C6A0A73D187100657F9406043C2B826C1519B8A21BED62BAC5`, 2,107,677 bytes / 4,768 lines, retained the stale/absent rows and is dated prestate only.
- Historical pre-callback by-memory checkpoint `22BB0BB3366ED1A445E99E03D6CED32D1F263E12940D400AEA68D1D19EC705F2`, 2,101,781 bytes / 4,754 lines, with then-current UID00025P line 4249 is retained only as dated evidence; its whole-file identity and old line anchor are superseded.
- Applied exact UID00025P row at current line 4262:

```markdown
    - [UID:00025P][0x0061d118-0x0061d264.BaramAppReadOnlyData](by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md) 0x0061d118-0x0061d264 | mixed read-only data index | BaramAppReadOnlyData : ignored : 86% : very-strong : Reviewed non-emitting mixed index split into exact BaramApp vtable, startup/update string, callback-vtable, and logo-string children plus a separate MainMenuPane locator child; exact children carry source ownership and compiler-data/string dispositions.
```

- Applied exact UID0003P4 nested row at current line 4263:

```markdown
        - [UID:0003P4][0x0061d234-0x0061d24c.BaramAppCallbackVtableData](by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md) 0x0061d234-0x0061d24c | compiler RTTI/vtable data | BaramAppCallbackVtableData : reconstructable : 92% : very-strong : Exact MSVC COL pointer plus five-slot PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp> vtable; sole Application::Startup binding targets BaramApp::OpenTerminalPaneAfterStartupLogo, and shared template/class declarations regenerate the bytes without a raw table.
```

- Applied exact UID0002Q0 row at current line 2115:

```markdown
        - [UID:0002Q0][0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory](by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md) 0x004f5f50-0x004f5faf | callback method | BaramAppTerminalPaneCallbackFactory : reconstructable : 92% : very-strong : Source-ready private void BaramApp startup-logo completion callback declared through Application.h and defined in Application.cpp; exact wrapper RTTI/stores prove signature and ownership, and the body restores cursor visibility then constructs TerminalPane.
```

- Current applied/verified class coverage: `by-class/-coverage-report.md` SHA256 `396DAD20C73A2A54EAF045320B17ECA1FF877B02D36FF4CE204D4BA0D8D0A9E9`, 272,277 bytes / 625 lines. Exact BaramApp row is current at line 57. Supervisor command `000000019993` validated this artifact with exit `0`, `ok: 1`, and completed generated refresh. Applied exact row:

```markdown
- [UID:00000V][BaramApp](by-class/BaramApp.md) : reconstructable : 87% : very strong : Game-client Application specialization routed through Application.h/Application.cpp; source-ready constructor, private startup-logo callback, activation/deactivation methods, primary/secondary vtables, scalar/deleting wrappers, read-only data, and WinMain stack-lifetime EH relationship are documented. Callback declaration spelling/access/placement are resolved for current reconstruction without inventing raw vptr, RTTI, deleting-flag, or EH source.
```

- Historical pre-Gate-2 by-class checkpoint `64862329F2FCE0B5AEF01B349E0D5A5D2F09F0B319C8A9EB173521F5F385BC03`, 272,272 bytes / 625 lines, and earlier pre-callback checkpoint `EE896367FAA8DF9113167918E06166EE932342C986E0BA7A5FA32C674CD74565`, 272,165 / 625, are retained only as dated evidence.
- Current read-only file-coverage inspection: `by-file/-coverage-report.md` SHA256 `736B2900338FDFE34C44CD18CF9DF0C7791820D28D42DAB7B5E9DD0691EB6BFE`, 162,964 bytes / 317 lines. Application UID0000HG remains valid at line 24 with `89%`, and FunctionObjects UID0000JO remains valid at line 105 with `90%`; neither row requires a C3P4 manual operation.
- Current read-only vtable-coverage inspection: `by-type/by-vtable/-coverage-report.md` SHA256 `D68E24B090F48570D17727658EE3020292D544C0866DFE1D1CB784EECB6E9571`, 67,386 bytes / 146 lines. No UID0003P4, UID00025P, UID0002Q0, BaramApp, Application, or FunctionObjects row/anchor exists there, so this target has no by-vtable manual operation.
- Current validator-owned generated closure from command `000000019993`: Application.cpp SHA256 `739C98D2FFE9F0F9982796EA5C9219E3F09F45884FA9780774EB2AE1031B0C50`, 35,024 bytes / 901 lines, with exactly one UID0003P4 contribution, one exact specialization marker, one binding, one callback definition, zero target empty markers, and no raw table definition; tracker SHA256 `69EEECA87A63E245662EAC7CE72D3EA46C0C41712DC513FE8F805AFBA19F76FA`, 1,679,725 bytes / 6,634 lines, with UID0003P4 line 3323 at `92/94`, `true`, `0/0/0`.
- Historical tracker command `000000019933`/line 1724 and command `000000019928`/line 1725 remain dated pre-callback/assignment evidence only. Coverage and generated/tracker artifacts were changed only by the supervisor/validator; B002 did not edit them.

## Follow-Up Actions

- Completed B002 ordinary callback: all eight exact ordinary destinations were leased only around their edit/serial validation, released immediately afterward, and reconciled to the ledger with exact post-edit identities and command provenance.
- Supervisor Gate 2A/2B closure recorded: ordinary artifacts were independently verified; I3P4-001 through I3P4-011 were applied/read back; protected entities were verified unchanged; the database was saved once and post-save health/readback passed.
- Supervisor manual/generated closure recorded: exact by-memory UID0002Q0/UID00025P/UID0003P4 and by-class BaramApp rows were applied and validated by commands19992/19993; generated Application.cpp and tracker topology were refreshed and verified; by-file and by-vtable remained exact no-ops.
- C3P4-028 through C3P4-044 are fully reconciled with zero blocked claims. Any report lifecycle status remains authoritative only from the report path and validator-owned status/history metadata, not from this durable prose.
- No A-agent or separate B-agent research is required for this target. Broad BaramApp field/base reconstruction remains separate future class work and must not reopen this callback decision without contrary evidence.

## Confidence

- Recommendation confidence: very strong for compiler-data disposition/owner/route; strong for human member spelling/access/source placement.
- Score confidence: strong. `92/94` recognizes exact binary/source-cause resolution while preserving a real margin below original-source proof.
- Remaining uncertainty: original PDB member text and exact historical filename cannot be recovered from current binary. They are provenance limits, not unresolved implementation directions.

## Validator Results

- Command `000000019972`, timestamp `2026-07-30T11:26:50-04:00`, cwd `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md --apply --queue-timeout 240 --no-generated-refresh`; exit `0`, `ok: 1`, warnings: none. Validator-owned completion/confidence/autogen-registry and projected-stats state was updated; incremental stats reported no further row change; generated refresh was explicitly skipped.
- Command `000000019973`, timestamp `2026-07-30T11:27:45-04:00`, cwd `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md --apply --queue-timeout 240 --no-generated-refresh`; exit `0`, `ok: 1`, warnings: none. Validator-owned completion/confidence/projected-stats state was updated; incremental stats reported no further row change; generated refresh was explicitly skipped.
- Command `000000019974`, timestamp `2026-07-30T11:28:23-04:00`, cwd `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md --apply --queue-timeout 240 --no-generated-refresh`; exit `0`, `ok: 1`, warnings: none. Validator-owned projected-stats state was updated; incremental stats reported no further row change; generated refresh was explicitly skipped.
- Command `000000019975`, timestamp `2026-07-30T11:30:00-04:00`, cwd `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-class/BaramApp.md --apply --queue-timeout 240 --no-generated-refresh`; exit `0`, `ok: 1`; five pre-existing `missing_ref_uid` warnings were reported in sequence for `0003P5`, `0003P6`, `0003P5`, `0003P6`, `0003P5`. Validator-owned completion/confidence/projected-stats state was updated; incremental stats reported no further row change; generated refresh was explicitly skipped.
- Command `000000019976`, timestamp `2026-07-30T11:30:46-04:00`, cwd `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-file/Application.md --apply --queue-timeout 240 --no-generated-refresh`; exit `0`, `ok: 1`; two pre-existing `missing_ref_uid 0003OY` warnings were reported. Validator-owned reference-index entries for `0000JO`, `0001WQ`, and `0003P4` plus projected-stats state were updated; incremental stats reported no further row change; generated refresh was explicitly skipped.
- Command `000000019977`, timestamp `2026-07-30T11:31:43-04:00`, cwd `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-type/by-template/FunctionObjectTemplates.md --apply --queue-timeout 240 --no-generated-refresh`; exit `0`, `ok: 1`; six pre-existing `missing_ref_uid` warnings were reported in sequence for `0003LP`, `0003LP`, `000366`, `000365`, `00036G`, `0003LP`. Validator-owned UID links for `0003P4`/`0002H7`, reference-index entries for `0002H7`/`0002Q0`/`0003P4`, and stats/projected-stats state were updated; generated refresh was explicitly skipped.
- Command `000000019978`, timestamp `2026-07-30T11:32:41-04:00`, cwd `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-file/FunctionObjects.md --apply --queue-timeout 240 --no-generated-refresh`; exit `0`, `ok: 1`; nine pre-existing `missing_ref_uid` warnings were reported in sequence for `0003LP`, `000366`, `000366`, `0003LP`, `0003OQ`, `0003LP`, `0003LP`, `0003OQ`, `0003LP`. Validator-owned UID link `0003P4`, reference-index entries for `0002H7`/`0002Q0`/`0003P4`, and projected-stats state were updated; incremental stats reported no further row change; generated refresh was explicitly skipped.
- Command `000000019979`, timestamp `2026-07-30T11:33:42-04:00`, cwd `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md --apply --queue-timeout 240 --no-generated-refresh`; exit `0`, `ok: 1`; ten pre-existing `missing_ref_uid` warnings were reported in sequence for `0003P5`, `0003P6`, `0003P5`, `0003P6`, `0003P6`, `0003P5`, `0003P6`, `0003P6`, `0003P5`, `0003P6`. Validator-owned UID links for `0002H7`/`0002Q0` and projected-stats state were updated; incremental stats reported no further row change; generated refresh was explicitly skipped.
- Serial-validation result: all eight permitted scoped validators passed. No validator error remains. The listed missing-reference warnings pre-existed this callback and are unrelated to the accepted UID0003P4 changes. No generated refresh, coverage edit, IDA action, or lifecycle command was performed by B002.
- Supervisor command `000000019992`: by-memory coverage validation completed with exit `0`, `ok: 1`; only pre-existing `missing_ref_uid` warnings `00039L` and `0003T6` were reported; generated refresh completed. Current by-memory coverage identity is `82A918D06B56759FB52713751D1BD4E171379BBC4239229C5616168CB49F0C8E`, 2,108,263 bytes / 4,769 lines.
- Supervisor command `000000019993`: by-class coverage validation completed with exit `0`, `ok: 1`; generated refresh completed. Current by-class coverage identity is `396DAD20C73A2A54EAF045320B17ECA1FF877B02D36FF4CE204D4BA0D8D0A9E9`, 272,277 bytes / 625 lines. Generated Application.cpp is `739C98D2FFE9F0F9982796EA5C9219E3F09F45884FA9780774EB2AE1031B0C50`, 35,024 bytes / 901 lines, with one UID0003P4 contribution, one exact specialization marker, one binding, one callback definition, zero target empty markers, and no raw table definition. Tracker is `69EEECA87A63E245662EAC7CE72D3EA46C0C41712DC513FE8F805AFBA19F76FA`, 1,679,725 bytes / 6,634 lines, with UID0003P4 line 3323 at `92/94`, `true`, `0/0/0`.
- Filesystem-only poststate audit independently rehashed the four coverage artifacts, generated Application.cpp, tracker, current saved IDB, and exact prestate backup to the identities recorded above; reread exact coverage rows 2115/4262/4263 and class row 57; and confirmed the generated UID0003P4 marker/binding/definition topology. This audit made no external edit and invoked no validator, IDA, or lifecycle command.
- Post-Gate-2 report reconciliation result: no validator command was run by B002. This reconciliation changed only this report and records supervisor-supplied coverage/generated/IDA readback results.

## Changed Files

- Modified ordinary destination: `by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md`, pre `7C58B5F76939566CFED13F5A5C91D69EF894EBB1264DB4FD73BD694402C5F7C2` (6,161 bytes / 75 lines), post `37CEE1CE47127F6179980C08EBD4610C3ECE7030B799FD7755D406F4B51149D9` (11,227 / 99), validated by command `000000019972`.
- Modified ordinary destination: `by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md`, pre `2524FBEA3122A316C508E316484362E1F7F3E459924E170FC8DA3D0EDF75495E` (prior artifact), post `A3A1D67CB8E6D782C8AC119DF32AFB21E1613356D2B54DD89BCD1C1F0CD854CD` (23,183 bytes / 137 lines), validated by command `000000019973`.
- Modified ordinary destination: `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md`, pre `6F26EB4385BA587927FB26B5F5C96D8719A6A7E4F34A78D8D3E030BDEFB2592A` (prior artifact), post `800FFF00D1CF1CF48D6E7513AC94C7059425D1DA06BBBAD513B4D2D8D247C8F4` (35,249 bytes / 269 lines), validated by command `000000019974`.
- Modified ordinary destination: `by-class/BaramApp.md`, pre `41E1C2F484E536680EE8037FC23B7EF4A6D2A1CBC316316AFC87BF7D565730D1` (prior artifact), post `D1E2C70FBCD2AEAFDA3091FDAE5AE371E1124849D5A881604E40D609E74A0C6C` (53,489 bytes / 256 lines), validated by command `000000019975`.
- Modified ordinary destination: `by-file/Application.md`, pre `910F4FD4BB1354AC410A52AAB91990AF2328F19F5A9E7AE640D1608F8BB4547B` (prior artifact), post `99F4E990F1092F76DA520D5148ED0309F2FB84A01440F4157BEA8F6B08AC0E81` (160,411 bytes / 524 lines), validated by command `000000019976`.
- Modified ordinary destination: `by-type/by-template/FunctionObjectTemplates.md`, pre `4B88FCAC834B8682A0A564A4D083867E60759A7194D948D7824F77C32CF10255` (prior artifact), post `B4F7FEA76D72C598CF89854DBA0973E37F279349B20D0A044DC6EC72296E5AB6` (71,973 bytes / 545 lines), validated by command `000000019977`.
- Modified ordinary destination: `by-file/FunctionObjects.md`, pre `06326604CDB5E503445114C4642E50E663E07D09AEDF172BFC926E972161349A` (prior artifact), post `80B8650B2E4D41849475CD17F2C9C50825F159C092ADBEFE9F14430D5FDC650A` (77,899 bytes / 336 lines), validated by command `000000019978`.
- Modified ordinary destination: `by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md`, pre `FF2F5791A64A1021685DA2BD84976088AA25189E92FF43491884C6E30F5A0AC7` (prior artifact), post `E481F144156119D01758A80BD0CD8DA58DB59B028529D7DBB50FE99D7DBFF034` (21,926 bytes / 142 lines), validated by command `000000019979`.
- Modified report: `tools/leaser/Agents/Agent-B002/research/0003P4-BaramAppCallbackVtableData-source-quality.md`; exact final identity is reported to the supervisor after final reconciliation and lease release.
- Currentness reread found all eight ordinary post-callback identities unchanged from the exact hashes above. Supervisor-modified current manual coverage identities are by-memory `82A918D06B56759FB52713751D1BD4E171379BBC4239229C5616168CB49F0C8E` (2,108,263 bytes / 4,769 lines) and by-class `396DAD20C73A2A54EAF045320B17ECA1FF877B02D36FF4CE204D4BA0D8D0A9E9` (272,277 / 625); by-file `736B2900338FDFE34C44CD18CF9DF0C7791820D28D42DAB7B5E9DD0691EB6BFE` (162,964 / 317) and by-type/by-vtable `D68E24B090F48570D17727658EE3020292D544C0866DFE1D1CB784EECB6E9571` (67,386 / 146) remained exact no-ops. B002 did not edit coverage files.
- Supervisor Gate 2B modified and saved IDA from backed-up prestate `D7D29DEB8CDA07A6693B36BEF32A544ABD1921D3A0C9B306A47DFCC350D08CCA` (143,194,156 bytes; backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B002-UID0003P4-20260730_120046.i64`) to current `836ABCFA986AF47A3CAC9EC1D46A31BE6B9B29DA83B6BCA797E7817F2CCF489F` (143,194,721 bytes, saved `2026-07-30T12:01:56.5937670-04:00`); all 11 actions are applied/verified, protected state is no-change verified, and post-save health/readback passed. B002 did not mutate or save IDA.
- Supervisor/validator modified by-memory coverage, by-class coverage, generated Application.cpp `739C98D2FFE9F0F9982796EA5C9219E3F09F45884FA9780774EB2AE1031B0C50` (35,024 / 901), tracker `69EEECA87A63E245662EAC7CE72D3EA46C0C41712DC513FE8F805AFBA19F76FA` (1,679,725 / 6,634), and saved IDB exactly as recorded. By-file/by-vtable coverage, all eight ordinary artifacts, and lifecycle artifacts were unchanged by this reconciliation.
- Renamed by supervisor in IDA: `sub_4F5F50` to `BaramApp__OpenTerminalPaneAfterStartupLogo`; no filesystem file rename occurred. B002 modified only this report during the current reconciliation.
- Report lifecycle boundary: execution/archive status is supervisor-owned and authoritative only from the current report path plus validator-owned status/history metadata. B002 did not run/probe `execute_report` or any equivalent lifecycle command.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Exact Gate-1 artifact `896BFEAB8F1286383FBE093EDDBFB67601D2C96EB51B11B5779FDE3F8C114B1B` was supervisor-accepted before implementation.
- [x] UID0003P4 target metadata, marker, Item Summary, exact layout/RTTI/reachability/source-decision evidence, score rationale, and historical assumptions are updated.
- [x] UID0002Q0 score/source-name/access/header/source placement is updated while its exact CPP body and justified blank H are preserved.
- [x] UID0002H7 callback evidence/caveat is updated without changing its formal source or score.
- [x] BaramApp class score, child matrix, source decision, score rationale, and historicalized callback caveats are updated while unrelated broad class blockers remain.
- [x] Application file route records the Application.h declaration/Application.cpp definition/binding.
- [x] FunctionObjectTemplates records the exact BaramApp specialization and 24-byte layout.
- [x] FunctionObjects file inventory records the concrete specialization/table/body/binding source split.
- [x] UID00025P exact child evidence is updated while ownerless/non-reconstructable/non-emitting metadata and score remain unchanged.
- [x] Every declared target UID has target-specific evidence, recommendation, ledger destinations, and validation; no additional target UID is declared.
- [x] Target score `86/91 -> 92/94`, UID0002Q0 `90/92 -> 92/94`, and BaramApp `86/90 -> 87/91` are applied; all other listed support scores remain unchanged.
- [x] Target owner/emitter/reconstructable metadata `00000V/00000V/TRUE` and parent `NONE/blank/FALSE` are preserved.
- [x] No split/merge/new child/reclassification is needed.
- [x] Exact target CPP marker is applied and target H remains blank with exact no-header proof.
- [x] UID0002Q0 body is preserved and its H remains blank until a complete BaramApp class H exists; no orphan declaration was generated.
- [x] All report-level evidence-time IDB, positive/negative evidence, rejected alternatives, and source-placement details are incorporated without summarizing them away.
- [x] Old B009/B013 `86/91`/unresolved-spelling/source-split assumptions are historicalized rather than deleted.
- [x] Supervisor Gate 2B independently applied/verified I3P4-001 through I3P4-011, reread protected functions/fences with no change, saved once, and passed post-save readback/health under `836ABCFA...CCF489F`.
- [x] Supervisor applied/verified exact current manual UID00025P line 4262, UID0003P4 line 4263, UID0002Q0 line 2115, and BaramApp line 57 rows; B002 did not edit coverage files.
- [x] Scoped validators ran serially for every changed ordinary by-* file with `--apply --queue-timeout 240 --no-generated-refresh`; exact command IDs/timestamps/results/warnings/side effects are recorded.
- [x] Commands `000000019933`/line 1724 and `000000019928`/line 1725 are preserved as dated pre-callback/assignment evidence only; command19993 refreshed tracker state to UID0003P4 line 3323 `92/94`, `true`, `0/0/0` without making lifecycle assertions.
- [x] Command19993 generated Application.cpp was verified to contain exactly one UID0003P4 contribution, one exact specialization marker, one callback binding, one callback definition, zero target empty markers, and no raw table definition.
- [x] Third-party import is not applicable.
- [x] Wave2/Wave3 material remains ignored.
- [x] Zero in-scope target research questions remain after implementation.
- [x] Report body remains lifecycle-neutral and report execution/archive movement remains supervisor-owned.

Implementation callback pass:
- [x] Supervisor-owned IDA changes are applied/verified by Gate 2B; B002 did not mutate/save IDA.
- [x] Exact report artifact was accepted by the supervisor for this implementation callback.
- [x] All accepted ordinary target/support details are incorporated at full report detail.
- [x] Every ledger claim is reconciled to `applied` or `already-present`; 38 are applied, six already present, and zero blocked.
- [x] Every changed ordinary doc was rehashed and independently checked against its claim destinations after all eight validators.
- [x] Metadata/score/owner/emitter/CPP/H changes are applied exactly.
- [x] Historical assumptions and negative evidence are preserved.
- [x] Validator provenance records ordinary generated-refresh skips plus supervisor commands19992/19993 and their completed generated refresh state.
- [x] Re-read all eight ordinary identities with no drift; current by-memory/by-class rows are applied/verified and by-file/by-vtable remain exact no-ops.
- [x] Preserved IDB `D7D29DEB...D08CCA` and `3892BDA8...798D1` as dated history; recorded current saved `836ABCFA...CCF489F`, all 11 applied/verified rows, protected no-change readback, backup, save, and health proof.
- [x] Manual supervisor-owned coverage operations and generated topology are independently verified.
- [x] No accepted item remains unapplied or blocked; report lifecycle authority remains external.
- [x] Report remains lifecycle-neutral and contains exactly one terminal readiness marker appropriate to its current phase.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000019995","destination_path":"executed-b-agent-research/B002/0003P4-BaramAppCallbackVtableData-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0003P4-BaramAppCallbackVtableData-source-quality.md","timestamp":"2026-07-30T12:17:30-04:00","uid":"0003P4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
