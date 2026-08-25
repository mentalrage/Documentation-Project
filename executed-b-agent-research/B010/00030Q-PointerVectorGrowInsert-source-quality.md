** TARGET-REPORT-UID:00030Q **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B010 Source-Quality Report: UID 00030Q PointerVectorGrowInsert

Assignment: `B010-goal2-pointer-vector-grow-insert-source-quality-00030Q-20260619`

Target: [UID:00030Q] `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00420de0-0x00420eea.PointerVectorGrowInsert.md`

Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B010\research\00030Q-PointerVectorGrowInsert-source-quality.md`

Mode: report-only. I did not edit by-memory, by-file, by-class, by-project-structure, auto-generated, or coverage-report files.

## Executive Conclusion

[UID:00030Q] is an exact 4-byte value-vector grow/insert slow path at `0x00420de0-0x00420eea`. The current direct owner, [UID:0000P3] `VectorHelpers`, remains the best source-placement owner because the function is reused by fitting-room code and by non-fitting-room `NewHumanImageLib` constructor code. It should not be moved to `FittingRoom`, `FittingRoomListPane`, `FittingRoomDialogItemState`, or `NewHumanImageLib`.

The main source-quality correction is naming and type scope. The existing title `PointerVectorGrowInsert` is directionally useful because one caller inserts `FittingRoomCatalogEntry*`, but it is too narrow. The binary caller setup proves the helper is a shared 4-byte slot grow/insert helper used for both integer/enumeration vectors and pointer vectors:

- `0x0041fef1` inserts a sign-extended byte/part-type value into a stack vector in `FittingRoomListPane::OnInputEvent`.
- `0x00422d31` inserts a `FittingRoomCatalogEntry*` into a pending-entry pointer vector in `FittingRoomDialogItemState::LoadCategoryFromJson`.
- `0x004e020d` inserts a converted integer hair-color/palette value into `NewHumanImageLib` member vector `this+0x54`.

Best-supported source-facing role: a compiler/STL/template support body for `std::vector<T>`-style grow insert when `sizeof(T) == 4` and `T` is trivially movable/copyable. Best working name for future docs/source notes: `Vector4ByteGrowInsert` or `DwordVectorGrowInsert`. Keep `PointerVectorGrowInsert` as the current UID title unless a supervisor rename pass is planned; treat `UInt32Vector_Insert_420DE0` as a historical alias, not the final semantic name.

Formal C++ should remain blank in the target page for now. The algorithm is reconstructable, but a source insertion would overstate the recovered source shape because the exact template declaration, original helper spelling, and concrete typedef set are not source-quality. A validation-only C++ sketch is included below, but it should not be copied into the by-memory `RECONSTRUCTION_CPP` block until the header/template policy is settled.

## Inputs Reviewed

Project instructions and assignment control:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B010/goal.md`
- `tools/leaser/Agents/Agent-B010/notes.md`

Target and owner docs:

- `by-memory/0x00420de0-0x00420eea.PointerVectorGrowInsert.md`
- `by-file/VectorHelpers.md`
- `by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md`
- `by-class/UInt32Vector.md`
- `by-meta/client_containers.md`
- `by-project-structure/proposed-source-tree.md`

Support/callee docs:

- `by-memory/0x00421500-0x0042151a.MsvcVectorThrowHelpers.md`
- `by-memory/0x00421520-0x00421584.AllocateAlignedDwordArray.md`
- `by-memory/0x00421290-0x00421301.PointerVectorCopyConstruct.md`

Caller docs:

- `by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md`
- `by-memory/0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson.md`
- `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`

Generated/source-placement evidence:

- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/util/VectorHelpers.cpp`
- `by-file/-coverage-report.md`
- `by-memory/-coverage-report.md`
- `project-level/-resolved.md`
- `project-level/-unresolved.md`
- `project-level/-resolved-multple-aliases.md`

Prior B-agent research:

- `tools/leaser/Agents/Agent-B001/research/executed/older/0002DR-FittingRoomSelectionVectorHelpers.md`

Fresh read-only binary validation:

- Local PE: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Capstone 5.0.7 disassembly with manual PE mapping.
- IDA MCP endpoint check at `http://127.0.0.1:13337/mcp` timed out in this session, so no new live IDA MCP state was used. Existing IDA-backed docs and the local PE read-only pass agree on the material facts.

