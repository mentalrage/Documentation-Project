** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_header_missing **
# B001-MEMTOOL-00506970 MapPaneInputPacketRenderCore Warning Audit

## Final Recommendation

Keep [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](../../../by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md) as a reviewed, non-emitting mixed-owner audit container:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- `EMITTER_POSITION_OPTIONAL:` blank

The Advanced-Error-Scan warning is a real but low-severity document-text issue, not an ownership, range, split, merge, or IDA metadata issue. The page title uses the expanded phrase "MapPane Input, Packet, And Render Core", but the exact compact filename token `MapPaneInputPacketRenderCore` does not appear anywhere in the document body. The scanner explicitly checks for filename label text, so it flags the page.

Recommended supervisor edit to the target page, directly under `## Status`:

```markdown
- Filename label: `MapPaneInputPacketRenderCore`; compact filename/search label for this expanded `MapPane Input, Packet, And Render Core` mixed-owner audit container.
```

No `by-memory/-coverage-report.md` edit is required. The coverage row already contains `MapPaneInputPacketRenderCore`, already classifies the target as `not_reconstructable`, and already records the correct child ownership split. After applying the one-line body alias, regenerate the normal `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan output to confirm the warning clears. Do not run memory-range repair modes for this item.

## Target And Warning

Target:

- UID: `0001AT`
- Path: `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md`
- Current generated warning: `0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md: missing document text for MapPaneInputPacketRenderCore`

Facts:

- `auto-generated/by-memory-tool-report.md` says Advanced-Error-Scan is heuristic and checks whether filename start/end addresses and label text appear in the Markdown body after ignored sections.
- The target body contains both range endpoints in the title, `# 0x00506970-0x0050e320 MapPane Input, Packet, And Render Core`.
- `Select-String -SimpleMatch MapPaneInputPacketRenderCore` against the target body returned no matches.
- The warning names only `MapPaneInputPacketRenderCore`, not the start or end address, matching the missing exact compact label.

Inference:

- The warning is caused by the title/body using a human-expanded label with spaces and commas while the scanner expects the compact filename label as literal text.
- Adding a short filename-label line in the Status section is the smallest correction and does not alter the research conclusion.

## Current Page State

Header facts from the target page:

```text
*** UID:0001AT ***
*** COMPLETION:88 ***
*** CONFIDENCE:90 ***
*** CANONICAL_OWNER:NONE ***
*** RECONSTRUCTABLE:FALSE ***
*** EMITTER_UIDS: ***
*** EMITTER_POSITION_OPTIONAL: ***
```

The page is already explicit about its role:

- Disposition: reviewed non-emitting mixed-owner container.
- Entity kind: by-structure audit aggregate over exact child memory pages.
- Autogen status: intentionally parentless and non-emitting.
- Exact MapPane source-bearing children `00037Q` through `00037Y`, plus `0001AU`, attach to [UID:00007Q][MapPane](../../../by-class/MapPane.md).
- Exact [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](../../../by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) remains attached to [UID:0000MS][ProfileStorage](../../../by-file/ProfileStorage.md).
- The page already says not to mark this aggregate reconstructable, not to attach it to MapPane, and not to emit C++ from it.

## IDA MCP Evidence

Live IDA MCP session used:

- Database/session: `b001_0003gy`
- Module: `NexusTK.exe`
- Input path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- `server_health` result: `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`

Function anchor facts from `lookup_funcs`:

| Address | IDA function | Size | Documentation role |
| --- | --- | ---: | --- |
| `0x00506970` | `sub_506970` | `0xf` | first function in `00037Q` object lookup helper aggregate |
| `0x00506ce0` | `sub_506CE0` | `0x35` | exact child `0001AU` hit-test helper |
| `0x00506d20` | `sub_506D20` | `0xcc` | `00037R` resize/command cluster start |
| `0x00507150` | `sub_507150` | `0xb22` | `00037S` mouse event core start |
| `0x00507c90` | `sub_507C90` | `0x1176` | `00037T` packet dispatcher start |
| `0x00508f60` | `sub_508F60` | `0xcb` | `00037U` notify/timer core start |
| `0x00509470` | `sub_509470` | `0x8` | `00037V` render-view child start |
| `0x0050a500` | `sub_50A500` | `0x337` | `00037W` paint/lighting child start |
| `0x0050aba0` | `sub_50ABA0` | `0x4d8` | exact `0001AV` ProfileStorage `SaveUserSettings` child |
| `0x0050b080` | `sub_50B080` | `0xb9` | `00037X` interaction/map-change child start |
| `0x0050bce0` | `sub_50BCE0` | `0x33c` | `00037Y` tile/object-grid child start |
| `0x0050e320` | `sub_50E320` | `0x196` | separate following `000232`, not part of this aggregate |

