** TARGET-REPORT-UID:0001AW **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001AW MapPane Packet Source Split Continuation Batch4

Assignment: `B001-goal2-memory-tool-mappane-packet-source-split-continuation4-0001AW-20260616`  
Agent: B001  
Target: [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](../../../../../by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)

## Final Recommendation

Create one executable direct-evidence child now:

- [UID:0003TH] `0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay.md`, `86/90`, owner/emitter [UID:00007Q][MapPane](../../../../../by-class/MapPane.md).
- Add the trailing ignored padding row `0x0050eef5-0x0050ef00`.
- Keep [UID:0001AW] `RECONSTRUCTABLE:TRUE`, `85/88`, owner/emitter [UID:00007Q]. Do not reclassify the parent yet.

Do not create children in this batch for `0x0050ec30-0x0050edd0` or `0x0050ef00-0x0050f029`. Both are well-formed object-overlay construction bodies, but IDA and raw PE scans show no direct callers, no absolute VA/RVA pointer hits, and no relative branch/call hits to either start. They remain roadmap-only retained-helper/source-placement questions instead of being forced into supervisor-created below-confidence pages.

Do not include `0x0050f030-0x0050f130` or later static-object/tile helpers in this batch. `0x0050f030` has a direct caller from `0x0050f130`, but it starts a different StaticObjectPane/tile refresh flow and needs its own bounded pass for source names and field/global routing.

No direct by-* docs, generated reports, IDA DB, or `by-memory/-coverage-report.md` were edited by B001.

## Current State Checked

- Parent [UID:0001AW] currently remains `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, with blank final C++.
- Executed prior batches already created [UID:0003TB], [UID:0003TC], [UID:0003TD], [UID:0003TE], [UID:0003TF], and [UID:0003TG], plus padding through `0x0050ec30`.
- `by-memory/-coverage-report.md` currently places [UID:0003TG] at `0x0050eb90-0x0050ec2e`, ignored padding `0x0050ec2e-0x0050ec30`, then jumps to [UID:0001AX] at `0x00510400-0x005104c7`.
- Supervisor notes say `memory_ranges.py report` is clean for Barrier Crossings, General Errors, Filename Errors, and Advanced-Error-Scan after batch3, with [UID:0001AW] still carrying a broad leaf `0x005104c7-0x00513800`.
- UID allocation assumption: supervisor notes show latest allocated MapPane packet child is [UID:0003TG]. If no intervening UID allocation occurred, the next UID for this batch is [UID:0003TH].

## Evidence Checked

### Live IDA MCP

Session: `b001_mappane_0001AW_20260616`, database `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

Function inventory for the immediate post-batch3 span:

| Start | IDA name | Size | Result |
|---|---|---:|---|
| `0x0050ec30` | `sub_50EC30` | `0x1a0` | SoundObjectPane construction helper-shaped body; no direct IDA callers/xrefs. |
| `0x0050edd0` | `sub_50EDD0` | `0x125` | Live HitBarObjectPane event-overlay helper; direct calls from `0x00512b96` and `0x00512c7f`. |
| `0x0050ef00` | `sub_50EF00` | `0x129` | DamageNumberObjectPane construction helper-shaped body; no direct IDA callers/xrefs. |
| `0x0050f030` | `sub_50F030` | `0x100` | StaticObjectPane/tile helper; direct caller `sub_50F130` at `0x0050f1f8`. |
| `0x0050f130` | `sub_50F130` | `0x13d` | Tile/object refresh loop; callers `sub_5059D0`, `sub_50BCE0`, and `sub_510960`. |

Important function details:

- `analyze_function(0x0050edd0)` reports prototype `void __thiscall(void *this, int, __int16, __int16)`, size `0x125`, callers `sub_512960`, xrefs-to `0x00512b96` and `0x00512c7f`, and callees `sub_538D50`, `PoolAllocator_Allocate`, `sub_5374D0`, `sub_53AE70`, `sub_5314A0`, `sub_597910`, and `sub_4B8E00`.
- The `0x0050edd0` decompilation resolves the target object's coordinates, checks the target's `+0x178`/index-94 overlay state, allocates a `HitBarObjectPane`, calls constructor `0x00538d50` with a final style flag selected from the overlay state, attaches it, inserts/registers it, schedules the timer subobject with `500`, invokes a virtual refresh slot, then refreshes bounds.
- `analyze_function(0x00512960)` reports caller `sub_507C90`, direct callees including `sub_50EDD0`, `sub_539230`, `sub_53AE80`, `sub_597910`, packet readers, and object-list lookup helpers. This pins `0x0050edd0` to the live combat/status packet path while also showing that DamageNumberObjectPane construction is inlined/direct in the same handler rather than routed through `0x0050ef00`.
- `analyze_function(0x0050ec30)` reports size `0x1a0`, no callers, no xrefs-to, and callees `PoolAllocator_Allocate`, `sub_53CA20`, `sub_53CB50`, `sub_5374D0`, `sub_5376D0`, and `sub_5314A0`. It is real SoundObjectPane construction behavior, but not direct-call live evidence.
- `analyze_function(0x00512f20)` reports a live sound packet handler called by `sub_507C90`; it directly calls `sub_53CA20`/`sub_53CB50` and sibling sound helpers rather than calling `0x0050ec30`. This reinforces that `0x0050ec30` may be a retained duplicate/static helper and should not be supervisor-created in this batch.
- `analyze_function(0x0050ef00)` reports size `0x129`, no callers, no xrefs-to, and callees `PoolAllocator_Allocate`, `sub_539230`, `sub_53AE80`, `sub_5314A0`, `sub_597910`, and `sub_4B8E00`. It is real DamageNumberObjectPane construction behavior, but not direct-call live evidence.
- `analyze_function(0x0050f030)` reports caller `sub_50F130`, direct callees including `sub_537900`, `sub_506980`, `sub_50A940`, `sub_4DD850`, `sub_4DDA30`, and pool allocation. This is a separate StaticObjectPane/tile helper flow and should be the next follow-up rather than part of this HitBar batch.

Padding signatures:

- `make_signature_for_range(0x0050eef5, 0x0050ef00, wildcard_operands=false)` returns eleven `CC` bytes.
- `make_signature_for_range(0x0050f029, 0x0050f030, wildcard_operands=false)` returns seven `CC` bytes.
- `make_signature_for_range(0x0050f26d, 0x0050f270, wildcard_operands=false)` returns three `CC` bytes.

### Raw PE Scan

