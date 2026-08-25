** TARGET-REPORT-UID:0003IO **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003IO **
# B002 Research Report: UID 0003IO - SharedGmWideString

## Post-Migration Supervisor Addendum (2026-06-13)

This report was written before the validator metadata split `AUTOGEN_PARENT_UID` into `CANONICAL_OWNER` and `EMITTER_UIDS`. The original "parentless" recommendation should now be read as `CANONICAL_OWNER:NONE`, not as "do not emit anywhere."

Updated final disposition: keep [UID:0003IO] no-owner because no single declaration/source owner is proven, but route output through the three proven source-use file roots with `EMITTER_UIDS:0000L3,0000KU,0000M4` ([UID:0000L3][MapPane](../../../../by-file/MapPane.md), [UID:0000KU][LivingObjectPane](../../../../by-file/LivingObjectPane.md), and [UID:0000M4][ObjectList](../../../../by-file/ObjectList.md)). This does not create a standalone global or assert that any one file canonically owns the pooled literal; it records that the literal must surface in multiple reconstructed source contexts.

## Historical Finalized Report / Superseded Wording

The bullets in this section are preserved from the original B002 report. Where they say "parentless" or "no-parent", read that through the post-migration addendum above as `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000L3,0000KU,0000M4`.

- Original recommendation: keep `[UID:0003IO] by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md` parentless, reconstructable, and source-declared/generated-binary.
- Final disposition: exact UTF-16 `GM` literal is a compiler/linker-pooled shared literal with material consumers in MapPane, LivingObjectPane, and ObjectList code. No single direct source parent clears the assignment gate.
- Required supervisor action: do not assign a parent, do not create a new owner/file, do not split or merge the item, and do not edit `by-memory/-coverage-report.md` for structural repair.
- Confidence: 90/100 for the no-parent pooled-literal outcome.

The best defensible inference is that original source referenced `L"GM"` at several independent object/actor-name suffix checks. IDA proves one emitted `.rdata` address at `0x0061e6f8` and proves direct references from already-modeled MapPane, LivingObjectPane, and ObjectList bodies, but it does not prove an original shared declaration, helper, header constant, or source file that should own the literal.

If the supervisor wants an explicit closure note in the target page, use this exact text:

```text
B002 ownership review (2026-06-13): retain parentless status. IDA MCP confirms exact UTF-16 `GM` at `0x0061e6f8-0x0061e700`, unique bytes `47 00 4D 00 00 00 00 00`, with 20 direct code xrefs split across MapPane `sub_505430`, LivingObjectPane suffix helper `sub_514EA0`, and six ObjectList extended lookup helpers `sub_533170`/`sub_5333B0`/`sub_533600`/`sub_533850`/`sub_533A90`/`sub_533D00`. The GM suffix tests are inlined at the consuming sites; no common GM/name helper, source file, or direct declaration owner is proven. Keep `AUTOGEN_PARENT_UID` blank as a parentless pooled-literal outcome.
```

Recommended metadata state:

```yaml
AUTOGEN_PARENT_UID:
AUTOGEN_RECONSTRUCTABLE: "true"
AUTOGEN_COMPLETION: 88
AUTOGEN_CONFIDENCE: 93
```

Recommended generated-source handling:

```text
Emit or preserve `L"GM"` at each reconstructed use site. Do not model a standalone global, do not attach it to ObjectList solely because ObjectList has most refs, and do not create a new shared source file for this single pooled literal.
```

All affected files for supervisor consideration:

```text
by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md
auto-generated/-ag-memory-coverage.md
```

No required changes are recommended for:

```text
by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md
by-memory/-coverage-report.md
by-file/MapPane.md
by-file/LivingObjectPane.md
by-file/ObjectList.md
by-class/MapPane.md
by-class/LivingObjectPane.md
by-class/ObjectList.md
```

If coverage status notes are updated externally, keep the row parent blank and reclassify the reason from ownership-unknown to reviewed parentless pooled literal:

```text
- [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) `0x0061e6f8-0x0061e700` | string-data | `SharedGmWideString` : reconstructable : 88% : very strong : Exact UTF-16 `GM` literal pooled across MapPane `sub_505430`, LivingObjectPane `sub_514EA0`, and ObjectList lookup helpers; parent blank by design.
```

## Target

- Assignment: `B002-0003IO`
- Target UID: `0003IO`
- Target path: `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md`
- Source queue: `auto-generated/-ag-memory-coverage.md`
- Current queue state: `unassigned`, reviewed-85-but-ownership-unknown.
- Address range: `0x0061e6f8-0x0061e700`
- Payload: UTF-16 `GM` plus trailing null/alignment bytes.
- Current parent: blank.
- Current reconstructable state: true.
- Physical neighbor/index: `[UID:0003C1] by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md`

## Supervisor Active Recheck

- The assigned exact child already exists and has precise bounds.
- Split repair is not needed. The target is already isolated from adjacent `MAPNAME.EPF`, `MMAPBUT.EPF`, and `CMAP` children.
- Direct edits to by-* docs and coverage reports were not performed.
- This report is placed directly in `tools/leaser/Agents/Agent-B002/research/` per the B-agent workflow.

## Evidence Standards Used

IDA MCP evidence used:

- `server_health` for active IDB context.
- `entity_query`, `get_bytes`, `get_string`, and `make_signature_for_range` for exact bytes, symbol state, and uniqueness.
- `xrefs_to`, `xref_query`, and `trace_data_flow` for direct literal consumers.
- `lookup_funcs`, `callees`, `xrefs_to` on consumer functions, and `analyze_component` for function ownership and call graph separation.
- `decompile` for consumer semantics and negative helper evidence.

Documentation evidence used:

- `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md`
- `by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md`
- `by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md`
- `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md`
- `by-memory/0x00505430-0x005055ca.MapPaneWeatherCoordinateObjectCore.md`
- `by-file/MapPane.md`, `by-class/MapPane.md`
- `by-file/LivingObjectPane.md`, `by-class/LivingObjectPane.md`
- `by-file/ObjectList.md`, `by-class/ObjectList.md`
- `by-structure.md`
- `inference_research.md`
- `by-project-structure/proposed-source-tree.md`

Guidance applied:

- `by-structure.md` treats `AUTOGEN_PARENT_UID` as a direct semantic ownership claim, not an output-routing shortcut.
- `inference_research.md` allows address adjacency and xref counts to inform hypotheses, but does not let them override direct source-ownership evidence. It also treats compiler/linker string pooling as a real no-parent outcome when a single emitted literal serves multiple source contexts.
- `by-project-structure/proposed-source-tree.md` already separates `map/MapPane.cpp`, `map/LivingObjectPane.cpp`, and `map/ObjectList.cpp`, which matters because each has direct or documented GM consumer code.

## IDA MCP Facts

IDA session:

```text
Session: a001_goal2_0002UM
Input: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
IDB: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
Module: NexusTK.exe
Image base: 0x00400000
Hex-Rays ready: true
Strings cache ready: true
```

Entity and raw-byte facts for the neighborhood:

```text
0x0061e6c8  aAmeEpf_0  .rdata
0x0061e6dc  aApbutEpf  .rdata
0x0061e6f0  aCmap      .rdata, global size 5
0x0061e6f8  aGm        .rdata, global size 6
0x0061e704  ??_7?$ProtectedArray@UNationEntry@GameServerConfig@@@@6B@
0x0061e70c  ??_7GameServerConfig@@6B@
```

Decoded byte sequence for `[UID:0003C1]`:

```text
0x0061e6c0: UTF-16 "MAPNAME.EPF"
0x0061e6d8: UTF-16 "MMAPBUT.EPF"
0x0061e6f0: ASCII  "CMAP"
0x0061e6f8: UTF-16 "GM"
0x0061e700: zero padding / transition into following RTTI-vtable data
```

Exact target bytes:

```text
0x0061e6f8: 47 00 4D 00 00 00 00 00
```

IDA string result:

```text
0x0061e6f8: GM
```

Signature result:

```text
Range: 0x0061e6f8-0x0061e700
Signature: 47 00 4D 00 00 00 00 00
Unique: true
```

## Direct Xref Inventory

IDA MCP reports exactly 20 direct code xrefs to `0x0061e6f8`:

```text
0x00505505 in sub_505430  size 0x019a  MapPane movement/collision/nation-mask helper
0x00514ec5 in sub_514EA0  size 0x003d  LivingObjectPane GM suffix helper
0x0053321a in sub_533170  size 0x0240  ObjectList extended lookup helper
0x005332b5 in sub_533170  size 0x0240  ObjectList extended lookup helper
0x0053334c in sub_533170  size 0x0240  ObjectList extended lookup helper
0x00533445 in sub_5333B0  size 0x024e  ObjectList extended lookup helper
0x00533515 in sub_5333B0  size 0x024e  ObjectList extended lookup helper
0x005335b7 in sub_5333B0  size 0x024e  ObjectList extended lookup helper
0x005336a5 in sub_533600  size 0x0243  ObjectList extended lookup helper
0x00533738 in sub_533600  size 0x0243  ObjectList extended lookup helper
0x005337d7 in sub_533600  size 0x0243  ObjectList extended lookup helper
0x005338dc in sub_533850  size 0x023d  ObjectList extended lookup helper
0x0053397a in sub_533850  size 0x023d  ObjectList extended lookup helper
0x00533a1b in sub_533850  size 0x023d  ObjectList extended lookup helper
0x00533b3a in sub_533A90  size 0x0267  ObjectList extended lookup helper
0x00533bfa in sub_533A90  size 0x0267  ObjectList extended lookup helper
0x00533ca5 in sub_533A90  size 0x0267  ObjectList extended lookup helper
0x00533d9a in sub_533D00  size 0x026d  ObjectList extended lookup helper
0x00533e6a in sub_533D00  size 0x026d  ObjectList extended lookup helper
0x00533f19 in sub_533D00  size 0x026d  ObjectList extended lookup helper
```

Grouped by modeled owner:

```text
MapPane direct use:             1 xref
LivingObjectPane direct use:    1 xref
ObjectList direct uses:        18 xrefs
```

The ObjectList count is the strongest numerical signal, but it is not a direct ownership proof because MapPane and LivingObjectPane each have independent direct source-context uses.

## Consumer Semantics

### MapPane consumer

`sub_505430` is documented under `[UID:0001AP] MapPaneWeatherCoordinateObjectCore`, owned by MapPane. IDA decompilation shows it performs movement/collision/nation-mask work, asks ObjectList for an object at target coordinates through `sub_533090`, then directly tests the object name tail against `L"GM"`.

Relevant decompilation shape:

```c
object = sub_533090(objectList, rowOrCoord);
if (object)
{
    /* scan wide object name at object + 0x126 / object + 0x128 */
    if (_wcsicmp((const wchar_t *)(object + computedTailOffset), L"GM") != 0
        && !*(_BYTE *)(object + 466))
        return 0;
}
```

Facts and inference:

- The literal is directly referenced by MapPane code at `0x00505505`.
- This is not just a pass-through from ObjectList; the GM suffix compare is in the MapPane helper body.
- The object being inspected appears to be a living/object entry because the wide name fields are the same offsets used by LivingObjectPane/ObjectList logic, but that field-level similarity does not transfer ownership of the literal to LivingObjectPane.

### LivingObjectPane consumer

`sub_514EA0` is documented as `[UID:000233] LivingObjectPaneGmNameSuffixCheck`, with parent `[UID:0000KU]` `by-file/LivingObjectPane.md`.

IDA decompilation:

```c
bool __thiscall sub_514EA0(char *this)
{
    /* scan wide name at this + 0x126 / this + 0x128 */
    return _wcsicmp((const wchar_t *)(this + computedTailOffset), L"GM") == 0;
}
```

Caller evidence:

```text
sub_514EA0 has one code xref:
0x0050a552 in sub_50A500
```

