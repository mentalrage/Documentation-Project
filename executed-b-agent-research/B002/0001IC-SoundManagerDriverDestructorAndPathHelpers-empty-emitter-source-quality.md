** TARGET-REPORT-UID:0001IC **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001IC SoundManagerDriverDestructorAndPathHelpers Ownership / Split Research


## Finalized Report / Current Recommendation
- Current recommendation: retain the completed exact UID-preserving `SoundManager::ReinitializeAudioDriver` split at `[0x0057b490,0x0057b5f0)`, its exact source-authored driver/callback children, broad non-emitting UID0001I8 physical index, and the now-implemented private static `SoundManager::AILStreamEndCallback` source shape. The focused source-legality callback is complete: no free function reads private `m_zonePlaylistActive`.
- Current disposition: UID0001IC remains a reconstructable class-method emitter at `93/94`, direct owner/emitter UID0000DG, position `500`, with complete first-draft C++. UID0000TU occupies the exact open-callback by-memory range. Allocated UIDs 0004X1/0004WW/0004WX/0004WY/0004WZ cover the retained resume/shutdown methods and four canonically file-owned file-static File callbacks. UID0004X0 is owner/emitter UID0000DG and emits the sole qualified private-static member definition. UID0000DG retains its complete declaration and `[[CHILDREN]]` in H with the private static callback declaration; UID0004WV retains the include and exactly four file-static File-callback prototypes at position `15`.
- Generated-order correction is complete. UID0004WV and the four File callback bodies remain canonically file-owned but insert through UID0000DG at positions `15` and `520-550`; UID0004X0 follows at position `560`. Current physical command `000000017510` verifies one body each, four free prototypes at CPP lines `16-19`, callback definitions at lines `759/779/785/802/815`, one qualified stream callback, legal class-private access, and zero target empty markers. Historical command17464 remains the focused-callback checkpoint that first established the corrected shape.
- Supervisor Gate 2A and Gate 2B are complete. Catalog entry `0312` records C1IC-020/021 as `APPLIED_VERIFIED` against saved-IDB SHA256 `DCB050F31EB99C9A6037DB8E29573B8A8C4737520317C4364814F3ECCB432281`. Remaining actions are supervisor-owned fresh exact-artifact Gate 1 continuity review, execution/archive, and post-execution manual coverage. B002 completed all authorized ordinary-document work and this same-report reconciliation without mutating IDA or lifecycle state.
- Confidence: very strong for ranges, behavior, callback ABI, split, generated order, and source legality; strong for the inferred private-static source shape and original helper spellings.

