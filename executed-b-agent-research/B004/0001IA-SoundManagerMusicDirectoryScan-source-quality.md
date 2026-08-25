** TARGET-REPORT-UID:0001IA **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0001IA SoundManagerMusicDirectoryScan Source-Quality Research

## Finalized Report / Current Recommendation

- Current callback result: UID0001IA is source-ready `92/94` `SoundManager::ScanMusicDirectory` at the UID-preserving half-open path ending `0x0057afce`, with direct semantic owner UID0000DG, emitter UID0000NV, and the complete accepted managed C++ block.
- Final disposition: reconstructable source-authored SoundManager policy. Its local containers are `std::vector<mystr::StringBase<char, ...> >` and `std::deque<mystr::StringBase<char, ...> >`; their out-of-line helper bodies are MSVC/Dinkumware template lowering, not a custom NexusTK `SoundPathVector` or `Deque` API.
- Implementation state: supervisor Gate 1 accepted the exact research artifact; C01-C46 and all accepted target/support destinations are applied and scoped-validated. Exact no-`FindClose` behavior, wide input contract, ANSI path-entry type, recursion/randomization behavior, standard-container source shape, EH evidence, negative evidence, and historical assumptions remain preserved.
- Confidence: `94` for the target recommendation. Exact original local/member spelling and the inferred lowercase member name remain below-95 caveats, but no behavior, type, ownership, range, or source-shape blocker remains.

## Supporting Research

- B004 used the project `ntk-b-agent-workflow`, current literal report template, `by-structure.md`, the score/blocker audit standard, current by-* documentation, executed prior B-agent reports as historical leads, exported decompilation only as corroboration, and fresh live IDA MCP as primary binary evidence.
- Concrete old-report searches used the terms `UID0001IA`, `0x0057a890|0x0057afce`, `SoundManagerMusicDirectoryScan|ScanMusicDirectory`, `SoundPathVector`, `UID0004FM|0x0057bc60`, and owner/source-family terms `UID0000NV|UID0000DG|SoundManager.cpp|SoundManager source`. B004 ran those searches across the Agent-B001 through Agent-B015 research trees that were active when searched, executed `executed-b-agent-research`, and legacy archive `archived/b-agent-reports-20260623` report trees.
- Then-active report result: the only matching report that was active when searched was this same artifact at `tools/leaser/Agents/Agent-B004/research/0001IA-SoundManagerMusicDirectoryScan-source-quality.md`; it was excluded as a self-hit. No independent then-active report directly researched UID0001IA, its range, or either scanner name.
- Opened executed match `executed-b-agent-research/B003/000149-DequePushBack-empty-emitter-source-quality.md`: it mentions UID0001IA only as SoundManager caller/support evidence carried by UID0001IE, so it supplies no direct scanner report or body decision.
- Opened executed match `executed-b-agent-research/B002/0001IE-DequeDestroyOwnedEntries-source-quality.md`: it decompiled `0x0057a890` as the music-directory scanner, established the ANSI path-string `std::deque` queue and cleanup call at `0x0057af90`, and explicitly treated UID0001IA as caller/source context rather than the Deque owner.
- Opened executed match `executed-b-agent-research/B010/0004FL-SoundPathVectorReallocate-source-quality.md`: it records UID0001IA/`SoundManagerMusicDirectoryScan` as the sole `0x0057aea5` reserve caller, leaves the scanner body blank in that historical callback, and proves the called three-pointer helper is vector reserve/reallocation support rather than scanner ownership.
- Opened executed match `executed-b-agent-research/B005/0001ID-SoundPathVector-source-quality.md`: it created the exact SoundPathVector helper split, including UID0004FM at `0x0057bc60`, while recording the then-unresolved custom-container/helper interpretation. That interpretation is historical lead material superseded here by the standard-vector traits and live hidden-result ABI.
- Opened executed match `executed-b-agent-research/B003/0004FM-SoundPathStringPrepareHelper-source-quality.md`: it proves `0x0057bc60` is a `0x7c` StringBase helper with one direct caller at `0x0057abb5` in `sub_57A890`, preparing a lowercase copy before `.mp3` testing. Its older explicit-output/helper-owner source shape is historical and is corrected by this report's live call-site and `retn 4` analysis.
- Opened executed match `executed-b-agent-research/B004/0001I8-SoundManagerAudioHelperCluster-source-quality.md`: it confirms UID0000NV/`SoundManager.cpp` as the source-family route, UID0000DG as SoundManager class context, UID0001IA as an exact scanner child, and the broad audio cluster as a non-emitting index rather than the scanner's semantic owner.
- Opened executed match `executed-b-agent-research/B004/0003MM-MusicControlDialogRefreshFolderPathControl-source-quality.md`: its `ScanMusicDirectory` match is an explicit negative boundary, stating UID0003MM does not call the scanner; it contributes no direct UID0001IA body evidence.
- Legacy-archive result: none of the concrete terms matched a report under `archived/b-agent-reports-20260623`; therefore there was no matching archived path to open and no direct legacy-archive scanner report. The duplicate-loose archive also produced no direct UID0001IA/range/name report lead.
- An earlier listener-only state had no usable IDB session, so B004 paused rather than finalizing fallback evidence. After the supervisor restart, the mandatory preflight succeeded on database `c81909be`; that session was healthy when this report's live evidence was collected. This report does not assert indefinite session availability.
- Fresh MCP preflight evidence: `idb_list` returned the NexusTK IDB at `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` reported `status:ok` with auto-analysis, Hex-Rays, and string cache ready; `lookup_funcs(0x0057a890)` returned `sub_57A890`, size `0x73e`; bounded `get_bytes(0x0057afc0, 32)` succeeded.
- Prior documentation had already resolved the Deque family as non-emitting Dinkumware `std::deque` support. This pass independently applied the same source-category test to the three-pointer SoundPathVector island. The `0x00421500` callee reports the literal `vector<T> too long`, and the helper family has standard `std::vector` reserve/grow/copy/destroy/swap/erase lowering. That direct evidence supersedes the custom-container source assumption.
- During the historical report-only pass, B004 performed no by-* edit, lease, scoped validator, generated refresh, report execution, lifecycle probe, move, or archive command. During the authorized callback, B004 edited only the accepted ordinary by-* destinations under short leases, ran scoped validators, released every lease, and ran one final waited generated refresh. B004 performed no `execute_report`, lifecycle probe, move, or archive command.

## Target

