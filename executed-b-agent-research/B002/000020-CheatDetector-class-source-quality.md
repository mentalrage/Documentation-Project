** TARGET-REPORT-UID:000020 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000020 CheatDetector Class Source-Quality Research

Report date: 2026-06-19  
Agent: B002  
Assignment: B-agent report-only source-quality and heuristic pass  
Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\CheatDetector.md`  
Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\000020-CheatDetector-class-source-quality.md`

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:000020] `CheatDetector` owned by [UID:0000I6] `CheatDetector` and emitted through `NexusTK/security/CheatDetector.cpp`, but raise the class page from `85/86` to `88/89` and populate a first-draft class declaration/header-shape C++ block.
- Final disposition: source-quality blockers are now narrowed enough for class-level C++. `CheatDetector` is a `TimerHandler`-derived startup singleton with a private retained time-snapshot helper, an always-true `OnTimer(eventId,arg0,arg1)` override, and compiler-generated constructor-unwind/deleting-destructor support. The remaining no-xref raw helper caveat blocks claims about active anti-cheat behavior, not the class declaration.
- Required action: supervisor implementation callback should update the class page, the raw time-snapshot helper page, the main memory aggregate, file/meta/source-tree support docs, and coverage text. Do not edit `by-memory/-coverage-report.md` directly; exact rows are included below.
- Confidence: high for class/file/vtable/global/TimerHandler ownership; medium-high for source field names; medium for runtime detection intent because the only nontrivial helper has no incoming route.

## Target

- Target UID: `000020`
- Target path: `by-class/CheatDetector.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000I6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000I6`
- Current generated route: `auto-generated/NexusTK/security/CheatDetector.cpp`
- Current generated output state: empty emitter markers for the class, main memory aggregate, time helper, virtual/clear/destructor range, vtable data, vtable type page, global, and singleton storage.

## Executive Recommendation

### Metadata

Recommended class metadata:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:0000I6
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000I6
```

Rationale:

- Completion rises because the report resolves the class header shape, TimerHandler inheritance, virtual callback signature, singleton lifecycle, destructor-wrapper policy, raw helper role/name/signature, field layout, and source placement.
- Confidence rises because the byte/xref evidence is direct for all lifecycle and vtable facts, and the class declaration no longer depends on proving an active caller for the raw helper.
- Confidence stays below final-audit level because `0x00483f90` still has no incoming xref/pointer route and the exact original names for the helper and comparison/baseline fields are inferred.

### First-Draft Class C++ Recommendation

Populate [UID:000020] with declaration-level source C++. Keep function bodies in the by-memory children or file-level reconstruction, not in the class page, except where local convention allows declarations only.

```cpp
class CheatDetector : public TimerHandler
{
public:
    CheatDetector();
    virtual ~CheatDetector();

    virtual bool OnTimer(int eventId, int arg0, int arg1);

private:
    void CaptureTimeSnapshot(unsigned int *timerTick, unsigned __int64 *systemFileTime);

    unsigned __int64 m_lastSystemFileTime;
    unsigned int m_lastTimerTick;
    unsigned int m_baselineTimerTick;
    unsigned __int64 m_baselineSystemFileTime;
};

extern CheatDetector *g_pCheatDetector;
```

Notes for implementation:

- The `unsigned __int64` fields are deliberately used instead of `FILETIME` struct members in the class declaration. With MSVC default packing, the first 64-bit field naturally starts at `+0x08` after the vptr at `+0x00`, leaving the observed `+0x04` alignment gap. A `FILETIME` struct would normally align to 4 and would not explain the observed `+0x08` start without an explicit padding dword.
- `m_lastSystemFileTime` at `+0x08` and `m_lastTimerTick` at `+0x10` are IDA-confirmed by the raw helper writes.
- `m_baselineTimerTick` at `+0x14` and `m_baselineSystemFileTime` at `+0x18` are inferred from constructor zeroing and the adjacent time/tick comparison layout. These names are descriptive, not proven original identifiers.
- Do not declare a separate source method named `CheatDetectorScalarDeletingDestructor`. The source class should declare a virtual destructor and let MSVC regenerate the deleting destructor wrapper.

## Supervisor Active Recheck

The current assignment asks for a class-level source-quality pass focused on:

- raw time-snapshot helper reachability and source role;
- final `TimerHandler` inheritance/header shape;
- class field names;
- singleton lifecycle;
- `OnTimer` callback signature;
- constructor-unwind cleanup;
- ordinary destructor versus scalar deleting wrapper policy;
- vtable/type/global support;
- `client_anticheat` relationship;
- first-draft class C++ readiness.

This is a class-level report. No split was required before writing the report because the relevant executable subranges are already split into [UID:0002EN] and [UID:000109]. No by-* files or coverage files were edited.

## Evidence Standards Used

Evidence types used:

- Existing by-* documentation for the target, file parent, memory children, vtable, singleton global, timer base, timer record layout, and anticheat meta page.
- Existing executed B-agent report: `Agent-B012/research/executed/000109-CheatDetectorVirtualClearAndDestructor-source-quality.md`, treated as a lead and rechecked against current docs and local bytes.
- Local PE byte scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Local direct rel32 call/jump scan and VA/RVA pointer-pattern scan for `0x00483f00`, `0x00483f90`, `0x00483fe0`, `0x00483ff0`, `0x00484000`, `0x00597570`, `0x00597580`, `0x00615564`, `0x0067ab3c`, and `0x0067ab80`.
- Local Capstone disassembly for the constructor, raw time helper, virtual callback, clear helper, scalar deleting destructor, TimerHandler constructor/destructor/default callback, and application startup/cleanup consumers.

No live IDA mutation was performed. No validator/autogen commands were run because this pass is report-only.

## Local PE / IDA-Equivalent Facts

Binary checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`  
Image base: `0x00400000`

