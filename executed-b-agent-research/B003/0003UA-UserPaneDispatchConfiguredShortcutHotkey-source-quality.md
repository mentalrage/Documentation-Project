** TARGET-REPORT-UID:0003UA **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0003UA UserPaneDispatchConfiguredShortcutHotkey Source-Quality Research


## Finalized Report / Current Recommendation

- Implemented recommendation: [UID:0003UA] is the exact unsplit source-authored `UserPane::DispatchConfiguredShortcutHotkey` member at `[0x005a3a20,0x005a3ad4)`, now `91/93`, with canonical owner/emitter UID0000FQ, `RECONSTRUCTABLE:TRUE`, blank optional position, `Nested:0`, and exact Destination R1.
- Final disposition: retained dead/legacy UserPane source, not a live-routed method, compiler artifact, covered-by marker, LivingObjectPane method, Config method, or no-code target. Exhaustive live-route and duplicate-body checks remain negative, but the complete 180-byte application body, stable class ABI, direct Config dataflow, and two source-authored UserPane callees justify reconstruction.
- Implemented support disposition: the complete `Config` declaration and all direct compact-record producers/consumers use one source-legal `CompactShortcutRecord { wchar_t code; unsigned char isSpellMode; }` contract. The fourth byte is natural two-byte-alignment tail padding, not `reserved` or an unknown source field. Stale `0x84` size prose is corrected to exact `0x4` without changing the complete Config layout or B005's accepted facts.
- Implemented historical correction: the old B013/B001 route-negative research remains as history, while its LivingObjectPane owner/file route, `m_userProfile`, `key`, generic `mode`, explicit `(void)unused`, unsigned `isalpha` conversion, schematic padding member, and current no-declaration assertions are rejected or explicitly historicalized.
- Confidence: `93` for range, bytes, selector mapping, record placement, helper calls, behavior, class owner, and retained-source disposition; capped by no recovered live entry, no original symbol spelling, and no recoverable semantic type/name for the untouched second ABI slot.
- Current artifact state: the separately authorized B003 callback is implementation-complete. Sixteen accepted ordinary by-* destinations were edited under serial short leases, each passed scoped validation, every lease was released, and final waited command `000000013328` completed generated readback. B003 manually edited no coverage, generated, tracker, audit, supervisor, validator-state, lifecycle, archive, or IDA file and ran no execute_report or lifecycle command. Report validation/execution/count/path/move/archive state remains external supervisor/validator-owned state and is neither asserted nor directed here.

## Supporting Research

- Historical initial supervisor assignment: target-specific report-only research for UID0003UA, with mandatory live IDA MCP and explicit resolution of contradictory UserPane/LivingObjectPane, no-route, source-retention, compact-record, Config-placement, ABI, and C++ claims.
- Historical report search terms were run exactly as: `0003UA`, `0x005a3a20`, `DispatchConfiguredShortcutHotkey`, `LivingObjectPaneRawConfigHotkeyHelper`, and `CompactShortcutRecord`. Source-family refinement terms were `UserPane`, `LivingObjectPane`, `0002QY`, `0003UB`, `0003UJ`, `0001KM`, `m_compactShortcutRecords`, `ProfileLoadAndLegacyImport`, `SaveUserSettings`, `NewMacroDialog`, and `Config`.
- Exact roots searched:
  - `source-3/project-documentation/executed-b-agent-research/**`: direct and supporting matches listed below.
  - `source-3/project-documentation/archived/**`: no match for the exact terms.
  - `source-3/project-documentation/tools/leaser/Agents/Older-Research/**`: no match.
  - `source-3/project-documentation/tools/leaser/Agents/SpecialReports/**`: no match.
  - `source-3/project-documentation/tools/leaser/Agents/**`: B005 UID0003UP collision report, active at the evidence-time search, plus incidental supervisor/goal/index references; no second UID0003UA target report.

| Report / source | Classification | Target-specific finding and disposition |
| --- | --- | --- |
| `executed-b-agent-research/B013/0003UA-LivingObjectPaneRawConfigHotkeyHelper-source-quality.md`, SHA256 `7D4814B54908DDFF5E62434C762E5EAA45698FB3962350AF6C83F4FCE6A35802` | Direct historical target report | Preserves correct range, no-route scan, selector/key/branch behavior, and retained-source insight. Its LivingObjectPane owner/file route, schematic `key/mode/reserved` record, named `unused` source assumption, and 87/88 cap are superseded by current UserPane/Config/profile evidence and fresh target disassembly. |
| `executed-b-agent-research/B001/0002QY-MotionAnimationTimerTick-empty-emitter-source-quality.md` | Broad executed UserPane source-integration lead | Correctly moved the target and its callees to UID0000FQ/UID0000P1 and supplied the complete UserPane declaration. Its target body introduced invalid `m_userProfile`, stale `key/mode`, unsigned classification, and `(void)unused`; only the ownership/integration result survives unchanged. |
| `executed-b-agent-research/B005/0003UB-UserPaneExecuteHotkeyAction-source-quality.md` | Adjacent direct source-family evidence | Independently proves UserPane ownership, the separate integrated 30-row table, one live successor caller, and current callee roles. Its historical Config-declaration blocker was valid at that evidence epoch but is superseded by the complete UID000031 declaration now on disk. UID0003UB itself remains outside the direct formal destination set here. |
| `executed-b-agent-research/B015/0003UJ-LivingObjectPaneRawFunctionKeyDebounceHelper-source-quality.md` | Sibling retained-helper comparison | Proves a second no-live-route legacy shortcut mechanism and comparable alphabetic slot mapping. Its LivingObjectPane owner spelling is historical; its separate legacy `wchar_t[10][0x80]` storage and debounce behavior are not merged into UID0003UA. |
| `executed-b-agent-research/B001/0001KM-livingobject-localplayer-source-split-audit.md` | Historical split/range lead | Correctly isolated `[0x005a3a20,0x005a3ad4)` and following 12-byte alignment, but its broad LivingObjectPane classification predates the current complete UserPane split and is rejected for ownership. |
| `executed-b-agent-research/B002/0001KN-UseInventorySlotDispatch-source-quality.md` | Direct callee support | Proves the mode-zero call target and one-based inventory-slot contract. Current by-memory metadata/formal now assign the method to UserPane; old LivingObjectPane prose is historical. |
| `executed-b-agent-research/B010/0003UC-LivingObjectPaneUseCommandSlotDispatch-source-quality.md` | Direct callee support | Proves the nonzero spell/command call target and one-based slot contract. Current by-memory metadata/formal now assign the method to UserPane; old LivingObjectPane prose is historical. |
| `executed-b-agent-research/B013/00019T-ProfileLoadAndLegacyImport-source-quality.md` | Direct storage lifecycle support | Proves `.usr` compact record load, legacy migration, direct Config storage, `code`, and `isSpellMode`; independently revalidated against live MCP. |
| `executed-b-agent-research/B005/0001AV-SaveUserSettings-empty-emitter-source-quality.md` | Direct writer support | Proves exact `code` and `S`/`I` persistence from `isSpellMode`; independently revalidated against live MCP. |
| Historical pre-execution path `tools/leaser/Agents/Agent-B005/research/0003UP-UserPaneHandleMovementReplyPacket-source-quality.md`, accepted SHA256 `D42D13C36310140D1BC899A31EB7F4C7FCFA292A2059F45507870861FD14EA13`; current executed artifact `executed-b-agent-research/B005/0003UP-UserPaneHandleMovementReplyPacket-source-quality.md`, SHA256 `CB31E9B73313D6E87D94F83515D2FE1F8402C81D908CD25424F3920ED3C400FF` | Accepted shared-destination collision, active at evidence collection and externally executed afterward | B005 was implementing the complete Config/UserPane union at evidence collection. Its full Config declaration was observed on disk at 90/92, but its compact record remained `code/unsigned char mode` and its report did not resolve UID0003UA. Historical callback gate: B003 had to confirm closure, reread terminal artifacts/live pages, and rebase without loss; C36 proof records that completed procedure. Validator-owned history now records external execution command `000000013340` at `2026-07-15T17:37:24-04:00`; the executed artifact explicitly preserves B003's later compact-shortcut additions and the resulting shared destination hashes. |
- Wave2/Wave3 mentions encountered in older Config/LivingObjectPane prose were treated only as stale provenance and were not used as current evidence.

## Target

- Target UID: `0003UA`.
- Target path: `by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md`.
- Historical assignment baseline: tracker `## by-memory` -> `### Not-Covered Files - Reconstructable`, target `87/88`, zero target-specific reports under B003, and no B003 lease before Gate 1.
- Supervisor classification at callback authorization: exact report SHA256 `F90EA2ED58FE6B4FD00C5739848FD2F4AB54DA4BF09DAD14B8F0F86563C02F3F` passed Gate 1 and authorized C01-C36/R1-R6 implementation.
- Historical evidence-capture metadata: owner/emitter UID0000FQ, reconstructable true, blank optional position, `Nested:0`, exact 180-byte half-open range, and a nonblank but source-invalid managed body.
- Implemented metadata: `91/93`; owner/emitter, reconstructable state, blank position, `Nested:0`, exact range/path/title, and all unrelated metadata remain unchanged.

## Current Target State

- Historical pre-callback target state: the top target section said UserPane and routed through UID0000FQ, but nested sections still asserted `LivingObjectPane::DispatchConfiguredShortcutHotkey`, LivingObjectPane.cpp placement, LivingObjectPane-owned callees, a schematic `key/mode/reserved` record, and confidence capped at 88. The formal used nonexistent `g_pConfig->m_userProfile`, `shortcut.key`, `shortcut.mode`, unsigned classifier conversion, and a named/evaluated `unused` second parameter. Those contradictions are preserved as before-state evidence only.
- Implemented target state: exact R1 uses direct `g_pConfig->m_compactShortcutRecords`, `code`, byte `isSpellMode`, signed-low-byte `_isalpha`, full-wchar ranges, `0xff` fallback, and an unnamed unread second `int`. The `[ebp+0xb]` byte remains documented as compiler scratch in the first narrow argument's home slot, not source or second-argument data.
- Implemented support state: exact R2 defines `CompactShortcutRecord` as `wchar_t code; unsigned char isSpellMode;` with natural tail alignment; R3-R6 use the same names; Config class/file size prose is exact 0x4; the profile slice is `90/92`; defaults are `89/91`; and NewMacroDialog constructor/save/load are current and source-consistent.
- Historical generated checkpoints remain: UserPane command `13252`, Config `13257`, and ProfileStorage/MacroDialogs `13239` exposed the stale cross-TU state described above. They are evidence-time facts, not current lifecycle assertions.
- Callback generated checkpoint: waited command/header `000000013328`, refreshed `2026-07-15T17:21:16-04:00`, emits R1-R6 exactly once in their owning translation units, uses canonical `code/isSpellMode`, closes UserPane before qualified definitions, and has zero UID0003UA Empty Emitter Marker. Exact hashes/counts are under Validator Results.

## Executive Recommendation

- Preserve the exact target range and source-facing name, but make the definition `UserPane::DispatchConfiguredShortcutHotkey(short hotkeyNumber, int)` with an unnamed second slot.
- Use direct base-typed Config storage: `g_pConfig->m_compactShortcutRecords[shortcutIndex]`.
- Use `wchar_t code` plus `unsigned char isSpellMode`; do not emit a source `reserved` member. The fourth byte is natural tail alignment.
- Preserve the exact unguarded selector mapping, narrow signed-low-byte classification, full-wchar ASCII comparisons, fallback `0xff`, and spell-before-inventory branch order.
- Preserve no-live-route evidence as liveness/history, not as an owner/emitter or no-code blocker.
- Synchronize all current target-specific LivingObjectPane/UserPane/Config/profile/NewMacroDialog support prose and formal bodies listed below. Do not silently absorb UID0003UB's separate formal-body debt.

## Supervisor Active Recheck

- This callback follows the supervisor's direct UID0003UA assignment and does not substitute the B013 target report or broad UID0002QY callback.
- Split repair is not required: fresh bytes prove one complete body and parent-owned successor alignment.
- Every source-bearing destination required to compile UID0003UA and the compact record's producers/consumers has the exact accepted formal below and in the validated destination. UID0003UB remained verify-only and unchanged.
- B005's accepted UID0003UP callback was active at evidence collection. B003 completed disjoint work first, then observed B005's terminal 56/56 checklist, zero proposed claims, and no shared lease; reread the terminal B005 and B002 artifacts plus each live shared page; and rebased additively. The later executed B005 artifact at SHA256 `CB31E9B73313D6E87D94F83515D2FE1F8402C81D908CD25424F3920ED3C400FF` and current B002 artifact at SHA256 `14DE947BE595D8BE91BA3FE5D61355508A0ED6D0898D5B8D055886F82146B13B` explicitly recognize B003's resulting shared hashes and preserved unions. A final read-only post-execution check at `2026-07-15T17:42:17-04:00` found all eight shared ordinary hashes unchanged, so no additional ordinary edit, lease, scoped validator, or generated refresh was necessary.

## Inference Research Guidance Check

- IDA facts are kept separate from documentation and inference. Exact bytes, instruction order, stack offsets, xrefs, functions, hashes, and direct storage consumers are facts. `UserPane` ownership and retained-dead-source placement are strong source-shape inferences from settled class/callee/source-family evidence. The stripped method and field spellings remain descriptive.
- Existing documentation was not trusted where current metadata and nested prose disagree. LivingObjectPane ownership, `m_userProfile`, a `reserved` field, unsigned classification, and a named `unused` parameter were each rechecked and rejected.
- The evidence ladder used raw bytes/disassembly first, direct storage lifecycle and callee contracts second, current by-* and generated output third, then historical reports as leads.
- No Wave2/Wave3 ownership or naming claim was accepted as current authority.

