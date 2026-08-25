** TARGET-REPORT-UID:0001NG **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0001NG SpellSlotInputPane Scalar/Direct Destructor Source-Quality Report

## Finalized Report / Current Recommendation

The accepted callback implemented the human-destructor/compiler-wrapper split. [UID:0001NG] remains at exact `[0x005b7dc0,0x005b7e84)`, is now `92/94`, retains canonical class ownership by UID0000DS, is `RECONSTRUCTABLE:FALSE`, has blank `EMITTER_UIDS` and optional position, retains `Nested:0`, and carries exact blank R0. Validator-issued [UID:0004UC][0x005b1310-0x005b1393.SpellSlotInputPaneDestructor](by-memory/0x005b1310-0x005b1393.SpellSlotInputPaneDestructor.md) is implemented at `91/94`, owner/emitter UID0000DS, reconstructable true, blank optional position, `Nested:0`, and exact human R1.

The source declaration remains `virtual ~SpellSlotInputPane()` in UID0000DS. A final generated-source readback also proves that the class declaration must add the private `SendSpellSlotPacket(signed char selectedSlot)` declaration already required by UID0003VX's emitted qualified definition. The direct function and scalar wrapper both contain compiler destructor lowering, but only the direct function has the complete-destructor ABI without delete flags. Their normalized source behavior is one branch that clears the active spell-input mode through GeneralPurposePanel child index 3. Human C++ must exclude vptr stores, explicit base teardown, scalar flags, storage release, guarded-size handling, SEH/cookie/EH machinery, adjustor arithmetic, and raw vtable/RTTI data.

Implementation and scoped validation are complete for every accepted ordinary destination. B003 edited no manual coverage, generated source, tracker, audit/supervisor, validator-state, IDA, lifecycle, or archive file directly and ran no report execution/probe/move/archive command. Validator commands produced authorized generated/tracker side effects, all 44 callback rows are checked from current readback, and the ledger has 21 atomic terminal claims: 19 `applied`, one `already-present`, and one supervisor-owned manual handoff `excluded-with-reason` because it remains unapplied by B003.

## Supporting Research

- Mandatory live IDA MCP evidence was collected against database session `9b0396a3` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. At evidence-collection time `idb_list` returned one active worker (PID 15732), and `server_health` returned `ok` with auto-analysis, Hex-Rays, and string caches ready.
- Binary identity: 32-bit `NexusTK.exe`, image base `0x00400000`, image size `0x002b3000`, `.text` `[0x00401000,0x0060d000)`, 7,862 functions, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Exact historical-report search terms: `TARGET-REPORT-UID:0001NG`, `0001NG`, `0x005b7dc0`, `0x005b7e84`, `0x005b1310`, `0x005b1393`, `SpellSlotInputPaneScalarDeletingDestructor`, `SpellSlotInputPaneDestructor`, `SpellSlotInputPane`, `0000DS`, `0000O0`, `0001LN`, `0001LV`, `0001LW`, `0001LX`, `0003VX`, `SendSpellSlotPacket`, `0001N9`, `00026W`, `g_useEpfAssets`, `g_pGeneralPurposePanel`, `0x0062f670`, `0x0062f6c0`, and `0x0062f6f0`.
- Exact roots searched: `executed-b-agent-research/**`, `archived/**`, `tools/leaser/Agents/Older-Research/**`, `tools/leaser/Agents/SpecialReports/**`, and active `tools/leaser/Agents/Agent-B001` through `Agent-B005` research paths.
- `executed-b-agent-research/**` produced seven `0x005b7dc0` matches and five `0x005b1310` matches. `archived/**`, `Older-Research/**`, and `SpecialReports/**` produced zero target-specific matches. Active B001-B005 research paths produced zero direct UID0001NG target collision.
- During finalization, Gate-1-accepted B001 UID0001NF implemented the adjacent SpellOneArg split and changed shared UID0001LN, UID0000O0, UID0001N9, UID00026W, `by-memory/-ignored.md`, generated source, and tracker state. B003 waited until B001 held zero ordinary leases, then reread and rebased the complete current union: real OneArg child UID0004UB, parent `90/93`, vtable aggregate `91/94`, and every B001 detail are preserved below. B001's report lifecycle remains external and is not inferred from ordinary-file state.
- Executed B002 `0000O0-SpellInputPanes-empty-emitter-family-source-quality.md`, SHA256 `842506F53B36826085B2C72B614B8D68FA3EF8B1A92A67F13DE5CE644F746BF0`, correctly identified the scalar family as compiler wrappers but historically placed each human destructor body on its scalar page because separate direct pages were not then established. Its SpellSlot carrier choice is superseded by the fresh exact direct-body proof here; its class/file/source behavior remains a useful historical lead.
- Executed B003 UID0001NE, SHA256 `7253A4A61621CED0DF7B6E2122A8ADEF25175521C03F19EF0D0CCA6022D58EAD`, is comparison evidence only. It establishes a recently accepted direct/scalar split standard for SpellFourArgsInputPane, but every SpellSlot range, hash, route, helper, padding, metadata, and source decision in this report was rechecked independently.
- Executed B004 UID0001NH, SHA256 `E0A96201E0BA52ACB01AC4B246F0E9CE7282CE37A72FEC4AA005D71AC072A0B6`, independently ties the sibling SpellString scalar wrapper to its separate direct destructor. It corroborates compiler-family shape but does not substitute for this target pass.
- Executed B005 UID0001LW and B007 UID0001LX provide target-class key/submit evidence. Executed B001 UID0001IJ, B006 UID0001II, and B011 UID00015W provide state-setter/accessor naming leads. All were rechecked against current ordinary docs and live target calls rather than inherited without verification.

## Target

- Assigned UID: `0001NG`.
- Assigned path: `by-memory/0x005b7dc0-0x005b7e84.SpellSlotInputPaneScalarDeletingDestructor.md`.
- Assignment-time SHA256: `B1DF217D05A88F9EDF14C5040272295D29E31C110826F6704AEF4E3270B2BB46`, 7,382 bytes / 86 lines.
- Implemented readback SHA256: `28829F3B5548EED56C6D5609AA49754B4D25222709EA97570C8D8EB7EBBD6731`, 10,806 bytes / 94 lines.
- Exact target function: `sub_5B7DC0`, `[0x005b7dc0,0x005b7e84)`, `0xc4` / 196 bytes, SHA256 `A293B245A4A4E9E98152A2AD366CA3F666BD4102DF35F1BC939FB29B947B9A28`.
- Target role: MSVC scalar-deleting-destructor wrapper for `SpellSlotInputPane`, reached from the primary class vtable and two adjusted-view thunks.
- Source cause: the virtual class destructor declared by UID0000DS plus ordinary source deletion expressions. The sole human destructor definition belongs on a dedicated page for `[0x005b1310,0x005b1393)`.

## Current Target State

| Field | Historical pre-callback state | Implemented state |
| --- | --- | --- |
| Completion / confidence | `86/90` | `92/94` |
| Canonical owner | `0000DS` | retain `0000DS` |
| Reconstructable | `TRUE` | `FALSE` |
| Emitters | `0000DS` | blank |
| Optional position | blank | blank |
| Nested | `0` | retain `0` |
| Formal C++ | human destructor body on scalar wrapper | blank R0 |
| Item Summary | scalar wrapper described as reconstructable destructor carrier | exact compiler-wrapper/no-code summary with `0004UC` source cause |

Historical pre-callback generated command/header `000000015307` at `2026-07-20T11:31:04-04:00`, SHA256 `D7D601D792B72A4085FFE8505DF12BBDC284EBD2A5EC0F08729ADA457195F9B4`, 20,398 bytes / 595 lines, emitted the destructor from UID0001NG and lacked the UID0003VX member declaration. That state motivated R1/R2 and is not current.

Waited validator command/header `000000015323` at `2026-07-20T12:00:50-04:00` produced `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp` SHA256 `FCAE50203A82EB62619BBB87157A16C742A84DB850854E4EC13F147EF94C8415`, 20,441 bytes / 597 lines. The UID0000DS class starts at line 224, declares private `SendSpellSlotPacket(signed char selectedSlot)` at line 234, closes at line 237, and all qualified definitions follow. Constructor line 240, UID0004UC marker line 247/destructor line 248, Event handler line 258, submitter line 276, UID0003VX marker line 308/sender line 309 each occur once as definitions. UID0001NG, `0x005b7dc0`, its title, body, and Empty Emitter Marker occur zero times. UID0003VV remains the sole unrelated Empty Emitter Marker at line 597. There is no target vptr/adjustor/address/delete/guard/cookie/SEH/EH/raw-vtable implementation.

Historical tracker command/header `000000015307` recorded pre-callback UID0001NG `86/90`, true, zero direct reports. Waited command/header `000000015323` at `2026-07-20T12:00:50-04:00` produced the B003 callback snapshot SHA256 `90D671C6988B502831C3B3565842841A31DDC6D0407C84ACBB74AADB5A2D8624`, 1,530,206 bytes / 6,204 lines. Validator-owned deferred command/header `000000015325` at `2026-07-20T12:11:35-04:00`, SHA256 `9C54A9B02F60EE2FD56698E1575E35EFD33B217E1376BA755902CAF5E780E8A4`, 1,530,204 bytes / 6,204 lines, is also historical. The final rebase observed external supervisor B005 execute command/header `000000015329` at `2026-07-20T12:33:10-04:00`, current read-only tracker SHA256 `C60D04925567C877C5ED3872E2841D07A6C42FA204E7ADCE6A02BF6C41906D6A`, 1,530,321 bytes / 6,204 lines. It lists UID0004UC `91/94`, true, and UID0001NG `92/94`, false, exactly once and records UID00030F `92/94`, true, with one executed B005 report at `executed-b-agent-research/B005/00030F-TextEditPaneOnKeyEvent-source-quality.md`. B003 issued none of commands 15325-15329. Exact later path/count/lifecycle state remains validator/supervisor-owned; these are bounded external snapshots, not indefinite assertions.

## Executive Recommendation

