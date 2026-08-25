** TARGET-REPORT-UID:0000O7 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** ASSIGNMENT-ID:B010-report-0000O7-StaticObjImageLib-empty-emitter-family-20260701 **
** MODE:REPORT_ONLY **
** STATUS:IMPLEMENTED_FOR_SUPERVISOR_VERIFICATION **

# 0000O7 StaticObjImageLib Empty-Emitter Family Source-Quality Research

## Scope

Target page:

- [UID:0000O7][by-file/StaticObjImageLib.md](../../../../../by-file/StaticObjImageLib.md)

Generated lead:

- `auto-generated/NexusTK/render/StaticObjImageLib.cpp`

Current visible generated empty markers:

| UID | Page | Current disposition in this report |
| --- | --- | --- |
| [UID:0000SD] | `by-global/g_pStaticObjImageLib.md` | Source-bearing global definition is ready. |
| [UID:0001PP] | `by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md` | Exact storage page should emit a no-duplicate/no-separate-source comment and correct stale zero-initialization evidence. |
| [UID:0000U6] | `by-item/BuildTilecArchiveTable_004DDA60.md` | First-draft formal C++ is ready, using the already accepted archive-table declarations and the neighboring accepted `BuildEffectArchiveTable` source form as a style lead. |
| [UID:000184] | `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md` | Target-specific no-code comment is ready; it is static cleanup/unwind glue whose source effect is the singleton clear. |

This is a report-only pass. No by-* docs, generated files, coverage reports, validator state, supervisor ledgers, archives, by-project-structure docs, queue files, or IDA DB were edited.

## MCP Evidence

Live IDA MCP was available and used. Session evidence:

- MCP server: `ida-pro-mcp`, protocol `2025-06-18`.
- Database: `supervisor_resume_20260629`.
- `idb_list`: one active session, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `14860`, not analyzing.
- `server_health`: `status=ok`, auto-analysis ready, Hex-Rays ready, strings cache ready, imagebase `0x400000`.

Calls were narrow and exact-address scoped per `by-structure.md` IDA MCP Output Discipline. No broad search, broad disassembly, broad callgraph, broad type scan, or batch analysis was used.

Exact MCP facts used:

- `lookup_funcs`:
  - `0x004dcf60` -> `sub_4DCF60`, size `0x278`.
  - `0x004dd1e0` -> `sub_4DD1E0`, size `0xde`.
  - `0x004dd2c0` -> `sub_4DD2C0`, size `0x58a`.
  - `0x004dd850` -> `sub_4DD850`, size `0x51`.
  - `0x004dd8b0` -> `sub_4DD8B0`, size `0x172`.
  - `0x004dda30` -> `sub_4DDA30`, size `0x27`.
  - `0x004dda60` -> `sub_4DDA60`, size `0x3a2`.
  - `0x004dde10` -> `sub_4DDE10`, size `0x14e`.
  - `0x004e5c00` -> `sub_4E5C00`, size `0xb`.
  - `0x004e6990` -> `sub_4E6990`, size `0x116`.
