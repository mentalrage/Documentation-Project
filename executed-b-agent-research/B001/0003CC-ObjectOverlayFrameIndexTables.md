** TARGET-REPORT-UID:0003CC **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0003CC ObjectOverlayFrameIndexTables Ownership Research

Revision: B001-057 ownership inference, 2026-06-12

## Finalized Report / Current Recommendation

- Target UID/path: [UID:0003CC] `by-memory/0x00620c10-0x00620c64.ObjectOverlayFrameIndexTables.md`
- Current recommendation: assign this child to existing [UID:0000HJ] `by-file/AttachedObjectPane.md` as file-local attached-overlay static constant data. Do not assign it to [UID:00003F] `DamageNumberObjectPane` or any narrower class, because live IDA still shows no direct table consumer and the nearby class methods do not read the table.
- Final disposition: no split, no rename required, keep `RECONSTRUCTABLE:TRUE`, keep current `86/91` unless the applying agent wants to raise completion for the new B001 evidence. The actionable repair is `AUTOGEN_PARENT_UID:0000HJ`.
- Required action: supervisor/A-agent may update the target page parent and row text, then run validator for the target page. B001 did not edit the by-memory target or `by-memory/-coverage-report.md`.
- Confidence: `82/100` for `AttachedObjectPane.cpp` file-level ownership; `97/100` for bytes/range/unique-pattern facts; `96/100` for no direct xrefs/names; `70/100` for exact original declaration spelling/class intent. This is strong enough for a file-level parent recommendation because the table is a structured source-authored block emitted in the attached-overlay read-only contribution, but not strong enough for class-level ownership.

## Supporting Research

## Target

