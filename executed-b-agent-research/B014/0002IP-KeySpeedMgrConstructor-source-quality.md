** TARGET-REPORT-UID:0002IP **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002IP KeySpeedMgr Constructor Source-Quality Report

Assignment: `Agent-B014` source-quality / heuristic research for [UID:0002IP] `KeySpeedMgrConstructor`  
Target: `source-3/project-documentation/by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md`  
Current state checked: `COMPLETION:84`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00006Z`, `EMITTER_UIDS:00006Z`, formal C++ blank.

## Final Recommendation

Recommend updating [UID:0002IP] to `COMPLETION:88`, `CONFIDENCE:92`, with owner/emitter unchanged as [UID:00006Z] `KeySpeedMgr`.

The target is first-draft C++ ready under the current active gate. It is reconstructable, has a nonblank source route through [UID:00006Z] to [UID:0000KJ] `NexusTK/input/KeySpeedMgr.cpp`, and the recommended combined score is above 85. The stale "blank final C++ below the 95/95 source gate" rationale should be removed.

Recommended formal C++:

```cpp
KeySpeedMgr::KeySpeedMgr()
{
    g_pKeySpeedMgr = this;
    m_savedKeyboardDelay = UINT(-1);
    m_savedKeyboardSpeed = UINT(-1);
}
```

Do not copy the old generated constructor shape. In particular, do not emit `KeySpeedMgr*` return type, `return this`, explicit `LObject::LObject()` as a body statement, explicit vtable stores, raw `0xFFFFFFFF` literals, the `this == reinterpret_cast<KeySpeedMgr*>(-4)` null-adjust artifact, `mbr_0x4`/`mbr_0x8`, or `dword_67AB48`.

## Evidence Checked

Instruction/rule documents:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B014/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`

Target/support documents:

- [UID:0002IP] `by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md`
- [UID:00006Z] `by-class/KeySpeedMgr.md`
- [UID:0000KJ] `by-file/KeySpeedMgr.md`
- [UID:00018O] `by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md`
- [UID:0002IQ] `by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md`
- [UID:0002IR] `by-memory/0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md`
- [UID:00018P] `by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md`
- [UID:0002IS] `by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md`
- [UID:00018Q] `by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md`
- [UID:0002IT] `by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md`
- [UID:0001UV] `by-type/by-struct/KeySpeedMgrLayout.md`
- [UID:0001XX] `by-type/by-vtable/KeySpeedMgrVtable.md`
- [UID:00031P] `by-memory/0x0061c9c4-0x0061c9dc.KeySpeedMgrVtableData.md`
- [UID:0000RB] `by-global/g_pKeySpeedMgr.md`
- [UID:0001P7] `by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md`
- [UID:00032A] `by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md`
- `source-3/project-documentation/auto-generated/NexusTK/input/KeySpeedMgr.cpp`
- `source-3/simroot_v2/class_KeySpeedMgr.cpp`
- `source-3/simroot_v2/class_KeySpeedMgr.cpp.disabled`
- `source-3/simroot_v2/class_KeySpeedMgr.cpp.source_map.json`
- `source-3/core/data/readonly/wave2/classes/KeySpeedMgr.json`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/executed/0002IQ-KeySpeedMgrDestructor-source-quality.md`
- `source-3/project-documentation/by-memory/-coverage-report.md`
- `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`
- `source-3/project-documentation/project-level/-auto-completion-stats.md`
- `source-3/project-documentation/project-level/-unresolved.md`

Tooling status:

- `list_mcp_resources` and `list_mcp_resource_templates` returned empty lists.
- Direct probe of `http://127.0.0.1:13337/mcp` timed out after two seconds. Live IDA MCP was therefore not available in this session.
- Existing IDA-backed docs and local IDA exports were used, plus a read-only raw PE/Capstone check.
- Raw executable checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- `int_convert.py` verified `0x3d` as 61 bytes, `0x0c` as 12 bytes, and `0x1f` as 31.

Raw PE/Capstone facts checked on 2026-06-19:

- Constructor bytes `0x004efea0-0x004efedd`, 61 bytes:

```text
55 8b ec 51 56 8b f1 89 75 fc e8 d1 4b 00 00 8d 46 04 85 c0 74 05 8d 48 fc eb 02 33 c9 89 0d 48 ab 67 00 c7 00 ff ff ff ff 8b c6 c7 06 c8 c9 61 00 c7 46 08 ff ff ff ff 5e 8b e5 5d c3
```

