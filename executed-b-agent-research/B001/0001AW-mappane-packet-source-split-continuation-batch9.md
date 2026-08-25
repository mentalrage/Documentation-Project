** TARGET-REPORT-UID:0001AW **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001AW MapPane Packet Source Split Continuation Batch9

## Finalized Report / Current Recommendation

- Current recommendation: executable child-split batch for the remaining [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](../../../by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) leaf `0x0050f26d-0x00510400`.
- Final disposition for this batch: create five exact child pages, add exact padding rows, update parent/support docs, and leave [UID:0001AW] as `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`.
- Required action: supervisor should apply the executable batch below. Do not reclassify the parent yet, because retained no-route modeled/raw helper bodies remain between the new children.
- Confidence: high for the five child ranges and direct route evidence; medium-high for working helper names; low for final C++ eligibility until packet structs, field names, and no-route retained bodies are resolved.

## Target

- Target UID: [UID:0001AW]
- Target path: `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`
- Assignment: `B001-goal2-memory-tool-mappane-packet-source-split-continuation9-0001AW-20260616`
- Source queue/report row: `auto-generated/by-memory-tool-report.md`, generated `2026-06-16 08:20:12`, largest range rank 89: `0x0050f26d-0x00510400` from [UID:0001AW], 4499 bytes, reconstructable.
- Current target state checked: `85/88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, final C++ blank.
- Current clean generated state checked: Barrier Crossings, General Errors, Filename Errors, and Advanced-Error-Scan all report `None`.

## Executive Recommendation

Create these exact children, assuming no concurrent UID allocation after [UID:0003TT]. The supervisor must re-check current UID availability and substitute the next free UID sequence if it advanced.

| Proposed UID | Path | Range | Owner/emitter | Score | Create now |
| --- | --- | --- | --- | --- | --- |
| [UID:0003TU] | `by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md` | `0x0050f4d0-0x0050f52a` | [UID:0000L3] `MapPane` file | `86/89` | yes |
| [UID:0003TV] | `by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md` | `0x0050f9c0-0x0050fa1b` | [UID:0000L3] `MapPane` file | `86/89` | yes |
| [UID:0003TW] | `by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md` | `0x0050fa90-0x0050faf4` | [UID:0000L3] `MapPane` file | `86/89` | yes |
| [UID:0003TX] | `by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md` | `0x0050fb00-0x0050feab` | [UID:00007Q] `MapPane` class | `86/90` | yes |
| [UID:0003TY] | `by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md` | `0x0050feb0-0x00510230` | [UID:00007Q] `MapPane` class | `86/90` | yes |

Do not create children yet for:

- `0x0050f270-0x0050f3b2`: modeled `sub_50F270`, WorldMapPane/child-pane factory-shaped body, but no IDA xrefs/callers and no raw PE VA/RVA/rel32 hits.
- raw no-function bodies at `0x0050f3c0`, `0x0050f460`, `0x0050f530`, `0x0050f590`, `0x0050f5e0`, `0x0050f620`, and `0x0050fa20`: behavior is recognizable, but there is no caller, pointer, or branch route evidence.
- modeled no-caller wrappers at `0x00510230`, `0x00510320`, and `0x00510380`: support docs identify their constructed dialog/helper routes, but live IDA and PE scans still find no route to their starts.

Do not reroute [UID:0001AW] itself in this batch. The new direct children prove that this subleaf contains both file-level MapPane helpers and class-owned packet handlers, but [UID:0001AW] is still a transitional reconstructable aggregate with many existing class-owned children and remaining no-route bodies. Revisit the parent owner only after the retained raw/modelled no-route spans are either split, reclassified, or proven source-dead; changing the parent from [UID:00007Q] to [UID:0000L3] now would be a metadata churn step rather than a completed source-structure repair.

## Supervisor Active Recheck

- The assignment is report-only. I did not edit by-* docs, generated reports, the IDA DB, or `by-memory/-coverage-report.md`.
- The child batch is directly executable: exact child markdown, support edits, ignored rows, coverage rows, and validation order are provided below.
- Parent [UID:0001AW] must remain reconstructable after this batch because enough no-route executable-looking bodies remain to prevent converting the aggregate into a non-emitting split index.
- No IDA DB edit is recommended. The no-route starts should not be force-created as IDA functions until a caller/pointer/branch route or source-placement proof appears.

## Evidence Standards Used

- IDA MCP session: `b001_mappane_0001AW_20260616`.
- Health: IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; imagebase `0x400000`; `hexrays_ready:true`; `strings_cache_ready:true`; `auto_analysis_ready:false` but the live worker reports `is_analyzing:false` and matches accepted prior MapPane reports.
- IDA checks used: `entity_query`, `xrefs_to`, `analyze_function`, `decompile`, `make_signature_for_range`, focused disassembly/decompilation of dispatcher and callers.
- Raw PE checks used: parsed PE section map, then scanned for little-endian absolute VA dwords, RVA dwords, `E8/E9 rel32`, and `0F 8x rel32` branch hits to every candidate start in `0x0050f270-0x00510400`.
- Documentation checked: current target page, `by-memory/-coverage-report.md`, `by-memory/-ignored.md`, `by-class/MapPane.md`, `by-file/MapPane.md`, `by-type/by-enum/MapServerPacketOpcode.md`, `by-file/RightButtonMenuPane.md`, `by-class/RightButtonMenuPane.md`, `by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md`, `by-memory/0x0061e8dc-0x0061e8ec.MerchantDialogCreatorVtableData.md`, `by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md`, WorldMapPane support docs, and prior executed B001 MapPane reports.

## IDA MCP Facts

### Function Inventory

`entity_query(functions, 0x0050f26d-0x00510400)` reports these modeled starts:

| Start | IDA name | Size | End | Route status |
| --- | --- | ---: | --- | --- |
| `0x0050f270` | `sub_50F270` | `0x142` | `0x0050f3b2` | no xrefs/raw hits, no child |
| `0x0050f4d0` | `sub_50F4D0` | `0x5a` | `0x0050f52a` | direct calls, create [UID:0003TU] |
| `0x0050f9c0` | `sub_50F9C0` | `0x5b` | `0x0050fa1b` | direct calls, create [UID:0003TV] |
| `0x0050fa90` | `sub_50FA90` | `0x64` | `0x0050faf4` | direct calls, create [UID:0003TW] |
| `0x0050fb00` | `sub_50FB00` | `0x3ab` | `0x0050feab` | dispatcher call, create [UID:0003TX] |
| `0x0050feb0` | `sub_50FEB0` | `0x380` | `0x00510230` | dispatcher call, create [UID:0003TY] |
| `0x00510230` | `sub_510230` | `0xe6` | `0x00510316` | no xrefs/raw hits, no child |
| `0x00510320` | `sub_510320` | `0x5f` | `0x0051037f` | no xrefs/raw hits, no child |
| `0x00510380` | `sub_510380` | `0x7d` | `0x005103fd` | no xrefs/raw hits, no child |

### Direct Xref And Raw PE Inventory

| Target | IDA xrefs-to | PE rel32 hits | Decision |
| --- | --- | --- | --- |
| `0x0050f270` | none | none | no child |
| `0x0050f3c0` | none | none | no child |
| `0x0050f460` | none | none | no child |
| `0x0050f4d0` | `0x005074ca`, `0x0050750d`, `0x00554ee3` | same three sites | create |
| `0x0050f530` | none | none | no child |
| `0x0050f590` | none | none | no child |
| `0x0050f5e0` | none | none | no child |
| `0x0050f620` | none | none | no child |
| `0x0050f9c0` | `0x00507765`, `0x005077a9` | same two sites | create |
| `0x0050fa20` | none | none | no child |
| `0x0050fa90` | `0x0050fe75`, `0x00513634` | same two sites | create |
| `0x0050fb00` | `0x00508818` | same site | create |
| `0x0050feb0` | `0x00507d13` | same site | create |
| `0x00510230` | none | none | no child |
| `0x00510320` | none | none | no child |
| `0x00510380` | none | none | no child |

The raw PE scan found no absolute VA or RVA pointer-byte hits for any of these starts.

### Dispatcher / Caller Facts

- `decompile(0x00507c90)` shows case `0x03` calls `sub_50FEB0(v3)` at `0x00507d18`.
- The same decompilation shows case `0x33` returns `sub_50FB00((_DWORD *)(this - 160), (int)v3)` at `0x0050881d`.
- This directly contradicts the current [UID:0001SO][MapServerPacketOpcode](../../../by-type/by-enum/MapServerPacketOpcode.md) row that says opcode `0x33` aliases `0x0050feb0`; update that support page as part of this batch.
- `decompile(0x00507150)` shows `sub_50F4D0` called at `0x005074ca` and `0x0050750d` from MapPane input/action paths, and `sub_50F9C0` called at `0x00507765` and `0x005077a9` from coordinate/action paths.
- `analyze_function(0x00554c40)` and disassembly show RightButtonMenuPane `OnEvent` case 4 calls `sub_50F4D0` at `0x00554ee3`. This is why [UID:0003TU] should be file-owned by [UID:0000L3] rather than treated as an instance method under [UID:00007Q].

### Padding Facts

`make_signature_for_range(..., wildcard_operands=false)` confirms these pure padding/alignment ranges:

| Range | Signature |
| --- | --- |
| `0x0050f3b2-0x0050f3c0` | 14 bytes of `0xcc` |
| `0x0050f454-0x0050f460` | 12 bytes of `0xcc` |
| `0x0050f4c8-0x0050f4d0` | 8 bytes of `0xcc` |
| `0x0050f52a-0x0050f530` | 6 bytes of `0xcc` |
| `0x0050f581-0x0050f590` | 15 bytes of `0xcc` |
| `0x0050f5dd-0x0050f5e0` | 3 bytes of `0xcc` |
| `0x0050f615-0x0050f620` | 11 bytes of `0xcc` |
| `0x0050f9bf-0x0050f9c0` | 1 byte of `0xcc` after a range-check-failure call |
| `0x0050fa1b-0x0050fa20` | 5 bytes of `0xcc` |
| `0x0050fa84-0x0050fa90` | 12 bytes of `0xcc` |
| `0x0050faf4-0x0050fb00` | 12 bytes of `0xcc` |
| `0x0050feab-0x0050feb0` | 5 bytes of `0xcc` |
| `0x00510316-0x00510320` | 10 bytes of `0xcc` |
| `0x0051037f-0x00510380` | 1 byte of `0xcc` |
| `0x005103fd-0x00510400` | 3 bytes of `0xcc` |

Do not mark `0x0050f452-0x0050f454` or `0x0050f57f-0x0050f581` as padding: those bytes are the final immediate bytes of raw `retn` instructions. Do not mark `0x0050f9ba-0x0050f9bf` as padding: those bytes are the terminal `___report_rangecheckfailure` call in the raw user-face asset body.

## Candidate Function Behavior

### [UID:0003TU] `0x0050f4d0-0x0050f52a`

- Decompilation: writes outbound opcode byte `67` (`0x43`), subtype byte `1`, appends one 32-bit argument, and sends exactly six bytes via `sub_574BB0(dword_67A7EC, &packet, 6)`.
- Callers: MapPane input/action handler `0x00507150` at `0x005074ca` and `0x0050750d`, plus RightButtonMenuPane `OnEvent` at `0x00554ee3`.
- Source placement: file-owned [UID:0000L3] `MapPane` helper, not direct class method. It has no `this` receiver, is analogous to [UID:000231] `MapPaneOpcode0CObjectIdPacketHelper`, and is directly reused by RightButtonMenuPane.

### [UID:0003TV] `0x0050f9c0-0x0050fa1b`

- Decompilation: writes outbound opcode byte `10` (`0x0a`), appends two 16-bit values, and sends exactly five bytes.
- Callers: MapPane input/action handler `0x00507150` at `0x00507765` and `0x005077a9`.
- Source placement: file-owned [UID:0000L3] helper. It has no `this` receiver and behaves like a local MapPane outbound packet builder rather than a class instance method.

### [UID:0003TW] `0x0050fa90-0x0050faf4`

- Decompilation: obtains current object/status state through `sub_53A8C0`, then calls `sub_53BAB0(object)` when status codes match `13`, `14`, `15`, `16`, `27`, or id/status codes `0x92`/`0xa1`.
- Callers: new child [UID:0003TX] `sub_50FB00` at `0x0050fe75` and existing [UID:0003TT] `sub_513310` at `0x00513634`.
- Source placement: file-owned [UID:0000L3] MapPane helper. It has no `this` receiver but is shared by MapPane object-info and object-status packet handlers.

### [UID:0003TX] `0x0050fb00-0x0050feab`

- Decompilation: parses packet coordinates, object id, subtype/status blob, object-display text, and object-info type; creates or updates map object state; writes the display text and type; conditionally creates ObjectInfoObjectPane routes; refreshes selection marker; inserts/refreshes the object; calls [UID:0003TW] and [UID:0003TB].
- Direct route: MapPane dispatcher case `0x33`, call at `0x00508818` / decompile marker `0x0050881d`.
- Source placement: direct [UID:00007Q] `MapPane` class packet handler. ObjectInfoObjectPane/ObjectList/ObjectStatusBlob are dependencies, not owners.

### [UID:0003TY] `0x0050feb0-0x00510230`

- Decompilation: clears/updates panel and screen state, uses TransferServerDialogPane construction routes, decodes transfer/server endpoint fields, performs socket/registry checks, sends outbound opcode `0x10` when needed, and toggles socket/transport state.
- Direct route: MapPane dispatcher case `0x03`, call at `0x00507d13` / decompile marker `0x00507d18`.
- Source placement: direct [UID:00007Q] `MapPane` class packet handler. TransferServerDialogPane, Socket, registry/config helpers, and GeneralPurposePanel are dependency or constructed-object owners, not packet-handler owners.

## Roadmap-Only / No-Create Findings

These are the remaining source-quality blockers in `0x0050f26d-0x00510400` after the executable batch:

| Range/start | Evidence checked | Why not safe to create now |
| --- | --- | --- |
| `0x0050f270` | IDA function exists; xrefs-to none; raw PE no VA/RVA/rel32 hits; WorldMapPane docs note constructor/setup calls from this body. | Looks like retained factory/source evidence, but no reachable source route. Leave roadmap-only. |
| `0x0050f3c0` | Raw no-function body; xrefs-to none; PE no hits. Behavior sends outbound opcode `0x05` with coordinate rectangle fields. | No caller or pointer route, and no IDA function object. |
| `0x0050f460` | Raw no-function body; xrefs-to none; PE no hits. Behavior sends opcode `0x38`, toggles MapPane-like state, and calls object/list helpers. | No route; source placement cannot be proven. |
| `0x0050f530` | Raw no-function body; xrefs-to none; PE no hits. Behavior sends outbound opcode `0x45` with one word argument. | Same outbound checksum/challenge family as dispatcher case `0x3b`, but no route to this retained copy. |
| `0x0050f590` | Raw no-function body; xrefs-to none; PE no hits. Behavior sends opcode `0x0b`, length `1`. | No route; do not create below-gate child. |
| `0x0050f5e0` | Raw no-function body; xrefs-to none; PE no hits. Behavior sends one-byte/word value `0x18`. | No route; body is too small to source-place safely. |
| `0x0050f620` | Raw no-function body; xrefs-to none; PE no hits; support string doc [UID:0003IW] records `/users/`, `.epf`, `.face` references. | Behavior is strong user-face asset upload/cache packet evidence, but the raw start has no route. Needs separate raw-retained helper audit before child creation. |
| `0x0050fa20` | Raw no-function body; xrefs-to none; PE no hits. Similar status helper to [UID:0003TW] but calls `sub_53BAD0`. | Looks source-authored/retained, but no caller route. |
| `0x00510230` | IDA function; xrefs-to none; PE no hits; TransferServerDialogPane docs confirm constructor calls inside it. | No live route. Keep as retained transition-dialog helper evidence only. |
| `0x00510320` | IDA function; xrefs-to none; PE no hits; MerchantDialogCreator support docs confirm vtable store and `sub_517450` call. | No live route. Do not create until a dispatcher/caller route is found. |
| `0x00510380` | IDA function; xrefs-to none; PE no hits; decompiles to validation then allocation/constructor at `sub_4A1D70`. | No live route and final owner is weaker than 85/85. |

## Ranked Ownership Analysis

### 1. [UID:0000L3] MapPane file for stateless packet helpers

- Evidence for: [UID:000231] already models no-`this` outbound MapPane packet helper ownership through [UID:0000L3]; [UID:0003TU], [UID:0003TV], and [UID:0003TW] have `__stdcall`/no-instance decompilation and live MapPane source placement; [UID:0003TU] is reused from RightButtonMenuPane and therefore should not be class-instance-only.
- Evidence against: these helpers are physically nested inside the [UID:0001AW] class aggregate and are semantically MapPane protocol helpers.
- Decision: use [UID:0000L3] as direct owner/emitter for [UID:0003TU], [UID:0003TV], and [UID:0003TW].

### 2. [UID:00007Q] MapPane class for dispatcher packet handlers

- Evidence for: [UID:0003TX] and [UID:0003TY] are `__thiscall` handlers reached only from `MapPane::HandlePacket`, take the MapPane receiver, parse inbound server packets, and mutate MapPane/UI state.
- Evidence against: both call into external UI/transport/object helpers, but those are constructed-object/provider dependencies.
- Decision: use [UID:00007Q] as direct owner/emitter for [UID:0003TX] and [UID:0003TY].

### 3. RightButtonMenuPane, Socket, TransferServerDialogPane, MerchantDialogCreator, WorldMapPane

- Evidence for: RightButtonMenuPane calls [UID:0003TU]; Socket helpers send data from the outbound helpers; TransferServerDialogPane and MerchantDialogCreator constructors are reached from later wrappers; WorldMapPane support docs identify `0x0050f270` construction calls.
- Evidence against: none of these own the live MapPane packet helper bytes. They are callers, dependencies, or constructed-object owners. For no-route starts, dependency evidence without a live route is not enough for child creation.
- Decision: reject as direct owners for this executable batch.

## Executable Supervisor Batch

### UID Allocation Assumption

Assume the next free UIDs after [UID:0003TT] are:

- [UID:0003TU]
- [UID:0003TV]
- [UID:0003TW]
- [UID:0003TX]
- [UID:0003TY]

Supervisor must re-check current UID availability before applying and substitute the next contiguous free UID set if another agent advanced the allocator.

### Child Page Markdown

Create `by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md`:

```markdown
*** UID:0003TU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0050f4d0-0x0050f52a MapPane Send Object Action 43 Packet

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact MapPane file-level outbound packet helper split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Direct owner/emitter: [UID:0000L3][MapPane](by-file/MapPane.md); related class [UID:00007Q][MapPane](by-class/MapPane.md).
- Working source name: `MapPaneSendObjectAction43Packet`.
- Confidence: strong for exact range, packet bytes, caller set, and MapPane file-source placement; medium-high for final outbound opcode/subtype name.
- Reconstruction note: C++ intentionally blank. Final source needs confirmed packet name, packet-writer API names, and object/action field names.

