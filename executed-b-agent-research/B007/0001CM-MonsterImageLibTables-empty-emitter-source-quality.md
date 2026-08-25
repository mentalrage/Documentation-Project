** TARGET-REPORT-UID:0001CM **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0001CM MonsterImageLibTables Empty-Emitter Source-Quality Report

## Finalized Report / Current Recommendation

- Current status: report accepted by supervisor and implementation callback completed on 2026-06-29.
- Applied disposition: converted [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](../../../by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) from an empty emitter marker into source-ready shared animation-table helper code in [UID:0000LK][MonsterImageLibTables](../../../by-file/MonsterImageLibTables.md).
- Applied metadata/source: kept `CANONICAL_OWNER:0000LK`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000LK`; did not split, rename, or move the helper island; raised target score to `90/90`; inserted the formal C++ block from this report.
- Callback proof: updated the target, [UID:0000LK][MonsterImageLibTables](../../../by-file/MonsterImageLibTables.md), [UID:00008O][MonsterImageLibTable_5289D0](../../../by-class/MonsterImageLibTable_5289D0.md), and [UID:00008P][MonsterImageLibTable_528BE0](../../../by-class/MonsterImageLibTable_528BE0.md); ran scoped validators `000000000776` through `000000000779`; generated `auto-generated/NexusTK/render/MonsterImageLibTables.cpp` now emits UID0001CM helper source instead of a UID0001CM Empty Emitter Marker.
- Report-correction disposition for C010: the `0x0069b424-0x0069b43c` byte-state mismatch is explicitly excluded from the UID0001CM implementation. Current MCP saw zeroed storage, and raw PE mapping shows both addresses are `.data` virtual zero-fill, outside UID0001CM and outside its helper C++/score/source-placement decision.
- Confidence: high for range, helper inventory, owner/emitter route, vector constructor/destructor behavior, parser callers, lookup fallback behavior, and padding. Confidence remains capped below final-audit range because exact original helper type names and public/private declaration placement are inferred.

## Target

- Target UID: `0001CM`
- Target path: `by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md`
- Assignment ID: `B007-implement-0001CM-MonsterImageLibTables-empty-emitter-20260629`
- Original queue reason: `auto-generated/NexusTK/render/MonsterImageLibTables.cpp` showed UID0001CM as an `Empty Emitter Marker`.
- Pre-callback metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000LK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LK`, blank formal C++.
- Post-callback metadata: `COMPLETION:90`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000LK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LK`, formal helper C++ present.
- Generated state checked read-only after callback: `auto-generated/NexusTK/render/MonsterImageLibTables.cpp` header `validator-command-id: 000000000779`, refreshed `2026-06-29T13:19:52-04:00`, emits UID0001CM helper source. The alias pages UID00008O/UID00008P and data page UID00027U still show Empty Emitter Markers as separate scoped items.

## Current Target State

The target contains the right range and owner route. It documents thirteen helper bodies in the half-open range `0x00528930-0x00528d51`, the shared monster/riding parser caller family, the accepted neutral `ImageAnimationGroup` and `ImageAnimationFrame` layout roles, and the fallback record at `0x0066deb0`. The previous stale declaration-pass blocker is now superseded by the callback implementation: UID0001CM emits the formal `ImageAnimationTable`, `ImageAnimationGroup`, and `ImageAnimationFrame` helper C++.

The implementation should not absorb the adjacent/default data pages into this target. [UID:00027U][MonsterImageLibDefaultFrameRecord](../../../by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md), [UID:00029K][ImageLibraryFallbackRecord](../../../by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md), and [UID:0001PL][RidingDefinitionGlobalTable](../../../by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md) remain separate data-storage pages.

## Evidence Checked

- Skill and workflow: `ntk-b-agent-workflow`, `b-agent-research-and-implementation-workflow.md`, `by-structure.md` IDA MCP output discipline, and `mcp-incident-playbook.md` for availability handling.
- MCP availability: direct JSON-RPC initialize succeeded; `idb_list` showed active session `b2ae72ec`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `16112`, active worker backend; `server_health` returned `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, imagebase `0x400000`.
- MCP calls: `tools/list`, `lookup_funcs`, `xrefs_to`, `decompile`, `disasm`, `get_bytes`, `get_int`, and `entity_query`, all using database/session id `b2ae72ec`.
- Target/support docs checked: UID0001CM target; `by-file/MonsterImageLibTables.md`; `by-file/MonsterImageLib.md`; `by-file/RidingImageLib.md`; `by-class/MonsterImageLibTable_5289D0.md`; `by-class/MonsterImageLibTable_528BE0.md`; `by-type/by-struct/MonsterImageEntry.md`; `by-type/by-struct/RidingDefinition.md`; `by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md`; `by-memory/0x004dc420-0x004dc68d.RidingImageLibLoadRidingDefinitions.md`; `by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md`; `by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md`; `by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md`.
- Generated/tracker docs checked read-only: `auto-generated/NexusTK/render/MonsterImageLibTables.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, and `project-level/-auto-completion-stats.md`.
- Old report search terms: `0001CM`, `00528930`, `00528d51`, `MonsterImageLibTables`, `MonsterImageLibTable`, `ImageAnimationGroup`, `ImageAnimationFrame`, and `MonsterImageLibDefaultFrameRecord` across `executed-b-agent-research` and `tools/leaser/Agents`. Relevant executed B report found: B002 `00027U-MonsterImageLibDefaultFrameRecord-advanced-scan.md` references UID0001CM as support. No executed B report directly covers UID0001CM.
- Numeric conversions: `tools/int_convert.py` verified `0x421` = 1057, `0x17` = 23, `0x76` = 118, `0x9e` = 158, `0x18` = 24, `0x34` = 52, `0x0f` = 15, `0x79` = 121, `0x9c` = 156, `0x28` = 40, `0x16` = 22, `0x0a` = 10, `0x08` = 8, `0x0c` = 12, `0x15` = 21, `0xa8` = 168, and `0x7530` = 30000.
- Report-correction C010 evidence: current MCP `get_bytes`/`get_int` on `0x0069b424-0x0069b43c` returned zeroed dwords. A raw PE mapping check against `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` maps VA `0x0069b424` to RVA `0x0029b424`, `.data`, raw offset `0x00299024`, virtual-zero-fill, and VA `0x0069b430` to RVA `0x0029b430`, `.data`, raw offset `0x00299030`, virtual-zero-fill. Final disposition: this is adjacent loader-zeroed data storage, not a UID0001CM helper blocker; no UID0001CM callback support-doc edit is required for C010.

## Positive Evidence Summary

- Current `lookup_funcs` confirms the target is a coherent helper island beginning at `0x00528930`, ending before successor function `0x00528d60`, with only local `0xcc` alignment/padding between modeled helper bodies.
- Current `xrefs_to` confirms the two source consumers: `MonsterImageLib::LoadMonsterTables` and `RidingImageLib::LoadRidingDefinitions` both call the allocation helpers `0x005289d0` and `0x00528be0`.
- The same xref pass confirms constructor/destructor callback wiring: `0x005289d0` references `0x00528b50` and `0x00528b60`; `0x00528be0` references `0x00528d30` and `0x00528d50`; cleanup helpers reference `0x00528b60` and `0x00528d50`.
- Current decompilation shows source-level container methods: zero constructors, `new[]`-style vector allocation, `delete[]`-style cleanup, bounds-checked frame lookup, default-frame fallback, and POD frame initialization.
- Accepted B001 source uses `ImageAnimationGroup`, `ImageAnimationFrame`, `AllocateGroups`, and `AllocateFrames`, proving the project already has source-facing names strong enough for method-level C++.
- Generated coverage already routes UID0001CM as `emits` through owner/emitter `0000LK` into `auto-generated/NexusTK/render/MonsterImageLibTables.cpp`; the empty marker is a stale C++ block problem, not an owner/emitter problem.

## Negative Evidence Summary

- No evidence supports moving UID0001CM to `MonsterImageLib` or `RidingImageLib`; both files are consumers of the shared helper island.
- No evidence supports splitting the helper island; internal gaps are local alignment/padding between adjacent helper bodies.
- No xrefs support source-authored public methods for `0x00528a70` or `0x00528c80`; both are duplicate cleanup/unwind clones.
- No evidence supports defining `0x0066deb0` inside UID0001CM; the fallback frame is a separate exact data page outside this range.
- No recovered IDA names contain `MonsterImageLibTable`; current class names are address-derived documentation aliases.
- No target-specific evidence makes the generated empty marker intentional; UID0001CM satisfies the source-entry gate.

## IDA MCP Facts

### Function And Range Facts

| Range | MCP fact from `b2ae72ec` | Source interpretation |
| --- | --- | --- |
| `0x00528930-0x00528947` | `lookup_funcs` -> `sub_528930`, size `0x17` / 23 bytes (Verified with int_convert.py); decompile zeroes three dwords. | `ImageAnimationTable` constructor / initializer for the 12-byte outer table shape. |
| `0x00528950-0x005289c6` | `sub_528950`, size `0x76` / 118 bytes (Verified with int_convert.py); destroys `8`-byte group vector through `0x00528b60`, frees allocation, clears count byte and group pointer. | `ImageAnimationTable` destructor / cleanup. |
| `0x005289d0-0x00528a6e` | `sub_5289D0`, size `0x9e` / 158 bytes (Verified with int_convert.py); allocates `8 * count + 4`, vector-constructs with `0x00528b50`/`0x00528b60`, stores pointer at `+0x08`, count low byte at `+0x04`. | `ImageAnimationTable::AllocateGroups(unsigned int)`. |
| `0x00528a70-0x00528ae6` | `sub_528A70`, size `0x76` / 118 bytes (Verified with int_convert.py); no xrefs; same cleanup shape as `0x00528950`. | Compiler EH/unwind cleanup clone, not a hand-authored separate method. |
| `0x00528af0-0x00528b08` | `sub_528AF0`, size `0x18` / 24 bytes (Verified with int_convert.py); returns `groups + groupIndex * 8` when in range, otherwise returns base `groups`. | `ImageAnimationTable::GetGroup`. |
| `0x00528b10-0x00528b44` | `sub_528B10`, size `0x34` / 52 bytes (Verified with int_convert.py); chooses a group if in range and returns frame pointer or `0x0066deb0`. | `ImageAnimationTable::GetFrame`. |
| `0x00528b50-0x00528b5f` | `sub_528B50`, size `0x0f` / 15 bytes (Verified with int_convert.py); zeroes frame pointer and frame count. | `ImageAnimationGroup` constructor. |
| `0x00528b60-0x00528bd9` | `sub_528B60`, size `0x79` / 121 bytes (Verified with int_convert.py); destroys `0x0a` / 10-byte frame records with no-op destructor callback and frees vector. | `ImageAnimationGroup` destructor / cleanup. |
| `0x00528be0-0x00528c7c` | `sub_528BE0`, size `0x9c` / 156 bytes (Verified with int_convert.py); allocates `10 * count + 4`, vector-constructs with `0x00528d30` and no-op destructor, stores pointer/count. | `ImageAnimationGroup::AllocateFrames(unsigned int)`. |
| `0x00528c80-0x00528cf9` | `sub_528C80`, size `0x79` / 121 bytes (Verified with int_convert.py); no xrefs; same cleanup shape as `0x00528b60`. | Compiler EH/unwind cleanup clone, not a hand-authored separate method. |
| `0x00528d00-0x00528d28` | `sub_528D00`, size `0x28` / 40 bytes (Verified with int_convert.py); returns `frames + 10 * index` when in range, else `0x0066deb0`. | `ImageAnimationGroup::GetFrame`. |
| `0x00528d30-0x00528d46` | `sub_528D30`, size `0x16` / 22 bytes (Verified with int_convert.py); sets offset/duration dword zero, `blendAlpha = 0xff`, `auxFrameId = -1`, tail word zero. | `ImageAnimationFrame` constructor. |
| `0x00528d50-0x00528d51` | `nullsub_13`, size `0x01`; no-op. | POD frame destructor callback generated from trivial destructor. |
| `0x00528d60` | Successor function `sub_528D60`, size `0x1c`. | Confirms target exclusive end before successor; padding `0x00528d51-0x00528d60` stays outside source. |

### Xref Facts

| Address / item | Current xrefs | Meaning |
| --- | --- | --- |
| `0x00528930` | static wrappers `0x00419fb5`, `0x00419fd5`; constructor-callback data refs from `0x004dace4`, `0x004dc4b4`. | Same zero initializer serves concrete monster/riding default tables and vector-constructed outer records. |
| `0x00528950` | static cleanup wrappers `0x0060c285`, `0x0060c295`; destructor-callback refs from monster/riding parser/destructor/scalar cleanup. | Same cleanup helper is shared by static and vector-managed outer table records. |
| `0x005289d0` | four code calls: `0x004dad0f`, `0x004dadb5`, `0x004dc4df`, `0x004dc585`. | Monster and riding parsers both allocate the outer 8-byte group arrays. |
| `0x00528be0` | four code calls: `0x004dad2b`, `0x004dade4`, `0x004dc4fb`, `0x004dc5b4`. | Monster and riding parsers both allocate inner 10-byte frame arrays. |
| `0x00528af0` / `0x00528d00` | five render/image consumer calls each from `0x53a110`, `0x53a9f0`, `0x53b700`, `0x53b830`, and `0x5a3770` families. | Group/frame lookup helpers are active render/lookup helpers, not parser-only scaffolding. |
| `0x00528b10` | twelve code calls spanning monster and riding render/lookup consumers. | Outer table frame lookup is source-visible behavior. |
| `0x0066deb0` | exactly two refs from `0x00528b2f` and `0x00528d11`. | Shared default frame record returned by both lookup helpers; target should reference it, not define its storage. |

### Padding And Boundary Facts

Current `get_bytes` shows local padding/alignment bytes between helper bodies: `0x00528947-0x00528950`, `0x005289c6-0x005289d0`, `0x00528ae6-0x00528af0`, `0x00528b5f-0x00528b60`, `0x00528bd9-0x00528be0`, `0x00528cf9-0x00528d00`, `0x00528d46-0x00528d50`, and `0x00528d51-0x00528d60` are `0xcc` padding except for function-final zero bytes included by IDA before padding at some endpoints. No split is needed; these are expected local alignment between source/lowered helpers.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00528930-0x00528d51` | [UID:0001CM](../../../by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) | Shared animation-table helper island | TRUE | [UID:0000LK](../../../by-file/MonsterImageLibTables.md) | current `85/88`; recommended `90/90` | Source-ready after this report. |
| `0x0066deb0-0x0066debc` | [UID:00027U](../../../by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) | Shared default frame record | TRUE | [UID:0000LK](../../../by-file/MonsterImageLibTables.md) | `85/88` | Related data dependency; do not absorb into UID0001CM. |
| `0x0069b424-0x0069b430` | [UID:00029K](../../../by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md) | Concrete monster default outer table | TRUE | [UID:0000LJ](../../../by-file/MonsterImageLib.md) | `86/91` | Related storage; C010 raw/MCP byte issue is outside UID0001CM callback scope and does not block helper C++. |
| `0x0069b430-0x0069b43c` | [UID:0001PL](../../../by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md) | Concrete riding default outer table | TRUE | [UID:0000TJ](../../../by-global/RidingDefinitionGlobalTable.md) | `86/91` | Related storage; C010 raw/MCP byte issue is outside UID0001CM callback scope and does not block helper C++. |

