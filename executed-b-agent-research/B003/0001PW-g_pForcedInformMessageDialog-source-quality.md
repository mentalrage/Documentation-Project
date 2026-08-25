** TARGET-REPORT-UID:0001PW **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001PW g_pForcedInformMessageDialog Ownership / Source-Quality Research


## Finalized Report / Current Recommendation

- Implemented recommendation: physical storage [UID:0001PW] is `92/94`, `RECONSTRUCTABLE:FALSE`, semantic `CANONICAL_OWNER:0000QY`, with blank emitter/position/R0 and `Nested:0`; semantic global [UID:0000QY] is the sole position-0 source emitter for `ForcedInformMessageDialog *g_pForcedInformMessageDialog = NULL;` in `NexusTK/login/ForcedInformMessageDialog.cpp`.
- Implemented disposition: the executable slot is loader-zeroed virtual `.data`/BSS storage, not a raw-backed `0xffffffff` initializer. Direct `Singleton<ForcedInformMessageDialog>` inheritance explains constructor publication, destructor clearing, and EH cleanup without handwritten assignments in the constructor or destructor.
- Callback state: all accepted target/global/class/file/method/compiler/vtable changes are applied. UID000490 is validator-preserving renamed to `ForcedInformMessageDialogOnControlCommand`; UID000491 is validator-preserving renamed to `ForcedInformMessageDialogHandleKeyOrTextEvent`; no new page or range split was created.
- Confidence: `94` for storage, range, six-reference lifecycle, physical/semantic one-definition routing, compiler/source split, class layout, and source-ready C++03; exact original private field and helper spellings remain bounded confidence caps rather than blockers.

## Supporting Research

