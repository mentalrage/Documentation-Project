** TARGET-REPORT-UID:00028R **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00028R g_pSoundManager Ownership / Split Research

## Finalized Report / Current Recommendation

- Current implemented disposition: [UID:00028R] `0x0067a7d0-0x0067a7d4` is exact false/non-emitting binary backing storage for one externally linked `SoundManager *g_pSoundManager`; validator-issued [UID:0004UF][g_pSoundManager](by-global/g_pSoundManager.md) owns the sole handwritten module definition in `NexusTK/audio/SoundManager.cpp`.
- UID00028R is now `92/94`, canonical owner `0004UF`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, with exact path/title/range and `Nested:0` preserved.
- UID0004UF is implemented at `92/94`, owner/emitter [UID:0000NV][SoundManager](by-file/SoundManager.md), position `0`, with Destination 2 as the only module definition. The matching external declaration remains separate proper shared-header/class placement and is not emitted redundantly from the by-global source block.
- The complete [UID:0000DG][SoundManager](by-class/SoundManager.md) declaration remains `92/94` and now includes the RTTI-proven direct `Singleton<SoundManager>` base before `TimerHandler`. Exact constructor UID0004UG, ordinary destructor UID0004UH, constructor-unwind clear UID0004UI, scalar-deleting-destructor UID0004UJ, and vtable UID0004UK are registered. Only constructor/destructor are source-bearing; Singleton publication/clear, EH cleanup, scalar wrapper, vptr stores, vector/base teardown, and vtable/RTTI bytes remain compiler manifestations.
- Confidence: very strong for storage, type, linkage, exact range, 117-reference fanout, five lifetime writes/clears, direct Singleton base, `0x10ac` object size, file placement, generated uniqueness, and no-code compiler dispositions; strong for exact private lexical spellings and null-literal style.
- Accepted same-report implementation callback completed. Thirteen ordinary pages were created/updated and scoped-validated; final waited generated command `000000015501` verified the accepted source shape. Manual coverage remained read-only with the exact thirteen-action supervisor handoff retained. B005 ran no report execution or lifecycle command; independent review and lifecycle state are supervisor-owned external facts not claimed by this artifact.

## Supporting Research

### Current project evidence read

- Read the target, [UID:0000DG][SoundManager](by-class/SoundManager.md), [UID:0000NV][SoundManager](by-file/SoundManager.md), [UID:0001I7][SoundManagerMusicSelection](by-memory/0x005797b0-0x0057a25c.SoundManagerMusicSelection.md), [UID:0001I8][SoundManagerAudioHelperCluster](by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md), [UID:0001IC][SoundManagerDriverDestructorAndPathHelpers](by-memory/0x0057b490-0x0057bf6e.SoundManagerDriverDestructorAndPathHelpers.md), and [UID:00026I][NetworkAndAudioReadOnlyData](by-memory/0x0062ce50-0x0062cfd8.NetworkAndAudioReadOnlyData.md).
- Read adjacent physical globals [UID:0001OX][g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md), [UID:0001OY][g_pSimpleHelpPane2](by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md), and nearby [UID:00028Q][g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md). They prove independent four-byte boundaries rather than one aggregate storage object.
- Read current Config, DATFile, DATFileMgr/HasDATEntry, TimerHandler/TimerMgr, Application cleanup, playback, Redbook, scanner, callback, SoundPathVector, and consumer documentation needed to preserve constructor/destructor behavior.
- Read semantic-global precedents [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), [UID:0000RK][g_pMessageShowPane](by-global/g_pMessageShowPane.md), and [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md). The newest accepted pattern emits one definition from a semantic global page and leaves physical storage evidence non-emitting.
- Read generated `auto-generated/NexusTK/audio/SoundManager.cpp` from B005's authorized waited command `000000015501` and took a time-bounded read-only checkpoint of validator-owned `auto-generated/-ag-research-tracker.md` at external command `000000015521`; exact checkpoint hashes, counts, order, and prior evidence-time epochs are recorded under Changed Files and Validator Results.

### Prior-report search record

- Exact terms searched: `00028R`, `UID00028R`, `0x0067a7d0`, `g_pSoundManager`, `dword_67A7D0`, `DAT_0067a7d0`, `Singleton<SoundManager>`, `SoundManagerConstructor`, `0x00579a30`, `0x00579cb0`, `0x0057b9a0`, `0x0057bb30`, `SoundManager.cpp`, `SoundManager singleton`, `audio manager global`, and `SoundManager lifetime`.
- Roots searched: central `executed-b-agent-research`; every active `tools/leaser/Agents/Agent-B001/research` through `Agent-B015/research`; legacy `tools/leaser/Agents/Older-Research`; and `archived`. No active or legacy/archive-root report matched. The central executed root produced 65 report matches; all were opened read-only and classified below.

| Opened report or group | Classification | Finding used here |
| --- | --- | --- |
| `executed-b-agent-research/B002/0001I7-soundmanager-music-selection-source-quality.md` | direct SoundManager support; executed; partly superseded | Exact constructor/destructor ranges, startup caller, DAT/Miles/config behavior, and accessor boundary remain useful. Its aggregate blank-body conclusion predates the exact lifecycle split implemented here. |
| `executed-b-agent-research/B004/0001I8-SoundManagerAudioHelperCluster-source-quality.md` | direct broad-family support; executed; current as index evidence | Confirms the broad aggregate is non-emitting, the exact vtable/singleton sites, driver/callback/path interleave, and scalar-wrapper compiler policy. Its statement that UID00028R needed no change is superseded by the newer semantic-global one-definition precedent and this direct target audit. |
| `executed-b-agent-research/B001/0001I9-SoundManagerPlaybackControls-source-quality.md` | direct class/source support; executed; current | Supplies the complete class layout/method union and exact playback-child order while leaving constructor/destructor outside that split. |
| `executed-b-agent-research/B003/0001IB-SoundManagerRedbookPlayback-source-quality.md` | direct Redbook support; executed; current | Confirms Redbook state, timers, track-order storage, config fields, and authored cleanup behavior used by the destructor draft. |
| `executed-b-agent-research/B004/0001IA-SoundManagerMusicDirectoryScan-source-quality.md` | direct scanner support; executed; current | Confirms the constructor's final wide-path/randomize/recursive scan call and `m_localMusicPaths` ownership. |
| `executed-b-agent-research/B015/0003ZH-SoundManagerStopRedbookAndCancelTrackTimerRaw-source-quality.md` | direct destructor helper support; executed; current | Confirms token `0x504e4354` as descriptive `kRedbookTrackEndedTimer` and inherited `CancelTimer` source spelling. |
| `executed-b-agent-research/B005/0001ID-SoundPathVector-source-quality.md`, `B003/0004FK-SoundPathVectorDestructor-source-quality.md`, `B007/0004FJ-SoundPathVectorGrowAndInsert-source-quality.md`, `B002/0001IE-DequeDestroyOwnedEntries-source-quality.md` | direct compiler/container support; executed | Prove standard-vector source shape, generated vector teardown, raw helper interleave, padding, and why vector destructor calls must not be handwritten in `SoundManager::~SoundManager()`. |
| `executed-b-agent-research/B010/0002H1-ApplicationCleanupResources-empty-emitter-source-quality.md`, `B008/0002H8-ApplicationShutdown-empty-emitter-source-quality.md` | direct lifetime consumer support; executed | Confirm Application checks `g_pSoundManager` and invokes virtual slot zero with scalar-delete flag `1` at `0x00464b14-0x00464b22`. |
| `executed-b-agent-research/B005/0001OS-g_pLanguageMan-source-quality.md` | semantic-global precedent; executed; current comparison | Establishes source-correct local forward declaration plus one module definition, separate future header extern, physical-storage no-duplicate policy, and compiler EH/scalar/vtable blank formals. |
| `executed-b-agent-research/B004/0001DO-OptionPane-source-quality.md`, `B005/0003UL-UserPaneParsePlayerSettingsPacket-source-quality.md`, `B003/0003MB-0003MD-MusicControlDialog-source-quality.md`, `B003/0003ME-0003MR-MusicControlDialogHelperFamily-source-quality.md`, `B002/0003TS-MapPaneHandleAnimationSoundPacket-source-quality.md` | direct consumer support; executed | Confirm config-to-SoundManager option/runtime mirroring, music/effect calls, and external cross-module linkage. |

Every other central match was opened and classified as incidental consumer, alias mention, neighboring subsystem, or report-handoff reference with no conflicting type/owner/lifetime conclusion: `B001/0000AO-0001MK-postinputpane-source-quality.md`, `B001/0001DE-LivingObjectPaneCore-source-quality.md`, `B001/0001MN-0001MP-0001MQ-spellspellinputpane-source-quality.md`, `B001/0002GJ-BaramAppOnActivate-empty-emitter-source-quality.md`, `B001/0002QY-MotionAnimationTimerTick-empty-emitter-source-quality.md`, `B002/0000O0-SpellInputPanes-empty-emitter-family-source-quality.md`, `B002/0001DJ-SoundObjectPaneCore-empty-emitter-source-quality.md`, `B002/0001EL-0001EN-flyingparcelpane-lifecycle-source-quality.md`, `B002/0001M8-ChangeSpellSlotInputPane-source-quality.md`, `B002/0002AF-g_pMainUiGraph-source-quality.md`, `B002/0002I7-0002QF-mappane-lifecycle-source-quality.md`, `B002/0003ME-MusicControlDialogUnmodeledSoundEffectApply.md`, `B002/00045D-IntegrateMacroDialogConstructor-empty-emitter-source-quality.md`, `B003/0000ZW-ChangeManRegister-source-quality.md`, `B003/0001MP-SpellSpellInputPaneKeyInput-source-quality.md`, `B003/0002PU-LogoPlayerPaneAdvanceToNextSegment-source-quality.md`, `B003/00034O-TabPaneHandleInputEvent-source-quality.md`, `B003/00036Y-MainMenuPaneCore-source-quality.md`, `B003/0003V9-UserPaneHandleKeyEvent-source-quality.md`, `B004/0001MR-WieldInputPane-source-quality.md`, `B004/00026R-TransferServerReadOnlyData-source-quality.md`, `B005/0000KC-ItemActionInputPanes-empty-emitter-family-source-quality.md`, `B005/0001LW-SpellSlotInputPaneKeyInput-source-quality.md`, `B005/00037V-MapPaneRenderViewCore-source-quality.md`, `B005/00037X-MapPaneInteractionMapChangeCore-source-quality.md`, `B005/00039Y-ScreenPaneCallbackAndFlagHelpers-source-quality.md`, `B005/0003TK-MapPaneHandleEffectMapStatePacket-source-quality.md`, `B005/0003TT-MapPaneHandleObjectStatusPacket-source-quality.md`, `B005/0003UP-UserPaneHandleMovementReplyPacket-source-quality.md`, `B005/0003XX-ObjectPaneUpdateBounds-source-quality.md`, `B005/0003Z5-LivingObjectPaneEffectMovementAndActionHelpers-source-quality.md`, `B005/00047D-PartySearchEditPaneConstructor-source-quality.md`, `B006/0001M6-ChangeItemSlotInputPane-source-quality.md`, `B007/0000LN-MusicControlDialog-empty-emitter-family-source-quality.md`, `B007/0001M9-ChangeSpellSlotInputPaneKeyInput-source-quality.md`, `B007/0002R6-FlyingParcelPaneStartAnimation-source-quality.md`, `B007/0003MO-MusicControlDialogPreviousTrackHelper-source-quality.md`, `B008/0000O4-StartupLogoPanes-empty-emitter-family-source-quality.md`, `B008/0002GK-BaramAppOnDeactivate-empty-emitter-source-quality.md`, `B009/0001JC-TerminalPaneStreamParser-source-quality.md`, `B009/00039S-ScreenPanePresentationModeFlagSetters-source-quality.md`, `B011/0000L0-MainMenuPane-empty-emitter-family-source-quality.md`, `B011/00019K-InitializeMainUiGraph-source-quality.md`, `B011/0001CP-MusicControlDialog-source-quality.md`, `B011/0003MN-MusicControlDialogNextTrackHelper-source-quality.md`, `B012/000058-FlyingParcelPane-class-source-quality.md`, `B012/00022Q-IconsPaneActionDispatchRawBody-source-quality.md`, and `B015/0001M9-ChangeSpellSlotInputPaneKeyInput-source-quality.md`.