## Address Range

- Start: `0x0050f4d0`
- End: `0x0050f52a` end-exclusive
- IDA function: `sub_50F4D0`
- Preceded by ignored padding `0x0050f4c8-0x0050f4d0`.
- Followed by ignored padding `0x0050f52a-0x0050f530`.

## Behavior

This helper builds and queues a six-byte outbound packet:

- writes opcode byte `67` / `0x43`;
- writes subtype byte `1`;
- appends the single 32-bit argument;
- queues exactly six bytes through `sub_574BB0(dword_67A7EC, packet, 6)`.

## Evidence

- IDA `analyze_function(0x0050f4d0)` reports prototype `int __stdcall(unsigned int)`, size `0x5a`, callees `sub_575380`, `sub_5753F0`, `sub_574BB0`, and security-cookie check.
- IDA xrefs-to report direct calls at `0x005074ca` and `0x0050750d` inside `sub_507150`, plus `0x00554ee3` inside `sub_554C40`.
- Raw PE scan with section-correct VA mapping confirms the same three `E8 rel32` hits and no absolute VA/RVA pointer hits.
- `decompile(0x00507150)` shows the MapPane input/action path passing the selected object's id at offsets `0x005074ca` and `0x0050750d`.
- `analyze_function(0x00554c40)` and disassembly show RightButtonMenuPane `OnEvent` case 4 calls this helper with `dword ptr [esi+0x5c]` at `0x00554ee3`.

