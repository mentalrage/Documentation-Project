** TARGET-REPORT-UID:0002IN **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# Agent-B001 Report: [UID:0002IN] ImageLibConstructor Source Quality

Agent: B001  
Date: 2026-06-27  
Assignment id: `B001-report-0002IN-ImageLibConstructor-source-quality-20260627`  
Mode: report-only research first  
Target: [UID:0002IN] `by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md`  
Required report path: `tools/leaser/Agents/Agent-B001/research/0002IN-ImageLibConstructor-source-quality.md`

## Final Recommendation

Raise the target from `85/90` to `91/92`, keep `CANONICAL_OWNER:00006E`, keep `EMITTER_UIDS:00006E`, keep `RECONSTRUCTABLE:TRUE`, and insert formal first-draft constructor C++ in `RECONSTRUCTION_CPP CODE`.

The rework resolves the previously named no-code blockers far enough for a defensible formal first draft. Live IDA confirms the constructor range, caller, vtable/global writes, field stores, list allocation, failure path, and unique signature. The important correction is the stack-argument order at the sole constructor call site: `sub_4639D0` pushes `0x4e20` first and `0x0f4240` second, so the callee stack slot `[ebp+8]` that the constructor stores at object offset `+0x08` receives `0x0f4240` / `1000000` in the only known call. The second callee argument `[ebp+0x0c]` is `0x4e20` / `20000` and is not consumed in the recovered body.

The target and support docs should be updated to make that distinction explicit and to close the prior no-code gap. The best-supported source shape is an `ImageLib::ImageLib(int cacheLimit, int)` constructor: the first callee parameter initializes inferred `m_cacheLimit` at `+0x08`; the second parameter is deliberately left unnamed in the definition because the ABI requires it and the complete constructor body plus the sole caller prove it is unused here; `+0x04` is inferred `m_refCount`; `+0x0c` is B006-supported `m_pEntryList`; and `+0x10` is inferred `m_maxCacheSize`.

## Current Target State

Target metadata currently says:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `85` |
| `CONFIDENCE` | `90` |
| `CANONICAL_OWNER` | `00006E` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `00006E` |
| Formal C++ | blank |
| Item summary | Constructs `g_pEPFLib`, installs the vtable, stores constructor state, and allocates `List::List(44, 10)`. |

Current blocker text on the target is valid in broad shape: IDA decompiles a two-stack-argument thiscall constructor and the second argument is not obviously used. The missing source-quality detail is exact argument order and value mapping:

- Caller instruction order is `push 0x4e20`, then `push 0x0f4240`, then `mov ecx, eax`, then call.
- Because x86 stack arguments are consumed in reverse push order, callee `[ebp+8]` / IDA `Block` is `0x0f4240`, not `0x4e20`.
- The constructor stores `[ebp+8]` to `this + 0x08`.
- The constructor also writes literal `0x0f4240` to `this + 0x10`.
- The unused second callee argument `[ebp+0x0c]` is `0x4e20`.

The current page also records a 2026-06-16 C001 IDA label sync (`ImageLib_Constructor`, `g_pEPFLib`, `ImageLib_vftable`). The live IDA session used for this report currently returns raw names (`sub_4CFFB0`, `dword_67A744`, `off_61B654`) through `lookup_funcs`, `decompile`, `disasm`, and `xrefs_to`. This should be documented as current-session label state, not manually repaired by this report-only pass.

## Evidence Checked

Project instructions and workflow:

- `tools/leaser/Agents/Agent-B001/goal.md`
- `tools/leaser/Agents/Agent-B001/notes.md`
- project-level `ntk-b-agent-workflow` skill
- `references/b-agent-research-and-implementation-workflow.md`
- `references/supervisor-rule26-review-and-incorporation-standard.md`

Target and support docs checked:

- `by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md`
- `by-class/ImageLib.md`
- `by-file/ImageLib.md`
- `by-type/by-struct/ImageLibLayout.md`
- `by-type/by-vtable/ImageLibVtable.md`
- `by-global/g_pEPFLib.md`
- `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md`
- `by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md`
- `by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md`
- `by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md`
- `by-memory/0x004639d0-0x00464a52.ApplicationInitialize.md`
- `by-memory/0x004f3060-0x004f30d5.ListConstructor.md`
- `by-class/List.md`
- `by-file/List.md`
- `by-memory/0x004f4a80-0x004f4a89.LObjectConstructor.md`
- `by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md`
- `by-class/ResourceLayoutTable.md`
- `by-file/ResourceLayoutTable.md`
- `by-type/by-struct/ResourceLayoutNameRecord.md`
- `by-type/by-struct/ResourceLayoutStore.md`
- `by-type/by-struct/ResourceLayoutBucket.md`
- `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md`
- `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md`
- `by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md` current B006 implementation state
- `by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md` current destructor-wrapper state

Generated and executed-report evidence checked as read-only inputs:

- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/NexusTK/render/ImageLib.cpp`
- `executed-b-agent-research/B008/000191-ListConstructor-source-quality.md`
- executed constructor reports for nearby image-library constructors, including B003/B005/B011 cases where the first-draft C++ gate was either deferred or accepted based on source-contract readiness.

Numeric values were verified with `tools/int_convert.py`:

- `0xbf` = `191` (Verified with int_convert.py)
- `0xab` = `171` (Verified with int_convert.py)
- `0xd2` = `210` (Verified with int_convert.py)
- `0x4e20` = `20000` (Verified with int_convert.py)
- `0x0f4240` = `1000000` (Verified with int_convert.py)
- `0x2c` = `44` (Verified with int_convert.py)
- `0x0a` = `10` (Verified with int_convert.py)
- `0x14` = `20` (Verified with int_convert.py)

## Live IDA MCP Evidence

IDA MCP was available and used. I did not edit the IDA database.

Live MCP provenance:

| Item | Value |
| --- | --- |
| Endpoint | `http://127.0.0.1:13337/mcp` |
| Initial report MCP session | `df0f84f2-514c-42fa-89ff-b9b7c67331f5` |
| Active database | `80de0a67` |
| IDB path | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Module | `NexusTK.exe` |
| Image base | `0x400000` |
| `server_health` | `status: ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, string cache size `2067` |

Rework live MCP recheck after supervisor rejection:

- `initialize` and `tools/list` succeeded against `http://127.0.0.1:13337/mcp`.
- `idb_list` returned active database/session `80de0a67`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `26892`, `is_analyzing:false`.
- Explicit JSON `server_health(database=80de0a67)` returned `status:ok`, uptime about `273490.998` seconds, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, string cache size `2067`.
- Explicit JSON `lookup_funcs(database=80de0a67, queries=[0x004cffb0,0x004d0120,0x004d17c0])` returned `sub_4CFFB0` size `0xbf`, `sub_4D0120` size `0x1c5`, and `sub_4D17C0` size `0x6f`.
- A malformed local PowerShell wrapper call returned "database is required"; this was a request-shape issue, not MCP unavailability, and the explicit JSON retry succeeded.

The first focused MCP batch hit a schema error because the current server requires `database=80de0a67` on each tool call and several tools use singular `addr` / byte `regions`. I retried with the current schema and got successful IDB-backed results. This is not an MCP-unavailable condition.

Function inventory from current MCP:

| Query | Result |
| --- | --- |
| `0x004cffb0` | `sub_4CFFB0`, size `0xbf` / `191` (Verified with int_convert.py) |
| `0x004d006f` | not a function |
| `0x004d0070` | `sub_4D0070`, size `0xab` / `171` (Verified with int_convert.py) |
| `0x004639d0` | `sub_4639D0`, size `0x1082` |
| `0x004f4a80` | `sub_4F4A80`, size `0x9` |
| `0x004f4aa0` | `sub_4F4AA0`, size `0x14` / `20` (Verified with int_convert.py) |
| `0x004f3060` | `sub_4F3060`, size `0x75` |
| `0x0061b654` | not a function |
| `0x0067a744` | not a function |

`analyze_function(database=80de0a67, addr=0x004cffb0)` returns:

- Name: `sub_4CFFB0`
- Prototype shape: `_DWORD *__thiscall(_DWORD *this, void *Block, int)`
- Size: `191`
- Callers: `sub_4639D0`
- Callees: `sub_4F4A80`, `sub_4F4AA0`, `sub_4F3060`
- Direct code xref to constructor: `0x004644f4`
- Decompiler behavior: call base helper, set or clear `dword_67A744`, install `off_61B654`, store `Block` at `this[2]`, clear `this[1]`, set `this[4] = 1000000`, allocate `20`, call `sub_4F3060(v4, 44, 10)`, store the result at `this[3]` or null on allocation failure.

`disasm(database=80de0a67, addr=0x004cffb0)` confirms the behavior-relevant instructions:

| Address | Instruction / meaning |
| --- | --- |
| `0x004cffd9` | `call sub_4F4A80` base constructor/setup |
| `0x004cffde` | `lea ecx, [esi+4]` |
| `0x004cffef` | `mov dword_67A744, eax` after `eax = ecx - 4`, so normal path publishes `this` |
| `0x004cfff6` | `mov dword_67A744, 0` on defensive null-adjusted path |
| `0x004d0000` | `mov eax, [ebp+Block]`, first callee stack argument |
| `0x004d0003` | `push 14h`, allocation size `20` (Verified with int_convert.py) |
| `0x004d0009` | `mov dword ptr [esi], offset off_61B654`, vtable write |
| `0x004d000f` | `mov [esi+8], eax`, store first callee stack argument |
| `0x004d0012` | `mov dword ptr [ecx], 0`, clear offset `+0x04` |
| `0x004d0018` | `mov dword ptr [esi+10h], 0F4240h`, literal `1000000` (Verified with int_convert.py) |
| `0x004d001f` | `call sub_4F4AA0`, allocation wrapper |
| `0x004d0032` | `push 0Ah`, list page count `10` (Verified with int_convert.py) |
| `0x004d0034` | `push 2Ch`, list element size `44` (Verified with int_convert.py) |
| `0x004d0038` | `call sub_4F3060`, `List::List(44, 10)` |
| `0x004d003d` | `mov [esi+0Ch], eax`, store constructed list pointer |
| `0x004d0051` | `retn 8`, two stack arguments |
| `0x004d0054` | allocation-failure path stores null at `+0x0c` |
| `0x004d006c` | second `retn 8` |

`disasm(database=80de0a67, addr=0x004644d0)` confirms the sole caller route inside `sub_4639D0`:

| Address | Instruction / meaning |
| --- | --- |
| `0x004644e8` | `push 4E20h`, pushes `20000` (Verified with int_convert.py) |
| `0x004644ed` | `push 0F4240h`, pushes `1000000` (Verified with int_convert.py) |
| `0x004644f2` | `mov ecx, eax`, constructor receiver |
| `0x004644f4` | `call sub_4CFFB0` |

The bytes at the call site are:

`68 20 4e 00 00 68 40 42 0f 00 8b c8 e8 b7 ba 06 00`

That byte sequence matches `push 0x4e20`, `push 0x0f4240`, `mov ecx,eax`, `call 0x004cffb0`.

Boundary and data bytes:

- `get_bytes(0x004cffaf, 1)` returns `0xcc`, padding before the constructor.
- `get_bytes(0x004d006f, 1)` returns `0xcc`, padding before the ordinary destructor.
- `get_bytes(0x0067a744, 4)` returns zero bytes, matching zero-initialized global storage.
- `make_signature_for_range(database=80de0a67, start=0x004cffb0, end=0x004d006f)` returns a unique IDA-format wildcarded signature for the exact constructor span.

Xrefs:

- `xrefs_to(0x004cffb0)` returns one code xref at `0x004644f4` in `sub_4639D0`.
- `xrefs_to(0x0061b654)` returns three vtable data refs: `0x004d0009` in the constructor, `0x004d009a` in the ordinary destructor, and `0x004e64d1` in the scalar deleting destructor.
- The current `xrefs_to(0x0067a744)` run reports the known broad consumer set and includes constructor writes at `0x004cffef` and `0x004cfff6`, destructor clear at `0x004d00fa`, and later ImageLib cleanup/lifecycle refs. The earlier same-assignment full pass returned `231` xrefs with no `more` flag at limit `300`; no evidence was found for a separate singleton owner.

## Corrected Constructor Semantics

Direct facts:

- The target is exactly one IDA-modeled function at `0x004cffb0-0x004d006f` exclusive end, followed by `0xcc` padding.
- The next function begins at `0x004d0070`.
- The constructor has a thiscall receiver in `ecx` and two stack arguments because both epilogues use `retn 8`.
- The sole direct caller is in `Application::Initialize`-area code at `0x004644f4`.
- The sole caller provides stack values `0x0f4240` for `[ebp+8]` and `0x4e20` for `[ebp+0x0c]`.
- The constructor stores `[ebp+8]` to object offset `+0x08`.
- The constructor never reads `[ebp+0x0c]` in the recovered body.
- The constructor writes literal `0x0f4240` to `+0x10`.
- The constructor allocates `0x14` / `20` bytes and calls the generic `List` constructor as `List(44, 10)`.
- Allocation failure stores null at `+0x0c` and still returns `this`.

The important source-quality correction is not just "two arguments exist". It is:

| Callee slot | Sole caller value | Constructor use |
| --- | ---: | --- |
| `[ebp+8]` / IDA `Block` | `0x0f4240` / `1000000` | stored at `this + 0x08` |
| `[ebp+0x0c]` / second stack arg | `0x4e20` / `20000` | no normal-body use found |

This resolves the current ambiguity in support docs that list the call-site values but do not state callee stack order. It also makes the source-signature blocker sharper: the binary API is a two-argument constructor, but current evidence only proves one source-observable stored parameter plus one unused stack-cleaned parameter.

## Rework Addendum - Field Consumers And Source Shape

The supervisor rejection correctly identified that the earlier report stopped at "unresolved" too early. I rechecked the constructor fields against ResourceLayout/ImageLib consumers, current B006 destructor documentation, and live MCP evidence. Result: the constructor is source-ready as an `ImageLib` constructor; the broader ResourceLayoutTable declaration/facet question does not block this constructor body.

Field-use matrix:

| Object offset | Constructor write | External consumers checked | Best source-facing disposition |
| --- | --- | --- | --- |
| `+0x04` | Cleared to `0` immediately after storing the first callee argument. | Destructor formal C++ from B006 does not use it; constructor EH unwind thunk at `0x005ff8a8` adjusts `ecx` to `this+4` but jumps to `sub_4E5B90`, whose live MCP decompile/disasm shows it ignores `ecx` and only clears `dword_67A744`. No ResourceLayout method in `0x004d0120-0x004d182f` reads object `+0x04`. | Inferred `int m_refCount`. This follows the existing ImageLib layout docs' `refCount` naming and the zero initialization. It is still marked inferred because the field has no direct increment/decrement consumer in this reviewed range. |
| `+0x08` | Stores first callee stack argument `[ebp+8]`; sole caller value is `1000000`. | Offset text searches in `0x004cffb0-0x004d182f` found only the constructor write for ImageLib object `+0x08`; other `[esi+8]` hits are ResourceLayout raw/local records, not ImageLib object accesses. No ResourceLayout method decompile reads `this+8`. | Inferred `int m_cacheLimit`; parameter name `cacheLimit`. The value is a constructor-supplied limit/budget, not the second pushed value. |
| `+0x0c` | Stores the constructed `List` pointer or null on allocation failure. | B006 destructor now emits formal C++ using `m_pEntryList`, iterates it with `GetCount`/`GetElementAt`, frees `ResourceLayoutNameRecord::entries`, deletes the list, and nulls the member. ResourceLayout methods `0x004d0120`, `0x004d02f0`, `0x004d0530`, `0x004d1730`, `0x004d1780`, and `0x004d17c0` read object `+0x0c` as a generic `List*` registry of 44-byte `ResourceLayoutNameRecord` rows. `by-class/List.md` and `ListConstructor` confirm `List(44, 10)` and the generic List layout. | Strongly supported `List* m_pEntryList`; constructor should use `new List(sizeof(ResourceLayoutNameRecord), 10)`. |
| `+0x10` | Writes literal `1000000` after clearing `+0x04` and before allocating the list. | Offset text searches in `0x004cffb0-0x004d182f` found the constructor's ImageLib object write; other `[esi+10h]` hits are ResourceLayout row/local fields or later image helper records, not ImageLib object reads. No ResourceLayout method decompile reads `this+0x10`. | Inferred `int m_maxCacheSize`, initialized to literal `1000000`. It is separate from `m_cacheLimit` even though the sole caller passes the same numeric value. |

