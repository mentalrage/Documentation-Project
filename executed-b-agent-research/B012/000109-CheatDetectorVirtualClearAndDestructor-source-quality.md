** TARGET-REPORT-UID:000109 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000109 CheatDetector Virtual Clear And Destructor Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:000109] owned by [UID:000020] `CheatDetector`, emitted through the class route into [UID:0000I6] `security/CheatDetector.cpp`.
- Final disposition: source-quality questions are resolved enough to raise the row from `84/90` to `86/90`; keep `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:000020`, and `EMITTER_UIDS:000020`.
- Required action: update the target/support text and coverage row wording. Do not edit `by-memory/-coverage-report.md` directly from this B pass.
- First-draft C++ decision: do not populate the formal `RECONSTRUCTION_CPP CODE` block for this combined range now. The range is a compact mix of one real virtual callback body, one constructor-unwind singleton cleanup helper, and one MSVC scalar deleting destructor. The correct final source should declare/define the class callback and ordinary destructor at the class/source level and let the compiler regenerate the cleanup/deleting wrapper, not hand-write a decompiler-shaped deleting-destructor thunk in this by-memory page.
- Confidence: strong for behavior, ownership, base teardown identity, vtable signature, singleton-clear role, and route; medium-high for exact original method spelling because no current live MCP was available and the final `TimerHandler` header/source split is still provisional.

## Supporting Research

## Target

- Target UID: `000109`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md`
- Source queue/report row: `project-level/-auto-completion-stats.md`, reconstructable low-score by-memory row, current `84/90`, average `87.0`.
- Current owner/emitter state: `CANONICAL_OWNER:000020`, `EMITTER_UIDS:000020`, route through [UID:000020] `CheatDetector` -> [UID:0000I6] `CheatDetector` -> `auto-generated/NexusTK/security/CheatDetector.cpp`.
- Current generated output: `auto-generated/NexusTK/security/CheatDetector.cpp` contains an empty emitter marker for [UID:000109].

## Executive Recommendation

Best direct owner remains `CheatDetector`:
- The `0x00483fe0` vtable slot is the `CheatDetector` override of the `TimerHandler` callback-shaped virtual slot.
- The `0x00483ff0` helper clears `g_pCheatDetector` only and is reached from constructor unwind/cleanup metadata.
- The `0x00484000` body is the `CheatDetector` scalar deleting destructor wrapper; its base call is the confirmed `TimerHandler_dtor` at `0x00597580`, not `EventDispatcher`, `boost::exception`, or another parent.

No split is recommended for this assignment. The range is internally multi-function, but every source-bearing semantic belongs to the same `CheatDetector` class/file route, and the padding subranges are already represented in `by-memory/-ignored.md` / coverage rows. Splitting would create tiny compiler-support children without improving ownership or source placement.

Recommended source-facing names:
- `0x00483fe0`: `CheatDetector::OnTimer` or `CheatDetector::OnTimerEvent`; best source-facing name is `CheatDetector::OnTimer`.
- `0x00483ff0`: `ClearCheatDetectorSingleton`; no-argument constructor-unwind cleanup helper, not an instance method.
- `0x00484000`: binary-level `CheatDetectorScalarDeletingDestructor`; source-facing semantic is `CheatDetector::~CheatDetector`, but the exact function is the MSVC deleting-destructor wrapper and should not be hand-written as ordinary application logic.

## Supervisor Active Recheck

The supervisor assignment asks for source-quality and heuristic/inference resolution for [UID:000109], specifically:
- source-facing names for the three subfunctions;
- vtable slot semantics/signature for `0x00483fe0`;
- singleton-clear helper role and relation to `g_pCheatDetector`;
- scalar deleting destructor versus ordinary destructor/source-shape decision;
- base teardown identity for `0x00597580`;
- owner/emitter routing;
- first-draft C++ population decision;
- exact coverage replacement row text if needed.

This is a report-only B-agent pass. The target does not require split repair before reporting. No `by-*`, coverage, generated, or project-level files were edited.

## Inference Research Guidance Check

Facts and evidence types are separated below:
- IDA fact recorded in existing docs: target page and related pages contain live IDA function sizes, xrefs, callees, byte padding, vtable entries, and constructor/destructor behavior from earlier live sessions.
- Local read-only export fact: exported function records for `0x00483fe0`, `0x00483ff0`, `0x00484000`, `0x00483f00`, `0x00597580`, and `0x005975d0` preserve decompile/signature conflicts and xref data.
- Documentation evidence: `CheatDetector`, `CheatDetector.cpp`, `g_pCheatDetector`, `CheatDetectorVtable`, `TimerHandler`, `TimerHandlerDestructor`, and `TimerMgr` pages record current ownership, route, and base-class evidence.
- Inference: final source-facing names and source-shape recommendations are inferred from vtable layout, callback dispatch layout, constructor/destructor patterns, singleton xrefs, and TimerHandler wrapper docs.

IDA MCP caveat: current-session MCP at `http://127.0.0.1:13337/mcp` was unavailable (`Unable to connect to the remote server`). This report therefore relies on existing project documentation with recorded live IDA evidence plus local read-only exported function records. Because multiple 2026-06-16 support pages already record live IDA refreshes for the same base/global/vtable facts, confidence remains strong but not final-audit.

