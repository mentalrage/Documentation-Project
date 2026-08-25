** TARGET-REPORT-UID:0001AH **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001AH / 0001AJ NewHistoryDialogPane And StaffsDialogPane Destructor Pair Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: raise both destructor pages from `84/88` to `88/90`, keep both reconstructable and emitting through their current login source-file owners, and populate formal first-draft C++ with the ordinary source destructor body rather than scalar deleting-wrapper pseudocode.
- Final disposition: both targets are scalar deleting destructor wrappers in the binary, but each wrapper carries one source-authored derived destructor statement: clearing its active singleton pointer. The base cleanup, delete flag, no-free flag, guard-check artifact, delete helper, and adjustor thunks are compiler/ABI output.
- Required action: supervisor should update the two target docs and support docs with the source-quality resolution below, then update `by-memory/-coverage-report.md` using the exact replacement rows in this report. Do not edit the ignored thunk pages into emitting source methods.
- Confidence: strong to very strong. Current IDA MCP was unavailable in this session, but existing target/support docs record prior live MCP checks, and local exported IDA/Ghidra JSON plus generated reports confirm the key function ranges, decompilation, xrefs, vtable routes, helper callees, and generated-output state.

## Target

| UID | Path | Current score | Current owner/emitter | Current issue |
| --- | --- | --- | --- | --- |
| `0001AH` | `by-memory/0x00502920-0x00502965.NewHistoryDialogPaneDestructor.md` | `84/88` | [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md) | Blank C++; stale 95/95 blocker; scalar deleting destructor versus ordinary source destructor identity; generated base-cleanup label. |
| `0001AJ` | `by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneDestructor.md` | `84/88` | [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md) | Blank C++; stale 95/95 blocker; scalar deleting destructor versus ordinary source destructor identity; generated base-cleanup label. |

Source queue rows in `project-level/-auto-completion-stats.md` are:

```text
| `0001AH` | 84 | 88 | 86.0 | `by-memory/0x00502920-0x00502965.NewHistoryDialogPaneDestructor.md` |
| `0001AJ` | 84 | 88 | 86.0 | `by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneDestructor.md` |
```

## Executive Recommendation

Populate both formal `RECONSTRUCTION_CPP CODE` blocks with ordinary destructor bodies:

```cpp
NewHistoryDialogPane::~NewHistoryDialogPane()
{
    g_pNewHistoryDialog = NULL;
}
```

```cpp
StaffsDialogPane::~StaffsDialogPane()
{
    g_pStaffsDialog = NULL;
}
```

Do not populate scalar deleting destructor wrappers such as `virt_deldtor_0x502920(unsigned int flags)` or `virt_deldtor_0x502cc0(unsigned int flags)`. Those are binary ABI shapes generated from the class destructor and compiler delete wrapper. The source declaration should remain normal mid-2000s C++: a non-returning-to-source `~ClassName()` body that clears the file-owned singleton, then lets the compiler emit base-class teardown and scalar deleting destructor glue.

Recommended metadata:

| UID | Completion | Confidence | Owner | Emitter | Reconstructable | Rationale |
| --- | --- | --- | --- | --- | --- | --- |
| `0001AH` | `88` | `90` | keep `0000LQ` | keep `0000LQ` | keep `TRUE` | Function range, singleton clear, wrapper flags, base cleanup target, vtable/thunk reachability, padding, owner, and C++ source shape are now resolved. |
| `0001AJ` | `88` | `90` | keep `0000O3` | keep `0000O3` | keep `TRUE` | Same source-quality resolution as `0001AH`, with Staffs-specific singleton and vtable routes. |

No split or rename is recommended. The current half-open ranges are exact scalar deleting-wrapper ranges. The source-authored statements inside them are small, but the by-memory targets are not mixed-owner enough to split because the wrapper is the compiler's implementation of the same class destructor.

## Supervisor Active Recheck

- Active assignment: paired B-preferred source-quality and heuristic pass for [UID:0001AH] and [UID:0001AJ].
- Report-only status: no by-* pages or coverage reports were edited directly.
- `by-memory/-coverage-report.md` edit ban honored. Exact replacement rows are included below.
- IDA MCP status: attempted `tools/list` at `http://127.0.0.1:13337/mcp`; connection failed with `Unable to connect to the remote server`. Evidence was therefore rechecked through local exported IDA/Ghidra JSON, existing target/support docs that record prior live MCP checks, generated coverage, and generated source output.

## Inference Research Guidance Check