Sections relevant to this report:

| Section | VA | Raw | Notes |
| --- | --- | --- | --- |
| `.text` | `0x00401000` | `0x00000400` | Contains constructor/helper/destructor/timer code. |
| `.rdata` | `0x0060d000` | `0x0020ba00` | Contains import pointers and vtables. |
| `.data` | `0x0066d000` | `0x0026ac00` | Contains singleton globals. |

### Exact CheatDetector bytes

| Range | Bytes / evidence | Meaning |
| --- | --- | --- |
| `0x00483f00-0x00483f86` | modeled constructor; starts `55 8b ec 6a ff 68 4b c4 5f 00 ...` | Constructor with SEH/unwind scaffolding, singleton publish, `TimerHandler` base constructor call, vtable install, field zeroing. |
| `0x00483f86-0x00483f90` | ten `cc` bytes | Alignment before raw helper. |
| `0x00483f90-0x00483fd9` | `55 8b ec 83 ec 08 56 ... c2 08 00` | Raw unmodeled `__thiscall` helper; complete body, no incoming route found. |
| `0x00483fd9-0x00483fe0` | seven `cc` bytes | Alignment before callback. |
| `0x00483fe0-0x00483fe5` | `b0 01 c2 0c 00` | `mov al,1; ret 0x0c`; `TimerHandler` callback override. |
| `0x00483fe5-0x00483ff0` | eleven `cc` bytes | Alignment before clear helper. |
| `0x00483ff0-0x00483ffb` | `c7 05 3c ab 67 00 00 00 00 00 c3` | `g_pCheatDetector = 0; ret`; constructor-unwind clear helper. |
| `0x00483ffb-0x00484000` | five `cc` bytes | Alignment before deleting destructor. |
| `0x00484000-0x0048402d` | modeled scalar deleting destructor; calls `0x00597580`, clears singleton, optional free | Compiler deleting-destructor wrapper over `TimerHandler_dtor`. |
| `0x0048402d-0x00484030` | three `cc` bytes | Alignment before `ClanStatusPane` successor. |

### Constructor disassembly facts

Important instructions in `0x00483f00-0x00483f86`:

```asm
00483f03  push -1
00483f05  push 0x005fc44b
00483f13  mov eax, [0x00672f24]       ; security cookie
00483f24  mov esi, ecx                ; this
00483f29  lea eax, [esi+4]
00483f2c  test eax, eax
00483f33  mov [0x0067ab3c], eax-4     ; normally g_pCheatDetector = this
00483f3a  mov [0x0067ab3c], 0         ; null/fallback path
00483f46  mov [ebp-4], 0              ; unwind state after singleton publication
00483f4d  call 0x00597570             ; TimerHandler::TimerHandler
00483f52  mov [esi], 0x00615564       ; CheatDetector vftable
00483f5a  mov [esi+0x10], 0
00483f61  mov [esi+0x14], 0
00483f68  mov [esi+0x18], 0
00483f6f  mov [esi+0x1c], 0
```

Constructor interpretation:

- `g_pCheatDetector` is published before `TimerHandler::TimerHandler()` is called.
- The cleanup handler at `0x005fc440-0x005fc446` jumps to `0x00483ff0`, so the early singleton publication is protected by constructor-unwind cleanup.
- The constructor installs the derived `CheatDetector` vtable after the base constructor, then zeroes `+0x10`, `+0x14`, `+0x18`, and `+0x1c`.
- It does not initialize the `+0x08/+0x0c` system-file-time field, which supports treating it as written by the snapshot helper before use.

### Constructor-unwind helper fact

Local disassembly around `0x005fc440`:

```asm
005fc440  mov ecx, [ebp-0x10]
005fc443  add ecx, 4
005fc446  jmp 0x00483ff0
```

`0x00483ff0` ignores the adjusted `ecx` and clears only `g_pCheatDetector`. This is constructor cleanup metadata/functionlet code, not an ordinary public source method.

### Raw time-snapshot helper facts

Disassembly of `0x00483f90-0x00483fd9`:

```asm
00483f90  push ebp
00483f91  mov ebp, esp
00483f93  sub esp, 8
00483f96  push esi
00483f97  lea eax, [ebp-8]
00483f9a  mov esi, ecx
00483f9c  push eax
00483f9d  call dword ptr [0x0060d150] ; GetSystemTimeAsFileTime
00483fa3  mov edx, [ebp-4]
00483fa6  xor eax, eax
00483fa8  add eax, [ebp-8]
00483fab  mov [esi+0x08], eax
00483fae  adc edx, 0
00483fb1  mov [esi+0x0c], edx
00483fb4  mov eax, [0x0067ab80]       ; g_pTimerMgr
00483fb9  mov ecx, [eax+0x18]         ; TimerMgr::currentTick
00483fbc  mov eax, [ebp+8]            ; tick out
00483fbf  mov [esi+0x10], ecx
00483fc2  mov [eax], ecx
00483fc4  mov ecx, [ebp+0x0c]         ; system time out
00483fc7  mov eax, [esi+0x08]
00483fca  mov [ecx], eax
00483fcc  mov eax, [esi+0x0c]
00483fcf  mov [ecx+4], eax
00483fd6  ret 8
```

Best binary-level signature:

```cpp
void __thiscall CheatDetector::CaptureTimeSnapshot(unsigned int *timerTick,
                                                   unsigned __int64 *systemFileTime);
```

Facts:

- `ecx` is the `CheatDetector` instance.
- First explicit argument receives the current `TimerMgr::currentTick`.
- Second explicit argument receives the sampled 64-bit system file time.
- The helper updates receiver fields at `+0x08/+0x0c/+0x10`.
- There is no null check for `g_pTimerMgr`, matching a startup-created scheduler singleton assumption.
- It has no incoming direct call, jump, VA pointer, or RVA pointer reference in the local scan.

