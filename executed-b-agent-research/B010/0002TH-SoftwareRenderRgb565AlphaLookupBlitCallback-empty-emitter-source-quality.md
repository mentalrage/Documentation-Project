** TARGET-REPORT-UID:0002TH **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002TH SoftwareRenderRgb565AlphaLookupBlitCallback Empty-Emitter Source Quality


## Finalized Report / Current Recommendation

- Current recommendation after the accepted B010 callback: retain [UID:0002TH] at implemented `92/94`, preserve `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000OC`, and retain the exact source-ready RGB565 alpha-mask callback now present in formal C++.
- Final disposition: this is a file-local `Surface.cpp` provider for slot 5, not a `RankingEventListPane` method, aggregate body, `SoftwareBlend16` function, or raw callback-table object. The source callback is `void __thiscall SoftwareRenderRgb565AlphaLookupBlitCallback(GrafPort *, const AlphaMaskSurface *, const RectBounds *, const RectBounds *)`.
- B010 ordinary implementation is complete for C2TH-001..022, C2TH-034, C2TH-037, and C2TH-039. The primary supervisor separately owns C2TH-023..033, C2TH-035, C2TH-036, C2TH-038, and C2TH-040: manual coverage, bounded IDA transaction, coherent generated refresh, mutable-authority reread, final verification, and lifecycle.
- Confidence: very strong for range, ABI, dispatch, ownership, source layout, helper roles, global roles, clipping, prefix/tail behavior, and first-draft C++; source spellings are high-probability reconstruction names because original private symbols are stripped.

## Supporting Research

- Exact target: `[0x004c3cf0,0x004c3e93)`, `0x1a3` / 419 bytes. Fresh MCP `get_bytes` returned the complete body and a target-byte SHA256 of `E01E7BED7A2E3B8CDF199D0193E7309A295328DCDC1BE2996EA85EEAE5BFD451`.
- Exact fences: `[0x004c3ce1,0x004c3cf0)` is fifteen `0xcc` bytes and `[0x004c3e93,0x004c3ea0)` is thirteen `0xcc` bytes. `lookup_funcs` resolves only the target start, not the end address.
- Dated live IDA snapshot: schema-current JSON-RPC `initialize -> tools/list -> tools/call` used MCP transport session `90db283a-1878-4a12-a4cf-6843f1e6fd44` and database session `supervisor-uid0003fs-rollback-reopen`, PID/worker PID 5076. `server_health` returned `status:ok`, exact IDB path, Hex-Rays ready, strings ready with 2068 strings, and `auto_analysis_ready:false`; bounded IDB-backed queries all succeeded, so the analysis flag was nonblocking.
- Dated canonical IDB disk identity at the evidence pass: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `B8B1CFB3E7B660AC394A904F4FBFAF05B6E99A8B074DACC1431E9CD1C865A299`, 143196536 bytes, last write `2026-08-04T18:06:14.8531551-04:00`. The supervisor must dynamically rebind session and disk identity before any Gate 2B mutation; this snapshot is evidence, not a permanent current-session assertion.
- Dated B010 self-audit snapshot at `2026-08-05T15:03:22-04:00`: fresh `idb_list` and `server_health` identified ephemeral session `b006-uid0004e0-postsave`, PID/worker PID `15660`, on the exact canonical path with Hex-Rays and the 2068-string cache ready. The canonical disk identity was then SHA256 `A4B44EBE405077D2750E2388DF781A7CB7DDA9E419C34645679A412787B5329B`, 143196656 bytes, last write `2026-08-04T21:25:33.8724072-04:00`; the UID0002TH I01-I06 semantic prestates matched. This snapshot is now historical because later unrelated supervisor persistence advanced the shared IDB container.
- Dated primary-supervisor transaction baseline reconciled at `2026-08-05T17:19:49-04:00`: sole session `b005-uid0001ny-d1-rollback-reopen`, PID `22636`; canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; canonical SHA256 `23B89BF35334D876FE63C04AE15C4F90AEF4DF41FAF9D79580F25D244A214283`; size 143196749 bytes. The full read-only I01-I06 preflight passed, but this identity is now historical because a separately accepted supervisor transaction advanced the shared IDB container.
- Current dated transaction baseline reconciled by B010 at `2026-08-05T17:32:00-04:00`: sole session `b005-uid0001ny-postsave-reopen`, PID `24380`; canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; canonical SHA256 `115491A99AE02621692E9F7AF4C9E3F011E77DD9678AF996A39A86AA02837695`; size 143196991 bytes. `tools/tmp_b010_uid0002th_gate2b.ps1 -Mode Preflight` reran the complete I01-I06 semantic type/function/frame/comment/item/byte/xref/name-table/padding package and returned `Status:PASS` with no semantic prestate drift. This read-only rebase grants no C2TH-027..033 or C2TH-038 mutation, save, persistence, or verification-state credit.
- Dated generated evidence: tracker command `000000021107`, tracker SHA256 `00CE63CC81A71DFD822A432DCFBBA3F3C12F805AD8C4891B0F67714224817C74`, still lists UID0002TH at `87/90`, reconstructable, with report counts `0/0/0`. Generated memory coverage and `Surface.cpp`/`.h` are command `000000021100`; `Surface.cpp` SHA256 `5CBDE03CEF493A91D469B3E9A48C9CFC4FD9AEC5413FA05735E847CF7A3A7E44` contains the UID0002TH Empty Emitter Marker, while `Surface.h` SHA256 is `CBD916D937D419EA1E613D935CAB3A9823E834B3049478CAEB769D6F5E75C115`.
- Dated B010 self-audit generated snapshot: coherent command `000000021151` (`2026-08-04T21:37:31-04:00`) produced tracker SHA256 `A00468E375F4A2AB4104F9FCE7710A977E36F377E922597C82F0749F6A6D2969`, memory coverage `B295C3653C3246D631B4B84AFB3AC597FD98A6FC65BC51EE23800C25DA3077EC`, file coverage `640C48970860F058702709C814E45F7D9F54100EE0113D32049A9FEAACFE34D0`, global coverage `9DEC965FA29CF29119744E88DAA8F818A99827FBE69EA85A4909C18E356B08A3`, and type coverage `B91D9B524B983996377011150E03FF2C4008E4CFA7596F4B7ED96A678931FE39`. `Surface.cpp` SHA256 `67210298222D71094273E7B8BD8F0A2B42DAEC32D0A63F7F084562F0095F260C` has exactly one UID0002TH provider and zero UID0002TH Empty Emitter Markers; `Surface.h` SHA256 `7F3F2B49881F0FA5D7164F1E37415D6681E8D72E6B74621F4BBB9920E38E9176` has the canonical slot typedef/externs. These are dated generated snapshots; C2TH-036 remains supervisor-owned until final post-manual/post-IDA coherent verification.
- Dated manual evidence: by-memory coverage SHA256 `39E989A7C7D4072311D32B0D66349AC0477D49A50834BD09399A260FCEFBCD09`, by-global coverage `2CBB39DFA34BACD232F591089CBF060D09D113CE422815CC1D4AE80A61A3A360`, by-file coverage `3758B4E367030DEC44AEA0504762A869FE91EBB591B048CDD7170489B670FA8D`, and by-struct coverage `4B6995A919504E744922F1C99BE53D7A2330B53BCF3B6B67DCD65E184107ABF1` were read, not edited.
- Dated B010 self-audit manual snapshot: by-memory coverage SHA256 `1527EA746CE920B388BBF2C919D2882214BD12C760BE5CB9BBE5BBD5913AFCF8`, by-global `2CBB39DFA34BACD232F591089CBF060D09D113CE422815CC1D4AE80A61A3A360`, by-file `DDB134C5264A40E31ECA32BE214C1325AE8230903053B4D82CB9EDD41393E7D4`, and by-struct `4B6995A919504E744922F1C99BE53D7A2330B53BCF3B6B67DCD65E184107ABF1` were read only. UID0002TH remains the stale 80-percent row, UID00029V remains the stale 92-percent row, and the UID0000TN/UID0000OC/UID0001TQ rows remain stale relative to accepted ordinary docs, so C2TH-023..026 correctly remain proposed.
- Historical-report search used UID `0002TH`, address `0x004c3cf0`, target name, `dword_69B3F4`, `AlphaMaskSurface`, `ApplyAlphaMap565`, and Surface slot-5 terms. No earlier B report directly covered UID0002TH; current by-* pages and sibling callback reports were treated as evidence, not as substitutes for this target-specific pass.

## Target

- Target UID: `0002TH`.
- Additional target UIDs: none. Support pages are not declared as additional report-covered targets.
- Target path: `by-memory/0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback.md`.
- Source queue row: `auto-generated/-ag-research-tracker.md` -> `by-memory` -> `Not-Covered Files - Reconstructable`.
- Current classification: exact source-authored software-render callback with an empty generated emitter.
- Report-start target identity was SHA256 `D3EB44EDB1694229B4A75899FFA45883126FACF255E3E06AD655D5F926BDC712`, 12452 bytes. After the accepted callback and scoped validation, physical reread produced SHA256 `12BBB2EC01F0CAB1A746C1E7B1D6F151E2CF8D41A3375D2BF402F14561E18445`, 21071 bytes.
- Current implemented metadata is `92/94`, owner/emitter `0000OC`, reconstructable true, blank position, nonblank formal CPP, and blank formal H.

## Current Target State