## Heuristic / Inference Reanalysis And Validation

1. **Range and body kind:** `[0x005a3a20,0x005a3ad4)` is one 180-byte function-shaped raw body with two `retn 8` exits. It is source-authored application logic, not alignment, switch data, a thunk, SEH/cookie lowering, CRT code, or part of the modeled successor.
2. **Owner:** both calls preserve the original receiver in `edi` and restore it to `ecx`. Current exact callee pages are `UserPane::UseCommandSlot` and `UserPane::UseInventorySlot`; those methods use UserPane-only storage beyond the 0x20c LivingObjectPane base. A LivingObjectPane method cannot naturally call those derived-only nonstatic members. UserPane is therefore the strongest direct class owner.
3. **Source file:** the body lies in the UserPane local-player extension cluster, immediately before another UserPane hotkey member, and current UID0000FQ/UID0000P1 already declare and emit it. `NexusTK/ui/panels/UserPane.cpp` is stronger than LivingObjectPane.cpp, Config.cpp, ProfileStorage.cpp, or MacroDialogs.cpp.
4. **Liveness:** no direct code/data/table route survives exhaustive scans. The compact records are loaded and then migrated into the integrated macro table; modern live input calls UID0003UB instead. This explains retained legacy source without inventing a caller.
5. **First parameter:** `movsx eax, word ptr [ebp+8]` proves a signed 16-bit selector. Values 0 and 10 select the tenth row of each page; all other values use selector minus one. No internal range check exists.
6. **Second ABI slot:** `retn 8` proves two four-byte stack homes under x86 thiscall, but `[ebp+0xc]` is never read. No caller survives to recover whether the source type was int, short, enum, pointer, or callback residue. An unnamed `int` preserves the established declaration/ABI without inventing semantics.
7. **Scratch byte:** `mov [ebp+0xb], al` writes the high byte of the first argument home, not the second slot. It is compiler stack-slot reuse for the record mode while `ebx` holds the code. Source must use an ordinary local/reference, not expose stack aliasing or `(void)unused` as binary behavior.
8. **Container placement:** all exact record addresses are direct `Config + 0x28f29c + index*4`. Startup constructs the 0x291918-byte Config base before RegistryConfig vtable promotion. Current complete Config formal directly declares the array. Nested `m_userProfile`, RegistryConfig casts, raw offset accessors, and a separate global are rejected.
9. **Record layout:** `wchar_t code` at +0 and one byte at +2 produce size 4 through compiler-natural two-byte alignment. No consumer reads/writes/serializes +3. It is tail padding, not an explicit field.
10. **Mode type/name:** defaults, modern load, legacy migration, and NewMacroEditControlPane input produce only 0/1; save writes `S` for nonzero and `I` for zero; paint labels the same state Spell/Item. Exact binary copies are byte-oriented and accept any nonzero value, so `unsigned char isSpellMode` is safer than claiming original `bool` while still resolving the semantic name.
11. **Code name:** modern profile load/save already uses `code`; the field is a wchar code unit and full-wchar ASCII comparisons follow. `key` remains a UI role alias but is rejected as the shared storage member spelling.
12. **Classification:** `movsx eax, bl` proves signed low-byte passage to `_isalpha`. `static_cast<unsigned char>` is behaviorally different for bytes >= 0x80. `static_cast<char>(shortcut.code)` matches the x86 plain-char sign extension while full `wchar_t` comparisons preserve the subsequent binary behavior.
13. **Slot mapping:** lowercase maps 1..26, uppercase 27..52, and an `_isalpha` result outside ASCII leaves 0xff. Non-alpha returns without calling either dispatcher.
14. **Mode branch:** nonzero mode calls UserPane::UseCommandSlot first; zero calls UserPane::UseInventorySlot. Both consume one-based unsigned-byte slots and return no semantic value to this method.
15. **Duplicate/inlining check:** exact target entry, dispatch tail, and full mapping signatures occur only in this body. UID0003UJ has conceptually similar alphabetic mapping but uses different storage, debounce, and command-only dispatch; it is not an exact inline copy or source substitute.
16. **Name:** `DispatchConfiguredShortcutHotkey` is descriptive, stable, and distinguishes the 20 compact rows from UID0003UB's integrated 30-row executor. Exact original lexical spelling is unrecoverable and remains a confidence cap, not a source blocker.
17. **Config collision:** B005's accepted callback, active while this research was in progress, installed a complete Config declaration. This report preserves that entire union and changes only the compact record's field name plus stale size/source-state prose. The authorized callback rebased on B005's terminal state as proved under C36 and Changed Files.
18. **Generated output:** current cross-TU field spellings make generated source inconsistent. R1-R6 make UserPane, Config, ProfileStorage, RegistryConfig defaults, and MacroDialogs use the same direct record contract without raw layout scaffolding.

Rejected alternatives:

- `LivingObjectPane::DispatchConfiguredShortcutHotkey`: rejected by current derived-only callee ownership and accepted UserPane source union.
- File-local `__fastcall` helper: rejected because the current class declaration, receiver-preserving member calls, and adjacent member source order provide a natural thiscall member route.
- `RegistryConfig` or ProfileStorage method: rejected because those own persistence, not runtime UserPane action dispatch.
- Merge with UID0003UB: rejected by independent prologue, padding, table layout, caller/liveness, and behavior.
- Covered-by UID0003UJ or modern UID0003UB: rejected because no exact body duplicate exists and retained source has distinct behavior.
- Blank/no-code: rejected because the body and complete Config declaration are source-reconstructable.
- `bool isSpellMode`: plausible but not proved. `unsigned char isSpellMode` preserves exact direct-byte/nonzero semantics and avoids overclaiming the stripped original type.
- Explicit range guard, null guard, raw offsets, `reserved`, `(void)unused`, decompiler locals, compiler scratch, and unsigned `isalpha`: rejected as behavior/source-shape changes.

## Evidence Standards Used

- Live IDA MCP: `idb_list`, `server_health`, bounded `get_bytes`, `lookup_funcs`, `xrefs_to`, `disasm`, `decompile`, and `find_bytes` against database `64c11373`.
- Raw executable checks: exact body SHA256, PE section route scan for rel32/short/near branches and VA/RVA pointers, and duplicate byte-pattern scans.
- Direct lifecycle evidence: Config defaults, profile load/migration, profile save, NewMacroDialog constructor/save/load, and NewMacroEditControlPane display/input behavior.
- Current documentation and generated sources were treated as evidence snapshots, not infallible authority.
- Historical reports were used only after target-specific revalidation.
- Strong confidence is justified because bytes, storage offsets, all writers/readers, current class declarations, and helper contracts agree. Confidence remains below final because liveness, original names, and the second slot's semantic type are stripped.

## Evidence Checked

- MCP initialization/session: streamable endpoint `http://127.0.0.1:13337/mcp`, protocol session `67ebc7f2-7c21-435c-923a-998bfe22ea2c`; fresh `idb_list` returned active/adopted NexusTK IDB `64c11373`, worker PID 21508.
- MCP health: `status=ok`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, strings cache ready with 2067 entries.
- Target checks: full 180-byte read, disassembly, start/end lookups, start/end xrefs, callee xrefs, predecessor/successor bytes, exact route pointers, and signature duplication.
- Storage checks: fresh decompilation/readback of `0x0048ebc0`, `0x004f95b0`, `0x0050aba0`, `0x0053ed90`, `0x0053f180`, `0x0053f210`, `0x0057faa0`, and `0x0057fc80`; all 40 aligned code/mode displacement patterns across 20 rows were searched.
- Current docs opened: target; UID0001KM, UID0003UB, UID0003UJ, UID0001KN, UID0003UC; UserPane/LivingObjectPane class and file pages; Config class/file/global; RegistryConfigUserProfileBlock; defaults/load/save/ProfileStorage; NewMacroDialog/NewMacroEditControlPane and exact constructor/save/load pages; generated UserPane/Config/ProfileStorage/MacroDialogs.
- Historical Gate-1 manual-row read: by-memory, by-class, by-file, and by-type/by-struct coverage rows for every accepted score/path/formal/source-description delta.
- Negative checks: no IDA function object at target, no xrefs to target/end, no VA/RVA pointer, no direct branch destination, no vtable/RTTI/export/exception/table route, no exact duplicate body/tail, no selector guard, no Config null guard, no read of second ABI slot, no lifecycle use of record byte +3.
- Failed/invalid tool invocation: one PowerShell `Invoke-WebRequest` attempt lacked `-UseBasicParsing`; two subsequent health/probe calls omitted arguments because a local function parameter collided with PowerShell's automatic `$args`; one pre-handoff `get_bytes` request used obsolete singular `address`/`size` keys before `tools/list` confirmed the current required `regions` shape. These client-side invocation/schema errors produced no IDB evidence and were discarded. Corrected calls immediately returned healthy MCP and real target bytes. No valid bounded MCP call failed.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | MCP session `64c11373` was healthy at evidence collection and returned real target bytes. | Direct | idb_list, health, get_bytes | Target evidence; report MCP facts | incorporate | applied |
| C02 | Exact target is `[0x005a3a20,0x005a3ad4)`, size `0xb4`/180, SHA256 `BAA84BF5C37F66CF1DFBC68667C8B41FD50FFF943A9B55207AACAB2F52358E13`. | Direct | full bytes/hash | UID0003UA range/evidence | incorporate | applied |
| C03 | Target has no IDA function object, but is a complete source-shaped body with 65 instructions and two `retn 8` exits. | Direct | lookup/disasm | UID0003UA status/CFG | incorporate | applied |
| C04 | Predecessor ends at 0x5a3a12 after epilogue; target is preceded by fill and followed by exactly 12 `cc` bytes through 0x5a3adf. | Direct | bytes/disasm | UID0003UA; UID0001KM; ignored verify | incorporate | applied |
| C05 | First parameter is signed short; second ABI home exists but is unread and semantically unrecoverable. | Direct/inference | `[ebp+8]`, `[ebp+0xc]` absence, `ret 8` | UID0003UA ABI/formal | incorporate | applied |
| C06 | `[ebp+0xb]` is first-argument-home scratch for the mode byte, not a second-argument read. | Direct | stack offsets/instruction order | UID0003UA ABI/history | incorporate | applied |
| C07 | Selector mapping is 0->9, 1..9->0..8, 10->19, 11..19->10..18, with no internal range check. | Direct | exact address arithmetic | UID0003UA behavior/R1 | incorporate | applied |
| C08 | Compact records are direct Config storage at +0x28f29c, 20 rows, stride 4; nested `m_userProfile` is invalid. | Direct | target/default/load/save/UI, complete Config | UID0003UA; Config/global/type support | incorporate | applied |
| C09 | Record source contract is `wchar_t code` plus byte `isSpellMode`; byte +3 is natural tail padding. | Strong inference | all writers/readers and no +3 lifecycle | Config R2; profile/global support | incorporate | applied |
| C10 | `unsigned char isSpellMode` is safer than unproved bool and exact for nonzero/zero behavior. | Strong inference | byte copies, setcc writers, save semantics | Config R2; R1/R3-R6 | incorporate | applied |
| C11 | Target passes signed low byte to `_isalpha`; unsigned-char conversion is behaviorally stale. | Direct | `movsx eax, bl`/call | UID0003UA R1/prose | incorporate | applied |
| C12 | Lowercase maps 1..26, uppercase 27..52, alpha non-ASCII falls to 0xff, non-alpha returns. | Direct | branches/subtractions | UID0003UA behavior/R1 | incorporate | applied |
| C13 | Nonzero mode calls UserPane::UseCommandSlot; zero calls UserPane::UseInventorySlot. | Direct | calls/xrefs/current callee contracts | UID0003UA/callee support | incorporate | applied |
| C14 | UserPane UID0000FQ is the strongest owner; LivingObjectPane ownership is superseded history. | Strong | derived-only callee/class/source union | target/UserPane/LivingObjectPane support | reject-stale | applied |
| C15 | Source route is UID0000P1 `NexusTK/ui/panels/UserPane.cpp`. | Strong | neighborhood/current class/file route | target/parent/class/file | incorporate | applied |
| C16 | Exhaustive current route scan found no live entry or pointer/table route. | Direct negative | xrefs, PE scan, find_bytes | target/parent/source history | incorporate | applied |
| C17 | No exact duplicate/inlined target exists; UID0003UJ is only a semantic mapping comparator. | Strong negative | signature/pattern comparisons | target/UID3UJ comparison | incorporate | applied |
| C18 | No-live-route means retained legacy/dead source, not compiler/no-code or covered-by. | Strong inference | complete app logic plus profile migration | target disposition/score | incorporate | applied |
| C19 | Best descriptive source name remains `DispatchConfiguredShortcutHotkey`; exact original spelling is unavailable. | Strong descriptive | behavior/current naming collision audit | target title/formal | already-present | already-present |
| C20 | UID0003UA becomes 91/93 with owner/emitter/true/blank position/Nested0/range unchanged and exact R1. | Strong | C01-C19 | target metadata/formal | incorporate | applied |
| C21 | Complete Config R2 is retained byte-for-byte except `mode -> isSpellMode`; score remains 90/92. | Strong | current complete declaration plus lifecycle | by-class/Config.md | incorporate | applied |
| C22 | Config class/file prose claiming `CompactShortcutRecord` size 0x84 is a typo; exact size is 0x4. | Direct | layout arithmetic/current formal | Config class/file | reject-invalid | applied |
| C23 | UID00028Q remains base-typed `Config *`, 88/92; compact row +3 becomes natural padding and stale declaration-blocker text becomes historical. | Strong | current complete Config and global lifecycle | g_pConfig page | incorporate | applied |
| C24 | UID0001VR becomes 90/92; comment-only formal remains because it is a documentation slice, while final Config arrangement is now resolved. | Strong | complete Config plus exact lifecycle | RegistryConfigUserProfileBlock | incorporate | applied |
| C25 | Defaults R3 uses `.code` and `.isSpellMode = 1`; recommend 89/91. | Direct | decompile and source consistency | UID00030W | incorporate | applied |
| C26 | NewMacroDialog constructor R4 reads `.code/.isSpellMode`; score remains 90/93. | Direct | constructor disassembly and UI API | UID00049J | incorporate | applied |
| C27 | SaveMacroEntries R5 writes `.code/.isSpellMode`; recommend 89/92. | Direct | exact getter/store calls | UID00049N | incorporate | applied |
| C28 | LoadMacroPage R6 reads `.code/.isSpellMode`; recommend 89/92. | Direct | exact load/setter calls | UID00049O | incorporate | applied |
| C29 | UserPane class/file and UID0001KM retain scores/routes/formals but gain exact target ownership, retained-liveness, ABI, and field evidence. | Strong | current union plus fresh target pass | UserPane class/file/parent | incorporate | applied |
| C30 | LivingObjectPane class/file must remove UID0003UA from current ownership and retain it only as superseded history; scores/formals unchanged. | Strong | C14-C15 | LivingObjectPane class/file | reject-stale | applied |
| C31 | UID0001KN/UID0003UC caller prose must use `isSpellMode == 0` / `!= 0` and current UserPane owner while preserving all callee facts/formals/scores. | Strong | target calls/current metadata | two callee pages | incorporate | applied |
| C32 | Historical B013/B001 facts remain evidence, but stale owner/layout/formal conclusions are explicitly historicalized. | Strong | report comparison | all touched history sections | historicalize | applied |
| C33 | UID0003UB and UID0003UJ remain verify-only formals; stale Config/Living owner rationales may be historicalized only where shared support text is touched. | Bounded | separate target scopes/current pages | verify-only readback | not-applicable | excluded-with-reason |
| C34 | Generated callback expectation is one exact UID0003UA body, direct Config field, consistent code/isSpellMode names, class closure before definitions, and no target marker/duplicate/raw ABI code. | Strong | current generator topology | waited UserPane/Config/ProfileStorage/MacroDialogs readback | incorporate | applied |
| C35 | Exact manual supervisor-owned coverage changes below are required; B003 must not edit coverage. | Direct docs | current manual rows | supervisor coverage handoff | incorporate | applied |
| C36 | B005 owned the earlier shared Config/UserPane callback lane; B003 had to wait, reread, and rebase without loss before applying shared edits. | Direct current-state | B005 goal/report/current hashes | callback collision gate/checklist | incorporate | applied |

