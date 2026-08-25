** TARGET-REPORT-UID:0002CC **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002CC ObjectListTypeSpecificIndexDispatch Source-Quality Report

Agent: B006
Assignment: report-only source-quality research for [UID:0002CC] `by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md`
Report path: `tools/leaser/Agents/Agent-B006/research/0002CC-ObjectListTypeSpecificIndexDispatch-source-quality.md`
Date: 2026-06-26

## Final Recommendation

Promote [UID:0002CC] from a documented-but-blank dispatch helper to a formal source-ready ObjectList method:

- Source-facing method: `ObjectList::GetTypedObjectKey(ObjectPane *object)`
- Conceptual return role: encoded ObjectList key, represented as `unsigned int` in first-draft C++.
- Not-found sentinel: `kObjectListKeyNotFound = 0xffffffffu`.
- Metadata recommendation: `COMPLETION:90`, `CONFIDENCE:90`, `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`, blank emitter position.
- C++ handling: populate the target `RECONSTRUCTION_CPP CODE` block with the formal switch body below.

This body is not a pure "index" dispatcher. It returns the exact ObjectList key family used by `ObjectListEncodedKeyResolve`: flat list indices for some object types, prefixed direct-list keys for other object types, and row/index packed keys for row-list storage. The current title can stay as historical documentation, but the source-facing name should move away from "index" and toward typed ObjectList key recovery.

## Formal Reconstruction C++

Use this exact C++ block for [UID:0002CC] if the report is accepted:

```cpp
unsigned int ObjectList::GetTypedObjectKey(ObjectPane *object)
{
    enum { kObjectListKeyNotFound = 0xffffffffu };

    switch (object->m_objectType) {
    case 0:
        return FindPrimaryCellKey(object);
    case 1:
        return FindSecondaryCellKey(object);
    case 2:
        return FindPrimaryRowKey(object);
    case 3:
        return FindTertiaryRowKey(object);
    case 4:
        return FindSecondaryRowKey(object);
    case 5:
        return FindExtendedRowKey(object);
    case 6:
        return FindPrimaryGlobalKey(object);
    case 7:
        return FindSecondaryGlobalKey(object);
    case 8:
        return FindAlternateGlobalKey(object);
    default:
        return kObjectListKeyNotFound;
    }
}
```

The function intentionally has no null check. The binary dereferences the object pointer immediately to read `object + 0xf8`, so a defensive source-level null check would not match the observed body.

The code uses numeric `m_objectType` cases on purpose. The storage-family helper names are now strong enough for implementation, but the full `ObjectPaneType` enum labels are not final enough to introduce source enum names in this exact page.

## MCP Evidence Status

IDA MCP was available and responsive. Evidence was collected from the active session only; no MCP process management or IDA DB edit was performed.

