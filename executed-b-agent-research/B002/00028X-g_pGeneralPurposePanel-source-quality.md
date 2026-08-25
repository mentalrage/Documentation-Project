** TARGET-REPORT-UID:00028X **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00028X g_pGeneralPurposePanel Ownership / Split Research


## Finalized Report / Current Recommendation

- Current recommendation: applied. Physical storage [UID:00028X] is a semantic-owned, false/non-emitting backing page at `92/94`; semantic [UID:0000R0] is the sole typed, externally linked definition in [UID:0000JQ] `NexusTK/ui/panels/GeneralPurposePanel.cpp`; and [UID:00005Q] now uses the RTTI-proven direct `LObject` plus `Singleton<GeneralPurposePanel>` declaration instead of the historical `PanelPane` shape.
- Final disposition: applied. The executable slot is loader-zeroed static storage, not an explicitly initialized `0xffffffff` object. Five of 87 refs are compiler/template lifetime writes and the other 82 are reads. The generated source has one zero-initialized pointer definition, one header declaration, one direct Singleton base, one source-authored constructor, one source-authored ordinary destructor, the accepted accessor/switch methods, and no handwritten EH/scalar/vtable storage.
- Callback status: Destinations 1-12 are applied, Destinations 13-15 are verified, and serial registration issued UID0004UL, UID0004UM, and UID0004UN. All eleven formal blocks are byte-equal to their destinations and no provisional UID remains.
- Confidence: very strong for storage, reference inventory, hierarchy, source/compiler split, fields, source placement, and one-definition policy; strong for inferred original spellings and scores.

## Supporting Research

- Historical report-only phase: the accepted pre-callback artifact performed no implementation, ordinary edit, manual coverage edit, validator, lease, IDA mutation, or report lifecycle command. The authorized callback subsequently changed only the twelve ordinary destinations listed below plus this report, using serial leases and scoped validators.
- Current workflow sources read: canonical `Agent-B002/goal.md`, project skill `ntk-b-agent-workflow`, `b-agent-research-and-implementation-workflow.md`, `score-blocker-audit-standard.md`, `b-agent-report-template.md`, and relevant `by-structure.md` ownership/emission/source-quality rules.
- Direct current documentation read: UID00028X physical storage, UID0000R0 semantic global, UID00005Q class, UID0000JQ file, UID00015V aggregate, UID00015W accessors, UID00015X switch, UID00015Z clear-helper pair, UID0003BC vtable data, UID00005R/UID0000R1/UID0002VS sibling family, current generated `GeneralPurposePanel.cpp`, tracker, manual coverage, consumers, goals, reports, and leases.
- Historical executed reports were used only as leads. B003 UID00015V correctly identified the split/index and virtual-tail concern but did not resolve direct Singleton inheritance or source children. B011 UID00015W and B005 UID00015X provide accepted exact accessor/switch bodies. B004 UID00015Y confirms the sibling switch. B003/B006/B007/B008 AboveFrame reports corroborate the `m_activeChildIndex` consumer without transferring ownership. B002 UID0001OT is a project precedent for physical/semantic singleton storage policy, not proof for this target.
- Final callback coordination read: B001 was implementing UID00028T, B003 was implementing UID0001P2, B004 was researching UID0001P5, and B005 was implementing UID00028R. Current leases were only unrelated B001/B003 paths; no other agent claimed UID00028X or a GeneralPurposePanel destination. Every B002 lease was released immediately after its scoped validator and the final B002 lease count is zero. Earlier report-only pool/lease observations remain evidence-time history.

## Target

- Target UID: `00028X`.
- Target path: `by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md`.
- Source queue/report row: historical report-only command `000000015486` recorded `86/90`, reconstructable true. Callback tracker command `000000015532`, timestamp `2026-07-20T18:09:25-04:00`, SHA256 `5238A19E7EF4B98474153EF83269F5CC6E3B3D06BF057B2D2D892C950E202271`, first recorded UID00028X at `92/94`, reconstructable false and the three real children. The final time-bounded reconciliation read observed the same applied metadata at tracker command `000000015549`, timestamp `2026-07-20T18:17:47-04:00`, SHA256 `F2E2FA14786D3987AD84CE3092977833D16218886F7474B21E0E8BDD7868935F`, `1,535,343` bytes, `6,218` lines.
- Current supervisor classification: exact four-byte singleton-pointer storage requiring source-quality and one-definition repair.
- Applied scores and parent state: target `92/94`, semantic UID0000R0 `92/94`, class UID00005Q `92/94`, file UID0000JQ `90/92`, aggregate UID00015V retained `89/93`.

## Current Target State

- Evidence-time/pre-callback target metadata was owner/emitter UID0000R0, reconstructable true, blank position/formal. Current UID00028X is `92/94`, owner UID0000R0, false, blank emitter/position/formal, `Nested:0`.
- Evidence-time/pre-callback semantic global was `88/86` with blank position/formal. Current UID0000R0 is `92/94`, owner/emitter UID0000JQ, position 0, with the sole typed zero definition.
- Evidence-time/pre-callback generated command `000000015481` contained UID0000R0/UID00028X Empty Emitter Markers and lacked the global/constructor/destructor. Callback waited command `000000015530`, timestamp `2026-07-20T18:08:56-04:00`, produced SHA256 `DD3C213827066731A23EA978BF2E730C6BF1CBEFA207AC47D2970A462A50C076`, `6,704` bytes, `226` lines, with the complete primary source route and no primary Empty Emitter Marker. A final time-bounded read at command `000000015548`, timestamp `2026-07-20T18:16:09-04:00`, observed SHA256 `63A01073CDDAD8473F2B59302B2723B8ACE860AF9ECFF5CC3406C29B37B543B6` with the same `6,704` bytes, `226` lines and exact semantic assertions; normalizing only its volatile command/timestamp header back to command 15530 reproduces SHA256 `DD3C2138...C076` exactly.
- Evidence-time/pre-callback class used `PanelPane`; current UID00005Q is `92/94`, position 10, direct `LObject` plus `Singleton<GeneralPurposePanel>`, exact 0x24 layout, one extern, and class closure before `[[CHILDREN]]`.
- Evidence-time/pre-callback target prose used `0xffffffff`; current target/global docs preserve that only as historical and prove `00 00 00 00` loader-zero bytes and source initializer zero.
- Evidence-time/pre-callback aggregate called primary constructor/destructor splits future work. Current UID00015V lists real UID0004UL, UID0004UM, and UID0004UN plus the complete source/compiler/padding/vtable union.
- Current ordinary hashes: UID00028X `35C7E2F5BAA19532668D94764325DDE77E9F4D6A62DD53490D291D4CEF75AC85`; UID0000R0 `405C7366668D5C0CA597F98AF4655BA7747A5BFA88BA7BFDB9884A508159D1FC`; UID00005Q `76772982D91F49C06EEC5F0FA01413ECB2F2809AC4E50281B94DD4C0C8F8F997`; UID0004UL `417450B0F19D708A3963051260F52E90CC78B4C7CA3809C5AC563A7615A8CD33`; UID0004UM `7C53540E825B1FBB2F36388D7BFD00872C446F98B928E41C63330FF55B411DB8`; UID00015W `81954C4ABA63F699BAF84E6D603B043AB3FCFF1D5EF5EBCBD65A7047AC048694`; UID00015X `6131E67580A03DAFC432593D316867EE632C80EC3008C04140AF0F62A7F0DB07`; UID00015Z `5369DA38BC4CF5F31FE0B96853483BD917C971694AE0B28DA97B1B85751C5693`; UID0004UN `187C6C2CB7E3A1CD9FF9F105CEECFFFF155EDE8CD75E472824A0ABCED683C92D`; UID0003BC `D16AC9DFC5295BE39F03BA93033E66D6946A6D434A5B35D1B6AE4AB458529A56`; UID00015V `4DF544B6B8FB0A4172E2E955E31DF00BB2F3D0E59A3FED38BE2CB1808ADF73C3`; UID0000JQ `D9852F32293343EC17B60A3F97EE637984D3A08B0CED6AB0A3C3E73F1550DE44`.
- Final sibling comparator snapshot: UID00005R `8FA99EC46A39F538D4EBBAD9B335DC0C21DA0A2133E68D0489F1128CD9CB49DB`; UID0000R1 `CEBEFFC6C47BBA8E080D6749161E3B743699F4695EEF4A5C819CB719674A2188`; UID0002VS `450A0D914DBC1ECE0491120B13A7853F1E9662BEB87713B3BDEC4DC03B54B6E7`.
- Current artifact/lifecycle wording is durable: B002's implementation, scoped validators, waited generated proof, report reconciliation, and lease release are complete. Current/future report path, Gate status, manual coverage application, execution, movement, archive, and later volatile generated/tracker epochs are external supervisor/validator-owned facts and are not asserted beyond the time-bounded evidence recorded here.

## Executive Recommendation

- UID00028X is physical backing storage. Retain semantic owner UID0000R0, set false/non-emitting, clear emitter/position, and keep the formal block blank.
- UID0000R0 is the source global. Emit the sole non-static zero-initialized definition at file position 0 and declare it externally after the complete class declaration.
- UID00005Q directly inherits `LObject` and `Singleton<GeneralPurposePanel>`. The Singleton base occupies PMD `+0x04` and is empty-base optimized over `m_childPanes[0]`; it is not `PanelPane`.
- UID0004UL is the exact source-authored constructor, UID0004UM the ordinary destructor, and UID0004UN the false/non-emitting scalar wrapper. UID00015W and UID00015X remain exact source children with byte-equal bodies.
- Keep UID00015Z as a mixed two-class compiler Singleton-base-destructor pair with owner NONE and no emitted C++. Convert UID0003BC to source-declared/generated-binary class-owned vtable data with no emitted C++.
- No assignment condition remains unresolved. Real child UIDs, destination validation, formal equality, waited generated output, sibling preservation, and zero leases are proven below.