Evidence-based search conclusion: no prior direct UID00028R / `g_pSoundManager` target-specific report exists. Earlier SoundManager reports are support evidence and contain the exact assumptions this direct audit now resolves; they are not substitutes for this report.

## Target

- Target UID: `00028R`.
- Target path: `by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md`.
- Source queue/report history: pre-callback tracker placed the target under `by-memory` -> `Not-Covered Files - Reconstructable` at `86/90`. The final read-only checkpoint at external command 15521 recorded UID00028R at `92/94`, average `93.0`, false; command 15501 remains B005's callback generation epoch.
- Current supervisor classification: accepted implementation callback completed for mixed physical-storage/semantic-global emission.
- Current scores and parent state: `92/94`, canonical owner `0004UF`, false/non-emitting, blank emitter/position/formal, `Nested:0`.

## Current Target State

- Current metadata routes physical `.data` UID00028R through semantic global UID0004UF, which emits once through [UID:0000NV][SoundManager](by-file/SoundManager.md). Generated output has the definition and zero UID00028R marker/name occurrences.
- Target/global/support prose now preserves zero storage, all 117 xrefs, five lifetime writes/clears, 112 readers, direct Singleton/EH/scalar lowering, exact source ownership, and one-definition policy at report-level detail.
- [UID:0000DG][SoundManager](by-class/SoundManager.md) remains complete/source-ready at `92/94`; its formal now declares `public Singleton<SoundManager>, public TimerHandler` while preserving the prior class block byte-for-byte otherwise.
- Exact lifecycle pages exist as UID0004UG-UID0004UK. Constructor/destructor emit positions `20/30`; EH/scalar/vtable are false/non-emitting blank-formal compiler evidence.
- UID0001I8 remains a non-emitting broad index. UID0001I7 and UID0001IC intentionally remain broad blank-formal emitters for other unsplit source families; command-15501 preserves those unrelated aggregate markers.
- Artifact/lifecycle status: B005 callback obligations are complete and all leases are released. Manual coverage and report lifecycle are supervisor-owned external state; this artifact records that B005 did not perform either action.

## Executive Recommendation

- Applied and verified: semantic by-global UID0004UF emits exactly one `SoundManager *g_pSoundManager = 0;` definition at file position `0` with a local `class SoundManager;` forward declaration.
- Applied and verified: UID00028R is false/non-emitting exact backing storage; no second definition, covered-by source comment, raw address declaration, or file-static alias is emitted.
- Applied and verified: the complete class declaration has direct `Singleton<SoundManager>` inheritance before TimerHandler, explaining compiler-inlined publication/reverse teardown without explicit source assignment/clear.
- Applied and verified: exact source constructor/destructor UID0004UG/UID0004UH emit at positions `20/30` before playback positions `100-290`.
- Applied and verified: exact EH/scalar/vtable UID0004UI/UID0004UJ/UID0004UK are false/non-emitting blank-formal compiler pages with exhaustive evidence.
- All broad SoundManager aggregates, playback/Redbook/scanner children, Application consumers, and unrelated content were preserved at same-or-greater detail.

## Supervisor Active Recheck

- The supervisor accepted exact pre-callback SHA `3500FAB3CCAAE8C4273EBEAB924CE9722EF21825215709FE9E06C658C7EE9D90` and authorized C01-C40/Destinations 1-8.
- The callback registered UID0004UF-UID0004UK serially, applied the split and one-definition route, validated every changed ordinary page, and completed waited generation under command `000000015501`.
- Every source-bearing item has exact applied C++; every non-source item has an exact applied blank managed block/no-code proof. No name/type/linkage/source-placement/lifetime or callback blocker remains.

## Inference Research Guidance Check

- IDA facts are addresses, bytes, xrefs, function bounds, decompilation, RTTI structures, PMDs, vtable slots, callers, and section boundaries. Documentation evidence is the current by-* union, executed reports, generated output, and manual coverage. Inference is limited to source-era names, class/header organization, and null-literal style.
- Existing raw names were treated as hypotheses. `dword_67A7D0` is rejected as source spelling; `g_pSoundManager` is retained because current project docs consistently use it, all consumers treat it as a `SoundManager *`, and no competing RTTI/global identity exists.
- Existing explicit lifetime descriptions were not trusted as handwritten source. Direct RTTI/PMD and EH/scalar routes prove compiler-lowered Singleton behavior.
- Wave2/Wave3 and `simroot_v2` mentions appeared only in historical support docs. They were ignored as current authority and do not override live MCP or the current documentation union.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence and resolution | Status / impact |
| --- | --- | --- |
| Raw name versus source name | IDA retains `dword_67A7D0`; project-wide consumers and class/file docs consistently use `g_pSoundManager`; RTTI supplies exact `SoundManager`. | Use `SoundManager *g_pSoundManager`; reject raw/void aliases. |
| Physical storage versus semantic global | Historical baseline had an exact backing page but no semantic global, and generated output had only an empty physical marker. Newer LanguageMan/MessageShowPane precedents emit once from semantic by-global. | Implemented semantic by-global UID0004UF; UID00028R is false/non-emitting. |
| External versus internal linkage | 112 non-lifetime reads span Application, OptionPane, MusicControlDialog, MapPane, UserPane, Bink/video, status panes, hotkeys, and other modules. | External linkage is required; `static`/anonymous-namespace storage is rejected. |
| Pointer type | Constructor stores the complete object pointer; readers invoke SoundManager methods and virtual destruction; no offset-adjusted alias is stored. | Exact type is `SoundManager *`. |
| Direct Singleton inheritance | SoundManager RTTI CHD has three bases; BCA lists SoundManager, `Singleton<SoundManager>`, TimerHandler. Singleton BCD PMD is `mdisp=4,pdisp=-1,vdisp=0`; TimerHandler PMD is `0,-1,0`. | Source declaration is `SoundManager : public Singleton<SoundManager>, public TimerHandler`. |
| EBO/polymorphic base order | Source BCA order places Singleton before TimerHandler, while polymorphic TimerHandler supplies the primary vptr at offset zero and empty Singleton appears at `+4`. Constructor computes `this+4`, tests, then stores adjusted complete `this`. | This is old-MSVC empty-base optimization/compiler lowering, not a handwritten `this+4` global assignment. |
| Constructor source body | Exact function `0x00579a30-0x00579ca5`, one startup caller, `0x10ac` allocation, TimerHandler/base setup, config copies, Miles reinit, DAT sample cache, scanner call. | Implemented source-bearing position-20 child UID0004UG; explicit Singleton publication/vptr/vector construction omitted. |
| Destructor source body | Exact function `0x00579cb0-0x00579dbf`; authored sample/stream/driver/Miles/Redbook cleanup followed by compiler vector/base/Singleton teardown. | Implemented source-bearing position-30 child UID0004UH; vector/base/global clear lowering omitted. |
| EH helper | Exact 11-byte `g_pSoundManager=0; ret`, sole code xref from constructor EH funclet at `0x0060831c`, where the object is adjusted by `+4`. | Compiler constructor-unwind cleanup; false/non-emitting blank C++. |
| Scalar deleting destructor | Exact `0x129` wrapper, sole vtable data reference, duplicates destructor/vector/base/Singleton cleanup, tests delete flag bit 0, and frees object. | Compiler scalar wrapper; false/non-emitting blank C++. |
| Vtable | COL at `0x0062ce78`, scalar wrapper slot at `0x0062ce7c`, `OnTimer` at `0x0062ce80`, `%03d.wav` starts at `0x0062ce84`; exactly three vptr stores target `0x0062ce7c`. | Split `[0x0062ce78,0x0062ce84)` as compiler-generated class data; blank C++. |
| Constructor option order | Binary copies Config music enabled to runtime and option bytes, then copies the preexisting SFX runtime byte to the SFX option byte before loading Config SFX enabled. | Preserve the observed legacy order even though the pre-load SFX mirror is surprising; do not silently "fix" it. |
| Constructor resources | IDs `0..999` format `%03d.wav`, test `HasDATEntry`, construct/open `DATFile`, cache `GetDataPointer`, close/destroy; misses store null. | Source-ready loop with accepted project APIs; no raw helper labels. |
| Destructor resources | Releases eight sample handles only when driver exists, closes stream/driver, releases timers/shuts Miles, stops/closes Redbook, cancels token twice around state reset. | Source-ready authored cleanup; preserve no exception/rollback behavior. |
| Broad aggregates | UID0001I7 also contains five other unsplit source methods; UID0001IC contains driver/callback/path work; UID0001I8 is an index. | Keep aggregate metadata/scores unchanged, add exact split links and source/compiler clarification only. |
| Header declaration | Cross-module consumers need `extern SoundManager *g_pSoundManager`, but the project does not model the shared SoundManager header as a separate formal emitter. | The header extern remains separate proper header/class placement, not in Destination 2 or duplicate source output. |
| Original lexical style | Current project formals use both `0` and `NULL`; the accepted LanguageMan module-definition precedent uses `0`. | Use `0`; lexical uncertainty caps confidence below 95. |

Rejected alternatives:

- Keep UID00028R as the source emitter: rejected because it creates an empty physical marker and leaves no semantic declaration owner.
- Emit from both physical and semantic pages: rejected as duplicate storage/ODR-invalid source.
- File-static `g_pSoundManager`: rejected by cross-module consumers.
- `void *`, raw integer, or offset-adjusted Singleton pointer: rejected by complete-object stores and typed method use.
- Handwrite constructor publication, destructor clear, EH clear helper, scalar wrapper, vtable array, vptr stores, vector destructors, TimerHandler destruction, or allocator/free flags: rejected as compiler/base/member lowering.
- Preserve TimerHandler-only inheritance: rejected by exact RTTI type descriptor, BCA, and PMD.
- Fold predecessor/successor globals into one table: rejected by independent xref/lifetime families and clean four-byte boundaries.
- Raise broad aggregates or claim all SoundManager source debt is closed: rejected; this direct report resolves the global and exact lifecycle items only, while unrelated aggregate methods keep their current independent status.

## Evidence Standards Used

- Highest-weight evidence: live IDA MCP `get_bytes`, `get_int`, `xref_query`, `lookup_funcs`, `analyze_function`, `decompile`, and `entity_query` against active database `9b0396a3`.
- Corroboration: current by-memory/by-class/by-file/by-global docs, current generated SoundManager source, current tracker, manual coverage, and executed direct support reports.
- Source-shape evidence: exact RTTI hierarchy/PMD, constructor/destructor order, EH funclet route, scalar wrapper flags, vtable slots, object allocation size, field offsets, resource literals, and accepted project API names.
- Negative evidence: no second storage/alias/type, no direct caller to ordinary destructor, no source caller to EH/scalar artifacts, no complete vtable source body, no merged neighbor range, no file-local-only consumer set, and no prior direct target report.
- Confidence remains below 95 because original private symbol spelling and exact shared-header organization are not recoverable from the binary; those lexical limits do not block compile-legal source.

