# UID00031I IMECandidatePane Scalar Deleting Destructor Source-Quality Research
** TARGET-REPORT-UID:00031I **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: legacy executable/request-package material removed into inert same-stem companion; fresh Gate 1 required **


## Finalized Report / Current Recommendation

- [UID:00031I] `by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md` is now physically implemented and verified as exact class-owned MSVC scalar-deleting-destructor output: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:00006F`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position, and literally blank formal CPP/H channels.
- Preserve one human destructor declaration in [UID:00006F] and one human definition in [UID:00031F]. The target duplicates the ordinary destructor's candidate-container and Pane teardown, then adds only hidden deleting-flag, optional storage-release, return-this, and complete-object-size ABI mechanics. It must not emit a second destructor, a deleting-wrapper pseudo-method, or a proof-comment marker.
- Support [UID:00031F] is now physically `91/94` and [UID:00006F] is now physically `90/93`, with the accepted ordinary/scalar relationship, exact cleanup chain, source container, object size, and no-duplicate source route incorporated. [UID:0000K5] remains `91/90`, [UID:00018C] remains `86/91`, [UID:00018D] remains `85/90`, [UID:0002MU] remains `86/90`, and [UID:00025J] remains `88/92`; the accepted target-specific prose is present where required.
- The three supervisor-owned IDA action rows were applied, saved once, and independently verified from a fresh no-auto-analysis session under catalog entry `0424`: one combined rename/type/comment/obsolete-comment cleanup for `0x004e8640`, and one combined rename/type/comment action for each `0xa0`/`0xa4` adjustor thunk. B007's role remained read-only research and report reconciliation; the primary supervisor performed every mutation and persistence check.
- Report execution/archive state is supervisor-owned and authoritative only from this report's current path plus validator-owned status/history metadata.

## Supporting Research

- Current target and support documentation read directly: UID00031I, UID00031F, UID00006F, UID0000K5, UID00018C, UID00018D, UID0002MU, UID00025J, the constructor UID0004C7, generated `auto-generated/NexusTK/input/IMEPanes.cpp`, and current manual by-memory/by-class/by-file coverage rows.
- Matching executed reports opened as leads and independently revalidated: B004 `00031J-IMECompositionPaneScalarDeletingDestructor-source-quality.md`, B004 `00031L-IMEStatusPaneScalarDeletingDestructor-source-quality.md`, B008 `0000K5-IMEPanes-empty-emitter-family-source-quality.md`, B010 `0004C2-IMECompositionPaneOrdinaryDestructor-source-quality.md`, B007 `00034W-TabPaneScalarDeletingDestructor-source-quality.md`, and B003 `0002Y3-SliderControlPaneScalarDeletingDestructor-source-quality.md` as the saved public-endpoint frame-normalization control.
- Direct searches used `00031I`, `UID:00031I`, `0x004e8640`, `0x4e8640`, `IMECandidatePaneScalarDeletingDestructor`, `IMECandidatePane`, `scalar deleting destructor`, `0x004e7cb0`, `0x004e85dc`, and `0x004e85e7`. No competing active target report existed when this report was created.
- Historical B008 proof-comment emission was useful interim documentation but is superseded by the current source-item rule and direct target analysis. The wrapper is compiler ABI output; evidence remains in documentation while formal target channels become blank.
- Wave2/Wave3 references encountered in older docs were rejected as stale workflow authority. Current by-* docs, current generated output, current skill/policy, and bounded live IDA MCP evidence control this report.
- Authoritative supervisor closure is the audit entry `Supervisor-S2 B007 UID00031I Gate 2B / Manual / Generated / Overall Gate 2 Audit`: Gate 2A passed `30/30`; Gate 2B I01-I03 applied/saved/fresh-session verified; manual coverage commands `000000022382` and `000000022383` passed; autogen command `000000022384` passed; and overall Gate 2 passed `44/44 PRE-LIFECYCLE CLAIMS`. This reconciliation changes the report bytes, so the fresh exact-artifact C044 audit and primary lifecycle C043 remain open.

## Target

- Target UID: `00031I`.
- Additional target UIDs: none. Every other UID is support evidence or a support destination and receives no independent report coverage claim.
- Path: `by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md`.
- Exact half-open range: `[0x004e8640,0x004e86bf)`, `0x7f` / 127 bytes.
- Exact byte SHA256: `6D7E5BAF5E4F865F49CFDB7A41F0E4EA699C3EDCF9D7DA675EC267263FB895EF`.
- Dated report-time IDA name/type: `sub_4E8640`, item declaration `Pane *__thiscall(Pane *Block, char)`.
- Semantic owner: [UID:00006F] `IMECandidatePane`; source file route: [UID:0000K5] `NexusTK/input/IMEPanes.cpp`.

## Current Target State

- Physical post-callback metadata is `92/94`, `CANONICAL_OWNER:00006F`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position, `Nested:0`, and literally blank formal CPP/H channels.
- The physical page now records the exact byte identity, four-byte flag ABI, branch truth table, object size, helper identities, vtable routes, ordinary-destructor parity, deterministic IDA handoff, compiler/no-source classification, superseded proof-comment history, and exact not-higher/not-lower score rationale.
- Supervisor-owned manual coverage is current and validated: by-memory command `000000022382` and by-class command `000000022383` returned exit `0`, `ok:1`, with final hashes `8D080707A33B24C6A79CC91FE0CA1DFA339F5174F5B79FF94D01F59C35AF425B` and `44C7B319DEFEC624AA25BDF8171A149BE62585C540B4559674153C50AD7100CA`. Coherent autogen command `000000022384` also passed; generated `IMEPanes.cpp` contains no UID00031I marker/body, retains UID00031F as the sole destructor definition at lines 116-120, and correctly has no sibling `IMEPanes.h`.
- [UID:00031F] already emits the sole human `IMECandidatePane::~IMECandidatePane()` definition. [UID:00006F] already declares `virtual ~IMECandidatePane();` and the `CandidateStringList visibleCandidates` member at `+0xf8`.

## Executive Recommendation

The exact source is one normal virtual destructor and one nontrivial standard-library member. The compiler emits both the ordinary destructor at `[0x004e7cb0,0x004e7cfc)` and the deleting wrapper at `[0x004e8640,0x004e86bf)`. Both perform the same three vptr restores, clear `visibleCandidates`, release its eight-byte proxy, null the proxy field, and tear down `Pane`. UID00031I then consumes one hidden four-byte flags argument, optionally releases complete-object storage, and returns complete `this`.

Therefore UID00031I is class-owned binary evidence but not an independent source item. Make it false/non-emitting/blank, retain the human source only at UID00031F/UID00006F, and remove the generated proof-comment marker on the next authorized coherent refresh. Preserve every exact ABI and cleanup fact in ordinary documentation.

## Supervisor Active Recheck

- The assigned target was read from the current goal and tracker row; no other active B report claimed UID00031I.
- The live listener at `127.0.0.1:13337` existed and bounded MCP calls succeeded. An initial bounded list request timeout was retried without process control; the service then returned the active canonical NexusTK session and all required reads completed.
- The dated evidence snapshot used active session `supervisor-b007-uid0002YJ-rollback-fresh-20260811`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, size `143205130`, physical SHA256 `049D1FC92CCDAA8DA17BF816AF35BFE8248B5D70B2FFB4EB5ABB91CB5D3CF92B`, worker PID `2388`. This name is provenance only, never future Gate 2B mutation authority.
- Gate 1 accepted the exact pre-callback report artifact SHA256 `B1C9177AF4963AB9154BA649AEB40408467C92AEA6F1E28C5427EEA9E4D2B6BD` at `33/33`; that acceptance is historical authority for this callback, not a pass for the post-callback report artifact.
- During the accepted callback, B007 changed only UID00031I, UID00031F, UID00006F, UID0000K5, UID00018C, and UID00018D, then ran one scoped `--no-generated-refresh` validator for each and physically reread all six. UID0002MU and UID00025J were physically verified unchanged. No coverage report, generated file, tracker, IDA database, goal, audit, lifecycle state, or removed archive was edited by B007.
- The later supervisor closure passed Gate 2A `30/30`, applied I01-I03 through the public-attested Gate 2B path, saved exactly once, and reproduced all accepted state in fresh session `supervisor-b007-uid00031I-postsave-fresh-20260811` with `run_auto_analysis:false`. Canonical IDB SHA changed from `BA6D026C06D368919C597196E9035B81E10ECF22841A3673A1FD5A57D4BBAFE2` to `DAD3B9B3C923FE8C6EE972818ED9EAA9C288A6467A05072827D2DE0B12B19CDC`; catalog entry `0424` records the transaction.
- The same closure applied and validated the three exact manual coverage rows, refreshed generated state, and passed overall Gate 2 `44/44 PRE-LIFECYCLE CLAIMS`. C043 remains primary-supervisor lifecycle work; C044 is deliberately reopened by this report-byte reconciliation and requires fresh exact-artifact Gate 1.

## Inference Research Guidance Check

- Direct facts are separated from inference: addresses, bytes, hashes, instructions, blocks, comments, frame rows, xrefs, vtable cells, and callees are live IDA facts; class/source routes and current scores are documentation facts; source spelling and compiler/source disposition are constrained inference.
- Raw labels are not accepted in final analysis recommendations. `IMECandidatePane__ScalarDeletingDestructor`, `...AdjustorA0`, `...AdjustorA4`, `deletingFlags`, and `visibleCandidates` match established project style and exact behavior.
- Source reconstruction stays human-written: no explicit vptr stores, hidden flags, proxy/map destruction calls, base-destructor calls, operator-delete wrapper calls, adjustors, or object-size constants are emitted as handwritten NexusTK source.
- Execution behavior remains exact because the class declaration, virtual destructor, nontrivial member, inheritance layout, and ordinary destructor cause the compiler/runtime to regenerate equivalent mechanics.

## Heuristic / Inference Reanalysis And Validation

| Question | Investigation | Resolution |
| --- | --- | --- |
| Is UID00031I a handwritten method? | Compared hidden flags, `ret 4`, return-this ABI, vtable-only/thunk liveness, and ordinary-body parity. | No. It is compiler-generated scalar deleting-destructor output. |
| Is any unique human cleanup trapped only in UID00031I? | Compared all cleanup instructions byte-for-byte with raw UID00031F and traced UID0002MU/`sub_5C7526`/Pane calls. | No. UID00031F has the same candidate-container and base teardown. |
| What is destroyed at `+0xf8`? | Constructor, class layout, paint/show methods, UID0002MU, proxy allocation/free, and object size were cross-checked. | `CandidateStringList visibleCandidates`, a `std::deque<std::wstring>`-style member. |
| Is the hidden argument a byte? | Frame row is four bytes, load is `mov eax,[ebp+8]`, and exit is `ret 4`; only `AL` is tested. | ABI type is `unsigned int deletingFlags`; byte rendering is a decompiler simplification. |
| What does mask `0x1` mean? | Followed both branch exits and `0x004f4ac0`. | With mask `0x1` set and `0x4` clear, complete-object storage is released. |
| What does mask `0x4` mean? | Disassembled direct callee `0x0041b6a0` and followed branch ordering. | It is reached only when `0x1` is set; target passes size `0x118` and `this` to a one-byte no-op, so normal free is suppressed. |
| Is this vector or sized deletion? | Checked for cookie/count/stride/loop, array element destruction, size-consuming free, and indirect call. | No. None exists; `0x0041b6a0` is not a deallocator. |
| Is `0x118` credible object size? | Compared constructor/root inline allocation and class field end at `+0x114`. | Yes, 280 bytes is exact complete-object size evidence. |
| Are the two thunks source methods? | Hashed/disassembled both 11-byte bodies and mapped their vtable cells. | No. They subtract `0xa0`/`0xa4` and tail-jump with unchanged hidden flags. |
| Should a proof comment remain emitted? | Compared current policy, sibling UID00031J/UID00031L, generated output, and sole source definition. | No. Evidence belongs in docs; a false compiler artifact has blank formal channels. |
| Should owner become `NONE`? | Checked three candidate vtables, constructor/ordinary/root-handler stores, and candidate class state. | No. Retain semantic owner UID00006F while clearing source emission. |
| Can the score rise? | Resolved every listed naming, ABI, helper, liveness, ownership, source, formal-code, and boundary blocker. | Yes, `92/94`; only original symbol/compiler provenance is unavailable. |

## Evidence Standards Used

- Exact binary evidence: bounded `lookup_funcs`, `get_bytes`, local SHA256, `analyze_function`, `disasm`, `decompile`, `stack_frame`, `inspect_items`, and boundary reads.
- Route evidence: `xrefs_to` for target and all three vtables; two exact adjustors; primary vtable cell; constructor, ordinary destructor, and root-handler vptr-store parity.
- Helper evidence: direct target callees plus current helper docs/types/comments for candidate clear, proxy free, Pane teardown, MemoryMan-backed operator delete, and one-byte runtime no-op.
- Source evidence: current class declaration/member layout, ordinary destructor formal body, source-file routing, and generated `IMEPanes.cpp` marker state.
- Negative evidence: no ordinary target caller, no unique target source cleanup, no vector/array mechanics, no size-consuming bit-`0x4` deallocator, no second destructor source declaration, no source-bearing split, and no proposed-name collision.
- Confidence remains below 95 because original PDB/private symbol spelling, exact compiler version/switches, and exact original typedef token are unavailable; these do not change behavior or source placement.

## Evidence Checked

- MCP: `idb_list`, bounded function lookup/analysis/disassembly/decompile, stack frames, bytes, item inspection, comments, xrefs, type query, entity/name collision query, and helper/thunk reads.
- Exact target bytes and hash; raw ordinary destructor bytes and hash; both adjustor bytes/hashes; successor `0xcc`; sibling start at `0x004e86c0`.
- Current IDA target, thunk, vtable, Pane destructor, operator-delete wrapper, proxy free, and runtime-no-op names/types/comments.
- Current target/support by-* docs and generated/manual coverage states listed in Supporting Research.
- Prior sibling/family reports were treated as leads and policy controls, then independently checked against this target. Executed UID0002Y3 records the same scalar-wrapper/adjustor ABI under saved public `set_type` readback: its primary frame retained saved/return rows and renamed the existing four-byte argument, while each 11-byte tail-jump adjustor retained return `+0x0/4` and materialized exactly one four-byte deleting-flag row at `+0x4`; I01-I03 bind those outcomes as literal fail-closed acceptance criteria for this matching target shape.
- Failed/unavailable checks: no required bounded MCP read remained unavailable. `server_health` returned no structured payload in one direct call, but current `idb_list`, listener state, and repeated valid IDB-backed calls proved the service usable; this was not treated as an outage.
- Callback physical evidence: UID00031I SHA256 `4E6C25C61280E50A16BF1A3B0EAD5026D704302401C55C3F05D42AD72F1F5BED` (9,335 bytes, 88 lines); UID00031F `EAD83F295BA115A11CAE02641A185E985CA46FC0780CEF6E82A2BDAB9FB11B22` (8,527 bytes, 80 lines); UID00006F `83B91F783B465808E3EE3A42C1B16CD9AD87BD9F56F0415BE8363830466D1BDF` (25,096 bytes, 158 lines); UID0000K5 `3C0780DC063DF4967FD404C5566DFBE679C34CB6C21B9EF175A98E689CB870A7` (53,810 bytes, 199 lines); UID00018C `191F0B2D5DAB0EC55075DE3A1E46C2E783A04659FCDFF973734F69C6CFEC4A3A` (21,701 bytes, 128 lines); UID00018D `9D909D1EE61EE744D57B19B1AA26FE968C866F582114610072F16963A7B772EC` (11,811 bytes, 90 lines).
- Verify-only physical evidence: UID0002MU remains SHA256 `9D908AAC394F0CA80CB3E33640CA6D47BC2566E1D0DA399D23CA754DFF592561` (6,084 bytes, 70 lines), and UID00025J remains `35197EBCBCFAC568F0E45AE180AC386DBD0A38D91AC539775026636B370339ED` (12,377 bytes, 131 lines).

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | 00031I | B007: record exact `[0x004e8640,0x004e86bf)`, 127-byte range and SHA256 `6D7E...95EF`. | Very high | Live bytes/hash and modeled bounds. | `by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md` Status/Evidence | incorporate | applied |
| C002 | 00031I | B007: record 39 instructions, five blocks, complexity 2, complete-this receiver, four-byte hidden flag, return-this, and `ret 4`. | Very high | Analyze/disassembly/frame. | UID00031I Behavior/ABI | incorporate | applied |
| C003 | 00031I | B007: record vptr stores `0x61c474/0x61c4c0/0x61c4f0` at `+0/+0xa0/+0xa4`. | Very high | Instructions and vtable xrefs. | UID00031I Behavior/Evidence | incorporate | applied |
| C004 | 00031I | B007: record `visibleCandidates +0xf8` clear through UID0002MU. | Very high | Constructor/class/clear-helper/target data flow. | UID00031I Behavior; UID00006F support | incorporate | applied |
| C005 | 00031I | B007: record eight-byte container-proxy release through `sub_5C7526` and nulling of `+0xf8`. | Very high | Exact push/call/store sequence and helper body. | UID00031I Behavior/Evidence | incorporate | applied |
| C006 | 00031I | B007: record inherited Pane teardown through `Pane__Destructor` without ownership transfer. | Very high | Direct callee and Pane comment/type. | UID00031I Behavior/Evidence | incorporate | applied |
| C007 | 00031I | B007: record exact mask `0x1`/`0x4` truth table and branch ordering. | Very high | Complete disassembly. | UID00031I ABI table | incorporate | applied |
| C008 | 00031I | B007: record `0x118` complete-object size and one-byte no-op disposition; reject sized/vector delete. | Very high | Direct branch/callee/item/object-layout evidence. | UID00031I ABI/Negative Evidence | incorporate | applied |
| C009 | 00031I | B007: record original complete-object pointer returned on every path. | Very high | All exits and EAX writes. | UID00031I ABI | incorporate | applied |
| C010 | 00031I | B007: record two thunk code refs plus primary-vtable data ref and zero ordinary callers. | Very high | `xrefs_to` and analyze result. | UID00031I Xrefs | incorporate | applied |
| C011 | 00031I | B007: record exact successor `0xcc`, sibling start `0x004e86c0`, and no split/range change. | Very high | Boundary bytes/item lookup. | UID00031I Range analysis | incorporate | applied |
| C012 | 00031I | B007: record byte-for-byte cleanup parity with UID00031F and the sole human destructor source route. | Very high | Raw UID00031F bytes/hash and source docs. | UID00031I Reconstruction; UID00031F support | incorporate | applied |
| C013 | 00031I | B007: retain semantic owner UID00006F and source file UID0000K5 while rejecting Pane/STL/runtime/no-owner alternatives. | Very high | Vtables, class state, source routing. | UID00031I Status/Ownership | incorporate | applied |
| C014 | 00031I | B007: change to `RECONSTRUCTABLE:FALSE`, blank emitter/position, `Nested:0`. | Very high | Compiler-only no-source proof. | UID00031I metadata | incorporate | applied |
| C015 | 00031I | B007: raise score from `86/91` to `92/94` with exact not-higher/not-lower rationale. | High | Closed blocker matrix. | UID00031I metadata/Score Rationale | incorporate | applied |
| C016 | 00031I | B007: make formal CPP and H literally blank; remove proof-comment emission and reject duplicate source. | Very high | Sole UID00031F/UID00006F human source. | UID00031I formal CPP/H/Reconstruction | incorporate | applied |
| C017 | 00031I | B007: replace Item Summary and preserve historical B008 proof-comment state as superseded history. | Very high | Current page/generated state and current policy. | UID00031I Item Summary/Changes | incorporate | applied |
| C018 | 00031I | B007: raise UID00031F to `91/94` and add exact hash/parity/source-coverage evidence without changing owner/emitter/formal body. | High | Exact raw bytes and target comparison. | `by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md` | incorporate | applied |
| C019 | 00031I | B007: raise UID00006F to `90/93`; update scalar row and destructor/source-container evidence without changing class formal source. | High | Full class/target/ordinary/vtable relation. | `by-class/IMECandidatePane.md` | incorporate | applied |
| C020 | 00031I | B007: update UID0000K5 candidate row/evidence to one ordinary source destructor plus non-emitting compiler wrapper; retain `91/90`. | High | Current file inventory and generated route. | `by-file/IMEPanes.md` | incorporate | applied |
| C021 | 00031I | B007: update UID00018C target row/evidence to `92/94` false/non-emitting and exact cleanup/ABI disposition; retain aggregate `86/91`. | High | Exact child result and mixed aggregate policy. | `by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md` | incorporate | applied |
| C022 | 00031I | B007: add candidate thunk hashes, names, exact deltas/routes, and non-source disposition; retain UID00018D `85/90`. | Very high | Live 11-byte bodies/hashes/vtable refs. | `by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md` | incorporate | applied |
| C023 | 00031I | B007: verify UID0002MU remains `86/90`, false/no-owner/no-emitter/blank and already documents exact STL clear behavior. | High | Physical page and live target call. | `by-memory/0x004e8a00-0x004e8ae6.CandidateStringQueueClear.md` | already-present | already-present |
| C024 | 00031I | B007: verify UID00025J remains `88/92`, source-file-owned generated data and already maps the three candidate vtables. | High | Physical page and live vtable xrefs. | `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md` | already-present | already-present |
| C025 | 00031I | Supervisor: replace stale manual by-memory UID00031I row with exact false/92% text. | High | Applied and validated by command `000000022382`; final by-memory coverage SHA256 `8D080707A33B24C6A79CC91FE0CA1DFA339F5174F5B79FF94D01F59C35AF425B`. | `by-memory/-coverage-report.md` | incorporate | applied |
| C026 | 00031I | Supervisor: replace stale manual by-memory UID00031F row with exact 91% text. | High | Applied and validated by command `000000022382`; final by-memory coverage SHA256 `8D080707A33B24C6A79CC91FE0CA1DFA339F5174F5B79FF94D01F59C35AF425B`. | `by-memory/-coverage-report.md` | incorporate | applied |
| C027 | 00031I | Supervisor: replace stale manual by-class UID00006F row with exact 90% text. | High | Applied and validated by command `000000022383`; final by-class coverage SHA256 `44C7B319DEFEC624AA25BDF8171A149BE62585C540B4559674153C50AD7100CA`. | `by-class/-coverage-report.md` | incorporate | applied |
| C028 | 00031I | Supervisor: execute I01's exact ordered contract of full rename dry-run/apply objects, one literal set-type object, one literal function-comment object, four literal address-comment clear objects, and immediate readback after each stage; accept only I01's literal prototype and complete three-row frame. | Very high | Applied/saved/fresh-session verified under catalog `0424`; pre/post IDB SHA `BA6D026C...BBAFE2` -> `DAD3B9B3...B19CDC`; exact name/type/frame/comment/clears reproduced. | IDA `0x004e8640` | incorporate | applied |
| C029 | 00031I | Supervisor: execute I02's exact ordered contract of full rename dry-run/apply objects, one literal set-type object, one literal function-comment object, and immediate readback after each stage; accept only I02's literal prototype and complete two-row frame. | Very high | Applied/saved/fresh-session verified under catalog `0424`; exact A0 name/type/frame/comment and unchanged 11-byte body/data route reproduced. | IDA `0x004e85dc` | incorporate | applied |
| C030 | 00031I | Supervisor: execute I03's exact ordered contract of full rename dry-run/apply objects, one literal set-type object, one literal function-comment object, and immediate readback after each stage; accept only I03's literal prototype and complete two-row frame. | Very high | Applied/saved/fresh-session verified under catalog `0424`; exact A4 name/type/frame/comment and unchanged 11-byte body/data route reproduced. | IDA `0x004e85e7` | incorporate | applied |
| C031 | 00031I | B007 callback: run scoped target validator with `--no-generated-refresh` and record receipt/readback. | High | Required callback gate. | UID00031I validator/readback | incorporate | applied |
| C032 | 00031I | B007 callback: run scoped UID00031F validator with `--no-generated-refresh` and record receipt/readback. | High | Required callback gate. | UID00031F validator/readback | incorporate | applied |
| C033 | 00031I | B007 callback: run scoped UID00006F validator with `--no-generated-refresh` and record receipt/readback. | High | Required callback gate. | UID00006F validator/readback | incorporate | applied |
| C034 | 00031I | B007 callback: run scoped UID0000K5 validator with `--no-generated-refresh` and record receipt/readback. | High | Required callback gate. | UID0000K5 validator/readback | incorporate | applied |
| C035 | 00031I | B007 callback: run scoped UID00018C validator with `--no-generated-refresh` and record receipt/readback. | High | Required callback gate. | UID00018C validator/readback | incorporate | applied |
| C036 | 00031I | B007 callback: run scoped UID00018D validator with `--no-generated-refresh` and record receipt/readback. | High | Required callback gate. | UID00018D validator/readback | incorporate | applied |
| C037 | 00031I | Supervisor: apply and validate exact manual coverage replacements; B007 must not edit coverage files. | High | Commands `000000022382`/`000000022383` passed exit `0`, `ok:1`; final by-memory/by-class hashes are recorded above. | Manual coverage files | incorporate | applied |
| C038 | 00031I | Supervisor: perform coherent generated refresh/readback and prove UID00031I marker/comment disappears while UID00031F source remains. | High | Autogen `000000022384` passed; `IMEPanes.cpp` SHA256 `A12A8A207E705EC12012DDB3E08808D0B49FD229D8EE778BD35496256197ECBD`, no UID00031I marker/body, UID00031F sole destructor, no header expected. | Validator-owned generated output | incorporate | applied |
| C039 | 00031I | Supervisor: perform fresh exact-artifact Gate 2A review of this post-callback report and accepted implementation. | Very high | Gate 2A passed all `30/30` checked B007 claims at pre-reconciliation SHA `85D7C6DF...5F770`. | Current report artifact and accepted implementation | incorporate | applied |
| C040 | 00031I | Supervisor: confirm the accepted same-report callback was limited to ordinary-doc claims and reconcile any exact Gate 2A defect. | Very high | Gate 2A confirmed ordinary-only callback scope; no ordinary defect required repair. | Report and listed by-* docs | incorporate | applied |
| C041 | 00031I | Supervisor: perform claim-by-claim Gate 2A after callback and fresh scoped validation. | Very high | Claim-by-claim Gate 2A and commands `000000022372-000000022378` passed with stable destination hashes. | Accepted implementation | incorporate | applied |
| C042 | 00031I | Supervisor: perform Gate 2B IDA preflight/mutation/save/readback or exact no-change rejection. | Very high | Public-attested I01-I03 applied, one save, `30/30` same-session and `28/28` fresh-session verification; catalog `0424`. | Current canonical IDA database | incorporate | applied |
| C043 | 00031I | Supervisor: run report lifecycle execution only after Gates 2A and 2B pass and all supervisor-owned coverage/generated work is reconciled. | Very high | Lifecycle boundary. | Validator-owned report lifecycle | incorporate | proposed |
| C044 | 00031I | Supervisor: independently confirm the stable post-callback report has 33 headings, exact ledger/checklist parity, zero executable script fences, one terminal marker, and no lease before lifecycle action. | Very high | Prior current-hash check passed, but this reconciliation invalidates it; fresh exact-artifact Gate 1 must close C044. | This report | incorporate | proposed |
| C045 | 00031I | Supervisor: preserve ordinary raw range, vtables, helpers, bytes, frame structure, repeatable channels, and all protected no-change dependencies. | Very high | Same-session protection `30/30` and independent fresh-session persistence `28/28` passed with raw UID00031F and all protected dependencies unchanged. | IDA protected dependencies | already-present | applied |

Current reconciliation state: `41 applied`, `2 already-present`, and `2 proposed`. Only C043 lifecycle and C044 fresh exact-artifact audit remain open.

## Positive Evidence Summary

- The target is one exact 127-byte, 39-instruction, five-block function with a stable byte hash and a clean one-byte successor boundary.
- Three `IMECandidatePane` vptr stores, the primary vtable cell, and two class-specific adjustors bind the function to UID00006F.
- The target's entire derived cleanup sequence matches UID00031F: clear the embedded candidate deque, free its eight-byte proxy, null the proxy field, and tear down Pane.
- Hidden four-byte flags, return-this, `ret 4`, normal project delete, and a size-carrying one-byte no-op path are canonical scalar deleting-destructor ABI evidence.
- The source class already has a virtual destructor and nontrivial candidate-string member, and UID00031F already owns the sole human definition.

## IDA MCP Facts

- Dated evidence snapshot: active session `supervisor-b007-uid0002YJ-rollback-fresh-20260811`; path/hash/size/PID are recorded under Supervisor Active Recheck. The session identifier must not be reused as Gate 2B authority.
- Target: `sub_4E8640`, `[0x004e8640,0x004e86bf)`, size `0x7f`, 39 instructions, five blocks, complexity 2, item type `Pane *__thiscall(Pane *Block, char)`.
- Frame: `__saved_registers +0x8/4 _DWORD`; `__return_address +0xc/4 _UNKNOWN *`; `arg_0 +0x10/4 _DWORD`; no modeled locals.
- Entry comments: address regular absent; address repeatable absent; function regular absent; function repeatable absent.
- Internal address comments: `0x4e8644` regular `int`, `0x4e866e` regular `Block`, `0x4e8686` regular `this`, `0x4e8698` regular `block`; each repeatable channel absent.
- Callees: UID0002MU `sub_4E8A00`; proxy free `sub_5C7526`; `Pane__Destructor`; `NexusTK_operator_delete_wrapper`; `_guard_check_icall_nop@4`.
- Inbound refs: code `0x4e85e2`, code `0x4e85ed`, data `0x61c474`; no ordinary caller.
- Proposed target and thunk names returned `Not found` in bounded collision lookup.
- Supervisor Gate 2B used the fresh canonical authority selected from `idb_list`; the mutation session was `supervisor-b007-uid0002YJ-rollback-fresh-20260811` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. The prestate was SHA256 `BA6D026C06D368919C597196E9035B81E10ECF22841A3673A1FD5A57D4BBAFE2`, 143,206,835 bytes, with byte-identical backup `E:\NTK\Resources\NexusTK\ida-backups\NexusTK.exe.uid00031I-prechange-20260811-183135.i64`.
- I01-I03 were applied in the accepted ordered contracts; `30/30` pre-save protected-state checks passed, exactly one `idb_save` returned `ok:true`, and the canonical post-save SHA256 became `DAD3B9B3C923FE8C6EE972818ED9EAA9C288A6467A05072827D2DE0B12B19CDC`, 143,205,069 bytes. Post-save copy: `E:\NTK\Resources\NexusTK\ida-backups\NexusTK.exe.uid00031I-postsave-20260811-183432.i64`.
- Fresh no-auto-analysis session `supervisor-b007-uid00031I-postsave-fresh-20260811` reproduced the accepted names, literal types, complete frames, comments, bytes, xrefs, and protected state in `28/28` reads. No rollback was required. Catalog entry `0424` at line 10852 records the transaction; post-append catalog SHA256 is `BCF5199F576B2B6E947497712B3FADA49EE4170B7F2D75B69D8D787D0AA1C072`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x004e8640,0x004e86bf)` | UID00031I target | Compiler scalar deleting wrapper with candidate member cleanup and deleting flags. | False | UID00006F semantic owner | `92/94` | Implemented and verified; blank formal channels. |
| `[0x004e7cb0,0x004e7cfc)` | UID00031F | Ordinary destructor source anchor; same candidate/base teardown. | True | UID00006F | `91/94` | Implemented and verified sole human destructor definition. |
| `[0x004e85dc,0x004e85e7)` | UID00018D child | `this-0xa0` scalar-delete adjustor. | False | None; compiler glue | aggregate `85/90` | No handwritten source. |
| `[0x004e85e7,0x004e85f2)` | UID00018D child | `this-0xa4` scalar-delete adjustor. | False | None; compiler glue | aggregate `85/90` | No handwritten source. |
| `[0x004e8a00,0x004e8ae6)` | UID0002MU | Dinkumware deque/wstring clear helper. | False | None | `86/90` | Existing ignored support remains correct. |
| `0x0061c474/0x0061c4c0/0x0061c4f0` | UID00025J | Primary/secondary/tertiary candidate vtables. | True generated data | UID0000K5 | `88/92` | Source-declared/compiler-emitted; no raw table source. |
| `IMECandidatePane` | UID00006F | Human class, virtual destructor, candidate member. | True | UID0000K5 | `90/93` | Implemented and verified; existing class CPP shell remains source owner. |
| `IMEPanes` | UID0000K5 | Human source file route. | True | FILE | `91/90` | Score retained; target-specific inventory update only. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004e8640` | `0x004e85e2` from thunk `0x004e85dc` | Secondary view at `+0xa0` tail-routes to complete wrapper. |
| `0x004e8640` | `0x004e85ed` from thunk `0x004e85e7` | Tertiary view at `+0xa4` tail-routes to complete wrapper. |
| `0x004e8640` | data cell `0x0061c474` | Primary deleting-destructor vtable entry. |
| `0x0061c474` | stores `0x4e7baf/0x4e7cba/0x4e82fd/0x4e864d` | Constructor, ordinary destructor, root inline cleanup, and scalar wrapper use the same primary view. |
| `0x0061c4c0` | stores `0x4e7bb5/0x4e7cc0/0x4e8303/0x4e8653` | Same lifecycle parity for `+0xa0` view. |
| `0x0061c4f0` | stores `0x4e7bbf/0x4e7cca/0x4e830d/0x4e865d` | Same lifecycle parity for `+0xa4` view. |
| `0x004e8667` | call UID0002MU | Clears active strings and deque map storage. |
| `0x004e8674` | call `sub_5C7526` after pushes pointer and size 8 | Frees the container proxy; helper consumes the pointer and ignores the extra size. |
| `0x004e8688` | call `Pane__Destructor` | Inherited base teardown. |
| `0x004e8699` | call `NexusTK_operator_delete_wrapper` | Normal complete-object free only for mask `0x1` with `0x4` clear. |
| `0x004e86af` | call `_guard_check_icall_nop@4` | One-byte no-op after pushes `this` and `0x118`; not a deallocator. |

## Documentation Evidence And IDA Status

- Supporting docs now establish class ownership, candidate-container offset, ordinary destructor, thunks, vtables, source file, STL helper classification, exact target identity/ABI, compiler/no-source disposition, and the no-duplicate source route at report-level detail.
- UID00031I is physically `92/94`, false/non-emitting, with blank formal CPP/H and the superseded proof-comment history retained. UID00031F and UID00006F are physically `91/94` and `90/93`; UID00018C and UID00018D contain the accepted exact target/thunk evidence while retaining their aggregate scores.
- UID0000K5 now distinguishes one ordinary source destructor from the non-emitting wrapper. UID0002MU and UID00025J were physically reread and already met the accepted support standard without edits.
- Manual coverage and coherent generated output remained supervisor-owned and are now closed by commands `000000022382-000000022384`. The final manual hashes and generated hashes are recorded below; UID00031I emits no generated marker/body, UID00031F remains the sole destructor definition, and no `IMEPanes.h` is expected.
- Historical report-time IDA prestate was raw/weak for the target and both thunks. B007 made no mutation. The primary supervisor later applied I01-I03, saved once, and verified the accepted poststate from a fresh no-auto-analysis session under catalog entry `0424`.

## Ranked Ownership Analysis

### 1. IMECandidatePane semantic owner, compiler-only target

- Evidence for: all three candidate vtables, candidate member at `+0xf8`, exact ordinary parity, class-specific adjustors, object size `0x118`, and established UID00006F -> UID0000K5 route.
- Evidence against: target is not a human method and cannot emit a second source body.
- Decision: retain `CANONICAL_OWNER:00006F`, set false/non-emitting/blank.

### 2. UID00031F ordinary destructor source owner

- Evidence for: exact same candidate/base teardown and existing `IMECandidatePane::~IMECandidatePane()` formal definition.
- Evidence against: it does not contain hidden deleting flags or optional storage-release ABI, which are compiler-generated from the destructor declaration.
- Decision: it remains the sole human destructor definition and coverage route, not the canonical owner of the wrapper page.

### 3. Rejected Pane, STL, runtime, aggregate, and no-owner routes

- Evidence for: target calls Pane/STL/runtime helpers and sits in UID00018C.
- Evidence against: helper use and physical containment do not outweigh class-specific vptrs, member offset, adjustors, complete size, and source route.
- Decision: reject ownership transfer and standalone wrapper source.

### Proposed new file/grouping, if applicable

- No new file, UID, split, merge, or grouping is required. Existing exact pages and `NexusTK/input/IMEPanes.cpp` are sufficient.

## Source Placement

- Human declaration: existing [UID:00006F] class shell in `IMEPanes`.
- Human definition: existing [UID:00031F] `IMECandidatePane::~IMECandidatePane()` through UID00006F/UID0000K5.
- Compiler output: UID00031I wrapper, UID00018D adjustors, UID00025J vtables, and UID0002MU/container-runtime lowering.
- Rejected placements: Pane source, InputMan, a generated `CandidateStringQueue.cpp`, runtime helper source, mixed aggregate source, and a standalone `IMECandidatePaneScalarDeletingDestructor.cpp`.
- Remaining source-placement uncertainty is only the unrecovered original physical filename spelling; current project route is coherent and behaviorally complete.

## Range / Split / Padding / Reclassification Analysis

- Target range is one coherent function `[0x004e8640,0x004e86bf)`; final instruction `ret 4` ends at `0x004e86bf`.
- Byte `0x004e86bf` is external `0xcc` padding; sibling UID00031J begins at `0x004e86c0`.
- No target interior padding, mixed data, extra function, source-bearing child, or unclaimed tail exists.
- Reclassification only: true/comment-emitting -> false/non-emitting/blank. Range/title/path/UID/semantic owner/Nested stay unchanged.
- The two adjustors remain exact children of UID00018D and do not move into the target page.

## Negative Evidence Summary

- No direct ordinary product caller; liveness is exactly primary vtable plus two adjusted vtable routes.
- No unique cleanup absent from UID00031F.
- No array cookie, element count, stride, loop, vector-dtor iteration, vector free, or indirect deallocator.
- No size-consuming `0x0041b6a0` behavior; it is one byte `ret`.
- No evidence for a handwritten hidden-flags method, explicit vptr stores, explicit Pane destructor call, explicit proxy/map calls, or wrapper return value in source.
- No proposed-name collision and no need to overwrite any existing semantic IDA symbol.
- No need to create an IDA function at raw UID00031F during this target's Gate 2B; that remains a separately bounded function-definition decision.

## IDA Rename / Type / Comment Recommendations

The legacy endpoint schemas, literal request objects, and numbered mutation sequence were removed to [00031I-IMECandidatePaneScalarDeletingDestructor-source-quality-removed.md](00031I-IMECandidatePaneScalarDeletingDestructor-source-quality-removed.md). That companion is non-authoritative and must never be executed. The live state contract is declarative:

| ID | Entity and dated observed state | Declarative intended state | Protected state / expected readback |
| --- | --- | --- | --- |
| I01 | Function `[0x004e8640,0x004e86bf)`, SHA256 `6D7E5BAF5E4F865F49CFDB7A41F0E4EA699C3EDCF9D7DA675EC267263FB895EF`, current name `sub_4E8640`, current item type `Pane *__thiscall(Pane *Block, char)`, frame saved `+0x8/4`, return `+0xc/4`, argument `+0x10/4`; entry comments blank; stale internal regular comments at `0x4e8644`, `0x4e866e`, `0x4e8686`, and `0x4e8698`; exact three inbound refs and five callees. | Name `IMECandidatePane__ScalarDeletingDestructor`; type `IMECandidatePane *__thiscall IMECandidatePane__ScalarDeletingDestructor(IMECandidatePane *this, unsigned int deletingFlags)`; function-regular comment exactly `Compiler-generated IMECandidatePane scalar deleting destructor: destroys CandidateStringList at +0xf8, tears down Pane, frees storage only when deletingFlags mask 0x1 is set and mask 0x4 is clear, and carries complete-object size 0x118 on the mask-0x4 one-byte runtime no-op path. Human source is virtual IMECandidatePane::~IMECandidatePane(); do not hand-author this wrapper.`; clear only the four stale internal regular comments. | Exact range/hash/bytes/CFG/xrefs/callees, UDT, vtables, CandidateStringList state, saved/return rows, and all repeatable channels remain unchanged; argument renders `deletingFlags +0x10/4 unsigned int`. |
| I02 | Function `[0x004e85dc,0x004e85e7)`, SHA256 `F04AD94CB5CA4DCB0AC5445029ACF56119B196504F771A746D7A69CD6A2628F3`, current name `sub_4E85DC`, current type `Pane *__thiscall(_DWORD *this, char)`, return-only frame, bytes `sub ecx,0xa0; jmp 0x4e8640`, sole data ref `0x61c4c0`, comments blank. | Name `IMECandidatePane__ScalarDeletingDestructorAdjustorA0`; type `IMECandidatePane *__thiscall IMECandidatePane__ScalarDeletingDestructorAdjustorA0(void *adjustedThis, unsigned int deletingFlags)`; function-regular comment exactly `Compiler-generated IMECandidatePane secondary-view deleting-destructor adjustor: subtracts 0xa0 from adjustedThis and tail-jumps to IMECandidatePane__ScalarDeletingDestructor with the unchanged four-byte deletingFlags argument.` | Exact range/hash/bytes/subtraction/jump/ref/return row and non-regular comment channels remain unchanged; only the prototype-driven `deletingFlags +0x4/4 unsigned int` row may appear. |
| I03 | Function `[0x004e85e7,0x004e85f2)`, SHA256 `4934A73982B557169F1FC796A9041F8081933E6BDC7737E566DE13F3535CD22D`, current name `sub_4E85E7`, current type `Pane *__thiscall(_DWORD *this, char)`, return-only frame, bytes `sub ecx,0xa4; jmp 0x4e8640`, sole data ref `0x61c4f0`, comments blank. | Name `IMECandidatePane__ScalarDeletingDestructorAdjustorA4`; type `IMECandidatePane *__thiscall IMECandidatePane__ScalarDeletingDestructorAdjustorA4(void *adjustedThis, unsigned int deletingFlags)`; function-regular comment exactly `Compiler-generated IMECandidatePane tertiary-view deleting-destructor adjustor: subtracts 0xa4 from adjustedThis and tail-jumps to IMECandidatePane__ScalarDeletingDestructor with the unchanged four-byte deletingFlags argument.` | Exact range/hash/bytes/subtraction/jump/ref/return row and non-regular comment channels remain unchanged; only the prototype-driven `deletingFlags +0x4/4 unsigned int` row may appear. |

Runtime authority, mutation mechanics, persistence, recovery, and operational receipts remain external supervisor responsibilities. No row above is an executable request package.
## First-Draft C++ Recommendation

- Eligible for a target-specific handwritten body: no.
- Target CPP block disposition: physically verified literally blank between the existing `RECONSTRUCTION_CPP CODE:BEGIN` and `END` markers.
- Target H block disposition: physically verified literally blank between the existing `RECONSTRUCTION_H CODE:BEGIN` and `END` markers.
- Human source remains physically present at UID00006F/UID00031F: exactly one `virtual ~IMECandidatePane();` declaration and one ordinary destructor definition. No new C++ was supplied by this callback.
- Exact no-code proof: target duplicates ordinary member/base destruction, is live only through vtable/adjustor routes, receives hidden deleting flags, returns `this`, and contains only compiler/runtime storage policy beyond UID00031F.
- This preserves exact behavior and plausible original source shape: the compiler, class layout, virtual destructor, `CandidateStringList` member, and inheritance regenerate the wrapper; handwritten decompiler mechanics would not resemble original developer source.
- Third-party import directive: not applicable.

## Final Recommendation

- Ordinary target/support implementation C001-C024 is complete and physically verified; the six changed destinations passed scoped validators, and the two verify-only destinations remain unchanged at the accepted evidence level.
- Manual coverage rows C025-C027 were applied and validated by the supervisor under commands `000000022382` and `000000022383`.
- IDA rows I01-I03 were applied, saved once, and fresh-session verified by the supervisor under catalog entry `0424`; the prestate/proposal table remains as historical handoff evidence.
- Coherent generated refresh `000000022384` verified no UID00031I marker/body, UID00031F as the sole destructor definition, and no expected `IMEPanes.h`.
- Overall Gate 2 passed `44/44 PRE-LIFECYCLE CLAIMS`. Only C044 fresh exact-artifact Gate 1 after this reconciliation and C043 primary-supervisor lifecycle execution remain open.
- Keep target range/path/title/UID/Nested and semantic owner unchanged; change reconstructability/emitter/formal output and score.
- No unresolved source-quality blocker remains inside this assignment. Original private symbol/compiler provenance is a bounded confidence cap, not future research required before implementation.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md`.
- Applied and verified metadata is `92/94`, owner `00006F`, false, blank emitter/position/formal CPP/H, `Nested:0`.
- Applied and verified Item Summary: `Exact 127-byte MSVC scalar deleting destructor for IMECandidatePane; duplicates UID00031F candidate-container and Pane teardown, interprets a four-byte hidden deletingFlags value, frees storage only for mask 0x1 with mask 0x4 clear, and remains class-owned but non-reconstructable/non-emitting with source exclusively in UID00031F/UID00006F.`
- The physical page contains the exact range/hash/CFG/frame, vptrs, queue/proxy/base chain, flag matrix, object size, xrefs, boundary, ordinary parity, source route, no-code proof, IDA disposition, rejected alternatives, and score rationale from this report.
- The historical 2026-06-30 proof-comment change remains as explicitly superseded history.

