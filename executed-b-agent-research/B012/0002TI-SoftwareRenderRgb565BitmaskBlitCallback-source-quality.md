** TARGET-REPORT-UID:0002TI **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# 0002TI SoftwareRenderRgb565BitmaskBlitCallback Source Quality

## Executive Recommendation

UID0002TI remains a reconstructable Surface-owned RGB565 render-callback target under [UID:0000OC][Surface](../../../../../by-file/Surface.md) / `NexusTK/render/Surface.cpp`. The implementation callback has already applied that outcome: target metadata is `89/91`, owner/emitter routing remains `0000OC`, and the formal `RECONSTRUCTION_CPP CODE` block now contains first-draft `BlitRgb565BitmaskCallback` source. The report now stands as a post-callback artifact awaiting supervisor Gate 1 recheck and Gate 2 verification/execution; no further B012 by-* implementation is proposed unless supervisor verification finds a specific defect.

The source-quality decision is to emit the callback as file-local/static Surface code, not as a child split, not as a `SoftwareBlend16` helper, not as a `BalloonObjectPane` method, and not as aggregate-level RGB565 inventory code. The remaining uncertainty is naming confidence only: exact original callback spelling, final mode enum spellings, and the `GrafPort+0x78` member spelling remain inferred and cap confidence, but they no longer block first-draft C++.

## Supervisor Active Recheck

This same report was repaired after a Gate 1 section-matrix rejection. B012 did not run `execute_report`, any report lifecycle/archive command, any dry-run/probe execution variant, or any IDA DB/process/session-management mutation during this repair. B012 did not manually edit generated files, coverage reports, validator state, supervisor ledgers, or lifecycle/archive state. The only current repair edit is this report text in Agent-B012's own `research/` folder.

Prior implementation-callback work had already edited and scoped-validated the target/support by-* files listed in `Changed Files` and `Validator Results`. Those validator-generated side effects are recorded for supervisor verification, but they are not manual B012 edits to generated outputs.

## Finalized Report / Current Recommendation

Implementation callback has been applied for UID0002TI. UID0002TI remains a reconstructable Surface-owned RGB565 render-callback target, and the previously empty formal C++ has been replaced with first-draft `BlitRgb565BitmaskCallback` source in the target's formal block.

Applied target outcome for `by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md`: `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank `EMITTER_POSITION_OPTIONAL`, and populated formal C++ block. The exact original callback spelling and two GrafPort color member spellings remain inferred, so confidence remains below final-audit quality. The artifact is now awaiting supervisor Gate 2 review/execution, not further B012 implementation.

## Supporting Research

This pass used current IDA MCP evidence from active session `73c77998` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` plus current by-* documentation. MCP `server_health` was `ok`, `auto_analysis_ready:true`, and `hexrays_ready:true`. `idb_list` showed session `73c77998` active, IDB-backed, not analyzing.

The target belongs to the RGB565 callback family under [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](../../../../../by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md) and the shared Surface callback table [UID:0000TN][SurfaceRenderCallbackTable](../../../../../by-global/SurfaceRenderCallbackTable.md). The direct source parent remains [UID:0000OC][Surface](../../../../../by-file/Surface.md), not the non-emitting RGB565 aggregate and not [UID:0000NT][SoftwareBlend16](../../../../../by-file/SoftwareBlend16.md).

## Target

- UID: `0002TI`
- Target path: `by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md`
- Range: `0x004c3ea0-0x004c4364`
- IDA function: `sub_4C3EA0`
- Source-facing target name recommended for docs/formal C++: `BlitRgb565BitmaskCallback`
- Callback slot: `dword_69B3F8` / `0x0069b3f8`
- Source parent: [UID:0000OC][Surface](../../../../../by-file/Surface.md), `NexusTK/render/Surface.cpp`

## Current Target State

