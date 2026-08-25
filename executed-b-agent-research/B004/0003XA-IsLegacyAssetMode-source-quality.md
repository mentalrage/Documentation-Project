** TARGET-REPORT-UID:0003XA **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003XA IsLegacyAssetMode Source-Quality Research

## Finalized Report / Current Recommendation

UID0003XA is a live, source-authored, externally linked global helper at exact half-open range `[0x004b60b0,0x004b60bd)`. Its 13-byte body returns the inverse of the one-byte `bool g_useEpfAssets`: `xor eax,eax; cmp g_useEpfAssets,1; setnz al; retn`. Live read-only IDA reports exactly 33 code callsites, no callees, no strings, no constants, one basic block, and cyclomatic complexity 1.

The full caller pass closes the former semantic-name blocker. Twenty-six callsites pass the result as the accepted `TextEditPane` constructor `legacyAssetMode` argument. The other seven pass it directly to `GrafPort::SetFontId`, whose exact accepted domain is `0..1` and whose destination is `unsigned short m_fontId` at `GrafPort+0x8a`. The helper therefore asks whether the client is in the legacy/non-EPF asset mode; the bool is then used as legacy font id 1 versus current/EPF font id 0. `IsLegacyAssetMode` is the strongest human source name and should remain canonical. `GetFontId`, `IsLegacyUiMode`, `IsCompactDisplayMode_4B60B0`, and `sub_4B60B0` are rejected as narrower, less consistent, or reverse-engineering-shaped alternatives.

Retain canonical owner/emitter UID0000SW `g_useEpfAssets` and its current file route UID0000O5 `StartupWindow`. The body owns no `FontImageLib`, `GrafPort`, or `TextEditPane` state. Physical adjacency to FontImageLib methods is valid linker/object-order evidence but does not override the direct global dependency, the sole observed global write in `StartupWindow::StartupWindow`, or the existing one-definition route. The helper must remain one external definition plus one shared declaration; 33 out-of-line calls spanning unrelated source families reject `static`, per-caller copies, and a header-inline source body.

The existing target CPP body is source-correct and behavior-exact for the accepted `bool` global type. At the explicitly historical bounded command `000000020493` checkpoint, generated `StartupWindow.h` contained only `extern bool g_useEpfAssets;` because UID0000SW H had no `[[CHILDREN]]` expansion point. The accepted ordinary-document repair supplies a complete guarded UID0000SW H payload containing the global declaration and `[[CHILDREN]]`; current generated-output truth is authoritative only from a fresh supervisor readback of validator-owned output.