- `xrefs_to 0x004dda60`: one code xref from `0x004dd0f0` inside `sub_4DCF60`.
- `xrefs_to 0x004e5c00`: one constructor cleanup/EH xref from `0x005fff9d` associated with `sub_4DCF60`; no ordinary public caller set.
- `xrefs_to 0x0069b448`: 13 data xrefs at constructor publish/clear, ordinary destructor clear, singleton clear helper, scalar deleting destructor clear, shutdown, map/static-object consumers, StaticObjectPane, and PhotoPane.
- `xrefs_to 0x0061b704`: vtable writes/restores at `0x004dcfb8`, `0x004dd20b`, and `0x004e69c4`.
- `get_global_value 0x0069b448`: `0x0`.
- `get_bytes 0x0069b440` size 24: neighboring image-library singleton storage bytes are all zero, including `0x0069b448`.
- `get_bytes 0x0069b448` size 4: `00 00 00 00`.
- `get_bytes 0x004dcf9c` size 24: constructor sequence stores the constructed pointer to `0x0069b448` or clears the slot to zero on the guard/fallback path.
- `get_bytes 0x004dd294` size 16 and `0x004e6a58` size 16: ordinary and scalar destructor sequences clear `0x0069b448` to zero.
- `get_bytes 0x004e5bf0` size 48: prior helper bytes, `sub_4E5C00` exact `mov [0x0069b448], 0; ret`, then alignment padding and next function.
- `disasm 0x004e5c00 max_instructions=8`: exactly two instructions, `mov dword ptr unk_69B448, 0` and `retn`.
- `decompile 0x004e5c00`: body reduces to `unk_69B448 = 0`.
- `analyze_function 0x004dda60 include_asm=false`: function size 930, 44 basic blocks, cyclomatic complexity 18, one caller from `sub_4DCF60`, and callees for allocation, DAT probing/open/read/seek, rectangle initialization, cleanup, free, and security-cookie check.
- `decompile 0x004dda60`: scans `TILEC%d.EPF` up to 100 shards, uses a 20-wchar buffer, probes entry existence, constructs temporary DAT readers and 12-byte shard headers, reads 8-byte shard headers, accumulates frame count and max metrics, allocates `24 * (count + 1)` packed records, reads raw top/left/bottom/right and payload offsets, normalizes bounds through `sub_4B7C50`, rebases offsets through the DAT payload base, appends a zero-rect sentinel, closes and destroys readers, frees temporaries, and returns the merged table.
- `decompile 0x004dcf60`: constructor publishes `g_pStaticObjImageLib`, installs the StaticObjImageLib vtable, reads `SOBJ.TBL`, stores `StaticObjImageLib +0x04` from `BuildTilecArchiveTable(L"TILEC.EPF")` in modern mode, uses the legacy `LoadImageFrameTable` route otherwise, and reads tile-class records.

## Current Docs And Leads Checked

Current docs read or checked as lead/support material:

- `by-file/StaticObjImageLib.md`
- `by-class/StaticObjImageLib.md`
- `by-global/g_pStaticObjImageLib.md`
- `by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md`
- `by-item/BuildTilecArchiveTable_004DDA60.md`
- `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md`
- `by-item/EPFArchiveMetadataTable.md`
- `by-file/EPFImageResources.md`
- `by-resource/sobj-tbl.md`
- `by-type/by-struct/StaticObjImageLibLayout.md`
- `by-type/by-vtable/StaticObjImageLibVtable.md`
- `by-item/BuildEffectArchiveTable_004DE420.md`
- `auto-generated/NexusTK/render/StaticObjImageLib.cpp`
- `auto-generated/-ag-research-tracker.md`

Older A-agent/B-agent and generated material was used only as lead material. Fresh MCP facts above are the acceptance evidence for the current pass.

## Tracker / Generated Count Discrepancy

The tracker row for [UID:0000O7] still reports `12` total emitters, `2` filled, `10` empty, `16.7%`. The current generated file is newer than the goal's cited generated snapshot and does not match that row.

Current generated file header observed for `auto-generated/NexusTK/render/StaticObjImageLib.cpp`:

- `validator-command-id: 000000003914`
- refreshed: `2026-07-01T15:39:40-04:00`

Current visible generated output contains:

- One populated class declaration from [UID:0000E2].
- Four empty markers: [UID:0000SD], [UID:0001PP], [UID:0000U6], [UID:000184].

The discrepancy is therefore a generated/tracker freshness mismatch, not proof of six additional currently visible empty emitters in `StaticObjImageLib.cpp`. The implementation callback should not manually edit the tracker. It should apply the accepted by-* updates, run scoped validators with `--wait-generated`, and then verify the refreshed generated file and tracker state. If the tracker still reports 12/2/10 after validators, that should be escalated as a validator/autogen indexing issue rather than solved by hand-editing `auto-generated/-ag-research-tracker.md`.

## Ownership And Source Placement

Ranked source-placement decision:

1. [UID:0000O7] `StaticObjImageLib.cpp`: owns the file-level singleton definition, StaticObjImageLib constructor-owned `TILEC` table builder, and constructor/static cleanup helper evidence.
2. [UID:0000E2] `StaticObjImageLib` class: owns declaration/layout context and already emits class-level declarations; it should keep the `extern StaticObjImageLib *g_pStaticObjImageLib;` declaration only.
3. [UID:0000UN] `EPFArchiveMetadataTable`: owns the shared `ArchiveMetadataTable` / `PackedArchiveRecord` declarations already accepted for image-frame metadata tables. It is support evidence for `BuildTilecArchiveTable`, not the owner of the Tilec helper body.
4. [UID:0000K1] `ImageFrameTable` / [UID:0000J3] `EPFImageResources`: source-family support for shared EPF table shape; not the direct emitter for `BuildTilecArchiveTable` because current xrefs prove the Tilec helper has one StaticObjImageLib constructor caller and asset-specific `TILEC` ownership.
5. Consumer pages such as StaticObjectPane, PhotoPane, MapPane, and ObjectList paths are rejected as owners. Their xrefs read the singleton or consume rendered objects; they do not publish the singleton, build the table, or own `SOBJ.TBL` / `TILEC` parsing.

## Marker Dispositions

### [UID:0000SD] `g_pStaticObjImageLib`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000O7`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000O7`

Recommended formal `RECONSTRUCTION_CPP CODE`:

```cpp
StaticObjImageLib *g_pStaticObjImageLib = 0;
```

Rationale:

- Current MCP confirms exact storage at `0x0069b448` with 13 lifecycle/consumer xrefs.
- Current bytes and global value prove zero initialization, not the stale `0xffffffff` sentinel currently written on the storage page and repeated by the global page.
- The class page already emits the declaration `extern StaticObjImageLib *g_pStaticObjImageLib;`; this global page should emit the single source definition.
- The constructor publishes the object pointer and destructors/cleanup clear it to zero. The source global initialization should therefore be null.

Support updates needed:

- Correct the stale wording in `by-global/g_pStaticObjImageLib.md` that says the exact storage child records an initialized `0xffffffff` sentinel.
- Preserve the 13-xref lifecycle table.
- Add that current B010 MCP recheck shows zero-initialized storage and that [UID:0000SD] owns the source definition while [UID:0001PP] is exact storage support.

### [UID:0001PP] `0x0069b448-0x0069b44c.g_pStaticObjImageLib`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000SD`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000SD`

Recommended formal `RECONSTRUCTION_CPP CODE`:

```cpp
// Exact storage for g_pStaticObjImageLib is emitted by [UID:0000SD].
// Current IDA MCP bytes show this slot is zero-initialized.
```

Rationale:

- This page should not duplicate the global definition, because [UID:0000SD] is the source-facing singleton symbol.
- It must not remain an empty marker: the source-quality disposition is a no-duplicate storage comment plus stale-data correction.
- Current MCP `get_bytes` and `get_global_value` prove `00 00 00 00` / `0x0`, while the current page incorrectly says `ff ff ff ff` / `0xffffffff`.

Support updates needed:

- Change Item Summary and Storage table from `0xffffffff` to zero-initialized.
- Keep lifecycle xrefs, constructor publish/clear, ordinary/helper/scalar destructor clears, shutdown read, and consumer reads.
- Explicitly state that source emission belongs to [UID:0000SD].

### [UID:0000U6] `BuildTilecArchiveTable_004DDA60`

Recommended metadata:

- `COMPLETION:89`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000O7`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000O7`

Recommended formal `RECONSTRUCTION_CPP CODE`:

```cpp
ArchiveMetadataTable *BuildTilecArchiveTable(const wchar_t *unusedArchiveName)
{
    (void)unusedArchiveName;

    struct TilecArchiveShardHeader
    {
        unsigned short frameCount;
        unsigned short maxWidth;
        unsigned short maxHeight;
        unsigned short reserved;
    };

    int shardCount = 0;
    wchar_t archiveName[20];
    while (shardCount < 100)
    {
        swprintf(archiveName, 20, L"TILEC%d.EPF", shardCount);
        if (!HasDATEntry(archiveName))
        {
            break;
        }
        ++shardCount;
    }

    TilecArchiveShardHeader *headers =
        shardCount > 0 ? new TilecArchiveShardHeader[shardCount] : 0;
    DATFile *archives = shardCount > 0 ? new DATFile[shardCount] : 0;

    ArchiveMetadataTable *table = new ArchiveMetadataTable;
    table->frameCount = 0;
    table->maxWidth = 0;
    table->maxHeight = 0;
    table->reserved = 0;
    table->records = 0;

    for (int i = 0; i < shardCount; ++i)
    {
        swprintf(archiveName, 20, L"TILEC%d.EPF", i);
        archives[i].Open(archiveName);
        archives[i].Read(&headers[i], 8);

        table->frameCount =
            static_cast<unsigned short>(table->frameCount + headers[i].frameCount);
        if (table->maxWidth < headers[i].maxWidth)
        {
            table->maxWidth = headers[i].maxWidth;
        }
        if (table->maxHeight < headers[i].maxHeight)
        {
            table->maxHeight = headers[i].maxHeight;
        }
    }

    table->records = new PackedArchiveRecord[table->frameCount + 1];
    PackedArchiveRecord *outRecord = table->records;
    unsigned char *lastPayloadBase = 0;
    int lastRecordTableOffset = 0;

    for (int i = 0; i < shardCount; ++i)
    {
        int recordTableOffset = 0;
        archives[i].Read(&recordTableOffset, sizeof(recordTableOffset));

        unsigned char *payloadBase = archives[i].GetDataPointer();
        lastPayloadBase = payloadBase;
        lastRecordTableOffset = recordTableOffset;

        archives[i].Seek(recordTableOffset, 1);

        for (int recordIndex = 0; recordIndex < headers[i].frameCount; ++recordIndex)
        {
            short top = 0;
            short left = 0;
            short bottom = 0;
            short right = 0;
            int payloadStartOffset = 0;
            int payloadEndOffset = 0;

            archives[i].Read(&top, sizeof(top));
            archives[i].Read(&left, sizeof(left));
            archives[i].Read(&bottom, sizeof(bottom));
            archives[i].Read(&right, sizeof(right));
            archives[i].Read(&payloadStartOffset, sizeof(payloadStartOffset));
            archives[i].Read(&payloadEndOffset, sizeof(payloadEndOffset));

            InitRectBounds(&outRecord->bounds, left, top, right, bottom);
            outRecord->payloadStart = payloadBase + payloadStartOffset;
            outRecord->payloadEnd = payloadBase + payloadEndOffset;
            ++outRecord;
        }
    }

    InitRectBounds(&outRecord->bounds, 0, 0, 0, 0);
    outRecord->payloadStart =
        lastPayloadBase != 0 ? lastPayloadBase + lastRecordTableOffset : 0;
    outRecord->payloadEnd =
        lastPayloadBase != 0 ? lastPayloadBase + lastRecordTableOffset : 0;

    for (int i = shardCount - 1; i >= 0; --i)
    {
        archives[i].Close();
    }

    delete [] archives;
    delete [] headers;

    return table;
}
```

Rationale:

- The previous "blank until final names" rationale is no longer enough under the score-blocker audit standard.
- The source body is strongly bounded by fresh MCP decompilation and by the accepted neighboring `BuildEffectArchiveTable` formal C++ pattern.
- The inferred helper/type names are not final original symbols, but they are already accepted project vocabulary: `ArchiveMetadataTable`, `PackedArchiveRecord`, `DATFile`, `HasDATEntry`, `InitRectBounds`, and `GetDataPointer`.
- The function parameter is preserved as an unused wide-name parameter because the binary receives one argument from the constructor call but current decompilation does not use it inside the numbered `TILEC%d.EPF` scan.
- The body preserves the source-significant behavior: 100-shard cap, 20-wchar archive-name buffer, stop on first missing shard, 8-byte shard header read, max metric accumulation, `frameCount + 1` record allocation, raw top/left/bottom/right conversion, DAT payload rebasing, terminal sentinel, reverse close, and cleanup.

Support updates needed:

- Update `by-item/BuildTilecArchiveTable_004DDA60.md` from blank to the formal body above.
- Add a note that this mirrors the already accepted `BuildEffectArchiveTable` source form but remains a StaticObjImageLib-owned helper because the current xref set has one constructor caller at `0x004dd0f0`.
- Add a note that helper spellings are source-facing inferred names, not original-symbol proof, and are accepted enough for first-draft C++.
- Update `by-file/StaticObjImageLib.md` to record that the Tilec builder is now first-draft formal C++ ready.
- Ensure `by-item/EPFArchiveMetadataTable.md` stays as the support declaration source for `ArchiveMetadataTable` and `PackedArchiveRecord`; no content change is required if the current declarations remain present.

