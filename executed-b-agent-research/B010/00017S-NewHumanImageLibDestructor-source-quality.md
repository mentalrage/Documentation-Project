** TARGET-REPORT-UID:00017S **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B010 Source-Quality Report: [UID:00017S] NewHumanImageLib Destructor

## Assignment

- Agent: B010.
- Assignment id: `B010-report-00017S-new-human-image-lib-destructor-source-quality-20260626`.
- Mode: report-only research. No by-* docs were edited.
- Target: [UID:00017S] `by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md`.
- Required output path: `tools/leaser/Agents/Agent-B010/research/00017S-NewHumanImageLibDestructor-source-quality.md`.
- MCP status: available and used. Session `80de0a67`, database `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, `server_health` status `ok`, auto-analysis ready, Hex-Rays ready, string cache ready.

## Executive Recommendation

[UID:00017S] should no longer stay as a file-owned blank-C++ page. It should be promoted to the direct class owner [UID:000092] `NewHumanImageLib`, with formal first-draft destructor C++ inserted into the target header block.

Recommended target metadata:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `86` | `90` |
| `CONFIDENCE` | `89` | `91` |
| `CANONICAL_OWNER` | `0000LR` | `000092` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `0000LR` | `000092` |
| `RECONSTRUCTION_CPP` | blank | populate with the formal block below |

The score should rise because current support docs now contain implementation-ready inferred member and row names, and the fresh MCP pass confirms the destructor's exact body, sole scalar-deleting caller, helper callees, helper xrefs, cleanup order, vtable reset, singleton clear, and boundary padding. It should not rise to 95+ yet because several helper-specific exact pages are still missing or below gate, and some nested descriptor field spellings remain inferred rather than original-symbol-proven.

## Current Target State

The source target currently records:

- `COMPLETION:86`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000LR`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LR`
- blank formal C++

The page already contains good boundary, cleanup-order, vtable, singleton, scalar-wrapper, and callee evidence. The stale blocker is the statement that final field/helper names are still below source quality. That was true when the page was last raised from the low-score queue, but it is no longer a sufficient reason to keep formal C++ blank because later accepted work added source-facing names and first-draft C++ for the constructor, layout, and composition helpers.

`auto-generated/NexusTK/render/NewHumanImageLib.cpp` is a read-only generated lead. It currently emits the constructor and composition helpers, and still shows a stale empty marker for [UID:00017S] with old `78/86` generated metadata despite the source by-memory header being `86/89`. This should be synchronized by scoped validation after accepted implementation, not by manual generated-file edits.

## Documentation Evidence Checked

Relevant current docs checked:

- Target [UID:00017S] `by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md`.
- Class [UID:000092] `by-class/NewHumanImageLib.md`.
- File [UID:0000LR] `by-file/NewHumanImageLib.md`.
- Layout [UID:0001VF] `by-type/by-struct/NewHumanImageLibLayout.md`.
- Vtable [UID:0001Y9] `by-type/by-vtable/NewHumanImageLibVtable.md`.
- Singleton [UID:0000RT] `by-global/g_pNewHumanImageLib.md`.
- Constructor [UID:0002JR] `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`.
- Scalar deleting destructor [UID:0002VN] `by-memory/0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md`.
- Motion cleanup helper [UID:000185] `by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md` and global [UID:0000PK] `by-global/DestroyMotionVector.md`.
- Descriptor/bounds support pages [UID:00041C], [UID:000437], [UID:000438], and [UID:000419].
- Local cluster [UID:00017R] `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`.
- Generated output `auto-generated/NexusTK/render/NewHumanImageLib.cpp` as a read-only generated lead.
- Old `by-memory/-report.old.md` only as a stale lead for helper-name history. It was not used as proof because stale Wave2 material is non-authoritative. Its helper names were rechecked against current MCP before being considered.

Important support-doc changes since the target's blank-C++ rationale:

- [UID:0002JR] constructor is now `91/92`, owner/emitter [UID:000092], with formal constructor C++ using `m_partEntries`, `m_layerEntries`, `m_motionEntries`, `m_auxiliaryEntries`, `m_loadedPartList`, `m_acc2drwEntries`, `m_hairColorEntries`, `NewHumanPartEntry`, `NewHumanLayerEntry`, `NewHumanMotionEntry`, `Acc2DrwEntry`, `kNewHumanHairPartIndex`, `LoadMotionTable`, `LoadPartSpriteDescriptors`, and `LoadAcc2DrwTable`.
- [UID:0001VF] layout explicitly says those member and row names are implementation-ready inference for first-draft source.
- [UID:000437]/[UID:000438] composition helpers now emit formal C++ using `NewHumanPartEntry`, `NewHumanPartFrameDescriptor`, `NewHumanSequenceFrameTable`, `NewHumanDrawRecord`, `ResolveCompositionPartRect`, and `ResolveCompositionPartFrame`.
- [UID:0002VN] scalar wrapper now resolves the source declaration to `virtual ~NewHumanImageLib();` plus the ordinary destructor body at [UID:00017S].

## Fresh IDA MCP Evidence

MCP session `80de0a67` was used during this report. No IDA DB edits were made.

### Server And Function Boundaries

- `server_health`: `status: ok`; database `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; module `NexusTK.exe`; imagebase `0x400000`; auto-analysis, Hex-Rays, and strings cache ready.
- `lookup_funcs`:
  - `0x004e0250`: `sub_4E0250`, size `0x374`.
  - `0x004e05c4`: not a function.
  - `0x004e05d0`: `sub_4E05D0`, size `0x60`, the next modeled helper after padding.
  - `0x004e6870`: `sub_4E6870`, size `0x38`, scalar deleting destructor wrapper.
  - `0x004dfd10`: `sub_4DFD10`, size `0x53a`, constructor.
