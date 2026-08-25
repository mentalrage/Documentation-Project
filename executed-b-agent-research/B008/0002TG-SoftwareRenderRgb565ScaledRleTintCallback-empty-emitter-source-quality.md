# UID0002TG SoftwareRenderRgb565ScaledRleTintCallback Empty-Emitter Source-Quality Report
** TARGET-REPORT-UID:0002TG **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


Removed operational material is preserved only in [0002TG-SoftwareRenderRgb565ScaledRleTintCallback-empty-emitter-source-quality-removed.md](0002TG-SoftwareRenderRgb565ScaledRleTintCallback-empty-emitter-source-quality-removed.md). That companion is non-authoritative, must never be executed or replayed, and grants no Gate, IDA, validator, score, or lifecycle credit.

## Finalized Report / Current Recommendation

- Implemented and verified: [UID:0002TG] moved from `87/90` to `92/94`, retained `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, and blank `EMITTER_POSITION_OPTIONAL`, and now contains the complete file-local RGB565 formal CPP from Section 22. Its H block remains blank because the provider is private to `Surface.cpp`.
- The accepted source-facing function is `SoftwareRenderRgb565ScaledRleTintCallback`. It is the RGB565 provider for callback slot 4, not a `RankingEventListPane` method and not a `GrafPort` member.
- The exact source ABI is logical `void __thiscall` with a `GrafPort *` receiver followed by `const EPFTileContext *sourceContext`, `const RectBounds *sourceBounds`, `const RectBounds *destinationBounds`, `unsigned char mode`, `float tintAmount`, `int rowOffset`, `float verticalScale`, and `float horizontalShear`.
- The body clips destination writes, parses signed zero-delimited mask rows, transforms existing RGB565 destination pixels only in negative foreground runs through the 5-bit and 6-bit tint tables, and advances source rows with rounded float scale accumulation. It does not read source pixel colors.
- Preserve exact binary behavior that looks unusual in source: the initial destination pointer subtracts the GrafPort surface bounds origin, later row pointers do not; mode is tested only after initial setup; no encoded-stream byte-count check exists; and no new guard for nonpositive vertical scale may be added.
- Update semantic callback-table UID0000TN with the missing `SurfaceScaledRleTintProc` typedef, `g_pfnBlitScaledRleTint` extern, and one `Surface.cpp` definition. Update the target, callback-table, initializer, physical-table, RGB565-family, Surface-file, compat-peer, GrafPort-support, EPFTileContext-support, and caller prose at the exact detail assigned in the claim ledger.
- Supervisor Gate 1 accepted the historical pre-callback report SHA256 `AD8BC6397B51E959A081D0CDF30D44CA04C55A4D94734A114346FF91A7960DDF`; that decision authorized the recorded callback but does not validate this later repaired artifact. Current report credit comprises C2TG-001 through C2TG-050 and C2TG-060 through C2TG-085 except C2TG-051 through C2TG-059: 52 `applied` and 24 `already-present` states. The only nine `proposed` and unchecked claims are the supervisor-owned IDA rows C2TG-051 through C2TG-059.
- The Gate 2A repair callback removed unrelated slot-7 evidence from GrafPort's UID0002TG section, corrected the sole conflicting retained compat assignment from unsupported `0x00558739` to evidence-backed `0x0055873b`, reconciled physical UID0001PI to `92/94`, and reported commands `21893-21902`. Those nine commands other than Surface command `21994` are now historical unretained callback assertions and receive no current proof credit. Independent Gate 2A found Surface omitted the two RGB565 assignment addresses required by C2TG-030; the same callback repaired Surface with exact `0x00558829`/`0x00558ec4` detail and retained command `21994`, which supersedes `21899` and remains the dated C2TG-065 proof.
- At the callback boundary B008 edited only the ten authorized by-* destinations and this report, reported ten scoped validators with `--no-generated-refresh`, and made no manual coverage, generated/tracker, IDA, goal/notes, audit/catalog, execute-report, movement, archive, or lifecycle edit. Those original receipts remain historical where identified. The retained ordinary scoped validations are commands `000000022926` through `000000022934`; the retained manual-coverage validation receipts are commands `000000023009`, `000000023010`, `000000023044`, and `000000023043`. All thirteen commands passed with generated refresh skipped. A later report-time physical reread reconfirmed every affected ordinary destination and all nine manual rows; unrelated by-memory coverage-file drift is recorded without mislabeling command `23009` as a validator receipt for the later whole-file hash. Commands `22921` through `22924`, `23011`, and `23012` are retained only as older historical manual-coverage receipts.

## Supporting Research

The target is the 657-byte function at `0x004c3a50-0x004c3ce1`. Dated read-only persisted-copy evidence from the 2026-08-10 research recheck establishes two initializer target references, no direct code caller, and twenty-one references to slot `0x0069b3f0`; fresh Gate 2B prestate must independently reproduce those literals before any action. The slot is selected between compat/RGB555 provider `0x004bdcc0` and this RGB565 provider by the Surface callback initializer. Both exact consumers recovered at Riding and Monster render call sites use mode `3` and pass an EPF tile context, source and destination rectangles, a MapPane day/night tint amount, an integer row offset, a vertical projection scale, and a horizontal shear.

The callback reads the accepted `EPFTileContext` mask-stream field at `+0x24`, not source pixel colors. Every row is a signed byte stream terminated by zero. A negative token identifies a destination-transform span; a positive token advances over transparent/background pixels; `token & 0x7f` is the run length. The RGB565 body decomposes each existing destination pixel into 5-bit red, 6-bit green, and 5-bit blue indices, applies `g_surfaceColorLookup5Bit`/`g_surfaceColorLookup6Bit` at the rounded tint-strength column, and reassembles the pixel.

The original target page accumulated useful binary facts but stopped at unresolved signature/layout/name blockers. The report's caller, type, sibling, initializer, and direct-body evidence resolves those blockers. Its generated caller-biased `RankingEventListPane::DrawScaledRLESpriteTinted_565` projection is historical and rejected. Surface owns the function because Surface owns the callback storage, initializer, both pixel-format providers, and sibling software-render families.

Source-quality details that must not be summarized away during callback implementation include the exact projection formulas, clip conditions, row-run semantics, lookup-channel masks, initial/later pointer asymmetry, two target refs, all twenty-one slot refs, predecessor switch table, successor padding, rejected owner names, constant-pool no-rename decision, and formal callback-table support declarations.

Dated generated command `000000023051` at `2026-08-13T02:45:23-04:00` produced `Surface.cpp` SHA256 `0F841087EDC5F3C9C5F690C6E64CA79151A0802DC15440B32C9082DA1546E9D7` and `Surface.h` SHA256 `C4D3C906473339F827C6503D1718FE582C1C43A4358E5CD7C5D24E2F9BC2C9E9`; later command `000000023099` produced `Surface.cpp` SHA256 `2C44CD856A2D4D883A822210D07CE58DF5C4E3617C1435A2ADB61468F72D1DF6` and `Surface.h` SHA256 `A1AA3DA961ABE4F4A43D3D7A950753C9DA11B83CA2B61081860CCC51504932EE`. Those exact identities are retained as valid superseded generated history. The final read-only report-freeze snapshot described below found the same required source semantics under command `000000023100`.

## Target

- Target UID: `0002TG`.
- Additional target UIDs: `none`.
- Declared-target inventory: UID0002TG is the sole report target and is the file-local Surface RGB565 scaled-RLE-tint callback. UIDs 0000TN, 0001PI, 00039V, 00016L, 0000OC, 0002TC, 00005V, 0000J4, 00004I, and 0002Y1 are support scope only and are not additional report targets.
- Primary target: `[UID:0002TG] by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md`.
- Target path: `by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md`.
- Physical range: `[0x004c3a50,0x004c3ce1)`, size `0x291` / 657 bytes.
- Entity: file-local Surface software-render callback, RGB565 provider for slot 4.
- Current route: `CANONICAL_OWNER:0000OC`, `EMITTER_UIDS:0000OC`, generated root `NexusTK/render/Surface.cpp`.
- Report coverage declaration: UID0002TG only. Support pages are implementation destinations but are not declared as additional covered UIDs.
- Source queue/report snapshot: the dated 2026-08-11 report-time read of `auto-generated/-ag-research-tracker.md` -> `## by-memory` found UID0002TG at row 3606 with `92/94`, mean `93.0`, reconstructable `true`, zero error/empty-emitter counters, and target path `by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md`. This row number and snapshot are provenance only, never current queue or lifecycle authority; the supervisor must dynamically reread the tracker at each relevant gate and again after any report execution/move before making a current-state claim.
- Final read-only report-freeze snapshot on 2026-08-13 found UID0002TG at row 3055 of `auto-generated/-ag-research-tracker.md`, validator command `000000023101` at `2026-08-13T07:11:17-04:00`, SHA256 `CB7917DF1FD82B736C493CC561D7476CE6CDC4102D115568CAC2678971C4207A`, 1,723,234 bytes, 6,780 LF lines, still at `92/94`, mean `93.0`, reconstructable `true`, with zero error/empty-emitter counters. Commands `000000022874`, `000000022990`, `000000023008`, `000000023045`, `000000023072`, and `000000023099` and their associated tracker identities are retained only as dated prior snapshots. Command `000000023101` is itself a dated snapshot, not permanent queue or lifecycle authority; every later gate and post-move decision must reread the then-current tracker.
- Work classification at this report freeze: same-report bounded B008 Gate 2B session-binding repair after the dated operational hold described in Sections 9 and 21. Ordinary documentation, nine manual-row no-change dispositions, dated generated readback, retained Surface validation, nine ordinary scoped validators, and four retained read-only coverage-page validators retain checked report credit. Only IDA, fresh exact-artifact review, and report lifecycle authority remain supervisor-owned without this report asserting an execution or archive state.
- Current scores and parent state: target UID0002TG is `92/94`, owned/emitted by UID0000OC with `RECONSTRUCTABLE:TRUE` and blank position. Its inventory parent UID00016L is `90/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal CPP/H, and remains a non-emitting audit container for exact child pages.
- Report artifact authority: the report's actual physical path at read time together with validator-owned status/history metadata. This prose does not hard-code an active, executed, moved, or archived lifecycle location.

## Current Target State

- Current target metadata is now `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, and blank position.
- The target formal CPP contains the accepted complete file-local RGB565 body. Its formal H remains blank because shared declaration ownership belongs to UID0000TN.
- The target and nine edited support pages now contain the full source contract, exact behavior, historical reconciliation, support ownership, and source-placement detail accepted at Gate 1. Riding UID0002Y1 was physically reread and already contained same-or-greater consumer evidence, so it remained unchanged.
- Semantic UID0000TN now contains the exact `SurfaceScaledRleTintProc` typedef, `g_pfnBlitScaledRleTint` extern, and one definition. UID00039V's already-correct formal assignments were preserved while its slot-4 inventory was expanded.
- Validator command `000000022403` is the dated originating generation receipt for the accepted formal source. Commands `000000022761`, `000000022770`, `000000022920`, `000000022981`, `000000023008`, `000000023042`, `000000023051`, and `000000023099` are superseded historical refreshes. The final read-only report-freeze generated snapshot is command `000000023100` at `2026-08-13T07:10:45-04:00`; physical reread reconfirmed the required Surface.cpp/Surface.h cardinalities with no UID0002TG source loss. All nine manual coverage rows remain present at same-or-greater detail. Commands `000000023009`, `000000023010`, `000000023044`, and `000000023043` are retained successful validation receipts; later physical by-memory coverage identities are recorded separately because unrelated drift advanced that file after command `23009`. Commands `22921` through `22924`, `23011`, and `23012` are older history. Retained ordinary scoped commands `000000022926` through `000000022934` also passed. Only IDA, fresh exact-artifact review, and lifecycle closure remain separately supervisor-owned.
- Current artifact/lifecycle authority: the report's actual physical path at read time plus validator-owned status/history metadata. This prose claims neither execution nor archive completion and remains true if the supervisor later changes lifecycle state.

## Executive Recommendation

Retain and verify the already-implemented UID0002TG target body and UID0000TN slot typedef/extern/definition closure. The accepted callback applied C2TG-001 through C2TG-044; B008 must not reimplement those changes. C2TG-065 remains the retained Surface scoped-validation receipt. Commands `000000022926` through `000000022934` close the other nine ordinary validation rows, retained commands `000000023009`, `000000023010`, `000000023044`, and `000000023043` plus dated physical row rereads support the four coverage-page validation rows, and final report-freeze generated command `000000023100` plus physical readback closes C2TG-073 through C2TG-081 while preserving `000000022403` as originating history and `000000022761`/`000000022770`/`000000022920`/`000000022981`/`000000023008`/`000000023042`/`000000023051`/`000000023099` as superseded refresh history. Commands `22921` through `22924`, `23011`, and `23012` remain older historical manual-coverage receipts. EPFTileContext, RectBounds, GrafPort, MapPane fields, two direct consumers, the paired provider, initializer, and target data flow establish the coherent source contract. Remaining work is the separately allocated fresh exact-artifact review, IDA C2TG-051 through C2TG-059, and lifecycle closure.

Do not move the body into `GrafPort.cpp`, Riding, Monster, or RankingEventListPane. Do not emit code at the RGB565 aggregate or physical callback-table page. Do not rename pooled float constants. Do not add stream bounds checks, vertical-scale validation, source-bounds offset skipping, or a normalized row-pointer formula. Those changes would make the source look cleaner but would stop it from reproducing the original executable.

## Supervisor Active Recheck

- Current Gate 2A requirement: physically reread the implemented target/support destinations and verify C2TG-001 through C2TG-044 against their recorded post-validator hashes, formal CPP/H blocks, metadata, historical reconciliation, and no-edit Riding support claim. Preserve any later accepted work additively; do not replay the callback from its pre-implementation baseline.
- Gate 2A now distinguishes 76 current-credit rows (52 `applied`, 24 `already-present`) from the nine still-`proposed` supervisor IDA rows C2TG-051 through C2TG-059 and rejects any stale pre-callback or historical-receipt current-state assertion.
- Gate 2B authority is supervisor-owned and external to this report. C2TG-051 through C2TG-059 are valid only when the supervisor verifies the current canonical IDB and every literal action/protection prestate; the named sessions remain dated read-only research provenance only and do not establish current authority.
- Manual coverage edits remain supervisor-owned; commands `000000023009`, `000000023010`, `000000023044`, and `000000023043` are retained successful validation receipts, while dated physical rereads prove all nine rows remained at same-or-greater accepted detail across later unrelated by-memory whole-file drift. Commands `22921` through `22924`, `23011`, and `23012` are older history. Generated output remains validator-owned; command `000000022403` is originating history, commands `000000022761`, `000000022770`, `000000022920`, `000000022981`, `000000023008`, `000000023042`, `000000023051`, and `000000023099` are superseded history, and command `000000023100` at `2026-08-13T07:10:45-04:00` is the final report-freeze physically reread output snapshot, but no exact command may be assumed permanently current at a later gate.
- The report must fail closed if the target bytes/range/xrefs, slot ref set, frame layout, protected neighbors, current type prestate, or action schemas differ from the literals in Section 21.
- No report execution/archive action is requested from B008. Current lifecycle truth remains authoritative only from the report path and validator-owned status/history metadata.

## Inference Research Guidance Check

- Wave2/Wave3 material was ignored. The report used the then-current by-* docs, generated-state snapshots, matching report searches, dated live read-only IDA MCP queries, and source-family comparison; only a fresh gate reread may assert current physical state.
- Unknown original symbols were not treated as permission to preserve `sub_`, `dword_`, or caller-biased names in final C++.
- Binary behavior outranks stylistic cleanup. Human-looking names and const qualifiers are inferred only where they do not alter ABI or writes.
- Project style was followed: `SoftwareRenderRgb565...Callback` provider names, `Surface...Proc` callback typedefs, `g_pfn...` callback globals, `m_surfaceContext`, `rowStridePixels`, `m_drawEnabled`, and `RectBounds`.
- Historical assumptions remain documented where useful but are labeled rejected or superseded rather than silently deleted.
- Score blockers were actively researched. No unresolved item in this report is merely deferred as "needs investigation."

## Heuristic / Inference Reanalysis And Validation

| Question | Evidence chain | Best-supported resolution | Rejected alternatives |
| --- | --- | --- | --- |
| Function name | Paired compat/RGB565 provider naming, initializer assignments, Surface family conventions, broad shared consumers | `SoftwareRenderRgb565ScaledRleTintCallback` | `RankingEventListPane::DrawScaledRLESpriteTinted_565`, `RenderMonsterTint`, `sub_4C3A50` |
| Owner | Surface owns slot storage, selection, pixel-format families, and generated root; callers only consume | `Surface.cpp`, file-local static provider | GrafPort, Riding, Monster, RankingEventListPane, SoftwareBlend16 |
| Return type | Stored/decompiled `void`, callers ignore return, shared slot contract | `void` | `int` or decompiler-residue return |
| Receiver | ECX flows through GrafPort state and `GetClipRect`; accepted class layout matches offsets; current stored ABI now names the receiver `const struct GrafPort *this` | `GrafPort *port` | older generic `int this` stored prestate, feature-pane receiver, or a non-GrafPort owner |
| Argument 1 | Reads `+0x24` mask stream; caller passes EPF tile/frame context | `const EPFTileContext *sourceContext` | raw byte buffer, sprite object, source pixels |
| Arguments 2/3 | Four-int rectangle reads and caller construction | const source/destination `RectBounds *` | `_DWORD *`, `int *`, one combined rectangle |
| Mode | One-byte frame row and exact comparison to `3` | `unsigned char mode` | `bool`, enum invented without project proof, 32-bit int source token |
| Tint | Caller passes MapPane day/night float; body computes rounded `*32.0f` strength | `float tintAmount` | color value, alpha byte, palette pointer |
| Row offset | Integral arithmetic before projection; callers pass zero | `int rowOffset` | float, source top coordinate |
| Scale/shear | Caller values `1.5f/0.0f` or MapPane projection divisor/shear; body uses float math | `float verticalScale`, `float horizontalShear` | width/height, two generic scale factors |
| RLE semantics | Direct signed-byte loop, zero row delimiter, sign branch, `&0x7f`; EPFTileContext docs | negative foreground transform, positive skip | color-valued runs, source intensity blending |
| Lookup roots | Direct refs and established table shapes | 5-bit red/blue root and 6-bit green root | palettes, source textures, gamma tables |
| Constants | Raw bytes decode to 32.0f/0.5f; many cross-function refs | source literals `32.0f` and `0.5f` | target-specific named globals or IDA renames |
| H disposition | Provider is private; callback type/global are shared | target H blank, UID0000TN H owns typedef/extern | duplicate target declaration or class method |

The strongest heuristic conclusion is not based on similarity alone. Direct callers supply every semantic parameter; accepted structures resolve every accessed field; direct target data flow resolves the algorithm; and the paired provider plus initializer resolves source-family placement. The remaining uncertainty concerns original lexical spelling, not executable behavior or source readiness.

## Evidence Standards Used

- Direct IDA facts from the dated read-only witness and fresh 2026-08-12 bounded revalidation: function bounds, observed name/type/frame, body hash, block/instruction counts, target and slot xrefs, bytes, neighboring items, lookup refs, constants, comments, and observed type/name-table state.
- Caller/initializer facts: exact assignment sites and indirect consumers in Riding/Monster routes observed during the research recheck.
- Type/layout facts: accepted EPFTileContext, RectBounds, GrafPort, MapPane, and lookup-table docs corroborated against body offsets.
- Comparative facts: compat provider has the same control/ABI shape with RGB555 channel extraction, but it is not used as a substitute for target-specific body proof.
- Negative facts: no direct caller, no target-specific constant ownership, no source-pixel read, no byte-count check, no vertical-scale guard, no function overlap, and no owner evidence for feature classes.
- Generated evidence is treated as a dated output witness, not binary or permanently current authority.
- Confidence is capped below final-audit levels because no original symbols or compile/binary-diff receipt exist and the compat peer still lacks its own completed formal body.

## Evidence Checked

