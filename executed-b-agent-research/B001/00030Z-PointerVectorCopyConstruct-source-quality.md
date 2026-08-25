** TARGET-REPORT-UID:00030Z **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00030Z PointerVectorCopyConstruct Source-Quality Research

Assignment: `B001-goal2-pointer-vector-copy-construct-source-quality-00030Z-20260619`  
Agent: `Agent-B001`  
Date: `2026-06-19`  
Target: `[UID:00030Z] by-memory/0x00421290-0x00421301.PointerVectorCopyConstruct.md`  
Requested mode: report-only. No by-* documentation edits. No `by-memory/-coverage-report.md` edit.

## Finalized Report / Current Recommendation

Keep the current source owner and emitter route:

```text
CANONICAL_OWNER: 0000P3
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000P3
```

Recommended metadata after a future implementation pass incorporates this report into the target/support docs:

```text
COMPLETION: 87
CONFIDENCE: 89
CANONICAL_OWNER: 0000P3
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000P3
RECONSTRUCTION_CPP CODE: no standalone function body
```

The current `85/87` target state is defensible, but the target page is still shallow for source-quality purposes. Once this report's exact disassembly, caller inventory, field/type names, rejected alternatives, no-code proof, and coverage text are incorporated, `87/89` is justified. I do not recommend a higher score because the final original template declaration, concrete element typedefs, and header/source split are still not recovered.

Best source-quality role:

```text
PointerVectorCopyConstruct
```

Best source-facing interpretation:

```text
compiler-emitted / template-emitted copy constructor for a three-pointer vector header whose elements are 4-byte pointers
```

Best source placement:

```text
NexusTK/util/VectorHelpers.h
```

The validator-generated output route currently surfaces through:

```text
auto-generated/NexusTK/util/VectorHelpers.cpp
```

That `.cpp` file is a staging artifact for the documentation/emitter system. It is not proof that the original project had a handwritten `VectorHelpers.cpp` function body for this helper.

Final C++ decision: do not emit a standalone function body for this target yet. The exact no-code proof is below.

## Target

Target document:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00421290-0x00421301.PointerVectorCopyConstruct.md
```

Current metadata:

```text
UID: 00030Z
COMPLETION: 85
CONFIDENCE: 87
CANONICAL_OWNER: 0000P3
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000P3
RECONSTRUCTION_CPP CODE: blank
```

Current direct owner:

```text
[UID:0000P3] by-file/VectorHelpers.md
```

Current direct owner state:

```text
COMPLETION: 86
CONFIDENCE: 86
PROPOSED_RECONSTRUCTION_PATH: "NexusTK/util/"
CANONICAL_OWNER: FILE
```

Current generated output marker:

```cpp
// UID:00030Z | by-memory\0x00421290-0x00421301.PointerVectorCopyConstruct.md | Completion:85 | Confidence:87 | Empty Emitter Marker
```

## Supervisor Active Recheck

The user's 2026-06-19 prompt explicitly assigns this target and overrides the stale saved assignment in `Agent-B001/goal.md`. I followed the B-agent report-only rules:

- Read the active `Supervisor.md`, B001 goal notes, `by-structure.md`, and `inference_research.md`.
- Did not edit by-* documentation.
- Did not edit `by-memory/-coverage-report.md`.
- Created one report in `Agent-B001/research`.
- Included the required `## Heuristic / Inference Reanalysis And Validation` section.
- Included source-quality reanalysis, best-supported generated/helper names, fields/types/globals/placeholders, caller/reachability, owner/source placement, split/range decisions, open-question closure, C++ readiness/no-code proof, exact supervisor-owned coverage row text, and a target/support implementation checklist.

This target does not require a by-structure split. It is already an exact child function range split from the mixed parent aggregate `[UID:0002DR]`.

## Inference Research Guidance Check

I treated existing documentation as prior evidence, not as authority. The accepted facts come from:

- current target/support docs that cite live IDA checks from earlier agent passes;
- the current by-structure ownership/emitter rules;
- local read-only PE byte, call-target, pointer-pattern, padding, and disassembly checks run in this pass;
- generated coverage state and current generated output markers.

Key by-structure implications:

- `CANONICAL_OWNER` should be the direct semantic owner, not the nearest feature caller.
- `EMITTER_UIDS` is output routing and can be present even when formal C++ remains blank.
- A reconstructable item with a valid emitter route and average score over `85` is only minimally eligible for C++; it is not required to emit weak or misleading code.
- `00030Z` has `(85 + 87) / 2 = 86.0`, so it passes the mechanical code-entry gate.
- The helper is still blocked from formal C++ because a standalone `VectorHelpers.cpp` function body would misrepresent a compiler/template-emitted vector copy constructor whose final type declarations are unresolved.

## Heuristic / Inference Reanalysis And Validation

### What This Helper Is

Direct behavior proves this is a copy constructor / copy-initialization helper for a vector-like three-pointer header:

```text
destination + 0x00: begin pointer
destination + 0x04: end/current pointer
destination + 0x08: capacity/end-of-storage pointer

source + 0x00: begin pointer
source + 0x04: end/current pointer
source + 0x08: capacity/end-of-storage pointer
```

The element size is 4 bytes. Current source-quality interpretation is pointer slots, not scalar `uint32_t` values, because the confirmed callers copy entry pointer vectors and the helper's current project route is "pointer-vector copy/construct."

Best descriptive type names:

```text
PointerVectorHeader
PointerVector<T>
PointerSlotVector
```

Recommended documentation name:

```text
PointerVectorCopyConstruct
```

Recommended source-facing description:

```text
template-emitted copy constructor for a vector<T*>-style three-pointer storage header
```

Do not rename it back to `UInt32Vector_421290`. Older generated/Wave2 traces used `UInt32Vector` labels because the machine-code element width is 4 bytes, but the current caller and semantic evidence show pointer-vector use. A dword-width code pattern is not enough to claim unsigned integer value semantics.

### Generated / Placeholder Name Resolution

`sub_421290`:

- Best replacement: `PointerVectorCopyConstruct`.
- Confidence: strong descriptive, not original-proof.
- Reason: exact function behavior is copy construction for a three-pointer vector header; direct callers include pointer-vector and entry-vector contexts; no original symbol/PDB/source string exists.

`sub_421520`:

- Best replacement in this context: `AllocateAlignedDwordArray` or `VectorAllocateDwordStorage`.
- Confidence: strong descriptive, already documented by `[UID:0002E2]`.
- Reason: it allocates `count * 4` bytes, with MSVC-style 32-byte-aligned large allocation metadata.
- Rebuild classification: runtime/STL-style helper, not NexusTK-authored source body.

`sub_421500`:

- Best replacement in this context: `VectorTooLongThrow` / `MsvcVectorTooLong`.
- Confidence: strong descriptive, already documented by `[UID:0002E1]`.
- Reason: it reports `"vector<T> too long"` through runtime support and is noreturn.
- Rebuild classification: third-party/runtime or compiler/STL-generated support.

`_memmove_0` / `0x005c9b30`:

- Best replacement: `memmove`.
- Confidence: strong.
- Reason: target passes `(dest, sourceBegin, byteCount)` after allocating the destination buffer.

No target-local global variable is involved. All meaningful state is in the destination/source vector headers and in the allocator/throw/memmove callees.

### Field / Type Meaning Resolution

Destination object:

```text
ECX / EBX = destination vector header
```

Source argument:

```text
[EBP+8] / EDI = const source vector header pointer
```

Destination fields:

```text
dst + 0x00 = begin
dst + 0x04 = end
dst + 0x08 = capacityEnd
```

Source fields:

```text
src + 0x00 = begin
src + 0x04 = end
src + 0x08 = capacityEnd
```

Element and size:

```text
element width = 4 bytes
count = (src.end - src.begin) >> 2
byteCount = src.end - src.begin
max count = 0x3fffffff
```

The `0x3fffffff` maximum is the highest element count that keeps `count * 4` within the unsigned 32-bit byte range. If the count exceeds that threshold, the function calls the vector-too-long helper at `0x00421500`.

### Caller / Reachability Resolution

Reachability is resolved. This is not a raw/no-entry orphan helper.

Local PE direct-call scan found exactly six direct `call` instructions to `0x00421290`:

```text
0x00420179 -> 0x00421290
0x00421047 -> 0x00421290
0x004224b7 -> 0x00421290
0x004226fe -> 0x00421290
0x00422d65 -> 0x00421290
0x005c2c7b -> 0x00421290
```

Current documentation identifies those caller contexts as:

| Call site | Caller context | Meaning |
| --- | --- | --- |
| `0x00420179` | `[UID:0002DN] FittingRoomListPaneOnInputEvent` | Selection/cart path copies pointer-vector state while constructing or comparing selected fitting-room entries. |
| `0x00421047` | `[UID:00030R] FittingRoomItemEntryVectorInsert` | Deep-copies the nested pointer-vector at selection-entry source offset `+0xa8`. |
| `0x004224b7` | `[UID:0002EC] FittingRoomDialogItemStateResetCategoryEntries` | Copies a category node's entry-pointer vector before walking and freeing contained entries. |
| `0x004226fe` | `[UID:0000WV] ItemCatalog::GetItemByIndex` | Copies a category-node pointer vector before indexed lookup and cleanup. |
| `0x00422d65` | `[UID:0002E6] FittingRoomDialogItemStateLoadCategoryFromJson` | Copies/prepares the completed pending-entry pointer vector before category lookup insertion. |
| `0x005c2c7b` | `[UID:0003SC] WorldMapPaneConstructorAndNodeSetup` | Non-fitting-room caller proving the helper is shared container support, not fitting-room-local code. |

