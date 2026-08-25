** TARGET-REPORT-UID:00010C **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00010C / 00010G ClanStatusPane UI Source-Quality Research

## Finalized Report / Current Recommendation

This report is now updated through the authorized implementation callback. The original 2026-06-16 recommendation to raise [UID:00010C] and [UID:00010G] from `82/88` to `86/90` has already been incorporated into the current target metadata and generated output. The current recommendation is to preserve both targets at `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00002K`, `EMITTER_UIDS:00002K`, `RECONSTRUCTABLE:TRUE`, `Nested:0`, and non-emitting aggregate marker C++.

Implementation callback disposition:
- [UID:00010C] formerly had stale `AN*.EPF` / `ANBUT.EPF` wording in its metadata Item Summary even though the body prose already documented full `CLAN1.EPF`, `CLAN2.EPF`, `CLAN3.EPF`, and `CLANBUT.EPF` resources. The callback repaired that Item Summary to the full `CLAN1.EPF`/`CLAN2.EPF`/`CLAN3.EPF`/`CLANBUT.EPF` wording with accepted state/event detail, while preserving metadata, owner/emitter, `Nested:0`, and the non-source aggregate C++ marker.
- [UID:00010G] already reflected the accepted row-helper names, row semantics, rectangle note, score, owner, emitter, and non-emitting aggregate marker; the callback validator confirmed the page without requiring a manual target edit.
- [UID:00002K] `ClanStatusPane` and [UID:0000I8] `Clan` already contained the accepted support sync at same-or-greater detail and did not receive score changes or manual edits from this callback.
- `by-memory/-coverage-report.md` still has stale [UID:00010C] and [UID:00010G] rows at `82%`; those rows are supervisor-owned and were not edited by B002.

## Supporting Research

This artifact began as an existing-report revalidation repair, not new report-only target research. The B002 goal returned the executed artifact with command `000000007182` at `2026-07-05T15:40:39-04:00` because the active report was missing the required `TARGET-REPORT-UID` header. After B002 repaired the report text, the supervisor cleared the active revalidation marker with validator command `000000007200` at `2026-07-05T16:00:53-04:00`. The supervisor then authorized the narrow implementation callback after Gate 1 passed. This report now records both the repaired Gate 1 research artifact and the callback implementation results; it has no live `REPORT-VALIDATION-STATUS` header, and the validator-owned lifecycle facts remain only in the history footer.

Evidence refreshed for the repair and callback was limited to current repository text, scoped file validators, and generated output inspection:
- Current target pages [UID:00010C] and [UID:00010G].
- Current support pages [UID:00002K] `ClanStatusPane` and [UID:0000I8] `Clan`.
- Current generated file `auto-generated/NexusTK/social/Clan.cpp`.
- Current supervisor-owned coverage rows for [UID:00010C] and [UID:00010G].

B002 manually edited only [UID:00010C] and this report during the callback. Scoped validators refreshed generated output and project stats; B002 did not manually edit generated files, coverage reports, validator state, lifecycle/archive locations, supervisor ledgers, or IDA DB. No `execute_report`, dry-run/probing execute variant, registry lifecycle command, report move, or archive/manual move command was run by B002.

## Target

- Primary target: [UID:00010C][0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput](../../../../../by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md)
- Primary target: [UID:00010G][0x00486800-0x00487291.ClanStatusPaneRows](../../../../../by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md)
- Class owner/emitter: [UID:00002K][ClanStatusPane](../../../../../by-class/ClanStatusPane.md)
- File route: [UID:0000I8][Clan](../../../../../by-file/Clan.md), generated as `NexusTK/social/Clan.cpp`
- Original source queue row: `B002-goal2-clan-status-pane-ui-source-quality-00010C-00010G-20260616`

## Current Target State

[UID:00010C] currently has `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00002K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002K`, blank optional emitter position, and `Nested:0`. Its formal C++ block is not source-bearing; it contains only an aggregate marker comment instructing that `OnPaintFrame`, `OnKeyInput`, and `OnMouseEvent` should be split before source bodies are emitted. The page body documents the full `CLAN*` resource names, state fields, event fields, vtable anchors, row-action dispatch, and score rationale. The callback repaired the former metadata Item Summary phrase ``AN*.EPF`/`ANBUT.EPF` resource selection`; the current summary names full `CLAN1.EPF`/`CLAN2.EPF`/`CLAN3.EPF`/`CLANBUT.EPF` resources and the accepted state/event detail.

[UID:00010G] currently has `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00002K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002K`, blank optional emitter position, and `Nested:0`. Its formal C++ block is not source-bearing; it contains only an aggregate marker comment for `DrawStatusRowText`, `GetStatusRowRect`, and `HitTestStatusRow`. The page already carries the accepted helper names, row role table, rectangle output caution, final C++ no-code rationale, and `86/90` score rationale.

