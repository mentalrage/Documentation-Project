** TARGET-REPORT-UID:0001OS **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001OS g_pLanguageMan Ownership / Split Research


## Finalized Report / Current Recommendation

- Current recommendation and implemented state: [UID:0001OS] `0x0067a750-0x0067a754` is exact binary backing storage for the `LanguageMan` singleton, while semantic global [UID:0000RC] owns the sole handwritten, externally linked pointer definition.
- Final disposition applied: UID0001OS is `92/94`, retains canonical semantic owner `0000RC`, is `RECONSTRUCTABLE:FALSE`, has blank emitter/position/formal C++, and retains `Nested:0`. UID0000RC is `92/94`, retains owner/emitter `0000KK`, uses position `0`, and emits Destination 2 as the sole `LanguageMan.cpp` module definition. The matching external declaration remains separate future proper header/class placement and is not emitted by the by-global source block.
- Source-shape correction applied: constructor publication, ordinary-destructor clear, 11-byte unwind clear, and scalar-wrapper clear are documented as manifestations of the RTTI-proven direct `Singleton<LanguageMan>` base. UID00041V and UID00018S no longer contain explicit singleton assignment/clear statements; UID00040R and UID00018V are compiler-only non-emitting pages.
- Support synchronization applied: the LanguageMan class/file/aggregate/helper/vtable pages now preserve the direct-base, one-definition, source/compiler, canonical-name, lifecycle, and generated-output facts below. The incomplete class formal remains blank because the otherwise unused `+0x0c-+0x28` object tail still has no evidence-backed human member names; that independent class declaration cap does not block the exact global definition.
- Confidence: very strong for exact storage, type, external linkage, direct Singleton base, all five lifetime writes/clears, 192-reference fanout, owner/file placement, and no-duplicate policy; strong for original lexical spelling and null-literal style.
- Current phase: B005 implementation callback and bounded C10 Gate 2 repair complete. The two C10 destinations now include the full Application shutdown read/check/flag-1/virtual-delete route, all scoped validators and the waited refresh passed, manual coverage stayed read-only, and supervisor Gate 2/execution remain external lifecycle state.

## Supporting Research

### Current project evidence read

- Target [UID:0001OS], semantic global [UID:0000RC], class [UID:000071], ignored alias [UID:000072], file [UID:0000KK], exact constructor [UID:00041V], ordinary destructor [UID:00018S], adjacent zero helper [UID:00018T], helper aggregate [UID:00018U], exact clear helper [UID:00040R], scalar wrapper [UID:00018V], vtable [UID:00040W], parser constants [UID:00040V], string literals [UID:00040X], and broader LanguageMan island [UID:00018R] were read from the canonical tree.
- Historical generated checkpoints include command `000000015346`, initial callback command `000000015406`, and external command `000000015414` with their hashes recorded in the callback history below. The C10 repair's authorized waited refresh is command `000000015419`, refreshed `2026-07-20T16:00:18-04:00`, SHA256 `A18C81A9CEF8E62A6FED7A46A7607D6747BA1FD16514F892A0D90292EFE6BAA9`, 4,206 bytes / 120 lines; every accepted LanguageMan structural assertion remains unchanged.
- Historical tracker checkpoints `000000015362`/`15369` recorded the pre-callback target, command `15407` recorded the first callback, and external command `15414` advanced only mutable headers. The C10 repair checkpoint is command `000000015419`, refreshed `2026-07-20T16:00:18-04:00`, SHA256 `45FD1B3E9582E71DAA052A046E88AAD6ED51B92BDC19159B65E600A5F589E831`, 1,531,696 bytes / 6,206 lines. It retains UID0001OS `92/94`, false; UID0000RC and UID00041V `92/94`, true; UID00018S `92/94`, true; UID00040R/UID00040W `90/94`, false; and UID00018V `91/94`, false. These command/header facts are time-bounded readback, while the ordinary implementation claims are durable.
- Manual reports were reread without editing after the external refresh: by-memory SHA256 `168E33F401270E2AA8B3138F1914EF4CA957263232F4B36737A3F67CED4413D2`, 1,860,404 bytes / 4,410 lines; by-global `4F96E6C2DE7E9BDCDEA2537579EF1D2CE1C0884E421B1D29D23757A8913BD97D`, 90,566 / 213; by-class `9EDFCA643DA82EF52EAC66466184DCA99C3F5A7B4D1A464C9141D926357C3570`, 240,757 / 623; by-file `D8A687733F5A3C3DD9FC931A3B0C14CB439B20325BB044922A9DE4B956352D66`, 138,194 / 316. The by-memory delta contains unrelated external additions; all exact LanguageMan rows remain the same stale pre-handoff rows quoted below. The exact eleven-action handoff remains unapplied and supervisor-owned.

### Prior-report search record

- Exact terms searched: `0001OS`, `UID0001OS`, `0x0067a750`, `g_pLanguageMan`, `dword_67A750`, `0000RC`, `LanguageMan`, `LanguageManager`, `Singleton<LanguageMan>`, `0x004f0010`, `0x004f0290`, `0x004f03c0`, `0x004f03d0`, `str.res`, and `localization singleton`.
- Roots searched: central `executed-b-agent-research`; active `tools/leaser/Agents/Agent-B*/research`; legacy `tools/leaser/Agents/Older-Research`; and relevant `archived` roots. The active, Older-Research, and archived roots yielded no direct UID0001OS report. All exact UID/address candidates below were opened from the central executed root.

| Opened report | Classification | Current finding used here |
| --- | --- | --- |
| `executed-b-agent-research/B002/00018V-LanguageManScalarDeletingDestructor-source-quality.md` | direct family support; executed; partly superseded | Exact `0xa7` wrapper, vtable-only reachability, `0x2c` size path, and helper identities remain useful. Its source-body clear interpretation predates the direct Singleton PMD proof and is superseded. |
| `executed-b-agent-research/B007/00018U-LanguageManLookupAndSingletonHelpers-source-quality.md` | direct helper support; executed; partly superseded | Exact helper boundaries, 192 singleton refs, and canonical LanguageMan name remain useful. Its 11-byte handwritten static-helper recommendation is superseded by direct Singleton EH evidence. |
| `executed-b-agent-research/B012/00018R-LanguageManLocalization-source-quality.md` | direct family aggregate; executed; partly superseded | Exact constructor split, parser behavior, file route, and child inventory remain current. Its explicit constructor publication source line predates the direct-base correction. |
| `executed-b-agent-research/B015/00018S-LanguageManCleanupDestructor-source-quality.md` | direct destructor support; executed; partly superseded | Exact destructor body, stale Boost-name rejection, and helper identities remain current. Its explicit ordinary-destructor clear conclusion is superseded by direct Singleton base destruction. |
| `executed-b-agent-research/B001/00018T-LocalizationAdjacentZeroInitializer.md` | direct adjacent-family support; executed; current for negative layout evidence | Confirms the seven-store helper has no caller/callee/xref route and does not prove LanguageMan tail fields. |
| `executed-b-agent-research/B013/00018U-LanguageManLookupAndSingletonHelpers-source-quality.md` | direct helper support; executed; superseded on split/emission | Useful exported-data corroboration and no-LanguageManager finding; its aggregate/static-clear emission plan is superseded by exact children and direct-base evidence. |
| `executed-b-agent-research/B011/00028L-g_pEventMan-source-quality.md` | adjacent singleton precedent; executed; current as a comparison only | Confirms the next four-byte boundary and 210 refs, but its target-owned global definition pattern is weaker than the newer semantic-global/backing-storage split used by MessageShowPane. |
| `executed-b-agent-research/B002/0002SW-iconspane-constructor-source-quality.md` | incidental consumer | Uses UID0001OS as localization support only; no lifetime or owner override. |
| `executed-b-agent-research/B002/0002US-ConfirmDeleteAlertRawConstructor-source-quality.md` | incidental consumer with useful xref confirmation | Confirms 192 refs, zero storage, canonical global name, and several exact prompt reads. |
| `executed-b-agent-research/B007/0001M0-TakeOffInputPaneRawConstructor-source-quality.md` | incidental consumer | Adds a prompt lookup consumer only. |
| `executed-b-agent-research/B009/00004B-EmotionInputPane-class-source-quality.md` | incidental consumer | Confirms EmotionInputPane localization reads and canonical global spelling. |
| `executed-b-agent-research/B012/0001KT-QuitDialogCore-source-quality.md` | incidental consumer | Uses the singleton for localized prompt construction; no owner override. |

The additional exact-address-only reports were also opened and classified as incidental consumers or neighbor-boundary evidence: `B001/000043-DropGoldInputPane-class-source-quality.md`, `B001/0001OR-g_pCollectionData-source-quality.md`, `B002/0000Z0-0002M4-0002M2-blackhole-deferred-deletion-source-quality.md`, `B002/0001CT-nexonclub-registration-dialog-source-quality.md`, `B002/0002N8-SelfSaveInputPaneVtableData-source-quality.md`, `B004/0001AY-SelfSaveOKPaneFactory-source-quality.md`, `B005/0003O5-SelfSaveInputPaneConstructorRaw-source-quality.md`, `B006/000138-EmployeeDialogPanes-source-quality.md`, `B006/0004B6-PowerListPaneOnMouseEvent-by-memory-source-quality.md`, `B009/0000JP-GameServerConfig-empty-emitter-family-source-quality.md`, `B010/00019J-CloseMainMenuDialogSingletons-source-quality.md`, `B011/0000HR-BlackHole-empty-emitter-family-source-quality.md`, `B012/0001KQ-SelfSaveInputPaneFactory-source-quality.md`, `B013/0001KS-QuitInputPaneCore-source-quality.md`, `B014/000039-CopyWindow-class-source-quality.md`, and `B015/00005T-GiveGoldInputPane-class-source-quality.md`. They add representative consumers or predecessor/successor facts but no conflicting type, owner, source file, or lifetime model.