ResourceLayout/ImageLib split impact:

- Live MCP decompile evidence for `0x004d0120` (`sub_4D0120`) shows the ResourceLayout load path allocates a `24 * (count + 1)` entries array, fills `ResourceLayoutNameRecord` rows, appends a row to `this[3]` through the List vtable, and returns `this[3][3] - 1`. It uses ImageLib object `+0x0c` only.
- `0x004d02f0`, `0x004d0530`, `0x004d1730`, `0x004d1780`, and `0x004d17c0` follow the same pattern: lazy lookup/load through `sub_4D17C0` / `sub_4D0120`, then read the row from the list at object `+0x0c`. They do not read constructor fields `+0x04`, `+0x08`, or `+0x10`.
- This supports a broader source-boundary caveat: ResourceLayoutTable is an API/facet over the ImageLib singleton's layout registry. It does not require modeling a separate base class or moving this constructor before drafting `ImageLib::ImageLib`.
- The constructor/destructor lifecycle evidence is now stronger than the split caveat. B006's accepted destructor implementation already uses `ImageLib::~ImageLib()` and `m_pEntryList`; this constructor should match that source shape while documenting the ResourceLayoutTable API caveat separately.

Unused second argument disposition:

- `retn 8` proves two stack arguments at the binary ABI.
- The sole caller pushes `0x4e20` / `20000` first, then `0x0f4240` / `1000000`; therefore `[ebp+0x0c]` is the `20000` value.
- Constructor decompile and disassembly never read `[ebp+0x0c]`; all normal returns and the allocation-failure return clean it.
- No constructor field, destructor field, ResourceLayout method, or singleton consumer checked in this pass gives a supported semantic role for `20000`.
- The least-bad source-facing disposition is to preserve the ABI with an unnamed second `int` parameter in the constructor definition: `ImageLib::ImageLib(int cacheLimit, int)`. This avoids inventing a false name while remaining legal, human-written C++ for an intentionally unused formal parameter. A header declaration may later name it if broader source evidence appears, but the implementation body should not attach unsupported semantics to it.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Decision | Rejected alternatives / impact |
| --- | --- | --- | --- |
| Constructor owner | Constructor publishes `dword_67A744`, installs `off_61B654`, is paired with ImageLib destructor/scalar deleting destructor, and target/support docs attach to [UID:00006E]. | Keep direct owner and emitter [UID:00006E][ImageLib]. | Do not move to `ResourceLayoutTable`; that facet consumes the same object but does not own singleton construction/destruction. |
| Range and boundary | `lookup_funcs`, `disasm`, padding bytes, next-function lookup. | Keep exact range `0x004cffb0-0x004d006f`. | No split needed. `0x004d006f` is padding, not part of the constructor or next function. |
| Function/source name | Docs use `ImageLib::ImageLib`; live IDA currently returns `sub_4CFFB0`. | Source-facing doc name `ImageLib::ImageLib` remains correct by behavior and ownership. | Do not rely on current IDA label state as proof that C001 labels are present; document label discrepancy. |
| Singleton global | Normal path writes `this` to `0x0067a744`; fallback writes zero; destructors clear it; broad consumers load it for EPF/EPD operations. | Keep `g_pEPFLib` as ImageLib-owned singleton global. | Do not create a second `ResourceLayoutTable` singleton global. |
| Vtable | Constructor and destructors write `0x0061b654`; vtable doc says only three ImageLib slots before MapTile boundary. | Keep vtable as ImageLib vtable data. | ResourceLayout lookup methods are not ImageLib virtual methods. They may be non-virtual ImageLib API, a base/facet, or recovered type alias. |
| `+0x04` | Constructor clears `this + 0x04`; existing layout uses `refCountOrState`/`refCount`; rework found no ResourceLayout consumer and showed the EH thunk target only clears `g_pEPFLib`. | Use inferred `m_refCount` in formal C++ and docs. | Do not leave it as raw offset/`unk_4`; do not claim original-name proof. |
| `+0x08` | Stores `[ebp+8]`; sole caller value is `1000000`; rework found no external ImageLib-object reads in reviewed ResourceLayout/ImageLib range. | Use inferred `m_cacheLimit` initialized from parameter `cacheLimit`. | Do not say it stores `20000`; that confuses push order with stack argument order. Do not collapse it with `+0x10`. |
| `+0x0c` | Allocation wrapper returns 20-byte object; `List::List(44, 10)` stores here; B006 destructor and ResourceLayout methods iterate/use this member. | Use strongly supported `List* m_pEntryList`. | Reject a custom `ResourceLayoutStore` vtable for this constructor; accepted List report confirms generic List. |
| `+0x10` | Constructor writes literal `1000000`; same value as sole caller's first callee argument; rework found no external ImageLib-object reads in reviewed range. | Use inferred `m_maxCacheSize`, initialized to literal `1000000`. | Do not model this as the unused `20000` parameter or a ResourceLayout row field. |
| Second constructor arg | `retn 8` proves two args; sole caller's second callee arg is `20000`; constructor and ResourceLayout/ImageLib consumer checks found no read or field role. | Preserve ABI with an unnamed second `int` in formal C++: `ImageLib::ImageLib(int cacheLimit, int)`. | Reject a one-argument source definition because it contradicts `retn 8`; reject invented names such as entry-count/cache-reserve without consumer evidence. |
| Reworked `+0x04` source field | Constructor clears it; EH thunk adjustment to `this+4` was checked and the target helper only clears `g_pEPFLib`; ResourceLayout consumers do not read it. | Use inferred `m_refCount` in formal C++. | Do not leave it as `unk_4` or raw `this[1]`; do not claim original-name proof. |
| Reworked `+0x08` source field | Constructor stores first callee argument; sole caller value is `1000000`; no external ImageLib reads found in reviewed range. | Use inferred `m_cacheLimit` and parameter `cacheLimit`. | Do not call it `Block`; do not say it stores `20000`; do not collapse it into `m_maxCacheSize`. |
| Reworked `+0x0c` source field | B006 destructor formal C++ and ResourceLayout methods consistently use the list at object `+0x0c`. | Use strongly supported `m_pEntryList`. | Do not create a custom `ResourceLayoutStore` constructor; the accepted List constructor and class docs support generic `List`. |
| Reworked `+0x10` source field | Constructor literal `1000000`; no external ImageLib reads in reviewed range; existing docs use max/cache wording. | Use inferred `m_maxCacheSize`. | Do not model this as the unused `20000` parameter or a ResourceLayout row field. |
| Reworked second constructor arg | `retn 8`, sole caller, constructor decompile/disassembly, and field-consumer checks prove the second callee arg is stack-cleaned but unused by this body. | Preserve ABI with unnamed second `int` in the formal definition. | Reject a one-argument constructor because it contradicts `retn 8`; reject named `entryCountLimit`/`cacheSize`/`reserveSize` because no consumer supports those semantics. |
| First-draft C++ readiness | Constructor is full-function coverage, owner/emitter are stable, B006 destructor source shape has landed or is in progress with `ImageLib::~ImageLib()` / `m_pEntryList`, and ResourceLayout methods only depend on the list member. | Insert formal first-draft C++ below. | Do not emit raw vtable/global stores or `_DWORD` decompiler output; do not keep the code blank just because exact original private names are inferred. |

