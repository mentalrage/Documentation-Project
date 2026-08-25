** TARGET-REPORT-UID:0002IQ **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002IQ KeySpeedMgr Destructor Source-Quality Report

Assignment: `B003-goal2-keyspeedmgr-destructor-source-quality-0002IQ-20260618`  
Target: [UID:0002IQ] `by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md`  
Current state: `COMPLETION:83`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00006Z`, `EMITTER_UIDS:00006Z`, formal C++ blank.

## Finalized Report / Current Recommendation

Recommend updating [UID:0002IQ] to `COMPLETION:87`, `CONFIDENCE:92`, with owner/emitter unchanged as [UID:00006Z] `KeySpeedMgr`. The target is an ordinary non-deleting destructor body for `KeySpeedMgr::~KeySpeedMgr`, not a dead function and not the scalar deleting destructor. It should receive first-draft formal C++ scoped to the source-authored destructor body:

```cpp
KeySpeedMgr::~KeySpeedMgr()
{
    g_pKeySpeedMgr = 0;
}
```

The binary body also restores the `KeySpeedMgr` vptr and tail-jumps to `LObject` base cleanup, but those are compiler-emitted destructor mechanics and should not be written as explicit source statements. The scalar deleting destructor at `0x004effc0` remains the vtable slot target and should remain non-formal/source-wrapper evidence unless a future policy explicitly emits compiler deleting-destructor wrappers.

No range split, merge, owner change, or non-reconstructable reclassification is recommended.

## Evidence Checked

Read current assignment/rules:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B003/goal.md`
- `tools/leaser/Agents/Agent-B003/notes.md`
- `by-structure.md`
- `inference_research.md`

Read target and support docs:

- [UID:0002IQ] `by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md`
- [UID:00006Z] `by-class/KeySpeedMgr.md`
- [UID:0000KJ] `by-file/KeySpeedMgr.md`
- [UID:00018O] `by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md`
- [UID:0002IP] `by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md`
- [UID:0002IR] `by-memory/0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md`
- [UID:00018P] `by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md`
- [UID:0002IS] `by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md`
- [UID:00018Q] `by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md`
- [UID:0002IT] `by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md`
- [UID:0001UV] `by-type/by-struct/KeySpeedMgrLayout.md`
- [UID:0001XX] `by-type/by-vtable/KeySpeedMgrVtable.md`
- [UID:0000RB] `by-global/g_pKeySpeedMgr.md`
- [UID:0001P7] `by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md`
- [UID:00032A] `by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md`
- `project-level/-auto-completion-stats.md`
- `by-memory/-coverage-report.md`
- `auto-generated/by-memory-tool-report.md`
- `project-documentation/auto-generated/NexusTK/input/KeySpeedMgr.cpp`
- `simroot_v2/class_KeySpeedMgr.cpp`
- `simroot_v2/class_KeySpeedMgr.cpp.disabled`
- `simroot_v2/class_KeySpeedMgr.cpp.source_map.json`
- `core/data/readonly/wave2/classes/KeySpeedMgr.json`

Tooling status:

- IDA MCP is not exposed in this session. `list_mcp_resources` and `list_mcp_resource_templates` both returned empty lists. A direct probe of `http://127.0.0.1:13337/mcp` timed out after two seconds. I therefore used existing IDA-backed documentation plus raw PE parsing and Capstone disassembly.
- Raw executable checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Active generated `project-documentation/auto-generated/NexusTK/input/KeySpeedMgr.cpp` is length `0`, last written `2026-05-31 09:26:16`; it does not currently assemble any KeySpeedMgr code.
- Older `simroot_v2/class_KeySpeedMgr.cpp` contains a generated scalar deleting destructor body with explicit `m_vtable`, `LObject::~LObject`, `operator_delete`, and `nullptr` artifacts. That output is useful as historical evidence of the destructor family, but it should not be copied into formal source.

Raw PE/Capstone facts checked on 2026-06-18:

- `0x004efedd-0x004efee0`: `cc cc cc`, three-byte alignment before the destructor.
- `0x004efee0-0x004efef5`: `c7 01 c8 c9 61 00 c7 05 48 ab 67 00 00 00 00 00 e9 9b 4b 00 00`, exactly 21 bytes.
- Disassembly:

```asm
004efee0  mov dword ptr [ecx], 0x61c9c8
004efee6  mov dword ptr [0x67ab48], 0
004efef0  jmp 0x4f4a90
```

- `0x004efef5-0x004eff00`: eleven `0xcc` bytes before `KeySpeedMgr::LoadSystemKeyboardSettings`.
- Successor `0x004eff00-0x004eff25` bytes decode to `LoadSystemKeyboardSettings`, with two `SystemParametersInfoW` calls and a plain `ret`.
- Scalar deleting destructor `0x004effc0-0x004f0008` starts with a frame, stores the same `0x0061c9c8` vptr, clears `0x0067ab48`, calls `0x004f4a90`, checks delete flags, calls `0x004f4ac0` when `(flags & 1) != 0 && (flags & 4) == 0`, has a guard-check branch for flag `4`, and returns with `ret 4`.
- Vtable data `0x0061c9c4-0x0061c9dc` is:

```text
0x0061c9c4: 0x00649820  RTTI complete-object locator
0x0061c9c8: 0x004effc0  scalar deleting destructor
0x0061c9cc: 0x004f4b10  inherited LObject identity/name slot
0x0061c9d0: 0x0041b6c0  inherited/default no-op callback slot
0x0061c9d4: 0x00000400  non-code constant
0x0061c9d8: 0x00000400  non-code constant
```

Route scans:

- No `E8`/`E9` rel32 refs to `0x004efee0`.
- No little-endian `0x004efee0` VA hits, no `0x000efee0` RVA hits, and no file-offset pointer hits to the ordinary destructor start.
- No `E8`/`E9` rel32 refs to `0x004effc0`; the scalar deleting destructor is reached through the vtable data pointer at `0x0061c9c8`.
- One little-endian hit for `0x004effc0`: `0x0061c9c8` in `.rdata`.
- Three little-endian hits for `0x0061c9c8`: constructor store at `0x004efecd`, ordinary destructor store at `0x004efee2`, scalar deleting destructor store at `0x004effc8`.
- Ten little-endian hits for `0x0067ab48`: `0x00464af8`, `0x00464b06`, `0x00466a1c`, `0x00466ad3`, `0x004673c2`, `0x004ab835`, `0x004efebf`, `0x004efee8`, `0x004effce`, and `0x004f5ede`.

## Target Inventory

| Item | Decision |
| --- | --- |
| Exact range | Keep `0x004efee0-0x004efef5`; exact body is 21 bytes. |
| Predecessor padding | `0x004efedd-0x004efee0`, three `0xcc` bytes after [UID:0002IP] constructor. |
| Successor padding | `0x004efef5-0x004eff00`, eleven `0xcc` bytes before [UID:0002IR] load method. |
| Function identity | Ordinary non-deleting destructor variant for `KeySpeedMgr::~KeySpeedMgr`. |
| Calling convention | `__thiscall`, `ecx == this`; no stack arguments; source return type is `void`. |
| Callees | No normal `call`; final instruction is a tail `jmp 0x004f4a90`, the `LObject` base destructor/cleanup. Existing wording saying "calls" should be corrected to "tail-jumps/chains". |
| Direct callers | None found by current docs or raw rel32 scan. |
| Data/pointer refs to target | None found for VA, RVA, or file-offset representation of `0x004efee0`. |
| Vtable route | Vtable slot `0x0061c9c8` points to [UID:0002IT] scalar deleting destructor, not this ordinary destructor. |
| Source route | Source family route through the `KeySpeedMgr` class destructor; VC++ emits ordinary and scalar deleting destructor variants from the same source destructor. |

## Heuristic / Inference Reanalysis And Validation

### Source-facing name and signature

Best source-facing name/signature: `KeySpeedMgr::~KeySpeedMgr()`.

Evidence:

- [UID:00006Z] class page lists this range as the destructor, between constructor `0x004efea0-0x004efedd` and load method `0x004eff00-0x004eff25`.
- [UID:00018O] aggregate brackets it as the non-deleting destructor body with clean `0xcc` padding on both sides.
- Raw bytes match a destructor variant: restore current class vptr, clear singleton global, then chain to base destructor cleanup.
- [UID:0002IT] is the paired scalar deleting destructor. It duplicates the vptr/global/base cleanup sequence and adds delete-flag handling, which is the expected MSVC virtual destructor family shape.
- The source destructor's return type should be `void`; generated/decompiler return of `this` belongs to deleting-wrapper lowering, not source.

