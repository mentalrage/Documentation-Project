** TARGET-REPORT-UID:00013Y **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00013Y ErrorBaseCleanupHelper Source-Quality Report

Status: FINISHED_REPORT_REVISED

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00013Y] `by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md` as a reconstructable Error hierarchy cleanup-support range routed through [UID:0000J5] `by-file/Error.md`; insert a minimal Rule 28 formal `RECONSTRUCTION_CPP CODE` comment marker instead of leaving the emitter block empty.
- Final disposition: exact helper remains real project-owned executable support, but executable source for the behavior should be folded into ordinary Error hierarchy destructor/unwind source shape rather than emitted as a named product helper. The formal block should still contain a comment marker so generated trackers do not classify [UID:00013Y] as an empty emitter.
- Required action: update the target and support docs with the 2026-06-27 MCP-backed evidence, raise the target to `COMPLETION:88`, `CONFIDENCE:91`, leave owner/emitter route unchanged, insert the accepted marker comment, and create/synchronize the exact sibling child for current MCP-modeled `sub_4A6470` at `0x004a6470-0x004a647b`.
- Confidence: strong for exact bytes, range, body, base-vtable store, tail jump, no-direct-xref/no-pointer route, and `Error.cpp` source placement; medium-high for the final source shape because no direct call-site or original source symbol proves whether the original compiler named or folded the helper.

No by-* docs, generated reports, source files, IDA database state, validator state, or manual coverage reports were edited in this report-only pass.

## Target

