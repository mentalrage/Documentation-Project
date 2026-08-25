** TARGET-REPORT-UID:00037Q **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID00037Q MapPaneObjectLookupHelpers Source-Quality Report

Report-only research for [UID:00037Q] `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`.

## Target

- UID: `00037Q`
- Target: `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`
- Current title: `0x00506970-0x00506cdd MapPane Object Lookup Helpers`
- Assignment source: `tools/leaser/Agents/Agent-B014/goal.md`
- Expected report path: `tools/leaser/Agents/Agent-B014/research/00037Q-MapPaneObjectLookupHelpers-source-quality.md`

## Current Target State

Current metadata in the target page:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `85` |
| `CONFIDENCE` | `88` |
| `CANONICAL_OWNER` | `00007Q` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `00007Q` |
| Formal C++ | blank |

The page already records the right high-level facts: it is MapPane-owned behavior, it uses `MapPane + 0x424` / `m_objectList`, it contains object-id lookup plus object-coordinate/update plus six key traversal wrappers plus a terminal ObjectList removal wrapper, and it should not receive one monolithic C++ body. The remaining source-quality blocker is structural: the current target is still one reconstructable aggregate over nine separate IDA functions and multiple internal padding spans.

## Evidence Checked

Project/workflow sources read:

- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `.codex/skills/ntk-b-agent-workflow/references/score-blocker-audit-standard.md`
- `source-3/project-documentation/by-structure.md`, including the IDA MCP Output Discipline and reconstructable/owner/emitter metadata rules.
- `tools/leaser/Agents/Agent-B014/goal.md`

Primary and support docs read:

- `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`
- `by-class/MapPane.md`
- `by-file/MapPane.md`
- `by-class/ObjectList.md`
- `by-file/ObjectList.md`
- `by-memory/-ignored.md` for padding coverage check.

Prior reports searched with `rg` / `Select-String` for `00037Q`, `MapPaneObjectLookupHelpers`, `0x00506970`, `00506970`, `0x00506cdd`, `sub_506970`, `sub_506980`, `sub_506AE0`, `sub_506B30`, `sub_506B80`, `sub_506BD0`, `sub_506C20`, `sub_506C70`, `sub_506CC0`, `ObjectList`, `GetTypedObjectKey`, `ResolveObjectListKey`, `FindByObjectId`, and `531C10`.

Relevant prior executed reports:

- `executed-b-agent-research/B004/0000L3-MapPane-empty-emitter-family-source-quality.md`: says [UID:00037Q] must split exact children before aggregate retirement; gives the nine-function table and padding list.
- `executed-b-agent-research/B001/B001-MEMTOOL-00506970-MapPaneInputPacketRenderCore.md`: broad parent evidence; exact MapPane source-bearing children include `00037Q`; `0x00506970` has 64 xrefs; parent aggregate is non-emitting.
- `executed-b-agent-research/B010/00023F-ObjectListExtendedTypeLookupHelpers-source-quality.md`: names six ObjectList `MoveKeyTo...` traversal callees and proves MapPane wrapper ownership versus ObjectList storage/key ownership.
- `executed-b-agent-research/B006/0002CC-ObjectListTypeSpecificIndexDispatch-source-quality.md`: accepts `ObjectList::GetTypedObjectKey(ObjectPane *object)` and its use as the seed call before `MoveKeyTo...`.
- `executed-b-agent-research/B005/0002CB-ObjectListEncodedKeyResolve-source-quality.md`: accepts `ObjectList::ResolveObjectListKey(unsigned int key)` and proves successful MapPane key movement resolves the key while failed movement returns the original object pointer.
- `executed-b-agent-research/B009/0002CD-ObjectListFindByObjectId-source-quality.md`: accepts `ObjectList::FindByObjectId(int objectId)` and names `0x00506970` as the MapPane wrapper around it.
- `executed-b-agent-research/B008/0000M4-ObjectList-empty-emitter-family-source-quality.md`: accepts `ObjectList::RemoveObjectPane(ObjectPane *object)` at `0x00531c10`.
- `executed-b-agent-research/B013/0001L4-ItemWhoInputPane-source-quality.md` and `executed-b-agent-research/B005/0001LD-0001LE-SelectObjectWithKeyboardPaneInputHandlers-source-quality.md`: support item/keyboard caller context for the selectable and alternate item-target wrappers.