Evidence-based conclusion: no prior direct target-specific UID0001OS / `g_pLanguageMan` source-quality report exists. Prior LanguageMan reports are support evidence and contain the now-correctable source/compiler-lifetime assumption; this report is the first direct storage/global one-definition audit.

## Target

- Target UID: `0001OS`.
- Target path: `by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md`.
- Historical source queue/report row: `by-memory` -> `Not-Covered Files - Reconstructable`, `86/90`, average `88.0`, reconstructable true before this callback.
- Current supervisor classification: implemented direct source-quality correction of an exact singleton-storage page.
- Current scores and parent state: `92/94`, canonical semantic owner `0000RC`, reconstructable false, blank emitter/position/formal C++, `Nested:0`.

## Current Target State

- Implemented metadata preserves the exact one-dword range and semantic parent while preventing duplicate source emission from the backing-storage page.
- Implemented prose preserves zero storage, 192 xrefs, five lifetime writes/clears, canonical `LanguageMan`, lookup/resource consumers, and clean singleton neighbors at report-level detail.
- UID0000RC now emits the complete forward-declared pointer definition without depending on a complete LanguageMan object layout.
- Constructor/destructor documentation and formals now classify publication/clear as direct `Singleton<LanguageMan>` base lowering at PMD `mdisp=4`; the constructor `this+4` / `-4` sequence is no longer misrepresented as handwritten source.
- UID00040R is false/non-emitting compiler unwind cleanup with blank formal; its exact 11-byte body, one constructor-EH reference, and no ordinary caller remain documented.
- UID00018V is false/non-emitting compiler scalar-wrapper output with blank formal; its vtable-only route, duplicate cleanup/base teardown, flags, size guard, and free behavior remain documented.
- Current artifact status: callback implementation and C10 repair complete, all C01-C40 states terminal, all ordinary leases released, generated output reverified, and exact manual coverage handoff retained for supervisor-owned external application.

## Executive Recommendation

- [UID:0000RC] is now the sole source-bearing semantic global and [UID:0001OS] is non-emitting exact backing-storage evidence.
- Keep external linkage because localization consumers exist throughout Application, RegistryConfig, UserPane, dialog, prompt, scanner, and other source families.
- The semantic definition emits at position `0` in `NexusTK/localization/LanguageMan.cpp` before constructor/method children.
- Model the source class direction as `LanguageMan` with direct `LObject` and `Singleton<LanguageMan>` bases. Do not preserve `LanguageManager` as a separate original class.
- Direct Singleton publication/clear statements are absent from handwritten constructor/destructor bodies; UID00040R and UID00018V source output is blank and documented as EH/scalar compiler manifestations.
- The LanguageMan class formal remains blank because complete size `0x2c` is proved while human field identities for `+0x0c-+0x28` are not. This is a separate complete-class declaration blocker, not a blocker on the source module's forward declaration, sole pointer definition, or exact type/linkage; the matching header external declaration remains separate future proper header/class placement.

## Supervisor Active Recheck

- The accepted callback applied the direct UID0001OS research, source-correct module definition separated from its future header declaration, canonical-name closure, every lifetime route, support synchronization, exact formals, and score-blocker resolution.
- No target split or child allocation is needed: the target is one exact four-byte storage slot with clean adjacent singleton boundaries.
- Every source-bearing destination in this report has the exact managed C++ applied below. Every compiler/backing-storage destination retains its exact blank managed block and explicit no-code proof.
- No consumer, cleanup route, source placement, owner, type, linkage, or duplicate-definition question is deferred.

## Inference Research Guidance Check

- IDA fact, documentation evidence, and inference are separated throughout this report. Addresses, bytes, xrefs, RTTI structures, function sizes, vtable references, and decompilation are IDA facts. Current by-* contents and executed reports are documentation evidence. Source-era spelling, null literal, and header/file organization are inference.
- Existing names were treated as hypotheses. `LanguageMan` is retained because RTTI exposes that exact class and `Singleton<LanguageMan>` while no `LanguageManager` RTTI/name exists. Raw `dword_67A750` and polluted Boost destructor names are rejected as source names.
- Existing static-helper and explicit-lifecycle statements were not trusted merely because they had accepted formal blocks; fresh base-hierarchy evidence changes their source/compiler disposition.
- Wave2/Wave3 and `simroot_v2` references were encountered only as historical search leads. They were not used as current authority and do not override live MCP or current documentation.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence and resolution | Status / impact |
| --- | --- | --- |
| `LanguageMan` versus `LanguageManager` | Current `entity_query` returns ten LanguageMan/Singleton names at `0x006498c0-0x00649944` and `0x00676efc/0x00676f18`, with no LanguageManager result. | `LanguageMan` is canonical; LanguageManager remains an ignored historical generated alias. |
| Pointer type | Every lifetime site stores a complete object pointer and lookup/destructor code interprets offsets from that object. | Exact source type is pointer to LanguageMan, not pointer to the string table or alias class. |
| Constructor publication | Bytes at `0x004f0055` form `lea this+4`, null test, then `add -4` before the store. Singleton BCD PMD is `mdisp=4`, `pdisp=-1`, `vdisp=0`, attributes `0x40`. | Compiler lowering for direct empty Singleton base; remove handwritten assignment from constructor C++. |
| Ordinary destructor clear | UID00018S restores LanguageMan vptr, frees authored fields, clears the global, then calls LObject destructor. Reverse direct-base teardown explains the clear. | Authored destructor retains only string-table frees; Singleton clear is implicit. |
| `0x004f03c0` clear helper | Exact `c7 05 50 a7 67 00 00 00 00 00 c3`, one EH xref at `0x00600a64` inside constructor metadata, no caller/callee/state beyond clear. | Compiler constructor-unwind cleanup; false/non-emitting with blank C++. |
| Scalar deleting destructor | One vtable data ref, no direct code caller, duplicate cleanup and Singleton/LObject teardown, delete flags, `0x2c` size path. | Compiler wrapper; false/non-emitting with blank C++. |
| Vtable bytes | Exact COL/vtable, three stores from ctor/dtor/scalar, scalar wrapper slot plus inherited LObject slots. | Compiler-generated from declarations; false/non-emitting, no handwritten vtable array. |
| External versus file-static linkage | 187 non-lifecycle reads occur across many source files, not only LanguageMan.cpp. | External linkage required; file-static rejected. |
| Semantic global versus exact storage emitter | A semantic by-global page already exists and routes through LanguageMan.cpp. Newer MessageShowPane precedent emits once from semantic global and leaves exact storage blank. | UID0000RC emits once; UID0001OS becomes false/non-emitting to prevent duplicate C++. |
| Global module definition without complete class | A pointer definition in `LanguageMan.cpp` requires only a local class forward declaration; it does not require object layout. The matching external declaration belongs to future proper header/class output and is not emitted by Destination 2. | Global blocker closed now; broader class formal and header declaration placement remain independently separate. |
| Complete LanguageMan class declaration | Allocation/delete-size evidence proves `0x2c`; methods prove fields at `+4` and `+8`; no current consumer gives source identities for `+0x0c-+0x28`; UID00018T has no route proving those fields. | Do not invent reserved arrays or opaque layout placeholders. Class stays `89/92`, formal blank, with direct-base evidence added in prose. |
| Adjacent storage boundaries | `0x0067a740-0x0067a75f` are zero; predecessor `0x0067a74c` has 72 refs, target `0x0067a750` has 192, successor `0x0067a754` has 210. | No merge, extension, padding, or child split. |
| Original lexical form | Existing project sources use both `0` and `NULL`; current LanguageMan formals use `0`. | Use `0` in Destination 2; lexical confidence remains capped below 95. |

Rejected alternatives:

- A second source definition on UID0001OS: rejected as duplicate/ODR-invalid because UID0000RC is the semantic global emitter.
- Keep UID0001OS reconstructable merely because bytes exist: rejected because the source module definition is represented once by UID0000RC; the memory page is evidence-only backing storage.
- Emit the pointer from the class page: rejected because the semantic global page is the dedicated owner and the class formal remains incomplete.
- Keep explicit assignment/clear statements for readability: rejected because they duplicate direct Singleton base behavior and misstate original source shape.
- Keep UID00040R as a source helper: rejected by its sole constructor-unwind xref and exact direct-base cleanup role.
- Keep UID00018V as a covered-by comment emitter: rejected because the compiler regenerates the wrapper from the virtual destructor/class declaration; no wrapper declaration exists in human source.
- Call the class LanguageManager: rejected by exact RTTI and lack of a separate allocation, vtable, type descriptor, or singleton.
- Infer LanguageMan tail fields from UID00018T: rejected because that helper is unreferenced and has no object/class route.
- Make the pointer file-static: rejected by cross-source consumers.
- Emit raw address, vptr, PMD, adjustor, delete flags, EH helper, or vtable arrays: rejected as binary/compiler scaffolding.

## Evidence Standards Used

- Primary evidence: fresh live IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `xrefs_to`, `entity_query`, `decompile`, and `analyze_function` against active database `9b0396a3`.
- Corroboration: current ordinary docs, evidence-time generated source/tracker checkpoints, manual coverage checkpoints, executed direct-family reports, adjacent singleton precedent, and the newer MessageShowPane direct-Singleton one-definition model.
- Evidence ladder: exact bytes and xrefs establish the storage/lifetime facts; RTTI hierarchy and PMD establish source inheritance; constructor/destructor lowering establishes source/compiler separation; cross-file consumer grouping establishes linkage; project owner/docs establish source placement.
- Remaining uncertainty is lexical, not behavioral: original header name, whitespace, and `0` versus `NULL` cannot be recovered from the binary. Those caps justify `94`, not blank C++.