### [UID:000184] `StaticObjImageLibSingletonClearHelper`

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000O7`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000O7`

Recommended formal `RECONSTRUCTION_CPP CODE`:

```cpp
// StaticObjImageLib constructor/static cleanup glue.
// The only binary effect is g_pStaticObjImageLib = 0; the source singleton
// definition is emitted by [UID:0000SD], and normal C++ lifetime/unwind code
// should regenerate this helper.
```

Rationale:

- Current MCP proves the exact two-instruction helper: `g_pStaticObjImageLib = 0; return`.
- `xrefs_to 0x004e5c00` reaches it from constructor cleanup/EH machinery rather than a public source call.
- The exact effect is source-owned and should not stay an empty marker, but a named public helper body would misstate the source route.
- The no-code comment is target-specific: it explains why the marker exists, what binary state it mutates, and which source emitter owns the actual global definition.

Support updates needed:

- Keep owner/emitter as [UID:0000O7].
- Replace "formal C++ intentionally blank" with the formal no-code comment above.
- Preserve the exact byte/disassembly/decompile evidence and constructor cleanup xref.

## Target And Support Doc Recommendations

Accepted implementation should update these docs only:

- `by-file/StaticObjImageLib.md`
  - Raise to `COMPLETION:88`, `CONFIDENCE:88`.
  - Add current B010 generated/tracker discrepancy note: generated file currently has four visible empty markers, while tracker row still says 12/2/10.
  - Add current MCP provenance and the four marker dispositions.
  - State that `g_pStaticObjImageLib` is zero-initialized, not `0xffffffff`.
  - State that `BuildTilecArchiveTable` now has first-draft formal C++ using the accepted archive-table pattern.
  - State that the singleton clear helper should emit a no-code cleanup-glue comment.
- `by-class/StaticObjImageLib.md`
  - Keep the declaration-level `extern StaticObjImageLib *g_pStaticObjImageLib;`.
  - Add that [UID:0000SD] now owns the source definition and [UID:0001PP] is storage support.
  - Add that `BuildTilecArchiveTable` is first-draft formal C++ ready; do not move the helper to the class declaration block.
  - Optional score unchanged at `88/89`.
- `by-global/g_pStaticObjImageLib.md`
  - Add formal source definition.
  - Correct stale sentinel wording to zero-initialized current storage.
  - Raise to `88/91`.
- `by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md`
  - Correct Item Summary, Storage table, and Evidence Notes from `0xffffffff` / `ff ff ff ff` to zero / `00 00 00 00`.
  - Add no-duplicate storage comment.
  - Raise to `88/91`.
- `by-item/BuildTilecArchiveTable_004DDA60.md`
  - Add formal first-draft C++ body.
  - Raise to `89/91`.
  - Keep owner/emitter [UID:0000O7].
- `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md`
  - Add formal no-code cleanup-glue comment.
  - Raise to `86/91`.
- `by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md`
  - Support-only update: record the current zero-initialized singleton correction and the first-draft BuildTilec source-form decision. Do not make this aggregate emit the child body.

No by-project-structure doc changes are recommended.

## Positive Evidence

- The current generated file has exactly four visible empty markers, each source-placeable or no-code-placeable with current evidence.
- `g_pStaticObjImageLib` has a complete lifecycle xref set and exact storage.
- The current IDB proves the singleton slot is zero-initialized. This repairs a stale storage claim, not a new ambiguity.
- `BuildTilecArchiveTable` has one constructor caller and a fully bounded table-builder body.
- The accepted `BuildEffectArchiveTable` formal C++ provides a same-pattern project precedent for not leaving this helper blank solely because source names remain inferred.
- `EPFArchiveMetadataTable` already emits the `ArchiveMetadataTable` and `PackedArchiveRecord` declarations used by the proposed helper.
- `StaticObjImageLibLayout` and `StaticObjImageLib` class docs already support `tileCatalog`, `tileClasses`, `staticObjEntries`, and `staticObjCount`.

## Negative Evidence / Rejected Alternatives