`by-structure.md` treats by-memory pages as the canonical home for exact function/method bodies and reconstructed C++ candidates, while compiler/linker-generated rebuild-handling policy says scalar deleting wrappers, adjustor thunks, and guard/delete boilerplate should normally be regenerated by the compiler rather than hand-authored. The active code-entry gate is `(completion + confidence) / 2 > 85` with nonblank emitter route, not the older `95/95` threshold. Both targets already have nonblank emitter UIDs that route to generated `NexusTK/login/*.cpp` files, and the recommended `88/90` scores clear the active gate.

Existing docs were treated as leads, not proof. The current pages correctly identify the range and lifecycle behavior, but the `RECONSTRUCTION_CPP` blockers are stale because they do not separate source-authored destructor semantics from scalar deleting destructor ABI glue. The best defensible inference is:

- source-facing method identity: `NewHistoryDialogPane::~NewHistoryDialogPane()` and `StaffsDialogPane::~StaffsDialogPane()`;
- source-authored body: singleton clear only;
- compiler-generated wrapper behavior: base destructor call, delete/no-free flag test, delete helper call, guard-check artifact, and secondary adjustor thunks.

## IDA / Export Evidence

### [UID:0001AH] `0x00502920-0x00502965`

Local exported function record `resources/exported_data/functions/0x00502920.json`:

- Address: `0x00502920`.
- Size: `69` bytes, matching half-open `0x00502920-0x00502965`.
- Ghidra name/signature: `NewHistoryDialogPane::~NewHistoryDialogPane(NewHistoryDialogPane *this,uint param_1)`.
- OOAnalyzer method type: `deldtor`, method `virt_deldtor_0x502920`.
- IDA signature still type-polluted as `boost::exception *__thiscall sub_502920(boost::exception *Block, char a2)`.
- Callees: `0x0049d9f0`, `0x004f4ac0`, `0x0041b6a0`.
- Ghidra callers: only the two thunk functions `0x005024f8` and `0x00502503`.
- IDA `xrefs_to`: jump refs from `0x005024fe` and `0x00502509`, and primary vtable data ref at `0x0061daf4`.
- IDA `xrefs_from`: call to the polluted `??1exception@boost@@MAE@XZ_0` name at `0x0049d9f0`, call to `sub_4F4AC0`, and call to `_guard_check_icall_nop`.

The exported Ghidra and IDA pseudocode both reduce to:

```cpp
g_pNewHistoryDialog = 0;
DialogPane::~DialogPane();          // IDA type-polluted as boost::exception::~exception
if ((deleteFlags & 1) != 0 && (deleteFlags & 4) == 0) {
    DeleteObjectStorageWrapper(this);
}
return this;
```

Existing target docs record prior live MCP checks that place the singleton clear at `0x00502926`, report no ordinary direct callers, and confirm eleven `0xcc` bytes at `0x00502965-0x00502970`.

### [UID:0001AJ] `0x00502cc0-0x00502d05`

Local exported function record `resources/exported_data/functions/0x00502cc0.json`:

- Address: `0x00502cc0`.
- Size: `69` bytes, matching half-open `0x00502cc0-0x00502d05`.
- Ghidra name/signature: `StaffsDialogPane::~StaffsDialogPane(StaffsDialogPane *this,uint param_1)`.
- OOAnalyzer method type: `deldtor`, method `virt_deldtor_0x502cc0`.
- IDA signature still type-polluted as `boost::exception *__thiscall sub_502CC0(boost::exception *Block, char a2)`.
- Callees: `0x0049d9f0`, `0x004f4ac0`, `0x0041b6a0`.
- Ghidra callers: only the two thunk functions `0x00502592` and `0x0050259d`.
- IDA `xrefs_to`: jump refs from `0x00502598` and `0x005025a3`, and primary vtable data ref at `0x0061d934`.
- IDA `xrefs_from`: call to the same type-polluted `0x0049d9f0` base cleanup, call to `sub_4F4AC0`, and call to `_guard_check_icall_nop`.

The exported pseudocode is the Staffs equivalent:

```cpp
g_pStaffsDialog = 0;
DialogPane::~DialogPane();          // IDA type-polluted as boost::exception::~exception
if ((deleteFlags & 1) != 0 && (deleteFlags & 4) == 0) {
    DeleteObjectStorageWrapper(this);
}
return this;
```

Existing target docs record the singleton clear at `0x00502cc6`, no ordinary direct callers, and eleven `0xcc` bytes at `0x00502d05-0x00502d10`.

### Shared base cleanup target `0x0049d9f0`