- MCP endpoint used by workflow: `http://127.0.0.1:13337/mcp`.
- `initialize` returned server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- `tools/list` exposed the required inspection tools, including `server_health`, `idb_list`, `lookup_funcs`, `entity_query`, `decompile`, `disasm`, `xrefs_to`, `callees`, and `get_bytes`.
- `idb_list` showed one active session, `80de0a67`, for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `is_analyzing:false`; backend process `26892`.
- JSON-RPC `server_health` id `10` returned status `ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, and `hexrays_ready:true`.

No fallback-only report path was used.

## Target State Before Report

[UID:0002CC] currently records:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00009Q`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00009Q`
- blank formal C++ block

The page already has good range and dispatch evidence, but it leaves the final helper name, return type, sentinel name, and object parameter type as open questions. This report resolves those blockers to implementation-ready quality without claiming original spelling beyond the evidence.

## Live IDA MCP Function Evidence

JSON-RPC `lookup_funcs` id `11` returned:

| Address | MCP result |
| --- | --- |
| `0x005322d0` | `sub_5322D0`, size `0x71` |
| `0x00532341` | not a function |
| `0x00532344` | not a function |
| `0x00532370` | `sub_532370`, size `0xd3` |
| `0x00532450` | not a function |

JSON-RPC `entity_query` id `12` over `0x00532180-0x00532530` returned four modeled functions:

| Start | Name | Size | Role |
| --- | --- | ---: | --- |
| `0x00532180` | `sub_532180` | `0x11e` | predecessor encoded-key resolver, [UID:0002CB] |
| `0x005322d0` | `sub_5322D0` | `0x71` | this target body |
| `0x00532370` | `sub_532370` | `0xd3` | successor object-id lookup, [UID:0002CD] |
| `0x00532530` | `sub_532530` | `0x4` | next ObjectList island |

This confirms the target source body ends at `0x00532341` and that the `0x00532341-0x00532370` tail is owned switch-table/alignment data, not a hidden neighboring function.

## Live IDA MCP Decompile Evidence

JSON-RPC `decompile` id `13` for `0x005322d0` returned a thiscall value dispatcher:

- Prototype shape: `unsigned int __thiscall sub_5322D0(_DWORD *this, int a2)`.
- Dispatch value: `*(_BYTE *)(a2 + 248)`, matching `ObjectPane::m_objectType` at `+0xf8`.
- Default return: `-1`.
- Cases `0..8` tail-call the nine type-specific encoded-key lookup helpers.

Case-to-helper mapping:

| Case | Target | Source-facing helper | Return family |
| ---: | --- | --- | --- |
| `0` | `sub_535F90` | `FindPrimaryCellKey` | direct index |
| `1` | `sub_535FD0` | `FindSecondaryCellKey` | `0x10000000 | index` |
| `2` | `sub_536010` | `FindPrimaryRowKey` | row/index key |
| `3` | `sub_535EC0` | `FindTertiaryRowKey` | row/index key |
| `4` | `sub_5360E0` | `FindSecondaryRowKey` | row/index key |
| `5` | `sub_535DF0` | `FindExtendedRowKey` | row/index key |
| `6` | `sub_5361B0` | `FindPrimaryGlobalKey` | `0x60000000 | index` |
| `7` | `sub_5361F0` | `FindSecondaryGlobalKey` | `0x70000000 | index` |
| `8` | `sub_536230` | `FindAlternateGlobalKey` | `0xc0000000 | index` |

The decompiler's `unsigned int` return type is the safest first-draft source type. A later header pass may introduce `ObjectListKey`, but this exact reconstruction should not depend on an undeclared typedef.

## Live IDA MCP Disassembly Evidence

JSON-RPC `disasm` id `14` for `0x005322d0` reported 37 instructions:

- `0x5322d0`: normal prologue.
- `0x5322d3`: loads the object argument from `[ebp+arg_0]`.
- `0x5322d6`: reads signed byte at `[eax+0f8h]`.
- `0x5322dd`: compares type value with `8`.
- `0x5322e0`: branches to default for out-of-range values.
- `0x5322e2`: jumps through `ds:jpt_5322E2[edx*4]`.
- Each case restores the object argument and tail-jumps to a typed helper.
- `0x53233a`: default sets `eax` to `0xffffffff`, pops `ebp`, and returns with `retn 4`.

The disassembly supports a direct switch reconstruction. It also explains why the callee summary may omit ordinary callees: the body uses tail jumps to the helper family.

## Raw Byte and Table Evidence

JSON-RPC `get_bytes` id `18` for `0x005322d0` size `160` returned the target body and owned post-body bytes:

- Function starts with `55 8b ec 8b 45 08 0f be 90 f8 00 00 00 83 fa 08 77 58 ff 24 95 44 23 53 00`.
- Default tail includes `83 c8 ff 5d c2 04 00`.
- `0x00532341-0x00532344` is a three-byte NOP/alignment span: `0f 1f 00`.
- `0x00532344-0x00532368` is the nine-dword switch table:
  - `0x005322fb`
  - `0x00532304`
  - `0x0053230d`
  - `0x005322f2`
  - `0x00532316`
  - `0x005322e9`
  - `0x0053231f`
  - `0x00532328`
  - `0x00532331`
- `0x00532368-0x00532370` is eight bytes of `0xcc` padding before [UID:0002CD].

Recommended target range text should refine the current broad "embedded jump table and alignment" statement to:

- body: `0x005322d0-0x00532341`
- post-body alignment: `0x00532341-0x00532344`
- jump table: `0x00532344-0x00532368`
- padding before successor: `0x00532368-0x00532370`

All of these bytes remain owned by [UID:0002CC] for documentation coverage purposes, but only `0x005322d0-0x00532341` is source-authored code.

## Xref and Caller Evidence

JSON-RPC `xrefs_to` id `15` for `0x005322d0` returned six code xrefs:

| Caller address | Function | Existing support role |
| --- | --- | --- |
| `0x00506af0` | `sub_506AE0` | `MapPane::FindPreviousSelectableObject` wrapper |
| `0x00506b40` | `sub_506B30` | `MapPane::FindNextSelectableObject` wrapper |
| `0x00506b90` | `sub_506B80` | item-target previous/up wrapper |
| `0x00506be0` | `sub_506BD0` | item-target next/down wrapper |
| `0x00506c30` | `sub_506C20` | living-target filtered previous/up wrapper |
| `0x00506c80` | `sub_506C70` | living-target filtered next/down wrapper |

The same `xrefs_to` call reported a data xref to the switch table at `0x00532344` from `0x005322e2`.

JSON-RPC `lookup_funcs` id `20` and `analyze_component` id `21` reconfirmed all six MapPane wrapper starts and showed that each wrapper calls `sub_5322D0`, then one of the accepted `ObjectList::MoveKeyTo...` traversal helpers, then resolves the mutated key through `sub_532180`.

Representative decompiler evidence:

- JSON-RPC `decompile` id `22`, `sub_506AE0`: computes `v3 = sub_5322D0((_DWORD *)this[265], a2)`, passes that key by address to `sub_533170`, then resolves the resulting key through `sub_532180(this[265], v6)` on success.
- JSON-RPC `decompile` id `23`, `sub_506C20`: computes `v4 = sub_5322D0((_DWORD *)this[265], a2)`, passes that key by address and a filter argument to `sub_533A90`, then resolves the resulting key through `sub_532180(this[265], v7)` on success.

This proves the return value is not just a type-specific array index. It is the encoded key seed consumed by the MapPane traversal wrappers.

## Typed Helper Family Evidence

JSON-RPC `xrefs_to` id `16` for the nine typed helper starts shows each helper is reached from this target and from the raw predicate companion [UID:0002CE]:

| Helper start | Xref from 0002CC | Xref from 0002CE body |
| --- | --- | --- |
| `0x00535df0` | `0x005322ed` | `0x0053246e` |
| `0x00535ec0` | `0x005322f6` | `0x0053247e` |
| `0x00535f90` | `0x005322ff` | `0x0053248e` |
| `0x00535fd0` | `0x00532308` | `0x0053249e` |
| `0x00536010` | `0x00532311` | `0x005324ae` |
| `0x005360e0` | `0x0053231a` | `0x005324be` |
| `0x005361b0` | `0x00532323` | `0x005324ce` |
| `0x005361f0` | `0x0053232c` | `0x005324de` |
| `0x00536230` | `0x00532335` | `0x005324ee` |

The predicate helper's xrefs appear with null function ownership because current IDA still does not model `0x00532450` as a function, but the addresses match the raw switch body already accepted in [UID:0002CE].

## Source-Quality Blocker Resolution

| Prior blocker | Resolution |
| --- | --- |
| Final source-facing name | Use `GetTypedObjectKey`. It names the value-returning companion to `ContainsTypedObject` and matches the MapPane traversal use as an encoded-key seed. |
| Return type | Use `unsigned int` in exact C++. Treat `ObjectListKey` as a conceptual future typedef only. |
| Sentinel name | Use `kObjectListKeyNotFound`. It matches [UID:0002BB]/[UID:00023F] support terminology and avoids the weaker local `kInvalidObjectListKey` wording used by older predicate draft code. |
| Object parameter type | Use `ObjectPane *object` for this dispatcher. The body only requires `m_objectType` at `+0xf8`, and the sibling predicate page already uses `ObjectPane *`. |
| Object type enum labels | Keep numeric cases. Do not invent final labels for cases `2`, `4`, `6`, `7`, and `8`. |
| Storage helper names | Use the accepted [UID:0002BB] helper names: `FindPrimaryCellKey`, `FindSecondaryCellKey`, `FindPrimaryRowKey`, `FindTertiaryRowKey`, `FindSecondaryRowKey`, `FindExtendedRowKey`, `FindPrimaryGlobalKey`, `FindSecondaryGlobalKey`, and `FindAlternateGlobalKey`. |
| C++ readiness | Ready for formal C++. The switch body is exact, bounded, and source-authored; the table/padding are compiler output and should remain prose evidence only. |
| Shared helper abstraction with 0002CE | Do not collapse 0002CE into this target or this target into 0002CE. The binary has two concrete switch bodies, so exact by-memory C++ should preserve separate bodies unless a later high-level source factoring pass intentionally changes shape. |

## Type-Harmonization Note

[UID:0002BB] currently emits helper C++ with `LivingObjectPane *object` parameters, while [UID:0002CE] already emits `ContainsTypedObject(ObjectPane *object)` and calls the same helpers. This is a support-doc/source-consistency issue, not a blocker for [UID:0002CC].

Recommended implementation handling:

- Keep [UID:0002CC] as `ObjectPane *object`.
- Add support text to [UID:0002BB] and/or [UID:0001VG] explaining that the typed-key helper family receives the same object pointer passed by the dispatcher and predicate helpers.
- If the implementation callback is allowed to adjust support C++ in [UID:0002BB], change the helper-family parameter type from `LivingObjectPane *object` to `ObjectPane *object`, unless a separate type-hierarchy proof shows that every `m_objectType` case in `0..8` is always a `LivingObjectPane`.

This report does not require changing [UID:0002BB] metadata. The important part for [UID:0002CC] is not to introduce casts or derived-class assumptions that are absent from the assembly.

## Rejected Alternatives

- `ObjectList::FindByObjectId` / `FindObjectBySerial`: rejected because this body reads `object + 0xf8` for type dispatch and never compares `object + 0xfc`; [UID:0002CD] owns object-id lookup.
- `ObjectList::ContainsTypedObject`: rejected for this page because [UID:0002CE] owns the boolean predicate. [UID:0002CC] returns the raw key/sentinel.
- `GetTypeSpecificIndex`: rejected as the primary source name because several cases return packed keys, not simple indices.
- `GetObjectListKeyForObject`: acceptable support alias, but weaker as the primary name because it does not express the typed-dispatch pairing with `ContainsTypedObject`.
- `ObjectListTypeSpecificIndexDispatch`: keep as the historical page title, but do not use it as source-facing method text.
- A shared private helper called by both [UID:0002CC] and [UID:0002CE]: rejected for exact by-memory reconstruction because the binary contains two separate concrete switch bodies.
- A null-safe implementation: rejected because the binary dereferences `object` before range-checking the object type.

## Recommended Target Doc Changes

For `by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md`:

- Set `COMPLETION:90`, keep `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`, and blank emitter position.
- Insert the formal `ObjectList::GetTypedObjectKey(ObjectPane *object)` C++ block from this report.
- Update the summary to say the unresolved return/sentinel/helper-name blocker is resolved to `unsigned int`, `kObjectListKeyNotFound`, and the [UID:0002BB] `Find*Key` helper family.
- Refine address-range prose to split body, NOP alignment, nine-dword jump table, and `0xcc` padding exactly.
- Add the 2026-06-26 MCP evidence with session `80de0a67`, JSON-RPC ids `10-18` and `20-24`, and active IDB/process state.
- Update the caller pattern to state that the six MapPane wrappers call this method to seed `ObjectList::MoveKeyTo...` traversal and then resolve the resulting key through [UID:0002CB].
- Move the old open questions into a resolved/rejected-alternatives section, leaving only final enum labels/original spelling as confidence caps.

## Recommended Support Doc Changes

Implementation should update these support docs at report-level useful detail if the report is accepted:

| File | Recommended change |
| --- | --- |
| `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md` | Update the [UID:0002CC] row to `ObjectList::GetTypedObjectKey(ObjectPane *object)`, note `0x00532341-0x00532344` NOP, `0x00532344-0x00532368` jump table, and `0x00532368-0x00532370` padding. |
| `by-class/ObjectList.md` | Add `unsigned int GetTypedObjectKey(ObjectPane *object)` to the ObjectList method surface as the value companion to `ContainsTypedObject`, used by MapPane traversal wrappers. |
| `by-file/ObjectList.md` | Add the same source-placement note under the `ObjectList.cpp` helper inventory and proposed contents. |
| `by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md` | Add a support note that MapPane traversal wrappers call `GetTypedObjectKey`, pass the key by address to `MoveKeyTo...`, then resolve it through this encoded-key resolver. |
| `by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md` | Add a sibling note that `ContainsTypedObject` repeats the same typed dispatch but converts `kObjectListKeyNotFound` to false; optionally rename the local enum from `kInvalidObjectListKey` to `kObjectListKeyNotFound` for terminology consistency. |
| `by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md` | Add a one-line cross-reference that `GetTypedObjectKey` returns this page's encoded key family and default not-found sentinel. |
| `by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md` | Add the [UID:0002CC] dispatcher as the value-returning direct caller and record the `ObjectPane *` parameter harmonization issue. If accepted, change helper parameter C++ to `ObjectPane *object` for consistency with [UID:0002CC]/[UID:0002CE]. |
| `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md` | Add the source-facing name `GetTypedObjectKey` to the key-traversal sequence that feeds `MoveKeyToPrevious/Next...` helpers. |
| `by-type/by-struct/ObjectListLayout.md` | Add the 0002CC case-to-field cross-check for offsets `+0x14`, `+0x18`, `+0x1c`, `+0x24`, `+0x20`, `+0x28`, `+0x2c`, `+0x30`, and `+0x34`. |
| `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md` | Refine the six-wrapper table to say the MapPane wrappers first obtain the seed key with `ObjectList::GetTypedObjectKey(ObjectPane *object)`, then call the relevant `MoveKeyTo...` helper, then resolve the result. |
| `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md` | Optional broad-parent support note only. The exact child `0x00506970-0x00506cdd` already carries the real wrapper detail, so this page only needs a concise summary if touched during callback. |

No [UID:0002CD] support edit is required beyond the target's boundary handoff note. It remains the separate object-id lookup successor.

## IDA Rename and Type Recommendations

Do not edit the IDA DB in this task. If a future IDA hygiene pass is assigned, recommended non-authoritative names are:

- Rename `sub_5322D0` to `ObjectList_GetTypedObjectKey`.
- Type it as `unsigned int __thiscall ObjectList::GetTypedObjectKey(ObjectPane *object)`.
- Name `jpt_5322E2` as `jpt_ObjectList_GetTypedObjectKey`.
- Keep the jump table as data at `0x00532344-0x00532368` and the surrounding alignment/padding as non-source bytes.

## Rule 26 Implementation Readiness

This is not a rare no-improvement report. The source-quality blockers were resolved enough for implementation:

- Exact code body is known and bounded.
- Exact compiler table/alignment ownership is known.
- Source owner and emitter remain [UID:00009Q] ObjectList.
- Return type and sentinel naming are implementation-ready.
- The MapPane caller chain proves the "key" role.
- The sibling predicate relationship is understood and should not be collapsed.
- Remaining uncertainty is capped to original spelling and enum-label names, not reconstruction behavior.

The report recommends a conservative `90/90` rather than a higher score because original method spelling and full `ObjectPaneType` names are still inferred.

## Files Changed During Report Phase

- Created this report only: `tools/leaser/Agents/Agent-B006/research/0002CC-ObjectListTypeSpecificIndexDispatch-source-quality.md`.

No by-* docs were edited. No generated/project-level files, coverage reports, validator/tool state files, or IDA DB files were edited. No leases were taken.

## Files Changed During Implementation Callback

Implementation callback applied the accepted report to:

- `by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md`
- `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`
- `by-class/ObjectList.md`
- `by-file/ObjectList.md`
- `by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md`
- `by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md`
- `by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md`
- `by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md`
- `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md`
- `by-type/by-struct/ObjectListLayout.md`
- `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`
- `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md`

## Validators

Validators were run from `source-3/project-documentation` with:

`python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`

| File | command_id | command_timestamp | Exit | Result | Generated refresh |
| --- | --- | --- | ---: | --- | --- |
| `by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md` | `000000003392` | `2026-06-26T20:39:37-04:00` | `0` | `ok: 1` | deferred, id `000000003392` |
| `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md` | `000000003395` | `2026-06-26T20:39:39-04:00` | `0` | `ok: 1` | deferred, id `000000003395` |
| `by-class/ObjectList.md` | `000000003398` | `2026-06-26T20:39:43-04:00` | `0` | `ok: 1`; pre-existing `missing_ref_target 00023D` warning | deferred, id `000000003398` |
| `by-file/ObjectList.md` | `000000003401` | `2026-06-26T20:39:46-04:00` | `0` | `ok: 1`; pre-existing `missing_ref_uid 0003IO` and `missing_ref_target 00023D` warnings | deferred, id `000000003401` |
| `by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md` | `000000003404` | `2026-06-26T20:39:48-04:00` | `0` | `ok: 1` | deferred, id `000000003404` |
| `by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md` | `000000003407` | `2026-06-26T20:39:51-04:00` | `0` | `ok: 1` | deferred, id `000000003407` |
| `by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md` | `000000003410` | `2026-06-26T20:39:55-04:00` | `0` | `ok: 1` | deferred, id `000000003410` |
| `by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md` | `000000003413` | `2026-06-26T20:39:59-04:00` | `0` | `ok: 1` | deferred, id `000000003413` |
| `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md` | `000000003416` | `2026-06-26T20:40:03-04:00` | `0` | `ok: 1`; pre-existing `missing_ref_target 0001B1` warning | deferred, id `000000003416` |
| `by-type/by-struct/ObjectListLayout.md` | `000000003418` | `2026-06-26T20:40:06-04:00` | `0` | `ok: 1` | deferred, id `000000003418` |
| `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md` | `000000003420` | `2026-06-26T20:40:09-04:00` | `0` | `ok: 1` | deferred, id `000000003420` |
| `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md` | `000000003422` | `2026-06-26T20:40:11-04:00` | `0` | `ok: 1`; pre-existing missing UID/ref warnings for split-child registry entries and `0001AW` | deferred, id `000000003422` |

Lease cleanup proof: B006 validation-batch leases were released immediately after validators; `current_leases.md` check after unlease showed no active B006 entries.

## Implementation Checklist

- [x] Lease only the by-* files that will be edited immediately; abort with `PAUSED_LEASE_CONFLICT` if any are actively leased.
  Proof: initial B006 edit leases were taken only for immediate edit batches. When B014 later held overlapping ObjectList leases until `2026-06-27T00:38:26Z`, editing/validation paused; after recheck at `2026-06-26T20:38:42-04:00`, no callback-file conflict remained, and B006 took a fresh validation-batch lease.
- [x] Update target [UID:0002CC] metadata to `COMPLETION:90`, `CONFIDENCE:90`, owner/emitter unchanged, blank emitter position.
  Proof: `by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md` now has `COMPLETION:90`, `CONFIDENCE:90`, `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Insert the formal `ObjectList::GetTypedObjectKey(ObjectPane *object)` reconstruction C++ in [UID:0002CC].
  Proof: [UID:0002CC] formal `RECONSTRUCTION_CPP CODE` block contains the accepted `unsigned int ObjectList::GetTypedObjectKey(ObjectPane *object)` switch body with numeric cases `0..8` and no null check.
