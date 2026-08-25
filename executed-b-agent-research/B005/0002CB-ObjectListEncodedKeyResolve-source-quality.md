** TARGET-REPORT-UID:0002CB **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002CB ObjectListEncodedKeyResolve Source-Quality Report

Assignment: `B005-report-0002CB-object-list-encoded-key-resolve-source-quality-20260626`  
Agent: `Agent-B005`  
Primary target: [UID:0002CB] `by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md`  
Required report path: `tools/leaser/Agents/Agent-B005/research/0002CB-ObjectListEncodedKeyResolve-source-quality.md`

## Report-Only Status

This is a report-only B-agent pass. I did not lease files, did not edit by-* documentation, did not edit generated/project-level/manual coverage/tool-state files, and did not edit the IDA database.

IDA MCP was mandatory and was available. Live MCP context used for this report:

- MCP endpoint: `http://127.0.0.1:13337/mcp`
- Listener: `127.0.0.1:13337`, `TcpTestSucceeded=True`
- Process state: listener owner PID `13684`; `idalib-mcp.exe` PID `17084`; active IDA/Python worker PID `26892`
- IDB session: `80de0a67`
- Database: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- `server_health`: `status=ok`, `auto_analysis_ready=true`, `hexrays_ready=true`, module `NexusTK.exe`, imagebase `0x400000`

Queue/context note: `auto-generated/-ag-research-tracker.md` still lists [UID:0002CB] as `80/84`, and `by-memory/-coverage-report.md` still has an older `80`-completion row. Those generated files are stale context only and were not edited during this report-only assignment. The current target by-* page itself is already `86/90`.

## Recommendation Summary

- Keep [UID:0002CB] owned/emitted by [UID:00009Q] `ObjectList`, with source emission through [UID:0000M4] `NexusTK/map/ObjectList.cpp`.
- Raise [UID:0002CB] from `86/90` to `88/91`.
- Use the source-facing method name `ObjectPane *ObjectList::ResolveObjectListKey(unsigned int key)`.
- Treat the return as `ObjectPane *`, not `int`, `void *`, or `LivingObjectPane *`: [UID:0002C9] `ObjectList::AddObjectPane(ObjectPane *object)` stores one `ObjectPane *` payload per `List` element, and 0002CB returns `*static_cast<ObjectPane **>(list->GetElementAt(index))`.
- Use `DecodeObjectListKey` for the direct `sub_535CE0` dependency, but do not emit that decoder body inside [UID:0002CB]. The live decoder belongs to [UID:0002BA] `0x00535ce0`; this target only calls it.
- Populate [UID:0002CB]'s formal C++ block with the exact one-method body in this report. The body emits only the target function and introduces no standalone helper bodies, no local helper functions, no lambdas, no namespace helpers, and no target-owned factoring functions.
- Preserve the target-owned compiler table/alignment split: source emits a switch, while bytes `0x0053229e-0x005322d0` remain compiler-generated alignment/table/padding owned by this memory page.
- Close the current blockers at implementation level:
  - Method name: `ResolveObjectListKey`.
  - Parameter name/type: `unsigned int key`, a packed ObjectList key.
  - Decoder local names: `keyType`, `rowSelector`, and `index`.
  - Return type: `ObjectPane *`.
  - Category names: keep numeric switch cases `0..9` and structural ObjectList field names; do not invent final game-domain enum labels here.
  - Exposure: document this as a MapPane-visible ObjectList member/helper in the same helper surface as `GetObjectListKeyForObject` / `MoveKeyTo...`, not as a file-static helper or MapPane-owned routine.

## Evidence Checked

Primary and support docs:

- [UID:0002CB] `by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md`
- [UID:00023E] `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`
- [UID:0002CA] `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md`
- [UID:0002CC] `by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md`
- [UID:0002BA] `by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md`
- [UID:0002BB] `by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md`
- [UID:00023F] `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md`
- [UID:00037Q] `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`
- [UID:0001AT] `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md`
- [UID:00009Q] `by-class/ObjectList.md`
- [UID:0000M4] `by-file/ObjectList.md`
- [UID:0001VG] `by-type/by-struct/ObjectListLayout.md`
- [UID:000079] `by-class/List.md`

