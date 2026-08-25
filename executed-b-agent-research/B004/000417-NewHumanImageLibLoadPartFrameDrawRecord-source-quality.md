** TARGET-REPORT-UID:000417 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 000417 NewHumanImageLibLoadPartFrameDrawRecord Source-Quality Research

## Final Recommendation

Promote [UID:000417] `by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md` from a below-gate support page to a first-draft emitting `NewHumanImageLib` method:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:000092`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000092`
- `EMITTER_POSITION_OPTIONAL:` remains blank

Recommended source-facing signature and body:

```cpp
void NewHumanImageLib::LoadPartFrameDrawRecord(int partIndex,
                                               unsigned short descriptorIndex,
                                               int motionIndex,
                                               int frameIndex,
                                               NewHumanDrawRecord *outRecord)
{
    NewHumanPartEntry *part = &m_partEntries[partIndex];
    NewHumanPartFrameDescriptor *descriptor =
        &part->frameDescriptors[descriptorIndex];
    NewHumanSequenceFrameTable *sequenceFrames =
        descriptor->sequenceFrames[motionIndex];
    if (sequenceFrames == NULL)
        return;

    LoadFrameDrawRecord(part->rawRecords,
                        sequenceFrames->frames[frameIndex].recordIndex +
                            descriptor->drawIndexBase,
                        outRecord);
}
```

This resolves the old B011 blocker. The target no longer needs to remain `84/86`, no-owner, and blank-C++ solely because the helper signature and nested support names were unsettled. Accepted support docs now provide the needed `NewHumanPartEntry`, `NewHumanPartFrameDescriptor`, `NewHumanSequenceFrameTable`, `NewHumanDrawRecord`, and `LoadFrameDrawRecord` vocabulary, while current MCP confirms the exact small bridge body.

## Scope And Process

- Assignment: `B004-report-000417-NewHumanImageLibLoadPartFrameDrawRecord-20260630`.
- Target: [UID:000417] `by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md`.
- Queue source: by-memory not-covered reconstructable queue.
- Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\000417-NewHumanImageLibLoadPartFrameDrawRecord-source-quality.md`.
- This was report-only research. I did not lease files and did not edit by-* docs, generated files, coverage reports, validator state, IDA DB, executed archives, supervisor ledgers, or lock files.
- No subagents were spawned.

## Current MCP Evidence

MCP was available and responsive. I used the current session only:

- `initialize`: protocol `2025-06-18`, server `ida-pro-mcp`.
- `tools/list`: 65 tools.
- `idb_list`: one active adopted worker session, `session_id:"supervisor_resume_20260629"`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, backend `worker`, pid/worker pid `17592`.
- `server_health`: `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready with size `2067`.

Target lookup and profile:

- `lookup_funcs 0x004e0d70`: `sub_4E0D70`, start `0x4e0d70`, size `0x5f`.
- `analyze_function 0x004e0d70`: prototype `int __thiscall(_DWORD *this, int, unsigned __int16, int, int, int)`, size `95`, callers `sub_501360` and `sub_501840`, callee `sub_4D1600`, no strings, 3 basic blocks, cyclomatic complexity 2.
- `basic_blocks 0x004e0d70`: blocks `0x4e0d70-0x4e0da0`, `0x4e0da0-0x4e0dc8`, and return block `0x4e0dc8-0x4e0dcf`.
- `lookup_funcs 0x004e0dcf`: not a function.
- `lookup_funcs 0x004e0dd0`: successor `sub_4E0DD0`, size `0xa`.
- `get_bytes 0x004e0dcf size 16`: starts with `0xcc`, then successor bytes for `sub_4E0DD0`. The exact modeled function range is `0x004e0d70-0x004e0dcf` half-open, followed by one byte of `0xcc` padding at `0x004e0dcf-0x004e0dd0`.

Current IDA names remain raw in this session:

- `lookup_funcs LoadPartFrameDrawRecord`: not found.
- `lookup_funcs NewHumanImageLib::LoadPartFrameDrawRecord`: not found.
- `lookup_funcs LoadFrameDrawRecord`: not found.
- `lookup_funcs sub_4E0D70` and `sub_4D1600`: both resolve. Use current raw IDA names as evidence facts, but use the accepted source-facing names from by-* support docs for reconstruction.

## Target Decompile And Disassembly Meaning

