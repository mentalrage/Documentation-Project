** TARGET-REPORT-UID:0001L8 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B005 Source Quality Report - 0001L8 TargetSelectionInputPanes

Status: FINISHED_REPORT

Agent: Agent-B005  
Assignment: B005-report-0001L8-TargetSelectionInputPanes-source-quality-20260627  
Primary target: `[UID:0001L8] by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md`  
Required report path: `tools/leaser/Agents/Agent-B005/research/0001L8-TargetSelectionInputPanes-source-quality.md`

## Executive Recommendation

`[UID:0001L8]` should not remain an emitting, reconstructable source-authored index. It is a contiguous by-memory audit/index page spanning several target-selection helpers and pane methods whose exact source-bearing children already own the reconstructable source units. The aggregate should become a non-emitting container after its child coverage is repaired.

Recommended final metadata after implementing the missing split described below:

```text
RECONSTRUCTABLE:FALSE
CANONICAL_OWNER:0000OH
EMITTER_UIDS:
COMPLETION:88
CONFIDENCE:90
RECONSTRUCTION_CPP:
```

Do not add formal C++ to `[UID:0001L8]`. The correct implementation action is to repair the boundary/child map, especially the undocumented SelectObject raw helper island at `0x005afd50-0x005afe6f`, and keep exact child pages responsible for source output.

If only the aggregate metadata is changed without adding the missing raw helper documentation, keep the target closer to the current `85/88` because exact child coverage is still incomplete inside the target range.

## Live IDA MCP Evidence

