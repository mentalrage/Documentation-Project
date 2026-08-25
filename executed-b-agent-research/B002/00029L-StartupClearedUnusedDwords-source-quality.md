** TARGET-REPORT-UID:00029L **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00029L Startup-Cleared Unused Dwords Source-Quality Report

Assignment: `B002-goal2-startup-cleared-unused-dwords-source-quality-00029L-20260619`

Target: [UID:00029L] `by-memory/0x0069b350-0x0069b358.StartupClearedUnusedDwords.md`

Required output: `tools/leaser/Agents/Agent-B002/research/00029L-StartupClearedUnusedDwords-source-quality.md`

Report-only result: this pass does not edit any `by-*` documentation file and does not edit `by-memory/-coverage-report.md`.

## Final Recommendation

Keep [UID:00029L] non-reconstructable, no-owner, non-emitting, and C++ blank. The unused/static-initializer-residue classification remains correct, but the target's current byte-state wording should be corrected.

The best current source-quality interpretation is:

- `0x0069b350-0x0069b358` is an exact two-dword `.data` virtual-tail/BSS-style island.
- The IDA listing declares both dwords as uninitialized data (`dd ?`), not source-initialized `0xffffffff` data.
- The raw PE section map confirms the range is not raw-backed; the Windows loader initializes it to zero.
- `sub_419F00` redundantly stores zero to both dwords during the compiler startup initializer pass.
- Raw VA/RVA pattern checks and the IDA listing find no hidden read, pointer, structure, branch, or ordinary code route for either dword.
- Neighboring live globals have their own exact pages and should not absorb this residue.

Recommended metadata:

```text
*** UID:00029L
*** COMPLETION:88
*** CONFIDENCE:91
*** CANONICAL_OWNER:NONE
*** RECONSTRUCTABLE:FALSE
*** EMITTER_UIDS:
```

The recommended score increase is from `85/85` to `88/91`. Completion rises because this pass resolves the initial-byte discrepancy, function semantics, hidden-ref question, neighbor-membership question, ignored-ledger gap, and exact no-code proof. Confidence rises because the target is now backed by the IDA listing export plus a raw PE section/ref scan. It should not go to final-audit confidence because fresh IDA MCP was unavailable and a broader `.data` virtual-tail cleanup remains pending for sibling pages with stale byte-state wording.

## Exact Evidence Checked