Recommended target metadata is `92/93`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000SW`, and `EMITTER_UIDS:0000SW`. Completion rises because the complete caller semantics, linkage, source route, formal CPP/H topology, manual coverage gap, IDA handoff, and stale history are now resolved. Confidence rises while remaining below certainty because no PDB/source artifact proves the exact original helper spelling or translation-unit name.

Historical callback record (`2026-08-01`): C01-C27 were applied or verified at full report detail in the five authorized destinations, C28-C34 were reread and verified as unchanged support dispositions, and the five required scoped validators passed with generated refresh disabled. This report does not assert the current state of manual coverage, generated/tracker output, IDA, audit/catalog data, or report execution/archive; those truths are authoritative only from fresh supervisor readback, the report's current path, and validator-owned status/history metadata.

## Supporting Research

- Primary target: UID0003XA `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`, post-validation SHA256 `80EAA64D25F955A306A28CE852C6C3BAF855C5A0DBF5D8E1EBBDFB3F479B9C3D`, 14,522 bytes, 149 lines. Its accepted report-time pre-callback identity was SHA256 `AC05FC023C6B82374E2ECE40C8785F542836A3F24205960035626625E7B11F13`, 6,000 bytes, 84 lines.
- Semantic global owner: UID0000SW `by-global/g_useEpfAssets.md`, post-validation SHA256 `09DE791E1AC135DFFA10AE95EAE81814978C018EF606975CA85FE9AD5EEE06C3`, 24,532 bytes, 182 lines. Its accepted report-time pre-callback SHA256 was `F047C1989FAFDEC16F3DB081B4E823AA921A9ECE4484A18A97DB87502949C031`.
- Exact storage child: UID0001OH `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`, post-validation SHA256 `35AA50F4910E6B294527BA6D2F31F3205418452FBE940BFAC1B8F1DB8575D23E`, 16,852 bytes, 132 lines. Its accepted report-time pre-callback SHA256 was `0285043B46ABD1E45194F4011C1AB55CDB006C4676FCC9560F6231847B3A1163`.
- Current file route: UID0000O5 `by-file/StartupWindow.md`, post-validation SHA256 `0B3C85DE029B8DA01A0DAE0237F7F324FDB3D4C3346DBA8DCBAF9E18FA5040D4`, 62,930 bytes, 305 lines. Its accepted report-time pre-callback SHA256 was `DCA095B351E9FCE87DCB5D2CDE0E7015F3C3124F0A3EEB79E01948F3B5B2325A`.
- Mixed physical parent: UID00015A `by-memory/0x004b5f00-0x004b6409.FontImageLib.md`, post-validation SHA256 `DC51CE1F03E419558023325A1BC64C3A01AC409F3B42A1A463C1E8299C523250`, 19,883 bytes, 157 lines. Its accepted report-time pre-callback SHA256 was `28E8A7163D0BF78748EB4C66DF7651EDF51E3EDEAAA5442C5C55160747995639`.
- FontImageLib source/class exclusions: UID0000JH SHA256 `1EDDB096D765C2DEE11BD7A43170B9239CC2E9060FAC4F443A19295AC76AB5D5`; UID00005B SHA256 `3A845C87CFAB8121E80FB33F0376B4F50E91D0FCCF89E14491201E7C9F22ADB7`.
- TextEditPane consumer contract: UID0000EO SHA256 `DE16797441A77EAB17D9414E9F2FBAA4CD52D034B5A26476A46A45720FD24A96`; UID0000ON SHA256 `677C5D58311C9A263D17139E4FFEA90837587D25365DB0220827AB7A353E873D`.
- GrafPort font-id contract: UID000162 SHA256 `6B5D6739EB8436DB939D9AFC71243996D974D9EB149FCFF6C3821CB959F76596`; UID00005V SHA256 `C7F0E15DE5FBD9747328F567E42F5081A3B54D38BF7688DBBE15F2EC1D73CF1A`; UID0000JR SHA256 `4EA6DDFC853BC82D724D777BB77BC8D97D0C3AFA2D1285E77A440EA120B3CA3F`.
- Matching executed reports inspected as evidence/history, not blindly copied: `executed-b-agent-research/B001/00015A-0002HP-fontimagelib-source-quality.md`, `executed-b-agent-research/B001/0000SW-g_useEpfAssets.md`, `executed-b-agent-research/B010/0000JH-FontImageLib-empty-emitter-family-source-quality.md`, `executed-b-agent-research/B001/000162-GrafPortDrawStateAccessors-source-quality.md`, `executed-b-agent-research/B001/0002ZY-TextEditPaneConstructor-source-quality.md`, and the caller-family reports found by UID/address/name search.
- The prior B001 UID00015A report discovered the split and 33 calls but intentionally left the helper name/formal route pending. Current docs later populated CPP/H and IDA names, so its blank-source recommendation is dated history rather than current truth.
- Live IDA MCP was mandatory and used read-only. Session `f608d7c2` reported `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, strings cache ready, and `auto_analysis_ready:false`; bounded target-backed queries succeeded, so the health flag was not an availability blocker.
- The physical saved IDB observed for this report was `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, 143,192,751 bytes, saved 2026-07-31T06:21:13.3464834-04:00. This is a dated report-time checkpoint, not a permanent global-currentness claim.
- Bounded generated/tracker checkpoint command `000000020493`, refreshed 2026-07-31T10:40:09-04:00 from `foreground-generated-refresh`: `auto-generated/NexusTK/app/StartupWindow.cpp` SHA256 `07D2188F4B6B5272DD3A3277E1D37368E02E322A9170A2290DD0D3BCC799A9D6`, 21,952 bytes/514 lines; `StartupWindow.h` SHA256 `F6BEBA4D21C7CD02EEAEF563CED7527A4E41AACB1B79D317AD786B3132FD4C9D`, 416 bytes/8 lines; `auto-generated/-ag-memory-coverage.md` SHA256 `AA9079AB934EE980C004BB3A767E2E453F290345BE957FD0EE973C157FDA8C36`, 1,430,860 bytes/4,985 lines, UID0003XA row 922; tracker SHA256 `13F74CBAA11133CF1CE2F061C0A9E27A70E6D18A57C7770A4F800F777AB7EDBE`, 1,690,672 bytes/6,676 lines. These are dated moving-artifact observations, not durable authority after a later validator refresh.

## Target

- Primary target UID: `0003XA`.
- Primary path: `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`.
- Primary address inventory: exactly `[0x004b60b0,0x004b60bd)`; no second function, data island, or padding is inside the target.
- Additional target UIDs: none.
- Source queue row at report time: bounded validator command `000000020493`, tracker line 1680, `86/90`, total `88.0`, reconstructable `true`, direct/additional/total coverage `0/0/0`. That moving tracker snapshot has not been refreshed or edited in this callback.
- Report classification: implementation-callback research artifact with dated ordinary-document and validator evidence. Current Gate/lifecycle disposition is not asserted here and must be read from a fresh exact-artifact supervisor audit, the report's current path, and validator-owned status/history metadata.
- Support-only UIDs: `0000SW`, `0001OH`, `0000O5`, `00015A`, `0000JH`, `00005B`, `0000EO`, `0000ON`, `000162`, `00005V`, and `0000JR`. None is claimed as an additional report target.

## Current Target State

- Metadata is now `92/93`, reconstructable, owner/emitter UID0000SW.
- Formal CPP is nonblank and contains `bool IsLegacyAssetMode() { return !g_useEpfAssets; }`.
- Formal H is nonblank and contains `bool IsLegacyAssetMode();`.
- Bounded command `000000020493` generated CPP contains the global definition followed by UID0003XA's exact body in `NexusTK/app/StartupWindow.cpp`; its exact report-time identity is listed under Supporting Research.
- The same bounded command `000000020493` generated H contains only `extern bool g_useEpfAssets;`; UID0003XA's declaration is absent. This is a source-channel topology defect, not evidence that the target H should be blank.
- The bounded command `000000020493` tracker snapshot lists UID0003XA at line 1680 as reconstructable `86/90`, total `88.0`, and direct/additional/total B-report coverage `0/0/0`. Tracker command/hash/line state is validator-owned moving evidence and must be reread at supervisor action time.
- Current target prose contains the exact body, range, ABI, owner, complete 33-call/26-7 split, rejected alternatives, external-linkage proof, dated generated-H defect, source-placement ranking, strict padding, score rationale, and literal IDA handoff. This report does not assert current manual-coverage or IDA/Gate disposition; fresh supervisor readback and authoritative validator/project artifacts control those states.
- The history line saying formal C++ remained blank is preserved and explicitly labeled as superseded historical pre-name state rather than deleted.
- The report artifact is `tools/leaser/Agents/Agent-B004/research/0003XA-IsLegacyAssetMode-source-quality.md`; execution/archive truth remains authoritative only from its actual path plus validator-owned status/history metadata.

## Executive Recommendation

Implement the target as one free `bool IsLegacyAssetMode()` definition and one declaration. Keep the body `return !g_useEpfAssets;`, because `g_useEpfAssets` is a one-byte `bool` with observed value/write 1 and current MSVC-shaped decompilation directly recovers logical negation. Do not model noncanonical corrupted byte values as authored source state.

Keep UID0000SW as semantic owner/emitter and UID0000O5 as current source route. Repair UID0000SW's H block so the target H child is emitted inside a complete `NEXUSTK_APP_STARTUPWINDOW_H` guard. Do not duplicate the helper in FontImageLib, GrafPort, TextEditPane, or each caller file.

Raise only UID0003XA to `92/93`. Retain support scores and metadata unless the physical callback reveals contradictory content. Apply the exact IDA comment cleanup through supervisor Gate 2B only. Apply four manual coverage operations and retain the explicit no-op rows listed later. Refresh generated output only through supervisor/validator closure.

## Supervisor Active Recheck

- Recheck the exact report artifact after every report edit; any edit invalidates a prior Gate 1 hash.
- Historical callback record (`2026-08-01`): all target/support physical hashes were verified. Tracker/generated command headers in this report are dated report-time evidence only; current truth requires fresh supervisor readback of the authoritative artifacts.
- Before Gate 2B, reread all eight action rows and six protected dependency rows against the then-current saved IDB. A newer unrelated IDB hash is not semantic drift, but literal prestate differences must fail closed.
- Before applying manual coverage, reread the four exact operation rows and anchors because shared coverage files are supervisor-owned moving artifacts.
- After callback, independently compare target/support docs, formal channels, generated `StartupWindow.cpp/.h`, and the ledger claim by claim.
- Only the supervisor may mutate/save IDA, edit manual coverage, refresh generated output, or run report lifecycle/`execute_report` actions.

## Inference Research Guidance Check

The report applies the project's dual requirement: exact runtime behavior and plausible human source shape. Raw labels are not retained merely because original symbols are absent. The accepted names follow existing project vocabulary (`g_useEpfAssets`, `legacyAssetMode`, `GrafPort::SetFontId`) and preserve a consistent bool query idiom. The source body is not decompiler-shaped and does not expose addresses, `byte_66DA97`, `sub_4B60B0`, or `setnz`.

Inference is bounded by direct evidence. `IsLegacyAssetMode` is not presented as a recovered PDB symbol. StartupWindow is the current reconstruction route, not asserted as a proven original filename. The physical FontImageLib adjacency is retained as counter-evidence. Execution replication outranks stylistic consistency; consistency is used only after the exact bool behavior, ABI, range, and caller flow are fixed.

Wave2/Wave3 mentions in older material were ignored as stale guidance. Current by-* docs, live IDA, generated output, current reports, and current project rules control this recommendation.

## Heuristic / Inference Reanalysis And Validation

### Behavior and type

- `xor eax,eax` clears the full return register; `setnz al` yields exactly 0 or 1.
- `cmp g_useEpfAssets,1` is consistent with MSVC bool normalization. Current IDA types the storage as one-byte `bool` and the function as `bool __cdecl()`.
- Initial storage is 1. Existing exhaustive support research reports 366 data xrefs, 365 reads, and one write; fresh live IDA reconfirmed total 366 and the sole known writer body at `0x005807f3` assigns 1.
- `return !g_useEpfAssets;` is exact for all legal bool states and is more plausible authored C++ than `return g_useEpfAssets != 1;`. The latter is retained as machine-level explanation, not final source shape.

### Caller semantics

- Twenty-six calls flow into TextEditPane construction as the accepted `unsigned short legacyAssetMode` argument.
- Seven calls flow into `GrafPort::SetFontId(unsigned short)`, which accepts only 0 or 1 and writes `m_fontId +0x8a`.
- The two consumer forms are consistent: legacy mode true maps to legacy font slot/id 1; EPF/current mode maps to slot/id 0.
- No caller treats the result as a pointer, count, arbitrary integer, class receiver, resource handle, or FontImageLib object.

### Linkage

- The one function body has 33 direct out-of-line calls spanning dialog, control, group, macro, text, and user-look families.
- A file-static function cannot satisfy calls from those independently reconstructed source roots.
- A header-inline function would ordinarily produce per-TU inline code or COMDAT copies; the observed single external address and call edges support one external definition plus a shared declaration.
- The helper has no `this`, arguments, local variables, strings, constants, or callees.

### Source placement ranking

1. UID0000SW -> UID0000O5 current global/StartupWindow route: best current reconstruction. The helper depends solely on the global, the global's only observed writer is StartupWindow construction, and this route already owns the one definition.
2. A hypothetical shared asset-mode/global utility file: semantically plausible but no current by-file page, source-tree evidence, or neighboring coherent helper family proves such a file. Creating it would invent topology.
3. UID0000JH FontImageLib.cpp: physical adjacency and font-slot consumption are real positive evidence, but the helper touches no FontImageLib state and FontImageLib methods do not call it. Retain as a source-placement confidence cap, not canonical ownership.
4. GrafPort/TextEditPane or caller files: rejected as consumers. They neither own nor write the global and cannot explain the shared call fan-in.

### Formal channel closure

- UID0000SW CPP already has `[[CHILDREN]]`, so UID0003XA CPP emits correctly.
- UID0000SW H lacks `[[CHILDREN]]`, so UID0003XA H is silently absent from generated `StartupWindow.h`.
- A complete guarded UID0000SW H block with the existing extern followed by `[[CHILDREN]]` repairs declaration visibility without inventing a second definition.

## Evidence Standards Used

- Direct: exact IDA function/range/type/decompile/disassembly/bytes, item bounds, comments, frame, xrefs, and bounded command20493 generated files.
- Corroborated: current target/global/storage/class/file docs and executed caller-family research.
- Inferred: exact original identifier and source filename. These are explicitly ranked and never presented as symbol recovery.
- Negative: no function arguments/locals/callees/strings/constants; no FontImageLib state access; no duplicate helper body; no target row under the manual parent; no target declaration in generated H.
- Mechanical: exact hashes, byte/line counts, UID metadata, coverage anchors, and tracker/generated command headers.

## Evidence Checked

- `server_health`, `analyze_function`, `decompile`, `xref_query`, `entity_query`, `get_comments`, `inspect_items`, `stack_frame`, and `get_bytes` were used through bounded read-only JSON-RPC calls.
- Target `analyze_function` returned exact name `IsLegacyAssetMode`, declaration `bool __cdecl()`, size 13, 33 xrefs, no callees/strings/constants, one basic block, and the exact logical-not decompilation.
- Target `xref_query` returned all 33 code callsites with no pagination remainder.
- Global `xref_query` returned total 366 data refs; output pagination was not used as a substitute for the existing exhaustive 365-read/one-write classification.
- `StartupWindow__Constructor` live decompilation reconfirmed `g_useEpfAssets = 1` at `0x005807f3`.
- `sub_4B9640` live decompilation resolved the formerly generic GrafPort consumer: exact `unsigned __int16 __thiscall(_WORD *this,unsigned __int16)` body, argument domain `<=1`, and store to `this[69]` / `+0x8a`; current ordinary docs identify it as `GrafPort::SetFontId` / `m_fontId`.
- Exact target/global comments, target frame, boundary items, neighboring globals, predecessor/successor functions, and bytes were reread.
- Bounded command20493 generated `StartupWindow.cpp/.h`, tracker, generated memory coverage, and all applicable manual coverage rows were read without editing.
- Active and executed report trees were searched by UID, exact address, helper name, global name, caller names, and source families. No active duplicate report claims UID0003XA.
- One earlier broad MCP search timed out while the listener/session remained available; it was discarded and replaced with the bounded calls enumerated above. All required narrow target/global/caller/boundary queries then succeeded, so no MCP-backed evidence in the final report depends on the failed broad request.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | 0003XA | Exact target is one 13-byte function at `[0x004b60b0,0x004b60bd)`. | high | live function/item/bytes | `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` / Status and Range | incorporate | applied-and-readback-verified |
| C02 | 0003XA | Exact body returns logical inverse of bool `g_useEpfAssets`. | high | disassembly/decompile/type | `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` / Behavior | incorporate | applied-and-readback-verified |
| C03 | 0003XA | Exact return ABI is `bool __cdecl()` with no arguments or locals. | high | IDA declaration/frame | `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` / Behavior and ABI | incorporate | applied-and-readback-verified |
| C04 | 0003XA | All 33 code xrefs are inventoried exactly. | high | complete xref query | `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` / Direct Caller Inventory | incorporate | applied-and-readback-verified |
| C05 | 0003XA | Twenty-six callsites supply TextEditPane `legacyAssetMode`. | high | caller decompilation and current TextEditPane docs | `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` / Caller Semantics | incorporate | applied-and-readback-verified |
| C06 | 0003XA | Seven callsites feed `GrafPort::SetFontId` and map bool to font id 0/1. | high | caller decompilation, UID000162 | `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` / Caller Semantics | incorporate | applied-and-readback-verified |
| C07 | 0003XA | `IsLegacyAssetMode` is accepted human source name; raw/narrow aliases are rejected. | high | complete caller semantics/global meaning | `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` / Heuristic Source-Quality Decision | incorporate | applied-and-readback-verified |
| C08 | 0003XA | Helper requires one external definition and shared declaration. | high | single address plus cross-family callers | `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` / Source Linkage | incorporate | applied-and-readback-verified |
| C09 | 0003XA | Owner/emitter remain UID0000SW. | high | sole global dependency and project ownership route | `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` / metadata | already-present | verified-current |
| C10 | 0003XA | Current file route remains UID0000O5 with explicit inference caveat. | medium-high | sole writer and existing route; adjacency counter-evidence | `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` / Source Placement | incorporate | applied-and-readback-verified |
| C11 | 0003XA | Formal CPP remains exact `return !g_useEpfAssets;`. | high | bool type/codegen/decompile | `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` / RECONSTRUCTION_CPP | already-present | verified-current |
| C12 | 0003XA | Formal H remains `bool IsLegacyAssetMode();`. | high | external-linkage proof | `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` / RECONSTRUCTION_H | already-present | verified-current |
| C13 | 0003XA | Target score changes `86/90 -> 92/93`; other metadata retained. | high | blocker closure and residual lexical/file inference | `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` / metadata and Score Rationale | incorporate | applied-and-readback-verified |
| C14 | 0003XA | Stale history claiming formal CPP blank becomes explicitly superseded history. | high | physical nonblank CPP and generated code | `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` / Change History | historicalize | applied-and-readback-verified |
| C15 | 0000SW | Add exact UID0003XA body/type/33-call relationship without pruning 366-xref global evidence. | high | live/helper/global docs | `by-global/g_useEpfAssets.md` / helper evidence | incorporate | applied-and-readback-verified |
| C16 | 0000SW | Retain sole CPP definition and CPP `[[CHILDREN]]`. | high | current formal/generated one-definition route | `by-global/g_useEpfAssets.md` / RECONSTRUCTION_CPP | already-present | verified-current |
| C17 | 0000SW | Replace H with complete guard, extern, and H `[[CHILDREN]]`. | high | generated declaration absence | `by-global/g_useEpfAssets.md` / RECONSTRUCTION_H | incorporate | applied-and-readback-verified |
| C18 | 0000SW | Retain `88/90`, owner/emitter UID0000O5. | high | broader 366-ref global scope not reaudited exhaustively here | `by-global/g_useEpfAssets.md` / metadata | already-present | verified-current |
| C19 | 0000SW | Preserve StartupWindow as best current route while labeling exact original declaration file unresolved. | medium-high | sole writer and negative Application/Config evidence | `by-global/g_useEpfAssets.md` / Ownership | incorporate | applied-and-readback-verified |
| C20 | 0001OH | Add exact saved IDA name/type/value/comments/boundaries and UID0003XA dependency. | high | live item/comments/bytes | `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md` / Evidence | incorporate | applied-and-readback-verified |
| C21 | 0001OH | Retain no-duplicate CPP marker and blank H. | high | global owner emits definition/declaration | `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md` / formal CPP/H | already-present | verified-current |
| C22 | 0001OH | Retain `88/90`, owner/emitter UID0000SW. | high | exact storage strong; broader name/file inference remains | `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md` / metadata | already-present | verified-current |
| C23 | 0000O5 | Add UID0003XA external helper definition/declaration route and global dependency. | high | current emitter topology | `by-file/StartupWindow.md` / Source Inventory | incorporate | applied-and-readback-verified |
| C24 | 0000O5 | Add generated-H defect and guarded child-expansion repair. | high | bounded command20493 physical H | `by-file/StartupWindow.md` / Generated Status | incorporate | applied-and-readback-verified |
| C25 | 0000O5 | Retain `89/88`; exact original file assignment remains inferred. | medium-high | file scope broader than target | `by-file/StartupWindow.md` / score | already-present | verified-current |
| C26 | 00015A | Add full UID0003XA caller/owner/formal separation while retaining mixed island facts. | high | range, neighbors, callers | `by-memory/0x004b5f00-0x004b6409.FontImageLib.md` / child inventory | incorporate | applied-and-readback-verified |
| C27 | 00015A | Retain `90/94`, nonreconstructable, owner NONE, blank CPP/H. | high | exact child split/no-duplicate rule | `by-memory/0x004b5f00-0x004b6409.FontImageLib.md` / metadata and formals | already-present | verified-current |
| C28 | 0000EO | Existing TextEditPane declaration already uses `legacyAssetMode`; no edit. | high | physical class page | `by-class/TextEditPane.md` / formal H | already-present | verified-no-change |
| C29 | 0000ON | Existing file page already states argument ten receives `IsLegacyAssetMode`; no edit. | high | physical file page | `by-file/TextEditPane.md` / constructor support | already-present | verified-no-change |
| C30 | 000162 | Existing accessor page already proves `SetFontId`, `m_fontId+0x8a`, and 0/1 domain; no edit. | high | physical accessor page/live decompile | `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md` / function inventory | already-present | verified-no-change |
| C31 | 00005V | Existing GrafPort class declaration/field topology is sufficient; no edit. | high | physical class page | `by-class/GrafPort.md` / formal H | already-present | verified-no-change |
| C32 | 0000JR | Existing GrafPort file ownership is sufficient; no edit. | high | physical file page | `by-file/GrafPort.md` / ownership | already-present | verified-no-change |
| C33 | 0000JH | Existing FontImageLib file page already rejects UID0003XA ownership and preserves mixed-island separation; no edit. | high | physical file page | `by-file/FontImageLib.md` / exclusions | already-present | verified-no-change |
| C34 | 00005B | Existing FontImageLib class page already excludes the helper; no edit. | high | physical class page | `by-class/FontImageLib.md` / child inventory | already-present | verified-no-change |
| C35 | 0003XA | Historical command20493 StartupWindow.cpp body was semantically correct and singular; current generated truth requires fresh readback. | high | bounded command20493 output | `auto-generated/NexusTK/app/StartupWindow.cpp` / UID0003XA readback | already-present | historical-command20493-current-readback-authoritative |
| C36 | 0003XA | Historical command20493 StartupWindow.h lacked the helper declaration; accepted owner H child expansion supplies the source repair, while current generated truth requires fresh readback. | high | bounded command20493 output | `auto-generated/NexusTK/app/StartupWindow.h` / UID0000SW and UID0003XA readback | incorporate | historical-command20493-current-readback-authoritative |
| C37 | 0003XA | Historical bounded tracker command20493 showed `0/0/0`; current tracker truth is authoritative only from fresh validator-owned state. | high | command20493 moving snapshot | `auto-generated/-ag-research-tracker.md` / UID0003XA row | incorporate | historical-command20493-current-readback-authoritative |
| C38 | 0003XA | Insert exact target row under UID00015A after UID0002HR in address order. | high | bounded report-time manual by-memory block | `by-memory/-coverage-report.md` / UID00015A children | incorporate | current-manual-readback-authoritative |
| C39 | 0001OH | Replace stale by-memory storage row no-loss at its bounded exact anchor. | high | bounded row says 86 and no owner proven | `by-memory/-coverage-report.md` / UID0001OH | incorporate | current-manual-readback-authoritative |
| C40 | 0000SW | Replace by-global row no-loss to add UID0003XA and H route. | high | bounded report-time row inspection | `by-global/-coverage-report.md` / UID0000SW | incorporate | current-manual-readback-authoritative |
| C41 | 0000O5 | Replace by-file row no-loss to add global/helper/formal route. | high | bounded report-time row inspection | `by-file/-coverage-report.md` / UID0000O5 | incorporate | current-manual-readback-authoritative |
| C42 | 00015A | Parent manual row already names separate UID0003XA; retain and insert only missing child. | high | bounded by-memory row | `by-memory/-coverage-report.md` / UID00015A parent | already-present | current-manual-readback-authoritative |
| C43 | 0000JH | FontImageLib manual file row already preserves mixed UID00015A/UID0003XA split; no-op. | high | bounded by-file row | `by-file/-coverage-report.md` / UID0000JH | already-present | current-manual-readback-authoritative |
| C44 | 0000EO | TextEditPane manual class row already has complete declaration union; no-op. | high | bounded by-class row | `by-class/-coverage-report.md` / UID0000EO | already-present | current-manual-readback-authoritative |
| C45 | 00005V | GrafPort manual class row remains sufficient for the accepted accessor; no-op. | high | bounded by-class row | `by-class/-coverage-report.md` / UID00005V | already-present | current-manual-readback-authoritative |
| C46 | 0003XA | IDA-3XA-001 name no-change readback. | high | live exact target | IDA function `0x004b60b0` name | already-present | current-IDA-readback-authoritative |
| C47 | 0003XA | IDA-3XA-002 declaration no-change readback. | high | live exact target | IDA function `0x004b60b0` type | already-present | current-IDA-readback-authoritative |
| C48 | 0003XA | IDA-3XA-003 removes terse function-regular comment. | high | literal report-time comment | IDA function `0x004b60b0` FR | incorporate | current-IDA-readback-authoritative |
| C49 | 0003XA | IDA-3XA-004 inserts exact function-repeatable comment. | high | resolved caller semantics | IDA function `0x004b60b0` FP | incorporate | current-IDA-readback-authoritative |
| C50 | 0000SW | IDA-3XA-005 global name no-change readback. | high | live exact global | IDA data `0x0066da97` name | already-present | current-IDA-readback-authoritative |
| C51 | 0000SW | IDA-3XA-006 global bool type no-change readback. | high | live item/type/value | IDA data `0x0066da97` type | already-present | current-IDA-readback-authoritative |
| C52 | 0000SW | IDA-3XA-007 removes concatenated regular data comment. | high | literal report-time comment | IDA data `0x0066da97` AR | incorporate | current-IDA-readback-authoritative |
| C53 | 0000SW | IDA-3XA-008 inserts exact repeatable data comment. | high | global/helper/writer evidence | IDA data `0x0066da97` AP | incorporate | current-IDA-readback-authoritative |
| C54 | 0003XA | IDA-3XA-009 protects two-byte predecessor padding. | high | live bytes/item | IDA data `[0x004b60ae,0x004b60b0)` | already-present | current-IDA-readback-authoritative |
| C55 | 0003XA | IDA-3XA-010 protects three-byte successor padding. | high | live bytes/item | IDA data `[0x004b60bd,0x004b60c0)` | already-present | current-IDA-readback-authoritative |
| C56 | 0002HR | IDA-3XA-011 protects predecessor method identity/range. | high | live function readback | IDA function `[0x004b6020,0x004b60ae)` | already-present | current-IDA-readback-authoritative |
| C57 | 0002HS | IDA-3XA-012 protects successor method identity/range. | high | live function readback | IDA function `[0x004b60c0,0x004b61d9)` | already-present | current-IDA-readback-authoritative |
| C58 | 00027F | IDA-3XA-013 protects left global neighbor. | high | live item/comments/bytes | IDA data `[0x0066da96,0x0066da97)` | already-present | current-IDA-readback-authoritative |
| C59 | 0001OI | IDA-3XA-014 protects right global neighbor. | high | live item/comments/bytes | IDA data `[0x0066da98,0x0066da9a)` | already-present | current-IDA-readback-authoritative |
| C60 | 0003XA | Callback validator must validate target serially with generated refresh disabled. | high | workflow | `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md` / Validator Results | incorporate | applied-command-000000020495 |
| C61 | 0000SW | Callback validator must validate global owner serially with generated refresh disabled. | high | workflow | `by-global/g_useEpfAssets.md` / Validator Results | incorporate | applied-command-000000020497 |
| C62 | 0001OH | Callback validator must validate storage child serially with generated refresh disabled. | high | workflow | `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md` / Validator Results | incorporate | applied-command-000000020498 |
| C63 | 0000O5 | Callback validator must validate StartupWindow file serially with generated refresh disabled. | high | workflow | `by-file/StartupWindow.md` / Validator Results | incorporate | applied-command-000000020501 |
| C64 | 00015A | Callback validator must validate mixed parent serially with generated refresh disabled. | high | workflow | `by-memory/0x004b5f00-0x004b6409.FontImageLib.md` / Validator Results | incorporate | applied-command-000000020502 |
| C65 | 0003XA | StartupWindow.cpp singular-definition truth must be established from fresh supervisor generated-output readback. | high | bounded command20493 CPP topology and proposed formals | `auto-generated/NexusTK/app/StartupWindow.cpp` / UID0000SW and UID0003XA readback | incorporate | current-supervisor-readback-authoritative |
| C66 | 0003XA | StartupWindow.h guard/global/helper topology truth must be established from fresh supervisor generated-output readback. | high | bounded command20493 H topology and proposed formals | `auto-generated/NexusTK/app/StartupWindow.h` / UID0000SW and UID0003XA readback | incorporate | current-supervisor-readback-authoritative |
| C67 | 0003XA | Direct report-coverage truth must be established from fresh validator-owned tracker state. | high | bounded command20493 `0/0/0` snapshot | `auto-generated/-ag-research-tracker.md` / UID0003XA row | incorporate | current-supervisor-readback-authoritative |
| C68 | 0003XA | By-memory manual-report truth must be established from fresh supervisor readback against atomic M01/M02 text and anchors. | high | exact M01/M02 payloads and anchors below | `by-memory/-coverage-report.md` / UID00015A children and UID0001OH | incorporate | current-supervisor-readback-authoritative |
| C69 | 0000SW | By-global manual-report truth must be established from fresh supervisor readback against atomic M03 text and anchor. | high | exact M03 payload and anchor below | `by-global/-coverage-report.md` / UID0000SW | incorporate | current-supervisor-readback-authoritative |
| C70 | 0000O5 | By-file manual-report truth must be established from fresh supervisor readback against atomic M04 text and anchor. | high | exact M04 payload and anchor below | `by-file/-coverage-report.md` / UID0000O5 | incorporate | current-supervisor-readback-authoritative |
| C71 | 0003XA | Report execution/archive state is authoritative only from the current path plus validator-owned status/history metadata. | high | lifecycle-neutral workflow | `tools/leaser/Agents/Agent-B004/research/0003XA-IsLegacyAssetMode-source-quality.md` plus validator-owned status/history metadata | not-applicable | lifecycle-truth-deferred-to-authoritative-state |

## Positive Evidence Summary

- Exact 13-byte one-block bool query with no incidental complexity.
- Exact one-byte bool storage, initial value 1, 366 live xrefs, and a known sole write assigning 1.
- Complete 33-call inventory with a closed 26/7 consumer split.
- TextEditPane and GrafPort docs independently use compatible `legacyAssetMode` and 0/1 `fontId` vocabulary.
- Current IDA already carries the accepted human name and exact bool declaration.
- Bounded command20493 generated CPP already emits one correct definition through UID0000SW.
- Owner/emitter and no-duplicate storage routes are established.
- Exact predecessor/successor and padding boundaries exclude split ambiguity.
- Manual coverage has a concrete missing child row and stale storage/file summaries, so closure is deterministic.

## IDA MCP Facts

- Session: `f608d7c2`; status ok; IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; imagebase `0x400000`; Hex-Rays and strings ready.
- Dated physical checkpoint: SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, 143,192,751 bytes, saved 2026-07-31T06:21:13.3464834-04:00.
- Target: `IsLegacyAssetMode`, `[0x004b60b0,0x004b60bd)`, size `0x0d`, `bool __cdecl()`.
- Assembly: `xor eax,eax; cmp g_useEpfAssets,1; setnz al; retn`.
- Frame: only `__return_address +0x0`, size `0x4`, type `_UNKNOWN *`; no arguments or decompiler locals.
- Comments: address regular absent; address repeatable absent; function regular exact `Source helper IsLegacyAssetMode(): returns !g_useEpfAssets.`; function repeatable absent.
- Bytes around target: `8b e5 5d c2 20 00 cc cc 33 c0 80 3d 97 da 66 00 01 0f 95 c0 c3 cc cc cc 55 8b ec 6a ff 68 a6 f0` at `0x004b60a8`.
- Global item: `[0x0066da97,0x0066da98)`, `g_useEpfAssets`, type `bool`, width 1, current value 1.
- Global local bytes at `0x0066da94`: `00 04 01 01 00 03 00 00`.
- Global regular comment is the exact four-line concatenation reproduced in the IDA table; repeatable comment absent.
- Exact target xrefs: 33 code calls; global xrefs: 366 data refs.
- Name query returns exactly one `IsLegacyAssetMode` at `0x004b60b0` and one `g_useEpfAssets` at `0x0066da97`; no collision exists.

## Function / Child Inventory

| Range | Entity | Source disposition |
| --- | --- | --- |
| `[0x004b6020,0x004b60ae)` | UID0002HR `FontImageLib__MeasureGlyphWidth` | protected predecessor; separate FontImageLib method |
| `[0x004b60ae,0x004b60b0)` | two bytes `cc cc` | protected alignment padding |
| `[0x004b60b0,0x004b60bd)` | UID0003XA `IsLegacyAssetMode` | sole target function; free external helper |
| `[0x004b60bd,0x004b60c0)` | three bytes `cc cc cc` | protected alignment padding |
| `[0x004b60c0,0x004b61d9)` | UID0002HS `FontImageLib__EnsureFontSlotLoaded` | protected successor; separate FontImageLib method |
| `[0x0066da96,0x0066da97)` | UID00027F `g_movementSubstepScale` | protected left data neighbor |
| `[0x0066da97,0x0066da98)` | UID0001OH / UID0000SW `g_useEpfAssets` | exact semantic dependency/storage |
| `[0x0066da98,0x0066da9a)` | UID0001OI `g_screenHeight` | protected right data neighbor |

No child split is required inside UID0003XA. The target is already exact. UID00015A remains the non-emitting mixed physical parent.

## Direct Xref / Caller Inventory

| Callsite(s) | Enclosing body / exact documentation | Count | Result use |
| --- | --- | ---: | --- |
| `0x475ac9`, `0x4761f9` | `sub_4753E0`; UID00030J ArticleDialogCore | 2 | TextEditPane `legacyAssetMode` |
| `0x47ba65`, `0x47c2e8` | `sub_47B220`; UID0000ZO MailDialogs | 2 | TextEditPane `legacyAssetMode` |
| `0x4840cc` | `sub_484030`; UID00010A ClanStatusPaneConstructor | 1 | TextEditPane `legacyAssetMode` |
| `0x4885b4` | raw UID00021T ClanInfoListPaneRawConstructor | 1 | TextEditPane `legacyAssetMode` |
| `0x498a48` | `TextEditControlPane_TextEditControlPane_full`; UID00011H | 1 | TextEditPane `legacyAssetMode` |
| `0x4990f9` | `sub_499030`; UID00011I StaticTextControlPaneConstructor | 1 | TextEditPane `legacyAssetMode` |
| `0x4994be` | `sub_499430`; UID00011K TargetOptionEditControlPane | 1 | `GrafPort::SetFontId` |
| `0x4a017c` | `AlertPane__AlertPane`; UID00012W | 1 | TextEditPane `legacyAssetMode` |
| `0x4f1d46`, `0x4f1f06` | `LineInputPane__Constructor`; UID00035P | 2 | TextEditPane `legacyAssetMode` in two geometry branches |
| `0x4ff15c` | `ScrolledTextControlPane__ScrolledTextControlPane`; UID0004WP | 1 | TextEditPane `legacyAssetMode` |
| `0x4ff51c` | `ScrolledTextControlPaneForMadeBy...`; UID0004MA | 1 | TextEditPane `legacyAssetMode` |
| `0x541ea0` | `sub_541E50`; UID0001E1 IntegrateMacroDialog | 1 | `GrafPort::SetFontId` |
| `0x56bab4` | raw UID0001H8 GroupListPaneRawConstructor | 1 | TextEditPane `legacyAssetMode` |
| `0x56bb4a` | `SpelledPane__Constructor`; UID0004YO | 1 | TextEditPane `legacyAssetMode` |
| `0x56bbf4` | `SpelledPane__ConstructorWithDimensions`; UID0004YP | 1 | TextEditPane `legacyAssetMode` |
| `0x56c42a` | `LegendPane_LegendPane`; UID0001HB | 1 | TextEditPane `legacyAssetMode` |
| `0x56c536` | `sub_56C4C0`; UID0001HC GroupPanes | 1 | TextEditPane `legacyAssetMode` |
| `0x56c7e6` | `sub_56C770`; UID0001HC GroupPanes | 1 | TextEditPane `legacyAssetMode` |
| `0x57f832`, `0x57f8da` | `sub_57F7D0`; UID0001IK MacroEditControlPanes | 2 | `GrafPort::SetFontId` |
| `0x57fb2a` | `sub_57FAA0`; UID0001IK | 1 | `GrafPort::SetFontId` |
| `0x57fdcc` | `sub_57FD10`; UID0004AG IntegrateMacroEditControlPaneConstructor | 1 | TextEditPane `legacyAssetMode` |
| `0x58000c` | `sub_57FFB0`; UID0001IK | 1 | `GrafPort::SetFontId` |
| `0x58eedc` | `sub_58EE90`; UID0001JM TextEditPaneCoreBeforeTextBoxPane | 1 | TextEditPane `legacyAssetMode` |
| `0x5953c4` | `sub_595390`; UID0002RV TextBoxPaneConstructor | 1 | TextEditPane `legacyAssetMode` |
| `0x59dfdb` | `sub_59DF50`; UID0001KJ CheckBoxTextControlPaneExecutableMap | 1 | `GrafPort::SetFontId` |
| `0x59f310`, `0x59f3a6` | `UserLookPane_UserLookPane`; UID0003RI | 2 | TextEditPane `legacyAssetMode` for two children |
| `0x5a22f4` | raw UID0003RX MoreInfoPaneRawConstructor | 1 | TextEditPane `legacyAssetMode` |
| `0x5a2374` | raw UID0003S0 ProfilePaneRawConstructor | 1 | TextEditPane `legacyAssetMode` |

Totals: 33 calls; 26 TextEditPane-constructor uses; 7 `GrafPort::SetFontId` uses; 24 modeled caller functions plus four raw constructor bodies; no unclassified callsite remains.

## Documentation Evidence And IDA Status

- Target docs and IDA agree on range, name, bool body, owner global, call total, and padding.
- Historical pre-callback documentation state: caller semantics were not fully enumerated, history still said formal CPP blank, and the command20493 generated-H absence was not acknowledged. The dated callback evidence and post-validation identities under `Validator Results` and `Changed Files` supersede that ordinary-document state.
- UID0000SW and UID0001OH contain the exact 366-ref/sole-writer evidence needed to keep type/name/owner stable.
- TextEditPane class/file docs already define argument ten as `legacyAssetMode`; no callback change is justified there.
- GrafPort accessor/class docs already define `SetFontId(unsigned short)` and `m_fontId+0x8a`; no callback change is justified there.
- FontImageLib file/class docs already exclude UID0003XA from class ownership; only the mixed parent needs the richer child record.
- IDA name/type are already correct. Comment channels need deterministic cleanup: remove terse function regular and concatenated global regular comments; install exact repeatable comments.
- No IDA mutation has been made by B004.

## Ranked Ownership Analysis

| Rank | Candidate | Disposition |
| ---: | --- | --- |
| 1 | UID0000SW `g_useEpfAssets` | retain canonical owner/emitter; sole direct semantic state |
| 2 | UID0000O5 StartupWindow | retain current source route only; owns sole observed write and current definition route |
| 3 | UID0000JH FontImageLib | physical-neighbor/source-file counter-hypothesis only; reject semantic ownership |
| 4 | UID00005V/UID0000JR GrafPort | consumer of seven results; reject ownership |
| 5 | UID0000EO/UID0000ON TextEditPane | consumer of 26 results; reject ownership |
| 6 | each feature caller | callsite-only relationship; reject fragmented owner copies |
| 7 | no owner / compiler-only | rejected; exact source helper body and external calls are source-authored |

## Source Placement

Current reconstruction placement is `NexusTK/app/StartupWindow.cpp` with declaration in generated `NexusTK/app/StartupWindow.h`, routed through UID0000SW and UID0000O5. This is the least-invented current source topology because the global definition already emits there and the sole known write is the StartupWindow constructor.

The report does not claim the historical developers necessarily placed the helper in a file literally named `StartupWindow.cpp`. Physical adjacency to FontImageLib is retained, but moving the helper to `FontImageLib.cpp` would sever its semantic owner route and make a state-free global policy query look font-library-owned. A new `AssetMode.cpp/.h` would be cleaner but unsupported. Therefore retain the current route and document the inference.

## Range / Split / Padding / Reclassification Analysis

- Target begins exactly at modeled function head `0x004b60b0` and ends at `0x004b60bd` after `retn`.
- Two `0xcc` bytes at `[0x004b60ae,0x004b60b0)` are predecessor alignment, not target prologue.
- Three `0xcc` bytes at `[0x004b60bd,0x004b60c0)` are successor alignment, not target tail.
- Predecessor UID0002HR ends exactly at `0x004b60ae`; successor UID0002HS begins exactly at `0x004b60c0`.
- UID0003XA needs no split, merge, range rename, padding child, additional target UID, or reconstructable reclassification.
- UID00015A remains mixed/non-emitting because it includes both FontImageLib children and this independent global helper.

## Negative Evidence Summary

- No PDB, source string, RTTI, import, export, or debug symbol proves original `IsLegacyAssetMode` spelling.
- No evidence supports retaining `sub_4B60B0`, `byte_66DA97`, `_DWORD`, or address-suffixed names in final source.
- No callsite uses an arbitrary font id; all use the exact 0/1 bool result.
- No helper instruction reads FontImageLib, GrafPort, TextEditPane, StartupWindow object fields, or any second global.
- No FontImageLib method calls UID0003XA.
- No evidence supports class membership, `thiscall`, parameters, local state, static per-file linkage, or compiler-only classification.
- No evidence supports duplicate storage or a second `g_useEpfAssets` definition.
- No evidence supports changing TextEditPane/GrafPort accepted names during this target pass.
- At the historical command20493 checkpoint, generated-H declaration absence rejected a claim of CPP/H closure. Current generated topology requires fresh supervisor readback of validator-owned output.
- Exact source filename remains inferred, but that is not justification to leave code un-emitted or reverse-engineering-shaped.

## IDA Rename / Type / Comment Recommendations

The eight action rows are supervisor-owned Gate 2B handoffs. `AR/AP/FR/FP` mean address regular/address repeatable/function regular/function repeatable. `absent` is literal. Each action row independently repeats the historical report-time physical prestate, recommended action, constraints, and expected readback. Six protected dependency rows follow separately. Current IDA state and action disposition are authoritative only from fresh supervisor readback and saved-IDB evidence; this report does not assert whether any row has since been applied.

### Gate 2B action rows

| ID | Exact entity and historical report-time literal prestate | Classification and exact action | Safety constraints and deterministic expected readback |
| --- | --- | --- | --- |
| IDA-3XA-001 | Function `[0x004b60b0,0x004b60bd)`, size `0x0d`; current name `IsLegacyAssetMode`; declaration `bool __cdecl()`; frame `__return_address +0x0/0x4/_UNKNOWN *`, no args/locals; AR absent; AP absent; FR `Source helper IsLegacyAssetMode(): returns !g_useEpfAssets.`; FP absent; bytes `33 c0 80 3d 97 da 66 00 01 0f 95 c0 c3`; exactly 33 code xrefs; name query has no competing collision. | `already present`: preserve exact name; no mutation. | Preserve range/bytes/xrefs/frame/type/comments. Readback must repeat name `IsLegacyAssetMode`, declaration and all four comment channels exactly as prestate at this step. |
| IDA-3XA-002 | Function `[0x004b60b0,0x004b60bd)`, size `0x0d`; current name `IsLegacyAssetMode`; declaration `bool __cdecl()`; frame `__return_address +0x0/0x4/_UNKNOWN *`, no arguments and no decompiler locals; AR absent; AP absent; FR exact `Source helper IsLegacyAssetMode(): returns !g_useEpfAssets.`; FP absent; bytes `33 c0 80 3d 97 da 66 00 01 0f 95 c0 c3`; exactly 33 code xrefs; entity query returns one exact name and no collision. | `already present`: preserve exact function declaration/type; no mutation. | Do not add arguments, class receiver, or widened return. Expected readback repeats range/name/declaration/frame/bytes/33 xrefs and AR absent/AP absent/FR exact current literal/FP absent. |
| IDA-3XA-003 | Function `[0x004b60b0,0x004b60bd)`, size `0x0d`; current name `IsLegacyAssetMode`; declaration `bool __cdecl()`; frame `__return_address +0x0/0x4/_UNKNOWN *`, no arguments and no decompiler locals; AR absent; AP absent; FR exact `Source helper IsLegacyAssetMode(): returns !g_useEpfAssets.`; FP absent; bytes `33 c0 80 3d 97 da 66 00 01 0f 95 c0 c3`; exactly 33 code xrefs; entity query returns one exact name and no collision. | `apply`: remove the function regular comment, setting FR to absent. | No other channel or entity changes. Expected readback repeats range/name/declaration/frame/bytes/33 xrefs with AR absent, AP absent, FR absent, and FP absent. |
| IDA-3XA-004 | Function `[0x004b60b0,0x004b60bd)`, size `0x0d`; current name `IsLegacyAssetMode`; declaration `bool __cdecl()`; frame `__return_address +0x0/0x4/_UNKNOWN *`, no arguments and no decompiler locals; AR absent; AP absent; FR exact `Source helper IsLegacyAssetMode(): returns !g_useEpfAssets.`; FP absent; bytes `33 c0 80 3d 97 da 66 00 01 0f 95 c0 c3`; exactly 33 code xrefs; entity query returns one exact name and no collision. | `apply`: set FP exactly to `Global legacy-asset mode query. Returns !g_useEpfAssets; 26 callsites pass the result as TextEditPane legacyAssetMode and 7 pass it to GrafPort::SetFontId.` | Apply after IDA-3XA-003. Expected readback repeats range/name/declaration/frame/bytes/33 xrefs with AR absent, AP absent, FR absent, and FP equal to the exact literal in this row. |
| IDA-3XA-005 | Data item `[0x0066da97,0x0066da98)`, size 1; current name `g_useEpfAssets`; type `bool`; value 1; AR exact four lines: `Global EPF/current-asset mode selector g_useEpfAssets.` / `EPF asset-mode flag. LivingObjectPane unregister clears DamageNumber attachment type 8 only while this mode is true.` / `EPF asset-mode flag selecting the alternate category-label update path.` / `Process-wide bool g_useEpfAssets; MapPane is a consumer and does not own this definition.`; AP absent; FR/FP not applicable and absent; 366 data xrefs; no name collision. | `already present`: preserve exact name; no mutation. | Preserve one-byte boundary, bool type, value, xrefs, comments, and adjacent items. Expected readback name `g_useEpfAssets`. |
| IDA-3XA-006 | Data item `[0x0066da97,0x0066da98)`, size 1; current name `g_useEpfAssets`; current type `bool`; value 1; AR exact four lines: `Global EPF/current-asset mode selector g_useEpfAssets.` / `EPF asset-mode flag. LivingObjectPane unregister clears DamageNumber attachment type 8 only while this mode is true.` / `EPF asset-mode flag selecting the alternate category-label update path.` / `Process-wide bool g_useEpfAssets; MapPane is a consumer and does not own this definition.`; AP absent; FR/FP not applicable and absent; exactly 366 data xrefs; entity query returns one exact name and no collision. | `already present`: preserve exact one-byte `bool`; no mutation. | Do not widen, merge, enum-type, or convert to `char`. Expected readback repeats range/name/type/value/366 xrefs and all four current comment channels exactly. |
| IDA-3XA-007 | Data item `[0x0066da97,0x0066da98)`, size 1; current name `g_useEpfAssets`; current type `bool`; value 1; AR exact four lines: `Global EPF/current-asset mode selector g_useEpfAssets.` / `EPF asset-mode flag. LivingObjectPane unregister clears DamageNumber attachment type 8 only while this mode is true.` / `EPF asset-mode flag selecting the alternate category-label update path.` / `Process-wide bool g_useEpfAssets; MapPane is a consumer and does not own this definition.`; AP absent; FR/FP not applicable and absent; exactly 366 data xrefs; entity query returns one exact name and no collision. | `apply`: remove the concatenated address regular comment, setting AR to absent. | Preserve item/name/type/value/range/xrefs. Expected readback has AR absent, AP absent, and FR/FP not applicable and absent. |
| IDA-3XA-008 | Data item `[0x0066da97,0x0066da98)`, size 1; current name `g_useEpfAssets`; current type `bool`; value 1; AR exact four lines: `Global EPF/current-asset mode selector g_useEpfAssets.` / `EPF asset-mode flag. LivingObjectPane unregister clears DamageNumber attachment type 8 only while this mode is true.` / `EPF asset-mode flag selecting the alternate category-label update path.` / `Process-wide bool g_useEpfAssets; MapPane is a consumer and does not own this definition.`; AP absent; FR/FP not applicable and absent; exactly 366 data xrefs; entity query returns one exact name and no collision. | `apply`: set AP exactly to `Process-wide EPF/current-asset selector initialized true; the sole observed write is StartupWindow::StartupWindow assigning true. IsLegacyAssetMode returns its inverse. While true, LivingObjectPane unregister clears DamageNumber attachment type 8; the flag also selects the alternate category-label update path. MapPane is a consumer, not the definition owner.` | Apply after IDA-3XA-007. Expected readback repeats range/name/type/value/366 xrefs with AR absent, AP equal to the exact literal in this row, and FR/FP not applicable and absent. |

### Protected dependency readback rows - no IDA mutation

| ID | Exact entity and historical report-time literal prestate | Classification and exact action | Safety constraints and deterministic expected readback |
| --- | --- | --- | --- |
| IDA-3XA-009 | Padding item `[0x004b60ae,0x004b60b0)`, size 2, bytes `cc cc`; name absent; type absent; AR absent; AP absent; FR/FP not applicable and absent; exact incoming xref total 0; no named entity or collision. | `no change recommended`: protect predecessor padding. | Do not create a function, merge with predecessor/target, name, type, or comment. Expected readback remains one two-byte data item with exact bytes, zero incoming xrefs, and absent channels. |
| IDA-3XA-010 | Padding item `[0x004b60bd,0x004b60c0)`, size 3, bytes `cc cc cc`; name absent; type absent; AR absent; AP absent; FR/FP not applicable and absent; exact incoming xref total 0; no named entity or collision. | `no change recommended`: protect successor padding. | Do not create a function, merge with target/successor, name, type, or comment. Expected readback remains one three-byte data item with exact bytes, zero incoming xrefs, and absent channels. |
| IDA-3XA-011 | Function `[0x004b6020,0x004b60ae)`, size `0x8e`; name `FontImageLib__MeasureGlyphWidth`; declaration `void __thiscall(FontImageLib *this, int fontId, unsigned __int16 glyphId, unsigned __int16 nextGlyphId, bool clearBeforeDecode, const unsigned __int8 *paletteMap, RectBounds *outBounds, __int16 *outAdvance, EPFTileContext *outContext)`; AR absent; AP absent; FR exact `FontImageLib::MeasureGlyphWidth source method using FontGlyphRecord metrics and optional bitmap decode output.`; FP absent; exactly nine code refs; entity query returns one exact name and no collision. | `no change recommended`: protect predecessor function identity/range. | Do not extend it through padding or absorb UID0003XA. Expected readback repeats exact range/name/declaration/comments, nine refs, and unique-name state. |
| IDA-3XA-012 | Function `[0x004b60c0,0x004b61d9)`, size `0x119`; name `FontImageLib__EnsureFontSlotLoaded`; declaration `FontSlotStorage *__thiscall(FontImageLib *this, int fontId)`; AR absent; AP absent; FR exact `FontImageLib::EnsureFontSlotLoaded. Loads BARAM%02d.EFT into one of two exact FontSlotStorage records and builds the 0x10000-entry glyph pointer table.`; FP absent; exactly two code refs; entity query returns one exact name and no collision. | `no change recommended`: protect successor function identity/range. | Do not move start into padding or absorb UID0003XA. Expected readback repeats exact range/name/declaration/comments, two refs, and unique-name state. |
| IDA-3XA-013 | Data item `[0x0066da96,0x0066da97)`, size 1; name `g_movementSubstepScale`; type `char`; value/byte 1; AR exact `MapPane.cpp file-static plain char g_movementSubstepScale, initialized to 1; all observed readers sign-extend it.`; AP absent; FR/FP not applicable and absent; exactly 23 data xrefs; entity query returns one exact name and no collision. | `no change recommended`: protect left neighbor. | Do not merge with g_useEpfAssets or change its signed char type/comment. Expected readback repeats exact item/name/type/value/AR, 23 xrefs, unique-name state, and one-byte boundary. |
| IDA-3XA-014 | Data item `[0x0066da98,0x0066da9a)`, size 2; name `g_screenHeight`; type `unsigned __int16`; value/bytes `0x0300` / `00 03`; AR absent; AP absent; FR/FP not applicable and absent; exactly 96 data xrefs; entity query returns one exact name and no collision. | `no change recommended`: protect right neighbor. | Do not merge with g_useEpfAssets or change width/type. Expected readback repeats exact item/name/type/value/bytes, 96 xrefs, unique-name state, and absent channels. |

## First-Draft C++ Recommendation

### UID0003XA target CPP

```cpp
bool IsLegacyAssetMode()
{
    return !g_useEpfAssets;
}
```

### UID0003XA target H

```cpp
bool IsLegacyAssetMode();
```

### UID0000SW resulting owner CPP

```cpp
bool g_useEpfAssets = true;
[[CHILDREN]]
```

### UID0000SW complete resulting owner H

```cpp
#ifndef NEXUSTK_APP_STARTUPWINDOW_H
#define NEXUSTK_APP_STARTUPWINDOW_H

