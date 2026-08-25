** TARGET-REPORT-UID:000299 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: removed prohibited executable PowerShell fence; exact-artifact revalidation required **
# 000299 g_pInputMan Empty-Emitter Source-Quality Report


## Finalized Report / Current Recommendation

- Current recommendation: retain the callback-applied semantic/physical split. Validator-assigned [UID:00050J][g_pInputMan](by-global/g_pInputMan.md) owns the sole source definition `InputMan *g_pInputMan = 0;` and emits through [UID:0000K6] InputMan. Physical [UID:000299] is high-confidence non-emitting storage evidence owned by UID00050J, matching the current g_pCheatDetector one-definition model and the project rule that process-wide singleton pointers belong under by-global.
- Final disposition: [UID:000299] remains the exact four-byte evidence page at `94/96`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank CPP/H. This is not a no-source decision: [UID:00050J] at `94/96` emits the source definition, while existing [UID:00006J] at `88/90` remains the sole declaration owner for `extern InputMan *g_pInputMan;`; [UID:0000K6] remains `88/90` and the `NexusTK/input/` source root.
- Callback result: command `000000021418` registered UID00050J first; commands `000000021421`, `000000021422`, and `000000021423` validated the target, class, and file serially. Every bounded registration token is removed. All four commands exited `0` with generated refresh explicitly skipped.
- Formal source result: UID00050J CPP is exactly `InputMan *g_pInputMan = 0;`. UID00050J H remains blank because the class page already emits the exact extern declaration. UID000299 CPP/H both remain blank because it is the physical duplicate evidence page, not a second source declaration.
- Supervisor closure receipt: exact-artifact Gate 1 and Gate 2A passed in the supervisor audit. Gate 2B then passed C000299-024-C000299-027 and C000299-044 through one bounded transaction: P0/backup SHA `B9D15E933B0FAA504D31F5AE9A20909534AF05A05157168BE072035D93251A46` at `143197476` bytes, one `idb_save`, and persisted S1 SHA `1EE09DC2B6DD0A7F39EB4EE459FF8B785C6E4E6B913CDA6A827BDB4FFE1D741C` at `143197502` bytes. Fresh persistence readback proved the type, symbol, four-byte item, exact regular comment, protected neighbors/bytes, and all 18 xrefs.
- Supervisor manual/generated receipt: C000299-028-C000299-031 passed commands `000000021436`-`000000021439`, each exit `0`/`ok:1`; C000299-036-C000299-040 passed coherent command `000000021445` at `2026-08-06T03:52:23-04:00`, exit `0`/`ok:1`, with generated refresh completed and the empty-emitter defect absent.
- Confidence: very strong. Current live MCP, executable section mapping, all 18 xrefs, constructor/destructor writes, zero-filled loader state, adjacent singleton patterns, class/file declarations, and generated one-definition behavior agree.

## Supporting Research

- Current live evidence was gathered read-only from MCP session primary-current-supervisor-202608060133. At the final research snapshot, idb_list reported exactly one active owned/adopted worker, PID 11540, for E:\NTK\Resources\NexusTK\NexusTK.exe.i64. server_health returned status ok, module NexusTK.exe, imagebase 0x400000, Hex-Rays ready, strings cache ready with 2068 entries, and auto_analysis_ready false. The false auto-analysis flag is context only because all bounded required calls succeeded.
- Canonical IDB disk snapshot at research time: E:\NTK\Resources\NexusTK\NexusTK.exe.i64, 143197386 bytes, SHA256 51FFD417524AABFFF2DDE403B2A96B348FEDF00B03CFC181EFD1BA1D66697A87, last-write UTC 2026-08-06T05:06:15.0633770Z. This identity is dated research evidence; supervisor Gate 2 must dynamically rebind to the then-current canonical disk/session rather than assuming this worker or hash remains current.
- Input executable snapshot: C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe, 2679296 bytes, SHA256 9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632, last-write UTC 2025-12-11T16:24:42.8919558Z.
- Read-only PE parsing places VA 0x0067ab44 at RVA 0x27ab44 in .data. The section starts RVA 0x26d000, has virtual size 0x2fe24, raw size 0xd800, and raw pointer 0x26ac00. Target offset 0xdb44 is beyond the raw extent, so the loader supplies zero-filled storage. This directly disproves the historical ff ff ff ff / 0xffffffff initializer claim.
- The old [UID:00018E] InputMan source-quality research and the current InputMan class/file/aggregate documentation were reviewed as leads and revalidated against the dated research MCP snapshot. Adjacent current semantic-global patterns were also checked: g_pCheatDetector uses a source-emitting by-global page plus a false/non-emitting physical by-memory page; g_pDATFileMgr and g_pKeySpeedMgr use source-emitting by-global pages with physical storage children. The newer no-duplicate g_pCheatDetector model best matches current by-structure guidance.
- No Wave2/Wave3 evidence or instruction is used. Any old wave terminology is ignored as stale.
- Callback-time ordinary authority: UID00050J was validator-registered and the four ordinary destinations were updated/validated at report-level detail. Current hashes are UID00050J `51D84F5ECC8AE8DC3F72806375B78778D5D14CD3830A43D917906F4C99B5B737`, UID000299 `347237E31A122B578FC03C4837D3ACDED3568CE66B603193055DEBDF03A5A7F6`, UID00006J `8B10C6405D5090C2AC2D8C1B39DECE5A81EF5FB2A42DCBDDEA3B24CBDFAF59CC`, and UID0000K6 `AEE85D4F703B87B6EE948DA19A7C1C461AD189FB1DFC7E4E126D7CF7BFD6F9B4`. These are dated callback readbacks; later unrelated edits require dynamic reread.
- Dated supervisor IDA authority: disposable preflight session `primary-preflight-uid000299-202608060343` operated on a copy and remained unsaved P0; canonical transaction session `primary-transaction-uid000299-202608060348` used the collision-free exact backup `NexusTK.exe.i64.bak-UID000299-prestate-20260806_0348`, declared `typedef struct InputMan InputMan;`, created the exact four-byte `InputMan *g_pInputMan` item at `0x0067ab44`, set the accepted regular comment, and saved exactly once. Fresh session `primary-verify-uid000299-202608060350` proved persisted S1 plus unchanged `0x0067ab40`, `0x0067ab48`, forty zero bytes, and all 18 xrefs; two final exclusive probes reproduced stable S1.
- Dated supervisor manual/generated authority: manual coverage hashes are by-memory `91E6071142DC79070054119F525C6D813D0EE85BF748B4FF5D19A8F8E493F48F`, by-class `C64EDFB074AD29F8C8A4194C66F31C28344B6CF394F29C4E4926C8D26E11AC41`, by-file `AA5292D61EF0300821326F549CF8616F7DB28C7AC629A5766C9BEC5A39B4FCAB`, and by-global `F50BA4E72FE183E95EE35A75BC5FE5015E767124C078F8325B13DC8A8E89709D`. Coherent command `000000021445` produced the exact source/header/ag-memory/tracker identities recorded below.

## Target

- Target UID: 000299.
- Additional target UIDs: none. Registered [UID:00050J][g_pInputMan](by-global/g_pInputMan.md) is an accepted support destination, not additional target coverage.
- Target path: by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md.
- Target role: exact physical four-byte storage evidence for the process-wide InputMan singleton pointer.
- Historical assignment queue state: 88/90, reconstructable true, direct/additional/total reports 0/0/0, generated route NexusTK/input/InputMan.cpp.
- Historical empty-emitter trigger: the pre-callback generated `InputMan.cpp` snapshot contained a UID000299 Empty Emitter Marker while using `g_pInputMan` without a definition. Supervisor command `000000021445` resolved that generated defect after the ordinary/manual/IDA closures.
- Current ordinary parent/source route: UID000299 `CANONICAL_OWNER:00050J`, `RECONSTRUCTABLE:FALSE`, blank emitters; UID00050J owner/emitter `0000K6`, reconstructable true, exact CPP definition and blank H.

## Current Target State

- Current ordinary metadata after callback: UID000299 is `94/96`, `CANONICAL_OWNER:00050J`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank emitter position, blank formal CPP, and blank formal H. UID00050J is `94/96`, owner/emitter `0000K6`, reconstructable true, blank position, exact formal CPP definition, and blank formal H.
- Historical P0 prestate: `0x0067ab44` was an undefined one-byte `unk_67AB44` item with displayed `_DWORD *`; the `InputMan` type and `g_pInputMan` global were absent, and regular/repeatable comments at all four target byte heads were absent. That prestate is retained as the exact transaction baseline, not asserted as the current S1 model.
- Current supervisor-verified S1: `typedef struct InputMan InputMan;` exists; `0x0067ab44` is one four-byte `InputMan *g_pInputMan` item; the exact accepted regular comment persisted; the protected repeatable/comment, predecessor `0x0067ab40`, successor `0x0067ab48`, forty zero bytes, and exact 18 data xrefs remained unchanged. Five xrefs are direct writes/clears inside InputMan construction/destruction/cleanup; thirteen are application, IME, menu, pane, text-edit, or user-pane consumers.
- Canonical IDB receipt: P0 and its exact backup were `B9D15E933B0FAA504D31F5AE9A20909534AF05A05157168BE072035D93251A46`, `143197476` bytes. The one-save persisted S1 is `1EE09DC2B6DD0A7F39EB4EE459FF8B785C6E4E6B913CDA6A827BDB4FFE1D741C`, `143197502` bytes, verified through fresh session `primary-verify-uid000299-202608060350` and two stable exclusive probes.
- Current declaration: [UID:00006J] by-class/InputMan.md formal H still contains exactly one `extern InputMan *g_pInputMan;`; its formal-H payload hash remains `CDEA9A45EA850D8919281804279F18D26851CCEB9CE65D00FF652E30AF2B54F7`, byte-for-byte unchanged by this callback.
- Current generated receipt from command `000000021445`: `InputMan.cpp` SHA `BE58A47A36C8C7BD9F8830FBBDA1852C14E78211FCEF0412979934D19B0151E4` contains exactly one definition and zero UID000299 markers; `InputMan.h` SHA `47F334EC12BFDCDC2DBE0ECF11E193A2B982D82FD723DA8D21C5533139D3C164` contains exactly one extern and zero definitions; ag-memory SHA `18A83A1B1D53F5A55C197AF0061294214B1ABBCCED7C967A8D8087B108E8A4DC` records UID000299 non-reconstructable, owner UID00050J, blank emitter/no code; tracker SHA `AE3D937E3E8B56CB10A46B140DCF4F728204AB6184693351D91432E10E63BF11` records UID00050J and UID000299 at `94/96` without stale empty-emitter state.
- Former stale `ff ff ff ff` / `0xffffffff` and missing-by-global/direct-file-parent assertions are retained only as explicitly disproved or superseded history in the ordinary docs; current Layout/Evidence/Parent-Gate text records loader zero-fill and UID00050J.
- Current ordinary file identities: UID00050J `51D84F5E...B5B737` (149 lines), UID000299 `347237E3...5A7F6` (102 lines), UID00006J `8B10C640...F59CC` (162 lines), UID0000K6 `AEE85D4F...F9B4` (154 lines).
- Current report lifecycle authority is external: it derives from this report's current path plus validator-owned status/history metadata. The report body does not claim an execution/archive state.

