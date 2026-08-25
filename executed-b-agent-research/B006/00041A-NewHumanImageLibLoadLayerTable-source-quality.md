** TARGET-REPORT-UID:00041A **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B006 Report: [UID:00041A] NewHumanImageLibLoadLayerTable Source Quality


Report timestamp: `2026-06-30T00:13:54-04:00`

Assignment: `B006-report-00041A-NewHumanImageLibLoadLayerTable-20260630`

Mode: report-first research, followed by accepted implementation callback on `2026-06-30`. Target/support by-* docs were edited during the callback and validators were run; generated output was refreshed only by validator/generator side effects.

Target: [UID:00041A] `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md`

Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B006\research\00041A-NewHumanImageLibLoadLayerTable-source-quality.md`

## Decision

Promote [UID:00041A] from below-gate no-owner support to a class-owned emitting `NewHumanImageLib` helper.

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:000092
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:000092
EMITTER_POSITION_OPTIONAL:
```

Recommended source route: [UID:000092] `by-class/NewHumanImageLib.md`, emitted through [UID:0000LR] `by-file/NewHumanImageLib.md` into `NexusTK/render/NewHumanImageLib.cpp`.

Recommended formal C++: source-authored first-draft body for `void NewHumanImageLib::LoadLayerTable(const wchar_t *tableName)`, pasted exactly in the target page's formal `RECONSTRUCTION_CPP CODE` block.

This is not a rare no-improvement/no-code case. Current MCP evidence resolves the previous blockers: helper signature, layer-row fields, child-index array shape, source placement, vector relation, no-xref caveat, and first-draft C++ body are implementation-ready with inferred source-facing names already accepted by the constructor/layout/destructor docs.

## MCP Session And Availability

MCP was required and was available.

Endpoint checked: `http://127.0.0.1:13337/mcp`

Active database used: `supervisor_resume_20260629`

Session facts from `idb_list`:

- `session_id`: `supervisor_resume_20260629`
- `input_path`: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- `filename`: `NexusTK.exe.i64`
- `created_at`: `2026-06-29T21:35:56.876252`
- `last_accessed`: `2026-06-30T00:09:21.200294`
- `is_analyzing`: `false`
- `is_active`: `true`
- `backend`: `worker`
- `owned`: `true`
- `adopted`: `true`
- `pid` / `worker_pid`: `17592`

Health facts from `server_health`:

- `status`: `ok`
- `idb_path`: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- `module`: `NexusTK.exe`
- `input_path`: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- `imagebase`: `0x400000`
- `auto_analysis_ready`: `true`
- `hexrays_ready`: `true`
- `strings_cache_ready`: `true`
- `strings_cache_size`: `2067`

No MCP write tools were used.

## Search And Prior Report Intake

Required search terms used:

```text
0x004e1040
NewHumanImageLibLoadLayerTable
LoadLayerTable
Layer.tbl
VectorGrowLayer
MotionTableLocalHelperA
00041A
```

Relevant prior report found:

- `executed-b-agent-research/B011/0002JR-NewHumanImageLibConstructor-source-quality.md`

B011 is directly relevant because it created/synchronized the helper child pages and recorded the first current evidence that `0x004e1040` is a reusable `Layer.tbl` loader rather than stale `MotionTableLocalHelperA`.

Stale UID-only collisions found and excluded:

- `executed-b-agent-research/B002/0001K6-TimerMgrAndTimerQueue-source-quality.md`
- `executed-b-agent-research/B004/0001K6-TimerMgrAndTimerQueue-source-quality.md`
- Current TimerMgr support docs still contain stale UID-collision links whose display UIDs now resolve to the current NewHuman helper paths. Examples include `by-file/TimerMgr.md` and `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md`.

Those TimerMgr rows are not evidence for this target because their address/name context is `0x00597...` TimerMgr, not `0x004e1040` NewHumanImageLib. This report does not recommend editing TimerMgr docs in the NewHuman callback unless the supervisor explicitly expands scope to UID-collision cleanup.

## Current Target State

Current target metadata before this report:

