** TARGET-REPORT-UID:0000N6 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# UID0000N6 RidingImageLib Empty-Emitter Family Source-Quality Report

Assignment: accepted implementation callback for [UID:0000N6] `by-file/RidingImageLib.md` from the Files With Empty Emitters queue.

Report status: implementation-callback complete and execution-ready for supervisor verification. I applied the accepted report details to the listed target/support by-* docs, updated this report's ledger/checklist, ran scoped validators with `--wait-generated`, and released all Agent-B008 leases. I did not manually edit generated C++ files, generated reports, manual coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, queue files, or lock files. I did not spawn subagents.

Target family: `RidingImageLib`, originally 16 emitters, 1 filled, 15 empty markers in `auto-generated/NexusTK/render/RidingImageLib.cpp`; after callback validation, generated `RidingImageLib.cpp` has zero `Empty Emitter Marker` hits.

## Required Disposition

The RidingImageLib file should remain the `NexusTK/render/RidingImageLib.cpp` source root. The current empty markers are not one uniform problem:

1. Source-ready declarations/bodies should be emitted now: class shell, `RidingDefinition` layout aliases, constructor, `RIDINGS.DNA` parser, riding-definition global table, and singleton global.
2. Compiler/generated artifacts should not pretend to be hand-authored source: vtable/data/scalar-deleting destructor pages should emit proof comments or be covered by the class declaration and ordinary destructor.
3. Broad container/cleanup pages should stop emitting: the early method cluster and singleton clear helper are support/cleanup artifacts, not source declarations.
4. The IDA-missed raw draw helper at `0x004dc7e0-0x004dca14` is the one rare no-improvement exception in this family: current MCP reconfirms no function object and no direct refs. Keep its behavior documentation, remove its emitter route for now, and do not invent a callable C++ signature from an orphan raw body.

Recommended file score after callback: [UID:0000N6] `COMPLETION:90`, `CONFIDENCE:90`. The score can clear the source-entry gate because the constructor/parser/global/type/class route has MCP-backed ownership, the ordinary destructor is already implemented, and the remaining non-emitting items are explicit compiler/container/raw-orphan exceptions rather than unresolved blockers. Confidence stays below final-source level because the original source names for some weak entry fields, package type names, and the raw draw helper ABI are still inferred or intentionally not emitted.

## Current Generated State

Generated output checked: `auto-generated/NexusTK/render/RidingImageLib.cpp`.

Accepted report baseline freshness:

- `validator-command-id: 000000002948`
- `validator-refreshed-at: 2026-06-30T14:41:03-04:00`
- `Source by-file UID: 0000N6`
- Contains first-draft [UID:00017G] `RidingImageLib::~RidingImageLib()`.
- Contains empty markers for [UID:0000BZ], [UID:0002LA], [UID:00017F], [UID:0002Y0], [UID:0002Y1], [UID:0002Y4], [UID:0001VV], [UID:0001VW], [UID:0001YM], [UID:00031E], [UID:0000TJ], [UID:0001PL], [UID:0000S4], [UID:0001PO], and [UID:000183].

Implementation-callback freshness after scoped validators and later validator-owned refresh:

- Current generated header `validator-command-id: 000000003133`
- Current generated header `validator-refreshed-at: 2026-06-30T15:40:39-04:00`
- Last Agent-B008 scoped by-* validator command touching this generated file: `000000003129` at `2026-06-30T15:37:16-04:00`
- `validator-refresh-source: foreground-generated-refresh`
- `Source by-file UID: 0000N6`
- `rg "Empty Emitter Marker|MARKER-ONLY|B008 Empty" auto-generated/NexusTK/render/RidingImageLib.cpp` count: `0`
- Generated file now includes the class shell, `LoadRidingDefinitions`, constructor, POD/global declarations, and proof comments from this callback.

## Implementation Callback Results

Changed by-* docs:

- `by-file/RidingImageLib.md`
- `by-class/RidingImageLib.md`
- `by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md`
- `by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md`
- `by-memory/0x004dc690-0x004dc722.RidingImageLibConstructor.md`
- `by-memory/0x004dc7e0-0x004dca14.RidingImageLibDrawRidingFrameRawHelper.md`
- `by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md`
- `by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md`
- `by-type/by-struct/RidingDefinition.md`
- `by-type/by-struct/RidingImageLibLayout.md`
- `by-type/by-vtable/RidingImageLibVtable.md`
- `by-memory/0x0061b6f0-0x0061b700.RidingImageLibVtableData.md`
- `by-global/RidingDefinitionGlobalTable.md`
- `by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md`
- `by-global/g_pRidingImageLib.md`
- `by-memory/0x0069b444-0x0069b448.g_pRidingImageLib.md`

Report changed:

- `tools/leaser/Agents/Agent-B008/research/0000N6-RidingImageLib-empty-emitter-family-source-quality.md`

Lease record:

- Initial edit batch: all 16 target/support docs were leased by Agent-B008 before editing; that 300-second lease window expired during the first long edit/validator cycle.
- Callback verification cleanup: all 16 target/support docs were re-leased, then explicitly released before the grouped validator rerun.
- Grouped validator rerun: four short lease groups were acquired and released successfully. Each group covered four changed by-* docs and completed inside the 300-second window.
- Final lease state: `tools/leaser/Agents/Agent-B008/current_leases.md` had no `Agent-B008` rows after release.

Scoped validator results from `E:/NTK/GhidraBridge/source-3/project-documentation`:

| File | Command ID | Command timestamp | Exit | OK | Warnings |
| --- | --- | --- | --- | --- | --- |
| `by-file/RidingImageLib.md` | `000000003109` | `2026-06-30T15:33:41-04:00` | `0` | `1` | `0` |
| `by-class/RidingImageLib.md` | `000000003111` | `2026-06-30T15:34:01-04:00` | `0` | `1` | `0` |
| `by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md` | `000000003113` | `2026-06-30T15:34:20-04:00` | `0` | `1` | `0` |
| `by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md` | `000000003115` | `2026-06-30T15:34:39-04:00` | `0` | `1` | `0` |
| `by-memory/0x004dc690-0x004dc722.RidingImageLibConstructor.md` | `000000003117` | `2026-06-30T15:34:59-04:00` | `0` | `1` | `0` |
| `by-memory/0x004dc7e0-0x004dca14.RidingImageLibDrawRidingFrameRawHelper.md` | `000000003119` | `2026-06-30T15:35:18-04:00` | `0` | `1` | `0` |
| `by-memory/0x004e68b0-0x004e6981.RidingImageLibScalarDeletingDestructor.md` | `000000003120` | `2026-06-30T15:35:38-04:00` | `0` | `1` | `0` |
| `by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md` | `000000003121` | `2026-06-30T15:35:48-04:00` | `0` | `1` | `0` |
| `by-type/by-struct/RidingDefinition.md` | `000000003122` | `2026-06-30T15:36:00-04:00` | `0` | `1` | `0` |
| `by-type/by-struct/RidingImageLibLayout.md` | `000000003123` | `2026-06-30T15:36:10-04:00` | `0` | `1` | `0` |
| `by-type/by-vtable/RidingImageLibVtable.md` | `000000003124` | `2026-06-30T15:36:21-04:00` | `0` | `1` | `0` |
| `by-memory/0x0061b6f0-0x0061b700.RidingImageLibVtableData.md` | `000000003125` | `2026-06-30T15:36:32-04:00` | `0` | `1` | `0` |
| `by-global/RidingDefinitionGlobalTable.md` | `000000003126` | `2026-06-30T15:36:43-04:00` | `0` | `1` | `0` |
| `by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md` | `000000003127` | `2026-06-30T15:36:54-04:00` | `0` | `1` | `0` |
| `by-global/g_pRidingImageLib.md` | `000000003128` | `2026-06-30T15:37:05-04:00` | `0` | `1` | `0` |
| `by-memory/0x0069b444-0x0069b448.g_pRidingImageLib.md` | `000000003129` | `2026-06-30T15:37:16-04:00` | `0` | `1` | `0` |

Validator notes:

- Every listed validator used `--apply --wait-generated --queue-timeout 240`.
- Each scoped run reported `generated_metadata_refresh` and exited cleanly.
- The quiet harness sampled lines containing the substring `Error` from unrelated pre-existing class names such as `DDError` and `ErrorMessage` inside `autogen_children_marker_missing` notices. These are not validator failures: all exit codes are `0`, all `ok` counts are `1`, and warning counts are `0`.
- Validator-owned generated refresh updated `auto-generated/NexusTK/render/RidingImageLib.cpp`; no generated C++ or generated report was manually edited.

## MCP Evidence

IDA MCP was available and responsive during this report. Current session evidence:

- `idb_list`: active session `supervisor_resume_20260629`, active worker for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health`: status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready.
- `lookup_funcs`:
  - `0x004dc420` -> `sub_4DC420`, size `0x26d`.
  - `0x004dc690` -> `sub_4DC690`, size `0x92`.
  - `0x004dc730` -> `sub_4DC730`, size `0xa8`.
  - `0x004dc7e0` -> no IDA function.
  - `0x004dca14` -> no IDA function.
  - `0x004dca20` -> `sub_4DCA20`, size `0x23`.
  - `0x004e5bf0` -> `sub_4E5BF0`, size `0x0b`.
  - `0x004e68b0` -> `sub_4E68B0`, size `0xd1`.
  - `0x004f4b10` -> `sub_4F4B10`, size `0x06`.
  - `0x0041b6c0` -> `nullsub_18`, size `0x03`.
- `xrefs_to`:
  - `0x004dc420`: one executable caller at `0x004dc6f5` inside the constructor.
  - `0x004dc690`: startup construction caller at `0x004f60ed`.
  - `0x004dc7e0`: no direct code or data refs.
  - `0x004e5bf0`: one constructor cleanup/support xref at `0x005fff4c`.
  - `0x004e68b0`: vtable data ref at `0x0061b6f4`.
  - `0x0069b430`: 11 refs, including parser/default-table refs and repeated render fallback use.
  - `0x0069b438`: exactly four parser refs at `0x004dc4f0`, `0x004dc500`, `0x004dc50d`, and `0x004dc519`, proving it is the `+0x08` field of the 12-byte global table, not a separate global.
  - `0x0069b444`: 20 singleton refs spanning constructor/destructor writes, cleanup, shutdown, and riding-aware consumers.
  - `0x0061b6f4`: constructor/destructor/scalar-destructor vtable refs.
- `callees`:
  - Parser `0x004dc420` opens/reads/closes `RIDINGS.DNA`, calls shared table helpers `0x005289d0` and `0x00528be0`, and uses vector construction.
  - Constructor `0x004dc690` calls base setup `0x004f4a80`, parser `0x004dc420`, and EPF loader `0x004d0f50`.
  - Ordinary and scalar destructors call shared package/vector cleanup and base cleanup.
  - Singleton clear helper has no callees.
- Data bytes:
  - `get_bytes 0x0069b420 size 48`: all zero bytes in the current IDB.
  - `get_int` u32le at `0x0069b430`, `0x0069b434`, `0x0069b438`, and `0x0069b444`: all `0`.
  - `get_int` u32le at `0x0061b6f0/0x0061b6f4/0x0061b6f8/0x0061b6fc`: `0x00648cb4`, `0x004e68b0`, `0x004f4b10`, `0x0041b6c0`.
  - `get_bytes 0x004e5bf0 size 16`: `c7 05 44 b4 69 00 00 00 00 00 c3 cc cc cc cc cc`, exact singleton clear helper followed by padding.
  - Padding boundaries: `0x004dc68d-0x004dc690`, `0x004dc7d8-0x004dc7e0`, and `0x004dca14-0x004dca20` are `0xcc` alignment gaps.

Decompile evidence:

- `0x004dc420` opens literal `L"RIDINGS.DNA"`, reads the definition count, allocates `count * 0x0c + 4`, stores pointer/count at `this+0x04/+0x08`, allocates `0x15` global default groups at `0x0069b430`, creates one default entry per group with frame offset `0`, duration `30000`, and flag byte `0`, then reads each riding definition and nested entry fields in the order documented below.
- `0x004dc690` publishes `g_pRidingImageLib`, runs base setup, installs the `RidingImageLib` vtable, zeroes the definition pointer, calls the parser, and stores the `RIDINGS.EPF` frame-table package handle at `this+0x0c`.
- `0x004e5bf0` only clears `g_pRidingImageLib`.
- `0x004e68b0` is the scalar deleting destructor wrapper around the ordinary destructor behavior plus optional delete.
- `0x004dca20` returns `this[1] + 12 * index` when `this[2] > index`, otherwise returns `&unk_69B430`; this supports source-facing name `RidingImageLib::GetDefinitionOrDefault`.

## Executed-Report Leads Consulted

- B003 `000178-00017G-00017I-00017W-00017X-00017Z-000180-0002J2-image-library-cleanup-source-quality.md`: accepted first-draft [UID:00017G] ordinary destructor and the `DestroyRidingDefinitionArray` / `FreeRidingDefinitionArray` aliases.
- B007 `0001CM-MonsterImageLibTables-empty-emitter-source-quality.md`: accepted shared helper names `ImageAnimationTable`, `ImageAnimationGroup`, and `ImageAnimationFrame`, plus `AllocateGroups`, `AllocateFrames`, and `GetFrame`. It also resolved adjacent `0x0069b424-0x0069b43c` byte-state confusion as current zero/virtual-zero-fill, not a helper blocker.
- B014 `0002V8-NewHumanImageLibCalculateCompositionBounds-source-quality.md`: accepted `RidingImageLib::GetDefinitionOrDefault` as the source-facing name for helper `0x004dca20` and uses it in NewHuman composition generated output.
- B007 `0002H7-ApplicationStartup-source-quality.md`: confirms startup constructs `new RidingImageLib;` as an Application dependency, not ownership transfer.

No direct executed B-report already covers the whole [UID:0000N6] empty-emitter family.

## Family Disposition Table

| UID | Current page | Current state | Recommended callback disposition |
| --- | --- | --- | --- |
| 0000N6 | `by-file/RidingImageLib.md` | `87/88`, file root | Raise to `90/90`; preserve `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`; add family source-quality summary and stale-zero correction note. |
| 0000BZ | `by-class/RidingImageLib.md` | `85/86`, empty class emitter | Raise to `89/90`; insert class shell with `[[CHILDREN]]`, member fields, `LoadRidingDefinitions`, destructor, and support declarations. |
| 0002LA | parser | `85/90`, empty method emitter | Raise to `89/91`; insert first-draft `LoadRidingDefinitions` C++ using accepted shared helper names and exact `RIDINGS.DNA` read/allocation behavior. |
| 00017F | early method cluster | `86/91`, empty aggregate emitter | Reclassify to `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++; document as split/container only. Exact child pages carry source. |
| 0002Y0 | constructor | `85/89`, empty method emitter | Raise to `88/91`; insert first-draft constructor C++ for singleton publish, parser call, and `RIDINGS.EPF` load. |
| 0002Y1 | raw draw helper | `86/90`, empty raw-helper emitter | Rare no-improvement exception: keep behavior docs, blank `EMITTER_UIDS`, leave formal C++ empty. Do not invent a callable signature while MCP shows no function object and no direct refs. |
| 0002Y4 | scalar deleting destructor | `85/90`, empty compiler wrapper emitter | Keep class owner; insert proof comment that source is covered by `RidingImageLib::~RidingImageLib()` and compiler delete wrapper. |
| 0001VV | `RidingDefinition` | `85/88`, empty type emitter | Raise to `88/90`; insert POD/alias declarations using accepted `ImageAnimationGroup` and `ImageAnimationFrame` helper types. |
| 0001VW | `RidingImageLibLayout` | `85/90`, empty layout emitter | Raise to `86/91`; insert covered-by proof comment pointing to the class shell and field-offset evidence. |
| 0001YM | vtable | `85/90`, empty vtable emitter | Raise to `86/91`; insert proof comment that vtable is compiler-generated from the class virtual declarations. |
| 00031E | vtable data | `88/91`, empty vtable-data emitter | Raise to `89/92`; insert proof comment with exact slot values and compiler-generated handling. |
| 0000TJ | riding definition global table | `87/88`, empty global emitter | Raise to `90/91`; insert `ImageAnimationTable g_ridingDefinitionGroups;` and note zero-fill/stale wording correction. |
| 0001PL | `0x0069b430-0x0069b43c` storage | `86/91`, empty data emitter | Raise to `88/92`; insert covered-by proof comment; correct stale `0xffffffff`/all-`0xff` wording to current zero/virtual-zero-fill. |
| 0000S4 | `g_pRidingImageLib` | `86/90`, empty global emitter | Raise to `90/91`; insert `RidingImageLib *g_pRidingImageLib = NULL;`; keep owner route through [UID:0000N6]. |
| 0001PO | `0x0069b444-0x0069b448` storage | `86/90`, empty data emitter | Raise to `88/91`; insert covered-by proof comment; correct stale initial `0xffffffff` wording to current null/zero-fill. |
| 000183 | singleton clear helper | `85/90`, empty cleanup helper emitter | Reclassify to `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++; document as compiler/static cleanup support covered by constructor/destructor/global lifecycle. |

## Exact Formal Text Proposals

These are exact insertion texts for the callback. The fenced blocks are neutral `text` blocks because the sentinel lines are not C++.

### [UID:0000BZ] Class Shell

Metadata changes:

- `COMPLETION:89`
- `CONFIDENCE:90`
- Keep `CANONICAL_OWNER:0000N6`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000N6`
- Keep blank optional position

Exact `RECONSTRUCTION_CPP CODE` block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ArchiveMetadataTable;
struct ImageAnimationTable;
struct ImageAnimationGroup;
struct ImageAnimationFrame;
struct RidingDefinition;

class RidingImageLib : public LObject
{
public:
    RidingImageLib();
    virtual ~RidingImageLib();

    void LoadRidingDefinitions();
    const RidingDefinition *GetDefinitionOrDefault(unsigned int ridingDefinitionIndex) const;

private:
    RidingDefinition *ridingDefinitions;
    unsigned int ridingDefinitionCount;
    ArchiveMetadataTable *ridingEpfPackage;
};