`sub_50A500` is a MapPane paint/selection path. It calls the LivingObjectPane method to decide whether a selected hidden/GM actor should be cleared. That caller relationship makes MapPane a consumer of the LivingObjectPane method, but it does not move the method or the direct `0x00514ec5` literal reference out of LivingObjectPane ownership.

### ObjectList consumers

`sub_533170`, `sub_5333B0`, `sub_533600`, `sub_533850`, `sub_533A90`, and `sub_533D00` are documented inside `[UID:00023F] ObjectListExtendedTypeLookupHelpers`, with parent `[UID:0000M4]` `by-file/ObjectList.md`.

IDA decompilation of the representative helpers shows the same pattern:

```c
sub_535CE0(encodedKey, decodedParts);
/* scan row/global ObjectList entries */
if (!object->hidden && !object->stateOrId && object->type == 5)
{
    /* scan wide object name at object + 0x126 / object + 0x128 */
    if (_wcsicmp(nameTail, L"GM") == 0)
        /* skip or accept depending on helper variant */
}
```

Caller evidence for the six helper bodies:

```text
sub_533170 called from sub_506AE0 at 0x00506b02
sub_5333B0 called from sub_506B30 at 0x00506b52
sub_533600 called from sub_506B80 at 0x00506ba2
sub_533850 called from sub_506BD0 at 0x00506bf2
sub_533A90 called from sub_506C20 at 0x00506c45
sub_533D00 called from sub_506C70 at 0x00506c95
```

The callers are short MapPane wrappers around the ObjectList pointer at MapPane offset `0x424`. That proves MapPane consumes ObjectList lookup services. It does not prove MapPane owns the ObjectList helper implementations.

### Negative helper evidence

IDA MCP `analyze_component` across all eight direct consumer functions reported `aGm` as the only shared global. There are no internal call-graph edges among the MapPane, LivingObjectPane, and six ObjectList direct consumers.

The likely helper candidates were checked:

```text
sub_514EA0  LivingObjectPane GM suffix method; only called by MapPane sub_50A500. Not called by sub_505430 or ObjectList helpers.
sub_533090  ObjectList coordinate/row lookup helper; called by sub_505430. No GM reference.
sub_535CE0  ObjectList encoded-key decoder; called by six ObjectList helpers and one other ObjectList helper. No GM reference.
```

This blocks the "shared actor/object-name helper" ownership theory for the current evidence set. The suffix logic is duplicated or inlined at use sites.

## Documentation Cross-Check

The target page already identifies the literal as UTF-16 `GM`, named `aGm`, unique bytes `47 00 4D 00 00 00 00 00`, with 20 executable xrefs. It currently leaves `AUTOGEN_PARENT_UID` blank because the documented consumers span MapPane, LivingObjectPane, and ObjectList paths.

The physical container `[UID:0003C1] MapNameMiniMapResourceStrings` is a non-emitting mixed index over:

```text
[UID:0003IL] MAPNAME.EPF  -> MapNamePane
[UID:0003IM] MMAPBUT.EPF  -> MiniMapButtonPane
[UID:0003IN] CMAP         -> MapPane file fallback via pointer slot
[UID:0003IO] GM           -> shared/parentless target
```

That page correctly treats the physical range as mixed and parentless. It should not own the child and does not need structural repair.

The class/file documentation aligns with the IDA split:

```text
by-file/MapPane.md / by-class/MapPane.md
  Owns MapPane code including the movement/collision/nation-mask helper that directly references GM at 0x00505505.

by-file/LivingObjectPane.md / by-class/LivingObjectPane.md
  Owns LivingObjectPane actor/object state and the standalone GM suffix method [UID:000233].

by-file/ObjectList.md / by-class/ObjectList.md
  Owns ObjectList row/global lookup helpers including [UID:00023F].
```

`by-project-structure/proposed-source-tree.md` likewise lists `map/ObjectList.cpp`, `map/LivingObjectPane.cpp`, and `map/MapPane.cpp` as separate source modules. This reinforces that a single parent assignment would be a semantic claim, not just a generated-output convenience.

## Ranked Ownership Outcomes