```text
COMPLETION:84
CONFIDENCE:86
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE: blank
```

Current prose correctly identifies the broad behavior: reusable `Layer.tbl` loader, 23-byte header, 4-byte row count, 32-byte layer rows, optional child-index arrays, and `VectorGrowLayer` insertion. The stale part is the below-gate/no-owner/no-code disposition.

## Range And Boundary Evidence

Current MCP `lookup_funcs`:

| Query | Result |
| --- | --- |
| `0x004e103f` | Not a function |
| `0x004e1040` | `sub_4E1040`, size `0x170` |
| `0x004e11af` | inside `sub_4E1040`, size `0x170` |
| `0x004e11b0` | next function `sub_4E11B0`, size `0x1f7` |
| `0x004e50a0` | `sub_4E50A0`, size `0x19e` |
| `0x0061c2fc` | Not a function |

Important range note:

- The assigned current filename uses `0x004e1040-0x004e11af`.
- MCP size `0x170` and disassembly show the function object is `0x004e1040-0x004e11b0` exclusive.
- `0x004e11af` is the last byte of the `retn 4` instruction, not the exclusive end.
- `0x004e11b0` is the next modeled function, `sub_4E11B0`.

Implementation should not create a duplicate page. Either retain the current path and document this last-byte/exclusive-end nuance explicitly, or let the validator/supervisor perform a path-normalization pass. This report's accepted edit plan assumes the current assigned path remains the edited target.

Boundary byte evidence:

```text
get_bytes 0x004e1038 size 16:
00 8b e5 5d c2 04 00 cc 55 8b ec 6a ff 68 36 03
```

This shows the prior function return/padding byte `cc` at `0x004e103f`, then `sub_4E1040` starts at `0x004e1040`.

```text
get_bytes 0x004e1040 size 32:
55 8b ec 6a ff 68 36 03 60 00 64 a1 00 00 00 00
50 83 ec 58 a1 24 2f 67 00 33 c5 89 45 f0 56 57
```

This is the target function prologue.

```text
get_bytes 0x004e11a0 size 32:
8b 4d f0 33 cd e8 85 65 0e 00 8b e5 5d c2 04 00
55 8b ec 6a ff 68 66 03 60 00 64 a1 00 00 00 00
```

This shows the target tail through `retn 4` at `0x004e11ad` and the next function prologue at `0x004e11b0`.

## Function Profile Evidence

MCP `func_profile 0x004e1040`:

- Name: `sub_4E1040`
- Size: `0x170`
- Instruction count: `133`
- Basic blocks: `17`
- Caller count: `0`
- Callee count: `11`
- Prototype as modeled by IDA: `int __thiscall(_DWORD *this, wchar_t *ArgList)`
- Constants include `0x17` / 23, `0x4`, `0x14` / 20, and `0x20` / 32.

The raw return type is not source-authoritative. The body ends by returning whatever the DAT-file cleanup helper leaves in `EAX`, and no caller consumes a return value. Source-quality treatment should use `void`.

MCP `func_profile 0x004e50a0`:

- Name: `sub_4E50A0`
- Size: `0x19e`
- Caller count: `2`
- Callers: constructor `sub_4DFD10` and target `sub_4E1040`
- Prototype as modeled by IDA: `int __thiscall(_DWORD *this, _OWORD *, _OWORD *)`
- Behavior: 32-byte element vector grow/insert helper.

## Xref Evidence

MCP `xrefs_to`:

| Target | Current xrefs |
| --- | --- |
| `0x004e1040` | zero xrefs |
| `0x004e50a0` | code xrefs at `0x004dffb2` from constructor `sub_4DFD10` and `0x004e1171` from target `sub_4E1040` |
| `0x0061c2fc` | data xref at `0x004dfe91` from constructor `sub_4DFD10` |

The zero-xref fact for `0x004e1040` remains important but does not block source reconstruction. It proves the constructor does not call this helper in the shipped binary; it does not make the helper non-source or non-ownable. The helper is a retained source-shaped class method/body adjacent to sibling NewHuman table loaders.

## Decompiled Body Evidence

