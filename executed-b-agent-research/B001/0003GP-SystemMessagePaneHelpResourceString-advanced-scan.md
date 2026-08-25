** TARGET-REPORT-UID:0003GP **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003GP **
# 0003GP SystemMessagePaneHelpResourceString Advanced-Scan Research

## Finalized Report / Current Recommendation
- Current recommendation: classify the original `missing document text for SystemMessagePaneHelpResourceString` finding as a real scanner-visible compact-label gap, not a stale range, stale UID, stale filename, bad owner/emitter, or split/merge issue.
- Final disposition: repaired in-scope by adding the exact compact label `SystemMessagePaneHelpResourceString` to [UID:0003GP][0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString](../../../../../by-memory/0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md) and by refreshing the target's body wording from legacy `AUTOGEN_PARENT_UID` terminology to current `CANONICAL_OWNER` / `EMITTER_UIDS` terminology.
- Required action: no target range, filename, score, canonical owner, emitter, reclassification, split, merge, or reconstruction C++ change is needed. Supervisor should apply the shared `by-memory/-coverage-report.md` replacement block below if the current hand-maintained report still has the stale single [UID:00026M] row.
- Confidence: high. Current live IDA MCP reconfirmed the `HELP.RES` bytes, tail-label behavior, no xrefs to the `.RES` suffix label, and the four real xrefs to the literal start. Regenerated `auto-generated/by-memory-tool-report.md` no longer lists this target.

## Supporting Research

## Target
- Target UID: `0003GP`.
- Target path: `by-memory/0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md`.
- Source queue/report row: `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan previously reported `0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md: missing document text for SystemMessagePaneHelpResourceString`.
- Current supervisor classification: Goal 2 B001 advanced-scan fallback assignment from `Supervisor_notes.md`.
- Current scores and parent state after this pass: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000OE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OE`, blank reconstruction C++.

## Executive Recommendation
- Keep the exact target as `0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString`.
- Keep direct canonical owner and emitter [UID:0000OE][SystemMessagePanes](../../../../../by-file/SystemMessagePanes.md). The literal is used by the system-message pane help-resource paths in both current and old system-message pane families, and the file parent clears `89/86`.
- Treat the advanced-scan finding as a body/filename compact-label mismatch. The page described the literal as `SystemMessagePane HELP.RES String`, but the scanner checks for the compact filename label in non-change document text.
- No code-entry recommendation is appropriate. The page remains below the active `90/90+` reconstruction-code gate, and this is source-authored/resource-derived literal data plus alignment, not a function body.

## Supervisor Active Recheck
- The supervisor/user assigned exactly one target: [UID:0003GP] `by-memory/0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md`.
- The target did not require split repair before final reporting. It is already an exact child of [UID:0003DN][0x0062d974-0x0062da10.SystemMessageResourceStrings](../../../../../by-memory/0x0062d974-0x0062da10.SystemMessageResourceStrings.md), which is itself the non-emitting resource-string/boundary index under [UID:00026M][0x0062d5f8-0x0062da10.SystemMessageReadOnlyData](../../../../../by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md).
- The directly in-scope repair was performed on the target page under a B001 lease. The shared memory coverage report was not edited directly.

## Inference Research Guidance Check
- `by-structure.md` treats string literals as source-declared/generated-binary or source-authored literal data. Here, source-use and resource-loading xrefs decide the route, not address adjacency.
- `by-structure.md` requires the narrowest true semantic owner. This exact child has only system-message pane help-resource xrefs, while the surrounding resource-string index mixes system-message, forced-inform, new-system-message, and TerminalPane boundary data. Therefore `0000OE` is valid for this child, and `NONE` remains valid for the mixed parent index.
- `inference_research.md` cautions that address adjacency is weak evidence. That matters here because `DLGSTAFF.*` and the `TerminalPane` RTTI boundary follow immediately after the target, but current IDA xrefs keep `HELP.RES` in the system-message source family.
- Existing documentation was treated as a lead, not authority. Current docs, generated coverage rows, live IDA bytes/xrefs, and prior A004 notes all agree on the physical split and owner/emitter. The only target-page problem found was scanner-visible wording.