- Disassembly:

```asm
004efea0  push ebp
004efea1  mov ebp, esp
004efea3  push ecx
004efea4  push esi
004efea5  mov esi, ecx
004efea7  mov dword ptr [ebp - 4], esi
004efeaa  call 0x4f4a80
004efeaf  lea eax, [esi + 4]
004efeb2  test eax, eax
004efeb4  je 0x4efebb
004efeb6  lea ecx, [eax - 4]
004efeb9  jmp 0x4efebd
004efebb  xor ecx, ecx
004efebd  mov dword ptr [0x67ab48], ecx
004efec3  mov dword ptr [eax], 0xffffffff
004efec9  mov eax, esi
004efecb  mov dword ptr [esi], 0x61c9c8
004efed1  mov dword ptr [esi + 8], 0xffffffff
004efed8  pop esi
004efed9  mov esp, ebp
004efedb  pop ebp
004efedc  ret
```

- `0x004efedd-0x004efee0` is `cc cc cc`, three-byte alignment before [UID:0002IQ] ordinary destructor.
- Raw rel32 scan found the only direct call to the constructor at `.text:0x00463a9a`.
- The application initialization window confirms the startup sequence: `0x00463a9a` calls constructor, `0x00463aae` calls `LoadSystemKeyboardSettings`, and `0x00463ab5` calls `ApplyFastKeyboardRepeatSettings`.
- Raw rel32 scan found the constructor's internal `LObject` base constructor call at `0x004efeaa -> 0x004f4a80`. The base constructor target has many other callers, as expected for a common base.
- Little-endian VA scan found no direct pointer table entry to `0x004efea0`; this constructor is reached by direct call from `Application::Initialize`, not by vtable.
- Little-endian VA scan found the three `0x0061c9c8` vtable-address immediates at constructor `0x004efecd`, ordinary destructor `0x004efee2`, and scalar deleting destructor `0x004effc8`.
- Little-endian VA scan found ten `0x0067ab48` singleton-address hits matching support docs: `0x00464af8`, `0x00464b06`, `0x00466a1c`, `0x00466ad3`, `0x004673c2`, `0x004ab835`, `0x004efebf`, `0x004efee8`, `0x004effce`, and `0x004f5ede`.
- Vtable data at `0x0061c9c4-0x0061c9dc` is `0x00649820 0x004effc0 0x004f4b10 0x0041b6c0 0x00000400 0x00000400`.

Local IDA export evidence checked:

- `NexusTK.exe.lst` models `sub_4EFEA0` at `0x004efea0`, calls `sub_4F4A80` at `0x004efeaa`, writes `dword_67AB48` at `0x004efebd`, writes `0xffffffff` at `0x004efec3` and `0x004efed1`, writes `??_7KeySpeedMgr@@6B@` at `0x004efecb`, returns at `0x004efedc`, and aligns at `0x004efedd`.
- `NexusTK.exe.lst` shows the direct caller at `0x00463a9a`, followed by `0x00463aae` load and `0x00463ab5` fast-repeat calls.
- `NexusTK.exe.map` names the vtable and RTTI family: `const KeySpeedMgr::\`vftable'`, `KeySpeedMgr` RTTI descriptors, and `Singleton<KeySpeedMgr>` RTTI descriptors.
- `NexusTK.exe.lst` RTTI class hierarchy for `KeySpeedMgr` has three base-class entries: `KeySpeedMgr`, `LObject`, and `Singleton<class KeySpeedMgr>`; the `Singleton<KeySpeedMgr>` base descriptor uses member displacement `4`.

## Heuristic / Inference Reanalysis And Validation

### Source-facing name and signature

Recommended source signature:

```cpp
KeySpeedMgr::KeySpeedMgr()
```

Evidence:

- The target is in the `0x004efea0-0x004f0008` KeySpeedMgr class island.
- The function uses `ecx == this`, calls the common `LObject` constructor at `0x004f4a80`, publishes the singleton, initializes object fields, installs the class vptr, and returns.
- `Application::Initialize` allocates `0x0c` bytes, calls `0x004efea0`, then immediately calls the load and fast-repeat helpers.
- IDA/Ghidra return types such as `_DWORD*` or `KeySpeedMgr*` are decompiler representations of constructor lowering. Source constructors have no return type.