- Target UID: `00013Y`.
- Target path: `by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md`.
- Assignment id: `B005-report-00013Y-ErrorBaseCleanupHelper-source-quality-20260627`.
- Required report path: `tools/leaser/Agents/Agent-B005/research/00013Y-ErrorBaseCleanupHelper-source-quality.md`.
- Primary queue row: `auto-generated/-ag-research-tracker.md` under `## by-memory` / `### Not-Covered Files - Reconstructable`, row for [UID:00013Y], showing stale/generated `78/88`.
- Current source-page state before recommended implementation: `COMPLETION:85`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000J5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J5`, currently empty formal C++.
- Current generated-output observation: `auto-generated/NexusTK/util/Error.cpp` was refreshed at `2026-06-27T06:04:11-04:00` with `validator-command-id: 000000003881`; it contains an empty emitter marker for [UID:00013Y] but still prints stale `Completion:78 | Confidence:88`.

## Current Target State

- Existing metadata correctly classifies the range as reconstructable project code and routes it through [UID:0000J5] `Error.cpp`.
- Existing body text already records the key behavior: `sub_4A6400` writes `Error::vftable` to `this`, then tail-jumps to inherited cleanup at `sub_4F4A90`.
- Existing open blockers were the same ones the assignment named: no direct start xrefs, source-facing name uncertainty, whether this should be a named helper or folded destructor/unwind cleanup, and whether formal C++ is safe.
- Current support docs checked: [UID:00013X] `ErrorWrappers`, [UID:0000J5] `Error`, [UID:00004J] `Error`, [UID:00004K] `ErrorMessage`, [UID:00004X] `FileError`, [UID:00013Z] `ErrorMessageCopyMessage`, [UID:000140] `FileErrorCopyMessage`, [UID:0002TV] `ErrorDestructorAndNameHelpers`, [UID:0001XI] `ErrorHierarchyVtables`, [UID:0001UE] `ErrorObjectLayouts`, and [UID:0002ND] `ErrorHierarchyVtableData`.
- Prior executed B reports checked: B013 `00013X-ErrorWrappers-source-quality.md`, B002 `0002TV-error-destructor-name-helpers-source-quality.md`, B002 `00013Z-ErrorMessageCopyMessage-source-quality.md`, B002/B012 `0002HL-FileErrorConstructor-source-quality.md`.

## Supervisor Active Recheck

- The supervisor/user assigned one report-only research target: [UID:00013Y].
- No split repair is required for the assigned target range itself. The target is exact as `[0x004a6400, 0x004a640b)`.
- A related sibling cleanup island at `[0x004a6470, 0x004a647b)` still lacks an exact by-memory child. This pass investigated it because it limits support-doc source shape. Current MCP now models it as a real function, `sub_4A6470`, size `0x0b`; the implementation-ready repair is to create a separate exact child now at `by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md` as associated source-quality/split repair during the accepted implementation callback.

## Evidence Checked

IDA MCP was available and used as authoritative live evidence for this pass.

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Tool flow: `initialize`, `tools/list`, `idb_list`, `server_health`, then read-only `lookup_funcs`, `analyze_batch`, `xrefs_to`, `callees`, `get_bytes`, and `find_bytes`.
- Active session: `80de0a67`, owned/adopted worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `pid=26892`, `worker_pid=26892`, `is_analyzing=false`.
- `server_health`: `status=ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`, strings cache size `2067`.
- `lookup_funcs`: `0x004a6400 -> sub_4A6400 size 0x0b`; `0x004a640b -> Not a function`; `0x004a63fc -> Not a function`; `0x004a6410 -> sub_4A6410 size 0x19`; `0x004f4a90 -> sub_4F4A90 size 0x7`; `0x004a6470 -> sub_4A6470 size 0x0b`; `0x00619344 -> Not a function`.
- `analyze_batch 0x004a6400`: prototype `void __thiscall(_DWORD *this)`, decompile `*this = &Error::vftable; sub_4F4A90(this);`, disassembly `mov dword ptr [ecx], offset ??_7Error@@6B@` then `jmp sub_4F4A90`, two instructions, one constant `0x619344`, no callers, no incoming xrefs, no strings.
- `xrefs_to 0x004a6400`: no cross-references.
- `xrefs_to 0x00619344`: ten base-vtable restore references, including `0x004a6400`, `0x004a6470`, `0x004a6874`, `0x004a6890`, `0x004a68a6`, `0x004a68e6`, `0x004a6926`, `0x004a6976`, `0x004a69d0`, and `0x004a6a27`.
- `xrefs_to 0x004f4a90`: includes the target tail jump at `0x004a6406` and the sibling cleanup tail jump at `0x004a6476` among many inherited-cleanup callers.
- `callees 0x004a6400`: empty because the inherited cleanup route is encoded as a tail `jmp`, not a normal call.
- `get_bytes 0x004a63f0 size 64`: confirms the previous raw constructor-shaped body returns at `0x004a63fb`, four `0xcc` bytes at `0x004a63fc-0x004a6400`, target bytes at `0x004a6400-0x004a640b`, five `0xcc` bytes at `0x004a640b-0x004a6410`, then `sub_4A6410`.
- `get_bytes 0x004a6400 size 11`: `c7 01 44 93 61 00 e9 85 e6 04 00`.
- `get_bytes 0x004a640b size 5`: `cc cc cc cc cc`.
- `find_bytes 00 64 4A 00` and `find_bytes 00 64 0A 00`: no little-endian VA/RVA pointer hits for the target start.
- `find_bytes C7 01 44 93 61 00 E9 85 E6 04 00`: one match at `0x004a6400`.
- `analyze_batch 0x004a6470`: prototype and body match the target source role: write `Error::vftable`, tail-jump to `sub_4F4A90`, no callers, no incoming xrefs, constant `0x619344`.
- `xrefs_to 0x004a6470`: no cross-references.
- `get_bytes 0x004a6470 size 11`: `c7 01 44 93 61 00 e9 15 e6 04 00`; `get_bytes 0x004a647b size 5`: `cc cc cc cc cc`.
- `find_bytes 70 64 4A 00` and `find_bytes 70 64 0A 00`: no little-endian VA/RVA pointer hits for the sibling start.
- `find_bytes C7 01 44 93 61 00 E9 15 E6 04 00`: one match at `0x004a6470`.
- Conversion check: `python .\tools\int_convert.py 0x0b` reports decimal `11`, so `0x0b` is 11 bytes (Verified with int_convert.py).
- Failed/unavailable checks: none. No MCP timeout, stale session, connection refusal, or fallback-only evidence path occurred.

## Inference Research Guidance Check

- IDA facts are separated from inference. The range, bytes, vtable immediate, tail jump, padding, lack of xrefs, and duplicate sibling function are live MCP facts from session `80de0a67`.
- Documentation evidence comes from current by-* docs and executed B reports. Older Wave2/Wave3/simroot-generated one-class files were not accepted as authority.
- The accepted inference is source-shape only: this helper is most plausibly compiler/unwind cleanup or destructor support generated around Error hierarchy construction/destruction, not a human-authored product method that should appear as `ErrorBaseCleanupHelper()` in final C++.
- Disconfirming evidence was checked: direct start xrefs are absent, direct callers are absent, VA/RVA pointer-byte hits are absent, and the same body shape appears again at `0x004a6470` as another no-route cleanup island. These negatives reject a normal source-visible helper name.

## Heuristic / Inference Reanalysis And Validation

### Helper Liveness

The helper is live binary code, not padding or dead data. IDA models `0x004a6400` as a real function; bytes and disassembly are executable; it writes a project-owned vtable pointer and transfers to the inherited cleanup path. The absence of direct callers does not make it ignorable because destructor/EH cleanup helpers can be reached through compiler-generated unwind paths or can survive as ABI support without direct call-site recovery.

### Source-Facing Name

`ErrorBaseCleanupHelper` is a good documentation filename/name because it describes the observed binary role. It should not become a final C++ source method name. The target has no vtable slot, no direct call route, and no original symbol proof. If IDA comments or local analysis names are later applied, a descriptive label such as `ErrorBaseCleanupHelper` is acceptable for `sub_4A6400`, with a comment that it is cleanup/unwind support, not a source-visible API.

Rejected names:

- `Error::~Error`: rejected for this exact range because the base scalar deleting destructor is separately documented at `0x004a68e0`; this helper is only the non-deleting base-vtable reset plus inherited cleanup tail.
- `LObject` helper: rejected because the function writes `Error::vftable` before tail-jumping to `sub_4F4A90`; `LObject` is the cleanup callee, not the owner.
- `ErrorMessage` method: rejected because adjacency to the raw `ErrorMessage` constructor and copy helper is insufficient; the body writes the base `Error` vtable, not the `ErrorMessage` vtable.
- `FileError` helper: rejected for this target because the FileError-adjacent duplicate is `0x004a6470`, not `0x004a6400`.

### Owner And Emitter Route

Keep `CANONICAL_OWNER:0000J5` and `EMITTER_UIDS:0000J5`.

The [UID:00004J] `Error` class is semantically relevant and should cross-link this helper, but using the file as direct canonical owner is still the better metadata choice for this exact page because the helper is not a source-visible `Error` method. It is a file-local cleanup/unwind island generated from the shared Error hierarchy implementation. Routing it directly through `Error.cpp` preserves ownership without forcing class-level method C++ that the evidence does not support.

### Range / Split / Padding

The target's own range is exact:

- Previous meaningful byte window ends with `c3` at `0x004a63fb`.
- Four `0xcc` padding bytes occupy `0x004a63fc-0x004a6400`.
- Target body occupies `0x004a6400-0x004a640b`.
- Five `0xcc` padding bytes occupy `0x004a640b-0x004a6410`.
- The next modeled function starts at `0x004a6410`.

No split is needed inside [UID:00013Y].

The related `0x004a6470-0x004a647b` sibling now has stronger evidence than the B013 report had: current MCP models it as `sub_4A6470` size `0x0b`. It remains outside [UID:00013Y], so it should not be merged into this target; it should get its own exact child page now as associated repair: `by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md`, reconstructable true, canonical owner/emitter [UID:0000J5] unless a later accepted class-specific source pass proves a better direct owner.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Remaining uncertainty |
| --- | --- | --- | --- | --- |
| `0x004a6400-0x004a640b` is an exact real function body. | Confirmed | MCP `lookup_funcs`, `analyze_batch`, `get_bytes`; end-exclusive `0x004a640b` not a function; surrounding `0xcc` padding. | Neighbor starts/endpoints checked. | None for binary bounds. |
| Body resets the object to the base `Error` vtable and tail-jumps to inherited cleanup. | Confirmed | Disasm `mov [ecx], ??_7Error@@6B@`; `jmp sub_4F4A90`; decompile writes `Error::vftable`. | Checked `callees` empty because this is a tail jump, not a call. | None for behavior. |
| No direct start route exists. | Confirmed negative | `xrefs_to 0x004a6400` empty; callers empty; VA/RVA pointer-byte scans empty. | Checked both full VA `00 64 4A 00` and RVA-style `00 64 0A 00`. | Indirect EH/unwind metadata route is not recovered by these tools. |
| The helper belongs with `util/Error.cpp`. | Strong | Writes `Error` vtable; `xrefs_to 0x00619344` matches destructor-family stores; support docs place hierarchy in [UID:0000J5]. | Rejected caller-subsystem ownership, `LObject`, `ErrorMessage`, and `FileError` target-local ownership. | Exact original source file name/path not proven beyond project reconstruction route. |
| Formal C++ should contain a Rule 28 marker comment, not an executable helper body. | Strong | [UID:00013Y] is a designated emitter, but no direct source-visible route exists; duplicate no-route helper at `0x004a6470`; destructor/name-helper policy says source should express ordinary destructors, not ABI cleanup wrappers; Supervisor Rule 28 requires a comment marker for emitter ranges represented by another source owner. | Considered a named helper body and rejected it because it would encode compiler/unwind support as product source. Also rejected leaving the formal block empty because Rule 28 says a covered emitter should still emit `//` or a covered-by marker. | A later `Error.h`/`Error.cpp` destructor pass may replace or refine the marker if it proves an executable source body is required. |
| `0x004a6470-0x004a647b` should be created as a sibling exact cleanup child now. | Strong | Current MCP `lookup_funcs` and `analyze_batch` model `sub_4A6470` as the same two-instruction body shape, no xrefs, unique bytes. | Rejected merging into [UID:0002HL] or [UID:000140] because padding separates the function from both. Rejected deferral because current MCP support supplies exact range/body/provenance and the missing child is a known support-doc/source-quality blocker. | UID will be assigned/validated when the new by-memory file is created. |