- The earlier bounded read-only IDA MCP passes used sessions `supervisor-uid00048A-persist-20260812` and `supervisor-canonical-20260812T-current` for canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; their public attestations and exact results remain dated research provenance. The latest bounded read-only reconciliation used active canonical-path session `supervisor-uid0002OW-gate2b-20260813T0115Z`. Fresh `idb_list` on 2026-08-13 returned that exact path/session active, non-analyzing, and worker-backed. Public `runtime_attestation` at `2026-08-13T04:34:29.647811+00:00` returned schema 1, `ok:true`, empty errors, listener nonce `07ad2876f9b0faf9c68711e7096da285`, listener generation `pid:13936;created:134309934982668433`, and the exact active session/path worker route with matching `ida_pro_mcp`/`zeromcp` provenance. `server_health` returned `status:ok`, exact IDB path, Hex-Rays ready, and `auto_analysis_ready:false`. Fresh read-only lookup/item/comment/frame/type/byte/xref checks reproduced the target name/range/type, complete 27-row frame, two target refs, twenty-one slot refs, 12/11 lookup refs, 60/37 pooled-constant refs, predecessor/padding/successor boundaries, and empty target/padding/protected comment channels. B008 performed no mutation, backup, save, process control, or lifecycle action. The session label and dated runtime state are evidence only; current authority and prestate verification remain supervisor-owned.
- Canonical IDB physical identity at the latest reconciliation: SHA256 `B8C1ABC6A9FBCBE1B2021BC72AC15AD7EAAD0EF3DD82443ADEFCFC0ADE0151F9`, 143,206,895 bytes, mtime `2026-08-12T21:38:01.5543297-04:00`. The earlier `BD6FBD2512070832EC8DE94603D2000B32AF20FA3C817BA0D64CB776D1F0F2C9` / 143,206,743-byte and `1B8E6E1B96FD984BCF06236B3500CB11C132B2F89F9866CE808EBF5437D60D78` / 143,206,508-byte identities remain dated provenance. Input executable identity was SHA256 `9AEC210B2E9FB3072351C38A250658278ECD185026F387B06F6C7E622F9DA632`, 2,679,296 bytes.
- Older dated read-only research provenance: session `supervisor-b007-uid00034w-postsave-verify-20260810` used witness `C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\leaser\Agents\ida-backups\NexusTK.exe.uid00034W-postsave-verify-20260810-140528.i64`; canonical and witness were then both 143,204,622 bytes with SHA256 `D0048B0E9F4FE067654DC0FB9F75BF26701085F77179EC0D77DAE7EF5E25EE98`. It remains historical provenance only.
- IDA queries covered target/neighbor inspection, stack frame, function metrics, decompilation/disassembly, bytes, xrefs, name/type queries, proposed-name collision, callback slot, lookup roots, constants, and comments. All were read-only.
- Documentation checked: target, UID0002TC compat peer, UID0002TF RLE grammar peer, UID0002TH lookup peer, UID0000TN semantic callback table, UID0001PI physical callback table, UID00039V initializer, UID0002Y1 Riding, UID000164 GrafPort clip helper, Surface/GrafPort/EPFTileContext/MapPane docs, lookup-root pages, and RGB565 aggregate.
- Generated state checked again read-only on 2026-08-13: final report-freeze validator command `000000023100`, timestamp `2026-08-13T07:10:45-04:00`, produced `auto-generated/NexusTK/render/Surface.cpp` SHA256 `10801BE643882E7CB30D9749090E0D5215E44C2ADB2209939D2D1915FEF7A0E7`, 71,018 bytes, 2,120 LF lines, and `Surface.h` SHA256 `AE5B807D20E2F71167E5E68392DF8611429B306CB1C63EE01E6328C9B420FE67`, 3,087 bytes, 102 LF lines. Physical readback found one UID0002TG source item/body, zero UID0002TG empty-emitter markers, one `SurfaceScaledRleTintProc` typedef, one `g_pfnBlitScaledRleTint` extern, one definition, and one assignment to each compat and RGB565 provider. Command `000000022403` remains the dated originating UID0002TG generation receipt; `000000022761`, `000000022770`, `000000022920`, `000000022981`, `000000023008`, `000000023042`, `000000023051`, and `000000023099` are superseded historical refreshes, not the final report-freeze generated-file identity.
- Dated 2026-08-11 report-time generated tracker snapshot: `auto-generated/-ag-research-tracker.md` SHA256 `58B8A6E8E12C9FB01637C5153FB7490FC562CF57790540EAD647F8E54FF7B163`, 2,043,293 bytes, 9,603 lines; row 3606 then recorded UID0002TG as `92/94`, mean `93.0`, reconstructable `true`, with zero error/empty-emitter counters. The hash, size, line count, and row location are historical evidence only. They must not be reused as current authority: dynamically reread the tracker at every relevant gate and after any report execution/move.
- Final report-freeze tracker preflight: validator command `000000023101` at `2026-08-13T07:11:17-04:00`, SHA256 `CB7917DF1FD82B736C493CC561D7476CE6CDC4102D115568CAC2678971C4207A`, 1,723,234 bytes, 6,780 LF lines; row 3055 records UID0002TG as `92/94`, mean `93.0`, reconstructable `true`, with zero error/empty-emitter counters. Commands `000000022874`, `000000022990`, `000000023008`, `000000023045`, `000000023072`, and `000000023099` and their associated snapshots are historical. Command `000000023101` is a dated report-freeze receipt only and is not permanent queue or lifecycle authority.
- Final report-freeze manual-coverage reread: `by-memory/-coverage-report.md` had SHA256 `44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681`, 2,211,023 bytes, 4,936 LF lines, with UID0002TC/UID00016L/UID0002TG/UID0001PI at lines 1628/1648/1656/4817. Earlier read-only snapshot SHA256 `D563B2D2DF4833B322D448CCC65BBE3421FE687E2B37D865A435AEAE1112F215`, 2,210,378 bytes, 4,935 LF lines, is retained as dated intervening history. Command `000000023009` at `2026-08-12T22:49:14-04:00`, exit 0/ok 1, remains the dated successful validation receipt for still-earlier SHA256 `BD69D1C1B92DD2840D1D91DA909725366B9538051472A91D25DF1EB884E98F1C`; it is not mislabeled as validating either later unrelated whole-file identity. At the same final reread, `by-global/-coverage-report.md` had SHA256 `B689A8B252FB7D24C3CADEF6F410636BB4A3EE81D5AEBEB9D96F130700E91A9A`, 101,868 bytes, 219 LF lines, UID0000TN at line 200, with retained successful command `000000023010`; `by-file/-coverage-report.md` had SHA256 `02A44EDBAAA596D59ECE589D05E6BF57553C3DCA5AD7EAE0E1369C567344E756`, 169,241 bytes, 319 LF lines, UID0000J4/UID0000OC at lines 85/275, with retained successful command `000000023044`; and `by-class/-coverage-report.md` had SHA256 `FF87AEF9714FF85284A51ACDB1ADC7171395DD926C44D78260A7CF8074A232E0`, 277,113 bytes, 626 LF lines, UID00004I/UID00005V at lines 188/237, with retained successful command `000000023043`. Every accepted payload remained present at same-or-greater detail; commands `22921` through `22924`, `23011`, and `23012` and their identities remain older snapshots only.
- Old-report search terms: `0002TG`, `0x004c3a50`, `SoftwareRenderRgb565ScaledRleTintCallback`, `g_pfnBlitScaledRleTint`, `ScaledRleTint`, `SoftwareRenderRgb565Callbacks`. Matching reports for UID00016L, UID0002TC, UID0002TF, UID0002Y1, UID00039V, and UID0002TH were used as leads. No direct prior UID0002TG B report exists.
- Negative checks: target-name collision absent; target address-regular, address-repeatable, function-regular, and function-repeatable comments all absent; slot/padding comments absent; no source-pixel read; no encoded-mask-count use; no direct code caller; pooled constants have broad xrefs; no overlap with the previous switch table or next callback.
- Gate 2A address recheck: initializer UID00039V, physical table UID0001PI, compat child UID0002TC, and compat aggregate UID0000W4 independently record the retained compat provider reference at `0x0055873b`; only semantic UID0000TN contained `0x00558739`, and no current by-* evidence supports that value. The semantic page was corrected to `0x0055873b` without changing the already-consistent `0x00558ba8`, `0x00558829`, or `0x00558ec4` refs.
- Gate 2A metadata recheck: UID0001PI's physical header is exactly `COMPLETION:92` / `CONFIDENCE:94`; stale current-state prose and report mirrors that still said `91/93` were corrected without changing owner/emitter, reconstructable state, or formal covered-by disposition.
- Independent C2TG-030 recheck at the recorded callback boundary found `by-file/Surface.md` with exact RGB565 assignment refs `0x00558829` and `0x00558ec4` in both the UID0002TG inventory row and detailed slot-4 section, beside compat refs `0x0055873b`/`0x00558ba8`; that post-validation snapshot is SHA256 `C7E6AFD00B89B7C9D34E583B6560993DCB6D3F8A71C136F241D7034F7C495955`, 142,346 bytes, 614 lines.
- Historical initial report-only phase: no IDA mutation, validator, generated refresh, by-* edit, manual coverage edit, lifecycle command, or execute/archive action occurred during that earlier phase. The later authorized callback applied the recorded ordinary by-* changes and scoped validators; IDA, manual coverage, generated refresh, and lifecycle actions remained outside B008's callback scope.

Historical physical documentation/input identities at the pre-callback final research reread; these are preserved as research-era provenance and are not current Gate 2A proof:

| Path | Bytes | SHA256 |
| --- | ---: | --- |
| target UID0002TG | 14,112 | `CFF90EB9E35ECE6FD2AA11719498C544234104251ED84D8D04F478207F0D2E94` |
| `by-global/SurfaceRenderCallbackTable.md` | 85,497 | `19158874B1AB117657ED4249C536DD5C9716904EA12E393F699AF8B063A9726C` |
| physical table UID0001PI | 71,362 | `93F3B817469D521EA620BB3E78FDFA7B7CAF5AD7B1DF38DC7B82ECB7B713B339` |
| initializer UID00039V | 25,338 | `62AAB634BA056718980A60D8F10BEA6AD739DD05BFF146B1CEFA20F009AB0409` |
| compat peer UID0002TC | 20,811 | `FE0C8C91711438C51BFB8823F2EF8A6144E89F074A58314D69155785426E28E0` |
| `by-file/Surface.md` | 135,722 | `D9D4AAC904B0DFA64B93BE6BF636A303FC5966B7A4F32274F86D64F81163D0A8` |
| `by-file/EPFTileContext.md` | 19,762 | `9E577923073936C4772EE451A89DB106CC8601CB15B839A2F8742EBEB8B1DF9A` |
| `by-class/EPFTileContext.md` | 27,173 | `E30DEF15E1A50EB174B76E7471EAE1FBDD75BC5DCD8228C8293FA0B39748AD96` |
| generated `Surface.cpp` | 59,575 | `EB6054213AA78F0D407E4E523FF2293D599D92FC28C8DB63ABAFBBDB322BF8AB` |
| generated `Surface.h` | 1,982 | `3E70DCBB674F63C3EB55686CE4797E6AF3549060C71D9A744ABA7687DFD349A6` |
| manual by-memory coverage | 2,191,934 | `48A3535442FD0E4152B1DC36A702016EDDD09AEAB214B93B628FFA5CF671E016` |
| manual by-global coverage | 101,256 | `475852E3421C2267AC394EBA2C0D0E0AF597FF1BAE88BB6464E710C02D091E76` |
| manual by-file coverage | 168,328 | `5CD0F53214FEE83C7281A5C4DAFA8BBB14827C81DBDD1C154ED81CD376D49285` |
| manual by-class coverage | 277,235 | `71D0018B513B3E5CD029ED0D0DF0992EFACCFE1424B69A3349F4EE9BEBCDFFB3` |

Read-only manual support-row comparison at the final research reread:

- `by-class/-coverage-report.md:237`, file identity `277,235` bytes / SHA256 `71D0018B513B3E5CD029ED0D0DF0992EFACCFE1424B69A3349F4EE9BEBCDFFB3`, then read exactly: `- [UID:00005V][GrafPort](by-class/GrafPort.md) : reconstructable : 88% : very-strong : Core graphics-port class with exact surface/clip/draw/text children, inherited UID000161 GrafPort::GetBounds over m_visibleBounds +0x44, draw enable/mode at +0x71/+0x70, and canonical callback color fields m_drawColor +0x74 and m_textBackFillColor +0x78; broad UI/map/render receivers reject historical BackPane or callback-owner pollution while the broad class formal remains blank to avoid a lossy partial shell.` That historical row lacked the proposed UID0002TG receiver-only dependency and required the Section 28 replacement later verified at same-or-greater detail.
- `by-file/-coverage-report.md:85`, file identity `168,328` bytes / SHA256 `5CD0F53214FEE83C7281A5C4DAFA8BBB14827C81DBDD1C154ED81CD376D49285`, then read exactly: `    - [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md) : reconstructable : 89% : strong : EPF tile-context render-support module with a Palette.h dependency for read-only consumption of DLPalette inclusive range records through the documented friendship, plus complete layout, lifecycle, normalization, and query routes.` That historical row lacked the proposed UID0002TG `encodedMaskBytes`/no-source-pixel-read use and required the Section 28 replacement later verified at same-or-greater detail.
- `by-class/-coverage-report.md:188`, under the same `277,235`-byte / SHA256 `71D0018B513B3E5CD029ED0D0DF0992EFACCFE1424B69A3349F4EE9BEBCDFFB3` identity, then read exactly: ``    - [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) : reconstructable : 88% : very-strong : Exact 0x28 decoded tile-context value type emitted through `NexusTK/render/EPFTileContext.h`; its palette query consumes DLPalette inclusive range records through the documented friend relationship while palette storage and copy semantics remain DLPalette-owned.`` That historical row also lacked the proposed UID0002TG `encodedMaskBytes`/no-source-pixel-read use and required the Section 28 replacement later verified at same-or-greater detail.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2TG-001 | 0002TG | Preserve exact target range 0x004c3a50-0x004c3ce1, size 0x291/657, 25 blocks, 212 instructions, and body SHA CF941A937FF9CF24FA19A2421020BBE42B03FFBA9EDC02C00FAB427F6C68A6F7. | exact | Actor/authority: B008 callback; dated 2026-08-12 canonical-path evidence and fresh 2026-08-13 bounded read-only reconciliation reproduced function metrics and bytes; current Gate 2B authority and prestate verification remain supervisor-owned | UID0002TG Address Range / IDA Evidence | incorporate | applied |
| C2TG-002 | 0002TG | Preserve two target data refs at 0x00558829 and 0x00558ec4 and no direct code callers. | exact | Actor/authority: B008 callback; dated 2026-08-12 canonical-path evidence and fresh 2026-08-13 bounded read-only reconciliation reproduced target xrefs; current Gate 2B authority and prestate verification remain supervisor-owned | UID0002TG IDA Evidence / Registration | incorporate | applied |
| C2TG-003 | 0002TG | Preserve all twenty-one slot refs and the distinction between target refs, slot dispatch, and setup refs. | exact | Actor/authority: B008 callback; dated 2026-08-12 canonical-path evidence and fresh 2026-08-13 bounded read-only reconciliation reproduced 0x0069b3f0 xrefs; current Gate 2B authority and prestate verification remain supervisor-owned | UID0002TG Dispatch Inventory | incorporate | applied |
| C2TG-004 | 0002TG | Replace the broad raw prototype prose with the logical void GrafPort receiver plus eight source arguments. | very strong | Actor/authority: B008 callback; Frame, decompile, callers, types, paired provider | UID0002TG Source Contract | incorporate | applied |
| C2TG-005 | 0002TG | Document EPFTileContext mask stream at +0x24 and signed zero-delimited row grammar. | exact | Actor/authority: B008 callback; Body and accepted EPFTileContext layout | UID0002TG Data Layout / Behavior | incorporate | applied |
| C2TG-006 | 0002TG | Document that negative runs transform existing destination RGB565 pixels and source pixelData is not read. | exact | Actor/authority: B008 callback; Target data flow | UID0002TG Behavior | incorporate | applied |
| C2TG-007 | 0002TG | Preserve the prior source-intensity-combination statement as a superseded historical assumption with the exact contradiction. | exact | Actor/authority: B008 callback; Target data flow rejects prior statement | UID0002TG Historical Assumptions | historicalize | applied |
| C2TG-008 | 0002TG | Document draw-enabled gate and GetClipRect call before projection and mode test. | exact | Actor/authority: B008 callback; Target control flow | UID0002TG Behavior | incorporate | applied |
| C2TG-009 | 0002TG | Document projected-row, destination-Y, and destination-X/shear formulas exactly. | exact | Actor/authority: B008 callback; Target float/integer data flow | UID0002TG Projection And Scaling | incorporate | applied |
| C2TG-010 | 0002TG | Preserve mode==3 gate after initial setup; do not hoist it earlier. | exact | Actor/authority: B008 callback; Target branch order | UID0002TG Exact Behavior Constraints | incorporate | applied |
| C2TG-011 | 0002TG | Document tint strength as low byte of int(tintAmount*32.0f+0.5f), including wrap semantics. | exact | Actor/authority: B008 callback; Constants, conversion, byte use | UID0002TG Tint Tables | incorporate | applied |
| C2TG-012 | 0002TG | Document clipping and negative/positive run handling with token length token&0x7f. | exact | Actor/authority: B008 callback; Inner row loop | UID0002TG RLE And Clipping | incorporate | applied |
| C2TG-013 | 0002TG | Document 5/6/5 lookup transformation and exact RGB565 reassembly. | exact | Actor/authority: B008 callback; LUT refs and masks | UID0002TG Tint Tables | incorporate | applied |
| C2TG-014 | 0002TG | Preserve rounded vertical-scale accumulator and whole-row delimiter skipping. | exact | Actor/authority: B008 callback; Outer loop data flow | UID0002TG Projection And Scaling | incorporate | applied |
| C2TG-015 | 0002TG | Preserve initial origin-adjusted destination pointer and later origin-unadjusted row-pointer recomputation. | exact | Actor/authority: B008 callback; Target pointer expressions | UID0002TG Exact Behavior Constraints | incorporate | applied |
| C2TG-016 | 0002TG | Preserve absence of encodedMaskByteCount check and verticalScale guard; do not add defensive behavior. | exact | Actor/authority: B008 callback; Negative body checks | UID0002TG Negative Evidence / C++ rationale | incorporate | applied |
| C2TG-017 | 0002TG | Preserve preceding 16-byte switch table and following 15 CC-byte alignment with next function at 0x004c3cf0. | exact | Actor/authority: B008 callback; Boundary bytes/items | UID0002TG Range / Padding | incorporate | applied |
| C2TG-018 | 0002TG | Use SoftwareRenderRgb565ScaledRleTintCallback as the source-facing name. | very strong | Actor/authority: B008 callback; Initializer, family style, broad consumers | UID0002TG Naming | incorporate | applied |
| C2TG-019 | 0002TG | Reject RankingEventListPane, caller-biased, and raw sub_4C3A50 names as stale source identities. | very strong | Actor/authority: B008 callback; Initializer, family style, broad consumers | UID0002TG Historical Naming | reject-stale | applied |
| C2TG-020 | 0002TG | Retain Surface UID0000OC as owner and emitter route. | very strong | Actor/authority: B008 callback; Storage, initializer, providers, consumers | UID0002TG Ownership | incorporate | applied |
| C2TG-021 | 0002TG | Preserve GrafPort, Riding, Monster, SoftwareBlend16, and feature-pane ownership candidates as rejected historical alternatives. | very strong | Actor/authority: B008 callback; Storage and broad consumer evidence | UID0002TG Ownership History | historicalize | applied |
| C2TG-022 | 0002TG | Populate target formal CPP with the exact file-local callback body from Section 22. | very strong | Actor/authority: B008 callback; Full target reconstruction | UID0002TG RECONSTRUCTION_CPP | incorporate | applied |
| C2TG-023 | 0002TG | Keep target formal H blank because the provider is private and shared declaration belongs to UID0000TN. | very strong | Actor/authority: B008 callback; Source placement and sibling convention | UID0002TG RECONSTRUCTION_H | already-present | already-present |
| C2TG-024 | 0000TN | Add SurfaceScaledRleTintProc typedef with exact receiver and eight arguments. | very strong | Actor/authority: B008 callback; Slot, callers, target, paired provider | UID0000TN RECONSTRUCTION_H / slot 4 typedef | incorporate | applied |
| C2TG-025 | 0000TN | Add extern SurfaceScaledRleTintProc g_pfnBlitScaledRleTint. | very strong | Actor/authority: B008 callback; Slot storage and project convention | UID0000TN RECONSTRUCTION_H / slot 4 extern | incorporate | applied |
| C2TG-026 | 0000TN | Add one SurfaceScaledRleTintProc g_pfnBlitScaledRleTint definition. | very strong | Actor/authority: B008 callback; Physical slot and semantic ownership | UID0000TN RECONSTRUCTION_CPP / slot 4 definition | incorporate | applied |
| C2TG-027 | 00039V | Preserve exact slot-4 initializer inventory with retained compat/RGB565 refs `0x0055873b`/`0x00558829` and inline refs `0x00558ba8`/`0x00558ec4`. | very strong | Actor/authority: B008 callback; Existing formal initializer plus four-way by-* address recheck | UID00039V Slot Inventory | incorporate | applied |
| C2TG-028 | 0001PI | Preserve physical slot-4 prose with exact provider assignment refs and non-emitting covered-by disposition while reconciling current physical metadata to 92/94. | very strong | Actor/authority: B008 callback; Slot location, semantic owner, provider pair, physical header | UID0001PI Slot Inventory / metadata | incorporate | applied |
| C2TG-029 | 00016L | Mark UID0002TG source-ready in the RGB565 family inventory while keeping aggregate non-reconstructable and blank. | very strong | Actor/authority: B008 callback; Exact child body and aggregate policy | UID00016L Inventory / Summary | incorporate | applied |
| C2TG-030 | 0000OC | Preserve exact slot-4 declaration, provider-body ownership, source order, and compat/RGB565 assignment refs `0x0055873b`/`0x00558ba8` and `0x00558829`/`0x00558ec4`. | very strong | Actor/authority: B008 callback; Surface lines 92/115/426; SHA256 C7E6AFD00B89B7C9D34E583B6560993DCB6D3F8A71C136F241D7034F7C495955 | by-file/Surface UID0002TG support | incorporate | applied |
| C2TG-031 | 0002TC | Preserve the resolved shared ABI, parameter contract, comparative RGB555/RGB565 algorithm facts, and exact compat target refs `0x0055873b`/`0x00558ba8`. | strong | Actor/authority: B008 callback; Target, paired-provider, and current xref comparison | UID0002TC Source Contract | incorporate | applied |
| C2TG-032 | 0002TC | Preserve the former shared ABI/layout/name blockers as superseded history while retaining the peer-specific blank-CPP cap. | strong | Actor/authority: B008 callback; Target resolves shared blockers but not peer body | UID0002TC Historical Assumptions | historicalize | applied |
| C2TG-033 | 00005V | Keep UID0002TG GrafPort support strictly target-specific: read-only receiver fields, GetClipRect, target `0x004c3a50`, slot 4, refs `0x00558829`/`0x00558ec4`, and twenty-one slot refs; exclude unrelated slot-7 fill evidence. | very strong | Actor/authority: B008 callback; GrafPort layout, target accesses, initializer, and slot-4 refs | by-class/GrafPort UID0002TG support | incorporate | applied |
| C2TG-034 | 0000J4 | Add target-specific encodedMaskBytes use, signed row grammar, and no-source-pixel-read distinction. | exact | Actor/authority: B008 callback; EPFTileContext layout and target data flow | by-file/EPFTileContext UID0002TG support | incorporate | applied |
| C2TG-035 | 00004I | Add target-specific encodedMaskBytes use, signed row grammar, and no-source-pixel-read distinction. | exact | Actor/authority: B008 callback; EPFTileContext layout and target data flow | by-class/EPFTileContext UID0002TG support | incorporate | applied |
| C2TG-036 | 0002Y1 | Keep the existing source-ready Riding consumer call and MapPane parameter semantics unchanged. | very strong | Actor/authority: B008 callback; Current Riding documentation already has same-or-greater detail | UID0002Y1 Target Support | already-present | already-present |
| C2TG-037 | 0002TG | Raise target metadata from 87/90 to 92/94. | very strong | Actor/authority: B008 callback; Resolved source blockers and remaining audit caps | UID0002TG completion/confidence | incorporate | applied |
| C2TG-038 | 0002TG | Keep CANONICAL_OWNER 0000OC, RECONSTRUCTABLE TRUE, EMITTER_UIDS 0000OC, and blank position unchanged. | exact | Actor/authority: B008 callback; Existing route remains correct | UID0002TG routing metadata | already-present | already-present |
| C2TG-039 | 0000TN | Keep support metadata 94/95 unchanged. | strong | Actor/authority: B008 callback; Broader table caps remain | UID0000TN metadata | already-present | already-present |
| C2TG-040 | 0001PI | Reconcile all current support metadata mirrors to the physical page's existing 92/94 without changing owner/emitter, reconstructable state, or covered-by source disposition. | strong | Actor/authority: B008 callback; Physical UID0001PI header and current page reread | UID0001PI metadata / current-state prose | incorporate | applied |
| C2TG-041 | 00039V | Keep support metadata 91/93 unchanged. | strong | Actor/authority: B008 callback; Initializer broader caps remain | UID00039V metadata | already-present | already-present |
| C2TG-042 | 00016L | Keep support metadata 90/92 unchanged. | strong | Actor/authority: B008 callback; Aggregate remains non-reconstructable | UID00016L metadata | already-present | already-present |
| C2TG-043 | 0000OC | Keep support metadata 90/89 and current reconstruction path unchanged. | strong | Actor/authority: B008 callback; Broader Surface source-boundary caps remain | UID0000OC metadata | already-present | already-present |
| C2TG-044 | 0002TC | Keep support metadata 87/90 unchanged. | strong | Actor/authority: B008 callback; Peer-specific body remains incomplete | UID0002TC metadata | already-present | already-present |
| C2TG-045 | 0002TG | Preserve the same-or-greater manual target row; no replacement or pruning is required. | exact | Actor/authority: Primary supervisor no-change disposition; dated command 23009 passed against the earlier coverage identity, while the final report-freeze physical reread proves row line 1656 under SHA256 44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681 contains the Section 28 payload plus retained later detail; intermediate SHA256 D563B2D2DF4833B322D448CCC65BBE3421FE687E2B37D865A435AEAE1112F215 and command 22921 are history. | by-memory/-coverage-report.md line 1656 | already-present | already-present |
| C2TG-046 | 0000TN | Preserve the current same-or-greater semantic-table manual row with slot-4/slot-5 closure; no replacement is required. | exact | Actor/authority: Primary supervisor no-change disposition; current by-global coverage command 23010 passed at 2026-08-12T22:49:34-04:00, and row line 200 under SHA256 B689A8B252FB7D24C3CADEF6F410636BB4A3EE81D5AEBEB9D96F130700E91A9A contains the Section 28 payload plus retained later slot detail; command 22922 is historical. | by-global/-coverage-report.md line 200 | already-present | already-present |
| C2TG-047 | 0000OC | Preserve the current same-or-greater Surface manual row with slot-4/slot-5 closure; no replacement is required. | exact | Actor/authority: Primary supervisor no-change disposition; current by-file coverage command 23044 and physical reread prove row line 275 under SHA256 02A44EDBAAA596D59ECE589D05E6BF57553C3DCA5AD7EAE0E1369C567344E756 contains the Section 28 payload plus retained later detail; commands 22923 and 23011 are historical. | by-file/-coverage-report.md line 275 | already-present | already-present |
| C2TG-048 | 0001PI | Preserve the same-or-greater physical-table row with 92% metadata, source-ready slot-4 detail, and unchanged owner/emitter/covered-by disposition. | exact | Actor/authority: Primary supervisor no-change disposition; dated command 23009 passed against the earlier coverage identity, while the final report-freeze physical reread proves row line 4817 under SHA256 44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681 contains the Section 28 payload plus retained later slot detail; intermediate SHA256 D563B2D2DF4833B322D448CCC65BBE3421FE687E2B37D865A435AEAE1112F215 and command 22921 are history. | by-memory/-coverage-report.md line 4817 | already-present | already-present |
| C2TG-049 | 00016L | Preserve the same-or-greater RGB565 aggregate row including source-ready UID0002TG and unchanged aggregate disposition. | exact | Actor/authority: Primary supervisor no-change disposition; dated command 23009 passed against the earlier coverage identity, while the final report-freeze physical reread proves row line 1648 under SHA256 44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681 contains the Section 28 payload plus retained later child detail; intermediate SHA256 D563B2D2DF4833B322D448CCC65BBE3421FE687E2B37D865A435AEAE1112F215 and command 22921 are history. | by-memory/-coverage-report.md line 1648 | already-present | already-present |
| C2TG-050 | 0002TC | Preserve the same-or-greater compat-peer row with resolved shared contract and explicit peer-body cap. | exact | Actor/authority: Primary supervisor no-change disposition; dated command 23009 passed against the earlier coverage identity, while the final report-freeze physical reread proves row line 1628 under SHA256 44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681 contains the Section 28 payload plus retained later body evidence; intermediate SHA256 D563B2D2DF4833B322D448CCC65BBE3421FE687E2B37D865A435AEAE1112F215 and command 22921 are history. | by-memory/-coverage-report.md line 1628 | already-present | already-present |
| C2TG-051 | 0002TG | Apply A01 pure name-only function rename after exact canonical range/type/frame/collision and four-channel comment prestate verification; require all four comment channels unchanged and no function-directory or decompiler-refresh/cache side effect. | very strong | Actor/authority: Primary supervisor; declarative A01 prestate, intended state, protections, and expected readback | Canonical IDB function 0x004c3a50 | incorporate | proposed |
| C2TG-052 | 0002TG | Apply A02 exact function-regular comment while preserving the address-regular, address-repeatable, and function-repeatable channels. | exact | Actor/authority: Primary supervisor; declarative A02 prestate, intended state, protections, and expected readback | Canonical IDB function comment 0x004c3a50 | incorporate | proposed |
| C2TG-053 | 0002TG | Apply A03 exact padding regular comment without changing the 15-byte item. | exact | Actor/authority: Primary supervisor; declarative A03 prestate, intended state, protections, and expected readback | Canonical IDB address comment 0x004c3ce1 | incorporate | proposed |
| C2TG-054 | 0002TG | Reject the prior stack rename/type and function set_type plan because no deterministic physical post-frame was proven. | exact safety disposition | Actor/authority: Primary supervisor; complete dated literal frame and report-only evidence limit | Canonical IDB type/frame handoff | reject-stale | proposed |
| C2TG-055 | 0000TN | Preserve callback slot 0x0069b3f0 item, name, type, comments, and exact 21-ref set without mutation. | exact | Actor/authority: Primary supervisor; declarative P01 protected state and expected readback | Canonical IDB slot 0x0069b3f0 | already-present | proposed |
| C2TG-056 | 0002TG | Preserve 5-bit lookup root 0x0069b3d8 item, name, type, comments, and exact 12-ref set without mutation. | exact | Actor/authority: Primary supervisor; declarative P02 protected state and expected readback | Canonical IDB lookup root 0x0069b3d8 | already-present | proposed |
| C2TG-057 | 0002TG | Preserve 6-bit lookup root 0x0069b3dc item, name, type, comments, and exact 11-ref set without mutation. | exact | Actor/authority: Primary supervisor; declarative P03 protected state and expected readback | Canonical IDB lookup root 0x0069b3dc | already-present | proposed |
| C2TG-058 | 0002TG | Preserve pooled 0.5f item 0x006104b0, bytes, name, absent type/comments, and 60-ref count without mutation. | exact | Actor/authority: Primary supervisor; declarative P04 protected state and expected readback | Canonical IDB pooled constant 0x006104b0 | already-present | proposed |
| C2TG-059 | 0002TG | Preserve pooled 32.0f item 0x006104cc, bytes, name, absent type/comments, and 37-ref count without mutation. | exact | Actor/authority: Primary supervisor; declarative P05 protected state and expected readback | Canonical IDB pooled constant 0x006104cc | already-present | proposed |
| C2TG-060 | 0002TG | Preserve the successful fresh scoped validation and physical reread of the target page; historical commands 000000021842 and 000000021896 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022926 at 2026-08-12T18:42:50-04:00, exit 0, ok 1, generated skipped; physical SHA256 45FEFE9E8C9426BF328C06A82C3A61C2CA75B83F4E91B8DDEB2C1E41F3815586, 25,984 bytes, 290 lines. | by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md | incorporate | applied |
| C2TG-061 | 0000TN | Preserve the successful fresh scoped validation and physical reread of the semantic callback-table page; historical commands 000000021843 and 000000021894 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022927 at 2026-08-12T18:42:53-04:00, exit 0, ok 1, generated skipped; three pre-existing UID0003XE warnings only; physical SHA256 00EAF8EE3BE884D38810AAC003F3A652CBD1267421DA8947F399C5E3078FFD24, 94,360 bytes, 553 lines. | by-global/SurfaceRenderCallbackTable.md | incorporate | applied |
| C2TG-062 | 0001PI | Preserve the successful fresh scoped validation and physical reread of the 92/94 physical callback-table page; historical commands 000000021844 and 000000021895 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022928 at 2026-08-12T18:42:56-04:00, exit 0, ok 1, generated skipped; three pre-existing UID0003XE warnings only; physical SHA256 4E63568215B41E93F0D076B37DBB70DE4A22EC8D79E279C3FCEAFE98BC18199B, 78,679 bytes, 417 lines. | by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md | incorporate | applied |
| C2TG-063 | 00039V | Preserve the successful fresh scoped validation and physical reread of the initializer page; historical commands 000000021845 and 000000021897 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022929 at 2026-08-12T18:42:59-04:00, exit 0, ok 1, generated skipped, no warnings; physical SHA256 CC7DC015E9A71BF88BE7BFD6566D74F00BD78C6A8F9E63B304F4BB15BD47785A, 28,970 bytes, 241 lines. | by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md | incorporate | applied |
| C2TG-064 | 00016L | Preserve the successful fresh scoped validation and physical reread of the RGB565 aggregate page; historical commands 000000021846 and 000000021898 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022930 at 2026-08-12T18:43:03-04:00, exit 0, ok 1, generated skipped, no warnings; physical SHA256 17FDC93B5559A59375FA6FF036887C3B5B8FF91F8A31AB4A4D1A5CBB6663C35A, 50,980 bytes, 294 lines. | by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md | incorporate | applied |
| C2TG-065 | 0000OC | Freshly validate and physically reread the C2TG-030 Surface repair with retained command 000000021994; historical commands 000000021847 and superseded 000000021899 carry no current proof credit. | exact receipt | Actor/authority: B008 callback; Command 000000021994, 2026-08-11T12:31:21-04:00, exit 0, ok 1 | by-file/Surface.md | incorporate | applied |
| C2TG-066 | 0002TC | Preserve the successful fresh scoped validation and physical reread of the compat peer page; historical commands 000000021848 and 000000021900 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022931 at 2026-08-12T18:43:06-04:00, exit 0, ok 1, generated skipped, no warnings; physical SHA256 A7B998198024E0F01A010F797B9C3FF6FB67D062554B8697C7DAE7A2282D0D15, 23,466 bytes, 169 lines. | by-memory/0x004bdcc0-0x004bdf3e.SoftwareRenderCompatScaledRleTintCallback.md | incorporate | applied |
| C2TG-067 | 00005V | Preserve the successful fresh scoped validation and physical reread of the target-specific GrafPort section; historical commands 000000021849 and 000000021893 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022932 at 2026-08-12T18:43:09-04:00, exit 0, ok 1, generated skipped; three pre-existing UID0003XE warnings only; physical SHA256 AC82E83E26B726F7D60A553798ABC7FACB4674660E4F3B49293AAE50081C8E38, 83,455 bytes, 534 lines. | by-class/GrafPort.md | incorporate | applied |
| C2TG-068 | 0000J4 | Preserve the successful fresh scoped validation and physical reread of the EPFTileContext file page; historical commands 000000021850 and 000000021901 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022933 at 2026-08-12T18:43:13-04:00, exit 0, ok 1, generated skipped, no warnings; physical SHA256 FE379E44538DD95CB5B0C958261E35FEF2CCBD342CF3D71FB16E20DD7D9A7981, 20,744 bytes, 186 lines. | by-file/EPFTileContext.md | incorporate | applied |
| C2TG-069 | 00004I | Preserve the successful fresh scoped validation and physical reread of the EPFTileContext class page; historical commands 000000021851 and 000000021902 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022934 at 2026-08-12T18:43:16-04:00, exit 0, ok 1, generated skipped, no warnings; physical SHA256 B05FEE57B247D44244E7E0CDC6EBD4616EBBB4D1E7561B0DFF9000D320958571, 28,350 bytes, 254 lines. | by-class/EPFTileContext.md | incorporate | applied |
| C2TG-070 | 0002TG | Preserve the successful dated by-memory manual-page validation receipt and final report-freeze physical readback proving all four UID0002TG-related rows remained unchanged at same-or-greater detail. | exact receipt and dated physical readback | Actor/authority: B008 read-only verification; command 23009 at 2026-08-12T22:49:14-04:00 exited 0/ok 1 with generated skipped against prior SHA256 BD69D1C1B92DD2840D1D91DA909725366B9538051472A91D25DF1EB884E98F1C; intermediate snapshot SHA256 D563B2D2DF4833B322D448CCC65BBE3421FE687E2B37D865A435AEAE1112F215 is history; final report-freeze SHA256 44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681, 2,211,023 bytes, 4,936 LF lines, retained physical rows 1628/1648/1656/4817 with all accepted payloads; command 22921 is older history. | by-memory/-coverage-report.md | incorporate | applied |
| C2TG-071 | 0000TN | Preserve successful current validation of the by-global manual page after its same-or-greater UID0000TN row was confirmed unchanged. | exact current receipt | Actor/authority: B008 current read-only validation; command 23010 at 2026-08-12T22:49:34-04:00, exit 0, ok 1, generated skipped, no content/hash change; SHA256 B689A8B252FB7D24C3CADEF6F410636BB4A3EE81D5AEBEB9D96F130700E91A9A, 101,868 bytes, 219 lines; only pre-existing UID0003MS warning; command 22922 is historical. | by-global/-coverage-report.md | incorporate | applied |
| C2TG-072 | 0000OC | Preserve successful dated validation of the by-file manual page after both same-or-greater Surface and EPFTileContext rows were confirmed unchanged. | exact dated receipt | Actor/authority: Primary-supervisor Gate 2A receipt and B008 report-freeze physical reread; command 23044 is the retained successful no-generated-refresh validation identity; SHA256 02A44EDBAAA596D59ECE589D05E6BF57553C3DCA5AD7EAE0E1369C567344E756, 169,241 bytes, 319 lines at that reread; commands 22923 and 23011 are historical; every later gate must reread the file. | by-file/-coverage-report.md | incorporate | applied |
| C2TG-073 | 0002TG | Preserve the coherent final report-freeze validator-owned generated refresh under command 000000023100 while retaining 000000022403 as dated originating UID0002TG generation history and 000000022761/000000022770/000000022920/000000022981/000000023008/000000023042/000000023051/000000023099 as superseded refresh history. | exact | Actor/authority: Validator; generated headers physically reread on 2026-08-13 record command 000000023100 at 2026-08-13T07:10:45-04:00; Surface.cpp/Surface.h share that dated report-freeze authority. | Validator generated-refresh result | already-present | already-present |
| C2TG-074 | 0002TG | Preserve exactly one UID0002TG target item/body in generated Surface.cpp. | exact | Actor/authority: Validator; final report-freeze Surface.cpp SHA256 10801BE643882E7CB30D9749090E0D5215E44C2ADB2209939D2D1915FEF7A0E7 has one UID0002TG item/body. | auto-generated/NexusTK/render/Surface.cpp target body | already-present | already-present |
| C2TG-075 | 0002TG | Preserve zero UID0002TG empty-emitter markers in generated Surface.cpp. | exact | Actor/authority: Validator; final report-freeze Surface.cpp SHA256 10801BE643882E7CB30D9749090E0D5215E44C2ADB2209939D2D1915FEF7A0E7 has zero UID0002TG empty-emitter markers. | auto-generated/NexusTK/render/Surface.cpp empty-marker check | already-present | already-present |
| C2TG-076 | 0000TN | Preserve exactly one SurfaceScaledRleTintProc typedef in generated Surface.h. | exact | Actor/authority: Validator; final report-freeze Surface.h SHA256 AE5B807D20E2F71167E5E68392DF8611429B306CB1C63EE01E6328C9B420FE67 has exactly one typedef. | auto-generated/NexusTK/render/Surface.h typedef | already-present | already-present |
| C2TG-077 | 0000TN | Preserve exactly one g_pfnBlitScaledRleTint extern in generated Surface.h. | exact | Actor/authority: Validator; final report-freeze Surface.h SHA256 AE5B807D20E2F71167E5E68392DF8611429B306CB1C63EE01E6328C9B420FE67 has exactly one extern. | auto-generated/NexusTK/render/Surface.h extern | already-present | already-present |
| C2TG-078 | 0000TN | Preserve exactly one g_pfnBlitScaledRleTint definition in generated Surface.cpp. | exact | Actor/authority: Validator; final report-freeze Surface.cpp SHA256 10801BE643882E7CB30D9749090E0D5215E44C2ADB2209939D2D1915FEF7A0E7 has exactly one definition. | auto-generated/NexusTK/render/Surface.cpp definition | already-present | already-present |
| C2TG-079 | 00039V | Preserve exactly one compat and one RGB565 provider initializer assignment in generated Surface.cpp. | exact | Actor/authority: Validator; final report-freeze Surface.cpp SHA256 10801BE643882E7CB30D9749090E0D5215E44C2ADB2209939D2D1915FEF7A0E7 has one assignment to each accepted provider. | auto-generated/NexusTK/render/Surface.cpp initializer | already-present | already-present |
| C2TG-080 | 0002TG | Physically reread generated Surface.cpp against final report-freeze validator command metadata and exact body, marker, definition, and initializer counts. | exact | Actor/authority: B008 read-only verification; 2026-08-13 reread: command 000000023100 at 2026-08-13T07:10:45-04:00; SHA256 10801BE643882E7CB30D9749090E0D5215E44C2ADB2209939D2D1915FEF7A0E7; 71,018 bytes; 2,120 LF lines; all required counts passed. | auto-generated/NexusTK/render/Surface.cpp readback | incorporate | applied |
| C2TG-081 | 0000TN | Physically reread generated Surface.h against final report-freeze validator command metadata and exact typedef/extern counts. | exact | Actor/authority: B008 read-only verification; 2026-08-13 reread: command 000000023100 at 2026-08-13T07:10:45-04:00; SHA256 AE5B807D20E2F71167E5E68392DF8611429B306CB1C63EE01E6328C9B420FE67; 3,087 bytes; 102 LF lines; both required counts passed. | auto-generated/NexusTK/render/Surface.h readback | incorporate | applied |
| C2TG-082 | 0002TG | Preserve successful dated validation of the by-class manual page after both same-or-greater GrafPort and EPFTileContext rows were confirmed unchanged. | exact dated receipt | Actor/authority: Primary-supervisor Gate 2A receipt and B008 report-freeze physical reread; command 23043 is the retained successful no-generated-refresh validation identity; SHA256 FF87AEF9714FF85284A51ACDB1ADC7171395DD926C44D78260A7CF8074A232E0, 277,113 bytes, 626 lines at that reread; commands 22924 and 23012 are historical; every later gate must reread the file. | by-class/-coverage-report.md | incorporate | applied |
| C2TG-083 | 00005V | Preserve the current same-or-greater GrafPort manual row with UID0002TG receiver-only dependency detail. | exact | Actor/authority: Primary supervisor no-change disposition; current by-class coverage command 23043 and physical reread prove row line 237 under SHA256 FF87AEF9714FF85284A51ACDB1ADC7171395DD926C44D78260A7CF8074A232E0 contains the Section 28 payload without unrelated slot-7 pollution; commands 22924 and 23012 are historical. | by-class/-coverage-report.md line 237 | already-present | already-present |
| C2TG-084 | 0000J4 | Preserve the current EPFTileContext by-file manual row with UID0002TG mask-stream/no-source-pixel-read detail. | exact | Actor/authority: Primary supervisor no-change disposition; current by-file coverage command 23044 and physical reread prove row line 85 under SHA256 02A44EDBAAA596D59ECE589D05E6BF57553C3DCA5AD7EAE0E1369C567344E756 contains the exact Section 28 payload; commands 22923 and 23011 are historical. | by-file/-coverage-report.md line 85 | already-present | already-present |
| C2TG-085 | 00004I | Preserve the current EPFTileContext by-class manual row with UID0002TG mask-stream/no-source-pixel-read detail. | exact | Actor/authority: Primary supervisor no-change disposition; current by-class coverage command 23043 and physical reread prove row line 188 under SHA256 FF87AEF9714FF85284A51ACDB1ADC7171395DD926C44D78260A7CF8074A232E0 contains the exact Section 28 payload; commands 22924 and 23012 are historical. | by-class/-coverage-report.md line 188 | already-present | already-present |

