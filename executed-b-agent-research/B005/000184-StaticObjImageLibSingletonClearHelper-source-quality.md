# UID000184 StaticObjImageLib Singleton Base Destructor Source Quality
** TARGET-REPORT-UID:000184 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


Removed legacy request material: [000184-StaticObjImageLibSingletonClearHelper-source-quality-removed.md](000184-StaticObjImageLibSingletonClearHelper-source-quality-removed.md). The companion is non-authoritative and must never be executed.

## Finalized Report / Current Recommendation

- Current recommendation: reclassify the retained function at `0x004e5c00-0x004e5c0b` as the compiler-emitted out-of-line destructor instantiation for the direct empty base `Singleton<StaticObjImageLib>`, not as a source-authored clear helper or static-registration callback.
- Final disposition: rename the documentation identity to `StaticObjImageLibSingletonBaseDestructor`, attach semantic ownership to class [UID:0000E2], set `RECONSTRUCTABLE:FALSE`, clear all emitter routing, and leave both formal CPP and H channels empty. The source cause is the class inheritance declaration and its implicit reverse-order base destruction.
- Required action: preserve the corrected source-bearing support payload: the complete class declaration remains in H with direct bases `LObject` and `Singleton<StaticObjImageLib>`, class CPP includes its own header plus shared ImageFrameTable, MemoryMan, and CRT dependencies before `[[CHILDREN]]`, and the authored destructor uses `MemoryMan::FreeBufferMemory`, preserves the measured second manager acquisition and unconditional catalog dereference, and omits an explicit `g_pStaticObjImageLib = 0;` statement. The scalar deleting wrapper and physical singleton slot remain non-emitting, and the affected ordinary pages preserve the exact RTTI, EH, range, lifecycle, and rejected-static-registration evidence.
- Confidence: near-certain for binary behavior, range, liveness, direct base identity, EH-only retained-body route, compiler-generated disposition, and source cause. Human-facing names are evidence-backed project names rather than recovered debug symbols, but no raw IDA name belongs in final source.

## Supporting Research

- Project purpose: this report supports local preservation and faithful reconstruction of the unsupported NexusTK client. Runtime behavior must remain exact while emitted source must resemble plausible human-written late-1990s or mid-2000s C++, not IDA output.
- The historical pre-callback target page correctly recorded the exact eleven-byte body and its sole constructor-unwind xref, but its phrase `constructor/static cleanup glue`, by-file ownership, reconstructable emitter route, and emitted proof comment stopped before identifying the actual C++ mechanism. The post-callback page now records the resolved compiler role.
- The target belongs to a contiguous island of eleven-byte zero-store/return functions separated by five `0xcc` bytes. Sibling pages already establish the same direct-Singleton-base-destructor pattern for MapTileImageLib, ItemObjImageLib, LightObjImageLib, and other image libraries.
- StaticObjImageLib RTTI independently identifies `Singleton<StaticObjImageLib>` as a direct base with PMD `+4,-1,0` and attribute `0x40`. Its empty-base subobject overlaps the first derived member at offset `+0x04`; it is not an authored field.
- Constructor EH state 1 loads the complete object, adds four to ECX, and tail-jumps to `0x004e5c00`. State 0 instead tail-jumps to `LObject::~LObject`. That exact split is the compiler's reverse cleanup for two direct bases.
- Ordinary and scalar destruction each clear `0x0069b448` immediately before `LObject` teardown. Those inlined copies are the reverse-order `Singleton<StaticObjImageLib>` base destructor, not statements that should remain in `StaticObjImageLib::~StaticObjImageLib()`.
- Application startup explicitly allocates and constructs the object, and Application shutdown explicitly scalar-deletes the global object. No `atexit`, `_onexit`, static-object registration, direct helper call, function-pointer reference, VA pointer, RVA pointer, or raw-file-offset pointer route supports a separate static callback.
- Named MCP sessions are dated read-only evidence, not lifecycle or application authority. The superseded `supervisor-uid0002OW-gate2b-20260813T0115Z` baseline remains history. Fresh bounded queries against runtime-attested canonical-path session `supervisor-uid0004HB-gate2b-20260813T1105Z` now establish every literal actionable and protected prestate in Section 21. Gate 2B must reattest and recheck those already-recorded literals against its selected current canonical worker; it must stop on drift rather than perform first-time discovery.
- Fresh bounded 2026-08-12 and 2026-08-13 research detected and resolved successive IDB-revision hazards without B005 mutation. Earlier canonical revisions SHA256 `1B8E6E1B96FD984BCF06236B3500CB11C132B2F89F9866CE808EBF5437D60D78`, `143,206,508` bytes, SHA256 `A95C3CF171A95F77AF9BBFF9247E81C53E7816059D203320E83E7B369ACD36F1`, `143,206,680` bytes, SHA256 `20DEC2DEDAFC51662CBFCA3E3A96CBC8A0AB165AF348C11566ED66CBF70E62F2`, `143,206,743` bytes, and SHA256 `B8C1ABC6A9FBCBE1B2021BC72AC15AD7EAAD0EF3DD82443ADEFCFC0ADE0151F9`, `143,206,895` bytes, plus their named workers, remain historical evidence only. The fresh current canonical disk snapshot is SHA256 `53B60FCF7C42327C9E03D90A407903D4EFF15510FEE791F2452EF0B2036A05D9`, `143,206,875` bytes, mtime `2026-08-13T07:09:07.5603942-04:00`. Public runtime attestation at `2026-08-13T11:38:46.695504+00:00` returned `schema_version:1`, `ok:true`, no errors, and the exact canonical path for session `supervisor-uid0004HB-gate2b-20260813T1105Z`; health was `status:ok`, Hex-Rays ready. Fresh read-only function, frame, comment, type, item, byte, integer, name, xref, and protected-entity queries produced the complete literal baseline in Section 21. No mutation or save occurred.
- Dated 2026-08-12 supervisor Gate 2B negative/tool-behavior evidence: on a fresh attested canonical worker, the exact accepted `make_data` request for `0x0069b448` returned `ok:true`, `size:4`, and `name:g_pStaticObjImageLib`, but returned `type:""`; immediate `inspect_items` confirmed one four-byte data item with a blank type. A diagnostic `set_type` operation with `kind:"global"` and `ty:"StaticObjImageLib *"` then attached the intended pointer type in that unsaved worker. Because the then-current report prohibited this necessary second operation, the supervisor stopped, saved nothing, discarded the whole unsaved worker/redirector, and reopened the canonical disk. At that dated A95C revision, readback restored four raw one-byte target items displayed through generated label `unk_69B448`, blank type/comments, and the then-observed neighboring state. The current canonical revision instead has no stored target name while IDA may generate `unk_69B448` for presentation, and it explicitly names the protected neighbors `g_pRidingImageLib` and `g_pEffectObjImageLib`. This trial receives no implementation credit; it proves the endpoint's required serial shape/name-then-type behavior now specified in Section 21.
- Dated 2026-08-12 UDT failure/compatibility evidence: fresh attested canonical session `supervisor-uid000184-gate2b-retry2-20260812` accepted the exact human-spelled `TileClassEntry` declaration, but canonical `type_inspect` rendered its members as `unsigned __int16`, `unsigned __int8`, and `unsigned __int8`. The then-current report incorrectly demanded literal `unsigned short`/`unsigned char` readback and therefore stopped before any later action. The unsaved canonical worker was discarded; canonical disk remained SHA256 `A95C3CF171A95F77AF9BBFF9247E81C53E7816059D203320E83E7B369ACD36F1`, `143,206,680` bytes. In a separate isolated unsaved scratch copy, `#pragma pack(push, 2)` failed because the parser split at its comma; the exact comma-free sequence `#pragma pack(push)`, `#pragma pack(2)`, declaration, `#pragma pack(pop)` succeeded. Scratch readback proved `StaticObjEntry` size `14` with canonical unsigned aliases at the same six offsets, then proved `StaticObjImageLib` size `20` with the existing five names/offsets/types. The scratch worker was discarded unsaved. These trials receive no implementation credit and distinguish human source spellings from deterministic IDA canonical readback spellings.

## Target

- Target UID: `000184`.
- Additional target UIDs, or `none`: none. Every other UID in this report is support scope and receives no independent research-tracker coverage claim.
- Declared-target inventory with path and role: [UID:000184] `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md`, the retained eleven-byte compiler-emitted direct-`Singleton<StaticObjImageLib>` base-destructor instantiation.
- Current target path: `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md`.
- Historical pre-callback target path: `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md`.
- Dated tracker state observed during the 2026-08-11 repair preflight: `auto-generated/-ag-research-tracker.md` listed UID000184 at `94/97`, average `95.5`, `RECONSTRUCTABLE:FALSE`, with the renamed base-destructor path; the historical assignment came from the by-memory not-covered reconstructable queue at `86/91`.
- Current supervisor classification: non-reconstructable source-declared/generated-binary support semantically owned by class [UID:0000E2], with no independent CPP or H emitter.
- Historical pre-callback classification: reconstructable file-owned cleanup helper with a no-code proof comment.
- Current scores and parent state: target `94/97`, semantic owner [UID:0000E2], `RECONSTRUCTABLE:FALSE`, blank emitters and emitter position, and `Nested:0`.

## Current Target State

- Exact post-callback target metadata is `COMPLETION:94`, `CONFIDENCE:97`, `CANONICAL_OWNER:0000E2`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`; both formal CPP and H are blank.
- Historical pre-callback metadata was `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000O7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O7`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`. Its CPP channel contained the obsolete four-line cleanup-glue proof comment and H was blank.
- The post-callback page now identifies the body as compiler-emitted direct-base destruction and records the exact bytes `c7 05 48 b4 69 00 00 00 00 00 c3`, sole EH xref at `0x005fff9d`, thirteen singleton-slot xrefs, and five-byte successor padding.
- At the 2026-08-12 report-text preflight, all twelve original ordinary callback destinations still preserved the accepted UID000184 behavior, hierarchy, metadata, and historical corrections. Eleven matched their B005 command `000000022285` through `000000022296` receipt hashes exactly, while UID0000E2 retained B003's later valid owning-header addition under command `000000022436`. That preflight identified the source-shape defect that the historical receipts had not resolved. Under the explicit C184-029 callback, B005 corrected the five source-bearing ordinary destinations and validated them without generated refresh: UID00017I SHA256 `43A52B6531B4B2A43907F3AD6911789AEB83BE4AC0E77FEE1E2C4D9719B42401`, UID0000E2 `C28BC94256BD6FD1F826E5A856790508A0FFD2DF510A40B8F504F19AA098117E`, UID0000O7 `9B8981EEB3E289F75D8C786F972997EEAB7ED45A7A7365B3E856B1F8B5797616`, UID0000UN `13024109D4A62F850BB9062F894A73A2168115F785239B03C53D54D776A2FC92`, and UID0000K1 `87F18FEA2BE6CA02EE734242BF11D6E50A716F3B0C5FB98659B7C9A7D5AD7E7F`. The ordinary source documents now use the accepted `MemoryMan::FreeBufferMemory` API, expose the complete archive declarations through shared ImageFrameTable H, preserve both manager acquisitions and the unconditional catalog dereference/free order, and route all required includes before child definitions. Independent Gate 2A acceptance remains supervisor-authoritative outside this report.
- Historical generated command `000000021890` emitted the obsolete four-line UID000184 marker, placed the class declaration in CPP, omitted the sibling header, and omitted the authored destructor child.
- Historical generated command `000000022403` at `2026-08-11T19:07:10-04:00` contained the direct-base declaration and no UID000184 marker but predated the owning-header correction. Historical command `000000022520` at `2026-08-12T03:08:58-04:00` added the owning header and target exclusion but still reproduced the UID00017I API/type/null-guard defects and dereferenced an incomplete `ArchiveMetadataTable`. Commands `000000022761`/`000000022762`, generated commands `000000022770`/`000000022920`/`000000022981`/`000000023008`, and tracker commands `000000022775`/`000000022785`/`000000022982`/`000000022990`/`000000023015` are explicitly historical snapshots at their previously recorded identities. A dated physical reread after generated command `000000023042` (`2026-08-13T01:06:08-04:00`) found `StaticObjImageLib.cpp` SHA256 `1AC04D0EBB9BCF45F053B841B9BAB23354F0D12CBE03281EB4B91A23A1D51335`, 5,719 bytes, 172 lines; `StaticObjImageLib.h` SHA256 `D00B3902A83DA2F6D4108EB9F2DAC3B2E13A1C3204B5740FFE90AF49340BB1C3`, 2,034 bytes, 66 lines; and `ImageFrameTable.h` SHA256 `78CEC2CCA386C0D52AD4D69936F1003F9D83D7E1D106DDADD35FC61A208F8D44`, 1,024 bytes, 40 lines. A separate dated tracker reread after command `000000023045` (`2026-08-13T01:12:15-04:00`) found SHA256 `6794C5420667408D376DD55098F05BD3649191D62F18D4C567F2D4613953DFFC`, 1,721,219 bytes, 6,765 lines, with UID000184 at line 5682 and unchanged `94/97`, average `95.5`, `RECONSTRUCTABLE:FALSE`, non-emitting semantics. Commands 23042/23045 are dated validator-owned snapshots only, transfer no B005 or supervisor implementation credit, and must never be treated as later-gate currentness; each later gate dynamically rereads the physical files. Physical source/header semantics at the dated snapshot remain the accepted four required includes, direct-base H, exact `MemoryMan::FreeBufferMemory` destructor with two manager acquisitions and unconditional catalog dereference/free order, complete shared `ArchiveMetadataTable`, and no UID000184 emission marker. C184-022 remains an unchecked supervisor acceptance boundary.
- At the dated 2026-08-11 repair preflight, manual coverage was stale: UID000184 said `85%` and reconstructable static cleanup; related class/file/global/struct/vtable rows retained older scores/descriptions, the local-cluster row retained the obsolete broad range, UID0003M2 was absent, and singleton storage said `0xffffffff`. Section 28 preserves the exact supervisor-owned replacement/insertion payload independent of later application state.
- Dated Gate 2B trial status: the 2026-08-12 singleton-slot `make_data` call demonstrated that this MCP endpoint shapes and names the four-byte item but does not retain the supplied declaration as its type. The follow-up global `set_type` diagnostic succeeded only in the unsaved worker. No mutation was saved, the entire worker was discarded, and a fresh canonical reopen proved the A95C disk prestate fully restored. Section 21 now treats blank type as the exact accepted intermediate state and requires a separate global `set_type` before the comment step and before any save eligibility.
- Dated UDT trial status: canonical retry2 stopped after the successful TileClassEntry declaration because the report rejected IDA's equivalent canonical aliases. The worker was discarded unsaved. Isolated scratch testing then established the exact parser-safe StaticObjEntry payload and exact canonical readbacks for all three UDTs; that scratch worker was also discarded unsaved. The older 1,016-entry catalog baseline is superseded. Fresh current canonical-session `type_inspect` proves all three proposed UDTs absent and proves `LObject`, `ArchiveMetadataTable`, and `MemoryMan` remain opaque incomplete declarations, while `type_query` records catalog total 1,020. The four current additions are ordinal 1017 `jpeg_common_struct` opaque, 1018 `jpeg_error_mgr` opaque, 1019 `j_common_ptr` four-byte typedef, and 1020 `TextMenuDialog` opaque. Section 21 accepts only the explicitly enumerated source-to-IDA alias pairs while preserving every current name, ordinal, offset, size, pointer type, packing result, catalog entry, and no-save rollback gate. Gate 2B must reproduce these literals before declaration; it does not discover them for the first time.
- Dated protected-CHD preflight status: historical canonical session `supervisor-uid000184-gate2b-20260812T2054Z` stopped before mutation because Section 21 then carried stale values `0,0,3,0x00648d78`; exact reads proved `0,1,3,0x00648d78`. Fresh 2026-08-13 canonical-session reads again prove values `0,1,3,0x00648d78` and bytes `00 00 00 00 01 00 00 00 03 00 00 00 78 8d 64 00`. The second dword is CHD attributes `1`, the expected multiple-inheritance descriptor state for the documented `LObject` plus direct `Singleton<StaticObjImageLib>` hierarchy. No B005 mutation or save occurred; the stale zero receives no authority, and Gate 2B rechecks this literal before mutation.
- Report execution/archive truth is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata. This body does not hard-code or predict current lifecycle location or execution state.

## Executive Recommendation

1. Preserve the exact target range and UID while changing the human identity from `SingletonClearHelper` to `SingletonBaseDestructor`.
2. Set target metadata to `94/97`, class owner [UID:0000E2], `RECONSTRUCTABLE:FALSE`, blank emitter fields, and blank formal CPP/H.
3. Put the source cause in [UID:0000E2] H as `class StaticObjImageLib : public LObject, public Singleton<StaticObjImageLib>`; make class CPP include `StaticObjImageLib.h`, `ImageFrameTable.h`, `../util/MemoryMan.h`, and `<stdlib.h>` before `[[CHILDREN]]`.
4. Keep `StaticObjImageLib::~StaticObjImageLib()` source-authored with exact `MemoryMan::FreeBufferMemory` calls, both observed manager acquisitions, and measured unsafe catalog dereference/free order, but remove its explicit singleton clear because reverse base destruction supplies it.
5. Keep [UID:0003M2] as non-emitting scalar-deleting compiler support and keep [UID:0001PP] as non-emitting physical storage support.
6. Keep one zero definition of `g_pStaticObjImageLib` through [UID:0000SD] and one header declaration through the complete class H payload.
7. Apply the exact IDA handoff only during supervisor Gate 2B after dynamic canonical-IDB attestation and literal pre-state reread.

## Supervisor Active Recheck