Fresh IDA MCP evidence, all read-only and bounded:

| MCP id | Tool | Result used |
| --- | --- | --- |
| `1` | `initialize` | Server `ida-pro-mcp`, protocol `2025-06-18`. |
| `2` | `tools/list` | Schema-current tool list checked. |
| `3` | `idb_list` | Active session `supervisor_resume_20260629`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker backend, active. |
| `5` | `server_health` | `status: ok`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis/Hex-Rays/string cache ready. |
| `6` | `lookup_funcs` | Confirms starts and sizes: `0x506970` `0xf`, `0x506980` `0x154`, `0x506ae0` `0x4a`, `0x506b30` `0x4a`, `0x506b80` `0x4a`, `0x506bd0` `0x4a`, `0x506c20` `0x4d`, `0x506c70` `0x4d`, `0x506cc0` `0x1d`, successor `0x506ce0` `0x35`. |
| `10-18` | `analyze_function` | Per-function pseudocode, callees, and unique caller samples for all nine target functions. |
| `40-49` | `disasm` | Paged disassembly: full small functions and two pages for `0x506980`; wrapper pattern and `+0x424` ObjectList member loads verified. |
| `60-62` | `xrefs_to` | Bounded xrefs for target starts and ObjectList callees; confirms raw xref counts and direct wrapper-to-callee mapping. |
| `70-74` | `analyze_function` | Representative caller bodies: item/keyboard paths (`0x5aedd0`, `0x5af710`, `0x5b0010`) and living-target/SpellWho paths (`0x5ad500`, `0x5ae410`). |

## Positive Evidence Summary

The range is a nine-function family plus padding, not one source method:

| Range | IDA function | Size | Direct role |
| --- | --- | ---: | --- |
| `0x00506970-0x0050697f` | `sub_506970` | `0x0f` | `MapPane::FindObjectPaneById(int objectId)` wrapper over `ObjectList::FindByObjectId`. |
| `0x00506980-0x00506ad4` | `sub_506980` | `0x154` | MapPane object screen-position/bounds update helper using tile dimensions, tile origin, movement substep scale, and object virtual bounds slots. |
| `0x00506ae0-0x00506b2a` | `sub_506AE0` | `0x4a` | previous selectable-object wrapper. |
| `0x00506b30-0x00506b7a` | `sub_506B30` | `0x4a` | next selectable-object wrapper. |
| `0x00506b80-0x00506bca` | `sub_506B80` | `0x4a` | previous item-target / alternate selectable wrapper. |
| `0x00506bd0-0x00506c1a` | `sub_506BD0` | `0x4a` | next item-target / alternate selectable wrapper. |
| `0x00506c20-0x00506c6d` | `sub_506C20` | `0x4d` | previous living-target / SpellWho wrapper with `targetFilter`. |
| `0x00506c70-0x00506cbd` | `sub_506C70` | `0x4d` | next living-target / SpellWho wrapper with `targetFilter`. |
| `0x00506cc0-0x00506cdd` | `sub_506CC0` | `0x1d` | null-checked `MapPane::RemoveObjectPane(ObjectPane *object)` wrapper over `ObjectList::RemoveObjectPane`. |

Direct binary facts:

- `0x506970` disassembly is five instructions: load `ecx = [ecx+424h]`, then tail-jump to `sub_532370`. Prior accepted [UID:0002CD] names that callee `ObjectList::FindByObjectId(int objectId)`.
- `0x506980` is 117 instructions / 340 bytes. It calls object virtual slot `+0x50`, `sub_5374D0`, `sub_505080`, `sub_4B78F0`, object virtual slots `+0x20/+0x2c`, and the security-cookie check. It reads `MapPane +0x3fc/+0x400`, `word_66DA9C`, `word_66DAA0`, `byte_66DA96`, and object fields `+0xf8`, `+0x1c4`, `+0x1c5`, `+0x1c6`, `+0x1e8`. That is source MapPane object-placement/update logic, not ObjectList storage logic.
- Each of the first four traversal wrappers loads `MapPane +0x424`, calls `ObjectList::GetTypedObjectKey`, calls one `ObjectList::MoveKeyTo...` helper with `&key`, then calls `ObjectList::ResolveObjectListKey` on success or returns the original object pointer on failure.
- The living-target pair pushes the extra argument before calling `sub_533A90` / `sub_533D00`, and returns with `retn 8`, confirming a two-argument wrapper surface after `this`.
- `0x506cc0` tests the object argument for null, loads `MapPane +0x424`, and tail-jumps to `sub_531C10`; accepted ObjectList evidence names that callee `ObjectList::RemoveObjectPane(ObjectPane *object)`.

Fresh xref facts:

- `xrefs_to` id `60` reports `0x00506970` has `64` code xrefs and `0x00506980` has `44` code xrefs, matching the existing target's high-fanout description.
- `xrefs_to` ids `60-61` report raw target-wrapper xref counts: `0x506ae0` six, `0x506b30` six, `0x506b80` two, `0x506bd0` two, `0x506c20` three, `0x506c70` five, `0x506cc0` eleven.
- `xrefs_to` id `62` confirms the six wrappers are the complete direct caller set for `ObjectList::GetTypedObjectKey` at `0x005322d0` and `ObjectList::ResolveObjectListKey` at `0x00532180`.
- `xrefs_to` id `62` confirms each `MoveKeyTo...` helper has the expected single MapPane wrapper call: `0x533170 <- 0x506b02`, `0x5333b0 <- 0x506b52`, `0x533600 <- 0x506ba2`, `0x533850 <- 0x506bf2`, `0x533a90 <- 0x506c45`, `0x533d00 <- 0x506c95`.

Caller-context facts:

- `analyze_function` id `70` for `0x5aedd0` calls `sub_506970`, then uses `sub_506b80/sub_506bd0` when input modifier bit `0x04` is set and `sub_506ae0/sub_506b30` otherwise. This supports the item-target/alternate naming for the middle pair and selectable naming for the first pair.
- `analyze_function` ids `71-72` for `0x5af710` / `0x5b0010` call the first selectable pair only, supporting the accepted `FindPreviousSelectableObject` / `FindNextSelectableObject` names.
- `analyze_function` id `73` for `0x5ad500` calls the living-target pair with stored `MapPane +0x110` style state and passes either the saved filter or literal `1`.
- `analyze_function` id `74` for `0x5ae410` derives filter values `-1`, `0`, or `1` from UI/config bytes and passes them into `sub_506c20/sub_506c70`; the exact final field name remains open, so `targetFilter` is the best source-facing parameter name.

## Negative Evidence Summary

- There is no evidence for one authored C++ function spanning `0x00506970-0x00506cdd`. IDA models nine function starts and `0x00506ce0` as the next separate child.
- There is no evidence that ObjectList owns the MapPane wrappers. ObjectList owns the storage/key/remove callee bodies; MapPane owns the wrapper decisions and the global active-map caller surface.
- There is no evidence that the middle item-target pair should be collapsed into the first selectable pair. The `0x5aedd0` caller chooses the alternate pair under modifier bit `0x04`.
- There is no evidence that `targetFilter` should be renamed to a final game-domain field. Current evidence only proves compare/pass-through filter behavior and caller-derived values.
- There is no evidence for final formal C++ for `0x506980` at source quality yet. Its behavior is bounded, but the exact ObjectPane virtual method names and object motion/dirty-bounds field names are still descriptive.
- The internal padding spans are not fully represented in `by-memory/-ignored.md`. Current `-ignored.md` contains `0x00506cdd-0x00506ce0` but not the eight earlier internal gaps.

