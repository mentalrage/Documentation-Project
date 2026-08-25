** TARGET-REPORT-UID:0004EM **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0004EM PrettyButtonControlPaneScalarDeletingDestructor Source-Quality Report

## Finalized Report / Current Recommendation

- Implemented target: [UID:0004EM] `by-memory/0x0054bc40-0x0054bcbd.PrettyButtonControlPaneScalarDeletingDestructor.md` is exact MSVC compiler deleting-destructor output at `92/94`, retains semantic owner `0000AR`, is `RECONSTRUCTABLE:FALSE`, has blank `EMITTER_UIDS`, blank optional position and formal C++, and retains `Nested:0`.
- Implemented source disposition: the human source is the virtual destructor declaration in complete [UID:0000AR] `PrettyButtonControlPane` plus exact [UID:0004E4] ordinary destructor body R9. UID0004EM emits no C++.
- Implemented class closure: UID0000AR carries exact R2 at source position `10`, closes the `0x128` object layout, declares all seven source methods, and closes before `[[CHILDREN]]`; UID0000AS remains complete at position `20`.
- Implemented child/source synchronization: UID0004E3 carries exact R3 with `RectBounds`, protected inherited control-state assignments, and normalized selected-state names; UID0004E8 carries exact R7; R4-R6/R8-R9 remain byte-for-byte exact.
- Implemented support disposition: UID0001F9 remains `88/90` false/blank with every child and pad preserved; UID0002UW is `90/94` with exact R10; UID0000MP is `92/93` with the complete two-class source/compiler union.
- Confidence: very strong for target range, bytes, ABI, flag matrix, teardown, vtable/thunk reachability, object size/layout, source/compiler boundary, and source route; strong for the most plausible original member/header spellings and access labels.
- Callback boundary: B003 implemented and scoped-validated only the eight accepted ordinary destinations. B003 did not manually edit coverage, generated output, tracker, audit/supervisor files, validator state, IDA, or lifecycle/archive state and did not run `execute_report` or any report lifecycle command.

Immutable callback-return evidence:

`READY_FOR_SUPERVISOR_GATE2_REVIEW`

## Supporting Research

