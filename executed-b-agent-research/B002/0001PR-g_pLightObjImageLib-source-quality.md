** TARGET-REPORT-UID:0001PR **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001PR g_pLightObjImageLib Ownership / Split Research


## Finalized Report / Current Recommendation

- Current recommendation and callback state: the accepted physical/semantic split is applied. Physical storage page [UID:0001PR] is a semantic-owned, non-emitting index for the single zero-initialized source global emitted by [UID:0000RD] `g_pLightObjImageLib`.
- Final disposition: [UID:0000RD] is the sole externally linked definition in `NexusTK/render/LightObjImageLib.cpp`; [UID:0001UX] carries the complete header-facing class plus `extern` declaration; [UID:0001PR] carries no C++ and cannot duplicate storage.
- Applied work: Destinations 1-14 and bounded support synchronization are complete. The class uses direct `LObject, Singleton<LightObjImageLib>` inheritance, preserves `ProtectedArray<LightInfo>` at `+0x04` by EBO, omits handwritten singleton publication/clear from the constructor/destructor, and classifies the clear/scalar/vtable artifacts as compiler-generated and non-emitting.
- B002's ordinary edits, scoped validators, lease releases, fourteen-formal parity check, and waited generated readback are complete. Manual coverage and report lifecycle are supervisor/validator-owned; this report does not assert a mutable execution or archive state beyond the authoritative current path and validator-owned history.
- Confidence: very strong for storage, type, one-definition route, direct bases, object size/layout, lifetime lowering, all 19 references, method bodies, and compiler/source split. Exact original lexical spelling of `tableId` and the singleton variable is unrecoverable and remains the bounded confidence cap.

## Supporting Research

- Mandatory live MCP evidence was collected on 2026-07-21 from freshly discovered database `9b0396a3`, worker PID `15732`. `server_health` returned `ok`; auto-analysis, Hex-Rays, and the 2,067-entry string cache were ready.
- Current active-pool coordination at the final research read: B001 owns adjacent physical `g_pHumanImageLib` UID0001PM; B003 owns unrelated UID0001PK; B004 owns adjacent `g_pEffectObjImageLib` UID0001PQ and temporarily leased only its own `0x004e5b70` Effect clear helper; B005 owns unrelated UID00029O. No active report or lease owns UID0001PR, UID0000RD, UID000076, UID0000KP, or another LightObjImageLib destination.
- Exact old-report search terms: `UID0001PR`, `0x0069b450`, `g_pLightObjImageLib`, `LightObjImageLibConstructor`, `LightObjImageLibDestructor`, `LightObjImageLibGetLightBounds`, `LightObjImageLibDrawLightMode1`, `LightObjImageLibDrawLightMode2`, `LightObjImageLibSingletonClearHelper`, and `LightObjImageLibScalarDeletingDestructor`.
- Active B001-B005 report roots searched: `tools/leaser/Agents/Agent-B001/research` through `Agent-B005/research`. There is no direct UID0001PR report. B004's active `0001PQ-g_pEffectObjImageLib-source-quality.md` is an adjacent-family comparison; B005's `00029O-MainUiLayerSlotsTail-source-quality.md` only mentions the global indirectly.
- Central executed root searched: `executed-b-agent-research`. Directly relevant artifacts opened were B001 `00017P-LightObjImageLibLocalMethodCluster-source-quality.md`; B002 `00017Z-LightObjImageLibSingletonClearHelper-source-quality.md`; B003 `0002IU-00017Q-0002IW-0002IX-0002IY-lightobjimagelib-source-quality.md`, `0002IV-lightobj-get-light-bounds-source-quality.md`, `0003LZ-LightInfoTableLoader.md`, and `000178-...-image-library-cleanup-source-quality.md`; B008 `0002H8-ApplicationShutdown-empty-emitter-source-quality.md`; B010 `0001D8-AttachedObjectPane-source-quality.md`; B011 `0002TX-AttachmentAnchorImageBoundsMetricRaw-source-quality.md`; and B015 `0001DH-AttachmentAnchorResolver-source-quality.md`.
- Legacy executed/archive roots under per-agent research trees were searched. No additional exact UID0001PR direct report exists. Older reports are corroborating leads only; every material recommendation below was independently checked against the current binary and docs.
- Historical Wave3/simroot statements were read only as provenance. They were not treated as authority where current IDA, current ordinary docs, or current generated output contradicted them.
- Historical lifecycle checkpoint: supervisor command `000000016065` executed the report historically, and supervisor command `000000016070` historically invalidated that execution and returned the report solely for stale lifecycle-text repair. B002 ran neither command and ran no report lifecycle action. At B002's final authored checkpoint, the ordinary implementation, corrected manual coverage union, validator evidence, technical report body, and lease release are complete and ready for supervisor execution. No mutable artifact path, executed/non-executed status, archive state, or future lifecycle result is asserted here; the exact artifact location and validator-owned history footer are the sole current lifecycle authority.

## Target

- Target UID: `0001PR`.
- Target path: `by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md`.
- Source queue/report row: evidence-time command `000000015946`, SHA256 `C66F72D799EC654ED43E8F4FB800BABF43E9571D5981EEC79114BB119E83D476`, recorded UID0001PR at `86/90`, true, blank formal before callback. Post-callback command `000000015984`, SHA256 `ACC6F4D953EB05BDF3EF4AE60B80B47E8FE7DE0FA1860440F0E4333218294855`, first recorded the applied row. At the final report read, validator-owned `auto-generated/-ag-research-tracker.md` is command `000000015994`, timestamp `2026-07-21T15:53:48-04:00`, SHA256 `61354AC166FAF4457A524110C8C2D76B182215D8AE1DE60173A874F85EEEE919`, 1,548,363 bytes / 6,263 lines; UID0001PR occurs once at line 3846 as `92/94`, `false`, Nested `0`, blank emitter/position/formal route. All are time-bounded external snapshots rather than claims that unrelated future validator work cannot advance the tracker header.
- Assignment-time supervisor classification: direct report required; older LightObjImageLib reports were family support, not a substitute.
- Evidence-time scores and parent state were target `86/90`, header owner/emitter UID0000KP, reconstructable true, blank position/C++, with semantic global UID0000RD separately `87/89`; that pre-callback split was contradictory. Current ordinary state is the applied target `92/94`, semantic owner UID0000RD, false/non-emitting, blank position/formal, with UID0000RD `92/94` as the sole definition at file position `0`.

## Current Target State