Ledger count is exactly 85. The canonical table is Actor-free, with actor/authority preserved inside every Evidence cell. Current checked credit is 76 rows: 52 `applied` and 24 `already-present`. The only nine proposed rows are primary-supervisor IDA claims C2TG-051 through C2TG-059.

## Positive Evidence Summary

- Exact modeled function at `0x004c3a50-0x004c3ce1`, 657 bytes, 25 blocks, 212 instructions, with stable boundary bytes and no overlap.
- Two initializer target refs select this exact provider; twenty-one slot refs establish broad runtime dispatch and reject caller ownership.
- Riding and Monster call sites independently establish all eight semantic argument roles and the ignored return.
- Accepted EPFTileContext and GrafPort layouts map every accessed offset to a source-quality field.
- The complete target body proves clipping, scale/shear projection, signed RLE row decoding, tint-strength formation, and RGB565 lookup writes.
- Compat provider has the same ABI/control skeleton and different RGB555 channel extraction, strongly supporting paired Surface source shape.
- UID0000TN and UID00039V already use `g_pfnBlitScaledRleTint` and both provider names, so the report closes formal source debt rather than inventing a new architecture.
- Dated bounded read-only IDA MCP revalidation on 2026-08-12 independently reproduced the target range/type/frame/body hash, exact target and slot xrefs, all boundary bytes, dependency names/types/ref counts, empty comment-channel prestates, and proposed-name collision absence from the then-canonical path. Fresh bounded 2026-08-13 reconciliation reproduced those literals through the healthy exact-path session identified in Section 9; current mutation authority remains supervisor-owned and external to this report.
- The final recommendation is sufficient because signature, layout, source placement, behavior, and formal code are independently corroborated; uncertainty is lexical/final-audit only.

## IDA MCP Facts

- Dated bounded read-only canonical-path revalidation on 2026-08-12 found name `sub_4C3A50`, range `[0x004c3a50,0x004c3ce1)`, size `0x291`, and stored type `void __thiscall(const struct GrafPort *this, int, _DWORD *, int *, char, float, int, float, float)`; fresh bounded 2026-08-13 reconciliation reproduced that exact state and all four absent comment channels. The older `void __thiscall(int this, int, _DWORD *, int *, char, float, int, float, float)` stored prestate is superseded historical evidence. The current literal state must agree before any recommendation receives supervisor credit.
- Decompiler rendering and stored type now independently resolve receiver data flow as GrafPort and render a receiver plus eight arguments; the exact stored `const struct GrafPort *this` spelling, not an older generic receiver or a future source-facing normalization, is the Gate 2B prestate.
- Body SHA256: `CF941A937FF9CF24FA19A2421020BBE42B03FFBA9EDC02C00FAB427F6C68A6F7` over 657 bytes.
- The complete frame was reproduced by both read-only passes and is literal and protected by the Section 21 table. It has fifteen four-byte `_DWORD` locals `var_50@0x08` through `var_18@0x40`, `outBounds@0x44/0x10/struct RectBounds`, `var_4@0x54/0x4/_DWORD`, `__saved_registers@0x58/0x4/_DWORD`, `__return_address@0x5c/0x4/_UNKNOWN *`, seven four-byte `_DWORD` arguments at `0x60`, `0x64`, `0x68`, `0x70`, `0x74`, `0x78`, and `0x7c`, and one one-byte `_BYTE` argument at `0x6c`. Fresh Gate 2B must match the complete 27-row matrix with no additions or omissions.
- Target xrefs: exactly `0x00558829` in `InitializeSurfaceRenderCallbacks` and `0x00558ec4` in `sub_558840`, both data/setup refs; no direct code caller.
- Both read-only passes found slot `0x0069b3f0` with exactly twenty-one inbound refs and accepted name-table mapping `g_pfnBlitScaledRleTint`; observed type is `SurfaceScaledRleTintProc`. Its physical inspect head is one byte, so this target recommends no slot data-boundary/type mutation.
- `SurfaceScaledRleTintProc` exists in the current local type library as a four-byte pointer typedef. The documentation formal declaration was nevertheless absent before callback.
- The 2026-08-12 collision query found no existing `SoftwareRenderRgb565ScaledRleTintCallback`; a current collision would invalidate the declarative A01 rename recommendation rather than authorize overwrite.
- Product callee is GrafPort `GetClipRect`; the trailing security-cookie check is compiler support. Self/CFG records are not source callees.
- LUT refs: `0x0069b3dc` at `0x004c3bc6`; `0x0069b3d8` at `0x004c3bd6` and `0x004c3bf7`.
- Constants: `0x006104cc` bytes `00 00 00 42` equal `32.0f`; `0x006104b0` bytes `00 00 00 3f` equal `0.5f`. They have broad pooled use and are protected no-change items.
- Predecessor `0x004c3a40-0x004c3a50` bytes are `11 33 4c 00 26 34 4c 00 f0 34 4c 00 9a 37 4c 00`, a local switch table for UID0002TF.
- Successor `0x004c3ce1-0x004c3cf0` is exactly fifteen `CC` bytes, blank comments/name/type. Next function at `0x004c3cf0` is `SoftwareRenderRgb565AlphaLookupBlitCallback`, size `0x1a3`.
- The 2026-08-12 session's `auto_analysis_ready:false` did not block research because health was `status:ok`, Hex-Rays was ready, and all required bounded IDB-backed queries succeeded; fresh Gate 2B runtime attestation controls mutation readiness.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | CPP/H disposition | Status |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `0x004c3a40-0x004c3a50` | UID0002TF local table | predecessor switch data | compiler-covered by UID0002TF | UID0000OC | source-ready peer | no target code | protected boundary |
| `0x004c3a50-0x004c3ce1` | UID0002TG target | RGB565 scaled RLE tint provider | true | UID0000OC Surface | 87/90 -> 92/94 | complete CPP; blank target H | implementation applied/verified |
| `0x004c3ce1-0x004c3cf0` | UID0000VN ignored | 15-byte alignment | compiler-generated padding | none | 100 | no code | protected boundary |
| `0x004c3cf0-0x004c3e93` | UID0002TH | next RGB565 alpha-lookup provider | true | UID0000OC | source-ready | no target change | protected neighbor |
| `0x004bdcc0-0x004bdf3e` | UID0002TC | compat/RGB555 paired provider | true | UID0000OC | 87/90 | shared contract updated; peer body remains separate | support update applied/verified |
| `0x00558690-0x0055883d` | UID00039V | callback initializer | true | UID0000OC | 91/93 | existing CPP preserved; exact slot-4 inventory applied | support update applied/verified |
| `0x0069b3f0-0x0069b3f4` logical slot | UID0000TN / UID0001PI | slot-4 semantic global and physical storage | true | UID0000OC | 94/95; 92/94 | semantic H/CPP additions applied; physical CPP stays covered-by | support update and Gate 2A metadata repair applied/verified |
| `0x0069b3d8` | lookup support | 5-bit color lookup root | true/support | UID0000OC | current | no target definition | protected dependency |
| `0x0069b3dc` | lookup support | 6-bit color lookup root | true/support | UID0000OC | current | no target definition | protected dependency |
| `0x006104b0` / `0x006104cc` | pooled constants | 0.5f / 32.0f | compiler-pooled literals | shared | current | use literals in source | protected no-change |

Inventory conclusion after the accepted callback and Gate 2A repair: the UID0002TG source-bearing target body and UID0000TN `SurfaceScaledRleTintProc` typedef, extern, and single definition are applied and physically verified. UID00039V carries the exact slot-4 inventory with compat/RGB565 retained refs `0x0055873b`/`0x00558829` and inline refs `0x00558ba8`/`0x00558ec4`; UID0001PI remains the non-emitting covered-by physical storage page at the dated report-freeze score `92/94`. No split, new child, duplicate physical data emitter, or new support type page is required. Final report-freeze generated command `000000023100` at `2026-08-13T07:10:45-04:00`, all nine ordinary scoped validator receipts `000000022926-000000022934`, retained coverage validator receipts `000000023009`, `000000023010`, `000000023044`, and `000000023043`, dated physical coverage rereads, and all nine manual-row no-change dispositions are reconciled. Commands `000000022761`, `000000022770`, `000000022920`, `000000022981`, `000000023008`, `000000023042`, `000000023051`, and `000000023099` are superseded generated-refresh evidence; commands `22921-22924`, `23011`, and `23012` are older coverage receipts. Only supervisor IDA actions/readback remain proposed. Lifecycle truth remains authoritative only from the report's actual path at read time and validator-owned status/history metadata, and every later gate must reread volatile generated/tracker/coverage state.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00558829` | initializer target ref | selects UID0002TG for RGB565 mode |
| `0x00558ec4` | inline/duplicate initializer target ref | selects UID0002TG in retained setup route |
| `0x004c3a79` | GrafPort GetClipRect callee | receiver is GrafPort and clipping precedes rendering |
| `0x004d7044`, `0x004d70e2`, `0x004d7685`, `0x004d7727` | slot reads | broad image/render consumers |
| `0x004d77c9`, `0x004d786b`, `0x004d790d`, `0x004d79af` | slot reads | broad image/render consumers |
| `0x004d7a4e`, `0x004d7ad4`, `0x004d7b75`, `0x004d7c1b`, `0x004d7cb9` | slot reads | broad image/render consumers |
| `0x004db310` | Monster render slot call | exact mode/tint/offset/scale/shear consumer |
| `0x004dc9fb` | Riding render slot call | exact mode/tint/offset/scale/shear consumer |
| `0x004e44f4`, `0x004e457f`, `0x004e4cf8` | slot reads in `sub_4E4280` | further shared dispatch evidence |
| `0x00558768` | slot-storage setup ref | shared `0x0069b3f0` storage route; not a provider target xref |
| `0x0055873b`, `0x00558ba8` | compat provider target refs | exact retained and inline assignments of `SoftwareRenderCompatScaledRleTintCallback` |
| `0x00558829`, `0x00558ec4` | RGB565 provider target refs | exact retained and inline assignments of `SoftwareRenderRgb565ScaledRleTintCallback` |
| no direct code xref to `0x004c3a50` | negative caller result | runtime invocation is through slot 4 |

The slot list totals twenty-one exact refs. The target itself has two direct target refs. Conflating those two populations is a documentation error.

## Documentation Evidence And IDA Status

- UID0002TG now preserves the exact bounds, body hash, control/data flow, constants, lookup refs, CFG size, padding, resolved receiver-plus-eight-argument contract, source-facing name, detailed behavior, ownership, score rationale, and complete formal CPP. Its target H remains intentionally blank because the provider is file-local. The former unresolved-signature/no-C++ wording is retained only as explicitly superseded pre-callback history.
- UID0000TN now contains the exact slot-4 `SurfaceScaledRleTintProc` typedef, `extern SurfaceScaledRleTintProc g_pfnBlitScaledRleTint`, and one CPP definition, together with the provider pair, caller set, const-normalized arguments, dispatch liveness, and source placement. Formal H/CPP closure is applied and physically verified rather than pending.
- UID00039V retains both exact formal assignment statements unchanged and now carries the exact slot-4 type, arguments, providers, retained/inlined assignment references, signed mask grammar, and ownership inventory. Its former generic inventory wording is superseded history.
- UID0002Y1 was physically reread and already supplies same-or-greater source-ready consumer calls and MapPane field semantics; no caller-page edit was required.
- EPFTileContext file/class docs now record UID0002TG's exact `encodedMaskBytes` signed-row use and no-source-pixel-read distinction. GrafPort class docs now record the target's read-only `m_drawEnabled`, `m_surfaceContext`, bounds, stride, and `GetClipRect` receiver dependency while preserving Surface ownership.
- The generated `Surface.cpp`/`Surface.h` snapshot inspected before callback witnessed an empty UID0002TG emitter and missing slot-4 declaration/definition; that evidence is historical only. Originating command `000000022403` first materialized the accepted closure. Commands `000000022761`, `000000022770`, `000000022920`, `000000022981`, `000000023008`, `000000023042`, `000000023051`, and `000000023099` are superseded historical refreshes. Final report-freeze validator command `000000023100` at `2026-08-13T07:10:45-04:00` was physically reread and contains one target item/body, zero target empty-emitter markers, one typedef, one extern, one definition, and one assignment to each provider under C2TG-073 through C2TG-081. This is dated evidence, not permanent generated-state authority.
- All nine manual coverage rows remain physically present at same-or-greater detail under C2TG-045 through C2TG-050 and C2TG-083 through C2TG-085; no edit or pruning is required. Commands `000000023009`, `000000023010`, `000000023044`, and `000000023043` are retained successful validation receipts under applied claims C2TG-070 through C2TG-072 and C2TG-082; dated physical rereads separately prove the rows remained present after later unrelated by-memory whole-file drift. Commands `22921` through `22924`, `23011`, and `23012` are older history. IDA remains unchanged by B008 and Section 21 remains a proposed supervisor handoff under C2TG-051 through C2TG-059; the separate lifecycle boundary remains prose-only, with current truth authoritative solely from the report's actual path at read time and validator-owned status/history metadata.
- Report-freeze physical by-* content preserves C2TG-001 through C2TG-044 at report-level detail. C2TG-065 retains exact command `000000021994`; the other nine original callback assertions remain historical, while commands `000000022926` through `000000022934` establish the dated ordinary-validation state. Sections 31-32 record the report-freeze hashes and successful coverage receipts without using generated/manual/IDA/lifecycle state to overstate those separate closure boundaries.

## Ranked Ownership Analysis

### 1. Surface / UID0000OC

- Evidence for: owns callback-table semantic globals, pixel-format initializer, compat/RGB565 providers, lookup roots, related formal types, and generated `render/Surface.cpp`; function has no feature-specific state.
- Evidence against: exact original source-unit boundary is inferred rather than symbol-proven.
- Decision: accepted with very strong confidence. The complete source architecture and sibling conventions outweigh lexical uncertainty.

### 2. GrafPort

- Evidence for: active receiver is `GrafPort *`; body reads GrafPort fields and calls `GetClipRect`.
- Evidence against: callback is selected and stored by Surface; sibling software providers are file-local Surface functions; no vtable/direct-member call route exists.
- Decision: dependency only. GrafPort docs should record receiver-field support, not own or emit the body.

### 3. RidingImageLib / MonsterImageLib / RankingEventListPane

- Evidence for: Riding and Monster are direct slot consumers; generated output once projected a RankingEventListPane method name.
- Evidence against: twenty-one slot refs, shared initializer, paired provider, and no target direct caller reject any one consumer as owner. Target uses no consumer-class fields.
- Decision: callers only. Preserve generated name as rejected history.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: none. Existing `NexusTK/render/Surface.cpp` is correct.
- Likely full contents: existing Surface callback globals, initializer, provider families, and helpers.
- Candidate related items that belong: UID0002TG target body and UID0000TN shared slot declaration/storage.
- Candidate related items rejected: caller classes, GrafPort member ownership, SoftwareBlend16, duplicate physical callback-table source.
- Standalone, narrow, or broad source-file inference: file-local narrow callback inside the existing broad Surface compilation unit.

## Source Placement

- Place the target definition in `Surface.cpp` at its existing exact-address child order after UID0002TF's local switch-table-covered function and before UID0002TH.
- Keep it `static` because no direct source-level external call targets the function; only the initializer takes its address.
- Put `SurfaceScaledRleTintProc` and `extern g_pfnBlitScaledRleTint` in `Surface.h` through semantic UID0000TN. Put the one global definition in `Surface.cpp` through the same semantic owner.
- Keep target H blank. A second declaration attached to UID0002TG would duplicate the private provider or expose an unnecessary symbol.
- Keep UID0001PI physical page non-emitting and covered-by UID0000TN to avoid duplicate storage.
- Reject GrafPort.cpp placement: receiver type does not determine callback provider ownership.
- Reject feature-file placement: broad slot fanout and initializer selection contradict caller ownership.

## Range / Split / Padding / Reclassification Analysis

- Exact target remains `[0x004c3a50,0x004c3ce1)`. No split is needed: one modeled function and one coherent source body occupy the entire range.
- Preceding `[0x004c3a40,0x004c3a50)` is the four-entry switch table of UID0002TF and must not be absorbed into UID0002TG.
- Following `[0x004c3ce1,0x004c3cf0)` is fifteen `0xcc` alignment bytes and remains ignored/compiler-generated.
- Next function starts exactly at `0x004c3cf0`; no tail bytes or shared epilogue cross the boundary.
- The callback-table slot is semantic UID0000TN storage physically indexed by UID0001PI. Do not create a new four-byte by-memory child or duplicate C++ definition.
- The pooled constants remain shared literal storage and need no reclassification or target ownership.
- Parent/container impact: update UID00016L inventory to source-ready child status while leaving its aggregate `RECONSTRUCTABLE:FALSE`, blank owner/emitter, and blank formal code.

## Negative Evidence Summary

- No direct code caller points to `0x004c3a50`; this supports indirect callback dispatch, not dead code.
- No target-specific use of source `pixelData` exists. The prior "combines source intensity" description is false.
- No `encodedMaskByteCount` reference exists in the target, so a checked decoder loop would alter behavior.
- No guard rejects zero/negative `verticalScale`; adding one is not justified by current callers or body.
- No source-bounds left/top stream seek exists; only width and row count are derived from source bounds.
- No evidence supports `RankingEventListPane`, Riding, Monster, GrafPort, or SoftwareBlend16 ownership.
- No evidence supports renaming shared pooled constants. Their many cross-function refs reject target-specific names.
- No evidence supports changing slot storage boundaries in this target. Current persisted copy exposes an accepted name/type but a one-byte physical head; unrelated storage materialization must not be coupled to the callback body.
- No original symbol proves exact lexical tokens. This caps confidence but does not justify decompiler labels or blank code.
- No compile/binary-diff receipt exists yet. This caps scores below 95/95 and is a post-documentation validation task, not a reason to leave the emitter empty.

## IDA Rename / Type / Comment Recommendations

All IDA changes are supervisor-owned and conditional on fresh reproduction of the literal target, frame, dependency, boundary, byte, comment, collision, and xref prestates below. The accepted recommendation is deliberately narrow: one function rename and two regular comments. The earlier function-type and stack rename/type plan is rejected because the report does not prove the exact deterministic physical frame it would create.

> Legacy session/attestation/backup/save/reopen orchestration and request-shaped actions were removed and preserved in [0002TG-SoftwareRenderRgb565ScaledRleTintCallback-empty-emitter-source-quality-removed.md](0002TG-SoftwareRenderRgb565ScaledRleTintCallback-empty-emitter-source-quality-removed.md). The archive is non-authoritative and must never be executed.

Dated witnesses reproduced the current stored signature, complete 27-row frame, blank target comment channels, exact boundaries, dependency types, and `2/21/12/11/60/37` xref counts. Those observations are research provenance only. The supervisor independently establishes current canonical identity and operational safety outside this report; any current-prestate mismatch or unexpected delta rejects the affected recommendation.

### Dated Literal Prestate And Required No-Type-Change Frame

Because no stack rename, stack type, or function type mutation is recommended, fresh Gate 2B must first reproduce every row below, which both read-only passes matched, and the deterministic required poststate is then exactly that reproduced matrix. There are no permitted name, type, offset, width, addition, or removal deltas. Every local, `outBounds`, saved-register row, return-address row, and argument is individually protected; any additional, missing, renamed, retyped, resized, or moved row cancels all actions before save.

| # | Current row | Offset | Width | Current type | Required poststate after A01-A03 |
| ---: | --- | ---: | ---: | --- | --- |
| 1 | `var_50` | `0x08` | 4 | `_DWORD` | identical |
| 2 | `var_4C` | `0x0c` | 4 | `_DWORD` | identical |
| 3 | `var_48` | `0x10` | 4 | `_DWORD` | identical |
| 4 | `var_44` | `0x14` | 4 | `_DWORD` | identical |
| 5 | `var_40` | `0x18` | 4 | `_DWORD` | identical |
| 6 | `var_3C` | `0x1c` | 4 | `_DWORD` | identical |
| 7 | `var_38` | `0x20` | 4 | `_DWORD` | identical |
| 8 | `var_34` | `0x24` | 4 | `_DWORD` | identical |
| 9 | `var_30` | `0x28` | 4 | `_DWORD` | identical |
| 10 | `var_2C` | `0x2c` | 4 | `_DWORD` | identical |
| 11 | `var_28` | `0x30` | 4 | `_DWORD` | identical |
| 12 | `var_24` | `0x34` | 4 | `_DWORD` | identical |
| 13 | `var_20` | `0x38` | 4 | `_DWORD` | identical |
| 14 | `var_1C` | `0x3c` | 4 | `_DWORD` | identical |
| 15 | `var_18` | `0x40` | 4 | `_DWORD` | identical |
| 16 | `outBounds` | `0x44` | 16 | `struct RectBounds` | identical |
| 17 | `var_4` | `0x54` | 4 | `_DWORD` | identical |
| 18 | `__saved_registers` | `0x58` | 4 | `_DWORD` | identical |
| 19 | `__return_address` | `0x5c` | 4 | `_UNKNOWN *` | identical |
| 20 | `arg_0` | `0x60` | 4 | `_DWORD` | identical |
| 21 | `arg_4` | `0x64` | 4 | `_DWORD` | identical |
| 22 | `arg_8` | `0x68` | 4 | `_DWORD` | identical |
| 23 | `arg_C` | `0x6c` | 1 | `_BYTE` | identical |
| 24 | `arg_10` | `0x70` | 4 | `_DWORD` | identical |
| 25 | `arg_14` | `0x74` | 4 | `_DWORD` | identical |
| 26 | `arg_18` | `0x78` | 4 | `_DWORD` | identical |
| 27 | `arg_1C` | `0x7c` | 4 | `_DWORD` | identical |