- Target UID: `0001IA`.
- Historical target path observed at research time: `by-memory/0x0057a890-0x0057afcd.SoundManagerMusicDirectoryScan.md`.
- Applied UID-preserving path: `by-memory/0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `by-memory` / `Not-Covered Files - Reconstructable`; that generated row is validator-owned and is not manually edited or frozen in this report.
- Historical research-time classification: reconstructable SoundManager local-music scanner with blank formal C++, last-byte filename, `86/90`, owner/emitter UID0000NV, and `Nested:0`.
- Applied source route: `NexusTK/audio/SoundManager.cpp` through by-file UID0000NV, with direct semantic class owner UID0000DG.

## Current Target State

- Historical pre-callback metadata snapshot: `86/90`, owner/emitter UID0000NV, true, blank position/C++, `Nested:0`.
- Historical owner/emitter state conflated semantic method ownership with source-file routing; historical blank C++ carried blockers for path-entry names, local element type, vector split, and source shape.
- Historical stale assumptions were custom source-ready `Deque::DestroyOwnedEntries`, custom `SoundPathVector` methods, provisional string-cell globals, a possible narrow MusicControl caller input, explicit-output `PrepareLowercaseSoundPathString(result, source)`, and filename end `0x0057afcd` as if exclusive.
- Current implemented metadata is `92/94`, owner UID0000DG, emitter UID0000NV, true, blank position, complete managed C++, and `Nested:0` at the renamed half-open path. The queue is `std::deque<SoundPathString>`; result/member spans are `std::vector<SoundPathString>`; literals are pooled inline values; scanner input is a const reference to UTF-16 StringBase; and UID0004FM has return-by-value member hidden-result ABI.
- Related docs checked: SoundManager class/file and music-selection/audio-cluster pages; all SoundPathVector aggregate/exact-child pages; Deque class/layout/owned-destructor pages; StringBase template/file/conversion/share/COW/append pages; MusicControlDialog class and FolderPathSelected exact child; network/audio read-only data; vector throw helpers; generated metadata cache only as a stale-output check.
- Current artifact state: implementation, per-file validators, lease releases, and waited generated verification are complete with no implementation item remaining. B004 itself performed no report execution, lifecycle probe, move, or archive command; execution/count/path/move/archive state is external supervisor/validator-owned and must be read from validator history and the artifact's actual location.

## Executive Recommendation

- Implemented the target as a normal `SoundManager` member in `SoundManager.cpp`, using wide StringBase input, ANSI StringBase path entries, `std::deque` pending directories, and `std::vector` result/member paths.
- Renamed only the UID0001IA filename/heading/link end from historical last byte `0x0057afcd` to exclusive end `0x0057afce`; no split occurred. The cold `0x0057afc9` path remains inside the function, `0x0057afce-0x0057afd0` remains padding, and separate raw code begins at `0x0057afd0`.
- Applied owner UID0000DG, emitter UID0000NV, true, blank position, `Nested:0`, and `92/94`.
- Corrected UID0004FM to the shared StringBase return-by-value lowercase-copy member shape; the historical explicit `(result, source)` free-helper draft remains rejected.
- Reclassified the SoundPathVector family as non-emitting old-MSVC `std::vector<SoundPathString>` evidence and cleared only compiler-helper emitters/formal bodies while preserving binary behavior/history.
- No exact child or implementation work is deferred.

## Supervisor Active Recheck

- Historical supervisor research instruction: complete report-only UID0001IA research with mandatory live MCP, resolve deferred path-entry/helper/local/source-shape/range/C++ issues, and stop at Gate 1. Gate 1 later accepted exact SHA `A084E4D662CCA454DD65029CDF2696365E5B589E4277B8F50157A673E8DA046A`.
- Split repair: no target split is required. A UID-preserving half-open filename correction is required. The adjacent vector/deque/helper bodies remain existing exact pages and receive source-category corrections rather than new children.
- Applied source-bearing scope: UID0001IA and UID0003MI carry their complete accepted blocks; UID0004FM carries the corrected return-by-value StringBase template-member block; compiler/STL vector children have blank bodies by disposition.
- No source-bearing behavior is left as future investigation. Exact original spelling uncertainty is recorded as inference and a confidence cap, not a blank-code blocker.

## Inference Research Guidance Check

- `by-structure.md` requires method ownership under the semantic class and source routing through the file page. That makes UID0000DG the direct owner and UID0000NV the emitter.
- Existing names and classifications were treated as hypotheses. `SoundPathVector`, `PrepareLowercaseSoundPathString`, `g_strBackslashStar`, `g_strMusicExtension`, `g_strBackslash`, narrow caller conversion, and historical filename end were all rechecked against live bytes/calls/ABI.
- IDA facts are address, size, bytes, instructions, calls, xrefs, calling convention, fields, imports, and EH references. Documentation facts are existing accepted StringBase/Deque semantics and current page metadata. Inferences are human names such as `directoryPath`, `randomize`, `recursive`, `musicPaths`, `directories`, `m_localMusicPaths`, and `ToLower`.
- Historical Wave2/Wave3 terms and old generated `LObject`/custom-container scaffolds were found. They are retained only as superseded history and were not used as authority over current MCP evidence.
- The strongest source-shape inference is not based on proximity alone: the standard vector length-error literal, three-pointer layout, 1.5x growth, reserve helper, range copy/destruction, erase shift, automatic cleanup, and existing project-wide Dinkumware classifications converge on `std::vector`.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best resolution | Evidence | Status |
| --- | --- | --- | --- |
| Function end | Half-open `0x0057a890-0x0057afce`; rename path end to `afce`. | IDA size `0x73e`; byte `0x57afcd` is inside final call displacement; `0x57afce-0x57afd0` is `cc cc`. | Direct fact. |
| Return/signature | `void` SoundManager member; UTF-16 StringBase const-reference plus `bool randomize`, `bool recursive`. | `retn 0Ch`; two caller argument orders; input dereferenced as wide StringBase and converted through `0x5825a0`. | Direct ABI plus inferred names. |
| Empty input | Clear `m_localMusicPaths`, then return. | Both nonempty and empty branches destroy/reset `+0x1028/+0x102c`; source normalization is one initial `clear()`. | Direct behavior. |
| Path-entry type | ANSI `mystr::StringBase<char, mystr::mychar_traits<char> >`. | Wide-to-ANSI helper `0x5825a0`; four-byte entry copies/releases; ANSI suffix and CRT lowercase helpers. | Direct type-family fact. |
| Queue | `std::deque<SoundPathString>`. | Five-field old Dinkumware layout, 4-entry blocks, `_Growmap`, typed destruction, current final Deque audit. | Direct/documented. |
| Result/member container | `std::vector<SoundPathString>`, not a custom class. | Three pointers; `vector<T> too long`; 1.5x growth; reserve/reallocate; push_back; erase shift; swap; Dinkumware cleanup. | Direct plus strong inference. |
| Lowercase helper | StringBase member-like lowercase-copy operation, source-facing `ToLower`. | Caller sets `ecx=fileName`, pushes hidden destination; target copies from saved `ecx`, mutates destination, returns it, `retn 4`. | ABI fact; name inferred. |
| Literal cells | Inline pooled `"\\*"`, `".mp3"`, `"/"`; not source globals. | Contiguous bytes at `0x62cee0`; only target xrefs; direct literal use pattern. | Direct/inferred source form. |
| Find handle | Preserve absence of `FindClose`. | Target calls FindFirst/FindNext; FindClose IAT has only CRT wildcard xref at `0x5ef9d4`; no target/EH close. | Direct negative fact. |
| Folder callback | Pass `path.c_str()` to a temporary wide scanner argument; remove narrow `std::string`. | Caller invokes wide c_str, `0x582560` wide-from-raw construction, scanner call, then wide destructor. | Direct fact/source inference. |
| Randomization | Repeated `rand() % size`, append selected entry, erase it. | Exact loop and assignment/destruction sequence. | Direct fact. |
| Nonrandom path | `m_localMusicPaths.swap(musicPaths)`. | Three pointer-triplet exchanges. | Direct fact. |
| Security/EH | Compiler SEH, cookie, local destructors, vector length throw remain generated. | Prologue/epilogue, `__security_check_cookie`, EH funclets `0x608401-0x608504`. | Direct fact. |
| Nested | Retain `0`; this field is relative nesting delta, not child count. | Neighboring address-sorted pages and no cumulative nesting transition at this exact row. | Documentation-rule application. |

Rejected alternatives:

- Keep blank C++ because exact names are absent: rejected; names are inferential confidence caps, while behavior/types/source shape are resolved.
- Emit custom `SoundPathVector` implementations: rejected by direct `vector<T> too long` and standard helper morphology.
- Restore custom `Deque::DestroyOwnedEntries`: rejected by the completed Deque full-family audit.
- Add `FindClose`: rejected because it changes observed binary behavior; the missing close is a source-level leak that reconstruction must preserve.
- Use `std::string` or `const char *` scanner input: rejected; both callers supply wide StringBase objects and the scanner itself performs the ANSI conversion.
- Pass FolderPathSelected's `path` directly: weaker than the observed source shape because binary calls wide `c_str`, constructs a temporary wide StringBase, calls the scanner, and destroys that temporary.
- Keep explicit `PrepareLowercaseSoundPathString(result, source)`: rejected by the thiscall plus hidden-result ABI.
- Treat the three literals as named globals: rejected by pooled adjacency and single-function xrefs.
- Extend the function through `0x57afed`, `0x57afd0`, or `0x57b020`: rejected by the exact function size, padding, and successor code boundaries.

## Evidence Standards Used

- Primary: live IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `decompile`, `disasm`, `callees`, `xrefs_to`, and `imports_query` against database `c81909be`.
- Secondary: current by-* docs, current validator metadata cache as a stale-emission inventory only, executed B-agent reports as historical evidence leads, and exported Ghidra/IDA records as independent ABI corroboration.
- Negative evidence: no target FindClose xref/call; no endpoint xrefs; no separate function at `0x57afce`/`0x57afd0`; no non-audio scanner callers; no evidence that literal cells are source globals; no source need for custom vector/deque methods.
- Evidence ladder: direct code/bytes/calls outrank generated names and historical prose. Standard-library classification requires multiple converging implementation traits, not a single naming guess; those traits are present here.
- Tool limitation: no PDB/source symbols prove exact original identifiers. This limits name confidence only and does not block the complete source-shaped draft.

## Evidence Checked

- IDA MCP/manual checks: target range/prototype/decompile/disassembly; end bytes and successor boundary; string bytes/xrefs; caller decompiles at `0x579a30` and `0x529ee0`; helper decompile/disassembly at `0x57bc60`; vector throw helper at `0x421500`; import/xrefs for FindFirstFileA, FindNextFileA, and FindClose; direct target callers/callees; EH cleanup addresses.
- Documentation checks: target; SoundManager class/file/music-selection/audio-cluster/playback pages; every SoundPathVector aggregate/exact child; Deque class/layout/destructor pages; StringBase template/file/helper families; MusicControlDialog class/FolderPathSelected; read-only data; MsvcVectorThrowHelpers; project structure/workflow/template.
- Old-report search terms checked verbatim: `UID0001IA`; `0x0057a890|0x0057afce`; `SoundManagerMusicDirectoryScan|ScanMusicDirectory`; `SoundPathVector`; `UID0004FM|0x0057bc60`; and `UID0000NV|UID0000DG|SoundManager.cpp|SoundManager source`.
- Reports active when searched: `tools/leaser/Agents/Agent-B004/research/0001IA-SoundManagerMusicDirectoryScan-source-quality.md` was the sole matching then-active path and was only the current-report self-hit. Searches across the other then-active B-agent research paths returned no direct UID0001IA report.
- Executed report opened: `executed-b-agent-research/B003/000149-DequePushBack-empty-emitter-source-quality.md`; finding: UID0001IA is only a support caller reference through UID0001IE, not a direct scanner analysis.
- Executed report opened: `executed-b-agent-research/B002/0001IE-DequeDestroyOwnedEntries-source-quality.md`; finding: `0x0057a890` constructs ANSI path strings, uses the local Deque for recursive directories, and calls typed cleanup at `0x0057af90`; scanner ownership/body remained out of scope.
- Executed report opened: `executed-b-agent-research/B010/0004FL-SoundPathVectorReallocate-source-quality.md`; finding: `0x0057aea5` is the scanner's vector-reserve call, and the old callback updated only caller support while UID0001IA formal C++ remained blank.
- Executed report opened: `executed-b-agent-research/B005/0001ID-SoundPathVector-source-quality.md`; finding: the split inventory created UID0004FM/`0x0057bc60` and exact vector children but left their custom source-category assumptions provisional, requiring this report's independent standard-container and helper-ABI reanalysis.
- Executed report opened: `executed-b-agent-research/B003/0004FM-SoundPathStringPrepareHelper-source-quality.md`; finding: one scanner call at `0x0057abb5`, four StringBase-family callees, lowercase mutation, and `.mp3` use are valid leads; its older source-facing signature/owner inference is superseded by current live ABI evidence.
- Executed report opened: `executed-b-agent-research/B004/0001I8-SoundManagerAudioHelperCluster-source-quality.md`; finding: UID0001IA is an exact SoundManager scanner child, UID0000NV is the `SoundManager.cpp` file route, and the broad audio aggregate is not an emitter or direct method owner.
- Executed report opened: `executed-b-agent-research/B004/0003MM-MusicControlDialogRefreshFolderPathControl-source-quality.md`; finding: the scanner name occurs only to reject scanner ownership/call behavior for UID0003MM, so it is not a direct UID0001IA research report.
- Archive reports checked: the complete concrete term set returned no match under `archived/b-agent-reports-20260623` or `archived/duplicate-loose-b-agent-reports`, so no matching archive report path existed to open. Combined with the then-active self-hit result, this is an explicit no-direct-prior-report result for UID0001IA/range/scanner-name research.
- Negative checks: searched all ordinary by-* references to the historical target path; checked the FindClose IAT and all xrefs; checked target/successor function starts; checked whether helper `0x57bc60` accepts two explicit source parameters; checked whether vector helpers call the shared standard throw path.
- Intentionally skipped: implementation validators, generated refresh, leases, IDA mutation/save, and lifecycle commands are forbidden before Gate 1. No fallback-only conclusion was used.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Target exclusive end is `0x0057afce`; historical filename used last byte. | 99 | `lookup_funcs`, end bytes, successor checks | UID0001IA path/heading/range | Rename UID-preservingly and update links. | Applied; validator `9491` performed path update plus 12 source-path and 28 UID-link updates. |
| C02 | `0x57afce-0x57afd0` is padding; `0x57afd0` is separate raw code. | 99 | bytes/disassembly/no-start checks | UID0001IA boundary sections; UID0001I8 | Preserve exclusion. | Applied in target and UID0001I8; validators `9491`/`9497`, exact boundary prose retained. |
| C03 | Direct owner UID0000DG; emitter UID0000NV; true/blank position/`Nested:0`. | 96 | class method/source route/by-structure | UID0001IA metadata | Apply exact metadata. | Applied; target validator `9491` reports owner/metadata update, generated UID0001IA route is UID0000NV. |
| C04 | Target score should be `92/94`. | 94 | blocker resolution and evidence breadth | UID0001IA metadata/rationale | Raise `86/90 -> 92/94`. | Applied and verified by `9491`; generated annotation reports `92/94`. |
| C05 | Signature is void, wide StringBase const-ref, randomize, recursive. | 97 | ABI and callers | UID0001IA formal/status | Insert exact signature. | Applied in exact target block; `9491` and generated `9534` verify one body. |
| C06 | Clear member vector first; empty input returns. | 99 | target control flow | UID0001IA formal/behavior | Apply. | Applied in exact target body; `9491`/`9534`. |
| C07 | Convert wide root path to ANSI SoundPathString once. | 98 | `0x5825a0` | UID0001IA formal/types | Apply. | Applied as `SoundPathString rootDirectory(directoryPath)`; `9491`/`9534`. |
| C08 | Pending directories use typed `std::deque<SoundPathString>`. | 98 | layout/cleanup/full-family audit | UID0001IA formal; Deque support | Apply; remove custom method wording. | Applied in target and UID0001IE concrete-type support; `9491`/`9526`. |
| C09 | Enumeration search is `currentDirectory + "\\*"`. | 99 | literal/xref/call sequence | UID0001IA formal | Apply. | Applied in exact target body; `9491`/`9534`. |
| C10 | File filter lowercases a copy and tests `.mp3`. | 98 | helper ABI and suffix call | UID0001IA/UID0004FM | Apply member-shaped operation. | Applied in target and exact UID0004FM member block; `9491`/`9521`/`9534`. |
| C11 | Accepted music entries must not be directories. | 99 | attribute bit branch | UID0001IA formal | Apply. | Applied in exact target body; `9491`/`9534`. |
| C12 | Recursion requires flag, non-dot-leading name, and directory bit. | 99 | exact branch sequence | UID0001IA formal | Apply. | Applied in exact target body; `9491`/`9534`. |
| C13 | Both accepted files and subdirectories join with `/`; loop uses FindNextFileA. | 99 | two slash xrefs and import call | UID0001IA formal | Apply. | Applied exactly; target validator `9491`, generated proof `9534`. |
| C14 | Original scanner does not call FindClose. | 99 | IAT xrefs/callees/EH negative check | UID0001IA behavior/negative/formal | Preserve omission explicitly in prose. | Applied and preserved in target evidence/formal body; no `FindClose` added, `9491`/`9534`. |
| C15 | Result/member containers are `std::vector<SoundPathString>`. | 98 | vector literal/layout/helper family | UID0001IA; SoundPathVector family | Replace custom source API. | Applied in target plus all vector documentation pages; `9491`, `9500`, `9502`, `9505`, `9508`, `9510`, `9512`, `9514`, `9516`, `9518`, `9519`. |
| C16 | Reserve member capacity to result count before branch. | 99 | `0x57aea5` and length guard | UID0001IA formal | Use `reserve`. | Applied in exact target body; `9491`/`9534`. |
| C17 | Random path repeatedly appends random entry then erases it. | 99 | rand/mod/copy/shift/destroy loop | UID0001IA formal | Apply. | Applied with unseeded `rand() % size`; `9491`/`9534`. |
| C18 | Nonrandom path swaps vector storage. | 99 | three pointer swaps | UID0001IA formal | Use `swap`. | Applied in exact target body; `9491`/`9534`. |
| C19 | SEH/cookie/local cleanup is compiler output, not handwritten source. | 99 | prologue/epilogue/funclets | UID0001IA EH notes | Preserve as evidence only. | Applied; preserved in target evidence/history and excluded from formal C++; `9491`/`9534`. |
| C20 | `\\*`, `.mp3`, `/` are pooled literals, not globals. | 98 | contiguous bytes/single target xrefs | UID0001IA; UID read-only-data | Correct names/roles. | Applied in target and UID00026I with exact bytes/xrefs; `9491`/`9531`. |
| C21 | `+0x1028` is local music vector; `+0x109c` is zone tracks, distinct. | 97 | scanner and music-selection callers | SoundManager class/file/selection | Synchronize typed fields. | Applied without support-score inflation; `9492`, `9494`, `9495`. |
| C22 | Only direct callers are constructor and FolderPathSelected. | 99 | xrefs/decompiles | UID0001IA caller inventory | Record. | Applied; preserved in target caller inventory; `9491`. |
| C23 | Folder caller builds a wide temporary from `path.c_str()`, not a narrow string. | 98 | c_str/`0x582560`/call/destructor | UID0003MI managed block | Replace exact block. | Applied in exact UID0003MI block; `9528`; generated output has no `narrowPath`/`ToNarrowPath`. |
| C24 | SoundManager class/file own policy and source route, not STL bodies. | 97 | source structure/callers | by-class/by-file SoundManager | Synchronize detail, scores unchanged. | Applied in class/file docs; `9492`/`9494`, scores unchanged. |
| C25 | Audio aggregate row end `0x57afed` is stale. | 99 | function size/boundary | UID0001I8 | Correct row to `0x57afce`; score unchanged. | Applied; validator `9497`, aggregate score unchanged. |
| C26 | MusicSelection references renamed target and typed local vector. | 98 | field/caller evidence | UID0001I7 | Update link/detail; score unchanged. | Applied; validator `9495`, score unchanged. |
| C27 | PlaybackControls predecessor link must use renamed target. | 99 | adjacent boundary | UID0001I9 | Update link only. | Applied; validator-propagated link confirmed by `9499`. |
| C28 | Deque owned-destructor page must link renamed target; classification stays final. | 99 | current Deque audit | UID0001IE | Link/source-cause sync only. | Applied concrete `SoundPathString`/renamed link; `9526`, final `92/95` false/blank retained. |
| C29 | SoundPathVector class is a non-emitting `std::vector` documentation projection. | 97 | helper morphology and throw literal | UID0000DI | Set false/blank and update status; `91/95`. | Applied and verified by `9500`: `91/95`, false, blank emitter/C++. |
| C30 | SoundPathVector aggregate remains non-emitting and records standard-vector cause. | 98 | full exact-child island | UID0001ID | Preserve false/blank; raise detail/score `92/95`. | Applied and verified by `9502`: `92/95`, false/blank. |
| C31 | GrowAndInsert is compiler vector push/insert slow path. | 98 | 1.5x growth/calls/throw | UID0004FJ | Set false/blank; `91/95`. | Applied and verified by `9505`: `91/95`, false/blank. |
| C32 | Destructor is compiler vector destructor lowering. | 98 | automatic/member destructor contexts | UID0004FK | Set false, clear emitter/C++; `92/95`. | Applied and verified by `9508`: `92/95`, false/blank. |
| C33 | ChangeArray is internal vector storage commit. | 98 | grow/reserve callers | UID0004FN | Set false, clear emitter/C++; `91/95`. | Applied and verified by `9510`: `91/95`, false/blank. |
| C34 | Reallocate is compiler `reserve` lowering. | 99 | sole reserve caller/throw family | UID0004FL | Set false, clear emitter/C++; `92/95`. | Applied and verified by `9514`: `92/95`, false/blank. |
| C35 | DestroyRange is compiler EH cleanup. | 99 | sole cleanup xref | UID0004FO | Set false/blank; `90/94`. | Applied and verified by `9512`: `90/94`, false/blank. |
| C36 | CopyConstructRange is compiler uninitialized-copy support. | 98 | grow callers/EH | UID0004FP | Set false, clear emitter/C++; `91/94`. | Applied and verified by `9516`: `91/94`, false/blank. |
| C37 | CopyConstructRangeTail is compiler append-copy support. | 98 | sole grow caller/EH | UID0004FQ | Set false/blank; `90/94`. | Applied and verified by `9518`: `90/94`, false/blank. |
| C38 | Clear is compiler `std::vector::clear` lowering. | 99 | two member callers and standard layout | UID0001IF | Set false, clear emitter/C++; `92/95`. | Applied and verified by `9519`: `92/95`, false/blank. |
| C39 | UID0004FM is a source-authored StringBase lowercase-copy member with hidden result. | 98 | thiscall disassembly/caller | UID0004FM | Owner/emitter 0001WS, true, exact member block, `92/94`. | Applied; `9521` records owner/emitter `0001WS`, `92/94`, exact block; generated by `9534`. |
| C40 | Shared StringBase docs need `ToLower` member-shape inventory and audio instantiation evidence. | 94 | helper ABI/StringBase primitives | UID0001WS, UID0000OA | Sync prose, scores/formal aggregate unchanged. | Applied without score/formal inflation; validators `9523`/`9525`. |
| C41 | UID0002E1 already proves standard vector throw support. | 99 | literal and broad fan-in | UID0002E1 | Reference only; unchanged. | Re-read and retained unchanged as accepted reference-only dependency; no edit/validator required. |
| C42 | Read-only data page must classify all three cells as pooled literals. | 98 | bytes/xrefs | UID00026I | Add exact roles; score unchanged. | Applied with exact bytes/xrefs/source-global rejection; `9531`, score unchanged. |
| C43 | MusicControlDialog class must remove narrow-conversion claim. | 98 | caller decompile | UID00008U | Sync caller signature/detail; score unchanged. | Applied in UID0003MI/class support; `9528`/`9530`, scores unchanged. |
| C44 | Source placement is SoundManager.cpp; STL/StringBase template code is header/compiler-owned. | 97 | source route and link-order evidence | target/support source sections | Apply distinction. | Applied across target, SoundManager, vector, and StringBase routes; validators `9491`-`9531`; generated routes verified by `9534`. |
| C45 | Preserve rejected alternatives, historical custom-container state, and no-FindClose evidence. | 99 | audit requirements | every changed page | Additive historicalization, no compression. | Applied additively across all 23 destinations; old custom/narrow/global/body alternatives remain explicitly historical/rejected. |
| C46 | Callback requires one scoped validator per changed by-* page and final waited generated verification. | 99 | workflow | report checklist/results | Run only after Gate 1 callback. | Completed: 23 scoped validators `9491`-`9531`, immediate releases, then waited generated command `9534` completed. |

## Positive Evidence Summary

- `sub_57A890` is one exact `0x73e` SoundManager method with two direct callers, a wide StringBase input, two boolean arguments, and void return.
- The body directly realizes a coherent source algorithm: clear prior paths, convert root path to ANSI, breadth/depth scan through a deque, filter lowercase `.mp3` non-directories, optionally queue subdirectories, reserve, random-extract or swap, then automatic cleanup.
- `0x421500 -> "vector<T> too long"` plus the three-pointer helper family is direct standard-vector evidence. Current Deque docs provide an already-audited parallel standard-container classification.
- UID0004FM's caller/target registers prove a member-like copy-to-lower operation: source in `ecx`, hidden result on stack, return object in `eax`, `retn 4`.
- Both callers establish the argument semantics and wide input: constructor passes config local-music path plus randomize flag and `true`; FolderPathSelected creates a temporary wide StringBase and passes the same flag/`true`.
- Exact literal bytes and xrefs support the human expressions without invented globals.

## IDA MCP Facts

- Function/range: `lookup_funcs(0x0057a890)` returned `sub_57A890`, size `0x73e`; exclusive end `0x0057afce`. `0x0057afcd` is inside the final call displacement. `0x0057afce-0x0057afd0` is `cc cc`.
- Entry/exit: compiler SEH registration, `0x198` local allocation, cookie setup; normal cleanup at `0x57af90/0x57af9b/0x57afa6`; cookie check at `0x57afbe`; `retn 0Ch` at `0x57afc6`; cold vector-length call at `0x57afc9` through the exclusive end.
- Predecessor/successor: predecessor ends `0x57a88e`, followed by two `cc` bytes. Separate raw code begins `0x57afd0`, ends before padding and modeled function `0x57b020`.
- String bytes: `0x62cee0` contains `5c 2a 00 00 2e 6d 70 33 00 00 00 00 2f 00 00 00`, encoding `\\*`, `.mp3`, `/`.
- Literal xrefs: `0x62cee0` at `0x57ab3e`; `0x62cee4` at `0x57abc1`; `0x62ceec` at `0x57ac32` and `0x57ad16`; all are target-local.
- Imports: FindFirstFileA IAT `0x60d1a8`, target xref `0x57ab5f`; FindNextFileA IAT `0x60d1ac`, target xref `0x57ae47`; FindClose IAT `0x60d2f8`, only xref `0x5ef9d4` in CRT wildcard expansion, none from target.
- Lower helper call site: `0x57aba4` loads destination; `0x57abae` pushes it; `0x57abaf` loads source fileName into `ecx`; `0x57abb5` calls `0x57bc60`; returned object is tested against `.mp3` and destroyed immediately.
- Lower helper body: saves incoming `ecx` as source, loads stack `arg_0` as destination, share/copy constructs destination, detaches it, lowercases `data` with `length+1`, returns destination, and `retn 4`.
- Vector proof: `decompile(0x421500)` is noreturn `sub_5C5EAC("vector<T> too long")`; target/vector helpers call it on max-size paths.
- EH: external cleanup funclets `0x608401`, `0x60840c`, `0x608417`, `0x608422`, `0x60842d-0x6084fe`, and frame handler `0x608504` correspond to automatic vector/string/deque/temporary cleanup.
- IDA database changes: none. B004 used read-only queries and did not rename, type, comment, save, start, stop, restart, or manage MCP/IDA processes.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Recommended score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x57a890-0x57afce` | UID0001IA renamed target | SoundManager scan policy | true | UID0000DG, emitter UID0000NV | `92/94` | Source-ready. |
| `0x57b860-0x57b99a` | UID0004FJ | `std::vector<SoundPathString>` grow/insert slow path | false | UID0000DI documentation group | `91/95` | Compiler/STL, blank. |
| `0x57b9e0-0x57baa3` | UID0001IE | `std::deque<SoundPathString>` destructor | false | UID00003P | `92/95` unchanged | Already final non-emitting. |
| `0x57bac0-0x57bb2a` | UID0004FK | vector destructor | false | UID0000DI | `92/95` | Clear custom emitter. |
| `0x57bc60-0x57bcdc` | UID0004FM | StringBase lowercase-copy member instantiation | true | UID0001WS | `92/94` | Source-ready return-by-value member. |
| `0x57bce0-0x57bd53` | UID0004FN | vector storage commit | false | UID0000DI | `91/95` | Compiler/STL, blank. |
| `0x57bd60-0x57bd84` | UID0004FO | vector EH destroy range | false | UID0000DI | `90/94` | Compiler/STL, blank. |
| `0x57bd90-0x57be52` | UID0004FL | vector reserve/reallocate | false | UID0000DI | `92/95` | Compiler/STL, blank. |
| `0x57be60-0x57becf` | UID0004FP | vector copy-construct range | false | UID0000DI | `91/94` | Compiler/STL, blank. |
| `0x57bed0-0x57bf3e` | UID0004FQ | vector append-copy tail | false | UID0000DI | `90/94` | Compiler/STL, blank. |
| `0x57bf40-0x57bf6e` | UID0001IF | vector clear | false | UID0000DI | `92/95` | Compiler/STL, blank. |