The generated `boost::exception` / `TransferReplyAlert` label should be rejected as type-recovery pollution for these targets.

Evidence checked:

- `by-memory/0x0049d8a0-0x0049feae.DialogPane.md` identifies `0x0049d9f0-0x0049dacb` as the cleanup/non-deleting destructor body for `DialogPane`.
- That page records that the body decrements `byte_69B380` / `g_activeDialogCount`, releases the control manager at `this+0x1fc`, destroys the tile context at `this+0x23c`, reinstalls the DialogPane vtables, and calls base Pane teardown.
- `by-file/DialogPane.md` confirms `0x0049d9f0` size `0xdb` and says the base constructor increments `g_activeDialogCount` while the destructor decrements it.
- Local exported `0x0049d9f0.json` has size `219` bytes and a huge destructor caller set across dialog-like classes, including `0x00502920` and `0x00502cc0`; this is exactly the pattern expected for a common `DialogPane` base destructor, not a Boost exception object.
- The generated C++ report for `0x0049d9f0` shows DialogPane vtable writes to `0x00618a64`, `0x00618ac4`, and `0x00618af4`, active-dialog count decrement, control-manager release, tile-context cleanup, and tail base Pane teardown.

Best source-quality name/signature:

```cpp
DialogPane::~DialogPane()
```

When describing the binary implementation, use `DialogPane` non-deleting destructor / base cleanup body at `0x0049d9f0`. Do not use `boost::exception::~exception`, `TransferReplyAlert::~TransferReplyAlert`, or a target-specific helper name for this call.

### Shared delete helper `0x004f4ac0`

Local generated report `re-agent/reports/code/0x004f4ac0__FUN_004f4ac0.cpp` and `resources/exported_data/functions/0x004f4ac0.json` show:

- Address `0x004f4ac0`, size `64`.
- Called by hundreds of destructor wrappers, including `0x00502920` and `0x00502cc0`.
- Calls `0x00516030` and `0x00516170(param_1)` inside an SEH-looking wrapper.

Best source-quality interpretation:

- source-facing semantic name: `operator delete(this)` or `DeleteObjectStorageWrapper(this)`;
- rebuild-handling: compiler/runtime/delete-wrapper support generated from scalar deleting destructor flags;
- not handwritten in the ordinary destructor body.