Governing instructions checked:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`, especially Rule 26
- `tools/leaser/Agents/Agent-B002/goal.md`
- `tools/leaser/Agents/Agent-B002/notes.md`
- `by-structure.md`

Target checked:

- [UID:00029L] `by-memory/0x0069b350-0x0069b358.StartupClearedUnusedDwords.md`

Direct support docs checked:

- [UID:0000W9] `by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md`
- [UID:0000HN] `by-file/AutoInit.md`
- [UID:00000Q] `by-class/AutoInit.md`
- [UID:0001PF] `by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md`
- [UID:0002VS] `by-memory/0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage.md`
- [UID:0002VR] `by-memory/0x0069b35c-0x0069b360.g_pTotemFrameStorage.md`
- [UID:0002VQ] `by-memory/0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage.md`
- [UID:00029M] `by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md`
- [UID:00029N] `by-memory/0x0069b370-0x0069b374.UnreferencedInitializedDword_69B370.md`
- [UID:0001PG] `by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md`
- [UID:00029O] `by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md`
- [UID:0001PH] `by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md`
- [UID:00029P] `by-memory/0x0069b381-0x0069b39c.UnreferencedInitializedBytes_69B381.md`
- [UID:0000T6] `by-global/MainUiLayerSlots.md`
- `by-memory/-ignored.md`
- `by-memory/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`

Prior B-agent reports checked:

- `tools/leaser/Agents/Agent-B001/research/executed/older/00029Q-StaticStringVectorStorage_69B39C-B001.md`

Binary/listing evidence checked:

- IDA listing export: `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`
- Raw PE image: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - MD5 `4247e04e20b65d6414c7238aa8ff5515`
  - SHA1 `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`
  - Image base `0x00400000`

Fresh local IDA MCP was attempted and unavailable:

```text
MCP_ERROR: Unable to connect to the remote server
```

This report therefore relies on the IDA listing export, raw PE scan, and existing live-IDA-backed documentation. The target conclusion does not require new live IDA because the listing and raw PE independently verify the function body, startup table route, section mapping, and absence of raw hidden references.

## Current Target State

Current target metadata:

```text
*** UID:00029L
*** COMPLETION:85
*** CONFIDENCE:85
*** CANONICAL_OWNER:NONE
*** RECONSTRUCTABLE:FALSE
*** EMITTER_UIDS:
```

Current target classification:

- Disposition: ignored as standalone source.
- Entity kind: initialized global-data dwords.
- Claimed initial bytes: `ff ff ff ff ff ff ff ff`.
- Claimed runtime evidence: both dwords are cleared to zero by `sub_419F00`; no other IDA data xrefs.
- Current confidence note: strong for address/range/xref set, medium for final source-owner explanation.

The no-owner/no-emitter/non-reconstructable result is correct. The stale parts are the "initialized `0xffffffff`" byte-state claim and the weaker final source-owner explanation. The raw PE and listing support a stronger explanation: uninitialized loader-zero-filled virtual `.data` tail with a redundant compiler startup clear and no reads.

## Raw PE And Listing Facts

Raw PE section map:

```text
File: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
MD5: 4247e04e20b65d6414c7238aa8ff5515
SHA1: c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a
ImageBase: 0x00400000
.text:  VA 0x00401000-0x0060c4ac, raw-backed VA end 0x0060c600, raw 0x400-0x20ba00
.rdata: VA 0x0060d000-0x0066c0be, raw-backed VA end 0x0066c200, raw 0x20ba00-0x26ac00
.data:  VA 0x0066d000-0x0069ce24, raw-backed VA end 0x0067a800, raw 0x26ac00-0x278400
.rsrc:  VA 0x0069d000-0x006b2c38, raw-backed VA end 0x006b2e00, raw 0x278400-0x28e200
```

Target byte-state result:

```text
Bytes 0x0069b350-0x0069b358: not raw-backed; loader zero-fill
```

Neighboring virtual-tail result:

```text
Bytes 0x0069b33c-0x0069b360: not raw-backed; loader zero-fill
Bytes 0x0069b358-0x0069b380: not raw-backed; loader zero-fill
```

This is stronger than the target's current raw-data claim. The page should not continue saying the target starts as `0xffffffff`. For the executable image checked in this pass, `0x0069b350-0x0069b358` is in the virtual tail of `.data`, beyond the raw-backed `.data` VA end at `0x0067a800`; the loader supplies zero bytes.

IDA listing data declarations around the target:

```asm
.data:0069B33C dword_69B33C dd ?
.data:0069B340 dword_69B340 dd ?
.data:0069B344 dword_69B344 dd ?
.data:0069B348 dword_69B348 dd ?
.data:0069B34C dword_69B34C dd ?
.data:0069B350 dword_69B350 dd ?
.data:0069B354 dword_69B354 dd ?
.data:0069B358 dword_69B358 dd ?
.data:0069B35C dword_69B35C dd ?
.data:0069B360 dword_69B360 dd ?
.data:0069B364 dword_69B364 dd ?
```

The listing uses `dd ?` for the target and adjacent virtual-tail dwords, matching the PE zero-fill conclusion and contradicting a source-initialized `0xffffffff` byte claim.

## `sub_419F00` Startup Write Semantics

IDA listing body:

```asm
.text:00419F00 sub_419F00 proc near
.text:00419F00 mov     dword_69B350, 0
.text:00419F0A mov     dword_69B354, 0
.text:00419F14 retn
.text:00419F14 sub_419F00 endp
```

Raw function bytes:

```text
Bytes 0x00419f00-0x00419f15 raw 0x19300:
c7 05 50 b3 69 00 00 00 00 00 c7 05 54 b3 69 00 00 00 00 00 c3
```

Decoded semantics:

- `0x00419f00`: store `0` to absolute dword `0x0069b350`.
- `0x00419f0a`: store `0` to absolute dword `0x0069b354`.
- `0x00419f14`: return.
- No reads.
- No conditional logic.
- No stack frame.
- No callee calls.
- No atexit registration.
- No construction of a C++ object.
- No initialization of the following singleton or layer-slot globals.

Startup table route:

```asm
.rdata:0060D6A0 dd offset sub_419EC0
.rdata:0060D6A4 dd offset sub_419EE0
.rdata:0060D6A8 dd offset sub_419F00
.rdata:0060D6AC dd offset sub_419F20
.rdata:0060D6B0 dd offset sub_419F40
.rdata:0060D6B4 dd offset sub_419F70
```

Raw startup table bytes:

```text
Bytes 0x0060d6a0-0x0060d6d0 raw 0x20c0a0:
c0 9e 41 00 e0 9e 41 00 00 9f 41 00 20 9f 41 00
40 9f 41 00 70 9f 41 00 90 9f 41 00 50 9f 41 00
b0 9f 41 00 d0 9f 41 00 f0 9f 41 00 10 a0 41 00
```

Route conclusion:

- `sub_419F00` is reached through startup initializer table entry `0x0060d6a8`.
- Corrected raw PE branch scan found zero direct E8/E9 branches to `0x00419f00`.
- IDA listing search found no `call sub_419F00` or `jmp sub_419F00`.
- The only listing reference to `sub_419F00` outside its body is the `.rdata` startup table entry.

## Hidden Read / Pointer / Structure Membership Checks

Raw little-endian absolute VA hits:

```text
Raw LE hits for 0x0069b350: 1
  raw 0x19302
