** TARGET-REPORT-UID:0002KT **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# 0002KT ResourceLayoutRawRecordGetEntryRect Source-Quality Report

Report state: implementation callback completed and report text repaired for fresh supervisor Gate 1 section validation. The initial research pass was report-only; the later approved callback edited the target/support by-* docs listed in the checklist and ran the scoped validators recorded below. Generated files, coverage reports, validator state, archives, lifecycle state, supervisor files, and manual report moves were not edited or run by Agent-B013.

## Target

- UID: `0002KT`
- Target doc: `by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md`
- Function: `sub_4D05A0`
- Address range: `0x004d05a0-0x004d05e6`
- Current direct owner: [UID:0000N5] `by-file/ResourceLayoutTable.md`
- Current generated placement: file-level ResourceLayout raw-helper group, projected to `NexusTK/render/ResourceLayoutTable.cpp`

## Current Target State

Current target metadata:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000N5`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000N5`
- `RECONSTRUCTION_CPP CODE` blank

Current page state is mostly accurate: it already documents the exact half-open range, the raw 24-byte record helper behavior, the signed-index caveat, no callees, two modeled NewHuman composition callsites, 24 orphan old-human xrefs, two orphan NewHuman gap xrefs, and rejection of class/caller ownership.

This pass finds an implementation improvement: the first-draft C++ blocker for UID0002KT is now narrow enough to resolve at target-doc level. The function is small, self-contained, returns the output rect pointer, uses already accepted `RectBounds` / `ResourceLayoutEntry` source-facing names, and is already called from accepted UID0002V8 formal C++ as `ResourceLayoutRawRecordGetEntryRect`.

## Evidence Checked

Workflow and local documentation checked:

- Read `Agent-B013/goal.md`, which requires report-only work, exact headings, existing-report search, current IDA MCP evidence, ownership/source-placement reanalysis, and no by-* edits.
- Used project-level `ntk-b-agent-workflow` and the B-agent research/implementation workflow reference.
- Read the score-blocker audit standard and applied its requirement to either resolve the C++ blocker or leave a target-specific no-code proof.
- Read target doc `by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md`.
- Read owner/support docs: `by-file/ResourceLayoutTable.md`, `by-class/ResourceLayoutTable.md`, `by-file/ImageLib.md`, `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md`, `by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md`, `by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md`, `by-item/ResourceLayoutEntry.md`, `by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md`, `by-file/NewHumanImageLib.md`, `by-file/HumanImageLib.md`, `by-memory/0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md`, and `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`.
- Searched existing reports and notes for `0002KT`, `0x004d05a0`, `004D05A0`, `ResourceLayoutRawRecordGetEntryRect`, and `sub_4D05A0`. Relevant matches were B001 ResourceLayoutTable aggregate, B011 ImageLib empty-emitter family, B014 NewHuman composition-bounds, and B010 companion UID0002KQ raw-buffer report.