The target pages should mention the helper only to explain the binary wrapper. The formal C++ should not call `0x004f4ac0` or model the delete flags.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct parent | Current score | Recommended state |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00502920-0x00502965` | [UID:0001AH][NewHistoryDialogPaneDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneDestructor.md) | Scalar deleting destructor wrapper for source `NewHistoryDialogPane::~NewHistoryDialogPane()` | `TRUE` | [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md) | `84/88` | `88/90`, populate ordinary destructor C++. |
| `0x005024f8-0x0050250e` | [UID:0001AC][NewHistoryDialogPaneDestructorThunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md) | Secondary destructor adjustor thunks | `FALSE` | `NONE` | `84/90` | No score change; keep ignored/non-emitting. |
| `0x00502cc0-0x00502d05` | [UID:0001AJ][StaffsDialogPaneDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneDestructor.md) | Scalar deleting destructor wrapper for source `StaffsDialogPane::~StaffsDialogPane()` | `TRUE` | [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md) | `84/88` | `88/90`, populate ordinary destructor C++. |
| `0x00502592-0x005025a8` | [UID:0001AE][StaffsDialogPaneDestructorThunks](by-memory/0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks.md) | Secondary destructor adjustor thunks | `FALSE` | `NONE` | `84/90` | No score change; keep ignored/non-emitting. |
| `0x0049d9f0-0x0049dacb` | [UID:00012R][DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md) | `DialogPane::~DialogPane()` base cleanup body | `TRUE` inside DialogPane aggregate | [UID:00003T][DialogPane](by-class/DialogPane.md) | documented | No target-specific edit required except references from these target pages. |
| `0x004f4ac0-0x004f4b00` | local exported helper | Scalar deleting destructor delete/free wrapper | runtime/compiler support | shared | documented by exports | Do not hand-author in target C++. |

## Direct Xref / Caller Inventory

| Target | Xref / caller / callee | Meaning |
| --- | --- | --- |
| `0x00502920` | `0x0061daf4` data xref | Primary `NewHistoryDialogPane` destructor vtable slot. |
| `0x00502920` | `0x005024fe`, `0x00502509` jump refs | Secondary destructor adjustor thunks dispatch here after `this-0xa0` / `this-0xa4` adjustment. |
| `0x00502920` | callees `0x0049d9f0`, `0x004f4ac0`, `0x0041b6a0` | Base DialogPane destructor, delete wrapper, guard/no-free branch artifact. |
| `0x00502926` | write to `0x0069b49c` | Source-authored `g_pNewHistoryDialog = NULL;`. |
| `0x00502cc0` | `0x0061d934` data xref | Primary `StaffsDialogPane` destructor vtable slot. |
| `0x00502cc0` | `0x00502598`, `0x005025a3` jump refs | Secondary destructor adjustor thunks dispatch here after `this-0xa0` / `this-0xa4` adjustment. |
| `0x00502cc0` | callees `0x0049d9f0`, `0x004f4ac0`, `0x0041b6a0` | Base DialogPane destructor, delete wrapper, guard/no-free branch artifact. |
| `0x00502cc6` | write to `0x0069b490` | Source-authored `g_pStaffsDialog = NULL;`. |

## Boundary, Padding, And Vtable Findings

`0001AH` exact boundary remains `0x00502920-0x00502965`.

- Size is `0x45` / 69 bytes in both IDA and Ghidra exports.
- Previous live MCP note confirms padding `0x00502965-0x00502970` as eleven `0xcc` bytes.
- The wrapper itself does not reinstall derived `NewHistoryDialogPane` vtables. Derived vtable identity is proven by constructor stores and by destructor vtable refs: primary `0x0061daf4`, secondary thunk heads `0x0061db54` and `0x0061db84`.
- `DialogPane::~DialogPane()` at `0x0049d9f0` performs the base vtable reinstalls to DialogPane vtables. Those writes belong to the base destructor, not to source code inside `NewHistoryDialogPane::~NewHistoryDialogPane()`.

`0001AJ` exact boundary remains `0x00502cc0-0x00502d05`.

- Size is `0x45` / 69 bytes in both IDA and Ghidra exports.
- Previous live MCP note confirms padding `0x00502d05-0x00502d10` as eleven `0xcc` bytes before the next modeled destructor cluster.
- The wrapper itself does not reinstall derived `StaffsDialogPane` vtables. Derived vtable identity is proven by constructor stores and by destructor vtable refs: primary `0x0061d934`, secondary thunk heads `0x0061d994` and `0x0061d9c4`.
- Base vtable reinstalls happen inside `DialogPane::~DialogPane()` and should be regenerated by the compiler/base destructor chain.

## Ranked Ownership Analysis

### 1. Existing by-file owners: [UID:0000LQ] and [UID:0000O3]

Evidence for:

- Both target pages already route to source files with valid generated roots: `auto-generated/NexusTK/login/NewHistoryDialogPane.cpp` and `auto-generated/NexusTK/login/StaffsDialogPane.cpp`.
- `auto-generated/-ag-memory-coverage.md` lists both targets as emitting through the same file UIDs, not dead-end routes.
- Surrounding core method pages also use file owners: [UID:0001A3] routes through [UID:0000LQ], and [UID:00019Z] routes through [UID:0000O3].
- Class/file/global pages place both dialogs in `NexusTK/login/`, with matching resources and singleton lifecycles.
- The source-authored destructor body is a method definition that naturally belongs in the same `.cpp` file as the constructor and event handlers.

Evidence against:

- By-class UIDs are semantically closer to the destructor method identity.
- `StaffsDialogPane.cpp` currently generated as zero bytes because formal C++ is blank on its emitting memory pages.

Decision: keep current file owner/emitter metadata. The by-class pages remain semantic class references, but the project already models these method bodies as file-emitted reconstruction children. The current file owners clear the active gate and avoid a route churn that would not improve generated output.

### 2. By-class owners: [UID:000091] and [UID:0000DY]

Evidence for:

- The source-facing method identities are class destructors.
- Class pages document vtables, methods, resources, and singleton lifecycle.
- Both class UIDs emit through the same file UIDs in `auto-generated/-ag-class-coverage.md`.

Evidence against:

- Current by-memory method bodies in these source families are file-owned, not class-owned, and the file pages are the generated source roots.
- Class-level formal C++ blocks are intentionally blank pending header/declaration audit. Populating method bodies through class pages would blur class declaration and method implementation responsibilities.

Decision: use class pages as support docs and method identity references, but do not change target `CANONICAL_OWNER` from file UIDs in this pass.

### 3. Nearby by-memory core pages [UID:0001A3] and [UID:00019Z]

Evidence for:

- They contain the constructor/input/action methods and establish source layout.
- They already emit to the correct generated files.

Evidence against:

- They are sibling memory method ranges, not source owners. Making one by-memory range the direct owner of another destructor range would be structurally wrong.

Decision: reject as direct owners. They should cross-reference the destructor pages as sibling source methods.

### 4. DialogPane / base destructor owner

Evidence for:

- Both wrappers call `0x0049d9f0`, the `DialogPane::~DialogPane()` base cleanup body.
- `0x0049d9f0` is the source-quality answer for the generated `boost::exception` label.

Evidence against:

- The source-authored target-specific statement is clearing `g_pNewHistoryDialog` or `g_pStaffsDialog`, neither of which belongs to DialogPane.
- Base cleanup is implicit in C++ and should not own derived-class destructor bodies.

Decision: reject as target owner. Use DialogPane only as a base-cleanup dependency.

### 5. MainMenuPane, ScrolledTextControlPane, resource, or generic UI/core ownership

Evidence for:

- `NewHistoryDialogPane` is shown over the main UI graph and has a made-by scrolled-text consumer.
- `StaffsDialogPane` is shown over the main menu and consumes `ScrolledTextControlPane`.

Evidence against:

- These are consumers or child controls, not owners of the destructor bodies.
- Singleton storage and destructor clears are target-dialog local lifecycle state.
- File docs already reject grouping Staffs under gameplay/staff-management solely because of the word "staff".

Decision: reject as direct owners.

### 6. No-owner / non-emitting fallback

Evidence for:

- The current direct constructor-start reachability for both classes remains a documented source-history caveat.

Evidence against:

- Vtable routes, singleton lifecycle, class/file ownership, generated roots, and exact destructor body semantics are strong.
- Both targets already have valid emitter routes and are source-authored enough for ordinary destructor body output.

Decision: reject. Keeping these below-source/no-code because of constructor reachability would over-penalize an already identified virtual destructor body.

## Heuristic / Inference Reanalysis And Validation

### Scalar deleting destructor versus ordinary source destructor

- Evidence checked: target docs, exported `0x00502920.json`, exported `0x00502cc0.json`, generated C++ reports, thunk pages, vtable refs, active code-entry rule in `Supervisor.md`.
- Rejected alternatives: emit `virt_deldtor_0x502920(unsigned int)` / `virt_deldtor_0x502cc0(unsigned int)`; keep C++ blank due to scalar wrapper shape; mark as non-reconstructable compiler output.
- Best inference: the physical by-memory ranges are scalar deleting destructor wrappers, but the source-authored derived destructors are ordinary `~NewHistoryDialogPane()` and `~StaffsDialogPane()` methods. The only target-specific source statement in each is the singleton clear. Compiler-generated base-call/delete flag code should be regenerated.
- Score/owner/C++ impact: raises both pages above the source-code gate, keeps owner/emitter unchanged, and supports formal C++ population.

### Generated `boost::exception` / `TransferReplyAlert` base-cleanup label

- Evidence checked: `0x0049d9f0` exported record and generated code, DialogPane memory/file docs, caller set across many dialog destructors, target `xrefs_from`.
- Rejected alternatives: Boost exception destructor, `TransferReplyAlert` destructor, target-local helper, Staffs/NewHistory-specific base helper.
- Best inference: `0x0049d9f0` is `DialogPane::~DialogPane()` / DialogPane non-deleting destructor cleanup. IDA's `boost::exception` name and Ghidra's `TransferReplyAlert` class label are inherited-type pollution from broad type recovery.
- Score/owner/C++ impact: removes a named-helper blocker. It should be documented in target pages but omitted from ordinary destructor C++.

### Delete helper / delete flag behavior

- Evidence checked: target exported decompilation, `0x004f4ac0` exported/generation report, large destructor-wrapper caller set, IDA pseudocode flag condition.
- Rejected alternatives: user-authored destructor helper, class-specific free method, manually emitted `sub_4F4AC0(this)` source.
- Best inference: `0x004f4ac0` is a common delete/free wrapper used when scalar deleting destructor flags request object storage release; bit `1` is the delete/free request and bit `4` is a no-free/placement-style guard. The Ghidra `guard_check_icall` high-flag branch is an ABI/decompiler artifact and not source logic for these destructors.
- Score/owner/C++ impact: do not lower score for unresolved helper spelling. Source C++ remains ordinary destructor only.

### Singleton global names and declaration shape

- Evidence checked: global docs [UID:0000RS] and [UID:0000SC], memory storage docs [UID:0001PV] and [UID:0001PT], constructor publish/fallback xrefs, clear helpers, destructor clears, generated output for NewHistory, empty generated output for Staffs.
- Rejected alternatives: generic active dialog pointer; `g_pMainMenuPane`; GM/staff gameplay singleton; inherited base dialog state; leaving `dword_69B49C` / `dword_69B490` in final C++.
- Best inference: use descriptive source names `g_pNewHistoryDialog` and `g_pStaffsDialog`. Exact original declaration linkage (`static`, `extern`, header placement) is not fully proven, but the names are already supported project-wide by lifecycle evidence and owner docs.
- Score/owner/C++ impact: the exact declaration audit caps global pages below final audit, but it does not block the destructor body. `g_p... = NULL;` is source-ready.

### Vtable and thunk dispatch

- Evidence checked: thunk pages [UID:0001AC] and [UID:0001AE], target xrefs, class/file vtable notes, constructor vtable-store docs.
- Rejected alternatives: source-authored overloads for `0x005024f8`, `0x00502503`, `0x00502592`, `0x0050259d`; missing ordinary callers as proof of dead methods; direct target vtable writes inside the scalar wrappers.
- Best inference: each destructor is reached through primary vtable slot plus two compiler adjustor thunks for secondary bases. The wrappers themselves do not store derived vtables. Base DialogPane vtable reinstalls happen in `0x0049d9f0`.
- Score/owner/C++ impact: no split needed. Thunk pages stay ignored/non-emitting. Target C++ should not include thunks or vtable writes.

### Owner/source placement

- Evidence checked: by-file and by-class pages, auto-generated class/file/memory coverage, generated root paths, resources and singleton lifecycle, sibling core pages.
- Rejected alternatives: by-memory core pages as owners, DialogPane ownership, MainMenuPane ownership, ScrolledTextControlPane ownership, generic UI-core ownership, no-owner/non-emitting.
- Best inference: keep [UID:0000LQ] and [UID:0000O3] as direct owner/emitter UIDs. Use [UID:000091] and [UID:0000DY] as class identity docs, not metadata reroutes.
- Score/owner/C++ impact: owner/emitter metadata remains valid and generated output should gain destructor bodies in `NexusTK/login/NewHistoryDialogPane.cpp` and `NexusTK/login/StaffsDialogPane.cpp` after supervisor incorporation.

### Remaining open questions

- Direct constructor-start reachability remains open in the class/file docs for both dialogs. Evidence checked includes prior live MCP caller checks and raw PE pointer scans recorded in support docs. This is a launcher/source-history caveat, not a destructor C++ blocker, because destructor identity is proven by vtable refs and singleton lifecycle.
- Exact original global declaration linkage is not proven. The project already uses `g_pNewHistoryDialog` and `g_pStaffsDialog` as supported descriptive names. This caps final global declaration confidence but does not block the destructor body.
- No remaining target-specific blocker should keep [UID:0001AH] or [UID:0001AJ] at `84/88` or blank formal C++.

## First-Draft C++ Recommendation

Populate [UID:0001AH] formal C++ with:

```cpp
NewHistoryDialogPane::~NewHistoryDialogPane()
{
    g_pNewHistoryDialog = NULL;
}
```

Populate [UID:0001AJ] formal C++ with:

```cpp
StaffsDialogPane::~StaffsDialogPane()
{
    g_pStaffsDialog = NULL;
}
```

Do not include:

- explicit `DialogPane::~DialogPane()` call;
- `DeleteObjectStorageWrapper`, `sub_4F4AC0`, or `operator delete` calls;
- scalar delete flag parameters;
- `_guard_check_icall_nop`;
- adjustor thunk bodies;
- manual vtable writes.

Those are compiler-generated or inherited-base effects. The destructor body shape above is the plausible mid-2000s C++ source shape and should compile into the observed wrapper/base/delete behavior when paired with the class hierarchy.

## Target Doc Update Recommendations

### [UID:0001AH] target page

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000LQ
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LQ
```

