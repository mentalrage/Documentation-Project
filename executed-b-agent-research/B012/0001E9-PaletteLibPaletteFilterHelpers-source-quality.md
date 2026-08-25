** TARGET-REPORT-UID:0001E9 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# Agent-B012 Research Report: 0001E9 PaletteLib Palette Filter Helpers

Initial report-only pass for [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](../../../../../by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md), followed by the accepted 2026-06-29 implementation callback. The callback applied only the accepted support cleanup; the UID0001E9 target metadata and existing formal C++ were not changed.

## Assignment And Constraints

- Agent: `Agent-B012`.
- Target: `by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md`.
- Required report path: `tools/leaser/Agents/Agent-B012/research/0001E9-PaletteLibPaletteFilterHelpers-source-quality.md`.
- Mode: accepted implementation callback for support cleanup only after supervisor validation.
- IDA MCP: mandatory and used successfully.
- Subagents: not used.
- Leases: callback leases were taken only for `by-class/PaletteLib.md`, `by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md`, `by-file/Palette.md`, and `by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md`; all four were released immediately after the edit/validator batch.

## Current Rule 26 Revision Summary

This 2026-06-29 revision preserves the original B012 evidence but supersedes its old implementation recommendation where later accepted work already incorporated the same or stronger details. The target page is no longer `86/90` with blank C++; after executed B014 implementation it is `91/91`, owned/emitted by [UID:0000A1] `PaletteLib`, and already contains formal `RECONSTRUCTION_CPP CODE`.

Current disposition:

| Topic | Current recommendation |
| --- | --- |
| Target metadata | Keep `COMPLETION:91`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000A1`, `EMITTER_UIDS:0000A1`, `RECONSTRUCTABLE:TRUE`. No target score movement is requested by this B012 revision. |
| Target C++ | Keep the already-present `SetPaletteFilterActive`, `GetPaletteFilterWeight`, and `UpdatePaletteFilterTables` formal C++ block. Do not replace it with the old B012 `SetPaletteFilterEnabled` / `void` draft. |
| Target evidence | Existing target/support docs already preserve the valid B012 evidence at same-or-greater detail: boundaries, callers, raw-getter retention, `+0x758`, `+0x75c`, `dword_69B408`, slot 11 skip, and source placement. |
| Implementation callback scope | Accepted and completed on 2026-06-29: core UID0001E9 facts were verified as already present, and only the accepted stale-source/stale-summary cleanup rows were applied. |

The score remains below final-audit range because exact original member spellings, exact Surface callback typedef spelling, and the broader `Palette.cpp` versus `PaletteLib.cpp` source split remain inferred. Those are documented support-quality limits, not blockers for the already-present target C++.

## Current Target State

Current file: `by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md`.

| Field | Current state checked 2026-06-29 |
| --- | --- |
| `COMPLETION` | `91` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | `0000A1` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000A1` |
| Formal C++ | populated and generated to `auto-generated/NexusTK/render/PaletteLib.cpp` |
| Generated coverage | `auto-generated/-ag-memory-coverage.md` marks UID `0001E9` `coded` through `0000A1` to `auto-generated/NexusTK/render/PaletteLib.cpp`; `auto-generated/-ag-coverage-report-by-memory.md` marks `emits_code:true` at `91%`. |

The current target page already records B014's 2026-06-26 source-quality implementation. This B012 revision therefore does not request a second target rewrite. It records a current MCP spot-check, rejects stale B012 draft details, and identifies concrete support stale-source repairs that remain implementation-ready.

## Evidence Checked

Current docs and generated read-only inputs checked:

| Source | Use |
| --- | --- |
| `goal.md` | Assignment scope, initial report-only restriction, accepted callback scope, lease/validator requirements, and forbidden-edit constraints. |
| `ntk-b-agent-workflow` references | Current report format, Rule 26 incorporation, score-blocker, C++ code-entry, and stale-source handling rules. |
| `by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md` | Current target metadata, formal C++, evidence sections, score rationale, and change log. |
| `by-class/PaletteLib.md`, `by-file/PaletteLib.md`, `by-file/Palette.md`, `by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md` | Direct class/source/support state and stale-source wording audit. |
| `by-item/PaletteSlotTable.md`, `by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md` | Slot 11 and related transform-family support; stale-summary audit for `0002R4`. |
| `by-global/g_pPaletteLib.md`, `by-global/SurfaceRenderCallbackTable.md`, `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` | Singleton receiver and Surface callback-provider support already updated by B014. |
| `auto-generated/NexusTK/render/PaletteLib.cpp` | Read-only generated output proves the target's current formal C++ reaches a source root. |
| `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-research-tracker.md` | Read-only generated state confirms UID `0001E9` is coded/emitting and that B014's report was executed. |
| `executed-b-agent-research/B014/0001E9-PaletteLibPaletteFilterHelpers-source-quality.md` | Later accepted/executed report that superseded the old B012 score/C++ recommendation. |
| `executed-b-agent-research/B001/0002R4-PaletteCollectionColorTransformRaw.md` | Transform-family support lead and no-standalone-transform-helper-file decision. |