- Target UID: `0003CC`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00620c10-0x00620c64.ObjectOverlayFrameIndexTables.md`
- Source queue/report row: `Supervisor_notes.md` Batch `B001-057`, `reviewed-85-but-ownership-unknown-under-review`
- Current scores and parent state: `COMPLETION:86`, `CONFIDENCE:91`, `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:` blank
- Current documented role: three seven-dword value runs after `DMGNUM.PAL` and before the scalar overlay constants
- Current coverage row state: parent blank because A001 Batch280 could not prove direct ownership

## Executive Recommendation

Best current inference: route [UID:0003CC] to [UID:0000HJ] `AttachedObjectPane` as source-file-owned, file-local attached-overlay constant data. This is not a DamageNumber class assignment. The evidence supports the attached-overlay source file because the emitted `.rdata` contribution is physically and semantically inside the attached overlay resource/constant tail: DamageNumber resource literals immediately precede it, the DamageNumber animation scalar immediately follows it, the broader file already owns HitBar/DamageNumber/ObjectInfo attached overlays, and MapPane caller decompilation shows overlapping combat-overlay immediate constants without producing a table data reference.

The practical distinction is important:

- `DamageNumberObjectPane` is too narrow. Its constructor, animation update, bounds computation, and render body do not read the table, and its digit rendering uses `DMGNUM.EPF` frame indices derived from digit characters plus style offsets.
- `MapPane` is a consumer/allocation side. It allocates DamageNumber/ObjectInfo overlays and uses immediate values overlapping the table (`0xE0`, `0xF5`) in packet handlers, but those are compiled immediates, not data references to `0x00620c10`.
- `AttachedObjectPane.cpp` is the best source-owner level because it is the reviewed file root for attached combat/object overlays and can own file-local static constants that do not resolve to a narrower live class consumer.

Do not split the target into three seven-dword child pages. Each run has no independent xrefs or names, and splitting would produce three weaker no-owner children while losing the table-level pattern.

## Supervisor Active Recheck

Supervisor assigned B001-057 to perform deeper ownership inference, not just restate A001's uncertainty. This pass rechecked the target with live IDA MCP, expanded beyond the immediate BowGauge/HitBar/DamageNumber functions into MapPane allocation/packet callers and ObjectInfo construction, compared proposed source-file candidates, and reviewed the existing by-file/by-class source root docs.

No split repair was required before final reporting. The existing exact range `0x00620c10-0x00620c64` is correct, and the scalar successor at `0x00620c64` remains a separate DamageNumber child.

## Inference Research Guidance Check

Applied the B001 inference standard:

- IDA facts are separated from documentation evidence and inference.
- Negative evidence is not treated as proof of no source owner. The no-xref result prevents class-level ownership but does not eliminate file-local static data ownership.
- Adjacency alone is not used as the final reason. The recommendation uses combined evidence: unique structured data, link/rdata contribution position, surrounding direct owners, semantic overlap with attached combat overlay packet handlers, absence of competing owner evidence, and existing source-root gating.
- Existing documentation was treated as a hypothesis. A001's "do not attach merely from adjacency" warning is still correct; this report recommends file-level assignment only after broader IDA review and candidate rejection.

## Evidence Standards Used

- IDA MCP tools used: `idb_list`, `get_bytes`, `get_int`, `xrefs_to`, `entity_query`, `find_bytes`, `search_text`, and `decompile`.
- Documentation reviewed: target page, numeric/resource parent pages, `ObjectPaneReadOnlyData`, `ObjectOverlayPanes`, `AttachedObjectPane`, `BowGaugeObjectPane`, `ObjectPane`, `MapPane`, `DamageNumberObjectPane`, `HitBarObjectPane`, `ObjectInfoObjectPane`, coverage rows, supervisor row, and proposed source-tree references.
- Evidence strength: direct xrefs would have justified a class parent; none exist. The file-level recommendation depends on rdata/source-contribution and source-scope inference, so confidence is capped below "very strong".

## IDA MCP Facts

### Data/table facts

Live IDA MCP `get_bytes` on `0x00620b90-0x00620c74` confirms the local order:

| Range / address | Bytes / values | Meaning |
| --- | --- | --- |
| `0x00620b90` | UTF-16 `BGAUGE.EPF` | BowGauge resource string |
| `0x00620ba8` | UTF-16 `BGAUGE.pal` | BowGauge resource string |
| `0x00620bc0` | UTF-16 `DEADSIGN.EPF` | HitBar dead-sign string |
| `0x00620bdc` | ANSI `%d` | DamageNumber format string |
| `0x00620be0` | UTF-16 `DMGNUM.EPF` | DamageNumber digit frame resource |
| `0x00620bf8` | UTF-16 `DMGNUM.PAL` | DamageNumber palette resource |
| `0x00620c10-0x00620c2c` | `0xf1, 0xf3, 0xf5, 0xf7, 0xf1, 0xf3, 0xf5` | first seven-dword run |
| `0x00620c2c-0x00620c48` | `0x2f, 0x2e, 0x2d, 0x2c, 0x2f, 0x2e, 0x2d` | second seven-dword run |
| `0x00620c48-0x00620c64` | `0xe0, 0xe1, 0xe2, 0xe3, 0xe0, 0xe1, 0xe2` | third seven-dword run |
| `0x00620c64` | `0x3d072b02` | DamageNumber animation step scalar |
| `0x00620c68` | `0x3dcccccd` | shared/folded `0.1f` scalar |
| `0x00620c6c` | `0x46fffe00` | SoundObjectPane threshold scalar |
| `0x00620c70` | RTTI locator dword before `0x00620c74` | OptionPane boundary |

`find_bytes` confirms uniqueness:

- Full 84-byte table pattern occurs exactly once, at `0x00620c10`.
- Run 1 occurs exactly once, at `0x00620c10`.
- Run 2 occurs exactly once, at `0x00620c2c`.
- Run 3 occurs exactly once, at `0x00620c48`.

### Xref facts

Fresh `xrefs_to` on every dword-aligned table element reports zero direct xrefs:

- `0x00620c10`, `0x00620c14`, `0x00620c18`, `0x00620c1c`, `0x00620c20`, `0x00620c24`, `0x00620c28`: no xrefs.
- `0x00620c2c`, `0x00620c30`, `0x00620c34`, `0x00620c38`, `0x00620c3c`, `0x00620c40`, `0x00620c44`: no xrefs.
- `0x00620c48`, `0x00620c4c`, `0x00620c50`, `0x00620c54`, `0x00620c58`, `0x00620c5c`, `0x00620c60`: no xrefs.

The same `xrefs_to` call confirms surrounding controls do have ordinary direct references:

| Address | Direct xref(s) | Meaning |
| --- | --- | --- |
| `0x00620b90` | `0x00538cbc` in `0x00538c50` | BowGauge paint loads `BGAUGE.EPF` |
| `0x00620ba8` | `0x00538cc8` in `0x00538c50` | BowGauge paint loads `BGAUGE.pal` |
| `0x00620bc0` | `0x00539075` in `0x00539030` | HitBar render loads `DEADSIGN.EPF` |
| `0x00620bdc` | `0x005392e3` in `0x00539230` | DamageNumber constructor formats with `%d` |
| `0x00620be0` | `0x00539551` in `0x005394d0` | DamageNumber render loads `DMGNUM.EPF` |
| `0x00620bf8` | `0x00539563` in `0x005394d0` | DamageNumber render uses `DMGNUM.PAL` |
| `0x00620c64` | `0x00539391` in `0x00539380` | DamageNumber animation progress scalar |
| `0x00620c68` | `0x00538235`, `0x00538421`, `0x00538566`, `0x0055b821` | shared/folded float scalar |
| `0x00620c6c` | `0x0053ccc9`, `0x0053cd4b` in `0x0053cc70` | SoundObjectPane threshold scalar |
| `0x00620c74` | `0x0053d861`, `0x0053dd50`, `0x00542946` | OptionPane vtable successor |

### Name/global facts

`entity_query` over `0x00620b80-0x00620c80` finds names/globals only at:

- `0x00620b88`: `??_7SoundObjectPane@@6B@_1`
- `0x00620b90`: `aBgaugeEpf`
- `0x00620ba8`: `aBgaugePal`
- `0x00620bc0`: `aDeadsignEpf`
- `0x00620bdc`: `aD_3`
- `0x00620be0`: `aDmgnumEpf`
- `0x00620bf8`: `aDmgnumPal`
- `0x00620c74`: `??_7OptionPane@@6B@`

There are no IDA names/globals inside `0x00620c10-0x00620c64`.

### Function and caller facts

`entity_query` confirms the overlay function cluster from `0x005380b0-0x00539bc0` includes AttachedObjectPane helpers, BowGauge, HitBar, DamageNumber, and ObjectInfo methods. Relevant constructor/caller xrefs:

| Function | Xrefs | Meaning |
| --- | --- | --- |
| `0x00538bc0` | code xref `0x005a2956` from `0x005a2530` | BowGauge constructed by UserPane side |
| `0x00538d50` | code xref `0x0050ee6c` from `0x0050edd0` | HitBar constructor from MapPane packet path |
| `0x00539230` | code xrefs `0x0050ef7a`, `0x0050efa0`, `0x00512a9c`, `0x00512ac2` | DamageNumber constructor from MapPane action/damage handlers |
| `0x005395b0` | code xrefs `0x0050fd17`, `0x0050fd8f`, `0x0050fdd1`, `0x0050fe10` | ObjectInfo constructor from MapPane object-label packet path |

### Decompilation observations

- `0x00538c50` BowGauge paint: derives frame from elapsed time, loads `L"BGAUGE.EPF"` and `L"BGAUGE.pal"`, then draws; no table reference and no table-values lookup.
- `0x00539030` HitBar render: draws `L"DEADSIGN.EPF"` in the dead-sign path and uses immediate bar colors/rectangles in the health-bar path; no table reference.
- `0x00539230` DamageNumber constructor: stores owner/sign/style state, formats the number through `%d`, and sets style offset byte `+309` using immediate offsets `0`, `10`, `20`, and `30`; no table reference.
- `0x00539380` DamageNumber update: reads the scalar at `0x00620c64` as an animation increment around `0.033`, clamps progress to `1.0`, and schedules repaint; no table reference.
- `0x00539400` DamageNumber bounds: computes rectangle from attached-object anchor and string length; no table reference.
- `0x005394d0` DamageNumber render: calls the image loader with `L"DMGNUM.EPF"` and index `digitChar + styleOffset - 48`, then draws with `L"DMGNUM.PAL"`; no table reference.
- `0x005395b0` ObjectInfo constructor: receives an `a6` immediate/resource index and stores it at `this + 436`; no table reference.
- `0x005398e0` ObjectInfo draw: draws label text and outline/decorative rectangles using stored color/index values; no table reference.
- `0x0050ef00` MapPane action/damage helper: allocates `DamageNumberObjectPane` and calls `0x00539230`, passing sign/style flag `1` or `0`; no table reference.
- `0x00512960` MapPane damage packet helper: allocates `DamageNumberObjectPane`, and when packet flags are set it uses immediate `0xE0` and immediate `0xF5`, values that overlap the first/third target runs. These are compiled immediates, not reads of `0x00620c10`.
- `0x0050fb00` MapPane object-label/helper packet path: constructs `ObjectInfoObjectPane` with immediates including `224`, `39`, `12`, and `55`; one immediate overlaps the table's third run (`0xE0`) but is not a table read.
- `0x00511db0` world-map/map-data routine was checked after a partial text search found `226h`; decompilation shows the hit was decimal `550` (`0x226`) in coordinate data, unrelated to target value decimal `226`.

`search_text` over the MapPane/input region found direct listing hits for `0F5h` and `0E0h` in `0x00512960`, and `0E0h` in `0x0050fb00`; it did not find `0F1h`, `0F3h`, `0F7h`, `0E1h`, or `0E3h` before a later global rendered-search attempt timed out. This partial search is useful only as supporting semantic evidence for immediate values; it is not a data-reference signal.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00620c10-0x00620c64` | [UID:0003CC] `ObjectOverlayFrameIndexTables` | three seven-dword static frame/index runs | true | recommended [UID:0000HJ] file parent | `86/91` | assign to file root, not class |
| `0x00620c10-0x00620c70` | [UID:0002YT] `ObjectOverlayNumericConstants` | mixed numeric constant index | false | blank | `88/91` | keep as non-emitting container |
| `0x00620b90-0x00620c70` | [UID:0002SO] `ObjectPaneResourceStringsAndOverlayConstants` | mixed strings/constants tail | false | blank | `89/91` | keep as non-emitting container |
| `0x00620bdc-0x00620c10` | [UID:0002YS] `DamageNumberResourceStrings` | `%d`, `DMGNUM.EPF`, `DMGNUM.PAL` | true | [UID:00003F] | `86/92` | no change |
| `0x00620c64-0x00620c68` | [UID:0003CD] `DamageNumberAnimationStepConstant` | DamageNumber scalar | true | [UID:00003F] | `85/91` | no change |
| `0x00620c68-0x00620c6c` | [UID:0003CE] `SharedMinimumFloatConstant` | folded/shared scalar | false | blank | `84/strong` | no change |
| `0x00620c6c-0x00620c70` | [UID:0003CB] `SoundObjectPaneRandomThresholdConstant` | SoundObjectPane scalar | true | SoundObjectPane class | `85/strong` | no change |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| table dwords `0x00620c10-0x00620c60` | all xref_count `0` | no direct runtime data consumer |
| `0x00620be0` / `0x00620bf8` | `0x005394d0` | DamageNumber render owns neighboring resource strings |
| `0x00620c64` | `0x00539380` | DamageNumber owns scalar successor, not the table |
| `0x00539230` | callers `0x0050ef00`, `0x00512960` | MapPane allocates DamageNumber overlays |
| `0x00512960` | immediates `0xE0`, `0xF5` | semantic overlap with target values, but no table read |
| `0x0050fb00` | ObjectInfo constructor immediates including `0xE0` | semantic overlap with attached overlay resource/index constants, but no table read |