Current MCP `decompile 0x004e0d70` returns:

```c
int __thiscall sub_4E0D70(_DWORD *this, int a2, unsigned __int16 a3, int a4, int a5, int a6)
{
  int v6; // esi
  int v7; // edx
  int result; // eax
  int v9; // ecx

  v6 = this[1] + 68 * a2; /*0x4e0d88*/
  v7 = *(_DWORD *)(v6 + 60) + 32 * a3; /*0x4e0d92*/
  result = *(_DWORD *)(v7 + 28); /*0x4e0d95*/
  v9 = *(_DWORD *)(result + 16 * a4 + 12); /*0x4e0d98*/
  if ( v9 ) /*0x4e0d9e*/
    return sub_4D1600(*(unsigned __int16 **)(v6 + 64), *(_DWORD *)(v9 + 8 * a5 + a5) + *(_DWORD *)(v7 + 8), a6); /*0x4e0dc3*/
  return result; /*0x4e0dc8*/
}
```

Current MCP `disasm 0x004e0d70` gives the source-shape details:

- `0x004e0d79 mov eax, [ecx+4]`: `this->m_partEntries` begin pointer.
- `0x004e0d7f shl edx, 4`, `0x004e0d84 add edx, [ebp+arg_0]`, `0x004e0d88 lea esi, [eax+edx*4]`: computes `partIndex * 0x44`, selecting a `NewHumanPartEntry`.
- `0x004e0d8b movzx edx, [ebp+arg_4]`, `0x004e0d8f shl edx, 5`, `0x004e0d92 add edx, [esi+3Ch]`: selects a 0x20-byte frame descriptor from part-row offset `+0x3c`.
- `0x004e0d95 mov eax, [edx+1Ch]`: loads the descriptor's sequence/motion table pointer.
- `0x004e0d98 mov ecx, [eax+ecx*8+0Ch]`: after `ecx = 2 * motionIndex`, selects the per-motion sequence-frame table pointer at `base + 0x10 * motionIndex + 0x0c`.
- `0x004e0d9c test ecx, ecx` / `0x004e0d9e jz 0x004e0dc8`: null sequence table means no output write and return.
- `0x004e0da0 mov eax, [ebp+arg_C]`, `0x004e0da6 lea ecx, [ecx+eax*8]`, `0x004e0da9 movq xmm0, qword ptr [ecx+eax]`: selects the 0x09-stride frame mapping record as `sequenceFrames->frames[frameIndex]`; the first dword is the record index used here.
- `0x004e0dae mov eax, [edx+8]`: descriptor `drawIndexBase`.
- `0x004e0dbc add eax, dword ptr [ebp+var_C]`: adds `sequenceFrames->frames[frameIndex].recordIndex`.
- `0x004e0dc0 push dword ptr [esi+40h]`: passes part-row offset `+0x40`, the raw frame/archive table consumed by `LoadFrameDrawRecord`.
- `0x004e0dc3 call sub_4D1600`: shared frame draw-record projection helper.
- `0x004e0dcc retn 14h`: five explicit stack arguments, with `this` in `ecx`.

The `movq` copies eight bytes from the 0x09-stride mapping row because the row carries more than just the first dword record index, but this helper only uses the first dword. The recommended first-draft body reads the source-level `recordIndex` field and leaves the unused payload unnamed.

## Callee Evidence

Current MCP `analyze_function 0x004d1600` reports `sub_4D1600`, prototype `int __stdcall(unsigned __int16 *, int, int)`, size `93`, no callees, and modeled callers including this target, `0x004e4210`, `0x004e4280`, `0x004ff7d0`, and `0x0055b5d0`.

Current MCP `disasm 0x004d1600` proves the three-stack-argument helper does not consume the caller's incoming `ecx`:

- `0x004d1603 mov ecx, [ebp+arg_4]`: loads `frameIndex` from the stack, overwriting incoming `ecx`.
- `0x004d160a mov edx, [ebp+arg_0]`: loads the table pointer.
- `0x004d1610 cmp ecx, eax`: bounds-checks against table count.
- `0x004d161a lea edx, [eax+ecx*8]`: selects a 0x18-byte packed record after `ecx = frameIndex * 3`.
- `0x004d1623`, `0x004d162b`, `0x004d1631`, `0x004d1638`, and `0x004d1641`: write fields to the caller-provided output draw record.
- `0x004d1648-0x004d1659`: out-of-range path clears output `+0x04` and `+0x24`.