- `get_bytes` around the target confirms six `0xcc` bytes before the destructor after constructor return, and post-body bytes with the destructor epilogue, the final invalid-parameter call, and padding before `0x004e05d0`.

### Target Body And Cleanup Order

`decompile 0x004e0250` confirms the target source shape:

1. Restores the `NewHumanImageLib` vtable at `this + 0x00`.
2. Walks the `m_partEntries` vector at `+0x04/+0x08/+0x0c` using a 68-byte row stride.
3. Releases each part row's `spriteArchive`/raw-record package pointer at row offset `+0x40`, including the nested pointer at package offset `+0x08`.
4. Walks each part row's descriptor rows at row offset `+0x3c`, with descriptor count at `+0x34`.
5. For each 32-byte descriptor row, frees pointer fields at descriptor offsets `+0x11` and `+0x16`, then walks and frees nested 16-byte sequence/frame rows through descriptor offsets `+0x1a/+0x1c`.
6. Frees the descriptor row array and clears descriptor pointer/count fields.
7. Walks the `m_layerEntries` vector at `+0x10/+0x14/+0x18` using a 32-byte row stride, freeing each row's child-index array at row offset `+0x1c`.
8. Walks the `m_motionEntries` vector at `+0x1c/+0x20/+0x24` using a 66-byte row stride, freeing dynamic fields at row offsets `+0x3a` and `+0x3e`, and clearing the row count/field at `+0x36`.
9. Frees `m_hairColorEntries` at `+0x54/+0x58/+0x5c`.
10. Calls the accessory/list/auxiliary/motion/layer/part storage cleanup chain in the observed order:
    - `0x004e5d00` on `this + 0x48` for the 3-byte `acc2drw.tbl` vector.
    - `0x004e5c30` on `this + 0x34` for the loaded-part/list state.
    - `0x004557f0` on `this + 0x28` for the 80-byte auxiliary vector.
    - `0x004e5dd0` on `this + 0x1c` for the 66-byte `Motion.tbl` vector.
    - inline direct free of `this + 0x10` layer vector storage.
    - `0x004e5e40` on `this + 0x04` for the 68-byte `Part.tbl` vector.
11. Clears `g_pNewHumanImageLib` / `dword_67A760` at `0x004e059e`.
12. Calls base `LObject` cleanup at `0x004f4a90`.

The tail order is important. The singleton clear happens after the member storage cleanup chain and before the base cleanup call, so formal C++ should not move it above the resource/vector cleanup sequence.

### Callers, Callees, And Xrefs

`callees 0x004e0250` returns:

- `0x00516030` and `0x00516170`: part/raw-record package cleanup.
- `0x005c7799`: raw `free` wrapper used for nested descriptor data.
- `0x005c7526`: checked/free wrapper for vector storage.
- `0x004e5d00`: 3-byte `Acc2DrwEntry` vector cleanup.
- `0x004e5c30`: loaded part/list state cleanup.
- `0x004557f0`: 80-byte auxiliary vector cleanup.
- `0x004e5dd0`: `DestroyMotionVector`.
- `0x004e5e40`: 68-byte part vector cleanup.
- `0x004f4a90`: base `LObject` cleanup.
- `0x005cd607`: invalid-parameter failure for checked large-allocation paths.

