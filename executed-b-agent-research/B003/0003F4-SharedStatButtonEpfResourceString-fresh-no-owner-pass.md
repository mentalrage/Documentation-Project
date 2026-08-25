** TARGET-REPORT-UID:0003F4 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003F4 **
# 0003F4 SharedStatButtonEpfResourceString Fresh No-Owner Pass

## Finalized recommendation

Keep `by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md` unchanged as a pooled shared source-use literal:

- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000NL,0000P0`
- `COMPLETION:89`
- `CONFIDENCE:92`
- `RECONSTRUCTION_CPP` remains blank

No canonical owner is defensible. The target is the single UTF-16LE `STATBUT.EPF` resource filename at `0x00624b90`, referenced directly by two independently documented panel render paths: `SelfLookPane`/`SelfLookPane2` (`0000NL`) and `UserLookPane` (`0000P0`). This is exactly the pooled literal case allowed by the current owner/emitter model: no declaration owner, but multiple proven source-use emitters.

No split, merge, reclassification, IDA-safe rename repair, target-page edit, related by-* edit, or `by-memory/-coverage-report.md` edit is required.

## Target and current metadata

Target file:

`by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md`

Current header state checked:

```text
UID:0003F4
COMPLETION:89
CONFIDENCE:92
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000NL,0000P0
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP:
```

Recommended after-state is identical. Score impact is unchanged: `89/92`.

The active generated coverage row also already matches this conclusion:

```text
| [UID:0003F4][0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString](by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md) | no-owner | `NONE` | `0000NL`,`0000P0` |  | no | `auto-generated/NexusTK/ui/panels/SelfLookPane.cpp` | `by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md` |  |
```

## Evidence standard applied

I treated current documentation and prior reports as leads only. The accepted conclusion requires current source-quality evidence under the owner/emitter model:

- direct data xrefs from current IDA evidence;
- current by-file/by-memory route documentation for candidate emitters;
- raw PE bytes and address-operand scans to confirm uniqueness and range boundaries;
- rejection of ownership by adjacency, most-ref consumer, and constructed-child relationships.

The relevant by-structure rules support `CANONICAL_OWNER:NONE` for pooled string literals when no single semantic declaration owner is defensible, while `EMITTER_UIDS` records every proven source-use output route. The inference rules also warn against treating nearby `.rdata` adjacency or linker pooling as source ownership proof.

## Current documentation checked

- `by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md` already describes a pooled UTF-16 `STATBUT.EPF` literal shared by `SelfLookPane2` and `UserLookPane`.
- `by-memory/0x00624788-0x00624c64.LookGroupCollectionResourceStringData.md` frames this neighborhood as mixed look/profile resource-string data and explicitly keeps pooled shared literal children parent-blank while routing by direct consumers.
- Predecessor `by-memory/0x00624b74-0x00624b90.SelfLookPane2LookPalStringFragments.md` is owned/emitted by `0000NL`.
- Successor `by-memory/0x00624ba8-0x00624bd0.SelfLookPane2StatButtonLabelStrings.md` is owned/emitted by `0000NL`.
- `by-file/SelfLookPane.md` (`0000NL`) owns the SelfLookPane/SelfLookPane2 source route and emits `auto-generated/NexusTK/ui/panels/SelfLookPane.cpp`.
- `by-file/UserLookPane.md` (`0000P0`) owns the remote user look/profile source route and emits `auto-generated/NexusTK/ui/panels/UserLookPane.cpp`.
- `by-file/LegendPane.md` (`0000KM`) documents a shared child pane constructed by both look panels, but it does not document or own this resource literal.
- `auto-generated/-ag-file-coverage.md` confirms `0000NL -> SelfLookPane.cpp`, `0000P0 -> UserLookPane.cpp`, and `0000KM -> LegendPane.cpp`.

No current documentation page proves a stronger single source declaration owner than the two direct source-use emitters.

## Live IDA MCP evidence

IDA session checked: `a001_goal2_class_batch` over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, image base `0x00400000`.

Bytes at `0x00624b90-0x00624ba8`:

```text
53 00 54 00 41 00 54 00 42 00 55 00 54 00 2E 00
45 00 50 00 46 00 00 00
```

Decoded value: UTF-16LE `STATBUT.EPF\0`.

Current IDA name: `aStatbutEpf` at `0x00624b90`.

Direct xrefs to `0x00624b90`:

```text
0x00571579 sub_570FC0
0x005715cc sub_570FC0
0x00571659 sub_570FC0
0x005716d6 sub_570FC0
0x0057175e sub_570FC0
0x0057177b sub_570FC0
0x00571b62 sub_570FC0
0x00571bb5 sub_570FC0
0x005a0c73 sub_5A0640
0x005a0ce1 sub_5A0640
```

Interior target addresses `0x00624b94`, `0x00624b98`, `0x00624b9c`, `0x00624ba0`, and `0x00624ba4` have no direct xrefs. This supports one whole-literal range, not a child split.

Successor label-string refs are separate:

```text
0x00624ba8 <- 0x005717ab sub_570FC0
0x00624bbc <- 0x00571868 sub_570FC0
```

The predecessor `SELF`/`LOOK.PAL` fragments are also separate from the target:

```text
0x00624b74 <- 0x00571005 sub_570FC0
```

Function lookup:

```text
0x00570fc0 -> sub_570FC0
0x005a0640 -> sub_5A0640
0x00624b90 -> not a function
```

Component analysis reports `aStatbutEpf` as a shared global accessed by `sub_570FC0` and `sub_5A0640`. It does not report `sub_56C400`/LegendPane as an accessor.

Decompiled use-site evidence:

- `sub_570FC0` contains eight calls using `L"STATBUT.EPF"` through `sub_4D02F0(...)`, with frame/select indices in the SelfLookPane2 paint path.
- `sub_5A0640` contains two branch-selected calls using `L"STATBUT.EPF"` through `sub_4D02F0(...)`, with frame/select indices in the UserLookPane render path.

These xrefs prove both `0000NL` and `0000P0` as emitters. They do not prove that either file declares a separate global, owns the literal source declaration, or should absorb the other route.

## PE/raw evidence

PE checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`

- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- `.rdata` VA range includes `0x00624b90`; VA-to-raw for target is `0x00223590`.
- Whole-file raw scan finds UTF-16LE `STATBUT.EPF\0` exactly once, at VA `0x00624b90`.
- ASCII `STATBUT.EPF\0` was not present.
- Raw scan finds `push 0x00624b90` exactly ten times, matching the IDA xrefs.
- Raw scan finds no VA32 operands to target interior addresses.
- Separate nearby strings are distinct: `STATBUTS.EPF` at `0x00624820` and `STAT.EPF` at `0x00630ee4`.

This confirms the target is a unique pooled wide literal, not a duplicate-resource table, index span, or stale scanner label.

## Function and child inventory

| Range/address | Current role | Owner/emitter result |
| --- | --- | --- |
| `0x00624b74-0x00624b90` | `SELF` / `LOOK.PAL` fragments | `0000NL`, separate predecessor |
| `0x00624b90-0x00624ba8` | `STATBUT.EPF` pooled resource filename literal | `CANONICAL_OWNER:NONE`, emitters `0000NL,0000P0` |
| `0x00624ba8-0x00624bd0` | SelfLookPane2 stat button label strings | `0000NL`, separate successor |
| `sub_570FC0` | SelfLookPane2 render/paint path | proves emitter `0000NL` |
| `sub_5A0640` | UserLookPane render path | proves emitter `0000P0` |
| `sub_56C400` | LegendPane constructor | no target xrefs; not an emitter for this literal |

## Ownership and emitter decision

Accepted:

1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000NL,0000P0`.

   This is the strongest model. The literal is a linker-visible `.rdata` wide string used by two source routes. Both routes should be able to emit their own use-site `L"STATBUT.EPF"` in reconstructed code. No evidence identifies a shared declaration site, resource manager constant, or single owning source file.

Rejected:

2. Canonical owner `0000NL` / `SelfLookPane`.

   `sub_570FC0` has eight of the ten direct refs, and adjacent predecessor/successor children are SelfLookPane-specific. That proves heavy SelfLookPane use, not declaration ownership. Assigning ownership by majority xrefs or adjacency would hide the independently proven UserLookPane source-use route.

3. Canonical owner `0000P0` / `UserLookPane`.

   `sub_5A0640` has two direct refs and clearly uses the same literal, but it has fewer refs and no declaration evidence. It remains an emitter, not a canonical owner.

4. Canonical owner `0000KM` / `LegendPane`.

   LegendPane is constructed in related UI flows, but current IDA evidence does not show LegendPane code directly referencing `0x00624b90`. Construction relationship is not source ownership.

5. Owner as parent mixed-data range `0002V2`.

   The parent range is a documentation/container split for mixed `.rdata`. It is not a source output file or semantic owner for this child literal.

6. New global/resource owner.

   No debug path, map symbol, source file path, resource table, or unique global declaration evidence was found. A fabricated shared owner would make the generated route weaker than the proven direct use-site emitters.

## Split, merge, and reclassification analysis

No split is needed. The target covers one null-terminated UTF-16LE literal, interior bytes have no xrefs, and the byte signature is unique.

No merge is needed. Adjacent predecessor and successor ranges have distinct xrefs and roles:

- predecessor refs resolve to the SelfLookPane `SELF`/`LOOK.PAL` fragment path;
- successor refs resolve to SelfLookPane stat label strings;
- target refs resolve to both SelfLookPane2 and UserLookPane.

No reclassification is needed. The item is reconstructable because it has valid source-use emitters and appears as literal data in source-level calls. It should not become non-reconstructable padding or index data.

No IDA-safe name repair is needed. `aStatbutEpf` correctly identifies the current literal.

## C++ entry gate

The item mechanically satisfies the current minimum C++ gate:

```text
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000NL,0000P0
(COMPLETION + CONFIDENCE) / 2 = (89 + 92) / 2 = 90.5
```

However, no standalone `RECONSTRUCTION_CPP` should be entered on this memory page. The correct source expression is the use-site literal `L"STATBUT.EPF"` inside the surrounding reconstructed SelfLookPane and UserLookPane functions. Adding a synthetic global declaration here would overstate source ownership.

## Required edits

No by-* documentation edits are required.

No `by-memory/-coverage-report.md` edit is required. The current supervisor-owned manual row can remain:

```text
            - [UID:0003F4][0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString](by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md) 0x00624b90-0x00624ba8 | pooled UTF-16 resource filename literal | SharedStatButtonEpfResourceString : reconstructable : 89% : very strong : B003 advanced-scan repair reclassified the shared `STATBUT.EPF` literal from non-reconstructable/non-emitting to `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000NL,0000P0`; live IDA confirms exact UTF-16LE bytes, ten direct xrefs to `aStatbutEpf` (eight from SelfLookPane2 `sub_570FC0`, two from UserLookPane `sub_5A0640`), no interior target refs, and separate successor label-string refs at `0x00624ba8`/`0x00624bbc`.
```

No replacement row is proposed for `auto-generated/-ag-memory-coverage.md`; it is generated and already reflects the recommended metadata.

## Validation and lease state

Changed files:

- `tools/leaser/Agents/Agent-B003/research/0003F4-SharedStatButtonEpfResourceString-fresh-no-owner-pass.md`

No by-* files were edited, so the documentation validator was not run.

No lease was required for this report-only edit inside Agent-B003's own research folder. No non-agent-folder files were modified.

## Confidence

Recommendation confidence: 92%.

Completion remains 89% because the literal routing and use sites are clear, but there is still no source-level debug artifact proving how the original developers organized the repeated literal in source. That uncertainty does not justify changing ownership; it is exactly why `CANONICAL_OWNER:NONE` with proven emitters is the appropriate current state.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003F4","source_path":"executed-b-agent-research/B003/0003F4-SharedStatButtonEpfResourceString-fresh-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