- Canonical assignment read: `tools/leaser/Agents/Agent-B003/goal.md`.
- Project workflow and report rules read:
  - `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/SKILL.md`
  - `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
  - `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/references/b-agent-report-template.md`
  - `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/references/score-blocker-audit-standard.md`
  - current compiler/source, owner/emitter, reconstructable, C++-gate, generated-binary-data, and manual-coverage rules in `by-structure.md`.
- Evidence-time target/support docs read before implementation:
  - UID0004EM target.
  - UID0004E3 constructor.
  - UID0004E4 ordinary destructor body.
  - UID0004E5 `SetSelected`.
  - UID0004E6 `SetCallback`.
  - UID0004E7 `SetState`.
  - UID0004E8 `OnPaint`.
  - UID0004E9 `OnClick`.
  - UID0004EJ/UID0004EK adjustor thunks.
  - UID0002UW class1 vtable/RTTI data.
  - UID0001F9 executable split/index.
  - UID0000AR class.
  - UID0000MP file.
  - UID000038 `ControlPane`, UID00001E `ButtonControlPane`, UID0000AS `PrettyButtonControlPane2`, and their current source contracts.
- Evidence-time generated/read-only project state read before implementation:
  - `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp`
  - `auto-generated/-ag-research-tracker.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/-ag-coverage-report-by-memory.md`.
- Current manual coverage read without editing:
  - `by-memory/-coverage-report.md`
  - `by-class/-coverage-report.md`
  - `by-file/-coverage-report.md`
  - `by-type/by-vtable/-coverage-report.md`.
- Prior-report searches used the exact terms `TARGET-REPORT-UID:0004EM`, `0004EM-PrettyButtonControlPaneScalarDeletingDestructor-source-quality.md`, `UID:0004EM`, `0x0054bc40`, `PrettyButtonControlPaneScalarDeletingDestructor`, and `sub_54BC40`.
- Search roots and outcomes:
  - `executed-b-agent-research/**`: zero dedicated UID0004EM report/header/filename; support mentions only. Target-specific useful leads were B008 UID0004E4 ordinary destructor, B011 UID0001F9 split/index, B004 UID0002UW vtable, B007 UID0004E3 constructor, B014 UID0004E5 selected setter, B015 UID0004E6 callback setter, B001 UID0004E7 state method, B002 UID0004E8 paint, and B003 UID0004EL class2 wrapper comparator.
  - `archived/**`: zero matches for every exact term.
  - `tools/leaser/Agents/Older-Research/**`: zero matches for every exact term.
  - `tools/leaser/Agents/SpecialReports/**`: zero matches for every exact term.
  - active `tools/leaser/Agents/Agent-B001/research/**` through `Agent-B005/research/**`: zero matches for every exact term.
- The prior reports were treated as leads only. Target bytes, wrapper behavior, constructor fields, selected-state callers, class layout, and current generated/manual state were independently revalidated.
- Historical Wave2/Wave3 or simroot material was not used as authority. Any such names retained in current docs are superseded provenance only.

## Target

- Target UID: `0004EM`.
- Target path: `by-memory/0x0054bc40-0x0054bcbd.PrettyButtonControlPaneScalarDeletingDestructor.md`.
- Exact half-open range: `[0x0054bc40,0x0054bcbd)`.
- Historical source queue row at the evidence snapshot: by-memory Not-Covered Files - Reconstructable, `86/90`, owner/emitter `0000AR`, `RECONSTRUCTABLE:TRUE`, comment-only formal, blank position, `Nested:0`, direct-report count zero.
- Current direct semantic owner: [UID:0000AR] `PrettyButtonControlPane`.
- Current source-file route: UID0000AR -> [UID:0000MP] `PrettyButtonControlPane` -> `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
- Implemented target state: `92/94`, owner `0000AR`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal, `Nested:0`.

## Current Target State

- Implemented ordinary target snapshot:
  - SHA256 `53726568A669290E4EC0A47EB40FC70CB7368B20C102DA9A11DFBF8EC52C9426`
  - 10,893 bytes
  - 134 lines
  - metadata `92/94`, owner `0000AR`, false, blank emitter/position/formal, `Nested:0`.
- Implemented source/support snapshots:
  - UID0000AR `92/93`, position `10`, exact R2, SHA256 `93605A05F618A014EA3EA124B9BA9BF27CC272F87F63D4BBF5EAC844A4BDB0BD`.
  - UID0004E3 `90/92`, exact R3, SHA256 `1360293AC1EED01F569110FCA021E774D81AD9391AB4DE14DD9A7DDA244AB183`.
  - UID0004E5 remains `88/91`, exact R4 with normalized selected-state prose, SHA256 `93F720C27F3EC1BECB6827D4B419FE855C59B7008BD7F291C2058986C6985ACB`.
  - UID0004E8 `90/92`, exact R7, SHA256 `E0E152D91ECED46F83A04972B9AE0C2666E4C0EF12AAE08610E5B1BDB28B7A76`.
  - UID0002UW `90/94`, exact R10, SHA256 `B17EF8B2D147232513FF01F4EDA9B07DB68165542D30E6AB9A48E5A0770F5034`.
  - UID0001F9 remains `88/90` false/blank, SHA256 `013B1CD6BD47E1065CA30CB387D9054BBB6DA7E5085F380D0DAAD8BC689D9886`.
  - UID0000MP `92/93`, SHA256 `8EF7840F1ECFA61D40B19922269380C4F4E4F8D74C732819CFBD14C20E17CE80`.
- Historical generated evidence-time snapshot, read only:
  - validator command/header `000000013791`
  - refreshed `2026-07-16T10:53:06-04:00`
  - SHA256 `91B06EB8F4F6077D07ED41DEB7E19181CC8E42FBCEBEE67588D855A21E9616EC`
  - 9,677 bytes
  - 270 lines.
- Historical generated semantic defects at that pre-callback snapshot:
  - `PrettyButtonControlPane2` declaration exists and closes at line 45.
  - No `PrettyButtonControlPane` declaration exists.
  - Seven class1 qualified definitions appear at lines 157-264.
  - UID0004EM comment output occurs once.
  - UID0000AR Empty Emitter Marker occurs once.
  - UID0002UW Empty Emitter Marker occurs once.
  - stale `Rect`, derived inherited-state aliases, and hover/state aliases remain in emitted class1 source.
- Historical B003 callback generated checkpoint:
  - validator command/header `000000013813`
  - refreshed `2026-07-16T11:21:05-04:00`
  - SHA256 `5F5F1D97E7C1F1857C8FA3F2EBCEBC8218D1E8F56B618374F41C44659D43D514`
  - 10,668 bytes
  - 303 lines
  - one complete class1 declaration and one complete class2 declaration, each closed before its seven qualified definitions;
  - all fourteen source definitions occur exactly once;
  - UID0004EM title/address/comment output count zero;
  - UID0000AR and UID0002UW Empty Emitter Marker counts zero;
  - UID0002UW and UID0002UX generated-binary markers occur once each;
  - no handwritten RTTI/vtable arrays, raw addresses, `sub_` labels, vptr stores, deleting flags, adjustor ABI, SEH/cookie/runtime-guard, or decompiler syntax.
- Current read-only external generated checkpoint:
  - validator command/header `000000013820`
  - refreshed `2026-07-16T11:25:27-04:00`
  - SHA256 `FA314493928A796826D44A439F3EACBBFC3146EFF4D13384A9059216FCCC9970`
  - 10,668 bytes
  - 303 lines
  - replacing only the command/timestamp header with the B003 command-13813 values reproduces exact SHA256 `5F5F1D97...3D514`, proving the source body is unchanged;
  - all method, declaration, marker, exclusion, and ordering assertions above were reread and remain exact.
- Exact later Gate 2, coverage application, execution/revalidation/invalidation, count, path, movement, archive, and lifecycle state is external validator/supervisor-owned state and is not asserted by this callback artifact.

## Executive Recommendation

- Treat UID0004EM as compiler-only deleting-destructor output, not a source method, covered-by comment, or dead raw helper.
- Preserve UID0000AR as semantic owner because the wrapper is generated from `PrettyButtonControlPane`'s virtual destructor and exact layout.
- Move all source-bearing semantics to the complete UID0000AR declaration and UID0004E4 ordinary destructor body.
- Install UID0000AR at source position `10` so class1 declaration and children precede UID0000AS position `20`, matching class/address order and eliminating marker-only output.
- Normalize the class1 source model to the exact `0x128` layout:
  - complete `ButtonControlPane` base through `+0x10b`;
  - three frame IDs at `+0x10c/+0x110/+0x114`;
  - `m_selected` and `m_visualStateFrameActive` at `+0x118/+0x119`;
  - natural 2-byte alignment at `+0x11a..+0x11b`;
  - two pointer-sized wide `StringBase` members at `+0x11c/+0x120`;
  - owned `FunctionObject0 *m_callback` at `+0x124`.
- Preserve all compiler lowering as non-source: vptr stores, member/base destructor sequencing, deleting flags, storage release, bit-4 no-op branch, adjustor thunks, RTTI/vtable arrays, SEH/cookies, and return-this ABI.
- No split, merge, rename, new UID, or new ordinary page is required.

## Supervisor Active Recheck

- Historical pre-callback gate: this assignment required a report-first pass and a separate supervisor callback before ordinary implementation; exact artifact `C65EA1F...7A7C4` received that authorization.
- The target is one exact modeled compiler wrapper; split repair is not required.
- The associated source declaration debt is not deferred:
  - exact class size/layout is closed;
  - constructor type/access/name conflicts are closed;
  - paint selected/state aliases are closed;
  - ordinary destructor source is already exact;
  - vtable generated-data disposition is closed;
  - source placement and declaration order are closed.
- Every source-bearing class1 child in scope is either supplied as an exact formal destination or verified at same-or-greater source detail.
- No in-scope blocker remains as "needs investigation."

## Inference Research Guidance Check

- Direct MCP facts, documentation evidence, and inference are separated throughout this report.
- Existing target metadata was treated as a hypothesis. The broad compiler-wrapper label was confirmed, while reconstructable/emitting/comment output was rejected.
- Existing class1 names were not copied forward:
  - caller pairs that clear the old choice and set the new choice prove `SetSelected` and `m_selected`;
  - the same selected byte selects the third frame, so `m_selectedFrameId` is stronger than `m_hoverFrameId`;
  - UID0004E7 directly writes the other byte, so `m_visualStateFrameActive` is stronger than `m_state11VisualActive`;
  - accepted base declarations prove `+0xff/+0x100` are inherited protected state, not duplicate Pretty-owned members.
- Consumer dialogs and neighboring source addresses were not treated as owners. They are construction/use evidence for a reusable control class.
- Exact original member/header names remain inferred where symbols are absent, but the chosen names are behaviorally coherent and consistent with accepted sibling/base conventions.
- Wave2/Wave3 and simroot references were ignored as current authority.

## Heuristic / Inference Reanalysis And Validation

### Compiler-wrapper classification

- Live MCP models `sub_54BC40` at `0x0054bc40`, size `0x7d` / 125.
- The function receives complete object `this` in `ecx`, consumes one four-byte flags argument, returns complete `this` in `eax`, restores three vtable views, performs derived/member/base teardown, tests deletion flags, optionally frees storage, and is reached from a primary vtable plus two receiver-adjustor thunks.
- Those properties are the exact compiler deleting-destructor pattern. A source-authored method interpretation is rejected.

### Exact deletion-flag behavior

- `(flags & 1) == 0`: teardown only; return complete `this`; no storage release.
- `(flags & 1) != 0 && (flags & 4) == 0`: teardown; call global operator delete route `sub_4F4AC0(this)`; return complete `this`.
- `(flags & 1) != 0 && (flags & 4) != 0`: teardown; push complete object size `0x128` and `this`; directly call one-byte `@_guard_check_icall_nop@4`; return complete `this`; no storage release.
- The bit-4 branch is not vector deletion, sized delete, a user callback, or source-authored logic. Live disassembly proves the destination is one instruction, `retn`.

### Teardown/source decomposition

The wrapper duplicates UID0004E4's ordinary destructor lowering rather than calling a distinct source destructor function:

1. Read the owned callback pointer at `+0x124`.
2. Restore class1 primary/secondary/tertiary vtables at `+0x00/+0xa0/+0xa4`.
3. If the callback is non-null, invoke its deleting virtual with flag `1`, source-shaped as `delete m_callback`.
4. Destroy the palette string member at `+0x120`.
5. Destroy the EPF string member at `+0x11c`.
6. Run inherited Pane/ControlPane/ButtonControlPane teardown through `sub_544580`.
7. Apply deleting flags and return complete `this`.

Only the derived destructor statement `delete m_callback;` is human source. Vptr stores, member destructor calls, base destructor calls, flags, storage release, no-op runtime branch, and return-this ABI are compiler lowering.

### Reachability and liveness

- Primary vtable cell `0x006222d8` contains `0x0054bc40`.
- Secondary cell `0x00622340` contains `0x0054bb9f`; its two-instruction thunk subtracts `0xa0` from `ecx` and jumps to UID0004EM.
- Tertiary cell `0x00622370` contains `0x0054bbaa`; its two-instruction thunk subtracts `0xa4` and jumps to UID0004EM.
- `xrefs_to 0x0054bc40` returns exactly the two thunk jumps and primary vtable data reference. No ordinary source call exists.
- The target is live compiler ABI output and must remain documented, but source emission is invalid.

### Constructor and layout closure

- Live constructor MCP reports `sub_54B5E0`, size `0xc4`, 59 instructions, and 30 direct calls from three containing functions.
- All constructor callers allocate `0x128` / 296 bytes.
- The constructor calls `ButtonControlPane(bounds)`, stores frame IDs at `+0x10c/+0x110/+0x114`, clears the adjacent word at `+0x118`, constructs strings at `+0x11c/+0x120`, writes the final byte argument to inherited `+0xff`, clears callback `+0x124`, and clears inherited `+0x100`.
- Exact source-visible body order after string construction is inherited `m_controlFlags`, owned `m_callback`, inherited `m_reservedControlState`.
- `RectBounds` is the accepted current rectangle spelling. Historical `Rect` is a stale source-facing alias.
- The exact source-safe object layout is:

| Offset / span | Size | Source member / subobject | Evidence and disposition |
| --- | ---: | --- | --- |
| `+0x000..+0x10b` | `0x10c` | complete `ButtonControlPane` base | Current accepted base declaration and deleting-wrapper size. |
| `+0x10c..+0x10f` | `4` | `int m_normalFrameId` | Constructor store and default paint branch. |
| `+0x110..+0x113` | `4` | `int m_pressedFrameId` | Constructor store and visual-state-active paint branch. |
| `+0x114..+0x117` | `4` | `int m_selectedFrameId` | Constructor store and selected-state paint branch. |
| `+0x118` | `1` | `bool m_selected` | UID0004E5 direct writer; 42 selection caller xrefs; UID0004E8 reader. |
| `+0x119` | `1` | `bool m_visualStateFrameActive` | UID0004E7 direct writer; UID0004E8 first-priority reader. |
| `+0x11a..+0x11b` | `2` | natural alignment | No source field. |
| `+0x11c..+0x11f` | `4` | wide `StringBase` EPF resource | Constructor, paint `c_str`, destructor cleanup. |
| `+0x120..+0x123` | `4` | wide `StringBase` palette resource | Constructor, paint `c_str`, destructor cleanup. |
| `+0x124..+0x127` | `4` | `FunctionObject0 *m_callback` | Constructor clear, setter replacement, click invoke, destructor delete. |

### Selected-state versus hover-state naming

- UID0004E5 has 42 direct caller xrefs.
- Representative callers obtain old/new controls, call the method with `0` on the old index and `1` on the new index, then store the new selected index and refresh associated display data.
- UID0004E8 tests `+0x119` first, then `+0x118`; `+0x118` selects frame `+0x114`.
- UID0004E7 exclusively manages `+0x119`, so the second byte cannot be the selected state.
- `m_selected` and `m_selectedFrameId` are therefore the strongest source-facing names. `m_hoverFrameActive`/`m_hoverFrameId` are rejected as inconsistent with actual caller semantics.

### Access and dependency closure

- `m_controlFlags` and `m_reservedControlState` are protected inherited `ControlPane` fields. Direct Pretty constructor assignments are legal under the accepted current base declaration; duplicate derived fields or invented setters are rejected.
- `ButtonControlPane.h` must be included because the base must be complete.
- `StringBase.h` must be included because both string template instances are by-value members.
- `FunctionObjects.h` must expose a complete `FunctionObject0` before the ordinary destructor's `delete m_callback`.
- `RectBounds` can be forward-declared because it is used by reference.
- `Event` is not referenced by the class1 declaration. Its forward declaration remains the responsibility of the complete `ButtonControlPane` dependency; adding a redundant Pretty-level include or declaration is unnecessary.
- `EPFTileContext` and frame-render helper types are method-definition dependencies in the source translation unit, not class-layout members.

### Declaration order and generated source

- UID0000AR should use source position `10`; UID0000AS already uses `20`.
- This preserves source/address order: class1 declaration and seven class1 definitions precede class2 declaration/definitions.
- The class must close before `[[CHILDREN]]`. Placing children inside the class would make qualified definitions invalid.
- The wrapper target must disappear from generated source, UID0000AR marker must disappear, and UID0002UW should emit one generated-binary marker rather than raw arrays or an Empty Emitter Marker.

### Rejected alternatives

- Handwritten deleting-destructor body: rejected because it duplicates compiler ABI lowering.
- Covered-by/comment target marker: rejected because the precise disposition is false/blank.
- Dead/raw helper: rejected by exact vtable/thunk reachability.
- Ownerless target: rejected because class declaration/layout/destructor source is known.
- `PrettyButtonControlPane2` owner: rejected by distinct class2 vtables, layout, methods, and wrapper UID0004EL.
- `m_hoverFrameId`/`m_hoverFrameActive`: rejected by selection caller pairs and direct state writer separation.
- Pretty-owned `m_constructorFlag`/`m_reservedState`: rejected by accepted inherited base layout and repeated direct derived stores.
- `Rect`: rejected as historical alias; `RectBounds` is the current coherent family type.
- Multiple source bases for three vtable views: rejected; one public `ButtonControlPane` source base generates inherited adjusted ABI facets.
- Raw vtable/RTTI arrays, vptr writes, SEH, cookie, `sub_` names, offsets, or delete flags in human source: rejected as compiler/decompiler artifacts.

## Evidence Standards Used

- Highest-weight evidence:
  - live IDA MCP function lookup, bytes, disassembly, decompilation, xrefs, vtable integers, thunk bodies, function sizes, CFG blocks, instruction counts, and health status;
  - exact constructor stores/callers and selected-state caller pairs;
  - exact ordinary destructor raw body and class2 deleting-wrapper comparator.
- Corroborating evidence:
  - current by-memory/by-class/by-file documentation;
  - accepted current base declarations and class2 declaration;
  - generated output and tracker/coverage snapshots;
  - manual coverage rows.
- Negative evidence:
  - no direct ordinary caller to the target;
  - no source-only target behavior beyond ordinary destructor/deletion ABI;
  - no hover-specific caller semantics;
  - no class-local fields at inherited `+0xff/+0x100`;
  - no need for a split, rename, new UID, or third-party route.
- The evidence ladder supports very strong binary/source-boundary confidence. Exact original private member/header spellings remain inferred and cap confidence below perfect recovery.

## Evidence Checked

- Live MCP endpoint: `http://127.0.0.1:13337/mcp`.
- MCP transport session headers were initialized successfully during the evidence pass.
- Fresh `idb_list`: one active NexusTK database, session `64c11373`, worker PID `21508`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health`: `status:"ok"`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, cache size `2067`.
- Bounded target probe: `lookup_funcs 0x0054bc40 -> sub_54BC40`, size `0x7d`; bounded first-byte read returned real target bytes.
- Target checks:
  - `analyze_function`
  - `decompile`
  - `disasm` with total count
  - `xrefs_to`
  - exact surrounding bytes
  - exact target-only byte SHA256
  - integer conversions.
- Dependency checks:
  - constructor analyze/decompile/disasm/xrefs;
  - selected setter analyze/disasm/xrefs and representative caller decompilation;
  - paint analyze/decompile/disasm;
  - vtable cell reads/xrefs;
  - both adjustor-thunk disassemblies;
  - bit-4 helper lookup/disassembly;
  - ordinary destructor raw bytes/current doc;
  - class2 wrapper/class declaration comparator.
- Documentation searches:
  - current target/support ordinary docs;
  - executed-report exact-term roots;
  - archived, Older-Research, SpecialReports, and active B-agent roots;
  - current generated source, tracker, generated coverage, manual coverage, and leases.
- One local PowerShell response parser initially used the wrong `get_bytes` object key and returned an address-parse error. The call was corrected to the documented `addr` schema and all bounded MCP reads then succeeded. That local argument error is not MCP outage evidence and contributes no target conclusion.
- Historical report-only evidence collection used no implementation validator, generated refresh, report execution/probe, IDA mutation, or unavailable fallback route. The later accepted callback used only the scoped validators and waited generated refresh recorded below; B003 still performed no report execution/probe/lifecycle command and no IDA mutation.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | Evidence-time IDB session `64c11373` was healthy and returned real target/function/byte evidence. | Very high | `idb_list`, `server_health`, target lookup/read. | Target IDA evidence; class/file/parent support; report Validator Results. | already-present | already-present | Captured evidence remains unchanged in the report and implemented destination prose; callback required no IDA mutation or new conclusion. |
| C02 | UID0004EM is exactly `[0x0054bc40,0x0054bcbd)`, size `0x7d`/125, binary SHA256 `A5038605020B355F8406805F041DC299171738E29A3D4DFF9F89E48A267E246F`, with 3-byte predecessor and 3-byte successor `0xcc` pads excluded. | Very high | MCP bytes/hash/disasm; parent/ignored rows. | Target range/hash/pads; parent inventory; manual row. | incorporate | applied | Target command `13795` and parent command `13808`; target SHA `53726568...C9426`, parent SHA `013B1CD6...9886`. |
| C03 | Target ABI is x86 `__thiscall`, one four-byte flags argument, complete-object return, 39 instructions, 7 blocks, complexity 3. | Very high | Analyze/decompile/disasm. | Target ABI/CFG/instruction evidence. | incorporate | applied | UID0004EM exact ABI/CFG/instruction section validated by command `13795`. |
| C04 | Exact flag matrix is bit1 deletion, bit4 direct one-byte no-op with object size `0x128`; only bit1-set/bit4-clear calls global operator delete. | Very high | Target/helper disassembly; int conversion. | Target behavior/no-code proof; class layout. | incorporate | applied | Target behavior/no-code proof command `13795`; class layout/formal command `13796`. |
| C05 | Target teardown duplicates UID0004E4: callback delete, palette/EPF string cleanup, inherited teardown, then compiler delete ABI. | Very high | Target and ordinary raw body comparison. | Target source/compiler split; class/file/parent history. | incorporate | applied | Target `13795`, class `13796`, parent `13808`, file `13812`; R9 verify-only parity true. |
| C06 | Reachability is primary vtable plus `-0xa0`/`-0xa4` adjustor thunks; no ordinary direct source call exists. | Very high | Vtable ints/xrefs; thunk disassembly. | Target/vtable/class/parent evidence. | incorporate | applied | Target `13795`, vtable `13804`, parent `13808`; UID0004EJ/EK remain false/blank at hashes `16491089...0B7D` and `D2B7EB9D...AE32`. |
| C07 | UID0004EM must become `92/94`, owner `0000AR`, false, blank emitter/position/formal, `Nested:0`. | Very high | Compiler-wrapper identity and exact source cause. | Target metadata/formal/summary/score. | incorporate | applied | Command `13795`, exit 0/ok 1; final target metadata and R1 verified. |
| C08 | Comment/covered-by/body emission is invalid; exact target no-code disposition is false/blank. | High | C++ gate, generated defect, scalar-wrapper comparator. | Target R1 and rejected alternatives. | reject-invalid | excluded-with-reason | R1 blank parity true; generated command `13813` has zero UID0004EM title/address/comment/marker output. |
| C09 | Target path/title/range remain exact; no rename/split/new UID; predecessor target has `Nested:0`, so relative target `Nested:0` remains exact. | Very high | Address ordering, current metadata, adjacent pages. | Target/parent/manual/checklist. | already-present | already-present | Exact path/range/title/Nested preserved in target and parent; no rename, split, or UID registration occurred. |
| C10 | Complete class1 object size is `0x128` with base `0x10c`, three ints, two bools, natural 2-byte alignment, two one-pointer strings, and callback pointer. | Very high | Size branch, constructor allocations/stores, paint/setter/destructor evidence. | UID0000AR layout/formal; target size proof; file/parent support. | incorporate | applied | Class command `13796`, constructor `13797`, target `13795`, file `13812`; R2/R3 parity true. |
| C11 | UID0000AR should become `92/93`, source position `10`, with exact R2 complete declaration closed before `[[CHILDREN]]`. | High | Layout/method/vtable closure and generated marker defect. | Class metadata/formal/status/layout/access/score. | incorporate | applied | Command `13796`, exit 0/ok 1; generated command `13813` shows one declaration closed before definitions and zero UID0000AR marker. |
| C12 | UID0004E3 should become `90/92` and use exact R3 with `RectBounds`, selected names, and inherited state/body assignments in observed order. | Very high | Constructor disasm, 30 calls, allocation size, base contract. | Constructor metadata/formal/prose; class/file support. | incorporate | applied | Command `13797`, exit 0/ok 1; R3 parity true and generated constructor count one. |
| C13 | UID0004E5 already has exact R4 `SetSelected`; preserve its formal/score and normalize any stale selected/pressed/hover prose to exact selected semantics. | Very high | 42 calls and paired old/new selection behavior. | Setter prose; class/file/parent support. | incorporate | applied | Command `13799`, exit 0/ok 1; score/formal retained, R4 parity true, selected prose normalized. |
| C14 | UID0004E8 should become `90/92` and use exact R7 with `m_visualStateFrameActive`, `m_selected`, and `m_selectedFrameId`; behavior remains unchanged. | Very high | Direct writer/reader/caller chain and paint disassembly. | OnPaint metadata/formal/field table/prose. | incorporate | applied | Command `13801`, exit 0/ok 1; R7 parity true and generated `OnPaint` count one. |
| C15 | UID0004E4 remains `88/91`, true/emitting, and exact R9 ordinary destructor body; it is the sole human destructor definition. | Very high | Raw body and current formal. | Destructor verify-only; target/class/file support. | already-present | already-present | UID0004E4 hash `87D5FC28...2C03`; R9 parity true; generated ordinary destructor count one. |
| C16 | UID0002UW should become `90/94`, retain owner/emitter `0000AR`, true, blank position, `Nested:4`, and use exact R10 compiler-generated marker without raw arrays. | High | Exact vtable bytes/slots/xrefs and complete class cause. | Vtable metadata/formal/summary/reconstruction/score. | incorporate | applied | Command `13804`, exit 0/ok 1; R10 parity true; generated marker count one and Empty Emitter Marker count zero. |
| C17 | UID0001F9 remains `88/90`, false/blank split index; update only class1 target/layout/source/compiler facts and preserve all children/pads/class2 content. | Very high | Complete current parent table and target reanalysis. | Parent Item Summary/inventory/evidence/history. | incorporate | applied | Command `13808`, exit 0/ok 1; parent metadata/formal unchanged and full class2/padding union retained. |
| C18 | UID0000MP should become `92/93`, retain file route, and record both complete class declarations, source order, exact children, and compiler exclusions. | High | Current file route, class1/class2 closure, generated state. | File metadata/inventory/source/generated policy/score. | incorporate | applied | Commands `13811` and final scoped repair `13812`, both exit 0/ok 1; final hash `8EF7840F...CE80`; waited `13813` verifies generated route. |
| C19 | UID0004E6/E7/E9, UID0004EJ/EK, UID0000AS, ControlPane, ButtonControlPane, Event, RectBounds, StringBase, and FunctionObject support are same-or-greater verify-only dependencies absent contradiction. | Very high | Current docs/formals plus live target-specific checks. | Cross-links and callback verify-only set. | already-present | already-present | R5/R6/R8 parity true; UID0000AS hash `96BA72D6...838A`; ButtonControlPane/ControlPane/Pane and FunctionObject0 readbacks retained, with no bounded contradiction. |
| C20 | Manual coverage rows are stale/absent for the changed target/class/constructor/paint/vtable/file/parent state; exact supervisor-owned handoff text is supplied, while B003 performs no coverage edit. | Very high | Current manual hashes/rows and proposed metadata. | Exact Manual Coverage section and checklist. | incorporate | applied | Four manual files reread at the exact evidence hashes below; handoff text preserved byte-for-byte in substance; B003 coverage edits zero. |

## Positive Evidence Summary

- Exact target bytes and function model agree on a 125-byte deleting wrapper.
- Exact binary SHA256 is independently computed from MCP target bytes.
- Three incoming routes are exactly the primary vtable and two adjustor thunks.
- Wrapper teardown matches the ordinary destructor's callback/string/base sequence.
- The bit-4 branch carries exact class size `0x128`, matching every observed class1 allocation and the complete field layout.
- Constructor, setters, paint, click, destructor, and vtable data converge on one coherent class declaration.
- Selection callers clear the old control and set the new control, proving selected-state semantics.
- Current accepted base classes expose the inherited state needed for legal source.
- Current class2 declaration is a close family comparator, while class1 fields/size/routes were independently checked.
- Generated output demonstrates the precise declaration/marker defects that R1/R2/R10 resolve.

## IDA MCP Facts

- Database: `64c11373`, NexusTK IDB, healthy at the evidence pass.
- Target:
  - start `0x0054bc40`
  - size `0x7d`
  - end `0x0054bcbd`
  - 39 instructions
  - 7 basic blocks
  - complexity 3
  - no strings
  - callers list empty at source-function level.
- Target SHA256: `A5038605020B355F8406805F041DC299171738E29A3D4DFF9F89E48A267E246F`.
- First 16 target bytes: `55 8b ec 56 8b f1 8b 8e 24 01 00 00 c7 06 d8 22`.
- Last 16 target bytes: `56 e8 ed f9 ec ff 83 c4 08 8b c6 5e 5d c2 04 00`.
- Target xrefs:
  - code `0x0054bba5` from thunk `0x0054bb9f`
  - code `0x0054bbb0` from thunk `0x0054bbaa`
  - data `0x006222d8` primary vtable.
- Vtable values:
  - `u32le 0x006222d8 = 0x0054bc40`
  - `u32le 0x00622340 = 0x0054bb9f`
  - `u32le 0x00622370 = 0x0054bbaa`.
- Vtable-store xrefs for each view are constructor, raw ordinary destructor, and deleting wrapper only.
- Secondary thunk: two instructions, subtract `0xa0`, jump target.
- Tertiary thunk: two instructions, subtract `0xa4`, jump target.
- Bit-4 helper: `0x0041b6a0`, size `1`, one instruction `retn`.
- Constructor:
  - `0x0054b5e0`, size `0xc4`
  - 59 instructions
  - 30 direct xrefs
  - three containing caller functions
  - two direct callees plus compiler EH/cookie paths
  - `retn 0x1c`.
- Selected setter:
  - `0x0054b700`, size `0x19`
  - 8 instructions
  - 42 code xrefs
  - direct store `+0x118`
  - tail dispatch through inherited slot `+0x20` with null rectangle.
- Paint:
  - `0x0054b7c0`, size `0xb9`
  - 61 instructions
  - first checks `+0x119` for frame `+0x110`
  - then checks `+0x118` for frame `+0x114`
  - otherwise frame `+0x10c`.
- Padding:
  - `0x0054bc3d-0x0054bc40`: three `0xcc` bytes, excluded from target and retained as parent-internal padding.
  - `0x0054bcbd-0x0054bcc0`: three `0xcc` bytes, excluded from target/parent and retained on `by-memory/-ignored.md`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0054b5e0-0x0054bcbd` | UID0001F9 | non-emitting split/index | false | address parent | `88/90` | retain; synchronize |
| `0x0054b5e0-0x0054b6a4` | UID0004E3 | class1 constructor | true | UID0000AR | `89/91 -> 90/92` | repair R3 |
| `0x0054b6b0-0x0054b6fb` | UID0004E4 | class1 ordinary destructor | true | UID0000AR | `88/91` | verify R9 |
| `0x0054b700-0x0054b719` | UID0004E5 | `SetSelected` | true | UID0000AR | `88/91` | verify R4; normalize prose |
| `0x0054b720-0x0054b744` | UID0004E6 | `SetCallback` | true | UID0000AR | `88/91` | verify R5 |
| `0x0054b750-0x0054b7b2` | UID0004E7 | `SetState` | true | UID0000AR | `88/91` | verify R6 |
| `0x0054b7c0-0x0054b879` | UID0004E8 | `OnPaint` | true | UID0000AR | `88/90 -> 90/92` | repair R7 |
| `0x0054b880-0x0054b8b9` | UID0004E9 | `OnClick` | true | UID0000AR | `87/90` | verify R8 |
| `0x0054b8c0-0x0054bb89` | class2 source children | class2 source | true | UID0000AS | accepted current | verify-only |
| `0x0054bb89-0x0054bb9f` | class2 thunks | compiler ABI | false | UID0000AS | accepted current | verify-only |
| `0x0054bb9f-0x0054bbaa` | UID0004EJ | class1 secondary thunk | false | UID0000AR | `86/90` | verify-only |
| `0x0054bbaa-0x0054bbb5` | UID0004EK | class1 tertiary thunk | false | UID0000AR | `86/90` | verify-only |
| `0x0054bbb5-0x0054bbc0` | parent-only padding | alignment | false | UID0001F9 | n/a | preserve |
| `0x0054bbc0-0x0054bc3d` | UID0004EL | class2 deleting wrapper | false | UID0000AS | `92/94` | verify-only comparator |
| `0x0054bc3d-0x0054bc40` | parent-only padding | alignment | false | UID0001F9 | n/a | preserve |
| `0x0054bc40-0x0054bcbd` | UID0004EM | class1 deleting wrapper | false recommended | UID0000AR | `86/90 -> 92/94` | target R1 |
| `0x006222d4-0x00622378` | UID0002UW | class1 RTTI/vtables | true generated-binary | UID0000AR | `88/93 -> 90/94` | R10 |
| class declaration | UID0000AR | class1 source declaration | true | UID0000MP | `89/91 -> 92/93` | R2, position 10 |
| source file | UID0000MP | class1/class2 source route | n/a | FILE | `90/92 -> 92/93` | synchronize |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x006222d8` | primary vtable -> UID0004EM | direct deleting entry |
| `0x00622340` | secondary vtable -> UID0004EJ -> UID0004EM | adjusted `this - 0xa0` deleting route |
| `0x00622370` | tertiary vtable -> UID0004EK -> UID0004EM | adjusted `this - 0xa4` deleting route |
| `0x0054bc6e` | callback virtual slot zero with flag 1 | compiler lowering of `delete m_callback` |
| `0x0054bc76` | `sub_582B70(+0x120)` | compiler cleanup of palette string |
| `0x0054bc81` | `sub_582B70(+0x11c)` | compiler cleanup of EPF string |
| `0x0054bc88` | `sub_544580(this)` | inherited Pane/control teardown |
| `0x0054bc99` | `sub_4F4AC0(this)` | global operator delete route |
| `0x0054bcae` | one-byte no-op helper with `this`/`0x128` | compiler bit-4 branch |
| 30 constructor callsites | `sub_52A540`, `sub_52C360`, `sub_52DD30` | reusable class construction, allocation size `0x128`, resource/frame triples |
| 42 selected-setter callsites | selection/update helpers | old control cleared, new control selected; proves selected semantics |
| `0x0062231c` | vtable -> UID0004E8 | class1 paint route |
| `0x00622320` | vtable -> UID0004E7 | class1 visual-state route |
| `0x00622374` | vtable -> UID0004E9 | adjusted-view click route |

## Documentation Evidence And IDA Status

- Historical pre-callback target state recorded the range and broad cleanup role but paired it with contradictory true/emitter/comment metadata. Current UID0004EM is false/blank at `92/94` with the complete compiler-only proof.
- UID0004E4 carries the exact sole human destructor definition and remains `88/91`, true/emitting, with byte-for-byte R9.
- UID0004E5 proves selected semantics, and current UID0004E8 now uses `m_visualStateFrameActive`, `m_selected`, and `m_selectedFrameId`; the historical hover aliases are explicitly superseded.
- UID0004E7 and the complete current class/paint declaration use the same `m_visualStateFrameActive` spelling.
- Historical UID0000AR lacked a class formal. Current UID0000AR is `92/93`, position `10`, and carries complete R2 before its seven routed definitions.
- Historical UID0002UW had a blank formal that caused marker-only output. Current UID0002UW is `90/94` with exact R10 generated-data marker and no Empty Emitter Marker.
- UID0000AS and the accepted base declarations demonstrate the exact source-safe declaration pattern, include completeness, class closure, source position, and compiler exclusions. They are comparator/support evidence, not a substitute for class1 revalidation.
- Evidence-time generated command `13791` is explicitly pre-callback state: class2 declaration is complete, class1 declaration is absent, seven class1 definitions are orphaned, and UID0004EM/UID0000AR/UID0002UW each generate one stale marker/comment symptom.
- Callback command `13813` produced the implemented result: one class1 declaration closed before its seven definitions, no UID0004EM output, no UID0000AR or UID0002UW Empty Emitter Marker, one UID0002UW generated-data marker, complete unchanged class2 source, and no raw ABI/vtable source.

## Ranked Ownership Analysis

### 1. UID0000AR PrettyButtonControlPane

- Evidence for:
  - all three vtables are PrettyButtonControlPane vtables;
  - constructor, ordinary destructor, deleting wrapper, and thunks use the same class views;
  - object size and fields close exactly;
  - UID0004E4 supplies the source destructor;
  - source file route already exists.
- Evidence against:
  - exact original private names and header split are not symbol-proven.
- Decision: retain as direct semantic owner and source declaration owner.

### 2. UID0000MP PrettyButtonControlPane source file

- Evidence for:
  - both class1/class2 methods and declarations belong to the same current source route;
  - executable cluster is contiguous;
  - generated output already uses this file.
- Evidence against:
  - exact original `.h` versus `.cpp` declaration split is inferred.
- Decision: retain as direct source-file owner; use current projected path.

### 3. UID0001F9 executable aggregate

- Evidence for:
  - contains the full address-ordered executable family and padding.
- Evidence against:
  - spans two classes, source methods, raw bodies, compiler thunks, wrappers, and padding; already false/blank.
- Decision: retain only as non-emitting split/index, never as source emitter.

### 4. Consumer dialogs / class2 / base classes / FunctionObjects

- Evidence for:
  - consumers construct and configure instances;
  - class2 and bases provide useful comparison;
  - FunctionObjects supplies callback type.
- Evidence against:
  - none owns the class1 wrapper or class1 source declaration.
- Decision: reject as direct owners.

### Proposed new file/grouping, if applicable

- Not applicable. No new file or grouping is needed.
- Current UID0000MP is the narrow source root for both Pretty button classes.

## Source Placement

- Recommended source module: `NexusTK/ui/controls/PrettyButtonControlPane.cpp`, routed by UID0000MP.
- Recommended declaration order:
  1. UID0000AR class1 at source position `10`.
  2. UID0000AS class2 at source position `20`.
- This order matches executable/class naming order and keeps each class closed before its routed child definitions.
- Required class1 dependencies:
  - complete `ButtonControlPane.h`
  - complete `FunctionObjects.h`
  - complete `StringBase.h`
  - forward-declared `RectBounds`.
- Event support remains transitive through ButtonControlPane and is not directly needed in UID0000AR.
- Rejected placements:
  - consumer dialog source files;
  - ButtonControlPane/ControlPane source;
  - FunctionObjects source;
  - a new class1-only file without evidence;
  - raw compiler/vtable source file.
- Remaining uncertainty is exact original header basename/split only; it does not block current projected source placement.

## Range / Split / Padding / Reclassification Analysis

- Exact target range remains `[0x0054bc40,0x0054bcbd)`.
- No byte belongs to a new child, merge, or rename.
- Predecessor:
  - UID0004EL ends at `0x0054bc3d`.
  - `0x0054bc3d-0x0054bc40` is three-byte parent-internal `0xcc` alignment.
- Successor:
  - target and UID0001F9 end at `0x0054bcbd`.
  - `0x0054bcbd-0x0054bcc0` is three-byte ignored alignment before UID0001FA.
- Relative nesting:
  - preceding address-sorted semantic child UID0004EL is `Nested:0`;
  - target remains at the same child level;
  - relative delta therefore remains `Nested:0`, not a child count.
- Reclassification is metadata/source-policy only: true/comment-emitting -> false/blank compiler output.
- UID0001F9 remains false/blank and retains every current child/padding row.

## Negative Evidence Summary

- No source callsite invokes UID0004EM as an ordinary method.
- No target-only behavior exists outside ordinary destructor sequencing and compiler deletion ABI.
- No evidence supports array/vector deletion; the bit-4 destination is a one-byte no-op.
- No evidence supports a user callback at the bit-4 destination.
- No evidence supports target body/comment emission.
- No evidence supports owner `NONE`; exact class source cause is known.
- No evidence supports class2 ownership.
- No selection caller uses hover enter/leave semantics.
- No class1 constructor evidence supports duplicate derived fields at `+0xff/+0x100`.
- No raw offset, vptr, RTTI-array, SEH, cookie, or delete-flag source is appropriate.
- No split, rename, new UID, or third-party import is required.
- Consumer callers prove use, not ownership.
- Address adjacency proves family context, not source ownership by the parent aggregate.

## IDA Rename / Type / Comment Recommendations

- No IDA mutation is requested or authorized.
- If a future supervisor-owned IDA naming pass is performed, the evidence supports:
  - `sub_54BC40` -> compiler scalar deleting destructor for `PrettyButtonControlPane`;
  - `sub_54B5E0` -> `PrettyButtonControlPane::PrettyButtonControlPane`;
  - `sub_54B700` -> `PrettyButtonControlPane::SetSelected`;
  - `sub_54B7C0` -> `PrettyButtonControlPane::OnPaint`;
  - `sub_54BB9F`/`sub_54BBAA` -> secondary/tertiary deleting-destructor adjustor thunks.
- Source-facing type/name recommendations:
  - `RectBounds`, not `Rect`;
  - `m_selected`, not `m_hoverFrameActive`;
  - `m_selectedFrameId`, not `m_hoverFrameId`;
  - `m_visualStateFrameActive`, not `m_state11VisualActive`;
  - inherited `m_controlFlags`/`m_reservedControlState`, not derived `m_constructorFlag`/`m_reservedState`.
- Exact original spelling remains inferred. Comments should distinguish direct binary fact from source-facing inference.

## First-Draft C++ Recommendation

All C++ below is destination-specific formal managed-block text. No target/example C++ exists outside these formal blocks.

### R0 - UID0001F9 parent formal destination

Verify and retain exact blank formal:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R1 - UID0004EM target formal destination

Eligible for draft C++: no.

Exact managed blank block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof:

1. The target accepts compiler deletion flags and returns complete `this`.
2. It duplicates the ordinary destructor's callback/member/base teardown.
3. It conditionally calls global operator delete.
4. It contains the compiler/runtime bit-4 no-op branch with object size `0x128`.
5. It is entered through deleting vtable/thunk routes.
6. Human source is fully represented by R2 plus R9.
7. Any target code/comment would duplicate source or expose ABI artifacts.

### R2 - UID0000AR class formal destination

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ButtonControlPane.h"
#include "FunctionObjects.h"
#include "StringBase.h"

struct RectBounds;

class PrettyButtonControlPane : public ButtonControlPane
{
public:
    PrettyButtonControlPane(const RectBounds &bounds,
                            const wchar_t *epfResourceName,
                            const wchar_t *paletteResourceName,
                            int normalFrameId,
                            int pressedFrameId,
                            int selectedFrameId,
                            unsigned char constructorFlag);
    virtual ~PrettyButtonControlPane();

    void SetSelected(bool selected);
    void SetCallback(FunctionObject0 *callback);

protected:
    virtual void SetState(unsigned char state);
    virtual int OnPaint();
    virtual bool OnClick(unsigned int action, int x, int y);

private:
    int m_normalFrameId;
    int m_pressedFrameId;
    int m_selectedFrameId;
    bool m_selected;
    bool m_visualStateFrameActive;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_epfResourceName;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_paletteResourceName;
    FunctionObject0 *m_callback;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R2 closes the exact `0x128` layout through natural alignment, supplies complete base/by-value/delete dependencies, declares all source methods, and closes the class before child definitions. It does not duplicate class2 or expose ABI facets.

### R3 - UID0004E3 constructor formal destination

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
PrettyButtonControlPane::PrettyButtonControlPane(const RectBounds &bounds,
                                                 const wchar_t *epfResourceName,
                                                 const wchar_t *paletteResourceName,
                                                 int normalFrameId,
                                                 int pressedFrameId,
                                                 int selectedFrameId,
                                                 unsigned char constructorFlag)
    : ButtonControlPane(bounds),
      m_normalFrameId(normalFrameId),
      m_pressedFrameId(pressedFrameId),
      m_selectedFrameId(selectedFrameId),
      m_selected(false),
      m_visualStateFrameActive(false),
      m_epfResourceName(epfResourceName),
      m_paletteResourceName(paletteResourceName)
{
    m_controlFlags = constructorFlag;
    m_callback = NULL;
    m_reservedControlState = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R3 preserves exact constructor field order and uses legal inherited protected state rather than duplicate derived members.

### R4 - UID0004E5 selected setter formal destination

Verify and retain exactly:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void PrettyButtonControlPane::SetSelected(bool selected)
{
    m_selected = selected;
    InvalidateRect(NULL);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R5 - UID0004E6 callback setter formal destination

Verify and retain exactly:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void PrettyButtonControlPane::SetCallback(FunctionObject0 *callback)
{
    delete m_callback;
    m_callback = callback;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R6 - UID0004E7 state method formal destination

Verify and retain exactly:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void PrettyButtonControlPane::SetState(unsigned char state)
{
    if (m_visualState != state)
    {
        if (state == 0x0b)
        {
            m_visualStateFrameActive = true;
            m_timerHandler.ScheduleTimer(0, 150, 0, 0);
        }
        else
        {
            m_visualStateFrameActive = false;
            m_timerHandler.RemovePendingTimers();
        }
    }

    ControlPane::SetVisualState(state);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R7 - UID0004E8 OnPaint formal destination

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int PrettyButtonControlPane::OnPaint()
{
    int frameId = m_normalFrameId;

    if (m_visualStateFrameActive) {
        frameId = m_pressedFrameId;
    } else if (m_selected) {
        frameId = m_selectedFrameId;
    }

    EPFTileContext tileContext;
    tileContext.Init();

    g_pEPFLib->LookupLayoutEntry(m_epfResourceName.c_str(), frameId, &tileContext);

    FrameDrawRecord drawRecord;
    int result = RenderTileFrame(&tileContext,
                                 &drawRecord,
                                 &m_bounds,
                                 1,
                                 m_paletteResourceName.c_str(),
                                 0);

    if (!m_enabled) {
        SetDrawColor(143);
        m_drawMode = 2;
        return g_surfaceRenderCallbacks->PreparePaneRegion(this, &m_bounds);
    }

    return result;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R7 changes only source-facing names. Branch order, frames, resources, rendering, disabled overlay color/mode/callback, and return behavior remain exact.

### R8 - UID0004E9 OnClick formal destination

Verify and retain exactly:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool PrettyButtonControlPane::OnClick(unsigned int actionId, int, int)
{
    if (actionId <= 1)
    {
        m_timerHandler.ScheduleTimer(1, 150, 0, 0);

        if (m_callback)
            m_callback->Invoke();
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R9 - UID0004E4 ordinary destructor formal destination

Verify and retain exactly:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
PrettyButtonControlPane::~PrettyButtonControlPane()
{
    delete m_callback;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R10 - UID0002UW vtable formal destination

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// PrettyButtonControlPane RTTI/vtable data is generated by the compiler from the class declaration and virtual method layout.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R10 is a generated-binary marker on a source-declared data page. It does not hand-author vtable or RTTI arrays.

## Final Recommendation

- C01-C20 and R0-R10 were applied or verified exactly in the accepted callback.
- Implemented target UID0004EM:
  - `86/90 -> 92/94`
  - owner remains `0000AR`
  - true -> false
  - emitter `0000AR` -> blank
  - blank position retained
  - `Nested:0` retained
  - exact path/range/title retained
  - exact R1 blank formal.
- Implemented UID0000AR:
  - `89/91 -> 92/93`
  - source position `10`
  - owner/emitter UID0000MP retained
  - exact R2.
- Implemented UID0004E3:
  - `89/91 -> 90/92`
  - exact R3
  - route/range/Nested retained.
- Implemented UID0004E8:
  - `88/90 -> 90/92`
  - exact R7
  - route/range/Nested retained.
- Implemented UID0002UW:
  - `88/93 -> 90/94`
  - owner/emitter UID0000AR retained
  - true, blank position, `Nested:4` retained
  - exact R10.
- Implemented UID0000MP:
  - `90/92 -> 92/93`
  - file route retained
  - synchronize complete class1/class2 source/compiler inventory.
- UID0001F9 remains `88/90`, false/blank, with all exact children and padding preserved.
- UID0004E4/E5/E6/E7/E9 and UID0004EJ/EK remain at accepted scores/routes/formals; only the accepted bounded terminology/current-state synchronization was applied.
- No new UID, page, rename, split, merge, import, IDA edit, manual coverage edit, or lifecycle action was performed by B003.

## Recommended Target Doc Changes

- Target: `by-memory/0x0054bc40-0x0054bcbd.PrettyButtonControlPaneScalarDeletingDestructor.md`.
- Implemented metadata/formal as specified by C07/R1.
- Implemented Item Summary with report-level exact facts:
  - compiler-only deleting wrapper;
  - size 125;
  - exact binary SHA256;
  - three vtable/thunk routes;
  - duplicated UID0004E4 teardown;
  - exact bit1/bit4 matrix;
  - `0x128` object size;
  - false/blank source disposition.
- Added exact range/bytes/hash/padding, ABI/CFG/instruction, behavior, teardown, xref, source/compiler, no-code, rejected-alternative, history, and score sections.
- Preserved historical target comment-emitter state as explicitly superseded provenance.
- Preserved exact owner, range, path/title, blank position, and `Nested:0`.

## Recommended Support Doc Changes

### `by-class/PrettyButtonControlPane.md` UID0000AR

- Applied `92/93`, position `10`, exact R2, exact `0x128` layout table, complete dependency/access/source/compiler evidence, method inventory, selected/state naming correction, wrapper/thunk/vtable dispositions, generated expectations, history, and score rationale.
- Preserved every unrelated current method/range/caller/resource/helper fact.

### `by-memory/0x0054b5e0-0x0054b6a4.PrettyButtonControlPaneConstructor.md` UID0004E3

- Applied `90/92` and exact R3.
- Historicalized stale `Rect`, `m_hoverFrameId`, `m_constructorFlag`, and `m_reservedState`.
- Added exact protected inherited access, source order, selected naming, object size, 30-call, and class-layout closure.

### `by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md` UID0004E5

- Retained score/metadata/R4.
- Normalized stale "selected/pressed/hover" ambiguity to exact selected-state semantics and cross-linked `m_selectedFrameId`.

### `by-memory/0x0054b7c0-0x0054b879.PrettyButtonControlPaneOnPaint.md` UID0004E8

- Applied `90/92` and exact R7.
- Replaced stale field table aliases with exact selected/state names.
- Preserved all helper/resource/disabled-overlay/range/vtable evidence.

### `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` UID0002UW

- Applied `90/94` and exact R10.
- Preserved exact range including `0x006222d4` locator caveat, three tables, slots, stores, RTTI/PMD/boundaries, and no-raw-array policy.
- Added exact false/blank UID0004EM disposition and complete R2 source cause.

### `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md` UID0001F9

- Preserved `88/90`, owner/emitter blank, false, blank formal, exact range, all children, and all padding.
- Updated only class1 layout/source names and UID0004EM compiler disposition.

### `by-file/PrettyButtonControlPane.md` UID0000MP

- Applied `92/93`.
- Preserved complete class2/B003 UID0004EL content and all concurrent historical evidence.
- Added class1 declaration at position 10, exact `0x128` layout, R3/R7 normalization, ordinary destructor/wrapper split, vtable marker, complete source/compiler inventory, and generated order/count/no-marker expectations.

### Verify-only destinations

- UID0004E4 R9 and metadata.
- UID0004E6 R5 and metadata.
- UID0004E7 R6 and metadata.
- UID0004E9 R8 and metadata.
- UID0004EJ/UID0004EK false/blank metadata/formals.
- UID0000AS class2 and all class2 children.
- UID000038, UID00001E, Pane, Event, RectBounds, StringBase, FunctionObject0, operator delete, timer/render helper support.
- Reread and verified unchanged; no exact contradiction required a broader edit.

## Score And Metadata Recommendation

| Destination | Historical pre-callback | Implemented | Rationale / cap |
| --- | --- | --- | --- |
| UID0004EM target | `86/90`, true/comment | `92/94`, false/blank | Exact bytes/hash/ABI/flags/xrefs/source cause/no-code proof close all target blockers. |
| UID0000AR class | `89/91`, blank class | `92/93`, position 10, R2 | Exact layout/declarations/dependencies/access/source split and generated route are complete. Exact original names/header split cap confidence. |
| UID0004E3 constructor | `89/91` | `90/92` | `RectBounds`, inherited access, selected naming, object size, and source order are closed. Parameter spellings remain inferred. |
| UID0004E8 paint | `88/90` | `90/92` | Direct writer/caller chain removes contradictory aliases; behavior/helper evidence was already strong. |
| UID0002UW vtable | `88/93` | `90/94` | Complete class cause and target disposition close source/compiler marker blocker. |
| UID0001F9 parent | `88/90` | unchanged | Exact split/index already complete; only bounded source-policy synchronization is needed. |
| UID0000MP file | `90/92` | `92/93` | Both class declarations/source families are complete and ordered; exact original file/header split caps confidence. |
| UID0004E4/E5/E6/E7/E9 | accepted current | unchanged | Existing bodies/routes are source-ready; only bounded cross-link/prose normalization is needed. |
| UID0004EJ/EK | `86/90` false/blank | unchanged | Exact two-instruction compiler roles are already complete enough. |

Score-improvement attempt:

1. Target range/hash blocker: closed with exact MCP bytes/hash/pads.
2. ABI/CFG blocker: closed with exact analyze/disasm facts.
3. Flag/free blocker: closed with exact branch matrix and helper disassembly.
4. Liveness blocker: closed with three exact vtable/thunk routes.
5. Source-destructor blocker: closed by UID0004E4 parity.
6. Object-size/layout blocker: closed at `0x128`.
7. Rectangle-type blocker: closed as `RectBounds`.
8. Inherited-access blocker: closed by accepted protected base state.
9. Selected/hover name blocker: closed by 42 selection calls and direct writer/reader chain.
10. String type blocker: closed by current pointer-sized `StringBase` contract.
11. Callback type/completeness blocker: closed by FunctionObject0 setter/destructor/click evidence.
12. Declaration/order blocker: closed by R2 position 10 and class closure before children.
13. Vtable marker blocker: closed by R10.
14. Generated wrapper/comment blocker: closed by R1 false/blank.
15. Exact original header/member/access spelling remains a bounded confidence cap, not an implementation blocker.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution / score impact |
| --- | --- | --- |
| Is UID0004EM source-authored? | Full body, flags, vtables, thunks, ordinary comparison. | No; compiler deleting wrapper. Closed. |
| Should it emit comment/body/covered-by/blank? | C++ gate, generated output, scalar comparator. | False/blank. Closed. |
| What does bit 4 mean here? | Branch, helper lookup/disasm, size immediate. | Direct compiler/runtime no-op branch with `0x128`; no free. Closed. |
| Is `0x128` object size? | Caller allocations, field layout, wrapper immediate. | Yes. Closed. |
| What is the source destructor? | UID0004E4 raw body and wrapper parity. | Virtual destructor with `delete m_callback;`. Closed. |
| Is `+0x118` hover or selected? | 42 callers, paired old/new updates, paint reader. | Selected. Closed. |
| What is frame `+0x114`? | Constructor triples, `+0x118` selected reader. | Selected frame. Closed. |
| What is `+0x119`? | UID0004E7 direct writes and paint priority. | Visual-state frame active. Closed. |
| Are `+0xff/+0x100` derived members? | Current base declarations and repeated direct writes. | No; inherited protected fields. Closed. |
| `Rect` or `RectBounds`? | Current base/family declaration evidence. | `RectBounds`. Closed for source. |
| What are the string types? | Constructor/dtor/paint and current type docs. | Pointer-sized wide `StringBase` instances. Closed enough. |
| What callback type/include is required? | Setter callers, click invoke, destructor delete. | Complete `FunctionObject0` via FunctionObjects include. Closed. |
| Is Event required directly? | Class method signatures and base declaration. | No direct Pretty dependency; transitive base support only. Closed. |
| Multiple source bases? | Source inheritance, three ABI views, thunks. | One `ButtonControlPane` base; adjusted views are compiler facets. Closed. |
| New file/split/rename? | Exact range and current source route. | No. Closed. |
| Can scores be higher? | All routes above. | No: exact original names/header/access labels remain inferred. |

No in-scope question remains unresolved. Remaining uncertainty is explicitly bounded source-spelling confidence only.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B003 did not edit manual coverage. The following are evidence-time read-only snapshots and exact proposed handoff text. Later coverage application, replacement, line movement, or lifecycle state is external and is not asserted.

| Manual file | Evidence-time SHA256 | Bytes | Lines | Relevant row state |
| --- | --- | ---: | ---: | --- |
| `by-memory/-coverage-report.md` | `97AF61EC2E16392FB8F0C6C378CB6FEF7F56AA25CEAFED34F84995F3216EE149` | 1,756,357 | 4,224 | UID0001F9 line 2806; UID0002UW line 3842; no UID0004E3/UID0004E8/UID0004EM rows. |
| `by-class/-coverage-report.md` | `2C9E9E28D60B6BC28CE81250C431005D3D88E4ECF42B7AF5AD6DDE68584E58ED` | 227,613 | 622 | UID0000AR line 409 stale at 76%. |
| `by-file/-coverage-report.md` | `ECB8A8CADC0D1083BA03B9091141E65690793057EE90157C3C0713AED2282EE7` | 130,782 | 316 | UID0000MP line 214 at 90%, explicitly capped by class1 debt. |
| `by-type/by-vtable/-coverage-report.md` | `BD8A622DCC9CEBD4A7358964BA2446E0A04D7D9B6C045733BAEA502A5EF46A60` | 65,969 | 142 | No separate affected UID0002UW row; UID0002UW is a by-memory page. |

### by-memory parent replacement

Replace the evidence-time UID0001F9 row at line 2806 with:

```markdown
    - [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md) 0x0054b5e0-0x0054bcbd | non-emitting split/index | PrettyButtonControls : not_reconstructable : 88% : very-strong : Exact address-ordered inventory for both PrettyButtonControlPane classes, source-authored constructors/destructors/setters/paint/click children, raw retained destructor bodies, four compiler adjustor thunks, two compiler deleting-destructor clones, and every internal 0xcc pad. UID0004EM is class1 compiler-only deleting output regenerated from the complete 0x128 PrettyButtonControlPane declaration and UID0004E4 ordinary destructor; UID0004EL remains the equivalent complete 0x12c class2 compiler output; the parent remains blank/non-emitting.
```

### by-memory class1 child insertions

Insert these rows immediately after the UID0001F9 parent in address order and before existing UID0004EA:

```markdown
        - [UID:0004E3][0x0054b5e0-0x0054b6a4.PrettyButtonControlPaneConstructor](by-memory/0x0054b5e0-0x0054b6a4.PrettyButtonControlPaneConstructor.md) 0x0054b5e0-0x0054b6a4 | constructor | PrettyButtonControlPaneConstructor : reconstructable : 90% : very-strong : Source-ready class1 constructor with exact seven-argument ABI, canonical RectBounds reference, three normal/pressed/selected frame ids, adjacent selected/frame-active booleans, two pointer-backed wide strings, protected inherited m_controlFlags/m_reservedControlState assignments in exact observed order, nullable FunctionObject0 callback initialization, three-view vtable stores, 30 callers, 0x128 allocation support, and exact padding.
        - [UID:0004E8][0x0054b7c0-0x0054b879.PrettyButtonControlPaneOnPaint](by-memory/0x0054b7c0-0x0054b879.PrettyButtonControlPaneOnPaint.md) 0x0054b7c0-0x0054b879 | virtual method | PrettyButtonControlPaneOnPaint : reconstructable : 90% : very-strong : Source-ready OnPaint selecting visual-state-active pressed, selected, or normal frame ids through normalized m_visualStateFrameActive/m_selected/m_selectedFrameId fields, resolving EPF/palette strings through EPFTileContext and RenderTileFrame, and preserving the disabled color-143 overlay, draw-mode 2 write, bounds callback, exact vtable route, and padding.
```

Insert this row immediately after existing UID0004EL and before the post-parent ignored padding row:

```markdown
        - [UID:0004EM][0x0054bc40-0x0054bcbd.PrettyButtonControlPaneScalarDeletingDestructor](by-memory/0x0054bc40-0x0054bcbd.PrettyButtonControlPaneScalarDeletingDestructor.md) 0x0054bc40-0x0054bcbd | compiler deleting-destructor clone | PrettyButtonControlPaneScalarDeletingDestructor : not_reconstructable : 92% : very-strong : Exact 125-byte MSVC deleting entry reached by the primary vtable plus +0xa0/+0xa4 adjustor thunks; duplicates UID0004E4 teardown, returns complete this, frees only when flag bit 1 is set and bit 4 is clear, and uses the 0x128 bit-4 no-op branch. Source is the virtual class destructor and UID0004E4 body; target emitter/formal remain blank.
```

### by-memory vtable replacement

Replace the evidence-time UID0002UW row at line 3842 with:

```markdown
        - [UID:0002UW][0x006222d4-0x00622378.PrettyButtonControlPaneVtableData](by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md) 0x006222d8-0x00622378 | vtable-data | PrettyButtonControlPaneVtableData : reconstructable : 90% : very-strong : Exact primary/secondary/tertiary PrettyButtonControlPane RTTI/vtable data with complete slot/store/boundary evidence, generated-binary marker, source cause in the complete 0x128 class declaration, UID0004E4 ordinary destructor, and false/blank UID0004EM compiler deleting clone; no raw arrays are emitted.
```

### by-class replacement

Replace the evidence-time UID0000AR row at line 409 with:

```markdown
- [UID:0000AR][PrettyButtonControlPane](by-class/PrettyButtonControlPane.md) : reconstructable : 92% : very-strong : Complete 0x128 ButtonControlPane-derived styled-button declaration with canonical RectBounds constructor, complete ButtonControlPane/StringBase/FunctionObject0 dependencies, public virtual destructor/setters, protected SetState/OnPaint/OnClick overrides, exact three-frame/two-bool/two-StringBase/callback tail layout, protected inherited control-state access, natural alignment, selected-state naming backed by 42 caller xrefs, complete child emission at source position 10, ordinary-destructor source, and compiler-only vtable/thunk/deleting-wrapper exclusions.
```

### by-file replacement

Replace the evidence-time UID0000MP row at line 214 with:

```markdown
- [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md) : reconstructable : 92% : very-strong : Styled-button source module under `NexusTK/ui/controls/` with complete source-ordered PrettyButtonControlPane and PrettyButtonControlPane2 declarations, canonical RectBounds constructors, protected inherited control-state assignments, complete StringBase/FunctionObject0 dependencies, exact constructor/destructor/setter/state/paint/click children, generated RTTI/vtables, compiler adjustor/deleting-wrapper exclusions, exact executable/read-only split inventories, class closure before all qualified definitions, and zero class/deleting-wrapper Empty Emitter Marker symptoms. Exact original header/member spellings remain bounded confidence caps.
```

Reason B003 must not apply these rows: all manual `-coverage-report.md` files are supervisor-owned and outside the accepted callback write scope.

## Follow-Up Actions

- The accepted implementation callback and every scoped/generated verification item below are complete.
- B003 supplied the exact supervisor-owned manual coverage handoff but did not edit coverage or any generated/tracker/audit/supervisor/validator-state/IDA/lifecycle file.
- Gate 2, coverage application, execution/revalidation/invalidation, count, path, movement, archive, and lifecycle state remain external validator/supervisor-owned facts and are neither asserted nor directed by this artifact.
- No B003 implementation item or separate B-agent research target remains inside this callback scope.

## Confidence

- Recommendation confidence: very strong.
- Target score confidence: very high.
- Class/file score confidence: high.
- Exact original source-name/header/access confidence: strong but inferred.
- Remaining uncertainty:
  - exact original header split/basenames;
  - exact original private member spelling;
  - exact original names for the constructor's final byte parameter and click parameters;
  - exact compiler version that emitted the deleting-wrapper flag ABI.
- None of these uncertainties changes range, ownership, false/blank target disposition, object size/layout, source method bodies, formal declaration safety, source placement, or implemented scores.

## Validator Results

All commands ran from `source-3/project-documentation`. Every scoped command exited `0` with `ok:1`; each ordinary lease was released immediately after its destination validator.

| Destination / purpose | Command ID | Command timestamp | Local interval | Exit / ok | Warnings and side effects |
| --- | --- | --- | --- | --- | --- |
| UID0004EM target | `000000013795` | `2026-07-16T11:10:05-04:00` | `11:10:04.9877164` to `11:10:06.9295705` | `0 / 1` | Applied `92/94`, true-to-false, emitter clear, formal blank, eight reference-index additions, projected stats; generated refresh deferred. |
| UID0000AR class | `000000013796` | `2026-07-16T11:11:42-04:00` | `11:11:41.8665119` to `11:11:43.8200357` | `0 / 1` | Applied `92/93`, position `10`, exact R2, seven UID links and two references, projected stats; generated refresh deferred. |
| UID0004E3 constructor | `000000013797` | `2026-07-16T11:12:37-04:00` | `11:12:37.8030645` to `11:12:40.0043169` | `0 / 1` | Applied `90/92`, exact R3, two references, projected stats; generated refresh deferred. |
| UID0004E5 selected setter | `000000013799` | `2026-07-16T11:13:14-04:00` | `11:13:13.9174622` to `11:13:21.3992440` | `0 / 1` | Metadata/formal retained; bounded prose normalization and projected stats; generated refresh deferred. |
| UID0004E8 OnPaint | `000000013801` | `2026-07-16T11:14:08-04:00` | `11:14:08.5125495` to `11:14:12.7480954` | `0 / 1` | Applied `90/92`, exact R7, projected stats; generated refresh deferred. |
| UID0002UW vtable data | `000000013804` | `2026-07-16T11:15:11-04:00` | `11:15:11.8296437` to `11:15:19.8137711` | `0 / 1` | Applied `90/94`, exact R10, projected stats; generated refresh deferred. |
| UID0001F9 parent split/index | `000000013808` | `2026-07-16T11:17:42-04:00` | `11:17:41.8786191` to `11:17:43.8315752` | `0 / 1` | Metadata/formal unchanged; complete class1 union added; projected stats; generated refresh deferred. |
| UID0000MP file initial complete union | `000000013811` | `2026-07-16T11:20:10-04:00` | `11:20:10.2749627` to `11:20:12.2181957` | `0 / 1` | Applied `92/93`, projected stats; generated refresh deferred. |
| UID0000MP bounded historicalization repair | `000000013812` | `2026-07-16T11:20:57-04:00` | `11:20:57.2689683` to `11:20:59.2282355` | `0 / 1` | Metadata unchanged; superseded constructor aliases made explicitly historical; projected stats; generated refresh deferred. |
| Final waited UID0000MP refresh | `000000013813` | `2026-07-16T11:21:05-04:00` | `11:21:05.4766968` to `11:21:26.5093339` | `0 / 1` | Generated refresh completed; validator-owned registry rebuild and 280 generated metadata refreshes. Unrelated global warnings: 15 fallback child insertions, 84 missing preferred child markers, and 149 emitter-has-no-code rows; no PrettyButton target error. |

Generated `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` at historical B003 callback command `13813`:

- SHA256 `5F5F1D97E7C1F1857C8FA3F2EBCEBC8218D1E8F56B618374F41C44659D43D514`, 10,668 bytes, 303 lines.
- Class1 declaration count one; class2 declaration count one.
- Each class closes before its first qualified definition.
- Class1 constructor, destructor, `SetSelected`, `SetCallback`, `SetState`, `OnPaint`, and `OnClick` counts are one each.
- Class2 constructor, destructor, `SetSelected`, `SetCallback`, `SetState`, `OnPaint`, and `OnClick` counts are one each.
- UID0004EM UID/title/address/comment count zero; all Empty Emitter Marker count zero.
- UID0002UW and UID0002UX compiler-generated marker counts are one each.
- `RTTICompleteObjectLocator`, `vftable`, `__declspec(naked)`, `sub_`, `__vfptr`, `security_cookie`, `_guard_check`, scalar-deleting text, and deleting-flag identifiers count zero.

Current read-only validator-owned header command `13820` has SHA256 `FA314493928A796826D44A439F3EACBBFC3146EFF4D13384A9059216FCCC9970`, 10,668 bytes, and 303 lines. Reconstructing only the prior command/timestamp header yields exact callback SHA `5F5F1D97...3D514`; all semantic counts and exclusions were reread unchanged.

Formal parity:

| Formal | LF-normalized destination block SHA256 | Exact report parity |
| --- | --- | --- |
| R0 | `CA40B93B6569C6F5127EE922903894943A86E38CB071968DB2A2260DC2E3F396` | true |
| R1 | `CA40B93B6569C6F5127EE922903894943A86E38CB071968DB2A2260DC2E3F396` | true |
| R2 | `9FAB10167F7BFE542FB78C15A034E105ED58399ABCCC79D8647336CEBEA48DD4` | true |
| R3 | `B70382FCAC8036485CA96FB6F87291A1CD67E39A38A18EAA740BBA004CB0DE9A` | true |
| R4 | `F97BEC14945DADC25B60F2D2AFE65A08C0B9E1BB39DCBA2D61634724FE779C16` | true |
| R5 | `88D723C0C4EFAAB83B9F633E0FDBBC44DAA8D5BD51CFE33DFB55C563003BCC3C` | true |
| R6 | `96BC476D4007F181D85A07EF444A884373440944C1C5BA0690C96B0C0EC02768` | true |
| R7 | `8D04C2AC585DBA73D490673D30C7235421C96107B8CA7EE8B7DB05EA78D03512` | true |
| R8 | `61A39299E6EC3BBDE808ABBE419ECF9A906522B7C982B30EC2DDF568B827F490` | true |
| R9 | `A6CA95569183FA948CE40F711ADA10C5B8C550D6445108069396764B2A8F0EEB` | true |
| R10 | `6CE6EFA8AC614549CCC433B732F406769B7E18BBF6AC4B7C74A92BE6AC5CB6CF` | true |

MCP evidence remains the healthy evidence-time database `64c11373`; the callback made no IDA call or mutation. B003 ran no report execution/probe/count/revalidation/lifecycle command.

## Changed Files

- Modified ordinary destinations:

| Path | SHA256 | Bytes | Lines |
| --- | --- | ---: | ---: |
| `by-memory/0x0054bc40-0x0054bcbd.PrettyButtonControlPaneScalarDeletingDestructor.md` | `53726568A669290E4EC0A47EB40FC70CB7368B20C102DA9A11DFBF8EC52C9426` | 10,893 | 134 |
| `by-class/PrettyButtonControlPane.md` | `93605A05F618A014EA3EA124B9BA9BF27CC272F87F63D4BBF5EAC844A4BDB0BD` | 19,301 | 208 |
| `by-memory/0x0054b5e0-0x0054b6a4.PrettyButtonControlPaneConstructor.md` | `1360293AC1EED01F569110FCA021E774D81AD9391AB4DE14DD9A7DDA244AB183` | 10,281 | 93 |
| `by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md` | `93F720C27F3EC1BECB6827D4B419FE855C59B7008BD7F291C2058986C6985ACB` | 5,938 | 48 |
| `by-memory/0x0054b7c0-0x0054b879.PrettyButtonControlPaneOnPaint.md` | `E0E152D91ECED46F83A04972B9AE0C2666E4C0EF12AAE08610E5B1BDB28B7A76` | 7,993 | 99 |
| `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` | `B17EF8B2D147232513FF01F4EDA9B07DB68165542D30E6AB9A48E5A0770F5034` | 21,363 | 141 |
| `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md` | `013B1CD6BD47E1065CA30CB387D9054BBB6DA7E5085F380D0DAAD8BC689D9886` | 44,486 | 205 |
| `by-file/PrettyButtonControlPane.md` | `8EF7840F1ECFA61D40B19922269380C4F4E4F8D74C732819CFBD14C20E17CE80` | 53,085 | 220 |

- Verify-only class1 hashes: UID0004E4 `87D5FC28...2C03`, UID0004E6 `918AC728...57F0`, UID0004E7 `7CE46148...D9EC`, UID0004E9 `74CCE7AA...F839`, UID0004EJ `16491089...0B7D`, UID0004EK `D2B7EB9D...AE32`.
- Verify-only class2 hashes: UID0000AS `96BA72D6...838A`; UID0004EA `D06B6738...5229`; UID0004EB `4D1FCD01...8CF1`; UID0004EC `8FFD50FA...4A5C`; UID0004ED `E9052201...560B`; UID0004EE `1EDA18A0...04A5`; UID0004EF `606CCD7F...D37D`; UID0004EG `107A2620...D71A`; UID0004EH `E089581E...2433`; UID0004EI `89B29229...CFBC`; UID0004EL `62A85D1D...908C`; UID0002UX `38B830EF...3F85`.
- Verify-only dependency hashes: ButtonControlPane class `614158C9...3C8E`; ControlPane class `3F2C4D1A...508B`; Pane class `B9686C65...AC10`; Event class `D18D26AB...F95B`; RectBounds class `71005750...370E`; StringBase template `41970454...F45C`; FunctionObject0 class `971335C6...1A60`; EPFTileContext class `7EC740D8...7F28`.
- Modified report: `tools/leaser/Agents/Agent-B003/research/0004EM-PrettyButtonControlPaneScalarDeletingDestructor-source-quality.md`.
- Renamed/new ordinary files: none.
- Manual coverage files were reread at the exact hashes in the handoff section and were not edited.
- Generated output changed through authorized B003 validator command `13813`; B003 did not manually edit it. A later external validator-owned header refresh at command `13820` preserved the exact source body and all assertions.
- Tracker/audit/supervisor/validator-state/IDA/lifecycle/archive files manually changed by B003: none.
- Lease discipline: one ordinary file at a time; every lease released after its validator; final current lease read shows zero B003 leases.
- Report execution/lifecycle: B003 performed none.

## Implementation Tracking Checklist

Report-only pass and completed callback obligations:

- [x] Supervisor validation is recorded for the exact report artifact before implementation.
- [x] Re-read target and every editable/verify-only destination immediately before any callback edit.
- [x] Re-read current leases and use one short ordinary-file lease at a time.
- [x] Apply C01-C20 claim by claim and update each row to a legal terminal callback state with destination proof.
- [x] Apply R0-R10 exactly or verify the destination already has byte-for-byte same-or-greater formal content.
- [x] Update UID0004EM to `92/94`, owner `0000AR`, false, blank emitter/position/formal, `Nested:0`, exact Item Summary, and full report evidence.
- [x] Preserve UID0004EM exact UID/path/title/range and both adjacent padding dispositions.
- [x] Update UID0000AR to `92/93`, position `10`, exact R2, exact `0x128` layout, complete dependencies/access/source/compiler evidence, and class close before `[[CHILDREN]]`.
- [x] Update UID0004E3 to `90/92`, exact R3, selected-state terminology, `RectBounds`, and inherited protected state assignments.
- [x] Verify UID0004E4 remains `88/91`, true/emitting, and exact R9 ordinary destructor source.
- [x] Verify UID0004E5 remains `88/91` and exact R4 while normalizing bounded selected-state prose.
- [x] Verify UID0004E6 remains `88/91` and exact R5.
- [x] Verify UID0004E7 remains `88/91` and exact R6.
- [x] Update UID0004E8 to `90/92`, exact R7, and exact selected/state field table/prose.
- [x] Verify UID0004E9 remains `87/90` and exact R8.
- [x] Verify UID0004EJ/UID0004EK remain false/blank with exact `-0xa0/-0xa4` thunk facts.
- [x] Update UID0002UW to `90/94`, exact R10, complete three-table/source-cause/no-raw-array evidence, and preserve `Nested:4`.
- [x] Preserve UID0001F9 at `88/90`, false/blank, with every child/range/pad/class2 fact intact and add only the accepted class1 union.
- [x] Update UID0000MP to `92/93` with complete class1/class2 declaration order, inventory, generated route, and compiler exclusions.
- [x] Verify UID0000AS and all class2 children remain unchanged at same-or-greater accepted detail.
- [x] Verify ControlPane/ButtonControlPane/Pane/Event/RectBounds/StringBase/FunctionObject0/operator-delete/timer/render dependencies remain unchanged absent exact contradiction.
- [x] Preserve all positive/negative evidence, caller/callee facts, exact ranges/hashes/padding, rejected alternatives, source placement, history, and score rationale without compression.
- [x] Preserve Wave2/Wave3/simroot material only as explicitly superseded provenance.
- [x] Confirm third-party import handling is not applicable and no `third_party_embeds/...` directive is added.
- [x] Run one scoped validator per actually changed ordinary by-* page and record command, command_id, timestamp, exit, ok, warnings, and side effects.
- [x] Release each ordinary lease immediately after its edit/scoped validator and before acquiring another.
- [x] Run one authorized final waited validation for `by-file/PrettyButtonControlPane.md`.
- [x] Verify generated class1 declaration appears before its seven definitions and closes before `[[CHILDREN]]` expansion.
- [x] Verify class1 constructor, destructor, SetSelected, SetCallback, SetState, OnPaint, and OnClick each appear exactly once.
- [x] Verify UID0004EM title/address/comment and Empty Emitter Marker counts are zero.
- [x] Verify UID0000AR Empty Emitter Marker count is zero.
- [x] Verify UID0002UW R10 marker occurs exactly once and its Empty Emitter Marker count is zero.
- [x] Verify class2 declaration/definitions and UID0004EL disposition remain unchanged and unique.
- [x] Verify generated output contains no duplicate/wrong-range class1 body and no handwritten vtable/RTTI/delete-flag/vptr/SEH/cookie/decompiler source.
- [x] Re-read current manual coverage rows and preserve/provide exact no-loss supervisor-owned text without B003 editing coverage.
- [x] Update `Finalized Report / Current Recommendation`, `Current Target State`, ledger, recommendations, Validator Results, Changed Files, Follow-Up Actions, and checklist to callback-time durable truth.
- [x] Record every changed path/hash/bytes/lines and every verify-only path/hash.
- [x] Confirm zero B003 leases remain.
- [x] Confirm B003 performed no manual coverage/generated/tracker/audit/supervisor/validator-state/IDA edit.
- [x] Confirm B003 performed no `execute_report`, report probe/count/revalidation, lifecycle, move, archive, or delete command.

Implementation callback pass:

- [x] Exact report artifact is accepted by the supervisor for implementation.
- [x] All accepted target/support details are incorporated at report-level factual depth.
- [x] C01-C20 have legal terminal callback actions/states and exact destination/validator/generated proof.
- [x] R0-R10 destination parity is verified.
- [x] Metadata/score/owner/emitter/position/reconstructable/C++ changes are applied or explicitly excluded with reason.
- [x] Historical/stale assumptions, rejected alternatives, negative evidence, and concurrent unrelated content are preserved.
- [x] Open questions remain closed or are retained only as evidence-backed score caps.
- [x] Scoped validators and waited generated proof are complete and recorded.
- [x] Exact supervisor-owned manual coverage handoff remains present without a B003 coverage edit or assertion about later application.
- [x] No accepted implementation item remains blocked.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000013843","destination_path":"executed-b-agent-research/B003/0004EM-PrettyButtonControlPaneScalarDeletingDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0004EM-PrettyButtonControlPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-07-16T11:42:20-04:00","uid":"0004EM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
