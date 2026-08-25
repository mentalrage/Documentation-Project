** TARGET-REPORT-UID:000114 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 Report - [UID:000114] ControlPaneAndProgressBarPrelude Source Routing

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/000114-ControlPaneAndProgressBarPrelude-source-routing.md`

Target: `source-3/project-documentation/by-memory/0x004949e0-0x00494b50.ControlPaneAndProgressBarPrelude.md`

Task type: B-agent report-only source-routing/source-quality pass. No by-* files were edited. `by-memory/-coverage-report.md` was not edited.

## Executive Recommendation

Keep [UID:000114] as a parentless, non-reconstructable, non-emitting physical range index. It should not receive a source owner, aggregate emitter, or formal C++ body.

Recommended target metadata:

```text
COMPLETION:86
CONFIDENCE:90
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Rationale: the target span is not one source item. It contains one exact `ControlPane` constructor child, two raw/projected `ProgressBarControlPane` range-helper children, and three `0xcc` padding spans. The next source-bearing band begins exactly at `0x00494b50`, and the `ControlPane::IgnoresHitTesting` accessor at `0x00494bf0-0x00494bf7` is outside this aggregate. The current `84/88` target is factually correct but capped too low now that the child split, padding map, no-code proof, and coverage mismatch are all resolved.

## Evidence Checked

- Read target [UID:000114] `0x004949e0-0x00494b50.ControlPaneAndProgressBarPrelude.md`.
- Read exact interior children:
  - [UID:0002PB] `0x004949e0-0x00494a81.ControlPaneConstructor.md`
  - [UID:000115] `0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter.md`
  - [UID:000117] `0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter.md`
  - [UID:000116] `0x00494a90-0x00494b4b.ProgressBarRangeSetters.md`
- Read out-of-range/successor context:
  - [UID:0002PD] `0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`
  - [UID:0003N1] `0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md`
  - [UID:0002PC] `0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md`
- Read source parents/support:
  - [UID:000038] `by-class/ControlPane.md`
  - [UID:0000IG] `by-file/ControlPane.md`
  - [UID:0000AW] `by-class/ProgressBarControlPane.md`
  - [UID:0000MT] `by-file/ProgressBarControlPane.md`
  - [UID:0003J9] `by-type/by-vtable/ControlPaneVtables.md`
  - [UID:0003J8] `by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md`
  - [UID:0001YH] `by-type/by-vtable/ProgressBarControlPaneVtables.md`
  - [UID:0002OL] `by-memory/0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData.md`
  - `by-project-structure/proposed-source-tree.md`
  - `wave3_data_issues.md`