- Triggering instruction: the direct supervisor assigned a pre-Gate-1, same-report, additive self-audit of existing UID000184 against the current literal 33-section template, validation preflight, Rule 26 no-loss standard, and B005 goal; this self-audit does not claim authoritative Gate 1.
- Exact rule provenance physically read for this repair: project skill `SKILL.md` SHA256 `8713A2ED7D9DA8CB40B2F03421ABF867072A3F3B40516D58330B6468152BA97E`; literal template SHA256 `9CAA380FC5DCA50EC1E60A92E1EA0F98D52D4C27E82EE0F5FB0DC4B0D81967ED`; B-agent workflow SHA256 `9ACFD9D24D43E144F5DE4A525CC0613EF47A274E89CD6E558FBC996E9CB9A4DF`; supervisor Rule 26 standard SHA256 `52445589A48DB02091BE1AEA050D917F8071BF141A1357C94A02C85CD55935F4`; supervisor preflight SHA256 `06CBCE752593D115F3D514608C0C67B69535D3E949B069E9B590C227D30959A5`; and B005 goal SHA256 `D66CE724406AD52E7C301D3EFA142C33B5D9C51B04180073E6A7442014CE0C5B`.
- Exact repair-input artifact recheck: SHA256 `BFB3FE0CED4378190D6029B568DAC193781EFE77BAFBC739B30C4485B0C43DA0`, `97,847` bytes, `683` LF-only physical lines, 33 literal H2 headings in template order, four balanced `cpp` blocks, and zero executable-language fences. The pre-repair artifact had 28/28 ledger/checklist parity but obsolete Actor-bearing 9/10-field schemas and one noncanonical readiness marker; this repair converts them to canonical Actor-free 8/9-field schemas and the sole allowed marker without changing claims or allocation.
- Historical continuation input: SHA256 `6518D61C9A43903AA6AB592D84CFF24A75A2029DABA079A892B80CACDE1CE9A7`, `112,633` bytes, `761` physical lines, 33/33 literal H2 headings, 28/28 canonical ledger/checklist parity, 15 checked and 13 unchecked claims, one terminal readiness marker, and zero executable-language fences. A superseded intermediate repair incorrectly converted the 13 supervisor-owned rows to checked `handoff`/`excluded-with-reason`; the current repair restores canonical `incorporate`/`proposed` unchecked states and preserves that mistake only as history.
- Dated ordinary callback destination recheck: on 2026-08-11 all twelve target/support documents existed with the accepted post-callback metadata/formal dispositions. Eleven exactly matched B005 commands `000000022285` through `000000022296`; UID0000E2 matched later additive owning-header remediation command `000000022436`, SHA256 `0D036C1E88AE932A925475BF02B9F40E798AB89DEBB13CD03490DEABB8A03D14`, while preserving all B005 hierarchy/H/score content. Those immutable receipts support supervisor Gate 2A without encoding its current result.
- Dated generated-output recheck: command `000000022403` supplied the direct-base H and no UID000184 emission but predated UID0000E2 command `000000022436`; command `000000022520` supplied the owning-header include and exclusion while retaining the now-historical C184-029 defects. All later command identities through generated 23008 and tracker 23015 are historical snapshots. The exact physical rereads after generated command `000000023042` (`2026-08-13T01:06:08-04:00`) found hashes `1AC04D0EBB9BCF45F053B841B9BAB23354F0D12CBE03281EB4B91A23A1D51335`, `D00B3902A83DA2F6D4108EB9F2DAC3B2E13A1C3204B5740FFE90AF49340BB1C3`, and `78CEC2CCA386C0D52AD4D69936F1003F9D83D7E1D106DDADD35FC61A208F8D44` for StaticObjImageLib.cpp, StaticObjImageLib.h, and ImageFrameTable.h. The dated tracker reread after command `000000023045` (`2026-08-13T01:12:15-04:00`) found SHA256 `6794C5420667408D376DD55098F05BD3649191D62F18D4C567F2D4613953DFFC`, 1,721,219 bytes, 6,765 lines, and unchanged UID000184 semantics at line 5682. These are snapshots only; C184-022 requires each later gate to reread the physical files dynamically and transfers no implementation credit.
- Dated manual-coverage recheck: on 2026-08-11 every row named by C184-015 through C184-021 was absent or stale exactly as described in Section 28, including the absent UID0003M2 insertion. No coverage file was edited by B005, and the exact handoff text remains valid regardless of later supervisor application.
- IDA recheck history and authority boundary: earlier A95C, 20DEC2DE, B8C1, and `supervisor-uid0002OW-gate2b-20260813T0115Z` states remain historical evidence. Public runtime attestation at `2026-08-13T11:38:46.695504+00:00` succeeded with `schema_version:1`, `ok:true`, and no errors for current canonical-path session `supervisor-uid0004HB-gate2b-20260813T1105Z`. Fresh bounded read-only queries on that exact session supplied the complete current preparation baseline now written literally in Section 21: all four actionable functions, frames, comments, xrefs, proposed-name collision state, six type prestates, 1,020-entry catalog with four identified additions, blank stored target name with generated-only `unk_69B448`, explicit protected neighboring names, and every RTTI/vtable protection row. No IDA mutation or save is credited to B005.
- Dated failed-closed Gate 2B trial: the supervisor's exact `make_data` call shaped/named the slot but returned and read back a blank type; a separate global `set_type` attached `StaticObjImageLib *` only in the unsaved diagnostic worker. The obsolete one-call-only rule forced the correct no-save stop. The worker/redirector was discarded and fresh canonical readback proved exact rollback. This same-report repair gives no mutation credit and changes only the deterministic handoff: `make_data`, exact blank-type intermediate readback, global `set_type`, exact typed readback, repeatable comment, then final full/protected readback.
- Dated failed-closed UDT trial and scratch proof: canonical retry2 accepted TileClassEntry and returned exact layout with IDA canonical unsigned aliases, then stopped on the report's obsolete literal-spelling condition and was discarded unsaved. A separate unsaved scratch copy proved that the comma-bearing pack pragma is not parseable by this endpoint, the two-line comma-free pack sequence is parseable, StaticObjEntry reads back as exact size 14, and the following StaticObjImageLib declaration reads back as exact size 20. No canonical or scratch save occurred. The repaired handoff treats human declaration spelling and canonical analysis spelling as equivalent only for the exact listed unsigned aliases; every structural difference remains fatal.
- Split/source-bearing closure: UID000184 already has the exact byte range and requires no split. Every source-bearing item directly affected by its source cause or the resolved destructor dependency defect has an explicit formal CPP/H or no-code disposition: UID0000E2, UID00017I, UID0000SD, UID0000UN, UID0000K1, and the non-emitting UID000184/UID0003M2/UID0001PP/UID0001YX support rows. The constructor is completely contained by UID00017H at `0x004dcf60-0x004dd1d8`, class-owned through UID0000E2, and independently inventoried with exact EH states; no constructor split is required to classify, route, or complete UID000184.
- Lease/lifecycle recheck: no pre-existing lease for this report or UID000184 target appeared in `current_leases.md`; B005 used only short report leases for additive report writes and released each after the corresponding write. No lifecycle header/footer was added and execution/archive authority remains validator/supervisor-owned.

## Inference Research Guidance Check

- Raw labels were not accepted as source names. The proposed names describe the direct source semantics and match established project naming.
- Absence of an ordinary caller was not treated as absence of liveness. The sole constructor EH jump is a real compiler route.
- The trivial body was not treated as sufficient no-code proof. RTTI hierarchy, PMD, EBO, EH state transitions, ordinary/scalar inlining, startup/shutdown, pointer searches, and sibling compiler patterns were all reconciled.
- No unresolved item was deferred merely because it requires inference. The highest-probability historical source form is explicit and implementation-ready.
- Stale Wave2/Wave3 material was ignored. Current ordinary docs, generated readback, archived matching reports, and live IDA MCP evidence control.
- Current `by-structure.md` discipline controls the source route: an exact by-memory range may document a retained compiler body without emitting an aggregate helper, while the human source cause is emitted only through the owning class, authored method, global, and shared-type formal channels. This prevents duplicate code and range expansion.
- Execution equivalence outranks naming consistency; human source shape outranks retaining decompiler spelling; project-wide style consistency is applied after those two requirements.

## Heuristic / Inference Reanalysis And Validation

### Ranked hypotheses

1. Direct `Singleton<StaticObjImageLib>` base destructor instantiation: probability greater than 0.99. It explains the RTTI direct base, PMD `+4`, constructor `this+4` cleanup receiver, exact global clear, ordinary/scalar inlining before LObject teardown, sibling helper island, and absence of authored call routes.
2. Source-authored file-local clear helper: probability below 0.01. It does not explain the adjusted receiver, direct-base RTTI, compiler EH state ordering, or inlined reverse base destruction.
3. Static object or `atexit` callback: rejected. No registration/import/pointer route exists; startup and shutdown explicitly own construction and deletion.
4. Global initializer: rejected. The target is referenced from constructor EH state 1 and accepts an implicit ECX base receiver even though its body does not read it.

### Source-form validation

- The probable historical declaration is multiple inheritance, not an explicit clear function.
- The probable authored destructor contains derived resource cleanup only. The compiler then invokes `Singleton<StaticObjImageLib>::~Singleton` and `LObject::~LObject` in reverse base order.
- The constructor may omit an explicit `Singleton<StaticObjImageLib>()` initializer because the compiler invokes the default base constructor automatically. The binary still proves that the direct base publishes the complete-object pointer and has an EH cleanup state.
- The current global name `g_pStaticObjImageLib` is retained as the project-wide source-facing name. No final source should contain `unk_69B448`, `dword_69B448`, `sub_4E5C00`, or an invented public `ClearStaticObjImageLibSingleton`.

## Evidence Standards Used

- Direct IDA fact: live function identity, disassembly, stack frame, xrefs, bytes, names, comments, data state, vtable words, RTTI bytes, and bounded entity searches.
- Direct binary inference: MSVC RTTI hierarchy and PMD decoding, EH cleanup order, empty-base overlap, deleting-wrapper parity, and sibling code-generation pattern.
- Documentation evidence: current target/support pages, exact generated CPP readback, current manual coverage rows, and archived matching B reports.
- Negative evidence: no ordinary target caller, no callee, no target VA/RVA/raw-offset pointer hit, no `atexit` or `_onexit` import route, no name collision, no independent source API surface.
- Historical evidence is labeled historical; Section 21 defines the invariant supervisor Gate 2B requirement to refresh literal prestates before mutation.
- Failed-closed tool behavior is evidence, not implementation credit: the dated unsaved singleton-slot trial established the exact endpoint split between `make_data` shape/name and `set_type(kind:"global")` typing, and the canonical reopen established rollback integrity.
- Binary context and storage role strengthen the conclusion: executable EH-only code, zero-initialized singleton storage, RTTI/vtable data, and alignment bytes are treated according to their section roles rather than as interchangeable source. Tool limits affect only proof of original private spelling, not behavior, range, ownership, or source shape.

## Evidence Checked

- Target and support pages: [UID:000184], [UID:0000E2], [UID:0000O7], [UID:00017H], [UID:00017I], [UID:0003M2], [UID:0000SD], [UID:0001PP], [UID:0001W8], [UID:0001W9], [UID:0001WC], and [UID:0001YX] were physically reread during this repair. The current resumption rehashed all fourteen ordinary destinations in Section 32: every SHA256, byte count, and line count still matches its recorded callback identity, including the five C184-029 destinations. Exact vtable-data child [UID:0002OY] remains compiler-data support rather than an additional report target.
- Lifecycle consumers: Application startup [UID:0002H7] still provides explicit allocation/construction and shutdown [UID:0002H8] still provides explicit scalar deletion. The documented map/static-object, ObjectList, StaticObjectPane, and PhotoPane reads remain among the thirteen global-slot references; none provides a registration callback or source-authored call to UID000184.
- Generated state history: command `000000021890` demonstrated the missing-H, misplaced-class, missing-destructor, and UID000184-marker baseline. Command `000000022403` supplied the direct-base declaration and no UID000184 marker but predated UID0000E2 command `000000022436`; command `000000022520` retained the C184-029 defects. Commands through generated 23008 and tracker 23015 are superseded dated snapshots. The dated 2026-08-13 physical rereads after generated 23042 and tracker 23045 found the exact hashes/sizes/lines recorded in Sections 4, 31, and C184-022 and preserved UID000184 at `94/97`, average `95.5`, false reconstructability, and non-emitting status at tracker line 5682. Neither snapshot is later-gate currentness or implementation credit; C184-022 preserves supervisor-only dynamic reread authority.
- Manual-report history: at the 2026-08-11 B005 readback, by-memory had stale UID000184/00017H/00017I/0001PP rows and no UID0003M2 row; by-class UID0000E2, by-file UID0000O7, by-global UID0000SD, by-struct UIDs 0001W8/0001W9/0001WC, and by-vtable UID0001YX had older scores/descriptions. Section 28 is the stable exact supervisor-owned replacement/insertion handoff and does not assert later row state.
- Matching reports: B002 UID000180 establishes the sibling Singleton-base code-generation pattern; B003 supplies the current `StaticObjEntry::lightImageIndex` cross-consumer evidence; B010 supplies the StaticObjImageLib empty-emitter family audit. None supplies an authored UID000184 call route or contradicts the direct-base disposition.
- Historical MCP results: earlier sessions established the original facts, displayed generated label `unk_69B448`, the superseded 1,016-entry catalog, and the corrected CHD attributes value `1`. Fresh 2026-08-13 read-only queries against runtime-attested current canonical-path session `supervisor-uid0004HB-gate2b-20260813T1105Z` independently reproduced all current Section 21 literals: target/predecessor/successor items and 13/20/12 xrefs; blank stored target name with generated-only `unk_69B448`; explicit neighboring names `g_pRidingImageLib` and `g_pEffectObjImageLib`; all four function rows and complete frames; absent proposed UDTs plus opaque dependencies; catalog total 1,020 with identified ordinals 1017-1020; zero proposed-name collisions; and every protected RTTI/vtable value/comment/item/xref row including 481 inbound data xrefs to the shared LObject BCD. No mutation/save occurred.
- Gate 2B tool-behavior trial: the exact current structured `make_data` request produced `ok:true`, size four, exact requested name, blank returned type, and an immediate four-byte blank-type item. The supervisor's separate `set_type` diagnostic with `kind:"global"`, `ty:"StaticObjImageLib *"` succeeded in the unsaved worker, but the obsolete report contract barred continuation. No save occurred; the worker/redirector was discarded; canonical SHA stayed A95C; and a fresh canonical reopen restored all target and adjacent prestates. Section 21 incorporates this exact negative/result evidence without claiming action completion.
- UDT parser/readback trials: canonical retry2 returned TileClassEntry size 4 with `tileFrameId +0x0 size2 unsigned __int16`, `allowPaletteFilter +0x2 size1 unsigned __int8`, and `reserved +0x3 size1 unsigned __int8`. Isolated scratch rejected the comma-bearing pack pragma, accepted the exact two-line pack push/value sequence, returned StaticObjEntry size 14 with `int`, two `unsigned __int8`, `unsigned __int16`, `StaticObjEntry *`, and `unsigned __int16[1]` at the documented offsets, and then returned StaticObjImageLib size 20 with the five existing field types. Both workers were discarded unsaved; canonical disk identity remained A95C/143,206,680 bytes.
- Dated shared-field recheck on 2026-08-11: read-only decompilation from the then-active canonical snapshot session `supervisor-b007-uid0002YJ-rollback-fresh-20260811` showed UID00023D obtaining a `StaticObjEntry` through `sub_4DDA30`, treating the signed dword at `+0x00` as a negative no-light sentinel, passing that same dword unchanged to `LightingObjectPane_SetLightImageIndex` at `0x00530dbe`, and passing it unchanged as the `0x0053c5e0` constructor's final argument at `0x00530e7e`. The setter compared and wrote `LightingObjectPane::m_lightImageIndex`; the constructor stored its final argument at `+0x128`. This direct cross-consumer chain selects `lightImageIndex` as the highest-probability shared source name and rejects `lightIntensity` except as historical terminology. The session identifier is historical evidence only; Section 21 defines the invariant supervisor Gate 2B rediscovery/attestation and prestate-reread boundary.
- Current B005 repair boundary: B005 performed no IDA query, mutation, or save and ran no validator, generated refresh, lifecycle command, target/support mutation, coverage edit, tracker/registry edit, or audit-ledger edit. The supervisor's separately supplied failed-closed canonical and isolated-scratch mutation evidence is recorded explicitly above; both workers were discarded unsaved and receive no implementation credit. Section 21 requires a fresh supervisor-owned canonical-path attestation and complete literal prestate reread before any retry.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C184-001 | 000184 | Rename identity to StaticObjImageLibSingletonBaseDestructor; change historical pre-callback 86/91, owner/emitter 0000O7, true, blank position, Nested 0, nonblank CPP proof comment/blank H to final 94/97, owner 0000E2, false, blank emitters/position, preserved Nested 0, and blank CPP/H | near-certain | Exact bytes, sole this+4 EH jump, direct Singleton RTTI, inlined ordinary/scalar copies | by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md metadata and formal channels | incorporate | applied |
| C184-002 | 000184 | Incorporate exact body, boundary, EH liveness, no-route evidence, source cause, rejected helper and static-registration hypotheses, and historical correction | near-certain | Live MCP target, constructor, xref, byte, RTTI, startup and shutdown evidence | by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md all prose sections | incorporate | applied |
| C184-003 | 000184 | Move the class declaration to H with direct bases and packed StaticObjEntry lightImageIndex at +0x00; make CPP include StaticObjImageLib.h before children; change 88/89 to 92/96 while preserving owner/emitter 0000O7, true, blank position, and by-class Nested inapplicability | very-strong | RTTI PMD/EBO, exact 0x14 layout, current UID00023D constructor/setter cross-consumer proof, historical generated missing-H/children baseline, and historical additive owning-header evidence from command 000000022436 whose valid content is incorporated into current command 000000022554, SHA256 C28BC94256BD6FD1F826E5A856790508A0FFD2DF510A40B8F504F19AA098117E | by-class/StaticObjImageLib.md formal CPP and H plus source-shape prose | incorporate | applied |
| C184-004 | 000184 | Remove explicit singleton clear from destructor CPP; change 87/91 to 92/96 while preserving owner/emitter 0000E2, true, blank position, Nested 0, and blank H | near-certain | Ordinary tail clear at 4dd29b before LObject and direct base RTTI | by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md formal CPP, metadata, and lifecycle prose | incorporate | applied |
| C184-005 | 000184 | Reclassify scalar wrapper; change 85/90, owner/emitter 0000E2, true, blank position, Nested 0, blank CPP/H to 93/97, owner 0000E2, false, blank emitters/position, preserved Nested 0, blank CPP/H | near-certain | Vtable slot, cleanup parity, flags and optional delete tail | by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md metadata, blank formal channels, and prose | incorporate | applied |
| C184-006 | 000184 | Correct cluster inventory; change 86/91 to 90/95 while preserving owner NONE, false, blank emitter/position, Nested -4, and blank CPP/H | near-certain | Constructor EH disassembly and target boundary | by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md inventory, lifecycle, source-form, and metadata | incorporate | applied |
| C184-007 | 000184 | Correct file root; change 88/88 to 90/94 while preserving owner FILE, blank CPP/H, and by-file schema-inapplicable reconstructable/emitter/position/Nested fields | very-strong | Class, RTTI, constructor, destructor, scalar, global, generated state | by-file/StaticObjImageLib.md status, owned helpers, parent evidence, source shape, history, and score | incorporate | applied |
| C184-008 | 000184 | Preserve one zero singleton definition; change 88/91 to 92/96 while preserving owner/emitter 0000O7, true, blank position, nonblank CPP/blank H, and by-global Nested inapplicability | near-certain | Global bytes and thirteen xrefs | by-global/g_pStaticObjImageLib.md formal definition, lifecycle, exact xrefs, and metadata | incorporate | applied |
| C184-009 | 000184 | Reclassify storage; change 88/91, owner/emitter 0000SD, true, blank position, Nested 0, CPP proof comment/blank H to 93/97, owner 0000SD, false, blank emitters/position, preserved Nested 0, blank CPP/H | near-certain | Live 00 00 00 00 bytes, exact 69b448-69b44c boundary, adjacent slots, thirteen refs | by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md metadata, blank formal channels, and prose | incorporate | applied |
| C184-010 | 000184 | Add PMD +4 EBO layout; change 85/88 to 92/97 while preserving owner/emitter 0000E2, true, blank position, blank CPP/H, and by-struct Nested inapplicability | near-certain | StaticObj RTTI CHD attributes 1 and three bases, direct-Singleton BCD PMD +4, and member accesses prove multiple inheritance plus EBO | by-type/by-struct/StaticObjImageLibLayout.md hierarchy, layout, evidence, and metadata | incorporate | applied |
| C184-011 | 000184 | Reclassify vtable; change 85/90, owner/emitter 0000E2, true, blank position, blank CPP/H to 92/97, owner 0000E2, false, blank emitters/position, blank CPP/H, preserving by-vtable Nested inapplicability | near-certain | COL, CHD values 0,1,3,0x00648d78 with attributes 1, BCD, base array, decorated names, exact three slots | by-type/by-vtable/StaticObjImageLibVtable.md metadata, RTTI hierarchy, and source disposition | incorporate | applied |
| C184-012 | 000184 | Preserve packed StaticObjEntry and class-H ownership with signed int lightImageIndex at +0x00; retain lightIntensity only as rejected historical terminology; change 85/88 to 90/94 while preserving owner/emitter 0000E2, true, blank position, blank CPP/H, and by-struct Nested inapplicability | very-strong | Current UID00023D passes +0x00 unchanged to the LightingObjectPane constructor and SetLightImageIndex; constructor allocation and destructor/render consumers preserve the remaining layout | by-type/by-struct/StaticObjEntry.md source declaration ownership, allocation semantics, field history, and metadata | incorporate | applied |
| C184-013 | 000184 | Preserve TileClassEntry and class-H ownership; change 85/88 to 90/95 while preserving owner/emitter 0000E2, true, blank position, blank CPP/H, and by-struct Nested inapplicability | very-strong | TILEC parser, renderer stride, destructor free | by-type/by-struct/TileClassEntry.md source declaration ownership and metadata | incorporate | applied |
| C184-014 | 000184 | Preserve and explicitly supersede the historical file-level static cleanup and authored clear-helper assumptions | near-certain | No registration route plus direct-base RTTI and EH evidence | target, class, file, cluster, destructor, scalar, global, storage, layout, and vtable historical assumptions sections | historicalize | applied |
| C184-015 | 000184 | Supply the exact target manual by-memory replacement row and bind its application/validation exclusively to supervisor manual-coverage authority | near-certain | Accepted target metadata and disposition | by-memory/-coverage-report.md UID000184 row | incorporate | proposed |
| C184-016 | 000184 | Supply the exact cluster, destructor, scalar-wrapper, and singleton-storage by-memory replacement/insertion rows and bind their application/validation exclusively to supervisor manual-coverage authority | very-strong | Accepted support metadata and dated manual-row audit | by-memory/-coverage-report.md UIDs 00017H, 00017I, 0003M2, and 0001PP rows | incorporate | proposed |
| C184-017 | 000184 | Supply the exact StaticObjImageLib class manual-coverage replacement row and supervisor ownership boundary | very-strong | Accepted class hierarchy, H route, and score | by-class/-coverage-report.md UID0000E2 row | incorporate | proposed |
| C184-018 | 000184 | Supply the exact StaticObjImageLib file manual-coverage replacement row and supervisor ownership boundary | very-strong | Accepted source-root and compiler-support disposition | by-file/-coverage-report.md UID0000O7 row | incorporate | proposed |
| C184-019 | 000184 | Supply the exact g_pStaticObjImageLib manual-coverage replacement row without sentinel wording and bind application to supervisor authority | near-certain | Zero bytes and thirteen refs | by-global/-coverage-report.md UID0000SD row | incorporate | proposed |
| C184-020 | 000184 | Supply the exact StaticObjEntry, StaticObjImageLibLayout, and TileClassEntry manual-coverage replacement rows, including lightImageIndex +0x00, and bind application to supervisor authority | very-strong | Accepted formal H, UID00023D cross-consumer field proof, and layout evidence | by-type/by-struct/-coverage-report.md UIDs 0001W8, 0001W9, and 0001WC rows | incorporate | proposed |
| C184-021 | 000184 | Supply the exact StaticObjImageLibVtable manual-coverage replacement row and supervisor ownership boundary | near-certain | Exact RTTI and vtable compiler-data disposition | by-type/by-vtable/-coverage-report.md UID0001YX row | incorporate | proposed |
| C184-022 | 000184 | Refresh generated source after C184-029 so StaticObjImageLib CPP/H preserve the direct-base class route, use the accepted MemoryMan and shared ImageFrameTable declarations, reproduce the exact destructor behavior, omit UID000184, and pass complete physical readback under supervisor authority | very-strong | Commands through generated 23008 and tracker 23015 are historical; dated generated command 000000023042 at 2026-08-13T01:06:08-04:00 reread StaticObjImageLib.cpp SHA256 1AC04D0EBB9BCF45F053B841B9BAB23354F0D12CBE03281EB4B91A23A1D51335, StaticObjImageLib.h SHA256 D00B3902A83DA2F6D4108EB9F2DAC3B2E13A1C3204B5740FFE90AF49340BB1C3, and ImageFrameTable.h SHA256 78CEC2CCA386C0D52AD4D69936F1003F9D83D7E1D106DDADD35FC61A208F8D44; dated tracker command 000000023045 at 2026-08-13T01:12:15-04:00, SHA256 6794C5420667408D376DD55098F05BD3649191D62F18D4C567F2D4613953DFFC (1,721,219 bytes, 6,765 lines), preserves UID000184 94/97, average 95.5, false/non-emitting at line 5682; both are snapshots only and later gates dynamically reread, without B005 or supervisor implementation credit | validator-owned generated StaticObjImageLib.h, StaticObjImageLib.cpp, ImageFrameTable.h, generated coverage, and tracker readback | incorporate | proposed |
| C184-023 | 000184 | Supply Section 21's literal pure function rename, exact function and occupied scalar-stack set_type, single-channel comment, complete-frame prestate/protection/readback, and supervisor Gate 2B boundary for four functions | very-strong | Fresh runtime-attested canonical-session reads prove exact names, ranges, prototypes, complete frames, four blank comment channels, xrefs, target bytes, and zero collisions for all proposed function/global names; Gate 2B rechecks these recorded literals before action | canonical IDB functions 004e5c00, 004dcf60, 004dd1e0, and 004e6990 | incorporate | proposed |
| C184-024 | 000184 | Supply the exact singleton-slot current prestate and intended final four-byte data-item state: name `g_pStaticObjImageLib`, type `StaticObjImageLib *`, exact repeatable comment, zero bytes, thirteen xrefs, and unchanged neighbors; no standalone rename | near-certain | Fresh current-session reads prove zero bytes, four one-byte target items with blank stored head name and generated-only display label `unk_69B448`, explicit protected neighbor names `g_pRidingImageLib`/`g_pEffectObjImageLib`, and exact 13/20/12 target/predecessor/successor xrefs plus item/comment/type boundaries; the dated unsaved diagnostic independently proves the final shape/name and type are supported | canonical IDB data 0069b444-0069b44d | incorporate | proposed |
| C184-025 | 000184 | Supply exact intended declarations and complete readbacks for TileClassEntry, packed StaticObjEntry with lightImageIndex +0x00, and StaticObjImageLib without a fake Singleton member, including parser-safe packing evidence and explicit human-source-to-IDA-canonical unsigned aliases | very-strong | Fresh current-session type_inspect proves all three proposed UDTs absent and LObject/ArchiveMetadataTable/MemoryMan opaque with size sentinel and zero members; type_query proves catalog total 1,020 with protected additions at ordinals 1017-1020; canonical retry2/scratch prove exact canonical aliases, parser-safe packing, size14 StaticObjEntry, size20 StaticObjImageLib, UID00023D lightImageIndex flow, allocation sizes, and EBO | canonical IDB local types | incorporate | proposed |
| C184-026 | 000184 | Supply the protected no-change inventory and exact decorated/blank name, kind, width, type, value, comment-channel, range, and final expected readback for every Section 21 RTTI/vtable/neighbor row | near-certain | Fresh current-session item/comment/byte/integer/xref reads prove every protected COL, CHD, array, BCD, type descriptor, vtable word, and successor row, including StaticObjImageLib CHD 0,1,3,0x00648d78 with attributes 1, exact low-count xref sources, and 481 inbound xrefs to the shared LObject BCD | canonical IDB 00640348-00640364, 00648d54-00648df8, 00676a8c-00676adc, and 0061b700-0061b714 | incorporate | proposed |
| C184-027 | 000184 | Record that current-runtime authority, persistence, and rollback are supervisor-owned outside this report; this report supplies only dated identity evidence, literal prestates, permitted deltas, protected properties, and complete expected readbacks | near-certain | Current physical disk SHA256 53B60FCF7C42327C9E03D90A407903D4EFF15510FEE791F2452EF0B2036A05D9, public runtime attestation at 2026-08-13T11:38:46.695504+00:00, complete fresh bounded actionable/protected baseline, and historical failed-closed diagnostics with exact restoration | supervisor Gate 2B boundary for UID000184 | incorporate | proposed |
| C184-028 | 000184 | Run scoped no-generated-refresh validators for every changed ordinary by-star doc and physically reread each destination | very-strong | Current workflow and exact callback destinations | report validator receipts and changed ordinary docs | incorporate | applied |
| C184-029 | 000184 | Correct the authored destructor and its declaration dependencies: use `MemoryMan::FreeBufferMemory`, preserve both observed `GetMemoryMan` acquisitions and unconditional catalog dereference, expose the accepted archive-table declarations from shared ImageFrameTable H, and include the required headers before child definitions | very-strong | Current MemoryMan H and UID0001BF formal API; ordinary-destructor body/call order; current UID0000UN accepted layout; generated command 000000022520 compile/readback defects | by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md formal CPP; by-class/StaticObjImageLib.md formal CPP; by-file/StaticObjImageLib.md dependency/source placement; by-item/EPFArchiveMetadataTable.md formal CPP/H and source placement; by-file/ImageFrameTable.md header route | incorporate | applied |
| C184-030 | 000184 | Supply exact manual by-item and by-file coverage replacements for the shared ImageFrameTable header/declaration route, with supervisor-only application and validation | very-strong | Accepted shared declarations plus C184-029 dependency closure | by-item/-coverage-report.md UID0000UN row and by-file/-coverage-report.md UID0000K1 row | incorporate | proposed |

