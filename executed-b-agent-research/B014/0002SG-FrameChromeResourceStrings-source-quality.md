** TARGET-REPORT-UID:0002SG **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-SCOPE:report-only source-quality research; no by-* edits performed **

# 0002SG FrameChromeResourceStrings Source-Quality Report

## Executive Recommendation

Reclassify [UID:0002SG][by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md] from a `FrameChrome`-owned reconstructable data page into a non-emitting mixed string-pool index, then split the exact source-use children under it. The byte range and corrected end boundary are good, but the current owner/emitter is too broad: only the first three literals are FrameChrome-local, while the palette tail is shared by FrameChrome, MapName/MiniMap, Group, BackPane, and UserStatus paint paths.

Recommended target metadata after implementation:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `86` | `90` |
| `CONFIDENCE` | `88` | `93` |
| `CANONICAL_OWNER` | `0000JL` | `NONE` |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` |
| `EMITTER_UIDS` | `0000JL` | blank |
| `Nested` | `8` | `4` after the four exact child pages below are present |
| C++ block | blank | keep blank; no standalone C++ or comment-only emitter |

Do not rename the live target file in this callback. The generated tracker still points at the older `0x00610f60-0x00610fd4.AboveFrameResourceStrings` path, but the live by-memory page already has the corrected `0x00610f60-0x00610fe8.FrameChromeResourceStrings` path. Treat that as generated-state staleness to be refreshed by validators, not as a manual generated-file edit.

## Report-Only State

- I edited only this report file: `tools/leaser/Agents/Agent-B014/research/0002SG-FrameChromeResourceStrings-source-quality.md`.
- I did not edit target/support by-* docs, generated files, coverage reports, validator/tool state, or the IDA database.
- No leases were requested because this is report-only mode.
- No validators were run because no by-* file was changed.

## MCP And Local Evidence

MCP is live and responding. The local listener at `http://127.0.0.1:13337/mcp` responds with HTTP `405 Method Not Allowed` for a GET probe, which confirms the listener is present, and the relevant `idalib-mcp` / `python` processes are responding. The active IDA session used for this research is session `80de0a67`, database `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, module `NexusTK.exe`, image base `0x400000`, with auto-analysis and Hex-Rays ready.

Primary MCP evidence gathered for this target:

| Evidence id | MCP/local query | Result |
| --- | --- | --- |
| B014-0002SG-MCP-001 | `server_health` / `idb_list` | Session `80de0a67` active; analysis not running; Hex-Rays ready; strings cache ready. |
| B014-0002SG-MCP-002 | `get_bytes(0x00610f50, 0xc0)` | Vtable tail ends before `0x00610f60`; six UTF-16LE strings run through `0x00610fe8`; AES bytes begin at `0x00610fe8`. |
| B014-0002SG-MCP-003 | `xrefs_to` for `0x00610f60`, `0x00610f78`, `0x00610f8c`, `0x00610fa4`, `0x00610fbc`, `0x00610fd0`, `0x00610fd4`, `0x00610fe8` | Literal starts have the xrefs listed below; old split `0x00610fd4` has no direct xrefs because it is inside `NPAL5.PAL`; AES boundary has AES table readers. |
| B014-0002SG-MCP-004 | `lookup_funcs` on all xref sites | Consumers map to `AboveFrame`, `FramePartPane`, `MapNamePane`, `MiniMapButtonPane`, `GroupPane`, `GroupPane2`, `BackPane`, `UserStatusPanePaint`, and the `0x005be520` user-status paint family. |
| B014-0002SG-MCP-005 | `decompile` for `0x004610f0`, `0x00461660`, `0x004b7410`, `0x00503350`, `0x00503650`, `0x0056c6c0`, `0x0056c970`, `0x004679e0` | Confirms source-use roles for constructor resource strings and palette branches. |
| B014-0002SG-MCP-006 | `entity_query` near `0x00610f50-0x00611010` | IDA labels are fragmentary UTF-16 heads such as `aMpartEpf`, `aBsEpf`, `aMpartPal`, and `aAl5Pal`; they are not reliable source names. |
| B014-0002SG-MCP-007 | `get_string` at literal starts | Mis-decoded fragments such as `F`, `T`, `TA`, and `AL5.PAL`; the report relies on raw bytes and xrefs instead. |
| B014-0002SG-LOCAL-001 | `python .\tools\int_convert.py 0x88` and `python .\tools\int_convert.py 136` | Range size verified as `0x88` / decimal `136`. |