Raw LE hits for 0x0069b354: 1
  raw 0x1930c
Raw LE hits for 0x0069b358: 14
Raw LE hits for 0x0069b33c: 4
Raw LE hits for 0x00419f00: 1
  raw 0x20c0a8
```

Meaning:

- The only raw VA immediate hit for `0x0069b350` is the immediate operand inside the first `mov` in `sub_419F00`.
- The only raw VA immediate hit for `0x0069b354` is the immediate operand inside the second `mov` in `sub_419F00`.
- The next live dword `0x0069b358` has 14 hits, matching the documented `g_pGeneralPurposePanel2` singleton storage page and proving the scan can see real references in the same neighborhood.
- The preceding live `FramePartPaneSlots` address `0x0069b33c` has four hits, also serving as a positive nearby control.
- The only raw absolute pointer to `0x00419f00` is the startup initializer table entry.

Raw little-endian RVA and alternate-pattern checks:

```text
Raw LE hits for 0x0029b350: 0
Raw LE hits for 0x0029b354: 0
Raw LE hits for 0x0029b358: 0
Raw LE hits for 0x0019b350: 0
Raw LE hits for 0x0019b354: 0
```

Corrected direct-branch scan:

```text
Direct E8/E9 branch hits to 0x00419f00 in .text: 0
```

No hidden membership was found:

- No hidden read of either dword.
- No hidden pointer table entry to either dword.
- No RVA-form reference.
- No ordinary direct branch/call to the startup wrapper.
- No larger data structure evidence spanning `0x0069b350-0x0069b358`.
- No proof that these two dwords are part of the preceding `FramePartPaneSlots` array.
- No proof that these two dwords are part of the following singleton-storage or MainUiLayerSlots family.

## Neighbor Relationship

Neighboring storage is cleanly split by xrefs and documentation:

| Range | UID / page | Current role | Relationship to [UID:00029L] |
| --- | --- | --- | --- |
| `0x0069b33c-0x0069b350` | [UID:0001PF] `FramePartPaneSlots` | Five `FramePartPane*` slots owned by [UID:0000JL] `FrameChrome` | Ends exactly at target start. Has lifecycle refs; target does not share them. |
| `0x0069b350-0x0069b358` | [UID:00029L] target | Two unused startup-cleared dwords | Exact residue island. |
| `0x0069b358-0x0069b35c` | [UID:0002VS] `g_pGeneralPurposePanel2Storage` | GeneralPurposePanel2 singleton pointer | Starts exactly after target. Has 14 refs; target has none except startup clear. |
| `0x0069b35c-0x0069b360` | [UID:0002VR] `g_pTotemFrameStorage` | TotemFrame singleton pointer | Separate singleton storage. |
| `0x0069b360-0x0069b364` | [UID:0002VQ] `g_pInterfaceEfxMgrStorage` | InterfaceEfxMgr singleton pointer | Separate singleton storage. |
| `0x0069b364-0x0069b370` | [UID:00029M] `MainUiLayerSlotsHead` | First three MainUiLayerSlots entries | Separate UI layer slot family. |
| `0x0069b370-0x0069b374` | [UID:00029N] `UnreferencedInitializedDword_69B370` | Unreferenced gap | Similar no-ref residue, but not contiguous with target because live singleton/layer slots intervene. |
| `0x0069b374-0x0069b378` | [UID:0001PG] `g_layoutContext_69B374` | Shared layout context slot | Live layer/layout slot; [UID:0001PG] already documents the zero-filled `.data` virtual-tail fact. |
| `0x0069b378-0x0069b380` | [UID:00029O] `MainUiLayerSlotsTail` | Tail layer/context slots | Separate UI layer slot family. |
| `0x0069b380-0x0069b381` | [UID:0001PH] `g_activeDialogCount` | Dialog activity counter byte | Separate live global. |

Relationship conclusion:

- [UID:00029L] is not a `FramePartPaneSlots` tail because the frame slot array has exactly five dwords and ends at `0x0069b350`.
- [UID:00029L] is not `g_pGeneralPurposePanel2` or a hidden predecessor member because the singleton pointer has its own exact start at `0x0069b358` and many independent refs.
- [UID:00029L] is not `MainUiLayerSlots` because the first documented UI layer slot starts at `0x0069b364`, and the target has no startup allocation, shutdown release, registration, or consumer refs matching that family.
- [UID:00029L] is not a source structure head for the following dwords because the following dwords have independent per-slot lifecycles and xref counts, while the target only has startup zero stores.

## Heuristic / Inference Reanalysis And Validation

Generated names: `dword_69B350` and `dword_69B354`

- Evidence checked: IDA listing declarations, raw PE section map, raw VA/RVA pattern scans, direct support docs.
- Conclusion: keep as address-based placeholder names in the target documentation. No source-facing variable names are recoverable because neither dword has reads, consumers, or source-owner context.
- Best descriptive label: `startup-cleared unused dword 69B350` and `startup-cleared unused dword 69B354`.
- Rejected source names: `g_p...` singleton names, `MainUiLayerSlots` member names, and `FramePartPane` slot names. The evidence does not support them.

Generated name: `sub_419F00`

- Evidence checked: IDA listing body, raw bytes, startup table, direct branch scan, [UID:0000W9].
- Conclusion: keep as compiler/static-initializer wrapper label in docs; do not promote to a NexusTK source function.
- Best descriptive label: `StartupClearUnusedDwords_69B350_69B354` if prose needs a name, but not as an emitted source symbol.
- Rejected source function model: a hand-authored game startup helper. The body is just two zero stores, is table-driven by the startup initializer array, and has no ordinary caller.

Initial value / raw data claim

- Evidence checked: target current text, raw PE section map, IDA listing `dd ?`, [UID:0001PG] neighboring zero-fill note, B001 `00029Q` zero-fill repair.
- Conclusion: current `0xffffffff` wording is stale for this target. Replace with loader-zero-filled/uninitialized `.data` virtual-tail wording.
- Historical assumption to preserve: older IDA MCP notes reported `0xffffffff`; the implementation pass should record that as superseded by raw PE/listing evidence rather than silently deleting the history.

Static-initializer residue classification

- Evidence checked: `sub_419F00`, startup table entry, no direct branches, no reads.
- Conclusion: remains correct. The wrapper is startup initializer glue; the target data has no source-bearing runtime semantics.
- Refinement: call it `startup-cleared unused zero-filled dwords`, not `initialized 0xffffffff dwords`.

Hidden reads/pointers/structure membership

- Evidence checked: raw absolute VA hits, raw RVA hits, direct branch scan, IDA listing refs, positive controls on `0x0069b358` and `0x0069b33c`.
- Conclusion: none found. The target is not silently read through a pointer table or larger structure in available binary evidence.
- Remaining uncertainty: a non-standard arithmetic construction of the address without an immediate reference is theoretically possible, but no adjacent behavior or structure evidence supports that. It should not affect the no-code decision.

Neighbor ownership

- Evidence checked: [UID:0001PF], [UID:0002VS], [UID:0002VR], [UID:0002VQ], [UID:00029M], [UID:0001PG], [UID:00029O], [UID:0001PH], [UID:0000T6].
- Conclusion: all plausible neighboring owners are rejected. The target remains a standalone ignored residue page.

Source-owner/no-owner decision

- Evidence checked: by-structure owner/emitter rules, wrapper docs, neighboring source owners.
- Conclusion: `CANONICAL_OWNER:NONE` remains correct. No direct semantic source owner exists for unused, unread, startup-cleared residue.
- Runtime owner, if one must be named descriptively: compiler/linker startup-initializer machinery represented by [UID:0000W9], not a NexusTK source module.

Emitter/C++ readiness

- Evidence checked: reconstructability state, emitter rules, no-owner result, target behavior.
- Conclusion: no NexusTK C++ should be emitted. `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank C++ are required.
- Exact no-code proof: the data has no source-owned reads or consumers, and the only code touching it is compiler startup wrapper glue. Emitting source declarations or assignments for these dwords would introduce a fake NexusTK source artifact.

