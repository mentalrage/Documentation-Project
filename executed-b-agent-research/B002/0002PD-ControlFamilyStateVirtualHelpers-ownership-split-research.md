** TARGET-REPORT-UID:0002PD **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002PD ControlFamilyStateVirtualHelpers Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0002PD][0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers](../../../../../by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md) as a no-owner, non-emitting, non-reconstructable mixed audit/container.
- Final disposition: exact child pages now carry all justified source routing. [UID:0003N1][0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue](../../../../../by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md) routes to [UID:0000AW][ProgressBarControlPane](../../../../../by-class/ProgressBarControlPane.md); modeled state virtual children [UID:0003N2] through [UID:0003N7] plus repaired [UID:0002PC] route to [UID:000038][ControlPane](../../../../../by-class/ControlPane.md); raw [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](../../../../../by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) remains no-owner/no-emitter at `82/84`.
- Required action: supervisor should apply the manual `by-memory/-coverage-report.md` replacement block below. Do not add aggregate emitters to `0002PD`.
- Confidence: high for the split, owner/emitter assignments on modeled functions, and no-owner aggregate disposition; medium for the raw no-xref draw helper.

## Supporting Research

## Target
- Target UID: `0002PD`
- Target path: `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`, originally no-owner with `CANONICAL_OWNER:NONE` and blank emitters.
- Supervisor tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, row `0002PD`.
- Starting state: `COMPLETION:84`, `CONFIDENCE:89`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`.
- Final state after B002 split: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.

## Executive Recommendation
`0002PD` should not gain a canonical owner or emitters. It is a physical address-band container over unrelated source-level objects:
- a `ProgressBarControlPane` current-value setter at `0x00494b50-0x00494b77`,
- base `ControlPane` virtual/state helpers at `0x00494b80-0x00494c4a`,
- the existing exact hit-test accessor child at `0x00494bf0-0x00494bf7`,
- alignment padding,
- one raw source-shaped but no-xref draw helper at `0x00494c50-0x00494c80`.

The owner/emitter model supports `CANONICAL_OWNER:NONE` with multiple emitters only for shared source-use items such as pooled literals or constants. This target is not that case. Aggregate emitters would duplicate unrelated progress-bar and base-control source and would hide the exact owner split.

## Supervisor Active Recheck
- The supervisor rejected the earlier report because it deferred split creation/research. This report follows the B-agent split-first workflow and records the actual child pages created/repaired.
- Every modeled source-bearing child in the band now has an exact by-memory page, IDA-backed behavior evidence, score rationale, and owner/emitter decision.
- The only source-shaped child that cannot clear `85/85` is [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](../../../../../by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md). It is documented explicitly as `82/84`, reconstructable, no-owner/no-emitter, with the blocker stated: no IDA function object and zero xrefs to the start.

## Evidence Standards Used
- IDA MCP facts: function boundaries, decompilation behavior, disassembly bytes, xrefs, callers/callees, vtable dword reads, and negative xref/function-object evidence.
- Documentation evidence: `ControlPane`, `ProgressBarControlPane`, `ButtonControlPane`, `RadioGroupControlPane`, `ControlPaneVtableData`, `ControlPaneVtables`, `ProgressBarControlPane` constructor/draw/current helpers, `PatchPanePacketResponseHandler`, `000114`, `000118`, and existing exact child `0002PC`.
- Inference rules: direct source ownership follows the narrowest semantic owner that clears `85/85`; consumer xrefs and address adjacency are supporting evidence only, not ownership proof.

## IDA MCP Facts

### Function and Range Facts
| Address / range | IDA fact | Decision |
| --- | --- | --- |
| `0x00494b50-0x00494b77` | `sub_494B50`, size `0x27`; writes word `this+0xfa`, invalidates via vtable `+0x20`; two PatchPane callers. | Exact ProgressBar child [UID:0003N1]. |
| `0x00494b77-0x00494b80` | not a function; nine `0xcc` bytes. | Padding, ignored ledger. |
| `0x00494b80-0x00494bad` | `sub_494B80`, size `0x2d`; writes byte `this+0x103`; invalidates on change. | Exact ControlPane child [UID:0003N2]. |
| `0x00494bad-0x00494bb0` | not a function; three `0xcc` bytes. | Padding, ignored ledger. |
| `0x00494bb0-0x00494bca` | `sub_494BB0`, size `0x1a`; sets byte `this+0x101`; invalidates on change. | Exact ControlPane child [UID:0003N3]. |
| `0x00494bca-0x00494bd0` | not a function; six `0xcc` bytes. | Padding, ignored ledger. |
| `0x00494bd0-0x00494bea` | `sub_494BD0`, size `0x1a`; clears byte `this+0x101`; invalidates on change. | Exact ControlPane child [UID:0003N4]. |
| `0x00494bea-0x00494bf0` | six `0xcc` bytes. | Existing ignored padding. |
| `0x00494bf0-0x00494bf7` | `sub_494BF0`, size `0x7`; returns byte `this+0x104`. | Existing child [UID:0002PC], repaired to ControlPane class owner. |
| `0x00494bf7-0x00494c00` | nine `0xcc` bytes. | Existing ignored padding. |
| `0x00494c00-0x00494c10` | `sub_494C00`, size `0x10`; writes byte `this+0x104`. | Exact ControlPane child [UID:0003N5]. |
| `0x00494c10-0x00494c2a` | `sub_494C10`, size `0x1a`; clears byte `this+0x102`; invalidates on change. | Exact ControlPane child [UID:0003N6]. |
| `0x00494c2a-0x00494c30` | not a function; six `0xcc` bytes. | Padding, ignored ledger. |
| `0x00494c30-0x00494c4a` | `sub_494C30`, size `0x1a`; sets byte `this+0x102`; invalidates on change. | Exact ControlPane child [UID:0003N7]. |
| `0x00494c4a-0x00494c50` | not a function; six `0xcc` bytes. | Padding, ignored ledger. |
| `0x00494c50-0x00494c80` | no IDA function object; complete raw helper checks `+0x101/+0x102`, calls `0x004b9660` and `0x004ba450`; zero xrefs. | Exact child [UID:0003N9], no-owner/no-emitter below gate. |
| `0x00494c80` | next modeled function is [UID:000119] `ProgressBarControlPane` constructor. | Successor boundary. |

### Xref and Vtable Facts
| Item | Xrefs / slot facts | Meaning |
| --- | --- | --- |
| `0x00494b50` | code xrefs at `0x005476ed` and `0x0054783f`, no data/vtable refs. | Patch progress current setter, not base ControlPane virtual. |
| `0x00494b80` | six code xrefs and 43 data refs; base vtable `0x00617ad8 -> 0x00494b80`. | Base ControlPane virtual/state setter. |
| `0x00494bb0` | 44 data refs; base vtable `0x00617adc -> 0x00494bb0`. | Base ControlPane visible/set helper. |
| `0x00494bd0` | 44 data refs; base vtable `0x00617ae0 -> 0x00494bd0`. | Base ControlPane visible/clear helper. |
| `0x00494bf0` | one code xref from `sub_49FB10`. | Hit-test skip accessor after rectangle test. |
| `0x00494c00` | 50 data refs; base vtable `0x00617ae4 -> 0x00494c00`. | Base ControlPane hit-test flag setter. |
| `0x00494c10` | one code xref plus 46 data refs; base vtable `0x00617ae8 -> 0x00494c10`. | Base ControlPane active/clear helper. |
| `0x00494c30` | two code xrefs plus 46 data refs; base vtable `0x00617aec -> 0x00494c30`. | Base ControlPane active/set helper. |
| `0x00494c50` | zero code refs, zero data refs, no function object. | Candidate ControlPane-like helper but below strict assignment gate. |

## Function / Child Inventory
| Range / item | UID / path | Role | Reconstructable | Direct parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00494b50-0x00494b77` | [UID:0003N1][ProgressBarControlPaneSetCurrentValue](../../../../../by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md) | Progress current-value setter, field `+0xfa`. | TRUE | [UID:0000AW][ProgressBarControlPane](../../../../../by-class/ProgressBarControlPane.md) | `86/90` | Assigned/emits `0000AW`. |
| `0x00494b77-0x00494b80` | [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md) | Alignment. | FALSE | none | `100/strong` | Ignored ledger updated. |
| `0x00494b80-0x00494bad` | [UID:0003N2][ControlPaneSetVisualState](../../../../../by-memory/0x00494b80-0x00494bad.ControlPaneSetVisualState.md) | Base ControlPane byte `+0x103` setter. | TRUE | [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) | `87/91` | Assigned/emits `000038`. |
| `0x00494bad-0x00494bb0` | [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md) | Alignment. | FALSE | none | `100/strong` | Ignored ledger updated. |
| `0x00494bb0-0x00494bca` | [UID:0003N3][ControlPaneSetVisibleFlag](../../../../../by-memory/0x00494bb0-0x00494bca.ControlPaneSetVisibleFlag.md) | Base ControlPane byte `+0x101` set helper. | TRUE | [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) | `86/90` | Assigned/emits `000038`. |
| `0x00494bca-0x00494bd0` | [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md) | Alignment. | FALSE | none | `100/strong` | Ignored ledger updated. |
| `0x00494bd0-0x00494bea` | [UID:0003N4][ControlPaneClearVisibleFlag](../../../../../by-memory/0x00494bd0-0x00494bea.ControlPaneClearVisibleFlag.md) | Base ControlPane byte `+0x101` clear helper. | TRUE | [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) | `86/90` | Assigned/emits `000038`. |
| `0x00494bea-0x00494bf0` | [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md) | Alignment. | FALSE | none | `100/strong` | Already tracked. |
| `0x00494bf0-0x00494bf7` | [UID:0002PC][ControlPaneIgnoresHitTesting](../../../../../by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md) | Base ControlPane hit-test suppression accessor. | TRUE | [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) | `85/90` | Repaired/emits `000038`. |
| `0x00494bf7-0x00494c00` | [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md) | Alignment. | FALSE | none | `100/strong` | Already tracked. |
| `0x00494c00-0x00494c10` | [UID:0003N5][ControlPaneSetIgnoreHitTesting](../../../../../by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md) | Base ControlPane byte `+0x104` setter. | TRUE | [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) | `86/90` | Assigned/emits `000038`. |
| `0x00494c10-0x00494c2a` | [UID:0003N6][ControlPaneDeactivate](../../../../../by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md) | Base ControlPane byte `+0x102` clear helper. | TRUE | [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) | `86/90` | Assigned/emits `000038`. |
| `0x00494c2a-0x00494c30` | [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md) | Alignment. | FALSE | none | `100/strong` | Ignored ledger updated. |
| `0x00494c30-0x00494c4a` | [UID:0003N7][ControlPaneActivate](../../../../../by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md) | Base ControlPane byte `+0x102` set helper. | TRUE | [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) | `86/90` | Assigned/emits `000038`. |
| `0x00494c4a-0x00494c50` | [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md) | Alignment. | FALSE | none | `100/strong` | Ignored ledger updated. |
| `0x00494c50-0x00494c80` | [UID:0003N9][ControlPaneDrawActiveFrameHelper](../../../../../by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) | Raw active-frame helper candidate over ControlPane state bytes. | TRUE | none | `82/84` | No-owner/no-emitter; below gate. |

