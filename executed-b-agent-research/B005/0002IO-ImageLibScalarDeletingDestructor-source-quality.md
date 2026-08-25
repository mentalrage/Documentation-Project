** TARGET-REPORT-UID:0002IO **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# B005 Report - [UID:0002IO] ImageLibScalarDeletingDestructor Source Quality

Assignment: `B005-report-0002IO-ImageLibScalarDeletingDestructor-source-quality-20260627`

Agent: Agent-B005

Date: 2026-06-27

Original scope: report-only research for [UID:0002IO] `by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md`. During the report-only pass I edited only this report file and did not edit by-* docs, generated C++ output, generated reports, project-level generated files, coverage reports, validator/tool state, or the IDA database.

Final report refresh status: complete against the current post-B006/post-B001 support state before implementation callback. I re-read the affected target/support by-* docs after B006's [UID:000173] implementation was supervisor-verified and executed with `python .\tools\validator.py execute_report B006 000173-ImageLibDestructor-source-quality.md 000173 --apply`, command id `000000004093`. A later support refresh also found B001's constructor implementation now reflected in ImageLib support docs and generated `ImageLib.cpp`, with [UID:0002IN] emitting `ImageLib::ImageLib(int cacheLimit, int)`. These newer constructor facts strengthened the `m_pEntryList` field evidence but did not change the [UID:0002IO] disposition: [UID:000173] emits source-authored cleanup, and [UID:0002IO] was the routed compiler scalar deleting wrapper that still needed the `85/90` blank formal block and stale "C++ stays blank" wording corrected.

Implementation callback status: completed on 2026-06-27 after supervisor acceptance. The target is now `88/92`, still owned/emitted by [UID:00006E], with inline `RECONSTRUCTION_CPP CODE:[[[]]]` blank and the formal scalar-wrapper marker in the multiline block. The validator canonicalized the marker's `[UID:000173]` reference with its standard target annotation in by-* and generated output.

## Target Recommendation

| Target | Current by-* metadata | Recommended metadata | Owner / emitter | C++ recommendation |
| --- | ---: | ---: | --- | --- |
| [UID:0002IO] `0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor` | `85/90` | `88/92` | keep `CANONICAL_OWNER:00006E`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006E` | Insert a comment-only formal marker in the multiline block; do not hand-write the ABI wrapper body. |

This target is the `ImageLib` vtable-routed MSVC scalar deleting destructor wrapper. It performs the same source cleanup as [UID:000173] `ImageLib::~ImageLib`, then adds compiler delete-flag handling and a guarded flag-4 path. The source-authored destructor body belongs on [UID:000173]; this wrapper should remain reconstructable and routed so generated trackers know the ABI wrapper is accounted for, but its formal C++ should be a marker comment rather than handwritten source.

Recommended exact formal content for `by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated scalar deleting destructor for ImageLib; source cleanup is represented by ImageLib::~ImageLib() [UID:000173].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The inline `RECONSTRUCTION_CPP CODE:[[[]]]` value should stay blank. The multiline formal block should contain only the marker comment above.

## Current Target State

The current target page already contains strong behavior evidence and class routing:

- `COMPLETION:85`, `CONFIDENCE:90`
- `CANONICAL_OWNER:00006E`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00006E`
- blank `EMITTER_POSITION_OPTIONAL`
- blank formal C++
- Item summary: `Destructor cleanup plus compiler scalar-delete flag handling.`
- IDA function described as `ImageLib_ScalarDeletingDestructor`, range `0x004e64a0-0x004e6572` exclusive.

The remaining blocker is not target behavior. It is source representation. The target is already routed, above the current code-entry gate, and has an exact no-code proof: the emitted source cleanup should be [UID:000173] `ImageLib::~ImageLib`, while this exact target covers the compiler-generated deleting wrapper and should contain a formal marker comment under Rule 28 rather than stay blank.

The 2026-06-27 B006 implementation correctly resolved [UID:000173], but the current [UID:0002IO] page still says "C++ stays blank." That statement is now stale under current Rule 28 practice: the source body must not move here, but a routed wrapper emitter should carry a minimal formal comment marker so generated trackers do not continue to treat it as an empty emitter.

## Evidence Checked

Project/workflow files read:

- `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `tools/leaser/Agents/Agent-B005/goal.md`
- `tools/leaser/Agents/Supervisor.md`
- `by-structure.md`
- `ntk-b-agent-workflow` references for B-agent research and Rule 26 incorporation.

Target and support docs checked:

- [UID:0002IO] `by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md`
- [UID:000173] `by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md`
- B006 executed report `executed-b-agent-research/B006/000173-ImageLibDestructor-source-quality.md`
- [UID:000172] `by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md`
- [UID:0002IN] `by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md`
- [UID:00006E] `by-class/ImageLib.md`
- [UID:0000K2] `by-file/ImageLib.md`
- [UID:0001US] `by-type/by-struct/ImageLibLayout.md`
- [UID:0001VT] `by-type/by-struct/ResourceLayoutNameRecord.md`
- [UID:0001XR] `by-type/by-vtable/ImageLibVtable.md`
- [UID:00031R] `by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md`
- [UID:0000QU] `by-global/g_pEPFLib.md`
- [UID:0001OQ] `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md`
- Final refresh after B006 implementation:
  - `tools/leaser/Agents/current_leases.md`: ImageLib target/support files are clear. The only active leases at the final refresh are unrelated B003 MonsterImageLib files, created `2026-06-27T14:28:27Z` and expiring `2026-06-27T14:33:27Z`.
  - B006 executed-report lifecycle is complete for [UID:000173]: supervisor-supplied execute command id `000000004093`; the current `auto-generated/-ag-research-tracker.md` row lists score `90/92`, executed count `1`, timestamp `2026-06-27T10:19:12`, agent `B006`, and path `executed-b-agent-research/B006/000173-ImageLibDestructor-source-quality.md`.
  - [UID:000173] target page now has `COMPLETION:90`, `CONFIDENCE:92`, formal `ImageLib::~ImageLib()` C++, and a source-placement section that keeps [UID:0002IO] as separate compiler scalar deleting wrapper glue.
  - [UID:0002IO] target page remains `COMPLETION:85`, `CONFIDENCE:90`, with blank inline and multiline formal C++ blocks; B006 added the ordinary-destructor relationship evidence but intentionally left this wrapper blank.
  - [UID:00006E] `ImageLib`, [UID:0000K2] `ImageLib`, lifecycle cluster, layout, record, vtable, vtable-data, global, and global-storage pages now carry the ordinary-destructor source-body and scalar-wrapper route at same-or-greater support detail.
  - Post-B001 support refresh: [UID:0002IN] `ImageLibConstructor` now has formal constructor C++; [UID:00006E] `ImageLib`, [UID:0000K2] `ImageLib`, and [UID:0001US] `ImageLibLayout` now document inferred `m_refCount`, inferred `m_cacheLimit`, strongly supported `m_pEntryList`, inferred `m_maxCacheSize`, and the unused second constructor argument. These changes do not affect the scalar-wrapper/no-code proof, but implementation should preserve them and not reintroduce stale "constructor blocked" wording.

Generated/read-only state checked before the implementation callback:

- `auto-generated/NexusTK/render/ImageLib.cpp`, refreshed at `2026-06-27T10:32:47-04:00` by validator command id `000000004108`, contains [UID:0002IN] `ImageLib::ImageLib(int cacheLimit, int)` at `91/92` and [UID:000173] `ImageLib::~ImageLib()` at `90/92`. The same generated file shows [UID:0002IO] as `Completion:85 | Confidence:90 | Empty Emitter Marker`, confirming the wrapper still has no formal marker/comment output.
- `auto-generated/-ag-memory-coverage.md`, refreshed at `2026-06-27T10:33:02-04:00` by validator command id `000000004109`, now lists [UID:000173] as `coded` / `yes`; [UID:0002IO] remains `emits` / `no`.
- `auto-generated/-ag-research-tracker.md`, refreshed at `2026-06-27T10:33:26-04:00` by validator command id `000000004112`, keeps [UID:000173] executed by `B006` at `90/92`, while [UID:0002IO] remains unexecuted at `85/90`.
- `auto-generated/-ag-coverage-report-by-memory.md`, refreshed at `2026-06-27T10:33:02-04:00` by validator command id `000000004109`, shows [UID:000173] as `emits_code:true`, `90%`, `very-strong`; [UID:0002IO] remains `emits_code:false`, `85%`, `very-strong`, with the old summary `Destructor cleanup plus compiler scalar-delete flag handling.` Accepted [UID:0002IO] implementation should refresh this through the target validator after the marker and summary update.

Accepted precedent checked:

- [UID:0002VC] ItemObjImageLib scalar deleting destructor report and executed implementation use a formal comment-only marker for an MSVC deleting-destructor wrapper whose source cleanup is represented by the ordinary destructor.
- [UID:00017S] NewHumanImageLib ordinary destructor report shows the companion pattern: the ordinary destructor can own source C++ while the scalar wrapper remains generated-binary ABI glue.

## Live IDA MCP Evidence

MCP was available and responsive.

- Endpoint: `http://127.0.0.1:13337/mcp`
- `idb_list`: active session/database `80de0a67`, worker PID `26892`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health(database=80de0a67)`: `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Focused evidence pass time: 2026-06-27 around `10:05:51-04:00`.
- Resume refresh after B006 execution, 2026-06-27 around `10:20:09-04:00`: `initialize` returned `ida-pro-mcp` protocol `2025-06-18`; `tools/list` returned the current schema; `idb_list` still showed the same active worker session `80de0a67`; `server_health` still returned `status:"ok"`, auto-analysis ready, Hex-Rays ready, and strings cache ready. A fresh `lookup_funcs`/`xrefs_to` probe reconfirmed the exact function inventory and vtable route below.
- Final lightweight MCP check after the latest generated refresh: `initialize` still returns `ida-pro-mcp`; `idb_list` still reports active session/database `80de0a67`, worker PID `26892`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. The current tool schema requires `database='80de0a67'` for IDB-backed calls; with that argument, `server_health` returns `status:"ok"`, `lookup_funcs` reconfirms the target/sibling boundaries, and `xrefs_to` reconfirms the vtable-only route below.

### Function Inventory And Numeric Checks

`lookup_funcs(database=80de0a67)`:

| Query | Result | Meaning |
| --- | --- | --- |
| `0x004e64a0` | `sub_4E64A0`, size `0xd2` | Exact scalar deleting destructor target. |
| `0x004e6572` | not a function | Confirms target exclusive end. |
| `0x004e6580` | `sub_4E6580`, size `0x5c` | Next modeled function after padding, ItemObjImageLib wrapper. |
| `0x004d0070` | `sub_4D0070`, size `0xab` | Ordinary `ImageLib::~ImageLib` cleanup body. |
| `0x004d011b` | not a function | Confirms ordinary destructor exclusive end. |
| `0x004d0120` | `sub_4D0120`, size `0x1c5` | ResourceLayoutTable successor. |
| `0x00516030` | `sub_516030`, size `0x6` | Memory manager accessor used before payload frees. |
| `0x00516170` | `sub_516170`, size `0x14` | Free-buffer helper used for row payloads. |
| `0x004f4a90` | `sub_4F4A90`, size `0x7` | `LObject` base cleanup chain. |
| `0x004f4ac0` | `sub_4F4AC0`, size `0x40` | Optional object delete helper. |