### Atomic Mutation Action Rows

| ID | Entity and literal current prestate | Proposed IDA outcome | Evidence | Expected readback | Safety and protected state |
| --- | --- | --- | --- | --- | --- |
| A01 | Function `0x004c3a50`: name `sub_4C3A50`; range `[0x004c3a50,0x004c3ce1)`; size `0x291`; stored signature `void __thiscall(const struct GrafPort *this, int, _DWORD *, int *, char, float, int, float, float)`; complete frame is exactly the 27 rows and offsets in the preceding no-type-change table; body SHA256 `CF941A937FF9CF24FA19A2421020BBE42B03FFBA9EDC02C00FAB427F6C68A6F7`; refs `0x00558829` and `0x00558ec4`; no code caller; address-regular absent; address-repeatable absent; function-regular absent; function-repeatable absent; proposed-name collision absent. | Declarative name-only function rename to `SoftwareRenderRgb565ScaledRleTintCallback` with `pure:true`; do not change the stored signature or frame. | Initializer and provider-family naming plus Surface ownership. | Exact new name; address-regular absent; address-repeatable absent; function-regular absent; function-repeatable absent; same range, size, signature, complete 27-row frame, bytes/hash, refs, and no code caller. | `pure:true` is mandatory. Name-only delta; no function-directory, decompiler/cache, type, frame, byte, xref, item, comment, predecessor-table, padding, or neighbor delta. |
| A02 | Function `0x004c3a50` after the accepted A01 stage: name `SoftwareRenderRgb565ScaledRleTintCallback`; range `[0x004c3a50,0x004c3ce1)`; size `0x291`; stored signature `void __thiscall(const struct GrafPort *this, int, _DWORD *, int *, char, float, int, float, float)`; complete frame is exactly the same 27 rows and offsets in the preceding no-type-change table; body SHA256 `CF941A937FF9CF24FA19A2421020BBE42B03FFBA9EDC02C00FAB427F6C68A6F7`; refs `0x00558829` and `0x00558ec4`; no code caller; address-regular absent; address-repeatable absent; function-regular absent; function-repeatable absent. | Declarative function-regular comment action with exact text `RGB565 slot-4 provider; clips and scales signed zero-delimited EPF mask rows, then tints existing destination pixels through 5/6-bit lookup tables.` No name, type, frame, address-comment, or repeatable-comment action is authorized. | Exact source role and body behavior. | Exact comment in function-regular only; address-regular absent; address-repeatable absent; function-repeatable absent; A01 name, range, size, signature, complete frame, body hash, refs, and no-caller state retained. | No address/repeatable comment, type, frame, name, item, decompiler/cache, or neighbor delta. Any different comment-channel effect rejects the action. |
| A03 | Padding data item at `0x004c3ce1`, exact range `[0x004c3ce1,0x004c3cf0)`, width 15, fifteen `CC` bytes, name absent, type absent; address-regular absent; address-repeatable absent; function-regular not applicable and function-repeatable not applicable because no function begins at the item; predecessor target ends exactly at `0x004c3ce1`; next function is `SoftwareRenderRgb565AlphaLookupBlitCallback`, range `[0x004c3cf0,0x004c3e93)`. | Declarative address-regular comment action with exact text `15-byte alignment between RGB565 scaled-RLE-tint and alpha-lookup callbacks.` No repeatable comment, name, type, item, code, or boundary action is authorized. | Exact alignment boundary. | Address-regular contains the exact text; address-repeatable absent; function comment channels remain not applicable; same item/range/width/fifteen `CC` bytes/name/type, predecessor boundary, and successor function identity. | Do not create code/name/type or alter bytes, boundaries, predecessor target, successor function, or any untargeted comment channel. Any materialized extra comment or other delta rejects the action. |

### Protected Dependency Readback Rows

These rows are read-only protection contracts, not mutation actions. Their literal prestates were reproduced by dated read-only passes and must be freshly reproduced before accepting any A-row outcome. No P row authorizes a rename, type, item-boundary, comment, or other IDA effect; any current mismatch rejects all active recommendations for that pass.

| ID | Protected entity/address | Literal current prestate | Evidence and no-action disposition | Required readback | Prohibited effects |
| --- | --- | --- | --- | --- | --- |
| P01 | callback slot `0x0069b3f0` | persisted item head `[0x0069b3f0,0x0069b3f1)`, width 1; `inspect_items` name blank while `entity_query names` maps `g_pfnBlitScaledRleTint`; type `SurfaceScaledRleTintProc`; regular/repeatable comments absent; exactly 21 refs at `0x004d7044,0x004d70e2,0x004d7685,0x004d7727,0x004d77c9,0x004d786b,0x004d790d,0x004d79af,0x004d7a4e,0x004d7ad4,0x004d7b75,0x004d7c1b,0x004d7cb9,0x004db310,0x004dc9fb,0x004e44f4,0x004e457f,0x004e4cf8,0x00558768,0x00558ba8,0x00558ec4` | current semantic identity is sufficient; storage materialization is unrelated; no action | same one-byte item head, blank inspect name, entity-name mapping, type, blank comments, and exact 21-ref set | No rename, resize, retype, materialize, comment, or other mutation |
| P02 | 5-bit lookup root `0x0069b3d8` | persisted item head `[0x0069b3d8,0x0069b3d9)`, width 1; `inspect_items` name blank while `entity_query names` maps `g_surfaceColorLookup5Bit`; type `unsigned __int8 **`; regular/repeatable comments absent; exactly 12 refs at `0x004bde35,0x004be04a,0x004bedf9,0x004c3bd6,0x004c3bf7,0x004c3e0b,0x004c4738,0x00556ab6,0x00556acf,0x00558c95,0x00558caa,0x00558cf7` | shared RGB lookup dependency; no action | same one-byte item head, blank inspect name, entity-name mapping, type, blank comments, and exact 12-ref set | No target-specific rename, resize, retype, materialize, comment, or other mutation |
| P03 | 6-bit lookup root `0x0069b3dc` | persisted item head `[0x0069b3dc,0x0069b3dd)`, width 1; `inspect_items` name blank while `entity_query names` maps `g_surfaceColorLookup6Bit`; type `unsigned __int8 **`; regular/repeatable comments absent; exactly 11 refs at `0x004bde4c,0x004be065,0x004bede3,0x004c3bc6,0x004c3dfc,0x004c4733,0x00556aec,0x00556b05,0x00558d24,0x00558d5a,0x00558da8` | shared RGB lookup dependency; no action | same one-byte item head, blank inspect name, entity-name mapping, type, blank comments, and exact 11-ref set | No target-specific rename, resize, retype, materialize, comment, or other mutation |
| P04 | pooled float `0x006104b0` | data item `[0x006104b0,0x006104b4)`, width 4; name `dword_6104B0`; type absent; bytes `00 00 00 3f` (`0.5f`); regular/repeatable comments absent; exactly 60 inbound refs | broadly shared compiler-pooled literal; use source literal `0.5f`; no action | exact same item/name/type/bytes/comments and 60-ref count | No rename, retype, resize, comment, or other mutation |
| P05 | pooled float `0x006104cc` | data item `[0x006104cc,0x006104d0)`, width 4; name `dword_6104CC`; type absent; bytes `00 00 00 42` (`32.0f`); regular/repeatable comments absent; exactly 37 inbound refs | broadly shared compiler-pooled literal; use source literal `32.0f`; no action | exact same item/name/type/bytes/comments and 37-ref count | No rename, retype, resize, comment, or other mutation |

### Rejected Historical Type And Frame Plan

The earlier stack-rename, stack-type, and function-`set_type` package is one superseded historical handoff, not a current action row. It is rejected because this read-only pass cannot prove the exact physical post-frame that IDA would install. The complete 27-row table above is therefore a literal no-change protection contract for A01-A03. Formal source still uses the inferred human argument names and types; no IDA type/frame implementation credit may be claimed.

The active Gate 2B mutation table contains exactly three actions: A01 function rename, A02 function regular comment, and A03 padding regular comment. P01-P05 are separately tabulated protected read-only dependencies and are not active actions. No active row asks the supervisor to infer a missing prestate or deterministic type-induced frame delta.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. This is a reconstructable, emitting, source-owned target above 85/85 with complete behavior and source contract.
- CPP block disposition: replace the blank target CPP with this exact formal insertion text.

```cpp
static void __thiscall SoftwareRenderRgb565ScaledRleTintCallback(
    GrafPort *port,
    const EPFTileContext *sourceContext,
    const RectBounds *sourceBounds,
    const RectBounds *destinationBounds,
    unsigned char mode,
    float tintAmount,
    int rowOffset,
    float verticalScale,
    float horizontalShear)
{
    if (!port->m_drawEnabled)
        return;

    RectBounds clipBounds;
    port->GetClipRect(&clipBounds);

    const int projectedRows = static_cast<int>(
        static_cast<float>(
            rowOffset + destinationBounds->bottom - destinationBounds->top) /
        verticalScale);
    int destinationY =
        destinationBounds->bottom - projectedRows + rowOffset - 2;
    float destinationXPosition = static_cast<float>(static_cast<int>(
        static_cast<float>(projectedRows) * horizontalShear +
        static_cast<float>(destinationBounds->left)));
    int destinationX = static_cast<int>(destinationXPosition);
    unsigned short *destinationRow =
        static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
        destinationX +
        port->m_surfaceContext.rowStridePixels *
            (destinationY - port->m_surfaceContext.bounds.top) -
        port->m_surfaceContext.bounds.left;

    if (mode != 3)
        return;

    const unsigned char tintStrength = static_cast<unsigned char>(
        static_cast<int>(tintAmount * 32.0f + 0.5f));
    const int sourceWidth = sourceBounds->right - sourceBounds->left;
    const int sourceRowCount = sourceBounds->bottom - sourceBounds->top;
    const signed char *encodedRow =
        reinterpret_cast<const signed char *>(
            sourceContext->encodedMaskBytes);
    float sourceRowPosition = 0.0f;
    int sourceRowsConsumed = 0;

    while (sourceRowsConsumed < sourceRowCount)
    {
        if (clipBounds.top <= destinationY &&
            destinationY < clipBounds.bottom)
        {
            const int clipLeft =
                clipBounds.left > destinationX
                    ? clipBounds.left
                    : destinationX;
            const int destinationRight = destinationX + sourceWidth;
            const int clipRight =
                clipBounds.right < destinationRight
                    ? clipBounds.right
                    : destinationRight;
            const signed char *run = encodedRow;
            int runX = destinationX;
            unsigned short *runPixels = destinationRow;

            while (*run != 0)
            {
                const int runLength =
                    static_cast<unsigned char>(*run) & 0x7f;

                if (*run < 0)
                {
                    const int writeLeft =
                        clipLeft > runX ? clipLeft : runX;
                    const int runRight = runX + runLength;
                    const int writeRight =
                        clipRight < runRight ? clipRight : runRight;
                    unsigned short *pixel =
                        runPixels + (writeLeft - runX);

                    for (int count = writeRight - writeLeft;
                         count > 0;
                         --count, ++pixel)
                    {
                        const unsigned short value = *pixel;
                        const unsigned int red =
                            g_surfaceColorLookup5Bit[value >> 11]
                                                     [tintStrength];
                        const unsigned int green =
                            g_surfaceColorLookup6Bit[(value >> 5) & 0x3f]
                                                     [tintStrength] & 0x3f;
                        const unsigned int blue =
                            g_surfaceColorLookup5Bit[value & 0x1f]
                                                     [tintStrength] & 0x1f;
                        *pixel = static_cast<unsigned short>(
                            (red << 11) | (green << 5) | blue);
                    }
                }

                runX += runLength;
                runPixels += runLength;
                ++run;
            }
        }

        destinationXPosition -= horizontalShear;
        ++destinationY;

        const float nextSourceRowPosition =
            sourceRowPosition + verticalScale;
        const int rowsToAdvance =
            static_cast<int>(nextSourceRowPosition + 0.5f) -
            static_cast<int>(sourceRowPosition + 0.5f);

        destinationX = static_cast<int>(destinationXPosition);
        destinationRow =
            static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
            destinationX +
            destinationY * port->m_surfaceContext.rowStridePixels;

        for (int row = 0; row < rowsToAdvance; ++row)
        {
            while (*encodedRow != 0)
                ++encodedRow;
            ++encodedRow;
        }

        sourceRowPosition = nextSourceRowPosition;
        sourceRowsConsumed += rowsToAdvance;
    }
}
```

- H block disposition for UID0002TG: keep blank. The static provider has no external declaration.
- UID0000TN formal H insertion after `SurfaceFillRleProc`:

```cpp
typedef void (__thiscall *SurfaceScaledRleTintProc)(
    GrafPort *port,
    const EPFTileContext *sourceContext,
    const RectBounds *sourceBounds,
    const RectBounds *destinationBounds,
    unsigned char mode,
    float tintAmount,
    int rowOffset,
    float verticalScale,
    float horizontalShear);

extern SurfaceScaledRleTintProc g_pfnBlitScaledRleTint;
```

- UID0000TN formal CPP insertion after `SurfaceFillRleProc g_pfnFillRle;`:

```cpp
SurfaceScaledRleTintProc g_pfnBlitScaledRleTint;
```

- Behavior fidelity: the code preserves setup-before-mode gating, signed token semantics, low-byte tint-strength conversion, clipped writes, row rounding, no stream-size guard, no scale guard, and the initial/later pointer asymmetry.
- Source shape: static Surface provider, typed callback global, ordinary named locals, accepted project structs, ternary clipping, and pre-modern C++ constructs fit the existing reconstructed Surface family and mid-2000s code style.
- Inferred names/types replacing IDA labels: all nine function parameters, source row/run locals, destination row/pixel locals, lookup roots, and Surface callback/global names.
- No third-party import applies.

## Final Recommendation

- C2TG-001 through C2TG-044 ordinary documentation, formal-source, support, metadata, and no-edit verification claims are applied and physically verified.
- Preserve C2TG-045 through C2TG-050 and C2TG-083 through C2TG-085 as same-or-greater rows at the dated report-freeze reread; do not replay the older replacement payloads or prune later accepted detail.
- C2TG-051 through C2TG-059 are declarative supervisor-owned IDA dispositions. Their accepted mutation subset is A01-A03 only, and every literal action/protection prestate and expected readback must agree before the supervisor grants credit.
- C2TG-060 through C2TG-069 scoped validation is complete through commands `000000022926` through `000000022934` plus retained Surface command `000000021994`. C2TG-070 through C2TG-072 and C2TG-082 retain successful coverage receipts `000000023009`, `000000023010`, `000000023044`, and `000000023043` plus dated physical row rereads; commands `22921` through `22924`, `23011`, and `23012` are older history. C2TG-073 through C2TG-081 are supported by final report-freeze validator command `000000023100` at `2026-08-13T07:10:45-04:00` and physical generated readback; command `000000022403` is originating history and commands `000000022761`/`000000022770`/`000000022920`/`000000022981`/`000000023008`/`000000023042`/`000000023051`/`000000023099` are superseded history. C2TG-072 validates both unchanged by-file rows and C2TG-082 validates both unchanged by-class rows. Every later gate must reread these volatile files before asserting then-current identity.
- Keep the target's owner/emitter/reconstructable state unchanged; only score, documentation, summary, and CPP change.
- Keep the target H blank and keep aggregate/physical pages non-emitting.
- No item remains no-owner. No split/new child is required.
- Future work outside this report: complete the compat/RGB555 peer's target-specific body and final compile/binary-diff validation. Those caps do not block UID0002TG source emission.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md`.
- Applied/verified: scores changed from `87/90` to `92/94`; owner/reconstructable/emitter/position stayed unchanged.
- Replace Item Summary with source-ready wording covering exact ABI, mask stream, scaling/shear, clipping, lookup transformation, two target refs, twenty-one slot refs, Surface ownership, complete CPP, and 15-byte alignment.
- Add source contract, exact behavior, projection/scaling formulas, signed run grammar, lookup semantics, registration/dispatch, touched typed fields, range/padding, ownership, source placement, score rationale, and exact behavior constraints at report-level detail.
- Populate CPP with Section 22's exact body. Keep H blank with the private-provider rationale.
- Preserve prior exact passes as historical evidence. Mark the generated RankingEventListPane name, source-intensity claim, unresolved-layout/signature blockers, and blank-C++ conclusion as superseded rather than silently erasing them.
- Add a dated B008 implementation history entry only during callback, describing before/after scores, exact evidence, formal source, support changes, IDA handoff status, and validators.

## Recommended Support Doc Changes

- `by-global/SurfaceRenderCallbackTable.md` UID0000TN: formal typedef/extern/definition and slot-4 provider state are applied; Gate 2A corrected the sole stale compat retained ref to exact `0x0055873b`; keep 94/95 and owner/emitter.
- `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` UID0001PI: slot-4 physical/semantic mapping is applied, current metadata/prose is reconciled to `92/94`, and covered-by CPP/no-duplicate-source disposition is preserved.
- `by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md` UID00039V: exact typedef, providers, and refs are already applied; current retained assignments `0x0055873b`/`0x00558829` and inline assignments `0x00558ba8`/`0x00558ec4` are preserved without rewriting formal CPP.
- `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md` UID00016L: mark UID0002TG source-ready in summary/inventory; keep aggregate non-reconstructable and formal blocks blank.
- `by-file/Surface.md` UID0000OC: incorporate callback contract, body ownership, support declaration/storage, and source order; keep current metadata/path.
- `by-memory/0x004bdcc0-0x004bdf3e.SoftwareRenderCompatScaledRleTintCallback.md` UID0002TC: replace shared ABI/layout/name blockers with resolved shared contract and comparative algorithm facts; keep peer CPP blank until its exact RGB555 body is independently finalized.
- `by-class/GrafPort.md` UID00005V: exact UID0002TG receiver dependency is applied and Gate 2A removed the unrelated slot-7 paragraph; the report-freeze support state cites only target `0x004c3a50`, slot 4, refs `0x00558829`/`0x00558ec4`, and the twenty-one-ref slot while retaining Surface ownership and unchanged class metadata/formal blocks.
- `by-file/EPFTileContext.md` UID0000J4 and `by-class/EPFTileContext.md` UID00004I: exact target use of `encodedMaskBytes`, signed row grammar, and no source-pixel read is applied with no layout/formal change.
- `by-memory/0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md`, MapPane, lookup-root pages, RectBounds, and UID000164: current docs already contain same-or-greater target-support facts; verify hashes/detail and make no edit unless drift is found.
- Generated files are read-only. They change only through validator refresh after source docs are accepted.

## Score And Metadata Recommendation

- Pre-callback target: `87/90`, owner `0000OC`, reconstructable true, emitter `0000OC`, blank position, blank CPP/H.
- Current physically verified target: `92/94`, same owner/reconstructable/emitter/position, complete CPP, blank H.
- Completion rises because the callback signature, parameter roles, EPFTileContext layout, source-facing name, exact behavior, source ownership, target CPP, shared callback declaration, current same-or-greater manual rows, and IDA handoff are now implementation-ready.
- Confidence rises because live current-IDB target/frame/bytes/xrefs, two independent consumers, initializer, paired provider, and accepted type docs agree.
- Reason not higher: original lexical names and const spelling are inferred; no compile/binary-diff receipt exists; supervisor IDA/save/readback remains a future gate; compat peer body remains incomplete. Scoped validation receipts and dated physical manual-row readbacks are reconciled. Generated source closure is proven at the final report-freeze snapshot under command `000000023100` at `2026-08-13T07:10:45-04:00`, with `000000022403` retained as originating history and `000000022761`/`000000022770`/`000000022920`/`000000022981`/`000000023008`/`000000023042`/`000000023051`/`000000023099` retained only as superseded historical refresh evidence. These are honest final-audit caps, not unresolved source blockers.
- Reason not lower: every former target-level blocker was actively resolved and the entire body can be represented without IDA labels or behavioral invention.
- Support score handling is unchanged except for correction of the report's stale UID0001PI assumption: the physical page was already `92/94`; Gate 2A reconciles prose and mirrors to that existing current metadata without claiming a new score raise.
- Metadata fields changed: only target completion/confidence and formal CPP. All routing fields remain unchanged.

## Open Questions With Attempted Resolution