MCP `decompile 0x004e1040` shows:

- `ECX` is the receiver object.
- Stack argument `ArgList` is a `wchar_t *` table path.
- A DAT/file object is constructed at `0x004e1072`.
- The path argument is opened at `0x004e109c`.
- The loader reads a 23-byte header at `0x004e10aa`.
- The loader reads a 4-byte row count at `0x004e10b8`.
- Each loop iteration zeroes a 32-byte temporary row.
- The loader reads:
  - 4 bytes into row offset `+0x00` at `0x004e10e4`.
  - 20 bytes into row offset `+0x04` at `0x004e10f2`.
  - 4 bytes into row offset `+0x18` at `0x004e1100`.
- If the offset `+0x18` count is positive, the body allocates `childCount * 4` bytes through `unknown_libname_19` at `0x004e111d` and reads one 4-byte integer per child at `0x004e1139`.
- The row pointer field at offset `+0x1c` receives the allocated array pointer.
- The row appends to the object vector at `this + 0x10`.
- If the vector has capacity, the body copies two 16-byte chunks and increments the end pointer by `0x20`.
- If the vector is full, the body calls `sub_4E50A0(this + 4, end, &row)` at `0x004e1171`.
- The file is closed/destructed through `sub_49C240` / `sub_49C160`.

MCP `callees 0x004e1040`:

| Callee | Source-facing role |
| --- | --- |
| `0x49c130` | DATFile constructor/setup |
| `0x516030` | runtime/helper initialization in DAT open path |
| `0x49c180` | DATFile open from path |
| `0x49c310` | DATFile read |
| `0x5c7790` | `operator new[]`-style allocation |
| `0x4e50a0` | `VectorGrowLayer` / layer vector grow-insert |
| `0x49c240` | DATFile close |
| `0x49c160` | DATFile destructor/cleanup |
| `0x5c772f` | security-cookie check |

The SEH/security-cookie and DAT temporary cleanup tail are compiler/runtime scaffolding and should not be hand-emitted in source.

## Disassembly Evidence

MCP `disasm 0x004e1040` confirms the key source facts:

- Stack argument `ArgList` has type `wchar_t *`.
- `sub esp, 58h` reserves local DAT/file, row, header, count, and cookie storage.
- `0x004e10a1`: pushes `17h` for the 23-byte header read.
- `0x004e10af`: pushes `4` for the row-count read.
- `0x004e10d0-0x004e10e0`: zeroes the 32-byte row temp.
- `0x004e10d6`: pushes `4` for row offset `+0x00`.
- `0x004e10e9`: pushes `14h` for the 20-byte row name field at offset `+0x04`.
- `0x004e10f7`: pushes `4` for row offset `+0x18` child count.
- `0x004e1113-0x004e111d`: multiplies child count by `4` and allocates child-index storage.
- `0x004e1130-0x004e1139`: reads one 4-byte child index per iteration.
- `0x004e114c-0x004e1163`: appends directly by copying 32 bytes and advancing the vector end by `0x20`.
- `0x004e1169-0x004e1171`: full-capacity path calls `sub_4E50A0` with `this + 0x10`.
- `0x004e11ad`: `retn 4`.

## String And Resource Evidence

Raw bytes at `0x0061c2e4` decode the adjacent UTF-16 table cluster:

```text
Motion.tbl
Layer.tbl
Part.tbl
acc2drw.tbl
.DSC
```

MCP `get_string` returns `Motion.tbl` at `0x0061c2e4` but only `L` at `0x0061c2fc`, matching the known IDA adjacent UTF-16 literal caveat. Prefer byte-level evidence for this string cluster.

`Layer.tbl` package/resource evidence from [UID:0001RI] remains valid:

- `char.dat`, entry index `37`
- offset `6,856,566`
- size `467` bytes
- header begins `LayerInformation`
- count at header offset `0x17` is `13`
- row size is `0x20` / 32 bytes

Resource bytes remain DAT payload. The source owns loader logic, not hard-coded table arrays.

## Row Declaration Resolution