[UID:00002K] `ClanStatusPane` currently has `COMPLETION:87`, `CONFIDENCE:89`. It already uses the full `CLAN1.EPF`/`CLAN2.EPF`/`CLAN3.EPF`/`CLANBUT.EPF` resource names, accepted method rows for `OnPaintFrame`, `OnKeyInput`, `OnMouseEvent`, `DrawStatusRowText`, `GetStatusRowRect`, and `HitTestStatusRow`, and the accepted field names `m_currentClanStatusView`, `m_statusDataVersion`, and `m_selectedStatusRow`.

[UID:0000I8] `Clan` currently has `COMPLETION:90`, `CONFIDENCE:85`. It already lists the full clan resource names and explains that IDA labels such as `AN*`, `LAN*`, and `ANBAN*` are interior suffix labels inside full UTF-16 strings unless a future callsite intentionally references a suffix.

Generated output `auto-generated/NexusTK/social/Clan.cpp` currently has `validator-command-id: 000000007206`, `validator-refreshed-at: 2026-07-05T16:06:49-04:00`, `validator-refresh-source: deferred-generated-refresh`, and emits [UID:00010C] and [UID:00010G] as non-source aggregate markers at `Completion:86 | Confidence:90`.

The live revalidation status header has been cleared by supervisor-owned validator command `000000007200`; no live `REPORT-VALIDATION-STATUS` / `REPORT-REVALIDATION-REASON` header remains at the top of this artifact. The `VALIDATOR-REPORT-HISTORY` footer remains validator-owned and records the historical `needs-revalidation`, `de-executed-for-rework`, and `active-revalidation-cleared` events without making the current report status live-blocked.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best defensible result | Rejected alternatives / remaining blocker |
| --- | --- | --- | --- |
| Status resource names | [UID:0003B8], [UID:0002MP], and `0x00484a60` xrefs at `0x00484aa3`, `0x00484ab0`, `0x00484abd`, `0x00484ae8`. | Use full resource names `CLAN1.EPF`, `CLAN2.EPF`, `CLAN3.EPF`, `CLANBUT.EPF`. | Reject `AN1.EPF`, `AN2.EPF`, `AN3.EPF`, `ANBUT.EPF` as source names; they are IDA interior suffix labels unless a future callsite passes suffix starts. |
| Current view/state field `+0xf8` | Parser reset to `0`; paint selects resource/background and row sets; key/mouse toggles `0/1`; raw show helpers write `2/3/4`. | `m_currentClanStatusView` is the best current name; enum values are `0=status`, `1=management`, `2=infoList`, `3=joinList`, `4=enlistList`. | Reject `m_currentTab` because values `2-4` are child-pane views, not tabs. |
| Version/status byte `+0xf9` | [UID:00010B] writes from packet version; row paint/mouse/eligibility compare against `0`, `1`, and `2`. | `m_statusDataVersion` is the best descriptive field. | Reject `permissionFlags`: comparisons are version thresholds and the byte is loaded from the status/attribute packet. |
| Selected row word `+0xfa` | Parser resets to `0xffff`; paint draws overlay when set; mouse stores clicked rows and clears to `-1` on event kind `3`; row drawer offsets selected row text by two pixels. | `m_selectedStatusRow` as signed 16-bit row index, with `-1`/`0xffff` meaning none. | Reject `selectedFieldIndex`: the row helpers and packet action caller use visible row numbers, not parser field numbers. |
| Raw attribute blob fields `+0x14e/+0x150` | [UID:00010B] reads a 16-bit length and copies raw attribute bytes. | `m_rawAttributeDataLength` and raw attribute payload storage are parser-owned support fields. | They are not part of [UID:00010C]/[UID:00010G] method signatures, but support docs should not call them unknown tail storage. |
| Event/input fields | Local IDA exports for `0x00484cd0` and `0x00484db0`. | Key event: `eventType` at `+4`, key/wide character at `+8`, key state/modifier/repeat byte at `+0x10a`. Mouse event: kind at `+4`, `mouseX` at `+8`, `mouseY` at `+0x0c`. | Exact event class and enum names remain unresolved; this caps first-draft C++ but not the current documentation score. |
| Secondary receiver adjustment | `OnKeyInput` and `OnMouseEvent` decompile through adjusted receiver offsets `this+88/89/90`, corresponding to full `ClanStatusPane+0xf8/+0xf9/+0xfa`; `this-160` is the full object. | Document source member names at full-object offsets and note the `+0xa0` adjusted receiver. | Reject treating `+0x58/+0x59/+0x5a` as real full-object fields. |
| Row text field names | Parser fills `+0xfe` and `+0x2150..+0x24c0`; row drawer reads them by row index; text is packet/server supplied. | Use `m_statusHeaderText`, `m_statusActionText[5]`, and `m_managementActionText[7]` or equivalent neutral storage names. | Do not hard-code localized/user-facing labels into field names. |
| Row/action semantics | [UID:00010H], [UID:00021D]-[UID:00021M] context, dispatcher dialog cases. | Rows `2-13` map to opcode `0x4b` subtypes `1-12`; row `7` delegates to subtype `6` helper `0x00485960`; rows `14/15` are tab rectangles. | Row labels remain unresolved; use action-subtype semantics rather than invented UI labels. |
| Row helper names | Function behavior and callers. | `DrawStatusRowText`, `GetStatusRowRect`, and `HitTestStatusRow`. | Reject `DrawInfoRow`; it draws status/manage action rows, not only an info-list row. |
| Rectangle output type | `0x00486d20` and `0x00486f90` call `0x004b7c50`; mouse invalidation passes the same four-dword local to pane vtable slot `+0x20`. | Reuse the existing UI rectangle type once the common type name is final. | Do not invent a `ClanStatusRowRect` type. |
| Relationship to [UID:00021N]-[UID:00021R] | Adjacent helper pages document the row blocked predicate and child-view mode writes `2/3/4`. | They support `m_currentClanStatusView`, child pane field names, and class ownership. | Raw/no-route show helpers still cap their own C++ emission and should not be used as direct caller proof for [UID:00010C]/[UID:00010G]. |
| Relationship to [UID:00010H] | Direct caller from `0x00484e91`; clicked rows `2-13` dispatch to row action packet helper. | [UID:00010C] should link row-action dispatch to [UID:00010H]. | Exact original packet helper name/signature remains a C++ cap for the aggregate frame/input target. |
| Source placement | `ClanStatusPane` class page, `Clan` file page, vtables/resource strings in the clan family, and generated route `NexusTK/social/Clan.cpp`. | Keep owner/emitter [UID:00002K], surfaced through [UID:0000I8] `social/Clan.cpp`. | Reject `ClanDialogs.cpp`, `ClanBank.cpp`, and protocol-only ownership for these UI bands. |
| Final C++ eligibility | Both targets satisfy score/emitter thresholds but remain multi-method aggregate ranges. | Keep non-source aggregate marker comments only. | Do not emit decompiler-shaped code until method-level split, exact event types, row enum labels, rectangle type, and packet helper names are source-grade. |