## Ownership Decision

This is a MapPane file-level protocol helper, not a `MapPane` instance method. It has no `this` receiver, one caller is RightButtonMenuPane, and the body only builds an outbound packet. The source-placement model matches [UID:000231][0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper](by-memory/0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md): a MapPane source helper that may be reused outside the MapPane class.

## Rejected Owners

- [UID:00007Q][MapPane](by-class/MapPane.md): semantic consumer, but the helper has no instance state and one non-MapPane-class caller.
- [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md): caller/consumer only; the helper is physically in the MapPane packet cluster and also called by MapPane input code.
- Socket/transport pages: packet-send dependency only.

## Score Rationale

Completion is `86` because exact range, packet bytes, all caller routes, raw PE branch evidence, ownership, and adjacent padding are documented. Confidence is `89` because the byte behavior and caller set are direct, but final opcode/subtype names remain working names.

## Cross-References

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md)
- [UID:000231][0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper](by-memory/0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation batch9: split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) as direct-route MapPane file-level outbound packet helper.
```

Create `by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md`:

```markdown
*** UID:0003TV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0050f9c0-0x0050fa1b MapPane Send Coordinate 0A Packet

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact MapPane file-level outbound coordinate packet helper split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Direct owner/emitter: [UID:0000L3][MapPane](by-file/MapPane.md); related class [UID:00007Q][MapPane](by-class/MapPane.md).
- Working source name: `MapPaneSendCoordinate0APacket`.
- Confidence: strong for exact range, packet bytes, MapPane input callers, and file-helper source placement; medium-high for final coordinate/action packet name.
- Reconstruction note: C++ intentionally blank. Final source needs confirmed packet name, coordinate meaning, and packet-writer helper names.