- The page now has correct exact bounds/hash, clean padding, Surface ownership, typed slot storage `0x0069b3f4`, two provider references, one live indirect consumer, no ordinary direct callers, exact ABI/layout/helper/lookup conclusions, score rationale, and complete formal C++.
- The former Item Summary and blank-C++ blocker language has been replaced or clearly retained as historical score progression; current prose no longer calls the callback typedef, alpha/source layout, helper names, or global names unresolved.
- Accepted dated pre-Gate2B IDA snapshot `2026-08-04T19:41:12-04:00` used IDB session `supervisor-uid0003fs-rollback-reopen` PID `5076` through transport session `57de975c-3c00-4425-9fa1-024188a0c19c`; health was `status:ok`, `hexrays_ready:true`, and the canonical disk IDB was `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, 143196536 bytes, SHA256 `B8B1CFB3E7B660AC394A904F4FBFAF05B6E99A8B074DACC1431E9CD1C865A299`. Those session/PID/hash values are evidence for that snapshot, not permanently current authority.
- The bounded `2026-08-05T15:03:22-04:00` B010 self-audit used ephemeral session `b006-uid0004e0-postsave` PID `15660` and canonical disk SHA256 `A4B44EBE405077D2750E2388DF781A7CB7DDA9E419C34645679A412787B5329B`, 143196656 bytes. All literal I01-I06 semantic prestates and protected rows matched, but that container identity is now a historical snapshot.
- The `2026-08-05T17:19:49-04:00` primary-supervisor read-only preflight used session `b005-uid0001ny-d1-rollback-reopen` PID `22636` and canonical disk SHA256 `23B89BF35334D876FE63C04AE15C4F90AEF4DF41FAF9D79580F25D244A214283`, 143196749 bytes. It passed every semantic prestate/protection row but is now historical.
- The current `2026-08-05T17:32:00-04:00` B010 read-only rebase used sole session `b005-uid0001ny-postsave-reopen` PID `24380` and canonical disk SHA256 `115491A99AE02621692E9F7AF4C9E3F011E77DD9678AF996A39A86AA02837695`, 143196991 bytes. The full `tools/tmp_b010_uid0002th_gate2b.ps1 -Mode Preflight` package passed every I01-I06 semantic prestate and protection row with no drift. No mutation or save occurred, so all IDA and mutable-authority claims remain proposed and unchecked.
- At that dated snapshot the four functions still had `sub_4C3CF0`, `sub_462300`, `sub_460410`, and `sub_460C90` plus polluted decompiler types. The IDA name table already mapped `g_surfaceColorLookup5Bit`, `g_surfaceColorLookup6Bit`, and `g_pfnBlitAlphaLookup` to `0x0069b3d8`, `0x0069b3dc`, and `0x0069b3f4`, while `inspect_items` still exposed one-byte undefined physical heads with blank item-name fields; this distinction is part of the literal I06 prestate.
- The report-start generated snapshot had `Surface.cpp` assigning `g_pfnBlitAlphaLookup = SoftwareRenderRgb565AlphaLookupBlitCallback` while emitting a UID0002TH Empty Emitter Marker and had no slot-5 typedef/extern in `Surface.h`. Dated command `000000021151` now reflects the ordinary provider, typedef, externs, definitions, and covered-by routes with zero UID0002TH markers, but generated authority remains supervisor/validator-owned and must be reread after manual coverage and IDA disposition before C2TH-036 is checked.
- The report-start manual coverage snapshot described only 80-percent evidence and unresolved assignment/source quality. Exact rows must be reread immediately before the supervisor applies the proposed replacements.
- At every later Gate 2B/current-state/post-move check the supervisor must dynamically rerun `idb_list`, `server_health`, canonical disk path/hash/size, and every bounded I01-I06 readback. No session ID, PID, item/name state, or disk hash in this section is asserted to remain current after the transaction.

## Executive Recommendation

1. Completed by B010: the exact target body is present through [UID:0000OC] `NexusTK/render/Surface.cpp`; target H remains blank because the callback is file-local.
2. Completed by B010: [UID:0000TN] now carries the slot-5 typedef, forward declaration, externs, and sole callback/lookup-root definitions; physical storage pages use covered-by markers to prevent duplicates.
3. Completed by B010: target, initializer, physical table, MapPane consumer, AlphaMaskSurface/view, helpers, lookup roots, compat peer, aggregate, and Surface file docs are synchronized without merging ownership.
4. Apply the report's exact IDA transaction only through the supervisor Gate 2B flow after dynamic preflight and backup.
5. Apply the exact manual coverage replacements, validate changed ordinary/manual docs, then run one coherent full generated refresh and verify the provider definition/typedef/global and disappearance of the empty marker.

## Supervisor Active Recheck

- The supervisor must rerun fresh `idb_list`, `server_health`, canonical disk hash/size, target/helper/global prestate, collision checks, bytes, xrefs, frames, UDT state, and comments before Gate 2B. Session IDs in this report are dated evidence only.
- The prior full preflight against SHA256 `23B89BF35334D876FE63C04AE15C4F90AEF4DF41FAF9D79580F25D244A214283`, 143196749 bytes, in session `b005-uid0001ny-d1-rollback-reopen` PID `22636` is historical. The current full preflight passed against SHA256 `115491A99AE02621692E9F7AF4C9E3F011E77DD9678AF996A39A86AA02837695`, 143196991 bytes, in sole session `b005-uid0001ny-postsave-reopen` PID `24380`. The current read-only result establishes only the transaction baseline; it does not satisfy any apply, save, reopen, rollback, or persistence claim.
- The supervisor must reject or stop the transaction on any range, byte, xref, type, frame, comment, item-width, collision, or neighbor drift. No partial save is allowed.
- The supervisor must reread target/support ordinary docs and mutable generated/manual identities immediately before Gate 2A/coverage/autogen work; file hashes in this report are gate snapshots, not immutable authority.
- B010 performed no IDA mutation/save, generated refresh, manual coverage edit, lifecycle command, or report execution. After Gate 1 acceptance, B010 edited only the 16 accepted ordinary by-* destinations and ran the 16 authorized scoped validators with `--no-generated-refresh`.

## Inference Research Guidance Check

- Binary/runtime behavior is the highest-priority constraint. The proposed source preserves the exact draw guard, clip order, source translation, destination addressing, prefix/tail split, row pitches, lookup indexing, and packed RGB565 result.
- Human source shape is reconstructed rather than leaving `sub_*`, `dword_*`, `__m64`, `_DWORD`, or stale-register return artifacts. Names follow established project Surface/AlphaMaskSurface/GrafPort conventions.
- Style consistency is subordinate to exact behavior and human-looking source. Existing accepted Surface callback style supports file-local `static` providers, typed `g_pfn*` globals, `RectBounds`, and canonical GrafPort fields.
- Stale Wave2/Wave3 language was ignored. No third-party import applies because this is NexusTK integration/render code.

## Heuristic / Inference Reanalysis And Validation

| Question | Positive evidence | Rejected alternative/test | Resolution |
| --- | --- | --- | --- |
| Return type | Only runtime dispatch at `0x0050a267` ignores EAX; target exits preserve path-dependent stale EAX; paired source-ready Surface callbacks use logical void. | `char`/byte result comes only from decompiler residue. No consumer tests AL/EAX. | Source return is `void`. |
| Calling convention and arguments | Assembly ends `retn 0x0c`; ECX is the GrafPort receiver; MapPane pushes exactly alpha surface, source bounds, destination bounds. | Five-argument `__userpurge` includes MM1 and mis-typed locals. The stack cleanup proves only three stack args. | `__thiscall` receiver plus three pointer arguments. |
| MM1 lane | Target forwards MM1 into `sub_460410`; its child `sub_460C90` begins by computing `pandn mm1,mm1`, forcing zero independent of incoming state. | A source alpha/color parameter in MM1 would be consumed before overwrite or supplied by the indirect caller. Neither occurs. | MM1 is compiler/decompiler residue, not source ABI. |
| Source object | MapPane `+0x3e0` is allocated/freed and documented as `AlphaMaskSurface *m_selectionOverlay`; first callback argument reaches `sub_462300`. | Embedded object/address-of interpretation conflicts with constructor ownership and the actual pushed pointer. | `const AlphaMaskSurface *alphaSurface`. |
| Source view | `sub_462300` copies object `+0x14..+0x27` into a 0x14-byte local. Existing layout docs and clipped-view helpers independently prove pointer/width/height/stride/ownership. | Raw `int[3]`/extra dwords are stack-fragment typing, not source fields. | `AlphaSurfaceBufferView` is exact 0x14 POD. |
| Slot/global | `0x0069b3f4` has initializer refs for both providers and one live MapPane dispatch; all code uses the fixed global directly. | Table-object ownership or MapPane-specific function name lacks a base-object/index route. | `SurfaceAlphaLookupBlitProc g_pfnBlitAlphaLookup`. |
| Lookup roots | 5-bit root has 12 refs and 6-bit root 11; initializer builds 32 and 64 rows of 256 entries; target indexes R/B through the 5-bit root and G through the 6-bit root. | Generic palette pointers lose exact channel-width semantics; per-target names ignore shared use. | `g_surfaceColorLookup5Bit` and `g_surfaceColorLookup6Bit`. |
| Helper names | `sub_460410` is exact existing UID0004BL `ApplyAlphaMap565`; its only callee is `sub_460C90`, the four-pixel MMX block worker. | New callback-local helper names would duplicate established SoftwareBlend16 ownership. | Keep `ApplyAlphaMap565`; name child `Rgb565AlphaMapMmxBlocks`. |
| Ownership | Both retained/inlined initializer copies select the target into a Surface global; target uses GrafPort/Surface infrastructure. | RankingEventListPane, MapPane, SoftwareBlend16, aggregate, and physical table are consumer/dependency/container/storage roles only. | Owner/emitter remains UID0000OC Surface. |
| Sibling relationship | UID0002TD has identical ECX/three-stack ABI, same source view and clipping, paired slot assignment, RGB555 bulk helper, and RGB555 tail. | Merge would collapse two separately selected compiled providers and pixel-format behavior. | Keep distinct compat/RGB555 and RGB565 provider bodies under one typedef/global. |

## Evidence Standards Used

- Direct IDA facts: function boundaries, bytes, stack cleanup/frame, decompilation, call instructions, xrefs, globals, item/type/comment state at each dated evidence snapshot, UDT state, and server/session identity.
- Documentation facts: report-start metadata, existing accepted class/layout/helper/global names, generated source/header route, manual rows, and source-tree ownership, with mutable identities treated as dated snapshots.
- Inference: source-facing private names, logical `void`, `const` qualification, file-local linkage, and exact C++ statement shape. Each inference is tied to a binary or project-style rejection test above.
- Negative evidence is used to reject alternatives, not to excuse investigation or leave placeholders.

## Evidence Checked

- MCP: `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `xrefs_to`, `decompile`, `callees`, `stack_frame`, `inspect_items`, `get_comments`, `get_global_value`, and `type_inspect` on the target, compat peer, source accessor, bulk helpers, initializer, slot, lookup roots, GrafPort, RectBounds, AlphaMaskSurface, and AlphaSurfaceBufferView.
- Fresh failed-section repair MCP pass at `2026-08-04T19:41:12-04:00`: repeated bounded `lookup_funcs`, `get_bytes`, `xrefs_to`, `stack_frame`, `inspect_items`, `get_comments`, `get_global_value`, `type_inspect`, `type_query`, and `entity_query`; confirmed the exact I01 collision/type state, all four I02-I05 function prestates, all three I06 global prestates, and every byte/item/name/type/comment/xref row in the four immediate protected-neighbor ranges. One combined catalog request timed out; `server_health` remained `ok`, and the same checks completed when narrowed to one type/entity at a time.
- Historical primary-supervisor preflight: `tools/tmp_b010_uid0002th_gate2b.ps1` completed the full read-only I01-I06 package against session `b005-uid0001ny-d1-rollback-reopen` PID `22636` and canonical IDB SHA256 `23B89BF35334D876FE63C04AE15C4F90AEF4DF41FAF9D79580F25D244A214283`, 143196749 bytes; every semantic prestate passed.
- Current B010 rebase preflight: the same full read-only I01-I06 package passed against sole session `b005-uid0001ny-postsave-reopen` PID `24380` and canonical IDB SHA256 `115491A99AE02621692E9F7AF4C9E3F011E77DD9678AF996A39A86AA02837695`, 143196991 bytes. No semantic prestate drift occurred, and no transaction operation or persistence stage ran.
- Ordinary docs: UID0002TH target; UID0002TD compat peer; UID0000TN callback globals; UID0001PI physical callback storage; UID00039V initializer; UID00029V lookup roots; UID0004BL/UID00020A blend helpers; UID0001TQ/UID0001TP/UID00000C/UID0000HF alpha-surface docs; UID0004QY/UID00007Q MapPane consumer; UID00016L RGB565 aggregate; UID0000OC Surface root.
- Generated evidence: research tracker, memory coverage, `NexusTK/render/Surface.cpp`, and `Surface.h` command IDs/hashes and exact UID0002TH rows/marker.
- Manual evidence: report-start by-memory, by-global, by-file, and by-struct coverage rows and whole-file hashes; the supervisor must reread those mutable files before applying any row.
- Historical search: active, executed, archived, and special B-report areas using UID/address/name/slot/helper/source-family terms; no direct prior UID0002TH report matched.

## Claim And Incorporation Ledger