No new child is required. UID0001ID remains the non-emitting range index, now with corrected standard-vector source-category wording.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x579c8c` | SoundManager constructor -> target | Initial scan of config local-music path; config randomize byte; recurse `true`. |
| `0x529fd8` | MusicControlDialog::FolderPathSelected -> target | Rescan after changed path using a temporary wide StringBase, config randomize byte, recurse `true`. |
| `0x57ab5f` | target -> FindFirstFileA | Opens each `directory + "\\*"` search. |
| `0x57ae47` | target -> FindNextFileA | Advances enumeration. |
| none | target -> FindClose | Deliberate reconstruction omission required by binary. |
| `0x57abb5` | target -> UID0004FM | Lowercase copy of filename before suffix test. |
| `0x57acab`, `0x57aef5` | target -> vector grow slow path | `push_back` full-capacity lowering. |
| `0x57aea5` | target -> vector reallocate | `reserve(musicPaths.size())` lowering. |
| `0x57af90` | target -> deque destructor | Automatic `std::deque<SoundPathString>` cleanup. |
| `0x57afa6` | target -> vector destructor | Automatic local result-vector cleanup after swap/random extraction. |

## Documentation Evidence And IDA Status

- Supporting current docs: DequeLayout/Deque/UID0001IE already identify standard Dinkumware source cause; StringBase docs resolve wide/ANSI construction, copy, assignment, detach, data, length, suffix, append, and destruction; SoundManager docs resolve the two member vector offsets and source route.
- Contradicted docs: UID0001IA's custom Deque and unresolved-vector wording; UID0000DI and compiler-child custom class/method emitters; UID0004FM's explicit output-pointer free helper; UID0003MI's narrow `std::string`; UID0001I8's `0x57afed` row; all historical `afcd` links.
- Generated/coverage state: pre-callback generated source was treated as read-only evidence that could lag. Authorized validator command `9534` later completed the generated refresh; B004 inspected output read-only and manually edited no generated or coverage file.
- MCP status: database `c81909be` was healthy during evidence collection and handled bounded target, caller, helper, byte, import, and xref queries successfully. No assertion is made about availability after evidence time.

## Ranked Ownership Analysis

### 1. SoundManager class UID0000DG with SoundManager.cpp emitter UID0000NV

- Evidence for: thiscall receiver; fields `+0x1028`; constructor and MusicControl caller; local-music policy; exact method naming family; existing source route.
- Evidence against: none for the policy body. STL and StringBase helpers are dependencies, not owned child methods.
- Decision: canonical owner UID0000DG, emitter UID0000NV.

### 2. SoundManager file UID0000NV as both owner and emitter

- Evidence for: current metadata and correct translation unit.
- Evidence against: conflates semantic class ownership with routing and differs from source-ready exact SoundManager method convention.
- Decision: retain only as emitter/source root.

### 3. SoundPathVector, Deque, or StringBase as target owner

- Evidence for: helper bodies and local container/string operations appear in the call graph.
- Evidence against: none owns scan policy, recursion, Win32 enumeration, filtering, randomization, or SoundManager field selection. Vector/deque bodies are standard-library lowering; StringBase owns primitive operations only.
- Decision: rejected for target ownership.

### Proposed new file/grouping, if applicable

- No new source file or by-* child. Reclassify existing SoundPathVector pages in place as a documentation grouping for `std::vector<SoundPathString>` binary instantiations caused by SoundManager source.
- Keep `NexusTK/audio/SoundManager.cpp` for the target. Keep `std::vector`/`std::deque` declarations in standard headers and StringBase lowercase member semantics in the shared StringBase template/header route.

## Source Placement

- Target placement: `NexusTK/audio/SoundManager.cpp`, member of `SoundManager`.
- SoundManager class/header placement: declare the method and member fields as wide StringBase input and `std::vector<SoundPathString>` storage.
- Standard container implementation bodies: compiler/STL generated from `<vector>` and `<deque>` operations in consumer source; no custom `SoundPathVector.cpp` or `Deque.cpp`.
- Lowercase-copy operation: shared StringBase template/header member semantics. Its binary placement next to SoundManager is consistent with template instantiation in the consuming translation unit and does not prove SoundPathVector ownership.
- Rejected placement: generic container source, StringBase.cpp for the scan policy, MusicControlDialog for the scan, or an aggregate audio helper body.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `[0x0057a890, 0x0057afce)`, size `0x73e`.
- Historical filename `...afcd` encoded the final included byte, not the repository's half-open end convention. Rename the target path and heading without changing UID.
- Pre-padding: `0x0057a88e-0x0057a890` is `cc cc` after UID0001I9.
- Post-padding: `0x0057afce-0x0057afd0` is `cc cc`.
- Successor: raw SoundManager audio reinit/music-mode bridge `0x0057afd0-0x0057b011`, then padding, then modeled `0x0057b020`.
- Target split: none. Cold vector length-error path at `0x57afc9-0x57afce` belongs to target compiler lowering.
- Support reclassification: UID0000DI/UID0001ID and vector exact children become standard-library documentation evidence. UID0004FM moves to source-authored StringBase template ownership with corrected member ABI. No range is merged or deleted.
- Parent/container impact: UID0001I8 corrects scanner row `0x0057a890-0x0057afed` to `0x0057a890-0x0057afce`; its non-emitting aggregate disposition remains unchanged.

## Negative Evidence Summary

- No target xref to FindClose and no hidden cleanup closes the handle. The only FindClose IAT xref is unrelated CRT wildcard code.
- No modeled function begins at `0x57afce` or `0x57afd0`; no xref targets either boundary as target continuation.
- No caller supplies ANSI input. Both caller paths originate in UTF-16 StringBase storage.
- No evidence supports named source globals for the three pooled literal cells.
- No non-SoundManager policy caller or non-audio field use supports moving the scan.
- No PDB/source symbol proves `ToLower`, `directoryPath`, `musicPaths`, or `m_localMusicPaths`; those names remain explicitly inferred.
- No evidence supports a handwritten custom vector class once the standard throw literal and helper morphology are considered together.
- Nearby helper placement alone does not prove source ownership; template instantiations are emitted in consumer translation units.
- Historical generated `LObject`, custom Deque, and custom SoundPathVector output is not source evidence and must not be preserved as current truth.

## IDA Rename / Type / Comment Recommendations

- Safe source-facing IDA name after supervisor approval: `SoundManager::ScanMusicDirectory` for `0x0057a890`.
- Recommended prototype: void thiscall SoundManager member with const UTF-16 StringBase reference, bool randomize, bool recursive. Exact IDA syntax should follow existing project type names rather than inventing an `_DWORD *` facade.
- Recommended helper semantic at `0x0057bc60`: ANSI StringBase lowercase-copy member, source-facing `ToLower` or equivalent; mark the name inferred.
- Recommended data comments: `0x62cee0` pooled directory wildcard `"\\*"`; `0x62cee4` pooled lowercase MP3 suffix `".mp3"`; `0x62ceec` pooled path separator `"/"`.
- Intentionally unchanged in IDA: during the historical report-only phase, no rename/type/comment, process management, or save was performed; the callback likewise made no IDA mutation.

## First-Draft C++ Recommendation

- Eligible: yes. All source-shape blockers are resolved.
- Exact target managed block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
typedef mystr::StringBase<char, mystr::mychar_traits<char> > SoundPathString;

void SoundManager::ScanMusicDirectory(
    const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > &directoryPath,
    bool randomize,
    bool recursive)
{
    m_localMusicPaths.clear();

    if (directoryPath.length() == 0)
        return;

    std::vector<SoundPathString> musicPaths;
    SoundPathString rootDirectory(directoryPath);
    std::deque<SoundPathString> directories;
    directories.push_back(rootDirectory);

    while (!directories.empty()) {
        SoundPathString currentDirectory;
        currentDirectory = directories.front();
        directories.pop_front();

        WIN32_FIND_DATAA findData;
        SoundPathString searchPath = currentDirectory + "\\*";
        HANDLE findHandle = FindFirstFileA(searchPath.c_str(), &findData);

        if (findHandle != INVALID_HANDLE_VALUE) {
            do {
                SoundPathString fileName(findData.cFileName);

                if (fileName.ToLower().EndsWithAnsi(".mp3") &&
                    (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
                    musicPaths.push_back(currentDirectory + "/" + fileName);
                }

                if (recursive &&
                    fileName.c_str()[0] != '.' &&
                    (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0) {
                    directories.push_back(currentDirectory + "/" + fileName);
                }
            } while (FindNextFileA(findHandle, &findData));
        }
    }

    m_localMusicPaths.reserve(musicPaths.size());

    if (randomize) {
        while (!musicPaths.empty()) {
            const std::vector<SoundPathString>::size_type index =
                rand() % musicPaths.size();
            m_localMusicPaths.push_back(musicPaths[index]);
            musicPaths.erase(musicPaths.begin() + index);
        }
    } else {
        m_localMusicPaths.swap(musicPaths);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact corrected UID0003MI managed block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MusicControlDialog::FolderPathSelected(const String& path)
{
    if (path.empty())
        return;

    if (g_pConfig->localMusicPath == path)
        return;

    g_pConfig->localMusicPath = path;
    SetControlText(kControlMusicFolderPath, path);
    ResetTextSelection(kControlMusicFolderPath, 0, 0);

    g_pSoundManager->ScanMusicDirectory(
        path.c_str(),
        g_pConfig->randomizeMusicOrder != 0,
        true);

    ApplyPlaybackState();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact corrected UID0004FM managed block:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace mystr {

template <>
StringBase<char, mychar_traits<char> >
StringBase<char, mychar_traits<char> >::ToLower() const
{
    StringBase<char, mychar_traits<char> > result(*this);

    result.DetachAnsiIfShared();
    _strlwr_s(result.data(), result.length() + 1);

    return result;
}

}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0000DI, UID0001ID, UID0004FJ/4FK/4FN/4FO/4FL/4FP/4FQ, and UID0001IF now have exactly blank managed multiline bodies after reclassification. Their behavior is regenerated from target/SoundManager typed source and standard headers; no compiler lowering was retained as replacement C++.
- Exact behavior preservation: no FindClose is added; wide input converts to ANSI once; suffix testing lowercases a copy; dot-prefixed directories are excluded only from recursion; `/` remains the join separator; random extraction uses unseeded global `rand`; reserve precedes both final paths; nonrandom mode swaps; automatic destructors regenerate cleanup/EH.
- Period plausibility: C++03-era `std::vector`, `std::deque`, Win32 `FindFirstFileA`/`FindNextFileA`, project StringBase, typedef, explicit loops, and `rand` match the old MSVC/Dinkumware binary.
- Inferred names: `SoundPathString`, `directoryPath`, `randomize`, `recursive`, `musicPaths`, `rootDirectory`, `directories`, `currentDirectory`, `searchPath`, `findData`, `findHandle`, `fileName`, `m_localMusicPaths`, and `ToLower` are source-facing inference, not symbol proof.
- Coding convention: braces and control flow follow current reconstructed NexusTK C++ pages; no decompiler variables, offsets, raw helpers, reverse-engineering comments, or ABI scaffolding appear in formal output.
- Third-party import directive: not applicable; this is NexusTK project source using standard/compiler libraries, not a staged static third-party embed.

## Final Recommendation

- C01-C46 were applied without compressing evidence.
- Target result: exclusive-end path, `92/94`, owner UID0000DG, emitter UID0000NV, true, blank position, `Nested:0`, exact Item Summary/status/evidence/negative/history, and exact managed scanner block.
- Support result: corrected MusicControl caller block; reclassified all custom SoundPathVector compiler children; corrected UID0004FM ABI/owner/disposition; synchronized SoundManager/StringBase/read-only-data/aggregate/link pages.
- UID0001IE and the broader Deque family remain non-emitting with scores unchanged; only renamed-link and concrete source-type wording changed.
- Items left non-emitting: all standard vector/deque helper bodies. Their exact binary evidence remains documented, but human source is typed container use. UID0004FM remains emitting source-authored StringBase template behavior through UID0001WS.
- Future work outside assignment: none required for UID0001IA source quality. Exact original spellings may improve if symbols/source are ever found, but they do not block implementation.

## Recommended Target Doc Changes

The following Gate-1-accepted target changes are implemented and verified by scoped validator `000000009491` plus waited generated command `000000009534`:

- Rename `by-memory/0x0057a890-0x0057afcd.SoundManagerMusicDirectoryScan.md` to `by-memory/0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan.md`, preserving UID0001IA.
- Metadata: `92/94`, owner `0000DG`, true, emitter `0000NV`, blank position, `Nested:0`.
- Replace blank managed C++ with the exact target block above.
- Replace stale Item Summary with archive-neutral current detail: source-ready SoundManager local-music scan; exact half-open range; wide input/ANSI entries; standard vector/deque; recursion/filter/random/swap; no FindClose; compiler cleanup excluded from source.
- Rewrite Status/Behavior/Evidence/Ownership/Score sections at report-level detail, preserving historical `86/90`, custom-container assumptions, prior sessions as historical, and all rejected alternatives.
- Do not retain statements that path-entry type, vector split, helper source shape, or final C++ remain unresolved.

## Recommended Support Doc Changes

The following Gate-1-accepted support changes are implemented. The table remains the exact accepted destination contract and is reconciled claim by claim in the ledger and Validator Results.

| Support path | Exact changes | Score/metadata |
| --- | --- | --- |
| `by-class/SoundManager.md` | Update target link/range/signature; type `m_localMusicPaths` and `m_zoneMusicTracks` as standard vectors of ANSI StringBase; record policy/STL split and no-FindClose. | Score unchanged. |
| `by-file/SoundManager.md` | Update target link; record source-ready scanner and compiler-generated container instantiations; remove UID0004FM/SoundPathVector custom-emitter current claims. | Score unchanged. |
| `by-memory/0x005797b0-0x0057a25c.SoundManagerMusicSelection.md` | Update target link and typed local vector wording. | Score unchanged. |
| `by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md` | Correct scanner row end `0x57afed -> 0x57afce`; update target link and standard-container support disposition. | Score unchanged. |
| `by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md` | Update successor target link to renamed path. | Score unchanged. |
| `by-class/SoundPathVector.md` | Reclassify as non-emitting documentation grouping for old-MSVC `std::vector<SoundPathString>` instantiations; no custom declaration. Preserve layout/call/evidence/history. | `91/95`, false, blank emitter/C++. |
| `by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md` | Preserve split index and exact inventory; replace custom-source narrative with standard-vector generated support. | `92/95`, false/blank retained. |
| UID0004FJ | Identify push/insert slow path from standard source `push_back`; preserve all growth/EH details. | `91/95`, false/blank. |
| UID0004FK | Identify standard vector destructor lowering; remove custom destructor emitter/body. | `92/95`, false/blank. |
| UID0004FN | Identify internal vector storage commit; remove custom `ChangeArray` emitter/body. | `91/95`, false/blank. |
| UID0004FO | Identify standard vector EH destroy range. | `90/94`, false/blank. |
| UID0004FL | Identify standard `reserve`/reallocation lowering; remove custom method emitter/body. | `92/95`, false/blank. |
| UID0004FP | Identify standard uninitialized-copy helper; clear custom emitter/body. | `91/94`, false/blank. |
| UID0004FQ | Identify append-copy support. | `90/94`, false/blank. |
| UID0001IF | Identify standard vector `clear` lowering from source `m_zoneMusicTracks.clear()`; clear custom emitter/body. | `92/95`, false/blank. |
| `by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md` | Correct ABI to StringBase lowercase-copy member instantiation; owner/emitter UID0001WS; replace explicit result/source free-helper C++ with the exact return-by-value member block. Preserve copy/detach/lowercase/EH/range evidence. | `92/94`, true, emitter UID0001WS. |
| `by-type/by-template/StringBaseTemplate.md` | Add `ToLower`-equivalent return-by-value member to method inventory; document hidden-result ABI and inferred spelling. Do not invent a standalone full class block in this callback. | Score/formal block unchanged. |
| `by-file/StringBase.md` | Add UID0004FM as consumer-TU template-instantiation evidence; remove SoundPathVector ownership. | Score unchanged. |
| `by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md` | Update renamed target link and concrete type to SoundPathString; preserve final false/blank `92/95`. | Score/metadata unchanged. |
| `by-memory/0x00529ee0-0x0052a00c.MusicControlDialogFolderPathSelected.md` | Replace exact managed block; remove narrow conversion; document temporary wide construction from `path.c_str()`. | Score/metadata unchanged. |
| `by-class/MusicControlDialog.md` | Synchronize wide temporary scanner call; remove narrow-input claim. | Score unchanged. |
| `by-memory/0x0062ce50-0x0062cfd8.NetworkAndAudioReadOnlyData.md` | Record the three target-only pooled literals and reject source-global names. | Score unchanged. |
| `by-memory/0x00421500-0x0042151a.MsvcVectorThrowHelpers.md` | No content change required; use as direct cross-reference for reclassification. | Unchanged. |

All ordinary by-* pages containing the old UID0001IA path were updated by the validator-preserving rename/reference mechanism. Only historical last-byte prose remains in the renamed target. Backup coverage files, project unresolved/config files, agent notes/goals, metadata cache, generated files, and supervisor/validator state were not manually changed.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/90`, owner/emitter UID0000NV, true, blank position/C++, `Nested:0`, last-byte filename.
- Current implemented target: `92/94`, owner UID0000DG, true, emitter UID0000NV, blank position, nonblank exact managed block, `Nested:0`, exclusive-end filename.
- Completion rationale: complete method body, exact range/boundaries, all callers/callees, all data/field/container/helper roles, source placement, standard-library disposition, negative evidence, EH/no-FindClose behavior, support contradictions, and exact destination blocks are resolved.
- Confidence rationale: direct live binary evidence is strong. The remaining uncertainty is exact original names and StringBase public spelling, so confidence remains below 95.
- Score-improvement attempt: path type resolved through caller and conversion helpers; queue type through completed Deque audit; vector type through standard throw literal and helper morphology; lowercase source shape through register/hidden-result ABI; literals through bytes/xrefs; FindClose through import/xref negative checks; range through function size/end bytes/successor checks; source placement through class/file structure and caller family.
- Support scores move only where source-category resolution materially completes those pages. SoundManager, MusicControl, read-only data, and other contextual support scores remain unchanged to avoid unrelated inflation.