Rejected alternatives:

- `sub_4EFEA0`: raw IDA name only.
- `KeySpeedMgr* KeySpeedMgr::KeySpeedMgr()`: generated/decompiler artifact; invalid source constructor signature.
- File-local setup helper: rejected because the function uses object state, base construction, and `KeySpeedMgr` vptr.
- Application-owned initializer: rejected. `Application::Initialize` is the caller and lifecycle orchestrator, not the owner of the constructor source.

### Constructor source shape

Best source-shaped body for this target:

```cpp
KeySpeedMgr::KeySpeedMgr()
{
    g_pKeySpeedMgr = this;
    m_savedKeyboardDelay = UINT(-1);
    m_savedKeyboardSpeed = UINT(-1);
}
```

Source statements represented:

- Publish the active singleton pointer.
- Initialize the saved Windows keyboard repeat delay field to an invalid sentinel.
- Initialize the saved Windows keyboard repeat speed field to an invalid sentinel.

Compiler/decompiler mechanics to omit:

- The `LObject` base constructor call is implicit in the constructor/base-initialization sequence. It can be documented as a base constructor call, but should not be emitted as a normal body statement.
- The `0x0061c9c8` vptr store is compiler-emitted constructor setup.
- `return this` is decompiler lowering, not source.
- The `this == -4`/null-adjust branch around `g_pKeySpeedMgr` is a base-subobject adjustment artifact. It is not a meaningful runtime branch for a valid constructed object and should not be copied.
- `this[1]`, `this[2]`, `mbr_0x4`, `mbr_0x8`, `DAT_0067ab48`, and `dword_67AB48` are raw/generated names.

Singleton-base nuance:

- IDA RTTI exposes `Singleton<KeySpeedMgr>` as a base class of `KeySpeedMgr`, with member displacement `4`.
- The constructor sequence `lea eax, [esi+4]`, `lea ecx, [eax-4]`, and `mov [0x67ab48], ecx` is consistent with an inlined empty singleton-base constructor/register step.
- Current by-doc and generated-source practice represents this effect as `g_pKeySpeedMgr = this;`, and that is the right first-draft target-level source effect.
- Final header work should decide whether `KeySpeedMgr` is declared as `class KeySpeedMgr : public LObject, public Singleton<KeySpeedMgr>` and whether the singleton publication is inherited/implicit. That header-level question does not block this method page from recording the constructor's observable source effect.

### Fields, keyboard settings, and range behavior

Recommended field names/types:

```cpp
UINT m_savedKeyboardDelay; // +0x04
UINT m_savedKeyboardSpeed; // +0x08
```

Evidence:

- The object allocation is `0x0c` bytes / 12 bytes (verified with `int_convert.py`): vptr at `+0x00`, saved delay at `+0x04`, saved speed at `+0x08`.
- Constructor writes `0xffffffff` to `+0x04` and `+0x08`.
- `LoadSystemKeyboardSettings` passes `this + 4` to `SystemParametersInfoW(SPI_GETKEYBOARDDELAY, 0, ..., 0)` and `this + 8` to `SystemParametersInfoW(SPI_GETKEYBOARDSPEED, 0, ..., 0)`.
- `RestoreSystemKeyboardSettings` restores delay only when `delay <= 3` and speed only when `speed <= 0x1f` / 31 (verified with `int_convert.py`), matching Windows keyboard repeat ranges.
- The raw two-argument setter and fixed fast-repeat helper use the same delay/speed range model and `SystemParametersInfoW` set actions.

Behavioral impact:

- The constructor has no range check or error path itself.
- The sentinel `UINT(-1)` is intentionally outside valid delay/speed ranges. If restore runs before load succeeds, the restore method's unsigned range checks suppress invalid `SystemParametersInfoW` calls.
- `m_savedKeyboardDelay`/`m_savedKeyboardSpeed` are stronger field names than `m_keyboardDelay`/`m_keyboardSpeed` because these fields store the user's original settings, not the active fast-repeat values.

Remaining non-blocking uncertainty:

- The exact original field spelling is not recoverable from binary evidence. `m_savedKeyboardDelay` and `m_savedKeyboardSpeed` are the best source-quality names for docs and first-draft code. If the final class header standardizes on shorter `m_keyboardDelay`/`m_keyboardSpeed`, the constructor body remains behaviorally identical.

