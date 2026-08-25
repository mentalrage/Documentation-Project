** TARGET-REPORT-UID:00022X **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022X UserCreateAppearanceScalarDeletingDestructors Source-Quality Report

Agent: B005  
Target: [UID:00022X] `0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors`  
Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md`  
Report date: 2026-06-19

## Final Recommendation

Raise the target from `84/88` to `86/90`, keep `CANONICAL_OWNER:0000OX`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000OX`, and keep the formal `RECONSTRUCTION_CPP` block blank with a target-specific no-code proof.

The score can move above the current 85 completion gate because the unresolved source-quality items are now resolved: `0x00544580` is ordinary `Pane::~Pane()`, the generated `TextButtonExControlPane` base label is owner pollution, `0x004f4ac0` is the MemoryMan-backed global `operator delete` wrapper, and the four target bodies are MSVC scalar deleting destructor wrappers rather than source-authored ordinary destructor bodies.

Do not populate the formal by-memory C++ block with raw `virt_deldtor_*` functions or with four out-of-line empty destructor definitions. The source-facing destructors are implicit/defaulted ordinary destructors for:

- `UserCreatePreviewControlPane::~UserCreatePreviewControlPane()`
- `UserFaceSelectControlPane::~UserFaceSelectControlPane()`
- `UserHairSelectControlPane::~UserHairSelectControlPane()`
- `UserShapeSelectControlPane::~UserShapeSelectControlPane()`

The by-memory page should remain a reconstructable source-declared/generated-binary evidence page because it proves the class/vtable destructor identities that the rebuilt class declarations must regenerate. It should not emit hand-authored wrapper code.

## Evidence Rechecked

### Tooling And Data Sources

- IDA MCP was attempted at `http://127.0.0.1:13337/mcp` and was unavailable: `Unable to connect to the remote server`.
- Local exported function JSON was checked under `resources/exported_data/functions`.
- Local vtable JSON/cache was checked under `resources/exported_data/master_vtables.json` and `hooks-generation/cached/vtable`.
- Generated/unrefined code reports were checked under `re-agent/reports/code` and `unrefined-source-backup/source`.
- Current by-* docs checked: target page, adjustor-thunk page [UID:0001AF], [UID:0000OX] `UserCreateAppearanceControls`, [UID:0000IK] `CreateUserDialogs`, the four class pages, [UID:0000MC] `Pane`, and [UID:000197] `OperatorDeleteWrapper`.
- No local `NexusTK.exe` was found in the workspace, and the function JSON does not include raw byte strings. Exact byte values therefore rely on current live-IDA byte notes already in the target/coverage docs; this pass revalidated function starts/sizes/routes from local exports and found no conflicting evidence.

### Range, Boundary, Padding

| Body | Exported size | Half-open range | Boundary / padding evidence |
| --- | ---: | --- | --- |
| Preview deleting destructor | `59` / `0x3b` | `0x00502d10-0x00502d4b` | Preceded by `0x00502d05-0x00502d10` `0xcc` padding after [UID:0001AJ]; followed by `0x00502d4b-0x00502d50` five-byte `0xcc` padding. |
| Face deleting destructor | `59` / `0x3b` | `0x00502d50-0x00502d8b` | Followed by `0x00502d8b-0x00502d90` five-byte `0xcc` padding. |
| Hair deleting destructor | `59` / `0x3b` | `0x00502d90-0x00502dcb` | Followed by `0x00502dcb-0x00502dd0` five-byte `0xcc` padding. |
| Shape deleting destructor | `59` / `0x3b` | `0x00502dd0-0x00502e0b` | Followed by `0x00502e0b-0x00502e10` five-byte `0xcc` padding. |

The target page's prior live-IDA note says byte checks confirmed the inter-function `0xcc` alignment; local exports reconfirm the four `0x3b` function objects and the successor/predecessor coverage rows still match the half-open boundaries.

### Wrapper Bodies