Prior accepted reports and context:

- `executed-b-agent-research/B010/00023F-ObjectListExtendedTypeLookupHelpers-source-quality.md`
- `executed-b-agent-research/B005/0002C9-ObjectListTypeDispatchInsertCategorize-source-quality.md`
- Existing by-* support sync from B005/B006/B010 ObjectList and MapPane traversal passes.

## Fresh IDA MCP Evidence

Live IDA MCP confirms the target boundary and neighboring functions:

- `lookup_funcs`:
  - `0x00532180`: `sub_532180`, size `0x11e`
  - `0x0053229e`: not a function
  - `0x005322d0`: `sub_5322D0`, size `0x71`
  - `0x00535ce0`: `sub_535CE0`, size `0xd8`
  - caller offsets resolve to `sub_506AE0`, `sub_506B30`, `sub_506B80`, `sub_506BD0`, `sub_506C20`, and `sub_506C70`.
- `analyze_function 0x00532180`:
  - Prototype reported as `int __thiscall(int this, unsigned int)`.
  - Direct callee list contains only `sub_535CE0`.
  - Caller list contains exactly `sub_506AE0`, `sub_506B30`, `sub_506B80`, `sub_506BD0`, `sub_506C20`, and `sub_506C70`.
  - The decompile is `sub_535CE0(a2, &type, &rowSelector, &index)` followed by `switch (type)`.
- `xrefs_to 0x00532180`: six code xrefs:
  - `0x00506b14` in `sub_506AE0`
  - `0x00506b64` in `sub_506B30`
  - `0x00506bb4` in `sub_506B80`
  - `0x00506c04` in `sub_506BD0`
  - `0x00506c57` in `sub_506C20`
  - `0x00506ca7` in `sub_506C70`
- `xrefs_to 0x00535ce0`: seven code xrefs:
  - `0x00532198` from this target
  - `0x0053318f`, `0x005333cf`, `0x0053361f`, `0x0053386f`, `0x00533aaf`, and `0x00533d1f` from the six ObjectList key-moving traversal helpers.
- `xrefs_to 0x005322a0`: one data xref from `0x005321aa`, the target switch jump.
- `get_bytes 0x0053229e size 50`:
  - `0x0053229e-0x005322a0`: `66 90` two-byte alignment.
  - `0x005322a0-0x005322c8`: ten dword switch entries:
    - case `0`: `0x005321e7`
    - case `1`: `0x005321fb`
    - case `2`: `0x0053220f`
    - case `3`: `0x005321cc`
    - case `4`: `0x0053222a`
    - case `5`: `0x005321b1`
    - case `6`: `0x00532245`
    - case `7`: `0x00532259`
    - case `8`: `0x0053226d`
    - case `9`: `0x00532281`
  - `0x005322c8-0x005322d0`: eight `0xcc` padding bytes before [UID:0002CC].
- Disassembly:
  - `0x00532198`: `call sub_535CE0`.
  - `0x0053219d`: sign-extends the decoded type byte.
  - `0x005321a1`: `cmp eax, 9`, proving the target handles only decoded categories `0..9`.
  - `0x005321a4`: categories above `9`, including decoder categories `10` and `11`, go to the default null return.
  - `0x005321aa`: jump through `jpt_5321AA[eax*4]`.
  - Row categories sign-extend the decoded row selector word before indexing row-list tables.
  - Every case calls `List` vtable slot `+0x10`, then dereferences the returned element slot and returns the stored pointer.

The paired key producer at [UID:0002CC] was also rechecked:

- `analyze_function 0x005322d0` shows `sub_5322D0` dispatching on `*(object + 0xf8)` for cases `0..8`, calling the typed key finders, and returning `0xffffffff` for unsupported object types.
- `xrefs_to 0x005322d0` are the same six MapPane wrappers at offsets `0x00506af0`, `0x00506b40`, `0x00506b90`, `0x00506be0`, `0x00506c30`, and `0x00506c80`.

The six MapPane wrappers were decompiled to confirm caller intent:

| Wrapper | Sequence | Source-facing role |
| --- | --- | --- |
| `0x00506ae0` | `sub_5322D0(current)`, `sub_533170(&key)`, `sub_532180(key)` | previous selectable object |
| `0x00506b30` | `sub_5322D0(current)`, `sub_5333B0(&key)`, `sub_532180(key)` | next selectable object |
| `0x00506b80` | `sub_5322D0(current)`, `sub_533600(&key)`, `sub_532180(key)` | previous item-target / alternate traversal |
| `0x00506bd0` | `sub_5322D0(current)`, `sub_533850(&key)`, `sub_532180(key)` | next item-target / alternate traversal |
| `0x00506c20` | `sub_5322D0(current)`, `sub_533A90(&key, targetFilter)`, `sub_532180(key)` | previous living-target filtered traversal |
| `0x00506c70` | `sub_5322D0(current)`, `sub_533D00(&key, targetFilter)`, `sub_532180(key)` | next living-target filtered traversal |

Each wrapper returns the original object pointer when the key-moving helper fails, and returns `sub_532180`'s result when it succeeds. This proves 0002CB is the encoded-key-to-object resolver used after ObjectList key traversal, not a boolean membership predicate or a key producer.

## Behavioral Resolution

[UID:0002CB] is the inverse lookup for ObjectList encoded keys. The resolved behavior is:

1. Decode the packed key through live ObjectList decoder `sub_535CE0` / `DecodeObjectListKey`.
2. Switch on decoded key type/category.
3. For direct-list categories, call `List::GetElementAt(index)` on the selected ObjectList `List *`.
4. For row-list categories, select `rowLists[rowSelector]`, then call `List::GetElementAt(index)`.
5. Dereference the returned `List` element address as an `ObjectPane **` and return the stored object pointer.
6. Return `NULL` for decoded categories outside `0..9`.

Case-to-tier mapping is fully resolved at structural level:

| Decoded key type | Storage tier | Notes |
| ---: | --- | --- |
| `0` | `m_primaryCellList` / `+0x14` | Direct list, plain low-word index. |
| `1` | `m_secondaryCellList` / `+0x18` | Direct list, high-nibble `1` key family. |
| `2` | `m_primaryRowLists[rowSelector]` / `+0x1c` | Row selector is sign-extended from the decoded word. |
| `3` | `m_tertiaryRowLists[rowSelector]` / `+0x24` | This is the row bucket used by the six key-moving traversal helpers. |
| `4` | `m_secondaryRowLists[rowSelector]` / `+0x20` | Row selector is sign-extended from the decoded word. |
| `5` | `m_extendedRowLists[rowSelector]` / `+0x28` | Extended row-table category. |
| `6` | `m_primaryGlobalList` / `+0x2c` | Direct global list. |
| `7` | `m_secondaryGlobalList` / `+0x30` | Direct global list. |
| `8` | `m_alternateGlobalList` / `+0x34` | Decoder category for the `0xc0000000` key family. |
| `9` | `m_tertiaryGlobalList` / `+0x38` | Direct global list. |
| `10` / `11` | not handled by this target | Decoder supports these categories for `+0x3c/+0x40`, but 0002CB's `cmp eax, 9; ja default` returns `NULL`. Do not add cases `10` or `11` to this target. |

The formal source should not introduce an enum for these categories during this implementation. Numeric cases are range-faithful and avoid pretending the final game-domain object-type names are known. The ObjectList structural field names are already accepted by [UID:0001VG] and [UID:0002C9].

## Naming Resolution

Recommended method:

```cpp
ObjectPane *ObjectList::ResolveObjectListKey(unsigned int key);
```