extern bool g_useEpfAssets;

[[CHILDREN]]

#endif
```

### UID0001OH storage CPP and H disposition

Retain exact CPP marker text:

```cpp
// Exact storage for g_useEpfAssets at 0x0066da97.
// The source declaration is emitted by [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) g_useEpfAssets;
// do not duplicate the global definition from this one-byte storage child.
```

Retain UID0001OH H blank. Retain UID00015A CPP and H blank. No formal change is proposed for TextEditPane, GrafPort, or FontImageLib.

## Final Recommendation

Historical Gate 1/callback recommendation that governed the `2026-08-01` ordinary work: apply the five ordinary-document destinations C01-C27 at full detail, verify C28-C34 as no-change support, supply UID0000SW's complete guarded H channel, retain the target's concise CPP body, and raise only the target to `92/93`. The dated implementation/readback evidence is preserved under `Validator Results` and `Changed Files`.

The report assigns IDA-3XA-001..008 and protected dependency rows IDA-3XA-009..014 to supervisor Gate 2B, and assigns M01-M04, manual-report validation, generated-output/tracker readback, and report lifecycle exclusively to the supervisor. Their current disposition is not asserted here; fresh supervisor evidence and authoritative validator/project artifacts control it.

## Recommended Target Doc Changes

For UID0003XA:

- Change metadata `86/90 -> 92/93`; retain owner/emitter/reconstructable.
- Preserve exact CPP and H formal blocks shown above.
- Expand item summary/status with exact 26/7 caller split and external-linkage proof.
- Add complete caller table, body/codegen explanation, IDA current state, source placement ranking, header-emission defect, generated/tracker evidence, and rejected alternatives.
- Historicalize the old blank-formal statement.
- Record callback validators, generated closure, manual coverage, and applied IDA state only after physical completion.

## Recommended Support Doc Changes

### UID0000SW `by-global/g_useEpfAssets.md`

- Preserve every 366-xref/365-read/one-write/boundary/alias/source-owner fact.
- Add UID0003XA's exact body, 33 calls, 26/7 split, and no-duplicate relationship.
- Replace only the H managed value with the complete guarded payload above.
- Retain CPP, metadata, and current owner/file route.

### UID0001OH storage

- Add current IDA item/name/type/value/comment/boundary evidence and UID0003XA dependency.
- Retain exact no-duplicate CPP, blank H, and `88/90` metadata.

### UID0000O5 StartupWindow file

- Add the global definition, free helper definition, shared declaration, generated H child-expansion requirement, and explicit original-file inference caveat.
- Retain `89/88` and unrelated StartupWindow detail.

### UID00015A mixed parent

- Add UID0003XA's complete external-helper/caller/owner/formal split in the child inventory.
- Retain mixed non-emitting metadata and blank formals.

### Inspected and retained

- UID0000EO and UID0000ON already carry `legacyAssetMode` and `IsLegacyAssetMode()` evidence.
- UID000162, UID00005V, and UID0000JR already carry `SetFontId`, `m_fontId+0x8a`, and class/file ownership.
- UID0000JH and UID00005B already exclude UID0003XA from FontImageLib ownership.

## Score And Metadata Recommendation

| UID | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| 0003XA | 86/90 | 92/93 | complete body/range/type/33 callers/26-7 semantics/linkage/formals/owner/manual/IDA closure; exact original spelling/file remain inferred |
| 0000SW | 88/90 | retain | report resolves helper and H topology, not all 366 global consumers/original declaration file |
| 0001OH | 88/90 | retain | storage is exact; lexical/global placement inference remains broader |
| 0000O5 | 89/88 | retain | helper route improves detail but broader file caveats remain |
| 00015A | 90/94 | retain | mixed index already exact/non-emitting |
| 0000EO/0000ON | 93/94 and 93/93 | retain | no target-specific defect remains |
| 000162/00005V/0000JR | 89/91, 88/90, 89/88 | retain | no target-specific defect remains |
| 0000JH/00005B | 94/94 | retain | no target-specific defect remains |

Reason not higher than `92/93`: no original symbol proves `IsLegacyAssetMode`; no source artifact proves `StartupWindow.cpp/.h`; physical FontImageLib adjacency remains contrary placement evidence; this report does not reclassify every one of 366 direct global refs.

Reason not lower: behavior/type/range/ABI are exact; every one of 33 callers is classified; both consumer contracts independently agree; owner/emitter and formal source are implementable; generated-H and manual-coverage gaps have deterministic repairs; no functional or source-shape blocker remains.

Score-improvement work was blocker-driven rather than a score-only adjustment:

| Prior blocker | Concrete research | Resolution / residual cap |
| --- | --- | --- |
| Semantic role of all 33 calls | Complete bounded xref inventory plus caller-family docs/decompilation | Closed as 26 TextEditPane legacy-mode and seven GrafPort font-id consumers |
| Bool versus arbitrary integer return | Exact `setnz`, `bool` declaration/storage, consumer domains, and writer pass | Closed as bool query whose 0/1 result is accepted by the font-id setter |
| Human source name | Caller semantics, accepted global/member vocabulary, and collision search | `IsLegacyAssetMode` accepted; absent original symbol remains a confidence-only cap |
| `!value` versus `value != 1` source shape | Storage type, legal bool domain, sole observed write, decompiler, and codegen | `return !g_useEpfAssets;` accepted; machine compare retained as evidence only |
| Linkage | Single body, 33 external calls, and reconstructed source-family spread | Closed as one external definition plus shared declaration |
| Owner/emitter | Sole dependency, storage/by-global hierarchy, write site, and consumer rejection | UID0000SW retained; no-owner/class-owner alternatives rejected |
| Source file placement | Existing route, sole StartupWindow writer, physical FontImageLib adjacency, and absent utility file | UID0000O5 retained as best current inference; original filename remains a confidence cap |
| CPP/H completeness | Physical target/owner formals and command20493 CPP/H topology | CPP already exact; complete guarded owner H with `[[CHILDREN]]` supplied |
| Range/split/padding | Function/item bounds, bytes, predecessor/successor, xrefs, and neighbor items | Closed as exact unsplit 13-byte function with protected fences |
| Manual/generated/report coverage | Current manual rows, command20493 memory/generated/tracker output | Deterministic M01-M04 operations and generated/tracker closure supplied |

## Open Questions With Attempted Resolution

1. **Original helper name?** No symbol survives. Exhaustive caller semantics and project vocabulary support `IsLegacyAssetMode`; raw/narrow alternatives are rejected. Closed for reconstruction, retained as lexical confidence cap.
2. **Return `bool` or font id?** IDA type, `setnz`, no-argument query shape, and TextEditPane `legacyAssetMode` support `bool`; GrafPort's unsigned-short consumer is an implicit 0/1 use. Closed.
3. **`!g_useEpfAssets` or `!=1` source?** Bool typing and observed bool writes make logical negation the plausible authored form; machine comparison remains documented. Closed.
4. **Static, inline, or external?** Single out-of-line body plus cross-family direct calls requires external definition/declaration. Closed.
5. **StartupWindow or FontImageLib source?** No source artifact proves either. Semantic owner/sole writer/current source route favor StartupWindow; adjacency is retained as cap. Closed for current reconstruction without inventing a new file.
6. **Owner global or consumer classes?** Body reads only global and callers are consumers. UID0000SW remains owner. Closed.
7. **Why generated H is missing?** Parent H lacks `[[CHILDREN]]`; exact guarded replacement supplied. Closed.
8. **Need a target split or added UID?** Exact one-function range and padding prove no. Closed.
9. **Can target exceed current score?** Yes. Every prior blocker now has evidence or an implementation-ready repair. Closed.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current manual files were read only. Hashes are dated report-time checkpoints and must be reread before supervisor application.

### M01 - by-memory insertion for UID0003XA

Current `by-memory/-coverage-report.md` checkpoint: SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`, 2,134,111 bytes, 4,803 lines. Under UID00015A, insert after UID0002HR and before UID0002HS:

```markdown
        - [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md) 0x004b60b0-0x004b60bd | external source helper | IsLegacyAssetMode : reconstructable : 92% : very-strong : Exact 13-byte bool query returning `!g_useEpfAssets`, with one basic block, no arguments/locals/callees/strings/constants, 33 exact calls split into 26 TextEditPane `legacyAssetMode` uses and seven `GrafPort::SetFontId` uses, external definition/declaration through UID0000SW, exact two-/three-byte padding fences, retained FontImageLib separation, and complete formal CPP/H source topology.
```

### M02 - by-memory replacement for UID0001OH

Replace only current UID0001OH row between UID00027F and UID0001OI:

```markdown
    - [UID:0001OH][0x0066da97-0x0066da98.g_useEpfAssets](by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md) 0x0066da97-0x0066da98 | global-data byte | g_useEpfAssets : reconstructable : 88% : strong : Exact one-byte bool storage initialized to 1, with 366 data xrefs across broad startup/UI/resource/input/weather users, 365 reads and sole observed StartupWindow constructor write of 1, strict `g_movementSubstepScale`/`g_screenHeight` boundaries, direct by-global owner [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), and exact [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md) inverse-query dependency; source definition/declaration emit through current [UID:0000O5][StartupWindow](by-file/StartupWindow.md) route while this storage child remains nonduplicating.
```