Split/range decision

- Evidence checked: half-open ranges around `0x0069b350`, IDA listing declarations, raw PE refs.
- Conclusion: no split is needed. Keep the two dwords together because they share the same only writer and same no-use classification.
- Do not merge with [UID:0001PF] or [UID:0002VS]; both neighbors have distinct source owners and xref sets.

Ignored-ledger status

- Evidence checked: `by-memory/-ignored.md` search for `00029L`, `0069b350`, `69B350`, and `69B354`.
- Conclusion: the exact target is absent from the ignored ledger even though coverage marks it ignored. Add an ignored-ledger entry during implementation or supervisor cleanup.

Open question closure

- "Are these unused/static-initializer residue?" Yes. The corrected evidence strengthens this.
- "What exactly does `sub_419F00` do?" It stores zero to `0x0069b350` and `0x0069b354`, then returns.
- "Does either dword have hidden reads/pointers?" No evidence found; raw VA/RVA and branch scans found none, and positive controls prove the scans detect neighboring live refs.
- "Are they part of neighboring UI singleton/layer globals?" No. Neighbor pages start/end at exact boundaries and have distinct xref families.
- "Is there a source owner?" No. If forced, the only runtime context is compiler/static-initializer glue [UID:0000W9], but that is not a source owner for the data.
- "Should C++ be emitted?" No. Exact no-code proof applies.