## Address Range

- Start: `0x0050f9c0`
- End: `0x0050fa1b` end-exclusive
- IDA function: `sub_50F9C0`
- Preceded by ignored padding `0x0050f9bf-0x0050f9c0`.
- Followed by ignored padding `0x0050fa1b-0x0050fa20`.

## Behavior

This helper builds and queues a five-byte outbound packet:

- writes opcode byte `10` / `0x0a`;
- appends two 16-bit values;
- queues exactly five bytes through `sub_574BB0(dword_67A7EC, packet, 5)`.

## Evidence

- IDA `analyze_function(0x0050f9c0)` reports prototype `int __stdcall(unsigned int, unsigned int)`, size `0x5b`, callees `sub_575380`, `sub_5753A0`, `sub_574BB0`, and security-cookie check.
- IDA xrefs-to report direct calls at `0x00507765` and `0x005077a9` inside `sub_507150`.
- Raw PE scan with section-correct VA mapping confirms the same two `E8 rel32` hits and no absolute VA/RVA pointer hits.
- `decompile(0x00507150)` shows both callers are MapPane input/action paths that resolve a selected object or tile/action context, then pass two packet values to this helper.

## Ownership Decision

This is a MapPane file-level outbound packet helper. It has no `this` receiver and only builds a compact socket packet. It should emit with [UID:0000L3][MapPane](by-file/MapPane.md), while MapPane class pages remain semantic consumers.

## Rejected Owners

- [UID:00007Q][MapPane](by-class/MapPane.md): semantic route, but no instance receiver and no direct MapPane field access.
- Socket/transport pages: send dependency only.
- Packet enum/type pages: naming/index evidence only, not executable owner.

## Score Rationale

Completion is `86` because exact range, packet construction, caller routes, raw PE call hits, owner decision, and adjacent padding are documented. Confidence is `89` because direct evidence is strong but final action/coordinate semantics remain provisional.

## Cross-References

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation batch9: split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) as direct-route MapPane file-level outbound coordinate packet helper.
```

Create `by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md`:

```markdown
*** UID:0003TW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0050fa90-0x0050faf4 MapPane Refresh Object Status Overlay

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact MapPane file-level object/status refresh helper split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Direct owner/emitter: [UID:0000L3][MapPane](by-file/MapPane.md); related class [UID:00007Q][MapPane](by-class/MapPane.md).
- Working source name: `MapPaneRefreshObjectStatusOverlay`.
- Confidence: strong for exact range, caller set, object/status branch behavior, and source placement; medium-high for final status code names.
- Reconstruction note: C++ intentionally blank. Final source needs named object/status codes and helper API names.

## Address Range

- Start: `0x0050fa90`
- End: `0x0050faf4` end-exclusive
- IDA function: `sub_50FA90`
- Preceded by ignored padding `0x0050fa84-0x0050fa90`.
- Followed by ignored padding `0x0050faf4-0x0050fb00`.

## Behavior

This helper reads current object/status context through `sub_53A8C0` and refreshes an object overlay/status route through `sub_53BAB0(object)` when the status values match known visual/status cases:

- status values `13`, `14`, `15`, `16`, or `27`;
- secondary values `0x92` or `0xa1`.

## Evidence

- IDA `analyze_function(0x0050fa90)` reports prototype `__int16 __stdcall(int)`, size `0x64`, callees `sub_53A8C0` and `sub_53BAB0`.
- IDA xrefs-to report direct calls at `0x0050fe75` inside [UID:0003TX] `sub_50FB00` and `0x00513634` inside existing [UID:0003TT][0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket](by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md).
- Raw PE scan with section-correct VA mapping confirms the same two `E8 rel32` hits and no absolute VA/RVA pointer hits.
- The caller set ties the helper to MapPane object-info and object-status packet processing, not to the callee object-pane implementation.

## Ownership Decision

This helper belongs to the [UID:0000L3][MapPane](by-file/MapPane.md) source file. It has no `this` receiver and is shared by two MapPane packet handlers. [UID:00007Q][MapPane](by-class/MapPane.md) owns the caller methods, but this helper should remain a file-level MapPane helper until final source proves a static class-member declaration.

## Rejected Owners

- [UID:00007Q][MapPane](by-class/MapPane.md): owns the packet handlers that call this helper, but the helper itself has no instance receiver.
- ObjectList/ObjectPane classes: status refresh dependencies only.
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md): packet-index support only.

## Score Rationale

Completion is `86` because exact range, caller set, raw PE call hits, decompiled status behavior, ownership, and adjacent padding are documented. Confidence is `89` because direct evidence is strong, with uncertainty limited to final status-code/helper names.

## Cross-References

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0003TX][0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket](by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md)
- [UID:0003TT][0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket](by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation batch9: split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) as direct-route MapPane file-level object/status refresh helper.
```

Create `by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md`:

```markdown
*** UID:0003TX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0050fb00-0x0050feab MapPane Handle Object Info Packet

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact MapPane packet-handler child split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Direct owner/emitter: [UID:00007Q][MapPane](by-class/MapPane.md); file owner [UID:0000L3][MapPane](by-file/MapPane.md).
- Working source name: `MapPaneHandleObjectInfoPacket`.
- Packet route: dispatcher case `0x33`.
- Confidence: strong for exact range, dispatcher caller, object-info/status behavior, MapPane ownership, and adjacent padding; medium-high for final payload, subtype, and helper names.
- Reconstruction note: C++ intentionally blank. Final source needs named object-info packet fields, status blob layout, object-info type names, and helper method names.

## Address Range

- Start: `0x0050fb00`
- End: `0x0050feab` end-exclusive
- IDA function: `sub_50FB00`
- Preceded by ignored padding `0x0050faf4-0x0050fb00`.
- Followed by ignored padding `0x0050feab-0x0050feb0`.

## Behavior

This handler parses an inbound map object/info packet:

- reads tile/object coordinates, object id, subtype, and status blob selector;
- parses one of two status blob encodings through `sub_4D1FA0` or `sub_4D2640`;
- converts the packet display text to a fixed wide-character buffer;
- creates or updates object state through MapPane object helpers;
- writes display text and object-info type to the target object;
- conditionally creates or refreshes object info panes and selection-marker state;
- inserts/refreshes the object in MapPane object state;
- calls [UID:0003TW][0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay](by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md) and [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent](by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md).

## Evidence