## Documentation Evidence And IDA Status

- Target page [UID:0003CC] correctly records the range, values, lack of direct xrefs, and A001 warning against adjacency-only assignment. IDA confirms those facts. This report changes the recommendation by adding broader owner/caller analysis, not by contradicting the no-xref fact.
- [UID:0002YT] `ObjectOverlayNumericConstants` is correctly non-emitting and mixed. IDA confirms children after the target have distinct owners. Keep it parent blank.
- [UID:0002SO] `ObjectPaneResourceStringsAndOverlayConstants` is correctly non-emitting and mixed over BowGauge, HitBar, DamageNumber, and numeric constants. Keep it parent blank.
- [UID:0000HJ] `AttachedObjectPane` is the best existing source root. It is `86/86`, has `NexusTK/map/`, and owns the attached overlay family: AttachedObjectPane, BalloonObjectPane, ObjectInfoObjectPane, HitBarObjectPane, and DamageNumberObjectPane.
- [UID:00003F] `DamageNumberObjectPane` is a strong class parent for resource strings and scalar data with direct refs. IDA contradicts using it for this target because the table itself has no class method data refs and the render algorithm does not use the table.
- [UID:0000L3] `MapPane` is a real consumer-side source file and owns packet handlers that allocate DamageNumber/ObjectInfo overlays. IDA confirms overlapping immediates in MapPane, but the table's emitted data sits in the ObjectPane/attached-overlay `.rdata` tail, not in the documented MapPane resource region.
- [UID:0000HU] `BowGaugeObjectPane` remains a separate HUD gauge source, below `85` completion as a by-file parent and excluded from AttachedObjectPane. Its direct resource strings precede the target but its methods do not use the target.
- [UID:0000M5] `ObjectPane` is the base map-object source. It excludes attached overlay companion classes, and IDA gives no base-ObjectPane xrefs to the target.

