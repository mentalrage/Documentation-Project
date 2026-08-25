** TARGET-REPORT-UID:000247 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 000247 TerminalPaneScalarDeletingDestructor Ownership / Split Research


## Finalized Report / Current Recommendation

- Current implemented state: [UID:000247][0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor](../../../../../by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md) is fully researched MSVC scalar-deleting-destructor ABI support at `92/94`, with `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter, blank position, blank formal C++, and `Nested:0`.
- Source-authored destructor disposition: [UID:0000EG][TerminalPane](../../../../../by-class/TerminalPane.md) now carries the complete class declaration with direct `DialogPane` and `Singleton<TerminalPane>` bases and an inline empty virtual destructor. The direct Singleton base causes unconditional singleton clear; implicit reverse base destruction causes `DialogPane` teardown. Handwritten source does not repeat the global clear, vptr restoration, base-destructor call, delete flags, storage release, adjustor thunks, or guarded-size branch.
- Class and callback correction: the `+0xa4` view is documented as inherited `TimerHandler`, not a data member. The tertiary slot at `0x0062daa4` resolves `0x0058b470` as the three-argument bool-returning `OnTimer` override. UID0001JD now calls inherited `ScheduleTimer` directly and contains no `m_timerHandler`.
- Source placement: [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md) remains the `NexusTK/login/TerminalPane.cpp` source root at `90/92`.
- Confidence: very strong for range, bytes, ABI, wrapper mechanics, three vtable routes, direct bases, Singleton lifetime, layout, source/compiler boundary, and formal destination. Exact original lexical spelling of the private parser-state member and whether the source author wrote the empty destructor explicitly remain bounded inference, not implementation blockers.
- Current B001 phase: the accepted implementation callback is complete. Ten ordinary pages were edited under serial short leases, eleven scoped/final validator commands passed, generated output was verified, and every lease was released. B001 did not edit manual coverage/generated/tracker/audit/supervisor/validator-state/lifecycle/IDA files and did not run report execution, probe, count, move, or archive commands.

## Supporting Research

- Canonical assignment and workflow:
  - `tools/leaser/Agents/Agent-B001/goal.md`
  - `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/SKILL.md`
  - `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
  - `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/references/b-agent-report-template.md`
- Direct historical target support:
  - `tools/leaser/Agents/Agent-A002/notes.md`, checkpoint `A002-goal2-destructor-support-refresh-headselect-forcedinform-terminal-0001FL-0001JA-000247-20260616`, directly covers UID000247. It established exact range, padding, vtable routes, singleton clear, polluted `0x0049d9f0` rejection, and MemoryMan delete routing, but stopped at `86/90` with unresolved source declaration shape. That score cap and owner/emitter route are superseded by the current direct RTTI, EBO, class-source, and modern wrapper-disposition evidence.
- Matching executed B reports opened as support, not substitutes:
  - `executed-b-agent-research/B006/0001JB-TerminalPaneAndSetup-source-quality.md`: direct aggregate support. Valid range, terminal/setup source placement, parser/callback inventory, Socket dependencies, and retained raw bytes are preserved. Its `OnDisconnect`, `m_timerHandler`, and member-helper conclusions are superseded where current vtable/RTTI evidence contradicts them.
  - `executed-b-agent-research/B005/000300-g_pTerminalPane-source-quality.md`: direct singleton-storage support. Zero initialization, nine xrefs, source-facing global name, and file ownership remain valid.
  - `executed-b-agent-research/B005/0001JD-TerminalPaneReconnectLeaveCallback-source-quality.md`: direct callback support. Callback type, range, reconnect/leave behavior, and callees remain valid. Its `m_timerHandler` field interpretation is superseded by inherited TimerHandler facet evidence.
  - `executed-b-agent-research/B009/0001JC-TerminalPaneStreamParser-source-quality.md`: direct parser support. Packet wrapper, parser state, inherited DialogPane slot calls, and source route remain valid.
- Reproducible historical search roots and classifications:
  - `tools/leaser/Agents/Older-Research/**`: searched target UID `000247`, address `0x0058dc60`, exact target name, `TerminalPane`, destructor, Singleton, vtable, and source-family terms. No matching direct or incidental report was found.
  - `tools/leaser/Agents/SpecialReports/**`: searched the same target and source-family terms. No matching direct or incidental report was found.
  - `tools/leaser/Agents/Agent-B*/research/**`: the current B001 goal is the only active dedicated target assignment. No active target report existed before this artifact was created.
  - `executed-b-agent-research/**`: no `TARGET-REPORT-UID:000247`, no dedicated UID000247 report, and no exact target-specific B artifact. B006 UID0001JB and B005/B009 support reports are dependency and source-family evidence, not direct target coverage.
  - `tools/leaser/Agents/Agent-A002/notes.md`: direct historical A-agent target checkpoint, classified as useful evidence-time support rather than a current B-report substitute.
- Explicit no-direct-report conclusion: before this report, no active, older-research, special-report, or central executed B artifact directly covered UID000247 as its target.

## Target

