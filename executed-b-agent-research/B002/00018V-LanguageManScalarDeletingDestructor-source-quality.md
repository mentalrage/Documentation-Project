** TARGET-REPORT-UID:00018V **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B002 Source-Quality Report: [UID:00018V] LanguageManScalarDeletingDestructor

Target: `source-3/project-documentation/by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/00018V-LanguageManScalarDeletingDestructor-source-quality.md`  
Report scope: B-agent source-quality / heuristic research only. No target/support by-* docs, generated files, prior reports, or `by-memory/-coverage-report.md` were edited.

## Finalized Report / Current Recommendation

Current recommendation: treat UID `00018V` as a class-owned MSVC scalar deleting destructor wrapper for `LanguageMan::~LanguageMan()`, not as a source-authored method body named `LanguageMan::DeletingDestructor`.

Final disposition:

- Keep `RECONSTRUCTABLE: TRUE` because the class declaration/destructor must regenerate equivalent vtable/destructor semantics.
- Change direct owner/emitter from file UID `0000KK` to class UID `000071`.
- Keep source placement through `NexusTK/localization/LanguageMan.cpp`.
- Do not handwrite a formal wrapper body in target C++.
- If the supervisor wants a non-empty formal block for a code-emitting no-code item, use a one-line comment marker only:

```cpp
// Compiler-generated scalar deleting destructor for LanguageMan::~LanguageMan(); no handwritten source body.
```

Recommended target metadata:

```yaml
COMPLETION: 87
CONFIDENCE: 92
CANONICAL_OWNER: 000071
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 000071
```

Implementation readiness: ready for a no-code compiler-wrapper implementation update. The real source destructor body belongs in companion UID `00018S` `LanguageManCleanupDestructor` if the supervisor includes support C++ in the implementation callback.

## Supervisor Active Recheck

Active user assignment:

- New B-preferred report-only task for [UID:00018V] `LanguageManScalarDeletingDestructor`.
- Preserve prior `00015O` report in place.
- Do not edit target/support by-* docs unless supervisor sends a later implementation callback.
- Do not edit `by-memory/-coverage-report.md`; include exact replacement row text in this report only.
- Required focus: ABI scalar/deleting-destructor shape, helper names/signatures, `LanguageManCleanupDestructor`, `LanguageManLookupAndSingletonHelpers`, `g_pLanguageMan`, class/file docs, vtable ownership, allocator/free helpers, source placement, flag semantics, `(flags & 4)` path, singleton/string-table fields, base destructor call, score gate, support docs, exact coverage row, and implementation readiness.

Split decision:

- No new split is required. The target is one complete IDA-modeled function, `0x004f03d0-0x004f0477`, followed by `0x004f0477-0x004f0480` padding.
- The correct repair is source-quality/routing/no-code clarification, not child creation.

## Evidence Checked

Process and guidance:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B002/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`

Target and direct support docs:

- `by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md`
- `by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md`
- `by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md`
- `by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md`
- `by-memory/0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md`
- `by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md`
- `by-global/g_pLanguageMan.md`
- `by-class/LanguageMan.md`
- `by-class/LanguageManager.md`
- `by-file/LanguageMan.md`
- `by-resource/str-res-localized-strings.md`

Vtable/read-only-data and runtime/helper docs:

- `by-memory/0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData.md`
- `by-memory/0x0061c9c4-0x0061c9dc.KeySpeedMgrVtableData.md`
- `by-type/by-vtable/KeySpeedMgrVtable.md`
- `by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md`
- `by-memory/0x004f4b90-0x004f4c0d.LObjectScalarDeletingDestructor.md`
- `by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md`
- `by-memory/0x00516030-0x00516036.GetMemoryMan.md`
- `by-memory/0x00516170-0x00516184.FreeBufferMemory.md`
- `by-memory/-ignored.md` for `0x0041b6a0-0x0041b6a1` `@_guard_check_icall_nop@4`.

Comparable scalar-deleting-destructor docs checked:

- `by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md`
- `by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md`
- `by-memory/0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor.md`
- `by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md`

Generated and queue state:

- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/-ag-file-coverage.md`
- `auto-generated/NexusTK/localization/LanguageMan.cpp`
- `source-3/simroot_v2/class_LanguageMan.cpp`
- `source-3/simroot_v2/class_LanguageManager.cpp`
- `project-level/-auto-completion-stats.md`
- `project-level/-resolved.md`
- `project-level/-unresolved.md`
- `wave3_data_issues.md`
- `by-meta/client_localization.md`