## Documentation Evidence And Repairs Applied
- [UID:0000IG][ControlPane](../../../../../by-file/ControlPane.md) and [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) now list the exact base state virtual children and the raw below-gate helper candidate.
- [UID:0000MT][ProgressBarControlPane](../../../../../by-file/ProgressBarControlPane.md) and [UID:0000AW][ProgressBarControlPane](../../../../../by-class/ProgressBarControlPane.md) now include [UID:0003N1] as the modeled current-value setter.
- [UID:0000HY][ButtonControlPane](../../../../../by-file/ButtonControlPane.md) was repaired so it no longer treats `0002PD` as nearby button/choice-owned shared state.
- [UID:0000BI][RadioGroupControlPane](../../../../../by-class/RadioGroupControlPane.md) was repaired so the old `0x00494b50-0x00494c49` state/focus row now points to inherited base `ControlPane` helpers instead of RadioGroup-owned source.
- [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md) now records the newly exposed `0xcc` padding spans between exact children.
- [UID:000118][ButtonChoiceControlCore](../../../../../by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md) remains the corrected ButtonChoice/Radio/Slider/Button core successor and should not be moved back over this band.

## Ranked Ownership Analysis

### 1. Split exact children and leave aggregate no-owner/non-emitting
- Evidence for: IDA boundaries and vtable/xref evidence prove different direct owners inside the same physical band; child pages now clear or explicitly fail the strict gate individually.
- Evidence against: requires manual coverage-report repair because the old report had one broad row.
- Decision: accepted and implemented.

