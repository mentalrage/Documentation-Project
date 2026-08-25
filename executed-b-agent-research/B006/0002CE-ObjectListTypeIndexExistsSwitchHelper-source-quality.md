** TARGET-REPORT-UID:0002CE **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002CE ObjectListTypeIndexExistsSwitchHelper Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002CE] as a single exact `ObjectList` class-owned raw `thiscall` predicate helper with embedded compiler switch-table data.
- Source-facing name/signature recommendation: `bool ObjectList::ContainsTypedObject(ObjectPane *object)` as a descriptive/high-probability source name. `ContainsObject(ObjectPane *object)` is the best shorter alias if no collision exists in the final class declaration.
- Final disposition: no split and no merge. The body, three-byte alignment, and nine-entry jump table all belong to this target.
- Owner/emitter recommendation: keep `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`, routing through [UID:0000M4] `NexusTK/map/ObjectList.cpp`.
- Score recommendation: raise from `85/86` to `88/89`. The route/name questions are now investigated and closed with evidence, but no inbound static route and provisional object-type/tier names should keep the page below final-audit confidence.
- C++ recommendation: populate first-draft formal C++. The target meets the active code-entry gate and this is one exact source-authored helper body, not a broad mixed helper island. The no-inbound-route finding should be documented as a liveness/source-shape caveat, not left as a passive blocker.

## Target

- Target UID: `0002CE`
- Target path: `source-3/project-documentation/by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/0002CE-ObjectListTypeIndexExistsSwitchHelper-source-quality.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`
- Current issue: target had blank C++ and open questions for final predicate name plus whether IDA should model the function boundary.

## Evidence Checked

- Existing target doc [UID:0002CE], parent aggregate [UID:00023E], siblings [UID:0002CC] and [UID:0002CD], downstream helper-family docs [UID:0002BA], [UID:0002BB], [UID:00023F], and support pages [UID:00009Q], [UID:0000M4], [UID:0001VG], [UID:00009R], [UID:0001D5], [UID:0003XN].
- Exported function records:
  - `resources/exported_data/functions/0x00532450.json`
  - `resources/exported_data/functions/0x005322d0.json`
  - `resources/exported_data/functions/0x00535f90.json`
- Direct PE read-only scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for `0x00532450`:
  - Image base `0x00400000`
  - Target RVA `0x00132450`
  - Scanned `.text` direct `E8`/`E9` branch targets to `0x00532450`
  - Scanned static little-endian VA `50 24 53 00`
  - Scanned static little-endian RVA `50 24 13 00`
- Coverage row context in `by-memory/-coverage-report.md` around the existing ObjectList helper cluster rows. The row is stale at `80%` and must be supervisor-updated if the report is accepted.

## Heuristic / Inference Reanalysis And Validation

### Function Boundary And Table Ownership

Best conclusion: `0x00532450-0x00532530` is one exact source-authored `ObjectList` helper plus compiler-generated switch table.

Evidence:
- Ghidra/exported data models `0x00532450` as a 185-byte function, signature `bool __thiscall FUN_00532450(void *this, void *param_1)`, with zero callers and nine callees.
- Existing live IDA notes say IDA does not model `0x00532450` as a function, but the raw bytes show a normal prologue, `retn 4`, and a switch through `jpt_532466`.
- Direct byte read from the executable confirms:
  - Body: `0x00532450-0x00532509`, length `0xb9` / 185 bytes
  - Alignment: `0x00532509-0x0053250c`, bytes `0f 1f 00` (three-byte NOP)
  - Jump table: `0x0053250c-0x00532530`, nine dwords
  - Table entries: `0x0053248d`, `0x0053249d`, `0x005324ad`, `0x0053247d`, `0x005324bd`, `0x0053246d`, `0x005324cd`, `0x005324dd`, `0x005324ed`
- The successor [UID:0001D3] begins at `0x00532530`, so the table cannot belong to the successor accessor island.

