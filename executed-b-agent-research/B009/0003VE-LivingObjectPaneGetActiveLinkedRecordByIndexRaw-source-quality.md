** TARGET-REPORT-UID:0003VE **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0003VE LivingObjectPaneGetActiveLinkedRecordByIndexRaw Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003VE] `LivingObjectPaneGetActiveLinkedRecordByIndexRaw` assigned to [UID:00007B] `LivingObjectPane` with emitter [UID:00007B], current `COMPLETION:87`, current `CONFIDENCE:89`, `RECONSTRUCTABLE:TRUE`, blank optional emitter position, and populated formal C++ for `LocalMovementHistoryRecord *LivingObjectPane::GetActiveMovementHistoryRecordByIndex(unsigned char recordIndex)`.
- Final disposition: reconstructable source-authored local-player movement-history helper. It is not padding, not a switch-table tail, not compiler glue, and not a `UserPane` virtual. The active MCP session still does not model `0x005a87b0` as an IDA function and shows zero xrefs/code refs/data refs, but the bytes decode as one compact thiscall-style helper and sibling clear helpers are modeled and route-positive.
- Callback result after Gate 1: B009 verified the accepted facts claim-by-claim. Target metadata/formal C++/range/body/source facts were already present; B009 repaired one target-only stale MCP-unavailable wording item with current `supervisor_recovery_20260705` evidence. Support docs already incorporated the accepted facts at same-or-greater detail and were not edited.
- Score recommendation: preserve `COMPLETION:87`, `CONFIDENCE:89`. The old `85/86` state is historical and was superseded by validator command `000000006905`; confidence remains below `90` because the active IDB still has no function object/caller/table/pointer route at `0x005a87b0` and the exact original source spelling is inferred.
- Metadata recommendation: preserve `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, and blank `EMITTER_POSITION_OPTIONAL`.
- C++ recommendation: preserve the exact formal target C++ block shown under `First-Draft C++ Recommendation`. Do not use side/example/body-only C++ for this reconstructable owner/emitter target.

## Target

- Target UID: [UID:0003VE]
- Target path: `source-3/project-documentation/by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/0003VE-LivingObjectPaneGetActiveLinkedRecordByIndexRaw-source-quality.md`
- Current metadata: `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, blank `EMITTER_POSITION_OPTIONAL`.
- Current source state: target formal C++ is populated as `LocalMovementHistoryRecord *LivingObjectPane::GetActiveMovementHistoryRecordByIndex(unsigned char recordIndex)`. The page preserves the retained raw/no-entry-route caveat, exact byte boundaries, zero-route evidence, adjusted-layout caveat, historical `LinkedRecord` alias, and movement-history field names.
- Callback metadata result: preserve the current `87/89` owner/emitter/reconstructable/formal-C++ state; no metadata drift was found.

## Supporting Research

- Historical lifecycle context: the active repair copy was returned from executed archive by validator command `000000006904` at `2026-07-05T08:30:12-04:00` because the archived artifact carried historical `target_uid_unknown: 0003VE`.
- Status-header repair: the active de-executed report copy previously carried top-level `REPORT-VALIDATION-STATUS: needs-revalidation` and `REPORT-REVALIDATION-REASON: target_uid_unknown: 0003VE`; those facts are now historicalized here and the top-level lock lines are removed from the repair artifact. The validator-owned `VALIDATOR-REPORT-HISTORY` footer is preserved unchanged.
- Supervisor scoped target validator command `000000006905` ran at `2026-07-05T08:30:27-04:00` on `by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`, exited `0` with `ok:1`, and reported effects including `path_update`, `completion_update 87`, `confidence_update 89`, `canonical_owner_update 00007B`, `insert_header_blank`, registry/reference-index updates, projected stats update, and `generated_refresh: deferred`.
- B009 implementation callback validator command `000000006921` ran at `2026-07-05T08:55:28-04:00` after the target MCP-wording repair, exited `0` with `ok:1`, reported `missing_ref_uid:13`, `projected_stats_update:1`, `reference_index_add:1`, `stats_incremental_noop:1`, and `generated_refresh: deferred`.
- Remaining validator warnings from commands `000000006905` and `000000006921` are sibling `missing_ref_uid` warnings including `0003UF`, `0003UG`, `0003UP`, and `0003UQ`; they are treated as sibling registry/reference warnings outside this callback scope. No support-doc edit was needed.
- Prior report content and old support recommendations remain useful as historical Rule 26 evidence, but current by-* docs already use the newer movement-history vocabulary rather than the older report's `LinkedRecord` primary naming.

## Current Target State