## Heuristic / Inference Reanalysis And Validation

### Compiler / Generated Names

Best direction:
- Replace `sub_483FE0` with `CheatDetector::OnTimer` in source-facing text.
- Replace `sub_483FF0` with `ClearCheatDetectorSingleton`.
- Replace `sub_484000` with `CheatDetectorScalarDeletingDestructor` for the binary wrapper and `CheatDetector::~CheatDetector` for the source-level semantic.

Evidence checked:
- `0x00615564` points to `0x00484000`; `0x00615568` points to `0x00483fe0`; both are in the exact `CheatDetector` vtable child.
- `0x00483ff0` has no callees and only clears `g_pCheatDetector`.
- `project-level/-unresolved.md` still sees generated names mostly because coverage and vtable evidence text quotes old IDA labels. That is generated-name pollution, not a behavior or ownership blocker.

Rejected alternatives:
- `virtual check slot`: descriptive but too vague; it hides the TimerHandler callback role.
- `IsEnabled`, `IsValid`, or `CheckCheat`: rejected because no call site or branch proves an anti-cheat check semantic. The body is a timer callback-shaped true return.
- `FUN_00483ff0` / `sub_483FF0`: rejected as raw generated labels.
- Writing `CheatDetector::ScalarDeletingDestructor` as a source method: rejected as compiler wrapper shape, not ordinary C++ source.

Score impact:
- Completion can rise because generated names and source-facing roles are now resolved.
- Confidence should stay below final-audit because exact original identifier spelling is inferred, not symbol-proven.

### Vtable Slot Semantics And Signature At 0x00483fe0

Best inference:
- `0x00483fe0` is `bool CheatDetector::OnTimer(int eventId, int arg0, int arg1)`.
- It is a `__thiscall` virtual method in source; the machine body does not use `ecx`, sets `al = 1`, and returns with `ret 0x0c`, consuming three explicit stack arguments.

Evidence checked:
- The `CheatDetector` vtable has two slots: scalar deleting destructor at `+0x00`, true-return slot at `+0x04`.
- `TimerMgr::DispatchDueTimers` documentation dispatches scheduled records through owner virtual slot `+4`.
- [UID:0001VX] `ScheduledTimerEvent` records the five-field scheduled timer event: owner, event id, due tick, `arg0`, `arg1`.
- `TimerHandler` support pages record the generic wrapper signature: schedule wrapper forwards owner, event id, delay/due tick, and two payload fields.
- The nearby `TimerHandler` callback-shaped helper at `0x005975d0` has the same return shape (`b0 01 c2 0c 00`) but no current xrefs; the actual base vtable callback slot is documented as `__purecall`. This strengthens the inference that concrete owners supply `OnTimer` overrides with three explicit arguments.