Replace the stale status/behavior wording with this substance:

```text
Entity kind: scalar deleting destructor wrapper for source `NewHistoryDialogPane::~NewHistoryDialogPane()`.

The wrapper clears `g_pNewHistoryDialog` at `0x00502926`, then calls the shared `DialogPane::~DialogPane()` base cleanup at `0x0049d9f0`. IDA's `boost::exception::~exception` name and Ghidra's `TransferReplyAlert` type label are inherited-type pollution, not source ownership. The remaining delete-flag/no-free branch through `0x004f4ac0` is scalar deleting destructor ABI glue and should be regenerated by the compiler.

Formal C++ should be the ordinary source destructor body:

NewHistoryDialogPane::~NewHistoryDialogPane()
{
    g_pNewHistoryDialog = NULL;
}
```

Add a change note:

```text
2026-06-19 B005 source-quality pass: raised to `88/90`, resolved the stale 95/95 C++ blocker under the active code-entry gate, identified `0x0049d9f0` as `DialogPane::~DialogPane()` despite IDA `boost::exception` label pollution, kept the scalar deleting wrapper range exact, and recommended ordinary destructor C++ with only the source-authored singleton clear.
```

### [UID:0001AJ] target page

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000O3
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000O3
```

Replace the stale status/behavior wording with this substance:

```text
Entity kind: scalar deleting destructor wrapper for source `StaffsDialogPane::~StaffsDialogPane()`.