## Heuristic / Inference Reanalysis And Validation

The target is not a pure data table and not a compiler-only artifact. It is a set of source-authored container helper methods, with two compiler-generated cleanup clones (`0x00528a70`, `0x00528c80`) and one trivial no-op destructor callback (`0x00528d50`) in the same island. The previous blocker, "standalone helper declaration pass pending", was solved by this accepted callback because:

- The helper names `ImageAnimationGroup` and `ImageAnimationFrame` are already accepted by [UID:0002JN][LoadMonsterTables](../../../by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md).
- The missing 12-byte outer type needs only a neutral source-facing name. `ImageAnimationTable` is the best current name because it describes the shared object shape used by both monster animation rows/default table and riding definition/default table logic without making it monster-only.
- The `MonsterImageLibTable_5289D0` and `MonsterImageLibTable_528BE0` names remain useful documentation aliases but should not be promoted into final source. They are address-derived and monster-biased, while current xrefs prove shared monster/riding use.
- `new[]` / `delete[]` source shape explains the vector constructor/destructor iterators, allocation count headers, EH cleanup clones, and no-op POD destructor callback better than raw helper calls.
- `ImageAnimationFrame::reserved`/padding byte at `+0x05` should not be explicitly initialized by the constructor. Current decompilation writes offsets `+0x00-+0x03`, `+0x04`, `+0x06-+0x07`, and `+0x08-+0x09`, but not `+0x05`. The formal code should preserve that by leaving the reserved byte alone.
- `ImageAnimationGroup` should not explicitly name the trailing `+0x06` word as a real field in source. The constructor zeroes pointer and frame count, while the 8-byte size naturally follows from 32-bit alignment padding after a pointer plus `unsigned short`.