- Do not keep [UID:0000U6] blank solely because final original helper/type names are unknown. Fresh evidence and accepted sibling code make a first-draft body defensible.
- Do not move `BuildTilecArchiveTable` to `ImageFrameTable.cpp` or EPFImageResources. Current direct xref evidence has one StaticObjImageLib constructor caller and resource-specific `TILEC` ownership.
- Do not emit a second global definition from [UID:0001PP]. It is exact storage support for [UID:0000SD].
- Do not keep or repeat the `0xffffffff` singleton-initializer claim. Current bytes and global value prove zero initialization in the active IDB.
- Do not represent [UID:000184] as a public source helper. It is constructor/static cleanup/unwind glue with a single state effect.
- Do not hand-edit `auto-generated/-ag-research-tracker.md` to repair the 12/2/10 row. The discrepancy should be resolved by accepted doc edits plus validator/autogen refresh or escalated as tooling state.

## Claim And Incorporation Ledger

| Claim ID | Target / Support | Action | Verification State | Proposed Change | Evidence |
| --- | --- | --- | --- | --- | --- |
| C-0000O7-01 | `by-file/StaticObjImageLib.md` | incorporate | applied | Added current family audit, four-marker disposition, generated/tracker mismatch note, zero-initialized singleton correction, and BuildTilec first-draft readiness. | Applied in `## 2026-07-01 B010 Empty-Emitter Family Implementation`; metadata now `88/88`; validator `000000003960` and final refresh `000000003967` both exited 0 with `ok: 1`. |
| C-0000O7-02 | `by-class/StaticObjImageLib.md` | incorporate | applied | Preserved `extern` declaration while stating [UID:0000SD] emits the definition, [UID:0001PP] is storage support, and [UID:0000U6] is first-draft body ready. | Applied in `Resource And Ownership Decisions`, method table row, and `Changes`; score unchanged `88/89`; validator `000000003961` exited 0 with `ok: 1`. |
| C-0000O7-03 | `by-global/g_pStaticObjImageLib.md` | incorporate | applied | Added `StaticObjImageLib *g_pStaticObjImageLib = 0;`, corrected stale sentinel wording, and raised to `88/91`. | Formal C++ block now contains the definition; `Source Definition And Storage Split` records zero-init proof; validator `000000003962` exited 0 with `ok: 1`. |
| C-0000O7-04 | `by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md` | incorporate | applied | Added no-duplicate storage comment, corrected bytes/value to zero, and raised to `88/91`. | Formal C++ block contains no-duplicate comment; Item Summary, Storage table, and Evidence Notes now show `00 00 00 00` / `0`; validator `000000003963` exited 0 with `ok: 1`. |
| C-0000O7-05 | `by-item/BuildTilecArchiveTable_004DDA60.md` | incorporate | applied | Added formal first-draft C++ body and raised to `89/91`. | Formal C++ block now contains `ArchiveMetadataTable *BuildTilecArchiveTable(const wchar_t *unusedArchiveName)` body; MCP proof and `BuildEffectArchiveTable` precedent documented; validator `000000003964` exited 0 with `ok: 1`. |
| C-0000O7-06 | `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md` | incorporate | applied | Added target-specific no-code cleanup-glue comment and raised to `86/91`. | Formal C++ block contains cleanup-glue no-code proof; evidence section records B010 size/disasm/decompile/EH xref proof; validator `000000003965` exited 0 with `ok: 1`. |
| C-0000O7-07 | `by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md` | incorporate | applied | Added support-only note for zero-initialized singleton and child BuildTilec source-form decision; did not duplicate child body. | Item Summary, Evidence Notes, State And Resource Map, Open Questions, and Changes updated; aggregate remains non-emitting `86/91`; validator `000000003966` exited 0 with `ok: 1`. |
| C-0000O7-08 | `by-item/EPFArchiveMetadataTable.md` | already-present | already-present | No content change required; declarations remain available for `ArchiveMetadataTable` and `PackedArchiveRecord`. | Confirmed current formal block contains `struct PackedArchiveRecord` and `struct ArchiveMetadataTable`; no edit needed. |
| C-0000O7-09 | `auto-generated/-ag-research-tracker.md` | excluded-with-reason | excluded-with-reason | Do not edit manually; validate/autogen refresh should reconcile or expose tracker staleness. | Generated tracker is validator-owned. After validators it changed from `12/2/10` to `12/6/6`, still stale against generated `StaticObjImageLib.cpp` showing no visible old empty markers. Reported as generated tracker freshness/tooling issue; no manual edit made. |