This caller spread is the strongest reason to keep the direct owner as `VectorHelpers` rather than `FittingRoom`, `FittingRoomListPane`, `FittingRoomDialogItemState`, `ItemCatalog`, or `WorldMapPane`.

### Owner / Source Placement Resolution

Best current direct owner:

```text
[UID:0000P3] VectorHelpers
```

Best current source placement:

```text
NexusTK/util/VectorHelpers.h
```

Why `VectorHelpers` wins:

- The helper body is generic three-pointer vector copy construction.
- The caller set crosses fitting-room and world-map code.
- It has no feature-specific strings, globals, fields, vtable slot, or object layout beyond the vector header.
- `by-file/VectorHelpers.md`, `by-meta/client_containers.md`, and `by-project-structure/proposed-source-tree.md` already model `VectorHelpers.h` as reusable utility/container support.
- Sibling pointer-vector helper `[UID:00030Q] PointerVectorGrowInsert` is also routed to `VectorHelpers`.
- Comparable vector helpers such as `UInt32Vector`, `VectorStorageFreeHelper`, and dword insert/grow helpers are treated as shared utility/template support rather than feature-owned code.

Rejected owner: `FittingRoom` / `FittingRoomListPane` / `FittingRoomDialogItemState`.

- Most callers are fitting-room-related, but consumer majority is not source ownership.
- The non-fitting-room `WorldMapPane` caller at `0x005c2c7b` is direct binary evidence against fitting-room-private ownership.
- The fitting-room callers use the helper for container mechanics, not for fitting-room-specific layout logic inside this function.

Rejected owner: `ItemCatalog`.

- `ItemCatalog::GetItemByIndex` calls this helper, but the helper is not specific to item catalog storage and has other callers.
- The call demonstrates a consumer, not a declaration owner.

Rejected owner: `WorldMapPane`.

- `WorldMapPane` proves cross-module reuse, but it has only one call site and no ownership signal over the helper declaration.

Rejected owner: `MsvcVectorThrowHelpers` / runtime allocator pages.

- `0x00421500` and `0x00421520` are runtime/STL-style support callees.
- `00030Z` is a concrete emitted vector copy constructor body used by game-owned source containers. It should be represented by source-level container declarations even if the low-level allocator/throw routines are runtime-generated.

Rejected model: `CANONICAL_OWNER:NONE` with multiple emitters.

- That model is appropriate for pooled constants or source items with no single declaration owner but proven multiple source-use contexts.
- Here the project already has a documented reusable utility container owner with a valid source path, and a single shared helper body is better represented as `VectorHelpers` support than duplicated into every caller's source module.
- Multiple emitter routing to all callers would likely generate duplicate helper bodies or comments in unrelated feature files, which is less faithful than a shared utility/header model.

### Split / Range Resolution

Keep the exact current range:

```text
0x00421290-0x00421301
```

No split is recommended:

- The normal return path ends with `ret 4` at `0x004212f9`.
- The overflow branch at `0x004212c1` targets `0x004212fc`, which calls the noreturn vector-too-long helper.
- The bytes `0x004212fc-0x00421301` are therefore part of this function, not tail padding.

No merge with predecessor:

- The predecessor `[UID:00030X] 0x00421260-0x00421290.WideFormatWrapper128` ends at `0x00421290`.
- It is a fixed-capacity wide formatting wrapper, not a vector copy helper.
- There is no padding between the predecessor return and this helper start, but source/body role still changes cleanly at `0x00421290`.

No merge with successor:

- `0x00421301-0x00421310` is fifteen bytes of `0xcc` padding.
- The next function begins at `0x00421310` in the separate `[UID:0000WT]` early SimpleUString/adjacent helper island.

### C++ Readiness Resolution

This target passes the numeric code-entry gate but should not receive a standalone function body yet.

Exact no-code proof:

1. The body is a compiler/template-emitted vector copy constructor shape, not a proven handwritten NexusTK helper.
2. There is no original source symbol, PDB, debug record, source path, or string breadcrumb for a standalone function.
3. The confirmed callers use the same 4-byte vector mechanics for multiple feature contexts. A single concrete element type cannot be chosen without lying about at least one caller.
4. The likely original source expressed typed containers at the caller/type level, such as fitting-room entry pointer vectors and world-map node/record vectors, rather than a manually named `PointerVectorCopyConstruct` function in a `.cpp`.
5. The direct owner `[UID:0000P3] VectorHelpers` itself documents `VectorHelpers.h` or compiler-emitted template support and says the generated `.cpp` placeholder should stay empty until final template/header shape is known.
6. The allocator and throw helpers used by the body are already classified as MSVC/Dinkumware runtime/STL-style support. A hand-authored helper that calls `AllocateAlignedDwordArray` and `VectorTooLongThrow` would be decompiler-shaped scaffolding, not plausible original mid-2000s source.
7. Comparable vector/template helper docs in this project keep C++ blank for the same source-shape reason even when behavior is clear.