## Executive Recommendation

1. Preserve callback-applied [UID:00050J] as the semantic process-wide symbol page, owner/emitter [UID:0000K6], with the sole `InputMan *g_pInputMan = 0;` definition.
2. Preserve [UID:000299] as the `94/96` physical evidence page owned by UID00050J, non-reconstructable/non-emitting with blank CPP/H and full zero-fill/xref/lifetime evidence.
3. Preserve [UID:00006J] as the sole header declaration owner with its exact formal H unchanged, and preserve [UID:0000K6] as the `88/90` `NexusTK/input/` file root with the semantic-global route.
4. Retain the dated supervisor Gate 2B receipt: the absent `InputMan` forward type, exact four-byte item/name/type, and one channel-specific regular address comment were applied through one save and verified from fresh S1 without changing protected bytes, neighbors, or xrefs.
5. Retain the exact supervisor manual coverage receipts from commands `000000021436`-`000000021439` and the coherent generated/currentness receipt from command `000000021445`.
6. Report execution/archive state remains supervisor-owned and authoritative only from current path plus validator-owned history.

## Supervisor Active Recheck

- Triggering research instruction: new report-only B002 assignment for UID000299 using the active canonical MCP session and all 33 literal sections. The later exact SHA `CAD08E5D...44442B` passed supervisor Gate 1 and authorized the ordinary-document callback recorded here.
- Split-first result: no address split is needed. The target already exactly spans one four-byte pointer slot [0x0067ab44,0x0067ab48).
- Semantic-page result: the required by-global page was registered as UID00050J because by-structure classifies process-wide singleton pointers under by-global and the adjacent singleton family already uses semantic global pages. The former direct by-file owner is explicitly documented as a temporary missing-page workaround.
- Source-bearing inventory after callback: UID00050J carries the definition, UID00006J carries the declaration, UID000299 carries no duplicate source, and UID0000K6 provides the source root.
- All reasonable blockers were investigated: bytes, PE raw/virtual mapping, all xrefs, lifecycle, name, type, comments, exact boundaries, source file, declaration/definition split, by-global requirement, generated route, scores, formal CPP/H, manual coverage, and deterministic IDA application.
- MCP stayed available for all bounded queries. One earlier broad entity query returned a large generic result and was discarded; subsequent bounded tools produced the exact evidence used here. No fallback-only conclusion is used.
- Current supervisor receipt: Gate 1 and Gate 2A passed in the supervisor audit; Gate 2B passed the literal three-action/one-save transaction; manual coverage commands `21436`-`21439` and generated/currentness command `21445` passed. These are dated evidence for this report artifact and do not transfer lifecycle authority into the report body.

## Inference Research Guidance Check

- Direct IDA facts: target item shape, zero bytes, comments, missing InputMan type, missing g_pInputMan symbol, 18 xrefs, and exact instruction references.
- Direct executable facts: .data virtual-zero-fill placement and exact image identity.
- Documentation facts: target/class/file metadata, class H declaration, InputMan method/lifetime evidence, generated empty marker, generated routes, manual coverage rows, and adjacent semantic-global conventions.
- Inference: original source likely used an explicitly zero-initialized external pointer definition. Zero-fill alone cannot distinguish InputMan *g_pInputMan; from InputMan *g_pInputMan = 0;, but current project-era singleton definitions near this subsystem commonly use = 0, including DATFileMgr and KeySpeedMgr. The explicit form is the most realistic, initialization-order-safe source-facing recommendation.
- Existing assumptions treated as uncertain and rechecked: ff ff ff ff initialization, direct by-file canonical ownership, absence of formal C++, lack of a semantic global page, and whether the class H declaration should be duplicated.
- Human-source rule: final source uses InputMan and g_pInputMan, not unk_67AB44, dword_67AB44, or address-derived names.
- Consistency is subordinate to exact behavior and human-looking source. The recommended = 0 form preserves loader-zero state and follows the dominant nearby source convention without using C++11 nullptr.
- No Wave2/Wave3 source or instruction affected the result.

## Heuristic / Inference Reanalysis And Validation

1. Initialization bytes.
   - Historical claim: ff ff ff ff / 0xffffffff.
   - Current checks: live 40-byte zero read, current integer zero reads, and PE virtual/raw boundary analysis.
   - Resolution: loader-zero-filled. Historical ff text is false current-state evidence and must be historicalized.

2. Runtime role.
   - Current checks: all 18 xrefs, constructor publication at 0x004e8b33, constructor failure/unwind clear at 0x004e8b3a, ordinary destructor clear at 0x004e8c81, clear helper at 0x004e9650, scalar deleting destructor clear at 0x004e96c8, and thirteen consumers.
   - Resolution: process-wide active InputMan singleton pointer, not a generic dword or unrelated adjacent state.

3. Type.
   - Current checks: constructor writes this/EAX; all consumers load the pointer into ECX/EAX and call documented InputMan methods; class page has exact InputMan declaration; IDA type is absent.
   - Resolution: InputMan *, very strong. No void *, DWORD, HANDLE, or pointer-to-pointer model fits the lifecycle and member-call evidence.

4. Source-facing name.
   - Current checks: class/file docs, generated constructor/destructor source, adjacent g_p singleton naming, and consumer semantics.
   - Resolution: g_pInputMan. This is a high-probability human source name consistent with the subsystem and established project naming; raw unk_67AB44 is rejected.

5. Declaration/definition split.
   - Current checks: class H already emits one extern declaration; generated InputMan.h contains one declaration; InputMan.cpp lacks a definition.
   - Resolution: definition belongs in semantic by-global CPP; declaration stays in class H. No duplicate target H or global H declaration.

6. Missing by-global page.
   - Current checks: by-structure process-wide-global category rule, narrow-owner rule, current g_pCheatDetector/g_pDATFileMgr/g_pKeySpeedMgr pages, target/file historical workaround.
   - Resolution: create by-global/g_pInputMan.md. Direct by-file ownership was acceptable as a temporary missing-parent bridge but is not the final narrow semantic owner.

7. Physical by-memory reconstruction state.
   - Current checks: current target is only the physical slot; the semantic page will emit the complete source symbol.
   - Resolution: set UID000299 RECONSTRUCTABLE FALSE and blank its emitter/code. This prevents duplicate source while retaining exact binary evidence. It is not a claim that g_pInputMan is non-source.

8. Original initializer spelling.
   - Current checks: loader zero-fill, nearby generated/global definitions, late-1999 through mid-2000s C++ style, and no explicit raw initializer bytes.
   - Resolution: InputMan *g_pInputMan = 0; is the best source-form inference. NULL remains plausible but weaker here; nullptr is historically invalid.

9. Score blockers.
   - Current checks closed initializer, role, xrefs, owner, source page, declaration, definition, boundaries, IDA handoff, manual rows, and generated route.
   - Resolution: target 94/96 and global UID00050J 94/96 are now present in ordinary docs. Completion remains below 95 because original token spelling (`= 0` versus implicit/`NULL`) is inferred, not symbol-proven; supervisor-owned IDA/manual/generated closure remains independently gated.

10. Split/merge/range.
    - Current checks: predecessor item ends exactly at 0x0067ab44; successor item starts at 0x0067ab48; every target xref lands at 0x0067ab44.
    - Resolution: exact four-byte page; no split, merge, padding child, or range extension.

11. Third-party/import question.
    - Resolution: not applicable. This is NexusTK module state, not a third-party static embed.

12. Remaining open questions.
    - Exact original zero-token spelling cannot be proven from loader-zero storage. A best source-form inference is selected rather than deferred. No ownership/type/C++ blocker remains.

## Evidence Standards Used

- Highest-weight evidence: current live IDA item/byte/xref/comment/type observations and current executable PE section mapping.
- Strong corroboration: constructor/destructor instruction writes, current class/file/aggregate docs, formal class H block, generated InputMan.cpp/InputMan.h, and adjacent singleton global patterns.
- Negative evidence: no g_pInputMan symbol, no InputMan IDA type, no raw-backed initializer, no by-global page, no extra xrefs, no overlap with neighboring slots, and no reason to duplicate the extern declaration.
- Inference is used only for original source spelling and page architecture after direct facts establish behavior. The recommendation does not require impossible original PDB/source proof.
- The dated research MCP `auto_analysis_ready:false` flag does not weaken the result because exact bounded item, byte, comment, type, xref, and instruction queries all succeeded and no analysis-producing call was required for the conclusion.
- Report/currentness rule: session IDs, PIDs, hashes, and generated/manual hashes are dated snapshots. Supervisor gates must reread dynamic authority.

