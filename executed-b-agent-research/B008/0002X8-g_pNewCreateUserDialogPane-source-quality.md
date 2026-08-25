** TARGET-REPORT-UID:0002X8 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002X8 g_pNewCreateUserDialogPane Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation and ordinary-document result: treat `[0x0069b4a8,0x0069b4ac)` as exact loader-zeroed physical storage for the externally linked `NewCreateUserDialogPane *g_pNewCreateUserDialogPane` singleton. Semantic ownership remains [UID:0002X7], while physical [UID:0002X8] is now non-reconstructable and non-emitting so it cannot define the same source object twice.
- Final ordinary disposition: [UID:0002X8] is `92/94`, `CANONICAL_OWNER:0002X7`, `RECONSTRUCTABLE:FALSE`, with blank `EMITTER_UIDS`, blank position, and blank CPP/H. Semantic global [UID:0002X7] is the sole definition emitter at source position `0` under [UID:0000LP].
- Accepted callback and post-IDA reconciliation result: the exact storage, PE loader-zero, six-reference lifecycle, direct Singleton RTTI/PMD, one-definition route, class inheritance/header correction, source placement, historical correction, and support cross-links are incorporated at report-level detail in all eight ordinary destinations. Supervisor Gate 2B catalog entry `0362` is applied and verified, and the ordinary destinations now record its exact saved-IDB poststate. Supervisor commands `000000019755` through `000000019758` applied and verified all eight manual coverage rows, and command `000000019759` completed generated closure. Report execution/archive truth remains supervisor-owned external state.
- Confidence: very strong for physical range/value/type/lifetime/owner/emitter/source placement and direct Singleton inheritance; strong for the inferred original global spelling and lexical `= 0` initializer.
- Research-scope statement: the initial report-only pass modified no external project file. The later accepted implementation callback modified and serially validated exactly eight ordinary by-* destinations; it did not edit generated files, manual coverage, IDA, supervisor state, goal/notes, or report lifecycle state.

## Supporting Research

- Assignment source: Agent-B008 `goal.md`, [UID:0002X8], queue row `87/90` in `auto-generated/-ag-research-tracker.md` command `000000018895`.
- Current dedicated-report screen: no earlier B-agent report declares [UID:0002X8] as its primary or additional target. Earlier reports for [UID:0002QS], [UID:0002SJ], [UID:0002X4], [UID:0002XN], [UID:00019J], and [UID:0001CR] are support evidence, not direct report coverage of this exact slot.
- Direct analogues: [UID:0002X4] `g_pNewUserDialogPane2` and [UID:0002XN] `g_pServerSelectPane` already establish the accepted physical-non-emitting versus semantic-global-emitting pattern for adjacent direct-Singleton storage.
- Lifecycle boundary: execution/archive state is supervisor-owned and authoritative only from this report's current path plus validator-owned status/history metadata. At initial creation there was no earlier execution, invalidation, repair, implementation callback, or archive history; that is dated creation context, not a continuing lifecycle claim.
- Historical repair-cycle facts: command `000000019760` executed an unreconciled artifact, the mandatory post-move audit rejected its stale manual-coverage prose, and command `000000019761` returned that artifact to this active path for same-report repair. These events are history only; the current lifecycle state is never inferred from ordinary report prose.
- Live evidence was read through healthy IDA MCP database session `1da2b2ae`; all B008 calls used read-only tools. Dated historical physical-IDB observations at `E:/NTK/Resources/NexusTK/NexusTK.exe.i64` include SHA256 `02A07727AC1E8B20003B82FA1005E89D96EAA5F1448823A0764687D65F74DBB5`, 143,191,086 bytes, last write `2026-07-29T09:42:53.7294878-04:00`; SHA256 `2823AB8A51B713C9D5B98093169C692D185F2DCEDEB2F283495DD48A9269F4C3`, 143,191,086 bytes, last write `2026-07-29T09:50:10.1520178-04:00`; SHA256 `08D31FD1C7B80721D6CD7774B42C5A5157B3A4683670A3E27EA5660290554F5A`, 143,190,452 bytes, last write `2026-07-29T12:53:48.4762005-04:00`; SHA256 `03F10207763C01455EA5F767F330A371FEDD9885FBFD98705F5A486985DBE5DA`, 143,190,601 bytes, last write `2026-07-29T13:03:43.9987735-04:00`; pre-catalog-0362 SHA256 `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481`, 143,190,636 bytes, last write `2026-07-29T13:59:50.1387219-04:00`; catalog-0362 action-time save SHA256 `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, 143,191,631 bytes, saved `2026-07-29T14:12:44.7229687-04:00`; post-catalog no-drift checkpoint SHA256 `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, 143,190,676 bytes, last write `2026-07-29T14:22:15.9735862-04:00`; later no-drift checkpoint SHA256 `905D1AB131C953911CD1DF5E536AF36EAECFA67486E2F800907B36C0673604C1`, 143,190,814 bytes, saved `2026-07-29T14:42:53.5091352-04:00`; and then-current checkpoint SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, 143,191,140 bytes, saved `2026-07-29T15:00:32.0998001-04:00`. The `0E0AF938...AB481` artifact is the historical A00-A03 pre-action state preserved by backup `E:/NTK/Resources/NexusTK/backups/NexusTK.exe.pre-B008-UID0002X8-20260729-1412.i64`; `3C8F3178...25B69` remains the catalog action-time save, while `296ED21C...63CF8B`, `905D1AB1...604C1`, and `412DA7E8...519CD` are dated later checkpoints. The bounded final no-drift readback used the same healthy MCP session against current authoritative saved IDB SHA256 `EEF0C80D8E7E886A573FF7FB93D8BAFEE332FF26C34A7243F7CB9AB3A4A7997B`, 143,192,422 bytes, saved `2026-07-29T16:24:30.9010410-04:00`. Current readback is one exact size-four `is_data:true` `NewCreateUserDialogPane *g_pNewCreateUserDialogPane` item with both accepted comments and an incomplete no-layout ordinal-949 class type; bytes/xrefs, both neighbors, all six protected RTTI dependencies, and the five lifecycle-function/raw identities remain exact.

## Target

- Target UID: `0002X8`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md`, exact four-byte physical singleton slot and sole report target.
- Target path: `source-3/project-documentation/by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md`.
- Source queue/report row: assignment-time tracker line 1805, `87/90`, combined `88.5`, reconstructable `true`, zero direct/additional report counts at command `000000018895`. Callback-time command `000000019228` remained at pre-callback `87/90` because all eight authorized callback validators used `--no-generated-refresh`; that is historical. Command `000000019759` completed generated closure. The later lifecycle refresh at command `000000019761`, `2026-07-29T16:13:57-04:00`, is the current shared tracker observation: SHA256 `D0FC00F7CA525A658CFBFCE08E95ECA13B07E9120B5DDE73B401DA23BB4FDD7F`, 1,677,700 bytes/6,632 lines, with UID0002X8 at line 5518 as `92/94`, combined `93.0`, reconstructable `false`; report-count/lifecycle fields remain path/validator-history owned.
- Gate handoff classification: initial report-only Gate 1 was accepted, the ordinary-document callback is physically complete, and supervisor Gate 2B catalog entry `0362` is applied/verified with poststate reconciled into all eight ordinary destinations. Commands `000000019755` through `000000019758` applied and validated all eight manual coverage rows, and command `000000019759` refreshed and physically verified generated coverage/CPP/H/topology. Execution, invalidation, and archive disposition remain external supervisor/validator state.
- Current scores and parent state after callback readback: target `92/94`, owner [UID:0002X7], false/non-emitting, blank formal CPP/H; semantic global [UID:0002X7] `92/94`, owner/emitter [UID:0000LP], position `0`, exact CPP and blank H; class [UID:00008Z] `90/92`, owner/emitter [UID:0000LP], position `10`, blank CPP and exact H; file [UID:0000LP] `89/92`; aggregate [UID:00029W] `92/94`, parentless and non-reconstructable. Support metadata remains UID0002QS `88/91`, UID0002SJ `88/92` false/non-emitting, and UID0002QU `88/90` false/non-emitting.

## Current Target State

- Current ordinary metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0002X7`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, blank CPP/H, `Nested:0`.
- Current ordinary owner/emitter/reconstructable state: semantic ownership remains correct and the duplicate physical emitter is removed. The target now records loader-zero storage and routes the one source definition solely through semantic UID0002X7.
- Current ordinary C++/emitter state: target CPP/H are blank; UID0002X7 carries the exact position-0 CPP definition; UID00008Z carries the exact position-10 H class/extern declaration and blank CPP. Every B008 callback validator deliberately disabled generated refresh, but later supervisor command `000000019759` physically confirmed the accepted generated CPP/H topology without making that refresh a B008 action.
- Current shared-artifact closure: supervisor commands `000000019755` through `000000019758` installed and validated all eight exact manual coverage rows; command `000000019759` refreshed generated memory coverage, CPP, H, registry, and tracker topology; command `000000019761` later refreshed only lifecycle-owned tracker state when returning this same artifact for prose repair. Both closure scopes are complete.
- Historical pre-callback defects now corrected in ordinary docs: raw `dword_69B4A8` current wording, missing loader-zero PE geometry, omitted direct Singleton RTTI/PMD, absent zero-interior-ref/one-definition evidence, class declaration in CPP, missing direct Singleton base, provisional aggregate wording, and missing core/vtable/lifecycle cross-links. Historical IDB `0E0AF938...AB481` exposes the literal A00-A03 pre-action state; catalog checkpoint `3C8F3178...25B69` records the applied action; dated checkpoints `296ED21C...3CF8B`, `905D1AB1...604C1`, and `412DA7E8...519CD`, followed by current authoritative IDB `EEF0C80D...A7997B`, confirm the applied A00/A01 state, protected A02/A03 state, verified unchanged RTTI dependencies, and unchanged lifecycle-function identities from catalog entry `0362` without later target drift.
- Related target/support docs checked: [UID:0002X7], [UID:00008Z], [UID:0000LP], [UID:00029W], [UID:0002QS], [UID:0002SJ], [UID:0002QU], [UID:00019J], sibling [UID:0002X4], and sibling [UID:0002XN].
- Artifact/lifecycle authority: ordinary callback completion is recorded as an applied historical/current ordinary-document fact, while execution/archive truth remains external and authoritative only from the artifact's actual path plus validator-owned status/history metadata at the time of inspection.

## Executive Recommendation

- Direct semantic owner: [UID:0002X7] `g_pNewCreateUserDialogPane`.
- Source owner: [UID:0000LP] `NexusTK/login/NewCreateUserDialogPane.cpp`, with header output coordinated through [UID:00008Z].
- Physical target disposition: preserve the exact by-memory page for address/storage/lifecycle evidence, but set `RECONSTRUCTABLE:FALSE`, clear its emitter route, and keep both formal blocks blank.
- Semantic global disposition: define exactly one external-linkage `NewCreateUserDialogPane *g_pNewCreateUserDialogPane = 0;` at source position `0`.
- Class disposition now applied in ordinary docs: the class declaration is in H with direct `Singleton<NewCreateUserDialogPane>` inheritance and the one matching `extern`; class CPP is blank. Constructor source initializes the Singleton base rather than containing a handwritten global assignment.
- Aggregate disposition: keep [UID:00029W] parentless/non-emitting; remove its statement that UID0002X8 spelling/grouping remains unresolved.
- No blocked owner, split, IDA, manual-coverage, or generated-closure action remains. Catalog entry `0362` closes the accepted IDA action without changing source ownership or emission; commands `000000019755` through `000000019759` close the manual coverage and generated topology. Report lifecycle remains supervisor-owned.

## Supervisor Active Recheck

- Assignment instruction (historical creation context): begin the assigned report-only research from the B008 goal, use the literal template, edit only this report, stop if live IDA MCP reads fail, and finish with one Gate 1 handoff marker.
- Split repair: no new split is required. `[0x0069b4a8,0x0069b4ac)` is already the exact child of mixed-owner aggregate [UID:00029W].
- Source-bearing children: the physical target is not itself source-bearing after one-definition analysis. Semantic global [UID:0002X7], class [UID:00008Z], file [UID:0000LP], exact method child [UID:0002QS], and compiler vtable/lifecycle support are all identified with exact dispositions.
- MCP availability: healthy throughout required reads; no unavailable-call stop condition occurred.

## Inference Research Guidance Check

- `by-structure.md` requires physical binary evidence and source semantics to be separated. The physical slot remains documented, while the source declaration/definition is emitted once through its semantic by-global page.
- Existing documentation assumptions were not treated as authority. The raw `dword_69B4A8`, reconstructable physical emitter, omitted Singleton base, CPP-channel class declaration, and historical `0xffffffff` initializer were rechecked independently.
- Direct IDA facts: bytes, item heads, comments, xrefs, disassembly, RTTI names/records, PMD, function boundaries, the current incomplete no-layout ordinal-949 type, and generated names.
- Documentation evidence: source family, direct owner UIDs, existing method/vtable maps, neighboring accepted singleton treatments, and dated generated-topology checkpoints.
- Inference: `g_pNewCreateUserDialogPane`, external linkage, `= 0`, source position `0`, and the exact human header arrangement. Each is anchored by same-family accepted source and cross-translation-unit use.
- Wave2/Wave3: stale mentions were ignored. No current conclusion relies on either system.

## Heuristic / Inference Reanalysis And Validation

