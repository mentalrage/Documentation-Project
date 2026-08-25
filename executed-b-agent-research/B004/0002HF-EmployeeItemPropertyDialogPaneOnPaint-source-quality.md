** TARGET-REPORT-UID:0002HF **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002HF EmployeeItemPropertyDialogPaneOnPaint Source-Quality Report

Agent: `B004`
Assignment: `B004-report-0002HF-employee-item-property-dialog-pane-onpaint-source-quality-20260626`
Target: [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](../../../../../by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md)
Mode: report-only MCP-backed research
MCP HTTP session: `f057c832-43a0-481b-b377-637857d0bdcc`
Active IDB/database: `80de0a67`

No by-* docs, generated/project-level files, IDA DB state, validator/tool state, or `-coverage-report.md` files were edited during this report-only pass. No subagents were used. No leases were taken.

## Recommendation

Apply a target repair, not a no-change or no-code disposition.

| Item | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `86` | `89` |
| `CONFIDENCE` | `88` | `91` |
| `CANONICAL_OWNER` | `000138` | `00004D` |
| `EMITTER_UIDS` | `000138` | `00004D` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_POSITION_OPTIONAL` | blank | blank |
| Formal C++ | blank | add first-draft `EmployeeItemPropertyDialogPane::OnPaint()` |

Rationale: current MCP proves the body is the `EmployeeItemPropertyDialogPane` primary vtable paint slot at `0x00618fe0`, with exact bounds, exact successor, alignment padding, `SELLITEM.EPF` / `SELLITEM.PAL` resource filename use, inherited dialog paint/draw-state setup, `m_itemIconRect` and `m_itemRecord` reads, and the item-image renderer call with selected-record fields `+0x004/+0x006`. The direct class [UID:00004D][EmployeeItemPropertyDialogPane](../../../../../by-class/EmployeeItemPropertyDialogPane.md) and file [UID:0000J0][EmployeeDialogPane](../../../../../by-file/EmployeeDialogPane.md) clear the active code-entry route. The aggregate [UID:000138][EmployeeDialogPanes](../../../../../by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md) should remain range/support coverage, not the exact method owner/emitter.

## MCP Availability

MCP was available and responsive.

| Detail | Value |
| --- | --- |
| Listener | `http://127.0.0.1:13337/mcp` |
| HTTP session | `f057c832-43a0-481b-b377-637857d0bdcc` |
| IDB session | `80de0a67` |
| IDB path | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Input binary | `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` |
| Module/imagebase | `NexusTK.exe`, `0x400000` |
| Worker | backend `worker`, PID `26892`, active/adopted/owned, `is_analyzing:false` |
| Health | `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, cache size `2067` |

Health proof: `B004-MCP-0017` / `idb_list` at `2026-06-26T17:01:06.4250798-04:00` returned the active worker session above; `B004-MCP-0018` / `server_health` at `2026-06-26T17:01:06.9147614-04:00` returned `status:ok`.

## Current MCP Evidence

Validated target facts:

- `B004-MCP-0005` / `lookup_funcs` at `2026-06-26T16:56:32.6275954-04:00` identifies `0x004a4570` as `sub_4A4570`, size `0xe9`; `0x004a4659` is not a function; successor `0x004a4660` is `sub_4A4660`, size `0x10e`; predecessor constructor `0x004a41c0` is `sub_4A41C0`, size `0x3ab`; `0x004a456b` is not a function.
- `B004-MCP-0006` / `entity_query` over `0x004a41c0-0x004a4770` returns exactly the constructor, this paint handler, sibling `OnCommand`, and successor quantity constructor starts in that neighborhood.
- `B004-MCP-0011` / `get_bytes` confirms seven `0xcc` alignment bytes at `0x004a4659-0x004a4660`; the target starts with `55 8b ec 83 ec 64 ...`.
- `B004-MCP-0016` / `disasm` reports 75 instructions ending with `retn` at `0x004a4658`.
- `B004-MCP-0014` / `make_signature_for_range 0x004a4570-0x004a4659` returned a unique full-range signature.

Validated reachability and vtable facts:

- `B004-MCP-0008` / `xrefs_to 0x004a4570` returns one inbound xref: data xref from `0x00618fe0`; `xrefs_to 0x00618fe0` returns no direct refs to the slot address.
- `B004-MCP-0009` / `get_int` reads `0x00618fe0 u32le -> 4867440`, verified by `int_convert.py` as `0x004a4570`; `0x00618fe4 u32le -> 4867680`, verified as `0x004a4660`.
- [UID:0002MF][EmployeeItemPropertyDialogPaneVtableData](../../../../../by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md) already places `0x00618fe0` as the primary paint slot and `0x00618fe4` as the command slot.

Validated decompile/disassembly behavior:

- `B004-MCP-0007` / `analyze_function 0x004a4570` reports prototype residue `int __thiscall(int this)`, size `233`, one basic block, and no code callers. Treat the return as decompiler residue from the final draw helper; the source virtual is `void OnPaint()`, matching paint-handler precedent.
- The body initializes two `EPFTileContext`-sized locals through `sub_457A60`, calls inherited dialog paint/focus setup `sub_49F090`, sets draw/text color state with `sub_4B9660(this, 143)` and `sub_4B9680(this, 143)`, looks up `SELLITEM.EPF` through `sub_4D02F0(g_pEPFLib, ..., frame 0, ...)`, renders it through `sub_4B9980(..., L"SELLITEM.PAL", 0)`, calls `GetItemGlyphBounds` / `sub_4DF460` for selected record word `+0x004`, copies `this+0x270`, expands right/bottom by `0x2c`, and calls `g_pItemObjImageLib->DrawItemImageIn43x43Slot` / `sub_4DEFC0` with selected record word `+0x004` and byte `+0x006`.
- `B004-MCP-0013` / `callees` reports `sub_457A60`, `sub_49F090`, `sub_4B9660`, `sub_4B9680`, `sub_4D02F0`, `sub_4B9980`, `sub_4DF460`, `sub_4DEFC0`, and `@__security_check_cookie@4`.

Validated resources:

- `B004-MCP-0008` / `xrefs_to` reports `0x00619238` referenced only at `0x004a45c1` in this target and `0x00619254` referenced only at `0x004a45cd` in this target.
- `B004-MCP-0015` / `get_bytes` over `0x00619238` and `0x00619254` confirms UTF-16LE bytes for `SELLITEM.EPF` and `SELLITEM.PAL`.
- [UID:0001R9][employee-dialog-resources](../../../../../by-resource/employee-dialog-resources.md) confirms the current package entries for `SELLITEM.EPF` and `SELLITEM.PAL`; this method owns filename use and draw behavior, not DAT payload bytes.

Integer proof: `B004-LOCAL-0001` / `tools\int_convert.py` at `2026-06-26T17:01:21.4618523-04:00` verified `0xe9 == 233`, `0x10e == 270`, `0x270 == 624`, `0x280 == 640`, `0x2c == 44`, `0x004 == 4`, `0x006 == 6`, `0x8f == 143`, `0x284 == 644`, `4867440 == 0x4a4570`, and `4867680 == 0x4a4660`.

## Source-Facing Names

Recommended names for the target and support docs:

| Binary location/artifact | Recommended source-facing name | Evidence and caveat |
| --- | --- | --- |
| method `0x004a4570` | `void EmployeeItemPropertyDialogPane::OnPaint()` | Primary vtable slot `0x00618fe0`; paint behavior and sibling class routing match [UID:00004D]. |
| `sub_49F090` | `DialogPane::OnPaint()` / inherited dialog focus-paint setup | [UID:0001U4][DialogPaneLayout](../../../../../by-type/by-struct/DialogPaneLayout.md) describes `0x0049f090` as inherited focus/selection drawing virtual. Use `DialogPane::OnPaint()` in first-draft source and note the helper-role caveat. |
| `sub_457A60` | `EPFTileContext::Initialize()` | [UID:0000XY][EPFTileContext](../../../../../by-memory/0x00457a60-0x00458610.EPFTileContext.md) documents the initializer and 0x28-byte context layout. |
| `sub_4B9660(this, 143)` | `SetDrawColor(143)` | [UID:000162][GrafPortDrawStateAccessors](../../../../../by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md) names this as the active draw-color setter; `143` is verified from `0x8f`. |
| `sub_4B9680(this, 143)` | `SetTextColor(143)` | Same accessor page documents the primary text-color setter at `+0x7c`; exact public spelling remains shared-support caveat. |
| `sub_4D02F0(dword_67A744, L"SELLITEM.EPF", 0, ...)` | `g_pEPFLib->LookupLayoutEntry(L"SELLITEM.EPF", 0, &sellItemTile)` | [UID:0002KP][ResourceLayoutTableLookupLayoutEntry](../../../../../by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md) and resource docs support this spelling. |
| `sub_4B9980(..., L"SELLITEM.PAL", 0)` | `RenderTileFrame(..., L"SELLITEM.PAL", 0)` | Same source-facing render helper used by the accepted `IconsPane::OnPaint` draft; helper owner remains shared render infrastructure. |
| `dword_67A758` | `g_pItemObjImageLib` | [UID:0001OT][g_pItemObjImageLib storage](../../../../../by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md) and [UID:0000KH][ItemObjImageLib](../../../../../by-file/ItemObjImageLib.md). |
| `sub_4DF460(record+0x004, outBounds)` | `GetItemGlyphBounds(m_itemRecord->itemImageId, &itemGlyphContext.bounds)` | [UID:0000UQ][GetItemGlyphBounds](../../../../../by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md) documents the item-glyph helper. Preserve the call even though this method does not consume the returned bounds later; the binary keeps it before the fixed-slot draw. |
| `sub_4DEFC0(g_pItemObjImageLib, this, &rect, record+0x004, record+0x006, 0, 0.0f)` | `g_pItemObjImageLib->DrawItemImageIn43x43Slot(this, &iconRect, m_itemRecord->itemImageId, m_itemRecord->itemPaletteFlags, NULL, 0.0f)` | [UID:00041S][DrawItemImageIn43x43Slot](../../../../../by-memory/0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md) documents this signature. |
| `this+0x270` | `m_itemIconRect` | Constructor and layout docs agree; target expands right/bottom from left/top by `44`. |
| `this+0x280` | `m_itemRecord` | Constructor, layout, command handler, and target decompile agree. |
| record `+0x004` | target-context `itemImageId`; broad aliases remain `stateCode` / `recordType` | It is parsed as a word, passed to `GetItemGlyphBounds`, and passed as `itemId` to `DrawItemImageIn43x43Slot`. Do not force the broad [UID:0001UD][EmployeeRecord](../../../../../by-type/by-struct/EmployeeRecord.md) page to drop its shared-context aliases. |
| record `+0x006` | target-context `itemPaletteFlags`; broad aliases remain `iconVariant` / `parserFlag` | It is parsed as a byte and passed as the renderer `paletteFlags` argument. Prefer `itemPaletteFlags` over generated `paletteId` because the callee signature documents flags. |

## First-Draft C++ Readiness

This method clears the active code-entry gate:

- `RECONSTRUCTABLE:TRUE`.
- Recommended `EMITTER_UIDS:00004D`; the class routes to [UID:0000J0][EmployeeDialogPane](../../../../../by-file/EmployeeDialogPane.md) and the generated file family `NexusTK/ui/dialogs/EmployeeDialogPane.cpp`.
- `(89 + 91) / 2 = 90`, greater than `85`.
- Dependencies used by the draft have documented routes: `DialogPane`, `EPFTileContext`, GrafPort draw-state accessors, `ResourceLayoutTable::LookupLayoutEntry`, `RenderTileFrame`, `g_pItemObjImageLib`, `GetItemGlyphBounds`, `ItemObjImageLib::DrawItemImageIn43x43Slot`, `EmployeeItemPropertyDialogPaneLayout`, and `EmployeeRecord`.

Recommended C++ to place in the target page:

```cpp
void EmployeeItemPropertyDialogPane::OnPaint()
{
    EPFTileContext sellItemTile;
    EPFTileContext itemGlyphContext;
    RectBounds iconRect;

    sellItemTile.Initialize();
    itemGlyphContext.Initialize();

    DialogPane::OnPaint();
    SetDrawColor(143);
    SetTextColor(143);

    g_pEPFLib->LookupLayoutEntry(L"SELLITEM.EPF", 0, &sellItemTile);
    RenderTileFrame(&sellItemTile,
                    &sellItemTile.bounds,
                    &m_bounds,
                    0,
                    L"SELLITEM.PAL",
                    0);

    GetItemGlyphBounds(m_itemRecord->itemImageId, &itemGlyphContext.bounds);

    iconRect = m_itemIconRect;
    iconRect.right = iconRect.left + 44;
    iconRect.bottom = iconRect.top + 44;

    g_pItemObjImageLib->DrawItemImageIn43x43Slot(
        this,
        &iconRect,
        m_itemRecord->itemImageId,
        m_itemRecord->itemPaletteFlags,
        NULL,
        0.0f);
}
```

Notes for implementation:

- Keep the two `EPFTileContext::Initialize()` calls. The second context's bounds are passed to `GetItemGlyphBounds` before the fixed-slot draw; removing it would lose a live binary call even though the bounds are not read again in this method.
- Keep `SetDrawColor(143)` and `SetTextColor(143)` before the resource lookup/render path.
- Build `iconRect` from `m_itemIconRect` by preserving left/top and setting right/bottom to left/top plus `44`.
- Do not rename `SELLITEM.EPF` / `SELLITEM.PAL` as resource payload variables in this method; they are source filename constants whose payload provenance stays in the resource docs.

## Owner, Emitter, And Placement

Ranked alternatives:

1. `CANONICAL_OWNER:00004D`, `EMITTER_UIDS:00004D` for target `0002HF`: recommended. The function is a primary vtable method of `EmployeeItemPropertyDialogPane`, uses derived-tail fields at `this+0x270/+0x280`, and the class parent already routes to the employee dialog source module.
2. Keep `CANONICAL_OWNER:000138`, `EMITTER_UIDS:000138`: reject for the exact method. The aggregate is useful range/support coverage, but the narrow class owner is now available and accepted for sibling `0002HG`.
3. `CANONICAL_OWNER:00004C`, `EMITTER_UIDS:00004C`: reject. The main employee dialog owns the surrounding source module and record array, but this paint body is dispatched from the property-dialog vtable and consumes property-dialog tail fields.
4. `CANONICAL_OWNER:0000J0`, `EMITTER_UIDS:0000J0`: reject for the exact target. The file is the source root, but by-structure should prefer the narrow class owner when it clears the route.
5. Keep formal C++ blank because helper names are shared/inferred: reject. The accepted `IconsPane::OnPaint` implementation uses the same helper-name tier (`EPFTileContext::Initialize`, `SetDrawColor`, `LookupLayoutEntry`, `RenderTileFrame`, `PreparePaneRegion`) after current support docs made the names source-facing enough for first-draft C++.

## Support Document Changes To Apply If Accepted

Target [UID:0002HF] should be updated at report-level detail:

- Header: `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00004D`, `EMITTER_UIDS:00004D`, `RECONSTRUCTABLE:TRUE`, blank emitter position.
- Formal C++: add the first-draft `EmployeeItemPropertyDialogPane::OnPaint()` above.
- Status/behavior: replace the stale blank-C++ rationale with current helper and field names; retain resource-derived `SELLITEM` handling.
- IDA evidence: add current MCP session `80de0a67` facts from this report: range, successor, vtable-only xref, padding, resource xrefs/bytes, decompile/disassembly, callee set, vtable dwords, and `int_convert.py` conversions.
- Touched state: use `m_itemIconRect`, `m_itemRecord`, target-context `itemImageId`, and `itemPaletteFlags`.
- Reconstruction notes: state that raw helper labels remain evidence aliases only; the exact target is now source-ready under the active gate.
- Changes log: add a 2026-06-26 B004 source-quality entry with score/owner/emitter/C++ changes and evidence summary.

Support pages:

- [UID:00004D][EmployeeItemPropertyDialogPane](../../../../../by-class/EmployeeItemPropertyDialogPane.md): raise `87/89 -> 88/90` if accepted; update method map and evidence to state `OnPaint` now emits through this class with first-draft C++, accepted target-local item icon fields, resource helper names, and direct vtable slot `0x00618fe0`.
- [UID:0001UB][EmployeeItemPropertyDialogPaneLayout](../../../../../by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md): score can remain `86/91`; add that `m_itemIconRect` and `m_itemRecord` now support first-draft `OnPaint()` C++ and target-local item icon aliases.
- [UID:0001UD][EmployeeRecord](../../../../../by-type/by-struct/EmployeeRecord.md): keep score unless a separate record-layout pass is requested; add target-context aliases that `+0x004` is `itemImageId` for the property/item icon draw path and `+0x006` is `itemPaletteFlags` for `DrawItemImageIn43x43Slot`, while broad aliases remain.
- [UID:0000J0][EmployeeDialogPane](../../../../../by-file/EmployeeDialogPane.md): keep score; update the `EmployeeItemPropertyDialogPane` row to state `0002HF` now emits through [UID:00004D] with first-draft C++ while the file remains `NexusTK/ui/dialogs/EmployeeDialogPane.cpp`.
- [UID:000138][EmployeeDialogPanes](../../../../../by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md): keep aggregate C++ blank; add a child-routing note that `0002HF`, like `0002HG`, emits through the direct class rather than the aggregate.
- [UID:0001XH][EmployeeDialogPaneVtables](../../../../../by-type/by-vtable/EmployeeDialogPaneVtables.md) and [UID:0002MF][EmployeeItemPropertyDialogPaneVtableData](../../../../../by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md): keep scores; add short notes that slot `0x00618fe0 -> 0x004a4570` now has first-draft C++ on `0002HF` and direct owner/emitter [UID:00004D].
- [UID:0002HE][EmployeeItemPropertyDialogPaneConstructor](../../../../../by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md): keep constructor C++ blank; add a support note that the initialized `m_itemIconRect` and `m_itemRecord` now feed accepted `OnPaint()` C++.
- [UID:0001R9][employee-dialog-resources](../../../../../by-resource/employee-dialog-resources.md) and [UID:000256][EmployeeDialogReadOnlyData](../../../../../by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md): no score change required; optionally add current `0002HF` source-quality xref evidence for `SELLITEM.EPF`/`.PAL`.
- No edits are required to ItemObjImageLib helper pages, GrafPort draw-state accessors, Surface callback table, or ResourceLayoutTable pages; they already provide sufficient support names for this target.

## Score Rationale

Recommended target completion `89`: the target now has current proof for exact range, byte boundary, successor, vtable-only xref, vtable slot dword, resource filename bytes/xrefs, decompile/disassembly behavior, helper/callee roles, selected record field consumers, layout field consumers, and first-draft C++.

Recommended target confidence `91`: MCP, resource docs, layout docs, vtable docs, sibling constructor/command docs, and ItemObjImageLib helper docs independently agree on the method's owner, helper calls, resource use, selected-record pointer, item icon rectangle, item-image draw API, and resource-derived rebuild boundary. Confidence stays below final-audit levels because exact original private member spellings and shared render-helper public names are still inferred source-facing names, not recovered symbols.

## Rejected No-Code And No-Score Dispositions

- No-code because drawing helper names are shared/inferred: rejected. Current support docs and accepted `IconsPane::OnPaint` precedent make the helper names source-facing enough for first-draft target C++.
- No-code because `EmployeeRecord` broad field names are conservative: rejected. Use target-context aliases for `+0x004/+0x006` while preserving broad layout aliases.
- Keep aggregate owner/emitter because the function lies in `0x004a1d70-0x004a4e6b`: rejected for this exact method. Vtable slot and derived-tail field use prove direct [UID:00004D] ownership.
- Move ownership to `EmployeeDialogPane`: rejected. The main dialog owns source module and record storage, but this method is dispatched through `EmployeeItemPropertyDialogPane` and reads `m_itemIconRect`/`m_itemRecord`.
- Treat `SELLITEM.EPF`/`.PAL` as standalone source-owned data emitted from this target: rejected. This method uses filename constants and runtime resource loading; DAT payload provenance stays with resource docs.
- Split a smaller child: rejected. `0002HF` is already the exact full modeled method; the two initialized contexts, resource draw, glyph lookup, and item image draw are one source paint override.

## Supervisor-Owned Coverage Text

Do not edit coverage during a B-agent implementation callback unless explicitly reassigned. If this report is accepted and implemented, the supervisor can apply coverage text after real doc edits and validator output are verified.

Replace the current [UID:0002HF] row in `by-memory/-coverage-report.md` with:

```md
        - [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md) 0x004a4570-0x004a4659 | method | EmployeeItemPropertyDialogPane::OnPaint : reconstructable : 89% : very strong : B004 2026-06-26 current MCP session `80de0a67` resolves the property-dialog paint slot: exact `0xe9` body ending at `0x004a4659`, seven `0xcc` bytes before sibling `0x004a4660`, vtable-only inbound data xref from slot `0x00618fe0`, direct class owner/emitter [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md), inherited dialog paint/setup, draw/text color `143`, `SELLITEM.EPF`/`SELLITEM.PAL` resource filename xrefs, `m_itemIconRect` at `this+0x270`, selected `m_itemRecord` at `this+0x280`, target-context record fields `itemImageId` at `+0x004` and `itemPaletteFlags` at `+0x006`, preserved `GetItemGlyphBounds` pre-draw call, `g_pItemObjImageLib->DrawItemImageIn43x43Slot`, and first-draft C++ on the target page.
