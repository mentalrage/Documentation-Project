** TARGET-REPORT-UID:0002SU **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002SU] InventoryPane2CoreAndHelpers Source-Quality Research

Agent: Agent-B013  
Mode: report-only research; no leases; no target/support by-* edits.  
Target: `by-memory/0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers.md`  
Assignment report path: `tools/leaser/Agents/Agent-B013/research/0002SU-InventoryPane2CoreAndHelpers-source-quality.md`

## 1. Current Recommendation

`0002SU` should be converted, during the supervisor implementation callback, from an emitting aggregate target into a non-emitting split/index parent. The current range is also underbroad: live MCP evidence shows two retained InventoryPane2 raw packet helpers in the gap after the documented end, before BackPane V3 starts.

Recommended implementation metadata for the repaired parent:

```text
*** COMPLETION:90 ***
*** CONFIDENCE:92 ***
*** CANONICAL_OWNER:00006S ***
*** RECONSTRUCTABLE:FALSE ***
*** EMITTER_UIDS: ***
```

Recommended parent path/range after implementation:

```text
by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md
```

Rationale: the range contains multiple source routines, compiler tables/padding, an ordinary destructor body, a source-empty virtual, vtable-dispatched event methods, and retained raw packet helpers. A single formal C++ block would be misleading. Exact child pages should carry the source C++ or no-code proof.

## 2. Constraints Observed

- Report-only first pass; no target/support by-* documentation edits were made.
- No leases were taken.
- No generated reports, generated C++ files, validator/tool state, manual coverage reports, project-level generated files, or IDA database content were edited.
- MCP evidence was collected from the active live IDA MCP session, not from offline-only reasoning.

## 3. Live MCP Session Evidence

MCP health was checked against supervisor-provided session `398b87c1`.

Observed status:

```text
database: 398b87c1
idb_path: E:\NTK\Resources\NexusTK\NexusTK.exe.i64
status: ok
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
```

Read-only MCP tools used: `server_health`, `lookup_funcs`, `xrefs_to`, `decompile`, `get_bytes`, and `insn_query`.

## 4. Positive Evidence

### Function and Vtable Evidence

`lookup_funcs` confirmed the current target is a cluster of separate IDA functions and raw spans:

| Range / address | MCP result | Recommendation |
|---|---|---|
| `0x004ee650` | not a function | raw InventoryPane2 constructor belongs to existing constructor target, not this core parent |
| `0x004ee6b0` | `sub_4EE6B0`, size `0x1f` | ordinary/non-deleting `InventoryPane2::~InventoryPane2` body |
| `0x004ee6d0` | `sub_4EE6D0`, size `0x0c` | thin embedded-child refresh/forwarder |
| `0x004ee6e0` | `nullsub_35`, size `0x01` | source-empty virtual/no-code child |
| `0x004ee6f0` | `sub_4EE6F0`, size `0x76c` | `InventoryPane2::OnPaint` |
| `0x004eee60` | `sub_4EEE60`, size `0x7c` | `InventoryPane2::OnKeyEvent` |
| `0x004eeee0` | `sub_4EEEE0`, size `0x39a` | `InventoryPane2::OnMouseEvent`, with owned switch table through `0x004ef290` |
| `0x004ef290` | `sub_4EF290`, size `0x16c` | `InventoryPane2::OnServerMessage` / item-help packet handler |
| `0x004ef400` | not a function | retained raw use-item packet helper |
| `0x004ef460` | not a function | retained raw drag/drop packet helper |
| `0x004ef510` | `sub_4EF510`, size `0x11e` | BackPane V3 start; excluded from InventoryPane2 |

`xrefs_to` showed the event methods are vtable-reached:

```text
0x004ee6d0 <- data ref from 0x0061c8b8
0x004ee6f0 <- data ref from 0x0061c8b4
0x004eee60 <- data ref from 0x0061c8c8
0x004eeee0 <- data ref from 0x0061c8c4
0x004ef290 <- data ref from 0x0061c8d0
```

The raw constructor and the retained raw packet helpers had no direct code/data xrefs, matching the local retained-raw-helper pattern already documented for nearby inventory panes.

### Method Behavior Evidence

`0x004ee6b0` restores the InventoryPane2 vtables and calls the base cleanup routine at `0x005450d0`. This is destructor-shaped, not an initialization/setup helper. The scalar deleting wrapper later at `0x004efa40` repeats the same cleanup before optional deallocation, so the source-level destructor body should be represented here and the wrapper should remain compiler glue.

`0x004ee6d0` forwards through virtual slot `+0x20` using the embedded child/subobject at `this + 0x44`. It should receive a descriptive helper name such as `InventoryPane2::RefreshEmbeddedPane` or `ForwardChildRefresh`, but the exact original spelling is not recoverable from MCP evidence.

`0x004ee6e0` is a one-byte `retn` with no meaningful body. It should be a source-empty virtual/no-code child, following accepted local precedent.

`0x004ee6f0` is `InventoryPane2::OnPaint`. It draws either the list view or grid view, iterates visible inventory records via the shared inventory-slot accessor, updates the last-page flag, draws item names/hotkeys, and draws the page/view buttons through `0x004ef630`.

`0x004eee60` is `InventoryPane2::OnKeyEvent`. It handles page decrement/increment on the secondary view object and invalidates/refreshes through the parent virtual slot.

`0x004eeee0` is `InventoryPane2::OnMouseEvent`. It handles hover, button press state, view-mode selection, direct item-use dispatch, double-click item-use dispatch, and inline drag/drop packet emission for opcode `0x66`.

`0x004ef290` is `InventoryPane2::OnServerMessage` / item-help packet handling. It handles opcode `0x59`, validates text length, converts payload text to wide characters, closes any active help popup, and constructs a `SimpleHelpPane` near the current pane bounds.

### Range Extension Evidence

Live bytes and disassembly show the current target end `0x004ef3fc` stops before two InventoryPane2 helpers:

| Range | Evidence | Recommendation |
|---|---|---|
| `0x004ef3fc-0x004ef400` | four `0xcc` bytes | padding before raw helpers |
| `0x004ef400-0x004ef460` | prologue, writes opcode `0x1c`, writes selected-slot byte, sends length `2`, returns with `retn 4` | `InventoryPane2SendUseItemSlotPacketRaw` |
| `0x004ef460-0x004ef50b` | prologue, writes opcode `0x66`, writes 10-byte drag/drop payload, sends length `10`, returns with `retn 8` | `InventoryPane2SendDragDropItemPacketRaw` |
| `0x004ef50b-0x004ef510` | alignment/padding | padding before BackPane V3 |
| `0x004ef510` | first BackPane V3 function | BackPane begins here |

`insn_query` over nearby inventory pane code found the same raw packet-helper pattern:

```text
push 1Ch: 0x004eae2a, 0x004edcf3, 0x004ef41a
push 66h: 0x004eae84, 0x004edde4, 0x004ef1ed, 0x004ef474
```

The `0x004ef41a` and `0x004ef474` sites are inside the newly observed raw helpers. The inline `0x004ef1ed` opcode `0x66` sender is inside `InventoryPane2::OnMouseEvent`, further tying the `0x004ef460` raw helper to InventoryPane2 rather than BackPane.

## 5. Negative Evidence