## Evidence Checked

- Dated pre-Gate2B MCP research session:
  - idb_list: exactly one active session primary-current-supervisor-202608060133, PID/worker PID 11540, canonical IDB path.
  - server_health: status ok, NexusTK.exe, imagebase 0x400000, Hex-Rays ready, strings cache ready 2068.
- Dated P0 target state:
  - inspect_items at 0x0067ab40, every byte address 0x0067ab44/45/46/47 in the replacement interval, and 0x0067ab48. The four target bytes are separate one-byte unknown heads before replacement: 0x0067ab44 is named unk_67AB44 with displayed type _DWORD *, while 0x0067ab45/46/47 each have absent name and absent type; all four are non-code/non-data unknown items.
  - get_bytes at 0x0067ab30 size 40.
  - get_comments at 0x0067ab40, 0x0067ab44/45/46/47, and 0x0067ab48; regular and repeatable address-comment values are explicitly absent at every target byte and both protected neighbors.
  - type_inspect InputMan: absent.
  - list_globals g_pInputMan: zero results.
  - xrefs_to 0x0067ab44 limit 100: exactly 18, not truncated.
  - bounded insn_query per containing function for every xref, with no broad scan retained as evidence.
- Raw executable:
  - SHA/size/mtime.
  - PE imagebase, target RVA, .data virtual/raw sizes, raw pointer, and target outside-raw proof.
- Ordinary docs:
  - by-global/g_pInputMan.md, UID00050J, SHA256 51D84F5ECC8AE8DC3F72806375B78778D5D14CD3830A43D917906F4C99B5B737, 12833 bytes, 149 lines.
  - by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md, SHA256 347237E31A122B578FC03C4837D3ACDED3568CE66B603193055DEBDF03A5A7F6, 9887 bytes, 102 lines.
  - by-class/InputMan.md, SHA256 8B10C6405D5090C2AC2D8C1B39DECE5A81EF5FB2A42DCBDDEA3B24CBDFAF59CC, 17476 bytes, 162 lines; formal H payload hash unchanged at CDEA9A45EA850D8919281804279F18D26851CCEB9CE65D00FF652E30AF2B54F7.
  - by-file/InputMan.md, SHA256 AEE85D4F703B87B6EE948DA19A7C1C461AD189FB1DFC7E4E126D7CF7BFD6F9B4, 22665 bytes, 154 lines.
  - current InputMan aggregate and related Application/IME/MainMenu/Pane/TextEdit/UserPane docs referenced by those support pages.
- Historical pre-callback generated snapshots:
  - InputMan.cpp SHA256 0C161CB8C2E3EFA984B32F574073880539699BF1DA1B65499E19AD218FCDE8A9, 10900 bytes, 342 lines.
  - InputMan.h SHA256 FF9E42FF4C0633C08C562A1C2A5D8C53C0CE0F5633BC0E329D3287BAB53CD9C1, 1159 bytes, 39 lines.
  - ag-memory SHA256 4B40A209515829055F544B305740E6FD61EA64BE324F157C6DA24CC020970DF6; UID000299 row says emits, owner/emitter 0000K6, CPP no, H no, InputMan.cpp.
  - research tracker SHA256 523A6E9361ECD382D597E223B1F33FDAB723ED9519E48EA555E9A286B10C05D3; UID000299 row is 88/90, true, 0/0/0; InputMan file row is 1/3 covered.
- Historical preapplication manual coverage snapshots:
  - by-memory SHA256 8B4FAEBA4592B939006BCA10914621C43DAE9978887939CD2AB15354026094F9, where UID000299 line 4704 was the stale reconstructable 88% row before command `000000021436`.
  - by-class SHA256 FA0D0E6F6FE388517A7CCBFE5C432D979B5C8E07292078C1DFDE2CF3194FAE71, historical preapplication UID00006J line 261.
  - by-file SHA256 4D4C1FABC5312CBF0D1A927415A7E814FB5A302BE1CEB80F85C83CC8CC273FA4, historical preapplication UID0000K6 line 123.
  - by-global SHA256 A41D2CAA391B97C59E343D0B7FBA51B862A7776A260C143C023C4B7F5CCF6B38, 218 lines, with zero g_pInputMan/UID000299 matches before command `000000021439`.
- Failed/intentionally skipped:
  - B002 ran only the four authorized scoped file validators. No `execute_report`, report lifecycle command, or generated refresh was run.
  - No IDA mutation/save/process management was performed.
  - No decompile result is required for the global slot; exact instructions and established method docs provide stronger bounded evidence.
- Supervisor closure readbacks:
  - Gate 2B: exact P0/backup, unsaved disposable preflight, three canonical mutations, one save, exact S1, fresh verifier, all protections, and two stable exclusive probes passed.
  - Manual coverage: commands `000000021436`-`000000021439`, each exit `0`/`ok:1`, produced the four current hashes recorded in the manual section.
  - Generated/currentness: command `000000021445`, timestamp `2026-08-06T03:52:23-04:00`, exit `0`/`ok:1`, generated completed, with exact source/header/ag-memory/tracker semantics and hashes recorded in Current Target State.
  - Supervisor audit: Gate 1 and Gate 2A passed; no validator command is fabricated for either gate.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Actor / authority | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| C000299-001 | 000299 | Replace stale ff/0xffffffff current-state claims with exact loader-zero-filled 00 00 00 00 evidence while retaining the old claim as disproved history. | direct | UID000299 SHA 347237E3; PE/IDA evidence physically present | UID000299 Layout/Evidence/Changes | incorporate | B002 callback | applied |
