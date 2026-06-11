# 000260 ObjectPaneReadOnlyData Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: READY FOR SUPERVISOR REVIEW. [UID:000260][0x00620284-0x00620c74.ObjectPaneReadOnlyData](by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md) is now an executed parent-blank, non-emitting mixed `.rdata` inventory.
- Final disposition: executed split complete for B001-035. Exact child pages now carry per-class/per-resource ownership decisions. The broad aggregate is `COMPLETION:90`, `CONFIDENCE:92`, `RECONSTRUCTABLE:FALSE`, `AUTOGEN_PARENT_UID:` blank.
- Required action: supervisor review only. Do not assign `000260` to `ObjectPane` or any single source parent. Remaining unassigned exact children should be revisited only after their direct class/file parents meet the strict `85/85` gate.
- Confidence: high for exact range boundaries and aggregate disposition; high for the applied assignments; medium-high for unassigned children because their remaining reasons are direct parent-score gates or mixed constant ownership, not unresolved IDA boundaries.
- Supervisor review: accepted on 2026-06-10 after a 30-file targeted dry-run validator pass returned exit code `0` for every checked target, child, parent, and coverage file. The report is confirmed in `research/executed` with no active duplicate left in the research folder.

## Supporting Research

## Target

- Target UID: `000260`.
- Target path: `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`.
- Source queue/report row: supervisor assignment B001-035.
- Initial supervisor classification: broad ObjectPane read-only data island with mixed vtable/resource-string/constants ownership and missing exact child split.
- Before state: `000260` was `86/91`, `RECONSTRUCTABLE:TRUE`, parent blank, and still depended on obsolete grouped child mappings `0002SL`, `0002SM`, and `0002SN`.
- After state: `000260` is `90/92`, `RECONSTRUCTABLE:FALSE`, parent blank, with exact children through `0x00620c74`.

## Executive Recommendation

Keep `000260` as a by-memory inventory only. IDA proves the range crosses `ObjectList`, base `ObjectPane`, Static/Item/Flying/Attached/Effect object panes, BowGauge/HitBar/DamageNumber/ObjectInfo overlay panes, `Motion`, `LivingObjectPane::BoxRotator`, `LivingObjectPane`, `LightingObjectPane`, `SoundObjectPane`, resource strings/constants, and a terminal `OptionPane` RTTI dword. No single class or source file directly owns that whole range.

The old grouped children were retired instead of kept as parent-blank pages because the new exact pages now provide the useful inventory without preserving invalid boundaries:

- `0002SL` old path `0x00620344-0x006205fc.StaticItemFlyingAttachedObjectPaneVtableData.md`.
- `0002SM` old path `0x006205fc-0x00620954.EffectGaugeDamageInfoObjectPaneVtableData.md`.
- `0002SN` old path `0x00620954-0x00620b90.MotionLivingLightSoundObjectPaneVtableData.md`.

Validator `--mode documented --remove-missing --uid-only --apply` removed those three stale UID mappings. Follow-up dry-run/reference checks did not report those old grouped targets.

## Supervisor Active Recheck

- Supervisor correction at 18:08 required stopping further shared-doc expansion and correcting this report before handoff.
- Shared split work had already been performed before this report rewrite: exact child pages were created/repaired, parent/resource pages were updated, targeted validators with `--apply` ran, and the old grouped UID mappings were removed.
- Current report state now reflects the executed split. No current impediment remains for B001-035 handoff.

## Inference Research Guidance Check

- `by-structure.md` requires mixed memory aggregates to remain parent blank when exact source-bearing children exist. That rule drives `000260` and `0002SO` to `RECONSTRUCTABLE:FALSE`.
- `inference_research.md` warns that physical adjacency in `.rdata` is weak ownership evidence. Ownership decisions below use RTTI/vtable names, constructor/destructor vptr stores, string/constant xrefs, and direct parent score gates.
- Existing grouped child docs were treated as hypotheses. IDA contradicted their boundaries, so the old grouped pages were retired rather than preserved as source-bearing children.

