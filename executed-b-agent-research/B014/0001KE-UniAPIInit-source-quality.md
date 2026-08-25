** TARGET-REPORT-UID:0001KE **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B014 source-quality report: [UID:0001KE] UniAPIInit

Status: FINISHED report-only research; no by-* documentation edited.

Target: `source-3/project-documentation/by-memory/0x005995b0-0x00599a34.UniAPIInit.md`  
Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/0001KE-UniAPIInit-source-quality.md`  
Primary owner/emitter route: [UID:0000ML] `by-file/PlatformApi.md` -> generated output `auto-generated/NexusTK/platform/PlatformApi.cpp`.

## Recommendation summary

Keep [UID:0001KE] as a reconstructable PlatformApi aggregate/static-object generated-boundary caveat, but do not populate the target's formal `RECONSTRUCTION_CPP` block. Raise the target from `85/86` to `87/89` after adding the current source-quality resolution:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:0000ML
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000ML
EMITTER_POSITION_OPTIONAL:
```

The formal C++ for the dispatch-table assignment body belongs in [UID:0000WD] `0x0041a280-0x0041a4a8.WideApiDispatchInit` if/when that support page is accepted for code entry, and the static-object/source declaration belongs in `by-class/UniAPIInit.md`, `by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md`, and `by-memory/0x0062e57c-0x0062e580.UniAPIInitVtableData.md`. The vtable reset helper, static cleanup wrapper, and scalar deleting destructor are compiler/static-lifetime support and should remain no-code/generated-binary evidence.

High-probability source shape:

```cpp
class UniAPIInit {
public:
    UniAPIInit();
    virtual ~UniAPIInit();
};

static UniAPIInit s_uniApiInit;
```

The constructor body or an immediately adjacent helper initializes the wide API dispatch table; the compiler emits the startup table entry at `0x0060d71c -> 0x0041a280`, the static cleanup wrapper registration, the static vptr slot at `0x006702c4`, the one-slot vtable at `0x0062e57c`, and the scalar deleting destructor at `0x00599a10`.

## Evidence checked

Documentation reviewed:

- `tools/leaser/Agents/Supervisor.md`, especially Rules 20/21/23/24/26/27/30/31.
- `.codex/AGENTS.md`.
- `tools/leaser/Agents/Agent-B014/goal.md`, especially the B-agent source-quality and 85/85 code-entry sections.
- Target `by-memory/0x005995b0-0x00599a34.UniAPIInit.md`.
- [UID:0000WD] `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`.
- [UID:0000ML] `by-file/PlatformApi.md`.
- [UID:0000FE] `by-class/UniAPIInit.md`.
- [UID:0000TQ] `by-global/WideApiDispatchTable.md`.
- [UID:0001O9] `by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md`.
- [UID:000249] `by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md`.
- [UID:00028B] `by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md`.
- [UID:0003E5] `by-memory/0x0062e57c-0x0062e580.UniAPIInitVtableData.md`.
- [UID:00026S] `by-memory/0x0062e57c-0x0062e624.UniApiUrlAlertReadOnlyData.md`.
- [UID:0002AS] `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`.
- [UID:0002A6] `by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md`.
- Current generated file `auto-generated/NexusTK/platform/PlatformApi.cpp`.
- Current coverage row in `by-memory/-coverage-report.md`; no edit made.

Direct PE scan:

- PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Size: `2,679,296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`
- Sections:
  - `.text` `0x00401000-0x0060c600`
  - `.rdata` `0x0060d000-0x0066c200`
  - `.data` `0x0066d000-0x0069ce24`
  - `.rsrc` `0x0069d000-0x006b2e00`

## Direct boundary and byte evidence

Exact target range remains `0x005995b0-0x00599a34`, but the internal source-quality split should be refined:

| Range | B014 classification | Evidence |
|---|---|---|
| `0x005995a7-0x005995b0` | predecessor padding, outside target | Nine bytes of `0xcc` after [UID:000249] `ReadUtf16CodeUnitFromFile` and before the target. |
| `0x005995b0-0x005997dd` | retained out-of-line constructor-shaped dispatch initializer projection | Starts with `push ebp; mov ebp, esp; sub esp, 0x98`, uses `ECX`/`ESI` as `this`, writes `0x0062e57c` to `*this` at `0x005995d7`, calls `GetVersionExA`, writes `0x0069be1c = 0x00599570`, installs wide API dispatch entries on NT, security-cookie checks, and returns `this` in `EAX`. No direct rel32 or absolute pointer route reaches this start. |
| `0x005997dd-0x005997e0` | internal padding | Three bytes of `0xcc`. |
| `0x005997e0-0x005997e7` | tiny vtable reset/non-deleting destructor-shaped helper | Exact body is `mov dword ptr [ecx], 0x0062e57c; ret`. No current direct refs. Treat as compiler/static-lifetime destructor support, not source-authored behavior needing C++ here. |
| `0x005997e7-0x005997f0` | internal padding | Nine bytes of `0xcc`. This corrects the older raw-span wording that implied executable code begins at `0x005997e7`. |
| `0x005997f0-0x00599a0b` | retained duplicate initializer-shaped projection | Starts with the same `OSVERSIONINFOA` stack frame and dispatch-table writes, but has no `this` register use, no vtable write, no `atexit` registration, no rel32 caller, and no absolute pointer route. It returns at `0x00599a0a`. |
| `0x00599a0b-0x00599a10` | internal padding | Five bytes of `0xcc`. |
| `0x00599a10-0x00599a34` | scalar deleting destructor | Exact `0x24`-byte body writes `0x0062e57c` to `*this`, conditionally calls `0x005c7526(this, 4)` when delete flag bit 0 is set, returns `this`, and ends with `ret 4` at `0x00599a31`. It is referenced by the one-slot vtable dword at `0x0062e57c`. |
| `0x00599a34-0x00599a40` | successor padding, outside target | Twelve bytes of `0xcc` before [UID:0001KF] `UrlAlertPane`. |

Key byte patterns from direct PE scan:

- `0x005995b0`: `55 8b ec 81 ec 98 00 00 00 ...`
- `0x005997e0`: `c7 01 7c e5 62 00 c3`
- `0x005997e7-0x005997ef`: nine `cc` bytes.
- `0x005997f0`: `55 8b ec 81 ec 98 00 00 00 ...`
- `0x00599a10`: `55 8b ec f6 45 08 01 56 8b f1 c7 06 7c e5 62 00 ... c2 04 00`
- `0x0060c440`: `c7 05 c4 02 67 00 7c e5 62 00 c3`

## Xref and route evidence

Direct rel32 call/jump scan over `.text` found no direct code references to:

- `0x005995b0`
- `0x005997e0`
- `0x005997e7`
- `0x005997f0`
- `0x00599a10`
- `0x0060c440`
- `0x0041a280`
- `0x00599570`

This is expected for startup-table and vtable/static-data routes, but it is important negative evidence for the retained raw starts.

Absolute VA dword hits:

| Target VA | Hits | Interpretation |
|---|---|---|
| `0x005995b0` | none | No direct startup table, vtable, or pointer route to the retained constructor-shaped body. |
| `0x005997e0` | none | No direct route to the tiny vtable reset helper. |
| `0x005997e7` | none | Padding/raw-span boundary only. |
| `0x005997f0` | none | No direct route to the duplicate initializer-shaped body. |
| `0x00599a10` | `0x0062e57c` in `.rdata` | Vtable first slot points at scalar deleting destructor. |
| `0x0060c440` | `0x0041a48e` in `.text` | Registered by the real startup initializer via `_atexit`; immediate appears inside the push at `0x0041a48d`. |
| `0x0041a280` | `0x0060d71c` in `.rdata` | Startup initializer table route. This is the live route for process startup dispatch initialization. |
| `0x00599570` | `0x0041a2b7`, `0x005995f0`, `0x00599827` in `.text` | Real initializer and raw/generated projections write `ReadUtf16CodeUnitFromFile` to the dispatch table. |
| `0x0062e57c` | `0x005995d9`, `0x005997e2`, `0x00599a1c`, `0x0060c446`, `0x006702c4` | Constructor projection, vtable reset helper, scalar deleting destructor, cleanup wrapper, and initialized static vptr slot all reference the same vtable dword. |
| `0x006702c4` | `0x0060c442` | Static cleanup wrapper writes the static object vptr slot. |
| `0x0069be1c` | `0x0041a2b3`, consumer reads, `0x005995ec`, `0x00599823` | Dispatch-table reader slot; the raw projection refs do not transfer ownership away from PlatformApi. |