## Open Questions With Attempted Resolution

- Exact scanner method spelling: `ScanMusicDirectory` is the established descriptive name and matches behavior; no symbol was found. It remains the best source-facing name and does not block code.
- Exact public wide-string alias: compiler metadata proves `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >`; `String`, `StringBaseW`, and `SimpleUString` facades coexist in docs. The target formal uses the proven full template type; caller preserves its current `String` alias.
- Exact lowercase member spelling: no symbol/public source was found. Calling convention proves member return-by-value semantics; `ToLower` is the highest-probability descriptive name and confidence cap.
- Exact member field names: `m_localMusicPaths` and `m_zoneMusicTracks` are established cross-page names tied to distinct offsets/callers. No competing interpretation fits better.
- Missing FindClose: exhaustively checked target callees, IAT xrefs, and EH cleanup. Resolution is to preserve the leak, not treat it as an unresolved omission.
- Standard vector versus custom container: exhaustively checked throw literal, growth, reserve, layout, cleanup, and project analogs. Resolution is standard vector; no custom source class remains defensible.
- No remaining question changes owner/emitter, range, score, or C++ readiness.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. The research tracker and by-memory coverage output are validator-owned auto-generated artifacts.
- The source page's Item Summary, metadata, filename, and `Nested:0` are the authoritative callback inputs. Validators should regenerate dependent reports.
- No manual coverage/tracker row text is supplied, and no pre-callback count is frozen as permanent truth.