- Target [UID:0003VE] exists at `by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`.
- Current target metadata is `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, and blank `EMITTER_POSITION_OPTIONAL`.
- Formal C++ is nonblank and uses current support-doc terminology: `LocalMovementHistoryRecord *LivingObjectPane::GetActiveMovementHistoryRecordByIndex(unsigned char recordIndex)`, with `m_movementHistoryCapacity`, `m_movementHistoryRecords`, and byte field `active`.
- Current target summary records exact `0x25` / 37-byte body at raw offset `0x001a7bb0`, three-byte prepad after UserPane animation, eleven-byte postpad before the clear-all helper, unsigned-byte index behavior, active-byte test, zero route evidence, positive sibling controls, owner/emitter [UID:00007B], historical `LinkedRecord` aliases, adjusted-layout caveat, and first-draft C++ populated.
- Current support docs checked for this repair already contain same-or-greater detail for the accepted movement-history model in [UID:00007B] `by-class/LivingObjectPane.md`, [UID:0000KU] `by-file/LivingObjectPane.md`, [UID:0001KM] `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`, [UID:0001DE] `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`, [UID:0003UF], and [UID:0003UG].

## Final Recommendation

Best current source-facing method name: `LivingObjectPane::GetActiveMovementHistoryRecordByIndex(unsigned char recordIndex)`.

Historical/search aliases: `GetActiveLinkedRecordByIndexRaw`, `GetActiveLinkedRecordByIndex`, `FUN_005a87b0`, and `sub_5A87B0`.

Recommended movement-history model:

| Element | Current source-facing direction | Evidence |
| --- | --- | --- |
| Receiver `+0x13eb14` | `m_movementHistoryRecords` / short alias `m_movementHistory` | This getter, [UID:0003UF], [UID:0003UG], [UID:0003UX], and [UID:0003UY] use the same stride-`0x10` ring. |
| Receiver `+0x13eb18` | `m_movementHistoryCapacity` | This getter compares the byte index against it; clear helpers use the same bound. |
| Receiver `+0x13eb1c` | `m_movementHistoryWriteIndex` | Packet writer helpers advance it; this getter does not read it. |
| Record `+0x00` | `active` byte | This getter returns null when it is zero; clear helpers zero exactly this byte. |
| Record `+0x04/+0x08` | `tileY` / `tileX` with offset/axis caveat | Movement packet helpers compare these fields; axis naming remains tied to the broader `MapPoint` convention. |
| Record `+0x0c` | `direction` or waypoint-kind depending on producer | Facing and waypoint helpers share the storage with context-specific meaning. |

Reasoning:

- The body loads only the low byte of the stack argument with `movzx edx, byte ptr [ebp+8]`, so the source parameter was almost certainly `unsigned char`, `BYTE`, or another unsigned 8-bit index type. An `int` source parameter would normally be loaded as a dword; a signed `char` promoted to int would more likely use sign extension when negative values mattered.
- The return is either `0` or `m_movementHistoryRecords + recordIndex * 0x10`, so the source return type should be a pointer to a 16-byte movement-history/prediction record, not a Boolean.
- The first byte of the 16-byte record is tested as nonzero before return. `active` is the best current field name because [UID:0003UF]/[UID:0003UG] clear the same byte and later support docs have converged on `LocalMovementHistoryRecord`.
- Exact original spelling is inferred/descriptive, not symbol-proven. Keep the raw IDA/Ghidra labels only as search aliases.

## Evidence Checked

Documentation read in this pass:

- Target [UID:0003VE] `by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`.
- Parent split index [UID:0001KM] `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`.
- Sibling linked-record helpers [UID:0003UF] `0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md` and [UID:0003UG] `0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md`.
- Owner/support docs [UID:00007B] `by-class/LivingObjectPane.md`, [UID:0000KU] `by-file/LivingObjectPane.md`, and [UID:0001DE] `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`.
- Movement packet siblings [UID:0003UP] `0x005ab090-0x005ab410.LivingObjectPaneHandleMovementPacketA.md`, [UID:0003UQ] `0x005ab410-0x005ab75d.LivingObjectPaneHandleMovementPacketB.md`, raw retained movement-correction helper [UID:0003UO] `0x005aaff0-0x005ab084.LivingObjectPaneRawMovementCorrectionPacketHelper.md`, and raw facing helper [UID:0003UY] `0x005ac9a0-0x005acad5.LivingObjectPaneRawFacingPacketHelper.md`.
- UserPane support/exclusion docs [UID:0000FQ] `by-class/UserPane.md`, [UID:0000P1] `by-file/UserPane.md`, [UID:0001KL] `by-memory/0x005a2530-0x005b8395.UserPane.md`, [UID:0003VD] `0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md`, and [UID:0003VB] `0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`.
- Coverage state in `by-memory/-coverage-report.md` and `auto-generated/-ag-memory-coverage.md`.
- Prior B reports used as leads and rechecked against current evidence:
  - `Agent-B001/research/executed/older/0001KM-livingobject-localplayer-source-split-retry.md`
  - `Agent-B001/research/00007B-LivingObjectPane-class-source-quality.md`
  - `Agent-B002/research/0003UO-LivingObjectPaneRawMovementCorrectionPacketHelper-source-quality.md`

Binary/export evidence checked:

- Current IDA MCP session `supervisor_recovery_20260705` through `http://127.0.0.1:13337/mcp`:
  - `idb_list`: one active adopted worker session for `NexusTK.exe.i64`, pid/worker_pid `19604`, `is_analyzing:false`.
  - `server_health`: `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
  - `lookup_funcs`: `0x005a87ad`, `0x005a87b0`, and `0x005a87d5` return `Not a function`; successor [UID:0003UF] at `0x005a87e0` is `sub_5A87E0` size `0x29`; [UID:0003UG] at `0x005a8810` is `sub_5A8810` size `0x22`; movement-handler positive controls `0x005ab090` and `0x005ab410` are modeled as `sub_5AB090` size `0x380` and `sub_5AB410` size `0x34d`.
  - `get_bytes` for `0x005a87ad` size `51` confirms three `0xcc` bytes, the exact 37-byte helper body, then eleven `0xcc` bytes.
  - `disasm` at `0x005a87b0` returns `<no function>` but decodes the exact instructions: `push ebp`, `mov ebp, esp`, byte argument load, capacity compare at `[ecx+13EB18h]`, record base load at `[ecx+13EB14h]`, `shl edx,4`, active-byte compare, null-return path, and `retn 4`; `0x005a87d5` is alignment before `sub_5A87E0`.
  - `decompile` at `0x005a87b0` fails because no function is modeled there; this is current negative function-object evidence, not an MCP outage.
  - `xrefs_to` / `xref_query` / `find code_ref` / `find data_ref`: zero references to `0x005a87b0`. `find_bytes` for VA/RVA/raw-offset pointer patterns `B0 87 5A 00`, `B0 87 1A 00`, and `B0 7B 1A 00` returns zero matches.
  - Positive route controls in the same MCP pass: [UID:0003UF] has code xrefs from `0x005ab2ea` in `sub_5AB090` and `0x005ab637` in `sub_5AB410`; [UID:0003UG] has code xrefs from `0x005ab2f4` in `sub_5AB090` and `0x005ab641` in `sub_5AB410`; handler starts `0x005ab090` and `0x005ab410` have dispatcher xrefs from `0x005a7a33` and `0x005a7a44` in `sub_5A76C0`.
  - `callees`: no function found for `0x005a87b0`; modeled siblings [UID:0003UF]/[UID:0003UG] have no callees.
- Historical local export/cache evidence remains a lead and is superseded by current MCP where they differ:
  - Old Ghidra export modeled a 37-byte `__thiscall FUN_005a87b0(void *this, byte param_1)` with zero callers, zero callees, no data refs, and decompile semantics equivalent to the current byte/disassembly interpretation.
  - Old local export/cache and support docs for [UID:0003UF]/[UID:0003UG] match current MCP route-positive evidence for `0x005ab2ea`/`0x005ab637` and `0x005ab2f4`/`0x005ab641`.
- Local export cache for [UID:0003UP] and [UID:0003UQ]:
  - Movement handlers compare selected record `+0x08` with one packet position word, record `+0x04` with another position word, and record `+0x0c` with movement direction before clearing all/one linked records.
  - Both handlers call `0x005a87e0` and `0x005a8810`; neither calls `0x005a87b0`.
- Raw PE scan over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:
  - Image base `0x00400000`.
  - `.text` range `0x00401000-0x0060c4ac`, raw `0x400-0x20ba00`.
  - Target raw offset `0x001a7bb0`.
  - `0x005a87ad-0x005a87b0` is three `0xcc` bytes.
  - `0x005a87b0-0x005a87d5` is exactly 37 bytes.
  - `0x005a87d5-0x005a87e0` is eleven `0xcc` bytes.
  - No direct `rel32` call/jump/near conditional branch targets to `0x005a87b0`.
  - No absolute VA, RVA, or raw-offset dword pattern hits for `0x005a87b0`.
  - Positive controls from the same scan find calls to `0x005a87e0` at `0x005ab2ea` and `0x005ab637`, and calls to `0x005a8810` at `0x005ab2f4` and `0x005ab641`.
- `int_convert.py` was used to verify:
  - `0x25` = 37.
  - `0x10` = 16.
  - `0x13eb14` = 1305364.
  - `0x13eb18` = 1305368.
  - `0x1a7bb0` = 1735600.
  - `0x5a87b0` = 5932976.
  - `0x5a87d5` = 5933013.

## Evidence Standards Used

- Current IDA MCP evidence is mandatory for this repair. This report uses narrow, schema-current calls only: `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `disasm`, `decompile`, `callees`, `xrefs_to`, `xref_query`, `find` for code/data refs, `find_bytes` for exact pointer patterns, and `int_convert`.
- Current MCP facts override stale report text saying MCP was unavailable. The old outage wording is historical only and is not used as current evidence.
- Generated/export/cache data and older B reports are leads. They are accepted only where current by-* docs or the current MCP pass corroborates them.
- For C++ decisions, this report follows the current formal-block rule: any recommended C++ is supplied only as exact `RECONSTRUCTION_CPP CODE` header/block insertion text for the target.
- For scores above the prior state but below final-audit range, the report requires exact range/byte proof, current negative route evidence, source-owner/source-route evidence, rejected alternatives, and an explicit reason confidence remains below `90`.