## Positive Evidence Summary

- The target has exact live MCP function, byte, decompile, and disassembly evidence.
- The helper writes the concrete `Error` base vtable at `0x00619344`, which is also restored by the destructor-family functions documented in [UID:0002TV].
- The helper's no-direct-start-xref state is now supported by both IDA xrefs and raw VA/RVA pointer scans.
- The sibling `0x004a6470` body, now live-modeled as `sub_4A6470`, confirms this pattern is cleanup/unwind support in the Error hierarchy rather than a one-off product method.
- Current support docs already establish [UID:0000J5] `Error.cpp`, [UID:00004J] `Error`, [UID:0001XI] vtable layout, [UID:0001UE] object layouts, and [UID:0002ND] vtable data as the correct source family.

## Negative Evidence Summary

- No incoming code or data xrefs to `0x004a6400`.
- No direct callers in `analyze_batch`.
- No little-endian VA or RVA pointer-byte hits for `0x004a6400`.
- No vtable slot points to `0x004a6400`; the `Error` base vtable destructor slot is `0x004a68e0`, and message/name slots are separate.
- The helper is not part of the preceding raw constructor-shaped range; four `0xcc` bytes separate them.
- The helper is not part of [UID:00013Z]; five `0xcc` bytes separate the end of this helper from `0x004a6410`.

