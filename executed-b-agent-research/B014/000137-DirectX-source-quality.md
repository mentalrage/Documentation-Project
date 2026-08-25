** TARGET-REPORT-UID:000137 **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:000137] DirectX Source-Quality Reanalysis

Agent: Agent-B014  
Target: `project-documentation/by-memory/0x004a1b60-0x004a1d6a.DirectX.md`  
Required output: `project-documentation/tools/leaser/Agents/Agent-B014/research/000137-DirectX-source-quality.md`  
Date: 2026-06-19

## Executive Recommendation

`0x004a1b60-0x004a1d6a.DirectX` should remain a reconstructable DirectX class/source cluster placed in `NexusTK/render/DirectX.cpp`, but its source-quality notes should be tightened before final C++ is emitted.

Recommended target metadata changes:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:00003Y
EMITTER_UIDS:00003Y
```

Rationale: the cluster is semantically class-owned by `DirectX` rather than directly file-owned, while `by-class/DirectX.md` already emits through `by-file/DirectX.md` to `NexusTK/render/DirectX.cpp`. The source-authored content is the constructor and ordinary virtual destructor. The constructor-unwind singleton-clear helper, scalar deleting destructor, far EH chunks, vtable stores, base destructor calls, and alignment padding are compiler output and should be explained in documentation, not handwritten as independent source functions.

First-draft C++ is ready after this routing/source-shape correction. The code should express `DirectDrawCreate`, `IDirectDraw::QueryInterface(IID_IDirectDraw, ...)`, pointer-thrown `MyError`, and unconditional release in the ordinary destructor. It should not emit a local GUID constant, a source-level scalar deleting destructor, a source-level unwind helper, or a defensive destructor null check not present in the binary.

## Evidence Read

- Target doc: `by-memory/0x004a1b60-0x004a1d6a.DirectX.md`
- Parent file doc: `by-file/DirectX.md`
- Class doc: `by-class/DirectX.md`
- Singleton doc: `by-global/g_pDirectX.md`
- Vtable docs: `by-type/by-vtable/DirectXVtable.md`, `by-memory/0x00618e60-0x00618e70.DirectXVtableData.md`
- GUID docs: `by-memory/0x00631570-0x00631580.DirectDrawGuidConstant.md`, `by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md`
- Diagnostic string doc: `by-memory/0x00618e70-0x00618efc.DirectXDiagnosticString.md`
- Singleton memory doc: `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md`
- Existing generated draft: `simroot_v2/class_DirectX.cpp`
- Existing empty emitter file: `auto-generated/NexusTK/render/DirectX.cpp`
- Local exports: `core/data/readonly/prewave/exported-functions/0x004a1b60.json`, `core/data/readonly/wave2/classes/DirectX.json`
- Context docs: `by-project-structure/proposed-source-tree.md`, `by-file/GrafPort.md`, `by-file/Surface.md`, `by-class/GrafPort.md`, `by-class/MyError.md`, `by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md`, `by-type/by-struct/ErrorObjectLayouts.md`

Live IDA MCP was attempted at `127.0.0.1:13337`, but the port was not accepting connections in this session. This report therefore relies on the existing IDA-backed documentation and local Ghidra/IDA export JSON already checked into the project. Those exports include both Ghidra and IDA decompiler evidence for the target constructor/destructor.

## Current Target State

The target currently covers:

- `0x004a1b60-0x004a1c56`: `DirectX::DirectX`
- `0x004a1c60-0x004a1cbc`: `DirectX::~DirectX`
- `0x004a1cc0-0x004a1ccb`: constructor-unwind singleton clear helper
- `0x004a1cd0-0x004a1d6a`: scalar deleting destructor
- alignment gaps at `0x004a1c56-0x004a1c5f`, `0x004a1cbc-0x004a1cbf`, `0x004a1ccb-0x004a1ccf`, and `0x004a1d6a-0x004a1d6f`

The current score is `84/90`, `RECONSTRUCTABLE:TRUE`, with `CANONICAL_OWNER:0000IW` and `EMITTER_UIDS:0000IW`. Its C++ block is blank under an older stricter source gate.

The target's behavioral interpretation is mostly correct, but the remaining source-quality issues are enough to affect first-draft C++:

- the `QueryInterface` GUID should be SDK `IID_IDirectDraw`, not a project-authored `kDirectDrawInterfaceId`;
- the thrown exception type is `MyError *`, not value `MyError`;
- `this+4` is the stored DirectDraw interface field;
- the destructor release is unconditional in the binary;
- the constructor-unwind helper and scalar deleting destructor are compiler artifacts;
- direct owner should be the class page, with file output via the existing class-to-file route.

## Function-Level Findings

### Constructor `0x004a1b60-0x004a1c56`

IDA/prewave evidence shows this shape:

- calls the `LObject` constructor first;
- records constructor EH state;
- stores `g_pDirectX = this`, with a decompiler artifact branch for `this == -4`;
- installs the `DirectX` vtable;
- zeroes `this+4`;
- calls `DirectDrawCreate(NULL, &lpDD, NULL)`;
- on failure, allocates 8 bytes, constructs `MyError` from the DirectX diagnostic string, and throws with `_TI4PAVMyError__`;
- on success, calls `lpDD->QueryInterface(lpDD, &IID_IDirectDraw, (LPVOID *)(this+4))`;
- on `QueryInterface` failure, repeats the same heap `MyError` pointer throw path.

Source-quality implications:

- The source throw spelling should be `throw new MyError(L"...");`, not `throw MyError(L"...");`.
- The failure string is the existing DirectX diagnostic string at `0x00618e70`.
- No source cleanup release of `lpDD` is visible on success or on `QueryInterface` failure. Adding one would be a source improvement, not reconstruction.
- The vtable store and EH state writes are compiler output.
- Base construction should be represented through C++ inheritance, not an explicit `LObject::LObject(this)` call in final source.

### Ordinary Destructor `0x004a1c60-0x004a1cbc`

IDA/wave2 evidence shows:

- load `this[1]`;
- store the `DirectX` vtable;
- call the COM vtable slot at offset `+8`, i.e. `Release`;
- set `this[1] = 0`;
- clear `g_pDirectX`;
- tail-call/base-destroy `LObject`.

Source-quality implications:

- The source destructor should be an ordinary virtual destructor body:

  ```cpp
  DirectX::~DirectX()
  {
      m_pDirectDraw->Release();
      m_pDirectDraw = NULL;
      g_pDirectX = NULL;
  }
  ```

- There is no binary null check before `Release`. The old generated draft's `if (this->m_directDraw != nullptr)` should not be carried forward as authoritative source.
- The vtable reset and base destructor call are compiler-generated destructor mechanics.

### Constructor-Unwind Helper `0x004a1cc0-0x004a1ccb`

This helper only clears `g_pDirectX` and returns. It is referenced from the far EH cleanup chunk associated with the constructor.

Source-quality implication: do not emit a source function for this helper. It is generated from the constructor's `g_pDirectX = this` side effect combined with later throwing calls. The correct source expression is to keep `g_pDirectX = this` before `DirectDrawCreate`/`QueryInterface`; the compiler regenerates the cleanup helper as needed.

### Scalar Deleting Destructor `0x004a1cd0-0x004a1d6a`

This function repeats the ordinary DirectX teardown and conditionally calls the project's delete routine depending on deletion flags. It occupies the first virtual slot in the DirectX vtable.

Source-quality implication: do not emit `DirectX::ScalarDeletingDestructor(...)` as handwritten source. MSVC emits this wrapper from a virtual destructor declaration. The source-level declaration should be `virtual ~DirectX();`, with only the ordinary destructor body authored.

### Alignment And Far EH Chunks

The alignment gaps in this memory item are padding between generated functions and before the next class cluster. The far EH chunks, including the previously documented constructor unwind xref, are compiler support code. Neither should receive separate source ownership or handwritten C++.

## Heuristic / Inference Reanalysis And Validation

### COM Interface Lifetime

The constructor creates a DirectDraw interface through `DirectDrawCreate`, then obtains/stores an interface pointer through `QueryInterface`. The stored field at `this+4` is the only persistent DirectDraw state in the class. The ordinary destructor calls vtable slot `+8` on that stored interface and clears the field.

The COM release slot identity is high-confidence: in `IUnknown`, slot `+0` is `QueryInterface`, `+4` is `AddRef`, and `+8` is `Release`; the destructor uses `+8`. The constructor's second COM call uses slot `+0` and takes an IID plus output pointer, matching `QueryInterface`.

The reconstruction should intentionally preserve the observed lifetime shape. A more idiomatic source might release the original `lpDD` after successful `QueryInterface`, and might clean it up on the failure path. The binary does not show those releases in this function. Therefore, adding them would change source fidelity. The safest first draft keeps `lpDD` local and stores the queried interface in `m_pDirectDraw`, without extra releases.

### `DirectDrawCreate` Failure Path

Both decompilers agree that `DirectDrawCreate(NULL, &lpDD, NULL) < 0` takes the first throw path. The path allocates 8 bytes with `sub_4F4AA0`, calls the MyError constructor at `0x004a67a0` using the DirectX diagnostic string, then throws with `_CxxThrowException`.

The throw metadata is decisive: `_TI4PAVMyError__` is pointer-to-`MyError` throw info. This is not a by-value `MyError` throw. Source should use `throw new MyError(...)` unless a local project macro/wrapper is later proven, but the available Error/MyError docs support direct heap pointer throwing elsewhere.

### `QueryInterface` Failure Path

The second failure path mirrors the first failure path: allocate 8 bytes, construct `MyError`, throw pointer. It uses the same diagnostic string. There is no distinct message for `QueryInterface` failure and no observed local cleanup before throwing.

Because both failure paths collapse to the same allocation/construction/throw labels in the IDA decompile, the source should repeat the same `throw new MyError(...)` statement for both checks rather than inventing an extracted helper unless such a helper is present elsewhere in the source model. No helper is indicated by the binary.

### Stored Interface GUID Identity

The 16 bytes at `0x00631570` are:

```text
6c14db80-a733-11ce-a521-0020af0be560
```

The GUID-specific doc identifies this as SDK `IID_IDirectDraw`. It has a single xref from the DirectX constructor's `QueryInterface` call. The broader `0x00631570-0x00632560` mixed-data page documents that this address was previously grouped with Browser COM GUIDs by range, but the first 16-byte item is actually the DirectDraw IID.

Source-quality conclusion: this should be spelled as SDK `IID_IDirectDraw` from DirectDraw headers/import libraries. Do not create a local NexusTK `GUID`, `kDirectDrawInterfaceId`, or Browser-owned GUID symbol for this constant.

### `this+4` Field Naming

The class doc currently identifies offset `+4` as `IDirectDraw *m_directDraw`. The binary evidence supports the type:

- constructor zeroes `this+4`;
- `QueryInterface` writes through `(LPVOID *)(this+4)`;
- destructor calls `Release` through the interface pointer;
- render/surface consumers access DirectDraw behavior through the `g_pDirectX` singleton and its stored interface.

Original source spelling is not recoverable from the binary alone. For first-draft source, `m_pDirectDraw` is the strongest project-style name because:

- the field is a pointer;
- the global singleton uses `g_pDirectX`;
- the Windows/DirectDraw local type naturally spells as `LPDIRECTDRAW`;
- `m_p...` names are common in generated/simroot class-member pointer conventions.

`m_directDraw` remains semantically acceptable, but `m_pDirectDraw` is the better source-quality draft name. Avoid names such as `m_device`, `m_ddraw`, or `m_lpDD` unless stronger original-source evidence appears.

### `g_pDirectX` Singleton Ownership And Users

`g_pDirectX` is the process-wide DirectX singleton pointer at `0x0067ab20`. Its own memory/global docs give it source ownership through the DirectX file/global path, and its memory child is not part of this function range.

The constructor stores the singleton before the DirectDraw calls. The ordinary destructor and scalar deleting destructor clear it. The constructor-unwind helper also clears it when construction fails after the singleton assignment. This establishes ownership/lifetime in DirectX.cpp.

Known users in render/surface code are consumers, not competing owners. GrafPort/Surface documentation correctly treats DirectX as a dependency/provider while keeping surface creation/presentation ownership in their own files/classes.

### Constructor-Unwind Helper Source Shape

The helper exists because `g_pDirectX = this` happens before potentially throwing DirectDraw calls. Since construction can fail, compiler EH cleanup must undo the singleton assignment. The helper's body only clears the global, matching exactly that source-level obligation.

High-probability source inference:

```cpp
DirectX::DirectX()
{
    g_pDirectX = this;
    ...
    if (DirectDrawCreate(...) < 0) {
        throw new MyError(...);
    }
    if (lpDD->QueryInterface(...) < 0) {
        throw new MyError(...);
    }
}
```

No named cleanup function should be authored. The helper is compiler glue.

### Scalar Deleting Destructor Versus Ordinary Destructor

The target currently includes both `0x004a1c60` and `0x004a1cd0`, but only the ordinary destructor is a source-authored body. The scalar deleting destructor appears in vtable slot 0 at `0x00618e64` and contains conditional delete behavior based on flags. That is the expected MSVC wrapper for virtual destruction.

Final C++ should therefore include:

```cpp
virtual ~DirectX();
```

and one destructor definition. The vtable data and wrapper should be regenerated by the compiler or documented as binary artifacts, not emitted as manual C++ methods.

### Far EH Chunks

The far EH references are consistent with MSVC exception cleanup. They do not introduce extra DirectX source functions. Their existence improves confidence in the constructor-unwind interpretation but should not change source placement or ownership.

### Source Placement

`by-project-structure/proposed-source-tree.md`, `by-file/DirectX.md`, and the generated route all place this material in:

```text
NexusTK/render/DirectX.cpp
```

This remains correct. The DirectX file owns the DirectDraw bootstrap wrapper, the singleton declaration/definition, and the class method definitions. Do not move this material into GrafPort, Surface, Application, Browser, or Error source files.

### Owner / Emitter Route

The current target routes directly to file UID `0000IW`. Under the structure rules, class methods and class-generated artifacts should be directly owned by the class page when a class page exists and clears the gate. `by-class/DirectX.md` exists, scores `85/88`, and emits through `by-file/DirectX.md`.

Recommended route:

```text
CANONICAL_OWNER:00003Y
EMITTER_UIDS:00003Y
```

The final output path remains `NexusTK/render/DirectX.cpp` through the existing class-to-file route. This keeps semantic ownership precise without changing source placement.

## Proposed First-Draft C++

This is the source-authored body that should be eligible for the target/class/file route. It intentionally excludes compiler glue.

```cpp
DirectX::DirectX()
{
    g_pDirectX = this;
    m_pDirectDraw = NULL;

    LPDIRECTDRAW lpDD = NULL;
    if (DirectDrawCreate(NULL, &lpDD, NULL) < 0) {
        throw new MyError(L"DirectX not installed, or is corrupted. Please install DirectX again.");
    }

    if (lpDD->QueryInterface(IID_IDirectDraw, (LPVOID *)&m_pDirectDraw) < 0) {
        throw new MyError(L"DirectX not installed, or is corrupted. Please install DirectX again.");
    }
}