## Evidence Checked

- Fresh MCP initialization produced transport session `46273d72-aeb0-4670-a465-98f241175315`; `idb_list` returned one active/adopted NexusTK database `9b0396a3`, worker PID `15732`, not analyzing. `server_health(database='9b0396a3')` returned `status:ok`, auto-analysis ready, Hex-Rays ready, and strings cache ready (`2067`).
- `get_bytes` over `0x0067a7c8-0x0067a7e8` returned 32 zero bytes. `get_int` returned zero u32 values for predecessor `0x0067a7cc`, target `0x0067a7d0`, and successor `0x0067a7d4`.
- `xref_query` returned target total `117`, predecessor total `145`, successor total `9`; target first/last refs are `0x00450e27`/`0x005c0116`.
- `lookup_funcs`/`analyze_function` confirmed constructor `0x00579a30-0x00579ca5` (`0x275`), destructor `0x00579cb0-0x00579dbf` (`0x10f`), EH clear `0x0057b9a0-0x0057b9ab` (`0xb`), scalar wrapper `0x0057bb30-0x0057bc59` (`0x129`), reader helper `0x0057b7f0-0x0057b853`, and Application cleanup `0x00464a60-0x00464cc1`.
- Raw bytes at startup `0x00464670` begin with allocation size `0x10ac`; the following constructor call resolves to `0x00579a30`.
- RTTI names and bytes were read at `0x00650490-0x0065051c`, type descriptors `0x00679270/0x0067928c`, TimerHandler BCD `0x00640640`, and vtable `0x0062ce78-0x0062ce84`.
- Read current ordinary docs, 65 matching executed reports, zero active report matches, zero Older-Research/archive matches, generated SoundManager/tracker, and all four relevant manual coverage reports.
- Two initial MCP calls used obsolete singular payload keys and returned schema errors requiring `regions`/`addrs`; they were corrected immediately. These were client payload errors, not availability failures, and no evidence conclusion uses them.
- No broad whole-image text search, IDA mutation, validator, lease, lifecycle command, or fallback-only evidence was used.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00028R is exactly four zero-initialized bytes at `[0x0067a7d0,0x0067a7d4)`. | very strong | target command `15494`; exact bytes/range retained | UID00028R | incorporate | applied |
| C02 | Predecessor `g_pScreenPane` and successor `g_pSimpleHelpPane2` are independent four-byte zero slots. | very strong | target command `15494`; adjacency retained without range growth | UID00028R | incorporate | applied |
| C03 | UID00028R has exactly 117 direct data xrefs. | very strong | target `15494`, global `15483` | UID00028R/UID0004UF | incorporate | applied |
| C04 | Five refs are lifetime writes/clears at `0x579a67`, `0x579a6e`, `0x579da3`, `0x57b9a0`, `0x57bc29`. | very strong | target/global/lifecycle commands `15494/15483/15484-15487` | target/global/lifecycle pages | incorporate | applied |
| C05 | The remaining 112 refs are reads across multiple source modules. | very strong | target/global/file commands `15494/15483/15496` | target/global/file | incorporate | applied |
| C06 | Canonical source type/name is `SoundManager *g_pSoundManager`. | very strong | global command `15483`; generated command `15501` has one exact definition | UID0004UF | incorporate | applied |
| C07 | Cross-module reads require external linkage; file-static storage is invalid. | very strong | UID0004UF command `15483` records external one-definition route | semantic global negative evidence | reject-invalid | excluded-with-reason |
| C08 | Semantic by-global owns the sole module definition; physical UID00028R is evidence-only storage. | very strong | commands `15483/15494`; generated `15501` | UID0004UF/UID00028R | incorporate | applied |
| C09 | Semantic definition must emit at SoundManager file position `0`. | strong | global/file commands `15483/15496`; generated line 10 under `15501` | UID0004UF/UID0000NV | incorporate | applied |
| C10 | Header `extern` is separate proper header/class placement and must not be duplicated in Destination 2. | strong | global/class/file commands `15483/15495/15496`; generated definition count one | UID0004UF/UID0000DG/UID0000NV | incorporate | applied |
| C11 | SoundManager RTTI proves direct `Singleton<SoundManager>` and `TimerHandler` bases. | very strong | class command `15495`; generated class line 28 under `15501` | UID0000DG | incorporate | applied |
| C12 | Source base order is Singleton then TimerHandler; PMDs are `+4` and `0` under old-MSVC EBO. | very strong | class/constructor commands `15495/15484` | UID0000DG/UID0004UG | incorporate | applied |
| C13 | `0x00579a30-0x00579ca5` is the source-authored constructor. | very strong | registered/validated as UID0004UG command `15484`; generated once under `15501` | UID0004UG | incorporate | applied |
| C14 | Startup allocates exact object size `0x10ac` and calls the constructor once. | very strong | constructor/class commands `15484/15495` | UID0004UG/UID0000DG | incorporate | applied |
| C15 | Constructor publication/fallback clear is inlined Singleton base construction, not handwritten assignment. | very strong | commands `15484/15495`; generated `15501` has no explicit Singleton write/clear | constructor/class compiler exclusion | reject-stale | excluded-with-reason |
| C16 | Constructor initializes exact scalar/vector state before config/resource policy. | very strong | UID0004UG command `15484`, Destination 4 parity | UID0004UG | incorporate | applied |
| C17 | Constructor preserves legacy music/SFX option/runtime assignment order. | very strong | UID0004UG command `15484`, generated source readback `15501` | UID0004UG/UID0000DG | incorporate | applied |
| C18 | Constructor calls `ReinitializeAudioDriver` and conditionally reapplies Config volume/output preference. | very strong | constructor/file commands `15484/15496` | UID0004UG/UID0000NV | incorporate | applied |
| C19 | Constructor caches all 1000 `%03d.wav` DAT payloads with null for missing entries. | very strong | constructor/class/file commands `15484/15495/15496` | UID0004UG/UID0000DG/UID0000NV | incorporate | applied |
| C20 | Constructor clears zone playlist state and calls `ScanMusicDirectory` with Config folder/randomize and recursive true. | very strong | UID0004UG command `15484` | UID0004UG | incorporate | applied |
| C21 | `0x00579cb0-0x00579dbf` is the ordinary source-authored destructor. | very strong | registered/validated as UID0004UH command `15485`; generated once under `15501` | UID0004UH | incorporate | applied |
| C22 | Destructor releases eight samples, stream, driver, Miles timers/runtime, and Redbook state exactly. | very strong | destructor/class/file commands `15485/15495/15496` | UID0004UH/UID0000DG/UID0000NV | incorporate | applied |
| C23 | Destructor cancels Redbook timer token `0x504e4354` twice around close/reset as observed. | very strong | UID0004UH command `15485`, Destination 5 parity | UID0004UH | incorporate | applied |
| C24 | Vector destructors, TimerHandler dtor, Singleton clear, and vptr stores are implicit compiler/member/base lowering. | very strong | commands `15485/15495`; generated `15501` excludes handwritten mechanics | destructor/class compiler exclusion | reject-stale | excluded-with-reason |
| C25 | Application shutdown checks target at `0x464b14` and virtually deletes it with flag `1` at `0x464b22`. | very strong | target/global/file commands `15494/15483/15496` | UID00028R/UID0004UF/UID0000NV | incorporate | applied |
| C26 | `0x0057b9a0-0x0057b9ab` is constructor-unwind Singleton cleanup only. | very strong | registered/validated as UID0004UI command `15486` | UID0004UI | incorporate | applied |
| C27 | The EH page is false/non-emitting with blank formal and no source helper. | very strong | UID0004UI command `15486`; zero generated UID0004UI marker under `15501` | UID0004UI no-code disposition | reject-invalid | excluded-with-reason |
| C28 | `0x0057bb30-0x0057bc59` is the scalar deleting destructor generated from the virtual destructor. | very strong | registered/validated as UID0004UJ command `15487` | UID0004UJ | incorporate | applied |
| C29 | The scalar page is false/non-emitting with blank formal; no ABI/free mechanics are handwritten. | very strong | UID0004UJ command `15487`; zero marker/ABI mechanics under `15501` | UID0004UJ no-code disposition | reject-invalid | excluded-with-reason |
| C30 | `[0x0062ce78,0x0062ce84)` is exact COL/vtable data: scalar slot then `OnTimer`. | very strong | registered/validated as UID0004UK command `15490`; support `15500` | UID0004UK/UID00026I | incorporate | applied |
| C31 | The vtable page is false/non-emitting with blank formal; compiler regenerates it from declarations. | very strong | UID0004UK command `15490`; zero generated UID0004UK marker under `15501` | UID0004UK no-code disposition | reject-invalid | excluded-with-reason |
| C32 | UID0001I7 remains `88/91` broad blank-formal emitter for five other unsplit methods, but links exact ctor/dtor children. | strong | scoped command `15497`; generated marker preserved under `15501` | UID0001I7 | incorporate | applied |
| C33 | UID0001I8 remains `88/91`, false/non-emitting broad index and records exact lifecycle splits. | strong | scoped command `15498` | UID0001I8 | incorporate | applied |
| C34 | UID0001IC remains `87/90` broad blank-formal emitter and records exact EH/scalar split/no-code policy. | strong | scoped command `15499`; generated marker preserved under `15501` | UID0001IC | incorporate | applied |
| C35 | UID00026I remains `88/91`, false/non-emitting mixed rdata index and links exact vtable child. | strong | scoped command `15500` | UID00026I | incorporate | applied |
| C36 | Target/global/ctor/dtor score `92/94`; EH/vtable `90/94`; scalar `91/94`; all new by-memory pages use address-sort-relative `Nested:0`; support scores and neighboring nesting remain unchanged. | strong | registration/scoped commands `15483-15500`; time-bounded tracker checkpoint `15521` preserves all rows | all metadata destinations | incorporate | applied |
| C37 | Raw `dword_67A7D0`, duplicate definition, file-static, void pointer, explicit Singleton writes, and handwritten ABI artifacts are rejected. | very strong | all ordinary validators plus generated negative readback `15501` | all destination negative evidence | reject-invalid | excluded-with-reason |
| C38 | Manual coverage requires exact target/support replacements plus new global/lifecycle/vtable rows. | very strong | current read-only four-file comparison; exact 13-action handoff retained | supervisor-owned manual handoff | incorporate | applied |
| C39 | Generated acceptance is one global, one constructor, one destructor, corrected class inheritance, no UID00028R/EH/scalar/vtable markers or duplicates. | strong | final waited command `15501`, SoundManager.cpp SHA `AC793B...3684` | generated verification | incorporate | applied |
| C40 | No third-party import, IDA rename/type mutation, range merge, padding creation, or alternate source file applies. | very strong | no such action occurred; exact ranges and source route preserved | excluded callback operations | not-applicable | excluded-with-reason |

## Positive Evidence Summary

- Exact bytes, integer reads, and independent adjacent xref families prove one four-byte null pointer slot.
- Exact 117-xref inventory gives five lifecycle manifestations and 112 readers; no separate write route or competing storage exists.
- RTTI names exact `SoundManager` and `Singleton<SoundManager>`; CHD/BCA/PMDs establish the direct-base source relationship and old-MSVC layout.
- Constructor/deconstructor decompilation, startup allocation, vtable, Config fields, DAT APIs, Miles imports, vector members, and scanner call jointly support destination-ready human source.
- EH and scalar artifacts each have compiler-specific reachability: one constructor funclet jump and one vtable data reference, respectively.
- Existing source tree already routes all SoundManager source through UID0000NV; a position-zero semantic global definition fits that route without creating a second file or storage object.