## Supporting Research
- The initial research pass was report-only. Supervisor Gate 1 accepted exact artifact SHA256 `52AAAA47F020D2718B690CD62BD5E79273350C745CEC8DB35E321A77FFA9E26D`, after which B002 completed the first ordinary-document implementation callback and serial scoped validation. Supervisor then accepted focused-repair artifact SHA256 `8EFFEFCA77A1D5F85AF846F931D4071BBD3ADE96CDC5E5EF00EF1632C4BA87CB`; B002 completed the authorized source-legality callback with scoped commands `17455-17464`. B002 did not mutate IDA, edit manual coverage, execute/archive the report, or invoke any lifecycle command.
- Historical checkpoints `48EBC47071A99F8E90D2B639724A67CCB2ABA32FD34A776CA894471AE3CD8BED`, `B6A2BD3E2D92B9E77CFB82660F87E71D3709BC2D80C777140D9762234684A138`, and `9F6E2C7AA9CFB718AB146AC8F8363CC1401F8474AA63803D7FAED35FA8ADE7CF` were bounded observations during the interrupted research cycle. They are not current-state claims.
- `CB62D69DD6833431565994032CA0F8229ED7762773A223E2F1CDA93AC9047C2E`, 143,186,380 bytes, saved `2026-07-24T20:36:29.1906020-04:00`, is retained only as the historical pre-callback research checkpoint.
- Historical read-only checkpoint `9DF44486A6C1DC34A55BDE2EB8E517916E0B073D46712BC7C1B9B1D3ECB9EB4C`, 143,186,002 bytes, saved `2026-07-24T22:09:37.3164487-04:00`, remains bounded supporting evidence and is not current authority.
- The current stable read-only rebase used live MCP database `supervisor_current_20260724_9f6e` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331`, 143,186,450 bytes, saved `2026-07-24T22:54:09.6318603-04:00`. `idb_list` showed one active, non-analyzing worker PID 17444; `server_health` returned `ok`; Hex-Rays and the 2,068-entry string cache were ready. Before/after disk hashes matched.
- Older SoundManager reports and docs were treated as leads and historical support. Every target-specific action, no-change/protected item, name, type, all entry/function/regular/repeatable comment channels, range, xref total, byte boundary, collision, raw-pointer pattern, and deterministic readback assertion below was independently re-read against `7509`; all item-specific states remained continuous from historical `9DF4`.
- Supervisor Gate 2B catalog entry `0312` applied and verified the accepted handoff. The pre-mutation backup is `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-0001IC-20260725_051650.bak`, SHA256 `3B7FC953A07344D07F33CD8C244853E0CD8DBFF8AB80C4DE2839D14A9800B63C`, 143,186,450 bytes. The saved post-mutation IDB is SHA256 `DCB050F31EB99C9A6037DB8E29573B8A8C4737520317C4364814F3ECCB432281`, 143,186,002 bytes, last write `2026-07-25T05:18:07.2105424-04:00`.
- The immediate post-definition save still reported analysis pending and was not accepted as final evidence. The supervisor performed a controlled saved-IDB restart; reopened session `5f18a105` returned `status:ok`, `auto_analysis_ready:true`, Hex-Rays ready, and exact live function/comment readback for all seven actions. B002 did not perform those IDA operations.

## Target
- Target UID: `0001IC`.
- Additional target UIDs: none. UID0000TU and all proposed children are support destinations, not additional report coverage.
- Assignment-time declared-target inventory: UID0001IC named `by-memory/0x0057b490-0x0057bf6e.SoundManagerDriverDestructorAndPathHelpers.md`, a redundant mixed aggregate beginning at the exact driver reinitializer.
- Current target path: `by-memory/0x0057b490-0x0057b5f0.SoundManagerReinitializeAudioDriver.md`; the old broad path no longer exists.
- Assignment-time source queue/report row: the generated research queue reported a reconstructable empty emitter at `87/90`. Current generated SoundManager.cpp has one UID0001IC definition and zero UID0001IC empty markers.
- Current supervisor classification: source-quality split/empty-emitter repair with mandatory live IDA handoff.
- Assignment-time scores and parent state were `87/90`, `CANONICAL_OWNER:0000NV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NV`, blank position, blank formal C++, `Nested:-4`. Current state is `93/94`, owner/emitter UID0000DG, position `500`, complete CPP formal, blank H, and `Nested:0`.

## Current Target State
- Assignment-time metadata routed a broad method/helper/destructor/container interval directly to the file root and both UID0001IC/UID0000TU were empty emitters. The callback has replaced that structurally invalid state with exact children while retaining the old claims as history.
- Current UID0001IC is exact at `[0x0057b490,0x0057b5f0)`, `93/94`, class-owned/emitted at position `500`, and has complete CPP. Current UID0000TU is exact by-memory `[0x0057b630,0x0057b72b)`, `93/94`, canonically file-owned by UID0000NV and inserted through UID0000DG at position `520`, with complete CPP. Neither has a generated empty marker.
- Current callback typedefs use the Miles SDK ABI; sample slots are typed; `[0x0057b7f0,0x0057b853)` is the stream-completion callback; all exact half-open boundaries and eight CC gaps are documented; and every new page has a validator-assigned UID.
- Current UID0000DG stores the complete class declaration, both retained private method declarations, private static `AILStreamEndCallback(HSTREAM)`, and `[[CHILDREN]]` in H with CPP blank. Current UID0004WV emits the include and exactly four free static File callback prototypes before every use. UID0004X0 is owner/emitter UID0000DG and emits the sole qualified static-member body; every body page retains blank H. Command17440 is historical proof of the rejected five-free-prototype/access-illegal shape, and command17464 is historical proof of the corrected focused-callback shape. Current command17510 verifies the same accepted declaration/definition split, physical source order, and private-access legality.
- Related docs checked: UID0001I8 broad cluster, UID0000DG class, UID0000NV file, UID0000TU item, UID0001IA scanner, UID0004QX shared music tail, UID0001ID path-vector index and exact children, File/DATFile/StdioFile docs, Config/MusicControlDialog/MapPane field evidence, client audio/library docs, generated SoundManager.cpp, manual coverage rows, research tracker, and by-structure rules.
- Current artifact/lifecycle status: focused ordinary source-legality callback, post-callback Gate 1, independent Gate 2A, and supervisor Gate 2B are complete. Catalog entry `0312` and saved-IDB SHA256 `DCB050F31EB99C9A6037DB8E29573B8A8C4737520317C4364814F3ECCB432281` are the current IDA authority. Fresh exact-artifact Gate 1 continuity review, execution/archive, and post-execution manual coverage remain supervisor-owned and unchecked.

## Executive Recommendation
- Keep the implemented UID0001IC exact method and UID0001I8 sole broad physical index; keep member methods and the private static stream callback under class UID0000DG, while the four file-static File callbacks remain canonically under file UID0000NV.
- Keep the complete UID0000DG class declaration plus `[[CHILDREN]]` in H and CPP blank, including the implemented private `static void AILCALLBACK AILStreamEndCallback(HSTREAM stream);` declaration.
- Keep UID0004WV canonically owned by UID0000NV and inserted through UID0000DG at position `15`, limited to the include and four genuinely file-static File-callback prototypes. Exact body pages remain the sole CPP definitions with blank H.
- Keep UID0000TU and UID0004WX/0004WY/0004WZ canonically file-owned but inserted through UID0000DG at positions `520-550`; keep UID0004X0 owner/emitter UID0000DG at position `560` with `void AILCALLBACK SoundManager::AILStreamEndCallback(HSTREAM stream)`. This routing preserves exact physical source order without changing the four File callbacks into class members. Preserve every all-`0xcc` gap and later compiler/STL/helper disposition.
- The bounded ordinary source-legality callback and both Gate 2 parts are complete. Fresh exact-artifact continuity review, lifecycle execution/archive, and post-execution manual coverage remain supervisor-owned rather than blocked by ordinary source or IDA state.

## Supervisor Active Recheck
- The supervisor assigned UID0001IC specifically to resolve blank C++, empty emission, split/ownership, naming/type, liveness, score, and IDA handoff blockers.
- Split repair is required before the target can be an exact emitter.
- Every source-bearing body in the target head island has an exact path, range, behavior, and score. UID0004X0's source role is corrected here from free file-static callback to private static SoundManager callback; the later `[0x0057b860,0x0057bf6e)` island remains excluded from new source output.
- The related raw predecessor also has an implementation-ready support disposition rather than another deferred question.
- Header/source declaration ordering is implemented and generated-verified: complete UID0000DG declaration in H including the private static stream callback, one position-15 four-prototype file-local callback preamble in CPP, and one definition per exact body page in positions `390`, `500-560`.

## Inference Research Guidance Check
- `by-structure.md` requires exact by-memory ranges to own exact source bodies and forbids broad parents from duplicating child code. That rule makes UID0001IC narrowing preferable to another non-emitting duplicate aggregate.
- Existing claims that saved callback labels remained current, that `0x0057b7f0` was a singleton helper, and that callback signatures were unresolved were treated as uncertain and rechecked.
- Direct IDA facts, documentation facts, SDK ABI corroboration, and source-shape inference are labeled separately below.
- Historical Wave2/Wave3 wording occurs in older docs. It was ignored as stale and is not used as evidence.

## Heuristic / Inference Reanalysis And Validation
- `SoundManager__ReinitializeAudioDriver` is already a source-quality semantic name and exact `void __thiscall(SoundManager *this)` type. Source spelling `SoundManager::ReinitializeAudioDriver()` is supported by class/file docs and constructor use.
- Raw `[0x0057afd0,0x0057b011)` is a unique private source method. Best inferred name: `SoundManager::ReinitializeAudioDriverAndResumeMusic()`. It calls the exact reinitializer, then resumes the current stream track for source mode 1 or enters the compiler-folded mode-zero zone-music suffix. Rejected: scanner tail, Redbook helper, padding, independent shared-tail helper, and dead bytes.
- Raw `[0x0057b5f0,0x0057b62a)` is a unique private teardown method. Best inferred name: `SoundManager::ShutdownAudioDriver()`. It closes/zeros stream and driver, releases all Miles timers, and tail-calls `AIL_shutdown`. Rejected: destructor body, compiler cleanup, callback, and padding.
- The callback family is project-owned SoundManager.cpp glue, not Miles library source and not FileIO-owned source. The four File callbacks are file-static; the stream callback is a private static SoundManager member. Registration xrefs exist only in SoundManager setup/playback.
- The Miles 6.x header ABI resolves callback types: open returns 32-bit unsigned success and writes a 32-bit handle; close returns void; seek returns signed 32-bit; read returns unsigned 32-bit; stream completion returns void and accepts `HSTREAM`. IDA lacks `U32` and `S32` aliases, so Gate 2B applied equivalent primitive declarations while source C++ retains Miles header spellings.
- `0x0057b630` is `AILFileOpenCallback`: ANSI input is converted to the wide project string, DAT is preferred, loose filesystem is fallback, the selected `File` implementation is opened, and its pointer is returned as a 32-bit Miles handle. The apparent null-allocation dereference is compiler lowering under throwing `new`, not a source null branch to preserve.
- `0x0057b730` is `AILFileCloseCallback`: source `delete file` explains the null test and virtual scalar-delete dispatch; IDA's current `int` return is a decompiler artifact contradicted by the SDK void callback.
- `0x0057b750` is `AILFileSeekCallback`: the switch maps Miles origin 0/1/2 to the numerically identical CRT origin values, preserves unknown values, ignores `File::Seek`'s boolean result, and returns `GetPosition()`.
- `0x0057b7a0` is `AILFileReadCallback`: it computes signed size-position then performs an unsigned clamp comparison, ignores the actual `Read` return, and reports the clamped requested count. Short reads are therefore still reported as requested; draft source preserves that weakness.
- `0x0057b7f0` is `SoundManager::AILStreamEndCallback`, not a singleton helper. Its machine ABI is still the Miles `void __stdcall(HSTREAM)` callback ABI: there is no `this` parameter, the argument is ignored, and the body posts message `0x407` for stream-source completion or independently `0x408` for an active mode-zero zone playlist. A C++ static member preserves that ABI while legally accessing private `m_zonePlaylistActive` through `g_pSoundManager`.
- Source-legality alternatives were explicitly tested. A public field is rejected because the current class keeps `m_zonePlaylistActive` private and no binary/source evidence supports widening visibility. A new public/private accessor is rejected because no accessor function or call exists; an inline accessor could reproduce bytes but would invent an API used only by this callback. A friend free function is mechanically possible, as the project has same-translation-unit friend callback precedents, but an external friend would change the current internal-linkage design and an internal-linkage friend requires a prior same-TU declaration before the header-defined class, complicating the established generated H/CPP split. A private static member is the narrowest legal source shape: it keeps the callback non-instance ABI, grants private access without visibility pollution, remains naturally registerable from `SoundManager` methods, and matches a common mid-2000s C++ callback integration pattern.
- Evidence for the selected shape is convergent rather than cosmetic: the sole address xref to `0x0057b7f0` is registration at `0x0057a065` inside the SoundManager playback method at `0x00579e30`; the callback reads `g_pSoundManager+0x10a9`; the current `SoundManager` UDT identifies `+0x10a9` as private `bool m_zonePlaylistActive`; and the body contains no accessor call and no `this` load. Evidence against certainty is limited to the stripped original declaration spelling and the possibility of a more awkward friend arrangement, so confidence remains below 95.
- `SoundManager::ReinitializeAudioDriver` uses the source `AIL_startup()` call. Live `0x004142a0` is the Miles/header shutdown-at-exit lowering that registers `AIL_shutdown`; it must not become a fabricated NexusTK helper body.
- `g_pConfig+0x291914` is the registry-backed `SoundFreq`/output-selection value. Best source field spelling here is `m_soundFrequency`; value 1 selects 22050 Hz and other values select 44100 Hz. Exact historical spelling is unrecoverable, but a human source name is mandatory and this inference is consistent with registry/UI consumers.
- Source style uses existing `m_` members, `g_p` globals, PascalCase methods, four file-static file-callback names, and one private static SoundManager stream callback. Raw `sub_`, `dword_`, `a1`, and offset labels are rejected from final source.
- Remaining uncertainty is limited to exact original helper spelling, the private-static versus less-likely friend declaration choice, and whether the SDK macro exposed the shutdown-at-exit wrapper. It does not affect behavior, ranges, or draft eligibility and caps confidence below 95.

## Evidence Standards Used
- Direct evidence: current MCP `lookup_funcs`, `inspect_items`, `get_comments`, `xref_query`, `find_bytes`, `get_bytes`, bounded `insn_query`, `analyze_function`, and `type_inspect`.
- Structural evidence: exact function sizes, raw instruction heads, all-`0xcc` gaps, registration-site data xrefs, two direct reinitializer code xrefs, shared-tail incoming edge, and generated empty-marker state.
- Type evidence: current `SoundManager` size `0x10ac`, exact field offsets/types including private bool `m_zonePlaylistActive` at `+0x10a9`, `File`/`DATFile`/`StdioFile` layouts, `HSTREAM` availability, and primary Miles SDK callback declarations.
- Negative evidence: zero IDA xrefs and zero VA/RVA byte patterns for both raw starts; no proposed-name collisions; no callback consumers outside SoundManager registration/playback.
- Confidence remains below final-audit level only for the stripped original declaration form/spellings and local names, not for runtime behavior or the requirement that the final C++ be access-legal.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks: all functions/raw bodies/padding from `0x0057afd0` through `0x0057b860`, exact comments and item boundaries, current types, xrefs, proposed-name collisions, caller behavior, Miles startup shim, Application HWND getter, and main WndProc dispatch.
- Documentation: all target/support pages named above, current class/file formals, by-structure, by-item declaration-emitter guidance and UID0000VF declaration-only precedent, ignored ranges, manual coverage, generated source, generated research tracker, current reports, and old SoundManager research as non-authoritative leads.
- Negative checks: `find_bytes` found zero `D0 AF 57 00`, `D0 AF 17 00`, `F0 B5 57 00`, or `F0 B5 17 00` occurrences; `xref_query` found zero incoming refs to both raw starts and every padding head; collision lookups found no proposed function names.
- Failed/unavailable/skipped checks: none material. Initial research was paused twice for supervisor IDB recovery/repair, historically resumed at `CB62`, and the prior repair was bounded at historical `9DF4`. This repair re-read every target action/no-change/protected item separately against stable `7509`; B002 remained read-only throughout. The supervisor later completed Gate 2B under catalog entry `0312`, rejected the immediate analysis-pending state, and obtained healthy reopened-session readback from `5f18a105`. After initial Gate 1 acceptance, B002 ran the historical serial scoped ordinary-document validators recorded below. No validator, IDA mutation, manual-coverage, or lifecycle command was run by B002 during this reconciliation.

## Claim And Incorporation Ledger
| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C1IC-001 | 0001IC | Narrow UID0001IC to exact `[0x0057b490,0x0057b5f0)` reinitializer page. | very strong | function size, broad-index duplication, structure rules | renamed target, status/history | rename/range repair | implemented/verified: old path absent; UID preserved |
| C1IC-002 | 0001IC | Route exact method through class UID0000DG at position 500. | very strong | member ABI, class declaration, source order | target metadata | owner/emitter/position | implemented/verified: owner/emitter 0000DG, position 500 |
| C1IC-003 | 0001IC | Raise target to `93/94` and install exact formal body. | strong | complete behavior and source inference | target metadata/formal | score/C++ | implemented/verified by command 000000017427 and generated readback |
| C1IC-004 | 0001IC | Preserve shutdown/startup order, cwd/redist setup, sample-rate branch, driver fallback, HWND call, callback registration, slot clear/allocation. | very strong | live decompile/bytes | target behavior/C++ | incorporate fully | implemented/verified in target prose/formal |
| C1IC-005 | 0001IC | Historicalize old aggregate, timeout, callback-type, singleton-helper, and inclusive-end assumptions. | very strong | current contradictions | target history | preserve/correct | implemented/verified; old evidence retained as superseded history |
| C1IC-006 | 0001IC | Create exact raw predecessor child `[0x0057afd0,0x0057b011)` as retained private method. | strong | 21 live instructions, shared tail, zero route | UID0004X1/class/file | create/emit | implemented/verified at position 390 |
| C1IC-007 | 0001IC | Create exact shutdown child `[0x0057b5f0,0x0057b62a)`. | strong | 17 live instructions, unique teardown | UID0004WW/class/file | create/emit | implemented/verified at position 510 |
| C1IC-008 | 0001IC | Move UID0000TU to exact open-callback by-memory page and formal. | very strong | size, registration xref, body, SDK ABI | moved UID0000TU | rename/move/emit | implemented/verified; old by-item path absent; canonical owner UID0000NV and insertion emitter UID0000DG preserve position 520 |
| C1IC-009 | 0001IC | Create exact close callback `[0x0057b730,0x0057b74a)`. | very strong | body, registration xref, SDK void ABI | UID0004WX/file | create/emit | implemented/verified at position 530; canonical owner UID0000NV, insertion emitter UID0000DG |
| C1IC-010 | 0001IC | Create exact seek callback `[0x0057b750,0x0057b793)`. | very strong | body, registration xref, File slots | UID0004WY/file | create/emit | implemented/verified at position 540; canonical owner UID0000NV, insertion emitter UID0000DG |
| C1IC-011 | 0001IC | Create exact read callback `[0x0057b7a0,0x0057b7e8)`, preserving short-read reporting weakness. | very strong | body, unsigned compare, File slots | UID0004WZ/file | create/emit | implemented/verified at position 550; canonical owner UID0000NV, insertion emitter UID0000DG |
| C1IC-012 | 0001IC | Cover exact stream completion callback `[0x0057b7f0,0x0057b853)` as private static `SoundManager::AILStreamEndCallback`, preserving Miles no-this ABI and legal private-field access. | very strong | sole registration xref, SDK ABI, direct `g_pSoundManager+0x10a9` load, message dispatch, current private UDT member | UID0004X0/class route | correct owner/formal | implemented/verified: owner/emitter UID0000DG, qualified definition, unchanged 92/93/range/body/blank H |
| C1IC-013 | 0001IC | Keep the complete UID0000DG declaration and `[[CHILDREN]]` in H with CPP blank; retain private resume/shutdown declarations and add the private static stream callback declaration. | strong | current formal, thiscall raw bodies, direct private-field callback use, source-access alternatives | by-class/SoundManager.md complete formal | declaration repair | implemented/verified: complete 92/94 H preserved, one private static declaration, CPP blank |
| C1IC-014 | 0001IC | Keep `by-item/SoundManagerMilesCallbackDeclarations.md` at position 15 with the SoundManager header include and exactly four file-static Miles file-callback prototypes; remove the stream callback prototype because its declaration belongs privately to UID0000DG. | very strong | callback ABI, earlier uses, generated source ordering, C++ access/linkage rules | UID0004WV plus by-file source-order prose | declaration/no-duplicate repair | implemented/verified: exactly four free prototypes, blank H, owner UID0000NV/emitter UID0000DG |
| C1IC-015 | 0001IC | Add six target-internal padding spans plus raw predecessor boundary gaps to ignored evidence. | very strong | exact items/bytes/xrefs | by-memory/-ignored.md | supervisor-approved ordinary support edit | implemented/verified by command 000000017422 |
| C1IC-016 | 0001IC | Preserve UID0001I8 as sole broad physical index; do not create another aggregate emitter. | very strong | current aggregate policy | UID0001I8 | support sync/no duplicate | implemented/verified; remains 88/91 non-emitting |
| C1IC-017 | 0001IC | Preserve all `[0x0057b860,0x0057bf6e)` exact child/compiler decisions. | very strong | current exact pages | UID0001ID and children | verify/no churn | verified/no change to exact child/compiler dispositions |
| C1IC-018 | 0001IC | Correct `0x0057b7f0` from singleton helper to stream-end callback everywhere. | very strong | body/xref/dispatch | target/class/file/aggregate | prose correction | implemented/verified across accepted ordinary destinations |
| C1IC-019 | 0001IC | Record SDK ABI and current IDA alias absence without importing raw labels into source. | very strong | Miles header/current type catalog | target/support docs | type evidence | implemented/verified; source uses Miles ABI spellings |
| C1IC-020 | 0001IC | Apply exact 7509-rebased IDA function creation/rename/type/comment actions after Gate 2A, including static-member semantic naming for `0x0057b7f0`. | strong | literal prestate/action table plus catalog entry `0312` and reopened live readback | supervisor Gate 2B | apply/read back | `APPLIED_VERIFIED`: two raw functions created, seven names/types/repeatable comments exact, saved as `DCB050F3...2281` |
| C1IC-021 | 0001IC | Protect every padding item, dependency item, and current exact reinitializer state. | very strong | 7509 prestate plus catalog `0312` protected readback | supervisor Gate 2B | verify recommended no-change state | `APPLIED_VERIFIED`: bytes, eight padding items, protected globals/functions/types, registration edge, xrefs, and eight operand-comment pairs unchanged |
| C1IC-022 | 0001IC | Replace manual UID0001IC/UID0000TU/UID0000DG/UID0000NV rows and insert the new declaration item, body-child, and padding rows with validator-assigned UIDs. | strong | current manual rows and absent declaration row | coverage reports | supervisor-only | supervisor pending |
| C1IC-023 | 0001IC | Keep both target empty markers removed and one body per exact page; correct generated SoundManager.h to contain the private static stream declaration and SoundManager.cpp to contain four free prototypes plus one qualified static-member definition, preserving source order and eliminating illegal private access. | strong | current command17510 generated readback; historical command17464 focused-callback proof; separate-channel rules, exact source order, C++ access control | generated SoundManager.cpp and SoundManager.h | focused validator consequence/source-legality verification | implemented/verified: one each UID0004WV/0004X1/0001IC/0004WW/0000TU/0004WX/0004WY/0004WZ/0004X0; four free prototypes at CPP lines 16-19; one private static declaration; one qualified stream definition; callback definitions at 759/779/785/802/815; zero UID0001IC/UID0000TU/UID0004X0 empty markers |

## Positive Evidence Summary
- UID0001IC begins at a modeled `0x160` SoundManager method with two direct code xrefs and an existing class declaration.
- Four file callbacks have exact registration data xrefs from `AIL_set_file_callbacks`; the stream callback has an exact `AIL_register_stream_callback` data xref.
- Raw shutdown and resume bodies have coherent `this`-relative SoundManager state, complete returns/tail behavior, exact padding boundaries, and no overlap with neighboring functions.
- Current SoundManager/File/DATFile/StdioFile types and Miles ABI converge on source-ready signatures.
- Broad UID0001I8 already solves physical inventory, making exact UID0001IC narrowing structurally lossless.
- UID0000DG provided the complete declaration without source invention, and the callback migrated it intact to H. UID0000VF established declaration-emitter precedent; generated readback then established that UID0004WV must use UID0000DG as insertion emitter at position `15` to appear before constructor position `20`.

## IDA MCP Facts
- Current authority: saved-IDB SHA256 `DCB050F31EB99C9A6037DB8E29573B8A8C4737520317C4364814F3ECCB432281`, 143,186,002 bytes, last write `2026-07-25T05:18:07.2105424-04:00`; reopened session `5f18a105` returned `status:ok`, `auto_analysis_ready:true`, and Hex-Rays ready. Pre-Gate-2B saved SHA256 `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331` and historical `9DF4` remain bounded prestate/continuity evidence only.
- Function/range facts after Gate 2B: `0x57afd0` is exact function size `0x41`; `0x57b490` size `0x160`; `0x57b5f0` exact function size `0x3a`; `0x57b630` size `0xfb`; `0x57b730` size `0x1a`; `0x57b750` size `0x43`; `0x57b7a0` size `0x48`; `0x57b7f0` size `0x63`.
- Data/table/padding facts: six internal gaps are exact all-`0xcc` data items of 6, 5, 6, 13, 8, and 13 bytes. Raw predecessor boundary gaps are 2 and 15 `0xcc` bytes.
- Xref facts: reinitializer xrefs from constructor `0x579b42` and raw predecessor `0x57afd3`; callback xrefs from `0x57b596/591/58c/587`; stream callback xref from `0x57a065`; raw starts and padding heads have zero xrefs.
- Vtable/global/type facts: `SoundManager` is `0x10ac`, with `HDIGDRIVER +0x8`, `HSTREAM +0x14`, eight `SoundSampleSlot` records at `+0x48`, and zone playlist active byte `+0x10a9`. `HSTREAM` exists; `U32` and `S32` aliases are absent.
- Negative IDA facts at pre-Gate-2B `7509`: all seven actionable function spellings were absent, while protected existing name `SoundManager__ReinitializeAudioDriver` remained attached at `0x57b490`; raw-start VA and RVA patterns `D0 AF 57 00`, `D0 AF 17 00`, `F0 B5 57 00`, and `F0 B5 17 00` each returned zero matches; there is no independent function at `0x509480`; no padding span is executable or referenced. Gate 2B changed only the accepted function objects/names/types/repeatable comments.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| source declaration | UID0000DG `by-class/SoundManager.md` | complete SoundManager declaration plus header children and private static stream callback | true | UID0000NV | 92/94 | complete H/blank CPP and private static callback declaration implemented/verified |
| source declaration | UID0004WV `by-item/SoundManagerMilesCallbackDeclarations.md` | SoundManager.cpp include and exactly four file-static Miles File callback prototypes; no free stream prototype | true | owner UID0000NV; insertion emitter UID0000DG | 93/94 | implemented/verified; current command17510 has the four free prototypes at CPP lines 16-19, UID0000DG H owns the private static stream declaration, and UID0004X0 owns the qualified definition; command17464 is historical focused-callback proof |
| `[0x0057afd0,0x0057b011)` | UID0004X1 `SoundManagerReinitializeAudioDriverAndResumeMusicRaw.md` | retained private method | true | UID0000DG | 90/91 | implemented |
| `[0x0057b490,0x0057b5f0)` | UID0001IC renamed target | `SoundManager::ReinitializeAudioDriver` | true | UID0000DG | 93/94 | narrow/emit |
| `[0x0057b5f0,0x0057b62a)` | UID0004WW `SoundManagerShutdownAudioDriverRaw.md` | retained private method | true | UID0000DG | 91/92 | implemented |
| `[0x0057b62a,0x0057b630)` | `by-memory/-ignored.md` | alignment | false | none | 100 | ignore |
| `[0x0057b630,0x0057b72b)` | UID0000TU moved to `AILFileOpenCallback.md` | file-static Miles open callback | true | UID0000NV | 93/94 | implemented |
| `[0x0057b72b,0x0057b730)` | ignored | alignment | false | none | 100 | ignore |
| `[0x0057b730,0x0057b74a)` | UID0004WX `AILFileCloseCallback.md` | file-static close callback | true | UID0000NV | 92/94 | implemented |
| `[0x0057b74a,0x0057b750)` | ignored | alignment | false | none | 100 | ignore |
| `[0x0057b750,0x0057b793)` | UID0004WY `AILFileSeekCallback.md` | file-static seek callback | true | UID0000NV | 93/94 | implemented |
| `[0x0057b793,0x0057b7a0)` | ignored | alignment | false | none | 100 | ignore |
| `[0x0057b7a0,0x0057b7e8)` | UID0004WZ `AILFileReadCallback.md` | file-static read callback | true | UID0000NV | 93/94 | implemented |
| `[0x0057b7e8,0x0057b7f0)` | ignored | alignment | false | none | 100 | ignore |
| `[0x0057b7f0,0x0057b853)` | UID0004X0 `AILStreamEndCallback.md` | private static SoundManager stream completion callback | true | UID0000DG | 92/93 | implemented: qualified member definition, no-this ABI, legal private access |
| `[0x0057b853,0x0057b860)` | ignored | alignment | false | none | 100 | ignore |
| `[0x0057b860,0x0057bf6e)` | existing UID0001ID/exact children | STL/StringBase/compiler island | per exact child | existing routes | unchanged | no duplicate |

- Historical command17440 emitted five free prototypes and an access-illegal free stream body. Historical focused-callback command17464 corrected that source shape. Current command17510 retains one each of UID0004WV/UID0004X1/UID0001IC/UID0004WW/UID0000TU/UID0004WX/UID0004WY/UID0004WZ/UID0004X0, exactly four free static prototypes at CPP lines `16-19`, callback definitions in accepted order at `759/779/785/802/815`, metadata positions `520/530/540/550/560`, and one qualified `SoundManager::AILStreamEndCallback`. UID0000DG emits one complete class in H with one private static stream declaration and one no-children placeholder. There is no free stream prototype and zero UID0001IC/UID0000TU/UID0004X0 empty markers; the two physical CPP empty markers belong only to unrelated UID0000DG/UID0001I7 rows.

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0057b490` | callers `0x00579b42`, `0x0057afd3` | constructor setup plus retained reinit/resume method |
| `0x0057b630` | data xref `0x0057b596` | AIL open callback argument |
| `0x0057b730` | data xref `0x0057b591` | AIL close callback argument |
| `0x0057b750` | data xref `0x0057b58c` | AIL seek callback argument |
| `0x0057b7a0` | data xref `0x0057b587` | AIL read callback argument |
| `0x0057b7f0` | data xref `0x0057a065` in `sub_579E30` | stream completion callback registration |
| `0x0057afd0` | zero incoming; calls `0x0057b490`, `0x00579e30`, or shared tail | retained private source body |
| `0x0057b5f0` | zero incoming; Miles teardown calls | retained private source body |
| `0x004142a0` | sole caller `0x0057b527` | Miles shutdown-at-exit/header lowering |
| `0x00465f20` cases `1031/1032` | calls next-track/playlist methods | proves `0x407/0x408` callback meaning |