## Implementation Tracking Checklist

- [x] Update `by-file/StaticObjImageLib.md`: added B010 family audit, generated/tracker discrepancy, MCP provenance, four-marker dispositions, score `88/88`, and source-placement decisions. Proof: `## 2026-07-01 B010 Empty-Emitter Family Implementation`; validator `000000003960`, final refresh `000000003967`.
- [x] Update `by-class/StaticObjImageLib.md`: added support note that [UID:0000SD] emits the global definition, [UID:0001PP] is storage support, and [UID:0000U6] is first-draft body ready; kept class declaration only. Proof: `Resource And Ownership Decisions`, method table, and `Changes`; validator `000000003961`.
- [x] Update `by-global/g_pStaticObjImageLib.md`: added formal source definition `StaticObjImageLib *g_pStaticObjImageLib = 0;`, corrected stale sentinel text, and updated score to `88/91`. Proof: formal block and `Source Definition And Storage Split`; validator `000000003962`.
- [x] Update `by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md`: corrected bytes/value from `ff ff ff ff` / `0xffffffff` to `00 00 00 00` / `0`, added no-duplicate storage comment, and updated score to `88/91`. Proof: Item Summary, Storage table, Evidence Notes, formal block; validator `000000003963`.
- [x] Update `by-item/BuildTilecArchiveTable_004DDA60.md`: inserted the formal first-draft C++ body, documented sibling `BuildEffectArchiveTable` precedent and current MCP proof, and updated score to `89/91`. Proof: formal block and 2026-07-01 MCP section; validator `000000003964`.
- [x] Update `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md`: inserted the formal cleanup-glue no-code comment and updated score to `86/91`. Proof: formal block, Evidence, Reconstruction Notes, Score Rationale; validator `000000003965`.
- [x] Update `by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md`: added support-only note for zero singleton initialization and BuildTilec first-draft source-form; did not duplicate child body. Proof: Item Summary, Evidence Notes, State And Resource Map, Open Questions, Changes; validator `000000003966`.
- [x] Confirm `by-item/EPFArchiveMetadataTable.md` declarations remain available; no edit needed. Proof: current formal block still contains `struct PackedArchiveRecord` and `struct ArchiveMetadataTable`.
- [x] Run scoped validators after implementation:
  - `python .\tools\validator.py --mode file --file by-file/StaticObjImageLib.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-class/StaticObjImageLib.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-global/g_pStaticObjImageLib.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-item/BuildTilecArchiveTable_004DDA60.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md --apply --queue-timeout 240 --wait-generated`
- [x] After validators, verify `auto-generated/NexusTK/render/StaticObjImageLib.cpp` has no remaining old empty markers for [UID:0000SD], [UID:0001PP], [UID:0000U6], or [UID:000184]. Proof: header `validator-command-id: 000000003967`, `validator-refreshed-at: 2026-07-01T15:59:24-04:00`; `rg 'Empty Emitter Marker|UID:0000SD|UID:0001PP|UID:0000U6|UID:000184'` shows no empty markers, [UID:0000SD] definition emitted, [UID:0000U6] body emitted, [UID:000184] no-code comment emitted, and no stale [UID:0001PP] marker.
- [x] After validators, verify whether `auto-generated/-ag-research-tracker.md` refreshed away from the stale 12/2/10 row; if not, report a generated tracker freshness/tooling issue rather than editing the tracker. Proof: validator-owned tracker refreshed but now reports `12 | 6 | 6 | 50.0%` for [UID:0000O7], which remains stale against the generated file showing no old visible empty markers; no manual tracker edit was made.

## Validator Results