`xrefs_to 0x004e0250` returns a single code xref from `sub_4E6870` at `0x004e6876`, matching the scalar deleting destructor relation.

`xrefs_to 0x0061b76c` reconfirms the constructor and ordinary destructor vtable-base writes, including the destructor write at `0x004e027e`.

`xrefs_to 0x0067a760` reconfirms 52 singleton references, including the destructor clear at `0x004e059e`.

### Helper Reanalysis

Current MCP rechecked the score-limiting helper names instead of leaving them as unresolved future work:

| Address | Current MCP facts | Best current source-facing role |
| --- | --- | --- |
| `0x004e5d00-0x004e5d60` | Decompile takes a three-pointer vector header, computes a 3-byte element span, validates large allocations, frees storage, and zeroes begin/end/capacity. Xrefs are destructor call `0x004e052f` and constructor cleanup-table ref `0x00600284`. | `DestroyAcc2DrwVector`, a file-local/free cleanup helper for `m_acc2drwEntries`. |
| `0x004e5c30-0x004e5cd3` | Decompile drains a list count at `+0x10`, clears `+0x0c`, frees child pointers from the pointer array at `+0x04`, frees the pointer array with large-allocation validation, frees the sentinel/root pointer at `+0x00`, and zeros state. Xrefs are destructor call `0x004e0537` plus thunk `0x004e5ce0`. | `DestroyLoadedPartListState`, a cleanup helper for `m_loadedPartList` / list-sentinel state at `+0x34`. |
| `0x004e5ce0-0x004e5ce5` | Decompile is a thunk to `0x004e5c30`; one constructor cleanup-table xref at `0x00600276`. | Compiler cleanup thunk for the loaded-part/list state. No handwritten C++ needed. |
| `0x004e5dd0-0x004e5e39` | Existing exact page plus current xrefs confirm destructor call `0x004e0547` and constructor cleanup-table ref `0x0060025a`; body handles 66-byte `Motion.tbl` vector storage. | Existing `DestroyMotionVector`, still valid. |
| `0x004e5e40-0x004e5eaa` | Decompile takes a three-pointer vector header, computes a 68-byte element span, validates large allocations, frees storage, and zeroes begin/end/capacity. Xrefs are destructor call `0x004e0594` and constructor cleanup-table ref `0x0060023e`. | `DestroyPartVector`, a file-local/free cleanup helper for `m_partEntries`. |
| `0x004557f0-0x00455856` | Decompile takes a three-pointer vector header, computes an 80-byte element span, validates large allocations, frees storage, and zeroes begin/end/capacity. Xrefs include destructor call `0x004e053f`, constructor cleanup-table ref `0x00600268`, and two other callers in `sub_454010`. | Shared `DestroyAuxiliaryVector80` or `DestroyAuxiliaryEntries` helper. It is not uniquely owned by this destructor, but its `this + 0x28` call is the NewHumanImageLib auxiliary-vector cleanup. |
| `0x00423810-0x00423860` | Decompile takes a three-pointer 4-byte vector header; xrefs are broad and shared, including constructor cleanup-table ref `0x00600292` and many non-NewHuman callers. | Shared integer/pointer-vector cleanup, used by `m_hairColorEntries`; not a NewHuman-only helper page candidate. |

The old `by-memory/-report.old.md` names `DestroyAcc2DrwVector` and `DestroyPartVector` match current behavior, but this report treats them as accepted only because the current MCP pass independently confirms the element sizes, xrefs, and destructor/constructor-cleanup roles.

## Ownership And Source Placement

The direct owner should be [UID:000092] `NewHumanImageLib`, not [UID:0000LR] `NewHumanImageLib` file root:

- The target is the ordinary class destructor and scalar-wrapper [UID:0002VN] resolves the source declaration to `virtual ~NewHumanImageLib();`.
- Constructor [UID:0002JR] already uses direct class owner/emitter [UID:000092] with formal C++.
- The destructor writes the `NewHumanImageLib` vtable, cleans `NewHumanImageLib` fields, clears `g_pNewHumanImageLib`, and calls the base `LObject` cleanup.
- [UID:000092] and [UID:0000LR] both clear routing gates, so class ownership is not blocked by parent score.

