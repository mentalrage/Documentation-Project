** TARGET-REPORT-UID:000234 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000234 GameServerNationEntryArrayResize Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:000234] as the exact concrete `ProtectedArray<GameServerConfig::NationEntry>::Resize(int count)` binary body, owned by [UID:0000B4] `ProtectedArray<GameServerConfig::NationEntry>`, and document that its source body is the reusable `ProtectedArray<T>::Resize` template instantiated in the map/game-server nation table source family.
- Final disposition: no split or merge needed. This is a standalone `0x8b` / 139-byte function (Verified with int_convert.py), not scalar-delete glue, EH support, a base destructor, or tail code from either neighbor.
- Required action: update the target and support docs with the resolved source shape, field/type names, caller route, allocator/copy/free roles, and first-draft C++ below. Do not move ownership away from the concrete specialization; do add the reusable-template split note to [UID:0000MU] / [UID:0001WR].
- Confidence: very strong for range, behavior, caller/callee set, fields used by this body, and source-family route; medium-high for the original header basename and the exact original name of `ProtectedArray` field `+0x0c`.

## Target

- Target UID: `000234`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B008\research\000234-GameServerNationEntryArrayResize-source-quality.md`
- Current target state: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000B4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000B4`, blank C++.
- Current generated row: `auto-generated/-ag-memory-coverage.md` routes [UID:000234] through [UID:0000B4] to `auto-generated/NexusTK/map/GameServerConfig.cpp`, currently with no emitted code.
- Supervisor instruction: B-agent source-quality / heuristic report only. No target/support `by-*` edits and no `by-memory/-coverage-report.md` edit in this pass.

## Executive Recommendation

The direct semantic owner should remain [UID:0000B4] `ProtectedArray_struct_GameServerConfig__NationEntry_`. The function is a concrete instantiation method operating on the embedded protected-array object at `GameServerConfig + 0x04`; it is not a direct `GameServerConfig` member even though the feature route and generated output flow through [UID:0000JP] `GameServerConfig`.

Populate first-draft C++ for the target if the supervisor accepts concrete template-instantiation bodies in `by-memory` docs. The body should be source-style `ProtectedArray<GameServerConfig::NationEntry>::Resize(int count)`, with a support-doc requirement that `GameServerConfig::NationEntry` has a default constructor or default initializer that sets `nationId` to `-1`. That source shape explains the compiler's allocation-size overflow check and first-word initialization loop without hand-calling raw runtime helpers.

Also update [UID:0000MU] `ProtectedArray`, [UID:0001WR] `ProtectedArrayTemplates`, and [UID:0001VM] `ProtectedArrayLayout` to say that `Resize(int count)` is a reusable template body whose concrete `GameServerConfig::NationEntry` instantiation is [UID:000234]. Keep final original field name for `+0x0c` provisional; the best descriptive name is `m_reservedCount` or `m_defaultCapacity`, not `m_capacity`, because reviewed resize/accessor/destructor bodies do not update or consult it.

## Supervisor Active Recheck

- Split need: no split. Raw PE bytes show `0x00514edd-0x00514ee0` is three `0xcc` bytes and `0x00514f6b-0x00514f70` is five `0xcc` bytes. The next function starts at `0x00514f70`.
- Boundary state: exact half-open range `0x00514ee0-0x00514f6b`.
- Ownership state: current owner/emitter [UID:0000B4] is correct for the concrete binary method. Source placement should document the split between reusable template source [UID:0000MU]/[UID:0001WR] and feature instantiation/output [UID:0000JP].
- B008 edit scope: this report only. Previous B008 reports, target docs, support docs, generated docs, and coverage docs were not modified.

## Inference Research Guidance Check

I treated existing docs and `simroot_v2` as leads, not authority. The current docs already had strong behavior notes, but the report rechecked:

- raw PE bytes and Capstone disassembly for the target range;
- rel32 caller scan across `.text`;
- current target/support docs for `ProtectedArray`, `GameServerConfig`, `GameServerNationEntry`, parser, seeder, destructor, vtable, and global table routes;
- generated output state under `auto-generated/NexusTK/map/GameServerConfig.cpp` and `auto-generated/NexusTK/util/ProtectedArray.cpp`;
- stale Wave2/Wave3/prewave names for `sub_514EE0`, `FUN_00514ee0`, `unknown_libname_19`, and `FID_conflict__free`.