## Follow-Up Actions

- Implementation, scoped validation, lease release, and waited generated verification are complete; no implementation item remains.
- B004 performed no `execute_report`, lifecycle probe, move, or archive command. Report validation, execution, count, path, move, and archive state remain external supervisor/validator-owned facts and are neither asserted nor directed by this artifact.
- Read-only generated proof from command `000000009534`: `auto-generated/NexusTK/audio/SoundManager.cpp` contains exactly one UID0001IA annotation and one scanner body, no target Empty Emitter Marker, and no UID0004FJ/4FK/4FN/4FO/4FL/4FP/4FQ/0001IF handwritten helper bodies. `StringBase.cpp` contains UID0004FM `ToLower() const`; `MusicControlDialog.cpp` contains UID0003MI with no narrow-path expression.

## Confidence

- Recommendation confidence: `94/100`.
- Score confidence: `94/100`.
- Remaining uncertainty: original identifiers and exact StringBase facade spelling only. Binary semantics, standard-container disposition, owner/source route, range, and complete first draft are resolved.

## Validator Results

All commands ran from `source-3/project-documentation` in `--mode file --apply --queue-timeout 240`; each ordinary by-* page had exactly one callback-scoped validator after its edit, and each lease was released immediately afterward. Command IDs are shown without leading zeroes in the ledger but in full below.