The 40 rows below are the sole authoritative claim registry. The final checklist repeats each row's Claim ID, Target UID, Claim, Confidence, Evidence, Destination doc/section, Action, Actor, and Verification state verbatim and in this order.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Actor | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| C2TH-001 | 0002TH | Set completion/confidence to 92/94, canonical owner and emitter to 0000OC, reconstructable true, and keep position blank. | very strong | Physical metadata, hash `12BBB2EC01F0CAB1A746C1E7B1D6F151E2CF8D41A3375D2BF402F14561E18445`, and validator 21131. | UID0002TH metadata | incorporate | B010 callback | applied |
| C2TH-002 | 0002TH | Add exact ABI, provider references, live slot dispatch, clipping, source-view, prefix, tail, lookup-root, Surface-route, and formal-C++ conclusions without pruning existing detail. | very strong | Target Item Summary and detailed behavior sections; validator 21131. | UID0002TH Item Summary and research sections | incorporate | B010 callback | applied |
| C2TH-003 | 0002TH | Add exact 419-byte range and SHA256, 15-byte predecessor and 13-byte successor padding, dated IDA snapshot, target xrefs, and slot xrefs. | exact binary evidence | Range `[0x004c3cf0,0x004c3e93)`, body SHA256 `E01E7BED7A2E3B8CDF199D0193E7309A295328DCDC1BE2996EA85EEAE5BFD451`, padding, and xref inventories. | UID0002TH Status, Range, and IDA Evidence | incorporate | B010 callback | applied |
| C2TH-004 | 0002TH | Record logical void return, ECX GrafPort receiver, three four-byte stack pointers, retn 0x0c, and the MM1 overwrite proof. | very strong | Callee cleanup, caller push order, ignored return, and MM1 zeroing. | UID0002TH ABI | incorporate | B010 callback | applied |
| C2TH-005 | 0002TH | Record draw guard, clip and intersection order, source translation, destination addressing, bulk-width rounding, scalar tail, pitches, and row iteration. | very strong | Dated decompile/disassembly plus exact formal body. | UID0002TH Behavior And Touched State | incorporate | B010 callback | applied |
| C2TH-006 | 0002TH | Record the exact AlphaSurfaceBufferView, GrafPort, and RectBounds offsets and source-facing types used by this callback. | very strong | Exact 0x14 view and observed receiver/bounds offsets. | UID0002TH Layout | incorporate | B010 callback | applied |
| C2TH-007 | 0002TH | Record exact five-bit and six-bit lookup roles plus ApplyAlphaMap565 and Rgb565AlphaMapMmxBlocks names, contracts, and ownership. | strong | Lookup indexing, helper caller/callee evidence, and SoftwareBlend16 ownership. | UID0002TH Lookup And Helper Evidence | incorporate | B010 callback | applied |
| C2TH-008 | 0002TH | Preserve Surface ownership and the evidence-backed rejection of RankingEventListPane, MapPane, SoftwareBlend16, aggregate, and physical-table ownership. | very strong | Initializer, slot, source-root, and negative ownership evidence. | UID0002TH Ownership And History | incorporate | B010 callback | applied |
| C2TH-009 | 0002TH | Insert the exact RECONSTRUCTION_CPP CODE callback body from First-Draft C++ Recommendation without extending outside the target range. | strong source reconstruction | One physical file-local callback body; target hash and validator 21131. | UID0002TH formal CPP block | incorporate | B010 callback | applied |
| C2TH-010 | 0002TH | Keep RECONSTRUCTION_H CODE blank because the provider is file-local and route shared declarations through UID0000TN and alpha-surface support pages. | very strong | Target H block is physically blank; shared declarations exist in UID0000TN. | UID0002TH formal H block | already-present | B010 callback | already-present |
| C2TH-011 | 0002TH | Add the AlphaMaskSurface forward declaration, SurfaceAlphaLookupBlitProc typedef, two lookup-root externs, and g_pfnBlitAlphaLookup extern exactly as reported. | strong | Physical UID0000TN H block, hash `19158874B1AB117657ED4249C536DD5C9716904EA12E393F699AF8B063A9726C`, and validator 21133. | UID0000TN formal H block | incorporate | B010 callback | applied |
| C2TH-012 | 0002TH | Add one definition each for the two lookup roots and g_pfnBlitAlphaLookup while preserving every existing callback-table definition. | very strong | Exactly one definition of each global in UID0000TN CPP. | UID0000TN formal CPP block | incorporate | B010 callback | applied |
| C2TH-013 | 0002TH | Add the exact void ABI, two providers, MapPane consumer, typed global, and raise completion/confidence from 93/94 to 94/95. | very strong | Slot-5 row, providers, consumer `0x0050a267`, metadata, and validator 21133. | UID0000TN slot 5 and metadata | incorporate | B010 callback | applied |
| C2TH-014 | 0002TH | Add the typed slot-5 storage relationship and four ordered xrefs while retaining exactly one non-emitting covered-by CPP comment and no physical data declaration, definition, or provider body. | very strong | UID0001PI hash `93F3B817469D521EA620BB3E78FDFA7B7CAF5AD7B1DF38DC7B82ECB7B713B339`; validator 21134; CPP block contains exactly `// Emitted source for this range is covered by [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md).` | UID0001PI physical storage and formal CPP/H blocks | incorporate | B010 callback | applied |
| C2TH-015 | 0002TH | Replace the provisional byte-result direction with the exact typedef and provider identities while preserving the already-correct formal assignment. | very strong | Initializer provider assignments and typed slot documentation; validator 21135. | UID00039V initializer | incorporate | B010 callback | applied |
| C2TH-016 | 0002TH | Correct the callback call to pass m_selectionOverlay rather than its address and preserve the pointer-owned field and bounds roles. | very strong | Formal call passes `m_selectionOverlay`; allocation/deletion proves pointer ownership; validators 21136 and 21137. | UID0004QY and UID00007Q MapPane docs | incorporate | B010 callback | applied |
| C2TH-017 | 0002TH | Add the exact 0x14 POD layout, one-byte ownership field, three explicit padding bytes, formal H declaration, and raise completion/confidence from 86/90 to 90/93. | very strong | Physical struct declaration, hash `18BDF47F2A84D9BB8EB7B1B23DC661AA42FBA8DC3C42E10204DA95302C9F03B7`, and validator 21138. | UID0001TQ AlphaSurfaceBufferView | incorporate | B010 callback | applied |
| C2TH-018 | 0002TH | Add the exact const GetBufferInfo accessor, target and peer caller set, callback-facing AlphaMaskSurface decision, and preserve historical IntAlphaSurface evidence. | strong | Three synchronized alpha-surface pages and validators 21139 through 21141. | UID00000C, UID0000HF, and UID0000YL alpha-surface docs | incorporate | B010 callback | applied |
| C2TH-019 | 0002TH | Add the fresh caller sets, exact logical void cdecl prototypes, and MM1 non-ABI proof while preserving existing helper bodies and SoftwareBlend16 ownership. | very strong | Exact callers `0x004c3db4` and `0x0046043f`, helper bodies, MM1 zeroing, and validators 21142 and 21143. | UID0004BL and UID00020A helper pages | incorporate | B010 callback | applied |
| C2TH-020 | 0002TH | Add source names and types, 32-row and 64-row by 256-entry geometry, RGB565 channel use, complete target and peer references, and raise completion/confidence from 92/94 to 93/95. | very strong | Exact root addresses, dimensions, channel indexing, references, and validator 21144. | UID00029V lookup-root page | incorporate | B010 callback | applied |
| C2TH-021 | 0002TH | Add the shared exact typedef, source-view, and slot relationship while preserving the peer as a separate RGB555 provider body. | very strong | Shared slot-5 ABI with distinct RGB555 behavior; validator 21145. | UID0002TD compat peer | incorporate | B010 callback | applied |
| C2TH-022 | 0002TH | Mark the exact child source-ready, preserve aggregate non-emission, and add the Surface slot-5 child inventory, body route, and declaration route. | very strong | Aggregate and Surface inventories; validators 21146 and 21147. | UID00016L aggregate and UID0000OC Surface file | incorporate | B010 callback | applied |
| C2TH-023 | 0002TH | Apply the exact UID0002TH and UID00029V replacement rows supplied in Exact Manual Supervisor-Owned Coverage Or Tracker Text without altering neighboring rows. | strong | Two exact by-memory manual payloads and literal in-place placement instructions; current rows must be reread before application. | by-memory manual coverage | incorporate | Primary supervisor | proposed |
| C2TH-024 | 0002TH | Apply the exact UID0000TN replacement row supplied in Exact Manual Supervisor-Owned Coverage Or Tracker Text. | strong | Exact by-global manual payload; current row must be reread before application. | by-global manual coverage | incorporate | Primary supervisor | proposed |
| C2TH-025 | 0002TH | Apply the exact UID0000OC replacement row supplied in Exact Manual Supervisor-Owned Coverage Or Tracker Text. | strong | Exact by-file manual payload; current row must be reread before application. | by-file manual coverage | incorporate | Primary supervisor | proposed |
| C2TH-026 | 0002TH | Apply the exact UID0001TQ replacement row supplied in Exact Manual Supervisor-Owned Coverage Or Tracker Text. | strong | Exact by-struct manual payload; current row must be reread before application. | by-struct manual coverage | incorporate | Primary supervisor | proposed |
| C2TH-027 | 0002TH | Declare only the literal AlphaSurfaceBufferView 0x14 UDT and SurfaceAlphaLookupBlitProc typedef, preserve AlphaMaskSurface as the existing incomplete zero-member type, and write no type comments. | strong dated prestate | Current full read-only I01 preflight passed under baseline `115491A99AE02621692E9F7AF4C9E3F011E77DD9678AF996A39A86AA02837695`/143196991; declaration operations and poststate/persistence readback remain unapplied. | IDA I01 types | incorporate | Primary supervisor | proposed |
| C2TH-028 | 0002TH | Apply the literal I02 function name, full signature, two written comment channels, complete post-frame, byte hash, xrefs, and padding protections while preserving the two blank comment channels. | strong dated prestate | Current full read-only I02 preflight under 115491A9/143196991 reconfirmed the exact target range, bytes, frame, comments, xrefs, and padding; operation/poststate/persistence remain unapplied. | IDA I02 target at `0x004c3cf0` | incorporate | Primary supervisor | proposed |
| C2TH-029 | 0002TH | Apply the literal I03 function name, full signature, two written comment channels, complete post-frame, byte hash, and two-xref set while preserving the two blank comment channels. | strong dated prestate | Current full read-only I03 preflight under 115491A9/143196991 reconfirmed the exact accessor entity, frame, comments, bytes, and xrefs; operation/poststate/persistence remain unapplied. | IDA I03 accessor at `0x00462300` | incorporate | Primary supervisor | proposed |
| C2TH-030 | 0002TH | Apply the literal I04 function name, full signature, two written comment channels, complete post-frame, byte hash, and one-xref set while preserving the two blank comment channels. | strong dated prestate | Current full read-only I04 preflight under 115491A9/143196991 reconfirmed the exact wrapper entity, frame, comments, bytes, and caller; operation/poststate/persistence remain unapplied. | IDA I04 wrapper at `0x00460410` | incorporate | Primary supervisor | proposed |
| C2TH-031 | 0002TH | Apply the literal I05 function name, full signature, two written comment channels, complete post-frame, byte hash, and one-xref set while preserving the two blank comment channels and excluding MM1 from the ABI. | strong dated prestate | Current full read-only I05 preflight under 115491A9/143196991 reconfirmed the exact MMX-child entity, frame, comments, bytes, caller, and MM1 proof; operation/poststate/persistence remain unapplied. | IDA I05 MMX child at `0x00460c90` | incorporate | Primary supervisor | proposed |
| C2TH-032 | 0002TH | Materialize the three literal four-byte global items, preserve or reapply their exact name-table symbols, apply exact types and regular comments, keep repeatable comments blank, and preserve every itemized immediate neighbor byte, item, name, type, comment, and ordered xref set. | strong dated prestate | Current full read-only I06 preflight under 115491A9/143196991 reconfirmed the literal global and protected-neighbor package; materialization/comments and persistence remain unapplied. | IDA I06 globals and neighbors | incorporate | Primary supervisor | proposed |
| C2TH-033 | 0002TH | Dynamically rebind every literal prestate, create and hash the exact byte-identical backup, apply I01 through I06 serially with immediate readback, save exactly once, independently reopen and verify, and use the stated no-save or saved rollback path on any mismatch. | exact operational contract | Read-only preflight passed; the active transaction/backup/rollback baseline is `115491A99AE02621692E9F7AF4C9E3F011E77DD9678AF996A39A86AA02837695`, 143196991 bytes. No backup, mutation, save, reopen, or persistence credit exists yet. | IDA transaction envelope | incorporate | Primary supervisor | proposed |
| C2TH-034 | 0002TH | Run one scoped file validator with no generated refresh for every accepted changed by-star file and record command ID, timestamp, exit code, and ok count. | verified | Commands 21131 and 21133 through 21147 all report exit 0, `ok:1`, and generated refresh skipped. | Validator Results and 16 ordinary destinations | incorporate | B010 callback | applied |
| C2TH-035 | 0002TH | Validate each supervisor-changed manual coverage report after applying the exact replacement rows and record command identity and result. | operational | Required only after C2TH-023 through C2TH-026 are applied. | Manual coverage validation | incorporate | Primary supervisor | proposed |
| C2TH-036 | 0002TH | Run one coherent generated refresh and verify exactly one UID0002TH provider body; zero UID0002TH Empty Emitter Marker occurrences; exactly one canonical SurfaceAlphaLookupBlitProc typedef and g_pfnBlitAlphaLookup declaration/definition in Surface.h/Surface.cpp; exactly one canonical Surface.h declaration and Surface.cpp definition for each 5-bit and 6-bit lookup root while allowing ordinary consuming-translation-unit extern declarations such as ScreenPane.cpp; exactly one AlphaSurfaceBufferView declaration; the MapPane call passes m_selectionOverlay rather than its address; and physical UID0001PI and UID00029V pages introduce no duplicate declaration, definition, or provider body. | operational | Dated command 21151 already shows the provider/marker/type/callsite state and canonical Surface declarations/definitions; final post-manual/post-IDA generated authority remains supervisor/validator-owned until coherent refresh and exact readback. | Generated refresh and semantic readback | incorporate | Primary supervisor and validator | proposed |
| C2TH-037 | 0002TH | Preserve all positive and negative evidence, source-name inference, rejected aliases and owners, historical assumptions, exact bytes, xrefs, layouts, and source-placement reasoning at report-level detail. | verified | Substantive evidence, ownership, history, and rejection sections remain present. | Same report research/evidence sections | incorporate | B010 callback | applied |
| C2TH-038 | 0002TH | Treat IDA sessions, PIDs, disk identities, generated commands, file hashes, and tracker state as dated snapshots and dynamically reread authority at every applicable gate while leaving lifecycle state external. | operational | A4B44/143196656 and 23B89B/143196749 are historical; current read-only transaction baseline is 115491A9/143196991, and any later identity change requires same-report rebase plus fresh Gate 1. No action/persistence credit is granted by currentness reconciliation. | Mutable-authority and lifecycle checks | incorporate | Primary supervisor | proposed |
| C2TH-039 | 0002TH | Record that this is NexusTK render code with no third-party import and that stale Wave2 and Wave3 material was ignored. | exact disposition | Inference Research Guidance Check records both exclusions. | Same report inference guidance | not-applicable | B010 callback | excluded-with-reason |
| C2TH-040 | 0002TH | Complete claim-by-claim ordinary, IDA, manual, and generated verification before any supervisor-owned report lifecycle action. | operational | Required final Gate2A, Gate2B, and post-refresh reconciliation. | Final implementation readback | incorporate | Primary supervisor | proposed |

## Positive Evidence Summary

- Exact bounded function, clean fences, two selected-provider refs, and one live slot call prove a retained callback provider rather than dead bytes.
- `retn 0x0c`, MapPane push order, and data flow prove the receiver plus three source pointers.
- The live MapPane field, AlphaMaskSurface constructor/destructor evidence, `sub_462300` copy, and two independent view-builder docs prove the source object and 0x14 view layout.
- Existing UID0004BL/UID00020A formal bodies and target/helper call chain resolve the optimized prefix without inventing a duplicate helper.
- Lookup initialization geometry and target indices resolve the two globals by channel width.
- Compat peer and two initializer copies independently prove one shared slot typedef and two distinct provider bodies.
- Existing Surface generated route and neighboring source-ready callbacks establish source placement and project style.

## IDA MCP Facts

- The detailed semantic rows below originate from the accepted dated `2026-08-04T19:41:12-04:00` pre-Gate2B snapshot. The `2026-08-05T17:19:49-04:00` primary-supervisor preflight reconfirmed them under historical session `b005-uid0001ny-d1-rollback-reopen` PID `22636` and historical SHA256 `23B89BF35334D876FE63C04AE15C4F90AEF4DF41FAF9D79580F25D244A214283`, 143196749 bytes. The current `2026-08-05T17:32:00-04:00` B010 full read-only preflight reconfirmed every row unchanged in sole session `b005-uid0001ny-postsave-reopen` PID `24380` against canonical SHA256 `115491A99AE02621692E9F7AF4C9E3F011E77DD9678AF996A39A86AA02837695`, 143196991 bytes. This current transaction baseline is not posttransaction or persistence evidence.
- `lookup_funcs`: target `sub_4C3CF0` `0x1a3`; peer `sub_4BDF40` `0x19b`; accessor `sub_462300` `0x17`; wrapper `sub_460410` `0xe4`; MMX child `sub_460C90` `0xc1`; initializer `InitializeSurfaceRenderCallbacks` `0x1ad`.
- Target-address xrefs were exactly `0x5587ec` in `InitializeSurfaceRenderCallbacks` and `0x558ece` in `sub_558840`; no ordinary direct caller existed. Accessor xrefs were `0x4bdfb5` and `0x4c3d65`; wrapper xref was `0x4c3db4`; MMX-child xref was `0x46043f`.
- Slot `0x69b3f4` xrefs were live dispatch `0x50a267` plus retained initializer/store refs `0x558791`, `0x558bb2`, and `0x558ece`. Lookup-root xrefs numbered 12 at `0x69b3d8` and 11 at `0x69b3dc`, including target reads `0x4c3e0b` and `0x4c3dfc`.
- Target callees were `GrafPort_GetClipRect`, `IntersectRects`, `IsRectEmptyOrInvalid`, `sub_462300`, `sub_460410`, and compiler-cookie check; `sub_460410` called only `sub_460C90`.
- Accepted target type was `char __userpurge@<al>(const struct GrafPort *@<ecx>, __m64@<mm1>, int, __m64 *, const struct RectBounds *secondBounds)`; the complete frame still contained exactly three four-byte stack arguments after the return address. I02 gives the literal pre- and post-frame rows.
- All three global values and four-byte storage bytes were zero. The IDA name table already held the three desired names at the desired addresses, but their physical heads remained size-one undefined items with blank `inspect_items.name`; types were `unsigned __int8 **`, `unsigned __int8 **`, and `int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD)`. Both address comment channels were absent.
- `type_inspect`/`type_query`: `AlphaSurfaceBufferView` and `SurfaceAlphaLookupBlitProc` were absent; `AlphaMaskSurface` was ordinal 696, declaration `AlphaMaskSurface`, kind `other`/non-UDT, unknown size `18446744073709551615`, zero members, and no relationship/member/comment field; `GrafPort` remained exact size `0xa0`; `RectBounds` remained exact size `0x10`.

## Function / Child Inventory

| Address/range | Source role | Owner/emitter | Disposition |
| --- | --- | --- | --- |
| `0x004c3cf0-0x004c3e93` | RGB565 slot-5 provider | Surface / UID0000OC | Primary source-ready body |
| `0x004bdf40-0x004be0db` | Compat/RGB555 slot-5 provider | Surface / UID0000OC | Separate sibling; shared ABI, separate body |
| `0x00462300-0x00462317` | `AlphaMaskSurface::GetBufferInfo` | AlphaMaskSurface / UID0000HF | Source accessor dependency |
| `0x00460410-0x004604f4` | `ApplyAlphaMap565` | SoftwareBlend16 / UID0000NT | Existing source-ready bulk wrapper |
| `0x00460c90-0x00460d51` | `Rgb565AlphaMapMmxBlocks` | SoftwareBlend16 / UID0000NT | Existing exact four-pixel MMX worker |
| `0x00558690-0x0055883d` | callback-family initializer | Surface / UID0000OC | Installs this provider in RGB565 family |
| `0x0069b3d8-0x0069b3e0` | 5/6-bit lookup roots | Surface / UID0000OC | Two typed globals, no target-body ownership |
| `0x0069b3f4-0x0069b3f8` | slot-5 callback global | Surface / UID0000OC | One typed global; physical UID0001PI stays non-duplicating |

