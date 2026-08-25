*** UID:0001RC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# HourPane Time Resources

## Status

- Confidence: very strong for resource names, owner usage, branch behavior, source/resource boundary, [UID:0002ZE][g_hourFrameTable](by-global/g_hourFrameTable.md) ownership, current-package `TIME.EPF` / `TIME.PAL` provenance, and `TIME.EPD` blocker classification; medium for legacy `TIME.EPD` payload provenance and final frame atlas semantics.
- Related file: [UID:0000JX][HourPane](by-file/HourPane.md)
- Related class: [UID:000068][HourPane](by-class/HourPane.md)
- Evidence basis: IDA MCP UTF-16 string and xref checks; generated sources are only lead material.

## Confirmed Resources

| Resource | Used by | Rebuild handling | Notes |
| --- | --- | --- | --- |
| `TIME.EPF` | `HourPane::OnPaint` at `0x004cf010` | Resource-derived image payload. Preserve the filename constant and EPF-mode branch in `HourPane.cpp`; the bytes belong to DAT/source-asset packaging. | Used when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` is `1`, the newer/current EPF asset-mode branch. |
| `TIME.PAL` | `HourPane::OnPaint` at `0x004cf010` | Resource-derived palette payload paired with `TIME.EPF`. Source owns the loader argument, not the palette data. | Palette passed to the EPF draw helper for `TIME.EPF`. |
| `TIME.EPD` | `HourPane::OnPaint` at `0x004cf010` | Resource-derived legacy image payload. Preserve the old-mode filename constant and frame-index call path in source. | Used when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` is not `1`, the old/non-EPF branch. |

## Package Provenance

2026-06-14 read-only package audit of `E:\2026\Resources\Read_Only\NexusTK\Data` parsed the documented DAT entry table format and found the current-mode time resources in `bint2.dat`:

| Resource | Current package evidence |
| --- | --- |
| `TIME.EPF` | Present as `Time.epf`, entry index `100`, offset `15,291,224`, size `10,464`; EPF table header advertises `12` frames, matching the documented two-hour frame selection. |
| `TIME.PAL` | Present as `Time.pal`, entry index `101`, offset `15,301,688`, size `1,056`; payload begins with `DLPalette`. |
| `TIME.EPD` | Not found as a DAT entry or loose file in the audited current package. |

This proves the current EPF/palette payloads and supports the twelve-frame interpretation. It does not prove the legacy EPD payload; keep the old branch documented from IDA operands and source behavior until another distribution or loose resource source supplies `TIME.EPD`.

2026-06-16 A002 rechecked package availability with the documented 17-byte DAT entry records. Exact DAT entry matches remain `bint2.dat` `Time.epf` index `100` offset `15,291,224` size `10,464` and `bint2.dat` `Time.pal` index `101` offset `15,301,688` size `1,056`; no exact `TIME.EPD` entry exists in the current archive set. A loose-file search under `E:\2026\Resources` found no standalone `TIME.*` files. `TIME.EPD` appears in `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe` only as a UTF-16 executable literal at raw offset `2,203,184`.

## Blocker Classification

2026-06-14 A002 reran the package audit with corrected start-offset DAT parsing, case-insensitive exact-name checks, loose-file search across `E:\2026\Resources`, and a narrow raw-name scan over the read-only client files. `TIME.EPD` remains absent from every DAT entry name and from loose resources. The only exact `TIME.EPD` occurrence outside IDA is the UTF-16 executable literal at raw offset `2,203,184` in `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe`.

Treat the legacy `TIME.EPD` blocker as a code-referenced but payload-missing old-rendering operand in this audited distribution. The current package supplies `Time.epf` / `Time.pal`, so the likely rebuild route is to ship current EPF/PAL assets and keep the `TIME.EPD` literal/branch documented until an older package or loose client tree provides the exact EPD payload.

## Frame Semantics

`HourPane::OnPaint` selects a frame from [UID:0002ZE][g_hourFrameTable](by-global/g_hourFrameTable.md) with index `(currentHour / 2) % 12`. This implies twelve visual clock/time frames, with each frame covering a two-hour block. Current evidence proves the table is HourPane-owned source-declared data: [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md) records exactly two xrefs, both inside `HourPane::OnPaint`, and excludes the unrelated tail constants after the twelfth word.

When no hour is set (`currentHour == -1`), the pane does not draw a time resource:

- new/current mode sets color `0` and invalidates;
- old mode sets color `0x80` and invalidates.

## Source Ownership Notes

`HourPane.cpp` owns the time-update state, invalidation behavior, hover tooltip, rendering-mode branch, and the `(currentHour / 2) % 12` lookup through [UID:0002ZE][g_hourFrameTable](by-global/g_hourFrameTable.md). The EPF/EPD/PAL payloads are resource packaging inputs and should not be recreated as C++ data.

The current resource boundary is:

- source-owned: resource filename constants, [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` branch, no-hour draw suppression, frame lookup use, and pane invalidation;
- resource-owned: `TIME.EPF`, `TIME.PAL`, and `TIME.EPD` bytes plus any archive metadata needed to pair the palette with the EPF image;
- resolved source-side table boundary: `g_hourFrameTable` is a HourPane-owned source-declared frame ordering table, not a resource payload and not a shared resource-layout table in current xrefs.

## Runtime Branch Matrix

| Runtime state | Resource behavior | Source behavior |
| --- | --- | --- |
| Current/EPF mode with a valid hour | Loads `TIME.EPF`, draws through the current EPF helper, and passes `TIME.PAL`. | Indexes [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md) with `(currentHour / 2) % 12`. |
| Legacy/EPD mode with a valid hour | Loads `TIME.EPD` and draws through the old-mode render callback. | Uses the same current-hour field and frame-table index calculation. |
| Current/EPF mode with unset hour | No `TIME.*` resource is drawn. | Fills/invalidates with color `0`. |
| Legacy/EPD mode with unset hour | No `TIME.*` resource is drawn. | Fills/invalidates with color `0x80`. |

## Rebuild Packaging Boundary

- Package the three named `TIME.*` assets as HourPane HUD resources.
- Preserve the source-level branch on [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), the unset-hour suppression, and the frame-table lookup.
- Keep the actual EPF/EPD image bytes, palette contents, and DAT placement in resource packaging rather than source declarations.
- Keep [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md) / [UID:0002ZE][g_hourFrameTable](by-global/g_hourFrameTable.md) as the HourPane-owned source-declared frame ordering dependency. The table should be rebuilt from source, while `TIME.EPF`, `TIME.PAL`, and any future `TIME.EPD` payload remain resource-derived assets.

## Rebuild Notes

For source reconstruction, keep `TIME.EPF`/`TIME.PAL` and `TIME.EPD` as literal loader inputs in the `OnPaint` branch rather than promoting them to a generic clock asset registry before broader HUD resource review. The branch is behaviorally important because no-hour handling differs between current and old rendering modes.

Final asset extraction still needs another package/distribution audit for `TIME.EPD` and to verify whether the EPF and EPD frame ordering are identical.

## Open Questions

- Find a distribution or loose-resource source for `TIME.EPD`; the current package contains `TIME.EPF` / `TIME.PAL` in `bint2.dat` but not the legacy EPD operand.
- Do the EPF and EPD resources share identical twelve-frame ordering, or does the old branch need a separate frame interpretation?
- The source-facing table spelling is now fixed as `g_hourFrameTable`; original symbol provenance remains unavailable, so this is a documented reconstruction name rather than a PDB-derived label.

## IDA MCP Evidence

- 2026-06-14 A003 IDA xref refresh confirms each time-resource literal has one observed code xref, all inside `sub_4CF010` / `HourPane::OnPaint`.
- `TIME.EPF` is a UTF-16 string at `0x0061b408`; xref `0x004cf069` lands in `0x004cf010-0x004cf139`.
- `TIME.PAL` is a UTF-16 string at `0x0061b41c`; xref `0x004cf07f` lands in `0x004cf010-0x004cf139`.
- `TIME.EPD` is a UTF-16 string at `0x0061b430`; xref `0x004cf100` lands in `0x004cf010-0x004cf139`.
- 2026-06-16 A002 live IDA MCP session `b001_selflookpane_0001H7_20260616` reconfirmed `sub_4CF010` size `0x129`, one xref each for `TIME.EPF`, `TIME.PAL`, and `TIME.EPD`, and exactly two [UID:0002ZE][g_hourFrameTable](by-global/g_hourFrameTable.md) xrefs at `0x004cf060` and `0x004cf0f7`, both inside the same paint function. Decompilation still indexes the table as `(currentHour / 2) % 12` for both current and legacy branches.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `89` | The page separates current versus legacy draw behavior, unset-hour behavior, HourPane-owned `g_hourFrameTable` source-data dependency, rebuild packaging boundaries, remaining frame-ordering questions, fresh single-consumer xref evidence for the three resource literals, current-package `TIME.EPF` / `TIME.PAL` entries with size, offset, palette signature, and twelve-frame EPF header evidence, and exact all-DAT/loose/executable-literal classification for the missing `TIME.EPD` payload. Completion remains capped because the exact `TIME.EPD` payload, EPF-versus-EPD ordering, visual frame semantics, and final table declaration spelling are not fully audited. |
| Confidence `92` | Fresh IDA xrefs confirm all three `TIME.*` literals route to the HourPane paint function, DAT parsing confirms the current EPF/palette payloads, the global/memory support pages and current IDA xrefs resolve `g_hourFrameTable` as HourPane-owned source data, and the corrected archive/loose/executable scan strengthens the negative `TIME.EPD` provenance. Confidence stays below final because the legacy payload is still absent and final asset/frame semantics remain unresolved. |

## Cross-References

- [UID:0000JX][HourPane](by-file/HourPane.md)
- [UID:000068][HourPane](by-class/HourPane.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0002ZE][g_hourFrameTable](by-global/g_hourFrameTable.md)
- [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)
- [UID:0001QJ][client_old_redering_mode](by-meta/client_old_redering_mode.md)

## 2026-07-14 Exact Paint-Child Synchronization

- Exact source consumer: [UID:0004NN][0x004cf010-0x004cf139.HourPaneOnPaint](by-memory/0x004cf010-0x004cf139.HourPaneOnPaint.md), range `[0x004cf010,0x004cf139)`.
- Current/EPF valid-hour branch: loads `TIME.EPF`, selects `g_hourFrameTable[(m_currentHour / 2) % 12]`, obtains the frame through the EPF layout/resource route, rejects null pixel data, and renders with `TIME.PAL` through the current tile-frame helper.
- Legacy/EPD valid-hour branch: loads `TIME.EPD`, uses the same exact twelve-entry frame selection, rejects null pixel data, and dispatches through slot 2 `g_pfnBlitSprite` with null options.
- Current unset branch sets draw color `0`; legacy unset branch sets `0x80`; each uses the slot-7 source-facing `FillRect(&m_bounds)` path and draws no `TIME.*` payload.
- The paint source owns the literal arguments and branch behavior. EPF/EPD/PAL payload bytes remain resource-owned; the frame table remains file-local source data; shared lookup/render callbacks remain independently owned.
- Existing score `89/92`, package offsets/sizes, missing legacy payload evidence, frame-semantics questions, ownership, and all negative/provenance detail remain unchanged.

## Changes

- Before: page was scored `0/0` and cited generated source as evidence.
- Changed to: `COMPLETION:70`, `CONFIDENCE:85`, with IDA MCP string addresses and xrefs as the evidence basis.
- Evidence: IDA MCP lookup of `TIME.EPF`, `TIME.PAL`, and `TIME.EPD` references in `0x004cf010-0x004cf139`.
- 2026-06-06 rebuild-boundary pass:
  - What existed before: the page identified the resources and frame branch but did not separate source-owned behavior from DAT/source-asset payloads.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:87`, with rebuild handling, ownership boundaries, and DAT/frame-ordering open questions.
  - Summary/evidence: existing `HourPane` file/class docs tie the resources to `HourPane.cpp`; the remaining unknowns are asset provenance and whether the frame table is local or shared.
- 2026-06-07 A002 branch-matrix pass:
  - What existed before: the page documented the branch in prose but did not isolate valid-hour versus unset-hour resource behavior or the frame-table dependency in a matrix.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:87`, with runtime branch matrix, rebuild packaging boundary, frame-table dependency note, and current-session IDA availability caveat.
  - Summary/evidence: existing [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md) method evidence records the current/legacy draw split, unset-hour colors, and frame-table lookup.
- 2026-06-07 A008 alias cleanup:
  - Normalized the HourPane time-resource mode branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the historical IDA lookup alias.
- 2026-06-14 A003 score refresh: Raised completion/confidence from `78/87` to `85/89` after live IDA MCP xrefs confirmed `TIME.EPF`, `TIME.PAL`, and `TIME.EPD` each reference only `sub_4CF010` / `HourPane::OnPaint`; DAT provenance, raw frame ordering, and frame-table ownership remain the below-gate blockers.
- 2026-06-14 A002 resource-payload provenance:
  - What existed before: `COMPLETION:85` / `CONFIDENCE:89` with all DAT provenance still open.
  - Changed to: `COMPLETION:86` / `CONFIDENCE:90`.
  - Evidence: current DAT table parsing found `Time.epf` and `Time.pal` in `bint2.dat`, with the EPF header advertising `12` frames and the palette payload beginning with `DLPalette`; no `TIME.EPD` DAT entry or loose file was found, so the legacy branch remains the main payload blocker. `CANONICAL_OWNER:NONE` remains unchanged per batch owner-preservation guidance.
- 2026-06-14 A002 blocker provenance pass:
  - Before: `COMPLETION:86`, `CONFIDENCE:90`, with `TIME.EPD` only known as absent from the first current-package audit.
  - After: raised to `COMPLETION:87`, `CONFIDENCE:91`, after corrected DAT start-offset parsing, case-insensitive exact-name checks, loose-resource search, and raw client scan confirmed `TIME.EPD` is present only as a UTF-16 executable literal at raw offset `2,203,184` in the packaged executables, not as a current DAT or loose payload.
- 2026-06-16 A002 item/resource completion refresh:
  - Before: `COMPLETION:87`, `CONFIDENCE:91`.
  - After: raised to `COMPLETION:89`, `CONFIDENCE:92`; `CANONICAL_OWNER:NONE` remains correct for the resource-boundary page.
  - Evidence: current live IDA MCP reconfirmed the HourPane paint function, single resource-string xrefs, and two `g_hourFrameTable` xrefs; support pages [UID:0002ZE][g_hourFrameTable](by-global/g_hourFrameTable.md) and [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md) resolve the previous table-ownership blocker as HourPane-owned source-declared data. Current all-DAT/loose/executable scans reconfirmed `TIME.EPF`/`TIME.PAL` payloads and kept `TIME.EPD` as an executable-literal-only missing legacy payload in this distribution.
- 2026-07-14 B005 HourPane support synchronization: linked exact paint child UID0004NN and added the complete current/legacy valid/unset branch matrix, frame selection, null-pixel checks, and callback ownership boundaries with scores and resource provenance preserved.