Local PE scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`, scanned absolute VA dwords, RVA dwords, and `E8`/`E9` rel32 call/jump encodings to candidate starts:

| Target | Absolute VA hits | RVA hits | Relative call/jump hits |
|---|---:|---:|---|
| `0x0050ec30` | 0 | 0 | 0 |
| `0x0050edd0` | 0 | 0 | 2: calls at `0x00512b96`, `0x00512c7f` |
| `0x0050ef00` | 0 | 0 | 0 |
| `0x0050f030` | 0 | 0 | 1: call at `0x0050f1f8` |

This resolves the reachability split for batch4: `0x0050edd0` is executable direct-call evidence; `0x0050ec30` and `0x0050ef00` remain retained helper-body evidence with unresolved liveness/source placement.

### Support Docs

Checked support pages:

- [UID:00007Q][MapPane](../../../../../by-class/MapPane.md) and [UID:0000L3][MapPane](../../../../../by-file/MapPane.md) already list prior packet/effect children through [UID:0003TG] and keep MapPane as the source owner for packet/object-event routing helpers.
- [UID:000067][HitBarObjectPane](../../../../../by-class/HitBarObjectPane.md) documents constructor callers in MapPane hit/damage paths, including `0x0050edd0`, and keeps HitBarObjectPane as the overlay class owner rather than the packet-helper owner.
- [UID:00003F][DamageNumberObjectPane](../../../../../by-class/DamageNumberObjectPane.md) documents constructor callers in `0x0050ef00` and `0x00512960`; this supports behavior but not direct reachability for `0x0050ef00`.
- [UID:0000DH][SoundObjectPane](../../../../../by-class/SoundObjectPane.md) and [UID:0000NW][SoundObjectPane](../../../../../by-file/SoundObjectPane.md) document `0x0050ec30` and `0x00512f20` as constructor-call contexts; this supports behavior but not direct reachability for `0x0050ec30`.
- Static pool docs for SoundObjectPane, HitBarObjectPane, and DamageNumberObjectPane record direct allocation xrefs from these helper bodies. Pool ownership stays with the constructed overlay classes; packet/source-routing ownership stays with MapPane only when direct routing evidence is strong enough.
- [UID:0001B3][0x00514ae0-0x00514d1e.ObjectPanePoolFreeUnwindWrappers](../../../../../by-memory/0x00514ae0-0x00514d1e.ObjectPanePoolFreeUnwindWrappers.md) already records EH/pool-free refs from `0x0050ec30`, `0x0050edd0`, `0x0050ef00`, and `0x0050f030`, confirming constructor-failure wrapper linkage but not changing ownership.

## Rejected Alternatives

- Reclassify [UID:0001AW] now: rejected. The parent still has large source-bearing leaves, especially `0x005104c7-0x00513800`, and roadmap-only helper bodies before `0x00510400`. It must remain reconstructable and source-bearing until enough exact children cover the remaining methods.
- Create a `0x0050ec30` SoundObjectPane helper child now: rejected for this executable batch. The body is real and documented, but IDA has no callers/xrefs, the raw PE scan found no branch or pointer hits, and the live `0x00512f20` sound packet handler performs the SoundObjectPane construction inline/directly. Source placement could be MapPane static helper, SoundObjectPane factory/helper, or retained duplicate; not safe for a new 85/85+ child yet.
- Create a `0x0050ef00` DamageNumberObjectPane helper child now: rejected for this executable batch. The body is real and documented, but IDA has no callers/xrefs, the raw PE scan found no branch or pointer hits, and the live `0x00512960` handler directly constructs DamageNumberObjectPane. Source placement could be MapPane retained helper or dead duplicate; not safe for a new 85/85+ child yet.
- Put `0x0050edd0` under HitBarObjectPane/AttachedObjectPane: rejected. HitBarObjectPane owns constructor `0x00538d50`, pool storage, vtables, rendering, and destructor behavior. The `0x0050edd0` body is the MapPane packet-side decision that resolves a target object, selects a style flag, constructs/registers the overlay, and schedules its timer.
- Include `0x0050f030` now: rejected for scope. It has direct-call evidence, but it is a StaticObjectPane/tile creation/update flow with different source dependencies and should be the next bounded split pass.

## Executable Supervisor Batch

### Create Child Page [UID:0003TH]

Create:

`by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay.md`

With exact content:

```markdown
*** UID:0003TH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0050edd0-0x0050eef5 MapPane Create HitBarObjectPane Event Overlay

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact MapPane private packet/object-event helper child split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Direct owner/emitter: [UID:00007Q][MapPane](by-class/MapPane.md); file owner [UID:0000L3][MapPane](by-file/MapPane.md).
- Working source name: `MapPaneCreateHitBarObjectPaneEventOverlay`.
- Confidence: strong for exact range, live callers, HitBarObjectPane allocation/construction path, MapPane object/list insertion, timer scheduling, ownership, and padding; medium-high for final packet/field/helper names.
- Reconstruction note: C++ intentionally blank. The final source names for the packet values, target-object overlay state at offset `+0x178`, object-list insertion helper, timer subobject, and bounds-refresh helpers still need final naming.

## Address Range

- Start: `0x0050edd0`
- End: `0x0050eef5` end-exclusive
- IDA function: `sub_50EDD0`
- IDA size: `0x125` bytes
- Preceded by roadmap-only retained helper body `sub_50EC30` at `0x0050ec30-0x0050edd0`; that body is not split in this batch because no direct caller or raw branch/pointer hit reaches its start.
- Followed by ignored padding `0x0050eef5-0x0050ef00` before roadmap-only retained helper body `sub_50EF00`.

## Behavior

This helper creates and registers a `HitBarObjectPane` from a live MapPane combat/status packet path:

- exits without side effects when the target object pointer is null;
- resolves target-relative coordinates through `0x005374d0`;
- checks target-object overlay/link state at offset `+0x178` / index `94`;
- allocates from the `HitBarObjectPane` pool;
- calls `HitBarObjectPane` constructor `0x00538d50` with a final style/attachment flag selected from the target overlay state;
- attaches the new overlay through `0x0053ae70`;
- inserts/registers it through MapPane object/list state via `0x005314a0`;
- schedules the embedded timer subobject through `0x00597910` with a `500` delay;
- invokes the overlay virtual refresh slot at vtable offset `+0x70`;
- refreshes bounds through `0x004b8e00` and the overlay virtual bounds setter at vtable offset `+0x20`.

## IDA MCP Evidence

- B001 live IDA MCP session `b001_mappane_0001AW_20260616` reports `sub_50EDD0` at `0x0050edd0`, size `0x125`, 14 basic blocks, cyclomatic complexity 2.
- `analyze_function(0x0050edd0)` reports prototype `void __thiscall(void *this, int, __int16, __int16)`.
- `xrefs_to` reports direct call sites at `0x00512b96` and `0x00512c7f`, both inside `sub_512960`.
- Raw PE scan of `NexusTK.exe` confirms two `E8` rel32 calls to `0x0050edd0` at `0x00512b96` and `0x00512c7f`; no absolute VA or RVA pointer hits were found.
- `analyze_function(0x00512960)` reports caller `sub_507C90` and confirms this packet handler directly calls `sub_50EDD0` while also handling related overlay/damage-number construction work.
- Direct callees are `sub_538D50`, `sub_5314A0`, `sub_5374D0`, `PoolAllocator_Allocate`, `@__security_check_cookie@4`, `sub_4B8E00`, `sub_53AE70`, and `sub_597910`.
- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md) records constructor callers in MapPane damage/hit event handlers around `0x0050e4c0`, `0x0050e690`, and `0x0050edd0`.
- [UID:0002WP][0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage](by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md) records allocation xrefs from `0x0050e4c0`, `0x0050e690`, and `0x0050edd0`.
- B001 byte-signature review confirms the following `0x0050eef5-0x0050ef00` bytes are eleven `0xcc` padding bytes, not part of this child.

## Ownership Decision

This body belongs to MapPane because it is the packet-side helper that decides when and how to create, attach, register, schedule, and refresh a `HitBarObjectPane` for a target object in a MapPane combat/status packet flow. `HitBarObjectPane` owns the constructed class behavior, vtables, pool, constructor, rendering, and destructor; MapPane owns this source-level routing helper.

## Rejected Owners

- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md): constructed overlay class, not the packet-side creation policy.
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md): owns the attached overlay class family, not the MapPane event packet route.
- TimerMgr support pages: generic timer queue utility only.
- [UID:00009Q][ObjectList](by-class/ObjectList.md): object/list dependency only.

## Score Rationale

Completion is `86` because exact range, live callers, raw PE relative-call hits, allocation/construction path, target attachment, MapPane registration, timer scheduling, owner decision, rejected owners, and trailing padding are documented. Confidence is `90` because direct call and support-doc evidence triangulate the behavior; confidence stays below final-source quality because packet field names, target-overlay field names, and original helper spelling remain provisional.

## Cross-References

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md)
- [UID:0002WP][0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage](by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md)
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation batch4 recommendation: create this exact child from the remaining [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) broad leaf. Parent remains reconstructable because later source-bearing leaves and retained no-caller helper bodies remain unsplit.
```

### Parent [UID:0001AW] Edits

Do not change [UID:0001AW] metadata. Keep:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

In the parent exact child table, insert after [UID:0003TG] and before [UID:0001AX]:

```markdown
| [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay](by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay.md) | Exact modeled MapPane private combat/status overlay helper that constructs/registers a `HitBarObjectPane` from the live `sub_512960` packet path. |
```

In `## Current Exact Boundary Inventory`, replace the existing `0x0050edd0` row and add the neighboring roadmap-only rows so the sequence reads:

```markdown
| `0x0050ec30` | `sub_50EC30` | `0x1a0` | Roadmap-only retained SoundObjectPane construction helper evidence. Live IDA reports no direct callers/xrefs, raw PE scan found no absolute VA/RVA/relative branch hits to the start, and live sound packet handler `0x00512f20` constructs SoundObjectPane directly, so no batch4 child is recommended. |
| `0x0050edd0` | `sub_50EDD0` | `0x125` | Exact child [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay](by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay.md); live MapPane combat/status packet helper called from `0x00512b96` and `0x00512c7f`, constructing/registering a `HitBarObjectPane`. |
| `0x0050ef00` | `sub_50EF00` | `0x129` | Roadmap-only retained DamageNumberObjectPane construction helper evidence. Live IDA reports no direct callers/xrefs, raw PE scan found no absolute VA/RVA/relative branch hits to the start, and live combat/status handler `0x00512960` constructs DamageNumberObjectPane directly, so no batch4 child is recommended. |
```

Leave the existing `0x0050f030` row in place for now, or optionally update its description to:

```markdown
| `0x0050f030` | `sub_50F030` | `0x100` | Roadmap-only StaticObjectPane/tile helper with direct caller `sub_50F130` at `0x0050f1f8`; source names and field/global routing require a separate bounded split pass. |
```

Append to the parent evidence/history near the existing batch3 evidence:

```markdown
- 2026-06-16 B001 continuation batch4 live IDA MCP session `b001_mappane_0001AW_20260616`: `analyze_function(0x0050edd0)` reports `sub_50EDD0` size `0x125`, direct calls from `sub_512960` at `0x00512b96` and `0x00512c7f`, callees `sub_538D50`, `sub_53AE70`, `sub_5314A0`, `sub_597910`, and `sub_4B8E00`, and HitBarObjectPane allocation/attachment/timer/bounds behavior. A raw PE scan confirms the two relative calls and no VA/RVA pointer hits. The same pass checked `0x0050ec30` and `0x0050ef00`; both are modeled object-construction bodies with support-doc evidence but no direct callers/xrefs and no raw PE branch/pointer hits, so they remain roadmap-only retained-helper/source-placement questions. `make_signature_for_range` confirms `0x0050eef5-0x0050ef00` as eleven `0xcc` bytes.
```

Append to the parent Cross-References list after [UID:0003TG]:

```markdown
- [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay](by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay.md)
```

Append to the parent Changes section:

```markdown
- 2026-06-16 B001 continuation split batch4: create exact child [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay](by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay.md) plus ignored padding `0x0050eef5-0x0050ef00`. Parent [UID:0001AW] remains `RECONSTRUCTABLE:TRUE`, `85/88`, and owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md) because `0x0050ec30`, `0x0050ef00`, `0x0050f030`, and later broad packet leaves still need exact split/source-placement work.
```

### Support Doc Edits

No support doc score or metadata changes are recommended.

In [UID:00007Q][MapPane](../../../../../by-class/MapPane.md), insert this Cross-References line after [UID:0003TG]:

```markdown
- [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay](by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay.md)
```

In [UID:00007Q][MapPane](../../../../../by-class/MapPane.md), append this Changes entry above the existing batch3 entry:

```markdown
- 2026-06-16 B001 continuation split batch4:
  - Score unchanged at `85/85`.
  - Added exact MapPane packet/object-event child [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay](by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay.md). The child documents the live combat/status packet route that constructs/registers a `HitBarObjectPane`; HitBarObjectPane and AttachedObjectPane remain the constructed-overlay class/file owners rather than owners of this MapPane packet helper.
```

In [UID:0000L3][MapPane](../../../../../by-file/MapPane.md), insert this Cross-References line after [UID:0003TG]:

```markdown
- [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay](by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay.md)
```

In [UID:0000L3][MapPane](../../../../../by-file/MapPane.md), append this Changes entry above the existing batch3 entry:

```markdown
- 2026-06-16 B001 continuation split batch4:
  - Score unchanged at `89/85`.
  - Added exact child [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay](by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay.md) under the MapPane packet/object-event family. `HitBarObjectPane`, `AttachedObjectPane`, TimerMgr, and ObjectList remain callee/constructed-object/support owners rather than owners of this MapPane method.
```

No changes are needed to `HitBarObjectPane`, `AttachedObjectPane`, `SoundObjectPane`, `DamageNumberObjectPane`, or the static pool docs in this batch. They already record the relevant constructor/pool evidence, and changing their scores or ownership would overstate what this MapPane child split proves.