- Read generated routing:
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/NexusTK/ui/core/ControlPane.cpp`
  - `auto-generated/NexusTK/ui/controls/ProgressBarControlPane.cpp`
  - `project-level/-auto-completion-stats.md`
- Read current manual coverage row context from `by-memory/-coverage-report.md` without editing it.
- Local PE checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 `4247E04E20B65D6414C7238AA8FF5515`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.

## Exact Range Split

The corrected target split is:

| Range | Disposition | Source route |
| --- | --- | --- |
| `0x004949df-0x004949e0` | one-byte predecessor padding | outside target |
| `0x004949e0-0x00494a81` | [UID:0002PB] `ControlPane::ControlPane` | [UID:000038] `ControlPane` / [UID:0000IG] `ui/core/ControlPane.cpp` |
| `0x00494a81-0x00494a90` | 15 bytes `0xcc` | padding |
| `0x00494a90-0x00494ae7` | [UID:000115] raw/projected progress range-start setter | [UID:0000AW] `ProgressBarControlPane` / [UID:0000MT] `ui/controls/ProgressBarControlPane.cpp` |
| `0x00494ae7-0x00494af0` | 9 bytes `0xcc` | padding |
| `0x00494af0-0x00494b4b` | [UID:000117] raw/projected progress range-end setter | [UID:0000AW] `ProgressBarControlPane` / [UID:0000MT] `ui/controls/ProgressBarControlPane.cpp` |
| `0x00494b4b-0x00494b50` | 5 bytes `0xcc` | padding |
| `0x00494b50-...` | successor band starts at [UID:0002PD] | outside target |
| `0x00494bf0-0x00494bf7` | [UID:0002PC] `ControlPane::IgnoresHitTesting` | outside target, inside [UID:0002PD] |

Direct PE byte verification:

```text
0x004949e0-0x00494a81 len=0xa1 all_cc=False first=55 8b ec 6a ff 68 d8 ce 5f 00 64 a1 00 00 00 00 last=f4 64 89 0d 00 00 00 00 59 5e 8b e5 5d c2 08 00
0x00494a81-0x00494a90 len=0xf all_cc=True
0x00494a90-0x00494ae7 len=0x57 all_cc=False first=55 8b ec 56 8b 75 08 57 8b f9 66 85 f6 79 04 33 last=89 b7 f8 00 00 00 ff 50 20 5b 5f 5e 5d c2 04 00
0x00494ae7-0x00494af0 len=0x9 all_cc=True
0x00494af0-0x00494b4b len=0x5b all_cc=False first=55 8b ec 56 8b 75 08 57 8b f9 66 85 f6 79 04 33 last=66 89 b7 fc 00 00 00 ff 52 20 5f 5e 5d c2 04 00
0x00494b4b-0x00494b50 len=0x5 all_cc=True
0x00494b50-0x00494b77 len=0x27 all_cc=False
0x00494bf0-0x00494bf7 len=0x7 all_cc=False first=8a 81 04 01 00 00 c3
```

Rel32 route scan:

```text
0x004949e0 rel32 call/jump hits=52
0x00494a90 rel32 call/jump hits=0
0x00494af0 rel32 call/jump hits=0
0x00494b50 rel32 call/jump hits=2 at 0x005476ed and 0x0054783f
0x00494bf0 rel32 call/jump hits=1 at 0x0049fb7f
```

Absolute-VA/RVA pointer-pattern scan over the PE found zero hits to `0x004949e0`, `0x00494a90`, `0x00494af0`, `0x00494b50`, and `0x00494bf0`. The positive routes here are rel32 code references, not data pointers.

## Constructor Child

[UID:0002PB] is the exact constructor child and should remain the only `ControlPane` source-bearing code inside [UID:000114].

Resolved direction:

- Source-facing signature direction: `ControlPane::ControlPane(unsigned char controlType, const RectBounds *bounds)` or equivalent local bounds pointer type. The first argument is stored at `this+0xfe`; the second argument gates the `0x00544bd0(this, bounds, 0)` optional bounds initialization call.
- Callees: `0x00544460` base `Pane` construction with mode `1`, and `0x00544bd0` optional bounds initialization.
- Direct route: 52 rel32 constructor call sites across UI/control constructors.
- Vtable stores: primary at `this+0`, secondary at `this+0xa0`, tertiary at `this+0xa4`, matching `ControlPane` vtable data at `0x00617a90`, `0x00617af8`, and `0x00617b28`.
- Field-name recommendations for child/source docs, not for [UID:000114] as emitted code:
  - `this+0xfe`: `m_controlType` or `m_controlId` (high confidence role, exact original name unknown).
  - `this+0xff`: 32-bit default `0x10000`; likely packed/default control state or repeat timing state, keep provisional.
  - `this+0xf8`/`this+0xfc`: initialized in base constructor but specialized by progress-bar helpers; do not name as progress fields on `ControlPane` without layout inheritance context.
  - `this+0x103`: byte default `10`; source role remains tied to the later visual-state helper and should be finalized on the child/control state docs.

[UID:0002PB] already clears `85/90` and emits through [UID:000038]. No new exact child is needed for the constructor.

## Raw ProgressBar Helper Children

[UID:000115] and [UID:000117] are source-authored-looking helper bodies, but IDA still does not model either start as a function object and no direct route to either start is proven. They should remain exact child pages under `ProgressBarControlPane`; [UID:000114] should only index their physical placement.

Resolved source-facing name direction:

- `0x00494a90-0x00494ae7`: `ProgressBarControlPane::SetRangeStart(short value)` or `SetMinimumValue(short value)`. Best current direction is `SetRangeStart` because existing docs and field behavior describe a lower/range-start bound rather than a purely UI-facing minimum label.
- `0x00494af0-0x00494b4b`: `ProgressBarControlPane::SetRangeEnd(short value)` or `SetMaximumValue(short value)`. Best current direction is `SetRangeEnd`.
- Shared input type: signed 16-bit argument, stack-cleaned by `retn 4`.
- Clamp contract: incoming value is clamped to `0..30000` (`0x7530`).
- Field roles:
  - `this+0xf8`: `m_rangeStart` / `m_minValue`, 16-bit.
  - `this+0xfa`: `m_currentValue`, 16-bit.
  - `this+0xfc`: `m_rangeEnd` / `m_maxValue`, 16-bit.
  - `this+0x44`: inherited pane rectangle passed to invalidation.
  - primary vtable slot `+0x20`: invalidate/dirty-rectangle dispatch.

Reachability/liveness direction:

- `0x00494a90` and `0x00494af0` have no rel32 call/jump hits in the PE scan.
- Both have zero absolute VA and RVA pattern hits.
- Existing docs record IDA `lookup_funcs` as `Not a function` and no xrefs/callers.
- Therefore the helpers are not proven live by direct routing. They are best kept as retained/projected private class helper bytes because their bodies are valid `thiscall` code over the `ProgressBarControlPane` field triplet, and the constructor/draw/vtable class evidence anchors ownership.

Rejected alternatives:

- Not `ControlPane`: the helper field triplet and range/current semantics are progress-bar-specific, and `wave3_data_issues.md` explicitly warns not to attach these starts to `ControlPane`, `RadioGroupControlPane`, or `ButtonControlPane` by address locality.
- Not `ButtonChoiceControlCore`: the corrected button-choice aggregate starts later, and [UID:0002PD] now separates the `0x00494b50` successor band.
- Not padding/ignored code: the raw bytes are complete helper-shaped bodies ending in `retn 4`, not all-`0xcc` gaps.

## Out-of-Range Hit-Test Child

[UID:0002PC] `0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting` is not part of [UID:000114]. It belongs to the following [UID:0002PD] control-family helper band.

Resolved direction:

- Source-facing name direction: `ControlPane::IgnoresHitTesting()` is acceptable and already used. Alternative `IsHitTestIgnored()` is also plausible, but the existing paired setter doc [UID:0003N5] uses `SetIgnoreHitTesting`, so `IgnoresHitTesting` is the better current pairing.
- Field: `this+0x104` should be named `m_ignoreHitTesting` / `m_hitTestingIgnored`, byte.
- Route: one rel32 caller at `0x0049fb7f` inside `sub_49FB10`, after a point-in-rectangle test. The caller uses it as a skip gate: rectangle hit and not ignore-hit-testing.
- Placement: [UID:000038] `ControlPane` / [UID:0000IG] `ui/core/ControlPane.cpp`, but under [UID:0002PD] as the physical containing aggregate.

This confirms the current target endpoint at `0x00494b50`. Extending [UID:000114] to include `0x00494bf0` would recreate the already-fixed barrier crossing.

## Source Placement Ranking

1. [UID:000114] as no-owner physical index, strongest. It contains mixed source owners and padding, so it is not a source file/class/method.
2. [UID:0002PB] through [UID:000038]/[UID:0000IG], strongest for constructor code. Vtable stores, caller fan-in, class/file support docs, and generated `ControlPane.cpp` all agree.
3. [UID:000115]/[UID:000117] through [UID:0000AW]/[UID:0000MT], strongest for progress range helpers. Field triplet, constructor/draw/vtable anchors, and generated `ProgressBarControlPane.cpp` all agree.
4. [UID:0002PC] through [UID:000038]/[UID:0000IG], but physically in [UID:0002PD], not in [UID:000114].
5. Rejected: single `ControlPane.cpp` owner for the target aggregate. It would absorb progress-bar-specific helper code.
6. Rejected: single `ProgressBarControlPane.cpp` owner for the target aggregate. It would absorb the base `ControlPane` constructor.
7. Rejected: `ButtonControlPane`/`ButtonChoiceControlCore`. Current docs and C001/B002 repairs supersede the older broad local aggregate.
8. Rejected: new missing child pages inside [UID:000114]. Exact source-bearing children already exist; no uncovered executable body remains in the target span.

The proposed source tree also supports the split: `ControlPane.cpp` is under `ui/core/`, while `ProgressBarControlPane.cpp` is under `ui/controls/`.

## Aggregate No-Code Proof

[UID:000114] should keep the formal C++ block blank.

Proof:

- The aggregate is not one function, class method, helper, or data declaration.
- Its source-authored executable bodies belong to different classes and different proposed source files.
- It contains compiler/linker `0xcc` alignment between those bodies.
- Exact source-bearing child pages already exist and are the correct units for emission/routing.
- Autogen already treats [UID:000114] as `not_reconstructable` with owner `NONE` and no output.
- Emitting C++ at the aggregate would duplicate child coverage and either mis-own progress helpers as `ControlPane` or mis-own the `ControlPane` constructor as `ProgressBarControlPane`.

No first-draft aggregate C++ is appropriate. First-draft C++ readiness belongs to the exact children, not to this mixed parent. The progress helper children should remain blank until the raw-start reachability/source-name policy is settled; the constructor child is eligible only through [UID:0002PB].

## Support Docs Needed

Recommended future target edits:

- Update [UID:000114] metadata to `86/90`.
- Keep owner/emitter/reconstructable fields as `NONE`/blank/`FALSE`.
- Add the direct PE byte evidence summarized above.
- Add the rel32/VA/RVA route scan summary:
  - constructor 52 rel32 hits,
  - raw progress range helpers zero rel32 and zero pointer hits,
  - successor `0x00494b50` two rel32 hits,
  - out-of-range hit-test accessor one rel32 hit.
- Add an explicit cross-reference to [UID:000116] as the non-emitting duplicate progress range-setter aggregate inside the target span.
- Clarify that [UID:0002PC] is a related out-of-range child inside [UID:0002PD], not a target child.
- Preserve the blank formal C++ block with the no-code proof above.

Support docs:

- `by-class/ControlPane.md` and `by-file/ControlPane.md`: no mandatory factual correction found. Optional future edit can mention that [UID:000114] is only a physical index and that `ControlPane::IgnoresHitTesting` is outside it in [UID:0002PD]. Current docs already route the constructor and hit-test child correctly.
- `by-class/ProgressBarControlPane.md` and `by-file/ProgressBarControlPane.md`: no mandatory factual correction found. Optional future edit can add [UID:000114] as a physical prelude cross-reference, but [UID:000116], [UID:000115], and [UID:000117] already carry the actual progress-helper routing.
- `by-memory/0x00494a90-0x00494b4b.ProgressBarRangeSetters.md`: no target-specific change required. It already has the correct non-emitting duplicate aggregate policy.
- `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`: no target-specific change required. It already states the band begins after [UID:000114] and contains [UID:0002PC].
- `auto-generated` state already matches the target recommendation: [UID:000114] is `not_reconstructable`; children emit only as empty markers through their class/source parents.

## Score Cap

Recommended cap for [UID:000114] is about `86/90`.

Reason to raise above current `84/88`: the exact boundary, padding, child routing, out-of-range hit-test placement, and no-code proof are now all supported by direct document and PE evidence.

Reason not to raise much higher: the source-facing field/helper names and final C++ eligibility belong to child pages, not to this aggregate. The raw progress helpers still lack proven function objects or direct routes, and the aggregate itself cannot become final source.

## Exact Future Implementation Checklist

1. Edit only the target doc unless the supervisor asks for support-doc polishing:
   - `COMPLETION:84 -> 86`
   - `CONFIDENCE:88 -> 90`
   - keep `CANONICAL_OWNER:NONE`
   - keep `RECONSTRUCTABLE:FALSE`
   - keep `EMITTER_UIDS:` blank
2. Add a "B003 source-routing recheck" evidence note with:
   - PE path/hash,
   - exact byte split,
   - rel32 route scan,
   - zero pointer hits to raw helper starts,
   - conclusion that [UID:000114] is a mixed physical index.
3. Add or tighten the no-code proof:
   - source bodies route through [UID:0002PB], [UID:000115], and [UID:000117],
   - padding spans remain ignored,
   - [UID:0002PC] is outside the target,
   - aggregate C++ would duplicate/mis-own child source.
4. Add [UID:000116] and [UID:0002PD] as explicit cross-references if not already present in the desired location.
5. Do not edit `by-memory/-coverage-report.md`; supervisor should apply the pending replacement rows below if accepted.
6. Validate the target and any optional support docs edited.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` from this B-agent report. The current manual coverage row is stale because it still shows [UID:000114] as `0x004949e0-0x00494bf7`, uses `82%`, and keeps stale nested child scores. If the supervisor applies this report, replace the [UID:000114] row with:

```text
    - [UID:000114][0x004949e0-0x00494b50.ControlPaneAndProgressBarPrelude](by-memory/0x004949e0-0x00494b50.ControlPaneAndProgressBarPrelude.md) 0x004949e0-0x00494b50 | mixed aggregate/index | ControlPaneAndProgressBarPrelude : ignored : 86% : strong : B003 2026-06-19 source-routing pass keeps this parentless/non-emitting physical prelude: exact ControlPane constructor child [UID:0002PB] covers 0x004949e0-0x00494a81 and emits through [UID:000038][ControlPane](by-class/ControlPane.md), padding covers 0x00494a81-0x00494a90, 0x00494ae7-0x00494af0, and 0x00494b4b-0x00494b50, raw/projected ProgressBarControlPane range-helper children [UID:000115] and [UID:000117] cover 0x00494a90-0x00494ae7 and 0x00494af0-0x00494b4b and emit through [UID:0000AW][ProgressBarControlPane](by-class/ProgressBarControlPane.md), the next source-bearing band starts at [UID:0002PD] 0x00494b50, and out-of-range ControlPane hit-test child [UID:0002PC] remains in that later band. Keep CANONICAL_OWNER:NONE, RECONSTRUCTABLE:FALSE, blank emitters/C++, and no aggregate code.
```