Rejected alternatives:

- Keeping UID0001CM blank: rejected because the combined score clears the C++ gate, owner/emitter route is valid, helper bodies are source-authored, and current evidence resolves the stale declaration blocker.
- Moving the island to `MonsterImageLib`: rejected because riding parser code calls the same allocation helpers and uses the same default table shape.
- Moving the island to `RidingImageLib`: rejected for the same reason in the opposite direction; monster parser and render paths also use it.
- Splitting each helper into separate pages now: rejected because the range is a coherent helper implementation unit, the generated route wants one shared helper source, and the padding between functions is local alignment rather than unrelated ownership.
- Emitting `0x00528a70` and `0x00528c80` as separate source methods: rejected because they have no direct xrefs and duplicate destructor cleanup bodies as compiler EH/unwind helpers.
- Defining the `0x0066deb0` fallback storage inside UID0001CM: rejected because it is a separate by-memory data page and outside this target range.

## Ranked Ownership Analysis

### 1. [UID:0000LK] MonsterImageLibTables

- Evidence for: current owner/emitter route; projected source `NexusTK/render/MonsterImageLibTables.cpp`; shared monster/riding parser callers; related class pages already route here; generated coverage lists UID0001CM as emitting through this file.
- Evidence against: exact original source file may have been a private helper section inside a broader render image module rather than a standalone `.cpp`.
- Decision: keep direct owner/emitter `0000LK`. It remains the best durable source owner for this shared helper implementation.

