** TARGET-REPORT-UID:00025V **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID00025V MessageShowReadOnlyData Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00025V][0x0061fa3c-0x0061fafc.MessageShowReadOnlyData](../../../../../by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md) as a non-emitting mixed `.rdata` parent/index, and refresh its body to the current child-owner state and current MCP evidence.
- Final disposition: no new split is needed. The exact children [UID:0003PB]-[UID:0003PF] already exist and carry the rebuild routes. The parent needs stale body cleanup, score refresh, and stale manual/generated tracker closure.
- Required action: report-approved callback should edit only target/support by-* docs, run scoped validators, and leave generated files, coverage reports, validator state, IDA DB, and executed reports untouched except through supervisor-owned validation/refresh.
- Confidence: strong. Current IDA MCP session `992d23de` is healthy and reconfirms the byte/name/xref boundaries.

## Target

- Target UID: `00025V`
- Target path: `by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md`
- Assignment source: `Agent-B001/goal.md`, assignment id `B001-report-00025V-MessageShowReadOnlyData-source-quality-20260629`
- Queue row checked: `auto-generated/-ag-research-tracker.md:1596` still lists this UID as `80/86`, average `83.0`, reconstructable `true`, report count `0`. That queue row is stale versus the current target header.
- Current target metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.

## Current Target State

The target is already a mixed `.rdata` index over five exact child ranges:

| Range | Current child | Current owner route | Current status |
| --- | --- | --- | --- |
| `0x0061fa3c-0x0061fa4c` | [UID:0003PB][MessageVtableData](../../../../../by-memory/0x0061fa3c-0x0061fa4c.MessageVtableData.md) | [UID:000084][Message](../../../../../by-class/Message.md) -> [UID:0000LA][MessageDialogs](../../../../../by-file/MessageDialogs.md) | Already correct. |
| `0x0061fa4c-0x0061fadc` | [UID:0003PC][MessageShowPaneVtableData](../../../../../by-memory/0x0061fa4c-0x0061fadc.MessageShowPaneVtableData.md) | [UID:000087][MessageShowPane](../../../../../by-class/MessageShowPane.md) -> [UID:0000LB][MessageShowPane](../../../../../by-file/MessageShowPane.md) | Already correct. |
| `0x0061fadc-0x0061faf0` | [UID:0003PD][MetaDatFilenameString](../../../../../by-memory/0x0061fadc-0x0061faf0.MetaDatFilenameString.md) | [UID:0000LC][MetaMan](../../../../../by-file/MetaMan.md) | Already correct. |
| `0x0061faf0-0x0061faf8` | [UID:0003PE][MetaTableVtableData](../../../../../by-memory/0x0061faf0-0x0061faf8.MetaTableVtableData.md) | [UID:000089][MetaTable](../../../../../by-class/MetaTable.md) -> [UID:0000LC][MetaMan](../../../../../by-file/MetaMan.md) | Already correct. |
| `0x0061faf8-0x0061fafc` | [UID:0003PF][MidiPlayerRttiLocatorPointer](../../../../../by-memory/0x0061faf8-0x0061fafc.MidiPlayerRttiLocatorPointer.md) | [UID:00008A][MidiPlayer](../../../../../by-class/MidiPlayer.md) -> [UID:0000LD][MidiPlayer](../../../../../by-file/MidiPlayer.md) | Child is correct; parent still has stale ownerless/gate wording. |

Open/stale target issues:

- Target body still says the `MidiPlayer` locator pointer child is ownerless and below the strict owner gate. That is stale. [UID:0003PF] is now `86/91`, `CANONICAL_OWNER:00008A`, `EMITTER_UIDS:00008A`.
- Target `Live IDA Evidence` cites old MCP session `a003_objectlist_dispatch_20260615` only. Current report requires adding the 2026-06-29 MCP session proof.
- Target score rationale should be updated from `86/90` to `87/91` after the current MCP spot-check and closed MidiPlayer owner gate. The parent stays below final because it is an inventory page, not a source object.
- Target formal C++ must remain blank.

## Evidence Checked

Old-report/source-family search:

- Searched `source-3/project-documentation/tools/leaser/Agents` with `00025V`, `0x0061fa3c`, `0x0061fafc`, `MessageShowReadOnlyData`, `MessageShowPaneVtableData`, `MetaDatFilenameString`, `MidiPlayerRttiLocatorPointer`, and `aAt_2`.
- No prior B-agent report for UID00025V was found.
- Matching historical implementation context was found in `Agent-C001/notes.md` and supervisor notes: C001 created [UID:0003PB]-[UID:0003PF] under the mixed parent on 2026-06-15, and a later C001 MidiPlayer slice raised [UID:0003PF] to owner/emitter route through [UID:00008A].