## Source Placement

The constructor should stay with [UID:00006E][ImageLib](by-class/ImageLib.md), emitted through [UID:0000K2][ImageLib](by-file/ImageLib.md), projected under `NexusTK/render/`.

Reasons:

- The constructor is the first writer of the `g_pEPFLib` singleton object for this lifecycle family.
- The vtable installed is the ImageLib vtable, not a ResourceLayoutTable vtable.
- The ordinary and scalar deleting destructor pair clean the same object, list, row payloads, and global.
- The `ResourceLayoutTable` method family is better understood as an EPF/EPD layout API/facet over the ImageLib singleton object, not as the direct owner of object construction.
- Existing B001 ResourceLayout raw-helper routing has already rejected assigning raw no-`this` helpers directly to the ImageLib class while keeping the file-neighborhood relationship.

The source file/class split is a broader declaration caveat, not a blocker for this constructor. `ImageLib.cpp` remains the best file route for the constructor and singleton lifecycle. Whether `ResourceLayoutTable` becomes a helper/base/facet in the final source declaration can be documented separately; ResourceLayout consumers checked in this rework use only `m_pEntryList` and do not alter the constructor's source body.

## First-Draft C++ Disposition

Formal C++ should be inserted for [UID:0002IN] after supervisor acceptance.

Exact formal `RECONSTRUCTION_CPP CODE` content recommended for supervisor-approved insertion:

```cpp
ImageLib::ImageLib(int cacheLimit, int)
    : LObject()
{
    g_pEPFLib = this;
    m_cacheLimit = cacheLimit;
    m_refCount = 0;
    m_maxCacheSize = 1000000;
    m_pEntryList = new List(sizeof(ResourceLayoutNameRecord), 10);
}
```

Behavior/source-shape rationale:

- The vtable write is compiler-generated and should not appear in source.
- `LObject()` is the source-facing base constructor corresponding to `sub_4F4A80(this)`.
- `g_pEPFLib = this;` captures the normal singleton publication path. The decompiler's impossible `this == -4` fallback is not source-shaped; it is an artifact of the constructor/EH lowering around adjusted object state and the singleton clear helper.
- The statement order matches the observed field-store order after base construction: first callee parameter to `+0x08`, `+0x04` clear, `+0x10` literal, then list allocation/construction/assignment to `+0x0c`.
- The unnamed second `int` preserves the two-argument ABI while refusing to invent unsupported semantics for the unused `20000` value.
- `m_pEntryList` aligns with the current B006 destructor implementation and ResourceLayout consumer evidence. `m_cacheLimit`, `m_refCount`, and `m_maxCacheSize` are inferred source-facing names; they are better than raw offsets/decompiler names and should be marked inferred in the target/support docs.
- The code intentionally uses `sizeof(ResourceLayoutNameRecord)` rather than raw `44`, because the accepted ResourceLayout row documentation proves the element size and this is the more plausible human-written source shape.