## Raw Byte And Boundary Evidence

PE bytes at `0x005a87ad-0x005a87e0`:

```text
cc cc cc
55 8b ec 0f b6 55 08 3b 91 18 eb 13 00 7d 10
8b 81 14 eb 13 00 c1 e2 04 03 c2 80 38 00 75
02 33 c0 5d c2 04 00
cc cc cc cc cc cc cc cc cc cc cc
```

Disassembly:

```asm
0x005a87b0  55                  push ebp
0x005a87b1  8b ec               mov ebp, esp
0x005a87b3  0f b6 55 08         movzx edx, byte ptr [ebp+8]
0x005a87b7  3b 91 18 eb 13 00   cmp edx, [ecx+0x13eb18]
0x005a87bd  7d 10               jge 0x005a87cf
0x005a87bf  8b 81 14 eb 13 00   mov eax, [ecx+0x13eb14]
0x005a87c5  c1 e2 04            shl edx, 4
0x005a87c8  03 c2               add eax, edx
0x005a87ca  80 38 00            cmp byte ptr [eax], 0
0x005a87cd  75 02               jne 0x005a87d1
0x005a87cf  33 c0               xor eax, eax
0x005a87d1  5d                  pop ebp
0x005a87d2  c2 04 00            retn 4
```

Boundary conclusions:

- The target is an exact single source-shaped helper from `0x005a87b0` through `0x005a87d5`.
- The previous UserPane method [UID:0003VD] ends at `0x005a87ad`; three `0xcc` bytes separate it from this helper.
- Eleven `0xcc` bytes separate this helper from [UID:0003UF] at `0x005a87e0`.
- There is no internal child split; all non-padding bytes in this target belong to one thiscall-style helper.

## Route / Liveness Recheck

Current route state:

| Target | Direct rel32 hits | VA pattern hits | RVA pattern hits | Raw-offset pattern hits | Meaning |
| --- | ---: | ---: | ---: | ---: | --- |
| `0x005a87b0` | 0 | 0 | 0 | 0 | No proven entry route to this raw getter. |
| `0x005a87e0` | 2 | 0 | 0 | 0 | Live calls from movement handlers at `0x005ab2ea` and `0x005ab637`. |
| `0x005a8810` | 2 | 0 | 0 | 0 | Live calls from movement handlers at `0x005ab2f4` and `0x005ab641`. |
| `0x005aaff0` | 0 | 0 | 0 | 0 | Raw retained movement-correction helper comparison. |
| `0x005ab090` | 1 | 0 | 0 | 0 | Positive live movement-handler control; call at `0x005a7a33`. |
| `0x005ab410` | 1 | 0 | 0 | 0 | Positive live movement-handler control; call at `0x005a7a44`. |

Interpretation:

- The route scan is strong negative evidence for direct reachability of `0x005a87b0`. It covers ordinary direct calls/jumps and common static pointer encodings in the loaded PE.
- It is not proof that the helper was not in original source. In a VC6/early-2000s non-function-section build, an unreferenced private method or file-local helper can remain in the linked object if the object file is pulled in for other methods in the same translation unit.
- The body is too semantic to classify as compiler-generated filler: it reads a class state pointer/count pair, checks a record active flag, and returns a record pointer.
- Because [UID:0003UF] and [UID:0003UG] are live and use the same pointer/count/active byte, the best explanation is a retained source helper in the `LivingObjectPane` local-player movement-history family whose direct caller was removed, inlined elsewhere, hidden behind an indirect route not captured by the scan, or left unused in source.

## Heuristic / Inference Reanalysis And Validation

### Raw Helper Status

- Existing issue: IDA did not model the target as a function in the older split report, while Ghidra/export cache does model a function start.
- Evidence checked: current target bytes, Ghidra export, sibling IDA/Ghidra exports, raw PE boundary bytes, route scans, parent split report, class/file pages.
- Best inference: source-authored raw helper, not compiler glue. The function shape is ordinary thiscall with `retn 4`, no thunk jump, no scalar-delete flags, no vtable adjustment, no import stub, no SEH frame, and no switch-table data.
- Rejected alternatives:
  - Padding: rejected because the target has a complete prologue, body, conditional checks, and epilogue between byte-proven `0xcc` padding spans.
  - UserPane switch-table tail: rejected because switch-table spans are already byte-accounted at [UID:0003VA] and [UID:0003VC]; this body contains executable logic and uses LivingObjectPane linked-record state.
  - Compiler-generated thunk: rejected because there is no `this` adjustment and no tail jump to another method.
  - CRT/runtime helper: rejected because it reads game object state at large local-player offsets and sits between UserPane/LivingObjectPane helpers in `.text`.

### Source-Facing Name And Signature

- Existing issue: `LivingObjectPaneGetActiveLinkedRecordByIndexRaw` was descriptive but field/type/signature status was still provisional.
- Evidence checked: instruction-level argument load, Ghidra signature, sibling clear helpers, movement packet handler comparisons.
- Best inference:
  - Current method name: `GetActiveMovementHistoryRecordByIndex`.
  - Historical/search alias: `GetActiveLinkedRecordByIndex`.
  - Documentation filename may retain `Raw` because no entry route is proven.
  - Signature: `LocalMovementHistoryRecord *__thiscall LivingObjectPane::GetActiveMovementHistoryRecordByIndex(unsigned char recordIndex)`.
  - Return type: `LocalMovementHistoryRecord *` / pointer to 16-byte record.
  - Parameter type: `unsigned char` or `BYTE`; `unsigned char` is preferred in source-facing prose.
- Rejected alternatives:
  - `bool HasLinkedRecord(index)`: rejected because the function returns the record pointer, not only a Boolean.
  - `GetLinkedRecordByIndex` without "active": too weak because inactive records return null even when index is in range.
  - `FindLinkedObjectByIndex`: weaker because the record is a movement/prediction/history record, not an object pointer.
  - `UserPane::Get...`: rejected as canonical method spelling because the helper's state family, sibling helpers, and current owner route are LivingObjectPane.

### Linked-Record Field Names