### Virtual callback facts

`0x00483fe0` bytes:

```asm
00483fe0  mov al, 1
00483fe2  ret 0x0c
```

Interpretation:

- Vtable slot `+0x04` points to this function.
- `ret 0x0c` consumes three explicit arguments.
- `TimerHandler`/`ScheduledTimerEvent` support docs record callback dispatch through owner virtual slot `+4`, with `eventId`, `arg0`, and `arg1`.
- Best source signature is:

```cpp
bool CheatDetector::OnTimer(int eventId, int arg0, int arg1);
```

Names `eventId`, `arg0`, and `arg1` are descriptive. Exact original parameter names are not recovered.

### Scalar deleting destructor facts

Disassembly of `0x00484000-0x0048402d`:

```asm
00484000  push ebp
00484001  mov ebp, esp
00484003  push esi
00484004  mov esi, ecx
00484006  call 0x00597580             ; TimerHandler_dtor
0048400b  test byte ptr [ebp+8], 1
0048400f  mov [0x0067ab3c], 0
00484019  je 0x00484026
0048401b  push 0x20
0048401d  push esi
0048401e  call 0x005c7526             ; free/delete helper
00484023  add esp, 8
00484026  mov eax, esi
0048402a  ret 4
```

Interpretation:

- This exact function is compiler deleting-destructor glue.
- It should be documented as `CheatDetectorScalarDeletingDestructor` at binary level.
- Source-facing class code should declare `virtual ~CheatDetector();`, not a handwritten `ScalarDeletingDestructor(unsigned int flags)` method.
- The observed singleton clear after `TimerHandler_dtor` suggests the global clear may be emitted from an inlined singleton-registration cleanup or compiler-merged destructor support, not necessarily from a straightforward handwritten destructor body. Do not overfit the final source to a manual destructor body until implementation owns the full class/file body.

### TimerHandler facts

Local bytes and support docs confirm:

```asm
00597570  mov [ecx], 0x0062e338
00597576  mov eax, ecx
00597578  ret

00597580  ... mov [ecx], 0x0062e338
005975a9  mov ecx, [0x0067ab80]
005975af  call 0x00597a10
```

- `0x00597570` is `TimerHandler::TimerHandler`.
- `0x00597580` is `TimerHandler_dtor`, not EventDispatcher, boost, LObject, or pane/dialog code.
- `0x005975d0` is the nearby default true-return callback (`b0 01 c2 0c 00`), but current `TimerHandler` vtable docs say the base vtable callback slot is `__purecall`; the CheatDetector slot is still a derived override.

### Vtable and global facts

Local bytes:

```text
0x00615560: 6c 48 64 00 00 40 48 00 e0 3f 48 00 54 4b 64 00
```

Decoded:

- `0x00615560 -> 0x0064486c`, CheatDetector RTTI/COL word.
- `0x00615564 -> 0x00484000`, scalar deleting destructor slot.
- `0x00615568 -> 0x00483fe0`, `OnTimer` callback slot.
- `0x0061556c -> 0x00644b54`, successor `ClanStatusPane` RTTI/COL boundary.

Local singleton bytes:

- `0x0067ab3c` current file bytes: `00 00 00 00`.
- `0x0067ab80` current file bytes: `00 00 00 00`.

Global xref scan:

- `0x0067ab3c` VA refs: `0x00464ba2`, `0x00483f34`, `0x00483f3c`, `0x00483ff2`, `0x00484011`.
- `0x0067ab80` VA refs: 125 total in the local scan; `0x00483fb5` is the raw helper's timer-manager read.

### Route scan results

Local rel32/pointer scan:

| Target | Direct calls | Direct jumps | VA refs | RVA refs | Interpretation |
| --- | ---: | ---: | ---: | ---: | --- |
| `0x00483f00` | `0x0046473e` | none | none | none | Startup constructs `CheatDetector`. |
| `0x00483f90` | none | none | none | none | Raw helper is retained/no-route in current image. |
| `0x00483fe0` | none | none | `0x00615568` | none | Vtable-only callback slot. |
| `0x00483ff0` | none | `0x005fc446` | none | none | Constructor-unwind cleanup helper. |
| `0x00484000` | none | none | `0x00615564` | none | Vtable-only deleting destructor slot. |
| `0x00597570` | 7 calls, including `0x00483f4d` | none | none | none | Shared `TimerHandler` constructor. |
| `0x00597580` | 8 calls and 7 jumps, including `0x00484006` | several unwind/tail jumps | none | none | Shared `TimerHandler` destructor. |
| `0x00615564` | none | none | `0x00483f54` | none | Constructor writes derived vtable. |
| `0x0067ab3c` | none | none | 5 | none | CheatDetector singleton lifecycle refs. |
| `0x0067ab80` | none | none | 125 | none | TimerMgr singleton shared by timer system. |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Current Score | Recommendation |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00483f00-0x00483f86` | part of [UID:000108] | `CheatDetector::CheatDetector` | yes | [UID:000020] | aggregate `85/90` | Document early singleton publish, TimerHandler ctor, vtable install, fields, unwind cleanup; no separate child required now. |
| `0x00483f90-0x00483fd9` | [UID:0002EN] | raw retained `CheatDetector::CaptureTimeSnapshot` helper | yes | [UID:000020] | `85/88` | Raise to `87/89`; emit first-draft helper C++ with no-route caveat. |
| `0x00483fe0-0x00483fe5` | part of [UID:000109] | `CheatDetector::OnTimer` true-return override | yes | [UID:000020] | aggregate `86/90` | Keep no split required; class declaration should declare the override. |
| `0x00483ff0-0x00483ffb` | part of [UID:000109] | constructor-unwind singleton cleanup | yes as support | [UID:000020] | aggregate `86/90` | Keep compiler/EH support policy; no handwritten class method. |
| `0x00484000-0x0048402d` | part of [UID:000109] | scalar deleting destructor wrapper | yes as support | [UID:000020] | aggregate `86/90` | Keep binary wrapper policy; declare ordinary virtual destructor at class level. |
| `0x00615560-0x00615570` | [UID:00024Y] / [UID:0003JE] | RTTI/vtable data | generated-binary from class declaration | [UID:000020] | `86/92`, `88/93` | No score change required; cross-reference class declaration. |
| `0x0067ab3c-0x0067ab40` | [UID:0001P5] / [UID:0000QJ] | `g_pCheatDetector` singleton pointer | yes | [UID:0000QJ] -> [UID:0000I6] | `86/90`, `88/89` | Document first-draft declaration readiness as `CheatDetector *g_pCheatDetector = 0;` if implementing global C++. |

## Heuristic / Inference Reanalysis And Validation

### 1. Raw time-snapshot helper reachability

Best direction: source-authored retained private member helper, not compiler glue, not padding, and not TimerMgr-owned code.

Evidence:

- Complete function-shaped prologue/body/epilogue at `0x00483f90-0x00483fd9`.
- Bounded by `0xcc` padding on both sides.
- Uses `ecx` as object receiver and `ret 8`, matching a private `__thiscall` helper with two explicit output arguments.
- Calls `GetSystemTimeAsFileTime`.
- Reads `g_pTimerMgr->currentTick` at `+0x18`.
- Writes `CheatDetector` fields and caller-provided outputs.
- Local scan found no direct calls, jumps, VA pointer refs, or RVA pointer refs to `0x00483f90`.

Rejected alternatives:

- Padding/data: rejected by full executable code body and imported API call.
- Compiler-generated SEH/helper glue: rejected because it calls Win32 time and updates class fields.
- TimerMgr method: rejected because receiver writes are in the `CheatDetector` object and it sits inside the compact CheatDetector island.
- Active anti-cheat proof: rejected because no caller route reaches it and `OnTimer` currently returns true without invoking it.

Remaining uncertainty:

- Exact original helper spelling and why the function is retained without a route are not provable from current refs.
- This caps runtime-behavior confidence but should not block class declaration or helper first-draft C++.

### 2. Source-facing raw helper name/signature

Best descriptive name:

```cpp
CheatDetector::CaptureTimeSnapshot
```

Alternates considered:

- `GetTimeSnapshot`: acceptable but less clear that the object is updated.
- `SnapshotTimerState`: acceptable alias, but slightly too timer-focused because it also captures system file time.
- `CheckTimerSkew`: rejected for this helper alone because it does not compare or branch.
- `GetSystemTimeAsFileTime` wrapper: rejected because it also samples `TimerMgr::currentTick` and updates object state.

Recommended binary/source signature:

```cpp
void __thiscall CheatDetector::CaptureTimeSnapshot(unsigned int *timerTick,
                                                   unsigned __int64 *systemFileTime);