## Exact Bytes And Boundaries

The target is exactly `0x00610f60-0x00610fe8`, size `0x88` / 136 bytes. The corrected end-exclusive boundary is sound.

| Range | Decoded bytes | Boundary decision |
| --- | --- | --- |
| `0x00610f60-0x00610f78` | UTF-16LE `FRMPART.EPF\0` | Starts immediately after [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData.md]. |
| `0x00610f78-0x00610f8c` | UTF-16LE `TABS.EPF\0` plus alignment null | Exact literal plus alignment. |
| `0x00610f8c-0x00610fa4` | UTF-16LE `FRMPART.EPD\0` | Last FrameChrome-local layout/resource literal in this run. |
| `0x00610fa4-0x00610fbc` | UTF-16LE `FRMPART.PAL\0` | Shared palette literal, not FrameChrome-only. |
| `0x00610fbc-0x00610fd0` | UTF-16LE `TABS.PAL\0` plus alignment null | Shared palette literal, not FrameChrome-only. |
| `0x00610fd0-0x00610fe8` | UTF-16LE `NPAL5.PAL\0` plus terminal padding | Shared palette literal. The old `0x00610fd4` endpoint is inside this string. |
| `0x00610fe8` | Bytes `63 7c 77 7b ...` | Start of [UID:0002JU][0x00610fe8-0x006112e8.AesReadOnlyTables.md]. |

Counter-evidence rejected: the old generated tracker row still names `0x00610f60-0x00610fd4.AboveFrameResourceStrings`. That is stale generated state. MCP bytes prove `0x00610fd4` begins the `A` in UTF-16 `NPAL5.PAL`; splitting there would corrupt the literal.

## Xref And Consumer Inventory

| Literal | Xrefs | Consumer/source route |
| --- | --- | --- |
| `FRMPART.EPF` at `0x00610f60` | `0x00461178`, `0x004b7446` | `AboveFrame` constructor and `FramePartPane::OnPaintFrame`, routed through [UID:0000JL][by-file/FrameChrome.md]. |
| `TABS.EPF` at `0x00610f78` | `0x004611a9` | `AboveFrame` constructor, routed through [UID:0000JL][by-file/FrameChrome.md]. |
| `FRMPART.EPD` at `0x00610f8c` | `0x00461222`, `0x004b744d` | `AboveFrame` constructor and `FramePartPane::OnPaintFrame`, routed through [UID:0000JL][by-file/FrameChrome.md]. |
| `FRMPART.PAL` at `0x00610fa4` | `0x00461683`, `0x00503375`, `0x00503678` | `AboveFrame::OnPaint`, [UID:0003XI][MapNamePane::OnPaint](by-memory/0x00503350-0x0050349f.MapNamePaneOnPaint.md), and [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md). |
| `TABS.PAL` at `0x00610fbc` | `0x0046167d`, `0x0056c6e9`, `0x0056c999` | `AboveFrame::OnPaint`, `GroupPane` paint, and `GroupPane2` paint under [UID:0000JS][by-file/Group.md]. |
| `NPAL5.PAL` at `0x00610fd0` | `0x0046169d`, `0x00467a20`, `0x005b9519`, `0x005be938` | `AboveFrame::OnPaint`, [UID:0000HO][by-file/BackPane.md], [UID:0003AE][UserStatusPanePaint](by-memory/0x005b8c70-0x005b9d6a.UserStatusPanePaint.md), and the `0x005be520` user-status paint family. |