## Heuristic / Inference Reanalysis And Validation

The prior "MapPaneObjectLookupHelpers" aggregate is a useful research label but not a valid source emission unit. The fresh MCP lookup and disassembly validate B004's earlier split plan exactly. This closes the source-quality blocker as an implementation-ready split/retirement action:

1. Create exact child pages for the nine functions.
2. Move source-facing reconstruction eligibility to child pages only.
3. Convert [UID:00037Q] itself to a non-emitting split/container so it does not duplicate the child bodies.
4. Add/confirm ignored coverage for the inter-function padding bytes.

The only remaining inference is naming, not ownership or range. Accepted reports already resolve the ObjectList callees: `FindByObjectId`, `GetTypedObjectKey`, `ResolveObjectListKey`, `MoveKeyToPreviousSelectableObject`, `MoveKeyToNextSelectableObject`, `MoveKeyToPreviousItemTargetObject`, `MoveKeyToNextItemTargetObject`, `MoveKeyToPreviousLivingTarget`, `MoveKeyToNextLivingTarget`, and `RemoveObjectPane`. MapPane wrapper names should mirror those roles while keeping caveats for original spelling.

## Ranked Ownership Analysis

| Rank | Owner candidate | Decision | Reason |
| ---: | --- | --- | --- |
| 1 | [UID:00007Q] `MapPane` for exact child functions | Accept | Every target function uses MapPane receiver state or wrapper policy. The wrappers load `MapPane +0x424`; callers use `g_activeMapPane` / `dword_67A764` and map UI state; `0x506980` reads MapPane tile origin and coordinate globals. |
| 2 | [UID:0000L3] `NexusTK/map/MapPane.cpp` for output route | Accept | The functions are MapPane method/helper surface. Existing `by-file/MapPane.md` already routes UID00037Q through MapPane and says ObjectList is only a dependency/callee owner. |
| 3 | [UID:00009Q] `ObjectList` for the wrapper functions | Reject for wrappers, accept for callees | ObjectList owns `0x532370`, `0x5322d0`, `0x532180`, `0x533170`, `0x5333b0`, `0x533600`, `0x533850`, `0x533a90`, `0x533d00`, and `0x531c10`, but not the MapPane wrappers. |
| 4 | [UID:0001AT] broad `MapPaneInputPacketRenderCore` parent | Reject as source owner | That parent is a non-emitting mixed-owner audit container. Exact source children carry ownership. |
| 5 | ProfileStorage / SaveUserSettings island | Reject | No target function is in the ProfileStorage island; this range ends before later packet/render spans and has MapPane/ObjectList behavior only. |

## Source Placement

The exact child functions should emit through [UID:0000L3] `NexusTK/map/MapPane.cpp` when a child body is ready. `ObjectList.cpp` is the callee/source owner for the storage and key traversal methods, not the placement for these wrappers.

Recommended child names:

| Range | Recommended source-facing name | C++ readiness |
| --- | --- | --- |
| `0x00506970-0x0050697f` | `MapPane::FindObjectPaneById(int objectId)` | Ready as a tiny wrapper if a child page is created. |
| `0x00506980-0x00506ad4` | `MapPane::UpdateObjectPaneScreenBounds(ObjectPane *object)` / `UpdateObjectPanePlacement` | Defer formal C++; behavior and dependencies can be documented now. |
| `0x00506ae0-0x00506b2a` | `MapPane::FindPreviousSelectableObject(ObjectPane *current)` | Ready as a thin wrapper if a child page is created. |
| `0x00506b30-0x00506b7a` | `MapPane::FindNextSelectableObject(ObjectPane *current)` | Ready as a thin wrapper if a child page is created. |
| `0x00506b80-0x00506bca` | `MapPane::FindPreviousItemTargetObject(ObjectPane *current)` | Ready as a thin wrapper with alternate-name caveat. |
| `0x00506bd0-0x00506c1a` | `MapPane::FindNextItemTargetObject(ObjectPane *current)` | Ready as a thin wrapper with alternate-name caveat. |
| `0x00506c20-0x00506c6d` | `MapPane::FindPreviousLivingTarget(ObjectPane *current, int targetFilter)` | Ready as a thin wrapper; keep `targetFilter` descriptive. |
| `0x00506c70-0x00506cbd` | `MapPane::FindNextLivingTarget(ObjectPane *current, int targetFilter)` | Ready as a thin wrapper; keep `targetFilter` descriptive. |
| `0x00506cc0-0x00506cdd` | `MapPane::RemoveObjectPane(ObjectPane *object)` / `RemoveObjectPaneIfPresent` wrapper | Ready as a tiny null-check wrapper if a child page is created; final source spelling should avoid implying ObjectList ownership. |

## Score And Metadata Recommendation

For existing [UID:00037Q], after exact child pages are created:

- Set `COMPLETION:88`.
- Set `CONFIDENCE:90`.
- Set `CANONICAL_OWNER:NONE`.
- Set `RECONSTRUCTABLE:FALSE`.
- Clear `EMITTER_UIDS`.
- Keep the formal C++ block blank.
- Add an explicit no-code/split-container note: exact MapPane source is owned by child pages under this range; this aggregate must not emit one C++ body.

Reason: evidence is strong enough to improve confidence, but the target should no longer be a reconstructable source emitter because it is a multi-function split index. `88/90` matches the reviewed-container pattern used by the broad parent and preserves a confidence cap for final names/fields.

Recommended child metadata when created:

- Thin lookup/traversal/remove wrapper children: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`.
- `0x00506980-0x00506ad4` coordinate/update child: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, formal C++ blank until object virtual/field names are accepted.

No class/file score change is required. `by-class/MapPane.md` and `by-file/MapPane.md` already support the MapPane route; they only need support-detail synchronization if this split is accepted.

## First-Draft C++ Recommendation

Do not add a formal C++ block to [UID:00037Q]. Parent aggregate no-code proof:

- It spans nine distinct IDA functions.
- It contains internal padding between functions.
- A single formal C++ block would either concatenate unrelated methods or duplicate future child-page bodies.
- Existing by-structure rules require source output on exact reconstructable children when the parent is only a split/index container.

Thin child pages may carry first-draft bodies after creation. Use only child-local bodies, for example:

```cpp
ObjectPane *MapPane::FindObjectPaneById(int objectId)
{
    return m_objectList->FindByObjectId(objectId);
}
```

and the traversal wrapper pattern:

```cpp
ObjectPane *MapPane::FindPreviousSelectableObject(ObjectPane *current)
{
    unsigned int key = m_objectList->GetTypedObjectKey(current);
    if (m_objectList->MoveKeyToPreviousSelectableObject(&key))
        return m_objectList->ResolveObjectListKey(key);
    return current;
}
```

The same pattern applies to next/selectable, item-target previous/next, and living-target previous/next with the corresponding ObjectList callee. Do not emit these bodies in the current aggregate.

For `0x506980`, defer formal C++ until the ObjectPane virtual calls and fields used for data/bounds placement are named at source quality. For `0x506cc0`, the child body can be a null-checked MapPane wrapper over `ObjectList::RemoveObjectPane`, but final naming should be applied on the child page.

Compiler/decompiler artifact note for implementation: the apparent tail jumps, security-cookie variable, stack temporaries, and raw `this[265]`/`[ecx+424h]` indexing are compiler/decompiler artifacts. Authored C++ should use normal `m_objectList` member calls and should not spell tail jumps, stack-cookie checks, or artificial local temporaries as source.

## Recommended Target Doc Changes

If accepted for implementation:

1. Create exact child pages for all nine functions listed in this report.
2. Convert [UID:00037Q] to a non-emitting split/container with `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank `EMITTER_UIDS`.
3. Replace the target's reconstructable-emitter language with an aggregate/split note that points to the exact child pages.
4. Preserve the full function inventory and direct MCP evidence from this report: session/health, lookup result, `analyze_function`, paged disassembly, xrefs, and caller-context proof.
5. Add the exact padding list:
   - `0x0050697f-0x00506980`
   - `0x00506ad4-0x00506ae0`
   - `0x00506b2a-0x00506b30`
   - `0x00506b7a-0x00506b80`
   - `0x00506bca-0x00506bd0`
   - `0x00506c1a-0x00506c20`
   - `0x00506c6d-0x00506c70`
   - `0x00506cbd-0x00506cc0`
   - `0x00506cdd-0x00506ce0`