## Evidence Checked

- At `2026-07-20T14:49:48-04:00`, fresh `idb_list` returned active/adopted session `9b0396a3` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `15732`, `is_analyzing:false`. `server_health` returned `status:ok`, imagebase `0x400000`, and auto-analysis/Hex-Rays/string cache ready.
- `get_bytes` checked `0x004f0050` (48 bytes), `0x004f02e8` (32), `0x004f03c0` (11), `0x004f0425` (32), and `0x0067a740` (32). The exact publication/clear opcodes and all-zero singleton neighborhood were returned successfully.
- `lookup_funcs` checked `0x004f0010`, `0x004f0290`, `0x004f0310`, `0x004f0350`, `0x004f0380`, `0x004f03c0`, `0x004f03d0`, and the startup/cleanup callsites. Exact sizes are recorded below.
- `xrefs_to` checked target, predecessor, successor, vtable, constructor, destructor, EH clear, and scalar wrapper. Target count is 192; vtable refs are exactly three; constructor has one direct caller; destructor has none; EH clear has one constructor metadata ref; scalar has one vtable ref.
- `entity_query(kind=names, regex=LanguageMan|LanguageManager)` returned ten LanguageMan/Singleton names and no LanguageManager name.
- Bounded RTTI bytes at `0x006498c0` and type-descriptor bytes at `0x00676efc` were read. They decode the three-base LanguageMan hierarchy and the Singleton PMD described below.
- Constructor, ordinary destructor, and application cleanup were decompiled with line addresses. These checks closed publication, reverse clear, startup allocation, and virtual deletion routes.
- Current by-* docs, exact report searches, evidence-time generated source/tracker, and all four relevant manual coverage checkpoints were read as listed under Supporting Research.
- During implementation, all eleven ordinary destinations were reread after lease acquisition, edited at same-or-greater detail, scoped-validated, and immediately released. The final waited refresh and independent generated/tracker/manual readbacks are recorded below.
- Negative checks: no second storage definition, no LanguageManager RTTI/allocation/vtable, no direct call to ordinary destructor, no ordinary call to UID00040R, no direct code call to scalar wrapper, no write outside five lifetime refs, no evidence attaching UID00018T to LanguageMan tail fields, and no range overlap with adjacent singleton slots.
- Failed/unavailable checks: none. No broad whole-image text scan was needed; all MCP requests were bounded and succeeded. No IDA mutation was performed.

## Claim And Incorporation Ledger

| Claim ID | Atomic claim | Confidence | Evidence | Destination | Action | Verification State |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0001OS is exactly `0x0067a750-0x0067a754`, four bytes. | certain | target bytes/boundaries | target | already-present | already-present |
| C02 | The slot is zero-initialized in the current IDB. | certain | `get_bytes 0x0067a740` | target/global | already-present | already-present |
| C03 | The target has exactly 192 direct data xrefs. | certain | current `xrefs_to` | target/global | incorporate | applied |
| C04 | Exactly five refs are lifetime writes/clears and the remaining 187 are reads. | certain | full xref classification | target/global | incorporate | applied |
| C05 | Constructor stores at `0x004f0066` and fallback-clears at `0x004f006d`. | certain | bytes/decompile | target/UID00041V | incorporate | applied |
| C06 | Constructor is called once from Application initialization at `0x00464108`. | certain | xrefs/decompile | target/UID00041V | incorporate | applied |
| C07 | Ordinary destructor clears at `0x004f02ef` after string cleanup. | certain | bytes/decompile | target/UID00018S | incorporate | applied |
| C08 | UID00040R clears at `0x004f03c0` and has only constructor-EH xref `0x00600a64`. | certain | analyze/xrefs | target/UID00040R | incorporate | applied |
| C09 | Scalar wrapper clears at `0x004f0431` and is reached only from the LanguageMan vtable. | certain | bytes/xrefs | target/UID00018V | incorporate | applied |
| C10 | Application cleanup checks the global and invokes virtual scalar deletion with flag 1 at `0x00464c3c`. | certain | cleanup decompile; exact target/global prose; commands `15417`/`15418` | target UID0001OS and semantic global UID0000RC | incorporate | applied |
| C11 | Vtable base `0x0061c9e0` has exactly ctor/dtor/scalar store refs. | certain | xrefs | vtable/class | incorporate | applied |
| C12 | Current RTTI exposes exact `LanguageMan` type/class descriptors. | certain | entity/RTTI bytes | class/target | incorporate | applied |
| C13 | Current RTTI exposes direct `Singleton<LanguageMan>` descriptors. | certain | entity/RTTI bytes | class/target | incorporate | applied |
| C14 | No current LanguageManager RTTI/name exists. | very strong | bounded entity query | alias/support | already-present | already-present |
| C15 | LanguageMan hierarchy declares three bases/entries: LanguageMan, LObject, Singleton. | certain | CHD/BCA bytes | class/vtable | incorporate | applied |
| C16 | Singleton PMD is `mdisp=4`, `pdisp=-1`, `vdisp=0`, attributes `0x40`; EBO overlaps `m_strings`. | certain | BCD bytes/field accesses | class/lifecycle | incorporate | applied |
| C17 | `LanguageMan` is the canonical source-facing class name. | very strong | RTTI/no-alias evidence | all | already-present | already-present |
| C18 | The global stores a complete LanguageMan object pointer, not `this+4` or the string table. | certain | constructor adjustment/field users | target/global | incorporate | applied |
| C19 | Cross-source consumers require external linkage. | certain | 187 read refs/owner grouping | global/file | incorporate | applied |
| C20 | `NexusTK/localization/LanguageMan.cpp` is the source definition owner. | very strong | file/resource/function island | global/file | already-present | already-present |
| C21 | UID0000RC must emit the sole pointer definition at position 0 in `LanguageMan.cpp`, preceded only by the class forward declaration; the matching external declaration is separate future header/class placement. | very strong | semantic-global precedent/ODR/order | global | incorporate | applied |
| C22 | UID0001OS must be false/non-emitting backing storage with blank formal C++. | very strong | one-definition policy | target | incorporate | applied |
| C23 | UID0001OS keeps owner 0000RC, blank emitter/position, exact title/path/range, and Nested 0. | certain | metadata policy | target | incorporate | applied |
| C24 | UID0001OS should rise `86/90 -> 92/94`. | strong | closed blocker matrix | target | incorporate | applied |
| C25 | UID0000RC should rise `87/92 -> 92/94` and receive Destination 2 as the source-only forward-declaration/module-definition block, without a header external declaration. | strong | exact type/linkage/owner/formal | global | incorporate | applied |
| C26 | UID00041V should rise `91/92 -> 92/94`; Destination 3 removes only explicit Singleton publication. | strong | direct-base lowering | constructor | incorporate | applied |
| C27 | UID00018S should rise `89/92 -> 92/94`; Destination 4 removes only explicit Singleton clear. | strong | reverse base teardown | destructor | incorporate | applied |
| C28 | UID00040R should become `90/94`, owner NONE, false, blank emitter/position/formal. | very strong | exact EH-only role | clear helper | incorporate | applied |
| C29 | UID00018V should become `91/94`, owner NONE, false, blank emitter/position/formal. | very strong | exact compiler wrapper | scalar wrapper | incorporate | applied |
| C30 | UID00040W should become `90/94`, owner 000071, false, blank emitter/position/formal. | very strong | generated vtable policy | vtable | incorporate | applied |
| C31 | UID000071 should record direct LObject/Singleton inheritance, compiler lifetime lowering, and the separate future header external-declaration role while staying `89/92` with blank formal. | strong | RTTI plus unresolved tail proof | class | incorporate | applied |
| C32 | UID0000KK should record the sole module definition, explicitly separate future header route, and compiler exclusions while staying `89/89`. | strong | source route/current union | file | incorporate | applied |
| C33 | UID00018R should retain non-emitting aggregate status but correct explicit/static lifecycle wording. | strong | exact child/source split | aggregate | incorporate | applied |
| C34 | UID00018U should retain split-index status but reclassify UID00040R as compiler EH support. | strong | direct-base/EH proof | helper aggregate | incorporate | applied |
| C35 | UID000072 remains ignored/non-emitting; no separate LanguageManager source is created. | very strong | no RTTI/allocation/vtable | alias | already-present | already-present |
| C36 | Predecessor `0x0067a74c` and successor `0x0067a754` remain separate singleton slots with 72 and 210 refs. | certain | bytes/xrefs/docs | target | incorporate | applied |
| C37 | No target split, merge, padding edit, new UID, or range change is warranted. | certain | exact one-dword boundary | target | not-applicable | excluded-with-reason |
| C38 | Eleven manual rows/actions below are required; generated tracker remains validator-owned. | certain | current row comparison | coverage handoff | incorporate | excluded-with-reason |
| C39 | Generated output should contain one global module definition preceded by its class forward declaration, no header external declaration in `LanguageMan.cpp`, and no target/EH/scalar/vtable markers or explicit singleton method statements. | very strong | emitter/source policy | generated verification | incorporate | applied |
| C40 | No third-party import, IDA mutation, ordinary edit, validator, lease, or lifecycle action belongs to this report-only pass. | certain | assignment constraints | report | not-applicable | already-present |

Callback verification notes: C01-C09/C11-C36 and C39 are proven by the original ordinary commands `15380`, `15381`, `15382`, `15384`, `15386`, `15387`, `15389`, `15390`, `15400`, `15403`, and `15405`, followed by waited command `15406`. C10 is now independently destination-complete: UID0001OS and UID0000RC each state the `0x00464c2e` global read, non-null check, scalar-delete flag `1`, and virtual scalar-deleting-destructor dispatch at `0x00464c3c`; scoped commands `15417` and `15418` passed, and waited command `15419` preserved generated semantics. C37 is excluded because the accepted one-dword target required no split/merge/new UID/padding/range action. C38 is excluded from B005 mutation because manual coverage is supervisor-owned; its exact eleven-action no-loss handoff is retained below. C40 preserves the completed report-only constraints; no third-party import, IDA mutation, or lifecycle action occurred.