- Global name: `g_pNewCreateUserDialogPane` is the best source-facing name. It matches the class name, project-wide `g_p...` active-pane convention, existing semantic page, main-menu C++, and adjacent accepted singleton names. `unk_69B4A8` and `dword_69B4A8` are rejected as binary-analysis aliases.
- Type: `NewCreateUserDialogPane *` is strongly supported by constructor publication, three class vtable stores, direct Singleton RTTI, destructor clear, and consumer use. `void *`, integer, byte array, or untyped dword interpretations are rejected.
- Initialization: explicit zero is required semantically. PE arithmetic proves the address has no raw backing, and the image has no relocation route that can supply a nonzero initializer. `0xffffffff` is impossible as a static-image value for this slot.
- Lexical initializer: `= 0` is selected over `NULL` or implicit zero because the same create-user family already emits `NewUserDialogPane2 *g_pNewUserDialogPane2 = 0;`. All three are binary-equivalent, but family-local source consistency makes `0` the strongest current reconstruction.
- Linkage: external linkage is required because `MainMenuPane.cpp` consumes the object while `NewCreateUserDialogPane.cpp` owns its lifetime. File-local `static` and class-static alternatives are rejected.
- Direct Singleton base: decorated RTTI names `Singleton<NewCreateUserDialogPane>` and its base descriptor records PMD `620/-1/0`. Constructor instructions form `this+0x26c`, subtract `0x26c`, and publish the complete pointer. The class declaration must include the direct base.
- Explicit publication source: rejected. The observed store is template base-constructor lowering. Human source initializes `Singleton<NewCreateUserDialogPane>()`; it does not copy the decompiler's global assignment.
- Helper identities: `sub_52F720` is source-facing Singleton clear/destructor lowering; `sub_52F870` is the MSVC scalar deleting destructor; raw `0x0052cd7a` is constructor unwind cleanup. They are compiler/lifecycle evidence, not handwritten free functions to emit.
- Constructor reachability: current xrefs and fresh PE absolute/RVA/direct-E8/E9 scans all return zero for `0x0052c360`. This remains retained-code evidence for the class/file, not a storage type, name, owner, or emission blocker.
- Complete class UDT: current IDA contains the accepted incomplete no-layout ordinal-949 `NewCreateUserDialogPane` declaration, but no complete `NewCreateUserDialogPane` UDT/layout. A full guessed UDT remains unnecessary and unsafe for this global; the incomplete forward type is sufficient for the pointer item.
- Physical versus semantic emission: physical [UID:0002X8] must be non-emitting, semantic [UID:0002X7] must be the sole global emitter, and class [UID:00008Z] must carry header class/extern source. Duplicate physical output is rejected.
- Source placement: `NexusTK/login/NewCreateUserDialogPane.cpp` is strongly supported by exact method owner, file page, create-user resources, class/vtable grouping, and adjacent variant layout.
- Remaining uncertainty: exact original lexical global spelling and `0` token cannot be proven without symbols/source, and direct constructor reachability remains absent. Neither uncertainty makes a raw label acceptable or blocks the source-quality recommendation.

## Evidence Standards Used

- Evidence types: IDA MCP health, `idb_list`, bytes, item inspection, comments, names/globals, types, xrefs, function lookup/analysis, disassembly, rendered-listing search, RTTI/type descriptor records, raw PE section parsing, relocation-directory parsing, direct branch/pointer scans, by-* documentation, executed support research, generated C++/tracker reports, and manual coverage rows.
- Strongest evidence: exact address storage and six xrefs agree across byte, item, xref, disassembly, and old/new documentation; RTTI PMD and constructor lowering independently agree on the direct Singleton base and pointer type.
- Storage/section role: the slot lies in the virtual tail of writable `.data` but outside raw backing, so loader-zero is authoritative.
- Tool limitation: IDA currently contains only an incomplete no-layout `NewCreateUserDialogPane` type. That correctly limits full-layout claims while supporting the exact pointer type and normalized four-byte storage; no complete UDT layout is claimed.
- Confidence remains below 95 because original source tokens and direct constructor reachability are unavailable, and 95+ requires extreme final-audit proof.

## Evidence Checked

