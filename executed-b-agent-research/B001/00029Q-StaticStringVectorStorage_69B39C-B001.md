** TARGET-REPORT-UID:00029Q **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00029Q StaticStringVectorStorage_69B39C Ownership Research

Revision: B001-001 / supervisor override active recheck / IDA MCP ownership audit / PE zero-fill repair / finalized recommendation, 2026-06-13

## Finalized Report / Current Recommendation

- Target UID/path: [UID:00029Q] `by-memory/0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C.md`.
- Final recommendation: create a new narrow by-global page, provisionally `by-global/StaticSimpleUStringVector_69B39C.md`, for the exact source-declared static vector object at `0x0069b39c-0x0069b3a8`. Parent that new global to [UID:0000OB] `StringUtil`, then set [UID:00029Q] `AUTOGEN_PARENT_UID` to the new by-global UID.
- Recommended classification: reconstructable zero-initialized three-pointer static vector control block for inline `0x18` / 24-byte SSO `SimpleUString`-layout elements. No range split is needed.
- Do not attach [UID:00029Q] directly to [UID:00024F] cleanup thunks, [UID:0000W9] static initializer wrappers, [UID:0000L7] MemoryMan, [UID:0000OT] TimerMgr, [UID:0000LG] MiscWorkThread/NCA URL storage, MetaMan, MIDI, image tables, `g_emptySimpleUString`, or the existing [UID:0000DA] `SimpleUStringVector` class.
- Confidence: `94/100` for exact storage/range/lifetime behavior, `93/100` for zero-filled initial state after live IDA and PE mapping, `86/100` for StringUtil/SimpleUString source-family ownership, and `30/100` for original variable spelling or purpose.
- Current target page state after B001 repair: `COMPLETION:88`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`, parent intentionally blank until the new by-global parent exists.
- Report state: final and ready for supervisor execution. The remaining work is mechanical creation/application, not more ownership research.

## Supporting Research

## Target Context

- Assigned row: `[UID:00029Q] by-memory/0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C.md`.
- Supervisor status on intake: reviewed-85-but-ownership-unknown after A003 raised the target to `87/93` and left parent blank.
- B001 scope: one-at-a-time ownership research, use live IDA MCP and existing docs, do not trust previous ownership/byte claims without evidence, and do not edit `by-memory/-coverage-report.md`.
- Lease: B001 held the target-page lease during the target repair and report work.

## Executive Result

The prior "ownership unknown, do nothing" stance is no longer the best route. The binary does not reveal a normal-use caller or original variable name, but the best defensible source model is strong enough to act:

- This storage is not a cleanup function or startup wrapper. The code at `0x0060c160` and `0x00419f40` is compiler/static-lifetime glue for a source-declared object.
- This storage is not the existing `SimpleUStringVector` class page. That page models a 4-byte pointer-backed string-handle vector; this storage is a three-pointer vector whose elements are inline 24-byte SSO string objects.
- This storage is best represented as its own by-global static object under StringUtil. The owning source family is StringUtil/SimpleUString because the element destructor exactly matches the 24-byte SSO layout, StringUtil already owns the related string support and `g_emptySimpleUString`, and the startup table places this static registration immediately after `g_emptySimpleUString`.

The new global should be narrow. It should contain this static vector object and its exact storage child only. It should not absorb `g_emptySimpleUString`, the `SimpleUString` class, the pointer-backed `SimpleUStringVector` class, MemoryMan, TimerMgr, NCA URL storage, MetaMan, image tables, or MIDI state.

## IDA MCP Facts

Live IDA MCP session used the loaded `NexusTK.exe` image. The facts below are direct evidence unless labeled as inference.

### Storage and Initial State

- Target address/range: `0x0069b39c-0x0069b3a8`, size `0x0c` / 12 bytes.
- Slot layout:
  - `0x0069b39c-0x0069b3a0`: begin pointer.
  - `0x0069b3a0-0x0069b3a4`: end pointer.
  - `0x0069b3a4-0x0069b3a8`: capacity/end-of-storage pointer.
- Live `get_bytes(0x0069b39c, 12)` returned twelve zero bytes.
- Live `get_int` for `0x0069b39c`, `0x0069b3a0`, and `0x0069b3a4` returned `0`, `0`, and `0`.
- PE section mapping explains why the raw file has no bytes for this object:
  - `.data` RVA range: `0x0026d000-0x0029ce24`.
  - `.data` raw-backed range: `0x0026ac00-0x00278400`, raw size `0x0000d800`.
  - Target RVA: `0x0029b39c`.
  - Inference from PE layout: target lies in the loader-zero-filled `.data` virtual tail, past raw file coverage.
- Earlier page claims that the three dwords were `0xffffffff` are superseded by the live zero-fill check.

### Direct Xrefs

| Target | Direct refs | Function | Meaning |
| --- | --- | --- | --- |
| `0x0069b39c` | `0x0060c161`, `0x0060c1d3`, `0x0060c21c` | `sub_60C160` | begin read/read/clear |
| `0x0069b3a0` | `0x0060c170`, `0x0060c226` | `sub_60C160` | end read/clear |
| `0x0069b3a4` | `0x0060c1d9`, `0x0060c230` | `sub_60C160` | capacity read/clear |
| `0x0069b3a8` | `0x00419f70`, `0x0060c260` | MemoryMan initializer/reset | separate next object |
| `0x0069b3d0` | `0x00419f50`, `0x00502ece`, `0x0051404e`, `0x00527c71`, `0x00527c7f`, `0x0060c250` | NCA URL string and consumers | separate later object |

IDA found no names in the nearby `0x0069b330-0x0069b3f0` data window that identify a larger owner. Nearby ref checks also keep the half-open range clean: predecessor points such as `0x0069b381` and `0x0069b398` have no direct refs, while `0x0069b3a8` starts MemoryMan storage.

### Cleanup and Initializer Behavior

- Decompilation of `0x0060c160` loads begin/end/capacity from the three target dwords.
- The cleanup tests begin, walks from begin to end in `0x18` / 24-byte elements, and for each element:
  - reads element capacity at offset `+0x14`;
  - frees heap string payloads when capacity is at least `8`;
  - handles large-allocation validation before free;
  - resets length/capacity to empty SSO state (`+0x10 = 0`, `+0x14 = 7`, first word zero).
- The cleanup then frees the backing vector allocation and clears the three control words to zero.
- Decompilation of `0x00419f40` is only `atexit(sub_60C160)`. It constructs no object and performs no semantic initialization.

### Raw Executable and Pattern Checks

- Raw VA pattern hits for `0x0069b39c` occur only at file offsets corresponding to `0x0060c161`, `0x0060c1d3`, and `0x0060c21c`.
- Raw VA pattern hits for `0x0069b3a0` occur only at offsets corresponding to `0x0060c170` and `0x0060c226`.
- Raw VA pattern hits for `0x0069b3a4` occur only at offsets corresponding to `0x0060c1d9` and `0x0060c230`.
- RVA patterns `0x0029b39c`, `0x0029b3a0`, and `0x0029b3a4` have zero raw hits.
- IDA `find_bytes` for the VA immediates agrees with the direct xref set.

Inference: there is no hidden non-cleanup reference, normal-use path, pointer table, or raw metadata reference for this storage in the available binary.

### Startup Table Context

IDA `get_int` on the nearby initializer table gives this order:

| Table address | Initializer | Current interpretation |
| --- | --- | --- |
| `0x0060d6a0` | `0x00419f00` | clears `unk_69B350` / `unk_69B354` |
| `0x0060d6a4` | `0x00419f20` | constructs [UID:0000PW] `g_emptySimpleUString` |
| `0x0060d6a8` | `0x00419f40` | registers this static vector cleanup |
| `0x0060d6ac` | `0x00419f70` | constructs MemoryMan static object |
| `0x0060d6b0` | `0x00419f90` | constructs TimerMgr static object |
| `0x0060d6b4` | `0x00419f50` | constructs NCA URL static string |
| `0x0060d6b8` | `0x00419fb0` | image table static |
| `0x0060d6bc` | `0x00419fd0` | riding table static |
| `0x0060d6c0` | `0x00419ff0` | MetaMan alias string |
| `0x0060d6c4` | `0x0041a010` | MIDI state |

Inference: the table is heterogeneous and cannot prove ownership by address order alone. It does, however, support StringUtil/SimpleUString as the best source family because the target registration immediately follows the StringUtil-owned `g_emptySimpleUString` initializer and the target cleanup destroys inline 24-byte SSO string elements.

## Documentation Evidence Checked

- [UID:0000W9] `StaticInitializerWrappersAfterOle` documents `0x00419f40` as wrapper glue. IDA confirms this and supports rejecting the wrapper as direct owner.
- [UID:00024F] `StaticStringContainerCleanupThunks` documents `0x0060c160` as a static string-container cleanup thunk. IDA confirms this and supports rejecting the cleanup thunk as direct owner.
- [UID:0000OB] `StringUtil` owns string utility coordination, `SimpleUString`, `SimpleUStringVector`, `StringIter`, and `g_emptySimpleUString`. This is source-family evidence, not direct proof by itself.
- [UID:0000D9] `SimpleUString` documents the 24-byte SSO-7 object layout, length at `+0x10`, capacity at `+0x14`, inline capacity `7`, and heap threshold `8`. IDA target cleanup matches this element layout.
- [UID:0000DA] `SimpleUStringVector` documents a 4-byte pointer-backed string-handle vector. This contradicts using that class page as the direct parent for the target's inline 24-byte-element vector.
- [UID:0000PW] `g_emptySimpleUString` and [UID:00027J] exact storage prove the project already models narrow by-global storage under StringUtil for static string objects. This supports creating a similar narrow by-global for the target.
- [UID:0000L7] MemoryMan, [UID:0000OT] TimerMgr, [UID:0000LG] MiscWorkThread/NCA URL string, MetaMan alias string, image table storage, and MIDI state are neighboring startup/static objects with their own evidence. IDA confirms they are separate objects, not owners of this vector.

Existing documentation treated as incorrect or superseded:

- The target page and some adjacent old notes claimed the bytes were all `0xff` / dwords `0xffffffff`. Live IDA and PE mapping contradict this. B001 repaired the target page only; adjacent stale byte-state pages should be audited separately if needed.

## Ranked Ownership Analysis

### 1. New by-global `StaticSimpleUStringVector_69B39C` under StringUtil

Recommendation rank: best and actionable.

Evidence for:

- IDA proves a source-declared static vector object: three control pointers, a cleanup registered by `atexit`, and backing storage freed at process shutdown.
- IDA proves inline 24-byte SSO string elements by the cleanup loop, `+0x10/+0x14` fields, capacity threshold `8`, reset capacity `7`, and first-word zero terminator.
- StringUtil already owns the SSO string infrastructure and `g_emptySimpleUString`.
- Startup order places this registration immediately after `g_emptySimpleUString`.
- No other direct owner has a normal-use xref, constructor, source metadata, or coherent neighbor cluster.

Evidence against:

- Original variable spelling and purpose are not recovered.
- No normal-use insertion/initialization function has been found.
- The StringUtil placement is inferred from type/source-family evidence and startup adjacency, not from debug metadata.

Conclusion: create the by-global and attach it to StringUtil. Then attach the exact by-memory storage to the new by-global.

Confidence: `86/100` for source-family/global-parent route; higher for storage itself.

### 2. Direct parent to StringUtil without a by-global

This is plausible but less correct. The direct semantic parent of a storage page should be the source-declared global object, not the broad source file. StringUtil should be the parent of the new by-global, and the by-memory page should parent to that global.

Conclusion: use StringUtil as source root, not as the direct target parent.

### 3. Existing `SimpleUString` or `SimpleUStringVector` class pages

`SimpleUString` is strong element-type evidence, but the target is a static container object, not a class method or instance layout page. `SimpleUStringVector` is explicitly the wrong direct type because it models 4-byte pointer-backed string-handle slots, not inline 24-byte SSO elements.

Conclusion: use as context only.

### 4. `g_emptySimpleUString`

The startup adjacency is useful, and `g_emptySimpleUString` proves StringUtil-owned static string-object modeling. But it is a separate 24-byte static object at `0x0066daec-0x0066db04`, not the parent of this vector.

Conclusion: supporting sibling/context only.

### 5. MemoryMan, TimerMgr, MiscWorkThread/NCA URL, MetaMan, MIDI, image/riding tables

These are nearby static objects, not owners. IDA shows their distinct storage, constructors, destructors, and xref families. Physical adjacency in the startup table is heterogeneous and cannot override object boundaries.

Conclusion: rejected.

### 6. Cleanup thunk or static initializer wrapper

`0x0060c160` is destructor/lifetime code and `0x00419f40` only registers it with `atexit`. They are compiler/runtime glue and should not be modeled as direct source owners.

Conclusion: rejected.

### 7. Leave unassigned as final state

Temporarily leaving [UID:00029Q] parent-blank is correct until the new by-global exists, but stopping there is too weak. The evidence justifies a concrete new-global route under StringUtil.

Conclusion: rejected as final recommendation.

## Proposed New By-Global

Proposed path:

```text
by-global/StaticSimpleUStringVector_69B39C.md
```

Proposed intent:

- Represents the exact source-declared static vector object whose storage is [UID:00029Q] `0x0069b39c-0x0069b3a8`.
- Parent: [UID:0000OB] `StringUtil`.
- Score target after creation: about `86/86` or better if the supervisor accepts the evidence in this report.
- Reconstructable: `TRUE`.
- C++ should remain descriptive, not final original spelling:

```cpp
// Reconstructed descriptive name; original variable spelling is not recovered.
static std::vector<SimpleUString> StaticSimpleUStringVector_69B39C;
```

Recommended initial contents and cross-links:

- Exact storage child: [UID:00029Q] `by-memory/0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C.md`.
- Type/context links: [UID:0000D9] `SimpleUString`, [UID:0000OB] `StringUtil`, [UID:0000PW] `g_emptySimpleUString`.
- Lifetime/context links: [UID:00024F] cleanup thunk page and [UID:0000W9] initializer wrapper page, clearly labeled as compiler/runtime glue.

Exclude from the new global:

- `g_emptySimpleUString` storage, `SimpleUString` methods, `SimpleUStringVector` pointer-backed methods, MemoryMan/TimerMgr/NCA URL storage, MetaMan alias string, image/riding table storage, and MIDI state.

## Target Page Repair Applied

B001 repaired the target page because ownership could not be judged cleanly while the byte state was wrong.

Applied to [UID:00029Q]:

- Raised completion from `87` to `88`; confidence remains `93`.
- Corrected bytes from stale `ff ff ...` to twelve zero bytes.
- Added PE zero-fill explanation for RVA `0x0029b39c`.
- Added 2026-06-13 IDA MCP evidence for zero dwords, startup-table context, and StringUtil/SimpleUString recommendation.
- Kept `AUTOGEN_PARENT_UID` blank pending creation of the by-global parent.
- Left final C++ blank because the original variable name and normal use path remain unrecovered.

No memory range split or child repair was required.

## Validation Evidence

Command run:

> Executable block R001 was removed from this report and preserved verbatim in [00029Q-StaticStringVectorStorage_69B39C-B001-removed.md](00029Q-StaticStringVectorStorage_69B39C-B001-removed.md). The archived block is non-authoritative and must not be executed.

Validator result summary:

- Exit code `0`.
- `ok: 1`.
- `completion_update 00029Q ... 88`.
- Reference index additions reported for `0000D9`, `0000DA`, `0000OB`, and `0000PW`.
- `autogen_report_update` refreshed validator-owned `auto-generated/-ag-memory-coverage.md`.
- `projected_stats_update` refreshed `project-level/-auto-completion-stats.md`.
- `by-memory/-coverage-report.md` was not edited.

## Supervisor-Owned Coverage Row

Do not edit `by-memory/-coverage-report.md` directly from this report. The exact row replacement should be applied by the supervisor at the current placement under [UID:0001Z8] `0x0066d000-0x0069d000.DataSection`, after [UID:00029P] and before [UID:00029R].

Replace the current [UID:00029Q] row with:

```markdown
    - [UID:00029Q][0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C](by-memory/0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C.md) 0x0069b39c-0x0069b3a8 | static container storage | StaticStringVectorStorage_69B39C : reconstructable : 88% : very-strong : Zero-filled three-pointer static vector control block for `0x18` / 24-byte SSO string elements; B001 live IDA/PE repair confirms the storage lies in the loader-zero-filled `.data` virtual tail, all direct refs and raw VA hits are confined to cleanup body `0x0060c160`, `0x00419f40` only registers that cleanup with `atexit`, and the best direct route is a new by-global static-vector parent under StringUtil/SimpleUString support while the original variable name and purpose remain unrecovered.