## Supervisor Active Recheck

- The supervisor assigned UID00028X specifically because physical and semantic pages both route blank output and the old static-byte claim conflicts with runtime null semantics.
- Split repair is required before final source output because the aggregate spans two classes, authored methods, compiler helpers, scalar wrappers, vtable support, and padding.
- Every source-bearing GeneralPurposePanel item needed by this target has a destination-ready outcome: new constructor and destructor children, existing accessor/switch children, complete class declaration, sole global definition, and exact compiler-only no-code pages.
- GeneralPurposePanel2 was rechecked as a structural comparator. Its own 14-ref storage and unsplit lifecycle remain an independent sibling family and are not consumed by UID00028X source. The report does not import its stale `PanelPane` declaration into the accepted UID00028X source route.

## Inference Research Guidance Check

- `by-structure.md` requires the physical data page to describe storage without duplicating semantic source, `CANONICAL_OWNER` to identify the semantic global, `EMITTER_UIDS` to route only source-bearing declarations, and compiler-generated artifacts to stay false/non-emitting.
- IDA facts are kept separate from inference: bytes/xrefs/functions/RTTI/PMD are direct; the exact header name and source spelling are inferred; current documentation/generated output are evidence but not authority.
- Existing assumptions treated as uncertain and rechecked: `0xffffffff` initialization, `PanelPane` inheritance, manual publication/clear, `static` linkage, function-local Singleton storage, and handwritten cleanup/scalar/vtable code.
- Wave2/Wave3 material was not used as authority. Any stale generated `SpellOneArgInputPane` ownership or raw labels were rejected in favor of current MCP and accepted docs.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence | Resolution |
| --- | --- | --- |
| `0xffffffff` versus null storage | MCP returns four zero bytes; `.data` RVA/raw bounds put target 0x74 / 116 bytes beyond initialized raw data (Verified with `int_convert.py`) | Loader-zeroed static pointer; old ff claim historical/rejected. |
| Physical versus semantic source | one address, one semantic global, current double blank emitters | Physical UID00028X false/non-emitting; semantic UID0000R0 sole definition. |
| Linkage | 82 reads span many independent source modules | External module linkage; reject `static`, function-local, or consumer-owned definitions. |
| Initializer | no raw initialized bytes; all preconstruction semantics are zero | Use zero initializer; no sentinel `-1` initializer. |
| Base hierarchy | decorated RTTI includes LObject and direct Singleton only; Singleton PMD `+0x04`; ctor calls LObject constructor | Direct `LObject, Singleton<GeneralPurposePanel>`; reject `PanelPane`. |
| EBO/layout | allocation size `0x24`; Singleton PMD `+0x04`; fields at `+0x04..+0x20` | Empty Singleton overlaps first child pointer; exact class size 36 bytes. |
| Constructor writes | null-adjusted complete-object store occurs immediately after LObject construction and before derived vptr/member stores | Compiler-lowered direct Singleton base constructor; do not handwrite global assignment or fallback branch. |
| Ordinary clear | seven child calls, clear, LObject teardown | Handwritten destructor contains only seven `MarkForDeletion` calls; clear/base teardown are implicit. |
| `0x004b8a90` helper | 11-byte clear with one constructor EH-table reference at `0x005ff1fe` | Compiler-instantiated Singleton base destructor; no free helper source. |
| Scalar wrapper | duplicates ordinary body, then flags/delete/free ABI | Compiler-only scalar deleting destructor; no separate handwritten method. |
| Vtable data | COL plus three slots, all writes from ctor/dtor/scalar | Source-declared/generated-binary; class virtual declaration regenerates it. |
| Child names/order | constructor callees, allocation sizes, existing class/support docs | Seven exact pane classes in indexes 0-6; retain `m_childPanes` and `m_activeChildIndex`. |
| Public helper names | accepted UID00015W/UID00015X bodies and current consumers | Preserve `GetChildPaneByIndex`, `GetActiveChildPane`, `DispatchActiveChildRefresh`, and `SwitchActiveTab`. |
| Source placement | lifecycle island, class/global/file docs, broad reads | `NexusTK/ui/panels/GeneralPurposePanel.cpp`; declaration belongs in its header/source declaration block. |
| Sibling family | separate global address, 14 refs, separate RTTI/type descriptors | Corroborating pattern only; no duplicate target children or source definition. |

- Rejected alternatives: raw `dword_67A874`, explicit `0xffffffff`, `static GeneralPurposePanel *`, function-local accessor storage, AutoInit wrapper, `PanelPane` inheritance, FrameChrome ownership, consumer ownership, a second template-static definition, explicit publication/clear, and handwritten EH/scalar/vtable code.
- No in-scope source-quality issue remains unresolved. Exact original filename/header split and spelling of the generic Singleton implementation are unavailable, but the chosen class/global source shape is behavior-identical and consistent with project convention.

## Evidence Standards Used