### C01-C36 Implementation Proof

| Claim | Implementation proof |
| --- | --- |
| C01 | Evidence-time MCP facts remain in the report and target prose; session `64c11373`, healthy server state, and real bounded bytes are preserved without an indefinite-current session claim. |
| C02 | UID0003UA retains exact `[0x005a3a20,0x005a3ad4)`, 0xb4/180-byte size, and SHA256 evidence; validator `13312` passed. |
| C03 | UID0003UA records the no-function-object result, 65-instruction body, source-authored disposition, and two `retn 8` exits; validator `13312` passed. |
| C04 | Target and UID0001KM retain predecessor/fill and exact twelve-byte `[0x005a3ad4,0x005a3ae0)` alignment; validators `13312` and `13320` passed; ignored padding was verify-only. |
| C05 | UID0003UA ABI prose and R1 preserve signed-short first parameter plus unnamed unread second `int`; validator `13312` and exact R1 readback passed. |
| C06 | UID0003UA explicitly retains `[ebp+0xb]` as first-home-slot compiler scratch and excludes it from source; validator `13312` passed. |
| C07 | Exact selector mapping and lack of internal guard are present in UID0003UA/R1; validator `13312` and generated R1 count 1 passed. |
| C08 | Direct `Config+0x28f29c` 20x4 storage and rejection of nested `m_userProfile` are present across target, Config, global, and profile slice; validators `13312`, `13323`-`13326` passed. |
| C09 | `wchar_t code`, byte `isSpellMode`, and natural tail alignment are synchronized in Config, g_pConfig, profile slice, defaults, and macro pages; validators `13323`-`13327` and `13313`-`13315` passed. |
| C10 | R1-R6 and support prose consistently use `unsigned char isSpellMode` and preserve arbitrary nonzero behavior; all six blocks match exactly and emit once. |
| C11 | UID0003UA/R1 use signed-low-byte `_isalpha` without unsigned normalization; validator `13312` and generated R1 exact containment passed. |
| C12 | Lowercase 1..26, uppercase 27..52, `0xff` fallback, and non-alpha return are exact in UID0003UA/R1 and parent/class/file prose; validators `13312`, `13320`-`13322` passed. |
| C13 | UID0003UA, UID0001KN, and UID0003UC use `isSpellMode != 0` for command and zero for inventory; validators `13312`, `13316`, and `13317` passed. |
| C14 | Target/UserPane pages make UID0000FQ current owner and LivingObjectPane pages retain old ownership only as history; validators `13312`, `13318`-`13322` passed. |
| C15 | UID0000P1/UserPane.cpp route is current in target, parent, class, and file; validators `13312`, `13320`-`13322` and generated command `13328` passed. |
| C16 | Exhaustive no-entry-route evidence remains target/parent history and does not suppress emission; validators `13312` and `13320` passed. |
| C17 | Exact-duplicate negative and UID0003UJ comparator classification remain; UID0003UJ readback SHA256 `F2F18BC6A7C20731F66026F689F81E05A79479DCDAD2B7C6570182A89B23FFD7` was unchanged. |
| C18 | UID0003UA is source-authored retained legacy/dead code, reconstructable and emitting; validator `13312` and zero target Empty Emitter Marker under command `13328` prove the applied disposition. |
| C19 | Existing collision-safe title/path/name were retained; validator `13312` preserved UID0003UA and exact path. |
| C20 | UID0003UA is `91/93`, owner/emitter UID0000FQ, true, blank position, `Nested:0`, exact range, and exact R1; validator `13312` passed. |
| C21 | `by-class/Config.md` retains complete B005 layout and matches R2 exactly after only `mode -> isSpellMode`; validator `13323` passed. |
| C22 | Both Config class/file current prose say `CompactShortcutRecord` is 0x4; validators `13323` and `13324` passed. |
| C23 | UID00028Q remains base-typed `Config *` at `88/92`, with natural tail and stale blocker historicalized; validator `13325` passed. |
| C24 | UID0001VR is `90/92` with unchanged comment-only formal and complete direct-Config arrangement; validator `13326` passed. |
| C25 | UID00030W is `89/91` and matches R3 exactly; validator `13327` and RegistryConfig.cpp generated body count 1 passed. |
| C26 | UID00049J remains `90/93` and matches R4 exactly; validator `13313` and MacroDialogs generated body count 1 passed. |
| C27 | UID00049N is `89/92` and matches R5 exactly; validator `13314` and MacroDialogs generated body count 1 passed. |
| C28 | UID00049O is `89/92` and matches R6 exactly; validator `13315` and MacroDialogs generated body count 1 passed. |
| C29 | UID0001KM/UserPane class/file retain their scores/routes/formals and contain the complete additive UID0003UA ownership, liveness, ABI, and field evidence; validators `13320`-`13322` passed. |
| C30 | LivingObjectPane class/file retain unrelated 0x20c/base/helper evidence and treat UID0003UA only as superseded history; validators `13318` and `13319` passed. |
| C31 | UID0001KN/UID0003UC caller prose uses current UserPane and `isSpellMode` semantics while bodies/formals/scores remain unchanged; validators `13316` and `13317` passed. |
| C32 | Every touched page retains dated B013/B001 provenance while current owner/layout/formal claims are corrected; all scoped validators `13312`-`13327` passed. |
| C33 | UID0003UB and UID0003UJ formals/pages were verify-only and unchanged at SHA256 `6B94291906ABC770754DADCACE25CAF1A9ECF923FF122773FA074EFD686DB433` and `F2F18BC6A7C20731F66026F689F81E05A79479DCDAD2B7C6570182A89B23FFD7`; only shared support prose historicalizes stale rationale. |
| C34 | Waited command `13328` emitted R1-R6 once each; UserPane class closes before definitions, UID0003UA definition/provenance/path counts are 1/1/1, target marker count is 0, 37 qualified UserPane definition names are unique, and ABI-artifact counts are zero. |
| C35 | The exact manual supervisor-owned coverage handoff below remains unchanged and complete. B003 applied it to no coverage file; manual coverage/lifecycle state remains external. |
| C36 | B003 completed disjoint pages first, observed B005's terminal 56/56 checklist and zero shared leases, reread terminal B005/B002 artifacts and all live shared pages, then rebased serially. The externally executed B005 artifact `executed-b-agent-research/B005/0003UP-UserPaneHandleMovementReplyPacket-source-quality.md`, SHA256 `CB31E9B73313D6E87D94F83515D2FE1F8402C81D908CD25424F3920ED3C400FF`, records validator-owned execution command `13340` and explicitly preserves B003 shared hashes `913963EF...03EA`, `31F6DC7C...1B88`, and `0B19A8D0...2A3`; current B002 SHA256 `14DE947B...B13B` preserves the H5/HUZ/H4 chain. Final post-execution readback found all eight shared hashes unchanged and the B002/B005/B003 semantic union intact. |

## Positive Evidence Summary

- The exact 180-byte body has a normal member prologue, stable receiver, selector logic, Config load, CRT classification, two UserPane calls, and two source-level return paths.
- Exact Config offsets, profile default/load/save, macro UI, and runtime use all converge on one 20x4 compact array at +0x28f29c.
- Current complete Config layout directly exposes the array without casts, nesting, raw offsets, or placeholders.
- Both call targets are current UserPane members; target placement between UserPane local-player methods and its existing UserPane declaration provide the strongest source owner.
- Profile migration supplies a concrete reason an old dispatcher can remain in the linked image without a live entry.
- The formal recommendation preserves every binary edge while removing only reverse-engineering/source-invalid artifacts.

## IDA MCP Facts

- Database at evidence collection and the final bounded recheck: session `64c11373` was active/adopted for NexusTK IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x00400000`.
- Health at evidence collection and final recheck: `ok`; auto-analysis, Hex-Rays, and strings cache ready; cache size 2067. The final valid `get_bytes` call at `2026-07-15T16:50:46.6848499-04:00` returned `55 8b ec 51 0f bf 45 08 53 56 57 8b f9 85 c0 75` from `0x005a3a20` with `isError:false`.
- `lookup_funcs`: target start and end are not functions; successor `0x005a3ae0` is `sub_5A3AE0`, size 0x259; callees `0x005a3e30` and `0x005a4530` are modeled sizes 0x1c3 and 0x3d8; `_isalpha` is 0x2f bytes.
- Exact bytes: target size 0xb4, SHA256 `BAA84BF5C37F66CF1DFBC68667C8B41FD50FFF943A9B55207AACAB2F52358E13`.
- Disassembly: 65 target instructions through 0x5a3ad3, 17 derived raw basic blocks, branch labels at the selector, classification, mapping, and dispatch joins, returns at 0x5a3ac3 and 0x5a3ad1.
- Xrefs: zero to 0x5a3a20 and 0x5a3ad4; one positive-control call to successor at 0x5a5ce5; eight xrefs each to UseInventorySlot and UseCommandSlot, including target calls 0x5a3ac6/0x5a3ab8.
- `find_bytes`: target VA dword `20 3A 5A 00` zero; target RVA dword `20 3A 1A 00` zero; entry/body and mode-dispatch signatures each exactly one hit at 0x5a3a24 and 0x5a3aad.
- Boundary: previous code ends `5e c3` at 0x5a3a10-11 then 14 `cc`; target starts 0x5a3a20; 12 `cc` occupy `[0x5a3ad4,0x5a3ae0)`; successor begins `55 8b ec 81 ec 34 02 00`.
- Direct compact-row references: defaults at 0x48ebc0, profile load/migration at 0x4f95b0, save at 0x50aba0, NewMacroDialog constructor/save/load at 0x53ed90/0x53f180/0x53f210, NewMacroEditControlPane paint/input at 0x57faa0/0x57fc80, and target.
- Negative IDA facts: no target function/xref, no pointer/table/vtable/RTTI/exception/export route, no exact duplicate body, no second-slot read, no selector/null guard, and no +3 record-byte lifecycle.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005a3a20-0x005a3ad4` | UID0003UA target | Retained UserPane compact-shortcut member | true | UID0000FQ | implemented 91/93 | exact unsplit target |
| `0x005a3ad4-0x005a3ae0` | UID0000VN ignored row | Twelve-byte parent-owned alignment | false | UID0001KM | unchanged | verify-only padding |
| `0x005a3ae0-0x005a3d39` | UID0003UB | Integrated macro executor | true | UID0000FQ | 90/92 | separate adjacent member; formal verify-only |
| `0x005a3e30-0x005a3ff3` | UID0001KN | One-based inventory slot dispatcher | true | UID0000FQ | 92/94 current | caller-prose sync only |
| `0x005a4530-0x005a4908` | UID0003UC | One-based spell/command dispatcher | true | UID0000FQ | 88/92 current | caller-prose sync only |
| `0x005a9250-0x005a9307` | UID0003UJ | Separate retained legacy function-key helper | true | UID0000FQ current | unchanged | comparison/verify-only |
| `Config + 0x28f29c`, 20x4 | UID0001VR slice / UID000031 declaration | Compact shortcut storage | true source data | Config | implemented slice 90/92 | direct declaration R2 |