Non-insertable explanatory shape:

```cpp
// Do not insert as formal reconstruction code yet.
// This is the binary shape of a vector<T*> copy constructor.
struct PointerVectorHeader {
    void** begin;
    void** end;
    void** capacityEnd;
};

PointerVectorHeader* CopyConstructPointerVector(
    PointerVectorHeader* dst,
    const PointerVectorHeader* src)
{
    dst->begin = 0;
    dst->end = 0;
    dst->capacityEnd = 0;

    const unsigned int count =
        static_cast<unsigned int>(src->end - src->begin);
    if (count != 0) {
        if (count > 0x3fffffff) {
            VectorTooLongThrow();
        }

        void** storage = AllocatePointerStorage(count);
        dst->begin = storage;
        dst->end = storage;
        dst->capacityEnd = storage + count;

        const size_t byteCount =
            reinterpret_cast<const char*>(src->end) -
            reinterpret_cast<const char*>(src->begin);
        memmove(dst->begin, src->begin, byteCount);
        dst->end = reinterpret_cast<void**>(
            reinterpret_cast<char*>(dst->begin) + byteCount);
    }

    return dst;
}
```

This shape is useful for documentation, but it should not be emitted as final project C++ because it invents helper/type names and moves compiler/template implementation details into a standalone source function.

If a future implementation callback wants to satisfy the no-code marker policy without adding a body, the only safe generated C++ content is a comment marker, for example:

```cpp
// Pointer-vector copy construction is represented by typed caller-owned vector declarations; no standalone VectorHelpers.cpp body is source-quality yet.
```

Do not emit the non-insertable `CopyConstructPointerVector` body unless the project explicitly chooses to create a compatibility shim and documents that as a deliberate divergence from likely original source.

## Evidence Standards Used

Evidence types used:

- current target documentation;
- current mixed parent aggregate documentation;
- `VectorHelpers`, `client_containers`, and proposed source-tree docs;
- sibling pointer-vector and vector-helper pages;
- fitting-room caller/support pages;
- world-map caller/support page;
- generated memory coverage and generated `VectorHelpers.cpp`;
- manual coverage row state;
- local read-only PE scan of bytes, sections, direct calls, pointer encodings, and disassembly.

IDA MCP status:

- The local MCP endpoint `http://127.0.0.1:13337/mcp` was not reachable in this session; PowerShell returned `Unable to connect to the remote server`.
- I therefore do not claim a fresh live-IDA query for this pass.
- Earlier project docs contain live IDA-backed findings for this target and support pages; this report validates them with a local raw PE scan and labels the evidence source accordingly.

## Local PE Recheck