Why this name:

- The method takes the same packed ObjectList key produced by [UID:0002CC] / typed key finder helpers and mutated by the six `MoveKeyTo...` traversal helpers.
- It resolves that location token back into the stored `ObjectPane *`.
- `ObjectListKey` is the established support term in [UID:00023F] and [UID:0002BA].
- `Resolve` matches the observed inverse-lookup role without implying ownership transfer, allocation, insertion, removal, or boolean membership.

Rejected method names:

- `ObjectListEncodedKeyResolve`: documentation title, not a source method name.
- `FindObjectByKey`: acceptable as a human alias but less precise because the body does no search; it indexes the decoded storage location.
- `GetObjectPaneFromKey` / `GetObjectForKey`: acceptable fallback aliases, but weaker than `ResolveObjectListKey` because the surrounding helper family names the token as an ObjectList key.
- `GetTypedObjectKey`: wrong direction; that belongs to [UID:0002CC], which returns a key from an object.
- `ContainsTypedObject`: wrong return semantics; that belongs to [UID:0002CE], which returns a boolean.
- `MapPane::...`: rejected because MapPane owns only the wrapper traversal methods. The key decode, ObjectList field selection, and `List::GetElementAt` access all operate on the ObjectList receiver.

Recommended dependency name:

```cpp
DecodeObjectListKey(key, &keyType, &rowSelector, &index);
```

This is a call to live out-of-range decoder `0x00535ce0`. [UID:0002CB] must not define `DecodeObjectListKey`; [UID:0002BA] owns the decoder range and can carry the declaration/source split policy. For this target, the source-shaped call is enough and does not create a target-owned helper body.

## Formal C++ Recommendation

Replace [UID:0002CB]'s current blank `RECONSTRUCTION_CPP CODE` block with exactly this content:

```cpp
ObjectPane *ObjectList::ResolveObjectListKey(unsigned int key)
{
    unsigned char keyType;
    short rowSelector;
    unsigned int index;

    DecodeObjectListKey(key, &keyType, &rowSelector, &index);

    switch (keyType) {
    case 0:
        return *static_cast<ObjectPane **>(m_primaryCellList->GetElementAt(index));
    case 1:
        return *static_cast<ObjectPane **>(m_secondaryCellList->GetElementAt(index));
    case 2:
        return *static_cast<ObjectPane **>(
            m_primaryRowLists[rowSelector]->GetElementAt(index));
    case 3:
        return *static_cast<ObjectPane **>(
            m_tertiaryRowLists[rowSelector]->GetElementAt(index));
    case 4:
        return *static_cast<ObjectPane **>(
            m_secondaryRowLists[rowSelector]->GetElementAt(index));
    case 5:
        return *static_cast<ObjectPane **>(
            m_extendedRowLists[rowSelector]->GetElementAt(index));
    case 6:
        return *static_cast<ObjectPane **>(m_primaryGlobalList->GetElementAt(index));
    case 7:
        return *static_cast<ObjectPane **>(m_secondaryGlobalList->GetElementAt(index));
    case 8:
        return *static_cast<ObjectPane **>(m_alternateGlobalList->GetElementAt(index));
    case 9:
        return *static_cast<ObjectPane **>(m_tertiaryGlobalList->GetElementAt(index));
    default:
        return NULL;
    }
}
```

Range-safety proof:

- The formal block emits exactly one target method body: `ObjectList::ResolveObjectListKey`.
- It emits no `DecodeObjectListKey` body, no allocation helper, no row/table helper, no `HeaderFrom...` helper, no lambda, no template helper, no namespace helper, and no local helper function.
- The call to `DecodeObjectListKey` represents the actual direct out-of-range call at `0x00532198` to [UID:0002BA] `0x00535ce0`.
- The switch has exactly ten cases, matching `cmp eax, 9` and the ten dword entries at `0x005322a0-0x005322c8`.
- The body does not add null checks. The binary directly dereferences the selected `List *` and the `List::GetElementAt` result before returning the stored pointer.
- The row selector is modeled as `short` because the target uses signed word extension before row-table indexing.
- The index is modeled as `unsigned int` because the decoder stores a zero-extended low-word index into a dword local and the target pushes that dword to `List::GetElementAt`.