## IDA MCP Facts

- Database: active `9b0396a3`; health `ok`; analysis/Hex-Rays/strings ready.
- Data: target bytes `00 00 00 00`; surrounding 32-byte window all zero; predecessor/target/successor u32 values zero.
- Xrefs: predecessor `145`, target `117`, successor `9`; target first `0x450e27`, last `0x5c0116`.
- Lifetime sites: ctor publish `0x579a67`, ctor guard clear `0x579a6e`, ordinary dtor clear `0x579da3`, EH clear `0x57b9a0`, scalar clear `0x57bc29`.
- Representative readers: `0x450e27`, `0x464b14`, `0x49e164`, `0x4f8af3`, `0x504678`, `0x528ecf`, `0x53da1c`, `0x53de20`, `0x57b827`, `0x58b3e3`, `0x5991ee`, `0x59e12d`, `0x5aa6a6`, `0x5c0116`.
- Constructor: size `0x275`, one startup call, allocation size `0x10ac`, vtable store at `0x579a86`, `%03d.wav` literal at `0x62ce84`.
- Destructor: size `0x10f`, no direct caller, authored cleanup followed by vector/TimerHandler/Singleton lowering.
- EH: size `0xb`, sole code xref `0x60831c` in constructor unwind metadata.
- Scalar: size `0x129`, sole ref vtable slot `0x62ce7c`, flag-bit-1 conditional free.
- Vtable: COL pointer at `0x62ce78`, scalar `0x57bb30`, `OnTimer` `0x57a800`, then audio literal at `0x62ce84`; three vptr xrefs from ctor/dtor/scalar.
- RTTI: SoundManager COL `0x650490`, CHD `0x6504a4`, BCA `0x6504b4`; type descriptors `0x679270` and `0x67928c`; Singleton BCD `0x6504e0`; TimerHandler BCD `0x640640`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005797b0-0x0057a25c` | UID0001I7 | broad music/lifecycle aggregate | true | UID0000DG | `88/91` | retained; exact UID0004UG/UID0004UH links applied |
| `0x00579a30-0x00579ca5` | UID0004UG | source constructor | true | UID0000DG | `92/94` | registered; position 20; Destination 4 applied |
| `0x00579cb0-0x00579dbf` | UID0004UH | source destructor | true | UID0000DG | `92/94` | registered; position 30; Destination 5 applied |
| `0x005797b0-0x0057bf6e` | UID0001I8 | broad audio index | false | UID0000NV | `88/91` | retained; support synchronized |
| `0x0057b490-0x0057bf6e` | UID0001IC | driver/destructor/path aggregate | true | UID0000NV | `87/90` | retained; support synchronized |
| `0x0057b9a0-0x0057b9ab` | UID0004UI | constructor unwind clear | false | NONE | `90/94` | registered; Destination 6 blank |
| `0x0057bb30-0x0057bc59` | UID0004UJ | scalar deleting destructor | false | NONE | `91/94` | registered; Destination 7 blank |
| `0x0062ce50-0x0062cfd8` | UID00026I | mixed rdata index | false | NONE | `88/91` | retained; support synchronized |
| `0x0062ce78-0x0062ce84` | UID0004UK | COL/vtable data | false | UID0000DG | `90/94` | registered; Destination 8 blank |
| `0x0067a7d0-0x0067a7d4` | UID00028R | physical backing storage | false | UID0004UF | `92/94` | Destination 1 blank applied |
| semantic global | UID0004UF / `by-global/g_pSoundManager.md` | sole pointer definition | true | UID0000NV | `92/94` | registered at position 0; Destination 2 applied |
| class declaration | UID0000DG | class shell/layout | true | UID0000NV | `92/94` | complete union preserved; Destination 3 applied |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00464697` | Application startup -> constructor | sole source construction route after `0x10ac` allocation |
| `0x00579a67/0x00579a6e` | ctor -> global | Singleton publish/fallback clear |
| `0x00579da3` | ordinary dtor -> global | reverse Singleton clear |
| `0x0060831c` | ctor EH funclet -> `0x0057b9a0` | compiler unwind clear after `this+4` adjustment |
| `0x0062ce7c` | vtable -> `0x0057bb30` | scalar wrapper only route |
| `0x00464b14-0x00464b22` | Application cleanup -> global/vslot0 flag1 | null-check and virtual delete |
| `0x0057b827` | singleton notification/helper reader | read-only helper; not a sixth lifetime write |
| `0x0053da1c/0x0053da47` | OptionPane readers | mirror current audio state |
| `0x0053de20-0x0053de9e` | OptionPane apply family | toggle volume/enable behavior |
| `0x00528ecf` and music-control family | UI music consumers | external linkage and method use |
| `0x005c0116` | Video/Bink consumer | final xref and digital-driver use family |

## Documentation Evidence And IDA Status

- The callback-updated docs identify the address, canonical name, 117 refs, lifetime sites, DAT/Miles ownership, broad consumers, semantic-global source ownership, direct Singleton inheritance, exact lifecycle splits, and source/compiler separation.
- The complete SoundManager class union was preserved while its inheritance list was corrected. Its `0x10ac` layout remains valid because Singleton is empty and represented by EBO.
- UID0001I8 remains correctly non-emitting; UID0001I7 and UID0001IC retain legitimate unrelated aggregate markers. Exact lifecycle children were added without claiming unrelated aggregate completion.
- Historical pre-callback command `000000015475` had no global/constructor/destructor definition, TimerHandler-only inheritance, and a UID00028R empty marker. Current waited command `000000015501` emits one semantic global, one constructor, one ordinary destructor, and direct Singleton-then-TimerHandler inheritance; it has zero UID00028R/UID0004UI/UID0004UJ/UID0004UK markers and preserves the independent UID0001I7/UID0001IC markers.
- Current manual rows remain stale for target/source disposition and several support scores/descriptions because B005 kept them read-only; exact no-loss supervisor-owned text is supplied below.

## Ranked Ownership Analysis

### 1. Semantic by-global g_pSoundManager under SoundManager.cpp

- Evidence for: exact external pointer identity, 112 cross-module reads, dedicated source file, complete class, semantic-global precedents, position-zero source order, one-definition policy.
- Evidence against: shared-header external declaration is not currently a separate formal destination.
- Decision: best and implementation-ready. A local class forward declaration makes the module definition compile-legal; header placement is separate and does not justify duplicate source output.

### 2. Physical UID00028R emitted directly through UID0000NV

- Evidence for: exact storage is in `.data`, and the file is the semantic source owner.
- Evidence against: produces only an empty marker, conflates storage evidence with declaration ownership, and leaves no reusable semantic global page.
- Decision: rejected/superseded. Keep UID00028R as non-emitting backing evidence.

### 3. Class-owned static or Singleton template static member

- Evidence for: direct `Singleton<SoundManager>` inheritance and inlined publication/clear.
- Evidence against: project source vocabulary and all current consumers use external `g_pSoundManager`; no qualified static member symbol or separate template static storage is evidenced.
- Decision: reject as source spelling. The base drives lifetime behavior around the external pointer definition.

### Applied new file/grouping

- Applied owner/name/path: `by-global/g_pSoundManager.md` (UID0004UF), emitted by UID0000NV into existing `NexusTK/audio/SoundManager.cpp`.
- Contents: one forward declaration and one initialized pointer definition, plus evidence/prose linking UID00028R and lifetime children.
- Candidate related items that belong: exact storage, constructor/destructor/EH/scalar/vtable links.
- Candidate related items rejected: a second source file, static template-member storage, duplicate physical definition, unrelated SoundStatusPane or Config globals.
- Source grouping: narrow semantic global in the existing SoundManager module, not a new broad file.

## Source Placement

- Recommended source placement: semantic definition at position `0` in `NexusTK/audio/SoundManager.cpp`; class at position `10`; constructor at `20`; destructor at `30`; existing playback children remain `100-290`, scanner `300`, Redbook `400-470`.
- Header placement: the cross-module `extern SoundManager *g_pSoundManager;` belongs in a proper shared SoundManager declaration/header route. It is explicitly not part of Destination 2 because combining extern and definition in the module block is redundant and repeats the source-placement defect corrected for g_pLanguageMan.
- Rejected placements: Application.cpp (consumer/allocator only), Config.cpp (settings provider only), DATFileMgr.cpp (resource dependency only), MusicControlDialog.cpp/MapPane.cpp/UserPane.cpp (consumers only), anonymous namespace/file-static storage (linkage mismatch), and a new standalone global source file (unnecessary split).
- Remaining placement uncertainty: exact original header filename is unknown; that is a lexical/build-organization cap only and does not block the module definition or target disposition.

## Range / Split / Padding / Reclassification Analysis

- UID00028R range remains exactly `[0x0067a7d0,0x0067a7d4)`. Do not merge with predecessor or successor and do not create padding.
- Created exact constructor `[0x00579a30,0x00579ca5)`; the next function begins at `0x00579cb0` after external alignment bytes.
- Created exact destructor `[0x00579cb0,0x00579dbf)`; successor accessor begins at `0x00579dc0` after one alignment byte.
- Created exact EH clear `[0x0057b9a0,0x0057b9ab)`; it is one complete 11-byte function and does not absorb nearby raw/helper code.
- Created exact scalar wrapper `[0x0057bb30,0x0057bc59)`; later helper code begins at `0x0057bc60` after alignment.
- Created exact vtable `[0x0062ce78,0x0062ce84)`: four-byte COL pointer plus two function slots. `%03d.wav` at `0x0062ce84` is excluded.
- `tools/validator_background.py` sorts memory rows by `(start, -end, normalized path)`, and `Nested` is a relative delta rather than a child count. The generated coverage establishes cumulative baselines of 560 spaces for the executable SoundManager region, 736 for the read-only-data region, and 752 for the singleton-global region. The applied insertion sequence is: UID0001I8 `0`/560, UID0001I7 `0`/560, UID0004UG `0`/560, UID0004UH `0`/560, following UID0001I9 `0`/560; UID0001IC and existing vector/deque rows `0`/560, UID0004UI `0`/560, UID0004UJ `0`/560, following UID0004FM `0`/560; UID00026I `0`/736, UID0004UK `0`/736, UID00026J `0`/736; UID0001OX `0`/752, UID00028R `0`/752, UID0001OY `0`/752. No registered page opens a semantic indentation level, so every new exact page uses `Nested:0` and no existing following row needs a compensating negative delta.
- The broad overlaps are evidence/index containment, not validator nesting declarations. UID0001I8, UID0001I7, UID0001IC, and UID00026I remain independent broad maps, while the exact pages route source or no-code ownership directly through the class/file metadata stated above.
- Physical UID00028R reclassifies from reconstructable emitter to false/non-emitting storage. Semantic source representation moves to new by-global without changing binary range.

## Negative Evidence Summary

- No second data slot, named alias object, template static-member symbol, or alternate SoundManager pointer storage was found.
- No source caller reaches the ordinary destructor directly; virtual/scalar use is expected for a virtual destructor.
- The EH clear has exactly one constructor-unwind code xref and no ordinary caller/callee behavior.
- The scalar wrapper has exactly one vtable data ref and no source call route.
- The vtable has no handwritten array consumer; ctor/dtor/scalar vptr stores are compiler manifestations.
- The 112 readers prove linkage and semantics but do not transfer ownership to Application, UI, MapPane, UserPane, Config, DATFile, Miles, Bink, or TimerMgr.
- Physical adjacency to ScreenPane/SimpleHelpPane2 does not imply one owner or table; their xref/lifetime sets are independent.
- The surprising SFX option-copy order is not "corrected" from intuition; exact binary order wins.
- No third-party static source import, IDA mutation, raw-offset accessor, reserved-layout placeholder, or compiler-shaped handwritten source is justified.