## Evidence Standards Used

- IDA MCP facts: active IDB `NexusTK.exe`, base `0x400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`; `initialize`, `tools/list`, `idb_meta`, and compact `py_eval` succeeded.
- Documentation evidence: `by-structure.md`, `Agent-B001/inference_research.md`, `000260`, generated/manual memory coverage, existing resource child pages, candidate class/file parent docs, and nearby executable aggregate docs.
- Validator evidence: UID registration, documented missing cleanup, targeted file-mode apply scans, reference-only aggregate dry run, stale UID text scans.

## IDA MCP Facts

### Exact Data Boundaries

| Range | Owner / item | Key IDA anchors |
| --- | --- | --- |
| `0x00620284-0x00620294` | `ObjectList` RTTI/vtable | RTTI at `0x00620284`; vtable at `0x00620288` |
| `0x00620294-0x00620340` | base `ObjectPane` RTTI/vtables | RTTI at `0x00620294`; tables at `0x00620298`, `0x00620308`, `0x00620338` |
| `0x00620340-0x006203ec` | `StaticObjectPane` RTTI/vtables | RTTI at `0x00620340`; stores from `0x00537926/2c/36` |
| `0x006203ec-0x00620498` | `ItemObjectPane` RTTI/vtables | RTTI at `0x006203ec`; refs from item/flying constructor/destructor paths |
| `0x00620498-0x00620544` | `FlyingObjectPane` RTTI/vtables | RTTI at `0x00620498`; stores from `0x00537d1c/22/2c` |
| `0x00620544-0x006205f8` | `AttachedObjectPane` RTTI/vtables | RTTI at `0x00620544`; stores from `0x005380d5/38132` and adjusted stores |
| `0x006205f8-0x006206ac` | `EffectObjectPane` RTTI/vtables | RTTI at `0x006205f8`; refs from `0x005387e9`, `0x00538880`, `0x0053d125` |
| `0x006206ac-0x00620734` | `BowGaugeObjectPane` RTTI/vtables | RTTI at `0x006206ac`; stores from `0x00538beb/f1/fb` |
| `0x00620734-0x006207e8` | `HitBarObjectPane` RTTI/vtables | RTTI at `0x00620734`; refs from `0x00538d93`, `0x00538e10`, `0x00538e40`, `0x0053d265` |
| `0x006207e8-0x0062089c` | `DamageNumberObjectPane` RTTI/vtables | RTTI at `0x006207e8`; refs from `0x0053927d`, `0x00539360`, `0x0053d085` |
| `0x0062089c-0x00620950` | `ObjectInfoObjectPane` RTTI/vtables | RTTI at `0x0062089c`; stores from `0x005395df/e5/ef` |
| `0x00620950-0x0062096c` | `Motion` RTTI/vtables | RTTI at `0x00620950`; refs from `0x00539c11`, `0x00539e47` |
| `0x0062096c-0x00620978` | `LivingObjectPane::BoxRotator` RTTI/vtable | RTTI at `0x0062096c`; refs from `0x0053a17c`, `0x0053a3cd` |
| `0x00620978-0x00620a38` | `LivingObjectPane` RTTI/vtables | RTTI at `0x00620978`; refs from `0x0053a14a`, `0x0053a39b`, `0x0053a5c5`, `0x0053d455` |
| `0x00620a38-0x00620ae4` | `LightingObjectPane` RTTI/vtables | RTTI at `0x00620a38`; refs from `0x0053c61f`, `0x0053c66b`, `0x0053d3ab` |
| `0x00620ae4-0x00620b90` | `SoundObjectPane` RTTI/vtables | RTTI at `0x00620ae4`; refs from `0x0053ca3c`, `0x0053caec`, `0x0053d693` |
| `0x00620b90-0x00620bc0` | BowGauge resources | `BGAUGE.EPF` xref `0x00538cbc`; `BGAUGE.pal` xref `0x00538cc8` |
| `0x00620bc0-0x00620bdc` | dead-sign resource | `DEADSIGN.EPF` xref `0x00539075` |
| `0x00620bdc-0x00620c10` | damage-number resources | `%d`, `DMGNUM.EPF`, `DMGNUM.PAL` xrefs at `0x005392e3`, `0x00539551`, `0x00539563` |
| `0x00620c10-0x00620c70` | overlay numeric constants | xrefs at `0x00539391`, `0x00538235`, `0x00538421`, `0x00538566`, `0x0055b821`, `0x0053ccc9`, `0x0053cd4b` |
| `0x00620c70-0x00620c74` | `OptionPane` RTTI boundary | `0x00620c70 -> ??_R4OptionPane@@6B@`; next vtable starts `0x00620c74` |