Rejected alternatives:
- `char __stdcall(int,int,int)` as the final source signature: rejected because the vtable entry belongs to a class object and should be modeled as `__thiscall` with an unused `this`.
- Zero-argument `CheatDetector::IsActive()`: rejected by `ret 0x0c` and TimerHandler dispatch context.
- A pure anti-cheat validation method: rejected because no caller passes cheat-detection context; the slot matches generic timer dispatch.

Remaining caveat:
- Final argument names are descriptive. `eventId`, `arg0`, and `arg1` are the strongest currently supported names; their exact original names are not recovered.

### Singleton-Clear Helper At 0x00483ff0

Best direction:
- `0x00483ff0` is `ClearCheatDetectorSingleton`, a no-argument cleanup helper that sets `g_pCheatDetector = 0`.
- Source-level role: constructor-unwind cleanup for the constructor's early singleton publish, plus a conceptual companion to destructor singleton clearing.

Evidence checked:
- Target page records function size `0x0b`, no callees, and xref from constructor cleanup metadata at `0x005fc446`.
- Local export decompile is only `dword_67AB3C = 0`.
- `g_pCheatDetector` docs record the five expected direct refs: startup cleanup reader, constructor publish/null writes, this clear helper, and scalar deleting destructor clear.
- Constructor export for `0x00483f00` stores `this` into `g_pCheatDetector` before calling `TimerHandler::TimerHandler`; if later construction fails, the unwind helper clears that early publication.

Rejected alternatives:
- Ordinary `CheatDetector` instance method: rejected because there is no `this`, no vtable/data ref, and no instance access.
- Application cleanup helper: rejected because application cleanup reads the global and dispatches the deleting destructor; it does not directly call this helper.
- Standalone global owner: rejected because all refs belong to the `CheatDetector` lifecycle.

Score impact:
- This is resolved enough for the support page and coverage row. It still argues against formal C++ population because it is an EH cleanup target, not a handwritten public helper.

### Scalar Deleting Destructor Versus Ordinary Destructor At 0x00484000

Best direction:
- Binary-level name: `CheatDetectorScalarDeletingDestructor`.
- Source semantic: `CheatDetector::~CheatDetector`, with `TimerHandler` base teardown and `g_pCheatDetector` clearing.
- Formal C++ for this by-memory page should stay blank now because the exact body is compiler deleting-destructor glue with a delete-flags argument and optional free.

Evidence checked:
- `0x00484000` is vtable slot `+0x00` in the `CheatDetector` vtable.
- Local export and target docs show signature pollution but stable behavior: call `0x00597580`, clear `g_pCheatDetector`, and call `0x005c7526` when delete flag bit `1` is set.
- The function returns the receiver and consumes the delete-flags argument with `ret 4`, matching MSVC scalar deleting destructor shape.
- `0x005c7526` is an optional delete/free helper, not class logic.
- Similar project pages, such as `TerminalPaneScalarDeletingDestructor`, explicitly keep formal C++ blank when the exact range is a compiler deleting wrapper.

Rejected alternatives:
- Treating this as an ordinary handwritten destructor body: rejected by the delete flag, optional free, vtable slot placement, and `ret 4`.
- Emitting a function named `CheatDetector::ScalarDeletingDestructor(unsigned int flags)`: rejected because that is decompiler-shaped compiler support, not plausible mid-2000s application source.
- Emitting only `CheatDetector::~CheatDetector() { g_pCheatDetector = 0; }` in this exact by-memory page: rejected because it does not cover the observed wrapper's base-call/delete-flag shape and risks misrepresenting the observed order.

Remaining caveat:
- The ordinary destructor source spelling is not unsafe conceptually, but it belongs in a class/source reconstruction pass that also decides the final `TimerHandler` declaration shape. It should not be inserted into this combined vtable-glue page as if it were the exact binary wrapper.

### Base Teardown Identity For 0x00597580

Best direction:
- `0x00597580` is `TimerHandler_dtor`, the non-deleting destructor for the `TimerHandler` base/subobject.
- The older `boost::exception` and `EventDispatcher` labels are stale generated/type pollution.