extern RidingImageLib *g_pRidingImageLib;
extern ImageAnimationTable g_ridingDefinitionGroups;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation note: `GetDefinitionOrDefault` is supported by MCP and B014, but there is no existing by-memory child page for `0x004dca20-0x004dca43`. If the callback elects to define it, use the supported split/UID workflow with TMP references; do not invent a permanent UID in this report.

### [UID:0001VV] RidingDefinition Layout

Metadata changes:

- `COMPLETION:88`
- `CONFIDENCE:90`
- Keep `CANONICAL_OWNER:0000BZ`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000BZ`
- Keep blank optional position

Exact `RECONSTRUCTION_CPP CODE` block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
typedef ImageAnimationGroup RidingBucket;
typedef ImageAnimationFrame RidingBucketEntry;

struct RidingDefinition
{
    unsigned int ridingId;
    unsigned char bucketCount;
    unsigned char defaultBucketIndex;
    unsigned short animationGroupId;
    RidingBucket *buckets;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: this keeps the riding-specific 12-byte definition record local to `RidingImageLib` while reusing the accepted shared 8-byte/10-byte animation table helper declarations from [UID:0001CM]. It rejects duplicate helper-class source under RidingImageLib.

### [UID:0002LA] LoadRidingDefinitions

Metadata changes:

- `COMPLETION:89`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000BZ`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000BZ`
- Keep blank optional position

Exact `RECONSTRUCTION_CPP CODE` block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void RidingImageLib::LoadRidingDefinitions()
{
    DatFile reader;

    reader.Open(L"RIDINGS.DNA");
    reader.Read(&ridingDefinitionCount, sizeof(ridingDefinitionCount));

    ridingDefinitions = AllocateRidingDefinitionArray(ridingDefinitionCount);

    g_ridingDefinitionGroups.AllocateGroups(0x15);
    for (unsigned int groupIndex = 0; groupIndex < 0x15; ++groupIndex) {
        ImageAnimationGroup *group = g_ridingDefinitionGroups.GetGroup(groupIndex);

        group->AllocateFrames(1);
        group->frames[0].frameOffset = 0;
        group->frames[0].frameDuration = 30000;
        group->frames[0].blendAlpha = 0;
    }

    for (unsigned int ridingIndex = 0; ridingIndex < ridingDefinitionCount; ++ridingIndex) {
        RidingDefinition *definition = ridingDefinitions + ridingIndex;

        reader.Read(&definition->ridingId, sizeof(definition->ridingId));
        reader.Read(&definition->bucketCount, sizeof(definition->bucketCount));
        reader.Read(&definition->defaultBucketIndex, sizeof(definition->defaultBucketIndex));
        reader.Read(&definition->animationGroupId, sizeof(definition->animationGroupId));

        definition->buckets = AllocateRidingBucketArray(definition->bucketCount);
        for (unsigned int bucketIndex = 0; bucketIndex < definition->bucketCount; ++bucketIndex) {
            ImageAnimationGroup *bucket = definition->buckets + bucketIndex;

            reader.Read(&bucket->frameCount, sizeof(bucket->frameCount));
            bucket->AllocateFrames(bucket->frameCount);

            for (unsigned int entryIndex = 0; entryIndex < bucket->frameCount; ++entryIndex) {
                ImageAnimationFrame *entry = bucket->frames + entryIndex;

                reader.Read(&entry->frameOffset, sizeof(entry->frameOffset));
                reader.Read(&entry->frameDuration, sizeof(entry->frameDuration));
                reader.Read(&entry->auxFrameId, sizeof(entry->auxFrameId));
                reader.Read(&entry->blendAlpha, sizeof(entry->blendAlpha));
                reader.Read(&entry->paletteIndex, sizeof(entry->paletteIndex));
                reader.Read(&entry->effectIndex, sizeof(entry->effectIndex));
            }
        }
    }

    reader.Close();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Name caveats to retain in prose:

- `DatFile`, `AllocateRidingDefinitionArray`, and `AllocateRidingBucketArray` are source-facing inferred names.
- `ImageAnimationTable`, `ImageAnimationGroup`, and `ImageAnimationFrame` are accepted shared helper names from [UID:0001CM].
- `blendAlpha`, `auxFrameId`, `paletteIndex`, and `effectIndex` are weaker field names than the parser offsets and sizes.

### [UID:0002Y0] Constructor

Metadata changes:

- `COMPLETION:88`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000BZ`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000BZ`
- Keep blank optional position

Exact `RECONSTRUCTION_CPP CODE` block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
RidingImageLib::RidingImageLib()
    : LObject(),
      ridingDefinitions(NULL),
      ridingDefinitionCount(0),
      ridingEpfPackage(NULL)
{
    g_pRidingImageLib = this;

    LoadRidingDefinitions();
    ridingEpfPackage = LoadImageFrameTable(L"RIDINGS.EPF", 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation note: retain prose that the `this == -4`/clear path in decompilation is cleanup projection around construction, not a source branch to model in first-draft C++.

### [UID:0002Y4] Scalar Deleting Destructor

Metadata changes:

- `COMPLETION:86`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000BZ`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000BZ`
- Keep blank optional position

Exact `RECONSTRUCTION_CPP CODE` block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated scalar deleting destructor for RidingImageLib.
// Source cleanup is emitted by RidingImageLib::~RidingImageLib(); the optional
// delete wrapper and vtable slot are compiler output and should not be hand-written.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0001VW] RidingImageLibLayout

Metadata changes:

- `COMPLETION:86`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000BZ`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000BZ`
- Keep blank optional position

Exact `RECONSTRUCTION_CPP CODE` block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// RidingImageLib object layout is emitted by the [UID:0000BZ] class shell:
// +0x04 ridingDefinitions, +0x08 ridingDefinitionCount, +0x0c ridingEpfPackage.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0001YM] Vtable

Metadata changes:

- `COMPLETION:86`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000BZ`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000BZ`
- Keep blank optional position

Exact `RECONSTRUCTION_CPP CODE` block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// RidingImageLib vtable data is compiler-generated from the class declaration
// and virtual destructor. Do not emit a hand-authored source vtable.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00031E] Vtable Data

Metadata changes:

- `COMPLETION:89`
- `CONFIDENCE:92`
- Keep `CANONICAL_OWNER:0001YM`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0001YM`
- Keep blank optional position