Old-report search terms used with `rg` across `executed-b-agent-research/` and `tools/leaser/Agents/`: `0001E9`, `0x00543f60`, `PaletteLibPaletteFilterHelpers`, `PaletteFilter`, `dword_69B408`, `SetPaletteFilter`, `GetPaletteFilterWeight`, and `UpdatePaletteFilterTables`. Relevant matches were B014's executed UID0001E9 report, A002 notes from the 2026-06-14 score/owner refresh, B001's executed UID0002R4 transform-family report, and consumer reports using palette-filter terminology. Non-executed historical notes were treated as leads only.

Implementation callback validators were run after the accepted support edits: command IDs `000000000322` through `000000000325`, all exit code `0` with `ok: 1`. B012 leases were acquired only for the four edited support docs and released immediately after the validator batch.

## Current IDA MCP Spot-Check

Mandatory MCP checks succeeded against the supervisor-provided active IDB session `86fb854e`.

| Check | Result |
| --- | --- |
| MCP endpoint | `http://127.0.0.1:13337/mcp` |
| Tool flow | `initialize` -> `tools/list` -> bounded `tools/call` reads |
| Active database | session `86fb854e`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `10220`, active/adopted worker |
| Health | `ok`; module `NexusTK.exe`; auto-analysis ready; Hex-Rays ready; strings cache ready with `2067` strings |
| Schemas checked | `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `xref_query`, `callees`, `decompile`, `disasm`, `get_bytes`, `find_bytes` |

Narrow spot-check facts:

| Query | Current MCP result |
| --- | --- |
| `lookup_funcs` | `0x00543f60` is `sub_543F60` size `0x10`; `0x00543f70` and `0x00543f77` are not functions; `0x00543f80` is `sub_543F80` size `0x170`; `0x005440e7` is inside `sub_543F80`; `0x005440f0` is not a function. |
| `xrefs_to 0x00543f60` | Four code refs: `0x005096e7`, `0x0050a277`, `0x0050d94f`, `0x0050d99f`. |
| `xrefs_to 0x00543f80` | Two code refs: `0x00509595`, `0x0050a918`. |
| Negative xrefs | `xrefs_to` and `xref_query` both return zero refs to `0x00543f70` and zero refs to `0x005440f0`. |
| Callees | `0x00543f60` has no callees; `0x00543f80` calls only external slot `0x0069b408` / `unk_69B408`. |
| Callback refs | `0x0069b408` has eight refs: palette-family consumers at `0x00542dc8`, `0x005436c8`, `0x00543fdd`, `0x00544020`, `0x005440a8`, plus Surface setup/target refs at `0x00558780`, `0x00558bd0`, `0x00558eec`. |
| Boundary bytes | `0x00543f55-0x00543f60` are eleven `0xcc`; setter bytes are `55 8b ec 8a 45 08 88 81 58 07 00 00 5d c2 04 00`; raw getter bytes are `d9 81 5c 07 00 00 c3`; `0x00543f77-0x00543f80` are nine `0xcc`; updater epilogue reaches `5f 5e 5b 8b e5 5d c2 04 00`; `0x005440f0` starts separate function-shaped bytes `55 8b ec 51 53 56 ...`. |
| Raw getter byte search | `find_bytes D9 81 5C 07 00 00 C3` matched only `0x00543f70`. |
| Decompile spot-check | `sub_543F60` stores the byte argument to `this[1880]` and returns it; `sub_543F80` compares/stores `this[471]` (`+0x75c`), computes `(weight * 32.0f) + 0.5f`, transforms 255 entries through `unk_69B408`, walks seven super palettes and 25 source/runtime slot pairs, and skips slot `11`. |

Two earlier script attempts reported a client-side parse error for the optional `notifications/initialized` HTTP acknowledgement. The listener stayed present and the required MCP evidence calls above succeeded; this is not treated as MCP-unavailable fallback evidence.

## Positive Evidence

- Current MCP independently reconfirms the exact target range: modeled setter `0x00543f60-0x00543f70`, retained raw getter bytes `0x00543f70-0x00543f77`, padding `0x00543f77-0x00543f80`, modeled updater `0x00543f80-0x005440f0`, and separate successor bytes at `0x005440f0`.
- Live callers still match the existing target page: four setter refs from `sub_5094B0` and `sub_50D8E0`, and two updater refs from `sub_5094B0` and `sub_50A8B0`.
- The updater still consumes only `0x0069b408`; current callback docs already identify that slot as Surface-owned provider state and UID `0001E9` as a PaletteLib consumer.
- Current decompilation confirms the field and loop facts already in target C++: `+0x758` is written by the setter; `+0x75c` is the float cache; strength is `(weight * 32.0f) + 0.5f`; loops transform 255 entries starting at entry 1; seven super palettes and 25 slot-list pairs are covered; slot `11` is intentionally skipped.
- Generated C++ currently contains UID `0001E9` in `auto-generated/NexusTK/render/PaletteLib.cpp`, proving the emitter route is not a dead end.

## Negative And Counter-Evidence

- No current MCP xrefs target the raw getter at `0x00543f70`; this remains a retained source-shaped accessor, not a live-caller claim.
- No current MCP xrefs target `0x005440f0`; this successor remains outside UID `0001E9` and should not be merged into the helper page.
- The old B012 `SetPaletteFilterEnabled` / `void` setter draft is weaker than current evidence because accessor reads show a bank selector and the current formal block preserves the observed return value.
- `dword_69B408` is not PaletteLib-owned storage. Surface callback-table docs own the provider/initialization route; PaletteLib only consumes the callback.
- Stale Wave3/simroot/recovered-source wording found in support docs was historicalized during the accepted callback. Those old generated-source strings are not evidence for this revised report.

## Heuristic / Inference Reanalysis And Validation

The accepted source shape is a `PaletteLib` method cluster, not a standalone transform-helper file and not a ScreenPane-owned helper. The validation routes are:

| Candidate | Evidence for | Evidence against | Disposition |
| --- | --- | --- | --- |
| [UID:0000A1] `PaletteLib` class | `g_pPaletteLib` receiver setup at all live callers; fields initialized by `PaletteLib::PaletteLib`; target support docs and generated output route through `PaletteLib`; target clears code-entry gate. | Exact original member spellings are inferred. | Accepted direct owner/emitter; already present in target. |
| [UID:0000MB] `PaletteLib` file | Narrow generated source root `NexusTK/render/PaletteLib.cpp`; generated output currently contains UID `0001E9`. | File is a source route, not the narrow semantic owner for class methods. | Accepted source route through class owner; already present. |
| [UID:0000MA] `Palette` umbrella | Broader render palette family owns related `DLPalette`, slot constants, raw transform-family context, and no-standalone-helper-file decision. | Too broad as direct owner for a `PaletteLib` method. | Keep as umbrella support only. |
| `ScreenPanePaletteState_543D30` | Adjacent helper range before this target shares palette-bank context. | Current and historical MCP caller evidence passes `g_pPaletteLib` as `this`; target fields are `PaletteLib` state. | Rejected as direct owner; adjacent facet support only. |
| Standalone `PaletteTransformHelpers.cpp` | Similar transform kernel appears in raw transform-family helpers. | No caller cluster, source metadata, object boundary, or independent state proves a separate compilation unit; B001/B014 support docs already reject it. | Rejected; keep under Palette/PaletteLib source family. |
| Split raw getter into a child page | Getter bytes are function-shaped. | No xrefs or pointer route; same `+0x75c` field family; splitting creates a tiny no-route child with no ownership benefit. | Rejected; retain inside UID `0001E9`. |
| Merge successor `0x005440f0` | Function-shaped bytes start immediately after updater. | Updater ends with `retn 4`; successor start has no xrefs and is outside current target; no evidence it belongs to filter-table update. | Rejected; leave outside UID `0001E9`. |

## Score-Blocker Audit

Every blocker or open question named by the original B012 report now has one of the allowed outcomes:

| Blocker / open question | Current outcome |
| --- | --- |
| `+0x758` field role | Resolved. Current target/support docs use `m_useFilteredPalettes` and document source-vs-filtered/runtime bank selection. |
| `+0x75c` field role | Resolved. Current target/support docs use `m_paletteFilterWeight` and document constructor/getter/updater cache semantics. |
| Caller context and setter return | Resolved. Current target docs record callers; formal C++ preserves `bool SetPaletteFilterActive(bool active)` returning the input byte. |
| Raw getter liveness | Resolved as retained no-xref source-shaped getter inside UID `0001E9`; no split requested. |
| `0x005440f0` boundary | Resolved as separate successor outside UID `0001E9`; no merge requested. |
| `dword_69B408` ownership | Resolved as Surface callback-table provider with PaletteLib consumer alias `g_pfnTransformPaletteColor` / `SurfacePaletteTransformProc`. |
| Exact original source split | Evidence-backed unresolved support limit only; it caps final-audit confidence but does not block target owner/emitter/C++ because current emitter route is valid and generated. |
| Old generated/Wave/simroot wording | Resolved by the accepted implementation callback; this revised report does not rely on stale Wave2/Wave3/recovered-source material. |
| `0002R4` optional related cleanup | Resolved by the accepted implementation callback; the item summary now records source-family assignment to [UID:0000MA] with the live-reachability caveat. |

## Target Function Inventory

| Address | IDA status | Evidence |
| --- | --- | --- |
| `0x00543f60` | `sub_543F60`, size `0x10` | Setter body: `mov al, [arg_0]`; store byte at `[ecx+758h]`; return. |
| `0x00543f70` | no IDA function object | Seven-byte raw getter body: `fld dword ptr [ecx+75Ch]`; `ret`; followed by `0xcc` padding to `0x00543f80`. |
| `0x00543f80` | `sub_543F80`, size `0x170` | Filter-table rebuild method; compares/stores `[ecx+75Ch]`, computes strength, rebuilds base/super/slot runtime palettes through callback slot `dword_69B408`. |
| `0x005440f0` | no IDA function object | Successor raw body starts with function prologue and list-bank cleanup loop; it is not padding and is not part of this target. |

Boundary bytes confirm:

- `0x00543f55-0x00543f60`: eleven `0xcc` bytes before the setter.
- `0x00543f70-0x00543f77`: raw getter.
- `0x00543f77-0x00543f80`: nine `0xcc` bytes before the updater.
- `0x005440e7-0x005440ef`: updater epilogue ending in `ret 4`.
- `0x005440f0`: separate raw successor body begins immediately with executable instructions.

## Caller Map

IDA xrefs confirm all live callers and show that the setter return value is ignored.

| Target | Callers |
| --- | --- |
| `0x00543f60` setter | `0x005096e7` and `0x0050a277` in `sub_5094B0`; `0x0050d94f` and `0x0050d99f` in `sub_50D8E0` |
| `0x00543f70` raw getter | no xrefs |
| `0x00543f80` updater | `0x00509595` in `sub_5094B0`; `0x0050a918` in `sub_50A8B0` |

Caller behavior:

- `sub_5094B0` loads `g_pPaletteLib`, calls the updater with the current map-pane fade/brightness float, then later calls the setter with `1` or `0` depending on the render branch.
- `sub_50A8B0` is the day/night fade target path. It updates map-pane fade fields, then calls `PaletteLib::UpdatePaletteFilterTables` when the same config gate allows palette filtering.
- `sub_50D8E0` wraps `MapTileImageLib::DrawTile` by setting the PaletteLib filter flag to `1` before tile drawing and back to `0` afterward.

This is strong evidence that `this+0x758` is not a generic config byte. It is the active "use filtered/runtime palettes" selector that render code toggles around filtered tile drawing.

## Field Resolution

Recommended source-facing PaletteLib field names:

| Offset | Recommended name | Rationale |
| --- | --- | --- |
| `+0x758` | `m_useFilteredPalettes` | Constructor initializes it to false; setter writes it; `GetCurrentPalette` and `GetSlotPalette` choose runtime/filtered palette banks when it is true; map-tile drawing toggles it around filtered draw calls. |
| `+0x75c` | `m_paletteFilterWeight` | Constructor initializes it to `1.0f`; raw getter returns it; updater compares and stores it as the current cached transform weight. |

Current target/support docs use these palette-bank names. Older B012 aliases such as `m_sourceBasePalette`, `m_runtimeBasePalette`, and `m_sourceSuperPalettes` are historical leads only and should not replace the already-present target C++ names.

| Storage | Recommended name |
| --- | --- |
| base/source palette | `m_basePalette` |
| base/runtime filtered palette | `m_filteredBasePalette` |
| source super/reserved palettes | `m_superPalettes[7]` |
| runtime filtered super/reserved palettes | `m_filteredSuperPalettes[7]` |
| source slot lists at `+0x690` | `m_sourcePaletteSets[25]` |
| runtime slot lists at `+0x6f4` | `m_runtimePaletteSets[25]` |

`DLPalette` support docs already use `m_mappedColors[256]` at object offset `+0x2c`. The updater starts at color-table offset `+0x2e` because it deliberately rebuilds palette indexes `1..255` and leaves index `0` unchanged.

## Callback Context

`dword_69B408` is the palette-color transform callback slot selected by the Surface callback setup code:

- Palette-family consumers: `0x00542dc8`, `0x005436c8`, `0x00543fdd`, `0x00544020`, `0x005440a8`.
- Surface setup refs: `0x00558780`, `0x00558bd0`, `0x00558eec`.
- RGB555 callback body: [UID:0002YI][0x004bede0-0x004bee35.SoftwareRenderCompatRgb555PaletteTransformCallback](../../../../../by-memory/0x004bede0-0x004bee35.SoftwareRenderCompatRgb555PaletteTransformCallback.md).
- RGB565 callback body: [UID:0002YN][0x004c4730-0x004c478a.SoftwareRenderRgb565PaletteTransformCallback](../../../../../by-memory/0x004c4730-0x004c478a.SoftwareRenderRgb565PaletteTransformCallback.md).

Current source-facing dependency name for the target C++ is `g_pfnTransformPaletteColor`, with `SurfacePaletteTransformProc` as the current typedef-style support-doc alias. The final declaration belongs with Surface callback-table support docs; the PaletteLib target should use the named dependency rather than the raw `dword_69B408` label.

## Raw Getter Liveness

The raw getter at `0x00543f70` has no direct xrefs, but it is function-shaped, padding-bounded, and reads the now-resolved `m_paletteFilterWeight` field. It should remain documented inside this target. Its exact formal C++ is included only in the formal `RECONSTRUCTION_CPP CODE` block above.

No caller/liveness claim should be added in this assignment unless a separate pointer-data or source-reference route proves one.

## Successor Boundary

`0x005440f0` is not padding and should not be merged into `0001E9`. IDA disassembly at `0x005440f0` shows a fresh function-shaped raw body:

- prologue: `push ebp; mov ebp, esp; push ecx; push ebx; push esi; push edi`;
- initializes a `0x19` / 25-slot loop;
- starts from `ecx+0x6f4`, matching the runtime slot-list bank.

This supports the current exclusive end `0x005440f0` for the filter helper target and a separate follow-up/successor disposition for the cleanup body.

## Source Placement

Recommended direct owner/emitter remains [UID:0000A1][PaletteLib](../../../../../by-class/PaletteLib.md).

Physical source placement should not block this target:

- [UID:0000MB][PaletteLib](../../../../../by-file/PaletteLib.md) is a valid focused source root for PaletteLib class members.
- [UID:0000MA][Palette](../../../../../by-file/Palette.md) remains the broader render palette umbrella and still accurately documents that original source may have grouped `DLPalette`, `PaletteLib`, `g_pPaletteLib`, and slot constants in a broader `Palette.cpp`.
- No new source file such as `PaletteTransformHelpers.cpp` should be introduced for this target.

Recommended implementation wording: emit the formal C++ through the PaletteLib class route and retain a source-split caveat in file-level support docs rather than leaving this target blank.

## Formal RECONSTRUCTION_CPP CODE Disposition

The target still qualifies for formal C++ under the current code-entry gate: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:0000A1`, the emitter route reaches `auto-generated/NexusTK/render/PaletteLib.cpp`, and `(91 + 91) / 2 = 91`.