Current by-* metadata after callback:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `89` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | `0000OC` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000OC` |
| Formal C++ | populated with `BlitRgb565BitmaskCallback` |

The stale item-summary phrase saying the target remained unassigned due to child/parent gate failure has been historicalized in the target. The target now records the applied Surface owner/emitter route, current MCP evidence, and first-draft formal C++.

## Heuristic / Inference Reanalysis And Validation

The old blockers were mask source layout, callback signature, mode names, final helper names, and local switch-data treatment. Current evidence resolves them enough for first-draft C++:

- The decompile and peer UID0002TE prove the ABI shape: hidden/unused fastcall slot, destination `GrafPort` receiver, packed bitmask byte stream, source bounds `RectBounds`, and mode byte. The formal body keeps the unused parameter explicitly to match the observed callback ABI.
- Mask layout is not an opaque object. The code treats the third parameter as contiguous packed 1bpp rows with row width derived from the supplied source rectangle. Bit index is `(sourceY * sourceWidth + sourceX) % 8`, and bit mask is `0x80 >> bit`.
- Mode behavior is source-ready even if enum spellings are inferred. Mode `0` writes primary/secondary colors for set/clear bits; mode `1` writes primary color only for set bits; mode `2` blends every pixel with the selected primary/secondary color at weight `16`; mode `3` blends only set bits with primary color at weight `16`.
- Helper names are support-backed: `GrafPort::GetClipRect`, `InitRectBounds`, `IntersectRects`, `IsRectEmptyOrInvalid`, `PaletteLib::GetCurrentPalette`, `DLPalette::MapColor`, and `BlendRgb565Pixel` are documented in current support pages. `m_drawColor` at `+0x74` is support-backed through `GrafPortDrawStateAccessors`; the `+0x78` field is the draw/display-mode-adjacent color state and is best documented here as inferred `m_secondaryDrawColor` for this callback's primary/secondary bitmask color pair.
- The switch table at `0x004c4364-0x004c4374` is local data for this function and `0x004c4374-0x004c4380` is `0xcc` alignment. It is represented as structured `switch (mode)`, not a child data page.
- UID0002TE is the RGB555/compat peer and proves the source family relationship. It is not an owner and does not block UID0002TI from emitting RGB565-specific C++ because UID0002TI delegates blending to the already source-ready `BlendRgb565Pixel`.

## Inference Research Guidance Check

The score/source-quality blockers were researched to resolution rather than deferred. The target had no code callers and only data refs, so ownership was tested through callback-table installation, sibling render-callback family placement, slot consumers, peer UID0002TE behavior, and support docs for `GrafPort`, rectangle helpers, palette mapping, and `BlendRgb565Pixel`. The result clears the emitter route through Surface while preserving negative evidence that direct reachability is table-driven.

No rare no-improvement exception is claimed. The report and implementation improve the target from blank-emitter source-blocked status to formal first-draft C++ with documented inference caps. The unsupported parts are limited to exact original names, not behavior, range, owner, route, or source placement.

## Evidence Standards Used

Facts marked MCP-backed come from narrow current session calls. Existing by-* pages are used as current support documentation, not as a substitute for the MCP pass. Older executed reports are lead/support evidence only where their claims match current by-* docs and the refreshed MCP results. Names without direct symbol proof are labeled as inferred source-facing names and kept below final-audit confidence.

## Evidence Checked

- MCP session `73c77998`: `idb_list` active session check and `server_health` ok check.
- MCP `lookup_funcs` for `0x004c3ea0`, `0x004c4364`, `0x004c4380`, `0x004be0e0`, `0x004be66e`, `0x00558840`, and `0x004c6050`.
- MCP `func_profile` for `0x004c3ea0` and `0x004be0e0`.
- MCP `xref_query` for target start `0x004c3ea0`, slot `0x0069b3f8`, and peer start `0x004be0e0`.
- MCP `decompile` for target `0x004c3ea0` and peer `0x004be0e0`.
- MCP `get_bytes` for `0x004c4364`, peer `0x004be66e`, and pre-target padding `0x004c3e93`.
- MCP `int_convert` for `0x4c4`, `0x58e`, `0x1c`, `0x10`, `0x71`, `0x74`, `0x78`, and `0x69b3f8`.
- Current by-* docs checked: target UID0002TI, `Surface.md`, RGB565 aggregate UID00016L, `SurfaceRenderCallbackTable`, UID0002TE, UID00016M `BlendRgb565Pixel`, `GrafPort.md`, `GrafPortGetClipRect`, `GrafPortDrawStateAccessors`, `RectGeometryHelpers`, `RectBounds`, `SoftwareBlend16.md`, `g_pPaletteLib.md`, `BalloonObjectPane`, and `BalloonObjectPaneStaticMasks`.
- Executed-report search terms: `0002TI`, `0x004c3ea0`, `SoftwareRenderRgb565BitmaskBlitCallback`, `dword_69B3F8`, `0x0069b3f8`, `bitmask`, `PaintBubble`, `SurfaceBitmask`, `slot 6`. Matching executed reports B001 UID00016L and B004 UID000276 were used only where aligned with current docs/MCP.

## IDA MCP Facts

- Session: `73c77998`; `server_health` returned `ok`; `auto_analysis_ready:true`; `hexrays_ready:true`; `idb_list` showed the NexusTK IDB active and not analyzing.
- `lookup_funcs`: `0x004c3ea0` is `sub_4C3EA0`, size `0x4c4`; `0x004c4364` is not a function; `0x004c4380` is `sub_4C4380`; peer `0x004be0e0` is `sub_4BE0E0`, size `0x58e`; peer `0x004be66e` is not a function; `0x00558840` is `sub_558840`; `0x004c6050` is `sub_4C6050`.
- Target `func_profile`: size `0x4c4` / 1220 bytes, 445 instructions, 49 blocks, zero callers, nine callees, zero strings, 55 constants, and decompiler prototype shape `char __fastcall(int, int, int, __int128 *, char)`.
- Target callees: self-artifact `sub_4C3EA0`, rectangle helpers `sub_4B96C0`, `sub_4B7CC0`, `sub_4B7EB0`, `sub_4B7C50`, palette helpers `sub_543D40`/`sub_542AC0`, `@__security_check_cookie@4`, and RGB565 blend helper `sub_4C6050`.
- Target decompile facts: first parameter is the `GrafPort` draw receiver, second fastcall slot is unused, third parameter is a packed bitmask byte stream, fourth parameter is source `RectBounds`, fifth parameter is mode. The body gates on `GrafPort+0x71`, clips through current clip/source bounds, maps colors from `+0x74/+0x78`, walks 1bpp mask bits, writes/blends RGB565 pixels, and returns `mode`.
- Byte facts: pre-target `0x004c3e93` has `0xcc` padding; `0x004c4364-0x004c4380` bytes are four target dwords `0x004c3fdf`, `0x004c40be`, `0x004c4193`, `0x004c427d` followed by twelve `0xcc` bytes.
- Numeric facts checked with MCP `int_convert`: `0x4c4` = 1220, `0x58e` = 1422, `0x1c` = 28, `0x10` = 16, `0x71` = 113, `0x74` = 116, `0x78` = 120, and `0x69b3f8` = 6927352.

## Function / Child Inventory

| Range | UID / role | Current disposition | Evidence and status |
| --- | --- | --- | --- |
| `0x004c3ea0-0x004c4364` | UID0002TI `SoftwareRenderRgb565BitmaskBlitCallback` | Source-bearing target; `RECONSTRUCTABLE:TRUE`, owner/emitter `0000OC`, formal C++ populated | Exact function body, 1220 bytes, Surface callback-table target, first-draft `BlitRgb565BitmaskCallback` applied |
| `0x004c4364-0x004c4374` | local switch target table | No child page; no separate emitter | Four local intra-function branch targets; represented as structured `switch (mode)` in formal C++ |
| `0x004c4374-0x004c4380` | alignment padding | No child page; no reconstruction | Twelve `0xcc` bytes after local switch table |
| `0x004be0e0-0x004be66e` | UID0002TE compat/RGB555 peer | Support/peer evidence only | Same callback signature and mode family; proves source shape but does not own UID0002TI |
| `0x004c6050-0x004c60c7` | UID00016M `BlendRgb565Pixel` | Already-present dependency | RGB565 blend helper called from target modes 2/3; not the callback owner |

No split was applied or recommended. The child/split route would create an artificial data item for a compiler switch table and would lose source shape.

## Direct Xref / Caller Inventory

MCP xrefs to function start `0x004c3ea0` found zero direct code callers and exactly two target data refs: raw setup at `0x0055881d` and `sub_558840` setup at `0x00558ed8`. This is expected for a callback installed into a render callback table, and it supports Surface source placement rather than no-owner status.

MCP xrefs to `dword_69B3F8` / `0x0069b3f8` found twelve data refs. Nine are `BalloonObjectPane::PaintBubble` consumer reads at `0x467c29`, `0x467c5e`, `0x467c92`, `0x467cd3`, `0x467d08`, `0x467d39`, `0x467d6b`, `0x467e5d`, and `0x467efb`. The setup refs are `0x55879d`, `0x558bbc`, and `0x558ed8`. Peer UID0002TE has two setup data refs at `0x0055872f` and `0x00558bbc`.

## Documentation Evidence And IDA Status

Current docs after implementation agree with the MCP pass: UID0002TI is source-ready under Surface, the RGB565 aggregate remains non-emitting inventory, the Surface callback table records slot `dword_69B3F8`, and PaintBubble is documented as a consumer. `BlendRgb565Pixel`, rectangle helpers, palette access, and draw-state support pages provide the helper/type direction used by formal C++.

The documentation/IDA discrepancy that initially kept this target blank has been resolved as a route issue, not a behavior issue: lack of direct code callers is not evidence that the function is dead or unowned, because the two target data refs and table slot refs prove callback installation and consumption. The remaining docs explicitly preserve the no-direct-start caveat while allowing Surface emission.

## Range / Split / Padding / Reclassification Analysis

The target range remains `0x004c3ea0-0x004c4364`. MCP confirms `0x004c4364` is not a function and the following bytes are four local switch-table dwords plus `0xcc` alignment through `0x004c4380`. The next real function starts at `0x004c4380`, so the target boundary is exact and no padding is incorrectly absorbed into the source body.

Reclassification applied: the target moved from stale blank-emitter/source-blocked wording at `86/88` to `COMPLETION:89`, `CONFIDENCE:91` with formal C++ populated. No parent/child split, aggregate reclassification, or child page creation is needed.

## IDA Rename / Type / Comment Recommendations

No IDA rename, type application, comment insertion, or database mutation was performed by B012. Source-facing documentation now uses inferred `BlitRgb565BitmaskCallback`, `GrafPort *port`, `const unsigned char *maskBits`, `const RectBounds *sourceBounds`, `unsigned char mode`, `m_drawColor`, and inferred `m_secondaryDrawColor`. Exact original callback name, mode enum names, and `+0x78` member spelling remain confidence caps rather than blockers.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual supervisor-owned `-coverage-report.md` or tracker text is required. Coverage/tracker refresh is validator-owned after supervisor execution. If the supervisor wants a human note, the exact text is: `UID0002TI now has Surface-owned first-draft formal C++ for BlitRgb565BitmaskCallback at 0x004c3ea0-0x004c4364; slot dword_69B3F8 remains callback-table data and the local switch table at 0x004c4364 is not a child.`

## Follow-Up Actions

Supervisor should perform Gate 1 recheck on this repaired report text, then Gate 2 verify the already-applied target/support by-* changes and scoped validator results. If both pass, supervisor may run the owned `execute_report` lifecycle command. B012 has no remaining implementation action unless Gate 2 identifies a specific missing destination fact or validator defect.

## Confidence

Confidence is `91`, not final-quality `95+`, because the binary has no original symbol proof for the callback name, mode enum names, or exact `GrafPort+0x78` member spelling. Confidence is still high enough for first-draft C++ because MCP, peer UID0002TE, callback-table xrefs, helper docs, field offsets, and decompile behavior agree on range, route, ABI, data layout, and side effects.

## Claim And Incorporation Ledger

| ID | Claim | Action | Destination | Verification state |
| --- | --- | --- | --- | --- |
| TI-001 | Target is exact `sub_4C3EA0`, range `0x004c3ea0-0x004c4364`, size `0x4c4` / 1220 bytes. | incorporate | applied to target, RGB565 aggregate, Surface support, callback table docs | applied |
| TI-002 | `0x004c4364` is not a function; `0x004c4364-0x004c4380` is four local switch target dwords plus twelve `0xcc` bytes. | incorporate | applied to target and callback-table/aggregate notes | applied |
| TI-003 | Target has zero direct code callers and exactly two target data refs, raw setup `0x0055881d` and `sub_558840` at `0x00558ed8`. | incorporate | applied to target, Surface, and table support | applied |
| TI-004 | `dword_69B3F8` has twelve slot refs, including nine `BalloonObjectPane::PaintBubble` consumer reads and setup refs at `0x0055879d`, `0x00558bbc`, and `0x00558ed8`. | incorporate | applied to target, Surface, by-global table, by-memory table; BalloonObjectPane itself already had consumer evidence at sufficient detail | applied |
| TI-005 | Source route remains Surface `0000OC`; RGB565 aggregate is a non-emitting inventory and SoftwareBlend16 is only the blend-helper dependency. | incorporate | applied to target, Surface, RGB565 aggregate, and table docs; SoftwareBlend16 support already sufficient | applied |
| TI-006 | Formal callback body uses packed bitmask rows, `RectBounds` clipping, `GrafPort` surface-context fields, palette color mapping, and four mode cases. | incorporate | applied to target formal C++ and behavior notes; support docs summarized at report-level detail | applied |
| TI-007 | `BlendRgb565Pixel(*pixel, color, 16)` is the exact RGB565 blend dependency in modes 2 and 3. | already-present/incorporate | target and support docs link UID00016M; UID00016M already recorded two callers from `0x004c3ea0` at sufficient detail | applied |
| TI-008 | `m_drawColor` at `+0x74` is support-backed; `+0x78` is documented as inferred `m_secondaryDrawColor` for this callback. | incorporate | applied to target and GrafPortDrawStateAccessors as target-level inferred alias over existing `+0x78` color field | applied |
| TI-009 | Existing target item summary and blank-C++ blocker wording are stale. | historicalize | applied to target item summary/reconstruction notes and peer wording | applied |
| TI-010 | No split or child page is required; jump table is local function data and should not become an owned data item. | not-applicable | applied to target and aggregate/table notes | applied |

## Positive Evidence Summary

- MCP function profile reports `sub_4C3EA0` as size `0x4c4`, 445 instructions, 49 basic blocks, zero callers, nine callees, no strings, and prototype-shaped `char __fastcall(int, int, int, __int128 *, char)`.
- Target xrefs are data-only and exactly match callback-table installation: `0x0055881d` raw setup and `0x00558ed8` in `sub_558840`.
- Slot `0x0069b3f8` / `dword_69B3F8` is consumed by `BalloonObjectPane::PaintBubble` and initialized with compat/RGB565 bitmask callbacks by Surface setup code.
- Decompile proves draw-enabled guard at `GrafPort+0x71`, clipping through `GetClipRect`, `IntersectRects`, and `IsRectEmptyOrInvalid`, packed bit traversal, destination pointer math through `m_surfaceContext`, palette mapping of fields `+0x74/+0x78`, and four mode cases.
- UID0002TE is structurally the RGB555 peer with the same signature and mode shape; the difference is RGB555 inline half-blend math versus UID0002TI's `BlendRgb565Pixel` dependency.
- `BlendRgb565Pixel` is already formal first-draft C++ and exactly matches the RGB565 blend semantics needed here.

## Negative Evidence Summary

- No direct code caller exists for `0x004c3ea0`; source placement must be through callback-table installation, not ordinary call graph.
- No symbol proof exists for the exact original callback function name, mode enum names, or `+0x78` member spelling. The report uses source-facing inferred names and caps confidence accordingly.
- `0x004c4364` is not a child function and does not justify a split; it is local switch-table data plus alignment.
- `BalloonObjectPane` is a consumer of `dword_69B3F8`, not the owner of the callback implementation.
- `SoftwareBlend16` owns `BlendRgb565Pixel` but not the callback body. Moving UID0002TI there would invert dependency direction.
- The RGB565 aggregate UID00016L is a non-emitting inventory; emitting aggregate-level code would duplicate exact child responsibility.

## Ranked Ownership Analysis

1. [UID:0000OC][Surface](../../../../../by-file/Surface.md) / `NexusTK/render/Surface.cpp`: best owner and current owner. Evidence: callback-table setup, Surface render initializer, sibling compat/RGB565 callbacks, current parent gate, and process-wide render dispatch role.
2. [UID:00016L][SoftwareRenderRgb565Callbacks](../../../../../by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md): useful non-emitting inventory only. It documents family membership and boundary context but should not own emitted source.
3. [UID:0000NT][SoftwareBlend16](../../../../../by-file/SoftwareBlend16.md): rejected as direct owner. It owns stateless RGB565 math helpers such as `BlendRgb565Pixel`; UID0002TI is a callback-table target that calls that helper.
4. [UID:0000YZ][BalloonObjectPane](../../../../../by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md): rejected. PaintBubble reads the callback slot and passes mask data; it does not define/install the callback.
5. No-owner/non-emitting: rejected. Current owner/emitter route already clears the gate and the remaining blockers are resolvable with formal first-draft C++.

## Source Placement

Keep emitted source under `NexusTK/render/Surface.cpp` through UID0000OC. The body is file-local/static callback-style code near the RGB565 software renderer callbacks and adjacent to the `dword_69B3F8` callback-table setup documentation. Do not create `SoftwareBlend16.cpp` ownership, do not move it under BalloonObjectPane, and do not split the local switch table.

## First-Draft C++ Recommendation

The implementation callback inserted this exact formal `RECONSTRUCTION_CPP CODE` block into the target:

```cpp
static unsigned char __fastcall BlitRgb565BitmaskCallback(
    GrafPort *port,
    int /*unused*/,
    const unsigned char *maskBits,
    const RectBounds *sourceBounds,
    unsigned char mode)
{
    if (!port->m_drawEnabled) {
        return 0;
    }

    RectBounds clipBounds;
    port->GetClipRect(&clipBounds);

    RectBounds clippedBounds = *sourceBounds;
    IntersectRects(&clipBounds, &clippedBounds, &clippedBounds);
    if (IsRectEmptyOrInvalid(&clippedBounds)) {
        return 0;
    }

    RectBounds sourceOrigin;
    InitRectBounds(&sourceOrigin,
                   0,
                   0,
                   sourceBounds->right - sourceBounds->left,
                   sourceBounds->bottom - sourceBounds->top);

    const int sourceWidth = sourceOrigin.right - sourceOrigin.left;
    const int startSourceY = clippedBounds.top - sourceBounds->top + sourceOrigin.top;
    const int startSourceX = clippedBounds.left - sourceBounds->left + sourceOrigin.left;
    const int endSourceY = clippedBounds.bottom - sourceBounds->bottom + sourceOrigin.bottom;
    const int endSourceX = sourceOrigin.right + clippedBounds.right - sourceBounds->right;
    const int width = endSourceX - startSourceX;
    const int height = endSourceY - startSourceY;

    const int startBitOffset = startSourceY * sourceWidth + startSourceX;
    const unsigned char *rowMask = maskBits + startBitOffset / 8;
    unsigned char rowBit = static_cast<unsigned char>(startBitOffset % 8);

    unsigned short *rowPixels = reinterpret_cast<unsigned short *>(
        port->m_surfaceContext.pixelData +
        2 * (clippedBounds.left +
             port->m_surfaceContext.rowStride *
                 (clippedBounds.top - port->m_surfaceContext.bounds.top) -
             port->m_surfaceContext.bounds.left));

    DLPalette *palette = g_pPaletteLib->GetCurrentPalette();
    const unsigned short primaryColor = palette->MapColor(port->m_drawColor);
    const unsigned short secondaryColor = palette->MapColor(port->m_secondaryDrawColor);

    for (int y = 0; y < height; ++y) {
        const unsigned char *mask = rowMask;
        unsigned char bit = rowBit;
        unsigned short *pixel = rowPixels;

        for (int x = 0; x < width; ++x) {
            const bool maskSet = ((*mask & (0x80 >> bit)) != 0);

            switch (mode) {
            case 0:
                *pixel = maskSet ? primaryColor : secondaryColor;
                break;
            case 1:
                if (maskSet) {
                    *pixel = primaryColor;
                }
                break;
            case 2:
                *pixel = BlendRgb565Pixel(*pixel,
                                           maskSet ? primaryColor : secondaryColor,
                                           16);
                break;
            case 3:
                if (maskSet) {
                    *pixel = BlendRgb565Pixel(*pixel, primaryColor, 16);
                }
                break;
            default:
                return mode;
            }

            ++pixel;
            if (bit == 7) {
                ++mask;
                bit = 0;
            } else {
                ++bit;
            }
        }

        const int nextRowBitOffset = sourceWidth + rowBit - sourceOrigin.left;
        rowMask += nextRowBitOffset / 8;
        rowBit = static_cast<unsigned char>(nextRowBitOffset % 8);
        rowPixels += port->m_surfaceContext.rowStride;
    }

    return mode;
}
```

The body intentionally uses inferred source-facing names instead of IDA labels. `BlitRgb565BitmaskCallback`, `m_secondaryDrawColor`, and any future mode enum names remain candidates for later family-wide naming cleanup, not blockers for target-level first-draft C++.

## Final Recommendation

Implementation callback is complete for UID0002TI. The target moved from blank C++ at `86/88` to first-draft formal C++ at `89/91`, preserving Surface owner/emitter routing. Target prose and direct support docs were updated at report-level detail; remaining action is supervisor Gate 2 verification/execution.

## Recommended Target Doc Changes

Accepted target doc changes applied to `by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md`:

- Set `COMPLETION:89`, `CONFIDENCE:91`.
- Kept `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, and blank `EMITTER_POSITION_OPTIONAL`.
- Replaced the blank formal C++ block with the `BlitRgb565BitmaskCallback` code above.
- Historicalized the stale item-summary phrase that said it remained unassigned due to gate failure.
- Added MCP session `73c77998` evidence: exact range, `0x4c4` / 1220-byte size, 445 instructions, 49 blocks, zero callers, two target data refs, twelve slot refs, callee set, local switch table bytes, and no function at `0x004c4364`.
- Recorded source-facing behavior: packed 1bpp mask rows, `RectBounds` clipping, `GrafPort` surface-context pointer math, color mapping from `+0x74/+0x78`, four mode cases, RGB565 blend weight `16`, and local switch table as structured `switch`.
- Preserved negative evidence: no direct code callers, no exact original callback spelling, no final mode enum names, and no ownership by BalloonObjectPane, RGB565 aggregate, or SoftwareBlend16.