The 2026-06-27 resume probe after B006 execution reconfirmed the key inventory: `0x004e64a0 -> sub_4E64A0` size `0xd2`; `0x004e6572` is not a function; `0x004e6580 -> sub_4E6580` size `0x5c`; `0x004d0070 -> sub_4D0070` size `0xab`; and `0x004d011b` is not a function.

`int_convert(database=80de0a67)` verified:

- `0xd2 = 210` bytes.
- `0xab = 171` bytes.
- `0x5c = 92` bytes.
- `0x1c5 = 453` bytes.
- `0x2c = 44` bytes.
- `0x28 = 40` bytes.
- `0x10 = 16` bytes.
- `0x0c = 12` bytes.
- `0x0e = 14` bytes.
- `0x05 = 5` bytes.

### Scalar Wrapper Decompile And Disassembly

`decompile 0x004e64a0` shows:

- `0x004e64d1`: stores `off_61B654` / `ImageLib_vftable` into `*this`.
- `0x004e64d7`: calls `sub_516030`.
- `0x004e64dc`: loads `this[3]`, the `+0x0c` list field.
- `0x004e64eb`: snapshots `*(list + 0x0c)` as the loop count.
- `0x004e64fb`: calls the list virtual slot `+0x10`, matching `GetElementAt(index)`.
- `0x004e64fd`: reads row payload pointer at row `+0x28`.
- `0x004e650d`: calls `sub_516170(payload)` and stores the return value back to row `+0x28`.
- `0x004e6521`: destroys the list through its virtual deleting destructor with flag `1`.
- `0x004e6523`: clears `this + 0x0c`.
- `0x004e652c`: clears `dword_67A744` / `g_pEPFLib`.
- `0x004e6536`: calls `sub_4F4A90(this)` for base cleanup.
- `0x004e6544-0x004e6547`: if `(flags & 1) != 0 && (flags & 4) == 0`, calls `sub_4F4AC0(this)`.
- Returns `this`.

Focused disassembly around the wrapper tail confirms:

- `0x004e653e`: `test al, 1`.
- `0x004e6540`: branch over object delete if flag bit 1 is not set.
- `0x004e6542`: `test al, 4`.
- `0x004e6544`: branch to guard path if flag bit 4 is set.
- `0x004e6547`: call `sub_4F4AC0`.
- `0x004e6551-0x004e6554`: flag-4 path pushes `0x14`, pushes `this`, and calls `_guard_check_icall_nop@4`.
- `0x004e656f`: `retn 4`, matching the scalar deleting destructor ABI flag parameter.

`analyze_component 0x004e64a0,0x004d0070` reports:

- `sub_4E64A0`: prototype `_DWORD *__thiscall(_DWORD *Block, char)`, size `210`, callees `sub_516030`, `sub_516170`, `sub_4F4A90`, `sub_4F4AC0`, `_guard_check_icall_nop@4`, `18` basic blocks, complexity `6`.
- `sub_4D0070`: prototype `void __thiscall(_DWORD *this)`, size `171`, callees `sub_516030`, `sub_516170`, `sub_4F4A90`, `13` basic blocks, complexity `5`.
- Shared globals: `0x0061b654` (`off_61B654`), `0x0067a744` (`dword_67A744`), and `___security_cookie`.

### Ordinary Destructor Comparison

`decompile 0x004d0070` shows the same source cleanup without delete-flag handling:

- `0x004d009a`: stores `off_61B654`.
- `0x004d00a0`: calls `sub_516030`.
- `0x004d00a5`: loads `this + 0x0c`.
- `0x004d00b4`: snapshots list count from list `+0x0c`.
- `0x004d00c9`: calls list virtual slot `+0x10`.
- `0x004d00cb`: reads row payload pointer at row `+0x28`.
- `0x004d00db`: stores `sub_516170(payload)` back to row `+0x28`.
- `0x004d00ef`: destroys the list with flag `1`.
- `0x004d00f1`: clears `this + 0x0c`.
- `0x004d00fa`: clears `g_pEPFLib`.
- `0x004d0104`: chains to `sub_4F4A90`.

This confirms [UID:000173] owns the source-facing destructor body, while [UID:0002IO] adds compiler scalar-delete behavior only after the same cleanup.

### Xrefs, Vtable Route, Pointer Negatives, And Bytes

`xref_query` and `xrefs_to`:

- `xrefs_to 0x004e64a0`: exactly one data xref, from `0x0061b654` to `0x004e64a0`.
- `xrefs_to 0x004d0070`: zero xrefs and "No cross-references to this address".
- `xrefs_to 0x0061b654`: exactly three data refs:
  - `0x004d0009` in constructor `sub_4CFFB0`.
  - `0x004d009a` in ordinary destructor `sub_4D0070`.
  - `0x004e64d1` in scalar deleting destructor `sub_4E64A0`.
- `xrefs_to 0x0067a744`: `231` total. Lifecycle owner refs in this family are constructor `0x004cffef` and `0x004cfff6`, ordinary destructor clear `0x004d00fa`, and scalar wrapper clear `0x004e652c`.

The 2026-06-27 resume probe after B006 execution reconfirmed this routing: `xrefs_to 0x004e64a0` still has exactly one data xref from `0x0061b654`; `xrefs_to 0x004d0070` still has zero xrefs; and `xrefs_to 0x0061b654` still has only the three constructor/destructor/scalar-wrapper data refs at `0x004d0009`, `0x004d009a`, and `0x004e64d1`.

`find_bytes`:

- `A0 64 4E 00`, the absolute VA pointer to `0x004e64a0`, matches once at `0x0061b654`.
- `A0 64 0E 00`, the RVA pattern for `0x004e64a0`, has zero matches.
- `70 00 4D 00`, the absolute VA pointer to `0x004d0070`, has zero matches.
- `70 00 0D 00`, the RVA pattern for `0x004d0070`, has zero matches.
- `54 B6 61 00`, the immediate vtable-slot address `0x0061b654`, matches `0x004d000b`, `0x004d009c`, and `0x004e64d3`, corresponding to constructor/destructor/scalar vptr stores.

`get_bytes`:

- `0x004e64a0` for `210` bytes starts with the SEH/cookie prologue and includes the vtable write, list loop, `g_pEPFLib` clear, base cleanup, flag tests, optional `sub_4F4AC0`, guard path, and `retn 4`.
- `0x004e6572-0x004e6580` is fourteen `0xcc` bytes.
- `0x004e6580` begins `55 8b ec 56 8b f1 ...`, the next ItemObjImageLib scalar deleting destructor.
- `0x004d0070` for `171` bytes contains the ordinary destructor body and `retn`.
- `0x004d011b-0x004d0120` is five `0xcc` bytes.
- `0x0061b650-0x0061b660` contains dwords `0x006486d4`, `0x004e64a0`, `0x004f4b10`, and `0x0041b6c0`.
- `0x0067a744` is currently zero-initialized storage.

## Heuristic / Inference Reanalysis And Validation

### Is [UID:0002IO] source-authored destructor code?

Decision: no. It is class-specific compiler-generated scalar deleting destructor glue over source-authored cleanup.

Evidence:

- The only direct pointer route to `0x004e64a0` is the `ImageLib` vtable slot at `0x0061b654`.
- The target takes a delete flag parameter and returns with `retn 4`.
- It returns `this` in `eax`, tests flag bits `1` and `4`, calls `sub_4F4AC0` only on the deleting path, and calls `_guard_check_icall_nop@4` on the guarded flag-4 path.
- The cleanup before the flag checks is the same as [UID:000173] `ImageLib::~ImageLib`.
- The ordinary destructor start `0x004d0070` has no xrefs and no absolute/RVA pointer matches, which is expected when the vtable points to the scalar deleting destructor.

Rejected alternatives:

- Hand-author `ImageLib::ScalarDeletingDestructor(unsigned int flags)`: rejected because that would encode compiler ABI mechanics as project source.
- Put the source cleanup body here instead of [UID:000173]: rejected because [UID:000173] is the modeled ordinary source destructor and B006's accepted report now supplies first-draft formal C++ there.
- Mark [UID:0002IO] `RECONSTRUCTABLE:FALSE`: rejected because the wrapper is class-specific binary output that must be regenerated from the reconstructed `ImageLib` declaration/destructor. It is not unrelated CRT/runtime code.
- Leave routed but blank: rejected under Rule 28 once the source/no-code proof is resolved. The formal marker should prevent generated trackers from treating this eligible emitter as missing code.

### Should [UID:0002IO] keep class owner and emitter [UID:00006E]?

Decision: yes.

Evidence:

- The vtable slot belongs to [UID:0001XR] `ImageLibVtable`, whose direct owner is [UID:00006E] `ImageLib`.
- The wrapper restores `ImageLib` vtable `0x0061b654`, cleans `ImageLib` field `+0x0c`, clears `g_pEPFLib`, and calls the base cleanup on the same object.
- [UID:00006E] routes to [UID:0000K2] `ImageLib`, projected under `NexusTK/render/`.
- Current target metadata already uses the class owner/emitter, which is narrower than file-level ownership and matches current by-structure guidance.

Rejected alternatives:

- Change direct owner to [UID:0000K2] file root: rejected as less precise for a vtable-backed class destructor wrapper.
- Change direct owner to [UID:0000QU] `g_pEPFLib`, [UID:0001VT] `ResourceLayoutNameRecord`, [UID:000079] `List`, `MemoryMan`, or `LObject`: rejected because these are global/field/helper/base dependencies, not method owners.
- Assign to `ResourceLayoutTable`: rejected because the wrapper writes the `ImageLib` vtable and participates in the `ImageLib` constructor/destructor/scalar family. The `ResourceLayoutTable` methods consume the same object/facet but do not own the vtable slot.

### Source-facing names and placeholders

Best-supported source-facing interpretation:

- `sub_4E64A0` should be documented as `ImageLib` compiler scalar deleting destructor wrapper, not as a handwritten `ScalarDeletingDestructor` method.
- `sub_4D0070` should be documented as `ImageLib::~ImageLib`.
- `off_61B654` / `ImageLib_vftable` is the `ImageLib` primary vtable.
- `dword_67A744` is `g_pEPFLib`.
- `Block[3]` / `this + 0x0c` is the list field documented as `m_pEntryList` or `resourceLayoutList`; the exact original private member spelling remains inferred.
- `sub_516030` and `sub_516170` remain memory-manager helpers; B006's [UID:000173] formal source uses `GetMemoryMan()` and `MemoryMan::FreeBufferMemory`.
- `sub_4F4A90` is base `LObject` cleanup lowering and should not be manually called in `ImageLib::~ImageLib` formal C++.
- `sub_4F4AC0` is the optional object delete helper used only by the scalar deleting destructor ABI.

Remaining uncertainty:

- Exact original private spelling for the `+0x0c` list field remains not directly proven, but the best source-facing name is now stronger: B001's constructor implementation and B006's destructor implementation both use `m_pEntryList`, and ResourceLayout consumer checks preserve the same storage as the `List*` registry field.
- Exact public type split between `ImageLib` and `ResourceLayoutTable` remains open. This affects class/header final-audit confidence, not this wrapper's no-code marker.
- The constructor's second stack argument remains unresolved. It has no impact on the scalar deleting destructor no-code disposition.

## Source Placement

Recommended placement:

- Direct semantic owner: [UID:00006E] `ImageLib`.
- Source root: [UID:0000K2] `ImageLib`, projected path `NexusTK/render/`.
- Source-authored cleanup: [UID:000173] `ImageLib::~ImageLib` formal C++ now present after B006 implementation.
- Wrapper representation: [UID:0002IO] formal comment-only marker.

This matches the vtable route, singleton/global ownership, layout page, vtable page, constructor page, ordinary destructor page, and B006's accepted ordinary destructor source-body decision.

## Range / Split / Padding / Reclassification Analysis

No split or child creation is needed.

- The target is one modeled IDA function at `0x004e64a0`, size `0xd2`, ending at `0x004e6572`.
- `0x004e6572` is not a function.
- `0x004e6572-0x004e6580` is fourteen `0xcc` bytes.
- The successor at `0x004e6580` is [UID:0002VC] ItemObjImageLib scalar deleting destructor, size `0x5c`.
- The ordinary destructor [UID:000173] is a separate modeled function at `0x004d0070-0x004d011b`; it must not be merged into the scalar wrapper page.

Rebuild handling should be documented as `source-declared/generated-binary`: reconstructing the `ImageLib` class with a destructor should cause the compiler/linker to regenerate the scalar deleting destructor wrapper; project source should not include a handwritten wrapper body.

## Score And Metadata Recommendation

Current target state:

- `COMPLETION:85`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00006E`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00006E`
- formal C++ blank

Recommended target state now that B006 ordinary-destructor implementation is reflected in by-* docs:

- `COMPLETION:88`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:00006E`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00006E`
- blank `EMITTER_POSITION_OPTIONAL`
- formal multiline C++ block containing only the marker comment.

Rationale:

- Completion rises because this pass resolves the final source representation blocker, adds live MCP pointer-negative evidence, ties the wrapper to [UID:000173] formal source cleanup, records the vtable-only route, and supplies exact formal block content.
- Confidence rises because the live MCP pass independently reconfirmed function boundaries, decompilation, disassembly, xrefs, bytes, vtable slot, pointer negatives, global refs, callee set, and ordinary-destructor parity.
- The score should stay below `95` because private field spelling, full `ImageLib` versus `ResourceLayoutTable` header/API split, constructor second-argument semantics, and class/file final-source declarations are not final-audit complete.

Recommended `Item Summary` replacement:

```text
Compiler-generated ImageLib scalar deleting destructor wrapper with vtable-only route, ordinary-destructor cleanup parity, 44-byte row payload free-and-null loop, List virtual deletion, `g_pEPFLib` clear, base cleanup, delete-flag/guard handling, padding boundary, and formal no-code marker pointing to [UID:000173].
```

## Target Doc Change Recommendations

`by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md`:

- Change metadata to `COMPLETION:88`, `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:00006E`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006E`, blank `EMITTER_POSITION_OPTIONAL`.
- Keep inline `RECONSTRUCTION_CPP CODE:[[[]]]` blank.
- Insert the exact formal marker comment in the multiline C++ block.
- Update status/rebuild handling to say this is source-declared/generated-binary compiler scalar deleting destructor glue, not a handwritten `ImageLib` method body.
- Add current MCP provenance: endpoint, session/database `80de0a67`, worker PID `26892`, health status, IDB path, and local pass time.
- Add current MCP facts: `lookup_funcs` size `0xd2`, `0x004e6572` not a function, `0x004e6572-0x004e6580` padding, successor `0x004e6580`, decompile/disasm cleanup sequence, callee list, vtable-only xref, pointer-route negatives, ordinary destructor parity, global clear refs, and vtable bytes.
- Preserve the exact delete-flag and guard path: `test al,1`, `test al,4`, optional `sub_4F4AC0`, `_guard_check_icall_nop@4`, `retn 4`.
- Preserve rejected alternatives: no handwritten wrapper body, no merge with [UID:000173], no `RECONSTRUCTABLE:FALSE`, no file/global/helper/base owner, and no stale blank formal block.
- Update score rationale to explain the `88/92` disposition and remaining non-95 limits.

## Support Doc Recommendations

Apply only where the implementation pass finds the current page does not already carry same-or-greater detail. Final refresh found B006's ordinary-destructor implementation already reflected across the main support pages, so most support work may be "record already sufficient" rather than text edits. The target page [UID:0002IO] is the page that still definitely needs metadata, marker, status, summary, and score-rationale updates.

- `by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md`: already updated by B006 to `90/92` with formal `ImageLib::~ImageLib()` C++, no-pointer-route evidence, scalar-wrapper relationship, source placement, and rejected alternatives. No B005 edit is recommended unless the supervisor explicitly assigns duplicate support cleanup.
- `by-class/ImageLib.md`: final refresh shows same-or-greater detail already present for the constructor and destructor split: [UID:0002IN] emits `ImageLib::ImageLib(int cacheLimit, int)`, [UID:000173] emits the source-authored ordinary destructor body, [UID:0002IO] is listed as compiler scalar deleting wrapper route, and class-level C++ remains blank for broader declaration/header/API-facet issues. If edited during implementation, only synchronize the [UID:0002IO] marker state.
- `by-file/ImageLib.md`: final refresh shows stale "ordinary destructor omitted" wording has been replaced and B001's constructor update is present. It now records [UID:0002IN] constructor emission, [UID:000173] ordinary destructor emission through `NexusTK/render/ImageLib.cpp`, and [UID:0002IO] as compiler wrapper/no-code support. If edited, synchronize the marker wording without moving source cleanup to the wrapper.
- `by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md`: final refresh shows the lower ordinary destructor child is source-ready/emitting and the later scalar wrapper is separate generated-binary glue. Keep the cluster non-emitting; only add [UID:0002IO] marker wording if the page is otherwise touched.
- `by-type/by-struct/ImageLibLayout.md`: final refresh shows B006 added the accepted `+0x0c` destructor field-use detail and B001 added constructor-facing fields. Source C++ now uses `m_pEntryList`, rows are 44-byte `ResourceLayoutNameRecord` entries, row `+0x28` is freed through the destructor, and [UID:0002IO] repeats that cleanup as compiler wrapper parity. No required score change.
- `by-type/by-struct/ResourceLayoutNameRecord.md`: final refresh shows B006 added [UID:000173] evidence that `entries` at `+0x28` is owned payload freed and nulled before list destruction, and that the scalar wrapper repeats the same cleanup. No required score change.
- `by-type/by-vtable/ImageLibVtable.md` and `by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md`: final refresh shows both pages state `0x0061b654 -> 0x004e64a0` remains the correct vtable slot, the ordinary destructor [UID:000173] is not a vtable pointer target, and no pointer route to `0x004d0070` is expected after the source-wrapper split. Do not redirect the slot.
- `by-global/g_pEPFLib.md` and `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md`: final refresh shows both pages record the ordinary destructor source clear at `0x004d00fa`, scalar wrapper parity clear at `0x004e652c`, and source-facing `g_pEPFLib = 0;` represented by [UID:000173]. No required score change.
- `by-class/List.md` and `by-file/List.md`: no required edit unless implementation finds stale wording about the `GetElementAt` slot or virtual delete semantics. Existing docs are support context only.

No support metadata score changes are required by this report unless the implementation pass finds stale or contradictory support text that materially changes a page's confidence/completion.

## Generated And Coverage Handling

- Do not edit `auto-generated/NexusTK/render/ImageLib.cpp` manually. It is generated output.
- Do not edit `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, or any generated report manually.
- Do not edit any manual `-coverage-report.md` file.
- After accepted by-* implementation, run scoped validators. The [UID:0002IO] target validator should include `--wait-generated` because generated output should show the comment-only marker and no longer report this routed target as empty.
- During report-only review, generated rows were current enough to prove B006 execution and [UID:000173] output, while [UID:0002IO] still appeared as non-emitting/empty until its own by-* implementation and target validator ran. After the accepted callback, validator-generated `ImageLib.cpp`, memory coverage, and research-tracker rows now show [UID:0002IO] at `88/92` with the scalar-wrapper marker routed through `ImageLib.cpp`. Do not manually edit generated files.