The accepted inferred row type is `NewHumanLayerEntry`, already documented by [UID:0001VF] `NewHumanImageLibLayout` and used by accepted constructor/destructor C++.

Current field layout:

```cpp
struct NewHumanLayerEntry
{
    int layerId;          // offset +0x00
    char name[20];        // offset +0x04
    int childCount;       // offset +0x18
    int *childIndexes;    // offset +0x1c
};
```

This declaration is source-ready inference, not proof of original spelling. It is now strong enough for first-draft C++ because:

- the constructor accepted the same field names and layout;
- the destructor accepted `childIndexes` cleanup;
- the target decompile/disassembly independently re-proves the same offsets and sizes;
- the resource page confirms `Layer.tbl` row size and count.

Implementation should synchronize this declaration in layout/resource prose. Do not force a standalone type formal C++ block in [UID:0001VF] during this callback unless the supervisor explicitly requests type emission; the concrete source body belongs in [UID:00041A].

## Helper Signature Resolution

Recommended source signature:

```cpp
void NewHumanImageLib::LoadLayerTable(const wchar_t *tableName)
```

Rationale:

- IDA confirms `thiscall` with `ECX` receiver and one stack `wchar_t *` path argument.
- The helper opens the supplied path, not an internal hard-coded string.
- Sibling constructor source already calls table helpers with wide literals.
- The decompiler's `int` return is a cleanup-return artifact; the body has no meaningful source return and no caller consumes one.
- The helper mutates `m_layerEntries` at object offset `+0x10`.

## Ownership And Source Placement

Recommended canonical owner: [UID:000092] `NewHumanImageLib`.

Recommended emitter: [UID:000092] `NewHumanImageLib`, routing through [UID:0000LR] `NexusTK/render/NewHumanImageLib.cpp`.

Owner ranking:

1. [UID:000092] `NewHumanImageLib`: receiver object, layout field `m_layerEntries`, class table family, constructor/destructor agreement, and neighboring method-family placement all point here.
2. [UID:0000LR] `NewHumanImageLib`: correct file/source route, not direct canonical owner for this member body.
3. [UID:00017R] local method cluster: index/container context only, non-emitting and not the owner.
4. [UID:0001RI] resource page: table payload evidence only.
5. [UID:00041F] `VectorGrowLayer`: callee/helper dependency only.
6. [UID:0000P3] `VectorHelpers`: vector helper support only, not owner of this class method.

## Formal C++ Recommendation

