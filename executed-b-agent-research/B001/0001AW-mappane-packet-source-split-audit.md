** TARGET-REPORT-UID:0001AW **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Research Report: 0001AW MapPane Packet Source Split Audit

Assignment: `B001-goal2-memory-tool-mappane-packet-source-split-0001AW-20260616`  
Agent: `Agent-B001`  
Target: [UID:0001AW] `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`  
Report-only: no by-memory, by-class, by-file, generated report, coverage report, or IDA DB edits were made.

## Final Recommendation

[UID:0001AW] should not remain a final reconstructable source-emitting aggregate. It should become a non-emitting MapPane packet/source-family split index after exact child pages are created for the remaining modeled functions, raw no-function packet bodies, and local switch-table tails.

Do not reclassify it before child coverage exists. Today [UID:0001AW] is still the only documentation carrier for two large reconstructable leaves:

- `0x0050e4c0-0x00510400`, 8000 bytes.
- `0x005104c7-0x00513800`, 13113 bytes.

Those broad leaves still contain many real modeled functions plus raw function-shaped bodies. Demoting the parent immediately would drop source-bearing evidence below the source-quality gate. The correct route is split-first:

1. Create exact child pages for the remaining function/raw spans listed below.
2. Keep [UID:0001AW] as `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:00007Q], until the child set validates and carries all reconstructable bytes at defensible 85/85+ scores.
3. After child validation, change [UID:0001AW] to a non-emitting split index:
   - `COMPLETION:88`
   - `CONFIDENCE:91`
   - `CANONICAL_OWNER:00007Q`
   - `RECONSTRUCTABLE:FALSE`
   - `EMITTER_UIDS:` blank
   - final C++ blank

The source-placement model is:

- MapPane owns the packet parser/dispatcher family, object/event update helpers, protocol response helpers, and local MapPane-owned raw duplicate bodies.
- SelfSaveOKPane child pages [UID:0001AY] and [UID:0001B0] stay owned/emitted by [UID:0000NN], not MapPane.
- WorldMapPane construction remains WorldMapPane-owned. MapPane owns only the packet route that allocates/uses it.
- EffectObjectPane helpers stay with EffectObjectPane where already documented; MapPane owns the packet-side creation/caller path.
- Friend-name sync protocol storage remains with the friend-sync/global support pages; MapPane owns only the live/raw packet handler copies.
- Raw starts `0x00510400`, `0x00513920`, and `0x00514380` and the additional raw starts below should not be turned into IDA functions yet. They have no proven incoming xrefs or pointer-table route, and that no-function state is part of the evidence.

## Executable Supervisor Batch (Option A)

This is the immediately executable first child-split batch. It creates one exact child at the start of [UID:0001AW] and records the three-byte alignment after it. It does not reclassify [UID:0001AW]; the parent remains `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:00007Q], and `85/88` after this first batch.

### UID Allocation Plan

Current registry check: `tools/validator.ini` has `[state] last_used_uid = 0003TA`. Reserve the next UID:

```ini
0003TB = by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md
```

Supervisor application note: if `last_used_uid` has advanced before execution, stop and allocate the current next UID instead, then mechanically replace `0003TB` in the page text, parent/support edits, and coverage rows below.

After creating the child page, advance `[state] last_used_uid` to `0003TB` if the validator does not do that automatically.

### New Child Page To Create

Path:

`by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md`

Exact content:

~~~md
*** UID:0003TB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0050e4c0-0x0050e68d MapPane Process Map Event

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact `MapPane` class method child split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Working source name: `MapPane::ProcessMapEvent`; this name is supported by generated-source/search evidence but remains provisional for final C++.
- Direct class parent: [UID:00007Q][MapPane](by-class/MapPane.md).
- Source route: [UID:0000L3][MapPane](by-file/MapPane.md).
- Rebuild handling: source-authored MapPane event/object marker helper. Keep final C++ blank until the packet/event payload type, MapPane object-list field names, and HitBarObjectPane attachment helper names are final-source quality.

## Range And Boundary

| Item | Evidence |
| --- | --- |
| Start | `0x0050e4c0`; IDA models `sub_50E4C0` here. |
| End | `0x0050e68d` end-exclusive; IDA function size is `0x1cd`. |
| Return | Raw bytes at `0x0050e687-0x0050e68c` include the epilogue and `retn 4`. |
| Successor padding | Raw PE bytes at `0x0050e68d-0x0050e690` are `cc cc cc`. |
| Next function | `0x0050e690` begins the next modeled function in the [UID:0001AW] aggregate. |

The leading boundary is also closed by [UID:0000VN][-ignored](by-memory/-ignored.md) padding at `0x0050e4b6-0x0050e4c0` after [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md).

## Behavior

This method is a MapPane-side object event and hit-bar update helper. The generated `simroot_v2/class_MapPane.cpp` body labels it `ProcessMapEvent` and shows this recovered shape:

1. Decode an event payload beginning at the stack argument: object id, damage amount, effect/type value, and current hit-point value.
2. Look up the target object through MapPane object-index state.
3. Return immediately if the target object is not present.
4. Read the target object's grid/screen placement support state.
5. If a HitBarObjectPane is already attached to the target, update the existing hit bar.
6. Otherwise, remove stale/dead marker state, allocate and construct a HitBarObjectPane, attach it to the target object, register it in the MapPane object list, and refresh/compute its bounds.

The behavior is MapPane-owned because the method resolves an object id against MapPane object/index state and mutates MapPane-visible attached-object relationships. The constructed/updated overlay remains [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md)-owned source.

## Caller And Callee Evidence

- Live IDA evidence gathered for this B001 assignment reports code refs to `0x0050e4c0` from the MapPane packet family and group/user/living/object marker paths, including `0x0050fb00`, `0x0056dd50`, `0x0056e130`, `0x005a76c0`, `0x005ac280`, and `0x005adc20`, plus raw/no-function contexts that should not be used as final caller names yet.
- [UID:0001KR][0x005adc20-0x005adcb3.GroupMemberMarkers](by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md) documents `0x005adc20` as a group-member marker refresh helper that forwards cached group member ids into this MapPane event/marker path.
- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md) records this address as a constructor/update caller for HitBarObjectPane: the dual constructor is called from `0x0050e4c0`, bounds/state helper calls originate from `0x0050e4c0`, and the active-flag accessor is used by `0x0050e4c0`.
- [UID:0002WP][0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage](by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md) records direct pool allocation evidence at `0x0050e5fc` inside this method, tying the constructed object to HitBarObjectPane static-pool storage.
- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) already lists `0x0050e4c0` as a modeled MapPane event/member marker refresh helper and records this address as part of the MapPane packet/object/event family.