- Original function spelling: no symbol survives. Initializer/family/project conventions and broad dispatch make `SoftwareRenderRgb565ScaledRleTintCallback` the highest-probability human name. This is resolved for source emission and remains a lexical confidence cap only.
- Const qualifiers: binary ABI cannot prove source const spelling, but all three input objects are read-only in this target and current project declarations use const pointers. Use const in source; this has no calling-convention or layout effect.
- Mode type: exact frame width is one byte and only value 3 is rendered. Use `unsigned char`, matching sibling callback style, rather than inventing an enum not established project-wide.
- Tint-strength overflow: body uses only the low byte after float-to-int conversion. Explicit unsigned-byte conversion preserves wrap; clamping would be wrong.
- Initial versus later destination pointer: rechecked as a real body asymmetry, not a decompiler simplification. Preserve it exactly; do not normalize.
- Source bounds offsets: the function uses width/height deltas but does not seek rows/columns from `left/top`. Preserve that behavior.
- Encoded-stream safety: no byte-count read occurs. Current callers supply valid EPF data; do not add a guard.
- Vertical-scale safety: no positive-scale validation occurs. Current callers provide positive scale; do not add a guard.
- Slot physical one-byte head: current persisted-copy inspection is insufficient reason to resize/materialize shared storage during this target. Preserve existing semantic name/type/xrefs and leave physical-boundary work outside this action set.
- Compat body: shared ABI/layout/name blockers are resolved, but exact RGB555 formal body remains outside UID0002TG and requires a peer-specific pass. It does not lower target source readiness.
- No target question remains unanswered in a way that blocks score improvement or C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The accepted payloads below are preserved verbatim as historical replacement authority, but retained successful validation receipts plus the dated final report-freeze physical reread prove they did not require an edit. At that reread the rows were at `by-memory/-coverage-report.md:1628,1648,1656,4817`, `by-global/-coverage-report.md:200`, `by-file/-coverage-report.md:85,275`, and `by-class/-coverage-report.md:188,237`. Each contained its accepted payload at same-or-greater detail, including later valid project work that must not be pruned. Commands `000000023009`, `000000023010`, `000000023044`, and `000000023043` remain dated successful validation receipts; by-memory's later whole-file drift is covered by the separate report-freeze physical reread rather than falsely assigned to command `23009`. Commands `22921` through `22924`, `23011`, and `23012` are older history. UID00039V still has no direct manual child row, so no insertion is justified. Generated tracker rows remain validator-owned and receive no manual text; command `000000023101` at `2026-08-13T07:11:17-04:00` is the dated final report-freeze tracker receipt, while commands `000000023099`, `000000023072`, and `000000023045` are historical. Dynamic reread, not any stored row number or command, controls every later gate.

1. Current no-change row `by-memory/-coverage-report.md:1656`; preserve this accepted payload as a required subset:

        - [UID:0002TG][0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback](by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md) 0x004c3a50-0x004c3ce1 | function | SoftwareRenderRgb565ScaledRleTintCallback : reconstructable : 92% : very-strong : Source-ready Surface slot-4 RGB565 scaled RLE tint callback with exact void GrafPort/EPFTileContext/sourceBounds/destinationBounds/mode/tint/row-offset/vertical-scale/horizontal-shear ABI, two initializer target refs, twenty-one slot refs, signed zero-delimited mask runs, exact clipping/projection/row-resampling behavior, 5/6-bit destination-pixel lookup transformation, clean 15-byte successor alignment, Surface ownership, and complete formal C++.

2. Current no-change row `by-global/-coverage-report.md:200`; preserve this accepted payload as a required subset:

- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) : reconstructable : 94% : very-strong : Semantic/source owner for twelve fixed Surface render callback globals; Surface.h owns typed declarations/externs and Surface.cpp owns single definitions, now including exact slot-4 SurfaceScaledRleTintProc g_pfnBlitScaledRleTint with void GrafPort/EPFTileContext/sourceBounds/destinationBounds/mode/tint/row-offset/vertical-scale/horizontal-shear ABI and source-ready RGB565 provider, plus exact slot-5 SurfaceAlphaLookupBlitProc g_pfnBlitAlphaLookup and its source-ready RGB565 provider; physical UID0001PI retains one non-emitting covered-by CPP comment and no duplicate physical declaration, definition, or provider body.

3. Current no-change row `by-file/-coverage-report.md:275`; preserve this accepted payload as a required subset:

- [UID:0000OC][Surface](by-file/Surface.md) : reconstructable : 90% : strong : Generated root NexusTK/render/Surface.cpp plus Surface.h callback declarations owns callback typedefs/definitions, initializer selection, pixel-format/lookup globals, software callback families, and true Surface helpers; slot 4 now has exact SurfaceScaledRleTintProc storage plus source-ready RGB565 scaled signed-RLE destination-tint provider and shared compat relationship, while slot 5 retains exact SurfaceAlphaLookupBlitProc storage plus source-ready RGB565 alpha-mask provider; unrelated callback-family work remains independently bounded.

4. Dated final report-freeze no-change row `by-memory/-coverage-report.md:4817`; preserve this accepted payload as a required subset:

    - [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md) 0x0069b3e0-0x0069b410 | function-pointer table | SurfaceRenderCallbackTable : reconstructable : 92% : very-strong : Twelve declaration-ordered zero-initialized Surface render callback globals with exact physical storage, initializer, and dispatch evidence; semantic UID0000TN emits the single Surface.h/Surface.cpp declaration-definition set, slot 4 now has exact SurfaceScaledRleTintProc storage plus a source-ready RGB565 scaled-RLE-tint provider, and slot 7 retains exact source-ready RGB555 compat/RGB565 rectangle-fill providers, while this physical page stays blank to prevent duplicate storage.

5. Current no-change row `by-memory/-coverage-report.md:1648`; preserve this accepted payload as a required subset:

    - [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md) 0x004c0770-0x004c5fde | function-family | SoftwareRenderRgb565Callbacks : not reconstructable : 90% : very-strong : Non-emitting RGB565 callback-family index over twelve exact Surface-owned source children; UID0002PI pixel, UID0002TF RLE fill, UID0002TG scaled RLE tint, UID0002TH alpha lookup, UID0002TI bitmask, and UID0002YK rectangle-fill callbacks are source-ready on exact child pages, while the aggregate remains blank and all unrelated child dispositions are preserved.

6. Current no-change row `by-memory/-coverage-report.md:1628`; preserve this accepted payload as a required subset:

        - [UID:0002TC][0x004bdcc0-0x004bdf3e.SoftwareRenderCompatScaledRleTintCallback](by-memory/0x004bdcc0-0x004bdf3e.SoftwareRenderCompatScaledRleTintCallback.md) 0x004bdcc0-0x004bdf3e | function | SoftwareRenderCompatScaledRleTintCallback : reconstructable : 87% : strong : Surface slot-4 compat/RGB555 peer with exact shared void GrafPort/EPFTileContext/sourceBounds/destinationBounds/mode/tint/row-offset/vertical-scale/horizontal-shear ABI, two initializer refs, twenty-one slot refs, signed zero-delimited mask traversal, clipping and rounded row resampling, and 5-bit destination-pixel lookup transformation; shared layout/name blockers are resolved, while peer-specific formal RGB555 body completion remains separate from the source-ready RGB565 child.

7. Current no-change row `by-class/-coverage-report.md:237`; preserve this exact accepted payload:

    - [UID:00005V][GrafPort](by-class/GrafPort.md) : reconstructable : 88% : very-strong : Core graphics-port class with exact surface/clip/draw/text children, inherited UID000161 GrafPort::GetBounds over m_visibleBounds +0x44, draw enable/mode at +0x71/+0x70, and canonical callback color fields m_drawColor +0x74 and m_textBackFillColor +0x78; UID0002TG's Surface-owned RGB565 scaled-RLE-tint callback uses GrafPort only as its receiver dependency through m_drawEnabled, m_surfaceContext pixelData/rowStridePixels/bounds, and GetClipRect, without moving provider ownership into GrafPort; broad UI/map/render receivers reject historical BackPane or callback-owner pollution while the broad class formal remains blank to avoid a lossy partial shell.

8. Current no-change row `by-file/-coverage-report.md:85`; preserve this exact accepted payload and its four-space indentation:

        - [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md) : reconstructable : 89% : strong : EPF tile-context render-support module with a Palette.h dependency for read-only consumption of DLPalette inclusive range records through the documented friendship, plus complete layout, lifecycle, normalization, and query routes; UID0002TG consumes encodedMaskBytes as signed zero-delimited mask rows, treats negative tokens as destination-transform spans and positive tokens as skips, and does not read source pixelData, while the provider remains Surface-owned.

9. Current no-change row `by-class/-coverage-report.md:188`; preserve this exact accepted payload and its four-space indentation:

        - [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) : reconstructable : 88% : very-strong : Exact 0x28 decoded tile-context value type emitted through `NexusTK/render/EPFTileContext.h`; its palette query consumes DLPalette inclusive range records through the documented friend relationship while palette storage and copy semantics remain DLPalette-owned; UID0002TG reads encodedMaskBytes as signed zero-delimited mask rows, uses negative tokens for destination-transform spans and positive tokens for skips, and never reads source pixelData, while the provider remains Surface-owned.

B008 did not apply these rows because all `-coverage-report.md` files are collision-prone supervisor-owned manual indexes. The current same-or-greater physical rows are credited only as read-only no-change dispositions; any future coverage edit remains supervisor-owned.

## Follow-Up Actions

- Completed: supervisor Gate 1 accepted SHA256 `AD8BC6397B51E959A081D0CDF30D44CA04C55A4D94734A114346FF91A7960DDF`.
- Completed report-freeze credit: C2TG-001 through C2TG-050 and C2TG-060 through C2TG-085 except C2TG-051 through C2TG-059. This includes ordinary implementation, retained Surface validation command `21994`, ordinary commands `22926-22934`, retained coverage receipts `23009`, `23010`, `23044`, and `23043`, the dated physical reread of nine same-or-greater manual rows, final report-freeze generation command `23100` at `2026-08-13T07:10:45-04:00`, and exact generated physical readback. Command `22403` remains originating history; commands `22761`, `22770`, `22920`, `22981`, `23008`, `23042`, `23051`, and `23099` are superseded refresh history; commands `22921-22924`, `23011`, and `23012` are older coverage receipts; commands `21842-21851`, `21893-21898`, `21900-21902`, and superseded Surface command `21899` remain historical callback assertions with no current proof credit.
- Primary-supervisor disposition: C2TG-051 through C2TG-059 remain pending declarative IDA recommendations, with only A01-A03 authorizing state changes. Gate validation, runtime control, persistence, and lifecycle handling are external supervisor responsibilities and are not prescribed by this report. No ordinary by-* edit, coverage edit, generated refresh, or additional scoped validator is currently requested.
- Validator-owned generated closure is proven by the dated final report-freeze command `000000023100` at `2026-08-13T07:10:45-04:00`, which preserves all six C2TG-074 through C2TG-079 outcomes from accepted formal source; command `000000022403` is the dated originating generation receipt and commands `000000022761`/`000000022770`/`000000022920`/`000000022981`/`000000023008`/`000000023042`/`000000023051`/`000000023099` are superseded historical refresh evidence.
- Generated verification passed: exactly one UID0002TG source item/body, no UID0002TG empty-emitter marker, exactly one `SurfaceScaledRleTintProc` typedef, one extern, one definition, and one assignment to each provider.
- Future B work outside this assignment: peer-specific UID0002TC RGB555 formal-body completion and eventual compile/binary-diff audit.
- B008 callback scope is complete. Further verification, execution, movement, and archive authority remains supervisor-owned and is authoritative only from the report's actual physical path at read time plus validator-owned status/history metadata; B008 never runs `execute_report` or performs lifecycle movement.

## Confidence

- Recommendation confidence: very strong. The source route, ABI, parameter roles, mask grammar, clipping/scaling algorithm, RGB565 transformation, and exact formal body are all independently supported.
- Score confidence: very strong for `92/94`. A lower score would ignore resolved source blockers; a score at or above 95 would overstate original lexical and compile/binary-diff certainty.
- Remaining uncertainty: original private lexical spelling, exact const tokens, and final compiler equivalence. None requires raw labels or blank C++.
- IDA-action confidence: very strong for the pure function rename and two comments when the supervisor confirms the current canonical target and exact action/protection prestates. The former stack/type plan is rejected because its physical post-frame was not proven; no-change confidence is exact for the current frame and strong-to-exact for the shared slot/LUT/constants.

## Validator Results

- Command form for each callback destination: `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240 --no-generated-refresh` from `source-3/project-documentation`.
- Historical receipt disposition: commands `000000021842` through `000000021851`, `000000021893` through `000000021898`, and `000000021900` through `000000021902` were asserted in earlier callback phases but are not retained as current independent proof. They remain historical assertions only and receive no current Gate 2A proof credit. Superseded Surface command `000000021899` likewise receives no current credit.
- C2TG-060 target UID0002TG: command `000000022926`, `2026-08-12T18:42:50-04:00`, exit `0`, `ok: 1`, generated skipped; SHA256 `45FEFE9E8C9426BF328C06A82C3A61C2CA75B83F4E91B8DDEB2C1E41F3815586`, 25,984 bytes, 290 lines.
- C2TG-061 semantic table UID0000TN: command `000000022927`, `2026-08-12T18:42:53-04:00`, exit `0`, `ok: 1`, generated skipped; three pre-existing UID0003XE warnings only; SHA256 `00EAF8EE3BE884D38810AAC003F3A652CBD1267421DA8947F399C5E3078FFD24`, 94,360 bytes, 553 lines.
- C2TG-062 physical table UID0001PI: command `000000022928`, `2026-08-12T18:42:56-04:00`, exit `0`, `ok: 1`, generated skipped; three pre-existing UID0003XE warnings only; current state `92/94`, SHA256 `4E63568215B41E93F0D076B37DBB70DE4A22EC8D79E279C3FCEAFE98BC18199B`, 78,679 bytes, 417 lines.
- C2TG-063 initializer UID00039V: command `000000022929`, `2026-08-12T18:42:59-04:00`, exit `0`, `ok: 1`, generated skipped, no warnings; SHA256 `CC7DC015E9A71BF88BE7BFD6566D74F00BD78C6A8F9E63B304F4BB15BD47785A`, 28,970 bytes, 241 lines.
- C2TG-064 RGB565 aggregate UID00016L: command `000000022930`, `2026-08-12T18:43:03-04:00`, exit `0`, `ok: 1`, generated skipped, no warnings; SHA256 `17FDC93B5559A59375FA6FF036887C3B5B8FF91F8A31AB4A4D1A5CBB6663C35A`, 50,980 bytes, 294 lines.
- C2TG-065 repaired Surface UID0000OC: fresh retained command `000000021994`, `2026-08-11T12:31:21-04:00`, exit `0`, `ok: 1`; twelve existing missing-UID00039R/UID0003XE reference warnings; generated refresh skipped. Command `000000021899` is superseded by this post-repair receipt and carries no current proof credit.
- C2TG-066 compat peer UID0002TC: command `000000022931`, `2026-08-12T18:43:06-04:00`, exit `0`, `ok: 1`, generated skipped, no warnings; SHA256 `A7B998198024E0F01A010F797B9C3FF6FB67D062554B8697C7DAE7A2282D0D15`, 23,466 bytes, 169 lines.
- C2TG-067 GrafPort UID00005V: command `000000022932`, `2026-08-12T18:43:09-04:00`, exit `0`, `ok: 1`, generated skipped; three pre-existing UID0003XE warnings only; SHA256 `AC82E83E26B726F7D60A553798ABC7FACB4674660E4F3B49293AAE50081C8E38`, 83,455 bytes, 534 lines.
- C2TG-068 EPFTileContext file UID0000J4: command `000000022933`, `2026-08-12T18:43:13-04:00`, exit `0`, `ok: 1`, generated skipped, no warnings; SHA256 `FE379E44538DD95CB5B0C958261E35FEF2CCBD342CF3D71FB16E20DD7D9A7981`, 20,744 bytes, 186 lines.
- C2TG-069 EPFTileContext class UID00004I: command `000000022934`, `2026-08-12T18:43:16-04:00`, exit `0`, `ok: 1`, generated skipped, no warnings; SHA256 `B05FEE57B247D44244E7E0CDC6EBD4616EBBB4D1E7561B0DFF9000D320958571`, 28,350 bytes, 254 lines.
- The historical callback commands reported `projected_stats_update: 1` and `stats_incremental_noop: 1`; those report assertions do not establish current validation or manual B008 tracker/stats edits.
- Coverage validation closure: commands `23009`, `23010`, `23044`, and `23043` are the retained successful validation identities. Exact dated physical hashes are recorded under C2TG-070 through C2TG-072/C2TG-082; commands `22921` through `22924`, `23011`, and `23012` are historical.
- Final report-freeze generated result under command `000000023100` at `2026-08-13T07:10:45-04:00`: target item/body present once, UID0002TG empty marker absent, typedef/extern/definition present once each, initializer assignments unchanged, and no target-specific source loss. Command `000000022403` remains dated originating history; commands `000000022761`, `000000022770`, `000000022920`, `000000022981`, `000000023008`, `000000023042`, `000000023051`, and `000000023099` are superseded historical refresh evidence.
- No scoped or coverage validator claim remains pending. C2TG-060 through C2TG-072/C2TG-082 and retained C2TG-065 have no unresolved validator error; only C2TG-051 through C2TG-059 remain supervisor-pending IDA work.

## Changed Files

- Modified additively: `tools/leaser/Agents/Agent-B008/research/0002TG-SoftwareRenderRgb565ScaledRleTintCallback-empty-emitter-source-quality.md`; the current cleanup retains declarative IDA prestates, intended outcomes, protections, and expected readbacks while removing operational runtime and persistence instructions to the inert companion.
- Historical callback snapshots, retained only as dated implementation history and not current validation proof:
  - `by-global/SurfaceRenderCallbackTable.md`: SHA256 `3F420BDE4006DAEE42FDEDCF4B81FEE7C7B274C8D582FB4F0AA6BA3AF4DA7EFA`, 91,811 bytes, 521 lines.
  - `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`: SHA256 `455C3196D31D1130E2295A642372006E755C29A031D0834545BFD6C21586DD2A`, 76,981 bytes, 409 lines.
  - `by-class/GrafPort.md`: SHA256 `0E3AD00B42BEA68FB19A893380976888981E6CB51381C82649433F0596F881B5`, 81,919 bytes, 526 lines.
- Report-freeze physical states after later additive work and successful scoped validation:
  - `by-global/SurfaceRenderCallbackTable.md`: SHA256 `00EAF8EE3BE884D38810AAC003F3A652CBD1267421DA8947F399C5E3078FFD24`, 94,360 bytes, 553 lines; current metadata `94/95`, owner/emitter `0000OC`, exact typedef/extern/definition retained.
  - `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`: SHA256 `4E63568215B41E93F0D076B37DBB70DE4A22EC8D79E279C3FCEAFE98BC18199B`, 78,679 bytes, 417 lines; current metadata `92/94`, owner/emitter `0000TN`, covered-by CPP retained and H blank.
  - `by-class/GrafPort.md`: SHA256 `AC82E83E26B726F7D60A553798ABC7FACB4674660E4F3B49293AAE50081C8E38`, 83,455 bytes, 534 lines; current metadata `88/90`, owner/emitter `0000JR`, target-specific slot-4 evidence retained.
- Report-freeze physical identities after successful scoped validation; C2TG-065 retains its separate command `000000021994`:
  - `by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md`: SHA256 `45FEFE9E8C9426BF328C06A82C3A61C2CA75B83F4E91B8DDEB2C1E41F3815586`, 25,984 bytes, 290 lines.
  - `by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md`: SHA256 `CC7DC015E9A71BF88BE7BFD6566D74F00BD78C6A8F9E63B304F4BB15BD47785A`, 28,970 bytes, 241 lines.
  - `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md`: SHA256 `17FDC93B5559A59375FA6FF036887C3B5B8FF91F8A31AB4A4D1A5CBB6663C35A`, 50,980 bytes, 294 lines.
  - `by-file/Surface.md`: SHA256 `C7E6AFD00B89B7C9D34E583B6560993DCB6D3F8A71C136F241D7034F7C495955`, 142,346 bytes, 614 lines; C2TG-030 exact RGB565 refs are present at lines 92/115/426 and command `000000021994` is the retained validator proof.
  - `by-memory/0x004bdcc0-0x004bdf3e.SoftwareRenderCompatScaledRleTintCallback.md`: SHA256 `A7B998198024E0F01A010F797B9C3FF6FB67D062554B8697C7DAE7A2282D0D15`, 23,466 bytes, 169 lines.
  - `by-file/EPFTileContext.md`: SHA256 `FE379E44538DD95CB5B0C958261E35FEF2CCBD342CF3D71FB16E20DD7D9A7981`, 20,744 bytes, 186 lines.
  - `by-class/EPFTileContext.md`: SHA256 `B05FEE57B247D44244E7E0CDC6EBD4616EBBB4D1E7561B0DFF9000D320958571`, 28,350 bytes, 254 lines.