- Direct IDA MCP: `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `xrefs_to`, `decompile`, `disasm`, and decorated-name queries on session `9b0396a3`.
- Raw executable evidence: PE section headers, mapped bytes, exact range hashes, allocation-call sequences, function boundaries, and padding.
- Structural evidence: RTTI COL/CHD/base descriptors, PMDs, EBO, vtable entries, constructor/destructor/scalar stores, and allocation size.
- Documentation evidence: current by-memory/global/class/file pages, current generated source/tracker/manual coverage, accepted executed reports, and source-family consumers.
- Negative evidence: no initialized raw bytes, no second target data object, no function-local accessor, no AutoInit object, no PanelPane RTTI/base construction, no ordinary source caller to the clear helper, and no reason to emit raw ABI data.
- Evidence is sufficient for `92/94`; absent original symbols cap spelling confidence below 95.

## Evidence Checked

- MCP health: evidence-time `idb_list` returned sole live NexusTK session `9b0396a3`; `server_health` returned `ok`, auto-analysis ready, Hex-Rays ready, and string cache ready. A bounded target read returned `00 00 00 00`.
- MCP target checks: all 87 xrefs returned in one bounded page with `more:false`; constructor, destructor, helper, scalar, RTTI names, and exact function bounds were independently queried.
- Raw file checks: `.data` RVA `0x26d000`, virtual size `0x2fe24`, raw size `0xd800`, raw file offset `0x26ac00`; target RVA `0x27a874` lies in the virtual tail. Exact SHA256 values: constructor `340C953A1F2832F91FF5598682A5DA8BFBDC2A671A69A5F9CAE6E4839F78C7C1`, destructor `ADC0F027F15DF3DA730A460596C25935AF05CCA39FBBC8B3F859D2A0E7E70DBF`, accessors `53C8E54A7AFFD6BD9FF2F952FF71DF6CCCCE6F692C4D16C19510D2F9084156DD`, switch `133DB046A6045925EACDFA87D14852DF1D9B8127CE34A8C849845A7D3D9CE0B4`, helper pair `DC0FCE3B70887AC925BEFB3ECBB138D638BA22D6D0ABBE30953C53636FF89216`, scalar `87B342F17E30EC9C279870FA37F5473B407C7E2A0D5285CE3033F724CA99E553`, vtable data `6940945830EB30969468C45ADE337DF7A5DD08D81DF4177204F8C72F552805C8`, four zero bytes `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- Current ordinary docs opened: UID00028X, UID0000R0, UID00005Q, UID0000JQ, UID00015V, UID00015W, UID00015X, UID00015Z, UID0003BC, UID00005R, UID0000R1, UID0002VS, adjacent UID0001P1 and AES mutable-state page, and representative consumers listed below.
- Historical search terms: `UID00028X`, `0x0067a874`, `0x0067a878`, `g_pGeneralPurposePanel`, `GeneralPurposePanelConstructor`, `GeneralPurposePanelDestructor`, `GeneralPurposePanelSingleton`, `UID00015V`, `UID00015W`, `UID00015X`, `UID00015Z`, `AboveFrame`, `FrameChrome`, and `m_activeChildIndex`.
- Central executed root opened relevant matches: `executed-b-agent-research/B003/00015V-GeneralPurposePanel-source-quality.md`, `B011/00015W-GeneralPurposePanelChildAccessors-source-quality.md`, `B005/00015X-GeneralPurposePanelSwitchActiveTab-source-quality.md`, `B004/00015Y-GeneralPurposePanel2SwitchActiveChild-empty-emitter-source-quality.md`, and B003/B006/B007/B008 `0000YH-AboveFrame-source-quality.md`. Findings are classified above; none is an exact prior UID00028X direct report.
- Analogous executed lead opened: `executed-b-agent-research/B002/0001OT-g_pItemObjImageLib-source-quality.md`; its physical/semantic Singleton disposition was independently revalidated here rather than inherited.
- Legacy executed/older root `tools/leaser/Agents/Older-Research`: searched, no direct UID00028X report.
- Archived root `archived`: searched, no direct UID00028X report.
- Special root `tools/leaser/Agents/SpecialReports`: searched, no direct UID00028X report.
- Active B001-B005 research roots: searched. B004 UID0001NJ mentions GeneralPurposePanel as a consumer dependency only; no active direct UID00028X report exists.
- Failed or unavailable checks: none. IDA mutation was intentionally skipped because this is read-only report research.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00028X is exactly four loader-zeroed bytes at `0x0067a874-0x0067a878`. | 99% | MCP bytes, PE virtual-tail mapping, adjacent pages | Destination 1 target; hash `35C7E2F5...AC85` | incorporate | applied |
| C02 | The historical `0xffffffff` initializer claim is invalid for source. | 99% | no raw payload at RVA; live bytes zero | target/global/file history labels | reject-stale | applied |
| C03 | UID00028X is physical backing storage and must be false/non-emitting. | 99% | one-definition analysis | Destination 1 plus generated zero marker | incorporate | applied |
| C04 | UID0000R0 is the sole typed source definition. | 98% | semantic owner and 82 cross-source reads | Destination 2 and generated one-definition readback | incorporate | applied |
| C05 | The pointer has external linkage and zero initialization. | 98% | cross-module reads and loader state | Destinations 2-3; one definition/extern | incorporate | applied |
| C06 | The complete target inventory is 87 refs with no truncation. | 99% | MCP `xref_count:87`, `more:false` | target/global/file prose | incorporate | applied |
| C07 | Exactly five refs are lifetime writes and 82 are reads. | 99% | instruction audit of every xref | target/global/lifecycle prose | incorporate | applied |
| C08 | Constructor stores are direct-Singleton compiler lowering. | 99% | PMD +4, null adjustment, ordering | UID0004UL/class/history | reject-stale | applied |
| C09 | Ordinary destructor clear and base teardown are implicit. | 98% | decompile/order/Singleton destruction | UID0004UM exact source and exclusions | incorporate | applied |
| C10 | UID00015Z contains two compiler Singleton base destructors. | 99% | exact bytes and EH-table refs | Destination 8 hash `5369DA38...5693` | incorporate | applied |
| C11 | The new GPP scalar child is compiler-only/no-code. | 99% | flags/free ABI and duplicated dtor | UID0004UN hash `187C6C2C...C92D` | incorporate | applied |
| C12 | UID0003BC is source-declared/generated-binary vtable data. | 99% | COL/three slots/vptr writes | Destination 10 hash `D16AC9DF...9A56` | incorporate | applied |
| C13 | GeneralPurposePanel directly inherits LObject and Singleton. | 99% | decorated RTTI and ctor call | Destination 3 plus generated class readback | incorporate | applied |
| C14 | PanelPane inheritance is contradicted and must be historicalized. | 99% | absent RTTI/base ctor; impossible size | class/file/children historical labels | reject-invalid | applied |
| C15 | Singleton PMD +4 is EBO over the first child pointer. | 99% | RTTI PMD and exact 0x24 allocation | class/constructor/vtable prose | incorporate | applied |
| C16 | Exact fields are seven Pane pointers and active index at +0x20. | 99% | ctor/accessor/switch/read consumers | retained byte-equal class/method blocks | already-present | already-present |
| C17 | Constructor creates seven exact child types in index order 0-6. | 98% | allocation/callee sequence | UID0004UL and generated one-constructor readback | incorporate | applied |
| C18 | Ordinary destructor source is exactly seven MarkForDeletion calls. | 98% | loop body, no null tests, Pane support | UID0004UM and generated one-destructor readback | incorporate | applied |
| C19 | Existing UID00015W formal remains behavior-exact with position 30. | 99% | accepted report/current bytes | byte-equal formal hash `DB0F450C...A99E` | already-present | already-present |
| C20 | Existing UID00015X formal remains behavior-exact with position 40. | 99% | accepted report/current bytes | byte-equal formal hash `B9D48B97...33FD` | already-present | already-present |
| C21 | UID00015V remains a false/non-emitting split index. | 99% | mixed source/compiler contents | retained metadata/formal; enriched real-child index | already-present | already-present |
| C22 | UID0000JQ remains the sole source file. | 98% | lifecycle island and current source route | prose-only Destination 12; generated source UID0000JQ | incorporate | applied |
| C23 | FrameChrome/AboveFrame are consumers, not owners. | 99% | two reads of +0x20; no writes | target/global/file ownership prose | reject-invalid | applied |
| C24 | Input/map/dialog consumers do not own storage. | 99% | read-only groups across modules | complete 82-read negative ownership evidence | reject-invalid | applied |
| C25 | GeneralPurposePanel2 is a separate sibling comparator. | 99% | separate address/RTTI/14-ref family | hashes unchanged; generated sibling union preserved | not-applicable | excluded-with-reason |
| C26 | Scores and metadata match the destination matrix. | 96% | resolved blockers and current gates | twelve ordinary headers plus tracker readback | incorporate | applied |
| C27 | Generated output must contain one target class/global/ctor/dtor path and no ABI source. | 98% | formal routing and compiler split | command `000000015530`, hash `DD3C2138...C076` | incorporate | applied |
| C28 | All stale aliases and assumptions remain labeled historical. | 98% | report/history plan | all changed docs preserve/reject prior assumptions | historicalize | applied |
| C29 | Manual coverage requires the exact supervisor-owned actions below. | 99% | all current rows read | twelve-row handoff rebased over current union | incorporate | applied |
| C30 | Callback requires serial child registration, leases, scoped validators, waited generation, and zero lifecycle actions. | 99% | workflow and destination dependencies | commands `15502-15530`; zero B002 leases/lifecycle | incorporate | applied |

## Positive Evidence Summary

- The slot contains zero bytes and has one exact semantic identity used by all 87 refs.
- Constructor and RTTI independently prove the direct Singleton base: PMD `+0x04`, null-adjusted complete-object store, direct LObject construction, and no PanelPane construction.
- Exact object allocation is `0x24`; fields occupy `+0x04..+0x20`, matching EBO and the seven-child layout without hidden state.
- Ordinary, EH, and scalar teardown all clear the same pointer through expected template/compiler manifestations.
- Eighty-two reads span FrameChrome, map, screen, macro, self-look, user, inventory, spell, item, and status code, requiring an externally visible declaration.
- Existing accepted accessor/switch source uses the same field map and class owner, so the new class/ctor/dtor route forms one coherent source unit.

## IDA MCP Facts

