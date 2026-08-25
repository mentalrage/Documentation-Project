** TARGET-REPORT-UID:0000UQ **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0000UQ GetItemGlyphBounds Source-Quality Report

## Finalized Report / Current Recommendation

Implementation callback has been applied for [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](../../../../../by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md). The target is ready for supervisor Gate 2 review.

Applied target metadata:

- `COMPLETION:90`
- `CONFIDENCE:92`
- Keep `CANONICAL_OWNER:0000KH`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KH`, and blank `EMITTER_POSITION_OPTIONAL` unchanged.

Applied disposition: source-authored free item-image helper in `NexusTK/render/ItemObjImageLib.cpp`, not an `ItemObjImageLib` instance method. Current MCP closes the prior behavior blockers enough to emit first-draft formal C++ for the exact helper body. The remaining caveats are final original helper spelling, final public type of `g_pEPFLib`, and exact original spelling of `OffsetRect`; those are support-level caveats already tolerated in comparable first-draft render/UI bodies.

Gate 1 report-only restrictions were satisfied before callback. During implementation, manual edits were limited to the authorized target and this research report. No support docs, generated files, coverage reports, lifecycle/archive files, supervisor ledgers, or executed-report locations were manually edited. No `execute_report`, dry-run/probing variant, lifecycle command, registry lifecycle command, report-move command, or archive command was run.

## Target

- Target UID: `0000UQ`
- Target path: [by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md](../../../../../by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md)
- Target address range: `0x004df460-0x004df4f9`
- Current source route: [UID:0000KH][ItemObjImageLib](../../../../../by-file/ItemObjImageLib.md), generated under `auto-generated/NexusTK/render/ItemObjImageLib.cpp`
- Assignment mode: implementation callback applied for target-only scope.

## Current Target State

After callback, the target records `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000KH`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KH`, and a blank `EMITTER_POSITION_OPTIONAL`. Its formal `RECONSTRUCTION_CPP CODE` block now contains the exact free helper body supplied by this report. Its Item Summary and prose now include the current MCP evidence, exact range/size/padding, unique signature, 48 xrefs, no VA/RVA pointer hits, source-facing void/out-rect signature, archive selection, remap constants, `GetEntryRect`, `OffsetRect`, rejected owner alternatives, and generated-output expectation.

Before implementation, `auto-generated/NexusTK/render/ItemObjImageLib.cpp` had validator command `000000006959` at `2026-07-05T10:43:05-04:00` and still showed UID0000UQ as an `Empty Emitter Marker`. After scoped validator command `000000007094` at `2026-07-05T13:54:21-04:00`, the generated file header matches the callback validator metadata and UID0000UQ now emits `void GetItemGlyphBounds(short itemId, RectBounds *outRect)`.

## Supporting Research

The research checked the target page, direct owner/support pages, generated output state, current tracker rows, relevant executed B reports, and current IDA MCP evidence. Current MCP and support docs close the range, behavior, string, remap, return-shape, reachability, and source-placement questions enough for a first-draft free-function body. The older "blank formal C++" blocker is therefore superseded for this target, while historical evidence remains useful and should be retained.

Searches covered target UID/address/name terms and source-family terms including `GetItemGlyphBounds`, `ItemGlyph`, `ItemHelp`, `ItemCatalog`, `ItemImage`, `Surface`, `GrafPort`, `0x004df460`, `ITEM.EPF`, `ITEM.EPD`, `ItemObjImageLib`, and `OffsetRect`. Old reports were used only as leads after current evidence checks.

## Evidence Standards Used

- Current IDA MCP evidence is mandatory and primary for binary facts: exact ranges, function starts, bytes, decompilation, disassembly, xrefs, pointer-hit checks, strings, and helper behavior.
- Current by-* docs are authority for accepted project vocabulary, owner/emitter routes, support-level caveats, and existing formal source names.
- Generated C++ and generated tracker/coverage reports are lead and freshness evidence only; they are not manually edited and do not override current by-* or MCP evidence.
- Executed B reports are lead material only unless their facts are reconfirmed by current MCP or current by-* docs.
- Heuristic names are allowed when behavior and source shape are strong and uncertainty is documented, but raw IDA/decompiler names are not promoted into formal C++.

## Evidence Checked

Local target and support docs checked:

- [UID:0000UQ][by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md](../../../../../by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md)
- [UID:0000KH][by-file/ItemObjImageLib.md](../../../../../by-file/ItemObjImageLib.md)
- [UID:00006W][by-class/ItemObjImageLib.md](../../../../../by-class/ItemObjImageLib.md)
- [UID:00017N][0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster](../../../../../by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md)
- [UID:0003ZN][0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants](../../../../../by-memory/0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants.md)
- [UID:0000T7][MapTilePixelDimensions](../../../../../by-global/MapTilePixelDimensions.md)
- [UID:0000SW][g_useEpfAssets](../../../../../by-global/g_useEpfAssets.md)
- [UID:0000QU][g_pEPFLib](../../../../../by-global/g_pEPFLib.md)
- [UID:0002KS][ResourceLayoutTableGetEntryRect](../../../../../by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md)
- [UID:0000J3][EPFImageResources](../../../../../by-file/EPFImageResources.md)
- [UID:0000RA][g_pItemObjImageLib](../../../../../by-global/g_pItemObjImageLib.md)
- [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](../../../../../by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md)
- [UID:0001BU][ObjectImageControlPane](../../../../../by-memory/0x00520540-0x00520816.ObjectImageControlPane.md)

Generated and tracker state checked:

- `auto-generated/NexusTK/render/ItemObjImageLib.cpp`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-coverage-report-by-memory.md`

Executed report leads used as leads only:

- B007 `0000KH-ItemObjImageLib-empty-emitter-family-source-quality.md`
- B005 `00017N-ItemObjImageLibLocalMethodCluster-source-quality.md`
- B008 `00006W-ItemObjImageLib-class-source-quality.md`
- B004 caller reports for `EmployeeItemPropertyDialogPaneOnPaint`, `MyItemListPaneDrawListEntry`, and `ExchangeItemListPaneDrawItemEntry`
- B008 `0001BU-ObjectImageControlPane-source-quality.md`
- B005 `00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md`
- B011/B015/B010 reports mentioning `OffsetRect` / `0x004b7e10`

Current MCP evidence:

- Active session: `supervisor_recovery_20260705`
- `server_health` request `102`: status `ok`; IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; imagebase `0x400000`; auto-analysis ready; Hex-Rays ready; strings cache ready.
- `lookup_funcs` request `103`: `0x004df460` is `sub_4DF460`, size `0x99`; `0x004df455` and `0x004df4f9` are not function starts; successor `0x004df500` is `sub_4DF500`, size `0x168`; callees `0x004d0530` and `0x004b7e10` are separate functions.
- `get_bytes` request `104`: `0x004df455-0x004df460` is eleven `0xcc` bytes; target body is 153 bytes; `0x004df4f9-0x004df500` is seven `0xcc` bytes.
- `decompile` request `105` and `disasm` request `107`: body computes `itemId + 0x4000`, applies the non-EPF remap/clamp, calls `0x004d0530`, offsets the output rect through `0x004b7e10`, and returns with `retn 8`.
- `analyze_function` request `108`: prototype is `int __stdcall(__int16, _DWORD *)`, size `153`, callees are `sub_4D0530` and `sub_4B7E10`, callers cover 23 modeled functions, and direct xrefs to the function count 48.
- `xrefs_to` request `112`: 48 code xrefs to `0x004df460`, `more:false`.
- `find_bytes` request `113`: no raw VA pointer hits for `60 f4 4d 00`; no raw RVA pointer hits for `60 f4 0d 00`.
- `get_int` requests `119` and `121`: `byte_66DA97` initial value `1`; remap constants are `0x0972`/2418, `0x0a20`/2592, and `0x0a56`/2646; tile dimensions are 48 and 48.
- `make_signature_for_range` request `120`: target range signature is unique.
- `get_bytes` request `122`: `0x0061c288` decodes as UTF-16 `ITEM.EPF`; `0x0061c29c` decodes as UTF-16 `ITEM.EPD`.
- `xrefs_to` request `123`: `ITEM.EPF` is referenced by the four item draw helpers, this glyph helper, and one orphan local-table context; `ITEM.EPD` is referenced by the fixed-slot/scaled draw helpers, this glyph helper, and one orphan local-table context.
- `decompile` and `disasm` requests `124`/`125` for `0x004b7e10`: helper adds dx to `left/right` and dy to `top/bottom` of a four-dword rect and returns only the dy value left in `eax`.

Representative call-site disassembly samples at `0x0041f73f`, `0x004c79ad`, `0x0052077a`, and `0x005a0d28` overwrite or ignore `eax` immediately after `call sub_4DF460`. That supports a source-facing `void` helper even though Hex-Rays types the raw ABI as returning `int` from the final `OffsetRect` call. Current generated/caller docs also treat the call as a statement with the rectangle passed by output pointer.

Decimals `0x99`, `0x4000`, `0x3f53`, `0xff53`, `0x0972`, `0x0a20`, and `0x0a56` were checked with `tools/int_convert.py`.

## Positive Evidence Summary

- Exact function range, predecessor padding, successor padding, and unique signature are confirmed by current MCP.
- The helper has 48 direct code xrefs across item-list, menu, dialog, object-image, and preview consumers.
- The body directly references accepted ItemObjImageLib remap constants and the `ITEM.EPF` / `ITEM.EPD` UTF-16 resource names.
- The final rectangle offset is behavior-proven through `0x004b7e10`, and current tile dimensions are 48/48 through accepted `MapTilePixelDimensions`.
- Existing support docs already route this helper to the ItemObjImageLib module as a same-module free helper.
- Call-site samples ignore the raw `eax` value, supporting a source-facing `void` return with an output rectangle parameter.

## Negative Evidence Summary

- No raw VA or RVA pointer hits were found for `0x004df460`.
- There is no hidden `this`: the target does not consume `ecx`, uses two stack arguments, and returns with `retn 8`.
- UI panes and dialogs only call the helper; none own the item archive strings, remap constants, or helper declaration.
- `ResourceLayoutTable`, `ImageLib`, `EPFImageResources`, `Surface`, `GrafPort`, `RectBounds`, `ItemCatalog`, `ItemHelp`, and `Application` are dependency or domain-neighbor candidates, not declaration owners.
- Generated `g_pItemObjImageLib->GetItemGlyphBounds(...)` phrasing is contradicted by the raw ABI and current support docs; it is stale generated callsite pollution.

## Heuristic / Inference Reanalysis And Validation

The exact range remains `0x004df460-0x004df4f9`, size `0x99` / 153 bytes, with alignment padding on both sides and successor `0x004df500`. The body has no local object lifetime, no hidden `this`, and no vtable/data pointer to the function. It is a source-authored free helper reached by ordinary call instructions from item UI/render paths.

The ABI is `__stdcall` with two stack arguments and `retn 8`. Source-facing shape should be `void GetItemGlyphBounds(short itemId, RectBounds *outRect)`: the first argument is the item image id, the second is the mutated rectangle, and the apparent `int` return is an unused register artifact from the final rectangle-offset helper.

The helper:

1. Computes a 16-bit item image entry from `itemId + 0x4000`.
2. If `g_useEpfAssets` is false, applies the ItemObjImageLib legacy remap policy:
   - entries in `g_currentItemImageRemapFirstEntry..g_currentItemImageRemapLastEntry` receive the `0xff53` low-word adjustment;
   - other entries above `g_legacyItemImageMaxEntry` clamp to `g_legacyItemImageMaxEntry`.
3. Selects `ITEM.EPF` when `g_useEpfAssets` is true and `ITEM.EPD` otherwise.
4. Calls the ResourceLayoutTable `GetEntryRect`-style helper through `g_pEPFLib` to fill the output rectangle.
5. Calls `OffsetRect(outRect, g_mapTilePixelWidth / 2, g_mapTilePixelHeight / 2)`, which offsets by 24/24 with current initialized dimensions.

The inference was validated against current MCP disassembly/decompilation, support pages for each global/helper, generated output state, and representative caller disassembly. The previous blank-formal recommendation was reasonable historically because archive strings, helper names, and return shape had not been fully closed in the target page; this pass closes them enough for first-draft C++ while preserving the remaining support-level caveats.

## Ranked Ownership Analysis

1. [UID:0000KH][ItemObjImageLib](../../../../../by-file/ItemObjImageLib.md): accepted. The helper is in the ItemObjImageLib local method/helper island, consumes ItemObjImageLib remap constants and item archive strings, and emits through `ItemObjImageLib.cpp`.
2. [UID:00006W][ItemObjImageLib class](../../../../../by-class/ItemObjImageLib.md): source-family support only. Reject as a direct method owner because the ABI has no `this`, does not use `ecx`, and returns `retn 8`.
3. UI pane/dialog callers: rejected. They provide callsite and semantic evidence only.
4. `ResourceLayoutTable` / `ImageLib` / `g_pEPFLib`: rejected as owner. They provide the resource-rectangle lookup dependency and keep their own source docs/type caveats.
5. `Surface`, `GrafPort`, `RectBounds`, `MapPane`, and tile-dimension globals: rejected as owner. They provide draw/geometry/tile helper dependencies only.
6. `ItemCatalog`, `ItemHelp`, `ItemHelpPane`, and `Application`: rejected. Searches found no direct ownership route; those names are domain/caller leads only.
7. No-owner/non-emitting: rejected because the helper has source-authored behavior, 48 direct callers, valid owner/emitter route, and now a source-quality first-draft body.

## Source Placement

Place the helper as a free function in `NexusTK/render/ItemObjImageLib.cpp` under [UID:0000KH]. It should not be emitted as a member method on `ItemObjImageLib`, not moved to `ResourceLayoutTable.cpp`, not placed in UI/dialog source files, and not split into a new generic item helper file from current evidence. Support docs may mention it as a same-module free helper near the item draw helper family.

## First-Draft C++ Recommendation

Insert the following exact text into the target `RECONSTRUCTION_CPP CODE` block:

```cpp
void GetItemGlyphBounds(short itemId, RectBounds *outRect)
{
    const bool useEpfAssets = g_useEpfAssets;
    int itemImageEntry = static_cast<unsigned short>(itemId + 0x4000);

    if (!useEpfAssets) {
        if (itemImageEntry >= g_currentItemImageRemapFirstEntry &&
            itemImageEntry <= g_currentItemImageRemapLastEntry) {
            itemImageEntry = static_cast<unsigned short>(itemImageEntry + 0xff53);
        } else if (itemImageEntry > g_legacyItemImageMaxEntry) {
            itemImageEntry = g_legacyItemImageMaxEntry;
        }
    }

    g_pEPFLib->GetEntryRect(useEpfAssets ? L"ITEM.EPF" : L"ITEM.EPD",
                            static_cast<unsigned short>(itemImageEntry),
                            outRect);

    OffsetRect(outRect, g_mapTilePixelWidth / 2, g_mapTilePixelHeight / 2);
}
```

This block stays inside the target range: it only represents `0x004df460-0x004df4f9`. It does not emit draw-method code, singleton declarations, remap constant declarations, tile dimension declarations, ResourceLayoutTable methods, or rectangle helper implementation.

## Final Recommendation

Accept the report for a scoped target-first callback. The target can stand on current MCP evidence and existing support docs with a `90/92` score and formal free-function C++ block. Support docs should be edited only if the supervisor authorizes the scoped sync notes below; no support score change is recommended.

## Recommended Target Doc Changes

For [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](../../../../../by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md):

- Applied: changed `COMPLETION:85` to `COMPLETION:90`.
- Applied: changed `CONFIDENCE:90` to `CONFIDENCE:92`.
- Applied/already-present: preserved `CANONICAL_OWNER:0000KH`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KH`, and blank `EMITTER_POSITION_OPTIONAL`.
- Applied: inserted the formal C++ block above.
- Applied: updated the Item Summary and prose with current MCP session `supervisor_recovery_20260705`, exact range/size/padding, unique signature, 48 code xrefs, no VA/RVA pointer hits, source-facing void/out-rect signature, `ITEM.EPF`/`ITEM.EPD` UTF-16 string evidence, remap constants and values, `g_useEpfAssets`, `g_pEPFLib->GetEntryRect`, `OffsetRect`, and half-tile offset through `g_mapTilePixelWidth` / `g_mapTilePixelHeight`.
- Applied: retained the historical A001/B005/B007/B008 evidence and the promotion from old by-item path, while marking older "formal C++ blank" blocker wording as superseded by this current pass.
- Applied: retained rejected alternatives for UI caller ownership, ItemHelp/ItemCatalog ownership, Application ownership, ResourceLayoutTable/ImageLib/Surface/GrafPort helper ownership, class-method route, and no-owner/non-emitting.