| Command | Timestamp | Scoped path / purpose | Exit / ok | Material side effects and warnings |
| --- | --- | --- | --- | --- |
| `000000009491` | `2026-07-13T08:52:30-04:00` | UID0001IA old-path lease, UID-preserving rename, target content | `0 / 1` | `path_update`; 12 reference-source-path and 28 UID-link updates; score/owner/C++/registry updates; 41 pre-existing missing-reference warnings; generated deferred. |
| `000000009492` | `2026-07-13T08:53:21-04:00` | `by-class/SoundManager.md` | `0 / 1` | Typed fields/scanner policy validated; 20 pre-existing missing-reference warnings; generated deferred. |
| `000000009494` | `2026-07-13T08:54:20-04:00` | `by-file/SoundManager.md` | `0 / 1` | Source/STL route validated; reference add UID0001WS; 12 pre-existing missing-reference warnings; generated deferred. |
| `000000009495` | `2026-07-13T08:55:03-04:00` | UID0001I7 music selection | `0 / 1` | Typed field/link sync; stale UID0000DI reference removed; generated deferred. |
| `000000009497` | `2026-07-13T08:55:58-04:00` | UID0001I8 audio aggregate | `0 / 1` | Corrected scanner row and STL classification; two pre-existing missing-reference warnings; generated deferred. |
| `000000009499` | `2026-07-13T08:56:27-04:00` | UID0001I9 playback controls | `0 / 1` | Renamed successor link validated; six pre-existing UID0003ZJ warnings; generated deferred. |
| `000000009500` | `2026-07-13T08:58:12-04:00` | `by-class/SoundPathVector.md` | `0 / 1` | `91/95`, true-to-false, emitter/formal route cleared, registry/stats updates; generated deferred. |
| `000000009502` | `2026-07-13T09:00:02-04:00` | UID0001ID vector aggregate | `0 / 1` | `92/95` score updates; false/blank retained; generated deferred. |
| `000000009505` | `2026-07-13T09:00:53-04:00` | UID0004FJ grow/insert | `0 / 1` | `91/95`, true-to-false, emitter/body cleared; generated deferred. |
| `000000009508` | `2026-07-13T09:02:17-04:00` | UID0004FK destructor | `0 / 1` | `92/95`, true-to-false, emitter/body cleared; registry error cleared; generated deferred. |
| `000000009510` | `2026-07-13T09:03:08-04:00` | UID0004FN storage commit | `0 / 1` | `91/95`, true-to-false, emitter/body cleared; registry error cleared; generated deferred. |
| `000000009512` | `2026-07-13T09:03:36-04:00` | UID0004FO EH destroy range | `0 / 1` | `90/94`, true-to-false, blank body retained; generated deferred. |
| `000000009514` | `2026-07-13T09:04:15-04:00` | UID0004FL reserve lowering | `0 / 1` | `92/95`, true-to-false, emitter/body cleared; stale UID0004FJ reference removed; generated deferred. |
| `000000009516` | `2026-07-13T09:05:04-04:00` | UID0004FP uninitialized copy | `0 / 1` | `91/94`, true-to-false, emitter/body cleared; registry error cleared; generated deferred. |
| `000000009518` | `2026-07-13T09:05:34-04:00` | UID0004FQ append-copy tail | `0 / 1` | `90/94`, true-to-false, blank body retained; generated deferred. |
| `000000009519` | `2026-07-13T09:06:28-04:00` | UID0001IF vector clear | `0 / 1` | `92/95`, true-to-false, emitter/body cleared; registry error cleared; generated deferred. |
| `000000009521` | `2026-07-13T09:07:14-04:00` | UID0004FM lowercase member | `0 / 1` | `92/94`; owner/emitter UID0000DI-to-UID0001WS; formal hash updated; UID0001WS reference added; generated deferred. |
| `000000009523` | `2026-07-13T09:08:04-04:00` | `StringBaseTemplate.md` | `0 / 1` | UID0004FM inventory/reference added; score/formal aggregate unchanged; generated deferred. |
| `000000009525` | `2026-07-13T09:08:36-04:00` | `by-file/StringBase.md` | `0 / 1` | UID0004FM consumer-instantiation reference added; score unchanged; generated deferred. |
| `000000009526` | `2026-07-13T09:09:02-04:00` | UID0001IE Deque destructor | `0 / 1` | Concrete `SoundPathString`/renamed-link sync; `92/95` false/blank unchanged; generated deferred. |
| `000000009528` | `2026-07-13T09:09:32-04:00` | UID0003MI folder callback | `0 / 1` | Exact formal hash changed to wide caller block; metadata/score unchanged; generated deferred. |
| `000000009530` | `2026-07-13T09:10:04-04:00` | `by-class/MusicControlDialog.md` | `0 / 1` | Wide-caller support validated; three pre-existing UID00040O missing-reference warnings; generated deferred. |
| `000000009531` | `2026-07-13T09:10:43-04:00` | UID00026I read-only data | `0 / 1` | UID0001IA literal reference added; score/metadata unchanged; generated deferred. |
| `000000009534` | `2026-07-13T09:11:38-04:00` | Final target-scoped `--wait-generated` | `0 / 1` | Registry rebuilt with 4,625 nodes/3,764 edges; 281 generated metadata files refreshed; unrelated project-wide marker warnings reported; `generated_refresh: completed`. |