Current IDA MCP evidence, using schema-current narrow calls:

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active session: `supervisor_resume_20260629`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- `idb_list`: one active session, `is_analyzing:false`, `owned:true`, `adopted:true`, backend `worker`.
- `server_health(database=supervisor_resume_20260629)`: `status:ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- `lookup_funcs(database, queries=[0x004d059b,0x004d05a0,0x004d05e5,0x004d05e6,0x004d05f0,0x004d0530,0x004d03a0])`: `0x004d05a0 -> sub_4D05A0 size 0x46`; terminal byte `0x004d05e5` is inside the function; exclusive end `0x004d05e6` is not a function; predecessor gap start `0x004d059b` is not a function; successor `0x004d05f0 -> sub_4D05F0`; sibling `0x004d0530 -> sub_4D0530`; companion raw helper `0x004d03a0 -> sub_4D03A0`.
- `export_funcs(database, addrs=[0x004d05a0], format=json)`: prototype artifact `_DWORD *__stdcall(unsigned __int16 *, int, _DWORD *)`, size `0x46`, decompiler body, assembly, and xrefs.
- `callees(database, addrs=[0x004d05a0], limit=20)`: empty callee set.
- `basic_blocks(database, addrs=[0x004d05a0], max_blocks=20, offset=0)`: three blocks, starts `0x004d05a0`, `0x004d05b0`, `0x004d05c4`.
- `xrefs_to(database, addrs=[0x004d05a0], limit=40)`: 28 direct code xrefs, no more pages.
- `decompile(database, addr=0x004d05a0, include_addresses=false)`: returns `_DWORD *__stdcall sub_4D05A0(unsigned __int16 *a1, int a2, _DWORD *a3)` and the exact `a2 >= *a1` / copy-or-zero body.
- `disasm(database, addr=0x004d05a0, max_instructions=80, offset=0, include_total=true)`: 21 instructions, complete function.
- `get_bytes(database, regions=[0x004d059b size 5, 0x004d05a0 size 16, 0x004d05e0 size 16, 0x004d05e6 size 10])`: predecessor gap is five `0xcc`; function starts `55 8b ec 8b 55 08 ...`; tail contains `5d c2 0c 00`; successor padding `0x004d05e6-0x004d05f0` is ten `0xcc`.

## Positive Evidence Summary

Live MCP reconfirms exact range and body:

- The function is `sub_4D05A0`, `0x46` bytes, half-open range `0x004d05a0-0x004d05e6`.
- Disassembly has 21 instructions and three basic blocks.
- The function returns with `retn 0Ch`, matching three stack arguments and no `this` receiver.
- The decompiler's return type artifact is `_DWORD *`; assembly sets `eax = output` in both valid and invalid branches before returning, so a source-facing `RectBounds *` return is supported.
- The helper has no static callees.
- The valid branch loads a zero-extended 16-bit count from `rawTable[0]`, compares signed `entryIndex` against that count, loads the entry pointer from raw-table offset `+8`, scales the index as `24 * entryIndex`, and copies 16 bytes with `movups`.
- The invalid branch clears the output rectangle fields. Assembly writes bottom/top/right/left order (`+0x0c`, `+0x04`, `+0x08`, `+0x00`), but the source-visible result is all-zero bounds.

The raw layout is now concrete enough for first-draft C++:

- Raw table header fields used by this helper are only `entryCount` at offset `+0x00` as unsigned 16-bit and `entries` at offset `+0x08` as a pointer to 24-byte rows.
- The row layout is already accepted in [UID:0000VB] `ResourceLayoutEntry`: `left`, `top`, `right`, `bottom`, `pixelData`, `encodedMaskData`.
- [UID:0002KS] `ResourceLayoutTable::GetEntryRect` already emits first-draft code using `RectBounds` and `ResourceLayoutEntry` for the class-backed version of the same rectangle-copy operation.
- [UID:0002V8] accepted first-draft C++ already calls `ResourceLayoutRawRecordGetEntryRect(g_pRidingImageLib->m_rawRecordTable, ..., &partBounds)`, so the target helper spelling and parameter role are no longer speculative at a report-blocking level.

The caller set is strong consumer evidence:

- Live `xrefs_to` reports the two modeled callsites inside UID0002V8 at `0x004e33a4` and `0x004e394c`.
- Live `xrefs_to` reports two NewHuman gap callsites at `0x004e3cc9` and `0x004e4025`.
- Live `xrefs_to` reports 24 old-human orphan callsites from `0x004d8140` through `0x004d8e5a`.
- Existing old/new human support pages document the common call pattern: caller pushes a stack output rect, adjusted overlay/resource index, and caller-provided raw layout table pointer, then optionally unions or copies the result.

Boundary evidence is clean:

- Predecessor `0x004d0530-0x004d059b` is UID0002KS `ResourceLayoutTableGetEntryRect`.
- `0x004d059b-0x004d05a0` is exactly five `0xcc` bytes.
- Successor padding `0x004d05e6-0x004d05f0` is exactly ten `0xcc` bytes before `sub_4D05F0`.
- No split or range extension is supported.

## Negative Evidence Summary

No evidence supports class-method ownership:

- The function uses `__stdcall`-style stack arguments and returns with `retn 0Ch`.
- There is no `this` receiver, no access to `this+0x0c`, no lazy `FindResourceIndex` / `LoadResourceIndex` path, and no `List::GetElementAt`.
- [UID:0000BY] `ResourceLayoutTable` correctly excludes UID0002KT from the class method inventory while using it as support context.

No evidence supports ImageLib direct ownership:

- [UID:0000K2] `ImageLib` owns lifecycle and class-backed ResourceLayout methods through the singleton/facet route.
- B011 explicitly excludes raw helpers UID0002KQ and UID0002KT from the ImageLib empty-emitter family.
- The target consumes a caller-provided raw table pointer, not `g_pEPFLib` directly.

No evidence supports HumanImageLib or NewHumanImageLib ownership:

- Human/NewHuman pages provide callsite context only. They consume the shared raw rectangle helper for composition overlays.
- The 24 old-human xrefs are all orphan/no-function callsite entries in the current IDB, not modeled methods that can claim the helper.
- The two modeled NewHuman calls sit inside UID0002V8, whose accepted C++ treats this target as an external `ResourceLayoutRawRecordGetEntryRect` dependency.
- The two NewHuman gap xrefs remain unmodeled local composition material and do not change helper ownership.

No evidence supports moving this helper into the mixed aggregate:

- [UID:000174] `0x004d0120-0x004d182f.ResourceLayoutTable` is a non-emitting mixed inventory spanning ResourceLayout class methods, raw helpers, ImageDecodeWrappers, ImageFrameTable helpers, and padding.
- UID0002KT is an exact child page with clean boundaries and should not be emitted from the aggregate.

Remaining caveat for first-draft C++:

- The original raw-table type name is not proven. The report recommendation should therefore use a target-specific lightweight source-facing raw-table view name and preserve that it is inferred from offset evidence.
- The signed-index caveat must not be "fixed" in source: negative `entryIndex` values are not rejected by the binary and must continue to take the copy path when `entryIndex < entryCount`.

## Heuristic / Inference Reanalysis And Validation

The previous blocker was mainly final helper spelling/raw table naming plus orphan old/new human caller ranges. Current support has reduced those from blockers to caveats.

Helper spelling is now validated enough for first-draft use because UID0002V8 already emits formal source that calls `ResourceLayoutRawRecordGetEntryRect`. That accepted caller body does not prove the original symbol spelling, but it proves the project source-facing name is stable enough to use consistently.

The raw layout is target-specific and byte-proven. The helper does not need a full parser or lifetime model: it only needs a two-field raw table view (`entryCount`, `entries`) and accepted `ResourceLayoutEntry` rows. Unlike UID0002KQ, there is no uninitialized next-row/mask-size read and no allocator/source-form ambiguity inside this target body.

The signed-index behavior is deliberate for reconstruction purposes: assembly uses `movzx eax, word ptr [edx]`, `cmp ecx, eax`, `jge zero`. With a signed `int entryIndex`, negative values pass the `< entryCount` test and index before the entries pointer. Current caller docs say known callers compute nonnegative overlay indexes before the call; the helper itself still does not enforce nonnegative range. The C++ must use `if (entryIndex < static_cast<int>(table->entryCount))` and must not add `entryIndex >= 0`.

The orphan old/new human xrefs are not a reason to keep the body blank. They are source placement/caller-coverage caveats, not internal behavior blockers. All xrefs call the same no-callee helper shape, and no xref alters the target's function body, range, owner, or parameter order.

## Ranked Ownership Analysis

1. [UID:0000N5] `by-file/ResourceLayoutTable.md`: strongest direct owner. The target is a no-`this` file-level ResourceLayout raw helper in the same address/source-family neighborhood as the class-backed ResourceLayout methods, consumes the accepted 24-byte `ResourceLayoutEntry` row format, and mirrors the class-backed `GetEntryRect` rectangle-copy behavior over caller-provided raw storage.
2. [UID:0000BY] `by-class/ResourceLayoutTable.md`: strong semantic support but rejected as direct owner. It owns the class/facet methods and deliberately excludes UID0002KT because the target has no `this`, no list lookup, and no lazy resource load path.
3. [UID:0000K2] `by-file/ImageLib.md`: broader ImageLib/ResourceLayout singleton context only. B011 keeps raw helpers out of the ImageLib empty-emitter family; UID0002KT should not be moved there.
4. [UID:000092] / [UID:0000LR] `NewHumanImageLib`: modeled caller/consumer only. UID0002V8 has two formal calls but treats the helper as external ResourceLayout raw-record support.
5. [UID:00006A] / [UID:0000JY] `HumanImageLib`: old-human consumer only. The 24 xrefs are in orphan old-human composition code and do not prove helper ownership.
6. [UID:000174] `0x004d0120-0x004d182f.ResourceLayoutTable` aggregate: inventory/support only. It remains non-emitting because the broader range mixes unrelated children and padding.
7. Generated Ranking/callsite ownership: rejected. Call count and generated ranking would favor human-image consumers, but the helper's body, calling convention, accepted row type, class-backed sibling relation, and file-level ResourceLayout route are stronger than consumer callsite volume.

## Source Placement

Keep UID0002KT under [UID:0000N5] `ResourceLayoutTable` as a file-local/static raw helper in `NexusTK/render/ResourceLayoutTable.cpp`.

Do not move it to `ResourceLayoutTable::GetEntryRect`: UID0002KS is the class-backed method at `0x004d0530-0x004d059b`, and this target starts only after five bytes of padding at `0x004d05a0`.

Do not move it to `NewHumanImageLib.cpp` or `HumanImageLib.cpp`: those files are consumers. Their composition code supplies raw layout table pointers and overlay indexes, but the helper source-family is ResourceLayout raw-record access.

Do not attach it to the non-emitting `0x004d0120-0x004d182f` aggregate. The exact child page owns the source-bearing body.

## Score And Metadata Recommendation

Recommended metadata:

- Raise `COMPLETION:85` to `COMPLETION:88`.
- Raise `CONFIDENCE:88` to `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000N5`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000N5`.