## Score Recommendation

| Field | Before | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | `85` | `91` | The target should now record current MCP session provenance, exact call-site byte/stack-argument order, the first-argument value stored at `+0x08`, unused second-argument value and disposition, padding bytes, current raw-label discrepancy, resolved generic `List(44, 10)` interpretation, ResourceLayout field-consumer negative evidence, B006 destructor alignment, inferred member names/types, and formal C++ content. |
| `CONFIDENCE` | `90` | `92` | Live MCP reconfirmed boundary, caller, decompilation, disassembly, bytes, xrefs, and unique signature. The expanded rework resolves the previously named C++ blockers. Confidence remains below final-audit territory because exact original private member names and the broader ResourceLayoutTable declaration/facet design remain inferred rather than symbol-proven. |
| `CANONICAL_OWNER` | `00006E` | `00006E` | Constructor lifecycle evidence remains ImageLib-owned. |
| `EMITTER_UIDS` | `00006E` | `00006E` | Source emission route remains ImageLib class through ImageLib file. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Custom game-client object lifecycle code. |
| Formal C++ | blank | populate multiline block | Formal first-draft constructor code above. |

Do not raise above `92` confidence until exact original private names or a final ImageLib/ResourceLayoutTable declaration model are proven. Those remaining issues no longer block this constructor's formal first-draft body.

## Generated / Tracker State

Read-only generated-state observations:

- `auto-generated/-ag-memory-coverage.md` routes [UID:0002IN] as an emitting ImageLib item to `auto-generated/NexusTK/render/ImageLib.cpp`, with no code.
- `auto-generated/-ag-research-tracker.md` still reports stale target scores around `78/88` for [UID:0002IN] in the not-covered reconstructable row, despite the current target page showing `85/90`.
- Generated tracker/coverage state also still contains stale old aggregate references such as the removed broad `[UID:000172] by-memory/0x004cffb0-0x004e6572.ImageLib.md` in some generated views.
- `auto-generated/NexusTK/render/ImageLib.cpp` contains marker-only output for this target and stale metadata in the generated header/markers.

These are validator/generated state issues, not report-only edit targets. Do not hand-edit generated reports, generated C++, validator state, or coverage reports. After accepted implementation, scoped validators should refresh the edited source docs. If generated tracker state still reports stale missing old aggregates or stale scores, the supervisor should use the documented validator lifecycle/refresh workflow rather than manual edits.

## Recommended Target / Support Doc Edits

If the supervisor accepts this report, apply these edits in a separate implementation callback under normal leases and validators.

Target doc:

- `by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md`
  - Raise metadata to `COMPLETION:91`, `CONFIDENCE:92`.
  - Keep owner/emitter/reconstructable unchanged.
  - Insert the formal C++ from this report into the multiline `RECONSTRUCTION_CPP CODE` block.
  - Update the signature notes to state the exact caller instruction order and callee stack-order mapping: `push 0x4e20`, then `push 0x0f4240`; `[ebp+8]` stores `1000000` at `+0x08`; `[ebp+0x0c]` is `20000` and unused in the recovered body.
  - Add current live MCP provenance including session/database, current raw IDA labels, function size, sole caller, callees, boundary padding bytes, call-site bytes, vtable/global refs, ResourceLayout field-consumer checks, and unique signature.
  - Add the inferred field/source-signature rationale in the C++/Autogen status area.
  - Preserve the historical C001 label-sync note but add current-session caveat that this IDB currently returns `sub_4CFFB0`, `dword_67A744`, and `off_61B654`.

Support docs:

- `by-class/ImageLib.md`
  - Update the observed layout/signature paragraph to distinguish push order from callee stack order.
  - State that `+0x08` receives the callee first argument, currently `1000000` in the sole caller, while the unused second callee argument is `20000`.
  - Record best inferred field names/types: `int m_refCount` at `+0x04`, `int m_cacheLimit` at `+0x08`, `List* m_pEntryList` at `+0x0c`, and `int m_maxCacheSize` at `+0x10`; mark names inferred except `m_pEntryList`, which is now strongly supported by B006 destructor/list evidence.
  - Add the current live label caveat if retaining the C001 label-sync history.

- `by-file/ImageLib.md`
  - Correct the important signature correction paragraph so it does not list the two push values in a misleading order.
  - State the byte-level call-site order and the callee stack mapping.
  - Keep the ImageLib/ResourceLayoutTable source-boundary caveat, but state that it does not block emitting the constructor as `ImageLib::ImageLib(int cacheLimit, int)` because ResourceLayout methods checked here consume only `m_pEntryList`.

- `by-type/by-struct/ImageLibLayout.md`
  - Correct the layout note to state the exact stack-slot/value mapping for `+0x08` and the unused second argument.
  - Update the field ledger with inferred names/types: `m_refCount`, `m_cacheLimit`, `m_pEntryList`, and `m_maxCacheSize`; keep exact-original-name caveats for the inferred fields.

- `by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md`
  - If B006's accepted implementation has landed, no content change is required unless the supervisor wants a constructor cross-note; preserve that it already supports `m_pEntryList`.
  - If B006 is still in progress in another worktree/session, avoid conflicting edits and treat its formal destructor C++ as a support-doc dependency to verify before implementation.