The file root [UID:0000LR] remains the source module/emission root through `NexusTK/render/NewHumanImageLib.cpp`, but this by-memory method should attach to the class the same way the constructor and composition helpers do.

## Rejected Alternatives

- Keep owner/emitter [UID:0000LR]: rejected as stale direct-owner routing. The method is a class destructor, the constructor/scalar-wrapper pages already route through [UID:000092], and class parent score is valid.
- Keep formal C++ blank because names are not original-symbol proven: rejected. The project standard requires best source-facing inference when original names are unavailable, and current constructor/layout/composition pages already accept the needed member and row names for first-draft C++.
- Copy decompiler-shaped C++: rejected. Formal C++ must avoid `_DWORD`, `sub_`, `dword_`, raw SEH state, `v26`, and raw pointer arithmetic as source-facing code.
- Treat scalar deleting destructor as the source body: rejected. [UID:0002VN] is compiler-generated ABI glue regenerated from `virtual ~NewHumanImageLib()` plus this ordinary destructor.
- Move the destructor to old [UID:0000JY] `HumanImageLib`: rejected by the NewHumanImageLib vtable, singleton, layout, resource names, and constructor/scalar-wrapper evidence.
- Treat `0x004557f0` and `0x00423810` as NewHuman-only helpers: rejected. Their caller sets show shared use; only the calls from this destructor/constructor-cleanup table are NewHumanImageLib member cleanup evidence.

## Formal C++ Recommendation

The target is eligible for first-draft formal C++ now:

- `RECONSTRUCTABLE:TRUE`.
- Recommended `EMITTER_UIDS:000092`.
- Direct class parent and file root both clear the gate.
- The scalar wrapper requires an ordinary destructor definition to regenerate correct vtable/ABI output.
- Current support docs provide implementation-ready inferred names.

Insert this exact block into [UID:00017S] `RECONSTRUCTION_CPP CODE` if the supervisor accepts this report:

```cpp
NewHumanImageLib::~NewHumanImageLib()
{
    for (NewHumanPartEntry *part = m_partEntries.begin();
         part != m_partEntries.end();
         ++part)
    {
        ReleaseSpritePartArchive(part->spriteArchive);

        for (int descriptorIndex = 0;
             descriptorIndex < part->descriptorCount;
             ++descriptorIndex)
        {
            NewHumanPartFrameDescriptor &descriptor =
                part->frameDescriptors[descriptorIndex];

            delete [] descriptor.primaryFrameData;
            descriptor.primaryFrameData = NULL;
            descriptor.hasPrimaryFrameData = false;

            delete [] descriptor.secondaryFrameData;
            descriptor.secondaryFrameData = NULL;
            descriptor.hasSecondaryFrameData = false;

            for (int sequenceIndex = 0;
                 sequenceIndex < descriptor.sequenceCount;
                 ++sequenceIndex)
            {
                delete [] descriptor.sequenceFrames[sequenceIndex].frames;
                descriptor.sequenceFrames[sequenceIndex].frames = NULL;
                descriptor.sequenceFrames[sequenceIndex].frameCount = 0;
            }

            delete [] descriptor.sequenceFrames;
            descriptor.sequenceFrames = NULL;
            descriptor.sequenceCount = 0;
        }

        delete [] part->frameDescriptors;
        part->frameDescriptors = NULL;
        part->descriptorCount = 0;
    }

    for (NewHumanLayerEntry *layer = m_layerEntries.begin();
         layer != m_layerEntries.end();
         ++layer)
    {
        delete [] layer->childIndexes;
        layer->childIndexes = NULL;
        layer->childCount = 0;
    }

    for (NewHumanMotionEntry *motion = m_motionEntries.begin();
         motion != m_motionEntries.end();
         ++motion)
    {
        delete [] motion->frameOffsets;
        motion->frameOffsets = NULL;

        delete [] motion->frameData;
        motion->frameData = NULL;
        motion->frameCount = 0;
    }

    m_hairColorEntries.clear();
    DestroyAcc2DrwVector(&m_acc2drwEntries);
    DestroyLoadedPartListState(&m_loadedPartList);
    DestroyAuxiliaryEntries(&m_auxiliaryEntries);
    DestroyMotionVector(&m_motionEntries);
    DestroyLayerVector(&m_layerEntries);
    DestroyPartVector(&m_partEntries);

    g_pNewHumanImageLib = NULL;
}
```