- Relative `Nested` analysis: current address-sorted predecessor/successor metadata do not introduce a parent delta at this exact child. Target remains `Nested:0`; this number is not a child count. The parent UID0001KM level is unchanged.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| 0x005a3a20 | zero xrefs | No recovered live entry. |
| 0x005a3ad4 | zero xrefs | No route to end/alignment. |
| 0x005a3ab8 -> 0x005a4530 | UserPane::UseCommandSlot | Nonzero compact spell-mode route. |
| 0x005a3ac6 -> 0x005a3e30 | UserPane::UseInventorySlot | Zero compact item-mode route. |
| 0x005a3a6f -> 0x005de870 | `_isalpha` | Signed low-byte classification. |
| 0x005a5ce5 -> 0x005a3ae0 | UserPane key handler -> UID0003UB | Positive control and modern integrated route; not a target caller. |
| 0x0048ebc0 writers | compact rows 0..19 | Defaults code a..t and mode 1. |
| 0x004f95b0 readers/writers | compact profile/migration | Reads code plus `S` equality and migrates into integrated table. |
| 0x0050aba0 readers | compact profile save | Writes code plus S/I from nonzero/zero mode. |
| 0x0053ed90/0x0053f180/0x0053f210 | NewMacroDialog UI | Constructs, saves, and loads two ten-row pages. |
| 0x0057fc80 | NewMacroEditControlPane input | Stores alphabetic key and mode from active child 2/3 equality. |

## Documentation Evidence And IDA Status

- Current authoritative metadata already assigns the target and both callees to UserPane. Nested LivingObjectPane prose is stale, not an ownership tie.
- UID0000FQ declares the target and both callees. Its complete class begins after the exact 0x20c LivingObjectPane base and contains UserPane-only state used by the callee implementations.
- UID000031 is now 90/92 with a complete 0x291918 class declaration. Older current-sounding paragraphs denying a declaration-complete route must become explicitly historical.
- UID0001VR and UID00028Q still describe byte +3 as padding/unknown and retain current-sounding declaration blockers. Live lifecycle checks prove natural tail padding and the complete declaration now exists.
- ProfileStorage generated source already uses `code/isSpellMode`; Config and MacroDialogs generated source use conflicting names; UserPane generated source additionally uses a nonexistent nested object. This is a source-consistency defect, not evidence for three different source layouts.
- B005's accepted UID0003UP callback changed shared Config/UserPane pages during Gate-1 research and was still active at the bounded evidence-time recheck. Baseline hashes below are historical timestamped snapshots; the authorized callback later confirmed terminal state, reread, and rebased as recorded under C36 and Changed Files.

## Ranked Ownership Analysis

### 1. UserPane / UID0000FQ

- Evidence for: current class declaration, existing target metadata, receiver-preserving calls to two current UserPane members, derived-only callee storage, exact source neighborhood, broad UID0002QY source integration, and generated route.
- Evidence against: no direct `this` field read in the target and no surviving caller.
- Decision: accepted. The absence of a field read does not outweigh the impossible base-to-derived call shape under LivingObjectPane ownership.

### 2. LivingObjectPane / UID00007B

- Evidence for: historical B001/B013 clustering, shared receiver ancestry, and old callee ownership.
- Evidence against: current exact callee pages and source union move the callees to UserPane; LivingObjectPane ends at 0x20c; old report predates the complete derived layout.
- Decision: rejected-stale as current ownership; preserve only historical provenance.

### 3. Config / RegistryConfig / ProfileStorage

- Evidence for: they own or persist the compact data.
- Evidence against: target receiver is forwarded to UI action dispatchers, not Config; no Config method call shape or source-file adjacency.
- Decision: rejected as executable owner; retained as storage/support owners.

### Proposed new file/grouping, if applicable

- Not applicable. UID0000P1 already owns `NexusTK/ui/panels/UserPane.cpp`; no new class/file/aggregate is justified.

## Source Placement

- Recommended source placement: member definition in `NexusTK/ui/panels/UserPane.cpp`, declared by UID0000FQ and emitted through UID0000P1.
- The method belongs beside the local-player hotkey/action helpers in source order, before UID0003UB.
- Rejected placements: LivingObjectPane.cpp (stale derived-callee conflict), Config.cpp/RegistryConfig.cpp (storage not behavior), ProfileStorage.cpp (serialization only), MacroDialogs.cpp (editor UI only), and a raw/recovered helper file (tool-artifact organization).
- Remaining uncertainty: the exact original header declaration name and second parameter spelling/type are stripped; current descriptive declaration is source-safe.

## Range / Split / Padding / Reclassification Analysis

- Exact target range remains `[0x005a3a20,0x005a3ad4)`, size 0xb4/180.
- Previous body returns at 0x005a3a11 and fill extends to 0x005a3a1f. Target starts with a separate prologue.
- Target has two complete `retn 8` exits and no fallthrough into successor.
- `[0x005a3ad4,0x005a3ae0)` is exactly twelve 0xcc bytes already represented as parent/ignored alignment; it is not absorbed into the target.
- UID0003UB starts at 0x005a3ae0 with a distinct security-cookie frame and integrated-table behavior.
- No split, merge, child creation, rename, padding move, or reconstructable reclassification is recommended.
- Parent UID0001KM remains a non-emitting mixed index at its current score/route; target `Nested:0` remains the correct relative delta.

## Negative Evidence Summary

- No target function object or xref exists in IDA.
- Local PE scan found zero rel32 E8/E9, short branch, near conditional branch, absolute VA dword, or RVA dword destinations to the target.
- No vtable, RTTI, exception, export, callback table, jump table, pointer table, or computed-entry evidence was found.
- No exact duplicate body, mode-dispatch tail, or compact-record indexing sequence was found elsewhere. UID0003UJ is not equivalent.
- No target call exists from modern key handling; the live route is UID0003UB.
- No evidence supports LivingObjectPane as current owner once derived-only callee ownership is considered.
- No nested Config aggregate, RegistryConfig-only field, explicit cast, accessor call, or separate compact-record global exists.
- No source-visible `reserved` member exists at record +3.
- No evidence recovers the second parameter's semantics. The report does not invent them.
- These negatives cap liveness/name confidence but do not erase a complete source-authored body.

## IDA Rename / Type / Comment Recommendations

- Source-facing method: retain `UserPane::DispatchConfiguredShortcutHotkey` as descriptive, not symbol-proven.
- Source-facing first parameter: `short hotkeyNumber` is direct ABI fact plus descriptive role.
- Source-facing second parameter: unnamed `int`; exact semantic type remains unavailable.
- Source-facing record: `CompactShortcutRecord`, `wchar_t code`, `unsigned char isSpellMode`, `m_compactShortcutRecords[20]`.
- Source-facing calls: `UseCommandSlot` and `UseInventorySlot` under UserPane.
- Comments should state retained/no-live-route history, direct Config placement, selector contract, signed low-byte classification, and natural tail alignment.
- Intentionally unchanged: target path/title, owner/emitter UID, class/file route, and IDA database names. No IDA mutation is requested or permitted.

## First-Draft C++ Recommendation