Startup table recheck:

- `0x0060d71c -> 0x0041a280`, the real dispatch initializer.
- `0x0060d720 -> 0x0041a4b0`, next unrelated startup constructor wrapper.
- No startup-table entry was found for `0x005995b0`, `0x005997e0`, or `0x005997f0`.

## Raw instruction pattern analysis

### `0x005995b0-0x005997dd`

Best classification: retained out-of-line `UniAPIInit::UniAPIInit()`-shaped body or constructor projection, not the live startup initializer.

Evidence:

- Uses `ECX` as `this`, copies it into `ESI`, writes the `UniAPIInit` vtable address `0x0062e57c` to `*this`, and returns `ESI` in `EAX`.
- Allocates a `0x98` stack frame and sets `OSVERSIONINFOA::dwOSVersionInfoSize` to `0x94`.
- Calls `GetVersionExA` through IAT cell `0x0060d168`.
- Writes `ReadUtf16CodeUnitFromFile` (`0x00599570`) to `0x0069be1c`.
- On NT platform (`dwPlatformId == 2`), installs the same broad wide API dispatch table as [UID:0000WD].
- Does not register the cleanup wrapper; the live startup wrapper at `0x0041a280` performs that static-lifetime registration.
- Has no direct caller, no startup table entry, and no absolute pointer route to the start address.

Inference:

This is very likely the original constructor body retained out of line by the linker/compiler, while the actual startup path at `0x0041a280` inlines or duplicates the constructor's table-initialization logic and registers the static cleanup wrapper. It should be documented as retained source-shaped evidence, but not used as this aggregate's formal source output because the live route and startup semantics are anchored elsewhere.

### `0x005997e0-0x005997e7`

Best classification: non-deleting destructor/vtable reset helper.

Evidence:

- Whole body is `*this = &UniAPIInit::vftable; return;`.
- No current direct xrefs.
- Same vtable pointer is written by constructor-shaped bytes, scalar deleting destructor, static cleanup wrapper, and static vptr slot.

Inference:

Treat as compiler/static-lifetime destructor support generated from a virtual class with no meaningful destructor body. Do not emit as handwritten C++ in the target. If support docs name it, use `UniAPIInit::ResetVtableForDestruction` descriptively or `UniAPIInit::~UniAPIInit` only with a caveat that the source destructor body is empty.

### `0x005997f0-0x00599a0b`

Best classification: retained duplicate initializer-shaped projection, not a proven source function.

Evidence:

- Begins after nine bytes of padding; older raw-span start `0x005997e7` is not the executable start.
- Has the same `OSVERSIONINFOA`/`GetVersionExA`/dispatch-table assignment pattern as `0x0041a280` and `0x005995b0`.
- Does not use `ECX`/`this`, does not write a vtable, does not return `this`, and does not register the static cleanup wrapper.
- Has no direct rel32 caller, no startup-table entry, and no absolute pointer route.

Inference:

This is probably a retained helper/projection emitted from the same source-level table-initialization logic, but no safe direct source name is provable. Best descriptive name for IDA/commentary is `UniAPIInitDispatchProjection` or `RetainedWideApiDispatchInitProjection`, not a final source function name.

### `0x00599a10-0x00599a34`

Best classification: scalar deleting destructor, compiler-generated.

Evidence:

- Vtable dword `0x0062e57c` points here.
- Body resets the vtable, checks delete flag bit `1`, calls delete/free helper `0x005c7526` with size `4`, returns `this`, and uses `ret 4`.

Inference:

No handwritten C++ body should be emitted. The source declaration should provide a virtual destructor for `UniAPIInit`; the compiler regenerates this helper.

## Real initializer comparison: [UID:0000WD] `0x0041a280`

[UID:0000WD] is the live startup-table route and should remain the authoritative executable initializer.

Evidence from PE scan and support docs:

- Startup table contains `0x0060d71c -> 0x0041a280`.
- No ordinary callers; route is startup data, not a source call site.
- Body starts with the same `0x98` stack frame and `OSVERSIONINFOA::dwOSVersionInfoSize = 0x94`.
- Calls `GetVersionExA`.
- Writes `ReadUtf16CodeUnitFromFile` to `0x0069be1c`.
- Installs the wide API table on NT-family Windows.
- Registers [UID:0001O9] `0x0060c440` with `_atexit` at `0x0041a48d`.

Source-shape inference:

`0x0041a280` is best understood as the compiler-emitted startup initializer for a file-scope `UniAPIInit` static object or equivalent PlatformApi static initialization construct. It carries the live startup route and cleanup registration. Therefore, if first-draft dispatch-initialization C++ is entered anywhere today, it should be entered on [UID:0000WD] or class/static support docs, not on [UID:0001KE]'s mixed raw aggregate.

## Source-quality names and placement

Recommended names:

- Class: `UniAPIInit`.
- Static object: `s_uniApiInit` or `g_uniApiInit`. Prefer `s_uniApiInit` in source prose because the object appears file-scope/static inside `PlatformApi.cpp`; use `g_uniApiInit` only if the project convention for process-singletons prefers `g_`.
- Static vptr slot: descriptive `s_uniApiInit` object storage / `UniAPIInit` static object vptr slot at `0x006702c4`. Do not name it as a standalone source pointer variable.
- Vtable dword: `UniAPIInit::vftable` / `??_7UniAPIInit@@6B@` at `0x0062e57c`.
- Reader helper: `ReadUtf16CodeUnitFromFile(FILE *stream)`, owned by [UID:000249] Platform string conversion helpers.
- Dispatch table: `WideApiDispatchTable` with `g_pfn*` entries; `0x0069be1c` as `g_pfnReadUtf16CodeUnitFromFile`.
- Real startup initializer page name: retain `WideApiDispatchInit` as a documentation/source-model name for the live startup table function.
- Raw duplicate helper descriptive name only: `RetainedWideApiDispatchInitProjection` or `UniAPIInitDispatchProjection`. Do not emit this as a source-facing public function.
- Vtable reset helper descriptive name: `UniAPIInitVtableResetHelper` or `UniAPIInitNonDeletingDestructorSupport`. Do not treat it as a handwritten method.
- Scalar deleting destructor: `UniAPIInit::ScalarDeletingDestructor`, compiler-generated/no-code.
- Static cleanup wrapper: `UniAPIInitStaticCleanupWrapper`, compiler/static-lifetime no-code.

Owner/emitter recommendation:

- Keep target owner/emitter as [UID:0000ML] `PlatformApi`.
- Do not reroute the target directly to [UID:0000FE] `UniAPIInit`. The executable aggregate mixes constructor projection, duplicate dispatch projection, vtable reset support, scalar deleting destructor, dispatch-table evidence, and static-lifetime cleanup evidence. The class owns the vtable data declaration, but the file owns the platform initialization source family.
- Do not route to `FileIO`, `PathUtil`, `InputMan`, browser, timer/thread, or URL-alert pages. Those are consumers or adjacent data families.

## First-draft C++ / no-code proof

Do not populate [UID:0001KE]'s formal `RECONSTRUCTION_CPP` block.

Target-specific no-code/defer proof:

1. The target is a mixed aggregate, not one source-authored function. It contains retained constructor-shaped bytes, internal padding, a vtable reset helper, a retained duplicate initializer-shaped body, more internal padding, and a scalar deleting destructor.
2. The live startup route for dispatch initialization is [UID:0000WD] `0x0041a280`, reached through startup table data at `0x0060d71c`.
3. No direct rel32, startup-table, absolute pointer, or vtable route reaches `0x005995b0`, `0x005997e0`, `0x005997e7`, or `0x005997f0`.
4. The scalar deleting destructor at `0x00599a10` and the cleanup wrapper at `0x0060c440` are compiler/static-lifetime artifacts. Source should declare a virtual destructor/static object; it should not hand-port those helpers.
5. `0x006702c4` and `0x0062e57c` are static object/vtable data generated by the class/static-object declaration.
6. `ReadUtf16CodeUnitFromFile` is already first-draft C++ in [UID:000249], not owned by this aggregate.
7. Entering a full dispatch initializer body in [UID:0001KE] would duplicate [UID:0000WD] and would make the generated aggregate look like a single handwritten source function, which the boundary/xref evidence rejects.