DirectX::~DirectX()
{
    m_pDirectDraw->Release();
    m_pDirectDraw = NULL;
    g_pDirectX = NULL;
}
```

Supporting declaration shape, for the class/header owner rather than this function-range page:

```cpp
class DirectX : public LObject {
public:
    DirectX();
    virtual ~DirectX();

private:
    LPDIRECTDRAW m_pDirectDraw;
};

extern DirectX *g_pDirectX;
```

Notes:

- Use project-era `NULL`/Win32 DirectDraw spelling rather than `nullptr`/`std::uint8_t`.
- Do not include explicit vtable assignment, `LObject` constructor/destructor calls, scalar deleting destructor, or constructor EH helper.
- Do not define `IID_IDirectDraw` locally in NexusTK source.
- Do not add an `if (m_pDirectDraw != NULL)` guard unless new evidence proves it existed in the original source.

## Support Changes Needed

### Target Documentation

Recommended edits to `by-memory/0x004a1b60-0x004a1d6a.DirectX.md`:

- change score to `COMPLETION:88`, `CONFIDENCE:91`;
- change direct owner/emitter to `00003Y`;
- add the first-draft C++ constructor/destructor block above;
- state explicitly that `0x004a1cc0` and `0x004a1cd0` are compiler-generated support for source constructor/destructor semantics;
- replace any `kDirectDrawInterfaceId` wording with SDK `IID_IDirectDraw`;
- describe `this+4` as `LPDIRECTDRAW m_pDirectDraw` or equivalent stored DirectDraw interface pointer;
- note that the destructor's `Release` is unconditional in observed binary.

### Class Documentation

Recommended edits to `by-class/DirectX.md`:

- consider renaming the field from `m_directDraw` to `m_pDirectDraw` in draft source notes;
- retain the field's semantic type as `IDirectDraw *` / `LPDIRECTDRAW`;
- clarify that scalar deleting destructor and unwind helper are binary/compiler artifacts emitted from class construction/destruction.

### File Documentation

Recommended edits to `by-file/DirectX.md`:

- replace unresolved `kDirectDrawInterfaceId` with SDK `IID_IDirectDraw`;
- record pointer-thrown `MyError` source spelling for both failure paths;
- keep source placement in `NexusTK/render/DirectX.cpp`.

### Generated Draft

`simroot_v2/class_DirectX.cpp` should not be treated as authority. If regenerated or manually reconciled later, it should change:

- `throw MyError(...)` -> `throw new MyError(...)`;
- `kDirectDrawInterfaceId` -> `IID_IDirectDraw`;
- `m_directDraw` -> preferably `m_pDirectDraw`;
- remove the destructor null check unless a source-style guard is independently proven;
- remove the handwritten scalar deleting destructor from source-level output.

## Coverage Report Replacement Row

Do not edit `by-memory/-coverage-report.md` directly. If the supervisor accepts the score/source-quality update, replace the existing UID `000137` row with:

```text
    - [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md) : reconstructable : 88% : very-strong : DirectX class-owned DirectDraw bootstrap cluster; source-quality reanalysis resolves `0x00631570` as SDK `IID_IDirectDraw`, names `this+4` as the stored `IDirectDraw`/`LPDIRECTDRAW m_pDirectDraw` interface field, keeps source placement in `NexusTK/render/DirectX.cpp`, recommends direct owner/emitter routing through [UID:00003Y][DirectX](by-class/DirectX.md) to [UID:0000IW][DirectX](by-file/DirectX.md), distinguishes source-authored constructor/destructor bodies from compiler-generated constructor-unwind singleton clear helper, scalar deleting destructor, far EH chunks, and alignment padding, and marks first-draft constructor/destructor C++ ready while excluding compiler glue from handwritten source.