## Positive Evidence Summary

- Direct facts supporting the recommendation: the target is exactly two instructions, has one code xref from constructor EH state 1, receives ECX equal to complete object plus four, clears the singleton slot, and has no authored-call route.
- RTTI corroboration: `StaticObjImageLib` has three CHD entries: itself, `LObject`, and direct `Singleton<StaticObjImageLib>`. The Singleton BCD PMD is `+4,-1,0`, proving a direct non-virtual empty base at the same offset passed to the target.
- Destructor corroboration: ordinary and scalar cleanup each clear the same slot after derived fields and before `LObject` cleanup.
- Sibling corroboration: adjacent image-library helpers have the same eleven-byte body, EH-only constructor route, direct Singleton RTTI, and no-source-body disposition.
- Source-tree corroboration: explicit Application startup construction and shutdown deletion explain the lifecycle without a static registration callback.
- Strongest inference chain: direct-base RTTI plus adjusted EH receiver plus reverse destruction order is sufficient to identify the retained function as a compiler-emitted base destructor even though the body does not dereference ECX.

## IDA MCP Facts

- Historical canonical snapshot: session discovered for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; runtime attestation `ok:true` at `2026-08-11T18:19:46Z`. Named session identifiers are not future authority.
- Current physical disk snapshot for this repair: canonical IDB SHA256 `53B60FCF7C42327C9E03D90A407903D4EFF15510FEE791F2452EF0B2036A05D9`, `143,206,875` bytes, mtime `2026-08-13T07:09:07.5603942-04:00`. Public runtime attestation at `2026-08-13T11:38:46.695504+00:00` validates exact canonical-path session `supervisor-uid0004HB-gate2b-20260813T1105Z`; final health remained `status:ok`, Hex-Rays ready, and all required bounded reads succeeded. Fresh read-only queries on that session establish Section 21's complete literal preparation baseline. Historical B8C1, `20DEC...`, `A95C...`, and `1B8E...` revisions remain dated evidence only.
- Target lookup: `sub_4E5C00`, start `0x004e5c00`, size `0x0b`, return `void`, two instructions.
- Target disassembly: `0x004e5c00 mov dword ptr unk_69B448, 0`; `0x004e5c0a retn`. Here `unk_69B448` is IDA's generated display label for an address whose stored name is blank, not a persisted user name.
- Target frame: only `__return_address` at `+0x00`, size four, type `_UNKNOWN *`; no stack arguments.
- Target bytes: `c7 05 48 b4 69 00 00 00 00 00 c3`; successor `0x004e5c0b-0x004e5c10` is five `cc` bytes.
- Sole target xref: code xref `0x005fff9d` inside constructor `sub_4DCF60`.
- Constructor EH: state 0 at `0x005fff8f` loads complete this and jumps to `LObject_destructor`; state 1 at `0x005fff97` loads complete this, `add ecx,4`, then jumps to target.
- Function sizes: constructor `0x278`, ordinary destructor `0xde`, scalar wrapper `0x116`.
- Ordinary tail: clear at `0x004dd29b`, then `LObject_destructor` at `0x004dd2a7`.
- Scalar tail: clear at `0x004e6a5e`, `LObject_destructor` at `0x004e6a6a`, flags tests, optional operator delete, receiver return, `retn 4`.
- Global slot: fresh 2026-08-13 canonical-session reads found bytes `00 00 00 00` and represented `0x0069b448-0x0069b44c` as four separate one-byte non-data items. The head has a blank stored name, blank type/comments, and `is_data:false`; `unk_69B448` is generated presentation only, and the remaining three bytes are unnamed/untyped. Thirteen xrefs occur at `4dcfa3`, `4dcfaa`, `4dd29b`, `4e5c00`, `4e6a5e`, `4f65e2`, `50f064`, `50f0b0`, `530d30`, `537960`, `53797a`, `5379ad`, and `54977d`. Gate 2B must reproduce this already-discovered complete row exactly before mutation.
- Vtable: `0x0061b700 -> 0x00648d54`; slots `0x0061b704 -> 0x004e6990`, `0x0061b708 -> 0x004f4b10`, `0x0061b70c -> 0x0041b6c0`; successor COL begins `0x0061b710`.
- RTTI: StaticObj COL `0x00648d54`, CHD `0x00648d68`, base array `0x00648d78`, self BCD `0x00648d88`, Singleton BCD `0x00648da4`, Singleton CHD `0x00648dc0`, Singleton base array `0x00648dd0`, Singleton self BCD `0x00648dd8`; type descriptors at `0x00676a8c` and `0x00676aac`.
- StaticObjImageLib CHD: exact bytes `00 00 00 00 01 00 00 00 03 00 00 00 78 8d 64 00` decode independently as dwords `0,1,3,0x00648d78`. The second dword is CHD attributes `1`, consistent with the evidenced multiple-inheritance hierarchy; the prior zero was stale report evidence, not current IDB state.
- Current comments: all four function comment channels are empty for target, constructor, ordinary destructor, and scalar wrapper; global regular/repeatable comments are empty; RTTI regular comments `signature` at `0x00648d54` and `reference to type description` at `0x00648da4` must be preserved.
- Exact proposed-name collision query returned zero results.
- Negative IDA facts: target callers/callees beyond the EH xref are empty; target VA, RVA, and raw-offset pointer searches returned zero; `atexit` and `onexit` import query returned zero.
- Current neighbor facts: `0x0069b444-0x0069b448` is four one-byte items, zero-valued, with explicit head name `g_pRidingImageLib`, blank comments, head type `RidingImageLib *`, `is_data:false`, and 20 xrefs; `0x0069b44c` is one zero-valued byte with explicit name `g_pEffectObjImageLib`, blank comments, type `EffectObjImageLib *`, `is_data:false`, and 12 xrefs. Earlier blank-neighbor observations are superseded dated states. Both current explicit names and all other fields are protected exactly as found on the current disk-backed snapshot.
- Dated MCP action behavior: the exact singleton-slot `make_data` call returns a four-byte data item and exact requested name but leaves its type blank even when the request's `type` field is `StaticObjImageLib *g_pStaticObjImageLib`. The public `set_type` global request with `ty:"StaticObjImageLib *"` attaches the type as a separate operation. The trial was unsaved and wholly discarded, so these facts describe endpoint behavior rather than current IDB mutation state.
- Dated UDT action behavior: `declare_type` accepts human C spellings but `type_inspect` canonicalizes `unsigned short` to `unsigned __int16` and `unsigned char` to `unsigned __int8`; those exact aliases are semantic identity, not layout drift. The declaration parser splits `#pragma pack(push, 2)` at its comma, while separate `#pragma pack(push)` and `#pragma pack(2)` lines parse and produce the intended size-14 StaticObjEntry. These observations come only from discarded unsaved workers.
- Current shared-field fact: UID00023D reads the signed `StaticObjEntry +0x00` dword, uses negative as the attached-light suppression sentinel, and forwards the unchanged nonnegative value to both the `LightingObjectPane` constructor and `LightingObjectPane_SetLightImageIndex`; the setter compares and stores `m_lightImageIndex`. The shared source field is therefore `int lightImageIndex`, while `lightIntensity` is a superseded interpretation rather than an active declaration name.
- Current source-API corroboration: the accepted project declaration is `MemoryMan`, `GetMemoryMan()` returns `MemoryMan *`, and the exact `0x00516170` callee is `MemoryMan::FreeBufferMemory(void *)`. The ordinary destructor body contains two manager acquisitions and the measured catalog dereference/free order; these facts reject the generated `MemoryManager::Free` spelling and unsupported outer catalog-null guard.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| 0x004dcf60-0x004dd1d8 | contained by UID00017H | Source-authored constructor plus compiler EH states | source-authored support, wholly contained by the cluster | 0000E2 | cluster 90/95 current | Direct Singleton construction and unwind source cause proven; the exact containing range and class route close this report without a target-triggered split |
| 0x004dd1e0-0x004dd2be | UID00017I | Source-authored ordinary destructor | true | 0000E2 | 92/96 current | Current formal CPP omits the explicit singleton clear, uses `MemoryMan::FreeBufferMemory`, preserves both manager acquisitions, and preserves the measured unconditional catalog dereference/free contract |
| 0x004e5c00-0x004e5c0b | UID000184 | Compiler-emitted Singleton base destructor | false current | 0000E2 semantic | 94/97 current | Target; blank formal CPP/H |
| 0x004e5c0b-0x004e5c10 | UID0000VN ignored ledger | Linker/compiler alignment padding | no source | NONE | 100 | Five cc bytes, unchanged |
| 0x004e6990-0x004e6aa6 | UID0003M2 | Compiler scalar deleting destructor | false current | 0000E2 semantic | 93/97 current | Blank formal CPP/H |
| 0x0069b448-0x0069b44c | UID0001PP | Physical singleton pointer storage | false current | 0000SD semantic | 93/97 current | Zero loader data, no duplicate source |
| g_pStaticObjImageLib | UID0000SD | Sole source singleton definition | true | 0000O7 | 92/96 current | CPP definition; declaration in complete class H |
| StaticObjImageLib declaration | UID0000E2 | Human source hierarchy and members | true | 0000O7 | 92/96 current | Complete H plus dependency-complete CPP includes before children |
| StaticObjImageLib layout | UID0001W9 | Exact storage plus direct empty base semantics | true support | 0000E2 | 92/97 current | No duplicate code |
| StaticObjImageLib vtable/RTTI | UID0001YX and UID0002OY | Source-declared/generated-binary compiler data | false current | 0000E2 semantic | 92/97 current | No handwritten table |
| Shared archive/draw declarations | UID0000UN | PackedArchiveRecord, ArchiveMetadataTable, and FrameDrawRecord ABI | true | 0000K1 | 88/91 current -> 90/92 recommended | Move accepted declarations from CPP to H; blank CPP; exact Section 22 H payload |
| ImageFrameTable source root | UID0000K1 | Shared declaration/header and image-frame implementation route | file root | FILE | 90/88 current -> 91/89 recommended | Metadata-only root; UID0000UN supplies ImageFrameTable.h while exact children retain bodies |
| Memory allocation API | UID00007U, UID0001BC, UID0001BF | Existing MemoryMan type, accessor, and FreeBufferMemory method | dependency only | existing owners | unchanged | Exact accepted API evidence; no edit or duplicate declaration |
| Application startup/shutdown | UID0002H7 and UID0002H8 | Explicit construction and deletion routes | source-authored consumers | Application | unchanged | Excludes static registration hypothesis |

- Inventory totals for this target family and the C184-029 dependency closure: one authored constructor, one authored ordinary destructor, one retained EH-only base-destructor instantiation, one scalar deleting wrapper, one physical storage slot, one semantic global definition, one class declaration, one class layout, one vtable/RTTI family, one five-byte padding span, one shared three-type declaration block, one shared source/header root, one already-established allocator API dependency, and explicit startup/shutdown consumers.
- Source-bearing rows receive explicit H, CPP, or no-code disposition. No additional target UID is declared.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| 0x004e5c00 | one code xref from 0x005fff9d; no callees | Constructor EH state-one base destruction only |
| 0x005fff97-0x005fff9d | load complete this; add ECX four; tail jump target | Exact direct Singleton base receiver |
| 0x005fff8f-0x005fff92 | load complete this; tail jump LObject destructor | Earlier direct base cleanup state |
| 0x004dd29b | write zero to 0x0069b448 | Inlined normal Singleton base destruction |
| 0x004e6a5e | write zero to 0x0069b448 | Inlined scalar-wrapper Singleton base destruction |
| 0x0069b448 | thirteen data xrefs | Constructor publish/null, three destruction forms, shutdown, and consumers |
| 0x0061b704 | constructor, ordinary destructor, scalar wrapper writes/refs | One class vtable and scalar deleting slot |
| 0x00648da4 | referenced from StaticObj base array | Direct Singleton base descriptor |
| ordinary destructor allocator calls | two `GetMemoryMan()` acquisitions and calls to exact callee `0x00516170` | Preserves original manager acquisition order and identifies accepted `MemoryMan::FreeBufferMemory` API |
| ordinary destructor archive table | unconditional `tileCatalog` load/dereference, conditional records free, unconditional catalog free | Rejects a source-added outer catalog-null guard and requires complete `ArchiveMetadataTable` visibility |
| target pointer forms | zero VA, zero RVA, zero raw-offset hits | No function-pointer or registration route |
| atexit/onexit imports | zero exact regex results | No static callback registration evidence |

## Documentation Evidence And IDA Status