- IDA MCP reads: healthy active database session `1da2b2ae`; bytes at `0x0069b4a0-0x0069b4b8`; item heads at target and neighbors; current comments; names/globals; direct type inspection/query; exact target and interior xrefs; constructor xrefs; function lookup for `0x004f69a0`, `0x0052c360`, `0x0052cd7a`, `0x0052f720`, and `0x0052f870`; RTTI names, bytes, and comments at `0x0064c858-0x0064c8a8` and `0x00677f68-0x00677fe0`. Readbacks through SHA256 `03F10207...B5DA`, pre-action SHA256 `0E0AF938...AB481`, catalog action-time SHA256 `3C8F3178...25B69`, and later SHA256 values `296ED21C...63CF8B`, `905D1AB1...604C1`, and `412DA7E8...519CD` are dated historical checkpoints. The historical `0E0AF938...AB481` pre-action readback found A00 absent and A01 as four one-byte undefined partitions with `unk_69B4A8` only at the first byte, blank types, blank address-regular and address-repeatable comments, six start xrefs, zero interior xrefs, and zero bytes. The bounded final readback against current authoritative saved IDB SHA256 `EEF0C80D8E7E886A573FF7FB93D8BAFEE332FF26C34A7243F7CB9AB3A4A7997B`, 143,192,422 bytes, saved `2026-07-29T16:24:30.9010410-04:00`, confirms A00 as ordinal `949`, an incomplete no-layout `NewCreateUserDialogPane` type, while `DialogPane` remains ordinal `471`, size `620`, with seven members. A01 remains one four-byte `is_data:true` item named `g_pNewCreateUserDialogPane`, typed `NewCreateUserDialogPane *`, with both exact accepted comments, six start xrefs, zero interior xrefs, and zero bytes. A02/A03 remain the protected `g_pNewUserDialogPane2`/`NewUserDialogPane2 *` and `g_pServerSelectPane`/`ServerSelectPane *` neighbors with blank address-regular and address-repeatable comments and zero bytes. The six protected RTTI dependency names/bytes/comments, PMD `620/-1/0`, attributes `0x40`, and five lifecycle-function/raw identities with blank comments remain exact.
- Raw PE checks: clone executable `C:/Users/admin/Desktop/Clone/NexusTK/NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, 2,679,296 bytes; PE32 image base, section table, relocation directory, raw/virtual target placement, absolute/RVA pointer patterns, and direct E8/E9 targets.
- Final current-IDB physical readback of all eight ordinary destinations: target SHA256 `E7A3423B0CFCBDB742A077BAE3E13D925657F8915786C79883C0AF447D3ED77F` (14,650 bytes/119 lines); global `C64F34AC6F73850855CCF5A5D399F536C8BDCB37EA8BB239BCE83998D7DF8726` (12,229/100); class `CCA7F289505EEE171060C29F9865F4C982579309EC52FD2F62FC18B25E1E252B` (21,880/165); file `710D5C872CD945E1AD276A89335D8C19CF9E9871A51CBB55AEEE9A1FF77CF113` (19,467/130); aggregate `6AC40B148C1DF29D6206081CD8369DA13EAA3DAD768CD333B25F0E1E45D186CC` (27,130/163); core `3FEEF5746F75D37607A052FC5288A4B452E84835684AB022E0A24007DFC4448D` (30,372/292); vtable data `67121D0BF24DEC1A34926459DEF2FE6C0E9EC4C01153030EBAA6B03D28B2DBE2` (20,599/134); lifecycle island `ED40C250321AA4B237D739317B3979287D6E4716B35B58E4384F6D2B544ED6A5` (27,254/177). These hashes were computed only after the final serial validator and lease release for each file.
- Historical pre-callback ordinary hashes were target `79D1589F...5ABA`, global `CEAB9A90...E01D`, class `257B1D60...F0DE`, file `D22128E9...BC0F`, aggregate `24A5826E...C348`, core `422B611D...E49C`, vtable `2637FBAE...7208`, and lifecycle `FB23E4BE...8981`; they are retained as dated research evidence, not current destination identities. Additional read-only support hashes retained: main-menu helper `618F9840...BA839`; adjacent physical pages `07401ADC...4712` and `3B3FC9CE...2001B`.
- Generated/shared-artifact checks: assignment tracker command `000000018895`; historical pre-callback generated memory coverage/CPP command `000000019221`; historical callback-time tracker command `000000019228`; supervisor manual-coverage commands `000000019755` through `000000019758`; generated-closure command `000000019759` for memory coverage and `NewCreateUserDialogPane.cpp/.h`; and lifecycle command `000000019761` for the current shared tracker. Current final coverage hashes are by-memory `EF11866142A27984E6904BBA1222FB4E0102E7073123A26237791065B43FC795`, by-global `522E9096367E7CC1878682E3ECA2275334073EDBECC02C555441D2C5144328E0`, by-class `2211261E2A7CBD83E7C63B4A63B184EF4F25B12D914C6284D887D1D4413D7F4F`, and by-file `725EBCE55E0FE27347012E27CB888BEB2A49F0E7AFCB72603FDA97967D583770`; all eight exact rows are installed. Commands `000000019063`/`000000019064`/`000000019068`/`000000019078`/`000000019152`/`000000019153`/`000000019201`/`000000019259` remain explicitly historical checkpoints.
- Negative checks: zero target interior xrefs; zero constructor-start xrefs; zero absolute-VA, RVA, or direct E8/E9 route to `0x0052c360`; no complete local `NewCreateUserDialogPane` layout; no duplicate name collision before or after the exact target naming action; no raw target backing; zero base-relocation directory.
- Failed/unavailable checks: none. B008 made no IDA mutation or report-lifecycle action. The accepted ordinary callback and post-IDA reconciliation used only the authorized serial scoped ordinary-file validators listed below, with generated refresh disabled; supervisor catalog entry `0362`, not B008, performed and saved the IDA action.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | 0002X8 | Summary records the exact range `[0x0069b4a8,0x0069b4ac)` and zero value. | confirmed | MCP bytes/items/value readback. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Summary | incorporate | applied |
| C002 | 0002X8 | Evidence records exact bytes `00 00 00 00` for the four-byte target. | confirmed | MCP bytes/items/value readback. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Evidence | incorporate | applied |
| C003 | 0002X8 | Target RVA `0x29b4a8` is `0x2e4a8` into `.data`, beyond raw size `0xd800` by `0x20ca8`. | confirmed | Parsed PE section table. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Loader-Zero And Relocation Proof | incorporate | applied |
| C004 | 0002X8 | No raw initializer or relocation can encode `0xffffffff`; loader supplies zero. | confirmed | No raw backing, base-relocation RVA/size zero, no `.reloc`. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Loader-Zero And Relocation Proof | incorporate | applied |
| C005 | 0002X8 | Evidence historicalizes the four one-byte undefined heads and records the current four-byte typed/named item. | confirmed | Historical `0E0AF938...AB481` prestate, catalog entry `0362`, dated checkpoints through `412DA7E8...519CD`, and current `EEF0C80D...A7997B` readback. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Evidence | historicalize | applied |
| C006 | 0002X8 | IDA handoff records the exact catalog-0362 name, type, regular comment, repeatable comment, and no-drift readback. | confirmed | Catalog entry `0362`, dated `296ED21C...3CF8B`/`905D1AB1...604C1`/`412DA7E8...519CD` checkpoints, and current `EEF0C80D...A7997B` readback. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / IDA Handoff | historicalize | applied |
| C007 | 0002X8 | Exact lifecycle inventory records six refs at the target start and zero refs at all interior bytes. | confirmed | MCP xref query. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Exact Lifecycle Inventory | incorporate | applied |
| C008 | 0002X8 | Boundary evidence records zero interior refs so no neighboring storage can be absorbed into the target. | confirmed | MCP xref query and exact item boundaries. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Boundaries And Protected Neighbors | incorporate | applied |
| C009 | 0002X8 | `0x004f6a13` is the main-menu cleanup read selected when `g_useEpfAssets` is true. | confirmed | Decompile/disassembly and UID00019J. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Exact Lifecycle Inventory | incorporate | applied |
| C010 | 0002X8 | Constructor `0x0052c360` publishes complete `this` at `0x0052c3b8`. | confirmed | Constructor disassembly. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Exact Lifecycle Inventory | incorporate | applied |
| C011 | 0002X8 | Constructor null/fallback path clears the slot at `0x0052c3bf`. | confirmed | Constructor disassembly. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Exact Lifecycle Inventory | incorporate | applied |
| C012 | 0002X8 | Raw constructor-unwind code clears the slot at `0x0052cd7a`. | strong | Rendered listing, item/bytes, lifecycle family. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Exact Lifecycle Inventory | incorporate | applied |
| C013 | 0002X8 | Tiny helper `0x0052f720-0x0052f72b` clears the slot. | confirmed | Analyze/decompile/xref. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Exact Lifecycle Inventory | incorporate | applied |
| C014 | 0002X8 | Scalar deleting destructor `0x0052f870` clears the slot at `0x0052f89d`. | confirmed | Analyze/decompile/disassembly. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Exact Lifecycle Inventory | incorporate | applied |
| C015 | 0002X8 | RTTI directly names `Singleton<NewCreateUserDialogPane>`. | confirmed | Decorated names/type descriptors. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Direct Singleton Source Cause | incorporate | applied |
| C016 | 00008Z | RTTI directly names `Singleton<NewCreateUserDialogPane>`. | confirmed | Decorated names/type descriptors. | [UID:00008Z] `by-class/NewCreateUserDialogPane.md` / Direct Singleton And Header Contract | incorporate | applied |
| C017 | 0002X8 | Singleton base descriptor PMD is `620/-1/0` and attributes `0x40`. | confirmed | Raw descriptor dwords at `0x0064c874`. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Direct Singleton Source Cause | incorporate | applied |
| C018 | 00008Z | Singleton base descriptor PMD is `620/-1/0` and attributes `0x40`. | confirmed | Raw descriptor dwords at `0x0064c874`. | [UID:00008Z] `by-class/NewCreateUserDialogPane.md` / Direct Singleton And Header Contract | incorporate | applied |
| C019 | 0002X8 | Constructor `this+0x26c` then `-0x26c` sequence is direct Singleton base-constructor lowering. | very strong | Exact instructions `0x0052c3a1-0x0052c3bf`. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Direct Singleton Source Cause | incorporate | applied |
| C020 | 0002X8 | Summary uses source type/name `NewCreateUserDialogPane *g_pNewCreateUserDialogPane`. | very strong | RTTI, vtables, lifetime, project convention. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Summary | incorporate | applied |
| C021 | 0002X8 | Source disposition identifies `NewCreateUserDialogPane *g_pNewCreateUserDialogPane` while keeping the physical page non-emitting. | very strong | RTTI, lifetime, one-definition rule, sibling convention. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Source And Generated Disposition | incorporate | applied |
| C022 | 0002X7 | Global role identifies the semantic object as `NewCreateUserDialogPane *g_pNewCreateUserDialogPane`. | very strong | RTTI, vtables, lifetime, project convention. | [UID:0002X7] `by-global/g_pNewCreateUserDialogPane.md` / Role | incorporate | applied |
| C023 | 0002X7 | Source definition contract uses the source type/name `NewCreateUserDialogPane *g_pNewCreateUserDialogPane`. | very strong | RTTI, lifetime, source-owner convention. | [UID:0002X7] `by-global/g_pNewCreateUserDialogPane.md` / Source Definition And Header Contract | incorporate | applied |
| C024 | 00008Z | Header contract uses `NewCreateUserDialogPane` and extern `g_pNewCreateUserDialogPane`. | very strong | RTTI, vtables, lifetime, project convention. | [UID:00008Z] `by-class/NewCreateUserDialogPane.md` / Direct Singleton And Header Contract | incorporate | applied |
| C025 | 00008Z | Singleton storage evidence identifies the source object as `NewCreateUserDialogPane *g_pNewCreateUserDialogPane`. | very strong | RTTI, lifetime, publication/clear sites. | [UID:00008Z] `by-class/NewCreateUserDialogPane.md` / Singleton Storage And Lifecycle Evidence | incorporate | applied |
| C026 | 0000LP | File evidence identifies the source object as `NewCreateUserDialogPane *g_pNewCreateUserDialogPane`. | very strong | RTTI, vtables, lifetime, project convention. | [UID:0000LP] `by-file/NewCreateUserDialogPane.md` / Evidence Notes | incorporate | applied |
| C027 | 0000LP | Source output topology places `NewCreateUserDialogPane *g_pNewCreateUserDialogPane` in the file-owned output. | very strong | One-definition route and file ownership. | [UID:0000LP] `by-file/NewCreateUserDialogPane.md` / Source Output Topology | incorporate | applied |
| C028 | 0002X8 | Physical target is false/non-emitting with blank CPP/H. | very strong | One-definition rule and accepted sibling topology. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Source And Generated Disposition | incorporate | applied |
| C029 | 0002X8 | Ownership routes semantic emission to UID0002X7 and leaves the physical page non-emitting. | very strong | One-definition rule and accepted sibling topology. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Ownership Decision | incorporate | applied |
| C030 | 0002X7 | Semantic [UID:0002X7] is sole global emitter under [UID:0000LP] at position `0`. | very strong | Cross-TU consumer and source owner. | [UID:0002X7] `by-global/g_pNewCreateUserDialogPane.md` / Ownership Decision | incorporate | applied |
| C031 | 0002X7 | Exact global CPP definition uses forward declaration and `= 0`. | strong | Same-family UID0002X3 output and C++03 source shape. | [UID:0002X7] `by-global/g_pNewCreateUserDialogPane.md` / Source Definition And Header Contract | incorporate | applied |
| C032 | 00008Z | H declaration includes direct `Singleton<NewCreateUserDialogPane>` inheritance and the extern global contract. | very strong | RTTI/PMD, constructor lowering, channel rules. | [UID:00008Z] `by-class/NewCreateUserDialogPane.md` / Direct Singleton And Header Contract | incorporate | applied |
| C033 | 00008Z | Source-quality disposition places the declaration in H and leaves class CPP blank. | very strong | Formal channel rules and generated topology. | [UID:00008Z] `by-class/NewCreateUserDialogPane.md` / Source-Quality Decision | incorporate | applied |
| C034 | 00008Z | Method notes require the constructor to initialize the Singleton base without explicit global publication. | very strong | Template-lowering instruction pattern. | [UID:00008Z] `by-class/NewCreateUserDialogPane.md` / Method Notes | incorporate | applied |
| C035 | 00008Z | Direct Singleton contract attributes publication to base construction, not authored assignment. | very strong | Template-lowering instruction pattern. | [UID:00008Z] `by-class/NewCreateUserDialogPane.md` / Direct Singleton And Header Contract | incorporate | applied |
| C036 | 0002QS | Constructor source must initialize the Singleton base and omit explicit global publication. | very strong | Template-lowering instruction pattern. | [UID:0002QS] `by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md` / Direct Singleton Constructor And Source Contract | incorporate | applied |
| C037 | 0002X8 | Target score rises `87/90 -> 92/94`. | strong | All material target blockers closed below final audit. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Score Rationale | incorporate | applied |
| C038 | 0002X7 | Global score rises `87/90 -> 92/94`. | strong | Type/linkage/definition/header/source route closed. | [UID:0002X7] `by-global/g_pNewCreateUserDialogPane.md` / Score Rationale | incorporate | applied |
| C039 | 00008Z | Class score rises `87/89 -> 90/92`. | strong | Direct base/header/channel corrected; reachability remains cap. | [UID:00008Z] `by-class/NewCreateUserDialogPane.md` / Score Rationale | incorporate | applied |
| C040 | 0000LP | File score rises `86/89 -> 89/92`. | strong | Global/class/source topology closed; constructor route remains cap. | [UID:0000LP] `by-file/NewCreateUserDialogPane.md` / Score Rationale | incorporate | applied |
| C041 | 00029W | UID0002X8 evidence replaces the aggregate's provisional slot wording with the complete physical/source disposition. | strong | Loader-zero proof, exact source route, and current IDA readback. | [UID:00029W] `by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md` / UID0002X8 Current Physical And Source Evidence | incorporate | applied |
| C042 | 00029W | Aggregate score rises `90/93 -> 92/94`. | strong | Previously unresolved slot now has full source/physical disposition. | [UID:00029W] `by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md` / Score Rationale | incorporate | applied |
| C043 | 0002X8 | Historical `0xffffffff` and `dword_69B4A8` are superseded, not current alternatives. | confirmed | PE proof, historical prestate, and catalog/current typed poststate. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Rejected And Historical Assumptions | historicalize | applied |
| C044 | 0002X7 | Historical `0xffffffff` and `dword_69B4A8` are superseded, not current alternatives. | confirmed | PE proof, historical prestate, and catalog/current typed poststate. | [UID:0002X7] `by-global/g_pNewCreateUserDialogPane.md` / Rejected And Historical Alternatives | historicalize | applied |
| C045 | 00008Z | Historical `0xffffffff` and `dword_69B4A8` are superseded, not current alternatives. | confirmed | PE proof, historical prestate, and catalog/current typed poststate. | [UID:00008Z] `by-class/NewCreateUserDialogPane.md` / Rejected And Historical Source Shapes | historicalize | applied |
| C046 | 0000LP | Historical `0xffffffff` and `dword_69B4A8` are superseded, not current alternatives. | confirmed | PE proof, historical prestate, and catalog/current typed poststate. | [UID:0000LP] `by-file/NewCreateUserDialogPane.md` / Rejected And Historical Alternatives | historicalize | applied |
| C047 | 00029W | Historical `0xffffffff` and `dword_69B4A8` are superseded, not current alternatives. | confirmed | PE proof, historical prestate, and catalog/current typed poststate. | [UID:00029W] `by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md` / UID0002X8 Current Physical And Source Evidence | historicalize | applied |
| C048 | 0002QS | Historical `0xffffffff` and `dword_69B4A8` are superseded, not current alternatives. | confirmed | PE proof, historical prestate, and catalog/current typed poststate. | [UID:0002QS] `by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md` / Singleton Storage And Generated-Lifecycle Evidence | historicalize | applied |
| C049 | 0002SJ | Historical `0xffffffff` and `dword_69B4A8` are superseded, not current alternatives. | confirmed | PE proof, historical prestate, and catalog/current typed poststate. | [UID:0002SJ] `by-memory/0x0061fda0-0x0061fe3c.NewCreateUserDialogPaneVtableData.md` / Direct Singleton Source Contract And Lifecycle Route | historicalize | applied |
| C050 | 0002QU | Historical `0xffffffff` and `dword_69B4A8` are superseded, not current alternatives. | confirmed | PE proof, historical prestate, and catalog/current typed poststate. | [UID:0002QU] `by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md` / NewCreateUserDialogPane Direct Singleton Lifecycle Closure | historicalize | applied |
| C051 | 0002X8 | Historical command-19221 physical empty marker is removed; command-19759 records the physical page non-reconstructable with no CPP/H marker. | confirmed | Command `000000019759`, memory-coverage SHA256 `ED4D13BD...1A05F`, and zero UID0002X8 generated markers. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Source And Generated Disposition | incorporate | applied |
| C052 | 0002X7 | Historical command-19221 empty marker is replaced by the sole position-0 global definition in command-19759 CPP. | confirmed | Current CPP SHA256 `4CB8A20A...F684D`, lines 7-10. | [UID:0002X7] `by-global/g_pNewCreateUserDialogPane.md` / Source Definition And Header Contract | incorporate | applied |
| C053 | 00008Z | Command-19759 generated H contains the exact class/extern contract. | confirmed | Current H SHA256 `F88C60C8...54226`, one UID00008Z H block. | [UID:00008Z] `by-class/NewCreateUserDialogPane.md` / Direct Singleton And Header Contract | incorporate | applied |
| C054 | 00008Z | Command-19759 generated CPP retains only the legitimate UID00008Z H-only empty-emitter marker. | confirmed | Current CPP SHA256 `4CB8A20A...F684D`, one UID00008Z empty marker. | [UID:00008Z] `by-class/NewCreateUserDialogPane.md` / Source-Quality Decision | incorporate | applied |
| C055 | 0002QS | Current generated command-19759 preserves UID0002QS core method CPP after owner/global/header correction. | confirmed | Current CPP SHA256 `4CB8A20A...F684D`, UID0002QS marker and method bodies. | [UID:0002QS] `by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md` / Direct Singleton Constructor And Source Contract | incorporate | applied |
| C056 | 0002X8 | MainMenu helper is a consumer, not source owner. | confirmed | Read-only branch and separate constructor/destructor lifetime. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Ownership Decision | incorporate | applied |
| C057 | 0002X7 | MainMenu helper is a consumer, not source owner. | confirmed | Read-only branch and separate constructor/destructor lifetime. | [UID:0002X7] `by-global/g_pNewCreateUserDialogPane.md` / Ownership Decision | incorporate | applied |
| C058 | 00029W | Mixed aggregate [UID:00029W] remains parentless and non-emitting. | confirmed | Four different semantic owners; callback readback preserved `CANONICAL_OWNER:NONE`, false, blank emitter. | [UID:00029W] `by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md` / Ownership Decision | already-present | already-present |
| C059 | 00008Z | Status records that no direct constructor route exists in current xrefs or PE scan. | confirmed | MCP xrefs and fresh PE scans. | [UID:00008Z] `by-class/NewCreateUserDialogPane.md` / Status | incorporate | applied |
| C060 | 00008Z | Missing direct constructor reachability remains a class confidence cap. | confirmed | Exhaustive xref and PE route negatives. | [UID:00008Z] `by-class/NewCreateUserDialogPane.md` / Score Rationale | incorporate | applied |
| C061 | 0000LP | Evidence notes record that no direct constructor route exists in current xrefs or PE scan. | confirmed | MCP xrefs and fresh PE scans. | [UID:0000LP] `by-file/NewCreateUserDialogPane.md` / Evidence Notes | incorporate | applied |
| C062 | 0000LP | Missing direct constructor reachability remains a file confidence cap. | confirmed | Exhaustive xref and PE route negatives. | [UID:0000LP] `by-file/NewCreateUserDialogPane.md` / Score Rationale | incorporate | applied |
| C063 | 0002X8 | Catalog entry `0362` applied the incomplete type, exact four-byte item, source-facing name/type, and both comments with no target drift. | very strong | Historical prestate, catalog action/save, backup, dated checkpoints through `412DA7E8...519CD`, and current `EEF0C80D...A7997B` readback. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / IDA Handoff | incorporate | applied |
| C064 | 0002X8 | Adjacent `g_pNewUserDialogPane2` and `g_pServerSelectPane` item/type/comment/byte/xref state remained protected. | confirmed | Catalog-0362 protected readback and current `EEF0C80D...A7997B` verification. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / Boundaries And Protected Neighbors | already-present | already-present |
| C065 | 0002X8 | All six individually enumerated RTTI dependencies remained exact across catalog action and later shared-IDB saves. | confirmed | Catalog-0362 protected readback and current `EEF0C80D...A7997B` verification. | [UID:0002X8] `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` / IDA Handoff | already-present | already-present |
| C066 | 00029W | Supervisor command19755 applied and verified the exact UID00029W aggregate coverage row at `92% : very-strong`. | confirmed | Command `000000019755`, exit `0`, `ok: 1`; by-memory coverage SHA256 `EF118661...C795`; row 4655 between UID0001PW and UID0002X4. | [UID:00029W] `by-memory/-coverage-report.md` / UID00029W row between UID0001PW and UID0002X4 | incorporate | applied |
| C067 | 0002X8 | Supervisor command19755 applied and verified the exact UID0002X8 false/non-emitting physical-target coverage row at `92% : very-strong`. | confirmed | Command `000000019755`, exit `0`, `ok: 1`; by-memory coverage SHA256 `EF118661...C795`; row 4657 between UID0002X4 and UID0002XN. | [UID:0002X8] `by-memory/-coverage-report.md` / UID0002X8 row between UID0002X4 and UID0002XN | incorporate | applied |
| C068 | 0002X7 | Supervisor command19756 applied and verified the exact UID0002X7 semantic-global coverage row at `92% : very-strong`. | confirmed | Command `000000019756`, exit `0`, `ok: 1`; by-global coverage SHA256 `522E9096...28E0`; row 121 between UID0000RR and UID0000RS. | [UID:0002X7] `by-global/-coverage-report.md` / UID0002X7 row between UID0000RR and UID0000RS | incorporate | applied |
| C069 | 00008Z | Supervisor command19757 applied and verified the exact UID00008Z class coverage row at `90% : very-strong`. | confirmed | Command `000000019757`, exit `0`, `ok: 1`; by-class coverage SHA256 `2211261E...7F4F`; row 347 between UID00008Y and UID000090. | [UID:00008Z] `by-class/-coverage-report.md` / UID00008Z row between UID00008Y and UID000090 | incorporate | applied |
| C070 | 0000LP | Supervisor command19758 applied and verified the exact UID0000LP file coverage row at `89% : very-strong`. | confirmed | Command `000000019758`, exit `0`, `ok: 1`; by-file coverage SHA256 `725EBCE5...770`; row 178 between UID0000LO and UID0000LQ. | [UID:0000LP] `by-file/-coverage-report.md` / UID0000LP row between UID0000LO and UID0000LQ | incorporate | applied |
| C071 | 0002QS | Supervisor command19755 applied and verified UID0002QS at `88% : very-strong` with the direct Singleton base-constructor/no-authored-publication disposition. | confirmed | Command `000000019755`, exit `0`, `ok: 1`; by-memory coverage SHA256 `EF118661...C795`; row 2678 between UID00043Y and UID0002QT. | [UID:0002QS] `by-memory/-coverage-report.md` / UID0002QS row between UID00043Y and UID0002QT | incorporate | applied |
| C072 | 0002SJ | Supervisor command19755 applied and verified UID0002SJ through endpoint `0x0061fe3c` as ignored/non-emitting at `88% : very-strong`. | confirmed | Command `000000019755`, exit `0`, `ok: 1`; by-memory coverage SHA256 `EF118661...C795`; row 4274 between UID0002SH and UID0002SI. | [UID:0002SJ] `by-memory/-coverage-report.md` / UID0002SJ row between UID0002SH and UID0002SI | incorporate | applied |
| C073 | 0002QU | Supervisor command19755 applied and verified the exact NewCreateUserDialogPane clear-helper/scalar-destructor Singleton cross-link while retaining ignored/non-emitting `88% : strong`. | confirmed | Command `000000019755`, exit `0`, `ok: 1`; by-memory coverage SHA256 `EF118661...C795`; row 2683 between UID00046S and UID0001CS. | [UID:0002QU] `by-memory/-coverage-report.md` / UID0002QU row between UID00046S and UID0001CS | incorporate | applied |

## Positive Evidence Summary

- Direct facts: exact zero bytes; one logical four-byte start-referenced slot; six lifecycle/consumer refs; class-specific vtable stores; direct Singleton RTTI and PMD; constructor publication; unwind/helper/destructor clears; main-menu read.
- Corroboration: target/global/class/file/core/vtable/lifecycle/main-menu docs agree on the class and owner; adjacent accepted singleton reports use the same physical-versus-semantic route.
- Strongest inference chain: class-specific RTTI plus constructor pointer adjustment proves direct Singleton inheritance; that inheritance explains every publication/clear site; cross-TU main-menu consumption proves external linkage; therefore one semantic global definition under the class source is substantially more likely than any raw integer, file-static, physical duplicate, or handwritten registration design.

## IDA MCP Facts

- Function/range facts: `sub_4F69A0` `0x91` bytes; `sub_52C360` `0x9e9`; `sub_52F720` `0x0b`; `sub_52F870` `0x6c`; raw cleanup instruction at `0x0052cd7a` has no containing function.
- Data facts: the historical `0E0AF938...AB481` pre-action state had four one-byte target heads at `0x0069b4a8`, `a9`, `aa`, and `ab`, with `unk_69B4A8` only at the first byte and blank target types/comments. Catalog entry `0362` replaced only those four heads; current IDB `EEF0C80D...A7997B` has one size-four `is_data:true` item named `g_pNewCreateUserDialogPane`, typed `NewCreateUserDialogPane *`, with both exact accepted comments. Bytes remain all zero; `296ED21C...3CF8B`, `905D1AB1...604C1`, and `412DA7E8...519CD` are retained only as dated matching checkpoints.
- Xref facts: six refs at `0x004f6a13`, `0x0052c3b8`, `0x0052c3bf`, `0x0052cd7a`, `0x0052f720`, and `0x0052f89d`; zero interior refs.
- RTTI/global/type facts: decorated class descriptor `??_R0?AVNewCreateUserDialogPane@@@8` at `0x00677f68`; decorated Singleton descriptor at `0x00677f90`; Singleton base descriptor at `0x0064c874` with PMD `620/-1/0`; current local `NewCreateUserDialogPane` is an incomplete no-layout type suitable for the target pointer; the exact target name is unique.
- Negative IDA facts: constructor start `0x0052c360` has zero inbound xrefs; no complete local class layout is available or inferred; no target interior xrefs, neighbor absorption, changed target bytes, or protected dependency drift is present.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0069b4a8-0x0069b4ac` | 0002X8 target | Physical singleton storage | false | 0002X7 | `92/94` | callback applied; non-emitting |
| semantic global | 0002X7 `by-global/g_pNewCreateUserDialogPane.md` | Sole global definition | true | 0000LP | `92/94` | callback applied; position-0 CPP |
| class | 00008Z `by-class/NewCreateUserDialogPane.md` | Header class/extern owner | true | 0000LP | `90/92` | callback applied; position-10 H |
| source file | 0000LP `by-file/NewCreateUserDialogPane.md` | Translation-unit root | true | FILE | `89/92` | callback applied |
| `0x0052c360-0x0052dcf5` | 0002QS | Exact class method cluster | true | 00008Z | `88/91` | score retained; source-contract detail applied |
| `0x0061fda0-0x0061fe3c` | 0002SJ | Compiler-generated vtable data | false | 00008Z | `88/92` | score retained; Singleton/global cross-link applied |
| `0x0052f710-0x0052f94c` | 0002QU | Compiler lifecycle/thunk island | false | 0000IK context | `88/90` | score retained; exact lifecycle closure applied |
| `0x0069b4a4-0x0069b4b4` | 00029W | Mixed-owner physical index | false | NONE | `92/94` | callback applied; parentless/non-emitting preserved |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f6a13` | `sub_4F69A0` / source `CloseMainMenuDialogSingletons` | Reads and closes this pane when `g_useEpfAssets` selects the newer dialog. Consumer only. |
| `0x0052c3b8` | `sub_52C360` constructor | Publishes complete `NewCreateUserDialogPane *`. |
| `0x0052c3bf` | same constructor | Null-adjustment fallback clears the pointer. |
| `0x0052cd7a` | raw constructor EH/unwind body | Clears partially published state before base teardown. |
| `0x0052f720` | tiny Singleton clear/destructor lowering | Writes zero; no ordinary code caller. |
| `0x0052f89d` | `sub_52F870` scalar deleting destructor | Clears after class member cleanup and before base destruction/deallocation. |
| `0x0052c360` | inbound xref query | Zero current xrefs; retained-code caveat, not ownership rejection. |

## Documentation Evidence And IDA Status

- Supporting docs: [UID:0002QS] maps the complete retained class cluster; [UID:0002SJ] maps class vtable data; [UID:0002QU] maps lifecycle artifacts; [UID:00019J] supplies source-ready main-menu consumer code; [UID:0002X4]/[UID:0002XN] supply accepted adjacent singleton policy.
- Historical pre-callback ordinary defects: target/global described `dword_69B4A8`; target was true/emitting; class declaration was in CPP, lacked Singleton, and had blank H; aggregate called UID0002X8 provisional. The callback corrected those ordinary-doc defects and preserved their disproved assumptions in historical/rejected sections. The manual coverage payload remained supervisor-owned; commands `000000019755` through `000000019758` subsequently applied and verified all eight exact replacements below, including UID0002QS, UID0002SJ, and UID0002QU.
- Assignment-time tracker checkpoint: command `000000018895`, SHA256 `21171036DD059D779DA0597D55C1075F93AF5AED9917E17063C1BE3485BD2274`, 1,669,011 bytes, 6,603 lines at `2026-07-29T07:49:11-04:00`; this remains assignment provenance, not current generated state.
- Historical intermediate generated checkpoint observed `2026-07-29T09:55:55-04:00`: tracker command `000000019064`, refreshed `2026-07-29T09:55:05-04:00`, SHA256 `50BD3D43C9E900139ED5E49FF84C5E9957D2F9B9BE804294F7452C4F48D9A538`, 1,672,098 bytes, 6,616 lines; target was line 1802 at unchanged `87/90` with no direct/additional report count.
- Historical intermediate memory-coverage checkpoint: command `000000019063`, refreshed `2026-07-29T09:53:20-04:00`, SHA256 `34E553794C531FD64FCFC3F08E439B374AFED796A313670997827CB2F59B677B`, 1,416,176 bytes, 4,936 lines; target was line 3253 and said `emits` through UID0002X7.
- Historical intermediate generated-source checkpoint: `NewCreateUserDialogPane.cpp` command `000000019063`, refreshed `2026-07-29T09:53:20-04:00`, SHA256 `2E8559F418BA58DF68E29262A1BB6F12673D864E229006864A3F3C659CD4A82E`, 5,475 bytes, 168 lines; it had UID0002X7 and UID0002X8 empty markers and no sibling H.
- Historical audit checkpoint at `2026-07-29T10:34:52-04:00`: tracker and memory coverage command `000000019078` had tracker SHA256 `409A6202E13CE806F70F8638F03E9FD715F0F3C9AED8C80B97494D779D6C5143` and memory-coverage SHA256 `69D5A0BA7DA5DC374258015914E3F3F7F6DC661FDE76352BCE2DA4DCF088B460`; generated source command `000000019068` had SHA256 `2B9972177259208AD1EF17712BABC33EA78AC7CC84D5FE36568C8E9B8F5F7B2C`. These are dated history, not current shared-artifact identities.
- Historical post-command-19152 checkpoint: tracker command `000000019153` had SHA256 `1FE96D5A171A10D8E2BBF53F8553B94DCCF2D7E529B078EDBAC9BACF4024CB6A`; generated memory coverage command `000000019152` had SHA256 `1C756C0998115DDA85392DD8766D3B2AA968051AF1D041345DA4D5570D54B832`; generated source command `000000019152` had SHA256 `204EB589DF7A11F3ABA7AEFCA528D6164E87CC9F412B2DAEBD56C02E53FAF550`. These are dated history, not current shared-artifact identities.
- Historical command-19201 checkpoint: tracker SHA256 `3B57476E224BD2D353C4D3C6868C90C27AE79D368D3111453DB2D78E69902183`, generated memory-coverage SHA256 `658A45B4B79D5A2A345AB75DC0F1B7504482A7E82C4855F63411188D9EED8619`, and generated source SHA256 `03926B50B657378F45D69B364FECF499D7115D72B7D0405E2CD75F9B6BF8682C` were refreshed at `2026-07-29T10:58:40-04:00`. They are dated history, not current shared-artifact identities.
- Historical pre-callback tracker observation after command `000000019221`, refreshed `2026-07-29T11:05:07-04:00`: SHA256 `2E18D81FCA6DBFCAF8794D63066546A147437CCFD78AE812C9D9485CA4598A31`, 1,675,820 bytes, 6,631 lines; target was line 1802 at `87/90`, reconstructable true, and zero direct/additional report counts.
- Historical pre-callback generated memory-coverage observation after command `000000019221`, refreshed `2026-07-29T11:05:07-04:00`: SHA256 `C9A6EFFC15DEBF7193DB0EC94927BE787C167C159FF15B7FE0D8D40236A80236`, 1,419,665 bytes, 4,948 lines; target was line 3261 and still said `emits` through UID0002X7.
- Historical pre-callback generated source observation after command `000000019221`, refreshed `2026-07-29T11:05:07-04:00`: `NewCreateUserDialogPane.cpp` SHA256 `90EA4FEE1D7FC67FD4451D53427266E4F1D8F350ACDB93C83902E556DFA2FD0B`, 5,475 bytes, 168 lines; it contained the UID00008Z class declaration plus UID0002QS method source, then one UID0002X7 empty marker and one UID0002X8 empty marker, with no H.
- Historical callback-time shared tracker observation: command `000000019228`, refreshed `2026-07-29T11:35:05-04:00`, SHA256 `E749DE7E9FB6D6AA761D1B51936DB38C7B6F06201919CA507628F3C567744CF0`, 1,676,442 bytes/6,632 lines. Its UID0002X8 line 1802 still showed `87/90`, reconstructable true, and zero direct/additional counts because B008's commands intentionally suppressed generated refresh; this is dated history, not current generated state.
- Historical external generated checkpoint: command `000000019259`, refreshed `2026-07-29T12:31:09-04:00`, established the accepted topology before final manual closure. Its tracker SHA256 was `0100F9163CD9178641161A1A2A43B16185D3C663A4BE02A05DD2D410635813A0`; generated memory coverage SHA256 was `79D93A8AF287C67C5DFF90ECD8DD3DCC02CC42BC3976E4746410B4C04C9CD5BD`; CPP SHA256 was `E49E393234BCB3610AA9DA96327B5D587FBFC8665821A06F474B06993C9F0CDC`; H SHA256 was `3437123289C3E01761D67985F5BC92DD70230F835EFA5B0334E840C39C7E0C69`. These are dated history, not current shared-artifact identities.
- Current generated closure: supervisor command `000000019759`, refreshed `2026-07-29T16:10:35-04:00`, exited `0` with `ok: 1`, rebuilt the registry, and refreshed generated coverage/CPP/H/research tracker. Generated memory coverage SHA256 `ED4D13CBD9770A1927290A2E03C89CBA66D9231C4D61F82EE9E6817F5101A05F`, 1,419,567 bytes/4,948 lines, records UID0002X8 at line 4323 as not reconstructable with no emitter. `NewCreateUserDialogPane.cpp` SHA256 `4CB8A20A7DC4D978567A2D0C665D2274D0B6C0EFE805BE8E900EFBCD1A0F684D`, 4,674 bytes/143 lines, contains the sole UID0002X7 definition, UID0002QS method CPP, one legitimate UID00008Z H-only empty marker, and no UID0002X8 marker. `NewCreateUserDialogPane.h` SHA256 `F88C60C8244850D4E60305091CEF6F44CD5B2329AF20DBE98F9907D7A2954226`, 1,356 bytes/40 lines, contains the exact UID00008Z extern/class contract and no UID0002X8 marker. The later lifecycle refresh at command `000000019761` made tracker SHA256 `D0FC00F7CA525A658CFBFCE08E95ECA13B07E9120B5DDE73B401DA23BB4FDD7F`, 1,677,700 bytes/6,632 lines, the current tracker observation; UID0002X8 remains `92/94`, reconstructable false at line 5518.
- Current ordinary formal/route readback after the accepted callback: UID0002X8 `92/94`, owner UID0002X7, false/non-emitting, blank position/CPP/H; UID0002X7 `92/94`, owner/emitter UID0000LP, position `0`, exact CPP and blank H; UID00008Z `90/92`, owner/emitter UID0000LP, position `10`, blank CPP and exact H; UID0000LP `89/92`, owner `FILE`; UID00029W `92/94`, parentless, false/non-emitting, blank CPP/H; UID0002QS `88/91`, owner/emitter UID00008Z with method CPP and blank H; UID0002SJ `88/92`, owner UID00008Z, false/non-emitting, blank CPP/H; UID0002QU `88/90`, owner UID0000IK, false/non-emitting, blank CPP/H.
- Current command-19759 generated topology matches the accepted recommendation: UID0002X8's physical empty marker is absent; UID0002X7 emits the position-0 semantic CPP definition; UID00008Z's class/extern contract is in H at position 10 with one legitimate H-only class emitter marker in CPP; UID0002QS method CPP remains attached through class/file; UID00029W, UID0002SJ, and UID0002QU produce no raw-data/lifecycle markers. Callback commands `000000019233` through `000000019248` explicitly skipped refresh, so command19759 is external supervisor/validator evidence rather than a B008-generated action.
- Generated artifacts are shared and may advance after these dated observations; the supervisor must re-read them during implementation validation rather than treating any generated hash as permanent current state.

## Ranked Ownership Analysis

### 1. Semantic global UID0002X7 under NewCreateUserDialogPane.cpp

- Evidence for: class-specific constructor/destructor writes, direct Singleton RTTI, main-menu cross-TU consumer, existing global/file/class pages, and accepted adjacent singleton topology.
- Evidence against: exact original symbol token is unavailable; no direct constructor caller survives.
- Decision: accepted with very strong confidence. Neither negative changes the pointer's semantic owner.

### 2. Physical by-memory target UID0002X8

- Evidence for: exact physical address and binary lifecycle.
- Evidence against: emitting from this page duplicates the semantic global definition and, at the historical pre-callback command-19221 generated checkpoint, produced only an empty marker.
- Decision: retain as non-reconstructable/non-emitting physical evidence linked to UID0002X7.

### 3. MainMenuPane or mixed aggregate

- Evidence for: MainMenu reads the slot; aggregate contains the address.
- Evidence against: neither constructs, destroys, or semantically owns the class; aggregate spans four owners.
- Decision: rejected as declaration/definition owner. MainMenu is a consumer and UID00029W remains an index.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new file. Use existing `NexusTK/login/NewCreateUserDialogPane.cpp` and generated matching header.
- Likely full contents: sole global definition, class declaration/extern in H, exact class method children from UID0002QS, ordinary destructor source, and compiler-regenerated Singleton/RTTI/vtable/thunk effects.
- Related items accepted: UID0002X7, UID00008Z, UID0002QS.
- Rejected grouping: CreateUserDialogs umbrella, MainMenuPane, physical four-slot aggregate, or a standalone Globals.cpp.
- Source-file inference: narrow class-specific module, matching current file structure and sibling create-user modules.

## Source Placement

- Recommended placement: `NexusTK/login/NewCreateUserDialogPane.cpp` and `NexusTK/login/NewCreateUserDialogPane.h` under [UID:0000LP].
- Why: constructor/method/resource family, class/vtable ownership, existing file page, and alternate create-user variant placement all converge on the login module.
- Global order: semantic UID0002X7 at position `0`; class/header declaration at position `10`; exact method children after the class/global structure.
- Rejected: `MainMenuPane.cpp` because it only reads; `CreateUserDialogs.cpp` because the umbrella is non-emitting; global aggregate source because its four slots have different classes/files; file-static definition because MainMenu consumes it externally.
- Remaining placement uncertainty: none material. Exact historical project filename capitalization is already stable in current project docs.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: four bytes `[0x0069b4a8,0x0069b4ac)`. One start-address ref family and zero interior refs prove one pointer-width object.
- Predecessor: separate `[0x0069b4a4,0x0069b4a8)` `g_pNewUserDialogPane2`; successor: separate `[0x0069b4ac,0x0069b4b0)` `g_pServerSelectPane`.
- Parent aggregate: `[0x0069b4a4,0x0069b4b4)` is a physical neighborhood over four direct owners. It remains parentless/non-emitting.
- Padding: none inside target. The four zero bytes are storage, not padding.
- Split: already exact; no new page, merge, range extension, or covered-by mechanism is needed.
- Reclassification: target true/emitting to false/non-emitting; semantic global remains true and becomes the sole source emitter.

## Negative Evidence Summary

- No direct constructor xref, absolute pointer, RVA pointer, or direct E8/E9 target was found. This limits retained class reachability confidence but does not negate class-specific storage writes or RTTI.
- No local complete `NewCreateUserDialogPane` UDT exists. A complete guessed layout is rejected; only an opaque pointer type is needed.
- No raw file bytes back the target; therefore a static `0xffffffff` initializer is rejected.
- No relocation directory can create a nonzero target state.
- No interior-byte xrefs support byte fields or an array.
- MainMenu read, aggregate adjacency, vtable data, and compiler cleanup bodies do not transfer source declaration ownership.
- No original symbols prove exact lexical spelling. The best human name is inferred rather than replaced with an IDA label.

## IDA Rename / Type / Comment Recommendations

| Action ID | Entity / range | Literal historical pre-action and current readback | Proposed/action-time operation | Evidence / confidence | Negative constraints | Expected/current readback | Supervisor classification |
| --- | --- | --- | --- | --- | --- | --- | --- |
| A00 | local type catalog `NewCreateUserDialogPane` | Historical `0E0AF938...AB481`: exact type query returned zero records while `DialogPane` was ordinal 471, size 620, seven members. Dated checkpoints through `412DA7E8...519CD` found the applied incomplete type. Current `EEF0C80D...A7997B`: `NewCreateUserDialogPane` remains ordinal 949, declaration-only/incomplete with sentinel unknown size, zero members, and no guessed layout; `DialogPane` remains ordinal 471, size 620, seven members. | Catalog entry `0362` declared only the incomplete forward type required by A01. | Class RTTI/vtables/lifecycle prove identity; full layout is outside this action. | do not create a complete UDT, members, inheritance, size, vtable, or overwrite `DialogPane` | incomplete no-layout type remains available for pointer application; `DialogPane` and unrelated types remain exact | applied and verified |
| A01 | data `[0x0069b4a8,0x0069b4ac)` | Historical `0E0AF938...AB481`: four one-byte heads, first named `unk_69B4A8`, remaining three unnamed; blank types, `is_code:false`, `is_data:false`; address-regular absent (`""`); address-repeatable absent (`""`); zero bytes; six start refs and zero interior refs. Dated checkpoints through `412DA7E8...519CD` matched the applied state. Current `EEF0C80D...A7997B`: one head/end/size `0x69b4a8/0x69b4ac/4`, `is_data:true`, exact name/type/comments, same zero bytes, six start xrefs, and zero interior xrefs. | Catalog entry `0362` replaced exactly the four target heads with one `NewCreateUserDialogPane *` item named `g_pNewCreateUserDialogPane`; regular comment `Active NewCreateUserDialogPane singleton pointer; loader-zeroed before newer create-user dialog construction.`; repeatable comment `NewCreateUserDialogPane *g_pNewCreateUserDialogPane; Singleton<NewCreateUserDialogPane> publishes and clears this external-linkage storage.` | exact bytes/xrefs, RTTI PMD, constructor publication, destructor clears, no name collision; very strong | preserve bytes and all xrefs; do not absorb neighbors; do not use `dword_69B4A8`; do not create initializer bytes; do not rename/type functions | current item remains exact, bytes still zero, six start refs, zero interior refs, both accepted comments exact | applied and verified |
| A02 | protected predecessor `[0x0069b4a4,0x0069b4a8)` | Historical pre-action and dated checkpoints through `412DA7E8...519CD` agree with current `EEF0C80D...A7997B`: name query resolves `g_pNewUserDialogPane2`; inspect presents a one-byte head at `0x69b4a4` with `NewUserDialogPane2 *`, name field blank, non-code/non-data; address-regular absent (`""`); address-repeatable absent (`""`); bytes zero. | No mutation under UID0002X8; catalog entry `0362` verified preservation. | separate accepted UID0002X4/UID0002X3 authority | do not undefine, resize, rename, retype, comment, or merge predecessor | exact protected state remains unchanged after A01 and later shared-IDB saves | no change recommended; protected and verified |
| A03 | protected successor `[0x0069b4ac,0x0069b4b0)` | Historical pre-action and dated checkpoints through `412DA7E8...519CD` agree with current `EEF0C80D...A7997B`: name query resolves `g_pServerSelectPane`; inspect presents a one-byte head at `0x69b4ac` with `ServerSelectPane *`, name field blank, non-code/non-data; address-regular absent (`""`); address-repeatable absent (`""`); bytes zero. | No mutation under UID0002X8; catalog entry `0362` verified preservation. | separate accepted UID0002XN/UID0000S8 authority | do not undefine, resize, rename, retype, comment, or merge successor | exact protected state remains unchanged after A01 and later shared-IDB saves | no change recommended; protected and verified |

- Protected read-only RTTI dependency `0x0064c858-0x0064c874`: `NewCreateUserDialogPane` base-class descriptor bytes encode type descriptor `0x00677f68`, contained-base count `7`, PMD `0/-1/0`, attributes `0x40`, and class-hierarchy descriptor `0x0064c824`; literal current address-regular comment `reference to type description`; address-repeatable comment absent (`""`). Preserve the exact bytes, comments, and descriptor interpretation; this dependency is outside the Gate 2B action table.
- Protected read-only RTTI dependency `0x0064c874-0x0064c890`: `Singleton<NewCreateUserDialogPane>` base-class descriptor bytes encode type descriptor `0x00677f90`, contained-base count `0`, PMD `620/-1/0`, attributes `0x40`, and class-hierarchy descriptor `0x0064c890`; literal current address-regular comment `reference to type description`; address-repeatable comment absent (`""`). Preserve the exact bytes, comments, and descriptor interpretation; this dependency is outside the Gate 2B action table.
- Protected read-only RTTI dependency `0x0064c890-0x0064c8a0`: Singleton class-hierarchy descriptor bytes encode signature `0`, attributes `0`, one base class, and base-class-array pointer `0x0064c8a0`; literal current address-regular comment `signature`; address-repeatable comment absent (`""`). Preserve the exact bytes, comments, and descriptor interpretation; this dependency is outside the Gate 2B action table.
- Protected read-only RTTI dependency `0x0064c8a0-0x0064c8a4`: the one-entry Singleton base-class array contains exact pointer `0x0064c8a8`; literal current address-regular comment `reference to base class decription 1`; address-repeatable comment absent (`""`). Preserve the exact pointer bytes and comments; this dependency is outside the Gate 2B action table.
- Protected read-only RTTI dependency `0x00677f68`: current decorated descriptor name `??_R0?AVNewCreateUserDialogPane@@@8`; TypeDescriptor name bytes at `+0x8` are `.?AVNewCreateUserDialogPane@@`; literal current address-regular comment `reference to RTTI's vftable`; address-repeatable comment absent (`""`). Preserve the exact name, descriptor bytes, comments, and current representation; this dependency is outside the Gate 2B action table.
- Protected read-only RTTI dependency `0x00677f90`: TypeDescriptor name bytes at `+0x8` are `.?AV?$Singleton@VNewCreateUserDialogPane@@@@`, resolving the existing decorated `Singleton<NewCreateUserDialogPane>` descriptor; literal current address-regular comment `reference to RTTI's vftable`; address-repeatable comment absent (`""`). Preserve the exact name bytes, descriptor bytes, comments, and current representation; this dependency is outside the Gate 2B action table.
- Former grouped A04 is intentionally removed: none of these six protected dependencies requests a Gate 2B mutation, and no grouped no-change action remains.
- Catalog entry `0362` readback, dated `296ED21C...3CF8B`/`905D1AB1...604C1`/`412DA7E8...519CD` checkpoints, and bounded current-IDB `EEF0C80D...A7997B` recheck independently confirm all six protected dependency names, descriptor bytes, PMD/attributes, regular comments, and blank repeatable-comment channels remain exact.
- Dependency functions intentionally unchanged by this target action: `sub_4F69A0` is source-facing `CloseMainMenuDialogSingletons`; `sub_52C360` is the `NewCreateUserDialogPane` constructor; `0x0052cd7a` is raw constructor unwind cleanup; `sub_52F720` is Singleton clear/destructor lowering; `sub_52F870` is the scalar deleting destructor. Each has blank function comments at its current start. Their source-facing roles are resolved here, but function renames/comments belong to their dedicated function/range authority and are unnecessary for safe target normalization.
- Supervisor integrity readback result: catalog entry `0362` changed only A00/A01. Current authoritative IDB `EEF0C80D...A7997B` verifies protected neighbors, all six RTTI dependencies, functions, bytes, xrefs, `DialogPane`, and unrelated types remain exact; `296ED21C...3CF8B`, `905D1AB1...604C1`, and `412DA7E8...519CD` are dated matching checkpoints.