No split or merge is required for the primary range. The accessor remains a support method within the existing alpha-surface inventory in this callback; creating a new exact child is not required to emit or understand UID0002TH and is therefore not added as speculative scope.

## Direct Xref / Caller Inventory

- Direct target refs: `0x5587ec` retained initializer RGB565 load and `0x558ece` inlined initializer RGB565 store.
- Indirect consumer: `MapPane::RenderMapView` at `0x50a267` calls through `0x69b3f4` with ECX=`this`, then pushes `m_selectionOverlay`, `&bounds`, `&bounds` in source order after stack reversal.
- Slot setup refs: `0x558791` shared retained-store path, `0x558bb2` compat inlined store, and `0x558ece` RGB565 inlined store.
- Accessor callers: exact target and compat peer only.
- `ApplyAlphaMap565` direct caller: exact target at `0x4c3db4`; helper ownership stays SoftwareBlend16.
- No vtable, export, direct call, registration object, or feature-pane member route points at the target.

## Documentation Evidence And IDA Status

- UID0000TN already uses source-ready typedef/global patterns for slots 0, 1, 3, 6, 7, and 9. Slot 5 alone retains a provisional byte-result description despite equivalent evidence closure.
- UID0004BL already supplies exact source C++ for `ApplyAlphaMap565`; UID00020A names the MMX child. The callback should call that helper rather than reimplementing the prefix.
- UID0001TQ and UID0001TP already record the 0x14 view and 0x28 object layouts. This report resolves the source-facing field declaration to one-byte ownership plus explicit three-byte padding, preserving the observed copied dword.
- UID0004QY/UID00007Q prove `AlphaMaskSurface *m_selectionOverlay`; B010 corrected the historical `&m_selectionOverlay` documentation/formal-code bug to pass the owned pointer itself under the exact callback ABI.
- At both the historical accepted snapshot and the current primary-supervisor read-only preflight, IDA had enough GrafPort/RectBounds structure to decompile destination state correctly, but the four function names/types, the view/callback types, physical global-item widths, and comments had not received this report's transaction. The three global name-table symbols were already present at their exact addresses and are preserved rather than redundantly treated as blank-name discoveries. Posttransaction authority still requires serial apply/readback, one save, and independent persisted reopen.

## Ranked Ownership Analysis

1. [UID:0000OC] Surface: accepted. Owns callback globals, initializer, format-selected provider families, generated `render/Surface.cpp`, and existing neighboring callbacks.
2. [UID:0000TN] SurfaceRenderCallbackTable: declaration/global support owner only. It emits one typedef/extern/definition but not the callback body.
3. [UID:0000NT] SoftwareBlend16: helper owner only. It owns `ApplyAlphaMap565` and MMX math, not clipping, source translation, or dispatch.
4. [UID:0000HF]/[UID:00000C] AlphaMaskSurface: source-object and accessor dependency only.
5. [UID:00007Q] MapPane: sole runtime consumer observed, not callback owner.
6. UID00016L/UID0001PI: non-emitting inventory/physical-storage evidence only.
7. RankingEventListPane: rejected. No target, slot, helper, field, initializer, or source-root evidence supports this generated alias.

## Source Placement

- Exact target body: file-local provider in `NexusTK/render/Surface.cpp`, emitted through UID0000OC.
- Slot typedef/extern and lookup-root externs: `NexusTK/render/Surface.h`, emitted once through UID0000TN.
- Slot and lookup-root definitions: `NexusTK/render/Surface.cpp`, emitted once through UID0000TN before provider/initializer use.
- Alpha view and source-object declarations remain in the AlphaMaskSurface header/module; helper bodies remain in SoftwareBlend16.
- Source order remains the existing Surface callback family order: compat providers, RGB565 providers, then initializer. No new source file is justified.

## Range / Split / Padding / Reclassification Analysis

- Primary half-open range is exact and closed by modeled function end plus thirteen successor `0xcc` bytes.
- Fifteen predecessor `0xcc` bytes belong to the preceding scaled-RLE callback alignment and are excluded.
- The target is one nine-block/150-instruction function with one prologue/cookie/epilogue and `retn 0x0c`; no internal split is justified.
- Do not merge with UID0002TG, UID0002TI, UID00016L, UID0002TD, or the physical callback table. They are separate function, aggregate, sibling, or storage entities.
- Reclassify only source readiness: the target remains reconstructable and emitting; it changes from blank body/empty marker to exact callback body.

## Negative Evidence Summary

- No direct ordinary code caller exists; this is expected for a callback selected through fixed global storage.
- No consumer reads AL/EAX, and exits leave path-dependent register values; byte-return C++ is rejected.
- No source call supplies MM1, and the MMX child destroys incoming MM1 before semantic work; an MM1 parameter is rejected.
- No common table-object base is indexed; a struct/table object source model is rejected in favor of twelve globals.
- No RankingEventListPane relationship exists beyond polluted generated naming.
- No evidence supports moving the body into MapPane, AlphaMaskSurface, SoftwareBlend16, or an aggregate.
- Original private lexical spellings are stripped. This does not justify raw names; the report selects project-consistent human names and keeps the uncertainty in confidence rather than in emitted source.

## IDA Rename / Type / Comment Recommendations

All rows are supervisor-owned and remain unapplied. The literal prestates below were accepted on `2026-08-04T19:41:12-04:00` from ephemeral IDB session `supervisor-uid0003fs-rollback-reopen` PID `5076`, transport session `57de975c-3c00-4425-9fa1-024188a0c19c`, and canonical disk IDB SHA256 `B8B1CFB3E7B660AC394A904F4FBFAF05B6E99A8B074DACC1431E9CD1C865A299`, 143196536 bytes. B010 later reconfirmed them under historical snapshot `A4B44EBE405077D2750E2388DF781A7CB7DDA9E419C34645679A412787B5329B`, 143196656 bytes, and the primary supervisor reconfirmed them under now-historical `23B89BF35334D876FE63C04AE15C4F90AEF4DF41FAF9D79580F25D244A214283`, 143196749 bytes. B010's current full read-only preflight reconfirmed every I01-I06 semantic prestate/protection row in sole session `b005-uid0001ny-postsave-reopen` PID `24380` against canonical SHA256 `115491A99AE02621692E9F7AF4C9E3F011E77DD9678AF996A39A86AA02837695`, 143196991 bytes. The current result grants no action/save/persistence credit; any later session or disk-identity change requires exact rebase and fresh Gate 1 rather than silent adaptation.

### I01 - Types

- Exact accepted prestate: `type_inspect` and `type_query` both found no `AlphaSurfaceBufferView`; no type, member, relationship, or type-comment-bearing record existed. `SurfaceAlphaLookupBlitProc` was also absent. `AlphaMaskSurface` existed as ordinal 696 with declaration `AlphaMaskSurface`, kind `other`, `is_udt:false`, unknown size `18446744073709551615`, zero members, no relationships, and no comment field exposed by either bounded type API. `GrafPort` was a complete 0xa0 UDT and `RectBounds` was a complete 0x10 UDT. No proposed function name existed. Each proposed global name existed only at its intended address, so there was no off-address collision.
- Deterministic safe scope: do not define, upgrade, replace, resize, comment, or add members to `AlphaMaskSurface`. Its incomplete named type is sufficient for pointer signatures. Do not change `GrafPort` or `RectBounds`.
- Exact `declare_type` operation 1:

```cpp
struct AlphaSurfaceBufferView {
    unsigned char *pixels;
    int width;
    int height;
    int stride;
    bool ownsBuffer;
    unsigned char padding[3];
};
```

- Literal operation-1 poststate: `AlphaSurfaceBufferView` is a complete struct/UDT of size 0x14 with `pixels +0x00 size0x04 unsigned char *`, `width +0x04 size0x04 int`, `height +0x08 size0x04 int`, `stride +0x0c size0x04 int`, `ownsBuffer +0x10 size0x01 bool`, and `padding +0x11 size0x03 unsigned char[3]`; no additional members and no type-comment mutation. The human source-facing member name matches the accepted formal H declaration rather than retaining an offset-derived IDA label.
- Exact `declare_type` operation 2:

```cpp
typedef void (__thiscall *SurfaceAlphaLookupBlitProc)(
    struct GrafPort *port,
    const AlphaMaskSurface *alphaSurface,
    const struct RectBounds *sourceBounds,
    const struct RectBounds *destinationBounds);
```

- Literal operation-2 poststate: `SurfaceAlphaLookupBlitProc` exists as one four-byte function-pointer typedef with the complete declaration above and no members or type-comment mutation. `AlphaMaskSurface`, `GrafPort`, and `RectBounds` retain the exact prestates above.

### I02 - Target `0x004c3cf0`

- Entity prestate: one code item head `[0x004c3cf0,0x004c3cf1)`, size 1, `is_code:true`, function `[0x004c3cf0,0x004c3e93)`, size 0x1a3, name `sub_4C3CF0`, full type `char __userpurge@<al>(const struct GrafPort *@<ecx>, __m64@<mm1>, int, __m64 *, const struct RectBounds *secondBounds)`.
- Bytes and references: 419 bytes, SHA256 `E01E7BED7A2E3B8CDF199D0193E7309A295328DCDC1BE2996EA85EEAE5BFD451`; first 16 bytes `55 8b ec 83 ec 54 a1 24 2f 67 00 33 c5 89 45 fc`; last 16 bytes `5f 5e 33 cd 5b e8 a2 38 10 00 8b e5 5d c2 0c 00`; ordered xrefs `0x5587ec data InitializeSurfaceRenderCallbacks`, `0x558ece data sub_558840`; predecessor `[0x004c3ce1,0x004c3cf0)` is 15 `cc` bytes and successor `[0x004c3e93,0x004c3ea0)` is 13 `cc` bytes.
- Comment-channel prestate: address regular `absent`; address repeatable `absent`; function regular `absent`; function repeatable `absent`.
- Complete pre-frame: `var_54 +0x0c size0x0c int[3]`; `var_48 +0x18 size0x04 _DWORD`; `var_40 +0x20 size0x04 _DWORD`; `var_3C +0x24 size0x04 _DWORD`; `var_38 +0x28 size0x04 _DWORD`; `var_34 +0x2c size0x04 _DWORD`; `var_30 +0x30 size0x04 _DWORD`; `var_2C +0x34 size0x04 _DWORD`; `var_28 +0x38 size0x04 _DWORD`; `bounds +0x3c size0x10 struct RectBounds`; `outBounds +0x4c size0x10 struct RectBounds`; `var_4 +0x5c size0x04 _DWORD`; `__saved_registers +0x60 size0x04 _DWORD`; `__return_address +0x64 size0x04 _UNKNOWN *`; `arg_0 +0x68 size0x04 _DWORD`; `arg_4 +0x6c size0x04 _DWORD`; `secondBounds +0x70 size0x04 struct RectBounds *`.
- Exact operation: rename function to `SoftwareRenderRgb565AlphaLookupBlitCallback`; set full type `void __thiscall SoftwareRenderRgb565AlphaLookupBlitCallback(struct GrafPort *port, const AlphaMaskSurface *alphaSurface, const struct RectBounds *sourceBounds, const struct RectBounds *destinationBounds)`; set function regular comment `Surface slot-5 RGB565 provider: clips destination, translates AlphaMaskSurface source, applies a four-pixel ApplyAlphaMap565 prefix, then scales the RGB565 tail through the 5/6-bit lookup roots.`; set address repeatable comment `Selected into g_pfnBlitAlphaLookup by the RGB565 Surface initializer; logical source return is void and incoming MM1 is not an ABI parameter.`; make no local-type operation.
- Literal post-frame: `var_54 +0x0c size0x0c int[3]`; `var_48 +0x18 size0x04 _DWORD`; `var_40 +0x20 size0x04 _DWORD`; `var_3C +0x24 size0x04 _DWORD`; `var_38 +0x28 size0x04 _DWORD`; `var_34 +0x2c size0x04 _DWORD`; `var_30 +0x30 size0x04 _DWORD`; `var_2C +0x34 size0x04 _DWORD`; `var_28 +0x38 size0x04 _DWORD`; `bounds +0x3c size0x10 struct RectBounds`; `outBounds +0x4c size0x10 struct RectBounds`; `var_4 +0x5c size0x04 _DWORD`; `__saved_registers +0x60 size0x04 _DWORD`; `__return_address +0x64 size0x04 _UNKNOWN *`; `alphaSurface +0x68 size0x04 const AlphaMaskSurface *`; `sourceBounds +0x6c size0x04 const struct RectBounds *`; `destinationBounds +0x70 size0x04 const struct RectBounds *`. No fourth stack argument and no MM1 frame row exist.
- Literal poststate: range, bytes, hash, xrefs, and padding remain exact; name/type equal the operation; address regular remains `absent`; address repeatable equals the exact text above; function regular equals the exact text above; function repeatable remains `absent`.

### I03 - Accessor `0x00462300`

- Entity prestate: one code item head `[0x00462300,0x00462301)`, size 1, `is_code:true`, function `[0x00462300,0x00462317)`, size 0x17, name `sub_462300`, full type `int __thiscall(int this, int)`.
- Bytes and references: 23 bytes, SHA256 `580C7557AA8D137C3E8AB8C7AC4C823AE4A76E1460C4FD88B9B3799F733E5501`; first 16 bytes `55 8b ec 8b 45 08 0f 10 41 14 8b 49 24 0f 11 00`; last 16 bytes `10 41 14 8b 49 24 0f 11 00 89 48 10 5d c2 04 00`; ordered xrefs `0x4bdfb5 code sub_4BDF40`, `0x4c3d65 code sub_4C3CF0`.
- Comment-channel prestate: address regular `absent`; address repeatable `absent`; function regular `absent`; function repeatable `absent`.
- Complete pre-frame: `__saved_registers +0x00 size0x04 _DWORD`; `__return_address +0x04 size0x04 _UNKNOWN *`; `arg_0 +0x08 size0x04 _DWORD`.
- Exact operation: rename function to `AlphaMaskSurface__GetBufferInfo`; set full type `void __thiscall AlphaMaskSurface__GetBufferInfo(const AlphaMaskSurface *surface, struct AlphaSurfaceBufferView *outView)`; set function regular comment `Copies the five-field 0x14 alpha-surface buffer view from object offsets +0x14..+0x27.`; set address repeatable comment `Source-facing AlphaMaskSurface::GetBufferInfo; return-register value is stale output-pointer residue.`
- Literal post-frame: `__saved_registers +0x00 size0x04 _DWORD`; `__return_address +0x04 size0x04 _UNKNOWN *`; `outView +0x08 size0x04 struct AlphaSurfaceBufferView *`. ECX is not a stack row.
- Literal poststate: range, bytes, hash, and ordered xrefs remain exact; name/type equal the operation; address regular remains `absent`; address repeatable equals the exact text above; function regular equals the exact text above; function repeatable remains `absent`.