Rejected alternatives:

- `DestroyKeySpeedMgr`: rejected. [UID:00032A] is a separate WinMain early-exit cleanup wrapper at `0x004673c0` that reads `g_pKeySpeedMgr` and dispatches the vtable deleting destructor with flag `1`. It is a consumer, not the class destructor body.
- `KeySpeedMgr::ScalarDeletingDestructor`: rejected for this target. The vtable slot points to `0x004effc0`, not `0x004efee0`, and the scalar wrapper has a stack delete flag and conditional delete path absent from this body.
- `KeySpeedMgr::RestoreSystemKeyboardSettings` or keyboard-setting helper naming: rejected. This body has no `SystemParametersInfoW` calls and no `+0x04/+0x08` field reads; it only clears singleton state and chains to base cleanup.
- File-local helper: rejected. The body writes through `ecx` as an object, uses the class vptr, and is part of the constructor/destructor/vtable family.

### `g_pKeySpeedMgr` name, type, and source role

Best source-facing type/name remains `KeySpeedMgr* g_pKeySpeedMgr`.

Evidence:

- [UID:0000RB] and [UID:0001P7] document `0x0067ab48-0x0067ab4c` as the singleton pointer.
- Constructor stores `this` to `0x0067ab48`; ordinary destructor and scalar deleting destructor both clear it.
- Startup/cleanup callers read this global before loading/restoring/applying keyboard settings or deleting the singleton.
- Raw scan found exactly ten little-endian references to `0x0067ab48`, matching the support-doc xref family.
- Active simroot/source-map evidence already names the storage `g_pKeySpeedMgr` and maps it to `KeySpeedMgr*`.

Rejected alternatives:

- `dword_67AB48`: rejected as a decompiler placeholder; type and singleton role are now documented.
- `g_pInputMan` or other input-manager ownership: rejected. `InputMan` handles message/IME input; this global's writes and field semantics are isolated to KeySpeedMgr keyboard repeat state.
- WinMain-owned global: rejected. [UID:00032A] reads it from WinMain cleanup, but constructor/destructor/global storage ownership is KeySpeedMgr.

Remaining uncertainty:

- Exact original linkage spelling (`KeySpeedMgr* g_pKeySpeedMgr`, `static KeySpeedMgr* g_pKeySpeedMgr`, or an anonymous-file global) is not proven by binary evidence. This does not block the destructor C++ body because all known docs already use `g_pKeySpeedMgr` and the target only assigns zero.

### KeySpeedMgr layout and keyboard-setting fields

Best layout:

```cpp
class KeySpeedMgr : public LObject {
    UINT m_savedKeyboardDelay; // +0x04
    UINT m_savedKeyboardSpeed; // +0x08
};
```

Evidence:

- Allocation size is `0x0c`.
- Constructor initializes `+0x04` and `+0x08` to `0xffffffff`, an invalid sentinel for unsigned keyboard settings.
- `LoadSystemKeyboardSettings` passes `this+0x04` to `SPI_GETKEYBOARDDELAY` and `this+0x08` to `SPI_GETKEYBOARDSPEED`.
- `RestoreSystemKeyboardSettings` restores delay only when `<= 3` and speed only when `<= 31`, matching documented Windows keyboard repeat ranges.
- File-local fast-repeat helpers set delay `0` and speed `31` without touching object state.

Rejected alternatives:

- Active/current settings fields: rejected. They are loaded from the system at startup and later restored; file-local helpers apply active settings separately.
- Generic `m_keyboardDelay`/`m_keyboardSpeed` without "saved": weaker than `m_savedKeyboardDelay`/`m_savedKeyboardSpeed` because the fields represent the user's pre-launch settings, not necessarily the active fast-repeat values.
- `int` with negative semantics: rejected for source role. The sentinel is `UINT(-1)`/invalid setting, while valid ranges are non-negative Win32 `UINT` values.

Impact on target:

- The destructor does not touch these fields, so their final spelling does not block formal destructor C++. They support the class/source placement and singleton lifecycle.

### Vtable store and `LObject` base cleanup

Best interpretation:

- `mov [ecx], 0x0061c9c8` at `0x004efee0` is compiler-emitted vptr reset for the current class during destruction.
- `jmp 0x004f4a90` at `0x004efef0` is compiler-emitted tail chaining to `LObject` base destructor/cleanup.
- Neither should appear as an explicit statement in formal source.