## Evidence Standards Used
- Evidence types used: current target metadata/body, parent and sibling by-memory docs, [UID:0000OE][SystemMessagePanes](../../../../../by-file/SystemMessagePanes.md), [UID:0000EA][SystemMessagePane](../../../../../by-class/SystemMessagePane.md), generated `-ag-memory-coverage.md`, generated `by-memory-tool-report.md`, shared `by-memory/-coverage-report.md`, live IDA MCP `idb_list`, `server_health`, `get_bytes`, `get_string`, `entity_query`, `xref_query`, `lookup_funcs`, `make_signature_for_range`, `trace_data_flow`, `search_text`, and `analyze_function`.
- The evidence is strong enough because the literal bytes, boundary alignment, xrefs, caller functions, and parent/source route all match across live IDA and current docs.
- Remaining uncertainty is only normal final-source declaration spelling and exact high-level helper names in the decompiled system-message code. That uncertainty does not affect this scanner repair or the owner/emitter decision.

## IDA MCP Facts
- Function/range facts:
  - `idb_list` reports active database session `b001_0003gy` for `NexusTK.exe`.
  - `server_health` reports IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - `lookup_funcs` resolves all four `HELP.RES` xref sites to `sub_586480` (`0x00586480`, size `0x675`) and `sub_589D30` (`0x00589d30`, size `0x500`).
  - `analyze_function 0x005858d0` shows the system-message key handler checks for the `?` shortcut and calls `sub_586480`.
  - `analyze_function 0x00589670` shows the old-system-message key handler performs the same `?` shortcut check and calls `sub_589D30`.
- Data/table/padding facts:
  - `get_bytes 0x0062d98c size 20`: `48 00 45 00 4C 00 50 00 2E 00 52 00 45 00 53 00 00 00 00 00`, which is UTF-16LE `HELP.RES`, a terminator at `0x0062d99c`, and two bytes of alignment through `0x0062d9a0`.
  - `get_bytes 0x0062d974 size 156` confirms the surrounding tail layout: `MSGBORD.EPD`, `HELP.RES`, alignment, `DLGSTAFF.PAL`, `DLGSTAFF.EPF`, `DLGSTAFF.EPD`, `SYSBAR.EPF`, alignment, and the `0x00650fe0` TerminalPane RTTI locator pointer.
  - `make_signature_for_range 0x0062d974-0x0062da10` returned the same byte sequence and marked it unique.
  - `entity_query names 0x0062d970-0x0062da10` reports `aGbordEpd` at `0x0062d978`, `aRes` at `0x0062d994`, `aDlgstaffPal` at `0x0062d9a0`, `aDlgstaffEpf` at `0x0062d9bc`, `aDlgstaffEpd` at `0x0062d9d8`, `aSbarEpf` at `0x0062d9f8`, and `??_7TerminalPane@@6B@` at `0x0062da10`.
  - IDA has no useful string/name head at `0x0062d98c`; this is an IDA tail-label artifact. The byte evidence proves the true source literal starts at `0x0062d98c`.
- Xref facts:
  - `xref_query to 0x0062d98c` reports exactly four data refs: `0x00586538` and `0x00586569` in `sub_586480`, plus `0x00589d9e` and `0x00589dcf` in `sub_589D30`.
  - `trace_data_flow backward 0x0062d98c` reports the same four `push offset off_62D98C` uses.
  - `search_text off_62D98C` over `0x00584000-0x0058b000` finds the same four text hits and no others.
  - `xref_query to 0x0062d994` reports no xrefs. The `.RES` label is not a separate source literal or split candidate.
  - Neighbor checks match the existing split: `0x0062d974` has system-message `MSGBORD.EPD` refs, `0x0062d9a0` has forced-inform `DLGSTAFF.PAL` refs, `0x0062d9f4` has the `SYSBAR.EPF` ref, and `0x0062da0c` has no code xrefs as a boundary dword.