```

## Open Questions Closed

- GUID identity: closed as SDK `IID_IDirectDraw`.
- `this+4` role: closed as stored DirectDraw interface pointer; recommended source name `m_pDirectDraw`.
- Failure path spelling: closed as pointer-thrown `MyError`, not by-value `MyError`.
- Destructor null guard: closed against the guard; binary releases unconditionally.
- `g_pDirectX` role: closed as DirectX-owned singleton declaration/lifetime, with render/surface consumers only.
- Constructor-unwind helper: closed as compiler EH cleanup, not source-authored function.
- Scalar deleting destructor: closed as compiler wrapper from virtual destructor, not source-authored function.
- Far EH chunks: closed as compiler support, not new source owners.
- Source placement: closed as `NexusTK/render/DirectX.cpp`.

Residual uncertainty:

- Exact original member spelling is not provable from the binary. `m_pDirectDraw` is a high-probability reconstruction name, while `m_directDraw` remains semantically correct.
- Live IDA MCP was unavailable during this report; confidence remains below the highest tier because this pass could not perform new interactive disassembly checks beyond the existing IDA-backed exports/docs.

## Final Score Justification

Recommended `88/91`:

- Completion rises from `84` to `88` because the source-level shape, GUID identity, field role/name, exception spelling, compiler-glue exclusion, owner route, and C++ readiness are now resolved.
- Confidence rises from `90` to `91` because the decisive facts are supported by multiple local docs and exports: GUID bytes, constructor/deconstructor decompilation, vtable data, singleton xrefs, and MyError type/layout docs.
- Confidence should not rise above the low 90s until live IDA can be rechecked or a broader compile-pass validates the exact include/declaration context.

## Validation Status

No project validator was run because this assignment produced a research report only and did not edit project reconstruction docs or generated C++.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/000137-DirectX-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"000137"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