Evidence checked:
- [UID:0001K7] `TimerHandlerDestructor` records 2026-06-16 live IDA refresh: `0x00597580` was renamed to `TimerHandler_dtor`, size `0x43`.
- The body writes the `TimerHandler` vtable at `0x0062e338` and calls timer unregister helper `0x00597a10` through `g_pTimerMgr`.
- `xrefs_to 0x00597580` includes `0x00484006` inside the `CheatDetector` deleting destructor plus many timer-owning cleanup paths. Broad caller spread supports a shared timer base destructor, not any one consumer.
- `CheatDetector` constructor calls `0x00597570`, the adjacent `TimerHandler` constructor that writes the same `TimerHandler` vtable.
- [UID:0003E0] `TimerHandlerVtableData` records the exact TimerHandler RTTI/vtable data and constructor/destructor vtable-store refs.

Rejected alternatives:
- `boost::exception::~exception`: rejected by vtable write, timer-manager unregister call, and project docs recording IDA label pollution.
- `EventDispatcher::~EventDispatcher`: rejected because `EventDispatcher` is only one consumer/derived owner; the body is generic timer-handler cleanup.
- `LObject` or dialog/pane base teardown: rejected by the specific TimerHandler vtable and `g_pTimerMgr` unregister behavior.

Score impact:
- The target page's current "base type remains unresolved" wording is stale. This pass resolves it to `TimerHandler` with strong support. Confidence remains at `90` only because current-session MCP was unavailable and exact final header split remains provisional.

### Owner / Emitter Routing

Best direction:
- Canonical owner: [UID:000020] `CheatDetector`.
- Emitter: [UID:000020] `CheatDetector`, surfacing through [UID:0000I6] `CheatDetector` to `auto-generated/NexusTK/security/CheatDetector.cpp`.

Evidence checked:
- `by-class/CheatDetector.md` is `85/86`, reconstructable, emits through [UID:0000I6].
- `by-file/CheatDetector.md` is `87/87`, proposed path `NexusTK/security/`.
- `auto-generated/-ag-memory-coverage.md` row for [UID:000109] reports `emits`, canonical owner `000020`, emitter `000020`, no dead end, and output path `auto-generated/NexusTK/security/CheatDetector.cpp`.
- Generated `CheatDetector.cpp` contains an empty emitter marker for [UID:000109], confirming the route exists but formal code is blank.

Rejected alternatives:
- `Application.cpp`: rejected because application constructs/cleans the singleton but does not own its class vtable, callback, or destructor.
- `TimerMgr.cpp`: rejected as direct owner. `TimerHandler` is the inherited base, but the vtable slot and singleton storage are `CheatDetector`.
- `client_anticheat` meta: rejected as a topical index, not a source emitter.
- `VirusChecker.cpp`: rejected because security folder adjacency does not imply shared class ownership.

### Coverage / Support Text Replacement

Recommended support text changes:
- Replace "virtual check slot" with "TimerHandler callback override that returns true".
- Replace "exact base type remains unresolved" with "`0x00597580` is the `TimerHandler_dtor` base teardown; exact final header/source split remains provisional."
- Add the likely callback signature: `bool CheatDetector::OnTimer(int eventId, int arg0, int arg1)`.
- Add no-code proof: the range is valid route-bearing code, but formal C++ should remain blank because two of three subfunctions are compiler/EH glue.

### First-Draft C++ Readiness

Final decision:
- Do not populate the formal [UID:000109] C++ block now.

Concrete no-code proof:
- `0x00483ff0` is reached only from constructor cleanup/unwind metadata and has no source-level call surface. The source construct is the constructor's singleton publish and cleanup semantics, not a handwritten helper function.
- `0x00484000` is a scalar deleting destructor wrapper with delete flags and optional free. Hand-writing this wrapper would produce decompiler-shaped compiler support instead of plausible original source.
- A source-level `CheatDetector::~CheatDetector()` body alone would not be an exact representation of this range and would not explain the delete-flag logic.
- The only clean source method in this range is `CheatDetector::OnTimer`, but emitting only that five-byte method in the combined page would leave the rest of the range's compiler/EH glue misrepresented. If a future maintainer wants formal code for the callback alone, split `0x00483fe0-0x00483fe5` into a dedicated child first or move the class declaration/destructor source shape into the class/file-level reconstruction.