Recommended companion replacement for the stale nested constructor child row, if the supervisor updates the same local block:

```text
        - [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md) 0x004949e0-0x00494a81 | constructor | ControlPane::ControlPane : reconstructable : 85% : strong : Exact constructor child now routes through [UID:000038][ControlPane](by-class/ControlPane.md); live/PE evidence confirms 0xa1-byte boundary, 52 direct constructor callsites, direct callees 0x00544460 and 0x00544bd0, vtable stores at +0/+0xa0/+0xa4, control-type storage at +0xfe, default state writes at +0xf8/+0xfc/+0xff/+0x103, and fifteen bytes of 0xcc padding before the progress-bar helper bytes.
```

Recommended companion replacement for the stale [UID:0002PD] row if that local coverage block is refreshed during the same supervisor pass:

```text
        - [UID:0002PD][0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers](by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md) 0x00494b50-0x00494c80 | mixed aggregate/index | ControlFamilyStateVirtualHelpers : ignored : 88% : strong : B002 split repair keeps this parentless/non-emitting successor band: [UID:0003N1] at 0x00494b50 is the ProgressBarControlPane current-value setter with two PatchPane callers, modeled ControlPane state helpers cover 0x00494b80-0x00494c4a through [UID:000038][ControlPane](by-class/ControlPane.md), [UID:0002PC] 0x00494bf0-0x00494bf7 is the out-of-range hit-test suppression accessor, padding spans are exact, raw [UID:0003N9] 0x00494c50-0x00494c80 remains a ControlPane-owned no-xref draw-state helper with blank C++, and the aggregate itself has no source-level owner or emitted code.
```