1. Registered validator-issued UID0004UC at `by-memory/0x005b1310-0x005b1393.SpellSlotInputPaneDestructor.md` as the exact direct complete-destructor source carrier and emitted R1 only there.
2. Reclassified UID0001NG as a fully documented non-reconstructable compiler scalar wrapper with R0 blank.
3. Raised UID0000DS from `90/93` to `91/94` and installed complete R2 while preserving its owner/emitter route, inheritance, layout, public API, and class closure before `[[CHILDREN]]`; the private `SendSpellSlotPacket(signed char selectedSlot)` declaration now matches the existing UID0003VX definition.
4. Preserved B001-rebased UID0001LN at `90/93`, `Nested:-4`, false/non-emitting, blank R3, with its complete nineteen-span parent-internal padding inventory and real UID0004TY/UID0004UB children; inserted UID0004UC in address order with `Nested:0`.
5. Preserved UID0001LV, UID0001LW, and UID0001LX scores, ranges, formals, routes, and `Nested:0`; added only bounded direct/scalar relationship/history prose.
6. Historicalized UID0001N9's stale blanket scalar-source sentence while retaining `86/90`, compiler-only status, blank R4, and every unrelated thunk.
7. Extended UID00026W's exact compiler-data provenance for the SpellSlot slice while retaining B001-applied `91/94`, false/non-emitting, blank R5, the complete OneArg/FourArgs union, and no raw-array emission.
8. Added the two target-external 12-byte scalar-family alignment spans to `by-memory/-ignored.md` while preserving all nineteen parent-internal spans and all unrelated rows.
9. Updated UID0000O0 at report-level detail without changing `92/94` or the `NexusTK/ui/dialogs/` route.

## Supervisor Active Recheck

- Every ordinary destination was reread after acquiring its short lease, rebased additively, scoped-validated, and released before the next lease. Commands 15311-15322 record the exact sequence below.
- Manual coverage snapshots and exact neighboring rows were reread after implementation and again after supervisor commands 15326-15329. The current roots preserve all 23 externally applied B005 rows; B003's separate Spell handoff remains supervisor-owned and unapplied, is rebased over that union, and reflects real UID0004UC.
- Waited generated command 15323 and tracker epochs 15323/15325/15329 were reread. External B005 execute command 15329 preserved the implemented UID0004UC/UID0001NG semantics and did not alter `SpellInputPanes.cpp`; these command epochs are bounded evidence facts rather than indefinite freshness claims.
- Final `tools/leaser/Agents/Agent-B003/current_leases.md` readback reports no active leases. B003 holds zero leases.
- Implementation callback work is complete; C01-C21 are atomic and terminal, and no B003 implementation item remains. Report validation/execution/count/path/move/archive state is external supervisor/validator-owned and is neither asserted nor directed by this artifact.

## Inference Research Guidance Check

- Range, size, bytes, hashes, instructions, xrefs, vtable cells, COL offsets, helper calls, and padding are direct facts.
- `SpellSlotInputPane`, the three vtable view names, and the virtual destructor relationship are RTTI/decorated-name facts.
- The exact original public/helper/member spellings are not present in the binary. `g_useEpfAssets`, `g_pGeneralPurposePanel`, `GetChildPaneByIndex`, `ItemWhoInputPaneState`, `SpellInputPaneState`, and `SetInputModeFlag` are project-consistent source-facing names supported by current declarations and behavior, with inference explicitly retained.
- Zero xrefs to the direct function are negative route evidence, not dead-code proof. The complete-destructor ABI, family-wide compiler materialization, scalar-wrapper normalization, and virtual deleting route establish source retention.
- No source statement is inferred for vptr stores, explicit base cleanup, scalar flags, free/guard logic, cookie/SEH/EH, adjustors, COLs, or vtable arrays; those are compiler consequences.

## Heuristic / Inference Reanalysis And Validation

The old page conflates two products of one virtual destructor. The direct function at `0x005b1310` accepts only `this`, returns `void`, restores the three class facets, executes the state-clear branch, and calls the `LineInputPane` cleanup body. The scalar wrapper at `0x005b7dc0` repeats that cleanup and then consumes a hidden flag byte, tests bits 1 and 4, invokes ordinary storage release or a guarded `0x10c` path, and returns the original object pointer. That delta is the standard complete-destructor versus scalar-deleting-destructor lowering boundary.

Normalization removes identical vptr stores, the shared state clear, explicit base cleanup, SEH/cookie setup, and EH funclets. The remaining human behavior is exactly one branch:

- when `g_useEpfAssets` is true/current mode, fetch GeneralPurposePanel child index 3 and call the accepted ItemWho state setter with false;
- otherwise fetch the same child index and call the accepted Spell state setter with false.

The direct function's zero exact-start xrefs and zero stored `0x005b1310` pointer hits do not prove dead or compiler-only no-source bytes. MSVC may emit an out-of-line complete destructor variant even when all runtime virtual destruction reaches the scalar wrapper. The same executable contains six 0x83 direct variants and six 0xc4 scalar variants with this normalized relationship. The class constructor is reached from three inventory functions and is separately inlined in UserPane command-slot construction, so the class is live. The primary vtable and two adjusted facets make virtual destruction live.

The current source-facing class declaration is layout-complete but declaration-incomplete. `SpellSlotInputPane : public CharInputPane` has a virtual public destructor, Event handler, submitter, and `char m_spellIndex` at complete-object `+0x108`; however, generated UID0003VX emits `SpellSlotInputPane::SendSpellSlotPacket(signed char selectedSlot)` without a matching member declaration. R2 therefore adds that helper under `private:` before `m_spellIndex`. Object size `0x10c` still closes through natural tail alignment at `+0x109..+0x10b`; secondary and tertiary facets begin at `+0xa0` and `+0xa4`. A member-function declaration has no object-size effect, and no raw layout filler belongs in R2.

The score-improvement attempt succeeds. Target uncertainty is no longer about behavior, ownership, or source representation; it is a compiler no-code page at `92/94`. The direct source carrier is complete enough for `91/94`. Class source quality improves to `91/94`. Remaining caps are original spelling/access formatting and broader unrelated SpellInputPanes raw-helper debt, not target blockers.

## Evidence Standards Used

- Direct: live IDA MCP function lookup, decompile, disassembly, memory bytes, xrefs, callees, pointer-pattern search, integer reads, decorated names, COL/RTTI data, current canonical docs, and exact file hashes.
- Corroborating: current generated source, validator-owned tracker, current manual coverage, constructor callers, sibling direct/scalar pairs, and executed historical reports.
- Negative: zero direct-start xrefs, zero direct pointer hits, absence of scalar flags in the direct function, absence of source callers to adjustors, and no evidence for alternative owners/files.
- Inferred: final source spellings and access formatting only; each inference is tied to current project declarations and behavior and is score-capped.

## Evidence Checked

- MCP `idb_list`, `server_health`, and binary survey/identity.
- `lookup_funcs` for `0x005b1310`, `0x005b1393`, `0x005b7dc0`, `0x005b7e84`, adjacent constructor/key/scalar functions, adjustors, and helpers.
- `get_bytes` for both complete bodies, four adjacent padding regions, and the full 140-byte SpellSlot vtable/RTTI cluster. An initial client call used the obsolete singular address shape and returned explicit invalid-parameter diagnostics; it supplied no evidence. The corrected `regions`/`addr` calls succeeded with real IDB bytes.
- `decompile` and `disasm` for both destructor variants; instruction totals include external compiler funclet lines and are separated below.
- `xrefs_to` for the direct/scalar functions, both adjustors, and three vtable views; `callees` for both functions; pointer-byte searches for both function starts.
- `get_int` for primary/secondary/tertiary vtable cells, COL pointers, offsets, type descriptor, hierarchy pointer, and base count; `entity_query` for decorated names.
- Current target, parent, constructor, key, submit, retained UID0003VX packet helper, class, file, adjustor, vtable aggregate, ignored ledger, globals, accessor, state setters, base cleanup, generated source, tracker, manual coverage roots, lease ledger, and relevant executed reports. UID0003VX is SHA256 `CCA39D446E2EAF6FA6AAE98487E386ED9F5019B0D26BD053C8CBCD224A42DC12`, 17,176 bytes / 141 lines, and already carries the complete retained helper body and formal.
- During the report-only evidence pass, no IDA mutation, ordinary-file write, validator, lease, report execution, move, archive, count, probe, or lifecycle command was performed. The later Gate-1-authorized callback made only the ordinary edits and validator calls recorded below; B003 still performed no IDA mutation, manual coverage/generated/tracker direct edit, or report lifecycle action.

## Claim And Incorporation Ledger