Current docs checked:

- Target page [UID:00025V].
- Exact children [UID:0003PB], [UID:0003PC], [UID:0003PD], [UID:0003PE], [UID:0003PF].
- Support pages [UID:0000LA][MessageDialogs], [UID:0000LB][MessageShowPane], [UID:000084][Message], [UID:000087][MessageShowPane], [UID:0000LC][MetaMan], [UID:000089][MetaTable], and [UID:00008A][MidiPlayer].
- Generated/tracker read-only checks: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `by-memory/-coverage-report.md`, and generated `auto-generated/NexusTK` C++/headers search.

Current MCP facts:

- MCP transport: JSON-RPC at `http://127.0.0.1:13337/mcp`.
- `idb_list`: one active worker session `992d23de`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, worker PID `12076`.
- `server_health` on `992d23de`: status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.
- Current listener/process state was not a blocker; no MCP pause condition occurred.

## IDA MCP Facts

Names and boundaries:

- `entity_query names 0x0061fa30-0x0061fb10` returns `??_7Message@@6B@` at `0x0061fa3c`, `??_7MessageShowPane@@6B@` at `0x0061fa4c`, secondary/tertiary `MessageShowPane` names at `0x0061fa98` and `0x0061fac8`, tail label `aAt_2` at `0x0061fae8`, successor `??_7MidiPlayer@@6B@` at `0x0061fafc`, and `aItForBufferRet` at `0x0061fb0c`.
- `entity_query names 0x0064c2e0-0x0064c360` returns `??_R4MetaTable@@6B@` at `0x0064c2fc` and `??_R4MidiPlayer@@6B@` at `0x0064c344`.

Bytes:

- `get_bytes 0x0061fa30 size 224` shows prior UTF-16 tail bytes before `0x0061fa3c`, then the Message vtable, MessageShowPane vtable island, full UTF-16 `Meta.dat` at `0x0061fadc-0x0061faec`, MetaTable cells `0x0061faf0 -> 0x0064c2fc` and `0x0061faf4 -> 0x00525780`, MidiPlayer RTTI locator cell `0x0061faf8 -> 0x0064c344`, successor MidiPlayer vtable at `0x0061fafc`, and successor UTF-16 `Wait...` bytes after `0x0061fb0c`.
- `get_string` reads partial IDA strings at `0x0061fadc` as `M`, `0x0061fae8` as `at`, and `0x0061fb0c` as `it For Buffer Return`; this confirms IDA's string labels are split/tail artifacts, while raw bytes prove the full `Meta.dat` and successor MidiPlayer diagnostic context.

Xrefs:

- `xrefs_to 0x0061fa3c`: `0x00520e6a`, `0x00520ed6`, `0x00521d49`, in functions `0x00520e30`, `0x00520ed0`, and `0x00521d40`.
- `xrefs_to 0x0061fa4c`: `0x00521e1d`, `0x00521fe5`, `0x0052274c`.
- `xrefs_to 0x0061fa98`: `0x00521e23`, `0x00521feb`, `0x00522752`.
- `xrefs_to 0x0061fac8`: `0x00521e2d`, `0x00521ff5`, `0x0052275c`.
- `xrefs_to 0x0061fadc`: `0x005234ae` in `0x00523470` and `0x005237fa` in `0x005237d0`.
- `xrefs_to 0x0061faf0`: none; the vtable cell is used through the following vtable pointer at `0x0061faf4`.
- `xrefs_to 0x0061faf4`: `0x00524643`, `0x005246b9`, `0x005257aa`.
- `xrefs_to 0x0061faf8`: none, as expected for a pointer cell.
- `xrefs_to 0x0064c344`: one data xref from `0x0061faf8`, proving the MidiPlayer RTTI locator target.
- `xrefs_to 0x0061fafc`: `0x00525e10`, `0x00525ed5`, `0x005265a5`.

Function lookup:

- Current `lookup_funcs` maps the Message refs to `0x00520e30` size `0x9b`, `0x00520ed0` size `0x25`, and `0x00521d40` size `0x54`.
- MessageShowPane refs map to constructor `0x00521da0` size `0x220`, ordinary destructor `0x00521fc0` size `0x65`, and scalar wrapper `0x00522720` size `0xa6`.
- MetaMan refs map to `0x00523470` size `0x350` and `0x005237d0` size `0x22b`.
- MetaTable refs map to `0x00524630` size `0x5c`, `0x00524690` size `0x97`, and `0x00525780` size `0xae`.
- MidiPlayer refs map to `0x00525dc0` size `0xe6`, `0x00525eb0` size `0x8d`, and `0x00526580` size `0xcb`.

## Heuristic / Inference Reanalysis And Validation

- The parent name `MessageShowReadOnlyData` is now a historical aggregate label, not a single owner. Direct MCP evidence spans Message, MessageShowPane, MetaMan, MetaTable, and MidiPlayer.
- IDA's `aAt_2` label is a string-tail artifact. Raw UTF-16 bytes prove the child should remain full `Meta.dat` at `0x0061fadc-0x0061faf0`, routed through MetaMan.
- The absence of `xrefs_to 0x0061faf8` does not weaken the MidiPlayer child; the positive xref is to the pointed-to RTTI locator `0x0064c344` from cell `0x0061faf8`.
- The generated tracker row is stale. Current target metadata and `auto-generated/-ag-memory-coverage.md` already classify UID00025V as non-reconstructable/ownerless, while `auto-generated/-ag-research-tracker.md` still lists the old reconstructable row.
- Existing generated/Wave2/Wave3/simroot wording in support pages is lead/history material only. Any support callback must either rewrite it as generated lead material, historicalize it, reject stale ownership implications, or explicitly retain already caveated historical text.

## Ranked Ownership Analysis

### 1. Mixed parent/index with exact children

- Evidence for: current bytes and names cross five owner families; target already has exact children for each subrange; current MCP confirms all boundaries.
- Evidence against: none for the parent/index role.
- Decision: keep UID00025V ownerless, non-reconstructable, emitterless, and blank C++.

### 2. MessageShowPane single owner

- Evidence for: the largest subrange is MessageShowPane vtable data at `0x0061fa4c-0x0061fadc`.
- Evidence against: Message vtable precedes it, `Meta.dat` is used by MetaMan, MetaTable cells follow, and MidiPlayer RTTI/vtable boundary starts at the successor.
- Decision: reject as stale aggregate ownership. MessageShowPane owns only [UID:0003PC].

### 3. MessageDialogs / Message owner

- Evidence for: [UID:0003PB] is the `Message` vtable and routes through [UID:000084].
- Evidence against: only `0x0061fa3c-0x0061fa4c` belongs to Message; the rest is not MessageDialogs source data.
- Decision: reject for parent ownership; retain for child [UID:0003PB].

### 4. MetaMan/MetaTable or MidiPlayer parent owner

- Evidence for: exact child evidence for `Meta.dat`, MetaTable, and MidiPlayer.
- Evidence against: these are narrow tail subranges, not the whole parent.
- Decision: retain for their exact children only.

## Range / Split / Padding / Reclassification Analysis

- No child creation is required. The split-first repair is already present as [UID:0003PB]-[UID:0003PF].
- Parent half-open range `0x0061fa3c-0x0061fafc` remains correct. It ends immediately before successor `??_7MidiPlayer@@6B@` at `0x0061fafc`.
- Child boundaries remain implementation-ready:
  - `0x0061fa3c-0x0061fa4c`: Message vtable.
  - `0x0061fa4c-0x0061fadc`: MessageShowPane primary/secondary/tertiary vtables.
  - `0x0061fadc-0x0061faf0`: full UTF-16 `Meta.dat` string and alignment.
  - `0x0061faf0-0x0061faf8`: MetaTable RTTI/vtable cells.
  - `0x0061faf8-0x0061fafc`: MidiPlayer RTTI locator pointer.
- Parent body should be repaired to say every child now has a direct route; [UID:0003PF] is no longer ownerless.

## First-Draft C++ Recommendation

- Eligible for draft C++: no.
- Recommended target C++: keep the formal block blank:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact no-code proof: UID00025V is a mixed `.rdata` address inventory crossing five owners. Vtable and RTTI bytes regenerate from class declarations, and the `Meta.dat` literal belongs to MetaMan. Hand-authored parent C++ would duplicate child/source responsibilities and create a false single owner.

## Recommended Target Doc Changes

Target path: `by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md`