## Ranked Ownership / Classification Analysis

### 1. Ignored no-owner startup-cleared residue

Evidence for:

- Target data is not raw-backed and is declared `dd ?`.
- Only two zero stores touch the target.
- No reads or consumers exist in raw VA/RVA scans or listing evidence.
- Startup wrapper is reached only by the startup initializer table.
- Neighboring live globals are exactly split and independently referenced.

Evidence against:

- The presence of a startup table wrapper means these bytes were visible to the compiler/linker as something at build time, but no current source-use context remains.

Decision:

- Accept. This is the only classification supported by all evidence.

### 2. Attach to [UID:0000W9] `StaticInitializerWrappersAfterOle`

Evidence for:

- `sub_419F00` is documented there and is the only writer.

Evidence against:

- [UID:0000W9] is compiler/static-initializer wrapper code, not the source owner of data storage.
- by-structure says compiler/linker generated startup glue should be documented for exclusion, not hand-ported as source.
- The target itself is data residue, not wrapper code.

Decision:

- Reject as canonical owner. Cross-reference [UID:0000W9] only.

### 3. Attach to [UID:0001PF] `FramePartPaneSlots` / [UID:0000JL] `FrameChrome`

Evidence for:

- Physical adjacency; the frame slot array ends immediately before the target.

Evidence against:

- `FramePartPaneSlots` has exactly five dwords, ending at `0x0069b350`.
- Its xref family is builder writes, cleanup reads/clears, and notification clears.
- The target dwords have none of those refs.