The wrapper clears `g_pStaffsDialog` at `0x00502cc6`, then calls the shared `DialogPane::~DialogPane()` base cleanup at `0x0049d9f0`. IDA's `boost::exception::~exception` name and Ghidra's `TransferReplyAlert` type label are inherited-type pollution, not source ownership. The remaining delete-flag/no-free branch through `0x004f4ac0` is scalar deleting destructor ABI glue and should be regenerated by the compiler.

Formal C++ should be the ordinary source destructor body:

StaffsDialogPane::~StaffsDialogPane()
{
    g_pStaffsDialog = NULL;
}
```

Add a change note:

```text
2026-06-19 B005 source-quality pass: raised to `88/90`, resolved the stale 95/95 C++ blocker under the active code-entry gate, identified `0x0049d9f0` as `DialogPane::~DialogPane()` despite IDA `boost::exception` label pollution, kept the scalar deleting wrapper range exact, and recommended ordinary destructor C++ with only the source-authored singleton clear.
```

## Support Doc Update Recommendations

Recommended support-doc changes for supervisor incorporation:

- [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md): update the Method Notes destructor row to say `Scalar deleting destructor wrapper for source NewHistoryDialogPane::~NewHistoryDialogPane(); source body clears g_pNewHistoryDialog, while DialogPane base cleanup, delete flags, and adjustor thunks are compiler/base output.`
- [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md): update the Method Notes destructor row to say `Scalar deleting destructor wrapper for source StaffsDialogPane::~StaffsDialogPane(); source body clears g_pStaffsDialog, while DialogPane base cleanup, delete flags, and adjustor thunks are compiler/base output.`
- [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md): in the Source Ownership Split table, change the destructor handling to ordinary source destructor in `login/NewHistoryDialogPane.cpp`; keep `0x005023e0` and `0x005024f8-0x0050250e` ignored as constructor cleanup/thunks.
- [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md): in the Source Boundary Split table, change the destructor handling to ordinary source destructor in `login/StaffsDialogPane.cpp`; keep `0x00502410` and `0x00502592-0x005025a8` ignored as constructor cleanup/thunks.
- [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md) and [UID:0001PV][g_pNewHistoryDialog storage](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md): add one sentence that the destructor page now has formal source C++ for the clear, while declaration linkage remains a global-page audit issue.
- [UID:0000SC][g_pStaffsDialog](by-global/g_pStaffsDialog.md) and [UID:0001PT][g_pStaffsDialog storage](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md): add one sentence that the destructor page now has formal source C++ for the clear, while declaration linkage remains a global-page audit issue.
- [UID:0001AC] and [UID:0001AE] thunk pages: no metadata change required. Optional wording only: `The source-authored destructor body is now documented on [UID:0001AH]/[UID:0001AJ]; these thunks remain compiler-generated and non-emitting.`
- [UID:00012R][DialogPane aggregate](by-memory/0x0049d8a0-0x0049feae.DialogPane.md) and [UID:0000IT][DialogPane file](by-file/DialogPane.md): no required metadata change. Current docs already resolve `0x0049d9f0` as DialogPane cleanup. Optional central alias sentence: `Child destructor pages should reference 0x0049d9f0 as DialogPane::~DialogPane(); IDA labels such as boost::exception::~exception are type pollution.`

No by-class, by-file, or by-global coverage row score changes are required by this report. The support pages already clear parent/emitter gates. Only the two by-memory target rows need replacement.

## Exact `by-memory/-coverage-report.md` Replacement Rows

Placement context: replace the existing [UID:0001AH] row immediately after [UID:0001AG] and before [UID:0001AI].

```text
    - [UID:0001AH][0x00502920-0x00502965.NewHistoryDialogPaneDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneDestructor.md) : reconstructable : 88% : very strong : B005 source-quality recheck resolves this as the scalar deleting destructor wrapper for source `NewHistoryDialogPane::~NewHistoryDialogPane()`: exact `0x45` extent, singleton clear at `0x00502926`, call to `DialogPane::~DialogPane`/base cleanup at `0x0049d9f0`, scalar delete/no-free wrapper path through `0x004f4ac0`, primary vtable ref `0x0061daf4`, secondary thunk refs `0x005024fe`/`0x00502509`, no ordinary direct callers, and `0x00502965-0x00502970` `0xcc` padding are confirmed by existing live-MCP notes plus local exported IDA/Ghidra data. Formal C++ should be the ordinary destructor body `g_pNewHistoryDialog = NULL;`; base cleanup, delete flags, guard artifact, and adjustor thunks are compiler/base output.