- Target UID: `000247`
- Target path: `by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md`
- Queue basis: current `auto-generated/-ag-research-tracker.md`, by-memory reconstructable not-covered row at `86/90`.
- Current target metadata:
  - `COMPLETION:92`
  - `CONFIDENCE:94`
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:FALSE`
  - blank `EMITTER_UIDS`
  - blank position
  - blank formal C++
  - `Nested:0`
- Current target hash: `C5139B5AB1D906B3D9A47A54A866234E4449FE31CC3A04C624CDF46129F40D11`
- Exact physical range: `[0x0058dc60,0x0058dca5)`, 69 bytes.
- Exact target byte SHA256: `D9F75675A6E2E3AAB12A4E19E941F6AC2EB2032CD024A702343747C05EA1207E`.
- Current callback classification: implementation is complete and independently reviewable; lifecycle state remains external supervisor/validator-owned.

## Current Target State

- UID000247 is `92/94`, ownerless, non-reconstructable, non-emitting, blank-position, blank-formal compiler support with `Nested:0`.
- UID0000EG is `92/94` and emits the complete TerminalPane declaration with direct DialogPane and Singleton bases, inline empty virtual destructor, OnTimer declaration, reconnect declaration, parser declaration, parser-state field, and `[[CHILDREN]]`.
- UID0001JD is `91/94` and emits the accepted source-legal body with one unqualified inherited `ScheduleTimer(0, 0, 0, 0)` and no prose duplicate.
- UID0000OI and UID0001JB are `90/92`; the file root and nonduplicating aggregate preserve the complete TerminalPane/TerminalSetupPane union.
- UID0001JK, UID0001JI, and UID0003DO are `92/94` with their accepted compiler/binary dispositions.
- UID0000SF and UID000300 remain `88/91`; their formal blocks and routes are unchanged, with direct Singleton-base lifetime cause added.
- Verify-only UID00012R, UID000197, DialDialog/PhoneBook boundaries, Pane/TimerHandler support, parser, and ignored rows remain same-or-greater and were not edited.
- Current generated artifact:
  - `auto-generated/NexusTK/login/TerminalPane.cpp`;
  - header command `000000014067`, refreshed `2026-07-16T13:22:45-04:00`;
  - final waited verification command `000000014068` completed at `2026-07-16T13:23:34-04:00`; because the ownerless target command introduced no further generated-source change, the file retained the immediately prior source-affecting command header;
  - SHA256 `3DCC82FAF93E4321D2EB18EA78614F6642C526201EF12117D6106192E353F57C`;
  - 5,010 bytes / 155 lines;
  - one complete TerminalPane class, one inline empty virtual destructor, no out-of-class destructor, zero UID000247, zero UID0001JK, zero UID0001JI, and no scalar-wrapper source;
  - one parser, global definition, and reconnect callback;
  - one exact unqualified `ScheduleTimer(0, 0, 0, 0)`, zero `m_timerHandler`, one `OnTimer`, zero `OnDisconnect`;
  - zero explicit vptr, operator-delete, guarded-size, adjustor, Singleton-clear, or DialogPane-destructor source for this target.
- Historical generated checkpoints `000000014005` / `23043A98...F3C4` and `000000013981` / `AD487425...F0FD` are evidence-time pre-callback states only.
- Current report path, validation, execution, movement, count, and archive state remain external supervisor/validator-owned facts; this artifact asserts only completed B001 callback work and restrictions.

## Executive Recommendation

1. UID000247 was reclassified to ownerless, non-reconstructable, non-emitting compiler ABI support at `92/94`; its exact formal block is blank.
2. UID0000EG is `92/94` with the complete accepted managed class declaration.
3. UID0000OI remains the source root at `90/92`.
4. UID0001JB remains a reconstructable, nonduplicating aggregate map at `90/92`, with direct bases, layout, source/compiler lifetime, OnTimer, and raw-helper disposition synchronized.
5. UID0001JK and UID0001JI are `92/94`, ownerless/non-emitting with blank formal C++ and exact compiler causes.
6. UID0003DO is `92/94`, class-owned/emitted with blank formal C++ because the vtable bytes are compiler-generated.
7. UID0000SF and UID000300 remain `88/91`; direct Singleton-base source-cause language was added without changing formal blocks.
8. UID0001JD is `91/94` with inherited unqualified scheduling.
9. UID00012R and UID000197 remain unchanged at same-or-greater detail.
10. Exact padding and neighbor pages remain unchanged.

## Supervisor Active Recheck

- The supervisor accepted this dedicated UID000247 reanalysis and authorized the bounded implementation callback.
- Split-first result: the target itself is one exact physical compiler wrapper and requires no target split. Source semantics belong in the existing TerminalPane class declaration. No new UID is required for the destructor closure.
- Source-bearing support in exact scope:
  - TerminalPane class declaration: fully specified in a destination-specific managed block.
  - Reconnect callback: fully specified correction in a destination-specific managed block.
  - `0x0058b470` method identity: resolved as `OnTimer`; its complete source body remains inside the existing broad aggregate and is not required to hand-author the UID000247 destructor cause.
  - retained raw `0x0058b0f0`: resolved as real terminal configuration code with no proven receiver or liveness route; it must not be declared as a TerminalPane member solely from locality.
- No source-bearing child required by the UID000247 wrapper remains unidentified, and every accepted destination is implemented.

## Inference Research Guidance Check

- Direct IDA facts are kept separate from documentation facts and source inference.
- Existing names and owner routes were treated as hypotheses:
  - `sub_58DC60` is not retained in source.
  - polluted `boost::exception` at `0x0049d9f0` is rejected.
  - `OnDisconnect` is rejected for tertiary slot `0x0062daa4`.
  - `m_timerHandler` is rejected as a direct TerminalPane field.
  - `PostConfiguredTerminalConnectIfSerial` is retained only as a descriptive raw-helper role, not an accepted class member.
- Inference discipline:
  - vtable slot and base-layout evidence determine method family and receiver adjustment;
  - RTTI base descriptors determine direct source bases;
  - constructor/destructor phase ordering determines Singleton lifetime cause;
  - complete-object size and EBO determine field placement and final size;
  - no ordinary caller plus vtable-only routes and standard flag logic determine compiler-wrapper disposition.
- Wave2/Wave3 language was found in older ordinary pages. It was ignored as authority. Only current by-* docs, current generated output, live IDA MCP, current manual coverage, and matching historical evidence were used.

## Heuristic / Inference Reanalysis And Validation

### Physical body classification

- Fact: `sub_58DC60` takes a complete object in ECX, a single flags dword on the stack, returns the original object pointer, and uses `retn 4`.
- Fact: direct reachability is limited to the primary vtable and two adjustor thunks.
- Fact: the body performs unconditional destruction, then selects normal storage release or a no-free guarded-size branch from flag bits.
- Inference: this is the MSVC scalar-deleting-destructor wrapper for TerminalPane, not a source-declared method.
- Rejected: retaining file ownership because the body is semantically associated with TerminalPane. Semantic association is not source ownership for compiler ABI output.

### Source-authored destructor shape

- Fact: no separate ordinary TerminalPane destructor function is present.
- Fact: the scalar wrapper contains no TerminalPane-specific human cleanup beyond direct-base effects.
- Fact: direct Singleton base destruction accounts for the global clear; implicit `DialogPane` destruction accounts for the base cleanup.
- Strongest source inference: an inline empty virtual destructor in the TerminalPane declaration.
- Weaker plausible alternative: an implicitly declared virtual destructor. It can also lower into an inlined wrapper, but project source precedents commonly declare virtual destructors explicitly, and a complete declaration is safer and more legible for reconstruction.
- Rejected: out-of-line manual global clear. It duplicates the direct Singleton-base effect and would misstate source ownership.
- Rejected: guarded clear based on comparison with the object. No load/compare exists; the clear is unconditional.
- Rejected: explicit `DialogPane` destructor call. Reverse base destruction is implicit in C++.

### Direct inheritance and layout

- Fact: TerminalPane RTTI hierarchy has eight entries: TerminalPane, DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, and `Singleton<TerminalPane>`.
- Fact: the Singleton base descriptor has PMD displacement `+0x26c`, nonvirtual `pdisp=-1`, and no own vtable.
- Fact: DialogPane complete size is `0x26c`.
- Fact: constructor installs views at `+0x00`, `+0xa0`, and `+0xa4`, then initializes a dword at `+0x26c`.
- Inference: direct source bases are exactly `DialogPane` and `Singleton<TerminalPane>`. EventHandler and TimerHandler arrive through DialogPane/Pane.
- Inference: the empty Singleton base overlaps the first derived dword through EBO, and that dword is the accepted parser state.
- Result: one derived int at `+0x26c` produces exact `sizeof(TerminalPane)==0x270`.
- Rejected: direct EventHandler or TimerHandler bases.
- Rejected: explicit TimerHandler data member at `+0xa4`.
- Rejected: separate guard/padding storage for Singleton.

### Singleton publication and clear

- Fact: constructor stage writes the active object or zero at `0x0058afa8/0x0058afaf`.
- Fact: constructor unwind helper writes zero at `0x0058dbe0`.
- Fact: scalar destruction writes zero at `0x0058dc66`.
- Fact: RTTI proves the direct Singleton base.
- Inference: all three are compiler-lowered construction/destruction effects of the direct Singleton base.
- Rejected: handwritten constructor publish, handwritten destructor clear, class-local clear helper, pointer guard, or explicit specialization body in this target.

### Three vtable routes

- Fact: primary wrapper cell `0x0062da10 -> 0x0058dc60`.
- Fact: secondary cell `0x0062da70 -> 0x0058dc01`, which subtracts `0xa0`.
- Fact: tertiary cell `0x0062daa0 -> 0x0058dc0c`, which subtracts `0xa4`.
- Inference: one complete-object wrapper is reused for all inherited views through compiler adjustors.
- Rejected: three source destructor overloads or hand-authored thunks.

### Timer virtual identity

- Fact: `0x0062daa4` is the only non-destructor slot in the tertiary `+0xa4` table.
- Fact: `0x0058b470` ends in `retn 0x0c`, returns true, and receives an adjusted receiver.
- Documentation fact: TimerHandler's accepted pure virtual contract is bool-returning `OnTimer(timerId,arg0,arg1)`.
- Inference: `0x0058b470` is `TerminalPane::OnTimer`, not `OnDisconnect`.
- Rejected: ordinary disconnect helper, standalone callback, or source member attached through a direct TimerHandler field.

### Reconnect callback access

- Fact: UID0001JD's nonzero branch adds `0xa4` to the complete receiver before calling the TimerHandler schedule wrapper.
- Source inference: because TimerHandler is inherited through Pane, source calls inherited `ScheduleTimer` unqualified.
- Rejected: `m_timerHandler.ScheduleTimer`, raw pointer adjustment, explicit cast to a subobject, or a synthetic reconnect helper.

### Retained configured-connect raw helper

- Fact: `[0x0058b0f0,0x0058b12c)` is executable terminal COM/baud and `ATZ` queue logic.
- Fact: the entry is not an IDA function and has no direct call, jump, vtable, pointer, VA, or RVA route in the checked evidence.
- Fact: no ECX/TerminalPane member use proves a class receiver.
- Disposition: retain as file-local raw helper evidence within UID0001JB, with no class declaration and no formal source body in this target callback.
- Rejected: padding, compiler glue, active TerminalPane member, or proof of constructor extraction.

### Score blocker closure

- Range, bytes, hash, ABI, flags, CFG, xrefs, callers, callees, and padding: closed.
- Direct owner and source file: closed at semantic class/file level; physical wrapper intentionally ownerless.
- Source destructor declaration/definition: closed to strongest implementation-ready inference.
- Singleton clear cause and unconditional behavior: closed.
- Base destructor route: closed.
- Three-vtable layout and adjustments: closed.
- Complete size and derived field: closed.
- Generated-output expectation: closed.
- Exact original lexical spelling: bounded confidence cap only; no remaining blocker requires "needs investigation."

## Evidence Standards Used

- Direct IDA MCP:
  - fresh `idb_list`;
  - `server_health`;
  - exact bounded `get_bytes`;
  - `lookup_funcs`;
  - `analyze_function`;
  - `decompile`;
  - `disasm`;
  - xref, caller, callee, RTTI, vtable, and global checks gathered in the retained pass.
- Raw evidence:
  - exact target bytes and SHA256;
  - exact pre/post padding bytes and SHA256;
  - exact thunk and EH helper bytes and SHA256;
  - exact vtable dwords and RTTI base descriptors.
- Documentation evidence:
  - current target, class, file, aggregate, thunk, EH, vtable, singleton, DialogPane, MemoryMan delete, TimerHandler, neighbor, ignored-range, generated-output, tracker, and manual coverage pages.
- Historical evidence:
  - matching A002 checkpoint and executed B006/B005/B009 support reports.
- Negative evidence:
  - no ordinary target caller;
  - no direct target import;
  - no separate ordinary TerminalPane destructor;
  - no singleton compare/guard;
  - no direct TimerHandler field;
  - no active raw-helper route;
  - no direct prior target B report.
- Evidence ladder result: exact binary and type-system evidence is sufficient for near-final behavior and source/compiler boundary. Confidence is capped below 95 because original lexical source and explicit-versus-implicit empty destructor spelling are stripped.

## Evidence Checked

- Research evidence-time MCP health at `2026-07-16T12:43:47-04:00`:
  - then-active NexusTK database session `64c11373`;
  - worker PID `21508`;
  - `server_health: ok`;
  - image base `0x00400000`;
  - auto-analysis, Hex-Rays, and strings cache ready;
  - bounded target `get_bytes` succeeded.
- Exact target:
  - `lookup_funcs(0x0058dc60)` -> `sub_58DC60`, size `0x45`;
  - exact range `[0x0058dc60,0x0058dca5)`;
  - exact bytes listed in IDA MCP Facts;
  - exact SHA256 `D9F75675A6E2E3AAB12A4E19E941F6AC2EB2032CD024A702343747C05EA1207E`.
- Exact support:
  - thunks `[0x0058dc01,0x0058dc17)`;
  - EH clear `[0x0058dbe0,0x0058dbeb)`;
  - constructor `0x0058af50`;
  - timer virtual `0x0058b470`;
  - reconnect callback `0x0058b620`;
  - DialogPane cleanup `0x0049d9f0`;
  - operator delete `0x004f4ac0`;
  - one-byte no-free helper `0x0041b6a0`;
  - TerminalPane vtables and RTTI;
  - singleton storage and all nine refs.
- Current ordinary hashes inspected:
  - target `C5139B5AB1D906B3D9A47A54A866234E4449FE31CC3A04C624CDF46129F40D11`;
  - class `0655596578611CDAFC16345B447413CA6380D81110322FCB8B754B440110E9EA`;
  - file `789CFFDB4FBEE61DF3DF23DD174BB51F93768633F983B6412E9C4850CC42DD7F`;
  - aggregate `65BABF633BE177565A4B2EF2AB60352139CA810806D09E96ADF770F49C180F56`;
  - thunks `7BB087B3F49BBFB00E346109A8E8A3B4A828E7C7FC1CAA0C4E47D1EF6341EE31`;
  - EH helper `6C2C2A78B14A38FE1A53761E1BB2CC5B5B7D838CED2B0A7A350C0F38C7EE7B4D`;
  - vtable `C93DD16CBA66331B931359C02379D7DF1834F042BDB80ECC94542A85427E924D`;
  - global `4F29178766A6501785A496BE066AF537F1B553B362AD63197CEE0773EAB67077`;
  - storage `5F8E8EAFDD47E12BBC104A15605389367CB2B9BFCA92C948D8A31C16C8E2BA98`;
  - reconnect callback `DCDE4554172E9656A6F8F2FD1DED89CBBCD7832DE5E6723D6713AF218483E724`;
  - DialogPane aggregate `3E2CF7496748739205DFE0CC0D5EB37ED6EC85C6AACA8E60BA700BB712E8C5C6`;
  - operator delete `1EB0C5E970BFCF6F4C6664918137EAF094E76BAAF2019D272948631DD660F7F1`;
  - ignored page `2348CAA2ADF662D969DAC2310CAB829A574B6546C2457F29AB3ED62AA6ED1199`.
- Current manual coverage read-only snapshots:
  - by-memory `A22703D70FB433DCEE752EC2F1372A5D2F2DAC3ADB150A474854ECE7FEF3DFD8`, 1,770,720 bytes / 4,248 lines;
  - by-class `AAE19425CFD36CBEF0A4CFDEADBF3799B5C15BB43E2DB3F742485C8F60162916`, 229,144 bytes / 622 lines;
  - by-file `D6DC2D3DAE7FFEFE18C5437687E007B80FE20B140BB7C67077D9D76BB65C707E`, 131,588 bytes / 316 lines;
  - by-global `E1F80490A2DC7FDFD3458E1F8593FF05D2FC8338F56883B762654AF50CC90A35`, 89,268 bytes / 210 lines.
  - The by-memory/by-class/by-file epochs advanced after the callback through unrelated validator-owned coverage changes. Every UID000247-scope row was re-read at this latest epoch and remains stale or absent exactly as classified in the manual handoff below; B001 did not edit coverage.
- Tool-call limitations recorded honestly:
  - one early `get_bytes` attempt used the obsolete `addr/size` shape instead of `regions`;
  - one PowerShell request omitted `-UseBasicParsing`;
  - one helper used PowerShell's reserved `$args` variable and serialized malformed argument arrays.
  - These were client/request-shape failures, not worker loss. Corrected bounded calls against session `64c11373` succeeded immediately.
- Phase boundary:
  - during the initial report-only evidence pass, ordinary edits, leases, validators, and generated refresh were intentionally not performed;
  - during the accepted implementation callback, the ten ordinary edits, short leases, scoped validators, and final waited generated refresh were performed exactly as recorded below;
  - manual coverage edits, IDA mutation, execute_report, lifecycle probes/counts, moves, and archive operations remained unperformed by B001.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C247-001 | Target is exact `[0x0058dc60,0x0058dca5)`, 69 bytes. | Certain | lookup/bytes | UID000247 exact function | incorporate | applied |
| C247-002 | Target bytes hash to `D9F75675...1207E`. | Certain | raw hash | UID000247 evidence | incorporate | applied |
| C247-003 | Pre-padding is five `cc` bytes with hash `992CF514...7329`. | Certain | raw bytes/hash | UID000247; verified ignored | incorporate | applied |
| C247-004 | Post-padding is eleven `cc` bytes with hash `3682C0A6...0943`. | Certain | raw bytes/hash | UID000247; verified ignored | incorporate | applied |
| C247-005 | ABI is ECX complete object plus one flags dword, return original object, `retn 4`. | Certain | disasm/stack | UID000247 | incorporate | applied |
| C247-006 | Target has 26 instructions, five blocks, and low complexity. | Very strong | analyze/disasm | UID000247 | incorporate | applied |
| C247-007 | Target has no ordinary caller. | Certain | caller/xref checks | UID000247 | incorporate | applied |
| C247-008 | Target xrefs are thunks at `0x58dc07/0x58dc12` and primary vtable cell `0x62da10`. | Certain | xrefs | UID000247 | incorporate | applied |
| C247-009 | Singleton clear at `0x58dc66` is unconditional. | Certain | disasm | UID000247; singleton docs | incorporate | applied |
| C247-010 | `0x49d9f0` is DialogPane cleanup, not Boost exception destruction. | Certain | current DialogPane evidence | UID000247 | reject-stale | excluded-with-reason |
| C247-011 | Normal scalar-delete path calls global operator delete only when bit 1 is set and bit 4 is clear. | Certain | CFG/disasm | UID000247 | incorporate | applied |
| C247-012 | Bit-4 branch supplies `this` and size `0x270` to one-byte no-free support. | Certain | disasm/bytes | UID000247 | incorporate | applied |
| C247-013 | Every exit returns the original complete object pointer. | Certain | disasm | UID000247 | incorporate | applied |
| C247-014 | DialDialog predecessor ends at `0x58dc5b`; target is not DialDialog-owned. | Certain | lookup/vtable/padding | verify-only current docs | already-present | already-present |
| C247-015 | PhoneBook formatted-output successor begins at `0x58dcb0`; target does not extend into it. | Certain | lookup/padding | verify-only current docs | already-present | already-present |
| C247-016 | Direct source bases are DialogPane and Singleton<TerminalPane>. | Certain | RTTI BCA/BCD | UID0000EG; UID0001JB; UID0000OI | incorporate | applied |
| C247-017 | EventHandler and TimerHandler are inherited through Pane, not direct TerminalPane bases. | Certain | RTTI/layout | UID0000EG; support prose | incorporate | applied |
| C247-018 | Singleton PMD displacement is `+0x26c`. | Certain | RTTI descriptor | class/global/storage | incorporate | applied |
| C247-019 | Empty Singleton base overlaps the first derived dword through EBO. | Very strong | RTTI plus constructor writes | class/aggregate | incorporate | applied |
| C247-020 | The derived dword is accepted parser state at full-object `+0x26c`. | Very strong | parser/constructor | class/aggregate/parser | already-present | already-present |
| C247-021 | Exact complete object size is `0x270`. | Certain | wrapper size path/layout | class/target/vtable | incorporate | applied |
| C247-022 | Highest-probability source destructor is an inline empty virtual destructor. | High | no ordinary body, direct-base effects, precedent | UID0000EG formal block | incorporate | applied |
| C247-023 | Manual singleton clear is not source-authored TerminalPane destructor logic. | Very strong | Singleton RTTI and phase order | target/class/global/storage | reject-stale | excluded-with-reason |
| C247-024 | Guarding the clear with object comparison is invalid. | Certain | no load/compare | target/class | reject-invalid | excluded-with-reason |
| C247-025 | Explicit source call to DialogPane destructor is invalid; base teardown is implicit. | Certain | C++ lifetime plus body | target/class | reject-invalid | excluded-with-reason |
| C247-026 | UID000247 is ownerless, non-reconstructable, non-emitting, blank position/C++, `Nested:0`. | Very strong | compiler-wrapper classification | UID000247 metadata | incorporate | applied |
| C247-027 | UID000247 score is `92/94`. | Very strong | closed blockers | UID000247 metadata | incorporate | applied |
| C247-028 | UID0001JK exact two thunks are compiler-only and `92/94`. | Certain | bytes/xrefs/vtables | UID0001JK | incorporate | applied |
| C247-029 | UID0001JI exact singleton-clear helper is constructor unwind glue and `92/94`. | Certain | sole EH xref/bytes | UID0001JI | incorporate | applied |
| C247-030 | UID0003DO is `92/94`, class-owned/generated-binary with blank formal C++. | Very strong | full vtable/RTTI map | UID0003DO | incorporate | applied |
| C247-031 | Primary/secondary/tertiary slot counts are 23/11/2. | Certain | raw vtable boundary | UID0003DO; class | incorporate | applied |
| C247-032 | UID0000EG is `92/94` with the exact complete class block. | Very strong | inheritance/layout/method closure | UID0000EG | incorporate | applied |
| C247-033 | UID0000OI is `90/92`; source path stays `NexusTK/login/`. | Very strong | file/source order | UID0000OI | incorporate | applied |
| C247-034 | UID0001JB is `90/92`, reconstructable/owned, and blank as a nonduplicating map. | Very strong | multi-method aggregate | UID0001JB | incorporate | applied |
| C247-035 | `0x0058b470` is `TerminalPane::OnTimer`, not `OnDisconnect`. | Very strong | tertiary slot/ABI/contract | class/file/aggregate/vtable | reject-stale | excluded-with-reason |
| C247-036 | OnTimer source signature is bool with timerId, arg0, arg1. | Very strong | TimerHandler contract/retn 0x0c | class/support | incorporate | applied |
| C247-037 | `+0xa4` is inherited TimerHandler view, not `m_timerHandler`. | Certain | RTTI/vtable/layout | class/UID0001JD/file/aggregate | reject-stale | excluded-with-reason |
| C247-038 | UID0001JD calls inherited ScheduleTimer directly. | Very strong | adjusted-call lowering | UID0001JD formal block | incorporate | applied |
| C247-039 | UID0001JD is `91/94`; owner/emitter remain UID0000OI. | High | behavior closed, name inferred | UID0001JD metadata | incorporate | applied |
| C247-040 | UID0001JD body-only prose code fence is removed; formal managed block is authoritative. | Certain | binding rule | UID0001JD prose | incorporate | applied |
| C247-041 | `0x0058b0f0` is real retained terminal config code, not padding or compiler glue. | Certain | raw bytes/callees | UID0001JB/file/class history | already-present | already-present |
| C247-042 | `0x0058b0f0` is not proven as a TerminalPane member or active helper. | Very strong | no receiver/xrefs | class/aggregate | reject-stale | excluded-with-reason |
| C247-043 | UID0000SF global definition remains accepted at `88/91`. | Very strong | current storage/global output | UID0000SF | already-present | already-present |
| C247-044 | UID000300 covered-by storage remains accepted at `88/91`. | Very strong | current bytes/xrefs | UID000300 | already-present | already-present |
| C247-045 | Global/storage prose attributes publish/clear to Singleton base lifetime. | Very strong | RTTI and phase order | UID0000SF; UID000300 | incorporate | applied |
| C247-046 | UID00012R supplies exact DialogPane cleanup proof; no edit or score change required. | Certain | current doc | verify-only | already-present | already-present |
| C247-047 | UID000197 supplies exact MemoryMan-backed operator delete; no edit or score change required. | Certain | current doc | verify-only | already-present | already-present |
| C247-048 | Existing ignored rows cover thunks and both target-adjacent padding spans. | Certain | current ignored page | verify-only | already-present | already-present |
| C247-049 | Current generated TerminalPane.cpp is hash `3DCC82FA...F57C`; commands 14005/13981 are historical checkpoints. | Certain | read-only generated file | report current state | incorporate | applied |
| C247-050 | Historical pre-callback output had a UID000247 Empty Emitter Marker and lacked the complete class/destructor/OnTimer declaration. | Certain | token counts | historical generated state | historicalize | applied |
| C247-051 | Callback removed UID000247 output entirely and emitted one complete class declaration. | Very strong | metadata/generator policy | generated verification | incorporate | applied |
| C247-052 | Callback preserved parser/global/callback bodies once each and corrected inherited ScheduleTimer qualification. | Very strong | current generated union | generated verification | incorporate | applied |
| C247-053 | No direct target-specific prior B report exists. | Certain | five-root search | Supporting Research | incorporate | applied |
| C247-054 | A002 `86/90` owner/emitter and unresolved-name conclusion is historical. | Certain | A002 checkpoint/current evidence | target history | historicalize | applied |
| C247-055 | B006 `OnDisconnect`, member helper, and B005 `m_timerHandler` are superseded, while behavioral evidence is preserved. | Very strong | current RTTI/vtable | support history | historicalize | applied |
| C247-056 | Manual coverage rows below require supervisor-owned synchronization after implementation verification. | Certain | current manual row audit | coverage handoff | incorporate | applied |

### Callback Verification Notes

Rows `001` through `056` map directly to ledger claims `C247-001` through `C247-056`.

| Row | Destination proof |
| --- | --- |
| 001 | UID000247 title/range and exact-function prose retain `[0x0058dc60,0x0058dca5)`, 69 bytes. |
| 002 | UID000247 records full SHA256 `D9F75675A6E2E3AAB12A4E19E941F6AC2EB2032CD024A702343747C05EA1207E`. |
| 003 | UID000247 records the five-byte pre-padding hash; current `-ignored.md` row remains present. |
| 004 | UID000247 records the eleven-byte post-padding hash; current `-ignored.md` row remains present. |
| 005 | UID000247 Behavior records ECX, one flags dword, return-this, and `retn 4`. |
| 006 | UID000247 Behavior records 26 instructions and five blocks. |
| 007 | UID000247 records no ordinary caller. |
| 008 | UID000247 records both thunk xrefs and primary vtable cell. |
| 009 | UID000247, UID0000SF, and UID000300 record unconditional clear and direct-base cause. |
| 010 | UID000247 rejects the polluted Boost label; UID00012R remains same-or-greater. |
| 011 | UID000247 records exact bit-1/bit-4 normal-delete condition. |
| 012 | UID000247 records `this`, `0x270`, and the one-byte no-free route. |
| 013 | UID000247 records original-this return on every exit. |
| 014 | DialDialog and ignored pages preserve exact predecessor/padding boundary. |
| 015 | PhoneBook helper and ignored pages preserve exact successor/padding boundary. |
| 016 | UID0000EG formal block, UID0001JB, and UID0000OI record both direct bases. |
| 017 | UID0000EG, UID0001JB, UID0000OI, and UID0003DO record inherited EventHandler/TimerHandler facets. |
| 018 | UID0000EG, UID0000SF, and UID000300 record Singleton PMD `+0x26c`. |
| 019 | UID0000EG and UID0001JB record EBO overlap. |
| 020 | Existing UID0001JC parser evidence and current class/aggregate prose retain parser state at full-object `+0x26c`. |
| 021 | UID000247, UID0000EG, UID0001JB, and UID0003DO record exact size `0x270`. |
| 022 | UID0000EG formal block contains one inline empty virtual destructor. |
| 023 | Target/class/global/storage docs reject handwritten clear and attribute it to Singleton lifetime. |
| 024 | Target/class/global/storage docs reject guarded clear because no load/compare exists. |
| 025 | Target/class docs state DialogPane teardown is implicit reverse base destruction. |
| 026 | UID000247 header is NONE/FALSE/blank emitter/position/formal and `Nested:0`. |
| 027 | UID000247 header is `92/94`; command 14043 and final 14068 returned ok1. |
| 028 | UID0001JK is `92/94`, NONE/FALSE/blank, with exact bytes/hash and compiler cause. |
| 029 | UID0001JI is `92/94`, NONE/FALSE/blank, with exact bytes/hash and EH cause. |
| 030 | UID0003DO is `92/94`, owner/emitter UID0000EG, true, blank formal, `Nested:8`. |
| 031 | UID0003DO and UID0000EG record exact 23/11/2 slot counts. |
| 032 | UID0000EG is `92/94` and its managed block exactly matches Destination 2. |
| 033 | UID0000OI is `90/92`; `NexusTK/login/` remains unchanged. |
| 034 | UID0001JB is `90/92`, true, owner/emitter UID0000OI, blank aggregate formal. |
| 035 | Current class/file/aggregate/vtable prose uses OnTimer; OnDisconnect survives only in explicit historical/rejected text. |
| 036 | UID0000EG formal declaration uses `bool OnTimer(int timerId, int arg0, int arg1)`. |
| 037 | Current class/callback/file/aggregate prose rejects `m_timerHandler`; generated output contains zero token occurrences. |
| 038 | UID0001JD formal body contains one unqualified inherited schedule call. |
| 039 | UID0001JD is `91/94`, owner/emitter UID0000OI. |
| 040 | UID0001JD contains zero `cpp` prose fences; only the managed formal block remains. |
| 041 | UID0001JB/file/class history retains raw helper behavior as real code. |
| 042 | UID0000EG, UID0001JB, and UID0000OI reject member/active-helper status without receiver/route evidence. |
| 043 | UID0000SF remains `88/91` with unchanged global formal definition. |
| 044 | UID000300 remains `88/91` with unchanged covered-by formal block. |
| 045 | UID0000SF and UID000300 now state direct Singleton-base publication/clear cause. |
| 046 | UID00012R readback proves ordinary DialogPane cleanup and polluted-label rejection; no edit made. |
| 047 | UID000197 readback proves MemoryMan-backed global operator delete; no edit made. |
| 048 | `-ignored.md` readback contains UID0001JK and both exact padding spans; no edit made. |
| 049 | Current generated hash/header/size/lines and final waited command are recorded below. |
| 050 | Pre-callback command 14005 state is retained explicitly as historical evidence. |
| 051 | Generated readback contains one complete class and zero UID000247 output/marker. |
| 052 | Generated readback contains one parser/global/callback and one exact schedule call. |
| 053 | Supporting Research preserves the five-root no-direct-report search. |
| 054 | UID000247 Changes and report history label A002 owner/score blockers superseded. |
| 055 | Current support docs preserve behavior while historicalizing OnDisconnect/member-helper/m_timerHandler assumptions. |
| 056 | Exact current supervisor-owned manual row text is preserved below; B001 edited no coverage file. |

## Positive Evidence Summary

- Exact target range, bytes, hash, stack cleanup, flags, return value, CFG, and boundaries are directly verified.
- Primary and adjusted vtable routes prove TerminalPane semantic class context and compiler thunk reuse.
- RTTI proves the exact direct base list and Singleton displacement.
- Constructor, EH, and destructor phase writes all align with one direct Singleton base lifetime.
- Exact DialogPane size plus EBO plus one derived int produces the wrapper's `0x270` complete-object size.
- No distinct ordinary destructor body and no derived human cleanup support an inline empty source destructor.
- Current project precedents for ParcelIconPane, HourPane, ScreenDimmer-family panes, and other Singleton-derived panes separate class/ordinary source from ownerless scalar wrappers.
- TimerHandler contract plus tertiary slot fixes `OnTimer` identity and eliminates the fictitious timer member.
- Historical pre-callback generated output demonstrated the blank class/target markers and member-qualified reconnect schedule call. Current generated output proves those defects are resolved.

## IDA MCP Facts

- Research evidence-time database:
  - session `64c11373`;
  - worker PID `21508`;
  - `NexusTK.exe.i64`;
  - health `ok`;
  - analysis/Hex-Rays/strings ready.
- Target exact bytes:
  - `55 8b ec 56 8b f1 c7 05 f8 bd 69 00 00 00 00 00 e8 7b fd f0 ff 8b 45 08 a8 01 74 22 a8 04 75 10 56 e8 3a 6e f6 ff 83 c4 04 8b c6 5e 5d c2 04 00 68 70 02 00 00 56 e8 05 da e8 ff 83 c4 08 8b c6 5e 5d c2 04 00`
- Target:
  - start `0x0058dc60`;
  - end `0x0058dca5`;
  - size `0x45`;
  - 26 instructions;
  - five basic blocks;
  - no strings or imports;
  - callees `0x0049d9f0`, `0x004f4ac0`, `0x0041b6a0`.
- Target control flow:
  - store zero to `0x0069bdf8`;
  - call DialogPane cleanup;
  - test flags bit 1;
  - if deletion requested, test bit 4;
  - normal path calls operator delete with `this`;
  - bit-4 path passes `this` and `0x270` to the one-byte no-free helper;
  - return original `this`, `retn 4`.
- Thunks:
  - `[0x0058dc01,0x0058dc0c)`: subtract `0xa0`, jump target;
  - `[0x0058dc0c,0x0058dc17)`: subtract `0xa4`, jump target;
  - exact combined bytes `81 e9 a0 00 00 00 e9 54 00 00 00 81 e9 a4 00 00 00 e9 49 00 00 00`;
  - SHA256 `131DEB66D370555FFCCE4D1EE7567637B00DE609168CD02C5908B7113DC47996`.
- EH clear:
  - `[0x0058dbe0,0x0058dbeb)`;
  - bytes `c7 05 f8 bd 69 00 00 00 00 00 c3`;
  - SHA256 `5EFB10D571E71458BBA8CCF01626AB201F2CCD5A84B2D8A59AD4770962304757`;
  - sole code reference from constructor unwind metadata.
- Padding:
  - `[0x0058dc5b,0x0058dc60)` five `cc`, SHA256 `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329`;
  - `[0x0058dca5,0x0058dcb0)` eleven `cc`, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`.