IDA MCP was attempted per `by-structure.md` at `http://127.0.0.1:13337/mcp`; the endpoint was unavailable (`Unable to connect to the remote server`). Therefore this report relies on local PE/Capstone checks plus existing IDA-backed documentation/cache evidence. The raw PE checks confirm the material range/caller/callee facts that matter for this source-quality pass.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best inference / decision |
| --- | --- | --- |
| Source shape: template instantiation vs handwritten helper | Target `ecx` is `GameServerConfig + 0x04` from parser call `0x00503d4f`; body uses `ProtectedArray` header offsets `+0x04/+0x08`; sibling seeder `0x00503b60` inlines the same positive-count resize logic for constant count `2`; `ProtectedArray` image-loader docs record repeated allocation/free/memmove protected-array growth across other instantiations. | This is `ProtectedArray<T>::Resize(int count)` emitted for `T = GameServerConfig::NationEntry`, not a handwritten `GameServerConfig` array helper. |
| Function signature | Ghidra cache signature lead is `void __thiscall FUN_00514ee0(void *this, uint param_1)`; IDA cache lead is `void __thiscall sub_514EE0(int this, int a2)`; caller passes one stack argument and ignores `eax`; function ends `ret 4`. | `void __thiscall ProtectedArray<GameServerConfig::NationEntry>::Resize(int count)`. Use signed `int` because `count <= 0` is an explicit no-op. |
| Behavior name: resize vs reserve | Body updates field `+0x04` to requested count, replaces field `+0x08`, and copies `min(oldCount, count)` records. It ignores `+0x0c`. | Name should be `Resize` or `SetCount`; prefer `Resize(int count)` because docs and sibling behavior already call it resize, and it changes live count. Reject `Reserve` / `EnsureCapacity`. |
| `count <= 0` semantics | `test esi, esi; jle 0x00514f65`; count equal branch also exits. Parser passes packet count plus one, so normal caller is positive. | `Resize` is positive-count only. It does not clear on zero and should not be documented as `Clear` or full STL-style resize-to-zero. |
| Field names | Accessor docs prove `+0x04` count, `+0x08` entries, `+0x10` fallback/default entry. Constructor writes `+0x0c = 10`, but this target, accessors, destructor, and seeder do not use it. | Use `m_count`, `m_entries`, `m_defaultEntry`. For `+0x0c`, use descriptive `m_reservedCount` or `m_defaultCapacity` with an explicit provisional note; do not claim final original spelling. |
| `NationEntry` layout/source names | [UID:0001UP] documents 68-byte / `0x44` stride (Verified with int_convert.py), first 16-bit id, and 33-wide-character label. Parser and copy/fallback docs use generated nested spelling `GameServerConfig::NationEntry`. | Best source name remains `GameServerConfig::NationEntry` or nested `NationEntry`. Fields should be `nationId` and `label[33]`. Add a default constructor/default initializer setting `nationId = -1`. |
| Why the loop writes only first word | Target allocates raw array and stores `-1` at offset `0` of each new 68-byte record before prefix copy. The compiler array-new lowering for a trivial inline constructor `NationEntry::NationEntry() : nationId(-1) {}` can compile to this loop. | Source should not hand-write `*((short*)entry) = -1`; express the default record constructor in the type support doc. |
| Allocation helper name | Target call `0x00514f07 -> 0x005c7790`; disassembly at `0x005c7790` is a tiny runtime allocation thunk to `0x005c74f6`. Docs consistently call it `unknown_libname_19` / allocator, distinct from MemoryMan global `operator new` at `0x004f4aa0`. | In source-style C++, prefer `new T[count]` / `delete []`. In IDA/comment text call `0x005c7790` the MSVC/CRT array allocation helper or `operator new[]` route, not `AllocateBufferMemory` and not feature-owned MemoryMan `operator new`. |
| Copy helper name | Target call `0x00514f4e -> 0x005c95b0`; old report identifies `0x005c95b0` as `_memmove`; Capstone confirms normal `memmove` overlap-handling prologue. | Use `memmove` / `_memmove`, not `memcpy`. The old Ghidra `memcpy_optimized` name is stale for source-quality docs. |
| Free helper name | Target call `0x00514f56 -> 0x005c7799`; docs identify it as `j_j_j___free_base` / CRT free wrapper. | Source representation should be `delete [] m_entries` for template body, while comments may call the binary helper CRT free. |
| Scalar-delete / EH / base destructor boundaries | Target has no vtable store, no delete flag, no base cleanup call, no guard-check, no SEH/EH prolog. Scalar deleting destructor is [UID:000372] `0x00514d50-0x00514d7f`; GameServerConfig scalar deleting destructor is [UID:000374] `0x00514d80-0x00514ddc`. | Do not merge target with destructor support. Do not add base destructor or scalar-delete text to target C++. |
| Caller/reachability | Raw PE rel32 scan found exactly one call/jump to target: `0x00503d4f`. No absolute VA dword references to `0x00514ee0` were found in the PE scan. Existing parser docs match this caller. | Sole direct caller is `GameServerConfig::ParseNationEntries`; no hidden pointer/table route was found locally. |
| Source file route | Target is in map/game-server neighborhood and called from `GameServerConfig` parser; [UID:0000B4] routes to [UID:0000JP]. Reusable `ProtectedArray` docs route to [UID:0000MU] `NexusTK/util/`. | Keep target emitter route through [UID:0000B4] / [UID:0000JP] for concrete output, while support docs should say reusable source body belongs in `util/ProtectedArray.h`. |
| Generated-output pollution | `source-3/simroot_v2/util/ProtectedArray.h` currently emits only the scalar deleting destructor for `ProtectedArray_struct_GameServerConfig__NationEntry_`; current `auto-generated/NexusTK/map/GameServerConfig.cpp` has an empty marker for [UID:000234]. | The blank marker is stale after this pass. Add first-draft C++ to target if accepted; also update support docs to avoid one-class-per-template generated-name assumptions. |
| First-draft readiness | Current target average is `(84 + 90) / 2 = 87`, owner/emitter route is nonblank and valid, exact boundaries/callers/callees are documented, and source names are now strong enough. | Eligible and ready for first-draft C++ under current gate. Remaining open issues should cap score below final-audit range, not block draft code. |