Rejected alternatives:
- Split table into a separate data page: rejected. The table is a compiler switch table private to this helper.
- Extend the helper past `0x00532530`: rejected. `0x00532530` is the next ObjectList accessor island start.
- Treat `0x00532509-0x0053250c` as ignored padding outside the target: rejected for now because it is compiler alignment between the body and this helper's own jump table, already inside the current exact target range.

### Liveness / Caller Route

Best conclusion: no ordinary inbound static route to the helper start is currently proven. This is not just an IDA xref modeling miss.

Evidence:
- Target doc records IDA `xref_query` found no code xrefs directly to `0x00532450`.
- Exported Ghidra function record reports `num_callers: 0` and an empty caller list for `0x00532450`.
- Direct PE route scan found:
  - `direct_e8_e9_hit_count: 0`
  - `static_va_00532450: 0`
  - `static_rva_00132450: 0`
- Each type-specific callee record still shows outbound xrefs from this raw helper, for example `sub_535F90` has xrefs from both `sub_5322D0` and address `0x0053248e` inside the target. That confirms this body calls the helper family, but it does not prove anything calls this body.

Inference:
- The helper is best documented as a retained/source-shaped out-of-line `ObjectList` predicate with no proven current inbound static route. It may have had external linkage in the original object file, may be dead/retained source code, or may reflect a source helper whose active callers inline or duplicate the same switch. No evidence supports a data-driven/indirect dispatch table into `0x00532450`.
- Because this is one exact helper body with external-looking class-method shape, the no-route finding should cap confidence but should not force `RECONSTRUCTABLE:FALSE`.

Rejected alternatives:
- "Direct caller unresolved": superseded. The recheck resolves the issue negatively for ordinary static routes.
- "IDA missed the callers": rejected for direct branches/static pointers because the PE scan also found none.
- "Live through a vtable": rejected. No ObjectList vtable slot points here; ObjectList vtable data is a separate small destructor/default-slot block.

### Predicate Name And Signature

Best signature:

```cpp
bool __thiscall ObjectList::ContainsTypedObject(ObjectPane *object);
```

Evidence:
- Raw body uses `this` in `ecx` and one stack argument at `[ebp+8]`; every exit returns with `retn 4`.
- It reads `object + 0xf8`. [UID:00009R] and [UID:0001D5] name this base `ObjectPane` field `m_objectType` / `ObjectPaneType`.
- It never reads `object + 0xfc`, so this is not an object-id/serial lookup. [UID:0002CD] covers the object-id/serial lookup.
- Each case calls a type-specific encoded-key lookup helper and returns whether the result differs from `0xffffffff`.

Name ranking:
- `ContainsTypedObject`: accepted as the best descriptive name. It reflects pointer membership plus type-dispatched storage selection without implying a final original spelling.
- `ContainsObject`: accepted as a shorter final-source alias if no collision exists once the full class declaration is drafted.
- `HasObjectListKey` / `HasEncodedKeyForObject`: acceptable support aliases, but weaker as source-facing names because this helper exposes a boolean membership answer rather than returning the key.
- `HasTypeSpecificIndex`: partly accurate but rejected as final wording because the function has no index parameter and the callees return packed keys, row/index encodings, or direct indices depending on type.
- `ObjectListTypeIndexExistsSwitchHelper`: keep as historical/documentation label only; it is not source-style.
- `FindByObjectId` / `FindBySerial`: rejected. This helper never compares `+0xfc`; [UID:0002CD] owns that behavior.

### Object Type / Key Semantics

This helper dispatches on `ObjectPane::m_objectType` at `+0xf8`, not on an ObjectList field. It passes the object pointer to helper functions that search ObjectList storage and return an encoded key/index or `0xffffffff`.