### 2. Assign whole aggregate to ControlPane
- Evidence for: most modeled helpers in `0x00494b80-0x00494c4a` are base ControlPane vtable slots.
- Evidence against: `0x00494b50` is progress-specific, padding is not source, and `0x00494c50` is below the owner gate.
- Decision: rejected.

### 3. Assign whole aggregate to ButtonControlPane/RadioGroup
- Evidence for: old documentation had stale nearby button/radio wording and derived controls reuse several state helpers.
- Evidence against: corrected `000118` starts at `0x00494eb0`; base ControlPane vtable owns the state slots; `0x00494b50` direct callers are PatchPane progress updates; RadioGroup constructor/option helpers start later.
- Decision: rejected and parent wording repaired.

### 4. Assign raw `0x00494c50-0x00494c80` helper to ControlPane now
- Evidence for: uses `+0x101/+0x102` state bytes set by ControlPane children, draws against `this+0x44`, and sits adjacent to the activation helper.
- Evidence against: no IDA function object, no code xrefs, no data/vtable refs, and no proven entry mechanism.
- Decision: document exact child, keep reconstructable, but leave `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` at `82/84`.

## Negative Evidence Summary
- Address adjacency is not ownership. The band sits between ProgressBar and ButtonChoice regions, but direct xrefs/vtables split ownership.
- Derived consumer wrappers are not owners. Gender/direction/pretty-button/macro/edit wrapper callers reuse inherited ControlPane virtual behavior.
- Derived vtable references are not enough to assign every helper to every derived class. The decisive slot evidence is that the base ControlPane vtable itself points to the modeled state helpers.
- The raw draw helper cannot be emitted just because its fields look like ControlPane state. It lacks the entrypoint proof required by the current strict gate.