## Documentation Evidence And IDA Status
- Supporting docs correctly place Miles/DAT/loose-file glue in SoundManager.cpp and type the class/sample slots.
- The callback corrected stale inclusive ends, current-label claims that drifted from the live IDB, unresolved ABI prose, broad-emitter routing, and the false singleton-helper role while preserving each superseded claim as history.
- Historical generated command17440 had zero UID0001IC/UID0000TU empty markers and one exact definition per body but remained access-illegal. Historical command17464 corrected source access through the private static declaration and qualified definition. Current command17510 retains those structural guarantees, zero UID0001IC/UID0000TU/UID0004X0 empty markers, and source-access legality; UID0001I8/compiler-helper bodies remain non-emitting, while the two physical CPP empty markers are unrelated UID0000DG/UID0001I7 rows.
- Supervisor Gate 2B catalog entry `0312` is `APPLIED_VERIFIED`. It created the two retained raw function objects, installed all seven accepted source-facing identities/types/repeatable comments, verified all no-change/protected rows, saved the IDB as `DCB050F3...2281`, and confirmed the result after a controlled reopen with `auto_analysis_ready:true`.

## Ranked Ownership Analysis

### 1. SoundManager class/file split
- Evidence for: member receivers/fields, constructor call, playback registration, global config/application dependencies, current source root, and callback-only xrefs. The stream callback alone directly reads private SoundManager state.
- Evidence against: all callbacks have no runtime `this`; the four file callbacks consume only generic File API. No stripped symbol proves the original stream declaration form.
- Decision: member methods and the private static stream callback belong to UID0000DG; the open/close/seek/read callbacks remain file-static under UID0000NV. A static member callback has no runtime `this`, so this ownership distinction changes source legality without changing the executable callback ABI.

### 2. FileIO
- Evidence for: callback bodies dispatch File/DATFile/StdioFile methods.
- Evidence against: FileIO never registers or calls them; their ABI and lifecycle exist only for Miles configured by SoundManager.
- Decision: dependency only, rejected as owner.

### 3. Miles third-party source or standalone callback module
- Evidence for: public ABI originates in Miles headers.
- Evidence against: DAT-first policy, project File classes, Config, Application HWND, and SoundManager state are NexusTK glue.
- Decision: rejected. No third-party import and no separate source module.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new translation unit. Exact children remain in `NexusTK/audio/SoundManager.cpp`.
- Likely full contents: two private SoundManager methods, four file-static File callbacks, and one private static SoundManager stream callback around the existing reinitializer.
- Candidate related items: raw predecessor and callback family.
- Rejected: later SoundPathVector/compiler helper island and shared tail as standalone source.
- Source-file inference: one existing SoundManager.cpp, with class methods, four file-static callbacks, and one private static member callback.

## Source Placement
- Recommended placement: ordinary member definitions and private static `SoundManager::AILStreamEndCallback` under class UID0000DG; open/close/seek/read callbacks remain canonically file-owned and file-static under UID0000NV while using UID0000DG only as their output insertion router.
- Corrected header/source split: UID0000DG position `10` emits the complete declaration only to `NexusTK/audio/SoundManager.h`; its CPP channel is blank and its private section declares the static stream callback. UID0004WV remains canonically file-owned and emits through UID0000DG at position `15`, placing `#include "SoundManager.h"` and four free static File-callback prototypes before constructor position `20` and every use. UID0000TU/UID0004WX/UID0004WY/UID0004WZ likewise retain canonical UID0000NV ownership and file-static definitions but insert through UID0000DG at positions `520-550`; class-owned UID0004X0 follows at `560`.
- Generator-routing correction: direct UID0000NV insertion was tried first. Generated hierarchy placed direct file children after the UID0000DG child subtree, so moving only UID0004X0 to class scope initially reordered stream before open/close/seek/read. Routing the declaration item and all four free callback bodies through UID0000DG preserves semantic file ownership, file-static linkage, declaration-before-use, and exact physical definition order. No File callback became a class member.
- No-duplicate policy: UID0000DG owns the sole class declaration including the private static callback declaration; UID0004WV owns only the include and four free prototypes; exact by-memory pages own the sole CPP definitions and keep H blank; insertion routing does not duplicate definitions; `by-file/SoundManager.md` remains a prose source root with no reconstruction formal.
- This matches direct xrefs, current file organization, adjacent SoundManager source order, and mid-2000s Miles integration style.
- Rejected placements: FileIO, client_audio metadata, third-party Miles source, SoundPathVector, generic utility, and independent callback translation unit.
- Remaining placement uncertainty: exact original static-member declaration order is inferred. The need for a compile-valid private-access mechanism and same-file SoundManager placement is not uncertain.

## Range / Split / Padding / Reclassification Analysis
- Exact half-open method/body boundaries are listed in the inventory. Assignment-time inclusive last-byte descriptions were corrected in every accepted ordinary destination.
- UID0001IC keeps its UID on the exact first function. UID0000TU keeps its UID while moving to exact by-memory coverage.
- Six target-internal and two predecessor-boundary gaps are all-`0xcc` data items with no comments, names, types, or xrefs.
- Broad UID0001I8 remains the sole physical cluster index. The old UID0001IC broad history moves into the narrowed page as explicitly historical split provenance.
- No source child crosses padding or absorbs the later path-vector/compiler island.

## Negative Evidence Summary
- Zero xrefs and zero pointer patterns were checked for both raw starts; these cap inferred name/liveness confidence but do not outweigh complete unique source-shaped bodies.
- The stream callback does not return the singleton semantically; decompiler return artifacts arise from stale `_DWORD*` typing.
- Generic File usage does not prove FileIO ownership because all callback addresses are registered only by SoundManager.
- Physical adjacency to Redbook and SoundPathVector does not merge source ownership.
- `0x00509480` is a compiler-folded shared suffix, not a callable helper to emit.
- The callback IDA labels described as saved in June were absent at historical `CB62` and `9DF4` and remain absent at current `7509`; those statements are history, not current prestates.
- A free file-static callback accessing `g_pSoundManager->m_zonePlaylistActive` is negative source evidence, not a harmless draft detail: the emitted field is private. Publicizing the field or inventing an accessor would hide rather than solve that contradiction.

## IDA Rename / Type / Comment Recommendations

Historical Gate 2B prestate basis: database `supervisor_current_20260724_9f6e`, saved IDB SHA256 `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331`, 143,186,450 bytes, saved `2026-07-24T22:54:09.6318603-04:00`. B002 re-read every row item by item and remained read-only. Historical `CB62D69DD6833431565994032CA0F8229ED7762773A223E2F1CDA93AC9047C2E` and `9DF44486A6C1DC34A55BDE2EB8E517916E0B073D46712BC7C1B9B1D3ECB9EB4C` are not current prestates. The table preserves the exact accepted prestate/action/readback contract; catalog entry `0312` has now closed every row.