```

### 3. Class field names and layout

Best field layout:

| Offset | Recommended field | Evidence | Confidence |
| --- | --- | --- | --- |
| `+0x00` | `TimerHandler` vptr / derived vptr | base ctor writes `0x0062e338`; derived ctor writes `0x00615564` | high |
| `+0x04` | alignment gap, not a source field | first observed source field is 64-bit time at `+0x08`; allocation size `0x20` | medium-high |
| `+0x08` | `unsigned __int64 m_lastSystemFileTime` | raw helper writes low/high file-time dwords | high |
| `+0x10` | `unsigned int m_lastTimerTick` | raw helper writes `g_pTimerMgr+0x18`; ctor zeroes | high |
| `+0x14` | `unsigned int m_baselineTimerTick` | ctor zeroes next tick-like dword; likely paired with baseline time | medium |
| `+0x18` | `unsigned __int64 m_baselineSystemFileTime` | ctor zeroes two dwords aligned like a second file-time snapshot | medium |

Rejected alternatives:

- `detectionCount`, `suspicionLevel`, or `activeState` for `+0x14/+0x18/+0x1c`: rejected as final names because no observed branch, increment, threshold, or active-state use exists.
- `FILETIME m_lastSystemTime` at `+0x08` without padding explanation: rejected for formal layout because plain `FILETIME` alignment would normally put it at `+0x04` after a 4-byte `TimerHandler` base. `unsigned __int64` better explains the observed alignment.
- Unknown dword field at `+0x04`: possible if packing differs, but no read/write evidence supports a real field. Prefer an alignment note.

Remaining uncertainty:

- `m_baselineTimerTick` and `m_baselineSystemFileTime` are inferred from layout and anti-cheat timing context. If later evidence finds actual reads, names should be updated to match those uses.

### 4. TimerHandler inheritance/header shape

Best direction: `class CheatDetector : public TimerHandler`.

Evidence:

- Constructor calls `0x00597570`, which writes `TimerHandler::vftable`.
- Derived constructor writes `CheatDetector::vftable` immediately after.
- Scalar deleting destructor calls `0x00597580`, now documented as `TimerHandler_dtor`.
- CheatDetector vtable slot `+0x04` matches the timer callback shape: return `bool`, consume three explicit callback args.
- `ScheduledTimerEvent` layout and `TimerMgr` dispatch docs record owner/callback dispatch through the timer handler virtual surface.

Rejected alternatives:

- EventDispatcher base: stale generated/decompiler pollution; `0x00597580` caller spread and vtable writes show TimerHandler.
- boost exception base: stale IDA name only; body is timer unregister.
- LObject/dialog/pane base: no constructor/destructor/vtable evidence.
- Standalone no-base class: rejected by explicit base constructor/destructor calls and callback vtable shape.

### 5. OnTimer callback signature

Best signature:

```cpp
bool CheatDetector::OnTimer(int eventId, int arg0, int arg1);
```

Evidence:

- Vtable slot `+0x04` points to `0x00483fe0`.
- Body returns `true` and `ret 0x0c`.
- `TimerHandler` scheduler docs identify the queued record fields as `eventId`, `arg0`, and `arg1`.
- `TimerHandler` default callback helper nearby has the same `b0 01 c2 0c 00` body, although current vtable docs say the abstract base slot is `__purecall`.

Rejected alternatives:

- `IsEnabled()` / `CheckCheat()` / zero-argument boolean check: rejected by `ret 0x0c`.
- Free helper: rejected by vtable ownership.
- `OnUpdate()` with no event payload: rejected by TimerMgr callback record shape.

### 6. Singleton lifecycle

Best direction:

- `g_pCheatDetector` is source-declared under `security/CheatDetector.cpp`.
- Constructor publishes it.
- Constructor-unwind helper clears it if construction fails after early publication.
- Deleting-destructor wrapper clears it during teardown.
- Application startup and cleanup are consumers, not owners.

Evidence:

- Direct startup call at `0x0046473e` constructs a `0x20` byte object and calls `0x00483f00`.
- Application cleanup at `0x00464ba0` reads `g_pCheatDetector`, tests it, and dispatches vtable slot `+0x00` with delete flag `1`.
- Singleton data refs match constructor publish/null writes, clear helper, and deleting destructor clear.

Rejected alternatives:

- Application-owned global: rejected because startup/cleanup are consumers only.
- TimerMgr-owned global: rejected because timer manager is a base/service dependency and does not own the CheatDetector singleton.
- `client_anticheat` owner: rejected because it is a meta index, not an emitter/source file.

### 7. Constructor-unwind cleanup

Best direction: `ClearCheatDetectorSingleton` is compiler/EH cleanup for constructor failure, not a public method.

Evidence:

- The only route is the unwind functionlet jump at `0x005fc446`.
- Body writes only `g_pCheatDetector = 0`.
- It ignores the adjusted `ecx` passed by the funclet.

Rejected alternatives:

- Public `CheatDetector::Clear()` method: no normal call or receiver state.
- Application cleanup helper: no application call; cleanup uses vtable delete.
- Standalone global function to emit manually: likely compiler support generated from singleton registration/lifecycle source.

### 8. Destructor policy

Best direction:

- Binary-level name: `CheatDetectorScalarDeletingDestructor`.
- Source declaration: `virtual ~CheatDetector();`.
- Do not hand-write deleting-destructor glue.

Evidence:

- Vtable slot `+0x00`.
- `ret 4` delete-flag argument.
- Optional free when flags bit `1` is set.
- Calls `TimerHandler_dtor`.
- Returns receiver.

Source caveat:

- The binary clears `g_pCheatDetector` after `TimerHandler_dtor`. A naive handwritten destructor body `g_pCheatDetector = 0;` would normally run before base teardown in C++. Therefore the class report should recommend declaration-level destructor source now, not a final destructor body that overfits or misorders the cleanup. The singleton clear may have originated in an inlined registration helper/base/member or compiler-merged cleanup.

### 9. `client_anticheat` relationship

Best direction: `client_anticheat` remains a topical/meta index. It should mention CheatDetector as a timer-based retained anti-cheat singleton with no proven active detection logic in the compact island.

Support update needed:

- `by-meta/client_anticheat.md` already lists CheatDetector accurately in broad terms but should be refreshed with the class declaration decision, `CaptureTimeSnapshot` helper name, and the exact `0x0048402d` exclusive end.
- `by-project-structure/proposed-source-tree.md` still says `0x00483f00-0x0048402c` in the CheatDetector section. Replace that stale endpoint with `0x0048402d`.

### 10. First-draft class C++ readiness

Resolved as ready for class declaration/header shape.

Reasons:

- Owner/emitter route is valid and non-dead.
- Class, file parent, vtable, global, and child memory items all clear the minimum gate.
- Header/inheritance shape no longer depends on raw helper reachability.
- Field layout has a defensible source representation using `unsigned __int64` snapshots.

Do not overstate:

- The class C++ should be declaration-level in the class page.
- The raw helper body can be first-drafted in [UID:0002EN].
- The combined [UID:000109] page should keep formal C++ blank unless split, because it mixes a clean callback with constructor-unwind cleanup and deleting-destructor glue.

## First-Draft C++ for Relevant Children

### [UID:0002EN] Raw time-snapshot helper

Recommended for the helper page:

```cpp
void CheatDetector::CaptureTimeSnapshot(unsigned int *timerTick,
                                        unsigned __int64 *systemFileTime)
{
    FILETIME fileTime;
    GetSystemTimeAsFileTime(&fileTime);

    m_lastSystemFileTime =
        (static_cast<unsigned __int64>(fileTime.dwHighDateTime) << 32) |
        fileTime.dwLowDateTime;

    m_lastTimerTick = g_pTimerMgr->m_currentTick;
    *timerTick = m_lastTimerTick;
    *systemFileTime = m_lastSystemFileTime;
}
```

Implementation notes:

- Use the project's established type/name for `TimerMgr::currentTick` if support docs prefer a different final spelling.
- Do not add null checks; the binary has none.
- If the local style avoids `static_cast` in draft code, the equivalent `ULARGE_INTEGER` spelling is acceptable as long as the field remains a 64-bit file-time value.

### [UID:000109] Callback review-only body

Do not populate the combined range's formal C++ block unless it is split. Review-only callback body:

```cpp
bool CheatDetector::OnTimer(int eventId, int arg0, int arg1)
{
    return true;
}
```

Reason: [UID:000109] also includes constructor-unwind cleanup and scalar deleting-destructor glue. A callback-only formal body would underrepresent the covered range.

## Ranked Ownership Analysis

### 1. [UID:0000I6] `security/CheatDetector.cpp`

Evidence for:

- Proposed source-tree already places `CheatDetector.cpp` under `security/`.
- File page owns the compact startup-created class island.
- Application startup directly constructs the singleton.
- `g_pCheatDetector`, vtable, constructor, raw helper, callback, and deleting destructor are cohesive.
- Generated route is valid: `CheatDetector` class emits through `CheatDetector` file into `auto-generated/NexusTK/security/CheatDetector.cpp`.

Evidence against:

- The compact class has no active detection branch in the recovered callback.
- Raw helper has no incoming route.

Decision:

- Accept as source file and emitter. The caveats limit runtime-behavior claims, not source placement.

### 2. [UID:0000OT] `TimerMgr.cpp` / `TimerHandler`

Evidence for:

- `CheatDetector` inherits `TimerHandler`.
- Raw helper reads `g_pTimerMgr->currentTick`.
- `OnTimer` uses TimerHandler callback shape.

Evidence against:

- TimerMgr does not own the derived vtable, singleton, constructor, class fields, or security purpose.
- TimerHandler constructor/destructor are base dependencies used by many classes.

Decision:

- Dependency/base owner only. Do not move CheatDetector to TimerMgr.

### 3. [UID:0000HG] `Application.cpp`

Evidence for:

- Application startup constructs the object.
- Application cleanup deletes it through the singleton.

Evidence against:

- Consumer edges only.
- Vtable/global/source-file docs place the class in security.

Decision:

- Reject as owner. Keep as caller/consumer.

### 4. [UID:0001Q7] `client_anticheat`

Evidence for:

- The class is security/anti-cheat themed and belongs in the anticheat topical index.

Evidence against:

- Meta page has no emitter role.
- It groups CheatDetector with VirusChecker/KeySpeed/TimerSkew as documentation topics, not source ownership.

Decision:

- Keep as meta support/cross-reference only.

### 5. No-owner or non-emitting

Rejected:

- The class has a valid file parent, valid generated route, constructor caller, vtable, global, and memory children. No-owner/non-emitting would lose real source ownership.

## Negative Evidence Summary

- No call, jump, VA pointer, or RVA pointer to `0x00483f90` was found in the local PE scan. This prevents claiming the time-snapshot helper is currently executed.
- No strings, packet opcodes, UI resources, or diagnostic literals in the compact CheatDetector island were found from current docs/evidence. This prevents naming a concrete detection rule.
- No field access beyond constructor zeroing and raw helper writes is known for `+0x14/+0x18/+0x1c`. Baseline/comparison field names remain inferred.
- No proof supports `CheatDetector` as an Application or TimerMgr-owned class despite those consumer/dependency edges.
- The stale `EventDispatcher`/`boost::exception` labels around `0x00597580` are contradicted by TimerHandler vtable writes and `g_pTimerMgr` unregister behavior.
- The previous `0x0048402c` endpoint in proposed-source-tree/meta references is stale; the exact exclusive end is `0x0048402d`.

## Recommended Target and Support Doc Changes

### `by-class/CheatDetector.md`

Apply:

- `COMPLETION:85` -> `COMPLETION:88`.
- `CONFIDENCE:86` -> `CONFIDENCE:89`.
- Keep owner/emitter/reconstructable unchanged.
- Replace the current class C++ blank blocker with the declaration-level C++ block in this report.
- Add the field layout table:
  - `+0x00` vptr / `TimerHandler` base.
  - `+0x04` alignment gap from 64-bit file-time field.
  - `+0x08` `m_lastSystemFileTime`.
  - `+0x10` `m_lastTimerTick`.
  - `+0x14` `m_baselineTimerTick`.
  - `+0x18` `m_baselineSystemFileTime`.
- Explain why `unsigned __int64` is the preferred source type for file-time fields.
- Name the raw helper `CaptureTimeSnapshot`.
- State that raw helper no-route still blocks active-detection claims, not class declaration.
- Record destructor policy: declare `virtual ~CheatDetector()`, do not model the scalar deleting wrapper as handwritten source.

### `by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md`

Apply:

- Recommended score: `COMPLETION:87`, `CONFIDENCE:89`.
- Name the helper `CheatDetector::CaptureTimeSnapshot`.
- Replace "do not emit C++ until names/reachability are resolved" with the narrower caveat: no-route still blocks active-use claims, but exact behavior and source-style private helper C++ are ready.
- Add the first-draft helper C++ from this report.
- Add the local route scan negative evidence: no direct calls, jumps, VA refs, or RVA refs to the start.
- Add the field layout/argument type reasoning from this report.

### `by-memory/0x00483f00-0x0048402d.CheatDetector.md`

Apply:

- Recommended score: `COMPLETION:87`, `CONFIDENCE:90`.
- Refresh method inventory with `CaptureTimeSnapshot`, `OnTimer`, `ClearCheatDetectorSingleton`, and `CheatDetectorScalarDeletingDestructor`.
- Add source-layout inference and class declaration readiness.
- Preserve combined-range C++ caveat if this aggregate itself remains blank; child/class docs should carry source code.
- Record exact constructor byte/order evidence: early singleton publish, `TimerHandler::TimerHandler`, vtable install, zeroed offsets.

### `by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md`

Apply no score change unless desired. Add cross-reference:

- Class declaration is now ready and should include `virtual bool OnTimer(int eventId, int arg0, int arg1)` and `virtual ~CheatDetector()`.
- Keep this combined range formal C++ blank unless split.
- Preserve B012's no-code proof for the combined range.

### `by-file/CheatDetector.md`

Recommended score: optionally raise `87/87` to `88/88` after support incorporation.

Add:

- `CheatDetector.cpp` should emit class declaration/header support and the raw helper body under `NexusTK/security/`.
- The raw helper is source-authored retained private member code, not active detection proof.
- Replace "do not emit final C++ for it until 95+" wording with current gate-aware policy: helper/body draft is ready at the child page, but final active-detection behavior remains capped by no-route evidence.

### `by-global/g_pCheatDetector.md` and `by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md`

Add:

- Class declaration support now justifies a first-draft source declaration:

```cpp
CheatDetector *g_pCheatDetector = 0;
```

- Preserve historical byte discrepancy notes if desired, but current local PE bytes and current IDA notes agree on zeroed storage.
- Clarify that application cleanup is a consumer, while the owner remains `CheatDetector.cpp`.

### `by-type/by-vtable/CheatDetectorVtable.md` and `by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md`

Add:

- The class declaration should regenerate the vtable from `virtual ~CheatDetector()` and `virtual bool OnTimer(int eventId,int arg0,int arg1)`.
- Keep raw vtable data source-declared/generated-binary; do not hand-copy table bytes.

### `by-meta/client_anticheat.md`

Add/update:

- Exact class range is `0x00483f00-0x0048402d`.
- Raw helper source name is `CaptureTimeSnapshot`.
- `CheatDetector` visible callback remains true-return only; active detection logic in this island is not proven.

### `by-project-structure/proposed-source-tree.md`

Update stale line:

- Replace `0x00483f00-0x0048402c` with `0x00483f00-0x0048402d` in the `security/CheatDetector.cpp` section.
- Optionally add that `CheatDetector.cpp` now has a declaration-level class C++ recommendation and a first-draft private time-snapshot helper.

### `auto-generated/NexusTK/security/CheatDetector.cpp`

Do not hand-edit. If the local validator/autogen workflow updates generated output from C++ blocks, rerun it after implementation.

## Exact Implementation Checklist for Supervisor Callback

1. Update `by-class/CheatDetector.md`:
   - Set `COMPLETION:88`.
   - Set `CONFIDENCE:89`.
   - Keep owner/emitter/reconstructable unchanged.
   - Insert the class declaration C++ block from this report.
   - Add class field layout and source-type rationale.
   - Add resolved helper name/signature `CaptureTimeSnapshot`.
   - Add `OnTimer(eventId,arg0,arg1)` signature and destructor-wrapper policy.
   - Preserve raw helper no-route caveat as runtime-behavior cap.

2. Update `by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md`:
   - Set `COMPLETION:87`.
   - Set `CONFIDENCE:89`.
   - Add first-draft helper C++.
   - Record no route found by direct call/jump/VA/RVA scan.
   - Document field/out-argument names.

3. Update `by-memory/0x00483f00-0x0048402d.CheatDetector.md`:
   - Set `COMPLETION:87`, keep `CONFIDENCE:90`.
   - Update inventory/source-layout/class-readiness details.

4. Update support docs:
   - `by-file/CheatDetector.md`
   - `by-global/g_pCheatDetector.md`
   - `by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md`
   - `by-type/by-vtable/CheatDetectorVtable.md`
   - `by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md`
   - `by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md`
   - `by-meta/client_anticheat.md`
   - `by-project-structure/proposed-source-tree.md`

5. Do not edit `by-memory/-coverage-report.md`; supervisor should apply the exact replacement rows below.

6. Run scoped validators from `source-3/project-documentation` after implementation.

7. Run autogen/rescore if the workflow regenerates `auto-generated/NexusTK/security/CheatDetector.cpp` from new C++ blocks.

## Exact Coverage Text

### `by-class/-coverage-report.md` replacement row

Replace the [UID:000020] row with:

```text
- [UID:000020][CheatDetector](by-class/CheatDetector.md) : reconstructable : 88% : strong : B002 2026-06-19 source-quality pass resolves the class as a `TimerHandler`-derived startup singleton under `NexusTK/security/CheatDetector.cpp`, with `g_pCheatDetector` lifecycle, two-slot vtable, `OnTimer(eventId,arg0,arg1)` true-return callback, constructor-unwind singleton clear, scalar deleting destructor wrapper policy, and class field layout. Raw helper `0x00483f90` is best modeled as private retained `CaptureTimeSnapshot(unsigned int*, unsigned __int64*)`, sampling `GetSystemTimeAsFileTime` plus `g_pTimerMgr->currentTick` into `m_lastSystemFileTime`/`m_lastTimerTick` and output pointers; it still has no direct call/jump/VA/RVA route, so active detection behavior remains unproven. First-draft class declaration C++ is ready; method bodies remain in by-memory children or compiler-generated wrapper support.
```

### `by-memory/-coverage-report.md` replacement rows

Replace the [UID:000108] row with:

```text
    - [UID:000108][0x00483f00-0x0048402d.CheatDetector](by-memory/0x00483f00-0x0048402d.CheatDetector.md) 0x00483f00-0x0048402d | class method cluster | CheatDetector : reconstructable : 87% : very strong : B002 2026-06-19 class source-quality pass confirms modeled constructor bytes, early `g_pCheatDetector` publication, constructor-unwind clear route through `0x005fc446 -> 0x00483ff0`, `TimerHandler::TimerHandler` call, `CheatDetector` vtable install, field zeroing at `+0x10/+0x14/+0x18/+0x1c`, raw private `CaptureTimeSnapshot` helper at `0x00483f90`, true-return `OnTimer(eventId,arg0,arg1)` vtable callback, scalar deleting-destructor wrapper over confirmed `TimerHandler_dtor`, exact padding boundaries, application startup/cleanup consumers, and class declaration readiness. The raw helper still has no direct route, so active anti-cheat behavior remains capped, but source layout and first-draft child/class C++ are ready.