```

Placement context: replace the existing [UID:0001AJ] row immediately after the `0x00502cbd-0x00502cc0` padding row and before the `0x00502d05-0x00502d10` padding row.

```text
    - [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneDestructor.md) : reconstructable : 88% : very strong : B005 source-quality recheck resolves this as the scalar deleting destructor wrapper for source `StaffsDialogPane::~StaffsDialogPane()`: exact `0x45` extent, singleton clear at `0x00502cc6`, call to `DialogPane::~DialogPane`/base cleanup at `0x0049d9f0`, scalar delete/no-free wrapper path through `0x004f4ac0`, primary vtable ref `0x0061d934`, secondary thunk refs `0x00502598`/`0x005025a3`, no ordinary direct callers, and `0x00502d05-0x00502d10` `0xcc` padding are confirmed by existing live-MCP notes plus local exported IDA/Ghidra data. Formal C++ should be the ordinary destructor body `g_pStaffsDialog = NULL;`; base cleanup, delete flags, guard artifact, and adjustor thunks are compiler/base output.
```

## Generated-Output Expectations

- `auto-generated/NexusTK/login/NewHistoryDialogPane.cpp` currently contains constructor/input first-draft C++ but no destructor. After supervisor incorporation, it should include `NewHistoryDialogPane::~NewHistoryDialogPane()` with `g_pNewHistoryDialog = NULL;`.
- `auto-generated/NexusTK/login/StaffsDialogPane.cpp` currently exists as a zero-byte generated file because the Staffs core/destructor formal C++ blocks are blank. After supervisor incorporation, it should at least include `StaffsDialogPane::~StaffsDialogPane()` with `g_pStaffsDialog = NULL;`; broader constructor/action C++ remains a separate [UID:00019Z] source-quality issue.

## Negative Evidence Summary

- No current IDA MCP server was reachable, so no new live IDA facts were claimed from this session.
- No direct ordinary callers were found in the exported caller records; only vtable/thunk paths are supported for these destructor wrappers. This is expected for virtual scalar deleting destructors.
- No evidence supports a source-authored helper name for `0x004f4ac0`; its large destructor-wrapper caller set supports compiler/runtime delete-wrapper semantics.
- No evidence supports treating `0x0049d9f0` as Boost or TransferReplyAlert ownership for these targets. DialogPane docs and function behavior reject that label.
- No evidence supports rerouting either target to DialogPane, MainMenuPane, ScrolledTextControlPane, generic UI-core, or no-owner/non-emitting state.

## Validation Notes

Commands/evidence checks run:

- Tried IDA MCP `tools/list` via `Invoke-WebRequest`; failed with `Unable to connect to the remote server`.
- Read target docs, class docs, file docs, global/storage docs, thunk docs, DialogPane docs, generated memory/class/file/global coverage, and `project-level/-auto-completion-stats.md`.
- Parsed local exported function JSON for `0x00502920`, `0x00502cc0`, `0x0049d9f0`, and `0x004f4ac0`.
- Read generated code reports for `0x00502920`, `0x00502cc0`, `0x0049d9f0`, and `0x004f4ac0`.
- Checked current generated source files under `auto-generated/NexusTK/login/`.

No `validator.py` run was needed because this pass directly edits only this research report and does not modify any by-* documentation. The supervisor should run the normal scoped validation after applying the recommended by-* changes.

## Changed Files

- Added this report: `tools/leaser/Agents/Agent-B005/research/0001AH-0001AJ-NewHistoryStaffsDialogPaneDestructorPair-source-quality.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0001AH-0001AJ-NewHistoryStaffsDialogPaneDestructorPair-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0001AH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