| Entity | Accepted pre-state at 7509 | Gate 2B action/disposition | Safety/collision evidence | Applied/verified readback |
| --- | --- | --- | --- | --- |
| Function `[0x0057b490,0x0057b5f0)` | name `SoundManager__ReinitializeAudioDriver`; type `void __thiscall(SoundManager *this)`; first bytes `55 8b ec 6a ff 68 34 85 60 00 64 a1 00 00 00 00`; entry regular absent; entry repeatable absent; function regular exact `SoundManager::ReinitializeAudioDriver source method. Rebuilds the Miles digital/audio-driver state and updates dependent handles while preserving observed cleanup order.`; function repeatable absent; two xrefs (`0x579b42`, `0x57afd3`). | `NO_CHANGE_RECOMMENDED`; `APPLIED_VERIFIED` by supervisor readback. | Exact function boundary; existing semantic name/type; no competing collision. | Same range, name, type, bytes, two xrefs, entry regular absent, entry repeatable absent, function regular exact, and function repeatable absent. |
| Raw code `[0x0057afd0,0x0057b011)` | no function object; start item head `0x57afd0`, size 1, code, name absent, type absent; entry regular absent; entry repeatable absent; because no function object exists, function regular and function repeatable channels are unavailable; 65 exact bytes begin `56 8b f1 e8 b8 04 00 00`; zero xrefs and zero VA/RVA patterns. | `APPLIED_VERIFIED`: created exact function, renamed `SoundManager__ReinitializeAudioDriverAndResumeMusic`, applied `void __thiscall SoundManager__ReinitializeAudioDriverAndResumeMusic(SoundManager *this)`, and applied the exact repeatable function comment; entry regular/repeatable and function regular remain absent. | Preceded by `[0x57afce,0x57afd0)` CC data; followed by `[0x57b011,0x57b020)` CC data; preferred name absent. Do not absorb shared tail `0x509480`. | Exact function `[0x57afd0,0x57b011)`, name/type/function-repeatable comment as specified, same bytes/control targets, zero xrefs, entry regular absent, entry repeatable absent, and function regular absent. |
| Raw code `[0x0057b5f0,0x0057b62a)` | no function object; start item head `0x57b5f0`, size 1, code, name absent, type absent; entry regular absent; entry repeatable absent; function comment channels unavailable; exact 58 bytes `56 8b f1 8b 46 14 85 c0 74 0e 50 ff 15 38 d6 60 00 c7 46 14 00 00 00 00 8b 46 08 85 c0 74 0e 50 ff 15 d4 d5 60 00 c7 46 08 00 00 00 00 ff 15 dc d5 60 00 5e ff 25 e8 d5 60 00`; zero xrefs and zero VA/RVA patterns. | `APPLIED_VERIFIED`: created exact function, renamed `SoundManager__ShutdownAudioDriver`, applied `void __thiscall SoundManager__ShutdownAudioDriver(SoundManager *this)`, and applied the exact repeatable function comment; entry regular/repeatable and function regular remain absent. | Ends exactly before six CC bytes; preferred name absent; tail jump remains inside exact range. | Exact function/range/name/type/function-repeatable comment, unchanged 17 instructions/import targets, zero xrefs, entry regular absent, entry repeatable absent, and function regular absent. |
| Function `[0x0057b630,0x0057b72b)` | name `sub_57B630`; type `int __stdcall(const char *Src, int **)`; first bytes `55 8b ec 6a ff 68 75 85 60 00 64 a1 00 00 00 00`; entry regular absent; entry repeatable absent; function regular absent; function repeatable absent; one data xref `0x57b596`. | `APPLIED_VERIFIED`: renamed `AILFileOpenCallback`, applied `unsigned int __stdcall AILFileOpenCallback(const char *filename, unsigned int *fileHandle)`, and applied the exact repeatable function comment; entry regular/repeatable and function regular remain absent. | Name absent; exact function and successor padding; primitive types avoid absent U32 alias. | Exact range/name/type/function-repeatable comment, same body and sole registration xref, entry regular absent, entry repeatable absent, and function regular absent. |
| Function `[0x0057b730,0x0057b74a)` | name `sub_57B730`; type `int __stdcall(int (__thiscall ***)(_DWORD, int))`; first bytes `55 8b ec 8b 4d 08 85 c9 74 0c 8b 01 c7 45 08 01`; entry regular absent; entry repeatable absent; function regular absent; function repeatable absent; one data xref `0x57b591`. | `APPLIED_VERIFIED`: renamed `AILFileCloseCallback`, applied `void __stdcall AILFileCloseCallback(unsigned int fileHandle)`, and applied the exact repeatable function comment; entry regular/repeatable and function regular remain absent. | SDK void ABI overrides stale decompiler return; name absent; exact padding. | Exact name/void type/function-repeatable comment, same null test/deleting dispatch/xref, entry regular absent, entry repeatable absent, and function regular absent. |
| Function `[0x0057b750,0x0057b793)` | name `sub_57B750`; type `int __stdcall(int, int, int)`; first bytes `55 8b ec 8b 45 10 83 e8 00 74 1b 83 e8 01 74 0f`; entry regular absent; entry repeatable absent; function regular absent; function repeatable absent; one data xref `0x57b58c`. | `APPLIED_VERIFIED`: renamed `AILFileSeekCallback`, applied `int __stdcall AILFileSeekCallback(unsigned int fileHandle, int offset, unsigned int origin)`, and applied the exact repeatable function comment; entry regular/repeatable and function regular remain absent. | Name absent; SDK signed return and 32-bit handle; exact padding. | Exact range/name/type/function-repeatable comment, same switch/virtual calls/xref, entry regular absent, entry repeatable absent, and function regular absent. |
| Function `[0x0057b7a0,0x0057b7e8)` | name `sub_57B7A0`; type `unsigned int __stdcall(int, int, unsigned int)`; first bytes `55 8b ec 53 56 57 8b 7d 08 8b cf 8b 07 ff 50 1c`; entry regular absent; entry repeatable absent; function regular absent; function repeatable absent; one data xref `0x57b587`. | `APPLIED_VERIFIED`: renamed `AILFileReadCallback`, applied `unsigned int __stdcall AILFileReadCallback(unsigned int fileHandle, void *buffer, unsigned int bytes)`, and applied the exact repeatable function comment; entry regular/repeatable and function regular remain absent. | Name absent; exact SDK ABI and boundary. | Exact range/name/type/function-repeatable comment, same unsigned clamp/virtual calls/xref, entry regular absent, entry repeatable absent, and function regular absent. |
| Function `[0x0057b7f0,0x0057b853)` | name `sub_57B7F0`; type `_DWORD *__stdcall(int)`; start item `[0x57b7f0,0x57b7f5)`, size 5; first bytes `a1 c8 a7 67 00 83 b8 08 19 29 00 01 75 20 8b 0d`; entry regular absent; entry repeatable absent; function regular absent; function repeatable absent; one data xref `0x57a065` in `sub_579E30`; eight instruction regular comments are exact: `0x57b804 lParam`, `0x57b806 wParam`, `0x57b808 Msg`, `0x57b812 hWnd`, `0x57b83b lParam`, `0x57b83d wParam`, `0x57b83f Msg`, `0x57b849 hWnd`; each repeatable comment is absent. | `APPLIED_VERIFIED`: renamed `SoundManager__AILStreamEndCallback`, applied `void __stdcall SoundManager__AILStreamEndCallback(HSTREAM stream)`, and applied the exact repeatable function comment; entry regular/repeatable and function regular remain absent; all eight instruction regular comments and absent repeatable comments were preserved. | `HSTREAM` exists as a 4-byte pointer; SDK return/calling convention exact; preferred `SoundManager__AILStreamEndCallback` and old free spelling are both collision-free; exact preceding/following padding; sole registration is inside SoundManager playback. | Exact range/start item, static-member semantic name, void type, repeatable comment, same 0x407/0x408 control flow and one xref, entry regular absent, entry repeatable absent, function regular absent, and all eight instruction comment pairs unchanged. |
| Padding `[0x0057afce,0x0057afd0)` | one 2-byte data item, no name/type, bytes `cc cc`, regular absent, repeatable absent, zero xrefs. | `NO_CHANGE_RECOMMENDED`; `APPLIED_VERIFIED` in catalog entry `0312`. | Separates scanner from raw support method. | Same item/range/bytes/name/type/xrefs, regular absent, repeatable absent. |
| Padding `[0x0057b011,0x0057b020)` | one 15-byte data item, no name/type, fifteen `cc`, regular absent, repeatable absent, zero xrefs. | `NO_CHANGE_RECOMMENDED`; `APPLIED_VERIFIED` in catalog entry `0312`. | Separates raw support method from Redbook child. | Same item/range/bytes/name/type/xrefs, regular absent, repeatable absent. |
| Padding `[0x0057b62a,0x0057b630)` | one 6-byte data item, no name/type, six `cc`, regular absent, repeatable absent, zero xrefs. | `NO_CHANGE_RECOMMENDED`; `APPLIED_VERIFIED` in catalog entry `0312`. | Exact shutdown/open boundary. | Same item/range/bytes/name/type/xrefs, regular absent, repeatable absent. |
| Padding `[0x0057b72b,0x0057b730)` | one 5-byte data item, no name/type, five `cc`, regular absent, repeatable absent, zero xrefs. | `NO_CHANGE_RECOMMENDED`; `APPLIED_VERIFIED` in catalog entry `0312`. | Exact open/close boundary. | Same item/range/bytes/name/type/xrefs, regular absent, repeatable absent. |
| Padding `[0x0057b74a,0x0057b750)` | one 6-byte data item, no name/type, six `cc`, regular absent, repeatable absent, zero xrefs. | `NO_CHANGE_RECOMMENDED`; `APPLIED_VERIFIED` in catalog entry `0312`. | Exact close/seek boundary. | Same item/range/bytes/name/type/xrefs, regular absent, repeatable absent. |
| Padding `[0x0057b793,0x0057b7a0)` | one 13-byte data item, no name/type, thirteen `cc`, regular absent, repeatable absent, zero xrefs. | `NO_CHANGE_RECOMMENDED`; `APPLIED_VERIFIED` in catalog entry `0312`. | Exact seek/read boundary. | Same item/range/bytes/name/type/xrefs, regular absent, repeatable absent. |
| Padding `[0x0057b7e8,0x0057b7f0)` | one 8-byte data item, no name/type, eight `cc`, regular absent, repeatable absent, zero xrefs. | `NO_CHANGE_RECOMMENDED`; `APPLIED_VERIFIED` in catalog entry `0312`. | Exact read/stream-callback boundary. | Same item/range/bytes/name/type/xrefs, regular absent, repeatable absent. |
| Padding `[0x0057b853,0x0057b860)` | one 13-byte data item, no name/type, thirteen `cc`, regular absent, repeatable absent, zero xrefs. | `NO_CHANGE_RECOMMENDED`; `APPLIED_VERIFIED` in catalog entry `0312`. | Exact callback/SoundPathVector boundary. | Same item/range/bytes/name/type/xrefs, regular absent, repeatable absent. |

Protected dependencies were also re-read item by item at `7509`; they are not implicit exemptions. Their literal states remained continuous from historical `9DF4`:

| Protected entity | Literal 7509 pre-state | Disposition and safety | Expected unchanged readback |
| --- | --- | --- | --- |
| `0x0067a7c8` | one 4-byte data item, value bytes `00 00 00 00`, name `g_pConfig`, type `Config *`, regular comment exact `Config *g_pConfig. SaveUserSettings directly serializes inherited Config profile/user-data fields from this runtime RegistryConfig object.\nActive Config/RegistryConfig singleton pointer (source-facing g_pConfig).\nConfig singleton. Relevant server-option bytes are exact at +0x28de48, +0x28de60/+61, and +0x28de6e..+75.`, repeatable absent, 433 xrefs. | `NO_CHANGE_RECOMMENDED`; broad shared semantic global, no target-specific correction or collision. | Same head/range/width/value/name/type, exact regular comment, repeatable absent, and 433 xrefs. |
| `0x0067a7d0` | one 4-byte data item, value bytes `00 00 00 00`, name `g_pSoundManager`, type `SoundManager *`, regular comment exact `SoundManager singleton. Byte +5 mirrors requested sound-effects option; byte +0x41 is the distinct runtime playback gate.\nCanonical SoundManager singleton pointer. Source identity: SoundManager *g_pSoundManager; raw dword_67A7D0 is rejected.`, repeatable absent, 117 xrefs. | `NO_CHANGE_RECOMMENDED`; current name/type already support the selected static-member callback and private-field evidence. | Same head/range/width/value/name/type, exact regular comment, repeatable absent, and 117 xrefs. |
| `0x0067ab1c` | one 4-byte data item, value bytes `00 00 00 00`, name `dword_67AB1C`, type `LObject *`, regular absent, repeatable absent, 140 xrefs. | `NO_CHANGE_RECOMMENDED`; this report uses documentary `g_pApplication` source spelling but does not own the broad Application global/type correction. | Same head/range/width/value/name/type/comments and 140 xrefs. |
| Function `[0x004651d0,0x004651d7)` | name `sub_4651D0`, size `0x7`, type `int __thiscall(_DWORD *this)`, bytes `8b 81 28 08 00 00 c3`; entry regular/repeatable absent; function regular/repeatable absent; 78 xrefs. | `NO_CHANGE_RECOMMENDED`; seven-byte Application HWND getter is a dependency owned by its broader Application work, and no boundary/collision change is needed here. | Same function/range/name/type/bytes, all four comment channels absent, and 78 xrefs. |
| Function `[0x00579e30,0x0057a0a5)` | name `sub_579E30`, size `0x275`, type `void __thiscall(int this, int, int, int)`, first bytes `55 8b ec 6a ff 68 b3 83 60 00 64 a1 00 00 00 00`; entry regular/repeatable absent; function regular/repeatable absent; 15 incoming xrefs; callback registration operand at `0x57a065` targets `0x57b7f0`. | `NO_CHANGE_RECOMMENDED`; broader playback-method naming/types are outside this report, while the exact registration edge is protected. | Same range/name/type/first bytes, all four comment channels absent, 15 incoming xrefs, and registration target `0x57b7f0`. |
| `SoundManager` UDT | type exists, natural size `0x10ac`; member `m_zonePlaylistActive` is `bool`, offset `0x10a9`, size 1. | `NO_CHANGE_RECOMMENDED`; do not widen the member's access or alter layout to mask source illegality. | Same UDT size and exact member name/type/offset/width. |
| `HSTREAM`, `U32`, `S32` | `HSTREAM` exists as a 4-byte pointer type; `U32` and `S32` are absent from the IDA type catalog. | `NO_CHANGE_RECOMMENDED`; `APPLIED_VERIFIED`; Gate 2B used primitive equivalents in IDA while source formals retain Miles header spellings. | `HSTREAM` still size 4; `U32`/`S32` still absent. |

### Gate 2B Applied Verification - Catalog 0312