### Singleton and lifecycle behavior

Resolved behavior:

- `g_pKeySpeedMgr` is the process singleton pointer at `0x0067ab48`.
- Constructor writes the active object pointer to `g_pKeySpeedMgr`.
- Ordinary destructor [UID:0002IQ] clears `g_pKeySpeedMgr = 0;` and now emits first-draft formal C++.
- Scalar deleting destructor [UID:0002IT] duplicates the singleton clear and base cleanup while handling delete flags; it remains compiler-wrapper evidence and should not be emitted as a separate hand-authored method.
- Startup sequence constructs the object, loads the user's current keyboard settings, then applies fast repeat settings.
- Cleanup/deactivation/error/exit paths read `g_pKeySpeedMgr` and call restore/delete consumers, including [UID:00032A] `DestroyKeySpeedMgr` in WinMain cleanup.

Ownership implications:

- `Application::Initialize` is the construction caller, not the source owner.
- `WinMain` and `DestroyKeySpeedMgr` consume the singleton during cleanup, but do not own the constructor or global storage.
- `InputMan` is input-adjacent but not owner; `KeySpeedMgr` only manages system keyboard repeat settings.

### Owner, emitter, and source-file route

Recommended metadata:

- `CANONICAL_OWNER:00006Z`
- `EMITTER_UIDS:00006Z`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_POSITION_OPTIONAL:` unchanged blank

Route:

- Target [UID:0002IP] is a `KeySpeedMgr` class constructor.
- [UID:00006Z] `KeySpeedMgr` is attached to [UID:0000KJ] `KeySpeedMgr`.
- [UID:0000KJ] has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/input/"`.
- Active generated output path is `auto-generated/NexusTK/input/KeySpeedMgr.cpp`.

Do not move ownership to:

- [UID:0000HG] `Application`: construction caller only.
- [UID:0000PA] `WinMain`: cleanup wrapper consumer only.
- [UID:0000K6] `InputMan`: adjacent input subsystem, but not the system keyboard repeat manager source.
- [UID:0000RB] `g_pKeySpeedMgr`: owns storage/global documentation, not the method body.

### Compiler-generated/raw/generated-name issues

Replace or explain these names:

| Raw/generated item | Source-quality handling |
| --- | --- |
| `sub_4EFEA0` | `KeySpeedMgr::KeySpeedMgr()` |
| `sub_4F4A80` | `LObject` base constructor; implicit base construction, not a normal body statement |
| `dword_67AB48` / `DAT_0067ab48` | `g_pKeySpeedMgr` |
| `this[1]`, `mbr_0x4` | `m_savedKeyboardDelay` |
| `this[2]`, `mbr_0x8` | `m_savedKeyboardSpeed` |
| `0x0061c9c8` / `??_7KeySpeedMgr@@6B@` | compiler-emitted vptr store; vtable page evidence only |
| `0xffffffff` | source-style invalid sentinel, recommend `UINT(-1)` |
| `KeySpeedMgr* KeySpeedMgr::KeySpeedMgr()` | invalid generated constructor signature |
| `if (this == reinterpret_cast<KeySpeedMgr*>(-4))` | singleton-base/null-adjust decompiler artifact |
| `return this` | constructor lowering artifact |

Current generated output state:

- `auto-generated/NexusTK/input/KeySpeedMgr.cpp` currently emits only the B003 destructor code and lists [UID:0002IP] as an empty emitter marker.
- `simroot_v2/class_KeySpeedMgr.cpp` contains a historical constructor with the correct core effects but bad source shape: explicit `LObject::LObject()`, null-adjust branch, `nullptr`, raw `0xFFFFFFFF`, explicit vtable write, and `return this`.
- `project-level/-unresolved.md` still flags `mbr_0x4`, `mbr_0x8`, `sub_4EFEA0`, and `sub_4F4A80` in this target. The recommended doc update resolves those as named fields and base constructor evidence.

### Score rationale

Recommended `COMPLETION:88`:

- Completion rises because the report resolves the stale below-95/no-code rationale, provides first-draft C++ source, maps raw names to source names, confirms exact bytes/padding/caller, ties the fields to load/restore/system ranges, and records the singleton/RTTI nuance.
- Completion should not go above low-90s yet because final class-header spelling, exact original field names, exact sentinel spelling, and singleton-base declaration style remain open.