- Evidence session `9b0396a3` was healthy at collection time; module `NexusTK.exe`, imagebase `0x00400000`.
- `0x004b83d0` size `0x1ae` / 430 bytes (Verified with `int_convert.py`), constructor; writes slot at `0x004b8412` and fallback/null result at `0x004b8419`.
- `0x004b8580` size `0x63` / 99 bytes (Verified with `int_convert.py`), ordinary destructor; clears at `0x004b85c6`.
- `0x004b8a90` size `0x0b` / 11 bytes (Verified with `int_convert.py`), exact clear; one xref from constructor EH table at `0x005ff1fe`.
- `0x004b8b40` size `0x93` / 147 bytes (Verified with `int_convert.py`), scalar deleting destructor; clears at `0x004b8b91` and implements delete flags/free.
- Decorated names expose vtable `0x0061a888`, COL `0x00647c94`, CHD `0x00647ca8`, base array `0x00647cb8`, GPP BCD `0x00647cc8`, Singleton BCD `0x00647ce4`, and type descriptors at `0x00676344`/`0x00676368`.
- CHD base entries resolve to GeneralPurposePanel, LObject, and Singleton; Singleton PMD is `{4,-1,0}`. No PanelPane base descriptor appears.
- Vtable bytes at `0x0061a884-0x0061a894` are COL pointer plus slots `0x004b8b40`, `0x004f4b10`, and `0x0041b6c0`; source does not declare raw table data.
- Constructor callers at `0x004f7ff7` and `0x004f8835` each follow allocation of `0x24` bytes.
- Target xrefs: 87 exactly, five writes and 82 reads; no xref remains unclassified.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0067a874-0x0067a878` | UID00028X target | physical storage | false | UID0000R0 | `92/94` | applied no-code |
| semantic global | UID0000R0 | sole external definition | true | UID0000JQ | `92/94` | applied source, position 0 |
| class | UID00005Q | complete declaration | true | UID0000JQ | `92/94` | applied direct hierarchy, position 10 |
| `0x004b83d0-0x004b857e` | UID0004UL | source constructor | true | UID00005Q | `92/94` | applied child, position 10 |
| `0x004b857e-0x004b8580` | aggregate padding | two `0xcc` bytes | false | UID00015V | retained | no child/source |
| `0x004b8580-0x004b85e3` | UID0004UM | source ordinary destructor | true | UID00005Q | `92/94` | applied child, position 20 |
| `0x004b85e3-0x004b85f0` | aggregate padding | alignment | false | UID00015V | retained | no source |
| `0x004b85f0-0x004b8644` | UID00015W | three source methods | true | UID00005Q | `92/94` | body preserved; position 30 applied |
| `0x004b8644-0x004b8650` | aggregate padding | alignment | false | UID00015V | retained | no source |
| `0x004b8650-0x004b8823` | UID00015X | source switch method | true | UID00005Q | `91/94` | body preserved; position 40 applied |
| `0x004b8a80-0x004b8a9b` | UID00015Z | two compiler Singleton base destructors plus padding | false | NONE | `92/95` | applied no-code |
| `0x004b8b40-0x004b8bd3` | UID0004UN | compiler scalar deleting destructor | false | UID00005Q | `93/96` | applied no-code child |
| `0x0061a884-0x0061a894` | UID0003BC | compiler RTTI/vtable data | false | UID00005Q | `92/95` | applied no-code |
| `0x004b83d0-0x004b8bd3` | UID00015V | two-class split/index | false | UID0000JQ | `89/93` | retained non-emitting; inventory enriched |
| source file | UID0000JQ | `GeneralPurposePanel.cpp` | true | FILE | `90/92` | applied prose-only support update |

## Direct Xref / Caller Inventory

| Page/group | Exact target-ref addresses | Count / meaning |
| --- | --- | --- |
| GeneralPurposePanel lifetime | `0x4b8412`, `0x4b8419`, `0x4b85c6`, `0x4b8a90`, `0x4b8b91` | 5 writes: publish/null-adjust, ordinary clear, EH clear, scalar clear |
| AboveFrame/refresh | `0x46140d`, `0x461610` | 2 reads of active-index route |
| DialogPane | `0x49e59c`, `0x49e5cd` | 2 reads |
| WillBeChangedPreviewPanes | `0x4c7adf` | 1 read |
| ItemHelpPane constructor | `0x4c8375`, `0x4c84aa` | 2 reads |
| Map teardown/dispatcher/transition | `0x5049d5`, `0x50803a`, `0x508670`, `0x508ca9`, `0x50fee0` | 5 reads |
| Map packet-handler fragments | `0x5119ca`, `0x5139df`, `0x5139f5`, `0x5144d9`, `0x51478b`, `0x5147a7` | 6 reads |
| Macro dialog constructors | `0x53eded`, `0x541b8d` | 2 reads |
| ScreenPane/palette refresh | `0x556dfc`, `0x5593f1` | 2 reads |
| SelfLook mouse/help | `0x569093`, `0x569153`, `0x5698a2` | 3 reads |
| Macro edit controls | `0x57fca0`, `0x5803ef` | 2 reads |
| UseInventorySlot/local extensions | `0x5a3eee`, `0x5a3fc2`, `0x5a4000`, `0x5a4030`, `0x5abfce` | 5 reads |
| Say-mode helpers | `0x5a4db0`, `0x5a4e40`, `0x5a4e70`, `0x5a4f20`, `0x5a4f40` | 5 reads |
| UserPane key/text handler | `0x5a5f97`, `0x5a605d`, `0x5a6d24`, `0x5a6e27` | 4 reads |
| UserPane server/settings/entry | `0x5a7e7c`, `0x5aa6d4`, `0x5aacba` | 3 reads |
| UI panel switch packet | `0x5abdd9`, `0x5abdf8`, `0x5abe33`, `0x5abe4b`, `0x5abe6a`, `0x5abea1`, `0x5abec8` | 7 reads |
| Ordinary input-pane destructors | `0x5ae016`, `0x5ae3c6`, `0x5aed8a`, `0x5b0856`, `0x5b0b96`, `0x5b0e76`, `0x5b1106`, `0x5b1356` | 8 reads |
| Input-pane key handlers | `0x5b13d5`, `0x5b3045`, `0x5b3295` | 3 reads |
| Drop/Give/Post/Throw/Use/Eat/Spell/Wield/Wear | `0x5b45b5`, `0x5b48e5`, `0x5b4dc5`, `0x5b5075`, `0x5b5735`, `0x5b5995`, `0x5b5da5`, `0x5b5fc5`, `0x5b6225`, `0x5b63d5`, `0x5b6665` | 11 reads |
| Input-pane scalar wrappers | `0x5b7a6a`, `0x5b7c66`, `0x5b7d36`, `0x5b7e06`, `0x5b7ed6`, `0x5b7fa6`, `0x5b8076`, `0x5b8146` | 8 reads |
| UserStatus payload | `0x5ba6ba` | 1 read |
| Total | all addresses above | 87 = 5 writes + 82 reads |

## Documentation Evidence And IDA Status

- Evidence-time/pre-callback UID00028X/UID0000R0 duplicated an empty route and retained stale initializer/lifetime wording. Current UID00028X is false/non-emitting and UID0000R0 alone emits the position-0 typed zero definition.
- Evidence-time/pre-callback UID00005Q used `PanelPane`. Current UID00005Q has direct `LObject`/`Singleton<GeneralPurposePanel>` inheritance, PMD `+0x04` EBO, exact 0x24 layout, extern declaration, and real method children.
- UID00015W and UID00015X retain accepted behavior-complete C++ byte-for-byte, with current positions 30/40 and accepted scores `92/94` and `91/94`.
- UID00015V remains false/non-emitting and now lists real UID0004UL/UID0004UM/UID0004UN plus resolved source/compiler/padding/vtable/storage routes.
- UID00015Z is `92/95`, NONE/false/blank, with exact two-Singleton-base-destructor proof. UID0003BC is `92/95`, class-owned false/no-code, and registered in validator state.
- Historical generated command `000000015481` proved the old defects. Callback waited command `000000015530` proves one direct-Singleton primary class, one extern, one definition, one constructor, one ordinary destructor, exact accepted accessors/switch, no primary Empty Emitter Marker, and no handwritten ABI source. Final observed command `000000015548` changes only the volatile header relative to that semantic proof and retains every exact assertion.
- Historical tracker commands `000000015482` and `000000015486` recorded the report-only state, and callback command `000000015532` first recorded the applied state. The final time-bounded tracker read was command `000000015549`, SHA256 `F2E2FA14786D3987AD84CE3092977833D16218886F7474B21E0E8BDD7868935F`, `1,535,343` bytes, `6,218` lines, and records the same applied target/global/class/real-child metadata. These tracker epochs are volatile observations, not indefinite lifecycle assertions.

## Ranked Ownership Analysis

### 1. UID0000R0 semantic global in UID0000JQ GeneralPurposePanel.cpp

- Evidence for: exact semantic page; constructor/destructor/template lifetime island; 82 reads across source modules; existing file route; project global naming convention; one-definition precedent.
- Evidence against: original header filename and exact template spelling are not recovered.
- Decision: accepted sole source definition and external declaration.

### 2. UID00005Q GeneralPurposePanel direct Singleton class

- Evidence for: RTTI names, PMD `+0x04`, EBO, exact allocation size, direct LObject constructor, seven fields, accepted methods, lifecycle code.
- Evidence against: exact original public spellings remain inferred.
- Decision: accepted semantic class owner for constructor/destructor/accessor/switch/scalar/vtable support.

### 3. UID00028X physical storage

- Evidence for: exact runtime address and all xrefs.
- Evidence against: it represents no separate source declaration beyond UID0000R0; emitting it duplicates storage.
- Decision: retain semantic owner UID0000R0 but false/non-emitting.

### 4. FrameChrome, AboveFrame, map, user, or input consumers

- Evidence for: many reads and behavior dependencies.
- Evidence against: no target writes, no construction, no source-definition evidence.
- Decision: rejected as owners; preserve as consumers.

### Proposed new file/grouping, if applicable

- No new file. UID0000JQ is the established narrow source module for both panel shells.
- New exact by-memory children belong under UID00015V inventory and class UID00005Q: constructor, ordinary destructor, scalar wrapper.
- GeneralPurposePanel2 remains a separate sibling family within the same file; it is not merged with target storage or child identities.

## Source Placement

- Recommended source module: `NexusTK/ui/panels/GeneralPurposePanel.cpp` under UID0000JQ.
- Place the sole pointer definition at file position 0, the complete class at file position 10, then class children at positions 10/20/30/40 in binary/source order.
- Place one external declaration after the complete class declaration; do not add reconstruction metadata to by-file pages.
- The direct Singleton base is source declaration, while publication/clear code is compiler/template lowering.
- Reject FrameChrome, MapPane, UserPane, input-pane, static/function-local, AutoInit, or standalone `Globals.cpp` placement because they consume rather than own the lifetime.
- Remaining placement uncertainty: exact `.h` filename is not recovered. It does not affect one-definition behavior or current emitter routing.

## Range / Split / Padding / Reclassification Analysis

- Target bounds are exact: predecessor UID0001P1 ends at `0x0067a874`; target occupies one dword; successor AES mutable state begins at `0x0067a878`.
- The target lies in zero-filled `.data` virtual tail, so no initialized raw-file payload exists for this dword.
- UID00015V remains an index, not a monolithic source item. Register exact children at `0x004b83d0-0x004b857e`, `0x004b8580-0x004b85e3`, and `0x004b8b40-0x004b8bd3`.
- Preserve padding `0x004b857e-0x004b8580`, `0x004b85e3-0x004b85f0`, `0x004b8644-0x004b8650`, and other aggregate gaps as compiler alignment, not source bodies.
- UID00015Z spans two 11-byte Singleton base destructor instantiations at `0x004b8a80` and `0x004b8a90`, separated by padding. Mixed semantic class ownership makes owner NONE correct.
- UID0003BC spans the COL pointer and three-slot vtable only. No child source should be pasted into it.
- Parent/container impact: UID00015V stays false/no-code; exact children and class/global pages carry source.

## Negative Evidence Summary

- No initialized `ff ff ff ff` bytes exist for UID00028X in the executable image or file-backed `.data` payload.
- No source-visible sentinel behavior compares the pointer to `-1`; runtime lifetime uses null/live pointer semantics.
- No `PanelPane` RTTI/base descriptor or constructor call exists in the class constructor.
- No second storage symbol, accessor-local static, AutoInit object, or pointer-definition wrapper exists.
- No consumer writes the slot; read fan-in does not transfer ownership.
- No ordinary call targets `0x004b8a90`; its only xref is constructor EH metadata.
- No null check precedes the destructor's seven `MarkForDeletion` calls; adding one would alter behavior.
- No source should contain vptr stores, pointer adjustments, fallback publication, explicit clear, EH funclets, scalar flags, object-size delete guard, storage free, COL, RTTI arrays, or raw vtable dwords.

## IDA Rename / Type / Comment Recommendations

- Source-facing name: `g_pGeneralPurposePanel`, type `GeneralPurposePanel *`, external linkage, zero initializer.
- Class source type: `GeneralPurposePanel : public LObject, public Singleton<GeneralPurposePanel>`.
- Fields: `Pane *m_childPanes[7]` at `+0x04..+0x1c`; `int m_activeChildIndex` at `+0x20`.
- New source children: `GeneralPurposePanelConstructor`, `GeneralPurposePanelDestructor`; compiler child: `GeneralPurposePanelScalarDeletingDestructor`.
- Existing accepted names retained: `GetChildPaneByIndex`, `GetActiveChildPane`, `DispatchActiveChildRefresh`, `SwitchActiveTab`.
- Historical/raw aliases retained only for search: `dword_67A874`, `unk_67A874`, `DAT_0067a874`, explicit `0xffffffff`, `PanelPane` base, and `RefreshActiveChild`.
- IDA DB changes are not requested and were not made. These are documentation/source recommendations only.

## First-Draft C++ Recommendation

- Exactly eleven managed destination blocks follow. Every source-bearing block is destination-specific exact insertion text. Destinations 1, 8-11 are intentional blank no-code blocks.
- No C++ appears outside these managed blocks. No third-party import applies.

### Destination 1: UID00028X physical backing storage

```text
*** UID:00028X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000R0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact four-byte loader-zeroed physical backing slot for g_pGeneralPurposePanel with complete 87-reference inventory, five direct Singleton/compiler lifetime writes, 82 cross-source reads, exact adjacent boundaries, direct class RTTI/PMD/EBO evidence, and sole typed source definition owned by UID0000R0; this storage page is false/non-emitting and cannot duplicate source. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 2: UID0000R0 sole module definition