- [x] Add MCP proof in [UID:0002CC]: session `80de0a67`, server-health id `10`, function/table/caller ids `11-18`, and MapPane wrapper ids `20-24`.
  Proof: [UID:0002CC] Raw Code Evidence now records active IDB/process state, server-health id `10`, `lookup_funcs`/`entity_query`/`decompile`/`disasm`/`xrefs_to`/`get_bytes` ids `11-18`, and MapPane wrapper ids `20-24`.
- [x] Refine [UID:0002CC] range prose to body `0x005322d0-0x00532341`, NOP `0x00532341-0x00532344`, table `0x00532344-0x00532368`, padding `0x00532368-0x00532370`.
  Proof: [UID:0002CC] Address Range and Boundary sections now list that exact split and table ownership.
- [x] Add rejected alternatives and resolved naming notes in [UID:0002CC].
  Proof: [UID:0002CC] now records `GetTypedObjectKey`, `unsigned int`, `kObjectListKeyNotFound`, separate sibling predicate body, rejected `FindByObjectId`/`ContainsTypedObject`/`GetTypeSpecificIndex`/shared-helper/null-safe alternatives, and remaining confidence caps only for original spelling and enum labels.
- [x] Update parent [UID:00023E] with `GetTypedObjectKey` and exact table/alignment ownership.
  Proof: `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md` now names [UID:0002CC] as `ObjectList::GetTypedObjectKey(ObjectPane *object)` and records body/NOP/table/padding ownership.