The old B012 draft below is rejected as stale:

- `SetPaletteFilterEnabled` is superseded by `SetPaletteFilterActive`; the field selects active source-vs-filtered palette banks, not just a generic enabled state.
- `void` setter return is superseded by the already-present formal `bool` return. The binary returns the input byte in `AL`; callers ignore it, but the current code preserves the exact return value.
- `g_pfnPaletteColorTransform`, `m_sourceBasePalette`, and `m_runtimeBasePalette` are superseded by the current target's established `g_pfnTransformPaletteColor`, `m_basePalette`, and `m_filteredBasePalette` names.

Exact formal insertion text if a future callback has to recreate the target block is the current already-present block:

```cpp
bool PaletteLib::SetPaletteFilterActive(bool active)
{
    m_useFilteredPalettes = active;
    return active;
}

float PaletteLib::GetPaletteFilterWeight() const
{
    return m_paletteFilterWeight;
}

void PaletteLib::UpdatePaletteFilterTables(float weight)
{
    if (weight == m_paletteFilterWeight) {
        return;
    }

    m_paletteFilterWeight = weight;

    const unsigned char strength = static_cast<unsigned char>((weight * 32.0f) + 0.5f);

    for (int color = 1; color < 256; ++color) {
        m_filteredBasePalette.m_mappedColors[color] =
            g_pfnTransformPaletteColor(m_basePalette.m_mappedColors[color], strength);
    }

    for (int paletteIndex = 0; paletteIndex < 7; ++paletteIndex) {
        DLPalette& sourcePalette = m_superPalettes[paletteIndex];
        DLPalette& filteredPalette = m_filteredSuperPalettes[paletteIndex];

        for (int color = 1; color < 256; ++color) {
            filteredPalette.m_mappedColors[color] =
                g_pfnTransformPaletteColor(sourcePalette.m_mappedColors[color], strength);
        }
    }

    for (int slot = 0; slot < 25; ++slot) {
        if (slot == 11) {
            continue;
        }

        List* sourceList = m_sourcePaletteSets[slot];
        List* filteredList = m_runtimePaletteSets[slot];
        const int count = sourceList->GetCount();

        for (int index = 0; index < count; ++index) {
            DLPalette* sourcePalette = *reinterpret_cast<DLPalette**>(sourceList->GetAt(index));
            DLPalette* filteredPalette = *reinterpret_cast<DLPalette**>(filteredList->GetAt(index));

            for (int color = 1; color < 256; ++color) {
                filteredPalette->m_mappedColors[color] =
                    g_pfnTransformPaletteColor(sourcePalette->m_mappedColors[color], strength);
            }
        }
    }
}
```