## Range, Table, And Padding Disposition

Keep the current range split with more precise text:

| Range | Disposition | Implementation text |
| --- | --- | --- |
| `0x00532180-0x0053229e` | Source-authored function body | `ObjectList::ResolveObjectListKey(unsigned int key)`. |
| `0x0053229e-0x005322a0` | compiler alignment | Two-byte `66 90` after the function body. |
| `0x005322a0-0x005322c8` | compiler switch table | Ten dword entries for cases `0..9`; data xref only from `0x005321aa`. |
| `0x005322c8-0x005322d0` | compiler/linker padding | Eight `0xcc` bytes before [UID:0002CC] starts. |

The embedded table/alignment remains owned by this by-memory page because it is generated from the target switch. It should not become standalone source and should not be moved to [UID:0002CC].

## Ownership And Source Placement

Keep owner/emitter as [UID:00009Q] `ObjectList` and source module [UID:0000M4] `ObjectList`.

Positive evidence:

- `ecx` is the ObjectList receiver.
- The body reads ObjectList fields `+0x14` through `+0x38`.
- The selected lists are exactly the fields initialized/destroyed by ObjectList lifecycle docs and mapped by [UID:0001VG].
- The direct dependency `DecodeObjectListKey` is documented as ObjectList-owned encoded-key support in [UID:0002BA] / [UID:00023F].
- The six direct callers are MapPane wrappers, but each wrapper already crosses into ObjectList for key production, key movement, and final key resolution.

Rejected owner/source placements:

- `MapPane`: direct caller/wrapper owner only. MapPane has no ownership of the key decode or ObjectList storage tiers.
- `List`: dependency for `GetElementAt`, not owner of ObjectList key policy.
- `ObjectPane` / `LivingObjectPane`: payload class only; the method does not inspect object fields.
- `ObjectListEncodedKeyAndRectHelpers` as emitter for this method: [UID:0002BA] owns the decoder dependency, not this resolver body.
- No-owner/raw-helper route: invalid because IDA models a real function with six direct callers and a clear ObjectList receiver.

Exposure disposition:

- Document as an ObjectList member/helper reachable by MapPane traversal wrappers.
- Do not mark it file-static.
- Do not force a final C++ access label from binary evidence. For implementation text, say it belongs with the ObjectList encoded-key/traversal helper surface used by MapPane wrappers.

## Support-Doc Implementation Plan

Apply these edits only after supervisor implementation callback and normal leasing:

1. [UID:0002CB] `by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md`
   - Update header score to `88/91`.
   - Populate the formal C++ block exactly as shown above.
   - Update item summary, status confidence, behavior, caller pattern, raw evidence, reconstruction notes, score rationale, open questions, and changes.
   - Replace "final helper/parameter/return/public-private names unresolved" with the resolved method/parameter/return/exposure disposition.
   - Correct table byte wording to `0x0053229e-0x005322a0` alignment, `0x005322a0-0x005322c8` ten-entry table, and `0x005322c8-0x005322d0` eight-byte padding.
2. [UID:00023E] `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`
   - Update the inventory row for `0x00532180-0x005322d0` to name `ObjectList::ResolveObjectListKey`.
   - Add a behavior/evidence note that 0002CB is the formal target-owned resolver paired with [UID:0002CC] and the six key-moving helpers.
   - Keep this aggregate's formal C++ blank.
   - Score can remain `85/88`; this support sync does not resolve every child in the aggregate.
3. [UID:0002CC] `by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md`
   - Add a relationship note: this page is the key-producing companion used before `ObjectList::MoveKeyTo...` and `ObjectList::ResolveObjectListKey`.
   - Keep its formal C++ blank unless separately assigned.
   - Score can remain `86/90`.