What should receive C++ instead:

- [UID:0000WD] should receive the dispatch-table assignment body when accepted for a PlatformApi implementation pass.
- [UID:0000FE], [UID:00028B], and [UID:0003E5] should receive or reference the class/static declaration shape:

```cpp
class UniAPIInit {
public:
    UniAPIInit();
    virtual ~UniAPIInit();
};

static UniAPIInit s_uniApiInit;
```

- [UID:0001O9], [UID:0003E5], and the scalar deleting destructor evidence should remain no-code/generated-binary support.

Support-only first-draft shape for [UID:0000WD] or a later PlatformApi pass, not for [UID:0001KE]:

```cpp
static void InitWideApiDispatchTable()
{
    OSVERSIONINFOA versionInfo;
    versionInfo.dwOSVersionInfoSize = sizeof(versionInfo);

    GetVersionExA(&versionInfo);

    g_pfnReadUtf16CodeUnitFromFile = ReadUtf16CodeUnitFromFile;

    if (versionInfo.dwPlatformId != VER_PLATFORM_WIN32_NT)
        return;

    g_pfnFindWindowW = FindWindowW;
    g_pfnCreateFileW = CreateFileW;
    g_pfnCreateWindowExW = CreateWindowExW;
    g_pfnDispatchMessageW = DispatchMessageW;
    g_pfnCreateEventW = CreateEventW;
    g_pfnDefWindowProcW = DefWindowProcW;
    g_pfnCharUpperBuffW = CharUpperBuffW;
    g_pfnPostMessageW = PostMessageW;
    g_pfnWideOpenFile = _wfopen;
    g_pfnWideStat = _wstat64i32;
    g_pfnSendMessageW = SendMessageW;
    g_pfnGetLocaleInfoW = GetLocaleInfoW;
    g_pfnSetFileAttributesW = SetFileAttributesW;
}

UniAPIInit::UniAPIInit()
{
    InitWideApiDispatchTable();
}

UniAPIInit::~UniAPIInit()
{
}
```

The snippet intentionally omits many table entries because final complete slot naming belongs to `WideApiDispatchTable` / `WideApiDispatchInit`, not this aggregate. It is included to show the source shape and code placement, not as target formal C++.

## Rejected alternatives

- `0x005995b0` as the live static initializer: rejected. It has constructor-shaped bytes but no startup table entry, no direct caller, and no pointer route. `0x0041a280` has the startup table entry and registers the cleanup wrapper.
- `0x005997e7` as an executable start: rejected. Direct byte scan shows nine `0xcc` bytes at `0x005997e7-0x005997f0`; the executable-looking body starts at `0x005997f0`.
- `0x005997f0` as the final source helper: rejected for now. It is initializer-shaped, but no route reaches it, and it lacks static cleanup registration. It is retained projection evidence, not an authoritative source function.
- `0x005997e0` as a source-authored method needing formal C++: rejected. It only writes the vtable and returns.
- `0x00599a10` as source-authored destructor logic: rejected. It is the scalar deleting destructor, generated from the virtual destructor declaration and delete flag ABI.
- `0x0060c440` as a handwritten cleanup function: rejected. It is a compiler/static-lifetime wrapper registered by the startup initializer.
- `ReadUtf16CodeUnitFromFile` ownership by `UniAPIInit`: rejected. The helper is part of [UID:000249] Platform string conversion helpers and is merely assigned into the dispatch slot by the real initializer and raw projections.
- Consumer ownership by `StdioFile`, `PathUtil`, `InputMan`, timer/thread, browser, or URL-alert code: rejected. Those pages consume dispatch slots or follow this range; they do not own the platform dispatch initializer/static object.
- Target-level first-draft C++ despite passing the 85/85 gate: rejected for this aggregate only. The target passes the minimum gate but fails source-shape safety because it is mixed generated-boundary evidence. Current rules allow eligible C++ when safe; they do not require hand-porting compiler/static-lifetime aggregates as one source body.