Rationale for score raise: the target has current MCP-backed boundary, body, no-callee, xref, prototype, block, and byte evidence; accepted support docs now provide `RectBounds`, `ResourceLayoutEntry`, sibling method semantics, and source-facing helper spelling from UID0002V8. The prior blank-C++ blocker is resolved for this specific target.

Rationale for not going higher: the original raw-table type name remains inferred, the old-human and NewHuman gap xrefs remain orphan callsite material, and the final original source placement within `ResourceLayoutTable.cpp` versus nearby file-local helper region is still reconstructed from binary/source-family evidence rather than source file text.

## First-Draft C++ Recommendation

Add first-draft formal C++ to the target. The code must be byte-faithful on the signed-index caveat and must not add a negative-index guard.

Exact recommended `RECONSTRUCTION_CPP CODE` insertion text:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ResourceLayoutRawRecordTable
{
    unsigned short entryCount;
    unsigned short reserved0;
    unsigned int reserved1;
    const ResourceLayoutEntry *entries;
};

static RectBounds *ResourceLayoutRawRecordGetEntryRect(
    const ResourceLayoutRawRecordTable *table,
    int entryIndex,
    RectBounds *bounds)
{
    if (entryIndex < static_cast<int>(table->entryCount))
    {
        const ResourceLayoutEntry *entry = &table->entries[entryIndex];

        bounds->left = entry->left;
        bounds->top = entry->top;
        bounds->right = entry->right;
        bounds->bottom = entry->bottom;
    }
    else
    {
        bounds->left = 0;
        bounds->top = 0;
        bounds->right = 0;
        bounds->bottom = 0;
    }

    return bounds;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

No-code proof is not recommended because this target no longer has a behavior blocker. The above body preserves:

- three-argument stack helper shape as a file-local `static` function;
- output pointer return through `RectBounds *`;
- raw table count at `+0x00`;
- entries pointer at `+0x08`;
- 24-byte `ResourceLayoutEntry` stride;
- first 16-byte rectangle copy only;
- zero output on `entryIndex >= entryCount`;
- negative-index pass-through when callers ever supply `entryIndex < 0`.

The raw table struct name is a source-facing inferred support name. If the supervisor prefers not to introduce a struct in this function block, the mechanically equivalent fallback is to keep the first parameter as `const unsigned short *rawTable` and load the entries pointer from byte offset `+8`; however, the struct form is clearer and matches the current support-doc style for inferred first-draft layouts.

## Recommended Target Doc Changes

Accepted and implemented target doc changes for `by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md`:

- Update metadata to `COMPLETION:88`, `CONFIDENCE:90`, keeping `CANONICAL_OWNER:0000N5`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000N5`.
- Insert the exact first-draft C++ block above.
- Add current MCP evidence from `supervisor_resume_20260629`: health/session state; `lookup_funcs` exact boundary and adjacent non-function/function results; prototype artifact `_DWORD *__stdcall(unsigned __int16 *, int, _DWORD *)`; no callees; three basic blocks; 21 instructions; decompiler copy/zero body; 28 xrefs; boundary bytes around `0x004d059b-0x004d05a0` and `0x004d05e6-0x004d05f0`.
- Preserve and sharpen the signed-index caveat: known callers appear nonnegative, but the helper itself does not reject negative `entryIndex`.
- Preserve split/range facts: predecessor UID0002KS owns `0x004d0530-0x004d059b`; `0x004d059b-0x004d05a0` is padding; target owns `0x004d05a0-0x004d05e6`; `0x004d05e6-0x004d05f0` is padding before successor `sub_4D05F0`.
- Preserve current ownership route and explicitly reject class, ImageLib, HumanImageLib, NewHumanImageLib, mixed aggregate, and generated ranking/callsite ownership.
- Record that UID0002V8 formal C++ already uses the helper spelling and `m_rawRecordTable` argument role.

Callback state: applied. The target doc was edited, validated with command_id `000000004643` at `2026-07-02T16:09:15-04:00`, exit code `0`, ok `1`, no warnings reported, `generated_refresh: deferred`.

## Recommended Support Doc Changes

Accepted support-doc disposition and callback results:

- `by-file/ResourceLayoutTable.md`: edited during callback because direct consistency verification found stale ownership/C++ readiness wording after UID0002KT began emitting first-draft formal C++. The edit states that UID0002KT now emits as a file-level raw helper while UID0002KQ remains blank due to its separate raw-buffer next-row/mask-size blocker. Validator command_id `000000004644`, command_timestamp `2026-07-02T16:09:23-04:00`, exit code `0`, ok `1`, no warnings reported, `generated_refresh: deferred`.
- `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md`: edited during callback because the UID0002KT row/status would have become stale after target emission. The edit refreshes only the UID0002KT child-specific C++ readiness wording and keeps the aggregate non-emitting. Validator command_id `000000004645`, command_timestamp `2026-07-02T16:09:23-04:00`, exit code `0`, ok `1`, no warnings reported, `generated_refresh: deferred`.
- `by-class/ResourceLayoutTable.md`: verified read-only during callback; no edit required because it already excludes UID0002KT from the class method inventory and keeps class-backed UID0002KS separate.
- `by-item/ResourceLayoutEntry.md`: verified read-only during callback; no edit required because it already defines the 24-byte row and documents this helper's row-copy context.
- `by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md`: verified read-only during callback; no edit required because it already uses the helper spelling and callsites.

Generated output was inspected read-only after validation: `auto-generated/NexusTK/render/ResourceLayoutTable.cpp` header shows validator-command-id `000000004644` and refreshed-at `2026-07-02T16:09:23-04:00`, equal/newer than target validator command `000000004643`; the generated output contains the UID0002KT C++ body. Generated files were not manually edited.

## Claim And Incorporation Ledger

| Claim | Confidence / Evidence | Destination doc / section | Action | Verification state |
| --- | --- | --- | --- | --- |
| UID0002KT is exactly `0x004d05a0-0x004d05e6`; filename, title, and range should not change. | High. Live MCP `lookup_funcs` in session `supervisor_resume_20260629` reports `0x004d05a0 -> sub_4D05A0 size 0x46`; `0x004d05e5` is inside the function and `0x004d05e6` is not a function. Current target filename already uses the correct half-open range. | `by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md` metadata/title/range evidence. | incorporate | applied |
| Predecessor UID0002KS and successor `sub_4D05F0` are separate; no split, merge, or range extension is supported. | High. Live `lookup_funcs` reports `0x004d0530 -> sub_4D0530 size 0x6b`, `0x004d059b` not a function, `0x004d05e6` not a function, and `0x004d05f0 -> sub_4D05F0`; live `get_bytes` reports five `0xcc` bytes at `0x004d059b-0x004d05a0` and ten `0xcc` bytes at `0x004d05e6-0x004d05f0`. | Target boundary/split notes and `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md` child row/status. | incorporate | applied |
| Metadata should become `COMPLETION:88`, `CONFIDENCE:90`, with `CANONICAL_OWNER:0000N5`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000N5` preserved. | High for owner/reconstructable/emitter, medium-high for exact score. Body, caller, ownership, type, and source-shape evidence now support first-draft C++; confidence stays below final due to inferred raw-table type name and orphan caller ranges. | Target metadata block. | incorporate | applied |
| The helper is a three-argument `__stdcall` raw ResourceLayout helper, not a `ResourceLayoutTable` class method. | High. Live prototype artifact `_DWORD *__stdcall(unsigned __int16 *, int, _DWORD *)`, `retn 0Ch`, no `this` fields, no `FindResourceIndex`/`LoadResourceIndex`, no `List::GetElementAt`, and no access to `this+0x0c`. | Target calling-convention/ownership evidence; direct class-method route rejected in target ownership section. | incorporate | applied |
| File-level [UID:0000N5] `ResourceLayoutTable` is the direct owner. | High. Target consumes accepted `ResourceLayoutEntry` rows, mirrors sibling `GetEntryRect` behavior over raw storage, sits in the ResourceLayout helper neighborhood, and B011 excludes raw helpers from ImageLib empty-emitter ownership. | Target ownership/source-placement sections and `by-file/ResourceLayoutTable.md` support refresh. | incorporate | applied |
| [UID:0000BY] `ResourceLayoutTable` class is support context, not direct owner. | High. Class page already excludes UID0002KT because the helper has no `this`; class-backed UID0002KS remains the method body. | Verified `by-class/ResourceLayoutTable.md`; target also repeats the rejection. | already-present | already-present |
| [UID:0000K2] `ImageLib`, [UID:000092]/[UID:0000LR] `NewHumanImageLib`, [UID:00006A]/[UID:0000JY] `HumanImageLib`, mixed aggregate UID000174, and generated Ranking/callsite ownership are rejected as direct owners. | High. B011 excludes UID0002KT from ImageLib empty-emitter family; live xrefs show NewHuman and old-human callsites are consumers; UID000174 remains non-emitting mixed inventory; call volume does not override body/source-family evidence. | Target ownership notes and support refresh in UID000174. | incorporate | applied |
| Live MCP evidence should be incorporated at report-level specificity. | High. Current calls captured health/session state, exact lookup results, prototype artifact, empty callee set, three basic blocks, 21-instruction disassembly, decompiler copy/zero body, 28 xrefs, and boundary bytes. | Target evidence, boundary, raw code, caller, and change sections. | incorporate | applied |
| Callee set is empty and body is a small copy-or-zero helper. | High. Live `callees` returns `[]`; `basic_blocks` returns three blocks; `disasm` returns 21 instructions; `decompile` returns the `if (a2 >= *a1) zero else copy 16 bytes from *((DWORD*)a1+2)+24*a2` body. | Target raw code evidence and formal-C++ rationale. | incorporate | applied |
| Raw table layout used by this helper is count at `+0x00`, entries pointer at `+0x08`, and 24-byte `ResourceLayoutEntry` rows. | High for offsets/stride, medium for source-facing raw-table type name. Disassembly uses `movzx word ptr [edx]`, `mov eax,[edx+8]`, `lea ecx,[ecx+ecx*2]`, and `[eax+ecx*8]`; [UID:0000VB] defines 24-byte `ResourceLayoutEntry`. | Target behavior notes and C++ block. | incorporate | applied |
| Signed-index caveat must be preserved; do not add `entryIndex >= 0`. | High. Assembly uses signed `jge` after zero-extending the 16-bit count, so negative indexes pass the valid branch when `entryIndex < entryCount`. Known callers appear to supply nonnegative overlay indexes, but the helper itself does not enforce that. | Target behavior notes, formal C++ condition, and change entry. | incorporate | applied |
| The formal first-draft C++ block should be inserted, or a supervisor-approved equivalent must preserve the same parameter order, return value, raw layout, zero path, and signed-index behavior. | Medium-high. Accepted `RectBounds`, `ResourceLayoutEntry`, UID0002KS sibling body, UID0002V8 helper spelling, and no internal unresolved behavior support first-draft source. Raw-table struct name remains inferred. | Target `RECONSTRUCTION_CPP CODE` block and generated `auto-generated/NexusTK/render/ResourceLayoutTable.cpp`. | incorporate | applied |
| UID0002V8 already uses the source-facing helper spelling and `m_rawRecordTable` argument role. | High. Current UID0002V8 formal C++ contains calls to `ResourceLayoutRawRecordGetEntryRect(g_pRidingImageLib->m_rawRecordTable, ..., &partBounds)` at the two modeled callsites. | Target naming/source-quality notes; UID0002V8 verified read-only. | incorporate | applied |
| `by-file/ResourceLayoutTable.md` currently has the correct ownership route but may need a direct consistency refresh if target C++ starts emitting. | Medium. Current file page already owns UID0002KT as a raw helper; callback found and corrected stale C++/ownership uncertainty wording. | `by-file/ResourceLayoutTable.md`. | incorporate | applied |
| `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md` currently has correct aggregate non-emitting status but may need a direct consistency refresh for UID0002KT row wording. | Medium. Current aggregate row identifies UID0002KT as raw helper and keeps aggregate non-emitting; callback refreshed child-specific C++ readiness wording. | `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md`. | incorporate | applied |
| `by-class/ResourceLayoutTable.md`, `by-item/ResourceLayoutEntry.md`, and `by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md` do not require edits unless callback verification finds directly stale text. | High. These docs already exclude UID0002KT from class ownership, define the 24-byte row, and use the helper name/calls respectively. | Verified read-only; no edits required. | already-present | already-present |
| Companion UID0002KQ should remain distinct and blank because its raw-buffer next-row/mask-size blocker is different from UID0002KT. | High. B010 report for UID0002KQ documents the unresolved `malloc` plus `entries[1].pixelData` mask-size issue; UID0002KT has no analogous allocator/next-row issue. | Target comparison note and `by-file/ResourceLayoutTable.md` support refresh. | incorporate | applied |
| Generated files, coverage reports, validator state, archives, supervisor files, lifecycle state, and manual report moves are out of scope for this report and callback. | High. Assignment explicitly forbids them; B-agent workflow reserves report execution/archive for supervisor. | No by-* destination; generated output inspected read-only for freshness only. | not-applicable | excluded-with-reason |

## Implementation Tracking Checklist

- [x] Read and followed updated `Agent-B013/goal.md`.
- [x] Used project-level `ntk-b-agent-workflow` skill.
- [x] Initial research pass was report-only; no by-* docs were edited until the later supervisor-approved implementation callback.
- [x] During the implementation callback, edited only the approved by-* target/support docs listed below.
- [x] Did not edit generated files, coverage reports, validator state, archives, lifecycle files, or supervisor files.
- [x] Did not run `execute_report`, dry-run/probing variants, lifecycle/archive commands, registry lifecycle commands, or manual report moves.
- [x] Searched existing reports and support docs for UID/range/name/IDA-name/source-family evidence.
- [x] Used current MCP session `supervisor_resume_20260629` with narrow, schema-current calls.
- [x] Included standalone `## Ranked Ownership Analysis`.
- [x] Included standalone `## Source Placement`.
- [x] Repaired the report to include standalone `## Recommended Target Doc Changes` and `## Recommended Support Doc Changes` sections with concrete callback-state content.
- [x] Included target-specific first-draft C++ recommendation.

Callback implementation status:

- [x] Acquired short edit leases for `by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md`, `by-file/ResourceLayoutTable.md`, and `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md` as B013 immediately before editing; release performed after validation batch.
- [x] Edited target doc `by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md`.
- [x] Edited support doc `by-file/ResourceLayoutTable.md` because callback verification found directly stale ownership/C++ readiness wording for UID0002KT; preserved UID0002KQ's separate blank-C++ blocker.
- [x] Edited support doc `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md` because callback verification found the UID0002KT row/status would be stale after target emission; kept the aggregate non-emitting.
- [x] Verified support docs `by-class/ResourceLayoutTable.md`, `by-item/ResourceLayoutEntry.md`, and `by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md` read-only; no direct stale consistency issue requiring edit was found.
- [x] In the target metadata, changed `COMPLETION:85` to `COMPLETION:88` and `CONFIDENCE:88` to `CONFIDENCE:90`; preserved `CANONICAL_OWNER:0000N5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N5`, and existing filename/range.
- [x] Inserted the first-draft `RECONSTRUCTION_CPP CODE` body between the existing target `BEGIN`/`END` markers only; no duplicate marker lines were inserted. The code preserves `RectBounds *` return, file-local/static helper shape, raw count at `+0x00`, entries pointer at `+0x08`, 24-byte `ResourceLayoutEntry` stride, zero path for `entryIndex >= entryCount`, and no `entryIndex >= 0` guard.
- [x] Added current MCP session evidence to the target at report-level specificity: `supervisor_resume_20260629` health/session state, `lookup_funcs` boundary/neighbor results, export prototype artifact `_DWORD *__stdcall(unsigned __int16 *, int, _DWORD *)`, empty callee set, three basic blocks, 21-instruction disassembly, decompiler copy/zero body, 28 direct code xrefs, and boundary bytes for `0x004d059b-0x004d05a0` and `0x004d05e6-0x004d05f0`.
- [x] Added target behavior notes for raw table layout: unsigned 16-bit count at offset `+0x00`, entries pointer at offset `+0x08`, 24-byte `ResourceLayoutEntry` rows, first 16-byte rectangle copy, and four-field zero output.
- [x] Added signed-index caveat in the target: assembly uses signed `jge` after zero-extending the count; known callers appear nonnegative, but the helper itself does not reject negative indexes and the C++ preserves that.
- [x] Refreshed target xref/caller notes: 24 old-human orphan callsites `0x004d8140` through `0x004d8e5a`, two modeled UID0002V8 callsites `0x004e33a4` and `0x004e394c`, and two NewHuman gap callsites `0x004e3cc9` and `0x004e4025`.
- [x] Added target ownership reanalysis: file-level UID0000N5 owner; rejected UID0000BY class direct ownership, ImageLib ownership, HumanImageLib/NewHumanImageLib caller ownership, UID000174 mixed aggregate ownership, and generated Ranking/callsite ownership.
- [x] Preserved target split/range facts: predecessor UID0002KS owns `0x004d0530-0x004d059b`; `0x004d059b-0x004d05a0` is five-byte padding; UID0002KT owns `0x004d05a0-0x004d05e6`; `0x004d05e6-0x004d05f0` is ten-byte padding before successor `sub_4D05F0`; no split or merge.
- [x] Did not edit generated reports, generated C++, manual `-coverage-report.md` files, validator state, archives, lifecycle files, supervisor ledgers, or unrelated support docs.
- [x] Ran target validator from `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-memory\0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md --apply --queue-timeout 240`; command_id `000000004643`, command_timestamp `2026-07-02T16:09:15-04:00`, exit code `0`, ok `1`, warnings none reported, generated_refresh `deferred`.
- [x] Ran support validator for `by-file\ResourceLayoutTable.md`: command_id `000000004644`, command_timestamp `2026-07-02T16:09:23-04:00`, exit code `0`, ok `1`, warnings none reported, generated_refresh `deferred`.
- [x] Ran support validator for `by-memory\0x004d0120-0x004d182f.ResourceLayoutTable.md`: command_id `000000004645`, command_timestamp `2026-07-02T16:09:23-04:00`, exit code `0`, ok `1`, warnings none reported, generated_refresh `deferred`.
- [x] Checked generated output freshness read-only: `auto-generated/NexusTK/render/ResourceLayoutTable.cpp` header shows validator-command-id `000000004644` and refreshed-at `2026-07-02T16:09:23-04:00`, which is equal/newer than target validator command `000000004643`; generated output contains the UID0002KT C++ body.
- [x] Updated this report's `## Claim And Incorporation Ledger` with callback states: accepted rows are `applied`, already-present support rows are `already-present`, and out-of-scope generated/lifecycle/manual edits are `excluded-with-reason`.
- [x] Updated this checklist with checked-off proof for each applied/already-present/excluded item.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004679","destination_path":"executed-b-agent-research/B013/0002KT-ResourceLayoutRawRecordGetEntryRect-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0002KT-ResourceLayoutRawRecordGetEntryRect-source-quality.md","timestamp":"2026-07-02T16:29:53-04:00","uid":"0002KT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