## Recommended Support Doc Changes

- `by-file/Surface.md`: updated UID0002TI row/status from blank-C++/source-blocked wording to source-ready first-draft C++ under `NexusTK/render/Surface.cpp`; included zero direct callers, setup/table refs, packed bitmask modes, and RGB565 `BlendRgb565Pixel` dependency.
- `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md`: updated the slot-6 row to say UID0002TI now has target-level first-draft C++ while the aggregate remains non-emitting.
- `by-global/SurfaceRenderCallbackTable.md` and `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`: refined `dword_69B3F8` slot wording with current UID0002TI mode behavior and source-ready status; preserved PaintBubble as consumer only.
- `by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md`: updated stale peer wording that still treated UID0002TI as source-blocked by shared blockers.
- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`: added explicit `+0x78` inferred `m_secondaryDrawColor` consumer evidence for UID0002TI.
- `by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md`, `by-class/GrafPort.md`, `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`, `by-class/RectBounds.md`, and `by-global/g_pPaletteLib.md`: verified as already present at same-or-greater support detail and not edited.
- Coverage reports and generated files were not manually edited. Scoped validators were run only for changed by-* files during the implementation callback.

## Score And Metadata Recommendation

Applied metadata after callback:

| Field | Recommended value | Rationale |
| --- | --- | --- |
| `COMPLETION` | `89` | Formal first-draft C++ becomes available, target range and switch-data boundary are exact, owner/emitter route is resolved, behavior and support dependencies are documented. |
| `CONFIDENCE` | `91` | MCP evidence, peer comparison, support docs, and helper names align. Confidence remains below final because exact original callback name, mode enum names, and `+0x78` field spelling are inferred. |
| `CANONICAL_OWNER` | `0000OC` | Surface owns callback-table setup and render-callback family placement. |
| `RECONSTRUCTABLE` | `TRUE` | Custom NexusTK callback implementation. |
| `EMITTER_UIDS` | `0000OC` | Source emits through `NexusTK/render/Surface.cpp`. |

No split was applied or recommended. The local jump table remains documented as function-local switch data, not a standalone reconstructable data item.

## Open Questions With Attempted Resolution

- Exact callback name: unresolved original spelling. Resolution: use `BlitRgb565BitmaskCallback` as a descriptive file-local source name; this is good enough for first-draft code and should be labeled inferred.
- Exact callback typedef: unresolved original type. Resolution: use `static unsigned char __fastcall` with explicit unused fastcall parameter because target and peer decompiles agree on `char __fastcall(int, int, int, __int128 *, char)` shape and callback-table dispatch implies a file-local target.
- Mode enum names: unresolved original spelling. Resolution: keep numeric `case 0..3` in first draft; behavior is fully documented.
- Mask layout: resolved enough. It is a packed 1bpp row stream; no external structure is needed for this target.
- `GrafPort+0x78` field spelling: not final. Resolution: document as inferred `m_secondaryDrawColor` for this callback's secondary mask color; support docs already identify the nearby draw-state family and `+0x74` active draw color.
- Jump-table child: rejected. The bytes are local switch targets plus alignment and are represented as structured control flow.

## Validator Results

Scoped validators were run from `source-3/project-documentation` for every changed by-* file after callback implementation:

| File | Command | command_id | command_timestamp | Exit | ok | Warnings / generated refresh |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md` | `python .\tools\validator.py --mode file --file by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md --apply --queue-timeout 240` | `000000006149` | `2026-07-04T05:57:26-04:00` | 0 | 1 | no warnings; `generated_refresh: deferred` |
| `by-file/Surface.md` | `python .\tools\validator.py --mode file --file by-file/Surface.md --apply --queue-timeout 240` | `000000006150` | `2026-07-04T05:57:28-04:00` | 0 | 1 | pre-existing `missing_ref_uid:30`; `generated_refresh: deferred` |
| `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md` | `python .\tools\validator.py --mode file --file by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md --apply --queue-timeout 240` | `000000006152` | `2026-07-04T05:57:30-04:00` | 0 | 1 | no warnings; `generated_refresh: deferred` |
| `by-global/SurfaceRenderCallbackTable.md` | `python .\tools\validator.py --mode file --file by-global/SurfaceRenderCallbackTable.md --apply --queue-timeout 240` | `000000006153` | `2026-07-04T05:57:33-04:00` | 0 | 1 | pre-existing `missing_ref_uid:9`; `generated_refresh: deferred` |
| `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` | `python .\tools\validator.py --mode file --file by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md --apply --queue-timeout 240` | `000000006155` | `2026-07-04T05:57:45-04:00` | 0 | 1 | pre-existing `missing_ref_uid:8`; `generated_refresh: deferred` |
| `by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md` | `python .\tools\validator.py --mode file --file by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md --apply --queue-timeout 240` | `000000006156` | `2026-07-04T05:57:47-04:00` | 0 | 1 | no warnings; `generated_refresh: deferred` |
| `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md --apply --queue-timeout 240` | `000000006157` | `2026-07-04T05:57:49-04:00` | 0 | 1 | pre-existing `missing_ref_uid:4`; `generated_refresh: deferred` |