- Current ordinary documentation status after the explicit C184-029 callback: the renamed target and all original support destinations retain the accepted metadata, hierarchy, range, lifecycle, historical-assumption, and `lightImageIndex` changes. The five C184-029 destinations now physically contain the accepted source correction at the exact hashes recorded in Sections 31-32: UID00017I uses `MemoryMan::FreeBufferMemory`, both manager acquisitions, and the unconditional catalog contract; UID0000E2 includes its own header, shared ImageFrameTable H, MemoryMan H, and CRT declarations before children; UID0000O7 records the dependency/source route; UID0000UN emits the shared declarations in H with blank CPP at `90/92`; and UID0000K1 records the sibling H route at `91/89`. The earlier defective ordinary states remain historical evidence rather than current truth.
- Historical pre-callback documentation defects: target/file/cluster used generic static-cleanup language; the class omitted the Singleton base and emitted its declaration in CPP; the destructor explicitly cleared the global; scalar/storage/vtable pages were reconstructable emitters; storage prose and manual coverage used the false `0xffffffff` sentinel. The ordinary pages now preserve these only as rejected history.
- Dated manual-documentation defects: at the 2026-08-11 B005 readback, the seven original supervisor-owned manual-coverage claim groups were stale or absent as enumerated in Section 28. C184-030 adds the exact shared-header by-item/by-file rows triggered by the current source correction. No manual row receives B005 ordinary-callback or generated-refresh credit; each supervisor-owned row is recorded as `proposed` in this artifact, while external application/verification truth remains supervisor-owned.
- Generated status history: commands through generated 23008 and tracker 23015 are superseded dated snapshots. The dated 2026-08-13 physical rereads after generated command 23042 found StaticObjImageLib.cpp SHA256 `1AC04D0EBB9BCF45F053B841B9BAB23354F0D12CBE03281EB4B91A23A1D51335` (5,719 bytes, 172 lines), StaticObjImageLib.h SHA256 `D00B3902A83DA2F6D4108EB9F2DAC3B2E13A1C3204B5740FFE90AF49340BB1C3` (2,034 bytes, 66 lines), and ImageFrameTable.h SHA256 `78CEC2CCA386C0D52AD4D69936F1003F9D83D7E1D106DDADD35FC61A208F8D44` (1,024 bytes, 40 lines), with no UID000184 marker. The tracker reread after command 23045 found SHA256 `6794C5420667408D376DD55098F05BD3649191D62F18D4C567F2D4613953DFFC` (1,721,219 bytes, 6,765 lines) and unchanged UID000184 semantics at line 5682. These are dated snapshots only; C184-022 requires dynamic physical reread at each later gate and gives no implementation credit.
- Fresh literal IDA preparation status from runtime-attested canonical-path session `supervisor-uid0004HB-gate2b-20260813T1105Z`: functions are `sub_4E5C00`, `sub_4DCF60`, `sub_4DD1E0`, and `sub_4E6990` at the exact ranges/types/frames/xrefs in Section 21; all four comment channels are blank; the target has a blank stored name with generated-only `unk_69B448`, four raw one-byte items, blank type/comments, zero bytes, and thirteen xrefs; protected neighbors are explicitly `g_pRidingImageLib` and `g_pEffectObjImageLib`; all proposed function/global names have zero collisions; all three proposed UDTs are absent; dependencies remain opaque; catalog total is 1,020 with identified ordinals 1017-1020; and every protected RTTI/vtable row matches, including CHD values `0,1,3,0x00648d78` and exact bytes `00 00 00 00 01 00 00 00 03 00 00 00 78 8d 64 00`. Gate 2B must reattest and prove equality with these literals before mutation; it is not authorized to discover or improvise them. No IDA mutation is credited to B005.
- Current failed-trial disposition: the fresh canonical reopen after the unsaved Gate 2B trial restored that exact A95C prestate. The trial's successful diagnostic global type application is retained only to make C184-024 deterministic; it does not change the current IDA-status statement or receive B005/supervisor implementation credit.
- Current UDT disposition: canonical retry2 and isolated scratch were both discarded unsaved, so TileClassEntry, StaticObjEntry, and StaticObjImageLib remain absent in the canonical disk state described above. Their successful temporary readbacks now constrain C184-025's exact payloads and expected canonical spellings without changing current-state or action-credit claims.

## Ranked Ownership Analysis

### 1. Class [UID:0000E2]

- Evidence for: direct `Singleton<StaticObjImageLib>` RTTI, PMD `+4,-1,0`, adjusted constructor-EH receiver, the class's authored virtual destructor, and the class-specific singleton slot all identify the class declaration as the target's exact source cause.
- Evidence against: UID000184 has no handwritten class-method body and therefore cannot emit through the class as an independent reconstructable child.
- Decision: accepted semantic owner. `CANONICAL_OWNER:0000E2` records the precise source cause while false reconstructability and blank emitters prevent duplicate source.

### 2. File [UID:0000O7]

- Evidence for: `StaticObjImageLib.cpp` and its sibling H are the compilation-unit route for the class, singleton definition, and authored methods whose compilation regenerates the retained body.
- Evidence against: file ownership is broader than the target's direct class/base relationship and would obscure the exact compiler cause.
- Decision: retained as compilation-unit root for UID0000E2 and its source-bearing children, rejected as UID000184's direct canonical owner.

### 3. Global [UID:0000SD], `NONE`, or an authored helper

- Evidence for: UID0000SD owns the sole source singleton definition; `NONE` could describe non-emission; a helper label superficially matches the two-instruction zero store.
- Evidence against: the global owns storage definition rather than destructor semantics; `NONE` loses a proven class source cause; no authored caller, pointer, registration route, API surface, or independent helper identity exists.
- Decision: reject all three as target owners. Keep UID0000SD as owner of storage UID0001PP only, preserve UID000184 as class-owned non-emitting support, and reject public/file-local helper source.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: none.
- Likely full contents: not applicable; the target is already exactly ranged and is covered by the existing StaticObjImageLib class/file source cause.
- Candidate related items rejected: ordinary destructor, scalar deleting wrapper, global storage, RTTI/vtable data, and padding remain separately ranged and separately classified.
- Standalone, narrow, or broad source-file inference: no new grouping is justified; the existing class/file split is exact.

## Source Placement

- Human source placement: `NexusTK/render/StaticObjImageLib.h` for the class/local record/global declaration and `NexusTK/render/StaticObjImageLib.cpp` for the singleton definition and authored method bodies. Shared `PackedArchiveRecord`, `ArchiveMetadataTable`, and `FrameDrawRecord` declarations belong in `NexusTK/render/ImageFrameTable.h`, emitted through [UID:0000UN]/[UID:0000K1], because StaticObjImageLib and other image libraries consume the same archive-table ABI.
- UID000184 has no handwritten source location. It is covered by the class declaration and compiler output.
- The class CPP channel should include `StaticObjImageLib.h`, shared `ImageFrameTable.h`, `../util/MemoryMan.h`, and `<stdlib.h>` before `[[CHILDREN]]`; the complete class declaration belongs in H. The common image-frame declarations move from UID0000UN CPP to UID0000UN H so every dereferencing translation unit sees one source-consistent definition.
- The global CPP channel remains the one definition `StaticObjImageLib *g_pStaticObjImageLib = 0;`.
- The authored destructor remains in UID00017I CPP without a direct global clear.
- The scalar wrapper, vtable/RTTI data, and physical singleton slot have blank formal channels.

## Range / Split / Padding / Reclassification Analysis

- Exact target half-open range is unchanged: `0x004e5c00-0x004e5c0b`.
- Predecessor Riding helper ends at `0x004e5bfb`; `0x004e5bfb-0x004e5c00` is five-byte alignment.
- Successor `0x004e5c0b-0x004e5c10` is five-byte alignment before the AUTOBUF destructor at `0x004e5c10`.
- The target is already split correctly by bytes and UID. Only the descriptive filename/title and semantic classification change.
- The local cluster's exact range is `0x004dcf60-0x004ddf60`; the dated manual-coverage defect used obsolete range `0x004dcf60-0x004e6aa6`, and Section 28 supplies the exact supervisor-owned corrected row without asserting its application state.
- No merge with the ordinary destructor, scalar wrapper, global, or padding is valid. Coverage occurs through source cause, not range merging.

## Negative Evidence Summary

- No ordinary direct call reaches `0x004e5c00`.
- No target callee exists.
- No target address pointer appears in VA, RVA, or raw-file-offset form.
- No import or reference indicates `atexit`, `_onexit`, or static callback registration.
- No separate global/resource cleanup occurs in the body.
- No RTTI supports an independent cleanup-helper class or method.
- No original symbol proves a source-authored helper name.
- No valid reason remains to emit a proof comment into final CPP; documentation prose records the compiler artifact.
- Negative tool-behavior evidence rejects the former atomic-data assumption: `make_data` did not retain the supplied pointer declaration as the item's type, so a one-call final typed poststate was not achievable through that endpoint on the tested historical revision.
- Negative parser/readback evidence rejects two former UDT assumptions: comma-bearing `#pragma pack(push, 2)` is not accepted by the current declaration splitter, and literal source aliases are not preserved by canonical `type_inspect`. Neither failure changes source C++ spelling or structure layout; both require an exact analysis-side contract.

## IDA Rename / Type / Comment Recommendations

### Dated Authority And Supervisor Boundary

The older `supervisor-uid0002OW-gate2b-20260813T0115Z`/B8C1 preparation baseline is superseded dated evidence. Fresh report-preparation reads used canonical-path session `supervisor-uid0004HB-gate2b-20260813T1105Z`. Public runtime attestation at `2026-08-13T11:38:46.695504+00:00` returned schema version 1, `ok:true`, no errors, and exact path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. The current disk snapshot was SHA256 `53B60FCF7C42327C9E03D90A407903D4EFF15510FEE791F2452EF0B2036A05D9`, size `143,206,875`, mtime `2026-08-13T07:09:07.5603942-04:00`; health remained `status:ok` with Hex-Rays ready and every required bounded query succeeded. These are dated evidence, not permanent runtime authority.

The rows below are declarative: they record literal prestates, intended outcomes, allowed deltas, protected properties, and expected readbacks. The primary supervisor independently establishes current runtime authority and performs any accepted backup, mutation, persistence, reopen verification, or rollback outside this report. Any identity, prestate, collision, type, frame, comment, byte, xref, neighbor, RTTI, vtable, or readback mismatch fails the affected recommendation closed.

### Function State-Change Rows

| Entity | Literal current prestate | Structured declarative operations | Exact expected readback and protection | Claim / classification |
| --- | --- | --- | --- | --- |
| `0x004e5c00-0x004e5c0b` | Name `sub_4E5C00`; type `void()`; size `0x0b`; bytes `c7 05 48 b4 69 00 00 00 00 00 c3`; one code xref from `0x005fff9d` inside `sub_4DCF60`; address regular absent; address repeatable absent; function regular absent; function repeatable absent. | `rename`: function address `0x004e5c00`, new name `StaticObjImageLib_SingletonBaseDestructor`, `pure:true`, `allow_overwrite:false`. `set_type`: address `0x004e5c00`, kind `function`, signature `void __thiscall StaticObjImageLib_SingletonBaseDestructor(void *singletonBase)`. `set_function_comments`: address `0x004e5c00`, comment `Compiler-emitted out-of-line destructor for the direct empty Singleton<StaticObjImageLib> base; reached only from StaticObjImageLib constructor unwind state 1 with ECX = complete this + 4; clears g_pStaticObjImageLib and returns. No authored helper body.` | Exact name, signature, and function-regular comment; address regular, address repeatable, and function repeatable remain absent; range, bytes, xref, and one-row frame remain exact. | C184-023 / apply |
| `0x004dcf60-0x004dd1d8` | Name `sub_4DCF60`; type `_DWORD *__thiscall(_DWORD *this)`; size `0x278`; one code xref from `0x004f607b` in `BaramApp__Startup`; address regular absent; address repeatable absent; function regular absent; function repeatable absent. | `rename`: function address `0x004dcf60`, new name `StaticObjImageLib_Constructor`, `pure:true`, `allow_overwrite:false`. `set_type`: address `0x004dcf60`, kind `function`, signature `StaticObjImageLib *__thiscall StaticObjImageLib_Constructor(StaticObjImageLib *this)`. `set_function_comments`: address `0x004dcf60`, comment `Constructs LObject then the direct empty Singleton<StaticObjImageLib> base; the base publishes complete this to g_pStaticObjImageLib and unwind state 1 tail-calls 0x004E5C00 with ECX = this + 4 before derived resource construction.` | Exact name, signature, and function-regular comment; address regular, address repeatable, and function repeatable remain absent; range, xref, and all fifteen frame rows remain exact. | C184-023 / apply |
| `0x004dd1e0-0x004dd2be` | Name `sub_4DD1E0`; type `void __thiscall(LObject *this)`; size `0xde`; zero xrefs; address regular absent; address repeatable absent; function regular absent; function repeatable absent. | `rename`: function address `0x004dd1e0`, new name `StaticObjImageLib_Destructor`, `pure:true`, `allow_overwrite:false`. `set_type`: address `0x004dd1e0`, kind `function`, signature `void __thiscall StaticObjImageLib_Destructor(StaticObjImageLib *this)`. `set_function_comments`: address `0x004dd1e0`, comment `Source-authored StaticObjImageLib cleanup; reverse base destruction then clears g_pStaticObjImageLib through Singleton<StaticObjImageLib> before LObject teardown.` | Exact name, signature, and function-regular comment; address regular, address repeatable, and function repeatable remain absent; range, zero-xref state, and all five frame rows remain exact. | C184-023 / apply |
| `0x004e6990-0x004e6aa6` | Name `sub_4E6990`; prototype `LObject *__thiscall(LObject *Block, char)`; size `0x116`; one data xref from vtable slot `0x0061b704`; address regular absent; address repeatable absent; function regular absent; function repeatable absent. Occupied stack row is `arg_0 +0x2c size 0x04 _DWORD`. | `rename`: function address `0x004e6990`, new name `StaticObjImageLib_ScalarDeletingDestructor`, `pure:true`, `allow_overwrite:false`. Dedicated stack `rename`: function address `0x004e6990`, old `arg_0`, new `flags`, with pure mode omitted. Stack `set_type`: address `0x004e6990`, kind `stack`, variable `flags`, type `unsigned int`. After that occupied-row poststate, function `set_type`: address `0x004e6990`, kind `function`, signature `StaticObjImageLib *__thiscall StaticObjImageLib_ScalarDeletingDestructor(StaticObjImageLib *this, unsigned int flags)`. `set_function_comments`: address `0x004e6990`, comment `Compiler scalar deleting destructor: inlines StaticObjImageLib cleanup, implicit Singleton<StaticObjImageLib> clear, LObject teardown, and optional storage deletion.` | Exact function name, signature, and function-regular comment; address regular, address repeatable, and function repeatable remain absent; final stack row is `flags +0x2c size 0x04 unsigned __int32`; range, xref, and every other frame row remain exact. | C184-023 / apply |

Fresh exact-name queries returned zero collisions for the four proposed function names and `g_pStaticObjImageLib`. Every function-name action above uses the schema-valid `rename` function path with `pure:true`; only the dedicated scalar stack-variable rename omits pure mode. Function prototypes use `set_type` with the `signature` field, the occupied scalar argument uses `set_type` kind `stack`, and function-regular comments use only `set_function_comments`. No standalone data rename or one-channel `set_comments` action is authorized.

### Exact Frame Preservation

| Function | Complete entry frame | Permitted delta / exact post-frame |
| --- | --- | --- |
| `004e5c00` | `__return_address +0x00 size 0x04 _UNKNOWN *` | Identical; hidden ECX meaning changes only through the prototype. |
| `004dcf60` | `var_50 +0x10 size 0x14 DATFile; var_3C +0x24 size 0x14 DATFile; var_28 +0x38 size 0x04 LObject *; var_24 +0x3c size 0x04 _DWORD; var_20 +0x40 size 0x04 MemoryMan *; var_1C +0x44 size 0x04 _DWORD; buffer +0x48 size 0x04 _BYTE[4]; var_14 +0x4c size 0x02 _WORD; var_E +0x52 size 0x01 _BYTE; var_D +0x53 size 0x01 _BYTE; var_C +0x54 size 0x04 _DWORD; var_4 +0x5c size 0x04 _DWORD; __saved_registers +0x60 size 0x04 _DWORD; __return_address +0x64 size 0x04 _UNKNOWN *; arg_4 +0x6c size 0x04 _DWORD` | Exact same fifteen rows, names, offsets, sizes, and types. |
| `004dd1e0` | `var_10 +0x10 size 0x04 _DWORD; var_C +0x14 size 0x04 _DWORD; __saved_registers +0x20 size 0x04 _DWORD; __return_address +0x24 size 0x04 _UNKNOWN *; arg_4 +0x2c size 0x04 _DWORD` | Exact same five rows, names, offsets, sizes, and types. |
| `004e6990` | `var_14 +0x10 size 0x04 _DWORD; var_10 +0x14 size 0x04 MemoryMan *; var_C +0x18 size 0x04 _DWORD; var_4 +0x20 size 0x04 _DWORD; __saved_registers +0x24 size 0x04 _DWORD; __return_address +0x28 size 0x04 _UNKNOWN *; arg_0 +0x2c size 0x04 _DWORD` | Final row only becomes `flags +0x2c size 0x04 unsigned __int32`; every other row remains exact. |

### UDT Prestates And Intended Declarations

Fresh type inspection returned `exists:false` and `Type not found` independently for `TileClassEntry`, `StaticObjEntry`, and `StaticObjImageLib`. `LObject`, `ArchiveMetadataTable`, and `MemoryMan` exist only as opaque declarations with unknown-size sentinel `0xffffffffffffffff`, no UDT body, and zero members. The current catalog baseline is 1,020 names. Its protected tail is ordinal 1017 `jpeg_common_struct` opaque, ordinal 1018 `jpeg_error_mgr` opaque, ordinal 1019 `j_common_ptr` four-byte typedef, and ordinal 1020 `TextMenuDialog` opaque. The prior 1,016-entry baseline is superseded historical evidence. Reproduce all six type prestates and the complete 1,020-entry catalog before declaring anything; do not redeclare or reshape dependencies.

| UDT | Literal prestate | Structured declarative operation | Exact required IDA readback | Claim / classification |
| --- | --- | --- | --- | --- |
| `TileClassEntry` | Type absent: `exists:false`, `Type not found`; catalog baseline 1,020 with ordinals 1017-1020 exactly as listed above. | `declare_type` with exact `decls` text `struct TileClassEntry { unsigned short tileFrameId; unsigned char allowPaletteFilter; unsigned char reserved; };` | Exists as UDT; size `0x04`; `tileFrameId +0x00 size2 unsigned __int16`; `allowPaletteFilter +0x02 size1 unsigned __int8`; `reserved +0x03 size1 unsigned __int8`; no extras. | C184-025 / apply |
| `StaticObjEntry` | Type absent: `exists:false`, `Type not found`; remains absent until its own declaration. | `declare_type` with four exact LF-separated `decls` lines: `#pragma pack(push)`; `#pragma pack(2)`; `struct StaticObjEntry { int lightImageIndex; unsigned char lightHeightClass; unsigned char layerCount; unsigned short reserved; StaticObjEntry *cacheChain; unsigned short tileIds[1]; };`; `#pragma pack(pop)`. The comma-bearing single-line pack form is prohibited by tested parser behavior. | Exists as UDT; size `0x0e`; `lightImageIndex +0x00 size4 int`; `lightHeightClass +0x04 size1 unsigned __int8`; `layerCount +0x05 size1 unsigned __int8`; `reserved +0x06 size2 unsigned __int16`; `cacheChain +0x08 size4 StaticObjEntry *`; `tileIds +0x0c size2 unsigned __int16[1]`; no fabricated tail padding. | C184-025 / apply |
| `StaticObjImageLib` | Type absent: `exists:false`, `Type not found`; remains absent until both record dependencies have their exact accepted readbacks. | `declare_type` with exact `decls` text `struct StaticObjImageLib { void *vftable; ArchiveMetadataTable *tileCatalog; TileClassEntry *tileClasses; StaticObjEntry **staticObjEntries; int staticObjCount; };` | Exists as UDT; size `0x14`; `vftable +0x00 size4 void *`; `tileCatalog +0x04 size4 ArchiveMetadataTable *`; `tileClasses +0x08 size4 TileClassEntry *`; `staticObjEntries +0x0c size4 StaticObjEntry **`; `staticObjCount +0x10 size4 int`; no fake Singleton member. | C184-025 / apply |

The declarative dependency order is `TileClassEntry`, `StaticObjEntry`, then `StaticObjImageLib`; the last declaration is ineligible unless the first two exact readbacks and the three opaque dependency prestates remain intact. After each declaration, complete type/member and catalog readback must show only the named accepted declaration and parser-required representation, with all 1,020 pre-existing catalog entries, including exact ordinals 1017-1020, and not-yet-declared rows unchanged. Any parser, size, member, offset, pointer, count, alias, catalog, or protected-prestate mismatch fails that recommendation closed. This is a structured evidence/action handoff and contains no executable automation.

### Singleton Data Intended State