Applied validator requirement: ran the scoped target validator from `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md --apply --queue-timeout 240`.

Generated-output expectation fulfilled: before implementation, `auto-generated/NexusTK/render/ItemObjImageLib.cpp` had validator-command-id `000000006959`, refreshed `2026-07-05T10:43:05-04:00`, and showed UID0000UQ as `Empty Emitter Marker`. After target implementation plus validator/autogen refresh, the file has validator-command-id `000000007094`, refreshed `2026-07-05T13:54:21-04:00`, and the UID0000UQ block contains the free `GetItemGlyphBounds` body. Generated output was not manually edited.

## Recommended Support Doc Changes

Support edits were excluded from this implementation callback because the supervisor authorized the target page only and the target could accurately stand alone. The scoped support syncs below remain possible future cleanups if the supervisor separately authorizes them:

- [UID:0000KH][by-file/ItemObjImageLib.md](../../../../../by-file/ItemObjImageLib.md): replace the UID0000UQ "keep blank" generated-output audit note with this current MCP closure and generated-output expectation. No support score change is needed.
- [UID:00006W][by-class/ItemObjImageLib.md](../../../../../by-class/ItemObjImageLib.md): keep the helper as a same-module free helper, not a class method; explicitly treat generated method-call phrasing as stale/generated. No support score change is needed.
- [UID:00017N][local method cluster](../../../../../by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md): update the UID0000UQ row with current session, formal-readiness status, xref count, string evidence, and no pointer hits. No support score change is needed.
- [UID:0003ZN][legacy remap constants](../../../../../by-memory/0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants.md): optional link-only cleanup from stale `by-item/GetItemGlyphBounds_004DF460.md` references to the current by-memory target path. No content or score change is needed.