- Eligible for exact human source C++: yes. Six complete destination-specific managed blocks follow.
- Destination R1: replace the complete managed target block in `by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md` exactly with:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserPane::DispatchConfiguredShortcutHotkey(
    short hotkeyNumber, int)
{
    int shortcutIndex;
    if (hotkeyNumber == 0)
        shortcutIndex = 9;
    else if (hotkeyNumber == 10)
        shortcutIndex = 19;
    else
        shortcutIndex = hotkeyNumber - 1;

    const CompactShortcutRecord &shortcut =
        g_pConfig->m_compactShortcutRecords[shortcutIndex];

    if (!isalpha(static_cast<char>(shortcut.code)))
        return;

    unsigned char slot;
    if (shortcut.code >= L'a' && shortcut.code <= L'z')
        slot = static_cast<unsigned char>(shortcut.code - L'a' + 1);
    else if (shortcut.code >= L'A' && shortcut.code <= L'Z')
        slot = static_cast<unsigned char>(shortcut.code - L'A' + 27);
    else
        slot = 0xff;

    if (shortcut.isSpellMode != 0)
        UseCommandSlot(slot);
    else
        UseInventorySlot(slot);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination R2: replace the complete managed block in `by-class/Config.md` exactly with the current complete declaration plus the source-consistent compact field name:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class List;
class LObject;
class SimpleUStringVector;
class ILauncherAuthentication;

template <typename Character>
class StringBase;

struct ConfigEntry
{
    ConfigEntry();
    ~ConfigEntry();

    unsigned char selector;
    wchar_t *primaryText;
    wchar_t *secondaryText;
    wchar_t *tertiaryText;
    unsigned short value;
    unsigned short state;
    unsigned short flags;
};

void ReleaseConfigEntryOwnedBuffers(ConfigEntry *entry);
errno_t GetLocalPlayerName(wchar_t *destination, size_t destinationCount);

struct ConfigEntryBlock
{
    ConfigEntry entries[32];
    int count;
    unsigned char dirty;

    void ReleaseOwnedBuffers();
};

struct ConfigMidiTrackPathEntry
{
    unsigned char selector;
    wchar_t path[32];
};

struct ConfigCharacterServerText
{
    unsigned short length;
    wchar_t text[256];
};

struct ConfigMacroName
{
    unsigned short length;
    wchar_t text[128];
};

struct ConfigCharacterServerMacroRow
{
    ConfigCharacterServerText playerName;
    ConfigCharacterServerText serverName;
    unsigned char macroEnabled[20];
    ConfigMacroName macroNames[20];
    wchar_t primaryMacroKeys[20];
    wchar_t primaryMacroText[20][256];
    wchar_t alternateMacroKeys[20];
    wchar_t alternateMacroText[20][256];
    int selectedMacroIndex;
};

struct ChatColorPair
{
    unsigned char foreground;
    unsigned char background;
};

struct CompactShortcutRecord
{
    wchar_t code;
    unsigned char isSpellMode;
};

struct MacroHotkeyRecord
{
    enum State {
        Text = 1,
        Spell = 2,
        Item = 3
    };

    unsigned short ordinal;
    State state;
    wchar_t text[0x80];
};

struct TargetOptionRow
{
    unsigned char userEnabled;
    unsigned char monsterEnabled;
};

struct DialogPositionRecord
{
    int x;
    int y;
    int state;
};

class Config : public LObject
{
public:
    Config();
    virtual ~Config();
    virtual void SaveToRegistry() = 0;
    virtual bool LoadFromRegistry() = 0;

    int FindOrAppendFixedConfigTableRow();
    void ResetFixedConfigTableRows();

    void CopyMidiTrackPathsTo(List *destination) const;
    void CopyMidiTrackPathsFrom(List *source);
    void GetMidiTrackPath(unsigned char selector, wchar_t *destination, size_t destinationCount) const;
    void SetMidiTrackPath(unsigned char selector, const wchar_t *source);
    void SetLogData(const wchar_t *source);

    ConfigCharacterServerMacroRow m_fixedConfigRows[100];
    int m_fixedConfigRowCount;
    int m_selectedServerId;
    unsigned char m_multiServerEnabled;
    unsigned char m_alternateServerEndpointActive;
    union {
        char m_thrunetAuthenticationToken[64];
        struct {
            char m_lgInternetSessionId[64];
            char m_lgInternetSessionKey[64];
        };
        char m_launcherPayload[2][64];
        ILauncherAuthentication *m_launcherAuthenticationObject;
        struct {
            char m_kornetWorldPayload[3][16];
            char m_kornetWorldPayloadData[256];
        };
    };
    ConfigEntryBlock m_serverDirectory;
    StringBase<char> m_loginServerAddress;
    unsigned int m_loginServerPort;
    unsigned int m_auxiliaryServerPort;
    unsigned int m_serverMode;
    unsigned char m_startupConnectionMode;
    unsigned int m_terminalBaudRate;
    unsigned short m_fontIndex;
    unsigned char m_iconPaneReducedMode;
    unsigned int m_registryClassIdSeed;
    unsigned char m_adapterPhysicalAddressDigest[16];
    unsigned char m_soundEffectsEnabled;
    unsigned int m_soundVolume;
    unsigned char m_musicEnabled;
    unsigned int m_musicVolume;
    unsigned char m_mapEffectEnabled;
    unsigned char m_sayWithEnter;
    unsigned char m_doubleClickEnabled;
    unsigned char m_autoMoveEnabled;
    unsigned char m_balloonFillEnabled;
    unsigned char m_staticObjectTransparencyEnabled;
    unsigned char m_shadowEnabled;
    unsigned char m_showUserName;
    unsigned char m_selfLookTopButtonSelected;
    unsigned char m_selfLookBottomButtonSelected;
    unsigned char m_targetSelectionSuppressed;
    unsigned char m_tabVSwap;
    unsigned char m_showDamage;
    unsigned char m_groupBarEnabled;
    unsigned char m_carnageColorEnabled;
    unsigned int m_graphicsSetting;
    unsigned char m_orbTargetShare;
    unsigned char m_f1Swap;
    unsigned char m_whisperEnabled;
    unsigned char m_shoutEnabled;
    unsigned char m_adviceEnabled;
    unsigned char m_hearSnoreMode;
    unsigned char m_magicEffectsEnabled;
    unsigned char m_weatherEffectsEnabled;
    unsigned char m_fixedMovementEnabled;
    unsigned char m_mapMovementStatusOption;
    unsigned char m_seeThroughEnabled;
    unsigned char m_hearEmotions;
    unsigned int m_chatVisibleLineCount;
    unsigned int m_chatHandleModeIndex;
    unsigned char m_secondaryChatEnabled;
    unsigned char m_chatHandleLeftToggle;
    ChatColorPair m_chatColorPairs[6];
    unsigned char m_clickMoveEnabled;
    unsigned char m_clickLookEnabled;
    unsigned int m_systemMessageHeight;
    unsigned short m_powerDialogThresholdDefaults[4];
    wchar_t m_profileTextSlots[10][0x80];
    wchar_t m_legacyShortcutText[10][0x80];
    CompactShortcutRecord m_compactShortcutRecords[20];
    MacroHotkeyRecord m_macroHotkeys[30];
    TargetOptionRow m_targetOptionRows[2];
    StringBase<wchar_t> m_profileStringSlots[20];
    wchar_t m_serverEndpointText[64];
    unsigned int m_serverEndpointPrefix;
    List *m_midiTrackPaths;
    wchar_t m_selectedProfileName[0x100];
    DialogPositionRecord m_dialogPositions[21];
    unsigned char m_startupAddress[16];
    wchar_t m_startupHostName[128];
    union {
        unsigned int m_startupPort;
        unsigned int m_launcherAuthenticationToken;
    };
    unsigned short m_startupServerId;
    unsigned short m_startupReady;
    wchar_t *m_logDataText;
    wchar_t m_lastServerName[16];
    wchar_t m_startupLaunchCommand[256];
    StringBase<wchar_t> m_startupLauncherId;
    unsigned int m_soundLatency;
    unsigned short m_systemHelperFlags;
    SimpleUStringVector m_blockListenNames;
    unsigned int m_musicSourceMode;
    StringBase<wchar_t> m_musicFolderPath;
    wchar_t m_redbookDriveLetter;
    unsigned char m_randomizeMusicOrder;
    unsigned char m_repeatMusic;
    unsigned char m_musicOutputSelection;
    unsigned char m_showMiniMapPortals;
    unsigned char m_showMiniMapNpcs;
    unsigned char m_showMiniMapPartyMembers;
};

extern Config *g_pConfig;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination R3: replace the complete managed block in `by-memory/0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults.md` exactly with:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void RegistryConfig::InitializeUserDataDefaults()
{
    for (int i = 0; i < 10; ++i)
        wcscpy_s(m_profileTextSlots[i], _countof(m_profileTextSlots[i]),
                 g_pLanguageMan->GetLocalizedString(67 + i));

    for (int i = 0; i < 10; ++i)
        wcscpy_s(m_legacyShortcutText[i], _countof(m_legacyShortcutText[i]), L"");

    wcscpy_s(m_selectedProfileName, _countof(m_selectedProfileName), L"");

    for (int i = 0; i < 20; ++i) {
        m_compactShortcutRecords[i].code = static_cast<wchar_t>(L'a' + i);
        m_compactShortcutRecords[i].isSpellMode = 1;
    }

    for (int i = 0; i < 30; ++i) {
        m_macroHotkeys[i].ordinal = static_cast<unsigned short>(i);
        m_macroHotkeys[i].state = MacroHotkeyRecord::Spell;

        const wchar_t key =
            static_cast<wchar_t>((i < 26) ? (L'a' + i) : (L'A' + (i - 26)));
        m_macroHotkeys[i].text[0] = key;
        m_macroHotkeys[i].text[1] = L'\0';
    }

    m_targetOptionRows[0].userEnabled = 1;
    m_targetOptionRows[0].monsterEnabled = 1;
    m_targetOptionRows[1].userEnabled = 1;
    m_targetOptionRows[1].monsterEnabled = 0;

    for (int i = 0; i < 20; ++i)
        m_profileStringSlots[i].Assign(L"");

    m_blockListenNames.Clear();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination R4: replace the complete managed block in `by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md` exactly with:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
NewMacroDialog::NewMacroDialog()
    : DialogPane(kMacroDialogCaption, 6, true),
      m_currentPage(0)
{
    g_pGeneralPurposePanel->SwitchActiveChild(3, false);
    PrepareMacroDialogPalette(g_pMacroDialogPalette, 0x198, 100);

    AddControl(new ResourceImagePane(L"DLGMAC2.EPF", Rect(0, 0, 289, 399), L"DLGMACRO.PAL"));
    AddControl(new ImageButtonControlPane(kMacroOkImageId, Rect(118, 362, 181, 386)));

    for (int row = 0; row < 10; ++row)
    {
        CompactShortcutRecord &record = g_pConfig->m_compactShortcutRecords[row];
        const int y = 54 + row * 29;
        AddControl(new NewMacroEditControlPane(
            record.code,
            row,
            record.isSpellMode,
            Rect(19, y, 268, y + 20)));
    }

    ImageButtonControlPane *previous = new ImageButtonControlPane(kMacroPreviousImageId, Rect(30, 362, 93, 386));
    previous->Disable();
    AddControl(previous);

    AddControl(new ImageButtonControlPane(kMacroNextImageId, Rect(200, 362, 263, 386)));

    SetHoverControl(2);
    SetModal(true);
    SetCloseOnEscape(true);
    SetBackgroundResource(L"DLGMACRO.EPF");
    SetBounds(Rect(130, 10, 419, 409));
    SetLayer(g_pDialogLayer);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination R5: replace the complete managed block in `by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md` exactly with:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewMacroDialog::SaveMacroEntries()
{
    const int baseIndex = m_currentPage * 10;

    for (int row = 0; row < 10; ++row)
    {
        NewMacroEditControlPane *edit = GetChild<NewMacroEditControlPane>(2 + row);
        CompactShortcutRecord &record = g_pConfig->m_compactShortcutRecords[baseIndex + row];

        record.code = edit->GetKey();
        record.isSpellMode = edit->GetMode();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination R6: replace the complete managed block in `by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md` exactly with:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewMacroDialog::LoadMacroPage(int page)
{
    if (m_currentPage == page)
        return;

    m_currentPage = page;

    const int baseIndex = page * 10;
    for (int row = 0; row < 10; ++row)
    {
        NewMacroEditControlPane *edit = GetChild<NewMacroEditControlPane>(2 + row);
        const CompactShortcutRecord &record = g_pConfig->m_compactShortcutRecords[baseIndex + row];

        edit->SetRecordIndex(baseIndex + row);
        edit->SetKey(record.code);
        edit->SetMode(record.isSpellMode);
        edit->Refresh();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- R1 preserves exact target behavior: no selector/null guard, signed low-byte classifier, full-wchar range checks, 0xff fallback, and branch order.
- R2 preserves B005's complete Config union and exact 0x291918 layout; changing one one-byte field name does not alter layout.
- R3-R6 align all direct compact-record source with ProfileStorage's existing `code/isSpellMode` spelling while preserving every original call/order/edge.
- Third-party import directive: not applicable; this is NexusTK application source.

## Final Recommendation

- C01-C36 and R1-R6 were applied after exact-artifact Gate 1 in the separately authorized callback.
- Implemented target: 91/93, owner/emitter UID0000FQ, true, blank position, Nested0, exact range/path/title, and exact R1.
- Implemented direct support: complete Config remains 90/92 and Config file 90/91; compact field/size/source-state prose, g_pConfig, profile slice, R3-R6, and exact UserPane/LivingObjectPane/callee/parent history are synchronized without unrelated formal or route changes.
- UID0003UB and UID0003UJ direct formals remained verify-only. UID0003UB's historical Config blocker is no longer current, and no separate unaccepted body was installed.
- No new file, UID, child, split, rename, import, IDA edit, or raw compiler support was introduced.

## Recommended Target Doc Changes

- Target path: `by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md`.
- Applied completion/confidence 91/93 while preserving UID, path/title, range, canonical owner/emitter UID0000FQ, true, blank position, and Nested0.
- Item Summary: `Retained UserPane compact-shortcut dispatcher with exact selector-to-row mapping, direct Config storage, signed narrow classification, key-to-slot conversion, spell/item branch ordering, two ABI slots, exhaustive no-entry-route evidence, and source-retention history.`
- R1 is installed exactly.
- Contradictory current LivingObjectPane, nested Config, schematic record, unsigned classification, `unused`, and score-cap prose was replaced or historicalized with the exact C01-C20 evidence.
- All exact byte/range/CFG/xref/callee/padding/no-route/history facts remain; old owner/type/formal conclusions are labeled historical rather than removed.

## Recommended Support Doc Changes

| Support path | Exact applied delta | Score/formal disposition |
| --- | --- | --- |
| `by-class/Config.md` | Applied R2; corrected `CompactShortcutRecord 0x84` typo to 0x4; added exact compact lifecycle/target evidence; historicalized old no-declaration current wording. Complete B005 union preserved. | Kept 90/92, owner/emitter/path/position. |
| `by-file/Config.md` | Corrected 0x84 typo, added direct compact storage/source consistency, and preserved the B005 full module union. | Kept 90/91 and route. |
| `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` | Replaced padding/unknown with natural tail alignment; applied code/isSpellMode; added direct target access and complete Config current state; historicalized stale blocker. | Kept 88/92/formal/route. |
| `by-type/by-struct/RegistryConfigUserProfileBlock.md` | Resolved direct Config arrangement, exact code/isSpellMode/natural-tail contract, signed target classifier, UserPane owner, and stale declaration blocker. | Applied 88/88 -> 90/92; comment-only formal unchanged. |
| `by-memory/0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults.md` | Applied R3 while preserving all unrelated defaults and ordering. | Applied 88/90 -> 89/91. |
| `by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md` | Applied R4 and exact field semantics; preserved all controls/resources/no-xref facts. | Kept 90/93. |
| `by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md` | Applied R5 and exact field semantics. | Applied 88/91 -> 89/92. |
| `by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md` | Applied R6 and exact field semantics. | Applied 88/91 -> 89/92. |
| `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` | Preserved the non-emitting index and exact target range/alignment/order; added current UserPane/retained/ABI/record evidence. | Score/route/formal/Nested unchanged. |
| `by-class/UserPane.md` | Preserved the complete class block; added exact target semantics and historicalized LivingObject/config blocker prose. Existing declaration retains a parameter name because it does not affect ABI; R1 definition is unnamed. | Kept 93/94 and complete formal. |
| `by-file/UserPane.md` | Added source-order/retained compact dispatcher and generated expectations; removed current LivingObject/no-source contradiction. | Kept 92/93 and route. |
| `by-class/LivingObjectPane.md` | Removed UID0003UA from current class ownership and classified the old section/table as superseded history. Preserved all unrelated 0x20c/base/source facts. | Scores/formal unchanged. |
| `by-file/LivingObjectPane.md` | Removed UID0003UA from current file ownership and retained B013/B001 only as historical provenance. | Scores/route unchanged. |
| `by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md` | Updated target caller to UserPane and `isSpellMode == 0`; preserved all eight xrefs, body, formal, and score. | Unchanged. |
| `by-memory/0x005a4530-0x005a4908.UserPaneUseCommandSlot.md` | Updated target caller to UserPane and `isSpellMode != 0`; historicalized stale LivingObject ownership only in target-specific prose. | Unchanged. |

- Verify-only rereads completed: UID0003UB, UID0003UJ, UID00019T, UID0001AV, ProfileStorage file, NewMacroDialog class, NewMacroEditControlPane class/method family, MacroDialogs file/aggregate, Config constructor/destructor, RegistryConfig class/file, `isalpha`, UserPane generated output, and ignored alignment remained unchanged absent contradiction.
- Shared collision rule was satisfied: B003 waited for B005's terminal checklist and lease release, reread its terminal report plus B002 and every shared destination, preserved the complete Config/UserPane/movement union, and applied only this report's delta.

## Score And Metadata Recommendation

- UID0003UA is implemented at 91/93 from the 87/88 baseline. Completion rises because owner, direct container, ABI scratch, signed classification, record type/name, liveness, complete formal, and support compilation are resolved. Confidence rises because fresh MCP/raw scans and all storage lifecycle routes agree.
- Reason not higher: no recovered live entry, original method spelling, source semantic for the second ABI slot, or original compact type/member spelling.
- UID0001VR is 90/92 from 88/88 because the complete Config declaration and exact compact field lifecycle remove its former declaration/layout blocker; comment-only slice disposition remains.
- UID00030W is 89/91 from 88/90 because its formal is source-consistent and compact field semantics are exact; unrelated private names remain caps.
- UID00049N and UID00049O are 89/92 from 88/91 because direct field names/types and profile/UI semantics are resolved; original private names remain inferred.
- UID000031 90/92, UID0000IE 90/91, UID00028Q 88/92, UID00049J 90/93, UID0000FQ 93/94, UID0000P1 92/93, UID0001KM, LivingObjectPane pages, and callee pages retain scores/routes.
- Score-improvement attempt: direct route scans remained negative; pointer/table/exception/vtable routes remained negative; exact duplicate/inlining scans remained negative; profile migration explained retention; fresh disassembly resolved stack alias and signed classification; all producers/consumers resolved storage semantics; complete Config current state removed source compilation blockers. The surviving caps are precise and nonblocking.

## Open Questions With Attempted Resolution

- **Live caller:** xrefs, branch-destination scans, VA/RVA pointers, tables, exceptions, vtables, exports, and exact duplicate patterns were exhausted. None exists. Best resolution is retained dead/legacy source after compact-to-integrated migration. This caps liveness confidence but not emission.
- **Second ABI parameter:** no caller and no read of `[ebp+0xc]` survives. `retn 8` proves the slot only. An unnamed int preserves the existing four-byte ABI without claiming semantics. Recovering original source/debug symbols would be required for a stronger answer.
- **Original method spelling:** no symbol/string/RTTI evidence survives. `DispatchConfiguredShortcutHotkey` is descriptive and collision-safe.
- **Record byte type:** all writers create 0/1 and all readers test zero/nonzero, but direct byte copies do not uniquely distinguish bool from unsigned char. `unsigned char isSpellMode` preserves every observed and malformed nonzero case; claiming bool would be stronger than the binary proves.
- **Tail byte +3:** no default/load/save/UI/runtime use exists. Natural two-byte alignment closes size 4; explicit source padding is rejected.
- **UID0003UB blank formal:** its former Config-declaration blocker is superseded by current UID000031, but reconstructing that separate 601-byte body is not required to compile or validate R1-R6 and is not silently altered here. Shared support prose must stop presenting the old blocker as current. A supervisor may assign a separate direct reactivation pass if desired; this artifact makes no lifecycle directive.
- No target behavior, owner, range, storage, or formal-C++ blocker remains unresolved.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Manual coverage files were read only at evidence capture; B003 must not edit them. Exact changes below preserve existing B005/UserPane unions and add only this target's accepted facts.
- `by-memory/-coverage-report.md`: replace the UID0003UA row under UID0001KM with:

        - [UID:0003UA][0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey](by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md) 0x005a3a20-0x005a3ad4 | retained UserPane member | UserPaneDispatchConfiguredShortcutHotkey : reconstructable : 91% : very-strong : Exact 180-byte retained compact-shortcut dispatcher with UserPane owner/emitter, signed-short selector mapping 0/10 to rows 9/19 and other values to selector-minus-one, direct Config m_compactShortcutRecords[20] access, wchar code plus unsigned-char isSpellMode and natural tail alignment, signed-low-byte isalpha behavior, lowercase/uppercase slots 1..52, 0xff alpha fallback, nonalpha return, nonzero spell-command versus zero inventory dispatch, two-slot ABI with unread second home, exhaustive no-entry/no-pointer/no-duplicate evidence, and complete source C++ without nested profile, range/null guards, reserved fields, raw offsets, or compiler scratch.

- `by-class/-coverage-report.md`: replace the current UID000031 row with the B005 full union plus this compact-record correction:

        - [UID:000031][Config](by-class/Config.md) : reconstructable : 90% : very-strong : Base Config singleton attached to Config.cpp with exact constructor child [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md), deleting destructor [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md), raw table helpers, exact helper children [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md), [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md), [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md), and [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md), g_pConfig lifecycle, config-module placement, 100 typed per-player/per-server macro-profile rows at +0x04/stride 0x6894 with player/server text, enabled/name/key/text banks and selected index, ConfigEntryBlock at +0x28db10, exact 0x291918 x86 allocation, inherited option/chat/profile/compact/macro/startup/music/minimap layout, protocol-specific Thrunet/LG/Generic-Bixel/COM/Kornet World launcher union at +0x28d9e0, semantic static-object-transparency/ShowUserName/SelfLook-top-bottom/HearSnore option fields, UID0003UB consumption of the 30-row macro table at +0x28f2ec, UID0003UA direct use of the 20-row compact table at +0x28f29c, and direct unsigned-char m_mapMovementStatusOption at +0x28de75 with default-zero, OptionPane control-8, server/settings writer, and movement-family consumer evidence; complete source-era C++ uses natural alignment, source-shaped typed storage, exact emitted-Config-method fields, a 0x4 CompactShortcutRecord with wchar_t code, unsigned-char isSpellMode, and natural tail alignment, ANSI login endpoint at +0x28de18, endpoint text at +0x291230, MP3 path at +0x29190c, startup port/authentication-token union at +0x2916c4, and exact sizeof/offsetof proof, with no reserved/raw/opaque/numeric/schematic placeholder while private stripped names remain confidence caps.

- `by-file/-coverage-report.md`: replace the current UID0000IE row with the B005 full union plus compact source consistency:

        - [UID:0000IE][Config](by-file/Config.md) : reconstructable : 90% : very-strong : Config module split with exact constructor child [UID:00030S][0x0048e550-0x0048e77a.ConfigConstructor](by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md), exact private helper children [UID:00032D][0x0048e480-0x0048e4a8.ConfigEntryInitialize](by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md), [UID:00032E][0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers](by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md), [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md), and [UID:00032I][0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers](by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md), deleting destructor, raw table helpers with copied local-player/server row matching and macro-profile reset, source-layout decision, B001-016 rejection of [UID:0002VB][0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw](by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md) in favor of RegistryConfig file ownership, generated-output caveats, g_pConfig lifecycle, typed character/server macro rows, ConfigEntryBlock and high-offset string/list construction, protocol-specific launcher union, exact 0x291918 base allocation, inherited semantic option/profile/chat/compact/macro/startup/music/minimap storage, UID0003UB macro-table consumption while RegistryConfig retains default/load/save behavior, UID0003UA direct compact-table use, and direct unsigned-char m_mapMovementStatusOption source storage at +0x28de75; complete Config C++ declares every emitted Config-method dependency, including exact 0x4 CompactShortcutRecord storage with wchar_t code, unsigned-char isSpellMode, and natural tail alignment, without reserved arrays/raw accessors/casts or opaque/numeric/schematic labels, resolves +0x28de18 as login address, +0x291230 as endpoint text, +0x29190c as MP3 path, and +0x2916c4 as startup-port/authentication-token union, and preserves stripped-name/source-split caps.

- `by-memory/-coverage-report.md`: replace the current UID00028Q row with the B005 full union plus exact compact storage:

        - [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md) 0x0067a7c8-0x0067a7cc | global pointer | g_pConfig : reconstructable : 88% : very-strong : Config/RegistryConfig singleton pointer with zero storage, 433 xrefs, constructor/startup/teardown lifecycle, base-typed Config pointer and derived-runtime use, broad UI/profile/network/audio consumers, exact NewUserDialogPane SetLogData success consumer, UID0003UL's ordered direct server-option stores for Whisper/Shout/Advice/Magic/Weather/Fixed movement plus movement-status overwrite/sound/SelfLook styles, UID0003UB's no-null-guard runtime access to the 30-row inherited Config macro table at +0x28f2ec, UID0003UA's direct no-null-guard access to the 20-row 0x4-byte compact table at +0x28f29c using wchar_t code, unsigned-char isSpellMode, and natural tail alignment, and direct unsigned-char Config::m_mapMovementStatusOption access at +0x28de75 across default-zero initialization, OptionPane control 8, server/settings writes, ProcessMovement, both reply handlers, and movement packet senders; complete source-era Config layout now covers typed character/server macro profiles, protocol-specific launcher union, login endpoint, static-object-transparency/ShowUserName/SelfLook-top-bottom/HearSnore option fields, profile/startup/high-tail fields, endpoint text at +0x291230, MP3 path at +0x29190c, startup port/authentication token at +0x2916c4, every emitted Config-method dependency, and exact size 0x291918, while the former RegistryConfig cast, nested profile field, raw accessor, field-only partial class, opaque wrapper, reserved byte, and numeric/schematic declaration remain superseded.

- `by-type/by-struct/-coverage-report.md`: replace UID0001VR with:

        - [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) : reconstructable : 90% : very-strong : Comment-only profile-layout slice of inherited Config runtime storage with resolved fixed strings, legacy shortcuts, exact 20x4 compact records, 30 macro rows, target-option rows, pointer-backed strings, selected-profile text, and block-list vector; complete default/load/save/UI/runtime evidence, exact eight-section writer widths/counts, direct placement in complete 0x291918 Config, and UID0003UA's retained UserPane dispatch prove CompactShortcutRecord as wchar_t code plus unsigned-char isSpellMode with natural tail alignment, while original private spellings remain inferred and no duplicate standalone aggregate is emitted.

- `by-memory/-coverage-report.md`: replace UID00030W with:

        - [UID:00030W][0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults](by-memory/0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults.md) 0x0048ebc0-0x0048eecf | class method | RegistryConfigInitializeUserDataDefaults : reconstructable : 89% : very-strong : Exact RegistryConfig user-data defaulting method called by InitializeDefaults and profile load, preserving localized profile labels 67..76, legacy rows, selected profile, compact code/isSpellMode defaults for 20 rows, 30 macro hotkeys, target-option bytes, 20 string slots, block-list clear, direct inherited Config storage, and complete source C++.

- `by-memory/-coverage-report.md`: replace UID00049J with:

        - [UID:00049J][0x0053ed90-0x0053f07f.NewMacroDialogConstructor](by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md) 0x0053ed90-0x0053f07f | constructor | NewMacroDialogConstructor : reconstructable : 90% : very-strong : Exact newer paged MacroDialog constructor with natural 0x270 layout, direct CompactShortcutRecord code/isSpellMode rows, OK/previous/next controls, inherited SetHoverControl(2), resource/bounds/layer setup, no final Show, complete source C++, and preserved no-direct-xref caveat.

- `by-memory/-coverage-report.md`: insert after UID00049M and in address order:

        - [UID:00049N][0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries](by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md) 0x0053f180-0x0053f203 | method | NewMacroDialogSaveMacroEntries : reconstructable : 89% : very-strong : Exact current-page ten-row save helper copying NewMacroEditControlPane key/mode into direct Config CompactShortcutRecord code/isSpellMode fields with complete source C++ and no MacroHotkeyRecord conflation.
        - [UID:00049O][0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage](by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md) 0x0053f210-0x0053f2b6 | method | NewMacroDialogLoadMacroPage : reconstructable : 89% : very-strong : Exact page-change and ten-row load helper copying direct Config CompactShortcutRecord code/isSpellMode into NewMacroEditControlPane index/key/mode before refresh, with corrected endpoint and complete source C++.

- `by-class/-coverage-report.md`, UID0000FQ row: preserve the entire current row and replace only the exact stale suffix `the target formal remains blank because Config has no binary-layout-correct source declaration for the inherited macro table` with `the complete Config declaration now exposes direct macro and compact tables; UID0003UA emits exact retained compact-shortcut source while UID0003UB's earlier blank-formal artifact remains separate historical debt rather than a current Config blocker`.
- `by-file/-coverage-report.md`, UID0000P1 row: preserve the entire current row and replace only the exact stale suffix `retained UID0000FQ emitter route with blank formal/no generated source body pending a binary-layout-correct Config table declaration` with `retained UID0000FQ emitter route, complete Config table declarations, exact retained UID0003UA compact-shortcut source, and a separately historical UID0003UB blank-formal artifact whose former Config blocker is no longer current`.
- LivingObjectPane class/file manual rows remain accurate because they already describe the exact 0x20c class/file and exclude UserPane-only large-offset functions; no replacement is needed after current prose is corrected.
- UID0001KM, UID0001KN, UID0003UC, ProfileStorage, NewMacroDialog class, NewMacroEditControlPane, MacroDialogs aggregate/file, UID00019T, and UID0001AV manual rows either remain semantically true or do not exist as individual rows. No additional replacement is required beyond the explicit UID00049N/O insertions.
- Tracker content is validator-owned and is not supplied here. Coverage/report lifecycle application is external supervisor/validator-owned state and is neither asserted nor directed by this artifact.

## Follow-Up Actions

- Completed B003 state: C01-C36, R1-R6, sixteen ordinary destination edits, scoped validators, serial lease releases, final waited generated verification, report reconciliation, exact manual coverage handoff retention, and verify-only readbacks are complete. No accepted B003 implementation item remains.
- External supervisor/validator-owned state: exact-artifact validation, coverage application, report execution/count/path/move/archive state, and later generated epochs are external and are neither asserted nor directed by this report.
- The separate UID0003UB body was not silently incorporated; its exact page/formal remained verify-only.

## Confidence

- Recommendation confidence: 93/100.
- Score confidence: high for 91/93 target; medium-high for bounded support score increases.
- Remaining uncertainty: live entry, original method/type/member spelling, and second-argument semantic type. None changes exact target behavior or R1-R6 source legality.

## Validator Results

- Historical report-only phase: no validator ran before exact-artifact Gate 1. The separately authorized callback then used one scoped validator per changed ordinary page and one final waited refresh. Every command below exited 0 with `ok=1`; generated output was deferred on scoped commands and completed on `13328`.

| Command | Timestamp (`-04:00`) | Ordinary destination / role | Result and validator-owned side effects |
| --- | --- | --- | --- |
| `000000013312` | `2026-07-15T17:03:21` | UID0003UA target | exit 0 / ok 1; completion/confidence and autogen registry updated; projected stats updated; generated deferred. |
| `000000013313` | `2026-07-15T17:04:14` | UID00049J R4 | exit 0 / ok 1; autogen registry/projected stats updated; generated deferred. |
| `000000013314` | `2026-07-15T17:04:59` | UID00049N R5 | exit 0 / ok 1; completion/confidence and autogen registry/projected stats updated; generated deferred. |
| `000000013315` | `2026-07-15T17:05:46` | UID00049O R6 | exit 0 / ok 1; completion/confidence and autogen registry/projected stats updated; generated deferred. |
| `000000013316` | `2026-07-15T17:06:56` | UID0001KN caller sync | exit 0 / ok 1; one UID link inserted and projected stats updated; generated deferred. |
| `000000013317` | `2026-07-15T17:07:43` | UID0003UC caller sync | exit 0 / ok 1; projected stats updated; generated deferred. |
| `000000013318` | `2026-07-15T17:08:59` | `by-class/LivingObjectPane.md` | exit 0 / ok 1; 12 pre-existing missing-UID warnings, reference-index removal for historical UID0001VR link, projected stats update; generated deferred. |
| `000000013319` | `2026-07-15T17:09:42` | `by-file/LivingObjectPane.md` | exit 0 / ok 1; 16 pre-existing missing-UID warnings and projected stats update; generated deferred. |
| `000000013320` | `2026-07-15T17:13:22` | UID0001KM shared parent rebase | exit 0 / ok 1; seven pre-existing UID0003JN/3V8/3VC missing-reference warnings, projected stats update; generated deferred. |
| `000000013321` | `2026-07-15T17:14:09` | `by-class/UserPane.md` shared rebase | exit 0 / ok 1; five pre-existing UID0003V8/3VC warnings, UID0003UA reference-index add, projected stats update; generated deferred. |
| `000000013322` | `2026-07-15T17:14:46` | `by-file/UserPane.md` shared rebase | exit 0 / ok 1; 18 pre-existing missing-reference warnings, UID0003UA reference-index add, projected stats update; generated deferred. |
| `000000013323` | `2026-07-15T17:16:04` | `by-class/Config.md` R2 | exit 0 / ok 1; autogen registry hash and UID0003UA reference index updated; projected stats updated; generated deferred. |
| `000000013324` | `2026-07-15T17:16:42` | `by-file/Config.md` | exit 0 / ok 1; UID0003UA reference-index and projected stats updated; generated deferred. |
| `000000013325` | `2026-07-15T17:17:25` | UID00028Q g_pConfig | exit 0 / ok 1; projected stats updated; generated deferred. |
| `000000013326` | `2026-07-15T17:20:01` | UID0001VR profile slice | exit 0 / ok 1; completion/confidence to 90/92, projected stats update, generated stats-row removal/rescore recommendation; generated deferred. |
| `000000013327` | `2026-07-15T17:20:59` | UID00030W R3 | exit 0 / ok 1; completion/confidence to 89/91, autogen registry/projected stats updated; generated deferred. |
| `000000013328` | `2026-07-15T17:21:16` | final waited `by-file/UserPane.md` refresh | exit 0 / ok 1; generated completed; registry rebuild 1, metadata refresh 281, fallback insert 14, missing-child-marker 85, emitter-no-code 160, projected stats update 1. These broad warnings are unrelated to UID0003UA/R1-R6. |

- Exact formal verification after command `13328`: R1-R6 destination equality is 6/6 and generated body counts are 1/1/1/1/1/1. Normalized block hashes are R1 `F1DCCFC320EF7C704738259D0E14FF507782964821E0995EF624F10407DC76C3`, R2 `E8707C848CEA211E38C992357507DF5CAA6E39DCD9B23A52FBB9E15CC566B7A7`, R3 `74245F153569C5255EAF0B32E5E0A64AE955BBDD0F4324F8140871FC3B7A69ED`, R4 `93BB2284981E2C6709EFD940D0818EFE87516B96D5140330C694088CF992A3E9`, R5 `327FAE9F222279D94926DD4774EA6C21F5DC1BED03CAB09F9CED48845F668A1D`, R6 `F1089388257859FF715F95D6E73C82325E5FC56317699FDB0684E4CDE9AEED46`; aggregate SHA256 `3CFC3A973B930547350ABD32F721D448A6CD26BD517C4ADA261D7FA9E4235D00`.
- B003 waited UserPane.cpp snapshot: command/header `13328`, SHA256 `75E0F93227029088FEA2A744EAC44DD46CEBB5B7FFB78EF19D7852EE852B6ECA`, 89,988 bytes, 2,684 lines. Class closure preceded R1; UID0003UA provenance/definition/path counts were 1/1/1; target marker count was 0; 37 qualified UserPane definition names had no duplicate; vftable/RTTI/cookie/EH artifact counts were 0/0/0/0.
- Later read-only external UserPane checkpoint: deferred command/header `13329`, refreshed `2026-07-15T17:31:31-04:00`, SHA256 `304BF934D6F1EF6F1DD20A5D21C1CDFB1DF06EA6B4C3EEE78504BA5C7049279D`, 90,321 bytes, 2,697 lines. R1 still appears exactly once and remains byte-identical; class closure still precedes definitions; UID0003UA provenance/definition/path counts remain 1/1/1; target marker and duplicate qualified-name counts remain 0; all 37 qualified UserPane names remain unique; vftable/RTTI/cookie/EH artifact counts remain 0/0/0/0. Command `13329` was not issued by B003 and does not alter the captured B003 command-13328 proof.
- Post-B005-execution read-only reconciliation at `2026-07-15T17:42:17-04:00`: the executed B005 artifact is SHA256 `CB31E9B73313D6E87D94F83515D2FE1F8402C81D908CD25424F3920ED3C400FF` and carries validator-owned execution history command `13340`; the current B002 report is SHA256 `14DE947BE595D8BE91BA3FE5D61355508A0ED6D0898D5B8D055886F82146B13B`. All eight shared ordinary destinations retained the exact hashes in the terminal table. Direct text readback preserved UID0003UA plus B002 UID0003H5/UID0003UZ/UID0003H4, B005 UID0003UP/UID0003UQ and `m_mapMovementStatusOption`/typed Config union, B003 `wchar_t code`/`unsigned char isSpellMode`/natural-tail contract, and B001-B005 historical union references. Because no ordinary destination changed, this reconciliation issued no lease, scoped validator, or waited refresh; commands `13312`-`13328` remain the exact B003 implementation proof and command `13329` remains the later read-only generated checkpoint.
- Config.cpp: SHA256 `20DF017AEA24BD07ECCBE5F57EAC39D82367ABC7DE8243F4D04080DAB3262C69`, 11,700 bytes, 424 lines, command/header `13328`; one complete Config class, one CompactShortcutRecord declaration, one `unsigned char isSpellMode`, zero stale compact `.key/.mode` expressions, exact R2 once.
- RegistryConfig.cpp: SHA256 `7F374F7E969E768B533CCE4AB5E3C9B65D5F4AD1A670EF973D023E5516DDB6EC`, 62,486 bytes, 1,709 lines, command/header `13328`; exact R3 once.
- ProfileStorage.cpp: SHA256 `259D98D8D631E7AB38D234C3FBDE8DEE1B7B0E3FAAFECAB2C74F072041E5BE53`, 17,413 bytes, 531 lines, command/header `13328`; six accepted `.code` and four accepted `.isSpellMode` expressions, zero stale compact `.key/.mode` expressions.
- MacroDialogs.cpp: SHA256 `57BB134615263D91983B92BCA052C79632DCCE09EC35F0279133FCD7A27E1E9A`, 34,786 bytes, 1,048 lines, command/header `13328`; R4-R6 once each, three `record.code`, three `record.isSpellMode`, and zero stale compact `record.key/record.mode` expressions.
- B003 manually edited no generated or validator-owned state. Validator side effects above are authorized tool output; all generated files were inspected read-only.

## Changed Files

- Report artifact: this same B003 report was updated in place; no manual report move/archive/lifecycle action occurred.
- Modified ordinary by-* files: exactly the sixteen accepted destinations in the terminal table below. No rename, new UID, new child, split, import, or unrelated ordinary edit occurred.
- Modified restricted/manual/generated/tracker/audit/supervisor/validator/lifecycle/IDA files manually by B003: none. Validator-owned side effects are recorded under Validator Results.
- Leases: one ordinary page at a time immediately before edit, then scoped validation and immediate release; final B003 lease count is zero.
- Validators: sixteen scoped ordinary validations plus one authorized final waited refresh; all exit 0 / ok 1.
- Report execution/lifecycle commands: not run or probed.
- Evidence-time destination baselines captured `2026-07-15T16:38:48.9096570-04:00`:

| Path | SHA256 | Bytes | Lines | Accepted callback role |
| --- | --- | ---: | ---: | --- |
| `by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md` | `B9D9CA298926950A666DF8CE28E46A73C7A7AC2BBDF74DD784D298E5E3C8B1C5` | 20755 | 254 | target R1/91/93 |
| `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` | `51FF95F237672E72242755ADD936747AC0085469CD5DA0B57AC71E61AF61C25A` | 124620 | 550 | parent sync |
| `by-class/UserPane.md` | `A62105E89A266FC6143B834880A60F71FD0A428138364651FC46003640C5E7A2` | 72838 | 563 | support sync |
| `by-file/UserPane.md` | `705C2C6F35745B778FA5362376E1F2F80969F948C4BF483A95EBE8B5E005A404` | 86377 | 347 | support sync/final route |
| `by-class/LivingObjectPane.md` | `B32782884853D061C9222C6C2FEF37301386DB99219FB52161670F3B1E4BABEC` | 124666 | 637 | historicalize target ownership |
| `by-file/LivingObjectPane.md` | `9231E598FD12848BFFBB6FBE9E4BF233E902E320A8DE20A5D3E12972FB858657` | 117988 | 422 | historicalize target ownership |
| `by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md` | `2D240DD7596E94FB034A7E2A3DCABEE49E5053CEF5B56545C0506A4D090417C4` | 33244 | 263 | caller sync |
| `by-memory/0x005a4530-0x005a4908.UserPaneUseCommandSlot.md` | `760562CCE9EDAEE9BD291BCBBB1451834DBB2E3A4AC066E48A56443479FB9B6C` | 29965 | 286 | caller sync |
| `by-class/Config.md` | `4F528B7CDFBD3DF6B40C460F0A6AA44138B67A681C043F2851B1B209A3DB4BAA` | 40787 | 489 | R2/prose |
| `by-file/Config.md` | `A59483DCC22B1263D149A08E926988EB7364B3EDE497F133389CF7B017E21FC8` | 36716 | 238 | source support |
| `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` | `D98A1FFCB23DC4E8EEC0FF9DA725934DA84DD3249FCEAC9D8F2BD1BC8E3C8FEB` | 55201 | 205 | global support |
| `by-type/by-struct/RegistryConfigUserProfileBlock.md` | `46F156D00B127EF30CAF556DA0B27474396EB4789E68B26FB0087133F5576B0A` | 43990 | 262 | layout support |
| `by-memory/0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults.md` | `21AD0B0CAD3A6AABFF9B2ED34311EFB4A41C0CCE1BF6F551DEBCA39E29E48880` | 6985 | 100 | R3 |
| `by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md` | `842BE1519C56196AABB6158372F8CFAC282F809A2EB7214216B111AE19194CCB` | 6596 | 93 | R4 |
| `by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md` | `2F46E7E461EEAAEDD3C088B8BDE720769A6F67B6A2D0FD00CCB88CBF328AFFE5` | 3617 | 58 | R5 |
| `by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md` | `265EDD63B2749457CF4AA3D9B0558D6A58A20A40B4CEEE0B4FF5CF80D6A235AD` | 3699 | 64 | R6 |
| `by-memory/0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction.md` | `6B94291906ABC770754DADCACE25CAF1A9ECF923FF122773FA074EFD686DB433` | 16311 | 125 | verify-only |
| `by-memory/0x005a9250-0x005a9307.UserPaneTryDispatchFunctionKeyShortcut.md` | `F2F18BC6A7C20731F66026F689F81E05A79479DCDAD2B7C6570182A89B23FFD7` | 13736 | 136 | verify-only comparator |
| `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md` | `041FC1B88844E2982F728C1040C31CCA1A01B23D8C95EA945399117801E1B16E` | 24100 | 370 | verify-only producer |
| `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md` | `FB2B12DC5E3871AB18C218260E097797C92AC098360174BFD7167BB401859935` | 21630 | 247 | verify-only writer |
| `by-file/ProfileStorage.md` | `49701BA735F28266817DA688EA902F556413D0553668BB87741D5EF2ED2F2525` | 16885 | 149 | verify-only source route |

- Historical collision snapshots: the `16:51` recheck and advanced hashes above were report-only evidence that B005 was still active and were never used as B003 edit baselines. B003 later observed B005's terminal 56/56 checklist, zero proposed claims, and no shared lease, then reread the terminal B005/B002 reports and live pages before every shared edit.
- Exact B003 pre-edit shared baselines were UID0001KM `1B4F824D17CDF265AE5BBE342A5BD7ADF76DA72701A78FF583F0384FEA62B7CF`, UserPane class `20460985D862954B894F8ECA366ABA5993A62747924B186FBBA2567A1A21763C`, UserPane file `F32A8CB1D279276D7A5DAE4432A46A407C9FDE4751A58CA78FB80715B9BD8D38`, Config class `F5C4301513D93D5067F4BB5AB2D5C4E8F1565DBE7DAEDE5C298F220EE18B01C6`, Config file `0149C304BC4F009CC0E9B8742381D0B12AA352D936B56E878778D137E0A4D75F`, g_pConfig `0B5466020E3A0991B944741B7B20C3A0CDE83A1F78FC3E888D274DCCC445E243`, profile slice `46F156D00B127EF30CAF556DA0B27474396EB4789E68B26FB0087133F5576B0A`, and defaults `21AD0B0CAD3A6AABFF9B2ED34311EFB4A41C0CCE1BF6F551DEBCA39E29E48880`.

### Terminal Ordinary Destination Hashes

| Path | B003 pre-edit SHA256 | Post-validation SHA256 | Validator |
| --- | --- | --- | --- |
| `by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md` | `B9D9CA298926950A666DF8CE28E46A73C7A7AC2BBDF74DD784D298E5E3C8B1C5` | `80A964B2A7D68EC5EB9ECB337DBD3E987AFC4D2207BDEB2BC48E45E054396E8C` | `13312` |
| `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` | `1B4F824D17CDF265AE5BBE342A5BD7ADF76DA72701A78FF583F0384FEA62B7CF` | `913963EF854015CFDD672090F9704C24CD0EA07B521C45951350E3538ABD03EA` | `13320` |
| `by-class/UserPane.md` | `20460985D862954B894F8ECA366ABA5993A62747924B186FBBA2567A1A21763C` | `31F6DC7CBEECDBF6791EDFD45726C9BE45543F03BC1259857220F60935271B88` | `13321` |
| `by-file/UserPane.md` | `F32A8CB1D279276D7A5DAE4432A46A407C9FDE4751A58CA78FB80715B9BD8D38` | `0B19A8D0EF7F40B1ABD37540C63BD1482197BE5886E4DC22208C66BF0A0932A3` | `13322`; waited `13328` |
| `by-class/LivingObjectPane.md` | `B32782884853D061C9222C6C2FEF37301386DB99219FB52161670F3B1E4BABEC` | `B26B13FA001B1E1A12EBDE210EC4552C782F6C6D0D3C991E3E0B7A106F581AE8` | `13318` |
| `by-file/LivingObjectPane.md` | `9231E598FD12848BFFBB6FBE9E4BF233E902E320A8DE20A5D3E12972FB858657` | `0BEB33FA4C05678788A1163467B92ADF99D13BCFC82F1C686E88E25C4E3E0CC4` | `13319` |
| `by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md` | `2D240DD7596E94FB034A7E2A3DCABEE49E5053CEF5B56545C0506A4D090417C4` | `5AE04744B4E8177332BDECFC54D56E122D55AB521801F3134F5A67E2F1C3D0AF` | `13316` |
| `by-memory/0x005a4530-0x005a4908.UserPaneUseCommandSlot.md` | `760562CCE9EDAEE9BD291BCBBB1451834DBB2E3A4AC066E48A56443479FB9B6C` | `E8467F22F3F295CAAE6C5764CDF928939EE94451FA1F322CE7F78B81C57293E9` | `13317` |
| `by-class/Config.md` | `F5C4301513D93D5067F4BB5AB2D5C4E8F1565DBE7DAEDE5C298F220EE18B01C6` | `9ECA99799904B0DD1E6D14E0C84DC784B578E2C31555C3AD7472C9B7A304B473` | `13323` |
| `by-file/Config.md` | `0149C304BC4F009CC0E9B8742381D0B12AA352D936B56E878778D137E0A4D75F` | `91984E67C9F7E99F2252203A65C892654531030AF190C7DAB7E2F0497FE3D577` | `13324` |
| `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` | `0B5466020E3A0991B944741B7B20C3A0CDE83A1F78FC3E888D274DCCC445E243` | `1F75F1DD325A8ADCAC209520F9BDFD0B48035C51AF4201B6DED615BD23B85737` | `13325` |
| `by-type/by-struct/RegistryConfigUserProfileBlock.md` | `46F156D00B127EF30CAF556DA0B27474396EB4789E68B26FB0087133F5576B0A` | `5F04BD5CCCCB69A64289A5F9BABF321653B3A841E8EB48EA84EF87BEF459102F` | `13326` |
| `by-memory/0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults.md` | `21AD0B0CAD3A6AABFF9B2ED34311EFB4A41C0CCE1BF6F551DEBCA39E29E48880` | `25EA2A1AF26405426336C559ACF6A5D8C946EA02DBCFCE0EE3E2539B27C87DD9` | `13327` |
| `by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md` | `842BE1519C56196AABB6158372F8CFAC282F809A2EB7214216B111AE19194CCB` | `0CE2B28756C775AEB6A27620137214484AE57D5CC928BD9030B7C565CDC98C65` | `13313` |
| `by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md` | `2F46E7E461EEAAEDD3C088B8BDE720769A6F67B6A2D0FD00CCB88CBF328AFFE5` | `B1A463D637E372A8CA44806DAAD2A2FEDD433786E45812D8D7E0F1AC5014EB4D` | `13314` |
| `by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md` | `265EDD63B2749457CF4AA3D9B0558D6A58A20A40B4CEEE0B4FF5CF80D6A235AD` | `51802ECFD5516F703958ED2F4F13621BB3801607AB0F552725719996759280F9` | `13315` |

- Verify-only readback remained exact: UID0003UB `6B94291906ABC770754DADCACE25CAF1A9ECF923FF122773FA074EFD686DB433`; UID0003UJ `F2F18BC6A7C20731F66026F689F81E05A79479DCDAD2B7C6570182A89B23FFD7`; UID00019T `041FC1B88844E2982F728C1040C31CCA1A01B23D8C95EA945399117801E1B16E`; UID0001AV `FB2B12DC5E3871AB18C218260E097797C92AC098360174BFD7167BB401859935`; ProfileStorage file `49701BA735F28266817DA688EA902F556413D0553668BB87741D5EF2ED2F2525`.
- Post-execution shared-lane recheck: B005 is externally executed at `executed-b-agent-research/B005/0003UP-UserPaneHandleMovementReplyPacket-source-quality.md`, SHA256 `CB31E9B73313D6E87D94F83515D2FE1F8402C81D908CD25424F3920ED3C400FF`, through validator-owned command `13340`; B002 remains at `tools/leaser/Agents/Agent-B002/research/0003H5-UserPaneSendAutoFaceDirectionPacket-source-quality.md`, SHA256 `14DE947BE595D8BE91BA3FE5D61355508A0ED6D0898D5B8D055886F82146B13B`. The terminal facts used by B003 remain 56/56 and 28/28 checked, zero proposed claims, and zero shared leases. Both reports explicitly preserve the B003 post hashes above; no external report was edited by B003.
- Exact post-execution shared hash parity: UID0001KM `913963EF854015CFDD672090F9704C24CD0EA07B521C45951350E3538ABD03EA`, UserPane class `31F6DC7CBEECDBF6791EDFD45726C9BE45543F03BC1259857220F60935271B88`, UserPane file `0B19A8D0EF7F40B1ABD37540C63BD1482197BE5886E4DC22208C66BF0A0932A3`, Config class `9ECA99799904B0DD1E6D14E0C84DC784B578E2C31555C3AD7472C9B7A304B473`, Config file `91984E67C9F7E99F2252203A65C892654531030AF190C7DAB7E2F0497FE3D577`, g_pConfig `1F75F1DD325A8ADCAC209520F9BDFD0B48035C51AF4201B6DED615BD23B85737`, profile slice `5F04BD5CCCCB69A64289A5F9BABF321653B3A841E8EB48EA84EF87BEF459102F`, and defaults `25EA2A1AF26405426336C559ACF6A5D8C946EA02DBCFCE0EE3E2539B27C87DD9`. Every value equals the corresponding B003 post-validation hash, so the final shared-lane pass was read-only and required no new ordinary validation.
- Generated-current rebase: after B003 waited command `13328`, external deferred command `13329` advanced only UserPane.cpp's header/content epoch. The exact current `13329` hash/count/assertions are under Validator Results; Config, RegistryConfig, ProfileStorage, and MacroDialogs remain at B003 command/header `13328` with the recorded hashes.
- Final read-only lease check: `tools/leaser/Agents/current_leases.md` contains zero B003 entries.

## Implementation Tracking Checklist

Research and authorized-callback requirements:

- [x] Supervisor validation required before implementation.
- [x] Wait for B005 UID0003UP accepted callback and all shared Config/UserPane leases to close; reread its terminal artifact and current shared pages before any edit.
- [x] Apply C01-C20 to UID0003UA at report-level detail without compressing bytes, ABI, behavior, liveness, negatives, or history.
- [x] Set UID0003UA 91/93; preserve owner/emitter UID0000FQ, true, blank position, Nested0, exact path/title/range.
- [x] Install target R1 exactly and apply the exact Item Summary.
- [x] Preserve no selector/null guard, signed low-byte classification, full-wchar comparisons, 0xff fallback, and branch order.
- [x] Preserve two ABI homes while leaving the unread second `int` unnamed; do not expose `[ebp+0xb]` compiler scratch.
- [x] Apply C21/C22 and R2 to `by-class/Config.md`, preserving the full B005 union and exact 0x291918 layout.
- [x] Correct Config class/file `CompactShortcutRecord` size typo from 0x84 to 0x4.
- [x] Synchronize `by-file/Config.md` with direct code/isSpellMode storage and target use, scores unchanged.
- [x] Synchronize UID00028Q g_pConfig with direct compact storage, natural tail alignment, and complete Config current state, score unchanged.
- [x] Apply UID0001VR 90/92 prose and preserve its comment-only no-duplicate declaration formal.
- [x] Apply UID00030W 89/91 and R3 exactly.
- [x] Apply UID00049J R4 exactly with score unchanged 90/93.
- [x] Apply UID00049N 89/92 and R5 exactly.
- [x] Apply UID00049O 89/92 and R6 exactly.
- [x] Synchronize UID0001KM target inventory/range/alignment/retained history without changing score/route/formal/Nested.
- [x] Synchronize UserPane class/file target semantics and stale Config/LivingObject history while preserving complete class closure, `[[CHILDREN]]`, concurrent union, scores, and route.
- [x] Historicalize UID0003UA current ownership in LivingObjectPane class/file without losing unrelated 0x20c/base/helper evidence.
- [x] Synchronize UID0001KN and UID0003UC target caller prose to UserPane plus isSpellMode zero/nonzero without changing their formals/scores.
- [x] Reread UID0003UB/UID0003UJ/UID00019T/UID0001AV/ProfileStorage/NewMacroDialog/NewMacroEditControlPane/MacroDialogs/ignored alignment verify-only and preserve unless an exact contradiction is recorded.
- [x] Apply every C01-C36 ledger row with a legal terminal action/state and destination-specific validator/generated proof.
- [x] Preserve all B001/B002/B003/B004/B005 concurrent UserPane/Config facts under Rule 26; never replace shared pages from stale baselines.
- [x] After B005 external execution command 13340, reread the executed B005 artifact, current B002 artifact, all eight shared destinations, current generated headers, and leases; confirm exact hash parity and complete B002/B005/B003 union without an unnecessary ordinary rewrite.
- [x] Run one scoped validator per actually changed ordinary page under one short serial lease; release immediately before the next lease.
- [x] Run final waited by-file/UserPane refresh after all ordinary pages pass.
- [x] Verify generated UserPane.cpp has class closed before definitions, one R1 body, zero UID0003UA Empty Emitter Marker, no duplicate/wrong-range body, and existing unrelated methods once.
- [x] Verify generated Config.cpp has one complete Config declaration, exact 0x4 code/isSpellMode record, no stale `.mode`, no raw padding/reserved/opaque accessor, and no duplicate declaration.
- [x] Verify generated ProfileStorage.cpp retains code/isSpellMode load/migrate/save expressions exactly once per accepted site.
- [x] Verify generated MacroDialogs.cpp uses code/isSpellMode at constructor/save/load sites and has no stale compact `.key/.mode` expressions.
- [x] Verify no handwritten vtable/RTTI/EH/cookie/stack-home/raw-address code is introduced.
- [x] Preserve UID0003UB direct formal verify-only; historicalize only its now-stale Config blocker where shared prose is edited.
- [x] Supply/apply the exact supervisor-owned manual coverage handoff externally; B003 must not edit coverage.
- [x] Update Validator Results with command IDs/timestamps/exits/ok/warnings/side effects and generated header freshness.
- [x] Update Changed Files with exact pre/post hashes, collision rebases, generated readback, and zero restricted edits.
- [x] Confirm every B003 lease released and zero active B003 leases before callback return.
- [x] Keep report validation/execution/count/path/move/archive state external supervisor/validator-owned; run no lifecycle command.

Implementation callback completion:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support detail incorporated at report-level depth.
- [x] C01-C36 updated from proposed to legal terminal verification states with proof.
- [x] R1-R6 read back byte-for-byte from their destination managed blocks.
- [x] All changed ordinary pages scoped-validated and immediately unleased.
- [x] Final waited generated readback completed with exact assertions above.
- [x] Exact manual coverage handoff retained for supervisor ownership.
- [x] Remaining accepted implementation items explicitly listed with exact blocker; expected zero.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000013356","destination_path":"executed-b-agent-research/B003/0003UA-UserPaneDispatchConfiguredShortcutHotkey-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0003UA-UserPaneDispatchConfiguredShortcutHotkey-source-quality.md","timestamp":"2026-07-15T17:56:37-04:00","uid":"0003UA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