Recommended `CONFIDENCE:92`:

- Confidence rises because raw PE/Capstone, existing IDA-backed docs, local IDA exports, support docs, generated-output checks, and lifecycle xrefs all agree on behavior and source route.
- Confidence should not be `95+` because live IDA MCP was unavailable in this session and the exact original source spelling is not recovered.

## Exact Supervisor Changes Required

### Target Header

In `by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md`, replace:

```text
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

with:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Leave owner/emitter metadata unchanged.

### Target Formal C++

In the same target, replace the empty reconstruction block:

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

with:

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
KeySpeedMgr::KeySpeedMgr()
{
    g_pKeySpeedMgr = this;
    m_savedKeyboardDelay = UINT(-1);
    m_savedKeyboardSpeed = UINT(-1);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Target Status Bullet

Replace this stale status bullet:

```markdown
- Generated parent: attached to [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md); both pages clear the 80/80 parent gate.
```

with:

```markdown
- Generated parent: attached to [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md), which routes through [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) to `NexusTK/input/KeySpeedMgr.cpp`; target, class, and file route clear the current 85/85+ source-entry gate after the B014 score update.
```

### Target Function Row

Replace the target `## Function` table row:

```markdown
| `0x004efea0-0x004efedd` | `KeySpeedMgr::KeySpeedMgr` | Calls the `LObject` base constructor, stores `g_pKeySpeedMgr`, initializes saved delay/speed fields to `0xffffffff`, installs the `KeySpeedMgr` vtable, and returns `this`. |
```

with:

```markdown
| `0x004efea0-0x004efedd` | `KeySpeedMgr::KeySpeedMgr` | Constructor body publishes `g_pKeySpeedMgr`, initializes saved keyboard delay/speed fields to the invalid `UINT(-1)` sentinel, and relies on normal compiler emission for `LObject` base construction, vptr setup, and constructor return mechanics. |
```

### Target Raw Evidence Insert

In the target `## Raw Evidence` section, after the existing bullets and before `## 2026-06-06 Live IDA Refresh`, insert:

```markdown
- 2026-06-19 B014 raw PE check on `NexusTK.exe` SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632` confirms the constructor body is 61 bytes (`0x3d`, verified with `int_convert.py`) at `0x004efea0-0x004efedd`.
- Capstone disassembly decodes the source effects as `call 0x4f4a80` at `0x004efeaa`, singleton write `mov dword ptr [0x67ab48], ecx` at `0x004efebd`, saved delay write `mov dword ptr [eax], 0xffffffff` at `0x004efec3`, vptr write `mov dword ptr [esi], 0x61c9c8` at `0x004efecb`, saved speed write `mov dword ptr [esi + 8], 0xffffffff` at `0x004efed1`, and `ret` at `0x004efedc`.
- Raw bytes at `0x004efedd-0x004efee0` are `cc cc cc`, confirming three-byte alignment before the ordinary destructor.
- Raw rel32 scan found the only direct constructor call at `0x00463a9a`; the same startup window calls `LoadSystemKeyboardSettings` at `0x00463aae` and `ApplyFastKeyboardRepeatSettings` at `0x00463ab5`.
- Local IDA export RTTI shows `KeySpeedMgr` has `LObject` and `Singleton<KeySpeedMgr>` base-class descriptors. Treat the singleton publish as source-visible constructor behavior, while leaving final base-list spelling to class/header reconstruction.
```

### Target Reconstruction Notes Replacement

Replace the target `## Reconstruction Notes` section with:

```markdown
## Reconstruction Notes

- First-draft formal source should be `KeySpeedMgr::KeySpeedMgr() { g_pKeySpeedMgr = this; m_savedKeyboardDelay = UINT(-1); m_savedKeyboardSpeed = UINT(-1); }`.
- Source should model fields as saved Windows keyboard repeat delay/speed values, not `mbr_0x4`, `mbr_0x8`, `this[1]`, or `this[2]`.
- `UINT(-1)` is the preferred source-style invalid sentinel. It is outside the valid restore ranges (`0..3` for keyboard delay, `0..31` for keyboard speed), so restore remains a no-op until the load method captures real system settings.
- Do not emit explicit vtable assignment, `return this`, raw `0xffffffff`, `KeySpeedMgr*` constructor return type, or the generated `this == reinterpret_cast<KeySpeedMgr*>(-4)` branch.
- IDA RTTI exposes `Singleton<KeySpeedMgr>` in the class hierarchy, so final header reconstruction should decide whether the singleton publish belongs to an explicit singleton base. This does not block target-level first-draft C++ because current docs, generated-source practice, and raw behavior all support recording the constructor's source-visible singleton effect as `g_pKeySpeedMgr = this;`.
- The stale 95/95 no-code note is obsolete under the current source-entry gate. This target is reconstructable, has a valid owner/emitter route, and should emit first-draft C++ after the B014 score update.
```