4. [UID:0002BA] `by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md`
   - Add a support note that [UID:0002CB]'s formal target body calls `DecodeObjectListKey` but does not emit the decoder body.
   - Keep combined-child formal C++ blank and retain the existing decoder split policy.
   - Score can remain `86/88`.
5. [UID:00023F] `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md`
   - Add `ObjectList::ResolveObjectListKey(unsigned int key)` to the source-facing helper list or prose around the six key-moving helpers.
   - State that the six helpers mutate keys and the 0002CB target resolves the resulting key back to `ObjectPane *`.
   - Keep aggregate formal C++ blank.
6. [UID:00037Q] `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`
   - Extend the wrapper relationship table so the ObjectList callee role includes the final `ResolveObjectListKey` call after successful `MoveKeyTo...`.
   - Keep MapPane as wrapper owner and ObjectList as key/storage owner.
   - Score can remain `85/88`.
7. [UID:00009Q] `by-class/ObjectList.md`
   - Add `ResolveObjectListKey` to the accepted descriptive helper/method surface alongside `MoveKeyToPreviousSelectableObject`, `MoveKeyToNextSelectableObject`, and related key helpers.
   - Note that exact original access label is not encoded in the binary, but the helper is MapPane-visible and not file-static.
   - Score can remain `85/88`.
8. [UID:0000M4] `by-file/ObjectList.md`
   - Add a one-line ObjectList.cpp ownership note for `ResolveObjectListKey` as the encoded-key-to-object resolver.
   - Score can remain `85/88`.
9. [UID:0001VG] `by-type/by-struct/ObjectListLayout.md`
   - Add a cross-check note that 0002CB uses fields `+0x14` through `+0x38` for decoded key types `0..9` and intentionally does not resolve decoder categories `10`/`11` to `+0x3c/+0x40`.
   - Keep score `85/90`.

No generated/project-level/manual coverage files should be edited by the implementation agent. Let the validator/generated refresh workflow handle generated outputs if the supervisor explicitly requests it; otherwise report generated-refresh state as not edited.

## Validator Plan

After implementation callback and file leases, run scoped validators for every changed by-* file. Expected commands, adjusted only for the final changed-file set:

> Executable block R001 was removed from this report and preserved verbatim in [0002CB-ObjectListEncodedKeyResolve-source-quality-removed.md](0002CB-ObjectListEncodedKeyResolve-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation callback narrows support edits, run validators only for the changed by-* files plus the target.

## Score And Metadata Rationale

Recommended target metadata:

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | `86` | `88` | Formal C++ is now ready, method/parameter/return names are resolved, table bytes are precisely split, and support-doc changes are file-specific. |
| `CONFIDENCE` | `90` | `91` | Live MCP revalidated boundary, callers, callee, data xref, bytes, paired key producer, and List slot semantics. Confidence stays below final-source levels because original symbol spelling and access label are not symbol-proven. |
| `CANONICAL_OWNER` | `00009Q` | `00009Q` | ObjectList receiver and fields. |
| `EMITTER_UIDS` | `00009Q` | `00009Q` | Class-owned method emitted through ObjectList.cpp route. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | One source-authored method body plus bounded compiler table/alignment. |

The target is implementation-ready. The remaining non-symbol-proof facts do not block first-draft formal C++ because the body uses descriptive source names already accepted by surrounding ObjectList docs and stays exact to the modeled target range.

## Implementation Tracking Checklist

- [x] Lease only immediate edit files before modifying by-* docs for this callback, and release leases immediately after the edit/validator batch.
  - Proof: B005 used short edit/validator leases only. The first non-conflicting batch covered [UID:00023E] `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`, [UID:00037Q] `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`, and [UID:0001VG] `by-type/by-struct/ObjectListLayout.md`; all three were released successfully at `2026-06-27T00:34:55.8579308Z`. After B009/B014 leases expired, B005 leased the remaining six files, validated them, and released `by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md`, `by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md`, `by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md`, `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md`, `by-class/ObjectList.md`, and `by-file/ObjectList.md` successfully. When B014 later took and released overlapping ObjectList support leases, B005 re-read those current files, confirmed the B005 facts were preserved at same-or-greater detail, took a short validator-only lease for [UID:00023F], [UID:00009Q], and [UID:0000M4], reran scoped validators, and released that lease successfully.
- [x] Update [UID:0002CB] score to `88/91`, item summary, behavior, evidence, reconstruction notes, score rationale, changes, and open-question disposition.
  - Proof: [UID:0002CB] now has `COMPLETION:88`, `CONFIDENCE:91`, `ObjectList::ResolveObjectListKey(unsigned int key)` item summary/prose, caller and field-map evidence, score rationale, and closed method/parameter/return/exposure questions.
- [x] Insert the exact `ObjectPane *ObjectList::ResolveObjectListKey(unsigned int key)` formal C++ block into [UID:0002CB], with no additional helper body.
  - Proof: [UID:0002CB]'s formal `RECONSTRUCTION_CPP CODE` block emits exactly the one `ObjectPane *ObjectList::ResolveObjectListKey(unsigned int key)` body. It calls out-of-range `DecodeObjectListKey` by name and does not emit a decoder, lambda, local helper, namespace helper, table helper, or any other standalone helper body.
- [x] Record [UID:0002CB]'s precise table/alignment split: `66 90`, ten dword table entries, and eight `0xcc` bytes.
  - Proof: [UID:0002CB] records body `0x00532180-0x0053229e`, alignment `0x0053229e-0x005322a0` (`66 90`), switch table `0x005322a0-0x005322c8` with ten dword entries, and padding `0x005322c8-0x005322d0` with eight `0xcc` bytes.
- [x] Update [UID:00023E] inventory/prose to name `ObjectList::ResolveObjectListKey` while keeping aggregate C++ blank.
  - Proof: [UID:00023E] names `ObjectList::ResolveObjectListKey(unsigned int key)` in the child inventory and behavior/prose, keeps the aggregate formal C++ blank, and preserves later B006/B009 `GetTypedObjectKey` and `FindByObjectId` detail.
- [x] Update [UID:0002CC] to document the key-producer relationship to `ResolveObjectListKey`; leave its formal block blank.
  - Proof: [UID:0002CC] documents the `GetTypedObjectKey -> MoveKeyTo... -> ResolveObjectListKey` relationship. The original B005 no-emission instruction is superseded by B006's separate accepted callback, which now legitimately emits `ObjectList::GetTypedObjectKey(ObjectPane *object)` on [UID:0002CC]; B005 preserved that same-or-greater B006 detail and corrected the stale sentence that still described [UID:0002CC] as non-emitting.
- [x] Update [UID:0002BA] to document that [UID:0002CB] calls `DecodeObjectListKey` without emitting the decoder body.
  - Proof: [UID:0002BA] states that [UID:0002CB] calls this page's live `DecodeObjectListKey` decoder at `0x00535ce0` from `0x00532198`, while [UID:0002CB] emits no decoder body or wrapper/helper body. B014's stronger raw-helper no-code proof and `88/90` metadata were preserved.
- [x] Update [UID:00023F] to include `ResolveObjectListKey` in the ObjectList key traversal/lookup helper surface.
  - Proof: [UID:00023F] includes the ObjectList traversal sequence with `GetTypedObjectKey`, the six `MoveKeyTo...` helpers, and [UID:0002CB] `ObjectList::ResolveObjectListKey` as the final packed-key-to-object resolver; aggregate C++ remains blank.
- [x] Update [UID:00037Q] MapPane wrapper relationship table to include the final `ResolveObjectListKey` call after successful key movement.
  - Proof: [UID:00037Q] records all six MapPane wrappers as `GetTypedObjectKey -> MoveKeyTo... -> ResolveObjectListKey`, and states failed key movement returns the original object pointer while successful movement calls `ObjectList::ResolveObjectListKey`.
- [x] Update [UID:00009Q] and [UID:0000M4] with the source-facing helper name and ObjectList.cpp ownership note.
  - Proof: [UID:00009Q] includes `ObjectList::ResolveObjectListKey(unsigned int key)` in the ObjectList helper/method surface and documents it as MapPane-visible but not symbol-proven file-static/access-labeled. [UID:0000M4] routes [UID:0002CB] through `NexusTK/map/ObjectList.cpp` and states the exact child, not the file page, carries the method body. B006/B009 same-or-greater companion details were preserved.
- [x] Update [UID:0001VG] with the resolver case-to-field cross-check and the explicit no-cases-10/11 note.
  - Proof: [UID:0001VG] records the [UID:0002CB] field map for decoded key types `0..9` through ObjectList fields `+0x14..+0x38` and explicitly notes that the resolver does not map decoder categories `10`/`11` to `+0x3c/+0x40`.
- [x] Run scoped validators for every changed by-* file and record command lines, exit status, `ok` counts, and generated-refresh state.
  - Proof: all changed by-* files were validated from `source-3/project-documentation` with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`.
  - `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`: command `000000003326`, timestamp `2026-06-26T20:34:17-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
  - `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`: command `000000003327`, timestamp `2026-06-26T20:34:29-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
  - `by-type/by-struct/ObjectListLayout.md`: command `000000003328`, timestamp `2026-06-26T20:34:41-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
  - `by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md`: command `000000003428`, timestamp `2026-06-26T20:41:56-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
  - `by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md`: command `000000003429`, timestamp `2026-06-26T20:42:08-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
  - `by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md`: command `000000003430`, timestamp `2026-06-26T20:42:21-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
  - `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md`: command `000000003431`, timestamp `2026-06-26T20:42:32-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`; retained existing missing-ref diagnostic for `by-memory/0x00514920-0x00514e5b.MapRefreshDimmer.md`.
  - `by-class/ObjectList.md`: command `000000003432`, timestamp `2026-06-26T20:42:44-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`; retained existing missing-ref diagnostic for `by-memory/0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper.md`.
  - `by-file/ObjectList.md`: command `000000003433`, timestamp `2026-06-26T20:42:56-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`; retained existing missing-ref/missing-UID diagnostics for `00023D` and `0003IO`.
  - Post-B014 revalidation for `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md`: command `000000003465`, timestamp `2026-06-26T20:51:10-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`; same existing missing-ref diagnostic for `by-memory/0x00514920-0x00514e5b.MapRefreshDimmer.md`.
  - Post-B014 revalidation for `by-class/ObjectList.md`: command `000000003467`, timestamp `2026-06-26T20:51:18-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`; same existing missing-ref diagnostic for `by-memory/0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper.md`.
  - Post-B014 revalidation for `by-file/ObjectList.md`: command `000000003469`, timestamp `2026-06-26T20:51:32-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`; same existing missing-ref/missing-UID diagnostics for `00023D` and `0003IO`.
- [x] Do not edit generated/project-level/manual coverage/tool-state/IDA DB files during implementation.
  - Proof: B005 manually edited only assigned by-* docs and this report checklist. No generated reports, project-level files, manual `-coverage-report.md` files, validator/leaser state files, or IDA DB were manually edited. The observed non-manual side effects came from required tools: leaser commands updated the shared lease report, and scoped validator commands reported projected-stats updates, deferred generated-refresh records, and validator-owned registry/reference/header side effects where applicable.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002CB-ObjectListEncodedKeyResolve-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002CB-ObjectListEncodedKeyResolve-source-quality.md","timestamp":"2026-06-26T22:10:32","uid":"0002CB"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002CB-ObjectListEncodedKeyResolve-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0002CB-ObjectListEncodedKeyResolve-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002CB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