### I04 - Wrapper `0x00460410`

- Entity prestate: one code item head `[0x00460410,0x00460411)`, size 1, `is_code:true`, function `[0x00460410,0x004604f4)`, size 0xe4, name `sub_460410`, full type `int __usercall@<eax>(__m64@<mm1>, __m64 *, int, unsigned int *, int, int, int)`.
- Bytes and references: 228 bytes, SHA256 `55D18785F8BADE4ECA802066E4B1A5FE8C7C096266B9A647B67B76D993CD2646`; first 16 bytes `55 8b ec 83 ec 08 8b 45 18 99 83 e2 03 53 8b 5d`; last 16 bytes `5d fc 89 45 1c 85 c0 7f 83 5f 5e 5b 8b e5 5d c3`; sole ordered xref `0x4c3db4 code sub_4C3CF0`.
- Comment-channel prestate: address regular `absent`; address repeatable `absent`; function regular `absent`; function repeatable `absent`.
- Complete pre-frame: `var_8 +0x0c size0x04 _DWORD`; `var_4 +0x10 size0x04 _DWORD`; `__saved_registers +0x14 size0x04 _DWORD`; `__return_address +0x18 size0x04 _UNKNOWN *`; `arg_0 +0x1c size0x04 _DWORD`; `arg_4 +0x20 size0x04 _DWORD`; `arg_8 +0x24 size0x04 _DWORD`; `arg_C +0x28 size0x04 _DWORD`; `arg_10 +0x2c size0x04 _DWORD`; `arg_14 +0x30 size0x04 _DWORD`.
- Exact operation: rename function to `ApplyAlphaMap565`; set full type `void __cdecl ApplyAlphaMap565(unsigned __int16 *pixels, int pixelPitchBytes, const unsigned __int8 *alphaBytes, int alphaPitchBytes, int widthPixels, int rowCount)`; set function regular comment `Applies per-byte alpha to RGB565 rows using four-pixel MMX blocks plus an exact scalar tail.`; set address repeatable comment `SoftwareBlend16 helper; incoming MM1 is compiler residue, not source ABI.`
- Literal post-frame: `var_8 +0x0c size0x04 _DWORD`; `var_4 +0x10 size0x04 _DWORD`; `__saved_registers +0x14 size0x04 _DWORD`; `__return_address +0x18 size0x04 _UNKNOWN *`; `pixels +0x1c size0x04 unsigned __int16 *`; `pixelPitchBytes +0x20 size0x04 signed __int32`; `alphaBytes +0x24 size0x04 const unsigned __int8 *`; `alphaPitchBytes +0x28 size0x04 signed __int32`; `widthPixels +0x2c size0x04 signed __int32`; `rowCount +0x30 size0x04 signed __int32`. No MM1 frame row exists.
- Literal poststate: range, bytes, hash, and ordered xref remain exact; name/type equal the operation; address regular remains `absent`; address repeatable equals the exact text above; function regular equals the exact text above; function repeatable remains `absent`.

### I05 - MMX child `0x00460c90`

- Entity prestate: one code item head `[0x00460c90,0x00460c91)`, size 1, `is_code:true`, function `[0x00460c90,0x00460d51)`, size 0xc1, name `sub_460C90`, full type `__m64 *__usercall@<eax>(__m64@<mm1>, __m64 *, int, unsigned int *, int, int, int)`.
- Bytes and references: 193 bytes, SHA256 `3278FA85924636835674F17485FAD98C2625163834E4FCFDA50F79836014FA8D`; first 16 bytes `55 8b ec 8b 45 18 53 56 c1 e0 02 57 89 45 18 66`; last 16 bytes `14 49 e9 73 ff ff ff 66 61 0f 77 5f 5e 5b 5d c3`; sole ordered xref `0x46043f code sub_460410`.
- Comment-channel prestate: address regular `absent`; address repeatable `absent`; function regular `absent`; function repeatable `absent`.
- Complete pre-frame: `__saved_registers +0x0c size0x04 _DWORD`; `__return_address +0x10 size0x04 _UNKNOWN *`; `arg_0 +0x14 size0x04 _DWORD`; `arg_4 +0x18 size0x04 _DWORD`; `arg_8 +0x1c size0x04 _DWORD`; `arg_C +0x20 size0x04 _DWORD`; `arg_10 +0x24 size0x04 _DWORD`; `arg_14 +0x28 size0x04 _DWORD`.
- Exact operation: rename function to `Rgb565AlphaMapMmxBlocks`; set full type `void __cdecl Rgb565AlphaMapMmxBlocks(unsigned __int16 *pixels, int pixelPitchBytes, const unsigned __int8 *alphaBytes, int alphaPitchBytes, int blockCount4Pixels, int rowCount)`; set function regular comment `Processes four RGB565 pixels per block with parallel alpha bytes.`; set address repeatable comment `Clears MM1 internally before semantic use; no incoming MM1 source parameter.`
- Literal post-frame: `__saved_registers +0x0c size0x04 _DWORD`; `__return_address +0x10 size0x04 _UNKNOWN *`; `pixels +0x14 size0x04 unsigned __int16 *`; `pixelPitchBytes +0x18 size0x04 signed __int32`; `alphaBytes +0x1c size0x04 const unsigned __int8 *`; `alphaPitchBytes +0x20 size0x04 signed __int32`; `blockCount4Pixels +0x24 size0x04 signed __int32`; `rowCount +0x28 size0x04 signed __int32`. No MM1 frame row exists.
- Literal poststate: range, bytes, hash, and ordered xref remain exact; name/type equal the operation; address regular remains `absent`; address repeatable equals the exact text above; function regular equals the exact text above; function repeatable remains `absent`.

### I06 - Globals

Each xref list below is complete, ordered ascending, and consists of data xrefs. `inspect_items.name` was blank on every undefined one-byte head, while `entity_query(kind=names)` supplied the stated name-table symbol. This dual prestate must be reproduced exactly before `make_data`.

- `0x0069b3d8`: prestate head `[0x69b3d8,0x69b3d9)`, size 1, undefined (`is_code:false`, `is_data:false`), item-name field blank, name-table symbol `g_surfaceColorLookup5Bit`, type `unsigned __int8 **`, bytes `00 00 00 00`, value `0x0`, regular comment `absent`, repeatable comment `absent`. Ordered xrefs: `0x4bde35(sub_4BDCC0)`, `0x4be04a(sub_4BDF40)`, `0x4bedf9(sub_4BEDE0)`, `0x4c3bd6(sub_4C3A50)`, `0x4c3bf7(sub_4C3A50)`, `0x4c3e0b(sub_4C3CF0)`, `0x4c4738(sub_4C4730)`, `0x556ab6(ScreenPane__Destructor)`, `0x556acf(ScreenPane__Destructor)`, `0x558c95(sub_558840)`, `0x558caa(sub_558840)`, `0x558cf7(sub_558840)`.
- Exact `0x0069b3d8` operation: `make_data` one dword at `0x69b3d8` with `delete_existing:true`, exact name `g_surfaceColorLookup5Bit`, exact IDA type `unsigned __int8 **`; set regular address comment `32 rows by 256 alpha entries used for five-bit RGB channels.`; do not write a repeatable comment.
- Literal `0x0069b3d8` poststate: one data item `[0x69b3d8,0x69b3dc)`, size 4, name `g_surfaceColorLookup5Bit`, type `unsigned __int8 **`, bytes `00 00 00 00`, value `0x0`, regular comment equal to the exact operation text, repeatable comment `absent`, and the exact 12-xref list above.

- `0x0069b3dc`: prestate head `[0x69b3dc,0x69b3dd)`, size 1, undefined (`is_code:false`, `is_data:false`), item-name field blank, name-table symbol `g_surfaceColorLookup6Bit`, type `unsigned __int8 **`, bytes `00 00 00 00`, value `0x0`, regular comment `absent`, repeatable comment `absent`. Ordered xrefs: `0x4bde4c(sub_4BDCC0)`, `0x4be065(sub_4BDF40)`, `0x4bede3(sub_4BEDE0)`, `0x4c3bc6(sub_4C3A50)`, `0x4c3dfc(sub_4C3CF0)`, `0x4c4733(sub_4C4730)`, `0x556aec(ScreenPane__Destructor)`, `0x556b05(ScreenPane__Destructor)`, `0x558d24(sub_558840)`, `0x558d5a(sub_558840)`, `0x558da8(sub_558840)`.
- Exact `0x0069b3dc` operation: `make_data` one dword at `0x69b3dc` with `delete_existing:true`, exact name `g_surfaceColorLookup6Bit`, exact IDA type `unsigned __int8 **`; set regular address comment `64 rows by 256 alpha entries used for the six-bit green channel.`; do not write a repeatable comment.
- Literal `0x0069b3dc` poststate: one data item `[0x69b3dc,0x69b3e0)`, size 4, name `g_surfaceColorLookup6Bit`, type `unsigned __int8 **`, bytes `00 00 00 00`, value `0x0`, regular comment equal to the exact operation text, repeatable comment `absent`, and the exact 11-xref list above.

- `0x0069b3f4`: prestate head `[0x69b3f4,0x69b3f5)`, size 1, undefined (`is_code:false`, `is_data:false`), item-name field blank, name-table symbol `g_pfnBlitAlphaLookup`, type `int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD)`, bytes `00 00 00 00`, value `0x0`, regular comment `absent`, repeatable comment `absent`. Ordered xrefs: `0x50a267(MapPane__RenderMapView)`, `0x558791(InitializeSurfaceRenderCallbacks)`, `0x558bb2(sub_558840)`, `0x558ece(sub_558840)`.
- Exact `0x0069b3f4` operation: `make_data` one dword at `0x69b3f4` with `delete_existing:true`, exact name `g_pfnBlitAlphaLookup`, exact type `SurfaceAlphaLookupBlitProc`; set regular address comment `Surface slot 5; selected compat/RGB555 or RGB565 alpha-mask provider.`; do not write a repeatable comment.
- Literal `0x0069b3f4` poststate: one data item `[0x69b3f4,0x69b3f8)`, size 4, name `g_pfnBlitAlphaLookup`, type `SurfaceAlphaLookupBlitProc`, bytes `00 00 00 00`, value `0x0`, regular comment equal to the exact operation text, repeatable comment `absent`, and the exact four-xref list above.

Immediate protected-neighbor rows are literal no-change contracts:

| Address | Exact byte/item/name/type/comments | Complete ordered xref set |
| --- | --- | --- |
| `0x69b3d4` | byte `00`; head `[d4,d5)` size1 undefined; name-table `g_surfaceUses32BitPresentation`; type `bool`; regular `absent`; repeatable `absent` | `0x5586cf`, `0x5586eb`, `0x5587c4`, `0x558b56`, `0x558b72`, `0x558e79`, `0x55960e` |
| `0x69b3d5` | byte `00`; head `[d5,d6)` size1 undefined; name-table `g_surfaceUsesRgb565Pixels`; type `bool`; regular `absent`; repeatable `absent` | `0x458560`, `0x4abac5`, `0x542f58`, `0x5579b7`, `0x557d1e`, `0x55805a`, `0x5586d6`, `0x5586f2`, `0x5587d1`, `0x5587da`, `0x558b5d`, `0x558b79`, `0x558d29`, `0x558e86`, `0x558e8f`, `0x5c02ce` |
| `0x69b3d6` | byte `00`; head `[d6,d7)` size1 undefined; name `absent`; type `absent`; regular `absent`; repeatable `absent` | empty |
| `0x69b3d7` | byte `00`; head `[d7,d8)` size1 undefined; name `absent`; type `absent`; regular `absent`; repeatable `absent` | empty |
| `0x69b3e0` | byte `00`; head `[e0,e1)` size1 undefined; name-table `g_pfnDrawPixel`; type `SurfaceDrawPixelProc`; regular `absent`; repeatable `absent` | `0x55875f`, `0x558b80`, `0x558e9c`, `0x5c15d4`, `0x5c1641`, `0x5c16b4`, `0x5c171e`, `0x5c178b`, `0x5c17f8`, `0x5c1977`, `0x5c19e7`, `0x5c1a61`, `0x5c1acc`, `0x5c1b3a`, `0x5c1ba8` |
| `0x69b3e1` | byte `00`; head `[e1,e2)` size1 undefined; name `absent`; type `absent`; regular `absent`; repeatable `absent` | empty |
| `0x69b3e2` | byte `00`; head `[e2,e3)` size1 undefined; name `absent`; type `absent`; regular `absent`; repeatable `absent` | empty |
| `0x69b3e3` | byte `00`; head `[e3,e4)` size1 undefined; name `absent`; type `absent`; regular `absent`; repeatable `absent` | empty |
| `0x69b3f0` | byte `00`; head `[f0,f1)` size1 undefined; name-table `g_pfnBlitScaledRleTint`; type `SurfaceScaledRleTintProc`; regular `absent`; repeatable `absent` | `0x4d7044`, `0x4d70e2`, `0x4d7685`, `0x4d7727`, `0x4d77c9`, `0x4d786b`, `0x4d790d`, `0x4d79af`, `0x4d7a4e`, `0x4d7ad4`, `0x4d7b75`, `0x4d7c1b`, `0x4d7cb9`, `0x4db310`, `0x4dc9fb`, `0x4e44f4`, `0x4e457f`, `0x4e4cf8`, `0x558768`, `0x558ba8`, `0x558ec4` |
| `0x69b3f1` | byte `00`; head `[f1,f2)` size1 undefined; name `absent`; type `absent`; regular `absent`; repeatable `absent` | empty |
| `0x69b3f2` | byte `00`; head `[f2,f3)` size1 undefined; name `absent`; type `absent`; regular `absent`; repeatable `absent` | empty |
| `0x69b3f3` | byte `00`; head `[f3,f4)` size1 undefined; name `absent`; type `absent`; regular `absent`; repeatable `absent` | empty |
| `0x69b3f8` | byte `00`; head `[f8,f9)` size1 undefined; name-table `g_pfnBlitBitmask`; type `SurfaceBitmaskBlitProc`; regular `absent`; repeatable `absent` | `0x467c29`, `0x467c5e`, `0x467c92`, `0x467cd3`, `0x467d08`, `0x467d39`, `0x467d6b`, `0x467e5d`, `0x467efb`, `0x55879d`, `0x558bbc`, `0x558ed8` |
| `0x69b3f9` | byte `00`; head `[f9,fa)` size1 undefined; name `absent`; type `absent`; regular `absent`; repeatable `absent` | empty |
| `0x69b3fa` | byte `00`; head `[fa,fb)` size1 undefined; name `absent`; type `absent`; regular `absent`; repeatable `absent` | empty |
| `0x69b3fb` | byte `00`; head `[fb,fc)` size1 undefined; name `absent`; type `absent`; regular `absent`; repeatable `absent` | empty |