## Coverage Report Row Text For Supervisor
Do not edit `by-memory/-coverage-report.md` directly from this report. Placement context: replace the existing single `0002PD` row immediately after the `0x00494b4b-0x00494b50` padding row with this block. Keep the existing `000118` row after the progress-bar constructor/draw/update rows because it begins at `0x00494eb0`.

```text
    - [UID:0002PD][0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers](by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md) 0x00494b50-0x00494c80 | aggregate-container | ControlFamilyStateVirtualHelpers : ignored : 88% : strong : B002 split repair reclassified this as a non-emitting mixed audit/container over one ProgressBar current-value setter, inherited ControlPane state virtuals, exact ControlPane hit-test accessor child, raw no-xref draw-state helper, and padding. Keep CANONICAL_OWNER:NONE, RECONSTRUCTABLE:FALSE, and no emitters; route source through exact child pages only.
        - [UID:0003N1][0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue](by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md) 0x00494b50-0x00494b77 | method | ProgressBarControlPaneSetCurrentValue : reconstructable : 86% : strong : B002 live IDA confirms `sub_494B50` writes current field `this+0xfa`, invalidates `this+0x44` through vtable `+0x20`, has only PatchPane packet-response calls at `0x005476ed` and `0x0054783f`, has no data/vtable refs, and routes to [UID:0000AW][ProgressBarControlPane](by-class/ProgressBarControlPane.md).
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00494b77-0x00494b80 | padding | ProgressBar current setter to ControlPane state helper alignment : ignored : 100% : strong : Confirmed nine `0xcc` bytes after `sub_494B50`.
        - [UID:0003N2][0x00494b80-0x00494bad.ControlPaneSetVisualState](by-memory/0x00494b80-0x00494bad.ControlPaneSetVisualState.md) 0x00494b80-0x00494bad | method | ControlPaneSetVisualState : reconstructable : 87% : strong : B002 live IDA confirms byte setter for `this+0x103`, redraw invalidation on change, six direct wrapper callers, 43 vtable/data refs, and base ControlPane vtable slot `0x00617ad8 -> 0x00494b80`; routes to [UID:000038][ControlPane](by-class/ControlPane.md).
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00494bad-0x00494bb0 | padding | ControlPane visual-state to visible-set helper alignment : ignored : 100% : strong : Confirmed three `0xcc` bytes between helper functions.
        - [UID:0003N3][0x00494bb0-0x00494bca.ControlPaneSetVisibleFlag](by-memory/0x00494bb0-0x00494bca.ControlPaneSetVisibleFlag.md) 0x00494bb0-0x00494bca | method | ControlPaneSetVisibleFlag : reconstructable : 86% : strong : B002 live IDA confirms set-if-clear helper for `this+0x101`, redraw invalidation on change, 44 vtable/data refs, and base ControlPane vtable slot `0x00617adc -> 0x00494bb0`; routes to [UID:000038][ControlPane](by-class/ControlPane.md).
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00494bca-0x00494bd0 | padding | ControlPane visible-set to visible-clear helper alignment : ignored : 100% : strong : Confirmed six `0xcc` bytes between helper functions.
        - [UID:0003N4][0x00494bd0-0x00494bea.ControlPaneClearVisibleFlag](by-memory/0x00494bd0-0x00494bea.ControlPaneClearVisibleFlag.md) 0x00494bd0-0x00494bea | method | ControlPaneClearVisibleFlag : reconstructable : 86% : strong : B002 live IDA confirms clear-if-set helper for `this+0x101`, redraw invalidation on change, 44 vtable/data refs, and base ControlPane vtable slot `0x00617ae0 -> 0x00494bd0`; routes to [UID:000038][ControlPane](by-class/ControlPane.md).
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00494bea-0x00494bf0 | padding | ControlPane visible-clear helper to hit-test accessor alignment : ignored : 100% : strong : Confirmed six `0xcc` bytes before `ControlPane::IgnoresHitTesting`.
        - [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md) 0x00494bf0-0x00494bf7 | method | ControlPaneIgnoresHitTesting : reconstructable : 85% : strong : B002 repaired existing exact accessor child to [UID:000038][ControlPane](by-class/ControlPane.md); live IDA confirms `mov al,[ecx+0x104]; retn`, sole caller `sub_49FB10` uses it as a post-rectangle-test skip gate, and paired setter child [UID:0003N5] writes the same field.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00494bf7-0x00494c00 | padding | ControlPane hit-test accessor to setter alignment : ignored : 100% : strong : Confirmed nine `0xcc` bytes after the hit-test accessor.
        - [UID:0003N5][0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting](by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md) 0x00494c00-0x00494c10 | method | ControlPaneSetIgnoreHitTesting : reconstructable : 86% : strong : B002 live IDA confirms byte setter for `this+0x104`, no ordinary code callers, 50 vtable/data refs, and base ControlPane vtable slot `0x00617ae4 -> 0x00494c00`; routes to [UID:000038][ControlPane](by-class/ControlPane.md).
        - [UID:0003N6][0x00494c10-0x00494c2a.ControlPaneDeactivate](by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md) 0x00494c10-0x00494c2a | method | ControlPaneDeactivate : reconstructable : 86% : strong : B002 live IDA confirms clear-if-set helper for `this+0x102`, redraw invalidation on change, direct caller `0x00580639`, 46 vtable/data refs, and base ControlPane vtable slot `0x00617ae8 -> 0x00494c10`; routes to [UID:000038][ControlPane](by-class/ControlPane.md).
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00494c2a-0x00494c30 | padding | ControlPane deactivate to activate helper alignment : ignored : 100% : strong : Confirmed six `0xcc` bytes between helper functions.
        - [UID:0003N7][0x00494c30-0x00494c4a.ControlPaneActivate](by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md) 0x00494c30-0x00494c4a | method | ControlPaneActivate : reconstructable : 86% : strong : B002 live IDA confirms set-if-clear helper for `this+0x102`, redraw invalidation on change, direct callers `0x004b0b4f` and `0x00580640`, 46 vtable/data refs, and base ControlPane vtable slot `0x00617aec -> 0x00494c30`; routes to [UID:000038][ControlPane](by-class/ControlPane.md).
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00494c4a-0x00494c50 | padding | ControlPane activation to draw-state helper alignment : ignored : 100% : strong : Confirmed six `0xcc` bytes before the raw draw-state helper.
        - [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) 0x00494c50-0x00494c80 | raw-helper | ControlPaneDrawActiveFrameHelper : reconstructable : 82% : medium-strong : B002 documented this exact no-owner child; IDA has no function object and no xrefs to this start, but raw bytes form a complete helper that checks `this+0x101` and `this+0x102`, selects color `0x80`, clears `this+0x70`, and calls the GrafPort frame drawer for `this+0x44`; keep CANONICAL_OWNER:NONE and blank emitters until stronger entrypoint evidence clears the strict gate.
```

