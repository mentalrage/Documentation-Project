** TARGET-REPORT-UID:0003F4 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003F4 **
# 0003F4 SharedStatButtonEpfResourceString Live Goal 2 No-Owner Pass

## Final Recommendation

Keep [UID:0003F4][0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString](../../../../../by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md) unchanged:

- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000NL,0000P0`
- `RECONSTRUCTION_CPP` remains blank
- no split, child-page creation, reclassification, IDA repair, by-memory edit, or coverage-report edit is justified

This is a valid owner/emitter split under the current system. The physical bytes are one unique pooled UTF-16LE `STATBUT.EPF` literal. IDA proves direct source-use routes from both [UID:0000NL][SelfLookPane](../../../../../by-file/SelfLookPane.md) and [UID:0000P0][UserLookPane](../../../../../by-file/UserLookPane.md), while current docs and IDA do not prove any single canonical declaration owner. Emitting the literal through both source-use files is therefore correct; assigning a canonical owner would overclaim one consumer or invent a shared declaration source.

No replacement row is needed for `by-memory/-coverage-report.md`. The current row already states the correct model:

```text
            - [UID:0003F4][0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString](by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md) 0x00624b90-0x00624ba8 | pooled UTF-16 resource filename literal | SharedStatButtonEpfResourceString : reconstructable : 89% : very strong : B003 advanced-scan repair reclassified the shared `STATBUT.EPF` literal from non-reconstructable/non-emitting to `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000NL,0000P0`; live IDA confirms exact UTF-16LE bytes, ten direct xrefs to `aStatbutEpf` (eight from SelfLookPane2 `sub_570FC0`, two from UserLookPane `sub_5A0640`), no interior target refs, and separate successor label-string refs at `0x00624ba8`/`0x00624bbc`.