## First-Draft C++ Recommendation

- Eligible for target draft C++: no. The target is physical evidence for source emitted elsewhere.
- Target CPP block disposition: exactly blank.
- Target H block disposition: exactly blank.
- Exact no-code proof: semantic global [UID:0002X7] represents the one authored external object. Emitting from physical [UID:0002X8] would define the same storage twice; the compiler/linker generates physical storage from the semantic declaration.
- Exact semantic-global CPP insertion for [UID:0002X7]:

```cpp
class NewCreateUserDialogPane;

NewCreateUserDialogPane *g_pNewCreateUserDialogPane = 0;
```

- Exact semantic-global H insertion: blank. The class H block below owns the one extern plus complete declaration, matching the accepted same-family `NewUserDialogPane2` arrangement.
- Exact class CPP insertion for [UID:00008Z]: blank.
- Exact class H insertion for [UID:00008Z]:

```cpp
class NewCreateUserDialogPane;
extern NewCreateUserDialogPane *g_pNewCreateUserDialogPane;

class NewCreateUserDialogPane : public DialogPane,
                                public Singleton<NewCreateUserDialogPane>
{
public:
    NewCreateUserDialogPane();
    virtual ~NewCreateUserDialogPane();

protected:
    virtual void OnCommand(int commandId, int action);
    virtual bool OnDialogEvent(void *event);
    virtual void OnDialogNotify(int commandId);

    void SelectGender(int genderOrNation);
    void SelectTotem(int totem);
    void SelectMale();
    void SelectFemale();

    void SubmitCreateUser();
    void SendCreateCharacterRequest();
    bool HandleCreateUserReply(const unsigned char *packet);

private:
    NewUserShapeSelectControlPane *m_shapeSelector;
    int m_selectedGenderOrNation;
    int m_selectedTotem;
    unsigned char m_waitingForCharacterReply;
    SimpleUString m_createdUserName;

    [[CHILDREN]]
};
```