### Target Change Log Insert

Add this at the top of the target `## Changes` section:

```markdown
### 2026-06-19 B014 constructor source-quality recheck

- Changed recommendation from `84/90`, blank formal C++, to `88/92` with first-draft constructor C++.
- Evidence: B014 raw PE/Capstone recheck confirmed the exact 61-byte body, sole startup caller at `0x00463a9a`, `LObject` base-constructor call at `0x004efeaa`, singleton write to `g_pKeySpeedMgr` at `0x0067ab48`, saved keyboard delay/speed sentinel writes at offsets `+0x04` and `+0x08`, `0x0061c9c8` vptr store, and three `0xcc` padding bytes before the ordinary destructor.
- Source decision: emit only the source-shaped constructor effects `g_pKeySpeedMgr = this;`, `m_savedKeyboardDelay = UINT(-1);`, and `m_savedKeyboardSpeed = UINT(-1);`; leave base construction, vptr setup, return-this lowering, and singleton-base/null-adjust mechanics to compiler/header reconstruction.
```

## Recommended Support Doc Changes

These are recommended exact support-doc changes for the supervisor implementation pass. They are not applied by this B-agent report.

### KeySpeedMgr Class Method Row

In `by-class/KeySpeedMgr.md`, replace the constructor method row:

```markdown
| [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md) | `0x004efea0-0x004efedd` | Constructs `LObject` base, stores singleton, initializes delay/speed to `0xffffffff`, installs vtable. |
```

with:

```markdown
| [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md) | `0x004efea0-0x004efedd` | Source constructor publishes `g_pKeySpeedMgr` and initializes saved keyboard delay/speed to `UINT(-1)`; `LObject` base construction, vptr setup, singleton-base adjustment, and return-this lowering are compiler/header mechanics. |
```

### KeySpeedMgr File Proposed-Contents Row

In `by-file/KeySpeedMgr.md`, replace the constructor row:

```markdown
| [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md) | `0x004efea0-0x004efedd` | Constructs the singleton object and installs the vtable. |
```

with:

```markdown
| [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md) | `0x004efea0-0x004efedd` | Source constructor publishes `g_pKeySpeedMgr` and initializes saved keyboard delay/speed fields to invalid sentinels; base/vptr/return mechanics stay compiler-generated. |
```

### KeySpeedMgr Aggregate Row

In `by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md`, replace the constructor row:

```markdown
| `0x004efea0-0x004efedd` | [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md) | Constructs base, stores singleton `0x0067ab48`, initializes saved delay/speed to `0xffffffff`, installs vtable. |
```

with:

```markdown
| `0x004efea0-0x004efedd` | [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md) | Source constructor publishes `g_pKeySpeedMgr` and initializes saved keyboard delay/speed to `UINT(-1)`; base construction, vptr setup, singleton-base adjustment, and return-this lowering are not hand-authored source. |
```

### Layout Reconstruction Note

In `by-type/by-struct/KeySpeedMgrLayout.md`, keep the field-offset table, but replace the reconstruction snippet:

```cpp
class KeySpeedMgr : public LObject {
    UINT m_savedKeyboardDelay;
    UINT m_savedKeyboardSpeed;
};
```

with:

```cpp
class KeySpeedMgr : public LObject, public Singleton<KeySpeedMgr> {
    UINT m_savedKeyboardDelay;
    UINT m_savedKeyboardSpeed;
};
```

Then add this note below the snippet:

```markdown
IDA RTTI exposes `Singleton<KeySpeedMgr>` as a base-class descriptor at member displacement `4`. That singleton base appears to be empty/overlapped for data-layout purposes; the observed writable fields remain `+0x04` saved keyboard delay and `+0x08` saved keyboard speed, and the object allocation remains `0x0c` bytes.
```

### Vtable / Vtable-Data RTTI Note