6. Keep ObjectList dependency wording explicit: MapPane owns wrappers; ObjectList owns key production, key movement, key resolution, id lookup, and remove callee bodies.
7. Do not insert parent formal C++.

## Recommended Support Doc Changes

Required if implementation creates/reties children:

- `by-class/MapPane.md`: add a concise UID00037Q split note under object ownership/indexing or the MapPane field/object-list discussion. Include exact size/caller/callee facts at support-doc level: `m_objectList` at `+0x424`, child wrappers use `FindByObjectId`, `GetTypedObjectKey -> MoveKeyTo... -> ResolveObjectListKey`, and null-checked remove wrapper calls `ObjectList::RemoveObjectPane`. No class score change expected.
- `by-file/MapPane.md`: replace the "Do not close UID00037Q in this callback" wording with "UID00037Q was split/retired as non-emitting container" once applied. Preserve the same nine ranges and state they route through `NexusTK/map/MapPane.cpp`; no file score/path change expected.
- `by-memory/-ignored.md`: add missing internal padding spans if the child pages are created. Current file only showed `0x00506cdd-0x00506ce0` for this area during this report pass.

Optional only if implementation discovers current text is less detailed after child creation:

- `by-class/ObjectList.md` and `by-file/ObjectList.md`: current ObjectList support already has same-or-greater detail for `FindByObjectId`, `GetTypedObjectKey`, `ResolveObjectListKey`, `MoveKeyTo...`, and `RemoveObjectPane`; do not touch unless a stale contradiction is found.
- `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md`: optional broad-parent one-line update that UID00037Q is now a split/container, not an emitting child.
- Target-selection/item/spell caller pages: optional only if current text still names the middle/living wrappers at lower specificity than this report.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | MCP was available and current; this report is not fallback-only. | High | MCP ids `1-6`; `server_health` id `5` ok for session `supervisor_resume_20260629`; active IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; Hex-Rays and auto-analysis ready. | `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md` / MCP Provenance | incorporate | applied |
| C002 | UID00037Q is nine functions plus padding, not one source method. | High | `lookup_funcs` id `6`; `disasm` ids `40-49`; prior B004 split plan; successor `0x00506ce0` separate function. | `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md` / Status, Child Inventory, Padding And Range Notes | incorporate | applied |
| C003 | The UID00037Q parent should become a non-emitting split/container after exact child pages exist. | High | Nine distinct IDA functions, internal padding, by-structure split/container rule, and B004 prior recommendation. | `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md` / metadata header and formal C++ block | incorporate | applied |
| C004 | `0x00506970-0x0050697f` is `MapPane::FindObjectPaneById(int objectId)` / object-id lookup wrapper over `ObjectList::FindByObjectId`. | High | `analyze_function` id `10`; `disasm` id `40`; `xrefs_to` id `62`; accepted B009 [UID:0002CD]. | New child [UID:0004DR] `by-memory/0x00506970-0x0050697f.MapPaneFindObjectPaneById.md`; `by-class/MapPane.md` / Key Relationships | incorporate | applied |
| C005 | `0x00506980-0x00506ad4` is a MapPane object screen-position/bounds update helper, but not formal-C++ ready. | Medium-high | `analyze_function` id `11`; `disasm` ids `41` and `49`; reads `+0x3fc/+0x400`, tile globals, movement scale, object virtual slots, and object motion fields. | New child [UID:0004DS] `by-memory/0x00506980-0x00506ad4.MapPaneUpdateObjectPaneScreenBounds.md`; `by-class/MapPane.md` / Key Relationships | incorporate | applied |
| C006 | Six traversal wrappers use `ObjectList::GetTypedObjectKey -> ObjectList::MoveKeyTo... -> ObjectList::ResolveObjectListKey`. | High | `analyze_function` ids `12-17`; `disasm` ids `42-47`; `xrefs_to` id `62`; accepted B006/B005/B010 reports. | New child pages [UID:0004DT]-[UID:0004DY]; parent Function Inventory; `by-class/MapPane.md` / Key Relationships | incorporate | applied |
| C007 | The first traversal pair is selectable previous/next. | High | Caller analysis ids `71-72`; accepted B010/B005 names; wrappers call `sub_533170` and `sub_5333b0`. | New child pages [UID:0004DT] and [UID:0004DU] | incorporate | applied |
| C008 | The middle traversal pair is item-target alternate previous/next. | Medium-high | Caller analysis id `70` selects `0x506b80/0x506bd0` under modifier bit `0x04`; accepted B013/B010 support. | New child pages [UID:0004DV] and [UID:0004DW] | incorporate | applied |
| C009 | The last traversal pair is living-target/SpellWho previous/next with `int targetFilter`; do not promote a final field/domain name. | Medium-high | Caller analysis ids `73-74`; `disasm` ids `46-47`; B010 target-filter note and `-1/0/1` style caller values. | New child pages [UID:0004DX] and [UID:0004DY]; child source notes preserve `targetFilter` as provisional | incorporate | applied |
| C010 | `0x00506cc0-0x00506cdd` is a null-checked MapPane wrapper over `ObjectList::RemoveObjectPane(ObjectPane *object)`. | High | `analyze_function` id `18`; `disasm` id `48`; `xrefs_to` id `62`; accepted B008 [UID:0002CA]. | New child [UID:0004DZ] `by-memory/0x00506cc0-0x00506cdd.MapPaneRemoveObjectPaneIfPresent.md`; `by-class/MapPane.md` support note | incorporate | applied |
| C011 | ObjectList is dependency/callee owner for id lookup, key production/movement/resolution, and removal; MapPane owns this wrapper surface. | High | Target wrappers load `MapPane +0x424`; callers use `g_activeMapPane`; accepted ObjectList callee docs own the callee bodies. | Parent Ownership/Behavior sections; `by-class/MapPane.md`; `by-file/MapPane.md` | incorporate | applied |
| C012 | ObjectList class/file docs already contain same-or-greater accepted detail for the callee bodies unless callback reread finds a stale contradiction. | High | Current support read plus accepted B005/B006/B008/B009/B010 ObjectList reports. | `by-class/ObjectList.md` and `by-file/ObjectList.md` / method inventory and source-placement notes | already-present | already-present |
| C013 | Internal padding must be represented when children are created; at report time only `0x00506cdd-0x00506ce0` was found in `by-memory/-ignored.md`. | High | Lookup sizes/endpoints; `rg` against `by-memory/-ignored.md` matched only the final padding row for this area. | `by-memory/-ignored.md` / MapPane padding entries plus parent Padding And Range Notes | incorporate | applied |
| C014 | Parent aggregate formal C++ must stay blank; child pages may carry thin wrapper C++ only after split. | High | Nine IDA functions plus padding; by-structure split/container rule; B004 prior recommendation; First-Draft C++ section in this report. | Parent formal C++ blank; child pages [UID:0004DR], [UID:0004DT]-[UID:0004DZ] carry thin C++; [UID:0004DS] carries blank-C++ proof | incorporate | applied |
| C015 | Compiler/decompiler artifacts in this family should not be authored as C++ source. | High | Disassembly/decompiler show tail jumps, security-cookie check, stack locals, `this[265]`, and raw `[+0x424]` indexing; authored source should use member calls. | Parent Source-Quality Notes; child Source Notes / No-Code Proof sections | incorporate | applied |
| C016 | `by-file/MapPane.md` already has the follow-up split plan but should be changed from "do not close in this callback" to applied split/container wording after implementation. | High | Current `by-file/MapPane.md` lines around the UID00037Q note contain the nine-range plan and padding list as future work. | `by-file/MapPane.md` / applied UID00037Q note and Changes section | incorporate | applied |