## Evidence Standards Used

This report applies source-quality standards, not byte-equivalence-only decompiler acceptance. A name or ownership claim is accepted only where the binary behavior, surrounding by-* docs, current generated route, and support pages agree. Inferences are kept descriptive and capped where original symbol names, exact event enum names, user-visible row labels, or common UI type names are still not recovered.

For this repair, old report evidence is preserved as historical B002 research, while current-state claims are checked against current repository documents and generated output. No fresh IDA MCP claim was added during the repair-only pass, and no fallback-only new target evidence was substituted for the existing IDA/local-export evidence.

## Evidence Checked

- `0x00484a60` has vtable xref `0x006155b4`, draws status resources, draws selected row overlay when full-object word `+0xfa` is not `0xffff`, calls row text/rect helpers, and gates rows by full-object bytes `+0xf8` and `+0xf9`.
- `0x00484cd0` has vtable xref `0x006155c4`; local IDA export decompiles it as a secondary-vtable key handler. It reads `event+4 == 8`, narrows the key from `event+8` with fallback/state byte `event+0x10a`, gates Page Up/Page Down/Escape on that state byte being zero, toggles adjusted receiver bytes `this+88/89` which map to full-object `+0xf8/+0xf9`, calls `0x00487370` on Escape, and invalidates through the primary vtable.
- `0x00484db0` has vtable xref `0x006155c0`; local IDA export decompiles it as a secondary-vtable mouse handler. It reads mouse event kind at `event+4`, mouse coordinates at `event+8` and `event+0x0c`, calls `HitTestStatusRow`, stores adjusted receiver word `this+90` mapping to full-object `+0xfa`, calls [UID:00010H][ClanStatusRowActionPacket](../../../../../by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md), computes row invalidation rectangles through `0x00486d20`, and toggles view modes for rows `14` and `15`.
- `0x00486800` is called thirteen times only from `0x00484a60`; it draws row `0` and rows `2-13` from wide text slots. This is a row text drawer, not an info-only row drawer.
- `0x00486d20` fills a rectangle out-parameter through `0x004b7c50`; row visibility is controlled by `+0xf8`. It returns invalid `-1` bounds for hidden rows.
- `0x00486f90` loops row indices `0..15`, builds row rectangles through `0x004b7c50`, tests the input point through `0x004b7e80`, and returns the first hit row or `-1`.
- [UID:0003B8] proves the full resource strings are `CLAN1.EPF`, `CLAN2.EPF`, `CLAN3.EPF`, and `CLANBUT.EPF`; the `AN*` labels are interior suffix labels with no current direct xrefs.
- [UID:00010B] proves `+0xf9` is the attribute/status data version byte from opcode `0x43` subtype `0`, `+0xfa` is reset to `0xffff`, and rows `0`, `2-13` text storage is server/packet populated.
- [UID:00021N]-[UID:00021R] prove `+0xf8` has more than two tab states: `0` status/action rows, `1` manage/action rows, `2` info child view, `3` join-list child view, and `4` enlist-list child view.
- [UID:00010H] proves clicked rows `2-13` map to opcode `0x4b` subtypes `1-12`, with row `7` delegated to subtype `6` helper `0x00485960`.
- Current generated `Clan.cpp` confirms [UID:00010C] and [UID:00010G] still emit as aggregate marker comments at `86/90`, not as source bodies.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-00010C-G-01 | [UID:00010C] belongs to `ClanStatusPane`, remains reconstructable, and should stay at `86/90` with [UID:00002K] as owner/emitter. | High | Target metadata verified after edit; validator `000000007205` returned exit `0`, `ok: 1`; generated `Clan.cpp` refreshed at `000000007206`. | `by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md` metadata and Score Rationale | already-present | already-present |
| C-00010C-G-02 | [UID:00010G] belongs to `ClanStatusPane`, remains reconstructable, and should stay at `86/90` with [UID:00002K] as owner/emitter. | High | Target metadata and C++ marker verified; validator `000000007206` returned exit `0`, `ok: 1`. | `by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md` metadata and Score Rationale | already-present | already-present |
| C-00010C-G-03 | Both targets should keep non-source aggregate marker C++, not source bodies. | High | UID00010C and UID00010G formal C++ blocks verified unchanged except no-code marker content already present. | Both target `RECONSTRUCTION_CPP CODE` blocks and First-Draft C++ notes | already-present | already-present |
| C-00010C-G-04 | Source-facing status resources are `CLAN1.EPF`, `CLAN2.EPF`, `CLAN3.EPF`, and `CLANBUT.EPF`; `AN*` labels are suffix labels. | High | UID00010C Item Summary repaired; UID00010C body, support docs, and generated route already carried the full `CLAN*` evidence. | UID00010C Item Summary/Evidence; `by-class/ClanStatusPane.md`; `by-file/Clan.md`; supervisor-owned coverage row | incorporate | applied |
| C-00010C-G-05 | `0x00484a60`, `0x00484cd0`, and `0x00484db0` are the frame/key/mouse virtual band under [UID:00010C]. | High | Covered ranges and evidence verified in UID00010C; validator `000000007205` passed. | UID00010C Covered Ranges and Evidence | already-present | already-present |
| C-00010C-G-06 | `0x00486800`, `0x00486d20`, and `0x00486f90` should be named `DrawStatusRowText`, `GetStatusRowRect`, and `HitTestStatusRow`. | High | UID00010G covered ranges and class Method Notes verified; validator `000000007206` passed. | UID00010G Covered Ranges; `by-class/ClanStatusPane.md` Method Notes | already-present | already-present |
| C-00010C-G-07 | Field names `m_currentClanStatusView`, `m_statusDataVersion`, and `m_selectedStatusRow` are the best current source-quality names for `+0xf8/+0xf9/+0xfa`. | High | UID00010C summary/body, UID00010G row-role prose, and class evidence notes verified. | UID00010C notes; UID00010G row-role prose; `by-class/ClanStatusPane.md` evidence notes | already-present | already-present |
| C-00010C-G-08 | Key/mouse event offsets and secondary receiver adjustment are documented enough for prose but not exact C++ signatures. | Medium-high | UID00010C Evidence and no-code rationale verified after validator `000000007205`. | UID00010C Evidence and First-Draft C++ Recommendation | already-present | already-present |
| C-00010C-G-09 | Row indices `2-13` map to opcode `0x4b` subtypes `1-12`, row `7` delegates through `0x00485960`, and rows `14/15` are view-tab rectangles. | High | UID00010G Row Role Inference and UID00010C row-action notes verified. | UID00010G Row Role Inference; UID00010C row-action notes | already-present | already-present |
| C-00010C-G-10 | `GetStatusRowRect` should use the existing UI rectangle type; a new `ClanStatusRowRect` type is not supported. | Medium-high | UID00010G rectangle note verified. | UID00010G rectangle note | already-present | already-present |
| C-00010C-G-11 | Adjacent [UID:00021N]-[UID:00021R] support field/view semantics but do not force a split or C++ body for UID00010C/UID00010G. | High | UID00010C/UID00010G relationship notes and class support notes verified. | UID00010C/UID00010G relationship notes; Open Questions | already-present | already-present |
| C-00010C-G-12 | Source placement remains `NexusTK/social/Clan.cpp`; reject `ClanDialogs.cpp`, `ClanBank.cpp`, and protocol-only ownership for these UI bands. | High | Class/file docs and generated `Clan.cpp` route verified. | Source Placement; `by-file/Clan.md` contents row | already-present | already-present |
| C-00010C-G-13 | `ClanStatusPane` support text is already present at same-or-greater detail and needs no score change from this report. | High | `by-class/ClanStatusPane.md` already has full `CLAN*` resources, method rows, field names, and rejected alternatives; no support edit made. | `by-class/ClanStatusPane.md` | already-present | already-present |
| C-00010C-G-14 | `Clan` support text is already present at same-or-greater detail and needs no score change from this report. | High | `by-file/Clan.md` already has full resource list and suffix-label caveat; no support edit made. | `by-file/Clan.md` | already-present | already-present |
| C-00010C-G-15 | Current coverage rows for UID00010C/UID00010G are stale but supervisor-owned. | High | Callback explicitly forbade editing `by-memory/-coverage-report.md`; exact proposed coverage rows remain in report only. | `by-memory/-coverage-report.md` rows for UID00010C and UID00010G | not-applicable | excluded-with-reason |
| C-00010C-G-16 | `by-memory/-ignored.md` already covers padding and switch data around these ranges; no ignored-doc edit is recommended. | High | Existing ignored rows remain outside callback scope and already sufficient. | `by-memory/-ignored.md` | already-present | already-present |
| C-00010C-G-17 | Generated `Clan.cpp` freshness currently matches target scores and non-source aggregate markers. | High | `auto-generated/NexusTK/social/Clan.cpp` refreshed to `validator-command-id: 000000007206`, `validator-refreshed-at: 2026-07-05T16:06:49-04:00`; both UIDs emit non-source aggregate markers at `86/90`. | `auto-generated/NexusTK/social/Clan.cpp` observation only | already-present | applied |
| C-00010C-G-18 | Old `82/88`, `AN*` source-name, `DrawInfoRow`, new row-rect type, and final C++ source-body claims are stale or invalid. | High | UID00010C stale summary wording replaced; UID00010G/support docs already reject stale names and keep no-code aggregate disposition. | Negative Evidence Summary; Recommended Target Doc Changes; First-Draft C++ Recommendation | reject-stale | applied |
| C-00010C-G-19 | Future implementation, if authorized, should use scoped file validators with `--queue-timeout 240` and should not run lifecycle/archive commands. | High | Callback validators `000000007205` and `000000007206` ran; no `execute_report`, lifecycle, report move, manual archive, coverage, or validator-state edit was performed by B002. | Validator Results and Implementation Tracking Checklist | incorporate | applied |