### M03 - by-global replacement for UID0000SW

Current `by-global/-coverage-report.md` checkpoint: SHA256 `D54B0FBFC043E7822860CB9828896C898BA65EC66B32854CE7F9D191FA066CA1`, 100,876 bytes, 218 lines. Replace only UID0000SW between UID0002ZQ and UID0000SX:

```markdown
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) : reconstructable : 88% : strong : Broad EPF/current-layout selector bool with exact one-byte storage at `0x0066da97`, initial 1, 366 xrefs across startup/UI/resource/input/weather users, strict neighboring-global boundaries, alias normalization, and exact memory child [UID:0001OH][0x0066da97-0x0066da98.g_useEpfAssets](by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md). Prior exhaustive IDA evidence records 365 reads, one write at `0x005807f3` in `StartupWindow__Constructor`, zero unknown operand refs, and zero direct refs in documented Application/Config/WinMain ranges. UID0003ZT remains an exact MapPane read consumer and does not own the definition. Exact child [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md) returns the inverse and has 33 calls split into 26 TextEditPane legacy-mode uses and seven GrafPort font-id uses. The by-global page remains the sole definition/semantic owner, routes through [UID:0000O5][StartupWindow](by-file/StartupWindow.md) as the best existing source-owner inference, and supplies one guarded direct source-root H channel with `extern bool g_useEpfAssets;` plus child declaration expansion; exact original spelling/file remain inferred.
```