| C000299-002 | 000299 | Record the exact one-byte undefined IDA prestate and exact four-byte physical range. | direct | UID000299 Loader-Zero-Fill And IDA Prestate | UID000299 Layout/IDA Status | incorporate | B002 callback | applied |
| C000299-003 | 000299 | Record all 18 xrefs and the five publication/clear writes independently. | direct | UID000299 complete 18-row table | UID000299 Evidence/Xrefs | incorporate | B002 callback | applied |
| C000299-004 | 000299 | Resolve runtime role as the process-wide active InputMan singleton pointer. | very strong | UID000299 summary/reconstruction readback | UID000299 Summary/Reconstruction | incorporate | B002 callback | applied |
| C000299-005 | 000299 | Raise target metadata to 94/96 after all score blockers are closed. | strong | UID000299 header plus command 000000021421 | UID000299 metadata/score | incorporate | B002 callback | applied |
| C000299-006 | 000299 | Set CANONICAL_OWNER to the real validator-assigned g_pInputMan by-global UID after registration. | very strong | UID000299 owner 00050J readback | UID000299 owner | incorporate | B002 callback | applied |
| C000299-007 | 000299 | Set RECONSTRUCTABLE FALSE, blank EMITTER_UIDS, and blank CPP/H because the semantic global page owns the sole source symbol. | very strong | UID000299 header/formal-channel readback | UID000299 metadata/formals | incorporate | B002 callback | applied |
| C000299-008 | 000299 | Replace Item Summary with exact physical-slot, zero-fill, xref, lifetime, and one-definition disposition. | strong | exact Item Summary physically present | UID000299 Item Summary | incorporate | B002 callback | applied |
| C000299-009 | 000299 | Preserve exact predecessor 0x67ab40 and successor 0x67ab48 boundary evidence without merging either slot. | direct | UID000299 Layout/Boundaries readback | UID000299 Layout/Boundaries | incorporate | B002 callback | applied |
| C000299-010 | 00050J | Create by-global/g_pInputMan.md and obtain a validator-assigned UID; eliminate every registration token before post-callback gates. | very strong | command 000000021418 assigned 00050J; token scan zero | new by-global page/registration | incorporate | B002 callback | applied |
| C000299-011 | 00050J | Set new global metadata to 94/96, owner/emitter 0000K6, reconstructable true. | strong | UID00050J header readback | new global metadata | incorporate | B002 callback | applied |
| C000299-012 | 00050J | Emit exact formal CPP InputMan *g_pInputMan = 0;. | strong | UID00050J formal CPP readback | new global CPP | incorporate | B002 callback | applied |
| C000299-013 | 00050J | Keep new global formal H blank because UID00006J already emits the sole extern declaration. | very strong | UID00050J blank H plus unchanged class H hash | new global H | incorporate | B002 callback | applied |
| C000299-014 | 00050J | Incorporate full purpose, lifetime, all 18 xrefs, zero-fill, boundaries, source placement, rejected alternatives, and source-shape rationale. | strong | UID00050J SHA 51D84F5E physical readback | new global prose | incorporate | B002 callback | applied |
| C000299-015 | 00006J | Keep class score 88/90 and formal H byte-for-byte unchanged, including one extern declaration. | direct | class formal H SHA CDEA9A45 unchanged | UID00006J metadata/H | already-present | B002 callback | already-present |
| C000299-016 | 00006J | Add semantic-global definition-route and corrected zero-fill/lifetime evidence without pruning existing field/method detail. | strong | UID00006J SHA 8B10C640 physical readback | UID00006J Evidence/Global Route | incorporate | B002 callback | applied |
| C000299-017 | 0000K6 | Keep file score 88/90 and NexusTK/input route unchanged. | direct | UID0000K6 metadata/path readback | UID0000K6 metadata | already-present | B002 callback | already-present |
| C000299-018 | 0000K6 | Replace temporary direct-file parent workaround with the new semantic global route. | very strong | UID0000K6 Parent-Gate/Singleton readback | UID0000K6 Singleton/Parent Gate | incorporate | B002 callback | applied |
| C000299-019 | 0000K6 | Correct stale 0xffffffff evidence and document the sole definition/declaration split. | direct/strong | UID0000K6 SHA AEE85D4F physical readback | UID0000K6 Evidence/Inventory | incorporate | B002 callback | applied |
| C000299-020 | 000299 | Preserve historical A006/B001 InputMan research as dated lead evidence and label contradicted initializer text historical. | strong | UID000299 Historical/Changes readback | UID000299 Changes | historicalize | B002 callback | applied |
| C000299-021 | 000299 | Preserve application, IME, MainMenu, Pane, TextEditPane, and UserPane consumer clusters with exact addresses. | direct | UID000299 complete xref table readback | UID000299 Evidence/Xrefs | incorporate | B002 callback | applied |
| C000299-022 | 000299 | Record InputMan * and g_pInputMan as source-facing type/name and reject raw labels. | very strong | UID000299 Reconstruction Notes readback | UID000299 Reconstruction Notes | incorporate | B002 callback | applied |
| C000299-023 | 000299 | Record no split/merge/padding/reclassification beyond exact physical-versus-semantic-page separation. | direct/strong | UID000299 boundary/source split readback | UID000299 Range Analysis | incorporate | B002 callback | applied |
| C000299-024 | 000299 | Supervisor Gate 2B declares typedef struct InputMan InputMan; only when current type remains absent and no incompatible type exists. | strong | one-save S1 fresh-session type readback | IDA I001 | incorporate | primary supervisor | applied |
| C000299-025 | 000299 | Supervisor Gate 2B make_data deterministically replaces the four exact one-byte unknown heads at 0x0067ab44/45/46/47 with one four-byte InputMan *g_pInputMan item while preserving the exact four zero bytes, 18 xrefs, and all four address-comment prestates except the separately authorized I003 regular comment at 0x0067ab44. | very strong | S1 item/name/type plus bytes/xrefs/neighbors readback | IDA I002 four-byte item replacement | incorporate | primary supervisor | applied |
| C000299-026 | 000299 | Supervisor Gate 2B sets the exact regular address comment through set_address_comments and protects repeatable blank. | strong | S1 exact regular/repeatable channel readback | IDA I003 | incorporate | primary supervisor | applied |
| C000299-027 | 000299 | Supervisor Gate 2B enforces complete bytes, all four replaced item heads and comment channels, xrefs, names, types, neighbors, guarded immediate/pre-save/no-save/persistence/rollback readbacks, and separate determinate-success, determinate-failure/tool-error, and timeout/disconnect/missing-response save classifications with no blind retry. | very strong | P0 backup, one-save S1, fresh verifier, and two stable exclusive probes | IDA protections/four-head/save-response transaction | incorporate | primary supervisor | applied |
| C000299-028 | 000299 | Replace the exact manual by-memory UID000299 row after ordinary implementation. | strong | command 000000021436 exit 0/ok 1; SHA 91E60711...3F48F | by-memory/-coverage-report.md | incorporate | primary supervisor | applied |
| C000299-029 | 00006J | Replace the stale manual by-class UID00006J row without losing current class facts. | strong | command 000000021437 exit 0/ok 1; SHA C64EDFB0...1AC41 | by-class/-coverage-report.md | incorporate | primary supervisor | applied |
| C000299-030 | 0000K6 | Replace the stale manual by-file UID0000K6 row without losing current file facts. | strong | command 000000021438 exit 0/ok 1; SHA AA5292D6...FCAB | by-file/-coverage-report.md | incorporate | primary supervisor | applied |
| C000299-031 | 00050J | Use the validator-assigned UID in the exact new by-global manual row after dynamic no-clobber reread and apply it. | strong | command 000000021439 exit 0/ok 1; SHA F50BA4E7...709D | by-global/-coverage-report.md | incorporate | primary supervisor | applied |
| C000299-032 | 000299 | Validate the changed target with the scoped file validator and no hand edit to generated state. | procedural | command 000000021421, exit 0, ok 1, generated skipped | validator target receipt | incorporate | B002 callback | applied |
| C000299-033 | 00050J | Validate/register the new by-global page serially, capture UID00050J, and prove all registration tokens removed. | procedural | command 000000021418, exit 0, ok count 0, insert_uid 1, generated skipped | validator new-global receipt | incorporate | B002 callback | applied |
| C000299-034 | 00006J | Validate the changed class page with a scoped file validator. | procedural | command 000000021422, exit 0, ok 1, generated skipped | validator class receipt | incorporate | B002 callback | applied |
| C000299-035 | 0000K6 | Validate the changed file page with a scoped file validator. | procedural | command 000000021423, exit 0, ok 1, generated skipped | validator file receipt | incorporate | B002 callback | applied |
| C000299-036 | 000299 | After coherent generated refresh, InputMan.cpp must contain one definition and zero UID000299 empty markers. | strong | command 000000021445; InputMan.cpp BE58A47A...151E4 | generated InputMan.cpp | incorporate | primary supervisor | applied |
| C000299-037 | 00006J | After coherent generated refresh, InputMan.h must contain exactly one extern declaration and no duplicate definition. | strong | command 000000021445; InputMan.h 47F334EC...3C164 | generated InputMan.h | incorporate | primary supervisor | applied |
| C000299-038 | 000299 | After coherent refresh, ag-memory must show UID000299 non-emitting/false with semantic owner and the new global as the coded source item. | strong | command 000000021445; ag-memory 18A83A1B...A4DC | generated ag-memory | incorporate | primary supervisor | applied |
| C000299-039 | 000299 | After coherent refresh, tracker must show target 94/96 and report coverage without stale empty-emitter state. | strong | command 000000021445; tracker AE3D937E...BF11 | generated research tracker | incorporate | primary supervisor | applied |
| C000299-040 | 000299 | Re-read current manual/generated/session authority dynamically at every supervisor gate; dated hashes are not permanent current claims. | very strong | supervisor currentness readback through command 000000021445 and exact receipt hashes | report currentness | incorporate | primary supervisor | applied |
| C000299-041 | 000299 | Reject a duplicate extern declaration, duplicate CPP definition, NULL-only requirement, nullptr, raw IDA names, and direct-file-only final ownership. | strong | current four-destination physical no-change readback | target/global/class/file | reject-invalid | B002 callback | already-present |
| C000299-042 | 000299 | Fresh exact-artifact Gate 1 must verify all 33 sections and 45/45 ledger/checklist parity before callback or later lifecycle action. | procedural | supervisor audit Gate 1 passed; no validator command attributed | supervisor Gate 1 | incorporate | primary supervisor | applied |
| C000299-043 | 000299 | Gate 2A must verify every accepted ordinary claim and scoped validator receipt after callback. | procedural | supervisor audit Gate 2A passed; no validator command attributed | supervisor Gate 2A | incorporate | primary supervisor | applied |
| C000299-044 | 000299 | Gate 2B must apply or reject each IDA action through the literal transaction, including standalone explicit-failure/tool-error classification distinct from timeout/disconnect/missing response, guarded failing-saved restore, and final closed-disk proof; B002 never mutates IDA. | procedural | one-save P0-to-S1 transaction and fresh persistence proof passed | supervisor Gate 2B/save-response closure | incorporate | primary supervisor | applied |
| C000299-045 | 000299 | Report execution/archive and post-move audit remain supervisor-owned and authoritative only from current path plus validator history. | procedural | lifecycle boundary | supervisor lifecycle | not-applicable | primary supervisor | proposed |

## Positive Evidence Summary

- The target is exactly four bytes in virtual .data and reads zero before runtime initialization.
- Exactly 18 direct data xrefs exist and no xref query truncation occurred.
- Constructor writes this to the slot at 0x004e8b33 and clears on failure/unwind at 0x004e8b3a.
- Ordinary destructor, dedicated clear helper, and scalar deleting destructor each write zero.
- Thirteen readers span application cleanup/message routing, IME composition support, MainMenu initialization, Pane input-target tracking, TextEditPane input handling, and UserPane initialization.
- Current class formal H has the exact human declaration, and command `000000021445` proves generated `InputMan.h` emits it exactly once with zero definitions.
- Command `000000021445` proves generated `InputMan.cpp` now contains exactly one `InputMan *g_pInputMan = 0;` definition and zero UID000299 empty markers; this closes the historical empty-emitter defect without duplicate source.
- Adjacent singleton symbols use semantic by-global pages. The direct-file owner note itself says the arrangement exists only because a global page was missing.
- The exact target name and type are supported by lifecycle behavior, not just address adjacency.
- Gate 2B persisted the exact `InputMan` forward type, four-byte `g_pInputMan` item, and accepted regular comment while preserving forty zero bytes, both neighbors, and all 18 xrefs across a fresh verifier and two stable S1 exclusive probes.

## IDA MCP Facts

