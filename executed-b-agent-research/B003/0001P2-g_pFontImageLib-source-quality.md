** TARGET-REPORT-UID:0001P2 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0001P2 g_pFontImageLib Source-Quality Report

## Finalized Report / Current Recommendation

The accepted source-closure callback is implemented. [UID:0001P2] `by-memory/0x0067ab24-0x0067ab28.g_pFontImageLib.md` is exact false/non-emitting physical storage at `92/94`, with semantic owner [UID:0000QX], no emitter, and blank R0. [UID:0000QX] is the sole source definition at position `0` with the R1 local forward declaration and `FontImageLib *g_pFontImageLib = 0;`. [UID:00005B] is `94/94` and supplies complete support declarations, direct `LObject, Singleton<FontImageLib>` inheritance, one matching `extern`, exact `0x8001c` state, and class closure before `[[CHILDREN]]`.

The constructor and ordinary destructor now contain only authored source: direct base initialization, slot/scratch initialization, two archive deletes, and scratch release. Direct empty `Singleton<FontImageLib>` PMD `+4/-1/0` regenerates publication and reverse clear, so neither lifecycle body contains an explicit global write. UID0002HU is false/non-emitting compiler output with blank R5. The mixed index, source route, exact ranges, every padding span, vtable/layout/data evidence, BARAM resources, and consumer boundaries remain unchanged.

B003 changed only the 13 accepted ordinary destinations and this report, using one short ordinary lease at a time. Each ordinary page passed its scoped validator and was released immediately; final waited command 15543 refreshed generated output. B003 did not edit manual coverage, generated/tracker/audit/supervisor/validator-state/IDA/lifecycle files and did not run/probe `execute_report`, move, archive, or any report lifecycle command. Current external manual coverage remains supervisor-owned and unapplied at this callback snapshot.

## Supporting Research

Historical pre-callback primary destinations and exact Gate-1 evidence-time hashes:

| UID | Path | SHA256 | Bytes / lines | Current role |
| --- | --- | --- | --- | --- |
| 0001P2 | `by-memory/0x0067ab24-0x0067ab28.g_pFontImageLib.md` | `36A0675CEE93DC779B07D1C7B84DF4028B8A11513F763F1408ED070A91F2913C` | 8,014 / 86 | mixed physical storage, `86/90`, true, QX emitter, comment formal |
| 0000QX | `by-global/g_pFontImageLib.md` | `16D77DEB227F34B9F7CCB58236DE17F184C8243B8C8DE59A1806DF52F7998482` | 9,000 / 90 | semantic global, `90/90`, sole definition but late order |
| 00005B | `by-class/FontImageLib.md` | `7997AEEFEAE0D538CF91CF28C08AC0721C0BF2172A0CEA9BAAD9203877FEC0A9` | 16,557 / 151 | class, `92/92`, missing Singleton base and extern |
| 0000JH | `by-file/FontImageLib.md` | `1F789FAC4A21850342E780A6A4356BEAB1A83C0C3B762AB78BDB1CECFB919D69` | 16,353 / 116 | `NexusTK/render/FontImageLib.cpp` source root, `92/92` |
| 00015A | `by-memory/0x004b5f00-0x004b6409.FontImageLib.md` | `C90F4520211F1C02AC12462E17914B89F8598C8FCE43774899D548916B042362` | 16,345 / 138 | false mixed executable index, stale final-source blocker |
| 0002HP | `by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md` | `7A8FDE0D9780DC545B333DBB7C293A62FA61A413DB21E20EAFF30489591199E0` | 13,335 / 135 | source constructor with stale explicit publication |
| 00015B | `by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md` | `1D4CE500CBDF5B8F97FA5C4272397C93AB03F238D5407BFAE950A8C233C8D50F` | 9,343 / 105 | source destructor with stale explicit clear |
| 0002HU | `by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md` | `AEF5CEF9D405221BEBA5E3671B0FD255FA6704705F8687F880643BE64C0F39E9` | 11,860 / 166 | compiler wrapper still true/comment-emitting |
| 0001XM | `by-type/by-vtable/FontImageLibVtable.md` | `E88ECC9D94B44D7A9E832129E4E6AA312675709149B328CFFE21DB4B2C0C1E61` | 9,007 / 92 | compiler vtable evidence, stale slot name/base hierarchy |
| 0001UL | `by-type/by-struct/FontImageLibLayout.md` | `0FBA55556547578BD3B64152430DA9C37AB028E6F76E6A5AF7C064CCAEB59511` | 11,049 / 108 | covered layout, missing Singleton EBO row |
| 0001UK | `by-type/by-struct/FontGlyphRecord.md` | `FC660E7BB60A549396929F749225CB2AB84F87F95282880F8B4291D28799519C` | 10,021 / 104 | source struct currently emitted after the class/methods that require it |
| 0001UM | `by-type/by-struct/FontSlotStorage.md` | `0BD83BE528837592D3A5A831439C15C20AD22C467534374B3E29CCEF5C8E2021` | 9,216 / 101 | source struct currently emitted after its by-value class member use |
| 00031Q | `by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md` | `5939E1A4C5B1D024824F3589E5512C6B6399BB8C8FD57876BBD25279D6404EDE` | 6,795 / 84 | exact RTTI/vtable child; stale `nullsub_18` source label |

Implemented callback destinations after scoped validation and final readback:

| UID | Path | Current SHA256 | Bytes / lines | Implemented role |
| --- | --- | --- | --- | --- |
| 0001P2 | `by-memory/0x0067ab24-0x0067ab28.g_pFontImageLib.md` | `008EBB81075C69DF320A263569B240A4E46179AE879D6BD915142F9E31EE8FE6` | 10,567 / 95 | `92/94`, QX owner, false/no-emitter, blank R0, Nested 0 |
| 0000QX | `by-global/g_pFontImageLib.md` | `25959A7A21896E565109784002A88516B18C90408345546E4BF13F770939CA58` | 11,297 / 101 | `92/94`, JH owner/emitter, true, position 0, exact R1 |
| 00005B | `by-class/FontImageLib.md` | `59D0EFF6AC1A3AD9C3B34003506415B01D0E096E4F8B870859DD9D1361282426` | 19,083 / 186 | `94/94`, complete R2 declaration and class closure |
| 0000JH | `by-file/FontImageLib.md` | `1EDDB096D765C2DEE11BD7A43170B9239CC2E9060FAC4F443A19295AC76AB5D5` | 17,164 / 123 | `94/94`, unchanged `NexusTK/render/` route, complete source/compiler contract |
| 00015A | `by-memory/0x004b5f00-0x004b6409.FontImageLib.md` | `A4C8498970391DBB81E61E03D41C7798B17240C904B88A7B3FD2B04D33AEEB67` | 16,910 / 142 | `90/94`, false mixed index, blank R6, all children/padding retained |
| 0002HP | `by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md` | `5D73D4D0C29893530F2A941D5D3349A738BCB2576A78C338F36F743C11940E59` | 13,815 / 139 | `92/94`, exact authored R3 with implicit Singleton publication |
| 00015B | `by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md` | `F1C4AEB1F79A957AC04497C79AD11CD2EEAE7F9BFB084E1AC3B5C8A102E88564` | 9,985 / 108 | `92/94`, exact authored R4 with implicit reverse Singleton clear |
| 0002HU | `by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md` | `0607540D18994E386973A2B05375D2CFB458554847069A5AA6EF7A8055B854CF` | 12,206 / 169 | `92/96`, class owner, false/no-emitter, blank R5 |
| 0001XM | `by-type/by-vtable/FontImageLibVtable.md` | `80BA19EA454ECB3B9CE73096254C908A84E4E2DBE47FCCC72913A8DAD75FDD2C` | 9,968 / 101 | `92/96`, class owner/emitter, exact R7 and resolved inherited slots |
| 0001UL | `by-type/by-struct/FontImageLibLayout.md` | `9882A1A4D345BC2F719884956F3E3B985CCD79CFD66966ADE3E11F43F71C3A24` | 12,193 / 120 | `92/96`, class owner/emitter, exact R8/EBO layout |
| 0001UK | `by-type/by-struct/FontGlyphRecord.md` | `E70F7E3CAE0C5DABB075DBC2A569E5F66238726150466694A03C027B4352CA15` | 10,491 / 101 | `92/94`, class owner/emitter, exact R10 covered-by disposition |
| 0001UM | `by-type/by-struct/FontSlotStorage.md` | `AF548C486A4713180555B785FA5BD840B635BD126270A87334CA1C00C71954DF` | 9,778 / 102 | `92/94`, class owner/emitter, exact R11 covered-by disposition |
| 00031Q | `by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md` | `47A9B5CFF08082B114C76D10FC2517879334625B709E4B45E00E711F969AFE17` | 7,572 / 91 | `92/96`, vtable owner/emitter, Nested +4, exact R9 |

Historical-report searches used the exact terms `UID0001P2`, `0001P2`, `0x0067ab24`, `g_pFontImageLib`, `FontImageLibConstructor`, and `Singleton<FontImageLib>` against these roots:

| Root | Outcome and classification |
| --- | --- |
| `tools/leaser/Agents/*/research/**` | No active direct research report. Current B003 goal was the only direct UID match; unrelated notes/tracker references were coordination evidence only. |
| `executed-b-agent-research/**` | Direct B001 reports `00015A-0002HP-fontimagelib-source-quality.md` and `0002HP-FontImageLibConstructor-empty-emitter-source-quality.md`; B010 `0000JH-FontImageLib-empty-emitter-family-source-quality.md`; B010 Application cleanup and B001/B002 GrafPort consumer reports. These are evidence leads, not inherited conclusions. |
| `archived/**` | No match for any exact term. |
| `tools/leaser/Agents/Older-Research/**` | B011 `00016I-GrafPortDrawGlyph-source-quality.md` matched `0x0067ab24`/`g_pFontImageLib`; it confirms consumer behavior only. |
| `tools/leaser/Agents/SpecialReports/**` | No match for any exact term. |