```

Replace the current [UID:00004D] row in `by-class/-coverage-report.md` if the class score is raised:

```md
- [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md) : reconstructable : 88% : very strong : Feature-private EmployeeDialogPane property/price editor attached to [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md); B004 2026-06-26 current MCP resolves `OnPaint` resource draw and item sprite render through slot `0x00618fe0`, `m_itemIconRect`, `m_itemRecord`, `SELLITEM.EPF`/`.PAL`, `GetItemGlyphBounds`, and `g_pItemObjImageLib->DrawItemImageIn43x43Slot`; [UID:0002HF] and [UID:0002HG] now own first-draft exact method C++ through this class while constructor/destructor and broader record/layout aliases remain below final-audit status.
```

## Implementation Tracking Checklist

- [x] Lease only immediate by-* files selected for the accepted implementation batch; do not lease coverage files; release all leases immediately after edits and scoped validators. Proof: `python .\leaser.py Agent-B004 lease ...` returned `Success` for the nine accepted by-* edit files. The post-validator unlease command reported `Rejected[No active lease]` for those same paths, and `current_leases.md` re-read at `2026-06-26T17:21:01.1769245-04:00` showed no `Agent-B004` / `B004` active leases.
- [x] Update [UID:0002HF] metadata to `89/91`, owner/emitter `00004D`, reconstructable true, blank emitter position. Proof: target header now has `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00004D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004D`, blank `EMITTER_POSITION_OPTIONAL`; validator `000000003054` confirmed completion/confidence/canonical-owner/autogen-registry updates.
- [x] Add first-draft `EmployeeItemPropertyDialogPane::OnPaint()` C++ preserving the two EPFTileContext initializations, inherited dialog paint/setup, draw/text color `143`, `SELLITEM` lookup/render, glyph-bounds pre-draw call, `m_itemIconRect` expansion by `44`, and fixed-slot item-image draw. Proof: formal target C++ block contains the accepted body with `sellItemTile.Initialize()`, `itemGlyphContext.Initialize()`, `DialogPane::OnPaint()`, `SetDrawColor(143)`, `SetTextColor(143)`, `SELLITEM.EPF`, `SELLITEM.PAL`, `GetItemGlyphBounds`, `iconRect.right/bottom = left/top + 44`, and `DrawItemImageIn43x43Slot`.
- [x] Update [UID:0002HF] behavior, touched-state, IDA evidence, reconstruction notes, score rationale, cross-reference/change-log sections with current MCP evidence and corrected helper/field names from this report. Proof: target now records MCP session `80de0a67`, range/successor/padding, vtable-only xref, resource xrefs/bytes, decompile/disassembly/callee set, vtable dwords, `int_convert.py` conversions, source-facing names, rejected alternatives, and score rationale; validator `000000003054` exited `0`, `ok: 1`.
- [x] Update [UID:00004D] class page with the accepted OnPaint method map, owner/emitter route, resource/draw helper names, `m_itemIconRect`, `m_itemRecord`, `itemImageId`, and `itemPaletteFlags`; raise to `88/90` if accepted. Proof: class page header is `88/90`; method map and evidence now route [UID:0002HF] through [UID:00004D] with first-draft C++; validator `000000003055` exited `0`, `ok: 1`.
- [x] Update [UID:0001UB] layout with target C++ readiness notes for `m_itemIconRect` and `m_itemRecord`. Proof: layout rows `+0x270` and `+0x280`, method-offset evidence, vtable notes, and change log now state these fields feed accepted [UID:0002HF] C++; validator `000000003056` exited `0`, `ok: 1`.
- [x] Update [UID:0001UD] `EmployeeRecord` with target-context aliases for `+0x004` / `itemImageId` and `+0x006` / `itemPaletteFlags` without forcing broad record names. Proof: record layout keeps broad aliases and adds target-context aliases/evidence/open-question notes for [UID:0002HF]; validator `000000003057` exited `0`, `ok: 1`.
- [x] Update [UID:0000J0] file page and [UID:000138] aggregate with direct class-emitter routing for [UID:0002HF]. Proof: file contents/ownership/follow-up/change sections now route [UID:0002HF] through [UID:00004D]; aggregate status/range/disposition/ownership/change sections keep aggregate C++ blank and record class child routing. Validators `000000003058` and `000000003059` exited `0`, `ok: 1`.
- [x] Add short support notes to [UID:0001XH] and [UID:0002MF] confirming slot `0x00618fe0` now has target first-draft C++ and direct class owner/emitter `00004D`. Proof: vtable-family and exact vtable-data pages now record `0x00618fe0 -> 0x004a4570` with [UID:0002HF] first-draft C++ and direct owner/emitter [UID:00004D]; validators `000000003060` and `000000003061` exited `0`, `ok: 1`.
- [x] Add a support note to [UID:0002HE] constructor confirming initialized `m_itemIconRect` / `m_itemRecord` now feed accepted `OnPaint()` C++; do not add constructor C++ unless separately accepted. Proof: constructor item summary, construction flow, initialized-state table, evidence, reconstruction notes, and change log now state `m_itemIconRect`/`m_itemRecord` feed accepted [UID:0002HF] C++; constructor C++ remains blank; validator `000000003062` exited `0`, `ok: 1`.
- [x] Resource/read-only-data support docs optional/no-edit disposition recorded. Proof: no edits were made to [UID:0001R9][employee-dialog-resources](../../../../../by-resource/employee-dialog-resources.md), [UID:000256][EmployeeDialogReadOnlyData](../../../../../by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md), ItemObjImageLib helper pages, GrafPort accessors, Surface callback table, or ResourceLayoutTable pages; the target and support docs now cite their existing support and resource filename proof.
- [x] Do not edit any `-coverage-report.md`; leave the exact replacement text above for supervisor-owned application. Proof: no `-coverage-report.md` files were leased or manually edited during this implementation callback.
- [x] Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* file, using `python tools\validator.py --mode file --file <by-*> --apply`; record exit code, ok count, warnings, and generated/autogen side effects. Proof: validator commands below all exited `0` with `ok: 1`; all reported `generated_refresh: deferred` and `projected_stats_update: 1`.
- [x] Re-read active leases after unlease/release commands and report no active B004 leases before returning implementation completion. Proof: `current_leases.md` re-read after validators/unlease attempt listed only other agents (`B005`, `B014`) and no B004/Agent-B004 lease rows.

## Implementation Validator Results

| File | command_id | command_timestamp | Exit | ok | Warnings / side effects |
| --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md` | `000000003054` | `2026-06-26T17:19:46-04:00` | `0` | `1` | `generated_refresh: deferred`; metadata/autogen updates; link-label/reference-index updates. |
| `by-class/EmployeeItemPropertyDialogPane.md` | `000000003055` | `2026-06-26T17:20:01-04:00` | `0` | `1` | `generated_refresh: deferred`; `missing_ref_uid: 5` for existing `0003L5` references; metadata/autogen/link updates. |
| `by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md` | `000000003056` | `2026-06-26T17:20:03-04:00` | `0` | `1` | `generated_refresh: deferred`; `missing_ref_uid: 1` for existing `0003KW`; metadata/autogen/reference-index updates. |
| `by-type/by-struct/EmployeeRecord.md` | `000000003057` | `2026-06-26T17:20:04-04:00` | `0` | `1` | `generated_refresh: deferred`; metadata/autogen/link/reference-index updates. |
| `by-file/EmployeeDialogPane.md` | `000000003058` | `2026-06-26T17:20:06-04:00` | `0` | `1` | `generated_refresh: deferred`; `missing_ref_uid: 21` for existing `0003K*`/`0003L*` references. |
| `by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md` | `000000003059` | `2026-06-26T17:20:07-04:00` | `0` | `1` | `generated_refresh: deferred`; `missing_ref_uid: 46` for existing `0003K*`/`0003L*` references; one UID link insert. |
| `by-type/by-vtable/EmployeeDialogPaneVtables.md` | `000000003060` | `2026-06-26T17:20:14-04:00` | `0` | `1` | `generated_refresh: deferred`; canonical-owner/autogen/reference-index updates. |
| `by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md` | `000000003061` | `2026-06-26T17:20:21-04:00` | `0` | `1` | `generated_refresh: deferred`; metadata/autogen updates and header blank insertion. |
| `by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md` | `000000003062` | `2026-06-26T17:20:22-04:00` | `0` | `1` | `generated_refresh: deferred`; metadata/autogen/link/reference-index updates and header blank insertion. |

## Report-Only Validation State

Original report-only phase state: no validators were run then because that phase did not edit by-* documentation. Implementation callback validator results are recorded in the table above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0002HF-EmployeeItemPropertyDialogPaneOnPaint-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002HF-EmployeeItemPropertyDialogPaneOnPaint-source-quality.md","timestamp":"2026-06-26T17:24:12","uid":"0002HF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