### Negative IDA Facts

- No constructor, destructor, vtable family, resource consumer, or class-source family spans the whole `0x00620284-0x00620c74` range.
- `0x00620c70` is `OptionPane` RTTI, not ObjectPane-family data.
- The former grouped pages missed or over-included boundary RTTI dwords: Static at `0x00620340`, Effect at `0x006205f8`, and Motion at `0x00620950`.

## Function / Child Inventory

| Range | UID / path | Role | State | Direct parent |
| --- | --- | --- | --- | --- |
| `0x00620284-0x00620c74` | [UID:000260][0x00620284-0x00620c74.ObjectPaneReadOnlyData](by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md) | broad mixed inventory | `90/92`, `FALSE`, blank | none |
| `0x00620284-0x00620294` | [UID:0002OF][0x00620284-0x00620294.ObjectListVtableData](by-memory/0x00620284-0x00620294.ObjectListVtableData.md) | `ObjectList` vtable | `85/92`, true, blank | unassigned; class/file `84/88` |
| `0x00620294-0x00620340` | [UID:0002SK][0x00620294-0x00620340.ObjectPaneVtableData](by-memory/0x00620294-0x00620340.ObjectPaneVtableData.md) | base `ObjectPane` vtables | `85/89`, true, blank | unassigned; class `84/86` |
| `0x00620340-0x006203ec` | [UID:00034X][0x00620340-0x006203ec.StaticObjectPaneVtableData](by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md) | `StaticObjectPane` vtables | `85/88`, true, blank | unassigned; class/file below gate |
| `0x006203ec-0x00620498` | [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md) | `ItemObjectPane` vtables | `85/88`, true, blank | unassigned; class `74/86` |
| `0x00620498-0x00620544` | [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md) | `FlyingObjectPane` vtables | `86/89`, true | [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md) |
| `0x00620544-0x006205f8` | [UID:000350][0x00620544-0x006205f8.AttachedObjectPaneVtableData](by-memory/0x00620544-0x006205f8.AttachedObjectPaneVtableData.md) | `AttachedObjectPane` vtables | `85/88`, true, blank | unassigned; class `82/88` |
| `0x006205f8-0x006206ac` | [UID:000351][0x006205f8-0x006206ac.EffectObjectPaneVtableData](by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md) | `EffectObjectPane` vtables | `85/88`, true, blank | unassigned; class/file gate fail |
| `0x006206ac-0x00620734` | [UID:000352][0x006206ac-0x00620734.BowGaugeObjectPaneVtableData](by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md) | `BowGaugeObjectPane` vtables | `86/89`, true | [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md) |
| `0x00620734-0x006207e8` | [UID:000353][0x00620734-0x006207e8.HitBarObjectPaneVtableData](by-memory/0x00620734-0x006207e8.HitBarObjectPaneVtableData.md) | `HitBarObjectPane` vtables | `86/89`, true | [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md) |
| `0x006207e8-0x0062089c` | [UID:000354][0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData](by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md) | `DamageNumberObjectPane` vtables | `85/88`, true, blank | unassigned; class `82/88` |
| `0x0062089c-0x00620950` | [UID:000355][0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData](by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md) | `ObjectInfoObjectPane` vtables | `85/88`, true, blank | unassigned; class `82/88` |
| `0x00620950-0x0062096c` | [UID:000356][0x00620950-0x0062096c.MotionVtableData](by-memory/0x00620950-0x0062096c.MotionVtableData.md) | `Motion` vtables | `85/88`, true | [UID:00008R][Motion](by-class/Motion.md) |
| `0x0062096c-0x00620978` | [UID:000357][0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData](by-memory/0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData.md) | `BoxRotator` vtable | `85/88`, true, blank | unassigned; class `82/84` |
| `0x00620978-0x00620a38` | [UID:000358][0x00620978-0x00620a38.LivingObjectPaneVtableData](by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md) | `LivingObjectPane` vtables | `85/88`, true, blank | unassigned; class/file confidence below gate |
| `0x00620a38-0x00620ae4` | [UID:000359][0x00620a38-0x00620ae4.LightingObjectPaneVtableData](by-memory/0x00620a38-0x00620ae4.LightingObjectPaneVtableData.md) | `LightingObjectPane` vtables | `85/88`, true, blank | unassigned; class/file completion below gate |
| `0x00620ae4-0x00620b90` | [UID:00035A][0x00620ae4-0x00620b90.SoundObjectPaneVtableData](by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md) | `SoundObjectPane` vtables | `85/88`, true, blank | unassigned; class/file below gate |
| `0x00620b90-0x00620c70` | [UID:0002SO][0x00620b90-0x00620c70.ObjectPaneResourceStringsAndOverlayConstants](by-memory/0x00620b90-0x00620c70.ObjectPaneResourceStringsAndOverlayConstants.md) | mixed resource/constant parent | `89/91`, `FALSE`, blank | none |
| `0x00620b90-0x00620bc0` | [UID:0002YQ][0x00620b90-0x00620bc0.BowGaugeResourceStrings](by-memory/0x00620b90-0x00620bc0.BowGaugeResourceStrings.md) | BowGauge strings | `88/92`, true | [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md) |
| `0x00620bc0-0x00620bdc` | [UID:0002YR][0x00620bc0-0x00620bdc.DeadSignResourceString](by-memory/0x00620bc0-0x00620bdc.DeadSignResourceString.md) | dead-sign string | `85/90`, true | [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md) |
| `0x00620bdc-0x00620c10` | [UID:0002YS][0x00620bdc-0x00620c10.DamageNumberResourceStrings](by-memory/0x00620bdc-0x00620c10.DamageNumberResourceStrings.md) | damage-number strings | `85/91`, true, blank | unassigned; class `82/88` |
| `0x00620c10-0x00620c70` | [UID:0002YT][0x00620c10-0x00620c70.ObjectOverlayNumericConstants](by-memory/0x00620c10-0x00620c70.ObjectOverlayNumericConstants.md) | overlay constants | `86/89`, true, blank | unassigned; mixed xrefs |
| `0x00620c70-0x00620c74` | [UID:00035B][0x00620c70-0x00620c74.OptionPaneRttiBoundaryData](by-memory/0x00620c70-0x00620c74.OptionPaneRttiBoundaryData.md) | `OptionPane` RTTI boundary | `85/88`, true, blank | unassigned; class `84/82` |