### 2. [UID:0000LJ] MonsterImageLib

- Evidence for: monster loader, render, and default monster table storage use these helpers heavily; accepted loader C++ already uses the helper names.
- Evidence against: riding parser and render paths also use the helper island; monster-specific storage [UID:00029K] is separate from this shared implementation.
- Decision: support/consumer only, not direct owner.

### 3. [UID:0000N6] RidingImageLib

- Evidence for: riding parser and render/default table paths use the same helpers.
- Evidence against: monster parser/render paths also use them, and concrete riding default storage is separate from shared implementation.
- Decision: support/consumer only, not direct owner.

### 4. Address-derived class pages [UID:00008O] / [UID:00008P]

- Evidence for: they currently group the outer and inner helper roles and appear as generated empty markers before UID0001CM.
- Evidence against: page names are address-derived placeholders, not recovered class names; source declarations should use neutral helper names and live in UID0001CM/file route.
- Decision: keep as support aliases; implementation should update their autogen status to say source declarations are covered by UID0001CM or insert minimal formal comments if supervisor wants to clear their empty markers.

## Source Placement

Recommended source placement is `NexusTK/render/MonsterImageLibTables.cpp` through [UID:0000LK][MonsterImageLibTables](../../../by-file/MonsterImageLibTables.md). The source should define the shared helper structs/methods used by both monster and riding render-table loaders. The code should read as a small private helper module, not as public engine infrastructure and not as a monster-only class.

Recommended source-facing names:

- `ImageAnimationTable`: inferred 12-byte outer table shape with `groupCount` and `groups`; the first dword and middle two bytes are semantic overlays used differently by monster and riding concrete rows.
- `ImageAnimationGroup`: accepted 8-byte group record with `frames` and `frameCount`.
- `ImageAnimationFrame`: accepted 10-byte frame record with `frameOffset`, `frameDuration`, `blendAlpha`, inferred `reserved`, `auxFrameId`, `paletteIndex`, and `effectIndex`.
- `g_defaultImageAnimationFrame`: source-facing dependency name for [UID:00027U]. This target should reference it as `extern`; the storage definition belongs to UID00027U or a later data declaration pass.

## Range / Split / Padding / Reclassification Analysis

No split is recommended.

- The target range starts at the first current helper function `0x00528930` and ends at the no-op callback `0x00528d50-0x00528d51`.
- Successor function `0x00528d60` is outside the target.
- Internal `0xcc` bytes are alignment between helper bodies, not separate source objects.
- `0x00528a70` and `0x00528c80` stay documented inside the island as compiler-generated cleanup clones. They should not become standalone source methods or separate owners.
- Related data at `0x0066deb0`, `0x0069b424`, and `0x0069b430` remains outside this target.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. UID0001CM is reconstructable, has a valid emitter route, average score is above 85, and current MCP proves the source-facing helper declarations/body shapes.

Recommended formal `RECONSTRUCTION_CPP CODE` insertion text for UID0001CM:

```cpp
struct ImageAnimationFrame
{
    short frameOffset;
    unsigned short frameDuration;
    unsigned char blendAlpha;
    unsigned char reserved;
    short auxFrameId;
    unsigned char paletteIndex;
    unsigned char effectIndex;

    ImageAnimationFrame();
};

struct ImageAnimationGroup
{
    ImageAnimationFrame *frames;
    unsigned short frameCount;

    ImageAnimationGroup();
    ~ImageAnimationGroup();

    void AllocateFrames(unsigned int count);
    ImageAnimationFrame *GetFrame(unsigned int frameIndex);
};

struct ImageAnimationTable
{
    int baseValue;
    unsigned char groupCount;
    unsigned char flags;
    unsigned short tableId;
    ImageAnimationGroup *groups;

    ImageAnimationTable();
    ~ImageAnimationTable();

    void AllocateGroups(unsigned int count);
    ImageAnimationGroup *GetGroup(unsigned int groupIndex);
    ImageAnimationFrame *GetFrame(unsigned int groupIndex, unsigned int frameIndex);
};

extern ImageAnimationFrame g_defaultImageAnimationFrame;

ImageAnimationTable::ImageAnimationTable()
{
    baseValue = 0;
    groupCount = 0;
    flags = 0;
    tableId = 0;
    groups = NULL;
}

ImageAnimationTable::~ImageAnimationTable()
{
    delete[] groups;
    groupCount = 0;
    groups = NULL;
}

void ImageAnimationTable::AllocateGroups(unsigned int count)
{
    groups = new ImageAnimationGroup[count];
    groupCount = (unsigned char)count;
}

ImageAnimationGroup *ImageAnimationTable::GetGroup(unsigned int groupIndex)
{
    ImageAnimationGroup *group = groups;
    if (groupIndex < groupCount)
        group += groupIndex;
    return group;
}

ImageAnimationFrame *ImageAnimationTable::GetFrame(unsigned int groupIndex, unsigned int frameIndex)
{
    ImageAnimationGroup *group = groups;
    if (groupIndex < groupCount)
        group += groupIndex;

    if (frameIndex < group->frameCount)
        return group->frames + frameIndex;

    return &g_defaultImageAnimationFrame;
}

ImageAnimationGroup::ImageAnimationGroup()
{
    frames = NULL;
    frameCount = 0;
}

ImageAnimationGroup::~ImageAnimationGroup()
{
    delete[] frames;
    frames = NULL;
    frameCount = 0;
}

void ImageAnimationGroup::AllocateFrames(unsigned int count)
{
    frames = new ImageAnimationFrame[count];
    frameCount = (unsigned short)(unsigned char)count;
}

ImageAnimationFrame *ImageAnimationGroup::GetFrame(unsigned int frameIndex)
{
    if (frameIndex < frameCount)
        return frames + frameIndex;

    return &g_defaultImageAnimationFrame;
}

ImageAnimationFrame::ImageAnimationFrame()
{
    frameOffset = 0;
    frameDuration = 0;
    blendAlpha = 0xff;
    auxFrameId = -1;
    paletteIndex = 0;
    effectIndex = 0;
}
```

Reason it preserves original behavior:

- `new[]` / `delete[]` source explains the vector constructor/destructor iterator calls and allocation count headers.
- `AllocateGroups` and `AllocateFrames` preserve the observed allocation sizes `8 * count` and `10 * count`, callback construction, pointer stores, and low-byte count store behavior.
- The lookup methods preserve binary fallback behavior, including returning the first group pointer when `groupIndex >= groupCount` in `GetGroup` / outer `GetFrame`.
- `ImageAnimationFrame` constructor intentionally leaves `reserved` at `+0x05` untouched because current decompilation does not write that byte.
- The no-op frame destructor and EH cleanup clones should be compiler output from trivial/POD destructor and `new[]` / `delete[]`, not manually written as source methods.

Reason it matches plausible original source:

- The code is simple Visual C++ 6/7-era helper-struct code, not decompiler-shaped raw calls.
- It uses already accepted project vocabulary from the loader implementation and support docs.
- It avoids address-derived class names and `sub_`/`unk_` labels in source.

## Documentation Evidence And IDA Status