```

## Research

### Scope And Current State

Target checked:

```text
UID:0003F4
Range: 0x00624b90-0x00624ba8
Current: CANONICAL_OWNER:NONE, RECONSTRUCTABLE:TRUE, EMITTER_UIDS:0000NL,0000P0
```

I treated prior reports as leads only. The user-named Agent-B001 prior report path was not present; existing Agent-B002/Agent-B003 reports were not used as authority for the conclusion.

Current documentation rechecked:

- Target page records `STATBUT.EPF` as a pooled UTF-16 resource filename literal with no canonical owner and emitters `0000NL,0000P0`.
- Parent [UID:0002V2][LookGroupCollectionResourceStringData](../../../../../by-memory/0x00624788-0x00624c64.LookGroupCollectionResourceStringData.md) is a non-emitting mixed inventory and explicitly keeps pooled shared literal children parent-blank.
- Predecessor [UID:0003F3][SelfLookPane2LookPalStringFragments](../../../../../by-memory/0x00624b74-0x00624b90.SelfLookPane2LookPalStringFragments.md) is SelfLookPane-owned.
- Successor [UID:0003F5][SelfLookPane2StatButtonLabelStrings](../../../../../by-memory/0x00624ba8-0x00624bd0.SelfLookPane2StatButtonLabelStrings.md) is SelfLookPane-owned.
- [UID:0000NL][SelfLookPane](../../../../../by-file/SelfLookPane.md) is `85/89` and owns the SelfLookPane/SelfLookPane2 source route.
- [UID:0000P0][UserLookPane](../../../../../by-file/UserLookPane.md) is `88/85` and owns the remote user-look/profile source route.
- `auto-generated/-ag-file-coverage.md` maps `0000NL` to `auto-generated/NexusTK/ui/panels/SelfLookPane.cpp` and `0000P0` to `auto-generated/NexusTK/ui/panels/UserLookPane.cpp`.

### Fresh IDA MCP Evidence

IDA session: `a001_goal2_class_batch`, module `NexusTK.exe`, image base `0x400000`, Hex-Rays ready, strings cache ready.

Bytes at `0x00624b90-0x00624ba8`:

```text
53 00 54 00 41 00 54 00 42 00 55 00 54 00 2E 00 45 00 50 00 46 00 00 00
```

The range signature is unique. MCP `int_convert` confirms `0x18` is 24 bytes. IDA `get_string` decodes `0x00624b90` as `STATBUT.EPF`; `get_bytes` and `make_signature_for_range` agree on the exact byte sequence.

`find_bytes` results:

| Pattern | Result |
| --- | --- |
| UTF-16LE `STATBUT.EPF\0` | one hit: `0x00624b90` |
| little-endian VA `90 4B 62 00` | ten hits: the operand bytes for the ten direct pushes |
| `push 0x00624b90` (`68 90 4B 62 00`) | ten instruction hits |
| interior VAs `0x00624b94`, `0x00624b98`, `0x00624b9c`, `0x00624ba0`, `0x00624ba4` | zero hits |
| target RVA `90 4B 22 00` | zero hits |
| ASCII `STATBUT.EPF\0` | zero hits |
| UTF-16LE `STATBUTS.EPF\0` | one separate hit: `0x00624820` |
| UTF-16LE `STAT.EPF\0` | one separate hit: `0x00630ee4` |

Direct xrefs to `0x00624b90`:

| Xref | IDA function | Source route |
| --- | --- | --- |
| `0x00571579` | `sub_570FC0` | `SelfLookPane` / `SelfLookPane2` via `0000NL` |
| `0x005715cc` | `sub_570FC0` | `SelfLookPane` / `SelfLookPane2` via `0000NL` |
| `0x00571659` | `sub_570FC0` | `SelfLookPane` / `SelfLookPane2` via `0000NL` |
| `0x005716d6` | `sub_570FC0` | `SelfLookPane` / `SelfLookPane2` via `0000NL` |
| `0x0057175e` | `sub_570FC0` | `SelfLookPane` / `SelfLookPane2` via `0000NL` |
| `0x0057177b` | `sub_570FC0` | `SelfLookPane` / `SelfLookPane2` via `0000NL` |
| `0x00571b62` | `sub_570FC0` | `SelfLookPane` / `SelfLookPane2` via `0000NL` |
| `0x00571bb5` | `sub_570FC0` | `SelfLookPane` / `SelfLookPane2` via `0000NL` |
| `0x005a0c73` | `sub_5A0640` | `UserLookPane` via `0000P0` |
| `0x005a0ce1` | `sub_5A0640` | `UserLookPane` via `0000P0` |

Interior xrefs:

```text
0x00624b94: 0
0x00624b98: 0
0x00624b9c: 0
0x00624ba0: 0
0x00624ba4: 0
```

Boundary checks:

```text
0x00624ba8 <- 0x005717ab sub_570FC0
0x00624bbc <- 0x00571868 sub_570FC0
```

The successor references are separate SelfLookPane2 label-string uses. They do not point inside the `STATBUT.EPF` child.

Representative disassembly:

```text
0x571579  push offset aStatbutEpf; "STATBUT.EPF"
0x57157e  call sub_4D02F0

0x5715cc  push offset aStatbutEpf; "STATBUT.EPF"
0x5715d1  call sub_4D02F0

0x5a0c73  push offset aStatbutEpf; "STATBUT.EPF"
0x5a0c78  call sub_4D02F0