## Current Target State

Target metadata currently records:

- UID: `00030Q`
- Completion/confidence: `85/87`
- Canonical owner: `0000P3`
- Reconstructable: `TRUE`
- Emitter UID: `0000P3`
- Current IDA name: `sub_420DE0`
- Current title: `PointerVectorGrowInsert`
- Parent aggregate: [UID:0002DR] `0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers`
- Current handling: reconstructable source-declared vector helper / emitted template support, with blank C++ because final concrete template declaration and typedefs are not source-quality.

This state is mostly correct. The main correction is that "pointer-vector" should be treated as pointer-size/4-byte-slot support rather than pointer-only support.

## Heuristic / Inference Reanalysis And Validation

### Evidence Ladder

Confirmed binary facts:

- `0x00420de0` is a function start and the function ends at exclusive address `0x00420eea`.
- The body uses `ECX` as a vector header pointer and returns with `ret 8`, so it has two stack arguments.
- Argument 1 is an insertion position pointer inside the old vector storage.
- Argument 2 is a pointer to the 4-byte value being inserted.
- The vector header is three pointers at offsets `+0`, `+4`, and `+8`: begin, end, capacity end.
- The helper divides byte distances by 4 through `sar ..., 2`, allocates `count * 4` storage through `0x00421520`, copies byte ranges with `_memmove_0` at `0x005c9b30`, frees old storage through `0x005c7526` after MSVC aligned-allocation validation, updates begin/end/capacity pointers, and returns the new inserted element address.
- Direct relative call sites to `0x00420de0` are exactly `0x0041fef1`, `0x00422d31`, and `0x004e020d` in the local PE scan. No immediate dword references to `0x00420de0` were found in the PE sections scanned.
- Following bytes `0x00420eea-0x00420ef0` are six `0xcc` padding bytes. Existing docs also record `0x00420dd5-0x00420de0` as padding before this helper island.

Strong inferences:

- This is the grow/reallocation path of a vector insert operation for a 4-byte element type, not a full vector insert routine. All visible callers call it only on the full-capacity path; non-full callers store directly into `*end` and advance `end`.
- It is shared template/helper support. The body is type-erased at the machine-code level because all observed element types are 4-byte trivially copyable values.
- The helper may be a COMDAT-folded or otherwise shared MSVC/Dinkumware-like vector instantiation body. The exact compiler/linker mechanism is inferred from behavior and shared runtime helper use, not proven by PDB or linker map data.

Rejected weak inferences:

- "It belongs to fitting-room because it is physically adjacent to fitting-room helpers." Rejected because `0x004e020d` calls it from `NewHumanImageLib::NewHumanImageLib`.
- "It is pointer-only." Rejected because two caller setups insert integer-like 4-byte values, not pointers.
- "It is a `UInt32Vector` method." Rejected as final naming because it also serves pointer vectors. `UInt32Vector_Insert_420DE0` is useful history but too narrow as a source-facing name.
- "It should emit as a standalone hand-authored `VectorHelpers.cpp` function today." Rejected because the direct owner docs and proposed source tree favor `VectorHelpers.h`/template support, while the generated `VectorHelpers.cpp` currently contains only an empty marker for this UID.

### Name Reanalysis

Current names and quality:

| Name | Quality | Reanalysis |
| --- | --- | --- |
| `sub_420DE0` | raw IDA placeholder | Keep only as IDA/raw alias. It remains listed in project-level unresolved because the target doc still mentions the raw name. |
| `FUN_00420de0` | raw Ghidra alias | Historical alias only. |
| `UInt32Vector_Insert_420DE0` | historical resolved alias | Better than raw IDA, but still too narrow because one caller inserts pointers and others insert integer/enumeration values. |
| `PointerVectorGrowInsert` | current UID/title | Acceptable as a stable current title, but source-quality text should qualify it as 4-byte value/pointer-slot support. Pointer-only wording should be avoided. |
| `DwordVectorGrowInsert` | recommended working name | Best concise name if the docs can tolerate dword-oriented helper names. |
| `Vector4ByteGrowInsert` | recommended working name | Most explicit and least semantically misleading: it describes the emitted body without over-committing to `uint32_t`, enum, or pointer element type. |
| `StdVector4ByteGrowInsert` | possible implementation note | Useful if the project decides to label STL/template support explicitly, but may overstate the exact library origin. |