- Negative IDA facts:
  - No xrefs to the interior `.RES` suffix label at `0x0062d994`.
  - No evidence supports extending this target into `MSGBORD.EPD`, `DLGSTAFF.*`, `SYSBAR.EPF`, or the `TerminalPane` boundary pointer.
  - No IDA evidence supports a canonical owner other than the system-message pane source family.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0062d98c-0x0062d9a0` | [UID:0003GP](../../../../../by-memory/0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md) | UTF-16 `HELP.RES` plus alignment | `TRUE` | [UID:0000OE][SystemMessagePanes](../../../../../by-file/SystemMessagePanes.md) | `86/91` | Keep owner/emitter; compact label gap repaired |
| `0x0062d974-0x0062da10` | [UID:0003DN](../../../../../by-memory/0x0062d974-0x0062da10.SystemMessageResourceStrings.md) | Non-emitting resource-string and TerminalPane boundary index | `FALSE` | `NONE` | `88/93` | Correct mixed container; no edit |
| `0x0062d974-0x0062d98c` | [UID:0003GO](../../../../../by-memory/0x0062d974-0x0062d98c.SystemMessagePaneMsgbordEpdString.md) | UTF-16 `MSGBORD.EPD` sibling | `TRUE` | [UID:0000OE][SystemMessagePanes](../../../../../by-file/SystemMessagePanes.md) | `87/92` | Predecessor sibling |
| `0x0062d9a0-0x0062d9f4` | [UID:0003GQ](../../../../../by-memory/0x0062d9a0-0x0062d9f4.ForcedInformMessageDialogStaffResourceStrings.md) | `DLGSTAFF.*` resource strings | `TRUE` | [UID:00005E][ForcedInformMessageDialog](../../../../../by-class/ForcedInformMessageDialog.md) | `87/92` | Successor owner boundary |
| `0x0062d9f4-0x0062da0c` | [UID:0003GR](../../../../../by-memory/0x0062d9f4-0x0062da0c.NewSystemMessageModifyHeightPaneSysbarEpfString.md) | `SYSBAR.EPF` literal | `TRUE` | [UID:00009B][NewSystemMessageModifyHeightPane](../../../../../by-class/NewSystemMessageModifyHeightPane.md) | `86/91` | Later sibling |
| `0x0062da0c-0x0062da10` | [UID:0003GS](../../../../../by-memory/0x0062da0c-0x0062da10.TerminalPaneRttiLocatorPointer.md) | TerminalPane RTTI locator pointer | `TRUE` | [UID:0000EG][TerminalPane](../../../../../by-class/TerminalPane.md) | `85/90` | Boundary child |
| `0x0062d5f8-0x0062da10` | [UID:00026M](../../../../../by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md) | Mixed system-message/forced-inform read-only island | `FALSE` | `NONE` | `90/93` | Shared coverage row stale |
| `0x00586480` | `sub_586480` | SystemMessagePane help-resource path | Code | [UID:0000OE][SystemMessagePanes](../../../../../by-file/SystemMessagePanes.md) | doc-backed | Uses target literal |
| `0x00589d30` | `sub_589D30` | OldSystemMessagePane help-resource path | Code | [UID:0000OE][SystemMessagePanes](../../../../../by-file/SystemMessagePanes.md) | doc-backed | Uses target literal |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00586538 -> 0x0062d98c` | `sub_586480` pushes `off_62D98C` before a string/resource test | Current system-message help-resource path uses the literal. |
| `0x00586569 -> 0x0062d98c` | `sub_586480` pushes `off_62D98C` as an argument | Same current path loads/expands the literal. |
| `0x00589d9e -> 0x0062d98c` | `sub_589D30` pushes `off_62D98C` before a string/resource test | Old-system-message help-resource path uses the literal. |
| `0x00589dcf -> 0x0062d98c` | `sub_589D30` pushes `off_62D98C` as an argument | Same old path loads/expands the literal. |
| `0x005858d0 -> 0x00586480` | key handler calls `sub_586480` after detecting `?` | Confirms help-shortcut context for one route. |
| `0x00589670 -> 0x00589d30` | key handler calls `sub_589D30` after detecting `?` | Confirms parallel old-pane help-shortcut context. |
| `0x0062d994` | no xrefs | The `.RES` label is an interior tail label only. |
| `0x0062d9a0` | forced-inform xref in `sub_587BB0` | Confirms successor child belongs to a different owner. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - Target page metadata already had UID `0003GP`, exact range `0x0062d98c-0x0062d9a0`, owner/emitter `0000OE`, reconstructable `TRUE`, and blank C++.
  - [UID:0003DN][SystemMessageResourceStrings](../../../../../by-memory/0x0062d974-0x0062da10.SystemMessageResourceStrings.md) already documents this target as an exact child routed to [UID:0000OE][SystemMessagePanes](../../../../../by-file/SystemMessagePanes.md).
  - [UID:00026M][SystemMessageReadOnlyData](../../../../../by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md) records the same four help-resource refs and the mixed parent split.
  - [UID:0000OE][SystemMessagePanes](../../../../../by-file/SystemMessagePanes.md) clears `89/86` and owns the current and old system-message pane source family.
  - [UID:0000EA][SystemMessagePane](../../../../../by-class/SystemMessagePane.md) documents the help shortcut path and system-message pane role.
  - `auto-generated/-ag-memory-coverage.md` is current and correct for this item: UID `0003GP`, status `emits`, owner `0000OE`, emitter `0000OE`, output `auto-generated/NexusTK/social/SystemMessagePanes.cpp`.