Prior B-agent research:

- Searched Agent-B001/B002/B003 research folders for `00018V`, `LanguageManScalarDeletingDestructor`, and `0x004f03d0`.
- Found one related prior executed B001 report for UID `00018T` zero-initializer; it mentions `00018V` only as neighboring LanguageMan vtable destructor evidence. No prior B-agent report for `00018V` itself was found.

Live IDA MCP status:

- Attempted JSON-RPC `tools/list` at `http://127.0.0.1:13337/mcp`.
- Result: unable to connect to the remote server.
- This report therefore uses existing recent live-IDA documentation plus a fresh raw PE/Capstone read from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

Raw PE / Capstone evidence generated in this pass:

- Parsed PE image base `0x00400000`.
- `.text` section covers `0x00401000-0x0060c4ac`.
- Raw target offset for `0x004f03d0` is `0x000ef7d0`.
- Capstone disassembled `0x004f03d0-0x004f0477` directly from the read-only executable.
- Raw little-endian target VA scan found `0x004f03d0` exactly once, at `.rdata:0x0061c9e0`.
- Raw `.text` rel32 scan found no direct call/jump to `0x004f03d0`.
- Raw dword scan found `0x0061c9e0` references at the constructor, cleanup destructor, and scalar deleting destructor vtable stores.

Conversions verified with `int_convert.py`:

- `0xa7` = 167 bytes (Verified with `int_convert.py`).
- `0x80` = 128 bytes (Verified with `int_convert.py`).
- `0x2c` = 44 bytes (Verified with `int_convert.py`).
- `0x09` = 9 bytes (Verified with `int_convert.py`).
- `0x04` = 4 bytes (Verified with `int_convert.py`).
- `0x08` = 8 bytes (Verified with `int_convert.py`).

## ABI Shape / Raw Function Facts

Target range:

- Start: `0x004f03d0`
- End-exclusive: `0x004f0477`
- Size: `0xa7` / 167 bytes (Verified with `int_convert.py`)
- Successor padding: `0x004f0477-0x004f0480`, `0x09` / 9 bytes (Verified with `int_convert.py`), all `0xcc`.

Binary signature:

```text
LanguageMan* __thiscall scalar_deleting_destructor(LanguageMan* this, unsigned int flags)
```

This is a compiler ABI wrapper. It returns `this`, accepts the MSVC deleting-destructor flags in `[ebp+8]`, and contains SEH/security-cookie scaffolding around the same cleanup body as UID `00018S`.

Capstone branch summary:

```asm
004f03fe  mov     dword ptr [esi], 0x61c9e0
004f0404  call    0x516030
004f0412  mov     eax, dword ptr [esi + 4]
004f0417  push    dword ptr [eax + edi*4]
004f041a  call    0x516170
004f0425  push    dword ptr [esi + 4]
004f042a  call    0x516170
004f0431  mov     dword ptr [0x67a750], 0
004f043b  call    0x4f4a90
004f0440  mov     eax, dword ptr [ebp + 8]
004f0443  test    al, 1
004f0445  je      0x4f0461
004f0447  test    al, 4
004f0449  jne     0x4f0456
004f044b  push    esi
004f044c  call    0x4f4ac0
004f0456  push    0x2c
004f0458  push    esi
004f0459  call    0x41b6a0
004f0461  mov     eax, esi
004f0474  ret     4
```

Flag semantics:

- `flags & 1` clear: cleanup destructor semantics run, but object storage is not freed.
- `flags & 1` set and `flags & 4` clear: calls [UID:000197] `OperatorDeleteWrapper` at `0x004f4ac0`.
- `flags & 1` set and `flags & 4` set: pushes `this` and object size `0x2c` / 44 bytes (Verified with `int_convert.py`) to `0x0041b6a0`.
- `0x0041b6a0` is documented in `by-memory/-ignored.md` as MSVC `@_guard_check_icall_nop@4`, a one-byte `retn` helper. It is not LanguageMan source behavior.