The first three literals form a coherent FrameChrome resource-name subset. The palette tail does not: it is a linker-pooled/shared literal run with multiple source-use sites.

## Decompiled Behavior Facts

- `0x004610f0` (`AboveFrame` constructor) chooses `FRMPART.EPF` for low EPF frame indexes, `TABS.EPF` for tab frame indexes, and `FRMPART.EPD` for legacy mode.
- `0x00461660` (`AboveFrame::OnPaint`) chooses `FRMPART.PAL`, `TABS.PAL`, or `NPAL5.PAL` from the stored mode/index state before drawing the loaded tile.
- `0x004b7410` (`FramePartPane::OnPaintFrame`) chooses `FRMPART.EPF` or `FRMPART.EPD` from the global asset-mode flag and the pane's stored part index.
- `0x00503350` (`MapNamePane::OnPaint`) uses `FRMPART.PAL` in the EPF/resource-backed draw path.
- `0x00503650` (`MiniMapButtonPane::OnPaint`) loads `MMAPBUT.EPF` and renders it with `FRMPART.PAL`.
- `0x0056c6c0` and `0x0056c970` (`GroupPane` / `GroupPane2` paint paths) use `TABS.PAL` before loading/drawing `GROUP.EPF`.
- `0x004679e0` (`BackPane` paint path) uses `NPAL5.PAL` in the legacy/non-EPF branch. [UID:0000HO][by-file/BackPane.md] already records this.
- `0x005b8c70` and `0x005be520` are user-status paint consumers of `NPAL5.PAL`; the xrefs prove use even though the current user-status docs mostly describe palette resources generically.

## Heuristic And Ownership Reanalysis

The current page says all six literals are `FrameChrome` source-owned constants. That was defensible when the page was primarily correcting the bad `0x00610fd4` boundary, but it is too strong after the current MCP xref review.

Project rule and precedent support the split:

- `by-structure.md` states that `EMITTER_UIDS` is a routing field and may contain multiple UIDs.
- The same structure guidance says compiler/linker-pooled string literals and shared constants with no proven single owner should keep `CANONICAL_OWNER:NONE` and use multiple emitters for proven source-use contexts.
- Executed shared-string precedents such as `0003P9-shared-epf-suffix-source-routing.md` keep shared suffix data parentless/no-owner with multiple source emitters rather than forcing the first nearby owner.
- Existing mixed string-data precedent [UID:0002RO][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md] uses a non-emitting mixed index with exact child pages for the real source-use strings.

The physical adjacency to the `AboveFrame` vtable does not prove ownership for the full run. It proves the start boundary and makes the first three literals good FrameChrome source evidence, but the shared palette tail has independent non-FrameChrome consumers.

## Recommended Child Split

Keep [UID:0002SG] as the non-emitting parent/index, then add these exact children during an accepted implementation callback. Use validator-assigned UIDs for new files.

| Proposed child path | Range | Metadata | Rationale |
| --- | --- | --- | --- |
| `by-memory/0x00610f60-0x00610fa4.FrameChromeFrameResourceStrings.md` | `0x00610f60-0x00610fa4` | `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000JL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JL` | Groups `FRMPART.EPF`, `TABS.EPF`, and `FRMPART.EPD`, all local to `AboveFrame` / `FramePartPane` under `FrameChrome`. |
| `by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md` | `0x00610fa4-0x00610fbc` | `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JL,0000L2,0000LE` | `FRMPART.PAL` is used by FrameChrome, MapNamePane, and MiniMapButtonPane. |
| `by-memory/0x00610fbc-0x00610fd0.SharedTabsPaletteResourceString.md` | `0x00610fbc-0x00610fd0` | `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JL,0000JS` | `TABS.PAL` is used by FrameChrome and Group pane paint paths. |
| `by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md` | `0x00610fd0-0x00610fe8` | `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JL,0000HO,0000P2` | `NPAL5.PAL` is used by FrameChrome, BackPane, and UserStatus paint paths. |