Evidence:

- The same vptr write appears in the constructor and scalar deleting destructor.
- [UID:0001XX] confirms `0x0061c9c8` is the RTTI-backed `KeySpeedMgr` primary vtable.
- [UID:0002IT] scalar deleting destructor calls the same `0x004f4a90` base cleanup after clearing the singleton.
- Existing generated simroot code was penalized for explicit `LObject::~LObject` and vtable/delete artifacts, confirming this is not desired source-shaped output.

Rejected alternatives:

- Handwritten `this->m_vtable = &KeySpeedMgr_vtable;`: rejected as compiler vptr restoration, not project source.
- Explicit `LObject::~LObject(...)` in `KeySpeedMgr::~KeySpeedMgr`: rejected. Base destructor chaining is implicit in C++ destructors; older generated output shows this is a reconstruction artifact.
- Treating `0x004f4a90` as a KeySpeedMgr helper: rejected. It is a broad `LObject` cleanup target with hundreds of code refs and is used by many destructor bodies.

### Destructor reachability and no-direct-caller meaning

Best interpretation:

- No direct caller to `0x004efee0` means the ordinary destructor variant is not currently reached by a direct call or vtable slot in the saved binary.
- This does not make it dead source. It is the ordinary destructor variant emitted as part of the `KeySpeedMgr` virtual destructor family. Runtime deletion uses [UID:0002IT] through vtable slot zero, and [UID:00032A] invokes that deleting destructor indirectly from WinMain cleanup.

Evidence:

- Raw scan found no rel32 refs and no VA/RVA/raw-pointer hits to `0x004efee0`.
- Vtable slot `0x0061c9c8` points to `0x004effc0`, the scalar deleting destructor.
- The scalar deleting destructor duplicates this ordinary destructor's singleton clear/base cleanup, then handles delete flags.
- Existing IDA-backed target doc also reports no direct callers.

Rejected alternatives:

- Dead/unused unrelated code: rejected. The body is bounded in the KeySpeedMgr method island, writes the KeySpeedMgr vptr, clears the KeySpeedMgr singleton, and matches the paired scalar deleting destructor.
- Hidden jump table/vtable/table route to this exact start: not found. The only vtable route is to the scalar deleting destructor. No hidden route is needed to justify source C++ because C++ source defines the destructor, while the compiler can emit multiple variants.

Score impact:

- No direct runtime ref prevents a near-final `95+` confidence claim for reachability. It does not cap the target below 85 or block formal source-shaped destructor C++.

### Owner and source placement

Ranking:

1. [UID:00006Z] `KeySpeedMgr` class, emitted through [UID:0000KJ] `KeySpeedMgr.cpp` - selected.
   - For: vptr store, class vtable, singleton lifecycle, constructor/destructor/scalar destructor family, and layout docs all point to the class.
   - Against: no direct caller to ordinary destructor, but this is normal for an emitted ordinary destructor variant.
2. [UID:0000KJ] `KeySpeedMgr.cpp` file-local helper - rejected as direct owner.
   - For: physical file island and global storage are file-level.
   - Against: object `this` and vptr make this a class destructor, not a plain file helper.
3. [UID:0000PA] `WinMain` - rejected.
   - For: WinMain has a cleanup wrapper that deletes the singleton.
   - Against: that wrapper is [UID:00032A], a consumer of `g_pKeySpeedMgr`; it does not own the class destructor.
4. [UID:0000HG] `Application` / startup lifecycle - rejected.
   - For: Application startup constructs and uses the singleton.
   - Against: construction/destruction semantics and vtable belong to KeySpeedMgr; Application only calls into the manager and restore helpers.
5. [UID:0000K6] `InputMan` or a generic platform helper - rejected.
   - For: keyboard repeat is input-adjacent.
   - Against: support docs already distinguish KeySpeedMgr as a system keyboard repeat manager, separate from input message handling.

## Existing Documentation Comparison And Stale/Open Questions

Validated current target docs:

- Exact half-open range `0x004efee0-0x004efef5` is correct.
- Owner/emitter [UID:00006Z] is correct.
- `g_pKeySpeedMgr` clear and `0x0061c9c8` vptr store are correct.
- Non-deleting destructor classification is correct.
- Separation from [UID:0002IT] scalar deleting destructor is correct.