## Direct Xref / Caller Inventory

| Address / item | Xref / caller evidence | Meaning |
| --- | --- | --- |
| `0x0062049c/0x0062050c/0x0062053c` | stores from `0x00537d1c/22/2c` | `FlyingObjectPane` vtable ownership |
| `0x006206b0/0x006206fc/0x0062072c` | stores from `0x00538beb/f1/fb` | `BowGaugeObjectPane` vtable ownership |
| `0x00620738/0x006207b0/0x006207e0` | refs from `0x00538d93`, `0x00538e10`, `0x00538e40`, `0x0053d265` | `HitBarObjectPane` vtable ownership |
| `0x00620954/0x00620964` | refs from `0x00539c11`, `0x00539e47` | `Motion` vtable ownership |
| `0x00620b90/0x00620ba8` | `0x00538cbc`, `0x00538cc8` | BowGauge resource literals |
| `0x00620bc0` | `0x00539075` | HitBar/dead-sign resource literal |
| `0x00620bdc/0x00620be0/0x00620bf8` | `0x005392e3`, `0x00539551`, `0x00539563` | DamageNumber literals |
| `0x00620c64/68/6c` | overlay helper refs including `0x00539391`, `0x00538235`, `0x00538421`, `0x00538566`, `0x0055b821`, `0x0053ccc9`, `0x0053cd4b` | mixed overlay constants |