The `flags & 4` path matches the project-wide scalar/vector-delete guarded-size path seen in `MenuItem`, `FittingRoomListPane`, `AlertPane`, `ThreadMan`, `StdioFile`, and many other destructor wrappers. It should be documented as compiler/runtime wrapper behavior, not as a second LanguageMan storage-free path.

## Reconciliation With LanguageManCleanupDestructor

UID `00018S` and UID `00018V` contain the same source-authored object cleanup:

- reset the LanguageMan vtable to `0x0061c9e0`;
- call `GetMemoryMan`;
- loop over `m_strings[i]` at `this + 0x4` using `m_stringCount` at `this + 0x8`;
- free each localized string through `FreeBufferMemory`;
- free the string pointer table itself;
- clear `g_pLanguageMan` at `0x0067a750`;
- run `LObject` base cleanup at `0x004f4a90`.

The difference is ABI, not source intent:

- UID `00018S` is the ordinary non-deleting cleanup destructor body.
- UID `00018V` is the scalar deleting destructor wrapper that duplicates cleanup and adds delete-flag branches.

Source-facing conclusion:

- The source-authored C++ destructor belongs on UID `00018S`.
- UID `00018V` should not emit a second hand-written destructor wrapper body.
- The class declaration `virtual ~LanguageMan();` and the ordinary destructor implementation should make MSVC regenerate the vtable slot wrapper.

Recommended first-draft source body for UID `00018S`, if the supervisor includes that support page in an implementation callback:

```cpp
LanguageMan::~LanguageMan()
{
    MemoryMan* memoryMan = GetMemoryMan();

    for (int i = 0; i < m_stringCount; ++i)
        memoryMan->FreeBufferMemory(m_strings[i]);

    memoryMan->FreeBufferMemory(m_strings);
    g_pLanguageMan = 0;
}
```

Notes for the `00018S` draft:

- The base `LObject` destructor call is implicit source behavior and should not be written manually.
- If the final MemoryMan API uses a project wrapper name such as `ReleaseHeapBlock`, use that helper name instead of exposing `FreeBufferMemory`.
- This destructor body should not be inserted into UID `00018V`.

## Helper Name / Signature Resolution

The target page currently leaves several `sub_` helpers provisional. The best source-facing names/signatures are now strong enough to document:

| Raw item | Recommended source-facing name | Evidence and confidence |
| --- | --- | --- |
| `0x00516030` / `sub_516030` | `GetMemoryMan()` returning the MemoryMan singleton | [UID:0001BC] documents exact 6-byte return of `g_pMemoryMan`; target calls once and reuses the returned object in `ebx`. |
| `0x00516170` / `sub_516170` | `MemoryMan::FreeBufferMemory(void* block)` or file-level `FreeBufferMemory` | [UID:0001BF] documents `free(block); return 0`; target calls it for each string and for the pointer table. |
| `0x004f4ac0` / `sub_4F4AC0` | `OperatorDeleteWrapper` / MemoryMan-backed global `operator delete` | [UID:000197] documents `GetMemoryMan` followed by `FreeBufferMemory`; target calls it only on ordinary scalar-delete path. |
| `0x004f4a90` / `sub_4F4A90` | `LObject::~LObject` non-deleting destructor body | [UID:000370] documents vtable restore for the base object. |
| `0x0041b6a0` | `@_guard_check_icall_nop@4`, compiler no-op guard helper | `by-memory/-ignored.md` documents one-byte `retn`; target flag-4 branch pushes size `0x2c` and `this` before this call. |
| `0x0061c9e0` | `LanguageMan` primary vtable base | Raw dword scan: only vtable pointer to `0x004f03d0`; constructor/cleanup/scalar wrapper write it. |
| `0x0067a750` | `g_pLanguageMan` | [UID:0000RC] and [UID:0001OS] document singleton storage, 192 xrefs, constructor set, destructor clears. |

Source-facing ABI pseudocode, not formal C++:

```cpp
// Descriptive only. Do not emit this as source.
LanguageMan* LanguageMan_scalar_deleting_destructor(LanguageMan* self, unsigned int flags)
{
    self->~LanguageMan();

    if ((flags & 1) != 0) {
        if ((flags & 4) != 0)
            compiler_guarded_sized_delete_path(self, 0x2c);
        else
            operator delete(self);
    }

    return self;
}
```

## Singleton And Field/Layout Findings