Raw boundary bytes from `get_bytes`:

| Range sampled | Result | Meaning |
| --- | --- | --- |
| `0x00506962` size `16` | fourteen `0xcc` bytes followed by `55 8b` | padding before aggregate start at `0x00506970` |
| `0x00506d10` size `16` | function epilogue ending at `0x00506d15`, then `0xcc` padding | exact padding before `0x00506d20` child |
| `0x0050ab90` size `24` | short returns, then `0xcc` padding, then `55 8b ec` at `0x0050aba0` | padding before ProfileStorage island |
| `0x0050b070` size `24` | `SaveUserSettings` epilogue, then eight `0xcc` bytes, then `55 8b ec` at `0x0050b080` | padding after ProfileStorage island |
| `0x0050e310` size `24` | epilogue through `0x0050e317`, `0xcc` padding, then `55 8b ec` at `0x0050e320` | exact boundary before following `000232` |

Xref facts:

- `xrefs_to 0x00506970` reports 64 code xrefs, supporting that the first child is a shared helper cluster rather than a single source-level aggregate.
- `xrefs_to 0x0050aba0` reports 8 code xrefs, supporting the separately documented `SaveUserSettings` island.
- `xrefs_to 0x0050e320` reports 4 code xrefs, supporting that `0x0050e320` is a real following function start and not padding/tail data.

Inference:

- The IDA evidence supports the current child split and the mixed-owner status.
- It does not support converting `0001AT` itself into a source-emitting MapPane item because a ProfileStorage-owned exact child is physically inside the broad range.

## Generated And Coverage Evidence

`auto-generated/-ag-memory-coverage.md` currently reports the exact children as emitting through their real owners:

| UID | Range/name | State | Canonical owner | Emitters | Output |
| --- | --- | --- | --- | --- | --- |
| `00037Q` | `0x00506970-0x00506cdd.MapPaneObjectLookupHelpers` | emits | `00007Q` | `00007Q` | `auto-generated/NexusTK/map/MapPane.cpp` |
| `0001AU` | `0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane` | emits | `00007Q` | `00007Q` | `auto-generated/NexusTK/map/MapPane.cpp` |
| `00037R` | `0x00506d20-0x00507150.MapPaneResizeCommandInputCore` | emits | `00007Q` | `00007Q` | `auto-generated/NexusTK/map/MapPane.cpp` |
| `00037S` | `0x00507150-0x00507c90.MapPaneMouseEventCore` | emits | `00007Q` | `00007Q` | `auto-generated/NexusTK/map/MapPane.cpp` |
| `00037T` | `0x00507c90-0x00508f60.MapPanePacketDispatcher` | emits | `00007Q` | `00007Q` | `auto-generated/NexusTK/map/MapPane.cpp` |
| `00037U` | `0x00508f60-0x00509470.MapPaneNotifyTimerCore` | emits | `00007Q` | `00007Q` | `auto-generated/NexusTK/map/MapPane.cpp` |
| `00037V` | `0x00509470-0x0050a4fd.MapPaneRenderViewCore` | emits | `00007Q` | `00007Q` | `auto-generated/NexusTK/map/MapPane.cpp` |
| `00037W` | `0x0050a500-0x0050ab95.MapPanePaintLightingCore` | emits | `00007Q` | `00007Q` | `auto-generated/NexusTK/map/MapPane.cpp` |
| `0001AV` | `0x0050aba0-0x0050b078.SaveUserSettings` | emits | `0000MS` | `0000MS` | `auto-generated/NexusTK/profile/ProfileStorage.cpp` |
| `00037X` | `0x0050b080-0x0050bcd8.MapPaneInteractionMapChangeCore` | emits | `00007Q` | `00007Q` | `auto-generated/NexusTK/map/MapPane.cpp` |
| `00037Y` | `0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore` | emits | `00007Q` | `00007Q` | `auto-generated/NexusTK/map/MapPane.cpp` |

The parent target is separately reported as:

```text
| [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md) | not_reconstructable | `NONE` |  |  | no |  | `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md` |  |
```

Manual coverage report context already has the correct row text and does not need replacement:

```text
- [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md) 0x00506970-0x0050e320 | mixed-owner audit container | MapPaneInputPacketRenderCore : not_reconstructable : 88% : strong : Reviewed non-emitting container for the old physical MapPane input/packet/render span; exact MapPane children [UID:00037Q][0x00506970-0x00506cdd.MapPaneObjectLookupHelpers](by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md)-[UID:00037Y][0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore](by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md) and [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md) carry source ownership under [UID:00007Q][MapPane](by-class/MapPane.md), while [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) remains excluded under [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md).
```

## Ownership, Emitter, Split, And Repair Decision

Ranked options:

| Rank | Option | Decision | Reason |
| ---: | --- | --- | --- |
| 1 | Keep `0001AT` as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters | Accept | This is a reviewed mixed-owner audit/index container. Exact source-bearing children already carry ownership and output routing. |
| 2 | Add a filename-label alias line to the target body | Accept | This directly fixes the scanner warning without changing semantics. |
| 3 | Attach parent `0001AT` to `MapPane` | Reject | The parent physical span contains `0001AV SaveUserSettings`, a ProfileStorage-owned island. Attaching the broad container to MapPane would overclaim. |
| 4 | Add `EMITTER_UIDS:00007Q` or `0000L3` to `0001AT` | Reject | `RECONSTRUCTABLE:FALSE` pages must not emit. The MapPane child pages already emit through MapPane. |
| 5 | Add multiple emitters to `0001AT` | Reject | This is not a pooled source literal requiring repeated source-use emission. It is a non-source audit container over independently emitted exact children. |
| 6 | Split or merge more ranges for this warning | Reject | The relevant split already exists. The warning is text-token-only, and IDA confirms the current boundaries. |
| 7 | IDA function/range repair | Reject | IDA modeled the key child starts, the ProfileStorage island, padding, and following function boundary consistently with the documentation. |

By-structure rule application:

- `CANONICAL_OWNER` is semantic ownership, while `EMITTER_UIDS` is output routing.
- `RECONSTRUCTABLE:FALSE` is appropriate for a reviewed mixed-owner convenience page whose exact children already carry real source ownership.
- `RECONSTRUCTABLE:FALSE` pages must not have nonblank emitters or reconstruction code.
- Parent aggregate code must not contain child C++.

## Score And Code-Entry Effect

Before:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `RECONSTRUCTABLE:FALSE`

After recommended alias edit:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `RECONSTRUCTABLE:FALSE`

No score change is recommended. The optional line fixes scanner discoverability only. It adds no new behavioral, boundary, ownership, or source-reconstruction evidence.

No code-entry recommendation is appropriate for `0001AT`. The target is a non-emitting audit container. The active 90/90+ code-entry gate applies only to source-output pages; exact child pages should be considered individually when their dependencies, boundaries, names, and source placement clear the gate.

## Exact Required Changes

Target page optional edit:

File:

```text
by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md
```

Placement:

```markdown
## Status

- Filename label: `MapPaneInputPacketRenderCore`; compact filename/search label for this expanded `MapPane Input, Packet, And Render Core` mixed-owner audit container.
- Disposition: reviewed non-emitting mixed-owner container
```

Metadata:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
```

Coverage-report edits:

```text
None.
```

Generated report edits:

```text
Do not edit auto-generated/by-memory-tool-report.md manually. Regenerate it after the optional target-page edit.
```

Memory range or IDA repairs:

```text
None.
```

## Validation And Commands

Commands/evidence gathered:

- Read `tools/leaser/Agents/Agent-B001/goal.md`.
- Read the target page.
- Read relevant `by-structure.md` owner/emitter and mixed-container rules.
- Read the Advanced-Error-Scan warning in `auto-generated/by-memory-tool-report.md`.
- Checked `auto-generated/-ag-memory-coverage.md` rows for `0001AT`, children `00037Q` through `00037Y`, `0001AU`, `0001AV`, and following `000232`.
- Checked `by-memory/-coverage-report.md` row context for `0001AT`.
- Ran `Select-String -SimpleMatch MapPaneInputPacketRenderCore` on the target page; result: no match.
- Ran IDA MCP `server_health`; result: ok, auto-analysis and Hex-Rays ready.
- Ran IDA MCP `lookup_funcs` for child and boundary anchors; result summarized above.
- Ran IDA MCP `get_bytes` for padding/boundary samples; result summarized above.
- Ran IDA MCP `xrefs_to` for `0x00506970`, `0x0050aba0`, and `0x0050e320`; result summarized above.

Validation performed:

- No project validator was run because this B-agent task produced a report only and did not edit by-memory documentation.
- No dry-run validator mode was used.
- No memory-range mode was used.

Recommended supervisor validation if the optional target-page alias is applied:

- Regenerate the normal `auto-generated/by-memory-tool-report.md` output and verify the `MapPaneInputPacketRenderCore` Advanced-Error-Scan entry disappears.
- No `by-memory/-coverage-report.md` row replacement is required.
- No memory-range repair or IDA repair pass is required for this warning.

## Confidence And Blockers

Confidence: high.

No blocker. The only remaining action is a one-line optional target-page alias edit plus normal regenerated warning output if the supervisor wants the Advanced-Error-Scan entry cleared.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_header_missing","source_path":"executed-b-agent-research/B001/B001-MEMTOOL-00506970-MapPaneInputPacketRenderCore.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