- Constructor:
  - `0x0058af50`, size `0x19e`;
  - callers `0x004f5f9b`, `0x004f647a`, `0x004f7cbb`, `0x004f924f`;
  - installs vtables at complete offsets 0, `+0xa0`, `+0xa4`;
  - Singleton base address at `+0x26c`;
  - parser state dword initialized at `+0x26c`.
- RTTI:
  - complete hierarchy count eight;
  - direct source bases DialogPane and `Singleton<TerminalPane>`;
  - Singleton base descriptor PMD `mdisp=0x26c`, `pdisp=-1`, `vdisp=0`.
- Vtables:
  - primary base `0x0062da10`, 23 slots;
  - secondary base `0x0062da70`, 11 slots;
  - tertiary base `0x0062daa0`, two slots;
  - tertiary second slot `0x0062daa4 -> 0x0058b470`;
  - successor TerminalSetupPane locator/table begins at `0x0062daa8/0x0062daac`.
- `0x0058b470`:
  - size `0x170`;
  - 127 listed instructions including EH funclets;
  - no ordinary caller;
  - sole vtable xref `0x0062daa4`;
  - adjusted receiver subtracts `0xa4`;
  - three stack callback arguments, `retn 0x0c`;
  - returns true;
  - source role `OnTimer`.