IDA MCP was available and responsive for this pass. The active IDB session was `80de0a67` for `NexusTK.exe.i64`; `server_health` reported `status: ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

The target range is not one source unit. Live function lookup showed a sequence of discrete modeled functions plus non-function helper/data islands:

| Range / start | Live IDA result | Current doc role |
| --- | --- | --- |
| `0x005af390` | `sub_5AF390`, size `0x1f` | `[UID:0001L7] ClearItemWhoTarget` |
| `0x005af3b0`, `0x005af430`, `0x005af4b0` | not functions | `[UID:0002S5] ItemWhoTargetNavigationRawHelpers` |
| `0x005af4f0` | `sub_5AF4F0`, size `0x8b` | `[UID:0001L9] SendTargetedActionPacket` |
| `0x005af580` | `sub_5AF580`, size `0x6a` | `[UID:0001LA] SendObjectActionPacket` |
| `0x005af5f0` | `sub_5AF5F0`, size `0xee` | `[UID:0001LB] SelectObjectWithKeyboardPaneConstructor` |
| `0x005af6e0` | `sub_5AF6E0`, size `0x29` | `[UID:0001LC] SelectObjectWithKeyboardPaneDestructor` |
| `0x005af710` | `sub_5AF710`, size `0x245` | `[UID:0001LD] SelectObjectWithKeyboardPaneOnKeyEvent` |
| `0x005afa10` | `sub_5AFA10`, size `0x27d` | `[UID:0001LE] SelectObjectWithKeyboardPaneOnMouseEvent` |
| `0x005afc90` | `sub_5AFC90`, size `0x93` | `[UID:0001LF] SelectObjectWithKeyboardPaneObjectListVirtual` |
| `0x005afd30` | `sub_5AFD30`, size `0x1f` | `[UID:0001LG] SelectObjectWithKeyboardPaneClearCurrentTarget` |
| `0x005afd50`, `0x005afdc0`, `0x005afe30` | not modeled functions, executable helper bodies | missing SelectObject raw helper island |
| `0x005afe70` | `sub_5AFE70`, size `0x7e` | `[UID:0001LH] SelectObjectWithKeyboardPaneForwardTabKey` |
| `0x005afef0` | `sub_5AFEF0`, size `0xee` | `[UID:0001LI] TargetObjectWithKeyboardPaneConstructor` |
| `0x005affe0` | `sub_5AFFE0`, size `0x29` | `[UID:0001LJ] TargetObjectWithKeyboardPaneDestructor` |
| `0x005b0010` | `sub_5B0010`, size `0x1ca` | `[UID:0001LK] TargetObjectWithKeyboardPaneKeyboardEvent` |
| `0x005b0290` | `sub_5B0290`, size `0x27d` | `[UID:0001LL] TargetObjectWithKeyboardPaneMouseEvent` |
| `0x005b050d` | not a function | final padding before suffix child |

This mixed shape is the main reason `[UID:0001L8]` should be a non-emitting range index rather than a source-authored code object.

## Exact Child Coverage

Current exact children inside `[UID:0001L8]` are mostly well identified:

| UID | Range | Owner / emitter | Current C++ state | Finding |
| --- | --- | --- | --- | --- |
| `0001L7` | `0x005af390-0x005af3af` | `0000OH / 0000OH` | populated | Exact ItemWho clear helper; xrefs from ItemWho key/mouse handlers confirm use. |
| `0002S5` | `0x005af3b0-0x005af4ef` | `00006X / 00006X` | blank | Raw ItemWho navigation helper container; helper starts have no direct xrefs. |
| `0001L9` | `0x005af4f0-0x005af57b` | `0000OH / 0000OH` | blank | Shared targeted-action packet helper; exact function, not aggregate code. |
| `0001LA` | `0x005af580-0x005af5ea` | `0000OH / 0000OH` | blank | Shared object-action packet helper; exact function, not aggregate code. |
| `0001LB` | `0x005af5f0-0x005af6de` | `0000CT / 0000CT` | blank | SelectObject constructor. |
| `0001LC` | `0x005af6e0-0x005af709` | `0000CT / 0000CT` | blank | SelectObject destructor. |
| `0001LD` | `0x005af710-0x005af955` | `0000CT / 0000CT` | populated | SelectObject key handler; source-shaped child. |
| `0001LE` | `0x005afa10-0x005afc8d` | `0000CT / 0000CT` | populated | SelectObject mouse handler; source-shaped child. |
| `0001LF` | `0x005afc90-0x005afd23` | `0000CT / 0000CT` | blank | SelectObject object-list virtual helper. |
| `0001LG` | `0x005afd30-0x005afd4f` | `0000CT / 0000CT` | blank | SelectObject clear-current-target helper. |
| missing | `0x005afd50-0x005afe6f` | should be `0000CT / non-emitting` | blank | Undocumented SelectObject raw helper island found live. |
| `0001LH` | `0x005afe70-0x005afeee` | `0000CT / 0000CT` | blank | SelectObject forward-tab helper. |
| `0001LI` | `0x005afef0-0x005affde` | `0000ED / 0000ED` | blank | TargetObject constructor. |
| `0001LJ` | `0x005affe0-0x005b0009` | `0000ED / 0000ED` | blank | TargetObject destructor. |
| `0001LK` | `0x005b0010-0x005b01da` | `0000ED / 0000ED` | blank | TargetObject key handler. |
| `0001LL` | `0x005b0290-0x005b050d` | `0000ED / 0000ED` | populated | TargetObject mouse handler. |

The gap at `0x005afd50-0x005afe6f` prevents the aggregate from claiming complete exact child coverage today. It is not padding and should not remain an undocumented internal span.

## Padding, Support Tables, and Boundaries

Live byte reads support the following boundary map:

| Range | Classification |
| --- | --- |
| `0x005af3af-0x005af3b0` | one `cc` alignment byte |
| `0x005af4ef-0x005af4f0` | one `cc` alignment byte |
| `0x005af57b-0x005af580` | five `cc` bytes |
| `0x005af5ea-0x005af5f0` | six `cc` bytes |
| `0x005af6de-0x005af6e0` | two `cc` bytes |
| `0x005af709-0x005af710` | seven `cc` bytes |
| `0x005af955-0x005afa10` | SelectObject key-handler switch support and alignment, not a function |
| `0x005afc8d-0x005afc90` | three `cc` bytes |
| `0x005afd23-0x005afd30` | thirteen `cc` bytes |
| `0x005afd4f-0x005afd50` | one `cc` byte after `ClearCurrentTarget` |
| `0x005afd50-0x005afe6f` | executable raw SelectObject helper island |
| `0x005afe6f-0x005afe70` | one-byte alignment before `ForwardTabKey` |
| `0x005afeee-0x005afef0` | two `cc` bytes |
| `0x005affde-0x005affe0` | two `cc` bytes |
| `0x005b0009-0x005b0010` | seven `cc` bytes |
| `0x005b01da-0x005b0290` | TargetObject key-handler switch support and alignment, not a function |
| `0x005b050d-0x005b0510` | three `cc` bytes before the suffix child |

The target aggregate currently has enough child and boundary evidence to become a high-confidence non-emitting index, but only after the SelectObject raw helper island is represented.

## Missing SelectObject Raw Helper Island

Live disassembly and byte inspection show three executable raw helper bodies between `[UID:0001LG]` and `[UID:0001LH]`:

| Proposed range | Proposed role | Evidence |
| --- | --- | --- |
| `0x005afd50-0x005afdb7` | `SelectObjectWithKeyboardPaneSelectPreviousTargetRawHelper` | Reads `dword_67A764`, uses saved target `unk_69BF28`, calls traversal helper `sub_506AE0`, toggles highlight through `sub_53B1B0`, stores or clears `[esi+0xfc]`. |
| `0x005afdc0-0x005afe27` | `SelectObjectWithKeyboardPaneSelectNextTargetRawHelper` | Same state/update shape as the previous helper but calls traversal helper `sub_506B30`. |
| `0x005afe30-0x005afe6e` | `SelectObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper` | Uses local/current player state, clears old highlight, highlights the local player target, and stores `[esi+0xfc]` to `unk_69BF28`. |

Alignment inside the island:

```text
0x005afdb8-0x005afdc0: 8-byte alignment
0x005afe28-0x005afe30: 8-byte alignment
0x005afe6f-0x005afe70: 1-byte alignment
```

Reachability check:

```text
xrefs_to 0x005afd50: 0
xrefs_to 0x005afdc0: 0
xrefs_to 0x005afe30: 0
find code_ref/data_ref to those starts: 0 matches
```

The helper bodies do reference the saved target global. `xrefs_to 0x0069bf28` includes raw-island references at `0x5afd58`, `0x5afda4`, `0x5afdab`, `0x5afdc8`, `0x5afe14`, `0x5afe1b`, `0x5afe37`, and `0x5afe68`.

Recommended documentation repair:

1. Create `by-memory/0x005afd50-0x005afe6f.SelectObjectWithKeyboardPaneNavigationRawHelpers.md` as a non-emitting raw helper container owned by `[UID:0000CT]`.
2. Prefer exact child pages for the three helper bodies above, each reconstructable only as an exact raw helper with blank formal C++ until a direct source route or entry-call mechanism is recovered.
3. Add the padding/alignment ranges to the parent boundary map so `[UID:0001L8]` does not silently absorb executable raw code or switch data.

Suggested child scoring for the three raw helpers is approximately `COMPLETION:85`, `CONFIDENCE:88` if they are created with the evidence above and no formal C++.

## ItemWho Raw Helper Island

The existing ItemWho raw helper container `[UID:0002S5] by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md` remains justified.

Live checks:

```text
lookup_funcs 0x005af3b0: not a function
lookup_funcs 0x005af430: not a function
lookup_funcs 0x005af4b0: not a function
xrefs_to 0x005af3b0 / 0x005af430 / 0x005af4b0: 0 each
find code_ref/data_ref to those starts: 0 matches
```

This supports keeping `[UID:0002S5]` as raw-helper documentation with no formal C++ until the helper-start reachability or source call surface is recovered. It should stay under the ItemWho class route `[UID:00006X]` and not be treated as aggregate-level source code for `[UID:0001L8]`.

## TargetObject Suffix and Non-Contiguous Helpers

The suffix children after `[UID:0001L8]` are correctly outside the target range and should not be pulled into the aggregate:

| UID | Range | Finding |
| --- | --- | --- |
| `00036R` | `0x005b0510-0x005b05a3` | TargetObject object-list helper; vtable/data xref observed at `0x0062f414`. |
| `00036S` | `0x005b05b0-0x005b05cf` | TargetObject clear-current-target helper; code refs from `0x005b0082`, `0x005b0422`, and `0x005b0495`. |
| `00036T` | `0x005b05d0-0x005b06ef` | TargetObject raw navigation helpers; raw starts have no direct xrefs and should remain non-emitting container documentation. |
| `00036U` | `0x005b06f0-0x005b077a` | TargetObject dispatch-forward helper; code refs from `0x005b00ce` and `0x005b00f4` in `sub_5B0010`. |

Live checks for `0x005b05d0`, `0x005b0640`, and `0x005b06b0` returned no modeled function and no code/data xrefs to the helper starts. This matches the TargetObject raw-helper treatment and provides the template for the missing SelectObject raw-helper split.

Non-contiguous destructor and thunk evidence also supports child-level handling, not aggregate code emission:

```text
0x005b7862 and 0x005b786d: SelectObject adjustor thunks, data xrefs from vtable slots.
0x005b7bc0: SelectObject scalar deleting destructor, reached by thunk jumps and vtable data.
0x005b7912 and 0x005b791d: TargetObject adjustor thunks, data xrefs from vtable slots.
0x005b81d0: TargetObject scalar deleting destructor, reached by thunk jumps and vtable data.
```

These are non-contiguous support artifacts and should not be merged into `[UID:0001L8]`.

## Packet and Action Helpers

The shared packet helpers are exact functions and should stay as child/source helper pages under the file route `[UID:0000OH]`; they are not evidence that the aggregate itself is source-authored code.

Live xrefs to `0x005af4f0` (`SendTargetedActionPacket`) include callers at:

```text
0x57caa7, 0x57e3ba, 0x5a4654, 0x5ae4bd, 0x5ae82e, 0x5ae94a, 0x5ae9d3
```

Live callees for `0x005af4f0`:

```text
sub_575380, sub_5753F0, sub_5753A0, sub_574BB0, @__security_check_cookie@4
```

Live xrefs to `0x005af580` (`SendObjectActionPacket`) include callers at:

```text
0x5a3e93, 0x5a3ed2, 0x5aee54, 0x5af131, 0x5af22d
```

Live callees for `0x005af580`:

```text
sub_575380, sub_5753F0, sub_574BB0, @__security_check_cookie@4
```

Existing child docs describe the first helper as the targeted action packet writer and the second as the object action packet writer. Their formal C++ should be decided on their own exact child pages after packet-buffer API naming is pinned down. Their current blank C++ state is not a reason to make `[UID:0001L8]` emit code.

## Source Ownership and File Route

The aggregate's semantic/file owner should remain `[UID:0000OH] by-file/TargetSelectionInputPanes.md` because the range groups target-selection input-pane support and shared target/action helpers. The exact emitting children route through their class or file owners:

```text
ItemWho helpers:              00006X / 00006Y / 0000OH
SelectObjectWithKeyboardPane: 0000CT
TargetObjectWithKeyboardPane: 0000ED
Spell input support:          0000DM where applicable
Shared packet helpers:        0000OH
```

This owner graph argues for `CANONICAL_OWNER:0000OH` on the index page but blank `EMITTER_UIDS` on `[UID:0001L8]`. The child pages should carry the actual emission route.

## Reconstruction C++ Decision

No formal C++ should be inserted into `[UID:0001L8]`.

No-code proof:

1. The target is a contiguous by-memory index over independent functions, raw helper islands, switch support tables, and alignment bytes.
2. Several exact child pages already have formal C++ where the source unit is proven (`0001L7`, `0001LD`, `0001LE`, `0001LL`, and suffix child `00036R`).
3. Several child pages are exact functions but still need child-local API/name proof before safe formal code (`0001L9`, `0001LA`, constructors/destructors/helpers).
4. The newly discovered `0x005afd50-0x005afe6f` raw helper island has no direct xrefs to helper starts and is not safe for formal C++ until its source entry mechanism is recovered.
5. Emitting aggregate C++ or `[[CHILDREN]]` from `[UID:0001L8]` would duplicate or conflate child-owned source output and would mix executable code with support tables/padding.

Therefore, `[UID:0001L8]` should use blank `RECONSTRUCTION_CPP` and `RECONSTRUCTABLE:FALSE`.

## Generated Coverage Note

The generated by-memory coverage row for `[UID:0001L8]` is stale relative to the current target doc. It still reflects an older A010 Batch049 `80% / strong` summary, while the target page currently reports `COMPLETION:85` and `CONFIDENCE:88`. This report does not edit generated coverage files. A normal validator/report refresh should update generated output after the target and child documentation repairs are accepted.

## Implementation Tracking Checklist

- [x] Leased `[UID:0001L8]` only for immediate edit/validation batches.
  - Proof: B005 leased `by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md` before parent/new-file editing, then renewed it for the final validation batch after the first lease expired during validator work.
- [x] Updated `[UID:0001L8]` metadata to non-emitting container/index: `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `RECONSTRUCTION_CPP`, keep `CANONICAL_OWNER:0000OH`.
  - Proof: `by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md` now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000OH`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank inline/multiline formal C++.
- [x] Added the full boundary map, including switch-support spans at `0x005af955-0x005afa10` and `0x005b01da-0x005b0290`.
  - Proof: `[UID:0001L8]` now records every modeled function, raw island, switch-support span, and alignment range from `0x005af390` through `0x005b0510`, including `0x005afd4f-0x005afd50`, `0x005afd50-0x005afe6f`, and `0x005afe6f-0x005afe70`.
- [x] Added explicit final adjacency note for `0x005b050d-0x005b0510` padding before suffix child `[UID:00036R]`.
  - Proof: `[UID:0001L8]` boundary map records `0x005b050d-0x005b0510` as three `cc` bytes before [UID:00036R].
- [x] Created documentation for the missing SelectObject raw helper island `0x005afd50-0x005afe6f`.
  - Proof: new page [UID:00048D][0x005afd50-0x005afe6f.SelectObjectWithKeyboardPaneNavigationRawHelpers](by-memory/0x005afd50-0x005afe6f.SelectObjectWithKeyboardPaneNavigationRawHelpers.md) was created and assigned UID `00048D` by validator command `000000004242`.
- [x] Preferred exact body documentation inside the container rather than separate child pages for `0x005afd50-0x005afdb7`, `0x005afdc0-0x005afe27`, and `0x005afe30-0x005afe6e`.
  - Proof: callback instructed use of the `[UID:0002S5]` raw-helper-container pattern unless exact child pages were structurally required. [UID:00048D] documents the three exact raw body ranges and internal alignment in one same-owner container; separate child pages were intentionally excluded because all bodies are contiguous, share [UID:0000CT], share `dword_69BF28` state, and share the no-direct-start-xref limitation.
- [x] Added no-formal-C++ proof for the new raw helper island.
  - Proof: [UID:00048D] is `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000CT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CT`, but its formal C++ remains blank with a target-specific no-code proof covering no modeled functions, no direct xrefs, no recovered source call surface, and duplicate-output risk.
- [x] Updated `[UID:0000CT] SelectObjectWithKeyboardPane` to reference the new raw helper island.
  - Proof: `by-class/SelectObjectWithKeyboardPane.md` method/helper table now lists [UID:00048D] between `ClearCurrentTarget` and `ForwardTabKey`; Evidence Notes preserve the three raw body roles, saved target state, no-direct-start-xref evidence, and relation to ItemWho/TargetObject raw navigation patterns.
- [x] Updated `[UID:0000OH] TargetSelectionInputPanes` source-file route.
  - Proof: `by-file/TargetSelectionInputPanes.md` now records [UID:0001L8] as a non-emitting contiguous index and lists [UID:00048D] in the SelectObject source-route/module inventory.
- [x] Kept ItemWho raw helper `[UID:0002S5]` as-is in principle: raw helper documentation, no formal C++, no direct helper-start xrefs.
  - Proof: no content edit was required to [UID:0002S5]; [UID:0001L8] and [UID:00048D] both preserve the existing ItemWho raw-helper pattern and no-code rationale.
- [x] Kept TargetObject suffix children outside `[UID:0001L8]`; did not extend the aggregate beyond `0x005b050d`.
  - Proof: `[UID:0001L8]` now explicitly records `0x005b050d-0x005b0510` padding before [UID:00036R] and keeps [UID:00036R]-[UID:00036U] as outside suffix pages.
- [x] Reviewed adjacent exact child pages for directly contradicted stale claims.
  - Proof: [UID:0001LG] and [UID:0001LH] already state surrounding bytes are outside their exact bodies; no content edits were needed. TargetObject suffix pages were validator-registered only because their UID mappings were stale.
- [x] Ran scoped validators and did not manually edit generated reports or validator state.
  - Proof: final requested validators all returned exit code `0` and `ok:1`: `[UID:0001L8]` command `000000004266` at `2026-06-27T11:46:47-04:00`; `[UID:00048D]` command `000000004267` at `2026-06-27T11:47:01-04:00`; `[UID:0000CT]` command `000000004272` at `2026-06-27T11:48:05-04:00`; `[UID:0000OH]` command `000000004277` at `2026-06-27T11:49:15-04:00`.
- [x] Registered existing support UID mappings through documented scoped validator commands after missing-ref diagnostics surfaced.
  - Proof: existing pages [UID:00036T], [UID:00036R], [UID:00036S], [UID:00040Y], [UID:00040Z], [UID:000410], [UID:00036U], [UID:0003J6], [UID:0003J5], and [UID:0003J7] were scanned by validator commands `000000004255`, `000000004259` through `000000004264`, `000000004271`, `000000004274`, and `000000004275`; these were validator-owned registry/header-normalization side effects, not manual content changes.
- [x] Verified generated output side effects.
  - Proof: queue status command `000000004281` at `2026-06-27T11:50:07-04:00` showed no queued/processing validator or generated-refresh jobs. `auto-generated/-ag-coverage-report-by-memory.md` refreshed at validator command id `000000004279` / `2026-06-27T11:49:49-04:00`; it now shows [UID:0001L8] as `not_reconstructable`, `88%`, `very-strong`, `emits_code:false`, and [UID:00048D] as reconstructable `85%`, strong, with blank-code/no-direct-xref summary. `auto-generated/-ag-research-tracker.md` also lists [UID:0001L8] as `88/90`, `false`, and [UID:00048D] as `85/88`, `true`.

## Final B005 Position

`[UID:0001L8]` is useful and should be retained as the target-selection contiguous index, but it should be non-emitting. Its current source-quality blocker is not missing aggregate C++; it is incomplete exact child coverage caused by the undocumented SelectObject raw helper island. Once that split is documented, `[UID:0001L8]` can be promoted as a high-confidence non-emitting index with `COMPLETION:88`, `CONFIDENCE:90`, and no formal C++.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0001L8-TargetSelectionInputPanes-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0001L8-TargetSelectionInputPanes-source-quality.md","timestamp":"2026-06-27T12:16:40","uid":"0001L8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