- Fresh evidence was collected against live IDA MCP database session `9b0396a3` at evidence time on 2026-07-21. `idb_list` returned one active adopted worker for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` returned `status:ok`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, and input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Corrected bounded calls succeeded: `get_bytes` returned four zeros at `0x0069b4a0`; `lookup_funcs` returned constructor `0x00587bb0` size `0x4c3`, key handler `0x00588160` size `0x8d`, and EH clear helper `0x0058aa90` size `0xb`; decompilation and disassembly were re-read for the constructor, destructor, button/key handlers, helper, thunks, scalar wrapper, main-menu cleanup, and EventMan key translator.
- Exact search terms were `UID0001PW`, `0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog`, `g_pForcedInformMessageDialog`, `ForcedInformMessageDialog`, `CloseMainMenuDialogSingletons`, and `EnsureLoginDialogPane`.
- `executed-b-agent-research/**` produced three material leads. Executed B008 `executed-b-agent-research/B008/0001J7-ForcedInformMessageDialogCore-source-quality.md`, SHA256 `DE24A791BCFED2EE1C2B4BD4A27F68D3C8AD8AB69C797EDA2182CADEB5F2717A`, is the prior family split and source-body lead; its explicit singleton assignments, old callback names, incomplete inheritance, and initializer uncertainty were independently revalidated and partly rejected here. Executed B010 `executed-b-agent-research/B010/00019J-CloseMainMenuDialogSingletons-source-quality.md`, SHA256 `1FE7890760A1D18B4564A628F5AA7B671772D5189606FFA99344B9113792A936`, corroborates only the cleanup read/call route. Executed B001 `executed-b-agent-research/B001/00019L-EnsureLoginDialogPane-source-quality.md`, SHA256 `592A5D5FAE891BF14033EE0ED10920136FDB358CF1057F167D60D1F36590BED9`, corroborates the login-helper owner and two destructor callers.
- `tools/leaser/Agents/Older-Research/**` contained no direct UID0001PW report; matches were older family mentions or generic singleton/initializer discussions and were treated as historical leads only.
- `tools/leaser/Agents/SpecialReports/**` contained no target-specific result.
- Active `tools/leaser/Agents/Agent-B001` through `Agent-B005` research trees contained no active exact-target report or accepted conflicting callback. Incidental ForcedInform references were consumers/support, not ownership evidence.
- Current ordinary pages, generated output, four manual coverage roots, PE bytes/headers, and the lease ledger were reread during research and again after implementation. Historical report-only no-edit state is superseded by the callback proof below.

## Target

- Target UID: `0001PW`.
- Target path: `by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md`.
- Source queue/report row: current tracker `## by-memory` -> `### Not-Covered Files - Reconstructable` selection.
- Supervisor classification: accepted report followed by bounded implementation callback for the physical singleton slot and complete ForcedInform source/compiler family.
- Implemented scores and parent state: target `92/94`, `CANONICAL_OWNER:0000QY`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/R0, `Nested:0`; semantic UID0000QY is `92/94`, reconstructable, owner/emitter UID0000JJ, position `0`, with exact R1.

## Current Target State

- Implemented target SHA256 is `D3AD17FED6843F6F5923F57E68AD6BF20408FD9F54172E6D9FF223C361B74965`, 10,835 bytes / 92 lines. The physical/semantic one-definition contradiction is closed and historical `0xffffffff` text is explicitly superseded.
- Historical pre-callback generated checkpoint was command `000000015999`, refreshed `2026-07-21T16:26:23-04:00`, SHA256 `3D3A939E1FA5820E5C6F3669CDF759331CC7C5329431DB607510FA15F63FB1EF`, 6,097 bytes / 162 lines, with stale C++11, explicit lifecycle writes, old method/type/helper names, a raw offset comment, and three relevant markers.
- Callback generated checkpoint is waited validator command `000000016132`, refreshed `2026-07-21T17:49:05-04:00`, SHA256 `535DDBEFC649E3A9457EB9A8EC35A8B13E667B11C82586CF2982B47991179A93`, 6,341 bytes / 165 lines. It has the sole global definition before the complete closed class; constructor, destructor, `OnControlCommand`, and `HandleKeyOrTextEvent` each occur once; old names, relevant markers, raw RTTI/vtables, scalar/EH/delete text, and body-level singleton assignments are zero.
- B003 completed ordinary implementation and scoped/waited validation but performed no `execute_report`, report move/archive, or lifecycle command. Exact current report path/status and later external lifecycle state are supervisor/validator-owned.

## Executive Recommendation

- Keep exact storage range and semantic name, but separate physical compiler/storage evidence from the sole source definition.
- Route the only global definition through UID0000QY at emitter position `0`; route the complete class through UID00005E at position `10`; keep source method children under UID0000JJ; make UID0001PW and UID0003DK non-emitting; retain UID0001J8/UID0001J9/UID0001JA as non-emitting compiler support.
- Correct source shape to direct `DialogPane, Singleton<ForcedInformMessageDialog>` inheritance, C++03 declarations/bodies, `OnControlCommand(int,int)`, and `HandleKeyOrTextEvent(Event *)` using `g_pEventMan->TranslateEventKey` before the key-down gate.
- No evidence remains that requires a new page, owner, source file, or delayed blocker pass.

## Supervisor Active Recheck

- The supervisor assigned a fresh direct pass specifically because the old family work left the initializer, one-definition route, compiler/source lowering, class declaration, and generated markers unresolved.
- The target does not require a range split. The existing exact four source children and three compiler-support pages are correctly bounded; two source child titles require UID-preserving renames.
- Every source-bearing destination in scope has complete destination-ready C++03 below; every physical/compiler destination has a blank formal plus exact no-code proof.

## Inference Research Guidance Check

- `by-structure.md` and current validator conventions were applied: physical storage may carry semantic ownership while remaining non-emitting; a semantic global emits exactly one definition; compiler RTTI/vtable/EH/scalar pages remain blank; `[[CHILDREN]]` follows the closed class.
- Existing documentation was treated as fallible. Specifically, `0xffffffff`, explicit constructor/destructor singleton writes, class inheritance lacking `Singleton<T>`, `OnButtonResponse`, `OnKeyInput`, `InputEvent`, and CRT `do_narrow` were rechecked rather than inherited.
- Direct facts are labeled IDA/PE evidence; source-facing names, access, and file placement are evidence-backed inference; rejected alternatives are explicit.
- No current Wave2/Wave3 override or artifact was found. Any historical Wave2/Wave3 wording encountered in broad roots was ignored as stale.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and evidence-backed resolution | Status |
| --- | --- | --- |
| Zero versus `0xffffffff` initializer | Live IDA bytes are four zeros. PE section arithmetic proves the slot lies `0x20ca0` bytes beyond raw-backed `.data`, so no raw initializer exists and the loader supplies zeros. Use `NULL`; historical `0xffffffff` is rejected. | Direct proof |
| Physical versus semantic definition | UID0001PW is address/storage evidence; UID0000QY is the source symbol. One global definition belongs on UID0000QY, while UID0001PW becomes false/non-emitting. | Policy plus direct evidence |
| Constructor publish/fallback clear | RTTI shows direct `Singleton<ForcedInformMessageDialog>` at PMD `+0x26c`; the constructor's `lea/test/store` sequence is empty-base template lowering. Do not handwrite the assignment. | Direct ABI inference |
| Destructor clear | Reverse direct-base destruction explains the clear after the derived destructor body. Source destructor contains only the accepted EPF/login restore condition. | Direct ABI inference |
| EH helper | Exact 11-byte store-zero/return body, one EH metadata/funclet ref, no ordinary caller. It is compiler cleanup for the Singleton base. | Compiler-only |
| Adjustor thunks | Two exact 11-byte thunks subtract `0xa0`/`0xa4` and jump to scalar wrapper; only vtable refs. | Compiler-only |
| Scalar wrapper | Vptr reinstalls, source destructor behavior, Singleton clear, DialogPane cleanup, scalar flags, and optional delete are compiler ABI lowering. | Compiler-only |
| Button method name/signature | Primary vtable cell `0x0062d760` is inherited `DialogPane` slot `+0x48`; body ends `retn 8`, reads first argument, ignores second. Exact source override is `OnControlCommand(int controlIndex, int notifyCode)`, not one-argument `OnButtonResponse`. | Direct vtable/ABI proof |
| Key method name/signature | Secondary EventHandler slot `0x0062d780`, one stack argument, `retn 4`, Boolean return in AL. Current interface is `HandleKeyOrTextEvent(Event *)`, not `OnKeyInput(const InputEvent *)`. | Direct vtable/ABI proof |
| Key translator | `0x004a8b10` is the ten-byte EventMan translator with 81 callers; current project support rejects stale CRT `do_narrow`. Push order is modifiers then key, so source argument order is key then modifiers. Translation occurs before event-type test. | Direct code plus current support |
| Object layout | RTTI CHD has eight bases; Singleton BCD PMD is `+0x26c`; DialogPane occupies `0x26c`; EBO permits the Singleton base and `m_bAccepted` to share `+0x26c`; natural tail alignment closes size `0x270`. | Direct RTTI/layout proof |
| Constructor liveness | No direct static caller or constructor VA/RVA pointer was found. Three vtable stores, RTTI, complete destructor family, resource refs, singleton lifecycle, and four source methods prove a retained source class; absence of a static call is a liveness cap, not no-source proof. | Positive plus bounded negative proof |
| Resource/source placement | `DLGSTAFF.PAL/.EPF/.EPD`, login restoration, main-menu cleanup, and `NexusTK/login/` route identify a distinct ForcedInform module; SystemMessagePanes and StaffsDialogPane are adjacency/prefix alternatives only. | Strong inference |
| C++ era/style | Replace `constexpr` and decompiler scaffolding with C++03 `const`, `NULL`, source helpers, normal inheritance, and ordinary virtual methods. No vptr stores, raw addresses, EH code, scalar flags, or offset comments. | Source-quality closure |

Rejected alternatives:

- `static ForcedInformMessageDialog *`: rejected because main-menu cleanup and other translation-unit routes require external linkage.
- Class static member: rejected because current semantic-global architecture and direct Singleton template use an external pointer symbol.
- Explicit `g_pForcedInformMessageDialog = this/NULL` in authored constructor/destructor: rejected by direct Singleton base PMD/order and compiler-helper parity.
- `0xffffffff` sentinel: rejected by PE raw/virtual mapping and live bytes.
- `OnButtonResponse(int)` and `OnKeyInput(const InputEvent *)`: rejected by current base interfaces, stack cleanup, and vtable slots.
- Raw vtable arrays or literal-pool pages: rejected because declarations/method bodies regenerate them.
- SystemMessagePanes, StaffsDialogPane, MainMenuPane, LoginDialogPane, TextEditPane, ScreenDimmer, or Application ownership: each is adjacency, resource-prefix, caller, or dependency evidence only.

## Evidence Standards Used

- Highest-weight evidence: live IDA MCP bytes, decompilation/disassembly, function bounds, xrefs, callers/callees, vtable/RTTI cells, and exact PE section arithmetic.
- Corroboration: local executable byte scans, SHA256 body hashes, current by-* pages, current generated output, manual coverage roots, executed B008/B010/B001 reports, and adjacent-range documentation.
- Inference was accepted only when multiple independent facts agreed: direct Singleton PMD plus publication/clear order; vtable slot plus ABI cleanup plus current interface; resource refs plus lifecycle consumers plus file route.
- Negative evidence was bounded rather than overclaimed: absence of a static constructor caller does not prove dead code; it only caps confidence after VA/RVA/raw/pointer/callback routes were exhausted.
- Tool limitations do not affect the conclusion. One initial PowerShell HTTP attempt failed before transport because `-UseBasicParsing` was omitted, and two later client calls used obsolete parameter names; those client-side errors were excluded. Corrected MCP calls against the healthy session succeeded.

## Evidence Checked

- IDA MCP: `idb_list`, `server_health`, `get_bytes`, `lookup_funcs`, `decompile`, function analysis, data/code xref searches, immediate/byte-pattern searches, vtable/RTTI reads, callers/callees, and target/global value reads.
- PE/local: executable SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, PE32 headers, section table, target RVA/raw mapping, exact target-VA pattern occurrences, absent target-RVA and constructor VA/RVA patterns, function-range bytes, and SHA256 hashes.
- Current documentation: target, semantic global, class, file, split parent, four method children, three compiler-support pages, vtable page, main-menu cleanup, EnsureLoginDialogPane, resources, neighbors, DialogPane/Event/EventMan/Singleton dependencies, generated source, four manual coverage roots, tracker selection, and current leases.
- Prior reports: exact executed B008/B010/B001 artifacts and broad historical/special/active-root searches described above.
- Negative checks: no direct constructor xref/caller; no constructor VA/RVA/raw pointer pattern; no target RVA encoding; no startup/factory/table/vtable pointer to the constructor or storage; no seventh storage reference; no independent source body for EH helper/thunks/scalar wrapper/vtable data; no raw initializer bytes; no alternate RTTI class or source file owner.
- Intentionally skipped: no IDA mutation, validator, generated refresh, coverage edit, tracker edit, report execution, lifecycle command, or ordinary-file edit is permitted during Gate 1.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Mandatory MCP evidence used healthy database `9b0396a3` with real bounded bytes/lookups/decompilation. | 99 | idb_list, health, bytes, lookup, decompile | UID0001PW Evidence; all touched evidence sections | incorporate | applied |
| C02 | `[0x0069b4a0,0x0069b4a4)` is a four-byte loader-zeroed pointer slot in virtual `.data`, outside raw-backed bytes. | 99 | live zeros; PE section arithmetic | UID0001PW | incorporate | applied |
| C03 | Historical `0xffffffff` initializer language is false for this PE and must remain only as superseded history. | 99 | no raw bytes; zero-fill mapping | UID0001PW; UID0000QY; coverage row | historicalize | applied |
| C04 | Exactly six refs exist at `0x004f69ec`, `0x00587c17`, `0x00587c1e`, `0x005880e2`, `0x0058aa90`, `0x0058ac59`. | 99 | MCP xrefs; executable pattern scan | UID0001PW; UID0000QY; UID0001J7; UID0000JJ | incorporate | applied |
| C05 | Constructor has no direct static route, but retained source liveness is proven by RTTI/vtables/resources/destructor family. | 94 | zero caller/pattern results plus positive family evidence | UID0001J7; UID00048Y; UID0000JJ | incorporate | applied |
| C06 | Physical UID0001PW must be false/non-emitting; semantic UID0000QY owns the sole source definition. | 99 | one-definition policy and generated markers | UID0001PW; UID0000QY | incorporate | applied |
| C07 | Sole C++03 definition is externally linked, zero-initialized, emitter position 0, with class forward declaration. | 96 | cross-TU read and source route | UID0000QY R1 | incorporate | applied |
| C08 | Class directly inherits DialogPane and Singleton<ForcedInformMessageDialog>; size is 0x270 with EBO at +0x26c and natural tail padding. | 97 | RTTI CHD/BCD PMD, vtable views, allocation/layout | UID00005E R2 | incorporate | applied |
| C09 | Constructor authored behavior is UI/resource setup; publication/fallback/vptr/EH are lowering and explicit singleton writes must be removed. | 96 | constructor CFG/decompile/RTTI | UID00048Y R3; UID0001J7 | incorporate | applied |
| C10 | Ordinary destructor authored body is only guarded EnsureLoginDialogPane; Singleton/base lowering clears storage implicitly. | 97 | ordinary/scalar parity and direct-base order | UID00048Z R4; UID0001JA | incorporate | applied |
| C11 | UID0001J8 is compiler/EH Singleton-base cleanup, false/non-emitting with blank R8. | 99 | exact 0xb body and sole EH ref | UID0001J8 | incorporate | applied |
| C12 | UID0001J9 is two compiler adjustor thunks, false/non-emitting with blank R9. | 99 | exact bodies/vtable refs | UID0001J9 | incorporate | applied |
| C13 | UID0001JA is compiler scalar deleting wrapper, false/non-emitting with blank R10. | 99 | vptr/source/base/flag/delete decomposition | UID0001JA | incorporate | applied |
| C14 | UID000490 must be UID-preserving renamed to OnControlCommand and receive exact two-argument R5. | 98 | primary slot +0x48, retn8, second arg unused | UID000490; class/file/parent links | incorporate | applied |
| C15 | UID000491 must be UID-preserving renamed to HandleKeyOrTextEvent and receive exact Event/EventMan R6. | 98 | secondary slot +0x08, retn4, Event layout, translator | UID000491; class/file/parent links | incorporate | applied |
| C16 | UID0003DK is exact compiler RTTI/vtable data, semantic owner UID00005E, false/non-emitting blank R11. | 99 | table/COL/store/thunk/RTTI evidence | UID0003DK | incorporate | applied |
| C17 | UID0001J7 remains a blank non-emitting split index; UID0000JJ remains the distinct login source root with corrected inventory/order. | 97 | exact children/padding/resources/routes | UID0001J7 R7; UID0000JJ | incorporate | applied |
| C18 | Main-menu cleanup, EnsureLoginDialogPane, resource literals, neighbors, DialogPane/Event/EventMan remain valid verify-only support. | 97 | current pages and fresh evidence | UID00019J/00019L/0003GQ/neighbors/dependencies | already-present | already-present |
| C19 | Recommended metadata/scores and R0-R11 remove all family source-quality blockers and three relevant generated markers. | 95 | exhaustive score-blocker and generated review | all recommended ordinary destinations | incorporate | applied |
| C20 | Thirteen exact supervisor-owned manual coverage actions are currently unapplied and are no-loss: nine replacements retain every valid current-row fact verbatim or explicitly historicalize the one disproved/pending clause before appending accepted additions, while four absent child rows are clearly identified as additions. | 99 | current four manual roots, exact row/anchor reread, and row-by-row retained/superseded/addition comparison | manual by-memory/global/class/file roots | incorporate | excluded-with-reason |

Implementation proof:

| Claim | Terminal proof |
| --- | --- |
| Proof C01 | UID0001PW, UID0001J7, UID00048Y/48Z/490/491, UID0001J8/1J9/1JA, UID0003DK, UID0000QY, UID00005E, and UID0000JJ now retain the healthy evidence-time session `9b0396a3`, bounded-call facts, and body/table hashes; scoped validators `16112`-`16132` all exited 0 with `ok:1`. |
| Proof C02 | UID0001PW is `92/94`, false, blank-emitter/R0, and documents target RVA, `.data` virtual/raw sizes, raw-backed end, `0x20ca0` zero-fill displacement, and live `00 00 00 00`; validator `16114`. |
| Proof C03 | UID0001PW and UID0000QY preserve the former `0xffffffff` observation only as superseded history and select C++03 `NULL`; validators `16114`/`16115`; exact supervisor coverage replacement text retains the correction but remains externally owned. |
| Proof C04 | UID0001PW, UID0000QY, UID0001J7, and UID0000JJ preserve the exact one-read/two-constructor-store/three-clear address inventory and local executable six-occurrence scan; validators `16114`, `16115`, `16122`, `16132`. |
| Proof C05 | UID0001J7/UID00048Y/UID0000JJ retain zero code callers and VA/RVA/direct-call patterns as bounded negatives while recording RTTI, three vtable views, resources, Singleton lifecycle, four bodies, and destructor parity; validators `16122`, `16124`/`16131`, `16132`. |
| Proof C06 | UID0001PW registry changed true/emitter0000QY to false/blank under validator `16114`; UID0000QY is the sole reconstructable source definition under validator `16115`; generated command `16132` contains one definition and zero UID0001PW marker. |
| Proof C07 | UID0000QY exact R1 parity is true, position is `0`, score is `92/94`, and command `16132` places the forward declaration/definition before the class; validator `16115`. |
| Proof C08 | UID00005E exact R2 parity is true at `93/94`, position `10`; the documented eight-base RTTI, direct Singleton PMD, EBO overlap, 0x270 layout, natural tail alignment, and class closure precede children; validator `16116` and generated command `16132`. |
| Proof C09 | UID00048Y exact R3 parity is true at `92/94`; it uses C++03 `const`, preserves duplicated branch-local text setup, and excludes explicit publication, fallback clear, vptr/EH/raw-offset, and fabricated helper source; validators `16124` and parity repair `16131`. |
| Proof C10 | UID00048Z exact R4 parity is true at `92/94`; only the guard/helper call remains in source, while UID0001JA documents Singleton/base clear and scalar lowering; validators `16125` and `16129`; generated body-level singleton assignments are zero. |
| Proof C11 | UID0001J8 is `90/94`, false/NONE, blank R8, with exact `0xb`/3-instruction/hash/sole-EH-route proof; validator `16127`. |
| Proof C12 | UID0001J9 is `90/94`, false/NONE, blank R9, with both exact `0xb` adjustor bounds, three-instruction forms, combined hash, and vtable-only routes; validator `16128`. |
| Proof C13 | UID0001JA is `92/94`, false/NONE, blank R10, with exact `0xc2`/62-instruction hash and vptr/authored-guard/Singleton/base/flag/delete/guard decomposition; validator `16129`. |
| Proof C14 | Validator `16112` UID-preserving renamed UID000490, updated registry/reverse links, set `92/94`, and installed exact R5; generated command `16132` has one `OnControlCommand`, zero `OnButtonResponse`, and no wrong-range duplicate. |
| Proof C15 | Validator `16113` UID-preserving renamed UID000491 and updated registry/reverse links; validators `16113`/`16126` leave exact R6 at `92/94`; generated command `16132` has one `HandleKeyOrTextEvent`, zero `OnKeyInput`, and correct translation-before-type order. |
| Proof C16 | UID0003DK is `92/94`, semantic owner UID00005E, false, blank emitter/position/R11, `Nested:-4`, with exact range/hash/COL/table/RTTI/store/thunk/successor proof; validator `16130`; generated raw RTTI/vtable arrays and UID marker are zero. |
| Proof C17 | UID0001J7 is `92/94`, false/NONE, blank R7, `Nested:4`, with four exact children/pads/hashes and complete source/compiler inventory; UID0000JJ is `92/93` at the unchanged login route with corrected definition/class/method order; validators `16122`/`16132`. |
| Proof C18 | UID00019J `DD3260F5891B316BF9240F78F64702317C86ECE0CB3C8DB4889259E9F754A5D5`, UID00019L `FB4890E0C46F371FE1DD0B17C544E6082EBF0E72B9F104BF0C68067E8AF66`, UID0003GQ `2D0D8138724E435EA4DF0A16F4F21E8045AD27C4891B762AACB456A5704B0D52`, UID0001PV `40304F9A9611D705CD950CE3629CC4B443F4CC73438CBF7E853739A67921EE9B`, UID00029W `F0A576B23E33DCFD991D01A10A429DC407015F2AE2D112AEFC01BBA3E8C8E9E7`, and named interface/resource dependencies were reread and left verify-only; no contradiction was found. |
| Proof C19 | All 13 ordinary destinations carry accepted tuples; all twelve R0-R11 blocks are byte-for-byte equal to the accepted report; generated command `16132` removes the three relevant markers and emits one global/class/four methods with no stale/compiler-authored output. |
| Proof C20 | The exact thirteen-row no-loss handoff remains report text only. Current manual roots were reread after unrelated external drift and remain unapplied for this family; B003 did not edit coverage. Exclusion is ownership-based, not an implementation blocker. |

## Positive Evidence Summary

- Four live zeros plus PE zero-fill arithmetic directly resolve the initializer.
- Six and only six address refs form a complete lifecycle: one read, two constructor stores, three teardown/cleanup clears.
- Direct Singleton RTTI PMD `+0x26c` matches the constructor `lea/test/store`, destructor order, EH clear helper, and class EBO layout.
- Three vtable views and exact callback cells prove class identity, callback ownership, and method signatures.
- Constructor resource refs and destructor login restoration place the module in `NexusTK/login/ForcedInformMessageDialog.cpp`.
- Ordinary/scalar parity cleanly separates authored destructor behavior from compiler ABI support.
- Current Event/EventMan support resolves the key method and translator without raw names or stale CRT semantics.

## IDA MCP Facts

- Database at evidence time: `9b0396a3`; IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; module `NexusTK.exe`; imagebase `0x00400000`; health `ok`.
- Target bytes: `00 00 00 00`; adjacent `0x0069b490` 48-byte read is also zero-filled at analysis time.
- Function facts and exact body hashes:

| Range | Size | Instructions | Role | SHA256 |
| --- | ---: | ---: | --- | --- |
| `0x00587bb0-0x00588073` | `0x4c3` | 430 | constructor | `A82ED3870204B8326E6FF1EE33F00380C74F48D24E0A70106E8D2EB7BF50D1EA` |
| `0x00588080-0x00588101` | `0x81` | 41 | ordinary destructor | `EBC61935D70257897C200D163B3347994CFCEB84D373BCFF93140D6C84266CAF` |
| `0x00588110-0x0058815d` | `0x4d` | 25 | control command | `D85211157B749B492DDBE2832FB48E2ED17BD03F625E6B42188A203FBBF68FB1` |
| `0x00588160-0x005881ed` | `0x8d` | 44 | key/text event | `235BDE76233C8DB7042AE38914229C03A41836B52E960345241949D64A97DBD4` |
| `0x0058aa90-0x0058aa9b` | `0xb` | 3 | EH Singleton clear | `FDD72B5AAC0E252BAE32F8EC00072CE0FB97D591F6B552923D3E17962B939F41` |
| `0x0058aadb-0x0058aaf1` | `0x16` | 6 | two adjustor thunks | `D2B17601D2EBD02AABDAEA862AB548C7DC265785B8E2C26148C46A454DA28E18` |
| `0x0058abf0-0x0058acb2` | `0xc2` | 62 | scalar deleting wrapper | `EDA111C5C3343C9006F8DE6FC21121CF8F08B336167668DCB77B4681AB7465BD` |
| `0x0062d714-0x0062d7b0` | `0x9c` | n/a | COL/vtable island | `A05CB0CFC89A90A4E4865877A7CD700ABF3536EECCF0670DD2D0543D84E962AE` |
| `0x004f69a0-0x004f6a31` | `0x91` | n/a | main-menu cleanup | `D534C0EAE23013DCBD4ED88BB03D954B5F027061616B5BF576BE4707F13A54FF` |

- PE facts: target RVA `0x29b4a0`; `.data` RVA `0x26d000`, virtual size `0x2fe24`, raw size `0xd800`, raw pointer `0x26ac00`; raw-backed end RVA `0x27a800`; target is `0x20ca0` bytes into zero-fill beyond that end.
- Local executable scan found target VA bytes `a0 b4 69 00` at exactly six raw offsets corresponding to the six refs; target RVA bytes `a0 b4 29 00`, constructor VA/RVA pointer forms, and direct constructor call/pointer patterns had zero matches.
- Vtable/COL facts: locator/table pairs begin at `0x0062d714/0x0062d718`, `0x0062d774/0x0062d778`, and `0x0062d7a4/0x0062d7a8`; complete-object view offsets are `0`, `0xa0`, and `0xa4`; CHD has eight bases; Singleton BCD PMD is `(0x26c,-1,0)` with attribute `0x40`.
- Resource refs: `DLGSTAFF.PAL` at `0x0062d9a0`, `DLGSTAFF.EPF` at `0x0062d9bc`, `DLGSTAFF.EPD` at `0x0062d9d8`; constructor references them at `0x00587c85`, `0x00587c92`, `0x00587e1b`, `0x00587f04`, and `0x00587fe5`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00587bb0-0x005881ed` | UID0001J7 `ForcedInformMessageDialogCore.md` | physical split index | false | none | `90/92 -> 92/94` | implemented, blank R7 |
| `0x00587bb0-0x00588073` | UID00048Y constructor | authored constructor | true | UID00005E/0000JJ | `89/91 -> 92/94` | implemented R3 |
| `0x00588080-0x00588101` | UID00048Z ordinary destructor | authored destructor | true | UID00005E/0000JJ | `89/91 -> 92/94` | implemented R4 |
| `0x00588110-0x0058815d` | UID000490 `ForcedInformMessageDialogOnControlCommand.md` | authored virtual | true | UID00005E/0000JJ | `90/92 -> 92/94` | UID-preserving rename implemented, R5 |
| `0x00588160-0x005881ed` | UID000491 `ForcedInformMessageDialogHandleKeyOrTextEvent.md` | authored virtual | true | UID00005E/0000JJ | `89/91 -> 92/94` | UID-preserving rename implemented, R6 |
| `0x0058aa90-0x0058aa9b` | UID0001J8 Singleton clear | compiler EH helper | false | none | `86/90 -> 90/94` | implemented, blank R8 |
| `0x0058aadb-0x0058aaf1` | UID0001J9 destructor thunks | compiler adjustors | false | none | `86/90 -> 90/94` | implemented, blank R9 |
| `0x0058abf0-0x0058acb2` | UID0001JA destructor | compiler scalar wrapper | false | none | `88/91 -> 92/94` | implemented, blank R10 |
| `0x0062d714-0x0062d7b0` | UID0003DK vtable data | compiler RTTI/vtables | false | semantic UID00005E | `87/93 -> 92/94` | implemented, blank R11 |
| `0x0069b4a0-0x0069b4a4` | UID0001PW physical slot | storage evidence | false | semantic UID0000QY | `86/90 -> 92/94` | implemented target, blank R0 |
| semantic global | UID0000QY | sole source definition | true | UID0000JJ | `87/90 -> 92/94` | implemented R1, position 0 |
| class | UID00005E | complete declaration | true | UID0000JJ | `89/89 -> 93/94` | implemented R2, position 10 |
| file | UID0000JJ | source root/inventory | true | file | `88/88 -> 92/93` | implemented prose/route |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f69ec` | read in `0x004f69a0` | main-menu cleanup checks and closes the active dialog |
| `0x00587c17` | constructor store | direct Singleton base publishes adjusted complete-object pointer |
| `0x00587c1e` | constructor fallback zero | null-adjusted Singleton base fallback |
| `0x005880e2` | ordinary destructor zero | reverse direct-base Singleton destruction |
| `0x0058aa90` | helper zero | constructor EH cleanup for Singleton base |
| `0x0058ac59` | scalar wrapper zero | compiler wrapper's Singleton-base cleanup |
| `0x0062d760 -> 0x00588110` | primary vtable data | `OnControlCommand(int,int)` override |
| `0x0062d780 -> 0x00588160` | secondary EventHandler vtable | `HandleKeyOrTextEvent(Event *)` override |
| `0x0062d718 -> 0x0058abf0` | primary vtable data | scalar deleting destructor compiler entry |
| `0x0062d778/0x0062d7a8` | thunk vtable cells | adjusted secondary/tertiary deleting entries |
| `0x005880db/0x0058ac52 -> 0x004f8b30` | two destructor callers | accepted EPF teardown may restore LoginDialogPane |
| constructor entry | zero direct callers/xrefs | bounded liveness negative; not no-source proof |

## Documentation Evidence And IDA Status

- Historical pre-callback target/global pages preserved the six refs but left initializer and source definition unresolved; current UID0001PW/UID0000QY close both with false physical routing and a sole position-0 definition.
- Historical pre-callback B008-derived methods contained useful exact behavior but stale source shape: explicit Singleton writes, C++11 `constexpr`, phantom helper factorization, old callback names/types, and a raw offset comment. Current R3-R6 remove those defects while retaining behavior/evidence.
- Historical pre-callback class lacked direct Singleton inheritance and used stale declarations; historical UID0003DK was reconstructable/blank and emitted a marker. Current UID00005E has complete R2 and UID0003DK is false/non-emitting blank R11.
- Historical pre-callback file prose repeated stale child names and explicit publication/clear semantics. Current UID0000JJ preserves the login route and StaffsDialog/SystemMessagePanes separation while documenting exact source/compiler order and implicit lifecycle.
- Generated command `15999` is explicitly historical pre-callback evidence. Current waited command `16132`, SHA256 `535DDBEFC649E3A9457EB9A8EC35A8B13E667B11C82586CF2982B47991179A93`, proves the applied one-definition/method/marker/compiler-exclusion state.
- Current read-only manual coverage snapshots are: by-memory SHA256 `316B019A623ED9D9698B7F52BF8755BC8084AD7797090788635FF47FE42297DC`, 1,927,924 bytes / 4,489 lines; by-global `DAD2BCB4C1E0B0872D32A4A4B821D5F4589148E5BF55C018A5A247F98729666C`, 96,267 / 214; by-class `6753174CAF0231C2687960A50E423B36F734D7FAA31128B66C38F2A6BDA1B9A1`, 250,232 / 623; by-file `FD97F683E662F9EC15A35DD6903F78BB4DD93A3A74E359DB793A54D3130E83CF`, 147,196 / 316. Unrelated external drift did not change ForcedInform row text; exact handoff remains unapplied and supervisor-owned.

## Ranked Ownership Analysis

### 1. UID0000QY semantic global in UID0000JJ ForcedInformMessageDialog

- Evidence for: exact source-facing symbol, six complete lifecycle refs, external main-menu consumer, class-specific Singleton RTTI, current login source route, and one-definition architecture.
- Evidence against: no symbols/header survive; exact original declaration placement is inferred.
- Decision: strongest source owner and sole emitter; inferred placement uncertainty is already bounded by position/file evidence.

### 2. UID0001PW physical storage page

- Evidence for: exact address, pointer width, zero-fill, and lifecycle xrefs.
- Evidence against: emitting here duplicates the semantic global and leaks physical layout into source.
- Decision: retain semantic owner link to UID0000QY, but `RECONSTRUCTABLE:FALSE`, blank emitter/formal.

### 3. Adjacent or consuming families

- Evidence for: MainMenuPane reads it; LoginDialogPane helper is called on teardown; SystemMessagePanes/vtable data are adjacent; StaffsDialog shares `DLGSTAFF` prefix.
- Evidence against: none owns class RTTI, constructor resources, all methods, or singleton lifecycle.
- Decision: support/consumer relationships only; reject ownership.

### Proposed new file/grouping, if applicable

- No new file. Preserve existing `NexusTK/login/ForcedInformMessageDialog.cpp` / `.h` route.
- Likely full contents are one global definition, complete class declaration, constructor, ordinary destructor, control command, key/text event handler, and source literals embedded in methods.
- Compiler EH/thunk/scalar/vtable pages remain documentation-only.

## Source Placement

- Recommended placement: UID0000QY definition, UID00005E declaration, and UID00048Y/48Z/490/491 bodies in `NexusTK/login/ForcedInformMessageDialog.cpp` with the corresponding header declaration.
- This placement fits `EnsureLoginDialogPane`, main-menu/login lifecycle, existing validator route, and distinct forced-information resources.
- Reject `SystemMessagePanes.cpp`, `StaffsDialogPane.cpp`, `MainMenuPane.cpp`, and `LoginDialogPane.cpp` as direct owners. They are physical neighbors, resource-prefix siblings, consumer, and callee respectively.
- Remaining original filename/header spelling uncertainty does not affect the established validator path or first-draft source quality.

## Range / Split / Padding / Reclassification Analysis

- Target exact half-open range remains `[0x0069b4a0,0x0069b4a4)`, size 4. Predecessor UID0001PV ends exactly at `0x0069b4a0`; successor UID00029W starts exactly at `0x0069b4a4`; no padding is owned by the target.
- Method parent remains `[0x00587bb0,0x005881ed)` with exact existing children. Internal/post-child `0xcc` spans remain `0x00588073-0x00588080` (13), `0x00588101-0x00588110` (15), `0x0058815d-0x00588160` (3), and parent-external successor alignment `0x005881ed-0x005881f0` (3).
- Vtable page remains locator-inclusive `[0x0062d714,0x0062d7b0)` and excludes successor locator at `0x0062d7b0`.
- Reclassification only: UID0001PW true -> false, UID0003DK true -> false. No page split/new UID/padding edit is required.
- Nested metadata remains UID0001J7 `4`, all four source children `0`, compiler pages `0`, vtable `-4`, target `0`; no relative nesting delta changes.

## Negative Evidence Summary

- No raw bytes back `0xffffffff`; no target-RVA encoding or seventh storage ref exists.
- No static constructor caller, function pointer, startup/factory registration, data-table entry, callback cell, or VA/RVA raw pattern points to `0x00587bb0`.
- No evidence supports two source definitions, a class static member, internal linkage, or explicit lifecycle assignments.
- No independent source route exists for the EH clear, adjustor thunks, scalar deleting wrapper, RTTI, COL, or vtables.
- No second class RTTI or object layout supports old one-base declaration.
- No ABI evidence supports one-argument `OnButtonResponse` or const `InputEvent` key callback.
- No current interface evidence supports CRT `do_narrow`; EventMan translator is the project source abstraction.
- No adjacency/resource-prefix/caller relationship displaces ForcedInformMessageDialog source ownership.

## IDA Rename / Type / Comment Recommendations

- Do not mutate IDA during this assignment.
- Source-facing type: `ForcedInformMessageDialog *` at `0x0069b4a0`; zero initializer; external linkage.
- Validator-aware UID-preserving page rename recommendations:
  - UID000490: `by-memory/0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand.md`.
  - UID000491: `by-memory/0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent.md`.
- Retain recovered `dword_69B4A0`, `sub_*`, old titles, CRT label, `0xffffffff`, and explicit-global drafts only as historical/superseded provenance in prose.
- Exact original private field spelling is not provable; `m_bAccepted` is the strongest behaviorally descriptive project-style name and is safe for draft source.

## First-Draft C++ Recommendation

- Eligible source destinations are UID0000QY, UID00005E, UID00048Y, UID00048Z, UID000490, and UID000491.
- UID0001PW, UID0001J7, UID0001J8, UID0001J9, UID0001JA, and UID0003DK require blank formal blocks under exact physical/index/compiler no-code proofs.
- Third-party import directives are not applicable; all code is project-authored NexusTK source.

### R0 - UID0001PW physical storage - blank

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

No-code proof: this page represents loader-zero physical storage. R1 emits the sole semantic source definition; any R0 data would duplicate it.

### R1 - UID0000QY semantic global definition

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ForcedInformMessageDialog;

ForcedInformMessageDialog *g_pForcedInformMessageDialog = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R2 - UID00005E complete class declaration

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

class ForcedInformMessageDialog : public DialogPane,
                                  public Singleton<ForcedInformMessageDialog>
{
public:
    ForcedInformMessageDialog(const wchar_t *messageText, Pane *parentPane, Layer *layer);
    virtual ~ForcedInformMessageDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    bool m_bAccepted;
};

extern ForcedInformMessageDialog *g_pForcedInformMessageDialog;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R3 - UID00048Y constructor

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {
const int kForcedInformDialogConfigId = 15;
const int kForcedInformAcceptButtonImage = 14;
const int kForcedInformDeclineButtonImage = 22;
const int kForcedInformHoverControl = 2;
const int kForcedInformFocusedControl = 2;
const int kForcedInformPendingControl = 3;
const short kForcedInformMaxLines = 2000;
const short kForcedInformMaxLength = 30000;
}

ForcedInformMessageDialog::ForcedInformMessageDialog(const wchar_t *messageText,
                                                     Pane *parentPane,
                                                     Layer *layer)
    : DialogPane(L"", kForcedInformDialogConfigId, 1),
      m_bAccepted(true)
{
    if (g_useEpfAssets == 1) {
        AddControl(new EPFImageControlPane(MakeRect(0, 0, 318, 456),
                                           0,
                                           L"DLGSTAFF.EPF",
                                           L"DLGSTAFF.PAL"));

        TextEditControlPane *messagePane =
            new TextEditControlPane(MakeRect(25, 56, 300, 391), L"");
        AddControl(messagePane);
        messagePane->SetMaxLines(kForcedInformMaxLines);
        messagePane->SetMaxLength(kForcedInformMaxLength);
        messagePane->SetEditActiveState(false, false);
        TextEditPane *editor = messagePane->GetTextEditPane();
        editor->SetText(messageText, static_cast<short>(std::wcslen(messageText)), NULL, 0);
        editor->SetSelectionRange(0, 0);
        messagePane->SetControlVisible(false);

        AddControl(new ImageButtonControlPane(MakeRect(86, 419, 149, 443),
                                              kForcedInformAcceptButtonImage));
        AddControl(new ImageButtonControlPane(MakeRect(163, 419, 226, 443),
                                              kForcedInformDeclineButtonImage));

        SetBackgroundResource(L"DLGSTAFF.EPF", NULL);
        SetMode(1);
        const int left = (g_screenWidth - 318) / 2;
        const int top = (g_screenHeight - 456) / 2;
        RectBounds dialogBounds = MakeRect(left, top, left + 318, top + 456);
        OnCreate(&dialogBounds, 0, parentPane, layer);
        OnShow(NULL, parentPane);
        SetHoverControl(kForcedInformHoverControl);
        SetFocusedControl(kForcedInformFocusedControl);
        SetPendingControl(kForcedInformPendingControl);
        SlideOpenVertical();
    } else {
        AddControl(new EPFImageControlPane(MakeRect(0, 0, 267, 367),
                                           0,
                                           L"DLGSTAFF.EPD",
                                           L"NP"));

        TextEditControlPane *messagePane =
            new TextEditControlPane(MakeRect(39, 70, 230, 306), L"");
        AddControl(messagePane);
        messagePane->SetMaxLines(kForcedInformMaxLines);
        messagePane->SetMaxLength(kForcedInformMaxLength);
        messagePane->SetEditActiveState(false, false);
        TextEditPane *editor = messagePane->GetTextEditPane();
        editor->SetText(messageText, static_cast<short>(std::wcslen(messageText)), NULL, 0);
        editor->SetSelectionRange(0, 0);
        messagePane->SetControlVisible(false);

        SetBackgroundResource(L"DLGSTAFF.EPD", NULL);
        SetMode(1);
        RectBounds dialogBounds = MakeRect(363, 100, 630, 467);
        OnCreate(&dialogBounds, 0, parentPane, layer);
        OnShow(NULL, parentPane);
        SlideOpenVertical();
    }

    if (g_pScreenDimmer != NULL) {
        g_pScreenDimmer->SetDimmed(true);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R3 preserves the duplicated branch-local text configuration seen in the binary and avoids inventing a separate helper with no body/xref evidence. Direct Singleton construction supplies publication.

### R4 - UID00048Z ordinary destructor

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ForcedInformMessageDialog::~ForcedInformMessageDialog()
{
    if (g_useEpfAssets == 1 &&
        m_bAccepted &&
        g_pMainMenuPane != NULL) {
        EnsureLoginDialogPane();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R5 - UID000490 OnControlCommand

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ForcedInformMessageDialog::OnControlCommand(int controlIndex, int notifyCode)
{
    (void)notifyCode;

    if (controlIndex == 2) {
        m_bAccepted = true;
        SlideCloseVertical();
        CloseDialog();
        return;
    }

    if (controlIndex == 3) {
        m_bAccepted = false;
        SlideCloseVertical();
        CloseDialog();
        g_pApplication->RequestExit();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R6 - UID000491 HandleKeyOrTextEvent

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ForcedInformMessageDialog::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (event->m_type == kEventKeyDown) {
        if (key == 'A' || key == 'a') {
            m_bAccepted = true;
            SlideCloseVertical();
            CloseDialog();
        } else if (key == 'D' || key == 'd') {
            m_bAccepted = false;
            SlideCloseVertical();
            CloseDialog();
            g_pApplication->RequestExit();
        }
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R6 deliberately translates before testing `m_type`, matching machine order and current Event source conventions.

### R7 - UID0001J7 split index - blank

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R8 - UID0001J8 EH clear helper - blank

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R9 - UID0001J9 adjustor thunks - blank

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R10 - UID0001JA scalar deleting wrapper - blank

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R11 - UID0003DK RTTI/vtable data - blank

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R7-R11 remain blank because exact source-bearing declarations/bodies regenerate the split aggregate's semantic code, Singleton EH cleanup, adjustors, deleting wrapper, RTTI, COLs, and vtables.

## Final Recommendation

- C01-C20 and R0-R11 are implemented exactly; all twelve destination formals match this report byte-for-byte.
- All exact ranges, padding, `Nested` values, six refs, hashes, resources, layout, negative constructor-route evidence, compiler exclusions, main-menu/login relationships, and historical corrections are preserved.
- Both validator-aware UID-preserving renames and their current ordinary-link updates are complete.
- Verify-only support was reread and left unchanged because no direct contradiction was found.
- No future research item remains inside this assignment. Exact original private/helper spellings are documented confidence caps only.

## Recommended Target Doc Changes

- Path: `by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md`.
- Implemented `92/94`, `CANONICAL_OWNER:0000QY`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, blank R0, `Nested:0`.
- Current documentation contains exact PE zero-fill proof, current bytes, complete six-ref inventory, physical/semantic one-definition split, direct Singleton source cause, exact neighbors/no padding, source type/linkage/name, negative searches, and score rationale.
- `0xffffffff` remains only as an explicitly superseded historical observation.

## Recommended Support Doc Changes

- `by-global/g_pForcedInformMessageDialog.md` UID0000QY: `92/94`, owner/emitter UID0000JJ, true, position `0`, exact R1, sole-definition/extern/order evidence, zero initializer, six refs, and physical UID0001PW non-emission.
- `by-class/ForcedInformMessageDialog.md` UID00005E: `93/94`, owner/emitter UID0000JJ, true, position `10`, exact R2; direct DialogPane plus Singleton inheritance; eight-base RTTI; exact layout table; corrected method declarations; class closes before extern and `[[CHILDREN]]`.
- Exact class layout to document:

| Offset | Size | Source entity | Evidence/disposition |
| --- | ---: | --- | --- |
| `0x000-0x26b` | `0x26c` | `DialogPane` direct base | inherited primary/EventHandler/TimerHandler facets |
| `0x26c` | EBO | `Singleton<ForcedInformMessageDialog>` direct base | RTTI PMD `(0x26c,-1,0)`; no data member |
| `0x26c` | 1 | `bool m_bAccepted` | EBO overlap; constructor/accept/decline/destructor uses |
| `0x26d-0x26f` | 3 | natural tail alignment | no explicit padding member |
| total | `0x270` | complete object | constructor/scalar allocation/layout evidence |

- `by-file/ForcedInformMessageDialog.md` UID0000JJ: `92/93`, preserve `NexusTK/login/`; exact source/global/class/method order, corrected child links/names, Singleton implicit lifecycle, resource ownership, compiler exclusions, generated contract, and consumer/support separation.
- `by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md` UID0001J7: `92/94`, retain false/NONE/blank emitters/position/R7 and `Nested:4`; correct source/compiler inventory, method names/signatures, padding, hashes, six refs, liveness negatives, and source route.
- UID00048Y constructor: `92/94`, owner UID00005E/emitter UID0000JJ/true/blank position/`Nested:0`; exact R3 is installed, explicit global write, C++11 `constexpr`, phantom helper, raw offset/decompiler/compiler details are removed, and all exact resource/control/geometry/order/fallback evidence is retained.
- UID00048Z destructor: `92/94`, owner/emitter/true/blank position/`Nested:0`; exact R4 is installed, explicit global clear is removed, and reverse Singleton/base lowering, ordinary/scalar parity, exact guard, and helper call are documented.
- UID000490: validator-preserving rename completed at `by-memory/0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand.md`; `92/94`, same owner/emitter/true/blank position/`Nested:0`; exact R5 and two-argument/unused-notify/vtable proof are current.
- UID000491: validator-preserving rename completed at `by-memory/0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent.md`; `92/94`, same owner/emitter/true/blank position/`Nested:0`; exact R6 and Event/EventMan/vtable/order/always-true proof are current.
- UID0001J8: `90/94`, false/NONE/blank emitter/position/R8, `Nested:0`; exact 0xb EH Singleton cleanup and no ordinary source proof.
- UID0001J9: `90/94`, false/NONE/blank emitter/position/R9, `Nested:0`; exact two thunk bounds/adjustments/jump/vtable-only proof.
- UID0001JA: `92/94`, false/NONE/blank emitter/position/R10, `Nested:0`; complete scalar-wrapper decomposition and ordinary destructor source ownership.
- UID0003DK: `92/94`, `CANONICAL_OWNER:00005E`, false, blank emitter/position/R11, `Nested:-4`; exact range/hash/three COL-table pairs/RTTI/bases/slots/stores/thunks/successor and no-raw-array proof.
- Verify-only unchanged: UID00019J main-menu cleanup `88/91`, UID00019L EnsureLoginDialogPane `88/90`, UID0003GQ resource literals `87/92`, UID0001PV/UID00029W neighbors, DialogPane, Event, EventMan, Singleton, TextEdit controls, ScreenDimmer, Application, and generated source.

## Score And Metadata Recommendation

| UID | Historical pre-callback tuple | Implemented exact tuple | Rationale/cap |
| --- | --- | --- | --- |
| 0001PW | `86/90`, owner/emitter0000QY, true, blank pos/formal, N0 | `92/94`, owner0000QY, false, blank emitter/pos/R0, N0 | storage/initializer/one-definition fully closed |
| 0000QY | `87/90`, owner/emitter0000JJ, true, blank pos/formal | `92/94`, same owner/emitter, true, pos0, R1 | sole source definition closed |
| 00005E | `89/89`, owner/emitter0000JJ, true, blank pos, incomplete formal | `93/94`, same route, true, pos10, R2 | direct bases/layout/methods complete |
| 0000JJ | `88/88` | `92/93`, same `NexusTK/login/` route | complete source/compiler inventory; filename inference caps 93 |
| 0001J7 | `90/92`, false/NONE, blank, N4 | `92/94`, same tuple/R7 | exact split and source closure complete |
| 00048Y | `89/91` | `92/94`, same owner/emitter/true/blank pos/N0, R3 | authored/compiler split and C++03 complete |
| 00048Z | `89/91` | `92/94`, same owner/emitter/true/blank pos/N0, R4 | direct-base clear correction complete |
| 000490 | `90/92` old path | `92/94`, same route, renamed path, R5 | exact inherited signature/name |
| 000491 | `89/91` old path | `92/94`, same route, renamed path, R6 | exact Event contract/name |
| 0001J8 | `86/90` false/NONE | `90/94`, same tuple/R8 | exact compiler EH proof |
| 0001J9 | `86/90` false/NONE | `90/94`, same tuple/R9 | exact thunk proof |
| 0001JA | `88/91` false/NONE | `92/94`, same tuple/R10 | complete scalar decomposition |
| 0003DK | `87/93`, owner/emitter00005E, true, N-4 | `92/94`, owner00005E, false, blank emitter/pos/R11, N-4 | compiler RTTI/vtable closure |

Score-improvement attempt removed every named blocker: PE mapping resolved initializer; reference scans closed lifecycle count; RTTI/ABI closed Singleton and class layout; current interfaces closed callback names/types; current EventMan support closed translator; decompilation closed source/compiler decomposition; current generated/manual roots closed routing and handoff. Scores remain below 95 only because original source symbols, exact header/file spelling, and some private helper names are not recoverable from the stripped binary.

## Open Questions With Attempted Resolution

- Initializer? Resolved to loader zero/`NULL`; `0xffffffff` rejected.
- Source definition route? Resolved to UID0000QY sole emitter at position 0; UID0001PW false.
- Direct base? Resolved to `Singleton<ForcedInformMessageDialog>` at `+0x26c` plus DialogPane.
- Explicit lifecycle writes? Resolved as compiler/template lowering; remove from authored bodies.
- Button/key names and signatures? Resolved to current DialogPane/EventHandler contracts with ABI/vtable proof.
- Key helper? Resolved to `g_pEventMan->TranslateEventKey(key, modifiers)` before type check.
- Object layout? Resolved exactly to 0x270 with EBO overlap and natural tail padding.
- Constructor reachability? Direct route remains absent after exhaustive search, but complete class/source retention is positively established; confidence cap only.
- Original private/helper/file spellings? Not directly recoverable. The selected names are current project-consistent, behavior-preserving, and source-ready; this does not justify blank C++ or delayed work.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current manual roots were reread read-only after callback completion. The following exact actions remain a supervisor-owned, unapplied handoff; B003 did not edit coverage. For every existing row, the replacement description starts with all valid current facts and then appends the accepted UID0001PW additions. The only current clauses not retained as current truth are explicitly labeled superseded. UID00048Y, UID000490, UID000491, and UID0003DK remain absent and are additions rather than replacements. Unrelated external coverage drift changed root hashes/one address-order anchor after Gate 1 without altering any ForcedInform row or the exact replacement text.

### by-memory/-coverage-report.md

Current read-only snapshot: SHA256 `316B019A623ED9D9698B7F52BF8755BC8084AD7797090788635FF47FE42297DC`, 1,927,924 bytes / 4,489 lines. Current anchors are UID0001J7 line 3343, UID00048Z line 3344, UID0001J8 line 3345, UID0001J9 line 3346, UID0001JA line 3347, UID0003GF line 4131, UID00026N line 4132, UID0001PV line 4402, UID0001PW line 4403, and UID00029W line 4404. The one-line shift after the family block is unrelated external content; all nine existing ForcedInform rows remain byte-for-byte the pre-handoff rows.

No-loss comparison against current rows:

- UID0001J7 retains the current forced login/main-menu core, constructor/destructor/button/key, EPF/EPD, singleton/teardown, vtable/read-only-data, and explicit parent-attachment facts; the split-index/source-quality facts are additions.
- UID00048Z retains the exact EPF/accepted/`g_pMainMenuPane` guard, `EnsureLoginDialogPane` restoration, singleton clear, compiler teardown exclusion, and source-ready formal fact; direct Singleton-base lowering is an addition.
- UID0001J8 retains strong confidence for exact function boundary and effect; EH/funclet/direct-Singleton no-code detail is an addition.
- UID0001J9 retains strong confidence for boundaries and owner; exact two-thunk adjustments/vtable routes are additions.
- UID0001JA retains the class-file attachment, three vtable reinstalls, accepted-EPF login restoration, explicit compiled `g_pForcedInformMessageDialog` clear, destructor-thunk links, and blank C++ disposition. Only the old statement that blank C++ was pending unresolved cleanup/delete helper names is superseded; the replacement adds the now-proven compiler-wrapper reason.
- UID0001PW retains the exact four-byte singleton role, six xrefs, constructor publish/fallback clear, non-deleting/helper/scalar clears, main-menu cleanup read, cleanup-helper callers, login-dialog restoration calls, and semantic parent UID0000QY. Only the `0xffffffff` initializer is superseded by loader-zero proof.
- UID00048Y, UID000490, UID000491, and UID0003DK are absent at these exact child positions and therefore are additions.

Replace the current UID0001J7/UID00048Z/UID0001J8/UID0001J9/UID0001JA block at current lines 3343-3347, preserving address order and every unrelated row, with:

```text
    - [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md) 0x00587bb0-0x005881ed | non-emitting split index | ForcedInformMessageDialogCore : not_reconstructable : 92% : very-strong : Retained current facts: forced login/main-menu information dialog core with constructor/destructor/button/key handlers, EPF/EPD behavior, singleton and teardown evidence, vtable/read-only-data links, and parent attachment documented. Additions: exact non-emitting four-method split with constructor, ordinary destructor, OnControlCommand, and HandleKeyOrTextEvent source children; complete padding, six singleton refs, direct Singleton<ForcedInformMessageDialog> lowering, resources, vtable/RTTI, liveness negatives, compiler-support exclusions, and blank aggregate C++.
        - [UID:00048Y][0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor](by-memory/0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor.md) 0x00587bb0-0x00588073 | constructor | ForcedInformMessageDialog::ForcedInformMessageDialog : reconstructable : 92% : very-strong : Addition, no current child row: exact C++03 constructor body for EPF/EPD DLGSTAFF layouts, supplied UTF-16 text, controls, geometry, focus/pending/hover state, slide-open, screen dimming, direct Singleton-base publication lowering, and no explicit global/vptr/EH source artifacts.
        - [UID:00048Z][0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor](by-memory/0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor.md) 0x00588080-0x00588101 | destructor | ForcedInformMessageDialog::~ForcedInformMessageDialog : reconstructable : 92% : very-strong : Retained current facts: exact ordinary destructor body with EPF/accepted/g_pMainMenuPane guard, EnsureLoginDialogPane restoration, singleton clear, compiler teardown exclusion, and source-ready formal body. Additions: direct Singleton/base destruction explains the compiled g_pForcedInformMessageDialog clear and inherited cleanup without handwritten lowering.
        - [UID:000490][0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand](by-memory/0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand.md) 0x00588110-0x0058815d | virtual method | ForcedInformMessageDialog::OnControlCommand : reconstructable : 92% : very-strong : Addition, no current child row: exact DialogPane primary-slot +0x48 two-argument control-command override; control 2 accepts/closes, control 3 declines/closes/requests exit, notify code is unused, and stale one-argument OnButtonResponse wording is superseded.
        - [UID:000491][0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent](by-memory/0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent.md) 0x00588160-0x005881ed | virtual method | ForcedInformMessageDialog::HandleKeyOrTextEvent : reconstructable : 92% : very-strong : Addition, no current child row: exact EventHandler secondary-slot +0x08 Event callback; EventMan key translation occurs before key-down gating, A/a accepts, D/d declines and requests exit, return is always true, and stale OnKeyInput/InputEvent/CRT labels are superseded.
    - [UID:0001J8][0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear](by-memory/0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear.md) 0x0058aa90-0x0058aa9b | compiler EH cleanup | ForcedInformMessageDialogSingletonClear : not_reconstructable : 90% : very-strong : Retained current fact: confidence is strong for function boundary and effect. Additions: exact 11-byte Singleton-base constructor-unwind clear with one EH metadata/funclet reference, no ordinary caller, and blank formal because direct Singleton inheritance regenerates it.
    - [UID:0001J9][0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks](by-memory/0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks.md) 0x0058aadb-0x0058aaf1 | compiler adjustor thunks | ForcedInformMessageDialogDestructorThunks : not_reconstructable : 90% : very-strong : Retained current facts: confidence is strong for boundaries and owner. Additions: exact two 11-byte secondary/tertiary this-adjustor thunks subtracting 0xa0/0xa4 and jumping to the scalar deleting wrapper; vtable-only routes, blank formal, and no handwritten source.
    - [UID:0001JA][0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor](by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md) 0x0058abf0-0x0058acb2 | compiler scalar deleting destructor | ForcedInformMessageDialogDestructor : not_reconstructable : 92% : very-strong : Retained current facts: scalar deleting destructor attached to ForcedInformMessageDialog.cpp; reinstalls three vtables, handles accepted-EPF login restoration through EnsureLoginDialogPane, explicitly clears g_pForcedInformMessageDialog in compiled output, and links to destructor adjustor thunks. Superseded current assumption: blank C++ was pending source-quality inherited cleanup/delete helper names. Additions: exact compiler wrapper decomposition covers ordinary destructor behavior, direct Singleton/base cleanup, scalar flags, and optional storage delete; source body lives solely on UID00048Z and this page remains blank/non-emitting by proof rather than by an open blocker.
```

Insert after current UID0003GF line 4131, under UID00026M and before UID00026N line 4132:

```text
        - [UID:0003DK][0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData](by-memory/0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData.md) 0x0062d714-0x0062d7b0 | compiler RTTI/vtable data | ForcedInformMessageDialogVtableData : not_reconstructable : 92% : very-strong : Addition, no current child row: exact locator-inclusive three-view ForcedInformMessageDialog RTTI/vtable island with primary/EventHandler/TimerHandler tables, direct DialogPane plus Singleton PMD +0x26c hierarchy, constructor/destructor stores, OnControlCommand/HandleKeyOrTextEvent/deleting-thunk slots, exact successor boundary, semantic class owner UID00005E, and blank no-raw-array formal.
```

Replace UID0001PW at current line 4403, between unchanged UID0001PV line 4402 and UID00029W line 4404, with:

```text
    - [UID:0001PW][0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog](by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md) 0x0069b4a0-0x0069b4a4 | physical global-pointer storage | g_pForcedInformMessageDialog : not_reconstructable : 92% : very-strong : Retained current facts: exact four-byte ForcedInformMessageDialog singleton slot with six live IDA xrefs, constructor publish/fallback clear, non-deleting/helper/scalar destructor clears, main-menu cleanup read, cleanup-helper callers, login-dialog restoration calls, and semantic parent [UID:0000QY][g_pForcedInformMessageDialog](by-global/g_pForcedInformMessageDialog.md). Superseded current assumption: the slot was initialized to 0xffffffff. Additions: exact PE arithmetic proves loader-zeroed virtual-.data backing for the sole semantic UID0000QY source definition; direct Singleton<ForcedInformMessageDialog> PMD +0x26c explains lifetime writes; exact neighbors/no padding and blank physical formal preserve one-definition policy.
```

### by-global/-coverage-report.md

Current read-only snapshot: SHA256 `DAD2BCB4C1E0B0872D32A4A4B821D5F4589148E5BF55C018A5A247F98729666C`, 96,267 bytes / 214 lines. UID0000QY remains the sole current row at line 87, between UID0000QX and UID0000QZ, with its exact pre-handoff text unchanged. Replace it with:

```text
- [UID:0000QY][g_pForcedInformMessageDialog](by-global/g_pForcedInformMessageDialog.md) : reconstructable : 92% : very-strong : Retained current facts: Forced-inform dialog singleton with 2026-06-14 IDA-confirmed six-ref map, constructor publish/fallback clear, non-deleting and scalar destructor clears, EH clear helper, main-menu cleanup read, return-to-login behavior, and non-dead-ended ForcedInform route documented. Additions: sole externally linked zero-initialized ForcedInformMessageDialog pointer definition at source position 0 in NexusTK/login/ForcedInformMessageDialog.cpp, matched by one class-header extern after the complete direct DialogPane plus Singleton<ForcedInformMessageDialog> declaration; physical UID0001PW is loader-zero backing with exactly six lifecycle refs and no duplicate emission, while implicit Singleton publication/clear replaces explicit constructor/destructor assignments.
```

### by-class/-coverage-report.md

Current read-only snapshot: SHA256 `6753174CAF0231C2687960A50E423B36F734D7FAA31128B66C38F2A6BDA1B9A1`, 250,232 bytes / 623 lines. UID00005E remains the sole current row at line 219, between UID00005D and UID00005F, with its exact pre-handoff text unchanged. Replace it with:

```text
- [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md) : reconstructable : 93% : very-strong : Retained current caveat: confidence is strong for class behavior and boundaries and medium for the exact original filename. Additions: complete ForcedInformMessageDialog declaration at position 10 with direct DialogPane and empty Singleton<ForcedInformMessageDialog> bases, exact 0x270 layout and +0x26c EBO/m_bAccepted overlap, natural tail alignment, constructor/virtual destructor/OnControlCommand/HandleKeyOrTextEvent declarations, sole-global extern, class closure before CHILDREN, exact three-view RTTI/vtable evidence, and compiler EH/thunk/scalar/vtable exclusions.
```

### by-file/-coverage-report.md

Current read-only snapshot: SHA256 `FD97F683E662F9EC15A35DD6903F78BB4DD93A3A74E359DB793A54D3130E83CF`, 147,196 bytes / 316 lines. UID0000JJ remains the sole current row at line 100, between UID0000JI and UID0000JK, with its exact pre-handoff text unchanged. Replace it with:

```text
- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) : reconstructable : 92% : very-strong : Retained current facts: Forced login/main-menu information dialog with singleton ownership, resource family, generated split table, IDA evidence, teardown/login relationship, compiler-helper exclusions, and migration notes documented. Additions: NexusTK/login/ForcedInformMessageDialog.cpp source root with one position-0 g_pForcedInformMessageDialog definition, one complete position-10 class/extern declaration, exact constructor/destructor/OnControlCommand/HandleKeyOrTextEvent bodies, DLGSTAFF EPF/EPD/PAL resources, main-menu cleanup and accepted login restoration, direct Singleton implicit lifecycle, exact split/padding/liveness evidence, and non-emitting physical storage/EH/thunk/scalar/vtable exclusions with no explicit global assignment or raw RTTI arrays.
```

Reason B003 did not apply these rows: all `-coverage-report.md` files are manual supervisor-owned state. Ordinary implementation and validators are complete; exact coverage application/validation and later lifecycle state remain external supervisor/validator-owned.

## Follow-Up Actions

- B003 implementation work is complete; no ordinary, validator, generated-readback, report-reconciliation, or lease item remains.
- The exact thirteen-action manual coverage handoff remains supervisor-owned and unapplied at this readback. B003 neither applies nor directs later coverage/lifecycle operations.
- Report validation, execution, count, current path, move, archive, and later manual/generated epochs are external supervisor/validator-owned state and are neither asserted nor directed by this artifact.

## Confidence

- Recommendation confidence: `94/100`.
- Score confidence: `94/100`.
- Remaining uncertainty: original private/helper/file spellings and hidden constructor invocation mechanism are not symbol-proven. All reasonable current routes were exhausted; these caps do not affect behavior, ownership, emitted C++03 completeness, or metadata disposition.

## Validator Results

- All listed commands ran from canonical `source-3/project-documentation`, exited `0`, and reported `ok:1`. Generated/tracker/registry/stat changes below are validator-owned side effects; B003 did not edit those files manually.

| Command | Timestamp | Scoped ordinary destination | Result / relevant side effects |
| --- | --- | --- | --- |
| `000000016112` | `2026-07-21T17:33:07-04:00` | renamed UID000490 `...OnControlCommand.md` | path/completion/confidence/formal registry update; six reverse-source paths and eleven UID links updated; generated deferred |
| `000000016113` | `2026-07-21T17:34:22-04:00` | renamed UID000491 `...HandleKeyOrTextEvent.md` | path/completion/confidence/formal registry update; six reverse-source paths and thirteen UID links updated; generated deferred |
| `000000016114` | `2026-07-21T17:36:30-04:00` | UID0001PW physical slot | `92/94`, reconstructable true->false, emitter UID0000QY->blank; generated deferred |
| `000000016115` | `2026-07-21T17:37:23-04:00` | UID0000QY semantic global | `92/94`, position 0, blank->block formal registry update; generated deferred |
| `000000016116` | `2026-07-21T17:38:41-04:00` | UID00005E class | `93/94`, position 10 and class-formal registry update; generated deferred |
| `000000016122` | `2026-07-21T17:39:58-04:00` | UID0001J7 split index | `92/94`; blank/non-emitting route unchanged; generated deferred |
| `000000016124` | `2026-07-21T17:41:22-04:00` | UID00048Y constructor | `92/94` and initial R3 registry update; generated deferred |
| `000000016125` | `2026-07-21T17:42:39-04:00` | UID00048Z destructor | `92/94` and R4 registry update; generated deferred |
| `000000016126` | `2026-07-21T17:43:11-04:00` | UID000491 bounded hash correction | warning-free `ok:1`; metadata unchanged; generated deferred |
| `000000016127` | `2026-07-21T17:43:48-04:00` | UID0001J8 EH clear | `90/94`; blank false/NONE route unchanged; generated deferred |
| `000000016128` | `2026-07-21T17:44:31-04:00` | UID0001J9 thunks | `90/94`; blank false/NONE route unchanged; generated deferred |
| `000000016129` | `2026-07-21T17:45:24-04:00` | UID0001JA scalar wrapper | `92/94`; blank false/NONE route unchanged; generated deferred |
| `000000016130` | `2026-07-21T17:46:14-04:00` | UID0003DK vtable/RTTI | `92/94`, reconstructable true->false, emitter UID00005E->blank; generated deferred |
| `000000016131` | `2026-07-21T17:47:51-04:00` | UID00048Y exact R3 parity repair | formal registry hash update; generated deferred |
| `000000016132` | `2026-07-21T17:49:05-04:00` | UID0000JJ file with `--wait-generated` | `92/93`; full registry rebuild, generated metadata/tracker refresh; foreground generation completed at the same command/timestamp |

- Command `16132` generated readback: `auto-generated/NexusTK/login/ForcedInformMessageDialog.cpp`, SHA256 `535DDBEFC649E3A9457EB9A8EC35A8B13E667B11C82586CF2982B47991179A93`, 6,341 bytes / 165 lines, header command/timestamp exact.
- Semantic counts: sole global definition `1`; complete class `1`; constructor `1`; destructor `1`; `OnControlCommand` `1`; `HandleKeyOrTextEvent` `1`; old `OnButtonResponse`/`OnKeyInput` `0`; Empty Emitter Markers `0`; UID0001PW/UID0003DK generated entries `0`; raw vtable/RTTI/compiler-scalar/EH text `0`; body-level singleton assignments `0`. The class closing `};` occurs before the first qualified definition.
- Formal parity: R0-R11 are `12/12` byte-for-byte equal between this accepted report and current destinations; R0/R7-R11 bodies are exactly blank.
- Validator diagnostics were only project-wide informational fallback/missing-marker/no-code notices unrelated to the scoped family. No scoped warning/error or unresolved callback item remains.

## Changed Files

- Modified ordinary destinations after final validation/readback:

| Path | SHA256 | Bytes / lines |
| --- | --- | ---: |
| `by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md` | `D3AD17FED6843F6F5923F57E68AD6BF20408FD9F54172E6D9FF223C361B74965` | 10,835 / 92 |
| `by-global/g_pForcedInformMessageDialog.md` | `9D8174210C0C4BD066E1290B678A117230443A2397070D8AA05E294ADF6F40F6` | 8,397 / 71 |
| `by-class/ForcedInformMessageDialog.md` | `28928BF643C3F7AAA5949B5A09CEAAB9173EDF8A7A8D6648E0B8BEC89D37D5D4` | 15,146 / 145 |
| `by-file/ForcedInformMessageDialog.md` | `2A945F19186A1C2D11731D9F8685A720F4D8D8CB82986C64E2EDE8FBCC52E09B` | 19,527 / 150 |
| `by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md` | `2A6082047A50DC5E17D304B1DC19D61D70010F6BA2C4A935240041BB2AA7DC5E` | 22,320 / 218 |
| `by-memory/0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor.md` | `0689F18EC96EFC7A75C4C31C287FFE3ECAADA908585C290CEFB796A6618A4AE6` | 13,287 / 160 |
| `by-memory/0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor.md` | `3DADF666E6D0045CFB087E690048B2B2E00F6C2086E3DCA2F173045549C560AF` | 7,048 / 82 |
| `by-memory/0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand.md` | `E55FC6E4FE94F449B418A1810B7D4026E5FF9343631D1CD9C2FA336174BABD97` | 7,002 / 88 |
| `by-memory/0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent.md` | `9C5148B9D5C1E0F12236B3DF343A90D0F41CEEDCBED71F9AD8FA9C80503F0DDD` | 7,722 / 92 |
| `by-memory/0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear.md` | `C46A94E5DCD5E94E43261093030B6548CD313B1AF2CABD540362066246690B2C` | 5,429 / 59 |
| `by-memory/0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks.md` | `CEC06D7B5EB4C7CB1624F8394BD72FDBADB1E96040964C52744FBF27658D8E51` | 5,251 / 58 |
| `by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md` | `922310C1F821EA21079AD6B83D190507B290C4CF2BFED9738DB12C97F2C63C88` | 11,911 / 100 |
| `by-memory/0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData.md` | `7CA4AD1227752ACFE53AB281719C92EC8A71852642DA6AFB5768AAA4349B0167` | 8,582 / 76 |

- Validator-aware renames removed old paths `...ForcedInformMessageDialogOnButtonResponse.md` and `...ForcedInformMessageDialogOnKeyInput.md`; current UID000490/UID000491 paths are the two rows above. Validator-owned dependent-link updates were subsequently reread/rebased in all planned shared destinations.
- Modified report: this canonical artifact only. Generated C++/coverage/tracker/registry/stat changes were validator-owned side effects and were inspected read-only; manual coverage remained untouched by B003.
- Verify-only dependencies remained unchanged. UID0001PV advanced externally to SHA256 `40304F9A9611D705CD950CE3629CC4B443F4CC73438CBF7E853739A67921EE9B`; the change is unrelated and does not contradict this scope.
- B003 did not run or probe `execute_report`, move/archive this report, or perform any report lifecycle command. Exact current report lifecycle/path state is external supervisor/validator-owned.
- Final lease ledger contains no B003 entry; the unrelated B005 report lease does not overlap this work.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 validation preceded implementation.
- [x] C01-C20 were applied only after exact-artifact Gate 1 acceptance.
- [x] All intended destinations and current leases were reread immediately before callback edits.
- [x] UID0001PW is `92/94`, false/non-emitting, owner UID0000QY, blank R0, `Nested:0`.
- [x] UID0000QY is `92/94`, position 0, with exact R1 sole definition.
- [x] UID00005E is `93/94`, position 10, exact R2, complete bases/layout, and class closure before `[[CHILDREN]]`.
- [x] UID0000JJ is `92/93` with complete source/compiler inventory and preserved login route.
- [x] UID0001J7 is `92/94` with blank split-index R7 and exact ranges/padding/children/liveness.
- [x] UID00048Y is `92/94` with exact C++03 R3 and no explicit singleton/compiler/C++11 residue.
- [x] UID00048Z is `92/94` with exact R4 and direct-base clear explanation.
- [x] UID000490 was validator-preserving renamed to `ForcedInformMessageDialogOnControlCommand` before dependent validation.
- [x] UID000490 is `92/94` with exact R5 and complete two-argument vtable/ABI evidence.
- [x] UID000491 was validator-preserving renamed to `ForcedInformMessageDialogHandleKeyOrTextEvent` before dependent validation.
- [x] UID000491 is `92/94` with exact R6 and complete Event/EventMan/order evidence.
- [x] UID0001J8 is `90/94`, false/non-emitting, blank R8, with exact EH cleanup proof.
- [x] UID0001J9 is `90/94`, false/non-emitting, blank R9, with exact thunk proof.
- [x] UID0001JA is `92/94`, false/non-emitting, blank R10, with exact scalar-wrapper proof.
- [x] UID0003DK is `92/94`, semantic owner UID00005E, false/non-emitting, blank R11, `Nested:-4`.
- [x] UID00019J, UID00019L, UID0003GQ, neighbors, DialogPane, Event/EventMan, Singleton, controls, ScreenDimmer, and Application were reread and preserved verify-only; no contradiction appeared.
- [x] Exact PE hash/mapping, all function hashes, six refs, RTTI/layout, resources, negative routes, rejected alternatives, and historical corrections are preserved.
- [x] Target/parent/vtable ranges and all padding/nesting dispositions are preserved.
- [x] All C++ is confined to exact managed destinations; R0/R7-R11 are fully blank.
- [x] Third-party import directive is not applicable.
- [x] One short ordinary lease/edit/scoped-validate/release cycle was used per changed page, with two bounded correction cycles where parity/hash required it.
- [x] Renamed links were updated without loss through validator-aware workflow; validator state was not hand-edited.
- [x] Final waited `by-file/ForcedInformMessageDialog.md` refresh completed after scoped validators.
- [x] Generated definition/name/order/marker/compiler-exclusion assertions are exact.
- [x] All four manual roots were reread and unrelated concurrent content was preserved in the exact handoff.
- [x] All nine replacement rows preserve every valid current fact/UID link or explicitly supersede only disproved clauses; UID00048Y/UID000490/UID000491/UID0003DK remain explicit additions.
- [x] Manual coverage application is correctly excluded from B003 scope and remains supervisor-owned; the exact thirteen-action handoff is preserved.
- [x] C01-C20 have legal claim-specific terminal states with destination/validator/generated proof.
- [x] Current Target State, Validator Results, Changed Files, hashes, and lifecycle wording reflect callback truth.
- [x] Every implementation item was independently read back before checking it.
- [x] Zero provisional tokens, zero current stale old paths/names, and zero B003 leases are confirmed.

Implementation callback pass:

- [x] Report was accepted by supervisor for implementation at exact SHA `E56E6FDFDB37757CD23CF43E4425D7C69698FCF29271A4057485A69D62967164`.
- [x] All accepted target/support details are incorporated at report-level depth without compression.
- [x] Physical/semantic one-definition state was independently read back.
- [x] Complete class layout/inheritance and method declarations were independently read back.
- [x] Exact R0-R11 destination parity is `12/12`.
- [x] Historical initializer/source-shape assumptions remain only as explicitly superseded history.
- [x] All scoped validators are recorded with command IDs, timestamps, exits, ok counts, warnings, and side effects.
- [x] Final generated header/hash/bytes/lines and semantic counts are recorded.
- [x] Current destination hashes and verify-only hashes are recorded after concurrent rebasing.
- [x] Manual coverage handoff was reread and current no-loss delta recorded without B003 editing coverage.
- [x] No B003 implementation item remains; only the explicitly excluded supervisor-owned manual handoff is unapplied.
- [x] Exactly one terminal callback readiness marker is present after all work completed.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000016143","destination_path":"executed-b-agent-research/B003/0001PW-g_pForcedInformMessageDialog-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0001PW-g_pForcedInformMessageDialog-source-quality.md","timestamp":"2026-07-21T18:12:07-04:00","uid":"0001PW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