Decision:

- Reject.

### 4. Attach to [UID:0002VS] `g_pGeneralPurposePanel2Storage` / following singleton globals

Evidence for:

- Physical adjacency; `g_pGeneralPurposePanel2Storage` starts immediately after the target.

Evidence against:

- `0x0069b358` has 14 direct refs and a known singleton lifecycle.
- `0x0069b35c` and `0x0069b360` also have independent singleton lifecycle refs.
- The target dwords have no singleton lifecycle refs or reads.

Decision:

- Reject.

### 5. Attach to [UID:0000T6] `MainUiLayerSlots`

Evidence for:

- The target is near the Main UI layer slots.

Evidence against:

- MainUiLayerSlots starts at `0x0069b364` in the head page and later resumes at `0x0069b374`/`0x0069b378`.
- The main UI startup/shutdown methods allocate, register, release, and clear the real layer slots; they do not use the target dwords.
- The target only receives startup zero stores from `sub_419F00`.

Decision:

- Reject.

### 6. Create a new by-global owner

Evidence for:

- There are two addressable dwords.

Evidence against:

- No reads, no consumers, no type, no lifecycle beyond redundant zero stores, no plausible declaration role.
- A by-global would create a fake source artifact.

Decision:

- Reject. Keep `CANONICAL_OWNER:NONE`.

## Exact No-Code / Unused-Residue Proof

No NexusTK reconstruction C++ should be emitted for [UID:00029L].

Proof:

- `RECONSTRUCTABLE:FALSE` is correct because rebuilding the game should not introduce source declarations or startup code for unused residue that has no runtime consumers.
- Both dwords are uninitialized/zero-filled in the executable image, not source-initialized data that must be hand-declared for contents.
- `sub_419F00` is compiler startup table glue and is already covered by non-reconstructable [UID:0000W9].
- The only writes are zero stores from `sub_419F00`; no code reads either dword.
- Raw VA hit counts for `0x0069b350` and `0x0069b354` are exactly one each, and both hits are the store immediates in `sub_419F00`.
- RVA pattern scans found zero hits.
- Direct E8/E9 branch scan found zero ordinary code branches to the wrapper.
- Positive controls in the same neighborhood found real refs for `0x0069b358` and `0x0069b33c`, so the scan was not blind to ordinary absolute refs.
- Neighboring reconstructable globals already have exact pages and owners.

If an implementation pass wants to show a pseudo-code explanation, keep it in prose only:

```cpp
// Non-emitting compiler startup residue only; do not add this to NexusTK source.
// sub_419F00:
//   dword_69B350 = 0;
//   dword_69B354 = 0;
```

Do not place that pseudo-code inside the target `RECONSTRUCTION_CPP CODE` block.

## Target Implementation Checklist

When this report is accepted for implementation, update only the target/support docs authorized by the supervisor. Recommended target changes:

- Keep `*** UID:00029L`.
- Change `COMPLETION` from `85` to `88`.
- Change `CONFIDENCE` from `85` to `91`.
- Keep `CANONICAL_OWNER:NONE`.
- Keep `RECONSTRUCTABLE:FALSE`.
- Keep `EMITTER_UIDS:` blank.
- Keep `RECONSTRUCTION_CPP CODE` blank.
- Keep the title `Startup-Cleared Unused Dwords` or retitle to `Startup-Cleared Zero-Fill Unused Dwords` if the supervisor wants the corrected byte state visible in the title.
- Replace `Entity kind: initialized global-data dwords` with wording like `loader-zero-filled .data virtual-tail dwords with only startup zero stores`.
- Replace `0xffffffff` initial-value/raw-data claims with:
  - IDA listing declares both dwords as `dd ?`.
  - Raw PE section map places the range beyond `.data` raw-backed VA end `0x0067a800`.
  - Loader initial state is zero-filled for this checked executable.
  - Older `0xffffffff` IDA MCP/raw-byte notes are historical and superseded for this target.
- Expand the `sub_419F00` evidence:
  - bytes `c7 05 50 b3 69 00 00 00 00 00 c7 05 54 b3 69 00 00 00 00 00 c3`
  - first store at `0x00419f00`
  - second store at `0x00419f0a`
  - return at `0x00419f14`
  - no reads/calls/branches inside the wrapper
  - startup table route from `0x0060d6a8`
  - zero direct E8/E9 code branches to `0x00419f00`