Validator side effects reported: projected stats updates and deferred generated refresh for each command. Narrow status confirms validator-owned refresh touched `auto-generated/NexusTK/render/Surface.cpp` and `auto-generated/NexusTK/render/GrafPort.cpp`, and projected stats touched `project-level/-auto-completion-stats.md`. `Surface.cpp` now includes UID0002TI `BlitRgb565BitmaskCallback` at header `validator-command-id: 000000006156`; `GrafPort.cpp` refreshed at header `validator-command-id: 000000006157`. No generated files, coverage reports, validator state, or lifecycle/archive files were manually edited.

## Changed Files

- `by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md`
- `by-file/Surface.md`
- `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md`
- `by-global/SurfaceRenderCallbackTable.md`
- `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
- `by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md`
- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
- `tools/leaser/Agents/Agent-B012/research/0002TI-SoftwareRenderRgb565BitmaskBlitCallback-source-quality.md`
- Validator-generated side effects: `auto-generated/NexusTK/render/Surface.cpp`, `auto-generated/NexusTK/render/GrafPort.cpp`, and `project-level/-auto-completion-stats.md`.

No generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers were manually edited. Scoped validators reported deferred generated refresh and projected stats side effects, listed above for supervisor visibility.

## Implementation Tracking Checklist

- [x] Target `by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md`: set `COMPLETION:89`, `CONFIDENCE:91`, preserved owner/emitter/reconstructable route, inserted formal C++ exactly, and updated summary/status/evidence/score text with MCP session `73c77998`.
- [x] Target: preserved negative evidence and rejected alternatives: no direct code callers, no exact original callback spelling, inferred mode names, local switch-table handling, and rejected BalloonObjectPane/RGB565 aggregate/SoftwareBlend16 ownership.
- [x] `by-file/Surface.md`: updated UID0002TI as first-draft C++ eligible/source-ready through `NexusTK/render/Surface.cpp`, with callback-table setup and sibling callback family evidence.
- [x] `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md`: updated slot-6 row/status while keeping the aggregate non-emitting.
- [x] `by-global/SurfaceRenderCallbackTable.md` and `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`: updated `dword_69B3F8` slot behavior/source-ready wording and retained PaintBubble as consumer only.
- [x] Peer/support verification: UID0002TE had stale shared-blocker wording and was updated; GrafPortDrawStateAccessors needed explicit `+0x78` inferred alias support and was updated. UID00016M, GrafPort, RectGeometryHelpers, RectBounds, and g_pPaletteLib were already present at same-or-greater support detail and were not edited.
- [x] Ran scoped validators from `source-3/project-documentation` for every changed by-* file with `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`; all seven exited 0 with `ok:1`.
- [x] Updated this report's Claim And Incorporation Ledger and checklist with `applied`/`already-present` states, validator command IDs/timestamps/exit/ok counts, warnings, and deferred generated-refresh state. Validator-owned generated outputs show `Surface.cpp` refreshed with UID0002TI formal C++ and `GrafPort.cpp` refreshed after the support sync; no manual generated edits were made.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000006213","destination_path":"executed-b-agent-research/B012/0002TI-SoftwareRenderRgb565BitmaskBlitCallback-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/0002TI-SoftwareRenderRgb565BitmaskBlitCallback-source-quality.md","timestamp":"2026-07-04T11:32:38-04:00","uid":"0002TI"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