- Verified no-edit support: `by-memory/0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md`, SHA256 `0416F08C76A96252D553BA2B253B465A01C42F9243F514F01F9EC3DA7C1799FA`, 17,262 bytes, 263 lines; exact typed `g_pfnBlitScaledRleTint` calls and MapPane semantics already present.
- Final report-freeze 2026-08-13 generated state: `auto-generated/NexusTK/render/Surface.cpp`, SHA256 `10801BE643882E7CB30D9749090E0D5215E44C2ADB2209939D2D1915FEF7A0E7`, 71,018 bytes, 2,120 LF lines; `Surface.h`, SHA256 `AE5B807D20E2F71167E5E68392DF8611429B306CB1C63EE01E6328C9B420FE67`, 3,087 bytes, 102 LF lines; both carry command `000000023100` at `2026-08-13T07:10:45-04:00` and passed the C2TG-074 through C2TG-081 cardinality/readback checks. Command `000000022403` remains originating history; commands `000000022761`, `000000022770`, `000000022920`, `000000022981`, `000000023008`, `000000023042`, `000000023051`, and `000000023099` are superseded history.
- Dated final report-freeze manual coverage identities after physical reread: by-memory SHA256 `44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681`, 2,211,023 bytes, 4,936 LF lines; by-global SHA256 `B689A8B252FB7D24C3CADEF6F410636BB4A3EE81D5AEBEB9D96F130700E91A9A`, 101,868 bytes, 219 LF lines; by-file SHA256 `02A44EDBAAA596D59ECE589D05E6BF57553C3DCA5AD7EAE0E1369C567344E756`, 169,241 bytes, 319 LF lines; and by-class SHA256 `FF87AEF9714FF85284A51ACDB1ADC7171395DD926C44D78260A7CF8074A232E0`, 277,113 bytes, 626 LF lines. All nine accepted rows were present at same-or-greater detail and remain unedited by B008. The immediately prior by-memory snapshot was SHA256 `D563B2D2DF4833B322D448CCC65BBE3421FE687E2B37D865A435AEAE1112F215`, 2,210,378 bytes, 4,935 LF lines. Commands `23009`, `23010`, `23044`, and `23043` are retained successful validation receipts, but only the separate dated physical reread is attributed to either later by-memory whole-file identity; commands `22921-22924`, `23011`, and `23012` are older snapshots.
- Created earlier and retained: `tools/leaser/Agents/Agent-B008/research/0002TG-SoftwareRenderRgb565ScaledRleTintCallback-empty-emitter-source-quality-removed.md`, an inert non-authoritative archive of removed operational material.
- Renamed: none.
- Manual `-coverage-report.md` files, generated output/trackers, IDA, goals, notes, audits/catalogs, and report lifecycle state were not manually modified by B008. Removed operational material is retained only in the linked sibling archive and receives no report credit. Scoped validator tool-owned registry/reference/projection side effects are reported in the receipts above.
- The report contains no executable PowerShell, Python, C#, JavaScript, batch, command, transaction, process-launcher, hostile-suite, or script-fixture body. Its only fenced source is the formal C++ recommendation required for CPP/H insertion.
- Report execution/archive status is supervisor-owned and authoritative only from the report's actual physical path at read time plus validator-owned status/history metadata. B008 does not run any execute, lifecycle, movement, or archive command.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C2TG-001 | 0002TG | Preserve exact target range 0x004c3a50-0x004c3ce1, size 0x291/657, 25 blocks, 212 instructions, and body SHA CF941A937FF9CF24FA19A2421020BBE42B03FFBA9EDC02C00FAB427F6C68A6F7. | exact | Actor/authority: B008 callback; dated 2026-08-12 canonical-path evidence and fresh 2026-08-13 bounded read-only reconciliation reproduced function metrics and bytes; current Gate 2B authority and prestate verification remain supervisor-owned | UID0002TG Address Range / IDA Evidence | incorporate | applied |
| [x] | C2TG-002 | 0002TG | Preserve two target data refs at 0x00558829 and 0x00558ec4 and no direct code callers. | exact | Actor/authority: B008 callback; dated 2026-08-12 canonical-path evidence and fresh 2026-08-13 bounded read-only reconciliation reproduced target xrefs; current Gate 2B authority and prestate verification remain supervisor-owned | UID0002TG IDA Evidence / Registration | incorporate | applied |
| [x] | C2TG-003 | 0002TG | Preserve all twenty-one slot refs and the distinction between target refs, slot dispatch, and setup refs. | exact | Actor/authority: B008 callback; dated 2026-08-12 canonical-path evidence and fresh 2026-08-13 bounded read-only reconciliation reproduced 0x0069b3f0 xrefs; current Gate 2B authority and prestate verification remain supervisor-owned | UID0002TG Dispatch Inventory | incorporate | applied |
| [x] | C2TG-004 | 0002TG | Replace the broad raw prototype prose with the logical void GrafPort receiver plus eight source arguments. | very strong | Actor/authority: B008 callback; Frame, decompile, callers, types, paired provider | UID0002TG Source Contract | incorporate | applied |
| [x] | C2TG-005 | 0002TG | Document EPFTileContext mask stream at +0x24 and signed zero-delimited row grammar. | exact | Actor/authority: B008 callback; Body and accepted EPFTileContext layout | UID0002TG Data Layout / Behavior | incorporate | applied |
| [x] | C2TG-006 | 0002TG | Document that negative runs transform existing destination RGB565 pixels and source pixelData is not read. | exact | Actor/authority: B008 callback; Target data flow | UID0002TG Behavior | incorporate | applied |
| [x] | C2TG-007 | 0002TG | Preserve the prior source-intensity-combination statement as a superseded historical assumption with the exact contradiction. | exact | Actor/authority: B008 callback; Target data flow rejects prior statement | UID0002TG Historical Assumptions | historicalize | applied |
| [x] | C2TG-008 | 0002TG | Document draw-enabled gate and GetClipRect call before projection and mode test. | exact | Actor/authority: B008 callback; Target control flow | UID0002TG Behavior | incorporate | applied |
| [x] | C2TG-009 | 0002TG | Document projected-row, destination-Y, and destination-X/shear formulas exactly. | exact | Actor/authority: B008 callback; Target float/integer data flow | UID0002TG Projection And Scaling | incorporate | applied |
| [x] | C2TG-010 | 0002TG | Preserve mode==3 gate after initial setup; do not hoist it earlier. | exact | Actor/authority: B008 callback; Target branch order | UID0002TG Exact Behavior Constraints | incorporate | applied |
| [x] | C2TG-011 | 0002TG | Document tint strength as low byte of int(tintAmount*32.0f+0.5f), including wrap semantics. | exact | Actor/authority: B008 callback; Constants, conversion, byte use | UID0002TG Tint Tables | incorporate | applied |
| [x] | C2TG-012 | 0002TG | Document clipping and negative/positive run handling with token length token&0x7f. | exact | Actor/authority: B008 callback; Inner row loop | UID0002TG RLE And Clipping | incorporate | applied |
| [x] | C2TG-013 | 0002TG | Document 5/6/5 lookup transformation and exact RGB565 reassembly. | exact | Actor/authority: B008 callback; LUT refs and masks | UID0002TG Tint Tables | incorporate | applied |
| [x] | C2TG-014 | 0002TG | Preserve rounded vertical-scale accumulator and whole-row delimiter skipping. | exact | Actor/authority: B008 callback; Outer loop data flow | UID0002TG Projection And Scaling | incorporate | applied |
| [x] | C2TG-015 | 0002TG | Preserve initial origin-adjusted destination pointer and later origin-unadjusted row-pointer recomputation. | exact | Actor/authority: B008 callback; Target pointer expressions | UID0002TG Exact Behavior Constraints | incorporate | applied |
| [x] | C2TG-016 | 0002TG | Preserve absence of encodedMaskByteCount check and verticalScale guard; do not add defensive behavior. | exact | Actor/authority: B008 callback; Negative body checks | UID0002TG Negative Evidence / C++ rationale | incorporate | applied |
| [x] | C2TG-017 | 0002TG | Preserve preceding 16-byte switch table and following 15 CC-byte alignment with next function at 0x004c3cf0. | exact | Actor/authority: B008 callback; Boundary bytes/items | UID0002TG Range / Padding | incorporate | applied |
| [x] | C2TG-018 | 0002TG | Use SoftwareRenderRgb565ScaledRleTintCallback as the source-facing name. | very strong | Actor/authority: B008 callback; Initializer, family style, broad consumers | UID0002TG Naming | incorporate | applied |
| [x] | C2TG-019 | 0002TG | Reject RankingEventListPane, caller-biased, and raw sub_4C3A50 names as stale source identities. | very strong | Actor/authority: B008 callback; Initializer, family style, broad consumers | UID0002TG Historical Naming | reject-stale | applied |
| [x] | C2TG-020 | 0002TG | Retain Surface UID0000OC as owner and emitter route. | very strong | Actor/authority: B008 callback; Storage, initializer, providers, consumers | UID0002TG Ownership | incorporate | applied |
| [x] | C2TG-021 | 0002TG | Preserve GrafPort, Riding, Monster, SoftwareBlend16, and feature-pane ownership candidates as rejected historical alternatives. | very strong | Actor/authority: B008 callback; Storage and broad consumer evidence | UID0002TG Ownership History | historicalize | applied |
| [x] | C2TG-022 | 0002TG | Populate target formal CPP with the exact file-local callback body from Section 22. | very strong | Actor/authority: B008 callback; Full target reconstruction | UID0002TG RECONSTRUCTION_CPP | incorporate | applied |
| [x] | C2TG-023 | 0002TG | Keep target formal H blank because the provider is private and shared declaration belongs to UID0000TN. | very strong | Actor/authority: B008 callback; Source placement and sibling convention | UID0002TG RECONSTRUCTION_H | already-present | already-present |
| [x] | C2TG-024 | 0000TN | Add SurfaceScaledRleTintProc typedef with exact receiver and eight arguments. | very strong | Actor/authority: B008 callback; Slot, callers, target, paired provider | UID0000TN RECONSTRUCTION_H / slot 4 typedef | incorporate | applied |
| [x] | C2TG-025 | 0000TN | Add extern SurfaceScaledRleTintProc g_pfnBlitScaledRleTint. | very strong | Actor/authority: B008 callback; Slot storage and project convention | UID0000TN RECONSTRUCTION_H / slot 4 extern | incorporate | applied |
| [x] | C2TG-026 | 0000TN | Add one SurfaceScaledRleTintProc g_pfnBlitScaledRleTint definition. | very strong | Actor/authority: B008 callback; Physical slot and semantic ownership | UID0000TN RECONSTRUCTION_CPP / slot 4 definition | incorporate | applied |
| [x] | C2TG-027 | 00039V | Preserve exact slot-4 initializer inventory with retained compat/RGB565 refs `0x0055873b`/`0x00558829` and inline refs `0x00558ba8`/`0x00558ec4`. | very strong | Actor/authority: B008 callback; Existing formal initializer plus four-way by-* address recheck | UID00039V Slot Inventory | incorporate | applied |
| [x] | C2TG-028 | 0001PI | Preserve physical slot-4 prose with exact provider assignment refs and non-emitting covered-by disposition while reconciling current physical metadata to 92/94. | very strong | Actor/authority: B008 callback; Slot location, semantic owner, provider pair, physical header | UID0001PI Slot Inventory / metadata | incorporate | applied |
| [x] | C2TG-029 | 00016L | Mark UID0002TG source-ready in the RGB565 family inventory while keeping aggregate non-reconstructable and blank. | very strong | Actor/authority: B008 callback; Exact child body and aggregate policy | UID00016L Inventory / Summary | incorporate | applied |
| [x] | C2TG-030 | 0000OC | Preserve exact slot-4 declaration, provider-body ownership, source order, and compat/RGB565 assignment refs `0x0055873b`/`0x00558ba8` and `0x00558829`/`0x00558ec4`. | very strong | Actor/authority: B008 callback; Surface lines 92/115/426; SHA256 C7E6AFD00B89B7C9D34E583B6560993DCB6D3F8A71C136F241D7034F7C495955 | by-file/Surface UID0002TG support | incorporate | applied |
| [x] | C2TG-031 | 0002TC | Preserve the resolved shared ABI, parameter contract, comparative RGB555/RGB565 algorithm facts, and exact compat target refs `0x0055873b`/`0x00558ba8`. | strong | Actor/authority: B008 callback; Target, paired-provider, and current xref comparison | UID0002TC Source Contract | incorporate | applied |
| [x] | C2TG-032 | 0002TC | Preserve the former shared ABI/layout/name blockers as superseded history while retaining the peer-specific blank-CPP cap. | strong | Actor/authority: B008 callback; Target resolves shared blockers but not peer body | UID0002TC Historical Assumptions | historicalize | applied |
| [x] | C2TG-033 | 00005V | Keep UID0002TG GrafPort support strictly target-specific: read-only receiver fields, GetClipRect, target `0x004c3a50`, slot 4, refs `0x00558829`/`0x00558ec4`, and twenty-one slot refs; exclude unrelated slot-7 fill evidence. | very strong | Actor/authority: B008 callback; GrafPort layout, target accesses, initializer, and slot-4 refs | by-class/GrafPort UID0002TG support | incorporate | applied |
| [x] | C2TG-034 | 0000J4 | Add target-specific encodedMaskBytes use, signed row grammar, and no-source-pixel-read distinction. | exact | Actor/authority: B008 callback; EPFTileContext layout and target data flow | by-file/EPFTileContext UID0002TG support | incorporate | applied |
| [x] | C2TG-035 | 00004I | Add target-specific encodedMaskBytes use, signed row grammar, and no-source-pixel-read distinction. | exact | Actor/authority: B008 callback; EPFTileContext layout and target data flow | by-class/EPFTileContext UID0002TG support | incorporate | applied |
| [x] | C2TG-036 | 0002Y1 | Keep the existing source-ready Riding consumer call and MapPane parameter semantics unchanged. | very strong | Actor/authority: B008 callback; Current Riding documentation already has same-or-greater detail | UID0002Y1 Target Support | already-present | already-present |
| [x] | C2TG-037 | 0002TG | Raise target metadata from 87/90 to 92/94. | very strong | Actor/authority: B008 callback; Resolved source blockers and remaining audit caps | UID0002TG completion/confidence | incorporate | applied |
| [x] | C2TG-038 | 0002TG | Keep CANONICAL_OWNER 0000OC, RECONSTRUCTABLE TRUE, EMITTER_UIDS 0000OC, and blank position unchanged. | exact | Actor/authority: B008 callback; Existing route remains correct | UID0002TG routing metadata | already-present | already-present |
| [x] | C2TG-039 | 0000TN | Keep support metadata 94/95 unchanged. | strong | Actor/authority: B008 callback; Broader table caps remain | UID0000TN metadata | already-present | already-present |
| [x] | C2TG-040 | 0001PI | Reconcile all current support metadata mirrors to the physical page's existing 92/94 without changing owner/emitter, reconstructable state, or covered-by source disposition. | strong | Actor/authority: B008 callback; Physical UID0001PI header and current page reread | UID0001PI metadata / current-state prose | incorporate | applied |
| [x] | C2TG-041 | 00039V | Keep support metadata 91/93 unchanged. | strong | Actor/authority: B008 callback; Initializer broader caps remain | UID00039V metadata | already-present | already-present |
| [x] | C2TG-042 | 00016L | Keep support metadata 90/92 unchanged. | strong | Actor/authority: B008 callback; Aggregate remains non-reconstructable | UID00016L metadata | already-present | already-present |
| [x] | C2TG-043 | 0000OC | Keep support metadata 90/89 and current reconstruction path unchanged. | strong | Actor/authority: B008 callback; Broader Surface source-boundary caps remain | UID0000OC metadata | already-present | already-present |
| [x] | C2TG-044 | 0002TC | Keep support metadata 87/90 unchanged. | strong | Actor/authority: B008 callback; Peer-specific body remains incomplete | UID0002TC metadata | already-present | already-present |
| [x] | C2TG-045 | 0002TG | Preserve the same-or-greater manual target row; no replacement or pruning is required. | exact | Actor/authority: Primary supervisor no-change disposition; dated command 23009 passed against the earlier coverage identity, while the final report-freeze physical reread proves row line 1656 under SHA256 44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681 contains the Section 28 payload plus retained later detail; intermediate SHA256 D563B2D2DF4833B322D448CCC65BBE3421FE687E2B37D865A435AEAE1112F215 and command 22921 are history. | by-memory/-coverage-report.md line 1656 | already-present | already-present |
| [x] | C2TG-046 | 0000TN | Preserve the current same-or-greater semantic-table manual row with slot-4/slot-5 closure; no replacement is required. | exact | Actor/authority: Primary supervisor no-change disposition; current by-global coverage command 23010 passed at 2026-08-12T22:49:34-04:00, and row line 200 under SHA256 B689A8B252FB7D24C3CADEF6F410636BB4A3EE81D5AEBEB9D96F130700E91A9A contains the Section 28 payload plus retained later slot detail; command 22922 is historical. | by-global/-coverage-report.md line 200 | already-present | already-present |
| [x] | C2TG-047 | 0000OC | Preserve the current same-or-greater Surface manual row with slot-4/slot-5 closure; no replacement is required. | exact | Actor/authority: Primary supervisor no-change disposition; current by-file coverage command 23044 and physical reread prove row line 275 under SHA256 02A44EDBAAA596D59ECE589D05E6BF57553C3DCA5AD7EAE0E1369C567344E756 contains the Section 28 payload plus retained later detail; commands 22923 and 23011 are historical. | by-file/-coverage-report.md line 275 | already-present | already-present |
| [x] | C2TG-048 | 0001PI | Preserve the same-or-greater physical-table row with 92% metadata, source-ready slot-4 detail, and unchanged owner/emitter/covered-by disposition. | exact | Actor/authority: Primary supervisor no-change disposition; dated command 23009 passed against the earlier coverage identity, while the final report-freeze physical reread proves row line 4817 under SHA256 44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681 contains the Section 28 payload plus retained later slot detail; intermediate SHA256 D563B2D2DF4833B322D448CCC65BBE3421FE687E2B37D865A435AEAE1112F215 and command 22921 are history. | by-memory/-coverage-report.md line 4817 | already-present | already-present |
| [x] | C2TG-049 | 00016L | Preserve the same-or-greater RGB565 aggregate row including source-ready UID0002TG and unchanged aggregate disposition. | exact | Actor/authority: Primary supervisor no-change disposition; dated command 23009 passed against the earlier coverage identity, while the final report-freeze physical reread proves row line 1648 under SHA256 44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681 contains the Section 28 payload plus retained later child detail; intermediate SHA256 D563B2D2DF4833B322D448CCC65BBE3421FE687E2B37D865A435AEAE1112F215 and command 22921 are history. | by-memory/-coverage-report.md line 1648 | already-present | already-present |
| [x] | C2TG-050 | 0002TC | Preserve the same-or-greater compat-peer row with resolved shared contract and explicit peer-body cap. | exact | Actor/authority: Primary supervisor no-change disposition; dated command 23009 passed against the earlier coverage identity, while the final report-freeze physical reread proves row line 1628 under SHA256 44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681 contains the Section 28 payload plus retained later body evidence; intermediate SHA256 D563B2D2DF4833B322D448CCC65BBE3421FE687E2B37D865A435AEAE1112F215 and command 22921 are history. | by-memory/-coverage-report.md line 1628 | already-present | already-present |
| [ ] | C2TG-051 | 0002TG | Apply A01 pure name-only function rename after exact canonical range/type/frame/collision and four-channel comment prestate verification; require all four comment channels unchanged and no function-directory or decompiler-refresh/cache side effect. | very strong | Actor/authority: Primary supervisor; declarative A01 prestate, intended state, protections, and expected readback | Canonical IDB function 0x004c3a50 | incorporate | proposed |
| [ ] | C2TG-052 | 0002TG | Apply A02 exact function-regular comment while preserving the address-regular, address-repeatable, and function-repeatable channels. | exact | Actor/authority: Primary supervisor; declarative A02 prestate, intended state, protections, and expected readback | Canonical IDB function comment 0x004c3a50 | incorporate | proposed |
| [ ] | C2TG-053 | 0002TG | Apply A03 exact padding regular comment without changing the 15-byte item. | exact | Actor/authority: Primary supervisor; declarative A03 prestate, intended state, protections, and expected readback | Canonical IDB address comment 0x004c3ce1 | incorporate | proposed |
| [ ] | C2TG-054 | 0002TG | Reject the prior stack rename/type and function set_type plan because no deterministic physical post-frame was proven. | exact safety disposition | Actor/authority: Primary supervisor; complete dated literal frame and report-only evidence limit | Canonical IDB type/frame handoff | reject-stale | proposed |
| [ ] | C2TG-055 | 0000TN | Preserve callback slot 0x0069b3f0 item, name, type, comments, and exact 21-ref set without mutation. | exact | Actor/authority: Primary supervisor; declarative P01 protected state and expected readback | Canonical IDB slot 0x0069b3f0 | already-present | proposed |
| [ ] | C2TG-056 | 0002TG | Preserve 5-bit lookup root 0x0069b3d8 item, name, type, comments, and exact 12-ref set without mutation. | exact | Actor/authority: Primary supervisor; declarative P02 protected state and expected readback | Canonical IDB lookup root 0x0069b3d8 | already-present | proposed |
| [ ] | C2TG-057 | 0002TG | Preserve 6-bit lookup root 0x0069b3dc item, name, type, comments, and exact 11-ref set without mutation. | exact | Actor/authority: Primary supervisor; declarative P03 protected state and expected readback | Canonical IDB lookup root 0x0069b3dc | already-present | proposed |
| [ ] | C2TG-058 | 0002TG | Preserve pooled 0.5f item 0x006104b0, bytes, name, absent type/comments, and 60-ref count without mutation. | exact | Actor/authority: Primary supervisor; declarative P04 protected state and expected readback | Canonical IDB pooled constant 0x006104b0 | already-present | proposed |
| [ ] | C2TG-059 | 0002TG | Preserve pooled 32.0f item 0x006104cc, bytes, name, absent type/comments, and 37-ref count without mutation. | exact | Actor/authority: Primary supervisor; declarative P05 protected state and expected readback | Canonical IDB pooled constant 0x006104cc | already-present | proposed |
| [x] | C2TG-060 | 0002TG | Preserve the successful fresh scoped validation and physical reread of the target page; historical commands 000000021842 and 000000021896 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022926 at 2026-08-12T18:42:50-04:00, exit 0, ok 1, generated skipped; physical SHA256 45FEFE9E8C9426BF328C06A82C3A61C2CA75B83F4E91B8DDEB2C1E41F3815586, 25,984 bytes, 290 lines. | by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md | incorporate | applied |
| [x] | C2TG-061 | 0000TN | Preserve the successful fresh scoped validation and physical reread of the semantic callback-table page; historical commands 000000021843 and 000000021894 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022927 at 2026-08-12T18:42:53-04:00, exit 0, ok 1, generated skipped; three pre-existing UID0003XE warnings only; physical SHA256 00EAF8EE3BE884D38810AAC003F3A652CBD1267421DA8947F399C5E3078FFD24, 94,360 bytes, 553 lines. | by-global/SurfaceRenderCallbackTable.md | incorporate | applied |
| [x] | C2TG-062 | 0001PI | Preserve the successful fresh scoped validation and physical reread of the 92/94 physical callback-table page; historical commands 000000021844 and 000000021895 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022928 at 2026-08-12T18:42:56-04:00, exit 0, ok 1, generated skipped; three pre-existing UID0003XE warnings only; physical SHA256 4E63568215B41E93F0D076B37DBB70DE4A22EC8D79E279C3FCEAFE98BC18199B, 78,679 bytes, 417 lines. | by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md | incorporate | applied |
| [x] | C2TG-063 | 00039V | Preserve the successful fresh scoped validation and physical reread of the initializer page; historical commands 000000021845 and 000000021897 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022929 at 2026-08-12T18:42:59-04:00, exit 0, ok 1, generated skipped, no warnings; physical SHA256 CC7DC015E9A71BF88BE7BFD6566D74F00BD78C6A8F9E63B304F4BB15BD47785A, 28,970 bytes, 241 lines. | by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md | incorporate | applied |
| [x] | C2TG-064 | 00016L | Preserve the successful fresh scoped validation and physical reread of the RGB565 aggregate page; historical commands 000000021846 and 000000021898 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022930 at 2026-08-12T18:43:03-04:00, exit 0, ok 1, generated skipped, no warnings; physical SHA256 17FDC93B5559A59375FA6FF036887C3B5B8FF91F8A31AB4A4D1A5CBB6663C35A, 50,980 bytes, 294 lines. | by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md | incorporate | applied |
| [x] | C2TG-065 | 0000OC | Freshly validate and physically reread the C2TG-030 Surface repair with retained command 000000021994; historical commands 000000021847 and superseded 000000021899 carry no current proof credit. | exact receipt | Actor/authority: B008 callback; Command 000000021994, 2026-08-11T12:31:21-04:00, exit 0, ok 1 | by-file/Surface.md | incorporate | applied |
| [x] | C2TG-066 | 0002TC | Preserve the successful fresh scoped validation and physical reread of the compat peer page; historical commands 000000021848 and 000000021900 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022931 at 2026-08-12T18:43:06-04:00, exit 0, ok 1, generated skipped, no warnings; physical SHA256 A7B998198024E0F01A010F797B9C3FF6FB67D062554B8697C7DAE7A2282D0D15, 23,466 bytes, 169 lines. | by-memory/0x004bdcc0-0x004bdf3e.SoftwareRenderCompatScaledRleTintCallback.md | incorporate | applied |
| [x] | C2TG-067 | 00005V | Preserve the successful fresh scoped validation and physical reread of the target-specific GrafPort section; historical commands 000000021849 and 000000021893 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022932 at 2026-08-12T18:43:09-04:00, exit 0, ok 1, generated skipped; three pre-existing UID0003XE warnings only; physical SHA256 AC82E83E26B726F7D60A553798ABC7FACB4674660E4F3B49293AAE50081C8E38, 83,455 bytes, 534 lines. | by-class/GrafPort.md | incorporate | applied |
| [x] | C2TG-068 | 0000J4 | Preserve the successful fresh scoped validation and physical reread of the EPFTileContext file page; historical commands 000000021850 and 000000021901 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022933 at 2026-08-12T18:43:13-04:00, exit 0, ok 1, generated skipped, no warnings; physical SHA256 FE379E44538DD95CB5B0C958261E35FEF2CCBD342CF3D71FB16E20DD7D9A7981, 20,744 bytes, 186 lines. | by-file/EPFTileContext.md | incorporate | applied |
| [x] | C2TG-069 | 00004I | Preserve the successful fresh scoped validation and physical reread of the EPFTileContext class page; historical commands 000000021851 and 000000021902 carry no current proof credit. | exact current receipt | Actor/authority: B008 same-report Gate 2A repair; command 000000022934 at 2026-08-12T18:43:16-04:00, exit 0, ok 1, generated skipped, no warnings; physical SHA256 B05FEE57B247D44244E7E0CDC6EBD4616EBBB4D1E7561B0DFF9000D320958571, 28,350 bytes, 254 lines. | by-class/EPFTileContext.md | incorporate | applied |
| [x] | C2TG-070 | 0002TG | Preserve the successful dated by-memory manual-page validation receipt and final report-freeze physical readback proving all four UID0002TG-related rows remained unchanged at same-or-greater detail. | exact receipt and dated physical readback | Actor/authority: B008 read-only verification; command 23009 at 2026-08-12T22:49:14-04:00 exited 0/ok 1 with generated skipped against prior SHA256 BD69D1C1B92DD2840D1D91DA909725366B9538051472A91D25DF1EB884E98F1C; intermediate snapshot SHA256 D563B2D2DF4833B322D448CCC65BBE3421FE687E2B37D865A435AEAE1112F215 is history; final report-freeze SHA256 44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681, 2,211,023 bytes, 4,936 LF lines, retained physical rows 1628/1648/1656/4817 with all accepted payloads; command 22921 is older history. | by-memory/-coverage-report.md | incorporate | applied |
| [x] | C2TG-071 | 0000TN | Preserve successful current validation of the by-global manual page after its same-or-greater UID0000TN row was confirmed unchanged. | exact current receipt | Actor/authority: B008 current read-only validation; command 23010 at 2026-08-12T22:49:34-04:00, exit 0, ok 1, generated skipped, no content/hash change; SHA256 B689A8B252FB7D24C3CADEF6F410636BB4A3EE81D5AEBEB9D96F130700E91A9A, 101,868 bytes, 219 lines; only pre-existing UID0003MS warning; command 22922 is historical. | by-global/-coverage-report.md | incorporate | applied |
| [x] | C2TG-072 | 0000OC | Preserve successful dated validation of the by-file manual page after both same-or-greater Surface and EPFTileContext rows were confirmed unchanged. | exact dated receipt | Actor/authority: Primary-supervisor Gate 2A receipt and B008 report-freeze physical reread; command 23044 is the retained successful no-generated-refresh validation identity; SHA256 02A44EDBAAA596D59ECE589D05E6BF57553C3DCA5AD7EAE0E1369C567344E756, 169,241 bytes, 319 lines at that reread; commands 22923 and 23011 are historical; every later gate must reread the file. | by-file/-coverage-report.md | incorporate | applied |
| [x] | C2TG-073 | 0002TG | Preserve the coherent final report-freeze validator-owned generated refresh under command 000000023100 while retaining 000000022403 as dated originating UID0002TG generation history and 000000022761/000000022770/000000022920/000000022981/000000023008/000000023042/000000023051/000000023099 as superseded refresh history. | exact | Actor/authority: Validator; generated headers physically reread on 2026-08-13 record command 000000023100 at 2026-08-13T07:10:45-04:00; Surface.cpp/Surface.h share that dated report-freeze authority. | Validator generated-refresh result | already-present | already-present |
| [x] | C2TG-074 | 0002TG | Preserve exactly one UID0002TG target item/body in generated Surface.cpp. | exact | Actor/authority: Validator; final report-freeze Surface.cpp SHA256 10801BE643882E7CB30D9749090E0D5215E44C2ADB2209939D2D1915FEF7A0E7 has one UID0002TG item/body. | auto-generated/NexusTK/render/Surface.cpp target body | already-present | already-present |
| [x] | C2TG-075 | 0002TG | Preserve zero UID0002TG empty-emitter markers in generated Surface.cpp. | exact | Actor/authority: Validator; final report-freeze Surface.cpp SHA256 10801BE643882E7CB30D9749090E0D5215E44C2ADB2209939D2D1915FEF7A0E7 has zero UID0002TG empty-emitter markers. | auto-generated/NexusTK/render/Surface.cpp empty-marker check | already-present | already-present |
| [x] | C2TG-076 | 0000TN | Preserve exactly one SurfaceScaledRleTintProc typedef in generated Surface.h. | exact | Actor/authority: Validator; final report-freeze Surface.h SHA256 AE5B807D20E2F71167E5E68392DF8611429B306CB1C63EE01E6328C9B420FE67 has exactly one typedef. | auto-generated/NexusTK/render/Surface.h typedef | already-present | already-present |
| [x] | C2TG-077 | 0000TN | Preserve exactly one g_pfnBlitScaledRleTint extern in generated Surface.h. | exact | Actor/authority: Validator; final report-freeze Surface.h SHA256 AE5B807D20E2F71167E5E68392DF8611429B306CB1C63EE01E6328C9B420FE67 has exactly one extern. | auto-generated/NexusTK/render/Surface.h extern | already-present | already-present |
| [x] | C2TG-078 | 0000TN | Preserve exactly one g_pfnBlitScaledRleTint definition in generated Surface.cpp. | exact | Actor/authority: Validator; final report-freeze Surface.cpp SHA256 10801BE643882E7CB30D9749090E0D5215E44C2ADB2209939D2D1915FEF7A0E7 has exactly one definition. | auto-generated/NexusTK/render/Surface.cpp definition | already-present | already-present |
| [x] | C2TG-079 | 00039V | Preserve exactly one compat and one RGB565 provider initializer assignment in generated Surface.cpp. | exact | Actor/authority: Validator; final report-freeze Surface.cpp SHA256 10801BE643882E7CB30D9749090E0D5215E44C2ADB2209939D2D1915FEF7A0E7 has one assignment to each accepted provider. | auto-generated/NexusTK/render/Surface.cpp initializer | already-present | already-present |
| [x] | C2TG-080 | 0002TG | Physically reread generated Surface.cpp against final report-freeze validator command metadata and exact body, marker, definition, and initializer counts. | exact | Actor/authority: B008 read-only verification; 2026-08-13 reread: command 000000023100 at 2026-08-13T07:10:45-04:00; SHA256 10801BE643882E7CB30D9749090E0D5215E44C2ADB2209939D2D1915FEF7A0E7; 71,018 bytes; 2,120 LF lines; all required counts passed. | auto-generated/NexusTK/render/Surface.cpp readback | incorporate | applied |
| [x] | C2TG-081 | 0000TN | Physically reread generated Surface.h against final report-freeze validator command metadata and exact typedef/extern counts. | exact | Actor/authority: B008 read-only verification; 2026-08-13 reread: command 000000023100 at 2026-08-13T07:10:45-04:00; SHA256 AE5B807D20E2F71167E5E68392DF8611429B306CB1C63EE01E6328C9B420FE67; 3,087 bytes; 102 LF lines; both required counts passed. | auto-generated/NexusTK/render/Surface.h readback | incorporate | applied |
| [x] | C2TG-082 | 0002TG | Preserve successful dated validation of the by-class manual page after both same-or-greater GrafPort and EPFTileContext rows were confirmed unchanged. | exact dated receipt | Actor/authority: Primary-supervisor Gate 2A receipt and B008 report-freeze physical reread; command 23043 is the retained successful no-generated-refresh validation identity; SHA256 FF87AEF9714FF85284A51ACDB1ADC7171395DD926C44D78260A7CF8074A232E0, 277,113 bytes, 626 lines at that reread; commands 22924 and 23012 are historical; every later gate must reread the file. | by-class/-coverage-report.md | incorporate | applied |
| [x] | C2TG-083 | 00005V | Preserve the current same-or-greater GrafPort manual row with UID0002TG receiver-only dependency detail. | exact | Actor/authority: Primary supervisor no-change disposition; current by-class coverage command 23043 and physical reread prove row line 237 under SHA256 FF87AEF9714FF85284A51ACDB1ADC7171395DD926C44D78260A7CF8074A232E0 contains the Section 28 payload without unrelated slot-7 pollution; commands 22924 and 23012 are historical. | by-class/-coverage-report.md line 237 | already-present | already-present |
| [x] | C2TG-084 | 0000J4 | Preserve the current EPFTileContext by-file manual row with UID0002TG mask-stream/no-source-pixel-read detail. | exact | Actor/authority: Primary supervisor no-change disposition; current by-file coverage command 23044 and physical reread prove row line 85 under SHA256 02A44EDBAAA596D59ECE589D05E6BF57553C3DCA5AD7EAE0E1369C567344E756 contains the exact Section 28 payload; commands 22923 and 23011 are historical. | by-file/-coverage-report.md line 85 | already-present | already-present |
| [x] | C2TG-085 | 00004I | Preserve the current EPFTileContext by-class manual row with UID0002TG mask-stream/no-source-pixel-read detail. | exact | Actor/authority: Primary supervisor no-change disposition; current by-class coverage command 23043 and physical reread prove row line 188 under SHA256 FF87AEF9714FF85284A51ACDB1ADC7171395DD926C44D78260A7CF8074A232E0 contains the exact Section 28 payload; commands 22924 and 23012 are historical. | by-class/-coverage-report.md line 188 | already-present | already-present |