## Ranked Ownership Analysis

### 1. [UID:0000HJ] AttachedObjectPane / `NexusTK/map/AttachedObjectPane.cpp`

Recommendation rank: best candidate and recommended parent.

Evidence for:

- Existing file root is gate-cleared at `86/86` and already owns the attached map-object overlay family: HitBar, DamageNumber, ObjectInfo, Balloon, attach/detach helpers, and anchor support.
- The table is emitted in the ObjectPane/attached-overlay `.rdata` contribution after `DMGNUM.PAL` and before the DamageNumber scalar, not in a generic MapPane or BowGauge resource island.
- Surrounding data has strong direct ownership: BowGauge strings, HitBar dead-sign string, DamageNumber strings, DamageNumber scalar, shared scalar, SoundObjectPane scalar, and OptionPane successor. The unreferenced table is the only unresolved static block in that local attached-overlay tail.
- IDA decompilation of MapPane packet handlers shows the values are semantically plausible combat/object overlay frame/index constants (`0xE0`, `0xF5` appear as immediates), but no table read remains. This fits an unused or compile-time-folded file-local constant table better than a live class-owned resource.
- A file parent is more honest than a class parent: `AttachedObjectPane.cpp` can own private/static helper constants whose exact class consumer was optimized away or never referenced in the linked build.