In `by-type/by-vtable/KeySpeedMgrVtable.md` or [UID:00031P] `by-memory/0x0061c9c4-0x0061c9dc.KeySpeedMgrVtableData.md`, add:

```markdown
- Local IDA export RTTI shows the `KeySpeedMgr` hierarchy includes `KeySpeedMgr`, `LObject`, and `Singleton<KeySpeedMgr>` base-class descriptors. The vtable slot interpretation remains unchanged; this RTTI detail mainly affects final class-header/base-list reconstruction and explains the constructor's singleton-base adjustment pattern before the `g_pKeySpeedMgr` write.
```

### Generated Output Note

In target/support docs that still mention generated source caveats, replace "blank final C++ below the source gate" with:

```markdown
Current generated output should refresh after the target C++ block is populated. Older `simroot_v2/class_KeySpeedMgr.cpp` constructor output is only a lead; it includes source-quality artifacts (`KeySpeedMgr*` constructor return type, explicit base call, null-adjust branch, explicit vtable write, raw `0xFFFFFFFF`, and `return this`) that should not be copied.
```

## Coverage Report Replacement Text

Do not edit `by-memory/-coverage-report.md` directly in this B-agent pass. During supervisor implementation, replace the current [UID:0002IP] row:

```markdown
        - [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md) 0x004efea0-0x004efedd | constructor | KeySpeedMgr::KeySpeedMgr : reconstructable : 84% : strong : Live IDA confirms exact constructor bounds, `Application::Initialize` caller at `0x00463a9a`, `LObject` base constructor call at `0x004efeaa`, singleton/vtable/field initialization evidence, class parent attachment, and blank final C++ below the source gate.
```

with:

```markdown
        - [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md) 0x004efea0-0x004efedd | constructor | KeySpeedMgr::KeySpeedMgr : reconstructable : 88% : strong : B014 raw PE/Capstone and IDA-export review confirms exact 61-byte constructor, sole startup caller `0x00463a9a`, `LObject` base-constructor call at `0x004efeaa`, singleton publish to `g_pKeySpeedMgr`, saved keyboard delay/speed sentinel writes, `0x0061c9c8` vptr store, and three-byte `0xcc` successor padding. Replace stale below-95/no-code rationale with first-draft source body `g_pKeySpeedMgr = this; m_savedKeyboardDelay = UINT(-1); m_savedKeyboardSpeed = UINT(-1);`, leaving null-adjust, vptr store, base construction, and return-this as compiler/decompiler mechanics; owner/emitter stay [UID:00006Z] through `NexusTK/input/KeySpeedMgr.cpp`.
```

Expected stats row after target score refresh, if regenerated rather than edited by hand:

```markdown
| `0002IP` | 88 | 92 | 90.0 | `by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md` |
```

## Validator Needs

No validator was run for target/support docs because this is a report-only B-agent pass.

Recommended supervisor validation after applying target/support changes:

> Executable block R001 was removed from this report and preserved verbatim in [0002IP-KeySpeedMgrConstructor-source-quality-removed.md](0002IP-KeySpeedMgrConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor implements only the target page and coverage row, validate only those touched files plus autogen.

## Remaining Open Questions

No blocker remains for 85/85+ routing, owner/emitter, first-draft C++ readiness, or coverage-row replacement.

Residual non-blocking items:

- Exact original field spelling is not recovered. Recommend `m_savedKeyboardDelay` and `m_savedKeyboardSpeed`; `m_keyboardDelay`/`m_keyboardSpeed` remain behaviorally equivalent but less precise.
- Exact sentinel spelling is not recovered. Recommend `UINT(-1)` because the fields are Win32 `UINT` values and the sentinel is intentionally outside the valid restore ranges.
- Exact global linkage is not recovered (`static` file global versus external declaration plus definition). Existing docs and generated-source practice support `KeySpeedMgr* g_pKeySpeedMgr`.
- Exact class header/base list needs a later header pass. IDA RTTI supports `Singleton<KeySpeedMgr>` in addition to `LObject`, but the target method can still emit the source-visible singleton publish effect.
- Live IDA MCP was unavailable in this session, so confidence stays below near-final `95+` despite raw PE/Capstone and local IDA-export confirmation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0002IP-KeySpeedMgrConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0002IP"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002IP-KeySpeedMgrConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0002IP-KeySpeedMgrConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002IP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