- [x] Update `by-class/ObjectList.md` with the `GetTypedObjectKey` method surface and MapPane traversal relationship.
  Proof: `by-class/ObjectList.md` method inventory and evidence now include `GetTypedObjectKey`, the typed-key producer role, and the MapPane `GetTypedObjectKey -> MoveKeyTo... -> ResolveObjectListKey` traversal chain.
- [x] Update `by-file/ObjectList.md` with the same source-placement detail.
  Proof: `by-file/ObjectList.md` proposed contents, evidence, and migration notes now keep [UID:0002CC] under `map/ObjectList.cpp` as `ObjectList::GetTypedObjectKey(ObjectPane *object)`, with the exact child carrying the formal method body.
- [x] Update [UID:0002CB] with the `GetTypedObjectKey -> MoveKeyTo... -> EncodedKeyResolve` sequence.
  Proof: `by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md` caller table and caller prose now use `ObjectList::GetTypedObjectKey` as the seed call before `MoveKeyTo...` and final `ObjectList::ResolveObjectListKey`.
- [x] Update [UID:0002CE] sibling note to use `kObjectListKeyNotFound` terminology for the predicate/value pair; change the local enum only if the implementation scope accepts that consistency edit.
  Proof: `by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md` now uses local `kObjectListKeyNotFound` in its formal C++ and documents the repeated switch-body sibling relationship with [UID:0002CC].