- Exact behavior preservation: one external pointer begins zero; Singleton base construction/destruction regenerates publication/clear side effects; class vtables/RTTI and compiler wrappers regenerate from ordinary class source.
- Original-source shape: plain forward declaration, raw pointer, direct CRTP Singleton base, C++03 zero literal, and ordinary `.h`/`.cpp` split match late-1999 through mid-2000s Windows game code and the same create-user family.
- Source-facing names replace all IDA aliases. No raw `unk_`, `dword_`, `sub_`, explicit EH cleanup, scalar-wrapper body, or manual RTTI/vtable data appears in final code.
- Third-party import directive: not applicable.

## Final Recommendation

- Target [UID:0002X8]: callback applied at `92/94`, owner `0002X7`, false/non-emitting, blank position/CPP/H, with full storage, loader-zero, lifecycle, Singleton, boundary, one-definition, historical IDA prestate, catalog-0362 applied poststate, and current authoritative saved-IDB `EEF0C80D...A7997B` target/protected no-drift, negative, and historical evidence.
- Global [UID:0002X7]: callback applied at `92/94`, owner/emitter `0000LP`, position `0`, exact CPP definition, blank H, external linkage, direct Singleton cause, loader-zero storage, and one-definition contract.
- Class [UID:00008Z]: callback applied at `90/92`, owner/emitter `0000LP`, position `10`, blank CPP, exact H forward/extern/class payload, and direct Singleton inheritance.
- File [UID:0000LP]: callback applied at `89/92`, with global/class/method position/order, one-definition structure, direct Singleton cause, and retained constructor-reachability caveat.
- Aggregate [UID:00029W]: callback applied at `92/94`, with NONE/false/non-emitting preserved, provisional UID0002X8 wording removed, and all four child dispositions synchronized.
- Supervisor closure: commands `000000019755` through `000000019758` applied and validated the eight exact manual coverage rows, and command `000000019759` refreshed generated coverage, CPP, H, registry, and tracker topology. No coverage/generated implementation item remains open in this recommendation.
- Outside scope: constructor-route recovery and full original field spellings remain class/file research, but have exact negative evidence and do not block this target implementation.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md`.
- Applied metadata: `92/94`, owner unchanged `0002X7`, false, blank emitter/position, blank CPP/H, `Nested:0`.
- Item Summary: physical loader-zeroed storage; six exact refs; direct Singleton PMD/lowering; semantic UID0002X7 sole emitter; no duplicate physical source.
- Applied target headings are exactly: Summary; Evidence; Loader-Zero And Relocation Proof; Direct Singleton Source Cause; Exact Lifecycle Inventory; Boundaries And Protected Neighbors; Source And Generated Disposition; IDA Handoff; Ownership Decision; Rejected And Historical Assumptions; Score Rationale; Cross-References; Changes.
- Preserve the historical pre-action IDA identity `unk_69B4A8` on the first of four undefined heads only as dated evidence; current saved IDB has the exact one-item identity `NewCreateUserDialogPane *g_pNewCreateUserDialogPane`. Retain `dword_69B4A8` only as a disproved historical alias.
- Preserve historical `0xffffffff` as a disproved assumption with exact PE reason, not delete it silently.

## Recommended Support Doc Changes

- `by-global/g_pNewCreateUserDialogPane.md`: exact CPP definition, position `0`, score `92/94`, sole-emitter/header contract, PE proof, RTTI/PMD/EBO, lifecycle, aliases/rejected alternatives, physical false child.
- `by-class/NewCreateUserDialogPane.md`: score `90/92`, position `10`, blank CPP, exact H payload, direct Singleton base evidence, one-definition/generated expectations, no explicit publication, historical omitted-base/CPP-channel correction.
- `by-file/NewCreateUserDialogPane.md`: score `89/92`, global/class/method order, one-definition/source-channel policy, loader-zero physical child, direct Singleton inheritance, generated acceptance, direct-constructor negative retained.
- `by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md`: score `92/94`, remove provisional UID0002X8 text, synchronize four-child physical/semantic dispositions, keep NONE/false/non-emitting.
- `by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md`: synchronize direct Singleton base-constructor interpretation and state that no explicit authored global publication belongs in constructor C++; ordinary score/owner remain `88/91` and UID00008Z. Supervisor command19755 replaced the stale manual `84% : strong` row with the exact accepted `88% : very-strong` payload.
- `by-memory/0x0061fda0-0x0061fe3c.NewCreateUserDialogPaneVtableData.md`: cross-link direct Singleton/global resolution while retaining false/non-emitting compiler support and blank code; ordinary metadata remains `88/92`. Supervisor command19755 replaced the stale `0x0061fe30`, reconstructable, `84% : strong` manual row with the exact accepted endpoint/disposition.
- Lifecycle island [UID:0002QU]: retain false/non-emitting compiler support and ordinary `88/90`; supervisor command19755 applied the exact NewCreateUserDialogPane clear-helper/scalar-destructor Singleton cross-link to its manual coverage description.
- Manual coverage reports: the supervisor-only exact eight-row replacement set below was applied and validated by commands19755-19758; no target/support manual row in that set was a no-op.

## Score And Metadata Recommendation

- Historical pre-callback target: `87/90`, owner/emitter UID0002X7, true, blank code.
- Current callback readback: `92/94`, owner UID0002X7, false, no emitter, blank code.
- Reason not lower: exact range/value/xrefs/lifetime/type/owner/source placement, PE initialization, RTTI/PMD, one-definition route, generated topology, and IDA action are all closed.
- Reason not higher: no original symbols/source prove lexical spelling or initializer token, and 95+ requires extreme final audit rather than ordinary strong research.
- Current callback readback: global `92/94`; class `90/92`; file `89/92`; aggregate `92/94`.
- Support ordinary metadata remains UID0002QS `88/91`, UID0002SJ `88/92` false/non-emitting, and UID0002QU `88/90` false/non-emitting; commands19755-19758 synchronized their manual rows without inflating those ordinary scores.
- Score-improvement attempt: raw name resolved by class/convention; type resolved by RTTI/lifecycle; initializer resolved by PE; source placement resolved by file/class family; emitter duplication resolved through physical/semantic split; class inheritance resolved by PMD/lowering; header channel resolved by by-structure and sibling output; direct constructor route exhaustively checked but remains absent and is retained only as class/file confidence cap.
- Current-IDB score check: live read-only verification against authoritative saved IDB `EEF0C80D8E7E886A573FF7FB93D8BAFEE332FF26C34A7243F7CB9AB3A4A7997B` reproduced A00-A03, all six protected RTTI dependencies, and the lifecycle identities without drift; no score, metadata, owner, emitter, reconstructability, or formal-code recommendation reopens.
- Fields unchanged on target: `CANONICAL_OWNER:0002X7`, blank position, blank CPP/H, `Nested:0`.

## Open Questions With Attempted Resolution

- Is `0xffffffff` a true sentinel? Resolved no. Target has no raw backing, no relocation route, and live zero bytes.
- Is the object a dword or pointer? Resolved pointer from exact publication, vtable/type family, destructor lifecycle, and main-menu dereference/close flow.
- Is publication handwritten? Resolved no for source reconstruction. Direct Singleton RTTI and adjusted-base sequence identify template lowering.
- Does the class inherit Singleton directly? Resolved yes. Decorated descriptor and PMD `620/-1/0` are explicit.
- Which page emits? Resolved: semantic global only; physical page false/non-emitting; class H carries extern/declaration.
- Which initializer token? Best inference `0` from same create-user family. Exact original token cannot be proven, but a raw label or omitted recommendation is less defensible.
- What is the exact original symbol token? Best inference `g_pNewCreateUserDialogPane`; no symbol evidence survives. Class identity, project convention, and existing source-facing usage make this high probability.
- Why no constructor caller? Xrefs, VA/RVA pointers, and direct branch scans are zero. Indirect/removed/retained build routing remains possible. This affects class/file confidence only, not the global's identity or required source declaration.
- Is a complete IDA UDT required? Resolved no. Opaque forward type is sufficient and safer than guessed layout.
- Did the later shared-IDB sequence reopen any target or protected dependency question? Resolved no. The current live read-only check against saved IDB `EEF0C80D...A7997B` reproduced the exact incomplete type, target item/name/type/comments/bytes/xrefs, predecessor/successor state, six protected RTTI descriptors, and lifecycle identities; prior `412DA7E8...519CD` remains only a dated checkpoint.
- No unresolved question remains that blocks target metadata, source owner/emitter, formal C++ disposition, manual coverage text, or IDA handoff.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Historical pre-application manual observation at `2026-07-29T13:52:26-04:00`: `by-memory/-coverage-report.md` SHA256 `BB5E391E0198251142EC7BA4907D524E9ABCC80A5A2DFB0EBA53CE3F93802E20`; `by-global/-coverage-report.md` SHA256 `C8402BC1CF8E639E7A9F75BC94BD9A7F0F17010E1E4FB363775C643440A32D89`; `by-class/-coverage-report.md` SHA256 `EB1ADFEAD1D3702137748D16942EF1AA2A4A39637C24FB9EA1230172B2FA41C5`; `by-file/-coverage-report.md` SHA256 `BDB85AA42D17E235E4C449A520DA2120D609247F0690ADC708B30121E995C83E`. At that dated checkpoint all eight rows were stale; the payloads below preserve the exact proposed text and original stable semantic anchors.
- Applied-and-verified manual closure: command19755 produced by-memory SHA256 `EF11866142A27984E6904BBA1222FB4E0102E7073123A26237791065B43FC795`, 2,091,561 bytes/4,740 lines; command19756 produced by-global SHA256 `522E9096367E7CC1878682E3ECA2275334073EDBECC02C555441D2C5144328E0`, 100,854 bytes/218 lines; command19757 produced by-class SHA256 `2211261E2A7CBD83E7C63B4A63B184EF4F25B12D914C6284D887D1D4413D7F4F`, 271,504 bytes/625 lines; command19758 produced by-file SHA256 `725EBCE55E0FE27347012E27CB888BEB2A49F0E7AFCB72603FDA97967D583770`, 162,435 bytes/317 lines. Each command exited `0` with `ok: 1`, generated refresh disabled, and its supervisor lease released after readback.
- Applied replacement total: exactly eight rows: by-memory UID00029W, UID0002X8, UID0002QS, UID0002SJ, UID0002QU; by-global UID0002X7; by-class UID00008Z; by-file UID0000LP.
- Supervisor-applied [UID:00029W] parent payload, now read back at by-memory line 4655 between UID0001PW and child UID0002X4:

```text
    - [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md) 0x0069b4a4-0x0069b4b4 | global singleton pointer cluster | MainMenuDialogSingletonSlots : ignored : 92% : very-strong : Parentless non-emitting mixed-owner four-slot pre-login dialog singleton index; all four slots are loader-zeroed with exact 6/6/7/20 reference counts, each exact child carries its own semantic owner, and physical UID0002X4/UID0002X8/UID0002XN/UID0002XO remain non-emitting evidence while their semantic globals own the sole source definitions.