### M04 - by-file replacement for UID0000O5

Current `by-file/-coverage-report.md` checkpoint: SHA256 `2AC15CEC42D5D2532EB360C67C7145B32738FDE1876BF56BC4F638DBB3761B66`, 166,582 bytes, 319 lines. Replace only UID0000O5 between UID0000O4 and UID0000O6:

```markdown
- [UID:0000O5][StartupWindow](by-file/StartupWindow.md) : reconstructable : 89% : strong : Startup update-notice translation unit with exact method/helper split, Win32/browser/curl/minimap behavior, UID000288 notice literals, source-local StartupWindow forward-declaration placement, and sole semantic definitions for g_startupWindowClassAtom/g_pStartupWindow. It is also the current one-definition route for [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) and external inverse query [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md), with guarded H declarations emitted through the global owner; the exact historical file placement remains inferred from the sole StartupWindow writer and existing source route. UID0002AM and its physical children remain non-emitting layout evidence, so generated source contains no duplicate storage or aggregate markers.
```

### No-op manual dispositions

- N01 UID00015A parent row already names separate UID0003XA and retains all mixed-island facts; only M01 child insertion is required.
- N02 UID0000JH by-file row already preserves mixed UID00015A/UID0003XA separation and one-definition topology; no replacement.
- N03/N04 bounded `by-class/-coverage-report.md` checkpoint: SHA256 `0A2F8F0BF6EF28ECB9633E504A0C2B59BCBF022B31201B33A1AAAB319B15D272`, 275,060 bytes/625 lines.
- N03 UID0000EO row 552 already preserves complete TextEditPane declaration/constructor union; no replacement.
- N04 UID00005V row 236 already preserves accepted GrafPort field/accessor topology; no replacement.