Review-only source shape for future class-level reconstruction:

```cpp
// Review-only shape, not recommended for UID:000109 formal C++ as a combined range.
bool CheatDetector::OnTimer(int eventId, int arg0, int arg1)
{
    return true;
}
```

## Evidence Standards Used

Evidence types used:
- existing target docs with live IDA-recorded function sizes, xrefs, callees, byte padding, and vtable refs;
- local read-only exported function records for the target subfunctions and TimerHandler base destructor;
- related by-class/by-file/by-global/by-type documentation;
- generated route reports and generated output markers;
- negative evidence from caller/xref absence and compiler-wrapper shape.

This is strong enough to resolve ownership, generated names, base teardown identity, singleton-clear role, and vtable signature. It is not strong enough to justify a final-audit score or a formal C++ body for the combined range because the exact original source spelling and generated wrapper treatment remain source-shape sensitive.

## IDA MCP Facts

Current-session live MCP:
- Attempted `tools/list` at `http://127.0.0.1:13337/mcp`.
- Result: unavailable, `Unable to connect to the remote server`.

Existing live IDA facts recorded in project docs:
- `0x00483fe0` size `0x05`, vtable data xref from `0x00615568`.
- `0x00483ff0` size `0x0b`, constructor cleanup metadata xref at `0x005fc446`.
- `0x00484000` size `0x2d`, vtable data xref from `0x00615564`, callees `0x00597580` and `0x005c7526`.
- `0x00483fe5-0x00483ff0`, `0x00483ffb-0x00484000`, and `0x0048402d-0x00484030` are `0xcc` alignment padding.
- `0x00597580` has current support-page live IDA evidence as `TimerHandler_dtor`, writes `TimerHandler::vftable`, and unregisters through `g_pTimerMgr`.

Local read-only export facts:
- `0x00483fe0` decompiles as true-return, IDA signature shape `char __stdcall(int,int,int)`, vtable data xref only.
- `0x00483ff0` decompiles as `g_pCheatDetector = 0`, no callees, cleanup/unwind xref.
- `0x00484000` decompiles as base destructor call, singleton clear, optional free under delete flag, return receiver.
- `0x00483f00` constructor stores `g_pCheatDetector`, calls `0x00597570`, installs `CheatDetector` vtable, and zeros four state dwords.
- `0x00597580` export still shows stale names but body writes `TimerHandler::vftable` and calls timer unregister helper `0x00597a10`; current docs supersede the stale export label.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00483fe0-0x00483fe5` | part of [UID:000109] | `CheatDetector::OnTimer` true-return callback override | yes | [UID:000020] | recommended `86/90` aggregate | source-facing name resolved |
| `0x00483fe5-0x00483ff0` | ignored padding | `0xcc` alignment | no | padding ledger | `100/strong` in coverage context | already ignored |
| `0x00483ff0-0x00483ffb` | part of [UID:000109] | `ClearCheatDetectorSingleton` constructor-unwind helper | yes as lifecycle support | [UID:000020] | recommended `86/90` aggregate | role resolved; no formal source body |
| `0x00483ffb-0x00484000` | ignored padding | `0xcc` alignment | no | padding ledger | `100/strong` in coverage context | already ignored |
| `0x00484000-0x0048402d` | part of [UID:000109] | `CheatDetectorScalarDeletingDestructor` / source semantic `~CheatDetector` | yes as lifecycle support | [UID:000020] | recommended `86/90` aggregate | base identity resolved; formal code withheld |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00615568 -> 0x00483fe0` | vtable data ref | `CheatDetector` callback slot `+0x04`. |
| `0x00615564 -> 0x00484000` | vtable data ref | `CheatDetector` scalar deleting destructor slot `+0x00`. |
| `0x005fc446 -> 0x00483ff0` | constructor unwind/cleanup metadata | Clears singleton if construction fails after early publish. |
| `0x00484006 -> 0x00597580` | call | `CheatDetector` deleting destructor calls `TimerHandler_dtor`. |
| `0x0048400f` | write to `0x0067ab3c` | Destructor clears `g_pCheatDetector`. |
| `0x00483ff0` | write to `0x0067ab3c` | Cleanup helper clears `g_pCheatDetector`. |
| `0x00483f33 / 0x00483f3a` | writes to `0x0067ab3c` | Constructor publishes or clears singleton based on null-adjustment guard. |
| `0x0046473e -> 0x00483f00` | application startup caller | Application constructs `CheatDetector`; startup is consumer, not owner. |
| `0x00464ba0` | application cleanup reader | Application cleanup reads singleton and dispatches destructor if non-null. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:
- `by-class/CheatDetector.md`: records `TimerHandler` base relationship, vtable entries, singleton refs, and current route through `CheatDetector.cpp`.
- `by-file/CheatDetector.md`: records `security/CheatDetector.cpp`, startup singleton role, and current support refresh resolving `0x00597580` as `TimerHandler_dtor`.
- `by-global/g_pCheatDetector.md` and `by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md`: record lifecycle refs for constructor, cleanup helper, deleting destructor, and application cleanup.
- `by-type/by-vtable/CheatDetectorVtable.md` and `by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md`: record two-slot `CheatDetector` vtable and slot targets.
- `by-class/TimerHandler.md` and `by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md`: resolve base teardown identity and stale `boost`/`EventDispatcher` labels.
- `by-type/by-struct/ScheduledTimerEvent.md`: records scheduled timer record fields and callback dispatch through virtual slot `+4`.