## Ranked Ownership Analysis

### 1. [UID:0000J5] `Error` source file

- Evidence for: exact helper writes `Error::vftable`; support docs place the shared error hierarchy in `util/Error.cpp`; duplicate cleanup islands and destructor-family vtable restores are all within the Error wrapper cluster; no consumer subsystem owns this code.
- Evidence against: semantically tied to the base [UID:00004J] `Error` class, not a free product helper.
- Decision: keep as canonical owner and emitter route because this exact range is compiler/unwind cleanup support, not a source-visible class method.

### 2. [UID:00004J] `Error` class

- Evidence for: helper resets to the base `Error` vtable and tail-jumps to inherited cleanup; class page already lists it as an important cleanup helper; class score clears the gate.
- Evidence against: no vtable slot or direct caller proves a normal `Error` method; base scalar deleting destructor already has its exact range at `0x004a68e0`; forcing this page under the class risks emitting a fake `ErrorBaseCleanupHelper` method.
- Decision: cite and update as support, but do not change target metadata to class owner in this pass.

### 3. [UID:00004K] `ErrorMessage` or [UID:00004X] `FileError`

- Evidence for: target sits between the raw `ErrorMessage` constructor-shaped body and `ErrorMessage` copy helper; duplicate sibling sits between `FileError` constructor and copy helper.
- Evidence against: target body writes the base `Error` vtable, not an `ErrorMessage` or `FileError` table; no direct references identify a class method; sibling pattern shows constructor-adjacent cleanup islands are generated support, not direct class ownership.
- Decision: rejected for [UID:00013Y]. Keep adjacency as context only.

### 4. `LObject` or runtime/compiler owner

- Evidence for: tail jump reaches inherited cleanup at `0x004f4a90`; no direct callers suggests compiler/unwind support.
- Evidence against: the source-visible semantics are part of project Error hierarchy teardown; the function writes `Error::vftable`; it is not external CRT/library code.
- Decision: rejected as canonical owner. Record compiler/unwind source-shape caveat, but keep reconstructable Error hierarchy routing.

## Source Placement

- Recommended source placement: `NexusTK/util/Error.cpp` under [UID:0000J5].
- Header/source impact: use this as evidence for ordinary `Error` hierarchy destructor/base cleanup behavior in `Error.h` / `Error.cpp`, not as a standalone declaration.
- Rejected placements: `ErrorMessage.cpp`, `FileError.cpp`, `LObject.cpp`, feature caller modules, and runtime/CRT support.
- Remaining placement uncertainty: exact original source spelling and whether the original compiler outlined this as a named internal helper are not recoverable from current evidence; the emitted source should not expose a helper unless a later source pass proves one is needed to reproduce the binary.

## First-Draft C++ Recommendation

- Eligible for draft C++ by route/score after implementation: technically yes (`RECONSTRUCTABLE:TRUE`, nonblank emitter, average score recommended above 85).
- Recommended formal code: keep the inline `RECONSTRUCTION_CPP CODE:[[[]]]` value empty and insert exactly this comment in the multiline formal block between `BEGIN` and `END`:

```cpp
// Emitted code for this compiler cleanup island is represented by the Error hierarchy destructor/unwind source in [UID:0000J5].
```

- Reason executable helper code should remain absent: a direct C++ body such as `void ErrorBaseCleanupHelper()` would be decompiler-shaped and likely source-wrong. The exact binary behavior is an ABI/unwind cleanup island: restore `Error` vtable, then tail-call inherited cleanup. The source reconstruction should express ordinary Error hierarchy destructors and constructor/unwind cleanup in the relevant class/file pass, not expose this helper as a product method. However, because [UID:00013Y] remains `RECONSTRUCTABLE:TRUE` with `EMITTER_UIDS:0000J5`, Supervisor Rule 28 applies: the formal block should emit a comment marker instead of staying empty.
- Exact no-product-helper-body proof:
  1. The helper has no direct start xrefs, no callers, and no VA/RVA pointer hits.
  2. The base `Error` scalar deleting destructor is a separate function at `0x004a68e0`, so naming this exact range `Error::~Error` would conflate binary ranges.
  3. Sibling `0x004a6470` now has the same two-instruction shape, no route, and file-local cleanup placement, proving this is a repeated cleanup-island pattern.
  4. [UID:0002TV] already documents that scalar deleting destructor wrappers and related cleanup outlines should inform ordinary destructors, not be pasted as source-authored helper functions.
  5. The marker comment avoids duplicate/incorrect generated helper output while satisfying Rule 28 and retaining the exact target evidence for the later `Error.h` / `Error.cpp` source pass.