| Case | Callee | Storage family from [UID:0002BB] | Meaning for this helper |
| --- | --- | --- | --- |
| `0` | `sub_535F90` | `+0x14 primaryCellList` | Return true if the object is in the primary flat/cell list. |
| `1` | `sub_535FD0` | `+0x18 secondaryCellList` | Return true if the object is in the secondary flat/cell list. |
| `2` | `sub_536010` | `+0x1c primaryRowLists` | Return true if row-table lookup finds the object. |
| `3` | `sub_535EC0` | `+0x24 tertiaryRowLists` | Return true if row-table lookup finds the object. |
| `4` | `sub_5360E0` | `+0x20 secondaryRowLists` | Return true if row-table lookup finds the object. |
| `5` | `sub_535DF0` | `+0x28 extendedRowLists` | Return true if extended-row lookup finds the object. |
| `6` | `sub_5361B0` | `+0x2c primaryGlobalList` | Return true if the object is in the primary global list. |
| `7` | `sub_5361F0` | `+0x30 secondaryGlobalList` | Return true if the object is in the secondary global list. |
| `8` | `sub_536230` | `+0x34 alternateGlobalList` | Return true if the object is in the alternate global list. |
| default | none | none | Return false. |

Known ObjectPane type names are only partly stabilized in [UID:00009R]: `0` item/ground item, `1` flying item/object, `3` living, and `5` static are high-probability; values `2`, `4`, `6`, `7`, and `8` should stay numeric or tier-named in this target until the object-pane type taxonomy is complete.

### Ownership And Source Placement

Best owner remains [UID:00009Q] `ObjectList`.

Evidence:
- The body uses `ecx` as an `ObjectList *` receiver and calls the same `ObjectList` type-specific encoded-key helper family as [UID:0002CC].
- Parent [UID:00023E] is the ObjectList categorize/lookup helper cluster.
- [UID:00009Q] and [UID:0000M4] both clear the owner/emitter gate and route to `NexusTK/map/ObjectList.cpp`.
- [UID:0001VG] documents all ObjectList storage fields used by the callees.

Rejected owner/source alternatives:
- [UID:0000M4] file-level direct owner: rejected as canonical owner because this is a `thiscall` class helper with `ObjectList *this`; the file remains the source root only.
- `MapPane` / `MapPaneSpatialIndex`: rejected. MapPane is a caller/consumer family for other ObjectList methods, and MapPaneSpatialIndex is a compatibility alias over ObjectList accessors. This target's receiver and callee family are ObjectList.
- `ObjectPane`: rejected. `ObjectPane` owns `m_objectType` and the object pointer layout, but this helper searches ObjectList storage.
- [UID:0002CC] value-returning dispatch: rejected as a parent/merge target. It is the companion value helper, not the owner of this separate boolean body.

## First-Draft C++ Recommendation

Populate the target formal C++ block with a source-style method body like this, after support docs accept the descriptive helper names. The body deliberately has no null check because the binary dereferences the object pointer before branching.

```cpp
bool ObjectList::ContainsTypedObject(ObjectPane *object)
{
    enum { kInvalidObjectListKey = 0xffffffffu };

    switch (object->m_objectType) {
    case 0:
        return FindPrimaryCellKey(object) != kInvalidObjectListKey;
    case 1:
        return FindSecondaryCellKey(object) != kInvalidObjectListKey;
    case 2:
        return FindPrimaryRowKey(object) != kInvalidObjectListKey;
    case 3:
        return FindTertiaryRowKey(object) != kInvalidObjectListKey;
    case 4:
        return FindSecondaryRowKey(object) != kInvalidObjectListKey;
    case 5:
        return FindExtendedRowKey(object) != kInvalidObjectListKey;
    case 6:
        return FindPrimaryGlobalKey(object) != kInvalidObjectListKey;
    case 7:
        return FindSecondaryGlobalKey(object) != kInvalidObjectListKey;
    case 8:
        return FindAlternateGlobalKey(object) != kInvalidObjectListKey;
    default:
        return false;
    }
}
```

Notes for implementation:
- The helper names above are descriptive placeholders for the `sub_535F90` through `sub_536230` family. They should be synchronized with [UID:0002BB] if accepted.
- Numeric cases should be replaced by `ObjectPaneType` enum constants only for values whose final labels are stable. It is safer to keep numeric cases in this first draft than to invent incorrect enum names for values `2`, `4`, `6`, `7`, and `8`.
- Do not rewrite this target as `return GetTypeSpecificKey(object) != kInvalidObjectListKey;`. That may be a plausible high-level source factoring, but it would not represent the observed duplicate switch body at `0x00532450`.