Required target edits:

- Change score to `COMPLETION:87`, `CONFIDENCE:91`.
- Leave `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++ unchanged.
- Refresh the summary/child table row for `0x0061faf8-0x0061fafc` to state [UID:0003PF] routes through [UID:00008A][MidiPlayer](../../../../../by-class/MidiPlayer.md), not ownerless.
- Add a 2026-06-29 current MCP evidence paragraph using session `992d23de`, `server_health: ok`, imagebase `0x400000`, Hex-Rays/string-cache ready, and the current name/byte/xref facts above.
- Historicalize the old session-only wording by retaining C001 as prior evidence but not as the only live evidence.
- Update score rationale to say confidence improved because current MCP reconfirms the split and because the MidiPlayer direct owner gate is now closed.
- Update `Item Summary` to remove stale MessageShowPane-owned/reconstructable wording and reflect mixed non-emitting parent status.

Suggested target `Item Summary` replacement:

```text
Mixed Message/MessageShowPane/MetaMan/MetaTable/MidiPlayer `.rdata` index; current MCP refresh reconfirms exact child boundaries for Message vtable, MessageShowPane vtables, `Meta.dat` literal, MetaTable vtable cells, and MidiPlayer RTTI locator pointer. Parent remains ownerless, non-reconstructable, emitterless, and blank C++ because exact children carry source-declared/generated-binary rebuild routes.
```

## Recommended Support Doc Changes

Support edits must be exact and source-quality oriented:

- `by-file/MessageShowPane.md`
  - Rewrite `Current generated sources: class_MessageShowPane.cpp... current simroot_v2 emits...` as generated lead/history material, not active source evidence. Exact action: historicalize/rewrite as `Generated lead material includes class_MessageShowPane.cpp; older generated/cache material attached 0x00522530 elsewhere, but current IDA xrefs and by-memory pages are the authority for MessageShowPane routing.`
  - Rewrite the boundary note saying `current simroot_v2 emits it as MessageShowPane::SetWrappedText` to `generated lead material places it under MessageShowPane; IDA xrefs prove the one packet-handler caller and MessageShowPane-specific layout.`
  - Rewrite `g_applyMessagePaneBorder is Wave3-owned...` to reject stale generated ownership: `Wave3/generated attribution alone is rejected; IDA xrefs make it a broad UI callback/table and not a MessageShowPane-owned global.`
  - Leave the migration command block as historical provenance, but add/keep explicit wording that it must not be run and is not evidence.

- `by-class/MessageShowPane.md`
  - Keep the already-caveated `Generated recovered file lead... not authoritative` line, but update `Current simroot_v2 now emits it under MessageShowPane` to `generated lead material emits it under MessageShowPane; IDA caller/xref evidence is the authority.`
  - Leave the `Generated Wave3/simroot output has historically...` line because it is already historical/rejected, but ensure callback does not promote it to evidence.

- `by-file/MessageDialogs.md`
  - Rewrite `Current generated sources:` as `Generated lead material:` and do not present generated class files as active source-file proof.
  - Rewrite `Evidence basis: Wave3 class inspection, simroot_v2 generated source, older Wave2...` so IDA MCP/current by-* docs are authority and Wave2/Wave3/simroot are historical leads only. Exact action: historicalize Wave2/Wave3 evidence wording.
  - Rewrite `omitted from current active simroot output`, `simroot_v2... emits only an omitted-body marker`, and `current simroot_v2 data/generation caveats` as generated-output caveats, not source proof.
  - Keep generated omission notes that are useful for final C++ blockers, but label them as generated-output limitations.

- `by-class/Message.md`
  - No required edit for line `Current recovered file lead... generated lead material, not final source placement proof`; it is already correctly caveated.
  - Leave historical `Wave3 grade` in the change log as provenance only. Explicit callback state: exclude from edits because it is in a historical change entry and not an active ownership claim.

- `by-file/MetaMan.md`
  - Rewrite `Current generated evidence: source-3/simroot_v2/metadata/MetaMan.cpp; current autogen route...` as `Generated lead material: ...; current autogen route...` and add that IDA/by-* docs, not generated output, are the source-quality authority.
  - Rewrite `simroot_v2 / autogen evidence now routes through metadata/MetaMan.cpp` as `generated lead/autogen route material supports metadata/MetaMan.cpp, but exact source claims stay with current IDA and child pages.`

- `by-class/MetaTable.md`
  - Rewrite `Current recovered file: source-3/simroot_v2/class_MetaTable.cpp` as `Generated recovered-file lead... not final placement proof`.
  - Historicalize `simroot_v2/class_MetaTable.meta_wave3 identifies MetaTable.cpp...` as generated/Wave3 lead material only; do not use it as active owner proof. The current direct owner remains [UID:0000LC][MetaMan](../../../../../by-file/MetaMan.md) from by-* and IDA evidence.

- `by-class/MidiPlayer.md`
  - No Wave2/Wave3/simroot/recovered-source wording was found in the checked page. No stale-source edit is required.
  - Do not edit old MCP session names here for this target unless the callback chooses to add a narrow current [UID:00025V]/[UID:0003PF] reference; the class already documents the closed MidiPlayer gate and current owner route at sufficient detail.

Support docs not to edit:

- Exact child pages [UID:0003PB]-[UID:0003PF] do not require body changes for this report. [UID:0003PF] already has the current owner route. The target parent is the stale page.

## Score And Metadata Recommendation

- Current target score/metadata: `86/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank C++.
- Recommended target score/metadata: `87/91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank C++.
- Reason to raise: current MCP reconfirms every split boundary, and the only previous child-owner gate called out by the parent is now closed by [UID:0003PF] and [UID:00008A].
- Reason not higher: the page is intentionally a non-source mixed index. Final source C++ and final literal/helper names belong to exact owner pages, not this parent.
- Metadata fields to leave unchanged: owner, reconstructable, emitters, optional emitter position, and formal C++.
- `Nested`: leave unchanged unless validator requires otherwise. The page uses an explicit child table rather than formal nested C++ emission.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | UID00025V is a mixed `.rdata` index, not a single MessageShowPane source object. | High | Current MCP names/bytes/xrefs cross Message, MessageShowPane, MetaMan, MetaTable, MidiPlayer. | Target summary/range/reconstruction notes | incorporate | applied - target summary, range, rebuild handling, and reconstruction notes now state mixed index/no-owner/no-emitter. |
| C002 | Exact child ranges [UID:0003PB]-[UID:0003PF] already exist and should not be recreated. | High | Current target child table and child pages. | Target child table / checklist | already-present | already-present - child table preserved; no child files created or renamed. |
| C003 | [UID:0003PF] now routes through [UID:00008A][MidiPlayer]; target ownerless wording is stale. | High | Child header `CANONICAL_OWNER:00008A`, MCP `0x0061faf8 -> 0x0064c344`, `??_R4MidiPlayer@@6B@`, `xrefs_to 0x0064c344` from `0x0061faf8`. | Target summary/table/score rationale | incorporate | applied - target child table, live evidence, reconstruction notes, and score rationale route [UID:0003PF] through [UID:00008A]. |
| C004 | Parent target should remain `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters. | High | Mixed owner range and exact child routing. | Target header/reconstruction notes | already-present | already-present - metadata retained unchanged except score. |
| C005 | Parent formal C++ should remain blank. | High | Mixed `.rdata` parent; vtables/RTTI/literal rebuild through children/source owners. | Target C++ block | already-present | already-present - formal C++ block remains blank and no-code proof is in target reconstruction notes. |
| C006 | Score should become `87/91`. | Medium-high | Current MCP spot-check plus closed MidiPlayer gate; parent remains non-source index. | Target header/score rationale | incorporate | applied - target header now `COMPLETION:87`, `CONFIDENCE:91`; validator command `000000000369` confirmed updates. |
| C007 | Old MCP session-only evidence on the target should be historicalized and supplemented with current session `992d23de`. | High | Current `idb_list` and `server_health` facts. | Target Live IDA Evidence | incorporate | applied - target Live IDA Evidence now keeps C001 as prior evidence and adds session `992d23de` health/name/byte/xref proof. |
| C008 | `aAt_2` is a tail label; full bytes prove `Meta.dat`. | High | Raw bytes and `get_string` partial tail behavior; xrefs to MetaMan load/save. | Target evidence; [UID:0003PD] already present | incorporate | applied - target Live IDA Evidence records partial string labels and raw-byte authority for full `Meta.dat`. |
| C009 | `by-file/MessageShowPane.md` active generated/simroot/Wave3 wording must be rewritten as generated lead/history or rejected stale generated ownership. | High | `rg` stale-source scan lines 14, 53, 56, 68. | `by-file/MessageShowPane.md` status/boundary/migration notes | historicalize | applied - status, boundary, generated attribution, and migration notes now label generated/Wave3 material as lead/history or rejected. |
| C010 | `by-class/MessageShowPane.md` should rewrite active `current simroot_v2` ownership wording but can retain already-caveated historical Wave3/simroot text. | High | `rg` stale-source scan lines 19, 40, 43. | `by-class/MessageShowPane.md` status/evidence notes | historicalize | applied - active simroot ownership wording now says generated lead material; already-historical Wave3/simroot line retained as history. |
| C011 | `by-file/MessageDialogs.md` generated/Wave2/Wave3/simroot evidence wording must be historicalized or rewritten as generated-output caveats. | High | `rg` stale-source scan lines 14, 15, 42, 71, 73, 98, 99. | `by-file/MessageDialogs.md` status/evidence/ownership notes | historicalize | applied - generated files are lead material, Wave2/Wave3/simroot are historical leads, and omissions are generated-output limitations. |
| C012 | `by-class/Message.md` active generated lead line is already caveated; historical Wave3 mention is a change-log entry and needs no edit. | Medium-high | `rg` stale-source scan lines 75, 215. | `by-class/Message.md` status/change log | not-applicable | excluded-with-reason - goal explicitly excluded editing `by-class/Message.md`; report found only already-caveated/historical text. |
| C013 | `by-file/MetaMan.md` generated evidence wording should be rewritten as generated lead/autogen route material, not authority. | High | `rg` stale-source scan lines 13, 84. | `by-file/MetaMan.md` status/data caveats | historicalize | applied - status and Data Caveats now label simroot/autogen as generated lead/autogen route material and put authority on IDA/current by-* docs. |
| C014 | `by-class/MetaTable.md` current recovered file and Wave3 meta wording should be historicalized as generated lead material. | High | `rg` stale-source scan lines 18, 78. | `by-class/MetaTable.md` status/evidence notes | historicalize | applied - status and Evidence Notes now label recovered file/meta_wave3 as generated or historical lead material, not owner proof. |
| C015 | `by-class/MidiPlayer.md` has no Wave2/Wave3/simroot/recovered-source cleanup needed for this target. | Medium-high | Targeted stale-source `rg` found no matches in the page. | `by-class/MidiPlayer.md` | not-applicable | excluded-with-reason - goal explicitly excluded editing `by-class/MidiPlayer.md`; no stale-source wording was found there for this target. |
| C016 | Active generated research tracker row is stale and supervisor-owned/generated; do not edit directly. | High | `auto-generated/-ag-research-tracker.md:1596` still listed `80/86`, reconstructable `true`, while target header was non-reconstructable. | Generated tracker note / supervisor refresh expectation | incorporate | applied by validator-generated refresh - read-only check now shows `auto-generated/-ag-research-tracker.md:3698` as `87/91`, average `89.0`, reconstructable `false`; no manual edit. |
| C017 | Manual `by-memory/-coverage-report.md` row is stale and should be refreshed by supervisor/validator, not edited directly by B-agent. | High | `by-memory/-coverage-report.md:3171` still says reconstructable `80%`; target header says `87/91` non-reconstructable after callback. | Exact supervisor-owned coverage text | incorporate | excluded-with-reason - manual coverage edits are forbidden by goal; row remains stale and supervisor-owned, with replacement text retained in this report. |
| C018 | No generated C++ file contains UID00025V or `MessageShowReadOnlyData`; generated C++ should remain unchanged. | High | Read-only `rg` over `auto-generated/NexusTK` returned no matches. | Generated output check section | already-present | already-present - post-callback read-only `rg` over `auto-generated/NexusTK` returned no matches. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Do not edit generated tracker files or manual coverage reports directly in the B-agent callback. If the supervisor chooses to refresh the stale by-memory coverage row manually, use this replacement for `by-memory/-coverage-report.md` row `3171`:

```markdown
    - [UID:00025V][0x0061fa3c-0x0061fafc.MessageShowReadOnlyData](by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md) 0x0061fa3c-0x0061fafc | mixed-rdata-index | MessageShowReadOnlyData : ignored/non-emitting : 87% : very-strong : Current B001 MCP refresh reconfirms this parent as a mixed Message/MessageShowPane/MetaMan/MetaTable/MidiPlayer `.rdata` index with exact child routes for Message vtable, MessageShowPane vtables, `Meta.dat` literal, MetaTable vtable cells, and MidiPlayer RTTI locator pointer; the parent remains ownerless, non-reconstructable, emitterless, and blank C++.
```

Generated tracker expectation:

- `auto-generated/-ag-research-tracker.md` row `1596` should disappear from `Not-Covered Files - Reconstructable` after generated tracker refresh because the target is `RECONSTRUCTABLE:FALSE`. Do not write an exact `-ag` replacement row in this report.
- `auto-generated/-ag-memory-coverage.md` already reports UID00025V as `not_reconstructable`/`NONE`; no generated C++ change is expected.

## Validator Results

Implementation callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--apply --queue-timeout 240`:

| File | Command ID | Timestamp | Exit | ok | Notes |
| --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md` | `000000000369` | `2026-06-29T02:56:16-04:00` | 0 | 1 | Confirmed completion `87`, confidence `91`, canonical owner `NONE`, and autogen registry `true -> false`; generated refresh deferred. Existing missing-ref-UID warnings for [UID:0003PB]/[UID:0003PD]/[UID:0003PE]/[UID:0003PF] remain validator registry state. |
| `by-file/MessageShowPane.md` | `000000000371` | `2026-06-29T02:56:26-04:00` | 0 | 1 | Existing missing-ref-UID warnings for [UID:0003UU]; generated refresh deferred. |
| `by-class/MessageShowPane.md` | `000000000373` | `2026-06-29T02:56:37-04:00` | 0 | 1 | Existing missing-ref-UID warnings for [UID:0003UU]; generated refresh deferred. |
| `by-file/MessageDialogs.md` | `000000000375` | `2026-06-29T02:56:46-04:00` | 0 | 1 | Existing missing-ref-UID warnings for multiple 0003* exact children; generated refresh deferred. |
| `by-file/MetaMan.md` | `000000000376` | `2026-06-29T02:56:56-04:00` | 0 | 1 | Existing `missing_ref_target 0001CB` registry warning for stale path `by-memory/0x00524630-0x005258f1.MetaTable.md`; visible doc links already point to `0x00524630-0x00525914`. Generated refresh deferred. |
| `by-class/MetaTable.md` | `000000000377` | `2026-06-29T02:56:58-04:00` | 0 | 1 | Existing `missing_ref_target 0001CB` registry warning for stale path `by-memory/0x00524630-0x005258f1.MetaTable.md`; visible doc links already point to `0x00524630-0x00525914`. Generated refresh deferred. |