Tracker text is validator-owned and must not be edited manually. Current direct report coverage is authoritative only from fresh tracker readback together with the report's current path and validator-owned status/history metadata.

## Follow-Up Actions

1. Exact-artifact Gate 1 and Gate 2 dispositions are supervisor-owned and must be established from a fresh audit of the current report artifact.
2. Historical callback record (`2026-08-01`): B004 applied C01-C27 to the five ordinary destinations and verified C28-C34 as no change.
3. Historical validator record (`2026-08-01`): B004 ran the five serial scoped ordinary validators with `--no-generated-refresh`; exact command evidence is retained below.
4. Ordinary/formal verification truth is authoritative only from fresh supervisor Gate 2A readback against the current destination files.
5. IDA-3XA-001..014 truth is authoritative only from fresh supervisor Gate 2B readback, mutation records where applicable, and saved-IDB evidence.
6. Any later saved-IDA prose reconciliation requires an explicit same-report callback and fresh physical evidence.
7. M01-M04/N01-N04, manual coverage, generated output, and tracker topology are supervisor-owned; their current truth must be read from the authoritative artifacts rather than inferred from this report.
8. Report execution/archive truth is authoritative only from the current path plus validator-owned status/history metadata.

A-agent actions: none; this report does not recommend an A-agent source-structure assignment. No additional B004 research recommendation is made within UID0003XA; later original-symbol/source-artifact discovery would be a separate naming/placement revalidation trigger.

## Confidence

- Behavior/range/ABI/type: very high.
- Caller classification and 26/7 split: very high.
- Global owner/emitter: high.
- Human helper name: high inference, not recovered symbol.
- Current StartupWindow source route: medium-high inference.
- Formal CPP behavior: very high.
- Formal H topology repair: high.
- Recommended target score: `92/93`.

## Validator Results

Historical callback command record (`2026-08-01`): exactly the five authorized scoped validators below ran serially from `source-3/project-documentation`, each with `--apply --queue-timeout 240 --no-generated-refresh`. Their recorded diagnostics explicitly said generated refresh was skipped. This command history does not assert current generated or report-lifecycle state.