- Score impact: the marker closes the empty-emitter issue without overstating source reconstruction. Recommended `88/91` remains appropriate because behavior and placement are strong, but final executable `Error.h` destructor/unwind source shape is still not standardized.

## Documentation Evidence And Generated State

- [UID:00013Y] target doc already records the core 2026-06-15 evidence but needs current MCP session `80de0a67`, pointer-route negatives, duplicate `sub_4A6470` current function status, a stronger no-product-helper-body proof, and the formal Rule 28 marker comment.
- [UID:00013X] `ErrorWrappers` already lists [UID:00013Y] as an exact child and `0x004a6470` as a duplicate cleanup island; update it to say current MCP now models `0x004a6470` as `sub_4A6470` size `0x0b`, and create an exact child page for that modeled sibling during the accepted implementation callback.
- [UID:0000J5] `Error`, [UID:00004J] `Error`, [UID:0001XI], [UID:0001UE], and [UID:0002ND] already contain the right source family. They need a small current-session synchronization for [UID:00013Y] and `0x004a6470`.
- `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/util/Error.cpp` show stale `78/88` values for [UID:00013Y] despite the source page being `85/89`. Do not edit generated files manually; the implementation validator pass should refresh generated state or report if validator state remains stale.

## Score And Metadata Recommendation

- Current source-page metadata: `COMPLETION:85`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000J5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J5`, blank `EMITTER_POSITION_OPTIONAL`, currently empty formal C++.
- Recommended metadata after implementation: `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:0000J5`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000J5`, keep `EMITTER_POSITION_OPTIONAL` blank, and insert the Rule 28 marker comment in the formal multiline `RECONSTRUCTION_CPP CODE` block.
- Reason for completion raise: current MCP session, exact byte window, pointer-route negatives, sibling `sub_4A6470` function confirmation, generated-state observation, target-specific no-product-helper-body proof, and formal marker disposition close the score-limiting blockers enough for stronger documentation.
- Reason confidence rises but stays below final: binary behavior, range, and source family are very strong, but original source name/declaration and the exact compiler source lowering remain inferred.
- Reason not higher: no recovered source symbol, no direct caller/EH route to the helper start, and final `Error.h` destructor/unwind source shape is not standardized. The sibling `0x004a6470` missing-child blocker is now repair-planned for immediate child creation rather than retained as a passive unresolved blocker.

## Recommended Target Doc Changes

Target path: `by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md`.

Recommended changes:

1. Change metadata to `COMPLETION:88`, `CONFIDENCE:91`; leave `CANONICAL_OWNER:0000J5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J5`, and `EMITTER_POSITION_OPTIONAL` unchanged; insert the accepted marker comment in the formal multiline `RECONSTRUCTION_CPP CODE` block.
2. Update `Item Summary` to include current MCP session `80de0a67`, no VA/RVA pointer route, duplicate `0x004a6470` cleanup-island support, and Rule 28 marker/source-folding policy.
3. Add a `2026-06-27 B005 Live IDA MCP Recheck` section with the exact MCP facts listed in this report.
4. Add a no-product-helper-body proof section or strengthen `Source Reconstruction Notes` so it explicitly says final source should fold this behavior into Error hierarchy destructor/unwind cleanup, not emit `ErrorBaseCleanupHelper` as a product method, while the formal block emits the accepted marker comment for tracker correctness.
5. Preserve old assumptions as historical evidence: previous `0x004a6470` local-PE-only/pending wording was correct at the time but is superseded by current MCP modeling `sub_4A6470`.
6. Add negative evidence: `xrefs_to 0x004a6400` empty; callers empty; little-endian VA/RVA pointer scans empty; only the exact helper byte pattern occurs at `0x004a6400`.
7. Add generated-state caveat: current generated `auto-generated/NexusTK/util/Error.cpp` still has an empty marker for [UID:00013Y] and stale `78/88`; generated files must be refreshed by validator after the source doc receives the formal comment marker, not edited manually.

## Recommended Support Doc Changes