| Address | Exported/generated identity | Callees | Source-quality interpretation |
| --- | --- | --- | --- |
| `0x00502d10` | `~UserCreatePreviewControlPane`, `virt_deldtor_0x502d10` | `0x00544580`, `0x004f4ac0`, `0x0041b6a0` | Scalar deleting wrapper for `UserCreatePreviewControlPane::~UserCreatePreviewControlPane()`. |
| `0x00502d50` | `~UserFaceSelectControlPane`, `virt_deldtor_0x502d50` | `0x00544580`, `0x004f4ac0`, `0x0041b6a0` | Scalar deleting wrapper for `UserFaceSelectControlPane::~UserFaceSelectControlPane()`. |
| `0x00502d90` | `~UserHairSelectControlPane`, `virt_deldtor_0x502d90` | `0x00544580`, `0x004f4ac0`, `0x0041b6a0` | Scalar deleting wrapper for `UserHairSelectControlPane::~UserHairSelectControlPane()`. |
| `0x00502dd0` | `~UserShapeSelectControlPane`, `virt_deldtor_0x502dd0` | `0x00544580`, `0x004f4ac0`, `0x0041b6a0` | Scalar deleting wrapper for `UserShapeSelectControlPane::~UserShapeSelectControlPane()`. |

The generated code for all four bodies has the same shape:

1. Call the base cleanup currently mislabeled as `TextButtonExControlPane::~TextButtonExControlPane`.
2. If `(flags & 1) != 0` and `(flags & 4) == 0`, call `FUN_004f4ac0(this)`.
3. If `(flags & 4) != 0`, branch to `guard_check_icall`.
4. Return `this`.

There are no derived-field releases, singleton clears, event unregisters beyond the base `Pane` destructor, vtable stores in the wrappers, resource frees, or class-specific source statements.

### Thunk And Vtable Reachability

| Class | Primary vtable slot | Secondary/tertiary thunks | Vtable refs for thunks | Route |
| --- | --- | --- | --- | --- |
| `UserCreatePreviewControlPane` | `0x0061dec4[0] -> 0x00502d10` | `0x005025a8`, `0x005025b3` | `0x0061df2c[0]`, `0x0061df5c[0]` | Both thunks forward to `0x00502d10` after `this - 0xa0` / `this - 0xa4`. |
| `UserFaceSelectControlPane` | `0x0061de20[0] -> 0x00502d50` | `0x005025be`, `0x005025c9` | `0x0061de88[0]`, `0x0061deb8[0]` | Both thunks forward to `0x00502d50` after `this - 0xa0` / `this - 0xa4`. |
| `UserHairSelectControlPane` | `0x0061dd7c[0] -> 0x00502d90` | `0x005025d4`, `0x005025df` | `0x0061dde4[0]`, `0x0061de14[0]` | Both thunks forward to `0x00502d90` after `this - 0xa0` / `this - 0xa4`. |
| `UserShapeSelectControlPane` | `0x0061d564[0] -> 0x00502dd0` | `0x005025ea`, `0x005025f5` | `0x0061d5cc[0]`, `0x0061d5fc[0]` | Both thunks forward to `0x00502dd0` after `this - 0xa0` / `this - 0xa4`. |

Local exported function JSON reports zero ordinary callers for the eight thunk bodies. For the four deleting destructors, the only code callers are the paired thunks; IDA xrefs also include the primary vtable data offsets. This is vtable/thunk reachability, not ordinary source call reachability.

### Shared Helper Identities

`0x00544580`: best source-facing name is `Pane::~Pane()`.

- [UID:0000MC] `Pane` documents `0x00544580-0x00544687` as the ordinary `Pane` destructor and rejects generated `TextButtonExControlPane` ownership pollution.
- [UID:0003CA] `PaneVtableData` and [UID:0000MC] list `Pane` constructor/destructor/scalar cleanup vtable refs around `0x006219e8`, `0x00621a34`, and `0x00621a64`.
- The generated report for `0x00544580` contains broad base-pane cleanup behavior: Pane vtable restoration, layer/event/timer detach, `LObject`/event dispatcher cleanup, and then base cleanup. It is not a `TextButtonExControlPane` destructor despite that generated label.