Corrections/updates needed:

- Target raw evidence says the destructor "calls `sub_4F4A90(this)` at `0x004efef0`"; raw bytes show `jmp 0x004f4a90`. Use "tail-jumps/chains to `LObject` base cleanup".
- Target reconstruction notes still defer formal C++ to a stale high threshold. Current code-entry policy permits source-shaped draft C++ because the target is reconstructable, routed to a nonblank emitter, and has average score above 85.
- Coverage row still says "blank final C++ below the source gate"; replace with the source-shaped destructor recommendation.
- Support docs can clarify that [UID:0002IT] scalar deleting destructor remains compiler wrapper evidence and should not be emitted as separate hand-authored source.

No open question remains that blocks 85/85+ or first-draft C++. Remaining non-blocking uncertainties are exact original null literal (`0` vs `NULL`) and exact storage linkage declaration for `g_pKeySpeedMgr`; both affect final style polish, not target behavior/source placement.

## Recommended Metadata And Score Changes

Target [UID:0002IQ]:

- `COMPLETION:87`
- `CONFIDENCE:92`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:00006Z`
- `EMITTER_UIDS:00006Z`
- `EMITTER_POSITION_OPTIONAL:` unchanged blank
- Populate formal C++ with the ordinary destructor body shown below.

Rationale:

- Completion rises because the report resolves stale C++ gating, corrects call-vs-tail-jump wording, records hidden route checks, documents no-direct-caller meaning, and provides source-shaped C++.
- Confidence rises because raw PE evidence independently confirms exact bytes, padding, vptr/global refs, vtable route, and negative pointer/ref scans.
- Confidence should not be raised to `95+` because live IDA MCP was unavailable in this session, the exact original null spelling/linkage is unrecovered, and the ordinary destructor start has no direct runtime route in the saved binary.

No owner/emitter change is recommended.

## First-Draft C++ Recommendation

Populate [UID:0002IQ] formal C++ with:

```cpp
KeySpeedMgr::~KeySpeedMgr()
{
    g_pKeySpeedMgr = 0;
}
```

Why this is source-shaped:

- It represents only the user-authored destructor body effect: clearing the singleton pointer when the `KeySpeedMgr` object is destroyed.
- It omits explicit vptr writes, explicit base destructor calls, and scalar deleting destructor/delete flag logic because those are compiler output.
- It uses `0` rather than `nullptr` to fit a mid-2000s C++ codebase and avoid the known generated-output penalty for modern `nullptr`.
- It keeps the target scoped exactly to `0x004efee0-0x004efef5`; it does not absorb [UID:0002IT] or any file-local keyboard-repeat helpers.

Optional source context for support docs/generated header work, not part of this target's formal body:

```cpp
extern KeySpeedMgr* g_pKeySpeedMgr;

class KeySpeedMgr : public LObject {
public:
    KeySpeedMgr();
    virtual ~KeySpeedMgr();

    void LoadSystemKeyboardSettings();
    void RestoreSystemKeyboardSettings();

private:
    UINT m_savedKeyboardDelay;
    UINT m_savedKeyboardSpeed;
};
```

Do not populate [UID:0002IT] with separate source C++ as `ScalarDeletingDestructor`; it should be produced by the compiler from `virtual ~KeySpeedMgr()`.

## Exact Supervisor Changes Required

### Target Header

In `by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md`, replace:

```text
*** COMPLETION:83 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

with:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Leave owner/emitter metadata unchanged.

### Target Formal C++

In `by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md`, replace the empty reconstruction block:

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