- Evidence-time / pre-callback target metadata was `86/90`, `CANONICAL_OWNER:0000KP`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KP`, blank position and managed C++; its Item Summary incorrectly asserted `0xffffffff`, and its file-owned route contradicted semantic global UID0000RD.
- Current target metadata is `92/94`, `CANONICAL_OWNER:0000RD`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal, `Nested:0`. Current prose and Item Summary preserve exact loader-zero physical storage, all 19 references, semantic ownership, sole-definition routing, PE arithmetic, and rejected historical initializer/source routes.
- Current source family is applied: UID0000RD owns one definition at position `0`; UID000076 routes the ordered class/type/method union; UID0001UW/UID0001UX emit at `1/2`; five methods emit at `10/30/40/50/60`; UID00017Z/UID0002IY/UID0001XY/UID00031S are false/non-emitting compiler/data evidence; UID0000KP is prose-only at `92/94` without by-file reconstruction metadata.
- Evidence-time generated `LightObjImageLib.cpp` command `000000015935`, SHA256 `6B4626D8E37F3EE26E614E18649358F80A448E509C93F018877520ADEF3DE147`, had nine Empty Emitter Markers, one UID0001PR marker, zero typed definitions, one explicit constructor publication, and one explicit destructor clear. That snapshot is historical.
- Target-specific waited proof is validator command `000000015981`, timestamp `2026-07-21T15:49:27-04:00`, SHA256 `DD22E999E9F1BEDA56BD8FFD0FEFD454B89717889704B7E4E31415E54CAA0AAC`. Later unrelated external generation advanced only the volatile header epoch: at the final report read, `LightObjImageLib.cpp` is command `000000015993`, timestamp `2026-07-21T15:52:21-04:00`, SHA256 `E7102C778C81D7911E31A88A6B76AD9933FBC1FF954D138C70073683F791BBC7`, semantic body SHA256 `7CF4452F2C28422EADD1A7BD36DAD138B33E6473526309CF9F6678D31E119BD2`, 7,557 bytes / 176 lines. It still has one global definition, one extern, one LightInfo, one complete class, one constructor/destructor/bounds/mode1/mode2 in exact order, and zero physical/helper/scalar/vtable markers, empty markers, manual singleton writes, handwritten ABI, or decompiler residue.
- B002-authored checkpoint state is implementation-callback complete and ready for supervisor execution. Historically, supervisor command `000000016065` executed the report and supervisor command `000000016070` invalidated/returned it solely because stale readiness/current-state wording failed the post-execution artifact audit. B002 edited and scoped-validated only accepted ordinary destinations, released every lease, and did not run `execute_report`, report probing, move, archive, or any lifecycle command. This checkpoint does not assert a mutable path, executed/non-executed status, archive state, or future lifecycle result; the exact artifact location and validator-owned history footer are the sole current lifecycle authority.

## Executive Recommendation

- UID0001PR is applied at `92/94`, semantic owner UID0000RD, `RECONSTRUCTABLE:FALSE`, blank emitter/position/C++, `Nested:0`; it remains exact binary storage evidence, not a second source declaration.
- UID0000RD is applied at `92/94`, owner/emitter UID0000KP, position `0`, with exactly one external definition after a local forward declaration.
- UID000076 and UID0000KP are applied at `92/94`. The class page retains its route marker and `[[CHILDREN]]`; UID0001UX emits the complete declaration at class position `2`, after UID0001UW `LightInfo` at position `1`.
- Source methods route to class UID000076 at positions `10,30,40,50,60`. Constructor initializes the direct Singleton base and contains no assignment. Destructor deletes generated frames only; implicit `ProtectedArray`, `Singleton`, and `LObject` destruction regenerate entry-buffer free, global clear, and base teardown.
- UID00017Z, UID0002IY, UID0001XY, and UID00031S are applied as compiler/generated-binary, false/non-emitting, blank formal. No source helper, scalar wrapper, RTTI, or raw vtable dwords are handwritten.
- No split, rename, or new UID is required.

## Supervisor Active Recheck

- The supervisor assigned UID0001PR because the header-owner/semantic-global route, stale initializer, lifetime inventory, and source/ABI split were not closed by older reports; Gate 1 accepted this report at SHA256 `0EFF30A1655D68235A1154772C179361507AF7432E71D47D327AFDEB4600E3F1`, and the bounded callback has now applied those accepted decisions.
- No range split is needed: `[0x0069b450,0x0069b454)` is one pointer slot. The source split is semantic: physical evidence page versus sole by-global definition.
- Every source-bearing family member has destination-ready C++ below and byte-equal current ordinary formals. Every compiler/data-only member has an exact blank formal, no-code proof, false/non-emitting metadata, and zero generated marker.

## Inference Research Guidance Check

- `by-structure.md` discipline requires semantic ownership to survive even when a physical page is non-emitting. Therefore UID0001PR can and should retain UID0000RD as owner while blanking emission.
- IDA facts are addresses, bytes, RTTI descriptors, PMD values, instruction effects, xrefs, function boundaries, and startup allocation size. Documentation facts are current UID routes and accepted method bodies. Inference is limited to source-facing spelling and reconstruction organization.
- Existing `0xffffffff`, handwritten publish/clear, static-cleanup-helper API, and file-owned physical storage assumptions were treated as uncertain and rechecked.
- Wave2/Wave3 artifacts were found in history and ignored as stale wherever current executable and canonical docs provide stronger evidence.

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution | Basis / status |
| --- | --- | --- |
| `0xffffffff` initializer | Reject as current source state; emit `= 0` once | PE `.data` arithmetic places the RVA beyond raw bytes; live MCP returns zero bytes/value. Direct binary fact. |
| Header owner UID0000KP versus semantic UID0000RD | Physical page owner becomes UID0000RD; global definition emits through UID0000KP | One-definition policy and established ItemObjImageLib/HumanImageLib patterns. |
| `g_pLightObjImageLib` versus `g_pLightObjectImageLib` | Keep `g_pLightObjImageLib`; historicalize longer alias as generated pollution | Canonical docs, saved IDA label, method/report usage, one physical address. Inferred spelling, exact identity. |
| Linkage | External definition, not `static` | Cross-TU ObjectPane/AttachedObjectPane/AttachmentAnchorResolver consumers require external visibility. |
| Direct bases | `LObject`, `Singleton<LightObjImageLib>` | RTTI names and base descriptors; Singleton PMD `{4,-1,0}`. Direct binary fact. |
| `+0x04` collision | Singleton EBO overlaps `ProtectedArray<LightInfo> m_lightInfos` | Constructor adjusted publication and complete 0x30 allocation; established compiler pattern. |
| Constructor publication/null branch | Compiler-lowered direct Singleton base construction | `lea this+4`, null test, subtract 4, global store; not authored logic. |
| Destructor clear | Compiler-lowered reverse Singleton base destruction | Clear follows member teardown before LObject tail; same effect in scalar and EH base destructor. |
| Buffer free in ordinary destructor | Implicit `ProtectedArray<LightInfo>` member destruction | Vptr restore and buffer free occur after authored generated-frame loop. Do not duplicate in source body. |
| UID00017Z identity | `Singleton<LightObjImageLib>` base-destructor instantiation used by constructor unwind | Eleven-byte clear, only EH jump, no ordinary caller/callee/API evidence. |
| UID0002IY identity | Compiler scalar deleting destructor | Vtable-only route, delete flags/size/free mechanics, ordinary-destructor parity. |
| Vtable/RTTI source | Compiler generated from class virtual declarations | Exact data is evidence, not handwritten arrays. |
| `LightInfo` fields | `tableId`, `innerRadius`, `radiusX`, `radiusY`, `brightness`, `blendScale`, `generatedFrame` | Exact load order and consumers; only `tableId` spelling remains inferred. |
| `ProtectedArray` member name | `m_lightInfos` | Human-shaped descriptive name matching accepted project style; layout is exact, lexical name inferred. |
| Source file | `NexusTK/render/LightObjImageLib.cpp` | Resource, class, methods, global, and current generated route agree. |
| Consumer ownership | Reject all consumers as owners | Consumers only read/select/draw/delete; publication and complete class source remain LightObjImageLib-owned. |

Rejected alternatives: a second by-memory definition violates one-definition behavior; a `static` definition breaks cross-TU consumers; a source `ClearLightObjImageLibSingleton()` invents an API; explicit constructor/destructor global assignments duplicate Singleton lowering; manually emitted vtable/RTTI/scalar wrappers duplicate ABI output; ownerless physical storage loses semantic traceability; and retaining reconstructable blank ABI pages would have preserved the evidence-time Empty Emitter Markers now removed by the callback.

## Evidence Standards Used

- Evidence ladder: live MCP health, bytes/global values, xrefs, disassembly/decompilation, RTTI names/descriptors, vtable xrefs, startup allocation/caller, raw PE section arithmetic, current ordinary docs, accepted executed reports, generated output, tracker/manual rows, and negative searches.
- Binary facts outrank old reports. Old reports were used to locate methods and accepted bodies, then independently checked against current binary shape.
- Confidence remains below absolute only for unrecoverable source spelling, not behavior, ownership, source placement, or C++ readiness.

## Evidence Checked

- Live MCP: fresh `idb_list`, `server_health`, `get_bytes(0x0069b440,32)`, `get_global_value` for `0x0069b44c/450/454`, `xrefs_to(0x0069b450)`, scoped `search_text`, constructor/startup disassembly/decompilation, vtable xrefs, RTTI entity/name/string query, and bounded consumer decompilation.
- Raw PE: `NexusTK.exe` image base `0x00400000`; target RVA `0x0029b450`; `.data` VA `0x0026d000`, virtual size `0x2fe24`, raw size `0xd800`, raw pointer `0x26ac00`; target delta `0x2e450` exceeds raw size, so loader zero-fill is mandatory.
- Current by-* docs: target, global, class, file, layout, row type, vtable type/data, five source methods, singleton base-destructor helper, scalar wrapper, local cluster, startup/shutdown, ObjectPane/AttachedObjectPane, and AttachmentAnchorResolver support.
- Current generated/tracker/manual coverage and all six affected manual coverage roots were read. Exact hashes and rows are recorded below.
- Negative checks: no second storage slot, no separate longer-alias global, no ordinary UID00017Z caller, no direct draw callers outside vtable dispatch, no additional LightObjImageLib virtual slot, no source reason for manual ABI arrays/wrappers, no active exact-target report/lease, and no raw-file bytes backing the target.
- No MCP call failed. No IDA mutation was requested or performed.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0001PR is exact four-byte storage `[0x0069b450,0x0069b454)`. | direct | MCP bytes/xrefs and PE mapping | D1 target | incorporate | applied |
| C02 | Loader initial value is zero; `0xffffffff` is stale history. | direct | `.data` raw/virtual arithmetic and MCP zero bytes | D1/D2 | reject-stale | applied |
| C03 | Type is `LightObjImageLib *`. | very strong | lifecycle writes, virtual consumers, RTTI | D1/D2/D5 | incorporate | applied |
| C04 | Canonical spelling is `g_pLightObjImageLib`. | strong | canonical docs/IDA/current consumers | D1/D2/D5 | incorporate | applied |
| C05 | `g_pLightObjectImageLib` is a superseded generated alias. | strong | same address and no second storage | D1/D2/file prose | historicalize | applied |
| C06 | Exactly 19 xrefs exist: five writes and fourteen reads. | direct | MCP `xrefs_to`, scoped text search | D1/D2 | incorporate | applied |
| C07 | UID0000RD is semantic owner and sole definition. | very strong | one slot and established source policy | D1/D2 | incorporate | applied |
| C08 | UID0001PR is false/non-emitting with blank C++. | very strong | duplicate-definition exclusion | D1 | incorporate | applied |
| C09 | Definition has external linkage and zero initializer. | very strong | cross-TU consumers and loader state | D2 | incorporate | applied |
| C10 | File owner is UID0000KP at `NexusTK/render/LightObjImageLib.cpp`. | very strong | resource/method/global route | D2/D3/file | incorporate | applied |
| C11 | Direct bases are `LObject` and `Singleton<LightObjImageLib>`. | direct | RTTI hierarchy/type descriptors | D5 | incorporate | applied |
| C12 | Singleton PMD is `{4,-1,0}` and EBO overlaps the member at +4. | direct | RTTI descriptor and constructor lowering | D3/D5 | incorporate | applied |
| C13 | Complete object size is `0x30`. | direct | startup `operator new(0x30)` | D5 | incorporate | applied |
| C14 | `ProtectedArray<LightInfo>` spans +4 through +2f. | very strong | vptr/count/entries/capacity/fallback use | D5 | incorporate | applied |
| C15 | `LightInfo` is exact 0x1c with seven resolved fields. | very strong | constructor/load/draw/bounds/destructor | D4 | incorporate | applied |
| C16 | Constructor is source-authored and startup-only. | direct | sole caller 0x4f6139 and exact body | D6 | already-present | already-present |
| C17 | Constructor publication/null store is compiler Singleton lowering. | direct | adjusted this+4/subtract4 sequence | D6 | reject-invalid | applied |
| C18 | Constructor must initialize `Singleton<LightObjImageLib>()`. | very strong | direct base/PMD/source parity | D6 | incorporate | applied |
| C19 | Ordinary destructor authored logic deletes generated frames. | direct | raw body prefix and scalar parity | D7 | incorporate | applied |
| C20 | Entry free/global clear/base tail are implicit member/base destruction. | very strong | reverse order and EBO hierarchy | D7 | reject-invalid | applied |
| C21 | GetLightBounds body/signature are source-ready. | very strong | exact body and sole caller | D8 | already-present | applied |
| C22 | DrawLightMode1 body/signature are source-ready. | very strong | vtable slot and exact body | D9 | already-present | applied |
| C23 | DrawLightMode2 body/signature are source-ready. | very strong | vtable slot and exact body | D10 | already-present | applied |
| C24 | UID00017Z is EH-only Singleton base-destructor compiler output. | direct | one cleanup jump, eleven-byte body | D13 | incorporate | applied |
| C25 | UID0002IY is compiler scalar deleting wrapper. | direct | vtable-only/delete-flag body | D14 | incorporate | applied |
| C26 | UID0001XY is compiler/source-declared vtable support, false/non-emitting. | very strong | exact slots plus complete class declaration | D11 | incorporate | applied |
| C27 | UID00031S is compiler RTTI/vtable data, false/non-emitting. | direct | exact dwords/RTTI/xrefs | D12 | incorporate | applied |
| C28 | Inherited slots +4/+8 are not Light-specific source children. | direct | LObject descriptor return and `ret 8` | D5/D11 | reject-invalid | applied |
| C29 | Local aggregate UID00017P stays ownerless/non-emitting. | very strong | exact children already own bodies | D16 | already-present | already-present |
| C30 | Startup allocates 0x30 and calls constructor once. | direct | 0x4f6118-0x4f6139 | D17 | already-present | already-present |
| C31 | Shutdown performs the one deleting-destruction read. | direct | 0x4f6642 path | D18 | already-present | already-present |
| C32 | Three ObjectPane refs select LightInfo and adjust brightness. | direct | 0x5373fa/54b/618 | consumer support | already-present | already-present |
| C33 | Six AttachedObjectPane refs select one/two rows and adjust brightness. | direct | 0x538162-0x538527 | consumer support | already-present | already-present |
| C34 | Raw metric helper returns selected `brightness`. | direct | 0x53c6bc body | consumer support | already-present | already-present |
| C35 | Bounds consumer calls `GetLightBounds`. | direct | 0x53c81d/0x53c82b | consumer support | already-present | already-present |
| C36 | Mode helpers dispatch virtual slots +0x0c/+0x10. | direct | 0x53c9c3/0x53c9f3 | consumer support | already-present | already-present |
| C37 | No consumer owns storage/publication. | very strong | read-only consumer graph | ownership sections | reject-invalid | already-present |
| C38 | File/class/type/method scores can reach source-ready range. | strong | blocker closure and complete formals | score section/D2-D14 | incorporate | applied |
| C39 | Existing technical history remains, labeled superseded where needed. | strong | no-loss workflow | all destinations | historicalize | applied |
| C40 | Supervisor-owned manual coverage rows require a no-loss linked representation that retains every concrete current-row fact, explicitly disposes each superseded assumption, appends the accepted LightObjImageLib source-quality delta and terminal score, and preserves every durable Markdown UID route. | direct | 16 supervisor-corrected current-row readbacks plus fact/link parity audit after command 000000016016 exposed the prior lossy handoff | coverage section | incorporate | already-present |

### Callback Verification Proof

- C01-C09: D1/D2 are applied and validated by commands `000000015960` and `000000015961`; current hashes are recorded in Changed Files. D1 is false/non-emitting with exact blank formal and complete zero-fill/19-ref/no-code proof; D2 emits the sole external definition at position `0`.
- C10-C15: D3-D5 plus prose-only UID0000KP are applied by commands `000000015962`-`000000015964` and `000000015976`. The class marker, direct bases, EBO/`0x30` layout, complete `LightInfo`, class/extern declaration, and `1/2` order are byte-equal to the accepted formals.
- C16-C23: D6-D10 are applied by commands `000000015965`-`000000015969`; formatting-only parity corrections were revalidated by `000000015978`-`000000015980`. Current formals exactly preserve the startup constructor, authored frame-only destructor, bounds helper, and distinct mode-1/mode-2 methods at `10/30/40/50/60`.
- C24-C28: D11-D14 are applied by commands `000000015970`, `000000015973`, `000000015974`, and `000000015975`. All four pages are owner UID000076, false/non-emitting, blank emitter/position/formal, with complete helper/scalar/vtable/data no-code proof.
- C29-C37: read-only current hashes prove UID00017P, Application startup/shutdown, ObjectPane, AttachedObjectPane, AttachmentAnchorResolver, AlphaMaskSurface, DATFile, ProtectedArray, and RectBounds support remains at same-or-greater detail; no accepted source owner or consumer fact required an ordinary support edit.
- C38-C39: all accepted scores, metadata, source/ABI decisions, negative evidence, and historical alternatives are retained in the fifteen changed ordinary pages and this report. Fourteen of fourteen managed destination blocks compare byte-for-byte after CRLF normalization.
- C40: B002 reread all six supervisor-corrected manual roots after coverage validator command `000000016016` exposed that the prior report handoff had converted durable Markdown UID links to plain UID text and caused `reference_index_remove 0001XY`. The prior handoff is historical and lossy. The 16 rows below now match the corrected current rows fact for fact and preserve the linked UID00031S-to-UID0001XY, UID0000RD-to-UID0000KP, UID0000KP-to-UID00031S, UID0001UW/UID0001UX-to-UID000076, and UID0001XY-to-UID00031S/UID000076/UID0000KP routes verbatim. Verification is `already-present` from read-only row parity; B002 edited no manual file, and this coverage correction does not assert report execution or renewed Gate clearance.

## Positive Evidence Summary

- The target is live loader-zero storage, not initialized raw data.
- Constructor publication uses the exact adjusted direct-Singleton pattern proven by RTTI PMD +4; startup allocates the exact 0x30 complete object.
- All lifetime writes fit base construction/destruction and no separate authored helper API exists.
- Every read is a shutdown or light-render consumer; none competes for ownership.
- Existing method bodies, LightInfo schema, and vtable slots already supply a complete source family once the class/global route is corrected.

## IDA MCP Facts

- Database `9b0396a3`; imagebase `0x00400000`; health `ok`.
- `get_bytes(0x0069b440,32)` returned 32 zero bytes. Global values at 0x69b44c, 0x69b450, and 0x69b454 were all zero.
- Constructor `0x004df7e0` size `0x2c6`, one caller at `0x004f6139`; startup pushes `0x30` before allocation/call.
- Constructor direct-Singleton sequence uses `this+4`, stores adjusted derived pointer at 0x69b450, then installs class vptr at +0 and ProtectedArray vptr at +4.
- RTTI names `LightObjImageLib` and `Singleton<LightObjImageLib>`; class hierarchy count is three: complete class, LObject, Singleton. Singleton base descriptor PMD is `{mdisp=4,pdisp=-1,vdisp=0}`.
- Vtable begins 0x61b754: scalar destructor, inherited runtime/type helper, inherited `ret 8` no-op, DrawLightMode1, DrawLightMode2. Adjacent ProtectedArray vtable precedes it; NewHumanImageLib RTTI follows.
- UID00017Z bytes are `c7 05 50 b4 69 00 00 00 00 00 c3`; no ordinary caller/callee; constructor unwind jumps to it.
- Negative: no modeled function at raw ordinary destructor start, no direct draw callers, no second singleton slot, and no source-shaped caller for UID00017Z.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| 0x69b450-0x69b454 | UID0001PR target | physical pointer slot | false | UID0000RD | 92/94 | applied non-emitting |
| semantic global | UID0000RD | sole external definition | true | UID0000KP | 92/94 | applied position 0 |
| class route | UID000076 | class/child route | true | UID0000KP | 92/94 | applied marker |
| row type | UID0001UW | `LightInfo` 0x1c | true | UID000076 | 90/92 | applied position 1 |
| class layout | UID0001UX | complete declaration | true | UID000076 | 92/94 | applied position 2 |
| 0x4df7e0-0x4dfaa6 | UID0002IU | constructor | true | UID000076 | 92/94 | applied position 10 |
| 0x4dfab0-0x4dfb36 | UID00017Q | ordinary destructor | true | UID000076 | 92/94 | applied position 30 |
| 0x4dfb40-0x4dfbb0 | UID0002IV | GetLightBounds | true | UID000076 | 92/94 | applied position 40 |
| 0x4dfbb0-0x4dfc5a | UID0002IW | DrawLightMode1 | true | UID000076 | 92/94 | applied position 50 |
| 0x4dfc60-0x4dfd0a | UID0002IX | DrawLightMode2 | true | UID000076 | 92/94 | applied position 60 |
| 0x4e5bb0-0x4e5bbb | UID00017Z | Singleton base dtor instantiation | false | UID000076 | 93/96 | applied compiler-only |
| 0x4e65e0-0x4e669d | UID0002IY | scalar deleting destructor | false | UID000076 | 93/96 | applied compiler-only |
| vtable type | UID0001XY | source-declared/generated ABI | false | UID000076 | 92/95 | applied compiler-only |
| 0x61b750-0x61b768 | UID00031S | RTTI/vtable data | false | UID000076 | 92/95 | applied compiler-only |
| 0x4df7e0-0x4dfd0a | UID00017P | non-emitting split index | false | NONE | 86/92 | verify-only |

Padding remains exact: ten `cc` bytes after constructor, ten after ordinary destructor, six between draw modes, six before NewHumanImageLib, five before/after UID00017Z, and three after scalar wrapper.

## Direct Xref / Caller Inventory

| Address | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| 0x4df82b | constructor | compiler Singleton publication |
| 0x4df832 | constructor | compiler null-adjustment side |
| 0x4dfb23 | raw ordinary destructor | implicit Singleton clear |
| 0x4e5bb0 | UID00017Z | constructor-unwind Singleton base dtor |
| 0x4e665d | UID0002IY | scalar copy of Singleton clear |
| 0x4f6642 | ApplicationShutdown | null-check/delete singleton |
| 0x5373fa | ObjectPane destructor | subtract selected brightness |
| 0x53754b | ObjectPane AttachObject | add selected brightness |
| 0x537618 | ObjectPane DetachObject | subtract selected brightness |
| 0x538162, 0x5381f6 | AttachedObjectPane method | select up to two rows; subtract brightness |
| 0x53834d, 0x5383e0 | AttachedObjectPane method | select up to two rows; add brightness |
| 0x538488, 0x538527 | AttachedObjectPane method | select up to two rows; subtract brightness |
| 0x53c6bc | UID0002TX raw metric | return selected brightness |
| 0x53c81d | AttachmentAnchorResolver bounds | call GetLightBounds at 0x53c82b |
| 0x53c9c3 | mode-1 anchor helper | virtual slot +0x0c |
| 0x53c9f3 | raw mode-2 twin | virtual slot +0x10 |

Count is exactly 19 with `more:false`: five lifetime writes and fourteen reads. Constructor itself has one caller. Draw methods are vtable-only. Bounds has one direct caller.

## Documentation Evidence And IDA Status

- Evidence-time docs preserved methods, layout, resources, consumers, and padding but had stale source organization: target/header owner conflict, blank global/class/type pages, manual singleton operations, and reconstructable ABI emitters. That pre-callback state is superseded by the applied ordinary destinations above.
- Current ordinary docs contain the accepted source organization and exact formals. Current supervisor-owned manual rows still lag those ordinary docs at the final callback read: method rows remain `82%`, class `84%`, local aggregate broad/stale, target says `0xffffffff`, and ABI rows call compiler output reconstructable. The exact no-loss replacements below remain external handoff text and were not applied by B002.
- Historical generated command `15935` proved the old symptom: source methods appeared without a definition/declaration and nine target/type/compiler pages emitted Empty Emitter Markers. Target-specific waited command `15981` and final-read external command `15993` both prove the complete source union and zero such markers.
- Evidence-time tracker command `15946` reflected pre-callback scores and blank formals. Post-callback command `15984` and final-read command `15994` record UID0001PR at `92/94`, false/non-emitting. These snapshots are volatile validator-owned evidence, not files B002 edited or claims of permanent header authority.

## Ranked Ownership Analysis

### 1. UID0000RD semantic global through UID0000KP

- Evidence for: exact physical slot, canonical typed name, single source definition, class/resource locality, external consumers, established singleton-family policy.
- Evidence against: original symbol spelling is not PDB-proven.
- Decision: accept. Lexical uncertainty does not weaken semantic ownership or one-definition behavior.

### 2. UID000076 class

- Evidence for: owns direct bases, member layout, methods, vtable semantics, and lifecycle lowering.
- Evidence against: a class is not the semantic variable page.
- Decision: own methods/types/compiler artifacts, not the physical slot definition.

### 3. UID0000KP file or consumer ownership

- Evidence for: file is the final source emitter; consumers use the pointer.
- Evidence against: file ownership is routing, not semantic-global identity; consumers only read.
- Decision: UID0000KP remains final emitter/file parent. Reject direct file ownership on UID0001PR and reject all consumer owners.

### Proposed new file/grouping, if applicable

- No new file or UID. Existing `NexusTK/render/LightObjImageLib.cpp` is the exact narrow module.
- Existing UID00017P remains a non-emitting address index; compiler islands remain separate exact pages.

## Source Placement

- Module definition and method bodies: `NexusTK/render/LightObjImageLib.cpp` via UID0000KP.
- Header-facing declaration: UID0001UW `LightInfo`, then UID0001UX complete `LightObjImageLib`, followed by `extern LightObjImageLib *g_pLightObjImageLib;`.
- Definition position 0 precedes declaration/method output by a local class forward declaration, matching accepted project generation style.
- Reject `Application.cpp`, ObjectPane/AttachedObjectPane, AttachmentAnchorResolver, global-only synthetic files, function-local static, and explicit template-static duplicate definitions.

## Range / Split / Padding / Reclassification Analysis

- UID0001PR range remains exact and unsplit. It changes classification from reconstructable file-owned source to false/non-emitting physical storage semantically owned by UID0000RD.
- UID00017Z and UID0002IY remain exact ranges but change from reconstructable blank emitters to false compiler outputs.
- UID0001XY and UID00031S retain all slot/data evidence but become false/non-emitting.
- UID00017P remains ownerless/non-emitting and its exact child/padding inventory remains unchanged.
- No new child, rename, range extension, or cross-island merge is defensible.

## Negative Evidence Summary

- Zero raw backing excludes a source `0xffffffff` initializer.
- No second address or distinct xref set supports `g_pLightObjectImageLib` as another variable.
- No ordinary UID00017Z caller, parameters, receiver, branch, callee, string, or semantic return supports a handwritten helper.
- Scalar delete flags, size guard, optional storage free, vptr restores, RTTI dwords, constructor EH funclets, and security cookies are compiler mechanisms.
- Render readers prove use, not ownership. Startup/shutdown prove lifetime ordering, not alternate source placement.
- Evidence-time blank class/type emitters were not proof that source declarations did not exist; RTTI, layout, method accesses, and ABI tables require the declarations now applied.

## IDA Rename / Type / Comment Recommendations

- Safe source-facing recommendation only: keep `g_pLightObjImageLib`, `LightObjImageLib`, `LightInfo`, `m_lightInfos`, and resolved row fields.
- Historical aliases `dword_69B450`, `unk_69B450`, `g_pLightObjectImageLib`, `lightSource`, and `blendValue` remain provenance, explicitly rejected as current source names.
- UID00017Z should be described as `Singleton<LightObjImageLib>` base-destructor compiler instantiation, not renamed to a public clear API. UID0002IY remains scalar deleting destructor terminology.
- No IDA mutation was requested or performed during either research or the implementation callback.

## First-Draft C++ Recommendation

Destination 1 - UID0001PR target, exact blank non-emitting formal:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof: UID0001PR is physical evidence for the same storage defined once by UID0000RD. Any token here would create a duplicate declaration/definition or misleading marker.

Destination 2 - UID0000RD sole definition:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class LightObjImageLib;

LightObjImageLib *g_pLightObjImageLib = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 3 - UID000076 class route marker:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// LightObjImageLib class routing is documented here; LightInfo and the complete class declaration are emitted by exact type children, and method bodies remain on exact by-memory children.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 4 - UID0001UW LightInfo at position 1:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class AlphaMaskSurface;

struct LightInfo
{
    int tableId;
    int innerRadius;
    int radiusX;
    int radiusY;
    float brightness;
    float blendScale;
    AlphaMaskSurface *generatedFrame;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 5 - UID0001UX complete class at position 2:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct RectBounds;

class LightObjImageLib : public LObject, public Singleton<LightObjImageLib>
{
public:
    LightObjImageLib();
    virtual ~LightObjImageLib();

    void GetLightBounds(int lightIndex, RectBounds *outBounds);
    virtual void DrawLightMode1(AlphaMaskSurface *targetSurface, int centerX, int centerY, int lightIndex);
    virtual void DrawLightMode2(AlphaMaskSurface *targetSurface, int centerX, int centerY, int lightIndex);

private:
    ProtectedArray<LightInfo> m_lightInfos;
};

extern LightObjImageLib *g_pLightObjImageLib;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 6 - UID0002IU constructor at position 10:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
LightObjImageLib::LightObjImageLib()
    : Singleton<LightObjImageLib>()
{
    m_lightInfos.m_count = 0;
    m_lightInfos.m_entries = 0;
    m_lightInfos.m_defaultCapacity = 10;

    m_lightInfos.m_defaultEntry.tableId = -1;
    m_lightInfos.m_defaultEntry.innerRadius = -1;
    m_lightInfos.m_defaultEntry.radiusX = -1;
    m_lightInfos.m_defaultEntry.radiusY = -1;
    m_lightInfos.m_defaultEntry.brightness = 0.0f;
    m_lightInfos.m_defaultEntry.blendScale = 0.0f;
    m_lightInfos.m_defaultEntry.generatedFrame = 0;

    DATFile lightTable;
    lightTable.Open(L"LIGHT.TBL");

    int lightCount = 0;
    ReadEncodedTableInt(&lightTable, &lightCount);

    if (lightCount > 0 && m_lightInfos.m_count != lightCount) {
        LightInfo *newEntries = static_cast<LightInfo *>(operator new(sizeof(LightInfo) * lightCount));
        if (m_lightInfos.m_entries != 0) {
            int copyCount = lightCount;
            if (m_lightInfos.m_count < copyCount)
                copyCount = m_lightInfos.m_count;
            memmove(newEntries, m_lightInfos.m_entries, sizeof(LightInfo) * copyCount);
            free(m_lightInfos.m_entries);
        }
        m_lightInfos.m_count = lightCount;
        m_lightInfos.m_entries = newEntries;
    }

    for (int index = 0; index < lightCount; ++index) {
        LightInfo lightInfo;
        ReadEncodedTableInt(&lightTable, &lightInfo.tableId);
        ReadEncodedTableInt(&lightTable, &lightInfo.innerRadius);
        ReadEncodedTableInt(&lightTable, &lightInfo.radiusX);
        ReadEncodedTableInt(&lightTable, &lightInfo.radiusY);
        ReadEncodedTableFloat(&lightTable, &lightInfo.brightness);
        ReadEncodedTableFloat(&lightTable, &lightInfo.blendScale);
        lightInfo.generatedFrame = 0;

        if (lightInfo.radiusX > 0 && lightInfo.radiusY > 0) {
            const int width = lightInfo.radiusX * 2 + 1;
            const int height = lightInfo.radiusY * 2 + 1;
            lightInfo.generatedFrame = new AlphaMaskSurface(width, height);
            if (lightInfo.generatedFrame != 0) {
                RectBounds frameRect;
                InitRectBounds(&frameRect, 0, 0, width, height);
                lightInfo.generatedFrame->ApplyRectAlpha(&frameRect, 0, 0);
                int center[2];
                lightInfo.generatedFrame->GetCenterPoint(center);
                const int innerAlpha = static_cast<int>(lightInfo.brightness * 32.0f + 0.5f);
                lightInfo.generatedFrame->FillEllipticGradient(center[1], center[0],
                    lightInfo.innerRadius, lightInfo.radiusX, lightInfo.radiusY,
                    static_cast<unsigned char>(innerAlpha), 0, lightInfo.blendScale, 0);
            }
        }

        LightInfo *slot = &m_lightInfos.m_defaultEntry;
        if (index >= 0 && index < m_lightInfos.m_count)
            slot = &m_lightInfos.m_entries[index];
        *slot = lightInfo;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 7 - UID00017Q authored destructor at position 30:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
LightObjImageLib::~LightObjImageLib()
{
    for (int index = 0; index < m_lightInfos.m_count; ++index) {
        AlphaMaskSurface *frame = m_lightInfos.m_entries[index].generatedFrame;
        if (frame != 0)
            delete frame;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 8 - UID0002IV at position 40:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LightObjImageLib::GetLightBounds(int lightIndex, RectBounds *outBounds)
{
    const LightInfo *lightInfo = &m_lightInfos.m_defaultEntry;
    if (lightIndex >= 0 && lightIndex < m_lightInfos.m_count)
        lightInfo = &m_lightInfos.m_entries[lightIndex];
    if (lightInfo->generatedFrame != 0) {
        InitRectBounds(outBounds, -lightInfo->radiusX, -lightInfo->radiusY,
            lightInfo->radiusX + 1, lightInfo->radiusY + 1);
        return;
    }
    InitRectBounds(outBounds, 0, 0, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 9 - UID0002IW at position 50:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LightObjImageLib::DrawLightMode1(AlphaMaskSurface *targetSurface, int centerX, int centerY, int lightIndex)
{
    const LightInfo *lightInfo = &m_lightInfos.m_defaultEntry;
    if (lightIndex >= 0 && lightIndex < m_lightInfos.m_count)
        lightInfo = &m_lightInfos.m_entries[lightIndex];
    AlphaMaskSurface *sourceFrame = lightInfo->generatedFrame;
    if (sourceFrame == 0)
        return;
    const int width = sourceFrame->width;
    const int height = sourceFrame->height;
    RectBounds sourceRect;
    InitRectBounds(&sourceRect, 0, 0, width, height);
    RectBounds destinationRect;
    InitRectBounds(&destinationRect, centerX - width / 2, centerY - height / 2,
        centerX - width / 2 + width, centerY - height / 2 + height);
    targetSurface->DrawFrameWithBlendMode(&destinationRect, sourceFrame, &sourceRect, 1);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 10 - UID0002IX at position 60:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LightObjImageLib::DrawLightMode2(AlphaMaskSurface *targetSurface, int centerX, int centerY, int lightIndex)
{
    const LightInfo *lightInfo = &m_lightInfos.m_defaultEntry;
    if (lightIndex >= 0 && lightIndex < m_lightInfos.m_count)
        lightInfo = &m_lightInfos.m_entries[lightIndex];
    AlphaMaskSurface *sourceFrame = lightInfo->generatedFrame;
    if (sourceFrame == 0)
        return;
    const int width = sourceFrame->width;
    const int height = sourceFrame->height;
    RectBounds sourceRect;
    InitRectBounds(&sourceRect, 0, 0, width, height);
    RectBounds destinationRect;
    InitRectBounds(&destinationRect, centerX - width / 2, centerY - height / 2,
        centerX - width / 2 + width, centerY - height / 2 + height);
    targetSurface->DrawFrameWithBlendMode(&destinationRect, sourceFrame, &sourceRect, 2);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 11 - UID0001XY exact blank formal:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 12 - UID00031S exact blank formal:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 13 - UID00017Z exact blank formal:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 14 - UID0002IY exact blank formal:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

No-code proof for Destinations 11-14: all observed operations are regenerated by the complete class virtual set, direct Singleton base, member destruction, and compiler ABI. Handwritten blocks would duplicate RTTI/vtable/scalar/EH output.

## Final Recommendation

- Destinations 1-14 are applied exactly and all unrelated history/evidence is preserved.
- UID0000RD is the semantic owner and sole definition, UID0000KP is the source file, and UID000076 owns class/method/type routing.
- UID00017P remains ownerless/non-emitting. Startup, shutdown, ObjectPane, AttachedObjectPane, AttachmentAnchorResolver, AlphaMaskSurface, DATFile, ProtectedArray, and rectangle helpers were reread and remain read-only at same-or-greater detail.
- No research or B002 implementation blocker remains. The exact supervisor-corrected manual coverage rows are retained below as a read-only, no-loss linked handoff/reference; the prior plain-UID handoff is historical and superseded. Lifecycle state remains supervisor/validator-owned rather than asserted as mutable pending/current truth by B002.

## Recommended Target Doc Changes

- Applied target: `by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md`, current SHA256 `7DC37595EB879E2406933950ECF9B164E970B5E9DBB98B210CCEEB2791728173`.
- Current metadata is `92/94`, owner UID0000RD, false, blank emitter/position/formal, Nested 0.
- Current Item Summary and body carry exact zero-initialized physical-storage/non-emitting/19-ref/sole-definition wording, PE mapping, live zero bytes, direct Singleton source cause, one-definition policy, and compiler/source exclusions.
- Historical `0xffffffff` remains only as explicitly superseded analysis-time evidence.

## Recommended Support Doc Changes

- UID0000RD is applied at `92/94`, owner/emitter UID0000KP, position 0, Destination 2, with full 19-ref and one-definition evidence.
- UID000076 is applied at `92/94`, owner/emitter UID0000KP, route marker Destination 3, with complete child order and compiler exclusions.
- UID0000KP is applied at `92/94`; prose only, no by-file reconstruction metadata, with exact module/header route and generated order.
- UID0001UW is applied at `90/92`, position 1, Destination 4; the bounded `tableId` spelling caveat is preserved.
- UID0001UX is applied at `92/94`, position 2, Destination 5; direct bases, exact 0x30 layout, EBO overlap, and extern are present.
- UIDs 0002IU/00017Q/0002IV/0002IW/0002IX are applied under owner/emitter UID000076 at positions 10/30/40/50/60, `92/94`, with Destinations 6-10 byte-equal.
- UID00017Z and UID0002IY are applied as owner UID000076, false, blank emitter/position/formal, `93/96`, with exact compiler proofs.
- UID0001XY and UID00031S are applied as owner UID000076, false, blank emitter/position/formal, `92/95`, with exact RTTI/vtable proofs.
- UID00017P: verify-only current false/ownerless split index; do not attach or emit.
- Startup/shutdown and thirteen render consumer routes: verify-only because current docs already use canonical name and behaviors at same-or-greater detail.

## Score And Metadata Recommendation

| UID | Evidence-time state | Current applied state | Key reason |
| --- | --- | --- | --- |
| 0001PR | 86/90 true/file-owned | 92/94 false/UID0000RD | physical/semantic/one-definition closed |
| 0000RD | 87/89 blank | 92/94 definition pos0 | sole typed source definition closed |
| 000076 | 86/86 blank | 92/94 route marker | complete direct hierarchy/children |
| 0000KP | 87/85 | 92/94 | complete module union |
| 0001UW | 88/92 blank | 90/92 struct pos1 | exact layout; lexical cap retained |
| 0001UX | 87/91 blank | 92/94 class pos2 | exact 0x30/EBO/extern |
| source methods | 88/92 | 92/94 | human source and positions closed |
| 00017Z/0002IY | 86/91,87/92 true | 93/96 false | exact compiler mechanisms |
| 0001XY/00031S | 88/92 true | 92/95 false | complete ABI data classification |

Score-improvement attempts resolved initializer, full xrefs, original class hierarchy, object size, field layout, authored-versus-implicit destructor operations, helper liveness, external linkage, source order, vtable slots, and source-safe C++. Scores stop below final only for unrecoverable lexical spellings, not an implementation blocker.

## Open Questions With Attempted Resolution

- Was `0xffffffff` authored? No. PE mapping proves no raw backing; loader and MCP show zero.
- Is the global static? No. Cross-TU consumers require external visibility.
- Is Singleton direct or inferred? Direct. RTTI and PMD prove it.
- Is +4 a second stored base/member conflict? No. EBO overlaps the empty Singleton base with `ProtectedArray<LightInfo>`.
- Should constructor/destructor assign/clear the global? No. Instruction ordering and direct-base model prove compiler lowering.
- Should destructor free entries explicitly? No. That sequence is the implicit ProtectedArray destructor after authored frame deletion.
- Is UID00017Z a callable API? No. It is constructor-unwind-only base-destructor instantiation.
- Are vtable/scalar pages source-bearing? Their declarations are represented by the class; raw ABI is compiler-only.
- Original spelling of `tableId`, `m_lightInfos`, and the global cannot be symbol-proven. The selected names are descriptive, project-consistent, behavior-safe, and explicitly confidence-capped; no blocker remains.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Evidence-time/pre-callback manual hashes were by-memory `1D95BA3D63840C56DE05AF8BFD9129BEB5F64D4CCAB8E524272F8F6C5AFE1EE1`; by-global `2F5A08437C721BD81F341556B786473CAB1E601388D09F67D4BDC5E22FC6F64B`; by-class `9C74E4C9C0E9BC0160290E8C7EE4A3511825EA0BD847C435713DE93520307E98`; by-file `3D3D4DEB9454144A4EEBAD87809AEFD2EC1935CCB0EA6A76FC6D36E3593C53CC`; by-struct `FE6F956B0F09178851B615A476910CF054AA6DA988A1D8688A8E91DE1F6BD5A0`; by-vtable `905DB13B93D3EBCEBC0BE71F1A2099B777C7655B6222F581C3AC416D6D966F06`.

The earlier final-callback read-only epoch is now historical: by-memory `69DAD2B0004C9BB609E78B3F3A7EDF5191340AAD98F4BCD37ACC8B0E95052767` (1,909,436 bytes / 4,475 lines); by-global `D6646A6C5820AC4A6E047E784F740F8770BDEF4113A15F23B06228A24D8650E4` (94,535 / 214); by-class `3AD9F9AFC1DCFD595F0534CFFCAF36F638F030E108858DCE43C50CBEC6911866` (247,999 / 623); by-file `63872C5A479AF72121008185E4231773DE0940508394EB30C32A857358DA42C5` (145,335 / 316); by-struct `70319E9F56488336A864603802F390A98D8A2FAF4398DFC8175DFACF68ED5EEC` (56,726 / 137); and by-vtable `74AD432F8B9592C0D87C3D7134CB6157532D1C1AB955113A087B2A165965B405` (64,637 / 142). The report's first enriched handoff against that epoch retained factual prose but replaced six durable Markdown UID routes with plain UID text. Supervisor coverage validator command `000000016016` exposed the defect as `reference_index_remove 0001XY`; this is coverage-validation provenance, not an assertion of report execution.

At the final read after supervisor correction, current manual hashes are by-memory `60BBCA2FB98496CBAFCCE13126EAAD3482451D0105469916404B8936822B8E7D` (1,921,168 bytes / 4,487 lines); by-global `0C2533250EAD5038B464B6C104730C21054E36E49D1C8865C30D2BEC976A0732` (95,363 / 214); by-class `F805ACBF02650ED517F0E969D365275AA284A442DCDB569F00919BE3FC0E6AA0` (249,506 / 623); by-file `1F89FD7F25F02035BCB0572B30F8CE6091B36E730335D6D6E42EA3EADB1C62E8` (146,478 / 316); by-struct `676BAA47DB24054110C95507785BD5147C979A99D7A3C444CBAAF77B547ACB8F` (57,412 / 137); and by-vtable `E4E68E13401E2E05867FFD0A4485C53B93DD2C0A8FDF66148960244DD05D5F3A` (65,118 / 142). Exact current anchors are by-memory UID00017P/0002IU/00017Q/0002IV/0002IW/0002IX/0002IY at lines `1822/1823/1824/1826/1827/1828/1829`, UID00017Z at `1849`, UID00031S at `3996`, and UID0001PR at `4388`; by-global UID0000RD at `103`; by-class UID000076 at `282`; by-file UID0000KP at `142`; by-struct UID0001UW/UID0001UX at `64/65`; and by-vtable UID0001XY at `75`. Each occurs once. The block below is the exact supervisor-corrected current row union, including every durable Markdown UID link; B002 read but did not edit any manual file.

For any supervisor-owned reconciliation, preserve surrounding rows and use the exact corrected UID rows below. They are retained as the durable no-loss handoff/reference for independent verification and do not assert report execution:

```text
    - [UID:00017P][0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster](by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md) 0x004df7e0-0x004dfd0a | non-emitting exact split index | LightObjImageLib local method cluster : ignored : 86% : very-strong : The historical row classified a non-contiguous `0x004df7e0-0x004e669d` class-method cluster and correctly preserved live-IDA child boundaries, raw ordinary-destructor non-function status, the constructor cleanup jump to the singleton clear helper, the sole GetLightBounds caller at `0x0053c82b`, vtable/global xrefs, exact `cc` padding, parent attachment, and then-open field/helper names. Its broad end, reconstructable parent attachment, and open-name status are superseded by the source split: this ownerless/non-emitting lower-method index is exactly `[0x004df7e0,0x004dfd0a)`, preserves constructor UID0002IU, raw ordinary destructor UID00017Q, bounds UID0002IV, draw children UID0002IW/UID0002IX, ten/ten/six/six-byte padding, vtable/global anchors, and separate compiler-only UID00017Z/UID0002IY tails without duplicate aggregate source.
        - [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md) 0x004df7e0-0x004dfaa6 | constructor | LightObjImageLib::LightObjImageLib : reconstructable : 92% : very-strong : Loads `LIGHT.TBL`, allocates `0x1c`-byte LightInfo rows, seeds fallback state, and creates radial light frames; live IDA preserves the exact `0x2c6` primary body, sole startup caller at `0x004f6139`, singleton/vtable writes, DAT/frame/memory callees, constructor cleanup chunks, and ten-byte `cc` padding before the raw destructor. Source reconstruction adds the direct `Singleton<LightObjImageLib>` base initializer, complete `ProtectedArray<LightInfo>` initialization/growth/copy/free flow, and procedural radial-frame loop; the observed singleton/vtable publication and unwind-clear chunks are explicitly compiler-lowered EBO/base lifetime mechanics rather than duplicate handwritten assignments.
        - [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md) 0x004dfab0-0x004dfb36 | destructor | LightObjImageLib::~LightObjImageLib : reconstructable : 92% : very-strong : The raw ordinary destructor remains a non-modeled exact `0x86`-byte body with no direct refs to its raw start, a generated-frame deletion loop over `0x1c`-byte LightInfo rows, vtable/global writes, record-buffer free, base tail-call, and ten-byte `cc` padding. Its authored source body is the frame-deletion loop only; `ProtectedArray`, `Singleton`, and `LObject` implicit destruction regenerates the buffer free, singleton clear, vptr restoration, and base teardown, so those binary operations are retained as compiler evidence rather than emitted as handwritten statements.
        - [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md) 0x004dfb40-0x004dfbb0 | method | LightObjImageLib::GetLightBounds : reconstructable : 92% : very-strong : Selects a LightInfo row or the fallback and emits local bounds from its radii when a generated frame exists; live IDA preserves the exact `0x70` body, sole external AttachmentAnchorResolver caller at `0x0053c82b`, no data refs, `0x1c` LightInfo stride, fallback at `this+0x14`, generated-frame gate at row `+0x18`, and rectangle-setter dependency. The accepted class-owned source uses the resolved LightInfo/member names and retains the same selected-versus-fallback and frame-gated rectangle behavior.
        - [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md) 0x004dfbb0-0x004dfc5a | virtual method | LightObjImageLib::DrawLightMode1 : reconstructable : 92% : very-strong : Centers a generated light frame and invokes the shared frame blitter with blend mode 1; live IDA preserves the exact `0xaa` body, vtable-only address cell `0x0061b760`, no direct callers, rectangle-setter/frame-blitter/security-cookie callees, and six-byte `cc` padding before mode 2. The source method retains row selection, null frame gating, centered source/destination bounds, and blend mode 1 while the security cookie remains compiler-only.
        - [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md) 0x004dfc60-0x004dfd0a | virtual method | LightObjImageLib::DrawLightMode2 : reconstructable : 92% : very-strong : Centers a generated light frame and invokes the shared frame blitter with blend mode 2; live IDA preserves the exact `0xaa` body, vtable-only address cell `0x0061b764`, no direct callers, rectangle-setter/frame-blitter/security-cookie callees, and six-byte `cc` padding before `NewHumanImageLib`. The source method retains row selection, null frame gating, centered source/destination bounds, and blend mode 2 while the security cookie remains compiler-only.
    - [UID:00017Z][0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper](by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md) 0x004e5bb0-0x004e5bbb | compiler Singleton base destructor | Singleton<LightObjImageLib> base-destructor instantiation : ignored : 93% : very-strong : The historical row correctly recorded the exact eleven-byte/two-instruction body, `dword_69B450` target at `0x0069b450`, no ordinary callers or callees, constructor cleanup jump at `0x006001d0`, 19 singleton lifecycle/render refs, and five-byte `cc` padding before the adjacent MapTileImageLib helper, but its reconstructable static-cleanup-helper label and open lifetime-mechanism caveat are superseded. The `this+0x04` cleanup route, RTTI PMD/EBO evidence, and matching ordinary/scalar clear sequences identify a compiler-generated `Singleton<LightObjImageLib>` base-destructor instantiation; it remains non-emitting and has no handwritten clear API.
        - [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md) 0x004e65e0-0x004e669d | compiler scalar deleting destructor | LightObjImageLib scalar deleting destructor : ignored : 93% : very-strong : The historical deleting-wrapper row correctly preserved the exact `0xbd` body, vtable-only address cell `0x0061b754`, no direct callers, base/free/delete/guard callees, generated-frame cleanup, singleton clear, delete-flag branch, and three-byte `cc` padding. Its former reconstructable wrapper disposition is superseded: this is compiler ABI source over ordinary UID00017Q plus implicit `ProtectedArray`/`Singleton`/`LObject` teardown, size guard, and optional storage free; UID00017Q remains the sole handwritten destructor source.
        - [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md) 0x0061b750-0x0061b768 | compiler RTTI/vtable data | LightObjImageLib vtable data : ignored : 92% : very-strong : Batch 139 live IDA established the exact `0x0061b750-0x0061b768` RTTI/vtable range, complete-object locator `0x0064900c`, five slot dwords (`0x0061b754 -> 0x004e65e0`, `0x0061b758 -> 0x004f4b10`, `0x0061b75c -> 0x0041b6c0`, `0x0061b760 -> 0x004dfbb0`, and `0x0061b764 -> 0x004dfc60`), target-function boundaries/sizes, and constructor/raw-destructor/scalar-deleting-destructor vptr xrefs; it also preserves the preceding `ProtectedArray<LightInfo>` template-vtable adjacency and `NewHumanImageLib` boundary at `0x0061b768`. The historical reconstructable `88%` row and child assignment to [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md) are superseded by ownerless/non-emitting compiler RTTI/vtable data at `92%`; the complete `LightObjImageLib` declaration regenerates its inherited and draw slots, so formal C++ remains blank.
    - [UID:0001PR][0x0069b450-0x0069b454.g_pLightObjImageLib](by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md) 0x0069b450-0x0069b454 | physical global pointer storage | g_pLightObjImageLib backing slot : ignored : 92% : very-strong : The exact four-byte slot retains 19 live IDA refs, constructor publication/null clear, ordinary/helper/scalar-destructor clears, startup/shutdown use, render consumers, and validator-visible file parent `LightObjImageLib`; the historical manual claim that storage is initialized to `0xffffffff` is explicitly superseded by PE loader-zero evidence. Current classification records five direct Singleton/compiler-lifetime writes and fourteen shutdown/render reads, semantic owner UID0000RD, one typed external definition there, false reconstruction on this physical page, and no duplicate storage-page source.