```

- Supervisor-applied [UID:0002X8] child payload, now read back at by-memory line 4657 between UID0002X4 and UID0002XN:

```text
        - [UID:0002X8][0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane](by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md) 0x0069b4a8-0x0069b4ac | global pointer storage | g_pNewCreateUserDialogPane : ignored : 92% : very-strong : Exact four-byte loader-zeroed NewCreateUserDialogPane singleton storage; PE virtual-tail/no-relocation proof, six live lifecycle/consumer refs, direct Singleton<NewCreateUserDialogPane> RTTI/PMD at +0x26c, clean neighboring-slot boundaries, and one-definition routing through semantic global [UID:0002X7][g_pNewCreateUserDialogPane](by-global/g_pNewCreateUserDialogPane.md) replace the stale 0xffffffff and duplicate-emitter state.
```

- Supervisor-applied [UID:0002X7] by-global payload, now read back at line 121 between UID0000RR and UID0000RS:

```text
- [UID:0002X7][g_pNewCreateUserDialogPane](by-global/g_pNewCreateUserDialogPane.md) : reconstructable : 92% : very-strong : Sole external-linkage NewCreateUserDialogPane singleton definition in login/NewCreateUserDialogPane.cpp; exact loader-zeroed physical storage UID0002X8, six live publish/clear/consumer refs, direct Singleton<NewCreateUserDialogPane> RTTI/PMD +0x26c cause, matching class-header extern contract, and rejected raw dword/0xffffffff/duplicate-physical-emitter alternatives are documented.
```

- Supervisor-applied [UID:00008Z] by-class payload, now read back at line 347 between UID00008Y and UID000090:

```text
- [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md) : reconstructable : 90% : very-strong : Newer retained create-user dialog class with live constructor/selector/command/submit/packet/reply/vtable/lifecycle evidence, direct DialogPane plus Singleton<NewCreateUserDialogPane> inheritance at PMD +0x26c, complete H-channel class and singleton extern contract, exact method-child routing, shape-control dependency, and preserved no-direct-constructor-route caveat.
```

- Supervisor-applied [UID:0000LP] by-file payload, now read back at line 178 between UID0000LO and UID0000LQ:

```text
- [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) : reconstructable : 89% : very-strong : Concrete NexusTK/login/NewCreateUserDialogPane.cpp source root with sole position-0 singleton definition, direct Singleton-derived class/header contract, exact method and vtable children, zero-initialized physical storage evidence, command/submit/packet/reply and shape-control behavior, compiler-lifecycle exclusions, and retained no-direct-constructor-route caveat.
```

- Supervisor-applied [UID:0002QS] by-memory payload, now read back at line 2678 between UID00043Y and UID0002QT:

```text
        - [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md) 0x0052c360-0x0052dcf5 | executable child | NewCreateUserDialogPaneCore : reconstructable : 88% : very-strong : Exact retained NewCreateUserDialogPane executable cluster with source-ready constructor/selector/command/submit/packet/reply behavior, direct DialogPane plus Singleton<NewCreateUserDialogPane> base-constructor lowering at +0x26c, shape-control and vtable dependencies, explicit policy that Singleton-generated global publication is not authored constructor C++, and the retained no-direct-constructor-route caveat.