## Documentation Evidence And IDA Status

- Existing docs confirmed by IDA: class labels for the vtable families, BowGauge resource children, HitBar resource use, Motion vtable refs, and the OptionPane boundary dword.
- Existing docs repaired: `000260` and `0002SO` are now non-emitting containers; `0002SK` now ends at `0x00620340`; `0002YR` is assigned to HitBarObjectPane; old grouped pages `0002SL`, `0002SM`, `0002SN` are retired.
- Related docs updated to remove stale grouped-page links: Flying/BowGauge/HitBar/Motion class docs and the target-adjacent executable aggregate pages listed under Changed Files.

## Ranked Ownership Analysis

### 1. Exact per-class/per-resource children with parent-blank aggregate

- Evidence for: clean RTTI/vtable boundaries, class-specific vptr-store xrefs, exact resource literal xrefs, and parent score gates.
- Evidence against: several direct class/file parents still do not clear `85/85`, so not every exact child can be assigned yet.
- Decision: accepted and executed.

### 2. Keep old grouped vtable pages

- Evidence for: they described useful physical clusters.
- Evidence against: they crossed owner boundaries and missed leading RTTI dwords. Exact children supersede them without preserving invalid mappings.
- Decision: rejected; retired through validator missing-entry cleanup.

### 3. Assign broad `000260` to `ObjectPane` or a new source file

- Evidence for: physical island starts in the ObjectPane family.
- Evidence against: range also contains ObjectList, Motion/Living/Lighting/Sound, resource strings/constants, and `OptionPane` RTTI. Vtables are compiler output from many class declarations, not one hand-authored source array.
- Decision: rejected.

## Negative Evidence Summary

- Consumer/read xrefs alone were not used as ownership proof. They were weighed against constructor/destructor vptr stores and source-parent score gates.
- File parents that clear the gate were not used to bypass below-gate direct class pages. Example: `AttachedObjectPane` file is `85/85`, but `AttachedObjectPane`, `DamageNumberObjectPane`, and `ObjectInfoObjectPane` classes remain below gate.
- The `OptionPane` file clears `91/85`, but `OptionPane` class is `84/82`, so `00035B` remains unassigned.
- `0002YT` remains unassigned because xrefs span mixed overlay helpers and no single source declaration owner is proven.

## Final Recommendation

- Exact changes applied: split/repair `000260` into exact child pages, retire stale grouped UIDs, convert `000260` and `0002SO` to parent-blank `RECONSTRUCTABLE:FALSE`, and update direct references to exact child pages.
- Exact parent assignments applied:
  - `00034Z` FlyingObjectPane vtable data -> `000057` FlyingObjectPane.
  - `000352` BowGaugeObjectPane vtable data -> `000011` BowGaugeObjectPane.
  - `000353` HitBarObjectPane vtable data -> `000067` HitBarObjectPane.
  - `000356` Motion vtable data -> `00008R` Motion.
  - `0002YQ` BowGauge resource strings remains assigned to `000011`.
  - `0002YR` DeadSign resource string -> `000067` HitBarObjectPane.