Existing docs that are stale or incomplete:
- Target page still says "medium for final base-class naming" and "actual base type is resolved later" style wording. This should be replaced with the stronger `TimerHandler_dtor` conclusion.
- Coverage row still says "exact base type remains unresolved"; replace with the row below.
- Some coverage/vtable evidence text still quotes `sub_483FE0`, `sub_483FF0`, and `sub_484000`; these are generated evidence labels and should be replaced or clearly marked as old IDA labels.
- `client_anticheat.md` still says the compact range ends at `0x0048402c`; related memory pages now use the exact exclusive end `0x0048402d`.

Generated/coverage report state:
- `auto-generated/-ag-memory-coverage.md` reports [UID:000109] as emitting through [UID:000020] with no dead end to `auto-generated/NexusTK/security/CheatDetector.cpp`.
- Generated `CheatDetector.cpp` has an empty emitter marker for [UID:000109].

## Ranked Ownership Analysis

### 1. [UID:000020] CheatDetector

Evidence for:
- Constructor installs `CheatDetector` vtable and publishes `g_pCheatDetector`.
- The target contains the class vtable callback, singleton clear, and deleting destructor.
- Vtable data and global singleton docs route directly to the class.
- Class and file parents both clear the current ownership/emitter gates.

Evidence against:
- The destructor calls `TimerHandler_dtor`, but that is base teardown, not direct ownership.

Decision:
- Accepted as canonical owner and emitter.

### 2. [UID:0000I6] CheatDetector source file

Evidence for:
- Proposed source tree and file docs place the module at `security/CheatDetector.cpp`.
- Generated route surfaces through this file.
- The file owns the singleton, class, vtable, and associated memory/global/type children.

Evidence against:
- Direct semantic owner should be the class, not the file root.

Decision:
- Accepted as source file route, not canonical owner.

### 3. [UID:0000F0] TimerHandler / [UID:0000OT] TimerMgr

Evidence for:
- Base constructor/destructor are `TimerHandler` functions.
- The true-return slot matches `TimerHandler` callback shape.

Evidence against:
- The vtable target is in `CheatDetector`'s vtable, not `TimerHandler`'s.
- `g_pCheatDetector` lifecycle is class-specific.
- TimerMgr owns scheduler infrastructure, not the derived security singleton.

Decision:
- Accepted as dependency/base identity only; rejected as owner/emitter for [UID:000109].

### 4. Application

Evidence for:
- Application startup constructs `CheatDetector` and cleanup reads the singleton.

Evidence against:
- Construction/cleanup consumer refs do not own class vtable, destructor, or singleton declaration.
- Application docs explicitly keep startup-created singleton modules out of `Application.cpp`.

Decision:
- Rejected.

### 5. EventDispatcher / Boost Exception