Executable scanned read-only:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
```

PE facts:

```text
ImageBase = 0x00400000
.text VA = 0x00001000, raw pointer = 0x400, raw size = 0x20B600, virtual size = 0x20B4AC
.rdata VA = 0x0020D000, raw pointer = 0x20BA00, raw size = 0x5F200, virtual size = 0x5F0BE
Target VA = 0x00421290
Target RVA = 0x00021290
Target file offset = 0x20690
```

Exact target bytes:

```text
55 8B EC 53 56 8B D9 57 8B 7D 08
C7 03 00 00 00 00
C7 43 04 00 00 00 00
C7 43 08 00 00 00 00
8B 77 04 2B 37 C1 FE 02 85 F6 74 38
81 FE FF FF FF 3F 77 39
56 E8 57 02 00 00
89 03 89 43 04 8B 03 8D 04 B0
8B 75 08 89 43 08
8B 07 8B 3B 8B 76 04 2B F0
56 50 57 E8 46 88 1A 00
8D 04 3E 83 C4 0C 89 43 04
5F 5E 8B C3 5B 5D C2 04 00
E8 FF 01 00 00
```

Successor padding:

```text
0x00421301-0x00421310:
CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC
```

Exact target byte signature count in the executable:

```text
1
```

Local direct call scan:

```text
Direct calls to 0x00421290: 6
0x00420179
0x00421047
0x004224b7
0x004226fe
0x00422d65
0x005c2c7b
```

Pointer-pattern scan:

```text
VA/RVA encodings for 0x00421290: 0
VA/RVA encodings for 0x00421291: 0
VA/RVA encodings for 0x004212a0: 0
VA/RVA encodings for 0x00421300: 0
VA/RVA encodings for 0x00421301: 0
```

This negative pointer result does not weaken reachability because the six direct call sites are sufficient. It does confirm there is no obvious vtable/table/data-pointer route to the function start.

Debug/source breadcrumb scan:

```text
RSDS: 0
NB10: 0
.pdb/.PDB: 0
.cpp/.CPP: 0
.cxx/.CXX: 0
```

This supports the conclusion that original source file/function/type names are not directly recoverable from embedded debug/source metadata in this binary.

## Disassembly

Local Capstone disassembly of `0x00421290-0x00421301`:

```asm
0x00421290: push     ebp
0x00421291: mov      ebp, esp
0x00421293: push     ebx
0x00421294: push     esi
0x00421295: mov      ebx, ecx
0x00421297: push     edi
0x00421298: mov      edi, dword ptr [ebp + 8]
0x0042129b: mov      dword ptr [ebx], 0
0x004212a1: mov      dword ptr [ebx + 4], 0
0x004212a8: mov      dword ptr [ebx + 8], 0
0x004212af: mov      esi, dword ptr [edi + 4]
0x004212b2: sub      esi, dword ptr [edi]
0x004212b4: sar      esi, 2
0x004212b7: test     esi, esi
0x004212b9: je       0x004212f3
0x004212bb: cmp      esi, 0x3fffffff
0x004212c1: ja       0x004212fc
0x004212c3: push     esi
0x004212c4: call     0x00421520
0x004212c9: mov      dword ptr [ebx], eax
0x004212cb: mov      dword ptr [ebx + 4], eax
0x004212ce: mov      eax, dword ptr [ebx]
0x004212d0: lea      eax, [eax + esi*4]
0x004212d3: mov      esi, dword ptr [ebp + 8]
0x004212d6: mov      dword ptr [ebx + 8], eax
0x004212d9: mov      eax, dword ptr [edi]
0x004212db: mov      edi, dword ptr [ebx]
0x004212dd: mov      esi, dword ptr [esi + 4]
0x004212e0: sub      esi, eax
0x004212e2: push     esi
0x004212e3: push     eax
0x004212e4: push     edi
0x004212e5: call     0x005c9b30
0x004212ea: lea      eax, [esi + edi]
0x004212ed: add      esp, 0x0c
0x004212f0: mov      dword ptr [ebx + 4], eax
0x004212f3: pop      edi
0x004212f4: pop      esi
0x004212f5: mov      eax, ebx
0x004212f7: pop      ebx
0x004212f8: pop      ebp
0x004212f9: ret      4
0x004212fc: call     0x00421500
```

Direct callees:

| Address | Current best name | Role |
| --- | --- | --- |
| `0x00421520` | `AllocateAlignedDwordArray` / vector dword allocator | Allocates `count * 4` bytes with MSVC-style large-block alignment metadata. |
| `0x005c9b30` | `memmove` | Copies source bytes to destination storage. |
| `0x00421500` | `VectorTooLongThrow` | Noreturn vector length failure helper. |

## Documentation Evidence

Target page `[UID:00030Z]` already records:

- exact range `0x00421290-0x00421301`;
- IDA name `sub_421290`;
- source role as shared pointer-vector copy/construct helper;
- parent aggregate `[UID:0002DR]`;
- direct owner `[UID:0000P3] VectorHelpers`;
- six caller sites, including one non-fitting-room caller in `0x005c2ac0`;
- callees `[UID:0002E2] AllocateAlignedDwordArray`, `_memmove_0`, and `[UID:0002E1] MsvcVectorThrowHelpers`;
- following padding `0x00421301-0x00421310`;
- final C++ blank due unresolved concrete vector typedefs.

Parent aggregate `[UID:0002DR]` already records:

- `00030Z` as one exact child of a mixed helper island;
- no single source owner for the aggregate;
- `00030Z` and sibling `00030Q` routed to `VectorHelpers`;
- `00030R`/`00030T` routed to `FittingRoomListPane`;
- `00030V`/`00030X` routed to `StringUtil`;
- fifteen `0xcc` bytes after `0x00421301`;
- caller count `6` for `0x00421290`.

Owner file `[UID:0000P3] VectorHelpers` already records:

- proposed path `NexusTK/util/`;
- likely artifact `VectorHelpers.h` or compiler-emitted template support;
- pointer-vector insert/copy helpers as shared utility/template support;
- generated `.cpp` placeholder intentionally empty until final template/header shape is near-final.

Support docs `[UID:0002E1]` and `[UID:0002E2]` correctly keep vector throw/allocator helpers non-reconstructable runtime/STL-style support. `00030Z` depends on them but should not absorb them as NexusTK-authored source code.

## Function / Child Inventory

Relevant local helper-island inventory:

| Range | UID | Role | Direct owner | Status |
| --- | --- | --- | --- | --- |
| `0x00420de0-0x00420eea` | `00030Q` | pointer-vector grow/insert | `0000P3` VectorHelpers | reconstructable, blank C++ |
| `0x00420ef0-0x00421143` | `00030R` | fitting-room item-entry vector insert | `000053` FittingRoomListPane | reconstructable |
| `0x00421150-0x0042122b` | `00030T` | fitting-room item-entry move range | `000053` FittingRoomListPane | reconstructable |
| `0x00421230-0x0042125d` | `00030V` | wide format wrapper, 32 wchar | `0000OB` StringUtil | reconstructable |
| `0x00421260-0x00421290` | `00030X` | wide format wrapper, 128 wchar | `0000OB` StringUtil in current docs/generated state | reconstructable |
| `0x00421290-0x00421301` | `00030Z` | pointer-vector copy construct | `0000P3` VectorHelpers | reconstructable, blank C++ |
| `0x00421301-0x00421310` | ignored padding | `0xcc` alignment | none | padding |

The parent `[UID:0002DR]` should remain non-reconstructable/non-emitting as a mixed aggregate map.

## Ranked Ownership Analysis

### 1. `[UID:0000P3] VectorHelpers`

Decision: keep as direct owner and emitter.

Evidence for:

- Generic three-pointer vector copy behavior.
- Direct calls from fitting-room and world-map code.
- No feature-specific field access inside the helper.
- Existing project structure places reusable vector support under `NexusTK/util/VectorHelpers.h`.
- Sibling pointer-vector grow/insert helper routes here.
- The parent aggregate's exact children already use multiple owners, so this child should keep the shared vector route.

Evidence against:

- Original source may have been standard/template source emitted through caller modules rather than a handwritten utility file.
- The generated output route is `.cpp`, while the proposed source-tree artifact is likely `.h`.

Conclusion:

This is still the best existing documentation/source-placement owner. The caveat affects final C++ body readiness, not ownership.

### 2. Feature caller ownership: FittingRoom / FittingRoomListPane / FittingRoomDialogItemState / ItemCatalog

Decision: reject.

Evidence for:

- Five of the six direct call sites are fitting-room or item-shop related.
- The helper sits physically in a fitting-room-adjacent helper island.

Evidence against:

- The non-fitting-room `WorldMapPane` call proves cross-module use.
- The helper body is pure container mechanics.
- Physical address locality is already known to be misleading for `[UID:0002DR]`, which mixes VectorHelpers, StringUtil, and FittingRoomListPane children.

Conclusion:

These are consumers, not direct owners.

### 3. `[UID:0000PB] WorldMapPane` / `[UID:0000G9] WorldMapPane class`

Decision: reject.

Evidence for:

- One direct call at `0x005c2c7b` occurs inside the world-map constructor/setup range.

Evidence against:

- Single consumer only.
- No world-map-specific state inside this helper.
- The call is better explained as use of shared pointer-vector support.

Conclusion:

WorldMap is important negative evidence against fitting-room ownership, not a better owner.

### 4. Runtime/STL ignored helper ownership

Decision: reject as canonical owner for this target, while preserving runtime classification for callees.

Evidence for:

- The body is compiler/template-shaped and calls MSVC/Dinkumware-style vector allocation/throw helpers.

Evidence against:

- The target is a concrete emitted helper used by source-level game containers.
- The project already distinguishes runtime support helpers (`0002E1`, `0002E2`) from source-declared vector/template support (`00030Q`, `00030Z`, `0000FD`, `0002UD`).
- Reconstructing source containers must account for this behavior, even if the compiler eventually regenerates the exact helper body.

Conclusion:

Keep `RECONSTRUCTABLE:TRUE` as source-declared/generated-binary vector support; keep runtime callees non-reconstructable.

### 5. New source owner / new file

Decision: reject.

Possible new names considered:

```text
PointerVectorHelpers.h
StlVectorSupport.h
FittingRoomSelectionVectorHelpers.cpp
```

Why rejected:

- `VectorHelpers` already provides the correct reusable utility bucket.
- A fitting-room-specific file would be contradicted by the world-map caller.
- A new single-helper file would overfit one template-emitted body and create source-tree noise.
- If final source uses ordinary typed `std::vector<T*>` declarations, no new project-authored helper source file should exist.

## Negative Evidence Summary

Checked and rejected:

- `FittingRoom` ownership based only on address neighborhood.
- `FittingRoomListPane` ownership based only on one high-level caller.
- `ItemCatalog` ownership based on one indexed-lookup caller.
- `WorldMapPane` ownership based on the non-fitting-room call.
- Old `UInt32Vector_421290` naming based only on 4-byte element width.
- Emitting a standalone helper body based on decompiler-shaped pseudocode.
- Splitting off `0x004212fc-0x00421301` as padding; it is an overflow branch target and noreturn call.
- Merging with predecessor `WideFormatWrapper128`; the source role changes at `0x00421290`.
- Merging with successor `0x00421310`; fifteen `0xcc` bytes separate the functions.

## Open-Question Closure

Original helper name:

- Closed as not recoverable from current binary evidence.
- Best descriptive name is `PointerVectorCopyConstruct`.
- Score impact: caps confidence below final/source-name quality.

Concrete element type:

- Closed as intentionally generic for current documentation.
- The helper is a pointer-slot vector copy constructor used by multiple caller contexts; no single concrete `T` should be chosen at this target level.
- Score/C++ impact: blocks standalone formal C++ body.

Header/source split:

- Best inference is `VectorHelpers.h` / compiler-emitted template support under `NexusTK/util/`.
- The generated `.cpp` output is a validator staging route, not original-source proof.
- Score/C++ impact: owner/emitter remains valid, but formal code stays blank or comment-only.

Runtime helper meaning:

- Resolved through support docs.
- `0x00421520` is vector dword allocator support; `0x00421500` is vector-too-long throw support; both remain runtime/STL-style support rather than NexusTK-authored child bodies.

Caller/reachability:

- Resolved.
- Six direct call sites are confirmed by documentation and local PE scan.

Split/range:

- Resolved.
- Keep `0x00421290-0x00421301` exactly.

Coverage:

- Current manual row exists but is compact.
- Recommended exact replacement row is provided below.
- Sibling row `00030X` in the manual coverage block appears stale relative to current docs/generated coverage, but that is support/supervisor cleanup outside this target's exact row.

## Generated / Coverage State

Generated coverage row currently says:

```text
| [UID:00030Z][0x00421290-0x00421301.PointerVectorCopyConstruct](by-memory/0x00421290-0x00421301.PointerVectorCopyConstruct.md) | emits | `0000P3` | `0000P3` |  | no | `auto-generated/NexusTK/util/VectorHelpers.cpp` | `by-memory/0x00421290-0x00421301.PointerVectorCopyConstruct.md` |  |
```

Current generated coverage totals observed:

```text
Total_Reconstructable: 3050
Total_Reconstructable_Routed: 3027
Total_Reconstructable_NoOwner: 20
Total_Reconstructable_NoOwner_Emitters: 11
Total_Reconstructable_Emits: 3038
Total_Reconstructable_Emitters_NoCode: 2763
Total_Reconstructable_NonEmits: 12
Total_Reconstructable_MultipleEmitters: 11
```

Project-level completion stats row:

```text
| `00030Z` | 85 | 87 | 86.0 | `by-memory/0x00421290-0x00421301.PointerVectorCopyConstruct.md` |
```

Current manual coverage row observed in `by-memory/-coverage-report.md`:

```text
            - [UID:00030Z][0x00421290-0x00421301.PointerVectorCopyConstruct](by-memory/0x00421290-0x00421301.PointerVectorCopyConstruct.md) 0x00421290-0x00421301 | helper-function | PointerVectorCopyConstruct : reconstructable : 85% : strong : Assigned to VectorHelpers (0000P3); shared three-pointer vector copy/construct helper with fitting-room and non-fitting-room callers and following 0x00421301-0x00421310 padding.