| Literal current prestate | Intended final state | Exact protection and expected readback |
| --- | --- | --- |
| Four zero bytes at `[0x0069b448,0x0069b44c)` represented as four separate one-byte non-data heads; first stored name blank, with `unk_69B448` generated only for display; blank type; regular and repeatable comments absent; thirteen xrefs; adjacent rows exactly as documented below. | One four-byte data item over exactly `[0x0069b448,0x0069b44c)`, named `g_pStaticObjImageLib`, typed `StaticObjImageLib *`, with repeatable address comment `StaticObjImageLib singleton slot; published by Singleton<StaticObjImageLib> construction, cleared by constructor unwind and direct-base destruction, and read by startup/shutdown and render consumers.` | Zero bytes and thirteen xrefs remain exact; regular comment remains absent; predecessor/successor item heads, bytes, explicit names, types, comments, and xrefs remain unchanged. Any other delta fails the recommendation closed. |

| State-dependent action | Structured declarative operation | Exact accepted immediate state | Claim / classification |
| --- | --- | --- | --- |
| Shape and name | `make_data`: address `0x0069b448`, full declaration `StaticObjImageLib *g_pStaticObjImageLib`, name `g_pStaticObjImageLib`, `delete_existing:true`. | One `is_data:true`, `is_code:false` item at `[0x0069b448,0x0069b44c)`, size four, exact name, blank type, zero bytes, both comments absent, thirteen xrefs, no independent target-tail items, and unchanged adjacent rows. The blank type is the tested accepted intermediate endpoint behavior. | C184-024 / apply |
| Attach pointer type | `set_type`: address `0x0069b448`, kind `global`, type `StaticObjImageLib *`. This action is eligible only from the exact preceding blank-type four-byte item state. | Same item/range/name/kind/bytes/xrefs/absent comments and neighbors, with canonical type exactly `StaticObjImageLib *`. | C184-024 / apply |
| Add semantic comment | `set_address_repeatable_comments`: address `0x0069b448`, comment `StaticObjImageLib singleton slot; published by Singleton<StaticObjImageLib> construction, cleared by constructor unwind and direct-base destruction, and read by startup/shutdown and render consumers.` This action is eligible only from the exact typed state. | Same final item and protections; regular address comment remains absent and repeatable address comment equals the literal text. | C184-024 / apply |

These rows declare three exact state-dependent actions and contain no executable automation. No partial state is save-eligible: final name, type, width, kind, comments, bytes, thirteen xrefs, collapsed target tails, and both protected adjacent rows must all match the recorded poststate. The historical machine-shaped material removed from this section is retained only in [000184-StaticObjImageLibSingletonClearHelper-source-quality-removed.md](000184-StaticObjImageLibSingletonClearHelper-source-quality-removed.md); it is non-authoritative and must never be executed.

### Protected adjacent data items

| Entity | Literal current item/name/type/kind/width/comments/xrefs | Required poststate | Supervisor classification |
| --- | --- | --- | --- |
| `0x0069b444-0x0069b448` predecessor | Fresh current-session prestate: bytes `00 00 00 00`; four separate size1 non-data items; head `0x0069b444-0x0069b445`, explicit name `g_pRidingImageLib`, type `RidingImageLib *`, `is_code:false`, `is_data:false`; remaining three bytes unnamed/untyped; regular/repeatable comments blank; exactly twenty xrefs. The earlier blank-name state is superseded historical evidence. | Gate 2B must reproduce and then preserve all four items, bytes, explicit head name, head type, blank comments, and xrefs field-for-field after target shaping | no change recommended |
| `0x0069b44c` successor | Fresh current-session head/end `0x0069b44c-0x0069b44d`; size1; explicit name `g_pEffectObjImageLib`; type `EffectObjImageLib *`; `is_code:false`; `is_data:false`; regular blank; repeatable blank; exactly twelve xrefs. The earlier blank-name state is superseded historical evidence. | Byte-for-byte and field-for-field unchanged after target shaping, including the explicit name; target item must end exactly at `0x0069b44c` | no change recommended |

### Protected RTTI and vtable no-change rows

No rename, type, comment, reshape, or declaration action is authorized for any row in this table. Fresh current-session `inspect_items`, integer/byte, comment, and xref queries established every row below. Every row defines item-specific dated observed state and the exact protected state expected to remain unchanged. `data dwords` means each physical component is a four-byte `is_data:true`, `is_code:false`, blank-type item unless a name is stated at the logical head.

| Logical entity | Literal current physical state | Required poststate | Supervisor classification |
| --- | --- | --- | --- |
| StaticObjImageLib COL `0x00648d54-0x00648d68` | five data dwords; head name `??_R4StaticObjImageLib@@6B@`; width `0x14`; values `0,0,0,0x00676a8c,0x00648d68`; head regular `signature`, repeatable blank; one xref from `0x0061b700` | exact name, kind, width, values, comments, and xrefs unchanged | no change recommended |
| StaticObjImageLib CHD `0x00648d68-0x00648d78` | four data dwords; head name `??_R3StaticObjImageLib@@8`; width `0x10`; values `0,1,3,0x00648d78`; exact bytes `00 00 00 00 01 00 00 00 03 00 00 00 78 8d 64 00`; second dword is CHD attributes `1`, consistent with multiple inheritance; head regular `signature`, repeatable blank; two xrefs from `0x00648d64` and `0x00648da0` | exact name, kind, width, values, bytes, attributes, comments, and xrefs unchanged | no change recommended |
| StaticObjImageLib base array `0x00648d78-0x00648d84` | three data dwords; head name `??_R2StaticObjImageLib@@8`; width `0x0c`; values `0x00648d88,0x00640348,0x00648da4`; head regular `reference to base class decription 1`, repeatable blank; one xref from `0x00648d74` | exact unchanged | no change recommended |
| alignment dword `0x00648d84-0x00648d88` | unnamed blank-type data dword value zero; both comments blank; zero xrefs | exact unchanged | no change recommended |
| StaticObjImageLib BCD `0x00648d88-0x00648da4` | seven data dwords; head name `??_R1A@?0A@EA@StaticObjImageLib@@8`; width `0x1c`; values `0x00676a8c,2,0,0xffffffff,0,0x40,0x00648d68`; head regular `reference to type description`, repeatable blank; one xref from `0x00648d78` | exact unchanged | no change recommended |
| direct Singleton BCD `0x00648da4-0x00648dc0` | seven data dwords; head name `??_R13?0A@EA@?$Singleton@VStaticObjImageLib@@@@8`; width `0x1c`; values `0x00676aac,0,4,0xffffffff,0,0x40,0x00648dc0`; head regular `reference to type description`, repeatable blank; one xref from `0x00648d80` | exact unchanged | no change recommended |
| Singleton CHD `0x00648dc0-0x00648dd0` | four data dwords; head name `??_R3?$Singleton@VStaticObjImageLib@@@@8`; width `0x10`; values `0,0,1,0x00648dd0`; head regular `signature`, repeatable blank; two xrefs from `0x00648dbc` and `0x00648df0` | exact unchanged | no change recommended |
| Singleton base array `0x00648dd0-0x00648dd4` | one data dword; head name `??_R2?$Singleton@VStaticObjImageLib@@@@8`; width4; value `0x00648dd8`; head regular `reference to base class decription 1`, repeatable blank; one xref from `0x00648dcc` | exact unchanged | no change recommended |
| alignment dword `0x00648dd4-0x00648dd8` | unnamed blank-type data dword value zero; both comments blank; zero xrefs | exact unchanged | no change recommended |
| Singleton self BCD `0x00648dd8-0x00648df4` | seven data dwords; head name `??_R1A@?0A@EA@?$Singleton@VStaticObjImageLib@@@@8`; width `0x1c`; values `0x00676aac,0,0,0xffffffff,0,0x40,0x00648dc0`; head regular `reference to type description`, repeatable blank; one xref from `0x00648dd0` | exact unchanged | no change recommended |
| shared LObject BCD `0x00640348-0x00640364` | seven data dwords; head name `??_R1A@?0A@EA@LObject@@8`; width `0x1c`; values `0x006738c0,0,0,0xffffffff,0,0x40,0x00640364`; head regular `reference to type description`, repeatable blank; exactly 481 inbound data xrefs | exact unchanged | no change recommended |
| StaticObjImageLib type descriptor `0x00676a8c-0x00676aac` | logical width `0x20`; head physical item is size4 data, name `??_R0?AVStaticObjImageLib@@@8`, blank type; bytes encode vftable `0x00635078`, spare zero, and exact descriptor text `.?AVStaticObjImageLib@@`; head regular `reference to RTTI's vftable`, repeatable blank; two xrefs from `0x00648d60` and `0x00648d88` | exact name/range/bytes/kind/type/comments/xrefs unchanged | no change recommended |
| Singleton type descriptor `0x00676aac-0x00676adc` | logical width `0x30`; head physical item is size4 data, name `??_R0?AV?$Singleton@VStaticObjImageLib@@@@@8`, blank type; bytes encode vftable `0x00635078`, spare zero, and the decorated Singleton name; head regular `reference to RTTI's vftable`, repeatable blank; two xrefs from `0x00648da4` and `0x00648dd8` | exact unchanged | no change recommended |
| successor EffectObj COL head `0x00648df4-0x00648df8` | size4 data, name `??_R4EffectObjImageLib@@6B@`, blank type, regular `signature`, repeatable blank; one xref from `0x0061b720` | exact unchanged and remains outside the StaticObjImageLib RTTI range | no change recommended |
| locator pointer `0x0061b700-0x0061b704` | size4 data, name/type blank, value `0x00648d54`, both comments blank, zero xrefs | exact unchanged | no change recommended |
| vtable slot 0 `0x0061b704-0x0061b708` | size4 data, name `??_7StaticObjImageLib@@6B@`, blank type, value `0x004e6990`, both comments blank; three xrefs from `0x004dcfb8`, `0x004dd20b`, and `0x004e69c4` | exact unchanged; total vtable-base xrefs remain three | no change recommended |
| vtable slot 1 `0x0061b708-0x0061b70c` | size4 data, name/type blank, value `0x004f4b10`, both comments blank, zero xrefs | exact unchanged | no change recommended |
| vtable slot 2 `0x0061b70c-0x0061b710` | size4 data, name/type blank, value `0x0041b6c0`, both comments blank, zero xrefs | exact unchanged | no change recommended |
| successor boundary `0x0061b710-0x0061b714` | size4 data, name/type blank, value `0x00648e94`, both comments blank, zero xrefs | exact unchanged and remains outside the vtable | no change recommended |

The complete expected final/protected state preserves the fresh baseline recorded here: exact target bytes/xref count one, singleton-slot xref count thirteen, all function ranges/xrefs/padding, every complete frame row, catalog/type prestates and accepted deltas, all protected xrefs, and StaticObjImageLib CHD values `0,1,3,0x00648d78` with exact bytes `00 00 00 00 01 00 00 00 03 00 00 00 78 8d 64 00`. These literals are report evidence rather than an operational procedure.

Action/claim binding is complete: C184-023 covers the four function names, signatures, one occupied scalar stack row, function-regular comments, complete frames, and zero-collision evidence at very-strong confidence; C184-024 covers the singleton data item and adjacent-row protections at near-certain confidence; C184-025 covers the three UDT declarations, parser-safe packing, canonical unsigned aliases, sizes, members, and catalog protections at very-strong confidence; C184-026 covers every RTTI/vtable/neighbor no-change row at near-certain confidence; and C184-027 preserves the supervisor-only runtime-authority, persistence, and rollback boundary at near-certain confidence. No IDA recommendation is deferred to the removed archive or to first-time Gate 2B discovery.

## First-Draft C++ Recommendation

### UID000184 target formal CPP

Leave the formal CPP body empty. Do not emit a no-code comment, helper function, explicit template destructor specialization, thunk, or marker payload.

### UID000184 target formal H

Leave the formal H body empty. The source cause is represented by the class inheritance declaration.

### UID0000E2 class formal CPP

```cpp
#include "StaticObjImageLib.h"
#include "ImageFrameTable.h"
#include "../util/MemoryMan.h"
#include <stdlib.h>

[[CHILDREN]]
```

### UID0000E2 class formal H

```cpp
#ifndef NEXUSTK_RENDER_STATICOBJIMAGELIB_H
#define NEXUSTK_RENDER_STATICOBJIMAGELIB_H

#include "../util/LObject.h"
#include "../util/Singleton.h"

struct ArchiveMetadataTable;
struct Rect;
struct GrafPort;
struct StaticObjectDrawRequest;

struct TileClassEntry
{
    unsigned short tileFrameId;
    unsigned char allowPaletteFilter;
    unsigned char reserved;
};

#pragma pack(push, 2)
struct StaticObjEntry
{
    int lightImageIndex;
    unsigned char lightHeightClass;
    unsigned char layerCount;
    unsigned short reserved;
    StaticObjEntry *cacheChain;
    unsigned short tileIds[1];
};
#pragma pack(pop)

class StaticObjImageLib : public LObject,
                          public Singleton<StaticObjImageLib>
{
public:
    StaticObjImageLib();
    virtual ~StaticObjImageLib();

    char RenderStaticObject(GrafPort *target,
                            StaticObjectDrawRequest *request,
                            unsigned short staticObjectId,
                            void *overlayBuffer,
                            float overlayAlpha,
                            bool enableBlendClip);
    void GetStaticObjectBounds(unsigned short staticObjectId, Rect *outBounds) const;
    bool HitTestStaticObjectPixel(unsigned short staticObjectId,
                                  int localX,
                                  int localY) const;
    StaticObjEntry *GetStaticObjectEntry(unsigned short staticObjectId) const;

private:
    ArchiveMetadataTable *tileCatalog;
    TileClassEntry *tileClasses;
    StaticObjEntry **staticObjEntries;
    int staticObjCount;
};

extern StaticObjImageLib *g_pStaticObjImageLib;

#endif
```

### UID0000UN shared ImageFrameTable formal CPP

Leave the formal CPP body empty after moving the shared declarations to H. They are type declarations consumed by multiple render translation units, not ImageFrameTable.cpp-local definitions.

### UID0000UN shared ImageFrameTable formal H

```cpp
#ifndef NEXUSTK_RENDER_IMAGEFRAMETABLE_H
#define NEXUSTK_RENDER_IMAGEFRAMETABLE_H

#include "../ui/core/RectBounds.h"

struct PackedArchiveRecord
{
    RectBounds bounds;
    unsigned char *payloadStart;
    unsigned char *payloadEnd;
};

struct ArchiveMetadataTable
{
    unsigned short frameCount;
    unsigned short maxWidth;
    unsigned short maxHeight;
    unsigned short reserved;
    PackedArchiveRecord *records;
};

struct FrameDrawRecord
{
    int reserved0;
    unsigned char *payloadStart;
    int reserved8;
    int width;
    RectBounds sourceRect;
    int payloadSpan;
    unsigned char *payloadEnd;
};

#endif
```

### UID00017I destructor formal CPP

```cpp
StaticObjImageLib::~StaticObjImageLib()
{
    MemoryMan *memoryMan = GetMemoryMan();

    if (staticObjEntries != 0) {
        for (int index = 0; index < staticObjCount; ++index) {
            StaticObjEntry *entry = staticObjEntries[index];
            StaticObjEntry *cacheNode = entry->cacheChain;

            if (cacheNode != 0) {
                entry->cacheChain = 0;

                while (cacheNode != 0) {
                    StaticObjEntry *nextNode = cacheNode->cacheChain;
                    memoryMan->FreeBufferMemory(cacheNode);
                    cacheNode = nextNode;
                }
            } else {
                memoryMan->FreeBufferMemory(entry);
            }
        }

        memoryMan->FreeBufferMemory(staticObjEntries);
    }

    ArchiveMetadataTable *catalog = tileCatalog;
    MemoryMan *catalogMemoryMan = GetMemoryMan();
    if (catalog->records != 0) {
        catalogMemoryMan->FreeBufferMemory(catalog->records);
    }
    catalogMemoryMan->FreeBufferMemory(catalog);

    free(tileClasses);
}
```

The compiler supplies reverse base destruction: first `Singleton<StaticObjImageLib>` clears the global, then `LObject` tears down. Do not call either base destructor explicitly. The two `GetMemoryMan()` acquisitions, unconditional `tileCatalog` dereference, conditional `records` free, unconditional catalog free, and final CRT `free(tileClasses)` preserve the measured call/branch order. `MemoryMan::FreeBufferMemory` is the accepted project API at `0x00516170`; `MemoryManager` and `Free` are rejected non-project spellings.

### UID0000SD global formal CPP

```cpp
StaticObjImageLib *g_pStaticObjImageLib = 0;
```

The declaration is already present in the complete UID0000E2 H payload. UID0000SD H therefore remains blank to avoid a duplicate declaration fragment.

### Compiler-support formal channels

- UID0003M2 scalar wrapper: blank CPP and blank H.
- UID0001PP physical storage: blank CPP and blank H.
- UID0001YX vtable/RTTI type page: blank CPP and blank H.
- No C++ appears in any other report section.
- Eligible source-bearing payloads: UID0000E2 receives the class/local-type/global-declaration H and dependency-complete CPP route, UID0000UN receives the shared ImageFrameTable H declaration block with blank CPP, UID00017I receives the authored destructor CPP body, and UID0000SD receives the sole global CPP definition. UID000184 itself is not eligible for an independent source body.
- Behavior-equivalence rationale: the class's direct `Singleton<StaticObjImageLib>` base regenerates constructor publication, EH-state destruction, ordinary reverse-order clear, and scalar-wrapper clear while the corrected authored destructor preserves both observed MemoryMan acquisitions, cache-chain branching, unconditional archive-table dereference/free behavior, and final CRT tile-class release. The sole zero global definition preserves loader and lifecycle state without duplicate storage.
- Historical-source-shape rationale: a human developer would express this mechanism through multiple inheritance, an ordinary virtual destructor, private typed members, and one `extern`/definition pair. Emitting a clear helper, vtable array, scalar wrapper, explicit base-destructor calls, or proof comments would reproduce compiler artifacts rather than plausible original source.
- Inferred-name/type/field rationale: `StaticObjImageLib`, `TileClassEntry`, `StaticObjEntry`, `g_pStaticObjImageLib`, `lightImageIndex`, and the typed pointer/count members are selected from subsystem usage, table strides, signed-sentinel flow, constructor/destructor consumers, and existing project vocabulary. Raw labels such as `sub_4E5C00` and `unk_69B448` are intentionally excluded.
- Naming/style consistency: class/type names use established PascalCase, the singleton uses the established `g_p` pointer prefix, members use lower camel case, null uses `0`, and braces/declarations follow surrounding reconstructed mid-2000s project style. Exact behavior and human source shape take priority over stylistic uniformity.
- Third-party import directive: not applicable; all payloads are project-owned NexusTK source reconstruction.
- Exact UID000184 no-code proof: its sole EH-only call with ECX adjusted to the direct Singleton base, RTTI PMD/EBO identity, inlined ordinary/scalar copies, and absence of every authored route prove the retained body is compiler output regenerated by the class declaration.

## Final Recommendation

- Accept the direct `Singleton<StaticObjImageLib>` source model as resolved, not provisional. Ordinary implementation proof for the original lifecycle work is the exact recorded target/support state and historical B005 commands `000000022285` through `000000022296`, with later valid UID0000E2 command `000000022436`. C184-029 is now applied across its five ordinary destinations under commands `000000022553` through `000000022557`, with exact physical hashes in Sections 31-32; independent Gate 2A acceptance remains supervisor-authoritative and intentionally is not encoded as a current report state.
- UID000184 final disposition: current renamed path `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md`, `94/97`, `CANONICAL_OWNER:0000E2`, `RECONSTRUCTABLE:FALSE`, blank emitters/position, `Nested:0`, and blank CPP/H. The body is generated from class inheritance and receives no independent source emission.
- Parent/source route: UID0000E2 remains owned/emitted by file UID0000O7 and supplies the direct-base class H plus CPP child expansion; UID00017I remains owned/emitted by UID0000E2 and supplies the authored derived destructor; UID0000SD remains owned/emitted by UID0000O7 and supplies the sole zero global definition.
- No-owner/non-emitting dispositions: UID00017H remains owner `NONE`, false, and non-emitting as an aggregate index; UID0003M2 remains semantically class-owned but false/non-emitting compiler scalar support; UID0001PP remains semantically global-owned but false/non-emitting physical storage; UID0001YX and UID0002OY remain class-owned compiler vtable/RTTI support with no handwritten source.
- Exact generated-source disposition: the compiler must regenerate singleton publication/clear, EH cleanup, scalar deletion, vtable/RTTI, and ABI support from the class declaration and authored destructor. No explicit target helper, global-clear statement, vtable array, wrapper body, or proof marker belongs in source.
- Stable supervisor boundary: C184-015 through C184-021 and C184-030 supply exact manual-coverage text, C184-022 supplies coherent post-C184-029 generated acceptance criteria, and C184-023 through C184-027 supply exact Gate 2B actions, fresh literal prestates, protections, stop conditions, and readbacks. These rows remain `incorporate`/`proposed` and unchecked because only the supervisor can apply or verify them. Commands through generated 23008 and tracker 23015 are superseded dated snapshots. Dated generated command 23042 and tracker command 23045 carry the exact hashes/sizes/lines in C184-022 only as snapshot evidence; every later gate dynamically rereads physical state and receives no B005 or supervisor implementation credit from those snapshots.
- C184-024's data handoff records one final source-quality state: a four-byte `g_pStaticObjImageLib` item with exact pointer type, semantic repeatable comment, bytes, xrefs, and neighbor protections. The dated unsaved diagnostic explains endpoint feasibility but supplies no current execution state or procedure.
- C184-025 separates human source spelling from analysis readback: conventional C source spellings remain authoritative for reconstruction, while only the exact `unsigned __int8`/`unsigned __int16` canonical aliases listed in Section 21 are acceptable IDA readbacks. Canonical retry2 and scratch outcomes are dated no-credit feasibility evidence.
- Work outside this assignment: a separately allocated constructor child could document `0x004dcf60-0x004dd1d8`, and original PDB/source/MAP/object data could recover private spellings or compiler bookkeeping. Neither can change UID000184 ownership, no-code disposition, formal channels, or `94/97` score.
- Do not treat absence of original debug names as a reason to retain raw labels; use the evidence-backed human names in this report. Apply structured IDA recommendations only through supervisor Gate 2B.