## Positive Evidence Summary

- Current target metadata already matches the accepted `86/90` score and [UID:00002K] owner/emitter route for both primary targets.
- [UID:00010C] has exact frame/key/mouse virtual anchors, vtable xrefs, function boundaries, state fields, event field offsets, row hit-testing, child refresh linkage, and row-action packet dispatch evidence.
- [UID:00010G] has exact row text, rectangle, and hit-test helper boundaries, callers, storage offsets, row/view gates, fixed coordinates, common rectangle behavior, and switch-table boundary evidence.
- [UID:0003B8] resolves the status resources to the full `CLAN*` names and explains the stale `AN*` labels.
- Current class/file support docs and generated `Clan.cpp` agree on `ClanStatusPane` under `NexusTK/social/Clan.cpp`.

## Negative Evidence Summary

- No original symbols recover the exact event class names, key/mouse enum names, row enum labels, user-facing row labels, or common rectangle type name.
- [UID:00010C] and [UID:00010G] are aggregate ranges spanning multiple source methods/helpers, so they should not emit decompiler-shaped C++ bodies.
- `ClanStatusRowRect`, `DrawInfoRow`, `m_currentTab`, `permissionFlags`, `selectedFieldIndex`, `ClanDialogs.cpp`, `ClanBank.cpp`, and protocol-only ownership remain rejected for these targets.
- Supervisor-owned coverage rows are stale, but the accepted B002 repair/callback scope excludes coverage reports and lifecycle-owned state.