- IDA `analyze_function(0x0050fb00)` reports prototype `char __thiscall(_DWORD *this, int)`, size `0x3ab`.
- IDA xrefs-to reports one direct code ref at `0x00508818` inside `sub_507C90`.
- Raw PE scan with section-correct VA mapping confirms the same `E8 rel32` hit and no absolute VA/RVA pointer hits.
- `decompile(0x00507c90)` shows dispatcher case `0x33` returning `sub_50FB00((_DWORD *)(this - 160), (int)v3)` at decompile marker `0x0050881d`.
- Decompilation reads coordinates at packet offsets `+1` and `+3`, object id at `+6`, subtype at `+10`, parses status blobs from `+11`, converts packet text with `MultiByteToWideChar`, and copies the resulting wide text to object storage.
- Direct callees include object/list and pane helpers `sub_505290`, `sub_505E00`, `sub_4B7E30`, `sub_4B7E80`, `sub_5314A0`, `sub_539690`, `sub_4B8E00`, [UID:0003TW] `sub_50FA90`, and [UID:0003TB] `sub_50E4C0`.

## Ownership Decision

This body belongs to [UID:00007Q][MapPane](by-class/MapPane.md). It is reached from the MapPane packet dispatcher, receives the MapPane instance, parses an inbound map object packet, and mutates MapPane object/UI state. ObjectInfoObjectPane, ObjectList, ObjectStatusBlob, and packet helper pages are dependencies or payload providers rather than direct owners.

## Support-Doc Correction

Current [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) incorrectly says opcode `0x33` aliases the `0x0050feb0` transition handler. This live IDA pass proves `0x33` dispatches to this handler at `0x0050fb00`; supervisor should update the opcode row and related evidence note.

## Score Rationale

Completion is `86` because exact range, dispatcher case, raw PE call hit, packet decoding behavior, callee/dependency routing, ownership decision, and adjacent padding are documented. Confidence is `90` because IDA, raw PE, and MapPane source placement agree; confidence remains below final-source quality because payload and helper names are still provisional.

## Cross-References

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)
- [UID:0003TW][0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay](by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md)
- [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent](by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation batch9: split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) as direct-call MapPane opcode `0x33` object-info packet handler.
```

Create `by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md`:

```markdown
*** UID:0003TY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x0050feb0-0x00510230 MapPane Handle Map Transition Packet

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: exact MapPane packet-handler child split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).
- Direct owner/emitter: [UID:00007Q][MapPane](by-class/MapPane.md); file owner [UID:0000L3][MapPane](by-file/MapPane.md).
- Working source name: `MapPaneHandleMapTransitionPacket`.
- Packet route: dispatcher case `0x03`.
- Confidence: strong for exact range, dispatcher caller, transition/transfer dialog behavior, MapPane ownership, and adjacent padding; medium-high for final transfer payload, registry/config, and helper names.
- Reconstruction note: C++ intentionally blank. Final source needs named packet fields, transport state helpers, registry/config helpers, and panel-field names.

## Address Range

- Start: `0x0050feb0`
- End: `0x00510230` end-exclusive
- IDA function: `sub_50FEB0`
- Preceded by ignored padding `0x0050feab-0x0050feb0`.
- Followed by no-route modeled function `sub_510230` at `0x00510230`.

## Behavior

This handler processes an inbound map transition / server transfer packet:

- clears or updates active panel/screen state through GeneralPurposePanel and UI helper routes;
- dismisses current transition/dialog pane state when present;
- constructs a TransferServerDialogPane when transfer overlay storage is empty;
- decodes endpoint/port/string payload fields from the packet;
- performs socket/transport and registry/config checks;
- sends outbound opcode `0x10` with the copied string and login/session state when needed;
- toggles socket/transport state and requests application/map transition side effects.

## Evidence

- IDA `analyze_function(0x0050feb0)` reports prototype `char __thiscall(_DWORD *this, int)`, size `0x380`.
- IDA xrefs-to reports one direct code ref at `0x00507d13` inside `sub_507C90`.
- Raw PE scan with section-correct VA mapping confirms the same `E8 rel32` hit and no absolute VA/RVA pointer hits.
- `decompile(0x00507c90)` shows dispatcher case `0x03` returning `sub_50FEB0(v3)` at decompile marker `0x00507d18`.
- Decompilation calls `sub_4B85F0`, `sub_5671E0`, `sub_4B8950`, `sub_588D70`, `sub_598ED0`, socket helpers `sub_574CD0`/`sub_574CE0`/`sub_574BB0`, registry helpers through `unk_69BE94`/`unk_69BE70`, and `RegCloseKey`.
- [UID:0001FI][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md) documents constructor calls from `0x0050ff65`, `0x0050ffce`, and `0x0051012e` inside this handler.
- [UID:0001XU][0x006168d0-0x00617a38.ConfigChannelReadOnlyData](by-memory/0x006168d0-0x00617a38.ConfigChannelReadOnlyData.md) and socket helper docs include this handler as a consumer/dependency route.

## Ownership Decision

This body belongs to [UID:00007Q][MapPane](by-class/MapPane.md). It is reached from the MapPane packet dispatcher and coordinates MapPane-side transition, panel, and transport behavior. TransferServerDialogPane owns the constructed pane class; Socket/transport and registry/config pages own their helper APIs and data, not this packet handler.

## Score Rationale

Completion is `86` because exact range, dispatcher case, raw PE call hit, transition behavior, dependency routes, ownership decision, and adjacent padding are documented. Confidence is `90` because IDA, raw PE, and support docs agree on the route; confidence remains below final-source quality because transfer packet field names and transport/registry helper names are still provisional.

## Cross-References

- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)
- [UID:0001FI][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)

## Changes