Do not aggregate any callback/global block into a struct and do not materialize or alter any protected-neighbor item.

### Literal Transaction And Rollback Envelope

1. Dynamic preflight: obtain fresh `idb_list` and `server_health`; verify canonical path; hash and size the canonical disk IDB; rerun every I01-I06 type/name/item/comment/frame/byte/xref query. Continue only when every literal row matches this accepted prestate. Session/PID identity may rotate, but content may not drift.
2. Collision preflight: `lookup_funcs` must return Not found for all four proposed function names; `type_inspect` must report `AlphaSurfaceBufferView` and `SurfaceAlphaLookupBlitProc` absent; `AlphaMaskSurface` must retain its exact incomplete prestate; `entity_query` must map each proposed global name only to its intended address. No overwrite of an off-address symbol is allowed.
3. Backup: require absent destination `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0002TH-prestate`; copy the canonical IDB byte-for-byte to that exact path; for the current reconciled transaction verify backup size 143196991 and SHA256 `115491A99AE02621692E9F7AF4C9E3F011E77DD9678AF996A39A86AA02837695` before any mutation. If the canonical disk identity changes again, stop for same-report reconciliation and fresh Gate 1; do not reuse any dated hash silently.
4. Apply I01 operation 1 and read back the literal AlphaSurfaceBufferView poststate. Apply I01 operation 2 and read back the literal typedef poststate. Recheck preserved AlphaMaskSurface, GrafPort, and RectBounds.
5. Apply I02 only, then read back its exact name, full type, four comment channels, complete frame, bytes, hash, xrefs, and padding.
6. Apply I03 only, then read back its exact name, full type, four comment channels, complete frame, bytes, hash, and xrefs.
7. Apply I04 only, then read back its exact name, full type, four comment channels, complete frame, bytes, hash, and xref.
8. Apply I05 only, then read back its exact name, full type, four comment channels, complete frame, bytes, hash, and xref.
9. Apply the three I06 global operations one address at a time in ascending order. After each operation, read back the literal global poststate and all 16 protected-neighbor rows before continuing.
10. Full pre-save readback: repeat I01-I06 in full, including all function frames/comment channels, all global item/comment/value/xref rows, and every protected neighbor. Do not save on any mismatch.
11. Save exactly once with `idb_save` only after steps 1-10 pass. Record the saved canonical path, new byte size, and new SHA256.
12. Independently reopen the saved canonical IDB in a fresh session, rerun every I01-I06 literal poststate and protection row, and compare the reopened canonical disk identity to the just-recorded saved identity. The reopened session is a dated persistence witness, not permanent authority.
13. No-save rollback: on any failure before step 11, close/discard the mutated unsaved worker without saving, verify the canonical disk remains 143196991 bytes with SHA256 `115491A99AE02621692E9F7AF4C9E3F011E77DD9678AF996A39A86AA02837695`, reopen independently, and prove the complete I01-I06 prestate.
14. Saved rollback: on save failure, reopen failure, or persisted readback mismatch after step 11, close all sessions on the canonical path, replace the canonical file from the exact verified step-3 backup, verify the restored current reconciled size/hash above, reopen independently, and prove the complete I01-I06 prestate before reporting failure. Never attempt a second save inside the failed transaction.

## First-Draft C++ Recommendation

Exact target formal CPP insertion:

```cpp
static void __thiscall SoftwareRenderRgb565AlphaLookupBlitCallback(
    GrafPort *port,
    const AlphaMaskSurface *alphaSurface,
    const RectBounds *sourceBounds,
    const RectBounds *destinationBounds)
{
    if (!port->m_drawEnabled) {
        return;
    }

    RectBounds clipBounds;
    port->GetClipRect(&clipBounds);

    RectBounds clippedBounds;
    IntersectRects(&clipBounds, destinationBounds, &clippedBounds);
    if (IsRectEmptyOrInvalid(&clippedBounds)) {
        return;
    }

    AlphaSurfaceBufferView sourceView;
    alphaSurface->GetBufferInfo(&sourceView);

    const int sourceX =
        sourceBounds->left + clippedBounds.left - destinationBounds->left;
    const int sourceY =
        sourceBounds->top + clippedBounds.top - destinationBounds->top;
    const unsigned char *sourceRow =
        sourceView.pixels + sourceY * sourceView.stride + sourceX;

    const int destinationPitchBytes =
        2 * port->m_surfaceContext.rowStridePixels;
    unsigned char *destinationBytes =
        static_cast<unsigned char *>(port->m_surfaceContext.pixelData) +
        2 * clippedBounds.left +
        destinationPitchBytes * clippedBounds.top;
    unsigned short *destinationRow =
        reinterpret_cast<unsigned short *>(destinationBytes);

    const int width = clippedBounds.right - clippedBounds.left;
    const int height = clippedBounds.bottom - clippedBounds.top;
    const int bulkWidth = width & ~3;

    ApplyAlphaMap565(
        destinationRow,
        destinationPitchBytes,
        sourceRow,
        sourceView.stride,
        bulkWidth,
        height);

    const int tailWidth = width - bulkWidth;
    destinationRow += bulkWidth;
    sourceRow += bulkWidth;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < tailWidth; ++x) {
            const unsigned short pixel = destinationRow[x];
            const unsigned char alpha = sourceRow[x];
            const unsigned int red =
                g_surfaceColorLookup5Bit[pixel >> 11][alpha];
            const unsigned int green =
                g_surfaceColorLookup6Bit[(pixel >> 5) & 0x3f][alpha];
            const unsigned int blue =
                g_surfaceColorLookup5Bit[pixel & 0x1f][alpha];

            destinationRow[x] = static_cast<unsigned short>(
                (red << 11) | (green << 5) | blue);
        }

        destinationRow = reinterpret_cast<unsigned short *>(
            reinterpret_cast<unsigned char *>(destinationRow) +
            destinationPitchBytes);
        sourceRow += sourceView.stride;
    }
}
```

Exact UID0000TN H additions, preserving all existing declarations:

```cpp
class AlphaMaskSurface;

typedef void (__thiscall *SurfaceAlphaLookupBlitProc)(
    GrafPort *port,
    const AlphaMaskSurface *alphaSurface,
    const RectBounds *sourceBounds,
    const RectBounds *destinationBounds);

extern unsigned char **g_surfaceColorLookup5Bit;
extern unsigned char **g_surfaceColorLookup6Bit;
extern SurfaceAlphaLookupBlitProc g_pfnBlitAlphaLookup;
```

Exact UID0000TN CPP additions, preserving all existing definitions:

```cpp
unsigned char **g_surfaceColorLookup5Bit;
unsigned char **g_surfaceColorLookup6Bit;
SurfaceAlphaLookupBlitProc g_pfnBlitAlphaLookup;
```

Exact UID0001TQ H block:

```cpp
struct AlphaSurfaceBufferView
{
    unsigned char *pixels;
    int width;
    int height;
    int stride;
    bool ownsBuffer;
    unsigned char padding[3];
};
```

Target H remains blank because the provider is `static` in `Surface.cpp`. The body deliberately contains no IDA labels, raw offsets, MMX pseudo-arguments, cookies, explicit register state, or duplicated helper body. It preserves the target's unusual destination addressing exactly; do not add subtraction of `m_surfaceContext.bounds` without contrary binary evidence.

## Final Recommendation

- B010 implemented UID0002TH as source-ready at `92/94` with the exact body and unchanged Surface route.
- B010 implemented the slot-5 `void` typedef/global and source-facing names in UID0000TN and corrected MapPane's address-of mistake.
- B010 implemented the AlphaSurfaceBufferView formal POD and alpha accessor semantics while retaining the documented `IntAlphaSurface` naming history as an implementation-family ambiguity rather than leaking it into this callback's source name.
- Accept IDA I01-I06 only as one guarded supervisor transaction; partial application or B-agent mutation is forbidden.
- Do not merge the compat peer or write its body in this report. Its shared ABI/source-view closure should be incorporated, but its exact RGB555 formal body remains its own target.
- No in-scope question remains a generic future-investigation blocker. Remaining uncertainty is original private spelling and final binary-diff audit, reflected by the sub-95 score.

## Recommended Target Doc Changes

- Applied: stale blank-C++/no-name-blocker language is superseded by exact ABI, return/MM1 rejection, source object/view, destination/source arithmetic, bulk helper, lookup tail, ownership, and source-placement findings.
- Applied: exact formal CPP body installed; H remains blank.
- Applied: Item Summary is source-ready and metadata-aware.
- Applied: historical score progression and old aliases remain visible as superseded evidence.
- Applied: dated MCP/session/disk and generated/manual evidence remains snapshot-scoped with dynamic-currentness wording.

## Recommended Support Doc Changes

- Applied to `by-global/SurfaceRenderCallbackTable.md`: typedef/extern/definitions, slot-5 ABI, provider/consumer refs, lookup-root route, and score rationale.
- Applied to `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`: exact typed slot-5 storage and non-duplicating physical role.
- Applied to `by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md`: exact typedef and two providers; existing formal assignments preserved.
- Applied to `by-memory/0x005094b0-0x0050a4fd.MapPaneRenderMapView.md` and `by-file/MapPane.md`: `m_selectionOverlay` pointer call, source/destination bounds, ownership, and consumer route.
- Applied to `by-type/by-struct/AlphaSurfaceBufferView.md`: exact formal H, byte ownership/padding, both providers, and `90/93` score rationale.
- Applied to the three AlphaMaskSurface pages: exact const logical-void accessor, caller set, callback-facing type, and retained IntAlphaSurface history without a partial class declaration.
- Applied to the two helper pages: exact caller/prototypes/MM1 proof, existing formal bodies, and SoftwareBlend16 ownership.
- Applied to the lookup-root page: source names/types, exact geometry, channel roles, complete refs, `93/95`, and covered-by route to prevent duplicate definitions.
- Applied to the compat peer: shared ABI/view/slot relationship and historicalized generic blocker; no peer body added.
- Applied to the RGB565 aggregate and Surface file: exact source-ready child inventory, declaration/body routes, and preserved non-emitting aggregate.

## Score And Metadata Recommendation

- UID0002TH report-start snapshot was `87/90`, owner/emitter `0000OC`, reconstructable true, blank formal CPP/H.
- UID0002TH implemented state is `92/94`, same owner/emitter/reconstructable/position, nonblank formal CPP, blank formal H.
- Score increase basis: every listed former blocker was investigated and resolved: exact logical return, callback typedef, stack arguments, alpha source object, view layout, helper names, lookup-global names, dispatch route, sibling relation, source owner, source file, and formal body.
- Reason not higher: original private spellings and const qualifiers are inferred, the compat peer's full body is not this report's target, and no compile/binary-diff audit has yet validated the draft. These are final-audit caps, not reasons to leave raw identifiers or blank code.
- Implemented support scores: UID0000TN `93/94 -> 94/95`, UID0001TQ `86/90 -> 90/93`, and UID00029V `92/94 -> 93/95`; other support scores remain unchanged.

## Open Questions With Attempted Resolution

- Callback return: resolved to source `void` through ignored result plus stale/path-dependent EAX.
- Callback argument count/order: resolved through `retn 0x0c`, MapPane push order, and target data flow.
- MM1: resolved as non-ABI compiler residue through unconditional in-child zeroing and absent caller setup.
- Source descriptor: resolved to `AlphaMaskSurface` with exact 0x14 `AlphaSurfaceBufferView` copy.
- Lookup globals: resolved to shared 5-bit and 6-bit color lookup roots through initialization geometry and channel indexing.
- Helper names: resolved to established `ApplyAlphaMap565` and `Rgb565AlphaMapMmxBlocks`.
- Owner/source placement: resolved to file-local Surface provider and one Surface callback global.
- Sibling relation: resolved as separate RGB555/RGB565 implementations of one slot ABI.
- Original lexical spelling: symbols are stripped, so exact original spelling cannot be proven. The selected names are the highest-probability project-consistent human names; raw labels are rejected rather than retained. This caps confidence but does not block source-ready C++.
- Final equivalence: compile/disassembly comparison is unavailable before implementation and is the remaining high-score audit. The first draft preserves every observed semantic operation and excludes compiler artifacts.
- Gate 2B currentness: resolved for this fresh Gate 1 baseline only. B010's full read-only I01-I06 preflight passed under canonical `115491A99AE02621692E9F7AF4C9E3F011E77DD9678AF996A39A86AA02837695`/143196991 in sole session `b005-uid0001ny-postsave-reopen` PID `24380`, with no semantic prestate drift. No operation, save, reopen, or persistence credit follows from preflight; any subsequent identity drift reopens same-report reconciliation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Manual files were read only. The supervisor should apply these exact replacements after ordinary implementation and before scoped coverage validation.

The `2026-08-05T15:03:22-04:00` read-only self-audit reconfirmed the exact physical target rows and indentation under current whole-file hashes: by-memory `1527EA746CE920B388BBF2C919D2882214BD12C760BE5CB9BBE5BBD5913AFCF8`, by-global `2CBB39DFA34BACD232F591089CBF060D09D113CE422815CC1D4AE80A61A3A360`, by-file `DDB134C5264A40E31ECA32BE214C1325AE8230903053B4D82CB9EDD41393E7D4`, and by-struct `4B6995A919504E744922F1C99BE53D7A2330B53BCF3B6B67DCD65E184107ABF1`. The exact replacements below remain absent and valid; the supervisor must still reread the rows immediately before editing because these shared files are mutable.

By-memory replacement for the report-start UID0002TH row, subject to supervisor reread before application:

```markdown
        - [UID:0002TH][0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback](by-memory/0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback.md) 0x004c3cf0-0x004c3e93 | function | SoftwareRenderRgb565AlphaLookupBlitCallback : reconstructable : 92% : very-strong : Source-ready Surface slot-5 RGB565 alpha-mask lookup callback with exact void GrafPort/AlphaMaskSurface/sourceBounds/destinationBounds ABI, two initializer target refs, one live slot dispatch, exact clipping/source translation, AlphaSurfaceBufferView layout, four-pixel ApplyAlphaMap565 prefix, 0..3-pixel lookup tail through g_surfaceColorLookup5Bit/g_surfaceColorLookup6Bit, clean padding, Surface ownership, and complete formal C++.
```

Replace only the existing UID0002TH row in place; do not alter either neighboring row.

By-memory replacement for UID00029V, subject to supervisor reread before application:

```markdown
    - [UID:00029V][0x0069b3d8-0x0069b3e0.SurfaceAlphaLookupTablePointers](by-memory/0x0069b3d8-0x0069b3e0.SurfaceAlphaLookupTablePointers.md) 0x0069b3d8-0x0069b3e0 | render lookup-table pointers | SurfaceAlphaLookupTablePointers : reconstructable : 93% : very-strong : Exact zero-initialized external Surface lookup-root pair g_surfaceColorLookup5Bit/g_surfaceColorLookup6Bit with unsigned char ** source types, 32/64 rows of 256 alpha entries, five-bit red/blue and six-bit RGB565-green roles, complete 12/11 initializer/provider/transform/cleanup xrefs, canonical Surface owner/emitter UID0000OC, and exact boundaries; semantic UID0000TN emits the sole declarations/definitions while this physical range retains one covered-by CPP comment and no duplicate declaration or definition.
```

Replace only the existing UID00029V row in place between UID00029U and UID0001PI; do not alter either neighboring row.

By-global UID0000TN replacement:

```markdown
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) : reconstructable : 94% : very-strong : Semantic/source owner for twelve fixed Surface render callback globals; Surface.h owns typed declarations/externs and Surface.cpp owns single definitions, now including exact slot-5 SurfaceAlphaLookupBlitProc g_pfnBlitAlphaLookup with void GrafPort/AlphaMaskSurface/sourceBounds/destinationBounds ABI, RGB555/RGB565 providers, live MapPane dispatch, and shared 5/6-bit lookup roots; physical UID0001PI retains exactly one non-emitting covered-by CPP comment and no physical data declaration, definition, or provider body, preventing duplicate storage.
```

By-file UID0000OC replacement, retaining 90 percent:

```markdown
- [UID:0000OC][Surface](by-file/Surface.md) : reconstructable : 90% : strong : Generated root NexusTK/render/Surface.cpp plus Surface.h callback declarations owns callback typedefs/definitions, initializer selection, pixel-format/lookup globals, software callback families, and true Surface helpers; slot 5 now has exact SurfaceAlphaLookupBlitProc storage plus source-ready RGB565 alpha-mask provider, shared compat relationship, AlphaMaskSurface view contract, and 5/6-bit lookup-tail semantics, while unrelated callback-family work remains independently bounded.
```

By-struct UID0001TQ replacement:

```markdown
- [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md) : reconstructable : 90% : very-strong : Exact 0x14-byte alpha-surface POD view with pixels, width, height, stride, one-byte ownsBuffer plus three bytes of padding; GetBufferInfo and clipped-view helpers prove all offsets, and both Surface slot-5 providers consume it for source-row translation.
```

Do not manually edit generated tracker or generated coverage. After coherent refresh, the supervisor must dynamically reread UID0002TH and affected support rows; report-count/lifecycle fields are validator-owned.

After the supervisor applies and validates the manual replacements, run one coherent generated refresh and verify: exactly one UID0002TH provider body; zero UID0002TH Empty Emitter Marker occurrences; exactly one canonical `SurfaceAlphaLookupBlitProc` typedef and one canonical `g_pfnBlitAlphaLookup` declaration/definition in Surface.h/Surface.cpp; exactly one canonical Surface.h declaration and Surface.cpp definition for each `g_surfaceColorLookup5Bit` and `g_surfaceColorLookup6Bit` while allowing normal extern declarations in consuming translation units; exactly one `AlphaSurfaceBufferView` declaration; MapPane passes `m_selectionOverlay` rather than `&m_selectionOverlay`; and UID0001PI/UID00029V introduce no duplicate declaration, definition, or provider body.

## Follow-Up Actions

- B010 callback is complete: accepted ordinary/formal claims were implemented serially, physically reread, validated with `--no-generated-refresh`, released, and reconciled in this same report.
- Primary supervisor Gate 2B: after this rebased report receives fresh Gate 1, apply or reject each I01-I06 row independently under the exact `115491A99AE02621692E9F7AF4C9E3F011E77DD9678AF996A39A86AA02837695`/143196991 transaction contract, recording actor/action/readback and persistence evidence. The completed read-only preflight is not implementation credit.
- Primary supervisor coverage/generated: apply the exact UID0002TH and UID00029V by-memory rows plus the UID0000TN, UID0000OC, and UID0001TQ manual rows; validate each changed manual report; run one coherent autogen refresh; and verify exactly one UID0002TH provider, zero UID0002TH empty-emitter markers, one callback typedef/global declaration/definition, one declaration/definition for each lookup root, one AlphaSurfaceBufferView declaration, the pointer-valued MapPane call, and no duplicate output from UID0001PI or UID00029V.
- No A-agent, third-party import, new report, report move, or execute action is assigned to B010 in this phase.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong for `92/94`; it is high enough for complete first-draft code and low enough to reserve final compile/binary-diff and original-spelling audit.
- Remaining uncertainty: exact original private names and const spelling only. No behavior, ownership, ABI, layout, dispatch, or source-placement blocker remains unresolved.

## Validator Results

- Report-first phase used no validator. Accepted implementation callback used the following scoped ordinary-document validators; every command exited `0`, reported `ok: 1`, and recorded `generated_refresh: skipped` because `--no-generated-refresh` was explicit.
- `21131` / `2026-08-04T20:06:38-04:00`: UID0002TH target.
- `21133` / `2026-08-04T20:07:35-04:00`: UID0000TN semantic callback table.
- `21134` / `2026-08-04T20:08:10-04:00`: UID0001PI physical callback storage.
- `21135` / `2026-08-04T20:08:44-04:00`: UID00039V initializer.
- `21136` / `2026-08-04T20:09:17-04:00`: UID0004QY MapPane render method.
- `21137` / `2026-08-04T20:09:54-04:00`: UID0000L3 MapPane file.
- `21138` / `2026-08-04T20:10:30-04:00`: UID0001TQ alpha view.
- `21139` / `2026-08-04T20:11:00-04:00`: UID00000C AlphaMaskSurface class.
- `21140` / `2026-08-04T20:11:29-04:00`: UID0000HF AlphaMaskSurface file.
- `21141` / `2026-08-04T20:11:56-04:00`: UID0000YL AlphaMaskSurface aggregate.
- `21142` / `2026-08-04T20:12:32-04:00`: UID0004BL ApplyAlphaMap565.
- `21143` / `2026-08-04T20:13:08-04:00`: UID00020A Rgb565AlphaMapMmxBlocks.
- `21144` / `2026-08-04T20:13:56-04:00`: UID00029V lookup roots.
- `21145` / `2026-08-04T20:14:44-04:00`: UID0002TD compat peer.
- `21146` / `2026-08-04T20:15:27-04:00`: UID00016L RGB565 aggregate.
- `21147` / `2026-08-04T20:16:22-04:00`: UID0000OC Surface file.
- MCP read-only calls returned `isError:false` for every required bounded result. One combined type/catalog request exceeded its 30-second timeout; `server_health` remained `status:ok`, and the same evidence completed when narrowed to one type/entity per request.
- The `2026-08-05T15:03:22-04:00` full-quality self-audit ran no validator and made no IDA mutation. Fresh read-only MCP health, type, function, frame, comment, item, name, byte, padding, and complete ordered-xref queries all matched the accepted I01-I06 prestate under the reconciled canonical disk identity. Dated generated command 21151 and the current manual rows were also reread without editing; supervisor-owned claims remain unchecked.
- The primary-supervisor `2026-08-05T17:19:49-04:00` full read-only preflight passed under now-historical session `b005-uid0001ny-d1-rollback-reopen` PID `22636` and identity `23B89BF35334D876FE63C04AE15C4F90AEF4DF41FAF9D79580F25D244A214283`, 143196749 bytes. B010's current `2026-08-05T17:32:00-04:00` run of `tools/tmp_b010_uid0002th_gate2b.ps1 -Mode Preflight` passed every I01-I06 semantic prestate under sole session `b005-uid0001ny-postsave-reopen` PID `24380` and canonical identity `115491A99AE02621692E9F7AF4C9E3F011E77DD9678AF996A39A86AA02837695`, 143196991 bytes. Both runs were read-only; neither grants C2TH-027..033/C2TH-038 credit.
- Validator side effects were limited to validator-managed registry/reference/projected-stat updates and explicitly skipped generated refresh. Known unrelated missing-reference warnings remained on UID0000TN/UID0001PI/MapPane/Surface; none was target-specific. Generated/manual/lifecycle results remain supervisor-owned and are not claimed.

## Changed Files

- Reconciled same report: `tools/leaser/Agents/Agent-B010/research/0002TH-SoftwareRenderRgb565AlphaLookupBlitCallback-empty-emitter-source-quality.md`.
- Changed and physically reread: `by-memory/0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback.md`, `by-global/SurfaceRenderCallbackTable.md`, `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`, `by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md`, `by-memory/0x005094b0-0x0050a4fd.MapPaneRenderMapView.md`, and `by-file/MapPane.md`.
- Changed and physically reread: `by-type/by-struct/AlphaSurfaceBufferView.md`, `by-class/AlphaMaskSurface.md`, `by-file/AlphaMaskSurface.md`, `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`, `by-memory/0x00460410-0x004604f4.ApplyAlphaMap565.md`, and `by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md`.
- Changed and physically reread: `by-memory/0x0069b3d8-0x0069b3e0.SurfaceAlphaLookupTablePointers.md`, `by-memory/0x004bdf40-0x004be0db.SoftwareRenderCompatAlphaLookupBlitCallback.md`, `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md`, and `by-file/Surface.md`.
- Exact post-validator physical identities: UID0002TH `12BBB2EC01F0CAB1A746C1E7B1D6F151E2CF8D41A3375D2BF402F14561E18445`; UID0000TN `19158874B1AB117657ED4249C536DD5C9716904EA12E393F699AF8B063A9726C`; UID0001PI `93F3B817469D521EA620BB3E78FDFA7B7CAF5AD7B1DF38DC7B82ECB7B713B339`; UID00039V `62AAB634BA056718980A60D8F10BEA6AD739DD05BFF146B1CEFA20F009AB0409`.
- Exact post-validator physical identities: UID0004QY `878B2A1DE411DA2F2EE96755DF33DF614454D4BB6589AFA2BEF4AE3D896A3579`; UID0000L3 `3777DA9E0484FE18D3B306D5CA4C9508A2A1783AEFEBA6F78F7502E86EC39CEE`; UID0001TQ `18BDF47F2A84D9BB8EB7B1B23DC661AA42FBA8DC3C42E10204DA95302C9F03B7`; UID00000C `2A88809AFD149752AAB98D26E0861FC2A137ABEEB89EADA6CB69D263C02C10F8`.
- Exact post-validator physical identities: UID0000HF `9FFF80419428BAFC6D4C015500D1821C4E4668E6BF35A6FB894F47E505FA3831`; UID0000YL `E177EA831CCB5DD14BEA5A5631E8BCCC947AE126697206C76413C59C4D4D37D4`; UID0004BL `31380854CEB15A9B0D21D49424BE51FC55DF8CE1DF4CB28CDD0FDFA04CF6BAFD`; UID00020A `67166B1E780E70F0559CD5E79925FB2DFD6BFD10E055867E4BA092E10184D77B`.
- Exact post-validator physical identities: UID00029V `7892ECD783AD60678188B6959AA93DD10F8E34D100590256432919312D24E380`; UID0002TD `5496CE0A042861055962853806747BDD81155956824BEC206BF8183F0BDF8830`; UID00016L `8370C29C0D387DB42D85E451CCD393216657ADD3D35D0D25E33987B7F283E240`; UID0000OC `D9D4AAC904B0DFA64B93BE6BF636A303FC5966B7A4F32274F86D64F81163D0A8`.
- B010 did not mutate IDA, manual coverage, generated output, audit/catalog/assignment state, or lifecycle state. Validator-managed projected stats/reference/registry side effects are recorded above.
- Report execution/archive state is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata. This report body makes no mutable current lifecycle claim.

## Implementation Tracking Checklist