No third-party import directive applies. This is NexusTK-owned palette-manager code, not staged static embedded third-party source.

## Claim And Incorporation Ledger

Final callback state was updated on 2026-06-29. All accepted rows are `applied`, `already-present`, or `excluded-with-reason`; no row is blocked.

| ID | Claim / fact | Destination / callback instruction | Action | Verification state |
| --- | --- | --- | --- | --- |
| L1 | UID `0001E9` should remain `91/91`, `CANONICAL_OWNER:0000A1`, `EMITTER_UIDS:0000A1`, `RECONSTRUCTABLE:TRUE`. | `by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md`; verify already present, no score edit requested. | already-present | Verified by `rg` on the target metadata: `91/91`, owner/emitter `0000A1`, and `RECONSTRUCTABLE:TRUE`; target file not edited. |
| L2 | Formal C++ should be `SetPaletteFilterActive`, `GetPaletteFilterWeight`, `UpdatePaletteFilterTables` exactly as in this revised report. | Target page and `auto-generated/NexusTK/render/PaletteLib.cpp`; verify already present, do not replace. | already-present | Verified by `rg` on target and read-only generated `auto-generated/NexusTK/render/PaletteLib.cpp`; no primary target C++ replacement was made. |
| L3 | Old B012 `SetPaletteFilterEnabled` / `void` setter draft is superseded. | Do not incorporate into by-* docs; if old wording is encountered, historicalize as old B012 draft only. | excluded-with-reason | Excluded because the accepted target already uses `SetPaletteFilterActive(bool)` and preserves the observed return value; no old draft wording was incorporated. |
| L4 | `+0x758` is `m_useFilteredPalettes`, the active source-vs-filtered/runtime bank selector. | Target, `by-class/PaletteLib.md`, `by-file/PaletteLib.md`, `by-file/Palette.md`; verify already present. | already-present | Verified in target/support docs before callback; accepted edits did not change this fact. |
| L5 | `+0x75c` is `m_paletteFilterWeight`, the cached float weight returned by the raw getter and updated by the table rebuild helper. | Target and PaletteLib support docs; verify already present. | already-present | Verified in target/support docs before callback; accepted edits did not change this fact. |
| L6 | Raw getter `0x00543f70-0x00543f77` has no xrefs but belongs inside UID `0001E9` because it is a unique source-shaped accessor for the same `+0x75c` field. | Target page; verify already present, no split. | already-present | Verified in target function inventory/evidence; no split or target edit made. |
| L7 | Successor `0x005440f0` is separate executable-shaped bytes outside UID `0001E9`; current MCP still finds no refs to the start. | Target boundary notes; verify already present, no merge. | already-present | Verified in target boundary notes; no merge or target edit made. |
| L8 | Current MCP `86fb854e` reconfirms function sizes, xrefs, callback refs, bytes, raw-getter uniqueness, and negative xrefs. | Report-only evidence; optional target note only if supervisor explicitly wants a 2026-06-29 recheck entry. | excluded-with-reason | Excluded from by-* edits because the supervisor accepted support cleanup only and did not request a target recheck note. The MCP evidence remains preserved in this report. |
| L9 | `dword_69B408` / `0x0069b408` is Surface callback-table provider state; PaletteLib consumes it as `g_pfnTransformPaletteColor` / `SurfacePaletteTransformProc`. | `by-global/SurfaceRenderCallbackTable.md`, `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`, target page; verify already present. | already-present | Verified by `rg` on Surface callback-table pages and target; no callback support edit was requested. |
| L10 | Generated C++ route is current and read-only: UID `0001E9` emits into `auto-generated/NexusTK/render/PaletteLib.cpp`. | Generated file inspection only; no manual generated edit. | already-present | Verified read-only by `rg` on `auto-generated/NexusTK/render/PaletteLib.cpp`; generated C++ was not manually edited. |
| L11 | `by-class/PaletteLib.md` still contains stale simroot wording: `Current recovered file: source-3/simroot_v2/class_PaletteLib.cpp`. | Replace with a historical generated-source lead note that current evidence comes from by-* docs, MCP, and validator-generated output, not simroot. | applied | Replaced with historical `simroot_v2` lead wording; validator `000000000322` at `2026-06-29T02:11:48-04:00` exited `0`, `ok: 1`. |
| L12 | `by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md` still contains stale simroot wording: `Current recovered file: source-3/simroot_v2/class_PaletteLib.cpp`. | Replace with a historical generated-source lead note; preserve current PaletteLib source route and child inventory. | applied | Replaced with historical `simroot_v2` lead wording; validator `000000000323` at `2026-06-29T02:11:55-04:00` exited `0`, `ok: 1`. |
| L13 | `by-file/Palette.md` contains stale `Current recovered sources:` simroot wording and `Wave3 emits` / `Wave3 imports` lead text. | Rewrite those as historical generated-source leads only; do not treat Wave3/simroot as current evidence. | applied | Historicalized `Current recovered sources`, replaced `Wave3 emits` with generator-neutral audit wording, and rewrote all three `Wave3 imports` bullets as historical leads; validator `000000000324` at `2026-06-29T02:12:01-04:00` exited `0`, `ok: 1`. |
| L14 | `by-file/Palette.md` row for `g_pPaletteLib` still says `Wave3 type/owner are known`. | Replace with current by-global/by-memory evidence wording for `g_pPaletteLib` storage/type/owner. | applied | Replaced with current `g_pPaletteLib` storage, publish/clear, and UID0001E9 receiver-call wording; validator `000000000324` exited `0`, `ok: 1`. |
| L15 | `by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md` item summary still says it "remains unassigned" because child score/liveness are missing, but metadata/body now assign it to [UID:0000MA] as source-family ownership with liveness caveat. | Update item summary to current assignment/liveness-caveat state; do not change owner/emitter/C++ here. | applied | Updated only the item summary to current B001-046 source-family assignment/liveness caveat wording; validator `000000000325` at `2026-06-29T02:12:11-04:00` exited `0`, `ok: 1`. |
| L16 | `by-file/PaletteLib.md`, `by-global/g_pPaletteLib.md`, `by-global/SurfaceRenderCallbackTable.md`, and the callback-table memory page already preserve the valid UID0001E9 support facts at same-or-greater detail. | Verify only; no support edit requested unless supervisor wants a fresh-MCP footnote. | already-present | Verified by `rg` on the named support docs; no edit requested or made. |
| L17 | `by-item/PaletteSlotTable.md` already supplies slot count `25` and slot `11` / `EFFECT.PAL` context; no edit is needed for UID0001E9. | Verify only. | already-present | Verified by support-doc audit during report revision; no edit requested or made. |
| L18 | Manual coverage reports, generated reports, generated C++, validator/tool state, executed reports, lock files, and IDA DB must not be edited. | Callback process constraint. | excluded-with-reason | No manual forbidden edits were made; no `execute_report` was run; IDA DB was not edited. Required validators with `--apply` updated `project-level/-auto-completion-stats.md` as a validator side effect, and all B012 leases were released. |