## IDA Rename / Type / Comment Recommendations

- Source-facing global name/type: `SoundManager *g_pSoundManager`.
- Source-facing class relationship: `SoundManager : public Singleton<SoundManager>, public TimerHandler`.
- Source-facing exact pages: `SoundManagerConstructor`, `SoundManagerDestructor`, descriptive `SoundManagerConstructorUnwindSingletonClear`, descriptive `SoundManagerScalarDeletingDestructor`, and `SoundManagerVtableData`.
- Preserve existing accepted field/API names from current class/support docs: `m_digitalDriver`, `m_stream`, `m_redbookHandle`, `m_sampleSlots`, `m_samplePayloads`, `m_localMusicPaths`, `m_zoneMusicTracks`, `ReinitializeAudioDriver`, `ScanMusicDirectory`, `HasDATEntry`, and `DATFile::GetDataPointer`.
- Treat `dword_67A7D0`, `sub_579A30`, `sub_579CB0`, `sub_57B9A0`, `sub_57BB30`, Boost-polluted destructor labels, and FourCC-looking timer spellings as rejected raw/decompiler vocabulary.
- IDA edits are not requested or authorized. These names are documentation/source recommendations only.

## First-Draft C++ Recommendation

- Eligible source-bearing destinations: semantic global, complete class declaration, constructor, and ordinary destructor.
- Non-source destinations: physical storage, constructor-unwind clear, scalar deleting destructor, and vtable remain exact blank managed blocks.
- Exactly eight accepted/applied destination blocks follow. No C++ or declaration/body edit was made outside these managed blocks.

Destination 1: `by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 2: new `by-global/g_pSoundManager.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SoundManager;