- Exact items left unassigned: `0002OF`, `0002SK`, `00034X`, `00034Y`, `000350`, `000351`, `000354`, `000355`, `000357`, `000358`, `000359`, `00035A`, `0002YS`, `0002YT`, and `00035B`, for the gate or mixed-owner reasons listed in the inventory table.
- Exact future work outside this assignment: improve the below-gate direct class/file parents before assigning their exact vtable/resource children; separately audit the broader `000261` Option/Macro/Profile read-only island if OptionPane boundary ownership needs deeper treatment.

## Follow-Up Actions

- Supervisor actions: review and accept the executed split; do not move this report to `executed` until supervisor review completes.
- A-agent actions: parent repair candidates are `ObjectList`, `ObjectPane`, `StaticObjectPane`, `ItemObjectPane`, `AttachedObjectPane`, `EffectObjectPane`, `DamageNumberObjectPane`, `ObjectInfoObjectPane`, `LivingObjectPane__BoxRotator`, `LivingObjectPane`, `LightingObjectPane`, `SoundObjectPane`, and `OptionPane`.
- B001 future research actions: none for current `000260` target unless supervisor reopens a specific remaining unassigned child.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `000260`, `0002SO`, and assigned children; medium-high for unassigned exact children because the binary boundaries are strong but direct-parent docs still need separate repair.
- Remaining uncertainty: final original source declaration details for several below-gate classes and the exact owner for mixed overlay numeric constants.

## Validator Results

- UID registration already applied for new children: `python .\tools\validator.py --mode file --file <new child> --uid-only --apply --lock-timeout 60`; assigned `00034X` through `00035B`.
- Old grouped UID cleanup dry run: `python .\tools\validator.py --mode documented --remove-missing --uid-only --lock-timeout 60`; result before apply: `missing: 3`, `remove_missing: 3`, exactly `0002SL`, `0002SM`, `0002SN`.
- Old grouped UID cleanup apply: `python .\tools\validator.py --mode documented --remove-missing --uid-only --apply --lock-timeout 60`; result: `scanned markdown files: 4076`, `ok: 4076`, removed `0002SL`, `0002SM`, `0002SN`, updated project stats.
- Targeted file-mode apply loop: `python .\tools\validator.py --mode file --file <file> --apply --lock-timeout 60` over the changed aggregate, exact children, resource children, class docs, target-adjacent executable docs, and `by-memory/-coverage-report.md`; result: every file command exited `0`. The validator rebuilt autogen registry state and refreshed generated coverage/projected stats as normal side effects.
- Post-apply stale UID text scan: `rg "\[UID:0002S[L-N]\]|0x00620344-0x006205fc|0x006205fc-0x00620954|0x00620954-0x00620b90" by-memory by-class/FlyingObjectPane.md by-class/BowGaugeObjectPane.md by-class/HitBarObjectPane.md by-class/Motion.md`; result: no hits.
- Aggregate reference-only dry run after supervisor interrupt: `python .\tools\validator.py --mode file --file by-memory\0x00620284-0x00620c74.ObjectPaneReadOnlyData.md --reference-only --lock-timeout 15`; result: first attempt completed, `reference phase: True`, no `0002SL`, `0002SM`, `0002SN`, missing-target, or reference-missing output.
- Documented missing cleanup recheck after supervisor interrupt: `python .\tools\validator.py --mode documented --remove-missing --uid-only --lock-timeout 20`; result: scans completed with `scanned markdown files: 4076`, `ok: 4076`, no old grouped UID lines. A local wrapper returned nonzero only because its generic `error` pattern matched normal `Error.md` `ok` rows; the validator summaries did not show missing old grouped mappings.
- Validator lock state: available for the aggregate reference-only scan; documented rechecks also ran rather than timing out.

## Changed Files