## Evidence Standards Used

- Raw PE and Capstone evidence: section map, target disassembly, leading/trailing padding bytes, direct call/callee targets, rel32 scan, and absolute VA reference scan.
- Documentation evidence: target page, class/file/type/template/global docs, parser/seeder/destructor/vtable docs, generated coverage and current generated C++ markers.
- Negative evidence: IDA MCP unavailable this session; no local PE rel32 caller except parser call; no VA dword references to target; target has no scalar-delete/base/EH instructions.
- Conversion evidence: `0x44` / 68, `0x8b` / 139, `0x54` / 84, `0x21` / 33, `0x0a` / 10, `0x88` / 136, `0x2f` / 47, and `0x5c` / 92 were verified with `tools/int_convert.py`.

## Raw PE / Capstone Facts

### Function / Range Facts

- PE path used for local evidence: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Image base: `0x00400000`.
- `.text`: `0x00401000-0x0060c600`.
- Target bytes start at `0x00514ee0`: `55 8b ec 56 8b 75 08 57 8b f9 85 f6 7e 77 39 77`.
- Target tail is `ret 4` at `0x00514f68-0x00514f6a`; `0x00514f6b-0x00514f70` is `cc cc cc cc cc`.
- Preceding padding `0x00514edd-0x00514ee0` is `cc cc cc`.
- Size is `0x8b` / 139 bytes (Verified with int_convert.py).

### Core Instructions

```text
0x00514eea  test esi, esi
0x00514eec  jle 0x00514f65
0x00514eee  cmp [edi+0x04], esi
0x00514ef1  je 0x00514f65
0x00514ef7  mov edx, 0x44
0x00514efc  mul edx
0x00514eff  seto cl
0x00514f07  call 0x005c7790
0x00514f23  mov word ptr [edx], -1
0x00514f26  lea edx, [edx+0x44]
0x00514f32  mov edx, [edi+0x08]
0x00514f3c  cmp esi, ecx
0x00514f3e  cmovl ecx, esi
0x00514f4e  call 0x005c95b0
0x00514f56  call 0x005c7799
0x00514f5e  mov [edi+0x08], ebx
0x00514f61  mov [edi+0x04], esi
0x00514f68  ret 4
```

### Xref / Caller Facts

Raw PE rel32 scan across `.text` found exactly one direct call/jump to `0x00514ee0`:

```text
0x00503d4f  e8 8c 11 01 00  call 0x00514ee0
```

Parser context:

```text
0x00503d43  lea ecx, [esi+0x04]
0x00503d48  movzx ebx, al
0x00503d4e  push ebx
0x00503d4f  call 0x00514ee0
```

This proves the called object is the embedded protected-array member at `GameServerConfig + 0x04`, not the outer `GameServerConfig` object.

### Callee Facts

| Call site | Target | Role |
| --- | --- | --- |
| `0x00514f07` | `0x005c7790` | Runtime allocation helper / `unknown_libname_19`; best source representation is `new T[count]` / array allocation. |
| `0x00514f4e` | `0x005c95b0` | `_memmove` / overlap-safe prefix copy. |
| `0x00514f56` | `0x005c7799` | CRT free wrapper / `j_j_j___free_base`; best source representation is `delete [] m_entries`. |