- `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`: keep [UID:00013Y] as exact child; update the `0x004a6470-0x004a647b` row/evidence to say current MCP `lookup_funcs` reports `sub_4A6470` size `0x0b`, with no xrefs/pointer hits, and that the accepted repair creates `by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md` as the exact child instead of leaving it pending.
- `by-file/Error.md`: synchronize the 2026-06-27 MCP evidence for [UID:00013Y] and the sibling `sub_4A6470`; keep `util/Error.cpp`; preserve that constructor/copy/destructor source should own final C++ rather than helper methods.
- `by-class/Error.md`: update the cleanup-helper evidence so `xrefs_to 0x00619344` includes both `0x004a6400` and current MCP-modeled `0x004a6470`, plus destructor-family restores.
- `by-class/ErrorMessage.md`: refresh the target-specific line for `sub_4A6400` with current session `80de0a67`; preserve that it is cleanup context adjacent to the raw constructor, not an `ErrorMessage` method.
- `by-class/FileError.md` and `by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md`: update their preceding-cleanup-island references to current MCP-modeled `sub_4A6470` and the new exact child page.
- `by-type/by-vtable/ErrorHierarchyVtables.md`: update the `0x004a6470` note from B013-local evidence to current MCP-modeled function evidence; keep the five-slot vtable declaration caveat.
- `by-type/by-struct/ErrorObjectLayouts.md`: add or update a short note that both `0x004a6400` and `0x004a6470` are base `Error` vtable reset / inherited-cleanup islands, but layout declarations should still come from the Error hierarchy source model.
- `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md`: update the constructor/store evidence to cite current MCP `xrefs_to 0x00619344` with `sub_4A6400` and `sub_4A6470` as modeled functions.
- `by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md`: add a short cross-reference that [UID:00013Y] and sibling `0x004a6470` are non-deleting cleanup-island counterparts to the scalar deleting destructor wrappers.
- No manual `by-memory/-coverage-report.md` edit is authorized by this assignment. Do not provide or apply manual coverage row text; rely on source metadata plus validator/generated refresh unless the supervisor explicitly grants a manual coverage-report override.

## Recommended 0x004a6470 Exact Child Repair

Create `by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md` during the accepted implementation callback as associated repair work because current MCP now supplies exact function support and the existing aggregate/support docs already depend on this sibling cleanup island.

- Proposed title: `0x004a6470-0x004a647b FileError Base Cleanup Helper`.
- Proposed metadata: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000J5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J5`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`.
- Proposed item summary: `Two-instruction FileError-adjacent cleanup island audited with live IDA; restores the base Error vtable, tail-jumps to inherited cleanup, has no direct xrefs or pointer-route hits, and is represented in emitted source by the Error hierarchy destructor/unwind implementation.`
- Proposed formal multiline `RECONSTRUCTION_CPP CODE` content:

```cpp
// Emitted code for this compiler cleanup island is represented by the Error hierarchy destructor/unwind source in [UID:0000J5].
```

- Proposed owner/emitter rationale: use [UID:0000J5] because the function writes the base `Error` vtable and belongs to the same `util/Error.cpp` cleanup/unwind source family as [UID:00013Y]; do not route it to [UID:00004X] `FileError` merely because it is adjacent to FileError constructor/copy ranges.
- Required child evidence: current MCP `lookup_funcs 0x004a6470 -> sub_4A6470 size 0x0b`; `analyze_batch` body writes `Error::vftable` and tail-jumps to `sub_4F4A90`; no callers/incoming xrefs; `xrefs_to 0x004a6470` empty; bytes `c7 01 44 93 61 00 e9 15 e6 04 00`; `get_bytes 0x004a647b size 5` gives `cc cc cc cc cc`; VA/RVA pointer scans for `70 64 4A 00` and `70 64 0A 00` are empty; the exact byte pattern occurs once at `0x004a6470`.
- Required support synchronization: update `ErrorWrappers`, `Error`, `Error` class, `FileError`, `FileErrorCopyMessage`, `ErrorHierarchyVtables`, `ErrorObjectLayouts`, `ErrorHierarchyVtableData`, and `ErrorDestructorAndNameHelpers` where they mention the sibling so they cite the new exact child instead of a pending/local-only island.
- Required validators: validate the new child file, the aggregate `ErrorWrappers` page, and every touched support doc in the same scoped implementation batch with `--wait-generated`.

## IDA Rename / Type / Comment Recommendations

- No IDA DB edits are requested in this report-only pass.
- Safe documentation/analysis label for `0x004a6400`: `ErrorBaseCleanupHelper`, with comment "restores Error base vtable and tail-jumps to inherited LObject cleanup; cleanup/unwind support, not a source-visible product method."
- Safe documentation/analysis label for `0x004a6470` when the exact child is created or a later IDA analysis pass is accepted: `FileErrorBaseCleanupHelper` or `ErrorBaseCleanupHelper_FileError`, with the same source-folding comment.
- Do not rename either helper as `Error::~Error`, `ErrorMessage::~ErrorMessage`, `FileError::~FileError`, or `LObject::~LObject`; those names would conflate distinct ranges and ownership roles.

## Open Questions With Attempted Resolution

- Direct helper route: resolved as far as current evidence allows. No direct xref/caller/pointer route exists; this is not an excuse to leave the page weak because the body, vtable immediate, duplicate helper, and destructor-family context explain the cleanup-support role.
- Named helper versus folded source: resolved for current docs. Keep the documentation name, but fold executable source semantics into destructor/unwind cleanup; do not emit a named helper C++ body. Insert the formal marker comment because the target remains a designated emitter represented by [UID:0000J5].
- Canonical owner: resolved for this pass. Keep [UID:0000J5] rather than switching to [UID:00004J], because the exact range is file-local cleanup support, not a source-visible class method.
- Duplicate helper exact child: resolved as associated repair. Create a separate exact child for `0x004a6470-0x004a647b` now during the accepted callback; do not merge it into [UID:00013Y].

## Validators