The child pages are reconstructable as source-authored string literals, but they should not emit standalone declarations from the by-memory pages. The literals should appear at their use sites or in file-local constants once the relevant method/file bodies emit; duplicating a central global declaration from this `.rdata` pool would invent source structure not supported by the binary.

## Formal C++ / No-Code Disposition

No first-draft C++ body is appropriate for [UID:0002SG]. It is data, and after the recommended split it becomes a non-reconstructable mixed index. The exact target formal block should remain empty:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Use the same empty formal block for the four child string-literal pages. Do not add a comment-only emitter: this is not compiler-generated glue that needs a no-code marker, and a comment in the C++ field would still create artificial output surface. The proof for no C++ is the absence of a standalone source symbol, the shared/pooled literal evidence, and the fact that source-use emission belongs to the consuming method/file pages.

## Support Documentation Disposition

Accepted support edits if this report is implemented:

- [UID:00024S][by-memory/0x00610ed8-0x006125a8.AboveFrameAndLocaleReadOnlyData.md]: update the `0002SG` child row and child ownership matrix so it says this is a non-emitting mixed string-pool index with four exact source-use children, not a wholly FrameChrome-owned child.
- [UID:0000JL][by-file/FrameChrome.md]: update source-placement notes to say `FRMPART.EPF`, `TABS.EPF`, and `FRMPART.EPD` are FrameChrome-local resource-name literals, while `FRMPART.PAL`, `TABS.PAL`, and `NPAL5.PAL` are shared pooled palette literals with non-FrameChrome consumers. Keep FrameChrome as the route for the FrameChrome use sites only.

Check-only/no-edit support proof unless implementation finds a contradiction:

- [UID:000005][by-class/AboveFrame.md] already documents constructor resource selection, `OnPaint` palette selection, and all six literal values at equal or greater detail for the class route.
- [UID:00005I][by-class/FramePartPane.md] already documents `FRMPART.EPF` / `FRMPART.EPD` paint behavior at equal or greater detail for that class route.
- [UID:00008B][by-class/MiniMapButtonPane.md] already states `MMAPBUT.EPF` is rendered with `FRMPART.PAL`.
- [UID:0000HO][by-file/BackPane.md] already states `BackPane::OnPaint` uses `FRAME.PAL` in EPF mode and `NPAL5.PAL` in legacy mode.
- [UID:0002NG][by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md], [UID:0002JU][by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md], and [UID:0001XO][by-type/by-vtable/FrameChromeVtableFamily.md] already have correct predecessor/successor boundary facts and do not need source-placement edits.
- [UID:0000L2][by-file/MapNamePane.md], [UID:0000LE][by-file/MiniMap.md], [UID:0000JS][by-file/Group.md], [UID:0000P2][by-file/UserStatusPane.md], [UID:0003XI][by-memory/0x00503350-0x0050349f.MapNamePaneOnPaint.md], [UID:0001HC][by-memory/0x0056c4c0-0x0056e939.GroupPanes.md], and [UID:0003AE][by-memory/0x005b8c70-0x005b9d6a.UserStatusPanePaint.md] do not currently contradict the shared-palette routing. The exact child pages should carry the cross-owner xrefs; consumer pages do not need to enumerate every shared palette literal in this callback.

Explicit generated-file disposition:

- Do not manually edit `auto-generated/-ag-research-tracker.md` or `auto-generated/-ag-coverage-report-by-memory.md`, even though they still list the old `0x00610f60-0x00610fd4.AboveFrameResourceStrings` row and `file_missing` state.
- After implementation, run scoped validators for changed/created by-* files and record whether generated refresh clears or continues to show the stale generated rows.