The B001 passes correctly established zero storage, 52 references, layout, and usable fields, but normalized the compiler-adjusted publication to handwritten `g_pFontImageLib = this`. The B010 family pass correctly emitted the source methods and compiler no-code pages, but retained explicit constructor/destructor singleton writes and omitted the direct Singleton RTTI base. This report preserves those historical decisions while superseding only the source-cause classification proven below.

## Target

- UID: `0001P2`.
- Current path: `by-memory/0x0067ab24-0x0067ab28.g_pFontImageLib.md`.
- Exact half-open range: `0x0067ab24-0x0067ab28`, size `0x4` / 4 bytes.
- Exact target bytes: `00 00 00 00`; SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- PE identity used by the active IDB: `NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, 2,679,296 bytes.
- Source identity: externally linked `FontImageLib *g_pFontImageLib`, zero-initialized.
- Physical role: loader-zero backing storage only; no independent C++ emitter.
- Semantic owner: [UID:0000QX] `g_pFontImageLib`.
- Source file: [UID:0000JH] `NexusTK/render/FontImageLib.cpp`.

## Current Target State

UID0001P2 is currently `92/94`, `CANONICAL_OWNER:0000QX`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position/formal, and `Nested:0`. UID0000QX is `92/94`, true under UID0000JH at position `0`; UID00005B is `94/94` with direct `LObject, Singleton<FontImageLib>` bases and one extern. UID0002HU is `92/96`, false/non-emitting with blank R5. All other accepted tuples match the implemented-destination table.

Current generated tracker command/header is external deferred refresh `000000015549`, refreshed `2026-07-20T18:17:47-04:00`, SHA256 `F2E2FA14786D3987AD84CE3092977833D16218886F7474B21E0E8BDD7868935F`, 1,535,343 bytes / 6,218 lines. It places the sole UID0001P2 row at line 3827 with `92/94`, average `93.0`, and `false`. B003 waited command 15543 established the same semantic tuple; command 15501 and earlier 15481/15492 are historical pre-callback defects.

Current generated `FontImageLib.cpp` is external foreground refresh command `000000015548`, refreshed `2026-07-20T18:16:09-04:00`, SHA256 `36D5E0953D6535AEEF956240FD9D1ED396475C96F897C73D1CE3B521364FDD9B`, 9,357 bytes / 262 lines. It differs from B003 waited command-15543 SHA `DEECB00A78352C99977F47E5355C6A799F43B631F12CAB863C169C8BFF15B149` only by the validator header epoch. The sole global definition is line 10; complete `FontGlyphRecord` and `FontSlotStorage` declarations precede class use; the compatible extern is line 38; the direct-Singleton class is line 40, closes at line 67, and the first qualified definition begins at line 70. Constructor, destructor, `GetFontMetrics`, `MeasureGlyphWidth`, `EnsureFontSlotLoaded`, and `DecodeGlyphBitmap` each occur exactly once. There are zero explicit singleton writes inside constructor/destructor, zero UID0001P2/UID0002HU text, zero Empty Emitter Markers, and zero handwritten vtable/RTTI/EH/cookie/scalar/base-teardown definitions.

## Executive Recommendation

The implemented representation is the accepted coherent three-part route: false/blank physical UID0001P2, one position-0 semantic definition on UID0000QX, and one class/header extern on complete direct-Singleton UID00005B. `FontGlyphRecord` and `FontSlotStorage` are declared once before first use; their pages retain covered-by evidence. Constructor/destructor source contains authored state work only, and direct Singleton lowering regenerates publication/clear. The scalar wrapper is false/blank compiler output; vtable/layout/data remain source-declared/generated-binary evidence. No further B003 ordinary implementation item remains.

## Supervisor Active Recheck

Historical report-only finalization observed command 15501 and the accepted pre-callback hashes above. The callback then applied and validated all 13 ordinary destinations and produced waited command 15543. Later external commands 15548/15549 advanced only generated/tracker headers while preserving the exact callback semantics. During callback, unrelated external manual epochs changed by-memory/by-global/by-class/by-file coverage hashes; affected FontImageLib row text remained stale and unapplied, with only by-memory UID00031Q/UID0001P2 line movement to 3912/4234. The exact no-loss handoff below is rebased to the current roots. Final lease readback contains no B003 entry. These external epochs do not alter C01-C20 or R0-R11.

## Inference Research Guidance Check

The report does not stop at the existing `covered-by` comment, raw constructor assignment, late generated definition, or prior family-report conclusions. It tests physical versus semantic ownership, source/header linkage, exact direct bases, EBO layout, source versus compiler lifetime mechanics, vtable slot identities, consumer non-ownership, and generated order against fresh MCP and current project precedents. All in-scope blockers are resolved to destination-ready metadata and C++ or exact no-code form; only unrecoverable lexical/header-token choices remain bounded confidence caps.

## Heuristic / Inference Reanalysis And Validation

1. The exact four-byte slot is not code, a field, an adjacent singleton, or a class-static member. Bounded reads show zero bytes, `get_global_value` returns zero, no function covers it, and its 52 operand references are independent of the 19-reference predecessor at `0x0067ab20` and the successor at `0x0067ab28`.
2. The constructor sequence is not evidence for a handwritten global assignment. It forms `this+4`, null-tests the adjusted pointer, subtracts four, and stores the complete object. RTTI independently identifies a direct empty `Singleton<FontImageLib>` base at PMD `+4/-1/0`. This is the same project/compiler pattern already resolved for `LanguageMan`, `MapTileImageLib`, `FrameMgr`, `UserListDialogPane`, and other singleton classes.
3. The ordinary destructor performs authored slot/scratch cleanup, then clears the singleton immediately before `LObject::~LObject`. With base order `LObject, Singleton<FontImageLib>`, reverse base destruction is exactly derived body, Singleton clear, then LObject cleanup. The source destructor must omit the clear.
4. The scalar wrapper repeats the cleanup and clear because MSVC lowered/inlined virtual destruction and conditional delete behavior. Its vtable-only reachability, delete flags, size guard, and optional storage free reject handwritten wrapper source.
5. The semantic by-global page is the correct sole definition carrier. A pointer definition needs only a forward-declared class. The class page is the correct header-facing extern carrier. The physical by-memory slot must be false and blank to avoid a second source entity.
6. Position `0` on UID0000QX fixes global declaration visibility before class/method output. The class block carries the accepted `FontGlyphRecord` and `FontSlotStorage` declarations before the class, plus a compatible `extern` before `[[CHILDREN]]`. UID0001UK/UID0001UM then emit covered-by comments instead of late duplicate structs. One module definition, one extern, and one copy of each complete support type is source-plausible C++03.
7. The existing source-facing name is retained. Raw `dword_67AB24`, `unk_67AB24`, `DAT_0067ab24`, `s_instance`, class-static storage, and `g_pFontLibrary` have weaker or no project evidence. Exact original spelling cannot be recovered, so confidence remains below perfect.
8. The 0x8001c layout closes without raw padding members: LObject at `+0x00`; empty Singleton base at `+0x04` overlapping `m_fontSlots[0]`; two 0x40008 slots at `+0x04/+0x4000c`; scratch pointer at `+0x80014`; scratch byte count at `+0x80018`; end `+0x8001c`.
9. The current primary vtable has only the inherited LObject virtual surface: compiler scalar deleting destructor, `LObject::GetRuntimeClass`, and `LObject::OnChangeMessage`. The old `nullsub_18` label is raw/historical, not the current source-facing name.
10. No broader physical split is needed. The target is one exact dword between exact independent singleton/control-pointer slots; all function/padding boundaries in the FontImageLib executable island remain unchanged.

## Evidence Standards Used

- Fresh live IDA MCP evidence from the configured NexusTK IDB, not stale report conclusions.
- Exact bytes, xrefs, function boundaries, bounded instruction queries, RTTI/COL/CHD/BCD/PMD bytes, vtable dwords, and caller/callee facts.
- Current ordinary documentation and generated-source readback, each with current SHA256/metrics where material.
- Current project singleton precedents with direct RTTI/PMD/EBO proof and one-definition source routing.
- Positive and negative route comparison; raw labels and decompiler expressions are retained only as evidence aliases.
- C++03-era human source shape, excluding handwritten vptr, base cleanup, deleting flags, SEH, cookie, RTTI, or raw-address artifacts.

## Evidence Checked

### Live MCP availability and bounded probes

- Fresh `idb_list` returned active database `9b0396a3` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` with worker PID 15732.
- At `2026-07-20T17:30:25.1972205-04:00`, `server_health(database=9b0396a3)` returned `status:ok`, module `NexusTK.exe`, image base `0x00400000`, and auto-analysis, Hex-Rays, and strings cache ready (`2067` cached strings).
- Bounded `get_bytes` succeeded for `0x0067ab10` size 48, constructor code at `0x004b5f00`, and cleanup code at `0x00464bc0`. `get_global_value` returned `0x0` for `0x0067ab1c`, `0x0067ab20`, `0x0067ab24`, `0x0067ab28`, and `0x0067ab2c`.
- One initially overbroad two-million-instruction client query exceeded its client timeout. It was discarded and is not evidence. All subsequent bounded target/function/range calls on the same session succeeded; no listener, worker, or database-session outage occurred.

### Binary and documentation inputs

- `xrefs_to(0x0067ab24)` returned exactly 52 entries with `more:false`.
- `analyze_batch` and bounded instruction queries covered constructor `0x004b5f00-0x004b5f54`, ordinary destructor `0x004b5f60-0x004b5fe6`, scalar wrapper `0x004b6350-0x004b6409`, startup `0x004639d0-0x00464a52`, and cleanup `0x00464a60`.
- RTTI bytes/names checked: FontImageLib COL `0x006479b0`, CHD `0x006479c4`, base array `0x006479d4`, self BCD `0x006479e4`, Singleton BCD `0x00647a00`, Singleton CHD/base array/self BCD `0x00647a1c/0x00647a2c/0x00647a34`, and type descriptors `FontImageLib` `0x00676244` / `Singleton<FontImageLib>` `0x00676260`.
- Vtable bytes checked at `0x0061a5f0-0x0061a600`, followed by UTF-16 `BARAM%02d.EFT` at `0x0061a600`.
- Current target/support/formal pages, current generated source, all six manual coverage roots, active/executed/archived/older/special report roots, neighboring slot docs, LObject class/vtable facts, application startup/cleanup, and representative GrafPort/UI consumers were reread.