- Singleton:
  - exactly nine known refs;
  - constructor publish/fallback at `0x0058afa8/0x0058afaf`;
  - consumers at `0x0058c15d`, `0x0058c316`, `0x0058c97d`, `0x0058d4ef`, `0x0058d907`;
  - EH clear `0x0058dbe0`;
  - scalar clear `0x0058dc66`.
- `0x0049d9f0`:
  - current polluted label is not source authority;
  - body restores DialogPane views, decrements active count, releases controls, destroys tile context, and tears down Pane.
- `0x004f4ac0`:
  - current exact source is global operator delete through `GetMemoryMan()->FreeBufferMemory`;
  - target calls it only on normal scalar delete.
- `0x0041b6a0`:
  - one byte `c3`;
  - SHA256 `AE3F4619B0413D70D3004B9131C3752153074E45725BE13B9A148978895E359E`;
  - compiler/runtime no-free support, not a source delete helper.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x0058dbe0,0x0058dbeb)` | UID0001JI / `ClearTerminalPaneSingletonEH.md` | constructor unwind Singleton clear | False | none | current `92/94` | implemented/validated compiler-only blank |
| `[0x0058dc01,0x0058dc17)` | UID0001JK / `TerminalPaneAdjustorThunks.md` | secondary/tertiary destructor adjustors | False | none | current `92/94` | implemented/validated compiler-only blank |
| `[0x0058dc20,0x0058dc5b)` | UID0001JG aggregate member | DialDialog scalar wrapper | unchanged | PhoneBookDialog file | unchanged | predecessor, excluded |
| `[0x0058dc5b,0x0058dc60)` | UID0000VN row | five-byte alignment | False | none | 100 | already ignored |
| `[0x0058dc60,0x0058dca5)` | UID000247 target | TerminalPane scalar deleting wrapper | False | none | current `92/94` | implemented/validated corrected boundary, owner, and C++ disposition |
| `[0x0058dca5,0x0058dcb0)` | UID0000VN row | eleven-byte alignment | False | none | 100 | already ignored |
| `[0x0058dcb0,0x0058dcd3)` | UID0001JL | CRT wide formatted-output wrapper | unchanged | existing support | unchanged | successor, excluded |
| TerminalPane class | UID0000EG / `by-class/TerminalPane.md` | complete source declaration and inline empty destructor | True | UID0000OI | current `92/94` | exact formal block implemented/validated |
| TerminalPane source | UID0000OI / `by-file/TerminalPane.md` | `NexusTK/login/TerminalPane.cpp` root | file root | FILE | current `90/92` | retained and synchronized |
| terminal/setup aggregate | UID0001JB | source map, nonduplicating aggregate | True | UID0000OI | current `90/92` | implemented/validated blank formal |
| reconnect callback | UID0001JD | source member callback | True | UID0000OI | current `91/94` | exact formal correction implemented/validated |
| vtable data | UID0003DO | three compiler-generated table views | True | UID0000EG | current `92/94` | implemented/validated blank formal |
| singleton global | UID0000SF | one source definition | True | UID0000OI | retain `88/91` | current formal retained |
| singleton storage | UID000300 | exact physical storage proof | True | UID0000SF | retain `88/91` | current covered-by retained |
| DialogPane cleanup | UID00012R | inherited ordinary cleanup | True | UID00003T | retain `90/93` | verify-only |
| operator delete | UID000197 | MemoryMan-backed global delete | True | UID0000L7 | retain `89/91` | verify-only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0058dc60` | code refs `0x0058dc07`, `0x0058dc12` | adjusted inherited views |
| `0x0058dc60` | data ref `0x0062da10` | primary deleting-destructor slot |
| `0x0058dc60` | ordinary callers `0` | vtable/compiler-only reachability |
| `0x0058dc01` | data ref `0x0062da70` | secondary view destructor slot |
| `0x0058dc0c` | data ref `0x0062daa0` | tertiary view destructor slot |
| `0x0058dbe0` | code ref `0x00609241` | constructor unwind metadata |
| `0x0069bdf8` | nine refs | constructor, consumers, EH, scalar destruction |
| `0x0049d9f0` | target call `0x0058dc70` | inherited DialogPane cleanup |
| `0x004f4ac0` | target call `0x0058dc85` | normal scalar storage release |
| `0x0041b6a0` | target call `0x0058dc9a` | bit-4 no-free guarded-size branch |
| `0x0058b470` | data ref `0x0062daa4` | TimerHandler OnTimer slot |
| `0x0058b470` | ordinary callers `0` | virtual callback dispatch only |
| `0x0058b620` | data ref `0x0058b56d` | typed reconnect/leave callback target |
| `0x0058b620` | ordinary callers `0` | callback-object dispatch only |
| `0x0058af50` | four code callers | startup/menu construction paths |