```

- Supervisor-applied [UID:0002SJ] by-memory payload, now read back at line 4274 between UID0002SH and UID0002SI:

```text
        - [UID:0002SJ][0x0061fda0-0x0061fe3c.NewCreateUserDialogPaneVtableData](by-memory/0x0061fda0-0x0061fe3c.NewCreateUserDialogPaneVtableData.md) 0x0061fda0-0x0061fe3c | vtable-data | NewCreateUserDialogPaneVtableData : ignored : 88% : very-strong : Exact non-emitting NewCreateUserDialogPane primary/secondary/tertiary vtable and COL support through exclusive end 0x0061fe3c, with constructor/destructor refs, scalar deleting destructor and command/event slots, direct Singleton<NewCreateUserDialogPane> RTTI/PMD +0x26c evidence, and source regeneration through the class H declaration and exact method children rather than raw vtable C++.
```

- Supervisor-applied [UID:0002QU] by-memory payload, now read back at line 2683 between UID00046S and UID0001CS:

```text
        - [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) 0x0052f710-0x0052f94c | lifecycle island | CreateUserDialogDestructorAndThunkIsland : ignored : 88% : strong : Non-emitting singleton clear helpers, adjustor thunks, helper destructors, and scalar deleting destructors for three create-user variants; the NewCreateUserDialogPane branch clears loader-zeroed g_pNewCreateUserDialogPane through the 0x0052f720 Singleton clear helper and 0x0052f89d scalar-destructor store, the NewUserDialogPane2 branch clears its sibling slot at 0x0052f730/0x0052f90d, and all source-authored definitions/declarations/destructor bodies remain on semantic global/class/core pages.
```

- B agent prohibition and closure: B008 did not apply or validate any `-coverage-report.md` file. The supervisor applied these exact rows with commands19755-19758 and verified the final hashes/readbacks recorded above.
- Validator-owned generated tracker/coverage rows must be refreshed through scoped validators, not manually edited.

## Follow-Up Actions

- Historical handoff sequence: the supervisor completed the literal Gate 1 acceptance that authorized this ordinary-document callback. Exact callback defects, if found during Gate 2A, return to this same report and the same eight destinations for repair.
- Callback scope completed by B008: accepted ordinary by-* detail only, using eight short lease/edit/serial-validator/release windows. No generated, manual coverage, IDA, supervisor, goal/notes, or report-lifecycle file was edited.
- Historical Gate 2B handoff is externally complete: supervisor catalog entry `0362` preserved backup `E:/NTK/Resources/NexusTK/backups/NexusTK.exe.pre-B008-UID0002X8-20260729-1412.i64`, applied only A00/A01, verified A02/A03 plus the six individually enumerated RTTI dependencies, and saved historical action-time IDB `3C8F3178...25B69`. B008 performed no IDA mutation. Bounded read-only checks against dated checkpoints `296ED21C...3CF8B`, `905D1AB1...604C1`, and `412DA7E8...519CD`, followed by the current authoritative saved IDB `EEF0C80D...A7997B`, found no target/protected drift.
- Coverage/generated closure: supervisor commands19755-19758 applied and serially validated all eight exact manual coverage replacements, and command19759 refreshed and verified the generated topology described under atomic C051-C055. No coverage/generated callback item remains open. Execution/archive state itself remains authoritative only from the report's current path and validator-owned status/history metadata.
- Historical lifecycle repair cycle: command19760 executed the unreconciled artifact; the mandatory post-move exact-artifact audit rejected its stale coverage prose; command19761 returned the same report to this active path for repair. Those command outcomes are historical facts recorded by the validator-owned footer, not present-tense lifecycle claims.
- A-agent actions: none.
- B008 callback boundary: B008 remained on this same artifact and target throughout the accepted ordinary-document callback.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong; proposed values intentionally stay below 95.
- Remaining uncertainty: exact original lexical spelling/zero token and the constructor's runtime route. These are fully researched current-evidence limits, not deferred investigations and not blockers for the target/global/class topology.

## Validator Results

- Research-pass commands: none; the report-only assignment intentionally excluded validators.
- Research-pass results: not applicable.
- Research-pass validator warnings/errors: none observed because validators were intentionally not invoked.
- Accepted implementation callback validators were run serially from `source-3/project-documentation`, each as `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240 --no-generated-refresh`:
  - UID0002X8 target: command `000000019233`, `2026-07-29T11:46:46-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
  - UID0002X7 global: command `000000019240`, `2026-07-29T11:47:51-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
  - UID00008Z class: command `000000019241`, `2026-07-29T11:48:59-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
  - UID0000LP file: command `000000019242`, `2026-07-29T11:50:15-04:00`, exit `0`, `ok: 1`, generated refresh skipped; validator added two missing UID links without changing the accepted source topology.
  - UID00029W aggregate: command `000000019244`, `2026-07-29T11:51:18-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
  - UID0002QS core: command `000000019246`, `2026-07-29T11:54:04-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
  - UID0002SJ vtable support: command `000000019247`, `2026-07-29T11:55:27-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
  - UID0002QU lifecycle support: command `000000019248`, `2026-07-29T11:56:14-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