- `by-global/g_pEPFLib.md` and `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md`
  - If edited in the same callback, add a short current-session note that live IDA still reports raw `dword_67A744` despite the project source-facing `g_pEPFLib` name, and that this is a label-state caveat rather than an ownership change.
  - No score change recommended for these support docs.

- `by-type/by-vtable/ImageLibVtable.md` and `by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md`
  - Optional support note only if supervisor wants label-state consistency: current IDA refs still show `off_61B654`, while source-facing docs use `ImageLib_vftable`.
  - No score change recommended.

- `by-file/ResourceLayoutTable.md`, `by-class/ResourceLayoutTable.md`, and related ResourceLayout method docs
  - No metadata change recommended for this report.
  - Only add a short cross-note if the supervisor wants the constructor page's corrected argument evidence mirrored into the ImageLib/ResourceLayout boundary caveat. The constructor report's current evidence says the boundary caveat is broader declaration work, not a blocker for the ImageLib constructor body.

## Expected Validators After Implementation

No validators were run in this report-only pass.

After accepted implementation, run scoped validators from `source-3/project-documentation` for each edited by-* file, for example:

- `python .\tools\validator.py --mode file --file by-memory\0x004cffb0-0x004d006f.ImageLibConstructor.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-class\ImageLib.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-file\ImageLib.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-type\by-struct\ImageLibLayout.md --apply --queue-timeout 240 --wait-generated`

If support global/vtable docs are edited, run matching scoped file validators for those paths too. Do not edit generated reports, generated C++, project-level generated files, validator/tool state, IDA DB, or any `-coverage-report.md`.

## Implementation Tracking Checklist