No manual supervisor-owned coverage replacement text is requested for this report.

## Validator Plan For Accepted Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted edits. Run validators only for support files actually edited, except the target validator is always expected.

> Executable block R001 was removed from this report and preserved verbatim in [0002IO-ImageLibScalarDeletingDestructor-source-quality-removed.md](0002IO-ImageLibScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Because final refresh confirms B006's [UID:000173] by-* implementation is present, the accepted implementation pass can proceed from the current support state. If those docs change again before implementation, re-read them and preserve same-or-greater detail rather than applying this report against stale text.

## Open Questions And Limits

Resolved in this pass:

- Exact scalar deleting destructor range: `0x004e64a0-0x004e6572`.
- Vtable route: `0x0061b654 -> 0x004e64a0`, with constructor/destructor/scalar vptr refs at `0x004d0009`, `0x004d009a`, and `0x004e64d1`.
- Ordinary destructor relationship: [UID:000173] has the same cleanup body minus delete-flag handling and should own source C++.
- Pointer-route blocker: no xrefs and no VA/RVA pointer matches for `0x004d0070`; exactly one VA pointer match for `0x004e64a0` at the vtable slot.
- Delete-flag semantics: `(flags & 1) != 0 && (flags & 4) == 0` calls `sub_4F4AC0(this)`; flag bit `4` routes through `_guard_check_icall_nop@4`.
- C++ disposition: comment-only formal marker, not blank and not handwritten wrapper body.

Remaining:

- Exact original private member spelling for the `+0x0c` list remains inferred. This caps final-audit score but does not block the marker.
- Exact original `ImageLib` / `ResourceLayoutTable` public API split remains open. This affects class/file/header confidence, not the scalar wrapper no-code proof.
- Constructor second argument is now documented in [UID:0002IN] as an unnamed unused `int` in formal source. It has no impact on [UID:0002IO].
- Generated tracker/coverage state now reflects B006 execution for [UID:000173] and the B005 implementation callback for [UID:0002IO]. [UID:0002IO] now appears at `88/92` with generated marker output; supervisor-owned executed-report archival remains separate from this implementation callback. Do not manually edit generated files.

## Changed Files In This Report-Only Pass

- Created/updated: `tools/leaser/Agents/Agent-B005/research/0002IO-ImageLibScalarDeletingDestructor-source-quality.md`
- No by-* docs edited.
- No generated files edited.
- No project-level generated files edited.
- No coverage reports edited.
- No validator/tool state edited.
- No IDA DB edits made.
- No leases taken.

## Changed Files In Implementation Callback

- Updated: `by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md`
- Updated: `by-class/ImageLib.md`
- Updated: `by-file/ImageLib.md`
- Updated: `by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md`
- Updated: `tools/leaser/Agents/Agent-B005/research/0002IO-ImageLibScalarDeletingDestructor-source-quality.md`
- Not edited because current text was already same-or-greater for this callback: `by-type/by-struct/ImageLibLayout.md`, `by-type/by-struct/ResourceLayoutNameRecord.md`, `by-type/by-vtable/ImageLibVtable.md`, `by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md`, `by-global/g_pEPFLib.md`, and `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md`.
- No manual edits to generated files, generated reports, project-level generated files, coverage reports, validator/tool state, IDA DB, or lease state.

## Implementation Tracking Checklist

Report-only pass:

- [x] Read current `Agent-B005/goal.md`.
- [x] Read and applied the project-level `ntk-b-agent-workflow` skill, B-agent research workflow, Rule 26 reference, `Supervisor.md`, and `by-structure.md`.
- [x] Confirmed report-only scope and did not edit by-* docs, generated files, project-level generated files, coverage reports, validator/tool state, or IDA DB.
- [x] Confirmed live IDA MCP availability: `idb_list` session/database `80de0a67`, worker PID `26892`, `server_health` status `ok`, auto-analysis ready, Hex-Rays ready.
- [x] Rechecked target function inventory with MCP `lookup_funcs`: `0x004e64a0` size `0xd2`, `0x004e6572` not a function, successor `0x004e6580`, ordinary destructor `0x004d0070` size `0xab`.
- [x] Rechecked numeric conversions with MCP `int_convert`: `0xd2`, `0xab`, `0x5c`, `0x1c5`, `0x2c`, `0x28`, `0x10`, `0x0c`, `0x0e`, and `0x05`.
- [x] Rechecked target decompile/disassembly and recorded exact cleanup sequence, delete-flag branch, guard path, and `retn 4`.
- [x] Rechecked ordinary destructor decompile and recorded cleanup parity with [UID:0002IO].
- [x] Rechecked component/callee facts with MCP `analyze_component` and `callees`.
- [x] Rechecked xrefs/liveness with MCP: one vtable data xref to `0x004e64a0`, no xrefs to `0x004d0070`, three vtable-slot refs to `0x0061b654`, and lifecycle `g_pEPFLib` refs.
- [x] Rechecked pointer-route evidence with MCP `find_bytes`: scalar VA pointer found once at `0x0061b654`, scalar RVA absent, ordinary VA/RVA patterns absent, vtable immediate pattern found in constructor/destructor/scalar wrapper.
- [x] Rechecked bytes and padding with MCP `get_bytes`.
- [x] Checked current target/support docs, accepted B006 [UID:000173] report, generated `ImageLib.cpp`, generated tracker/coverage rows, and comparable scalar-wrapper precedent [UID:0002VC].
- [x] Final refresh before returning `FINISHED_REPORT`: re-read `tools/leaser/Agents/current_leases.md` and affected target/support docs after B006's [UID:000173] implementation and B001's constructor refresh. Proof: ImageLib files are clear; only unrelated B003 MonsterImageLib leases are active; [UID:000173] now has `90/92` and formal `ImageLib::~ImageLib()` C++; [UID:0002IO] still has `85/90`, blank formal C++, and stale "C++ stays blank" wording; support docs now carry same-or-greater ordinary-destructor/source-wrapper split detail.
- [x] Resume refresh after B006 supervisor execution: recorded execute command id `000000004093`, confirmed `executed-b-agent-research/B006/000173-ImageLibDestructor-source-quality.md`, confirmed `auto-generated/-ag-research-tracker.md` registers [UID:000173] as executed by `B006` at `90/92`, and reconfirmed live MCP session `80de0a67` with current `lookup_funcs`/`xrefs_to`.
- [x] Post-B001 support/generated refresh: re-read currently affected ImageLib support docs and generated `ImageLib.cpp`; confirmed [UID:0002IN] constructor source now emits at `91/92`, support docs now use `m_refCount`, `m_cacheLimit`, `m_pEntryList`, `m_maxCacheSize`, and the unnamed unused second constructor argument, and [UID:0002IO] remains unchanged at `85/90` with an empty formal marker slot.
- [x] Final pre-callback generated-state check: `ImageLib.cpp` header was validator command id `000000004108` / refreshed `2026-06-27T10:32:47-04:00`; generated memory and by-memory coverage headers were `000000004109` / `2026-06-27T10:33:02-04:00`; research tracker header was `000000004112` / `2026-06-27T10:33:26-04:00`. At that report-only point the generated files still showed [UID:0002IO] as non-emitting/empty, which the accepted implementation callback has now corrected through target validator command id `000000004125` and later generated refreshes.

Accepted implementation callback pass:

- [x] Lease exact edit set immediately before editing and release immediately after the edit/validator batch. Proof: leased `by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md`, `by-class/ImageLib.md`, `by-file/ImageLib.md`, and `by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md` as B005 at `2026-06-27T14:39:16Z`, expiring `2026-06-27T14:44:16Z`. Release command at `2026-06-27T10:44:43-04:00` reported `Rejected[No active lease]` for all four because the leases had just expired during validation; the per-agent `current_leases.md` check showed no active B005 rows.
- [x] Reconfirm [UID:000173] ordinary destructor implementation from B006 is still present or same-or-greater in current docs immediately before applying [UID:0002IO] support changes. Proof: target/support reread showed [UID:000173] at `90/92` with formal `ImageLib::~ImageLib()` C++, B006 execute command id `000000004093`, and generated `ImageLib.cpp` already emitting the ordinary destructor.
- [x] Update [UID:0002IO] target metadata to `COMPLETION:88`, `CONFIDENCE:92`, unchanged `CANONICAL_OWNER:00006E`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006E`, blank emitter position. Proof: target header now has those exact values.
- [x] Insert the exact formal marker comment into the [UID:0002IO] multiline `RECONSTRUCTION_CPP CODE` block and keep the inline value blank. Proof: inserted the accepted marker before validation; the target validator then canonicalized `[UID:000173]` to `[UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md)` in the by-* file and generated output. Inline `RECONSTRUCTION_CPP CODE:[[[]]]` remains blank.
- [x] Update [UID:0002IO] status/evidence/source-readiness with current MCP session `80de0a67`, boundary/padding/decompile/disasm/xref/pointer-route/ordinary-destructor parity facts from this report. Proof: target evidence now records endpoint/session/worker/IDB provenance, `0xd2` function size, `0x004e6572` non-function, successor `0x004e6580`, fourteen `0xcc` bytes, xrefs, pointer positives/negatives, callee set, cleanup parity, and delete-flag/guard behavior.
- [x] Preserve rejected alternatives in [UID:0002IO]: no handwritten wrapper, no merge with [UID:000173], no `RECONSTRUCTABLE:FALSE`, no file/global/List/MemoryMan/LObject/ResourceLayoutTable ownership, and no stale blank formal block. Proof: target Autogen Status now has a rejected-alternatives list covering each item.
- [x] Update [UID:0002IO] score rationale and `Item Summary` with the exact recommended disposition. Proof: target has `88/92` score table and Item Summary for the compiler-generated wrapper, vtable-only route, destructor parity, row cleanup, `g_pEPFLib`, base cleanup, delete flag/guard, padding, and formal marker.
- [x] Update `by-class/ImageLib.md` or record already-sufficient proof. Proof: edited method/disposition notes to state [UID:000173] emits source `ImageLib::~ImageLib()` while [UID:0002IO] carries only the formal scalar-wrapper marker; class-level C++ remains blank for broader declaration/header/API issues.
- [x] Update `by-file/ImageLib.md` or record already-sufficient proof. Proof: edited file-level destructor/source split to state `ImageLib.cpp` gets source `ImageLib::~ImageLib()` from [UID:000173] and only the compiler-wrapper marker from [UID:0002IO].
- [x] Update `by-memory/0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md` or record already-sufficient proof. Proof: edited the related tail row and Autogen Status to say the aggregate is non-emitting, [UID:000173] emits ordinary destructor source, and [UID:0002IO] is separate generated-binary scalar wrapper glue with marker only.
- [x] Update `by-type/by-struct/ImageLibLayout.md` or record already-sufficient proof. Proof: re-read and left unchanged because it already records the `+0x0c` `m_pEntryList` field, B001/B006 constructor/destructor field evidence, and wrapper parity at same-or-greater detail for this callback.
- [x] Update `by-type/by-struct/ResourceLayoutNameRecord.md` or record already-sufficient proof. Proof: re-read and left unchanged because it already records `entries` at `+0x28` as the payload freed/nulled by the ordinary destructor and repeated by scalar wrapper cleanup.
- [x] Update `by-type/by-vtable/ImageLibVtable.md` and/or `by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md` only if needed. Proof: re-read and left unchanged because both already keep `0x0061b654 -> 0x004e64a0` and document that no pointer route to the ordinary destructor start is expected.
- [x] Update `by-global/g_pEPFLib.md` and/or `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md` only if needed. Proof: re-read and left unchanged because both already record the source-facing clear through [UID:000173] and scalar wrapper parity clear at `0x004e652c`.
- [x] Do not edit generated files, generated reports, project-level generated files, validator/tool state, IDA DB, or any `-coverage-report.md`. Proof: all generated/project-level changes came from validator commands only; no manual edits were made to excluded files.
- [x] Run scoped validators for every edited by-* file; target validator must use `--wait-generated`. Proof:
  - `python .\tools\validator.py --mode file --file by-memory\0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md --apply --queue-timeout 240 --wait-generated` from `E:\NTK\GhidraBridge\source-3\project-documentation`; command id `000000004125`, timestamp `2026-06-27T10:41:38-04:00`, exit code `0`, `ok: 1`, generated refresh `completed`.
  - `python .\tools\validator.py --mode file --file by-class\ImageLib.md --apply --queue-timeout 240`; command id `000000004126`, timestamp `2026-06-27T10:41:54-04:00`, exit code `0`, `ok: 1`, generated refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-file\ImageLib.md --apply --queue-timeout 240`; command id `000000004127`, timestamp `2026-06-27T10:42:01-04:00`, exit code `0`, `ok: 1`, generated refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-memory\0x004cffb0-0x004d011b.ImageLibLifecycleCluster.md --apply --queue-timeout 240`; command id `000000004128`, timestamp `2026-06-27T10:42:09-04:00`, exit code `0`, `ok: 1`, generated refresh `deferred`.
- [x] Report validator command, working directory, command id, timestamp, exit code, `ok` count, generated refresh state, and any warnings. Proof: captured above. Target validator reported unrelated stale/missing registry warnings plus expected updates: `completion_update`, `confidence_update`, `autogen_registry_update`, `autogen_cpp_update:1`, `memory_auto_coverage_update:1`, `research_tracker_update:1`, and `projected_stats_update:1`.
- [x] Confirm generated `auto-generated/NexusTK/render/ImageLib.cpp` is current for the target validator and contains [UID:0002IO] marker output if generated refresh completed. Proof: generated header is command id `000000004127`, refreshed `2026-06-27T10:42:01-04:00`, newer than target command `000000004125`; it contains [UID:0002IO] at `88/92` followed by the marker comment.
- [x] Confirm generated queue and generated report state. Proof: `python .\tools\validator.py --queue-status` command id `000000004131`, timestamp `2026-06-27T10:44:43-04:00`, exit code `0`, showed worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, and processing generated refresh jobs `0`. Generated memory coverage shows [UID:0002IO] as coded/emitting to `auto-generated/NexusTK/render/ImageLib.cpp`; research tracker shows [UID:0002IO] at `88/92`.
- [x] Release all B005 leases immediately after validators and verify no active B005 leases remain. Proof: release attempt returned no active leases after expiry; `tools/leaser/Agents/Agent-B005/current_leases.md` showed no B005 rows.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002IO-ImageLibScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002IO-ImageLibScalarDeletingDestructor-source-quality.md","timestamp":"2026-06-27T10:50:12","uid":"0002IO"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002IO-ImageLibScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0002IO-ImageLibScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002IO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