Caller pages already use `GetItemGlyphBounds` as a dependency and do not need target-specific edits unless their generated output still expresses the helper as an `ItemObjImageLib` method after refresh.

## Score And Metadata Recommendation

Completion should rise to `90` because this pass resolves the exact range, byte padding, current decompilation, xref count, no pointer-hit state, resource string identities, remap constants, source-facing void/out-rect signature, owner/source placement, and first-draft C++ readiness. Completion remains below final-audit tier because exact original helper spelling and support-level public type/helper declaration spelling are still inferred rather than recovered source symbols.

Confidence should rise to `92` because current MCP, current support docs, generated output state, and representative caller samples agree. Confidence remains below final-audit tier because `g_pEPFLib`'s final public type and exact original `OffsetRect` spelling remain support-level caveats.

Metadata should keep `CANONICAL_OWNER:0000KH`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KH`, and blank `EMITTER_POSITION_OPTIONAL`.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Outcome |
| --- | --- | --- |
| Is this a class method? | Checked ABI, disassembly, generated callsites, and support docs. | Closed: no hidden `this`; free helper in ItemObjImageLib module. |
| Is the source return type `int` or `void`? | Checked raw epilogue, decompiler return, and representative callers after the call. | Closed for source-facing draft: use `void`; callers ignore/overwrite `eax`, and the meaningful effect is out-rect mutation. |
| Are `ITEM.EPF` and `ITEM.EPD` exact? | Current MCP byte reads decode both UTF-16 strings and xrefs show this target consumes both. | Closed. |
| Are remap constants source-facing enough? | Current MCP values match UID0003ZN formal declarations and existing ItemObjImageLib docs. | Closed for target; use accepted names. |
| Can `g_pEPFLib->GetEntryRect` be used despite global type caveat? | UID0000QU documents the type caveat, while UID0002KS provides accepted `GetEntryRect` formal method and comparable docs use `g_pEPFLib` ResourceLayout-style calls. | Closed for target C++ with support caveat retained. |
| Can `OffsetRect` be used? | MCP proves behavior; multiple accepted reports/docs use `OffsetRect` as source-facing name for `0x004b7e10`. | Closed for first-draft target C++. |
| Are support docs required? | Support docs already carry owner/remap/tile/global facts; stale parts are blank-C++ blocker text and old by-item links. | Optional scoped sync only; no support score change recommended. |

## Validator Results

Implementation callback scoped validator run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0000UQ-GetItemGlyphBounds-source-quality-removed.md](0000UQ-GetItemGlyphBounds-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- `command_id`: `000000007094`
- `command_timestamp`: `2026-07-05T13:54:21-04:00`
- Exit code: `0`
- `ok`: `1`
- Target updates reported: `completion_update 0000UQ ... 90`, `confidence_update 0000UQ ... 92`, `autogen_registry_update ... blank -> block`
- Non-blocking diagnostics reported: four `missing_ref_uid` entries for existing UID references `0003ZN`/`0003LZ`; no target validation failure.
- Generated refresh result: `generated_refresh: deferred`, `generated_refresh_command_id: 000000007094`, `generated_refresh_timestamp: 2026-07-05T13:54:21-04:00`.

Generated freshness check after the validator: `auto-generated/NexusTK/render/ItemObjImageLib.cpp` has `validator-command-id: 000000007094`, `validator-refreshed-at: 2026-07-05T13:54:21-04:00`, and `validator-refresh-source: deferred-generated-refresh`. The UID0000UQ block now emits `void GetItemGlyphBounds(short itemId, RectBounds *outRect)` and is no longer an `Empty Emitter Marker`.

## Changed Files

Manual callback edits:

- `by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md`
- `tools/leaser/Agents/Agent-B003/research/0000UQ-GetItemGlyphBounds-source-quality.md`

Support docs were not edited because the target page could stand alone and the supervisor callback did not authorize support expansion. No generated files were manually edited. The scoped validator refreshed/observed `auto-generated/NexusTK/render/ItemObjImageLib.cpp` for freshness, as recorded above. No coverage reports, lifecycle/archive files, supervisor ledgers, or executed-report locations were manually edited.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0000UQ-01 | Target score should move from `85/90` to `90/92`. | High | Current MCP closes range, body, archive string, remap value, return-shape, xref, pointer-hit, and formal C++ blockers; remaining caveats are support-level. | Target metadata and Score Rationale. | incorporate | Applied: target header now has `COMPLETION:90` and `CONFIDENCE:92`; validator `000000007094` accepted both updates with exit `0`, `ok:1`. |
| C-0000UQ-02 | Owner/emitter route stays `0000KH`; reconstructable stays `TRUE`; optional emitter position stays blank. | High | `__stdcall` free helper, no `this`, broad item draw/list callers, ItemObjImageLib remap constants and archive strings; no better owner route. | Target metadata, Status, Ownership Decision. | already-present | Already-present and preserved: target still has `CANONICAL_OWNER:0000KH`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KH`, and blank `EMITTER_POSITION_OPTIONAL`. |
| C-0000UQ-03 | Exact target range is `0x004df460-0x004df4f9`, size `0x99` / 153, with 11 bytes of predecessor padding and 7 bytes of successor padding. | High | MCP requests `103`, `104`, `107`, `120`; int_convert for `0x99`. | Target Item Summary, Boundary Evidence. | incorporate | Applied: target Item Summary, Status, Evidence, and Changes now carry exact range, size, padding, and unique-signature evidence. |
| C-0000UQ-04 | Formal C++ is now ready as a free `void GetItemGlyphBounds(short itemId, RectBounds *outRect)` helper. | Medium-high | `retn 8`; decompiler prototype has two args; sampled callers ignore/overwrite `eax`; all behavior is out-rect mutation; support docs use helper as statement. | Target formal `RECONSTRUCTION_CPP CODE` block and Signature section. | incorporate | Applied: exact formal C++ block from this report was inserted into the target formal block; validator registry updated `blank -> block`. |
| C-0000UQ-05 | The helper starts with `itemId + 0x4000` and uses a 16-bit item image entry. | High | MCP decompile/disasm requests `105`/`107`: `add eax, 4000h`, `movzx ecx, ax`; int_convert confirms `0x4000` / 16384. | Target Behavior. | incorporate | Applied: target formal C++ and Behavior document `itemId + 0x4000` and the 16-bit/static-cast item image entry shape. |
| C-0000UQ-06 | Non-EPF mode applies the accepted ItemObjImageLib remap constants and clamp. | High | MCP `119`: `0x0972`/2418, `0x0a20`/2592, `0x0a56`/2646`; disasm at `0x004df47b-0x004df4a9`; support UID0003ZN. | Target Behavior and Remap Policy. | incorporate | Applied: target Behavior retains/remodels the remap policy, constants, signed `0xff53` translation, and `0x0972` clamp. |
| C-0000UQ-07 | `g_useEpfAssets` selects `ITEM.EPF` versus `ITEM.EPD`. | High | MCP `122` bytes decode UTF-16 `ITEM.EPF` at `0x0061c288` and `ITEM.EPD` at `0x0061c29c`; `byte_66DA97` value and support UID0000SW. | Target Behavior and Dependencies. | incorporate | Applied: target formal C++ and Evidence document `g_useEpfAssets`, `ITEM.EPF`, `ITEM.EPD`, UTF-16 string addresses, and the selector evidence. |
| C-0000UQ-08 | The resource lookup is the ResourceLayoutTable `GetEntryRect` path through `g_pEPFLib`. | High for behavior, medium-high for final public type | MCP call to `0x004d0530`; support UID0002KS formal method; UID0000QU documents `g_pEPFLib` type caveat and accepted ResourceLayout-style API exposure. | Target Behavior and Dependency Notes. | incorporate | Applied: target formal C++ and Behavior use `g_pEPFLib->GetEntryRect`; Evidence records callee `0x004d0530`. |
| C-0000UQ-09 | The final offset is `OffsetRect(outRect, g_mapTilePixelWidth / 2, g_mapTilePixelHeight / 2)`. | High for behavior, medium-high for exact helper spelling | MCP `107`, `121`, `124`, `125`; support UID0000T7; existing reports use `OffsetRect` as accepted source-facing name. | Target Behavior and Formal C++ block. | incorporate | Applied: target formal C++ and Behavior include `OffsetRect` with half `g_mapTilePixelWidth` / `g_mapTilePixelHeight`; Evidence records helper `0x004b7e10`. |
| C-0000UQ-10 | Direct reachability is 48 code xrefs; no raw VA/RVA pointer hits were found for the function address. | High | MCP `112` reports 48 code xrefs, `more:false`; MCP `113` finds no `60 f4 4d 00` or `60 f4 0d 00` matches. | Target Caller/Reachability Evidence. | incorporate | Applied: target Item Summary, Score Rationale, Evidence, and Changes document 48 direct code xrefs and no VA/RVA pointer hits. |
| C-0000UQ-11 | Class-method route should remain rejected despite generated `g_pItemObjImageLib->GetItemGlyphBounds(...)` phrasing in some generated/caller outputs. | High | Function has no `this`, uses `retn 8`, is physically free helper; support docs already say free helper same module. | Target Ownership Decision; by-file/by-class support sync. | incorporate | Applied in target Ownership Decision: free-helper route retained; generated class-method/callsite pollution and rejected owner alternatives are explicit. No support docs edited. |
| C-0000UQ-12 | Generated `ItemObjImageLib.cpp` should no longer contain an empty UID0000UQ marker after accepted target implementation and validator refresh. | High | Current generated file refreshed `2026-07-05T10:43:05-04:00`, command id `000000006959`, still showed empty marker; target now contains formal C++. | Target Generated Output section; generated freshness check. | incorporate | Applied/verified: generated `auto-generated/NexusTK/render/ItemObjImageLib.cpp` header is `validator-command-id: 000000007094`, refreshed `2026-07-05T13:54:21-04:00`, and UID0000UQ emits the `GetItemGlyphBounds` body. |
| C-0000UQ-13 | Support docs need only scoped sync notes, not score changes. | Medium-high | Support docs already carry owner/remap/tile/global facts; stale parts are blank-formal blocker text and old by-item links. | Support docs excluded for this callback. | not-applicable | Excluded-with-reason: supervisor authorized target page only; the target edit stood alone and no direct support-doc contradiction was found. No support docs or support scores were changed. |
| C-0000UQ-14 | Historical A001/B005/B007/B008 evidence should be retained, with old "blank formal C++" conclusions historicalized rather than deleted. | High | Executed reports and target history remain correct for their then-current blockers; current MCP closes specific blockers. | Target Changes / Historical Evidence. | historicalize | Applied: target preserves old A001/B005/B007/B008 evidence and changes old blank-C++ wording into historical/superseded context. |
| C-0000UQ-15 | Validator requirement for accepted implementation is the scoped target command from `source-3/project-documentation`. | High | B-agent workflow and assignment rules require scoped validators after by-* edits. | Recommended Target Doc Changes; Implementation Checklist. | incorporate | Applied: scoped validator command `000000007094` ran from `source-3/project-documentation`, exit `0`, `ok:1`. |
| C-0000UQ-16 | Gate 1 report-only pass did not modify by-* docs or lifecycle/archive files; implementation callback should remain within authorized scope. | High | Gate 1 passed at SHA256 `B54376ECB1F7BF221B904E4265445DB35CD7EAE6A54068417738BD34CE593616`; callback explicitly authorized target implementation. | Report metadata / callback verification. | already-present | Satisfied: target by-* edit was supervisor-authorized; report updated in own research folder; no `execute_report`, lifecycle/archive/report-move, dry-run/probing, or support-doc edit was run. |

## Implementation Tracking Checklist

- [x] C-0000UQ-01: target metadata updated to `90/92`; validator `000000007094` accepted both values.
- [x] C-0000UQ-02: owner/emitter/reconstructable/position metadata stayed unchanged.
- [x] C-0000UQ-03: target Item Summary/Status/Evidence/Changes incorporate current range, size, padding, and unique-signature evidence.
- [x] C-0000UQ-04: exact formal C++ block from this report inserted into target formal block.
- [x] C-0000UQ-05 through C-0000UQ-09: target behavior prose and formal C++ cover entry computation, remap, archive selection, `GetEntryRect`, and `OffsetRect`.
- [x] C-0000UQ-10: target reachability updated with 48 code xrefs and no VA/RVA pointer hits.
- [x] C-0000UQ-11: target ownership decision incorporates free-helper ownership and class-method/generated-callsite rejection.
- [x] C-0000UQ-12: generated `ItemObjImageLib.cpp` checked after validation; command id/timestamp match validator `000000007094` / `2026-07-05T13:54:21-04:00`, and UID0000UQ is no longer an empty marker.
- [x] C-0000UQ-13: support docs excluded-with-reason; target stood alone, callback did not authorize support expansion, and no direct contradiction was found.
- [x] C-0000UQ-14: old blank-C++ blocker wording historicalized without removing prior A001/B005/B007/B008 evidence.
- [x] C-0000UQ-15: scoped target validator ran from `source-3/project-documentation`: command id `000000007094`, timestamp `2026-07-05T13:54:21-04:00`, exit `0`, `ok:1`.
- [x] C-0000UQ-16: callback stayed within authorized scope and did not run `execute_report`, lifecycle/archive/report-move, dry-run/probing, or support-doc edits.
- [x] Lease proof: B003 target lease acquired successfully at `2026-07-05T13:52:51-04:00`; released successfully at `2026-07-05T13:54:42-04:00`; `current_leases.md` showed no active leases after release.
- [x] Ledger actions use only allowed states: `incorporate`, `already-present`, `historicalize`, and `not-applicable`.

## Implementation Callback Verification

- IDA MCP mandatory evidence was collected from active session `supervisor_recovery_20260705`; fallback-only work was not used.
- No subagents were spawned.
- Lease used only for the target edit/validator/freshness batch and released immediately afterward.
- Scoped validator command `000000007094` completed with exit `0`, `ok:1`.
- Generated freshness for `auto-generated/NexusTK/render/ItemObjImageLib.cpp` is current to validator command `000000007094`; UID0000UQ is no longer an empty marker.
- No support docs were edited. No `execute_report`, dry-run/probing variant, registry lifecycle command, report move, or archive command was run.
- Gate 1 report SHA before implementation: `B54376ECB1F7BF221B904E4265445DB35CD7EAE6A54068417738BD34CE593616`.
- Original report timestamp: `2026-07-05T13:34:53-04:00`.
- Repair timestamp: `2026-07-05T13:48:48-04:00`.
- Implementation verification timestamp: `2026-07-05T13:54:42-04:00`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000007105","destination_path":"executed-b-agent-research/B003/0000UQ-GetItemGlyphBounds-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0000UQ-GetItemGlyphBounds-source-quality.md","timestamp":"2026-07-05T14:02:06-04:00","uid":"0000UQ"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000UQ-GetItemGlyphBounds-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0000UQ-GetItemGlyphBounds-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000UQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