Generated read-only checks after `9534`: UID0001IA annotation count `1`, `SoundManager::ScanMusicDirectory` definition count `1`, target Empty Emitter Marker count `0`; no compiler-only vector child UID/body occurs in `SoundManager.cpp`. UID0004FM emits once through UID0001WS in `StringBase.cpp`, and UID0003MI emits the accepted direct wide call in `MusicControlDialog.cpp` without `narrowPath` or `ToNarrowPath`.

## Changed Files

- Renamed and modified: `by-memory/0x0057a890-0x0057afcd.SoundManagerMusicDirectoryScan.md` -> `by-memory/0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan.md` (UID0001IA preserved).
- Modified: `by-class/SoundManager.md`.
- Modified: `by-file/SoundManager.md`.
- Modified: `by-memory/0x005797b0-0x0057a25c.SoundManagerMusicSelection.md`.
- Modified: `by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md`.
- Modified: `by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md`.
- Modified: `by-class/SoundPathVector.md`.
- Modified: `by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md`.
- Modified: `by-memory/0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert.md`.
- Modified: `by-memory/0x0057bac0-0x0057bb2a.SoundPathVectorDestructor.md`.
- Modified: `by-memory/0x0057bce0-0x0057bd53.SoundPathVectorReplaceStorage.md`.
- Modified: `by-memory/0x0057bd60-0x0057bd84.SoundPathStringDestroyRange.md`.
- Modified: `by-memory/0x0057bd90-0x0057be52.SoundPathVectorReallocate.md`.
- Modified: `by-memory/0x0057be60-0x0057becf.SoundPathStringCopyConstructRange.md`.
- Modified: `by-memory/0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail.md`.
- Modified: `by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md`.
- Modified: `by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md`.
- Modified: `by-type/by-template/StringBaseTemplate.md`.
- Modified: `by-file/StringBase.md`.
- Modified: `by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md`.
- Modified: `by-memory/0x00529ee0-0x0052a00c.MusicControlDialogFolderPathSelected.md`.
- Modified: `by-class/MusicControlDialog.md`.
- Modified: `by-memory/0x0062ce50-0x0062cfd8.NetworkAndAudioReadOnlyData.md`.
- Modified: this report, `tools/leaser/Agents/Agent-B004/research/0001IA-SoundManagerMusicDirectoryScan-source-quality.md`.
- Validator-generated side effects were produced only by the authorized scoped/final refresh commands. B004 manually edited no coverage, generated, tracker, supervisor, registry, validator-state, lifecycle, or archive file and ran no report execution/lifecycle command.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 accepted exact report SHA `A084E4D662CCA454DD65029CDF2696365E5B589E4277B8F50157A673E8DA046A` before implementation.
- [x] Target/support inventory covered UID0001IA, every accepted support destination, and all ordinary historical-path links.
- [x] Research-time target state and binary evidence remain recorded without compression; current callback state is reconciled separately.
- [x] C01-C46 ledger records destination, applied state, and exact validator/generated proof claim by claim.
- [x] Metadata/score contract applied: target `86/90 -> 92/94`; vector scores/dispositions exactly as listed; UID0004FM `92/94` true with UID0001WS owner/emitter; contextual scores unchanged.
- [x] Range, input, entry, queue/vector, lowercase ABI, literals, fields, callers, FindClose, EH, source placement, and formal-C++ blockers were resolved before callback and preserved.
- [x] Owner/emitter/reconstructable contract applied: target `0000DG`/`0000NV`/true; vector family false/blank; UID0004FM `0001WS`/`0001WS`/true.
- [x] UID0001IA was renamed UID-preservingly to end `afce`; no split/new child; existing helper pages were reclassified.
- [x] Source-placement/range/padding/reclassification decisions were applied; B004 made no IDA mutation.
- [x] Exactly three accepted formal managed destination blocks are nonblank: UID0001IA, UID0003MI, UID0004FM. Compiler-only vector helper blocks are exactly blank.
- [x] Third-party import directive remains not applicable.
- [x] Every accepted target/support fact was incorporated at report-level detail.
- [x] Custom Deque/vector/helper history, old filename, narrow caller, source-global literals, no-FindClose, EH, and rejected routes remain explicit.
- [x] Wave2/Wave3/generated historical artifacts remain labeled superseded rather than current authority.
- [x] Exact-name caps remain; no implementation blocker or unapplied item remains.
- [x] One scoped validator ran per changed ordinary by-* page under one-file-at-a-time leases, followed by immediate release.
- [x] Final authorized `--wait-generated` command `9534` completed and read-only generated checks passed.