## Support Stale-Source Actions

This revised report does not rely on stale Wave2/Wave3/simroot/recovered-source material. The supervisor accepted the support cleanup callback, and the following edits were applied:

| File | Callback result |
| --- | --- |
| `by-class/PaletteLib.md` | Historicalized the stale `Current recovered file: source-3/simroot_v2/class_PaletteLib.cpp` line as an older generated-source lead and named by-* docs, IDA MCP, and validator-generated output as current evidence. |
| `by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md` | Historicalized the stale `Current recovered file: source-3/simroot_v2/class_PaletteLib.cpp` line with the same current-evidence wording. |
| `by-file/Palette.md` | Historicalized the stale `Current recovered sources: source-3/simroot_v2/...` lead, replaced `Wave3 emits` with generator-neutral audit wording, and rewrote all `Wave3 imports ...` evidence notes as historical generated-source leads only. |
| `by-file/Palette.md` | Replaced `Wave3 type/owner are known` in the `g_pPaletteLib` row with current by-global/by-memory evidence for storage, constructor publish, destructor/unwind clear, and UID0001E9 receiver calls. |
| `by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md` | Updated the item summary to current B001-046 source-family assignment/liveness-caveat wording without changing owner, emitter route, or C++. |

No manual coverage/tracker text was edited. Validator-owned generated/projected state was touched only through the required scoped validator commands.