- [x] C2TH-001 | 0002TH | Set completion/confidence to 92/94, canonical owner and emitter to 0000OC, reconstructable true, and keep position blank. | very strong | Physical metadata, hash `12BBB2EC01F0CAB1A746C1E7B1D6F151E2CF8D41A3375D2BF402F14561E18445`, and validator 21131. | UID0002TH metadata | incorporate | B010 callback | applied
- [x] C2TH-002 | 0002TH | Add exact ABI, provider references, live slot dispatch, clipping, source-view, prefix, tail, lookup-root, Surface-route, and formal-C++ conclusions without pruning existing detail. | very strong | Target Item Summary and detailed behavior sections; validator 21131. | UID0002TH Item Summary and research sections | incorporate | B010 callback | applied
- [x] C2TH-003 | 0002TH | Add exact 419-byte range and SHA256, 15-byte predecessor and 13-byte successor padding, dated IDA snapshot, target xrefs, and slot xrefs. | exact binary evidence | Range `[0x004c3cf0,0x004c3e93)`, body SHA256 `E01E7BED7A2E3B8CDF199D0193E7309A295328DCDC1BE2996EA85EEAE5BFD451`, padding, and xref inventories. | UID0002TH Status, Range, and IDA Evidence | incorporate | B010 callback | applied
- [x] C2TH-004 | 0002TH | Record logical void return, ECX GrafPort receiver, three four-byte stack pointers, retn 0x0c, and the MM1 overwrite proof. | very strong | Callee cleanup, caller push order, ignored return, and MM1 zeroing. | UID0002TH ABI | incorporate | B010 callback | applied
- [x] C2TH-005 | 0002TH | Record draw guard, clip and intersection order, source translation, destination addressing, bulk-width rounding, scalar tail, pitches, and row iteration. | very strong | Dated decompile/disassembly plus exact formal body. | UID0002TH Behavior And Touched State | incorporate | B010 callback | applied
- [x] C2TH-006 | 0002TH | Record the exact AlphaSurfaceBufferView, GrafPort, and RectBounds offsets and source-facing types used by this callback. | very strong | Exact 0x14 view and observed receiver/bounds offsets. | UID0002TH Layout | incorporate | B010 callback | applied
- [x] C2TH-007 | 0002TH | Record exact five-bit and six-bit lookup roles plus ApplyAlphaMap565 and Rgb565AlphaMapMmxBlocks names, contracts, and ownership. | strong | Lookup indexing, helper caller/callee evidence, and SoftwareBlend16 ownership. | UID0002TH Lookup And Helper Evidence | incorporate | B010 callback | applied
- [x] C2TH-008 | 0002TH | Preserve Surface ownership and the evidence-backed rejection of RankingEventListPane, MapPane, SoftwareBlend16, aggregate, and physical-table ownership. | very strong | Initializer, slot, source-root, and negative ownership evidence. | UID0002TH Ownership And History | incorporate | B010 callback | applied
- [x] C2TH-009 | 0002TH | Insert the exact RECONSTRUCTION_CPP CODE callback body from First-Draft C++ Recommendation without extending outside the target range. | strong source reconstruction | One physical file-local callback body; target hash and validator 21131. | UID0002TH formal CPP block | incorporate | B010 callback | applied
- [x] C2TH-010 | 0002TH | Keep RECONSTRUCTION_H CODE blank because the provider is file-local and route shared declarations through UID0000TN and alpha-surface support pages. | very strong | Target H block is physically blank; shared declarations exist in UID0000TN. | UID0002TH formal H block | already-present | B010 callback | already-present
- [x] C2TH-011 | 0002TH | Add the AlphaMaskSurface forward declaration, SurfaceAlphaLookupBlitProc typedef, two lookup-root externs, and g_pfnBlitAlphaLookup extern exactly as reported. | strong | Physical UID0000TN H block, hash `19158874B1AB117657ED4249C536DD5C9716904EA12E393F699AF8B063A9726C`, and validator 21133. | UID0000TN formal H block | incorporate | B010 callback | applied
- [x] C2TH-012 | 0002TH | Add one definition each for the two lookup roots and g_pfnBlitAlphaLookup while preserving every existing callback-table definition. | very strong | Exactly one definition of each global in UID0000TN CPP. | UID0000TN formal CPP block | incorporate | B010 callback | applied
- [x] C2TH-013 | 0002TH | Add the exact void ABI, two providers, MapPane consumer, typed global, and raise completion/confidence from 93/94 to 94/95. | very strong | Slot-5 row, providers, consumer `0x0050a267`, metadata, and validator 21133. | UID0000TN slot 5 and metadata | incorporate | B010 callback | applied
- [x] C2TH-014 | 0002TH | Add the typed slot-5 storage relationship and four ordered xrefs while retaining exactly one non-emitting covered-by CPP comment and no physical data declaration, definition, or provider body. | very strong | UID0001PI hash `93F3B817469D521EA620BB3E78FDFA7B7CAF5AD7B1DF38DC7B82ECB7B713B339`; validator 21134; CPP block contains exactly `// Emitted source for this range is covered by [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md).` | UID0001PI physical storage and formal CPP/H blocks | incorporate | B010 callback | applied
- [x] C2TH-015 | 0002TH | Replace the provisional byte-result direction with the exact typedef and provider identities while preserving the already-correct formal assignment. | very strong | Initializer provider assignments and typed slot documentation; validator 21135. | UID00039V initializer | incorporate | B010 callback | applied
- [x] C2TH-016 | 0002TH | Correct the callback call to pass m_selectionOverlay rather than its address and preserve the pointer-owned field and bounds roles. | very strong | Formal call passes `m_selectionOverlay`; allocation/deletion proves pointer ownership; validators 21136 and 21137. | UID0004QY and UID00007Q MapPane docs | incorporate | B010 callback | applied
- [x] C2TH-017 | 0002TH | Add the exact 0x14 POD layout, one-byte ownership field, three explicit padding bytes, formal H declaration, and raise completion/confidence from 86/90 to 90/93. | very strong | Physical struct declaration, hash `18BDF47F2A84D9BB8EB7B1B23DC661AA42FBA8DC3C42E10204DA95302C9F03B7`, and validator 21138. | UID0001TQ AlphaSurfaceBufferView | incorporate | B010 callback | applied
- [x] C2TH-018 | 0002TH | Add the exact const GetBufferInfo accessor, target and peer caller set, callback-facing AlphaMaskSurface decision, and preserve historical IntAlphaSurface evidence. | strong | Three synchronized alpha-surface pages and validators 21139 through 21141. | UID00000C, UID0000HF, and UID0000YL alpha-surface docs | incorporate | B010 callback | applied
- [x] C2TH-019 | 0002TH | Add the fresh caller sets, exact logical void cdecl prototypes, and MM1 non-ABI proof while preserving existing helper bodies and SoftwareBlend16 ownership. | very strong | Exact callers `0x004c3db4` and `0x0046043f`, helper bodies, MM1 zeroing, and validators 21142 and 21143. | UID0004BL and UID00020A helper pages | incorporate | B010 callback | applied
- [x] C2TH-020 | 0002TH | Add source names and types, 32-row and 64-row by 256-entry geometry, RGB565 channel use, complete target and peer references, and raise completion/confidence from 92/94 to 93/95. | very strong | Exact root addresses, dimensions, channel indexing, references, and validator 21144. | UID00029V lookup-root page | incorporate | B010 callback | applied
- [x] C2TH-021 | 0002TH | Add the shared exact typedef, source-view, and slot relationship while preserving the peer as a separate RGB555 provider body. | very strong | Shared slot-5 ABI with distinct RGB555 behavior; validator 21145. | UID0002TD compat peer | incorporate | B010 callback | applied
- [x] C2TH-022 | 0002TH | Mark the exact child source-ready, preserve aggregate non-emission, and add the Surface slot-5 child inventory, body route, and declaration route. | very strong | Aggregate and Surface inventories; validators 21146 and 21147. | UID00016L aggregate and UID0000OC Surface file | incorporate | B010 callback | applied
- [ ] C2TH-023 | 0002TH | Apply the exact UID0002TH and UID00029V replacement rows supplied in Exact Manual Supervisor-Owned Coverage Or Tracker Text without altering neighboring rows. | strong | Two exact by-memory manual payloads and literal in-place placement instructions; current rows must be reread before application. | by-memory manual coverage | incorporate | Primary supervisor | proposed
- [ ] C2TH-024 | 0002TH | Apply the exact UID0000TN replacement row supplied in Exact Manual Supervisor-Owned Coverage Or Tracker Text. | strong | Exact by-global manual payload; current row must be reread before application. | by-global manual coverage | incorporate | Primary supervisor | proposed
- [ ] C2TH-025 | 0002TH | Apply the exact UID0000OC replacement row supplied in Exact Manual Supervisor-Owned Coverage Or Tracker Text. | strong | Exact by-file manual payload; current row must be reread before application. | by-file manual coverage | incorporate | Primary supervisor | proposed
- [ ] C2TH-026 | 0002TH | Apply the exact UID0001TQ replacement row supplied in Exact Manual Supervisor-Owned Coverage Or Tracker Text. | strong | Exact by-struct manual payload; current row must be reread before application. | by-struct manual coverage | incorporate | Primary supervisor | proposed
- [ ] C2TH-027 | 0002TH | Declare only the literal AlphaSurfaceBufferView 0x14 UDT and SurfaceAlphaLookupBlitProc typedef, preserve AlphaMaskSurface as the existing incomplete zero-member type, and write no type comments. | strong dated prestate | Current full read-only I01 preflight passed under baseline `115491A99AE02621692E9F7AF4C9E3F011E77DD9678AF996A39A86AA02837695`/143196991; declaration operations and poststate/persistence readback remain unapplied. | IDA I01 types | incorporate | Primary supervisor | proposed
- [ ] C2TH-028 | 0002TH | Apply the literal I02 function name, full signature, two written comment channels, complete post-frame, byte hash, xrefs, and padding protections while preserving the two blank comment channels. | strong dated prestate | Current full read-only I02 preflight under 115491A9/143196991 reconfirmed the exact target range, bytes, frame, comments, xrefs, and padding; operation/poststate/persistence remain unapplied. | IDA I02 target at `0x004c3cf0` | incorporate | Primary supervisor | proposed
- [ ] C2TH-029 | 0002TH | Apply the literal I03 function name, full signature, two written comment channels, complete post-frame, byte hash, and two-xref set while preserving the two blank comment channels. | strong dated prestate | Current full read-only I03 preflight under 115491A9/143196991 reconfirmed the exact accessor entity, frame, comments, bytes, and xrefs; operation/poststate/persistence remain unapplied. | IDA I03 accessor at `0x00462300` | incorporate | Primary supervisor | proposed
- [ ] C2TH-030 | 0002TH | Apply the literal I04 function name, full signature, two written comment channels, complete post-frame, byte hash, and one-xref set while preserving the two blank comment channels. | strong dated prestate | Current full read-only I04 preflight under 115491A9/143196991 reconfirmed the exact wrapper entity, frame, comments, bytes, and caller; operation/poststate/persistence remain unapplied. | IDA I04 wrapper at `0x00460410` | incorporate | Primary supervisor | proposed
- [ ] C2TH-031 | 0002TH | Apply the literal I05 function name, full signature, two written comment channels, complete post-frame, byte hash, and one-xref set while preserving the two blank comment channels and excluding MM1 from the ABI. | strong dated prestate | Current full read-only I05 preflight under 115491A9/143196991 reconfirmed the exact MMX-child entity, frame, comments, bytes, caller, and MM1 proof; operation/poststate/persistence remain unapplied. | IDA I05 MMX child at `0x00460c90` | incorporate | Primary supervisor | proposed
- [ ] C2TH-032 | 0002TH | Materialize the three literal four-byte global items, preserve or reapply their exact name-table symbols, apply exact types and regular comments, keep repeatable comments blank, and preserve every itemized immediate neighbor byte, item, name, type, comment, and ordered xref set. | strong dated prestate | Current full read-only I06 preflight under 115491A9/143196991 reconfirmed the literal global and protected-neighbor package; materialization/comments and persistence remain unapplied. | IDA I06 globals and neighbors | incorporate | Primary supervisor | proposed
- [ ] C2TH-033 | 0002TH | Dynamically rebind every literal prestate, create and hash the exact byte-identical backup, apply I01 through I06 serially with immediate readback, save exactly once, independently reopen and verify, and use the stated no-save or saved rollback path on any mismatch. | exact operational contract | Read-only preflight passed; the active transaction/backup/rollback baseline is `115491A99AE02621692E9F7AF4C9E3F011E77DD9678AF996A39A86AA02837695`, 143196991 bytes. No backup, mutation, save, reopen, or persistence credit exists yet. | IDA transaction envelope | incorporate | Primary supervisor | proposed
- [x] C2TH-034 | 0002TH | Run one scoped file validator with no generated refresh for every accepted changed by-star file and record command ID, timestamp, exit code, and ok count. | verified | Commands 21131 and 21133 through 21147 all report exit 0, `ok:1`, and generated refresh skipped. | Validator Results and 16 ordinary destinations | incorporate | B010 callback | applied
- [ ] C2TH-035 | 0002TH | Validate each supervisor-changed manual coverage report after applying the exact replacement rows and record command identity and result. | operational | Required only after C2TH-023 through C2TH-026 are applied. | Manual coverage validation | incorporate | Primary supervisor | proposed
- [ ] C2TH-036 | 0002TH | Run one coherent generated refresh and verify exactly one UID0002TH provider body; zero UID0002TH Empty Emitter Marker occurrences; exactly one canonical SurfaceAlphaLookupBlitProc typedef and g_pfnBlitAlphaLookup declaration/definition in Surface.h/Surface.cpp; exactly one canonical Surface.h declaration and Surface.cpp definition for each 5-bit and 6-bit lookup root while allowing ordinary consuming-translation-unit extern declarations such as ScreenPane.cpp; exactly one AlphaSurfaceBufferView declaration; the MapPane call passes m_selectionOverlay rather than its address; and physical UID0001PI and UID00029V pages introduce no duplicate declaration, definition, or provider body. | operational | Dated command 21151 already shows the provider/marker/type/callsite state and canonical Surface declarations/definitions; final post-manual/post-IDA generated authority remains supervisor/validator-owned until coherent refresh and exact readback. | Generated refresh and semantic readback | incorporate | Primary supervisor and validator | proposed
- [x] C2TH-037 | 0002TH | Preserve all positive and negative evidence, source-name inference, rejected aliases and owners, historical assumptions, exact bytes, xrefs, layouts, and source-placement reasoning at report-level detail. | verified | Substantive evidence, ownership, history, and rejection sections remain present. | Same report research/evidence sections | incorporate | B010 callback | applied
- [ ] C2TH-038 | 0002TH | Treat IDA sessions, PIDs, disk identities, generated commands, file hashes, and tracker state as dated snapshots and dynamically reread authority at every applicable gate while leaving lifecycle state external. | operational | A4B44/143196656 and 23B89B/143196749 are historical; current read-only transaction baseline is 115491A9/143196991, and any later identity change requires same-report rebase plus fresh Gate 1. No action/persistence credit is granted by currentness reconciliation. | Mutable-authority and lifecycle checks | incorporate | Primary supervisor | proposed
- [x] C2TH-039 | 0002TH | Record that this is NexusTK render code with no third-party import and that stale Wave2 and Wave3 material was ignored. | exact disposition | Inference Research Guidance Check records both exclusions. | Same report inference guidance | not-applicable | B010 callback | excluded-with-reason
- [ ] C2TH-040 | 0002TH | Complete claim-by-claim ordinary, IDA, manual, and generated verification before any supervisor-owned report lifecycle action. | operational | Required final Gate2A, Gate2B, and post-refresh reconciliation. | Final implementation readback | incorporate | Primary supervisor | proposed

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000021225","destination_path":"executed-b-agent-research/B010/0002TH-SoftwareRenderRgb565AlphaLookupBlitCallback-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0002TH-SoftwareRenderRgb565AlphaLookupBlitCallback-empty-emitter-source-quality.md","timestamp":"2026-08-05T18:28:59-04:00","uid":"0002TH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