Evidence for:
- Older generated/decompiler labels pointed at `EventDispatcher` or `boost::exception`.

Evidence against:
- Current support docs and local export body show `TimerHandler` vtable write and timer unregister.
- Broad caller spread proves shared timer base behavior.

Decision:
- Rejected as generated/type pollution.

## Negative Evidence Summary

Checked and rejected:
- No ordinary direct callers for the vtable slot or scalar deleting destructor; this is expected for vtable reachability and does not weaken ownership.
- No source evidence supports naming the true-return slot as an anti-cheat rule checker; the timer callback shape is stronger.
- No evidence supports moving the target into `TimerMgr.cpp`; inherited base calls are dependencies.
- No evidence supports hand-writing `ClearCheatDetectorSingleton` as an ordinary source helper; the xref is constructor unwind metadata.
- No evidence supports hand-writing the scalar deleting destructor as source. The delete flag and optional free are compiler wrapper mechanics.

## Final Recommendation

Exact recommended metadata:
- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:000020`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000020`
- Keep the formal `RECONSTRUCTION_CPP CODE` block blank for now.

Recommended target-page text changes:
- Rename the functions table entries:
  - `virtual check slot` -> `CheatDetector::OnTimer callback override`.
  - `singleton clear helper` -> `ClearCheatDetectorSingleton`.
  - `scalar deleting destructor` -> `CheatDetectorScalarDeletingDestructor / source semantic CheatDetector::~CheatDetector`.
- Replace base ambiguity with: `0x00597580 is TimerHandler_dtor; old EventDispatcher/boost labels are polluted decompiler/generated names.`
- Add the no-code proof from the First-Draft C++ section.
- Add the callback signature inference: `bool CheatDetector::OnTimer(int eventId, int arg0, int arg1)`.

Exact coverage replacement row, preserving low-to-high ordering and replacing the current [UID:000109] row:

```text
    - [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md) 0x00483fe0-0x0048402d | virtual callback/destructor glue | CheatDetectorVirtualClearAndDestructor : reconstructable : 86% : strong : Source-quality reanalysis resolves `0x00483fe0` as the CheatDetector `TimerHandler` callback override `OnTimer(eventId,arg0,arg1)` returning true, `0x00483ff0` as constructor-unwind `ClearCheatDetectorSingleton`, and `0x00484000` as the MSVC scalar deleting destructor over confirmed `TimerHandler_dtor` base teardown plus optional free; owner/emitter stay [UID:000020], and formal C++ remains blank because this combined range includes compiler/EH cleanup and deleting-destructor glue that should be regenerated from class declarations/destructor source rather than hand-written.
```

## Follow-Up Actions

Supervisor actions:
- Apply the coverage row replacement above if accepting the report.
- Incorporate target support text details into [UID:000109].
- Consider cleaning generated label references in coverage/vtable evidence text where they trigger `project-level/-unresolved.md`, replacing them with the resolved source-facing names or explicitly marking them as old IDA labels.

A-agent actions:
- If tasked with target-page editing, update [UID:000109] with the resolved names, callback signature, `TimerHandler_dtor` base identity, and no-code proof.
- Optionally update `client_anticheat.md` from `0x0048402c` to the exact exclusive end `0x0048402d` when that meta page is next edited.

B012 future research actions:
- None required for this target unless the supervisor asks for an actual split of the five-byte callback into a dedicated child page.

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for `86/90`.
- Remaining uncertainty: exact original identifier spelling for `OnTimer` and callback argument names; exact final source split for `TimerHandler` header/source; ordinary destructor source ordering if a future class-level C++ pass attempts to model it. These uncertainties block formal C++ for this combined range but do not block owner/emitter routing or the score raise.

## Validator Results

- Commands run: none. This was report-only B012 research, and no by-* or coverage files were changed.
- Current generated route was checked through `auto-generated/-ag-memory-coverage.md` and generated `CheatDetector.cpp`.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B012/research/000109-CheatDetectorVirtualClearAndDestructor-source-quality.md`
- Modified: none outside B012 research.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/000109-CheatDetectorVirtualClearAndDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"000109"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