## Recommended Target Doc Changes

- Historical callback change: rename the file to `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md` while preserving UID000184 and change the title to `0x004e5c00-0x004e5c0b StaticObjImageLib Singleton Base Destructor`.
- Historical callback metadata transition: `86/91`, owner/emitter `0000O7`, `RECONSTRUCTABLE:TRUE`, blank emitter position, `Nested:0`, nonblank CPP proof comment, and blank H became current `94/97`, owner `0000E2`, `RECONSTRUCTABLE:FALSE`, blank emitters/position, preserved `Nested:0`, and blank CPP/H.
- Current post-callback target prose contains the exact direct-base-destructor conclusion, full EH state, RTTI/PMD/EBO proof, ordinary/scalar inlining, startup/shutdown exclusion, pointer/import negatives, exact frames/comments, sibling pattern, historical rejected helper interpretation, and compiler-emitted/no-handwritten-source item summary. No new target-page edit is introduced by C184-029; that correction is confined to source-bearing support pages.

## Recommended Support Doc Changes

- [UID:0000E2] `by-class/StaticObjImageLib.md`: historical `88/89`, CPP class declaration, blank H became current `92/96`, owner/emitter `0000O7`, true, blank position, dependency-complete CPP owning-header/children route, and complete H; by-class Nested is schema-inapplicable. C184-029 preserves metadata/H and supplies `ImageFrameTable.h`, `MemoryMan.h`, and `<stdlib.h>` before children.
- [UID:0000O7] `by-file/StaticObjImageLib.md`: historical `88/88` became current `90/94`, owner `FILE`, blank formal channels, with by-file reconstructable/emitter/position/Nested fields schema-inapplicable. Current prose records the complete lifecycle/source root and C184-029 dependency/header relationship.
- [UID:00017H] local cluster: historical `86/91` became current `90/95`, owner `NONE`, false, blank emitter/position, `Nested:-4`, blank CPP/H, with corrected inventory/bases/range/lightImageIndex semantics. Preserve all current state and add the corrected authored-destructor API/dependency note.
- [UID:00017I] destructor: historical `87/91` became current `92/96`, owner/emitter `0000E2`, true, blank position, `Nested:0`, nonblank CPP, blank H. Current CPP is Section 22's corrected `MemoryMan::FreeBufferMemory` body with both manager acquisitions and exact unconditional catalog behavior; metadata and implicit base destruction remain preserved.
- [UID:0003M2] scalar: historical `85/90`, true/emitting became current `93/97`, owner `0000E2`, false, blank emitters/position, `Nested:0`, blank CPP/H, with exact compiler-wrapper behavior. Preserve unchanged.
- [UID:0000SD] global: historical `88/91` became current `92/96`, owner/emitter `0000O7`, true, blank position, one CPP definition, blank H, with by-global Nested schema-inapplicable. Preserve unchanged.
- [UID:0001PP] storage: historical `88/91`, true/emitting with CPP proof comment became current `93/97`, owner `0000SD`, false, blank emitters/position, `Nested:0`, blank CPP/H, zero initialization, and protected neighbors. Preserve unchanged.
- [UID:0001W9] layout: historical `85/88` became current `92/97`, owner/emitter `0000E2`, true, blank position/formal channels, with by-struct Nested schema-inapplicable and exact PMD/EBO/0x14/no-fake-member proof. Preserve unchanged.
- [UID:0001YX] vtable: historical `85/90`, true/emitting became current `92/97`, owner `0000E2`, false, blank emitters/position/formal channels, with by-vtable Nested schema-inapplicable and exact compiler-data disposition. Preserve unchanged.
- [UID:0001W8] `StaticObjEntry`: historical `85/88` became current `90/94`, owner/emitter `0000E2`, true, blank position/formal channels, by-struct Nested schema-inapplicable, class-H ownership, and signed `lightImageIndex +0x00`. Preserve unchanged.
- [UID:0001WC] `TileClassEntry`: historical `85/88` became current `90/95`, owner/emitter `0000E2`, true, blank position/formal channels, by-struct Nested schema-inapplicable, and exact class-H ownership. Preserve unchanged.
- [UID:0000UN] `by-item/EPFArchiveMetadataTable.md`: current `90/92`, owner/emitter `0000K1`, true, blank position, blank CPP, and exact Section 22 declarations in H so every consumer receives one shared definition.
- [UID:0000K1] `by-file/ImageFrameTable.md`: current `91/89`, owner `FILE`, blank formal channels, with by-file reconstructable/emitter/position/Nested fields schema-inapplicable. Current source-placement prose records explicit `ImageFrameTable.h` generation through UID0000UN H while method bodies remain on exact children.
- Preserve exact old assumptions as history rather than deleting them.

## Score And Metadata Recommendation

| UID | Score historical/current -> accepted/recommended | Owner historical/current -> accepted/recommended | Reconstructable historical/current -> accepted/recommended | Emitters historical/current -> accepted/recommended | Position historical/current -> accepted/recommended | Nested historical/current -> accepted/recommended | Formal historical/current -> accepted/recommended | Target-specific rationale |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 000184 | 86/91 historical -> 94/97 current | 0000O7 historical -> 0000E2 current | TRUE historical -> FALSE current | 0000O7 historical -> blank current | blank -> blank | 0 -> 0 | four-line CPP proof comment / blank H historical -> blank CPP/H current | Behavior, range, EH liveness, ownership, and source cause are closed. Completion stops at 94 because no original compiler symbol/PDB or linker COMDAT record survives to distinguish the exact internal destructor-instantiation spelling/linkage. Confidence stops at 97 because identity is convergent RTTI/EH/codegen inference rather than recovered source/debug identity. |
| 0000E2 | 88/89 historical -> 92/96 current | 0000O7 -> 0000O7 | TRUE -> TRUE | 0000O7 -> 0000O7 | blank -> blank | schema n/a -> schema n/a | historical CPP class / blank H -> current dependency-complete CPP children route / full H | Current hierarchy/layout/lifecycle and C184-029 compile-required shared/archive and MemoryMan includes are accepted without score/routing change. |
| 0000O7 | 88/88 historical -> 90/94 current | FILE -> FILE | schema n/a -> schema n/a | schema n/a -> schema n/a | schema n/a -> schema n/a | schema n/a -> schema n/a | blank CPP/H -> blank CPP/H | Lifecycle placement and C184-029 dependency/source-placement prose are closed while unrelated whole-file method debt remains. |
| 00017H | 86/91 historical -> 90/95 current/recommended | NONE -> NONE | FALSE -> FALSE | blank -> blank | blank -> blank | -4 -> -4 | blank CPP/H -> blank CPP/H | Exact non-emitting inventory with direct-base lifecycle; add corrected destructor dependency/API cross-reference without score change. |
| 00017I | 87/91 historical -> 92/96 current | 0000E2 -> 0000E2 | TRUE -> TRUE | 0000E2 -> 0000E2 | blank -> blank | 0 -> 0 | historical defective authored CPP / blank H -> current corrected Section 22 authored CPP / blank H | Derived cleanup and implicit bases are exact; C184-029 fixes API spelling, complete-type visibility, second accessor call, and unsupported null guard without inflating score. |
| 0003M2 | 85/90 historical -> 93/97 current | 0000E2 -> 0000E2 | TRUE historical -> FALSE current | 0000E2 historical -> blank current | blank -> blank | 0 -> 0 | blank CPP/H -> blank CPP/H | Exact compiler deleting wrapper. |
| 0000SD | 88/91 historical -> 92/96 current | 0000O7 -> 0000O7 | TRUE -> TRUE | 0000O7 -> 0000O7 | blank -> blank | schema n/a -> schema n/a | one CPP definition / blank H -> same | Exact slot, lifecycle, and consumers. |
| 0001PP | 88/91 historical -> 93/97 current | 0000SD -> 0000SD | TRUE historical -> FALSE current | 0000SD historical -> blank current | blank -> blank | 0 -> 0 | CPP proof comment / blank H historical -> blank CPP/H current | Exact physical storage support. |
| 0001W9 | 85/88 historical -> 92/97 current | 0000E2 -> 0000E2 | TRUE -> TRUE | 0000E2 -> 0000E2 | blank -> blank | schema n/a -> schema n/a | blank CPP/H -> blank CPP/H, covered by class H | Exact storage plus EBO hierarchy. |
| 0001YX | 85/90 historical -> 92/97 current | 0000E2 -> 0000E2 | TRUE historical -> FALSE current | 0000E2 historical -> blank current | blank -> blank | schema n/a -> schema n/a | blank CPP/H -> blank CPP/H | Compiler vtable/RTTI data regenerated from class. |
| 0001W8 | 85/88 historical -> 90/94 current | 0000E2 -> 0000E2 | TRUE -> TRUE | 0000E2 -> 0000E2 | blank -> blank | schema n/a -> schema n/a | blank CPP/H -> blank CPP/H, declaration in class H | Exact variable-tail layout and consumers; UID00023D proves signed `lightImageIndex +0x00`. |
| 0001WC | 85/88 historical -> 90/95 current | 0000E2 -> 0000E2 | TRUE -> TRUE | 0000E2 -> 0000E2 | blank -> blank | schema n/a -> schema n/a | blank CPP/H -> blank CPP/H, declaration in class H | Exact four-byte layout and consumers. |
| 0000UN | 88/91 historical -> 90/92 current | 0000K1 -> 0000K1 | TRUE -> TRUE | 0000K1 -> 0000K1 | blank -> blank | schema n/a -> schema n/a | historical declarations in CPP / blank H -> current blank CPP / declarations in H | Shared ABI and consumers are accepted; moving the block to H resolves complete-type visibility while inferred original names retain the confidence cap. |
| 0000K1 | 90/88 historical -> 91/89 current | FILE -> FILE | schema n/a -> schema n/a | schema n/a -> schema n/a | schema n/a -> schema n/a | schema n/a -> schema n/a | blank CPP/H -> blank CPP/H | File root remains metadata-only; explicit sibling H generation through UID0000UN closes source placement without duplicating declarations. |

- No code-emitting item exceeds the 95 completion barrier.
- Confidence above 95 is justified for exact compiler artifacts and directly measured layout/lifecycle facts, not original private spelling.

## Open Questions With Attempted Resolution

- Was this a source-authored clear helper? Resolved no: adjusted EH receiver, RTTI, inlined base destruction, and zero authored routes prove compiler support.
- Was this an `atexit` or static-registration callback? Resolved no: explicit startup/shutdown plus zero import/pointer routes reject it.
- What is the source name? Resolved as no authored function name. `StaticObjImageLib_SingletonBaseDestructor` is an IDA/documentation label for compiler output only.
- Does the Singleton base consume storage? Resolved no independent storage: PMD `+4,-1,0` and 0x14 allocation show EBO overlap with the first derived member.
- Should the authored destructor clear the global? Resolved no: the compiler's reverse base destruction does it after the derived body.
- Should the target emit a comment? Resolved no: final generated source should contain human source only; the ordinary documentation carries the no-code proof.
- Is `StaticObjEntry +0x00` an intensity or image index? Resolved as signed `int lightImageIndex`. Current UID00023D decompilation uses negative as the no-light sentinel, forwards the unchanged dword to the `LightingObjectPane` constructor's final argument, and forwards it to `SetLightImageIndex`; the setter compares and stores `m_lightImageIndex`. `lightIntensity` remains only as a superseded historical interpretation and must not appear in the active H or IDA UDT declaration.
- Is the destructor's memory API `MemoryManager::Free`? Resolved no. Current [UID:00007U] class H declares `MemoryMan`, [UID:0001BC] declares `MemoryMan *GetMemoryMan()`, and [UID:0001BF] formally defines `void *MemoryMan::FreeBufferMemory(void *buffer)` for the exact `0x00516170` callee. `MemoryManager` and `Free` are non-project placeholders and must not survive in formal or generated source.
- May source guard `tileCatalog` before dereferencing it? Resolved no. The measured ordinary destructor copies `tileCatalog`, obtains a second `MemoryMan` pointer, dereferences `catalog->records` unconditionally, conditionally frees that records pointer, then unconditionally frees the catalog. Adding an outer null guard changes crash behavior and branch structure; Section 22 intentionally preserves the unsafe original contract.
- Where must `ArchiveMetadataTable` be complete? Resolved in shared `ImageFrameTable.h`, emitted through [UID:0000UN]/[UID:0000K1]. StaticObjImageLib H needs only a pointer declaration, but StaticObjImageLib CPP and its `BuildTilecArchiveTable`/destructor children dereference/allocate the type and therefore include the common header. Leaving the accepted declarations in ImageFrameTable CPP or duplicating them locally would not provide one coherent source-visible type.
- Which live IDB state supplies the literal prestate evidence? Resolved. The fresh physical disk snapshot is SHA256 `53B60FCF7C42327C9E03D90A407903D4EFF15510FEE791F2452EF0B2036A05D9`, `143,206,875` bytes, mtime `2026-08-13T07:09:07.5603942-04:00`. Public runtime attestation succeeded at `2026-08-13T11:38:46.695504+00:00` for canonical-path session `supervisor-uid0004HB-gate2b-20260813T1105Z`, and fresh bounded reads on that session supply every literal Section 21 prestate. Earlier B8C1/1,016/blank-neighbor states are superseded dated evidence. This current evidence is not permanent mutation/save authority; current-runtime handling remains supervisor-owned outside the report.
- Can the singleton item support the intended final pointer type? Resolved yes. A dated unsaved diagnostic produced the final four-byte name/shape and demonstrated that `StaticObjImageLib *` is accepted. The diagnostic is feasibility evidence only; Section 21 records the intended final state without an operational sequence.
- Are `unsigned short`/`unsigned char` required as literal IDA readback spellings? Resolved no. They remain the intended human source spellings, while current `type_inspect` deterministically renders the same widths/signedness as `unsigned __int16`/`unsigned __int8`. Only those exact member-specific aliases are accepted; names, offsets, widths, array count, structure size, and all pointer/int types must still match literally.
- Can the analysis declaration preserve the packed size? Resolved yes. Isolated scratch evidence proves a parser-compatible analysis declaration produces size 14, while formal source H remains conventional human C++ with `#pragma pack(push, 2)`. The report does not prescribe the transaction used to install it.
- Is exact original member spelling known? No debug symbols survive, but the accepted project names are high-probability human names supported by roles and neighboring style. This is not a valid reason to retain raw labels or block first-draft source.
- Does the absence of a separately split constructor page prevent this target conclusion? Resolved no. The complete constructor range `0x004dcf60-0x004dd1d8`, binary body, caller, and EH states are directly measured inside UID00017H; UID0000E2 owns the constructor declaration and the direct-Singleton source cause. UID000184 neither overlaps that range nor emits constructor source, so no split is required by this target's range, ownership, emitter, or no-code disposition.
- Residual original-spelling impact: available function names, RTTI, strings, xrefs, decompilation, sibling vocabulary, and ordinary documentation were exhausted without recovering private source identifiers. Only original PDB/source, MAP, object, or equivalent debug/build artifacts could prove them. This residual caps confidence exactly as shown in Section 26, including UID000184 at `97` and `StaticObjEntry` at `94`; it does not lower completion, alter formal C++, or reopen owner/emitter/source-placement decisions.
- Constructor split/range impact: closed for this report. UID00017H already owns the exact half-open constructor range and complete local inventory, UID0000E2 owns the human class declaration/source cause, and UID000184 owns only the disjoint retained base-destructor body. Creating a separate constructor page would be an independent coverage-granularity decision, not missing evidence or a prerequisite for UID000184; it therefore has zero impact on this target's `94/97`, class ownership, false reconstructability, blank emitters, and blank formal CPP/H.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

These exact rows are stable supervisor-owned incorporation payloads. Supervisor process order places their application after ordinary callback validation; replace existing rows in place unless an insertion location is stated. This report does not encode whether application has occurred.

### by-memory target row

>     - [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md) 0x004e5c00-0x004e5c0b | source-declared/generated-binary base destructor | Singleton<StaticObjImageLib> base destructor : not_reconstructable : 94% : near-certain : Exact eleven-byte EH-only direct empty-base destructor instantiation with sole constructor state-1 tail-jump after ECX plus four adjustment, direct Singleton<StaticObjImageLib> RTTI PMD +0x04 and EBO identity, ordinary/scalar inlined copies, thirteen singleton-slot refs, exhaustive no-atexit/no-pointer/no-helper proof, semantic class owner UID0000E2, and blank non-emitting formal CPP/H.

### by-memory support rows

>     - [UID:00017H][0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster](by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md) 0x004dcf60-0x004ddf60 | non-emitting class method index | StaticObjImageLib local source/compiler island : not_reconstructable : 90% : near-certain : Exact constructor-through-loader local inventory with authored children, state-zero LObject and state-one Singleton<StaticObjImageLib> EH cleanup, direct RTTI/PMD/EBO hierarchy, separately ranged UID000184 base destructor and UID0003M2 scalar wrapper, exact padding, and no duplicate aggregate source.
>     - [UID:00017I][0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md) 0x004dd1e0-0x004dd2be | ordinary destructor | StaticObjImageLib::~StaticObjImageLib : reconstructable : 92% : near-certain : Exact authored derived cleanup for variable StaticObjEntry records/cache chains, archive metadata, and TileClassEntry storage through MemoryMan::FreeBufferMemory and final CRT free; preserves two GetMemoryMan acquisitions, unconditional tileCatalog dereference, conditional records free, unconditional catalog free, and intentionally omits vptr/EH machinery and direct global clear because reverse implicit Singleton<StaticObjImageLib> then LObject base destruction regenerates the measured tail.
>     - [UID:0001PP][0x0069b448-0x0069b44c.g_pStaticObjImageLib](by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md) 0x0069b448-0x0069b44c | physical singleton storage | g_pStaticObjImageLib backing slot : not_reconstructable : 93% : near-certain : Exact four-byte loader-zero storage with bytes 00 00 00 00, thirteen constructor/destructor/shutdown/render consumer refs, adjacent singleton boundaries, direct Singleton<StaticObjImageLib> publication/clear cause, sole semantic definition through UID0000SD, and no duplicate CPP/H emission.

Insert the following UID0003M2 row immediately after the existing UID0002Y4 Riding scalar row and before the `0x004e6aa6-0x004e6ab0` ignored padding row:

>     - [UID:0003M2][0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor](by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md) 0x004e6990-0x004e6aa6 | compiler scalar deleting destructor | StaticObjImageLib deleting support : not_reconstructable : 93% : near-certain : Exact vtable-only compiler wrapper with full authored-destructor parity, inlined reverse Singleton<StaticObjImageLib> clear, LObject teardown, flags 1/4 predicate, optional storage deletion, receiver return, 0x14 delete-size evidence, class owner UID0000E2, and blank formal CPP/H generated from the virtual ordinary destructor.

### by-class row