| ID | Atomic claim | Confidence | Action | Destination | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Database `9b0396a3` was healthy at evidence collection; corrected bounded IDB calls returned real data. | very strong | incorporate | UID0001NG and UID0004UC evidence/history | applied | Both pages record time-bounded session health, PE identity, exact calls/results; UID0004UC clean validator 15312 and target validator 15313 returned exit 0/`ok:1`. |
| C02 | UID0001NG is exactly `[0x005b7dc0,0x005b7e84)`, size `0xc4`/196, body SHA `A293B245A4A4E9E98152A2AD366CA3F666BD4102DF35F1BC939FB29B947B9A28`. | very strong | incorporate | UID0001NG | applied | Implemented target hash `28829F3B...6731`; exact range/size/hash/ABI, 59+8 accounting, callees, routes, and external pads are present; validator 15313 `ok:1`. |
| C03 | UID0001NG is an MSVC scalar-deleting wrapper containing source cleanup expansion plus delete/vptr/base/EH lowering. | very strong | incorporate | UID0001NG, UID0001LN, UID0000DS, UID0000O0 | applied | Target, parent, class, and file distinguish human cleanup from compiler lowering; validators 15313/15314/15318/15319 all exit 0/`ok:1`. |
| C04 | The direct complete destructor is exactly `[0x005b1310,0x005b1393)`, size `0x83`/131, body SHA `0C790092FA101DC253189374C74A67099CCD7F18B0483055A25C37D21E3F525E`. | very strong | incorporate | UID0004UC | applied | Validator 15311 issued UID0004UC; page hash `6BBFCBE0...E3D0` carries exact range/size/hash/ABI/37+7 accounting and R1; clean validator 15312 `ok:1`. |
| C05 | The direct and scalar variants normalize to one source destructor; zero direct xrefs are compiler-variant behavior, not dead-code proof. | very strong | incorporate | UID0001NG and UID0004UC | applied | Both pages contain normalized-body, zero-route, sibling, primary/adjusted-vtable, and source-retention reasoning; validators 15312/15313 passed. |
| C06 | Source branches on `g_useEpfAssets` and fetches `g_pGeneralPurposePanel` child index 3 in either branch. | very strong | incorporate | UID0004UC R1 and evidence | applied | UID0004UC R1 and exact behavior preserve the branch/index; generated line 248 body contains the accepted source once under command 15323. |
| C07 | Current project-consistent state calls are `ItemWhoInputPaneState::SetInputModeFlag(false)` and `SpellInputPaneState::SetInputModeFlag(false)`. | strong | incorporate | UID0004UC R1 and support links | applied | R1 contains both calls exactly once; generated destructor contains the two state calls and no decompiler aliases; validator 15312 passed. |
| C08 | `LineInputPane` cleanup is automatic compiler-emitted base destruction and must not appear as an explicit source call. | very strong | incorporate | UID0001NG, UID0004UC, UID0000DS | applied | All destinations retain the exact base-cleanup fact; R1/R2 omit explicit base destruction, and generated command 15323 contains no explicit target base-destructor call. |
| C09 | Scalar flags, free/guard paths, object size, vptr stores, SEH/cookie/EH, adjustor arithmetic, and raw RTTI/vtables are excluded from human C++. | very strong | incorporate | UID0001NG R0 and compiler-support docs | applied | R0/R4/R5 are blank; generated target has zero UID0001NG/range, vptr, delete, guard, adjusted-address, EH/cookie, or raw table implementation. |
| C10 | Primary vtable cell `0x0062f670` and `-0xa0`/`-0xa4` adjustors prove virtual destructor liveness and exact class ownership. | very strong | incorporate | UID0001NG, UID0001N9, UID00026W | applied | Exact cells/routes/offsets/source causes appear in all three; validators 15313/15320/15321 returned `ok:1`. |
| C11 | UID0000DS remains canonical class owner and UID0000O0 remains source file/emitter route. | very strong | already-present | target/new child/class/file | already-present | Headers/readback preserve target/new-child owner 0000DS and class/file route 0000O0; command 15323 emits UID0004UC through the established source root. |
| C12 | UID0001NG is false/non-emitting with blank R0, preventing duplicate human source. | very strong | incorporate | UID0001NG | applied | Header is `92/94`, false, blank emitter/position/R0; validator 15313 updated registry; generated command 15323 has zero UID0001NG body/marker. |
| C13 | UID0004UC is the sole target-specific source carrier at `91/94`, owner/emitter `0000DS`, true, blank position, `Nested:0`, exact R1. | very strong | incorporate | UID0004UC | applied | Registration 15311 issued UID0004UC; clean 15312 passed; header/formal are exact and command 15323 emits its marker/destructor once. |
| C14 | UID0001LN inventories UID0004UC in address order while retaining `90/93`, `Nested:-4`, R3 blank, all nineteen internal pads, real UID0004TY/UID0004UB children, and the complete B001/B003 union. | very strong | incorporate | UID0001LN and by-memory/-ignored.md | applied | Parent hash `9251820B...AE5`, validator 15314; UID0004UC lies between LV/LW, all nineteen pads and B001 children persist. Ignored validator 15322 adds only two external spans and reports `ok:1` plus 247 pre-existing warnings. |
| C15 | Pre-callback UID0000DS was layout-complete but omitted the member declaration for the already-emitted UID0003VX `SendSpellSlotPacket(signed char)` definition; complete R2 closes that interface. | very strong | incorporate | UID0000DS R2 | applied | Class hash `89A2C794...5D77`, `91/94`, exact R2; validator 15318 passed. Generated declaration line 234/class close 237 precede unchanged UID0003VX definition line 309. |
| C16 | UID0000O0 records the SpellSlot direct source destructor versus scalar/adjustor/vtable compiler split without losing current family content. | strong | incorporate | UID0000O0 | applied | File hash `3C6E444E...C1A2` retains `92/94`/route and full B001/B003 union; validator 15319 and waited 15323 passed. |
| C17 | UID0001LV/LW/LX need bounded direct/scalar links/history only, while UID0003VX's existing helper page/body/formal remain already present at same-or-greater detail and require only the matching declaration in R2. | strong | incorporate | UID0001LV, UID0001LW, UID0001LX, UID0003VX verification, UID0000DS R2 | applied | Validators 15315/15316/15317 passed after prose-only links; scores/metadata/formals remain unchanged. UID0003VX remains byte-for-byte SHA `CCA39D44...C12`; generated declaration/definition pair is complete. |
| C18 | UID0001N9 remains compiler-only `86/90` with blank R4, and its stale reconstructable-scalar sentence is historicalized. | very strong | historicalize | UID0001N9 | applied | Hash `065C6869...AFDF`; all twelve thunks/metadata/R4 persist, SpellSlot routes/source child are exact, stale blanket wording is historical; validator 15320 passed. |
| C19 | UID00026W remains compiler-only at B001-applied `91/94` with blank R5 and includes exact SpellSlot tables/COL/slot/direct/scalar provenance without raw arrays. | very strong | incorporate | UID00026W | applied | Hash `ADAD410C...5881`; exact `0x8c` slice, three COLs, eight-base RTTI, slots/routes/source cause added without loss; validator 15321 passed and generated source contains no raw arrays. |
| C20 | Exact ordinary score and metadata changes reflect closed source/compiler provenance without overstating inferred names. | strong | incorporate | target/new child/parent/class/file/adjustor/vtable ordinary pages | applied | Ordinary headers/hashes match every accepted score, owner, emitter, reconstructable, position, nesting, and formal disposition; scoped validators 15312-15322 and waited command 15323 prove the applied ordinary state. |
| C21 | The exact B003 manual coverage handoff remains supervisor-owned and unapplied over the current 23-row B005 union. | strong | not-applicable | `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md` | excluded-with-reason | B003 is prohibited from editing manual coverage. Current hashes `4BB897EE...B220`, `B666A61C...1255`, and `63FFCA85...006C` prove all B005 rows are present while UID0004UC/two scalar pads remain absent and UID0001LN/UID0001N9/UID0001NG/UID00026W/UID0000DS/UID0000O0 retain the stale states addressed by the exact unapplied handoff below. |

## Positive Evidence Summary

- Exact bytes independently delimit the direct and scalar functions and all four adjacent alignment spans.
- Direct ABI is `void __thiscall(this)` with no flags; scalar ABI adds a hidden flag argument, return pointer, storage-release tail, and guarded-size path.
- Both variants use identical class vptr views, mode branch, child index, state setters, and base cleanup.
- Primary and adjusted vtable routes prove virtual deletion liveness and class ownership.
- Decorated names and RTTI/COL data prove `SpellSlotInputPane`, secondary offsets `0xa0`/`0xa4`, and an eight-base hierarchy.
- Current globals, accessor, setters, base docs, and UID0003VX body close the source name/type/body blockers. Generated readback exposes the remaining declaration blocker precisely, and complete R2 closes it with a private source-era member declaration.
- Existing constructor callers and inlined construction prove the class is live independently of the direct destructor's zero xrefs.

## IDA MCP Facts