- No MCP evidence supports treating `0x004ee6b0` as a generic setup helper; it is destructor-shaped and has scalar-deleting-wrapper corroboration at `0x004efa40`.
- No direct xrefs were found to `0x004ef400` or `0x004ef460`, but their byte patterns, placement, sibling inventory-pane analogs, and opcodes are positive evidence for retained InventoryPane2 raw helpers.
- No evidence supports assigning the `0x004ef400-0x004ef50b` raw helpers to BackPane. BackPane V3 starts at `0x004ef510`.
- No evidence supports assigning the raw packet builders to PacketBuffer, Socket, or protocol infrastructure ownership. PacketBuffer byte writes and queue/send calls are dependencies, not source ownership.
- No evidence supports a separate `InventoryPane2.cpp` split at this time. The existing file/class docs already route InventoryPane and InventoryPane2 to the InventoryPane source family, while NewInventoryPane and ScrollInventoryPane remain separate.
- No evidence supports a monolithic formal C++ block for the current aggregate parent. It would mix unrelated routines, compiler padding/tables, and raw retained helpers.

## 6. Heuristic Reanalysis and Resolved Open Questions

### Source Split

InventoryPane2 should remain under [UID:0000KA] InventoryPane source ownership, with likely source placement in the existing InventoryPane file family:

```text
NexusTK/ui/inventory/InventoryPane.cpp
```

This matches current `by-file/InventoryPane.md`, `by-class/InventoryPane2.md`, and `by-memory/0x004ea130-0x004efbb7.InventoryPanes.md` routing. The new raw helpers are local InventoryPane2 helpers, not a reason to create a separate file.

### Helper Ownership

Recommended helper ownership:

| Address / range | Ownership |
|---|---|
| `0x004ee6b0` | InventoryPane2 destructor source body |
| `0x004ee6d0` | InventoryPane2 local embedded-child refresh forwarder |
| `0x004ee6e0` | InventoryPane2 source-empty virtual |
| `0x004ee6f0` | InventoryPane2 paint handler |
| `0x004eee60` | InventoryPane2 key handler |
| `0x004eeee0-0x004ef290` | InventoryPane2 mouse handler including owned switch table |
| `0x004ef290` | InventoryPane2 server/message handler |
| `0x004ef400-0x004ef460` | InventoryPane2 retained raw use-item packet helper |
| `0x004ef460-0x004ef50b` | InventoryPane2 retained raw drag/drop packet helper |
| `0x004ef630`, `0x004ef890`, `0x004ef970` | InventoryPane2 tail helper children already covered by the tail split |
| `0x004efa40` | scalar deleting destructor wrapper/compiler glue |

### Field Names and Meanings

The current open field questions can be resolved to source-quality names or bounded descriptive names:

| Complete-object offset | Evidence-backed meaning | Recommended name |
|---|---|---|
| `+0x44` | embedded pane bounds/subpane argument passed to refresh/paint helpers | `m_embeddedPaneBounds` |
| `+0x70` | draw/text state selector set to `1` during item rendering and `2` during button rendering | keep descriptive until shared base type is named, e.g. `m_drawState` |
| `+0xf8` | current page index; decremented/incremented by key handler; used by paint pagination | `m_pageIndex` |
| `+0xf9` | true when no later non-empty inventory item exists; page-down only when false | `m_isLastPage` |
| `+0xfc` | view mode; `0` is list, nonzero is grid | `m_viewMode` |
| `+0x104` | list-view selector button visual state; `0` normal, `1` hover, `2` pressed; paint uses `3 * state` | `m_listButtonState` |
| `+0x108` | grid-view selector button visual state; `0` normal, `1` hover, `2` pressed; paint uses `3 * state + 1` | `m_gridButtonState` |

Do not use `m_hasNextPage` for `+0xf9`; the observed semantics are inverted. The source-quality name should express the stored truth value as last-page/no-next-page.

### Packet and Drag Helpers

`0x004ef400-0x004ef460` writes opcode `0x1c`, one selected-slot byte, and sends a 2-byte packet. This matches the retained raw helper family represented by `SendUseItemSlotPacketRaw`.

`0x004ef460-0x004ef50b` writes opcode `0x66`, source/event bytes, the selected inventory slot, and fixed flag bytes, then sends a 10-byte packet. It matches the inline drag/drop send path in `InventoryPane2::OnMouseEvent` and the sibling raw-helper shape in earlier inventory panes.

Both helpers should be documented as InventoryPane2-owned retained raw helpers even though MCP reports no direct xrefs.

### Selector Notification Fields

The selector/button fields are not independent external notification state. In this target they are local view/button state:

- `+0xfc` selects list vs grid view.
- `+0x104` and `+0x108` store list/grid selector button visual state.
- key and mouse handlers refresh through the pane virtual slot after state changes.

This amendment supersedes the earlier up/down or previous/next wording. The mouse handler proves the two selector buttons change `+0xfc`: button id `2` sets list mode (`m_viewMode = 0`) and presses `m_listButtonState`; button id `3` sets grid mode (`m_viewMode = 1`) and presses `m_gridButtonState`. They are not page-up/page-down buttons.

## 7. First-Draft C++ / No-Code Proof

The current aggregate parent should have no formal C++ block after implementation because it is a split/index parent. This is a no-code proof, not an unresolved blocker:

- The parent contains multiple independent source routines and raw helper spans.
- The parent also contains compiler-owned padding and at least one switch table span.
- Exact source routines can be represented by child pages.
- A parent-level aggregate C++ block would duplicate or conflate child semantics.

Recommended parent formal `RECONSTRUCTION_CPP CODE` disposition:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The inline value and multiline block both remain blank. The no-code proof is that this page is a split/index parent over multiple child routines, compiler padding, an owned switch table, and retained raw helpers; child pages carry formal C++ or no-code proof. The one-byte `0x004ee6e0` virtual should receive its own no-code child proof. The raw packet helpers should receive raw-helper child pages, not be folded into the parent body.

## 8. Proposed Child Split for Implementation Callback

Recommended exact children for the repaired parent:

| Proposed child range | Proposed role |
|---|---|
| `0x004ee6b0-0x004ee6cf` | `InventoryPane2Destructor` |
| `0x004ee6cf-0x004ee6d0` | one-byte padding |
| `0x004ee6d0-0x004ee6dc` | `InventoryPane2RefreshEmbeddedPane` / forwarder |
| `0x004ee6dc-0x004ee6e0` | padding |
| `0x004ee6e0-0x004ee6e1` | `InventoryPane2SourceEmptyVirtual` |
| `0x004ee6e1-0x004ee6f0` | padding |
| `0x004ee6f0-0x004eee5c` | `InventoryPane2OnPaint` |
| `0x004eee5c-0x004eee60` | padding |
| `0x004eee60-0x004eeedc` | `InventoryPane2OnKeyEvent` |
| `0x004eeedc-0x004eeee0` | padding |
| `0x004eeee0-0x004ef290` | `InventoryPane2OnMouseEvent`, including owned switch table/alignment |
| `0x004ef290-0x004ef3fc` | `InventoryPane2OnServerMessage` / item-help packet handler |
| `0x004ef3fc-0x004ef400` | padding |
| `0x004ef400-0x004ef460` | `InventoryPane2SendUseItemSlotPacketRaw` |
| `0x004ef460-0x004ef50b` | `InventoryPane2SendDragDropItemPacketRaw` |
| `0x004ef50b-0x004ef510` | padding before BackPane V3 |

If validator policy requires switch tables to be separate non-emitting spans, split `0x004ef27a-0x004ef290` out of `InventoryPane2OnMouseEvent`; otherwise accepted local precedent supports including an owned method jump table inside the method child range.