## Recommended Support Doc Changes

- UID00031F ordinary destructor is physically `91/94` with exact SHA256 `E6E6B5ECF5F1F161768923135BC4C645B378C955F4FBF59B39B7BC4C9A2FDA2E`, exact parity with UID00031I, sole human source status, and unchanged formal body/owner/emitter.
- UID00006F class is physically `90/93`; its scalar row is `92/94`, false/non-emitting compiler output, UID00031F is the sole source definition, and `visibleCandidates` explains generated container teardown. Existing class/source C++ was preserved.
- UID0000K5 retains `91/90` and physically distinguishes one ordinary source destructor from false/non-emitting UID00031I. Supervisor autogen `000000022384` confirmed that generated consequence: no UID00031I marker/body, UID00031F as the sole destructor definition, and no expected `IMEPanes.h`.
- UID00018C retains `86/91` and physically records UID00031I as exact `92/94` false/non-emitting compiler output covered by UID00031F/UID00006F.
- UID00018D retains `85/90` and physically records both candidate thunk hashes, deltas, vtable cells, target, proposed analysis names, and no-source disposition.
- UID0002MU and UID00025J were physically verified unchanged at the accepted evidence level.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/91`, owner `00006F`, true, emitter `00006F`, comment-only CPP, blank H.
- Current implemented target: `92/94`, owner `00006F`, false, blank emitter/position/CPP/H, `Nested:0`.
- Reason not lower: every function boundary, byte hash, CFG branch, frame slot, vptr, xref, callee, cleanup effect, flag outcome, size value, source route, and no-code decision is exact and mutually corroborated.
- Reason not higher: original PDB/private symbol, exact compiler version/switches, and exact original `CandidateStringList` typedef token are unavailable; IDA's candidate UDT is incomplete and UID00031F is not modeled as a function.
- Score-improvement attempt: unresolved member/helper names were traced through class/container/helper docs; byte-sized flag ambiguity was resolved by frame/load/`ret 4`; optional-delete ambiguity was resolved by complete branch/callee analysis; object size was resolved from `0x118` and allocation/layout; caller liveness was resolved through three vtable routes; source duplication was resolved through ordinary-body parity; compiler names were resolved to collision-free source-quality analysis names.
- Support scores: UID00031F `91/94`; UID00006F `90/93`; other listed support scores unchanged.

## Open Questions With Attempted Resolution

- Exact original scalar-wrapper symbol: no PDB/private name survives. Project-wide naming precedents and class identity support `IMECandidatePane__ScalarDeletingDestructor`; this is an IDA analysis name only and never source C++.
- Exact original typedef token: class docs currently use `CandidateStringList`; binary shape proves `std::deque<std::wstring>` semantics. Retain `CandidateStringList` for source consistency unless separate direct lexical evidence later supersedes it.
- Exact original source filename: address/source-family evidence strongly supports current `IMEPanes.cpp`; no stronger competing filename evidence exists.
- Exact compiler version/switches: unavailable, but the deleting-wrapper, adjustors, Dinkumware container, and one-byte no-op behavior are exact. This does not alter source or metadata disposition.
- IDA operation/type/frame poststate is resolved and persisted: I01-I03 contain the complete literal request objects and exact accepted outcomes; the supervisor applied them in order, passed `30/30` pre-save protections, saved once, and reproduced the final state in `28/28` fresh-session reads. Executed B003 UID0002Y3 remains supporting normalization evidence, while catalog entry `0424` is the authoritative completed transaction receipt for this target.
- No question remains as "needs investigation." All currently available bounded binary, documentation, generated, policy, sibling-control, negative, and deterministic IDA-readback routes were exhausted.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- `by-memory/-coverage-report.md`, replace the current UID00031I line in place with:
  `        - [UID:00031I][0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor](by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md) 0x004e8640-0x004e86bf | scalar deleting destructor | IMECandidatePane scalar deleting destructor : not_reconstructable : 92% : very-strong : Exact 127-byte class-owned MSVC wrapper; duplicates UID00031F candidate-container and Pane teardown, interprets four-byte deletingFlags, conditionally releases storage, and emits no independent source beyond UID00031F/UID00006F.`
- `by-memory/-coverage-report.md`, replace the current UID00031F line in place with:
  `        - [UID:00031F][0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor](by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md) 0x004e7cb0-0x004e7cfc | raw ordinary destructor | IMECandidatePane ordinary destructor : reconstructable : 91% : very-strong : Sole human IMECandidatePane destructor definition; exact 76-byte body restores candidate vptrs, clears visibleCandidates, releases its proxy, nulls +0xf8, and transfers to Pane teardown, while UID00031I remains compiler-only.`
- `by-class/-coverage-report.md`, replace the current UID00006F line in place with:
  `- [UID:00006F][IMECandidatePane](by-class/IMECandidatePane.md) : reconstructable : 90% : very-strong : IME candidate-list popup pane with exact constructor, display/dispatch/paint methods, CandidateStringList layout, sole ordinary destructor UID00031F, compiler-only non-emitting scalar wrapper UID00031I, vtable/adjustor liveness, and IMEPanes source route.`
- Inspected but unchanged: UID00018C, UID00018D, UID0002MU, UID00025J manual by-memory rows and UID0000K5 manual by-file row remain accurate at their current page-level scores after target-specific prose updates.
- B007 did not edit any coverage/tracker file. The supervisor applied these exact rows and validated them with commands `000000022382` and `000000022383`; final hashes are by-memory `8D080707A33B24C6A79CC91FE0CA1DFA339F5174F5B79FF94D01F59C35AF425B` and by-class `44C7B319DEFEC624AA25BDF8171A149BE62585C540B4559674153C50AD7100CA`. Generated tracker/coverage files remain validator-owned and were coherently refreshed by command `000000022384`.

## Follow-Up Actions

- Supervisor handoff: Gate 2A, Gate 2B IDA closure, manual coverage validation, coherent generated refresh, protected-state verification, and overall Gate 2 are complete. Perform fresh exact-artifact Gate 1 for this reconciled report to close C044, then run supervisor-only `execute_report` for C043.
- B007 implementation callback is complete: C001-C024 and C031-C036 were physically verified; no second ordinary callback is pending.
- Supervisor closure receipts are complete for C025-C030, C037-C042, and C045. C043/C044 are the only remaining rows.
- A-agent actions: none.
- B007 future research actions: none for UID00031I unless the supervisor identifies an exact current-artifact defect.

## Confidence

- Recommendation confidence: very high (`94`) for compiler/no-source classification, owner, exact behavior, source route, and the now-complete deterministic IDA handoff. I01-I03 bind every operation to a complete literal request object and ordered readback, accept only their literal prototypes and complete frame states, and fail closed without save on any deviation.
- Score confidence: high; `92/94` matches resolved sibling/compiler-wrapper depth without crossing the 95 final-code/provenance barrier.
- Remaining uncertainty is lexical/toolchain provenance only. It does not justify raw final names, a duplicate source body, proof-comment output, or unchanged low scores.

## Validator Results

- Six callback validators ran from `source-3/project-documentation`; each used the exact scoped form `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240 --no-generated-refresh`, exited `0`, reported `ok: 1`, and reported `generated_refresh: skipped`.
- UID00031I: command ID `000000022242`, validator timestamp `2026-08-11T15:23:08-04:00`, invocation window `2026-08-11T15:23:08.2167694-04:00` through `2026-08-11T15:23:10.4311110-04:00`.
- UID00031F: command ID `000000022243`, validator timestamp `2026-08-11T15:24:18-04:00`, invocation window `2026-08-11T15:24:17.9731641-04:00` through `2026-08-11T15:24:20.1872222-04:00`.
- UID00006F: command ID `000000022244`, validator timestamp `2026-08-11T15:25:29-04:00`, invocation window `2026-08-11T15:25:29.2273839-04:00` through `2026-08-11T15:25:31.4408603-04:00`.
- UID0000K5: command ID `000000022246`, validator timestamp `2026-08-11T15:26:42-04:00`, invocation window `2026-08-11T15:26:42.1864903-04:00` through `2026-08-11T15:26:44.3981069-04:00`.
- UID00018C: command ID `000000022248`, validator timestamp `2026-08-11T15:27:47-04:00`, invocation window `2026-08-11T15:27:47.6737593-04:00` through `2026-08-11T15:27:49.8825325-04:00`.
- UID00018D: command ID `000000022250`, validator timestamp `2026-08-11T15:28:43-04:00`, invocation window `2026-08-11T15:28:42.9478937-04:00` through `2026-08-11T15:28:45.1447597-04:00`.
- Gate 2A reran scoped validations as commands `000000022372-000000022378`; all six accepted destination hashes remained stable.
- Supervisor manual coverage commands `000000022382` and `000000022383` exited `0`, reported `ok:1`, and kept generated refresh disabled. Command `000000022382` reported only unrelated existing missing-reference warnings `00039L`/`0003T6`; command `000000022383` removed stale reverse-reference edges caused by the exact replacement prose.
- Coherent autogen command `000000022384` passed. Relevant hashes: `IMEPanes.cpp` `A12A8A207E705EC12012DDB3E08808D0B49FD229D8EE778BD35496256197ECBD`; `-ag-memory-coverage.md` `B5615B6138612AEA9E5A1432F9969B1C3AB10DEDE75E0B8F6E161F50E69B4942`; `-ag-class-coverage.md` `A1379B044BBEE652AED1FE42AD91AC388D3C81F4F88F9277DA807CB10EF2AE50`; `-ag-research-tracker.md` `2D874F4C2E4D079ABEC920D0E8CE3AEA5BAD9D872F17125B56FA1DE873E2222B`; generated by-memory aggregate `740744BD8E6ACFBC2B81905B49282737BC257A6E8B1A0C484C810760B34171DA`.
- B007 did not edit project-level/generated/coverage files. The primary supervisor owns those receipts and their validator side effects.

## Changed Files

- Updated report: `tools/leaser/Agents/Agent-B007/research/00031I-IMECandidatePaneScalarDeletingDestructor-source-quality.md`.
- Modified and verified: UID00031I SHA256 `4E6C25C61280E50A16BF1A3B0EAD5026D704302401C55C3F05D42AD72F1F5BED`; UID00031F `EAD83F295BA115A11CAE02641A185E985CA46FC0780CEF6E82A2BDAB9FB11B22`; UID00006F `83B91F783B465808E3EE3A42C1B16CD9AD87BD9F56F0415BE8363830466D1BDF`; UID0000K5 `3C0780DC063DF4967FD404C5566DFBE679C34CB6C21B9EF175A98E689CB870A7`; UID00018C `191F0B2D5DAB0EC55075DE3A1E46C2E783A04659FCDFF973734F69C6CFEC4A3A`; UID00018D `9D909D1EE61EE744D57B19B1AA26FE968C866F582114610072F16963A7B772EC`.
- Physically verified without edit: UID0002MU SHA256 `9D908AAC394F0CA80CB3E33640CA6D47BC2566E1D0DA399D23CA754DFF592561`; UID00025J `35197EBCBCFAC568F0E45AE180AC386DBD0A38D91AC539775026636B370339ED`.
- Supervisor-modified and validated manual files: `by-memory/-coverage-report.md` SHA256 `8D080707A33B24C6A79CC91FE0CA1DFA339F5174F5B79FF94D01F59C35AF425B`; `by-class/-coverage-report.md` SHA256 `44C7B319DEFEC624AA25BDF8171A149BE62585C540B4559674153C50AD7100CA`.
- Supervisor-refreshed generated truth: `auto-generated/NexusTK/input/IMEPanes.cpp` SHA256 `A12A8A207E705EC12012DDB3E08808D0B49FD229D8EE778BD35496256197ECBD`, with no UID00031I marker/body and UID00031F as sole destructor definition; no `IMEPanes.h` exists or is expected.
- Supervisor IDA persistence: canonical pre/post SHA256 `BA6D026C06D368919C597196E9035B81E10ECF22841A3673A1FD5A57D4BBAFE2` -> `DAD3B9B3C923FE8C6EE972818ED9EAA9C288A6467A05072827D2DE0B12B19CDC`; byte-identical backup/copy paths and catalog entry `0424` are recorded under IDA MCP Facts.
- Renamed/moved: none.
- Callback leases were taken only for each immediate document edit/validator batch and released immediately afterward; the report lease is released immediately after this reconciliation and stable reread.
- Report lifecycle boundary: execution/archive state is supervisor-owned and authoritative only from this report's current path plus validator-owned status/history metadata.

## Implementation Tracking Checklist

| Checked | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C001 | 00031I | B007: record exact `[0x004e8640,0x004e86bf)`, 127-byte range and SHA256 `6D7E...95EF`. | Very high | Live bytes/hash and modeled bounds. | `by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md` Status/Evidence | incorporate | applied |
| [x] | C002 | 00031I | B007: record 39 instructions, five blocks, complexity 2, complete-this receiver, four-byte hidden flag, return-this, and `ret 4`. | Very high | Analyze/disassembly/frame. | UID00031I Behavior/ABI | incorporate | applied |
| [x] | C003 | 00031I | B007: record vptr stores `0x61c474/0x61c4c0/0x61c4f0` at `+0/+0xa0/+0xa4`. | Very high | Instructions and vtable xrefs. | UID00031I Behavior/Evidence | incorporate | applied |
| [x] | C004 | 00031I | B007: record `visibleCandidates +0xf8` clear through UID0002MU. | Very high | Constructor/class/clear-helper/target data flow. | UID00031I Behavior; UID00006F support | incorporate | applied |
| [x] | C005 | 00031I | B007: record eight-byte container-proxy release through `sub_5C7526` and nulling of `+0xf8`. | Very high | Exact push/call/store sequence and helper body. | UID00031I Behavior/Evidence | incorporate | applied |
| [x] | C006 | 00031I | B007: record inherited Pane teardown through `Pane__Destructor` without ownership transfer. | Very high | Direct callee and Pane comment/type. | UID00031I Behavior/Evidence | incorporate | applied |
| [x] | C007 | 00031I | B007: record exact mask `0x1`/`0x4` truth table and branch ordering. | Very high | Complete disassembly. | UID00031I ABI table | incorporate | applied |
| [x] | C008 | 00031I | B007: record `0x118` complete-object size and one-byte no-op disposition; reject sized/vector delete. | Very high | Direct branch/callee/item/object-layout evidence. | UID00031I ABI/Negative Evidence | incorporate | applied |
| [x] | C009 | 00031I | B007: record original complete-object pointer returned on every path. | Very high | All exits and EAX writes. | UID00031I ABI | incorporate | applied |
| [x] | C010 | 00031I | B007: record two thunk code refs plus primary-vtable data ref and zero ordinary callers. | Very high | `xrefs_to` and analyze result. | UID00031I Xrefs | incorporate | applied |
| [x] | C011 | 00031I | B007: record exact successor `0xcc`, sibling start `0x004e86c0`, and no split/range change. | Very high | Boundary bytes/item lookup. | UID00031I Range analysis | incorporate | applied |
| [x] | C012 | 00031I | B007: record byte-for-byte cleanup parity with UID00031F and the sole human destructor source route. | Very high | Raw UID00031F bytes/hash and source docs. | UID00031I Reconstruction; UID00031F support | incorporate | applied |
| [x] | C013 | 00031I | B007: retain semantic owner UID00006F and source file UID0000K5 while rejecting Pane/STL/runtime/no-owner alternatives. | Very high | Vtables, class state, source routing. | UID00031I Status/Ownership | incorporate | applied |
| [x] | C014 | 00031I | B007: change to `RECONSTRUCTABLE:FALSE`, blank emitter/position, `Nested:0`. | Very high | Compiler-only no-source proof. | UID00031I metadata | incorporate | applied |
| [x] | C015 | 00031I | B007: raise score from `86/91` to `92/94` with exact not-higher/not-lower rationale. | High | Closed blocker matrix. | UID00031I metadata/Score Rationale | incorporate | applied |
| [x] | C016 | 00031I | B007: make formal CPP and H literally blank; remove proof-comment emission and reject duplicate source. | Very high | Sole UID00031F/UID00006F human source. | UID00031I formal CPP/H/Reconstruction | incorporate | applied |
| [x] | C017 | 00031I | B007: replace Item Summary and preserve historical B008 proof-comment state as superseded history. | Very high | Current page/generated state and current policy. | UID00031I Item Summary/Changes | incorporate | applied |
| [x] | C018 | 00031I | B007: raise UID00031F to `91/94` and add exact hash/parity/source-coverage evidence without changing owner/emitter/formal body. | High | Exact raw bytes and target comparison. | `by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md` | incorporate | applied |
| [x] | C019 | 00031I | B007: raise UID00006F to `90/93`; update scalar row and destructor/source-container evidence without changing class formal source. | High | Full class/target/ordinary/vtable relation. | `by-class/IMECandidatePane.md` | incorporate | applied |
| [x] | C020 | 00031I | B007: update UID0000K5 candidate row/evidence to one ordinary source destructor plus non-emitting compiler wrapper; retain `91/90`. | High | Current file inventory and generated route. | `by-file/IMEPanes.md` | incorporate | applied |
| [x] | C021 | 00031I | B007: update UID00018C target row/evidence to `92/94` false/non-emitting and exact cleanup/ABI disposition; retain aggregate `86/91`. | High | Exact child result and mixed aggregate policy. | `by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md` | incorporate | applied |
| [x] | C022 | 00031I | B007: add candidate thunk hashes, names, exact deltas/routes, and non-source disposition; retain UID00018D `85/90`. | Very high | Live 11-byte bodies/hashes/vtable refs. | `by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md` | incorporate | applied |
| [x] | C023 | 00031I | B007: verify UID0002MU remains `86/90`, false/no-owner/no-emitter/blank and already documents exact STL clear behavior. | High | Physical page and live target call. | `by-memory/0x004e8a00-0x004e8ae6.CandidateStringQueueClear.md` | already-present | already-present |
| [x] | C024 | 00031I | B007: verify UID00025J remains `88/92`, source-file-owned generated data and already maps the three candidate vtables. | High | Physical page and live vtable xrefs. | `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md` | already-present | already-present |
| [x] | C025 | 00031I | Supervisor: replace stale manual by-memory UID00031I row with exact false/92% text. | High | Applied and validated by command `000000022382`; final by-memory coverage SHA256 `8D080707A33B24C6A79CC91FE0CA1DFA339F5174F5B79FF94D01F59C35AF425B`. | `by-memory/-coverage-report.md` | incorporate | applied |
| [x] | C026 | 00031I | Supervisor: replace stale manual by-memory UID00031F row with exact 91% text. | High | Applied and validated by command `000000022382`; final by-memory coverage SHA256 `8D080707A33B24C6A79CC91FE0CA1DFA339F5174F5B79FF94D01F59C35AF425B`. | `by-memory/-coverage-report.md` | incorporate | applied |
| [x] | C027 | 00031I | Supervisor: replace stale manual by-class UID00006F row with exact 90% text. | High | Applied and validated by command `000000022383`; final by-class coverage SHA256 `44C7B319DEFEC624AA25BDF8171A149BE62585C540B4559674153C50AD7100CA`. | `by-class/-coverage-report.md` | incorporate | applied |
| [x] | C028 | 00031I | Supervisor: execute I01's exact ordered contract of full rename dry-run/apply objects, one literal set-type object, one literal function-comment object, four literal address-comment clear objects, and immediate readback after each stage; accept only I01's literal prototype and complete three-row frame. | Very high | Applied/saved/fresh-session verified under catalog `0424`; pre/post IDB SHA `BA6D026C...BBAFE2` -> `DAD3B9B3...B19CDC`; exact name/type/frame/comment/clears reproduced. | IDA `0x004e8640` | incorporate | applied |
| [x] | C029 | 00031I | Supervisor: execute I02's exact ordered contract of full rename dry-run/apply objects, one literal set-type object, one literal function-comment object, and immediate readback after each stage; accept only I02's literal prototype and complete two-row frame. | Very high | Applied/saved/fresh-session verified under catalog `0424`; exact A0 name/type/frame/comment and unchanged 11-byte body/data route reproduced. | IDA `0x004e85dc` | incorporate | applied |
| [x] | C030 | 00031I | Supervisor: execute I03's exact ordered contract of full rename dry-run/apply objects, one literal set-type object, one literal function-comment object, and immediate readback after each stage; accept only I03's literal prototype and complete two-row frame. | Very high | Applied/saved/fresh-session verified under catalog `0424`; exact A4 name/type/frame/comment and unchanged 11-byte body/data route reproduced. | IDA `0x004e85e7` | incorporate | applied |
| [x] | C031 | 00031I | B007 callback: run scoped target validator with `--no-generated-refresh` and record receipt/readback. | High | Required callback gate. | UID00031I validator/readback | incorporate | applied |
| [x] | C032 | 00031I | B007 callback: run scoped UID00031F validator with `--no-generated-refresh` and record receipt/readback. | High | Required callback gate. | UID00031F validator/readback | incorporate | applied |
| [x] | C033 | 00031I | B007 callback: run scoped UID00006F validator with `--no-generated-refresh` and record receipt/readback. | High | Required callback gate. | UID00006F validator/readback | incorporate | applied |
| [x] | C034 | 00031I | B007 callback: run scoped UID0000K5 validator with `--no-generated-refresh` and record receipt/readback. | High | Required callback gate. | UID0000K5 validator/readback | incorporate | applied |
| [x] | C035 | 00031I | B007 callback: run scoped UID00018C validator with `--no-generated-refresh` and record receipt/readback. | High | Required callback gate. | UID00018C validator/readback | incorporate | applied |
| [x] | C036 | 00031I | B007 callback: run scoped UID00018D validator with `--no-generated-refresh` and record receipt/readback. | High | Required callback gate. | UID00018D validator/readback | incorporate | applied |
| [x] | C037 | 00031I | Supervisor: apply and validate exact manual coverage replacements; B007 must not edit coverage files. | High | Commands `000000022382`/`000000022383` passed exit `0`, `ok:1`; final by-memory/by-class hashes are recorded above. | Manual coverage files | incorporate | applied |
| [x] | C038 | 00031I | Supervisor: perform coherent generated refresh/readback and prove UID00031I marker/comment disappears while UID00031F source remains. | High | Autogen `000000022384` passed; `IMEPanes.cpp` SHA256 `A12A8A207E705EC12012DDB3E08808D0B49FD229D8EE778BD35496256197ECBD`, no UID00031I marker/body, UID00031F sole destructor, no header expected. | Validator-owned generated output | incorporate | applied |
| [x] | C039 | 00031I | Supervisor: perform fresh exact-artifact Gate 2A review of this post-callback report and accepted implementation. | Very high | Gate 2A passed all `30/30` checked B007 claims at pre-reconciliation SHA `85D7C6DF...5F770`. | Current report artifact and accepted implementation | incorporate | applied |
| [x] | C040 | 00031I | Supervisor: confirm the accepted same-report callback was limited to ordinary-doc claims and reconcile any exact Gate 2A defect. | Very high | Gate 2A confirmed ordinary-only callback scope; no ordinary defect required repair. | Report and listed by-* docs | incorporate | applied |
| [x] | C041 | 00031I | Supervisor: perform claim-by-claim Gate 2A after callback and fresh scoped validation. | Very high | Claim-by-claim Gate 2A and commands `000000022372-000000022378` passed with stable destination hashes. | Accepted implementation | incorporate | applied |
| [x] | C042 | 00031I | Supervisor: perform Gate 2B IDA preflight/mutation/save/readback or exact no-change rejection. | Very high | Public-attested I01-I03 applied, one save, `30/30` same-session and `28/28` fresh-session verification; catalog `0424`. | Current canonical IDA database | incorporate | applied |
| [ ] | C043 | 00031I | Supervisor: run report lifecycle execution only after Gates 2A and 2B pass and all supervisor-owned coverage/generated work is reconciled. | Very high | Lifecycle boundary. | Validator-owned report lifecycle | incorporate | proposed |
| [ ] | C044 | 00031I | Supervisor: independently confirm the stable post-callback report has 33 headings, exact ledger/checklist parity, zero executable script fences, one terminal marker, and no lease before lifecycle action. | Very high | Prior current-hash check passed, but this reconciliation invalidates it; fresh exact-artifact Gate 1 must close C044. | This report | incorporate | proposed |
| [x] | C045 | 00031I | Supervisor: preserve ordinary raw range, vtables, helpers, bytes, frame structure, repeatable channels, and all protected no-change dependencies. | Very high | Same-session protection `30/30` and independent fresh-session persistence `28/28` passed with raw UID00031F and all protected dependencies unchanged. | IDA protected dependencies | already-present | applied |

Current checklist allocation: `43 checked` and `2 unchecked`. C043 and C044 are the only unchecked rows.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000022401","destination_path":"executed-b-agent-research/B007/00031I-IMECandidatePaneScalarDeletingDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/00031I-IMECandidatePaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-11T19:05:53-04:00","uid":"00031I"} -->
<!-- {"agent":"B007","command_id":"000000023069","details":"report marked for revalidation","event":"needs-revalidation","issue":"legacy executable/request-package material removed into inert same-stem companion; fresh Gate 1 required","source_path":"executed-b-agent-research/B007/00031I-IMECandidatePaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T05:24:35-04:00","uid":"00031I"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