Confirmed `LanguageMan` object fields from constructor, lookup, cleanup, and scalar wrapper:

| Offset | Field direction | Evidence |
| --- | --- | --- |
| `+0x00` | `LObject` base / vtable | Constructor and both destructor paths write `0x0061c9e0`. |
| `+0x04` | `wchar_t** m_strings` | Constructor stores final table; lookup reads it; both destructors free entries and table. |
| `+0x08` | `int m_stringCount` | Constructor initializes/increments; lookup checks bounds; destructors use as free loop bound. |

New layout implication from this pass:

- The scalar deleting destructor flag-4 branch pushes object size `0x2c` / 44 bytes (Verified with `int_convert.py`).
- That is strong evidence that the complete `LanguageMan` object is 44 bytes in this build.
- The adjacent zero-initializer UID `00018T` writes zeros to `+0x0c` through `+0x24`, which lies inside this `0x2c` object-size envelope.

However, this does not safely promote UID `00018T` to a `LanguageMan` class method:

- Prior B001/A010 evidence found no callers, no vtable slot, no EH metadata, no pointer bytes, and no direct references for `0x004f0310`.
- The constructor range checked here visibly initializes the proven localization fields `+0x04` and `+0x08`; it does not call `0x004f0310`.
- Best current direction: update class/file docs with a provisional `sizeof(LanguageMan) == 0x2c` inference from the deleting wrapper, while keeping only `+0x04` and `+0x08` as behavior-proven fields and keeping `00018T` as a file-level orphan/private helper until a real call/layout route is found.

`g_pLanguageMan` pointer clarification:

- Constructor instructions at `0x004f0055-0x004f0066` use `lea eax, [ebx+4]`, null-test, then `add eax, -4` before storing to `0x0067a750`.
- That collapses to storing the complete object pointer `ebx` when non-null, not a permanent `this + 4` view pointer.
- The lookup helpers receive this complete object pointer and read `+0x04` and `+0x08`.

## Vtable Ownership

Raw `.rdata` dwords confirm:

| Address | Value | Meaning |
| --- | --- | --- |
| `0x0061c9dc` | `0x006498c0` | `LanguageMan` complete-object locator pointer |
| `0x0061c9e0` | `0x004f03d0` | primary vtable slot 0, scalar deleting destructor wrapper |
| `0x0061c9e4` | `0x004f4b10` | inherited `LObject` runtime-class accessor |
| `0x0061c9e8` | `0x0041b6c0` | inherited/default `LObject` no-op virtual |
| `0x0061c9ec` | UTF-16 `str.res` | first LanguageMan resource string after vtable island |

Reachability facts:

- Raw dword scan found `0x004f03d0` only at `0x0061c9e0`.
- Raw `.text` rel32 scan found zero direct call/jump targets to `0x004f03d0`.
- Existing docs also report no direct code callers.

Ownership conclusion:

- Direct semantic owner should be [UID:000071] `LanguageMan`, not file UID `0000KK`.
- Emitter should also be [UID:000071], because the class already routes to file [UID:0000KK] `LanguageMan.cpp`.
- This matches UID `00018S`, which was already rerouted to the class parent after the strict gate cleared.

## Source Placement

Keep final source placement:

```text
NexusTK/localization/LanguageMan.cpp
```

Evidence:

- [UID:0000KK] `LanguageMan` by-file page owns `str.res` loading, `LanguageMan`, `g_pLanguageMan`, lookup helpers, and destructor lifecycle.
- Proposed source tree places `LanguageMan.cpp` under `NexusTK/localization/`.
- Generated reports route [UID:000071] and [UID:0000KK] to `auto-generated/NexusTK/localization/LanguageMan.cpp`.
- The current generated file has an empty marker for UID `00018V`, proving the route is valid but content is missing.

Rejected alternatives:

- `LanguageManager`: rejected as a generated alias/view. [UID:000072] is ignored as a standalone class; no `LanguageManager` RTTI/name evidence exists.
- `MemoryMan`: rejected as direct owner. MemoryMan owns allocation/free helpers, not LanguageMan destructor semantics.
- `LObject`: rejected as direct owner. `LObject` is the base cleanup callee and inherited vtable slots, not the derived destructor wrapper owner.
- `by-file/LanguageMan` direct ownership: weaker than class ownership because this is a vtable slot for the `LanguageMan` class.