- [x] Update [UID:0002BA], [UID:0002BB], and [UID:00023F] support prose with the `GetTypedObjectKey` cross-reference.
  Proof: [UID:0002BA] ties `GetTypedObjectKey` to the encoded-key family and sentinel; [UID:0002BB] records [UID:0002CC] as the value-returning direct caller for all nine helpers; [UID:00023F] adds `GetTypedObjectKey` as the traversal seed before `MoveKeyTo...`.
- [x] Record or resolve the `ObjectPane *` versus `LivingObjectPane *` helper-parameter harmonization in [UID:0002BB].
  Proof: [UID:0002BB] now explicitly documents the `ObjectPane *` dispatcher versus existing `LivingObjectPane *` formal-helper parameter issue and explains why helper signatures were not partially changed in this callback.
- [x] Update [UID:0001VG] ObjectListLayout with the 0002CC case-to-field cross-check.
  Proof: `by-type/by-struct/ObjectListLayout.md` now has the [UID:0002CC] case-to-field table for cases `0..8` and offsets `+0x14`, `+0x18`, `+0x1c`, `+0x24`, `+0x20`, `+0x28`, `+0x2c`, `+0x30`, and `+0x34`.
- [x] Update [UID:00037Q] `MapPaneObjectLookupHelpers` with the seed-key call sequence; update broad [UID:0001AT] only if the supervisor wants a broad-parent summary.
  Proof: [UID:00037Q] six-wrapper table now uses `ObjectList::GetTypedObjectKey(ObjectPane *object)` before the relevant `MoveKeyTo...` helper and final `ObjectList::ResolveObjectListKey`; [UID:0001AT] also has the concise broad-parent summary.
- [x] Run scoped validators from `source-3/project-documentation` for every changed by-* file.
  Proof: 12 scoped validator runs completed with exit `0` and `ok: 1`; command ids `000000003392`, `000000003395`, `000000003398`, `000000003401`, `000000003404`, `000000003407`, `000000003410`, `000000003413`, `000000003416`, `000000003418`, `000000003420`, and `000000003422` are listed in the Validators table.
- [x] Release all leases immediately after the edit/validator batch.
  Proof: B006 unlease command succeeded for all 12 changed by-* files after validators; subsequent `current_leases.md` check showed no active B006 lease entries.
- [x] Reopen this report and replace each accepted checklist item with checked proof, including validator command ids/timestamps/results and lease cleanup proof.
  Proof: this implementation callback section now contains checked proof lines, changed-file list, validator command ids/timestamps/results, generated-refresh state, and lease cleanup proof.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0002CC-ObjectListTypeSpecificIndexDispatch-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0002CC-ObjectListTypeSpecificIndexDispatch-source-quality.md","timestamp":"2026-06-26T20:43:36","uid":"0002CC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