- Dated active research session: `primary-current-supervisor-202608060133`, PID 11540. This is historical pre-Gate2B research evidence, not current session authority.
- Historical P0 0x0067ab44 item: head 0x0067ab44, end 0x0067ab45, size 1, name unk_67AB44, type _DWORD *, is_code false, is_data false.
- 0x0067ab40 protected item: head 0x0067ab40, end 0x0067ab44, size 4, name dword_67AB40, is_data true.
- 0x0067ab48 protected item: head 0x0067ab48, end 0x0067ab49, size 1, name unk_67AB48, type _DWORD *, is_code false, is_data false.
- Bytes 0x0067ab30-0x0067ab58 are all zero in the loaded image.
- Comments at 0x0067ab40, 0x0067ab44, and 0x0067ab48: regular blank, repeatable blank.
- Historical P0 type/symbol state: `InputMan` absent and `g_pInputMan` query returned no results.
- Target xrefs: 18 data refs, exact inventory below.
- No function begins in the target range; it is data storage.
- Current supervisor-verified S1 after one save: `typedef struct InputMan InputMan;`, exact four-byte `InputMan *g_pInputMan` at `0x0067ab44`, and the accepted regular address comment persisted. Fresh session `primary-verify-uid000299-202608060350` proved the complete poststate plus unchanged predecessor, successor, forty zero bytes, and exact 18 xrefs; two closed-disk exclusive probes remained exact S1.
- P0 SHA/size was `B9D15E933B0FAA504D31F5AE9A20909534AF05A05157168BE072035D93251A46` / `143197476`; exact backup `NexusTK.exe.i64.bak-UID000299-prestate-20260806_0348` matched P0. S1 SHA/size is `1EE09DC2B6DD0A7F39EB4EE459FF8B785C6E4E6B913CDA6A827BDB4FFE1D741C` / `143197502`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| 0x0067ab44-0x0067ab48 | UID000299 by-memory target | Physical singleton pointer slot | false after semantic page exists | UID00050J g_pInputMan global | 94/96 | exact unsplit evidence page; IDA item persisted |
| g_pInputMan semantic symbol | UID00050J by-global/g_pInputMan.md | Sole source definition and lifetime contract | true | UID0000K6 InputMan file | 94/96 | registered/emitting |
| InputMan class | UID00006J by-class/InputMan.md | Class layout/API and sole extern declaration | true | UID0000K6 | retain 88/90 | support updated |
| InputMan source file | UID0000K6 by-file/InputMan.md | InputMan.cpp/InputMan.h source root | source root | FILE | retain 88/90 | support updated |
| 0x004e8af0-0x004e970d | UID00018E InputMan aggregate | Constructor/destructor/method bodies | true | UID00006J/UID0000K6 route | existing | behavior support |
| 0x0067ab40-0x0067ab44 | UID0001P6 g_pDATFileMgr | Predecessor singleton slot | separate | g_pDATFileMgr | existing | protected, not in target |
| 0x0067ab48-0x0067ab4c | UID0001P7 g_pKeySpeedMgr | Successor singleton slot | separate | g_pKeySpeedMgr | existing | protected, not in target |

## Direct Xref / Caller Inventory

The exact instruction renderings below are retained from dated P0 before Gate 2B, when IDA displayed `unk_67AB44`. Fresh S1 verification preserved the same 18 xref addresses; the current item is the typed/named `g_pInputMan` global recorded in `IDA MCP Facts`.

| Address | Containing function | Exact instruction | Role/evidence |
| --- | --- | --- | --- |
| 0x00464bff | sub_464A60, 0x00464a60-0x00464cc1 | mov ecx, dword ptr unk_67AB44 | Application cleanup consumer; loads the active manager. |
| 0x00464d94 | sub_464CD0, 0x00464cd0-0x00464e1f | mov ecx, dword ptr unk_67AB44 | Application/message-loop input-mode consumer. |
| 0x00465f84 | sub_465F20, 0x00465f20-0x0046673c | mov eax, dword ptr unk_67AB44 | Main window-message path consumer. |
| 0x004661c7 | sub_465F20 | mov ecx, dword ptr unk_67AB44 | Key/input-mode path consumer in the same application dispatcher. |
| 0x004e7600 | sub_4E7470, 0x004e7470-0x004e763c | mov ecx, dword ptr unk_67AB44 | IME composition helper consumer. |
| 0x004e8b33 | sub_4E8AF0, InputMan constructor | mov dword ptr unk_67AB44, eax | Publishes the constructed InputMan instance. |
| 0x004e8b3a | sub_4E8AF0 | mov dword ptr unk_67AB44, 0 | Constructor failure/unwind clear. |
| 0x004e8c81 | sub_4E8C20, ordinary destructor | mov dword ptr unk_67AB44, 0 | Ordinary teardown clear. |
| 0x004e9650 | sub_4E9650, size 0xb | mov dword ptr unk_67AB44, 0 | Dedicated singleton clear helper. |
| 0x004e96c8 | sub_4E9660, scalar deleting destructor | mov dword ptr unk_67AB44, 0 | Scalar teardown clear. |
| 0x004f6796 | MainMenuPane_MainMenuPane | mov ecx, dword ptr unk_67AB44 | MainMenu construction/input-mode consumer. |
| 0x004f8ae4 | MainMenuPane_InitializeMainUiGraph | mov ecx, dword ptr unk_67AB44 | Main UI graph/input-target consumer. |
| 0x005445cc | Pane__Destructor | mov ecx, dword ptr unk_67AB44 | Pane input-target deregistration consumer. |
| 0x00544ebb | sub_544EA0 | mov ecx, dword ptr unk_67AB44 | Pane input-target tracking branch. |
| 0x00544ecd | sub_544EA0 | mov ecx, dword ptr unk_67AB44 | Opposite tracking branch in the same helper. |
| 0x00544fa3 | sub_544F50 | mov ecx, dword ptr unk_67AB44 | Pane scalar teardown/input-target cleanup. |
| 0x00590f65 | TextEditPane__OnMouseEvent | mov ecx, dword ptr unk_67AB44 | Text edit input/IME consumer. |
| 0x005a25e0 | sub_5A2530 | mov ecx, dword ptr unk_67AB44 | UserPane initialization/input-mode consumer. |

## Documentation Evidence And IDA Status

- UID000299 now documents the correct address, pointer role, zero-filled bytes, all xref clusters, exact boundaries, UID00050J ownership, and non-emitting disposition.
- UID00006J documents the 0x20 InputMan layout, constructor/destructor/message methods, exact global lifecycle, and one extern declaration in formal H.
- UID0000K6 documents InputMan.cpp under NexusTK/input/, complete executable inventory, and g_pInputMan as an input-manager global. Its Parent-Gate Note explicitly treats direct file ownership as temporary because no by-global page existed.
- Command `000000021445` generated `InputMan.cpp` with exactly one definition and zero UID000299 markers; `InputMan.h` has one extern and zero definitions. ag-memory and tracker record the accepted owner/reconstructable/score state without stale empty-emitter status.
- Registered UID00050J closes the source-definition omission and restores the narrow semantic owner without moving Event, IMEPanes, PlatformApi, List, or Application responsibilities into InputMan.
- Current IDA improvement is supervisor-verified: the exact type/item/name/comment transaction persisted as S1, with all bounded protections/readbacks passing.
- Generated/manual hashes in this report are dated. Any concurrent unrelated change requires a no-loss reread, not a blind hash replacement.

## Ranked Ownership Analysis

### 1. New semantic by-global/g_pInputMan.md

- Evidence for: by-structure assigns process-wide singleton pointers to by-global; adjacent singleton pointers have semantic global pages; the target is a globally linked symbol with external declaration; the current file note admits its owner is a fallback caused by the missing page.
- Historical evidence against at assignment time: the page did not exist and required validator UID registration. Command `000000021418` resolved that procedural gap by assigning UID00050J.
- Decision: strongest and required. Registered [UID:00050J][g_pInputMan](by-global/g_pInputMan.md) is now the sole definition owner.

### 2. UID0000K6 InputMan file as final direct owner

- Evidence for: the symbol belongs in InputMan.cpp and the file already owns the class implementation.
- Evidence against: it is the source root, not the narrow semantic global symbol page; retaining it as direct canonical owner bypasses current by-global organization and preserves the documented workaround.
- Decision: retain as canonical owner/emitter of registered UID00050J, not as UID000299's final direct semantic owner.

### 3. UID00006J InputMan class as direct owner

- Evidence for: the pointer type is InputMan and the class header owns the extern declaration.
- Evidence against: g_pInputMan is a free process-wide global, not a static class data member. No mangled static-member access pattern or class-qualified symbol is observed.
- Decision: declaration support only; reject direct class ownership.

### 4. Consumer modules or no-owner

- Evidence for: Application, UI, IME, and Pane code read the pointer.
- Evidence against: consumers do not publish or own the singleton definition; InputMan lifecycle does. Ownership is fully resolvable.
- Decision: reject.

### Registered file/grouping

- Path: by-global/g_pInputMan.md.
- Registration result: command `000000021418` assigned UID00050J; callback readback finds zero registration tokens.
- Canonical owner/emitter: UID0000K6.
- Contents: exact source definition, zero-fill/source-spelling rationale, all 18 xrefs, constructor/destructor lifecycle, class-header extern relationship, boundaries, source placement, rejected alternatives, confidence/score rationale, and links to UID000299/UID00006J/UID00018E/UID0000K6.
- Scope: one global only. Do not create a broad InputManGlobals container or merge adjacent DATFileMgr/KeySpeedMgr symbols.

## Source Placement

- Source definition: NexusTK/input/InputMan.cpp through registered UID00050J by-global/g_pInputMan.md -> UID0000K6.
- Header declaration: NexusTK/input/InputMan.h through existing UID00006J class formal H.
- Physical storage evidence: UID000299, no independent source.
- Recommended definition placement: normal file-scope definition in InputMan.cpp. Exact emitter position may stay blank unless callback-time generated ordering requires a stable position; the source root currently places global definitions independently of the aggregate bodies.
- Rejected placement: Application.cpp, IMEPanes.cpp, Pane.cpp, MainMenuPane.cpp, by-class static member, broad data-section page, or standalone InputGlobals.cpp.
- Final-file uncertainty: none material. Existing project structure and InputMan dependencies agree on NexusTK/input/InputMan.cpp.

## Range / Split / Padding / Reclassification Analysis