No local call in this target reaches `0x004f4aa0` `OperatorNewWrapper`, `0x004f4ac0` `OperatorDeleteWrapper`, `0x004f4a90` base cleanup, guard-check, or scalar-delete support.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00514ee0-0x00514f6b` | [UID:000234] target | Concrete `ProtectedArray<GameServerConfig::NationEntry>::Resize(int count)` body | TRUE | [UID:0000B4] | Recommend `88/92` | Keep exact target, add source-quality notes and draft C++. |
| `0x00514d50-0x00514d7f` | [UID:000372] | Concrete protected-array scalar deleting destructor | TRUE | [UID:0000B4] | `90/93` | Separate compiler destructor wrapper. |
| `0x00514d80-0x00514ddc` | [UID:000374] | `GameServerConfig` scalar deleting destructor | TRUE | [UID:00005O] | `90/93` | Separate outer class destructor wrapper. |
| `0x0061e704-0x0061e708` | [UID:0003II] | Concrete protected-array vtable slot | TRUE | [UID:0000B4] | `86/93` | Generated from concrete template/class declaration. |
| `0x00503d10-0x00503e77` | [UID:0002I0] | Parser caller | TRUE | [UID:00005O] | `85/90` | Sole direct caller of target. |
| `0x00503b60-0x00503c61` | [UID:0002HY] | Raw default seeder | TRUE | [UID:00005O] | `85/88` | Inlines same count-2 resize pattern; no direct call to target. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00503d4f` | only rel32 caller to `0x00514ee0` | Parser resizes the table to packet count plus one before writing records. |
| `0x00503d43` | `lea ecx, [esi+4]` before call | Confirms `this` is the embedded protected-array member, not outer `GameServerConfig`. |
| `0x00503b60` raw seeder | no call to `0x00514ee0`, but same allocation/copy/free sequence for count `2` | Strong evidence of inlined template body / source-level `Resize(2)` behavior. |
| `0x00514d50` vtable slot ref from `0x0061e704` | destructor support for same concrete specialization | Confirms specialization identity, but not part of this target. |
| `0x0061e704` vtable store refs | constructor/destructor stores at raw constructor, raw destructor, MapPane initialization, and destructor wrappers | Confirms concrete `ProtectedArray<GameServerConfig::NationEntry>` class exists in binary. |

## Documentation Evidence And IDA Status

### Existing Docs That Support The Conclusion

- [UID:000234] already documents the exact range, sole parser caller, `0x44` / 68-byte stride (Verified with int_convert.py), first-word `-1` initialization, `memmove`, old-buffer free, and final field updates.
- [UID:0000B4] documents the concrete specialization, destructor, resize helper, vtable slot, parser call, and `GameServerConfig` embedding.
- [UID:0001WR] and [UID:0000MU] document `ProtectedArray<T>` as reusable template/header source, and warn that generated one-class files are not original source-file proof.
- [UID:0001VM] documents `ProtectedArray` offsets `+0x04` count, `+0x08` entries, `+0x10` fallback/default entry, and unresolved `+0x0c`.
- [UID:0001UP] documents `GameServerConfig::NationEntry` as 68 bytes with `nationId` plus `label[33]`.
- [UID:0002I0] documents parser caller `0x00503d4f` and packet count plus one route.
- [UID:0002HY] documents the default seeder using the same 68-byte record allocation/copy/free pattern.

### Existing Docs That Need Cleanup Or Clarification

- Target page still says C++ remains blank because the emission may be template instantiation. That is now resolved enough for first-draft code: use the source-style template body, with target documented as the concrete emitted instantiation.
- Target page calls the body "resize/reserve helper"; "reserve" should be removed because the body updates `m_count`, not only storage capacity.
- The docs should stop presenting `unknown_libname_19` as an unresolved source helper for this target. It is runtime array allocation/compiler support; source should be `new T[count]` or an equivalent array-allocation expression.
- [UID:0001UP] should add the likely default constructor/default initializer for `NationEntry::nationId = -1`; otherwise the C++ `new NationEntry[count]` draft does not explain the binary initialization loop.
- [UID:0001VM] should keep `+0x0c` provisional. It should not be renamed unqualified `m_capacity` unless another pass finds code that updates/uses it as capacity.

### Generated / Coverage State

- Current generated `auto-generated/NexusTK/map/GameServerConfig.cpp` has only an empty marker for [UID:000234].
- Current generated `auto-generated/NexusTK/util/ProtectedArray.cpp` has no [UID:0000B4] concrete class marker because [UID:0000B4] routes through [UID:0000JP], not [UID:0000MU].
- `source-3/simroot_v2/util/ProtectedArray.h` contains the stale/generated concrete class name and only the scalar deleting destructor for `ProtectedArray_struct_GameServerConfig__NationEntry_`, which is useful as provenance but not final source shape.