SoundManager *g_pSoundManager = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 3: `by-class/SoundManager.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace mystr {
template <typename CharT> struct mychar_traits;
template <typename CharT, typename Traits> class StringBase;
}

typedef mystr::StringBase<char, mystr::mychar_traits<char> > SoundPathString;
class SimpleUString;
class BaramApp;

struct SoundSampleSlot
{
    HSAMPLE handle;
    int playVolumeScale;
};

class SoundManager : public Singleton<SoundManager>, public TimerHandler
{
public:
    SoundManager();
    virtual ~SoundManager();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

    void LoadTrackListFromFile(const SimpleUString &playlistName);
    void StopStreamAndResetZone(int fadeOutMilliseconds);
    HDIGDRIVER GetDigitalDriver() const;
    void PlayTrackByIndex(int trackIndex, int volumeScale, int loopCount);
    void PlayMusicByZone(int zoneId,
                         int fallbackTrackIndex,
                         int volumeScale,
                         int loopCount);

    void StopStream(int fadeOutMilliseconds);
    int GetStreamVolume() const;
    void SetStreamVolume(unsigned int volume);
    bool IsPlaybackEnabled() const;
    void MuteMusic();
    void UnmuteMusic();
    void SetStreamPaused(bool paused);
    void PlayNextTrack();
    void PlayNextPlaylistTrack();
    void PlaySample(unsigned int sampleId, int playVolumeScale);
    void PlayEffect(unsigned int sampleId, int playVolumeScale)
    {
        PlaySample(sampleId, playVolumeScale);
    }
    int GetSampleVolume() const;
    void SetSampleVolume(unsigned int volume);
    bool IsSoundEffectsEnabled() const;
    void EnableSoundEffects();
    void DisableSoundEffects();
    void SuspendSoundEffectsForApplicationDeactivate();
    void RestoreSoundEffectsAfterAppFocus();
    LPDIRECTSOUND GetDirectSound();

    void ScanMusicDirectory(
        const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > &directoryPath,
        bool randomize,
        bool recursive);

    void OpenRedbookDrive(uint16_t driveLetter);
    void CloseRedbookDevice();
    void PlayRedbookTrack(uint32_t trackNumber);
    bool AdvanceRedbookTrack();
    bool RewindRedbookTrack();
    void SetRedbookPaused(bool paused);
    void RestartMusic(int fadeOutMilliseconds);
    void ReinitializeAudioDriver();

private:
    friend class BaramApp;

    void SetDigitalAudioMuted(bool muted);
    void StopRedbookAndCancelTrackTimer();

    bool m_musicOptionEnabled;
    bool m_soundEffectsOptionEnabled;
    HDIGDRIVER m_digitalDriver;
    bool m_musicPlaybackEnabled;
    int m_streamVolume;
    HSTREAM m_stream;
    HREDBOOK m_redbookHandle;
    int m_redbookTrackCount;
    int m_redbookOrderIndex;
    int m_currentRedbookTrack;
    int m_currentTrackVolumeScale;
    int m_currentTrackIndex;
    int m_currentLoopCount;
    int m_pendingTrackIndex;
    int m_pendingTrackVolumeScale;
    int m_pendingLoopCount;
    bool m_musicAdvanceRequested;
    bool m_soundEffectsEnabled;
    int m_soundEffectVolume;
    SoundSampleSlot m_sampleSlots[8];
    void *m_samplePayloads[1000];
    std::vector<SoundPathString> m_localMusicPaths;
    unsigned char m_redbookOrder[100];
    int m_currentMusicZoneId;
    std::vector<SoundPathString> m_zoneMusicTracks;
    bool m_randomizeZonePlaylist;
    bool m_zonePlaylistActive;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 4: new `by-memory/0x00579a30-0x00579ca5.SoundManagerConstructor.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SoundManager::SoundManager()
    : m_digitalDriver(0),
      m_stream(0),
      m_redbookHandle(0),
      m_redbookTrackCount(0),
      m_redbookOrderIndex(0),
      m_currentRedbookTrack(0),
      m_currentTrackIndex(0),
      m_pendingTrackIndex(-1)
{
    m_musicPlaybackEnabled = g_pConfig->m_musicEnabled;
    m_musicOptionEnabled = m_musicPlaybackEnabled;
    m_soundEffectsOptionEnabled = m_soundEffectsEnabled;
    m_streamVolume = 100;
    m_soundEffectsEnabled = g_pConfig->m_soundEffectsEnabled;
    m_soundEffectVolume = 100;
    m_currentTrackVolumeScale = 100;
    m_musicAdvanceRequested = false;

    ReinitializeAudioDriver();

    if (m_digitalDriver != 0) {
        m_musicPlaybackEnabled = g_pConfig->m_musicEnabled;
        m_streamVolume = g_pConfig->m_musicVolume;
        m_soundEffectsEnabled = g_pConfig->m_soundEffectsEnabled;
        m_soundEffectVolume = g_pConfig->m_soundVolume;
        m_currentTrackVolumeScale = 100;
        AIL_set_preference(42, g_pConfig->m_musicOutputSelection);
    }

    m_zonePlaylistActive = false;
    m_currentMusicZoneId = 0;
    m_zoneMusicTracks.clear();

    if (m_digitalDriver != 0) {
        for (int sampleId = 0; sampleId < 1000; ++sampleId) {
            SimpleUString sampleName(L"%03d.wav", sampleId);

            if (HasDATEntry(sampleName.c_str())) {
                DATFile sampleFile;
                sampleFile.Open(sampleName.c_str());
                m_samplePayloads[sampleId] = sampleFile.GetDataPointer();
                sampleFile.Close();
            } else {
                m_samplePayloads[sampleId] = 0;
            }
        }
    }

    ScanMusicDirectory(g_pConfig->m_musicFolderPath,
                       g_pConfig->m_randomizeMusicOrder != 0,
                       true);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 5: new `by-memory/0x00579cb0-0x00579dbf.SoundManagerDestructor.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SoundManager::~SoundManager()
{
    enum { kRedbookTrackEndedTimer = 0x504e4354 };

    if (m_digitalDriver != 0) {
        for (int slot = 0; slot < 8; ++slot) {
            if (m_sampleSlots[slot].handle != 0)
                AIL_release_sample_handle(m_sampleSlots[slot].handle);
        }
    }

    if (m_stream != 0) {
        AIL_close_stream(m_stream);
        m_stream = 0;
    }

    if (m_digitalDriver != 0) {
        AIL_close_digital_driver(m_digitalDriver);
        m_digitalDriver = 0;
    }

    AIL_release_all_timers();
    AIL_shutdown();

    if (m_redbookHandle != 0) {
        AIL_redbook_stop(m_redbookHandle);
        CancelTimer(kRedbookTrackEndedTimer);
        AIL_redbook_close(m_redbookHandle);
        m_redbookHandle = 0;
        m_redbookTrackCount = 0;
        m_redbookOrderIndex = 0;
        m_currentRedbookTrack = 0;
        CancelTimer(kRedbookTrackEndedTimer);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 6: new `by-memory/0x0057b9a0-0x0057b9ab.SoundManagerConstructorUnwindSingletonClear.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 7: new `by-memory/0x0057bb30-0x0057bc59.SoundManagerScalarDeletingDestructor.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 8: new `by-memory/0x0062ce78-0x0062ce84.SoundManagerVtableData.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Destination 1 is blank because binary storage is represented once by Destination 2.
- Destination 2 is source-complete for the `.cpp` module definition. A header extern is separate proper declaration placement, not missing C++ in this destination.
- Destination 3 preserves every current class declaration byte except adding direct Singleton inheritance in the source/RTTI order.
- Destination 4 omits explicit global publication, vptr stores, base/member constructors, EH code, raw offsets, and decompiler labels. The surprising option assignment order is intentionally preserved.
- Destination 5 includes only authored cleanup. Member vector destructors, TimerHandler destruction, Singleton clear, scalar flags/free, and vptr stores remain compiler generated.
- Destinations 6-8 are exact blank no-code blocks for compiler output.
- No third-party import applies.

## Final Recommendation

- C01-C40 were applied at full report-level detail after supervisor acceptance.
- UID0004UF and exact children UID0004UG-UID0004UK were registered serially; each validator-issued UID replaced its provisional token before any later registration or cross-link.
- Destinations 1-8 were applied exactly, with the complete SoundManager class/formal union preserved except for the accepted inheritance change.
- Only target/new-destination scores were raised. UID0000DG/UID0000NV/UID0001I7/UID0001I8/UID0001IC/UID00026I scores and unrelated metadata remain unchanged.
- UID0001I7 and UID0001IC broad aggregate markers remain independent source-family debt; they were neither misreported as target failures nor eliminated by blanking legitimate unresolved source methods.
- Manual coverage remained read-only; the exact supervisor-owned handoff below remains the durable external action set.

## Recommended Target Doc Changes

- Applied target path: `by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md`.
- Applied metadata: `92/94`; canonical owner `0004UF`; `RECONSTRUCTABLE:FALSE`; blank emitters/position/formal; exact UID/path/title/range and `Nested:0` preserved.
- Exact Item Summary: `Exact zero-initialized four-byte backing storage for semantic g_pSoundManager; 117 data xrefs comprise five direct Singleton lifetime writes/clears and 112 reads; source definition emits once from the semantic global, so this page is non-emitting evidence.`
- Destination 1 was applied exactly.
- Complete 117-xref grouping, all lifetime addresses, representative consumers, adjacency, DAT/Miles/Config/Application behavior, canonical type/name, linkage, source placement, compiler distinctions, and negative/rejected history were preserved.
- The former "reconstructable NexusTK global data" and direct file-emitter wording is explicitly historical and superseded by the semantic-global one-definition route.

## Recommended Support Doc Changes

1. Created `by-global/g_pSoundManager.md` as UID0004UF: `92/94`, owner/emitter `0000NV`, position `0`, reconstructable true, Destination 2, exact backing/lifetime/consumer/RTTI/ODR/header-placement evidence.
2. Updated `by-class/SoundManager.md`: preserved `92/94`, owner/emitter/position/layout/methods/fields/children/history; applied Destination 3; added direct Singleton RTTI/PMD/EBO and lifecycle/source-compiler evidence.
3. Updated `by-file/SoundManager.md`: preserved `92/93`, path/root/order and full source union; added position-zero semantic global, positions 20/30 constructor/destructor, exact compiler children, source/compiler no-duplicate policy, and generated assertions.
4. Created `by-memory/0x00579a30-0x00579ca5.SoundManagerConstructor.md` as UID0004UG: `92/94`, owner/emitter `0000DG`, position `20`, reconstructable true, `Nested:0`, exact Item Summary and Destination 4.
5. Created `by-memory/0x00579cb0-0x00579dbf.SoundManagerDestructor.md` as UID0004UH: `92/94`, owner/emitter `0000DG`, position `30`, reconstructable true, `Nested:0`, exact Item Summary and Destination 5.
6. Created `by-memory/0x0057b9a0-0x0057b9ab.SoundManagerConstructorUnwindSingletonClear.md` as UID0004UI: `90/94`, owner NONE, false, blank emitter/position, `Nested:0`, exact Item Summary and blank Destination 6.
7. Created `by-memory/0x0057bb30-0x0057bc59.SoundManagerScalarDeletingDestructor.md` as UID0004UJ: `91/94`, owner NONE, false, blank emitter/position, `Nested:0`, exact Item Summary and blank Destination 7.
8. Created `by-memory/0x0062ce78-0x0062ce84.SoundManagerVtableData.md` as UID0004UK: `90/94`, owner `0000DG`, false, blank emitter/position, `Nested:0`, exact Item Summary and blank Destination 8.
9. Updated UID0001I7 at unchanged `88/91`: added exact ctor/dtor split links, authored-body/source order, direct Singleton lowering, and preserved five other unsplit methods plus aggregate blank C++/marker rationale.
10. Updated UID0001I8 at unchanged `88/91`, false/non-emitting: added exact lifecycle child inventory, RTTI/PMD, semantic-global split, and preserved all broad index facts.
11. Updated UID0001IC at unchanged `87/90`: added exact EH/scalar child links and no-code proof while preserving driver/callback/path/source aggregate status and marker.
12. Updated UID00026I at unchanged `88/91`, false: linked exact vtable child and preserved all UniAPI/packet/audio/status literals and mixed-index boundaries.
13. Verified without change: UID00028Q, UID0001OX, UID0001OY, Application cleanup/shutdown, Config, DATFile/DATFileMgr, TimerHandler/TimerMgr, playback/Redbook/scanner exact children, consumer pages, ignored padding, manual reports, tracker, and generated output.

Exact new-page Item Summaries:

- Constructor: `Source-authored SoundManager constructor with direct Singleton and TimerHandler base lowering, exact 0x10ac allocation route, Config audio settings, Miles driver reinitialization, 1000-entry %03d.wav DAT payload cache, and music-directory scan.`
- Destructor: `Source-authored SoundManager destructor releasing eight Miles samples, stream, digital driver, timers/runtime, and Redbook state; vector, TimerHandler, Singleton, vptr, scalar-delete, and free mechanics remain compiler-generated.`
- EH clear: `Compiler-only SoundManager constructor-unwind cleanup: exact 11-byte singleton clear with one EH-funclet jump after +4 Singleton-base adjustment and no ordinary source caller.`
- Scalar destructor: `Compiler-generated SoundManager scalar deleting destructor: vtable-only route, repeated authored/member/base teardown, Singleton clear, delete-flag bit 0 test, conditional free, and no handwritten source body.`
- Vtable: `Compiler-generated SoundManager COL/vtable span with scalar deleting destructor and OnTimer slots, three lifecycle vptr stores, direct Singleton/TimerHandler RTTI, and exclusion of following %03d.wav literal.`

## Score And Metadata Recommendation

- UID00028R: `86/90 -> 92/94`; owner `0000NV -> 0004UF`; true -> false; emitter `0000NV -> blank`; position/formal remain blank; `Nested:0` unchanged.
- New semantic global: `92/94`, owner/emitter `0000NV`, position `0`, true.
- New constructor/destructor: each `92/94`, owner/emitter `0000DG`, positions `20/30`, true, `Nested:0`.
- New EH clear/vtable: each `90/94`, false; EH owner NONE, vtable owner `0000DG`; blank emitters/positions/formals, `Nested:0`.
- New scalar wrapper: `91/94`, owner NONE, false, blank emitter/position/formal, `Nested:0`.
- Existing UID0000DG `92/94`, UID0000NV `92/93`, UID0001I7 `88/91`, UID0001I8 `88/91`, UID0001IC `87/90`, UID00026I `88/91`: scores/routes preserved.
- Completion reaches 92 because source owner/type/linkage, exact storage, all lifecycle routes, inheritance, source/compiler split, authored constructor/destructor, ranges, source positions, and generated uniqueness are resolved.
- Confidence reaches 94 because all facts are live-MCP-backed and cross-checked against current docs. It stays below 95 because original private lexical spellings, exact header filename, and null-literal style are not provable.
- No score is raised on broad aggregates because their other independent source methods/helpers remain outside this direct global/lifecycle split.

## Open Questions With Attempted Resolution

- Is the pointer a separate external global or Singleton template static member? RTTI proves Singleton behavior, but project source vocabulary and unqualified cross-module `g_pSoundManager` use support a separate external definition. Resolution: external semantic global with direct Singleton base behavior.
- Is the Singleton source base first or second? RTTI BCA lists Singleton before TimerHandler; PMDs show empty Singleton at +4 and polymorphic TimerHandler at 0. Resolution: source order Singleton, TimerHandler; old-MSVC EBO explains physical offsets.
- Should constructor/destructor contain explicit global writes? Exact PMD/EH/reverse teardown proves those are base lowering. Resolution: omit explicit writes/clears.
- Should the EH/scalar/vtable pages emit covered-by comments? Compiler regenerates all three from declarations, and marker source would pollute generated C++. Resolution: false/non-emitting blank blocks with exhaustive prose.
- Can the semantic global compile without a complete class? Yes, pointer definition needs only a local forward declaration. Resolution: Destination 2 is source-complete for the module; header extern remains separate placement.
- Does the pre-load SFX mirror indicate a decompiler error? Instruction order is direct and field offsets are independently established. Resolution: preserve observed legacy order; do not infer a source fix.
- Are aggregate markers target blockers? UID0001I7/UID0001IC contain other unsplit source methods. Resolution: preserve their independent markers; target acceptance checks only eliminate UID00028R and new compiler-page markers while adding exact ctor/dtor bodies.
- No in-scope question remains unresolved. The only residuals are lexical/header-file uncertainty already reflected in confidence, not C++ or ownership blockers.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Manual reports were reread without editing after final waited command `000000015501`: by-memory SHA256 `DBBE05F492E692CB4F9AAC44C089AF2DB4D639A5B01839AFCE183524174BB0AA` (1,866,899 bytes / 4,417 lines), by-class `180AAA33BCF01060F431021B96CDF1EDF23C6C8077107339D3C31241CB895D72` (241,906 / 623), by-file `98F7A112CE92D6D3E888EAB109345C1EA0EA9DD3B2065FBAF18620A3F50103E8` (139,437 / 316), and by-global `CCD3A1EEDCE573D08F35204E03C2B555F60C6A73541B9BE2ADD082888D7CE474` (91,029 / 213). The pre-callback `AC9FA5.../E8DFAE.../4EC54A.../C7F9B2...` snapshots and earlier epochs are historical evidence-time facts. All thirteen in-scope current rows/placements were reread: UID0001I8, UID0001I7, UID0001IC, UID00026I, UID00028R, UID0000DG, and UID0000NV still carry pre-callback descriptions or scores, and no rows yet exist for UID0004UF/UID0004UG/UID0004UH/UID0004UI/UID0004UJ/UID0004UK. The exact no-loss supervisor-owned handoff below therefore remains required and unapplied.

1. In `by-memory/-coverage-report.md`, replace the current UID0001I8 row at the existing `0x005797b0` placement with:

`    - [UID:0001I8][0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster](by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md) 0x005797b0-0x0057bf6e | SoundManager aggregate | SoundManagerAudioHelperCluster : not_reconstructable : 88% : very-strong : Non-emitting broad SoundManager audio-family index preserving 53 modeled functions before SoundStatusPane, superseding the historical incomplete 47-function count; exact UID0001IA scanner range 0x0057a890-0x0057afce; raw helper bodies; DAT-backed music and sound-effect policy; exact playback controls; Redbook helpers; Miles file callbacks; driver/path behavior; vtable/singleton lifecycle; boundary padding; and the adjacent old-MSVC std::vector/std::deque/StringBase instantiation island. Exact children retain source/no-code ownership, UID0004FM remains routed through StringBaseTemplate, direct Singleton<SoundManager>/TimerHandler RTTI and the semantic g_pSoundManager backing split are recorded, and exact constructor/destructor/EH/scalar/vtable lifecycle children add no duplicate aggregate source.`

2. Replace the current UID0001I7 row immediately after UID0001I8 with:

`    - [UID:0001I7][0x005797b0-0x0057a25c.SoundManagerMusicSelection](by-memory/0x005797b0-0x0057a25c.SoundManagerMusicSelection.md) 0x005797b0-0x0057a25c | method-cluster | SoundManagerMusicSelection : reconstructable : 88% : strong : SoundManager music/lifecycle aggregate preserving five unsplit DAT playlist/direct-track, stream-reset, GetDigitalDriver, and playback-selection methods; local-path behavior; %08d.LST/%08d.LSR/%08d.MP3 resource policy; corrected PlayTrackByIndex/PlayMusicByZone volumeScale flow into m_currentTrackVolumeScale and Miles stream volume; standard SoundPathString vectors at +0x1028/+0x109c; compiler-emitted clear paths at 0x00579f9a/0x0057a214; exact caller/range/padding evidence; and local-mode consumption of the source-ready UID0001IA scanner. Exact source children UID0004UG and UID0004UH add constructor/destructor bodies; direct Singleton publication/clear, vector/base teardown, and compiler wrappers remain excluded while aggregate C++ stays blank for the other five methods.`

3. Insert after UID0001I7 in address order:

`    - [UID:0004UG][0x00579a30-0x00579ca5.SoundManagerConstructor](by-memory/0x00579a30-0x00579ca5.SoundManagerConstructor.md) 0x00579a30-0x00579ca5 | constructor | SoundManagerConstructor : reconstructable : 92% : very-strong : Source-ready SoundManager constructor with exact 0x10ac startup allocation, direct Singleton/TimerHandler lowering, Config audio-option order, Miles driver reinitialization, 1000-entry %03d.wav DAT payload cache, zone reset, and local music-directory scan.`

4. Insert after the constructor row:

`    - [UID:0004UH][0x00579cb0-0x00579dbf.SoundManagerDestructor](by-memory/0x00579cb0-0x00579dbf.SoundManagerDestructor.md) 0x00579cb0-0x00579dbf | destructor | SoundManagerDestructor : reconstructable : 92% : very-strong : Source-ready SoundManager destructor releasing eight sample handles, stream, digital driver, Miles timers/runtime, and Redbook state while vector, TimerHandler, Singleton, vptr, scalar-delete, and free mechanics remain compiler-generated.`

5. Replace the current UID0001IC row at `0x0057b490` with:

`    - [UID:0001IC][0x0057b490-0x0057bf6e.SoundManagerDriverDestructorAndPathHelpers](by-memory/0x0057b490-0x0057bf6e.SoundManagerDriverDestructorAndPathHelpers.md) 0x0057b490-0x0057bf6e | method-cluster | SoundManagerDriverDestructorAndPathHelpers : reconstructable : 87% : strong : SoundManager driver/callback/path aggregate preserving Miles AIL runtime setup and reinitialization, exact AIL_set_file_callbacks open/close/seek/read callback xrefs, DATFile/HasDATEntry DAT-first behavior, StdioFile/PathExists loose-file fallback, eight sample-handle allocation and current sample-slot/payload layout, singleton/helper interleave, SoundPathVector/deque/StringBase delegation, source-ready UID0001IF SoundPathVector::Clear, scalar-wrapper placement, parent SoundManager.cpp attachment, and blank aggregate C++. Exact compiler-only constructor-unwind child UID0004UI and scalar-wrapper child UID0004UJ are split with blank source without changing unrelated driver/callback/path source debt; the older 82%/95-gate and MCP-timeout caveats are historical and superseded by current healthy bounded evidence.`

6. Insert at `0x0057b9a0` before UID0001IE:

`    - [UID:0004UI][0x0057b9a0-0x0057b9ab.SoundManagerConstructorUnwindSingletonClear](by-memory/0x0057b9a0-0x0057b9ab.SoundManagerConstructorUnwindSingletonClear.md) 0x0057b9a0-0x0057b9ab | compiler EH cleanup | SoundManagerConstructorUnwindSingletonClear : not_reconstructable : 90% : very-strong : Exact 11-byte g_pSoundManager clear reached only from the constructor EH funclet after +4 Singleton-base adjustment; compiler-generated direct-base unwind with no handwritten source body.`

7. Insert at `0x0057bb30` after the existing helper rows at lower addresses:

`    - [UID:0004UJ][0x0057bb30-0x0057bc59.SoundManagerScalarDeletingDestructor](by-memory/0x0057bb30-0x0057bc59.SoundManagerScalarDeletingDestructor.md) 0x0057bb30-0x0057bc59 | compiler deleting destructor | SoundManagerScalarDeletingDestructor : not_reconstructable : 91% : very-strong : Vtable-only scalar deleting destructor repeating authored/member/base cleanup, clearing the direct Singleton, testing delete flag bit 0, and conditionally freeing the 0x10ac object; compiler-generated with blank source.`

8. Replace the current UID00026I row at `0x0062ce50` with:

`    - [UID:00026I][0x0062ce50-0x0062cfd8.NetworkAndAudioReadOnlyData](by-memory/0x0062ce50-0x0062cfd8.NetworkAndAudioReadOnlyData.md) 0x0062ce50-0x0062cfd8 | mixed rdata index | NetworkAndAudioReadOnlyData : not_reconstructable : 88% : strong : Non-emitting mixed .rdata index preserving UNL.DLL at 0x0062ce50 and RegisterUniApp at 0x0062ce60 tied to the unreferenced raw UniAPI registration helper at 0x00578ea0; %s%s packet-transform string-key format at 0x0062ce70; SoundManager COL/vtable pointer region beginning at 0x0062ce78 with first function slot 0x0062ce7c; exact %03d.wav, %08d.MP3, %08d.LST, and %08d.LSR audio literals; SoundStatusPane vtables and Music On/Music Off/Sound On/Sound Off/%s/%s captions; and corrected SpellInventoryPane successor boundary 0x0062cfd8, superseding the historical 0x0062ce60-0x0062d02c span. Exact compiler-generated SoundManager child UID0004UK owns 0x0062ce78-0x0062ce84, and owning source pages emit declarations/literals without duplicate aggregate source.`

9. Insert immediately after UID00026I:

`    - [UID:0004UK][0x0062ce78-0x0062ce84.SoundManagerVtableData](by-memory/0x0062ce78-0x0062ce84.SoundManagerVtableData.md) 0x0062ce78-0x0062ce84 | compiler vtable data | SoundManagerVtableData : not_reconstructable : 90% : very-strong : Exact SoundManager COL plus scalar-deleting-destructor and OnTimer slots, three lifecycle vptr stores, direct Singleton<SoundManager>/TimerHandler RTTI, and strict exclusion of following %03d.wav literal; generated from declarations with blank source.`

10. Replace the current UID00028R row at `0x0067a7d0`, preserving its placement between UID0001OX and UID0001OY, with:

`    - [UID:00028R][0x0067a7d0-0x0067a7d4.g_pSoundManager](by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md) 0x0067a7d0-0x0067a7d4 | global backing storage | g_pSoundManager : not_reconstructable : 92% : very-strong : Exact zero-filled SoundManager pointer backing slot with 117 xrefs comprising five direct Singleton construction/fallback/unwind/ordinary-destruction/scalar-wrapper writes or clears and 112 cross-module readers; preserves Miles/DAT audio-setup ownership and UI/Bink/Miles/hotkey consumers. Historical direct SoundManager-file parent attachment is superseded by semantic owner UID0004UF; the sole externally linked source definition emits there, so this physical page is non-emitting without duplicate storage.`

11. In `by-global/-coverage-report.md`, insert alphabetically between `g_pSimpleHelpPane2` and `g_pSoundStatusPane`:

`- [UID:0004UF][g_pSoundManager](by-global/g_pSoundManager.md) : reconstructable : 92% : very-strong : Sole externally linked SoundManager pointer module definition in NexusTK/audio/SoundManager.cpp at position 0, preceded by a local class forward declaration and backed by exact storage UID00028R; the matching header extern remains separate proper declaration placement. Live IDA proves zero storage, 117 refs, five direct Singleton<SoundManager> lifetime writes/clears, 112 cross-module readers, direct Singleton/TimerHandler RTTI, exact constructor/destructor/EH/scalar/vtable split, and one-definition policy.`

12. In `by-class/-coverage-report.md`, replace UID0000DG at its current alphabetical placement with:

`- [UID:0000DG][SoundManager](by-class/SoundManager.md) : reconstructable : 92% : very-strong : Complete x86/MSVC 0x10ac natural-alignment SoundManager declaration with direct Singleton<SoundManager> then TimerHandler inheritance and PMD/EBO proof; Miles handles; option/runtime bytes; stream/Redbook tuples; eight SoundSampleSlot records; 1000 DAT payload pointers; standard local/zone SoundPathString vectors; complete playback, Redbook, scanner, OnTimer, and DirectSound method surface; PlaySample plus inline PlayEffect alias; BaramApp friend/private access; exact source constructor/destructor children; compiler-only Singleton publication/clear, EH/scalar/vptr/vtable/vector/base exclusions; exact child emission; and one-definition g_pSoundManager route through SoundManager.cpp.`

13. In `by-file/-coverage-report.md`, replace UID0000NV at its current alphabetical placement with:

`- [UID:0000NV][SoundManager](by-file/SoundManager.md) : reconstructable : 92% : very-strong : NexusTK/audio/SoundManager.cpp source root with the sole position-zero g_pSoundManager definition; complete direct-Singleton/TimerHandler 0x10ac class declaration; exact authored constructor/destructor at positions 20/30; playback-control children at 100-290; music-directory scanner at 300; Redbook children at 400-470; complete Miles driver/file-callback, DAT-backed sample/music, Config, Application, TimerHandler OnTimer, and DirectSound behavior; preserved compiler/STL helper exclusions, exact source order, and generated verification requirements; and compiler-only Singleton publication/clear, EH, scalar, vector/base, vptr, and vtable output. Broad UID0001I7/UID0001IC markers remain only for their other independent unsplit methods, with no duplicate global or lifecycle source.`

Reason B005 did not apply these rows: all four manual `-coverage-report.md` files are supervisor-owned and explicitly read-only for this assignment. Validator-generated tracker state was refreshed from ordinary metadata during the completed callback and did not receive manual row edits.

## Follow-Up Actions

- B005's accepted callback responsibilities are complete: all six pages were registered serially, all ordinary destinations were applied and scoped-validated, every provisional token was removed, all leases were released, and final waited command `000000015501` verified generated output.
- The exact thirteen-action manual coverage handoff remains unapplied in supervisor-owned files at this artifact checkpoint. Its application, independent review, and report lifecycle state remain external to this completed callback artifact.
- No B005 target implementation or research action remains for UID00028R. The other five UID0001I7 methods and unrelated UID0001IC source families remain independent targets, not hidden work in this report.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong.
- Remaining uncertainty: exact original header filename, private lexical names, and use of `0` versus `NULL`. None changes storage, ABI, layout, owner, source file, body behavior, or compile legality.

## Validator Results

All commands ran from the canonical project root with exit `0` and `ok:1`. A one-file lease was held only for the active ordinary destination, its content was reread after acquisition, and the lease was released immediately after the listed scoped validator. Registration commands issued the real UID before any later cross-link.

| Command | Timestamp (ET) | Validated destination | Result / side effects |
| --- | --- | --- | --- |
| `000000015483` | `2026-07-20T17:33:44-04:00` | register UID0004UF under `by-file/SoundManager.md` | exit 0 / ok1; registry metadata/refs/stats refreshed; generated refresh deferred; parent lease released |
| `000000015484` | `2026-07-20T17:36:37-04:00` | register UID0004UG under UID0001I7 | exit 0 / ok1; real UID captured and substituted; generated refresh deferred; parent lease released |
| `000000015485` | `2026-07-20T17:38:25-04:00` | register UID0004UH under UID0001I7 | exit 0 / ok1; real UID captured and substituted; generated refresh deferred; parent lease released |
| `000000015486` | `2026-07-20T17:39:42-04:00` | register UID0004UI under UID0001IC | exit 0 / ok1; real UID captured and substituted; generated refresh deferred; parent lease released |
| `000000015487` | `2026-07-20T17:40:59-04:00` | register UID0004UJ under UID0001IC | exit 0 / ok1; real UID captured and substituted; generated refresh deferred; parent lease released |
| `000000015490` | `2026-07-20T17:43:19-04:00` | register UID0004UK under UID00026I | exit 0 / ok1; real UID captured and substituted; generated refresh deferred; parent lease released |
| `000000015494` | `2026-07-20T17:45:12-04:00` | UID00028R | exit 0 / ok1; refs/stats refreshed; generated refresh deferred; lease released |
| `000000015495` | `2026-07-20T17:46:09-04:00` | UID0000DG `by-class/SoundManager.md` | exit 0 / ok1; refs/stats refreshed; generated refresh deferred; lease released |
| `000000015496` | `2026-07-20T17:47:08-04:00` | UID0000NV `by-file/SoundManager.md` | exit 0 / ok1; refs/stats refreshed; generated refresh deferred; lease released |
| `000000015497` | `2026-07-20T17:48:37-04:00` | UID0001I7 | exit 0 / ok1; refs/stats refreshed; generated refresh deferred; lease released |
| `000000015498` | `2026-07-20T17:49:19-04:00` | UID0001I8 | exit 0 / ok1; refs/stats refreshed; generated refresh deferred; lease released |
| `000000015499` | `2026-07-20T17:50:04-04:00` | UID0001IC | exit 0 / ok1; refs/stats refreshed; generated refresh deferred; lease released |
| `000000015500` | `2026-07-20T17:50:51-04:00` | UID00026I | exit 0 / ok1; refs/stats refreshed; generated refresh deferred; lease released |
| `000000015501` | `2026-07-20T17:51:10-04:00` | final waited `by-file/SoundManager.md` refresh | exit 0 / ok1; generated refresh completed after zero leases; pre-existing global warnings: 13 fallback inserts, 85 missing child markers, 134 empty emitters; registry rebuilt 5,174 nodes/4,145 edges and 280 metadata records refreshed; no target error |

Current command-15501 `SoundManager.cpp` readback proves one `SoundManager *g_pSoundManager = 0;` at line 10, one direct `Singleton<SoundManager>, public TimerHandler` class shell at line 28, one constructor at line 117, and one ordinary destructor at line 172. It has zero UID00028R/UID0004UI/UID0004UJ/UID0004UK markers, zero duplicate definitions, and zero cookie/raw-label/decompiler/explicit-Singleton/ABI/free mechanics. Independent UID0001I7 and UID0001IC markers remain exactly once each; playback, scanner, and Redbook ordering remains intact.

## Changed Files

- Created ordinary pages: `by-global/g_pSoundManager.md` (UID0004UF), `by-memory/0x00579a30-0x00579ca5.SoundManagerConstructor.md` (UID0004UG), `by-memory/0x00579cb0-0x00579dbf.SoundManagerDestructor.md` (UID0004UH), `by-memory/0x0057b9a0-0x0057b9ab.SoundManagerConstructorUnwindSingletonClear.md` (UID0004UI), `by-memory/0x0057bb30-0x0057bc59.SoundManagerScalarDeletingDestructor.md` (UID0004UJ), and `by-memory/0x0062ce78-0x0062ce84.SoundManagerVtableData.md` (UID0004UK).
- Updated ordinary pages: `by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md`, `by-class/SoundManager.md`, `by-file/SoundManager.md`, `by-memory/0x005797b0-0x0057a25c.SoundManagerMusicSelection.md`, `by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md`, `by-memory/0x0057b490-0x0057bf6e.SoundManagerDriverDestructorAndPathHelpers.md`, and `by-memory/0x0062ce50-0x0062cfd8.NetworkAndAudioReadOnlyData.md`.
- Current ordinary hashes/metrics after command `15501`: UID0004UF `BC31D6A198DED99A5CE50A3BE0A29A336A125EC308ECABCD952EC756E2783ECD` (8,562 bytes / 87 lines); UID0004UG `0C3DAC80CD2A8E68FDEC6AEAD57CB25335770E45107D3B87651EB6FA85E56A80` (9,566 / 142); UID0004UH `DA49E7641FA446466A8B37C4DE92C219DCBAE8ABBAFD47D5F8A4760FCED35625` (7,558 / 117); UID0004UI `9ADC094C8C5601280886A1854CADC0B792590D64FF6122D712A7DF525549D3FC` (5,549 / 73); UID0004UJ `5F0BB64915BC5AFF056A7E821C089AE397B8730637AA9288AB3746892D9B4799` (6,199 / 75); UID0004UK `E4F0389DF0B03F97B9DD5F3B26BF40CEEAE67CF5F0B3B2D4B1D21615AC11A181` (5,889 / 80).
- Current updated ordinary hashes/metrics: UID00028R `8087180FC53789B09DA127AA0EF97E3AECBD01001813DD6E7D066EF93EA2D185` (11,660 / 111); UID0000DG `6B47EFDB124BBA1103C1B982D8F6A22EFCBBADDA3E3C3C4D16EC39BF72356DB1` (43,336 / 365); UID0000NV `421E0624EC0008AB0F22695A63AFA8F02B0C709E68FDDF868454E70B6D38F5BB` (51,744 / 300); UID0001I7 `42A4D7D517F7BE4ED92585C9B69789124FDCF36FE0081A49664179AB3CE672EC` (26,606 / 189); UID0001I8 `0C72E67B746AEC0CE1C824202D11DA674D16B6553057A966B616308AAF88EA25` (37,565 / 207); UID0001IC `12B1EC18432170C1523A021E4B00D9F133311A7645C21E42E546F1B3AB0A37B2` (30,396 / 188); UID00026I `B602283AAE5E7FF0C34EE2150A0C111A72E2311C0E83FC353E3C65491E8460CA` (21,127 / 168).
- Verify-only UID0001OX and UID0001OY remained unchanged at their callback baselines; no contradiction required an edit.
- Read-only external checkpoint: generated `SoundManager.cpp` remains at B005 waited command `000000015501`, SHA256 `AC793B560A1C19E0C040B11CD1A682FC21CBE1E751E01B54976AE35EF7873684` (25,736 bytes / 779 lines). The final tracker read at `2026-07-20T18:06:23-04:00` observed external command `000000015521`, SHA256 `473B642B5EBABF948397390263E9C27DE9C7105B089E3037833B93F34F1EF94F` (1,534,976 bytes / 6,217 lines), with exactly one row for UID0004UF/UID0004UG/UID0004UH/UID0004UI/UID0004UJ/UID0004UK/UID00028R and the accepted scores, routes, reconstructable states, and no unresolved token. This is an explicit evidence-time checkpoint rather than a permanent claim about later unrelated validator epochs. Tracker commands `15501/15511/15520` and their hashes are historical callback/external checkpoints; command `15475` and SHA values `85B51D...4672A` / `105542...41E45` are historical pre-callback evidence, as are earlier report-build epochs.
- Current manual hashes are recorded in the exact handoff section; no manual coverage file was edited. Generated/tracker changes were validator side effects only, not manual edits.
- Updated callback artifact: `tools/leaser/Agents/Agent-B005/research/00028R-g_pSoundManager-source-quality.md`.
- Renamed/moved/archived: none. Report execution/lifecycle commands: none.
- Lease state: every ordinary lease was released immediately after its validator; zero B005 leases remain.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validates the exact report artifact before any ordinary edit.
- [x] Re-read every destination and verify-only dependency immediately before callback editing.
- [x] Register new semantic `by-global/g_pSoundManager.md` serially and capture real UID.
- [x] Replace the provisional semantic-global UID token with real UID0004UF before linking or validating another page.
- [x] Register constructor page `[0x00579a30,0x00579ca5)` serially and capture real UID.
- [x] Replace the provisional constructor UID token with real UID0004UG before cross-linking.
- [x] Register destructor page `[0x00579cb0,0x00579dbf)` serially and capture real UID.
- [x] Replace the provisional destructor UID token with real UID0004UH before cross-linking.
- [x] Register EH clear page `[0x0057b9a0,0x0057b9ab)` serially and capture real UID.
- [x] Replace the provisional EH-clear UID token with real UID0004UI before cross-linking.
- [x] Register scalar wrapper page `[0x0057bb30,0x0057bc59)` serially and capture real UID.
- [x] Replace the provisional scalar-wrapper UID token with real UID0004UJ before cross-linking.
- [x] Register vtable page `[0x0062ce78,0x0062ce84)` serially and capture real UID.
- [x] Replace the provisional vtable UID token with real UID0004UK before cross-linking.
- [x] Apply C01-C40 with each ledger row remaining atomic and destination-verifiable.
- [x] Apply UID00028R metadata, exact Item Summary, Destination 1, evidence, history, and rejected alternatives.
- [x] Apply new semantic-global metadata, Destination 2, backing/lifetime/consumer/source/header/ODR evidence.
- [x] Apply Destination 3 to UID0000DG while preserving every other formal byte and all current class detail.
- [x] Create/apply constructor metadata, exact Item Summary, Destination 4, bytes/CFG/caller/config/DAT/scanner/source/compiler detail.
- [x] Create/apply destructor metadata, exact Item Summary, Destination 5, cleanup/timer/source/compiler detail.
- [x] Create/apply EH metadata, exact Item Summary, blank Destination 6, bytes/xref/PMD/no-code proof.
- [x] Create/apply scalar metadata, exact Item Summary, blank Destination 7, vtable/flags/free/no-code proof.
- [x] Create/apply vtable metadata, exact Item Summary, blank Destination 8, bytes/slots/RTTI/boundary/no-code proof.
- [x] Update UID0000NV at report-level detail without changing its score/path/root/unrelated union.
- [x] Update UID0001I7 at report-level detail without changing score/owner/emitter/aggregate blank-body disposition.
- [x] Update UID0001I8 at report-level detail without changing score/false/non-emitting broad-index disposition.
- [x] Update UID0001IC at report-level detail without changing score/owner/emitter/aggregate marker disposition.
- [x] Update UID00026I at report-level detail without changing score/false/mixed-index boundaries or unrelated contents.
- [x] Preserve UID00028Q, UID0001OX, UID0001OY and all other verify-only dependencies unchanged absent documented contradiction.
- [x] Preserve exact five lifetime sites, 112-read consumer grouping, shutdown flag-1 delete, all positive/negative evidence, and historical corrections.
- [x] Preserve exact constructor legacy option order, 1000-entry loop, DATFile close/destructor behavior, and final scanner call.
- [x] Preserve exact destructor sample/stream/driver/Miles/Redbook/timer behavior and omit all compiler lowering.
- [x] Confirm no handwritten raw address, decompiler label, vptr, EH, scalar flag/free, vector/base destructor, or Singleton assignment/clear appears.
- [x] Confirm no third-party import applies.
- [x] Keep all four manual coverage reports read-only and retain exact 13-action supervisor handoff.
- [x] Keep generated/tracker/audit/supervisor/validator/IDA/lifecycle files read-only.
- [x] Run no report execution/probe/move/archive/lifecycle command.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] One ordinary file leased only immediately before edit, reread after acquisition, scoped-validated, and released immediately.
- [x] No lease wait occurs while another lease is held.
- [x] One scoped validator is recorded for each changed ordinary page with command ID, timestamp, exit, ok count, warnings, and side effects.
- [x] All six validator-issued UIDs are real and no brace token remains anywhere in the report or ordinary docs.
- [x] Every C01-C40 row has a legal terminal callback state and adjacent destination/validator/generated proof.
- [x] Every accepted target/support fact is incorporated at same-or-greater report detail or excluded with an exact reason.
- [x] All historical assumptions, rejected alternatives, negative evidence, range/padding facts, and lexical caps remain preserved.
- [x] Final authorized `--wait-generated` refresh runs only after all ordinary leases clear.
- [x] Generated SoundManager.cpp has one semantic global definition at position zero.
- [x] Generated class shell has direct Singleton then TimerHandler inheritance and remains otherwise byte-for-byte equivalent.
- [x] Generated SoundManager.cpp has exactly one constructor and one ordinary destructor in positions 20/30.
- [x] Generated output has zero UID00028R, EH-clear, scalar-wrapper, or vtable empty markers/definitions.
- [x] Existing unrelated UID0001I7/UID0001IC markers and current playback/scanner/Redbook output remain intact.
- [x] Generated output contains no duplicate global, duplicate lifecycle body, cookie, raw label, decompiler cast, vptr write, explicit Singleton write/clear, scalar flag/free, or vector/base teardown.
- [x] Tracker readback reflects target/global/new-page scores, routes, reconstructable states, and no unresolved UID token.
- [x] Current ordinary/generated/tracker/manual hashes and readback metrics are recorded in the same report with mutable epochs labeled time-bounded.
- [x] Exact manual handoff is rechecked against current disk and updated no-loss without direct coverage edits.
- [x] All accepted implementation rows are checked only after readback proves them true.
- [x] All B005 leases are released and zero remain.
- [x] Same report ends with the supervisor-requested post-callback readiness marker only after full reconciliation.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000015549","destination_path":"executed-b-agent-research/B005/00028R-g_pSoundManager-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00028R-g_pSoundManager-source-quality.md","timestamp":"2026-07-20T18:17:47-04:00","uid":"00028R"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