```

## Exact Supervisor-Owned Coverage Row Text

Recommended replacement row for supervisor-owned `by-memory/-coverage-report.md`, at the same nested location under `[UID:0002DR]`, after the `[UID:00030X]` row and before the successor aggregate:

```text
            - [UID:00030Z][0x00421290-0x00421301.PointerVectorCopyConstruct](by-memory/0x00421290-0x00421301.PointerVectorCopyConstruct.md) 0x00421290-0x00421301 | helper-function | PointerVectorCopyConstruct : reconstructable : 87% : strong : B001 2026-06-19 source-quality reanalysis keeps the shared VectorHelpers owner/emitter route (`0000P3`) for this pointer-vector copy-construction helper. Local PE recheck reconfirmed the exact `0x00421290-0x00421301` range, unique target byte signature, normal `ret 4` path plus `0x004212fc` vector-too-long branch, fifteen-byte `0xcc` successor padding at `0x00421301-0x00421310`, six direct callers at `0x00420179`, `0x00421047`, `0x004224b7`, `0x004226fe`, `0x00422d65`, and non-fitting-room `WorldMapPane` caller `0x005c2c7b`, and no VA/RVA pointer encodings for the helper start. The body zeroes the destination three-pointer vector header, computes `(src.end - src.begin) >> 2`, calls the shared dword allocator `0x00421520`, copies the source pointer span with `memmove` at `0x005c9b30`, updates begin/end/capacity, and calls `0x00421500` for `vector<T> too long`; keep formal C++ body blank or comment-only until the final template/header declaration and concrete caller-owned vector typedefs are source-quality.