Implementation callback pass:

- [x] Gate-1-accepted callback authorization recorded above.
- [x] All accepted target/support details are incorporated without evidence compression.
- [x] C01-C46 ledger is applied/verified claim by claim; no blocker remains.
- [x] Target rename, metadata, score, owner, emitter, position, nesting, and exact C++ are applied.
- [x] UID0003MI exact corrected managed block is applied with unrelated content preserved.
- [x] SoundPathVector/UID0001ID/eight exact vector children are reclassified and only custom emitted bodies removed.
- [x] UID0004FM ABI/owner/source category/exact return-by-value member block and StringBase support are synchronized.
- [x] All ordinary historical target links and stale UID0001I8 row are corrected; backup coverage files remain untouched.
- [x] Historical assumptions, rejected alternatives, no-FindClose, EH, caller, field, literal, and boundary evidence are preserved.
- [x] Validator Results records every command ID, timestamp, exit, ok, side effect, and pre-existing warning.
- [x] Every lease was released immediately; `current_leases.md` has no B004 entry.
- [x] Waited generated command `9534` proves one UID0001IA body, no target marker, no compiler-only vector body, plus correct UID0003MI/UID0004FM output.
- [x] Remaining unapplied accepted items: none.
- [x] Current-state wording is archive-neutral; B004 ran no execution/lifecycle/move/archive command.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000009581","destination_path":"executed-b-agent-research/B004/0001IA-SoundManagerMusicDirectoryScan-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0001IA-SoundManagerMusicDirectoryScan-source-quality.md","timestamp":"2026-07-13T09:35:07-04:00","uid":"0001IA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