## Source Placement Decision

Assign this child to [UID:00007Q][MapPane](by-class/MapPane.md), emitting through [UID:00007Q]. The function is MapPane behavior even though it constructs or updates [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md): MapPane owns the event payload routing, target lookup, object-list registration, and object/marker side effects. HitBarObjectPane owns the constructed overlay class, vtables, pool storage, rendering, and destructor behavior.

Rejected owners:

- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md): consumer/constructed class, not owner of the MapPane event payload route.
- [UID:0000JS][Group](by-file/Group.md): some group-marker helpers call this function, but Group supplies member ids and does not own MapPane object side effects.
- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md): source-family parent only; this exact child carries the method-level source evidence.

## Reconstruction Notes

Final C++ remains blank. The behavior is clear enough for an exact child split, but the final source should wait for:

- the real event payload struct or packet-reader type;
- final names for the MapPane object-index field and target-object attachment slots;
- final names for the HitBarObjectPane create/update/bounds helpers;
- final decision on whether `ProcessMapEvent` was the original method name or only a generated recovery label.

## Score Rationale

Completion is `86` because the page has exact range/boundary evidence, raw padding closure, modeled-function status, caller-family evidence, HitBarObjectPane constructor/pool links, source-owner decision, rejected-owner rationale, and explicit final-C++ blockers.

Confidence is `89` because multiple independent docs agree on MapPane ownership and HitBarObjectPane callee relationships. Confidence stays below final range because the original method name, payload type, and field names are not final-source quality.

## Cross-References

- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md)
- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md)
- [UID:0002WP][0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage](by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md)
- [UID:0001KR][0x005adc20-0x005adcb3.GroupMemberMarkers](by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 executable child-split batch: created as the exact first child of [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md), scored `86/89`, routed to [UID:00007Q][MapPane](by-class/MapPane.md), and left final C++ blank pending final payload/field/helper names. Evidence: IDA function inventory reports `0x0050e4c0` as a modeled `0x1cd`-byte function, raw PE bytes close the end at `0x0050e68d` with `0x0050e68d-0x0050e690` padding, existing MapPane/HitBarObjectPane/GroupMemberMarkers/pool-storage docs tie the method to MapPane object-event side effects and HitBarObjectPane construction/update callees.
~~~

### Padding Ledger Entry

Add this exact entry to `by-memory/-ignored.md` immediately after the existing `0x0050e4b6-0x0050e4c0` entry:

```md
- `0x0050e68d-0x0050e690` - alignment padding after `MapPaneProcessMapEvent`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes, not executable product logic.
  - Evidence: 2026-06-16 B001 raw PE byte check shows `cc cc cc` at `0x0050e68d-0x0050e690`; the preceding modeled function `sub_50E4C0` returns with `retn 4` through byte `0x0050e68c`, and the next modeled function begins at `0x0050e690`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent](by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md) and [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
```

### Parent Page Edits

Apply these exact edits to [UID:0001AW] `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`.

In `## Exact Child Pages And Nesting`, insert this row before the [UID:0001AX] row:

```md
| [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent](by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md) | Exact modeled first child for the MapPane process-map-event/object-marker helper; updates or creates HitBarObjectPane overlays while keeping HitBarObjectPane source ownership separate. |
```

In `## Current Exact Boundary Inventory`, replace the `0x0050e4c0` row with:

```md
| `0x0050e4c0` | `sub_50E4C0` | `0x1cd` | Exact child [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent](by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md); MapPane process-map-event/object-marker helper with HitBarObjectPane construction/update evidence. |
```

Append this change note under `## Changes`:

```md
- 2026-06-16 B001 executable child-split addendum: created exact child [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent](by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md) and ignored padding `0x0050e68d-0x0050e690`. Parent [UID:0001AW] remains `RECONSTRUCTABLE:TRUE`, `85/88`, and owner/emitter [UID:00007Q] because the remaining broad leaves still need exact children.
```

Do not change [UID:0001AW] metadata in this first batch.

### Support Doc Edits

Apply these exact minimal support-doc edits. No score changes are recommended for support docs in this first batch.

In [UID:00007Q] `by-class/MapPane.md`, insert this cross-reference immediately after the existing [UID:0001AW] cross-reference:

```md
- [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent](by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md)
```

Append this change note to [UID:00007Q] `by-class/MapPane.md`:

```md
- 2026-06-16 B001 executable child-split addendum:
  - Score unchanged at `85/85`.
  - Added exact packet/event child [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent](by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md), the modeled MapPane process-map-event/object-marker helper that updates or creates HitBarObjectPane overlays while leaving HitBarObjectPane source ownership separate.
```

In [UID:0000L3] `by-file/MapPane.md`, insert this cross-reference immediately after the existing [UID:0001AW] cross-reference:

```md
- [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent](by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md)
```

Append this change note to [UID:0000L3] `by-file/MapPane.md`:

```md
- 2026-06-16 B001 executable child-split addendum:
  - Score unchanged at `89/85`.
  - Added exact child [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent](by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md) under the MapPane packet/object/event family. The child documents MapPane-owned event routing and HitBarObjectPane construction/update calls while preserving HitBarObjectPane as the direct overlay class owner.
```

No edit is required to [UID:000067] `HitBarObjectPane.md` or [UID:0002WP] `HitBarObjectPanePoolStaticStorage.md`; both already record the relevant `0x0050e4c0` caller/allocation evidence.

### Coverage Report Rows For This Batch

Placement: in `by-memory/-coverage-report.md`, inside the existing [UID:0001AW] block, insert these rows immediately after the [UID:0001AW] parent row and before the existing [UID:0001AX] child row.

```md
        - [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent](by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md) 0x0050e4c0-0x0050e68d | class method | MapPaneProcessMapEvent : reconstructable : 86% : strong : Exact first child split from MapPanePacketHandlers; modeled `sub_50E4C0` process-map-event/object-marker helper that decodes an object event payload, resolves the target through MapPane object state, updates or creates HitBarObjectPane overlays, and registers/refreshes the attached overlay. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); HitBarObjectPane remains the constructed overlay owner. Final C++ blank pending final payload, field, and helper names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050e68d-0x0050e690 | padding | MapPaneProcessMapEvent to next MapPane packet helper alignment : ignored : 100% : strong : B001 raw PE byte check shows three `0xcc` bytes after `sub_50E4C0` returns with `retn 4` through `0x0050e68c` and before the next modeled function starts at `0x0050e690`.
```

Do not replace the [UID:0001AW] parent row yet. The parent still has large source-bearing childless leaves after this first batch.

### Validation Order For This Batch

1. Confirm `tools/validator.ini` still has `last_used_uid = 0003TA`; if not, allocate the actual next UID and adjust all `0003TB` references before applying.
2. Create `by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md` with the exact page text above.
3. Add the padding entry to `by-memory/-ignored.md`.
4. Apply the [UID:0001AW], [UID:00007Q], and [UID:0000L3] support-doc edits above.
5. Insert the two nested coverage rows above under [UID:0001AW].
6. Run the documentation validator.
7. Run `memory_ranges.py report`.
8. Confirm no barrier/general/filename/advanced errors, [UID:0003TB] validates at `86/89`, the padding row is recognized as ignored, and [UID:0001AW] remains reconstructable at `85/88`.

### Below-Gate Items In The Earlier Full Inventory

The earlier full child inventory remains a roadmap only. Do not create the `84/87` proposed children in that table as part of this executable batch. They need deeper behavior/source-owner research before they can support parent reclassification.

## Current State Checked

Target page:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:00007Q`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00007Q`
- final C++ blank

Existing child pages inside the span:

- [UID:0001AX] `0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md`, raw duplicate day/night body, `84/88`, owner/emitter [UID:0000L3].
- [UID:0001AY] `0x00513800-0x00513920.SelfSaveOKPaneFactory.md`, SelfSaveOKPane factory/helper, `86/86`, owner/emitter [UID:0000NN].
- [UID:0001AZ] `0x00514380-0x005143b7.FriendNameListSyncRawHandler.md`, raw duplicate friend sync body, `84/88`, owner/emitter [UID:0000L3].
- [UID:0001B0] `0x005147d0-0x00514914.SelfSaveOKPane.md`, SelfSaveOKPane constructor/timer island, `88/88`, owner/emitter [UID:0000NN].
- Ignored padding [UID:0000VN] `0x00514914-0x00514920`.

The refreshed memory report still lists [UID:0001AW] as a large reconstructable leaf because most of the packet-handler family is not split into exact children. This is the primary reason [UID:0001AW] should not be treated as finished final-source material.

## Evidence Checked

### Live IDA/MCP Session

Opened `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` through `ida-pro-mcp` as session `b001_mappane_0001AW_20260616`; Hex-Rays was available. The target range was inspected with function inventory, xrefs, raw-start lookups, instruction listings, and function profiles.

IDA function inventory in `0x0050e4c0-0x00514920` contains 51 modeled functions before the successor [UID:0001B1] at `0x00514920`. The modeled functions include packet dispatcher callees, object/effect helpers, UI/pane creation helpers, no-op stubs, response builders, and SelfSaveOKPane functions.

Important function-start/xref results:

- `0x0050fb00`, `0x0050feb0`, `0x005104d0`, `0x00510960`, `0x00511440`, `0x00511710`, `0x00511c90`, `0x00511db0`, `0x00512960`, `0x00512d60`, `0x00512f20`, `0x00513310`, `0x00513c90`, `0x00513da0`, and `0x00514640` are live packet-dispatcher callees from `0x00507c90`.
- `0x0050e4c0`, `0x0050e810`, `0x0050e850`, `0x0050ea30`, `0x0050eb90`, and `0x0050edd0` have external or intra-family xrefs through object/marker/effect helper routes.
- `0x0050f270` calls the WorldMapPane constructor at `0x005c2ac0`; this supports a MapPane packet/source route but not WorldMapPane ownership.
- `0x0050ea30` calls the EffectObjectPane constructor and `EffectObjectPaneStartIdleTimer`; this supports MapPane ownership for the caller path and EffectObjectPane ownership for the helper.
- `0x00513800` and `0x005147d0` have no direct code xrefs, but their SelfSaveOKPane ownership is already supported by vtable/literal/timer evidence and packet-created UI context.
- `0x005148e0` has a data xref from the SelfSaveOKPane timer vtable.

Raw/no-function start lookups:

- `0x00510400`, `0x00513920`, `0x00514380`, and adjacent end/padding addresses are not IDA functions.
- The raw starts have no IDA xrefs.
- The raw starts should remain no-function evidence unless a later pass proves a safe function-definition route.

### Raw PE Scans

Read-only PE scans against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirmed:

- Image base `0x400000`.
- `.text` covers `0x00401000-0x0060c600`.
- No absolute VA dword hits, RVA dword hits, or credible rel32 branch/call hits to the checked raw starts:
  - `0x00510400`
  - `0x00513920`
  - `0x00514380`
  - additional hidden raw starts listed below
  - SelfSave starts `0x00513800` and `0x005147d0`

Naive rel32 byte scans produced a few apparent hits into raw starts, but live IDA xrefs to those same starts were zero and the bytes sit inside unrelated instruction/data contexts. They are not safe caller evidence.

### Support Documentation Checked

Checked source-route and ownership support pages:

- [UID:00007Q] `by-class/MapPane.md`
- [UID:0000L3] `by-file/MapPane.md`
- [UID:00037T] `by-memory/0x00507c90-0x00508f60.MapPanePacketDispatcher.md`
- [UID:0001SO] `by-type/by-enum/MapServerPacketOpcode.md`
- [UID:0001AX], [UID:0001AY], [UID:0001AZ], [UID:0001B0]
- [UID:0000NN] and [UID:0000CX] SelfSaveOKPane support pages
- [UID:0000PB] WorldMapPane support page
- [UID:0000L4] and [UID:0001B1] MapRefreshDimmer support pages
- [UID:0001DA] EffectObjectPaneStartIdleTimer
- [UID:0000UP] FriendNameListSyncOpcodes
- [UID:0003IW] MapPane user-face asset path strings
- [UID:0003JK] MapPane `Mscfg.dll` format string
- [UID:00027N] MapPane checksum lookup table
- [UID:00027Q] MapPane day/night float table
- [UID:0001OM] FriendNameListSyncEnabled

The support docs agree on the source-family split: MapPane owns packet parsing and object/event routes; SelfSaveOKPane and WorldMapPane remain separate source classes/files; raw duplicate bodies are evidence, not final emitted standalone C++ yet.

## Raw and Split Findings

The current four child pages are not enough. Between the modeled IDA functions are multiple no-function bodies, local switch tables, and packet-helper islands. These are the exact source-quality blockers for final C++.

### Existing Raw Duplicate Bodies

[UID:0001AX] `0x00510400-0x005104c7`:

- Exact raw prologue and `retn 4` body.
- No IDA function object.
- No xrefs to raw start.
- No VA/RVA/rel32 pointer route.
- Duplicates the live dispatcher opcode `0x20` day/night body.
- Best source model: retained out-of-line/duplicate MapPane packet-handler body, not a called standalone function in this binary.

[UID:0001AZ] `0x00514380-0x005143b7`:

- Exact raw prologue and return.
- No IDA function object.
- No xrefs to raw start.
- No VA/RVA/rel32 pointer route.
- Duplicates the live dispatcher opcode `0x6a` friend/name-list sync path.
- Best source model: retained duplicate MapPane packet-handler body, not a proved live route.

Both should remain reconstructable evidence pages with blank final C++; they should not emit final standalone methods unless a future build/source proof appears.

### Additional No-Function Bodies Found

Raw scans and instruction listings found additional source-bearing no-function bodies not represented as exact child pages:

- `0x0050f3c0-0x0050f454`: packet builder sends opcode `0x05`; no raw-start xrefs.
- `0x0050f460-0x0050f4c8`: MapPane refresh/request body, writes `MapPane+0x4cd`, may refresh object list; no raw-start xrefs.
- `0x0050f530-0x0050f581`: packet builder body; no raw-start xrefs.
- `0x0050f590-0x0050f5dd`: packet builder body; no raw-start xrefs.
- `0x0050f5e0-0x0050f615`: packet builder body; no raw-start xrefs.
- `0x0050f620-0x0050f9b9`: user-face asset path body using `/users/`, `.epf`, `.face`, file reads, `WideCharToMultiByte`, and packet send; no raw-start xrefs.
- `0x0050fa20-0x0050fa84`: packet helper body after `0x0050f9c0`; no raw-start xrefs.
- `0x00511350-0x00511414`: raw packet/helper body before stubs; no raw-start xrefs.
- `0x005119b0-0x005119ef`: side-panel/timer body after a local switch table; no raw-start xrefs.
- `0x005119f0-0x00511ac2`: object lookup/update body; no raw-start xrefs.
- `0x00511ad0-0x00511b70`: object lookup/update/request body; no raw-start xrefs.
- `0x00511b70-0x00511c5b`: object state/update body; no raw-start xrefs.
- `0x00511c60-0x00511c8f`: object-list helper calling `sub_5060F0`; no raw-start xrefs.
- `0x00512cb0-0x00512d59`: raw body in the gap before `0x00512d60`; no raw-start xrefs.
- `0x00513680-0x00513780`: packet global/state helper with local switch table; no raw-start xrefs.
- `0x00513780-0x005137c2`: packet state toggle body; no raw-start xrefs.
- `0x005137d0-0x005137ff`: small packet/state body; no raw-start xrefs.
- `0x00513920-0x005139a4`: checksum/CRC response body using [UID:00027N], sends outbound opcode `0x45`; no raw-start xrefs.
- `0x005139b0-0x00513a1a`: side-panel/timer body using `byte_66DA97`, `dword_67A748+0x3eba`, and `sub_4B8650`; no raw-start xrefs.
- `0x00513d30-0x00513d94`: raw helper before `0x00513da0`; no raw-start xrefs.
- `0x005141d0-0x00514241`: timestamp echo/challenge body, sends outbound opcode `0x75`; no raw-start xrefs.
- `0x00514250-0x00514373`: `Mscfg.dll` payload/file-write body using `%s\Mscfg.dll`, `GetSystemDirectoryW`, `CreateFileW`, `WriteFile`, `SetFilePointer`, `SetEndOfFile`, and `CloseHandle`; no raw-start xrefs.

These bodies explain why the parent remains a large leaf even though it already has four children. They are source-bearing evidence, but the lack of raw-start xrefs prevents claiming live standalone methods. They should be exact evidence children or included in child packet-family pages with explicit `no IDA function/no xref` metadata.

### Local Switch Tables

The parent also contains table tails that must be carried with their owning modeled function or raw child:

- `0x00511998-0x005119b0`: jump table for the `0x00511710` neighborhood.
- `0x0051376c-0x00513780`: local jump table/tail for the `0x00513680` raw body.
- `0x00514090-0x005140a0`: local jump table/tail for `0x00513da0`.
- `0x005141b4-0x005141d0`: local jump table/tail for `0x005140a0`.

These are not separate final C++ emitters. They are compiler data owned by their switch-bearing helper pages.

## Existing Child Decisions

### [UID:0001AX] MapPaneDayNightPacketRawBody

Recommendation: keep as reconstructable evidence, owner/emitter [UID:0000L3], final C++ blank. Optional score update to `86/90` after supervisor records this B001 raw-start/pointer-scan evidence.

Reason: the retained body is exact and source-shaped, but it is unreferenced in the live binary and duplicates a dispatcher case. It should not become emitted standalone C++.

### [UID:0001AY] SelfSaveOKPaneFactory

Recommendation: keep current owner/emitter [UID:0000NN] and current reconstructable status. Do not move to MapPane.

Reason: no direct xrefs were found, but the pane-specific vtable/literal/timer behavior, SelfSaveOKPane class docs, and [UID:0001B0] companion page support SelfSaveOKPane ownership. MapPane is only the packet-created source route.

### [UID:0001AZ] FriendNameListSyncRawHandler

Recommendation: keep as reconstructable evidence, owner/emitter [UID:0000L3], final C++ blank. Optional score update to `86/90` after supervisor records this B001 raw-start/pointer-scan evidence.

Reason: the retained body is exact and source-shaped, but it is unreferenced in the live binary and duplicates dispatcher opcode `0x6a`. Source owner remains MapPane/protocol packet route, but final emitted code should come from the live dispatcher path.

### [UID:0001B0] SelfSaveOKPane

Recommendation: keep current owner/emitter [UID:0000NN], current reconstructable status, and exact range.

Reason: constructor/timer vtable evidence is pane-local. MapPane packet case `0x21` creates the pane but does not own its source.

## Recommended Child Inventory

These are recommended supervisor child-page creation targets. Placeholder UIDs are intentional; use the next available UID allocator rather than these literal IDs.

Scores below are proposed starting targets. If a child cannot reach the proposed gate after decompilation and support-doc linkage, create it at the lower supported score and keep [UID:0001AW] reconstructable until the gap is resolved.

| Placeholder | Range | Proposed title | Owner/emitter | Proposed score | Disposition |
|---|---:|---|---|---:|---|
| Batch-1 / [UID:0003TB] | `0x0050e4c0-0x0050e68d` | `MapPaneProcessMapEvent` | [UID:00007Q] | `86/89` | executable first-batch child if current UID registry still has next UID `0003TB`; otherwise use the actual next UID and adjust references |
| NEW-AW-02 | `0x0050e690-0x0050e805` | `MapPaneHitBarObjectEventHelper` | [UID:00007Q] | `85/87` | modeled function child; caller evidence limited |
| NEW-AW-03 | `0x0050e810-0x0050e848` | `MapPaneMarkerRefreshHelper` | [UID:00007Q] | `85/88` | modeled function child |
| NEW-AW-04 | `0x0050e850-0x0050ea2c` | `MapPaneObjectEffectSetupHelper` | [UID:00007Q] | `86/88` | modeled function child |
| NEW-AW-05 | `0x0050ea30-0x0050eb8a` | `MapPaneEffectObjectPaneFactory` | [UID:00007Q] | `86/88` | MapPane caller path; EffectObjectPane owns callee helper |
| NEW-AW-06 | `0x0050eb90-0x0050ec2e` | `MapPaneEffectObjectLookupHelper` | [UID:00007Q] | `85/88` | modeled function child |
| NEW-AW-07 | `0x0050ec30-0x0050edcf` | `MapPaneObjectPaneConstructionHelper` | [UID:00007Q] | `84/87` | modeled, no callers; needs behavior pass |
| NEW-AW-08 | `0x0050edd0-0x0050eef5` | `MapPanePacketObjectUpdateHelper` | [UID:00007Q] | `85/88` | modeled function child |
| NEW-AW-09 | `0x0050ef00-0x0050f029` | `MapPaneObjectPaneHelper` | [UID:00007Q] | `84/87` | modeled, no callers; needs behavior pass |
| NEW-AW-10 | `0x0050f030-0x0050f12f` | `MapPanePacketResponseHelper` | [UID:0000L3] | `85/87` | modeled helper |
| NEW-AW-11 | `0x0050f130-0x0050f26d` | `MapPanePacketResponseHelper2` | [UID:0000L3] | `85/87` | modeled helper |
| NEW-AW-12 | `0x0050f270-0x0050f3b2` | `MapPaneWorldMapPanePacketFactory` | [UID:00007Q] | `86/89` | MapPane route, WorldMapPane owns constructed class |
| NEW-AW-R01 | `0x0050f3c0-0x0050f454` | `MapPaneRawPacketSend05Body` | [UID:0000L3] | `85/88` | raw evidence child; no IDA function/xrefs |
| NEW-AW-R02 | `0x0050f460-0x0050f4c8` | `MapPaneRawMapRefreshRequestBody` | [UID:0000L3] | `85/88` | raw evidence child; no IDA function/xrefs |
| NEW-AW-13 | `0x0050f4d0-0x0050f52a` | `MapPanePacketSend43Helper` | [UID:0000L3] | `85/88` | modeled helper |
| NEW-AW-R03 | `0x0050f530-0x0050f581` | `MapPaneRawPacketBuilderA` | [UID:0000L3] | `84/87` | raw evidence child; needs full behavior pass |
| NEW-AW-R04 | `0x0050f590-0x0050f5dd` | `MapPaneRawPacketBuilderB` | [UID:0000L3] | `84/87` | raw evidence child; needs full behavior pass |
| NEW-AW-R05 | `0x0050f5e0-0x0050f615` | `MapPaneRawPacketBuilderC` | [UID:0000L3] | `84/87` | raw evidence child; needs full behavior pass |
| NEW-AW-R06 | `0x0050f620-0x0050f9b9` | `MapPaneRawUserFaceAssetPacketBody` | [UID:0000L3] | `86/90` | raw evidence child; path-string support exists |
| NEW-AW-14 | `0x0050f9c0-0x0050fa1b` | `MapPanePacketSendHelper` | [UID:0000L3] | `85/88` | modeled helper |
| NEW-AW-R07 | `0x0050fa20-0x0050fa84` | `MapPaneRawPacketHelper` | [UID:0000L3] | `84/87` | raw evidence child; needs behavior pass |
| NEW-AW-15 | `0x0050fa90-0x0050fafa` | `MapPanePacketHelper` | [UID:0000L3] | `85/87` | modeled helper |
| NEW-AW-16 | `0x0050fb00-0x0050feab` | `MapPanePacketTransitionHandler` | [UID:00007Q] | `86/88` | dispatcher-called |
| NEW-AW-17 | `0x0050feb0-0x00510230` | `MapPaneMapTransferPacketHandler` | [UID:00007Q] | `86/88` | dispatcher-called |
| NEW-AW-18 | `0x00510230-0x00510316` | `MapPaneTransferUiHelper` | [UID:0000L3] | `84/87` | modeled, no callers; needs behavior pass |
| NEW-AW-19 | `0x00510320-0x0051037f` | `MapPaneTransferUiHelper2` | [UID:0000L3] | `84/87` | modeled, no callers; needs behavior pass |
| NEW-AW-20 | `0x00510380-0x005103fd` | `MapPaneTransferUiHelper3` | [UID:0000L3] | `84/87` | modeled, no callers; needs behavior pass |
| existing | `0x00510400-0x005104c7` | `MapPaneDayNightPacketRawBody` | [UID:0000L3] | `86/90` optional | existing raw evidence child |
| NEW-AW-21 | `0x005104d0-0x00510958` | `MapPaneDayNightPacketHandler` | [UID:00007Q] | `86/90` | dispatcher-called; owns live emitted route |
| NEW-AW-22 | `0x00510960-0x00511347` | `MapPaneMapInfoPacketHandler` | [UID:00007Q] | `86/89` | dispatcher-called |
| NEW-AW-R08 | `0x00511350-0x00511414` | `MapPaneRawPacketHelperBeforeStubs` | [UID:0000L3] | `84/87` | raw evidence child; needs behavior pass |
| NEW-AW-23 | `0x00511420-0x00511425` | `MapPanePacketNoOpStubA` | [UID:0000L3] | `85/88` | modeled 5-byte stub |
| NEW-AW-24 | `0x00511430-0x00511435` | `MapPanePacketNoOpStubB` | [UID:0000L3] | `85/88` | modeled 5-byte stub |
| NEW-AW-25 | `0x00511440-0x00511703` | `MapPaneSpawnOrMovementPacketHandler` | [UID:00007Q] | `86/88` | dispatcher-called |
| NEW-AW-26 | `0x00511710-0x005119b0` | `MapPaneMovementPacketHandlerAndJumpTable` | [UID:00007Q] | `86/88` | modeled function plus jump table tail |
| NEW-AW-R09 | `0x005119b0-0x005119ef` | `MapPaneRawSidePanelTimerBody` | [UID:0000L3] | `85/88` | raw evidence child |
| NEW-AW-R10 | `0x005119f0-0x00511ac2` | `MapPaneRawObjectUpdateBodyA` | [UID:0000L3] | `85/88` | raw evidence child |
| NEW-AW-R11 | `0x00511ad0-0x00511b70` | `MapPaneRawObjectUpdateBodyB` | [UID:0000L3] | `85/88` | raw evidence child |
| NEW-AW-R12 | `0x00511b70-0x00511c5b` | `MapPaneRawObjectUpdateBodyC` | [UID:0000L3] | `85/88` | raw evidence child |
| NEW-AW-R13 | `0x00511c60-0x00511c8f` | `MapPaneRawObjectLookupBody` | [UID:0000L3] | `85/88` | raw evidence child |
| NEW-AW-27 | `0x00511c90-0x00511dae` | `MapPaneObjectMovePacketHandler` | [UID:00007Q] | `86/88` | dispatcher-called |
| NEW-AW-28 | `0x00511db0-0x0051283a` | `MapPaneObjectCreateAndWorldMapPacketHandler` | [UID:00007Q] | `86/89` | MapPane route; WorldMapPane remains separate owner |
| NEW-AW-29 | `0x00512840-0x0051289f` | `MapPaneUiFactoryHelperA` | [UID:0000L3] | `84/87` | modeled, no callers; needs behavior pass |
| NEW-AW-30 | `0x005128a0-0x005128fd` | `MapPaneUiFactoryHelperB` | [UID:0000L3] | `84/87` | modeled, generated name is pollution |
| NEW-AW-31 | `0x00512900-0x0051295d` | `MapPaneUiFactoryHelperC` | [UID:0000L3] | `84/87` | modeled, no callers; needs behavior pass |
| NEW-AW-32 | `0x00512960-0x00512ca4` | `MapPaneCombatOrActionPacketHandlerA` | [UID:00007Q] | `86/88` | dispatcher-called |
| NEW-AW-R14 | `0x00512cb0-0x00512d59` | `MapPaneRawCombatOrActionHelper` | [UID:0000L3] | `84/87` | raw evidence child; needs behavior pass |
| NEW-AW-33 | `0x00512d60-0x00512f1c` | `MapPaneCombatOrActionPacketHandlerB` | [UID:00007Q] | `86/88` | dispatcher-called |
| NEW-AW-34 | `0x00512f20-0x00513305` | `MapPaneCombatOrActionPacketHandlerC` | [UID:00007Q] | `86/88` | dispatcher-called |
| NEW-AW-35 | `0x00513310-0x0051367b` | `MapPaneStatusPacketHandler` | [UID:00007Q] | `86/88` | dispatcher-called |
| NEW-AW-R15 | `0x00513680-0x00513780` | `MapPaneRawGlobalStateSwitchBody` | [UID:0000L3] | `85/88` | raw evidence child with switch table |
| NEW-AW-R16 | `0x00513780-0x005137c2` | `MapPaneRawStateToggleBody` | [UID:0000L3] | `85/88` | raw evidence child |
| NEW-AW-R17 | `0x005137d0-0x005137ff` | `MapPaneRawSmallStateBody` | [UID:0000L3] | `84/87` | raw evidence child; needs behavior pass |
| existing | `0x00513800-0x00513920` | `SelfSaveOKPaneFactory` | [UID:0000NN] | current | existing child |
| NEW-AW-R18 | `0x00513920-0x005139a4` | `MapPaneRawChecksumResponseBody` | [UID:0000L3] | `86/90` | raw evidence child; checksum table support exists |
| NEW-AW-R19 | `0x005139b0-0x00513a1a` | `MapPaneRawPanelTimerBody` | [UID:0000L3] | `85/88` | raw evidence child |
| NEW-AW-36 | `0x00513a20-0x00513aa6` | `MapPaneDialogFactoryHelperA` | pending direct pane owner | `84/87` | modeled, no callers; source owner unresolved |
| NEW-AW-37 | `0x00513ab0-0x00513b49` | `MapPaneDialogFactoryHelperB` | pending direct pane owner | `84/87` | modeled, no callers; source owner unresolved |
| NEW-AW-38 | `0x00513b50-0x00513bab` | `PowerDialogPaneFactoryHelper` | likely pane owner, not MapPane | `84/87` | modeled, no callers; needs pane support doc check |
| NEW-AW-39 | `0x00513bb0-0x00513c20` | `MapPaneDialogFactoryHelperC` | pending direct pane owner | `84/87` | modeled, no callers; source owner unresolved |
| NEW-AW-40 | `0x00513c20-0x00513c84` | `MapPaneDialogFactoryHelperD` | pending direct pane owner | `84/87` | modeled, no callers; source owner unresolved |
| NEW-AW-41 | `0x00513c90-0x00513d1f` | `MapPaneChallengePacketHandler` | [UID:00007Q] | `86/88` | dispatcher-called |
| NEW-AW-42 | `0x00513d20-0x00513d25` | `MapPanePacketNoOpStubC` | [UID:0000L3] | `85/88` | modeled 5-byte stub |
| NEW-AW-R20 | `0x00513d30-0x00513d94` | `MapPaneRawChallengeHelper` | [UID:0000L3] | `84/87` | raw evidence child; needs behavior pass |
| NEW-AW-43 | `0x00513da0-0x005140a0` | `MapPaneAlertPacketHandlerAndJumpTable` | [UID:00007Q] | `86/88` | modeled function plus switch table tail |
| NEW-AW-44 | `0x005140a0-0x005141d0` | `MapPaneTimerPanePacketFactoryAndJumpTable` | likely TimerPane source owner for factory body | `84/87` | modeled, no direct caller; table tail included |
| NEW-AW-R21 | `0x005141d0-0x00514241` | `MapPaneRawTimestampEchoBody` | [UID:0000L3] | `86/90` | raw evidence child; opcode support exists |
| NEW-AW-R22 | `0x00514250-0x00514373` | `MapPaneRawMscfgDllPayloadBody` | [UID:0000L3] | `86/90` | raw evidence child; string/API support exists |
| existing | `0x00514380-0x005143b7` | `FriendNameListSyncRawHandler` | [UID:0000L3] | `86/90` optional | existing raw evidence child |
| NEW-AW-45 | `0x005143c0-0x0051447c` | `PhotoPaneFactoryHelper` | likely PhotoPane owner | `84/87` | modeled, no callers; source owner unresolved |
| NEW-AW-46 | `0x00514480-0x00514579` | `CollectionDialogPaneFactoryHelper` | likely direct pane owner | `84/87` | modeled, no callers; calls `0x00514640` |
| NEW-AW-47 | `0x00514580-0x00514636` | `EmployeeDialogPaneFactoryHelper` | likely direct pane owner | `84/87` | modeled, no callers; source owner unresolved |
| NEW-AW-48 | `0x00514640-0x005147cb` | `MapPanePacketDialogRouteHelper` | [UID:00007Q] or [UID:0000L3] | `86/88` | dispatcher-called and factory-called |
| existing | `0x005147d0-0x00514914` | `SelfSaveOKPane` | [UID:0000NN] | current | existing child |

The children listed at `84/87` should not be used to reclassify the parent until their decompilation, caller/callee route, and direct class/file ownership are raised to a defensible 85/85+ state. The table records where further A/B follow-up is required instead of overstating confidence.

## Rejected Alternatives

### Keep [UID:0001AW] as a final reconstructable aggregate

Rejected. It remains the source carrier only because exact children do not exist yet. A single final C++ body cannot represent the range cleanly: it contains dispatcher callees, object/effect helpers, no-op stubs, UI factory helpers, raw duplicate bodies, raw no-xref packet bodies, switch-table data, SelfSaveOKPane children, and a successor boundary before MapRefreshDimmer.

### Reclassify [UID:0001AW] immediately as non-emitting

Rejected for now. The memory report proves two large childless reconstructable leaves remain. Immediate reclassification would hide source-bearing bytes and leave many functions without child pages.

### Move SelfSaveOKPane children to MapPane

Rejected. MapPane packet logic creates or routes to SelfSaveOKPane, but the constructor/timer/factory evidence is pane-local. Keep [UID:0001AY] and [UID:0001B0] with [UID:0000NN].

### Move WorldMapPane construction into MapPane

Rejected. `0x0050f270` and `0x00511db0` are MapPane packet routes that call WorldMapPane construction. [UID:0000PB] owns the WorldMapPane implementation.

### Treat raw bodies as dead data and remove reconstructability

Rejected. The raw bodies are executable, source-shaped, and behaviorally meaningful. The correct classification is "retained raw evidence, no proven live standalone route", not padding/data/non-code.

### Repair IDA by defining raw functions

Rejected. No raw-start xrefs, pointer hits, or safe branch routes were found. Creating IDA functions would obscure the no-function evidence and may mislead later function-boundary automation. Leave IDA untouched.

## Remaining Blockers and Evidence Checked

Packet enum/source names:

- Checked [UID:0001SO] and live dispatcher xrefs. Several opcodes have documented behavior (`0x20`, `0x21`, `0x2e`, `0x3b`, `0x4a`, `0x67`, `0x68`, `0x6a`), but many helper names remain behavior-derived rather than source-proven.
- Safe resolution: use descriptive provisional titles in child pages; do not write final C++ names for the parent.

Raw body liveness:

- Checked IDA `lookup_funcs`, `xrefs_to`, raw PE VA/RVA pointer scans, and rel32 scans.
- Result: raw starts remain no-function/no-xref. The build/source reason cannot be proven from the binary. Best safe classification is retained raw evidence or duplicate source-shaped bodies with blank final C++.

UI factory ownership:

- Checked modeled callee profiles and support-doc routes for SelfSaveOKPane, WorldMapPane, PhotoPane, PowerDialogPane, CollectionDialogPane, TimerPane, and dialog-like constructors.
- Result: SelfSaveOKPane and WorldMapPane are safely routed. Several no-caller factory helpers near `0x00513a20-0x00514640` need direct pane support-page checks before assigning final owner/emitter.

Switch tables:

- Checked raw byte boundaries and instruction listings around `0x00511998`, `0x0051376c`, `0x00514090`, and `0x005141b4`.
- Result: these are compiler table tails owned by adjacent switch-bearing child pages, not independent emitters.

MapRefreshDimmer successor:

- Checked successor docs [UID:0001B1] and current coverage row. `0x00514920` is the correct successor start; no merge or range expansion is recommended.

Final C++ eligibility:

- Checked parent final C++ block and child/source coverage. Parent remains blank and should stay blank. Exact child pages can eventually carry final C++ after decompilation and source-quality gates, but [UID:0001AW] should not.

## Exact Supervisor Actions

1. Do not edit IDA DB for this assignment.

2. Create exact child pages in batches rather than one large manual pass:
   - Batch A: dispatcher-called MapPane handlers and the live day/night handler.
   - Batch B: raw no-function packet bodies with strongest support (`0x0050f620`, `0x00513920`, `0x005141d0`, `0x00514250`).
   - Batch C: object/effect helper methods.
   - Batch D: no-caller UI factory helpers, after direct pane support-doc review.
   - Batch E: remaining raw bodies and stubs.

3. For every new raw child page, include these evidence bullets:
   - exact byte/range endpoint;
   - `lookup_funcs` shows no IDA function at the raw start;
   - `xrefs_to` count is zero;
   - local PE VA/RVA/rel32 scans found no credible pointer/call route;
   - final C++ blank unless a later pass proves a live source route.

4. Update [UID:0001AW] only after all source-bearing child pages validate:
   - `COMPLETION:88`
   - `CONFIDENCE:91`
   - `RECONSTRUCTABLE:FALSE`
   - blank `EMITTER_UIDS`
   - keep `CANONICAL_OWNER:00007Q`
   - rewrite summary as a non-emitting split index over MapPane packet handlers, raw retained bodies, SelfSaveOKPane children, and adjacent pane factory routes.

5. Optional child-page score updates after recording this B001 evidence:
   - [UID:0001AX] from `84/88` to `86/90`, still reconstructable evidence, final C++ blank.
   - [UID:0001AZ] from `84/88` to `86/90`, still reconstructable evidence, final C++ blank.

6. Keep [UID:0001AY] and [UID:0001B0] unchanged except for optional back-link notes from [UID:0001AW].

7. Update support docs after child creation:
   - [UID:00007Q] `by-class/MapPane.md`: add the exact packet-handler child inventory and state that [UID:0001AW] is a non-emitting split index after split completion.
   - [UID:0000L3] `by-file/MapPane.md`: add the same source-family routing and raw-body policy.
   - [UID:0001SO] `by-type/by-enum/MapServerPacketOpcode.md`: add or cross-link child pages for opcode-backed helpers where opcode evidence is known.
   - [UID:0000NN]/SelfSaveOKPane docs: keep [UID:0001AY]/[UID:0001B0] ownership and note MapPane packet-created route only.
   - WorldMapPane docs: keep constructor ownership and note MapPane packet factory callers only if not already present.

## Coverage Report Text

Do not apply this shared row change until child pages have been created and validated. Placement: replace the current [UID:0001AW] row block under [UID:000232] and before [UID:0001B1] in `by-memory/-coverage-report.md`.

Parent row after completed split:

```md
    - [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) 0x0050e4c0-0x00514920 | source-family split index | MapPanePacketHandlers : not_reconstructable : 88% : strong : Non-emitting MapPane packet/source-family index after exact child split; covers dispatcher-called MapPane handlers, object/effect helper routes, retained raw no-function packet bodies, switch-table tails, SelfSaveOKPane child islands, and pane-factory boundary notes. Final C++ remains blank; source emission belongs to exact children or direct class owners.
```

Existing child row replacement text if optional raw-child score updates are accepted:

```md
        - [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md) 0x00510400-0x005104c7 | raw duplicate packet-handler body | MapPaneDayNightPacketRawBody : reconstructable : 86% : strong : Retained raw MapPane opcode `0x20` day/night body; live IDA and raw PE scans confirm no modeled function, exact `retn 4` endpoint and padding, no raw-start xrefs/callers/VA/RVA/rel32 pointer route, dispatcher case `32` equivalence, day/night table and apply-helper xrefs, touched MapPane lighting/fade fields, MapPane parent, and blank final C++ because emitted source belongs to the live dispatcher route.
        - [UID:0001AZ][0x00514380-0x005143b7.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143b7.FriendNameListSyncRawHandler.md) 0x00514380-0x005143b7 | retained raw duplicate | FriendNameListSyncRawHandler : reconstructable : 86% : strong : Retained raw duplicate of the live `MapPane::HandlePacket` opcode `0x6a` friend/name-list sync body; live IDA and raw PE scans confirm exact raw bytes, flag/send-helper xrefs, modeled caller contrast, no raw-start xrefs/callers/VA/RVA/rel32 pointer route, and blank final C++ because emitted source belongs to the live dispatcher route.
```

For newly created children, insert rows as nested children under [UID:0001AW] in ascending address order using the exact child inventory above. Use assigned UIDs, not the placeholder IDs. Do not replace [UID:0001AW] with the non-reconstructable parent row until those child rows cover the two current large reconstructable leaves.

## Validation Order

1. Create/update child pages in ascending address order.
2. Run the project documentation validator for touched by-memory/by-class/by-file/by-type pages.
3. Run `memory_ranges.py report`.
4. Confirm:
   - no barrier/general/filename/advanced errors;
   - [UID:0001AW] no longer appears as broad reconstructable largest leaves;
   - all new child pages meet their stated scores or remain explicitly below gate with parent still reconstructable;
   - [UID:0001B1] still begins at `0x00514920`;
   - [UID:0001AY] and [UID:0001B0] remain SelfSaveOKPane-owned.
5. Only after the child set validates, apply the [UID:0001AW] non-emitting split-index metadata and coverage-row replacement.

## Direct Edit Confirmation

No target/support docs, generated reports, IDA database state, or `by-memory/-coverage-report.md` were edited by Agent-B001 for this assignment. This report is the only file created.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001AW-mappane-packet-source-split-audit.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001AW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