| Fact | Live result |
| --- | --- |
| Database | `9b0396a3`, worker PID 15732 at evidence collection |
| Health | `ok`; analysis, Hex-Rays, strings ready |
| PE identity | NexusTK.exe, image base `0x00400000`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632` |
| Scalar wrapper | `sub_5B7DC0`, `0xc4`/196, SHA `A293B245A4A4E9E98152A2AD366CA3F666BD4102DF35F1BC939FB29B947B9A28` |
| Direct destructor | `sub_5B1310`, `0x83`/131, SHA `0C790092FA101DC253189374C74A67099CCD7F18B0483055A25C37D21E3F525E` |
| Direct disassembly | 37 in-body instructions plus 7 external SEH/cookie handler lines, 44 reported total |
| Scalar disassembly | 59 in-body instructions plus 8 external terminate/SEH/cookie lines, 67 reported total |
| Direct callees | `0x004b85f0`, `0x0057d0a0`, `0x0057c430`, `0x004f2010` |
| Scalar-only extra callees | `0x004f4ac0`, guard helper `0x0041b6a0` |
| Direct xrefs/pointer hits | zero exact-start xrefs; zero stored `10 13 5b 00` hits |
| Scalar routes | jumps from `0x005b78aa`/`0x005b78b5`; data xref `0x0062f670` |
| Adjustor routes | `0x005b78a4` from `0x0062f6c0`; `0x005b78af` from `0x0062f6f0` |
| Vtable cluster | `[0x0062f66c,0x0062f6f8)`, 140 bytes, SHA `F36ED34FA58FAD3E07BBD262A52B796E7A933BC8DF5A9E99944087F6896176A4` |
| COL/RTTI | locators `0x00652898`, `0x006528fc`, `0x00652910`; offsets `0`, `0xa0`, `0xa4`; type descriptor `0x00679e68`; hierarchy `0x006528ac`; 8 bases |

## Function / Child Inventory

| Address range | Identity | UID | Role | Recommended status |
| --- | --- | --- | --- | --- |
| `[0x005b1280,0x005b130d)` | SpellSlotInputPaneConstructor | 0001LV | source constructor | preserve `89/93`, R/body/metadata; bounded link only |
| `[0x005b130d,0x005b1310)` | alignment | 0000VN/-ignored | 3 `0xcc`, SHA `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE` | existing parent-only span, preserve |
| `[0x005b1310,0x005b1393)` | SpellSlotInputPaneDestructor | 0004UC | source complete destructor carrier | registered `91/94`, R1, `Nested:0` |
| `[0x005b1393,0x005b13a0)` | alignment | 0000VN/-ignored | 13 `0xcc`, SHA `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE` | existing parent-only span, preserve |
| `[0x005b13a0,0x005b140c)` | SpellSlotInputPaneHandleKeyOrTextEvent | 0001LW | source virtual Event handler | preserve `91/93`, bounded link only |
| `[0x005b140c,0x005b1410)` | alignment | 0000VN/-ignored | 4 `0xcc` | existing parent-only span, preserve |
| `[0x005b1410,0x005b14e6)` | SpellSlotInputPaneSubmitSpellSlot | 0001LX | source submitter | preserve `89/91`, bounded link only |
| `[0x005b14e6,0x005b14f0)` | alignment | 0000VN/-ignored | parent-external successor pad | preserve outside UID0001LN |
| `[0x005b14f0,0x005b1568)` | SpellSlotDirectSlotPacketRaw | 0003VX | retained no-route helper | preserve `87/89`, body/formal/metadata; declare it privately in R2 |
| `[0x005b10c0,0x005b1143)` | SpellOneArgInputPaneDestructor | 0004UB | current adjacent source destructor child | preserve B001-applied `91/94`, body/formal/metadata, `Nested:0` |
| `[0x005b7cf0,0x005b7db4)` | SpellOneArg scalar wrapper | 0001NF | predecessor compiler wrapper whose source child is UID0004UB | preserve B001-applied `92/94`, false/non-emitting, blank formal |
| `[0x005b7db4,0x005b7dc0)` | alignment | 0000VN/-ignored | 12 `0xcc`, SHA `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902` | implemented parentless compiler-family pad |
| `[0x005b7dc0,0x005b7e84)` | SpellSlot scalar wrapper | 0001NG | compiler wrapper | `92/94`, false, non-emitting, R0 blank |
| `[0x005b7e84,0x005b7e90)` | alignment | 0000VN/-ignored | 12 `0xcc`, same SHA | implemented parentless compiler-family pad |
| `[0x005b7e90,0x005b7f54)` | SpellString scalar wrapper | 0001NH | successor compiler wrapper | verify-only |
| `[0x005b78a4,0x005b78af)` | SpellSlot secondary adjustor | 0001N9 aggregate | compiler thunk `this-0xa0` | blank R4, no source |
| `[0x005b78af,0x005b78ba)` | SpellSlot tertiary adjustor | 0001N9 aggregate | compiler thunk `this-0xa4` | blank R4, no source |
| `[0x0062f66c,0x0062f6f8)` | SpellSlot RTTI/vtable cluster | 00026W aggregate | compiler data | blank R5, no raw arrays |

Relative nesting is proved from the actual address-sorted family rows. UID0001LN stays `Nested:-4`; first same-start child UID0001LM already carries `Nested:4`; every later child, including UID0004UC, stays `Nested:0`; successor UID0001LY remains outside this target relation. A new child count is not a nesting increment.

## Direct Xref / Caller Inventory

| Target | Exact route | Meaning |
| --- | --- | --- |
| `0x005b1310` | zero exact-start xrefs and zero stored pointer hits | out-of-line complete destructor variant has no direct static consumer; not dead-source proof |
| `0x005b7dc0` | `0x0062f670 -> 0x005b7dc0` | primary virtual scalar-deleting-destructor slot |
| `0x005b7dc0` | jump at `0x005b78aa` from function `0x005b78a4` | `this-0xa0` adjusted-view deletion |
| `0x005b7dc0` | jump at `0x005b78b5` from function `0x005b78af` | `this-0xa4` adjusted-view deletion |
| `0x005b78a4` | sole data xref `0x0062f6c0` | secondary table owns adjustor |
| `0x005b78af` | sole data xref `0x0062f6f0` | tertiary table owns adjustor |
| `0x005b1280` | constructor calls from functions `0x0057c9b0`, `0x0057e2d0`, `0x0057f030` | live class construction from spell inventory flows |
| constructor-equivalent inline sequence | inside `0x005a4530` | compiler-inlined UserPane command-slot construction; not a duplicate source constructor |

The primary vtable also contains submit slot `0x0062f6b8 -> 0x005b1410`; the secondary table contains key/Event slot `0x0062f6c8 -> 0x005b13a0`. These source virtuals, constructor stores, and deletion slots form one coherent class.

## Documentation Evidence And IDA Status

- Historical pre-callback UID0001NG described the scalar wrapper as a reconstructable source carrier and emitted the human destructor. The implemented page preserves its useful range/behavior evidence but is now `92/94`, false/non-emitting, blank-emitter, and blank R0; command 15323 emits neither its body nor an Empty Emitter Marker.
- Historical pre-callback UID0001LN was already B001-rebased `90/93`, false/non-emitting, `Nested:-4`, blank formal, with all nineteen parent-internal spans and UID0004TY/UID0004UB, but it lacked an exact SpellSlot child. The implemented parent preserves that complete union and now inventories validator-issued UID0004UC in address order at `Nested:0`.
- Historical pre-callback UID0000DS was `90/93` and omitted the private `SendSpellSlotPacket(signed char selectedSlot)` declaration required by UID0003VX. The implemented class is `91/94`, retains the public virtual destructor, exact inheritance/layout/class closure/`[[CHILDREN]]`, installs complete R2, and records direct/scalar/adjustor/vtable provenance.
- UID0000O0 remains `92/94`. Its implemented source/compiler inventory now adds the exact UID0004UC direct-child route and UID0001NG/UID0001N9/UID00026W compiler split while preserving the complete B001/B003 family union.
- UID0001N9 remains false/non-emitting compiler support at `86/90`; its former blanket claim that scalar deleting destructors remain reconstructable owner methods is now explicitly historical for the accepted FourArgs/OneArg/SpellSlot splits, and its twelve-thunk inventory and blank R4 remain intact.
- UID00026W remains B001-rebased `91/94`, false/non-emitting, and blank-formal. It now includes the exact SpellSlot table/COL/direct/scalar/adjustor provenance alongside the preserved FourArgs/OneArg and unrelated bands.
- The ignored ledger still preserves all B001 UID0004UB/UID0004TY and parent-internal content and now also contains exact target-external scalar pads `[0x005b7db4,0x005b7dc0)` and `[0x005b7e84,0x005b7e90)` without absorbing either into UID0001LN.
- Historical pre-callback generated command 15307 attributed the destructor to UID0001NG and omitted the UID0003VX member declaration. Current callback command 15323 closes the class before definitions, declares the private member, emits the UID0004UC destructor and unchanged UID0003VX definition once each, and has zero UID0001NG body/marker.

## Ranked Ownership Analysis

1. **UID0000DS SpellSlotInputPane class**: canonical semantic owner. Decorated vtable names, constructor stores, direct/scalar vptr restores, adjusted views, field layout, and virtual slots all agree.
2. **UID0000O0 SpellInputPanes file**: canonical source placement/emitter route. Constructor, destructor, Event handler, submitter, and retained slot helper form one spell-input source family.
3. **UID0001LN SpellArgumentInputPanes parent index**: exact address-order inventory owner for the direct source child, not the emitter.
4. **UID000077 LineInputPane/InputPanes**: inherited cleanup dependency only. It owns `0x004f2010`, not the derived state clear or SpellSlot vtables.
5. **GeneralPurposePanel, ItemWhoInputPaneState, SpellInputPaneState**: called dependencies. Their methods and globals close source names; they do not own the destructor.
6. **SpellInventoryPane/UserPane caller families**: construction/caller evidence only. They do not own this class's source definition.

## Source Placement

- Source directory: `NexusTK/ui/dialogs/`.
- Source file: `NexusTK/ui/dialogs/SpellInputPanes.cpp`, represented by UID0000O0.
- Header/class declaration: UID0000DS `SpellSlotInputPane`, installing complete R2 with the private retained-helper declaration and preserving the existing public API, layout, and class closure.
- Sole human definition: UID0004UC, emitted through UID0000DS after the class-closing `};` and `[[CHILDREN]]` expansion.
- Compiler products: UID0001NG scalar wrapper, UID0001N9 adjustors, UID00026W vtable/RTTI, vptr restores, base destructor calls, cookies/EH, scalar flags, storage release, and guarded delete.
- Rejected file placements: `InputPanes.cpp` owns the base; `GeneralPurposePanel.cpp` owns the singleton/accessor; `TargetSelectionInputPanes.cpp` owns state setters; `SpellInventoryPane.cpp` owns callers. None owns the SpellSlot destructor definition.

## Range / Split / Padding / Reclassification Analysis

- Direct function range is exact: `lookup_funcs(0x005b1310)` gives size `0x83`; `0x005b1393` is not a function; 131 live bytes hash to `0C790092FA101DC253189374C74A67099CCD7F18B0483055A25C37D21E3F525E`.
- Direct predecessor `[0x005b130d,0x005b1310)` is exactly three `0xcc`; direct successor `[0x005b1393,0x005b13a0)` is exactly thirteen `0xcc`. Both remain parent-internal ignored padding and must not be absorbed.
- Scalar function range is exact: `lookup_funcs(0x005b7dc0)` gives size `0xc4`; `0x005b7e84` is not a function; 196 live bytes hash to `A293B245A4A4E9E98152A2AD366CA3F666BD4102DF35F1BC939FB29B947B9A28`.
- Scalar predecessor `[0x005b7db4,0x005b7dc0)` and successor `[0x005b7e84,0x005b7e90)` are each twelve `0xcc`, each SHA `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`. They are target-external compiler-family alignment and were added to the ignored ledger by validator 15322.
- Do not merge direct and scalar ranges: they are non-contiguous compiler variants with distinct hidden ABIs and source roles.
- Do not split either function internally: branches, helper calls, EH prologue/epilogue, and return paths are one modeled function each.
- Reclassification is source-preserving: target changes to no-code compiler support only because the new exact direct child becomes the source carrier.
- Parent `Nested:-4`, first child `Nested:4`, later children `Nested:0`, and successor state are retained. The new page receives `Nested:0` from its real address-sorted position.

## Negative Evidence Summary

- No direct code/data xref or pointer literal names `0x005b1310`; therefore no direct caller can be claimed.
- No evidence supports deleting or suppressing the direct body: six sibling pairs, identical normalized cleanup, and compiler ABI explain the no-route state.
- No scalar flag, free, guard, object-size path, or pointer return occurs in the direct body.
- No source-facing need exists for explicit `LineInputPane::~LineInputPane()`, vptr assignments, `operator delete`, guard calls, cookie checks, SEH/EH handlers, or adjusted-this wrappers.
- No evidence supports `LineInputPane`, GeneralPurposePanel, state classes, SpellInventoryPane, or UserPane as source owner.
- No padding byte belongs inside either function, and no adjacent source method belongs inside the target range.
- No original source/PDB symbol proves every inferred helper/member spelling; confidence remains below 95.
- The report-only evidence-time coordination read found no active B001-B005 target collision. Callback work then used serial leases, and final lease-ledger readback shows zero B003 leases.

## IDA Rename / Type / Comment Recommendations

- UID0004UC now documents `sub_5B1310` as `SpellSlotInputPane::~SpellSlotInputPane` / `SpellSlotInputPaneDestructor`; this is source-facing documentation and no IDA mutation was performed.
- UID0001NG remains documented as `SpellSlotInputPaneScalarDeletingDestructor`, a compiler wrapper returning the original `this` and consuming hidden delete flags.
- The direct semantic ABI is recorded as `void __thiscall(SpellSlotInputPane *this)` and the scalar binary ABI as `SpellSlotInputPane *__thiscall(SpellSlotInputPane *this, unsigned char flags)` in prose only. Human source declares only `virtual ~SpellSlotInputPane()`.
- `g_useEpfAssets`, `g_pGeneralPurposePanel`, `GeneralPurposePanel::GetChildPaneByIndex(int)`, `ItemWhoInputPaneState::SetInputModeFlag(bool)`, and `SpellInputPaneState::SetInputModeFlag(bool)` remain the best project-consistent source names.
- Vtable view offsets `+0xa0` and `+0xa4`, object size `0x10c`, and direct/scalar normalization are documented in evidence rather than emitted as raw offset comments in formal C++.
- UID0001N9 now historicalizes the stale blanket scalar-source statement; unrelated thunks and sibling pages were not renamed.

## First-Draft C++ Recommendation

### R0 - UID0001NG target compiler wrapper

Destination: `by-memory/0x005b7dc0-0x005b7e84.SpellSlotInputPaneScalarDeletingDestructor.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R1 - UID0004UC direct source destructor