Implementation validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--apply --queue-timeout 240 --wait-generated`. Each scoped file run returned exit code `0`, `ok: 1`, and `generated_refresh: completed`.

| File | Command | command_id | command_timestamp | exit | ok | generated refresh |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md --apply --queue-timeout 240 --wait-generated` | `000000003932` | `2026-06-27T06:53:28-04:00` | `0` | `1` | `completed`, refresh id `000000003932`, timestamp `2026-06-27T06:53:28-04:00` |
| `by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md --apply --queue-timeout 240 --wait-generated` | `000000003933` | `2026-06-27T06:53:37-04:00` | `0` | `1` | `completed`, refresh id `000000003933`, timestamp `2026-06-27T06:53:37-04:00` |
| `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md --apply --queue-timeout 240 --wait-generated` | `000000003934` | `2026-06-27T06:53:46-04:00` | `0` | `1` | `completed`, refresh id `000000003934`, timestamp `2026-06-27T06:53:46-04:00` |
| `by-file/Error.md` | `python .\tools\validator.py --mode file --file by-file/Error.md --apply --queue-timeout 240 --wait-generated` | `000000003935` | `2026-06-27T06:53:55-04:00` | `0` | `1` | `completed`, refresh id `000000003935`, timestamp `2026-06-27T06:53:55-04:00` |
| `by-class/Error.md` | `python .\tools\validator.py --mode file --file by-class/Error.md --apply --queue-timeout 240 --wait-generated` | `000000003936` | `2026-06-27T06:54:05-04:00` | `0` | `1` | `completed`, refresh id `000000003936`, timestamp `2026-06-27T06:54:05-04:00` |
| `by-class/ErrorMessage.md` | `python .\tools\validator.py --mode file --file by-class/ErrorMessage.md --apply --queue-timeout 240 --wait-generated` | `000000003937` | `2026-06-27T06:54:14-04:00` | `0` | `1` | `completed`, refresh id `000000003937`, timestamp `2026-06-27T06:54:14-04:00` |
| `by-class/FileError.md` | `python .\tools\validator.py --mode file --file by-class/FileError.md --apply --queue-timeout 240 --wait-generated` | `000000003938` | `2026-06-27T06:54:23-04:00` | `0` | `1` | `completed`, refresh id `000000003938`, timestamp `2026-06-27T06:54:23-04:00` |
| `by-type/by-vtable/ErrorHierarchyVtables.md` | `python .\tools\validator.py --mode file --file by-type/by-vtable/ErrorHierarchyVtables.md --apply --queue-timeout 240 --wait-generated` | `000000003939` | `2026-06-27T06:54:32-04:00` | `0` | `1` | `completed`, refresh id `000000003939`, timestamp `2026-06-27T06:54:32-04:00` |
| `by-type/by-struct/ErrorObjectLayouts.md` | `python .\tools\validator.py --mode file --file by-type/by-struct/ErrorObjectLayouts.md --apply --queue-timeout 240 --wait-generated` | `000000003940` | `2026-06-27T06:54:42-04:00` | `0` | `1` | `completed`, refresh id `000000003940`, timestamp `2026-06-27T06:54:42-04:00` |
| `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md` | `python .\tools\validator.py --mode file --file by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md --apply --queue-timeout 240 --wait-generated` | `000000003941` | `2026-06-27T06:54:51-04:00` | `0` | `1` | `completed`, refresh id `000000003941`, timestamp `2026-06-27T06:54:51-04:00` |
| `by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md --apply --queue-timeout 240 --wait-generated` | `000000003942` | `2026-06-27T06:55:00-04:00` | `0` | `1` | `completed`, refresh id `000000003942`, timestamp `2026-06-27T06:55:00-04:00` |
| `by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md --apply --queue-timeout 240 --wait-generated` | `000000003943` | `2026-06-27T06:55:09-04:00` | `0` | `1` | `completed`, refresh id `000000003943`, timestamp `2026-06-27T06:55:09-04:00` |

Generated-state check after the validator batch:

- `auto-generated/-ag-research-tracker.md` lists [UID:00013Y] at `88/91` and [UID:00048A] at `86/91`.
- `auto-generated/-ag-coverage-report-by-memory.md` lists [UID:00013Y] as `emits_code:true`, `88%`, `very-strong`, and [UID:00048A] as `emits_code:true`, `86%`, `very-strong`.
- `auto-generated/NexusTK/util/Error.cpp` was refreshed by the validator batch and includes both cleanup marker comments. The validator's UID-linker renders `[UID:0000J5]` as `[UID:0000J5][Error](by-file/Error.md)` in generated output. The authoritative by-memory formal blocks were corrected after validation to the literal accepted marker `// Emitted code for this compiler cleanup island is represented by the Error hierarchy destructor/unwind source in [UID:0000J5].`; rerunning the validator would reapply the markdown UID link inside the formal comment.

## Implementation Tracking Checklist