- `by-file/MonsterImageLibTables.md` already described the shared helper source route and accepted neutral names; callback implementation superseded its stale blank-C++/declaration-pass wording.
- `by-class/MonsterImageLibTable_5289D0.md` and `by-class/MonsterImageLibTable_528BE0.md` already stated their names are address-derived aliases; callback implementation updated them to reference UID0001CM as the source declaration/body home and to stop treating the declaration pass as pending.
- `by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md` remains a separate data target. This report's code uses an `extern` declaration for its source-level dependency; do not paste the data definition into UID0001CM.
- `by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md` and `by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md` are adjacent concrete storage pages, not UID0001CM helper-source dependencies. C010 is resolved for this report: current MCP reads zeroed storage and raw PE mapping places both addresses in `.data` virtual zero-fill; any stale all-`0xff` wording on those pages is a separate data-page cleanup matter and is not required for UID0001CM implementation.
- Generated `MonsterImageLibTables.cpp` currently has four empty markers: the two alias class pages, UID0001CM, and UID00027U. Implementing UID0001CM should clear the target marker; the other markers need either minimal "covered by UID0001CM" comments for alias pages or separate data/no-code dispositions.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | UID0001CM exact range remains `0x00528930-0x00528d51`; no split or rename is needed. | High | `lookup_funcs`, successor `0x00528d60`, padding bytes. | Target Range/Split, Status, Evidence Notes | incorporate | applied: target Status/Reconstruction Notes/Changes preserve no split/rename and padding/successor evidence. |
| C002 | Owner/emitter should remain [UID:0000LK] `MonsterImageLibTables`; MonsterImageLib and RidingImageLib are consumers. | High | Existing metadata, generated coverage, parser xrefs to both modules. | Target metadata, by-file MonsterImageLibTables, support docs | incorporate | applied: target metadata still `CANONICAL_OWNER:0000LK` and `EMITTER_UIDS:0000LK`; by-file and class pages identify MonsterImageLib/RidingImageLib as consumers. |
| C003 | The stale blank-C++ blocker is resolved; UID0001CM should emit first-draft helper code. | High | Current decompile, accepted B001 names, C++ gate satisfied, generated empty marker. | Target formal C++ block and Reconstruction Notes | incorporate | applied: target formal block now contains `ImageAnimationTable` / `ImageAnimationGroup` / `ImageAnimationFrame` C++; generated file emits UID0001CM source. |
| C004 | Source-facing 12-byte outer helper name should be `ImageAnimationTable`; address-derived `MonsterImageLibTable_5289D0` remains an alias only. | Medium-high | Shared monster/riding use, accepted neutral helper vocabulary, no IDA recovered name. | Target Accepted Names, by-file/class support docs | incorporate | applied: target, by-file, and UID00008O state `ImageAnimationTable` is inferred source-facing name and address-derived class page is an alias. |
| C005 | `ImageAnimationGroup` and `ImageAnimationFrame` are accepted source-facing names for the 8-byte and 10-byte records. | High | B001 implementation, class/type docs, current decompilation. | Target C++, class docs, by-file MonsterImageLibTables | incorporate | applied: target formal C++ and support docs use `ImageAnimationGroup` / `ImageAnimationFrame` with field caveats. |
| C006 | `0x00528a70` and `0x00528c80` are compiler EH/unwind cleanup clones, not standalone source methods. | High | No xrefs and duplicate cleanup decompilation. | Target Function Inventory / Reconstruction Notes | incorporate | applied: target function inventory and Reconstruction Notes preserve cleanup/unwind clone disposition; class pages keep them as duplicate cleanup/EH support. |
| C007 | UID0001CM should reference but not define the `0x0066deb0` fallback frame storage. | High | `xrefs_to 0x0066deb0`, UID00027U range ownership, outside target range. | Target C++ `extern` dependency, UID00027U support note | incorporate | applied/already-present: target formal C++ uses `extern ImageAnimationFrame g_defaultImageAnimationFrame`; target notes do not absorb storage; UID00027U already documents the fallback frame ownership at same-or-greater detail. |
| C008 | Recommended target score is `90/90`. | Medium-high | Current MCP evidence, formal C++ readiness, remaining original-name uncertainty. | Target metadata and support rows | incorporate | applied: target metadata changed to `COMPLETION:90`, `CONFIDENCE:90`; by-file support records the score rationale without changing file-level score. |
| C009 | Generated output should show UID0001CM emitted source after validation; other existing empty markers may remain until support alias/data pages are addressed. | High | Read-only generated `MonsterImageLibTables.cpp` inspection. | Report Validator Results / generated expectation, support docs | incorporate | applied: read-only generated inspection after validators shows UID0001CM source emitted under command id `000000000779`; UID00008O/UID00008P/UID00027U still show empty markers as separate scoped items. |
| C010 | The `0x0069b424-0x0069b43c` byte-state discrepancy is resolved as not applicable to UID0001CM implementation: current MCP reads zeroed storage, raw PE mapping places both addresses in `.data` virtual zero-fill, and the range is outside UID0001CM helper code and outside the `0x0066deb0` fallback frame dependency used by the helper methods. | High | Current MCP `get_bytes`/`get_int`; raw PE mapping of VA `0x0069b424` -> RVA `0x0029b424`, `.data`, raw offset `0x00299024`, virtual-zero-fill, and VA `0x0069b430` -> RVA `0x0029b430`, `.data`, raw offset `0x00299030`, virtual-zero-fill; target range/xrefs. | Report-only exclusion note; no target/support by-* edit required for UID0001CM callback | not-applicable | excluded-with-reason: target Status/Evidence Notes preserve C010 as outside UID0001CM score/C++/owner impact; UID00029K/UID0001PL not edited. |
| C011 | Class alias pages [UID:00008O]/[UID:00008P] should not emit duplicate helper declarations; they should point to UID0001CM as the declaration/body home or use minimal covered-by comments. | High | Generated output order, alias-page status, target C++ recommendation. | by-class support docs | incorporate | applied: both class pages now state they are address-derived support aliases covered by UID0001CM source and should not duplicate helper C++. |
| C012 | Several function inventory rows should be normalized to current half-open IDA endpoints: `0x005289d0-0x00528a6e`, `0x00528af0-0x00528b08`, `0x00528b10-0x00528b44`, `0x00528be0-0x00528c7c`, and `0x00528d00-0x00528d28`. | High | `lookup_funcs` sizes from current session `b2ae72ec`; endpoint byte probes. | Target and class support Function/Method maps | incorporate | applied: target and by-class method maps use the normalized half-open endpoints; by-file records the normalized endpoint set. |

## Implemented Target Doc Changes