Therefore the target's `0x004e0db1 mov ecx, dword_67A744` before `call sub_4D1600` is not a semantic receiver argument for this call in the current IDB. Do not turn it into an ItemObjImageLib, ResourceLayout, or global-manager owner route. The accepted [UID:0002P6] `LoadFrameDrawRecord` first-draft body is the correct support API:

```cpp
void LoadFrameDrawRecord(const ArchiveMetadataTable *table,
                         int frameIndex,
                         FrameDrawRecord *outRecord)
```

B006 accepted and executed the [UID:0002P6] update on 2026-06-29: `LoadFrameDrawRecord` is now `88/92`, emits first-draft `void LoadFrameDrawRecord(...)`, and documents the `void` return rationale even though IDA infers `int`.

## Caller Evidence

Current MCP `xrefs_to 0x004e0d70` reports exactly two code xrefs:

| Call site | Containing function | Current raw name | Source-facing support |
| --- | --- | --- | --- |
| `0x0050141a` | `0x00501360-0x0050158a` | `sub_501360` | [UID:0000FL] `UserHairSelectControlPane::OnPaintFrame` |
| `0x005018fa` | `0x00501840-0x00501a6a` | `sub_501840` | [UID:0000FJ] `UserFaceSelectControlPane::OnPaintFrame` |

The `sub_501360` decompile context around `0x0050141a` passes:

- receiver `dword_67A760`, the `g_pNewHumanImageLib` singleton;
- `partIndex = 5`, the hair part category in the hair-selector grid;
- a `uint16_t` hair part frame id from `m_hairPartFrames[m_genderStyle][slot]`;
- `motionIndex = 2`;
- `frameIndex = 0`;
- a stack/local output draw-record buffer.

The `sub_501840` decompile context around `0x005018fa` passes:

- receiver `dword_67A760`, the `g_pNewHumanImageLib` singleton;
- `partIndex = 2`, the face part category in the face-selector grid;
- a `uint16_t` face part id from `m_facePartIds[m_gender][slot]`;
- `motionIndex = 2`;
- `frameIndex = 0`;
- a stack/local output draw-record buffer.

These caller facts support the recommended argument names:

- `partIndex`: the NewHuman part category row (`5` for hair, `2` for face).
- `descriptorIndex`: the per-part descriptor/part id read from UI selector tables.
- `motionIndex`: the per-motion or per-sequence table selector. Existing support also uses the name `sequence`; `motionIndex` is preferred here because the target page already describes a motion-specific draw mapping.
- `frameIndex`: the row in the selected sequence frame table.
- `outRecord`: the render-side `NewHumanDrawRecord` / `FrameDrawRecord`-compatible output buffer.

## Existing Documentation And Report Leads

Current target page state:

- [UID:000417] is `84/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, and blank formal C++.
- It already documents the exact half-open range `0x004e0d70-0x004e0dcf`, the inferred `NewHumanImageLib::LoadPartFrameDrawRecord` name, the two UI/preview xrefs, and the bridge to `0x004d1600`.
- Its current score rationale explicitly says the page remained below gate because helper-specific C++ signature and descriptor typedefs were not promoted.

Prior report/search findings:

- B011 `0002JR-NewHumanImageLibConstructor-source-quality.md` created this exact child page and intentionally left it below-gate at `84/86`, no owner/emitter, blank C++; the stated future route was [UID:000092] after exact `LoadFrameDrawRecord` and descriptor typedef support synchronized.
- `by-memory/-report.old.md` is a historical lead, not authority, but it independently recorded the same source-facing method name, the same two caller classes, and the same `void __thiscall NewHumanImageLib::LoadPartFrameDrawRecord(int partIndex, std::uint16_t descriptorIndex, int motionIndex, int frameIndex, FrameDrawRecord_4D1600 *outRecord)` shape.
- B007 `0000FJ-UserFaceSelectControlPane-source-quality.md` documents `UserFaceSelectControlPane::OnPaintFrame` calling `NewHumanImageLib::LoadPartFrameDrawRecord(..., 2, facePartId, 2, 0, frameContext)`.
- B009 `0000FL-UserHairSelectControlPane-source-quality.md` documents `UserHairSelectControlPane::OnPaintFrame` calling `g_pNewHumanImageLib->LoadPartFrameDrawRecord(5, partFrameId, 2, 0, partFrame)`.
- B014 `0002V8-NewHumanImageLibCalculateCompositionBounds-source-quality.md` and its executed helper pages resolved the relevant `NewHumanPartEntry`, `NewHumanPartFrameDescriptor`, `NewHumanSequenceFrameTable`, `NewHumanDrawRecord`, and `LoadFrameDrawRecord` support vocabulary for first-draft NewHumanImageLib helper bodies.
- B006 `0000K1-ImageFrameTable-empty-emitter-family-source-quality.md` resolved [UID:0002P6] `LoadFrameDrawRecord` as a first-draft `void` helper with `ArchiveMetadataTable`, `PackedArchiveRecord`, and `FrameDrawRecord` support declarations.

## Support Type And Field Resolution

Accepted support names are now sufficient for source-ready first draft:

| Observed target access | Accepted source-facing field/type |
| --- | --- |
| `this[1]`, object offset `+0x04` | `m_partEntries` / `NewHumanPartEntry *` from [UID:0001VF] `NewHumanImageLibLayout` |
| part row stride `0x44` | `NewHumanPartEntry` row, already used by constructor/destructor/composition helpers |
| part row `+0x3c` | `part->frameDescriptors` / descriptor base |
| descriptor stride `0x20` | `NewHumanPartFrameDescriptor` |
| descriptor `+0x08` | `descriptor->drawIndexBase` |
| descriptor `+0x1c` | `descriptor->sequenceFrames` support pointer |
| sequence/motion slot at `base + 0x10 * motionIndex + 0x0c` | `descriptor->sequenceFrames[motionIndex]` as used by [UID:000438] |
| frame mapping row stride `0x09`, first dword | `sequenceFrames->frames[frameIndex].recordIndex` |
| part row `+0x40` | `part->rawRecords` / archive frame table passed to `LoadFrameDrawRecord` |
| output pointer argument | `NewHumanDrawRecord *outRecord`, compatible with `FrameDrawRecord` support |

[UID:000438] `NewHumanImageLib::ResolveCompositionPartFrame` already emits a class-owned first-draft helper using the same source vocabulary:

```cpp
NewHumanPartFrameDescriptor *descriptor = &part->frameDescriptors[selectedPart];
NewHumanSequenceFrameTable *sequenceFrames = descriptor->sequenceFrames[sequence];
if (sequenceFrames != NULL) {
    LoadFrameDrawRecord(
        part->rawRecords,
        sequenceFrames->frames[frame].recordIndex + descriptor->drawIndexBase,
        outRecord);
    return RectBoundsAdjust(&outRecord->bounds, xOffset, yOffset);
}
```

UID000417 is the same frame-record resolution core without the clamping and rectangle-adjust call, and with the part row selected from `this->m_partEntries[partIndex]`.

## Ownership And Source Placement Ranking

1. [UID:000092] `NewHumanImageLib`, emitted through [UID:0000LR] `NewHumanImageLib.cpp`: strongest owner. The function uses `this`, indexes the `NewHumanImageLib` part vector, consumes NewHuman descriptor/sequence-frame tables, is named in class/file/local-cluster docs, and is called through `g_pNewHumanImageLib` by both UI consumers.
2. [UID:0000LR] `by-file/NewHumanImageLib.md`: source-file route. It already owns the NewHuman render/image source file and accepted helper-name cluster, and [UID:000092] is its class route.
3. [UID:0000OX] `UserCreateAppearanceControls`: caller-only. Hair/face selectors call this helper while drawing thumbnails, but they do not own the table data or frame-resolution algorithm.
4. [UID:0000K1] `ImageFrameTable` / [UID:0002P6] `LoadFrameDrawRecord`: callee-only support. It owns the shared projection helper at `0x004d1600`, but not this NewHuman-specific descriptor lookup wrapper.
5. [UID:00017R] `NewHumanImageLibLocalMethodCluster`: support aggregate only. It should keep non-emitting aggregate status while its exact child page UID000417 becomes a routed first-draft child.

## Negative Evidence And Exclusions

- Do not keep `CANONICAL_OWNER:NONE`: the original blocker was unresolved helper/type names, and those support names are now accepted by executed NewHuman/ImageFrameTable reports.
- Do not fold this into [UID:0002JR] `NewHumanImageLibConstructor`: current MCP xrefs are only the two UI paint callers at `0x0050141a` and `0x005018fa`; there is no constructor call. The function is outside the constructor range and uses runtime part/frame parameters.
- Do not assign to `UserHairSelectControlPane` or `UserFaceSelectControlPane`: they are consumers that pass category/id/frame arguments from UI tables; the function body reads `NewHumanImageLib` internal layout.
- Do not assign to `ImageFrameTable`, `ResourceLayoutTable`, `EPFLib`, `GrafPort`, `PaletteLib`, or Surface callback docs: those are downstream/shared render dependencies, not owner routes for this wrapper.
- Do not assign to `dword_67A744` or a frame-table manager class based on `mov ecx, dword_67A744`: current callee disassembly overwrites `ecx` from stack argument `frameIndex`, so this register load is not a source receiver for `sub_4D1600`.
- Do not keep raw `sub_4E0D70` naming in source: raw name lookup is a current IDA fact, but by-* docs and prior reports consistently support `LoadPartFrameDrawRecord` as the source-facing name.
- Do not require a no-code proof: the body is compact, exact, source-shaped, has two real callers, uses accepted support types, and clears the current `(COMPLETION + CONFIDENCE) / 2 > 85` emitter gate after the recommended score update.

## Score Rationale

Recommended `88/90`:

- Completion `88`: exact half-open range, successor padding, current MCP lookup/decompile/disassembly/basic-block/xref/callee facts, two caller contexts, callee semantics, source owner route, formal C++ body, and support type names are now documented. It remains below final-audit quality because original spellings for nested descriptor/sequence-frame fields and the unused 0x09-row payload remain inferred.
- Confidence `90`: current MCP evidence agrees with existing by-* docs, B011's original route prediction, B006's `LoadFrameDrawRecord` first-draft support, B014's NewHuman nested type support, and the B007/B009 caller evidence. Confidence stays below final-source certainty because current IDA still has raw names for both `sub_4E0D70` and `sub_4D1600`, and final original field names are inferred rather than symbol-proven.

This score clears the active code-entry rule from `by-structure.md`: average `(88 + 90) / 2 = 89`, with nonblank `EMITTER_UIDS:000092`.

## Implementation Recommendations After Supervisor Acceptance

Primary target:

- Update [UID:000417] metadata to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:000092`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000092`, blank `EMITTER_POSITION_OPTIONAL`.
- Replace the target's below-gate/no-owner prose with current MCP evidence at report-level detail: session `supervisor_resume_20260629`, raw IDA names, exact range, one-byte successor padding, three basic blocks, two callers, one semantic callee, decompile/disassembly row mapping, current name-lookup negative evidence, and support-type resolution.
- Insert the exact formal C++ block from this report.

Support docs to update if accepted:

- [UID:000092] `by-class/NewHumanImageLib.md`: change the `LoadPartFrameDrawRecord` row from below-gate/candidate-only to resolved first-draft method at `88/90`, owner/emitter [UID:000092], emitted through [UID:0000LR]. Keep class-page declaration-container policy; do not paste method body into the class overview if the current policy keeps class C++ blank.
- [UID:0000LR] `by-file/NewHumanImageLib.md`: replace stale wording saying UID000417 is disabled/non-emitting; record that UID000417 now emits through [UID:000092] and depends on accepted `NewHumanImageLibLayout` and `LoadFrameDrawRecord` support.
- [UID:00017R] `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`: change the UID000417 inventory row and the below-gate helper paragraph to routed first-draft child status while preserving the aggregate as `RECONSTRUCTABLE:FALSE` and non-emitting.
- [UID:0001VF] `by-type/by-struct/NewHumanImageLibLayout.md`: no required body edit found. It already supplies the accepted member/row names and composition helper evidence used here. If supervisor wants a cross-reference-only sync, add UID000417 as another consumer of the already documented descriptor/sequence-frame names.
- [UID:0002P6] `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md`: no edit required by this report. It already emits the accepted `void LoadFrameDrawRecord(...)` body and documents the return-value rationale.
- [UID:0000FL] `UserHairSelectControlPane` and [UID:0000FJ] `UserFaceSelectControlPane`: no required body edits found. They already describe calls to `LoadPartFrameDrawRecord` with categories `5` and `2` respectively. If supervisor wants exact target-score synchronization, add a short support note only; do not move ownership.
- Current unrelated stale UID-collision references in `TimerMgr` docs were observed by search, but they are outside this target assignment and should not be edited in this callback unless the supervisor explicitly scopes them.

## Implementation Tracking Checklist

- [x] Target metadata updated to `88/90`, owner/emitter [UID:000092], reconstructable true, blank optional emitter position. Proof: `by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md` now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:000092`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000092`, and blank `EMITTER_POSITION_OPTIONAL`; validator `000000001850` recorded completion/confidence/canonical-owner/autogen-registry updates and exited `0` / `ok:1`.
- [x] Target `RECONSTRUCTION_CPP CODE` block contains the exact recommended `void NewHumanImageLib::LoadPartFrameDrawRecord(...)` first-draft body. Proof: target formal block matches this report's first-draft body; generated `auto-generated/NexusTK/render/NewHumanImageLib.cpp` lines `178-197` now emit UID000417 as `void NewHumanImageLib::LoadPartFrameDrawRecord(...)`, not an empty marker.
- [x] Target status/evidence records current MCP session `supervisor_resume_20260629`, raw IDA names, exact half-open range, one-byte padding, three basic blocks, two callers, one semantic callee, and current name-lookup negative evidence. Proof: target `Current MCP Evidence` section records callback health check plus accepted MCP target profile for `sub_4E0D70`, `sub_4D1600`, raw-name lookups, blocks, padding, xrefs, and callee.
- [x] Target behavior documents `m_partEntries[partIndex]`, 0x44 part row stride, `+0x3c` descriptor base, 0x20 descriptor stride, `+0x1c` sequence table pointer, 0x10 motion/sequence slot stride, nullable sequence branch, 0x09 frame mapping stride, descriptor `drawIndexBase`, part `rawRecords`, and `LoadFrameDrawRecord` call. Proof: target `Behavior And Row Mapping` and `Support Type Resolution` sections include these exact offsets/fields and the null branch/no-output-write behavior.
- [x] Target negative evidence rejects constructor folding, caller ownership, ImageFrameTable/callee ownership, `dword_67A744` ownership, raw `sub_4E0D70` source naming, and no-code disposition. Proof: target `Rejected Alternatives`, `Callee Evidence`, and `Ownership And Source Placement` sections include each exclusion.
- [x] `by-class/NewHumanImageLib.md` stale UID000417 below-gate/candidate-only wording superseded. Proof: method-family row now says UID000417 is `88/90`, class-owned/emitting with `EMITTER_UIDS:000092`; the 2026-06-30 B004 sync section carries range/padding/caller/callee/field and negative-owner details; historical B011 change text now says UID000417 is superseded by B004. Validator `000000001851` exited `0` / `ok:1`.
- [x] `by-file/NewHumanImageLib.md` stale UID000417 disabled/non-emitting wording superseded. Proof: file page now states UID000417 is class-owned/emitting through [UID:000092] and depends on `NewHumanImageLibLayout` plus `LoadFrameDrawRecord`; the generated-output note includes UID000417 on the emitter route; historical B011 change text now says UID000417 is superseded by B004. Validator `000000001852` exited `0` / `ok:1`.
- [x] `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md` UID000417 inventory row and below-gate paragraph updated while preserving aggregate non-emitter status. Proof: active-function and child-state rows now record UID000417 as a routed first-draft child at `88/90`; the resolved/disabled table says it is no longer disabled/excluded; the aggregate metadata remains `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++. Validator `000000001853` exited `0` / `ok:1`.
- [x] `by-type/by-struct/NewHumanImageLibLayout.md` inspected during callback; unchanged as already-present support. Proof: targeted scan showed the layout page already has owner/emitter [UID:000092], accepted `NewHumanImageLibLayout` support, and no direct stale UID000417 contradiction; no edit required.
- [x] `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md` inspected during callback; no edit required because B006 already resolved callee support. Proof: targeted scan confirmed it is already owner/emitter [UID:0000K1] with formal `void LoadFrameDrawRecord(...)` support and no UID000417 stale blocker.
- [x] `UserHairSelectControlPane` / `UserFaceSelectControlPane` inspected during callback; no edits required. Proof: targeted scan confirmed hair page already describes the `LoadPartFrameDrawRecord` call with part category `5`, and face page already describes the call with part category `2`; no direct stale accepted-item wording was present.
- [x] Scoped validators run for every changed by-* doc with `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`. Proof: validator command IDs/timestamps are recorded below.
- [x] Generated `auto-generated/NexusTK/render/NewHumanImageLib.cpp` freshness inspected only through validator-owned refresh/header metadata after validators; no generated output was edited manually. Proof: header reports `validator-command-id: 000000001852`, `validator-refreshed-at: 2026-06-30T00:37:34-04:00`, `validator-refresh-source: deferred-generated-refresh`; UID000417 appears at lines `178-197` as the emitted method body.
- [x] Leases acquired only immediately before editing and no by-* edits were made after the release/expiry check. Proof: initial lease attempt acquired only the target and rejected support docs as already leased; B004 released the target, waited, retried, and acquired all four edit-target leases successfully. After the edit/validator batch, `python leaser.py B004 unlease ...` returned target `Rejected[No active lease]` and support docs `Rejected[Lease owned by B006]`, showing B004 no longer held releasable leases by the explicit release attempt; no further by-* edits were made after that point.