- [x] Update [UID:00013Y] target metadata to `COMPLETION:88`, `CONFIDENCE:91`, keeping owner/emitter/reconstructable fields unchanged and inserting the accepted formal marker comment. Proof: `by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md` now has `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000J5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J5`, blank emitter position, and the literal accepted marker in the formal multiline block.
- [x] Add the 2026-06-27 MCP session/provenance to [UID:00013Y]. Proof: target page now records endpoint `http://127.0.0.1:13337/mcp`, session `80de0a67`, IDB path, module, imagebase, Hex-Rays/strings readiness, and strings cache size.
- [x] Add exact [UID:00013Y] MCP facts. Proof: target page records `lookup_funcs`, `analyze_batch`, empty `xrefs_to 0x004a6400`, base-vtable `xrefs_to 0x00619344`, tail-jump `xrefs_to 0x004f4a90` at `0x004a6406`, exact bytes/padding, pointer-byte negative checks, exact pattern match, and `0x0b = 11`.
- [x] In [UID:00013Y], keep inline `RECONSTRUCTION_CPP CODE:[[[]]]` empty and insert the exact multiline formal marker. Proof: source page formal block currently contains only `// Emitted code for this compiler cleanup island is represented by the Error hierarchy destructor/unwind source in [UID:0000J5].`
- [x] Add target-specific no-product-helper-body proof to [UID:00013Y]. Proof: `Source Reconstruction Notes` now rejects a named helper body using no-call/no-xref/no-pointer-route/no-slot evidence, distinct destructor ranges, sibling island evidence, and destructor/unwind source placement.
- [x] Preserve/restate the source-facing naming decision. Proof: target page states `ErrorBaseCleanupHelper` is a documentation/analysis name and not a product helper API.
- [x] Create `by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md` as an exact child. Proof: validator assigned [UID:00048A]; page has `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000J5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J5`, blank emitter position, `Nested:0`, accepted item summary, and the same literal Rule 28 marker.
- [x] Add exact `0x004a6470` child evidence. Proof: [UID:00048A] records MCP `lookup_funcs`/`analyze_batch`, body bytes `c7 01 44 93 61 00 e9 15 e6 04 00`, no xrefs/callers, padding, pointer-byte negative checks, unique byte-pattern hit, and [UID:0000J5] owner/emitter rationale.
- [x] Update [UID:00013X] `ErrorWrappers`. Proof: aggregate now links [UID:00048A] in the covered-range table, replaces deferred wording, records current MCP `sub_4A6470` size `0x0b`, no xrefs/pointer hits, exact bytes, and Rule 28 source-folding policy.
- [x] Update [UID:0000J5] `Error`. Proof: file page evidence basis and evidence bullets now include B005 MCP session `80de0a67`, [UID:00013Y], [UID:00048A], exact bytes, no-route proof, and `util/Error.cpp` destructor/unwind placement.
- [x] Update [UID:00004J] `Error`. Proof: class page now lists both cleanup islands as important methods/support, adds the B005 cleanup-island section, and records `xrefs_to 0x00619344` / `xrefs_to 0x004f4a90` evidence for both.
- [x] Update [UID:00004K] `ErrorMessage`. Proof: class page now refreshes `sub_4A6400` with current B005 session `80de0a67`, negative route evidence, bytes, sibling [UID:00048A], and non-ErrorMessage source placement.
- [x] Update [UID:00004X] `FileError` and [UID:000140] `FileErrorCopyMessage`. Proof: `FileError` now lists [UID:00048A] as local support/boundary evidence and rejects FileError method ownership; `FileErrorCopyMessage` now links [UID:00048A] as the preceding cleanup island and preserves copy-helper ownership/body.
- [x] Update [UID:0001XI] `ErrorHierarchyVtables`, [UID:0001UE] `ErrorObjectLayouts`, and [UID:0002ND] `ErrorHierarchyVtableData`. Proof: all three now cite current modeled-function support for [UID:00013Y] and [UID:00048A], base `Error` vtable writes, no-route evidence, and destructor/unwind source placement.
- [x] Update [UID:0002TV] `ErrorDestructorAndNameHelpers`. Proof: page now cross-links [UID:00013Y] and [UID:00048A] as non-deleting cleanup-island counterparts while preserving the scalar deleting destructor no-code policy.
- [x] Do not edit generated reports, project-level generated files, manual `-coverage-report.md` files, validator/tool state, or IDA DB. Proof: no manual edits were made to generated files, coverage reports, validator state, or IDA DB; generated files changed only through validator refresh.
- [x] Run scoped validator command for every edited by-* doc from `source-3/project-documentation`. Proof: validator table above records commands `000000003932` through `000000003943`, all exit `0`, `ok:1`, with completed generated refreshes.
- [x] Confirm generated state after validation. Proof: generated tracker lists [UID:00013Y] at `88/91` and [UID:00048A] at `86/91`; generated by-memory coverage lists both as `emits_code:true`; generated `Error.cpp` includes both cleanup marker comments, with the validator UID-link rendering caveat noted above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/00013Y-ErrorBaseCleanupHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00013Y-ErrorBaseCleanupHelper-source-quality.md","timestamp":"2026-06-27T08:20:42","uid":"00013Y"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