Paste this exact formal block into [UID:00041A]'s `RECONSTRUCTION_CPP CODE` header/block during implementation:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewHumanImageLib::LoadLayerTable(const wchar_t *tableName)
{
    DATFile layerFile;
    unsigned char header[23];
    int layerCount = 0;

    layerFile.Open(tableName);
    layerFile.Read(header, sizeof(header));
    layerFile.Read(&layerCount, sizeof(layerCount));

    for (int index = 0; index < layerCount; ++index)
    {
        NewHumanLayerEntry layer = {};

        layerFile.Read(&layer.layerId, sizeof(layer.layerId));
        layerFile.Read(layer.name, sizeof(layer.name));
        layerFile.Read(&layer.childCount, sizeof(layer.childCount));

        if (layer.childCount > 0)
        {
            layer.childIndexes = new int[layer.childCount];

            for (int childIndex = 0;
                 childIndex < layer.childCount;
                 ++childIndex)
            {
                layerFile.Read(&layer.childIndexes[childIndex],
                               sizeof(layer.childIndexes[childIndex]));
            }
        }

        m_layerEntries.push_back(layer);
    }

    layerFile.Close();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Why this source block is safe:

- It stays inside the current target body and does not paste `VectorGrowLayer` C++.
- It preserves the path-argument loader shape; it does not hard-code `L"Layer.tbl"` inside the helper.
- It mirrors the accepted constructor's inline `Layer.tbl` loop while keeping the target as its own retained source helper.
- It uses the already accepted `DATFile`, `NewHumanLayerEntry`, `m_layerEntries`, and `childIndexes` source-facing names.
- It expresses vector growth as `m_layerEntries.push_back(layer)`, which is the plausible source that emits the direct-copy/full-capacity helper path.
- It omits SEH, security-cookie, raw `_DWORD *`, `_OWORD`, `sub_*`, stack temp, and DAT destructor return artifacts.

## Rejected Alternatives

- Reject keeping [UID:00041A] as no-owner/non-emitting solely because it has zero direct xrefs. Current body is source-authored and has a direct class/file route; no-xref status is a reachability caveat, not a no-code proof.
- Reject preserving the stale name `MotionTableLocalHelperA`; row size, destination vector, and behavior prove `LoadLayerTable`.
- Reject claiming the constructor calls `0x004e1040`; current xrefs to the target remain zero, and the constructor contains its own inline `Layer.tbl` loop.
- Reject moving ownership to [UID:00017R]; the cluster is a non-emitting index.
- Reject moving ownership to [UID:0001RI] or DAT/resource pages; resource bytes are payload dependencies.
- Reject moving ownership to [UID:00041F] or [UID:0000P3]; `VectorGrowLayer` is a callee, not this loader body.
- Reject formal C++ that returns `int`; the decompiler return is a cleanup artifact and no source return is meaningful.
- Reject formal C++ with `sub_49C310`, `unknown_libname_19`, `_OWORD`, or `_DWORD *`.
- Reject editing TimerMgr support docs in this callback based only on UID matches; those are stale collision artifacts with unrelated address/name context.
- Reject creating a duplicate `0x004e1040-0x004e11b0` page. Record the exact exclusive end in the current target page unless the supervisor explicitly requests validator-managed path normalization.

## Score Rationale

Completion should rise from `84` to `88` because the target now has:

- current MCP session/health facts;
- function lookup and boundary proof;
- decompile and disassembly proof for every row read and child-index path;
- caller/xref proof, including the zero-xref caveat;
- `VectorGrowLayer` caller/callee relation;
- source-owner and emitter route;
- first-draft formal C++;
- support-doc synchronization plan for all stale below-gate text;
- explicit rejected alternatives.

Confidence should rise from `86` to `90` because live IDA directly supports the helper signature, body, row shape, vector field, callee relation, boundary bytes, and no-xref fact. Confidence stays below final-audit range because original symbol spellings for `LoadLayerTable`, `NewHumanLayerEntry`, `layerId`, `name`, `childCount`, and `childIndexes` remain inferred source-facing names rather than recovered source symbols.

## Implementation Plan After Supervisor Acceptance

No implementation was performed in this report-only pass.

After acceptance, lease only the immediate edit/validator batch paths, edit, validate, and release leases immediately.

Required by-* edit set:

- `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md`
- `by-class/NewHumanImageLib.md`
- `by-file/NewHumanImageLib.md`
- `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`
- `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`
- `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md`
- `by-resource/new-human-motion-tables.md`
- `by-type/by-struct/NewHumanImageLibLayout.md`

Do not edit TimerMgr docs in this callback unless the supervisor explicitly adds UID-collision cleanup to the implementation scope.

Recommended scoped validators:

> Executable block R001 was removed from this report and preserved verbatim in [00041A-NewHumanImageLibLoadLayerTable-source-quality-removed.md](00041A-NewHumanImageLibLoadLayerTable-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated freshness check after validators:

- `auto-generated/NexusTK/render/NewHumanImageLib.cpp` must refresh through validator/autogen only.
- It should contain a [UID:00041A] block with `NewHumanImageLib::LoadLayerTable`.
- It should no longer contain an empty marker for [UID:00041A].
- Existing [UID:0002JR], [UID:00017S], and [UID:0002V8] generated bodies must remain present.

## Claim And Incorporation Ledger

| Claim | Target/support doc | Accepted report detail to incorporate | Implementation callback state |
| --- | --- | --- | --- |
| C01 | Target [UID:00041A] | Raise metadata to `COMPLETION:88`, `CONFIDENCE:90`; preserve `RECONSTRUCTABLE:TRUE`; set `CANONICAL_OWNER:000092`, `EMITTER_UIDS:000092`, blank `EMITTER_POSITION_OPTIONAL`. | [x] Implemented in target; validator `000000001898` recorded completion/confidence/canonical-owner/autogen-registry updates and `ok: 1`. |
| C02 | Target [UID:00041A] | Insert the exact formal `void NewHumanImageLib::LoadLayerTable(const wchar_t *tableName)` C++ block. | [x] Implemented in target formal block; generated `NewHumanImageLib.cpp` now has UID00041A lines `239-275` with `NewHumanImageLib::LoadLayerTable`. |
| C03 | Target [UID:00041A] | Add current MCP session facts for database `supervisor_resume_20260629`, health `ok`, Hex-Rays ready, strings cache ready, and no MCP writes. | [x] Implemented in target Current MCP Evidence section. |
| C04 | Target [UID:00041A] | Document boundary proof: current path key `0x004e1040-0x004e11af`; function object `0x004e1040-0x004e11b0` exclusive; `0x004e11af` last byte; `0x004e11b0` next function. Do not create a duplicate page. | [x] Implemented in target status/boundary text; no duplicate page created. |
| C05 | Target [UID:00041A] | Add lookup/profile facts: `sub_4E1040`, size `0x170`, 133 instructions, 17 blocks, zero callers, modeled `thiscall` with `wchar_t *` path. | [x] Implemented in target Boundary, Xrefs, And Bytes section. |
| C06 | Target [UID:00041A] | Add decompile/disassembly evidence for DAT open, 23-byte header, 4-byte count, 4+20+4 row reads, child-index allocation/read loop, direct vector append, and `VectorGrowLayer` full-capacity call. | [x] Implemented in target behavior/boundary evidence and formal C++. |
| C07 | Target [UID:00041A] | Add no-xref caveat and rejected constructor-call claim; state constructor still inlines its own `Layer.tbl` loop. | [x] Implemented in target and constructor/file/class/cluster/resource support text. |
| C08 | Target [UID:00041A] | Add return/signature rationale: source `void`, IDA `int` return is DAT cleanup-return artifact. | [x] Implemented in target Signature And Return Rationale section. |
| C09 | Target [UID:00041A] | Add owner/source placement decision: direct class owner [UID:000092], file route [UID:0000LR], dependencies are not owners. | [x] Implemented in target Source Placement section and support docs. |
| C10 | [UID:0001VF] Layout | Synchronize `NewHumanLayerEntry` declaration details: `int layerId`, `char name[20]`, `int childCount`, `int *childIndexes`; mark names inferred/source-ready, not original-spelling proof. | [x] Implemented in layout page; validator `000000001906` inserted UID00041A link and returned `ok: 1`. |
| C11 | [UID:0001RI] Resource | Update `Layer.tbl` loader note: [UID:00041A] now has first-draft formal loader C++ while resource bytes remain DAT payload. Preserve char.dat entry/count/size evidence. | [x] Implemented in resource page; validator `000000001905` returned `ok: 1`. |
| C12 | [UID:00041F] VectorGrowLayer | Add current MCP proof that callsites are constructor `0x004dffb2` and target `0x004e1171`; keep [UID:00041F] below-gate/no-owner/non-emitting because this report does not promote vector-template helper C++. | [x] Implemented in VectorGrowLayer page; validator `000000001904` returned `ok: 1`. |
| C13 | [UID:000092] Class | Update method-family row for `LoadLayerTable` from below-gate support to `88/90` class-owned/emitting helper with no-xref caveat and formal C++ on target page. | [x] Implemented in class method table and sync section; validator `000000001899` returned `ok: 1`. |
| C14 | [UID:000092] Class | Historicalize B011 blanket wording that all [UID:000417]-[UID:00041G] pages are below-gate; [UID:00041A] is now the exception promoted by this report. | [x] Implemented in class B011 sync and Changes entries. |
| C15 | [UID:0000LR] File | Update owned/nearby helper text so `LoadLayerTable` is no longer described as below-gate/no-owner; keep other unpromoted helpers below-gate. | [x] Implemented in file helper/source-route text; validator `000000001900` returned `ok: 1`. |
| C16 | [UID:0000LR] File | Add generated-output expectation: [UID:00041A] should emit through `NexusTK/render/NewHumanImageLib.cpp`; no manual generated edit. | [x] Implemented; generated output refreshed by validators only. |
| C17 | [UID:00017R] Local cluster | Update active-function and child-state rows so [UID:00041A] is class-owned/emitting at `88/90`, while the aggregate remains non-emitting. | [x] Implemented in local cluster; validator `000000001901` returned `ok: 1` with existing `missing_ref_uid 0003UD` warnings. |
| C18 | [UID:0002JR] Constructor | Preserve no-constructor-call fact, but update stale helper-family notes so [UID:00041A] is no longer below-gate/blank; constructor C++ remains unchanged and keeps inline `Layer.tbl` loop. | [x] Implemented in constructor support text only; validator `000000001903` returned `ok: 1`. |
| C19 | Target/support docs | Preserve rejected alternatives: no `MotionTableLocalHelperA`, no resource/vector/local-cluster ownership, no raw decompiler C++, no duplicate range page, no TimerMgr UID-collision evidence. | [x] Implemented across target/support rejected-alternative and source-placement text. |
| C20 | TimerMgr collision docs | Explicitly exclude `by-file/TimerMgr.md` and `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md` from this callback unless supervisor expands scope. | [x] Excluded; no TimerMgr docs edited. |
| C21 | Validators | Run the scoped validators listed above, record command, command id, timestamp, exit code, ok count, warnings, and side effects. | [x] Completed; see Callback Validator Ledger below for commands `000000001898` through `000000001906`. |
| C22 | Generated freshness | Verify `auto-generated/NexusTK/render/NewHumanImageLib.cpp` freshness and [UID:00041A] generated code after validator refresh. | [x] Verified file length `23430`, `LastWriteTimeUtc 2026-06-30T04:57:41.8184838Z`, UID00041A generated block at lines `239-275`, and no UID00041A empty-marker hit. |
| C23 | Leasing | During implementation only, take short leases for immediate edit/validator batch and release immediately after validators. No leases were taken for this report-only pass. | [x] Completed with lease wait/retry. Partial early lease was released, full callback leases were reacquired for edit/validator, then released after validators; `current_leases.md` ended with no active leases. |

## Callback Validator Ledger

| File | Command | command_id | command_timestamp | Exit | ok | Warnings / side effects |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md` | `python .\tools\validator.py --mode file --file by-memory\0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md --apply --queue-timeout 240 --wait-generated` | `000000001898` | `2026-06-30T00:56:04-04:00` | `0` | `1` | Updated completion/confidence/canonical owner, autogen registry, UID links; generated refresh completed; broad generated metadata refresh and validator backups were validator side effects. |
| `by-class/NewHumanImageLib.md` | `python .\tools\validator.py --mode file --file by-class\NewHumanImageLib.md --apply --queue-timeout 240 --wait-generated` | `000000001899` | `2026-06-30T00:56:24-04:00` | `0` | `1` | Inserted UID00041A link; generated refresh completed; broad generated metadata refresh and validator backups were validator side effects. |
| `by-file/NewHumanImageLib.md` | `python .\tools\validator.py --mode file --file by-file\NewHumanImageLib.md --apply --queue-timeout 240 --wait-generated` | `000000001900` | `2026-06-30T00:56:39-04:00` | `0` | `1` | Inserted UID00041A link, stats row update; generated refresh completed; broad generated metadata refresh and validator backups were validator side effects. |
| `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md` | `python .\tools\validator.py --mode file --file by-memory\0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md --apply --queue-timeout 240` | `000000001901` | `2026-06-30T00:56:55-04:00` | `0` | `1` | Existing `missing_ref_uid 0003UD` reported twice; generated refresh deferred. |
| `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md` | `python .\tools\validator.py --mode file --file by-memory\0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md --apply --queue-timeout 240` | `000000001903` | `2026-06-30T00:57:03-04:00` | `0` | `1` | Inserted UID00041F link; generated refresh deferred. |
| `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md` | `python .\tools\validator.py --mode file --file by-memory\0x004e50a0-0x004e523e.VectorGrowLayer.md --apply --queue-timeout 240` | `000000001904` | `2026-06-30T00:57:12-04:00` | `0` | `1` | Inserted UID00041A link, reference index add, stats row updates; generated refresh deferred. |
| `by-resource/new-human-motion-tables.md` | `python .\tools\validator.py --mode file --file by-resource\new-human-motion-tables.md --apply --queue-timeout 240` | `000000001905` | `2026-06-30T00:57:25-04:00` | `0` | `1` | Inserted UID00041A link, stats row update; generated refresh deferred. |
| `by-type/by-struct/NewHumanImageLibLayout.md` | `python .\tools\validator.py --mode file --file by-type\by-struct\NewHumanImageLibLayout.md --apply --queue-timeout 240` | `000000001906` | `2026-06-30T00:57:36-04:00` | `0` | `1` | Inserted UID00041A link, reference index add for UID00041F, stats row update; generated refresh deferred. |

## Generated Freshness

- `auto-generated/NexusTK/render/NewHumanImageLib.cpp`: length `23430`, `LastWriteTime 2026-06-30T00:57:41.8184838-04:00`, `LastWriteTimeUtc 2026-06-30T04:57:41.8184838Z`.
- UID00041A generated block begins at line `239` and contains `void NewHumanImageLib::LoadLayerTable(const wchar_t *tableName)` through line `275`.
- `rg "UID:00041A|LoadLayerTable|EMPTY|empty|NewHumanImageLib::LoadLayerTable"` returned UID00041A and method lines only for this block; no UID00041A empty-marker hit.

## Implementation Tracking Checklist

- [x] Lease only accepted target/support by-* docs for the immediate edit/validator batch; waited through B002/B004 conflicts, reacquired full B006 callback leases, and released them after validators.
- [x] Update [UID:00041A] metadata to `88/90`, owner/emitter [UID:000092], `RECONSTRUCTABLE:TRUE`, blank optional position.
- [x] Insert the exact formal C++ block in [UID:00041A].
- [x] Add current MCP/session/boundary/decompile/disassembly/xref/byte evidence to [UID:00041A].
- [x] Add the exact no-xref caveat and rejected constructor-call alternative to [UID:00041A].
- [x] Add source signature and `void` return rationale to [UID:00041A].
- [x] Update [UID:000092] class method row and B011 helper-family historical text for the [UID:00041A] promotion.
- [x] Update [UID:0000LR] file helper/source-route text and generated-output expectation for [UID:00041A].
- [x] Update [UID:00017R] local-cluster active function and child-state rows for [UID:00041A] without changing aggregate non-emitting metadata.
- [x] Update [UID:0002JR] constructor support text only; constructor formal C++ unchanged.
- [x] Update [UID:00041F] `VectorGrowLayer` support facts/callsites without promoting that helper.
- [x] Update [UID:0001RI] resource page for the promoted `Layer.tbl` loader/source-payload split.
- [x] Update [UID:0001VF] layout page with the source-ready `NewHumanLayerEntry` declaration/field notes and inferred-name caveat.
- [x] Do not edit TimerMgr docs; UID-collision cleanup remains excluded.
- [x] Run scoped validators with `--wait-generated` where listed.
- [x] Record validator command ids, timestamps, exit codes, ok counts, warnings, side effects, and generated refresh state in this report.
- [x] Verify `auto-generated/NexusTK/render/NewHumanImageLib.cpp` contains the [UID:00041A] source body after validator refresh.
- [x] Release all leases immediately after the validator batch; `current_leases.md` reported no active leases.
- [x] Update this report ledger/checklist with callback proof.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/00041A-NewHumanImageLibLoadLayerTable-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/00041A-NewHumanImageLibLoadLayerTable-source-quality.md","timestamp":"2026-06-30T01:02:19","uid":"00041A"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00041A-NewHumanImageLibLoadLayerTable-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/00041A-NewHumanImageLibLoadLayerTable-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00041A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