## Ranked Ownership Analysis

1. [UID:00002K] `ClanStatusPane`: direct owner/emitter. The targets use ClanStatusPane vtable entries, ClanStatusPane fields, child pane fields, row-action packet context, and status-pane resource/state behavior.
2. [UID:0000I8] `Clan`: source-file route only. The generated route and file support page place the class and helpers in `NexusTK/social/Clan.cpp`.
3. `ClanDialogs.cpp` / [UID:0000IA] `ClanDialogs`: rejected. These targets are visible status-pane frame/input/row helpers, not modal dialog bodies.
4. `ClanBank.cpp` / [UID:0000I9] `ClanBank`: rejected. The row actions may open bank-related flows, but the frame/input and row geometry code remain status-pane UI.
5. Protocol-only helper ownership: rejected. Packet helper evidence supports row action semantics but does not own the UI drawing/input bands.

## Source Placement

Keep source placement through [UID:0000I8] `Clan` and generated path `NexusTK/social/Clan.cpp`. Current generated output confirms:

```text
// validator-command-id: 000000007143
// validator-refreshed-at: 2026-07-05T15:10:39-04:00
// UID:00010C | by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md | Completion:86 | Confidence:90
// UID:00010G | by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md | Completion:86 | Confidence:90
```

Both entries remain aggregate marker comments, not source method bodies.

## Function / Child Inventory

No child UID creation or split implementation is recommended by this report. The current targets remain aggregate documentation pages.