### by-memory/-coverage-report.md Rows

Do not edit `by-memory/-coverage-report.md` directly as B001. Use this existing row as placement context only; do not duplicate it:

```markdown
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050ec2e-0x0050ec30 | padding | MapPaneApplyEffectObjectPaneTimerAction to next MapPane helper alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows two `0xcc` bytes after `sub_50EB90` end-exclusive `0x0050ec2e` and before next modeled function `sub_50EC30` starts at `0x0050ec30`.
```

Insert the following two rows immediately after that existing context row and before the existing [UID:0001AX] row:

```markdown
        - [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay](by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPaneEventOverlay.md) 0x0050edd0-0x0050eef5 | class method/private helper | MapPaneCreateHitBarObjectPaneEventOverlay : reconstructable : 86% : strong : Exact modeled `sub_50EDD0` child split from MapPanePacketHandlers; live IDA and raw PE confirm two direct calls from `sub_512960` at `0x00512b96` and `0x00512c7f`; helper resolves target coordinates, allocates/constructs a `HitBarObjectPane`, attaches it to the target, inserts it into MapPane object/list state, schedules the overlay timer, and refreshes bounds. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); HitBarObjectPane owns the constructed overlay class/pool/constructor. Final C++ blank pending final packet/field/helper names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050eef5-0x0050ef00 | padding | MapPaneCreateHitBarObjectPaneEventOverlay to retained DamageNumberObjectPane helper alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows eleven `0xcc` bytes after `sub_50EDD0` end-exclusive `0x0050eef5` and before modeled function `sub_50EF00` starts at `0x0050ef00`.
```

Parent [UID:0001AW] row remains unchanged.

### IDA DB Recommendation

No IDA DB edits are recommended. IDA already has correct function boundaries for `sub_50EDD0`; missing direct callers for `0x0050ec30` and `0x0050ef00` should not be repaired manually without a real branch/pointer target.

### Validation Order

Supervisor validation order after applying the batch:

1. Create [UID:0003TH] page exactly as above.
2. Apply [UID:0001AW] parent child-table, boundary-inventory, evidence, cross-ref, and Changes additions.
3. Apply MapPane class/file cross-ref and Changes additions.
4. Insert the two coverage rows under [UID:0001AW] after the existing `0x0050ec2e-0x0050ec30` padding row and before [UID:0001AX].
5. Run the by-memory validator for the new child and parent/support pages.
6. Run `memory_ranges.py report` and confirm Barrier Crossings, General Errors, Filename Errors, and Advanced-Error-Scan remain `None`.
7. Confirm [UID:0001AW] still remains `RECONSTRUCTABLE:TRUE`, `85/88`, owner/emitter [UID:00007Q].

## Remaining Blockers and Next Follow-Up

- `0x0050ec30-0x0050edd0`: investigated with IDA function analysis, raw PE branch/pointer scan, SoundObjectPane support docs, static pool docs, and live `0x00512f20` sibling handler. It cannot be safely resolved as a MapPane child, SoundObjectPane helper, or dead duplicate yet because no code/pointer route reaches the function start while the body is valid retained SoundObjectPane construction code.
- `0x0050ef00-0x0050f029`: investigated with IDA function analysis, raw PE branch/pointer scan, DamageNumberObjectPane support docs, static pool docs, and live `0x00512960` handler. It cannot be safely resolved as a MapPane child or dead duplicate yet because no code/pointer route reaches the function start while the body is valid retained DamageNumberObjectPane construction code.
- `0x0050f030-0x0050f130` and `0x0050f130-0x0050f26d`: investigated enough to exclude from this batch. Direct caller evidence exists (`0x0050f130 -> 0x0050f030`), but source naming, StaticObjectPane ownership boundaries, tile descriptor fields, and caller opcode roles need a separate child split report.
- `0x005104c7-0x00513800`: not reworked in this batch. It remains the broad largest leaf and should be prioritized after the immediate post-`0x0050ec30` helper chain is split or explicitly classified.

## No-Direct-Edit Confirmation

B001 created this research report only. No by-* documentation, generated report, IDA DB, or `by-memory/-coverage-report.md` file was directly edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch4.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001AW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