## 9. Accepted Precedent Applied

`by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` is the closest accepted precedent. It is a non-emitting split/index parent over exact child pages for a pane core/helper cluster, including raw constructor/destructor material, source-empty virtuals, paint/key/mouse/message handlers, raw packet helpers, geometry helpers, hit-test helpers, and mapper helpers.

`0002SU` should follow the same pattern. This is not a lower-confidence workaround; it is the local source-quality shape for pane clusters with multiple owned routines.

## 10. Initial Implementation Notes (Superseded By Final Checklist)

For supervisor callback implementation:

1. Confirm MCP session health remains `ok` before editing.
2. Path-update or recreate the parent as `by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md`.
3. Convert the parent to non-emitting split/index metadata: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:00006S`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
4. Add prose no-code proof for the parent-level C++ block and leave the parent formal C++ blank.
5. Create exact child pages for destructor, forwarder, source-empty virtual, paint, key, mouse, server/message, use-item raw packet helper, and drag/drop raw packet helper.
6. Route all reconstructable source children to owner/emitter `00006S`; route source-empty/compiler-only children with blank emitter/reconstructability as appropriate.
7. Add padding spans to the ignored/padding documentation or parent map, according to current validator convention.
8. Update `by-memory/0x004ea130-0x004efbb7.InventoryPanes.md`, `by-class/InventoryPane2.md`, and `by-file/InventoryPane.md` to reference the repaired parent range and new children.
9. Keep BackPane V3 starting at `0x004ef510`; do not absorb it into InventoryPane2.
10. Run scoped validators only after edits; do not run broad generated-state mutations manually.

Suggested scoped validation command after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0002SU-InventoryPane2CoreAndHelpers-source-quality-removed.md](0002SU-InventoryPane2CoreAndHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Then validate each new exact child file and the touched support pages with the same file-scoped mode.

## 11. Residual Risk

The remaining uncertainty is limited to unprovable original spelling for the chosen source-facing names. Implementation should still use `RefreshEmbeddedPane`, `m_embeddedPaneBounds`, `m_viewMode`, `m_listButtonState`, and `m_gridButtonState`; the alternate names are rejected/search aliases only. MCP behavior is strong enough for implementation-quality names and for the split/range/ownership decisions above. No further pass is needed before implementation to decide field ownership, helper ownership, source placement, range repair, child C++ disposition, or parent no-code treatment.

## 12. Rule 26 Amendment: Fresh MCP Recheck And Chosen Implementation Names

Amendment recheck used live IDA MCP session `398b87c1` again. `server_health` reported `status: ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`. The active `decompile` schema requires one `addr` per call; the first multi-address attempt returned an invalid-params schema error, not an MCP availability failure, and the calls were retried with the active schema.

Fresh read-only MCP facts used for this amendment:

- `lookup_funcs` reconfirmed modeled functions at `0x004ee6b0`, `0x004ee6d0`, `0x004ee6e0`, `0x004ee6f0`, `0x004eee60`, `0x004eeee0`, and `0x004ef290`; `0x004ef3fc`, `0x004ef400`, and `0x004ef460` are not functions; `0x004ef510` is `sub_4EF510`.
- `xrefs_to` reconfirmed vtable/data refs from `0x0061c8b8`, `0x0061c8b4`, `0x0061c8c8`, `0x0061c8c4`, and `0x0061c8d0` for the InventoryPane2 virtual methods, and no xrefs to `0x004ef400` or `0x004ef460`.
- `decompile` reconfirmed the destructor body, refresh forwarder, source-empty virtual, paint, key, mouse, message handler, tail button-rect helper, slot hit-test, visible-index mapper, and scalar deleting destructor wrapper.
- `insn_query` over `0x004ef400-0x004ef50b` reconfirmed the two raw packet helpers: opcode `0x1c` with send length `2`, then opcode `0x66` with send length `10`.

### Chosen Implementation Names

The implementation should use one source-facing name for each resolved item. Plausible aliases are listed only as rejected/search aliases.

| Item | Implementation name | Rejected or search aliases | Reason |
| --- | --- | --- | --- |
| `0x004ee6d0` helper | `InventoryPane2::RefreshEmbeddedPane` | `ForwardChildRefresh`, `RefreshChildPane` | The helper forwards the pane refresh/invalidation virtual slot using the embedded bounds/subpane at `this + 0x44`; `RefreshEmbeddedPane` describes the source role without exposing vtable mechanics. |
| `+0xfc` | `m_viewMode` | `m_gridMode` | The stored value is an enum-like list/grid selector, not only a boolean grid flag. `0` means list, `1` means grid in observed paths. |
| `+0x104` | `m_listButtonState` | `m_upButtonState`, `m_prevButtonState` | Mouse button id `2` sets list mode and this state. The earlier up/down wording is rejected. |
| `+0x108` | `m_gridButtonState` | `m_downButtonState`, `m_nextButtonState` | Mouse button id `3` sets grid mode and this state. The earlier up/down wording is rejected. |
| `0x004ef400` raw helper | `InventoryPane2::SendUseItemSlotPacketRaw` | `SendUsePacketRaw`, `SendItemActionPacketRaw` | The body writes opcode `0x1c`, one inventory-slot byte, and sends length `2`, matching the local use-item packet-helper family. |
| `0x004ef460` raw helper | `InventoryPane2::SendDragDropItemPacketRaw` | `SendDragDropPacketRaw`, `SendMoveItemPacketRaw` | The body writes opcode `0x66`, an event/source byte, the inventory slot, fixed flags, and sends length `10`, matching the drag/drop branch in `OnMouseEvent`. |
| `0x004ef290` message handler | `InventoryPane2::OnServerMessage` | `HandleItemHelpPacket` | It is vtable-reached from the pane message slot and only one branch handles item-help opcode `0x59`; the method name should stay event-handler level. |

## 13. Rule 26 Amendment: Exact Child Manifest

New child UIDs should be validator-allocated. Do not copy `0002SU` into child files. Create the child files with the exact metadata below except for UID, scan each child with the scoped validator to allocate/register its UID, then use the assigned child UIDs in parent/support references.

| Intended file path | Range | Role/name | Completion | Confidence | Canonical owner | Reconstructable | Emitters | C++ / no-code disposition | Support docs that must reference it |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x004ee6b0-0x004ee6cf.InventoryPane2Destructor.md` | `0x004ee6b0-0x004ee6cf` | non-deleting `InventoryPane2::~InventoryPane2` body | `90` | `92` | `00006S` | `TRUE` | `00006S` | formal destructor C++ supplied below | parent `0002SU`, `InventoryPanes`, `InventoryPane2`, `InventoryPane`, tail scalar destructor doc |
| `by-memory/0x004ee6d0-0x004ee6dc.InventoryPane2RefreshEmbeddedPane.md` | `0x004ee6d0-0x004ee6dc` | `InventoryPane2::RefreshEmbeddedPane` | `87` | `90` | `00006S` | `TRUE` | `00006S` | formal helper C++ supplied below | parent `0002SU`, `InventoryPanes`, `InventoryPane2`, `InventoryPane`, vtable/read-only data docs |
| `by-memory/0x004ee6e0-0x004ee6e1.InventoryPane2SourceEmptyVirtual.md` | `0x004ee6e0-0x004ee6e1` | source-empty virtual/no-op | `86` | `92` | `00006S` | `FALSE` | blank | exact no-code proof supplied below | parent `0002SU`, `InventoryPanes`, `InventoryPane2`, vtable/read-only data docs |
| `by-memory/0x004ee6f0-0x004eee5c.InventoryPane2OnPaint.md` | `0x004ee6f0-0x004eee5c` | `InventoryPane2::OnPaint` | `89` | `91` | `00006S` | `TRUE` | `00006S` | formal paint C++ supplied below | parent `0002SU`, `InventoryPanes`, `InventoryPane2`, `InventoryPane`, tail helper docs by reference |
| `by-memory/0x004eee60-0x004eeedc.InventoryPane2OnKeyEvent.md` | `0x004eee60-0x004eeedc` | `InventoryPane2::OnKeyEvent` | `89` | `91` | `00006S` | `TRUE` | `00006S` | formal key C++ supplied below | parent `0002SU`, `InventoryPanes`, `InventoryPane2`, `InventoryPane`, vtable/read-only data docs |
| `by-memory/0x004eeee0-0x004ef290.InventoryPane2OnMouseEvent.md` | `0x004eeee0-0x004ef290` | `InventoryPane2::OnMouseEvent`, including owned switch table/alignment | `89` | `91` | `00006S` | `TRUE` | `00006S` | formal mouse C++ supplied below | parent `0002SU`, `InventoryPanes`, `InventoryPane2`, `InventoryPane`, tail helper docs, packet helper children |
| `by-memory/0x004ef290-0x004ef3fc.InventoryPane2OnServerMessage.md` | `0x004ef290-0x004ef3fc` | `InventoryPane2::OnServerMessage` | `89` | `91` | `00006S` | `TRUE` | `00006S` | formal message C++ supplied below | parent `0002SU`, `InventoryPanes`, `InventoryPane2`, `InventoryPane`, vtable/read-only data docs |
| `by-memory/0x004ef400-0x004ef460.InventoryPane2SendUseItemSlotPacketRaw.md` | `0x004ef400-0x004ef460` | retained raw `InventoryPane2::SendUseItemSlotPacketRaw` | `88` | `91` | `00006S` | `TRUE` | `00006S` | formal raw-helper C++ supplied below | repaired parent `0002SU`, `InventoryPanes`, `InventoryPane2`, `InventoryPane`, `OnMouseEvent` child |
| `by-memory/0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw.md` | `0x004ef460-0x004ef50b` | retained raw `InventoryPane2::SendDragDropItemPacketRaw` | `88` | `91` | `00006S` | `TRUE` | `00006S` | formal raw-helper C++ supplied below | repaired parent `0002SU`, `InventoryPanes`, `InventoryPane2`, `InventoryPane`, `OnMouseEvent` child |