| UID | Range | Best source-facing role | Current disposition |
| --- | --- | --- | --- |
| 00010C | `0x00484a60-0x00484cb0` | `ClanStatusPane::OnPaintFrame` | Documented inside aggregate; no source body on parent. |
| 00010C | `0x00484cd0-0x00484da2` | `ClanStatusPane::OnKeyInput` | Documented inside aggregate; no source body on parent. |
| 00010C | `0x00484db0-0x00484f16` | `ClanStatusPane::OnMouseEvent` | Documented inside aggregate; no source body on parent. |
| 00010G | `0x00486800-0x00486cde` | `ClanStatusPane::DrawStatusRowText` | Documented inside aggregate; no source body on parent. |
| 00010G | `0x00486d20-0x00486f3f` | `ClanStatusPane::GetStatusRowRect` | Documented inside aggregate; no source body on parent. |
| 00010G | `0x00486f90-0x00487291` | `ClanStatusPane::HitTestStatusRow` | Documented inside aggregate; no source body on parent. |

## Range / Split / Padding / Reclassification Analysis

No range split is recommended in this report artifact. The primary targets are coherent documentation aggregates, and padding/switch data around them are already represented in [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md).

Existing ignored coverage already includes:
- `0x00484a51-0x00484a60` parser/frame alignment.
- `0x00484f17-0x00484f18`, `0x00484f18-0x00484f6a`, and `0x00484f6a-0x00484f70` mouse-event tail padding/switch support.
- `0x004867f2-0x00486800` helper-to-row alignment.
- `0x00487292-0x00487294`, `0x00487294-0x004872d8`, and `0x004872d8-0x004872e0` row-hit-test switch/alignment.
- `0x00487336-0x00487338`, `0x00487338-0x00487370`, and child-view helper alignment rows through `0x00487600`.
- `0x004877a0-0x004877d0` row-action packet switch table.

## Recommended Target Doc Changes

For [UID:00010C], callback-applied state:
- Preserve current metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00002K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002K`, blank optional emitter position, and `Nested:0`.
- Preserve the non-source aggregate marker in the formal C++ block. Do not add source C++.
- Metadata Item Summary was corrected to remove stale `AN*.EPF` / `ANBUT.EPF` source-name wording. Current applied text:

```text
IDA-verified `ClanStatusPane` frame/key/mouse virtuals with vtable anchors, full `CLAN1.EPF`/`CLAN2.EPF`/`CLAN3.EPF`/`CLANBUT.EPF` resource selection, inferred `m_currentClanStatusView`/`m_statusDataVersion`/`m_selectedStatusRow` state, event field offsets, row hit-testing, child-pane refresh, row-action packet dispatch, and switch-data boundaries documented.
```

- Preserve the already-present body evidence for resource names, `m_currentClanStatusView`, `m_statusDataVersion`, `m_selectedStatusRow`, child-pane fields, event offsets, row-action dispatch, and `86/90` score rationale.

For [UID:00010G], callback-verified state:
- Preserve current metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00002K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002K`, blank optional emitter position, and `Nested:0`.
- Preserve the non-source aggregate marker in the formal C++ block. Do not add source C++.
- Preserve the already-present helper names `DrawStatusRowText`, `GetStatusRowRect`, and `HitTestStatusRow`; row role table; common UI rectangle note; and `86/90` score rationale.

## Recommended Support Doc Changes

No support-doc edit was made during this callback. Current [UID:00002K] `ClanStatusPane` and [UID:0000I8] `Clan` already contain the accepted support sync at same-or-greater detail:
- Full `CLAN1.EPF`/`CLAN2.EPF`/`CLAN3.EPF`/`CLANBUT.EPF` resource names.
- `AN*`, `LAN*`, and `ANBAN*` labels treated as IDA suffix labels.
- Method rows for `OnPaintFrame`, `OnKeyInput`, `OnMouseEvent`, `DrawStatusRowText`, `GetStatusRowRect`, and `HitTestStatusRow`.
- Field names for `m_currentClanStatusView`, `m_statusDataVersion`, `m_selectedStatusRow`, and child pane pointers.

Support scores did not change from this report. Current observed support metadata is `ClanStatusPane` `87/89` and `Clan` `90/85`.

## Supervisor-Owned Coverage Rows

The current `by-memory/-coverage-report.md` rows are stale and supervisor-owned. B002 did not edit them in the repair or callback. If a supervisor-owned coverage refresh is authorized later, use this exact direction:

```text
    - [UID:00010C][0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput](by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md) : reconstructable : 86% : strong : IDA-verified `ClanStatusPane` frame/key/mouse virtuals with vtable anchors, full `CLAN1.EPF`/`CLAN2.EPF`/`CLAN3.EPF`/`CLANBUT.EPF` resource selection, inferred `m_currentClanStatusView`/`m_statusDataVersion`/`m_selectedStatusRow` state, event field offsets, row hit-testing, child-pane refresh, row-action packet dispatch, and switch-data boundaries documented.
```

```text
    - [UID:00010G][0x00486800-0x00487291.ClanStatusPaneRows](by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md) : reconstructable : 86% : strong : IDA-verified `ClanStatusPane` row text drawing, row-rectangle, and hit-test helpers with exact callers, packet-populated text-storage offsets, inferred row/view-action semantics, common UI rectangle output, fixed row/tab coordinates, status-data version gates, and switch-table boundary documented.
```

Optional adjacent shared-report sync noticed by the original audit: [UID:00021N], [UID:00021P], [UID:00021Q], and [UID:00021R] rows in `by-memory/-coverage-report.md` may also be stale relative to their current by-memory pages. They are not primary targets for this report and require separate supervisor scope.