## Heuristic / Inference Reanalysis And Validation

Issue: target has blank C++ despite active code gate.

- Evidence checked: by-structure active code gate, current target metadata `84/90`, generated output marker, comparable scalar-deleting-destructor docs.
- Best direction: do not insert handwritten wrapper source. Use target no-code proof and optional comment marker because this exact range is compiler-generated deleting-destructor glue.
- Impact: target can rise above gate with no-code marker; ordinary source destructor should be emitted on UID `00018S` if accepted.

Issue: current owner/emitter is file UID `0000KK`.

- Evidence checked: vtable slot at `0x0061c9e0`, raw pointer scan, class page, cleanup destructor routing, generated class route.
- Best direction: reroute `CANONICAL_OWNER` and `EMITTER_UIDS` to [UID:000071] `LanguageMan`.
- Rejected: keeping file direct owner. The file is the source root, but by-structure says class method/vtable-owned destructor wrappers belong to the narrowest class owner.

Issue: helper names are raw `sub_` labels.

- Evidence checked: MemoryMan helper docs, LObject docs, ignored CFG helper entry, raw disassembly.
- Best direction: use `GetMemoryMan`, `FreeBufferMemory`, `OperatorDeleteWrapper`, `LObject::~LObject`, and `@_guard_check_icall_nop@4`/compiler guard no-op.
- Impact: no remaining helper-name blocker for this target.

Issue: `(flags & 4)` path meaning.

- Evidence checked: raw target disassembly, `MenuItem`, `FittingRoomListPane`, `AlertPane`, `LObject`, `ThreadMan`, `StdioFile`, and `by-memory/-ignored.md` guard helper evidence.
- Best direction: bit `0x4` is the project-wide MSVC guarded/vector/sized-delete alternate path. In this target it pushes object size `0x2c` / 44 bytes (Verified with `int_convert.py`) and does not call the normal delete wrapper.
- Impact: source C++ should not model it as custom LanguageMan logic.

Issue: singleton/string-table fields and object size.

- Evidence checked: constructor instructions, lookup helper instructions, cleanup/scalar destructor instructions, zero-initializer docs, raw flag-4 size immediate.
- Best direction: document proven fields `m_strings` at `+0x04` and `m_stringCount` at `+0x08`; add a provisional complete-object size `0x2c` / 44 bytes from the deleting wrapper; do not assign names to `+0x0c..+0x28` from this target alone.
- Impact: improves class layout documentation but keeps `00018T` class ownership open.

Issue: base destructor call.

- Evidence checked: target and `00018S` call `0x004f4a90`; [UID:000370] documents `LObjectDestructorBody`.
- Best direction: docs should say the binary calls `LObject::~LObject`; source C++ for ordinary destructor should not hand-call the base destructor.
- Impact: no C++ blocker; avoids decompiler-shaped output.

Issue: `LanguageMan` versus `LanguageManager`.

- Evidence checked: by-class alias page, by-file notes, lookup helper docs, RTTI/name evidence in docs, generated `class_LanguageManager.cpp`.
- Best direction: use `LanguageMan` as canonical class. Preserve `LanguageManager` only as alias/history.
- Impact: no blocker for this target.

Issue: reconstructable versus not reconstructable.

- Evidence checked: current project has mixed policy for scalar wrapper pages, but recent no-code-proof pages keep reconstructable true when the class source must regenerate equivalent vtable/destructor semantics.
- Best direction: keep `RECONSTRUCTABLE: TRUE`, but document rebuild handling as `source-declared/generated-binary compiler wrapper`.
- Impact: generated route remains visible; formal C++ should be comment-only/no-code.

## First-Draft C++ / No-Code Proof

Do not populate UID `00018V` with a handwritten wrapper body.

Exact no-code proof:

- The only pointer to `0x004f03d0` is the `LanguageMan` vtable slot at `0x0061c9e0`.
- There are no direct `.text` rel32 calls/jumps to `0x004f03d0`.
- The body duplicates UID `00018S` cleanup and adds only MSVC deleting-destructor machinery:
  - flag byte tests;
  - optional call to global delete wrapper;
  - guarded/sized flag-4 branch to one-byte `@_guard_check_icall_nop@4`;
  - `ret 4` ABI wrapper return;
  - SEH/security-cookie scaffolding.