1. Keep UID 0003IO parentless as a pooled source-declared/generated-binary literal.
   - Confidence: 90/100.
   - Reason: IDA proves exact one-address sharing across independently modeled MapPane, LivingObjectPane, and ObjectList source contexts, and proves no common GM/name helper among the direct consumer functions. Parent blank is the most accurate representation.

2. Create a new shared actor/object-name helper or source file.
   - Confidence: 24/100.
   - Best hypothetical name if forced: `map/ObjectNameRules.cpp` or `map/ActorNameRules.cpp`.
   - Reason rejected: no direct helper, no xref cluster of related constants, no source/debug metadata, and no function body to place there. A new file would contain only one pooled literal or a speculative helper not present in the binary.

3. Assign to ObjectList.
   - Confidence if forced: 58/100.
   - Best forced existing owner: `by-file/ObjectList.md` `[UID:0000M4]`, not `by-class/ObjectList.md`, because the references are helper/file-level implementation details.
   - Reason for plausibility: ObjectList has 18 of 20 direct xrefs and six helper bodies repeat the suffix filter.
   - Reason rejected: MapPane `sub_505430` and LivingObjectPane `sub_514EA0` directly reference the same literal in their own bodies. ObjectList cannot own those source uses.

4. Assign to LivingObjectPane.
   - Confidence if forced: 45/100.
   - Reason for plausibility: the cleanest semantic helper is `[UID:000233] LivingObjectPaneGmNameSuffixCheck`, and all three consumer families inspect the same living/object wide-name field offsets.
   - Reason rejected: MapPane and ObjectList do not call `sub_514EA0` for their direct suffix checks. Field semantics are not enough to assign a pooled literal to the class that owns one helper.

5. Assign to MapPane.
   - Confidence if forced: 38/100.
   - Reason for plausibility: MapPane directly references the literal in movement/collision logic and calls wrapper paths that consume ObjectList and LivingObjectPane GM behavior.
   - Reason rejected: most direct references are in ObjectList helper bodies, and the standalone suffix method is LivingObjectPane. MapPane is a major consumer, not the declaration owner.

6. Assign to physical container `[UID:0003C1]`.
   - Confidence: 8/100.
   - Reason rejected: 0003C1 is a non-emitting mixed by-memory index whose children have different owners. Physical adjacency to `MAPNAME.EPF`, `MMAPBUT.EPF`, `CMAP`, and nearby RTTI/vtable data is not source ownership.

## Source Reconstruction Guidance

Do not introduce a generated global like:

```cpp
static const wchar_t kGm[] = L"GM";
```

That would imply a single source declaration not proven by the binary. Instead, preserve source-local uses where behavior is reconstructed:

```cpp
_wcsicmp(nameTail, L"GM")
```

Likely reconstructed source placement:

```text
map/MapPane.cpp
  MapPane movement/collision helper contains its direct inline `L"GM"` comparison.

map/LivingObjectPane.cpp
  LivingObjectPane GM suffix method contains its direct inline `L"GM"` comparison.

map/ObjectList.cpp
  ObjectList extended lookup helpers contain their direct inline `L"GM"` comparisons.
```

This handles the real source semantics without inventing a cross-file owner for a linker-pooled emitted literal.

## Required Changes

No structural changes are required.

Recommended supervisor changes, if documenting the completed review:

```text
1. In `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md`, replace "ownership unknown" style wording with "confirmed parentless pooled-literal outcome".
2. Keep `AUTOGEN_PARENT_UID` blank.
3. Keep `AUTOGEN_RECONSTRUCTABLE: TRUE`.
4. Do not add a C++ global/source block.
5. Keep `[UID:0003C1]` as a non-emitting mixed physical container; no split repair.
6. If `auto-generated/-ag-memory-coverage.md` is used for external tracking, update only the review reason/status to parentless pooled literal, preserving blank parent semantics.
```

No direct edits were made to the by-* docs or coverage files as part of this assignment.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003IO","source_path":"executed-b-agent-research/B002/0003IO-SharedGmWideString.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