- Existing issue: `this+0x13eb14`, `this+0x13eb18`, and record fields were provisional.
- Evidence checked:
  - Target reads `this+0x13eb18` as a count bound and `this+0x13eb14` as a base pointer.
  - Target multiplies the index by `0x10` / 16 bytes and tests record byte `+0x00`.
  - [UID:0003UF] clears byte `+0x00` for every record from the same pointer/count pair.
  - [UID:0003UG] clears byte `+0x00` for one index after a signed index check.
  - [UID:0003UP]/[UID:0003UQ] compare record `+0x04/+0x08` against packet coordinates and record `+0x0c` against movement direction.
  - [UID:0003UO] and older B009/B001 reports used `m_linkedRecords`, `m_linkedRecordCount`, and `LinkedRecord::active`; current support docs supersede those names with movement-history terminology while retaining the older wording as search aliases.
- Best inference:
  - `this+0x13eb14`: `LocalMovementHistoryRecord *m_movementHistoryRecords`.
  - `this+0x13eb18`: `int m_movementHistoryCapacity`.
  - `this+0x13eb1c`: `m_movementHistoryWriteIndex`, used by sibling writers but not read here.
  - Record stride: `0x10` / 16 bytes.
  - `LocalMovementHistoryRecord +0x00`: `unsigned char active` or byte-sized bool; use byte semantics in behavior prose because the binary tests a byte.
  - `LocalMovementHistoryRecord +0x04/+0x08`: coordinate pair, with `tileY`/`tileX` still carrying the project-wide axis-order caveat. Movement handlers compare `+0x08` to one position word and `+0x04` to another.
  - `LocalMovementHistoryRecord +0x0c`: direction/facing byte, or waypoint-kind in [UID:0003UX] target-local wording.
- Adjusted-layout caveat:
  - [UID:00007B] class-level research correctly warns that local-player offsets such as `+0x13eb14` are much larger than the standalone `LivingObjectPane` pool block size and likely belong to the local player/UserPane aggregate viewed through a LivingObjectPane-adjusted pointer.
  - This caveat affects the final class declaration but does not change this target's local source body: the helper still uses those fields through its `this` receiver exactly as a LivingObjectPane local-player helper.
- Rejected alternatives:
  - Movement buffer pointer/count: rejected because deferred packet/user-list buffer fields are documented at `+0x13eb20/+0x13eb24`, not `+0x13eb14/+0x13eb18`.
  - Timer queue: rejected because TimerMgr/TimerHandler state is documented elsewhere and this target has no timer calls or event ids.
  - MapPane object list: rejected because the target does not dereference MapPane state and the pointer/count pair is only seen in local LivingObjectPane movement-history helpers.
  - ObjectPane child list: rejected because object/attached visual lists live in the core object-pane ranges and use different offsets and methods.

### Active Flag Semantics

- Existing issue: active flag meaning needed a final source-quality explanation.
- Evidence checked: target returns null if byte `+0x00` is zero; sibling clear-all and clear-one helpers write zero to the same byte; movement handlers clear records after successful or failed prediction reconciliation.
- Best inference: `active` means the movement-history slot is currently valid for matching or prediction reconciliation. Clearing it invalidates the slot without freeing or compacting the array.
- Rejected alternatives:
  - Object lifetime flag: too broad; records are fixed-stride entries in a separate pointer array, and clear helpers only zero a byte rather than destructing records.
  - Dirty/sync flag: weaker because the getter refuses to return inactive records, and movement handlers use the record as a prediction match candidate.
  - Linked object visibility flag: no render/visibility calls in this target; usage is movement packet reconciliation.

## Positive Evidence Summary

- Current MCP bytes/disassembly prove a compact source-shaped helper at `0x005a87b0-0x005a87d5`: byte argument load, capacity compare, record-base load, `index * 0x10`, active-byte test, null-return path, and `retn 4`.
- Current MCP `get_bytes` confirms three `0xcc` bytes before the helper and eleven `0xcc` bytes before the successor, matching the target page's exact range and raw-boundary proof.
- Current MCP positive controls prove the sibling clear helpers are live: [UID:0003UF] from `0x005ab2ea`/`0x005ab637` and [UID:0003UG] from `0x005ab2f4`/`0x005ab641`.
- The helper reads the same adjusted local-player movement-history pointer/capacity fields as [UID:0003UF]/[UID:0003UG], and support docs now resolve the record model as `LocalMovementHistoryRecord` with `active`, coordinate fields, and context-specific direction/waypoint byte.
- [UID:00007B] `LivingObjectPane`, [UID:0000KU] `LivingObjectPane.cpp`, and [UID:0001KM] local-player extension docs already record [UID:0003VE] as retained LivingObjectPane movement-history material rather than UserPane code.

## Negative Evidence Summary

- Current MCP `lookup_funcs` says `0x005a87b0` is not a function; `decompile` fails at that address for the same reason. This caps confidence and must remain in the target/support docs.
- Current MCP xref checks find zero xrefs, zero code refs, zero data refs, and zero VA/RVA/raw-offset pointer-pattern matches for `0x005a87b0`.
- No current evidence proves a live caller, vtable slot, jump table, function pointer, or dispatcher route into the raw helper.
- UserPane ownership is negative: the predecessor [UID:0003VD] ends before the three-byte prepad and the helper uses LivingObjectPane local-player movement-history state.
- Padding, switch-table, compiler thunk, CRT/runtime helper, Boolean predicate, movement-buffer/deferred-packet state, MapPane object list, and ObjectPane child-list interpretations remain rejected by the byte shape and touched fields.

## Ranked Ownership Analysis

Ranked ownership/source placement:

1. [UID:00007B] `LivingObjectPane` / [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp` - accepted.
   - Evidence for: linked-record pointer/count state is in the LivingObjectPane local-player movement family; adjacent live helpers [UID:0003UF]/[UID:0003UG] are LivingObjectPane methods; [UID:0001KM] local-player split index already classifies this child as LivingObjectPane after excluding UserPane methods and switch-table spans; file/class support pages include movement-history helpers in `LivingObjectPane.cpp`.
   - Evidence against: no direct caller route and the large local-player field offsets are adjusted-layout fields, not standalone `0x20c` LivingObjectPane allocation fields. This caps confidence but does not make `UserPane` the better owner.
   - Decision: keep owner/emitter [UID:00007B].
2. [UID:0000FQ] `UserPane` / [UID:0000P1] `UserPane.cpp` - rejected as canonical owner.
   - Evidence for: the helper physically sits after a UserPane animation/update virtual and before more local-player methods; UserPane owns the surrounding event dispatcher surface.
   - Evidence against: the previous UserPane method ends at `0x005a87ad`, three bytes of padding separate it, and the helper touches linked-record fields used by LivingObjectPane movement helpers. UserPane is a consumer/aggregate context, not the direct source owner for this helper.
   - Decision: keep UserPane support docs as an exclusion note only.
3. [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions` aggregate - rejected as direct owner/emitter.
   - Evidence for: the target is contained in that address neighborhood.
   - Evidence against: [UID:0001KM] is intentionally a non-emitting mixed split index with `CANONICAL_OWNER:NONE`; exact child pages carry ownership.
   - Decision: keep [UID:0001KM] as context only.
4. No-owner/non-emitting - rejected.
   - Evidence for: no direct entry route.
   - Evidence against: behavior, field family, sibling helpers, and owner/source placement are strong. No-route is a liveness caveat, not enough to undo source ownership.
   - Decision: do not demote to `CANONICAL_OWNER:NONE` or blank emitter.

## Source Placement

- Current source route: [UID:0003VE] emits through [UID:00007B] `LivingObjectPane`, which routes to [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`.
- Placement rationale: the helper is a local-player movement-history method in the LivingObjectPane movement/prediction family. It touches adjusted receiver offsets `+0x13eb14/+0x13eb18`, is adjacent to live LivingObjectPane movement-history clear helpers, and is documented in the LivingObjectPane class/file/support pages with raw/no-entry-route caveats.
- Rejected placement `UserPane.cpp`: physical adjacency to UserPane methods is only address-neighborhood context; the previous UserPane virtual ends at `0x005a87ad`, padding separates the helper, and the touched state belongs to LivingObjectPane movement-history.
- Rejected placement as [UID:0001KM] aggregate output: [UID:0001KM] is a mixed/non-emitting split index and should not own exact child C++.
- Remaining uncertainty: no route proves the helper is live in the shipped client. The source-placement decision is owner/source-shape strong, but confidence remains below final-audit level because the helper may be retained dead/private source.

### Final C++ Readiness

This target is eligible for first-draft C++ if retained raw-helper emission is accepted:

- `RECONSTRUCTABLE:TRUE`.
- Valid nonblank emitter [UID:00007B] routes through [UID:0000KU] to `auto-generated/NexusTK/map/LivingObjectPane.cpp`.
- Current score average is greater than `85`.
- The range covers one compact helper and no sibling code/data.
- The method has no callees, no packet parsing, and no external side effects, so the body is low-risk now that the `LocalMovementHistoryRecord` pointer/capacity/active names are documented.

Remaining C++ caveats:

- There is no direct caller route, so formal source output should be documented as a retained/private raw helper, not as a known live virtual/called method.
- The final class declaration must not blindly place `m_movementHistoryRecords` at `LivingObjectPane +0x13eb14` in the standalone actor allocation without addressing the local-player adjusted-layout warning.
- Exact original method spelling is not symbol-proven; `GetActiveMovementHistoryRecordByIndex` is a descriptive source-quality name, with `GetActiveLinkedRecordByIndex` retained as a historical/search alias.

Exact no-code proof if the supervisor chooses not to emit retained raw no-route helpers:

```text
Keep the formal C++ block blank because `0x005a87b0` has zero direct rel32 call/jump/near-branch routes, zero absolute VA/RVA/raw-offset pointer hits in the local PE scan, and zero callers/data refs in the local Ghidra export. The body is source-authored and belongs to LivingObjectPane, but no live source-use route is proven; emit only after the project accepts retained raw/no-entry helper bodies or a future indirect/pointer/runtime route is found. This no-code proof replaces the stale generic "linked-record field names are provisional" blocker.
```

I do not recommend demoting the target to non-reconstructable or no-owner under this no-code policy. The helper remains source-authored and owner-resolved either way.

## First-Draft C++ Recommendation

Preserve this exact target formal C++ insertion text. This is not a side/sample snippet; it is the formal block content for `by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
LocalMovementHistoryRecord *LivingObjectPane::GetActiveMovementHistoryRecordByIndex(unsigned char recordIndex)
{
    if (recordIndex >= m_movementHistoryCapacity)
        return 0;

    LocalMovementHistoryRecord *record = &m_movementHistoryRecords[recordIndex];
    if (record->active == 0)
        return 0;

    return record;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation notes:

- Use `0` rather than `nullptr` for a mid-2000s/VC6-friendly code style unless the project has standardized on `NULL`.
- `LocalMovementHistoryRecord::active` should be an `unsigned char` or byte-sized Boolean field. The compiler can still emit byte tests for either, but `unsigned char` best matches binary semantics.
- Do not add bounds checks for negative values; the parameter is an unsigned byte. The binary zero-extends it before comparing to the signed `int` count.
- Do not call [UID:0003UF] or [UID:0003UG]; this target has no callees and only returns a pointer.
- If final class layout later models the large `+0x13ebxx` fields in a local-player extension subobject, adapt the field access names while preserving the method body semantics.

## Recommended Target Doc Changes

Target path: `source-3/project-documentation/by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`.

Callback disposition after Gate 1: B009 verified the target against these accepted facts. Items 1-3 and 5-8 were already present at same-or-greater detail; item 4 had one stale current-state phrase saying live MCP was unavailable, so B009 leased the target, repaired that phrase with current `supervisor_recovery_20260705` route-negative evidence, ran the scoped target validator, and released the lease.

1. Preserve metadata `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, and blank `EMITTER_POSITION_OPTIONAL`.
2. Preserve formal target C++ exactly as the `First-Draft C++ Recommendation` formal block above unless supervisor explicitly rejects retained raw-helper emission. If rejected later, the no-code proof must be target-specific: no current IDA function object, zero xrefs/code refs/data refs, zero pointer-pattern hits, no caller/table/dispatch route, and retained source-shaped body evidence.
3. Preserve raw byte/range evidence: `.text` imagebase `0x00400000`, target body `0x005a87b0-0x005a87d5`, size `0x25` / 37 bytes (Verified with `int_convert.py`), raw offset `0x001a7bb0` / 1735600 (Verified with `int_convert.py`), three-byte prepad `0x005a87ad-0x005a87b0`, eleven-byte postpad `0x005a87d5-0x005a87e0`, and exact instruction/byte summary.
4. Preserve current MCP route/liveness evidence: `0x005a87b0` not a function, decompile failure due no function, zero xrefs/code refs/data refs/pointer-pattern hits, positive controls to [UID:0003UF] and [UID:0003UG], and no callees for the raw helper.
5. Preserve field/type resolution: `this+0x13eb14` is `m_movementHistoryRecords`, `this+0x13eb18` is `m_movementHistoryCapacity`, `this+0x13eb1c` is `m_movementHistoryWriteIndex` for sibling writers, record stride is `0x10` / 16 bytes (Verified with `int_convert.py`), record byte `+0x00` is `active`, and record `+0x04/+0x08/+0x0c` carry coordinate and direction/waypoint context with axis caveats.
6. Preserve source-facing method recommendation: `LocalMovementHistoryRecord *LivingObjectPane::GetActiveMovementHistoryRecordByIndex(unsigned char recordIndex)`, with `GetActiveLinkedRecordByIndexRaw` / `GetActiveLinkedRecordByIndex` as historical/search aliases.
7. Preserve rejected alternatives: not `UserPane` owned, not padding, not compiler-generated thunk/glue, not movement-buffer/deferred-packet state, not MapPane/ObjectPane list state, and not no-owner/non-emitting.
8. Preserve score rationale: historical `85/86 -> 87/89` because behavior, bytes, padding, route scan, movement-history fields, active semantics, sibling call controls, owner/source placement, and formal C++ are now documented; confidence remains below `90` because no live route or exact original source spelling is proven.

## Recommended Support Doc Changes

Callback verification result: B009 checked all listed support docs. The accepted support facts were already present at same-or-greater detail, so no support docs were leased, edited, or validated.

### `by-class/LivingObjectPane.md` [UID:00007B]

Verify already-present/no edit unless drift: current class page has `## Local-Player Movement History`, records `m_movementHistoryRecords` / `m_movementHistoryCapacity` / `m_movementHistoryWriteIndex`, `LocalMovementHistoryRecord { active, tileY, tileX, direction }`, [UID:0003VE] first-draft retained raw-helper C++ as `GetActiveMovementHistoryRecordByIndex(unsigned char)`, sibling clear-helper roles, route-positive callsites, and the adjusted-layout warning that `+0x13ebxx` fields are local-player/UserPane aggregate offsets viewed through LivingObjectPane code.

### `by-file/LivingObjectPane.md` [UID:0000KU]

Verify already-present/no edit unless drift: current file page keeps `NexusTK/map/LivingObjectPane.cpp` as source route, records zero-route raw-local starts including `0x005a87b0`, marks [UID:0003VE] as an accepted retained-helper exception with exact body/field/owner evidence and formal C++ as `GetActiveMovementHistoryRecordByIndex(unsigned char)`, and keeps `UserPane.cpp` rejected as source placement.

### `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md` [UID:0001KM]

Verify already-present/no edit unless drift: current split index records [UID:0003VE] as retained `GetActiveMovementHistoryRecordByIndex(unsigned char)` with first-draft exact-child C++, preserves the no-entry-route caveat, keeps UserPane methods/switch tables excluded, and records the B009 support sync in the change log.

### `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md` [UID:0001DE]

Verify already-present/no edit unless drift: current core page's `Local-Player Movement-History Support Note` uses `m_movementHistoryRecords`, `m_movementHistoryCapacity`, `m_movementHistoryWriteIndex`, and `LocalMovementHistoryRecord` terminology, preserves the active/coordinate/direction layout and adjusted-layout caveat, and keeps the broad core split/index non-emitting.

### `by-memory/0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md` [UID:0003UF]

Verify already-present/no edit unless drift: current sibling page already has formal `LivingObjectPane::ClearAllMovementHistoryRecords()` C++, records `m_movementHistoryRecords`, `m_movementHistoryCapacity`, active-byte-only clearing, direct callers `0x005ab2ea`/`0x005ab637`, the [UID:0003VE] getter relationship, and current movement-history terminology.

### `by-memory/0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md` [UID:0003UG]

Verify already-present/no edit unless drift: current sibling page already records `m_movementHistoryRecords`, `m_movementHistoryCapacity`, `m_movementHistoryWriteIndex`, active-byte-only indexed clear, direct callers `0x005ab2f4`/`0x005ab641`, movement handler comparisons, route scan table including [UID:0003VE] as no-entry-route, and formal first-draft C++.

### `by-memory/0x005aaff0-0x005ab084.LivingObjectPaneRawMovementCorrectionPacketHelper.md` [UID:0003UO]

Verify already-present/no edit unless drift: support docs now record opcode `0x04` correction logic as clearing the same movement-history active byte for all records through the same pointer/capacity pair that [UID:0003VE] reads.

### `by-memory/0x005ab090-0x005ab410.LivingObjectPaneHandleMovementPacketA.md` [UID:0003UP] and `by-memory/0x005ab410-0x005ab75d.LivingObjectPaneHandleMovementPacketB.md` [UID:0003UQ]

Verify already-present/no edit unless drift: current sibling movement-handler docs record packet byte `+10 & 0x7f` as the movement-history index, compare selected record active/coordinate/direction fields, call [UID:0003UF] on mismatch/correction paths, call [UID:0003UG] for consumed records, and support [UID:0003VE]'s record-return semantics.

### `by-class/UserPane.md`, `by-file/UserPane.md`, and `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md`

Verify already-present/no edit unless drift: UserPane support/exclusion docs keep [UID:0003VE] out of UserPane ownership because [UID:0003VD] ends before the three-byte padding and the target reads LivingObjectPane local-player movement-history state rather than UserPane event/vtable state.

## Exact Pending Coverage Text

Read-only coverage check during this repair found the generated memory coverage row for [UID:0003VE] in `auto-generated/-ag-memory-coverage.md`; the manual `by-memory/-coverage-report.md` did not show a matching UID/address row in the targeted `rg` check. Do not edit either coverage file during this B-report repair. If the supervisor later chooses a manual coverage sync, use supervisor-owned lifecycle/text only.

Recommended supervisor-owned insertion point: under [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions`, insert after the existing [UID:0003VB] row and before the existing [UID:0003US] row. If the supervisor later applies the fuller [UID:0003V8]-[UID:0003VE] block from the older split report, this row should replace/supersede only the old [UID:0003VE] row text.

Exact row:

```text
        - [UID:0003VE][0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw](by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md) 0x005a87b0-0x005a87d5 | raw helper / active movement-history lookup | LivingObjectPaneGetActiveLinkedRecordByIndexRaw : reconstructable : 87% : very-strong : Source-authored LivingObjectPane local-player movement-history accessor. The exact `0x25` / 37-byte body at raw offset `0x001a7bb0` loads an unsigned byte index, bounds-checks it against `m_movementHistoryCapacity` at `this+0x13eb18`, computes `m_movementHistoryRecords + recordIndex * 0x10` from `this+0x13eb14`, returns null when the record active byte at `+0x00` is zero, and otherwise returns the record pointer. Current MCP finds no function/xref/code-ref/data-ref/VA/RVA/raw-offset route to `0x005a87b0`, while positive controls find live calls to sibling clear helpers [UID:0003UF] at `0x005ab2ea`/`0x005ab637` and [UID:0003UG] at `0x005ab2f4`/`0x005ab641`; keep owner/emitter [UID:00007B], treat source name `GetActiveMovementHistoryRecordByIndex` and fields `m_movementHistoryRecords`/`m_movementHistoryCapacity`/`LocalMovementHistoryRecord::active` as strong descriptive inferences, and preserve populated first-draft formal C++ under retained raw-helper policy.
```

## Claim And Incorporation Ledger

| ID | Claim | Destination / disposition | Action | Verification state |
| --- | --- | --- | --- | --- |
| VE-C01 | Target metadata is `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, blank optional emitter position. | Target by-memory page. | already-present: callback recheck found the accepted header unchanged. | already-present |
| VE-C02 | Target formal C++ should be populated only as exact formal block text for `LocalMovementHistoryRecord *LivingObjectPane::GetActiveMovementHistoryRecordByIndex(unsigned char recordIndex)`. | Target by-memory page; current target already populated. | already-present: formal block matches the report and no side/example C++ was added. | already-present |
| VE-C03 | Current MCP proves no IDA function at `0x005a87b0`, decompile failure due no function, zero xrefs/code refs/data refs/pointer-pattern hits, and no callees. | Target evidence / support route caveat. | applied: target Evidence, Score Rationale, and Changes now cite current `supervisor_recovery_20260705` no-function/decompile/xref/pointer-route proof instead of stale MCP-unavailable wording. | applied |
| VE-C04 | Exact bytes/range are three-byte prepad, 37-byte source-shaped helper, eleven-byte postpad; body reads byte index, compares capacity, computes stride-`0x10` record pointer, tests active byte, returns pointer or zero. | Target byte/evidence sections. | already-present: target Byte Evidence and Behavior sections already matched the accepted range/body facts. | already-present |
| VE-C05 | Positive controls: [UID:0003UF] has callers `0x005ab2ea`/`0x005ab637`; [UID:0003UG] has callers `0x005ab2f4`/`0x005ab641`; movement-handler starts route from `0x005a7a33`/`0x005a7a44`. | Target route/liveness and sibling support docs. | already-present: target route evidence plus [UID:0003UF]/[UID:0003UG]/[UID:0003UP]/[UID:0003UQ] support docs carry the same-or-greater caller details. | already-present |
| VE-C06 | Preferred vocabulary is movement-history: `m_movementHistoryRecords`, `m_movementHistoryCapacity`, `m_movementHistoryWriteIndex`, `LocalMovementHistoryRecord::active`; older `LinkedRecord` names are historical/search aliases. | Target/support docs. | already-present: target, class, file, local-player, core, clear-helper, correction, and movement-handler docs use the movement-history vocabulary and alias caveats. | already-present |
| VE-C07 | Owner/source placement remains [UID:00007B] `LivingObjectPane` through [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`; [UID:0001KM] is context, not direct owner. | Target/class/file/local-player docs. | already-present: target Status/Ownership and class/file/local-player support pages preserve the owner/emitter/source route and [UID:0001KM] context role. | already-present |
| VE-C08 | Rejected alternatives remain rejected: UserPane owner, padding/switch-table, compiler thunk/glue, Boolean predicate, movement/deferred packet buffer, MapPane/ObjectPane list, no-owner/non-emitting. | Target/support rejected alternatives. | already-present: target rejected alternatives and UserPane boundary docs preserve the accepted exclusions. | already-present |
| VE-C09 | Manual coverage must not be edited by B009; generated coverage already has a [UID:0003VE] row while manual coverage sync, if desired, is supervisor-owned. | Coverage note only; no file edit. | excluded-with-reason: coverage files are outside callback edit scope; no manual coverage or generated coverage file was edited. | excluded-with-reason |
| VE-C10 | Validator lifecycle/callback facts: `000000006904` returned the report for rework; `000000006905` scoped target validator previously exited `0`/`ok:1`; callback validator `000000006921` exited `0`/`ok:1` after the target MCP-wording repair with sibling `missing_ref_uid` warnings and deferred generated refresh. | Supporting Research / Validator Results. | applied: Validator Results and Changed Files now record command IDs, timestamps, exit/ok counts, warnings, lease use, generated-refresh state, and validator side effects. | applied |

## Score And Metadata Recommendation

- Preserve target `COMPLETION:87` and `CONFIDENCE:89`.
- Preserve `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, and blank `EMITTER_POSITION_OPTIONAL`.
- Completion stays at `87` because the target has exact range/byte/disassembly evidence, current MCP route-negative proof, owner/source placement, field/type model, rejected alternatives, and formal C++; it is not final-audit-complete because the live route and exact original names remain unproven.
- Confidence stays at `89` because behavior and owner/source route are strong, but the active IDB still has no function object or xref route for `0x005a87b0`.
- The old `85/86` state is historical/pre-repair only and should not be described as current.

## Open Questions With Attempted Resolution

- Live route to `0x005a87b0`: attempted current MCP `lookup_funcs`, `xrefs_to`, `xref_query`, `find code_ref`, `find data_ref`, `find_bytes`, `callees`, and `decompile`; result remains no function and zero route evidence. Resolution: document retained raw/private helper caveat and cap confidence below `90`.
- Exact original names: no symbol/PDB/decorated-name evidence was found. Resolution: use source-quality inferred `GetActiveMovementHistoryRecordByIndex`, `LocalMovementHistoryRecord`, and movement-history field names, with older `LinkedRecord` names retained as historical/search aliases.
- Local-player/UserPane aggregate layout: support docs still warn that `+0x13ebxx` offsets are adjusted aggregate state rather than normal compact `LivingObjectPane` base fields. Resolution: preserve the caveat and do not use this report to freeze a full class declaration.
- Manual coverage row: targeted read-only search found generated coverage current but manual coverage without a matching row. Resolution: do not edit coverage in B009 report-only mode; leave any manual coverage sync to supervisor-owned process.

## Implementation Tracking Checklist

Report-only repair notes: this artifact removed the active top-level revalidation status/reason lines, preserved the validator history footer unchanged, historicalized commands `000000006904`/`000000006905`, replaced stale MCP-unavailable text with current `supervisor_recovery_20260705` evidence, and repaired the C++ decision to exact formal block text only. No by-* docs, generated files, coverage files, validator state, queue/lock files, lifecycle/archive files, or supervisor ledgers were edited during this report-only repair.

Completed implementation/verification callback checklist:

- [x] Leased only the drifted target by-memory page before editing: `by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`. Lease command succeeded for `Agent-B009`.
- [x] Verified target metadata already present: `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Verified target formal C++ already present as the exact formal block for `LocalMovementHistoryRecord *LivingObjectPane::GetActiveMovementHistoryRecordByIndex(unsigned char recordIndex)`; no side/example/body-only C++ was added.
- [x] Applied the only target drift found: stale current-state confidence text saying live MCP was unavailable was replaced/historicalized with current `supervisor_recovery_20260705` no-function/decompile/xref/pointer-route evidence.
- [x] Verified target raw evidence already present: `0x005a87b0-0x005a87d5`, `0x25` / 37 bytes, raw offset `0x001a7bb0`, three-byte prepad, eleven-byte postpad, exact disassembly/bytes, `retn 4`, no internal child split, no callees, unsigned-byte index, capacity compare, stride `0x10`, active-byte test, and pointer/null return behavior.
- [x] Verified target source-quality facts already present: `m_movementHistoryRecords`, `m_movementHistoryCapacity`, `m_movementHistoryWriteIndex` as sibling-writer state, `LocalMovementHistoryRecord::active`, coordinate/direction caveats, no negative/null guard additions, and adjusted local-player/UserPane aggregate caveat.
- [x] Verified target owner/source facts already present: direct owner/emitter [UID:00007B], source route [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`, [UID:0001KM] as context only, and UserPane/no-owner/non-emitting/padding/compiler-thunk alternatives rejected.
- [x] Verified support docs were already present at same-or-greater detail and required no edits: `by-class/LivingObjectPane.md`, `by-file/LivingObjectPane.md`, `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`, `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`, `by-memory/0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md`, `by-memory/0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md`, `by-memory/0x005aaff0-0x005ab084.LivingObjectPaneRawMovementCorrectionPacketHelper.md`, `by-memory/0x005ab090-0x005ab410.LivingObjectPaneHandleMovementPacketA.md`, `by-memory/0x005ab410-0x005ab75d.LivingObjectPaneHandleMovementPacketB.md`, `by-class/UserPane.md`, `by-file/UserPane.md`, and `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md`.
- [x] Ran scoped target validator after the target edit: command `000000006921`, timestamp `2026-07-05T08:55:28-04:00`, exit `0`, `ok:1`, warnings `missing_ref_uid:13`, side effects `projected_stats_update:1`, `reference_index_add:1`, `stats_incremental_noop:1`, `generated_refresh: deferred`.
- [x] Released the target lease immediately after validation; unlease command succeeded for `Agent-B009`.
- [x] Did not edit support docs, generated `auto-generated/-ag-*` files, `by-memory/-coverage-report.md`, validator state, queue/lock files, lifecycle/archive files, executed-report records, supervisor ledgers, or report history footer. Validator-owned projected stats changed only through the required scoped validator.
- [x] Did not run `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, registry commands, manual report moves, or manual coverage edits.

## IDA Rename / Type / Comment Recommendations

Function:

- `0x005a87b0`: if IDA function creation/rename is later authorized outside this report-only pass, name/comment as `LivingObjectPane::GetActiveMovementHistoryRecordByIndex` with `GetActiveLinkedRecordByIndexRaw` retained as an alias/search note.
- Type: `LocalMovementHistoryRecord *__thiscall LivingObjectPane::GetActiveMovementHistoryRecordByIndex(unsigned char recordIndex)`.
- Comment: "Raw no-entry-route LivingObjectPane local-player movement-history accessor. Bounds-checks byte index against m_movementHistoryCapacity, returns zero if inactive, otherwise returns &m_movementHistoryRecords[recordIndex]."

Sibling functions:

- `0x005a87e0`: rename/comment as `LivingObjectPane::ClearAllMovementHistoryRecords`. Type `void __thiscall LivingObjectPane::ClearAllMovementHistoryRecords()`.
- `0x005a8810`: rename/comment as `LivingObjectPane::ClearMovementHistoryRecordByIndex`. Type `void __thiscall LivingObjectPane::ClearMovementHistoryRecordByIndex(int recordIndex)`.

Fields/types:

- Receiver `+0x13eb14`: `LocalMovementHistoryRecord *m_movementHistoryRecords` (strong descriptive inference, local-player adjusted-layout caveat).
- Receiver `+0x13eb18`: `int m_movementHistoryCapacity` (strong descriptive inference).
- Receiver `+0x13eb1c`: `m_movementHistoryWriteIndex` for sibling packet writers; not used by this target.
- `LocalMovementHistoryRecord +0x00`: `unsigned char active`.
- `LocalMovementHistoryRecord +0x04`: coordinate field; use `tileY` / `coordFromOffset104` only with the existing axis caveat.
- `LocalMovementHistoryRecord +0x08`: coordinate field; use `tileX` / `coordFromOffset100` only with the existing axis caveat.
- `LocalMovementHistoryRecord +0x0c`: `unsigned char direction` / `facing`, or waypoint-kind in the [UID:0003UX] context.

IDA comments:

- At `0x005a87ad`: "three-byte int3 alignment after UserPane::OnAnimationStep before raw LivingObjectPane movement-history helper."
- At `0x005a87d5`: "eleven-byte int3 alignment before LivingObjectPane::ClearAllLinkedRecords."
- At movement handler callsites `0x005ab2ea`, `0x005ab637`, `0x005ab2f4`, and `0x005ab641`: "positive route controls for movement-history clear helpers; no matching route currently found to getter 0x005a87b0."

## Rejected Alternatives Summary

- Demote to no-owner/non-emitting: rejected because owner/source placement and behavior are strong; no-route only caps confidence and controls C++ policy.
- Move to UserPane: rejected because this is not a UserPane virtual and uses LivingObjectPane movement-history state.
- Treat as generated/padding: rejected by complete executable semantics between `0xcc` padding spans.
- Name it a movement-buffer helper: rejected because movement/deferred packet buffers live at other offsets; this target uses a pointer/count array of 16-byte records with an active byte.
- Emit class-level fields without adjusted-layout caveat: rejected because `+0x13ebxx` fields conflict with the standalone `LivingObjectPane` pool allocation size and likely belong to local-player/UserPane aggregate state viewed through a LivingObjectPane-adjusted receiver.

## Validator Results

- B009 ran no validators during this report-only repair and did not edit by-* docs.
- Incorporated supervisor lifecycle command `000000006904`: returned executed archive copy to active B009 research at `tools/leaser/Agents/Agent-B009/research/0003VE-LivingObjectPaneGetActiveLinkedRecordByIndexRaw-source-quality.md`, timestamp `2026-07-05T08:30:12-04:00`.
- Incorporated supervisor scoped target validator command `000000006905`: `python .\tools\validator.py --mode file --file by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md --apply --queue-timeout 240`, timestamp `2026-07-05T08:30:27-04:00`, exit `0`, `ok:1`, effects `path_update`, `completion_update 87`, `confidence_update 89`, `canonical_owner_update 00007B`, `insert_header_blank`, autogen registry/reference index updates, projected stats update, and `generated_refresh: deferred`.
- Remaining warnings from `000000006905`: sibling `missing_ref_uid` warnings including `0003UF`, `0003UG`, `0003UP`, and `0003UQ`; this report treats them as sibling registry/reference warnings outside report-only edit scope.
- B009 callback scoped target validator command `000000006921`: `python .\tools\validator.py --mode file --file by-memory\0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md --apply --queue-timeout 240`, timestamp `2026-07-05T08:55:28-04:00`, exit `0`, scanned markdown files `1`, `ok:1`, `missing_ref_uid:13`, `projected_stats_update:1`, `reference_index_add:1`, `stats_incremental_noop:1`, `generated_refresh: deferred`, `generated_refresh_command_id: 000000006921`, `generated_refresh_timestamp: 2026-07-05T08:55:28-04:00`.
- Warnings from `000000006921`: repeated sibling `missing_ref_uid` rows for `0003UG`, plus `0003UP` and `0003UQ`; three more rows were suppressed by non-verbose output. These are existing sibling reference-index warnings and did not require support-doc edits.

## Changed Files

- Modified by callback: `source-3/project-documentation/by-memory/0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md`.
- Modified by callback: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/0003VE-LivingObjectPaneGetActiveLinkedRecordByIndexRaw-source-quality.md`.
- Validator side effect from scoped `--apply`: `source-3/project-documentation/project-level/-auto-completion-stats.md` projected path completion section updated.
- No support by-* docs edited. No generated `auto-generated/-ag-*` files, `by-memory/-coverage-report.md`, validator state, queue/lock files, lifecycle/archive files, executed-report records, supervisor ledgers, report moves, manual coverage edits, or `VALIDATOR-REPORT-HISTORY` footer edits.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003VE","source_path":"executed-b-agent-research/B009/0003VE-LivingObjectPaneGetActiveLinkedRecordByIndexRaw-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- {"agent":"B009","command_id":"000000006904","destination_path":"tools/leaser/Agents/Agent-B009/research/0003VE-LivingObjectPaneGetActiveLinkedRecordByIndexRaw-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B009/0003VE-LivingObjectPaneGetActiveLinkedRecordByIndexRaw-source-quality.md","timestamp":"2026-07-05T08:30:12-04:00"} -->
<!-- {"agent":"B009","command_id":"000000006923","destination_path":"executed-b-agent-research/B009/0003VE-LivingObjectPaneGetActiveLinkedRecordByIndexRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0003VE-LivingObjectPaneGetActiveLinkedRecordByIndexRaw-source-quality.md","timestamp":"2026-07-05T09:00:58-04:00","uid":"0003VE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