Also update the existing `0002PC` manual coverage row if it remains duplicated outside the new nested block:

```text
    - [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md) 0x00494bf0-0x00494bf7 | method | ControlPaneIgnoresHitTesting : reconstructable : 85% : strong : B002 repaired exact accessor child to [UID:000038][ControlPane](by-class/ControlPane.md); live IDA confirms exact bounds, `mov al,[ecx+0x104]; retn`, no callees, sole caller `sub_49FB10` using it as a post-rectangle-test skip gate, adjacent `0xcc` padding, and paired setter [UID:0003N5].
```

## Validator Results
- Child-page UID registration was performed earlier with normal validator file scans using `--apply`; assigned UIDs are `0003N1`, `0003N2`, `0003N3`, `0003N4`, `0003N5`, `0003N6`, `0003N7`, and `0003N9`. UID `0003N8` was consumed concurrently by B003's `ButtonControlPaneActiveRefreshHelper`, not by this target.
- Final validation command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002PD-ControlFamilyStateVirtualHelpers-ownership-split-research-removed.md](0002PD-ControlFamilyStateVirtualHelpers-ownership-split-research-removed.md). The archived block is non-authoritative and must not be executed.

- Result: exit code `0`; all file validations completed. The output ended with `ALL_VALIDATIONS_COMPLETED`.
- Normal validator side effects: UID link annotations were inserted, validator registry/report state refreshed, and generated `auto-generated/-ag-memory-coverage.md` now shows `0003N1-0003N7` as emitting through `0000AW` or `000038`, `0003N9` as `no-owner`, and `0002PD` as `not_reconstructable`.
- Unresolved validator errors: none observed.
- Not used: no dry-run validator mode; no memory-range mode.