## Positive Evidence Summary

- Exact four-byte zero storage and 192 direct refs prove a live process-wide pointer rather than padding or an unused slot.
- Five exact writes/clears cover normal construction, constructor fallback, constructor unwind, ordinary destruction, and scalar-wrapper teardown.
- RTTI independently names both `LanguageMan` and `Singleton<LanguageMan>` and encodes direct Singleton base offset `+4`; no LanguageManager type appears.
- Constructor arithmetic matches that PMD exactly: the compiler derives the empty-base address then recovers the complete object for singleton publication.
- Consumer reads cross Application, RegistryConfig, UserPane, dialogs/prompts, scanner, and gameplay UI, proving external linkage.
- Current project ownership already routes LanguageMan class/method/data through `NexusTK/localization/LanguageMan.cpp`.
- The semantic-global/exact-storage split is already established by current MessageShowPane documentation and avoids duplicate generated definitions.

## IDA MCP Facts

- Session: `9b0396a3`; health `ok`; auto-analysis, Hex-Rays, and strings ready; imagebase `0x400000`.
- Target bytes: `00 00 00 00`; full `0x0067a740-0x0067a75f` read is zero.
- Constructor publication bytes include `8d 43 04`, null test, `83 c0 fc`, then absolute store to `0x0067a750`; fallback is an absolute zero store.
- Ordinary clear bytes at `0x004f02ef`, exact EH helper bytes at `0x004f03c0`, and scalar clear bytes at `0x004f0431` all target `0x0067a750`.
- Exact functions: ctor `0x004f0010` size `0x27c`; dtor `0x004f0290` size `0x80`; adjacent zero helper `0x004f0310` size `0x32`; lookup `0x004f0350` size `0x22`; copy `0x004f0380` size `0x3b`; EH clear `0x004f03c0` size `0x0b`; scalar wrapper `0x004f03d0` size `0xa7`.
- Current IDA still applies stale Boost name `??1exception@boost@@MAE@XZ_3` to `0x004f0290`; body/vtable/global/base evidence rejects it.
- Xrefs: target 192; predecessor 72; successor 210; vtable base 3; ctor 1; ordinary dtor 0; EH clear 1; scalar wrapper 1 data ref.
- RTTI names: LanguageMan COL/CHD/BCA/BCD at `0x006498c0-0x00649910`, Singleton descriptors through `0x00649944`, type descriptors at `0x00676efc` and `0x00676f18`.
- CHD attributes are multiple-inheritance `1`; base count is 3. Singleton BCD PMD is `+4,-1,0`, attributes `0x40`.
- Constructor allocates/uses complete object size 44 through Application startup; scalar flag-4 path independently supplies `0x2c` / 44 bytes.
- No MCP failure occurred and no IDA mutation was made.

## Function / Child Inventory