- Exact range: [0x0067ab44,0x0067ab48), four bytes.
- Predecessor: item 0x0067ab40-0x0067ab44, current IDA dword_67AB40, documented g_pDATFileMgr slot.
- Target: current item is under-defined as one byte but xrefs and virtual storage prove a four-byte pointer.
- Successor: exact KeySpeedMgr slot begins at 0x0067ab48; current IDA has an under-defined one-byte item there, but documentation and xrefs keep it outside this target.
- No padding exists inside the target.
- No range split or merge is needed.
- Reclassification is documentary/source-layer only: the physical page becomes false/non-emitting after the semantic global page exists. The underlying source global remains reconstructable and is emitted by the new page.
- make_data at exactly 0x0067ab44 with a four-byte pointer is the required IDA item-boundary repair; delete_existing must not affect 0x0067ab40 or 0x0067ab48.

## Negative Evidence Summary

- Raw IDA name unk_67AB44 is not source evidence and must not survive into final C++.
- Historical ff ff ff ff / 0xffffffff is contradicted by both loaded bytes and the executable's virtual-zero-fill mapping.
- The 18 xrefs do not support DATFileMgr, KeySpeedMgr, Application, Pane, MainMenu, or IMEPanes ownership; those are adjacent symbols or consumers.
- No evidence supports InputMan **, void *, DWORD, HANDLE, or static InputMan member storage.
- No evidence supports a broad multi-global page or a range merge.
- No by-global page currently exists, but absence is a documentation gap, not proof that by-file is the narrow semantic owner.
- The class H already declares the symbol; adding another extern in target/global H would be duplicate source.
- nullptr is rejected as post-C++03 style. NULL is plausible but not preferred over the nearby = 0 convention.
- An uninitialized definition is behaviorally equivalent in zero-filled static storage but less explicit than the established source-family convention.
- No third-party import, compiler-generated covered-by function, or no-code global disposition applies to the semantic page.

## IDA Rename / Type / Comment Recommendations

The legacy runnable request package and transaction/rollback sequence were removed to [000299-g_pInputMan-empty-emitter-source-quality-removed.md](000299-g_pInputMan-empty-emitter-source-quality-removed.md). That companion is non-authoritative and must never be executed. The live report retains the complete evidence-supported state contract below.

### Dated observed state and declarative intended state

| ID | Entity | Dated observed prestate | Declarative intended state | Protected state / expected readback |
| --- | --- | --- | --- | --- |
| I001 | local type `InputMan` | `type_inspect` reported absent: `Type not found: InputMan`. | One incomplete forward type equivalent to `typedef struct InputMan InputMan;`; no full layout, size, members, bases, methods, or enums are inferred. | The type exists only as an incomplete declaration sufficient for `InputMan *`; no unrelated type-library delta. |
| I002 | `0x0067ab44-0x0067ab48` | Four separate one-byte unknown item heads. `0x0067ab44` was named `unk_67AB44`, displayed `_DWORD *`, and the other three bytes were unnamed/untyped. All four address-comment channels were blank; bytes were `00 00 00 00`; exactly 18 xrefs landed at `0x0067ab44`. | One four-byte data item headed at `0x0067ab44`, named `g_pInputMan`, typed `InputMan *`; the three following addresses are interior bytes rather than independent items. | Exact half-open interval, zero bytes, all 18 xrefs, neighboring items, and comments remain unchanged. No byte outside the interval is consumed. |
| I003 | regular comment at `0x0067ab44` | Regular and repeatable address comments blank. | Regular comment exactly `Process-wide InputMan singleton pointer; published by InputMan construction and cleared by destruction and unwind cleanup.` | Repeatable comment remains blank; both channels at `0x0067ab45-0x0067ab47` and neighboring items remain blank. |

### Complete protections

- Target bytes remain exactly four zero bytes, and surrounding `0x0067ab30-0x0067ab58` remains forty zero bytes.
- The predecessor item at `0x0067ab40` and successor at `0x0067ab48` retain their exact heads, ends, names, types, kinds, values, comments, and xrefs.
- The exact 18-address xref set and data-reference classification remain unchanged.
- `g_pInputMan` has no collision, and no other global, function, local, member, or type name changes.
- Only the incomplete `InputMan` declaration is added. No complete UDT or unrelated type-library state is authorized.
- No function boundary, name, signature, frame, local, decompilation, call graph, executable byte, or PE-image change is authorized.
- Runtime authority, mutation mechanics, persistence, recovery, and operational receipts remain external supervisor responsibilities. This report supplies state and evidence only.
## First-Draft C++ Recommendation

- UID000299 eligibility: its current combined score passes the source-entry gate, but after the semantic split it is deliberately a false/non-emitting physical evidence page. Its formal CPP and H blocks must both be blank.
- UID000299 CPP blank proof: any definition here would duplicate the semantic by-global definition. The target documents storage, not a second source entity.
- UID000299 H blank proof: UID00006J already emits the exact extern declaration once.
- Registered UID00050J CPP formal text:

~~~cpp
InputMan *g_pInputMan = 0;
~~~

- Registered UID00050J H formal text: blank.
- Existing UID00006J H declaration to preserve exactly:

~~~cpp
extern InputMan *g_pInputMan;
~~~

- Behavior preservation: static storage begins null, constructor publishes this, failure/destructor paths clear it, and all consumers read one process-wide pointer.
- Original-source shape: a file-scope pointer definition beside InputMan implementation plus an extern declaration in InputMan.h is plausible precompiled mid-2000s C++, unlike raw address labels or decompiler storage syntax.
- Source names: InputMan and g_pInputMan only.
- Style: = 0 is C++03-era and matches nearby DATFileMgr/KeySpeedMgr/global definitions. nullptr is forbidden.
- Third-party directive: not applicable.

## Final Recommendation

- Preserve registered [UID:00050J][g_pInputMan](by-global/g_pInputMan.md) as the semantic global at `94/96`, owner/emitter UID0000K6, reconstructable true, exact CPP definition, and blank H.
- Preserve UID000299 at `94/96`, owner UID00050J, reconstructable false, blank emitter/position/CPP/H, with exact zero-fill, item under-definition, PE mapping, all 18 xrefs, five lifecycle writes, thirteen consumers, source-facing type/name, exact boundaries, one-definition disposition, and historical ff correction.
- Preserve UID00006J at `88/90` with byte-identical formal H and the added UID00050J definition route/zero-fill evidence.
- Preserve UID0000K6 at `88/90` and `NexusTK/input/` with the semantic global route and historicalized stale initializer evidence.
- IDA: primary supervisor applied I001-I003 through the literal package after freezing all four one-byte heads and both comment channels at `0x0067ab44/45/46/47`; one `idb_save` produced stable S1 and fresh persistence verification passed every action/protection row.
- Manual coverage and generated/currentness work are supervisor-verified through commands `21436`-`21439` and `21445`. Report execution/archive authority remains supervisor-owned as enumerated.
- No unresolved target blocker remains; only exact original zero-token spelling is inferential and already resolved to the best source form.

## Recommended Target Doc Changes

- Path: by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md.
- Callback-applied metadata:
  - COMPLETION:94
  - CONFIDENCE:96
  - CANONICAL_OWNER:00050J
  - RECONSTRUCTABLE:FALSE
  - EMITTER_UIDS: blank
  - EMITTER_POSITION_OPTIONAL: blank
  - RECONSTRUCTION_CPP: blank
  - RECONSTRUCTION_H: blank
- Exact Item Summary replacement:
  - Exact loader-zero-filled four-byte backing slot for the process-wide InputMan singleton, with 18 complete application/IME/InputMan/UI xrefs, constructor publication and unwind clear, three teardown clears, exact adjacent singleton boundaries, and one-definition source routing through the semantic g_pInputMan global page; this physical page emits no duplicate C++.
- Layout replacement: current IDA prestate is one-byte unknown unk_67AB44 with displayed _DWORD *; physical source range is four bytes; mapped initial bytes are 00 00 00 00; semantic declaration/definition is InputMan *g_pInputMan = 0; on the global page.
- Applied evidence: dated MCP snapshot, PE virtual-zero-fill proof, complete 18-row xref table, comment/type/name prestate, class H declaration, and dated pre-refresh generated defect.
- Applied history: June ff/0xffffffff and direct-file-owner claims remain explicitly disproved/superseded rather than deleted.
- Applied assignment gate: UID00050J is the semantic parent and UID000299 is false/non-emitting physical evidence.
- No target formal source is allowed after the semantic page is established.

## Recommended Support Doc Changes

### [UID:00050J] by-global/g_pInputMan.md

- Created UID-less, then serially registered by command `000000021418`, which assigned UID00050J before dependent ordinary edits. Callback readback proves zero registration tokens.
- Metadata: 94/96, CANONICAL_OWNER 0000K6, RECONSTRUCTABLE TRUE, EMITTER_UIDS 0000K6, blank position, CPP exact definition, H blank.
- Status/Purpose: process-wide InputMan singleton pointer at UID000299; type InputMan *; source owner InputMan.cpp; declaration owner InputMan.h through UID00006J.
- Evidence: PE zero-fill, 18 xrefs, five publication/clear writes, thirteen consumers, boundaries, IDA prestate, no symbol/type/comment, class formal declaration.
- Lifetime: null before InputMan construction; published on successful construction; constructor-unwind, ordinary destruction, clear helper, and scalar destruction reset zero.
- Source shape: external file-scope definition, not class static, consumer-owned, broad global container, or duplicate physical-page emission.
- Rejected history: old ff initializer and temporary direct-file canonical owner.
- Links: UID000299, UID00006J, UID00018E, UID0000K6, Application, IME, Pane/MainMenu/TextEdit/UserPane consumers.

### UID00006J by-class/InputMan.md

- Keep metadata and complete H block unchanged.
- Add the semantic global page as the definition owner and UID000299 as physical backing evidence.
- Correct any live initializer wording to loader-zero-filled; retain old ff claim only as historical.
- Preserve every existing field/method/IMM/Event/List/size caveat.

### UID0000K6 by-file/InputMan.md