- Existing docs that were stale, incomplete, or contradicted:
  - The target page lacked non-change-section text containing the compact label `SystemMessagePaneHelpResourceString`; fixed in this pass.
  - The target page used legacy `AUTOGEN_PARENT_UID` body wording even though metadata now uses `CANONICAL_OWNER` and `EMITTER_UIDS`; fixed in this pass.
  - `by-memory/-coverage-report.md` is stale around [UID:00026M]: it still shows `0x0062d5fc-0x0062da10`, `reconstructable : 88%`, omits the exact children, and says `SystemMessagePanes` is below 85 confidence. Current docs and generated coverage contradict all three points.
- Generated/coverage report state:
  - Before this pass, `auto-generated/by-memory-tool-report.md` reported the missing compact document text.
  - After `python tools\memory_ranges.py --advanced-scan report`, `auto-generated/by-memory-tool-report.md` no longer lists `SystemMessagePaneHelpResourceString`, `0062d98c`, or `0003GP`.
  - `auto-generated/-ag-memory-coverage.md` still lists the correct owner/emitter row and was reported unchanged by validator.

## Ranked Ownership Analysis

### 1. Keep [UID:0000OE][SystemMessagePanes] as canonical owner and emitter
- Evidence for:
  - The target is a `HELP.RES` resource literal used by system-message pane help-loading paths.
  - Live IDA shows the four refs all land in `sub_586480` and `sub_589D30`, both in the system-message pane code family.
  - The caller key handlers show `?` help shortcut routing into those two help loaders.
  - The direct file parent [UID:0000OE][SystemMessagePanes](../../../../../by-file/SystemMessagePanes.md) clears `89/86`.
  - The surrounding mixed parent [UID:0003DN] correctly splits away forced-inform and TerminalPane successor data.
- Evidence against:
  - None found. The exact source declaration spelling is not known, but owner/emitter routing is clear.
- Decision:
  - Accepted and retained. No metadata change needed.

### 2. Make the target `CANONICAL_OWNER:NONE`
- Evidence for:
  - The broader physical parent is mixed, and two system-message pane variants use the literal.
- Evidence against:
  - Both routes are inside the same source-file family [UID:0000OE], unlike a pooled literal shared by independent source files.
  - The exact child has one defensible file owner and one output route.
- Decision:
  - Rejected. `NONE` is correct for the mixed parent index, not for this exact child.

### 3. Assign to [UID:0000EA][SystemMessagePane] or [UID:00009T][OldSystemMessagePane] instead of the file
- Evidence for:
  - The help paths cover current and old system-message pane behavior.
- Evidence against:
  - The xrefs span more than one class in the same source family.
  - Assigning one class would hide the other class route. The file parent is the narrow common source owner.
- Decision:
  - Rejected. Keep the file owner [UID:0000OE].

### 4. Treat warning as stale filename/range or split issue
- Evidence for:
  - The advanced scan specifically named the compact filename label.
- Evidence against:
  - Current bytes prove the existing range exactly covers `HELP.RES` plus alignment.
  - No xrefs target the `.RES` suffix label at `0x0062d994`.
  - The predecessor and successor child boundaries are already correct.
- Decision:
  - Rejected. The warning was a scanner-visible text gap only.

### 5. Treat warning as harmless scanner wording only
- Evidence for:
  - The page already had correct semantic prose and current metadata.