Exact `RECONSTRUCTION_CPP CODE` block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted RidingImageLib vtable storage at 0x0061b6f0-0x0061b700:
// RTTI locator 0x00648cb4, scalar deleting destructor 0x004e68b0,
// base cleanup 0x004f4b10, and nullsub_18 0x0041b6c0.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000TJ] RidingDefinitionGlobalTable

Metadata changes:

- `COMPLETION:90`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000N6`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000N6`
- Keep blank optional position

Exact `RECONSTRUCTION_CPP CODE` block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ImageAnimationTable g_ridingDefinitionGroups;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation note: update prose to say current MCP reads zeroed bytes at `0x0069b430-0x0069b43c`; older all-`0xff` or `0xffffffff` wording is stale and should be preserved only as rejected/historical context.

### [UID:0001PL] RidingDefinitionGlobalTable Storage

Metadata changes:

- `COMPLETION:88`
- `CONFIDENCE:92`
- Keep `CANONICAL_OWNER:0000TJ`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000TJ`
- Keep blank optional position

Exact `RECONSTRUCTION_CPP CODE` block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Storage for g_ridingDefinitionGroups is emitted by [UID:0000TJ].
// Current MCP reads this 12-byte object as virtual-zero-filled .data, not 0xffffffff.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000S4] g_pRidingImageLib

Metadata changes:

- `COMPLETION:90`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000N6`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000N6`
- Keep blank optional position

Exact `RECONSTRUCTION_CPP CODE` block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
RidingImageLib *g_pRidingImageLib = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0001PO] g_pRidingImageLib Storage

Metadata changes:

- `COMPLETION:88`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000S4`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000S4`
- Keep blank optional position

Exact `RECONSTRUCTION_CPP CODE` block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Storage for g_pRidingImageLib is emitted by [UID:0000S4].
// Current MCP reads 0x0069b444 as NULL/zero-filled .data at program image load.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Non-Emitting Repair Plans

### [UID:00017F] Early Method Cluster

Recommended metadata:

- `COMPLETION:87`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000BZ`
- Set `RECONSTRUCTABLE:FALSE`
- Set `EMITTER_UIDS:` blank
- Keep blank optional position
- Formal C++ block remains empty.

Reason: [UID:00017F] is a broad aggregate from `0x004dc420-0x004dca14`, not a source body. Its child source is carried by the exact parser, constructor, ordinary destructor, raw-helper proof, and related split pages. Emitting `[[CHILDREN]]` from this aggregate would duplicate the class shell route and is less precise than exact child ownership.

### [UID:0002Y1] DrawRidingFrameRawHelper

Recommended metadata:

- Keep `COMPLETION:86`
- Keep `CONFIDENCE:90`
- Keep `CANONICAL_OWNER:0000BZ`
- Keep `RECONSTRUCTABLE:TRUE`
- Set `EMITTER_UIDS:` blank
- Keep blank optional position
- Formal C++ block remains empty.

Rare no-improvement proof:

- Current MCP still reports no function at `0x004dc7e0` or `0x004dca14`.
- Current MCP `xrefs_to 0x004dc7e0` returns no direct code/data refs.
- The body is real decoded code, not padding: prior/current evidence shows stack cookie, `retn 0x14`, `this+0x04/+0x08` definition-vector reads, `0x8000 + inputWord` indexing, `0x00528b10` bucket lookup, `RIDINGS.EPF` frame lookup through `0x004d02f0`, rectangle offsets, and `dword_69B3F0` dispatch.
- The missing facts are source ABI facts, not merely names: no caller confirms the five stack arguments or a source call route. A formal member signature would invent parameter semantics and create a generated callable body with no proven source placement.
- Keep the detailed behavior notes on the page and explicitly state this is a non-emitting raw orphan until a caller/ABI route is recovered.

Rejected alternatives:

- Emit first-draft `DrawRidingFrame(...)`: rejected because every candidate signature depends on unproven argument roles from an unreferenced raw span.
- Mark as padding/data: rejected because raw disassembly shows a full stack-cookie-protected executable body.
- Merge into destructor or `0x004dca20`: rejected by `0xcc` boundaries and distinct behavior.

### [UID:000183] Singleton Clear Helper

Recommended metadata:

- Keep `COMPLETION:85`
- Set `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000N6`
- Set `RECONSTRUCTABLE:FALSE`
- Set `EMITTER_UIDS:` blank
- Keep blank optional position
- Formal C++ block remains empty.

Reason: `0x004e5bf0-0x004e5bfb` is cleanup-support code that only writes `g_pRidingImageLib = 0` and returns. Source-visible lifetime is already represented by the constructor, ordinary destructor, scalar wrapper proof, and singleton global. It has only the constructor cleanup/support xref and no independent source declaration.

## Optional Split Plan For 0x004dca20

`0x004dca20-0x004dca43` is not one of the 15 empty markers in this assignment, but it is a real `RidingImageLib` helper used by accepted NewHuman docs as `RidingImageLib::GetDefinitionOrDefault`.

Implementation-ready plan if supervisor allows support split during callback:

- Create a new by-memory child with the supported by-structure UID workflow, using a TMP reference until the validator assigns a permanent UID.
- Range: `0x004dca20-0x004dca43`.
- Source-facing name: `RidingImageLibGetDefinitionOrDefault` / method `RidingImageLib::GetDefinitionOrDefault`.
- Owner: [UID:0000BZ] `RidingImageLib`.
- Emitter route: [UID:0000BZ].
- Formal C++:

```text
const RidingDefinition *RidingImageLib::GetDefinitionOrDefault(unsigned int ridingDefinitionIndex) const
{
    if (ridingDefinitionIndex < ridingDefinitionCount)
        return ridingDefinitions + ridingDefinitionIndex;

    return reinterpret_cast<const RidingDefinition *>(&g_ridingDefinitionGroups);
}
```