- [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md) : reconstructable : 92% : very-strong : The historical attachment to [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) and C001/B003 evidence remain valid for the 19 storage xrefs, startup-only construction, raw and scalar destructor clears, shutdown/read consumers, render consumers, exact vtable child, `LIGHT.TBL` ownership, saved IDA storage label `g_pLightObjImageLib`, and saved LightObjImageLib lifecycle/draw names. The former file/class attachment gates (`87/85` and `86/86`), generated `g_pLightObjectImageLib` alias pollution, `0xffffffff` initializer assumption, and remaining Wave3 global-data range omission are retained as historical/superseded states: PE zero-fill and UID0001PR now resolve physical storage, and the source-facing name is `g_pLightObjImageLib`. The terminal source delta is the sole externally linked zero-initialized `LightObjImageLib *g_pLightObjImageLib` definition at position 0 in `NexusTK/render/LightObjImageLib.cpp`, paired with one header `extern` after the complete class and no duplicate physical-page definition.
- [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md) : reconstructable : 92% : very-strong : The prior class row correctly inventoried the IDA-confirmed constructor, ordinary destructor, bounds helper, two draw modes, singleton clear helper, deleting destructor, singleton/vtable anchors, and LightInfo layout; its `84%` score and statement that final field/helper names remained provisional are historical and superseded by the accepted typed source. The class now records direct `LObject` plus `Singleton<LightObjImageLib>` inheritance, `0x30` EBO layout, `ProtectedArray<LightInfo>` member, constructor/destructor/GetLightBounds/DrawLightMode1/DrawLightMode2 order, external singleton declaration, and explicit exclusion of the Singleton clear, scalar wrapper, RTTI, and vtable compiler artifacts under the one-definition policy.
- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) : reconstructable : 92% : very-strong : The existing `NexusTK/render/LightObjImageLib.cpp` module facts remain: `LIGHT.TBL` inputs, `0x1c` row handling, procedural radial-frame generation, constructor/bounds/two draw/destructor bodies, layout/record/vtable anchors, exact vtable child [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md), singleton storage, and documented source-name caveats. Its former `87%` score and unresolved caveats are historical/superseded by the accepted source names and route. The terminal file contract adds source order `g_pLightObjImageLib` position 0, `LightInfo` position 1, complete `LightObjImageLib` declaration position 2, five authored methods, the 19-reference lifetime/consumer graph, and compiler-only Singleton-clear/scalar/vtable/RTTI exclusions, with no by-file reconstruction metadata or second global definition.
- [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md) : reconstructable : 90% : very-strong : The LightObjImageLib-owned `0x1c` `LIGHT.TBL` row and B003 2026-06-17 reanalysis remain authoritative: fields are `tableId`, `innerRadius`, `radiusX`, `radiusY`, `brightness`, `blendScale`, and `generatedFrame`; historical `lightSource`/`blendValue` aliases are explicitly rejected; `FillEllipticGradient` dataflow proves `innerRadius` and `blendScale`; and the owner route remains [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md). The terminal source delta emits this struct at position 1 and preserves constructor/bounds/draw/destructor and metric dataflow; only the original spelling of the first field remains confidence-capped.
- [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md) : reconstructable : 92% : very-strong : C001/B003 layout evidence remains valid for the `LightObjImageLib` object, `ProtectedArray<LightInfo>` header at `+0x04`, `lightInfoCapacity` at `+0x10`, fallback record at `+0x14` seeded with four `-1` integers plus zero float/pointer fields, `28 * count` allocation, generated-frame pointer at row `+0x18`, constructor/bounds/draw/destructor agreement, and owner route through [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md). Those offset labels are retained as binary layout/dataflow evidence; any interpretation of the fallback/capacity as separately authored top-level members is superseded by the source declaration's `ProtectedArray<LightInfo> m_lightInfos` member. The terminal declaration adds direct `LObject` plus `Singleton<LightObjImageLib>` bases, Singleton PMD `+0x04` EBO overlap, exact `0x30` size, public five-method virtual set, position 2, and one external singleton declaration.
- [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md) : ignored : 92% : very-strong : The historical assignment/gate provenance remains explicit: exact child [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md) was attached after child `88/92`, direct class parent [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md) reached `86/86`, and source file [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) reached `87/85` and cleared the corrected gate; the 2026-06-11 live IDA recheck recorded five slots, xrefs, target boundaries, plus adjacent `ProtectedArray<LightInfo>` and `NewHumanImageLib` boundaries. Its former reconstructable `88%` disposition is superseded by source-declared/generated-binary RTTI/vtable support: direct `LightObjImageLib`/`LObject`/`Singleton` hierarchy, scalar slot `0x0061b754`, inherited slots `0x0061b758/0x0061b75c`, draw slots `0x0061b760/0x0061b764`, constructor/ordinary/scalar vptr xrefs, and blank non-emitting formal C++ regenerated by the complete class declaration.
```

No tracker text is proposed: tracker is validator-generated. Reason B002 must not apply manual rows: all `-coverage-report.md` files are supervisor-owned.

## Follow-Up Actions

- B002 work is complete: accepted ordinary edits, scoped validation, parity correction, waited generated verification, manual-row readback, report reconciliation, and lease release are finished.
- The exact supervisor-corrected 16-row union remains available above as the durable linked handoff/reference. B002 did not edit manual coverage; the earlier plain-UID handoff and command-`16016` `reference_index_remove 0001XY` discovery are historical repair provenance only.
- Independent report review, manual coverage validation, execution, movement, archive state, and any future lifecycle action are supervisor/validator-owned. The exact current report path and validator-owned history are authoritative; this wording does not assert a mutable pending or completed lifecycle state.
- A-agent: none.

## Confidence

- Recommendation confidence: 94/100.
- Score confidence: 93/100.
- Remaining uncertainty: original lexical names only. No source behavior, type, ownership, placement, or emission blocker remains.

## Validator Results

- All commands ran from canonical `source-3/project-documentation`; every command returned exit `0`, `ok: 1`, and deferred generated refresh unless otherwise stated.
- `000000015960` (`2026-07-21T15:32:23-04:00`) validated UID0001PR; `000000015961` (`15:32:46`) validated UID0000RD; `000000015962` (`15:35:30`) validated UID000076; `000000015963` (`15:36:33`) validated UID0001UW; `000000015964` (`15:37:16`) validated UID0001UX.
- `000000015965` (`15:38:15`) validated UID0002IU; `000000015966` (`15:39:10`) UID00017Q; `000000015967` (`15:40:09`) UID0002IV; `000000015968` (`15:40:54`) UID0002IW; `000000015969` (`15:41:43`) UID0002IX.
- `000000015970` (`15:42:18`) validated UID0001XY; `000000015973` (`15:42:54`) UID00031S; `000000015974` (`15:43:43`) UID00017Z; `000000015975` (`15:44:38`) UID0002IY; `000000015976` (`15:45:46`) UID0000KP.
- Initial waited readback command `000000015977` (`15:46:03`) returned exit `0`, `ok: 1`, and completed generated refresh. A strict report/destination comparison then found three formatting-only mismatches, so UID0002IU/UID0002IW/UID0002IX were corrected and revalidated by `000000015978` (`15:48:22`), `000000015979` (`15:48:43`), and `000000015980` (`15:49:16`), each exit `0`, `ok: 1`.
- Final authorized waited command `000000015981` (`2026-07-21T15:49:27-04:00`) was `python .\tools\validator.py --mode file --file by-file/LightObjImageLib.md --apply --queue-timeout 240 --wait-generated`; exit `0`, `ok: 1`, `generated_refresh: completed`, same command/timestamp in the target generated header.
- Target-specific warnings: UID000076 and UID0000KP validation each reported two pre-existing `missing_ref_uid 0003LZ` entries; they are unrelated stale ItemObjImageLib references already preserved in those pages and did not affect Light source generation. Final waited validation repeated those two warnings. No destination-specific missing reference, owner, emitter, formal, or generated error remained.
- Final waited side effects were validator-owned: registry rebuild `5,224` metadata nodes / `4,144` edges, generated metadata refresh on `280` files, projected stats refresh, and broad pre-existing `autogen_children_marker_missing`, `autogen_children_fallback_insert`, and `autogen_emitter_has_no_code` diagnostics outside this target. B002 did not edit validator state, generated files, tracker, or projected stats manually.
- Generated proof: target-specific waited command `15981`, SHA256 `DD22E999E9F1BEDA56BD8FFD0FEFD454B89717889704B7E4E31415E54CAA0AAC`, was followed by unrelated external header refresh command `15993`, current SHA256 `E7102C778C81D7911E31A88A6B76AD9933FBC1FF954D138C70073683F791BBC7`, semantic body SHA256 `7CF4452F2C28422EADD1A7BD36DAD138B33E6473526309CF9F6678D31E119BD2`, 7,557 bytes / 176 lines. Final counts remain global definition `1`, extern `1`, `LightInfo` `1`, complete class `1`, constructor/destructor/bounds/mode1/mode2 `1` each in order; Empty Emitter Markers `0`; UIDs 0001PR/00017Z/0002IY/0001XY/00031S `0`; manual publication/clear `0`; handwritten vtable/RTTI/scalar ABI `0`; decompiler residue `0`.
- Fourteen-formal proof: all fourteen report managed blocks were found, all fourteen destination blocks were found, and all fourteen compared byte-for-byte after line-ending normalization.

## Changed Files

- Modified ordinary destination: `by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md` - SHA256 `7DC37595EB879E2406933950ECF9B164E970B5E9DBB98B210CCEEB2791728173` (14,711 bytes / 122 lines).
- Modified ordinary destination: `by-global/g_pLightObjImageLib.md` - `DB2C7A3E2329F65E1BA8A432A1AD052F141272761A56BDEE14D7DFCE2D02AEB4` (15,773 / 140).
- Modified ordinary destination: `by-class/LightObjImageLib.md` - `016499C455D6B0CF063BC063459AB68EB612F589D4A6AF4BC7B02DFD4A3F0C15` (19,531 / 164).
- Modified ordinary destination: `by-type/by-struct/LightInfo.md` - `F3A365AF39DFDD77A8F615AB811A76FDBFFD656C7CBFAA9090F4BB4F7A45E081` (10,928 / 108).
- Modified ordinary destination: `by-type/by-struct/LightObjImageLibLayout.md` - `B13E2E55E729BB7F734EA6E5899B8C2A95E2937EE80D829F564759C910E4D2C4` (12,073 / 111).
- Modified ordinary destination: `by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md` - `A19440538CE190569977B9477EADCF87C7277ACD81C9393A20ED95F4783BB461` (14,659 / 170).
- Modified ordinary destination: `by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md` - `7D5BD0107ABE7DB7861D84249378DAAC7AEC33CC714E2342A598C256AA6B18E5` (9,938 / 97).
- Modified ordinary destination: `by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md` - `8B12FD66BB93A54AAE4385C64155E489E5F665AD62BF9094CEF2E695DC5B8C78` (9,169 / 104).
- Modified ordinary destination: `by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md` - `FB58604CDCD9AE0DA2289E1B0601E5190D989C71AAB2B1342CA158FC5A035296` (9,580 / 108).
- Modified ordinary destination: `by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md` - `E01326EDCEB993BA1945849C921C09B563C0A9385CE082ADA00003274544D931` (9,781 / 108).
- Modified ordinary destination: `by-type/by-vtable/LightObjImageLibVtable.md` - `EF13EDD3D15085CB913751AE24A458B81D0D28D4C88EA29E22118074324207C3` (10,845 / 117).
- Modified ordinary destination: `by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md` - `BA361B168DB953294D0CA782295D3C44AB88718A1F516008439064218327B1C9` (8,950 / 95).
- Modified ordinary destination: `by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md` - `B7B39E030236EF41B1BB67F9839814406BF7DB2F1D5FDDA96FC627A11DE78783` (15,618 / 110).
- Modified ordinary destination: `by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md` - `48D86662EDD329B13B058ED7A050AABD7A22BA991898236DA2943735D913FA1F` (8,779 / 90).
- Modified ordinary support: `by-file/LightObjImageLib.md` - `40D4BEC7E23869268F3646ABE6928A309D360141D11817482B0032D1B349DD5E` (22,022 / 137), prose-only with no reconstruction metadata.
- Modified report: `tools/leaser/Agents/Agent-B002/research/0001PR-g_pLightObjImageLib-source-quality.md`. Final self-hash/metrics are reported externally because embedding them would change the artifact.
- Preserved read-only proof: UID00017P `CF15979F426A1B5E4154FC7B8DA10C9E521EAB96D6A536ACBDADE734CC457F76`; ApplicationStartup `07713A29D28133500BD16D51763715E5E0CAE30F610C8150281A514CDB9A945D`; ApplicationShutdown `DF47B7F3528DAF49A10718A0BECB123BB0394C043A6773726B2FA2BCB2EB62F0`; ObjectPane aggregate `1EE9B42DD503E4E599D73AB34C70B1A62DA0C7B6D39C284BCAC4E70A1DF17A1D`; AttachedObjectPane aggregate `8DBCE9885BDDEF76AB9EA731EAE40C0EFDD3D9C942DC0F1E212AB01E53315704`; AttachmentAnchorResolver `F40D978FAE5A1E1F762F10EAE53274A1457C434ADF39087E7C33F0F5569ED47E`; AlphaMaskSurface file `C0B47374D45313D05F5C3269F4484AF6DFC6FB6B7A840B8A98541409287A7BAE`; DATFile `50159ABA978A6AAC0B194B842619EDAA6D99B0077647F81524D3AE1D0712393E`; ProtectedArray `DDA968461FF9C424F07EEA209C6CB18DE5C9AA996C885971F61CFA5BD8EAAC83`; RectBounds file/class/layout `0BCD3DDB41C7991D24511BE87F6A81FFF9092E4C5BC741431D1491042BF42829` / `710057507F3BCBAC7528CFC299AC57C6652068EBB24F1CEF06D60C513BAF370E` / `3FC01A6E920DDECDB8A2223D34244A535BF0DAF1AE838A9B36F3A42AAEEEAC33`.
- Renamed/created ordinary files: none. Manual coverage files: read only. Generated/tracker/stats/validator files: validator-owned side effects only, never manually edited by B002.
- Historical supervisor lifecycle: command `000000016065` executed the report, and command `000000016070` invalidated that execution and returned the report solely for stale lifecycle-text repair. These historical facts come from the unchanged validator-owned history footer; they are not assertions about mutable path, executed/non-executed status, archive state, or future lifecycle outcome.
- B002-authored lifecycle checkpoint: B002 ran no `execute_report`, report probe, count, move, archive, or lifecycle command. Implementation is complete and ready for supervisor execution at this checkpoint. The exact artifact location and unchanged validator-owned history footer are the sole current lifecycle authority before and after any supervisor-owned action.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation; Gate 1 passed exact pre-callback SHA `0EFF30A1655D68235A1154772C179361507AF7432E71D47D327AFDEB4600E3F1`.
- [x] Target UID0001PR metadata, zero-fill, semantic owner, false/non-emitting state, Item Summary, and full 19-ref inventory applied.
- [x] UID0000RD sole definition, position 0, external linkage, source definition, and one-definition evidence applied.
- [x] UID000076 class route marker and complete child order applied.
- [x] UID0000KP file score/module/header/source-order/compiler-exclusion prose applied without by-file reconstruction metadata.
- [x] UID0001UW exact 0x1c struct and position 1 applied.
- [x] UID0001UX complete class, direct bases, EBO layout, extern, and position 2 applied.
- [x] UID0002IU owner/position/score and exact Singleton-initializer constructor applied.
- [x] UID00017Q owner/position/score and exact authored-only destructor applied.
- [x] UID0002IV owner/position/score and exact member-qualified body applied.
- [x] UID0002IW owner/position/score and exact member-qualified body applied.
- [x] UID0002IX owner/position/score and exact member-qualified body applied.
- [x] UID00017Z false/non-emitting compiler base-destructor proof applied.
- [x] UID0002IY false/non-emitting scalar-wrapper proof applied.
- [x] UID0001XY false/non-emitting source-declared/generated ABI proof applied.
- [x] UID00031S false/non-emitting concrete RTTI/vtable proof applied.
- [x] UID00017P verified unchanged as ownerless/non-emitting exact split index.
- [x] ApplicationStartup exact 0x30 allocation/sole call verified unchanged.
- [x] ApplicationShutdown canonical deletion/order verified unchanged.
- [x] ObjectPane three-reference brightness behavior verified unchanged.
- [x] AttachedObjectPane six-reference one/two-row behavior verified unchanged.
- [x] AttachmentAnchorResolver metric/bounds/mode1/mode2 consumers verified unchanged.
- [x] AlphaMaskSurface, DATFile, ProtectedArray, RectBounds, and encoded-reader dependencies verified at same-or-greater detail.
- [x] Historical `0xffffffff`, longer alias, manual publication/clear, and helper-API assumptions preserved as superseded history.
- [x] Every C01-C40 accepted claim terminalized with legal verification states and destination proof.
- [x] All fourteen managed formal blocks installed/verified byte-for-byte.
- [x] No duplicate global, class declaration, method body, helper body, scalar wrapper, or ABI table introduced.
- [x] Current target/support hashes reread immediately before each callback edit.
- [x] One just-in-time lease held per ordinary edit, scoped validator run, and lease released immediately.
- [x] Final waited generated refresh run lease-free as command `000000015981`.
- [x] Generated output contains exactly one global definition, one complete class, one constructor/destructor/bounds/mode1/mode2 in order.
- [x] Generated constructor has Singleton initializer and zero explicit singleton publication.
- [x] Generated destructor has frame deletion and zero explicit buffer free/global clear/base/vptr/scalar mechanics.
- [x] Generated output has no UID0001PR/UID00017Z/UID0002IY/UID0001XY/UID00031S Empty Emitter Marker.
- [x] Generated output has no handwritten RTTI/vtable/scalar/EH ABI source.
- [x] All 16 supervisor-corrected manual rows reread and reproduced fact/link byte-for-byte in the no-loss handoff; all required durable Markdown UID links across the six affected rows are restored, retained facts and superseded assumptions remain explicit, and B002 made no manual edit.
- [x] Tracker/generated headers and hashes time-scoped through final report-read commands `15994`/`15993`, while target-specific waited command `15981` remains historical semantic proof.
- [x] Validator command IDs/timestamps/exit/ok/warnings/side effects recorded.
- [x] Changed ordinary paths and final SHA256 values recorded.
- [x] All leases released and canonical lease ledger confirms zero B002 leases.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation at the exact Gate-1-passed SHA.
- [x] C01-C40 implemented without compression or evidence loss.
- [x] Destination 1 exact blank physical-storage formal verified.
- [x] Destination 2 sole definition verified.
- [x] Destination 3 class route/CHILDREN marker verified.
- [x] Destination 4 LightInfo struct verified.
- [x] Destination 5 complete class/extern verified.
- [x] Destinations 6-10 exact source method bodies verified.
- [x] Destinations 11-14 exact blank compiler/data formals verified.
- [x] All accepted support prose and scores applied or excluded with concrete same-or-greater proof.
- [x] Historical and negative evidence preserved.
- [x] Open questions closed exactly as accepted.
- [x] Scoped validators all exit 0/ok 1; warnings and side effects recorded.
- [x] Final waited generated assertions independently read back.
- [x] Manual coverage remains unedited by B002; final-read parity is 16/16 against the supervisor-corrected rows, including all required restored Markdown UID links across six affected rows, and command `000000016016` is recorded only as the validator discovery that invalidated the prior lossy handoff.
- [x] No generated/tracker/audit/supervisor/validator-state/IDA/lifecycle file manually edited.
- [x] No `execute_report`, probe, move, archive, or lifecycle command run.
- [x] Report current state, ledger, validators, changed files, hashes, and checklist reconciled.
- [x] Historical supervisor execution attempt `000000016065` and invalidation/return command `000000016070` are recorded without asserting current execution; exactly one implementation-complete `READY_FOR_SUPERVISOR_EXECUTE` marker appears before the unchanged validator-owned history footer.
- [x] Zero leases confirmed before return.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000016065","destination_path":"executed-b-agent-research/B002/0001PR-g_pLightObjImageLib-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0001PR-g_pLightObjImageLib-source-quality.md","timestamp":"2026-07-21T17:01:28-04:00","uid":"0001PR"} -->
<!-- {"agent":"B002","command_id":"000000016070","destination_path":"tools/leaser/Agents/Agent-B002/research/0001PR-g_pLightObjImageLib-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B002/0001PR-g_pLightObjImageLib-source-quality.md","timestamp":"2026-07-21T17:02:36-04:00","uid":"0001PR"} -->
<!-- {"agent":"B002","command_id":"000000016104","destination_path":"executed-b-agent-research/B002/0001PR-g_pLightObjImageLib-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0001PR-g_pLightObjImageLib-source-quality.md","timestamp":"2026-07-21T17:23:25-04:00","uid":"0001PR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