C++ rationale:

- The code uses source-facing names already accepted or now MCP-supported: `NewHumanImageLib`, `NewHumanPartEntry`, `NewHumanLayerEntry`, `NewHumanMotionEntry`, `NewHumanPartFrameDescriptor`, `NewHumanSequenceFrameTable`, `m_partEntries`, `m_layerEntries`, `m_motionEntries`, `m_auxiliaryEntries`, `m_loadedPartList`, `m_acc2drwEntries`, `m_hairColorEntries`, and `g_pNewHumanImageLib`.
- `ReleaseSpritePartArchive`, `DestroyAcc2DrwVector`, `DestroyLoadedPartListState`, `DestroyAuxiliaryEntries`, `DestroyLayerVector`, and `DestroyPartVector` are inferred source-facing helper names. The current MCP pass documents their binary roles enough for first-draft C++; exact original spellings remain inferential.
- The block preserves the observed runtime cleanup order: part nested data, layer child arrays, motion dynamic fields, hair-color vector, accessory/list/auxiliary/motion/layer/part storage, singleton clear, then implicit base cleanup.
- The code deliberately omits compiler artifacts: vtable store, SEH/security-cookie state, checked large-allocation guard internals, raw invalid-parameter paths, and base destructor call. Those should be regenerated by the compiler or helper implementations.

## Score Rationale

Recommended `90/91`:

- Completion should rise from `86` to `90` because the report resolves the prior blank-C++/name blockers, routes to the direct class owner, supplies formal first-draft C++, and documents the formerly unresolved helper-name/source-shape decisions.
- Confidence should rise from `89` to `91` because fresh MCP confirms the exact target function, scalar-wrapper caller, vtable/global refs, helper xrefs, helper body semantics, and boundary bytes, while current support docs independently provide the source-facing names used in the formal block.
- Do not score above 95. The remaining limitations are real but no longer block first-draft code: helper-specific pages for `DestroyAcc2DrwVector`, `DestroyLoadedPartListState`, `DestroyPartVector`, and the shared 80-byte auxiliary cleanup are missing or not promoted; exact original field spellings for descriptor subfields remain inferred; and generated output currently shows stale metadata until validation refreshes it.

## Recommended Documentation Edits After Acceptance

Apply these only after supervisor acceptance and implementation callback.

1. Target [UID:00017S] `by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md`:
   - Set `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:000092`, `EMITTER_UIDS:000092`, `RECONSTRUCTABLE:TRUE`.
   - Insert the formal `RECONSTRUCTION_CPP CODE` block above.
   - Update status to say this is the class-owned ordinary destructor emitted through [UID:000092] into [UID:0000LR].
   - Replace the stale blank-C++ rationale with the current first-draft C++ rationale.
   - Preserve all existing boundary, scalar-wrapper, vtable, singleton, callee, and padding evidence.
   - Add this report's helper reanalysis table, including current MCP xrefs for `0x004e5d00`, `0x004e5c30`, `0x004e5ce0`, `0x004e5e40`, `0x004557f0`, and `0x00423810`.
   - Add a historical/superseded note that prior blank C++ was retained because field/helper names were below source quality; later constructor/layout/composition work superseded that blocker.

2. [UID:000092] `by-class/NewHumanImageLib.md`:
   - Update the method-family row for `~NewHumanImageLib` to state [UID:00017S] is now class-owned/emitting with first-draft destructor C++.
   - Add a short support note that the destructor now uses the accepted layout/member names from [UID:0001VF] and remains below final-audit score only because helper-specific pages and exact original spellings remain inferred.
   - Keep class score unchanged unless the implementation pass finds a directly supported score reason.

3. [UID:0000LR] `by-file/NewHumanImageLib.md`:
   - Update the source module inventory to say [UID:00017S] emits through [UID:000092] and supplies the ordinary destructor body required by [UID:0002VN].
   - Keep file score unchanged unless validation/report review finds a directly supported reason.

4. [UID:0001VF] `by-type/by-struct/NewHumanImageLibLayout.md`:
   - Add a destructor-consumer note that [UID:00017S] now uses the accepted member names for first-draft C++ and confirms cleanup agreement for `m_partEntries`, `m_layerEntries`, `m_motionEntries`, `m_auxiliaryEntries`, `m_loadedPartList`, `m_acc2drwEntries`, and `m_hairColorEntries`.