## Claim And Incorporation Ledger

| Claim | Atomic accepted fact | Confidence | Destination | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Evidence was collected on healthy MCP database `9b0396a3`; bounded health/bytes/function calls succeeded. | High | all changed evidence sections | incorporate | applied | Target/global/class/file and lifecycle/type pages retain the exact session health, PE, bounded call, and historical evidence; validators 15510-15542 accepted the incorporated prose. |
| C02 | UID0001P2 is exact `0x0067ab24-0x0067ab28`, four zero bytes with SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. | High | UID0001P2, QX, file | incorporate | applied | UID0001P2 current SHA `008EBB81075C69DF320A263569B240A4E46179AE879D6BD915142F9E31EE8FE6` and UID0000QX current SHA `25959A7A21896E565109784002A88516B18C90408345546E4BF13F770939CA58` retain exact range/bytes/hash; validator commands 15510/15512 returned exit 0, ok 1. |
| C03 | The slot has exactly 52 direct refs: three lifecycle writes/clears, one Application cleanup read, and 48 render/UI/text reads. | High | UID0001P2, QX | incorporate | applied | UID0001P2 now contains the complete grouped 52-address table and raw-operand note; UID0000QX records lifecycle/consumer closure. |
| C04 | Application initialization allocates `0x8001c` bytes and directly calls the constructor once; cleanup checks the global and dispatches virtual scalar deletion with flag 1. | High | target/global/file/aggregate | incorporate | applied | UID0001P2/QX/JH/15A and constructor retain `0x00464505`, `0x00464520`, and `0x00464bcf-0x00464bdd` routes; corresponding validators 15510/15512/15525/15528/15532 passed. |
| C05 | Constructor publication is direct `Singleton<FontImageLib>` base lowering at PMD +4, not handwritten assignment. | High | class, ctor, global, target | incorporate | applied | R2 has direct Singleton base; R3 initializes it and has no assignment. Generated command 15543 has direct base once and zero `g_pFontImageLib = this`. |
| C06 | Ordinary-destructor clear is reverse direct Singleton-base destruction after authored cleanup and before LObject teardown. | High | class, dtor, global | incorporate | applied | UID00015B R4 omits the clear and documents exact reverse order; generated destructor has zero indented global clear. Validator 15533 passed. |
| C07 | UID0002HU is a vtable-only compiler scalar deleting wrapper; set false/no-emitter/blank formal and retain full ABI proof. | High | UID0002HU, aggregate, vtable | incorporate | applied | UID0002HU is `92/96`, false/no-emitter/blank R5 at SHA `0607540D18994E386973A2B05375D2CFB458554847069A5AA6EF7A8055B854CF`; validator 15535 updated registry true->false/block->blank. Generated output has zero UID0002HU text/body. |
| C08 | FontImageLib directly inherits `LObject` then empty `Singleton<FontImageLib>`; RTTI hierarchy has exactly three entries. | High | class, vtable, vtable data | incorporate | applied | R2/R7/R9 and destination prose carry the direct bases and three-entry hierarchy; generated direct-base declaration occurs once. |
| C09 | Singleton PMD +4 EBO overlaps the first font slot without changing exact `0x8001c` layout. | High | class, layout, ctor/dtor | incorporate | applied | UID0001UL R8 and class/current lifecycle pages record `+0x04/-1/0`, first-slot overlap, second slot `+0x4000c`, scratch `+0x80014/+0x80018`, size `0x8001c`; validators 15515/15539 passed. |
| C10 | Primary vtable is scalar wrapper, inherited `LObject::GetRuntimeClass`, inherited `LObject::OnChangeMessage`; no handwritten table. | High | vtable, vtable data, class | incorporate | applied | UID0001XM/UID00031Q names are synchronized; R7/R9 preserve exact data/no-code disposition; generated command 15543 has no handwritten vtable/RTTI definitions. |
| C11 | Best source identity is externally linked `FontImageLib *g_pFontImageLib = 0;`; raw/class-static aliases are rejected. | High | QX, class, file | incorporate | applied | R1 emits one external definition at line 10 and R2 one extern at line 38; QX/class/file retain rejected alternatives. |
| C12 | Physical UID0001P2 is false/non-emitting storage owned semantically by QX; blank formal replaces comment emission. | High | UID0001P2 | incorporate | applied | Target metadata/formal and validator 15510 prove false/no-emitter/blank; generated command 15543 has zero UID0001P2 text or marker. |
| C13 | Semantic UID0000QX owns the sole definition at position 0 with local forward declaration. | High | UID0000QX | incorporate | applied | UID0000QX metadata is position 0 and exact R1; generated source lines 7-10 prove local forward plus sole definition before every use. |
| C14 | UID00005B supplies the two complete support structs before first use, the direct Singleton base, and one header-facing extern before `[[CHILDREN]]`; UID0001UK/UM become covered-by no-duplicate pages. | High | UID00005B, UID0001UK, UID0001UM | incorporate | applied | R2/R10/R11 exact destination blocks; validators 15515/15519/15522 passed. Generated source has one of each struct before class use and R10/R11 comments once. |
| C15 | Historical command-15501 ordering was defective; waited output must place the global and complete support types before use, emit one of each declaration/definition, and preserve commands 15481/15492 only as history. | High | class/global/type/file/generated verification | historicalize | applied | B003 command 15543 superseded historical 15481/15492/15501; current external command 15548 preserves definition line 10, structs lines 16/29, extern line 38, class close line 67, first method line 70, and all uniqueness assertions. |
| C16 | Source remains `NexusTK/render/FontImageLib.cpp`; consumers and Application remain non-owning support. | High | UID0000JH and bounded links | incorporate | applied | UID0000JH remains `NexusTK/render/` at `94/94`; verify-only consumers were reread and no contradiction or edit occurred. |
| C17 | UID00015A remains false mixed index; exact children and all internal/external padding boundaries remain unchanged. | High | UID00015A | incorporate | applied | UID00015A is `90/94`, NONE/false/blank R6/Nested 0; all eight children and nine internal/outer padding rows remain present; validator 15528 passed. |
| C18 | GrafPort/text/glyph/UI refs are consumers only and do not alter owner, emitter, or source placement. | High | target/global/file | already-present | already-present | Reread of target/global/file and verify-only consumer pages found no competing definition/owner; no consumer page was modified. |
| C19 | Recommended scores/metadata follow resolved source blockers and retain lexical confidence caps. | High | score table/all destinations | incorporate | applied | Current destination table and external generated tracker command 15549 show every accepted score/true-false/route tuple; B003 command 15543 is the callback proof epoch and lexical caps remain explicit. |
| C20 | Manual coverage remains supervisor-owned; the exact no-loss replacement text is retained and was not applied by B003. | High | manual handoff only | not-applicable | excluded-with-reason | Current six-root readback is recorded below. Direct rows remain stale/unapplied; B003 is prohibited from manual coverage edits, so the exact handoff remains external supervisor work rather than an implementation omission. |

## Positive Evidence Summary

- Exact zero bytes/value and a four-byte boundary prove a pointer slot, not code or composite data.
- Exact 52-reference closure ties the slot to one constructor publication, two destructor clear sites, Application lifecycle, and broad font consumers.
- Constructor `this+4/-4` adjustment and RTTI PMD `+4/-1/0` independently prove direct Singleton base publication of the complete object.
- Reverse destructor order exactly explains cleanup, singleton clear, then LObject teardown.
- The class allocation, memset span, slot stride, scratch offsets, RTTI EBO, and scalar size guard all agree on `sizeof(FontImageLib)==0x8001c`.
- Current LObject docs resolve `0x004f4b10` and `0x0041b6c0` to inherited source methods, closing the vtable-name blocker.
- Current LanguageMan/MapTileImageLib/UserListDialogPane precedents establish one by-global definition, one class extern, false physical storage, and implicit Singleton lifecycle as the project-consistent route.

## IDA MCP Facts

### Lifetime writes and startup/cleanup

| Address | Context | Exact meaning |
| --- | --- | --- |
| `0x00464505` | Application initialization | Allocation result for size `0x8001c`; null-tested before construction. |
| `0x00464520` | Application initialization | Sole direct call to `FontImageLib::FontImageLib`. |
| `0x004b5f24` | constructor | Stores complete object selected by compiler adjustment around direct Singleton base at `this+4`. |
| `0x004b5fc5` | ordinary destructor | Reverse Singleton-base clear after authored slot/scratch cleanup. |
| `0x004b63c0` | scalar wrapper | Inlined compiler Singleton clear in deleting wrapper. |
| `0x00464bcf-0x00464bdd` | Application cleanup | Loads/checks global, pushes delete flag `1`, calls vtable slot 0. |

Constructor `0x004b5f00-0x004b5f54` calls `LObject::LObject`, executes the direct Singleton publication idiom, installs vtable `0x0061a5f4`, clears `this+4` for `0x80010` bytes, and clears `+0x80014/+0x80018`. Ordinary destructor `0x004b5f60-0x004b5fe6` destroys two `0x40008`-stride DATFile slots, frees scratch storage, clears the Singleton, and calls `LObject::~LObject`. Scalar wrapper `0x004b6350-0x004b6409` repeats cleanup, handles delete flags `1/4`, optionally frees a `0x8001c` object, and has only the vtable data reference.

### RTTI and vtable

The FontImageLib CHD records three entries: `FontImageLib`, `LObject`, and direct `Singleton<FontImageLib>`. The Singleton BCD PMD is `mdisp=4`, `pdisp=-1`, `vdisp=0`, attributes `0x40`. The exact table is:

| Address | Value | Source interpretation |
| --- | --- | --- |
| `0x0061a5f0` | `0x006479b0` | FontImageLib COL |
| `0x0061a5f4` | `0x004b6350` | compiler scalar deleting destructor |
| `0x0061a5f8` | `0x004f4b10` | inherited `LObject::GetRuntimeClass` |
| `0x0061a5fc` | `0x0041b6c0` | inherited `LObject::OnChangeMessage` default no-op |
| `0x0061a600` | `BARAM%02d.EFT` | successor resource string, excluded from vtable |

## Function / Child Inventory

| Range | UID | Current identity | Accepted disposition |
| --- | --- | --- | --- |
| `0x004b5f00-0x004b6409` | 00015A | mixed FontImageLib index | false/non-emitting; retain complete child/padding map |
| `0x004b5f00-0x004b5f54` | 0002HP | `FontImageLib::FontImageLib` | source; remove explicit publish, retain all initialization |
| `0x004b5f60-0x004b5fe6` | 00015B | `FontImageLib::~FontImageLib` | source; remove explicit clear, retain authored cleanup |
| `0x004b5ff0-0x004b6018` | 0002HQ | `GetFontMetrics` | verify-only unchanged |
| `0x004b6020-0x004b60ae` | 0002HR | `MeasureGlyphWidth` | verify-only unchanged |
| `0x004b60b0-0x004b60bd` | 0003XA | `IsLegacyAssetMode` | separate owner/source; unchanged |
| `0x004b60c0-0x004b61d9` | 0002HS | `EnsureFontSlotLoaded` | verify-only unchanged |
| `0x004b61e0-0x004b6341` | 0002HT | `DecodeGlyphBitmap` | verify-only unchanged |
| `0x004b6350-0x004b6409` | 0002HU | scalar deleting destructor | compiler-only false/non-emitting, blank formal |
| `0x0061a5f0-0x0061a600` | 00031Q | RTTI/vtable data | source-declared/generated-binary evidence; updated slot/base proof |
| `0x0067ab24-0x0067ab28` | 0001P2 | physical global storage | false/non-emitting, blank formal |

## Direct Xref / Caller Inventory

`xrefs_to(0x0067ab24)` returned all 52 entries. Grouped without omission:

| Group | References |
| --- | --- |
| Three lifecycle writes/clears | `0x004b5f24`, `0x004b5fc5`, `0x004b63c0` |
| Application cleanup read | `0x00464bcf` |
| render/UI/text reads, part 1 | `0x00468bef`, `0x00468e0f`, `0x00475abf`, `0x004761ef`, `0x0047ba5b`, `0x0047c2de`, `0x004840c2`, `0x004885a7`, `0x00498a35`, `0x004990f1`, `0x004994b8`, `0x004a0172` |
| GrafPort/font reads | `0x004ba8e0`, `0x004ba9cb`, `0x004baaaf`, `0x004babe2`, `0x004badb1`, `0x004bb5f4`, `0x004bb6ac`, `0x004bb6f2`, `0x004bb73a` |
| render/UI/text reads, part 2 | `0x004f1d3e`, `0x004f1efe`, `0x004ff152`, `0x004ff512`, `0x00541e9a`, `0x0056baa7`, `0x0056bb3a`, `0x0056bbe7`, `0x0056c41a`, `0x0056c52c`, `0x0056c7dc` |
| render/UI/text reads, part 3 | `0x0057f82c`, `0x0057f8d4`, `0x0057fb24`, `0x0057fdbc`, `0x00580006`, `0x00586b79`, `0x00586f2a`, `0x0058a284`, `0x0058eed2`, `0x005948cb`, `0x005953ba`, `0x0059dfd5`, `0x0059f306`, `0x0059f39c`, `0x005a22e7`, `0x005a2367` |

The six raw/no-modeled-function references (`0x00468e0f`, `0x004885a7`, `0x0056baa7`, `0x0056bbe7`, `0x005a22e7`, `0x005a2367`) remain valid operand evidence. They do not create extra writers or owners. The 48 non-lifecycle consumers read the singleton; none supplies separate storage or a competing source definition.

## Documentation Evidence And IDA Status

- Historical pre-callback UID0001P2 prose had corrected the old `0xffffffff` claim to zero, while metadata/formal remained mixed and manual coverage still said `0xffffffff`. Current UID0001P2 is `92/94`, false/non-emitting with blank R0; manual coverage alone remains supervisor-owned stale text.
- Historical pre-callback UID0000QX owned the definition/52-ref story but lacked position 0, forward declaration, direct Singleton cause, and extern separation. Current UID0000QX has exact R1 at position 0, and current UID00005B supplies the sole compatible extern.
- Historical pre-callback UID00005B inherited only `LObject`, treated publication/clear as handwritten, and used `FontSlotStorage` before its late definition. Current exact R2 declares both support records first, then direct `LObject, Singleton<FontImageLib>`, one extern, complete members/methods, class closure, and children.
- Historical pre-callback UID0002HP/UID00015B explicitly duplicated compiler-owned Singleton lifecycle. Current R3/R4 retain only authored initialization/cleanup, and generated command 15543 proves zero explicit lifecycle global writes.
- Historical pre-callback UID0002HU was true/comment-emitting despite complete compiler ABI proof. It is now `92/96`, false/no-emitter with blank R5 and zero generated marker/body.
- Historical pre-callback UID0001XM/UID00031Q retained `nullsub_18` and omitted the Singleton hierarchy. Current pages use inherited `GetRuntimeClass`/`OnChangeMessage`, exact three-entry RTTI, PMD/EBO proof, and R7/R9 compiler dispositions.
- Historical pre-callback UID0001UL omitted the empty Singleton base/EBO row. Current R8 records direct EBO overlap and all exact offsets at `92/96`.
- UID0000JH continues to own `NexusTK/render/FontImageLib.cpp`; its current `94/94` prose records the complete source/header order and compiler/source split without changing the route.
- Commands 15481/15492/15501 are explicitly historical defective generated epochs. B003 waited command 15543 fixed them; current external command 15548 preserves the definition and support types before use, one extern, direct Singleton class, class closure before methods, and no duplicate or ABI source.

## Ranked Ownership Analysis

| Rank | Candidate | Decision | Reason |
| --- | --- | --- | --- |
| 1 | semantic [UID:0000QX] global emitted by [UID:0000JH] | Accepted | exact type, one-definition route, owner file, lifecycle/consumer closure, current project singleton precedent |
| 2 | physical [UID:0001P2] owns source through QX | Rejected | duplicates semantic source identity and leaves a linker slot as a source emitter; mixed comment formal has no source construct |
| 3 | `FontImageLib::s_instance` class-static | Rejected | all current project docs/consumers use external global; no decorated/static-member evidence and external cross-file reads require linkage |
| 4 | `Application` owns the definition | Rejected | Application allocates/deletes but RTTI and methods place lifecycle in FontImageLib/Singleton; consumer is not owner |
| 5 | GrafPort/text/UI owner | Rejected | 48 reads are consumers of font services and provide no writer, RTTI, allocation, or storage evidence |
| 6 | no owner / compiler-only storage | Rejected | the externally linked zero-initialized pointer is a real source definition used across modules; only publish/clear mechanics are compiler-lowered |

## Source Placement

Logical source split:

- `FontImageLib.h`: `FontGlyphRecord` and `FontSlotStorage` declarations before the class; class declaration with direct `LObject` and `Singleton<FontImageLib>` bases, accepted fields/methods; and `extern FontImageLib *g_pFontImageLib;`.
- `FontImageLib.cpp`: include the header, define exactly `FontImageLib *g_pFontImageLib = 0;`, then source-authored constructor/destructor/method bodies.
- Generated flattened route: UID0000QX at optional position `0` emits local forward declaration plus sole definition before class/method output; UID00005B emits complete support structs, compatible forward declaration/extern, and complete class before `[[CHILDREN]]`. UID0001UK/UM contribute no duplicate struct definitions.
- UID0001P2 emits nothing; linker/loader placement recreates the `.data` zero-fill slot.

File-local `static` is rejected because consumers span Application, GrafPort, controls, panes, and gameplay/UI source families. A template specialization body is rejected because the observed semantic storage is the plain external `FontImageLib *` slot used by all consumers.

## Range / Split / Padding / Reclassification Analysis

- Keep target range exactly `0x0067ab24-0x0067ab28`; no split or extension.
- Predecessor `0x0067ab20-0x0067ab24` is independent UID000295 `g_pDirectX`; successor `0x0067ab28-0x0067ab2c` is independent UID0001P3 `g_activeBrowserControlPane`. Each is a separate zero dword with distinct xrefs.
- `0x0067ab18-0x0067ab1c` remains the parent-external ATL runtime flag; `0x0067ab1c-0x0067ab20` remains UID000294 `g_pApplication`; `0x0067ab2c-0x0067ab30` remains UID0001P4 `g_pChangeMan`.
- Keep UID00015A exact `0x004b5f00-0x004b6409`, false/non-emitting, with all children unchanged.
- Preserve predecessor padding `0x004b5efc-0x004b5f00`, internal spans `0x004b5f54-0x004b5f60`, `0x004b5fe6-0x004b5ff0`, `0x004b6018-0x004b6020`, `0x004b60ae-0x004b60b0`, `0x004b60bd-0x004b60c0`, `0x004b61d9-0x004b61e0`, `0x004b6341-0x004b6350`, and successor padding `0x004b6409-0x004b6410`.
- Preserve `Nested:0` on UID0001P2 and all current address-order nesting on the FontImageLib executable/vtable children. No relative-level change follows from a metadata reclassification.

## Negative Evidence Summary