- Checklist count: 9 unchecked, 76 checked.
- Ledger/checklist parity: exact same 85 Claim IDs and exact same Target UID, Claim, Confidence, Evidence, Destination, Action, and Verification state fields in the same order.
- Actor/authority is preserved inside every Evidence cell: 60 B008 callback/read-only/repair/validation rows, 18 primary-supervisor rows, and seven validator rows.
- Current checked-state allocation: 52 `applied`, 24 `already-present`; current pending allocation: 9 `proposed`.
- The nine pending rows are exactly C2TG-051 through C2TG-059; they cover supervisor IDA only.

Initial report-only pass:
- [x] Supervisor validation required before implementation: historical Gate 1 acceptance is recorded, and all later exact-artifact repairs remain separately historicalized.
- [x] For a by-file target, exhaustive whole-file inventory completed and reconciled against IDA, all related by-* pages, generated output, and matching reports; every function and every other code/data/type/resource/range item has an evidence-backed disposition rather than a sampled-subset or generic future-work entry: not applicable because UID0002TG is one exact by-memory function; its Surface support route and affected pages are exhaustively inventoried.
- [x] For a by-file target, every file-owned inventory item has explicit behavior/role, ownership/emitter/source placement, CPP/H or no-code, metadata/score, destination doc, Claim And Incorporation Ledger, and Implementation Tracking Checklist coverage as applicable; excluded candidates have evidence-backed reasons: not applicable for the by-memory target; all triggered support items have explicit dispositions.
- [x] For a by-file target, current generated `.cpp`/`.h` audited against the inventory and every missing/incomplete function, code path, data definition, declaration/type/include/forward declaration, child route/order defect, stub/placeholder/empty marker, and required-but-missing header has an exact formal CPP/H repair or evidence-backed no-code/no-header disposition: not applicable as a by-file gate; the target-specific generated CPP/H state is nevertheless physically audited under C2TG-073 through C2TG-081.
- [x] Target/support docs to update: exact C2TG-001 through C2TG-044 callback destinations are applied and physically current; no unlisted ordinary destination remains.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: no additional target UIDs are declared; related UIDs are support scope only.
- [x] Current target state and actual evidence checked recorded: Sections 3, 4, 9, 16, 29, and 32 record literal current state and hashes.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: 85 canonical rows.
- [x] Metadata/score changes to apply: target 92/94 is applied; every support score has an exact retain/reconcile disposition.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof after all reasonable current routes were exhausted: Section 27 closes every target blocker; remaining caps are lexical/compile-audit confidence caps, not deferred research.
- [x] Owner/emitter/reconstructable changes to apply: exact retain dispositions are recorded; no route change is required.
- [x] Split/rename/new-child changes to apply: no split/new child is required; the sole supported source-facing function rename is atomized in Section 21.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: exact Surface placement, boundaries, padding, three active IDA mutations, and protected no-change entities are documented.
- [ ] Supervisor Gate 2B IDA handoff lists every exact address/entity, pre-state, proposed action, supporting type, safety constraint, and expected readback; leave this row unchecked for the supervisor: Section 21 retains three declarative mutation rows and five separate protected-dependency readbacks, while runtime and persistence handling remain external supervisor responsibilities and C2TG-051 through C2TG-059 remain pending.
- [x] First-draft CPP block text/no-code proof and H block text/no-header-code proof to apply: complete target CPP plus blank-target-H rationale and UID0000TN H/CPP support are preserved.
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank: no third-party import applies; no import directive or multiline import block exists.
- [x] Exact target/support doc facts to incorporate at report-level detail: C2TG-001 through C2TG-044 are applied without summary loss.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: retained in Sections 2, 6, 18, 19, 27, and claim rows.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: explicitly ignored in Section 7.
- [x] Open questions to close or document as evidence-backed unresolved: Section 27 resolves every target question and bounds only final-audit uncertainty.
- [x] Validators to run: C2TG-060 through C2TG-064 and C2TG-066 through C2TG-069 passed under commands 000000022926 through 000000022934; C2TG-070 through C2TG-072 and C2TG-082 are current under commands 23009, 23010, 23044, and 23043; all generated refreshes were skipped and all physical identities were reread. Commands 22921 through 22924, 23011, and 23012 are historical.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: final report-freeze generated command 000000023100 at 2026-08-13T07:10:45-04:00 is physically verified, command 000000022403 is originating history, commands 000000022761/000000022770/000000022920/000000022981/000000023008/000000023042/000000023051/000000023099 are superseded historical refresh evidence, and all nine manual rows are same-or-greater no-change dispositions under retained receipts 23009, 23010, 23044, and 23043 plus a dated physical reread. Tracker command 23101 is final report-freeze provenance only; commands 23099, 23072, and 23045 are historical.

Implementation callback pass:
- [x] Supervisor-owned IDA changes remain pending and were not applied by the B agent: C2TG-051 through C2TG-059 remain unchecked/proposed.
- [x] For a by-file target, all accepted whole-file inventory claims were incorporated and verified across the by-file page and every affected support page; no function or other file-owned code/data/type/resource item was silently omitted: not applicable as a by-file gate; all UID0002TG support destinations are accounted for.
- [x] For a by-file target, every accepted missing/incomplete function/code/data/declaration/header/routing repair was applied through owning formal CPP/H channels; a coherent validator refresh completed; current generated `.cpp` and required `.h` were physically reread against the full inventory and contain no unresolved stub, placeholder, empty marker, partial implementation, missing declaration, or ordering defect. If no `.h` exists, the report contains a file-specific verified no-header disposition: not applicable as a by-file gate; target-specific CPP/H generation and the private-target-H disposition are nevertheless verified.
- [x] Report accepted by supervisor for implementation: historical Gate 1 acceptance SHA256 AD8BC6397B51E959A081D0CDF30D44CA04C55A4D94734A114346FF91A7960DDF is recorded.
- [x] All accepted target/support doc details incorporated at report-level detail: C2TG-001 through C2TG-044 are physically present.
- [x] Every declared primary/additional UID verified independently against its ledger and destination docs: UID0002TG is the sole declared target; support UIDs are independently mapped without claiming additional target coverage.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: 85/85 canonical rows with exact checklist parity.
- [x] Metadata/score/owner/emitter/split/rename/CPP/H changes applied or explicitly not applied with reason: complete in Sections 22, 24-26, and 29.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: no accepted historical detail was pruned.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: no target blocker remains; final-audit caps are explicit.
- [x] Validators run and results recorded: retained command 000000021994, ordinary commands 000000022926 through 000000022934, and coverage receipts 23009, 23010, 23044, and 23043 are reconciled with current physical destination/row rereads; commands 22921 through 22924, 23011, and 23012 are older history.
- [x] Generated CPP/H and report refresh completed by validator; each affected generated file's dated report-freeze command ID is recorded, or explicit manual supervisor-owned coverage/tracker text is supplied/confirmed unchanged: command 000000023100 at 2026-08-13T07:10:45-04:00 and exact Surface.cpp/Surface.h readbacks are the final report-freeze snapshot, command 000000022403 is originating history, commands 000000022761/000000022770/000000022920/000000022981/000000023008/000000023042/000000023051/000000023099 are superseded historical refresh evidence, manual rows are confirmed unchanged under retained receipts 23009, 23010, 23044, and 23043 plus a dated physical reread, and tracker command 23101 is dated report-freeze provenance only while commands 23099, 23072, and 23045 are historical.
- [x] Remaining unapplied accepted items listed with exact blocker: only supervisor Gate 2B claims C2TG-051 through C2TG-059 remain, subject to exact current-prestate agreement, with no research or validator deferral.
- [x] Report body is lifecycle- and gate-neutral: execution/archive truth is deferred to the report's actual physical path at read time plus validator-owned status/history metadata; dated tracker hashes/rows and dated IDA sessions are provenance only. Runtime, persistence, and lifecycle procedures are deliberately excluded from this report.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000023152","destination_path":"executed-b-agent-research/B008/0002TG-SoftwareRenderRgb565ScaledRleTintCallback-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0002TG-SoftwareRenderRgb565ScaledRleTintCallback-empty-emitter-source-quality.md","timestamp":"2026-08-13T13:11:07-04:00","uid":"0002TG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
