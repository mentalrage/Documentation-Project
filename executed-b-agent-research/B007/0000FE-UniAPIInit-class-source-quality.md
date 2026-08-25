** TARGET-REPORT-UID:0000FE **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# FINISHED - [UID:0000FE] UniAPIInit Class Source-Quality Reanalysis

Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\UniAPIInit.md`

Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B007\research\0000FE-UniAPIInit-class-source-quality.md`

Report-only scope: no `by-*` documentation files were edited, and `by-memory/-coverage-report.md` was not edited.

## Finalized Report / Current Recommendation

- Current recommendation: keep `UniAPIInit` as a reconstructable PlatformApi-owned class, but resolve its source shape as a file-local static initializer object rather than the stale generated destructor body at `0x005995b0`.
- Final disposition: update [UID:0000FE] from `88/85` to `90/88`; keep `CANONICAL_OWNER:0000ML`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000ML`.
- Required action after supervisor acceptance: populate class-level first-draft C++ with the `UniAPIInit` declaration, document `static UniAPIInit s_uniAPIInit` as the best-supported file-local object spelling, and synchronize the PlatformApi/WideApiDispatchTable/support memory docs with the exact source-shape decisions below.
- C++ recommendation: emit class-level C++ now for [UID:0000FE]. Do not emit the raw/generated `0x005995b0` aggregate as a standalone source body. The source-authored behavior should be represented as `UniAPIInit` static-object construction / a PlatformApi dispatch-initialization helper, while the cleanup wrapper, vtable data, scalar deleting destructor, and vptr-only reset are compiler-generated or ABI support.
- Confidence: strong for class name, PlatformApi source placement, real initializer, dispatch-table ownership, vtable/static-slot relation, and stale generated-body rejection; medium-high for exact original variable spelling and whether the original body was written directly in the constructor or through a private file-local helper.

## Target Baseline

Current target metadata:

```text
*** COMPLETION:88
*** CONFIDENCE:85
*** CANONICAL_OWNER:0000ML
*** RECONSTRUCTABLE:TRUE
*** EMITTER_UIDS:0000ML
```

Current target summary already records the important anchors:

- [UID:0000WD] `0x0041a280-0x0041a4a8.WideApiDispatchInit` is the real dispatch-table initializer.
- [UID:0001KE] `0x005995b0-0x00599a34.UniAPIInit` is a raw/generated caveat span, not trustworthy final source.
- `0x005997e0-0x005997e7` is a vtable reset helper.
- [UID:0001O9] `0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper` is static cleanup glue.
- `0x00599a10-0x00599a34` is the scalar deleting destructor.
- [UID:00028B] `0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot` is the static object vptr slot.
- [UID:0003E5] `0x0062e57c-0x0062e580.UniAPIInitVtableData` is the exact one-dword vtable data child.
- [UID:0000TQ] `WideApiDispatchTable` owns the concrete `0x0069be14-0x0069bed0` dispatch storage.

The remaining target open questions were source-quality questions, not broad ownership blockers:

- final class/static object source spelling;
- final dispatch table declaration style;
- whether `0x005995b0` should become C++ or remain a generated/raw caveat;
- whether the class page should emit C++ under the current code-entry rule.

This report closes those questions to the strongest defensible current direction.

## Instructions And Evidence Sources Checked

Read current instructions and guidance:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B007/goal.md`
- `.codex/AGENTS.md`
- `by-structure.md`
- `inference_research.md`

Read target and support docs:

- [UID:0000FE] `by-class/UniAPIInit.md`
- [UID:0000ML] `by-file/PlatformApi.md`
- [UID:0000TQ] `by-global/WideApiDispatchTable.md`
- [UID:0000WD] `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`
- [UID:0001KE] `by-memory/0x005995b0-0x00599a34.UniAPIInit.md`
- [UID:0001O9] `by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md`
- [UID:00028B] `by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md`
- [UID:0003E5] `by-memory/0x0062e57c-0x0062e580.UniAPIInitVtableData.md`
- [UID:000249] `by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md`
- [UID:0002AS] `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`
- [UID:0001Q1] `by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md`
- [UID:0002A6] `by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md`
- [UID:0001R1] `by-project-structure/proposed-source-tree.md`
- Generated source lead: `source-3/simroot_v2/class_UniAPIInit.cpp`
- Current generated output lead: `auto-generated/NexusTK/platform/PlatformApi.cpp`
- Current coverage/generated rows for [UID:0000FE], [UID:0001KE], [UID:0003E5], [UID:00028B], [UID:0000WD], [UID:0000TQ], and dispatch-table children.
- Prior B-agent executed research lead: `Agent-B002/research/executed/000249-platform-string-conversion-source-quality.md`.

IDA MCP status:

- Attempted `tools/list` at `http://127.0.0.1:13337/mcp`.
- Result: `MCP_UNAVAILABLE: Unable to connect to the remote server`.
- Current-session disassembly evidence below comes from the raw PE `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` with local PE parsing and Capstone. Existing IDA-backed docs remain evidence, and current raw checks were used to validate or challenge them.

## Scoped Validator Baseline

Command:

> Executable block R001 was removed from this report and preserved verbatim in [0000FE-UniAPIInit-class-source-quality-removed.md](0000FE-UniAPIInit-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
exit code: 0
mode: file
scanned markdown files: 1
ok: 1
ok 0000FE by-class/UniAPIInit.md UID header exists
```

The validator was run as a dry-run baseline only. No `--apply` write was requested.

## Current-Session Raw PE Evidence

Raw binary checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`

PE facts from current-session parsing:

- Image base: `0x00400000`.
- `.text`: `0x00401000-0x0060c600`, raw executable bytes.
- `.rdata`: `0x0060d000-0x0066c200`.
- `.data`: `0x0066d000-0x0069ce24`; the dispatch table at `0x0069be14+` lies in the virtual zero-fill tail rather than in raw file bytes. That supports writable runtime-initialized global dispatch storage, not const table data.

### Real Initializer At `0x0041a280`

Raw disassembly confirms [UID:0000WD] as the real startup-table initializer:

```text
0x0041a280: prologue, stack allocation 0x98
0x0041a299: OSVERSIONINFOA.dwOSVersionInfoSize = 0x94
0x0041a2a4: call KERNEL32.dll!GetVersionExA
0x0041a2aa: compare dwPlatformId with 2
0x0041a2b1: dword_69BE1C = 0x00599570 / ReadUtf16CodeUnitFromFile
0x0041a2bb: branch around NT wide table if platform id is not 2
0x0041a48d: push 0x0060c440
0x0041a492: call atexit helper
0x0041a4a7: ret
```

Current raw xref scan:

- No rel32 call/jump to `0x0041a280`.
- One absolute data reference to `0x0041a280` at `0x0060d71c`, matching startup initializer table evidence.

The `0x0041a280` body is therefore the startup dynamic-initialization entry for PlatformApi/UniAPIInit state, not an ordinary source-called function.

### Full NT Wide Dispatch Assignment Sequence

Current-session raw import/disassembly parsing confirms these stores:

| Slot | Assigned target/source |
| --- | --- |
| `0x0069be1c` | `ReadUtf16CodeUnitFromFile` at `0x00599570`, unconditional after `GetVersionExA` |
| `0x0069be20` | `FindWindowW` |
| `0x0069be24` | `OpenFileMappingW` |
| `0x0069be28` | `CreateMutexW` |
| `0x0069be2c` | `CreateDialogParamW` |
| `0x0069be30` | `LoadLibraryW` |
| `0x0069be34` | `CreateFileW` |
| `0x0069be38` | `CreateProcessW` |
| `0x0069be3c` | `CreateEventW` |
| `0x0069be40` | `RegisterClassW` |
| `0x0069be44` | `CreateWindowExW` |
| `0x0069be48` | `CreateFileMappingW` |
| `0x0069be4c` | `CreateSemaphoreW` |
| `0x0069be50` | `DefWindowProcW` |
| `0x0069be54` | `RegisterClipboardFormatW` |
| `0x0069be58` | `CharUpperBuffW` |
| `0x0069be5c` | `CreateDirectoryW` |
| `0x0069be60` | `DeleteFileW` |
| `0x0069be64` | `DispatchMessageW` |
| `0x0069be68` | `FindFirstFileW` |
| `0x0069be6c` | `FormatMessageW` |
| `0x0069be70` | `GetCurrentDirectoryW` |
| `0x0069be74` | `GetModuleFileNameW` |
| `0x0069be78` | `GetModuleHandleW` |
| `0x0069be7c` | `GetWindowsDirectoryW` |
| `0x0069be80` | `GlobalGetAtomNameW` |
| `0x0069be84` | `LoadCursorW` |
| `0x0069be88` | `LoadIconW` |
| `0x0069be8c` | `PeekMessageW` |
| `0x0069be90` | `PostMessageW` |
| `0x0069be94` | `RegCreateKeyExW` |
| `0x0069be98` | `RegDeleteKeyW` |
| `0x0069be9c` | `RegEnumValueW` |
| `0x0069bea0` | `RegQueryInfoKeyW` |
| `0x0069bea4` | `RegQueryValueExW` |
| `0x0069bea8` | `RegSetValueExW` |
| `0x0069beac` | `SetCurrentDirectoryW` |
| `0x0069be14` | `_wfopen` wrapper/address `0x005d253a` |
| `0x0069be18` | `_wstat64i32` wrapper/address `0x005e25aa` |
| `0x0069beb0` | `GetFileVersionInfoSizeW` wrapper/address `0x005c5c8d` |
| `0x0069beb4` | `GetFileVersionInfoW` wrapper/address `0x005c5c93` |
| `0x0069beb8` | `VerQueryValueW` wrapper/address `0x005c5c99` |
| `0x0069bebc` | `ImmGetCompositionStringW` wrapper/address `0x005c5cc9` |
| `0x0069bec0` | `ImmGetCandidateListW` wrapper/address `0x005c5ce7` |
| `0x0069bec4` | `SendMessageW` |
| `0x0069bec8` | `GetLocaleInfoW` |
| `0x0069becc` | `SetFileAttributesW` |

The table is not owned by any consumer module. Current raw scan again finds broad consumer references to representative slots:

- `0x0069be14`: 41 absolute references, including file/resource/logo consumers.
- `0x0069be18`: 5 absolute references, including `StdioFileOpen` and `PathExistsViaStat`.
- `0x0069be1c`: 11 absolute references, including the real initializer and raw/generated projection refs.
- `0x0069bec4`: 17 absolute references, including browser/socket/message consumers plus generated projection writes.

### Raw/Generated `0x005995b0` Caveat

Raw disassembly confirms `0x005995b0` is constructor-shaped:

```text
0x005995b0: prologue
0x005995c3: push esi
0x005995c4: esi = ecx
0x005995d7: [esi] = 0x0062e57c / UniAPIInit vtable
0x005995dd: call GetVersionExA
0x005995ea: dword_69BE1C = 0x00599570 / ReadUtf16CodeUnitFromFile
0x005995f4: branch around NT wide table if platform id is not 2
...
0x005997dc: ret
```

But current raw xref scan finds:

- no rel32 call/jump to `0x005995b0`;
- no absolute pointer reference to `0x005995b0`;
- no modeled direct route from startup or vtable data to `0x005995b0`.

Therefore, the source-quality conclusion is not "initializer is unknown." The best inference is:

- `0x005995b0` is a constructor-shaped duplicate or retained raw body that Wave3 projected as `UniAPIInit::~UniAPIInit`, but the executable startup route does not use this address.
- The destructor label is stale and should be recorded as historical/generated error.
- If the raw body is ever split into exact children, the `0x005995b0-0x005997dd` subspan should be treated as `UniAPIInit::UniAPIInit()`-shaped code, not a destructor, but no current final source should emit from that unreferenced raw span.

### Second Raw Projection At `0x005997f0`

Raw disassembly around `0x005997f0` confirms a second initializer-shaped copy:

```text
0x005997e7-0x005997ef: 9 bytes of 0xcc padding
0x005997f0: prologue
0x00599814: call GetVersionExA
0x00599821: dword_69BE1C = 0x00599570
0x00599831+: NT wide table assignments
0x005999e4: dword_69BEC4 = SendMessageW
0x005999fd-0x00599a0a: security-cookie check and ret
0x00599a0b-0x00599a10: 5 bytes of 0xcc padding
```

Current docs already model this as part of [UID:0001KE]'s raw/generated caveat span. This pass validates that treatment. It is initializer-shaped, but it is not a safer source owner than `0x0041a280` because no direct startup-table xref or call route reaches it.

### Vtable Reset Helper At `0x005997e0`

Exact raw body:

```text
0x005997e0: mov dword ptr [ecx], 0x0062e57c
0x005997e6: ret
```

Current raw xref scan:

- no direct rel32 callers;
- no absolute pointer refs to `0x005997e0`.

Best interpretation: this is a vptr-only `UniAPIInit` ctor/dtor fragment, most likely an unused non-deleting destructor or vptr-reset helper emitted by the compiler. It should remain documented as ABI/static-lifetime support, not as meaningful handwritten source logic.

### Scalar Deleting Destructor At `0x00599a10`

Exact raw body:

```text
0x00599a10: prologue
0x00599a13: test byte ptr [ebp+8], 1
0x00599a1a: [esi] = 0x0062e57c / UniAPIInit vtable
0x00599a20: branch if no delete
0x00599a25: call delete/free helper with size 4
0x00599a31: ret 4
```

Current raw xref scan:

- one absolute reference to `0x00599a10` at `0x0062e57c`, the one-slot `UniAPIInit` vtable.

Best interpretation: this is MSVC scalar deleting destructor glue for `UniAPIInit`, not a source-authored public method body. The source should declare a virtual destructor, probably empty or defaulted. The generated scalar deleting destructor should be produced by the compiler.

### Static Cleanup Wrapper At `0x0060c440`

Exact raw body:

```text
0x0060c440: mov dword ptr [0x006702c4], 0x0062e57c
0x0060c44a: ret
```

Current raw xref scan:

- one absolute text reference to `0x0060c440` at `0x0041a48e`, the `_atexit` registration inside the real initializer.
- one absolute text reference to `0x006702c4` at `0x0060c442`, the cleanup wrapper write.

Best interpretation: this is compiler/static-lifetime cleanup for the file-local static `UniAPIInit` object. It should stay `RECONSTRUCTABLE:FALSE` as a standalone memory item and be regenerated by the compiler from the static object plus virtual destructor declaration.

### Vtable Data And Static Object Slot

Current raw scan validates the existing docs:

- `0x0062e57c` is referenced by the raw constructor-shaped body at `0x005995d9`, vptr reset helper at `0x005997e2`, scalar deleting destructor at `0x00599a1c`, static cleanup wrapper at `0x0060c446`, and static object slot `0x006702c4`.
- `0x006702c4` has exactly one current text writer: `0x0060c440`.

Best interpretation:

- [UID:0003E5] `0x0062e57c-0x0062e580` is compiler-emitted vtable data for the `UniAPIInit` class.
- [UID:00028B] `0x006702c4-0x006702c8` is the storage for a file-local static `UniAPIInit` object whose only concrete data member is the vptr. It should be source-declared as a static object, not as an explicit `void *` or raw vtable pointer.

## Function / Data Inventory

| Item | Current UID / path | Role | Reconstructable | Best direct owner | Status |
| --- | --- | --- | --- | --- | --- |
| `UniAPIInit` class | [UID:0000FE] `by-class/UniAPIInit.md` | Platform API static initializer class | TRUE | [UID:0000ML] PlatformApi | Keep and improve; emit class declaration. |
| `0x0041a280-0x0041a4a8` | [UID:0000WD] `WideApiDispatchInit` | Real startup dynamic initializer/inlined dispatch setup | TRUE | [UID:0000ML] PlatformApi | Keep as exact code anchor; update source-shape notes. |
| `0x005995b0-0x00599a34` | [UID:0001KE] `UniAPIInit` memory aggregate | Raw/generated duplicate/caveat aggregate | TRUE container/caveat | [UID:0000ML] PlatformApi | Keep C++ deferred; document constructor-shaped not destructor. |
| `0x005997e0-0x005997e7` | inside [UID:0001KE] | Vptr-only reset/non-deleting dtor-like helper | compiler/ABI support | [UID:0000FE] conceptually, but no standalone source | Do not emit as handwritten source. |
| `0x00599a10-0x00599a34` | inside [UID:0001KE] and [UID:0003E5] vtable value | Scalar deleting destructor | compiler/ABI support | [UID:0000FE] | Represent by virtual destructor declaration, not manual body. |
| `0x0060c440-0x0060c44b` | [UID:0001O9] | Static cleanup wrapper | FALSE | NONE | Keep ignored/non-emitting compiler cleanup wrapper. |
| `0x0062e57c-0x0062e580` | [UID:0003E5] | One-slot vtable data | TRUE source-declared/generated-binary | [UID:0000FE] | Keep class-owned, no manual dword code. |
| `0x006702c4-0x006702c8` | [UID:00028B] | Static object vptr slot | TRUE source-declared/generated-binary | [UID:0000ML] PlatformApi | Rename/source-shape as `s_uniAPIInit` static object storage if accepted. |
| `0x0069be14-0x0069bed0` | [UID:0000TQ] and child pages | Wide API dispatch function-pointer storage | TRUE source-declared/generated-binary | [UID:0000ML] PlatformApi via [UID:0000TQ] | Keep as individual dispatch pointer declarations grouped by table doc. |

## Ranked Ownership And Source Placement Analysis

### 1. PlatformApi file [UID:0000ML] - accepted

Evidence for:

- The source tree already places `PlatformApi.cpp` under `NexusTK/platform/`.
- [UID:0000ML] owns the platform string conversion helpers, OLE/AutoInit compatibility bucket, and Win32 dispatch table docs.
- The real initializer writes only process-wide platform dispatch entries and registers static cleanup.
- Dispatch table consumers are broad: file I/O, path checks, logo loader, input/IME, browser/socket message dispatch, thread/event code, registry/config helpers, MIDI/file loaders, and locale helpers.
- The table is not semantically local to any one consumer.
- The static object has no direct UI, network, file-I/O, browser, or render ownership signal.

Evidence against:

- `AutoInit` might later move to a browser/OLE-specific file, but that does not weaken `UniAPIInit` dispatch-table placement.
- The generated `class_UniAPIInit.cpp` one-class file is a Wave3 staging artifact, not original source proof.

Decision: keep [UID:0000FE] owned/emitted through [UID:0000ML] `PlatformApi`.

### 2. UniAPIInit class as direct owner of vtable/class declaration - accepted for class artifacts only

Evidence for:

- The vtable symbol name `??_7UniAPIInit@@6B@` directly proves the class name.
- [UID:0003E5] correctly uses [UID:0000FE] as direct owner for vtable data.
- The scalar deleting destructor and vptr reset helper are class ABI artifacts.

Evidence against:

- The dispatch storage itself is global/file-level table state, not a class member table.
- The static object slot is file-local static storage in PlatformApi, not a static data member proven by symbol or access pattern.

Decision: keep class-owned artifacts under [UID:0000FE], but do not move WideApiDispatchTable or static object storage wholesale under the class.

### 3. WideApiDispatchTable global [UID:0000TQ] - accepted for storage grouping, not class ownership

Evidence for:

- Exact table children [UID:0002AS], [UID:0001Q1], and [UID:0002A6] are direct storage children.
- Table slots share initializer, consumer style, and source declaration style.

Evidence against:

- The `UniAPIInit` class and static object are not themselves table entries.
- The table doc should own function-pointer storage, not executable initializer code or class declaration.

Decision: keep [UID:0000TQ] as table/global grouping under PlatformApi.

### 4. Consumer modules - rejected

Rejected owners:

- `StdioFile` and `PathUtil`: consume `_wfopen` and `_wstat64i32` slots but do not own the table.
- `Browser` / transport: consume `SendMessageW` slot but do not own `0x0069bec4`.
- `InputMan`: consumes IME/default-window/message slots but does not own them.
- `Thread` / `WaitableTimer`: consume `CreateEventW` and related slots but do not own PlatformApi dispatch state.
- `Application`: startup table references `0x0041a280`, but that is runtime initialization route evidence, not source ownership.

Decision: all are consumers only.

## Heuristic / Inference Reanalysis And Validation

### Class name

Best-supported name: `UniAPIInit`.

Evidence:

- Current IDA-backed docs report vtable symbol `??_7UniAPIInit@@6B@`.
- Current raw scan shows the vtable dword at `0x0062e57c` points to the scalar deleting destructor at `0x00599a10`.
- Static object slot and cleanup wrapper both use the same vtable address.

Rejected alternatives:

- `WideApiDispatchInit`: correct for the initializer role but not the class name.
- `UnicodeApiInitializer`: descriptive but unnecessary because the binary already exposes `UniAPIInit`.
- `PlatformApiInit`: plausible source concept but weaker than the recovered class/vtable name.

Decision: keep `UniAPIInit`.

### Static object name and storage shape

Best-supported source shape:

```cpp
static UniAPIInit s_uniAPIInit;
```

Confidence: medium-high descriptive, not original-spelling proof.

Evidence:

- `0x006702c4-0x006702c8` is one object-sized vptr slot initialized to `UniAPIInit` vtable data.
- The cleanup wrapper registered through `atexit` writes that vtable pointer back into the slot.
- No ordinary source code reads the slot as a function pointer table or generic global pointer.
- The source effect needed to recreate the slot is a file-local static object of type `UniAPIInit`, not a hand-authored vptr variable.

Rejected alternatives:

- `void *UniAPIInitStaticObjectVptr`: describes bytes but would hand-port a compiler implementation detail.
- `UniAPIInit *g_pUniAPIInit`: rejected because the memory is the object storage itself, not a pointer-to-object slot.
- `g_uniAPIInit`: plausible, but `s_uniAPIInit` better communicates file-local static lifetime. If the wider project strongly prefers `g_` for all file statics, `g_uniAPIInit` is an acceptable naming-style adjustment. The semantic recommendation is the file-local static object, not the exact prefix.
- Class static member `UniAPIInit::s_instance`: rejected because no class-member symbol, method access, or exported address-taking evidence proves class-static ownership.

Decision: document the storage as file-local static `UniAPIInit s_uniAPIInit`, with exact spelling marked inferred/descriptive.

### Real initializer source shape

Best-supported source shape:

- Source-authored logic belongs to `UniAPIInit` construction or a private PlatformApi helper called by that constructor.
- Binary `0x0041a280` is the startup dynamic initializer that installs the dispatch table and registers static cleanup.

Evidence:

- `0x0041a280` has startup-table data xref `0x0060d71c`, not ordinary callers.
- It writes the dispatch table and registers the cleanup wrapper.
- The raw constructor-shaped `0x005995b0` duplicate sets `this` vptr and performs the same dispatch setup but has no route.
- This is a normal MSVC-era pattern when static object initialization and unused/out-of-line constructor bodies both survive or are recovered inconsistently.

Rejected alternatives:

- Handwritten free function `WideApiDispatchInit()` called by application startup: weaker because no ordinary source call exists; the xref is startup table data and the cleanup wrapper is static-object cleanup.
- `UniAPIInit::~UniAPIInit()` does initialization: rejected. A destructor would not call `GetVersionExA` and install the process-wide API table; the generated destructor projection is stale.
- A pure compiler-generated wrapper with no source-authored logic: rejected because the table assignments and platform compatibility policy are source behavior that must be represented in rebuilt PlatformApi code.

Decision: represent source as `UniAPIInit` static object construction, with an optional private helper such as `InstallWideApiDispatchTable()` if support docs need a cleaner body owner.

### Raw/generated `0x005995b0` caveat

Best-supported interpretation:

- `0x005995b0-0x005997dd` is constructor-shaped duplicate/raw code.
- `0x005997f0-0x00599a0a` is a second initializer-shaped duplicate/raw code span.
- The aggregate [UID:0001KE] should remain a source-quality caveat unless later split work creates exact children and decides how to represent the duplicates.

Evidence:

- Current raw scan finds no direct route to `0x005995b0`.
- Current docs and prior IDA checks agree IDA does not model `0x005995b0` as a function.
- Current raw disassembly still shows valid function-shaped bytes.
- The true startup route is `0x0041a280`, not this span.

Rejected alternatives:

- Emit [UID:0001KE] as `UniAPIInit::~UniAPIInit()`: rejected as stale generated output.
- Ignore the span entirely as padding: rejected because the bytes are real initializer-shaped instructions with table writes and security-cookie checks.
- Make it the canonical initializer body: rejected because no startup xref reaches it.

Decision: keep [UID:0001KE] reconstructable as a raw/generated caveat aggregate, but do not populate its formal C++ block yet.

### Vtable reset helper

Best-supported interpretation:

- `0x005997e0` is a vptr-only ctor/dtor fragment or non-deleting destructor-like helper.
- It is class-related ABI support, not meaningful source logic.

Evidence:

- Exact body is only `this->vptr = &UniAPIInit::vftable; return`.
- No current direct callers or pointer refs.
- Same vptr write is inlined in the scalar deleting destructor and static cleanup wrapper.

Rejected alternatives:

- Handwritten `Reset()` method: no caller route and no behavior beyond compiler vptr maintenance.
- Dispatch-table initializer: no table writes.

Decision: document as ABI/vptr reset helper. Do not emit standalone C++.

### Static cleanup wrapper

Best-supported interpretation:

- `0x0060c440` is compiler/static-lifetime cleanup for the file-local static `UniAPIInit` object.

Evidence:

- Registered only by `0x0041a280` via atexit.
- Exact body only writes the vtable pointer to the static object slot and returns.
- Existing [UID:0001O9] correctly marks it `RECONSTRUCTABLE:FALSE`.

Rejected alternatives:

- PlatformApi handwritten cleanup function: no explicit source-level cleanup behavior besides vptr maintenance.
- Pool cleanup wrapper: rejected by exact range and registration evidence; it is adjacent to pool wrappers but not part of them.

Decision: keep ignored/non-emitting as standalone memory, while documenting the source cause as `static UniAPIInit s_uniAPIInit`.

### Scalar deleting destructor

Best-supported interpretation:

- `0x00599a10` is MSVC scalar deleting destructor glue generated from a virtual destructor declaration.

Evidence:

- Vtable data points directly to `0x00599a10`.
- Body checks delete flag and calls delete/free with size `4`.
- No source cleanup logic exists beyond vptr reset.

Rejected alternatives:

- Handwritten destructor body that should be manually emitted: rejected because source-level behavior is empty/defaulted.
- Real cleanup for dispatch table: rejected because table cleanup is not performed; only vptr maintenance and optional delete.

Decision: class declaration should include `virtual ~UniAPIInit();`, but the scalar deleting destructor should not be hand-authored.

### Dispatch table declaration and typedef style

Best-supported source declaration style:

- Use a group of file-scope function-pointer globals in PlatformApi, documented together by [UID:0000TQ] `WideApiDispatchTable`.
- Prefer source names of the form `g_pfnFindWindow`, `g_pfnCreateFile`, `g_pfnPostMessage`, etc. for the dispatch variables, without forcing a `W` suffix into the variable name, because the variable abstracts the selected platform implementation. The installed NT target should still be documented as the `*W` API.
- For slots whose role is clearer with wide/file names, use descriptive aliases in docs, for example `g_pfnWideOpenFile` for `_wfopen`, `g_pfnWideStat` for `_wstat64i32`, and `g_pfnReadUtf16CodeUnitFromFile` for `ReadUtf16CodeUnitFromFile`.
- Use exact Windows/CRT signature typedefs where the function pointer appears in source, not `void *`, `DWORD`, or raw `dword_69BE**`.

Why individual globals instead of a C++ struct as primary source style:

- Generated source already recovers individual `g_pfn*` declarations.
- Consumer code compiles naturally as calls through individual globals.
- The table's contiguous memory can be explained by declaration/link order for adjacent file-scope globals.
- No code computes `base + index * 4`, passes a table pointer, or treats the storage as a struct object at runtime.

Why the by-global page should still be named `WideApiDispatchTable`:

- Documentation needs one owner for the contiguous storage cluster and its split memory children.
- "Table" describes the binary layout and conceptual dispatch group even if final C++ uses individual globals.

Rejected alternatives:

- `struct WideApiDispatchTable { ... } g_wideApiDispatch;`: plausible but weaker because no base-pointer field access is observed. It is acceptable as a documentation abstraction, but it should not be forced as the final C++ style without stronger source evidence.
- Raw globals `dword_69BE14`, `dword_69BE18`, etc.: rejected for final source because targets and roles are now known.
- Consumer-local declarations: rejected by broad xrefs and shared initialization.

Decision: document final C++ direction as PlatformApi file-scope function-pointer globals grouped under `WideApiDispatchTable` docs, with typedefs or Windows SDK pointer types as needed.

### Source placement under PlatformApi

Best-supported placement:

- `NexusTK/platform/PlatformApi.cpp`
- Header/declaration likely `NexusTK/platform/PlatformApi.h` if headers are later modeled.

Evidence:

- Existing proposed source tree and by-file page already place PlatformApi under `platform/`.
- Platform string helpers, dispatch table, and OLE/static init wrappers all sit in platform compatibility territory.
- Dispatch table consumers span many subsystems.

Rejected alternatives:

- `Application.cpp`: startup route only, not ownership.
- `FileIO.cpp` / `PathUtil.cpp`: file slots only.
- `Browser.cpp`: stale `SendMessageW` consumer alias only.
- `InputMan.cpp`: IME/window slots only.
- New standalone `UnicodeApi.cpp`: possible source-file name but weaker than current established PlatformApi route and proposed tree.

Decision: keep [UID:0000ML] PlatformApi as file owner.

### C++ readiness

[UID:0000FE] meets the current class-level C++ gate:

- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000ML`
- emitter route surfaces to `auto-generated/NexusTK/platform/PlatformApi.cpp`
- `(90 + 88) / 2 = 89`, above the current `>85` rule after accepted score update
- source placement and class declaration shape are now resolved enough for class-level code

Remaining uncertainty:

- exact original static object variable spelling;
- whether the dispatch setup body was written directly in `UniAPIInit::UniAPIInit()` or split through a private helper;
- formal exhaustive typedef names for every dispatch slot.

Impact:

- These remaining uncertainties should not block a class declaration.
- They should block hand-porting [UID:0001KE] raw/generated duplicate code.
- They should not block support docs from recommending `UniAPIInit` constructor/static-object source shape.

## First-Draft C++ Recommendation

Accepted implementation should add class-level first-draft C++ to [UID:0000FE]:

```cpp
class UniAPIInit
{
public:
    UniAPIInit();
    virtual ~UniAPIInit();
};
```

Reasoning:

- The vtable symbol and scalar deleting destructor prove a polymorphic class with virtual destructor support.
- The class object is only 4 bytes in current evidence, consistent with a vptr-only initializer object.
- The constructor declaration is needed because the source-level static object is the best explanation for the startup initializer and raw constructor-shaped duplicate.
- The destructor declaration is needed to regenerate the vtable/scalar deleting destructor/static cleanup behavior, but the destructor body should be empty/defaulted unless later evidence proves source-authored cleanup.

Support C++ direction for later callback, not necessarily placed in the class page:

```cpp
static UniAPIInit s_uniAPIInit;
```

This static object definition should be represented in PlatformApi source/static-object support, most directly through [UID:00028B] or the PlatformApi file page, not as a raw vptr variable.

Recommended constructor/body direction for [UID:0000WD] if the supervisor accepts support C++ beyond the class declaration:

```cpp
UniAPIInit::UniAPIInit()
{
    OSVERSIONINFOA osVersionInfo;

    osVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);
    GetVersionExA(&osVersionInfo);

    g_pfnReadUtf16CodeUnitFromFile = ReadUtf16CodeUnitFromFile;

    if (osVersionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT) {
        g_pfnFindWindow = FindWindowW;
        g_pfnOpenFileMapping = OpenFileMappingW;
        g_pfnCreateMutex = CreateMutexW;
        g_pfnCreateDialogParam = CreateDialogParamW;
        g_pfnLoadLibrary = LoadLibraryW;
        g_pfnCreateFile = CreateFileW;
        g_pfnCreateProcess = CreateProcessW;
        g_pfnCreateEvent = CreateEventW;
        g_pfnRegisterClass = RegisterClassW;
        g_pfnCreateWindowEx = CreateWindowExW;
        g_pfnCreateFileMapping = CreateFileMappingW;
        g_pfnCreateSemaphore = CreateSemaphoreW;
        g_pfnDefWindowProc = DefWindowProcW;
        g_pfnRegisterClipboardFormat = RegisterClipboardFormatW;
        g_pfnCharUpperBuff = CharUpperBuffW;
        g_pfnCreateDirectory = CreateDirectoryW;
        g_pfnDeleteFile = DeleteFileW;
        g_pfnDispatchMessage = DispatchMessageW;
        g_pfnFindFirstFile = FindFirstFileW;
        g_pfnFormatMessage = FormatMessageW;
        g_pfnGetCurrentDirectory = GetCurrentDirectoryW;
        g_pfnGetModuleFileName = GetModuleFileNameW;
        g_pfnGetModuleHandle = GetModuleHandleW;
        g_pfnGetWindowsDirectory = GetWindowsDirectoryW;
        g_pfnGlobalGetAtomName = GlobalGetAtomNameW;
        g_pfnLoadCursor = LoadCursorW;
        g_pfnLoadIcon = LoadIconW;
        g_pfnPeekMessage = PeekMessageW;
        g_pfnPostMessage = PostMessageW;
        g_pfnRegCreateKeyEx = RegCreateKeyExW;
        g_pfnRegDeleteKey = RegDeleteKeyW;
        g_pfnRegEnumValue = RegEnumValueW;
        g_pfnRegQueryInfoKey = RegQueryInfoKeyW;
        g_pfnRegQueryValueEx = RegQueryValueExW;
        g_pfnRegSetValueEx = RegSetValueExW;
        g_pfnSetCurrentDirectory = SetCurrentDirectoryW;
        g_pfnWideOpenFile = _wfopen;
        g_pfnWideStat = _wstat64i32;
        g_pfnGetFileVersionInfoSize = GetFileVersionInfoSizeW;
        g_pfnGetFileVersionInfo = GetFileVersionInfoW;
        g_pfnVerQueryValue = VerQueryValueW;
        g_pfnImmGetCompositionString = ImmGetCompositionStringW;
        g_pfnImmGetCandidateList = ImmGetCandidateListW;
        g_pfnSendMessage = SendMessageW;
        g_pfnGetLocaleInfo = GetLocaleInfoW;
        g_pfnSetFileAttributes = SetFileAttributesW;
    }
}