## Target doc changes to make later

In `by-memory/0x005995b0-0x00599a34.UniAPIInit.md`:

1. Raise metadata to `COMPLETION:87`, `CONFIDENCE:89`; keep `CANONICAL_OWNER:0000ML`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000ML`.
2. Add a "2026-06-19 B014 source-quality reanalysis" section or merge equivalent details into `Address Range`, `Evidence`, `Reconstruction Notes`, and `Confidence And Open Questions`.
3. Replace the current broad raw-span rows with refined subrange detail:
   - `0x005995b0-0x005997dd` retained constructor-shaped projection.
   - `0x005997dd-0x005997e0` padding.
   - `0x005997e0-0x005997e7` vtable reset/non-deleting destructor support.
   - `0x005997e7-0x005997f0` padding.
   - `0x005997f0-0x00599a0b` retained duplicate initializer-shaped projection.
   - `0x00599a0b-0x00599a10` padding.
   - `0x00599a10-0x00599a34` scalar deleting destructor.
4. Add the direct PE evidence:
   - PE hash/section basis.
   - No direct rel32 refs to raw starts.
   - No absolute VA route to `0x005995b0`, `0x005997e0`, `0x005997e7`, or `0x005997f0`.
   - Startup table entry `0x0060d71c -> 0x0041a280`.
   - Vtable slot `0x0062e57c -> 0x00599a10`.
   - Cleanup wrapper registration immediate at `0x0041a48e`.
   - `ReadUtf16CodeUnitFromFile` refs at `0x0041a2b7`, `0x005995f0`, and `0x00599827`.
5. Add the high-probability source shape:
   - file-scope/static `UniAPIInit` object in `PlatformApi.cpp`.
   - `UniAPIInit::UniAPIInit()` initializes the dispatch table or calls a private/static helper that does.
   - virtual destructor is source-empty; compiler emits vtable reset, scalar deleting destructor, vtable data, and cleanup wrapper.
6. Add the target-specific no-code/defer proof from this report. The formal C++ block should remain blank.
7. Preserve historical generated-boundary caveats, but update them:
   - The current generated output no longer has `class_UniAPIInit.cpp`; `auto-generated/NexusTK/platform/PlatformApi.cpp` contains empty emitter markers for [UID:0000FE], [UID:0000TQ], [UID:0000WD], [UID:0001KE], [UID:00028B], and related dispatch pages.
   - Historical `class_UniAPIInit.cpp` / `~UniAPIInit` naming remains stale provenance, not current source placement.

## Support doc changes to make later

### `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`

- Add B014 comparison note:
  - `0x0041a280` is the only live startup-table route (`0x0060d71c`) for wide API dispatch initialization.
  - `0x005995b0` and `0x005997f0` are retained/raw projection bodies with no direct route.
  - C++ for dispatch assignment belongs here or in a PlatformApi helper called by `UniAPIInit::UniAPIInit`, not in [UID:0001KE].
- Current page can remain `85/90`, or raise to `87/91` if an implementation callback adds complete first-draft C++ and resolves final table typedef/slot naming enough for source output. Without code entry, score change is optional.

### `by-file/PlatformApi.md`

- Update migration/source-shape notes:
  - `UniAPIInit` should be modeled as a file-scope static object in `platform/PlatformApi.cpp`.
  - `0x0041a280` is the compiler/startup-table route for the object initialization.
  - `0x005995b0` is retained constructor-shaped projection, not the live startup entry.
  - `0x005997e0`, `0x00599a10`, `0x0060c440`, `0x0062e57c`, and `0x006702c4` are static-lifetime/compiler support generated from that declaration.
- Recommended score if these details are incorporated without broad PlatformApi code entry: keep `88/85` or raise confidence to `87`. The file owner is already correct; this pass mainly resolves a child caveat.

### `by-class/UniAPIInit.md`

- Replace open questions with a higher-probability class/source declaration:

```cpp
class UniAPIInit {
public:
    UniAPIInit();
    virtual ~UniAPIInit();
};
```

- Add `static UniAPIInit s_uniApiInit;` or `g_uniApiInit` as a recommended file-scope object spelling, with `s_` preferred unless project convention decides process-static objects are `g_`.
- Clarify that the source destructor is effectively empty; vtable reset and scalar deleting destructor are ABI artifacts.
- Add that `ReadUtf16CodeUnitFromFile` is no longer an open class helper name; it belongs to the PlatformApi helper island.
- Recommended score: `COMPLETION:89`, `CONFIDENCE:87` from current `88/85` if the class declaration/source-shape recommendation is added. Keep the formal C++ block blank unless the class page convention accepts declaration-only output.

### `by-global/WideApiDispatchTable.md`

- Add cross-note that raw/generated projection writes at `0x005995ea` and `0x00599821` are duplicate/provenance evidence only; the live startup write is `0x0041a2b1` inside [UID:0000WD].
- Add or preserve `0x0069be1c` as `g_pfnReadUtf16CodeUnitFromFile`.
- No score change required.

### `by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md`

- Add B014 confirmation that the wrapper is registered by immediate at `0x0041a48e`, writes `0x0062e57c` to `0x006702c4`, and remains no-code/generated static-lifetime support.
- No score change required.

### `by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md`

- Add `s_uniApiInit` / file-scope static object vptr-slot wording.
- Clarify that this slot is not a standalone source pointer and should be emitted from the static object declaration.
- No score change required.

### `by-memory/0x0062e57c-0x0062e580.UniAPIInitVtableData.md`

- Add that scalar deleting destructor target `0x00599a10` is compiler-generated and source should provide only a virtual destructor declaration.
- No score change required.

### `by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md`

- No behavioral change needed. Optional cross-note: [UID:0001KE] raw projection writes to `0x0069be1c` are not ownership evidence; `ReadUtf16CodeUnitFromFile(FILE *)` remains PlatformApi helper-island code.

### `auto-generated/NexusTK/platform/PlatformApi.cpp`

- Do not edit by hand. Expected after accepted docs/autogen:
  - [UID:0001KE] remains an empty emitter marker.
  - [UID:0000WD] may become the code-emitting dispatch initializer if the implementation callback adds accepted C++ there.
  - [UID:000249] remains the current emitted helper island.

## Optional future split plan

Do not split during this report-only task. If a later by-structure repair is requested, the defensible child candidates are:

| Candidate range | Suggested child name | Reconstruction policy |
|---|---|---|
| `0x005995b0-0x005997dd` | `UniAPIInitRetainedConstructorProjection` | Reconstructable evidence, but keep no-code until live route/source declaration policy is decided; likely retained constructor-shaped body. |
| `0x005997dd-0x005997e0` | padding | ignored |
| `0x005997e0-0x005997e7` | `UniAPIInitVtableResetHelper` | no-code/generated destructor support |
| `0x005997e7-0x005997f0` | padding | ignored |
| `0x005997f0-0x00599a0b` | `RetainedWideApiDispatchInitProjection` | no-code retained duplicate projection unless a route is later found |
| `0x00599a0b-0x00599a10` | padding | ignored |
| `0x00599a10-0x00599a34` | `UniAPIInitScalarDeletingDestructor` | no-code/generated ABI helper, vtable slot target |

This split is not required for the current score recommendation because the aggregate can accurately document the mixed subranges. It may be useful if coverage tooling later requires every raw body to have exact child pages.

## Exact implementation checklist for callback

1. Edit `by-memory/0x005995b0-0x00599a34.UniAPIInit.md`.
   - Raise metadata to `87/89`.
   - Keep owner/emitter `0000ML`.
   - Refine internal subranges and padding as listed above.
   - Add direct PE scan evidence, xref negative evidence, and startup-table route.
   - Add source-shape inference for `static UniAPIInit s_uniApiInit`.
   - Add target-specific no-code/defer proof and keep `RECONSTRUCTION_CPP` blank.
   - Preserve historical Wave3/generated-boundary caveats as stale provenance, not current C++ blockers.
2. Edit `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`.
   - Add comparison note that first-draft dispatch initialization belongs here/support docs, not in [UID:0001KE].
   - Do not add C++ unless the callback explicitly accepts the support draft and table-slot naming scope.
3. Edit `by-class/UniAPIInit.md`.
   - Add the class/static-object declaration shape and empty-source-destructor policy.
   - Replace unresolved static-object wording with high-probability inference plus exact evidence.
4. Edit `by-file/PlatformApi.md`.
   - Add file-scope static object/source route and raw projection classification.
5. Edit `by-global/WideApiDispatchTable.md` only if adding the projection-vs-live-write caveat is accepted.
6. Edit `by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md`, `by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md`, and `by-memory/0x0062e57c-0x0062e580.UniAPIInitVtableData.md` only for concise support-sync notes if the supervisor includes them.
7. Do not edit `by-memory/-coverage-report.md`; supervisor applies the replacement row below.
8. Run validators listed below.

## Supervisor-owned coverage row

Exact replacement row for `by-memory/-coverage-report.md`:

```text
    - [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md) 0x005995b0-0x00599a34 | class/static initializer caveat | UniAPIInit : reconstructable : 87% : very strong : B014 2026-06-19 source-quality pass recommends `87/89`, keeps owner/emitter [UID:0000ML][PlatformApi](by-file/PlatformApi.md), and keeps target C++ blank with a target-specific no-code/defer proof: direct PE scan confirms nine-byte predecessor padding, retained constructor-shaped projection `0x005995b0-0x005997dd`, three-byte internal padding, vtable reset helper `0x005997e0-0x005997e7`, nine-byte padding before the second executable-looking body, retained duplicate initializer-shaped projection `0x005997f0-0x00599a0b`, five-byte padding, scalar deleting destructor `0x00599a10-0x00599a34`, and twelve-byte successor padding; no rel32 or absolute route reaches `0x005995b0`, `0x005997e0`, `0x005997e7`, or `0x005997f0`; real startup route is [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) via startup table `0x0060d71c`, vtable slot `0x0062e57c` points to scalar deleting destructor `0x00599a10`, static cleanup wrapper `0x0060c440` writes vptr slot `0x006702c4`, and `ReadUtf16CodeUnitFromFile` remains PlatformApi helper-island code assigned to dispatch slot `0x0069be1c` by the real initializer and raw projection refs.