Destination: `by-memory/0x005b1310-0x005b1393.SpellSlotInputPaneDestructor.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SpellSlotInputPane::~SpellSlotInputPane()
{
    if (g_useEpfAssets) {
        static_cast<ItemWhoInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
    } else {
        static_cast<SpellInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R2 - UID0000DS class declaration

Destination: `by-class/SpellSlotInputPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SpellSlotInputPane : public CharInputPane
{
public:
    explicit SpellSlotInputPane(char spellIndex);
    virtual ~SpellSlotInputPane();

    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void SubmitSpellSlot();

private:
    void SendSpellSlotPacket(signed char selectedSlot);

    char m_spellIndex;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R3 - UID0001LN parent index

Destination: `by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R4 - UID0001N9 adjustor aggregate

Destination: `by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R5 - UID00026W vtable aggregate

Destination: `by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R0/R3/R4/R5 are deliberately empty. R2 preserves the current class declaration and adds only the missing private declaration for the already-present UID0003VX source definition. R1 is the only new human source definition. No draft/example C++ exists outside these formal destination blocks.

## Final Recommendation

The split, source-carrier correction, and bounded class-interface closure are implemented. UID0004UC was registered first and every provisional token was replaced before dependent ordinary edits. Waited command 15323 proves exactly one `SpellSlotInputPane::~SpellSlotInputPane()` definition from the direct child, one private `SendSpellSlotPacket(signed char selectedSlot)` declaration before class closure, the unchanged UID0003VX definition exactly once after class closure, no UID0001NG body or Empty Emitter Marker, no wrong-range target marker, and no handwritten target compiler artifacts. All unrelated SpellInputPanes content is preserved.

## Recommended Target Doc Changes

Implemented in `by-memory/0x005b7dc0-0x005b7e84.SpellSlotInputPaneScalarDeletingDestructor.md`:

- Applied `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000DS`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position, `Nested:0`, and exact blank R0.
- Applied Item Summary: `Exact 0xc4 MSVC SpellSlotInputPane scalar-deleting-destructor wrapper with three vptr restores, source-destructor cleanup expansion, LineInputPane base cleanup, scalar/guarded delete flags, two secondary-base adjustor routes, primary vtable route, exact surrounding alignment, and blank human C++ because UID0004UC owns the source destructor.`
- Incorporated exact range/size/body hash, 59+8 instruction accounting, hidden ABI, callees, xrefs, primary/adjusted routes, normalized source behavior, compiler exclusions, both external pads, positive/negative evidence, source-cause link, rejected alternatives, score rationale, and historical correction.
- Preserved exact owner, range, position, nesting, behavior, helper calls, and prior evidence; historicalized only the stale source-emitter conclusion.

## Recommended Support Doc Changes

The following accepted support changes are implemented; each bullet preserves the accepted no-loss specification and its current disposition.

- Created/registered `by-memory/0x005b1310-0x005b1393.SpellSlotInputPaneDestructor.md` as UID0004UC: `91/94`, owner/emitter UID0000DS, true, blank optional position, `Nested:0`, exact R1, range/size/hash, 37+7 instruction accounting, zero direct xrefs/pointer hits, normalized source body, compiler exclusions, padding, vtable/class/source relationship, rejected alternatives, and score rationale. Item Summary: `Exact 0x83 SpellSlotInputPane complete destructor with three class vptr restores, g_useEpfAssets state-object selection, general-purpose-panel child index 3 lookup, input-mode clear through accepted state types, compiler-emitted LineInputPane base cleanup, exact boundary padding, normalized scalar-wrapper relationship, and human R1 excluding all compiler mechanics.`
- UID0001LN preserved B001-applied `90/93`, owner UID0000O0, false, blank emitter/position, `Nested:-4`, exact R3, real UID0004TY/UID0004UB source-destructor children, every existing child/raw-helper/history fact, and all nineteen internal pads; issued UID0004UC was inserted between UID0001LV and UID0001LW, and UID0001NG is identified as the non-contiguous compiler wrapper.
- UID0001LV preserved `89/93`, all metadata, R body, range, callers, and `Nested:0`; only the exact successor direct-destructor link and source/scalar history were added.
- UID0001LW preserved `91/93`, all metadata, R body, range, Event behavior, vtable route, and `Nested:0`; only predecessor direct-destructor/padding and scalar-wrapper relationship prose was added.
- UID0001LX preserved `89/91`, all metadata, R body, range, packet behavior, route, retained helper, and `Nested:0`; only bounded class direct/scalar lifecycle link/history was added.
- UID0000DS was raised `90/93 -> 91/94` while preserving owner/emitter UID0000O0, true, blank position, public destructor access, inheritance, 0x10c layout, `m_spellIndex`, every existing method, and class closure; exact R2 adds the private `SendSpellSlotPacket(signed char selectedSlot)` declaration required by UID0003VX plus exact direct/scalar/adjustor/vtable/COL provenance and compiler exclusions.
- UID0003VX remains byte-for-byte unchanged at `87/89`, owner/emitter UID0000DS, true, blank position, `Nested:0`, with its exact range, Item Summary, retained no-route evidence, packet behavior, and formal definition. Callback verification proves implemented R2 declares that existing qualified definition.
- UID0000O0 preserved `92/94`, source path/route, all existing classes/methods/helpers/history, current UID0004TY/UID0004UB direct-destructor union, and generated union; the exact SpellSlot direct source destructor and scalar/adjustor/vtable compiler split were added.
- UID0001N9 preserved `86/90`, owner none, false, blank emitter/position/R4, `Nested:0`, all twelve thunks/ranges, and B001's exact OneArg correction; its historicalized blanket scalar-source statement now includes the exact SpellSlot source-child/compiler-wrapper disposition.
- UID00026W preserved B001-applied `91/94`, owner none, false, blank emitter/position/R5, `Nested:0`, all existing bands/children and exact FourArgs/OneArg slices; the full SpellSlot cluster `[0x0062f66c,0x0062f6f8)`, SHA, primary/secondary/tertiary cells, COL offsets, eight-base RTTI, constructor/direct/scalar/adjustor/method links, and no-raw-array source cause were added.
- `by-memory/-ignored.md` preserved every existing row and the UID0004TY/UID0004UB owner/readback union, then added exactly `[0x005b7db4,0x005b7dc0)` and `[0x005b7e84,0x005b7e90)` as twelve-byte `0xcc` scalar-family alignment. The existing nineteen parent-internal spans and parent-external `[0x005b14e6,0x005b14f0)` are unchanged.
- Verify-only support remained unchanged absent exact contradiction: UID0001NF/UID0004UB, UID0001NH, sibling direct/scalar pages, UID00015W, UID0001IJ, UID0001II, UID00035Q, globals, state classes, CharInputPane, LineInputPane, and Event/helper APIs. UID0003VX also remained verify-only as an ordinary page while its unchanged formal definition triggered the R2 declaration addition above.

## Score And Metadata Recommendation

| Destination | Pre-callback | Implemented | Exact metadata/disposition rationale |
| --- | ---: | ---: | --- |
| UID0001NG target | `86/90` | `92/94` | Exact compiler wrapper fully resolved; owner retained, false/non-emitting, blank R0, position blank, Nested 0. |
| UID0004UC | absent | `91/94` | Exact complete-destructor source carrier with complete R1; owner/emitter 0000DS, true, blank position, Nested 0. |
| UID0001LN parent | current `90/93` after B001 | unchanged | SpellSlot child closes the next inventory gap while preserving UID0004TY/UID0004UB; broader family/raw-helper/source debt remains; false, blank R3, Nested -4. |
| UID0000DS class | `90/93` | `91/94` | Exact direct/scalar/vtable provenance and the missing private UID0003VX helper declaration close class source quality without changing layout. |
| UID0003VX helper | `87/89` | unchanged | Exact retained no-route body/formal/metadata already present; declaration closure belongs only in UID0000DS R2. |
| UID0000O0 file | `92/94` | unchanged | Exact source placement already strong; broader family debt caps completion. |
| UID0001LV | `89/93` | unchanged | Constructor already source-ready; only relation prose changes. |
| UID0001LW | `91/93` | unchanged | Event handler already source-ready; only relation prose changes. |
| UID0001LX | `89/91` | unchanged | Submitter retains independent packet-name/type debt. |
| UID0001N9 | `86/90` | unchanged | Compiler thunk evidence complete enough for current score; only stale disposition prose changes. |
| UID00026W | current `91/94` after B001 | unchanged | Exact compiler-data aggregate remains no-code; preserve FourArgs/OneArg slices and add SpellSlot provenance without inflating broad unrelated bands. |

Scores stay below 95 because original source symbols are absent and helper/member spellings remain inferred. No low-confidence name is disguised as binary fact.

## Open Questions With Attempted Resolution

1. **Does `0x005b1310` require a dedicated page?** Yes. It is a modeled exact function between two proved parent-internal pads, has a complete destructor ABI/body, and is the sole source carrier after scalar-wrapper reclassification.
2. **Is the direct function dead because it has zero xrefs?** No. The compiler-family pair pattern, complete-destructor ABI, identical normalized cleanup, live class construction, and virtual scalar route explain the zero route. Record zero xrefs without suppressing source.
3. **Should UID0001NG remain reconstructable to carry the destructor?** No. Doing so after creating the direct child duplicates one human definition and misattributes hidden delete machinery.
4. **Are helper/global/type names sufficient for human source?** Yes at 91/94. Current project docs and generated interfaces agree on the exact names in R1; original spelling uncertainty remains score-capped.
5. **Should the source call the base destructor explicitly?** No. C++ automatically destroys `CharInputPane`/`LineInputPane`; `0x004f2010` remains evidence only.
6. **Does the class declaration need raw facet fields or padding arrays?** No. Inheritance generates `+0xa0/+0xa4` facets; natural alignment closes `+0x109..+0x10b`.
7. **Did UID0003VX require declaration work in this callback?** Yes, but only in UID0000DS R2. Its existing `SendSpellSlotPacket(signed char)` qualified definition, exact body, metadata, and retained no-route disposition were already complete; the implemented private member declaration makes generated C++ source-legal without rewriting the helper or submitter.
8. **Does adding a child change relative Nested levels?** No. The first same-start child remains +4; this later child is 0; parent remains -4.
9. **Do scalar-family pads belong to UID0001LN?** No. They are non-contiguous target-external compiler alignment and belong only in the ignored ledger/manual padding handoff.
10. **Is another owner/file plausible?** No evidence survived the ranked owner analysis. Dependencies and callers do not supersede decorated class/source-family ownership.
11. **Does broader raw-helper debt block this target?** No. It caps parent/file scores but does not block the exact destructor source split or the exact UID0003VX declaration closure.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B003 does not edit manual coverage. Historical pre-B005 read-only snapshots were by-memory SHA256 `0029ACDD1B73898BBF33DC3642863D79AC6A24FA671E79E6481D7B0D2A0318C0`, 1,844,228 bytes / 4,381 lines; by-class `F74CD4B66D71702A16EACF336B7318924F65F9D7DDC1313F07263391724AEC27`, 239,835 / 623; and by-file `0C87AAAC6D0F7E87097E5A57A651D25FD1C2AA474C1429A4FF70E884F5027497`, 138,245 / 316. Supervisor commands 15326-15328 applied B005 UID00030F's exact 23-row handoff, and external execute command 15329 established the current read-only union: by-memory SHA256 `4BB897EEA5814100C46905500DC1A1B88A9F7EEA96DDE498B11812FB9594B220`, 1,849,192 bytes / 4,393 lines; by-class `B666A61C1F5F728E10C1F80B7B2354AF9B4CABF240B55CA7CC1281D7D3321255`, 239,187 / 623; by-file `63FFCA8568BF47DAE6D311DC4044A1001A896B7A619F87471CDF5DABFFCF006C`, 137,424 / 316. Unchanged read-only roots are by-global `4F96E6C2DE7E9BDCDEA2537579EF1D2CE1C0884E421B1D29D23757A8913BD97D`, 90,566 / 213; by-item `66C86AAFBA920F09B29B5E6C5B1C5E477255362F2A4A2A009402DA8428079EA6`, 28,963 / 87; and by-type/by-struct `FEB144165B08A72402ED071C1C359C7A9BCE12A93541B84C2721A1D477805AE0`, 57,041 / 137. Those three have no affected row.

The current manual union preserves all 23 externally applied B005 rows exactly, and none overlaps a B003 Spell replacement/insertion below. The eighteen by-memory actions are UID0001JM, UID00030F, padding `[0x00590dc5,0x00590dd0)`, UID0004TZ, padding `[0x00590dd5,0x00590de0)`, UID0004T8, UID0004U1, padding `[0x00591c65,0x00591c70)`, UID0001JS, UID0004U3, UID0004U5, UID0004U7, UID0004U8, UID0004U9, UID0004UA, UID0001JT, UID0003DV, and UID0001JO. The three by-class rows are UID00004L Event, UID0000EO TextEditPane, and UID0000EP TextEditScrap; the two by-file rows are UID0000J6 Event and UID0000ON TextEditPane. The exact current row text in those roots is the no-loss base and must remain byte-for-byte unchanged when the independent B003 handoff is applied.

### by-memory/-coverage-report.md

Current post-B005 anchors: UID0001LN line 3598; UID0001LV 3608; UID0001LW 3609; UID0001LX 3610; UID0001N9 3694; UID0001NF 3702; UID0001NG 3703; UID0001NH 3704; UID00026W 4066. The B005 insertions shifted these by-memory anchors by twelve lines but did not change any Spell row or neighboring Spell text. The Spell rows still predate B001/B003's applied ordinary UID0004UB/parent/vtable/direct-destructor union, so the exact replacements below preserve those newer ordinary facts, retain all 18 B005 by-memory rows above, and add B003's SpellSlot facts in one no-loss handoff. UID0004UC and both scalar padding rows remain absent. UID0003VX also has no manual by-memory row, but no row is proposed in this bounded report because its path, title, `87/89` score, reconstructable/owner/emitter metadata, formal definition, and source-quality description remain unchanged; only UID0000DS R2 receives its missing declaration.

Replace UID0001LN with:

`    - [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md) 0x005b0780-0x005b14e6 | non-emitting class-method aggregate | SpellArgumentInputPanes : not_reconstructable : 90% : very-strong : Exact spell argument input-pane split index with five signed one-byte prompt constructors, exact SpellFourArgsInputPane, SpellOneArgInputPane, and SpellSlotInputPane source-destructor children UID0004TY/UID0004UB/UID0004UC, confirm/submit children, nineteen parent-internal padding spans, direct/scalar/adjustor/vtable and no-route raw-helper inventory, three inventory callers plus compiler-inlined UserPane construction, SpellInputPanes ownership, and blank aggregate C++ because exact children own source bodies.`

Insert validator-issued UID0004UC immediately after UID0001LV and before UID0001LW:

`    - [UID:0004UC][0x005b1310-0x005b1393.SpellSlotInputPaneDestructor](by-memory/0x005b1310-0x005b1393.SpellSlotInputPaneDestructor.md) 0x005b1310-0x005b1393 | destructor | SpellSlotInputPaneDestructor : reconstructable : 91% : very-strong : Exact 0x83 SpellSlotInputPane complete destructor with three class vptr restores, g_useEpfAssets state-object selection, general-purpose-panel child index 3 lookup, input-mode clear through accepted state types, compiler-emitted LineInputPane base cleanup, exact boundary padding, normalized scalar-wrapper relationship, and human C++ excluding all compiler mechanics.`

Replace UID0001N9 with:

`    - [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) 0x005b7878-0x005b78fc | compiler destructor-adjustor aggregate | SpellInputPaneAdjustorThunks : ignored : 86% : very-strong : Exact twelve 0xb MSVC this-adjusting destructor thunks for six spell input-pane classes, paired -0xa0/-0xa4 adjustments, sole vtable data routes, scalar-wrapper tail jumps, exact UID0004TY/UID0004UB/UID0004UC source-destructor child provenance for FourArgs/OneArg/SpellSlot, and blank formal C++ because class inheritance/destructors regenerate the glue.`

Insert after UID0001NF and before UID0001NG:

`    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005b7db4-0x005b7dc0 | padding | SpellOneArg scalar wrapper to SpellSlot scalar wrapper alignment : ignored : 100% : strong : Exact twelve 0xcc bytes, SHA256 A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902.`

Replace UID0001NG with:

`    - [UID:0001NG][0x005b7dc0-0x005b7e84.SpellSlotInputPaneScalarDeletingDestructor](by-memory/0x005b7dc0-0x005b7e84.SpellSlotInputPaneScalarDeletingDestructor.md) 0x005b7dc0-0x005b7e84 | compiler scalar-deleting-destructor wrapper | SpellSlotInputPaneScalarDeletingDestructor : not_reconstructable : 92% : very-strong : Exact 0xc4 MSVC SpellSlotInputPane scalar-deleting-destructor wrapper with three vptr restores, source-destructor cleanup expansion, LineInputPane base cleanup, scalar/guarded delete flags, two secondary-base adjustor routes, primary vtable route, exact surrounding alignment, and blank human C++ because UID0004UC owns the source destructor.`

Insert after UID0001NG and before UID0001NH:

`    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005b7e84-0x005b7e90 | padding | SpellSlot scalar wrapper to SpellString scalar wrapper alignment : ignored : 100% : strong : Exact twelve 0xcc bytes, SHA256 A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902.`

Replace UID00026W with:

`    - [UID:00026W][0x0062ef0c-0x006307ec.UserPaneInputVtables](by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md) 0x0062ef0c-0x006307ec | compiler vtable-data aggregate | UserPaneInputVtables : ignored : 91% : very-strong : Parentless mixed-owner vtable inventory with exact source-local children; SpellFourArgsInputPane, SpellOneArgInputPane, and SpellSlotInputPane slices each have three views, COL offsets 0/0xa0/0xa4, eight-base RTTI hierarchies, constructor/direct-destructor/scalar/adjustor/virtual-method provenance, and blank formal because class declarations regenerate tables without raw arrays.`

UID0001LV, UID0001LW, and UID0001LX rows remain exact and need no manual replacement because their scores, paths, formal dispositions, and row-level summaries do not change. Their ordinary pages receive only bounded relationship prose.

### by-class/-coverage-report.md

Current UID0000DS is unique at line 517, unchanged by the B005 class-row replacements at UID00004L/UID0000EO/UID0000EP. Replace only UID0000DS with:

`- [UID:0000DS][SpellSlotInputPane](by-class/SpellSlotInputPane.md) : reconstructable : 91% : very-strong : Complete CharInputPane-derived declaration with signed spell index at +0x108 and natural 0x10c tail alignment, constructor, virtual destructor, canonical EventHandler Shift+? tab-3/effect/base method, submit child, private SendSpellSlotPacket(signed char) declaration for the retained no-route sender, exact direct source destructor at 0x005b1310, scalar/adjustor/vtable compiler separation, and class closure before children.`

### by-file/-coverage-report.md

Current UID0000O0 is unique at line 261, unchanged by the B005 file-row replacements at UID0000J6/UID0000ON. Replace only UID0000O0 with:

`- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) : reconstructable : 92% : very-strong : NexusTK/ui/dialogs/SpellInputPanes.cpp source root with complete class declarations closed before children, canonical EventHandler signatures, UID0001MP Shift+? help route through EventMan/tab/effect/base APIs, six signed-index prompt constructors, exact prompt/accessor/submit bodies, exact SpellFourArgsInputPane, SpellOneArgInputPane, and SpellSlotInputPane direct source destructors UID0004TY/UID0004UB/UID0004UC with scalar/adjustor/vtable compiler separation, retained no-route raw helpers, and compiler destructor/adjustor/vtable/EH exclusions.`

All neighboring and unrelated rows, including every one of the 23 current B005 rows enumerated above, must be preserved exactly. The supervisor/validator owns whether and when these independent B003 proposed rows are applied; this artifact neither edits coverage nor asserts a future lifecycle state.

## Follow-Up Actions

- The accepted callback registered UID0004UC before dependent edits, removed every provisional token, reconciled C01-C21/R0-R5, scoped-validated every changed/new ordinary page, released every lease, and completed waited generated verification through command 15323. C01-C20 cover the applied/already-present ordinary implementation; C21 is terminally excluded from B003 implementation because manual coverage is supervisor-owned and remains unapplied at the recorded current epoch.
- No B003 implementation item remains. B005's distinct 23-row coverage union and execution are externally applied current facts; the exact B003 Spell handoff above remains separately supervisor-owned and unapplied. B003 did not edit coverage and does not assert whether or when that separate handoff is applied.
- Report validation/execution/count/path/move/archive state and later generated/manual epochs remain external supervisor/validator-owned. B003 ran no report lifecycle command and this artifact neither asserts nor directs a future lifecycle state.

## Confidence

- Overall recommendation confidence: `94` / very strong.
- Exact ranges, bytes, hashes, instructions, ABIs, normalized bodies, xrefs, vtable/COL/adjustor routes, padding, ownership, and compiler/source split: very strong.
- Source-facing global/helper/state names, R1, and the private UID0003VX declaration in R2: strong to very strong because current accepted project definitions and live behavior agree.
- Exact original lexical spelling/access formatting: strong, capped below 95 because no original source/PDB survives.
- Parent/file completion remains capped by unrelated family/raw-helper debt; this does not weaken the target split.

## Validator Results

- MCP evidence remains the accepted time-bounded session `9b0396a3`; no IDA mutation occurred during research or callback.
- All validator commands ran from canonical `source-3/project-documentation`, exited `0`, and produced `ok:1` on the final scoped pass for each destination. Deferred generated refresh was expected for commands 15311-15322.

| Command | Timestamp | Scoped destination | Exit / ok | Exact result and side effects |
| ---: | --- | --- | --- | --- |
| 15311 | `2026-07-20T11:48:14-04:00` | new UID0004UC page | `0`; registration pass | Issued real UID0004UC; inserted UID/path/91/94/owner/emitter/formal registry state; two `00035Q` missing-reference diagnostics exposed stale registry identity; generated refresh deferred. |
| 15312 | `2026-07-20T11:48:44-04:00` | UID0004UC | `0`; `ok:1` | Clean scoped validation after preserving `LineInputPaneCleanupBody` by exact path instead of fabricating missing UID00035Q; generated refresh deferred. |
| 15313 | `2026-07-20T11:51:58-04:00` | UID0001NG | `0`; `ok:1` | Applied 92/94, true-to-false, cleared emitter/formal registry, added UID0004UC reverse reference; generated refresh deferred. |
| 15314 | `2026-07-20T11:53:21-04:00` | UID0001LN | `0`; `ok:1` | Added UID0004UC parent reverse reference; scores/route/R3/nesting unchanged; generated refresh deferred. |
| 15315 | `2026-07-20T11:53:57-04:00` | UID0001LV | `0`; `ok:1` | Added bounded UID0004UC reference only; constructor metadata/formal unchanged; generated refresh deferred. |
| 15316 | `2026-07-20T11:54:28-04:00` | UID0001LW | `0`; `ok:1` | Added bounded UID0004UC reference only; Event metadata/formal unchanged; generated refresh deferred. |
| 15317 | `2026-07-20T11:55:03-04:00` | UID0001LX | `0`; `ok:1` | Added UID0004UC/retained UID0003VX references; submit metadata/formal unchanged; generated refresh deferred. |
| 15318 | `2026-07-20T11:56:02-04:00` | UID0000DS | `0`; `ok:1` | Applied 91/94 and exact R2 formal registry hash; added UID0004UC reference; generated refresh deferred. |
| 15319 | `2026-07-20T11:57:34-04:00` | UID0000O0 | `0`; `ok:1` | Preserved 92/94/path and added UID0004UC source-root reference; generated refresh deferred. |
| 15320 | `2026-07-20T11:58:30-04:00` | UID0001N9 | `0`; `ok:1` | Added UID0001NG/UID0004UC references; 86/90/false/blank R4 unchanged; generated refresh deferred. |
| 15321 | `2026-07-20T11:59:35-04:00` | UID00026W | `0`; `ok:1` | Added UID0001LV/UID0001NG/UID0004UC references; 91/94/false/blank R5 unchanged; generated refresh deferred. |
| 15322 | `2026-07-20T12:00:30-04:00` | `by-memory/-ignored.md` | `0`; `ok:1` | Added four reverse references for the two exact pads; reported 247 unrelated pre-existing missing-reference warnings; generated refresh deferred. |
| 15323 | `2026-07-20T12:00:50-04:00` | `by-file/SpellInputPanes.md --wait-generated` | `0`; `ok:1` | Full autogen registry rebuild and completed foreground refresh; repository-wide notices: 13 fallback inserts, 86 missing preferred child markers, 137 emitting-children-only pages, 280 generated metadata refreshes. No scoped failure. |

- Command 15323 generated `SpellInputPanes.cpp` SHA256 `FCAE50203A82EB62619BBB87157A16C742A84DB850854E4EC13F147EF94C8415`, 20,441 bytes / 597 lines, with header timestamp equal to the command. Structural/count assertions are recorded in Current Target State.
- Command 15323 generated the B003 callback tracker snapshot SHA256 `90D671C6988B502831C3B3565842841A31DDC6D0407C84ACBB74AADB5A2D8624`, 1,530,206 bytes / 6,204 lines. External deferred command 15325 at `2026-07-20T12:11:35-04:00`, SHA256 `9C54A9B02F60EE2FD56698E1575E35EFD33B217E1376BA755902CAF5E780E8A4`, 1,530,204 bytes / 6,204 lines, is historical. Supervisor coverage commands 15326/15327/15328 applied B005's 18 by-memory, three by-class, and two by-file rows; each exited `0` with `ok:1`. Supervisor-only B005 execute command 15329 at `2026-07-20T12:33:10-04:00` exited `0` with `research_execute_report:1` and `research_report_header_update:1`, moved UID00030F to `executed-b-agent-research/B005/00030F-TextEditPaneOnKeyEvent-source-quality.md`, and established current tracker SHA256 `C60D04925567C877C5ED3872E2841D07A6C42FA204E7ADCE6A02BF6C41906D6A`, 1,530,321 bytes / 6,204 lines. Its rows preserve UID0004UC `91/94` true and UID0001NG `92/94` false and record UID00030F `92/94` true with one executed B005 report. These commands were external; B003 ran none of them.
- Current manual readback after those external commands is by-memory SHA256 `4BB897EEA5814100C46905500DC1A1B88A9F7EEA96DDE498B11812FB9594B220`, 1,849,192 bytes / 4,393 lines; by-class `B666A61C1F5F728E10C1F80B7B2354AF9B4CABF240B55CA7CC1281D7D3321255`, 239,187 / 623; and by-file `63FFCA8568BF47DAE6D311DC4044A1001A896B7A619F87471CDF5DABFFCF006C`, 137,424 / 316. All 23 B005 rows are present, the B003 Spell rows retain the exact stale states/anchors documented in the handoff, and B003 performed no manual edit.
- Final managed-body parity readback is exact for all six destinations: R0/R3/R4/R5 are empty-body SHA256 `E3B0C44298FC1C149AFBF4C8996FB92427AE41E4649B934CA495991B7852B855`; R1 is 326 bytes, SHA256 `06EF143E49F5A955AC68C0CDFFA8AE862CAC55988A9A38869439C1C6CA20B85A`; R2 is 339 bytes, SHA256 `F3B782DF9B9691D97152B1081B40B58BEEA6AD49230E89142A2CD938F170E92D`. Each report body equals its destination body exactly after line-ending normalization.
- Every ordinary lease was released immediately after its scoped validator. Final lease ledger readback reports no active leases.

## Changed Files

Changed by the accepted callback:

| Path | Before SHA256 | Implemented SHA256 | Bytes / lines | Validator |
| --- | --- | --- | ---: | ---: |
| `by-memory/0x005b1310-0x005b1393.SpellSlotInputPaneDestructor.md` | absent | `6BBFCBE03E8620C7863214147E3AFF689CA0101FC0F9897AF2181E0AF4D0E3D0` | 13,622 / 130 | 15311 registration; 15312 clean |
| `by-memory/0x005b7dc0-0x005b7e84.SpellSlotInputPaneScalarDeletingDestructor.md` | `B1DF217D05A88F9EDF14C5040272295D29E31C110826F6704AEF4E3270B2BB46` | `28829F3B5548EED56C6D5609AA49754B4D25222709EA97570C8D8EB7EBBD6731` | 10,806 / 94 | 15313 |
| `by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md` | `FE7CF04E9FD3267AFA9F8D34E3FC97A33C51B3D23317D1EADFCC8783E6B761F6` | `9251820B828C25DBF89708F01256BF22A54BABC1A7FE581279CDDC9773258AE5` | 44,547 / 224 | 15314 |
| `by-memory/0x005b1280-0x005b130d.SpellSlotInputPaneConstructor.md` | `627C73FA72115139E3FE66880DDEEF922E09EE7A9550B2F33DB893D3219EC4DC` | `5B04B9B8B2311F56D5FA0B34210B2BDEB17205021D2CC7B01D350778FC426612` | 13,607 / 111 | 15315 |
| `by-memory/0x005b13a0-0x005b140c.SpellSlotInputPaneKeyInput.md` | `F161AE448BC0FF09582B97BE7B527054312CE7274EC0BDF0CD265CA17248EB57` | `15661767AD130954C3082766A28920B547198A0C914B9F188DD4444E86FBFB27` | 19,291 / 143 | 15316 |
| `by-memory/0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot.md` | `A474DA53E1C822B1164619A07D7DB25CD74C194383A43DA6D68286C136667A9F` | `2701F7ABD54331BF6371DB5320FE30DE52C6E047A02351471F5EDF8CF14C78E4` | 19,087 / 147 | 15317 |
| `by-class/SpellSlotInputPane.md` | `FF961962214ECE3007E9B78CEF530049173F37DE4C0DDC150ED25E47DC4A775E` | `89A2C79405481E29838D35761980B7CC13E89FAE0D3A87981206F72263955D77` | 14,915 / 114 | 15318 |
| `by-file/SpellInputPanes.md` | `B0106CED2FD07AFD514E0BD8ED1BABB530891C8642E51711ECB25FF1839551F0` | `3C6E444E6A3C215047AFE374BA520D51297917443BE2893C35FF9B5543BBC1A2` | 68,065 / 269 | 15319; final 15323 |
| `by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md` | `366AEB34CFF81ADE2E0BD89DEE78C5A1E0BD3641D4E7415087FA370A9288F06B` | `065C6869D1DD01F786500AD6131E4BF55A7DF7E9CB4A892C316594A33640AFDF` | 12,775 / 108 | 15320 |
| `by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md` | `877B5C1F72AD37E83F6297897C3A326519A2020E465097F18138EDAF79BAB50C` | `ADAD410CC06DF24F26CFD3D547B22A89270497208D066FB9D170198F4E155881` | 37,489 / 241 | 15321 |
| `by-memory/-ignored.md` | `B016C3DD617424D506A94A1425C1AAA12891754E560D7B1C8A084FDB627FA5BC` | `411E9EFD70832309294B1A15E8F2F28F0C892E480292421290F0E24F46718411` | 1,088,318 / 5,294 | 15322 |
| `tools/leaser/Agents/Agent-B003/research/0001NG-SpellSlotInputPaneScalarDeletingDestructor-source-quality.md` | Gate-1 SHA `30765EBCD6665C10AA6FFA2BA71647EFF9BE59FF13E6C79A730749EF3AC7144E` | callback, post-B005 shared-epoch rebase, and atomic C20/C21 report-only repair complete; exact SHA/metrics returned out of band | current artifact | none; agent-owned report |

Read-only verification and validator-owned side effects:

| Path | Current SHA256 | Bytes / lines | Result |
| --- | --- | ---: | --- |
| `by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md` | `CCA39D446E2EAF6FA6AAE98487E386ED9F5019B0D26BD053C8CBCD224A42DC12` | 17,176 / 141 | byte-for-byte unchanged; R2 now declares its existing definition |
| `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp` | `FCAE50203A82EB62619BBB87157A16C742A84DB850854E4EC13F147EF94C8415` | 20,441 / 597 | validator-owned command 15323 output, read only |
| `auto-generated/-ag-research-tracker.md` | `C60D04925567C877C5ED3872E2841D07A6C42FA204E7ADCE6A02BF6C41906D6A` | 1,530,321 / 6,204 | current read-only external B005 execute command 15329; command 15325 and callback command 15323 snapshots retained above as historical proof |
| `by-memory/-coverage-report.md` | `4BB897EEA5814100C46905500DC1A1B88A9F7EEA96DDE498B11812FB9594B220` | 1,849,192 / 4,393 | current supervisor-owned union after command 15326; all 18 B005 actions preserved, separate B003 handoff unapplied |
| `by-class/-coverage-report.md` | `B666A61C1F5F728E10C1F80B7B2354AF9B4CABF240B55CA7CC1281D7D3321255` | 239,187 / 623 | current supervisor-owned union after command 15327; all three B005 rows preserved, separate UID0000DS replacement unapplied |
| `by-file/-coverage-report.md` | `63FFCA8568BF47DAE6D311DC4044A1001A896B7A619F87471CDF5DABFFCF006C` | 137,424 / 316 | current supervisor-owned union after command 15328; both B005 rows preserved, separate UID0000O0 replacement unapplied |

Verify-only support remained unchanged: accessor `1285D1563F41F2DCD7BD168F95C1549E282875869B8B8C4712D0D71D8FDE4B4F`; item setter `8C41F55243C5DA9DB26E52C893DDDCFA992D43C80F8124506E9431AC55D5DDF7`; spell setter `0A06D5ED6D33E3ED7D0B8292D48674879073F307EA95DEE010D6097A66E16CB5`; LineInputPane cleanup `FD4CE32694F42FF49B4CD1C6CA1F4443F47553E7382FC1F9D919F4CA853492A7`; `g_useEpfAssets` `63105269A3F90B2E11AAD2B457D4A35DA4EC8FEAEBC4B8A3E86120882DA21E10`; `g_pGeneralPurposePanel` `40D8FD9C67A1BF47869F961F061DBCCC41B7A04EA2BAD0C7AE932F780B47C66E`.

## Implementation Tracking Checklist

- [x] Confirm the report retains all 33 required H2 headings and exactly one Gate 2 marker.
- [x] Confirm C01-C21 are atomic and destination-specific: C01-C20 ordinary claims are applied/already-present as proved, while supervisor-owned manual C21 is `excluded-with-reason` and unapplied by B003.
- [x] Confirm R0-R5 are destination-shaped managed blocks and no draft/example C++ exists outside them.
- [x] Confirm all positive, negative, historical, source/compiler, padding, score, and rejected-alternative evidence remains no-loss.
- [x] Reread target/support/formal/manual/generated/tracker/lease state before callback edits, during callback reconciliation, and again against the post-B005 command-15329 current union.
- [x] Register `by-memory/0x005b1310-0x005b1393.SpellSlotInputPaneDestructor.md` through validator-supported new-file workflow.
- [x] Capture real validator-issued UID0004UC without guessing or editing validator state.
- [x] Replace every provisional new-child token in report and dependent destinations before dependent validation.
- [x] Apply UID0001NG `92/94`, owner 0000DS, false, blank emitter/position, Nested 0, exact Item Summary/evidence, and R0 blank.
- [x] Apply UID0004UC `91/94`, owner/emitter 0000DS, true, blank position, Nested 0, exact Item Summary/evidence, and R1.
- [x] Apply UID0001LN child inventory/source split without changing current B001-applied `90/93`, owner, false route, blank position, Nested -4, R3, nineteen pads, real UID0004TY/UID0004UB union, or unrelated content.
- [x] Preserve UID0001LM as first same-start child `Nested:4`; assign UID0004UC `Nested:0`; preserve UID0001LW and following children `Nested:0`.
- [x] Preserve `[0x005b130d,0x005b1310)`, `[0x005b1393,0x005b13a0)`, and all other nineteen parent-internal spans exactly.
- [x] Preserve parent-external `[0x005b14e6,0x005b14f0)` outside UID0001LN.
- [x] Add exactly `[0x005b7db4,0x005b7dc0)` and `[0x005b7e84,0x005b7e90)` to `by-memory/-ignored.md` without loss.
- [x] Apply UID0000DS `91/94`, exact R2 with the private `SendSpellSlotPacket(signed char selectedSlot)` declaration, class closure before children, complete layout/access/API, and direct/scalar provenance.
- [x] Apply UID0000O0 no-loss source/compiler union at unchanged `92/94` and unchanged route.
- [x] Apply bounded UID0001LV direct/scalar link/history without changing score, metadata, formal, range, or route.
- [x] Apply bounded UID0001LW predecessor/direct/scalar link/history without changing score, metadata, formal, Event behavior, range, or route.
- [x] Apply bounded UID0001LX lifecycle link/history without changing score, metadata, formal, packet behavior, range, or route.
- [x] Apply UID0001N9 stale-disposition historicalization while preserving score/metadata/all thunks and blank R4.
- [x] Apply UID00026W exact SpellSlot slice/COL/route/source-cause evidence while preserving current B001-applied `91/94`, metadata, all bands, exact FourArgs/OneArg slices, and blank R5.
- [x] Preserve current UID0001NF/UID0004UB pair, UID0001NH, and all sibling direct/scalar pages verify-only absent exact contradiction.
- [x] Preserve globals/accessor/state setters/base cleanup/state classes/CharInputPane/LineInputPane verify-only absent exact contradiction.
- [x] Preserve UID0003VX score/metadata/body/formal/history byte-for-byte while proving complete R2 declares its existing qualified definition.
- [x] Lease only one ordinary file immediately before editing it.
- [x] Reread and no-loss rebase each leased destination after acquisition.
- [x] Run one scoped validator from canonical project-documentation root for every changed/new ordinary page.
- [x] Record every command ID, timestamp, exit, ok count, warning, side effect, before/after hash, and issued UID.
- [x] Release each ordinary lease immediately after its scoped validator.
- [x] Run one final authorized `--wait-generated` validation through `by-file/SpellInputPanes.md`.
- [x] Verify generated UID0000DS class declares `SendSpellSlotPacket(signed char selectedSlot)` privately and closes before all qualified definitions.
- [x] Verify exactly one `SpellSlotInputPane::~SpellSlotInputPane()` definition, sourced from UID0004UC.
- [x] Verify zero UID0001NG body, Empty Emitter Marker, title/address marker, duplicate, or wrong-range emission.
- [x] Verify constructor, Event handler, submitter, retained helper definition, sibling methods, and complete current file union remain once/no-loss, with no undeclared `SpellSlotInputPane` qualified member.
- [x] Verify no raw vptr store, explicit base destructor, scalar flag, delete/guard path, cookie/SEH/EH, adjustor arithmetic, or raw vtable/RTTI array is emitted for this target.
- [x] Verify the unrelated UID0003VV Empty Emitter Marker remains unrelated and unchanged.
- [x] Re-read post-B005 manual coverage roots, preserve all 23 applied B005 rows exactly, and rebase the separate B003 no-loss handoff/anchors without B003 editing coverage.
- [x] Update C01-C21 to legal callback terminal states with claim-specific destination/validator/generated/manual-ownership proof.
- [x] Check each row only after independent readback proves it.
- [x] Update Current Target State, Validator Results, Changed Files, generated/manual/tracker evidence, and lifecycle-neutral wording through external command 15329 while preserving callback truth.
- [x] Confirm no provisional token and no B003 lease remains.
- [x] Confirm B003 edited no manual coverage/generated/tracker/audit/supervisor/validator-state/IDA/lifecycle/archive file.
- [x] Stop at the supervisor-authorized Gate 2 handoff without running or probing `execute_report` or another lifecycle command.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000015333","destination_path":"executed-b-agent-research/B003/0001NG-SpellSlotInputPaneScalarDeletingDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0001NG-SpellSlotInputPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-07-20T12:58:07-04:00","uid":"0001NG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