```

Replace the [UID:0002EN] row with:

```text
      - [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md) 0x00483f90-0x00483fd9 | retained private time-snapshot helper | CheatDetectorTimeSnapshotHelper : reconstructable : 87% : strong : B002 2026-06-19 source-quality pass resolves the raw no-IDA-function body as `CheatDetector::CaptureTimeSnapshot(unsigned int *timerTick, unsigned __int64 *systemFileTime)`: it calls `GetSystemTimeAsFileTime`, stores a 64-bit file-time snapshot at `this+0x08/+0x0c`, reads `g_pTimerMgr->currentTick` from `+0x18`, stores it at `this+0x10`, copies tick/time to the two out-parameters, and returns with `ret 8`. Local route scan found no direct call, jump, VA pointer, or RVA pointer to `0x00483f90`, so active execution remains unproven; nevertheless the helper is bounded source-authored project code inside the CheatDetector island and first-draft helper C++ is ready with the no-route caveat.
```

No replacement is required for [UID:000109] if the current B012 row is already present. If supervisor wants a consistency refresh only, preserve the current score/summary and add a sentence that class-level declaration is now ready while the combined range remains no-code.

## Expected Validation Commands After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [000020-CheatDetector-class-source-quality-removed.md](000020-CheatDetector-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If generated output is refreshed:

> Executable block R002 was removed from this report and preserved verbatim in [000020-CheatDetector-class-source-quality-removed.md](000020-CheatDetector-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: scoped validators should pass or apply only formatting/path-reference updates. If validator rejects class-level C++ because the local class-page convention wants declaration-only or excludes `extern`, keep the declaration block and move the global declaration recommendation to `by-global/g_pCheatDetector.md`.

## IDA Rename / Type / Comment Recommendations

Function renames:

- `sub_483F00` -> `CheatDetector_ctor` or `CheatDetector::CheatDetector`.
- raw `0x00483f90` -> `CheatDetector_CaptureTimeSnapshot`.
- `sub_483FE0` -> `CheatDetector_OnTimer`.
- `sub_483FF0` -> `ClearCheatDetectorSingleton`.
- `sub_484000` -> `CheatDetectorScalarDeletingDestructor`.
- Keep `0x00597570` as `TimerHandler_ctor`.
- Keep `0x00597580` as `TimerHandler_dtor`.

Recommended types:

```cpp
CheatDetector *__thiscall CheatDetector_ctor(CheatDetector *this);
void __thiscall CheatDetector_CaptureTimeSnapshot(CheatDetector *this,
                                                  unsigned int *timerTick,
                                                  unsigned __int64 *systemFileTime);