Recommended companion replacement for the stale [UID:0002PC] row if the hit-test row is updated:

```text
    - [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md) 0x00494bf0-0x00494bf7 | method | ControlPane::IgnoresHitTesting : reconstructable : 85% : strong : Exact ControlPane hit-test suppression accessor in the [UID:0002PD] successor band; bytes are mov al,[ecx+0x104]; ret, field +0x104 is the ignore-hit-testing byte, no callees, sole rel32 caller at 0x0049fb7f uses it as a post-rectangle-test skip gate, and source ownership routes through [UID:000038][ControlPane](by-class/ControlPane.md), not the [UID:000114] prelude aggregate.
```

## Validation Commands Needed

No validators were run because this is report-only and no by-* docs were edited.

Run these if the target implementation is accepted:

> Executable block R001 was removed from this report and preserved verbatim in [000114-ControlPaneAndProgressBarPrelude-source-routing-removed.md](000114-ControlPaneAndProgressBarPrelude-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If optional support docs are edited, also run:

> Executable block R002 was removed from this report and preserved verbatim in [000114-ControlPaneAndProgressBarPrelude-source-routing-removed.md](000114-ControlPaneAndProgressBarPrelude-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

After coverage is updated by the supervisor, run the normal scoped coverage/report refresh if requested by the supervisor workflow.

## IDA Rename/Type/Comment Recommendations

High-confidence safe names/comments:

- `sub_4949E0` -> `ControlPane__ctor` or `ControlPane_ctor`.
- Comment `0x004949e0-0x00494a81`: exact `ControlPane` constructor child; [UID:000114] is only a physical parent index.
- Comment padding:
  - `0x00494a81-0x00494a90`: 15 bytes `0xcc`.
  - `0x00494ae7-0x00494af0`: 9 bytes `0xcc`.
  - `0x00494b4b-0x00494b50`: 5 bytes `0xcc`.
- `sub_494BF0` -> `ControlPane_IgnoresHitTesting` or `ControlPane_IsHitTestIgnored`; prefer `IgnoresHitTesting` to match current docs and paired setter.
- Struct field comment/type candidates:
  - `ControlPane +0xfe`: `uint8_t m_controlType`.
  - `ControlPane +0x104`: `uint8_t m_ignoreHitTesting`.

Medium-confidence raw helper names, do not force function creation unless IDA policy allows projected private helper starts:

- `0x00494a90`: `ProgressBarControlPane_SetRangeStart_raw` / source-facing `SetRangeStart(short value)`.
- `0x00494af0`: `ProgressBarControlPane_SetRangeEnd_raw` / source-facing `SetRangeEnd(short value)`.
- `ProgressBarControlPane +0xf8`: `int16_t m_rangeStart` / `m_minValue`.
- `ProgressBarControlPane +0xfa`: `int16_t m_currentValue`.
- `ProgressBarControlPane +0xfc`: `int16_t m_rangeEnd` / `m_maxValue`.
- Add comments that both raw starts currently have no IDA function object, no direct xrefs/callers, no rel32 hits, and no VA/RVA pointer hits in the PE scan.

Do not add an IDA name or source owner for [UID:000114] as a function. The only useful label is the documentation/index label `ControlPaneAndProgressBarPrelude`.

## Open Questions Revisited

- Exact constructor child? Resolved: [UID:0002PB] `0x004949e0-0x00494a81`.
- Raw ProgressBar helpers? Resolved as [UID:000115] and [UID:000117], owned by `ProgressBarControlPane`, not direct routes but retained/projected private helper bytes.
- Padding and split? Resolved with PE byte proof: 15/9/5 bytes of `0xcc`; successor starts at `0x00494b50`.
- ControlPane hit-test out-of-range child? Resolved: [UID:0002PC] is outside target and inside [UID:0002PD].
- Owner/source placement? Resolved: aggregate owner `NONE`; child owners split between `ControlPane` and `ProgressBarControlPane`.
- Missing exact children? No new child pages needed for [UID:000114]. Existing exact children cover all non-padding bytes.
- Aggregate C++? Resolved no-code. Formal C++ must remain blank.
- Coverage? Manual coverage row is stale and should be replaced by the exact pending text above; do not edit it in this report-only pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/000114-ControlPaneAndProgressBarPrelude-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"000114"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000114-ControlPaneAndProgressBarPrelude-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/000114-ControlPaneAndProgressBarPrelude-source-routing.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000114"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