## Validator Results

| File | Command | command_id | command_timestamp | exit | ok | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md` | `python .\tools\validator.py --mode file --file by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md --apply --queue-timeout 240` | `000000001850` | `2026-06-30T00:37:18-04:00` | `0` | `1` | Applied UID/link/stat/autogen-registry updates; generated refresh deferred under this command. |
| `by-class/NewHumanImageLib.md` | `python .\tools\validator.py --mode file --file by-class/NewHumanImageLib.md --apply --queue-timeout 240` | `000000001851` | `2026-06-30T00:37:27-04:00` | `0` | `1` | No structural errors; generated refresh deferred. |
| `by-file/NewHumanImageLib.md` | `python .\tools\validator.py --mode file --file by-file/NewHumanImageLib.md --apply --queue-timeout 240` | `000000001852` | `2026-06-30T00:37:34-04:00` | `0` | `1` | Generated `NewHumanImageLib.cpp` header refreshed from this command. |
| `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md` | `python .\tools\validator.py --mode file --file by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md --apply --queue-timeout 240` | `000000001853` | `2026-06-30T00:37:41-04:00` | `0` | `1` | Reported pre-existing `missing_ref_uid 0003UD`, but command still exited `0` / `ok:1`; validator also normalized UID links. |

Generated freshness check:

- Read-only file inspected: `auto-generated/NexusTK/render/NewHumanImageLib.cpp`.
- Header: `validator-command-id: 000000001852`, `validator-refreshed-at: 2026-06-30T00:37:34-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- UID000417 state: present at generated lines `178-197` as `void NewHumanImageLib::LoadPartFrameDrawRecord(...)` with the accepted formal body; no empty-emitter marker remains for UID000417.