0x5a0ce1  push offset aStatbutEpf; "STATBUT.EPF"
0x5a0ce6  call sub_4D02F0
```

Filtered Hex-Rays evidence:

```text
sub_570FC0: sub_4D02F0(v1, L"STATBUT.EPF", 5 * *(_DWORD *)(this + 3464), (int)v51);
sub_570FC0: sub_4D02F0(v1, L"STATBUT.EPF", 5 * *(_DWORD *)(this + 3468) + 1, (int)v51);
sub_570FC0: sub_4D02F0(v1, L"STATBUT.EPF", 7, (int)v51);
sub_570FC0: sub_4D02F0(v1, L"STATBUT.EPF", 2, (int)v51);
sub_570FC0: sub_4D02F0(v1, L"STATBUT.EPF", 8, (int)v51);
sub_570FC0: sub_4D02F0(v1, L"STATBUT.EPF", 3, (int)v51);
sub_570FC0: sub_4D02F0(v1, L"STATBUT.EPF", 9, (int)v51);
sub_570FC0: sub_4D02F0(v1, L"STATBUT.EPF", 4, (int)v51);
sub_5A0640: sub_4D02F0(v2, L"STATBUT.EPF", 8, (int)v124);
sub_5A0640: sub_4D02F0(v2, L"STATBUT.EPF", 3, (int)v124);
sub_5A0640: sub_4D02F0(v2, L"STATBUT.EPF", 7, (int)v124);
sub_5A0640: sub_4D02F0(v2, L"STATBUT.EPF", 2, (int)v124);
```

`analyze_component` confirms `sub_570FC0` and `sub_5A0640` both call `sub_4D02F0`, and reports `aStatbutEpf` at `0x00624b90` as a shared global accessed by exactly those two functions in the checked component set. `trace_data_flow` backward from `0x00624b90` reaches the same ten `push offset aStatbutEpf` code nodes at depth 1.

### Candidate Owner And Emitter Analysis

`0000NL` / `SelfLookPane` is a required emitter. It owns the documented SelfLookPane2 route, and IDA proves eight direct uses in `sub_570FC0`. It should not be the canonical owner because two direct uses are in `UserLookPane`; choosing it as the owner would treat a source-use majority and physical adjacency as ownership proof.

`0000P0` / `UserLookPane` is a required emitter. It owns `sub_5A0640` through the current class and memory docs, and IDA proves two direct uses there. It should not be the canonical owner because the eight SelfLookPane2 uses are independent and not downstream of UserLookPane.

`0002V2` / `LookGroupCollectionResourceStringData` should not own or emit this child. It is a non-emitting mixed inventory over multiple source owners. Its current guidance is directly applicable: pooled shared literal children remain parent-blank when direct consumers prove use but not declaration ownership.

A new shared resource-string owner is not justified. The IDA evidence shows a pooled read-only literal and direct push operands; it does not show a table, exported/global declaration, relocation group, by-resource source page, or debug/source-path clue that would support a single shared declaration module.

`sub_4D02F0` is not an owner. It is the resource-frame helper called after the literal is pushed. It explains the use of the filename but not the source declaration route.

### Rejected Alternatives

- Assign canonical owner `0000NL`: rejected because it overclaims the two `UserLookPane` references.
- Assign canonical owner `0000P0`: rejected because it overclaims the eight `SelfLookPane2` references.
- Assign a synthetic common owner: rejected because no current doc or IDA fact proves one.
- Remove one emitter: rejected because IDA proves both source-use routes and both source files clear the B-agent threshold.
- Reclassify as non-reconstructable/non-emitting: rejected because source reconstruction needs the filename literal at both source-use sites.
- Split the range: rejected because the byte-pattern is one unique UTF-16LE string, all xrefs target the start, interior xrefs/immediate scans are zero, and successor refs start at `0x00624ba8`.
- Create child pages: rejected because the exact child already exists and is narrow enough.
- IDA repair: rejected because current labels and xrefs are usable; ownership does not depend on renaming generic functions.
- Coverage-row replacement: rejected because current generated and coverage-report rows already encode `NONE` with emitters `0000NL,0000P0`.

### Exact Recommended Changes

No file edits are recommended outside this report.

If a supervisor refreshes generated coverage text, the intended metadata remains:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000NL,0000P0
```

No replacement `by-memory/-coverage-report.md` row is requested.

### Validation Needs

No validator run or dry run was performed. The assignment forbids dry runs, and this pass does not change by-memory metadata. A future normal coverage regeneration should preserve this item as no-owner with emitters `0000NL,0000P0`; if the display path still shows `SelfLookPane.cpp`, that should be treated as a single-path display artifact unless the emitter list itself changes.

### Confidence

Confidence: high. The byte uniqueness, exact ten xrefs, function ownership docs, parent split-inventory guidance, interior-negative scans, successor-boundary refs, decompiler context, and component analysis all agree. The only remaining uncertainty is original source declaration style, and that uncertainty is exactly why `CANONICAL_OWNER:NONE` is the correct conservative state.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003F4","source_path":"executed-b-agent-research/B001/0003F4-SharedStatButtonEpfResourceString-live-goal2-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