- Keep 88/90 and NexusTK/input/ route.
- Replace Parent-Gate Note with the new global direct semantic owner.
- Update State And Dispatch Inventory singleton row to distinguish semantic global, physical backing page, CPP definition, and class H extern.
- Correct stale 0xffffffff evidence.
- Preserve Event/IMEPanes/PlatformApi/List/Application ownership boundaries and all method inventory.

### No other ordinary page

- Existing consumers require no edit solely because they read the global. Their xrefs are incorporated into target/global evidence.
- Do not edit generated or manual coverage files in the B002 callback.

## Score And Metadata Recommendation

- UID000299 historical pre-callback state: 88/90, owner/emitter 0000K6, reconstructable true, blank CPP/H.
- UID000299 callback-applied state: 94/96, owner UID00050J, reconstructable false, emitter/CPP/H blank.
- UID00050J callback-applied state: 94/96, owner/emitter 0000K6, reconstructable true, CPP definition, H blank.
- UID00006J and UID0000K6: retain 88/90 because broader exact original field/helper spellings and candidate-deque ownership remain their own documented caps.
- Reason target not lower: exact bytes/section, all xrefs, lifetime, type/name, boundaries, owner hierarchy, C++ source split, IDA package, and coverage/generated obligations are closed.
- Reason target not 95 completion or 97+ confidence: no original symbol/PDB proves whether developers wrote implicit zero, = 0, or = NULL. The selected = 0 spelling is high-probability inference.
- Score-improvement attempts:
  - initializer blocker: solved by PE virtual-zero-fill.
  - xref/lifetime blocker: solved by exact 18-row inventory.
  - type/name blocker: solved by construction/member-use evidence and established class naming.
  - owner blocker: solved by semantic by-global creation.
  - CPP/H blocker: solved by sole definition plus existing sole declaration.
  - empty emitter: solved by physical-page reclassification and semantic global emission.
  - IDA blocker: solved and supervisor-applied through the three-action deterministic package with one-save S1 persistence proof.
- Metadata changes were applied only after command `000000021418` assigned UID00050J.

## Open Questions With Attempted Resolution

- Was the original initializer implicit, 0, or NULL?
  - Checked: PE raw/virtual mapping, live bytes, nearby global source forms, project era/style.
  - Resolution: use = 0 as the most realistic explicit source form. Exact token remains inferred but is not deferred.
- Is g_pInputMan a class static?
  - Checked: global address access and existing extern declaration.
  - Resolution: no; it is a free process-wide global.
- Is a by-global page actually required?
  - Checked: by-structure and three adjacent singleton patterns.
  - Resolution: yes; UID00050J is now the narrow semantic page.
- Should UID000299 keep emitting?
  - Checked: one-definition routing and g_pCheatDetector precedent.
  - Resolution: no; false/non-emitting physical evidence after global creation.
- Should the new global H repeat extern?
  - Checked: UID00006J and generated InputMan.h.
  - Resolution: no; class H remains sole declaration.
- Does auto_analysis_ready false block research?
  - Checked: health status and every bounded required call.
  - Resolution: no; MCP was responsive and exact evidence succeeded.
- Can an explicit idb_save failure/tool-error response be treated as equivalent to a timeout or as proof that nothing persisted?
  - Checked: save-call response classes, closed-worker/disk attribution requirements, and rollback safety under a response that may disagree with physical persistence.
  - Resolution: no. The determinate returned-error branch is standalone: freeze the response, never retry, retire/prove the worker absent, classify exact P0 as not persisted only after complete prestate/non-poststate proof, classify a failing-saved identity only after complete poststate and repeated exact transaction attribution, restore only that guarded identity from the intact P0 backup, and stop without overwrite for partial/mixed/both/neither/missing/unknown/third state. Timeout/disconnect/missing response remains a separate indeterminate branch.
- Which save-response branch occurred for the accepted supervisor transaction?
  - Resolution: the one canonical `idb_save` produced the accepted persisted S1 path. Fresh session and closed-disk exclusive-probe verification reproduced the complete poststate, so no failure, indeterminate, or rollback branch was used.
- No question remains with a material owner/type/source/score/C++ impact.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The following payload-time snapshots and exact payloads are retained as no-loss implementation history. Primary supervisor dynamically reread and applied all four rows through commands `000000021436`-`000000021439`, each exit `0`/`ok:1`. Current receipt hashes are by-memory `91E6071142DC79070054119F525C6D813D0EE85BF748B4FF5D19A8F8E493F48F`, by-class `C64EDFB074AD29F8C8A4194C66F31C28344B6CF394F29C4E4926C8D26E11AC41`, by-file `AA5292D61EF0300821326F549CF8616F7DB28C7AC629A5766C9BEC5A39B4FCAB`, and by-global `F50BA4E72FE183E95EE35A75BC5FE5015E767124C078F8325B13DC8A8E89709D`.

### by-memory/-coverage-report.md

- Historical callback-time preapplication SHA256: 8B4FAEBA4592B939006BCA10914621C43DAE9978887939CD2AB15354026094F9. Supervisor-applied command `000000021436`; current receipt SHA256 `91E6071142DC79070054119F525C6D813D0EE85BF748B4FF5D19A8F8E493F48F`.
- Historical preapplication UID000299 row: line 4704.
- Exact supervisor-applied replacement after ordinary docs and real global UID existed:

~~~text
    - [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md) 0x0067ab44-0x0067ab48 | physical singleton backing slot | g_pInputMan : ignored : 94% : very-strong : Exact loader-zero-filled four-byte backing slot for the process-wide InputMan singleton, with 18 complete application/IME/InputMan/UI xrefs, constructor publication and unwind clear, three teardown clears, exact adjacent singleton boundaries, and one-definition source routing through the semantic g_pInputMan global page; this physical page emits no duplicate C++.
~~~

### by-class/-coverage-report.md

- Historical callback-time preapplication SHA256: FA0D0E6F6FE388517A7CCBFE5C432D979B5C8E07292078C1DFDE2CF3194FAE71. Supervisor-applied command `000000021437`; current receipt SHA256 `C64EDFB074AD29F8C8A4194C66F31C28344B6CF394F29C4E4926C8D26E11AC41`.
- Historical preapplication UID00006J row: line 261 with stale 82%/strong summary.
- Exact supervisor-applied replacement:

~~~text
- [UID:00006J][InputMan](by-class/InputMan.md) : reconstructable : 88% : very-strong : Global Win32/IME input manager attached to InputMan.cpp with complete 0x20 layout, constructor/destructor/message-routing inventory, Application callers, IMM API behavior, exact g_pInputMan extern contract and semantic-global definition route, singleton/vtable lifetime evidence, and retained descriptive-spelling/candidate-deque ownership caveats.
~~~

### by-file/-coverage-report.md

- Historical callback-time preapplication SHA256: 4D4C1FABC5312CBF0D1A927415A7E814FB5A302BE1CEB80F85C83CC8CC273FA4. Supervisor-applied command `000000021438`; current receipt SHA256 `AA5292D61EF0300821326F549CF8616F7DB28C7AC629A5766C9BEC5A39B4FCAB`.
- Historical preapplication UID0000K6 row: line 123 with stale 84%/strong summary.
- Exact supervisor-applied replacement:

~~~text
- [UID:0000K6][InputMan](by-file/InputMan.md) : reconstructable : 88% : very-strong : Win32/IMM input manager under NexusTK/input/ with complete executable island and 0x20 class declaration, exact loader-zero-filled g_pInputMan semantic-global definition and header declaration route, constructor/destructor/application/UI lifetime evidence, Windows/IMM dispatch dependencies, and explicit Event/IMEPanes/PlatformApi/List ownership boundaries.
~~~

### by-global/-coverage-report.md

- Historical callback-time preapplication SHA256: A41D2CAA391B97C59E343D0B7FBA51B862A7776A260C143C023C4B7F5CCF6B38; zero g_pInputMan/UID00050J/UID000299 matches at that time. Supervisor-applied command `000000021439`; current receipt SHA256 `F50BA4E72FE183E95EE35A75BC5FE5015E767124C078F8325B13DC8A8E89709D`.
- Exact supervisor-applied new row using the real validator-assigned UID:

~~~text
- [UID:00050J][g_pInputMan](by-global/g_pInputMan.md) : reconstructable : 94% : very-strong : Sole loader-zero-initialized InputMan singleton definition in NexusTK/input/InputMan.cpp, backed by non-emitting physical UID000299 and exposed by the exact InputMan.h extern declaration; 18 direct refs cover application/IME/UI consumers, constructor publication and unwind clear, ordinary/clear-helper/scalar teardown, exact adjacent singleton boundaries, one-definition routing, and historical 0xffffffff correction.
~~~

- Applied placement: UID-sorted position for UID00050J after the supervisor's fresh no-clobber reread.
- No validator-owned auto-generated row is written here.
- Role boundary retained: B002 did not apply these manual rows; the primary supervisor applied and validated them.

## Follow-Up Actions

1. Dated current-artifact receipts establish supervisor Gate 1 and Gate 2A, Gate 2B one-save persistence closure, all four manual coverage updates, and one coherent generated/currentness refresh. Any later changed artifact or shared authority must be dynamically reread rather than inheriting these identities blindly.
2. Report execution/archive state and exact moved-artifact audit remain supervisor-owned and authoritative only from current path plus validator-owned history.
3. No A-agent or future B-agent research is needed for this target unless a later gate finds concrete new evidence.

## Confidence

- Runtime role/type/name: 98%.
- Address/range/bytes/xrefs/lifetime: 99%.
- Semantic by-global ownership and InputMan.cpp placement: 97%.
- Exact source declaration/definition split: 98%.
- Exact original initializer token: 90%; best inference = 0.
- Recommended target score: 94/96.
- Recommended global score: 94/96.
- Remaining uncertainty is source-token spelling only and does not justify raw labels, blank semantic C++, or continued direct-file-only ownership.

