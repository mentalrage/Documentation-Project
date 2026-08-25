** TARGET-REPORT-UID:0000YQ **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000YQ] ApplicationErrorStateCleanup Source-Quality Report

Agent: B005  
Target: [UID:0000YQ] `by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md`  
Required output: report-only source-quality / heuristic-inference pass  
Date: 2026-06-18

## Final Recommendation

Raise the target from `84/89` to `86/91`, keep it reconstructable, keep [UID:0000HG] `Application` as the current canonical owner/emitter route, and keep the formal `RECONSTRUCTION_CPP` block blank.

The important breakthrough is the source-level type: the object is not a bespoke `ApplicationErrorState` class. The vtable/COL evidence resolves it as the Application-owned wide `_AUTOBUF<wchar_t>` static used to store the pending application error text. The current page title may remain stable for UID continuity, but the target prose should be rewritten as "`_AUTOBUF<wchar_t>` application error-text deleting destructor / cleanup" rather than generic "ApplicationErrorState" cleanup.

The function at `0x004632c0-0x0046330b` is source-declared/generated-binary code: a compiler-emitted deleting destructor path for a concrete `_AUTOBUF<wchar_t>` instantiation. Application source should declare/use the static error-text buffer and the setter/display logic; it should not hand-author this scalar deleting destructor body.

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:91
CANONICAL_OWNER:0000HG
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000HG
RECONSTRUCTION_CPP CODE:[[[]]]
```

If the supervisor chooses to add a new by-type/by-class page for `_AUTOBUF<wchar_t>`, this target could later move to that type owner or dual-route through [UID:0000HM] `AUTOBUF`. For the current documentation state, Application remains the best direct route because the only proven wide specialization instance is the Application error-text static at `0x0067a998-0x0067a9a0`.

## Evidence Sources Rechecked

- Target page [UID:0000YQ] `0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md`.
- Support pages [UID:0003OY] `0x00612574-0x00612580.ApplicationErrorStateVtableData.md`, [UID:000292] `0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics.md`, [UID:0002H1] `ApplicationCleanupResources`, [UID:0000HG] `Application`, [UID:0000W7] `StaticInitializerWrappersPreOle`, [UID:00024E] `StaticCleanupThunksBeforeAutoInit`, [UID:000195] `LObjectRuntimeShell`, [UID:000226] `CriticalSectionApiWrappers`, and the AUTOBUF docs [UID:0000HM], [UID:0001WN], [UID:00000P], [UID:000188], [UID:00019E], [UID:0002MR].
- Prior neighboring-family reports, especially B001's `IntAlphaSurfaceVtable` report, which already excluded `0x004632c0` from the IntAlphaSurface/AlphaMaskSurface family.
- Local IDA export artifacts under `C:\Users\admin\Desktop\CTools\Output\ida\`: `functions.json`, `decompile/*.json`, `globals.json`, `xrefs.json`, `rtti_hierarchy.json`, `segments.json`, and `memory.bin`.
- IDA MCP was attempted and unavailable for this run because the direct endpoint request failed to connect, so this report uses the current by-* live-IDA evidence plus local IDA export data rather than new live MCP queries.

> The removed literal PowerShell command is preserved only in [0000YQ-ApplicationErrorStateCleanup-source-quality-removed.md](0000YQ-ApplicationErrorStateCleanup-source-quality-removed.md). The archive is non-authoritative and must not be executed.

## Exact Range, Bytes, Boundary, Padding

`functions.json` reports `sub_4632C0` at `0x004632c0-0x0046330b`, size `0x4b` / 75 bytes (Verified with `int_convert.py`). The target is a modeled function, not raw padding or a tail of the previous IntAlphaSurface destructor.

Function bytes from local export:

```text
0x004632c0: 55 8b ec 56 8b f1 ff 76 04 c7 06 74 25 61 00 e8
0x004632d0: c5 44 16 00 83 c4 04 8b ce e8 b2 17 09 00 8b 45
0x004632e0: 08 a8 01 74 1f a8 04 75 10 56 e8 d1 17 09 00 83
0x004632f0: c4 04 8b c6 5e 5d c2 04 00 6a 0c 56 e8 9f 83 fb
0x00463300: ff 83 c4 08 8b c6 5e 5d c2 04 00
```

Boundary findings:

- Predecessor [UID:0000VN] `0x004632b1-0x004632c0` is 15 bytes of `0xcc` alignment padding.
- Target starts cleanly at `push ebp` at `0x004632c0`.
- Target ends at `0x0046330b` after `retn 4`.
- Successor [UID:0000VN] `0x0046330b-0x00463310` is five bytes of `0xcc` alignment padding (Verified with `int_convert.py` for `0x5` / 5).

No split or range change is needed for [UID:0000YQ].

## Function Semantics

Current decompile of `0x004632c0`:

```cpp
_DWORD *__thiscall sub_4632C0(_DWORD *Block, char a2)
{
  void *v4;

  v4 = (void *)Block[1];
  *Block = &off_612574;
  j_j_j___free_base(v4);
  sub_4F4A90(Block);
  if ((a2 & 1) == 0 || (a2 & 4) != 0)
    return Block;
  sub_4F4AC0(Block);
  return Block;
}
```

Interpretation:

- `this+0x00` is the `_AUTOBUF<wchar_t>` / `LObject`-compatible vptr.
- `this+0x04` is the owned buffer pointer. In the Application instance this is `0x0067a99c`, currently named `Block` in IDA exports.
- The destructor stores vtable `0x00612574`, frees the payload pointer, calls `LObject` destructor body `0x004f4a90`, and conditionally calls the delete wrapper `0x004f4ac0`.
- The delete flag argument follows MSVC deleting-destructor convention. `a2 & 1` enables scalar object deletion; `a2 & 4` routes through the compiler/vector-delete guard/no-op path rather than the scalar `operator delete` wrapper. This is compiler policy, not source-authored application logic.
- The local decompile metadata also lists `_guard_check_icall_nop`/`0x0041b6a0` as a callee on the bit-4 path. It should not be modeled as a project helper or source method.

The function is therefore best named descriptively as `_AUTOBUF<wchar_t>::scalar deleting destructor` or `ApplicationErrorTextAutoBufDeletingDestructor`, not `ApplicationErrorState::Cleanup`.

## Xrefs, Reachability, Startup, Atexit

Direct ordinary code callers to `0x004632c0`: none found. The only direct absolute reference to the function body is the vtable slot at `0x00612574`. This matches a virtual deleting destructor that is reached through generated vtable/static-object cleanup paths rather than normal source calls.

Pointer and xref checks from local exports:

```text
0x004632c0 <- 0x00612574        vtable slot
0x00612574 <- 0x00419e95        static initializer vptr store
0x00612574 <- 0x004632cb        self vptr restore in destructor
0x00612574 <- 0x0060c0bc        atexit cleanup thunk vptr restore
0x0067a998 <- 0x00419e81        static initializer LObject construction target
0x0067a998 <- 0x00419e91        static initializer vptr store target
0x0067a998 <- 0x0060c0b8        atexit cleanup thunk vptr store target
0x0067a998 <- 0x0060c0c9        atexit cleanup thunk LObject destructor target
0x0067a99c <- 0x00419e9b        static initializer payload zero
0x0067a99c <- 0x00464b74        Application cleanup message-box text load
0x0067a99c <- 0x00465b0d        SetApplicationErrorText free old buffer
0x0067a99c <- 0x00465b42        SetApplicationErrorText store new buffer
0x0067a99c <- 0x004665c0        Main_WndProc error-code path free old buffer
0x0067a99c <- 0x004665f6        Main_WndProc error-code path store new buffer
0x0067a99c <- 0x0060c0b2        atexit cleanup thunk free old buffer
0x0067a9a0 <- 0x00419ea5        static initializer count zero
0x0067a9a0 <- 0x00464b63        Application cleanup non-empty test
0x0067a9a0 <- 0x00465b37        SetApplicationErrorText count store
0x0067a9a0 <- 0x004665ea        Main_WndProc error-code path count store
0x0060c0b0 <- 0x00419e8b        atexit registration
0x00419e80 <- 0x0060d69c        startup initializer table
```

Modeled related functions:

- `0x00419e80-0x00419eb4`, size `0x34` / 52 bytes (Verified with `int_convert.py`): compiler static initializer. It calls `LObject` constructor `0x004f4a80`, writes vtable `0x00612574`, zeros `0x0067a99c` and `0x0067a9a0`, and registers `0x0060c0b0` with `atexit`.
- `0x0060c0b0-0x0060c0d2`, size `0x22` / 34 bytes (Verified with `int_convert.py`): static cleanup thunk. It restores vtable `0x00612574`, frees the payload pointer, and calls `LObject` destructor body. It is compiler/linker cleanup support, not a source-facing Application helper.
- `0x00465af0-0x00465b6f`, size `0x7f` / 127 bytes (Verified with `int_convert.py`): source-facing error-text setter candidate. It computes `wcslen(Source) + 1`, frees the old payload, allocates `2 * count`, stores count and pointer, and copies with `wcscpy_s`. Direct code callers found at `0x00596b6b` and `0x005c08ef`.
- `0x00465f20-0x0046673c`, size `0x81c` / 2076 bytes (Verified with `int_convert.py`): `Main_WndProc` contains an inlined error-code text replacement path for message `0x405`, formatting `L"Error #%03d"` into the same payload/count fields and then requesting application shutdown.
- `0x00464a60` / [UID:0002H1] `ApplicationCleanupResources`: displays `MessageBoxW(0, Block, L"Error", 0)` when `2 * dword_67A9A0` is nonzero.

This reachability supports reconstructable source effects while keeping [UID:0000YQ] itself in the generated deleting-destructor category.

## Vtable, RTTI, And Type Resolution

The target's key source-quality improvement is at the `.rdata` boundary.

Current [UID:0003OY] documents `0x00612574-0x00612580` as the three-slot Application error-state vtable:

```text
0x00612574 -> 0x004632c0
0x00612578 -> 0x004f4b10
0x0061257c -> 0x0041b6c0
0x00612580 -> UTF-16 "S" successor literal
```

The local export byte/pointer check shows the immediately preceding dword:

```text
0x00612570 -> 0x00641ee4
```

`globals.json` names `0x00641ee4` as:

```text
??_R4?$_AUTOBUF@_W@@6B@
```

That is the MSVC complete-object locator for `_AUTOBUF<wchar_t>`. Nearby RTTI globals reinforce the same type family:

```text
0x00641ef8 ??_R3?$_AUTOBUF@_W@@8
0x00641f08 ??_R2?$_AUTOBUF@_W@@8
0x00641f14 ??_R1A@?0A@EA@?$_AUTOBUF@_W@@8
0x0067450c ??_R0?AV?$_AUTOBUF@_W@@@8
```

This rejects the earlier "bespoke ApplicationErrorState class" wording. The source-facing type should be documented as `_AUTOBUF<wchar_t>` / `AUTOBUF<wchar_t>`, with Application-owned static use. Exact original header spelling is not new evidence; existing AUTOBUF docs still keep `_AUTOBUF`/`AUTOBUF`/`AutoBuf` casing open. The RTTI proves the decorated class spelling `_AUTOBUF<wchar_t>` for this binary artifact.

Support range note: [UID:0003OY] currently begins at `0x00612574`, so it omits the RTTI locator pointer at `0x00612570`. The immediate predecessor [UID:0003OZ] ends at `0x00612574`. If the supervisor wants structural precision, trim [UID:0003OZ] to end at `0x00612570` and expand/rename [UID:0003OY] to `0x00612570-0x00612580.ApplicationWideAutoBufVtableData.md` or equivalent. This is not required to fix [UID:0000YQ]'s function range, but it is the cleanest support-doc repair for the resolved type.

## Source-Facing Names And Field Model

Best defensible source declarations:

```cpp
// Application.cpp source-shape recommendation only; do not paste into [UID:0000YQ]'s formal C++ block.
static _AUTOBUF<wchar_t> s_applicationErrorText;

static void SetApplicationErrorText(const wchar_t* text);
```

Best field names:

| Address / offset | Current IDA name | Source-facing meaning | Recommended name |
| --- | --- | --- | --- |
| `0x0067a998` / `+0x00` | `dword_67A998` | `_AUTOBUF<wchar_t>` object header/vptr | `s_applicationErrorText` |
| `0x0067a99c` / `+0x04` | `Block` | owned wide payload pointer | `s_applicationErrorText.m_data` or `m_buffer` |
| `0x0067a9a0` / `+0x08` | `dword_67A9A0` | count of wide characters, including terminator | `s_applicationErrorText.m_count` or `m_cch` |

I prefer `m_data` / `m_count` for the generic AUTOBUF template field names because the unsigned-char AUTOBUF pages document the same `+0x04` pointer and `+0x08` count/capacity layout. For Application-specific prose, call the count "stored wide-character count including the null terminator." The binary uses `wcslen(Source) + 1`, stores that count at `0x0067a9a0`, allocates `2 * count`, and tests `2 * count` before displaying the stored pointer.

Best helper name for `0x00465af0`: `SetApplicationErrorText(const wchar_t* text)` or `SetApplicationErrorMessage(const wchar_t* text)`. I recommend `SetApplicationErrorText` because the helper only stores the text payload; the display path is in `Application::CleanupResources`, and `Main_WndProc` has an inline equivalent for formatted `Error #%03d` text.

## Owner / Source Route Ranking

1. [UID:0000HG] `Application` - keep as current canonical owner/emitter. The concrete static object is Application error-message state, initialized from the startup table, consumed by `Application::CleanupResources`, written by Application/error-message paths, and grouped with [UID:000292] Application statics. This route is directly source-useful even though the destructor code body is compiler-generated.

2. [UID:0000HM] `AUTOBUF` / a future `_AUTOBUF<wchar_t>` by-type page - strong type owner, but not the best current canonical target owner unless the supervisor creates a wide AUTOBUF type record. The RTTI proves `_AUTOBUF<wchar_t>`, and the unsigned-char AUTOBUF pages establish the same field layout and blank-C++ policy for compiler-emitted template helpers. However, the concrete wide specialization is currently proven only through the Application static, not through cross-feature wide AUTOBUF fan-out.

3. Small runtime/error-state helper file - rejected as canonical owner. The static object is App-level state, and no independent helper file, source path, or non-Application consumer cluster appears. A source helper function such as `SetApplicationErrorText` can stay in Application.cpp.

4. [UID:0000YK]/AlphaMaskSurface and [UID:00006K]/IntAlphaSurface - rejected. Nearby code adjacency is accidental. The target vtable is `0x00612574`, not the Alpha/IntAlpha vtables; the predecessor report for IntAlphaSurface already excluded `0x004632c0`; the target globals and call/use paths are Application error-message storage, not pixel-surface storage.

5. [UID:000195] `LObject` runtime support - rejected as canonical owner. `LObject` supplies the base constructor/destructor and inherited virtual slot, but the vtable COL and payload layout are `_AUTOBUF<wchar_t>`, and the concrete static storage belongs to Application.

6. No-owner / non-reconstructable fallback - rejected. The type, vtable, static initializer, cleanup thunk, payload fields, setter/display users, and Application source route are now strong enough to stay reconstructable and move above the 85 gate.

## First-Draft C++ / No-Code Proof

Do not populate [UID:0000YQ]'s formal C++ block.

Target-specific proof:

- The body is a compiler-emitted deleting destructor path with MSVC delete-flag argument semantics, a vtable restore, base `LObject` destructor call, and delete-wrapper dispatch. This shape is not source-authored Application code.
- Direct ordinary callers are absent. Reachability comes through the `_AUTOBUF<wchar_t>` vtable slot, startup initializer, and atexit/static cleanup thunk.
- Existing AUTOBUF pages [UID:000188], [UID:00019E], [UID:0001WN], and [UID:0002MR] intentionally keep formal C++ blank for comparable concrete template/helper/vtable artifacts while documenting source-declared/generated-binary handling.
- The source construct that should recreate this binary artifact is the Application static `_AUTOBUF<wchar_t>` declaration plus the generic AUTOBUF template support, not a handwritten scalar deleting destructor.

Recommended declaration/source shape for support docs, not formal target C++:

```cpp
// Likely Application.cpp source shape.
static _AUTOBUF<wchar_t> s_applicationErrorText;

static void SetApplicationErrorText(const wchar_t* text)
{
    const size_t count = wcslen(text) + 1;
    // Exact original AUTOBUF API is not proven. The binary effect is:
    // free old s_applicationErrorText.m_data;
    // allocate count * sizeof(wchar_t);
    // store count and pointer;
    // wcscpy_s(pointer, count, text);
}

// Application cleanup displays:
// if (s_applicationErrorText.m_count != 0)
//     MessageBoxW(nullptr, s_applicationErrorText.m_data, L"Error", 0);
```

The exact source API (`Resize`, `assign`, direct member use, or another project helper) is not safely inferable from this target alone. That uncertainty caps confidence below final-source quality but does not block the score increase, because the target-specific decision is declaration/generated-code policy rather than source body emission.

## Heuristic / Inference Reanalysis And Validation

### Issue 1: Is this a real function and is the half-open range exact?

Evidence checked: `functions.json`, target bytes from `memory.bin`, current target doc, coverage rows for predecessor/successor padding. Rejected alternatives: merging with preceding IntAlphaSurface destructor, extending into `0x0046330b-0x00463310`, or trimming before the final `retn 4`.

Best inference: exact function range is `0x004632c0-0x0046330b`, with padding on both sides. No split/range change for [UID:0000YQ].

Effect: supports score increase; no coverage range edit except score/prose.

### Issue 2: What is the source-level type?

Evidence checked: vtable slot data at `0x00612574`, predecessor dword `0x00612570`, `globals.json` RTTI names for `??_R4?$_AUTOBUF@_W@@6B@`, existing AUTOBUF unsigned-char pages, `LObject` runtime shell docs, target decompile field layout.

Rejected alternatives:

- Bespoke `ApplicationErrorState`: descriptive but not the compiler type. No RTTI or class-vtable evidence supports that class name.
- `LObject` only: base helpers are present, but the vtable COL resolves `_AUTOBUF<wchar_t>`.
- `AboveFrame`: local decompile metadata's vtable heuristic is polluted; no vtable pointer, RTTI, storage, or caller evidence supports it.
- AlphaMaskSurface/IntAlphaSurface: rejected by different vtable and Application storage/user evidence.

Best inference: source-facing type is `_AUTOBUF<wchar_t>` / `AUTOBUF<wchar_t>`, used as an Application-owned static error-text buffer.

Effect: resolves the main blocker, raises completion/confidence, and supports support-doc updates. Exact original header casing remains open but no longer blocks source placement.

### Issue 3: What are the global and field names?

Evidence checked: static initializer zeros `0x0067a99c` and `0x0067a9a0`, setter writes `wcslen + 1` and allocates `2 * count`, `Main_WndProc` inline writes the same fields, `ApplicationCleanupResources` displays `Block` when `2 * count` is nonzero, AUTOBUF<unsigned char> field model uses pointer at `+0x04` and count at `+0x08`.

Rejected alternatives:

- `Block` as a source name: IDA/CRT artifact, not source-quality.
- `m_bytes` for `+0x08`: rejected because the wide path stores character count and allocates bytes separately as `2 * count`.
- `m_lengthWithoutNull`: rejected because stores are `wcslen + 1`.

Best inference: `static _AUTOBUF<wchar_t> s_applicationErrorText`, with `m_data`/`m_buffer` at `+0x04` and `m_count`/`m_cch` at `+0x08`, where the Application semantic is "wide-character count including terminator."

Effect: enough for support-doc/source-shape text; exact original static variable spelling remains unknowable from binary and caps confidence at `91`, not score below `85`.

### Issue 4: What helper/method name is defensible?

Evidence checked: `0x00465af0` decompile, direct callers at `0x00596b6b` and `0x005c08ef`, `Main_WndProc` inline error-code replacement path, display path in `ApplicationCleanupResources`.

Rejected alternatives:

- `ApplicationErrorStateCleanup` as a source method: target is a generated destructor, not the setter.
- `SetErrorCode`: too narrow; `0x00465af0` accepts arbitrary wide text.
- AUTOBUF generic `Resize`: `0x00465af0` is Application-specific wide-string replacement logic, not the generic AUTOBUF resize helper.

Best inference: `SetApplicationErrorText(const wchar_t* text)` is the best support-doc helper name for `0x00465af0`. `Main_WndProc` contains an inlined equivalent for formatted errors.

Effect: support-doc update only; not a formal C++ body for [UID:0000YQ].

### Issue 5: Are static initializer and atexit cleanup source-authored?

Evidence checked: [UID:0000W7], [UID:00024E], pointer refs from startup table `0x0060d69c`, `atexit(sub_60C0B0)` in `0x00419e80`, current static cleanup thunk decompile.

Rejected alternatives:

- Application explicit startup function: no ordinary caller; reached via startup table.
- Source-authored `DestroyApplicationErrorState`: no naming or direct caller evidence; body matches compiler static cleanup.

Best inference: `0x00419e80` and `0x0060c0b0` are generated static initialization/destruction wrappers for the Application-owned static `_AUTOBUF<wchar_t>`.

Effect: supports blank target C++ and prevents introducing fake helper declarations.

### Issue 6: What does the vtable range imply for support docs?

Evidence checked: bytes around `0x00612570-0x00612580`, [UID:0003OY], [UID:0003OZ], [UID:0003P0], `globals.json` RTTI names.

Rejected alternatives:

- Keep calling `0x00612574-0x00612580` complete vtable data without noting the COL pointer: incomplete for source-type inference.
- Merge through `0x006125a4`: rejected because `0x00612580` begins a separate UTF-16 literal area and [UID:0003P1]/PasswordError data follows later.

Best inference: the semantic vtable/COL slice is `0x00612570-0x00612580` for `_AUTOBUF<wchar_t>`, with the vtable entries still starting at `0x00612574`.

Effect: recommend support-doc boundary/prose repair. It does not force a [UID:0000YQ] code-range change.

### Issue 7: Should owner/emitter change?

Evidence checked: Application file page, Application cleanup page, data static page, AUTOBUF file/type pages, vtable/COL, direct user/caller evidence, rejected Alpha/IntAlpha reports.

Rejected alternatives: Alpha/IntAlpha, `LObject`, no-owner, independent error-state file. AUTOBUF type owner is real but not currently modeled for wide specialization.

Best inference: keep [UID:0000HG] as current canonical owner/emitter route, add explicit dependency note to [UID:0000HM] AUTOBUF, and optionally create a future `_AUTOBUF<wchar_t>` type page if the supervisor wants type-owner parity with `_AUTOBUF<unsigned char>`.

Effect: metadata owner/emitter stays stable; score rises because the owner/no-owner ambiguity is resolved enough for the current doc structure.

### Issue 8: Should the target emit first-draft C++?

Evidence checked: target decompile, delete-flag behavior, vtable-only reachability, startup/atexit wrappers, AUTOBUF generated-code policy in support docs.

Rejected alternatives:

- Emit a handwritten `ApplicationErrorState::~ApplicationErrorState`: wrong type and wrong generated-wrapper level.
- Emit a specialized `_AUTOBUF<wchar_t>` destructor body in Application.cpp: would turn a compiler-generated deleting destructor into hand source and still would not match the original template/header contract.

Best inference: no formal target C++. Emit only source-shape recommendations in support docs: Application static `_AUTOBUF<wchar_t>` declaration and `SetApplicationErrorText` logic; AUTOBUF template support should produce the destructor artifact.

Effect: target remains reconstructable but generated-code/declaration-driven; blank formal block is required, not a blocker.

## Support-Doc Update Recommendations

### Target [UID:0000YQ]

Placement: replace current status/reconstruction wording that says the final helper/type name is provisional.

Recommended replacement text:

```text
Source-quality update: B005 reanalysis resolves the source-level type as the Application-owned `_AUTOBUF<wchar_t>` error-text static, not a bespoke `ApplicationErrorState` class. The function is the compiler-emitted deleting destructor path for that concrete AUTOBUF instance: it restores vtable `0x00612574`, frees the owned wide payload at `this+0x04`, calls `LObject` destructor body `0x004f4a90`, and conditionally dispatches the scalar delete wrapper `0x004f4ac0` according to MSVC deleting-destructor flags. Direct ordinary callers remain absent; reachability is through the vtable slot, static initializer `0x00419e80`, and atexit cleanup thunk `0x0060c0b0`.

Final C++ policy: keep the formal C++ block blank. The source effect should be recreated by an Application.cpp static `_AUTOBUF<wchar_t>` declaration and AUTOBUF template support, not by hand-authoring this compiler-generated deleting destructor.
```

Recommended source-facing name note:

```text
Preferred descriptive name: `ApplicationErrorTextAutoBufDeletingDestructor` / `_AUTOBUF<wchar_t>` scalar deleting destructor. Keep `ApplicationErrorStateCleanup` as a stable page title only if avoiding a rename.
```

### [UID:000292] ApplicationErrorAndCriticalSectionStatics

Placement: layout/source-name section.

Recommended text:

```text
B005 source-quality reanalysis resolves `0x0067a998-0x0067a9a4` as an Application-owned `_AUTOBUF<wchar_t>` static used for deferred error text. Recommended source shape is `static _AUTOBUF<wchar_t> s_applicationErrorText;`. Field `0x0067a99c` / `+0x04` is the owned wide payload pointer (`m_data`/`m_buffer`), and `0x0067a9a0` / `+0x08` is the stored wide-character count including the null terminator (`m_count`/`m_cch`). The adjacent `0x0067a9a4-0x0067a9c0` critical section remains separate Application state, not part of the AUTOBUF object.
```

### [UID:0003OY] ApplicationErrorStateVtableData

Placement: range/layout section.

Recommended text if the supervisor keeps the current filename/range:

```text
B005 reanalysis found the RTTI locator pointer immediately before this page: `0x00612570 -> 0x00641ee4`, named `??_R4?$_AUTOBUF@_W@@6B@` in local IDA globals. The three documented slots at `0x00612574-0x00612580` are therefore the vtable body for `_AUTOBUF<wchar_t>`, with `0x00612580` still beginning the successor UTF-16 literal. Preferred descriptive name is `ApplicationWideAutoBufVtableData`.
```

Optional structural repair:

```text
Trim [UID:0003OZ] `0x006112fc-0x00612574.MsvcStlLocaleNameData` to end at `0x00612570`.
Expand/rename [UID:0003OY] from `0x00612574-0x00612580.ApplicationErrorStateVtableData` to `0x00612570-0x00612580.ApplicationWideAutoBufVtableData`, with layout:
  0x00612570 -> 0x00641ee4  RTTI COL `??_R4?$_AUTOBUF@_W@@6B@`
  0x00612574 -> 0x004632c0  `_AUTOBUF<wchar_t>` deleting destructor
  0x00612578 -> 0x004f4b10  inherited `LObject` runtime-class/name helper
  0x0061257c -> 0x0041b6c0  inherited/default no-op virtual
```

### [UID:0000HG] Application

Placement: source-shape / evidence map section.

Recommended text:

```text
Application owns a static wide AUTOBUF error-text buffer, recommended source-facing shape `static _AUTOBUF<wchar_t> s_applicationErrorText;`. Startup static initialization constructs it through `0x00419e80`; atexit cleanup is emitted at `0x0060c0b0`; `Application::CleanupResources` displays `s_applicationErrorText.m_data` with title `L"Error"` when `m_count` is nonzero; `0x00465af0` is best documented as `SetApplicationErrorText(const wchar_t*)`; `Main_WndProc` has an inline formatted `L"Error #%03d"` replacement path. The deleting destructor [UID:0000YQ] remains generated AUTOBUF/template support and should keep formal C++ blank.
```

### [UID:0000HM] AUTOBUF

Placement: Known concrete code or evidence map.

Recommended text:

```text
In addition to the documented `_AUTOBUF<unsigned char>` instantiation, B005 reanalysis of [UID:0000YQ] identifies an Application-owned `_AUTOBUF<wchar_t>` static at `0x0067a998`, with RTTI COL `??_R4?$_AUTOBUF@_W@@6B@` referenced from `0x00612570` and vtable body `0x00612574-0x00612580`. This wide instantiation stores a payload pointer at `+0x04` and a wide-character count including terminator at `+0x08`. Current source route remains through Application because the wide specialization is proven only for the Application error-text static.
```

## Coverage Row Recommendation

Do not edit `by-memory/-coverage-report.md` directly. Replace the existing [UID:0000YQ] row at the current placement between the `0x004632b1-0x004632c0` padding row and the `0x0046330b-0x00463310` padding row with:

```text
    - [UID:0000YQ][0x004632c0-0x0046330b.ApplicationErrorStateCleanup](by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md) 0x004632c0-0x0046330b | scalar deleting destructor / static wide AUTOBUF cleanup | ApplicationErrorStateCleanup : reconstructable : 86% : very-strong : B005 reanalysis resolves the provisional type as the Application-owned `_AUTOBUF<wchar_t>` error-text holder rather than AlphaMaskSurface/IntAlphaSurface or bespoke runtime state; exact `0x4b` / 75-byte function (Verified with `int_convert.py`) stores vtable `0x00612574`, frees payload at `+4`, calls `LObject` destructor body, conditionally dispatches the scalar delete wrapper according to MSVC deleting-destructor flags, has no direct ordinary callers, and is reached through the `_AUTOBUF<wchar_t>` vtable/static initializer `0x00419e80`/atexit thunk `0x0060c0b0`; source emission should be Application.cpp static declaration plus AUTOBUF template support, so the formal function C++ block remains blank.
```

If the supervisor applies the optional [UID:0003OY] range rename, update the vtable support row separately; no [UID:0000YQ] range text changes are needed.

## Open Questions And Their Effects

1. Exact original static variable spelling is not binary-proven. Best defensible source name is `s_applicationErrorText`. This affects only final naming polish and confidence cap; it does not affect owner/emitter, range, or reconstructability.

2. Exact AUTOBUF header casing/API (`_AUTOBUF`, `AUTOBUF`, `AutoBuf`, `Resize`, `assign`, or direct member operations) remains a project-wide AUTOBUF question already recorded by [UID:0000HM]/[UID:0001WN]. This supports leaving [UID:0000YQ] formal C++ blank; it does not justify leaving the type as unknown.

3. Optional support-doc structural repair for `0x00612570-0x00612580` is recommended but not required to complete [UID:0000YQ]. If not applied, [UID:0003OY] should at least mention the omitted COL pointer so future reports do not regress to "ApplicationErrorState" as a source type.

No remaining open question blocks raising [UID:0000YQ] above the 85 completion gate.

## Changed Files

This report is the only file changed by Agent-B005:

```text
project-documentation/tools/leaser/Agents/Agent-B005/research/0000YQ-ApplicationErrorStateCleanup-source-quality.md
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0000YQ-ApplicationErrorStateCleanup-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0000YQ"} -->
<!-- {"agent":"B005","command_id":"000000023047","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000YQ-ApplicationErrorStateCleanup-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0000YQ-ApplicationErrorStateCleanup-source-quality.md","timestamp":"2026-08-13T02:36:38-04:00","uid":"0000YQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