- Add hidden-reference proof:
  - raw VA hits for `0x0069b350`: one store immediate
  - raw VA hits for `0x0069b354`: one store immediate
  - raw RVA hits for `0x0029b350`/`0x0029b354`: zero
  - positive controls: `0x0069b358` has 14 raw VA hits and `0x0069b33c` has four raw VA hits
- Add neighbor-membership rejection:
  - not FramePartPaneSlots
  - not GeneralPurposePanel2/TotemFrame/InterfaceEfxMgr singleton storage
  - not MainUiLayerSlots
  - not active-dialog count or following static-string area
- Add a historical/stale-assumption note preserving that earlier docs reported `0xffffffff`, with this report's raw PE/listing evidence explaining why that should be superseded.
- Add the no-code proof from this report.
- Add/keep cross references to [UID:0000W9], [UID:0001PF], [UID:0002VS], [UID:0002VR], [UID:0002VQ], [UID:00029M], [UID:0001PG], [UID:00029O], and [UID:0000T6] as neighbor/source-context evidence.

## Support Implementation Checklist

[UID:0000W9] `by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md`

- Keep `RECONSTRUCTABLE:FALSE`, owner none, emitters blank.
- Add a sharper note for `0x00419f00-0x00419f15`:
  - It clears loader-zero-filled, unused target dwords [UID:00029L].
  - It is startup initializer table glue reached from `0x0060d6a8`.
  - It should not be treated as a source function or as proof that the target dwords need source declarations.
- Existing range map is correct; no split needed.

`by-memory/-ignored.md`

- Add the exact ignored-ledger entry below because by-structure expects ignored coverage rows to be represented in the folder ledger:

```text
- `0x0069b350-0x0069b358` - startup-cleared unused zero-fill dwords [UID:00029L][0x0069b350-0x0069b358.StartupClearedUnusedDwords](by-memory/0x0069b350-0x0069b358.StartupClearedUnusedDwords.md).
  - Why ignored: two uninitialized/loader-zero-filled `.data` virtual-tail dwords with no source-owner or rebuild semantics. The only writes are `sub_419F00` zero stores at `0x00419f00` and `0x00419f0a`; no reads, hidden pointers, RVA refs, or ordinary code callers were found.
  - Evidence: 2026-06-19 B002 raw PE/listing check on `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` / SHA1 `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a` shows `.data` raw-backed VA end `0x0067a800`, target `0x0069b350-0x0069b358` not raw-backed and therefore loader-zero-filled, IDA listing declarations `dword_69B350 dd ?` and `dword_69B354 dd ?`, raw VA hits only at the two store immediates, zero RVA hits, and zero direct E8/E9 branches to `0x00419f00`.
  - Replacement owner/dependency: none. Neighboring live globals remain separately documented by [UID:0001PF] `FramePartPaneSlots`, [UID:0002VS] `g_pGeneralPurposePanel2Storage`, [UID:0002VR] `g_pTotemFrameStorage`, [UID:0002VQ] `g_pInterfaceEfxMgrStorage`, and [UID:0000T6] `MainUiLayerSlots`.
```

[UID:0001PG] `by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md`

- No required target-blocking change. This page already records the important zero-filled `.data` virtual-tail section-map fact for `0x0069b360-0x0069b388`.
- It can be cross-linked from [UID:00029L] as neighbor precedent for correcting stale `0xffffffff` wording.

[UID:00029N] `by-memory/0x0069b370-0x0069b374.UnreferencedInitializedDword_69B370.md` and [UID:00029P] `by-memory/0x0069b381-0x0069b39c.UnreferencedInitializedBytes_69B381.md`

- These sibling unused-residue pages still contain `0xffffffff` / `0xff` initial-byte claims that are likely stale under the same PE virtual-tail evidence.
- Do not force those edits under this target unless the supervisor accepts a broader virtual-tail byte-state audit.
- If edited later, preserve their historical IDA MCP claims as superseded assumptions and apply the same raw PE section-map reasoning used here.