## Validator Results

- Callback commands run serially by B002 from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Removed executable PowerShell block R001; preserved verbatim in [000299-g_pInputMan-empty-emitter-source-quality-removed.md](000299-g_pInputMan-empty-emitter-source-quality-removed.md).

- `000000021418`, timestamp `2026-08-06T03:12:28-04:00`: by-global registration, exit `0`, `insert_uid:1`, assigned UID00050J, no `ok` row (`ok` count `0`), generated refresh skipped. Validator-owned side effects: UID/path/completion/confidence/owner/autogen registry updates, five UID-link insertions, six reference-index additions, and projected-stats update.
- `000000021421`, timestamp `2026-08-06T03:13:50-04:00`: by-memory target, exit `0`, `ok:1`, generated refresh skipped. Validator-owned side effects: metadata/owner/reconstructable/emitter registry updates, one UID-link/reference-index insertion, and projected-stats update.
- `000000021422`, timestamp `2026-08-06T03:14:43-04:00`: by-class support, exit `0`, `ok:1`, generated refresh skipped. Validator-owned side effects: two UID-link/reference-index insertions and projected-stats update.
- `000000021423`, timestamp `2026-08-06T03:15:53-04:00`: by-file support, exit `0`, `ok:1`, generated refresh skipped. Validator-owned side effects: three UID-link insertions, one reference-index addition, and projected-stats update.
- C000299-041 report-only no-change proof: current [UID:00050J] `Source Placement And One-Definition Rationale`, `Formal Source Decision`, and `Historical And Superseded Assumptions` physically require one CPP definition, exactly one class-owned extern declaration, blank global H, non-emitting physical storage, the human C++03 `= 0` form rather than `nullptr`, and treat `NULL` as only one unrecoverable spelling rather than a requirement; they explicitly reject raw IDA labels and duplicate physical-page emission. Current [UID:000299] `Reconstruction Notes`/`Assignment Gate`, [UID:00006J] `g_pInputMan Definition And Physical Backing Contract`, and [UID:0000K6] `Parent-Gate Note` independently preserve the one-definition/one-declaration split and identify direct-file-only ownership as a superseded temporary workaround. Current destination hashes are `51D84F5E...B737`, `347237E3...A7F6`, `8B10C640...F59CC`, and `AEE85D4F...6F9B4`; no ordinary document edit or validator run was needed for this reconciliation.
- Supervisor manual coverage receipts: commands `000000021436`, `000000021437`, `000000021438`, and `000000021439` each exited `0` with `ok:1`, producing current by-memory/by-class/by-file/by-global hashes `91E60711...3F48F`, `C64EDFB0...1AC41`, `AA5292D6...FCAB`, and `F50BA4E7...709D`.
- Supervisor coherent generated/currentness receipt: command `000000021445`, timestamp `2026-08-06T03:52:23-04:00`, exit `0`, `ok:1`, generated completed. Output hashes: `InputMan.cpp` `BE58A47A...151E4`, `InputMan.h` `47F334EC...3C164`, ag-memory `18A83A1B...A4DC`, tracker `AE3D937E...BF11`; all required semantic readbacks passed.
- Supervisor audit receipts state Gate 1 and Gate 2A passed; no validator command is attributed to either gate. Gate 2B passed through the separately recorded P0-to-S1 IDA transaction.
- No validator reported a target-specific error. B002 did not hand-edit validator state or projected stats.

## Changed Files

- Created by B002: `by-global/g_pInputMan.md`, registered as UID00050J.
- Modified by B002: `by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md`, `by-class/InputMan.md`, `by-file/InputMan.md`, and this same report.
- Validator-owned side effects: UID/link/reference/metadata registry state and `project-level/-auto-completion-stats.md` projected-path updates from commands 21418/21421/21422/21423. Generated refresh was skipped by all four commands.
- Primary-supervisor receipts, not B002 edits: canonical IDB advanced from exact P0 to verified S1 through one save; manual coverage commands `21436`-`21439` applied the four exact rows; generated/currentness command `21445` produced the accepted source/header/ag-memory/tracker outputs.
- Manual coverage, generated/tracker, goal/assignment, audit/catalog, report lifecycle, and IDA files modified by B002: none. This reconciliation edited only this report.
- B002 IDA/MCP role: research-time bounded read-only calls only; the primary supervisor exclusively performed the recorded mutation/save/persistence transaction.
- Leases: UID00050J, UID000299, UID00006J, and UID0000K6 were each held only for their immediate edit/validator batch and released. This report was held only for final reconciliation and released immediately after physical self-audit.
- Report lifecycle boundary: execution/archive truth is supervisor-owned and authoritative only from the current report path plus validator-owned status/history metadata.

## Implementation Tracking Checklist

| Done | Claim ID | Destination | Actor | Action | Verification state |
| --- | --- | --- | --- | --- | --- |
| [x] | C000299-001 | UID000299 Layout/Evidence/Changes | B002 callback | incorporate | applied |
| [x] | C000299-002 | UID000299 Layout/IDA Status | B002 callback | incorporate | applied |
| [x] | C000299-003 | UID000299 Evidence/Xrefs | B002 callback | incorporate | applied |
| [x] | C000299-004 | UID000299 Summary/Reconstruction | B002 callback | incorporate | applied |
| [x] | C000299-005 | UID000299 metadata/score | B002 callback | incorporate | applied |
| [x] | C000299-006 | UID000299 owner | B002 callback | incorporate | applied |
| [x] | C000299-007 | UID000299 metadata/formals | B002 callback | incorporate | applied |
| [x] | C000299-008 | UID000299 Item Summary | B002 callback | incorporate | applied |
| [x] | C000299-009 | UID000299 Layout/Boundaries | B002 callback | incorporate | applied |
| [x] | C000299-010 | new by-global page/registration | B002 callback | incorporate | applied |
| [x] | C000299-011 | new global metadata | B002 callback | incorporate | applied |
| [x] | C000299-012 | new global CPP | B002 callback | incorporate | applied |
| [x] | C000299-013 | new global H | B002 callback | incorporate | applied |
| [x] | C000299-014 | new global prose | B002 callback | incorporate | applied |
| [x] | C000299-015 | UID00006J metadata/H | B002 callback | already-present | already-present |
| [x] | C000299-016 | UID00006J Evidence/Global Route | B002 callback | incorporate | applied |
| [x] | C000299-017 | UID0000K6 metadata | B002 callback | already-present | already-present |
| [x] | C000299-018 | UID0000K6 Singleton/Parent Gate | B002 callback | incorporate | applied |
| [x] | C000299-019 | UID0000K6 Evidence/Inventory | B002 callback | incorporate | applied |
| [x] | C000299-020 | UID000299 Changes | B002 callback | historicalize | applied |
| [x] | C000299-021 | UID000299 Evidence/Xrefs | B002 callback | incorporate | applied |
| [x] | C000299-022 | UID000299 Reconstruction Notes | B002 callback | incorporate | applied |
| [x] | C000299-023 | UID000299 Range Analysis | B002 callback | incorporate | applied |
| [x] | C000299-024 | IDA I001 | primary supervisor | incorporate | applied |
| [x] | C000299-025 | IDA I002 four-byte item replacement | primary supervisor | incorporate | applied |
| [x] | C000299-026 | IDA I003 | primary supervisor | incorporate | applied |
| [x] | C000299-027 | IDA protections/four-head/save-response transaction | primary supervisor | incorporate | applied |
| [x] | C000299-028 | by-memory/-coverage-report.md | primary supervisor | incorporate | applied |
| [x] | C000299-029 | by-class/-coverage-report.md | primary supervisor | incorporate | applied |
| [x] | C000299-030 | by-file/-coverage-report.md | primary supervisor | incorporate | applied |
| [x] | C000299-031 | by-global/-coverage-report.md | primary supervisor | incorporate | applied |
| [x] | C000299-032 | validator target receipt | B002 callback | incorporate | applied |
| [x] | C000299-033 | validator new-global receipt | B002 callback | incorporate | applied |
| [x] | C000299-034 | validator class receipt | B002 callback | incorporate | applied |
| [x] | C000299-035 | validator file receipt | B002 callback | incorporate | applied |
| [x] | C000299-036 | generated InputMan.cpp | primary supervisor | incorporate | applied |
| [x] | C000299-037 | generated InputMan.h | primary supervisor | incorporate | applied |
| [x] | C000299-038 | generated ag-memory | primary supervisor | incorporate | applied |
| [x] | C000299-039 | generated research tracker | primary supervisor | incorporate | applied |
| [x] | C000299-040 | report currentness | primary supervisor | incorporate | applied |
| [x] | C000299-041 | target/global/class/file | B002 callback | reject-invalid | already-present |
| [x] | C000299-042 | supervisor Gate 1 | primary supervisor | incorporate | applied |
| [x] | C000299-043 | supervisor Gate 2A | primary supervisor | incorporate | applied |
| [x] | C000299-044 | supervisor Gate 2B/save-response closure | primary supervisor | incorporate | applied |
| [ ] | C000299-045 | supervisor lifecycle | primary supervisor | not-applicable | proposed |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000021450","destination_path":"executed-b-agent-research/B002/000299-g_pInputMan-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/000299-g_pInputMan-empty-emitter-source-quality.md","timestamp":"2026-08-06T04:04:37-04:00","uid":"000299"} -->
<!-- {"agent":"B002","command_id":"000000021916","details":"report marked for revalidation","event":"needs-revalidation","issue":"removed prohibited executable PowerShell fence; exact-artifact revalidation required","source_path":"executed-b-agent-research/B002/000299-g_pInputMan-empty-emitter-source-quality.md","timestamp":"2026-08-11T11:26:50-04:00","uid":"000299"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
