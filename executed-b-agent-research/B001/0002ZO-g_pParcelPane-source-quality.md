** TARGET-REPORT-UID:0002ZO **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002ZO g_pParcelPane Ownership / Source-Quality Research


## Finalized Report / Current Recommendation

- Current implementation: [UID:0002ZO] `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md` is the exact non-emitting physical-storage page for the source-level singleton pointer represented by [UID:0000RY] `g_pParcelPane`.
- Final target disposition: `COMPLETION:92`, `CONFIDENCE:94`, semantic `CANONICAL_OWNER:0000RY`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, blank formal C++, and retained `Nested:4` because it is the first exact child of [UID:0002A0].
- Sole source definition: [UID:0000RY] is `92/94`, owned/emitted by [UID:0000MF] at position `50`, and emits exactly `ParcelPane *g_pParcelPane = NULL;`.
- Source-family closure: complete ParcelPane, ParcelIconPane, and FlyingParcelPane declarations are applied; both Pane/Singleton direct-base lifetimes and every source-authored parcel method are documented; raw `0x005460f0` emits as an out-of-line ParcelIconPane method inlined into its callback; target/layout/vtable/compiler marker pollution is absent from generated source.
- Source route: keep one module, `NexusTK/ui/panels/ParcelPane.cpp`, with class roots ParcelPane/ParcelIconPane/FlyingParcelPane at positions `10/20/30`, singleton definitions at `40/50`, and class-child positions listed below.
- Confidence: very strong for storage, bytes, references, RTTI/PMD/EBO, behavior, class layouts, source/compiler split, and one-definition route; bounded below `95` because original private member spellings and header separation are inferred rather than symbol-proven.
- Callback state: 38 authorized ordinary pages were edited and scoped-validated under short leases; D32/D39/D40 were verified without B001 edits at the callback checkpoint; corrective D4/D8 commands `000000016270`/`000000016271` and final waited command `000000016272` completed after leases cleared. B005 later completed protected D39 externally without changing B001's successor-boundary claim. After B001's report-only reconciliation, the supervisor applied all 38 exact manual handoff rows through commands `000000016365`-`000000016370` and completed final waited command `000000016371`; those are external supervisor/validator actions, not B001 edits. B001 did not edit manual coverage, generated/tracker files, audit/supervisor/validator state, lifecycle state, or IDA, and ran no report execution/lifecycle/move/archive command. All 100 claims are terminal and all 63 accepted checklist rows are checked.

## Supporting Research