Evidence against:

- No direct data xrefs, names, or symbol metadata identify the declaration owner.
- The exact original source spelling and whether the table was active, legacy, or compile-time-folded cannot be recovered from current IDA evidence.
- It is possible the constants came from a header/local helper included by the attached-overlay source rather than from hand-written `AttachedObjectPane.cpp` itself. That still routes through the `AttachedObjectPane` source root in current documentation.

Decision: assign to [UID:0000HJ] as file-local attached-overlay constant data. Keep class parent blank/not used.

Confidence: `82/100`.

### 2. [UID:00003F] DamageNumberObjectPane

Evidence for:

- Target is immediately after `DMGNUM.PAL` and before the DamageNumber scalar.
- Neighboring DamageNumber strings and scalar are directly owned by this class.
- DamageNumber is a combat overlay under the same attached-overlay file root.

Evidence against:

- `xrefs_to` for all target dwords is zero.
- DamageNumber constructor `0x00539230`, update `0x00539380`, bounds `0x00539400`, and render `0x005394d0` do not reference the table.
- Render derives digit frame indices from formatted digit characters plus style offset; it does not need the seven-dword runs.
- The table contains values such as `0xE0-0xE3` and `0xF1-0xF7`, which look more like object/effect frame IDs than digit glyph offsets.

Decision: reject as direct parent. Use the broader file root instead.

Confidence if forced: `58/100`.

### 3. [UID:0000L3] MapPane / `NexusTK/map/MapPane.cpp`

Evidence for:

- MapPane packet/action handlers allocate DamageNumber and ObjectInfo overlays.
- `0x00512960` uses immediate `0xE0` and `0xF5`, overlapping two target runs.
- `0x0050fb00` passes immediate `0xE0` to ObjectInfo construction in one path.

Evidence against:

- There are no data xrefs from MapPane to `0x00620c10`.
- The overlapping values are compiled immediates, not table references.
- MapPane's documented resource/constant data lives in other map ranges; this target is physically in the ObjectPane/attached-overlay read-only tail after DamageNumber strings.
- MapPane is the allocation/packet consumer side for overlay objects. That does not make it the declaration owner of no-xref static data emitted with overlay resource strings.

Decision: reject as parent, but record as important semantic/caller evidence.

Confidence if forced: `45/100`.

### 4. HitBarObjectPane, ObjectInfoObjectPane, or shared attached-overlay class parent

Evidence for:

- HitBar and ObjectInfo are siblings under `AttachedObjectPane.cpp`.
- ObjectInfo constructor caller paths use immediate resource/index values including `0xE0`.
- HitBar resource string and render code are physically near the target.

Evidence against:

- No table xrefs in HitBar or ObjectInfo methods.
- No one class accounts for all three seven-dword runs.
- `ObjectInfoObjectPane` stores constructor immediates; it does not refer to this static table.
- `HitBarObjectPane` render uses dead-sign and bar drawing immediates, not these runs.

Decision: reject class-level assignment. Their shared file root is the recommended parent.

Confidence if forced: HitBar `35/100`, ObjectInfo `45/100`.

### 5. BowGaugeObjectPane

Evidence for:

- BowGauge resource strings are earlier in the same broad resource tail.
- BowGauge executable functions physically precede HitBar/DamageNumber/ObjectInfo in the mixed code cluster.

Evidence against:

- BowGauge is a local-player HUD pane, not part of the attached map-object overlay family.
- Its by-file page is `84/88`, below the strict completion gate.
- IDA paint code uses `BGAUGE.EPF`/`BGAUGE.pal` and an elapsed-time frame count, not this table.
- The target follows DamageNumber strings and does not sit inside the BowGauge string child.

Decision: reject.

Confidence if forced: `20/100`.

### 6. ObjectPane base or non-emitting by-memory aggregate parents

Evidence for:

- The target is inside the broad ObjectPane read-only region.
- `ObjectOverlayNumericConstants` and `ObjectPaneResourceStringsAndOverlayConstants` already contain the target structurally.

Evidence against:

- `ObjectPane.cpp` is the base map-object source and current docs explicitly split attached overlay companion classes into `AttachedObjectPane.cpp`.
- The aggregate by-memory pages are non-emitting inventories and not direct source owners.
- No base ObjectPane method references the table.

Decision: reject as direct source owners. Keep aggregates as containers only.

Confidence if forced: ObjectPane `30/100`, aggregates `0/100` as source parents.

### 7. New source file or grouping

Potential name if one were required: `ObjectOverlayFrameTables` or `AttachedOverlayFrameIndexTables`.

Evidence for:

- The target is a coherent structured table with three runs.
- No current class directly consumes it, so a helper grouping could describe it.

Evidence against:

- No xrefs, names, source path clues, separate rdata island, or additional siblings support an independent source file.
- The broader existing `AttachedObjectPane.cpp` file already owns the attached overlay family and is the natural file-local static-data container.
- The nearby data items either already have direct class/file owners or are mixed/folded scalars; they should not be swept into a new file.

Decision: do not create a new source file. If a narrow documentation grouping is desired later, make it a subdocument/note under `AttachedObjectPane.cpp`, not a standalone reconstruction unit.

Confidence for new file: `25/100`.

## Proposed Owner Contents / Scope

No new source file is recommended. The proposed owner is existing [UID:0000HJ] `AttachedObjectPane`, whose likely original contents already include:

- `AttachedObjectPane` base attach/detach lifecycle.
- `BalloonObjectPane` speech balloon overlay.
- `HitBarObjectPane` health/dead-sign overlay.
- `DamageNumberObjectPane` floating damage/healing number overlay.
- `ObjectInfoObjectPane` floating label/tooltip overlay.
- Detach-registry helper and possible anchor resolver folding.
- File-local/static constants and resource literals used by those overlays.

Candidate related data:

| Candidate | Decision |
| --- | --- |
| [UID:0003CC] target table | add to `AttachedObjectPane` file root |
| [UID:0002YS] DamageNumber strings | keep class parent [UID:00003F]; no change |
| [UID:0003CD] DamageNumber animation scalar | keep class parent [UID:00003F]; no change |
| [UID:0003CE] shared minimum float | keep non-reconstructable/parent blank; no change |
| [UID:0003CB] SoundObjectPane threshold | keep SoundObjectPane class parent; no change |
| [UID:0001DB] ObjectOverlayPanes code aggregate | keep non-emitting mixed BowGauge/AttachedObjectPane container; no change |
| MapPane immediate constants in `0x00512960` and `0x0050fb00` | record as semantic/caller evidence only; no data page exists to move |

## Negative Evidence Summary

- Every dword-aligned address in the target has zero direct xrefs in fresh IDA MCP.
- No IDA name/global exists inside the target range.
- No decompiled BowGauge, HitBar, DamageNumber, or ObjectInfo method reads the target.
- MapPane caller paths use overlapping immediates but do not reference the table.
- The table pattern is unique, so there is no duplicate referenced copy elsewhere.
- The scalar successor at `0x00620c64` is separate and directly owned by DamageNumber. It must not be merged back into the target.
- Splitting into three runs would not improve ownership because each run has the same no-xref/no-name evidence profile.