> Executable block R001 was removed from this report and preserved verbatim in [0003XA-IsLegacyAssetMode-source-quality-removed.md](0003XA-IsLegacyAssetMode-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- UID0003XA target: command `000000020495`, `2026-08-01T03:25:27-04:00`, exit `0`, `ok: 1`. Diagnostics recorded completion update `92`, confidence update `93`, normalized UID0002HR/UID0002HS links, projected-stat updates, and generated refresh skipped. Post-validation identity is SHA256 `80EAA64D25F955A306A28CE852C6C3BAF855C5A0DBF5D8E1EBBDFB3F479B9C3D`, 14,522 bytes, 149 lines.
- UID0000SW global owner: command `000000020497`, `2026-08-01T03:26:27-04:00`, exit `0`, `ok: 1`. Diagnostics recorded validator registry/reference/stat updates including UID0003XA, projected-stat updates, and generated refresh skipped. Post-validation identity is SHA256 `09DE791E1AC135DFFA10AE95EAE81814978C018EF606975CA85FE9AD5EEE06C3`, 24,532 bytes, 182 lines.
- UID0001OH storage child: command `000000020498`, `2026-08-01T03:27:31-04:00`, exit `0`, `ok: 1`. Diagnostics recorded UID0003XA reference and projected-stat updates, with generated refresh skipped. Post-validation identity is SHA256 `35AA50F4910E6B294527BA6D2F31F3205418452FBE940BFAC1B8F1DB8575D23E`, 16,852 bytes, 132 lines.
- UID0000O5 StartupWindow file: command `000000020501`, `2026-08-01T03:29:30-04:00`, exit `0`, `ok: 1`. Diagnostics recorded UID0003XA reference and projected-stat updates, with generated refresh skipped. Post-validation identity is SHA256 `0B3C85DE029B8DA01A0DAE0237F7F324FDB3D4C3346DBA8DCBAF9E18FA5040D4`, 62,930 bytes, 305 lines.
- UID00015A mixed parent: command `000000020502`, `2026-08-01T03:30:42-04:00`, exit `0`, `ok: 1`. Diagnostics recorded UID0000O5/UID0003XA references and projected-stat updates, with generated refresh skipped. Post-validation identity is SHA256 `DC51CE1F03E419558023325A1BC64C3A01AC409F3B42A1A463C1E8299C523250`, 19,883 bytes, 157 lines.

Historical callback verification record (`2026-08-01`): each destination was reopened after validation and compared against C01-C34 and the exact formal payloads; validator success was not used as a substitute for content verification. Current generated/manual/IDA/audit/lifecycle dispositions are not asserted here. Report execution/archive truth is authoritative only from the report's current path plus validator-owned status/history metadata, and other current states require fresh supervisor readback of their authoritative artifacts.

## Changed Files

- `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`: applied C01-C14, raised only UID0003XA to `92/93`, retained owner/emitter/reconstructability and exact CPP/H, and preserved historical material as explicitly superseded history. Post-validation SHA256 `80EAA64D25F955A306A28CE852C6C3BAF855C5A0DBF5D8E1EBBDFB3F479B9C3D`, 14,522 bytes, 149 lines.
- `by-global/g_useEpfAssets.md`: applied C15-C19 without pruning the 366-xref/365-read/one-write evidence, retained its singular CPP definition/child route, and replaced only H with the complete guarded extern/child payload. Post-validation SHA256 `09DE791E1AC135DFFA10AE95EAE81814978C018EF606975CA85FE9AD5EEE06C3`, 24,532 bytes, 182 lines.
- `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`: applied C20-C22 while retaining metadata, exact one-byte storage/boundaries, nonduplicating CPP disposition, and blank H. Post-validation SHA256 `35AA50F4910E6B294527BA6D2F31F3205418452FBE940BFAC1B8F1DB8575D23E`, 16,852 bytes, 132 lines.
- `by-file/StartupWindow.md`: applied C23-C25 with the exact helper/global definition/declaration route and generated-H defect/repair, while preserving all unrelated translation-unit inventory and history. Post-validation SHA256 `0B3C85DE029B8DA01A0DAE0237F7F324FDB3D4C3346DBA8DCBAF9E18FA5040D4`, 62,930 bytes, 305 lines.
- `by-memory/0x004b5f00-0x004b6409.FontImageLib.md`: applied C26-C27 while preserving the non-emitting mixed range, all seven FontImageLib children, every padding fact, and blank aggregate CPP/H. Post-validation SHA256 `DC51CE1F03E419558023325A1BC64C3A01AC409F3B42A1A463C1E8299C523250`, 19,883 bytes, 157 lines.
- This report was reconciled additively after the ordinary callback. Because embedding its own SHA256 would change that SHA256, exact current report identity must be computed from the released artifact; current Gate/lifecycle truth is authoritative only from fresh supervisor audit, current path, and validator-owned status/history metadata.
- C28-C34 support documents were reread and not edited. Their verified identities remain: UID0000EO `DE16797441A77EAB17D9414E9F2FBAA4CD52D034B5A26476A46A45720FD24A96`; UID0000ON `677C5D58311C9A263D17139E4FFEA90837587D25365DB0220827AB7A353E873D`; UID000162 `6B5D6739EB8436DB939D9AFC71243996D974D9EB149FCFF6C3821CB959F76596`; UID00005V `C7F0E15DE5FBD9747328F567E42F5081A3B54D38BF7688DBBE15F2EC1D73CF1A`; UID0000JR `4EA6DDFC853BC82D724D777BB77BC8D97D0C3AFA2D1285E77A440EA120B3CA3F`; UID0000JH `1EDDB096D765C2DEE11BD7A43170B9239CC2E9060FAC4F443A19295AC76AB5D5`; UID00005B `3A845C87CFAB8121E80FB33F0376B4F50E91D0FCCF89E14491201E7C9F22ADB7`.
- Historical callback write-scope record (`2026-08-01`): IDA, manual coverage, generated output, tracker/project-state, audit/catalog/lifecycle, goal/notes, and destinations outside the exact ordinary write set were not edited in that callback. This statement records that dated callback scope and does not assert their current state.

## Implementation Tracking Checklist

- [x] Read current goal, project skill, literal template, workflow, inference, score-blocker, and by-structure rules.
- [x] Verified exact target identity/range/body/type/frame/comments/bytes through healthy live read-only MCP.
- [x] Enumerated all 33 target callsites without pagination remainder.
- [x] Classified all 33 uses into 26 TextEditPane legacy-mode and seven GrafPort font-id calls.
- [x] Investigated raw caller starts instead of treating no-function state as a blocker.
- [x] Resolved human helper/global names and rejected raw/decompiler aliases.
- [x] Resolved bool versus integer/font-id return semantics.
- [x] Resolved external linkage versus static/inline alternatives.
- [x] Ranked source placement and retained physical FontImageLib adjacency as explicit counter-evidence.
- [x] Resolved owner/emitter and no-duplicate storage route.
- [x] Supplied exact target CPP and H formal payloads.
- [x] Supplied complete resulting UID0000SW CPP/H payloads, including guard and child expansion.
- [x] Supplied exact UID0001OH no-duplicate CPP and blank-H disposition.
- [x] Confirmed third-party import directives are not applicable to this first-party NexusTK helper/global route.
- [x] Resolved score blockers and supplied target/support score dispositions.
- [x] Read exact manual coverage rows and supplied M01-M04 plus N01-N04.
- [x] Supplied 71 atomic ledger claims with exact UIDs/destinations/actions/proposed states.
- [x] Supplied eight atomic IDA action rows plus six separately tabulated protected dependency readbacks with literal prestates/actions/readbacks/boundaries.
- [x] Closed all nine open questions or retained bounded confidence caps.
- [x] Confirmed Wave2/Wave3 material was not used as current authority.
- [x] Historical supervisor Gate 1 acceptance applies only to pre-callback SHA256 `3A1104DF21E517893ED0FC864E82C41F27A28D5CF587B3822C70FA5CD85D1562`, 80,183 bytes/693 lines, audit timestamp `2026-08-01T03:19:26.9882175-04:00`; current Gate truth is authoritative only from the exact-artifact audit ledger.
- [x] C01 add exact range/status to `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`.
- [x] C02 add exact logical-inverse behavior to `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`.
- [x] C03 add exact bool ABI/frame/no-local state to `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`.
- [x] C04 add all 33 code xrefs to `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`.
- [x] C05 add the 26 TextEditPane legacy-mode uses to `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`.
- [x] C06 add the seven GrafPort font-id uses to `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`.
- [x] C07 add accepted/rejected source-name analysis to `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`.
- [x] C08 add external-linkage proof to `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`.
- [x] C09 verify owner/emitter UID0000SW remain exact in `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`.
- [x] C10 add ranked source placement and UID0000O5 inference caveat to `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`.
- [x] C11 verify exact target CPP remains in `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`.
- [x] C12 verify exact target H remains in `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`.
- [x] C13 apply target score `92/93` with unchanged reconstructable/owner/emitter metadata in `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`.
- [x] C14 historicalize the stale blank-formal assertion in `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`.
- [x] C15 add UID0003XA body/type/33-call relationship without loss to `by-global/g_useEpfAssets.md`.
- [x] C16 verify UID0000SW CPP definition and CPP child expansion remain exact in `by-global/g_useEpfAssets.md`.
- [x] C17 replace UID0000SW H with the complete guarded extern/child payload in `by-global/g_useEpfAssets.md`.
- [x] C18 verify UID0000SW `88/90` and owner/emitter UID0000O5 remain exact in `by-global/g_useEpfAssets.md`.
- [x] C19 preserve the StartupWindow route and original-file caveat in `by-global/g_useEpfAssets.md`.
- [x] C20 add exact IDA item/comment/boundary and UID0003XA dependency evidence to `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`.
- [x] C21 verify the no-duplicate CPP marker and blank H in `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`.
- [x] C22 verify UID0001OH `88/90` and owner/emitter UID0000SW in `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`.
- [x] C23 add the global/helper definition/declaration route to `by-file/StartupWindow.md`.
- [x] C24 add the generated-H defect and guarded child-expansion repair to `by-file/StartupWindow.md`.
- [x] C25 verify UID0000O5 `89/88` and original-file caveat in `by-file/StartupWindow.md`.
- [x] C26 add the full external-helper/caller/owner/formal separation to `by-memory/0x004b5f00-0x004b6409.FontImageLib.md`.
- [x] C27 verify UID00015A `90/94`, nonreconstructable, owner NONE, blank CPP, and blank H in `by-memory/0x004b5f00-0x004b6409.FontImageLib.md`.
- [x] C28 verify no change to `by-class/TextEditPane.md` formal H at SHA256 `DE16797441A77EAB17D9414E9F2FBAA4CD52D034B5A26476A46A45720FD24A96`.
- [x] C29 verify no change to `by-file/TextEditPane.md` constructor support at SHA256 `677C5D58311C9A263D17139E4FFEA90837587D25365DB0220827AB7A353E873D`.
- [x] C30 verify no change to `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md` at SHA256 `6B5D6739EB8436DB939D9AFC71243996D974D9EB149FCFF6C3821CB959F76596`.
- [x] C31 verify no change to `by-class/GrafPort.md` formal H at SHA256 `C7F0E15DE5FBD9747328F567E42F5081A3B54D38BF7688DBBE15F2EC1D73CF1A`.
- [x] C32 verify no change to `by-file/GrafPort.md` ownership at SHA256 `4EA6DDFC853BC82D724D777BB77BC8D97D0C3AFA2D1285E77A440EA120B3CA3F`.
- [x] C33 verify no change to `by-file/FontImageLib.md` exclusions at SHA256 `1EDDB096D765C2DEE11BD7A43170B9239CC2E9060FAC4F443A19295AC76AB5D5`.
- [x] C34 verify no change to `by-class/FontImageLib.md` child inventory at SHA256 `3A845C87CFAB8121E80FB33F0376B4F50E91D0FCCF89E14491201E7C9F22ADB7`.
- [x] Ran target scoped validator as command `000000020495`; recorded timestamp/exit/ok/diagnostics/generated-skip state and post identity.
- [x] Ran UID0000SW scoped validator as command `000000020497`; recorded timestamp/exit/ok/diagnostics/generated-skip state and post identity.
- [x] Ran UID0001OH scoped validator as command `000000020498`; recorded timestamp/exit/ok/diagnostics/generated-skip state and post identity.
- [x] Ran UID0000O5 scoped validator as command `000000020501`; recorded timestamp/exit/ok/diagnostics/generated-skip state and post identity.
- [x] Ran UID00015A scoped validator as command `000000020502`; recorded timestamp/exit/ok/diagnostics/generated-skip state and post identity.
- Gate 2A disposition source: fresh supervisor readback of every ordinary/formal/score/history claim; no current Gate 2A state is asserted by this report.
- IDA-3XA-001 disposition source: fresh supervisor Gate 2B name readback; no current action state is asserted here.
- IDA-3XA-002 disposition source: fresh supervisor Gate 2B declaration readback; no current action state is asserted here.
- IDA-3XA-003 disposition source: fresh supervisor Gate 2B regular-comment prestate/action/readback evidence; no current action state is asserted here.
- IDA-3XA-004 disposition source: fresh supervisor Gate 2B repeatable-comment prestate/action/readback evidence; no current action state is asserted here.
- IDA-3XA-005 disposition source: fresh supervisor Gate 2B global-name readback; no current action state is asserted here.
- IDA-3XA-006 disposition source: fresh supervisor Gate 2B global-bool-type readback; no current action state is asserted here.
- IDA-3XA-007 disposition source: fresh supervisor Gate 2B global regular-comment prestate/action/readback evidence; no current action state is asserted here.
- IDA-3XA-008 disposition source: fresh supervisor Gate 2B global repeatable-comment prestate/action/readback evidence; no current action state is asserted here.
- IDA-3XA-009 disposition source: fresh supervisor Gate 2B predecessor-padding readback; no current action state is asserted here.
- IDA-3XA-010 disposition source: fresh supervisor Gate 2B successor-padding readback; no current action state is asserted here.
- IDA-3XA-011 disposition source: fresh supervisor Gate 2B predecessor-function-boundary readback; no current action state is asserted here.
- IDA-3XA-012 disposition source: fresh supervisor Gate 2B successor-function-boundary readback; no current action state is asserted here.
- IDA-3XA-013 disposition source: fresh supervisor Gate 2B left-neighbor readback; no current action state is asserted here.
- IDA-3XA-014 disposition source: fresh supervisor Gate 2B right-neighbor readback; no current action state is asserted here.
- IDA backup/save/catalog disposition source: current supervisor records and saved-IDB evidence; no current state is asserted here.
- M01 disposition source: fresh supervisor readback of the by-memory manual report against the exact target insertion text; no current application state is asserted here.
- M02 disposition source: fresh supervisor readback of the by-memory manual report against the exact storage replacement text; no current application state is asserted here.
- M03 disposition source: fresh supervisor readback of the by-global manual report against the exact replacement text; no current application state is asserted here.
- M04 disposition source: fresh supervisor readback of the by-file manual report against the exact replacement text; no current application state is asserted here.
- N01-N04 disposition source: fresh supervisor readback of the then-current manual rows; no current no-op confirmation state is asserted here.
- Generated StartupWindow.cpp disposition source: fresh supervisor readback of validator-owned output; no current definition-count state is asserted here.
- Generated StartupWindow.h disposition source: fresh supervisor readback of validator-owned output; no current guard/declaration state is asserted here.
- Tracker/report-coverage disposition source: fresh supervisor readback of validator-owned tracker state; no current coverage state is asserted here.
- Gate review disposition source: fresh exact-artifact supervisor audit. The accepted pre-callback Gate 1 hash is explicitly historical and is not current report identity.
- Report lifecycle truth source: current report path plus validator-owned status/history metadata; this checklist does not assert current execution/archive state.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000020529","destination_path":"executed-b-agent-research/B004/0003XA-IsLegacyAssetMode-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0003XA-IsLegacyAssetMode-source-quality.md","timestamp":"2026-08-01T05:10:38-04:00","uid":"0003XA"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003XA-IsLegacyAssetMode-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0003XA-IsLegacyAssetMode-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003XA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