with:

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
KeySpeedMgr::~KeySpeedMgr()
{
    g_pKeySpeedMgr = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Target Function Row

In the target `## Function` table, replace the existing row:

```markdown
| `0x004efee0-0x004efef5` | `KeySpeedMgr::~KeySpeedMgr` | Restores the class vtable, clears `g_pKeySpeedMgr`, and calls the `LObject` base destructor/cleanup. |
```

with:

```markdown
| `0x004efee0-0x004efef5` | `KeySpeedMgr::~KeySpeedMgr` | Compiler-emitted ordinary destructor variant: restores the class vptr, clears `g_pKeySpeedMgr`, and tail-jumps to `LObject` base cleanup. Formal source should contain only the singleton clear; vptr restoration and base cleanup are implicit destructor emission. |
```

### Target Raw Evidence Insert

In the target `## Raw Evidence` section, after the existing 2026-05-31 bullets and before `## 2026-06-06 Live IDA Refresh`, insert:

```markdown
- 2026-06-18 B003 raw PE check on `NexusTK.exe` SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632` confirms exact body bytes `c7 01 c8 c9 61 00 c7 05 48 ab 67 00 00 00 00 00 e9 9b 4b 00 00`.
- Capstone disassembly decodes the body as `mov dword ptr [ecx], 0x61c9c8`; `mov dword ptr [0x67ab48], 0`; `jmp 0x4f4a90`. The final instruction is a tail jump to `LObject` cleanup, not a normal call/return pair.
- Raw route scan found no `E8`/`E9` rel32 refs and no little-endian VA/RVA/file-offset pointer hits to `0x004efee0`; the paired scalar deleting destructor is instead referenced through vtable slot `0x0061c9c8 -> 0x004effc0`.
- The same raw scan found the three expected vtable-address immediates for `0x0061c9c8` at constructor `0x004efecd`, ordinary destructor `0x004efee2`, and scalar deleting destructor `0x004effc8`, plus ten singleton-address references to `0x0067ab48`, matching the documented `g_pKeySpeedMgr` lifecycle.
```

### Target Reconstruction Notes Replacement

Replace the target `## Reconstruction Notes` section with:

```markdown
## Reconstruction Notes

- This is the ordinary source destructor for [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md). Keep it separate from the scalar deleting destructor at `0x004effc0`.
- Formal source should be `KeySpeedMgr::~KeySpeedMgr() { g_pKeySpeedMgr = 0; }`. The binary vptr store and tail jump to `LObject` cleanup are compiler-emitted destructor mechanics and should not appear as explicit source statements.
- No direct code callers or pointer refs to `0x004efee0` are currently known. This does not make the target dead: runtime deletion uses [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) through the `0x0061c9c8` vtable slot, while this ordinary destructor remains the source-authored destructor body emitted by the compiler.
```

### Target Change Log Insert

Add this at the top of the target `## Changes` section:

```markdown
### 2026-06-18 B003 source-quality recheck

- Changed recommendation from `83/90`, blank formal C++, to `87/92` with first-draft ordinary destructor C++.
- Evidence: raw PE/Capstone recheck confirmed the exact 21-byte body, `0xcc` padding before and after, vptr store to `0x0061c9c8`, clear of `g_pKeySpeedMgr` at `0x0067ab48`, and tail jump to `0x004f4a90` `LObject` cleanup. Route scans found no direct rel32 or VA/RVA/raw-pointer refs to the ordinary destructor start; scalar deleting destructor reachability remains through vtable slot `0x0061c9c8 -> 0x004effc0`.
- Source decision: emit only the source destructor body `g_pKeySpeedMgr = 0;`; leave vptr reset, base cleanup, delete flag handling, and guard-check behavior to compiler-generated ordinary/scalar destructor emission.
```

### KeySpeedMgr Class Support Rows

In `by-class/KeySpeedMgr.md`, replace the two method inventory rows:

```markdown
| [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) | `0x004efee0-0x004efef5` | Clears singleton and destroys `LObject` base. |
| [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) | `0x004effc0-0x004f0008` | Clears singleton, destroys base, optionally frees memory. |
```

with:

```markdown
| [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) | `0x004efee0-0x004efef5` | Ordinary `~KeySpeedMgr` source destructor; formal source body clears `g_pKeySpeedMgr`, while the vptr store and `LObject` base cleanup are compiler-emitted destructor mechanics. |
| [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) | `0x004effc0-0x004f0008` | Compiler-emitted scalar deleting destructor wrapper referenced by the vtable; duplicates singleton clear/base cleanup and conditionally frees memory, but should not be emitted as a separate source-authored method. |
```

### KeySpeedMgr File Support Rows

In `by-file/KeySpeedMgr.md`, replace the two proposed-content rows:

```markdown
| [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) | `0x004efee0-0x004efef5` | Ordinary destructor body that clears the singleton slot and runs base cleanup. |
| [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) | `0x004effc0-0x004f0008` | Scalar deleting destructor wrapper referenced by the vtable. |
```

with:

```markdown
| [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) | `0x004efee0-0x004efef5` | Ordinary `~KeySpeedMgr` source destructor; source body clears `g_pKeySpeedMgr`, with vptr restoration and `LObject` base cleanup emitted by the compiler. |
| [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) | `0x004effc0-0x004f0008` | Compiler-emitted scalar deleting destructor wrapper referenced by the vtable; keep as wrapper evidence rather than separate formal source. |
```

### Scalar Deleting Destructor Support Notes

In `by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md`, replace the `## Reconstruction Notes` section with:

```markdown
## Reconstruction Notes

- This wrapper is emitted because `KeySpeedMgr` has a virtual destructor. It should be generated from the class declaration and [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md), not hand-authored as ordinary source.
- Keep the ordinary destructor body at [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) separate from this wrapper.
- Do not emit formal C++ for this page under normal source reconstruction policy. The wrapper's vptr store, duplicated singleton clear, base cleanup call, delete flag handling, optional heap free, and guard-check branch are compiler/destructor-support output.
```

## Coverage Report Replacement Text

In `by-memory/-coverage-report.md`, replace the current [UID:0002IQ] row at the `0x004efedd-0x004eff00` KeySpeedMgr region:

```markdown
        - [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) 0x004efee0-0x004efef5 | destructor | KeySpeedMgr::~KeySpeedMgr : reconstructable : 83% : strong : Live IDA confirms exact ordinary destructor bounds, no direct code callers, `KeySpeedMgr` vtable restore, `g_pKeySpeedMgr` clear, base cleanup behavior, class parent attachment, and blank final C++ below the source gate.
```

with:

```markdown
        - [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) 0x004efee0-0x004efef5 | destructor | KeySpeedMgr::~KeySpeedMgr : reconstructable : 87% : strong : Raw PE/Capstone recheck confirms exact 21-byte ordinary destructor body, `0xcc` padding before and after, `0x0061c9c8` vptr store, `g_pKeySpeedMgr` clear, and tail jump to `LObject` cleanup; route scans found no rel32/VA/RVA/raw-pointer refs to the ordinary destructor start, while scalar deletion is reached through vtable slot `0x0061c9c8 -> 0x004effc0`. B003 recommends formal source body `g_pKeySpeedMgr = 0;`, leaving vptr/base cleanup/delete-wrapper behavior to compiler emission.
```

No generated stats or generated source files should be edited directly. The `project-level/-auto-completion-stats.md` row for [UID:0002IQ] should disappear or refresh only after supervisor-owned documentation/application tooling updates the target score.

## Remaining Blockers

No blocker remains for 85/85+, owner/emitter, source placement, or first-draft C++.

Residual non-blocking items:

- Exact original null spelling is not recoverable from binary evidence. Use `0` in the draft because it matches older C++ style and avoids modern `nullptr`; `NULL` would also be source-plausible but is not proven.
- Exact declaration linkage for `g_pKeySpeedMgr` is not proven (`extern` plus single definition versus file-local linkage). Existing support docs and generated source use `KeySpeedMgr* g_pKeySpeedMgr`; this is sufficient for the destructor body.
- IDA MCP was unavailable in this session, so this report relies on current IDA-backed docs plus raw PE/Capstone verification. This caps confidence below near-final `95+`, but does not block the recommendation.
- No direct runtime route to `0x004efee0` is known. This is documented and interpreted as an ordinary destructor variant emitted from source, with runtime deletion going through [UID:0002IT] scalar deleting destructor.

## Validation Commands

Commands run for this report:

> Executable block R001 was removed from this report and preserved verbatim in [0002IQ-KeySpeedMgrDestructor-source-quality-removed.md](0002IQ-KeySpeedMgrDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Raw PE/Capstone check used an inline read-only Python script to parse PE sections, disassemble `0x004efee0`, `0x004effc0`, `0x004673c0`, and `0x004efea0`, scan rel32 refs, scan VA/RVA/file-offset pointer representations, and print the vtable dwords at `0x0061c9c4-0x0061c9dc`.

Recommended supervisor validation after applying changes:

> Executable block R002 was removed from this report and preserved verbatim in [0002IQ-KeySpeedMgrDestructor-source-quality-removed.md](0002IQ-KeySpeedMgrDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002IQ-KeySpeedMgrDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002IQ"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002IQ-KeySpeedMgrDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002IQ-KeySpeedMgrDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002IQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