- Handwritten C++ would expose vtable addresses, compiler flags, guard no-op calls, and MemoryMan delete routing as if they were original LanguageMan source. That would be less source-faithful than an ordinary virtual destructor.

Recommended formal block for UID `00018V`:

```cpp
// Compiler-generated scalar deleting destructor for LanguageMan::~LanguageMan(); no handwritten source body.
```

If the validator/autogen policy allows truly blank no-code compiler-wrapper blocks, blank is also acceptable, but the target page must contain the no-code proof above. Do not emit:

```cpp
LanguageMan* LanguageMan::DeletingDestructor(unsigned int flags) { ... }
```

That shape exists in old `simroot_v2/class_LanguageMan.cpp`, but it is a generated reverse-engineering artifact, not the best final source.

## Recommended Exact Target Changes

For `by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md`:

1. Change metadata:

```yaml
COMPLETION: 87
CONFIDENCE: 92
CANONICAL_OWNER: 000071
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 000071
```

2. Replace stale source-gate wording with:

```text
2026-06-19 B002 source-quality pass: this target clears the active routing/code gate, but formal source for this exact range must remain a no-code compiler-wrapper marker. The source-authored destructor body is UID 00018S; this range is the MSVC scalar deleting destructor wrapper generated for LanguageMan::~LanguageMan().
```

3. Add raw ABI facts:

```text
Raw PE/Capstone recheck from E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe confirms 0x004f03d0-0x004f0477 is 0xa7 / 167 bytes (Verified with int_convert.py). The wrapper restores vtable 0x0061c9e0, frees m_strings entries and the m_strings table through GetMemoryMan/FreeBufferMemory, clears g_pLanguageMan, calls LObject::~LObject, then checks MSVC delete flags. It calls OperatorDeleteWrapper only when (flags & 1) != 0 and (flags & 4) == 0. When flags & 4 is set, it pushes object size 0x2c / 44 bytes (Verified with int_convert.py) and this to @_guard_check_icall_nop@4; that is compiler/runtime guarded-size delete glue, not LanguageMan source logic.
```

4. Add vtable-only reachability proof:

```text
Raw pointer/call scan found the target VA 0x004f03d0 only at .rdata:0x0061c9e0, the LanguageMan primary vtable slot, and found no direct .text rel32 call/jump targets to 0x004f03d0. The wrapper is vtable/ABI-owned.
```

5. Add helper mapping:

```text
Helper names: 0x00516030 is GetMemoryMan, 0x00516170 is FreeBufferMemory, 0x004f4ac0 is the MemoryMan-backed OperatorDeleteWrapper/global operator delete path, 0x004f4a90 is LObject::~LObject non-deleting cleanup, and 0x0041b6a0 is the ignored MSVC @_guard_check_icall_nop@4 one-byte no-op.
```

6. Add source/no-code policy:

```text
Do not handwrite LanguageMan::DeletingDestructor in final source. The correct source representation is an ordinary virtual LanguageMan destructor on UID 00018S / the class declaration; this UID may emit only a no-code marker comment if the generated source system requires nonblank output for emitting wrapper pages.
```

7. Formal C++ block recommendation:

```cpp
// Compiler-generated scalar deleting destructor for LanguageMan::~LanguageMan(); no handwritten source body.
```

## Recommended Support Changes

For [UID:00018S] `LanguageManCleanupDestructor`:

- Remove stale `95% reconstruction-code gate` wording.
- Mark it as the source-authored destructor body that should receive first-draft C++ if accepted.
- Add cross-note that UID `00018V` is the generated scalar deleting wrapper and must not duplicate the destructor body.
- Consider metadata `COMPLETION: 87`, `CONFIDENCE: 91` after adding first-draft destructor C++.

Suggested `00018S` formal source direction:

```cpp
LanguageMan::~LanguageMan()
{
    MemoryMan* memoryMan = GetMemoryMan();

    for (int i = 0; i < m_stringCount; ++i)
        memoryMan->FreeBufferMemory(m_strings[i]);

    memoryMan->FreeBufferMemory(m_strings);
    g_pLanguageMan = 0;
}
```

For [UID:000071] `LanguageMan` class:

- Add `sizeof(LanguageMan) == 0x2c` / 44 bytes (Verified with `int_convert.py`) as a provisional complete-object size inferred from UID `00018V` flag-4 branch.
- Keep proven fields:
  - `+0x00` `LObject` base/vtable.
  - `+0x04` `wchar_t** m_strings`.
  - `+0x08` `int m_stringCount`.
- Add a caveat that `+0x0c..+0x28` remain unnamed/unproven even though `00018T` zeros part of this tail region.
- Update scalar deleting destructor method note to "compiler-generated wrapper for `~LanguageMan`; no handwritten source body".
- Recommended class score after support update: `COMPLETION: 87`, `CONFIDENCE: 89`.

For [UID:0000KK] `LanguageMan` file:

- Add that UID `00018V` should route through class [UID:000071] to `LanguageMan.cpp`, not directly through the file page.
- Add that `LanguageMan.cpp` should not contain a handwritten `DeletingDestructor` method; it should contain the ordinary destructor body and class declaration.
- No file score change is required from this report alone; optional confidence can move `85 -> 86` after implementation because the scalar wrapper route/helper names are clearer.

For [UID:00018R] `LanguageManLocalization` aggregate:

- Update the covered-ranges table for `0x004f03d0-0x004f0477` to say "class-owned compiler scalar deleting wrapper generated for `LanguageMan::~LanguageMan`; no target-level handwritten C++".
- Add the object-size immediate `0x2c` / 44 bytes (Verified with `int_convert.py`) to the scalar wrapper note.

For [UID:0000RC] and [UID:0001OS] `g_pLanguageMan` docs:

- Clarify that constructor prologue stores the complete `LanguageMan*` into `g_pLanguageMan`. The `lea [this+4]` then `add -4` sequence collapses back to `this` when non-null.
- Keep `LanguageManager` as alias-only, not a separate singleton.
- No score change required.

For [UID:00018T] `LocalizationAdjacentZeroInitializer`:

- Add a cross-note only: UID `00018V` proves the complete `LanguageMan` object size immediate is `0x2c` / 44 bytes (Verified with `int_convert.py`), and `00018T` writes inside that size envelope. This increases plausibility of a LanguageMan-tail-field relationship but still does not prove a caller/class-method route.
- Do not reroute `00018T` to the class from this evidence alone.

## Validator Needs

No validators were run for this report-only task.

Implementation callback validation commands:

> Executable block R001 was removed from this report and preserved verbatim in [00018V-LanguageManScalarDeletingDestructor-source-quality-removed.md](00018V-LanguageManScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation callback edits only UID `00018V`, run only that target validator and autogen refresh.

Post-validation checks:

- Confirm `auto-generated/NexusTK/localization/LanguageMan.cpp` routes UID `00018V` through class UID `000071`.
- Confirm no handwritten `LanguageMan::DeletingDestructor` body appears from UID `00018V`.
- Confirm any destructor source body is emitted only from UID `00018S`, if that support page is included in the callback.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` during this B-agent report. If the supervisor accepts this report and requests implementation, replace the current UID `00018V` row with:

```text
    - [UID:00018V][0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor](by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md) 0x004f03d0-0x004f0477 | scalar-deleting-destructor | LanguageMan scalar deleting destructor : reconstructable : 87% : very-strong : B002 source-quality pass raw-disassembled the 0xa7 / 167-byte wrapper, verified vtable-only reachability at 0x0061c9e0, no direct rel32 callers, LanguageMan vtable reset refs, string table cleanup at +0x4/+0x8, g_pLanguageMan clear, LObject destructor call, GetMemoryMan/FreeBufferMemory/OperatorDeleteWrapper helper names, delete flags including the 0x2c / 44-byte guarded no-op path for flags & 4, and adjacent 0x004f0477-0x004f0480 padding; reroute owner/emitter through [UID:000071] LanguageMan and keep formal C++ to a no-code compiler-wrapper marker because source should emit ordinary LanguageMan::~LanguageMan().
```

## Changed Files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/00018V-LanguageManScalarDeletingDestructor-source-quality.md`

Modified:

- None.

Target/support by-* docs edited:

- None.

Coverage report edited:

- No. Exact pending row text is included above for supervisor-owned application.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00018V-LanguageManScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00018V"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00018V-LanguageManScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00018V-LanguageManScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00018V"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