## Final Recommendation

Recommended by-memory target header edit:

```text
*** AUTOGEN_PARENT_UID:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended target-page narrative changes:

- Change disposition from "unassigned" to "file-owned attached-overlay static constant data".
- Replace the assignment-gate warning with a B001-057 note that the table remains no-xref/no-class-owner, but the best direct source owner is [UID:0000HJ] `AttachedObjectPane` as a file-local static block.
- Add a changes entry for B001-057 with the fresh IDA facts: unique full/run byte patterns, no xrefs to every dword, no names/globals inside target, surrounding control xrefs, MapPane immediate overlap, and rejected class/new-file candidates.
- Keep `COMPLETION:86`, `CONFIDENCE:91`, and `RECONSTRUCTABLE:TRUE` unless the applying agent chooses to raise completion based on the expanded report.

Exact replacement coverage-report row for supervisor application, replacing line 3551 under [UID:0002YT]:

```markdown
                - [UID:0003CC][0x00620c10-0x00620c64.ObjectOverlayFrameIndexTables](by-memory/0x00620c10-0x00620c64.ObjectOverlayFrameIndexTables.md) 0x00620c10-0x00620c64 | constant-data | ObjectOverlayFrameIndexTables : reconstructable : 86% : strong : B001-057 recommends assigning this three-run no-xref frame/index table to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) as file-local attached-overlay static constant data, not to a narrower class: fresh IDA confirms all 21 dword-aligned elements still have zero direct xrefs or names and the full/individual run byte patterns are unique, while surrounding controls have direct owners (`DMGNUM.*` strings in DamageNumber, the `0x00620c64` DamageNumber scalar, shared folded float, and SoundObjectPane threshold); deeper decompilation found MapPane damage/ObjectInfo packet handlers using overlapping immediates such as `0xE0` and `0xF5` but no table read, so MapPane is consumer-side evidence and DamageNumber/HitBar/ObjectInfo/BowGauge/new-file candidates are weaker than the existing attached-overlay file root.
```

Placement context: replace the current child row immediately after [UID:0002YT] and before [UID:0003CD] in `by-memory/-coverage-report.md`. Do not manually edit that file as B001.

## Follow-Up Actions

Supervisor actions:

- Apply the target `AUTOGEN_PARENT_UID:0000HJ` if accepting this recommendation.
- Apply the exact replacement row above to `by-memory/-coverage-report.md`.
- Update `Supervisor_notes.md` from `reviewed-85-but-ownership-unknown-under-review` to the accepted disposition.
- Run validator after applying the target edit.

A-agent actions:

- If editing the target page, include the B001 evidence and avoid claiming a direct DamageNumber class xref.
- Do not create a new `ObjectOverlayFrameTables.cpp` file from current evidence.
- Do not split the three seven-dword runs unless future IDA/source evidence discovers independent owners.

B001 future research actions:

- Revisit only if new symbol/link-map/PDB/source-path evidence appears or an IDA ref pass discovers nonstandard references to `0x00620c10`.

## Confidence

- Recommendation confidence: `82/100` for `AttachedObjectPane.cpp` file-level ownership.
- Fact confidence: `97/100` for range, bytes, uniqueness, surrounding xrefs, and no direct table xrefs.
- Score confidence: current `86/91` is still reasonable. The evidence is stronger on facts than on original declaration owner, so leaving the score unchanged is defensible.
- Remaining uncertainty: exact original declaration name and whether the table was legacy unused data, header-local static data, or a compile-time-folded lookup table.

## Validator Results

- Validator was not run because B001 did not modify by-* documentation or generated coverage in this turn.
- Recommended validator command after supervisor/A-agent applies the target edit:

> Executable block R001 was removed from this report and preserved verbatim in [0003CC-ObjectOverlayFrameIndexTables-removed.md](0003CC-ObjectOverlayFrameIndexTables-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0003CC-ObjectOverlayFrameIndexTables.md`
- Modified: none outside B001 research.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0003CC-ObjectOverlayFrameIndexTables.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:22","uid":"0003CC"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003CC-ObjectOverlayFrameIndexTables-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0003CC-ObjectOverlayFrameIndexTables.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003CC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