## Ranked Ownership Analysis

### 1. [UID:0000B4] `ProtectedArray<GameServerConfig::NationEntry>` Concrete Specialization

- Evidence for: target operates on `ProtectedArray` offsets relative to `ecx`; parser passes `GameServerConfig + 4`; vtable data [UID:0003II] and destructor [UID:000372] are attached to the same specialization; target stride matches [UID:0001UP].
- Evidence against: original source likely defined the body in reusable `ProtectedArray<T>` template code, not in a one-off concrete class source file.
- Decision: keep as direct semantic owner for this exact by-memory item. Add text explaining the source-body split rather than changing owner.

### 2. [UID:0000MU] / [UID:0001WR] `ProtectedArray` Reusable Template Source

- Evidence for: body is generic except for `T` size and `T` default construction; other `ProtectedArray` docs show shared offsets and template behavior; seeder inlines the same pattern.
- Evidence against: the concrete emitted binary function and route live in the GameServerConfig feature neighborhood, and current target docs/coverage route through [UID:0000B4] / [UID:0000JP].
- Decision: use as support/source-declaration owner, not direct owner for this concrete by-memory target. Add reusable `Resize` behavior to these docs.

### 3. [UID:00005O] / [UID:0000JP] `GameServerConfig`

- Evidence for: parser caller, `NationEntry` type, global table lifecycle, and generated output route are all in `GameServerConfig.cpp`; map/server table owns the concrete records.
- Evidence against: target `ecx` is the embedded protected-array object and the field layout is `ProtectedArray`, not outer `GameServerConfig`.
- Decision: keep as feature/file route only. Do not set target canonical owner directly to `GameServerConfig`.

### 4. Runtime / CRT / MemoryMan Utility

- Evidence for: callees are runtime allocation, memmove, and free.
- Evidence against: consumer code and fields are project-owned; runtime callees are dependencies, not owners. It does not call MemoryMan `operator new` / `operator delete` wrappers.
- Decision: reject as owner. Document the runtime helpers as dependencies and do not hand-port them in this target.

## Negative Evidence Summary

- No split evidence: local bytes show padding before and after; no internal unrelated body or tail.
- No merge evidence: predecessor [UID:000233] ends at `0x00514edd`; successor [UID:000235] starts at `0x00514f70`; five bytes of padding separate successor.
- No scalar-delete evidence: no delete flag parameter, vtable store, object delete, base cleanup, or guard-check path in target.
- No direct `GameServerConfig` method evidence: caller passes `this+4`, and target reads/writes protected-array member offsets.
- No `Reserve` evidence: target stores requested count in `+0x04`.
- No MemoryMan allocation evidence: target calls `0x005c7790`, not [UID:000196] `0x004f4aa0`.
- No alternate route found locally: PE rel32 scan found only parser call `0x00503d4f`; absolute VA dword scan found no `0x00514ee0` data pointer.

## First-Draft C++ Recommendation

Use this for the target C++ block if the supervisor accepts concrete template-instantiation bodies on by-memory pages:

```cpp
void ProtectedArray<GameServerConfig::NationEntry>::Resize(int count)
{
    if (count <= 0 || count == m_count)
        return;

    GameServerConfig::NationEntry* entries = new GameServerConfig::NationEntry[count];

    if (m_entries != NULL) {
        int copyCount = m_count;
        if (count < copyCount)
            copyCount = count;

        memmove(entries, m_entries, copyCount * sizeof(GameServerConfig::NationEntry));
        delete [] m_entries;
    }

    m_entries = entries;
    m_count = count;
}
```

Required support declaration for [UID:0001UP] / `GameServerConfig::NationEntry`:

```cpp
struct GameServerConfig::NationEntry
{
    NationEntry()
        : nationId((unsigned short)-1)
    {
    }

    unsigned short nationId;
    wchar_t label[33];
};
```

Why this is source-style and binary-supported:

- `new NationEntry[count]` explains the compiler-emitted overflow-aware `sizeof(NationEntry) * count` allocation and the constructor loop that stores `-1` at each first word.
- `memmove` matches the overlap-safe prefix copy.
- `delete [] m_entries` matches the free path for a POD/trivial-destructor array in this binary.
- The code intentionally does not update `+0x0c`; reviewed binary does not update it.
- The code intentionally does not clear on `count <= 0`; reviewed binary exits unchanged.