5. [UID:0002VN] `by-memory/0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md`:
   - Update only if needed to note that the ordinary destructor body now has first-draft formal C++. Do not add wrapper C++ to [UID:0002VN].

6. Optional exact helper split pages if the supervisor wants to close the helper-page gap now:
   - Create `by-memory/0x004e5d00-0x004e5d60.DestroyAcc2DrwVector.md` for the 3-byte `Acc2DrwEntry` vector cleanup.
   - Create `by-memory/0x004e5c30-0x004e5cd3.DestroyLoadedPartListState.md` for the list/sentinel cleanup helper.
   - Create `by-memory/0x004e5ce0-0x004e5ce5.DestroyLoadedPartListStateThunk.md` as a compiler cleanup thunk if by-structure requires exact coverage for the thunk.
   - Create `by-memory/0x004e5e40-0x004e5eaa.DestroyPartVector.md` for the 68-byte `NewHumanPartEntry` vector cleanup.
   - These helper pages are not required to insert [UID:00017S] first-draft C++, but they would improve helper coverage and reduce remaining confidence caps.

7. Do not manually edit generated/project-level files or any `-coverage-report.md` file. Let scoped validation and supervisor-owned coverage handling refresh reports.

## Implementation Tracking Checklist

Updated during accepted implementation callback `B010-implement-00017S-new-human-image-lib-destructor-source-quality-20260626`.