- Callback validator summary: eight commands, eight `ok: 1` results, no nonzero exit, no manual coverage validation, and no generated refresh. This scoped validation evidence does not change external execution/archive authority.
- Post-catalog-0362 ordinary reconciliation was also validated serially with generated refresh disabled. Its first pass used commands `000000019367`, `000000019371`, `000000019373`, `000000019382`, `000000019386`, `000000019396`, `000000019402`, and `000000019404`; all exited `0` with `ok: 1`. After the shared IDB advanced again, each destination received one bounded currentness reconciliation and a final serial scoped validator:
  - UID0002X8 target: command `000000019426`, `2026-07-29T14:26:13-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
  - UID0002X7 global: command `000000019429`, `2026-07-29T14:26:38-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
  - UID00008Z class: command `000000019433`, `2026-07-29T14:27:08-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
  - UID0000LP file: command `000000019437`, `2026-07-29T14:27:39-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
  - UID00029W aggregate: command `000000019443`, `2026-07-29T14:28:13-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
  - UID0002QS core: command `000000019456`, `2026-07-29T14:28:41-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
  - UID0002SJ vtable support: command `000000019467`, `2026-07-29T14:29:12-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
  - UID0002QU lifecycle support: command `000000019476`, `2026-07-29T14:29:44-04:00`, exit `0`, `ok: 1`, generated refresh skipped.
- Final post-IDA reconciliation validator summary: eight final commands, eight exit-`0`/`ok: 1` results, all leases released, no generated refresh, and no manual coverage, IDA, audit/catalog, or report-lifecycle command.
- After the unrelated shared-IDB advance to the now-historical `905D1AB1...604C1` checkpoint, the bounded no-drift currentness reconciliation was validated serially with the same command shape and generated refresh disabled:
  - UID0002X8 target: command `000000019517`, `2026-07-29T14:47:18-04:00`, exit `0`, `ok: 1`.
  - UID0002X7 global: command `000000019519`, `2026-07-29T14:47:51-04:00`, exit `0`, `ok: 1`.
  - UID00008Z class: command `000000019522`, `2026-07-29T14:48:22-04:00`, exit `0`, `ok: 1`.
  - UID0000LP file: command `000000019525`, `2026-07-29T14:48:54-04:00`, exit `0`, `ok: 1`.
  - UID00029W aggregate: command `000000019529`, `2026-07-29T14:49:28-04:00`, exit `0`, `ok: 1`.
  - UID0002QS core: command `000000019532`, `2026-07-29T14:50:00-04:00`, exit `0`, `ok: 1`.
  - UID0002SJ vtable support: command `000000019535`, `2026-07-29T14:50:32-04:00`, exit `0`, `ok: 1`.
  - UID0002QU lifecycle support: command `000000019538`, `2026-07-29T14:51:06-04:00`, exit `0`, `ok: 1`.
- Historical `905D1AB1...604C1` checkpoint reconciliation summary: eight exit-`0`/`ok: 1` results, all leases released immediately, generated refresh skipped, and no manual coverage, generated-file, IDA, audit/catalog, or report-lifecycle action.
- After the unrelated supervisor UID0002MZ Gate 2B advance to the then-current, now-historical saved IDB checkpoint `412DA7E8...519CD`, B008 performed another bounded target/protected no-drift readback and reconciled the same eight ordinary destinations. Serial validators used the same command shape with generated refresh disabled:
  - UID0002X8 target: command `000000019648`, `2026-07-29T15:03:24-04:00`, exit `0`, `ok: 1`.
  - UID0002X7 global: command `000000019649`, `2026-07-29T15:04:03-04:00`, exit `0`, `ok: 1`.
  - UID00008Z class: command `000000019651`, `2026-07-29T15:04:35-04:00`, exit `0`, `ok: 1`.
  - UID0000LP file: command `000000019657`, `2026-07-29T15:06:11-04:00`, exit `0`, `ok: 1`.
  - UID00029W aggregate: command `000000019660`, `2026-07-29T15:06:57-04:00`, exit `0`, `ok: 1`.
  - UID0002QS core: command `000000019666`, `2026-07-29T15:07:31-04:00`, exit `0`, `ok: 1`.
  - UID0002SJ vtable support: command `000000019670`, `2026-07-29T15:08:04-04:00`, exit `0`, `ok: 1`.
  - UID0002QU lifecycle support: command `000000019672`, `2026-07-29T15:08:40-04:00`, exit `0`, `ok: 1`.
- Historical `412DA7E8...519CD` checkpoint reconciliation summary: eight exit-`0`/`ok: 1` results, all leases released immediately, generated refresh skipped, and no manual coverage, generated-file, IDA, audit/catalog, or report-lifecycle action. The later report-only live verification against current authoritative saved IDB `EEF0C80D...A7997B` found no target/protected drift and required no ordinary-document validation.
- Supervisor manual-coverage closure, performed outside B008's callback edits:
  - command `000000019755` validated `by-memory/-coverage-report.md`, exit `0`, `ok: 1`, generated refresh disabled; final SHA256 `EF11866142A27984E6904BBA1222FB4E0102E7073123A26237791065B43FC795`.
  - command `000000019756` validated `by-global/-coverage-report.md`, exit `0`, `ok: 1`, generated refresh disabled; final SHA256 `522E9096367E7CC1878682E3ECA2275334073EDBECC02C555441D2C5144328E0`.
  - command `000000019757` validated `by-class/-coverage-report.md`, exit `0`, `ok: 1`, generated refresh disabled; final SHA256 `2211261E2A7CBD83E7C63B4A63B184EF4F25B12D914C6284D887D1D4413D7F4F`.
  - command `000000019758` validated `by-file/-coverage-report.md`, exit `0`, `ok: 1`, generated refresh disabled; final SHA256 `725EBCE55E0FE27347012E27CB888BEB2A49F0E7AFCB72603FDA97967D583770`.
- Supervisor generated closure: command `000000019759`, `2026-07-29T16:10:35-04:00`, exit `0`, `ok: 1`, generated refresh completed and registry rebuilt. It produced current generated memory coverage SHA256 `ED4D13CBD9770A1927290A2E03C89CBA66D9231C4D61F82EE9E6817F5101A05F`, CPP SHA256 `4CB8A20A7DC4D978567A2D0C665D2274D0B6C0EFE805BE8E900EFBCD1A0F684D`, and H SHA256 `F88C60C8244850D4E60305091CEF6F44CD5B2329AF20DBE98F9907D7A2954226`. B008 did not run these commands.
- Validator-owned lifecycle history records command19760 execution and command19761 de-execution-for-rework. Those lifecycle commands are historical external events and are not validator evidence produced by B008.

## Changed Files

- Research-pass artifact created: `tools/leaser/Agents/Agent-B008/research/0002X8-g_pNewCreateUserDialogPane-source-quality.md`.
- Historical research-pass external files modified: none.
- Accepted callback plus post-catalog and dated shared-IDB checkpoint reconciliations changed ordinary files and produced these exact final post-validator identities; the later current `EEF0C80D...A7997B` verification was report-only and changed no ordinary destination:
  - `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md`: SHA256 `E7A3423B0CFCBDB742A077BAE3E13D925657F8915786C79883C0AF447D3ED77F`, 14,650 bytes/119 lines.
  - `by-global/g_pNewCreateUserDialogPane.md`: SHA256 `C64F34AC6F73850855CCF5A5D399F536C8BDCB37EA8BB239BCE83998D7DF8726`, 12,229 bytes/100 lines.
  - `by-class/NewCreateUserDialogPane.md`: SHA256 `CCA7F289505EEE171060C29F9865F4C982579309EC52FD2F62FC18B25E1E252B`, 21,880 bytes/165 lines.
  - `by-file/NewCreateUserDialogPane.md`: SHA256 `710D5C872CD945E1AD276A89335D8C19CF9E9871A51CBB55AEEE9A1FF77CF113`, 19,467 bytes/130 lines.
  - `by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md`: SHA256 `6AC40B148C1DF29D6206081CD8369DA13EAA3DAD768CD333B25F0E1E45D186CC`, 27,130 bytes/163 lines.
  - `by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md`: SHA256 `3FEEF5746F75D37607A052FC5288A4B452E84835684AB022E0A24007DFC4448D`, 30,372 bytes/292 lines.
  - `by-memory/0x0061fda0-0x0061fe3c.NewCreateUserDialogPaneVtableData.md`: SHA256 `67121D0BF24DEC1A34926459DEF2FE6C0E9EC4C01153030EBAA6B03D28B2DBE2`, 20,599 bytes/134 lines.
  - `by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md`: SHA256 `ED40C250321AA4B237D739317B3979287D6E4716B35B58E4384F6D2B544ED6A5`, 27,254 bytes/177 lines.
- Supervisor-only manual coverage closure changed four shared coverage files after the B008 callback: `by-memory/-coverage-report.md` SHA256 `EF11866142A27984E6904BBA1222FB4E0102E7073123A26237791065B43FC795`; `by-global/-coverage-report.md` SHA256 `522E9096367E7CC1878682E3ECA2275334073EDBECC02C555441D2C5144328E0`; `by-class/-coverage-report.md` SHA256 `2211261E2A7CBD83E7C63B4A63B184EF4F25B12D914C6284D887D1D4413D7F4F`; `by-file/-coverage-report.md` SHA256 `725EBCE55E0FE27347012E27CB888BEB2A49F0E7AFCB72603FDA97967D583770`. B008 did not edit or validate these files.
- Supervisor command19759 refreshed shared generated artifacts: `auto-generated/-ag-memory-coverage.md` SHA256 `ED4D13CBD9770A1927290A2E03C89CBA66D9231C4D61F82EE9E6817F5101A05F`; `auto-generated/NexusTK/login/NewCreateUserDialogPane.cpp` SHA256 `4CB8A20A7DC4D978567A2D0C665D2274D0B6C0EFE805BE8E900EFBCD1A0F684D`; and `auto-generated/NexusTK/login/NewCreateUserDialogPane.h` SHA256 `F88C60C8244850D4E60305091CEF6F44CD5B2329AF20DBE98F9907D7A2954226`. Command19761 later refreshed `auto-generated/-ag-research-tracker.md` to SHA256 `D0FC00F7CA525A658CFBFCE08E95ECA13B07E9120B5DDE73B401DA23BB4FDD7F`; lifecycle fields remain path/history owned. B008 did not edit generated artifacts.
- Lease record: B008 acquired each ordinary destination only immediately before its edit/validator batch, released each lease immediately afterward, and physical shared-lease readback contains no active B008 lease.
- Research-pass files renamed: none.
- Lifecycle boundary: B008 did not probe or invoke `execute_report`, any equivalent report-lifecycle command, registry repair, or archive movement. Current execution/archive truth is external and authoritative only from the report's actual path plus validator-owned status/history metadata.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation: exact accepted report SHA `93867800931F020DC3C877EA48BC10FC2620F45E0D782B25C57CCDE1CA97DDFB` passed Gate 1 and received this callback.
- [x] Target/support docs updated: target UID0002X8; global UID0002X7; class UID00008Z; file UID0000LP; aggregate UID00029W; core UID0002QS; vtable UID0002SJ; lifecycle UID0002QU.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: not applicable; no additional UID is declared.
- [x] Historical pre-action state recorded against `0E0AF938...AB481`; catalog entry `0362` action/readback recorded at `3C8F3178...25B69`; dated `296ED21C...3CF8B`, `905D1AB1...604C1`, and `412DA7E8...519CD` checkpoints retained; current target/protected no-drift checked live and read-only against authoritative saved IDB SHA256 `EEF0C80D8E7E886A573FF7FB93D8BAFEE332FF26C34A7243F7CB9AB3A4A7997B`.
- [x] Claim And Incorporation Ledger C001-C073 atomized with literal UID/path/section destinations and truthful callback verification states.
- [x] Metadata/score changes applied: target `92/94`; global `92/94`; class `90/92`; file `89/92`; aggregate `92/94`; three support scores retained.
- [x] Score-limiting blockers researched to resolution or exact rare evidence-backed limit: all target blockers resolved; constructor reachability exhaustively negative and affects only class/file cap.
- [x] Owner/emitter/reconstructable changes applied: target false/non-emitting; global sole position-0 emitter; class H position 10.
- [x] Split/rename/new-child disposition applied: no split/new child; source-facing canonical global used in ordinary docs; literal historical IDA prestate and exact catalog/current poststate are both preserved.
- [x] Source-placement, range/split/padding/reclassification, and IDA closure: all ordinary-document components are applied; supervisor catalog entry `0362` externally applied/verified A00/A01 and protected A02/A03 plus all six RTTI dependencies.
- [x] Supervisor Gate 2B handoff reconciled from external evidence: A00/A01 applied and read back; A02/A03 and six protected read-only RTTI dependencies unchanged; action-time and moving shared-IDB identities distinguished. B008 performed no IDA mutation/save.
- [x] First-draft CPP/H dispositions applied: target blank; global exact CPP; global H blank; class CPP blank; class exact H.
- [x] Third-party import directive: not applicable.
- [x] Exact target/support facts incorporated at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Wave2/Wave3 artifacts ignored as stale.
- [x] Open questions closed or recorded with exhaustive negative evidence.
- [x] Scoped validators run serially for every changed ordinary doc.
- [x] Exactly eight manual supervisor-owned coverage replacements verified: five by-memory plus by-global/by-class/by-file, applied by commands19755-19758 with exact final hashes/readbacks; B008 did not edit or validate coverage.

Implementation callback pass:
- [x] Supervisor-owned IDA closure was never performed by B008; its externally supplied catalog-0362 disposition, backup/save proof, exact readback, dated `296ED21C...3CF8B`/`905D1AB1...604C1`/`412DA7E8...519CD` checkpoints, and current authoritative `EEF0C80D...A7997B` no-drift state are reconciled claim by claim.
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support details incorporated without summarizing away evidence.
- [x] Primary UID0002X8 and every support destination independently checked against atomized C001-C073.
- [x] Ledger verification states updated only after physical destination readback.
- [x] Metadata/score/owner/emitter/reconstructable/CPP/H changes applied exactly.
- [x] Historical assumptions and negative evidence preserved.
- [x] Open-question results incorporated.
- [x] Validators run serially and exact command IDs/results recorded.
- [x] Generated CPP/H, memory coverage, registry, and tracker topology physically verified at supervisor command `000000019759`; command19761's later tracker refresh is recorded separately as lifecycle-owned currentness.
- [x] Remaining external accepted items listed with exact ownership: no ordinary, IDA, manual-coverage, or generated-closure implementation item remains open; report lifecycle remains supervisor/validator-owned state.
- [x] Report body remains lifecycle-neutral: execution/archive truth is determined by the current path and validator-owned status/history metadata, and no body/checklist sentence becomes false solely because the supervisor executes, invalidates, or archives the report.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000019760","destination_path":"executed-b-agent-research/B008/0002X8-g_pNewCreateUserDialogPane-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0002X8-g_pNewCreateUserDialogPane-source-quality.md","timestamp":"2026-07-29T16:12:18-04:00","uid":"0002X8"} -->
<!-- {"agent":"B008","command_id":"000000019761","destination_path":"tools/leaser/Agents/Agent-B008/research/0002X8-g_pNewCreateUserDialogPane-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B008/0002X8-g_pNewCreateUserDialogPane-source-quality.md","timestamp":"2026-07-29T16:13:57-04:00","uid":"0002X8"} -->
<!-- {"agent":"B008","command_id":"000000019779","destination_path":"executed-b-agent-research/B008/0002X8-g_pNewCreateUserDialogPane-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0002X8-g_pNewCreateUserDialogPane-source-quality.md","timestamp":"2026-07-29T16:49:51-04:00","uid":"0002X8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