- No function covers `0x0067ab24`; no code body, import, RTTI object, or table starts there.
- No nonzero initializer, relocation pointer, all-ones sentinel, adjacent-field merge, or padding claim is supported.
- No second source definition, class-static decorated symbol, template-specialization storage, or file-static route is present.
- No source branch corresponds to the constructor's adjusted-null guard; it is base-adjustment lowering.
- No human source should contain vptr stores, explicit LObject destruction, explicit Singleton publish/clear, scalar flags, size guards, object free, SEH/cookie code, raw vtable/RTTI arrays, or absolute addresses.
- No consumer owns the storage merely because it loads the pointer.
- No evidence changes `BARAM%02d.EFT`, the two-slot layout, existing method bodies, `IsLegacyAssetMode` separation, or source directory.

## IDA Rename / Type / Comment Recommendations

Use source name `g_pFontImageLib` and type `FontImageLib *`. Retain `dword_67AB24`, `unk_67AB24`, and `DAT_0067ab24` only as raw search aliases. Retain `FontImageLib`, `FontSlotStorage`, `FontGlyphRecord`, `m_fontSlots`, `m_scratchBuffer`, and `m_scratchBufferBytes` as accepted source-facing names. Add direct base `Singleton<FontImageLib>` and normalize vtable slot `0x0041b6c0` to inherited `LObject::OnChangeMessage`.

Do not mutate IDA during this report. Any future IDA rename is optional documentation hygiene and is not required for the accepted source route.

## First-Draft C++ Recommendation

### R0 - UID0001P2 physical storage: exact blank formal

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R1 - UID0000QX semantic global at position 0

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FontImageLib;

FontImageLib *g_pFontImageLib = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R2 - UID00005B complete class/header declaration

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DATFile;
class EPFTileContext;
struct RectBounds;

struct FontGlyphRecord
{
    short advance;
    short top;
    short left;
    short bottom;
    short right;
    short reserved0;
    short reserved1;
    unsigned char encodedRows[1];
};

struct FontSlotStorage
{
    DATFile *archiveFile;
    unsigned short maxCellWidth;
    unsigned short maxCellHeightMinus4;
    FontGlyphRecord *glyphTable[0x10000];
};

class FontImageLib;
extern FontImageLib *g_pFontImageLib;

class FontImageLib : public LObject, public Singleton<FontImageLib>
{
public:
    FontImageLib();
    virtual ~FontImageLib();

    void GetFontMetrics(int fontId, short *outWidth, short *outHeight);
    void MeasureGlyphWidth(int fontId,
                           unsigned short glyphId,
                           unsigned short nextGlyphId,
                           bool clearBeforeDecode,
                           const unsigned char *paletteMap,
                           RectBounds *outBounds,
                           short *outAdvance,
                           EPFTileContext *outContext);

private:
    FontSlotStorage *EnsureFontSlotLoaded(int fontId);
    int DecodeGlyphBitmap(const FontGlyphRecord *glyph,
                          unsigned short glyphId,
                          bool clearBeforeDecode,
                          const unsigned char *paletteMap,
                          EPFTileContext *tileContext);