- [x] Target [UID:0002IN] `by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md`: updated metadata from `85/90` to `91/92`; kept `CANONICAL_OWNER:00006E`, `EMITTER_UIDS:00006E`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_POSITION_OPTIONAL`, and inserted the formal first-draft constructor C++ into `RECONSTRUCTION_CPP CODE`. Proof: target header now shows `COMPLETION:91`, `CONFIDENCE:92`, unchanged owner/emitter/reconstructable, and generated `auto-generated/NexusTK/render/ImageLib.cpp` includes UID `0002IN` as `Completion:91 | Confidence:92`.
- [x] Target [UID:0002IN]: updated signature notes with exact byte/instruction order `push 0x4e20`, `push 0x0f4240`, `mov ecx,eax`, `call 0x004cffb0`, and explained that `[ebp+8]` stores `0x0f4240` / `1000000` at object `+0x08`, while `[ebp+0x0c]` is `0x4e20` / `20000` and unused in the recovered body. Proof: target `Signature Notes` now includes the call-site bytes and stack mapping.
- [x] Target [UID:0002IN]: added current live IDA MCP provenance: endpoint/session/database evidence from report implementation context, `server_health` status, `sub_4CFFB0` size `0xbf` / `191`, sole caller `sub_4639D0` at `0x004644f4`, callees `sub_4F4A80`, `sub_4F4AA0`, `sub_4F3060`, and `retn 8` two-stack-argument proof. Proof: target `Evidence` now records B001 live database/session `80de0a67`, `server_health:ok`, function size, sole caller/callees, and two-argument ABI.
- [x] Target [UID:0002IN]: preserved behavior facts for singleton write/clear at `0x004cffef` and `0x004cfff6`, vtable write `off_61B654` at `0x004d0009`, field stores at `+0x04`, `+0x08`, `+0x10`, allocation of `20` bytes, `List::List(44, 10)`, success store at `+0x0c`, null failure store at `+0x0c`, and `0xcc` padding at `0x004d006f`. Proof: target `Behavior Summary`, `Evidence`, and `Score Rationale` include those facts.
- [x] Target [UID:0002IN]: added current-session IDA label caveat that live MCP returns `sub_4CFFB0`, `dword_67A744`, and `off_61B654` despite the historical C001 label-sync note; did not edit IDA DB. Proof: target `Evidence` records the raw-label caveat, and no IDA DB/tool-state edit was performed.
- [x] Target [UID:0002IN]: inserted exact formal `RECONSTRUCTION_CPP CODE` content:
  ```cpp
  ImageLib::ImageLib(int cacheLimit, int)
      : LObject()
  {
      g_pEPFLib = this;
      m_cacheLimit = cacheLimit;
      m_refCount = 0;
      m_maxCacheSize = 1000000;
      m_pEntryList = new List(sizeof(ResourceLayoutNameRecord), 10);
  }
  ```
- [x] Target [UID:0002IN]: documented the resolved source-shape rationale: two-argument ABI preserved with unnamed unused second `int`; first callee argument `cacheLimit` initializes inferred `m_cacheLimit`; `m_refCount`, `m_cacheLimit`, and `m_maxCacheSize` are inferred names; `m_pEntryList` is strongly supported by B006 destructor/List/ResourceLayout evidence; ResourceLayoutTable declaration split is a broader caveat but not a constructor-body blocker. Proof: target `Signature Notes`, `Autogen Status`, `Score Rationale`, and `Changes` now carry that rationale.
- [x] Target [UID:0002IN]: added ResourceLayout consumer evidence: `0x004d0120`, `0x004d02f0`, `0x004d0530`, `0x004d1730`, `0x004d1780`, and `0x004d17c0` use object `+0x0c` as the layout-entry `List*` and do not read ImageLib object `+0x04`, `+0x08`, or `+0x10`; text-search hits for those offsets outside the constructor are row/local/helper records unless specifically object `+0x0c`. Proof: target `Evidence` and support docs record these checks.
- [x] `by-class/ImageLib.md`: updated the observed layout/signature paragraph with the corrected stack-order/value mapping and inferred field names/types `m_refCount`, `m_cacheLimit`, `m_pEntryList`, and `m_maxCacheSize`; kept exact-original-name caveats for inferred fields; no support score change. Proof: `Observed Layout`, `Method Notes`, `Autogen Status`, `2026-06-27 Constructor Source Shape`, and `Changes` were updated.
- [x] `by-file/ImageLib.md`: corrected the important signature correction paragraph with byte-level push order and callee stack mapping; preserved the central `ImageLib.cpp` / `ResourceLayoutTable` source-boundary caveat while stating it does not block constructor C++; no support score change. Proof: `File Role`, object layout, `Class Boundary Caveat`, and `Changes` were updated.
- [x] `by-type/by-struct/ImageLibLayout.md`: updated the field ledger so `+0x04` is inferred `m_refCount`, `+0x08` is inferred `m_cacheLimit` initialized from first callee argument value `1000000` in the sole caller, `+0x0c` is `List* m_pEntryList`, `+0x10` is inferred `m_maxCacheSize` literal `1000000`, and the unused second callee argument is `20000`; no support score change. Proof: `Layout`, `2026-06-14 IDA Recheck`, `2026-06-27 Constructor Field-Use Resolution`, `Score Rationale`, and `Changes` were updated.
- [x] `by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md`: B006 executed state was already sufficient, so this file was intentionally not edited. Proof: current page already has B006 formal `ImageLib::~ImageLib()` C++, `COMPLETION:90`, `CONFIDENCE:92`, `m_pEntryList`, `ResourceLayoutNameRecord::entries`, scalar-wrapper split evidence, and `Changes` note for 2026-06-27 B006 source-quality implementation; generated `ImageLib.cpp` includes UID `000173` destructor immediately after UID `0002IN`.
- [x] Optional `by-global/g_pEPFLib.md` and `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md`: not edited because the accepted target/support pages now carry the raw-IDB-label caveat at sufficient detail and no owner/emitter/score change was needed.
- [x] Optional `by-type/by-vtable/ImageLibVtable.md` and `by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md`: not edited because the target/support pages already preserve `off_61B654` current-session label caveat and no owner/emitter/score change was needed.
- [x] Ran scoped validator for the target file from `source-3/project-documentation` with `--apply --queue-timeout 240 --wait-generated`. Proof: `python .\tools\validator.py --mode file --file by-memory\0x004cffb0-0x004d006f.ImageLibConstructor.md --apply --queue-timeout 240 --wait-generated`; clean recorded pass `command_id:000000004098`, `command_timestamp:2026-06-27T10:27:39-04:00`, exit code `0`, `ok:1`, `generated_refresh:completed`.
- [x] Ran scoped validators for every edited support by-* file. Proof:
  - `python .\tools\validator.py --mode file --file by-class\ImageLib.md --apply --queue-timeout 240 --wait-generated`; `command_id:000000004099`, `command_timestamp:2026-06-27T10:27:48-04:00`, exit code `0`, `ok:1`, `generated_refresh:completed`.
  - `python .\tools\validator.py --mode file --file by-file\ImageLib.md --apply --queue-timeout 240 --wait-generated`; `command_id:000000004100`, `command_timestamp:2026-06-27T10:27:58-04:00`, exit code `0`, `ok:1`, `generated_refresh:completed`.
  - `python .\tools\validator.py --mode file --file by-type\by-struct\ImageLibLayout.md --apply --queue-timeout 240 --wait-generated`; `command_id:000000004102`, `command_timestamp:2026-06-27T10:28:07-04:00`, exit code `0`, `ok:1`, `generated_refresh:completed`.
- [x] Verified generated `auto-generated/NexusTK/render/ImageLib.cpp` freshness after validation. Proof: generated header shows `validator-command-id: 000000004103`, `validator-refreshed-at: 2026-06-27T10:28:32-04:00`, newer than the final scoped validator timestamp, and the generated file includes UID `0002IN` constructor C++ plus UID `000173` destructor C++.
- [x] Lease discipline completed. Proof: leased immediate edit files `by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md`, `by-class/ImageLib.md`, `by-file/ImageLib.md`, and `by-type/by-struct/ImageLibLayout.md` as `B001`; released them after edit/validator/generated-check batch; `Select-String` for `B001|Agent-B001` in `tools/leaser/Agents/current_leases.md` returned no active B001 leases.
- [x] Did not manually edit generated reports, generated C++, project-level generated files, validator/tool state, IDA DB, by-project-structure, scalar-wrapper [UID:0002IO], or any `-coverage-report.md`. Validator refreshed generated outputs and reports as expected; those side effects were tool-owned.
- [x] If generated tracker/coverage output remains stale after supervisor report execution, supervisor should use documented validator lifecycle/refresh commands; no generated rows or validator state were hand-edited in this implementation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002IN-ImageLibConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002IN-ImageLibConstructor-source-quality.md","timestamp":"2026-06-27T10:37:57","uid":"0002IN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