- Target path: `by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md`
- Metadata changed from `COMPLETION:85` / `CONFIDENCE:88` to `COMPLETION:90` / `CONFIDENCE:90`; `CANONICAL_OWNER:0000LK`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000LK` were kept.
- Formal C++ inserted using the exact `ImageAnimationTable` / `ImageAnimationGroup` / `ImageAnimationFrame` block from this report.
- Body text updated in Status, Item Summary, Evidence Notes, Accepted Source-Facing Layout Names, Reconstruction Notes, Score Rationale, and Changes to state that the declaration pass is complete enough for first-draft C++.
- Negative evidence preserved: no split, no monster-only/riding-only ownership, no helper clones as source methods, no fallback-frame storage inside UID0001CM, no address-derived class names in final source.
- Current MCP session `b2ae72ec` evidence added: `idb_list`, `server_health`, exact helper inventory, xrefs, decompilation, padding, generated output state, and C010 not-applicable byte-state exclusion.
- Function inventory normalized for helpers whose existing table rows used last-byte-style endpoints: `0x005289d0-0x00528a6e`, `0x00528af0-0x00528b08`, `0x00528b10-0x00528b44`, `0x00528be0-0x00528c7c`, and `0x00528d00-0x00528d28`.

## Implemented Support Doc Changes

- `by-file/MonsterImageLibTables.md`: Status/Score Rationale/Helper Island Details/Changes now say UID0001CM carries first-draft helper declarations and method definitions; stale "helper C++ remains blank pending declaration pass" wording was superseded; remaining empty markers for alias/data pages are separate scoped items.
- `by-class/MonsterImageLibTable_5289D0.md`: preserved as an address-derived alias; Autogen Status and Accepted Neutral Name Overlay now say source declarations/method bodies are emitted by UID0001CM as `ImageAnimationTable`, and this class page should not duplicate C++.
- `by-class/MonsterImageLibTable_528BE0.md`: preserved as an address-derived alias; Autogen Status and Accepted Neutral Name Overlay now say source declarations/method bodies are emitted by UID0001CM as `ImageAnimationGroup` / `ImageAnimationFrame`, and this class page should not duplicate C++.
- `by-file/MonsterImageLib.md`, `by-file/RidingImageLib.md`, UID0002JN, and UID0002LA were not edited; the accepted details were incorporated through the target/by-file/class pages and optional narrow notes were not needed.
- `by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md` was not edited because it already documents the fallback frame ownership at same-or-greater detail; UID0001CM references it with `extern ImageAnimationFrame g_defaultImageAnimationFrame` and does not absorb the storage.
- `by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md` and `by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md` were not edited for C010. The current zero-byte/virtual-zero-fill evidence is outside the UID0001CM helper range and does not affect UID0001CM owner/emitter route, C++ content, or score.

## Score And Metadata Recommendation

- Current target metadata: `85/88`, owner/emitter `0000LK`, reconstructable true, blank C++.
- Recommended target metadata: `90/90`, owner/emitter unchanged, reconstructable true, formal C++ present.
- Reason completion rises: current report adds a source-ready formal helper declaration/body block, current MCP exact range/xref/decompile/padding evidence, and closes the previous declaration-pass blocker.
- Reason confidence rises: helper behavior, caller family, owner route, generated route, and source-facing names are cross-checked by current MCP and accepted support docs.
- Reason not higher: exact original helper type names, exact file/private-header placement, and some weak frame-field names remain inferred. C010 no longer caps the UID0001CM score because the adjacent default globals are outside this helper-source implementation.

## Final Recommendation

- Apply UID0001CM helper declaration/body C++ and raise the target to `90/90`.
- Keep the source route through owner/emitter [UID:0000LK] `MonsterImageLibTables`.
- Treat [UID:00008O] and [UID:00008P] as address-derived support aliases, not duplicate emitters.
- Keep [UID:00027U], [UID:00029K], and [UID:0001PL] as separate data pages. Do not add C010 byte-discrepancy edits as part of the UID0001CM callback unless the supervisor explicitly widens scope beyond this report.
- After validation and generated refresh, `auto-generated/NexusTK/render/MonsterImageLibTables.cpp` emits UID0001CM helper source instead of listing UID0001CM as an Empty Emitter Marker.

## Open Questions With Attempted Resolution

- Exact original 12-byte outer helper type name: no recovered symbol exists; `ImageAnimationTable` is the best source-facing descriptive name. It is strong enough for first-draft source but should be marked inferred.
- Exact public/private placement: evidence supports a shared render helper source, but whether it was a standalone `MonsterImageLibTables.cpp` or private helper declarations included by image-library modules remains unresolved. The existing owner/emitter route through `MonsterImageLibTables.cpp` is the best current project placement.
- `ImageAnimationFrame` weak fields `auxFrameId`, `paletteIndex`, and `effectIndex`: current target only allocates and initializes/returns records; consumer semantics remain partly outside scope. Keep existing caveats.
- Default global initial bytes at `0x0069b424-0x0069b43c`: resolved for this report. Current MCP reads zeros, and raw PE mapping shows `.data` virtual-zero-fill at both `0x0069b424` and `0x0069b430`; therefore the older all-`0xff` text is not a UID0001CM implementation blocker, does not affect the recommended helper C++, and requires no UID0001CM callback edit.

## Validator Results

Implementation callback validators were run from `source-3/project-documentation`:

- `python .\tools\validator.py --mode file --file by-memory\0x00528930-0x00528d51.MonsterImageLibTables.md --apply --queue-timeout 240 --wait-generated`
  - Exit code: `0`
  - `command_id: 000000000776`
  - `command_timestamp: 2026-06-29T13:18:59-04:00`
  - `ok: 1`
  - Notable output: `completion_update 0001CM ... 90`, `confidence_update 0001CM ... 90`, `autogen_registry_update ... blank -> block`, generated refresh completed.
- `python .\tools\validator.py --mode file --file by-file\MonsterImageLibTables.md --apply --queue-timeout 240`
  - Exit code: `0`
  - `command_id: 000000000777`
  - `command_timestamp: 2026-06-29T13:19:35-04:00`
  - `ok: 1`
  - Generated refresh: deferred.
- `python .\tools\validator.py --mode file --file by-class\MonsterImageLibTable_5289D0.md --apply --queue-timeout 240`
  - Exit code: `0`
  - `command_id: 000000000778`
  - `command_timestamp: 2026-06-29T13:19:46-04:00`
  - `ok: 1`
  - Generated refresh: deferred.
- `python .\tools\validator.py --mode file --file by-class\MonsterImageLibTable_528BE0.md --apply --queue-timeout 240`
  - Exit code: `0`
  - `command_id: 000000000779`
  - `command_timestamp: 2026-06-29T13:19:52-04:00`
  - `ok: 1`
  - Generated refresh: deferred.

Read-only generated output inspection:

- File: `auto-generated/NexusTK/render/MonsterImageLibTables.cpp`
- Header after callback: `validator-command-id: 000000000779`, `validator-refreshed-at: 2026-06-29T13:19:52-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- UID0001CM now emits `ImageAnimationFrame`, `ImageAnimationGroup`, `ImageAnimationTable`, and `extern ImageAnimationFrame g_defaultImageAnimationFrame`; UID0001CM is no longer an Empty Emitter Marker.
- UID00008O, UID00008P, and UID00027U still show Empty Emitter Markers as separate alias/data pages outside this callback's C++ emission scope.

