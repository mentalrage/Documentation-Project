** TARGET-REPORT-UID:0003UG **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003UG **
# 0003UG LivingObjectPane Clear Linked Record By Index Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003UG] assigned to [UID:00007B] `LivingObjectPane` with emitter [UID:00007B], but replace the current shallow "linked record" explanation with the exact live movement-history clear helper semantics and first-draft C++.
- Final disposition: source-authored, IDA-modeled, route-proven `LivingObjectPane` local-player movement-history helper. It is not a raw no-route island, not padding, not compiler glue, and not a `UserPane` method despite the adjacent `UserPane::OnClipBounds` successor.
- Required action: update the target and support docs with exact bytes, signed index bounds behavior, movement-history vocabulary, direct caller proof, sibling relationships, rejected alternatives, score rationale, and the first-draft C++ below. Do not edit `by-memory/-coverage-report.md`; use the exact supervisor-owned row in this report.
- Score recommendation: raise [UID:0003UG] from `COMPLETION:85`, `CONFIDENCE:87` to `COMPLETION:90`, `CONFIDENCE:92`.
- C++ recommendation: populate formal `RECONSTRUCTION_CPP`. The active code-entry gate is met: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:00007B`, valid route to `auto-generated/NexusTK/map/LivingObjectPane.cpp`, combined score above 85, and no target-specific no-code proof remains.

## Report-Only Status

This is a report-only research pass. I did not edit the target by-memory page, any support by-* docs, generated source, IDA state, or `by-memory/-coverage-report.md`.

Required report path:

`E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B003\research\0003UG-LivingObjectPaneClearLinkedRecordByIndex-source-quality.md`

## Target

- Target UID: [UID:0003UG].
- Target path: `by-memory/0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md`.
- Current scores and routing at report time: `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, blank formal `RECONSTRUCTION_CPP`.
- Current documented name: `LivingObjectPane Clear Linked Record By Index`.
- Current IDA name in target doc: `sub_5A8810`.
- Immediate source family: `0x005a2de0-0x005ad441` [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions`, a non-emitting split index for local-player movement/command/server-packet code and adjacent `UserPane` methods.

## Executive Recommendation

Use the source-facing method name:

```cpp
void LivingObjectPane::ClearMovementHistoryRecordByIndex(int recordIndex)
```

Recommended first-draft formal C++:

```cpp
void LivingObjectPane::ClearMovementHistoryRecordByIndex(int recordIndex)
{
    if (recordIndex >= 0 && recordIndex < m_movementHistoryCapacity)
        m_movementHistoryRecords[recordIndex].active = 0;
}
```

This draft intentionally:

- uses `int recordIndex`, not `unsigned char`, because the target loads a 32-bit stack argument and checks the sign bit with `test edx, edx` / `js`;
- uses one source-level combined bounds check because the binary branches first on negative, then on `recordIndex >= capacity`;
- clears only the record active byte, matching `mov byte ptr [eax + edx*8], 0` after `edx *= 2`;
- does not null-check the record pointer because the binary does not;
- does not clear retained coordinate, direction, or waypoint-kind payload fields;
- does not change `m_movementHistoryWriteIndex` at `this+0x13eb1c`.

Recommended field/type vocabulary:

| Binary location | Best source-facing name | Type direction | Status |
| --- | --- | --- | --- |
| `this+0x13eb14` | `m_movementHistoryRecords` | `LocalMovementHistoryRecord *` | Best class-wide name. Existing `m_movementHistory` text is acceptable as a short alias, but implementation should prefer the pointer-specific `Records` spelling where new text is added. |
| `this+0x13eb18` | `m_movementHistoryCapacity` | `int` | Capacity/count bound for getter/clear helpers and modulus divisor for packet helper write-index updates. |
| `this+0x13eb1c` | `m_movementHistoryWriteIndex` | `unsigned char` or byte-sized index | Not read by [UID:0003UG], but part of the same ring. It is serialized by [UID:0003UX]/[UID:0003UY] and advanced modulo capacity. |
| record `+0x00` | `active` | `unsigned char` | Only field [UID:0003UG] writes. Do not model this helper as clearing the whole record. |
| record `+0x04` | `tileY` / `coordFromOffset104` | `int` | Read by movement ack/correction handlers; not touched by [UID:0003UG]. Axis naming remains offset-sensitive. |
| record `+0x08` | `tileX` / `coordFromOffset100` | `int` | Read by movement ack/correction handlers; not touched by [UID:0003UG]. Axis naming remains offset-sensitive. |
| record `+0x0c` | `direction` in movement/facing ack contexts; `waypointKind` in opcode `0x06` waypoint contexts | `unsigned char` | Shared slot. A final shared struct can document it as `movementKind` or `directionOrWaypointKind` if the project wants one field name across both packet families. |

## Evidence Checked

Instruction and binary evidence checked directly:

- PE-aware byte and Capstone disassembly of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Exact target bytes for `0x005a8810-0x005a8832`.
- Neighbor bytes for `0x005a87d0-0x005a8840`.
- Disassembly around direct callers `0x005ab2f4` and `0x005ab641`.
- Section-aware direct `E8`/`E9` rel32 scans for `0x005a87b0`, `0x005a87e0`, `0x005a8810`, `0x005ab090`, `0x005ab410`, `0x005aaff0`, `0x005ac7e0`, and `0x005ac9a0`.
- Near conditional-branch scan for the same starts.
- VA/RVA pointer scans in `.text`, `.rdata`, `.data`, and `.rsrc` for the same starts.

Documentation evidence checked:

- Target [UID:0003UG] `by-memory/0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md`.
- Sibling [UID:0003VE] `0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`.
- Sibling [UID:0003UF] `0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md`.
- Sibling [UID:0003UX] `0x005ac7e0-0x005ac99b.LivingObjectPaneRawWaypointPacketHelper.md`.
- Sibling [UID:0003UY] `0x005ac9a0-0x005acad5.LivingObjectPaneRawFacingPacketHelper.md`.
- Caller docs [UID:0003UP] `0x005ab090-0x005ab410.LivingObjectPaneHandleMovementPacketA.md` and [UID:0003UQ] `0x005ab410-0x005ab75d.LivingObjectPaneHandleMovementPacketB.md`.
- Parent split index [UID:0001KM] `0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`.
- Class [UID:00007B] `by-class/LivingObjectPane.md`.
- Source-file [UID:0000KU] `by-file/LivingObjectPane.md`.
- Core split/index [UID:0001DE] `0x0053a110-0x0053d818.LivingObjectPaneCore.md`, including stale `m_linkedRecords`/`m_linkedRecordCount` field-table text.
- UserPane aggregate `0x005a2530-0x005b8395.UserPane.md` and B004 UserPane report evidence for successor `0x005a8840-0x005a88cf` as `UserPane::OnClipBounds`.
- B002 report `0003UO-LivingObjectPaneRawMovementCorrectionPacketHelper-source-quality.md`, which previously recorded the two direct callers to `0x005a8810`.
- B003 report `0003UX-LivingObjectPaneRawWaypointPacketHelper-source-quality.md`.
- B008 executed report `0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality.md`.
- `by-memory/-ignored.md` for existing adjacent padding coverage.
- Supervisor-owned `by-memory/-coverage-report.md` as read-only input.
- Generated support `auto-generated/-ag-memory-coverage.md` and `auto-generated/NexusTK/map/LivingObjectPane.cpp` as generated-output state, not as source proof.

## IDA / Binary Facts

### Exact Target Bytes And Body

Raw bytes for `0x005a8810-0x005a8832`:

```text
55 8b ec 8b 55 08 85 d2 78 14 3b 91 18 eb 13 00
7d 0c 8b 81 14 eb 13 00 03 d2 c6 04 d0 00 5d c2
04 00
```

Instruction-level body:

```asm
0x005a8810  55                    push ebp
0x005a8811  8b ec                 mov ebp, esp
0x005a8813  8b 55 08              mov edx, dword ptr [ebp+8]
0x005a8816  85 d2                 test edx, edx
0x005a8818  78 14                 js 0x005a882e
0x005a881a  3b 91 18 eb 13 00     cmp edx, dword ptr [ecx+0x13eb18]
0x005a8820  7d 0c                 jge 0x005a882e
0x005a8822  8b 81 14 eb 13 00     mov eax, dword ptr [ecx+0x13eb14]
0x005a8828  03 d2                 add edx, edx
0x005a882a  c6 04 d0 00           mov byte ptr [eax+edx*8], 0
0x005a882e  5d                    pop ebp
0x005a882f  c2 04 00              ret 4
```

Decoded behavior:

1. Load signed 32-bit `recordIndex` from `[ebp+8]`.
2. If `recordIndex < 0`, return without side effects.
3. Compare `recordIndex` against `*(int *)(this+0x13eb18)`.
4. If `recordIndex >= m_movementHistoryCapacity`, return without side effects.
5. Load `m_movementHistoryRecords` from `this+0x13eb14`.
6. Compute `recordIndex * 0x10` as `edx *= 2`, then scaled-index addressing `edx*8`.
7. Store zero to byte `records[recordIndex].active`.
8. Return `void` with `ret 4`.

### Bounds Behavior

The bounds behavior is exact and source-relevant:

- Negative indexes are explicitly rejected with `js`.
- Indexes equal to or above capacity are rejected with signed `jge`.
- Capacity `0` produces no clears for any nonnegative index.
- Negative capacity also produces no clears for any nonnegative index because `recordIndex >= negativeCapacity` is true.
- There is no record pointer null guard. Source must rely on the invariant that `m_movementHistoryRecords` is valid when capacity is positive.
- There is no byte truncation inside this helper. It accepts a signed dword argument. The two known callers happen to pass a low-seven-bit packet byte widened to dword, but the helper itself is not a `uint8_t` helper.

### Boundary Facts

| Range | Classification | Evidence |
| --- | --- | --- |
| `0x005a87d5-0x005a87e0` | padding before [UID:0003UF] | Eleven `0xcc` bytes already recorded in [UID:0003VE] and `by-memory/-ignored.md`. |
| `0x005a87e0-0x005a8809` | [UID:0003UF] `ClearAllLinkedRecords` | Modeled helper ending in `ret` at `0x005a8808`. It loops over capacity and clears each record active byte. |
| `0x005a8809-0x005a8810` | padding | Seven `0xcc` bytes after [UID:0003UF] and before this target. This span is not currently called out in `by-memory/-ignored.md` and should be added or folded into the local-player padding entry during implementation if the supervisor accepts coverage/support cleanup. |
| `0x005a8810-0x005a8832` | [UID:0003UG] target | Modeled function body above; prologue, signed-index bounds, active-byte clear, `ret 4`. |
| `0x005a8832-0x005a8840` | padding | Fourteen `0xcc` bytes after this target and before successor `0x005a8840`. This span is not currently called out in `by-memory/-ignored.md` and should be added or folded into the local-player padding entry during implementation if support cleanup is in scope. |
| `0x005a8840-0x005a88cf` | `UserPane::OnClipBounds` successor | B004/UserPane docs and vtable evidence classify `0x005a8840` as a UserPane virtual, not a LivingObjectPane movement helper. Padding prevents fallthrough from [UID:0003UG]. |

### Route And Caller Facts

Direct route scan results:

| Target start | Direct `E8`/`E9` hits | Meaning |
| --- | ---: | --- |
| `0x005a87b0` | 0 | [UID:0003VE] remains raw/no-xref as currently documented. |
| `0x005a87e0` | 2: calls at `0x005ab2ea`, `0x005ab637` | [UID:0003UF] is live in movement ack/correction handlers. |
| `0x005a8810` | 2: calls at `0x005ab2f4`, `0x005ab641` | [UID:0003UG] is live in movement ack/correction handlers. |
| `0x005ab090` | 1: call at `0x005a7a33` | Movement handler A has a dispatcher route. |
| `0x005ab410` | 1: call at `0x005a7a44` | Movement handler B has a dispatcher route. |
| `0x005aaff0` | 0 | B002's retained/out-of-line opcode `0x04` helper remains no-entry-route. |
| `0x005ac7e0` | 0 | [UID:0003UX] remains retained no-route raw helper. |
| `0x005ac9a0` | 0 | [UID:0003UY] remains retained no-route raw helper. |

Near conditional-branch scan found zero `0F 8x` routes to `0x005a8810`. VA/RVA pointer scans found no stored start pointer for `0x005a8810` in `.text`, `.rdata`, `.data`, or `.rsrc`. This absence matters only for virtual/table ownership: the helper is not vtable or data-dispatched. It does not weaken reachability because the two direct `E8` calls prove live source use.

Direct caller details:

| Caller address | Parent item | Instruction context | Meaning |
| --- | --- | --- | --- |
| `0x005ab2f4` | [UID:0003UP] `LivingObjectPaneHandleMovementPacketA` | `push dword ptr [ebp-0x18]`; `mov ecx, ebx`; `call 0x005a8810` | Handler A calls the helper with the decoded low-seven-bit history index after record comparison or correction reconciliation. |
| `0x005ab641` | [UID:0003UQ] `LivingObjectPaneHandleMovementPacketB` | `push dword ptr [ebp+8]`; `mov ecx, ebx`; `call 0x005a8810` | Handler B calls the helper with the decoded low-seven-bit history index after the same movement-history comparison/correction family. |

The caller parse shape in both movement handlers:

- read a direction/movement byte from payload `+1`;
- read multiple big-endian coordinate words from payload offsets `+2`, `+4`, `+6`, and `+8`;
- read payload byte `+0x0a` through `0x00575470`, mask with `0x7f`, and store as the movement-history record index;
- compare the index against `this+0x13eb18`;
- compute record pointer from `this+0x13eb14 + index * 0x10`;
- require record `+0x00` active;
- compare record `+0x08` with current/expected X-like coordinate, record `+0x04` with Y-like coordinate, and record `+0x0c` with the movement direction byte;
- call [UID:0003UG] to clear the indexed record after a matching prediction or after a correction branch;
- on correction/mismatch paths, call [UID:0003UF] `ClearAllLinkedRecords` immediately before the shared [UID:0003UG] indexed clear call.

The clear-all plus clear-index sequence is not contradictory. It is a compiler/control-flow sharing artifact in the mismatch path: the handler clears all records when prediction reconciliation fails, then falls into or shares the same epilogue that also clears the indexed record used by the matched path.

## Heuristic / Inference Reanalysis And Validation

### 1. Generated Name `sub_5A8810`

- Issue: target doc still exposes the IDA placeholder `sub_5A8810` and a generic "Clear Linked Record By Index" title.
- Evidence checked: target bytes, direct callers, sibling record getter/clear docs, B002/B008/B003 movement-history reports, parent/class/file docs.
- Best inference: source-facing role is `LivingObjectPane::ClearMovementHistoryRecordByIndex(int recordIndex)`.
- Status: descriptive/inferred, not symbol-proven.
- Rejected alternatives:
  - `ClearLinkedRecordByIndex` as final source vocabulary: retained as historical alias only. It does not express the movement prediction/history role proven by [UID:0003UY] writes and [UID:0003UP]/[UID:0003UQ] ack/correction comparisons.
  - `ClearWaypointHistoryRecordByIndex`: rejected for this target. [UID:0003UX] uses the same ring as waypoint history, but [UID:0003UG]'s live callers are movement ack/correction handlers comparing direction and coordinates.
  - `ClearRecordByIndex`: too generic for source-quality docs.
  - `ClearMovementBuffer`: rejected because [UID:0003UK] and deferred user-list packet paths use a different buffer cluster at `+0x13eb20/+0x13eb24`.
- Final direction: use `ClearMovementHistoryRecordByIndex` in new text and C++. Keep filename rename optional; no split or rename is required to implement source-quality content.

### 2. Index Type And Bounds

- Issue: current surrounding docs sometimes imply byte indexes because [UID:0003VE] takes a byte index and packet helpers serialize byte write indexes.
- Evidence checked: [UID:0003UG] raw body and both direct callers.
- Best inference: [UID:0003UG] source signature uses `int recordIndex`.
- Validation:
  - `mov edx, dword ptr [ebp+8]` reads a full stack dword.
  - `test edx, edx` / `js` rejects signed negative values.
  - `cmp edx, [ecx+0x13eb18]` / `jge` rejects signed `>= capacity`.
  - Callers pass a widened low-seven-bit packet byte, but helper source is more general and defensive than a byte-only helper.
- Rejected alternatives:
  - `unsigned char index`: contradicted by dword load and sign check.
  - `unsigned int index`: contradicted by signed negative guard.
  - `short index`: no sign extension or word load exists in the helper.
- Score/C++ impact: resolves a material source-quality issue and supports first-draft C++.

### 3. Record Layout And Clear Semantics

- Issue: target summary said "clears one movement-history record" but did not prove whether it clears the whole record or only an active flag.
- Evidence checked: target byte store, [UID:0003VE] active-byte getter, [UID:0003UF] clear-all loop, [UID:0003UX]/[UID:0003UY] record writers, [UID:0003UP]/[UID:0003UQ] record comparisons.
- Best inference: record stride is `0x10`; [UID:0003UG] clears only `record->active` at offset `+0x00`.
- Validation:
  - Store is `c6 04 d0 00`, exactly one byte at computed record base.
  - No stores to record `+4`, `+8`, or `+0xc` occur.
  - [UID:0003VE] tests the same byte and returns only active records.
  - [UID:0003UY] and [UID:0003UX] set the active byte after filling coordinates and kind/direction.
  - [UID:0003UP]/[UID:0003UQ] compare coordinates and direction before clearing, proving the payload is history data, not zero-on-clear scratch.
- Rejected alternatives:
  - Whole-record clear/memset: contradicted by single byte store.
  - Coordinate reset: contradicted by absence of dword stores.
  - Write-index reset: contradicted by no access to `+0x13eb1c`.
- Final direction: target docs should explicitly say retained payload bytes are not zeroed.

### 4. Field Names: Movement-History, Waypoint-History, Linked-Record, Or Dual Alias

- Issue: docs use a mix of `linked record`, `movement-history`, `movement-prediction`, and `waypoint-history` names.
- Evidence checked: [UID:0003UP]/[UID:0003UQ] movement correction comparisons, [UID:0003VE] getter, [UID:0003UF]/[UID:0003UG] clear helpers, [UID:0003UY] opcode `0x32` writer, [UID:0003UX] opcode `0x06` writer, class/file parent docs.
- Best inference:
  - Class-wide field cluster should be documented as movement-history or movement-prediction state.
  - Best source-facing field names for new text: `m_movementHistoryRecords`, `m_movementHistoryCapacity`, `m_movementHistoryWriteIndex`.
  - Best current type name: `LocalMovementHistoryRecord`.
  - `linked record` should remain only as a historical/search alias for old docs and filenames.
  - `waypoint-history` should remain a target-local alias for [UID:0003UX] because opcode `0x06` stores waypoint-kind/path information into the same ring.
- Why movement-history beats waypoint-history:
  - Two live modeled movement ack/correction handlers route directly to [UID:0003UG].
  - Those handlers parse a history index from packet `+0x0a`, compare active/X/Y/direction fields, then clear the indexed record.
  - [UID:0003UY] fills the same ring after opcode `0x32` movement/facing-history send.
  - [UID:0003UX] is no-route retained code and uses the same storage in a waypoint/path context, but it does not outweigh the live movement-correction route.
- Why not pure linked-record:
  - The record contents are local movement position/direction/waypoint values, not linked object pointers or companion/follower object relationships.
  - [UID:0003UW] `ParseLinkedObjectsPacket` is the real linked-object/player companion area and is separate from this ring.
- Remaining uncertainty:
  - Exact original field spellings are not symbol-proven. This should not block C++ because the best descriptive names are now strong enough and the target body is tiny.
- Score/C++ impact: confidence should remain below final audit because spelling is inferred, but not below the C++ entry gate.

### 5. Record `+0x0c` Field Name

- Issue: [UID:0003UY] names record `+0x0c` as `direction`; [UID:0003UX] names it `waypointKind`.
- Evidence checked: [UID:0003UP]/[UID:0003UQ] compare record `+0x0c` against the signed movement direction byte; [UID:0003UX] stores first argument `waypointKind` into the same slot; [UID:0003UG] does not read or write the slot.
- Best inference: for target [UID:0003UG], do not force a final field name because it clears only `active`. For shared type docs, use a documented alias such as `directionOrWaypointKind` or `movementKind`; for [UID:0003UY] local text, `direction` remains correct; for [UID:0003UX] local text, `waypointKind` remains correct.
- Rejected alternatives:
  - Direction only across all docs: contradicted by [UID:0003UX].
  - Waypoint kind only across all docs: contradicted by live movement correction handlers and [UID:0003UY].
- Final direction: target docs should mention the dual-slot caveat only as context; formal [UID:0003UG] C++ need not name this field.

### 6. Caller / Reachability Hypothesis

- Issue: earlier linked-record raw helper work separated [UID:0003VE] as no-xref, while packet-tail helpers [UID:0003UX]/[UID:0003UY] are no-route. [UID:0003UG] needed an independent route decision.
- Evidence checked: rel32 scan, pointer scan, caller disassembly, target docs, B002 route table.
- Best inference: [UID:0003UG] is live and normally reachable through movement handler A/B.
- Validation:
  - Direct `E8` call to `0x005a8810` at `0x005ab2f4`.
  - Direct `E8` call to `0x005a8810` at `0x005ab641`.
  - Both callers are modeled `LivingObjectPane` handlers with dispatcher routes.
  - No VA/RVA/vtable pointer route exists, so it is not virtual or table-dispatched.
- Rejected alternatives:
  - Retained no-route helper policy: rejected for [UID:0003UG] because direct callers exist.
  - Padding: rejected by modeled body and direct calls.
  - Inline-only duplicate: rejected because direct calls use the standalone body.
- Score/C++ impact: route proof is the main reason first-draft formal C++ should now be emitted.

### 7. Owner And Source Placement

- Issue: the helper is physically adjacent to `UserPane` virtual methods and uses large local-player offsets.
- Evidence checked: `this` field offsets, direct callers, parent [UID:0001KM], [UID:00007B] class docs, [UID:0000KU] file docs, successor `0x005a8840` UserPane evidence.
- Best inference: direct owner remains [UID:00007B] `LivingObjectPane`; source file route remains [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`.
- Evidence for `LivingObjectPane`:
  - Direct callers [UID:0003UP]/[UID:0003UQ] are `LivingObjectPane` movement ack/correction handlers.
  - State is the local movement-history/prediction ring also filled by `LivingObjectPane` packet helpers.
  - [UID:0001KM] lists `0x005a8810` as a modeled local-player movement helper.
  - [UID:00007B] and [UID:0000KU] already own the movement-history helper family.
- Rejected owners:
  - `UserPane`: rejected. The adjacent successor `0x005a8840` is UserPane, but [UID:0003UG] is separated by padding, uses movement-history state, and is called by LivingObjectPane movement handlers.
  - `MapPane`: rejected. No MapPane receiver or field is touched by [UID:0003UG].
  - Socket/PacketBuffer: rejected. [UID:0003UG] does not build or send packets.
  - Generic ObjectPane: rejected. The ring belongs to the local-player LivingObjectPane extension, not the base object-pane position accessor.
- Final direction: keep `CANONICAL_OWNER:00007B`, `EMITTER_UIDS:00007B`.

### 8. Source Split / Boundary Decision

- Issue: determine whether [UID:0003UG] should be merged with [UID:0003UF], split further, or treated as part of UserPane successor.
- Evidence checked: padding bytes, direct call targets, target return, successor prologue and external UserPane evidence.
- Best inference: keep [UID:0003UG] as a standalone exact by-memory function.
- Rejected alternatives:
  - Merge with [UID:0003UF]: rejected by `0x005a8809-0x005a8810` padding and separate direct call targets to `0x005a87e0` and `0x005a8810`.
  - Merge into successor UserPane `0x005a8840`: rejected by `0x005a8832-0x005a8840` padding and different owner/source family.
  - Split [UID:0003UG] further: rejected because the target is one 0x22-byte method body with one guard/body/epilogue structure.
- Implementation impact: no by-memory target split is needed; support padding docs can be improved.

### 9. Formal C++ Blocker Reanalysis

- Existing blocker: final C++ blank until linked-record layout is source-quality.
- Evidence checked: exact body, route proof, field/type naming, parent/emitter gate, generated output state.
- Current conclusion: blocker closed. The layout needed by this helper is only pointer, capacity, and active byte. The remaining original spelling uncertainty is not material enough to keep C++ blank.
- Rejected no-code reasons:
  - No route: false for [UID:0003UG]; two direct callers exist.
  - Raw/no-function: false; docs and binary show modeled `sub_5A8810` body and direct calls.
  - Field names unresolved: no longer blocking; descriptive movement-history names are strong enough.
  - Mixed aggregate: false; this exact child is standalone and attached to [UID:00007B].
- Final direction: populate first-draft C++ in the target block.

## Relationship To Required Siblings

### [UID:0003VE] GetActiveLinkedRecordByIndexRaw

- [UID:0003VE] is still raw/no-entry-route, unlike [UID:0003UG].
- [UID:0003VE] takes a byte index (`movzx edx, byte ptr [ebp+8]`), checks `index < capacity`, computes `records + index * 0x10`, and returns the record only when active byte `+0` is nonzero.
- [UID:0003UG] takes a signed dword index, explicitly rejects negative values, and clears byte `+0` if the index is in range.
- Together they prove record `+0` is an active/valid flag.
- Support update needed: [UID:0003VE] should cross-reference that [UID:0003UG] is route-proven and uses the same active byte but a signed dword index.

### [UID:0003UF] ClearAllLinkedRecords

- [UID:0003UF] loops from zero to capacity and clears the active byte of each stride-`0x10` record.
- [UID:0003UG] performs the same active-byte clear for one signed index.
- Direct callers call [UID:0003UF] at `0x005ab2ea`/`0x005ab637` on correction/mismatch paths, then share the [UID:0003UG] indexed clear at `0x005ab2f4`/`0x005ab641`.
- B012 is separately researching [UID:0003UF]. This report does not depend on B012 finishing, and the [UID:0003UG] conclusions stand independently. Implementation should avoid overwriting B012's accepted future edits; if both reports touch [UID:0003UF], merge facts claim-by-claim.

### [UID:0003UX] RawWaypointPacketHelper

- [UID:0003UX] remains retained no-route raw opcode `0x06` waypoint/path packet helper.
- It fills the same ring after sending a waypoint packet: sets active byte, writes current coordinates, writes `waypointKind`, advances `m_movementHistoryWriteIndex`/waypoint alias.
- For [UID:0003UX], `m_waypointHistoryRecords`, `m_waypointHistoryCapacity`, `m_waypointHistoryWriteIndex`, `LivingObjectWaypointHistoryRecord`, and `waypointKind` are good target-local aliases.
- For [UID:0003UG], the live caller evidence favors class-wide movement-history terminology. The target should mention waypoint-history only as a local alias used by [UID:0003UX].

### [UID:0003UY] RawFacingPacketHelper

- [UID:0003UY] remains retained no-route raw opcode `0x32` movement/facing-history packet helper.
- It fills the same ring after sending direction, history tag, movement-state byte, current X/Y, and trailing sent `0x32`.
- It proves record fields `active`, `tileY`, `tileX`, and `direction` for the fixed movement/facing context.
- [UID:0003UG]'s direct callers [UID:0003UP]/[UID:0003UQ] independently validate `direction` at record `+0x0c` for movement ack/correction, strengthening [UID:0003UY]'s field naming.

## Ranked Ownership Analysis

### 1. [UID:00007B] LivingObjectPane - accepted

- Evidence for:
  - Direct callers are `LivingObjectPane` movement ack/correction handlers.
  - The state ring is movement-history/prediction state in the local-player LivingObjectPane extension.
  - [UID:0001KM], [UID:00007B], and [UID:0000KU] already place the movement-history family in `LivingObjectPane.cpp`.
  - The target uses `thiscall` receiver state at large local-player offsets already documented as adjusted LivingObjectPane/UserPane aggregate offsets.
- Evidence against:
  - Physical address neighborhood is interleaved with UserPane virtuals.
- Decision:
  - Accept [UID:00007B]. Address adjacency is weaker than receiver/caller/state evidence.

### 2. [UID:0000FQ] UserPane - rejected

- Evidence for:
  - Predecessor/successor neighborhood includes UserPane virtual methods; successor `0x005a8840` is UserPane `OnClipBounds`.
- Evidence against:
  - Padding separates [UID:0003UG] from successor.
  - Direct callers are LivingObjectPane movement handlers.
  - Target state is movement-history state, not UserPane UI surface state.
- Decision:
  - Reject as canonical owner. UserPane docs may mention the local event-band exclusion, but source ownership stays with LivingObjectPane.

### 3. [UID:0000KU] LivingObjectPane.cpp by-file page as direct owner - rejected as too broad

- Evidence for:
  - Final output route is `NexusTK/map/LivingObjectPane.cpp`.
- Evidence against:
  - By-structure rules prefer the narrowest semantic owner; this is a class method, and [UID:00007B] clears the 85/85 gate.
- Decision:
  - Keep [UID:0000KU] as source-file route through [UID:00007B], not direct canonical owner.

### 4. No-owner / non-emitting - rejected

- Evidence for:
  - None after route recheck.
- Evidence against:
  - Reconstructable true, direct owner known, emitter route valid, direct callers found, C++ body exact.
- Decision:
  - Reject. This target should not remain a blank emitter after implementation.

## Score Rationale

Recommended target metadata:

```text
COMPLETION:90
CONFIDENCE:92
CANONICAL_OWNER:00007B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00007B
RECONSTRUCTION_CPP: populated with the first-draft method body
```

Why completion `90`:

- Exact body bytes and disassembly are documented.
- Signed dword index bounds behavior is resolved.
- Active-byte-only clear semantics are resolved.
- Direct caller route is proven by two rel32 calls in live movement handlers.
- Owner/emitter/source placement are supported by caller/state evidence.
- Movement-history field vocabulary is strong enough for source emission.
- Support-doc checklist and exact coverage row are available.

Why confidence `92`:

- Behavior, range, route, and owner are direct binary facts.
- Sibling reports and live caller comparisons independently validate the record model.
- Confidence remains below final-audit range because exact original symbol names are not recovered, the final shared field name for record `+0x0c` remains context-dependent, and support docs have not yet been updated claim-by-claim.

## Open Question Closure

Current target open question: "Exact original source spelling of the movement-history fields is not recovered."

- Closure: exact original spelling remains unrecovered, but a safe source-quality descriptive naming set is now available and should be used: `m_movementHistoryRecords`, `m_movementHistoryCapacity`, `m_movementHistoryWriteIndex`, and `LocalMovementHistoryRecord`.
- Evidence checked: target body, live callers, [UID:0003VE]/[UID:0003UF]/[UID:0003UX]/[UID:0003UY], class/file docs, B002/B008/B003 reports.
- Rejected names: pure `linkedRecord`, pure `waypointHistory`, pure `movementBuffer`.
- Score/C++ impact: no longer blocks C++; caps confidence below final audit only.

Current target open question: "Final C++ is blank until the linked-record layout is source-quality."

- Closure: no longer valid. This helper only needs pointer/capacity and active byte semantics, all of which are resolved.
- Evidence checked: exact byte store, direct callers, sibling active-byte getter/clear-all and writers.
- Score/C++ impact: formal C++ should be emitted in the implementation pass.

Potential unresolved issue: exact axis names for record `+4` and `+8`.

- Closure for this target: not a blocker and not within the target's body because [UID:0003UG] does not read or write coordinates. Support docs should keep `tileY/tileX` with offset-based caveat or `coordFromOffset104/coordFromOffset100` until the broader `MapPoint` convention is finalized.
- Score/C++ impact: no impact on [UID:0003UG] C++.

Potential unresolved issue: B012 concurrent [UID:0003UF] research.

- Closure for this target: [UID:0003UG] does not depend on B012. This report can recommend [UID:0003UF] support updates, but implementation must merge with B012 if its report is accepted first.
- Score/C++ impact: no impact on [UID:0003UG].

## Target / Support Implementation Checklist

### Target: `by-memory/0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md`

1. Update metadata to `COMPLETION:90`, `CONFIDENCE:92`, keep `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`.
2. Add best source-facing name `LivingObjectPane::ClearMovementHistoryRecordByIndex(int recordIndex)` while preserving `ClearLinkedRecordByIndex` as a historical/search alias.
3. Add exact byte/disassembly block from this report.
4. Add exact signed bounds behavior:
   - negative index no-op;
   - index `>= this+0x13eb18` no-op;
   - no null pointer guard;
   - `recordIndex * 0x10` stride;
   - clear only record byte `+0`.
5. Add direct caller/reachability proof:
   - `0x005ab2f4` in [UID:0003UP];
   - `0x005ab641` in [UID:0003UQ];
   - no VA/RVA/vtable pointer route found, but direct calls prove liveness.
6. Add boundary proof:
   - predecessor [UID:0003UF] `0x005a87e0-0x005a8809`;
   - padding `0x005a8809-0x005a8810`;
   - target `0x005a8810-0x005a8832`;
   - padding `0x005a8832-0x005a8840`;
   - successor UserPane `OnClipBounds` `0x005a8840-0x005a88cf`.
7. Replace open questions with the resolved movement-history naming narrative and exact C++-readiness rationale.
8. Populate formal C++ with:

```cpp
void LivingObjectPane::ClearMovementHistoryRecordByIndex(int recordIndex)
{
    if (recordIndex >= 0 && recordIndex < m_movementHistoryCapacity)
        m_movementHistoryRecords[recordIndex].active = 0;
}
```

### Sibling / support by-memory docs

`by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`

- Add that [UID:0003UG] is route-proven and clears the same active byte.
- Contrast byte index in [UID:0003VE] with signed dword index in [UID:0003UG].
- Preserve [UID:0003VE]'s no-route status.

`by-memory/0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md`

- Add relation to [UID:0003UG]: clear-all loops active bytes; indexed clear clears one active byte with signed bounds.
- Add caller relationship: correction/mismatch paths call clear-all then share indexed clear.
- Coordinate with B012 if B012's [UID:0003UF] report is accepted first.

`by-memory/0x005ab090-0x005ab410.LivingObjectPaneHandleMovementPacketA.md`

- Add report-level detail for the direct call at `0x005ab2f4`.
- Document payload `+0x0a` read, `& 0x7f` masking, capacity check, active/coordinate/direction comparison, and indexed clear.
- Add `0x005ab2ea` clear-all call on mismatch/correction path.

`by-memory/0x005ab410-0x005ab75d.LivingObjectPaneHandleMovementPacketB.md`

- Add report-level detail for the direct call at `0x005ab641`.
- Document payload `+0x0a` read, `& 0x7f` masking, capacity check, active/coordinate/direction comparison, and indexed clear.
- Add `0x005ab637` clear-all call on mismatch/correction path.

`by-memory/0x005ac7e0-0x005ac99b.LivingObjectPaneRawWaypointPacketHelper.md`

- Keep [UID:0003UX]'s no-route/blank C++ policy.
- Add or preserve that `waypointHistory` is a target-local alias for the same class-wide movement-history ring.
- Cross-reference [UID:0003UG] as the live indexed active-byte clear helper for that ring.

`by-memory/0x005ac9a0-0x005acad5.LivingObjectPaneRawFacingPacketHelper.md`

- Add or preserve that [UID:0003UG]'s live callers validate record `+0x0c` as direction in movement ack/correction contexts.
- Keep [UID:0003UY]'s no-route/blank C++ policy.

`by-memory/0x005a8cf0-0x005a8e67.LivingObjectPaneSendMovementPacket.md`

- Optional but useful: cross-reference [UID:0003UG] in the movement-history family as the live ack/correction clear helper, without claiming this sender calls it.

`by-memory/0x005a9310-0x005a934a.LivingObjectPaneSetMovementBuffer.md`

- No direct [UID:0003UG] update required unless implementation broadens the movement-history field cluster section. Keep this helper distinct from the `+0x13eb14` movement-history ring.

`by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`

- Update stale field table rows that still say `m_linkedRecords` / `m_linkedRecordCount`.
- Recommended text: `m_movementHistoryRecords` / `m_movementHistoryCapacity`, with `linked record` as historical alias.
- Add `m_movementHistoryWriteIndex` if not present in the field cluster.

`by-memory/-ignored.md`

- If support cleanup is accepted, extend the local-player event-band padding entry or add exact padding rows for:
  - `0x005a8809-0x005a8810`: seven `0xcc` bytes between [UID:0003UF] and [UID:0003UG].
  - `0x005a8832-0x005a8840`: fourteen `0xcc` bytes between [UID:0003UG] and `UserPane::OnClipBounds`.

### Class/file support docs

`by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`

- Update the anchor table entry for `0x005a8810` from generic linked-record clear to route-proven movement-history indexed active-byte clear.
- Add direct caller proof and boundary padding.
- Preserve non-emitting split-index disposition.

`by-class/LivingObjectPane.md`

- Update local-player movement-history section with the route-proven [UID:0003UG] semantics:
  - class-wide field names `m_movementHistoryRecords`, `m_movementHistoryCapacity`, `m_movementHistoryWriteIndex`;
  - active-byte-only clear;
  - signed index bounds;
  - `linked record` historical alias;
  - `waypointHistory` target-local alias for [UID:0003UX].

`by-file/LivingObjectPane.md`

- Update proposed contents / movement-history helper row to include [UID:0003UG] as live and C++-eligible.
- Preserve raw no-route blank-C++ policy for [UID:0003UX]/[UID:0003UY].

`by-memory/0x005a2530-0x005b8395.UserPane.md`

- Optional support cleanup: add `0x005a8810` to the list of local-player addresses in the UserPane neighborhood that should not migrate to `UserPane`.
- Preserve `0x005a8840` as UserPane `OnClipBounds`.

## Exact Supervisor-Owned Coverage Row

Do not edit `by-memory/-coverage-report.md` during B-agent implementation. Current `by-memory/-coverage-report.md` has no standalone [UID:0003UG] row and also lacks standalone [UID:0003VE]/[UID:0003UF]/[UID:0003UX] rows in the [UID:0001KM] child block, while [UID:0003UY] is present at line 3380 in the current read-only check.

Placement:

- Insert under the [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions` child block in address order.
- Preferred placement is after the [UID:0003UF] `0x005a87e0-0x005a8809` row when that row exists and before any `0x005a8832-0x005a8840` padding / `0x005a8840` UserPane successor / [UID:0003UH] `0x005a88d0` row.
- If the supervisor has not yet inserted [UID:0003VE]/[UID:0003UF], insert this row in address order between existing [UID:0002RW] and [UID:0003UY] until the missing child rows are restored.

Exact row text:

```text
        - [UID:0003UG][0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex](by-memory/0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md) 0x005a8810-0x005a8832 | method | LivingObjectPaneClearLinkedRecordByIndex : reconstructable : 90% : very-strong : B003 2026-06-19 source-quality pass resolves the live modeled helper as `LivingObjectPane::ClearMovementHistoryRecordByIndex(int recordIndex)`: exact body rejects negative indexes and indexes greater than or equal to `m_movementHistoryCapacity` at `this+0x13eb18`, then clears only the `active` byte at `m_movementHistoryRecords[recordIndex]` using the stride-0x10 record base at `this+0x13eb14`; it does not zero retained coordinate, direction, or waypoint-kind payload bytes and does not touch `m_movementHistoryWriteIndex` at `this+0x13eb1c`. Direct rel32 callers at `0x005ab2f4` and `0x005ab641` in live movement ack/correction handlers prove reachability; those handlers parse the packet history index from payload `+0x0a` masked with `0x7f`, compare active/tileY/tileX/direction fields, and call this helper after match or correction paths. Source-facing vocabulary should use class-wide movement-history/prediction names while preserving `linked record` as a historical alias and `waypointHistory` only as the opcode `0x06` target-local alias. Formal first-draft C++ is recommended because the target is reconstructable, owner/emitter [UID:00007B], route-proven, and source-quality blockers are closed to descriptive naming uncertainty.
```

## Validator Results

Baseline validator command run during this report-only pass:

> Executable block R001 was removed from this report and preserved verbatim in [0003UG-LivingObjectPaneClearLinkedRecordByIndex-source-quality-removed.md](0003UG-LivingObjectPaneClearLinkedRecordByIndex-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`.
- `ok: 1`.
- Relevant target line: `ok 0003UG by-memory/0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md UID header exists`.
- Dry run only: `apply: False`; no generated/project files were written.
- Dry-run side notes included `stats_incremental_skip` and generated autogen/noop diagnostics, but no target validation failure.

Recommended implementation validators after by-* edits:

> Executable block R002 was removed from this report and preserved verbatim in [0003UG-LivingObjectPaneClearLinkedRecordByIndex-source-quality-removed.md](0003UG-LivingObjectPaneClearLinkedRecordByIndex-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If implementation edits optional support files, validate those exact files as well:

> Executable block R003 was removed from this report and preserved verbatim in [0003UG-LivingObjectPaneClearLinkedRecordByIndex-source-quality-removed.md](0003UG-LivingObjectPaneClearLinkedRecordByIndex-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not run a B-agent implementation validator against `by-memory/-coverage-report.md`; supervisor owns applying and validating that shared coverage row.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0003UG-LivingObjectPaneClearLinkedRecordByIndex-source-quality.md`.
- Modified by-* docs: none.
- Modified generated/project reports: none.
- Modified coverage: none.

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003UG","source_path":"executed-b-agent-research/B003/0003UG-LivingObjectPaneClearLinkedRecordByIndex-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