bool __thiscall CheatDetector_OnTimer(CheatDetector *this, int eventId, int arg0, int arg1);
void __cdecl ClearCheatDetectorSingleton();
void *__thiscall CheatDetectorScalarDeletingDestructor(CheatDetector *this, unsigned int flags);
```

Recommended comments:

- Constructor: "Publishes `g_pCheatDetector`, constructs TimerHandler base, installs CheatDetector vtable, initializes timing comparison fields; unwind funclet clears early singleton publication."
- Raw helper: "Retained private CheatDetector time snapshot helper; samples system file time and TimerMgr current tick into object and out parameters; no incoming route found."
- Callback: "TimerHandler callback override; consumes event id and two payload args; returns true without detection work in recovered body."
- Deleting destructor: "MSVC scalar deleting destructor wrapper; calls TimerHandler_dtor, clears singleton, optionally frees 0x20-byte object."

## Remaining Open Questions and Score Impact

1. Why is `CaptureTimeSnapshot` retained without an incoming route?
   - Evidence checked: direct call, jump, VA pointer, and RVA pointer scans; existing docs also report IDA no-function/no-xref state.
   - Best current answer: retained source-authored private member, likely unused in the visible build or kept because the object file was linked whole.
   - Score impact: prevents claiming active anti-cheat behavior and keeps helper/class below final audit, but does not block first-draft source.

2. Exact original field names for `+0x14/+0x18/+0x1c`.
   - Evidence checked: constructor zeroing and raw helper field writes; no reads/branches found in current compact island.
   - Best current answer: baseline/comparison timer tick and file-time snapshot fields.
   - Score impact: medium confidence; names should be clearly marked descriptive.

3. Exact singleton registration mechanism.
   - Evidence checked: constructor order, unwind funclet, scalar deleting destructor order.
   - Best current answer: source-visible singleton lifecycle under `CheatDetector.cpp`, possibly generated/inlined from a small singleton-registration idiom. Do not infer a separate base without vtable/destructor/size evidence.
   - Score impact: class declaration can include `extern CheatDetector *g_pCheatDetector`; avoid final handwritten constructor/destructor bodies until implementation owns exact order.

4. Whether there is anti-cheat logic outside this island.
   - Evidence checked: `client_anticheat` docs, proposed tree, application timing docs as leads.
   - Best current answer: not proven in this assignment. `CheckTimerSkewAndSendHeartbeat` remains Application timing, not CheatDetector ownership.
   - Score impact: runtime purpose is security-timer singleton, but active detection remains unproven.

## Validator Results

Commands run during report pass:

- No validator commands were run because no by-* documentation was edited.

Read-only commands/evidence collected:

- Read B002 `goal.md`.
- Read target and support docs listed throughout this report.
- Searched existing B-agent reports for CheatDetector prior research.
- Ran local PE byte/xref scans and Capstone disassembly over the relevant executable ranges.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B002/research/000020-CheatDetector-class-source-quality.md`

Modified:

- None outside the required B002 research report.

Coverage:

- `by-memory/-coverage-report.md` was not edited. Exact replacement rows are provided above for supervisor-owned application.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/000020-CheatDetector-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"000020"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000020-CheatDetector-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/000020-CheatDetector-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000020"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