- Evidence against:
  - The generated report persisted until the compact label appeared in active document text.
  - Prior B-agent advanced-scan repairs add the compact report label when the underlying documentation is otherwise correct.
- Decision:
  - Partly rejected. It was harmless to ownership/range, but it was a real documentation consistency gap and was fixed.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: none.
- Likely full contents: not applicable.
- Candidate related items that belong: the system-message resource children [UID:0003GO] and [UID:0003GP] route to `SystemMessagePanes`; forced-inform, new-system-message height-pane, and TerminalPane boundary children remain separate.
- Candidate related items rejected: `DLGSTAFF.*`, `SYSBAR.EPF`, and the `TerminalPane` RTTI locator pointer are address-adjacent but have different direct owners.
- Standalone, narrow, or broad source-file inference: no new source file is justified.

## Negative Evidence Summary
- No IDA evidence supports splitting `.RES` at `0x0062d994`; it has no xrefs and is a tail label inside `HELP.RES`.
- No evidence supports merging this target with `MSGBORD.EPD`, `DLGSTAFF.*`, `SYSBAR.EPF`, or the TerminalPane RTTI pointer.
- No generated coverage evidence shows an owner/emitter problem for `0003GP`.
- No final C++ should be entered because the active score is `86/91`, below the current `90/90+` code-entry gate, and this is data rather than a function body.

## Exact Required Edits
- Applied target-page edits:
  - Added `Scanner/report label: SystemMessagePaneHelpResourceString` to the `Range` section.
  - Replaced legacy body wording ``AUTOGEN_PARENT_UID is set to ...`` with current ``CANONICAL_OWNER and EMITTER_UIDS are both ...``.
  - Added a 2026-06-14 change note documenting the advanced-scan label repair and fresh IDA evidence.
- No target metadata changes were needed:
  - Keep `COMPLETION:86`.
  - Keep `CONFIDENCE:91`.
  - Keep `CANONICAL_OWNER:0000OE`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Keep `EMITTER_UIDS:0000OE`.
  - Keep blank `RECONSTRUCTION_CPP`.

## Shared Report / Coverage Text
- Do not directly edit `by-memory/-coverage-report.md` in this B001 pass.
- Recommended supervisor replacement for the stale single [UID:00026M] row currently at the `0x0062d5f8` neighborhood:

```text
    - [UID:00026M][0x0062d5f8-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md) 0x0062d5f8-0x0062da10 | vtable/string-data | SystemMessageReadOnlyData : ignored : 90% : strong : Non-emitting mixed read-only inventory for SystemMessagePane, marker/color system-message entries, ForcedInformMessageDialog, NewSystemMessageModifyHeightPane, NewSystemMessagePane, OldSystemMessagePane, resource-string children, and the TerminalPane RTTI boundary. Exact children carry owner/emitter routing; the aggregate remains CANONICAL_OWNER:NONE with blank emitters because no single direct parent owns the full physical island.
        - [UID:0003DI][0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData](by-memory/0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData.md) 0x0062d5f8-0x0062d6a8 | vtable-data | SystemMessagePaneVtableData : reconstructable : 87% : strong : Exact SystemMessagePane RTTI/vtable child assigned to [UID:0000EA][SystemMessagePane](by-class/SystemMessagePane.md); live IDA confirms three locator/vtable pairs, constructor/destructor stores, scalar deleting destructor linkage, and the HeaderSystemMessage successor locator boundary.
        - [UID:0003DJ][0x0062d6a8-0x0062d714.SystemMessageEntryVtableData](by-memory/0x0062d6a8-0x0062d714.SystemMessageEntryVtableData.md) 0x0062d6a8-0x0062d714 | vtable-data | SystemMessageEntryVtableData : ignored : 90% : strong : Non-emitting split index over HeaderSystemMessage, FooterSystemMessage, and ColorStringSystemMessage RTTI/vtable children; exact class-owned children carry the owner/emitter routing.
            - [UID:0003GD][0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData](by-memory/0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData.md) 0x0062d6a8-0x0062d6cc | vtable-data | HeaderSystemMessageVtableData : reconstructable : 88% : strong : Exact HeaderSystemMessage locator/vtable child assigned to [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md).
            - [UID:0003GE][0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData](by-memory/0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData.md) 0x0062d6cc-0x0062d6f0 | vtable-data | FooterSystemMessageVtableData : reconstructable : 88% : strong : Exact FooterSystemMessage locator/vtable child assigned to [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md).
            - [UID:0003GF][0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData](by-memory/0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData.md) 0x0062d6f0-0x0062d714 | vtable-data | ColorStringSystemMessageVtableData : reconstructable : 88% : strong : Exact ColorStringSystemMessage locator/vtable child assigned to [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md).
        - [UID:0003DK][0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData](by-memory/0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData.md) 0x0062d714-0x0062d7b0 | vtable-data | ForcedInformMessageDialogVtableData : reconstructable : 87% : strong : Exact ForcedInformMessageDialog vtable child assigned to [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md).
        - [UID:0003DL][0x0062d7b0-0x0062d8c4.NewSystemMessagePaneVtableData](by-memory/0x0062d7b0-0x0062d8c4.NewSystemMessagePaneVtableData.md) 0x0062d7b0-0x0062d8c4 | vtable-data | NewSystemMessagePaneVtableData : ignored : 88% : strong : Non-emitting split index over NewSystemMessageModifyHeightPane and NewSystemMessagePane RTTI/vtable children; exact class-owned children carry reconstructable ownership.
            - [UID:0003GM][0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData](by-memory/0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData.md) 0x0062d7b0-0x0062d838 | vtable-data | NewSystemMessageModifyHeightPaneVtableData : reconstructable : 87% : strong : Exact NewSystemMessageModifyHeightPane locator/vtable child assigned to [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md).
            - [UID:0003GN][0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData](by-memory/0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData.md) 0x0062d838-0x0062d8c4 | vtable-data | NewSystemMessagePaneVtableData : reconstructable : 87% : strong : Exact NewSystemMessagePane locator/vtable child assigned to [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md).
        - [UID:0003DM][0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData](by-memory/0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData.md) 0x0062d8c4-0x0062d974 | vtable-data | OldSystemMessagePaneVtableData : reconstructable : 88% : strong : Exact OldSystemMessagePane locator/vtable child assigned to [UID:00009T][OldSystemMessagePane](by-class/OldSystemMessagePane.md); C001 raised the parent gate and confirmed the resource-string successor boundary.
        - [UID:0003DN][0x0062d974-0x0062da10.SystemMessageResourceStrings](by-memory/0x0062d974-0x0062da10.SystemMessageResourceStrings.md) 0x0062d974-0x0062da10 | string-data/RTTI-boundary index | SystemMessageResourceStrings : ignored : 88% : strong : Non-emitting split index over system-message resource literals, forced-inform resource literals, new-system-message height-pane `SYSBAR.EPF`, and the TerminalPane RTTI boundary pointer; exact children carry direct owner/emitter routing.
            - [UID:0003GO][0x0062d974-0x0062d98c.SystemMessagePaneMsgbordEpdString](by-memory/0x0062d974-0x0062d98c.SystemMessagePaneMsgbordEpdString.md) 0x0062d974-0x0062d98c | string-data | SystemMessagePaneMsgbordEpdString : reconstructable : 87% : strong : Exact UTF-16 `MSGBORD.EPD` child assigned to [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md); `GBORD.EPD` is an interior tail label, not a separate source literal.
            - [UID:0003GP][0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString](by-memory/0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md) 0x0062d98c-0x0062d9a0 | string-data | SystemMessagePaneHelpResourceString : reconstructable : 86% : strong : Exact UTF-16 `HELP.RES` plus alignment child assigned to [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md); B001 advanced-scan pass added the compact report label, refreshed owner/emitter wording, and live IDA reconfirmed the true literal start, `.RES` tail label, no xrefs to `0x0062d994`, and four refs from the system-message help paths.
            - [UID:0003GQ][0x0062d9a0-0x0062d9f4.ForcedInformMessageDialogStaffResourceStrings](by-memory/0x0062d9a0-0x0062d9f4.ForcedInformMessageDialogStaffResourceStrings.md) 0x0062d9a0-0x0062d9f4 | string-data | ForcedInformMessageDialogStaffResourceStrings : reconstructable : 87% : strong : Exact `DLGSTAFF.PAL`, `DLGSTAFF.EPF`, and `DLGSTAFF.EPD` resource literal group assigned to [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md).
            - [UID:0003GR][0x0062d9f4-0x0062da0c.NewSystemMessageModifyHeightPaneSysbarEpfString](by-memory/0x0062d9f4-0x0062da0c.NewSystemMessageModifyHeightPaneSysbarEpfString.md) 0x0062d9f4-0x0062da0c | string-data | NewSystemMessageModifyHeightPaneSysbarEpfString : reconstructable : 86% : strong : Exact UTF-16 `SYSBAR.EPF` plus alignment child assigned to [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md); `SBAR.EPF` is an interior tail label.
            - [UID:0003GS][0x0062da0c-0x0062da10.TerminalPaneRttiLocatorPointer](by-memory/0x0062da0c-0x0062da10.TerminalPaneRttiLocatorPointer.md) 0x0062da0c-0x0062da10 | vtable-data | TerminalPaneRttiLocatorPointer : reconstructable : 85% : strong : Exact `TerminalPane` complete-object-locator pointer assigned to [UID:0000EG][TerminalPane](by-class/TerminalPane.md); this boundary dword is not a resource string.
```