## Documentation Evidence And IDA Status

- UID000247:
  - exact direct evidence is retained;
  - owner/reconstructable state, score, source-clear attribution, no-code proof, and body-only C++ removal are applied and validated.
- UID0000EG:
  - TerminalPane purpose, parser, callback, vtable, singleton, and file route are preserved;
  - complete formal class, direct bases, OnTimer, inherited TimerHandler, inline destructor, and raw-helper no-member disposition are applied and validated.
- UID0000OI:
  - `NexusTK/login/TerminalPane.cpp` remains correct;
  - method inventory and source/compiler lifetime wording are synchronized at `90/92`.
- UID0001JB:
  - aggregate range, child-first policy, and complete current union remain valid;
  - OnTimer identity, direct Singleton inheritance, EBO/size, raw-helper no-member status, and source destructor cause are synchronized at `90/92`.
- UID0001JK and UID0001JI:
  - compiler-only classifications remain correct;
  - scores, summaries, exact bytes/hashes, and source causes are applied at `92/94`.
- UID0003DO:
  - exact range/table heads remain correct;
  - complete slot counts, direct-base hierarchy, OnTimer slot identity, and class-regeneration cause are applied at `92/94`.
- UID0000SF and UID000300:
  - source definition, storage, xrefs, scores, routes, and formal blocks remain unchanged;
  - direct Singleton-base source lifetime cause is added.
- UID0001JD:
  - exact behavior and callback type remain correct;
  - formal body now uses inherited unqualified scheduling and contains no duplicate prose C++.
- UID00012R:
  - exact ordinary DialogPane cleanup and polluted-name rejection already present at same-or-greater detail.
- UID000197:
  - exact MemoryMan-backed global operator delete already present at same-or-greater detail.
- Current generated source:
  - source-affecting header command `000000014067`, final waited verification command `000000014068`;
  - hash `3DCC82FA...F57C`, 5,010 bytes / 155 lines;
  - commands `000000014005` and `000000013981` are historicalized pre-callback epochs;
  - current output is a read-only checkpoint, not source authority;
  - it proves the class/target and callback defects are resolved with accepted uniqueness/absence counts.
- Current manual coverage:
  - rows are stale for target, class, file, aggregate, EH, thunks, callback, and global;
  - exact vtable and singleton-storage children are absent from by-memory manual coverage;
  - operator-delete row is stale at 82 versus current 89.
  - the current by-memory/class/file/global union was re-read after callback validation; all exact rows in this report's scope remain stale or absent exactly as represented by the unchanged handoff text.

## Ranked Ownership Analysis

### 1. Ownerless compiler ABI support for UID000247

- Evidence for:
  - vtable/thunk-only reachability;
  - standard flags and return-this ABI;
  - no source-only derived action;
  - direct base effects explain all destruction;
  - modern accepted project precedent.
- Evidence against:
  - semantic association with TerminalPane.
- Decision:
  - semantic association is recorded in prose, but no canonical owner or emitter belongs on the physical wrapper.

### 2. TerminalPane class as source destructor destination

- Evidence for:
  - RTTI identity and exact direct bases;
  - virtual destructor requirement;
  - no distinct ordinary body;
  - class declaration regenerates wrapper, thunks, and vtables;
  - source file already routes all TerminalPane members.
- Evidence against:
  - explicit versus implicit empty destructor spelling is not symbol-proven.
- Decision:
  - accepted strongest source destination. Use explicit inline empty virtual destructor and document the lexical confidence cap.

### 3. Separate destructor child or file-local helper

- Evidence for:
  - an out-of-line empty destructor could also be plausible in human source.
- Evidence against:
  - no ordinary function body or xref exists;
  - creating a source child would invent an address-backed method that is not present;
  - manual global clear would duplicate Singleton.
- Decision:
  - reject.

### 4. TerminalPane file as physical wrapper owner

- Evidence for:
  - source module contains the class.
- Evidence against:
  - compiler wrapper is not handwritten source and should disappear from generated output.
- Decision:
  - reject owner/emitter on UID000247; retain file only as source context.

### Proposed new file/grouping, if applicable

- Not applicable. Existing `NexusTK/login/TerminalPane.cpp` is the strongest and current source route.
- No standalone destructor source file, wrapper file, or ABI-helper file should be created.

## Source Placement

- Source class declaration and inline empty destructor: [UID:0000EG][TerminalPane](../../../../../by-class/TerminalPane.md), emitted through [UID:0000OI][TerminalPane](../../../../../by-file/TerminalPane.md).
- Source file: `NexusTK/login/TerminalPane.cpp`.
- Singleton definition: preserve [UID:0000SF][g_pTerminalPane](../../../../../by-global/g_pTerminalPane.md) in the same file.
- Reconnect callback: preserve exact child UID0001JD in the same file with inherited schedule call.
- Parser: preserve exact child UID0001JC in the same file.
- Physical wrapper, thunks, EH clear, and vtable bytes: compiler-generated from the class/direct-base declaration and source lifetimes.
- Rejected placements:
  - `PhoneBookDialog.cpp`: physical adjacency only; vtable/singleton identity rejects it.
  - `DialogPane.cpp`: owns base cleanup, not TerminalPane derived identity.
  - `TimerMgr.cpp`: owns TimerHandler infrastructure, not TerminalPane source.
  - `MemoryMan.cpp`: owns global delete dependency only.
  - standalone `TerminalPaneDestructor.cpp`: no source or linker evidence.

## Range / Split / Padding / Reclassification Analysis

- Target range requires no split.
- Reclassification:
  - current reconstructable/file-owned wrapper -> ownerless non-reconstructable compiler support.
- Exact predecessor:
  - DialDialog scalar wrapper ends at `0x0058dc5b`.
- Exact pre-padding:
  - `[0x0058dc5b,0x0058dc60)`, five `cc`, already recorded.
- Exact target:
  - `[0x0058dc60,0x0058dca5)`.
- Exact post-padding:
  - `[0x0058dca5,0x0058dcb0)`, eleven `cc`, already recorded.
- Exact successor:
  - PhoneBook formatted-output helper starts at `0x0058dcb0`.
- Associated compiler children:
  - UID0001JK thunks remain exact separate page;
  - UID0001JI EH clear remains exact separate page.
- Parent/container impact:
  - UID0001JB remains a source map, not a parent that emits the wrapper.
  - UID0000EG becomes the source declaration surface.
- No ignored-range edit is proposed because all three relevant ignored spans are already present.

## Negative Evidence Summary

- No ordinary target caller.
- No direct target import.
- No target string or feature literal.
- No separate ordinary TerminalPane destructor.
- No singleton load or object comparison before the clear.
- No source need for explicit base-destructor call.
- No direct TimerHandler field in RTTI or layout.
- No source justification for hand-authored `this -= 0xa0/0xa4`.
- No source justification for delete flags or `0x270` guarded branch.
- No direct code/data/pointer/vtable route to raw `0x0058b0f0`.
- No TerminalPane receiver use in the raw helper.
- No evidence `0x0058b470` is an ordinary disconnect method; its table and ABI are TimerHandler callback evidence.
- No evidence PhoneBookDialog, DialDialog, DialogPane, TimerMgr, MemoryMan, or a new file owns the target wrapper.
- No direct target-specific historical B report.
- No current evidence requires changing DialogPane, operator delete, neighbor pages, ignored padding, TimerHandler, Pane, or generated files manually.

## IDA Rename / Type / Comment Recommendations

- No IDA database mutation is requested or permitted.
- Documentation/source-facing recommendations:
  - target semantic comment: TerminalPane scalar deleting destructor ABI wrapper;
  - class direct bases: DialogPane and `Singleton<TerminalPane>`;
  - derived field: descriptive `m_terminalParserState`;
  - tertiary virtual: `OnTimer`;
  - reconnect callback: `OnReconnectOrLeave`;
  - inherited schedule call: `ScheduleTimer`;
  - global: retain descriptive `g_pTerminalPane`.