## Changed Files
Created:
- `by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md`
- `by-memory/0x00494b80-0x00494bad.ControlPaneSetVisualState.md`
- `by-memory/0x00494bb0-0x00494bca.ControlPaneSetVisibleFlag.md`
- `by-memory/0x00494bd0-0x00494bea.ControlPaneClearVisibleFlag.md`
- `by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md`
- `by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md`
- `by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md`
- `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`

Modified:
- `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`
- `by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md`
- `by-memory/-ignored.md`
- `by-file/ControlPane.md`
- `by-class/ControlPane.md`
- `by-file/ProgressBarControlPane.md`
- `by-class/ProgressBarControlPane.md`
- `by-file/ButtonControlPane.md`
- `by-class/RadioGroupControlPane.md`
- `auto-generated/-ag-memory-coverage.md` and other validator-generated reports/registry outputs as normal validator side effects.
- `tools/leaser/Agents/Agent-B002/research/0002PD-ControlFamilyStateVirtualHelpers-ownership-split-research.md`

Not modified:
- `by-memory/-coverage-report.md` was not edited directly.

## Blockers
- No external blocker prevented the split, child research, parent repair, or normal validation.
- Remaining research uncertainty is limited to the raw `0x00494c50-0x00494c80` helper. It is documented in its own child page and no longer hidden inside the aggregate.

## Final Recommendation
Finalize `0002PD` as a non-reconstructable mixed container with no owner and no emitters. Apply the manual coverage-report replacement block above. Treat [UID:0003N9] as the only unresolved child; all other source-bearing modeled children now have evidence-backed direct owner/emitter routing.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002PD-ControlFamilyStateVirtualHelpers-ownership-split-research.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002PD"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002PD-ControlFamilyStateVirtualHelpers-ownership-split-research-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002PD-ControlFamilyStateVirtualHelpers-ownership-split-research.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002PD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