## Final Recommendation
- Exact changes applied or recommended: target label/body repair applied; shared coverage-report replacement block recommended for supervisor.
- Exact parent assignments applied or recommended: keep target `CANONICAL_OWNER:0000OE`; keep `EMITTER_UIDS:0000OE`.
- Exact items left no-owner/non-emitting and why: [UID:0003DN] and [UID:00026M] remain no-owner/non-emitting because each is a mixed physical index over exact children with different direct owners.
- Exact future work outside this assignment scope: the stale shared `by-memory/-coverage-report.md` row should be supervisor-applied; no further `0003GP` target work is needed.

## Follow-Up Actions
- Supervisor actions: apply the shared `by-memory/-coverage-report.md` replacement block if desired. The generated advanced-scan finding itself is already cleared.
- A-agent actions: none for this target.
- B001 future research actions: none for `0003GP`.

## Confidence
- Recommendation confidence: high for the label repair and unchanged owner/emitter decision.
- Score confidence: retain `86/91`. The range, literal bytes, xrefs, and source route are strong; no score raise is needed for a scanner wording repair, and final C++ stays blocked by the `90/90+` gate.
- Remaining uncertainty: exact original helper names and source declaration spelling for the help loader are broader system-message reconstruction questions, not blockers for this target-page decision.

## Validator Results
- Lease workflow:
  - Read `tools/leaser/Agents/current_leases.md`: no active lease on this target.
  - Ran `python leaser.py B001 lease E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md`: success.
  - Ran `python leaser.py B001 unlease E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md`: success.
  - Final lease check: no `B001`, `0003GP`, `0062d98c`, or `SystemMessagePaneHelpResourceString` entries in current leases.
- Commands run:
  - `python tools\validator.py --mode file --file by-memory\0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md --apply --queue-timeout 240`
  - `python tools\memory_ranges.py --advanced-scan report`
- Results:
  - Validator exited `0`, `ok: 1`; `auto-generated/-ag-memory-coverage.md` was reported unchanged.
  - Validator generated expected side effects in projected stats / registry state.
  - Memory-ranges exited `0` and wrote `auto-generated/by-memory-tool-report.md`.
  - `Select-String` after regeneration found no `SystemMessagePaneHelpResourceString`, `0062d98c`, or `0003GP` match in `auto-generated/by-memory-tool-report.md`.
- Any unresolved validator warnings/errors: none for this target.
- Dry runs: none used.

## Changed Files
- Created:
  - `tools/leaser/Agents/Agent-B001/research/0003GP-SystemMessagePaneHelpResourceString-advanced-scan.md`.
- Modified:
  - `by-memory/0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md`.
  - Generated/report side effect: `auto-generated/by-memory-tool-report.md`.
  - Validator-generated side effects reported by the validator: `project-level/-auto-completion-stats.md` and validator registry state.
- Not directly edited:
  - `by-memory/-coverage-report.md`.
  - `auto-generated/-ag-memory-coverage.md` (validator reported unchanged).
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003GP","source_path":"executed-b-agent-research/B001/0003GP-SystemMessagePaneHelpResourceString-advanced-scan.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