UniAPIInit::~UniAPIInit()
{
}
```

Important placement note:

- The class page should emit only the class declaration. The constructor body and static object definition should be emitted by accepted support docs if and when the supervisor includes them in the implementation callback.
- Do not emit the `atexit` call as handwritten source; it is compiler output from the static object lifetime.
- Do not emit `0x0060c440` cleanup wrapper, `0x005997e0` vptr reset helper, `0x00599a10` scalar deleting destructor, or `0x0062e57c` vtable dword as handwritten code.

## Exact No-Code / Defer Proof For Raw Or Generated Support Items

[UID:0001KE] `0x005995b0-0x00599a34.UniAPIInit` should keep formal C++ blank for now:

- It is an aggregate containing two raw initializer-shaped duplicate spans, a vptr reset helper, padding, and the scalar deleting destructor.
- `0x005995b0` has no current rel32 call/jump or absolute pointer route.
- The generated name `~UniAPIInit` at `0x005995b0` is contradicted by the body, which is constructor-shaped and installs the dispatch table.
- The real startup route is [UID:0000WD] `0x0041a280`, not [UID:0001KE].
- Emitting this aggregate would duplicate the dispatch initialization body and risk hand-porting unreachable generated projection bytes.

[UID:0001O9] `0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper` should stay no-code:

- Exact body only writes the vtable pointer back into the static object slot.
- It is registered by `atexit` from the dynamic initializer.
- It is compiler/static-lifetime glue and is already `RECONSTRUCTABLE:FALSE`.

[UID:0003E5] `0x0062e57c-0x0062e580.UniAPIInitVtableData` should stay no manual code:

- The dword should be regenerated by the compiler from the class declaration and virtual destructor.
- Hand-writing a vtable dword in C++ would be reverse-engineering scaffolding, not plausible source.

[UID:00028B] `0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot` should not emit a raw pointer:

- The source declaration should be `static UniAPIInit s_uniAPIInit;`.
- If support docs emit this item, emit the static object declaration, not a `void *` or `DWORD` initialized to a vtable address.

## Proposed Metadata And Score Rationale

Recommended [UID:0000FE] metadata:

```text
*** COMPLETION:90
*** CONFIDENCE:88
*** CANONICAL_OWNER:0000ML
*** RECONSTRUCTABLE:TRUE
*** EMITTER_UIDS:0000ML
```

Rationale:

- Completion rises from 88 to 90 because this pass closes the class/static-object source shape, raw/generated `0x005995b0` interpretation, vtable reset/destructor/static cleanup treatment, dispatch-table declaration direction, and class-level C++ readiness.
- Confidence rises from 85 to 88 because raw PE disassembly and xref scanning validated the existing IDA-backed docs in the current session. Confidence remains below 90 because IDA MCP was unavailable during this pass and exact original variable/typedef spelling is still inferred/descriptive.
- Owner/emitter remain [UID:0000ML] because PlatformApi is still the correct direct source file route for the class declaration and static object.
- `RECONSTRUCTABLE:TRUE` remains correct: the class/static object and dispatch initialization policy must be recreated, even though several child artifacts are compiler-generated.

## Exact Coverage / Report Text

Do not edit any by-* coverage/report file during this report-only pass.

Recommended replacement row for `by-class/-coverage-report.md` if supervisor accepts the score/source-quality update:

```text
- [UID:0000FE][UniAPIInit](by-class/UniAPIInit.md) : reconstructable : 90% : very strong : PlatformApi-owned static Unicode API initializer class; source-quality reanalysis validates `UniAPIInit` as a vtable-proven class with file-local static object shape `static UniAPIInit s_uniAPIInit`, real startup dynamic initializer [UID:0000WD] `0x0041a280-0x0041a4a8`, static cleanup wrapper [UID:0001O9] `0x0060c440-0x0060c44b`, vtable data [UID:0003E5] `0x0062e57c-0x0062e580`, static object/vptr slot [UID:00028B] `0x006702c4-0x006702c8`, scalar deleting destructor `0x00599a10-0x00599a34`, vptr-only reset helper `0x005997e0-0x005997e7`, WideApiDispatchTable ownership under [UID:0000TQ], exact NT `*W` dispatch assignment sequence, rejection of stale generated `0x005995b0` destructor projection, and first-draft class declaration readiness.
```

No direct `by-memory/-coverage-report.md` row replacement is required for this report-only class assignment. If the later implementation callback changes support memory scores, names, or C++ status, the implementing pass should provide exact `by-memory/-coverage-report.md` row text then; B007 must still not edit that file directly.

Generated `auto-generated/-ag-class-coverage.md` and `auto-generated/NexusTK/platform/PlatformApi.cpp` should be refreshed only by validator/autogen commands during an accepted implementation pass, not by hand.

## Exact Implementation Checklist For Later Callback

Target [UID:0000FE] `by-class/UniAPIInit.md`:

- Update metadata to `COMPLETION:90`, `CONFIDENCE:88`; keep owner/emitter [UID:0000ML].
- Replace old "medium for static-object shape" uncertainty with the high-probability source shape:
  - `class UniAPIInit`;
  - file-local static object `static UniAPIInit s_uniAPIInit` or project-style equivalent;
  - constructor/static initializer installs dispatch table;
  - destructor is empty/defaulted source, with compiler-generated scalar deleting destructor/static cleanup.
- Add the raw PE validation details:
  - `0x0041a280` startup-table xref `0x0060d71c`;
  - no current direct route to `0x005995b0`;
  - exact `0x005997e0` vptr reset body;
  - exact `0x00599a10` scalar deleting destructor body;
  - exact `0x0060c440` static cleanup wrapper body;
  - vtable/static-slot xref set.
- Add the full NT wide dispatch assignment sequence or a table at the same factual detail as this report.
- Add rejected alternatives:
  - generated `~UniAPIInit` at `0x005995b0`;
  - raw vptr global;
  - dispatch-table ownership by StdioFile/PathUtil/Browser/InputMan/Application;
  - forced struct table if individual globals remain the better C++ style.
- Replace open questions with closed or explicitly deferred items:
  - class/static source shape closed to file-local static object;
  - dispatch declaration style closed to PlatformApi file-scope function-pointer globals grouped by [UID:0000TQ];
  - exact original `s_`/`g_` variable prefix remains spelling-only, not source-placement blocker;
  - [UID:0001KE] duplicate raw body remains deferred with exact no-code proof.
- Add class-level C++:
  - `class UniAPIInit { public: UniAPIInit(); virtual ~UniAPIInit(); };`
  - Do not put the full dispatch assignment body into the class page unless local class-page convention explicitly includes method bodies.

Support docs to synchronize:

- [UID:0000ML] `by-file/PlatformApi.md`:
  - Add source-shape statement that `PlatformApi.cpp` likely declares the `UniAPIInit` class, file-local static object, dispatch function-pointer globals, and platform string helpers.
  - Correct any "final static-object spelling is open" language to "exact prefix/spelling inferred; file-local static object shape accepted."
- [UID:0000TQ] `by-global/WideApiDispatchTable.md`:
  - Add final declaration-style direction: grouped individual file-scope function-pointer globals with exact typedefs, not raw `dword_` names and not necessarily a runtime struct object.
  - Add or sync the full assignment sequence above.
  - Preserve `SendMessageW` stale-alias correction.
- [UID:0000WD] `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`:
  - Recast the source shape as static-object dynamic initialization/inlined `UniAPIInit` constructor logic.
  - Preserve exact startup-table xref and atexit wrapper evidence.
  - Decide during implementation whether to keep formal C++ blank with the compiler-wrapper proof or emit a constructor-shaped body under accepted source policy.
- [UID:0001KE] `by-memory/0x005995b0-0x00599a34.UniAPIInit.md`:
  - Update the caveat to say `0x005995b0` is constructor-shaped, not destructor-shaped.
  - Keep formal C++ blank unless it is split into exact children and the supervisor accepts a route for raw duplicate bodies.
  - Preserve the no-route proof and duplicate/projection evidence.
- [UID:0001O9] `by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md`:
  - Add or preserve no-code proof as compiler/static-lifetime cleanup from `static UniAPIInit s_uniAPIInit`.
- [UID:00028B] `by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md`:
  - Rename/source-shape the slot as static object storage if accepted, not an explicit vptr variable.
  - If C++ is emitted here, use `static UniAPIInit s_uniAPIInit;`, not a raw pointer/dword initializer.
- [UID:0003E5] `by-memory/0x0062e57c-0x0062e580.UniAPIInitVtableData.md`:
  - Preserve class owner [UID:0000FE], no manual dword emission, compiler-generated from virtual destructor declaration.
- [UID:0002AS], [UID:0001Q1], and [UID:0002A6]:
  - Synchronize with the selected dispatch declaration style and exact assignment sequence if their current text still says final style is open.
- [UID:000249] `PlatformStringConversionHelpers`:
  - Ensure `ReadUtf16CodeUnitFromFile` remains PlatformApi-owned and is referenced as the `0x0069be1c` dispatch slot target, not a UniAPIInit-owned helper.
- `by-project-structure/proposed-source-tree.md`:
  - Optional sync only if already editing source-tree text: update the PlatformApi rationale from `sub_599570` to `ReadUtf16CodeUnitFromFile` and mention the accepted file-local static `UniAPIInit` shape.

Validation required after accepted implementation:

- Run scoped validator on `by-class/UniAPIInit.md`.
- Run scoped validator on each edited support doc.
- If any filename is renamed, run validator on the renamed file and any edited UID-reference sources.
- Do not edit `by-memory/-coverage-report.md`; leave exact row text in the implementation response if support memory rows change.

## Open Questions Closure

Closed:

- Class name: `UniAPIInit`.
- Direct source route: [UID:0000ML] `PlatformApi.cpp`.
- Static object shape: file-local static `UniAPIInit` object.
- Static object best descriptive name: `s_uniAPIInit`, exact prefix not proofed.
- Dispatch storage owner: [UID:0000TQ] under [UID:0000ML].
- Dispatch declaration style: grouped file-scope function-pointer globals with typedefs; not raw dwords and not consumer-local.
- Real initializer: `0x0041a280` startup dynamic initializer / inlined constructor logic.
- `0x005995b0` generated body: stale destructor projection, constructor-shaped no-route duplicate/caveat.
- Static cleanup wrapper: compiler/static-lifetime glue.
- Scalar deleting destructor/vtable data: compiler ABI from virtual destructor declaration.
- Class C++ readiness: yes, declaration should be emitted.

Still unresolved but non-blocking:

- Exact original static object variable spelling (`s_uniAPIInit` versus `g_uniAPIInit` or a bare file-static name). This affects naming polish only, not ownership, source placement, or class C++ readiness.
- Whether original source wrote all dispatch assignments directly in `UniAPIInit::UniAPIInit()` or factored them into a private helper such as `InstallWideApiDispatchTable()`. Current binary shape supports either; constructor/static object remains the top-level source model.
- Exhaustive typedef spellings for every dispatch pointer. The report resolves declaration style and roles, but exact typedef names can be refined during WideApiDispatchTable implementation.

Score/C++ impact:

- These uncertainties cap confidence at 88.
- They do not block class declaration C++.
- They do block emitting [UID:0001KE] raw/generated aggregate as a standalone source body.

## Changed Files In This Report Pass

Created:

- `tools/leaser/Agents/Agent-B007/research/0000FE-UniAPIInit-class-source-quality.md`

Modified:

- `tools/leaser/Agents/Agent-B007/notes.md` should receive a short bookkeeping entry for this report pass.

Not edited:

- No `by-*` documentation files.
- No `by-memory/-coverage-report.md`.
- No generated/autogen/project-level documentation files.

## Final Report-Only Statement

FINISHED.

Target [UID:0000FE] `by-class/UniAPIInit.md` has been reanalyzed under the B-agent Rule 26/no-detail-cap source-quality standard. The report validates the PlatformApi class/static object source shape, corrects the stale generated `0x005995b0` destructor interpretation, recommends class-level first-draft C++ now, gives target-specific no-code/defer proof for raw/generated and compiler artifacts, provides exact support-doc synchronization actions, and supplies exact by-class coverage row text for supervisor-owned application.

Validator baseline: command above, exit code `0`, `ok: 1`.

No `by-*` docs were edited. `by-memory/-coverage-report.md` was not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000FE-UniAPIInit-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"0000FE"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000FE-UniAPIInit-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0000FE-UniAPIInit-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000FE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