```text
*** UID:0000R0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class GeneralPurposePanel;

GeneralPurposePanel *g_pGeneralPurposePanel = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3: UID00005Q complete class/header declaration

```text
*** UID:00005Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class GeneralPurposePanel : public LObject, public Singleton<GeneralPurposePanel>
{
public:
    GeneralPurposePanel();
    virtual ~GeneralPurposePanel();

    Pane *GetChildPaneByIndex(int index);
    Pane *GetActiveChildPane();
    void DispatchActiveChildRefresh();
    void SwitchActiveTab(
        int tabIndex,
        const unsigned char *packetData);

private:
    Pane *m_childPanes[7];
    int m_activeChildIndex;
};

extern GeneralPurposePanel *g_pGeneralPurposePanel;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4: UID0004UL GeneralPurposePanel constructor

```text
*** UID:0004UL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
GeneralPurposePanel::GeneralPurposePanel()
    : Singleton<GeneralPurposePanel>(),
      m_activeChildIndex(-1)
{
    m_childPanes[0] = new SelfLookPane;
    m_childPanes[1] = new UserLookPane;
    m_childPanes[2] = new NewInventoryPane;
    m_childPanes[3] = new NewSpellInventoryPane;
    m_childPanes[4] = new NewGroupPane;
    m_childPanes[5] = new CollectionPane;
    m_childPanes[6] = new NewOptionPane;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact source-authored GeneralPurposePanel constructor over 0x004b83d0-0x004b857e with implicit LObject construction, direct Singleton<GeneralPurposePanel> base initialization, compiler-lowered +0x04 EBO publication and unwind clear, m_activeChildIndex -1 initialization, seven exact child allocations/stores in indexes 0-6, exact allocation/callee/range/hash/padding evidence, and no duplicate handwritten singleton assignment, vptr store, null-adjust fallback, or EH cleanup. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 5: UID0004UM GeneralPurposePanel ordinary destructor

```text
*** UID:0004UM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
GeneralPurposePanel::~GeneralPurposePanel()
{
    for (int index = 0; index < 7; ++index)
        m_childPanes[index]->MarkForDeletion();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact source-authored GeneralPurposePanel ordinary destructor over 0x004b8580-0x004b85e3 with seven unconditional Pane::MarkForDeletion calls in child-array order, exact no-null-check behavior, compiler-lowered vptr reseat, implicit Singleton clear, implicit LObject teardown, exact range/hash/padding, and no duplicate handwritten clear, base call, scalar flags, size guard, or storage free. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 6: UID00015W child accessor methods

```text
*** UID:00015W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
Pane* GeneralPurposePanel::GetChildPaneByIndex(int index)
{
    const int childCount = (g_useEpfAssets == 1) ? 7 : 4;
    if (index >= childCount) {
        return NULL;
    }

    return m_childPanes[index];
}

Pane* GeneralPurposePanel::GetActiveChildPane()
{
    if (m_activeChildIndex == -1) {
        return NULL;
    }

    return m_childPanes[m_activeChildIndex];
}

void GeneralPurposePanel::DispatchActiveChildRefresh()
{
    if (m_activeChildIndex != -1) {
        m_childPanes[m_activeChildIndex]->InvalidateRect(NULL);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Three source-authored GeneralPurposePanel child accessor helpers with exact 0x004b85f0-0x004b8644 range/hash/padding, explicit EPF seven-versus-legacy-four upper-bound-only lookup, no added negative guard, active index at +0x20, Pane::InvalidateRect(NULL) dispatch, broad caller inventory, rejected stale SpellOneArgInputPane ownership, and source position 30 after the ordinary destructor. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 7: UID00015X active-tab switch

```text
*** UID:00015X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void GeneralPurposePanel::SwitchActiveTab(
    int tabIndex,
    const unsigned char *packetData)
{
    if (g_useEpfAssets == 1) {
        if (tabIndex >= 7)
            return;

        if (tabIndex == m_activeChildIndex &&
            tabIndex != 0 &&
            tabIndex != 1)
            return;

        if (g_pTotemFrame != NULL)
            g_pTotemFrame->MarkForDeletion();

        Pane *oldChild = NULL;
        if (m_activeChildIndex != -1)
            oldChild = m_childPanes[m_activeChildIndex];

        if (oldChild != NULL) {
            oldChild->Collapse();
            oldChild->UnregisterEventHandler();
        }

        m_activeChildIndex = tabIndex;

        Pane *newChild = NULL;
        if (tabIndex != -1)
            newChild = m_childPanes[tabIndex];

        RectBounds bounds;
        bounds.SetLTRB(832, 79, 1021, 367);
        newChild->SetBounds(&bounds, 0);
        newChild->AddToLayer(
            &bounds,
            0,
            g_pBackPane,
            g_mainUiLayerSlots.rootPaneLayerContext);
        newChild->SetPaneOrder(0, g_pBackPane);
        newChild->OnActivate(packetData);
        ReleaseDynamicAboveFrame();
        RecreateDynamicAboveFrame();
    } else {
        if (tabIndex >= 4)
            return;

        if (tabIndex == m_activeChildIndex &&
            tabIndex != 0 &&
            tabIndex != 1)
            return;

        if (g_pTotemFrame != NULL)
            g_pTotemFrame->MarkForDeletion();

        Pane *oldChild = NULL;
        if (m_activeChildIndex != -1)
            oldChild = m_childPanes[m_activeChildIndex];

        if (oldChild != NULL) {
            oldChild->Collapse();
            oldChild->UnregisterEventHandler();
        }

        m_activeChildIndex = tabIndex;

        Pane *newChild = NULL;
        if (tabIndex != -1)
            newChild = m_childPanes[tabIndex];

        RectBounds bounds;
        bounds.SetLTRB(434, 12, 626, 300);
        newChild->SetBounds(&bounds, 0);
        newChild->AddToLayer(
            &bounds,
            0,
            g_pBackPane,
            g_mainUiLayerSlots.rootPaneLayerContext);
        newChild->SetPaneOrder(0, g_pBackPane);
        if (packetData != NULL)
            newChild->OnActivate(packetData);
        g_pInterfaceEfxMgr->TriggerInterfaceEffect(m_activeChildIndex);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact GeneralPurposePanel::SwitchActiveTab source body with 0x004b8650-0x004b8823 half-open interval, EPF seven/legacy four limits, same-tab 0/1 exceptions, Pane child array and active index, Collapse/unregister ordering, exact branch rectangles and activation/null behavior, FrameChrome and InterfaceEfx dependencies, 35-call fan-in, padding, stale SpellOneArgInputPane ownership rejection, and source position 40. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 8: UID00015Z compiler Singleton base-destructor pair

```text
*** UID:00015Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact compiler-emitted Singleton<GeneralPurposePanel2> and Singleton<GeneralPurposePanel> base-destructor instantiations at 0x004b8a80 and 0x004b8a90, each eleven bytes and reached only from its constructor unwind table, with direct RTTI/PMD/EBO identity, mixed semantic class ownership, ordinary/scalar inline parity, intervening padding, and no handwritten clear-helper source. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 9: UID0004UN scalar deleting destructor

```text
*** UID:0004UN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact compiler scalar deleting destructor for GeneralPurposePanel over 0x004b8b40-0x004b8bd3, duplicating the ordinary destructor's seven child MarkForDeletion calls and implicit Singleton/LObject teardown before delete-flag, size-guard, and storage-free ABI mechanics; UID0004UM is the sole handwritten destructor source and this wrapper remains false/non-emitting. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 10: UID0003BC raw RTTI/vtable data

```text
*** UID:0003BC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact compiler RTTI complete-object-locator pointer and three-slot GeneralPurposePanel vtable data with direct GeneralPurposePanel/LObject/Singleton<GeneralPurposePanel> hierarchy, constructor/ordinary/scalar vptr stores, adjacent vtable boundaries, and no handwritten raw table source; the complete class declaration regenerates this source-declared binary support. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 11: UID00015V non-emitting source-unit index

```text
*** UID:00015V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Non-emitting GeneralPurposePanel.cpp split/index with exact 0x004b83d0-0x004b8bd3 bounds, both panel classes, real constructor/destructor/accessor/switch children, compiler Singleton base destructors/scalar wrappers, padding, vtable/source routes, direct Singleton RTTI/PMD/EBO evidence, one-definition globals, dependencies, and historical ownership alternatives documented without monolithic source duplication. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Behavior preservation: direct base construction publishes before derived member initialization; constructor failure uses compiler EH cleanup; reverse destruction performs authored child deletion requests before implicit Singleton clear and LObject teardown.
- One-definition preservation: Destination 3 declares externally, Destination 2 defines once, Destination 1 emits nothing.
- Compiler exclusion: no explicit Singleton assignment/clear, null-adjust branch, vptr store, EH funclet, scalar flags, object-size delete guard, storage free, RTTI array, or vtable dword is handwritten.

## Final Recommendation

- Destinations 1-11 and Destination 12 prose are applied at full report detail.
- UID0004UL, UID0004UM, and UID0004UN were serially registered under UID00015V; all placeholders are replaced with real UIDs.
- UID00015W/UID00015X bodies are byte-equal to accepted text with positions 30/40 and accepted scores.
- The physical target, helper pair, scalar wrapper, vtable data, and aggregate are false/non-emitting exactly as accepted.
- UID0000R0 is the only source definition and UID00005Q is the semantic class owner/declaration emitter.
- Sibling UID00005R/UID0000R1/UID0002VS are byte-for-byte unchanged at their accepted hashes. Their separate inheritance/storage closure is not duplicated or claimed as B002 work.
- No in-scope future research remains.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md`.
- Applied Destination 1 exactly: `92/94`, semantic owner retained, false, blank emitter/position/formal, `Nested:0`.
- Applied zero-filled virtual-tail evidence, four-byte hash, 87-ref inventory, five-write/82-read split, one-definition route, boundaries, hierarchy, compiler-lifetime distinction, negative evidence, and rejected alternatives.
- Preserved old `0xffffffff` and raw alias provenance only as explicitly superseded historical evidence.

## Recommended Support Doc Changes

- Destination 2 applied at `92/94`, position 0, sole typed definition, and complete lifetime/consumer/linkage/one-definition evidence.
- Destination 3 applied at `92/94`, position 10, complete direct LObject/Singleton declaration, EBO/layout/method/child/source/compiler evidence, and historicalized PanelPane.
- Destination 4 is real UID0004UL with exact constructor formal, position 10, range/hash/callees/children/EH/negative evidence.
- Destination 5 is real UID0004UM with exact destructor formal, position 20, range/hash/loop/no-null/compiler teardown evidence.
- Destination 6 UID00015W is `92/94`, position 30, with exact formal and all caller/behavior/history detail preserved.
- Destination 7 UID00015X remains `91/94`, position 40, with exact formal and all caller/dependency/history detail preserved.
- Destination 8 UID00015Z is `92/95`, NONE/false/blank, with exact two-template-destructor no-code proof.
- Destination 9 is real UID0004UN at `93/96`, class owner, false/blank, with full ABI no-code proof.
- Destination 10 UID0003BC is `92/95`, class owner, false/blank, with complete RTTI/vtable no-code proof.
- Destination 11 UID00015V remains `89/93`, false/blank, with real child inventory, source/compiler split, EBO, storage route, and exact padding.
- Destination 12 is prose-only `90/92` with one-definition/header/source ordering, direct Singleton hierarchy, exact primary children, compiler exclusions, and sibling boundary; no by-file reconstruction metadata was added.
- Destination 13 verify-only pages UID00005R/UID0000R1/UID0002VS are unchanged at accepted hashes.
- Destination 14 FrameChrome/AboveFrame and all 82 consumers retain dependency-only ownership; no consumer-owned definition was added.
- Destination 15 generated/tracker/manual readback is complete without manual generated/coverage edits.

## Score And Metadata Recommendation

| UID | Before callback | Applied | Owner | Reconstructable / emitter / position |
| --- | --- | --- | --- | --- |
| UID00028X | `86/90` | `92/94` | UID0000R0 | false / blank / blank |
| UID0000R0 | `88/86` | `92/94` | UID0000JQ | true / UID0000JQ / 0 |
| UID00005Q | `89/91` | `92/94` | UID0000JQ | true / UID0000JQ / 10 |
| UID0004UL | absent | `92/94` | UID00005Q | true / UID00005Q / 10 |
| UID0004UM | absent | `92/94` | UID00005Q | true / UID00005Q / 20 |
| UID00015W | `88/91` | `92/94` | UID00005Q | true / UID00005Q / 30 |
| UID00015X | `91/94` | `91/94` | UID00005Q | true / UID00005Q / 40 |
| UID00015Z | `86/90` | `92/95` | NONE | false / blank / blank |
| UID0004UN | absent | `93/96` | UID00005Q | false / blank / blank |
| UID0003BC | `86/92` | `92/95` | UID00005Q | false / blank / blank |
| UID00015V | `89/93` | `89/93` | UID0000JQ | false / blank / blank |
| UID0000JQ | `89/91` | `90/92` | FILE | prose-only by-file root |

- Target score rises because bytes, section semantics, all refs, hierarchy, one-definition route, initializer, linkage, source/compiler lifetime, boundaries, and no-code disposition are resolved.
- Scores remain below 95 because original header filename, generic Singleton template source, and some inferred public spellings are not symbol-proven.
- GeneralPurposePanel2 is not rescored by this target report.

## Open Questions With Attempted Resolution

- Was the static source initializer `0xffffffff`? Resolved no: no raw bytes back the claim, current bytes are zero, and code uses null/live semantics.
- Is publication manual source? Resolved no: PMD `+0x04`, null-adjustment, and ordering identify direct Singleton base lowering.
- Is the base PanelPane? Resolved no: RTTI/base ctor/size all contradict it.
- Where is the source definition? Resolved: sole external definition in UID0000JQ, header declaration after the class.
- Is the clear helper handwritten? Resolved no: one EH-table xref and exact Singleton destructor shape.
- Is the ordinary destructor empty? Resolved no: seven child deletion requests are authored; only clear/base teardown are implicit.
- Should scalar/vtable bytes emit? Resolved no: compiler ABI/data generated from the class declaration.
- Do consumers imply another owner? Resolved no: 82 reads without writes prove access, not ownership.
- Remaining uncertainty: exact original header filename and generic Singleton spelling. These do not change source behavior, formal declarations, metadata, or scores.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Historical callback-read manual hashes were by-memory `DBBE05F492E692CB4F9AAC44C089AF2DB4D639A5B01839AFCE183524174BB0AA`, by-global `CCD3A1EEDCE573D08F35204E03C2B555F60C6A73541B9BE2ADD082888D7CE474`, by-class `180AAA33BCF01060F431021B96CDF1EDF23C6C8077107339D3C31241CB895D72`, and by-file `98F7A112CE92D6D3E888EAB109345C1EA0EA9DD3B2065FBAF18620A3F50103E8`.
- The final time-bounded reconciliation read observed by-memory `5F05B4ED5ED2F1A37BBDBAEDB550B47AF85A5BC884E42C77118D25055EEFBE9C` (`1,870,851` bytes / `4,422` lines), by-global `12213CE572404A7960F9819A401BE4197615A97BDB4788868614228F349C7292` (`91,643` / `214`), by-class `6A6DB4EEF150CC2915749322C1FAD17F6D250D269FCF19257276C4824EC69849` (`242,188` / `623`), and by-file `F512B5308D0C61931AAD8848307DA4AE67073FDB689BA0543BAA9750A5229456` (`139,871` / `316`). The exact target rows remain stale/absent: UID00015V line 1503, UID00015W 1504, UID00015X 1505, UID00015Z 1507, UID00028X 4223, UID0000R0 line 89, UID00005Q line 231, and UID0000JQ line 107; UID0004UL/UID0004UM/UID0004UN/UID0003BC actions remain absent as specified below. Preserve all unrelated rows. Supervisor owns application of these exact replacements/additions after callback verification; B002 did not edit manual coverage.

1. Replace UID00015V at its current `0x004b83d0` anchor with:

`    - [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md) 0x004b83d0-0x004b8bd3 | split/index | GeneralPurposePanel source-unit inventory : ignored : 89% : very-strong : Non-emitting two-class source-unit index with exact constructor/destructor/accessor/switch children, compiler Singleton base destructors/scalar wrappers, padding, vtable/source routes, direct Singleton RTTI/PMD/EBO evidence, one-definition globals, dependencies, and historical ownership alternatives; exact children carry source.`

2. Add UID0004UL immediately after UID00015V and before the first following child:

`        - [UID:0004UL][0x004b83d0-0x004b857e.GeneralPurposePanelConstructor](by-memory/0x004b83d0-0x004b857e.GeneralPurposePanelConstructor.md) 0x004b83d0-0x004b857e | constructor | GeneralPurposePanel::GeneralPurposePanel : reconstructable : 92% : very-strong : Exact direct-Singleton source constructor with implicit LObject construction, +0x04 EBO publication/unwind clear, active index -1, seven exact child allocations/stores in indexes 0-6, exact range/hash/padding, and no handwritten singleton/vptr/EH lowering.`

3. Add UID0004UM after constructor and before UID00015W:

`        - [UID:0004UM][0x004b8580-0x004b85e3.GeneralPurposePanelDestructor](by-memory/0x004b8580-0x004b85e3.GeneralPurposePanelDestructor.md) 0x004b8580-0x004b85e3 | destructor | GeneralPurposePanel::~GeneralPurposePanel : reconstructable : 92% : very-strong : Exact ordinary destructor with seven unconditional child MarkForDeletion calls, no null checks, implicit Singleton clear/LObject teardown, exact range/hash/padding, and no handwritten vptr/base/scalar/delete ABI.`

4. Replace UID00015W with:

`        - [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md) 0x004b85f0-0x004b8644 | methods | GeneralPurposePanel child accessors : reconstructable : 92% : very-strong : Three exact source methods with EPF seven/legacy four upper-bound-only lookup, active-index sentinel at +0x20, Pane::InvalidateRect(NULL) dispatch, exact range/hash/padding/callers, position 30, and rejected SpellOneArgInputPane ownership.`

5. Replace UID00015X with:

`        - [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md) 0x004b8650-0x004b8823 | method | GeneralPurposePanel::SwitchActiveTab : reconstructable : 91% : very-strong : Exact EPF seven/legacy four tab-switch source with same-tab exceptions, child collapse/unregister ordering, active-index store, exact bounds/layer/order/activation behavior, FrameChrome and InterfaceEfx routes, position 40, and stale SpellOneArgInputPane ownership rejected.`

6. Replace UID00015Z with:

`    - [UID:00015Z][0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers](by-memory/0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers.md) 0x004b8a80-0x004b8a9b | compiler base destructors | GeneralPurposePanel singleton cleanup pair : ignored : 92% : very-strong : Exact eleven-byte Singleton<GeneralPurposePanel2> and Singleton<GeneralPurposePanel> constructor-unwind base-destructor instantiations with direct RTTI/PMD/EBO identity, ordinary/scalar parity, mixed class ownership, intervening padding, and blank non-emitting formal C++.`

7. Add UID0004UN at the `0x004b8b40` anchor:

`    - [UID:0004UN][0x004b8b40-0x004b8bd3.GeneralPurposePanelScalarDeletingDestructor](by-memory/0x004b8b40-0x004b8bd3.GeneralPurposePanelScalarDeletingDestructor.md) 0x004b8b40-0x004b8bd3 | compiler scalar deleting destructor | GeneralPurposePanel scalar deleting destructor : ignored : 93% : very-strong : Exact compiler wrapper duplicating seven child deletion requests and implicit Singleton/LObject teardown before delete flags, size guard, and storage free; ordinary destructor child is sole handwritten source and formal C++ stays blank.`

8. Add UID0003BC at its `0x0061a884` read-only-data anchor:

`        - [UID:0003BC][0x0061a884-0x0061a894.GeneralPurposePanelVtableData](by-memory/0x0061a884-0x0061a894.GeneralPurposePanelVtableData.md) 0x0061a884-0x0061a894 | compiler RTTI/vtable data | GeneralPurposePanel vtable data : ignored : 92% : very-strong : Exact COL pointer and three-slot vtable with GeneralPurposePanel/LObject/Singleton hierarchy, constructor/ordinary/scalar vptr stores, adjacent boundaries, source-declared/generated-binary disposition, and blank non-emitting formal C++.`

9. Replace UID00028X at line/anchor `0x0067a874` with:

`    - [UID:00028X][0x0067a874-0x0067a878.g_pGeneralPurposePanel](by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md) 0x0067a874-0x0067a878 | singleton backing storage | g_pGeneralPurposePanel : ignored : 92% : very-strong : Exact four-byte loader-zeroed physical slot with complete 87-reference inventory, five direct Singleton/compiler lifetime writes, 82 cross-source reads, adjacent boundaries, canonical semantic owner UID0000R0, and one typed external source definition; false/non-emitting with no duplicate C++.`

10. Replace UID0000R0 in `by-global/-coverage-report.md` with:

`- [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md) : reconstructable : 92% : very-strong : Sole externally linked GeneralPurposePanel singleton pointer definition at position 0 in NexusTK/ui/panels/GeneralPurposePanel.cpp, matched by one header extern after the complete direct LObject plus Singleton<GeneralPurposePanel> class. Exact storage UID00028X has 87 refs, five compiler/template lifetime writes, 82 reads, loader-zeroed backing, one-definition policy, and no physical-page duplicate.`

11. Replace UID00005Q in `by-class/-coverage-report.md` with:

`- [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md) : reconstructable : 92% : very-strong : Complete seven-child side-panel class with direct LObject plus Singleton<GeneralPurposePanel> inheritance, PMD +0x04 EBO over m_childPanes[0], exact 0x24 layout, source constructor/destructor/accessor/switch children, sole external g_pGeneralPurposePanel definition/header declaration, compiler-only EH/scalar/vtable support, and preserved child index and consumer behavior.`

12. Replace UID0000JQ in `by-file/-coverage-report.md` with:

`- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) : reconstructable : 90% : very-strong : NexusTK/ui/panels/GeneralPurposePanel.cpp owns one position-0 typed g_pGeneralPurposePanel definition and complete direct LObject plus Singleton<GeneralPurposePanel> class/header route. Exact constructor/destructor/accessor/switch source order, seven-child layout, compiler-only Singleton/EH/scalar/vtable artifacts, full 87-ref inventory, one-definition policy, sibling boundary, aliases, and no by-file reconstruction metadata are documented.`

- Tracker is validator-owned; do not write tracker row text manually. After callback validation, supervisor verifies generated rows reflect ordinary metadata and real child UIDs.

## Follow-Up Actions

- B002 callback work is complete: the three children are registered, every accepted ordinary destination is applied/verified, all formals match, validators passed, generated assertions passed, and all leases are released.
- Supervisor-owned manual coverage: the twelve exact actions remain an external handoff for independent application after callback review; this report records current rows/hashes and B002 did not edit coverage.
- Supervisor review/lifecycle: independent Gate 2, any manual coverage application, report validation/execution, movement, and archive state are supervisor/validator-owned. The exact current report path and any later validator-owned lifecycle history are authoritative; B002 asserts no global pending/not-run lifecycle state that would become stale.
- A-agent actions: none.
- B002 future research: none for UID00028X. GeneralPurposePanel2 is an independent sibling target, not a duplicate dependency child.
- Lifecycle: B002 never runs report execution, probe, move, or archive commands. Current/future path and lifecycle state remain external supervisor/validator-owned facts.

## Confidence

- Recommendation confidence: `99%` for physical/semantic split and one-definition policy.
- Source-shape confidence: `98%` for direct Singleton base, PMD/EBO, constructor publication, destructor clear, EH/scalar/vtable compiler dispositions.
- Name/linkage confidence: `95%` for `g_pGeneralPurposePanel` external definition and accepted method/field names.
- Score confidence: `96%` for the destination matrix.
- Remaining uncertainty is limited to original header filename, generic Singleton template spelling, and symbol-level proof of inferred public names; none changes behavior or source routing.

## Validator Results

- MCP read-only checks succeeded on evidence session `9b0396a3`; no callback IDA call or mutation was needed.

| Command | Timestamp | File / purpose | Exit / ok | Warnings | Side effects / result |
| --- | --- | --- | --- | --- | --- |
| `000000015502` | `2026-07-20T17:54:59-04:00` | UID0004UL constructor registration | `0`; registration succeeded (no separate `ok` counter emitted) | none | inserted UID0004UL, path/owner/score/emitter/position/formal registry; generated deferred |
| `000000015503` | `2026-07-20T17:56:22-04:00` | UID0004UM destructor registration | `0`; registration succeeded (no separate `ok` counter emitted) | none | inserted UID0004UM and complete registry; generated deferred |
| `000000015504` | `2026-07-20T17:57:48-04:00` | UID0004UN scalar registration | `0`; registration succeeded (no separate `ok` counter emitted) | two UID0003BC missing-ref notices | inserted UID0004UN and no-code registry; notices resolved by command 15520 registering existing UID0003BC |
| `000000015505` | `2026-07-20T17:59:40-04:00` | UID00028X target | `0 / ok:1` | none | `86/90 -> 92/94`, true/emitter -> false/blank; generated deferred |
| `000000015507` | `2026-07-20T18:00:47-04:00` | UID0000R0 global | `0 / ok:1` | two pre-existing UID0003A2 missing-ref notices | `92/94`, position 0 and formal body registry; generated deferred |
| `000000015508` | `2026-07-20T18:01:53-04:00` | UID00005Q class | `0 / ok:1` | three UID0003BC missing-ref notices | `92/94`, position 10 and corrected class-block registry; notices resolved by command 15520; generated deferred |
| `000000015511` | `2026-07-20T18:02:44-04:00` | UID00015W accessors | `0 / ok:1` | two pre-existing UID0003A2 missing-ref notices | `92/94`, position 30; validator normalized current UID0003UT path; generated deferred |
| `000000015514` | `2026-07-20T18:03:41-04:00` | UID00015X switch | `0 / ok:1` | none | position 40; validator normalized current UID0003UT path; generated deferred |
| `000000015517` | `2026-07-20T18:04:38-04:00` | UID00015Z helper pair | `0 / ok:1` | none | `92/95`; generated deferred |
| `000000015520` | `2026-07-20T18:05:41-04:00` | UID0003BC vtable data | `0 / ok:1` | none | registered existing UID path, inserted metadata separator, set `92/95` false/blank, resolved prior UID0003BC refs; generated deferred |
| `000000015524` | `2026-07-20T18:07:16-04:00` | UID00015V aggregate | `0 / ok:1` | two pre-existing UID0003A2 missing-ref notices | linked real children and normalized their labels; generated deferred |
| `000000015527` | `2026-07-20T18:08:25-04:00` | UID0000JQ file | `0 / ok:1` | one pre-existing UID0003A2 missing-ref notice | `90/92`, current child-link normalization; generated deferred |
| `000000015530` | `2026-07-20T18:08:56-04:00` | final UID0000JQ `--wait-generated` | `0 / ok:1` | one pre-existing UID0003A2 missing-ref notice plus unrelated repository-wide generated advisories | generated refresh completed; registry rebuilt; target source header is command 15530 |

- Callback waited generated readback: `auto-generated/NexusTK/ui/panels/GeneralPurposePanel.cpp`, command `000000015530`, SHA256 `DD3C213827066731A23EA978BF2E730C6BF1CBEFA207AC47D2970A462A50C076`, `6,704` bytes, `226` lines. Final time-bounded read: command `000000015548`, SHA256 `63A01073CDDAD8473F2B59302B2723B8ACE860AF9ECFF5CC3406C29B37B543B6`, same metrics and assertions; command/timestamp-header normalization reproduces the command-15530 hash exactly.
- Exact assertions: one `GeneralPurposePanel *g_pGeneralPurposePanel = 0;`; one matching extern; one `class GeneralPurposePanel : public LObject, public Singleton<GeneralPurposePanel>`; one constructor with Singleton initializer and seven allocations; one ordinary destructor with seven deletion requests; one each `GetChildPaneByIndex`, `GetActiveChildPane`, `DispatchActiveChildRefresh`, and `SwitchActiveTab`; zero UID00028X/UID00015Z/UID0004UN/UID0003BC Empty Emitter Markers or ABI bodies; no explicit singleton assignment/clear, vptr, RTTI table, scalar flags, size guard, or storage free.
- Sibling/unrelated assertion: one GeneralPurposePanel2 class and accepted UID00015Y body remain; its two pre-existing sibling empty markers remain unchanged. Verify-only ordinary hashes are UID00005R `8FA99EC4...49DB`, UID0000R1 `CEBEFFC6...2188`, and UID0002VS `450A0D91...B6E7`.
- Formal comparison: all eleven report/destination managed blocks match after CRLF normalization. Exact formal hashes are UID00028X `804ECBCE...C619`, UID0000R0 `80F982EC...2A70`, UID00005Q `648E684C...9EF`, UID0004UL `513DAECB...4B72`, UID0004UM `D3FF1FFD...25D7`, UID00015W `DB0F450C...A99E`, UID00015X `B9D48B97...33FD`, UID00015Z `84854E85...7A25`, UID0004UN `0F56FC86...DB37`, UID0003BC `26AED99B...BB40`, and UID00015V `4FF57E2B...7240`.
- Unresolved callback blockers: none. UID0003A2 notices are pre-existing registry/reference debt outside this callback and do not affect target emission.

## Changed Files

- Created during callback: UID0004UL `by-memory/0x004b83d0-0x004b857e.GeneralPurposePanelConstructor.md` SHA256 `417450B0F19D708A3963051260F52E90CC78B4C7CA3809C5AC563A7615A8CD33`; UID0004UM `by-memory/0x004b8580-0x004b85e3.GeneralPurposePanelDestructor.md` SHA256 `7C53540E825B1FBB2F36388D7BFD00872C446F98B928E41C63330FF55B411DB8`; UID0004UN `by-memory/0x004b8b40-0x004b8bd3.GeneralPurposePanelScalarDeletingDestructor.md` SHA256 `187C6C2CB7E3A1CD9FF9F105CEECFFFF155EDE8CD75E472824A0ABCED683C92D`.
- Modified ordinary: UID00028X `35C7E2F5...AC85`; UID0000R0 `405C7366...D1FC`; UID00005Q `76772982...F997`; UID00015W `81954C4A...8694`; UID00015X `6131E675...DB07`; UID00015Z `5369DA38...5693`; UID0003BC `D16AC9DF...9A56`; UID00015V `4DF544B6...73C3`; UID0000JQ `D9852F32...DE44`.
- Modified report: `tools/leaser/Agents/Agent-B002/research/00028X-g_pGeneralPurposePanel-source-quality.md`; final hash/metrics are computed after the terminal self-check.
- Validator-owned side effects only: scoped commands updated validator registry/reference/stat projections; command 15530 refreshed generated files and command 15532 refreshed tracker during the callback. Later externally owned commands 15548/15549 advanced only the observed volatile generated/tracker headers/union epoch; B002 read them without editing generated/tracker/validator-state files.
- Manual coverage, audit, goal, supervisor, IDA, executed archive, and lifecycle files modified by B002: none.
- Renamed ordinary files: none. New child paths were registered directly with validator-issued UIDs.
- Leases: twelve short ordinary-file leases used serially; every lease released immediately after validation. Final B002 lease count zero.
- Report execution/probe/move/archive: not run. Lifecycle remains external supervisor/validator-owned.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 validated accepted pre-callback SHA `CADF5B96...961C` before implementation.
- [x] Ledger Action values remain limited to `incorporate`, `already-present`, `historicalize`, `reject-stale`, `reject-invalid`, and `not-applicable`.
- [x] Historical report-only Verification states were exactly `proposed`; callback states are now only `applied`, `already-present`, or `excluded-with-reason`.
- [x] Reread UID00028X immediately before callback and preserved unrelated history/detail.
- [x] Applied Destination 1 to UID00028X: `92/94`, owner retained, false, blank emitter/position/formal, exact summary and full evidence.
- [x] Historicalized old `0xffffffff` and raw-label assumptions without deleting provenance.
- [x] Applied Destination 2 to UID0000R0 with position 0 and sole definition.
- [x] Applied Destination 3 to UID00005Q with direct LObject/Singleton bases and one extern.
- [x] Preserved class closure before the extern and `[[CHILDREN]]`.
- [x] Registered UID0004UL serially and replaced its placeholder everywhere.
- [x] Applied Destination 4 constructor and exact report-level evidence.
- [x] Registered UID0004UM serially and replaced its placeholder everywhere.
- [x] Applied Destination 5 ordinary destructor and exact report-level evidence.
- [x] Preserved exact no-null-check destructor behavior.
- [x] Applied Destination 6 UID00015W score/position/summary while preserving exact body/current detail.
- [x] Applied Destination 7 UID00015X position/summary while preserving exact body/current detail.
- [x] Applied Destination 8 UID00015Z score/no-code/compiler proof.
- [x] Registered UID0004UN serially and replaced its placeholder everywhere.
- [x] Applied Destination 9 scalar false/no-code proof.
- [x] Applied Destination 10 UID0003BC false/no-code RTTI/vtable proof.
- [x] Applied Destination 11 UID00015V real-child/source/compiler/padding inventory without monolithic emission.
- [x] Applied Destination 12 UID0000JQ prose/score only; no by-file reconstruction metadata exists.
- [x] Preserved UID00015W/UID00015X source bodies byte-for-byte.
- [x] Preserved full seven-child index map and active-index semantics.
- [x] Preserved complete 87-ref inventory and five-write/82-read proof.
- [x] Preserved exact ranges/hashes/padding and adjacent UID boundaries.
- [x] Preserved RTTI/PMD/EBO/allocation-size evidence.
- [x] Preserved source-versus-compiler lifetime distinctions.
- [x] Preserved negative evidence and rejected ownership/linkage/source alternatives.
- [x] Verified UID00005R/UID0000R1/UID0002VS read-only at accepted hashes; no sibling repair claimed.
- [x] Verified FrameChrome/AboveFrame and consumer support ownership remains unchanged.
- [x] Confirmed no third-party import directive applies.
- [x] Confirmed exactly one typed definition and no duplicate physical/template static definition is emitted.
- [x] Reread current B001-B005 goals and leases; current work is unrelated and no destination collision exists.
- [x] Used only one ordinary-file lease immediately around each edit/scoped validator.
- [x] Released every lease immediately after validation.
- [x] Recorded every validator command ID, timestamp, exit/ok, warning, and side effect.
- [x] Ran final authorized waited GeneralPurposePanel refresh command `000000015530` after all leases cleared.
- [x] Verified one complete direct-Singleton GeneralPurposePanel class.
- [x] Verified exactly one external declaration and one global definition.
- [x] Verified one constructor with Singleton initializer and zero explicit global assignments.
- [x] Verified one ordinary destructor with seven deletion requests and zero explicit clears/base teardown.
- [x] Verified exact accessor/switch definition counts and order.
- [x] Verified zero primary target/helper/scalar/vtable Empty Emitter Markers or ABI bodies.
- [x] Verified no handwritten vptr, RTTI, scalar flags, size guard, or storage free.
- [x] Verified GeneralPurposePanel2 and unrelated source union remain present without loss.
- [x] Reread tracker/manual coverage at final reconciliation without manual edits; recorded time-bounded tracker command 15549 and the then-current four manual hashes while preserving all twelve exact actions.
- [x] Rebased twelve exact supervisor-owned manual actions over current rows/hashes.
- [x] Terminalized C01-C30 from destination/validator/generated proof using legal callback states.
- [x] Updated Validator Results, Changed Files, current state, hashes, real UIDs, and checklist.
- [x] Confirmed zero prohibited manual generated/coverage/tracker/audit/supervisor/validator-state/IDA/lifecycle edits.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation at exact pre-callback SHA.
- [x] All accepted target/support facts incorporated without compression.
- [x] All eleven managed blocks are byte-equal to exact destination text after real-UID replacement.
- [x] All three new child UIDs/paths are registered and propagated.
- [x] All C01-C30 claims are terminal with legal verification states and separate proof.
- [x] Every scoped validator passed and every lease is released.
- [x] Final waited generated assertions passed on independent readback.
- [x] Exact manual supervisor-owned coverage handoff is rebased without editing coverage.
- [x] Remaining unapplied accepted implementation items: none; manual coverage and lifecycle remain external supervisor work, not callback blockers.
- [x] Same report is reconciled to archive-neutral callback truth for independent Gate 2.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000015555","destination_path":"executed-b-agent-research/B002/00028X-g_pGeneralPurposePanel-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00028X-g_pGeneralPurposePanel-source-quality.md","timestamp":"2026-07-21T07:57:00-04:00","uid":"00028X"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