`0x004f4ac0`: best source-facing name is MemoryMan-backed global `operator delete(void*)` wrapper.

- [UID:000197] `OperatorDeleteWrapper` documents `0x004f4ac0-0x004f4b00` as a global deallocation wrapper owned by [UID:0000L7] `MemoryMan`.
- Its body calls `0x00516030` / `GetMemoryMan`, then `0x00516170` / `FreeBufferMemory` on the supplied block.
- The scalar deleting wrappers should not hand-call it in source; the compiler emits this call when the deleting-destructor flags request storage release.

`0x0041b6a0`: compiler guard helper used only on the no-free / guarded branch of the scalar deleting destructor pattern. It is not project source logic.

## Owner And Source Placement Ranking

1. [UID:0000OX] `UserCreateAppearanceControls` - accepted owner/emitter route. The four classes are old create-user appearance controls; [UID:0000OX] already owns the selector/control cluster [UID:0001A6], the exact class list, constructor xrefs from `CreateUserDialogPane::CreateUserDialogPane`, and the dense destructor/thunk support area. The aggregate has four class identities and no single class owner can own the whole page cleanly.
2. Four class pages - accepted as semantic declaration owners but not as the aggregate by-memory owner. Each class page should describe its own implicit/defaulted ordinary destructor identity and vtable wrapper, but the aggregate target should remain under the file-level [UID:0000OX] route.
3. [UID:0000IK] `CreateUserDialogs` / `CreateUserDialogPane` - rejected as direct owner. `CreateUserDialogPane` constructs the controls and coordinates them, but the controls have distinct class/vtable identities. `UserShapeSelectControlPane` is also reused by newer create-user paths, so direct old-dialog ownership is too narrow.
4. Generic `Pane` support - rejected as owner. `Pane::~Pane()` is the base destructor callee, but the vtable slots and destructor identities are the four create-user controls, not generic pane support.
5. No-owner/non-emitting fallback - rejected for metadata in this pass. The bodies are compiler-generated wrappers, but the page is still useful reconstructable source-declared/generated-binary evidence: it proves which source class destructors and vtable slots must exist. The correct fix is no formal C++ plus explicit generated-wrapper policy, not dropping the source route entirely.

## First-Draft C++ Recommendation / No-Code Proof

Do not populate the target's formal `RECONSTRUCTION_CPP` block.

Target-specific proof:

- The four bodies each have a compiler deleting-destructor parameter, return `this`, conditionally call `operator delete`, and use the compiler guard branch. This is MSVC scalar deleting destructor shape, not source-level destructor syntax.
- No body contains derived member cleanup, singleton clear, resource release, local helper call, or class-specific statement.
- The only project cleanup call is implicit base destruction through `Pane::~Pane()`.
- The generated/unrefined source output emits raw `virt_deldtor_*` wrappers and stale `TextButtonExControlPane` base calls. That output is not acceptable mid-2000s source shape.
- Emitting four empty out-of-line destructors would be a guess that the original source explicitly declared out-of-line bodies. The binary does not distinguish an explicitly empty destructor body from an implicit/defaulted derived destructor when the scalar deleting wrapper has no derived cleanup. Therefore no out-of-line body is safer and more source-faithful.

Source-facing declaration guidance for class/file support, not for the target's formal code block:

```cpp
// Declaration-level guidance only. Do not paste into 00022X formal C++.
// If explicit destructor declarations are needed for class readability or vtable documentation,
// keep them empty/defaulted and do not hand-write scalar deleting wrappers.
class UserCreatePreviewControlPane : public ControlPane {
public:
    virtual ~UserCreatePreviewControlPane() {}
};

class UserFaceSelectControlPane : public ControlPane {
public:
    virtual ~UserFaceSelectControlPane() {}
};

class UserHairSelectControlPane : public ControlPane {
public:
    virtual ~UserHairSelectControlPane() {}
};

class UserShapeSelectControlPane : public ControlPane {
public:
    virtual ~UserShapeSelectControlPane() {}
};
```

If the final reconstruction style omits explicit destructors when no class-specific cleanup exists, that is also defensible; the important requirement is that no scalar deleting wrapper or delete-flag parameter is hand-authored.

## Heuristic / Inference Reanalysis And Validation

### Compiler-Generated Names

Checked evidence:

- Generated reports for `0x00502d10`, `0x00502d50`, `0x00502d90`, and `0x00502dd0`.
- `unrefined-source-backup/source/UserCreatePreviewControlPane.cpp`, `UserFaceSelectControlPane.cpp`, `UserHairSelectControlPane.cpp`, and `UserShapeSelectControlPane.cpp`.
- [UID:0000MC] `Pane` and [UID:000197] `OperatorDeleteWrapper`.

Rejected alternatives:

- `virt_deldtor_0x502d10` / `virt_deldtor_0x502d50` / `virt_deldtor_0x502d90` / `virt_deldtor_0x502dd0` as source method names. These are generator/compiler labels.
- `TextButtonExControlPane::~TextButtonExControlPane` as the base cleanup name. The address is the shared ordinary `Pane::~Pane()`.
- `FUN_004f4ac0` or `sub_4F4AC0` as a project helper name. The documented behavior is global operator delete via MemoryMan.

Best defensible inference:

- Use source destructor identities only: `Class::~Class()`.
- Use `Pane::~Pane()` for `0x00544580`.
- Use MemoryMan-backed `operator delete(void*)` for `0x004f4ac0`.

Effect:

- Raises completion because helper/name blockers are resolved.
- Keeps C++ blank because the generated names describe compiler output, not source functions.

### Scalar Wrapper Versus Ordinary Source Destructor

Checked evidence:

- All four local function exports report size `59`, deleting-destructor method type, delete-flag parameter, and callees `0x00544580`, `0x004f4ac0`, `0x0041b6a0`.
- Generated bodies show delete-flag tests and `return this`.
- No target body contains derived cleanup.

Rejected alternatives:

- Emit raw wrappers in final C++: rejected because source code should not include deleting flags or guard-helper branch.
- Emit four out-of-line empty destructors: rejected as unnecessary and not proven. It may force a source shape the binary does not require.
- Mark the destructor identities unresolved: rejected because vtable slots and class names are strong.

Best defensible inference:

- The ordinary source destructors are implicit/defaulted or empty. The source declaration surface may mention them, but the by-memory target has no hand-authored body to emit.

Effect:

- Score can clear the current gate despite blank formal C++ because the blank is a positive no-code proof, not a stale threshold blocker.
- Supports `RECONSTRUCTABLE:TRUE` as source-declared/generated-binary evidence under [UID:0000OX].

### Vtable And Adjustor-Thunks

Checked evidence:

- [UID:0001AF] thunk page.
- Local function JSON for all eight thunks.
- `master_vtables.json` entries for primary, secondary, and tertiary tables.
- Cached primary vtable text for `0x0061dec4`, `0x0061de20`, `0x0061dd7c`, and `0x0061d564`.

Rejected alternatives:

- Ordinary call reachability from application logic: rejected. The only code refs are thunk forwards; the durable routes are vtable data refs.
- Treat thunks as source helpers: rejected. They are `this` adjustor wrappers for secondary/tertiary vtable views.

Best defensible inference:

- The four wrappers are virtual destructor targets for the primary views; the eight thunks support secondary/tertiary embedded pane/event-handler views at offsets `+0xa0` and `+0xa4`.

Effect:

- No split/range change required.
- [UID:0001AF] remains ignored/non-emitting.
- Target remains a useful class/vtable support page.

### Source Owner And File Placement

Checked evidence:

- [UID:0000OX] `UserCreateAppearanceControls`.
- [UID:0000IK] `CreateUserDialogs`.
- Four class pages.
- `auto-generated/-ag-memory-coverage.md`.
- Project-documentation generated output path `auto-generated/NexusTK/login/UserCreateAppearanceControls.cpp` exists but is empty.

Rejected alternatives:

- Direct `CreateUserDialogPane` ownership: too narrow because the controls are separate classes and `UserShapeSelectControlPane` is reused in create-user family paths.
- `Pane` ownership: only a base destructor dependency.
- No-owner fallback: too lossy; the page still proves source class declarations/vtables.

Best defensible inference:

- Keep target owner/emitter [UID:0000OX]. Use class pages for per-class declaration wording.

Effect:

- No owner/emitter metadata change.
- Support docs should clarify generated-wrapper policy and remove stale 95/95 wording.

### Score And C++ Readiness

Checked evidence:

- Current target is `84/88`, reconstructable, owner/emitter [UID:0000OX], blank C++.
- Current page says blank C++ is due to a stale `95/95` gate.
- Current supervisor rule uses the average-over-85 gate and allows target-specific no-code proof.

Rejected alternatives:

- Keep `84/88`: rejected because the helper-name, destructor-identity, and C++ policy blockers have been resolved.
- Inflate to high-final score: rejected because live IDA MCP was unavailable during this pass, raw byte strings were not locally available, and exact original "implicit vs explicitly empty inline destructor" source spelling cannot be proven.
- Reclassify to non-reconstructable/ignored: rejected because source declarations still need to account for the vtable destructor slots and class destructor identities.

Best defensible inference:

- `86/90` is the right target state: enough to pass the source-quality gate, capped because final declaration style and raw-byte live recheck remain non-final.

Effect:

- Formal C++ stays blank for a positive reason.
- Support and coverage wording should change so future agents do not reopen the stale threshold blocker.

## Exact Recommended Metadata Changes

For `by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md`:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep `RECONSTRUCTION_CPP CODE` blank.

No score/metadata change is required for [UID:0001AF], [UID:0000OX], [UID:0000IK], or the four class pages from this target alone. Their support text should be updated, but their broader field/method/source-quality blockers remain outside this narrow destructor cluster.

## Exact Support-Doc Changes For Supervisor Application

### Target Page

Replace `## Reconstruction Handling` body with:

```text
The formal C++ block should remain blank for target-specific source-shape reasons, not because of the stale `95/95` gate. The four bodies are MSVC scalar deleting destructor wrappers: each takes compiler delete flags, calls ordinary `Pane::~Pane()` at `0x00544580`, conditionally releases storage through the MemoryMan-backed global `operator delete` wrapper at `0x004f4ac0`, and returns `this`. No wrapper contains source-authored derived cleanup.

The source-facing destructors are `UserCreatePreviewControlPane::~UserCreatePreviewControlPane()`, `UserFaceSelectControlPane::~UserFaceSelectControlPane()`, `UserHairSelectControlPane::~UserHairSelectControlPane()`, and `UserShapeSelectControlPane::~UserShapeSelectControlPane()`. They should be represented by implicit/defaulted or empty declaration-level destructors on the class/file route if needed, while the compiler regenerates the scalar deleting wrappers and adjustor thunks. Do not emit raw `virt_deldtor_*` code or hand-call `operator delete` in source for this target.
```

Replace `## Score Rationale` body with:

```text
Completion/confidence should be `86/90`. Existing live-IDA notes and local exported function/vtable data confirm the exact four `0x3b` function objects, thunk and vtable routes, no ordinary callers, and documented padding. This B005 pass resolves the remaining source-quality blockers: `0x00544580` is ordinary `Pane::~Pane()`, `0x004f4ac0` is the MemoryMan-backed global `operator delete` wrapper, the generated `TextButtonExControlPane` base label is rejected as owner pollution, and the formal C++ block remains blank because the page is compiler wrapper evidence rather than a source-authored destructor body.

The score remains below final-audit quality because IDA MCP was unavailable for this pass, raw bytes are not available in local exports, and the exact original declaration spelling (implicit destructor versus explicitly empty inline destructor) cannot be proven from the wrapper bytes.
```

Append to `## Changes`:

```text
- 2026-06-19 B005 source-quality recheck:
  - Recommended change: raise from `84/88` to `86/90`, keep owner/emitter [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md), and keep the formal C++ block blank with a target-specific no-code proof.
  - Summary/evidence: local exported function/vtable data reconfirmed four `0x3b` deleting destructor objects, only paired adjustor-thunk code refs plus primary vtable refs, no ordinary callers, and identical callees. Support docs resolve `0x00544580` as ordinary `Pane::~Pane()` and `0x004f4ac0` as the MemoryMan-backed global `operator delete` wrapper. The four bodies contain no derived cleanup statements, so the source route should express implicit/defaulted ordinary destructors in class declarations and let the compiler regenerate the scalar deleting wrappers.
```

### UserCreateAppearanceAdjustorThunks Page

Replace the current ownership sentence:

```text
The scalar deleting destructors remain reconstructable owner methods. Only these `this`-adjusting wrappers are excluded from source reconstruction.
```

with:

```text
[UID:00022X][0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors](by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md) remains reconstructable source-declared/generated-binary evidence for the four class destructor identities, but its formal C++ should stay blank because the target bodies are scalar deleting wrappers with no source-authored derived cleanup. These `this`-adjusting wrappers remain excluded from source reconstruction.
```

### UserCreateAppearanceControls Page

Replace the dense destructor/thunk note currently ending with "while the scalar deleting destructors remain reconstructable" with:

```text
- The dense destructor/adjustor thunk area around [UID:0001AF][0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x00502600.UserCreateAppearanceAdjustorThunks.md) and [UID:00022X][0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors](by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md) is compiler destructor support for these controls and adjacent create-user panes; do not use the thunk pile as evidence for a separate source module. The adjustor range is excluded from source reconstruction through [UID:0000VN][-ignored](by-memory/-ignored.md). The scalar deleting destructor cluster remains attached to this file route as source-declared/generated-binary evidence for the four class destructor/vtable identities, but its formal C++ should stay blank because the wrappers contain no derived cleanup beyond implicit/defaulted destructors, base `Pane::~Pane()`, delete flags, and compiler guard/delete support.
```

### Four Class Pages

For each class page, replace the `destructor/thunks` Method Notes role with the corresponding sentence below.

`UserCreatePreviewControlPane.md`:

```text
Adjustor thunks are ignored compiler support; `0x00502d10` is the scalar deleting destructor wrapper for implicit/defaulted source destructor `UserCreatePreviewControlPane::~UserCreatePreviewControlPane()`. No derived cleanup body is proven; base `Pane::~Pane()`, delete flags, and `operator delete` are compiler/base output.
```

`UserFaceSelectControlPane.md`:

```text
Adjustor thunks are ignored compiler support; `0x00502d50` is the scalar deleting destructor wrapper for implicit/defaulted source destructor `UserFaceSelectControlPane::~UserFaceSelectControlPane()`. No derived cleanup body is proven; base `Pane::~Pane()`, delete flags, and `operator delete` are compiler/base output.
```

`UserHairSelectControlPane.md`:

```text
Adjustor thunks are ignored compiler support; `0x00502d90` is the scalar deleting destructor wrapper for implicit/defaulted source destructor `UserHairSelectControlPane::~UserHairSelectControlPane()`. No derived cleanup body is proven; base `Pane::~Pane()`, delete flags, and `operator delete` are compiler/base output.
```