## Rejected Alternatives

| Alternative | Decision | Reason |
| --- | --- | --- |
| Keep [UID:0002SG] as `CANONICAL_OWNER:0000JL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JL` for the whole range | Reject | `FRMPART.PAL`, `TABS.PAL`, and `NPAL5.PAL` have proven non-FrameChrome consumers. Whole-range FrameChrome ownership overclaims source placement. |
| Revert to `0x00610f60-0x00610fd4.AboveFrameResourceStrings` | Reject | `0x00610fd4` splits UTF-16 `NPAL5.PAL`; there is no direct xref to `0x00610fd4`; AES begins at `0x00610fe8`. |
| Create a new global `PaletteResourceNames` source owner | Reject | No binary evidence of a standalone source file/global table. The data is consistent with pooled wide string literals used by multiple source files. |
| Attach the whole range to `ResourceLayoutTable`, ImageLib, or EPF resource-loader ownership | Reject | Consumers pass literal names into loader/draw helpers; the resource subsystem uses the strings but does not own this source island. |
| Merge into [UID:00024S] parent aggregate only | Reject | The exact range is useful and source-authored; the parent is a broad non-emitting `.rdata` index. Keeping only the parent would lose source-use routing detail. |
| Emit named `static const wchar_t` declarations from the by-memory page | Reject for now | Original declaration placement is not proven, and shared-palette literals need source-use routing across multiple files. Emission belongs in consuming source bodies/files, not this data index. |

## Score Rationale

The parent [UID:0002SG] should rise to `90/93` after implementation because the byte range, literal inventory, old-boundary rejection, AES/vtable boundaries, xref inventory, source-use split, no-code decision, and stale generated-state explanation are all resolved. It should not be higher yet because the implementation will create new child pages whose final source declaration style remains intentionally blank/no-standalone-code, and not every consumer method page is being expanded into a palette-literal audit.

Each proposed child page should start at `88/92`: byte/value/xref/source-route evidence is strong, but original constant naming and exact declaration placement remain inferred. The shared palette children use `CANONICAL_OWNER:NONE` because no single source owner is proven; their `EMITTER_UIDS` name the source-use routes rather than an invented central owner.

## Implementation Tracking Checklist