Validator side effects reported by scoped commands:

- `projected_stats_update` occurred on each scoped validator.
- Target validator `000000000369` reported autogen registry updates and deferred generated refresh. B-agent did not manually edit validator/tool state, generated reports, generated C++ files, project-level generated files, or manual coverage reports.
- `auto-generated/-ag-research-tracker.md` was checked read-only after validators and now lists UID00025V at `87/91`, average `89.0`, reconstructable `false`.
- `auto-generated/-ag-memory-coverage.md` was checked read-only after validators and already lists UID00025V as `not_reconstructable` / `NONE`.
- `by-memory/-coverage-report.md` was checked read-only after validators and remains stale at row `3171`; this remains supervisor-owned manual coverage text from this report.
- `rg -n "00025V|MessageShowReadOnlyData|0x0061fa3c" source-3/project-documentation/auto-generated/NexusTK -g "*.cpp" -g "*.h"` returned no matches, so no generated C++ output contains this UID/name/range.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/00025V-MessageShowReadOnlyData-source-quality.md`
- Modified in implementation callback:
  - `by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md`
  - `by-file/MessageShowPane.md`
  - `by-class/MessageShowPane.md`
  - `by-file/MessageDialogs.md`
  - `by-file/MetaMan.md`
  - `by-class/MetaTable.md`
  - `tools/leaser/Agents/Agent-B001/research/00025V-MessageShowReadOnlyData-source-quality.md`
- Report execution: not run. Supervisor owns `execute_report` after validation.

## Implementation Tracking Checklist

Implementation callback pass:

- [x] Supervisor validation required before implementation. Proof: callback received in `goal.md` assignment `B001-implement-00025V-MessageShowReadOnlyData-20260629`.
- [x] Target doc update: edit `by-memory/0x0061fa3c-0x0061fafc.MessageShowReadOnlyData.md` to `87/91`, retain ownerless/non-reconstructable/blank-emitter/blank-C++ metadata, add current MCP session `992d23de` proof, and remove stale ownerless MidiPlayer child wording. Proof: target header/body updated; validator `000000000369` exited `0`, `ok:1`.
- [x] Target doc update: replace target `Item Summary` with the mixed non-emitting parent summary above or equivalent same-detail text. Proof: target `Item Summary` now states mixed Message/MessageShowPane/MetaMan/MetaTable/MidiPlayer `.rdata` index and blank/no-emitter disposition.
- [x] Target doc update: preserve exact child split table and update [UID:0003PF] row to route through [UID:00008A][MidiPlayer](../../../../../by-class/MidiPlayer.md). Proof: child table row and reconstruction notes updated; no child pages changed.
- [x] No child creation, split movement, or range rename: confirm [UID:0003PB]-[UID:0003PF] are already present and correct. Proof: no child files were created, renamed, or edited.
- [x] No C++ insertion: keep the target formal C++ block blank with exact no-code proof. Proof: target formal `RECONSTRUCTION_CPP CODE` block remains blank; reconstruction notes state parent no-code disposition.
- [x] Support edit `by-file/MessageShowPane.md`: historicalize/rewrite active generated/simroot wording and reject stale Wave3 ownership for `g_applyMessagePaneBorder`. Proof: status, boundary, `g_applyMessagePaneBorder`, and migration notes updated; validator `000000000371` exited `0`, `ok:1`.
- [x] Support edit `by-class/MessageShowPane.md`: rewrite active `current simroot_v2` owner wording as generated lead material; retain already-historical Wave3/simroot caveat without promoting it. Proof: evidence note now says generated lead material and IDA caller/xref authority; validator `000000000373` exited `0`, `ok:1`.
- [x] Support edit `by-file/MessageDialogs.md`: rewrite active generated-source/Wave2/Wave3/simroot evidence wording as generated lead/history and generated-output caveats. Proof: status, evidence basis, proposed content, and generated-output caveat bullets updated; validator `000000000375` exited `0`, `ok:1`.
- [x] Support check `by-class/Message.md`: no edit required for already-caveated generated lead and historical change-log Wave3 mention; record excluded-with-reason if callback leaves it unchanged. Proof: not edited per `goal.md`; ledger C012 marked `excluded-with-reason`.
- [x] Support edit `by-file/MetaMan.md`: rewrite active generated evidence/autogen route wording as generated lead/autogen route material, not source authority. Proof: status and Data Caveats updated; validator `000000000376` exited `0`, `ok:1`.
- [x] Support edit `by-class/MetaTable.md`: rewrite `Current recovered file` and `meta_wave3` lines as generated lead/history material, not owner proof. Proof: status and Evidence Notes updated; validator `000000000377` exited `0`, `ok:1`.
- [x] Support check `by-class/MidiPlayer.md`: no Wave2/Wave3/simroot/recovered-source cleanup required for this target; record excluded-with-reason if unchanged. Proof: not edited per `goal.md`; ledger C015 marked `excluded-with-reason`.
- [x] Claim And Incorporation Ledger updated in callback with `applied`, `already-present`, or `excluded-with-reason` for every accepted claim. Proof: all C001-C018 rows now have callback verification states.
- [x] Scoped validators run for every edited target/support by-* file and results recorded. Proof: validator table above records commands `000000000369`, `000000000371`, `000000000373`, `000000000375`, `000000000376`, and `000000000377`, all exit `0`, `ok:1`.
- [x] Generated C++ checked read-only; no generated file edits. Proof: read-only `rg` over `auto-generated/NexusTK` returned no matches for UID/name/range.
- [x] Generated tracker/coverage state recorded: `-ag-research-tracker.md` stale row is supervisor/generated refresh only, `-ag-memory-coverage.md` already sees non-reconstructable, and manual `by-memory/-coverage-report.md` replacement text above is supervisor-owned. Proof: read-only check shows tracker row now `87/91` reconstructable `false`, memory coverage `not_reconstructable`, and manual coverage row still stale/supervisor-owned.
- [x] No leases taken during report-only. In callback, take only short leases for immediate edit/validator batches and release immediately. Proof: B001 leased six by-* files immediately before editing and validation; `python leaser.py B001 unlease` released all six successfully, and `current_leases.md` has no active B001 row.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00025V-MessageShowReadOnlyData-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/00025V-MessageShowReadOnlyData-source-quality.md","timestamp":"2026-06-29T03:05:12","uid":"00025V"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