All commands were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--wait-generated`.

| Target | Command ID | Timestamp | Exit | ok | Generated refresh | Warnings / side effects |
| --- | --- | --- | ---: | ---: | --- | --- |
| `by-file/StaticObjImageLib.md` | `000000003960` | `2026-07-01T15:58:09-04:00` | 0 | 1 | completed, command `000000003960` | `missing_ref_uid 0003M2` twice; projected stats update; generated metadata refresh. |
| `by-class/StaticObjImageLib.md` | `000000003961` | `2026-07-01T15:58:20-04:00` | 0 | 1 | completed, command `000000003961` | `missing_ref_uid 0003M2` twice; projected stats update; generated metadata refresh. |
| `by-global/g_pStaticObjImageLib.md` | `000000003962` | `2026-07-01T15:58:30-04:00` | 0 | 1 | completed, command `000000003962` | research tracker update; projected stats update; generated metadata refresh. |
| `by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md` | `000000003963` | `2026-07-01T15:58:41-04:00` | 0 | 1 | completed, command `000000003963` | registry hash update; projected stats update; generated metadata refresh. |
| `by-item/BuildTilecArchiveTable_004DDA60.md` | `000000003964` | `2026-07-01T15:58:52-04:00` | 0 | 1 | completed, command `000000003964` | stats row update for `0000U6`; projected stats update; generated metadata refresh. |
| `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md` | `000000003965` | `2026-07-01T15:59:03-04:00` | 0 | 1 | completed, command `000000003965` | registry hash update; projected stats update; generated metadata refresh. |
| `by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md` | `000000003966` | `2026-07-01T15:59:13-04:00` | 0 | 1 | completed, command `000000003966` | `missing_ref_uid 0003M2` three times; research tracker update; projected stats update; generated metadata refresh. |
| final generated freshness refresh, `by-file/StaticObjImageLib.md` | `000000003967` | `2026-07-01T15:59:24-04:00` | 0 | 1 | completed, command `000000003967` | `missing_ref_uid 0003M2` twice; generated C++ header now equals this command. |

The earlier full validator batch also ran the same listed validators as command IDs `000000003953` through `000000003959`, all exit 0 with `ok: 1`. The compact pass above is the final proof set.

## Generated Output Verification

- `auto-generated/NexusTK/render/StaticObjImageLib.cpp` header:
  - `validator-command-id: 000000003967`
  - `validator-refreshed-at: 2026-07-01T15:59:24-04:00`
  - This equals the final generated freshness command metadata, so generated output is current for this implementation.
- Old visible empty markers for [UID:0000SD], [UID:0001PP], [UID:0000U6], and [UID:000184] are gone.
- Generated source now includes:
  - [UID:0000SD] `StaticObjImageLib *g_pStaticObjImageLib = 0;`
  - [UID:0000U6] full `BuildTilecArchiveTable` first-draft body.
  - [UID:000184] cleanup-glue no-code comment.
  - No stale [UID:0001PP] empty marker; the no-duplicate exact-storage disposition remains documented in its by-memory page and source definition emits from [UID:0000SD].
- `auto-generated/-ag-research-tracker.md` is still not semantically aligned with generated source: it now reports [UID:0000O7] as `12 | 6 | 6 | 50.0%` instead of the prior `12 | 2 | 10 | 16.7%`, while the generated file visibly has no old empty markers for the audited UIDs. This is a validator/generated tracker freshness or indexing issue for supervisor/tool follow-up; B010 did not edit the tracker manually.

## Lease And Scope Verification

- Leases acquired as B010 for immediate edit/validator batch:
  - `by-file\StaticObjImageLib.md`
  - `by-class\StaticObjImageLib.md`
  - `by-global\g_pStaticObjImageLib.md`
  - `by-memory\0x0069b448-0x0069b44c.g_pStaticObjImageLib.md`
  - `by-item\BuildTilecArchiveTable_004DDA60.md`
  - `by-memory\0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md`
  - `by-memory\0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md`
- Release command after validators returned `Rejected[No active lease]` for each path, meaning the short leases had already expired before cleanup.
- Current lease report shows no active B010 leases.
- No generated files, generated reports, project-level reports, manual coverage reports, validator/tool state, queue files, archives, supervisor ledgers, by-project-structure docs, or IDA DB were manually edited. Validator-owned generated/tool-state side effects are recorded above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0000O7-StaticObjImageLib-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0000O7-StaticObjImageLib-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T16:02:53","uid":"0000O7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