```

## Recommended By-* Edits

Supervisor/A-agent sequence:

- Create `by-global/StaticSimpleUStringVector_69B39C.md` with parent [UID:0000OB] `StringUtil`.
- Validate the new by-global so it receives a UID and reference-index updates.
- Set [UID:00029Q] `AUTOGEN_PARENT_UID` to that new global UID.
- Update this report's coverage row text in `by-memory/-coverage-report.md` using the exact row above.
- Do not update adjacent stale byte-state pages in this ownership action unless the supervisor opens a separate zero-fill audit for the wider `.data` virtual-tail neighborhood.

## Negative Evidence Summary

- No normal-use caller, insertion function, constructor path, pointer table, source string, PDB/debug source path, or original variable name was found.
- No raw RVA-style hits exist for the target dwords.
- No IDA name exists for the target or nearby owner block.
- Cleanup and startup wrapper evidence proves lifetime, not ownership.
- Existing docs that claimed `0xffffffff` bytes were wrong for the live IDA/PE state.
- Address adjacency to MemoryMan, TimerMgr, NCA URL, image/riding tables, MetaMan, or MIDI is heterogeneous and not ownership evidence.

## Final Recommendation

Create `by-global/StaticSimpleUStringVector_69B39C.md`, parent it to [UID:0000OB] `StringUtil`, then attach [UID:00029Q] to that new global. Treat `StaticSimpleUStringVector_69B39C` as a descriptive reconstruction name, not a recovered symbol. The report is final for supervisor execution.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00029Q-StaticStringVectorStorage_69B39C-B001.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"00029Q"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00029Q-StaticStringVectorStorage_69B39C-B001-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00029Q-StaticStringVectorStorage_69B39C-B001.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00029Q"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