`UserShapeSelectControlPane.md`:

```text
Adjustor thunks are ignored compiler support; `0x00502dd0` is the scalar deleting destructor wrapper for implicit/defaulted source destructor `UserShapeSelectControlPane::~UserShapeSelectControlPane()`. No derived cleanup body is proven; base `Pane::~Pane()`, delete flags, and `operator delete` are compiler/base output.
```

Optional evidence bullet to insert after the existing 2026-05-26 adjustor recheck note on each class page:

```text
- 2026-06-19 B005 source-quality recheck resolves the destructor-specific C++ policy: the deleting-destructor target is compiler wrapper evidence for an implicit/defaulted ordinary destructor, not a hand-authored source body. `0x00544580` is ordinary `Pane::~Pane()` and `0x004f4ac0` is the MemoryMan-backed global `operator delete` wrapper.
```

### CreateUserDialogs Page

No mandatory metadata or coverage update. If the supervisor wants to reduce stale source-split ambiguity, add this note after the old appearance-control starts evidence:

```text
- 2026-06-19 B005 destructor-cluster recheck keeps old appearance-control destructor evidence under [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md). `CreateUserDialogPane` constructs and coordinates the controls, but the scalar deleting destructor cluster [UID:00022X] is class/vtable support for the controls, not direct dialog-owned source logic.
```

## Exact Coverage Replacement

Do not edit `by-memory/-coverage-report.md` directly. Replace the current [UID:00022X] row at the `0x00502d10-0x00502e0b` placement between the `0x00502d05-0x00502d10` padding row and the `0x00502d4b-0x00502d50` padding row with:

```text
    - [UID:00022X][0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors](by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md) 0x00502d10-0x00502e0b | scalar deleting destructor cluster | UserCreateAppearanceScalarDeletingDestructors : reconstructable : 86% : very strong : B005 source-quality recheck resolves the four `0x3b` bodies as MSVC scalar deleting destructor wrappers for the implicit/defaulted destructors of `UserCreatePreviewControlPane`, `UserFaceSelectControlPane`, `UserHairSelectControlPane`, and `UserShapeSelectControlPane`: only thunk/vtable reachability, no ordinary callers, calls to `Pane::~Pane()` at `0x00544580`, delete/no-free flag handling through MemoryMan-backed `operator delete` wrapper `0x004f4ac0`, guard helper on the no-free branch, and byte-confirmed `0xcc` padding remain documented. Formal C++ should stay blank for this by-memory page; source declarations/defaulted destructors belong on the class/file support route, not as hand-authored wrapper code.
```

No by-class or by-file coverage row replacement is required from this destructor-cluster pass alone.

## Validation Commands Run

- `Invoke-WebRequest` JSON-RPC probe to `http://127.0.0.1:13337/mcp` - failed, IDA MCP unavailable.
- `Get-Content` for target/support docs: target page, [UID:0001AF], [UID:0000OX], [UID:0000IK], four class pages, [UID:0000MC], [UID:000197].
- Local function export checks for `0x00502d10`, `0x00502d50`, `0x00502d90`, `0x00502dd0`, eight thunks, `0x00544580`, `0x004f4ac0`, and `0x0041b6a0`.
- Generated code checks under `re-agent/reports/code` for the four wrappers, thunk examples, `0x00544580`, and `0x004f4ac0`.
- Vtable checks from `hooks-generation/cached/vtable` and `resources/exported_data/master_vtables.json`.
- Coverage row lookup in `by-memory/-coverage-report.md` and generated route lookup in `auto-generated/-ag-memory-coverage.md`.

## Changed Files

- `tools/leaser/Agents/Agent-B005/research/00022X-UserCreateAppearanceScalarDeletingDestructors-source-quality.md` - new report only.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/00022X-UserCreateAppearanceScalarDeletingDestructors-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"00022X"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