[UID:0001PF], [UID:0002VS], [UID:0002VR], [UID:0002VQ], [UID:00029M], [UID:00029O], and [UID:0001PH]

- No owner/emitter change from this target.
- If these pages are later refreshed for raw byte state, do not disturb their source ownership conclusions; their xref/lifecycle evidence, not the stale byte claim, is what proves their reconstructable/live-global status.
- [UID:00029L] should simply reference them as neighboring exact ranges rejected as owners.

`by-memory/-coverage-report.md`

- Supervisor-owned only. Use the exact replacement row in the next section; B002 must not edit it directly during report-only work.

## Exact Supervisor-Owned Coverage Row

Current exact coverage row:

```text
    - [UID:00029L][0x0069b350-0x0069b358.StartupClearedUnusedDwords](by-memory/0x0069b350-0x0069b358.StartupClearedUnusedDwords.md) 0x0069b350-0x0069b358 | initialized global data | StartupClearedUnusedDwords : ignored : 85% : strong : Two startup-cleared dwords initialized to `0xffffffff`; IDA data xrefs only from static initializer `sub_419F00`.
```

Replace it with:

```text
    - [UID:00029L][0x0069b350-0x0069b358.StartupClearedUnusedDwords](by-memory/0x0069b350-0x0069b358.StartupClearedUnusedDwords.md) 0x0069b350-0x0069b358 | loader-zero-filled unused data | StartupClearedUnusedDwords : ignored : 88% : very-strong : Two uninitialized/loader-zero-filled `.data` virtual-tail dwords (`dword_69B350`, `dword_69B354`) whose only raw VA/data references are the `sub_419F00` zero stores at 0x00419f00 and 0x00419f0a. The IDA listing declares both as `dd ?`, raw PE section mapping places `0x0069b350-0x0069b358` beyond the `.data` raw-backed VA end `0x0067a800`, raw RVA pattern checks found zero hidden refs, and a corrected `.text` scan found zero direct E8/E9 branches to `0x00419f00`; the wrapper is reached only from startup initializer table entry `0x0060d6a8`. Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, and blank C++; neighboring FramePartPane slots, GeneralPurposePanel2/TotemFrame/InterfaceEfxMgr singleton slots, MainUiLayerSlots, layout-context, and dialog-count globals have separate exact pages and must not absorb this unused residue.
```

Placement remains the same, after [UID:0001PF] `0x0069b33c-0x0069b350` and before [UID:0002VS] `0x0069b358-0x0069b35c`.

## Validator Baseline

Scoped validator baseline command:

> Executable block R001 was removed from this report and preserved verbatim in [00029L-StartupClearedUnusedDwords-source-quality-removed.md](00029L-StartupClearedUnusedDwords-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
mode: file
apply: False
scanned markdown files: 1
ok: 1
ok 00029L by-memory/0x0069b350-0x0069b358.StartupClearedUnusedDwords.md UID header exists
stats_incremental_skip 00029L project-level/-auto-completion-stats.md dry run; pass --apply to update generated stats rows
dry run only; pass --apply to write changes
```

The validator run was dry-run only. It did not edit by-memory files, support docs, coverage, generated stats, or generated source. It printed unrelated global autogen status lines; no target-specific validator failure was present.

Recommended implementation-time validator scope:

- Target [UID:00029L].
- [UID:0000W9] only if startup-wrapper prose is edited.
- `by-memory/-ignored.md` if the ignored-ledger entry is added.
- `by-memory/-coverage-report.md` only under supervisor-owned coverage workflow.
- Neighbor pages only if the supervisor authorizes a broader virtual-tail byte-state cleanup.

## Final Status

This report confirms the no-owner/no-emitter/no-code disposition and improves the source-quality rationale. The only substantive target correction is byte-state wording: use loader-zero-filled/uninitialized `.data` virtual-tail evidence instead of `0xffffffff` initialized-data wording.

No `by-*` documentation file was edited.

`by-memory/-coverage-report.md` was not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00029L-StartupClearedUnusedDwords-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00029L"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00029L-StartupClearedUnusedDwords-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00029L-StartupClearedUnusedDwords-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00029L"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