- 2026-06-16 B001 continuation batch9: split from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) as direct-call MapPane opcode `0x03` map transition packet handler.
```

### Parent / Support Doc Actions

1. In `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`, keep header metadata unchanged: `85/88`, owner/emitter [UID:00007Q], reconstructable true.

2. In the `Covered Ranges` table, replace:

```markdown
| `0x0050fb00-0x0051022f` | map packet and transition handlers | Parses map-object packet and handles server transfer/map transition. |
```

with:

```markdown
| `0x0050fb00-0x0051022f` | object-info and map transition handlers | Parses opcode `0x33` object-info/map-object packet at `0x0050fb00` and opcode `0x03` server transfer/map transition packet at `0x0050feb0`. |
```

3. In the same parent page, add these rows to `Exact Child Pages And Nesting` after [UID:0003TJ] and before [UID:0001AX]:

```markdown
| [UID:0003TU][0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet](by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md) | Exact modeled MapPane file-level outbound opcode `0x43` helper; builds a six-byte packet from MapPane input/action and RightButtonMenuPane action routes. |
| [UID:0003TV][0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket](by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md) | Exact modeled MapPane file-level outbound opcode `0x0a` coordinate/action helper called by MapPane input routes. |
| [UID:0003TW][0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay](by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md) | Exact modeled MapPane file-level object/status refresh helper called by the object-info and object-status packet handlers. |
| [UID:0003TX][0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket](by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md) | Exact modeled MapPane opcode `0x33` object-info/map-object packet handler; parses object coordinates/id/status blobs, creates or updates object-info state, and refreshes object overlays. |
| [UID:0003TY][0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket](by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md) | Exact modeled MapPane opcode `0x03` server transfer/map transition packet handler; clears panels, manages transfer overlay state, decodes endpoint payload, and routes socket/registry transition checks. |
```

4. In the parent `Current Exact Boundary Inventory`, add rows for `0x0050f4d0`, `0x0050f9c0`, `0x0050fa90`, and `0x0050feb0`, and replace the existing `0x0050fb00` row with:

```markdown
| `0x0050f4d0` | `sub_50F4D0` | `0x5a` | Exact child [UID:0003TU][0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet](by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md); file-level outbound opcode `0x43` helper called by MapPane input/action paths and RightButtonMenuPane `OnEvent`. |
| `0x0050f9c0` | `sub_50F9C0` | `0x5b` | Exact child [UID:0003TV][0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket](by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md); file-level outbound opcode `0x0a` coordinate/action helper called by MapPane input paths. |
| `0x0050fa90` | `sub_50FA90` | `0x64` | Exact child [UID:0003TW][0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay](by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md); file-level object/status refresh helper called by `0x0050fb00` and [UID:0003TT]. |
| `0x0050fb00` | `sub_50FB00` | `0x3ab` | Exact child [UID:0003TX][0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket](by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md); opcode `0x33` object-info/map-object handler called from dispatcher case at `0x00508818`. |
| `0x0050feb0` | `sub_50FEB0` | `0x380` | Exact child [UID:0003TY][0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket](by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md); opcode `0x03` map transition / transfer handler called from dispatcher case at `0x00507d13`. |
```

5. Add this parent evidence bullet before the `Ownership Decision` section:

```markdown
- 2026-06-16 B001 continuation batch9 live IDA MCP session `b001_mappane_0001AW_20260616`: `entity_query` over `0x0050f26d-0x00510400` reports modeled starts at `0x0050f270`, `0x0050f4d0`, `0x0050f9c0`, `0x0050fa90`, `0x0050fb00`, `0x0050feb0`, `0x00510230`, `0x00510320`, and `0x00510380`. `analyze_function` and `xrefs_to` confirm direct route evidence for [UID:0003TU] `0x0050f4d0`, [UID:0003TV] `0x0050f9c0`, [UID:0003TW] `0x0050fa90`, [UID:0003TX] `0x0050fb00`, and [UID:0003TY] `0x0050feb0`; a section-correct raw PE scan confirms the same rel32 hits and no VA/RVA pointer hits. The same pass confirms no xrefs/raw PE route for no-create starts `0x0050f270`, raw bodies at `0x0050f3c0`, `0x0050f460`, `0x0050f530`, `0x0050f590`, `0x0050f5e0`, `0x0050f620`, `0x0050fa20`, and modeled wrappers `0x00510230`, `0x00510320`, and `0x00510380`. `decompile(0x00507c90)` corrects opcode routing: case `0x03` calls `0x0050feb0`, while case `0x33` calls `0x0050fb00`.
```

6. Add this parent change bullet:

```markdown
- 2026-06-16 B001 continuation split batch9: create file-level helper children [UID:0003TU][0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet](by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md), [UID:0003TV][0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket](by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md), and [UID:0003TW][0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay](by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md), plus class-owned packet handler children [UID:0003TX][0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket](by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md) and [UID:0003TY][0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket](by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md). Parent [UID:0001AW] remains `RECONSTRUCTABLE:TRUE`, `85/88`, and owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md) because retained no-route raw/modelled helper bodies remain in `0x0050f270-0x00510400`.
```

7. In `by-type/by-enum/MapServerPacketOpcode.md`, replace the observed value row:

```markdown
| `0x33` | map transition / map packet handler alias | Dispatches to `0x0050feb0`, same target as `0x03`. |
```

with:

```markdown
| `0x33` | object info / map-object packet | Dispatches to `0x0050fb00`; parses object coordinates/id/status blobs, creates or updates map object-info state, and refreshes object overlays. |
```

8. In the same enum page evidence note that currently says selected live case bodies include `case 0x03 at 0x00507d0c calls 0x0050feb0`, add:

```markdown
case `0x33` at `0x00508818` calls `0x0050fb00` for object-info/map-object packet handling;
```

9. In `by-file/MapPane.md`, add this note after the existing 2026-06-16 B001 continuation batch8 paragraph:

```markdown
2026-06-16 B001 continuation batch9 split the earlier `0x0050f26d-0x00510400` leaf into exact direct-route children [UID:0003TU][0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet](by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md), [UID:0003TV][0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket](by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md), [UID:0003TW][0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay](by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md), [UID:0003TX][0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket](by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md), and [UID:0003TY][0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket](by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md). The first three are MapPane file-level helpers because they have no `this` receiver, while the latter two are direct `MapPane` packet handlers. The same pass corrected opcode `0x33` to the object-info handler at `0x0050fb00`; opcode `0x03` remains the transition handler at `0x0050feb0`.
```

Add the five new child links to the MapPane file cross-reference list near the other [UID:0003T*] MapPane packet children.

10. In `by-class/MapPane.md`, add this evidence note after the batch8 note:

```markdown
- 2026-06-16 B001 continuation batch9: added direct packet-handler children [UID:0003TX][0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket](by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md) for opcode `0x33` and [UID:0003TY][0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket](by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md) for opcode `0x03`. The same pass added file-level MapPane protocol helpers [UID:0003TU], [UID:0003TV], and [UID:0003TW] under the MapPane source file because those helpers have no `this` receiver.
```

Add [UID:0003TX] and [UID:0003TY] to the class cross-reference list; add [UID:0003TU]/[UID:0003TV]/[UID:0003TW] only as related file-level helpers if the class page keeps a related-helper subsection.

### Ignored Ledger Text

In `by-memory/-ignored.md`, insert these entries after existing `0x0050f26d-0x0050f270` MapPane entry:

```markdown
- `0x0050f3b2-0x0050f3c0` - alignment padding after retained no-route `sub_50F270`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between modeled no-route `sub_50F270` and the raw no-function outbound helper body at `0x0050f3c0`.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows fourteen `0xcc` bytes at `0x0050f3b2-0x0050f3c0`; `entity_query` reports `sub_50F270` size `0x142` ending at `0x0050f3b2`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).

- `0x0050f454-0x0050f460` - alignment padding after raw outbound helper body.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the raw `0x0050f3c0` body's `retn 8` and before raw no-function bytes at `0x0050f460`.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows twelve `0xcc` bytes at `0x0050f454-0x0050f460`; the preceding two bytes `0x0050f452-0x0050f454` are part of the raw `retn 8` instruction and are not marked ignored.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).

- `0x0050f4c8-0x0050f4d0` - alignment padding before `MapPaneSendObjectAction43Packet`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes before exact child [UID:0003TU].
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows eight `0xcc` bytes at `0x0050f4c8-0x0050f4d0`; `entity_query` reports `sub_50F4D0` starts at `0x0050f4d0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0003TU][0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet](by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md) and [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).

- `0x0050f52a-0x0050f530` - alignment padding after `MapPaneSendObjectAction43Packet`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after exact child [UID:0003TU].
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows six `0xcc` bytes at `0x0050f52a-0x0050f530`; `entity_query` reports `sub_50F4D0` size `0x5a` ending at `0x0050f52a`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0003TU][0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet](by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md) and [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).

- `0x0050f581-0x0050f590` - alignment padding after raw no-route opcode `0x45` helper body.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the raw `0x0050f530` body's `retn 4` and before raw no-function bytes at `0x0050f590`.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows fifteen `0xcc` bytes at `0x0050f581-0x0050f590`; the preceding two bytes `0x0050f57f-0x0050f581` are part of the raw `retn 4` instruction and are not marked ignored.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).

- `0x0050f5dd-0x0050f5e0` - alignment padding between raw no-route outbound helper bodies.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows three `0xcc` bytes at `0x0050f5dd-0x0050f5e0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).