## Implementation Tracking Checklist

- [x] C001-C003, C011, C014-C015: leased and updated `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`; parent metadata is `88/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++; added split-container/no-code proof, MCP session/health/lookup/disassembly/xref/caller evidence, ObjectList boundary, and compiler/decompiler artifact note. Proof: validator `000000004727` at `2026-07-02T17:02:36-04:00`, exit `0`, `ok:1`.
- [x] C004-C010, C014-C015: created exact child pages [UID:0004DR]-[UID:0004DZ] for all nine ranges with `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, report-specific names, behavior/callee evidence, and child-only C++/no-code disposition. Proof: parent validator `000000004727` inserted UIDs; child validators `000000004728`-`000000004736` all exited `0`, `ok:1`.
- [x] C005-C011: synced `by-class/MapPane.md` with concise UID00037Q child/wrapper/ObjectList-boundary evidence, including `m_objectList` at `+0x424`, object-id lookup, six traversal wrappers, living-target `targetFilter`, and null-checked remove wrapper. No class score change. Proof: validator `000000004737`, exit `0`, `ok:1`; warnings are pre-existing missing-ref UID noise on the broad class page.
- [x] C002-C003, C011, C016: synced `by-file/MapPane.md` from follow-up split-plan wording to applied split/container wording after child creation, preserving the `NexusTK/map/MapPane.cpp` route and no file score/path change. Proof: validator `000000004738`, exit `0`, `ok:1`; warnings are pre-existing missing-ref UID noise on the broad file page.
- [x] C012: reread `by-class/ObjectList.md` and `by-file/ObjectList.md`; both already contain same-or-greater detail for `FindByObjectId`, `GetTypedObjectKey`, `MoveKeyTo...`, `ResolveObjectListKey`, and `RemoveObjectPane`, so no ObjectList edit was needed. State: already-present.
- [x] C013: accounted for internal padding spans in `by-memory/-ignored.md` and in parent range notes. Proof: validator `000000004739`, exit `0`, `ok:1`; warnings are pre-existing missing-ref UID noise on the broad ignored ledger.
- [x] C001-C016: updated this ledger's `Verification state` row by row to `applied` or `already-present`.
- [x] Validated every edited by-* file from `source-3/project-documentation`: parent `000000004727`; children `000000004728`-`000000004736`; support/ignored `000000004737`-`000000004739`.
- [x] Callback result must report validator command ids, timestamps, exit codes, ok counts, warnings, generated-refresh state, leases used/released, and any unapplied or excluded checklist/ledger item.

Callback validators were scoped file validators only. No `execute_report`, lifecycle, registry lifecycle, manual report move, archive, generated-report manual edit, generated-output manual edit, coverage-report edit, validator-state edit, supervisor-ledger edit, or unrelated support-doc edit command was run.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004746","destination_path":"executed-b-agent-research/B014/00037Q-MapPaneObjectLookupHelpers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/00037Q-MapPaneObjectLookupHelpers-source-quality.md","timestamp":"2026-07-02T17:26:22-04:00","uid":"00037Q"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