## Recommended Exact Doc Changes

### Primary Target [UID:0002CE]

- Metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:89`
  - Keep `CANONICAL_OWNER:00009Q`
  - Keep `RECONSTRUCTABLE:TRUE`
  - Keep `EMITTER_UIDS:00009Q`
- Status:
  - Replace "final C++ blank" wording with first-draft C++ readiness.
  - State that direct callers are no longer merely unresolved: IDA/Ghidra/direct-PE evidence finds no inbound direct static route to `0x00532450`.
  - State that no-route evidence caps confidence but does not change owner/emitter for this exact source-authored class helper.
- Address range:
  - Body `0x00532450-0x00532509`
  - Alignment `0x00532509-0x0053250c`, bytes `0f 1f 00`
  - Jump table `0x0053250c-0x00532530`, entries listed above
- Behavior:
  - Rename behavior description from "type/index exists" to "boolean membership wrapper over type-dispatched encoded-key lookup helpers."
  - Document that the parameter is an `ObjectPane *object`, that `object->m_objectType` is read at `+0xf8`, and that `+0xfc` is not used.
- Reconstruction notes:
  - Recommend source-facing name `ContainsTypedObject` with alias `ContainsObject`.
  - Include rejected alternatives from this report.
  - Add the first-draft C++ block above.
- Open questions:
  - Close the old predicate-name question with the accepted/rejected name ranking.
  - Close the IDA boundary question with "create an IDA function at `0x00532450`; the documentation evidence is strong enough even though current IDA has not modeled it."
  - Leave only a bounded caveat that exact original spelling and enum labels are not proven; this caps score but should not block C++.

### Parent / Support Docs

- [UID:00023E] `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`
  - Update the [UID:0002CE] row to use `ContainsTypedObject` / boolean membership helper language.
  - Add the direct PE no-route conclusion and table/body split.
  - Note first-draft C++ is now recommended on the exact child, not the aggregate.
- [UID:00009Q] `by-class/ObjectList.md`
  - Add `ContainsTypedObject(ObjectPane *object)` to the method-family notes as a raw/retained `thiscall` helper with no inbound static route found.
  - Keep class C++ blank unless a separate class declaration pass accepts method prototypes and `[[CHILDREN]]`.
- [UID:0000M4] `by-file/ObjectList.md`
  - Update the categorize/lookup helper cluster summary to mention the boolean membership helper and no-route conclusion.
  - Preserve `NexusTK/map/ObjectList.cpp` placement.
- [UID:0002CC] `by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md`
  - Keep it as the value-returning companion.
  - Recommended source-facing alias for future pass: `GetTypedObjectKey` / `GetObjectListKeyForObject`; do not let [UID:0002CE] collapse into a call to [UID:0002CC] unless a later source factoring pass explicitly decides to model inlining.
- [UID:0002BB] `by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md`
  - Add/confirm descriptive helper aliases used by the target draft: `FindPrimaryCellKey`, `FindSecondaryCellKey`, `FindPrimaryRowKey`, `FindTertiaryRowKey`, `FindSecondaryRowKey`, `FindExtendedRowKey`, `FindPrimaryGlobalKey`, `FindSecondaryGlobalKey`, `FindAlternateGlobalKey`.
  - Preserve the caveat that final object-type/tier semantic names are still provisional.
- [UID:00009R] `by-class/ObjectPane.md` and [UID:0001D5] `ObjectPane` core index
  - No required score/metadata change. Existing `m_objectType` / `ObjectPaneType` and `m_objectId` / `m_objectSerial` direction supports this target.
  - Optional note: [UID:0002CE] uses `+0xf8` only and does not use the `+0xfc` id/serial field.
- [UID:0001VG] `ObjectListLayout`
  - No metadata change required. Existing field names support the callee-family mapping; only final semantic layer names remain open.

## IDA Rename / Type / Comment Recommendations

- Create or fix function boundary:
  - Function start `0x00532450`
  - Function end `0x00532509`
  - Type: `bool __thiscall ObjectList::ContainsTypedObject(ObjectPane *object)`
- Mark `0x00532509-0x0053250c` as alignment/NOP bytes inside the helper/table span.
- Define `0x0053250c-0x00532530` as a nine-dword jump table and rename `jpt_532466` to `jpt_ObjectList_ContainsTypedObject`.
- Add function comment: "Boolean retained/source-shaped ObjectList membership helper. Dispatches on ObjectPane::m_objectType (+0xf8), calls typed encoded-key lookup helpers, returns key != 0xffffffff; no direct E8/E9 or VA/RVA inbound route found in PE scan."
- Suggested callee renames, medium confidence:
  - `sub_535F90` -> `ObjectList_FindPrimaryCellKey`
  - `sub_535FD0` -> `ObjectList_FindSecondaryCellKey`
  - `sub_536010` -> `ObjectList_FindPrimaryRowKey`
  - `sub_535EC0` -> `ObjectList_FindTertiaryRowKey`
  - `sub_5360E0` -> `ObjectList_FindSecondaryRowKey`
  - `sub_535DF0` -> `ObjectList_FindExtendedRowKey`
  - `sub_5361B0` -> `ObjectList_FindPrimaryGlobalKey`
  - `sub_5361F0` -> `ObjectList_FindSecondaryGlobalKey`
  - `sub_536230` -> `ObjectList_FindAlternateGlobalKey`

## Exact Coverage Row Text

Placement: replace the existing [UID:0002CE] row under the [UID:00023E] ObjectList categorize/lookup helper cluster in `by-memory/-coverage-report.md`. B006 must not edit that file directly.

```markdown
        - [UID:0002CE][0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper](by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md) 0x00532450-0x00532530 | raw thiscall helper + switch table | ObjectListContainsTypedObject : reconstructable : 88% : strong : B006 source-quality reanalysis resolves the IDA-missed ObjectList boolean membership helper as descriptive `bool ObjectList::ContainsTypedObject(ObjectPane *object)`: Ghidra models `FUN_00532450` as a 185-byte `__thiscall` bool helper with no callers, direct PE scan finds no `E8`/`E9` or VA/RVA pointer route to `0x00532450`, raw bytes confirm body `0x00532450-0x00532509`, three-byte NOP alignment `0x00532509-0x0053250c`, and nine-dword table `0x0053250c-0x00532530`, the switch reads `ObjectPane::m_objectType` at `+0xf8`, cases `0..8` call the same type-specific encoded-key lookup helpers as `0002CC`, returns `key != 0xffffffff`, default false, owner/emitter stay `ObjectList` through `NexusTK/map/ObjectList.cpp`, and first-draft C++ is ready while no-route liveness and final enum/tier names cap confidence.