- [x] Edit [UID:00017S] target metadata to `90/91`, `CANONICAL_OWNER:000092`, `EMITTER_UIDS:000092`, `RECONSTRUCTABLE:TRUE`.
  - Proof: `by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md` header now has `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:000092`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000092`.
- [x] Insert the exact formal destructor C++ block from this report into [UID:00017S].
  - Proof: [UID:00017S] `RECONSTRUCTION_CPP CODE` now contains `NewHumanImageLib::~NewHumanImageLib()` with the accepted cleanup order and `g_pNewHumanImageLib = NULL`.
- [x] Update [UID:00017S] prose with class-owner route, MCP session `80de0a67`, current helper reanalysis, positive/negative evidence, score rationale, and superseded blank-C++ rationale.
  - Proof: added `2026-06-26 B010 Source-Quality Implementation`, `Helper Reanalysis`, updated `Reconstruction Notes`, `Score Rationale`, `Status`, and `Changes`; preserved old blank-C++ history as superseded.
- [x] Update [UID:000092] `by-class/NewHumanImageLib.md` destructor row/support prose.
  - Proof: method-family row now lists [UID:00017S] as `90/91` class-owned/emitting with first-draft destructor C++; added `2026-06-26 Destructor Source-Quality Sync` and a `Changes` entry.
- [x] Update [UID:0000LR] `by-file/NewHumanImageLib.md` inventory/source-module prose.
  - Proof: file page now states [UID:00017S] emits through [UID:000092] while this file remains the source-module route, explains the ordinary destructor body required by [UID:0002VN], and adds `2026-06-26 Destructor And Helper Sync`.
- [x] Update [UID:0001VF] `NewHumanImageLibLayout.md` with destructor cleanup agreement and first-draft destructor use of accepted member names.
  - Proof: added `2026-06-26 Destructor Consumer Evidence` table covering `m_partEntries`, `m_layerEntries`, `m_motionEntries`, `m_auxiliaryEntries`, `m_loadedPartList`, `m_acc2drwEntries`, and `m_hairColorEntries`.
- [x] Update [UID:0002VN] scalar-wrapper page only if needed to mention that the ordinary destructor now has first-draft formal C++; keep wrapper formal C++ blank.
  - Proof: scalar-wrapper page now says [UID:00017S] carries formal first-draft ordinary destructor C++; wrapper formal C++ remains blank and source-declared/generated-binary.
- [x] If supervisor chooses to close helper coverage now, create or update exact helper pages for `0x004e5d00`, `0x004e5c30`, `0x004e5ce0`, and `0x004e5e40` using the evidence in this report.
  - Proof: not created by this callback. `goal.md` explicitly said not to create helper pages unless required. The accepted helper reanalysis was incorporated into [UID:00017S] and support docs; no helper page was required to make the accepted destructor route valid.
- [x] Run scoped validators from `source-3/project-documentation` for every edited by-* file, starting with `python .\tools\validator.py --mode file --file by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md --apply --queue-timeout 240`.
  - Proof: validators passed for all five edited by-* files; command details below.
- [x] Report validator command, `command_id`, `command_timestamp`, exit code, `ok` count, and generated-refresh state for each edited file.
  - Proof: see `Implementation Callback Proof`.
- [x] Supervisor-owned: update any manual `-coverage-report.md` row if still required after scoped validation. B010 must not edit coverage reports directly.
  - Proof: B010 did not edit any `-coverage-report.md`; no manual coverage text was required from this callback after scoped validation. Supervisor remains owner of any manual coverage report update.
- [x] Confirm no active B010 leases remain after implementation.
  - Proof: leases were acquired successfully for the five by-* files before edits. Cleanup command returned `Rejected[No active lease]` for each B010 path, and `tools/leaser/Agents/current_leases.md` shows no active B010 leases. Other agents may hold unrelated active leases.

## Implementation Callback Proof

Changed by-* files:

- `by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md`
- `by-class/NewHumanImageLib.md`
- `by-file/NewHumanImageLib.md`
- `by-type/by-struct/NewHumanImageLibLayout.md`
- `by-memory/0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md`

Metadata before/after for [UID:00017S]:

| Field | Before | After |
| --- | --- | --- |
| `COMPLETION` | `86` | `90` |
| `CONFIDENCE` | `89` | `91` |
| `CANONICAL_OWNER` | `0000LR` | `000092` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `0000LR` | `000092` |
| `RECONSTRUCTION_CPP` | blank | formal `NewHumanImageLib::~NewHumanImageLib()` block |

Validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | Command | `command_id` | `command_timestamp` | Exit | `ok` | Generated refresh |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md --apply --queue-timeout 240` | `000000002739` | `2026-06-26T14:57:09-04:00` | `0` | `1` | `deferred`, `generated_refresh_command_id: 000000002739` |
| `by-class/NewHumanImageLib.md` | `python .\tools\validator.py --mode file --file by-class/NewHumanImageLib.md --apply --queue-timeout 240` | `000000002741` | `2026-06-26T14:57:20-04:00` | `0` | `1` | `deferred`, `generated_refresh_command_id: 000000002741` |
| `by-file/NewHumanImageLib.md` | `python .\tools\validator.py --mode file --file by-file/NewHumanImageLib.md --apply --queue-timeout 240` | `000000002742` | `2026-06-26T14:57:27-04:00` | `0` | `1` | `deferred`, `generated_refresh_command_id: 000000002742` |
| `by-type/by-struct/NewHumanImageLibLayout.md` | `python .\tools\validator.py --mode file --file by-type/by-struct/NewHumanImageLibLayout.md --apply --queue-timeout 240` | `000000002743` | `2026-06-26T14:57:36-04:00` | `0` | `1` | `deferred`, `generated_refresh_command_id: 000000002743` |
| `by-memory/0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md --apply --queue-timeout 240` | `000000002745` | `2026-06-26T14:57:51-04:00` | `0` | `1` | `deferred`, `generated_refresh_command_id: 000000002745` |

Validator-owned side effects: scoped validation updated projected stats/autogen registry/reference index as reported by validator. B010 did not manually edit generated reports, project-level files, manual coverage reports, tool state, or IDA DB.

Queue status check after validators: `python .\tools\validator.py --queue-status`, `command_id: 000000002749`, `command_timestamp: 2026-06-26T15:02:11-04:00`, exit `0`; worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.

Leases:

- Lease command succeeded for the five by-* files before editing.
- Release cleanup command after validation reported no active B010 lease for each path; the shared current lease report shows no active B010 leases. Other agents may hold unrelated active leases.

Unimplemented/excluded items:

- Helper child pages for `0x004e5d00`, `0x004e5c30`, `0x004e5ce0`, and `0x004e5e40` were intentionally not created because the callback accepted helper reanalysis incorporation and explicitly said not to create helper pages unless required. They remain optional future coverage improvements.
- Manual coverage report update is supervisor-owned and was not performed by B010.

## Original Report-Only Scope Proof

- Original report-only changed files: this report only.
- Original report-only by-* docs edited: none.
- Original report-only generated/project-level/coverage files edited: none.
- Original report-only IDA DB edits: none.
- Original report-only leases used: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/00017S-NewHumanImageLibDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/00017S-NewHumanImageLibDestructor-source-quality.md","timestamp":"2026-06-26T15:05:42","uid":"00017S"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