- State: `APPLIED_VERIFIED` for C1IC-020 and C1IC-021. The supervisor used backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-0001IC-20260725_051650.bak`, SHA256 `3B7FC953A07344D07F33CD8C244853E0CD8DBFF8AB80C4DE2839D14A9800B63C`, 143,186,450 bytes, and saved the accepted result as SHA256 `DCB050F31EB99C9A6037DB8E29573B8A8C4737520317C4364814F3ECCB432281`, 143,186,002 bytes, last write `2026-07-25T05:18:07.2105424-04:00`.
- Exact raw-function creation: `[0x0057afd0,0x0057b011)` is now `SoundManager__ReinitializeAudioDriverAndResumeMusic`, size `0x41`, type `void __thiscall SoundManager__ReinitializeAudioDriverAndResumeMusic(SoundManager *this)`, repeatable function comment `Retained private SoundManager::ReinitializeAudioDriverAndResumeMusic source method. Rebuilds the Miles driver, then resumes the current stream track in source mode 1 or reaches the shared zone-music tail in source mode 0; no current entry route is known.`; `[0x0057b5f0,0x0057b62a)` is now `SoundManager__ShutdownAudioDriver`, size `0x3a`, type `void __thiscall SoundManager__ShutdownAudioDriver(SoundManager *this)`, repeatable function comment `Retained private SoundManager::ShutdownAudioDriver source method. Closes and clears m_stream and m_digitalDriver, releases all Miles timers, and tail-calls AIL_shutdown; no current entry route is known.` Both retain entry regular/repeatable and function regular channels absent, exact original bytes/control targets, and zero xrefs.
- Exact modeled-callback identities: `[0x0057b630,0x0057b72b)` is `AILFileOpenCallback`, size `0xfb`, type `unsigned int __stdcall AILFileOpenCallback(const char *filename, unsigned int *fileHandle)`, repeatable function comment `Miles file-open callback used by SoundManager. Converts the ANSI path, prefers DATFile when HasDATEntry succeeds, falls back to StdioFile for an existing loose path, opens the File, and returns its pointer as the 32-bit Miles handle.`; `[0x0057b730,0x0057b74a)` is `AILFileCloseCallback`, size `0x1a`, type `void __stdcall AILFileCloseCallback(unsigned int fileHandle)`, repeatable function comment `Miles file-close callback used by SoundManager. Treats the 32-bit handle as File* and deletes it when nonzero.`
- Remaining callback identities: `[0x0057b750,0x0057b793)` is `AILFileSeekCallback`, size `0x43`, type `int __stdcall AILFileSeekCallback(unsigned int fileHandle, int offset, unsigned int origin)`, repeatable function comment `Miles file-seek callback used by SoundManager. Maps origin 0/1/2 to File::Seek, preserves unknown values, ignores the seek result, and returns File::GetPosition().`; `[0x0057b7a0,0x0057b7e8)` is `AILFileReadCallback`, size `0x48`, type `unsigned int __stdcall AILFileReadCallback(unsigned int fileHandle, void *buffer, unsigned int bytes)`, repeatable function comment `Miles file-read callback used by SoundManager. Clamps bytes to File::GetSize()-GetPosition(), calls File::Read, ignores the actual read return, and reports the clamped request count.`
- Static-member callback identity: `[0x0057b7f0,0x0057b853)` is `SoundManager__AILStreamEndCallback`, size `0x63`, type `void __stdcall SoundManager__AILStreamEndCallback(HSTREAM stream)`, repeatable function comment `Private static SoundManager stream-completion callback. Ignores HSTREAM, posts 0x407 for stream-source completion, and posts 0x408 when mode-zero zone-playlist playback remains active through g_pSoundManager; static-member source shape preserves the no-this Miles ABI and legal private-state access.` All five callback entry regular/repeatable and function regular channels are absent. Open/close/seek/read/stream xrefs remain exactly one each at `0x57b596`, `0x57b591`, `0x57b58c`, `0x57b587`, and `0x57a065`.
- Existing reinitializer protection: `[0x0057b490,0x0057b5f0)` remains `SoundManager__ReinitializeAudioDriver`, size `0x160`, type `void __thiscall(SoundManager *this)`, with its exact regular function comment, function-repeatable absent, entry regular/repeatable absent, original first bytes, and two xrefs at `0x579b42` and `0x57afd3`.
- Exact padding protection: `[0x57afce,0x57afd0)` two bytes, `[0x57b011,0x57b020)` fifteen bytes, `[0x57b62a,0x57b630)` six bytes, `[0x57b72b,0x57b730)` five bytes, `[0x57b74a,0x57b750)` six bytes, `[0x57b793,0x57b7a0)` thirteen bytes, `[0x57b7e8,0x57b7f0)` eight bytes, and `[0x57b853,0x57b860)` thirteen bytes remain exact `0xcc` data items with absent names/types/regular/repeatable comments and zero xrefs. All target/raw/padding bytes are unchanged.
- Protected globals/functions/types: `g_pConfig` remains a four-byte `Config *` with exact existing regular comment, repeatable absent, and 433 xrefs; `g_pSoundManager` remains a four-byte `SoundManager *` with exact existing regular comment, repeatable absent, and 117 xrefs; `dword_67AB1C` remains a four-byte `LObject *` with both comments absent and 140 xrefs. `sub_4651D0` remains exact seven-byte `int __thiscall(_DWORD *this)` with all four comment channels absent and 78 xrefs; `sub_579E30` remains exact size `0x275`, type `void __thiscall(int this, int, int, int)`, all four comment channels absent, 15 incoming xrefs, and registration target `0x57b7f0`. `SoundManager` remains size `0x10ac` with one-byte `bool m_zonePlaylistActive` at `0x10a9`; `HSTREAM` remains four bytes; `U32` and `S32` remain absent.
- Operand-comment protection: regular comments remain exact at `0x57b804` `lParam`, `0x57b806` `wParam`, `0x57b808` `Msg`, `0x57b812` `hWnd`, `0x57b83b` `lParam`, `0x57b83d` `wParam`, `0x57b83f` `Msg`, and `0x57b849` `hWnd`; each paired repeatable comment remains absent.
- Persistence/health: the immediate post-definition save reported analysis pending and was not accepted. The controlled saved-IDB reopen produced session `5f18a105` with `status:ok`, `auto_analysis_ready:true`, Hex-Rays ready, and exact live lookup/comment readback for all seven applied actions and every protected state above.

Other dependencies outside this report remain protected/no-action: `0x004142a0` Miles shutdown-at-exit shim, `0x00465f20` dispatch, `g_activeMapPane`, File/DATFile/StdioFile UDTs, imports, shared tail UID0004QX, and later helper functions. Catalog entry `0312` verified the report-owned no-change rows; these additional dependencies remain intentionally untouched.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes for UID0001IC and every exact source child; no for aggregate UID0001I8, ignored padding, shared compiler tail, or later compiler/STL children.
- Target CPP block disposition: the callback applied this complete destination-ready block after the UID-preserving rename:

```text
*** UID:0001IC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000DG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000DG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:500 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SoundManager::ReinitializeAudioDriver()
{
    if (m_stream != NULL) {
        AIL_close_stream(m_stream);
        m_stream = NULL;
    }

    if (m_digitalDriver != NULL) {
        AIL_close_digital_driver(m_digitalDriver);
        m_digitalDriver = NULL;
    }

    AIL_release_all_timers();
    AIL_shutdown();

    char *currentDirectory = _getcwd(NULL, 256);
    SoundPathString milesDirectory(currentDirectory);
    free(currentDirectory);
    AIL_set_redist_directory(milesDirectory.c_str());

    AIL_startup();

    const int sampleRate = g_pConfig->m_soundFrequency == 1 ? 22050 : 44100;
    m_digitalDriver = AIL_open_digital_driver(sampleRate, 16, 2, 1);
    if (m_digitalDriver == NULL)
        m_digitalDriver = AIL_open_digital_driver(sampleRate, 16, 2, 0);

    AIL_set_DirectSound_HWND(m_digitalDriver,
                             g_pApplication->GetMainWindowHandle());

    if (m_digitalDriver != NULL) {
        AIL_set_file_callbacks(AILFileOpenCallback,
                               AILFileCloseCallback,
                               AILFileSeekCallback,
                               AILFileReadCallback);
        m_stream = NULL;
        memset(m_sampleSlots, 0, sizeof(m_sampleSlots));

        for (int slot = 0; slot < 8; ++slot)
            m_sampleSlots[slot].handle = AIL_allocate_sample_handle(m_digitalDriver);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
*** Item Summary: Exact SoundManager audio-driver reinitializer preserving Miles teardown/startup order, redistributable-directory setup, 44100/22050 selection, hardware/fallback driver open, DirectSound HWND binding, project file-callback registration, eight-slot reset/allocation, exact callers/boundaries, and source-era draft C++. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Target H block disposition: UID0001IC and every exact body page keep H blank because definitions belong in CPP and UID0000DG owns the sole class declaration. The corrected complete UID0000DG replacement formal below preserves every current declaration, the prior channel migration, and both private methods, and adds the private static Miles callback declaration required for compile-valid access to `m_zonePlaylistActive`.

- Destination: `by-class/SoundManager.md` (UID0000DG complete formal replacement).

```text
*** UID:0000DG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
    void ReinitializeAudioDriverAndResumeMusic();
    void ShutdownAudioDriver();
    static void AILCALLBACK AILStreamEndCallback(HSTREAM stream);

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
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

- The prose-only `by-file/SoundManager.md` page has no reconstruction channels and cannot safely provide callback prototypes. UID0004WV remains the narrow declaration-only emitter after class position `10` and before constructor position `20`. `#include "SoundManager.h"` exposes the private static stream declaration; the item must therefore declare only the four free file callbacks with exact Miles ABI spellings.

- Destination: `by-item/SoundManagerMilesCallbackDeclarations.md` (validator-assigned UID0004WV).

```text
*** UID:0004WV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000DG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:15 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "SoundManager.h"

static U32 AILCALLBACK AILFileOpenCallback(const char *filename, U32 *fileHandle);
static void AILCALLBACK AILFileCloseCallback(U32 fileHandle);
static S32 AILCALLBACK AILFileSeekCallback(U32 fileHandle, S32 offset, U32 origin);
static U32 AILCALLBACK AILFileReadCallback(U32 fileHandle, void *buffer, U32 bytes);
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

- Declaration-emitter H reason: the four File callbacks have internal linkage and are used only by `SoundManager.cpp`; exporting them through `SoundManager.h` would invent a public interface. Its H channel remains blank. The stream callback is different because legal private access requires its declaration in private class scope; UID0000DG owns that declaration without making it public.
- No-duplicate policy: UID0004WV emits only the include and four free declarations. UID0000TU and close/seek/read pages emit one free CPP definition each at positions `520-550`; UID0004X0 emits one qualified static-member CPP definition at position `560`; no body page emits H. UID0000DG emits the sole class declaration and header children.
- The following body formals are the exact implemented text. Scoped validation allocated UID0004X1, UID0004WW, UID0004WX, UID0004WY, UID0004WZ, and UID0004X0; all are recorded here before supervisor execution.

- Destination: `by-memory/0x0057afd0-0x0057b011.SoundManagerReinitializeAudioDriverAndResumeMusicRaw.md`.

```text
*** UID:0004X1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000DG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000DG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:390 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SoundManager::ReinitializeAudioDriverAndResumeMusic()
{
    ReinitializeAudioDriver();

    if (g_pConfig->m_musicSourceMode == 1) {
        const int trackIndex = m_currentTrackIndex;
        m_currentTrackIndex = 0;
        PlayTrackByIndex(trackIndex, 100, 1);
    } else if (g_pConfig->m_musicSourceMode == 0) {
        PlayMusicByZone(g_activeMapPane->m_zoneMusicId,
                        g_activeMapPane->m_zoneMusicFallbackTrackIndex,
                        g_activeMapPane->m_zoneMusicVolumeScale,
                        0);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
*** Item Summary: Retained private SoundManager audio-driver reinitialization/resume method preserving mode-one current-track restart and mode-zero zone-music shared-tail behavior, exact zero-route evidence, and inferred source-quality naming. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Destination: `by-memory/0x0057b5f0-0x0057b62a.SoundManagerShutdownAudioDriverRaw.md`.

```text
*** UID:0004WW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000DG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000DG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:510 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SoundManager::ShutdownAudioDriver()
{
    if (m_stream != NULL) {
        AIL_close_stream(m_stream);
        m_stream = NULL;
    }

    if (m_digitalDriver != NULL) {
        AIL_close_digital_driver(m_digitalDriver);
        m_digitalDriver = NULL;
    }

    AIL_release_all_timers();
    AIL_shutdown();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
*** Item Summary: Retained private SoundManager audio-driver shutdown method closing and clearing the active stream and digital driver, releasing Miles timers, tail-calling Miles shutdown, and preserving exact zero-route evidence. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Destination: `by-memory/0x0057b630-0x0057b72b.AILFileOpenCallback.md` (UID0000TU move).

```text
*** UID:0000TU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000DG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:520 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static U32 AILCALLBACK AILFileOpenCallback(const char *filename, U32 *fileHandle)
{
    SoundPathString ansiPath(filename);
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > path(ansiPath);
    File *file;

    if (HasDATEntry(path.c_str())) {
        file = new DATFile;
    } else {
        if (!PathExistsViaStat(path.c_str()))
            return 0;
        file = new StdioFile;
    }

    file->Open(path.c_str());
    *fileHandle = reinterpret_cast<U32>(file);
    return 1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
*** Item Summary: SoundManager file-local Miles open callback converting the ANSI path, preferring DAT-backed files, falling back to an existing loose file, opening through File, and returning the pointer as the 32-bit Miles handle. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Destination: `by-memory/0x0057b730-0x0057b74a.AILFileCloseCallback.md`.

```text
*** UID:0004WX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000DG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:530 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void AILCALLBACK AILFileCloseCallback(U32 fileHandle)
{
    delete reinterpret_cast<File *>(fileHandle);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
*** Item Summary: SoundManager file-local Miles close callback deleting the File object carried by the 32-bit Miles handle with the SDK's exact void callback ABI and null-safe virtual destruction behavior. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Destination: `by-memory/0x0057b750-0x0057b793.AILFileSeekCallback.md`.

```text
*** UID:0004WY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000DG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:540 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static S32 AILCALLBACK AILFileSeekCallback(U32 fileHandle, S32 offset, U32 origin)
{
    File *file = reinterpret_cast<File *>(fileHandle);
    int seekOrigin;

    switch (origin) {
    case 0: seekOrigin = SEEK_SET; break;
    case 1: seekOrigin = SEEK_CUR; break;
    case 2: seekOrigin = SEEK_END; break;
    default: seekOrigin = origin; break;
    }

    file->Seek(offset, seekOrigin);
    return file->GetPosition();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
*** Item Summary: SoundManager file-local Miles seek callback mapping origin values to File seeking, preserving unknown origins, ignoring the seek result, and returning the resulting File position. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Destination: `by-memory/0x0057b7a0-0x0057b7e8.AILFileReadCallback.md`.

```text
*** UID:0004WZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000DG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:550 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static U32 AILCALLBACK AILFileReadCallback(U32 fileHandle, void *buffer, U32 bytes)
{
    File *file = reinterpret_cast<File *>(fileHandle);
    const U32 remaining = static_cast<U32>(file->GetSize() - file->GetPosition());

    if (bytes >= remaining)
        bytes = remaining;

    file->Read(buffer, bytes);
    return bytes;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
*** Item Summary: SoundManager file-local Miles read callback clamping the requested byte count to unsigned remaining File size, preserving the ignored Read return and short-read reporting weakness, and returning the clamped request count. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Destination: `by-memory/0x0057b7f0-0x0057b853.AILStreamEndCallback.md`.

```text
*** UID:0004X0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000DG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000DG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:560 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void AILCALLBACK SoundManager::AILStreamEndCallback(HSTREAM stream)
{
    enum {
        kPlayNextTrackMessage = 0x407,
        kPlayNextPlaylistTrackMessage = 0x408
    };

    if (g_pConfig->m_musicSourceMode == 1) {
        PostMessageA(g_pApplication->GetMainWindowHandle(),
                     kPlayNextTrackMessage, 0, 0);
    }

    if (g_pConfig->m_musicSourceMode == 0 &&
        g_pSoundManager->m_zonePlaylistActive) {
        PostMessageA(g_pApplication->GetMainWindowHandle(),
                     kPlayNextPlaylistTrackMessage, 0, 0);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
*** Item Summary: Private static SoundManager Miles stream-completion callback preserving the no-this HSTREAM ABI, legally reading private zone-playlist state through g_pSoundManager, and posting the exact next-track or active zone-playlist messages selected by two independent source-mode conditions. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Reason behavior is preserved: each block follows exact branch, call, field, return, omission, and weakness evidence. Compiler EH, callback calling convention lowering, tail merge, SDK startup wrapper, scalar destructors, and STL internals are not handwritten.
- Source shape: private class methods, four file-static File callbacks, and one private static class callback match a mid-2000s game integration unit. The static member preserves the exact callback machine ABI while satisfying C++ access control. Human names replace decompiler labels while Miles typedef/macro spellings come from the contemporary header ABI.
- Naming convention: existing SoundManager PascalCase methods, `m_` fields, `g_p` globals, descriptive file-static File callback names, and a PascalCase private static class callback.
- Third-party import directive: not applicable. This is project-owned integration glue that calls an external Miles DLL.

## Final Recommendation
- Accept the implemented UID0001IC `93/94` exact range, class owner/emitter, position `500`, `Nested:0`, and complete formal.
- Accept moved UID0000TU and allocated exact children UID0004X1/0004WW/0004WX/0004WY/0004WZ at their validated ranges/routes/scores. UID0000TU and the four File callback children remain canonically file-owned and insert through UID0000DG at positions `520-550`. Accept implemented UID0004X0 exact range/body/score, class owner/emitter UID0000DG, and qualified private-static definition at `560`.
- Retain implemented UID0000DG CPP-blank/H-complete migration, both retained private methods, private static stream callback declaration, every prior declaration, and `[[CHILDREN]]`.
- Retain UID0004WV canonical owner UID0000NV, insertion emitter UID0000DG, position `15`, one SoundManager include, and exactly four file-static Miles File callback prototypes. Current command17510 verifies generated ordering and semantic continuity; historical command17464 records the focused-callback correction. UID0000DG supplies the stream declaration and UID0004X0 the sole definition.
- Preserve broad UID0001I8 and all later exact compiler/STL/StringBase children without duplicate source, plus all synchronized historical assumptions and callback ABI evidence.
- The focused ordinary legality callback, scoped/generated checks, independent Gate 2A, and supervisor Gate 2B are complete. Catalog entry `0312` records exact applied/readback state. Supervisor next performs fresh exact-artifact Gate 1 continuity review, execution/archive only after that approval, and manual coverage only afterward.

## Recommended Target Doc Changes
- Applied target path: `by-memory/0x0057b490-0x0057b5f0.SoundManagerReinitializeAudioDriver.md`, preserving UID0001IC; old broad path absent.
- The target's exact behavior, calls, types, fields, two callers, boundary bytes, startup macro/shim explanation, rejected alternatives, raw sibling relationships, confidence caps, and historical aggregate provenance remain valid.
- Target metadata/formal remain valid. Old broad-range/saved-label claims remain dated history superseded by the exact split; `9DF4` and `7509` are historical evidence/prestate, while saved-IDB SHA256 `DCB050F31EB99C9A6037DB8E29573B8A8C4737520317C4364814F3ECCB432281` is the current Gate 2B authority.

## Recommended Support Doc Changes
- Applied UID0000TU UID-preserving move to exact by-memory path with the correct half-open end, SDK ABI, formal, score, position, and historical raw-name drift.
- Created exact children UID0004X1/0004WW/0004WX/0004WY/0004WZ/0004X0 from the accepted inventory and complete formals.
- UID0000DG now contains the private static stream declaration while preserving its `92/94` score, complete H declaration, blank CPP, and every existing declaration/child.
- UID0004WV retains allocation/route/score/order and now contains only the include plus four File callback prototypes; H remains blank.
- UID0004X0 preserves range/body/`92/93` and now has owner/emitter UID0000DG plus the qualified static-member formal. UID0000TU/UID0004WX/UID0004WY/UID0004WZ preserve canonical UID0000NV ownership and now insert through UID0000DG to keep physical positions `520-550` ahead of UID0004X0 at `560`.
- Synchronized UID0000NV and UID0001I8 for the private-static/file-static split and output-order route. UID0001IA and UID0004QX already carried accepted facts and required no focused-callback churn. File/DATFile/StdioFile/MapPane support also required no change.
- Added all eight accepted padding spans to `by-memory/-ignored.md` with full byte/xref/comment evidence.
- Historical commands17427 and17440 established the initial output and exposed the five-free-prototype/private-access defect. Historical focused-callback command `000000017464`, refreshed `2026-07-24T23:35:34-04:00`, produced SoundManager.cpp SHA256 `53FB2C2E1AEE1B2FE05A38C12A0D1096585AC214B70EE5C2C65C32A5F08890B6`, 27,748 bytes/836 lines, and SoundManager.h SHA256 `672AE824D02F3D98D3B20649252F2F8538A314EBACB9CE6680B1C0D6CAB1C9AE`, 3,795 bytes/114 lines; it remains valid historical proof of the corrected shape.
- Current physical command `000000017510`, refreshed `2026-07-25T04:52:56-04:00`, reads SoundManager.cpp SHA256 `00929E145B36E1186653E404F3DAA2D1D29CD731651D8DFE082092FEFCCA50E6`, 27,750 bytes/836 lines, and SoundManager.h SHA256 `092EBB2DCD2F8151623C354D5A5267EB62487717144B1A805DDC39672AA5C8B9`, 3,797 bytes/114 lines. CPP has one each UID0004WV/0004X1/0001IC/0004WW/0000TU/0004WX/0004WY/0004WZ/0004X0, four free prototypes at lines `16-19`, callback definitions at `759/779/785/802/815`, one qualified `SoundManager::AILStreamEndCallback`, and zero UID0001IC/UID0000TU/UID0004X0 empty markers. H has one class, one private-static stream declaration, and one no-children placeholder. The two physical CPP empty markers belong to unrelated UID0000DG/UID0001I7 rows. No free body accesses private SoundManager state.

## Score And Metadata Recommendation
- Assignment-time UID0001IC: `87/90`, owner/emitter UID0000NV, true, blank position/formal, `Nested:-4`.
- Current implemented UID0001IC: `93/94`, owner/emitter UID0000DG, true, position500, complete formal, `Nested:0`.
- Reason not higher: exact original private-static versus friend declaration form, helper spellings, local names, Config field spelling, and SDK macro expansion are inferred; corrected source has not yet been compiled/compared.
- Reason not lower: every behavior, boundary, xref, type, callback ABI, owner, split, source route, and code/no-code disposition has direct or convergent evidence.
- Score-improvement attempt: all former blockers were researched. Callback typedefs resolve from SDK ABI; fields from current UDT/support writers; split from exact functions/raw items/padding; liveness from xrefs/byte patterns/unique bodies; singleton-helper error from callback registration/dispatch; and source legality from C++ access rules plus direct private-field use. The chosen static-member repair resolves the legality blocker without changing runtime behavior.
- Support scores are listed in the inventory; class/file scores remain unchanged.
- Declaration-only by-item UID0004WV remains `93/94`, canonical owner UID0000NV, insertion emitter UID0000DG, reconstructable true, position `15`, CPP include/four-prototype preamble, blank H. UID0004X0 remains `92/93`; its corrected class route is a source-placement repair, not an evidence-based score increase.

## Open Questions With Attempted Resolution
- Original names: binary cannot prove private/static spelling. Best consistent names are selected and collision-checked; no raw labels remain in final source. This is a confidence cap, not a blocker.
- Stream callback declaration shape: a free static function is rejected because it cannot access private `m_zonePlaylistActive`. Making the field public is unevidenced; an accessor has no binary call; friend linkage is possible but less consistent with the header-emitted class and internal-linkage predeclaration requirements. The implemented private static member is the highest-probability compile-valid shape and preserves exact `__stdcall(HSTREAM)` behavior. Current command17510 verifies the selected declaration/definition split; historical command17464 records the focused-callback checkpoint.
- Raw liveness: zero xrefs and pointer patterns were exhaustively checked. Unique complete source bodies retained in the executable plus direct semantic state/calls justify private method emission under project policy; no caller is invented.
- Miles startup shim: live analysis proves atexit registration immediately before imported startup. Contemporary SDK/header behavior makes `AIL_startup()` the correct human source representation; no NexusTK helper is invented.
- Config `+0x291914`: registry key `SoundFreq`, UI writer, and rate branch support `m_soundFrequency`; alternate exact spelling cannot be recovered. The chosen name is high-probability source inference.
- Callback declaration and definition order: generated readback proved direct file-root children sort after UID0000DG's subtree. UID0004WV therefore emits through UID0000DG at position `15` while retaining canonical file ownership, and the four canonically file-owned File callback bodies use the same insertion router at positions `520-550`; class-owned stream follows at `560`. This preserves declaration-before-use and physical address/source order without changing file-static linkage. The private static stream declaration belongs only inside UID0000DG H.
- New UIDs resolved: validator allocated declaration UID0004WV, raw method UID0004X1, shutdown UID0004WW, close UID0004WX, seek UID0004WY, read UID0004WZ, and stream UID0004X0. All are materialized and recorded before supervisor execution.
- No research question, authorized ordinary source-legality correction, or accepted IDA recommendation remains unresolved. Remaining work is supervisor exact-artifact Gate 1 continuity review, lifecycle execution/archive, and post-execution manual coverage only.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Assignment-time rows were inspected for by-memory UID0001IC, by-item UID0000TU, by-class UID0000DG, and by-file UID0000NV. Scoped validation allocated all new UIDs and automatically propagated UID/path reference links, but B002 did not manually edit any coverage report. The exact supervisor-owned semantic row payload below remains pending until after report execution.
- Supervisor replacement for current UID0001IC row:

```text
    - [UID:0001IC][0x0057b490-0x0057b5f0.SoundManagerReinitializeAudioDriver](by-memory/0x0057b490-0x0057b5f0.SoundManagerReinitializeAudioDriver.md) 0x0057b490-0x0057b5f0 | method | SoundManagerReinitializeAudioDriver : reconstructable : 93% : very-strong : Exact SoundManager::ReinitializeAudioDriver source method with Miles teardown/startup ordering, redistributable-directory setup, SoundFreq-backed 44100/22050 selection, hardware/fallback driver open, DirectSound HWND binding, exact file-callback registration, eight SoundSampleSlot clear/allocation, constructor and retained reinit/resume callers, exact padding/sibling split, class UID0000DG ownership, position 500, complete source-era draft C++, and historical broad UID0001IC aggregate evidence preserved under sole broad index UID0001I8.
```

- Delete the current by-item UID0000TU row and insert under by-memory after the shutdown child:

```text
    - [UID:0000TU][0x0057b630-0x0057b72b.AILFileOpenCallback](by-memory/0x0057b630-0x0057b72b.AILFileOpenCallback.md) 0x0057b630-0x0057b72b | file-local callback | AILFileOpenCallback : reconstructable : 93% : very-strong : Exact Miles file-open callback registered only by SoundManager; converts ANSI input to the wide project string, prefers DATFile through HasDATEntry, falls back to StdioFile for an existing loose path, opens through File, returns the pointer as a 32-bit Miles handle, preserves throwing-new and unchecked-Open source behavior, uses the contemporary Miles callback ABI, remains canonically file-owned by UID0000NV while inserting through UID0000DG at position 520 for exact callback order, and records bounded historical 9DF4 plus current pre-Gate2B 7509 IDA checkpoints.
```

- Insert this exact allocated row in `by-item/-coverage-report.md` after `ServerSelectHelpers_574510_5745b0` and before `SpellMenuActionButtonState_51d6c0_51e600`:

```text
- [UID:0004WV][SoundManagerMilesCallbackDeclarations](by-item/SoundManagerMilesCallbackDeclarations.md) : reconstructable : 93% : very-strong : Declaration-only SoundManager.cpp source preamble canonically owned by file UID0000NV and emitted through insertion parent UID0000DG at position 15 before constructor position 20 and every free callback use; includes SoundManager.h and declares the exact four file-static Miles open, close, seek, and read callbacks with U32/S32/AILCALLBACK ABI spellings, while UID0000DG privately declares the static HSTREAM completion callback and exact by-memory pages retain the sole CPP definitions; generated readback rejected direct-file insertion because it sorted after the class subtree.
```

- New-child rows are materialized with the following validator-assigned UIDs. Exact supervisor-owned row bodies, in address order, are:

```text
    - [UID:0004X1][0x0057afd0-0x0057b011.SoundManagerReinitializeAudioDriverAndResumeMusicRaw](by-memory/0x0057afd0-0x0057b011.SoundManagerReinitializeAudioDriverAndResumeMusicRaw.md) 0x0057afd0-0x0057b011 | retained private method | SoundManagerReinitializeAudioDriverAndResumeMusicRaw : reconstructable : 90% : strong : Exact raw no-function SoundManager method that rebuilds the audio driver, resumes the current stream track in source mode 1, or enters the shared mode-zero zone-music suffix with active MapPane zone/fallback/volume values and loop count zero; zero xref and VA/RVA route evidence caps original-name confidence but does not erase the unique source body; emits through class UID0000DG at position 390.
    - [UID:0004WW][0x0057b5f0-0x0057b62a.SoundManagerShutdownAudioDriverRaw](by-memory/0x0057b5f0-0x0057b62a.SoundManagerShutdownAudioDriverRaw.md) 0x0057b5f0-0x0057b62a | retained private method | SoundManagerShutdownAudioDriverRaw : reconstructable : 91% : very-strong : Exact raw no-function SoundManager teardown method closing/clearing stream and digital driver, releasing all Miles timers, and tail-calling AIL_shutdown; zero route evidence caps name confidence but complete unique behavior emits through class UID0000DG at position 510.
    - [UID:0004WX][0x0057b730-0x0057b74a.AILFileCloseCallback](by-memory/0x0057b730-0x0057b74a.AILFileCloseCallback.md) 0x0057b730-0x0057b74a | file-local callback | AILFileCloseCallback : reconstructable : 92% : very-strong : Exact Miles void close callback registered only by SoundManager, treating the 32-bit handle as File* and deleting it with null-safe virtual destruction; canonically owned by UID0000NV and inserted through UID0000DG at position 530.
    - [UID:0004WY][0x0057b750-0x0057b793.AILFileSeekCallback](by-memory/0x0057b750-0x0057b793.AILFileSeekCallback.md) 0x0057b750-0x0057b793 | file-local callback | AILFileSeekCallback : reconstructable : 93% : very-strong : Exact Miles seek callback mapping origins 0/1/2 to File::Seek while preserving unknown values, ignoring the seek result, and returning File::GetPosition; canonically owned by UID0000NV and inserted through UID0000DG at position 540.
    - [UID:0004WZ][0x0057b7a0-0x0057b7e8.AILFileReadCallback](by-memory/0x0057b7a0-0x0057b7e8.AILFileReadCallback.md) 0x0057b7a0-0x0057b7e8 | file-local callback | AILFileReadCallback : reconstructable : 93% : very-strong : Exact Miles read callback clamping requested bytes to unsigned remaining File size, calling File::Read, intentionally ignoring the actual return, and reporting the clamped request count including short-read weakness; canonically owned by UID0000NV and inserted through UID0000DG at position 550.
    - [UID:0004X0][0x0057b7f0-0x0057b853.AILStreamEndCallback](by-memory/0x0057b7f0-0x0057b853.AILStreamEndCallback.md) 0x0057b7f0-0x0057b853 | private static member callback | AILStreamEndCallback : reconstructable : 92% : very-strong : Exact Miles void stream-completion callback registered by PlayTrackByIndex, preserving the no-this HSTREAM ABI, legally accessing private SoundManager zone-playlist state through g_pSoundManager, and posting main-window messages 0x407/0x408 for next stream track or active mode-zero playlist progression; corrects stale singleton-helper/free-callback wording and emits through UID0000DG at position 560.
```

- Exact ignored-page insertion text:

```text
- `0x0057afce-0x0057afd0`, `0x0057b011-0x0057b020`, `0x0057b62a-0x0057b630`, `0x0057b72b-0x0057b730`, `0x0057b74a-0x0057b750`, `0x0057b793-0x0057b7a0`, `0x0057b7e8-0x0057b7f0`, and `0x0057b853-0x0057b860` - SoundManager scanner, driver, and Miles callback split alignment padding.
  - Why ignored: exact compiler/linker alignment gaps separating complete source-bearing SoundManager methods and file-static Miles callbacks.
  - Evidence: B002 UID0001IC live MCP checkpoint 9DF4 verifies one unnamed/untyped data item per half-open span, respectively 2, 15, 6, 5, 6, 13, 8, and 13 consecutive `0xcc` bytes, absent regular/repeatable comments, zero xrefs, and exact neighboring code/function heads.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: UID0001IA scanner, UID0001IC reinitializer, and the exact SoundManager raw/callback children created from B002 UID0001IC.
```

- Replace the current UID0000DG class row with:

```text
- [UID:0000DG][SoundManager](by-class/SoundManager.md) : reconstructable : 92% : very-strong : Complete x86/MSVC 0x10ac natural-alignment SoundManager declaration emitted solely through the H channel into SoundManager.h with CPP exactly blank, direct Singleton<SoundManager> then TimerHandler inheritance and PMD/EBO proof; Miles handles; option/runtime bytes; stream/Redbook tuples; eight SoundSampleSlot records; 1000 DAT payload pointers; standard local/zone SoundPathString vectors; complete playback, Redbook, scanner, OnTimer, DirectSound, ReinitializeAudioDriver, retained private ReinitializeAudioDriverAndResumeMusic, retained private ShutdownAudioDriver, and private static AILStreamEndCallback surface; static callback preserves the Miles no-this ABI while legally accessing private zone-playlist state; PlaySample plus inline PlayEffect alias; BaramApp friend/private access; [[CHILDREN]] retained inside H; exact source constructor/destructor and method children; compiler-only Singleton publication/clear, EH/scalar/vptr/vtable/vector/base exclusions; exact child emission; and one-definition g_pSoundManager route through SoundManager.cpp.
```

- Replace the current UID0000NV file row with:

```text
- [UID:0000NV][SoundManager](by-file/SoundManager.md) : reconstructable : 92% : very-strong : NexusTK/audio/SoundManager.cpp and SoundManager.h source root with the sole position-zero g_pSoundManager definition; complete UID0000DG 0x10ac class declaration emitted H-only at position 10 with CPP blank and a private static stream-completion declaration; declaration-only position-15 SoundManager.h include and four file-static Miles File callback prototypes before all free uses; exact authored constructor/destructor at positions 20/30; playback-control children at 100-290; music-directory scanner at 300; retained private reinitialize/resume at 390; Redbook children at 400-470; exact ReinitializeAudioDriver, ShutdownAudioDriver, AIL open/close/seek/read, and qualified SoundManager stream-completion definitions at positions 500-560; complete Miles driver/file-callback, DAT-backed sample/music, Config, Application, TimerHandler OnTimer, and DirectSound behavior; preserved compiler/STL helper exclusions, exact source order, separate CPP-definition/blank-H body policy, source-access legality, and generated CPP/H verification requirements; and compiler-only Singleton publication/clear, EH, scalar, vector/base, vptr, and vtable output.
```

- B002 did not apply manual coverage text. The payload is fully allocated; the supervisor applies and validates it only after report execution.

## Follow-Up Actions
- Supervisor: perform fresh exact-artifact Gate 1 continuity review on this post-Gate-2B reconciled report. The focused UID0000DG/UID0004WV/UID0004X0 legality changes, callback insertion-route synchronization, serial validators, current command17510 generated readback, independent Gate 2A, and catalog-entry-0312 Gate 2B are complete.
- After the new exact-artifact continuity review passes, the supervisor may run execution/archive and then apply/validate the fully allocated manual coverage payload in that required order.
- A-agent actions: none.
- B002 focused callback and same-report Gate 2B reconciliation are complete. Ordinary docs implement the selected compile-valid source shape and exact output-order routing; validators alone refreshed generated files. Supervisor catalog entry `0312` closed the `7509`-based actionable/no-change/protected handoff and saved `DCB050F3...2281`. B002 did not mutate IDA, manually edit generated/coverage/audit/validator/lifecycle state, or run/probe any lifecycle command.

## Confidence
- Recommendation confidence: very strong (`94`) for target; strong-to-very-strong per raw/new child scores.
- Score confidence: strong. All former score blockers have concrete evidence-backed resolutions.
- Remaining uncertainty: exact original static-member versus friend declaration form, local spellings, and SDK macro expansion. Runtime behavior is exact; the chosen class ownership is high-probability and compile-valid.

## Validator Results
- All scoped commands used `python .\tools\validator.py --mode file --file <relative-path> --apply --queue-timeout 240`; every listed command exited `0` with `ok: 1`.
- `000000017396` at `2026-07-24T21:15:23-04:00`: initial UID0000DG CPP-to-H channel migration; generated `SoundManager.h` created/refreshed.
- `000000017399` at `2026-07-24T21:16:37-04:00`: declaration page allocation, UID0004WV.
- `000000017401` at `2026-07-24T21:18:00-04:00`: shutdown page allocation, UID0004WW.
- `000000017402` at `2026-07-24T21:18:40-04:00`: close page allocation, UID0004WX.
- `000000017403` at `2026-07-24T21:19:27-04:00`: seek page allocation, UID0004WY.
- `000000017405` at `2026-07-24T21:20:16-04:00`: read page allocation, UID0004WZ.
- `000000017411` at `2026-07-24T21:21:03-04:00`: stream page allocation, UID0004X0.
- `000000017415` at `2026-07-24T21:22:14-04:00`: UID0000TU move to exact by-memory path. Three unrelated pre-existing missing-ref warnings remained in by-item coverage (UID0003VI/0003VJ/0003VL); validator automatically propagated UID/path links into coverage, but B002 made no manual coverage edit.
- `000000017416` at `2026-07-24T21:23:17-04:00`: raw retained method allocation, UID0004X1.
- `000000017417` at `2026-07-24T21:24:40-04:00`: UID0001IC exact rename/range/formal. Validator automatically propagated reverse-reference links; 213 pre-existing missing-ref warnings were emitted by broad reverse-reference scans, with no target-specific error.
- `000000017418` at `2026-07-24T21:25:54-04:00`: by-file/SoundManager.md synchronization.
- `000000017419` at `2026-07-24T21:26:46-04:00`: UID0001I8 broad-index synchronization.
- `000000017420` at `2026-07-24T21:27:25-04:00`: UID0001IA scanner synchronization.
- `000000017421` at `2026-07-24T21:28:05-04:00`: UID0004QX shared-tail synchronization.
- `000000017422` at `2026-07-24T21:28:47-04:00`: by-memory/-ignored.md eight-span insertion. Its large pre-existing reference inventory emitted 209 missing-ref warnings; target insertion passed.
- `000000017424` at `2026-07-24T21:31:34-04:00`: UID0004WV insertion emitter corrected from UID0000NV to UID0000DG after generated-order readback.
- `000000017425` at `2026-07-24T21:32:42-04:00`: UID0000DG allocated-UID/source-order synchronization.
- `000000017426` at `2026-07-24T21:33:30-04:00`: UID0001IC historical-state correction.
- `000000017427` at `2026-07-24T21:34:04-04:00`: historical final UID0001IC scoped validation and initial generated readback.
- Historical command `000000017440`, refreshed `2026-07-24T22:15:48-04:00`, exposed the five-free-prototype/private-access defect: SoundManager.cpp SHA256 `5175A754A2F7FBBC1058ED0DB99CB71C4F3FBDFFFC2F2E47B1EF4D85E945E299`, 27,806 bytes/838 lines; SoundManager.h SHA256 `CF25AFFD5378297A45AF816ACFC1EE0C83DE6DE0372FB75AAE7939E8F82AEBAA`, 3,731 bytes/113 lines.
- Focused callback commands, all exit `0`, `ok: 1`, no target-specific warnings: `000000017455` at `2026-07-24T23:21:50-04:00` UID0000DG; `000000017456` at `23:22:46-04:00` UID0004WV; `000000017457` at `23:23:26-04:00` UID0004X0 owner/emitter/formal; `000000017458` at `23:24:03-04:00` UID0000NV; `000000017459` at `23:24:37-04:00` UID0001I8; `000000017460` at `23:26:53-04:00` UID0000TU insertion route; `000000017461` at `23:27:13-04:00` UID0004WX insertion route; `000000017462` at `23:27:35-04:00` UID0004WY insertion route; `000000017463` at `23:28:02-04:00` UID0004WZ insertion route; `000000017464` at `23:35:34-04:00` UID0000TU autogen-parent wording reconciliation and final physical generated refresh.
- Historical focused-callback command `000000017464`, refreshed `2026-07-24T23:35:34-04:00`: SoundManager.cpp SHA256 `53FB2C2E1AEE1B2FE05A38C12A0D1096585AC214B70EE5C2C65C32A5F08890B6`, 27,748 bytes/836 lines; SoundManager.h SHA256 `672AE824D02F3D98D3B20649252F2F8538A314EBACB9CE6680B1C0D6CAB1C9AE`, 3,795 bytes/114 lines. This remains historical proof of the corrected source shape, not the current physical identity.
- Current physical command `000000017510`, refreshed `2026-07-25T04:52:56-04:00`: SoundManager.cpp SHA256 `00929E145B36E1186653E404F3DAA2D1D29CD731651D8DFE082092FEFCCA50E6`, 27,750 bytes/836 lines; SoundManager.h SHA256 `092EBB2DCD2F8151623C354D5A5267EB62487717144B1A805DDC39672AA5C8B9`, 3,797 bytes/114 lines.
- Current command17510 semantic readback: CPP contains one each UID0004WV/0004X1/0001IC/0004WW/0000TU/0004WX/0004WY/0004WZ/0004X0, exactly four free prototypes at lines `16-19`, callback definitions in accepted physical order at lines `759/779/785/802/815`, one qualified `SoundManager::AILStreamEndCallback`, and zero UID0001IC/UID0000TU/UID0004X0 empty markers. H contains one class, one private-static stream declaration, and one no-children placeholder. The two physical CPP empty markers belong to unrelated UID0000DG/UID0001I7 rows. The free callbacks do not access private SoundManager state, and the member callback has legal private access.
- A pre-creation `python leaser.py` attempt from the documentation root failed before any edit because that path has no root-level `leaser.py`. New-child creation then proceeded while the required parent lease was held, and every created page was subsequently leased/validated/released normally. No lifecycle command was attempted.
- Historical validators passed structural validation but did not detect the C++ access-control defect. Focused commands17455-17464 validated the corrected ordinary documents and established the historical generated legality/count/order checkpoint; current command17510 independently preserves those semantic invariants.
- This same-report Gate 2B reconciliation ran no validator and did not refresh or edit ordinary/generated files; all validator evidence above is preserved unchanged.

## Changed Files
- Historical first-callback `by-class/SoundManager.md` checkpoint: SHA256 `C0841B7E352B6001B7BAC8C233B225B6C601A98890115533F42AAD5DD026071A`, 45,359 bytes / 377 lines.
- Historical first-callback `by-item/SoundManagerMilesCallbackDeclarations.md` UID0004WV checkpoint: SHA256 `FFCB12C30B81B9F63BBA0235A08E79E85A683F712B9C5EC379BB8A9C3471016F`, 6,840 bytes / 72 lines.
- Created `by-memory/0x0057afd0-0x0057b011.SoundManagerReinitializeAudioDriverAndResumeMusicRaw.md` UID0004X1: SHA256 `1C57F3D78A6333612A50C1BB035130AF67C141851FCB839603B9AFB3ADD51465`, 6,335 bytes / 82 lines.
- Renamed/narrowed UID0001IC to `by-memory/0x0057b490-0x0057b5f0.SoundManagerReinitializeAudioDriver.md`: SHA256 `84BDA053BFF33F6283DA621F03F2C0B2DE80965EDC0FD524D33779EDD55079C5`, 36,799 bytes / 274 lines. Old broad path is absent.
- Created `by-memory/0x0057b5f0-0x0057b62a.SoundManagerShutdownAudioDriverRaw.md` UID0004WW: SHA256 `92E62C46F75DAECFC96C7D3255BD28D59655EF9CD444F6F2A51E9DA5BDD3F6ED`, 5,679 bytes / 81 lines.
- Historical first-callback UID0000TU checkpoint at `by-memory/0x0057b630-0x0057b72b.AILFileOpenCallback.md`: SHA256 `CAB8DD14EC246C45CADB56AAC187CA90AA68618D87C604D643A74995EE3E53A4`, 13,151 bytes / 143 lines. Old by-item path is absent.
- Historical first-callback children: UID0004WX close SHA256 `8BE6C052131CA1481DBE79F1D3C70A8B721574FA6027BBA29BF2ED8CE361191C`; UID0004WY seek `0F536534724B6FFCB929C3D9964900A0642FA12375BD66322C5601CE0CB16F23`; UID0004WZ read `E8EAD82763E478A7CB1C355AE1ED631F3DF295DFFC122750141DCE23123EAE47`; UID0004X0 stream `4798C36DDEE21AE19D780FA40DFF3B63CA5BE4A6F639482AB40B82B4B65E512E`.
- Historical first-callback `by-file/SoundManager.md` checkpoint: SHA256 `6732FC87C3B7D61EEF13602F966D3383195E2C1A97286925044886D612D57C99`, 55,677 bytes / 316 lines.
- Historical first-callback UID0001I8 `SoundManagerAudioHelperCluster.md` checkpoint: SHA256 `A60DE89C0FC471C8D1F93E2B36FBCB612C8D018F644FD2A1124155504D3EDBA7`, 40,519 bytes / 220 lines.
- Modified UID0001IA `SoundManagerMusicDirectoryScan.md`: SHA256 `98E0E03E7DFAE5781619BF8118954EFD16A62567535BBCD26553E1143CB4C719`, 21,409 bytes / 238 lines.
- Modified UID0004QX `SharedMusicPlaybackTail.md`: SHA256 `DFEAAD91751F7F22E3E7E162CA178322D4AAAAD0CF8FFEB8493B0E9DD9130E29`, 10,605 bytes / 112 lines.
- Modified `by-memory/-ignored.md`: SHA256 `4FC1BE22990D5CE92625E85E1E01042DE78425000C95494BBF724BCE52D06B72`, 1,112,439 bytes / 5,386 lines.
- Historical post-callback generated checkpoint from command 17427: `SoundManager.cpp` SHA256 `1740E8653027D57F47F0749E711512250816DF3E7E0058BEFE3D0B1BA29CC33E`, 27,806 bytes/838 lines; `SoundManager.h` SHA256 `BA6BCC27E73A604CC5D27A7ED02A1AD850DA8DB25B9288F2973E5AA613539875`, 3,731 bytes/113 lines.
- Historical command 17440 generated checkpoint: `SoundManager.cpp` SHA256 `5175A754A2F7FBBC1058ED0DB99CB71C4F3FBDFFFC2F2E47B1EF4D85E945E299`, 27,806 bytes/838 lines; `SoundManager.h` SHA256 `CF25AFFD5378297A45AF816ACFC1EE0C83DE6DE0372FB75AAE7939E8F82AEBAA`, 3,731 bytes/113 lines; this is the rejected access-illegal shape.
- Current focused-callback destinations: `by-class/SoundManager.md` SHA256 `9E5E4C431D74EEB0676B6ADB51653CB0E3D39474A177931315EC43B0AEDF1756`, 45,622 bytes/378 lines; `by-item/SoundManagerMilesCallbackDeclarations.md` SHA256 `649D11B8AB4478182D11545AA09855A1783CDFF477D82FB4D84306C88FBC0C5C`, 8,195 bytes/71 lines; UID0004X0 `by-memory/0x0057b7f0-0x0057b853.AILStreamEndCallback.md` SHA256 `085CF495F68EAB79CFEB50F5B6C5886EDBF7BAC5EBD45E8DC6D304DB77D4ABFA`, 7,084 bytes/81 lines.
- Current focused-callback support: `by-file/SoundManager.md` SHA256 `66256D544BFF7BE55D239FA2CD8A75F915A4114BF01AC747262B6AE6249DE772`, 56,330 bytes/316 lines; UID0001I8 SHA256 `6D6CC2D5519B409F810B36A5844C9BE997503CF82233F920A88B61D8CBB921B2`, 40,772 bytes/220 lines.
- Current file-callback insertion routes: UID0000TU SHA256 `27C110EE9F2E2EF0132CBB968C7027AC46DAA92C6FB6F9250C78D2E648CA2B5C`, 14,023 bytes/145 lines; UID0004WX `165C2F7D6752423FF79F878E75042C5847AB9BF1F8073966B5BBB3055097FD6F`, 4,945 bytes/62 lines; UID0004WY `05452E595D7FEFBDDCECFB91B001F2AFF6FD1BACCC63047F2149628E3506BADA`, 5,296 bytes/73 lines; UID0004WZ `FCCD77CC26F318C4391B7867820EB04E779EE5290508F254EAA6FC56D301F7C5`, 5,340 bytes/69 lines.
- Historical focused-callback command17464 generated checkpoint: `SoundManager.cpp` SHA256 `53FB2C2E1AEE1B2FE05A38C12A0D1096585AC214B70EE5C2C65C32A5F08890B6`, 27,748 bytes/836 lines; `SoundManager.h` SHA256 `672AE824D02F3D98D3B20649252F2F8538A314EBACB9CE6680B1C0D6CAB1C9AE`, 3,795 bytes/114 lines.
- Current physical command17510 generated checkpoint, refreshed `2026-07-25T04:52:56-04:00`: `SoundManager.cpp` SHA256 `00929E145B36E1186653E404F3DAA2D1D29CD731651D8DFE082092FEFCCA50E6`, 27,750 bytes/836 lines; `SoundManager.h` SHA256 `092EBB2DCD2F8151623C354D5A5267EB62487717144B1A805DDC39672AA5C8B9`, 3,797 bytes/114 lines. Semantic readback matches all accepted UID/prototype/definition/order/private-static/empty-marker invariants; two unrelated CPP empty markers remain UID0000DG/UID0001I7.
- Supervisor-owned Gate 2B state, not a B002 file edit: catalog entry `0312`; backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-0001IC-20260725_051650.bak`, SHA256 `3B7FC953A07344D07F33CD8C244853E0CD8DBFF8AB80C4DE2839D14A9800B63C`, 143,186,450 bytes; saved IDB SHA256 `DCB050F31EB99C9A6037DB8E29573B8A8C4737520317C4364814F3ECCB432281`, 143,186,002 bytes, last write `2026-07-25T05:18:07.2105424-04:00`; reopened session `5f18a105` healthy and analysis-ready.
- This reconciliation changed only this existing report. B002 did not edit ordinary/support/generated/tracker, coverage, audit/catalog/supervisor/goal/validator-state, IDA, or lifecycle state. Validator-owned registry/reference/projected-stats/generated consequences remain distinguished from manual coverage payload C1IC-022. All B002 leases remain released.
- Report execution: not run, probed, or dry-run by B002.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact SHA256 `52AAAA47F020D2718B690CD62BD5E79273350C745CEC8DB35E321A77FFA9E26D` before implementation.
- [x] Target/support destination inventory covers UID0001IC, UID0000TU, allocated exact children, UID0004WV, UID0000DG, UID0000NV, UID0001I8, UID0001IA, UID0004QX, and ignored padding.
- [x] No additional report target UID was declared; every support UID has item-specific evidence, ledger action, destination, and validation.
- [x] Current target state, actual evidence, score blockers, owner/emitter/split, source placement, padding, ABI, and no-duplicate policy recorded.
- [x] Complete corrected destination-ready CPP/H blocks, class formal, exact bodies, four-prototype preamble, private-static callback declaration/definition, no-header-code reasons, source-legality alternatives, history, negative evidence, Wave2/Wave3 rejection, and third-party non-applicability recorded.
- [x] Literal Gate 2B handoff contains `7509` item-by-item prestate, action/no-change disposition, safety constraints, collision/boundary/xref evidence, and deterministic readback; `9DF4` is labeled historical. Catalog entry `0312` now records every row as applied/verified.
- [x] Exact manual supervisor-owned coverage text is fully allocated and preserved below.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] UID0000DG CPP-to-H migration and two retained private methods were applied without losing the class declaration or `[[CHILDREN]]`; historical implementation state preserved.
- [x] UID0004WV was initially created with include/five-prototype preamble, blank H, canonical file ownership, corrected insertion route, and no duplicate body; this historical checkpoint is preserved and explicitly superseded by the focused four-prototype correction.
- [x] All accepted target/support evidence incorporated at report-level detail; allocated UIDs and destination hashes recorded.
- [x] C1IC-001..011 and C1IC-015..019 independently verified against their ledger and current destinations.
- [x] Metadata, scores, split/rename/move, history, rejected alternatives, negative evidence, and open-question dispositions reconciled; C1IC-012/013/014/023 were reopened for the bounded source-legality correction and are now implemented/verified.
- [x] Serial scoped validators completed and exact command evidence recorded.
- [x] Historical command 17440 generated one-of-each/order counts but exposed the exact private-access failure; it is retained as a superseded checkpoint.
- [x] The preceding report-only Gate 1 repair changed no ordinary file and left all B002 leases released before this callback.
- [x] Focused ordinary callback: added UID0000DG private static stream declaration while preserving complete H/blank CPP/class layout.
- [x] Focused ordinary callback: reduced UID0004WV to the include plus four free File callback prototypes.
- [x] Focused ordinary callback: rerouted UID0004X0 owner/emitter to UID0000DG and applied the qualified private-static definition without changing behavior/range/score.
- [x] Focused ordinary callback: synchronized affected support/history/manual payload text, corrected four File callback insertion routes for physical source order, ran serial scoped validators 17455-17464, verified generated legality/count/order/empty markers, and released every lease.
- [x] Final generated continuity repair: preserved command17464 as historical focused-callback evidence and rebound current physical identity to command17510 CPP `00929E14...50E6` / H `092EBB2D...C8B9`; verified one each accepted UID, four prototypes at lines 16-19, callback definitions at 759/779/785/802/815, one qualified stream callback, zero UID0001IC/UID0000TU/UID0004X0 empty markers, one H class/private-static declaration/no-children placeholder, and only unrelated UID0000DG/UID0001I7 CPP empty markers.
- [x] Supervisor post-callback Gate 2A exact-artifact audit passed C1IC-001..019/023 against report SHA256 `C279172B866C539C64482BE375198070F88641144AA94D7C4817D9616AB5B5ED` and parked C1IC-020/021 for Gate 2B.
- [x] Supervisor Gate 2B applied/read back C1IC-020/021 under catalog entry `0312`: two exact raw functions created; seven exact names/types/repeatable function comments installed; comment channels, xrefs, eight padding items, protected globals/functions/types, registration edge, bytes, and eight operand-comment pairs verified; saved IDB `DCB050F3...2281`; healthy reopened session `5f18a105`. B002 did not mutate IDA.
- [x] B002 reconciled this same report only to the supervisor-applied Gate 2B state without changing prior research or ordinary/generated evidence.
- [ ] Supervisor fresh exact-artifact Gate 1 continuity review of this reconciled report remains pending.
- [ ] Supervisor execute_report/archive lifecycle step remains pending; B002 did not run or probe it.
- [ ] Supervisor post-execution manual coverage application/validation for C1IC-022 remains pending.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000017517","destination_path":"executed-b-agent-research/B002/0001IC-SoundManagerDriverDestructorAndPathHelpers-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0001IC-SoundManagerDriverDestructorAndPathHelpers-empty-emitter-source-quality.md","timestamp":"2026-07-25T22:38:45-04:00","uid":"0001IC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