```

If the supervisor does not accept the recommended `87/89` target score increase yet, keep the current row's `85%` value but replace the body text with the same evidence summary adjusted to say `keeps score 85/87`.

I did not edit `by-memory/-coverage-report.md`.

## Target / Support Implementation Checklist

Future implementation callback checklist:

- Target `[UID:00030Z]`: update metadata to `COMPLETION:87`, `CONFIDENCE:89`, keep `CANONICAL_OWNER:0000P3`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000P3`.
- Target `[UID:00030Z]`: keep the range `0x00421290-0x00421301`; explicitly document that `0x004212fc-0x00421301` is the overflow branch's noreturn call, not padding.
- Target `[UID:00030Z]`: replace `sub_421290` language with `PointerVectorCopyConstruct` as the best descriptive helper name; retain `sub_421290` only as a historical/search label.
- Target `[UID:00030Z]`: document vector header fields as `begin`, `end`, and `capacityEnd` at offsets `+0x00/+0x04/+0x08` for both destination and source.
- Target `[UID:00030Z]`: document `ECX` as the destination vector header and `[EBP+8]` as the source vector header pointer.
- Target `[UID:00030Z]`: document element width as 4-byte pointer slots, with `count = (src.end - src.begin) >> 2` and `byteCount = src.end - src.begin`.
- Target `[UID:00030Z]`: document callees as `0x00421520` vector dword allocator, `0x005c9b30` `memmove`, and `0x00421500` vector-too-long helper.
- Target `[UID:00030Z]`: document the six direct call sites and their caller contexts, especially the non-fitting-room `WorldMapPane` call at `0x005c2c7b`.
- Target `[UID:00030Z]`: document rejected owners: FittingRoom/FittingRoomListPane/FittingRoomDialogItemState, ItemCatalog, WorldMapPane, runtime/STL ignored helper pages, no-owner/multiple-emitter model, and new source file creation.
- Target `[UID:00030Z]`: document the exact no-code proof. Do not insert a standalone `CopyConstructPointerVector` body.
- Target `[UID:00030Z]`: if the supervisor wants a Rule 28 no-code marker, use only a comment explaining that typed caller-owned vector declarations represent this helper; otherwise keep `RECONSTRUCTION_CPP CODE` blank.
- Support `[UID:0000P3] VectorHelpers`: add the source-quality note that `00030Z` is a pointer-slot vector copy constructor with six direct callers and that final source likely belongs in `VectorHelpers.h` or typed caller-owned template declarations, not a handwritten `.cpp` body.
- Support `[UID:0002DR]`: update the `00030Z` child row/notes with the new score and the exact source-quality summary if the target score changes.
- Support generated-output review: expect `auto-generated/NexusTK/util/VectorHelpers.cpp` to remain an empty marker or comment-only marker for this UID; do not add a helper body there.
- Supervisor coverage: replace the manual coverage row with the exact row text above if accepting the score/evidence update.
- Validation after future documentation edits: run scoped validator file mode with `--apply` on the target page, `by-file/VectorHelpers.md`, and `0002DR`; then inspect generated coverage/autogen output for `00030Z`.