- Current direct evidence was collected from active NexusTK IDB session `9b0396a3`, current executable `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, current ordinary docs, current manual coverage rows, and current generated `ParcelPane.cpp`.
- Search roots checked with `0002ZO`, `0069ba28`, `g_pParcelPane`, `ParcelNotificationPanes`, `ParcelIconPaneParcelUpdateRawHelper`, `ClearParcelPaneSingleton`, and `FlyingParcelPane`:
  - `tools/leaser/Agents/Agent-B001/research` through `Agent-B005/research`: no direct UID0002ZO report. B002's evidence-time active `0001PY-g_pBowGaugeObjectPane-source-quality.md` was adjacent-slot coordination evidence only; its current ordinary page later advanced independently and still does not cover UID0002ZO.
  - `executed-b-agent-research/B003/0002A0-ParcelAndPatchPaneSingletonSlots-memory-range-report.md`, SHA256 `F1DEBFD2DEA6061286B3C6493CAF10FB9204743A0713FBD8EDE2A6D5FE79A944`: direct split-index lead; its zero-filled virtual-tail conclusion is independently reconfirmed here.
  - `executed-b-agent-research/B005/0000MF-ParcelPane-empty-emitter-family-source-quality.md`, SHA256 `8B478052E7B9FD468E5633BEEFB65CE4F4F2C664394F0C295DBF10308849D2C9`: direct source-family lead; its comment-marker workaround is superseded by the present duplicate-free complete-declaration/no-code disposition.
  - `executed-b-agent-research/B006/0002KN-ClearParcelPaneSingleton-source-quality.md`, SHA256 `D0AD828754ABD1178A3E575B9379727A2CCEF9F0A674B34EB4A638C7C929B007`: direct compiler/EH clear-helper proof, incorporated and independently reconfirmed.
  - `executed-b-agent-research/B001/00043J-ParcelIconPaneParcelUpdateRawHelper-by-memory-source-quality.md`, SHA256 `FEBF518428F07D67300CB3B7DF5025F294FD3598C8E19FA35BE14C245FC64A0F`: direct raw-helper lead; its no-code conclusion is superseded by the new exact raw/callback equivalence and inline-source explanation.
  - `executed-b-agent-research/B002/0001EL-0001EN-flyingparcelpane-lifecycle-source-quality.md`: direct Flying lifecycle lead; source/compiler split retained, class-access integration strengthened.
  - `executed-b-agent-research/B012/000058-FlyingParcelPane-class-source-quality.md`, SHA256 `05D7A0EC969705039977B367C305EF49D87AF30B7C12C24B7E4D61F9FCB24634`: direct class/private-helper lead; declaration blocker is closed here.
  - `executed-b-agent-research/B001/0001EO-ParcelIconPaneScalarDeletingDestructor-source-quality.md`, post-report evidence-time SHA256 `676F8975A8159684E634684940315563C3C1E9BF67B4E4E65C08CFA40246C40F`: direct ParcelIconPane direct-base/class-shape proof, preserved.
  - Other matching executed reports for individual ParcelPane and FlyingParcelPane methods were opened as child-specific evidence, not substitutes for this whole-family pass.
  - `tools/leaser/Agents/Older-Research/**` and `tools/leaser/Agents/SpecialReports/**`: searched with the same UID/address/name/source-family terms; no matching report was found.
- Explicit no-direct-report conclusion: no prior report directly closes UID0002ZO's current physical-versus-semantic one-definition target together with the complete current Parcel notification source family.

## Target

- Target UID: `0002ZO`.
- Target path: `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md`.
- Queue source: historical pre-callback `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Current target header: `92/94`, semantic owner UID0000RY, reconstructable false, no emitter, blank position/formal, `Nested:4`.
- Exact range: `[0x0069ba28,0x0069ba2c)`, four bytes, 32-bit `ParcelPane *` storage.
- Accepted target header: `92/94`, semantic owner UID0000RY, reconstructable false, no emitter, blank position/formal, `Nested:4`; applied and validated by command `000000016167`.

## Current Target State

- The page has the correct exact range, four zero bytes, nine-reference family, split-index child relationship, source name, semantic UID0000RY link, false/non-emitting metadata, and exactly blank formal block.
- UID0000RY is the sole source definition. The former reconstructable/file-emitting/comment-marker state is retained only as a superseded pre-callback assumption.
- Fresh PE mapping proves RVA `0x29ba28` lies in `.data` virtual size but beyond the section's raw-backed end RVA `0x27a800`; the four bytes are loader-zeroed BSS-style storage with no source `0xffffffff` initializer bytes.
- Fresh IDA reads show zero for every dword in `[0x0069ba20,0x0069ba38)`. UID0002ZP remains the protected zero-filled successor beginning exactly at `0x0069ba2c`; B001's callback checkpoint was SHA256 `6AE27F3408441A2015F9DFBFF522CB2875BBB6445F60AF2FBD76D57BA3DBB6E8`, 8,572 bytes/84 lines, and B005's later external completion is SHA256 `D1FB8382F6FD3767306DB71ABAF3EDA9F2C1EE4B48724B894F4709852D4B1A9D`, 9,097/89. B002's UID0001PY predecessor was not edited by B001; UID0002A1 documents the zero/no-xref filler and historicalizes its old `ff` wording.
- Historical generated command `000000016132`, SHA256 `3DC71F686425ACE8766E94AE8DC7528C437025E420DC06AA438C004F519CE2AE`, 4,771 bytes/130 lines, records the pre-callback omissions. Initial waited command `000000016246` and later header-only command `000000016248` are evidence-time callback snapshots. After the exact D4/D8 formal corrections, B001's final authorized waited command `000000016272`, SHA256 `FA543CE85E2F762B432A7AC20AFFA289CF85B27BD7EB7066F41D009D1A616647`, 17,715 bytes/560 lines, became the accepted callback checkpoint. Later read-only external commands `000000016340` and `000000016371` advanced generated metadata only. Command `000000016371` is the current supervisor-owned checkpoint, SHA256 `BD29AB0038F89A0E2734D34C17AA199E6528D70A7DFDBF00D64231BAC1E2E2AB`, 17,715 bytes/560 lines, and preserves exactly 9 ParcelPane definitions, 4 ParcelIconPane definitions, 5 FlyingParcelPane definitions, one `g_pParcelPane` definition, one `g_pParcelIconPane` definition, zero UID0002ZO/UID0002W9 physical markers, zero Empty Emitter Markers, and zero decompiler labels.
- Manual coverage synchronization is complete externally. Supervisor commands `000000016365`-`000000016370` applied and validated all 38 exact literal handoff rows once each: 30 by-memory rows including UID00043J, three by-class rows, one by-file row, two by-global rows, one by-struct row, and one by-vtable row. Final waited command `000000016371` preserved those rows and refreshed generated output. B001 did not edit any manual coverage file.
- Historical tracker command `000000016161` recorded the pre-callback `86/90` queue row; commands `000000016246`, `000000016248`, `000000016272`, and `000000016276` are command-scoped evidence-time snapshots rather than indefinite-current requirements. A later bounded read observed unrelated validator-owned tracker command `000000016344`, SHA256 `2781E186632337049194F0A8F5E05FCC78FFE488908D37FC59B57CC16F3462BE`, 1,557,917 bytes/6,301 lines; it preserves UID0002ZO and UID0002ZP at `92/94`, reconstructable false. Subsequent unrelated tracker epochs remain external mutable state and do not supersede the ordinary evidence or generated semantics.
- During the initial report-only pass, B001 performed no ordinary edit, lease, validator, or generated refresh. During the accepted callback, B001 performed the authorized ordinary edits, short leases, scoped validators, and final waited refresh enumerated below. IDA mutation, manual coverage edits, report execution, archive, move, and lifecycle commands remained unperformed.

## Executive Recommendation

1. Physical and semantic ownership are separated: UID0002ZO is false/non-emitting physical storage owned semantically by UID0000RY; UID0000RY is the only source definition under UID0000MF.
2. UID0002W9 has the same no-duplicate physical disposition; UID0000RX remains the sole `g_pParcelIconPane` definition.
3. ParcelPane and ParcelIconPane have complete `Pane, Singleton<...>` declarations; publication and clear stores are direct-base lowering, not handwritten assignments.
4. FlyingParcelPane is a complete Pane-derived implementation-private class and uses the private friend-accessible ParcelPane completion helper.
5. `0x005460f0` emits as `ParcelIconPane::UpdateParcelCounts(const unsigned char *)`; `OnParcelUpdate` is the opcode gate/call wrapper, preserving the exact retained-out-of-line plus inlined binary relationship.
6. Cleanup funclets, adjustor thunks, scalar deleting destructors, vtable/RTTI bytes, layout support, and aggregate indexes are blank/non-emitting compiler/data evidence.
7. All 38 changed ordinary pages passed scoped validation; corrective D4/D8 validation and final waited command `000000016272` produced one duplicate-free source union matching all eighteen accepted formals, and external command `000000016340` later reconfirmed the same semantics.

## Supervisor Active Recheck

- The accepted callback has closed UID0002ZO and the complete Parcel notification family; old `86/90` and comment-marker conclusions are historical only.
- No split or UID registration is required: the physical target and every executable source child already have exact pages and stable UIDs.
- Every source-bearing range is destination-ready at same-or-greater detail. Every compiler/data range has an exact no-code disposition.
- B002-owned UID0001PY remained protected and was not edited by B001. Its latest observed ordinary hash is `800D080E300E186E4A5170D9A71BB03220E0E3B92DCF934E3713A059CDD882A6`; B001 uses only its durable adjacent-boundary evidence.

## Inference Research Guidance Check

- IDA facts, documentation facts, generated-routing observations, and source-shape inference are labeled separately throughout.
- Current docs and executed reports were treated as leads. Material claims were rechecked against session `9b0396a3`, raw PE mapping, exact bytes, xrefs, RTTI, function bodies, and current generated output.
- Source names use existing subsystem conventions: `g_p...` globals, `m_...` fields, Pane method conventions, `ParcelButtonState`, `SetParcelSlotData`, `AdvanceButtonAnimation`, and `ResolveButtonFrameIndex`.
- Compiler output is not emitted as handwritten source: vptr stores, null-adjusted Singleton publication, unwind cleanup, adjustor thunks, scalar-delete flags, vtables, RTTI, and address-fixed storage remain evidence only.
- Wave2/Wave3 and `simroot_v2` mentions were found in current historical prose. They were ignored as authority; omissions and wrong ownership are retained only as explicitly superseded history.

## Heuristic / Inference Reanalysis And Validation

### Physical storage and initializer

- Direct fact: `0x0069ba28` is four zero bytes in live IDA; SHA256 of the exact payload is `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- Direct fact: `.data` begins RVA `0x26d000`, virtual size `0x2fe24`; its raw-backed data ends RVA `0x27a800`. Target RVA `0x29ba28` is virtual-only and has no physical raw file offset.
- Resolution: source spelling is null initialization, `NULL` for project-era C++03. Historical `ff ff ff ff` / `0xffffffff` is rejected as a stale raw-offset/tool interpretation.

### Physical versus semantic one-definition

- UID0002ZO documents where the compiler/linker allocated the pointer; UID0000RY documents the source symbol and emits its sole definition.
- Retaining semantic owner UID0000RY on the false physical page preserves navigation while clearing source emission. Direct file UID0000MF remains owner/emitter of UID0000RY, not of the physical bytes.
- The target must not emit even a covered-by comment because generated C++ should contain the definition once and no address-storage artifact.

### Singleton source shape

- RTTI and PMD evidence proves direct empty `Singleton<ParcelPane>` and `Singleton<ParcelIconPane>` source bases at effective PMD `+0xf8`; EBO overlaps the first derived state byte.
- Constructor store pairs select adjusted `this` or null when `this == -248`; reverse destruction clears occur between derived cleanup and Pane teardown. That is compiler inlining of Singleton base construction/destruction.
- Resolution: constructors initialize the Singleton base; ordinary destructors contain only derived cleanup. No source body manually publishes or clears either global.

### ParcelIconPane raw helper

- Exact raw range `[0x005460f0,0x005461c0)`, SHA256 `E20711EEBE0A6B2AD37B5AFEED2EB94963A96FE826D70793FCC96D669FC61B8D`, is 71 instructions, `this` in ECX, one stack payload argument, `retn 4`, and false return.
- It lacks the callback's opcode check but duplicates the count-offset decode, nibble split, old/new comparisons, owner writes, child load, and `SetParcelSlotData` call exactly.
- No absolute VA, RVA, rel32, modeled-function, or inbound-xref route was found. This is not evidence that the source method was absent: a normal externally linked member may remain out of line while its sole callback call is optimized inline.
- Resolution: source method `UpdateParcelCounts(const unsigned char *packet)` owns the raw body; `OnParcelUpdate` performs the opcode gate and invokes it. This is behavior-identical and removes the prior blank-C++ blocker without claiming an original symbol.

### ParcelPane declaration and cross-class access

- Exact object size is `0x124`; fields occupy `+0xf8..+0x121`, followed only by natural alignment. No explicit reserved member is warranted.
- The direct Singleton base explains publication/clear. The existing timer/input/paint/animation formals already prove all declarations.
- Flying completion directly affects ParcelPane private state and inherited Pane bounds. A simple `friend class FlyingParcelPane` alone does not grant access to Pane's protected member through a sibling object.
- Resolution: a private inline `FinishFlyingParcelAnimation(total,left,right)` method inside ParcelPane performs the setter call, action-enable write, and self-invalidation. FlyingParcelPane is a friend and invokes that helper. The compiler may inline it into `AnimateStep`, reproducing the observed direct accesses without illegal source.

### FlyingParcelPane declaration

- Exact fields: frame/count/right/left bytes at `+0xf8..+0xfb`, bool at `+0xfc`, natural alignment through `+0xff`, and `Layer *m_animationLayer` at `+0x100`; size `0x104` follows naturally.
- The class is an implementation-private Pane-derived helper, not a Singleton and not a separate source module.
- Constructor, destructor, start, timer-step, and paint/draw bodies are all source-authored. Scalar wrapper and adjustors are compiler output.

### Source order and generated route

- ParcelPane declaration must precede ParcelIconPane's constructor definition because `new ParcelPane` requires a complete type in the generated single translation unit.
- Root order `ParcelPane` 10, `ParcelIconPane` 20, `FlyingParcelPane` 30, `g_pParcelIconPane` 40, `g_pParcelPane` 50 is therefore source-legal and deterministic.
- Existing binary address order differs; address order is evidence, not a requirement to emit invalid C++.

### Rejected alternatives

- Rejected: target remains reconstructable/comment-emitting. Reason: duplicates UID0000RY and pollutes source with physical-address documentation.
- Rejected: source initializer `0xffffffff`. Reason: no raw backing and live bytes are zero.
- Rejected: manual `g_pParcelPane = this/NULL`. Reason: direct Singleton base, PMD, EBO, and store timing.
- Rejected: raw helper stays no-code. Reason: exact duplicate behavior and ABI support a source method plus compiler inlining.
- Rejected: raw helper merged into callback only. Reason: retained out-of-line body requires a source-level entity.
- Rejected: Flying direct access to ParcelPane's inherited `m_bounds`. Reason: source-illegal sibling protected access.
- Rejected: public fields/getters invented for Flying. Reason: private inline friend helper preserves observed behavior with smaller API exposure.
- Rejected: explicit alignment arrays in any class. Reason: natural x86 alignment produces all observed offsets.
- Rejected: separate ParcelIconPane/FlyingParcelPane source files. Reason: address clustering, resources, globals, vtables, and current file route support one ParcelPane module.

## Evidence Standards Used

- Strongest evidence: exact bytes, PE section arithmetic, SHA256 payload/range hashes, bounded MCP xrefs, decompilation/disassembly, RTTI/PMD, vtable slots, constructor/destructor store order, object allocation sizes, and generated-source readback.
- Corroborating evidence: current by-memory/by-class/by-file/by-global/by-type docs and matching executed reports.
- Inference is used only for source-facing spellings and private organization after behavior, layout, ABI, and route were closed.
- Negative evidence includes no raw helper route, no target raw backing, no `0x0069ba30` xrefs, no extra global definition need, no final-dword ParcelIconPane accesses, and no direct handwritten need for compiler artifacts.
- The confidence ceiling is `94`; no item receives `95+` because original symbols/header boundaries are unavailable.

## Evidence Checked

- MCP transport: streamable JSON-RPC initialize -> tools/list -> tools/call at `http://127.0.0.1:13337/mcp`.
- Session discovery: one active adopted NexusTK worker, database `9b0396a3`, worker PID `15732`, `is_analyzing:false`.
- Health: `status:ok`, image base `0x400000`, auto-analysis/Hex-Rays/string cache ready.
- Bounded calls: `lookup_funcs` for `0x00545e40`, `0x00546290`, `0x00546d70`, `0x00546e80`, `0x00547000`; `get_bytes` for `0x0069b4cc` and `0x0069ba20`; `xrefs_to` for `0x0069b4d0`, `0x0069ba28`, `0x0069ba2c`, and `0x0069ba30`; prior same-pass decompile/disassembly, list-global, RTTI, byte, immediate, and PE scans enumerated below.
- Final bounded confirmation: a fresh transport initialization returned one active adopted session `9b0396a3`/worker PID `15732`; `server_health` again returned `status:ok` with analysis, Hex-Rays, and strings ready; schema-exact `get_bytes` for `[0x0069ba20,0x0069ba38)` again returned 24 zero bytes.
- Tool-call limitations: one first research `get_bytes` request used the obsolete `addr/size` top-level shape and returned `missing required parameters: ['regions']`. During final confirmation, a PowerShell helper accidentally used the reserved automatic `$args` variable and serialized tool arguments as a list, then one region used `address` rather than schema-exact `addr`; the server rejected both malformed request shapes. `tools/list` was read, the current `regions: { addr, size }` schema was used, and the valid bounded retry succeeded. These were client request-shape errors, not MCP loss; no evidence from failed calls was consumed.
- Raw executable scan: little-endian VA `0x0069ba28` occurs at nine file offsets `0x00145304`, `0x0014530c`, `0x001456e2`, `0x001456ea`, `0x0014588f`, `0x001461be`, `0x001461d4`, `0x00146282`, `0x00146456`; RVA pattern has zero hits.
- Raw-helper negative scans: no absolute VA, RVA, or rel32 edge to `0x005460f0`, `0x00546ac0`, `0x00546b80`, or `0x00546bc0`.
- Current docs checked: D1-D41 destinations listed below, direct resources/globals, adjacent UID0001PY/UID0002ZP/UID0002A1, `by-memory/-ignored.md`, all six relevant manual coverage files, current generated ParcelPane source, and current tracker.
- Historical roots/results are path-classified under Supporting Research. No direct Older-Research/SpecialReports hit exists.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C2ZO-001 | Target range is exactly `[0x0069ba28,0x0069ba2c)`. | 94 | IDA item/adjacency/PE map | D1 range/evidence | incorporate | applied |
| C2ZO-002 | Exact target payload is four zeros, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. | 94 | valid MCP get_bytes | D1 storage | incorporate | applied |
| C2ZO-003 | Target is virtual `.data` tail with no raw-file backing. | 94 | PE section arithmetic | D1 storage/history | incorporate | applied |
| C2ZO-004 | Source type is `ParcelPane *`. | 94 | all nine typed uses/class route | D1/D2/D3 | incorporate | applied |
| C2ZO-005 | Source-facing name is `g_pParcelPane`. | 94 | current subsystem/global convention | D1/D2 | already-present | already-present |
| C2ZO-006 | Historical `0xffffffff` target initializer is stale. | 94 | zero bytes/no raw backing | D1/D35/manual | historicalize | applied |
| C2ZO-007 | UID0002ZO is physical storage, not an independent source definition. | 94 | one-definition analysis | D1 | incorporate | applied |
| C2ZO-008 | UID0000RY is the sole semantic source global. | 94 | current formal and source route | D2 | incorporate | applied |
| C2ZO-009 | Target owner becomes semantic UID0000RY. | 93 | modern physical/global pattern | D1 metadata | incorporate | applied |
| C2ZO-010 | Target becomes false/non-emitting/blank formal. | 94 | duplicate-free generated requirement | D1 metadata/formal | incorporate | applied |
| C2ZO-011 | Target retains `Nested:4` as first UID0002A0 child. | 94 | address-sorted hierarchy | D1 metadata | already-present | already-present |
| C2ZO-012 | UID0002A0 remains false split index over two exact dwords. | 94 | exact child ranges/distinct xrefs | D35 | incorporate | applied |
| C2ZO-013 | UID0002ZP begins exactly at target end. | 94 | bytes/xrefs/current page | D39 verify-only | already-present | already-present |
| C2ZO-014 | UID0002A1 begins at `0x0069ba30`, has zero bytes and no refs. | 94 | MCP bytes/xrefs | D36 | incorporate | applied |
| C2ZO-015 | UID0001PY predecessor ends exactly at target start. | 94 | adjacent exact page/current B002 evidence | D40 verify-only | already-present | already-present |
| C2ZO-016 | Exactly nine live target xrefs exist. | 94 | MCP xrefs_to | D1/D2 | incorporate | applied |
| C2ZO-017 | Outer constructor has publish/fallback pair at `0x545f03/0x545f0a`. | 94 | decompile/xrefs | D1/D2/D14 | incorporate | applied |
| C2ZO-018 | Standalone constructor has publish/fallback pair at `0x5462e1/0x5462e8`. | 94 | decompile/xrefs | D1/D2/D4 | incorporate | applied |
| C2ZO-019 | Ordinary destructor clear is at `0x54648d`. | 94 | decompile/xrefs | D1/D2/D5 | incorporate | applied |
| C2ZO-020 | Flying completion reads/uses global at `0x546dbc/0x546dd2`. | 94 | decompile/xrefs | D1/D2/D22 | incorporate | applied |
| C2ZO-021 | EH clear helper store is at `0x546e80`. | 94 | exact helper/xrefs | D30 | incorporate | applied |
| C2ZO-022 | Scalar wrapper clear is at `0x547054`. | 94 | decompile/xrefs | D31 | incorporate | applied |
| C2ZO-023 | ParcelPane directly derives Pane and Singleton<ParcelPane>. | 94 | RTTI/PMD/store timing | D3/D26/D27 | incorporate | applied |
| C2ZO-024 | Singleton PMD is `+0xf8`, `pdisp=-1`, `vdisp=0`, attr `0x40`. | 94 | RTTI bytes | D3/D26 | incorporate | applied |
| C2ZO-025 | Singleton base is empty-base optimized. | 94 | PMD plus first field overlap | D3/D26 | incorporate | applied |
| C2ZO-026 | Constructor source initializes Singleton base, not global manually. | 94 | adjusted-null store lowering | D4 | reject-stale | applied |
| C2ZO-027 | Ordinary destructor omits manual global clear. | 94 | reverse base destruction order | D5 | reject-stale | applied |
| C2ZO-028 | Clear helper is constructor-unwind compiler funclet. | 94 | EH xrefs/no ordinary route | D30 | incorporate | applied |
| C2ZO-029 | Parcel scalar wrapper is compiler output. | 94 | vtable/thunk/delete flags | D31 | incorporate | applied |
| C2ZO-030 | Parcel class exact size is `0x124`. | 94 | outer child allocation | D3/D26 | incorporate | applied |
| C2ZO-031 | Parcel fields at `+0xf8..+0x121` retain accepted meanings. | 94 | all method accesses | D3/D26 | incorporate | applied |
| C2ZO-032 | ParcelButtonState is byte-sized values idle/hover/pressed/animating `0/1/2/3`. | 93 | mouse/timer/frame resolver | D3/D26 | incorporate | applied |
| C2ZO-033 | No explicit ParcelPane padding member is needed. | 94 | natural alignment to 0x124 | D3/D26 | reject-invalid | applied |
| C2ZO-034 | ParcelPane class declaration is destination-ready. | 93 | complete methods/layout/access route | D3 formal | incorporate | applied |
| C2ZO-035 | Private FinishFlyingParcelAnimation helper is source-legal integration. | 92 | access rules and observed inline body | D3 formal/D22 | incorporate | applied |
| C2ZO-036 | FlyingParcelPane friendship is narrower than public fields/getters. | 92 | source-shape ranking | D3/D18 | incorporate | applied |
| C2ZO-037 | Parcel constructor score/position becomes `92/94`, 20. | 94 | complete exact source | D4 | incorporate | applied |
| C2ZO-038 | Parcel destructor score/position becomes `92/94`, 30. | 94 | ordinary/compiler split | D5 | incorporate | applied |
| C2ZO-039 | Setter score/position becomes `92/94`, 40. | 94 | three callers/full body | D6 | incorporate | applied |
| C2ZO-040 | Key handler score/position becomes `91/93`, 50. | 93 | exact vtable/event behavior | D7 | incorporate | applied |
| C2ZO-041 | Mouse handler score/position becomes `92/93`, 60 and uses C++03 NULL. | 93 | full event flow | D8 | incorporate | applied |
| C2ZO-042 | Timer handler score/position becomes `92/94`, 70. | 94 | vtable/body/state | D9 | incorporate | applied |
| C2ZO-043 | Paint score/position becomes `92/93`, 80. | 93 | resources/render flow | D10 | incorporate | applied |
| C2ZO-044 | Animation helper score/position becomes `92/94`, 90. | 94 | exact state transitions | D11 | incorporate | applied |
| C2ZO-045 | Frame resolver score/position becomes `92/94`, 100. | 94 | exact frame map | D12 | incorporate | applied |
| C2ZO-046 | ParcelIconPane directly derives Pane and Singleton<ParcelIconPane>. | 94 | accepted RTTI/PMD evidence | D13/D26 | already-present | already-present |
| C2ZO-047 | ParcelIconPane complete size is `0x104`. | 94 | allocation/scalar size | D13/D26 | already-present | already-present |
| C2ZO-048 | ParcelIconPane `+0x100` remains inferred uninitialized inactive int. | 92 | exhaustive no-use evidence | D13/D26 | already-present | already-present |
| C2ZO-049 | Raw helper range/hash are exact. | 94 | disasm/get_bytes/hash | D16 | incorporate | applied |
| C2ZO-050 | Raw helper has thiscall one-payload ABI and false return. | 94 | 71 instructions/retn4 | D16 | incorporate | applied |
| C2ZO-051 | Raw helper has no opcode gate. | 94 | instruction inventory | D16 | incorporate | applied |
| C2ZO-052 | Raw helper has no direct xref/VA/RVA/rel32 route. | 94 | bounded negative scans | D16 | incorporate | applied |
| C2ZO-053 | Raw helper is source method retained out of line and inlined into callback. | 92 | exact body equivalence/optimizer shape | D13/D16/D17 | incorporate | applied |
| C2ZO-054 | Best inferred helper name is UpdateParcelCounts. | 91 | role and project naming | D13/D16 | incorporate | applied |
| C2ZO-055 | Callback becomes thin opcode gate/call source. | 92 | inlined raw-body relationship | D17 | incorporate | applied |
| C2ZO-056 | Icon class position is 20; methods 20/30/40/50. | 93 | source legality/order | D13-D17 | incorporate | applied |
| C2ZO-057 | Icon ctor becomes `92/94`, position 20. | 94 | full source/direct base | D14 | incorporate | applied |
| C2ZO-058 | Icon dtor retains `92/94`, gains position 30. | 94 | accepted exact source | D15 | incorporate | applied |
| C2ZO-059 | Raw helper becomes `92/93`, emitter UID0000A5, position 40. | 93 | source-route closure | D16 | incorporate | applied |
| C2ZO-060 | Callback becomes `92/93`, position 50. | 93 | source-route closure | D17 | incorporate | applied |
| C2ZO-061 | FlyingParcelPane is implementation-private Pane-derived class. | 94 | source cluster/RTTI/layout | D18 | incorporate | applied |
| C2ZO-062 | Flying exact derived fields are `+0xf8..+0x100`. | 94 | constructor/start/step/draw/dtor | D18/D26 | incorporate | applied |
| C2ZO-063 | Flying uses natural alignment before pointer; no padding field. | 94 | x86 layout | D18/D26 | reject-invalid | applied |
| C2ZO-064 | Flying class declaration is destination-ready. | 93 | complete children/access route | D18 formal | incorporate | applied |
| C2ZO-065 | Flying ctor becomes `92/94`, position 20. | 94 | complete body | D19 | incorporate | applied |
| C2ZO-066 | Flying ordinary dtor becomes `92/94`, position 30. | 94 | raw body/scalar parity | D20 | incorporate | applied |
| C2ZO-067 | StartAnimation becomes `92/93`, position 40, C++03 NULL. | 93 | exact source body | D21 | incorporate | applied |
| C2ZO-068 | AnimateStep becomes `92/93`, position 50, private-helper call. | 93 | exact behavior/source legality | D22 | incorporate | applied |
| C2ZO-069 | Draw becomes `92/93`, position 60. | 93 | exact resources/render flow | D23 | incorporate | applied |
| C2ZO-070 | Flying scalar wrapper becomes false/no-owner/no-emitter/blank at `92/94`. | 94 | ABI wrapper proof | D24 | incorporate | applied |
| C2ZO-071 | Parcel source file becomes `92/93`. | 93 | full coherent module | D25 | incorporate | applied |
| C2ZO-072 | Layout support becomes `92/94`, false/non-emitting/blank. | 94 | declarations own fields | D26 | incorporate | applied |
| C2ZO-073 | Vtable-family support becomes `92/94`, false/non-emitting/blank. | 94 | compiler regenerates vtables | D27 | incorporate | applied |
| C2ZO-074 | Exact vtable-data page becomes `92/94`, false/non-emitting/blank. | 94 | source-declared/generated-binary | D28 | incorporate | applied |
| C2ZO-075 | Executable aggregate becomes `92/94`, remains false/blank. | 94 | complete child inventory | D29 | incorporate | applied |
| C2ZO-076 | Parcel clear helper becomes `92/94`, remains false/blank. | 94 | exact EH proof | D30 | incorporate | applied |
| C2ZO-077 | Parcel scalar wrapper becomes `92/94`, remains false/blank. | 94 | exact ABI proof | D31 | incorporate | applied |
| C2ZO-078 | Mixed data aggregate becomes `92/94`, remains false split index. | 94 | exact children/zero bytes | D35 | incorporate | applied |
| C2ZO-079 | g_pParcelIconPane global becomes `92/94`, position 40. | 94 | direct Singleton lifecycle | D33 | incorporate | applied |
| C2ZO-080 | UID0002W9 becomes `92/94`, semantic owner UID0000RX, false/no-emitter/blank. | 94 | zero physical storage/one definition | D34 | incorporate | applied |
| C2ZO-081 | Icon physical bytes are four zeros. | 94 | valid MCP get_bytes | D34 | incorporate | applied |
| C2ZO-082 | Icon global has six direct xrefs including one UI teardown read. | 94 | MCP xrefs_to | D33/D34 | incorporate | applied |
| C2ZO-083 | Icon clear helper remains compiler/EH no-code and reaches `92/94`. | 94 | accepted helper evidence | D37 | incorporate | applied |
| C2ZO-084 | Adjustor-thunk aggregate remains compiler no-code and reaches `92/94`. | 94 | exact thunk inventory | D38 | incorporate | applied |
| C2ZO-085 | ParcelIcon scalar wrapper remains accepted `92/94` false/no-code. | 94 | executed UID0001EO | verify-only | already-present | already-present |
| C2ZO-086 | Flying raw lifecycle aggregate remains false and reaches `92/94`. | 94 | exact split children | D41 | incorporate | applied |
| C2ZO-087 | Generated output must contain each of three classes once. | 94 | one source module | final readback | incorporate | applied |
| C2ZO-088 | Generated output must contain 4 Icon, 9 Parcel, and 5 Flying source bodies once each. | 94 | source inventory | final readback | incorporate | applied |
| C2ZO-089 | Generated output must contain two singleton definitions once each. | 94 | one-definition plan | final readback | incorporate | applied |
| C2ZO-090 | Generated output must omit physical target/icon markers. | 94 | false/no-emitter disposition | final readback | incorporate | applied |
| C2ZO-091 | Generated output must omit layout/vtable/aggregate/compiler markers. | 94 | false/no-emitter disposition | final readback | incorporate | applied |
| C2ZO-092 | Generated output must not emit manual global publish/clear statements. | 94 | Singleton direct bases | final readback | incorporate | applied |
| C2ZO-093 | Pre-callback generated command 16132 is evidence-time, not current authority. | 94 | header/readback | report/generated history | historicalize | applied |
| C2ZO-094 | The callback's exact 38-row manual handoff was required and was later supervisor-applied and validated. | 94 | six coverage reads plus supervisor commands 16365-16371 | manual section | historicalize | applied |
| C2ZO-095 | No validator-owned tracker text is manually edited. | 94 | workflow rule | manual/follow-up | not-applicable | excluded-with-reason |
| C2ZO-096 | Existing resource/global dependencies remain unchanged. | 93 | bounded support audit | verify-only dependencies | already-present | already-present |
| C2ZO-097 | B002-owned UID0001PY remains protected and unedited by B001. | 94 | current coordination state | D40 verify-only | not-applicable | excluded-with-reason |
| C2ZO-098 | Wave2/Wave3 conclusions are rejected as authority. | 94 | current workflow | all historical sections | reject-stale | applied |
| C2ZO-099 | Scoped validators and final waited refresh are callback-only. | 94 | report-only boundary | Validator Results/checklist | not-applicable | applied |
| C2ZO-100 | B001 performs no execute/lifecycle/move/archive action. | 94 | role boundary | Changed Files/Follow-Up | not-applicable | excluded-with-reason |

### Callback Verification Notes

| Claim ID | Final state | Destination-specific callback proof |
| --- | --- | --- |
| C2ZO-001 | applied | D1 SHA256 `FC0F1A0CDCE0DAADD3B9213BF558318AC5C4893D82536851104C9E1AF58AE790` (validator `000000016167` exit 0/ok:1) Claim verified: Target range is exactly `[0x0069ba28,0x0069ba2c)`. |
| C2ZO-002 | applied | D1 SHA256 `FC0F1A0CDCE0DAADD3B9213BF558318AC5C4893D82536851104C9E1AF58AE790` (validator `000000016167` exit 0/ok:1) Claim verified: Exact target payload is four zeros, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. |
| C2ZO-003 | applied | D1 SHA256 `FC0F1A0CDCE0DAADD3B9213BF558318AC5C4893D82536851104C9E1AF58AE790` (validator `000000016167` exit 0/ok:1) Claim verified: Target is virtual `.data` tail with no raw-file backing. |
| C2ZO-004 | applied | D1 SHA256 `FC0F1A0CDCE0DAADD3B9213BF558318AC5C4893D82536851104C9E1AF58AE790` (validator `000000016167` exit 0/ok:1); D2 SHA256 `BCE398FC76AE6A74E00A7417038214ED8FBAECE79396BC5726546B464A8C4B23` (validator `000000016168` exit 0/ok:1); D3 SHA256 `72AC588D76D9036D481D70CC19BE09C310C13D08BD4D740A347DCF483275ED88` (validator `000000016169` exit 0/ok:1) Claim verified: Source type is `ParcelPane *`. |
| C2ZO-005 | already-present | D1 SHA256 `FC0F1A0CDCE0DAADD3B9213BF558318AC5C4893D82536851104C9E1AF58AE790` (validator `000000016167` exit 0/ok:1); D2 SHA256 `BCE398FC76AE6A74E00A7417038214ED8FBAECE79396BC5726546B464A8C4B23` (validator `000000016168` exit 0/ok:1) Claim verified: Source-facing name is `g_pParcelPane`. |
| C2ZO-006 | applied | D1 SHA256 `FC0F1A0CDCE0DAADD3B9213BF558318AC5C4893D82536851104C9E1AF58AE790` (validator `000000016167` exit 0/ok:1); D35 SHA256 `A04BE87C25D3E9F46A28DC7A0D4AA7C614B5D3554238170205CE7AA8A8E773EC` (validator `000000016241` exit 0/ok:1) Claim verified: Historical `0xffffffff` target initializer is stale. |
| C2ZO-007 | applied | D1 SHA256 `FC0F1A0CDCE0DAADD3B9213BF558318AC5C4893D82536851104C9E1AF58AE790` (validator `000000016167` exit 0/ok:1) Claim verified: UID0002ZO is physical storage, not an independent source definition. |
| C2ZO-008 | applied | D2 SHA256 `BCE398FC76AE6A74E00A7417038214ED8FBAECE79396BC5726546B464A8C4B23` (validator `000000016168` exit 0/ok:1) Claim verified: UID0000RY is the sole semantic source global. |
| C2ZO-009 | applied | D1 SHA256 `FC0F1A0CDCE0DAADD3B9213BF558318AC5C4893D82536851104C9E1AF58AE790` (validator `000000016167` exit 0/ok:1) Claim verified: Target owner becomes semantic UID0000RY. |
| C2ZO-010 | applied | D1 SHA256 `FC0F1A0CDCE0DAADD3B9213BF558318AC5C4893D82536851104C9E1AF58AE790` (validator `000000016167` exit 0/ok:1) Claim verified: Target becomes false/non-emitting/blank formal. |
| C2ZO-011 | already-present | D1 SHA256 `FC0F1A0CDCE0DAADD3B9213BF558318AC5C4893D82536851104C9E1AF58AE790` (validator `000000016167` exit 0/ok:1) Claim verified: Target retains `Nested:4` as first UID0002A0 child. |
| C2ZO-012 | applied | D35 SHA256 `A04BE87C25D3E9F46A28DC7A0D4AA7C614B5D3554238170205CE7AA8A8E773EC` (validator `000000016241` exit 0/ok:1) Claim verified: UID0002A0 remains false split index over two exact dwords. |
| C2ZO-013 | already-present | Historical protected B001 checkpoint D39 SHA256 `6AE27F3408441A2015F9DFBFF522CB2875BBB6445F60AF2FBD76D57BA3DBB6E8`, 8,572/84; current external B005 completion SHA256 `D1FB8382F6FD3767306DB71ABAF3EDA9F2C1EE4B48724B894F4709852D4B1A9D`, 9,097/89. Both begin at `0x0069ba2c`; the current page remains loader-zero physical backing, and B001 made no D39 edit. Claim verified: UID0002ZP begins exactly at target end. |
| C2ZO-014 | applied | D36 SHA256 `E58F886E3816687DBDC50837FF806C8B6083849110231A2C307B4D78FF11C014` (validator `000000016242` exit 0/ok:1) Claim verified: UID0002A1 begins at `0x0069ba30`, has zero bytes and no refs. |
| C2ZO-015 | already-present | D40 SHA256 `800D080E300E186E4A5170D9A71BB03220E0E3B92DCF934E3713A059CDD882A6` (protected verify-only; concurrent B002 union) Claim verified: UID0001PY predecessor ends exactly at target start. |
| C2ZO-016 | applied | D1 SHA256 `FC0F1A0CDCE0DAADD3B9213BF558318AC5C4893D82536851104C9E1AF58AE790` (validator `000000016167` exit 0/ok:1); D2 SHA256 `BCE398FC76AE6A74E00A7417038214ED8FBAECE79396BC5726546B464A8C4B23` (validator `000000016168` exit 0/ok:1) Claim verified: Exactly nine live target xrefs exist. |
| C2ZO-017 | applied | D1 SHA256 `FC0F1A0CDCE0DAADD3B9213BF558318AC5C4893D82536851104C9E1AF58AE790` (validator `000000016167` exit 0/ok:1); D2 SHA256 `BCE398FC76AE6A74E00A7417038214ED8FBAECE79396BC5726546B464A8C4B23` (validator `000000016168` exit 0/ok:1); D14 SHA256 `6D4105FF45B1CE70493C2D775737BB6278BE3A51B5DCD2A2C533A662964BEA59` (validator `000000016196` exit 0/ok:1) Claim verified: Outer constructor has publish/fallback pair at `0x545f03/0x545f0a`. |
| C2ZO-018 | applied | D1 SHA256 `FC0F1A0CDCE0DAADD3B9213BF558318AC5C4893D82536851104C9E1AF58AE790` (validator `000000016167` exit 0/ok:1); D2 SHA256 `BCE398FC76AE6A74E00A7417038214ED8FBAECE79396BC5726546B464A8C4B23` (validator `000000016168` exit 0/ok:1); D4 SHA256 `A06D5BB99A32BB8D1F78BC1B5654D65B7CA6FF4B1A4B97091D3565D228CEC75B` (validators `000000016172` and corrective `000000016270`, exit 0/ok:1) Claim verified: Standalone constructor has publish/fallback pair at `0x5462e1/0x5462e8`. |
| C2ZO-019 | applied | D1 SHA256 `FC0F1A0CDCE0DAADD3B9213BF558318AC5C4893D82536851104C9E1AF58AE790` (validator `000000016167` exit 0/ok:1); D2 SHA256 `BCE398FC76AE6A74E00A7417038214ED8FBAECE79396BC5726546B464A8C4B23` (validator `000000016168` exit 0/ok:1); D5 SHA256 `264FBEF684674FB0D199D516D1C63772D41F681AFB95E186A39B0C9E5DE42CE7` (validator `000000016176` exit 0/ok:1) Claim verified: Ordinary destructor clear is at `0x54648d`. |
| C2ZO-020 | applied | D1 SHA256 `FC0F1A0CDCE0DAADD3B9213BF558318AC5C4893D82536851104C9E1AF58AE790` (validator `000000016167` exit 0/ok:1); D2 SHA256 `BCE398FC76AE6A74E00A7417038214ED8FBAECE79396BC5726546B464A8C4B23` (validator `000000016168` exit 0/ok:1); D22 SHA256 `A6C78A51B9E7F2F71D9ABDE3831C650993BF80074745ED2E504ED61564F22234` (validator `000000016219` exit 0/ok:1) Claim verified: Flying completion reads/uses global at `0x546dbc/0x546dd2`. |
| C2ZO-021 | applied | D30 SHA256 `0C7FF33F086DB7DF66645FC2AEA37E8314E8592071FDF32F17F8CFA85C44E8D4` (validator `000000016235` exit 0/ok:1) Claim verified: EH clear helper store is at `0x546e80`. |
| C2ZO-022 | applied | D31 SHA256 `944FE7F34B92E7C9BD638A63DA7E502504BCE2C47B1F03B107BDB38FAFEB66D9` (validator `000000016236` exit 0/ok:1) Claim verified: Scalar wrapper clear is at `0x547054`. |
| C2ZO-023 | applied | D3 SHA256 `72AC588D76D9036D481D70CC19BE09C310C13D08BD4D740A347DCF483275ED88` (validator `000000016169` exit 0/ok:1); D26 SHA256 `6C36405AAC6638AFCAC1EB5677914F846B91526770401EA6E983CEF005BDFA31` (validator `000000016230` exit 0/ok:1); D27 SHA256 `22EE82C7FD934B5CA7DB60671A58BA1FBB9CC4FEE8A095E6EB7BBA2473C62366` (validator `000000016232` exit 0/ok:1) Claim verified: ParcelPane directly derives Pane and Singleton<ParcelPane>. |
| C2ZO-024 | applied | D3 SHA256 `72AC588D76D9036D481D70CC19BE09C310C13D08BD4D740A347DCF483275ED88` (validator `000000016169` exit 0/ok:1); D26 SHA256 `6C36405AAC6638AFCAC1EB5677914F846B91526770401EA6E983CEF005BDFA31` (validator `000000016230` exit 0/ok:1) Claim verified: Singleton PMD is `+0xf8`, `pdisp=-1`, `vdisp=0`, attr `0x40`. |
| C2ZO-025 | applied | D3 SHA256 `72AC588D76D9036D481D70CC19BE09C310C13D08BD4D740A347DCF483275ED88` (validator `000000016169` exit 0/ok:1); D26 SHA256 `6C36405AAC6638AFCAC1EB5677914F846B91526770401EA6E983CEF005BDFA31` (validator `000000016230` exit 0/ok:1) Claim verified: Singleton base is empty-base optimized. |
| C2ZO-026 | applied | D4 SHA256 `A06D5BB99A32BB8D1F78BC1B5654D65B7CA6FF4B1A4B97091D3565D228CEC75B` (corrective validator `000000016270` exit 0/ok:1) exactly matches the accepted formal and contains zero `g_pParcelPane = this` statements. Claim verified: Constructor source initializes Singleton base, not global manually. |
| C2ZO-027 | applied | D5 SHA256 `264FBEF684674FB0D199D516D1C63772D41F681AFB95E186A39B0C9E5DE42CE7` (validator `000000016176` exit 0/ok:1) Claim verified: Ordinary destructor omits manual global clear. |
| C2ZO-028 | applied | D30 SHA256 `0C7FF33F086DB7DF66645FC2AEA37E8314E8592071FDF32F17F8CFA85C44E8D4` (validator `000000016235` exit 0/ok:1) Claim verified: Clear helper is constructor-unwind compiler funclet. |
| C2ZO-029 | applied | D31 SHA256 `944FE7F34B92E7C9BD638A63DA7E502504BCE2C47B1F03B107BDB38FAFEB66D9` (validator `000000016236` exit 0/ok:1) Claim verified: Parcel scalar wrapper is compiler output. |
| C2ZO-030 | applied | D3 SHA256 `72AC588D76D9036D481D70CC19BE09C310C13D08BD4D740A347DCF483275ED88` (validator `000000016169` exit 0/ok:1); D26 SHA256 `6C36405AAC6638AFCAC1EB5677914F846B91526770401EA6E983CEF005BDFA31` (validator `000000016230` exit 0/ok:1) Claim verified: Parcel class exact size is `0x124`. |
| C2ZO-031 | applied | D3 SHA256 `72AC588D76D9036D481D70CC19BE09C310C13D08BD4D740A347DCF483275ED88` (validator `000000016169` exit 0/ok:1); D26 SHA256 `6C36405AAC6638AFCAC1EB5677914F846B91526770401EA6E983CEF005BDFA31` (validator `000000016230` exit 0/ok:1) Claim verified: Parcel fields at `+0xf8..+0x121` retain accepted meanings. |
| C2ZO-032 | applied | D3 SHA256 `72AC588D76D9036D481D70CC19BE09C310C13D08BD4D740A347DCF483275ED88` (validator `000000016169` exit 0/ok:1); D26 SHA256 `6C36405AAC6638AFCAC1EB5677914F846B91526770401EA6E983CEF005BDFA31` (validator `000000016230` exit 0/ok:1) Claim verified: ParcelButtonState is byte-sized values idle/hover/pressed/animating `0/1/2/3`. |
| C2ZO-033 | applied | D3 SHA256 `72AC588D76D9036D481D70CC19BE09C310C13D08BD4D740A347DCF483275ED88` (validator `000000016169` exit 0/ok:1); D26 SHA256 `6C36405AAC6638AFCAC1EB5677914F846B91526770401EA6E983CEF005BDFA31` (validator `000000016230` exit 0/ok:1) Claim verified: No explicit ParcelPane padding member is needed. |
| C2ZO-034 | applied | D3 SHA256 `72AC588D76D9036D481D70CC19BE09C310C13D08BD4D740A347DCF483275ED88` (validator `000000016169` exit 0/ok:1) Claim verified: ParcelPane class declaration is destination-ready. |
| C2ZO-035 | applied | D3 SHA256 `72AC588D76D9036D481D70CC19BE09C310C13D08BD4D740A347DCF483275ED88` (validator `000000016169` exit 0/ok:1); D22 SHA256 `A6C78A51B9E7F2F71D9ABDE3831C650993BF80074745ED2E504ED61564F22234` (validator `000000016219` exit 0/ok:1) Claim verified: Private FinishFlyingParcelAnimation helper is source-legal integration. |
| C2ZO-036 | applied | D3 SHA256 `72AC588D76D9036D481D70CC19BE09C310C13D08BD4D740A347DCF483275ED88` (validator `000000016169` exit 0/ok:1); D18 SHA256 `A236565DF928A186109DF7C76468B1BB606ED199D88EF7EC910CEE1FAC513471` (validator `000000016212` exit 0/ok:1) Claim verified: FlyingParcelPane friendship is narrower than public fields/getters. |
| C2ZO-037 | applied | D4 SHA256 `A06D5BB99A32BB8D1F78BC1B5654D65B7CA6FF4B1A4B97091D3565D228CEC75B` (validators 16172/16270, exit 0/ok:1) readbacks exact `92/94`, position 20, and accepted formal. Claim verified: Parcel constructor score/position becomes `92/94`, 20. |
| C2ZO-038 | applied | D5 SHA256 `264FBEF684674FB0D199D516D1C63772D41F681AFB95E186A39B0C9E5DE42CE7` (validator `000000016176` exit 0/ok:1) Claim verified: Parcel destructor score/position becomes `92/94`, 30. |
| C2ZO-039 | applied | D6 SHA256 `C7AA8D6852EF6545351C9B89939451105FB3D34A727EFA4FC96AE2BC3FEAEFF2` (validator `000000016177` exit 0/ok:1) Claim verified: Setter score/position becomes `92/94`, 40. |
| C2ZO-040 | applied | D7 SHA256 `738B116CE95AE755BCBD8908CC9D758826326297E755A92266B7D1DAAEE144E8` (validator `000000016179` exit 0/ok:1) Claim verified: Key handler score/position becomes `91/93`, 50. |
| C2ZO-041 | applied | D8 SHA256 `5186FCC7A4F4375457EBDD60087B6BF85C578F56F548A86F29EC647613065DFE` (corrective validator `000000016271` exit 0/ok:1) exactly matches the accepted C++03 managed block at `92/93`, position 60. Claim verified: Mouse handler score/position becomes `92/93`, 60 and uses C++03 NULL. |
| C2ZO-042 | applied | D9 SHA256 `570C8195CAD9CFB80C9CB2268CB2AD34C7E6B7EE8DE59B306B3C7DA01A3D6474` (validator `000000016181` exit 0/ok:1) Claim verified: Timer handler score/position becomes `92/94`, 70. |
| C2ZO-043 | applied | D10 SHA256 `0721E7986BAA4AFD056D9B85C0F2705E94740E4B68191EA84BD9055584241252` (validator `000000016184` exit 0/ok:1) Claim verified: Paint score/position becomes `92/93`, 80. |
| C2ZO-044 | applied | D11 SHA256 `707E7CCD242DD7FF92964061AE1986CA8018F59FD123D14355375B4CA8893580` (validator `000000016186` exit 0/ok:1) Claim verified: Animation helper score/position becomes `92/94`, 90. |
| C2ZO-045 | applied | D12 SHA256 `821C8C290A00044566C59192BED408C8AF2B11C8031FB1C64AAD8A0302C2DAD3` (validator `000000016187` exit 0/ok:1) Claim verified: Frame resolver score/position becomes `92/94`, 100. |
| C2ZO-046 | already-present | D13 SHA256 `737D17498BB5B06AF3A89DBBA07A812B96680CFC59B5063978580E904F655A9B` (validator `000000016194` exit 0/ok:1); D26 SHA256 `6C36405AAC6638AFCAC1EB5677914F846B91526770401EA6E983CEF005BDFA31` (validator `000000016230` exit 0/ok:1) Claim verified: ParcelIconPane directly derives Pane and Singleton<ParcelIconPane>. |
| C2ZO-047 | already-present | D13 SHA256 `737D17498BB5B06AF3A89DBBA07A812B96680CFC59B5063978580E904F655A9B` (validator `000000016194` exit 0/ok:1); D26 SHA256 `6C36405AAC6638AFCAC1EB5677914F846B91526770401EA6E983CEF005BDFA31` (validator `000000016230` exit 0/ok:1) Claim verified: ParcelIconPane complete size is `0x104`. |
| C2ZO-048 | already-present | D13 SHA256 `737D17498BB5B06AF3A89DBBA07A812B96680CFC59B5063978580E904F655A9B` (validator `000000016194` exit 0/ok:1); D26 SHA256 `6C36405AAC6638AFCAC1EB5677914F846B91526770401EA6E983CEF005BDFA31` (validator `000000016230` exit 0/ok:1) Claim verified: ParcelIconPane `+0x100` remains inferred uninitialized inactive int. |
| C2ZO-049 | applied | D16 SHA256 `E4345CE59BEB26EFC68FC487CC7263EA4A677D023A87F1D257095727C0E6AACC` (validator `000000016201` exit 0/ok:1) Claim verified: Raw helper range/hash are exact. |
| C2ZO-050 | applied | D16 SHA256 `E4345CE59BEB26EFC68FC487CC7263EA4A677D023A87F1D257095727C0E6AACC` (validator `000000016201` exit 0/ok:1) Claim verified: Raw helper has thiscall one-payload ABI and false return. |
| C2ZO-051 | applied | D16 SHA256 `E4345CE59BEB26EFC68FC487CC7263EA4A677D023A87F1D257095727C0E6AACC` (validator `000000016201` exit 0/ok:1) Claim verified: Raw helper has no opcode gate. |
| C2ZO-052 | applied | D16 SHA256 `E4345CE59BEB26EFC68FC487CC7263EA4A677D023A87F1D257095727C0E6AACC` (validator `000000016201` exit 0/ok:1) Claim verified: Raw helper has no direct xref/VA/RVA/rel32 route. |
| C2ZO-053 | applied | D13 SHA256 `737D17498BB5B06AF3A89DBBA07A812B96680CFC59B5063978580E904F655A9B` (validator `000000016194` exit 0/ok:1); D16 SHA256 `E4345CE59BEB26EFC68FC487CC7263EA4A677D023A87F1D257095727C0E6AACC` (validator `000000016201` exit 0/ok:1); D17 SHA256 `815E62703CD9ED30A5991073F2A580689F43802A180C90900BD2482F098ECAA8` (validator `000000016202` exit 0/ok:1) Claim verified: Raw helper is source method retained out of line and inlined into callback. |
| C2ZO-054 | applied | D13 SHA256 `737D17498BB5B06AF3A89DBBA07A812B96680CFC59B5063978580E904F655A9B` (validator `000000016194` exit 0/ok:1); D16 SHA256 `E4345CE59BEB26EFC68FC487CC7263EA4A677D023A87F1D257095727C0E6AACC` (validator `000000016201` exit 0/ok:1) Claim verified: Best inferred helper name is UpdateParcelCounts. |
| C2ZO-055 | applied | D17 SHA256 `815E62703CD9ED30A5991073F2A580689F43802A180C90900BD2482F098ECAA8` (validator `000000016202` exit 0/ok:1) Claim verified: Callback becomes thin opcode gate/call source. |
| C2ZO-056 | applied | D13 SHA256 `737D17498BB5B06AF3A89DBBA07A812B96680CFC59B5063978580E904F655A9B` (validator 16194), D14 `6D4105FF45B1CE70493C2D775737BB6278BE3A51B5DCD2A2C533A662964BEA59` (16196), D15 `D3BDDF095A58FC39B569F9800F71F7533640DF583895655FB90D8D3E11E7F049` (16197), D16 `E4345CE59BEB26EFC68FC487CC7263EA4A677D023A87F1D257095727C0E6AACC` (16201), and D17 `815E62703CD9ED30A5991073F2A580689F43802A180C90900BD2482F098ECAA8` (16202) read back positions `20/20/30/40/50`, all exit 0/ok:1. Claim verified: Icon class position is 20; methods 20/30/40/50. |
| C2ZO-057 | applied | D14 SHA256 `6D4105FF45B1CE70493C2D775737BB6278BE3A51B5DCD2A2C533A662964BEA59` (validator `000000016196` exit 0/ok:1) Claim verified: Icon ctor becomes `92/94`, position 20. |
| C2ZO-058 | applied | D15 SHA256 `D3BDDF095A58FC39B569F9800F71F7533640DF583895655FB90D8D3E11E7F049` (validator `000000016197` exit 0/ok:1) Claim verified: Icon dtor retains `92/94`, gains position 30. |
| C2ZO-059 | applied | D16 SHA256 `E4345CE59BEB26EFC68FC487CC7263EA4A677D023A87F1D257095727C0E6AACC` (validator `000000016201` exit 0/ok:1) Claim verified: Raw helper becomes `92/93`, emitter UID0000A5, position 40. |
| C2ZO-060 | applied | D17 SHA256 `815E62703CD9ED30A5991073F2A580689F43802A180C90900BD2482F098ECAA8` (validator `000000016202` exit 0/ok:1) Claim verified: Callback becomes `92/93`, position 50. |
| C2ZO-061 | applied | D18 SHA256 `A236565DF928A186109DF7C76468B1BB606ED199D88EF7EC910CEE1FAC513471` (validator `000000016212` exit 0/ok:1) Claim verified: FlyingParcelPane is implementation-private Pane-derived class. |
| C2ZO-062 | applied | D18 SHA256 `A236565DF928A186109DF7C76468B1BB606ED199D88EF7EC910CEE1FAC513471` (validator `000000016212` exit 0/ok:1); D26 SHA256 `6C36405AAC6638AFCAC1EB5677914F846B91526770401EA6E983CEF005BDFA31` (validator `000000016230` exit 0/ok:1) Claim verified: Flying exact derived fields are `+0xf8..+0x100`. |
| C2ZO-063 | applied | D18 SHA256 `A236565DF928A186109DF7C76468B1BB606ED199D88EF7EC910CEE1FAC513471` (validator `000000016212` exit 0/ok:1); D26 SHA256 `6C36405AAC6638AFCAC1EB5677914F846B91526770401EA6E983CEF005BDFA31` (validator `000000016230` exit 0/ok:1) Claim verified: Flying uses natural alignment before pointer; no padding field. |
| C2ZO-064 | applied | D18 SHA256 `A236565DF928A186109DF7C76468B1BB606ED199D88EF7EC910CEE1FAC513471` (validator `000000016212` exit 0/ok:1) Claim verified: Flying class declaration is destination-ready. |
| C2ZO-065 | applied | D19 SHA256 `2B045787C88CFD81F08C6186FC3A308489A67BBA06F6078057DCD51C061CD6FC` (validator `000000016214` exit 0/ok:1) Claim verified: Flying ctor becomes `92/94`, position 20. |
| C2ZO-066 | applied | D20 SHA256 `C1A6A5E9723AAC57DBD323086A7EB9E54FCF914F570CDF2FF85F32EC3894A530` (validator `000000016216` exit 0/ok:1) Claim verified: Flying ordinary dtor becomes `92/94`, position 30. |
| C2ZO-067 | applied | D21 SHA256 `3EE191F590DFDCD99BE0A648BDCA7DAE1E9DD91C2647C61D1CC03351C7679E8F` (validator `000000016218` exit 0/ok:1) Claim verified: StartAnimation becomes `92/93`, position 40, C++03 NULL. |
| C2ZO-068 | applied | D22 SHA256 `A6C78A51B9E7F2F71D9ABDE3831C650993BF80074745ED2E504ED61564F22234` (validator `000000016219` exit 0/ok:1) Claim verified: AnimateStep becomes `92/93`, position 50, private-helper call. |
| C2ZO-069 | applied | D23 SHA256 `69E100E3FCB1C0C65005B0697084337F5AAAF0579F86812A72FAEBB791F1207C` (validator `000000016221` exit 0/ok:1) Claim verified: Draw becomes `92/93`, position 60. |
| C2ZO-070 | applied | D24 SHA256 `661198045C8952B291E2480E2383296021B071AC889C61AC02124076689E800E` (validator `000000016225` exit 0/ok:1) Claim verified: Flying scalar wrapper becomes false/no-owner/no-emitter/blank at `92/94`. |
| C2ZO-071 | applied | D25 SHA256 `BD0E17988F0634A5158CB5B207725D36889156C937EA89FB905C1B8D09442740` (validator `000000016229` exit 0/ok:1) Claim verified: Parcel source file becomes `92/93`. |
| C2ZO-072 | applied | D26 SHA256 `6C36405AAC6638AFCAC1EB5677914F846B91526770401EA6E983CEF005BDFA31` (validator `000000016230` exit 0/ok:1) Claim verified: Layout support becomes `92/94`, false/non-emitting/blank. |
| C2ZO-073 | applied | D27 SHA256 `22EE82C7FD934B5CA7DB60671A58BA1FBB9CC4FEE8A095E6EB7BBA2473C62366` (validator `000000016232` exit 0/ok:1) Claim verified: Vtable-family support becomes `92/94`, false/non-emitting/blank. |
| C2ZO-074 | applied | D28 SHA256 `628FEDF6A45A36B5A7FB7D52FD0A76AF6D29E2A5FE5CE31EC8C6CFDB75481C92` (validator `000000016233` exit 0/ok:1) Claim verified: Exact vtable-data page becomes `92/94`, false/non-emitting/blank. |
| C2ZO-075 | applied | D29 SHA256 `213A35CDE030500BFC4D37F13B53B824280C7136D70DC83516B55A540688E5D5` (validator `000000016234` exit 0/ok:1) Claim verified: Executable aggregate becomes `92/94`, remains false/blank. |
| C2ZO-076 | applied | D30 SHA256 `0C7FF33F086DB7DF66645FC2AEA37E8314E8592071FDF32F17F8CFA85C44E8D4` (validator `000000016235` exit 0/ok:1) Claim verified: Parcel clear helper becomes `92/94`, remains false/blank. |
| C2ZO-077 | applied | D31 SHA256 `944FE7F34B92E7C9BD638A63DA7E502504BCE2C47B1F03B107BDB38FAFEB66D9` (validator `000000016236` exit 0/ok:1) Claim verified: Parcel scalar wrapper becomes `92/94`, remains false/blank. |
| C2ZO-078 | applied | D35 SHA256 `A04BE87C25D3E9F46A28DC7A0D4AA7C614B5D3554238170205CE7AA8A8E773EC` (validator `000000016241` exit 0/ok:1) Claim verified: Mixed data aggregate becomes `92/94`, remains false split index. |
| C2ZO-079 | applied | D33 SHA256 `9C0DA5767E02AE35D4DA87A7B1D176BF2ADC73F49081E5655012EBAD89717373` (validator `000000016239` exit 0/ok:1) Claim verified: g_pParcelIconPane global becomes `92/94`, position 40. |
| C2ZO-080 | applied | D34 SHA256 `33F1E9C7BDF0DDD9A62C26FD19564408C2810A5E517EF5F46F749090F9CF5F02` (validator `000000016240` exit 0/ok:1) Claim verified: UID0002W9 becomes `92/94`, semantic owner UID0000RX, false/no-emitter/blank. |
| C2ZO-081 | applied | D34 SHA256 `33F1E9C7BDF0DDD9A62C26FD19564408C2810A5E517EF5F46F749090F9CF5F02` (validator `000000016240` exit 0/ok:1) Claim verified: Icon physical bytes are four zeros. |
| C2ZO-082 | applied | D33 SHA256 `9C0DA5767E02AE35D4DA87A7B1D176BF2ADC73F49081E5655012EBAD89717373` (validator `000000016239` exit 0/ok:1); D34 SHA256 `33F1E9C7BDF0DDD9A62C26FD19564408C2810A5E517EF5F46F749090F9CF5F02` (validator `000000016240` exit 0/ok:1) Claim verified: Icon global has six direct xrefs including one UI teardown read. |
| C2ZO-083 | applied | D37 SHA256 `2499AC6C98BA69B74795AB6CA37C2B059F13A2C8687425A4F194D0A75268D8A0` (validator `000000016243` exit 0/ok:1) Claim verified: Icon clear helper remains compiler/EH no-code and reaches `92/94`. |
| C2ZO-084 | applied | D38 SHA256 `DCB08EF6725CEEC6E79C196C567D2A0EB858FE824CED001002647402CFFDF85F` (validator `000000016244` exit 0/ok:1) Claim verified: Adjustor-thunk aggregate remains compiler no-code and reaches `92/94`. |
| C2ZO-085 | already-present | Current callback readback and report section prove the accepted disposition without an unauthorized file mutation. Claim verified: ParcelIcon scalar wrapper remains accepted `92/94` false/no-code. |
| C2ZO-086 | applied | D41 SHA256 `7FCC357DBF18FD44D48659C79FCDEB17B6D38314F7EE286C8063A3CC2A9D55CB` (validator `000000016245` exit 0/ok:1) Claim verified: Flying raw lifecycle aggregate remains false and reaches `92/94`. |
| C2ZO-087 | applied | B001 checkpoint command `000000016272` passed; current external waited command `000000016371`/SHA256 `BD29AB0038F89A0E2734D34C17AA199E6528D70A7DFDBF00D64231BAC1E2E2AB` retains one complete definition of each class. Claim verified: Generated output must contain each of three classes once. |
| C2ZO-088 | applied | Current external command `000000016371`, SHA256 `BD29AB0038F89A0E2734D34C17AA199E6528D70A7DFDBF00D64231BAC1E2E2AB`, retains exactly 4 Icon, 9 Parcel, and 5 Flying source definitions, matching B001 command 16272 and external command 16340 semantically. Claim verified: Generated output must contain 4 Icon, 9 Parcel, and 5 Flying source bodies once each. |
| C2ZO-089 | applied | Current external command `000000016371`, SHA256 `BD29AB0038F89A0E2734D34C17AA199E6528D70A7DFDBF00D64231BAC1E2E2AB`, retains both singleton definitions once. Claim verified: Generated output must contain two singleton definitions once each. |
| C2ZO-090 | applied | Current external command `000000016371`, SHA256 `BD29AB0038F89A0E2734D34C17AA199E6528D70A7DFDBF00D64231BAC1E2E2AB`, retains zero UID0002ZO/UID0002W9 physical markers. Claim verified: Generated output must omit physical target/icon markers. |
| C2ZO-091 | applied | Current external command `000000016371`, SHA256 `BD29AB0038F89A0E2734D34C17AA199E6528D70A7DFDBF00D64231BAC1E2E2AB`, retains zero layout/vtable/aggregate/compiler markers, zero Empty Emitter Markers, and zero decompiler labels. Claim verified: Generated output must omit layout/vtable/aggregate/compiler markers. |
| C2ZO-092 | applied | Current external command `000000016371`, SHA256 `BD29AB0038F89A0E2734D34C17AA199E6528D70A7DFDBF00D64231BAC1E2E2AB`, retains zero handwritten Singleton publication/clear or ABI-lowering bodies. Claim verified: Generated output must not emit manual global publish/clear statements. |
| C2ZO-093 | applied | Command `000000016132` is pre-callback historical evidence; commands `000000016246` and `000000016248` are intermediate callback snapshots; command `000000016272` is B001's accepted checkpoint; external commands `000000016340` and `000000016371` preserve its semantics, while tracker hashes remain command-scoped evidence-time only. Claim verified: pre-callback generated command 16132 is evidence-time, not current authority. |
| C2ZO-094 | applied | Supervisor commands `000000016365`-`000000016370` applied and validated the exact 38-row handoff, and waited command `000000016371` retained it; all 38 literal rows and their UIDs occur exactly once. B001 edited no coverage file. Claim verified: the formerly required exact manual handoff is externally applied and validated. |
| C2ZO-095 | excluded-with-reason | The six current manual files were reread after command `000000016371`; the exact accepted rows are present once, B001 edited no coverage/tracker file, and all synchronization was supervisor/validator-owned. Claim verified: No validator-owned tracker text is manually edited. |
| C2ZO-096 | already-present | Bounded dependency readback found no accepted contradiction; no dependency page was edited. Claim verified: Existing resource/global dependencies remain unchanged. |
| C2ZO-097 | excluded-with-reason | D40 SHA256 `800D080E300E186E4A5170D9A71BB03220E0E3B92DCF934E3713A059CDD882A6` (protected verify-only; concurrent B002 union). Claim verified: B002-owned UID0001PY remains protected and unedited by B001. |
| C2ZO-098 | applied | Current destination history explicitly labels the rejected Wave2/Wave3/comment-marker assumptions as superseded while retaining their provenance. Claim verified: Wave2/Wave3 conclusions are rejected as authority. |
| C2ZO-099 | applied | Thirty-eight initial scoped ordinary validators passed, the D10 transient command `000000016182` was superseded by successful `000000016184`, D4/D8 exact-formal corrections passed as commands `000000016270`/`000000016271`, and final waited command `000000016272` completed after leases cleared. Claim verified: Scoped validators and final waited refresh are callback-only. |
| C2ZO-100 | excluded-with-reason | B001 changed only the 38 authorized ordinary pages plus this report; no execute/lifecycle/move/archive command was run. Claim verified: B001 performs no execute/lifecycle/move/archive action. |

## Positive Evidence Summary

- Exact live bytes, PE virtual-tail mapping, and payload hash prove null-initialized physical storage.
- Nine exact target xrefs divide cleanly into two publication paths, ordinary clear, Flying consumer reads, EH clear, and scalar-wrapper clear.
- RTTI/PMD plus adjusted-null store timing independently proves direct Singleton source bases and EBO.
- Every ParcelPane field is tied to constructor/setter/input/timer/paint/helper accesses and the exact `0x124` allocation.
- Raw helper and callback have exact behavior identity except the callback's opcode gate, supporting one source helper plus optimized inlining.
- Existing individual method formals already provide behavior-identical source for all other source-bearing ranges.
- Historical command-16132 generated output directly demonstrated the pre-callback routing problem and supplied the precise uniqueness target; B001 command `000000016272` proved that target was met without loss, and later external command `000000016340` reconfirmed identical semantics.

## IDA MCP Facts

- Session `9b0396a3`: active, healthy, analysis/Hex-Rays/strings ready, module NexusTK.exe, image base `0x400000`.
- Executable SHA256: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, 2,679,296 bytes.
- `.text`: RVA `0x1000`, virtual size `0x20b4ac`; `.rdata`: RVA `0x20d000`, virtual size `0x5f0be`; `.data`: RVA `0x26d000`, virtual size `0x2fe24`, raw size `0xd800`, raw-backed end RVA `0x27a800`.
- Target RVA `0x29ba28` is virtual-only `.data`; exact bytes are zero.
- `lookup_funcs`: `0x545e40` size `0x22a`, `0x546290` size `0x1a6`, `0x546440` size `0x6c`, `0x546d70` size `0x7e`, `0x546e80` size `0xb`, `0x547000` size `0xad`; `0x5460f0` is not modeled as a function.
- Parcel RTTI hashes: vtable island `[0x621bb0,0x621d50)` SHA256 `9F2F65BE404E125005F8CB358D18495CC86175D9DBDDBD1C4AE9B3E18CB8847D`; RTTI descriptor island `[0x64dbb8,0x64dc90)` SHA256 `6329A60395F0B275AFCDEB84BBDF7BB11515CB7AE6804D2C9239F2AC552F920D`; type-name island `[0x6786c8,0x67870c)` SHA256 `5DCDC577F7226512C6050639EDC9C9C415BC73367059FD4C9BD0447F24C08DEE`.
- Exact code hashes:

| Range | Role | SHA256 |
| --- | --- | --- |
| `0x545e40-0x54606a` | ParcelIconPane constructor | `1BC94E3D48236A940856A3CF4F50BF7C561525D3395C04A4BE529230B848841C` |
| `0x546070-0x5460e8` | ParcelIconPane ordinary destructor | `1D997FF6B5D62387A76CB96856D84E7D9F8B252F55556900136B8F3A4B110BE5` |
| `0x5460f0-0x5461c0` | raw count helper | `E20711EEBE0A6B2AD37B5AFEED2EB94963A96FE826D70793FCC96D669FC61B8D` |
| `0x5461c0-0x54628d` | packet callback | `92657C7E9D16B0605B6D221F4A02A44DB24AF3CC2D18887809F65D17B74714A1` |
| `0x546290-0x546436` | ParcelPane constructor | `5EA1C0E00D74F95231461414019866BE47726E46F8D7120D3D5B007382D54276` |
| `0x546440-0x5464ac` | ParcelPane ordinary destructor | `F811200FB3F50B17B1CB576492CB99DE67F07AF98B44251913882359F80D2D2F` |
| `0x5464b0-0x546575` | slot-data setter | `6887F71BB5950F9653F0B0CE10BAC85B8E38691D205614190B363E98017BDAEE` |
| `0x5465e0-0x54660a` | key handler | `6CA71D2A0F98001781113802261B50923688236FEA86E5C8DF11C4B4238FEE63` |
| `0x546610-0x546807` | mouse handler | `B3CE1610402B26FD801576525C55C53E6CBB10C06744AE72D532FE383FAFF83C` |
| `0x546810-0x546888` | timer handler | `DD1886FBD87C500A4756B3F887E793D9AFB358138755741BCE3AEF52BB663F0A` |
| `0x546890-0x54696f` | paint | `6A27DF84BDA427AE861567797370A20EE0238ED8D394AF6A5A4FC74354BE7D2` |
| `0x546970-0x5469db` | animation helper | `93CD7FA0DD169BAAE98BD0F213D2AE9A237D18AC951B4E71CF41728DA8AE2075` |
| `0x5469e0-0x546aab` | frame resolver | `934BA77C7194D8394630A3A595020B22F440562950A41F75F491394AD7E13EF6` |
| `0x546ac0-0x546b74` | Flying constructor | `85B07258E260632030D56B1C00C0D8C4D142338313C9374EC09FAE232EEFA7A6` |
| `0x546b80-0x546bb5` | Flying ordinary destructor | `F184575D48893112C5704BEEC8DC5AA0DE71F206EF8BC69FD8650907EB82C9F7` |
| `0x546bc0-0x546d64` | Flying start | `5F2CFC04F1769CDBE3804AB5D046D8BA6FB224169743F23B24B6DFF887824BEB` |
| `0x546d70-0x546dee` | Flying step | `CDB8B07C3072410453377AB81DC3987EE54DCB8020F6791CD2DAAE90726B9A43` |
| `0x546df0-0x546e6b` | Flying draw | `B4642EF28A4690440AFF06053C5831C466707F505BD8268998480C4B5D07FC9C` |
| `0x546e70-0x546e7b` | icon Singleton EH clear | `23C1DD0808977F9A12B81C9C0A87B7DD9C1A14955020733054C377CF39E6E708` |
| `0x546e80-0x546e8b` | parcel Singleton EH clear | `E2E96AF0724C19273F8012198639D0A780DB3CB3B2052111C03F7CB0DCE0EDA2` |
| `0x546e8b-0x546ecd` | adjustor thunks | `0FF6F7EB64236860F06CB896B38713DC3575960AE85B03EED0A9B07081963E8F` |
| `0x546ed0-0x546f37` | Flying scalar wrapper | `D0AEFE3B6A35312C4752DB4726D81273B08256580446C852495C41C96E5EC97D` |
| `0x546f40-0x546ff9` | Icon scalar wrapper | `0C1591EC89D60FD5B8D8F29574E26126965B6B4D81CBF00B89A6479DF3DE6A` |
| `0x547000-0x5470ad` | Parcel scalar wrapper | `CA96ED0FBB80D7C41F03736203892B7C55F8B9199800335867678168804EF38` |
| `0x545e40-0x5470ad` | full executable family | `ADED1BCE084A2A99D32D79FF1555B52235D7C63E6B167F4EF8CE22EA4EF81AF6` |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Recommended Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0069ba28-0x0069ba2c` | UID0002ZO / D1 | physical g_pParcelPane storage | false | UID0000RY semantic | 92/94 | reclassify/no emit |
| source global | UID0000RY / D2 | sole g_pParcelPane definition | true | UID0000MF | 92/94 | emit position 50 |
| class | UID0000A6 / D3 | ParcelPane declaration | true | UID0000MF | 92/94 | complete declaration position 10 |
| `0x545e40-0x54606a` | UID0001EG / D14 | Icon constructor | true | UID0000A5 | 92/94 | emit 20 |
| `0x546070-0x5460e8` | UID0001EI / D15 | Icon ordinary destructor | true | UID0000A5 | 92/94 | emit 30 |
| `0x5460f0-0x5461c0` | UID00043J / D16 | UpdateParcelCounts | true | UID0000A5 | 92/93 | emit 40 |
| `0x5461c0-0x54628d` | UID0001EJ / D17 | OnParcelUpdate | true | UID0000A5 | 92/93 | emit 50 |
| `0x546290-0x546436` | UID0002KB / D4 | Parcel constructor | true | UID0000A6 | 92/94 | emit 20 |
| `0x546440-0x5464ac` | UID0001EK / D5 | Parcel ordinary destructor | true | UID0000A6 | 92/94 | emit 30 |
| `0x5464b0-0x546575` | UID0002KC / D6 | SetParcelSlotData | true | UID0000A6 | 92/94 | emit 40 |
| `0x5465e0-0x54660a` | UID0002KD / D7 | OnKeyDown | true | UID0000A6 | 91/93 | emit 50 |
| `0x546610-0x546807` | UID0002KE / D8 | OnMouseEvent | true | UID0000A6 | 92/93 | emit 60 |
| `0x546810-0x546888` | UID0002KF / D9 | OnTimer | true | UID0000A6 | 92/94 | emit 70 |
| `0x546890-0x54696f` | UID0002KG / D10 | OnPaint | true | UID0000A6 | 92/93 | emit 80 |
| `0x546970-0x5469db` | UID0002KH / D11 | AdvanceButtonAnimation | true | UID0000A6 | 92/94 | emit 90 |
| `0x5469e0-0x546aab` | UID0002KI / D12 | ResolveButtonFrameIndex | true | UID0000A6 | 92/94 | emit 100 |
| `0x546ac0-0x546b74` | UID0002KJ / D19 | Flying constructor | true | UID000058 | 92/94 | emit 20 |
| `0x546b80-0x546bb5` | UID0002R5 / D20 | Flying ordinary destructor | true | UID000058 | 92/94 | emit 30 |
| `0x546bc0-0x546d64` | UID0002R6 / D21 | StartAnimation | true | UID000058 | 92/93 | emit 40 |
| `0x546d70-0x546dee` | UID0002KK / D22 | AnimateStep | true | UID000058 | 92/93 | emit 50 |
| `0x546df0-0x546e6b` | UID0002KL / D23 | DrawParcelOrLetter | true | UID000058 | 92/93 | emit 60 |
| `0x546e70-0x546e7b` | UID0002KM / D37 | icon EH clear | false | none | 92/94 | compiler no-code |
| `0x546e80-0x546e8b` | UID0002KN / D30 | parcel EH clear | false | none | 92/94 | compiler no-code |
| `0x546e8b-0x546ecd` | UID0001EM / D38 | adjustor thunks | false | none | 92/94 | compiler no-code |
| `0x546ed0-0x546f37` | UID0001EN / D24 | Flying scalar wrapper | false | none | 92/94 | compiler no-code |
| `0x546f40-0x546ff9` | UID0001EO / D32 | Icon scalar wrapper | false | none | 92/94 | verify-only; already present |
| `0x547000-0x5470ad` | UID0001EP / D31 | Parcel scalar wrapper | false | none | 92/94 | compiler no-code |
| full executable island | UID0001EH / D29 | source-family index | false | none | 92/94 | non-emitting aggregate |
| raw Flying aggregate | UID0001EL / D41 | split inventory | false | none | 92/94 | non-emitting aggregate |
| class | UID0000A5 / D13 | ParcelIconPane declaration | true | UID0000MF | 92/93 | complete declaration position 20 |
| class | UID000058 / D18 | FlyingParcelPane declaration | true | UID0000MF | 92/93 | complete declaration position 30 |
| file | UID0000MF / D25 | ParcelPane.cpp source root | true | source tree | 92/93 | one coherent module |
| layout | UID0001VI / D26 | layout evidence | false | UID0000MF semantic | 92/94 | blank no-code |
| vtable family | UID0001YE / D27 | vtable evidence | false | UID0000MF semantic | 92/94 | blank no-code |
| `0x621bb0-0x621d50` | UID0002OH / D28 | RTTI/vtable bytes | false | UID0000MF semantic | 92/94 | blank no-code |
| `0x0069b4d0-0x0069b4d4` | UID0002W9 / D34 | physical icon global storage | false | UID0000RX semantic | 92/94 | blank no-code |
| source global | UID0000RX / D33 | sole icon global definition | true | UID0000MF | 92/94 | emit position 40 |
| `0x0069ba28-0x0069ba30` | UID0002A0 / D35 | mixed data split index | false | none | 92/94 | non-emitting |
| `0x0069ba30-0x0069ba34` | UID0002A1 / D36 | zero unreferenced filler | false | none | 92/94 | ignored/no source |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x545f03`, `0x545f0a` | UID0001EG outer constructor | inlined child Singleton publish/null fallback |
| `0x5462e1`, `0x5462e8` | UID0002KB standalone constructor | Singleton publish/null fallback |
| `0x54648d` | UID0001EK ordinary destructor | reverse Singleton-base clear |
| `0x546dbc`, `0x546dd2` | UID0002KK Flying step | global receiver and completion invalidation route |
| `0x546e80` | UID0002KN | constructor/EH Singleton clear |
| `0x547054` | UID0001EP scalar wrapper | inlined Singleton clear |
| `0x4f848c`, `0x4f89f3` | `sub_4F7D10` -> UID0001EG | two `0x104` ParcelIconPane constructions |
| `0x621c10` | vtable -> UID0001EJ | ParcelIconPane secondary callback slot |
| `0x621c3c/90/c0` | ParcelPane vtable views | source virtual declaration route |
| `0x621ccc/d18/d48` | Flying vtable views | source virtual declaration and compiler wrapper route |
| UID00043J | no inbound xref | retained out-of-line method after callback inlining |
| `0x5461b0`, `0x546274`, `0x546dcd` | callers of SetParcelSlotData | raw helper, callback, Flying completion |
| `0x0069b4d0` six refs | UI teardown, ctor pair, dtor, EH clear, scalar clear | complete icon singleton lifetime |
| `0x0069ba2c` five refs | PatchPane2 family | confirms separate successor owner |
| `0x0069ba30` zero refs | none | confirms non-source filler boundary |

## Documentation Evidence And IDA Status

- Same-or-greater current evidence is retained in the implemented ordinary union: all accepted individual source bodies, ParcelIconPane direct-base/size proof, ParcelPane field meanings/frame map, Flying resource and animation behavior, exact padding rows, and PatchPane successor split.
- Historical pre-callback ordinary defects identified during the report-only evidence pass were UID0002ZO physical emission; ParcelPane/Flying comment-only declarations; raw-helper blank source route; manual global publish/clear in Parcel constructor/destructor; Flying sibling direct member access; Flying scalar-wrapper reconstructability; layout/vtable/data comment emission; UID0002W9 physical emission; UID0002A1 `ff` bytes; and stale manual coverage scores/descriptions. The accepted callback repaired and scoped-validated every ordinary/code disposition in that list. The exact manual coverage synchronization was later completed externally by the supervisor under commands `000000016365`-`000000016371`; B001 did not edit coverage.
- Historical generated command `000000016132`, SHA256 `3DC71F686425ACE8766E94AE8DC7528C437025E420DC06AA438C004F519CE2AE`, lacked the ParcelPane declaration and nine bodies, FlyingParcelPane declaration and five bodies, and raw helper, while retaining comment-only physical/layout/vtable markers. Those omissions and markers are evidence-time pre-callback facts, not current output.
- B001 callback closure is historical generated checkpoint command `000000016272`, SHA256 `FA543CE85E2F762B432A7AC20AFFA289CF85B27BD7EB7066F41D009D1A616647`, 17,715 bytes/560 lines. Later read-only external command `000000016340`, SHA256 `A133CE0D58AE211441CED78B828128D8B89BA55115EB812E6F19F980523FC0C1`, 17,715/560, preserves exactly one complete ParcelPane, ParcelIconPane, and FlyingParcelPane class; exactly 9/4/5 corresponding source bodies; both singleton definitions once; exact class/global/child order; zero UID0002ZO/UID0002W9, layout, vtable, aggregate, EH, adjustor, scalar, or Empty Emitter markers; zero duplicate bodies; and zero handwritten Singleton/ABI lowering in method bodies.
- The callback reread and no-loss rebased all destinations before editing, applied the eighteen accepted managed blocks, passed the 38 ordinary scoped validators plus corrective commands `000000016270`/`000000016271`, and completed final waited command `000000016272` after lease release. D1-D38/D40/D41 hashes remain the accepted ordinary authority; D39's historical protected B001 checkpoint and current external B005 hash are both recorded below. Terminal claim proofs and checked callback rows remain current; no future B001 callback action remains.

## Ranked Ownership Analysis

### 1. UID0000RY semantic global under UID0000MF

- Evidence for: exact source definition already exists; all nine references use ParcelPane pointer semantics; file owns the complete family; one-definition policy requires one emitter.
- Evidence against: none material. UID0000RY is a semantic page rather than the physical address page, which is the intended separation.
- Decision: strongest and accepted source owner/emitter route.

### 2. UID0002ZO physical page with semantic owner UID0000RY

- Evidence for: exact address/bytes/range evidence belongs here; semantic owner preserves navigation; modern physical-storage precedents use false/no-emitter with a semantic by-global owner.
- Evidence against: cannot emit without duplicating UID0000RY.
- Decision: detailed evidence page only, false/non-emitting/blank formal.

### 3. Direct file owner UID0000MF on physical target

- Evidence for: current metadata and source module association.
- Evidence against: skips the semantic global layer and currently causes a source marker; file ownership belongs on UID0000RY.
- Decision: reject for target, retain on semantic global.

### 4. ParcelIconPane or FlyingParcelPane consumer ownership

- Evidence for: constructors/destructors/consumer read the slot.
- Evidence against: consumer/lifetime use is not global-definition ownership; the concrete pointer type is ParcelPane.
- Decision: reject.

### Proposed new file/grouping, if applicable

- No new file. UID0000MF `ParcelPane.cpp` is the coherent source root for both globals, three classes, 18 source bodies, resource dependencies, and compiler-generated companions.

## Source Placement

- Project route: `NexusTK/ui/panels/ParcelPane.cpp` under UID0000MF.
- Root order: ParcelPane class 10, ParcelIconPane class 20, FlyingParcelPane class 30, g_pParcelIconPane 40, g_pParcelPane 50.
- Parcel child order: constructor 20, destructor 30, setter 40, key 50, mouse 60, timer 70, paint 80, animation helper 90, frame resolver 100.
- Icon child order: constructor 20, destructor 30, count helper 40, callback 50.
- Flying child order: constructor 20, destructor 30, start 40, step 50, draw 60.
- Rejected placements: by-memory address-shaped source, separate raw-helper file, separate Flying file, MainUiGraph, PatchPane, Pane.cpp, resource module, or vtable/layout source definitions.
- Original header separation is not recoverable, but the single generated translation-unit route is source-legal and behavior complete.

## Range / Split / Padding / Reclassification Analysis

- UID0002A0 remains `[0x0069ba28,0x0069ba30)` with two exact four-byte children. No merge or new UID is needed.
- Hierarchy sequence remains balanced: UID0002A0 `Nested:0`; first child UID0002ZO `Nested:4`; second child UID0002ZP `Nested:0`; following UID0002A1 `Nested:-4` closes to baseline.
- UID0002ZO predecessor UID0001PY ends at `0x0069ba28`; successor UID0002ZP begins at `0x0069ba2c`.
- UID0002A1 at `[0x0069ba30,0x0069ba34)` is also virtual-tail zero storage with no xrefs; its stale initialized-`ff` prose should be corrected, but it remains false/ignored and no source global is created.
- Executable padding remains as currently proven in `by-memory/-ignored.md`; no new ignored interval is required.
- UID0001EH and UID0001EL remain non-emitting indexes; exact child pages remain the source/ABI authorities.

## Negative Evidence Summary

- No target raw bytes exist in the PE file; no `0xffffffff` initializer is supportable.
- No tenth target reference, pointer-table reference, or unrelated consumer was found.
- No `0x0069ba30` xref or source identity was found.
- No raw-helper inbound xref or encoded pointer was found, but exact inline duplication disproves the stronger conclusion that no source method existed.
- No evidence supports manual Singleton publication/clear source statements.
- No evidence supports public ParcelPane fields, invented getters, or source-illegal Flying direct access.
- No evidence supports explicit padding arrays in ParcelPane, ParcelIconPane, or FlyingParcelPane.
- No evidence supports hand-emitting EH clear helpers, scalar wrappers, adjustor thunks, vtables, RTTI, layout markers, aggregate markers, or physical address storage.
- No evidence supports changing resource/global dependencies or PatchPane ownership.
- B001's accepted callback never permitted editing B002-owned UID0001PY; D40 remained protected, verify-only, and unchanged by B001 at its recorded current-union hash.

## IDA Rename / Type / Comment Recommendations

- Source names: retain `g_pParcelPane`, `g_pParcelIconPane`, `ParcelPane`, `ParcelIconPane`, `FlyingParcelPane`, and accepted method/field names.
- New inferred source method: `ParcelIconPane::UpdateParcelCounts(const unsigned char *packet)` for `0x005460f0`.
- New inferred private integration method: `ParcelPane::FinishFlyingParcelAnimation(unsigned char totalCount, unsigned char leftCount, unsigned char rightCount)`; intended inline-only declaration/body.
- Type: both globals are 32-bit pointers to their concrete classes; `ParcelButtonState` remains an unsigned-byte source type with four named values.
- Keep IDA names unchanged in this task. No IDA mutation is requested or permitted.
- Preserve raw `sub_*`/address names only in historical binary evidence, never in final source C++.

## First-Draft C++ Recommendation

The following 18 destination-specific managed blocks are the accepted and applied C++ changes. Existing method blocks not reproduced here remain unchanged at exact current content. Current destination readback confirms all eighteen blocks match their accepted formal shapes.

### D1 UID0002ZO physical target: exact blank no-code block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D2 UID0000RY g_pParcelPane sole definition

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ParcelPane *g_pParcelPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D3 UID0000A6 ParcelPane declaration

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FlyingParcelPane;
struct PaneKeyEvent;
struct PaneMouseEvent;

typedef unsigned char ParcelButtonState;

enum ParcelButtonStateValue
{
    kParcelButtonIdle = 0,
    kParcelButtonHover = 1,
    kParcelButtonPressed = 2,
    kParcelButtonAnimating = 3
};

class ParcelPane;
extern ParcelPane *g_pParcelPane;

class ParcelPane : public Pane,
                   public Singleton<ParcelPane>
{
public:
    ParcelPane();
    virtual ~ParcelPane();

    void SetParcelSlotData(unsigned char totalCount,
                           unsigned char leftCount,
                           unsigned char rightCount);

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent& event);
    virtual bool OnKeyDown(const PaneKeyEvent *event);
    virtual bool OnTimer(int timerId, int userData1, int userData2);
    virtual void OnPaint();
    virtual void AdvanceButtonAnimation(ParcelButtonState *state,
                                        signed char *frame,
                                        bool rightSide);
    virtual int ResolveButtonFrameIndex(const ParcelButtonState *state,
                                        unsigned char slotCount,
                                        bool rightSide) const;

private:
    friend class FlyingParcelPane;

    void FinishFlyingParcelAnimation(unsigned char totalCount,
                                     unsigned char leftCount,
                                     unsigned char rightCount)
    {
        SetParcelSlotData(totalCount, leftCount, rightCount);
        m_rightSlotActionEnabled = true;
        InvalidateRect(&m_bounds);
    }

    unsigned char m_totalParcelCount;
    unsigned char m_leftParcelCount;
    unsigned char m_rightParcelCount;
    bool m_rightSlotActionEnabled;
    ParcelButtonState m_leftButtonState;
    ParcelButtonState m_rightButtonState;
    signed char m_leftAnimationFrame;
    signed char m_rightAnimationFrame;
    RectBounds m_leftButtonRect;
    RectBounds m_rightButtonRect;
    bool m_leftSlotAcknowledged;
    bool m_rightSlotAcknowledged;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D4 UID0002KB ParcelPane constructor

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ParcelPane::ParcelPane()
    : Pane(1),
      Singleton<ParcelPane>(),
      m_totalParcelCount(0),
      m_leftParcelCount(0),
      m_rightParcelCount(0),
      m_rightSlotActionEnabled(true),
      m_leftButtonState(kParcelButtonIdle),
      m_rightButtonState(kParcelButtonIdle),
      m_leftAnimationFrame(-3),
      m_rightAnimationFrame(0),
      m_leftSlotAcknowledged(false),
      m_rightSlotAcknowledged(false)
{
    SetRect(&m_leftButtonRect, 0, 0, 30, 25);
    SetRect(&m_rightButtonRect, 31, 0, 62, 25);

    SetParcelSlotData(0, 0, 0);
    SetPaneOrder(NULL, g_pBackPane);
    m_timerHandler.ScheduleTimer(0, 100, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D5 UID0001EK ParcelPane ordinary destructor

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ParcelPane::~ParcelPane()
{
    RemoveFromLayer();
    UnregisterEventHandler();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D8 UID0002KE ParcelPane OnMouseEvent C++03 normalization

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ParcelPane::OnMouseEvent(const PaneMouseEvent& event)
{
    const int x = event.x;
    const int y = event.y;

    switch (event.type) {
    case kPaneMouseMove:
        if (!PointInRect(x, y, &m_bounds)) {
            if (m_leftButtonState != kParcelButtonAnimating)
                m_leftButtonState = kParcelButtonIdle;
            if (m_rightButtonState != kParcelButtonAnimating)
                m_rightButtonState = kParcelButtonIdle;
            return false;
        }

        if (PointInRect(x, y, &m_rightButtonRect)) {
            if (m_leftButtonState != kParcelButtonAnimating)
                m_leftButtonState = kParcelButtonIdle;
            if (m_rightButtonState != kParcelButtonPressed)
                m_rightButtonState = kParcelButtonHover;
        }

        if (PointInRect(x, y, &m_leftButtonRect)) {
            if (m_rightButtonState != kParcelButtonAnimating)
                m_rightButtonState = kParcelButtonIdle;
            if (m_leftButtonState != kParcelButtonPressed)
                m_leftButtonState = kParcelButtonHover;
        }
        return true;

    case kPaneMouseDown:
        if (!PointInRect(x, y, &m_bounds))
            return false;
        if (PointInRect(x, y, &m_rightButtonRect))
            m_rightButtonState = kParcelButtonPressed;
        if (PointInRect(x, y, &m_leftButtonRect))
            m_leftButtonState = kParcelButtonPressed;
        return true;

    case kPaneMouseUp:
        if (!PointInRect(x, y, &m_bounds))
            return false;

        m_leftButtonState = kParcelButtonIdle;
        m_rightButtonState = kParcelButtonIdle;

        if (PointInRect(x, y, &m_leftButtonRect)) {
            m_leftButtonState = kParcelButtonHover;
            if (m_leftParcelCount != 0) {
                unsigned char packet = 0x41;
                g_packetSender->QueueAndSendPacket(&packet, 1);
                m_leftSlotAcknowledged = true;
            }
        }

        if (PointInRect(x, y, &m_rightButtonRect)) {
            m_rightButtonState = kParcelButtonHover;
            if (m_rightSlotActionEnabled && g_pBulletinSession == NULL) {
                new BulletinSession(1, 0, true);
                m_rightSlotAcknowledged = true;
            }
        }
        return true;

    default:
        return false;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D13 UID0000A5 ParcelIconPane declaration

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ParcelIconPane;
class ParcelPane;
struct PaneEvent;

extern ParcelIconPane *g_pParcelIconPane;

class ParcelIconPane : public Pane,
                       public Singleton<ParcelIconPane>
{
public:
    ParcelIconPane();
    virtual ~ParcelIconPane();

protected:
    virtual bool OnParcelUpdate(const PaneEvent *event);

private:
    bool UpdateParcelCounts(const unsigned char *packet);

    unsigned char m_totalParcelCount;
    unsigned char m_leftParcelCount;
    unsigned char m_rightParcelCount;
    ParcelPane *m_parcelPane;
    int m_notificationState;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D16 UID00043J UpdateParcelCounts body

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ParcelIconPane::UpdateParcelCounts(const unsigned char *packet)
{
    unsigned char flags;
    unsigned short countOffset;
    unsigned char packedCount;
    unsigned char leftCount;
    unsigned char rightCount;
    unsigned char totalCount;
    unsigned char previousTotal;

    flags = packet[1];
    countOffset = (flags & 0x40) ? 31 : 2;
    if (flags & 0x20)
        countOffset += 8;
    if (flags & 0x10)
        countOffset += 9;
    if (flags & 0x08)
        countOffset += 5;

    packedCount = packet[countOffset];
    leftCount = packedCount & 0x0f;
    rightCount = packedCount >> 4;
    totalCount = leftCount + rightCount;

    previousTotal = m_totalParcelCount;
    m_totalParcelCount = totalCount;

    if (previousTotal > totalCount ||
        m_leftParcelCount < leftCount ||
        m_rightParcelCount < rightCount) {
        m_leftParcelCount = leftCount;
        m_rightParcelCount = rightCount;
        m_parcelPane->SetParcelSlotData(totalCount, leftCount, rightCount);
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D17 UID0001EJ OnParcelUpdate wrapper body

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ParcelIconPane::OnParcelUpdate(const PaneEvent *event)
{
    if (event->packetData[0] == 8)
        return UpdateParcelCounts(event->packetData);

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D18 UID000058 FlyingParcelPane declaration

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Layer;

class FlyingParcelPane : public Pane
{
public:
    FlyingParcelPane();
    virtual ~FlyingParcelPane();

    void StartAnimation(unsigned char parcelCountOrState,
                        unsigned char leftSlot,
                        unsigned char rightSlot,
                        bool isParcel);

protected:
    virtual bool AnimateStep(int timerId, int userData1, int userData2);
    virtual void DrawParcelOrLetter();

private:
    unsigned char m_animationFrame;
    unsigned char m_parcelCountOrState;
    unsigned char m_rightSlot;
    unsigned char m_leftSlot;
    bool m_isParcel;
    Layer *m_animationLayer;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D21 UID0002R6 StartAnimation C++03 normalization

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void FlyingParcelPane::StartAnimation(unsigned char parcelCountOrState,
                                      unsigned char leftSlot,
                                      unsigned char rightSlot,
                                      bool isParcel)
{
    RectBounds animationRect;

    if (g_useEpfAssets == 1) {
        g_pSoundManager->PlaySample(200, 100);
        g_pScreenPane->SetLayerFrame(m_animationLayer, 0);

        m_leftSlot = leftSlot;
        m_rightSlot = rightSlot;
        m_parcelCountOrState = parcelCountOrState;
        m_isParcel = isParcel;
        m_animationFrame = 0;

        if (isParcel)
            SetRect(&animationRect, 630, 730, 659, 755);
        else
            SetRect(&animationRect, 667, 730, 698, 747);

        RemoveFromLayer();
        AddToLayer(&animationRect, 0, NULL, m_animationLayer);
        m_origin.y += 30;
        InvalidateRect(&m_bounds);
        m_timerHandler.ScheduleTimer(0, 100, 0, 0);
        return;
    }

    g_pScreenPane->SetLayerFrame(m_animationLayer, 0);

    m_leftSlot = leftSlot;
    m_rightSlot = rightSlot;
    m_parcelCountOrState = parcelCountOrState;
    m_isParcel = isParcel;
    m_animationFrame = 0;

    const int displaySlot = parcelCountOrState <= 4 ? parcelCountOrState : 4;
    SetRect(&animationRect,
            397 + displaySlot * 11,
            4,
            419 + displaySlot * 11,
            26);

    RemoveFromLayer();
    AddToLayer(&animationRect, 0, NULL, m_animationLayer);
    InvalidateRect(&m_bounds);
    m_timerHandler.ScheduleTimer(0, 10, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D22 UID0002KK AnimateStep legal access body

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool FlyingParcelPane::AnimateStep(int, int, int)
{
    if (m_animationFrame < 30) {
        --m_origin.y;
        InvalidateRect(&m_bounds);
        ++m_animationFrame;
        m_timerHandler.ScheduleTimer(0, 10, 0, 0);
        return true;
    }

    RemoveFromLayer();
    g_pScreenPane->RemoveLayer(m_animationLayer);
    g_pParcelPane->FinishFlyingParcelAnimation(m_parcelCountOrState,
                                               m_leftSlot,
                                               m_rightSlot);
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D24 UID0001EN Flying scalar wrapper: exact blank no-code block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D26 UID0001VI layout support: exact blank no-code block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D27 UID0001YE vtable family: exact blank no-code block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D28 UID0002OH vtable data: exact blank no-code block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D33 UID0000RX g_pParcelIconPane sole definition

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ParcelIconPane *g_pParcelIconPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### D34 UID0002W9 physical icon target: exact blank no-code block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Behavior preservation: the source blocks keep all observed packet offsets, nibble arithmetic, asymmetric update condition, frame maps, mouse behavior, timer values, resources, coordinates, sound, layer order, and return values. They replace only compiler mechanics, duplicate markers, modern `nullptr`, and source-illegal cross-class access.

## Final Recommendation

- C2ZO-001 through C2ZO-100 and Destinations D1-D41 were applied or verified in the accepted bounded implementation callback.
- Make UID0002ZO and UID0002W9 detailed false/non-emitting physical-storage pages; keep UID0000RY and UID0000RX as the sole definitions.
- Complete the three class declarations and all 18 source-authored bodies in one ParcelPane module.
- Preserve all compiler/data/index pages as evidence but make duplicate marker destinations false/non-emitting/blank where listed.
- Preserve the current B002-owned UID0001PY union, B005-completed UID0002ZP successor, and all unrelated dependencies; B001 made no edit to D39 or D40.
- No new UID, split, rename, file, or ignored interval is required.

## Recommended Target Doc Changes

- Applied and validated: the recommendations below describe durable current target truth.
- D1 `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md`: set `92/94`, owner UID0000RY, false, no emitter/position, blank formal, retain `Nested:4`; add PE mapping, exact hash, all nine refs, physical/semantic distinction, source/compiler disposition, historical `ff` rejection, boundaries, generated exclusion, and score rationale.
- Preserve exact address, current zero bytes, UID, split-index relationship, and every valid lifecycle fact.

## Recommended Support Doc Changes

- Applied or verify-only as specified: D2-D38 and D41 match these dispositions; D32/D39/D40 were read-only verified by B001, and later B005 D39 completion preserves the accepted boundary/storage disposition.
- D2 `by-global/g_pParcelPane.md`: `92/94`, owner/emitter UID0000MF, position 50, exact definition unchanged; add complete lifecycle/Singleton/physical-child/source-order evidence.
- D3 `by-class/ParcelPane.md`: `92/94`, position 10, exact class block; preserve method behavior and add direct Singleton, friend/private-helper, layout, source legality, and no-manual-global history.
- D4-D12: apply exact scores/positions above; replace only D4/D5/D8 formals as shown and preserve same-or-greater behavior on all nine pages.
- D13 `by-class/ParcelIconPane.md`: `92/93`, position 20, add private helper declaration; preserve direct bases, inactive `m_notificationState`, and unrelated content.
- D14-D17: apply exact scores/positions; preserve ctor/dtor; insert D16 helper body and replace D17 with thin gate/call wrapper while retaining exact inlined-binary evidence.
- D18 `by-class/FlyingParcelPane.md`: `92/93`, position 30, exact class declaration with natural alignment and no explicit pad.
- D19-D23: exact scores/positions; preserve ctor/dtor/draw; normalize D21 NULL and D22 private-helper call without changing binary behavior.
- D24: `92/94`, owner none, false, no emitter/position, blank formal; retain scalar-wrapper evidence and ordinary-destructor route.
- D25 `by-file/ParcelPane.md`: `92/93`; synchronize complete module inventory, positions, duplicate-free generated expectations, and historical omissions.
- D26-D28: `92/94`, false/non-emitting/blank formals, retain semantic UID0000MF route and all layout/vtable/RTTI evidence.
- D29/D41 aggregates: `92/94`, false/non-emitting/blank, complete child inventory and historical omission closure.
- D30/D31/D37/D38 compiler destinations: `92/94`, none/false/no-emitter/blank; retain exact hashes/routes and ordinary-source causes.
- D32 UID0001EO ParcelIconPane scalar wrapper remains the accepted `92/94`, none/false/no-emitter/blank-formal compiler disposition and is verify-only in this callback.
- D35 mixed storage index: `92/94`, none/false/no-emitter/blank, exact two-child zero-fill history.
- D33 `by-global/g_pParcelIconPane.md`: `92/94`, position 40, exact definition unchanged; synchronize direct Singleton lifetime.
- D34 `by-memory/0x0069b4d0-0x0069b4d4.g_pParcelIconPane.md`: `92/94`, semantic owner UID0000RX, false/no-emitter/blank, exact zero bytes and six refs.
- D36 `by-memory/0x0069ba30-0x0069ba34.UnreferencedInitializedDword_69BA30.md`: `92/94`, retain none/false/blank and `Nested:-4`; replace `ff`/initialized wording with exact virtual-tail zero/no-xref filler evidence.
- D39 UID0002ZP and D40 UID0001PY were verify-only/protected in B001's callback. D39 later advanced externally through B005 to SHA256 `D1FB8382F6FD3767306DB71ABAF3EDA9F2C1EE4B48724B894F4709852D4B1A9D`, 9,097/89, while preserving exact `0x0069ba2c` start, loader-zero physical backing, and non-emitting semantics; D40 remains B002-owned.
- Preserve external Pane, Layer, EPFTileContext, ScreenPane, SoundManager, EventMan, Socket, BulletinSession, cleanup queue, resource, and global docs unchanged unless an exact current contradiction blocks these accepted formals.

## Score And Metadata Recommendation

- Target: `86/90`, file-owned true/emitting/comment marker -> `92/94`, semantic UID0000RY, false/no-emitter/blank, `Nested:4` retained.
- Semantic globals: UID0000RY and UID0000RX -> `92/94`, owner/emitter UID0000MF, positions 50/40.
- Classes: ParcelPane `92/94` pos10; ParcelIconPane `92/93` pos20; FlyingParcelPane `92/93` pos30.
- Source methods: exact values/positions in Function / Child Inventory.
- Compiler/data/index pages: `92/94` false/non-emitting/blank as listed.
- Score blockers closed:
  - initializer/raw mapping: exact PE/bytes/hash;
  - ownership/one-definition: semantic by-global versus physical by-memory;
  - reference inventory: complete MCP/raw scan;
  - class declarations: complete destination blocks;
  - Singleton lifecycle: RTTI/PMD/EBO and source-lowering decision;
  - raw helper: exact source method/inlining disposition;
  - Flying access: source-legal private helper/friend route;
  - compiler split: exact no-code pages;
  - generated output: exact uniqueness/order/absence plan.
- Scores remain below 95 because original private lexical spellings, precise header exposure, and optimizer provenance are inferred rather than symbol-proven.

## Open Questions With Attempted Resolution

- Was the target initialized to `0xffffffff`? Resolved no: virtual-only tail plus live zero bytes.
- Which page emits the global? Resolved UID0000RY only; UID0002ZO is physical evidence.
- Was publication handwritten? Resolved no: direct Singleton base/PMD/EBO/store order.
- Is the raw helper dead? Resolved as retained out-of-line source method whose callback call was inlined; absence of direct xrefs is preserved as negative evidence.
- Can Flying legally touch ParcelPane state? Resolved with a private inline ParcelPane method callable by friend FlyingParcelPane.
- Are padding members needed? Resolved no; natural x86 alignment produces exact offsets/sizes.
- Is a new source file needed? Resolved no; one ParcelPane module is coherent and source-legal.
- Remaining lexical uncertainty: exact original names for `UpdateParcelCounts`, `FinishFlyingParcelAnimation`, and `m_notificationState`. The selected names are ranked, behavior-specific, and safe; uncertainty caps confidence but does not block source.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The whole-root manual hashes are command-scoped evidence-time snapshots, not indefinite-current requirements. B001's post-callback read recorded by-memory SHA256 `5C6C89F1D5F04CC2C9B557FCB2D8624DD2C7845704282C80BAF7EF008693FFB8`, 1,939,707 bytes/4,500 lines; by-class `F2BCF2B86E4EC742CBAA60F1E81C13543B4BC47356929A00C02F5F4A922F9E4D`, 250,872/623; by-file `A64A0250CAF3FEFE1FA6D39E3218B6BAE7A035C595B07381906ABE6252A82504`, 148,527/316; by-global `E163655B4F551E6A01B03DF0AF732CCEA2BF73153D79A57A8BDA34AAAB9C584C`, 98,529/217; by-struct `676BAA47DB24054110C95507785BD5147C979A99D7A3C444CBAAF77B547ACB8F`, 57,412/137; and by-vtable `F6A29DFEF6A3139F16DB1889A2261FFBF289ADE2D4AB389926A16F4223D3272D`, 66,097/144. A later bounded read after external command 16340 observed by-memory `70752950CCBC249C54AF73D4E9B4B3D3C111EC7B2F3C656FE69A088CDF28A352`, 1,950,308/4,521; by-class `FD57AEA8C9277B8E2DCB57E6B024D3F8A96465FB5F0875C54DAE9AD775E395B7`, 252,156/623; by-file `F24B17418C7889C74DC1BA4A20B169BCFBEC38A367D5F7AD59771CA9DAF54272`, 149,999/317; by-global `E163655B4F551E6A01B03DF0AF732CCEA2BF73153D79A57A8BDA34AAAB9C584C`, 98,529/217; by-struct `2E3B0FF38B5006A552F027D5ED444D6ABEEB52794982E7BC66873592478F67D4`, 57,808/137; and by-vtable `F6A29DFEF6A3139F16DB1889A2261FFBF289ADE2D4AB389926A16F4223D3272D`, 66,097/144. All earlier hashes retained in this paragraph and report history are historical evidence-time snapshots.

The supervisor later applied the exact handoff below without B001 coverage edits. Commands `000000016365`-`000000016370` validated all 38 literal rows, and final waited command `000000016371` retained them. Current post-16371 checkpoints are: by-memory SHA256 `85AD82FC4D1E579255B06B4EA26813C8651A0AA24E6BB8D0D26D92AEC3E3CBF7`, 1,955,223 bytes/4,528 lines; by-class `B9A93C85C1CE2DDE5C3F76C2FC6985F2C0DBE6D37384A1F9601CCB9BC83B7570`, 252,231/623; by-file `35EA6391EF8C89256572B6CFCDD81256A6DAA7D5C14545B8AFFC1EB94336DDC3`, 149,968/317; by-global `F79F04B44824C59A4CDC8EEA145C6CDBD2564571754C1FFE61B2471F07E5FEBF`, 97,902/217; by-struct `375E0919656011E6C2B892884D912C77B12AEC462347F43CE052263C2B1FA78A`, 57,600/137; and by-vtable `18E9DC82B5F7267E847AD4B64065FBCF24DC82034F125971C29F07ECAFE71C18`, 65,863/144. Readback confirms 30 by-memory rows including newly inserted UID00043J, three by-class rows, one by-file row, two by-global rows, one by-struct row, and one by-vtable row; all 38 rows are present exactly once and each listed UID occurs exactly once. The literal blocks below are retained unchanged as the exact applied handoff and no longer direct a pending edit.

### by-memory exact applied handoff

Supervisor command `000000016365` applied the following no-loss rows in address order while preserving all intervening padding and unrelated rows; this block is retained verbatim as readback evidence.

```text
    - [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md) 0x00545e40-0x005470ad | class-cluster aggregate | ParcelNotificationPanes : non-reconstructable : 92% : very-strong : Fully inventoried non-emitting ParcelIconPane/ParcelPane/FlyingParcelPane executable-family index with exact child ranges and hashes, complete source declarations and ordinary bodies in child/class destinations, raw UpdateParcelCounts helper plus inlined callback relationship, direct Singleton source lifetimes, compiler EH/thunk/scalar-wrapper separation, exact padding and PatchPane boundary, and no aggregate source emission.
    - [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md) 0x00545e40-0x0054606a | constructor | ParcelIconPane constructor : reconstructable : 92% : very-strong : Exact 0x22a source-ready constructor with two MainUiGraph callers allocating 0x104 bytes, direct Pane and empty Singleton<ParcelIconPane> base initialization, implicit singleton publication, three count bytes, intentionally uninitialized inactive final int, child ParcelPane allocation at +0xfc, exact class/file route, and no handwritten vptr/EH or inlined child internals.
    - [UID:0001EI][0x00546070-0x005460e8.ParcelIconPaneDestructor](by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md) 0x00546070-0x005460e8 | destructor | ParcelIconPane ordinary destructor : reconstructable : 92% : very-strong : Source-ready ordinary destructor queues child dismissal and unregisters events; implicit reverse Singleton<ParcelIconPane> destruction clears g_pParcelIconPane before Pane teardown, while vptr restoration, base teardown, and scalar deletion remain compiler output.
    - [UID:00043J][0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper](by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md) 0x005460f0-0x005461c0 | class method | ParcelIconPane UpdateParcelCounts : reconstructable : 92% : very-strong : Exact 0xd0 one-argument thiscall helper decodes flag-selected parcel count offset, splits nibbles, updates total/left/right owner bytes, conditionally forwards to the child ParcelPane, returns false, and has no direct xref because its OnParcelUpdate call is compiler-inlined while the out-of-line source method remains emitted.
    - [UID:0001EJ][0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback](by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md) 0x005461c0-0x0054628d | class callback | ParcelIconPane OnParcelUpdate : reconstructable : 92% : very-strong : Secondary-vtable callback gates packet opcode 8 then calls UpdateParcelCounts; the compiler-inlined helper body exactly preserves flag-dependent offset arithmetic, nibble counts, asymmetric update condition, child forwarding, and false return.
    - [UID:0002KB][0x00546290-0x00546436.ParcelPaneConstructor](by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md) 0x00546290-0x00546436 | constructor | ParcelPane constructor : reconstructable : 92% : very-strong : Source-ready Pane plus Singleton<ParcelPane> constructor initializes exact count/state/frame/ack/rect state, performs zero-slot reset, pane order, and 100 ms timer; publication/null fallback, vptrs, cookie, and EH are compiler lowering rather than manual global source.
    - [UID:0001EK][0x00546440-0x005464ac.ParcelPaneDestructor](by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md) 0x00546440-0x005464ac | destructor | ParcelPane ordinary destructor : reconstructable : 92% : very-strong : Source-ready derived body removes the pane from its layer and unregisters events; reverse Singleton<ParcelPane> destruction clears g_pParcelPane before implicit Pane teardown, with vptr restoration and scalar-delete mechanics excluded.
    - [UID:0002KC][0x005464b0-0x00546575.ParcelPaneSetParcelSlotData](by-memory/0x005464b0-0x00546575.ParcelPaneSetParcelSlotData.md) 0x005464b0-0x00546575 | class method | ParcelPane SetParcelSlotData : reconstructable : 92% : very-strong : Exact total/left/right update, changed-slot acknowledgment clears, empty-slot state reset without frame clear, fixed 630/726/698/751 layer bounds, conditional reattach, and invalidation with three proven callers.
    - [UID:0002KD][0x005465e0-0x0054660a.ParcelPaneOnKeyDown](by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md) 0x005465e0-0x0054660a | class method | ParcelPane OnKeyDown : reconstructable : 91% : very-strong : Exact secondary key callback checks event kind 8, passes key/state bytes to EventMan::TranslateEventKey, ignores its return, and always returns false; vtable-only route and inferred event field spellings are documented.
    - [UID:0002KE][0x00546610-0x00546807.ParcelPaneOnMouseEvent](by-memory/0x00546610-0x00546807.ParcelPaneOnMouseEvent.md) 0x00546610-0x00546807 | class method | ParcelPane OnMouseEvent : reconstructable : 92% : very-strong : Source-ready move/down/up handling, exact hit tests and state transitions, left packet byte 0x41 through g_packetSender, right BulletinSession(1,0,true) under action/session gate, acknowledgment writes, C++03 NULL spelling, and false/true consumption behavior.
    - [UID:0002KF][0x00546810-0x00546888.ParcelPaneProcessSlotAnimations](by-memory/0x00546810-0x00546888.ParcelPaneProcessSlotAnimations.md) 0x00546810-0x00546888 | class method | ParcelPane OnTimer : reconstructable : 92% : very-strong : Exact tertiary timer callback advances unacknowledged nonempty left/right button animations, invalidates bounds, reschedules at 200 ms, and returns true with normalized owner offsets.
    - [UID:0002KG][0x00546890-0x0054696f.ParcelPaneOnPaint](by-memory/0x00546890-0x0054696f.ParcelPaneOnPaint.md) 0x00546890-0x0054696f | class method | ParcelPane OnPaint : reconstructable : 92% : very-strong : Source-ready EPFTileContext paint path prepares pane bounds, resolves exact left/right ALERTBTN frame indices, loads ALERTBTN.EPF, and renders both button rectangles with ALERTBTN.PAL.
    - [UID:0002KH][0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter](by-memory/0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter.md) 0x00546970-0x005469db | class method | ParcelPane AdvanceButtonAnimation : reconstructable : 92% : very-strong : Exact idle/animating state transitions, negative-frame delay, left 6..13 and right 20..27 frame cycles, side-dependent reset, vtable slot, and no-callee behavior.
    - [UID:0002KI][0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex](by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md) 0x005469e0-0x00546aab | class method | ParcelPane ResolveButtonFrameIndex : reconstructable : 92% : very-strong : Exact idle/hover/pressed/animating mapping for empty/occupied left and right ALERTBTN frames, live animation-frame reads, vtable route, switch-table boundary, and source-ready const helper.
    - [UID:0002KJ][0x00546ac0-0x00546b74.FlyingParcelPaneConstructor](by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md) 0x00546ac0-0x00546b74 | constructor | FlyingParcelPane constructor : reconstructable : 92% : very-strong : Source-ready Pane constructor initializes five compact animation/payload fields and allocates the owned Layer pointer at +0x100; vptr/cookie/EH remain compiler output.
    - [UID:0001EL][0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart](by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md) 0x00546b80-0x00546d64 | raw-method aggregate | FlyingParcelPane raw lifecycle/start split index : non-reconstructable : 92% : very-strong : Exact non-emitting aggregate over UID0002R5 ordinary destructor `[0x00546b80,0x00546bb5)` and UID0002R6 StartAnimation `[0x00546bc0,0x00546d64)`, preserving both intervening all-CC padding spans, complete owned-Layer cleanup and animation-start source bodies in the children, scalar-wrapper/adjustor/compiler separation, class/file ownership, and the historical no-direct-route caveat without duplicating either child body.
        - [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) 0x00546b80-0x00546bb5 | raw class method | FlyingParcelPane ordinary destructor : reconstructable : 92% : very-strong : Exact raw ordinary destructor source deletes m_animationLayer; vptr restoration and Pane teardown are compiler effects, with scalar wrapper/adjustor parity and no-direct-route evidence preserved.
        - [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md) 0x00546bc0-0x00546d64 | raw class method | FlyingParcelPane StartAnimation : reconstructable : 92% : very-strong : Source-ready payload setup, EPF/legacy rectangles, optional sample 200 volume 100, ScreenPane layer setup, inherited m_origin.y adjustment, C++03 NULL attachment, invalidation, and 100/10 ms timer selection with raw no-direct-route history preserved.
    - [UID:0002KK][0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep](by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md) 0x00546d70-0x00546dee | class method | FlyingParcelPane AnimateStep : reconstructable : 92% : very-strong : Tertiary timer callback moves inherited origin upward for 30 frames, invalidates/reschedules at 10 ms, removes the layer, then invokes ParcelPane's private friend-accessible completion helper to preserve exact count/action/invalidation behavior legally.
    - [UID:0002KL][0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter](by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md) 0x00546df0-0x00546e6b | class method | FlyingParcelPane DrawParcelOrLetter : reconstructable : 92% : very-strong : Source-ready draw selects ALERTBTN parcel art/palette or LETTER art/palette from m_isParcel, initializes one EPFTileContext, and renders into inherited bounds.
    - [UID:0002KM][0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton](by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md) 0x00546e70-0x00546e7b | compiler EH cleanup | ParcelIconPane Singleton clear funclet : non-reconstructable : 92% : very-strong : Exact one-store constructor-unwind funclet with no ordinary route; source cause is the direct Singleton<ParcelIconPane> base and no standalone helper is emitted.
    - [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md) 0x00546e80-0x00546e8b | compiler EH cleanup | ParcelPane Singleton clear funclet : non-reconstructable : 92% : very-strong : Exact one-store constructor-unwind funclet with two EH references and no ordinary route; source cause is the direct Singleton<ParcelPane> base and no standalone helper is emitted.
    - [UID:0001EM][0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks](by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md) 0x00546e8b-0x00546ecd | adjustor thunks | Parcel notification destructor adjustors : non-reconstructable : 92% : very-strong : Exact secondary/tertiary this-adjustment jumps for the three Pane-derived classes; compiler-generated from multiple inheritance/vtables and never emitted as handwritten source.
    - [UID:0001EN][0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor](by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md) 0x00546ed0-0x00546f37 | compiler-generated scalar deleting destructor | FlyingParcelPane scalar deleting destructor : non-reconstructable : 92% : very-strong : Exact wrapper repeats ordinary Layer cleanup and Pane teardown, handles delete flags and optional storage free, and is regenerated from the complete FlyingParcelPane declaration plus ordinary destructor; ownerless, non-emitting, blank formal.
    - [UID:0001EP][0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor](by-memory/0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor.md) 0x00547000-0x005470ad | compiler-generated scalar deleting destructor | ParcelPane scalar deleting destructor : non-reconstructable : 92% : very-strong : Exact primary-vtable wrapper repeats ordinary derived cleanup, reverse Singleton clear and Pane teardown, handles delete flags and optional storage free, and is regenerated from the complete class/ordinary destructor; ownerless, non-emitting, blank formal.
        - [UID:0002W9][0x0069b4d0-0x0069b4d4.g_pParcelIconPane](by-memory/0x0069b4d0-0x0069b4d4.g_pParcelIconPane.md) 0x0069b4d0-0x0069b4d4 | physical global storage | g_pParcelIconPane backing slot : non-reconstructable : 92% : very-strong : Exact four-zero-byte virtual-tail storage with six publication/read/ordinary/EH/scalar lifecycle refs, semantic owner UID0000RX, and blank non-emitting one-definition disposition; UID0000RX alone emits the source global.
        - [UID:0002OH][0x00621bb0-0x00621d50.ParcelNotificationVtableData](by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md) 0x00621bb0-0x00621d50 | compiler RTTI/vtable data | ParcelNotificationVtableData : non-reconstructable : 92% : very-strong : Exact three-class RTTI/vtable island, slots, lifecycle stores, adjustors, hashes, and ALERTBTN successor boundary; complete class declarations regenerate bytes and this page emits no source marker.
    - [UID:0002A0][0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots](by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md) 0x0069ba28-0x0069ba30 | split global-data aggregate | ParcelAndPatchPaneSingletonSplitIndex : ignored : 92% : very-strong : Exact non-emitting split index over separate four-byte loader-zeroed ParcelPane and PatchPane2 singleton storage, distinct nine/five-reference families, no combined source declaration, and balanced child hierarchy.
        - [UID:0002ZO][0x0069ba28-0x0069ba2c.g_pParcelPane](by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md) 0x0069ba28-0x0069ba2c | physical global storage | g_pParcelPane backing slot : non-reconstructable : 92% : very-strong : Exact four-zero-byte virtual-tail storage and SHA256 DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119 with nine constructor/destructor/Flying/EH/scalar refs, semantic owner UID0000RY, exact BowGauge/Patch boundaries, and blank non-emitting one-definition disposition; UID0000RY alone emits the source global.
    - [UID:0002A1][0x0069ba30-0x0069ba34.UnreferencedInitializedDword_69BA30](by-memory/0x0069ba30-0x0069ba34.UnreferencedInitializedDword_69BA30.md) 0x0069ba30-0x0069ba34 | loader-zero filler | UnreferencedDataDword_69BA30 : ignored : 92% : very-strong : Four virtual-tail zero bytes with no IDA name or xrefs between PatchPane2 and PowerDialog singleton slots; historical initialized-0xffffffff wording is superseded and no source global is created.
```

### by-class exact applied handoff

```text
- [UID:000058][FlyingParcelPane](by-class/FlyingParcelPane.md) : reconstructable : 92% : very-strong : Complete implementation-private Pane-derived class declaration with exact 0x104 layout, natural alignment, frame/count/right/left/isParcel fields, owned Layer pointer, constructor/destructor/start/step/draw children, source-legal ParcelPane friend-helper completion route, resources/globals, raw-route negatives, and compiler scalar/adjustor exclusions.
- [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md) : reconstructable : 92% : very-strong : Complete Pane plus Singleton<ParcelIconPane> declaration of size 0x104 with implicit singleton lifecycle, three count bytes, natural alignment, ParcelPane child pointer, intentionally uninitialized inferred notification state, constructor/destructor, source UpdateParcelCounts helper, thin OnParcelUpdate wrapper, exact inlining/no-xref proof, compiler scalar exclusion, and one ParcelPane.cpp route.
- [UID:0000A6][ParcelPane](by-class/ParcelPane.md) : reconstructable : 92% : very-strong : Complete Pane plus Singleton<ParcelPane> declaration of size 0x124 with exact count/action/state/frame/rect/ack fields, ParcelButtonState values/frame map, constructor/destructor/setter/input/timer/paint/helper children, implicit singleton lifecycle, private friend-accessible flying-completion helper, source-legal C++03 formals, and compiler EH/thunk/scalar exclusions.
```

### by-file exact applied handoff

```text
- [UID:0000MF][ParcelPane](by-file/ParcelPane.md) : reconstructable : 92% : very-strong : Complete NexusTK/ui/panels/ParcelPane.cpp source root with ParcelPane/ParcelIconPane/FlyingParcelPane declarations, eighteen ordinary source bodies, two singleton definitions, deterministic class/global and child ordering, exact layouts/resources/globals/callers, raw-helper inlining relationship, direct Singleton publication/clear lowering, compiler RTTI/vtable/EH/thunk/scalar exclusions, and duplicate-free generated expectations.
```

### by-global exact applied handoff

```text
- [UID:0000RX][g_pParcelIconPane](by-global/g_pParcelIconPane.md) : reconstructable : 92% : very-strong : Sole source definition ParcelIconPane *g_pParcelIconPane = NULL at ParcelPane.cpp position 40, with exact zero physical child UID0002W9, one UI read, constructor publish/null fallback, ordinary and EH and scalar clears, direct Singleton<ParcelIconPane> PMD/EBO lifetime, and no duplicate physical emission.
- [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md) : reconstructable : 92% : very-strong : Sole source definition ParcelPane *g_pParcelPane = NULL at ParcelPane.cpp position 50, with exact loader-zero physical child UID0002ZO, nine constructor/destructor/Flying/EH/scalar refs, direct Singleton<ParcelPane> PMD/EBO lifetime, exact ParcelIcon/BowGauge/Patch boundaries, and no duplicate physical emission.
```

### by-struct exact applied handoff

```text
- [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md) : non-reconstructable : 92% : very-strong : Exact three-class layout evidence with normalized Pane secondary/tertiary views, direct empty Singleton PMDs/EBO, ParcelIconPane size 0x104 and inactive final int, ParcelPane size 0x124 and all count/action/state/frame/rect/ack fields, FlyingParcelPane size 0x104 with natural alignment and owned Layer pointer, no explicit pad fields, and source fields emitted only by complete class declarations.
```

### by-vtable exact applied handoff

```text
- [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md) : non-reconstructable : 92% : very-strong : Exact ParcelIconPane/ParcelPane/FlyingParcelPane primary/secondary/tertiary table and slot inventory with lifecycle stores, callback/method identities, adjustor/scalar routes, RTTI boundaries and ALERTBTN successor; complete class declarations regenerate the tables and this support page emits no source marker.
```

No manual tracker row was supplied because `auto-generated/-ag-research-tracker.md` is validator-owned. B001 did not apply any text above; the supervisor applied and validated the exact coverage handoff under commands `000000016365`-`000000016371`. Commands `000000016272`/SHA `71C33D1552F7C7FE969BEB47029C2E93D9D14F7E8EEC01BDD11511F940819D0B`, `000000016276`/SHA `1106869EE43EFE04C404DA75DB5BEB49433A0D667078E5D4DBEE1949BAE007B2`, and bounded command `000000016344`/SHA256 `2781E186632337049194F0A8F5E05FCC78FFE488908D37FC59B57CC16F3462BE` are historical command-scoped tracker samples. No tracker hash is an indefinite-current requirement, and later unrelated tracker epochs remain external mutable state.

## Follow-Up Actions

- B001 callback work is complete. The report remains active and unexecuted at this reconciliation checkpoint; independent Gate 2 review, `execute_report`, report count/path, move, and archive state remain external supervisor/validator-owned.
- The exact no-loss manual coverage rows remain supplied above and were applied and validated externally by the supervisor under commands `000000016365`-`000000016371`; B001 did not edit coverage.
- A-agent actions: none.
- B001 remaining implementation actions: none for UID0002ZO.

## Confidence

- Recommendation confidence: `94/100` for target one-definition, storage, reference, source/compiler, and routing decisions.
- Score confidence: `93/100`; all named blockers were closed, while original lexical/header details cap scores below 95.
- Remaining uncertainty: exact original private spellings and whether the compiler retained UID00043J because of external linkage, debug/address taking, or conservative code generation. None changes behavior, ownership, or destination-ready source.

## Validator Results

All commands ran from `source-3/project-documentation`. Each scoped command used `--mode file --file <destination> --apply --queue-timeout 240`; generated refresh was deferred until the final waited target command. Each successful ordinary command returned exit `0`, `ok:1`, updated only validator-owned registry/reference/projected-stat state as reported, and was followed by immediate lease release.

| Destination | Command | Timestamp (EDT) | Result / warnings / side effects |
| --- | --- | --- | --- |
| D1 | `000000016167` | `2026-07-21T18:52:02-04:00` | exit 0, ok:1; metadata/reference/projected-stat updates; generated deferred |
| D2 | `000000016168` | `2026-07-21T18:53:03-04:00` | exit 0, ok:1; metadata/projected-stat updates; generated deferred |
| D3 | `000000016169` | `2026-07-21T18:53:06-04:00` | exit 0, ok:1; score/position/formal registry updates; generated deferred |
| D4 | `000000016172` | `2026-07-21T18:58:34-04:00` | exit 0, ok:1; score/position updates; generated deferred |
| D5 | `000000016176` | `2026-07-21T19:00:13-04:00` | exit 0, ok:1; score/position/formal updates; generated deferred |
| D6 | `000000016177` | `2026-07-21T19:00:22-04:00` | exit 0, ok:1; score/position updates; generated deferred |
| D7 | `000000016179` | `2026-07-21T19:00:35-04:00` | exit 0, ok:1; score/position updates; generated deferred |
| D8 | `000000016180` | `2026-07-21T19:00:39-04:00` | exit 0, ok:1; score/position/formal updates; generated deferred |
| D9 | `000000016181` | `2026-07-21T19:00:52-04:00` | exit 0, ok:1; score/position updates; generated deferred |
| D10 first attempt | `000000016182` | `2026-07-21T19:01:05-04:00` | nonzero client failure: transient `PermissionError` during validator.ini atomic replace under concurrent validator load; lease was released; no accepted content was omitted |
| D10 retry | `000000016184` | `2026-07-21T19:01:33-04:00` | exit 0, ok:1; successful score/position validation superseded 16182; generated deferred |
| D11 | `000000016186` | `2026-07-21T19:02:04-04:00` | exit 0, ok:1; score/position updates; generated deferred |
| D12 | `000000016187` | `2026-07-21T19:02:08-04:00` | exit 0, ok:1; score/position updates; generated deferred |
| D13 | `000000016194` | `2026-07-21T19:04:15-04:00` | exit 0, ok:1; score/position/formal updates; generated deferred |
| D14 | `000000016196` | `2026-07-21T19:04:25-04:00` | exit 0, ok:1; score/position updates; generated deferred |
| D15 | `000000016197` | `2026-07-21T19:04:29-04:00` | exit 0, ok:1; position update; generated deferred |
| D16 | `000000016201` | `2026-07-21T19:05:30-04:00` | exit 0, ok:1; score/owner/position/formal updates; generated deferred |
| D17 | `000000016202` | `2026-07-21T19:05:40-04:00` | exit 0, ok:1; score/position/formal and UID00043J reference updates; generated deferred |
| D18 | `000000016212` | `2026-07-21T19:08:30-04:00` | exit 0, ok:1; score/position/formal updates; generated deferred |
| D19 | `000000016214` | `2026-07-21T19:09:24-04:00` | exit 0, ok:1; score/position updates; generated deferred |
| D20 | `000000016216` | `2026-07-21T19:09:43-04:00` | exit 0, ok:1; score/position updates; generated deferred |
| D21 | `000000016218` | `2026-07-21T19:10:02-04:00` | exit 0, ok:1; score/position/formal updates; generated deferred |
| D22 | `000000016219` | `2026-07-21T19:10:26-04:00` | exit 0, ok:1; score/position/formal updates; one pre-existing missing UID0003A1 reference warning; generated deferred |
| D23 | `000000016221` | `2026-07-21T19:10:49-04:00` | exit 0, ok:1; score/position updates; generated deferred |
| D24 | `000000016225` | `2026-07-21T19:11:27-04:00` | exit 0, ok:1; score/owner/reconstructable/emitter/formal updates; generated deferred |
| D25 | `000000016229` | `2026-07-21T19:13:37-04:00` | exit 0, ok:1; score updates; generated deferred |
| D26 | `000000016230` | `2026-07-21T19:13:41-04:00` | exit 0, ok:1; score/reconstructable/emitter/formal updates; generated deferred |
| D27 | `000000016232` | `2026-07-21T19:13:51-04:00` | exit 0, ok:1; score/reconstructable/emitter/formal plus stats-row removal; generated deferred |
| D28 | `000000016233` | `2026-07-21T19:13:55-04:00` | exit 0, ok:1; score/reconstructable/emitter/formal updates; generated deferred |
| D29 | `000000016234` | `2026-07-21T19:14:06-04:00` | exit 0, ok:1; score updates; generated deferred |
| D30 | `000000016235` | `2026-07-21T19:14:19-04:00` | exit 0, ok:1; score updates; generated deferred |
| D31 | `000000016236` | `2026-07-21T19:14:29-04:00` | exit 0, ok:1; score updates; generated deferred |
| D33 | `000000016239` | `2026-07-21T19:16:01-04:00` | exit 0, ok:1; score/position updates; generated deferred |
| D34 | `000000016240` | `2026-07-21T19:16:05-04:00` | exit 0, ok:1; score/reconstructable/emitter/formal updates; generated deferred |
| D35 | `000000016241` | `2026-07-21T19:16:15-04:00` | exit 0, ok:1; score updates; generated deferred |
| D36 | `000000016242` | `2026-07-21T19:16:28-04:00` | exit 0, ok:1; score and projected-stat queue removal; generated deferred |
| D37 | `000000016243` | `2026-07-21T19:16:41-04:00` | exit 0, ok:1; score updates; generated deferred |
| D38 | `000000016244` | `2026-07-21T19:16:54-04:00` | exit 0, ok:1; score updates; generated deferred |
| D41 | `000000016245` | `2026-07-21T19:17:07-04:00` | exit 0, ok:1; score/owner updates; generated deferred |
| Initial D1 waited refresh | `000000016246` | `2026-07-21T19:17:40-04:00` | exit 0, ok:1; full registry rebuild and generated refresh completed after zero leases; only pre-existing global warnings were reported |
| D4 exact-formal correction | `000000016270` | `2026-07-21T19:30:16-04:00` | exit 0, ok:1; removed the non-accepted manual singleton publication and restored exact accepted constructor formal; generated deferred; lease released immediately |
| D8 exact-formal correction | `000000016271` | `2026-07-21T19:30:35-04:00` | exit 0, ok:1; restored exact accepted C++03 body shape without behavior change; generated deferred; lease released immediately |
| Corrective final D1 waited refresh | `000000016272` | `2026-07-21T19:30:43-04:00` | exit 0, ok:1; full registry rebuild and generated refresh completed after zero leases; only pre-existing global warnings were reported |

Generated command `000000016272`, SHA256 `FA543CE85E2F762B432A7AC20AFFA289CF85B27BD7EB7066F41D009D1A616647`, 17,715 bytes/560 lines, is B001's accepted callback checkpoint; commands `000000016246`/SHA `0F6B5F525A54A648C76EE837BB1A6D41607D04D62515C37F95EB6E66970E6064` and `000000016248`/SHA `F9EAEE5CAC237FB2FAC34687C59C04FDDC2895E2CA855EDDA632E0AEFC8C86F9` are earlier historical callback samples. Later read-only external command `000000016340`, SHA256 `A133CE0D58AE211441CED78B828128D8B89BA55115EB812E6F19F980523FC0C1`, 17,715/560, changed metadata only and preserves the terminal assertions: one complete ParcelPane, ParcelIconPane, and FlyingParcelPane class definition; Icon bodies constructor/destructor/UpdateParcelCounts/OnParcelUpdate once each; Parcel bodies constructor/destructor/setter/key/mouse/timer/paint/advance/resolver once each; Flying bodies constructor/destructor/start/animate/draw once each; both global definitions once; class order `10/20/30`, globals `40/50`, child order exact; zero UID0002ZO/UID0002W9 markers; zero layout/vtable/aggregate/EH/adjustor/scalar markers; zero Empty Emitter Marker; no duplicate body; and no handwritten Singleton/ABI lowering in method bodies. Tracker commands `000000016272`, `000000016276`, and bounded later sample `000000016344` are evidence-time external state, not generated-semantic authority or indefinite-current requirements.

External supervisor-owned post-callback validation completed after the B001 checkpoint:

| External destination | Command | Result / warnings / side effects |
| --- | --- | --- |
| `by-memory/-coverage-report.md` | `000000016365` | exit 0, ok:1; applied 30 exact rows and added the UID00043J reference; unrelated pre-existing missing-reference warnings UID0003MT/UID0003VS/UID00039L/UID0003T6 |
| `by-class/-coverage-report.md` | `000000016366` | exit 0, ok:1; applied three exact class rows |
| `by-file/-coverage-report.md` | `000000016367` | exit 0, ok:1; applied one exact file row |
| `by-global/-coverage-report.md` | `000000016368` | exit 0, ok:1; applied two exact global rows; unrelated pre-existing missing-reference warning UID0003MS |
| `by-type/by-struct/-coverage-report.md` | `000000016369` | exit 0, ok:1; applied one exact struct row |
| `by-type/by-vtable/-coverage-report.md` | `000000016370` | exit 0, ok:1; applied one exact vtable row; unrelated pre-existing missing-reference warnings |
| final waited D1 validation | `000000016371` | exit 0, ok:1; generated refresh completed and retained all 38 exact coverage rows |

Command `000000016371` produced the current ParcelPane.cpp checkpoint, SHA256 `BD29AB0038F89A0E2734D34C17AA199E6528D70A7DFDBF00D64231BAC1E2E2AB`, 17,715 bytes/560 lines. Readback proves exactly 9 ParcelPane definitions, 4 ParcelIconPane definitions, 5 FlyingParcelPane definitions, one `g_pParcelPane` definition, one `g_pParcelIconPane` definition, zero UID0002ZO/UID0002W9 physical markers, zero Empty Emitter Markers, and zero decompiler labels. Commands 16272 and 16340 remain historical semantic-equivalent checkpoints; command 16371 is external supervisor/validator work and was not run by B001.

## Changed Files

- Modified ordinary files: D1-D31 except verify-only D32, D33-D38, and D41; exact current hashes are recorded below. No file was renamed or created.
- Verify-only/protected: D32, D39, and D40 were not edited by B001. D39's B001 checkpoint later advanced through B005 to the external hash shown below while preserving boundary/storage semantics; D40 advanced independently to the current B002-owned hash shown below.
- Modified report: this same canonical research artifact only.
- Manual coverage/generated/tracker/audit/supervisor/validator-state/IDA files: none edited by B001. The supervisor later applied the exact coverage handoff under commands `000000016365`-`000000016370`; command `000000016371` refreshed generated output. Those external changes and current hashes are recorded above.
- Current external checkpoints after command `000000016371`: by-memory coverage `85AD82FC4D1E579255B06B4EA26813C8651A0AA24E6BB8D0D26D92AEC3E3CBF7`; by-class `B9A93C85C1CE2DDE5C3F76C2FC6985F2C0DBE6D37384A1F9601CCB9BC83B7570`; by-file `35EA6391EF8C89256572B6CFCDD81256A6DAA7D5C14545B8AFFC1EB94336DDC3`; by-global `F79F04B44824C59A4CDC8EEA145C6CDBD2564571754C1FFE61B2471F07E5FEBF`; by-struct `375E0919656011E6C2B892884D912C77B12AEC462347F43CE052263C2B1FA78A`; by-vtable `18E9DC82B5F7267E847AD4B64065FBCF24DC82034F125971C29F07ECAFE71C18`; generated ParcelPane.cpp `BD29AB0038F89A0E2734D34C17AA199E6528D70A7DFDBF00D64231BAC1E2E2AB`.
- Leases: each ordinary destination was leased only for its immediate reread/edit/scoped-validator batch and released immediately; zero B001 leases remain.
- Report execution/lifecycle/probe/count/move/archive: not run by B001.

| D | Current SHA256 | Bytes / lines | B001 disposition |
| --- | --- | ---: | --- |
| D1 | `FC0F1A0CDCE0DAADD3B9213BF558318AC5C4893D82536851104C9E1AF58AE790` | 10,243 / 106 | changed, validated 16167 |
| D2 | `BCE398FC76AE6A74E00A7417038214ED8FBAECE79396BC5726546B464A8C4B23` | 14,823 / 120 | changed, validated 16168 |
| D3 | `72AC588D76D9036D481D70CC19BE09C310C13D08BD4D740A347DCF483275ED88` | 35,151 / 242 | changed, validated 16169 |
| D4 | `A06D5BB99A32BB8D1F78BC1B5654D65B7CA6FF4B1A4B97091D3565D228CEC75B` | 12,353 / 109 | changed, validated 16172 and corrective 16270 |
| D5 | `264FBEF684674FB0D199D516D1C63772D41F681AFB95E186A39B0C9E5DE42CE7` | 11,284 / 109 | changed, validated 16176 |
| D6 | `C7AA8D6852EF6545351C9B89939451105FB3D34A727EFA4FC96AE2BC3FEAEFF2` | 13,820 / 139 | changed, validated 16177 |
| D7 | `738B116CE95AE755BCBD8908CC9D758826326297E755A92266B7D1DAAEE144E8` | 12,971 / 114 | changed, validated 16179 |
| D8 | `5186FCC7A4F4375457EBDD60087B6BF85C578F56F548A86F29EC647613065DFE` | 19,569 / 193 | changed, validated 16180 and corrective 16271 |
| D9 | `570C8195CAD9CFB80C9CB2268CB2AD34C7E6B7EE8DE59B306B3C7DA01A3D6474` | 9,768 / 134 | changed, validated 16181 |
| D10 | `0721E7986BAA4AFD056D9B85C0F2705E94740E4B68191EA84BD9055584241252` | 20,527 / 169 | changed, validated 16184 |
| D11 | `707E7CCD242DD7FF92964061AE1986CA8018F59FD123D14355375B4CA8893580` | 9,546 / 149 | changed, validated 16186 |
| D12 | `821C8C290A00044566C59192BED408C8AF2B11C8031FB1C64AAD8A0302C2DAD3` | 10,270 / 154 | changed, validated 16187 |
| D13 | `737D17498BB5B06AF3A89DBBA07A812B96680CFC59B5063978580E904F655A9B` | 25,133 / 163 | changed, validated 16194 |
| D14 | `6D4105FF45B1CE70493C2D775737BB6278BE3A51B5DCD2A2C533A662964BEA59` | 17,250 / 125 | changed, validated 16196 |
| D15 | `D3BDDF095A58FC39B569F9800F71F7533640DF583895655FB90D8D3E11E7F049` | 11,325 / 95 | changed, validated 16197 |
| D16 | `E4345CE59BEB26EFC68FC487CC7263EA4A677D023A87F1D257095727C0E6AACC` | 18,516 / 185 | changed, validated 16201 |
| D17 | `815E62703CD9ED30A5991073F2A580689F43802A180C90900BD2482F098ECAA8` | 15,440 / 137 | changed, validated 16202 |
| D18 | `A236565DF928A186109DF7C76468B1BB606ED199D88EF7EC910CEE1FAC513471` | 44,697 / 234 | changed, validated 16212 |
| D19 | `2B045787C88CFD81F08C6186FC3A308489A67BBA06F6078057DCD51C061CD6FC` | 14,626 / 154 | changed, validated 16214 |
| D20 | `C1A6A5E9723AAC57DBD323086A7EB9E54FCF914F570CDF2FF85F32EC3894A530` | 18,082 / 161 | changed, validated 16216 |
| D21 | `3EE191F590DFDCD99BE0A648BDCA7DAE1E9DD91C2647C61D1CC03351C7679E8F` | 23,092 / 239 | changed, validated 16218 |
| D22 | `A6C78A51B9E7F2F71D9ABDE3831C650993BF80074745ED2E504ED61564F22234` | 22,323 / 181 | changed, validated 16219 |
| D23 | `69E100E3FCB1C0C65005B0697084337F5AAAF0579F86812A72FAEBB791F1207C` | 18,749 / 177 | changed, validated 16221 |
| D24 | `661198045C8952B291E2480E2383296021B071AC889C61AC02124076689E800E` | 11,932 / 92 | changed, validated 16225 |
| D25 | `BD0E17988F0634A5158CB5B207725D36889156C937EA89FB905C1B8D09442740` | 58,348 / 250 | changed, validated 16229 |
| D26 | `6C36405AAC6638AFCAC1EB5677914F846B91526770401EA6E983CEF005BDFA31` | 27,266 / 166 | changed, validated 16230 |
| D27 | `22EE82C7FD934B5CA7DB60671A58BA1FBB9CC4FEE8A095E6EB7BBA2473C62366` | 16,926 / 148 | changed, validated 16232 |
| D28 | `628FEDF6A45A36B5A7FB7D52FD0A76AF6D29E2A5FE5CE31EC8C6CFDB75481C92` | 15,029 / 131 | changed, validated 16233 |
| D29 | `213A35CDE030500BFC4D37F13B53B824280C7136D70DC83516B55A540688E5D5` | 31,767 / 172 | changed, validated 16234 |
| D30 | `0C7FF33F086DB7DF66645FC2AEA37E8314E8592071FDF32F17F8CFA85C44E8D4` | 13,762 / 99 | changed, validated 16235 |
| D31 | `944FE7F34B92E7C9BD638A63DA7E502504BCE2C47B1F03B107BDB38FAFEB66D9` | 14,285 / 116 | changed, validated 16236 |
| D32 | `1DC1ECCF7FE475E206D84991BD95F457621EF66482AE32D0424441885FE6CB37` | 12,952 / 102 | verify-only, unchanged by B001 |
| D33 | `9C0DA5767E02AE35D4DA87A7B1D176BF2ADC73F49081E5655012EBAD89717373` | 9,869 / 96 | changed, validated 16239 |
| D34 | `33F1E9C7BDF0DDD9A62C26FD19564408C2810A5E517EF5F46F749090F9CF5F02` | 5,834 / 57 | changed, validated 16240 |
| D35 | `A04BE87C25D3E9F46A28DC7A0D4AA7C614B5D3554238170205CE7AA8A8E773EC` | 5,952 / 68 | changed, validated 16241 |
| D36 | `E58F886E3816687DBDC50837FF806C8B6083849110231A2C307B4D78FF11C014` | 2,658 / 47 | changed, validated 16242 |
| D37 | `2499AC6C98BA69B74795AB6CA37C2B059F13A2C8687425A4F194D0A75268D8A0` | 6,712 / 75 | changed, validated 16243 |
| D38 | `DCB08EF6725CEEC6E79C196C567D2A0EB858FE824CED001002647402CFFDF85F` | 5,814 / 66 | changed, validated 16244 |
| D39 | `D1FB8382F6FD3767306DB71ABAF3EDA9F2C1EE4B48724B894F4709852D4B1A9D` | 9,097 / 89 | current external B005 completion; protected and unedited by B001; historical B001 checkpoint `6AE27F3408441A2015F9DFBFF522CB2875BBB6445F60AF2FBD76D57BA3DBB6E8`, 8,572/84 |
| D40 | `800D080E300E186E4A5170D9A71BB03220E0E3B92DCF934E3713A059CDD882A6` | 12,834 / 127 | protected verify-only; current B002-owned union |
| D41 | `7FCC357DBF18FD44D48659C79FCDEB17B6D38314F7EE286C8063A3CC2A9D55CB` | 13,905 / 109 | changed, validated 16245 |

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 accepted exact report SHA256 `7C64083C65C4E02E9733EA871ECCD218BA4BD14003D0190A0157B04C1A6655A4` before implementation.
- [x] Re-read every D1-D41 destination and active leases immediately before callback edits.
- [x] Apply D1 UID0002ZO `92/94`, semantic owner UID0000RY, false/no-emitter/blank, `Nested:4`, full evidence/history.
- [x] Apply D2 UID0000RY `92/94`, position 50, sole exact definition and complete lifecycle.
- [x] Apply D3 complete ParcelPane declaration, `92/94`, position 10, direct Singleton and private friend helper.
- [x] Apply D4 constructor exact managed block, `92/94`, position 20.
- [x] Apply D5 destructor exact managed block, `92/94`, position 30.
- [x] Preserve D6 setter exact body, raise to `92/94`, position 40, add complete evidence/history.
- [x] Preserve D7 key exact body, set `91/93`, position 50, add complete evidence/history.
- [x] Apply D8 mouse exact C++03 managed block, `92/93`, position 60.
- [x] Preserve D9 timer exact body, set `92/94`, position 70.
- [x] Preserve D10 paint exact body, set `92/93`, position 80.
- [x] Preserve D11 animation-helper exact body, set `92/94`, position 90.
- [x] Preserve D12 frame-resolver exact body, set `92/94`, position 100.
- [x] Apply D13 ParcelIconPane declaration with UpdateParcelCounts, `92/93`, position 20.
- [x] Preserve D14 Icon constructor, set `92/94`, position 20.
- [x] Preserve D15 Icon destructor `92/94`, set position 30.
- [x] Apply D16 exact UpdateParcelCounts body, `92/93`, emitter UID0000A5, position 40.
- [x] Apply D17 exact thin callback body, `92/93`, position 50, retain inlined binary proof.
- [x] Apply D18 complete FlyingParcelPane declaration, `92/93`, position 30, natural alignment.
- [x] Preserve D19 Flying constructor, set `92/94`, position 20.
- [x] Preserve D20 Flying ordinary destructor, set `92/94`, position 30.
- [x] Apply D21 StartAnimation C++03 block, `92/93`, position 40.
- [x] Apply D22 AnimateStep private-helper block, `92/93`, position 50.
- [x] Preserve D23 draw body, set `92/93`, position 60.
- [x] Apply D24 Flying scalar false/none/no-emitter/blank `92/94` disposition.
- [x] Apply D25 ParcelPane file `92/93` complete source inventory/order/history/generated plan.
- [x] Apply D26 layout `92/94` false/non-emitting/blank while preserving all exact offsets.
- [x] Apply D27 vtable family `92/94` false/non-emitting/blank while preserving all slots.
- [x] Apply D28 vtable data `92/94` false/non-emitting/blank while preserving hashes/bounds.
- [x] Apply D29 executable aggregate `92/94` false/blank complete child index.
- [x] Apply D30 Parcel EH clear `92/94` false/none/blank complete proof.
- [x] Apply D31 Parcel scalar wrapper `92/94` false/none/blank complete proof.
- [x] Apply D33 UID0000RX `92/94`, position 40, sole definition/lifecycle.
- [x] Apply D34 UID0002W9 `92/94`, semantic owner UID0000RX, false/no-emitter/blank, zero/six-ref proof.
- [x] Apply D35 UID0002A0 `92/94` split-index evidence without range/hierarchy change.
- [x] Apply D36 UID0002A1 `92/94` zero/no-xref filler correction and retain `Nested:-4`.
- [x] Apply D37 icon EH clear `92/94` false/none/blank proof.
- [x] Apply D38 adjustor aggregate `92/94` false/none/blank proof.
- [x] Verify D39 UID0002ZP at the protected B001 checkpoint, then reconcile B005's external completion SHA `D1FB8382F6FD3767306DB71ABAF3EDA9F2C1EE4B48724B894F4709852D4B1A9D`; exact `0x0069ba2c` successor start, loader-zero physical backing, and C2ZO-013 remain unchanged without a B001 edit.
- [x] Verify/protect D40 B002-owned UID0001PY; B001 made no edit and final readback recorded current hash `800D080E300E186E4A5170D9A71BB03220E0E3B92DCF934E3713A059CDD882A6`.
- [x] Apply D41 Flying raw aggregate `92/94` false/blank exact split inventory.
- [x] Preserve D32 UID0001EO at accepted `92/94` false/no-code and all unrelated Parcel dependencies.
- [x] Preserve every exact byte/hash/xref/caller/callee/vtable/layout/resource/global fact.
- [x] Preserve historical `ff`, manual global, comment-marker, raw-no-code, illegal-access, and Wave3 assumptions as explicitly superseded.
- [x] Apply exactly the 18 managed blocks above and preserve all other current formal bodies exactly.
- [x] Convert every C2ZO-001..100 ledger state from `proposed` only after the accepted callback proved it; all 100 are now terminal with separate claim-specific proof.
- [x] Re-read and no-loss merge all current manual coverage rows; B001 does not edit coverage.
- [x] Run one scoped validator per changed ordinary page under one-file lease/validate/release discipline.
- [x] Run final UID0002ZO `--wait-generated` only after all ordinary leases are clear.
- [x] Verify generated three-class, 18-body, two-global, order, uniqueness, C++03, and absence assertions; external waited command `000000016371` later reconfirmed the same semantics.
- [x] Record exact command IDs/timestamps/exits/ok/warnings/side effects and generated hashes in this report.
- [x] Update all 100 claims to legal callback states with claim-specific destination proof.
- [x] Check callback rows only after independent readback; list any blocked claim exactly.
- [x] Confirm zero provisional UIDs, zero stale marker comments, and zero B001 leases.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted ordinary destinations updated at report-level detail without loss.
- [x] Every accepted formal/metadata/score/owner/emitter/position disposition applied or explicitly excluded with reason.
- [x] Every scoped validator and final waited generated check passed and was recorded.
- [x] Exact supervisor-owned manual coverage handoff rebased without loss, then externally applied and validated under commands `000000016365`-`000000016371`; all 38 rows and UIDs occur exactly once.
- [x] C2ZO-001..100 terminalized and all accepted checklist rows checked truthfully.
- [x] No manual coverage/generated/tracker/audit/supervisor/validator-state/IDA/lifecycle file edited by B001.
- [x] No execute_report/probe/count/move/archive/lifecycle command run by B001.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000016385","destination_path":"executed-b-agent-research/B001/0002ZO-g_pParcelPane-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002ZO-g_pParcelPane-source-quality.md","timestamp":"2026-07-22T15:32:16-04:00","uid":"0002ZO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