    FontSlotStorage m_fontSlots[2];
    unsigned char *m_scratchBuffer;
    int m_scratchBufferBytes;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R3 - UID0002HP source constructor

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
FontImageLib::FontImageLib()
    : LObject(),
      Singleton<FontImageLib>()
{
    memset(m_fontSlots, 0, sizeof(m_fontSlots));
    m_scratchBuffer = 0;
    m_scratchBufferBytes = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R4 - UID00015B source destructor

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
FontImageLib::~FontImageLib()
{
    for (int i = 0; i < 2; ++i) {
        if (m_fontSlots[i].archiveFile != NULL) {
            delete m_fontSlots[i].archiveFile;
        }
    }

    if (m_scratchBuffer != NULL) {
        GetMemoryMan()->FreeBufferMemory(m_scratchBuffer);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R5 - UID0002HU compiler scalar wrapper: exact blank formal

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R6 - UID00015A mixed aggregate: exact blank formal

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R7 - UID0001XM vtable no-code formal

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No handwritten vtable or RTTI data should be emitted for [UID:0001XM].
// The FontImageLib declaration, virtual destructor, and direct empty
// Singleton<FontImageLib> base regenerate the three-slot vtable and
// three-entry FontImageLib/LObject/Singleton class hierarchy.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R8 - UID0001UL layout no-code formal

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No separate layout C++ should be emitted for [UID:0001UL].
// The FontImageLib declaration owns the LObject base at +0x00, empty
// Singleton<FontImageLib> base and first FontSlotStorage at +0x04,
// second slot at +0x4000c, scratch pointer at +0x80014, and scratch
// byte count at +0x80018. RTTI PMD +0x04 and size 0x8001c prove EBO.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R9 - UID00031Q exact vtable-data no-code formal

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Exact FontImageLib RTTI/vtable storage is compiler-generated from the
// FontImageLib declaration, direct Singleton<FontImageLib> base, inherited
// LObject virtuals, and virtual destructor. Do not hand-port 0x0061a5f0 data.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R10 - UID0001UK covered-by support-type formal

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FontGlyphRecord is declared before FontImageLib by [UID:00005B].
// This page remains exact resource-record layout evidence only.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R11 - UID0001UM covered-by support-type formal

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FontSlotStorage is declared before FontImageLib by [UID:00005B].
// This page remains exact per-font-slot layout evidence only.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

## Final Recommendation

C01-C19 and R0-R11 are implemented without compression; C20 remains the exact supervisor-owned manual handoff and is excluded from B003 edits. Physical storage and the scalar wrapper are false/non-emitting, semantic owners are preserved, the global is position 0, complete support records precede the Singleton-aware class/extern, and the two false handwritten singleton assignments are absent. All resource, method, layout, range, padding, consumer, history, rejected-alternative, and compiler/source evidence remains. Thirteen scoped validators and waited command 15543 passed; no B003 implementation item remains.

## Recommended Target Doc Changes

For UID0001P2, the following accepted changes are implemented:

- Current metadata is `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000QX`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position, `Nested:0`, and blank R0.
- Item Summary: `Exact four-byte loader-zero FontImageLib singleton backing slot at 0x0067ab24, SHA256 DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119, with 52 direct refs split into three compiler-lowered Singleton lifecycle writes/clears, one Application cleanup read, and 48 render/UI/text reads; semantic UID0000QX owns the sole source definition, while this physical page is false/non-emitting.`
- Full MCP provenance, zero-fill/PE-section evidence, exact xref inventory, predecessor/successor boundaries, source/storage split, rejected aliases/owners, generated result, score rationale, and historical correction from the prior true/comment-emitting state are incorporated.

## Recommended Support Doc Changes

Implemented support results:

- UID0000QX is `92/94`, owner/emitter JH unchanged, true, position `0`, exact R1, with complete 52-ref/lifetime, direct Singleton cause, one-definition/header split, ordering, aliases, negative evidence, and score rationale.
- UID00005B is `94/94`, owner/emitter JH unchanged, true, blank position, exact R2, with complete support structs before first use, direct bases, RTTI hierarchy, PMD/EBO layout, implicit lifecycle, extern/definition contract, inherited vtable slots, and preserved methods/fields/access/history.
- UID0000JH is `94/94` on preserved `NexusTK/render/`; it records the historical generated defect, current accepted output order, false physical/scalar routes, no-duplicate/no-ABI-source assertions, and all existing resource/method/helper exclusions.
- UID00015A is `90/94`, preserving NONE/false/blank R6/Nested and all children/padding; only the stale final-declaration blocker was historicalized, with direct Singleton/source/compiler classification added.
- UID0002HP is `92/94`, preserving class owner/emitter/true/blank position/Nested `+4`; exact R3 retains all bytes, caller, allocation, memset, fields, return, vtable, and negative evidence while publication is implicit.
- UID00015B is `92/94`, preserving class owner/emitter/true/blank position/Nested; exact R4 retains slot/scratch cleanup, no-direct-caller state, padding, vtable/base evidence, scalar parity, and negative evidence while clear is implicit.
- UID0002HU is `92/96`, with semantic class owner, false/no-emitter/blank position and blank R5; complete ABI/delete-flag/size/vtable/cleanup/clear evidence and compiler exclusions remain.
- UID0001XM is `92/96`, class owner/emitter/true, with exact R7, direct Singleton RTTI hierarchy, inherited slot names, and table/boundary/compiler proof.
- UID0001UL is `92/96`, class owner/emitter/true, with exact R8/Singleton EBO row and preserved slot/scratch/field consumers and lexical caps.
- UID0001UK is `92/94`, class owner/emitter/true/blank position; exact R10 replaces the duplicate late struct while R2 owns the complete declaration and this page retains all field/resource/unknown-name evidence.
- UID0001UM is `92/94`, class owner/emitter/true/blank position; exact R11 replaces the duplicate late struct while R2 owns the complete declaration and this page retains all stride/field/loader/destructor evidence.
- UID00031Q is `92/96`, vtable owner/emitter/true/Nested `+4`; exact R9, inherited `OnChangeMessage`, direct Singleton RTTI, dwords/range/string boundary/history are present.
- Verify-only unless exact callback-time contradiction exists: UID0002HQ, UID0002HR, UID0002HS, UID0002HT, UID0003XA, LObject support, Application pages, GrafPort/text consumers, UID000294/UID000295/UID0001P3/UID0001P4, and all unrelated FontImageLib file content.

Exact support Item Summary values:

| UID | Exact implemented Item Summary |
| --- | --- |
| 0000QX | `Sole externally linked FontImageLib pointer definition at source position 0 with a local class forward declaration, exact zero-filled physical storage UID0001P2, 52 refs, direct Singleton<FontImageLib> PMD +0x04 publication/reverse-clear cause, one class-header extern, FontImageLib.cpp ownership, and no duplicate or handwritten lifecycle source.` |
| 00005B | `Complete FontImageLib declaration with direct LObject and empty Singleton<FontImageLib> bases, FontGlyphRecord/FontSlotStorage declarations before first use, PMD +0x04 EBO and exact 0x8001c layout, one typed global extern, source method inventory, inherited three-slot vtable, two DAT-backed font slots, scratch state, and compiler scalar/vtable/RTTI exclusions.` |
| 00015A | `Exact non-emitting mixed FontImageLib executable index retaining seven FontImageLib source/compiler children, separate UID0003XA IsLegacyAssetMode, every internal and outer padding boundary, direct Singleton source cause, authored constructor/destructor versus compiler scalar-wrapper split, and no aggregate C++.` |
| 0002HP | `Exact source FontImageLib constructor at 0x004b5f00-0x004b5f54 with sole Application startup caller, 0x8001c allocation, direct LObject and Singleton<FontImageLib> base initialization, compiler-lowered +0x04 EBO publication, class vtable install, 0x80010 two-slot clear, scratch clears, and no handwritten singleton assignment.` |
| 00015B | `Exact source FontImageLib destructor at 0x004b5f60-0x004b5fe6 with no direct callers, two 0x40008-stride DATFile deletes, scratch-buffer free, implicit reverse Singleton<FontImageLib> clear before LObject teardown, scalar-wrapper parity, exact padding, and no handwritten global clear or ABI mechanics.` |
| 0002HU | `Exact vtable-only compiler scalar deleting wrapper at 0x004b6350-0x004b6409 around authored slot/scratch cleanup, implicit Singleton clear, LObject teardown, flags 1/4, 0x8001c size guard, and optional object free; false/non-emitting because UID00015B owns the sole handwritten destructor body.` |
| 0001XM | `Exact compiler-generated FontImageLib primary vtable with scalar deleting destructor, inherited LObject::GetRuntimeClass and LObject::OnChangeMessage, direct three-entry FontImageLib/LObject/Singleton<FontImageLib> RTTI hierarchy, PMD +0x04 EBO, lifecycle stores, UID00031Q concrete data, and no handwritten arrays.` |
| 0001UL | `Exact 0x8001c FontImageLib layout with LObject +0x00, empty Singleton<FontImageLib> and first FontSlotStorage EBO overlap at +0x04, second slot +0x4000c, scratch pointer/byte count +0x80014/+0x80018, 0x80010 constructor clear, and covered-by class-source disposition.` |
| 0001UK | `Exact variable-size FontGlyphRecord resource declaration with consumed advance/bounds fields, encoded rows at +0x0e, BARAM%02d.EFT pointer-table provenance, decoder token consumers, two reserved 16-bit fields, and one leading declaration through UID00005B; this page emits only a covered-by comment.` |
| 0001UM | `Exact 0x40008 FontSlotStorage declaration with DATFile pointer, two 16-bit metrics, 0x10000 FontGlyphRecord pointer table, loader/destructor consumers, two-object embedding, and one leading declaration through UID00005B; this page emits only a covered-by comment.` |
| 00031Q | `Exact 0x0061a5f0-0x0061a600 FontImageLib COL/vtable child with scalar wrapper, inherited GetRuntimeClass/OnChangeMessage slots, direct Singleton RTTI/PMD/EBO proof, lifecycle vtable stores, compiler no-code route, and BARAM%02d.EFT successor boundary.` |

## Score And Metadata Recommendation

| UID | Historical pre-callback | Implemented | Exact metadata/formal disposition | Rationale/cap |
| --- | --- | --- | --- | --- |
| 0001P2 | 86/90 | 92/94 | QX / false / no emitter / blank position / Nested 0 / R0 blank | exact storage/lifetime/source route closed; original spelling cap |
| 0000QX | 90/90 | 92/94 | JH / true / JH / position 0 / R1 | one definition, external linkage, source order closed |
| 00005B | 92/92 | 94/94 | JH / true / JH / blank / R2 | complete class, direct bases, EBO, extern; lexical caps remain |
| 0000JH | 92/92 | 94/94 | file route unchanged | complete source/header/compiler inventory and output contract |
| 00015A | 88/92 | 90/94 | NONE / false / no emitter / blank R6 | exact mixed index and children/padding closed; not source-bearing |
| 0002HP | 90/93 | 92/94 | 05B / true / 05B / R3 | exact source body/caller plus direct-base cause |
| 00015B | 90/92 | 92/94 | 05B / true / 05B / R4 | exact authored body plus reverse-base clear cause |
| 0002HU | 88/93 | 92/96 | 05B / false / no emitter / R5 blank | exact compiler-only ABI wrapper |
| 0001XM | 89/93 | 92/96 | 05B / true / 05B / R7 | exact RTTI hierarchy, slots, compiler route |
| 0001UL | 88/92 | 92/96 | 05B / true / 05B / R8 | exact direct bases/EBO/size/field offsets |
| 0001UK | 90/91 | 92/94 | 05B / true / 05B / R10 covered-by | declaration retained once in R2; resource layout exact, two names capped |
| 0001UM | 90/91 | 92/94 | 05B / true / 05B / R11 covered-by | declaration retained once in R2; exact 0x40008 layout, metric spelling capped |
| 00031Q | 90/94 | 92/96 | 1XM / true / 1XM / R9 / Nested +4 | exact dwords, slot identities, boundaries, RTTI route |

## Open Questions With Attempted Resolution

- Original variable spelling: binary cannot recover it. `g_pFontImageLib` is the strongest established project/source name; confidence capped at 94 rather than deferring code.
- `0` versus `NULL`: not binary-recoverable. Current project definition uses `0`; preserve it consistently in C++03 source.
- Exact historical header filename/include graph: logical `FontImageLib.h` is strongly implied but not recovered. The managed class/global ordering is independently compilable and does not require inventing include statements.
- Support-type order: resolved. `FontSlotStorage` is a by-value member and must be complete before the class; R2 therefore carries both existing exact struct declarations once, while R10/R11 prevent late duplicates.
- Whether publication/clear were handwritten: resolved against handwritten form by direct Singleton RTTI PMD, constructor adjustment, destructor order, and project analogs.
- Whether the scalar wrapper needs source: resolved no. Virtual source destructor regenerates it; direct ABI source would be wrong.
- Whether target storage should emit a covered-by comment: resolved no. False/blank physical storage is the coherent current representation; evidence remains in prose.
- Whether consumers imply another owner: resolved no; all 48 reads are non-owning.
- Whether a split/padding change is needed: resolved no; exact dword and all island boundaries are stable.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Read-only current manual snapshots after callback and unrelated external epoch drift:

| Root | SHA256 | Bytes / lines | Affected current rows |
| --- | --- | --- | --- |
| `by-memory/-coverage-report.md` | `5F05B4ED5ED2F1A37BBDBAEDB550B47AF85A5BC884E42C77118D25055EEFBE9C` | 1,870,851 / 4,422 | 1447-1454, 3912, 4234 |
| `by-global/-coverage-report.md` | `12213CE572404A7960F9819A401BE4197615A97BDB4788868614228F349C7292` | 91,643 / 214 | 86 |
| `by-class/-coverage-report.md` | `6A6DB4EEF150CC2915749322C1FAD17F6D250D269FCF19257276C4824EC69849` | 242,188 / 623 | 216 |
| `by-file/-coverage-report.md` | `F512B5308D0C61931AAD8848307DA4AE67073FDB689BA0543BAA9750A5229456` | 139,871 / 316 | 98 |
| `by-type/by-vtable/-coverage-report.md` | `16E3B845B82EAFE0EF7902F3CC2374FD61375018A9A0087756A577DCE6142DD3` | 64,820 / 142 | 60 |
| `by-type/by-struct/-coverage-report.md` | `144A36A822D9BDE72C3B52DB75F9AD38A63F6F8AF66EFDD6365D3A74474B769C` | 56,905 / 137 | 52-54 |

The first four manual roots advanced through unrelated external work after Gate 1; the FontImageLib rows remain textually stale/unapplied. UID00015A/2HP/15B/2HU remain at 1447/1448/1449/1454, UID00031Q moved to 3912, UID0001P2 moved to 4234, and global/class/file rows remain 86/216/98. The vtable/struct roots are unchanged. The exact replacement text below remains a no-loss handoff over this current union; B003 did not edit any coverage file.

Current generated tracker readback is external command 15549, SHA256 `F2E2FA14786D3987AD84CE3092977833D16218886F7474B21E0E8BDD7868935F`, 1,535,343 bytes / 6,218 lines; UID0001P2 is the sole row at line 3827 with `92/94`, average `93.0`, and `false`. B003 waited command 15543 and its tracker SHA `69B21C86E129368CF2647889A2DFA67CE52B5A6043200726981DAB62FB6749B7` are retained as callback-time history. The tracker is validator-owned and receives no manual replacement text; command 15501 is historical pre-callback evidence.

Supervisor-owned exact replacement rows follow. B003 does not edit manual coverage.

Replace by-memory row 1447, preserving preceding `0x004b5efc-0x004b5f00` padding and following children:

```markdown
    - [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md) 0x004b5f00-0x004b6409 | mixed executable index | FontImageLib : not_reconstructable : 90% : very-strong : Exact non-emitting mixed island retaining seven FontImageLib source/compiler children plus separate UID0003XA IsLegacyAssetMode, all internal padding and predecessor/successor boundaries; direct LObject and Singleton<FontImageLib> source hierarchy, sole global route, authored constructor/destructor versus compiler scalar wrapper, complete 0x8001c layout, resource/helper exclusions, and no aggregate C++ are resolved.
```

Replace by-memory rows 1448, 1449, and 1454; leave 1450-1453 unchanged:

```markdown
        - [UID:0002HP][0x004b5f00-0x004b5f54.FontImageLibConstructor](by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md) 0x004b5f00-0x004b5f54 | class constructor | FontImageLib::FontImageLib : reconstructable : 92% : very-strong : Exact source constructor with direct LObject and Singleton<FontImageLib> base initialization, compiler-lowered +0x04 EBO publication, sole Application startup allocation/caller, 0x80010 two-slot clear, scratch pointer/byte-count clears, 0x8001c layout, and no duplicate handwritten singleton assignment.
        - [UID:00015B][0x004b5f60-0x004b5fe6.FontImageLibDestructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md) 0x004b5f60-0x004b5fe6 | class destructor | FontImageLib::~FontImageLib : reconstructable : 92% : very-strong : Exact source destructor with no direct callers, two DATFile slot deletes at 0x40008 stride, scratch-buffer free, compiler vtable/base exclusions, and implicit reverse Singleton<FontImageLib> clear before LObject teardown; all padding and scalar-wrapper parity preserved without handwritten global clear.
        - [UID:0002HU][0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor](by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md) 0x004b6350-0x004b6409 | compiler scalar deleting destructor | FontImageLib scalar deleting destructor : not_reconstructable : 92% : very-strong : Exact vtable-only MSVC wrapper around authored slot/scratch cleanup, implicit Singleton clear, LObject teardown, delete flags 1/4, 0x8001c size guard, and optional object free; semantic class-owned but blank/non-emitting because UID00015B is the sole handwritten destructor body.
```

Replace current by-memory row 3912 between UID00025D and UID00025E:

```markdown
        - [UID:00031Q][0x0061a5f0-0x0061a600.FontImageLibVtableData](by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md) 0x0061a5f0-0x0061a600 | vtable-data | FontImageLibVtableData : reconstructable : 92% : very-strong : Exact FontImageLib COL plus three-slot primary vtable with compiler scalar destructor, inherited LObject::GetRuntimeClass and LObject::OnChangeMessage, constructor/destructor/scalar stores, direct three-entry FontImageLib/LObject/Singleton<FontImageLib> RTTI hierarchy and PMD +0x04 EBO, compiler no-raw-array disposition, and exact BARAM%02d.EFT successor boundary.
```

Replace current by-memory row 4234 between UID000295 and UID0001P3:

```markdown
    - [UID:0001P2][0x0067ab24-0x0067ab28.g_pFontImageLib](by-memory/0x0067ab24-0x0067ab28.g_pFontImageLib.md) 0x0067ab24-0x0067ab28 | physical singleton storage | g_pFontImageLib backing slot : not_reconstructable : 92% : very-strong : Exact four-byte loader-zero storage, bytes 00 00 00 00, with 52 refs split into three compiler-lowered Singleton<FontImageLib> lifecycle writes/clears, one Application cleanup read, and 48 render/UI/text reads; semantic UID0000QX owns the sole typed definition, so this physical child is false/non-emitting with exact adjacent singleton boundaries.
```

Replace by-global row 86 between UID0000QV and UID0000QY:

```markdown
- [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md) : reconstructable : 92% : very-strong : Sole externally linked FontImageLib pointer definition at source position 0 with local class forward declaration, exact false backing storage UID0001P2, zero initializer, 52-reference lifecycle/consumer closure, direct Singleton<FontImageLib> PMD +0x04 publication/reverse-clear cause, one class-header extern, FontImageLib.cpp ownership, and rejected duplicate/static/class-member/explicit-lifecycle alternatives.
```

Replace by-class row 216 between UID00005A and UID00005C:

```markdown
- [UID:00005B][FontImageLib](by-class/FontImageLib.md) : reconstructable : 94% : very-strong : Complete FontImageLib declaration with direct LObject and empty Singleton<FontImageLib> bases, PMD +0x04 EBO over the first FontSlotStorage, exact 0x8001c layout, typed global extern, constructor/virtual destructor/metrics/measure/loader/decode inventory, sole-definition and implicit singleton lifecycle policy, exact inherited three-slot vtable, two DAT-backed font slots, scratch storage, resource ownership, and compiler scalar/vtable/RTTI exclusions.
```

Replace by-file row 98 between UID0000JG and UID0000JI:

```markdown
- [UID:0000JH][FontImageLib](by-file/FontImageLib.md) : reconstructable : 94% : very-strong : `NexusTK/render/FontImageLib.cpp` source root with one position-0 g_pFontImageLib definition, one class-header extern, direct LObject plus Singleton<FontImageLib> declaration, implicit publication/clear, exact 0x8001c/two-slot layout, constructor/destructor/metrics/measure/loader/decode source bodies, compiler scalar/vtable/RTTI exclusions, BARAM%02d.EFT ownership, mixed UID00015A/UID0003XA separation, text-consumer exclusions, and generated one-definition/declaration-before-use contract.
```

Replace by-vtable row 60 between FolderTreePaneTreeVtable and FpsPane_vtables:

```markdown
- [UID:0001XM][FontImageLibVtable](by-type/by-vtable/FontImageLibVtable.md) : reconstructable : 92% : very-strong : Exact three-slot FontImageLib primary vtable routed to the class, with compiler scalar deleting destructor, inherited LObject::GetRuntimeClass and LObject::OnChangeMessage, direct FontImageLib/LObject/Singleton<FontImageLib> RTTI hierarchy, PMD +0x04 EBO, lifecycle stores, exact UID00031Q child/string boundary, and compiler-generated no-raw-table source disposition.
```

Replace by-struct row 53 between FontGlyphRecord and FontSlotStorage:

```markdown
- [UID:0001UL][FontImageLibLayout](by-type/by-struct/FontImageLibLayout.md) : reconstructable : 92% : very-strong : Exact 0x8001c FontImageLib layout with LObject at +0x00, direct empty Singleton<FontImageLib> PMD +0x04 EBO overlapping first 0x40008 FontSlotStorage, second slot at +0x4000c, scratch pointer/byte count at +0x80014/+0x80018, 0x80010 constructor clear, loader/decode/destructor consumers, typed global lifecycle, and covered-by class-source/no-duplicate-layout disposition.
```

Replace by-struct rows 52 and 54 while retaining UID0001UL between them:

```markdown
- [UID:0001UK][FontGlyphRecord](by-type/by-struct/FontGlyphRecord.md) : reconstructable : 92% : very-strong : Exact variable-size BARAM%02d.EFT glyph payload declaration with advance/bounds fields, encoded rows beginning at +0x0e, loader pointer-table provenance, decoder token consumers, two conservatively reserved 16-bit fields, and one-definition ordering through the leading UID00005B class formal; this page emits only a covered-by declaration comment.
- [UID:0001UM][FontSlotStorage](by-type/by-struct/FontSlotStorage.md) : reconstructable : 92% : very-strong : Exact 0x40008 per-font slot declaration with DATFile pointer, two 16-bit metrics, 0x10000 FontGlyphRecord pointer table, BARAM%02d.EFT loader and destructor consumers, and one-definition ordering before FontImageLib's by-value two-slot member through UID00005B; this page emits only a covered-by declaration comment.
```

No manual changes are proposed for verify-only UID0002HQ/HR/HS/HT, Application, LObject, GrafPort, or neighboring globals.

## Follow-Up Actions

Ordinary implementation and callback validation are complete, and the exact supervisor-owned manual text is retained against the current read-only roots. Manual coverage application and exact report validation/execution/count/path/move/archive state are external supervisor/validator-owned and are neither asserted nor directed by this artifact. B003's boundary is factual: no coverage/generated/tracker/audit/supervisor/validator-state/IDA/lifecycle file was edited and no `execute_report`, probe, move, archive, or report lifecycle command was run. No B003 implementation item remains.

## Confidence

Overall recommendation confidence: `94/100` (very strong). Address, bytes, PE identity, xrefs, direct bases, PMD/EBO, function bodies, lifetime, vtable, source/compiler split, one-definition route, and generated defect are exact. The bounded caps are original variable/member spelling, exact historical header filename/include order, and `0` versus `NULL`; none blocks realistic C++03 source.

## Validator Results

Every changed ordinary page passed one scoped `--mode file --apply --queue-timeout 240` validation while its sole B003 lease was held, then the lease was released before the next acquisition. All commands exited `0` with `ok:1`:

| Command | Timestamp | Scoped path | Result and bounded side effects |
| --- | --- | --- | --- |
| 15510 | `2026-07-20T18:01:58-04:00` | `by-memory/0x0067ab24-0x0067ab28.g_pFontImageLib.md` | completion/confidence and true->false/emitter/block->blank registry updates; one successor UID link label normalization; refresh deferred |
| 15512 | `2026-07-20T18:03:16-04:00` | `by-global/g_pFontImageLib.md` | completion/confidence, position `0`, and formal-hash registry updates; refresh deferred |
| 15515 | `2026-07-20T18:04:16-04:00` | `by-class/FontImageLib.md` | completion/confidence/formal registry updates; four pre-existing missing UID0003XA warnings and two reference-index removals; refresh deferred |
| 15519 | `2026-07-20T18:05:13-04:00` | `by-type/by-struct/FontGlyphRecord.md` | completion/confidence/formal updates; validator link insertion/reference removal recorded; accepted literal R10 restored before release and captured by final registry rebuild |
| 15522 | `2026-07-20T18:06:45-04:00` | `by-type/by-struct/FontSlotStorage.md` | completion/confidence/formal updates; validator link insertion/reference removal recorded; accepted literal R11 restored before release and captured by final registry rebuild |
| 15525 | `2026-07-20T18:07:43-04:00` | `by-file/FontImageLib.md` | completion/confidence updates; four pre-existing missing UID0003XA warnings; refresh deferred |
| 15528 | `2026-07-20T18:08:34-04:00` | `by-memory/0x004b5f00-0x004b6409.FontImageLib.md` | completion/confidence updates; six pre-existing missing UID0003XA warnings; refresh deferred |
| 15532 | `2026-07-20T18:09:25-04:00` | `by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md` | completion/confidence and R3 formal-hash updates; refresh deferred |
| 15533 | `2026-07-20T18:10:13-04:00` | `by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md` | completion/confidence and R4 formal-hash updates; refresh deferred |
| 15535 | `2026-07-20T18:11:02-04:00` | `by-memory/0x004b6350-0x004b6409.FontImageLibScalarDeletingDestructor.md` | completion/confidence and true->false/emitter/block->blank registry updates; refresh deferred |
| 15537 | `2026-07-20T18:11:42-04:00` | `by-type/by-vtable/FontImageLibVtable.md` | completion/confidence and R7 formal-hash updates; refresh deferred |
| 15539 | `2026-07-20T18:12:32-04:00` | `by-type/by-struct/FontImageLibLayout.md` | completion/confidence and R8 formal-hash updates; refresh deferred |
| 15542 | `2026-07-20T18:13:23-04:00` | `by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md` | completion/confidence and R9 formal-hash updates; refresh deferred |
| 15543 | `2026-07-20T18:13:35-04:00` | `by-file/FontImageLib.md --wait-generated` | final registry rebuild and generated refresh completed; four pre-existing UID0003XA warnings plus unrelated project-wide fallback/empty-child warnings; no FontImageLib failure |

Managed formal readback matches the accepted report exactly. Inner-body SHA256 values are: R0/R5/R6 blank `E3B0C44298FC1C149AFBF4C8996FB92427AE41E4649B934CA495991B7852B855`; R1 `030A15CC5ED45C0E983BC1AA98C1C3F83BF902CCCBD8D2956EF31E044DCF54A8`; R2 `407B8965C1F5B27B0859E4ECF9AB59B2FAF1AC961EC4F0DA023C0A09570454E3`; R3 `0A2EA697F142FDEE5F990F2C9C69E1EE7F5FC75B1A7587FF084E4E7FE6AC2170`; R4 `EF6B812D1BA9FEDE3EDA6843D116D3ADE414B1E5A20050BE5F9A10883244C620`; R7 `1EC8A8B0FE30D783459628A266A3A5EC5856EA284DCB5E48B26A46DE8E7518D7`; R8 `6CE90173DA7F06E0CE13847DCB0250C0F4515CCDF4FA516CCA2FD5637676D9C1`; R9 `6B9692CF84D647041DBB5C6A29726820540B42014C711C2DD36009DCC420B2F0`; R10 `1AECB0DF62C5465776D542DE4AC635E512A50793C6C6929F89F55082229021A7`; R11 `07F1BA4BFADA699F4ECB295662748E20F0CB79CC5A794A33F9AE365F3A4F7D45`.

B003 waited generated readback is command/header `000000015543`, refreshed `2026-07-20T18:13:35-04:00`, SHA256 `DEECB00A78352C99977F47E5355C6A799F43B631F12CAB863C169C8BFF15B149`, 9,357 bytes / 262 lines. Current external command/header `000000015548`, refreshed `2026-07-20T18:16:09-04:00`, SHA256 `36D5E0953D6535AEEF956240FD9D1ED396475C96F897C73D1CE3B521364FDD9B`, has identical 9,357-byte/262-line semantic content and all exact assertions below:

- one position-0 global definition at line 10 and one compatible extern at line 38;
- one `FontGlyphRecord` and one `FontSlotStorage`, both before class and method use;
- one direct `LObject, Singleton<FontImageLib>` class at line 40, closed at line 67 before the first qualified definition at line 70;
- constructor, destructor, `GetFontMetrics`, `MeasureGlyphWidth`, `EnsureFontSlotLoaded`, and `DecodeGlyphBitmap` each exactly once;
- zero `g_pFontImageLib = this` and zero indented lifecycle clear; the sole zero assignment is the intended global definition;
- zero UID0001P2 text/body, zero UID0002HU text/body, and zero Empty Emitter Markers;
- R7, R8, R10, and R11 comments each once. R9 is exact on its nested compiler-data destination and intentionally has no recursive source emission or marker;
- no duplicate/wrong-range source and no handwritten vtable/RTTI/EH/cookie/scalar-delete/base-teardown definition.

## Changed Files

- Report updated in place: `tools/leaser/Agents/Agent-B003/research/0001P2-g_pFontImageLib-source-quality.md`.
- Changed ordinary pages: UID0001P2, UID0000QX, UID00005B, UID0001UK, UID0001UM, UID0000JH, UID00015A, UID0002HP, UID00015B, UID0002HU, UID0001XM, UID0001UL, and UID00031Q at the exact paths/hashes in the implemented-destination table.
- Verify-only pages unchanged by B003: UID0002HQ/HR/HS/HT, UID0003XA, LObject, Application, GrafPort/text consumers, neighboring globals, and unrelated FontImageLib pages. Callback reread found no contradiction requiring scope expansion.
- Manual coverage/generated/tracker/audit/supervisor/validator-state/IDA/lifecycle files edited manually by B003: zero. Validator-generated side effects are recorded under command IDs 15510-15543.
- Each ordinary lease was acquired only for its active edit/validation and released immediately. Final ledger SHA256 `EA2FA43FFE5ADAEE941CD801C5EA2E206A3D9B9D7FFC692F685134199392AAC4`, 166 bytes / 8 lines, reports `No active leases` and zero B003 entries.

## Implementation Tracking Checklist

- [x] Supervisor validated the exact pre-callback report artifact before callback.
- [x] Reread goal, accepted report, current leases, all intended ordinary destinations, generated source, and manual roots immediately before callback edits.
- [x] Confirmed accepted live bounded MCP evidence remained coherent; no callback-time contradiction required a new MCP conclusion or scope change.
- [x] Leased only UID0001P2, reread/no-loss rebased, applied exact `92/94` false/non-emitting metadata, R0, summary/evidence/history, scoped-validated, and released.
- [x] Leased only UID0000QX, reread/no-loss rebased, applied `92/94`, position 0, R1 and full one-definition/Singleton/lifetime evidence, scoped-validated, and released.
- [x] Leased only UID00005B, reread/no-loss rebased, applied `94/94`, exact R2, direct bases/EBO/extern/vtable/lifecycle proof, preserved all current class details, scoped-validated, and released.
- [x] Leased only UID0001UK, reread/no-loss rebased, applied `92/94`, exact R10 covered-by formal and declaration-order evidence without losing resource/field history, scoped-validated, and released.
- [x] Leased only UID0001UM, reread/no-loss rebased, applied `92/94`, exact R11 covered-by formal and declaration-order evidence without losing stride/loader/destructor history, scoped-validated, and released.
- [x] Leased only UID0000JH, reread/no-loss rebased, applied `94/94` source/header/order/compiler inventory without losing resources/methods/history, scoped-validated, and released.
- [x] Leased only UID00015A, reread/no-loss rebased, applied `90/94`, R6 blank/current blocker correction, preserved every child/padding/mixed-owner fact, scoped-validated, and released.
- [x] Leased only UID0002HP, reread/no-loss rebased, applied `92/94` and exact R3, removed only explicit singleton assignment, preserved all behavior/evidence, scoped-validated, and released.
- [x] Leased only UID00015B, reread/no-loss rebased, applied `92/94` and exact R4, removed only explicit singleton clear, preserved all cleanup/evidence, scoped-validated, and released.
- [x] Leased only UID0002HU, reread/no-loss rebased, applied `92/96`, false/no-emitter/blank R5, preserved full compiler ABI proof, scoped-validated, and released.
- [x] Leased only UID0001XM, reread/no-loss rebased, applied `92/96`, R7, exact direct RTTI bases and inherited slot names, preserved table/compiler/history facts, scoped-validated, and released.
- [x] Leased only UID0001UL, reread/no-loss rebased, applied `92/96`, R8, exact Singleton EBO layout, preserved all field consumers/history, scoped-validated, and released.
- [x] Leased only UID00031Q, reread/no-loss rebased, applied `92/96`, R9, normalized slot +8 to inherited `OnChangeMessage`, added Singleton RTTI, preserved exact bytes/range/string boundary/history, scoped-validated, and released.
- [x] Verified UID0002HQ/HR/HS/HT, UID0003XA, LObject, Application, consumers, and neighboring global pages unchanged absent an exact contradiction.
- [x] Preserved predecessor/successor/global boundaries and every executable-island padding span exactly.
- [x] Preserved `Nested:0` target, `Nested:+4` vtable-data child, and all unrelated nesting.
- [x] Preserved `NexusTK/render/` source route and rejected ImageLib/GrafPort/Application/static/class-member/duplicate ownership.
- [x] Preserved exact PE/hash/bytes, 52-reference grouping, startup allocation/call, cleanup call, RTTI/PMD/EBO, layout, vtable, and negative evidence at report-level depth.
- [x] Ran final authorized `by-file/FontImageLib.md` scoped validation with `--wait-generated` after all ordinary validators.
- [x] Recorded every validator command ID, timestamp, exit, ok count, warnings/side effects, and lease release in this report.
- [x] Read generated `FontImageLib.cpp` without editing it and recorded header command/time/hash/bytes/lines.
- [x] Proved one global definition before all uses, one compatible extern, and class closure before child definitions.
- [x] Proved one constructor and one ordinary destructor definition with no explicit `g_pFontImageLib = this` or lifecycle `g_pFontImageLib = 0` inside either method.
- [x] Proved zero UID0001P2 physical marker/body and zero UID0002HU scalar marker/body.
- [x] Proved R7-R11 destination dispositions and applicable generated comments with no Empty Emitter Marker for the accepted source route.
- [x] Proved no duplicate/wrong-range source and no handwritten vtable/RTTI/EH/cookie/scalar-delete/base-teardown code.
- [x] Reread every changed ordinary destination and captured final full SHA256/bytes/lines.
- [x] Reread all six manual roots after callback and rebased the exact supervisor-owned rows over external epochs without editing them.
- [x] Updated C01-C20 to legal terminal callback states with claim-specific destination/validator/generated proof.
- [x] Updated Current Target State, Final Recommendation, Validator Results, Changed Files, and lifecycle wording to durable callback truth.
- [x] Checked each callback row only after independent readback; no proposed or unchecked implementation row remains.
- [x] Confirmed no B003 lease remains and no prohibited file/action occurred.
- [x] Ended the callback artifact with the exact supervisor-requested terminal marker only after all accepted work was complete.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000015591","destination_path":"executed-b-agent-research/B003/0001P2-g_pFontImageLib-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0001P2-g_pFontImageLib-source-quality.md","timestamp":"2026-07-21T08:22:48-04:00","uid":"0001P2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