Caveat: the return fallback is a 12-byte `ImageAnimationTable` object treated through the same shape as `RidingDefinition`. Keep the reinterpretation documented as a decompiler/source-model compromise unless a stronger source declaration is recovered.

If the split workflow cannot be completed safely during callback, do not invent a permanent UID. Leave the declaration in the class shell and record the split as deferred.

## Content Updates Required In Prose

During callback, update target/support prose at report-level detail:

- Preserve exact ranges:
  - parser `0x004dc420-0x004dc68d`
  - constructor `0x004dc690-0x004dc722`
  - ordinary destructor `0x004dc730-0x004dc7d8`
  - raw helper `0x004dc7e0-0x004dca14`
  - lookup helper support `0x004dca20-0x004dca43`
  - singleton clear helper `0x004e5bf0-0x004e5bfb`
  - scalar deleting destructor `0x004e68b0-0x004e6981`
  - table storage `0x0069b430-0x0069b43c`
  - singleton storage `0x0069b444-0x0069b448`
- Preserve constructor-only parser caller proof: `xrefs_to 0x004dc420` has only `0x004dc6f5` inside `sub_4DC690`.
- Preserve `.RIDINGS` resource proof with exact suffixes: parser opens `RIDINGS.DNA`; constructor loads `RIDINGS.EPF` through `0x004d0f50`.
- Preserve descriptor/count/allocation behavior:
  - `RidingDefinition` records are 12 bytes.
  - `ImageAnimationGroup`/bucket rows are 8 bytes.
  - `ImageAnimationFrame`/entry rows are 10 bytes.
  - parser reads definition fields at `+0x00`, `+0x04`, `+0x05`, and `+0x06`.
  - parser reads entry fields in order `+0x00`, `+0x02`, `+0x06`, `+0x04`, `+0x08`, `+0x09`.
  - global default table creates `0x15` groups and one default frame per group with offset `0`, duration `30000`, and flag/alpha byte `0`.
- Correct stale all-`0xff`/`0xffffffff` language for `0x0069b430` and `0x0069b444`: current MCP reads zeroes and B007 resolved adjacent storage as virtual-zero-fill.
- Preserve name caveats:
  - `ImageAnimationTable`, `ImageAnimationGroup`, and `ImageAnimationFrame` are accepted inferred helper names.
  - `DatFile`, `AllocateRidingDefinitionArray`, `AllocateRidingBucketArray`, and weak frame-entry tail names remain inferred.
  - Do not turn address-derived helper names into final source names.
- Preserve rejected alternatives:
  - Do not move shared table helpers under RidingImageLib.
  - Do not move RidingImageLib globals to Application or consumer render pages.
  - Do not emit raw vtable data as hand-written source.
  - Do not invent a raw draw helper signature while no caller/ABI route exists.

## Claim And Incorporation Ledger