Recommendation: use `Vector4ByteGrowInsert` in source-quality prose and implementation checklists, while leaving the UID title unchanged unless a supervisor rename pass is explicitly requested.

### Type Reanalysis

The best support type is not `std::vector<void*>` and not a concrete `UInt32Vector`. It is a layout-compatible vector header for 4-byte elements:

```cpp
struct Vector4ByteHeader {
    unsigned char* begin;
    unsigned char* end;
    unsigned char* capacityEnd;
};
```

For source-facing caller reconstruction, this should usually disappear into typed vectors:

- `std::vector<int>` / `std::vector<FittingRoomPartType>` for fitting-room part-type values.
- `std::vector<FittingRoomCatalogEntry*>` for pending category entries.
- `std::vector<int>` / `std::vector<uint32_t>` for NewHumanImageLib hair-color palette values.

The target helper itself should not force one typedef. A final compatibility helper, if needed, should be templated or explicitly documented as a 4-byte slot helper:

```cpp
template <class T>
T* GrowInsert4ByteVector(std::vector<T>& vector, T* position, const T& value);
```

That template spelling is illustrative only. The project has not recovered original source spelling or exact use of `std::vector` versus a project-local vector wrapper.

### Owner Reanalysis

The current owner [UID:0000P3] `VectorHelpers` is still best supported.

Reasons:

- `VectorHelpers.md` is already projected to `NexusTK/util/` and specifically owns `00030Q` and sibling `00030Z`.
- `by-project-structure/proposed-source-tree.md` lists `util/VectorHelpers.h` under reusable containers/template helpers and says feature modules consume generic vector machinery rather than absorbing it.
- `by-meta/client_containers.md` tracks `VectorHelpers` as reusable collection/allocation support.
- The call set crosses fitting-room and render/image-library code.
- The callee set uses runtime/STL-like vector throw, aligned allocation, memmove, and deallocation support.

Rejected owner alternatives:

- `FittingRoom` or `FittingRoomListPane`: physical adjacency and two fitting-room callers are outweighed by the non-fitting-room caller and generic body.
- `FittingRoomDialogItemState`: only one consumer and only the pointer-vector use case.
- `NewHumanImageLib`: one consumer and only the integer hair-color use case.
- `UInt32Vector`: older bucket, but not direct source ownership for pointer uses.

### Compiler/Generated Reanalysis

This helper has the signature and behavior expected from a compiler-emitted or STL-template vector grow insert body:

- `ECX` carries the vector header pointer.
- `ret 8` removes `position` and `valueRef`.
- It calls the local `vector<T> too long` throw/report helper at `0x00421500`.
- It calls `0x00421520`, already documented as an aligned dword-array vector allocator.
- It frees aligned vector storage with the same validation pattern used by other MSVC vector helpers.
- It uses `memmove` rather than element constructors/destructors, consistent with 4-byte trivially copyable element types.

The project should reconstruct the typed caller source first. Only add an explicit helper declaration/body if the build cannot reproduce the emitted helper from normal typed vector declarations.

## Instruction-Level Behavior

Fresh local PE disassembly confirms the following source-equivalent flow.

Function shape:

- Entry: `0x00420de0`
- Exit path return: `0x00420edd ret 8`
- Noreturn error tails:
  - `0x00420ee0 call 0x005cd607` invalid-parameter handling for bad aligned allocation metadata.
  - `0x00420ee5 call 0x00421500` vector-too-long helper.
- Exclusive end: `0x00420eea`

Parameters:

| Machine location | Meaning |
| --- | --- |
| `ECX` / saved `ESI` | vector header pointer (`begin`, `end`, `capacityEnd`) |
| `[ebp+8]` / saved `EDI` initially | insertion position pointer inside old storage |
| `[ebp+0xc]` | pointer/reference to the 4-byte value being inserted |
| return `EAX` | pointer to inserted element in new storage |

Algorithm:

1. Read `oldBegin = vector->begin`, `oldEnd = vector->end`, and `oldCapacityEnd = vector->capacityEnd`.
2. Compute `insertIndex = (insertPos - oldBegin) / 4`.
3. Compute `oldSize = (oldEnd - oldBegin) / 4`.
4. If `oldSize == 0x3fffffff`, call `VectorTooLong_421500`.
5. Compute `newSize = oldSize + 1`.
6. Compute old capacity in 4-byte slots.
7. Compute a 1.5x geometric capacity when possible, otherwise use the required new size. Because visible callers enter only on full-capacity paths, the overflow branch resolves to the required maximum-sized growth case rather than an arbitrary smaller capacity.
8. Allocate new dword storage with `AllocateAlignedDwordArray(newCapacity)`.
9. Store the 4-byte inserted value at `newBegin + insertIndex * 4`.
10. If inserting at old end, copy the whole old `[begin,end)` span to the start of new storage.
11. Otherwise, copy the prefix `[oldBegin, insertPos)` to the new start and copy the suffix `[insertPos, oldEnd)` to `newBegin + (insertIndex + 1) * 4`.
12. If old storage is non-null, free it. For large allocations (`>= 0x1000` bytes), validate the saved raw allocation pointer at `oldBegin[-4]`, adjust size by `0x23`, and invalid-parameter on impossible alignment metadata before calling the checked free helper.
13. Update `begin`, `end`, and `capacityEnd`.
14. Return `begin + insertIndex * 4`.

Mapped callees:

| Address | Current/best name | Role |
| --- | --- | --- |
| `0x00421500` | `VectorTooLong_421500` / `MsvcVectorThrowHelpers` | Noreturn max-size vector growth error. |
| `0x00421520` | `AllocateAlignedDwordArray` | Allocate `count * 4` bytes with MSVC-style aligned large-allocation handling. |
| `0x005c9b30` | `_memmove_0` | Copy prefix/suffix byte spans. |
| `0x005c7526` | checked free / runtime deallocator | Free old vector storage, receiving raw pointer and byte count. |
| `0x005cd607` | `__invalid_parameter_noinfo_noreturn` | Noreturn invalid aligned-allocation metadata guard. |

## Caller And Reachability Analysis

Fresh local PE call scan found exactly three relative calls to `0x00420de0`:

| Call site | Owner context | Inserted value evidence | Source-quality implication |
| --- | --- | --- | --- |
| `0x0041fef1` | [UID:0002DN] `FittingRoomListPane::OnInputEvent` | The caller stores `movsx ecx, al` into a stack dword at `[ebp-0xdc]`, passes `&value`, insertion position `eax`, and vector header `lea ecx,[ebp-0x2c]`. This is a part-type or enum/integer vector, not a pointer vector. | Consumer only. Supports generic 4-byte vector support and rejects pointer-only naming. |
| `0x00422d31` | [UID:0002E6] `FittingRoomDialogItemState::LoadCategoryFromJson` | The caller has a newly allocated/parsed `FittingRoomCatalogEntry*` in `esi`, stores it through the direct path when capacity exists, and calls `0x00420de0` with `&esi` when full. | Pointer-vector use case. Explains the current title, but not enough to make the helper pointer-only. |
| `0x004e020d` | [UID:0002JR] `NewHumanImageLib::NewHumanImageLib` | The caller converts a six-byte text row through `0x005cea6d`, stores the integer result in a local dword, and grows the member vector at `this+0x54` if full. | Non-fitting-room integer vector use case. Strongest owner evidence for shared `VectorHelpers`. |

Reachability notes:

- No vtable, class-method, exported-symbol, or data-pointer route to this helper was found in the local PE pass.
- The helper is reached as ordinary direct code from typed caller logic.
- Because the visible direct callers are full-capacity slow paths, source callers should be reconstructed as ordinary `push_back`/`insert` operations or typed vector operations, not as explicit calls to `Vector4ByteGrowInsert`.

## Fields, Types, Globals, And Placeholders

Target-local fields:

| Offset | Best-supported role | Notes |
| --- | --- | --- |
| `this+0x00` | `begin` | Pointer to first 4-byte slot. |
| `this+0x04` | `end` | Pointer one past last populated 4-byte slot. |
| `this+0x08` | `capacityEnd` | Pointer one past allocated 4-byte storage. |

Target-local globals:

- None. The target helper reads no global project state and uses no strings directly.

Caller-owned state examples:

| Caller | State |
| --- | --- |
| `FittingRoomListPane::OnInputEvent` | Stack vector for selected part-type values. |
| `FittingRoomDialogItemState::LoadCategoryFromJson` | Stack pending vector of `FittingRoomCatalogEntry*`. |
| `NewHumanImageLib::NewHumanImageLib` | Member vector at `this+0x54/+0x58/+0x5c`, documented as the hair-color vector. |

Placeholders and recommended interpretation:

| Placeholder/raw name | Recommended status |
| --- | --- |
| `sub_420DE0` | Raw IDA name for this target. Replace in explanatory prose with `Vector4ByteGrowInsert`/`DwordVectorGrowInsert` once allowed. |
| `FUN_00420de0` | Raw Ghidra alias. Historical only. |
| `UInt32Vector_Insert_420DE0` | Historical alias from older reports. Keep as alias, not source-facing name. |
| `sub_421500` | `VectorTooLong_421500`, documented under MSVC vector throw helpers. |
| `sub_421520` | `AllocateAlignedDwordArray`, documented shared dword-array allocator. |
| `sub_5C7526` | Runtime checked free/deallocator helper. Exact source spelling remains lower confidence, but role is clear. |
| `_memmove_0` / `0x005c9b30` | CRT memmove wrapper/import. |
| `__invalid_parameter_noinfo_noreturn` / `0x005cd607` | Runtime invalid-parameter noreturn handler. |

## Owner And Source Placement

Keep owner [UID:0000P3] `VectorHelpers`.

Source placement should be described as:

- Proposed source folder: `NexusTK/util/`.
- Preferred final source artifact: `VectorHelpers.h` or equivalent template/container support header.
- Current generated artifact: `auto-generated/NexusTK/util/VectorHelpers.cpp`, but it contains only an empty emitter marker for UID `00030Q`.

Relevant generated marker:

```text
// UID:00030Q | by-memory\0x00420de0-0x00420eea.PointerVectorGrowInsert.md | Completion:85 | Confidence:87 | Empty Emitter Marker
```

This means current autogen routing is structurally correct but source emission is intentionally absent. The implementation should be recovered through typed vector declarations in callers, not by inventing a standalone project utility function unless binary compatibility demands it.

## Split And Range Decisions

The current range split is correct.

| Range | Decision |
| --- | --- |
| `0x00420dd5-0x00420de0` | Preceding `0xcc` alignment padding documented in ignored/coverage context. Do not merge into 00030Q. |
| `0x00420de0-0x00420eea` | Exact helper body, including normal return and two noreturn error tails. |
| `0x00420eea-0x00420ef0` | Six bytes of `0xcc` padding confirmed by local PE read. Do not merge into 00030Q or 00030R. |
| `0x00420ef0-0x00421143` | Separate [UID:00030R] fitting-room entry-vector insert helper. Do not merge with 00030Q. |

The parent aggregate [UID:0002DR] is correctly treated as a mixed helper-island/audit container. 00030Q should remain an exact child function, not an aggregate owner and not a physical-neighborhood source file.

## Open-Question Closure

| Question | Closure |
| --- | --- |
| Is this fitting-room-private? | Closed: no. The `0x004e020d` caller in `NewHumanImageLib::NewHumanImageLib` is outside fitting-room. |
| Is this pointer-only? | Closed: no. Two callers insert integer-like 4-byte values. |
| Is this a concrete `UInt32Vector` method? | Closed as final-source name: no. It is a 4-byte vector helper that also handles pointer slots. |
| Is `VectorHelpers` still the best owner? | Closed: yes, subject to header/template caveat. |
| Does the exact range need a split? | Closed: no internal split; exact range `0x00420de0-0x00420eea` is correct. |
| Should 0002DR own/emit this code? | Closed: no. 0002DR is a mixed aggregate; exact child pages own source placement. |
| Should formal C++ be populated in the target today? | Closed for this pass: no. See no-code proof below. |
| Original helper spelling/header location? | Open. Best current placement is `NexusTK/util/VectorHelpers.h` or typed caller-owned vector declarations. |
| Exact runtime deallocator source spelling? | Open but not blocking. The role and call behavior are clear. |
| Exact compiler mechanism for sharing this body across element types? | Open. COMDAT/template folding is plausible but not proven without PDB/linker metadata. |

## First-Draft C++ Eligibility / Exact No-Code Proof

Formal first-draft C++ is not eligible for insertion into the target page today.