```

## Validator commands for implementation callback

Run from `source-3/project-documentation` after accepted implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001KE-UniAPIInit-source-quality-removed.md](0001KE-UniAPIInit-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run validators for files actually edited, plus autogen if any emitting/source-route metadata changes. Expected result: [UID:0001KE] remains an empty emitter marker in `auto-generated/NexusTK/platform/PlatformApi.cpp`; [UID:000249] remains emitted; [UID:0000WD] remains empty unless the implementation callback explicitly adds accepted C++ there.

## IDA rename/type/comment recommendations

High confidence:

- Name/comment `0x0041a280` as `WideApiDispatchInit` / PlatformApi startup initializer.
- Name `0x00599570` as `ReadUtf16CodeUnitFromFile`.
- Name `0x00599a10` as `UniAPIInit::ScalarDeletingDestructor` or `UniAPIInit_scalar_deleting_destructor`.
- Name/comment `0x0060c440` as `UniAPIInitStaticCleanupWrapper`.
- Name/comment `0x0062e57c` as `UniAPIInit::vftable`.
- Name/comment `0x006702c4` as `s_uniApiInit` object vptr slot / `UniAPIInit` static object storage.

Medium confidence:

- Comment `0x005995b0` as `retained UniAPIInit constructor-shaped dispatch initializer projection`; avoid final global rename to `UniAPIInit::UniAPIInit` until IDA/function-boundary policy is decided.
- Comment `0x005997f0` as `retained duplicate WideApi dispatch initializer projection`; avoid source-facing function rename unless a route is found.
- Comment `0x005997e0` as `UniAPIInit vtable reset / non-deleting destructor support`.

Do not rename globally from this pass alone:

- Do not make `0x005997e7` a function start; it is padding before the `0x005997f0` raw body.
- Do not rename consumer aliases at `0x0069be14+` from this target pass except where `WideApiDispatchTable` already has accepted names.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0001KE-UniAPIInit-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0001KE"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001KE-UniAPIInit-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0001KE-UniAPIInit-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001KE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