## Final Recommendation

The accepted callback implementation is complete for B002 scope. The old score raise had already landed in current target metadata and generated output; this callback repaired the remaining stale [UID:00010C] metadata Item Summary `AN*` wording, verified [UID:00010G] and support docs as already present, ran the scoped target validators, and left supervisor-owned coverage rows untouched.

## Score And Metadata Recommendation

- [UID:00010C]: keep `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00002K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002K`, blank optional emitter position, and `Nested:0`.
- [UID:00010G]: keep `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00002K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002K`, blank optional emitter position, and `Nested:0`.
- Support docs: no score changes recommended; current observed metadata is `ClanStatusPane` `87/89` and `Clan` `90/85`.

The `86/90` score remains appropriate because exact virtual functions, helper boundaries, vtable anchors, callers/callees, row storage, view/version/selection fields, resource names, event offsets, row semantics, and generated route are documented. Scores should not be `95+` because original symbols, exact event types/enums, common rectangle type, row labels, row enum spelling, and method-level source splits are not recovered.

## Open Questions With Attempted Resolution

- Exact event class and enum names remain unresolved. Resolution for this report: document observed offsets and kind values in prose; do not emit C++ signatures.
- Exact common rectangle type name remains unresolved. Resolution: document the common `0x004b7c50` rectangle initializer and reject a new row-specific type.
- Exact user-facing row labels and row enum names remain unresolved. Resolution: document opcode subtype/action relationships and avoid invented labels.
- Exact source split into six method-level child pages is not authorized by this report. Resolution: retain aggregate pages as non-source emitters and do not create child UIDs.
- Coverage rows are stale but supervisor-owned. Resolution: provide exact proposed row text and mark the action not applicable to the B002 repair/callback scope.

## First-Draft C++ Recommendation

Do not add final C++ for [UID:00010C] or [UID:00010G]. Both targets satisfy the minimum score/emitter gate, but source-quality blockers remain:
- exact event base type and key/mouse enum names,
- exact common UI rectangle type name,
- final child-pane virtual slot names for refresh/show helpers,
- final source-facing packet helper and row enum names,
- original user-facing row labels and whether the source used arrays or named fixed fields for the row text slots,
- method-level split/child allocation not authorized by this report.

The current aggregate marker comments are the correct formal C++ disposition for this report.

## Validator Results

Pre-callback report lifecycle history:
- `000000004167` marked the report for revalidation at `2026-07-01T19:52:03-04:00` for `target_header_missing`.
- `000000007182` returned the report to active B002 research at `2026-07-05T15:40:39-04:00`.
- `000000007200` cleared the active returned report revalidation marker at `2026-07-05T16:00:49-04:00` after de-execution repair.