| Claim ID | Claim | Evidence / Confidence | Incorporation target | Action | Verification state |
| --- | --- | --- | --- | --- | --- |
| C001 | IDA MCP was available and current evidence is MCP-backed. | High: active `supervisor_resume_20260629`, `server_health ok`, current lookup/xref/decompile/data reads retained in the evidence section. | Report evidence section. | incorporated | already-present: accepted report evidence retained unchanged for supervisor review. |
| C002 | [UID:0000N6] remains the source root for `NexusTK/render/RidingImageLib.cpp`. | High: by-file header/prose now records root ownership; generated output header names `Source by-file UID: 0000N6`. | `by-file/RidingImageLib.md`. | incorporated | applied: by-file score is `90/90`; validator `000000003109` exit `0`, ok `1`. |
| C003 | Current generated file has one filled destructor and 15 empty markers. | High: accepted-report baseline preserved; callback generated refresh now has zero empty markers. | File status/prose; implementation checklist. | incorporated | applied: baseline documented; current generated header is command `000000003133` and marker count `0`. |
| C004 | [UID:0000BZ] should emit a class shell with `[[CHILDREN]]`. | High: class page formal block now has support declarations, fields, methods, globals, and `[[CHILDREN]]`. | `by-class/RidingImageLib.md`. | incorporated | applied: class score is `89/90`; validator `000000003111` exit `0`, ok `1`. |
| C005 | Parser [UID:0002LA] should emit first-draft `LoadRidingDefinitions`. | High: parser page formal block now preserves exact range, constructor-only xref, `RIDINGS.DNA`, allocation/read behavior, and helper-name caveats. | Parser target formal C++ and prose. | incorporated | applied: parser score is `89/91`; validator `000000003113` exit `0`, ok `1`. |
| C006 | Constructor [UID:0002Y0] should emit first-draft constructor C++. | High: constructor page formal block now publishes singleton, calls parser, loads `RIDINGS.EPF`, and documents cleanup projection caveat. | Constructor target formal C++ and prose. | incorporated | applied: constructor score is `88/91`; validator `000000003117` exit `0`, ok `1`. |
| C007 | Ordinary destructor [UID:00017G] is already the filled source cleanup body. | High: B003 accepted report and generated `RidingImageLib.cpp` continue to include the destructor body. | Support prose only; no target formal change. | no-op | already-present: no by-memory destructor edit was needed; generated file still contains [UID:00017G]. |
| C008 | Raw helper [UID:0002Y1] is a rare non-emitting source-authored raw orphan. | High for real body and owner; high for no current function/xrefs; page now records no-code proof and blanks emitter route. | Raw helper metadata/prose; blank emitter route. | incorporated | applied: raw helper keeps `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`; validator `000000003119` exit `0`, ok `1`. |
| C009 | Scalar deleting destructor [UID:0002Y4] should emit only compiler-wrapper proof comment. | High: scalar wrapper page now has exact compiler-wrapper proof comment and class/ordinary destructor route. | Scalar wrapper formal block/prose. | incorporated | applied: scalar wrapper score is `86/91`; validator `000000003120` exit `0`, ok `1`. |
| C010 | `RidingDefinition` should emit POD/alias declarations tied to accepted shared helper types. | High: type page now emits `RidingBucket`, `RidingBucketEntry`, and 12-byte `RidingDefinition` fields. | `by-type/by-struct/RidingDefinition.md`. | incorporated | applied: type score is `88/90`; validator `000000003122` exit `0`, ok `1`. |
| C011 | `RidingImageLibLayout` should not duplicate the class shell, only proof-comment the layout. | High: layout page now proof-comments class-shell coverage and field offsets. | `by-type/by-struct/RidingImageLibLayout.md`. | incorporated | applied: layout score is `86/91`; validator `000000003123` exit `0`, ok `1`. |
| C012 | Vtable page [UID:0001YM] should emit proof comment, not source vtable data. | High: vtable page now proof-comments compiler generation from class virtual declarations. | `by-type/by-vtable/RidingImageLibVtable.md`. | incorporated | applied: vtable score is `86/91`; validator `000000003124` exit `0`, ok `1`. |
| C013 | Vtable storage [UID:00031E] should emit exact compiler-data proof comment. | High: vtable-data page now lists `0x00648cb4`, `0x004e68b0`, `0x004f4b10`, `0x0041b6c0`. | Vtable-data memory page. | incorporated | applied: vtable-data score is `89/92`; validator `000000003125` exit `0`, ok `1`. |
| C014 | Riding-definition global table should emit `ImageAnimationTable g_ridingDefinitionGroups;`. | High: global page now emits the accepted shared helper type and zero-fill/stale-wording prose. | `by-global/RidingDefinitionGlobalTable.md`. | incorporated | applied: global table score is `90/91`; validator `000000003126` exit `0`, ok `1`. |
| C015 | `0x0069b430` child storage should correct stale all-ff wording to current zero-fill. | High: memory child now records current zero-filled bytes and rejects stale all-`0xff` language. | `by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md`. | incorporated | applied: storage score is `88/92`; validator `000000003127` exit `0`, ok `1`. |
| C016 | Singleton global should emit `RidingImageLib *g_pRidingImageLib = NULL;`. | High: singleton global page now emits the global definition and lifecycle prose. | `by-global/g_pRidingImageLib.md`. | incorporated | applied: singleton global score is `90/91`; validator `000000003128` exit `0`, ok `1`. |
| C017 | `0x0069b444` child storage should correct stale `0xffffffff` wording to current null/zero-fill. | High: memory child now records NULL/zero-fill storage and rejects stale sentinel wording. | `by-memory/0x0069b444-0x0069b448.g_pRidingImageLib.md`. | incorporated | applied: singleton storage score is `88/91`; validator `000000003129` exit `0`, ok `1`. |
| C018 | Singleton clear helper [UID:000183] is cleanup support and should not emit. | High: helper page now marks `RECONSTRUCTABLE:FALSE`, blanks `EMITTER_UIDS`, and documents cleanup-support ownership. | Clear-helper memory page. | incorporated | applied: helper confidence is `91`; validator `000000003121` exit `0`, ok `1`. |
| C019 | Early method cluster [UID:00017F] is a container/split page and should not emit. | High: cluster page now marks `RECONSTRUCTABLE:FALSE`, blanks `EMITTER_UIDS`, and documents split/container disposition. | Early cluster memory page. | incorporated | applied: cluster score is `87/91`; validator `000000003115` exit `0`, ok `1`. |
| C020 | Shared helper implementation remains owned by MonsterImageLibTables, not RidingImageLib. | High: B007 accepted helper names are referenced without moving helper implementation into Riding docs. | Target/support prose. | incorporated | applied: by-file/class/parser/type prose preserves shared-helper ownership and rejected alternative. |
| C021 | `0x004dca20` helper name/source-placement blocker is resolved as an optional split plan. | Medium-high: current decompile and B014 accepted use; supervisor explicitly disallowed creating optional split in this callback. | Optional callback split plan. | excluded from implementation | excluded-with-reason: no `0x004dca20-0x004dca43` page was created; class declaration and deferred support plan are preserved. |
| C022 | Root score can rise to `90/90` after callback. | Medium-high: generated markers became source, proof comments, or explicit non-emitting exceptions. | `by-file/RidingImageLib.md`. | incorporated | applied: by-file header is `COMPLETION:90`, `CONFIDENCE:90`; validator `000000003109` exit `0`, ok `1`. |
| C023 | The accepted research baseline is preserved, and callback edits are separately recorded. | High: callback section distinguishes accepted implementation edits from the original research pass. | Report integrity. | no-op | already-present: baseline evidence retained; callback records no manual generated/coverage/tool-state/ledger edits. |
| C024 | Callback must validate every changed by-* file and refresh generated output for target/class/file routes where applicable. | High: 16 scoped validator runs with `--wait-generated`; current generated RidingImageLib header is validator command `000000003133` after a later validator-owned refresh. | Implementation checklist/checkpoint. | incorporated | applied: Agent-B008 scoped validators `000000003109` through `000000003129` listed above; all exit `0`, ok `1`, warnings `0`; current generated marker count is `0`. |

## Implementation Tracking Checklist

Callback checklist status:

- [x] Re-read current target/support docs immediately before editing. Proof: all 16 listed by-* files were read and patched against current file state; no unrelated support docs were overwritten.
- [x] Check active leases before each file edit; take only short immediate leases and release them after the edit/validator batch. Proof: no conflicting Riding leases were present; all final validator groups were leased/released, and final `current_leases.md` has no `Agent-B008` rows.
- [x] Update [UID:0000N6] `by-file/RidingImageLib.md` score to `90/90`, preserve path, add family source-quality summary, generated marker disposition, current MCP evidence, and stale zero-fill correction. Proof: validator `000000003109`, exit `0`, ok `1`.
- [x] Update [UID:0000BZ] `by-class/RidingImageLib.md` metadata to `89/90`, insert the exact class shell with `[[CHILDREN]]`, preserve field offsets and ownership proof. Proof: validator `000000003111`, exit `0`, ok `1`.
- [x] Update [UID:0001VV] `by-type/by-struct/RidingDefinition.md` metadata to `88/90`, insert exact alias/POD formal block, and synchronize field caveats with B007 helper names. Proof: validator `000000003122`, exit `0`, ok `1`.
- [x] Update [UID:0002LA] parser metadata to `89/91`, insert exact `LoadRidingDefinitions` formal block, and preserve constructor-only caller/resource/allocation/read-order proof. Proof: validator `000000003113`, exit `0`, ok `1`.
- [x] Update [UID:0002Y0] constructor metadata to `88/91`, insert exact constructor formal block, and document cleanup-projection caveat. Proof: validator `000000003117`, exit `0`, ok `1`.
- [x] Update [UID:0002Y4] scalar deleting destructor metadata to `86/91` and insert exact compiler-wrapper proof comment. Proof: validator `000000003120`, exit `0`, ok `1`.
- [x] Update [UID:0001VW] layout metadata to `86/91` and insert exact covered-by proof comment. Proof: validator `000000003123`, exit `0`, ok `1`.
- [x] Update [UID:0001YM] vtable metadata to `86/91` and insert exact compiler-vtable proof comment. Proof: validator `000000003124`, exit `0`, ok `1`.
- [x] Update [UID:00031E] vtable-data metadata to `89/92` and insert exact slot-value proof comment. Proof: validator `000000003125`, exit `0`, ok `1`.
- [x] Update [UID:0000TJ] global-table metadata to `90/91`, insert exact `ImageAnimationTable g_ridingDefinitionGroups;`, and correct stale byte-state wording. Proof: validator `000000003126`, exit `0`, ok `1`.
- [x] Update [UID:0001PL] global-table storage metadata to `88/92`, insert exact covered-by proof comment, and correct stale `0xffffffff` wording. Proof: validator `000000003127`, exit `0`, ok `1`.
- [x] Update [UID:0000S4] singleton metadata to `90/91` and insert exact `RidingImageLib *g_pRidingImageLib = NULL;`. Proof: validator `000000003128`, exit `0`, ok `1`.
- [x] Update [UID:0001PO] singleton storage metadata to `88/91`, insert exact covered-by proof comment, and correct stale `0xffffffff` wording. Proof: validator `000000003129`, exit `0`, ok `1`.
- [x] Update [UID:00017F] early cluster metadata to `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, and split/container prose. Proof: validator `000000003115`, exit `0`, ok `1`.
- [x] Update [UID:0002Y1] raw helper metadata to blank `EMITTER_UIDS`, preserve `RECONSTRUCTABLE:TRUE`, blank formal C++, and add rare no-improvement no-code proof. Proof: validator `000000003119`, exit `0`, ok `1`.
- [x] Update [UID:000183] singleton clear helper metadata to `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, and cleanup-support proof. Proof: validator `000000003121`, exit `0`, ok `1`.
- [x] If supervisor allows the support split, create `0x004dca20-0x004dca43` `GetDefinitionOrDefault` via supported UID/TMP workflow; otherwise record it as deferred without inventing a permanent UID. Proof: supervisor override said not to create the optional split; no new page/UID was created, and the deferred plan remains in this report/class prose.
- [x] Run scoped validators from `E:/NTK/GhidraBridge/source-3/project-documentation` for every changed by-* file. Proof: 16 validator rows listed in `Implementation Callback Results`.
- [x] Use `--wait-generated` for target/class/file validators where `auto-generated/NexusTK/render/RidingImageLib.cpp` freshness matters. Proof: every listed validator command used `--apply --wait-generated --queue-timeout 240`.
- [x] Record validator command IDs, timestamps, exit codes, ok counts, warnings, generated freshness, changed files, and lease release status in the report callback section/checkpoint. Proof: see `Implementation Callback Results`.
- [x] Confirm no generated C++, generated reports, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, queue files, or lock files were manually edited. Proof: only by-* docs and this report were manually patched; generated refresh was validator-owned.

## Callback Coordination Notes

This family touches shared NewHuman/Monster/Riding support concepts:

- B007 owns the accepted shared `ImageAnimationTable` helper terminology in MonsterImageLibTables.
- B014/B009/B010/B011 style NewHuman reports may reference `RidingImageLib::GetDefinitionOrDefault` and riding layout names from composition consumers.
- During implementation, re-read every shared support doc immediately before editing, respect active leases, and do not overwrite newer accepted support edits. If a support file is leased, wait for expiration and recheck, or mark that support edit deferred/blocked with exact lease details.
- Support edits are secondary. The primary target remains [UID:0000N6] and its listed empty-emitter family.

## Rejected Alternatives

- Move shared `ImageAnimationTable` helpers into RidingImageLib: rejected because B007 and current MCP show both Monster and Riding parsers consume the helper island.
- Leave parser/constructor/type/global pages marker-only because helper names are inferred: rejected because score-blocker rules treat name/type blockers as in-scope, and accepted helper names are already available.
- Emit hand-written vtable arrays or scalar deleting destructor bodies: rejected because the source route is the class declaration plus ordinary destructor; these are compiler artifacts.
- Treat `0x0069b430` or `0x0069b444` as initialized `0xffffffff`: rejected by current MCP zero bytes and B007 virtual-zero-fill evidence.
- Merge `0x004dc7e0` raw helper into the destructor or `0x004dca20`: rejected by alignment gaps and distinct behavior.
- Invent a first-draft raw draw helper signature: rejected by current MCP no-function/no-xref state and no caller-confirmed ABI.

## Implementation Callback Integrity

Manual edits were limited to the 16 scoped by-* docs listed in `Implementation Callback Results` and this Agent-B008 report. I did not manually edit generated C++ files, generated reports, manual coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, queue files, or lock files.

Validator-owned generated freshness:

- `auto-generated/NexusTK/render/RidingImageLib.cpp`
- Current generated header `validator-command-id: 000000003133`
- Current generated header `validator-refreshed-at: 2026-06-30T15:40:39-04:00`
- Last Agent-B008 scoped by-* validator command touching this generated file: `000000003129` at `2026-06-30T15:37:16-04:00`
- `Empty Emitter Marker`/`MARKER-ONLY`/`B008 Empty` marker count: `0`

Lease status: all Agent-B008 RidingImageLib leases were released after the validator groups. Final `current_leases.md` check showed no active `Agent-B008` rows.

Deferred item: no optional `0x004dca20-0x004dca43` split was created during this callback per supervisor override. The source-placement/name plan remains documented for a future support split if authorized.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000N6-RidingImageLib-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0000N6-RidingImageLib-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T15:45:24","uid":"0000N6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