```

## Validation Commands For Implementation Callback

Run after the supervisor accepts an implementation checklist and B006 updates the target/support docs:

> Executable block R001 was removed from this report and preserved verbatim in [0002CE-ObjectListTypeIndexExistsSwitchHelper-source-quality-removed.md](0002CE-ObjectListTypeIndexExistsSwitchHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Optional if sibling helper-name prose is updated:

> Executable block R002 was removed from this report and preserved verbatim in [0002CE-ObjectListTypeIndexExistsSwitchHelper-source-quality-removed.md](0002CE-ObjectListTypeIndexExistsSwitchHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Suggested post-validation check:

> Executable block R003 was removed from this report and preserved verbatim in [0002CE-ObjectListTypeIndexExistsSwitchHelper-source-quality-removed.md](0002CE-ObjectListTypeIndexExistsSwitchHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Validator Results

- Not run. This is a report-only assignment and no by-* docs were edited.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/0002CE-ObjectListTypeIndexExistsSwitchHelper-source-quality.md`
- Modified: none outside the B006 research report.
- by-* docs edited: none.
- `by-memory/-coverage-report.md` edited: no.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0002CE-ObjectListTypeIndexExistsSwitchHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"0002CE"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002CE-ObjectListTypeIndexExistsSwitchHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0002CE-ObjectListTypeIndexExistsSwitchHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002CE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