> - [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) : reconstructable : 92% : near-certain : Complete StaticObjImageLib H declaration with direct LObject and Singleton<StaticObjImageLib> bases, PMD +0x04 EBO, exact 0x14 storage, TileClassEntry and variable-tail StaticObjEntry declarations including signed lightImageIndex +0x00, extern singleton contract, dependency-complete CPP child expansion through StaticObjImageLib.h, ImageFrameTable.h, MemoryMan.h, and CRT declarations, exact authored destructor source, constructor EH publication/clear, scalar/vtable/compiler exclusions, and render/resource method surface through StaticObjImageLib.cpp.

### by-file row

> - [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) : reconstructable : 90% : very-strong : Static object image library projected to NexusTK/render with complete class/header source shape, SOBJ/TILEC resources, shared ImageFrameTable archive declarations, MemoryMan and CRT dependencies, signed StaticObjEntry lightImageIndex semantics, singleton definition, constructor/direct-Singleton lifecycle, exact authored destructor and method children, UID000184 EH-only base-destructor exclusion, UID0003M2 scalar-wrapper exclusion, vtable/RTTI/layout/global routes, and remaining broader renderer/helper polish separated from the resolved lifecycle.

### shared ImageFrameTable by-item and by-file rows

> - [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md) : reconstructable : 90% : near-certain : Shared ImageFrameTable.h declaration block for PackedArchiveRecord, ArchiveMetadataTable, and FrameDrawRecord, with exact 0x18 packed-record, 0x0c table, and 0x28 draw-record layouts tied to loader/projection/sentinel/destructor evidence; CPP remains blank, H includes RectBounds, StaticObjImageLib and other render consumers receive one complete source-visible ABI, and inferred original type/field spellings remain the bounded confidence cap.
> - [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) : reconstructable : 91% : very-strong : Shared NexusTK/render ImageFrameTable.cpp/ImageFrameTable.h module with exact loader, destroy, frame-record helper, and resource-layout boundaries; UID0000UN emits the common archive/draw declarations through H, exact by-memory children retain method/helper bodies, MemoryMan and RectBounds dependencies are explicit, and unrelated raw-helper linkage/name uncertainty remains documented without duplicating declarations in consumer files.

### by-global row

> - [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md) : reconstructable : 92% : near-certain : Sole zero source definition for the StaticObjImageLib singleton at exact physical child UID0001PP; thirteen live refs cover direct Singleton construction publication/null handling, constructor-unwind clear, implicit ordinary/scalar clears, shutdown, and map/static-object/photo consumers, with extern declaration in the complete class H and no sentinel or duplicate storage emission.

### by-struct rows

> - [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md) : reconstructable : 90% : very-strong : Exact packed minimum 0x0e variable-tail SOBJ record declared once in StaticObjImageLib H, with signed lightImageIndex +0x00 proven by unchanged flow into LightingObjectPane construction and SetLightImageIndex, lightHeightClass +0x04, layerCount +0x05, reserved +0x06, cacheChain +0x08, tileIds +0x0c, allocation as offsetof plus two times layerCount, constructor/render/bounds/destructor/ObjectList consumers, and historical lightIntensity explicitly rejected.
> - [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md) : reconstructable : 92% : near-certain : Exact 0x14 class storage with LObject/vptr +0x00, direct empty Singleton<StaticObjImageLib> PMD +0x04 EBO overlap, tileCatalog +0x04, tileClasses +0x08, staticObjEntries +0x0c, staticObjCount +0x10, and constructor/destructor/render/bounds/RTTI agreement; no fake Singleton field.
> - [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md) : reconstructable : 90% : near-certain : Exact four-byte type declared once in StaticObjImageLib H with tileFrameId +0x00, allowPaletteFilter +0x02, reserved +0x03, and TILEC parser, renderer four-byte stride, and destructor ownership evidence.

### by-vtable row

> - [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md) : not_reconstructable : 92% : near-certain : Exact compiler vtable/RTTI support for StaticObjImageLib with COL 0x00648d54, three slots at 0x0061b704, scalar deleting wrapper first, complete hierarchy entries for StaticObjImageLib, LObject, and direct Singleton<StaticObjImageLib> PMD +0x04 EBO, constructor/destructor/scalar xrefs, exact UID0002OY data child, and blank formal CPP/H regenerated from the class declaration.

No direct manual edit to `auto-generated/-ag-research-tracker.md` is permitted. Validator execution owns the target's covered-state refresh.

## Follow-Up Actions

1. Exact-artifact Gate 1 review is supervisor-authoritative and precedes Gate 2 or lifecycle action; this report does not assert the current gate result.
2. Historical callback fact: B005 implemented C184-001 through C184-014 and C184-028 with JIT edit leases, scoped no-generated-refresh validators, and physical readback.
3. Gate 2A claim-by-claim verification of the exact changed artifacts and receipts is a supervisor-owned process boundary whose current result is external to this report.
4. Historical callback fact: after supervisor Gate 1 and the explicit implementation callback, B005 applied C184-029 to all five ordinary destinations, ran scoped no-generated-refresh validators, and physically reread their formal/source-placement content and hashes.
5. C184-015 through C184-021 and C184-030 contain complete exact manual-coverage incorporation text; application and validation are supervisor-owned and not represented as pending or complete here.
6. C184-023 through C184-027 contain complete declarative IDA prestates, intended outcomes, protections, expected readbacks, parser-feasibility evidence, and exact human-to-canonical alias rules. Runtime operations and IDA application state are supervisor-owned and not represented here.
7. C184-022 contains the post-C184-029 coherent generated-refresh acceptance contract for shared H, StaticObjImageLib CPP/H, target exclusion, destructor inclusion, coverage, and tracker readback; execution state is supervisor-owned and not represented here.
8. Report execution/archive truth is authoritative only from the current path plus validator-owned metadata.

## Confidence

- Binary behavior and range: 100 percent.
- EH liveness and adjusted receiver: 100 percent.
- Direct Singleton base identity and EBO: greater than 99 percent.
- Compiler-generated base-destructor disposition: greater than 99 percent.
- No static registration or authored helper: greater than 99 percent after bounded route searches.
- Human source hierarchy and removal of explicit destructor clear: near-certain.
- Shared `StaticObjEntry::lightImageIndex +0x00` role and source name: near-certain. The current UID00023D signed-sentinel branch and unchanged constructor/setter flow prove image-table index semantics; only exact original spelling remains inferential, and `lightImageIndex` is the strongest subsystem-consistent human name.
- Exact original private spellings: not recoverable from current symbols, but evidence-backed human names are sufficiently strong for source-quality reconstruction and are preferred over raw labels.
- Current-state confidence: fresh runtime-attested canonical-session reads prove the exact four function ranges/names/prototypes/frames/comments/xrefs, zero proposed-name collisions, the raw singleton slot with blank stored target name/generated-only `unk_69B448`, explicit protected neighbor names, exact 13/20/12 xrefs, all six type prestates, catalog total 1,020 with identified ordinals 1017-1020, and every protected RTTI/vtable row. Independent bytes and u32le reads reproduce StaticObjImageLib CHD `0,1,3,0x00648d78`, with attributes `1` matching multiple inheritance. The current physical disk snapshot is 53B60F; no literal prestate is left undiscovered. Historical B8C1, A95C, `1B8E...`, and `20DEC...` evidence remains explicit history.
- UDT-contract confidence: fresh current-session reads prove all three proposed UDTs absent and all three dependencies opaque; canonical retry2 proves TileClassEntry canonical aliases, while isolated scratch proves the comma-free packing payload, StaticObjEntry size-14 six-member layout, and StaticObjImageLib size-20 five-member layout. Both unsaved test environments were discarded. Gate 2B must reproduce the recorded absence/catalog literals and exact deterministic poststates; it does not perform first-time research.
- Recommended target score: `94/97`.

## Validator Results

- Historical ordinary callback commands used the scoped form from `source-3/project-documentation`: `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240 --no-generated-refresh`.
- Every ordinary receipt command below exited `0`, returned `ok: 1`, and explicitly reported generated refresh skipped. Each destination was then physically reread and hashed; older receipts are historical evidence, while command `000000022554` and its resulting hash are the current ordinary UID0000E2 receipt identity.
- No validator was run during this report-only repair because no ordinary by-* destination changed. Under the explicit C184-029 callback, B005 previously ran five scoped `--no-generated-refresh` validators; all exited `0`, returned `ok: 1`, explicitly skipped generated refresh, and were followed by physical content/hash reread. All fourteen ordinary destination hashes remain recorded in Sections 31-32. Commands through generated 23008 and tracker 23015 are historical. Dated generated command 23042 and tracker command 23045 produced the exact physical snapshot identities in C184-022; they are validator-owned snapshot evidence without B005 or supervisor implementation credit and cannot substitute for later dynamic reread. C184-022 and C184-030 remain supervisor-owned generated/tracker/manual validation boundaries.
- No validator was run for this UDT request/readback repair. The canonical retry2 and isolated scratch evidence were unsaved IDA trials, not validator or implementation receipts; the ordinary validator table and all destination identities remain unchanged.
- No validator was run for the IDA-prestate repair. Historical session `supervisor-uid000184-gate2b-20260812T2054Z` stopped before mutation after exact bytes/u32le reads disproved the old second CHD dword. This repair's fresh runtime-attested canonical-session pass performed only bounded reads, supplied the complete current 53B60F preparation baseline, and made no IDA mutation/save. Gate 2B must independently reattest and reproduce the current blank stored target name, explicit neighbor names, 1,020-entry type catalog, and every other literal before mutation.

| Command ID | Timestamp | Destination | Exit / ok | Post-validator SHA256 |
| --- | --- | --- | --- | --- |
| `000000022285` | `2026-08-11T15:44:08-04:00` | `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md` | `0 / 1` | `404C40DD098A53A3B26046B78AD529D6D3445EA62F586216633336CF57C50A06` |
| `000000022286` | `2026-08-11T15:44:12-04:00` | `by-class/StaticObjImageLib.md` | `0 / 1` | `B1DC9EE6071B3917415238707E51EF4B5817DBE7B2254DD7EEE5EBAE159E82AA` |
| `000000022436` | `2026-08-11T19:30:10-04:00` | `by-class/StaticObjImageLib.md` historical additive owning-header remediation incorporated into later UID0000E2 content | `0 / 1` | `0D036C1E88AE932A925475BF02B9F40E798AB89DEBB13CD03490DEABB8A03D14` |
| `000000022287` | `2026-08-11T15:44:14-04:00` | `by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md` | `0 / 1` | `BB3926EB9E96B433703345CADB391958590048AAC826A550193D730B9E1BF5E8` |
| `000000022288` | `2026-08-11T15:44:16-04:00` | `by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md` | `0 / 1` | `DFC8800D47EE1AEE57508E71875A5EB5E1A704D90D20E3D2B095D10472DD1695` |
| `000000022289` | `2026-08-11T15:44:19-04:00` | `by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md` | `0 / 1` | `7484661816E3D72199889E8F44151CA11F8D0F3B988B175DC16A2475CEEAC804` |
| `000000022290` | `2026-08-11T15:44:21-04:00` | `by-file/StaticObjImageLib.md` | `0 / 1` | `55BDB10D5DD0E8BE990AD865EC62C2175F03FFE10D0645D157435B02122242A8` |
| `000000022291` | `2026-08-11T15:44:23-04:00` | `by-global/g_pStaticObjImageLib.md` | `0 / 1` | `DBC0FB5811C056CBCAD52CEF9088753F3A1FF4E6CFD247CBEE415F06668C4FDE` |
| `000000022292` | `2026-08-11T15:44:25-04:00` | `by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md` | `0 / 1` | `0F6BD0A7DD634AAFC70CE252B1C4E31F876EA67E709E0E8BE782FE850CCEC48A` |
| `000000022293` | `2026-08-11T15:44:27-04:00` | `by-type/by-struct/StaticObjImageLibLayout.md` | `0 / 1` | `98D8714CE9CE48AEA61882123D93BF082D91E2A1331D6414B690EF508BC06905` |
| `000000022294` | `2026-08-11T15:44:30-04:00` | `by-type/by-vtable/StaticObjImageLibVtable.md` | `0 / 1` | `EE18EBB9281519E45A72A0791E89EA0937EE3839AB590D35F347E08FF665D1C2` |
| `000000022295` | `2026-08-11T15:44:32-04:00` | `by-type/by-struct/StaticObjEntry.md` | `0 / 1` | `34495C232C538EDE62F569C31717AE416FCD8B5075EB0AE7307B53AC8D53C388` |
| `000000022296` | `2026-08-11T15:44:34-04:00` | `by-type/by-struct/TileClassEntry.md` | `0 / 1` | `0742DF9ECE35F41DDCDD22776FEFAF3EA42536D229FD8E3A5E3F9789643D0185` |
| `000000022553` | `2026-08-12T04:32:39-04:00` | `by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md` C184-029 callback | `0 / 1` | `43A52B6531B4B2A43907F3AD6911789AEB83BE4AC0E77FEE1E2C4D9719B42401` |
| `000000022554` | `2026-08-12T04:32:46-04:00` | `by-class/StaticObjImageLib.md` current ordinary UID0000E2 C184-029 receipt | `0 / 1` | `C28BC94256BD6FD1F826E5A856790508A0FFD2DF510A40B8F504F19AA098117E` |
| `000000022555` | `2026-08-12T04:32:53-04:00` | `by-file/StaticObjImageLib.md` C184-029 callback | `0 / 1` | `9B8981EEB3E289F75D8C786F972997EEAB7ED45A7A7365B3E856B1F8B5797616` |
| `000000022556` | `2026-08-12T04:33:02-04:00` | `by-item/EPFArchiveMetadataTable.md` C184-029 callback | `0 / 1` | `13024109D4A62F850BB9062F894A73A2168115F785239B03C53D54D776A2FC92` |
| `000000022557` | `2026-08-12T04:33:08-04:00` | `by-file/ImageFrameTable.md` C184-029 callback | `0 / 1` | `87F18FEA2BE6CA02EE734242BF11D6E50A716F3B0C5FB98659B7C9A7D5AD7E7F` |

- Command `000000022285` registered the UID000184 rename and propagated validator-owned UID link/reference bookkeeping. UID0000E2 command `000000022286` is the historical B005 callback receipt. Later B003 command `000000022436` is an explicitly historical additive owning-header receipt: it added the include before `[[CHILDREN]]`, preserved the accepted B005 H/hierarchy/score, exited `0` with `ok: 1`, and its content was incorporated into the later ordinary callback state. Command `000000022554` is the current ordinary UID0000E2 receipt and produced current ordinary class SHA256 `C28BC94256BD6FD1F826E5A856790508A0FFD2DF510A40B8F504F19AA098117E`. Scoped validation also refreshed projected completion statistics as validator-owned state; no manual generated, tracker, project-level, coverage-row payload, audit, lifecycle, or IDA edit was performed by B005. These receipt identities are lifecycle-neutral documentation evidence and do not assert report execution/archive state.
- C184-015 through C184-027 and C184-030 are canonical `incorporate`/`proposed` supervisor work: the report supplies exact manual text, generated acceptance criteria, and IDA/protected/runtime actions, prestates, protections, stop conditions, and readbacks, while application and verification remain exclusively supervisor-owned and external to this report. C184-029 is canonical `incorporate`/`applied` B005 callback work under commands `000000022553` through `000000022557`.

## Changed Files

- Supervisor cleanup created the inert companion `000184-StaticObjImageLibSingletonClearHelper-source-quality-removed.md`; this recertification started from exact live-report SHA256 `1B967E7025C8567393D025090D121BD1CF6187E6907491E81574943372A5003E` and changes only this live report to reconcile that cleanup provenance. B005 did not edit the companion; it is non-authoritative, must never be executed, and provides no gate, score, coverage, IDA, validator, or lifecycle credit.
- Renamed: UID000184 from `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md` to `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md` under callback command `000000022285`.
- Modified ordinary callback artifacts and current stable identities; UID0000E2 includes the later valid additive command `000000022436` state while the other eleven remain at their B005 callback hashes:

| Path | SHA256 | Bytes | Lines |
| --- | --- | ---: | ---: |
| `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md` | `404C40DD098A53A3B26046B78AD529D6D3445EA62F586216633336CF57C50A06` | 10,479 | 106 |
| `by-class/StaticObjImageLib.md` | `C28BC94256BD6FD1F826E5A856790508A0FFD2DF510A40B8F504F19AA098117E` | 27,173 | 226 |
| `by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md` | `43A52B6531B4B2A43907F3AD6911789AEB83BE4AC0E77FEE1E2C4D9719B42401` | 13,386 | 131 |
| `by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md` | `DFC8800D47EE1AEE57508E71875A5EB5E1A704D90D20E3D2B095D10472DD1695` | 11,692 | 98 |
| `by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md` | `7484661816E3D72199889E8F44151CA11F8D0F3B988B175DC16A2475CEEAC804` | 23,393 | 158 |
| `by-file/StaticObjImageLib.md` | `9B8981EEB3E289F75D8C786F972997EEAB7ED45A7A7365B3E856B1F8B5797616` | 22,196 | 143 |
| `by-global/g_pStaticObjImageLib.md` | `DBC0FB5811C056CBCAD52CEF9088753F3A1FF4E6CFD247CBEE415F06668C4FDE` | 11,659 | 107 |
| `by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md` | `0F6BD0A7DD634AAFC70CE252B1C4E31F876EA67E709E0E8BE782FE850CCEC48A` | 11,862 | 110 |
| `by-type/by-struct/StaticObjImageLibLayout.md` | `98D8714CE9CE48AEA61882123D93BF082D91E2A1331D6414B690EF508BC06905` | 9,373 | 94 |
| `by-type/by-vtable/StaticObjImageLibVtable.md` | `EE18EBB9281519E45A72A0791E89EA0937EE3839AB590D35F347E08FF665D1C2` | 9,101 | 102 |
| `by-type/by-struct/StaticObjEntry.md` | `34495C232C538EDE62F569C31717AE416FCD8B5075EB0AE7307B53AC8D53C388` | 11,211 | 93 |
| `by-type/by-struct/TileClassEntry.md` | `0742DF9ECE35F41DDCDD22776FEFAF3EA42536D229FD8E3A5E3F9789643D0185` | 9,460 | 90 |
| `by-item/EPFArchiveMetadataTable.md` | `13024109D4A62F850BB9062F894A73A2168115F785239B03C53D54D776A2FC92` | 20,267 | 214 |
| `by-file/ImageFrameTable.md` | `87F18FEA2BE6CA02EE734242BF11D6E50A716F3B0C5FB98659B7C9A7D5AD7E7F` | 29,005 | 159 |

- Historical report identity boundaries: the earlier repair inputs were SHA256 `BFB3FE0CED4378190D6029B568DAC193781EFE77BAFBC739B30C4485B0C43DA0`, `97,847` bytes, `683` LF-only lines, and SHA256 `6518D61C9A43903AA6AB592D84CFF24A75A2029DABA079A892B80CACDE1CE9A7`, `112,633` bytes, `761` physical lines. They remain provenance only.
- This additive preflight started from exact report SHA256 `7A9FE3F444B394F017B7A513C8CAC133187FF935DAF749F3411D5F4BAD891C41`, `119,801` bytes, `767` physical lines. It modified only this report and preserved all valid ordinary research, formal source decisions, receipts, negative evidence, historical assumptions, and claim identities/order while adding C184-029/C184-030 for newly resolved source closure. Final identity is returned externally to avoid a self-referential hash.
- Modified by B005 under the explicit C184-029 callback: the five ordinary destinations and this report. Earlier repairs and generated/tracker command identities through generated 23008 and tracker 23015 are historical chronology only. This report-only repair starts from SHA256 `F0504B109FFED7C48856C959A2749B0DE141E343ACD4198BD9E3B6F718375CC9`, changes only this report, records dated generated 23042/tracker 23045 physical snapshots without implementation credit, and requires dynamic reread at later gates. Not modified: any by-* destination, manual `-coverage-report.md`, generated/tracker/audit/lifecycle file, goal, notes, other report, removed companion, or IDA database.
- This same-report Gate 2B tool-contract repair started from exact SHA256 `8915D7CE359CCC58EDFA2297BDD8765253EC24CCB561C269F50FC8D731AE3FD9`. It records the dated unsaved `make_data`/diagnostic-global-`set_type` result, replaces only the impossible atomic data contract and its mirrors, and leaves every by-* destination, coverage/generated/tracker/audit/lifecycle file, goal, notes, validator state, and IDA database unchanged. Final report identity is returned externally to avoid a self-referential hash.
- This same-report UDT Gate 2B repair started from exact SHA256 `A14AF7EDC5956D9604AC14549090891FC912FD6608A96250515145F55B2B5786`. It records canonical retry2's failed-closed alias mismatch and the discarded scratch parser/layout proof, replaces only the UDT analysis payload/readback/rollback contract and its mirrors, preserves human formal H and every ordinary receipt, and changes no external file or IDA state. Final report identity is returned externally to avoid a self-referential hash.
- This same-report protected-CHD history records the no-mutation/no-save 20DEC2DE stop and preserves the old zero only as dated failed-report history. The later B8C1/1,016/blank-neighbor baseline is also preserved only as superseded dated evidence. This repair binds the current 53B60F physical snapshot, fresh runtime-attested canonical-session baseline, blank stored target name/generated-only `unk_69B448`, explicit protected neighbor names, 1,020-entry catalog, and exact `0,1,3,0x00648d78` readback while changing no external file, validator state, or IDA state. Final report identity is returned externally to avoid a self-referential hash.
- Report lifecycle boundary: execution/archive status is supervisor-owned and authoritative only from the current report path plus validator-owned status/history metadata. B005 did not run an execute-report command or move/archive this report, and this section deliberately makes no path-dependent current execution-state claim.