- Created exact child pages:
  - [UID:00034X][0x00620340-0x006203ec.StaticObjectPaneVtableData](by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md)
  - [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md)
  - [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md)
  - [UID:000350][0x00620544-0x006205f8.AttachedObjectPaneVtableData](by-memory/0x00620544-0x006205f8.AttachedObjectPaneVtableData.md)
  - [UID:000351][0x006205f8-0x006206ac.EffectObjectPaneVtableData](by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md)
  - [UID:000352][0x006206ac-0x00620734.BowGaugeObjectPaneVtableData](by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md)
  - [UID:000353][0x00620734-0x006207e8.HitBarObjectPaneVtableData](by-memory/0x00620734-0x006207e8.HitBarObjectPaneVtableData.md)
  - [UID:000354][0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData](by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md)
  - [UID:000355][0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData](by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md)
  - [UID:000356][0x00620950-0x0062096c.MotionVtableData](by-memory/0x00620950-0x0062096c.MotionVtableData.md)
  - [UID:000357][0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData](by-memory/0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData.md)
  - [UID:000358][0x00620978-0x00620a38.LivingObjectPaneVtableData](by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md)
  - [UID:000359][0x00620a38-0x00620ae4.LightingObjectPaneVtableData](by-memory/0x00620a38-0x00620ae4.LightingObjectPaneVtableData.md)
  - [UID:00035A][0x00620ae4-0x00620b90.SoundObjectPaneVtableData](by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md)
  - [UID:00035B][0x00620c70-0x00620c74.OptionPaneRttiBoundaryData](by-memory/0x00620c70-0x00620c74.OptionPaneRttiBoundaryData.md)
- Repaired exact child/range pages:
  - [UID:0002SK][0x00620294-0x00620340.ObjectPaneVtableData](by-memory/0x00620294-0x00620340.ObjectPaneVtableData.md)
  - [UID:0002YR][0x00620bc0-0x00620bdc.DeadSignResourceString](by-memory/0x00620bc0-0x00620bdc.DeadSignResourceString.md)
- Modified aggregate/resource/manual coverage pages:
  - [UID:000260][0x00620284-0x00620c74.ObjectPaneReadOnlyData](by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md)
  - [UID:0002SO][0x00620b90-0x00620c70.ObjectPaneResourceStringsAndOverlayConstants](by-memory/0x00620b90-0x00620c70.ObjectPaneResourceStringsAndOverlayConstants.md)
  - [by-memory/-coverage-report](by-memory/-coverage-report.md)
- Modified parent/reference docs:
  - [FlyingObjectPane](by-class/FlyingObjectPane.md)
  - [BowGaugeObjectPane](by-class/BowGaugeObjectPane.md)
  - [HitBarObjectPane](by-class/HitBarObjectPane.md)
  - [Motion](by-class/Motion.md)
  - [0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md)
  - [0x0053ca20-0x0053ce3c.SoundObjectPaneCore](by-memory/0x0053ca20-0x0053ce3c.SoundObjectPaneCore.md)
  - [0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md)
  - [0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor](by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md)
  - [0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor](by-memory/0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md)
  - [0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors](by-memory/0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors.md)
- Retired validator mappings:
  - `0002SL` old grouped Static/Item/Flying/Attached page.
  - `0002SM` old grouped Effect/Gauge/Damage/Info page.
  - `0002SN` old grouped Motion/Living/Light/Sound page.
- Validator-generated/project-level side effects:
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/-ag-class-coverage.md`
  - `auto-generated/-ag-file-coverage.md`
  - `auto-generated/-ag-global-coverage.md`
  - `auto-generated/-ag-item-coverage.md`
  - `auto-generated/-ag-type-coverage.md`
  - `project-level/-auto-completion-stats.md`
- Modified research report:
  - `tools/leaser/Agents/Agent-B001/research/000260-ObjectPaneReadOnlyData.md`