- Intentionally rejected names:
  - raw `sub_58DC60`;
  - polluted Boost destructor label at `0x0049d9f0`;
  - `OnDisconnect` for `0x0058b470`;
  - `m_timerHandler`;
  - class member `PostConfiguredTerminalConnectIfSerial` without a receiver route.
- Exact lexical caveats:
  - `m_terminalParserState`, `OnReconnectOrLeave`, and `g_pTerminalPane` remain high-probability descriptive project names rather than PDB-proven spellings.
  - Those caveats cap confidence but do not block source correctness.

## First-Draft C++ Recommendation

- Eligible formal destinations: UID000247 target blank block, UID0000EG complete class declaration, and UID0001JD callback correction.
- No other draft/example/sample C++ is proposed.
- Third-party import: not applicable.

### Destination 1 - UID000247 target

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact no-code proof:
  - physical wrapper is reached only through vtable/adjustor paths;
  - it implements compiler flags, return-this ABI, vptr/base lowering, conditional release, and guarded-size support;
  - all semantic source behavior is explained by the class declaration and direct bases;
  - hand-authoring it would duplicate compiler output and expose non-source ABI details.

### Destination 2 - `by-class/TerminalPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SocketPacket;
class TerminalPane;

extern TerminalPane *g_pTerminalPane;