- [x] Update [UID:0002SG][by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md]: metadata changed from `86/88`, `CANONICAL_OWNER:0000JL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JL`, `Nested:8` to `90/93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank emitter position, `Nested:4`. The formal C++ header block is empty and is the only `RECONSTRUCTION_CPP CODE` block after the repair. Proof: target Status/Summary/Exact Child Split/Byte And Boundary Evidence/Xrefs And Consumers/Decompile Evidence/Ownership And Rebuild Decision/Formal C++/Rejected Alternatives/Score Rationale/Changes sections now preserve MCP session `80de0a67`, exact `0x00610f60-0x00610fe8` byte run, six UTF-16 values, stale `0x00610fd4` rejection, AES successor, xrefs, consumers, source-use routing, no-code disposition, and rejected alternatives.
- [x] Create `by-memory/0x00610f60-0x00610fa4.FrameChromeFrameResourceStrings.md` for `FRMPART.EPF`, `TABS.EPF`, and `FRMPART.EPD`. Validator assigned [UID:00044T]. Metadata is `88/92`, `CANONICAL_OWNER:0000JL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JL`, blank emitter position, empty formal C++ block. Proof: page String Inventory/MCP Evidence records xrefs `0x00461178`, `0x004b7446`, `0x004611a9`, `0x00461222`, `0x004b744d` and FrameChrome route.
- [x] Create `by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md` for `FRMPART.PAL`. Validator assigned [UID:00044U]. Metadata is `88/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JL,0000L2,0000LE`, blank emitter position, empty formal C++ block. Proof: page Xrefs And Consumers records `0x00461683`, `0x00503375`, `0x00503678` and routes through FrameChrome, MapNamePane, and MiniMap.
- [x] Create `by-memory/0x00610fbc-0x00610fd0.SharedTabsPaletteResourceString.md` for `TABS.PAL`. Validator assigned [UID:00044V]. Metadata is `88/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JL,0000JS`, blank emitter position, empty formal C++ block. Proof: page Xrefs And Consumers records `0x0046167d`, `0x0056c6e9`, `0x0056c999` and routes through FrameChrome and Group.
- [x] Create `by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md` for `NPAL5.PAL`. Validator assigned [UID:00044W]. Metadata is `88/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JL,0000HO,0000P2`, blank emitter position, empty formal C++ block. Proof: page Xrefs And Consumers/MCP Evidence records `0x0046169d`, `0x00467a20`, `0x005b9519`, `0x005be938`, `xrefs_to 0x00610fd4` negative evidence, AES successor `0x00610fe8`, and routes through FrameChrome, BackPane, and UserStatusPane.
- [x] Update [UID:00024S][by-memory/0x00610ed8-0x006125a8.AboveFrameAndLocaleReadOnlyData.md]. Proof: Covered Data row, Child Ownership And Rebuild Matrix row, Evidence, Rebuild Notes, and 2026-06-26 Changes section now recognize [UID:0002SG] as a non-emitting mixed string-pool index with exact children [UID:00044T], [UID:00044U], [UID:00044V], and [UID:00044W], rather than a wholly FrameChrome-owned reconstructable child.
- [x] Update [UID:0000JL][by-file/FrameChrome.md]. Proof: Status resource-string anchor, File Role paragraph, Evidence Notes B014 bullet, Cross-References, and 2026-06-26 Changes entry now state only `FRMPART.EPF`, `TABS.EPF`, and `FRMPART.EPD` are FrameChrome-local, while `FRMPART.PAL`, `TABS.PAL`, and `NPAL5.PAL` are shared with MapName/MiniMap, Group, BackPane, and UserStatus use sites.
- [x] Record no-edit proof for check-only support pages. Proof: no edits were made to `by-class/AboveFrame.md` because it already documents constructor resource selection, `OnPaint` palette selection, and all six literal values; `by-class/FramePartPane.md` already documents `FRMPART.EPF`/`FRMPART.EPD` paint behavior; `by-class/MiniMapButtonPane.md` already states `MMAPBUT.EPF` renders with `FRMPART.PAL`; `by-file/BackPane.md` already states legacy `BackPane::OnPaint` uses `NPAL5.PAL`; `by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md`, `by-memory/0x00610fe8-0x006112e8.AesReadOnlyTables.md`, and `by-type/by-vtable/FrameChromeVtableFamily.md` already have correct boundary facts; `by-file/MapNamePane.md`, `by-file/MiniMap.md`, `by-file/Group.md`, `by-file/UserStatusPane.md`, `by-memory/0x00503350-0x0050349f.MapNamePaneOnPaint.md`, `by-memory/0x0056c4c0-0x0056e939.GroupPanes.md`, and `by-memory/0x005b8c70-0x005b9d6a.UserStatusPanePaint.md` do not contradict the child-page shared-palette routing and did not require narrow edits.
- [x] Do not edit generated/project-level files, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md` manually. Proof: manual by-* edits were limited to [UID:0002SG], [UID:00024S], [UID:0000JL], and the four new child pages; this report was updated in the B014 research folder. Validator-driven side effects are recorded below: `tools/validator.ini`, `project-level/-auto-completion-stats.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/-ag-research-tracker.md` changed/refreshed through validator commands, not manual edits. No manual coverage report was edited.
- [x] Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed/created by-* file. Final validator results:

| File | Command id | Timestamp | Exit | Ok | Warnings / generated-refresh |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x00610f60-0x00610fa4.FrameChromeFrameResourceStrings.md` | `000000002787` | `2026-06-26T15:16:15-04:00` | `0` | `1` | No warnings; `generated_refresh: deferred`, no queued generated jobs by queue status `000000002796`. UID assignment happened earlier in command `000000002775` as [UID:00044T]. |
| `by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md` | `000000002788` | `2026-06-26T15:16:23-04:00` | `0` | `1` | No warnings; `generated_refresh: deferred`, no queued generated jobs by queue status `000000002796`. UID assignment happened earlier in command `000000002778` as [UID:00044U]. |
| `by-memory/0x00610fbc-0x00610fd0.SharedTabsPaletteResourceString.md` | `000000002789` | `2026-06-26T15:16:34-04:00` | `0` | `1` | No warnings; `generated_refresh: deferred`, no queued generated jobs by queue status `000000002796`. UID assignment happened earlier in command `000000002784` as [UID:00044V]. |
| `by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md` | `000000002790` | `2026-06-26T15:16:47-04:00` | `0` | `1` | No warnings; `generated_refresh: deferred`, no queued generated jobs by queue status `000000002796`. UID assignment happened earlier in command `000000002785` as [UID:00044W]. |
| `by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md` | `000000002791` | `2026-06-26T15:16:58-04:00` | `0` | `1` | No warnings; repaired autogen C++ state `invalid -> blank` after removing the body-level marker quote; `generated_refresh: deferred`, no queued generated jobs by queue status `000000002796`. Earlier command `000000002786` updated the stale `0002SG` registry path from `0x00610f60-0x00610fd4.AboveFrameResourceStrings` to the live path and resolved child TMP links. |
| `by-memory/0x00610ed8-0x006125a8.AboveFrameAndLocaleReadOnlyData.md` | `000000002795` | `2026-06-26T15:17:45-04:00` | `0` | `1` | Pre-existing registry warnings remain for old child UIDs `0003OX`, `0003OZ`, `0003OY`, `0003P0`, `0003P1`, and stale target `0000YR` path `by-memory/0x00463310-0x004679be.ApplicationLifecycle.md`; no B014 child/TMP warnings remain. `generated_refresh: deferred`, no queued generated jobs by queue status `000000002796`. |
| `by-file/FrameChrome.md` | `000000002794` | `2026-06-26T15:17:33-04:00` | `0` | `1` | Pre-existing registry warnings remain for `0003I2`, `0003I3`, and stale `0000YI` path `by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md`; no B014 child/TMP warnings remain. `generated_refresh: deferred`, no queued generated jobs by queue status `000000002796`. |

Generated-refresh observation: `auto-generated/-ag-coverage-report-by-memory.md` and `auto-generated/-ag-research-tracker.md` headers show validator command id `000000002795` and `validator-refreshed-at: 2026-06-26T15:17:45-04:00`. Read-only checks show tracker/coverage rows for [UID:0002SG] at `90/93`, [UID:00044T] through [UID:00044W] at `88/92`, and the old generated `0x00610f60-0x00610fd4.AboveFrameResourceStrings` row is gone from those refreshed generated files.
- [x] Update this report checklist after implementation with proof. Proof: this checked checklist records changed paths, metadata, child UIDs, validators, warnings, generated-refresh state, and lease cleanup. Lease proof: B014 acquired leases successfully on `by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md`, `by-memory/0x00610ed8-0x006125a8.AboveFrameAndLocaleReadOnlyData.md`, and `by-file/FrameChrome.md` immediately before the edit batch. After validators, `python .\tools\leaser\leaser.py B014 unlease ...` returned `Rejected[No active lease]` for all three because the short leases had already expired; `tools/leaser/Agents/current_leases.md` read afterward contained no B014 entries. Unchecked blockers: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0002SG-FrameChromeResourceStrings-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/0002SG-FrameChromeResourceStrings-source-quality.md","timestamp":"2026-06-26T15:23:46","uid":"0002SG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