## Validation Status

Validators were run after the accepted support edits while the B012 leases were held, then the leases were released.

From `E:\NTK\GhidraBridge\source-3\project-documentation`:

| Command ID | Timestamp | File | Exit / result |
| --- | --- | --- | --- |
| `000000000322` | `2026-06-29T02:11:48-04:00` | `by-class/PaletteLib.md` | exit `0`, `ok: 1`; `missing_ref_uid` warnings for existing `0003MT` / `0003MV` references; `projected_stats_update: 1`; `generated_refresh: deferred`. |
| `000000000323` | `2026-06-29T02:11:55-04:00` | `by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md` | exit `0`, `ok: 1`; `missing_ref_uid` warnings for existing `0003MT` / `0003MU` / `0003MV` references; `projected_stats_update: 1`; `generated_refresh: deferred`. |
| `000000000324` | `2026-06-29T02:12:01-04:00` | `by-file/Palette.md` | exit `0`, `ok: 1`; `missing_ref_uid` warnings for existing `0003MT` / `0003MU` / `0003MV` / `0003LS` references; `projected_stats_update: 1`; `generated_refresh: deferred`. |
| `000000000325` | `2026-06-29T02:12:11-04:00` | `by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md` | exit `0`, `ok: 1`; validator normalized header spacing/registry metadata already reflected by the page; `projected_stats_update: 1`; `generated_refresh: deferred`. |