- `0x0050f615-0x0050f620` - alignment padding before retained raw user-face asset helper body.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows eleven `0xcc` bytes at `0x0050f615-0x0050f620`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).

- `0x0050f9bf-0x0050f9c0` - alignment padding after raw user-face asset range-check failure site.
  - Why ignored: confirmed single `0xcc` compiler/linker alignment byte after the raw body's terminal range-check-failure call and before exact child [UID:0003TV].
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows one `0xcc` byte at `0x0050f9bf-0x0050f9c0`; the preceding `0x0050f9ba-0x0050f9bf` bytes are the terminal `___report_rangecheckfailure` call and are not ignored.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0003TV][0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket](by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md) and [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).

- `0x0050fa1b-0x0050fa20` - alignment padding after `MapPaneSendCoordinate0APacket`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after exact child [UID:0003TV].
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows five `0xcc` bytes at `0x0050fa1b-0x0050fa20`; `entity_query` reports `sub_50F9C0` size `0x5b` ending at `0x0050fa1b`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0003TV][0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket](by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md) and [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).

- `0x0050fa84-0x0050fa90` - alignment padding before `MapPaneRefreshObjectStatusOverlay`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes before exact child [UID:0003TW].
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows twelve `0xcc` bytes at `0x0050fa84-0x0050fa90`; `entity_query` reports `sub_50FA90` starts at `0x0050fa90`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0003TW][0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay](by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md) and [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).

- `0x0050faf4-0x0050fb00` - alignment padding after `MapPaneRefreshObjectStatusOverlay`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after exact child [UID:0003TW] and before exact child [UID:0003TX].
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows twelve `0xcc` bytes at `0x0050faf4-0x0050fb00`; `entity_query` reports `sub_50FA90` size `0x64` ending at `0x0050faf4` and `sub_50FB00` starts at `0x0050fb00`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0003TW][0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay](by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md), [UID:0003TX][0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket](by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md), and [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).

- `0x0050feab-0x0050feb0` - alignment padding between object-info and map-transition packet handlers.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after exact child [UID:0003TX] and before exact child [UID:0003TY].
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows five `0xcc` bytes at `0x0050feab-0x0050feb0`; `entity_query` reports `sub_50FB00` ending at `0x0050feab` and `sub_50FEB0` starting at `0x0050feb0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0003TX][0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket](by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md), [UID:0003TY][0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket](by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md), and [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).

- `0x00510316-0x00510320` - alignment padding after no-route `sub_510230`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after modeled no-route transfer-dialog wrapper and before modeled no-route MerchantDialogCreator wrapper.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows ten `0xcc` bytes at `0x00510316-0x00510320`; `entity_query` reports `sub_510230` size `0xe6` ending at `0x00510316` and `sub_510320` starts at `0x00510320`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).

- `0x0051037f-0x00510380` - alignment padding after no-route `sub_510320`.
  - Why ignored: confirmed single `0xcc` compiler/linker alignment byte.
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows one `0xcc` byte at `0x0051037f-0x00510380`; `entity_query` reports `sub_510320` size `0x5f` ending at `0x0051037f` and `sub_510380` starts at `0x00510380`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md).

- `0x005103fd-0x00510400` - alignment padding before `MapPaneDayNightPacketRawBody`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after modeled no-route `sub_510380` and before existing raw child [UID:0001AX].
  - Evidence: 2026-06-16 B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows three `0xcc` bytes at `0x005103fd-0x00510400`; `entity_query` reports `sub_510380` size `0x7d` ending at `0x005103fd`, and [UID:0001AX] begins at `0x00510400`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) and [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md).
```

### Coverage Report Rows

Do not edit `by-memory/-coverage-report.md` directly. Supervisor should insert this block under the existing [UID:0001AW] row, after the existing `0x0050f26d-0x0050f270` ignored row and before the existing [UID:0001AX] `0x00510400-0x005104c7` row:

```markdown
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050f3b2-0x0050f3c0 | padding | Retained no-route WorldMapPane factory-shaped helper to raw outbound helper alignment : ignored : 100% : strong : B001 IDA MCP `make_signature_for_range` with operand wildcarding disabled shows fourteen `0xcc` bytes after `sub_50F270` end-exclusive `0x0050f3b2`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050f454-0x0050f460 | padding | Raw outbound helper to raw state-reset helper alignment : ignored : 100% : strong : B001 IDA MCP confirms twelve `0xcc` bytes after the raw `0x0050f3c0` body's `retn 8`; the `retn` immediate bytes are not marked ignored.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050f4c8-0x0050f4d0 | padding | Raw state-reset helper to MapPaneSendObjectAction43Packet alignment : ignored : 100% : strong : B001 IDA MCP confirms eight `0xcc` bytes before exact child [UID:0003TU].
        - [UID:0003TU][0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet](by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md) 0x0050f4d0-0x0050f52a | file-level outbound packet helper | MapPaneSendObjectAction43Packet : reconstructable : 86% : strong : Exact modeled `sub_50F4D0` child split from MapPanePacketHandlers; live IDA and raw PE confirm direct calls from MapPane input/action at `0x005074ca` and `0x0050750d` plus RightButtonMenuPane `OnEvent` at `0x00554ee3`; helper writes outbound opcode `0x43`, subtype `1`, a 32-bit argument, and sends six bytes. Owner/emitter [UID:0000L3][MapPane](by-file/MapPane.md); MapPane and RightButtonMenuPane are callers/consumers. Final C++ blank pending final packet/action names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050f52a-0x0050f530 | padding | MapPaneSendObjectAction43Packet to raw opcode 0x45 helper alignment : ignored : 100% : strong : B001 IDA MCP confirms six `0xcc` bytes after [UID:0003TU] end-exclusive `0x0050f52a`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050f581-0x0050f590 | padding | Raw opcode 0x45 helper to raw opcode 0x0b helper alignment : ignored : 100% : strong : B001 IDA MCP confirms fifteen `0xcc` bytes after the raw `0x0050f530` body's `retn 4`; the `retn` immediate bytes are not marked ignored.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050f5dd-0x0050f5e0 | padding | Raw opcode 0x0b helper to raw opcode 0x18 helper alignment : ignored : 100% : strong : B001 IDA MCP confirms three `0xcc` bytes.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050f615-0x0050f620 | padding | Raw opcode 0x18 helper to raw user-face asset helper alignment : ignored : 100% : strong : B001 IDA MCP confirms eleven `0xcc` bytes.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050f9bf-0x0050f9c0 | padding | Raw user-face asset helper to MapPaneSendCoordinate0APacket alignment : ignored : 100% : strong : B001 IDA MCP confirms one `0xcc` byte after the raw body's terminal `___report_rangecheckfailure` call and before exact child [UID:0003TV].
        - [UID:0003TV][0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket](by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md) 0x0050f9c0-0x0050fa1b | file-level outbound packet helper | MapPaneSendCoordinate0APacket : reconstructable : 86% : strong : Exact modeled `sub_50F9C0` child split from MapPanePacketHandlers; live IDA and raw PE confirm direct calls from MapPane input/action at `0x00507765` and `0x005077a9`; helper writes outbound opcode `0x0a`, two 16-bit values, and sends five bytes. Owner/emitter [UID:0000L3][MapPane](by-file/MapPane.md). Final C++ blank pending final coordinate/action packet names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050fa1b-0x0050fa20 | padding | MapPaneSendCoordinate0APacket to raw status-refresh helper alignment : ignored : 100% : strong : B001 IDA MCP confirms five `0xcc` bytes after [UID:0003TV] end-exclusive `0x0050fa1b`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050fa84-0x0050fa90 | padding | Raw status-refresh helper to MapPaneRefreshObjectStatusOverlay alignment : ignored : 100% : strong : B001 IDA MCP confirms twelve `0xcc` bytes before exact child [UID:0003TW].
        - [UID:0003TW][0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay](by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md) 0x0050fa90-0x0050faf4 | file-level object/status helper | MapPaneRefreshObjectStatusOverlay : reconstructable : 86% : strong : Exact modeled `sub_50FA90` child split from MapPanePacketHandlers; live IDA and raw PE confirm direct calls from [UID:0003TX] at `0x0050fe75` and [UID:0003TT] at `0x00513634`; helper refreshes object overlay/status routes for status codes `13`, `14`, `15`, `16`, `27`, `0x92`, and `0xa1`. Owner/emitter [UID:0000L3][MapPane](by-file/MapPane.md). Final C++ blank pending final status-code/helper names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050faf4-0x0050fb00 | padding | MapPaneRefreshObjectStatusOverlay to MapPaneHandleObjectInfoPacket alignment : ignored : 100% : strong : B001 IDA MCP confirms twelve `0xcc` bytes after [UID:0003TW] end-exclusive `0x0050faf4` and before exact child [UID:0003TX].
        - [UID:0003TX][0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket](by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md) 0x0050fb00-0x0050feab | class method/packet handler | MapPaneHandleObjectInfoPacket : reconstructable : 86% : strong : Exact modeled `sub_50FB00` child split from MapPanePacketHandlers; live IDA and raw PE confirm the dispatcher call at `0x00508818`, and `decompile(0x00507c90)` proves opcode `0x33` routes here rather than to `0x0050feb0`. Handler parses object coordinates/id/status blobs/text, creates or updates map object-info state, calls [UID:0003TW] and [UID:0003TB], and refreshes MapPane object UI state. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md). Final C++ blank pending final packet, blob, field, and helper names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050feab-0x0050feb0 | padding | MapPaneHandleObjectInfoPacket to MapPaneHandleMapTransitionPacket alignment : ignored : 100% : strong : B001 IDA MCP confirms five `0xcc` bytes after [UID:0003TX] end-exclusive `0x0050feab` and before exact child [UID:0003TY].
        - [UID:0003TY][0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket](by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md) 0x0050feb0-0x00510230 | class method/packet handler | MapPaneHandleMapTransitionPacket : reconstructable : 86% : strong : Exact modeled `sub_50FEB0` child split from MapPanePacketHandlers; live IDA and raw PE confirm the dispatcher call at `0x00507d13` for opcode `0x03`; handler clears/updates UI panels, manages TransferServerDialogPane construction, decodes transfer endpoint payload, checks socket/registry state, sends outbound opcode `0x10` when needed, and toggles transport/transition state. Owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md); TransferServerDialogPane and Socket remain dependency/constructed-object owners. Final C++ blank pending final packet, transport, registry, field, and helper names.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00510316-0x00510320 | padding | No-route transfer-dialog wrapper to no-route MerchantDialogCreator wrapper alignment : ignored : 100% : strong : B001 IDA MCP confirms ten `0xcc` bytes after no-route `sub_510230` end-exclusive `0x00510316`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051037f-0x00510380 | padding | No-route MerchantDialogCreator wrapper to no-route dialog allocator wrapper alignment : ignored : 100% : strong : B001 IDA MCP confirms one `0xcc` byte after no-route `sub_510320` end-exclusive `0x0051037f`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005103fd-0x00510400 | padding | No-route dialog allocator wrapper to MapPaneDayNightPacketRawBody alignment : ignored : 100% : strong : B001 IDA MCP confirms three `0xcc` bytes after no-route `sub_510380` end-exclusive `0x005103fd` and before existing [UID:0001AX].
```

Leave the existing [UID:0001AX] `0x00510400-0x005104c7` row unchanged unless separately assigned. It is still `84%` and should not be forced above gate by this batch.

## Validation Order

Supervisor should run validation after applying the child/support/ignored/coverage edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001AW-mappane-packet-source-split-continuation-batch9-removed.md](0001AW-mappane-packet-source-split-continuation-batch9-removed.md). The archived block is non-authoritative and must not be executed.

Expected post-application state:

- Barrier/General/Filename/Advanced memory-tool sections should remain `None`.
- The old `0x0050f26d-0x00510400` leaf should split into smaller retained no-route raw/modelled leaves and exact new children.
- [UID:0001AW] remains `RECONSTRUCTABLE:TRUE`, because no-route executable-looking bodies remain.

## IDA DB Recommendation

No IDA DB edit is recommended.

- Do not create IDA functions at raw starts `0x0050f3c0`, `0x0050f460`, `0x0050f530`, `0x0050f590`, `0x0050f5e0`, `0x0050f620`, or `0x0050fa20`; all lack xrefs/raw branch/pointer routes.
- Do not rename functions yet. The working names are documentation/source-placement names, not final recovered symbols.
- Do not alter prototypes for `0x0050f4d0`, `0x0050f9c0`, `0x0050fa90`, `0x0050fb00`, or `0x0050feb0`; the current Hex-Rays prototypes are sufficient for documentation, while final C++ needs a dedicated packet-structure naming pass.

## Final Recommendation

Execute batch9 as a bounded child split:

- Create [UID:0003TU]-[UID:0003TY].
- Add exact ignored padding rows listed above.
- Update parent/support docs, especially the [UID:0001SO] opcode `0x33` correction.
- Apply the exact `by-memory/-coverage-report.md` insertion block.
- Keep [UID:0001AW] as `85/88`, `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:00007Q], final C++ blank.
- Keep [UID:0001AX] unchanged; it remains below gate and outside this executable batch.

Next follow-up should audit the retained no-route raw/modelled spans that remain between `0x0050f270` and `0x00510400`, with highest priority on the large raw `0x0050f620` user-face asset helper because support string docs already prove strong behavior but route/liveness remains unresolved.

## Validator Results

- Not run. This was a report-only assignment and no by-* docs were edited.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0001AW-mappane-packet-source-split-continuation-batch9.md`
- Modified: none outside this report.
- Direct by-* edits: none.
- IDA DB edits: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch9.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001AW"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001AW-mappane-packet-source-split-continuation-batch9-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch9.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001AW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