| Range / item | UID / path | Role | Reconstructable recommendation | Direct parent | Score recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004f0010-0x004f028c` | UID00041V | authored constructor/parser | true | UID000071 | `92/94` | source body, implicit Singleton base publication |
| `0x004f0290-0x004f0310` | UID00018S | authored ordinary destructor | true | UID000071 | `92/94` | source body, implicit Singleton base clear |
| `0x004f0310-0x004f0342` | UID00018T | unreferenced file-local zero initializer | unchanged true | UID0000KK | unchanged `85/91` | verify-only; no LanguageMan field proof |
| `0x004f0350-0x004f0372` | UID00040P | authored lookup | unchanged true | UID000071 | unchanged `90/93` | verify-only |
| `0x004f0380-0x004f03bb` | UID00040Q | authored copy helper | unchanged true | UID000071 | unchanged | verify-only signature cap |
| `0x004f03c0-0x004f03cb` | UID00040R | compiler constructor-unwind Singleton cleanup | false | NONE | `90/94` | blank/no-code |
| `0x004f03d0-0x004f0477` | UID00018V | compiler scalar deleting destructor | false | NONE | `91/94` | blank/no-code |
| `0x0061c9dc-0x0061c9ec` | UID00040W | compiler RTTI/vtable data | false | UID000071 semantic | `90/94` | blank/no-code |
| `0x0067a750-0x0067a754` | UID0001OS | exact backing storage | false | UID0000RC semantic | `92/94` | blank/no-code |
| semantic global | UID0000RC | sole `LanguageMan.cpp` pointer definition; header external declaration placed separately in future class/header output | true | UID0000KK | `92/94` | source-bearing at position 0 |

## Direct Xref / Caller Inventory

| Address / item | Xref / caller / callee | Meaning |
| --- | --- | --- |
| `0x004f0066` | constructor write | normal direct Singleton base publication |
| `0x004f006d` | constructor fallback write | null-adjustment fallback generated by base construction |
| `0x004f02ef` | ordinary destructor write | reverse direct Singleton base clear after authored string cleanup |
| `0x004f03c0` | one xref from EH metadata `0x00600a64` | constructor-unwind duplicate clear, not ordinary source helper |
| `0x004f0431` | scalar wrapper write | duplicate Singleton teardown in compiler wrapper |
| `0x00464108` | sole ctor caller in Application initialization | startup allocation/construction route |
| `0x00464c36-0x00464c3c` | Application cleanup read and virtual delete flag 1 | explicit shutdown consumer route |
| `0x005a5bd0` group | 16 refs | UserPane key/text event localization fanout |
| `0x0048ebc0` group | 10 refs | RegistryConfig user-default localization fanout |
| `0x005b2a70`, `0x005bdfa0`, `0x005c05a0` | four refs each | EmotionInputPane, OldUserStatusPane, VirusChecker consumers |
| `0x005b6a20` | three refs | BlockListen input command localization consumer |
| 18 unmodeled-function refs | exact raw prompt/dialog/helper ranges in current docs | raw function-model gaps do not reduce pointer liveness; all are source consumer contexts |

The full target set contains 192 data refs. Subtracting the five writes/clears leaves 187 reads. Representative consumer reports opened during the search confirm localized string IDs and calls rather than alternate pointer meanings.

## Documentation Evidence And IDA Status

- Current target/global docs agree on address, role, 192 refs, exact writers, LanguageMan canonical name, LanguageMan.cpp owner, one-definition split, accepted `92/94` source states, and the complete Application shutdown sequence: `0x00464c2e` read, non-null check, flag `1`, and virtual scalar deletion at `0x00464c3c`.
- Current class docs identify `m_strings` at `+4`, `m_stringCount` at `+8`, complete size `0x2c`, no safe names for the tail, and the proven direct `LObject` plus `Singleton<LanguageMan>` bases while preserving the blank formal.
- Current constructor/destructor formals are behaviorally complete and exclude the two explicit singleton statements proved to be compiler-lowered.
- Current UID00040R docs classify the exact EH-only clear as compiler constructor-unwind support with false/blank source state.
- Current scalar and vtable pages identify compiler behavior and now use false/blank source states that produce no generated source markers.
- C10-repair generated `LanguageMan.cpp` command `15419` preserves the sole UID0000RC definition, corrected ctor/dtor bodies, and zero UID0001OS/UID00040R/UID00018V/UID00040W output first verified by B005 command `15406`. Only the independent UID000071 class-tail and unchanged UID00018T orphan markers remain.
- Current manual rows are stale at multiple historical scores and still call the global C++ blocked by LanguageMan/LanguageManager spelling. Exact no-loss replacements/additions are supplied below for supervisor application only.

## Ranked Ownership Analysis

### 1. Semantic global UID0000RC in LanguageMan.cpp

- Evidence for: dedicated by-global identity, exact memory child, direct LanguageMan type, cross-file external linkage, existing owner/emitter UID0000KK, established semantic-global/backing-storage precedent, and source-order need before constructor methods.
- Evidence against: exact original header organization and null-literal spelling are not binary-recoverable.
- Decision: strongest and accepted recommendation; one externally linked module definition at position 0, with its header declaration placed separately.

### 2. Exact storage UID0001OS as a second emitter

- Evidence for: exact storage and current reconstructable/emitter metadata.
- Evidence against: duplicates the same source object, produces an Empty Emitter Marker now, and would violate one-definition policy if given the same definition.
- Decision: reject; retain as false/non-emitting evidence page under semantic owner UID0000RC.

### 3. Class, LanguageManager, or standalone file ownership

- Evidence for: class context is required for pointer type; historical generated output used LanguageManager; a file-static definition would be simple.
- Evidence against: class page is not the dedicated global owner, LanguageManager has no RTTI/allocation/vtable, and 187 cross-source reads reject internal linkage.
- Decision: reject all three as definition owners. Class/file pages receive support prose only; LanguageManager remains ignored.

### Proposed new file/grouping, if applicable

- Not applicable. Existing UID0000KK `NexusTK/localization/LanguageMan.cpp` is the correct source file and no new UID/file is needed.

## Source Placement

- Recommended source definition placement: UID0000RC at position `0` in `NexusTK/localization/LanguageMan.cpp`.
- Header-facing role: the matching external LanguageMan pointer declaration belongs in future proper header/class output. Destination 2 is routed to `LanguageMan.cpp` and therefore contains only the local class forward declaration plus the sole module definition; it does not emit the header declaration.
- Constructor, destructor, lookup, parser constants, and literals already route to the same file, and `str.res` makes localization ownership unambiguous.
- Rejected `LanguageManager.cpp`: no independent source type exists.
- Rejected Application.cpp: startup and shutdown only consume the singleton lifecycle; they do not own localization data.
- Rejected static/internal linkage: consumers span many translation-unit families.
- Remaining uncertainty: exact original folder spelling is currently `localization/`; the existing by-file route is authoritative for reconstruction and is not changed here.

## Range / Split / Padding / Reclassification Analysis

- Target boundary is exactly one dword. Predecessor is `0x0067a74c-0x0067a750` application cleanup queue storage; successor is `0x0067a754-0x0067a758` EventMan storage.
- Neighbor xref counts 72/192/210 independently distinguish the three slots.
- All 32 bytes at `0x0067a740-0x0067a75f` being zero does not merge them; distinct xref sets and lifecycle owners prove separate source globals.
- No target child, split, merge, ignored padding, nesting delta, or range extension is needed. Keep `Nested:0`.
- Reclassification is source-emission only: UID0001OS changes from reconstructable/emitting backing storage to false/non-emitting exact evidence.
- UID00040R and UID00018V receive analogous compiler/no-source reclassification. UID00040W becomes compiler-generated binary data from declarations.
- Existing `0xcc` internal LanguageMan function padding remains untouched.

## Negative Evidence Summary

- No LanguageManager type descriptor, class hierarchy, vtable, allocation, constructor, destructor, or singleton storage was found.
- No second source global is needed or legal.
- No target write exists outside the five closed lifetime sites.
- No ordinary call reaches UID00040R; its only reference is constructor EH metadata.
- No direct call reaches UID00018V; its only inbound route is the vtable.
- No direct call reaches UID00018S because normal destruction is virtual through the scalar wrapper; absence of direct calls does not make the authored destructor compiler-only.
- No UID00018T reference ties its seven stores to a LanguageMan object, so it cannot name or justify the class tail.
- No source needs raw storage addresses, direct vptr stores, RTTI arrays, PMDs, delete flags, object-size guards, EH thunks, or raw labels.
- No evidence supports file-static linkage, `g_pStringTable`, pointer-to-`this+4`, or separate LanguageManager ownership.

## IDA Rename / Type / Comment Recommendations

- Source-facing global name/type: retain `g_pLanguageMan` and pointer-to-LanguageMan.
- Source-facing class direction: retain `LanguageMan`; document direct LObject plus Singleton-of-LanguageMan inheritance.
- Raw aliases to preserve only as history/search provenance: `dword_67A750`, `DAT_0067a750`, `g_pStringTable`, `sub_4F03C0`, and stale Boost destructor name.
- UID00040R descriptive page title may remain for discoverability, but its status must say compiler constructor-unwind Singleton cleanup, not an original helper name.
- No IDA rename/type/comment mutation was performed. The saved-name inconsistency remains documented without changing the accepted source-doc reconstruction.

## First-Draft C++ Recommendation

Exactly seven managed destination blocks follow. They are the only accepted and applied C++/formal changes in this report. Destinations 1, 5, 6, and 7 are intentionally blank no-code blocks.

Destination 1: `by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 2: `by-global/g_pLanguageMan.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class LanguageMan;

LanguageMan *g_pLanguageMan = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 3: `by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
LanguageMan::LanguageMan()
{
    MemoryMan* memoryMan = GetMemoryMan();

    DATFile stringResource;
    stringResource.Open(kStringResourceName);
    (void)stringResource.GetSize();

    wchar_t **temporaryStrings =
        static_cast<wchar_t **>(
            memoryMan->AllocateBufferMemory(sizeof(wchar_t *) * kMaxLocalizedStringCount));
    m_stringCount = 0;

    bool reachedEndOfFile = false;
    char multiByteLine[kMaxStringResourceLineBytes * 2];
    wchar_t wideLine[kMaxStringResourceLineBytes];

    do {
        int lineLength = 0;

        while (stringResource.Tell() < stringResource.GetSize()) {
            stringResource.Read(&multiByteLine[lineLength], 1);

            if (multiByteLine[lineLength] == '\r') {
                stringResource.Seek(1, 1);
                break;
            }

            if (multiByteLine[lineLength] == '\n' || ++lineLength >= kMaxStringResourceLineBytes)
                break;
        }

        if (stringResource.Tell() >= stringResource.GetSize())
            reachedEndOfFile = true;

        for (int i = 0; i < lineLength; ++i) {
            if (multiByteLine[i] == 0x11)
                multiByteLine[i] = '\r';
        }

        const int wideChars = MultiByteToWideChar(
            0,
            0,
            multiByteLine,
            lineLength,
            wideLine,
            kMaxStringResourceLineBytes);
        const size_t byteCount = static_cast<size_t>(wideChars) * sizeof(wchar_t);
        wchar_t *copiedLine =
            static_cast<wchar_t *>(
                memoryMan->AllocateBufferMemory(byteCount + sizeof(wchar_t)));

        temporaryStrings[m_stringCount] = copiedLine;
        MemmoveWrapper(temporaryStrings[m_stringCount], wideLine, byteCount);
        temporaryStrings[m_stringCount][wideChars] = L'\0';

        const int storedIndex = m_stringCount++;
        if (storedIndex >= kMaxLocalizedStringCount)
            throw MyError(kTooManyStringsMessage);
    } while (!reachedEndOfFile);

    m_strings =
        static_cast<wchar_t **>(memoryMan->AllocateBufferMemory(sizeof(wchar_t *) * m_stringCount));
    for (int i = 0; i < m_stringCount; ++i)
        m_strings[i] = temporaryStrings[i];

    memoryMan->FreeBufferMemory(temporaryStrings);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 4: `by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
LanguageMan::~LanguageMan()
{
    MemoryMan* memoryMan = GetMemoryMan();

    for (int i = 0; i < m_stringCount; ++i)
        memoryMan->FreeBufferMemory(m_strings[i]);

    memoryMan->FreeBufferMemory(m_strings);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 5: `by-memory/0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 6: `by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 7: `by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Destination 2 is legal with an incomplete LanguageMan type, supplies the local class forward declaration and sole `LanguageMan.cpp` module definition, and preserves zero initialization. The matching external declaration remains separate future proper header/class placement and is intentionally absent from this source-routed block.
- Destination 3 preserves the accepted parser body byte-for-byte except for removing the compiler-lowered direct-base publication statement.
- Destination 4 preserves every authored free operation and removes only reverse direct-base Singleton teardown.
- Destination 5 has no source body because it is constructor-unwind cleanup.
- Destination 6 has no source body because it is the MSVC scalar deleting destructor generated from the virtual destructor.
- Destination 7 has no source body because RTTI/vtable bytes are generated from class declarations.
- The current style uses pointer stars with the declarator and integer zero for null in LanguageMan methods; Destination 2 follows that family convention.
- No third-party import applies.

## Final Recommendation

- C01-C40 were applied/already present/excluded with exact reason at full report detail; no accepted item is blocked.
- Destinations 1-7 were applied exactly and independently verified after generation.
- Destination 2 is source-correct: only the local class forward declaration and sole module definition emit in `LanguageMan.cpp`; the matching external declaration remains reserved for separate future proper header/class output.
- Only the target/global/constructor/destructor/EH-clear/scalar/vtable scores listed in the score matrix changed. Class/file/aggregate/helper-aggregate/alias/adjacent-helper scores remain unchanged.
- The exact target path/title/range, owner `0000RC`, and `Nested:0` are preserved; only its source disposition and accepted scores changed.
- LanguageMan parser, lookup, copy-helper, constants, literals, resource, and unrelated class/file evidence are preserved.
- `LanguageManager` remains only rejected/historical search provenance.
- UID00018T remains unchanged and is not used to invent LanguageMan tail members.
- No new UID, source file, split, merge, rename, padding edit, third-party import, or IDA mutation occurred.
- Future class-layout work is outside this target callback only in the narrow sense that it must not fabricate the unknown `+0x0c-+0x28` members; it is not a prerequisite for the accepted global/source-lifetime corrections.

## Recommended Target Doc Changes

Target: `by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md`.

- Applied and verified: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000RC`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`/position/formal, exact range/title/path, `Nested:0`, and blank Destination 1.
- Applied exact Item Summary: `Exact four-byte LanguageMan Singleton backing storage. Direct Singleton<LanguageMan> construction, unwind, ordinary destruction, and scalar-wrapper teardown produce five lifecycle writes or clears; 187 reads feed localization consumers, while the semantic global page emits the sole externally linked source definition and this storage page emits no duplicate C++.`
- Applied current evidence-time session, zero bytes, 192 total refs, five/187 write-read split, exact lifetime addresses, top consumer groups, 18 raw-context refs, startup/shutdown route, RTTI/PMD/EBO proof, one-definition policy, and neighboring 72/210-ref boundaries.
- Applied and repair-verified the complete shutdown route in the target: Application cleanup reads `g_pLanguageMan` at `0x00464c2e`, checks it, supplies scalar-delete flag `1`, and dispatches virtual scalar deletion at `0x00464c3c`.
- Historicalized the former `reconstructable project global data` and `final C++ waits for broader LanguageMan.cpp` claims with the semantic-global one-definition reason.
- Preserved all existing exact consumer examples and resource links without compression.

## Recommended Support Doc Changes

1. Applied/verified in `by-global/g_pLanguageMan.md`: `92/94`, owner/emitter `0000KK`, true, position `0`, exact Destination 2, external-linkage/direct-Singleton/read-group/source-order proof, separate future header declaration, historicalized spelling/adjacent-helper blocker, and complete `0x00464c2e` read/check plus flag-1 virtual scalar-delete dispatch at `0x00464c3c`.
2. Applied/verified in `by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md`: `92/94`, unchanged owner/emitter/range/position, every parser fact preserved, exact Destination 3, and authored-parser/compiler-publication split.
3. Applied/verified in `by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md`: `92/94`, unchanged owner/emitter/range, all free/helper/stale-name evidence preserved, exact Destination 4, and implicit reverse Singleton teardown.
4. Applied/verified in `by-memory/0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper.md`: `90/94`, owner NONE, false, blank emitter/position/formal, exact blank Destination 5, constructor-unwind no-code disposition, and exact bytes/hash/range/xref preserved.
5. Applied/verified in `by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md`: `91/94`, owner NONE, false, blank emitter/position/formal, exact blank Destination 6, all cleanup/delete-flag/size/helper/padding evidence preserved, and authored-destructor/implicit-base/compiler-wrapper split.
6. Applied/verified in `by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md`: `90/94`, semantic owner `000071`, false, blank emitter/position/formal, exact blank Destination 7, and hierarchy/PMD/source-declared-generated-binary proof.
7. Applied/verified in `by-class/LanguageMan.md`: unchanged `89/92`, owner/emitter/file route, and blank formal; direct bases, EBO overlap, singleton/compiler exclusions, one-definition relationship, separate future header declaration, and exact `0x2c` no-placeholder cap were added.
8. Applied/verified in `by-file/LanguageMan.md`: unchanged `89/89`, path/metadata/unrelated inventory; added UID0000RC sole position-0 definition and separate future header route, UID0001OS backing storage, UID00040R EH-only, UID00018V scalar glue, UID00040W generated vtable data, and removed current static-helper/marker expectations.
9. Applied/verified in `by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md`: unchanged non-emitting aggregate metadata/score/formal, synchronized direct Singleton lifecycle/child dispositions, and preserved parser/helper/padding inventory.
10. Applied/verified in `by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md`: unchanged split-index metadata/score/formal and lookup/copy detail, with UID00040R reclassified as compiler constructor-unwind support.
11. Verify-only/no edit checks passed for UID000072, UID00018T, UID00040P, UID00040Q, UID00040V, UID00040X, resource `str.res`, LObject, MemoryMan, Application startup/cleanup, and adjacent singleton pages; no concrete contradiction required an edit.

## Score And Metadata Recommendation

| Destination | Before callback | Applied current state | Owner / reconstructable / emitter / position | Rationale |
| --- | --- | --- | --- | --- |
| UID0001OS target | `86/90` | `92/94` | `0000RC / FALSE / blank / blank` | Exact storage, all refs/lifetime routes, direct base, one-definition, type/linkage, boundaries, no-code proof closed. |
| UID0000RC global | `87/92` | `92/94` | `0000KK / TRUE / 0000KK / 0` | Sole externally linked module definition and exact source formal now ready; header declaration is separate. |
| UID00041V constructor | `91/92` | `92/94` | unchanged `000071 / TRUE / 000071 / blank` | Removes compiler publication from otherwise complete parser source. |
| UID00018S destructor | `89/92` | `92/94` | unchanged `000071 / TRUE / 000071 / blank` | Removes compiler base clear from otherwise complete authored cleanup. |
| UID00040R EH clear | `88/93` | `90/94` | `NONE / FALSE / blank / blank` | Exact EH-only no-code disposition closed; compiler output caps completion below source methods. |
| UID00018V scalar | `87/92` | `91/94` | `NONE / FALSE / blank / blank` | Exact wrapper decomposition, flags, size, vtable-only route, and no-code policy closed. |
| UID00040W vtable | `86/91` | `90/94` | `000071 / FALSE / blank / blank` | Exact RTTI/vtable hierarchy and generated-binary policy closed; class tail keeps completion below 92. |
| UID000071 class | `89/92` | unchanged | unchanged | Direct bases resolved, but full `0x2c` human declaration remains blocked by unnamed tail. No placeholder inflation. |
| UID0000KK file | `89/89` | unchanged | FILE | Source file is correct; exact original path spelling and incomplete class/copy declaration still cap it. |

Score-improvement attempts:

- Naming blocker: queried all current names/RTTI; resolved to LanguageMan and rejected LanguageManager.
- Type blocker: traced constructor adjustment and method field use; resolved to complete LanguageMan pointer.
- Linkage blocker: classified all 192 refs and cross-file groups; resolved external.
- Owner/emitter blocker: compared semantic-global and exact-storage models; resolved UID0000RC sole definition.
- Lifecycle source-shape blocker: decoded RTTI CHD/BCD/PMD and all five writes; resolved direct Singleton lowering.
- Clear-helper blocker: checked exact bytes, caller/callee/xref/EH route; resolved compiler-only.
- Scalar/vtable blocker: checked vtable-only reachability, flags, object-size path, and hierarchy; resolved compiler-only.
- Complete class blocker: checked constructor/destructor/lookup/copy, allocation/delete size, adjacent zero helper, current class/type docs, and old reports. Tail member identities remain genuinely unavailable; no raw reserved array is emitted and target/global scores are not held down by that independent issue.

## Open Questions With Attempted Resolution

- Is the object `LanguageMan` or `LanguageManager`? Resolved to LanguageMan by exact RTTI/type descriptors and absence of LanguageManager runtime identity.
- Is the global pointer complete-object or `this+4`? Resolved to complete object by the constructor's `+4/-4` adjustment and downstream field addressing.
- Is publication/clear handwritten? Resolved no: direct Singleton BCD PMD plus exact constructor/destructor/EH/scalar patterns prove compiler/base lowering.
- Is UID00040R an original static helper? Resolved no: exact 11-byte body and sole constructor-EH metadata reference prove generated unwind cleanup.
- Is the global file-static? Resolved no by cross-source consumer set.
- Which page emits the definition? Resolved UID0000RC; UID0001OS is backing evidence.
- Does the adjacent zero helper define LanguageMan tail fields? Resolved no with exhaustive caller/callee/xref/layout negative evidence.
- What occupies `+0x0c-+0x28`? Unresolved only at human member-name/declaration level after checking all current LanguageMan methods, size/allocation paths, UID00018T, RTTI, consumers, type pages, old reports, and generated source. The exact unavailable evidence would be original symbols/debug types or a source consumer that accesses those members. Impact: class formal/score stays capped; no impact on global type, linkage, definition, target score, or lifecycle source correction.
- Exact null literal/header arrangement? The binary cannot recover the original header path or null-token spelling. Destination 2 uses project-consistent integer zero and the source-legal local forward declaration plus module definition; the matching external declaration is explicitly reserved for separate future proper header/class output rather than this `.cpp` block. Confidence remains 94.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The manual files and affected rows were reread after implementation at the current callback-time hashes in Supporting Research. The older report-only hashes remain historical evidence. The tracker is validator-owned and must not receive manual row text. The following eleven exact supervisor-owned actions remain unapplied external state; B005 did not edit the manual reports. Supervisor application must reread the mutable files and preserve any later unrelated union.

1. In `by-memory/-coverage-report.md`, replace the current UID00018R row in its existing address-sorted location with:

`    - [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md) 0x004f0010-0x004f0477 | exact split index | LanguageMan localization lifecycle and helpers : ignored : 90% : very-strong : Non-emitting LanguageMan.cpp island over exact constructor, ordinary destructor, lookup/copy methods, compiler Singleton unwind cleanup, compiler scalar deleting wrapper, and internal padding. Direct LObject plus Singleton<LanguageMan> RTTI resolves lifetime source shape; exact children own source/no-code dispositions and the aggregate emits no marker.`

2. Immediately after that aggregate row and before `0x004f028c-0x004f0290` padding, insert:

`        - [UID:00041V][0x004f0010-0x004f028c.LanguageManConstructor](by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md) 0x004f0010-0x004f028c | constructor | LanguageMan::LanguageMan : reconstructable : 92% : very-strong : Exact str.res parser/allocator constructor with one Application startup caller, direct Singleton<LanguageMan> publication generated by base construction, complete DATFile/MemoryMan/MyError behavior, and source C++ that excludes the compiler singleton assignment.`

3. Replace the current UID00018S row with:

`        - [UID:00018S][0x004f0290-0x004f0310.LanguageManCleanupDestructor](by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md) 0x004f0290-0x004f0310 | destructor | LanguageMan::~LanguageMan : reconstructable : 92% : very-strong : Exact authored destructor frees every localized string and the pointer table through MemoryMan. The stale Boost name is rejected; vptr restore, Singleton<LanguageMan> reverse clear, and LObject teardown are compiler/base lowering excluded from handwritten C++.`

4. Replace the current UID00018U row with:

`    - [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md) 0x004f0350-0x004f03cb | exact split index | LanguageMan lookup/copy and Singleton unwind support : ignored : 88% : very-strong : Non-emitting index over exact GetLocalizedString, copy-output helper, compiler constructor-unwind Singleton clear, and internal padding. LanguageMan is canonical over the rejected LanguageManager alias; exact children carry source/no-code decisions.`

5. Under UID00018U in address order after the copy-helper subrange and before `0x004f03cb-0x004f03d0` padding, insert:

`        - [UID:00040R][0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper](by-memory/0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper.md) 0x004f03c0-0x004f03cb | compiler EH cleanup | LanguageMan Singleton constructor-unwind clear : ignored : 90% : very-strong : Exact 11-byte clear with one constructor EH metadata reference, no ordinary caller/callee, and direct Singleton<LanguageMan> base source cause; false/non-emitting with blank formal C++ because no standalone handwritten helper exists.`

6. Replace the current UID00018V row with:

`        - [UID:00018V][0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor](by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md) 0x004f03d0-0x004f0477 | compiler scalar deleting destructor | LanguageMan scalar deleting destructor : ignored : 91% : very-strong : Exact vtable-only compiler wrapper duplicates authored destructor plus implicit Singleton/LObject teardown, then applies delete flags, OperatorDeleteWrapper, flag-4 0x2c size guard, optional free, and return-this ABI behavior; no handwritten wrapper source is emitted.`

7. In the address-sorted LanguageMan read-only-data area, insert or replace UID00040W with:

`    - [UID:00040W][0x0061c9dc-0x0061c9ec.LanguageManVtableData](by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md) 0x0061c9dc-0x0061c9ec | compiler RTTI/vtable data | LanguageMan vtable data : ignored : 90% : very-strong : Exact complete-object locator and vtable with scalar deleting destructor plus inherited LObject slots; three vtable stores and RTTI prove direct LObject plus Singleton<LanguageMan> source bases, while the compiler regenerates all raw bytes and no vtable array is handwritten.`

8. Replace UID0001OS in `by-memory/-coverage-report.md` with:

`    - [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md) 0x0067a750-0x0067a754 | singleton backing storage | g_pLanguageMan : ignored : 92% : very-strong : Exact four-byte zero-initialized LanguageMan Singleton slot with 192 refs, five base/compiler lifetime writes or clears, 187 cross-source localization reads, direct Singleton<LanguageMan> RTTI/PMD proof, clean neighboring singleton boundaries, and sole externally linked source definition emitted by UID0000RC; this storage page emits no duplicate C++.`

9. Replace UID0000RC in `by-global/-coverage-report.md` with:

`- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md) : reconstructable : 92% : very-strong : Sole LanguageMan singleton pointer module definition in NexusTK/localization/LanguageMan.cpp at position 0, preceded by a local class forward declaration and backed by exact storage UID0001OS; the matching external declaration belongs to separate future proper header/class output and is not emitted in this source block. Live IDA proves zero storage, 192 refs, five direct Singleton<LanguageMan> construction/unwind/destruction/scalar lifetime writes, 187 localization consumers, canonical LanguageMan RTTI with no LanguageManager type, external linkage, and one-definition policy.`

10. Replace UID000071 in `by-class/-coverage-report.md` with:

`- [UID:000071][LanguageMan](by-class/LanguageMan.md) : reconstructable : 89% : very-strong : LanguageMan localization class with direct LObject plus Singleton<LanguageMan> RTTI inheritance, EBO singleton base at +0x04, m_strings at +0x04, m_stringCount at +0x08, exact constructor/destructor/lookup lifecycle, compiler-only unwind/scalar/vtable support, canonical-name proof, a separate future header declaration, and the sole externally linked g_pLanguageMan module-definition route. Complete size 0x2c is proved, while +0x0c-+0x28 human member identities remain unavailable and the class formal stays blank without reserved placeholders.`

11. Replace UID0000KK in `by-file/-coverage-report.md` with:

`- [UID:0000KK][LanguageMan](by-file/LanguageMan.md) : reconstructable : 89% : strong : NexusTK/localization/LanguageMan.cpp owns the sole position-0 externally linked g_pLanguageMan module definition, preceded by a local class forward declaration while the matching external declaration belongs to separate future header/class output; the file also owns the direct LObject plus Singleton<LanguageMan> class lifecycle, str.res constructor/parser, authored destructor and lookup methods, parser constants/literals, and exact source/compiler split. UID0001OS is backing storage; UID00040R, UID00018V, and UID00040W are compiler-generated no-code support; LanguageManager remains a rejected generated alias.`

Verify-only current manual dispositions: UID000072 remains ignored as a LanguageMan alias; UID00018T remains a file-level orphan with no LanguageMan field proof. No replacement is included for either page. B005 did not apply any row because manual coverage is supervisor-owned, while generated tracker updates are validator-owned.

## Follow-Up Actions

- B005 callback responsibilities are complete: all eleven ordinary destinations and seven managed blocks were applied, scoped-validated under short leases, immediately released, generated-read back, and reconciled in this artifact.
- The exact eleven-action manual coverage handoff remains supervisor-owned external state; report execution, movement, archival, and any later coverage application do not alter the completed ordinary implementation evidence recorded here.
- The validator-owned generated source/tracker were refreshed through commands `15406`/`15407`; their headers/hashes are callback-time readback rather than promises that unrelated later validator epochs will not advance them.
- No separate target research remains. The unresolved complete LanguageMan tail is explicitly bounded class-declaration evidence, not a pending UID0001OS blocker or a reason to undo the exact global/lifecycle recommendations.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong for all applied scores; compiler-only items stay below 95 by policy and lexical uncertainty caps source items at 94.
- Remaining uncertainty: original local/member names for the unused LanguageMan tail and exact header/null-literal spelling. Neither changes the chosen owner, type, linkage, one-definition route, lifetime source/compiler split, target formal, or score improvement.

## Validator Results

- Report-only history: no validator was run before the accepted Gate 1 callback; live MCP read-only evidence succeeded against session `9b0396a3` and no fallback-only conclusion was used.
- Callback scoped validators, all `exit 0 / ok:1`:

| Command | Timestamp | Scoped page | Result / side effects |
| --- | --- | --- | --- |
| `000000015380` | `2026-07-20T15:24:46-04:00` | UID0001OS target | metadata completion/confidence/source-state/reference/projected-stats updates; generated deferred |
| `000000015381` | `2026-07-20T15:25:49-04:00` | UID0000RC global | metadata/source-order/formal/reference/projected-stats updates and obsolete stats-row removal; generated deferred |
| `000000015382` | `2026-07-20T15:26:57-04:00` | UID00041V constructor | completion/confidence/projected-stats updates; generated deferred |
| `000000015384` | `2026-07-20T15:28:05-04:00` | UID00018S destructor | completion/confidence/projected-stats updates; generated deferred |
| `000000015386` | `2026-07-20T15:29:09-04:00` | UID00040R EH helper | owner/reconstructable/emitter/formal/completion/confidence/projected-stats updates; generated deferred |
| `000000015387` | `2026-07-20T15:30:16-04:00` | UID00018V scalar wrapper | owner/reconstructable/emitter/formal/completion/confidence/projected-stats updates; generated deferred |
| `000000015389` | `2026-07-20T15:31:07-04:00` | UID00040W vtable | reconstructable/emitter/formal/completion/confidence/projected-stats updates; generated deferred |
| `000000015390` | `2026-07-20T15:32:24-04:00` | UID000071 class | `ok:1`; projected-stats update only; generated deferred |
| `000000015400` | `2026-07-20T15:35:40-04:00` | UID0000KK file | reference-index add and projected-stats update; generated deferred |
| `000000015403` | `2026-07-20T15:37:20-04:00` | UID00018R aggregate | `ok:1`; projected-stats update; generated deferred |
| `000000015405` | `2026-07-20T15:38:28-04:00` | UID00018U helper aggregate | `ok:1`; pre-existing `missing_ref_uid 000363` warning, reference-index/projected-stats update; generated deferred |

- Final authorized waited validator `000000015406`, timestamp `2026-07-20T15:38:47-04:00`, scoped UID0001OS, returned `exit 0 / ok:1` and completed the generated refresh. It reported project-wide pre-existing autogen marker/emitter warnings, rebuilt the registry, refreshed generated metadata, and did not report a target failure.
- A deferred validator-owned tracker refresh completed as command `000000015407` at `2026-07-20T15:39:13-04:00`; no B005 manual generated/tracker edit occurred.
- C10 repair validators: target command `000000015417` at `2026-07-20T15:59:29-04:00` and semantic-global command `000000015418` at `2026-07-20T16:00:00-04:00`; both returned `exit 0 / ok:1`, updated projected stats, deferred generation, and reported no target warning.
- C10 final waited validator `000000015419` at `2026-07-20T16:00:18-04:00` returned `exit 0 / ok:1`, rebuilt validator-owned registry/generated metadata, completed generation, and reported only the same project-wide pre-existing autogen marker/emitter warnings as the first callback.
- B005 generated proof: original callback command `15406`, external interim command `15414`, and C10 repair command `15419`. Command `15419` SHA256 `A18C81A9CEF8E62A6FED7A46A7607D6747BA1FD16514F892A0D90292EFE6BAA9`, 4,206 bytes / 120 lines, preserves one UID0000RC block, local `class LanguageMan;`, one `LanguageMan *g_pLanguageMan = 0;`, one UID00041V constructor, one UID00018S destructor, zero `extern LanguageMan`, zero explicit `g_pLanguageMan = this`, and no destructor clear.
- Exact generated exclusions passed: zero UID0001OS, UID00040R, UID00018V, and UID00040W markers/bodies/comments; zero duplicate global, cookie, `undefined`, `sub_`, or `dword_` source spellings. The two remaining Empty Emitter Markers are independently bounded UID000071 incomplete-class and unchanged UID00018T orphan blockers.
- Tracker readback: B005 callback checkpoint `15407` and external interim checkpoint `15414` are historical mutable epochs. C10 repair command `15419`, SHA256 `45FD1B3E9582E71DAA052A046E88AAD6ED51B92BDC19159B65E600A5F589E831`, 1,531,696 bytes / 6,206 lines, retains all accepted UID score/reconstructability rows.

## Changed Files

- Callback artifact: `tools/leaser/Agents/Agent-B005/research/0001OS-g_pLanguageMan-source-quality.md` was updated in place; report execution/movement/archive was not run.
- Changed ordinary pages and post-validation SHA256/bytes/lines:
  - `by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md` — C10-repaired `B64BC95310FAA4D724D7FFA9D5C4CCC4E5E5C421B236CB1A675154CFCC6C0987`, 16,270 / 119; prior callback hash `C21444DB...11945` is historical.
  - `by-global/g_pLanguageMan.md` — C10-repaired `DE734F1F2A671054F31EC4DCB795635CFA4774F392F0A557F973032CE5A4A164`, 18,830 / 129; prior callback hash `81DCBD80...80B8` is historical.
  - `by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md` — `C1A903A6CE29EC54A74C4931E7D8C241E1DCA3703F9A9AC23CA34505169C983C`, 14,060 / 185.
  - `by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md` — `4E309ADAE60A3FEA0AA1525D81777625727347F35AE12F0A09CF22B856E6A1AA`, 20,661 / 155.
  - `by-memory/0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper.md` — `4858E977C5DDFA632A7AF89467147AAF8606FC36FD0FA5357A2B8EEDEC87A630`, 7,246 / 67.
  - `by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md` — `94B3595AB57FF7003995AB99CD77913B239BE9A96F1F0FA3A5C068BD7831C588`, 14,384 / 99.
  - `by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md` — `F8D2F0BAFE92EE6EC9A4FB230589A7BBE0DE2F159D3BF9AE287E50EBCD1E8419`, 6,859 / 66.
  - `by-class/LanguageMan.md` — `F194DDE36F46329F1CFA704C87B93F3CCB9E869E2EA06D89AB6BBC0D4FBF0B52`, 18,415 / 114.
  - `by-file/LanguageMan.md` — `5602922226FD482D9806D8A6FC7D7B16CAEC9B7702FAB2B64C903CB7BB9C71A8`, 27,136 / 132.
  - `by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md` — `CA65792444DB886905EC7479E2F0113572966BE79DEEEA427A04C2BC2335D951`, 27,318 / 180.
  - `by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md` — `5E2408CF0907B66C8D2FCE63766A1BC280523FBFCBEF7CFEB4232F347987F1A2`, 20,626 / 127.
- Verify-only dependency readback hashes: UID000072 `E3591F8815D6FC67A133E1E9534F0BE9B205A725E9274F02DC9D85500716A6AA`; UID00018T `A26F1F8BBB2A0D0D9B12E66D3FC694D5EF18669F1C86CB14B59BBBA07A00E7B1`; UID00040P `EE6C7BAE383D6B4BC7AAAA924C1C1717F0581C723C52A0477F9C572C94EE6059`; UID00040Q `4937444706F36C5278D1C86C2853A2C57142B729003070FD88DC4DEEEC6D87FF`; UID00040V `231AE8A9091C797E215A97BA9BEA043925DE3D22033142854FE0D9BB4BBB561C`; UID00040X `AE43F5536DAAC9931CA4C87344E82D10508DA43C8B84786345E0C2C139703D74`; resource `A35EA79A3E580305A0D233BF38A8F1093ACC1EDA73BDA46AF2FEA90F096C06E2`; LObject `B4D92014D4703B36DF0B0ADD8B9C6341BF29D58B17D19E5D59885AE09E48B63B`; MemoryMan `DFC517211BA8F0ABE749397B5F57D707A52239645645A70A376D77F2BBFC248C`; Application `580310E22614301954AB99153CB95A7A3DA5C145849E4B10651E0790413A0FF0`.
- Validator-owned generated/tracker files changed only through authorized validator flow; manual coverage, supervisor, audit, goal, IDA, and lifecycle files were not edited by B005.
- Leases: each ordinary lease was released immediately after its scoped validator; final lease report showed zero B005 leases.

## Implementation Tracking Checklist

- [x] Supervisor Gate 1 acceptance of this exact report artifact is recorded before implementation.
- [x] Re-read UID0001OS after acquiring its short one-file lease and preserve all current/concurrent detail.
- [x] Set UID0001OS to `92/94`, owner `0000RC`, false, blank emitter/position/formal, exact range/path/title, `Nested:0`.
- [x] Apply exact target Item Summary and C01-C24/C36-C37 evidence without compression.
- [x] Scoped-validate UID0001OS and immediately release its lease.
- [x] Re-read/lease UID0000RC only while editing it.
- [x] Set UID0000RC to `92/94`, retain owner/emitter `0000KK`, true, and set position `0`.
- [x] Apply Destination 2 exactly as the local class forward declaration plus sole module definition; add external-linkage/one-definition evidence and keep the matching external declaration in separate future proper header/class placement.
- [x] Scoped-validate UID0000RC and immediately release its lease.
- [x] Re-read/lease UID00041V only while editing it.
- [x] Set UID00041V to `92/94` and apply Destination 3 exactly while preserving every parser/helper/resource/negative fact.
- [x] Scoped-validate UID00041V and immediately release its lease.
- [x] Re-read/lease UID00018S only while editing it.
- [x] Set UID00018S to `92/94` and apply Destination 4 exactly while preserving every cleanup/helper/stale-name fact.
- [x] Scoped-validate UID00018S and immediately release its lease.
- [x] Re-read/lease UID00040R only while editing it.
- [x] Set UID00040R to `90/94`, owner NONE, false, blank emitter/position, and apply blank Destination 5.
- [x] Add exact EH-only/direct-Singleton no-code proof and historicalize the static-helper interpretation.
- [x] Scoped-validate UID00040R and immediately release its lease.
- [x] Re-read/lease UID00018V only while editing it.
- [x] Set UID00018V to `91/94`, owner NONE, false, blank emitter/position, and apply blank Destination 6.
- [x] Preserve exact cleanup, vtable, delete-flag, size-guard, optional-free, helper, padding, and historical evidence.
- [x] Scoped-validate UID00018V and immediately release its lease.
- [x] Re-read/lease UID00040W only while editing it.
- [x] Set UID00040W to `90/94`, retain semantic owner `000071`, set false, blank emitter/position, and apply blank Destination 7.
- [x] Add exact hierarchy/PMD/vtable/source-generated proof and scoped-validate/release UID00040W.
- [x] Re-read/lease UID000071 only while editing it; keep `89/92` and blank formal.
- [x] Add direct LObject/Singleton inheritance, EBO, lifetime lowering, separate future header-declaration/global-definition route, compiler exclusions, and exact class-tail no-placeholder cap.
- [x] Scoped-validate UID000071 and immediately release its lease.
- [x] Re-read/lease UID0000KK only while editing it; keep `89/89`, path, metadata, and unrelated inventory.
- [x] Add sole position-0 definition and corrected storage/EH/scalar/vtable source policy; scoped-validate/release UID0000KK.
- [x] Re-read/lease UID00018R only while editing it; preserve non-emitting aggregate metadata/formal/score and all children/padding.
- [x] Apply direct-Singleton lifecycle decomposition; scoped-validate/release UID00018R.
- [x] Re-read/lease UID00018U only while editing it; preserve split-index metadata/formal/score and lookup/copy detail.
- [x] Reclassify UID00040R in aggregate prose; scoped-validate/release UID00018U.
- [x] Verify UID000072, UID00018T, UID00040P, UID00040Q, UID00040V, UID00040X, resource, LObject, MemoryMan, Application, and adjacent singleton docs remain unchanged absent a concrete contradiction.
- [x] Confirm no new UID, split, merge, rename, range, padding, nested, third-party import, raw layout placeholder, or IDA mutation occurred.
- [x] Run one scoped validator per changed ordinary page while its lease is held; record command ID, timestamp, exit, ok, warnings, and side effects.
- [x] Confirm every ordinary lease is released immediately after its validator and no B005 lease remains.
- [x] After all leases clear, run one authorized final target/file validator with `--wait-generated`.
- [x] Verify generated LanguageMan.cpp contains exactly one UID0000RC global definition before constructor output, preceded only by its class forward declaration and containing no header external declaration.
- [x] Verify UID00041V constructor and UID00018S destructor each appear exactly once with no explicit singleton assignment/clear.
- [x] Verify zero UID0001OS, UID00040R, UID00018V, and UID00040W generated markers/bodies/comments.
- [x] Verify UID000071 class marker remains only as the independently bounded complete-class blocker and UID00018T remains unchanged.
- [x] Verify no duplicate global, raw address, vptr, PMD, RTTI/vtable array, EH helper, scalar wrapper, delete flag, cookie, or decompiler label appears as handwritten source.
- [x] Re-read current manual coverage after implementation and preserve exact no-loss row unions/placement; do not edit manual coverage.
- [x] Leave generated tracker/source writes to the authorized validator flow; do not edit them manually.
- [x] Update C01-C40 to legal terminal callback states with destination/validator/generated proof.
- [x] Update Validator Results, Changed Files, generated snapshots, lease proof, and checklist only after independent readback.
- [x] Preserve all historical assumptions, negative evidence, prior-report classifications, score caps, and class-tail no-placeholder proof.
- [x] Confirm no ordinary/manual/generated/tracker/supervisor/audit/validator-state/IDA/lifecycle file was edited outside the accepted callback workflow.
- [x] Never run/probe execute_report, lifecycle registry actions, report movement, or archival.
- [x] End the callback report with the supervisor-required terminal marker only after every accepted item is true.
- [x] Read the exact `2026-07-20T15:57:06-04:00` Gate 2 audit and preserve the 39 passing claims/formals/support edits unchanged.
- [x] Lease/reread UID0001OS, add the exact `0x00464c2e` read/non-null check/flag-1/`0x00464c3c` virtual scalar-delete route, validate as command `15417`, and release immediately.
- [x] Lease/reread UID0000RC, add the same exact Application shutdown route at report-level detail, validate as command `15418`, and release immediately.
- [x] Preserve both pages' accepted scores, metadata, managed blocks, source/header split, and compiler-wrapper no-code disposition.
- [x] Run waited command `15419` after lease closure and independently verify all accepted `LanguageMan.cpp` structural counts/exclusions remain unchanged.
- [x] Update C10 proof, both destination hashes, validator commands/results, generated/tracker snapshots, and current report lifecycle wording.
- [x] Confirm manual coverage remained read-only, the exact eleven-action handoff is unchanged, and no report lifecycle command ran.
- [x] Confirm zero B005 leases and exactly one terminal Gate 2 readiness marker after final readback.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000015430","destination_path":"executed-b-agent-research/B005/0001OS-g_pLanguageMan-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0001OS-g_pLanguageMan-source-quality.md","timestamp":"2026-07-20T16:25:13-04:00","uid":"0001OS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