## Implementation Tracking Checklist

### Initial report-only pass

- [x] Gate authority/order is invariant: exact-artifact Gate 1 is supervisor-owned and precedes Gate 2 or lifecycle action without this report asserting a current gate result.
- [x] Historical callback fact: supervisor acceptance preceded ordinary implementation.
- [x] By-file exhaustive-inventory obligations are not triggered because the declared target is one exact by-memory range; the complete directly affected constructor/destructor/compiler/global/class/layout family is nevertheless inventoried in Sections 13-19.
- [x] Target/support documents, current state, actual evidence, metadata, score, ownership, reconstructability, emitter, range, source placement, split, CPP/H, historical assumptions, and open-question dispositions are explicit.
- [x] No additional target UID is declared; support UIDs receive no independent tracker claim.
- [x] Every accepted claim has an exact destination and initial proposed state in the ledger history; the callback states below preserve all 30 current claim identities.
- [x] Every score-limiting target blocker was researched to resolution or an exact residual impact; no target work is deferred as generic investigation.
- [x] The formal CPP/H payload and exact target/compiler-support no-code proof are complete; the third-party import directive is target-specifically not applicable.
- [x] Wave2/Wave3 artifacts were ignored as stale.
- [ ] Section 21 completely supplies every exact Gate 2B entity, dated prestate, intended outcome, protection, parser-feasibility result, human-to-canonical alias rule, and expected readback; supervisor-owned runtime application/verification remains unchecked.
- [ ] Section 28 supplies manual-coverage payloads C184-015 through C184-021 and C184-030, while Sections 22/31 and C184-022 supply the coherent generated/tracker closure contract. Generated 23042 and tracker 23045 are dated snapshots at the exact C184-022 identities, not later-gate currentness; these supervisor-owned rows remain unchecked and require dynamic physical reread without implementation credit.
- [x] C184-029 supplies and now applies exact ordinary-document/formal CPP/H corrections for the accepted MemoryMan API, catalog behavior, shared declaration route, includes, score rationale, and historical/current-state prose under the explicit callback.

### Implementation callback pass

- [x] Historical callback fact: the supervisor accepted ordinary implementation; B005 applied C184-001 through C184-014 and C184-028 and supplied the stable C184-015 through C184-027 supervisor handoff.
- [x] All facts accepted in the historical ordinary callback were incorporated at report-level detail and physically reread; unchanged destinations retain their historical receipt hashes, and the five C184-029 destinations now carry commands `000000022553` through `000000022557` and the exact current hashes in Sections 31-32.
- [x] The sole declared target UID was independently reconciled with every support destination and its formal/no-code disposition.
- [x] Metadata, scores, owner/emitter routes, rename, source placement, historical assumptions, CPP/H payloads, and negative evidence from C184-001 through C184-014 and C184-029 were applied exactly.
- [x] Scoped `--no-generated-refresh` validators ran successfully and their command IDs, timestamps, results, and post-validator identities are preserved in Sections 31-32.
- [ ] C184-015 through C184-027 and C184-030 remain unchecked `incorporate`/`proposed` supervisor work. Commands through generated 23008/tracker 23015 are historical; generated 23042/tracker 23045 are dated snapshots only. C184-022 requires dynamic later-gate physical reread and gives neither B005 nor supervisor implementation credit for snapshot identity alone.
- [ ] B005 performed no supervisor-owned IDA mutation; dated supervisor diagnostics established singleton-data feasibility, canonical UDT aliases, and parser-safe packed-size feasibility without save credit. Section 21 supplies declarative authority provenance, prestates, intended outcomes, protections, parser/alias evidence, and expected readbacks. This Gate 2B closure row remains unchecked.
- [x] C184-029 ordinary source correction was applied under the explicit supervisor callback, validated in five scoped no-generated-refresh passes, and physically reread at the hashes recorded in Sections 31-32.
- [x] The report body is lifecycle-neutral and delegates execution/archive truth to current path plus validator-owned metadata.
- [x] Independent Gate 2A verification authority for ordinary applied claims is explicitly delegated to the supervisor without encoding its current result.
- [ ] Manual coverage, coherent generated acceptance, Gate 2B mutation/readback, and lifecycle authority are explicitly delegated to the supervisor; those exact claim rows remain unchecked until supervisor application and verification.

### Claim allocation and parity

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C184-001 | 000184 | Rename identity to StaticObjImageLibSingletonBaseDestructor; change historical pre-callback 86/91, owner/emitter 0000O7, true, blank position, Nested 0, nonblank CPP proof comment/blank H to final 94/97, owner 0000E2, false, blank emitters/position, preserved Nested 0, and blank CPP/H | near-certain | Exact bytes, sole this+4 EH jump, direct Singleton RTTI, inlined ordinary/scalar copies | by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md metadata and formal channels | incorporate | applied |
| [x] | C184-002 | 000184 | Incorporate exact body, boundary, EH liveness, no-route evidence, source cause, rejected helper and static-registration hypotheses, and historical correction | near-certain | Live MCP target, constructor, xref, byte, RTTI, startup and shutdown evidence | by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md all prose sections | incorporate | applied |
| [x] | C184-003 | 000184 | Move the class declaration to H with direct bases and packed StaticObjEntry lightImageIndex at +0x00; make CPP include StaticObjImageLib.h before children; change 88/89 to 92/96 while preserving owner/emitter 0000O7, true, blank position, and by-class Nested inapplicability | very-strong | RTTI PMD/EBO, exact 0x14 layout, current UID00023D constructor/setter cross-consumer proof, historical generated missing-H/children baseline, and historical additive owning-header evidence from command 000000022436 whose valid content is incorporated into current command 000000022554, SHA256 C28BC94256BD6FD1F826E5A856790508A0FFD2DF510A40B8F504F19AA098117E | by-class/StaticObjImageLib.md formal CPP and H plus source-shape prose | incorporate | applied |
| [x] | C184-004 | 000184 | Remove explicit singleton clear from destructor CPP; change 87/91 to 92/96 while preserving owner/emitter 0000E2, true, blank position, Nested 0, and blank H | near-certain | Ordinary tail clear at 4dd29b before LObject and direct base RTTI | by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md formal CPP, metadata, and lifecycle prose | incorporate | applied |
| [x] | C184-005 | 000184 | Reclassify scalar wrapper; change 85/90, owner/emitter 0000E2, true, blank position, Nested 0, blank CPP/H to 93/97, owner 0000E2, false, blank emitters/position, preserved Nested 0, blank CPP/H | near-certain | Vtable slot, cleanup parity, flags and optional delete tail | by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md metadata, blank formal channels, and prose | incorporate | applied |
| [x] | C184-006 | 000184 | Correct cluster inventory; change 86/91 to 90/95 while preserving owner NONE, false, blank emitter/position, Nested -4, and blank CPP/H | near-certain | Constructor EH disassembly and target boundary | by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md inventory, lifecycle, source-form, and metadata | incorporate | applied |
| [x] | C184-007 | 000184 | Correct file root; change 88/88 to 90/94 while preserving owner FILE, blank CPP/H, and by-file schema-inapplicable reconstructable/emitter/position/Nested fields | very-strong | Class, RTTI, constructor, destructor, scalar, global, generated state | by-file/StaticObjImageLib.md status, owned helpers, parent evidence, source shape, history, and score | incorporate | applied |
| [x] | C184-008 | 000184 | Preserve one zero singleton definition; change 88/91 to 92/96 while preserving owner/emitter 0000O7, true, blank position, nonblank CPP/blank H, and by-global Nested inapplicability | near-certain | Global bytes and thirteen xrefs | by-global/g_pStaticObjImageLib.md formal definition, lifecycle, exact xrefs, and metadata | incorporate | applied |
| [x] | C184-009 | 000184 | Reclassify storage; change 88/91, owner/emitter 0000SD, true, blank position, Nested 0, CPP proof comment/blank H to 93/97, owner 0000SD, false, blank emitters/position, preserved Nested 0, blank CPP/H | near-certain | Live 00 00 00 00 bytes, exact 69b448-69b44c boundary, adjacent slots, thirteen refs | by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md metadata, blank formal channels, and prose | incorporate | applied |
| [x] | C184-010 | 000184 | Add PMD +4 EBO layout; change 85/88 to 92/97 while preserving owner/emitter 0000E2, true, blank position, blank CPP/H, and by-struct Nested inapplicability | near-certain | StaticObj RTTI CHD attributes 1 and three bases, direct-Singleton BCD PMD +4, and member accesses prove multiple inheritance plus EBO | by-type/by-struct/StaticObjImageLibLayout.md hierarchy, layout, evidence, and metadata | incorporate | applied |
| [x] | C184-011 | 000184 | Reclassify vtable; change 85/90, owner/emitter 0000E2, true, blank position, blank CPP/H to 92/97, owner 0000E2, false, blank emitters/position, blank CPP/H, preserving by-vtable Nested inapplicability | near-certain | COL, CHD values 0,1,3,0x00648d78 with attributes 1, BCD, base array, decorated names, exact three slots | by-type/by-vtable/StaticObjImageLibVtable.md metadata, RTTI hierarchy, and source disposition | incorporate | applied |
| [x] | C184-012 | 000184 | Preserve packed StaticObjEntry and class-H ownership with signed int lightImageIndex at +0x00; retain lightIntensity only as rejected historical terminology; change 85/88 to 90/94 while preserving owner/emitter 0000E2, true, blank position, blank CPP/H, and by-struct Nested inapplicability | very-strong | Current UID00023D passes +0x00 unchanged to the LightingObjectPane constructor and SetLightImageIndex; constructor allocation and destructor/render consumers preserve the remaining layout | by-type/by-struct/StaticObjEntry.md source declaration ownership, allocation semantics, field history, and metadata | incorporate | applied |
| [x] | C184-013 | 000184 | Preserve TileClassEntry and class-H ownership; change 85/88 to 90/95 while preserving owner/emitter 0000E2, true, blank position, blank CPP/H, and by-struct Nested inapplicability | very-strong | TILEC parser, renderer stride, destructor free | by-type/by-struct/TileClassEntry.md source declaration ownership and metadata | incorporate | applied |
| [x] | C184-014 | 000184 | Preserve and explicitly supersede the historical file-level static cleanup and authored clear-helper assumptions | near-certain | No registration route plus direct-base RTTI and EH evidence | target, class, file, cluster, destructor, scalar, global, storage, layout, and vtable historical assumptions sections | historicalize | applied |
| [ ] | C184-015 | 000184 | Supply the exact target manual by-memory replacement row and bind its application/validation exclusively to supervisor manual-coverage authority | near-certain | Accepted target metadata and disposition | by-memory/-coverage-report.md UID000184 row | incorporate | proposed |
| [ ] | C184-016 | 000184 | Supply the exact cluster, destructor, scalar-wrapper, and singleton-storage by-memory replacement/insertion rows and bind their application/validation exclusively to supervisor manual-coverage authority | very-strong | Accepted support metadata and dated manual-row audit | by-memory/-coverage-report.md UIDs 00017H, 00017I, 0003M2, and 0001PP rows | incorporate | proposed |
| [ ] | C184-017 | 000184 | Supply the exact StaticObjImageLib class manual-coverage replacement row and supervisor ownership boundary | very-strong | Accepted class hierarchy, H route, and score | by-class/-coverage-report.md UID0000E2 row | incorporate | proposed |
| [ ] | C184-018 | 000184 | Supply the exact StaticObjImageLib file manual-coverage replacement row and supervisor ownership boundary | very-strong | Accepted source-root and compiler-support disposition | by-file/-coverage-report.md UID0000O7 row | incorporate | proposed |
| [ ] | C184-019 | 000184 | Supply the exact g_pStaticObjImageLib manual-coverage replacement row without sentinel wording and bind application to supervisor authority | near-certain | Zero bytes and thirteen refs | by-global/-coverage-report.md UID0000SD row | incorporate | proposed |
| [ ] | C184-020 | 000184 | Supply the exact StaticObjEntry, StaticObjImageLibLayout, and TileClassEntry manual-coverage replacement rows, including lightImageIndex +0x00, and bind application to supervisor authority | very-strong | Accepted formal H, UID00023D cross-consumer field proof, and layout evidence | by-type/by-struct/-coverage-report.md UIDs 0001W8, 0001W9, and 0001WC rows | incorporate | proposed |
| [ ] | C184-021 | 000184 | Supply the exact StaticObjImageLibVtable manual-coverage replacement row and supervisor ownership boundary | near-certain | Exact RTTI and vtable compiler-data disposition | by-type/by-vtable/-coverage-report.md UID0001YX row | incorporate | proposed |
| [ ] | C184-022 | 000184 | Refresh generated source after C184-029 so StaticObjImageLib CPP/H preserve the direct-base class route, use the accepted MemoryMan and shared ImageFrameTable declarations, reproduce the exact destructor behavior, omit UID000184, and pass complete physical readback under supervisor authority | very-strong | Commands through generated 23008 and tracker 23015 are historical; dated generated command 000000023042 at 2026-08-13T01:06:08-04:00 reread StaticObjImageLib.cpp SHA256 1AC04D0EBB9BCF45F053B841B9BAB23354F0D12CBE03281EB4B91A23A1D51335, StaticObjImageLib.h SHA256 D00B3902A83DA2F6D4108EB9F2DAC3B2E13A1C3204B5740FFE90AF49340BB1C3, and ImageFrameTable.h SHA256 78CEC2CCA386C0D52AD4D69936F1003F9D83D7E1D106DDADD35FC61A208F8D44; dated tracker command 000000023045 at 2026-08-13T01:12:15-04:00, SHA256 6794C5420667408D376DD55098F05BD3649191D62F18D4C567F2D4613953DFFC (1,721,219 bytes, 6,765 lines), preserves UID000184 94/97, average 95.5, false/non-emitting at line 5682; both are snapshots only and later gates dynamically reread, without B005 or supervisor implementation credit | validator-owned generated StaticObjImageLib.h, StaticObjImageLib.cpp, ImageFrameTable.h, generated coverage, and tracker readback | incorporate | proposed |
| [ ] | C184-023 | 000184 | Supply Section 21's literal pure function rename, exact function and occupied scalar-stack set_type, single-channel comment, complete-frame prestate/protection/readback, and supervisor Gate 2B boundary for four functions | very-strong | Fresh runtime-attested canonical-session reads prove exact names, ranges, prototypes, complete frames, four blank comment channels, xrefs, target bytes, and zero collisions for all proposed function/global names; Gate 2B rechecks these recorded literals before action | canonical IDB functions 004e5c00, 004dcf60, 004dd1e0, and 004e6990 | incorporate | proposed |
| [ ] | C184-024 | 000184 | Supply the exact singleton-slot current prestate and intended final four-byte data-item state: name `g_pStaticObjImageLib`, type `StaticObjImageLib *`, exact repeatable comment, zero bytes, thirteen xrefs, and unchanged neighbors; no standalone rename | near-certain | Fresh current-session reads prove zero bytes, four one-byte target items with blank stored head name and generated-only display label `unk_69B448`, explicit protected neighbor names `g_pRidingImageLib`/`g_pEffectObjImageLib`, and exact 13/20/12 target/predecessor/successor xrefs plus item/comment/type boundaries; the dated unsaved diagnostic independently proves the final shape/name and type are supported | canonical IDB data 0069b444-0069b44d | incorporate | proposed |
| [ ] | C184-025 | 000184 | Supply exact intended declarations and complete readbacks for TileClassEntry, packed StaticObjEntry with lightImageIndex +0x00, and StaticObjImageLib without a fake Singleton member, including parser-safe packing evidence and explicit human-source-to-IDA-canonical unsigned aliases | very-strong | Fresh current-session type_inspect proves all three proposed UDTs absent and LObject/ArchiveMetadataTable/MemoryMan opaque with size sentinel and zero members; type_query proves catalog total 1,020 with protected additions at ordinals 1017-1020; canonical retry2/scratch prove exact canonical aliases, parser-safe packing, size14 StaticObjEntry, size20 StaticObjImageLib, UID00023D lightImageIndex flow, allocation sizes, and EBO | canonical IDB local types | incorporate | proposed |
| [ ] | C184-026 | 000184 | Supply the protected no-change inventory and exact decorated/blank name, kind, width, type, value, comment-channel, range, and final expected readback for every Section 21 RTTI/vtable/neighbor row | near-certain | Fresh current-session item/comment/byte/integer/xref reads prove every protected COL, CHD, array, BCD, type descriptor, vtable word, and successor row, including StaticObjImageLib CHD 0,1,3,0x00648d78 with attributes 1, exact low-count xref sources, and 481 inbound xrefs to the shared LObject BCD | canonical IDB 00640348-00640364, 00648d54-00648df8, 00676a8c-00676adc, and 0061b700-0061b714 | incorporate | proposed |
| [ ] | C184-027 | 000184 | Record that current-runtime authority, persistence, and rollback are supervisor-owned outside this report; this report supplies only dated identity evidence, literal prestates, permitted deltas, protected properties, and complete expected readbacks | near-certain | Current physical disk SHA256 53B60FCF7C42327C9E03D90A407903D4EFF15510FEE791F2452EF0B2036A05D9, public runtime attestation at 2026-08-13T11:38:46.695504+00:00, complete fresh bounded actionable/protected baseline, and historical failed-closed diagnostics with exact restoration | supervisor Gate 2B boundary for UID000184 | incorporate | proposed |
| [x] | C184-028 | 000184 | Run scoped no-generated-refresh validators for every changed ordinary by-star doc and physically reread each destination | very-strong | Current workflow and exact callback destinations | report validator receipts and changed ordinary docs | incorporate | applied |
| [x] | C184-029 | 000184 | Correct the authored destructor and its declaration dependencies: use `MemoryMan::FreeBufferMemory`, preserve both observed `GetMemoryMan` acquisitions and unconditional catalog dereference, expose the accepted archive-table declarations from shared ImageFrameTable H, and include the required headers before child definitions | very-strong | Current MemoryMan H and UID0001BF formal API; ordinary-destructor body/call order; current UID0000UN accepted layout; generated command 000000022520 compile/readback defects | by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md formal CPP; by-class/StaticObjImageLib.md formal CPP; by-file/StaticObjImageLib.md dependency/source placement; by-item/EPFArchiveMetadataTable.md formal CPP/H and source placement; by-file/ImageFrameTable.md header route | incorporate | applied |
| [ ] | C184-030 | 000184 | Supply exact manual by-item and by-file coverage replacements for the shared ImageFrameTable header/declaration route, with supervisor-only application and validation | very-strong | Accepted shared declarations plus C184-029 dependency closure | by-item/-coverage-report.md UID0000UN row and by-file/-coverage-report.md UID0000K1 row | incorporate | proposed |

- Mechanical allocation: 30 ledger rows and 30 checklist rows. C184-001 through C184-014, C184-028, and C184-029 are checked/`applied`; C184-015 through C184-027 and C184-030 are unchecked/`proposed`.
- Ledger/checklist parity requirement: fields after `Done` must match literally and remain in identical C184-001 through C184-030 order.
- Actor allocation preserved outside the canonical tables: B005 owns C184-001 through C184-014, C184-028, and C184-029; SUPERVISOR owns C184-015 through C184-027 and C184-030.
- Lifecycle state is intentionally neutral. Current execution/archive truth belongs only to the report's path and validator-owned metadata.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000023111","destination_path":"executed-b-agent-research/B005/000184-StaticObjImageLibSingletonClearHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/000184-StaticObjImageLibSingletonClearHelper-source-quality.md","timestamp":"2026-08-13T08:58:19-04:00","uid":"000184"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