Implementation callback validators run by B002 from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00010C-00010G-clan-status-pane-ui-source-quality-removed.md](00010C-00010G-clan-status-pane-ui-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: command id `000000007205`, timestamp `2026-07-05T16:06:42-04:00`, exit code `0`, `ok: 1`. Diagnostics: `missing_ref_uid 0003B8` reported three times for UID00010C references not present in `validator.ini`; `projected_stats_update: 1`; `stats_incremental_noop: 1`; generated refresh initially deferred with generated command id `000000007205`.

> Executable block R002 was removed from this report and preserved verbatim in [00010C-00010G-clan-status-pane-ui-source-quality-removed.md](00010C-00010G-clan-status-pane-ui-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: command id `000000007206`, timestamp `2026-07-05T16:06:49-04:00`, exit code `0`, `ok: 1`. Diagnostics: `projected_stats_update: 1`; `stats_incremental_noop: 1`; generated refresh initially deferred with generated command id `000000007206`.

Support validators were not run because support docs were not edited and were verified already present at same-or-greater detail.

Generated freshness: `auto-generated/NexusTK/social/Clan.cpp` now has `validator-command-id: 000000007206`, `validator-refreshed-at: 2026-07-05T16:06:49-04:00`, and `validator-refresh-source: deferred-generated-refresh`. UID00010C and UID00010G still emit as non-source aggregate markers at `Completion:86 | Confidence:90`.

No `execute_report`, dry-run/probing execute variant, registry lifecycle command, report move, manual archive move, coverage edit, validator-state edit, or manual generated edit was run/performed by B002.

## Changed Files

Manual callback edits by B002:
- `by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md`: repaired the metadata Item Summary to full `CLAN1.EPF`/`CLAN2.EPF`/`CLAN3.EPF`/`CLANBUT.EPF` wording with state/event detail.
- `tools/leaser/Agents/Agent-B002/research/00010C-00010G-clan-status-pane-ui-source-quality.md`: updated ledger, validator results, changed files, checklist, lease status, and generated freshness.

Validator side effects observed after scoped validators:
- `auto-generated/NexusTK/social/Clan.cpp`: refreshed by validator to command id `000000007206`.
- `project-level/-auto-completion-stats.md`: validator output reported projected path completion section update.

Verified but not manually edited by B002 in this callback:
- `by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md`
- `by-class/ClanStatusPane.md`
- `by-file/Clan.md`

No generated file, coverage report, `by-memory/-coverage-report.md`, validator state, lifecycle/archive file, supervisor ledger, or IDA DB was manually edited by B002.

## Implementation Tracking Checklist

- [x] Lease only `by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md` immediately before editing and release immediately after the edit/validator/generated-freshness batch. Proof: `python leaser.py B002 lease ...ClanStatusPaneFrameAndInput.md` returned `Success`; `python leaser.py B002 unlease ...ClanStatusPaneFrameAndInput.md` returned `Success`; shared `current_leases.md` showed no active leases after release.
- [x] [UID:00010C] target metadata: verify/preserve `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00002K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002K`, blank optional emitter position, and `Nested:0`. Proof: target header verified after edit; validator `000000007205` returned exit `0`, `ok: 1`.
- [x] [UID:00010C] target C++: preserve the current non-source aggregate marker comment; do not add source C++. Proof: formal block still contains only the aggregate split marker.
- [x] [UID:00010C] target prose: replace stale Item Summary `AN*.EPF` / `ANBUT.EPF` wording with full `CLAN1.EPF`/`CLAN2.EPF`/`CLAN3.EPF`/`CLANBUT.EPF` wording; preserve already-present evidence for fields, events, row helpers, packet dispatch, and score rationale. Proof: metadata Item Summary now names full `CLAN*` resources and state/event detail.
- [x] [UID:00010C] validator: `python .\tools\validator.py --mode file --file by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md --apply --queue-timeout 240`. Proof: command id `000000007205`, timestamp `2026-07-05T16:06:42-04:00`, exit `0`, `ok: 1`.
- [x] [UID:00010G] target metadata/prose/C++: verify current already-present state; do not edit unless a callback explicitly authorizes drift repair. Proof: header/C++/helper rows verified already present; validator `000000007206` returned exit `0`, `ok: 1`.
- [x] [UID:00010G] validator: `python .\tools\validator.py --mode file --file by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md --apply --queue-timeout 240`. Proof: command id `000000007206`, timestamp `2026-07-05T16:06:49-04:00`, exit `0`, `ok: 1`.
- [x] Support docs: verify [UID:00002K] `ClanStatusPane` and [UID:0000I8] `Clan` already contain accepted facts at same-or-greater detail with no score changes. Proof: class/file docs already contain full `CLAN*` resource names, suffix-label caveats, method rows, field names, source placement, and rejected alternatives; no support edits made.
- [x] Support validators: not applicable because no support docs were edited.
- [x] Coverage rows: do not edit `by-memory/-coverage-report.md` as B002. Proof: callback kept coverage rows supervisor-owned; no coverage edit made.
- [x] Ignored ranges: do not edit `by-memory/-ignored.md`; current ignored rows already cover padding/switch data around these targets. Proof: no ignored-doc edit made.
- [x] Generated freshness check: inspect `auto-generated/NexusTK/social/Clan.cpp` without manual generated edits and confirm UID00010C/UID00010G still emit as non-source aggregate markers at the target scores. Proof: header has command id `000000007206`, refreshed `2026-07-05T16:06:49-04:00`, and both UIDs remain `Completion:86 | Confidence:90` aggregate markers.
- [x] Report callback update: update ledger verification states from `proposed` to `applied`, `already-present`, or `excluded-with-reason`; record changed files, validator command IDs/timestamps/exit/ok counts, generated freshness, and lease release confirmation. Proof: this section and ledger updated.
- [x] Do not run `execute_report`, dry-run/probing execute variants, registry lifecycle commands, report moves, archive/manual moves, broad rescore, generated manual edits, coverage manual edits, or validator-state manual edits. Proof: only scoped file validators and leaser lease/unlease were run by B002.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_header_missing","source_path":"executed-b-agent-research/B002/00010C-00010G-clan-status-pane-ui-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- {"agent":"B002","command_id":"000000007182","destination_path":"tools/leaser/Agents/Agent-B002/research/00010C-00010G-clan-status-pane-ui-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B002/00010C-00010G-clan-status-pane-ui-source-quality.md","timestamp":"2026-07-05T15:40:39-04:00"} -->
<!-- {"agent":"B002","command_id":"000000007200","details":"active returned report revalidation marker cleared after de-execution repair","event":"active-revalidation-cleared","source_path":"tools/leaser/Agents/Agent-B002/research/00010C-00010G-clan-status-pane-ui-source-quality.md","timestamp":"2026-07-05T16:00:49-04:00","uid":"00010C"} -->
<!-- {"agent":"B002","command_id":"000000007227","destination_path":"executed-b-agent-research/B002/00010C-00010G-clan-status-pane-ui-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00010C-00010G-clan-status-pane-ui-source-quality.md","timestamp":"2026-07-05T16:24:06-04:00","uid":"00010C"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00010C-00010G-clan-status-pane-ui-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00010C-00010G-clan-status-pane-ui-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00010C"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