Suggested future validator commands if edits are applied:

> Executable block R001 was removed from this report and preserved verbatim in [00030Z-PointerVectorCopyConstruct-source-quality-removed.md](00030Z-PointerVectorCopyConstruct-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Final Recommendation

Do not change owner/source placement. `VectorHelpers` remains the best direct semantic owner and output route for `00030Z`.

Do improve the target/source-quality documentation and raise the target to `87/89` after incorporating the evidence in this report.

Do not emit a standalone C++ helper body. This is a source-declared/generated-binary vector/template artifact. Final source should express typed containers in caller/type declarations and let the toolchain produce the helper, or use a deliberately documented compatibility shim only if the project later chooses that approach.

## Confidence

Recommendation confidence: strong.

Strong facts:

- Exact range and bytes.
- Direct caller set.
- Source/callee behavior.
- Successor padding.
- Cross-module caller evidence.
- Correctness of `VectorHelpers` as the current shared utility parent.

Remaining uncertainty:

- Original function/helper name is not recoverable.
- No single concrete `T` can be chosen for the vector element type at this target level.
- Final source may use `std::vector<T*>`, a project vector wrapper, or recovered `VectorHelpers.h` declarations.
- The generated `.cpp` route is documentation infrastructure, not original-source proof.

Score impact:

- These uncertainties block `90+` and formal C++ body insertion.
- They do not block owner/emitter routing or a modest score increase once this detail is incorporated.

## Validator Results

No by-* docs were edited in this report-only pass, so no documentation validator was run for changed by-* files.

Checks performed:

- Read active supervisor/B001 instructions.
- Read target `[UID:00030Z]`.
- Read direct owner `[UID:0000P3] VectorHelpers`.
- Read parent aggregate `[UID:0002DR]`.
- Read sibling/support vector helper pages `[UID:00030Q]`, `[UID:0002E1]`, `[UID:0002E2]`, `[UID:0000FD]`, `[UID:0001B2]`, and `[UID:0002UD]`.
- Read caller/support pages for fitting-room and world-map call contexts.
- Read `client_containers` and proposed source-tree VectorHelpers placement.
- Checked generated coverage and generated output marker.
- Checked current manual coverage row.
- Attempted live MCP tool list; endpoint unavailable.
- Performed local PE byte/disassembly/direct-call/pointer-pattern/debug-breadcrumb scan.

## Changed Files

Created this report only:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\00030Z-PointerVectorCopyConstruct-source-quality.md
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00030Z-PointerVectorCopyConstruct-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:22","uid":"00030Z"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00030Z-PointerVectorCopyConstruct-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00030Z-PointerVectorCopyConstruct-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00030Z"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