`project-level/-auto-completion-stats.md` was updated by validator `--apply` as projected stats state. No target validator was run because the primary UID0001E9 target was not edited. `execute_report` was not run.

## Implementation Tracking Checklist

- [x] During callback only, lease the exact approved by-* support docs immediately before editing; do not lease for report-only work. Proof: leased four support files with `leaser.py B012 lease ...`; no target or generated files were leased.
- [x] Verify `by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md` already has `91/91`, owner/emitter [UID:0000A1], `RECONSTRUCTABLE:TRUE`, and the formal C++ block shown in this report; do not replace target C++ with the old B012 draft. Proof: `rg` verified metadata and C++ names in the target and read-only generated `auto-generated/NexusTK/render/PaletteLib.cpp`; target was not edited.
- [x] Update the Claim And Incorporation Ledger verification state for every accepted row as `applied`, `already-present`, `excluded-with-reason`, or `blocked`. Proof: rows L1-L18 above are all resolved and none are blocked.
- [x] Historicalize stale simroot wording in `by-class/PaletteLib.md` and validate that file. Proof: stale line replaced; validator `000000000322`, exit `0`, `ok: 1`.
- [x] Historicalize stale simroot wording in `by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md` and validate that file. Proof: stale line replaced; validator `000000000323`, exit `0`, `ok: 1`.
- [x] Historicalize stale simroot/Wave3 wording and the `g_pPaletteLib` Wave3 row in `by-file/Palette.md` and validate that file. Proof: stale source, `Wave3 emits`, `Wave3 imports`, and `Wave3 type/owner are known` wording replaced; validator `000000000324`, exit `0`, `ok: 1`.
- [x] Update the stale item summary in `by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md` without changing owner/emitter/C++ and validate that file. Proof: item summary now records B001-046 source-family assignment and liveness caveat; validator `000000000325`, exit `0`, `ok: 1`.
- [x] Do not edit generated reports, generated C++, manual `-coverage-report.md` files, validator/tool state, lock files, executed reports, or IDA DB. Proof: no manual forbidden edits; required validators updated `project-level/-auto-completion-stats.md` only through `--apply`; no IDA DB/MCP write action and no `execute_report`.
- [x] Release any callback leases immediately after the edit/validator batch. Proof: `leaser.py B012 unlease ...` succeeded for all four support docs; subsequent `current_leases.md` had no B012 rows.
- [x] Report changed files, validator command IDs/timestamps/exit status/ok counts, generated-refresh side effects if any, and any ledger rows that could not be resolved. Proof: validation table above records command IDs/timestamps/results; no ledger row is blocked.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/0001E9-PaletteLibPaletteFilterHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/0001E9-PaletteLibPaletteFilterHelpers-source-quality.md","timestamp":"2026-06-29T02:19:57","uid":"0001E9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