Padding spans to record in the repaired parent and, if convention requires, in ignored/padding docs:

| Range | Disposition |
| --- | --- |
| `0x004ee6cf-0x004ee6d0` | one-byte alignment after destructor body |
| `0x004ee6dc-0x004ee6e0` | four-byte alignment before source-empty virtual |
| `0x004ee6e1-0x004ee6f0` | alignment before paint method |
| `0x004eee5c-0x004eee60` | alignment before key method |
| `0x004eeedc-0x004eeee0` | alignment before mouse method |
| `0x004ef3fc-0x004ef400` | alignment before raw packet helpers |
| `0x004ef50b-0x004ef510` | alignment before BackPane V3 start |

## 14. Rule 26 Amendment: Child Formal RECONSTRUCTION_CPP CODE

These are exact formal block contents for the proposed child pages. The names are inferred source-facing names, not original-symbol proof; they are still implementation names for this callback.

### `InventoryPane2Destructor`

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
InventoryPane2::~InventoryPane2()
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `InventoryPane2RefreshEmbeddedPane`

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int InventoryPane2::RefreshEmbeddedPane()
{
    return Invalidate(&m_embeddedPaneBounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `InventoryPane2SourceEmptyVirtual`

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

No-code proof: the entire body is one byte, `retn`, with no stores, calls, reads, arguments, packet effects, global effects, resource effects, or nested data. `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank inline `RECONSTRUCTION_CPP CODE`, and blank multiline block are intentional, matching the accepted `SpellInventoryPane2SourceEmptyVirtual` precedent.

### `InventoryPane2OnPaint`

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void InventoryPane2::OnPaint()
{
    EpfFrame frame;
    EpfFrame buttonFrame;
    Rect itemRect;
    int visibleOrdinal = 0;
    int drawnCount = 0;
    int slot = 1;
    const int pageSize = (m_viewMode == kInventoryViewGrid) ? kInventoryGridPageSlots : kInventoryListPageSlots;

    LoadEpfFrame(g_pEPFLib, L"IT", (m_viewMode == kInventoryViewGrid) ? 0 : 1, &frame);
    DrawEpfFrame(frame, m_embeddedPaneBounds, L"IT");

    while (slot <= g_pInventoryState->inventorySlotCount)
    {
        const InventorySlotRecord& item = g_pUserPane->GetInventorySlotRecord(slot);
        if (item.itemId != 0 && ++visibleOrdinal > m_pageIndex * pageSize)
            break;
        ++slot;
    }

    m_drawState = kInventoryDrawItems;

    if (m_viewMode == kInventoryViewGrid)
    {
        SetPoint(&itemRect, 21, 12);
        int column = 0;

        for (; slot <= g_pInventoryState->inventorySlotCount && drawnCount < kInventoryGridPageSlots; ++slot)
        {
            const InventorySlotRecord& item = g_pUserPane->GetInventorySlotRecord(slot);
            if (item.itemId == 0)
                continue;

            DrawInventoryGridItem(itemRect, item);
            DrawInventoryHotkey(itemRect.left + 1, itemRect.top + 11, SlotIndexToHotkeyLetter(slot));

            ++drawnCount;
            column = (column + 1) % 3;
            itemRect.left = 12 + 51 * column;
            if (column == 0)
                itemRect.top += 51;
        }
    }
    else
    {
        SetPoint(&itemRect, 30, 15);

        for (; slot <= g_pInventoryState->inventorySlotCount && drawnCount < kInventoryListPageSlots; ++slot)
        {
            const InventorySlotRecord& item = g_pUserPane->GetInventorySlotRecord(slot);
            if (item.itemId == 0)
                continue;

            DrawInventoryListItem(itemRect, item);
            DrawInventoryHotkey(itemRect.left + 24, itemRect.top, SlotIndexToHotkeyLetter(slot));
            DrawText(item.name);

            ++drawnCount;
            itemRect.top += 26;
            itemRect.left = 15;
        }
    }

    m_isLastPage = true;
    for (++slot; slot <= g_pInventoryState->inventorySlotCount; ++slot)
    {
        if (g_pUserPane->GetInventorySlotRecord(slot).itemId != 0)
            m_isLastPage = false;
    }

    SetTextColor(kInventoryTextColor);
    m_drawState = kInventoryDrawButtons;

    BuildButtonRect(kInventoryListViewButton, &itemRect);
    LoadEpfFrame(g_pEPFLib, L"BU", 3 * m_listButtonState, &buttonFrame);
    DrawEpfFrame(buttonFrame, itemRect, L"BU");

    BuildButtonRect(kInventoryGridViewButton, &itemRect);
    LoadEpfFrame(g_pEPFLib, L"BU", 3 * m_gridButtonState + 1, &buttonFrame);
    DrawEpfFrame(buttonFrame, itemRect, L"BU");
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `InventoryPane2OnKeyEvent`

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool InventoryPane2::OnKeyEvent(PaneKeyEvent *event)
{
    if (event->eventKind != kPaneKeyDown || event->imeActive)
        return false;

    const int key = NarrowInputEventByte(event);

    if (key == kPaneKeyPageUp)
    {
        if (m_pageIndex > 0)
        {
            --m_pageIndex;
            RefreshEmbeddedPane();
        }
        return true;
    }

    if (key == kPaneKeyPageDown)
    {
        if (!m_isLastPage)
        {
            ++m_pageIndex;
            RefreshEmbeddedPane();
        }
        return true;
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `InventoryPane2OnMouseEvent`

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool InventoryPane2::OnMouseEvent(PaneMouseEvent *event)
{
    Rect rect;

    if (g_pUserPane->IsInputLocked())
        return false;

    switch (event->eventKind)
    {
    case kPaneMouseMove:
        if (!PtInRect(m_embeddedPaneBounds, event->x, event->y))
        {
            m_listButtonState = kButtonNormal;
            m_gridButtonState = kButtonNormal;
            return false;
        }

        BuildButtonRect(kInventoryListViewButton, &rect);
        if (PtInRect(rect, event->x, event->y))
        {
            m_listButtonState = kButtonHover;
            m_gridButtonState = kButtonNormal;
            RefreshEmbeddedPane();
            return true;
        }

        BuildButtonRect(kInventoryGridViewButton, &rect);
        if (PtInRect(rect, event->x, event->y))
        {
            m_listButtonState = kButtonNormal;
            m_gridButtonState = kButtonHover;
            RefreshEmbeddedPane();
            return true;
        }

        if (m_listButtonState != kButtonNormal || m_gridButtonState != kButtonNormal)
        {
            m_listButtonState = kButtonNormal;
            m_gridButtonState = kButtonNormal;
            RefreshEmbeddedPane();
        }
        return false;

    case kPaneMouseDown:
        for (int button = 0; button < kInventoryButtonCount; ++button)
        {
            BuildButtonRect(button, &rect);
            if (!PtInRect(rect, event->x, event->y))
                continue;

            if (button == kInventoryListViewButton)
            {
                m_viewMode = kInventoryViewList;
                m_listButtonState = kButtonPressed;
                m_gridButtonState = kButtonNormal;
                RefreshEmbeddedPane();
                return true;
            }

            if (button == kInventoryGridViewButton)
            {
                m_viewMode = kInventoryViewGrid;
                m_listButtonState = kButtonNormal;
                m_gridButtonState = kButtonPressed;
                RefreshEmbeddedPane();
                return true;
            }
            break;
        }

        if (g_pClientOptions->doubleClickInventoryUse)
            return false;
        break;

    case kPaneMouseDoubleClick:
        if (!g_pClientOptions->doubleClickInventoryUse)
            return false;
        break;

    case kPaneMouseDragDrop:
    {
        const int hitSlot = HitTestSlot(event->x, event->y);
        if (hitSlot > kInventoryMouseHitMaxSlot)
            return false;

        const int inventorySlot = VisibleIndexToInventorySlot(hitSlot + kInventoryMousePageSlots * m_pageIndex + 1);
        if (inventorySlot == -1)
            return false;

        SendDragDropItemPacketRaw(static_cast<unsigned char>(inventorySlot), event->dragSource);
        return true;
    }

    default:
        return false;
    }

    const int hitSlot = HitTestSlot(event->x, event->y);
    if (hitSlot > kInventoryMouseHitMaxSlot)
        return false;

    const int inventorySlot = VisibleIndexToInventorySlot(hitSlot + kInventoryMousePageSlots * m_pageIndex + 1);
    if (inventorySlot == -1)
        return false;

    UseInventorySlotDispatch(g_pUserPane, inventorySlot);
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `InventoryPane2OnServerMessage`

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool InventoryPane2::OnServerMessage(ServerPaneMessage *message)
{
    const unsigned char *packet = message->payload;
    const unsigned char opcode = packet[0];

    if (opcode < 0x0f)
        return false;

    if (opcode <= 0x10)
    {
        NotifyPaneMessageHandled(false);
        return false;
    }

    if (opcode != 0x59 || packet[1] != 0)
        return false;

    const unsigned char side = packet[2];
    const unsigned short textLength = ReadPacketUInt16(packet + 3);
    if (textLength >= 1 && textLength <= 1023)
    {
        wchar_t helpText[1024];
        const unsigned int chars = MultiByteToWideChar(0, 0, reinterpret_cast<const char *>(packet + 5), textLength, helpText, 1023);
        helpText[chars] = 0;

        Rect bounds;
        GetBounds(&bounds);

        if (g_pActiveSimpleHelpPane != NULL)
            g_pActiveSimpleHelpPane->Close(true);

        new SimpleHelpPane(helpText, this, (bounds.left + bounds.right) / 2, side, 10000);
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `InventoryPane2SendUseItemSlotPacketRaw`

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void InventoryPane2::SendUseItemSlotPacketRaw(unsigned char inventorySlot)
{
    unsigned char packet[3];

    WritePacketByte(packet, 0x1c);
    WritePacketByte(packet + 1, inventorySlot);
    packet[2] = 0;

    g_pPacketSender->Send(packet, 2);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `InventoryPane2SendDragDropItemPacketRaw`

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void InventoryPane2::SendDragDropItemPacketRaw(unsigned char inventorySlot, unsigned char dragSource)
{
    unsigned char packet[10];

    WritePacketByte(packet, 0x66);
    WritePacketByte(packet + 1, 0);
    WritePacketByte(packet + 2, dragSource);
    WritePacketByte(packet + 3, 0);
    WritePacketByte(packet + 4, 1);
    WritePacketByte(packet + 5, 1);
    WritePacketByte(packet + 6, inventorySlot);
    WritePacketByte(packet + 7, 1);
    WritePacketByte(packet + 8, 0);
    WritePacketByte(packet + 9, 0);

    g_pPacketSender->Send(packet, 10);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## 15. Rule 26 Amendment: Exact Support-Doc Incorporation

Apply these facts at report-level detail during the implementation callback. Use validator-allocated UIDs for new child links after the child files are scanned.

| File | Exact incorporation instructions |
| --- | --- |
| `by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md` | Rename/move the existing `0002SU` file to this path, preserving UID `0002SU`. Change metadata to `90/92`, `CANONICAL_OWNER:00006S`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`. Update title/range/summary/covered-range map to include `0x004ef3fc-0x004ef510`. Add split/index parent no-code proof and child manifest. Record padding spans and the rejected old end at `0x004ef3fc`. Remove/supersede the old "final C++ needs names" blocker with chosen names and child C++ dispositions. Keep BackPane V3 start at `0x004ef510`. |
| `by-memory/0x004ea130-0x004efbb7.InventoryPanes.md` | Replace the old `InventoryPane2` core child range `0x004ee6b0-0x004ef3fc` with repaired `0x004ee6b0-0x004ef510`. Add the nine exact child pages and padding spans. State `0x004ef400` and `0x004ef460` are InventoryPane2 raw packet helpers, not BackPane. Keep BackPane V3 beginning at `0x004ef510` and tail helpers beginning at `0x004ef630`. |
| `by-class/InventoryPane2.md` | Add the new method/helper inventory with names `~InventoryPane2`, `RefreshEmbeddedPane`, source-empty virtual, `OnPaint`, `OnKeyEvent`, `OnMouseEvent`, `OnServerMessage`, `SendUseItemSlotPacketRaw`, and `SendDragDropItemPacketRaw`. Add field names `m_embeddedPaneBounds`, `m_drawState`, `m_pageIndex`, `m_isLastPage`, `m_viewMode`, `m_listButtonState`, and `m_gridButtonState`. State the class remains owned/emitted by `00006S`, while `0002SU` becomes a non-emitting index parent. |
| `by-file/InventoryPane.md` | Keep InventoryPane2 under the existing InventoryPane source family at `NexusTK/ui/inventory/InventoryPane.cpp`. Add the new child method/helper list under the InventoryPane2 contents. State `InventoryPane2.cpp` is rejected for now because current class/file docs and sibling panes support the existing InventoryPane file family. Add the two raw packet helpers as InventoryPane2-local helpers, with PacketBuffer/socket code listed as dependencies only. |
| `by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md` | Update forward/cross-reference text so the next InventoryPane2 core parent is `0x004ee6b0-0x004ef510`, not the old `0x004ee6b0-0x004ef3fc`. Preserve the constructor as a separate raw child and do not merge it into `0002SU`. |
| `by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md` | Update upstream references from the old core range to `0x004ee6b0-0x004ef510`. Add a note that the ordinary non-deleting destructor body is now the child at `0x004ee6b0-0x004ee6cf`, while `0x004efa40-0x004efa95` remains the scalar deleting destructor wrapper/compiler helper. |
| `by-memory/0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor.md` | Add the same destructor relationship note: `0x004ee6b0-0x004ee6cf` is the source destructor body, and this page is the scalar deleting wrapper that repeats vtable/base cleanup before optional free. Keep it separate and do not make it the primary destructor body. |
| `by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md` and `by-memory/0x0061c86c-0x0061c8f8.InventoryPane2VtableData.md` | Update InventoryPane2 vtable slot descriptions, where present, to reference the new child pages and chosen names. No range extension is needed here; this is a name/reference incorporation only. |
| Exact tail helper children `InventoryPane2ButtonRectHelper`, `InventoryPane2SlotHitTest`, and `InventoryPane2VisibleIndexToInventorySlot` | No range change required. If touched for references, only add backward references from `OnPaint`/`OnMouseEvent` and preserve current tail-child ownership. Do not rename these files as part of this callback. |

No manual `-coverage-report.md` edit is authorized or needed. Do not supply row text for validator-owned `auto-generated/-ag-*` reports. Source metadata and validator execution should refresh generated coverage/tracker views.

## 16. Rule 26 Amendment: Rename and Validator Lifecycle

Implementation should rename the existing file, not create a replacement copy while the old file remains:

1. During callback only, lease the existing parent and support docs for the immediate edit batch.
2. Move `by-memory/0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers.md` to `by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md`.
3. Preserve the existing `*** UID:0002SU | DO NOT MODIFY OR REMOVE!!! ***` header in the moved file.
4. Do not create a second file with UID `0002SU`; the validator protects against duplicate UID path conflicts when the old path still exists.
5. Create child files without hand-allocating UIDs; let the scoped validator assign/register UIDs for each new child.
6. After child UIDs are allocated, update parent/support references to those UIDs and run scoped validators.
7. Do not edit `tools/validator.ini`, queue state, generated reports, or tracker rows manually.
8. If the file-scoped validator scan of the moved parent reports stale old-path registry state, use the documented validator lifecycle command `python .\tools\validator.py --mode documented --remove-missing --apply --queue-timeout 240` rather than hand-editing validator state. This is conditional cleanup, not a routine first command.
9. The stale tracker row (`80/86`) should be refreshed by validator lifecycle and final supervisor `execute_report`; do not manually edit `auto-generated/-ag-research-tracker.md`.

Exact scoped validator commands to run from `E:\NTK\GhidraBridge\source-3\project-documentation` after implementation edits:

> Executable block R002 was removed from this report and preserved verbatim in [0002SU-InventoryPane2CoreAndHelpers-source-quality-removed.md](0002SU-InventoryPane2CoreAndHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Conditional lifecycle cleanup only if the scoped scans report stale missing old-path registry entries:

> Executable block R003 was removed from this report and preserved verbatim in [0002SU-InventoryPane2CoreAndHelpers-source-quality-removed.md](0002SU-InventoryPane2CoreAndHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After supervisor verification, the supervisor-owned report execution command should be:

> Executable block R004 was removed from this report and preserved verbatim in [0002SU-InventoryPane2CoreAndHelpers-source-quality-removed.md](0002SU-InventoryPane2CoreAndHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

That execution, plus normal validator generated refresh, should refresh `auto-generated/-ag-research-tracker.md` and generated coverage rows. Agents must not edit those generated files manually.

## Implementation Tracking Checklist

Implementation callback proof pass completed by B013 on 2026-06-27 EDT / 2026-06-28 UTC. B013 did not run `execute_report`, did not move/archive this report, did not manually edit generated reports, project-level generated files, manual `-coverage-report.md` files, validator/tool state, or the IDA DB.

Live MCP proof for implementation verification: existing session `b001_000241_20260627` reported `server_health` `status:"ok"`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`. `lookup_funcs` matched the accepted split facts: no function at `0x004ee650`, functions at `0x004ee6b0`, `0x004ee6d0`, `0x004ee6e0`, `0x004ee6f0`, `0x004eee60`, `0x004eeee0`, `0x004ef290`, no function at `0x004ef3fc`, `0x004ef400`, or `0x004ef460`, and BackPane V3 function `sub_4EF510` at `0x004ef510`. `xrefs_to` showed vtable/data refs from `0x0061c8b8`, `0x0061c8b4`, `0x0061c8c8`, `0x0061c8c4`, and `0x0061c8d0`, with zero xrefs to `0x004ef400` and `0x004ef460`. `make_signature_for_range 0x004ef400-0x004ef50b` captured the raw helper bytes containing opcode `0x1c`/send length `2` and opcode `0x66`/send length `10`.

Lease proof: the starting and final `tools/leaser/Agents/Agent-B013/current_leases.md` checks showed no `B013` rows. The lease report still contained only expired `Supervisor` rows created `2026-06-18T04:43:02Z` and expiring `2026-06-18T04:48:02Z`; no B013 interrupted-session lease was active or expired in the report. During validation B013 leased one by-* file at a time immediately before its validator command and unleased it immediately after; every lease and unlease returned `Success`.

Validator note: every scoped validator below was run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--apply --queue-timeout 240 --wait-generated`, exited `0`, reported `ok: 1`, and reported `generated_refresh: completed`. All validator runs also reported broad pre-existing generated registry diagnostics `autogen_registry_stale: 130` and `memory_coverage_metadata_missing_file: 129`; none reported the old `0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers.md` path (`old_path_stale_hit=no` for every captured run). B013 did not run the conditional `--remove-missing` lifecycle cleanup.

| File | command_id | command_timestamp | result |
| --- | --- | --- | --- |
| `by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md` | `000000004580` | `2026-06-27T21:27:42-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-memory/0x004ee6b0-0x004ee6cf.InventoryPane2Destructor.md` | `000000004581` | `2026-06-27T21:28:28-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-memory/0x004ee6d0-0x004ee6dc.InventoryPane2RefreshEmbeddedPane.md` | `000000004582` | `2026-06-27T21:28:39-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-memory/0x004ee6e0-0x004ee6e1.InventoryPane2SourceEmptyVirtual.md` | `000000004583` | `2026-06-27T21:28:50-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-memory/0x004ee6f0-0x004eee5c.InventoryPane2OnPaint.md` | `000000004584` | `2026-06-27T21:29:01-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-memory/0x004eee60-0x004eeedc.InventoryPane2OnKeyEvent.md` | `000000004585` | `2026-06-27T21:29:12-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-memory/0x004eeee0-0x004ef290.InventoryPane2OnMouseEvent.md` | `000000004586` | `2026-06-27T21:29:23-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-memory/0x004ef290-0x004ef3fc.InventoryPane2OnServerMessage.md` | `000000004587` | `2026-06-27T21:29:35-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-memory/0x004ef400-0x004ef460.InventoryPane2SendUseItemSlotPacketRaw.md` | `000000004588` | `2026-06-27T21:29:46-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-memory/0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw.md` | `000000004589` | `2026-06-27T21:29:57-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-memory/0x004ea130-0x004efbb7.InventoryPanes.md` | `000000004590` | `2026-06-27T21:30:28-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-class/InventoryPane2.md` | `000000004591` | `2026-06-27T21:30:40-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-file/InventoryPane.md` | `000000004592` | `2026-06-27T21:30:51-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md` | `000000004593` | `2026-06-27T21:31:02-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md` | `000000004594` | `2026-06-27T21:31:14-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-memory/0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor.md` | `000000004595` | `2026-06-27T21:31:26-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md` | `000000004596` | `2026-06-27T21:31:37-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-memory/0x0061c86c-0x0061c8f8.InventoryPane2VtableData.md` | `000000004597` | `2026-06-27T21:31:50-04:00` | exit `0`, `ok: 1`, generated refresh completed |
| `by-memory/-ignored.md` | `000000004598` | `2026-06-27T21:32:02-04:00` | exit `0`, `ok: 1`, generated refresh completed |

- [x] Supervisor validates amended B013 report `tools/leaser/Agents/Agent-B013/research/0002SU-InventoryPane2CoreAndHelpers-source-quality.md` before any by-* edit.
  - Proof: active `goal.md` callback override dated 2026-06-27 named this report as accepted implementation callback for [UID:0002SU].
- [x] During callback only, lease the current parent/support docs for the immediate edit batch; no leases are used during report-only research.
  - Proof: B013 used one-file immediate leases for every by-* validator command above and released each immediately; final lease report has no `B013` rows.
- [x] Rename/move `by-memory/0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers.md` to `by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md`, preserving UID `0002SU` and not creating a duplicate UID file.
  - Proof: old path no longer exists; new path exists with `*** UID:0002SU | DO NOT MODIFY OR REMOVE!!! ***`; validator `000000004580` passed and did not report old-path stale state.
- [x] Update moved parent `0002SU` metadata to `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:00006S`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank inline `RECONSTRUCTION_CPP CODE`, and blank multiline `RECONSTRUCTION_CPP CODE` block.
  - Proof: `by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md` header has those exact metadata values and blank formal C++; validator `000000004580` passed.
- [x] Update moved parent title, range, covered-range table, range-extension evidence, child manifest, padding spans, BackPane boundary at `0x004ef510`, rejected old end `0x004ef3fc`, positive/negative evidence, and split/index parent no-code proof.
  - Proof: parent sections `Covered Range`, `Exact Child Manifest`, `Fresh MCP Evidence`, `Chosen Source-Facing Names`, `No-Code Proof`, and `Rejected/Superseded Alternatives` contain those facts; validator `000000004580` passed.
- [x] Create `by-memory/0x004ee6b0-0x004ee6cf.InventoryPane2Destructor.md` with `90/92`, owner/emitter `00006S`, `RECONSTRUCTABLE:TRUE`, and the exact formal destructor `RECONSTRUCTION_CPP CODE` block from this report.
  - Proof: file exists as [UID:00048P], has `90/92`, owner/emitter `00006S`, `RECONSTRUCTABLE:TRUE`, and `InventoryPane2::~InventoryPane2()` formal C++; validator `000000004581` passed.
- [x] Create `by-memory/0x004ee6d0-0x004ee6dc.InventoryPane2RefreshEmbeddedPane.md` with `87/90`, owner/emitter `00006S`, `RECONSTRUCTABLE:TRUE`, chosen name `RefreshEmbeddedPane`, and the exact formal helper `RECONSTRUCTION_CPP CODE` block from this report.
  - Proof: file exists as [UID:00048Q] with `87/90`, owner/emitter `00006S`, `RECONSTRUCTABLE:TRUE`, `InventoryPane2::RefreshEmbeddedPane()`, and `m_embeddedPaneBounds`; validator `000000004582` passed.
- [x] Create `by-memory/0x004ee6e0-0x004ee6e1.InventoryPane2SourceEmptyVirtual.md` with `86/92`, owner `00006S`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++ block, and the exact one-byte `retn` no-code proof.
  - Proof: file exists as [UID:00048R] with `86/92`, owner `00006S`, `RECONSTRUCTABLE:FALSE`, blank emitter/formal C++, and one-byte `retn` no-code proof; validator `000000004583` passed.
- [x] Create `by-memory/0x004ee6f0-0x004eee5c.InventoryPane2OnPaint.md` with `89/91`, owner/emitter `00006S`, `RECONSTRUCTABLE:TRUE`, field names `m_viewMode`, `m_pageIndex`, `m_isLastPage`, `m_listButtonState`, `m_gridButtonState`, and the exact formal paint `RECONSTRUCTION_CPP CODE` block from this report.
  - Proof: file exists as [UID:00048S] with `89/91`, owner/emitter `00006S`, all listed field names, and formal `InventoryPane2::OnPaint()` C++; validator `000000004584` passed.
- [x] Create `by-memory/0x004eee60-0x004eeedc.InventoryPane2OnKeyEvent.md` with `89/91`, owner/emitter `00006S`, `RECONSTRUCTABLE:TRUE`, and the exact formal key-event `RECONSTRUCTION_CPP CODE` block from this report.
  - Proof: file exists as [UID:00048T] with `89/91`, owner/emitter `00006S`, and formal `InventoryPane2::OnKeyEvent(PaneKeyEvent *event)` C++; validator `000000004585` passed.
- [x] Create `by-memory/0x004eeee0-0x004ef290.InventoryPane2OnMouseEvent.md` with `89/91`, owner/emitter `00006S`, `RECONSTRUCTABLE:TRUE`, include owned switch table/alignment through `0x004ef290`, and insert the exact formal mouse-event `RECONSTRUCTION_CPP CODE` block from this report.
  - Proof: file exists as [UID:00048U] with `89/91`, owner/emitter `00006S`, owned switch table/alignment note, and formal `InventoryPane2::OnMouseEvent(PaneMouseEvent *event)` C++; validator `000000004586` passed.
- [x] Create `by-memory/0x004ef290-0x004ef3fc.InventoryPane2OnServerMessage.md` with `89/91`, owner/emitter `00006S`, `RECONSTRUCTABLE:TRUE`, and the exact formal server-message `RECONSTRUCTION_CPP CODE` block from this report.
  - Proof: file exists as [UID:00048V] with `89/91`, owner/emitter `00006S`, opcode `0x59` popup evidence, and formal `InventoryPane2::OnServerMessage(ServerPaneMessage *message)` C++; validator `000000004587` passed.
- [x] Create `by-memory/0x004ef400-0x004ef460.InventoryPane2SendUseItemSlotPacketRaw.md` with `88/91`, owner/emitter `00006S`, `RECONSTRUCTABLE:TRUE`, no direct xrefs documented, opcode `0x1c`, send length `2`, and the exact formal raw-helper `RECONSTRUCTION_CPP CODE` block from this report.
  - Proof: file exists as [UID:00048W] with `88/91`, owner/emitter `00006S`, no-direct-xref evidence, opcode `0x1c`, send length `2`, and formal `SendUseItemSlotPacketRaw` C++; validator `000000004588` passed.
- [x] Create `by-memory/0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw.md` with `88/91`, owner/emitter `00006S`, `RECONSTRUCTABLE:TRUE`, no direct xrefs documented, opcode `0x66`, send length `10`, and the exact formal raw-helper `RECONSTRUCTION_CPP CODE` block from this report.
  - Proof: file exists as [UID:00048X] with `88/91`, owner/emitter `00006S`, no-direct-xref evidence, opcode `0x66`, send length `10`, and formal `SendDragDropItemPacketRaw` C++; validator `000000004589` passed.
- [x] Record padding spans `0x004ee6cf-0x004ee6d0`, `0x004ee6dc-0x004ee6e0`, `0x004ee6e1-0x004ee6f0`, `0x004eee5c-0x004eee60`, `0x004eeedc-0x004eeee0`, `0x004ef3fc-0x004ef400`, and `0x004ef50b-0x004ef510` in the parent and/or ignored-padding docs according to current validator convention.
  - Proof: parent `Covered Range`/padding line and `by-memory/-ignored.md` include every listed padding span and child owner references `00048P`-`00048X`; validators `000000004580` and `000000004598` passed.
- [x] Update `by-memory/0x004ea130-0x004efbb7.InventoryPanes.md` with repaired parent range, new child list, new raw helper gap ownership, and unchanged BackPane V3 start at `0x004ef510`.
  - Proof: `InventoryPanes` records `0x004ee6b0-0x004ef510`, child UIDs `00048P`-`00048X`, raw helpers at `0x004ef400`/`0x004ef460`, and BackPane V3 at `0x004ef510`; validator `000000004590` passed.
- [x] Update `by-class/InventoryPane2.md` with new method/helper inventory, chosen helper names, chosen fields, raw packet helper ownership, and parent split/index disposition.
  - Proof: class page includes `~InventoryPane2`, `RefreshEmbeddedPane`, source-empty virtual, `OnPaint`, `OnKeyEvent`, `OnMouseEvent`, `OnServerMessage`, both raw packet helpers, fields `m_embeddedPaneBounds`, `m_drawState`, `m_pageIndex`, `m_isLastPage`, `m_viewMode`, `m_listButtonState`, and `m_gridButtonState`, and notes `0002SU` as non-emitting index parent; validator `000000004591` passed.
- [x] Update `by-file/InventoryPane.md` with InventoryPane2 source placement under `NexusTK/ui/inventory/InventoryPane.cpp`, rejected `InventoryPane2.cpp` split, new helper/method list, and PacketBuffer/socket dependencies as dependencies only.
  - Proof: file page records the existing `InventoryPane.cpp` family placement, rejects separate `InventoryPane2.cpp`, lists child UIDs `00048P`-`00048X`, and states PacketBuffer/socket sender APIs are dependencies only; validator `000000004592` passed.
- [x] Update `by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md` to reference the repaired next parent range and preserve constructor separation.
  - Proof: constructor page references [UID:0002SU] `0x004ee6b0-0x004ef510`, preserves raw constructor separation, and says not to merge it into `0002SU`; validator `000000004593` passed.
- [x] Update `by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md` with repaired upstream parent range and ordinary-destructor versus scalar-wrapper relationship.
  - Proof: tail page references the repaired upstream parent `0x004ee6b0-0x004ef510` and states [UID:00048P] is the ordinary non-deleting destructor body while `0x004efa40-0x004efa95` remains scalar deleting wrapper/compiler helper; validator `000000004594` passed.
- [x] Update `by-memory/0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor.md` to state `0x004ee6b0-0x004ee6cf` is the source destructor body and this page remains the scalar deleting wrapper/compiler helper.
  - Proof: scalar deleting destructor page includes that relationship note and remains separate; validator `000000004595` passed.
- [x] Update `by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md` and `by-memory/0x0061c86c-0x0061c8f8.InventoryPane2VtableData.md` with new child references and chosen vtable-slot names where present.
  - Proof: read-only data page names the InventoryPane2 vtable slot children; vtable data page links `00048Q`, `00048S`, `00048T`, `00048U`, `00048V`, and source destructor `00048P`; validators `000000004596` and `000000004597` passed.
- [x] Preserve negative evidence: no xrefs to `0x004ef400`/`0x004ef460`, no BackPane ownership for the raw helpers, no PacketBuffer/socket ownership for feature packet builders, no aggregate parent formal C++.
  - Proof: parent and raw helper pages preserve no-xref evidence, BackPane exclusion at `0x004ef510`, PacketBuffer/socket dependency-only wording, and blank aggregate parent formal C++; live MCP `xrefs_to` reconfirmed zero xrefs to `0x004ef400`/`0x004ef460`.
- [x] Preserve rejected/superseded assumptions: old target end `0x004ef3fc` as underbroad, previous up/down/prev/next button-state names as wrong for selector fields, `m_hasNextPage` as inverted, `InventoryPane2.cpp` as unsupported.
  - Proof: parent `Rejected/Superseded Alternatives`, class page field notes, and file page source-placement note preserve all four rejections.
- [x] Run the exact scoped validator commands listed in section 16 for the moved parent, every new child, and every touched support page, all from `E:\NTK\GhidraBridge\source-3\project-documentation`, each with `--apply --queue-timeout 240`.
  - Proof: table above lists every Section 16 file plus `by-memory/-ignored.md`; B013 added `--wait-generated` to keep generated freshness current.
- [x] If validator reports stale old-path registry state after the parent rename, run `python .\tools\validator.py --mode documented --remove-missing --apply --queue-timeout 240`; do not edit validator state manually.
  - Proof: not triggered. Every captured validator summary had `old_path_stale_hit=no`; no lifecycle cleanup or manual validator-state edit was performed.
- [x] Report validator `command_id`, `command_timestamp`, exit code, `ok` count, warnings, and generated-refresh state for each implementation validator command.
  - Proof: validator table and note above record command IDs/timestamps, exit `0`, `ok: 1`, generated refresh completed, and repeated broad diagnostics `autogen_registry_stale: 130` / `memory_coverage_metadata_missing_file: 129`.
- [x] Let normal validator generated refresh and supervisor `execute_report` refresh `auto-generated/-ag-research-tracker.md` and generated coverage; do not manually edit generated reports.
  - Proof: every validator command used validator-owned generated refresh with `generated_refresh: completed`; B013 did not manually edit generated reports. Final supervisor `execute_report` remains supervisor-owned.
- [ ] Supervisor executes the amended report only after claim-by-claim verification using `python .\tools\validator.py execute_report B013 0002SU-InventoryPane2CoreAndHelpers-source-quality.md 0002SU --apply`.
  - B013 status: intentionally not run. The by-* implementation and B013 checklist proof are complete and ready for supervisor verification/execution.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0002SU-InventoryPane2CoreAndHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0002SU-InventoryPane2CoreAndHelpers-source-quality.md","timestamp":"2026-06-27T21:37:55","uid":"0002SU"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002SU-InventoryPane2CoreAndHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0002SU-InventoryPane2CoreAndHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002SU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