Lease record:

- Initial acquisition command: `python leaser.py B004 lease <target> <class> <file> <cluster>` returned target `Success`, support docs `Rejected[Already has lease]`.
- B004-only support unlease probe returned `Rejected[Lease owned by Agent-B002]` for class/file/cluster; target was then released successfully.
- Retry acquisition after a short wait returned `Success` for all four changed by-* docs.
- Post-validator release command returned target `Rejected[No active lease]`, class/file/cluster `Rejected[Lease owned by B006]`. This is recorded as the exact final lease state observed by the leaser command; no by-* edits were made after this release/expiry check.

## Claim And Incorporation Ledger

| Claim ID | Report claim | Evidence | Target/support incorporation plan | Verification state |
| --- | --- | --- | --- | --- |
| C01 | UID000417 should promote from `84/86`, no-owner, non-emitting to `88/90`, owner/emitter [UID:000092]. | Current MCP exact target evidence plus B011 route prediction and accepted support-name docs. | Update target metadata; update class/file/cluster stale below-gate wording. | Applied. Target metadata updated and validator `000000001850` recorded completion/confidence/canonical-owner/autogen updates; class/file/cluster stale wording superseded and validators `000000001851`-`000000001853` passed. |
| C02 | Exact range is `0x004e0d70-0x004e0dcf` half-open with one `0xcc` byte before successor `0x004e0dd0`. | MCP `lookup_funcs`, `basic_blocks`, `get_bytes`, successor lookup. | Add to target evidence; cluster row may mention exact child range unchanged. | Applied. Target status/current MCP evidence and cluster active row record the exact half-open range, one-byte padding, successor `sub_4E0DD0`, and three basic blocks. |
| C03 | Current IDA names are raw `sub_4E0D70` and `sub_4D1600`; source names are accepted by docs, not active IDA symbols in this session. | MCP name lookups for source names return not found; raw names resolve. | Add current MCP evidence and raw/source-name distinction to target. | Applied. Target, class, file, and cluster B004 sections explicitly separate raw current IDA names from accepted source-facing names. |
| C04 | Function body selects `m_partEntries[partIndex]`, a descriptor row, a nullable motion/sequence frame table, a frame mapping row, then calls `LoadFrameDrawRecord`. | MCP decompile and disasm offsets `0x004e0d79-0x004e0dc3`; support docs UID0001VF/UID000438. | Add target behavior section and formal C++ body. | Applied. Target behavior/support tables and formal C++ carry the row mapping; class/file/cluster support summaries record the same shape. |
| C05 | Formal C++ should return `void`, not IDA's inferred `int`. | Callers ignore return; B006 [UID0002P6] resolved `LoadFrameDrawRecord` as `void`; null branch has no source-level output write. | Insert recommended body with `void` return and no write on null sequence table. | Applied. Target formal block and generated UID000417 body both emit `void NewHumanImageLib::LoadPartFrameDrawRecord(...)`; null branch returns before output write. |
| C06 | `dword_67A744` loaded before the callee is not an owner/receiver route for `LoadFrameDrawRecord`. | MCP callee disassembly overwrites `ecx` from stack argument at `0x004d1603`; accepted callee prototype has three stack args. | Add negative evidence to target. | Applied. Target callee evidence and rejected alternatives record the `0x004d1603` `ecx` overwrite; class/file/cluster B004 sections preserve the dependency-owner exclusion. |
| C07 | Two current code xrefs are hair and face selector paint callers. | MCP `xrefs_to`; caller decompile/disasm contexts; B007/B009 docs. | Add caller table to target; no ownership change for caller docs unless stale wording found. | Applied. Target caller table records call sites `0x0050141a` and `0x005018fa`; class/file support text keeps those classes as callers only. Hair/face docs were inspected and left unchanged as already-present support. |
| C08 | Support type names are implementation-ready: `NewHumanPartEntry`, `NewHumanPartFrameDescriptor`, `NewHumanSequenceFrameTable`, `NewHumanDrawRecord`, `LoadFrameDrawRecord`. | UID0001VF layout, UID000437/UID000438 composition helpers, UID0002P6 callee. | Use these names in target C++; no support body edits required unless supervisor wants cross-ref-only sync. | Applied/already-present. Target formal C++ and support table use these names; `NewHumanImageLibLayout`, `LoadFrameDrawRecord`, and caller pages were inspected and did not need body edits. |
| C09 | Constructor folding and aggregate-only/no-code disposition are invalid after this pass. | Function outside constructor range; xrefs only from UI callers; exact child has source-shaped body and support types. | Supersede target/class/file/cluster stale below-gate/no-code wording. | Applied. Target negative evidence rejects constructor fold/no-code; class/file/cluster B004 sections supersede B011 below-gate wording while preserving [UID00017R] as non-emitting aggregate only. |
| C10 | Generated output currently lacks UID000417 because it has no emitter route. | Read-only `rg` against `auto-generated/NexusTK/render/NewHumanImageLib.cpp` found empty markers for support UIDs but no UID000417 entry. | After callback validators, inspect validator-owned refresh/header only; do not edit generated file. | Applied/verified. After validators, generated header shows `validator-command-id: 000000001852`, `validator-refreshed-at: 2026-06-30T00:37:34-04:00`; UID000417 appears at lines `178-197` as the emitted method body. |

## Implementation Completion State

FINISHED_IMPLEMENTATION. Accepted callback items were applied to the target/support by-* docs, already-present support pages were inspected and left unchanged, scoped validators passed, generated freshness was inspected read-only, and this checklist/ledger was updated. No generated C++ files, generated reports, coverage reports, IDA DB, supervisor ledgers, or MCP process state were manually edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/000417-NewHumanImageLibLoadPartFrameDrawRecord-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/000417-NewHumanImageLibLoadPartFrameDrawRecord-source-quality.md","timestamp":"2026-06-30T00:43:09","uid":"000417"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