If the supervisor instead decides that template-source bodies should be emitted only from [UID:0000MU] `ProtectedArray`, keep the target C++ block blank and add the same body as `template <class T> void ProtectedArray<T>::Resize(int count)` in the support template doc/source route. I do not recommend leaving the target blank as an unresolved blocker; the only remaining question is output policy for concrete template-instantiation bodies versus reusable template body placement.

## Recommended Exact Target Doc Changes

### Metadata

Recommended target metadata after implementation:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000B4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000B4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Title / Status

Replace the "source emission may be a template instantiation" blocker with:

```markdown
- Source-quality decision: concrete `ProtectedArray<GameServerConfig::NationEntry>::Resize(int count)` instantiation emitted from the reusable `ProtectedArray<T>::Resize` template body.
- Direct semantic owner: [UID:0000B4][ProtectedArray_struct_GameServerConfig__NationEntry_](by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md).
- Source route: reusable template declaration/body through [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) / [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md), concrete feature instantiation/output through [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md).
- First-draft C++: ready, with the `NationEntry` default constructor/default initializer support noted on [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md).
```

### Behavior Additions

Add or revise behavior notes:

```markdown
The helper is a positive-count resize. It exits unchanged when `count <= 0` or when `count == m_count`. When resizing, it allocates a new `GameServerConfig::NationEntry[count]` array, default-initializes each new record's `nationId` to `-1`, copies `min(oldCount, count)` complete records from the old dynamic array with `_memmove`, frees the old dynamic array, then stores the new pointer and count.
```

### Field Table Replacement

Recommended field table:

```markdown
| Offset / value | Source-facing name | Meaning | Evidence |
| --- | --- | --- | --- |
| object offset `+0x00` | vtable | Concrete `ProtectedArray<GameServerConfig::NationEntry>` vtable. | Vtable child [UID:0003II] and constructor/destructor stores. |
| object offset `+0x04` | `m_count` | Active dynamic entry count. | Target compares this against requested count and overwrites it after resize. |
| object offset `+0x08` | `m_entries` | Dynamic `GameServerConfig::NationEntry*` storage. | Target copies from, frees, and replaces this pointer. |
| object offset `+0x0c` | `m_reservedCount` / provisional `m_defaultCapacity` | Constructor-initialized value `10`; not used by this resize body. | Constructor docs write `0x0a` / 10 (Verified with int_convert.py); resize/accessor/destructor bodies do not read or write it. |
| object offset `+0x10` | `m_defaultEntry` | Inline fallback/default record returned by accessors when index is out of range. | Accessor docs and parser/seeder fallback paths use outer `GameServerConfig + 0x14`. |
| element offset `+0x00` | `NationEntry::nationId` | 16-bit id, default constructed to `-1`. | Target initialization loop writes first word of each newly allocated `0x44` / 68-byte record (Verified with int_convert.py). |
| element offset `+0x02` | `NationEntry::label[33]` | Wide label storage. | Parser/seeder/copy docs and `0x21` / 33-wide-character copies (Verified with int_convert.py). |
```

### C++ Block

Populate with the first-draft C++ shown above unless the supervisor elects support-template-only emission. If support-template-only emission is chosen, explicitly add a target reconstruction note saying:

```markdown
Formal target C++ intentionally remains blank only because this exact binary body is generated from the reusable `ProtectedArray<T>::Resize` template body. The source body should be emitted through the `ProtectedArray` support route, while this page documents the concrete `GameServerConfig::NationEntry` instantiation, range, and caller evidence.
```

### Change Log Addition

```markdown
- 2026-06-19 B008 source-quality report: recommended `84/90 -> 88/92`, resolved the body as concrete `ProtectedArray<GameServerConfig::NationEntry>::Resize(int count)` emitted from reusable `ProtectedArray<T>::Resize`, kept direct owner/emitter [UID:0000B4], documented the `GameServerConfig` feature route and `ProtectedArray` template-source split, confirmed by local PE/Capstone exact range/padding/callers/callees after IDA MCP was unavailable, rejected reserve/handwritten/helper/scalar-delete interpretations, and provided first-draft C++ plus support requirements for `NationEntry` default construction and provisional `+0x0c` naming.
```

## Recommended Support Doc Changes

### [UID:0000B4] `ProtectedArray_struct_GameServerConfig__NationEntry_`

- Raise from `85/88` to `87/90` after adding this source-shape decision.
- Method table row should be:

```markdown
| [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) | `Resize(int count)` | Concrete `ProtectedArray<GameServerConfig::NationEntry>` instantiation of the reusable `ProtectedArray<T>::Resize` body; positive-count resize with `NationEntry` default id initialization, prefix preservation, and dynamic array replacement. |
```