Exact no-code proof:

1. The helper is shared by at least three distinct source type contexts: part-type integer/enumeration values, entry pointers, and hair-color integer values. A single concrete non-template C++ signature would be misleading.
2. The current target title `PointerVectorGrowInsert` is not source-quality as a type name because two callers are not pointer vectors.
3. `VectorHelpers.md` explicitly warns that final source may be header/template support or compiler-emitted template support, and the validator-created `.cpp` is a staging artifact rather than proof of an original `VectorHelpers.cpp` body.
4. `auto-generated/NexusTK/util/VectorHelpers.cpp` contains an empty emitter marker for UID `00030Q`, confirming that current autogen knows the route but does not have source-quality C++.
5. The surrounding runtime helpers `MsvcVectorThrowHelpers` and `AllocateAlignedDwordArray` are documented as MSVC/Dinkumware-style vector support rather than NexusTK-authored source. Hand-authoring this body as a product function would overstate authorship.
6. A source-quality reconstruction should normally express typed vectors at the callers. The emitted helper body should be left to the compiler/STL or implemented as a compatibility template only if the build/reproduction policy requires it.

Validation-only source-equivalent sketch, not recommended for target insertion:

```cpp
struct Vector4ByteHeader {
    unsigned char* begin;
    unsigned char* end;
    unsigned char* capacityEnd;
};

// Analysis sketch only. The original source was likely typed vector/template support.
static unsigned char* __thiscall Vector4ByteGrowInsert(
    Vector4ByteHeader* vector,
    unsigned char* position,
    const unsigned char* value4)
{
    unsigned char* oldBegin = vector->begin;
    unsigned char* oldEnd = vector->end;
    const unsigned int insertIndex =
        static_cast<unsigned int>((position - oldBegin) >> 2);
    const unsigned int oldSize =
        static_cast<unsigned int>((oldEnd - oldBegin) >> 2);

    if (oldSize == 0x3fffffff) {
        VectorTooLong_421500();
    }

    const unsigned int required = oldSize + 1;
    const unsigned int oldCapacity =
        static_cast<unsigned int>((vector->capacityEnd - oldBegin) >> 2);

    unsigned int newCapacity = required;
    const unsigned int halfCapacity = oldCapacity >> 1;
    if (oldCapacity <= 0x3fffffff - halfCapacity) {
        const unsigned int geometric = oldCapacity + halfCapacity;
        if (geometric >= required) {
            newCapacity = geometric;
        }
    }

    unsigned char* newBegin =
        reinterpret_cast<unsigned char*>(AllocateAlignedDwordArray(newCapacity));
    unsigned char* inserted = newBegin + insertIndex * 4;
    *reinterpret_cast<unsigned int*>(inserted) =
        *reinterpret_cast<const unsigned int*>(value4);

    if (position == oldEnd) {
        memmove(newBegin, oldBegin, oldEnd - oldBegin);
    } else {
        memmove(newBegin, oldBegin, position - oldBegin);
        memmove(inserted + 4, position, oldEnd - position);
    }

    FreeVectorStorageWithMsvcAlignmentCheck(
        oldBegin,
        vector->capacityEnd - oldBegin);

    vector->begin = newBegin;
    vector->end = newBegin + required * 4;
    vector->capacityEnd = newBegin + newCapacity * 4;
    return inserted;
}
```

The sketch is useful for validator/test implementation planning only. It should remain out of `RECONSTRUCTION_CPP` until the source declaration is recovered as a template/header or the project decides to add explicit compatibility helpers.

## Exact Supervisor-Owned Coverage Row Text

Current exact row in `by-memory/-coverage-report.md`:

```text
            - [UID:00030Q][0x00420de0-0x00420eea.PointerVectorGrowInsert](by-memory/0x00420de0-0x00420eea.PointerVectorGrowInsert.md) 0x00420de0-0x00420eea | helper-function | PointerVectorGrowInsert : reconstructable : 85% : strong : Assigned to VectorHelpers (0000P3); shared 4-byte pointer-vector grow/insert helper with fitting-room and non-fitting-room callers.
```

Supervisor-only future row improvement, if this report is accepted:

```text
            - [UID:00030Q][0x00420de0-0x00420eea.PointerVectorGrowInsert](by-memory/0x00420de0-0x00420eea.PointerVectorGrowInsert.md) 0x00420de0-0x00420eea | helper-function | PointerVectorGrowInsert : reconstructable : 85% : strong : Assigned to VectorHelpers (0000P3); shared 4-byte value-vector grow/insert helper used by fitting-room integer/pointer vectors and non-fitting-room NewHumanImageLib integer-vector code.
```

Do not apply that row directly from this report-only assignment.

## Target Implementation Checklist

Recommended target-page updates for a future A/supervisor pass:

- Keep `CANONICAL_OWNER:0000P3`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000P3`.
- Keep the exact range `0x00420de0-0x00420eea`.
- Retain `PointerVectorGrowInsert` as the UID title unless a rename pass is authorized, but change behavior prose from pointer-only to 4-byte value/pointer-slot grow insert.
- Add caller-type evidence:
  - `0x0041fef1`: fitting-room part-type/integer stack vector.
  - `0x00422d31`: fitting-room pending-entry pointer vector.
  - `0x004e020d`: `NewHumanImageLib` hair-color integer vector.
- Add the best-supported working names `Vector4ByteGrowInsert` / `DwordVectorGrowInsert` and demote `UInt32Vector_Insert_420DE0` to historical alias.
- Add the local PE validation result: exact three rel32 callers, no dword references, following padding `cc cc cc cc cc cc`.
- Keep target C++ blank and record the no-code proof above unless the project introduces a `VectorHelpers.h` template support policy.
- Keep completion/confidence at least `85/87`. A small confidence increase could be justified by the integer-vs-pointer caller clarification, but the unresolved source-header/template spelling still prevents a high-final score.

## Support Implementation Checklist

Recommended support-doc updates for future non-report-only work:

- `VectorHelpers.md`: clarify that `00030Q` is a 4-byte value-vector grow insert helper, not only pointer-vector support. Keep the `VectorHelpers.h` caveat and empty `.cpp` marker policy.
- `UInt32Vector.md`: preserve the note that `0x00420de0` was historically classified as `UInt32Vector`, but add that the helper also serves pointer vectors and should be treated as generic 4-byte vector support.
- `project-level/-resolved.md`: if alias hygiene is in scope, resolve `sub_420DE0` to `Vector4ByteGrowInsert_420DE0` or `DwordVectorGrowInsert_420DE0` rather than the older `UInt32Vector_Insert_420DE0`.
- `project-level/-unresolved.md`: the pending `sub_420DE0` mention in the target doc should disappear after target prose uses a source-facing helper name and keeps raw IDA only in evidence fields.
- `FittingRoomListPaneOnInputEvent.md`: no required behavioral change, but its current C++ using `newEntry.partTypes.push_back(...)` is consistent with reconstructing typed caller source instead of direct helper calls.
- `FittingRoomDialogItemStateLoadCategoryFromJson.md`: no required behavioral change; its `pendingEntries.push_back(entry)` source is the correct source-facing form.
- `NewHumanImageLibConstructor.md`: no required owner change; its current note that `0x00420de0` is an integer-vector growth helper is important support evidence.
- `auto-generated/NexusTK/util/VectorHelpers.cpp`: leave as empty emitter markers until source-template policy is decided.

## Validation Notes

Read-only checks performed:

- `rg` searches for UID/name/address references across project documentation.
- `Select-String` read of the supervisor-owned coverage row.
- Local PE Capstone disassembly of `0x00420de0-0x00420eea`.
- Local PE scan for `call rel32` to `0x00420de0`.
- Local PE scan for immediate dword references to `0x00420de0`.
- Local PE byte read of `0x00420eea-0x00420ef0`.
- Generated `VectorHelpers.cpp` read to confirm empty emitter marker for UID `00030Q`.
- IDA MCP endpoint check timed out; no live IDA MCP mutation or query results were used in the final evidence beyond existing docs.

No validators were run because this was a report-only assignment and no by-* docs were edited.

## Changed Files

Created:

- `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B010\research\00030Q-PointerVectorGrowInsert-source-quality.md`

Not edited:

- `by-memory/0x00420de0-0x00420eea.PointerVectorGrowInsert.md`
- `by-memory/-coverage-report.md`
- Any by-* documentation
- Any auto-generated source file

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/00030Q-PointerVectorGrowInsert-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00030Q"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