class TerminalPane : public DialogPane,
                     public Singleton<TerminalPane>
{
public:
    TerminalPane();

    virtual ~TerminalPane()
    {
    }

    virtual void OnClose();
    virtual char ParseTerminalStream(SocketPacket *packet);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

    void OnReconnectOrLeave(unsigned long decision);

private:
    int m_terminalParserState;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior preservation:
  - direct Singleton construction/destruction regenerates publish/clear;
  - reverse base destruction regenerates DialogPane teardown;
  - virtual destructor regenerates primary wrapper, adjusted entries, and vtable slots;
  - empty-base overlap plus one int preserves exact size `0x270`;
  - inherited TimerHandler contract regenerates tertiary `OnTimer` slot.
- Source-era plausibility:
  - explicit virtual destructor declarations and direct Singleton mixin bases are established project conventions;
  - inline empty body is the narrowest source cause consistent with no ordinary destructor function.

### Destination 3 - UID0001JD reconnect/leave callback

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void TerminalPane::OnReconnectOrLeave(unsigned long decision)
{
    if (decision != 0) {
        ScheduleTimer(0, 0, 0, 0);
        return;
    }

    g_pApplication->RequestExit();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior preservation:
  - unqualified inherited call lowers to the same `this + 0xa4` TimerHandler receiver;
  - decision branches, timer arguments, application exit, and void callback type are unchanged.
- Rejected source forms:
  - no `m_timerHandler`;
  - no pointer adjustment;
  - no explicit base cast;
  - no synthetic reconnect helper.

## Final Recommendation

- UID000247 is `92/94`, none/false/no emitter/blank position/blank C++, `Nested:0`.
- UID0000EG is `92/94`, retains owner/emitter UID0000OI, true, blank position, and the complete class managed block.
- UID0000OI is `90/92`, retaining file root/path and full TerminalPane/TerminalSetup union.
- UID0001JB is `90/92`, retaining owner/emitter UID0000OI, true, blank position/C++, and nonduplicating map.
- UID0001JK is `92/94`, none/false/no emitter/blank C++, with exact thunk evidence.
- UID0001JI is `92/94`, none/false/no emitter/blank C++, with exact direct Singleton unwind cause.
- UID0003DO is `92/94`, retaining owner/emitter UID0000EG, true, blank C++, and exact three-table evidence.
- UID0001JD is `91/94`, retaining owner/emitter UID0000OI, true, with the accepted formal body and no prose duplicate.
- UID0000SF and UID000300 retain `88/91`, metadata, and formal blocks with source-cause synchronization only.
- UID00012R, UID000197, DialDialog, PhoneBook successor, Pane, TimerHandler, and ignored padding were verified without edit.
- Future work outside this target:
  - exact child split and complete formal body for `0x0058b470` OnTimer may be researched independently;
  - raw `0x0058b0f0` may be revisited only if a real entry/receiver/liveness route is recovered.
- No future work is required to settle UID000247's current score, owner, reconstructable state, or formal C++.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md`
- Applied metadata:
  - `COMPLETION:92`
  - `CONFIDENCE:94`
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:FALSE`
  - blank `EMITTER_UIDS`
  - blank position
  - blank formal block from Destination 1
  - `Nested:0`
- Item Summary was replaced with full exact wrapper evidence and compiler-only disposition.
- The body-only illustrative C++ fence was removed.
- Applied evidence:
  - exact bytes/hash;
  - instruction/CFG/ABI;
  - exact xrefs and no ordinary caller;
  - all three flags branches;
  - one-byte no-free helper;
  - direct Singleton source cause;
  - DialogPane implicit base teardown;
  - exact direct bases/layout/size;
  - predecessor/successor/padding hashes;
  - generated-output expectations;
  - negative evidence and rejected source forms.
- Preserved:
  - historical A002 provenance;
  - DialDialog/PhoneBook separation;
  - polluted Boost rejection;
  - MemoryMan delete route.
- Historicalized:
  - old owner/emitter state;
  - unresolved source-name blocker;
  - any wording that treats the wrapper or clear as handwritten TerminalPane source.

## Recommended Support Doc Changes

| Support path | Applied callback result |
| --- | --- |
| `by-class/TerminalPane.md` | Applied `87/88 -> 92/94`, Destination 2 formal block, direct bases, RTTI/EBO/size, inline destructor cause, inherited TimerHandler, OnTimer, compiler split, raw-helper negative evidence, and historicalized old assumptions. |
| `by-file/TerminalPane.md` | Applied `87/85 -> 90/92`; preserved path/current union and synchronized class/global/source order, Singleton lifetime, OnTimer, inherited schedule call, and compiler split. |
| `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md` | Applied `87/88 -> 90/92`; preserved reconstructable blank aggregate and synchronized direct bases, EBO/size, wrapper no-code, OnTimer, raw-helper no-member status, schedule call, and B006 history. |
| `by-memory/0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks.md` | Applied `88/92 -> 92/94`; preserved none/false/no emitter/blank and added exact bytes/hash, vtable cells, wrapper relation, inherited-view cause, and no-source proof. |
| `by-memory/0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH.md` | Applied `86/90 -> 92/94`; preserved none/false/no emitter/blank and added exact bytes/hash, sole EH reference, direct Singleton unwind cause, and handwritten-clear rejection. |
| `by-memory/0x0062da10-0x0062daac.TerminalPaneVtableData.md` | Applied `87/93 -> 92/94`; preserved UID0000EG route/blank formal, populated summary, and added 23/11/2 slots, direct bases, OnTimer, wrapper/thunks, successor, and regeneration policy. |
| `by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md` | Applied `89/93 -> 91/94`, Destination 3 formal body, prose-duplicate removal, inherited facet explanation, and preserved callback type/range/behavior/callees. |
| `by-global/g_pTerminalPane.md` | Preserved `88/91`, route/formal definition; added direct Singleton publication/clear cause, EBO displacement, and handwritten/guarded-clear rejection. |
| `by-memory/0x0069bdf8-0x0069bdfc.g_pTerminalPane.md` | Preserved `88/91`, route/covered-by block; added direct Singleton source lifetime and retained nine refs/zero initialization. |
| `by-memory/0x0049d8a0-0x0049feae.DialogPane.md` | Verified same-or-greater; no edit. |
| `by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md` | Verified same-or-greater; no edit. |
| `by-memory/0x0058d750-0x0058dc5b.DialDialog.md` | Verified exact predecessor/exclusion; no edit. |
| `by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md` | Verified exact successor/exclusion; no edit. |
| `by-memory/-ignored.md` | Verified exact thunk and padding entries; no edit. |
| `by-class/TimerHandler.md`, `by-class/Pane.md` | Verified inherited callback/scheduler support; no edit. |

## Score And Metadata Recommendation

| UID | Before callback | Current applied | Owner / emitter | Reconstructable | Position / Nested | Rationale |
| --- | --- | --- | --- | --- | --- | --- |
| UID000247 | `86/90` | `92/94` | none / blank | False | blank / `0` | complete compiler wrapper, no source body |
| UID0000EG | `87/88` | `92/94` | UID0000OI / UID0000OI | True | blank / current | complete class/source declaration |
| UID0000OI | `87/85` | `90/92` | FILE | file root | existing path | complete source/compiler route |
| UID0001JB | `87/88` | `90/92` | UID0000OI / UID0000OI | True | blank / `0` | complete map, no duplicate C++ |
| UID0001JK | `88/92` | `92/94` | none / blank | False | blank / `0` | exact compiler thunks |
| UID0001JI | `86/90` | `92/94` | none / blank | False | blank / `0` | exact EH Singleton clear |
| UID0003DO | `87/93` | `92/94` | UID0000EG / UID0000EG | True | blank / `8` | exact compiler vtable data |
| UID0001JD | `89/93` | `91/94` | UID0000OI / UID0000OI | True | blank / `0` | source-legal inherited schedule call |
| UID0000SF | `88/91` | `88/91` retained | UID0000OI / UID0000OI | True | blank / current | exact global retained; source cause synchronized |
| UID000300 | `88/91` | `88/91` retained | UID0000SF / UID0000SF | True | blank / `8` | exact storage retained; source cause synchronized |

Score-improvement attempt:

- Exact range and bytes: resolved.
- ABI and return: resolved.
- CFG and branch semantics: resolved.
- Xrefs and callers: resolved.
- Vtables and thunks: resolved.
- Base cleanup identity: resolved.
- Delete route: resolved.
- Direct bases and inheritance: resolved.
- Singleton clear source cause: resolved.
- Layout and object size: resolved.
- Destructor source spelling: narrowed to explicit inline empty as strongest source-era form; implicit destructor remains a bounded lexical alternative.
- Timer virtual and member layout: resolved.
- Retained helper liveness/member status: exhaustively negative and no longer a class blocker.
- Remaining confidence caps:
  - exact original lexical member/method spellings;
  - explicit versus implicit empty destructor token in original source;
  - future exact body split for OnTimer.
- These caps justify `94`, not a lower score and not 95.

## Open Questions With Attempted Resolution

- Did the original author explicitly write the empty virtual destructor?
  - Checked: separate ordinary function absence, scalar wrapper inlining, RTTI, vtables, direct bases, project class declarations, modern accepted Singleton-pane precedents.
  - Resolution: explicit inline empty is highest probability and implementation-ready; implicit is a weaker lexical alternative. No behavior or metadata blocker remains.
- Should UID000247 carry a covered-by comment?
  - Checked modern ownerless scalar-wrapper precedents.
  - Resolution: no. Ownerless/non-emitting wrappers use a blank managed block; a covered-by comment would still emit artificial source.
- Should the source destructor clear the singleton?
  - Checked all nine refs, RTTI Singleton base, constructor/EH/destructor phase order.
  - Resolution: no handwritten clear. Direct Singleton base destruction causes unconditional zeroing.
- Should the clear be guarded?
  - Checked target instructions for load/compare.
  - Resolution: no. Guard is contradicted.
- Should source call DialogPane destruction?
  - Checked C++ base lifetime and target callee.
  - Resolution: no explicit call.
- Is `+0xa4` a member?
  - Checked RTTI, Pane layout, vtable heads, constructor stores.
  - Resolution: inherited TimerHandler view, not a member.
- Is `0x0058b470` OnDisconnect?
  - Checked table slot, receiver adjustment, `retn 0x0c`, return true, TimerHandler contract.
  - Resolution: OnTimer.
- Is raw `0x0058b0f0` a member?
  - Checked function promotion, xrefs, direct references, receiver use, bytes/callees.
  - Resolution: no current proof. Retain as file-local raw helper evidence without declaration.
- Does UID0001JD require an explicit cast or member field?
  - Checked inherited schedule wrappers and adjusted lowering.
  - Resolution: no. Unqualified inherited `ScheduleTimer` is source-legal and behavior-identical.
- Is a new source file required?
  - Checked current source tree, class/file docs, constructor callers, global owner, generated file.
  - Resolution: no.
- Remaining unresolved questions:
  - only stripped lexical spelling and future OnTimer body split, with no UID000247 score/C++ impact.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Manual files were read only. B001 must not apply these rows.
- Latest post-callback read-only snapshots are by-memory `A22703D70FB433DCEE752EC2F1372A5D2F2DAC3ADB150A474854ECE7FEF3DFD8`, by-class `AAE19425CFD36CBEF0A4CFDEADBF3799B5C15BB43E2DB3F742485C8F60162916`, by-file `D6DC2D3DAE7FFEFE18C5437687E007B80FE20B140BB7C67077D9D76BB65C707E`, and by-global `E1F80490A2DC7FDFD3458E1F8593FF05D2FC8338F56883B762654AF50CC90A35`. The first three hashes advanced through unrelated validator-owned coverage changes after callback validation; the exact UID000247-scope rows were re-read and did not change.
- Current manual rows remain stale or absent for the destinations listed below. This handoff is pending external supervisor-owned application and does not assert that coverage has been applied.
- Exact supervisor-owned replacement/insertion text follows.

### `by-memory/-coverage-report.md`

Placement: replace UID0001JB in the TerminalPane source cluster.

```text
    - [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md) : reconstructable : 90% : very-strong : Complete TerminalPane/TerminalSetupPane source map with exact method and padding inventory, direct DialogPane plus Singleton<TerminalPane> inheritance, +0x26c EBO/parser-state overlap, 0x270 TerminalPane size, corrected TimerHandler OnTimer identity, source-legal reconnect scheduling, retained no-route configured-connect helper evidence, child-first emission policy, singleton/vtable/compiler-wrapper separation, and exact PhoneBook successor boundary.
```

Placement: replace UID0001JD after UID0001JC.

```text
    - [UID:0001JD][0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback](by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md) : reconstructable : 91% : very-strong : Exact TerminalPane reconnect/leave member callback with 0x2f-byte boundary, typed void member-function callback installation, one data xref and no ordinary caller, nonzero inherited TimerHandler ScheduleTimer route, zero Application exit route, source-legal unqualified schedule call, preserved prompt semantics, and formal body.
```

Placement: replace UID0001JI.

```text
    - [UID:0001JI][0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH.md) : ignored : 92% : very-strong : Exact 11-byte constructor-unwind cleanup for the direct Singleton<TerminalPane> base; one zero store to g_pTerminalPane, one EH metadata xref, no ordinary caller, blank formal C++, and no handwritten clear-helper source.
```

Placement: replace UID0001JK.

```text
    - [UID:0001JK][0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks](by-memory/0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks.md) : ignored : 92% : very-strong : Exact two 0x0b-byte TerminalPane destructor adjustors; subtract +0xa0/+0xa4 inherited views and jump to UID000247, with secondary/tertiary vtable refs, exact bytes/hash, blank formal C++, and compiler-only source cause.
```

Placement: replace UID000247 after the existing five-byte padding row and before the eleven-byte padding row.

```text
    - [UID:000247][0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor](by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md) 0x0058dc60-0x0058dca5 | compiler-generated scalar deleting destructor | TerminalPane scalar deleting destructor ABI wrapper : non-reconstructable : 92% : very-strong : Fresh B001 live IDA proves the exact 0x45-byte body/hash, return-this/retn-4 ABI, primary plus +0xa0/+0xa4 adjustor routes, no ordinary caller, unconditional direct-Singleton clear, implicit DialogPane teardown, exact scalar-delete and guarded-size 0x270 branches, MemoryMan operator-delete dependency, closed DialDialog/PhoneBook padding boundaries, direct DialogPane plus Singleton<TerminalPane> layout, and ownerless non-emitting blank formal disposition.
```

Placement: insert UID0003DO as a child immediately under UID00026N TerminalPhoneReadOnlyData.

```text
        - [UID:0003DO][0x0062da10-0x0062daac.TerminalPaneVtableData](by-memory/0x0062da10-0x0062daac.TerminalPaneVtableData.md) 0x0062da10-0x0062daac | vtable-data | TerminalPaneVtableData : reconstructable : 92% : very-strong : Exact TerminalPane 23/11/2 primary, EventHandler, and TimerHandler vtable views with constructor stores, scalar-wrapper and +0xa0/+0xa4 adjustor slots, corrected OnTimer target at 0x0058b470, RTTI direct DialogPane plus Singleton<TerminalPane> hierarchy, exact TerminalSetupPane successor, class owner UID0000EG, and compiler-generated blank formal C++.
```

Placement: insert UID000300 as a child immediately under UID0002AQ TerminalAndTextEditGlobals.

```text
        - [UID:000300][0x0069bdf8-0x0069bdfc.g_pTerminalPane](by-memory/0x0069bdf8-0x0069bdfc.g_pTerminalPane.md) 0x0069bdf8-0x0069bdfc | global-data pointer storage | g_pTerminalPane storage : reconstructable : 88% : strong : Exact zero-initialized TerminalPane singleton storage with nine constructor/consumer/EH/destructor refs, direct Singleton<TerminalPane> publication/clear source cause, raw IDB-name caveat, separate TextEdit neighbors, and one covered-by route to UID0000SF without duplicate definition.
```

Placement: replace the stale UID000197 row at its existing location.

```text
    - [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md) 0x004f4ac0-0x004f4b00 | function | OperatorDeleteWrapper : reconstructable : 89% : strong : MemoryMan-backed global operator delete with exact 0x40-byte boundary, GetMemoryMan and FreeBufferMemory callees only, broad scalar-wrapper caller fan-in, formal global delete body, compiler EH/security-cookie exclusion, and UID000247 use only on the normal scalar-delete flag path.
```

### `by-class/-coverage-report.md`

Placement: replace UID0000EG TerminalPane.

```text
- [UID:0000EG][TerminalPane](by-class/TerminalPane.md) : reconstructable : 92% : very-strong : Complete TerminalPane declaration with direct DialogPane and Singleton<TerminalPane> bases, inline empty virtual destructor, exact +0x26c EBO/parser-state layout and 0x270 size, corrected OnTimer and inherited TimerHandler facet, parser/close/reconnect declarations, three vtable routes, singleton lifetime, wrapper/thunk/EH compiler exclusions, retained raw-helper no-member proof, and TerminalPane.cpp child route.
```

### `by-file/-coverage-report.md`

Placement: replace UID0000OI TerminalPane.

```text
- [UID:0000OI][TerminalPane](by-file/TerminalPane.md) : reconstructable : 90% : very-strong : NexusTK/login/TerminalPane.cpp source root with complete TerminalPane declaration/global/source order, TerminalSetupPane union, direct Singleton lifetime, parser and reconnect bodies, corrected OnTimer identity, retained configured-connect raw evidence, exact vtable/thunk/EH/scalar-wrapper compiler separation, DialogPane/MemoryMan dependencies, and PhoneBook boundary.
```

### `by-global/-coverage-report.md`

Placement: replace UID0000SF g_pTerminalPane.

```text
- [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md) : reconstructable : 88% : strong : Single TerminalPane pointer definition with exact zero storage child UID000300, nine constructor/consumer/EH/destructor refs, direct Singleton<TerminalPane> publication and unconditional clear source cause at +0x26c EBO, TerminalSetupPane/PhoneBook/Dial consumers, raw IDB-name caveat, and ownership in UID0000OI without duplicate or guarded source clear.
```

- No by-type manual row is required by this report.
- Reason B001 must not apply these changes: manual coverage files are supervisor-owned and are not synchronized by ordinary scoped validators.

## Follow-Up Actions

- Supervisor actions:
  - independent post-callback Gate 1/Gate 2 review remains supervisor-owned;
  - the exact manual coverage rows remain available for supervisor-owned application if still current.
- A-agent actions: none.
- B001 callback state:
  - implementation, validators, generated readback, report reconciliation, and lease release are complete;
  - no B001 implementation claim remains unapplied or blocked.
- Optional independent future target:
  - exact OnTimer child/body research for `[0x0058b470,0x0058b5e0)`;
  - raw configured-connect helper liveness if a real route appears.
- Lifecycle wording:
  - report validation, coverage application, execution, report path/count, movement, and archive state remain external supervisor/validator-owned state and are neither asserted nor directed by this artifact;
  - B001 performed no execute_report, lifecycle probe/count, move, or archive command.

## Confidence

- Recommendation confidence: `94/100`.
- Target score confidence: very strong.
- Class/source confidence: very strong for behavior, layout, and legal source shape; high for exact lexical destructor/member spellings.
- Remaining uncertainty:
  - explicit versus implicit source token for the empty virtual destructor;
  - exact original lexical names for parser state and reconnect callback;
  - complete OnTimer body source rendering;
  - retained raw helper original source/liveness.
- Impact of remaining uncertainty:
  - no effect on UID000247 range, ownerless/non-emitting classification, blank formal block, score, or compiler/source boundary;
  - bounded cap preventing confidence 95.

## Validator Results

All commands ran from `source-3/project-documentation`; every command exited `0` with `ok:1`.

| Command ID | Timestamp | Scoped file / purpose | Result and relevant side effects |
| --- | --- | --- | --- |
| `000000014043` | `2026-07-16T13:16:21-04:00` | UID000247 initial scoped validation | Applied `92/94`, owner NONE, false, blank route; generated refresh deferred. Reported pre-existing missing UID0003DO registry references. |
| `000000014044` | `2026-07-16T13:17:17-04:00` | `by-class/TerminalPane.md` | Applied `92/94` and registered the complete formal block; generated refresh deferred. Missing UID0003DO/UID0003GS reference warnings were pre-existing registry gaps. |
| `000000014045` | `2026-07-16T13:18:10-04:00` | UID0001JD callback | Applied `91/94` and new formal hash; generated refresh deferred. Missing pooled-string UID0003G3/UID0003G4 warnings were pre-existing registry gaps. |
| `000000014046` | `2026-07-16T13:19:07-04:00` | `by-file/TerminalPane.md` | Applied `90/92`; generated refresh deferred. Missing UID0003DP/UID0003G7/UID0003B1 warnings were existing reference-registry gaps. |
| `000000014053` | `2026-07-16T13:20:16-04:00` | UID0001JB aggregate | Applied `90/92`; generated refresh deferred. Missing UID0003DP reference warnings were pre-existing. |
| `000000014058` | `2026-07-16T13:20:45-04:00` | UID0001JK thunks | Applied `92/94`; generated refresh deferred; no target-specific warning. |
| `000000014062` | `2026-07-16T13:21:17-04:00` | UID0001JI EH clear | Applied `92/94`; generated refresh deferred; no target-specific warning. |
| `000000014064` | `2026-07-16T13:21:46-04:00` | UID0003DO vtable | Registered existing UID/path, applied `92/94`, owner/emitter UID0000EG, and preserved blank formal; generated refresh deferred. Missing UID0003GS warning remained pre-existing. |
| `000000014065` | `2026-07-16T13:22:15-04:00` | `by-global/g_pTerminalPane.md` | Passed with retained `88/91` metadata/formal; generated refresh deferred. |
| `000000014067` | `2026-07-16T13:22:45-04:00` | UID000300 storage | Passed with retained `88/91` metadata/formal; added reference index; generated refresh deferred and subsequently wrote the current TerminalPane.cpp header. |
| `000000014068` | `2026-07-16T13:23:34-04:00` | final UID000247 `--wait-generated` | Exit 0/ok1; full registry/generated metadata refresh completed. No current source change followed command 14067, so unchanged TerminalPane.cpp retained header command 14067 while command 14068 verified the waited current union. |

Generated `auto-generated/NexusTK/login/TerminalPane.cpp` readback:

- header command `000000014067`, refreshed `2026-07-16T13:22:45-04:00`;
- final waited verification command `000000014068`, completed `2026-07-16T13:23:34-04:00`;
- SHA256 `3DCC82FAF93E4321D2EB18EA78614F6642C526201EF12117D6106192E353F57C`;
- 5,010 bytes / 155 lines;
- one complete `class TerminalPane : public DialogPane, public Singleton<TerminalPane>` declaration;
- one inline `virtual ~TerminalPane()`, zero out-of-class destructor definitions;
- zero UID000247, UID0001JK, and UID0001JI output or target empty marker;
- one UID0001JC/parser definition, one UID0000SF/global definition, one UID0001JD/callback definition;
- one exact `ScheduleTimer(0, 0, 0, 0);`, zero `m_timerHandler`;
- one `OnTimer` declaration, zero `OnDisconnect`;
- zero `ScalarDeletingDestructor`, `operator delete`, `0x270`, `vptr`, explicit singleton-clear, adjustor, DialogPane-destructor, or guarded-size source tokens.

Known warnings were unrelated/pre-existing missing-reference registry entries and did not prevent any scoped page from returning ok1. B001 did not repair validator state manually.

## Changed Files

- Updated report:
  - `tools/leaser/Agents/Agent-B001/research/000247-TerminalPaneScalarDeletingDestructor-source-quality.md`
- Modified ordinary files:
  - `by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md` - `C5139B5AB1D906B3D9A47A54A866234E4449FE31CC3A04C624CDF46129F40D11`
  - `by-class/TerminalPane.md` - `0655596578611CDAFC16345B447413CA6380D81110322FCB8B754B440110E9EA`
  - `by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md` - `DCDE4554172E9656A6F8F2FD1DED89CBBCD7832DE5E6723D6713AF218483E724`
  - `by-file/TerminalPane.md` - `789CFFDB4FBEE61DF3DF23DD174BB51F93768633F983B6412E9C4850CC42DD7F`
  - `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md` - `65BABF633BE177565A4B2EF2AB60352139CA810806D09E96ADF770F49C180F56`
  - `by-memory/0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks.md` - `7BB087B3F49BBFB00E346109A8E8A3B4A828E7C7FC1CAA0C4E47D1EF6341EE31`
  - `by-memory/0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH.md` - `6C2C2A78B14A38FE1A53761E1BB2CC5B5B7D838CED2B0A7A350C0F38C7EE7B4D`
  - `by-memory/0x0062da10-0x0062daac.TerminalPaneVtableData.md` - `C93DD16CBA66331B931359C02379D7DF1834F042BDB80ECC94542A85427E924D`
  - `by-global/g_pTerminalPane.md` - `4F29178766A6501785A496BE066AF537F1B553B362AD63197CEE0773EAB67077`
  - `by-memory/0x0069bdf8-0x0069bdfc.g_pTerminalPane.md` - `5F8E8EAFDD47E12BBC104A15605389367CB2B9BFCA92C948D8A31C16C8E2BA98`
- Renamed ordinary files: none.
- Deleted files: none.
- Coverage/generated/tracker/audit/supervisor/validator-state/lifecycle files: none edited.
- IDA database: no mutation.
- Leases: one ordinary file at a time; each was released immediately after its scoped validator. Final lease report contains no B001 row.
- Report execution: not run.
- Report lifecycle/probe/count/move/archive commands: not run.

## Implementation Tracking Checklist

Implementation callback completion checklist:

- [x] Exact report artifact passed supervisor Gate 1 before ordinary implementation.
- [x] Re-read UID000247 immediately before callback edit.
- [x] Applied UID000247 `92/94`, none/false/no emitter/blank position/blank formal C++/`Nested:0`.
- [x] Replaced UID000247 Item Summary and body with full exact bytes/hash/ABI/CFG/xref/flag/padding/source-cause evidence.
- [x] Removed UID000247 body-only illustrative C++ and preserved historical A002 evidence as superseded history.
- [x] Re-read UID0000EG immediately before callback edit.
- [x] Applied UID0000EG `92/94` and exact Destination 2 managed class block.
- [x] Removed the class body-only sketch and historicalized Pane-only, OnDisconnect, `m_timerHandler`, and member raw-helper assumptions.
- [x] Re-read UID0001JD immediately before callback edit.
- [x] Applied UID0001JD `91/94` and exact Destination 3 managed body.
- [x] Removed UID0001JD body-only prose code duplicate and preserved all callback behavior/evidence.
- [x] Re-read and updated UID0000OI to `90/92` with complete source/compiler route.
- [x] Re-read and updated UID0001JB to `90/92`, preserving blank nonduplicating formal C++.
- [x] Re-read and updated UID0001JK to `92/94`, preserving none/false/no emitter/blank C++.
- [x] Re-read and updated UID0001JI to `92/94`, preserving none/false/no emitter/blank C++.
- [x] Re-read and updated UID0003DO to `92/94`, preserving UID0000EG owner/emitter and blank formal C++.
- [x] Re-read and synchronized UID0000SF source-cause prose without score/formal/metadata change.
- [x] Re-read and synchronized UID000300 source-cause prose without score/formal/metadata change.
- [x] Verified UID00012R carries same-or-greater DialogPane cleanup proof; no edit was required.
- [x] Verified UID000197 carries same-or-greater MemoryMan operator-delete proof; no edit was required.
- [x] Verified DialDialog predecessor, PhoneBook successor, Pane, TimerHandler, and ignored rows remain same-or-greater; no edit was required.
- [x] Preserved exact target bytes/hash, thunk bytes/hash, EH bytes/hash, padding hashes, and vtable/RTTI values.
- [x] Preserved all positive evidence, negative evidence, rejected alternatives, and superseded A002/B006/B005 assumptions.
- [x] Preserved current parser/global/callback behavior and unrelated TerminalPane/TerminalSetup content.
- [x] Applied exactly three accepted managed formal blocks and left no body-only C++ in those destinations.
- [x] Confirmed no new child, UID, source file, or ignored span is required for UID000247.
- [x] Kept third-party import not applicable.
- [x] Kept manual coverage edits supervisor-owned and preserved exact handoff rows without editing coverage.
- [x] Used one short lease for only the immediate ordinary file being edited.
- [x] Ran one scoped validator for each changed ordinary destination and released its lease immediately.
- [x] Recorded each validator command ID, timestamp, exit, ok count, warnings, and side effects.
- [x] Ran final target validation with `--wait-generated`.
- [x] Verified generated TerminalPane.cpp contains one complete TerminalPane class declaration.
- [x] Verified generated TerminalPane.cpp contains one inline empty virtual destructor and no out-of-class target destructor definition.
- [x] Verified UID000247 occurs zero times and no UID000247 Empty Emitter Marker remains.
- [x] Verified UID0001JK and UID0001JI compiler pages emit no bodies.
- [x] Verified parser, global definition, and reconnect callback each occur exactly once.
- [x] Verified reconnect callback contains one unqualified inherited `ScheduleTimer(0, 0, 0, 0)` and zero `m_timerHandler`.
- [x] Verified generated class declares `OnTimer` and does not declare `OnDisconnect`.
- [x] Verified no explicit vptr, adjustor, singleton clear, DialogPane destructor call, delete flags, guarded-size path, or operator delete appears as TerminalPane source.
- [x] Re-read current manual coverage after ordinary callback and rebased current snapshots; exact handoff text remains applicable.
- [x] Updated every C247-001 through C247-056 row to a legal callback verification state with claim-specific proof.
- [x] Recorded exact changed-file hashes and generated hash/header/assertions.
- [x] Checked callback checklist items only after independent proof.
- [x] Confirmed zero B001 leases remain.
- [x] Confirmed B001 did not edit coverage/generated/tracker/audit/supervisor/validator-state/lifecycle/IDA files.
- [x] Confirmed B001 did not run execute_report, report probes/counts, move, or archive commands.

Implementation callback pass:

- [x] Exact report artifact was accepted by supervisor before ordinary edits.
- [x] All accepted target/support facts were incorporated at report-level detail without compression.
- [x] All accepted metadata/score/owner/emitter/reconstructable/C++ changes were applied or excluded with exact reason.
- [x] Every changed ordinary page scoped-validates successfully.
- [x] Final waited generated refresh completed and exact assertions passed.
- [x] Exact supervisor-owned manual coverage handoff remains current and unapplied by B001.
- [x] No accepted claim remains unapplied or blocked.
- [x] Same report is reconciled to terminal callback truth.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000014095","destination_path":"executed-b-agent-research/B001/000247-TerminalPaneScalarDeletingDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/000247-TerminalPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-07-16T13:43:20-04:00","uid":"000247"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