- Add ownership note:

```markdown
The direct documentation parent for the concrete binary helper is this specialization. The reusable source body belongs to [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) / [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md); the concrete instantiation is emitted in the [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) map/game-server source route because the only caller and record type are feature-local.
```

### [UID:0000MU] `ProtectedArray`

- Add `Resize(int count)` to the file role/common behavior:

```markdown
`ProtectedArray<T>::Resize(int count)` is a positive-count dynamic-array replacement helper. It exits for `count <= 0` or unchanged count, array-allocates `T[count]`, lets `T` default construction initialize new slots, preserves `min(oldCount, count)` existing records with `memmove`, releases the old array, and updates `m_entries` / `m_count`. [UID:000234] is the concrete `GameServerConfig::NationEntry` emitted instantiation of this source body.
```

- Keep original header basename caveat. Do not create one source file per generated `ProtectedArray_struct_*` class.

### [UID:0001WR] `ProtectedArrayTemplates`

- Add a common behavior row:

```markdown
| Positive-count resize | `0x00514ee0` and inline default-seeder copy at `0x00503b60` | Allocates `T[count]`, default-initializes new elements, preserves the overlapping old prefix with `memmove`, frees old storage, and updates `m_entries` / `m_count`; concrete `NationEntry` stride is `0x44` / 68 bytes (Verified with int_convert.py). |
```

- Update instantiation evidence:

```markdown
| `ProtectedArray<GameServerConfig::NationEntry>` | - | - | `0x00514d50` | `0x00514ee0` | [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) |
```

### [UID:0001VM] `ProtectedArrayLayout`

- Keep `+0x0c` unresolved but upgrade wording from generic blocker to checked limitation:

```markdown
`+0x0c` is constructor-initialized to `0x0a` / 10 (Verified with int_convert.py) for the `GameServerConfig::NationEntry` specialization. The reviewed resize, accessor, and destructor bodies do not use it, so the safest source-quality spelling is provisional `m_reservedCount` or `m_defaultCapacity`; do not call it ordinary current capacity until a body that updates or tests it is found.
```

### [UID:0001UP] `GameServerNationEntry`

- Add source-style constructor/default note:

```markdown
The resize helper's per-element first-word initialization is best represented as an inline default constructor or default member initializer.

The constructor/default initializer is inferred from the array-new lowering in [UID:000234]; the label buffer is populated later by parser/seeder paths and is not zeroed by the reviewed resize body.
```

- Include this constructor snippet if the support doc accepts source-style member declarations:

```cpp
GameServerConfig::NationEntry::NationEntry()
    : nationId((unsigned short)-1)
{
}
```

- Keep type name caveat as medium confidence: nested `GameServerConfig::NationEntry` is the strongest generated/source-facing spelling, but original source may have used a local `NationEntry` nested declaration.

### [UID:00005O] / [UID:0000JP] `GameServerConfig`

- Clarify in method inventory:

```markdown
[UID:000234] is not a handwritten outer `GameServerConfig` method. It is the concrete `ProtectedArray<GameServerConfig::NationEntry>::Resize(int count)` instantiation called by `GameServerConfig::ParseNationEntries` with `ecx = this + 4`. It still belongs in the `GameServerConfig.cpp` feature route because the only caller, record type, global lifecycle, and concrete vtable are map/game-server nation-table owned.
```

### [UID:0002HY] Default Seeder

- Add a cross-note:

```markdown
The seeder inlines the same resize algorithm for constant count `2` rather than calling [UID:000234]. This supports the template/source-body inference for `ProtectedArray<T>::Resize` and should not be treated as a separate allocation helper design.
```

## Score / Metadata Recommendation

- Target [UID:000234]: `84/90 -> 88/92`.
  - Completion increases because the report resolves the source shape, field names used by the target, allocator/copy/free source equivalents, caller/reachability, no-split/no-merge boundaries, scalar-delete/EH exclusion, owner split, and first-draft C++ readiness.
  - Confidence increases modestly because raw PE/Capstone reconfirmed exact facts and existing IDA docs already supported them. It stays below final-audit range because IDA MCP was unavailable this session, original header basename is inferred, and `+0x0c` original field spelling is still not provable.