## Changed Files

- Modified: `by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md`
- Modified: `by-file/MonsterImageLibTables.md`
- Modified: `by-class/MonsterImageLibTable_5289D0.md`
- Modified: `by-class/MonsterImageLibTable_528BE0.md`
- Modified: `tools/leaser/Agents/Agent-B007/research/0001CM-MonsterImageLibTables-empty-emitter-source-quality.md`
- Optional docs not edited: `by-file/MonsterImageLib.md`, `by-file/RidingImageLib.md`, UID0002JN, UID0002LA, UID00027U, UID00029K, and UID0001PL. UID00027U already contained fallback-frame ownership detail; UID00029K/UID0001PL were excluded for C010.
- Leases: B007 leased the four by-* docs for the immediate edit/validator batch, renewed after the target `--wait-generated` validator crossed the first five-minute lease window, and released all B007 leases after updating this checklist.

## Implementation Tracking Checklist

Implementation callback:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted report and issued `B007-implement-0001CM-MonsterImageLibTables-empty-emitter-20260629`.
- [x] Lease only immediate files to edit during callback; do not lease during report-only research. Proof: leased only target, by-file, and two by-class support docs; no report lease needed.
- [x] Update `by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md` metadata to `COMPLETION:90`, `CONFIDENCE:90`, keeping owner/emitter/reconstructable route `0000LK`. Proof: validator `000000000776` reported `completion_update` and `confidence_update`.
- [x] Insert the exact formal UID0001CM C++ block from this report. Proof: target formal block and generated C++ contain `ImageAnimationTable`, `ImageAnimationGroup`, `ImageAnimationFrame`, and `extern ImageAnimationFrame g_defaultImageAnimationFrame`.
- [x] Update UID0001CM Item Summary, Status, Evidence Notes, Function table, Accepted Source-Facing Layout Names, Reconstruction Notes, Score Rationale, Range/Split/Padding notes, and Changes with current MCP session `b2ae72ec` facts. Proof: target sections updated with session `b2ae72ec`, normalized endpoints, xrefs, cleanup-clone status, C010 exclusion, and score rationale.
- [x] Normalize helper inventory half-open endpoints for `0x005289d0`, `0x00528af0`, `0x00528b10`, `0x00528be0`, and `0x00528d00` in the target and affected class support maps. Proof: target, by-file, UID00008O, and UID00008P contain normalized endpoint rows/notes.
- [x] Preserve rejected alternatives: no split, no monster-only/riding-only owner, no duplicate source methods for EH cleanup clones, no fallback data definition inside UID0001CM, no final source use of address-derived class names. Proof: target and support docs explicitly preserve these negative findings.
- [x] Update `by-file/MonsterImageLibTables.md` so the declaration pass is no longer pending and UID0001CM is the helper source body home. Proof: by-file Status, Score Rationale, File Role, Helper Island Details, and Changes updated.
- [x] Update `by-class/MonsterImageLibTable_5289D0.md` and `by-class/MonsterImageLibTable_528BE0.md` as address-derived support aliases covered by UID0001CM source declarations; do not duplicate helper C++ there unless supervisor explicitly wants minimal covered-by comments. Proof: both class pages state C++ remains blank because UID0001CM emits the source; no duplicate helper C++ inserted.
- [x] If edited, update `by-file/MonsterImageLib.md`, `by-file/RidingImageLib.md`, UID0002JN, and UID0002LA only with narrow support notes tying their parser C++ to UID0001CM helper source. Proof: not edited; required details were already handled in the target/by-file/class pages and optional docs were not needed.
- [x] Do not absorb or redefine [UID:00027U] `0x0066deb0-0x0066debc` inside UID0001CM; if edited, add only the dependency note or a separate supervisor-approved sentinel-data disposition. Proof: UID0001CM declares `extern` only; UID00027U was read-only and already had fallback ownership details.
- [x] Preserve C010 as not applicable to the UID0001CM callback: do not edit UID00029K/UID0001PL for C010 under this callback; record that current MCP zeroes plus raw PE `.data` virtual-zero-fill prove the adjacent data-page byte issue has no UID0001CM score, C++, owner/emitter, or source-placement impact. Proof: target Status/Evidence Notes and ledger C010 record exclusion; UID00029K/UID0001PL were not edited.
- [x] Run the scoped validators listed above, recording command, command id, timestamp, exit code, ok count, warnings, and generated-refresh state. Proof: validator results section records commands `000000000776` through `000000000779`, all exit `0`, all `ok: 1`.
- [x] Inspect generated `auto-generated/NexusTK/render/MonsterImageLibTables.cpp` read-only and confirm UID0001CM no longer appears as an Empty Emitter Marker. Proof: generated header `000000000779` and UID0001CM source body inspected read-only; no UID0001CM Empty Emitter Marker remains.
- [x] Update this Claim And Incorporation Ledger after callback with `applied`, `already-present`, or explicit exclusion reasons for C001-C012. Proof: ledger rows updated above.
- [x] Release all B007 leases immediately after the edit/validator batch and verify no active B007 leases remain. Proof: release command run after this checklist update; shared `current_leases.md` checked after release.
- [x] Do not edit generated files, manual `-coverage-report.md` files, project-level generated reports, validator/tool state, IDA DB, executed archives, or supervisor ledgers. Proof: generated C++ inspected read-only; only validator-generated side effects occurred through scoped validator commands.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0001CM-MonsterImageLibTables-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0001CM-MonsterImageLibTables-empty-emitter-source-quality.md","timestamp":"2026-06-29T13:31:31","uid":"0001CM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