- Owner/emitter: keep `CANONICAL_OWNER:0000B4`, `EMITTER_UIDS:0000B4`.
- Reconstructable: keep `TRUE`.
- C++: ready for first-draft source if concrete-instantiation target code is accepted; otherwise the same body should be support-template emission, not a blocker.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` in this pass. Recommended exact replacement row for the current [UID:000234] row:

```markdown
    - [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) 0x00514ee0-0x00514f6b | template helper | ProtectedArray<GameServerConfig::NationEntry>::Resize : reconstructable : 88% : very strong : B008 source-quality recheck resolves this as the source-authored `ProtectedArray<T>::Resize(int count)` body emitted for `GameServerConfig::NationEntry`; local PE/Capstone confirms exact `0x8b` / 139-byte range (Verified with int_convert.py), three-byte leading and five-byte trailing padding, sole parser caller at `0x00503d4f`, no VA/rel32 alternate route, runtime array allocation at `0x005c7790` with overflow sizing, `NationEntry` default id `-1` construction loop, `_memmove` prefix preservation, CRT free at `0x005c7799`, final `m_entries`/`m_count` stores, and no scalar-delete/EH/base-destructor content.
```

Placement context: replace line currently following the ignored padding row for `0x00514edd-0x00514ee0` and preceding [UID:000235] `0x00514f70-0x005151a9.MapPathDequeSupport`.

## Validator Needs

No validators were run because only this research report was created. If the supervisor accepts implementation, recommended validation sequence:

> Executable block R001 was removed from this report and preserved verbatim in [000234-GameServerNationEntryArrayResize-source-quality-removed.md](000234-GameServerNationEntryArrayResize-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If supervisor applies the coverage row, validate the coverage doc or run the normal supervisor coverage validation after that edit.

## IDA Rename / Type / Comment Recommendations

These are IDA-side recommendations only; no IDA DB changes were made.

| Item | Recommendation | Confidence |
| --- | --- | --- |
| `sub_514EE0` / `FUN_00514ee0` | Rename to `ProtectedArray_GameServerConfig_NationEntry_Resize` or equivalent IDA-safe spelling. | Very high |
| Prototype | `void __thiscall ProtectedArray_GameServerConfig_NationEntry_Resize(ProtectedArray_GameServerConfig_NationEntry *this, int count);` | Very high |
| `GameServerConfig_NationEntry` struct | `unsigned short nationId; wchar_t label[33];` size `0x44` / 68 bytes (Verified with int_convert.py). | Very high |
| Protected-array struct | `void *vftable; int m_count; GameServerConfig_NationEntry *m_entries; int m_reservedCount; GameServerConfig_NationEntry m_defaultEntry;` size `0x54` / 84 bytes for this specialization (Verified with int_convert.py). | High for offsets; medium for `m_reservedCount` original spelling. |
| Callsite `0x00503d4f` | Comment: `g_gameServerNationTable->entries.Resize(packetCount + 1)` or `ProtectedArray<GameServerConfig::NationEntry>::Resize(countPlusNeighborhood)`. | High |
| `0x005c7790` | Do not project-rename as MemoryMan. If local comment needed, mark as MSVC/CRT array allocation helper / `operator new[]` route. | Medium-high |
| `0x005c95b0` | Keep/confirm `_memmove`. | Very high |
| `0x005c7799` | Keep/confirm `j_j_j___free_base` / CRT free wrapper. | High |
| Target range comment | "Positive-count resize for concrete `ProtectedArray<GameServerConfig::NationEntry>`; default-constructs new `NationEntry` records with id -1, preserves overlapping prefix, replaces dynamic storage." | Very high |

## Open Questions With Attempted Resolution

- Original `ProtectedArray` header basename: checked [UID:0000MU], [UID:0001WR], `simroot_v2/util/ProtectedArray.h`, and generated output. Best source artifact remains `util/ProtectedArray.h`; exact original basename is not provable from binary. This does not block target owner or draft C++.
- Exact original name for `+0x0c`: checked constructor, target resize, accessors, destructor, parser/seeder, and layout docs. No reviewed body tests or updates the field after constructor initialization to `10`. Keep as provisional `m_reservedCount` / `m_defaultCapacity`; do not let this block target code because target does not touch it.
- Exact allocator helper original name: checked docs and local disassembly. `0x005c7790` is runtime/compiler allocation, historically `unknown_libname_19`, not feature-owned. Source should use `new[]`; exact internal CRT symbol does not block target source.
- `NationEntry` nested vs standalone spelling: checked generated names, type docs, parser/copy/resize support. Strongest current source spelling is nested `GameServerConfig::NationEntry`; if future source-tree cleanup promotes it to a file-local `GameServerNationEntry`, the resize body stays the same except for the type qualifier.

## Changed Files

Created only:

```text
source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/000234-GameServerNationEntryArrayResize-source-quality.md
```

No target, support, generated, or coverage docs were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/000234-GameServerNationEntryArrayResize-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"000234"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000234-GameServerNationEntryArrayResize-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/000234-GameServerNationEntryArrayResize-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000234"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
