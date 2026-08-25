** TARGET-REPORT-UID:00033V **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00033V MixItemDialogSubmitPacketHelper Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:00033V] as a reconstructable source-bearing private/helper body owned and emitted by [UID:00008J] `MixItemDialog`, with source routed through [UID:0000KE] `ItemDialogs`.
- Final disposition: update the target from `85/86` to `88/89`; keep `CANONICAL_OWNER:00008J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008J`, and blank optional emitter position.
- Required action: after supervisor acceptance, update the target and support docs with the raw no-xref route proof, duplicate live `HandleAction` case-3 relationship, packet-byte semantics, field/helper names, first-draft C++, and exact pending coverage row below. Do not edit `by-memory/-coverage-report.md` directly.
- Confidence: high for behavior, range, owner, emitter route, packet format, and source-file family; medium-high for the original source-facing helper spelling because no symbol or direct caller survives and live IDA MCP was unavailable in this session.

## Target
- Target UID: `00033V`
- Target path: `source-3/project-documentation/by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/00033V-MixItemDialogSubmitPacketHelper-source-quality.md`
- Current scores and parent state: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:00008J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008J`; formal C++ is currently blank.
- Current target status issue: the doc has the right broad owner and packet summary, but it still treats the raw/no-function state and final names as a code-entry blocker. The current gate is the active 85/85 combined-score rule, so the source-quality pass should replace stale no-code reasoning with exact route evidence and a first-draft helper body.

## Supervisor Active Recheck
- Assignment was report-only. I did not edit target/support by-* docs and did not edit `by-memory/-coverage-report.md`.
- No split is recommended. The standalone range has a normal prologue, security cookie, loop, send, close calls, return, and nine-byte `0xcc` postpad before the next documented helper. It is a complete body plus padding, not a mixed aggregate.
- The target should not be merged into [UID:00033U] `MixItemDialogCore`: the core owns the action dispatcher and switch table, while this item owns the standalone retained helper island.

## Evidence Checked
- Existing docs:
  - `by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md`
  - `by-class/MixItemDialog.md`
  - `by-file/ItemDialogs.md`
  - `by-memory/0x004af570-0x004afb80.MixItemDialogCore.md`
  - `by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md`
  - `by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md`
  - `by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md`
  - `by-memory/0x004b0000-0x004b011d.AddMixingItemDialogConstructor.md`
  - `by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md`
  - `by-type/by-vtable/MixItemDialogVtables.md`
  - `by-memory/0x004b0870-0x004b0875.MixItemDialogSingletonClearHelper.md`
  - `by-memory/0x004b0880-0x004b0894.MixItemDialogDoubleParamCallback.md`
  - sibling raw helpers `0x004aeab0-0x004aebbc.AddItemDialogSubmitPacketHelper.md` and `0x004af4f0-0x004af557.AddItemWithCountDialogSubmitPacketHelper.md`
  - `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
  - `by-global/g_packetSender.md`
  - `by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md`
  - `by-memory/0x00575380-0x005754c0.PacketBufferScalarBigEndianWriteHelpers.md`
  - `by-memory/0x00575650-0x00575673.PacketBufferCursorAppendBigEndianHelpers.md`
  - `by-class/AddMixingItemDialog.md`
  - `by-type/by-vtable/AddMixingItemDialogVtables.md`
  - `by-memory/0x00619d28-0x00619e04.ExchangeItemReadOnlyData.md`
  - `by-file/MyItemListPane.md`
  - `by-type/by-struct/MyItemListPaneEntryLayouts.md`
  - prior B001 report `tools/leaser/Agents/Agent-B001/research/executed/older/00014T-ItemExchangeMixDialogs.md`
- Exported reverse-engineering data:
  - `resources/exported_data/functions/0x004afb80.json`
  - `resources/exported_data/functions/0x004af8b0.json`
  - generated source marker `auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp`
  - generated decompiler output `source-3/simroot_v2/class_MixItemDialog.cpp`
- Raw binary evidence:
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - image base `0x00400000`
  - `.text` raw mapping for target start: VA `0x004afb80` -> raw offset `0x000aef80`
  - raw pointer scans for VA, RVA, and raw-offset patterns
  - `.text` direct branch/call rel32 and short-branch scans to the target start
  - Capstone disassembly/callee/branch breakdown from the raw bytes
- Tool limitation: live IDA MCP resources were unavailable in this session, so direct live IDA renames/types were not applied. The target's range, bytes, refs, and decompilation were rechecked through exported data and the raw PE.

## Raw Range / Byte Facts
- Whole documented range: `0x004afb80-0x004afcc0`, size `0x140`.
- Executed body: `0x004afb80-0x004afcb7`, size `0x137` / 311 bytes.
- Padding: `0x004afcb7-0x004afcc0`, nine bytes of `0xcc`.
- Raw file offset for body start: `0x000aef80`.
- Full byte summary:

```text
004afb80: 55 8b ec 81 ec 10 01 00 00 a1 24 2f 67 00 33 c5
004afb90: 89 45 fc 53 56 8b f1 57 6a 05 89 b5 f0 fe ff ff
004afba0: 8b 8e fc 01 00 00 8b 01 ff 50 10 8b 00 8b b8 08
004afbb0: 01 00 00 8b cf 89 bd f4 fe ff ff e8 10 40 04 00
004afbc0: 8b d8 85 db 0f 8e ce 00 00 00 8d 85 fc fe ff ff
004afbd0: c7 85 f8 fe ff ff 00 00 00 00 50 6a 6b e8 9e 57
004afbe0: 0c 00 8b 85 f8 fe ff ff 8d 8d fc fe ff ff 40 89
004afbf0: 85 f8 fe ff ff 03 c1 50 53 e8 82 57 0c 00 ff 85
004afc00: f8 fe ff ff 83 c4 10 33 f6 0f 1f 80 00 00 00 00
004afc10: 56 8b cf e8 a8 41 04 00 8b 8d f8 fe ff ff 8b f8
004afc20: 8d 85 fc fe ff ff 03 c8 51 0f be 0f 51 e8 4e 57
004afc30: 0c 00 ff 85 f8 fe ff ff 83 c4 08 0f b6 0f 51 8b
004afc40: 0d 48 a7 67 00 e8 26 3c 0f 00 80 b8 ec 01 00 00
004afc50: 00 74 1c 8d 85 f8 fe ff ff 50 8d 85 fc fe ff ff
004afc60: 50 ff b7 08 02 00 00 e8 e4 59 0c 00 83 c4 0c 8b
004afc70: bd f4 fe ff ff 46 3b f3 7c 96 ff b5 f8 fe ff ff
004afc80: 8b 0d ec a7 67 00 8d 85 fc fe ff ff 50 e8 1e 4f
004afc90: 0c 00 8b b5 f0 fe ff ff 8b ce e8 f1 ee fe ff 8b
004afca0: ce e8 2a de fe ff 8b 4d fc 5f 5e 33 cd 5b e8 7c
004afcb0: 7a 11 00 8b e5 5d c3 cc cc cc cc cc cc cc cc cc
```

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004af570-0x004afb80` | [UID:00033U] `by-memory/0x004af570-0x004afb80.MixItemDialogCore.md` | Constructor/action dispatcher area, including live `HandleAction` switch and case-3 inline packet serialization. | TRUE | `00008J` | current `85/88` | Support doc should gain exact switch table and duplicate-helper relationship. |
| `0x004afb68-0x004afb78` | inside [UID:00033U] | Four-entry action switch table. | data/table | `00008J` | covered by core | Entries are `0x004af8fa`, `0x004af9f9`, `0x004afa3a`, `0x004afb3b`; no entry targets `0x004afb80`. |
| `0x004afb78-0x004afb80` | inside [UID:00033U] | Eight bytes of `0xcc` after the switch table. | padding | `00008J` | covered by core | Separates switch table from the standalone helper. |
| `0x004afb80-0x004afcb7` | [UID:00033V] target | Standalone retained private helper body that serializes and sends opcode `0x6b` mix packet, then closes the dialog. | TRUE | `00008J` | recommend `88/89` | Source-bearing helper; no direct runtime route to standalone start found. |
| `0x004afcb7-0x004afcc0` | [UID:00033V] target | Nine-byte `0xcc` postpad. | padding | `00008J` | recommend `88/89` | Belongs in target range as exact post-function padding. |
| `0x004afcc0-0x004afe38` | [UID:000319] `MixItemDialogQuantityPromptHelper` | Quantity prompt helper for adding stackable mix rows. | TRUE | `00008J` | support | Confirms metadata offsets and row quantity semantics used by target. |
| `0x004afe40-0x004afff7` | [UID:00031A] `MixItemDialogQuantityCallback` | Quantity callback stores row data/quantity. | TRUE | `00008J` | support | Confirms `+0x208` row quantity path. |

## Direct Xref / Caller / Route Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004afb80` | no exact VA pointer hits (`80 fb 4a 00`) | No observed direct pointer to the standalone body. |
| `0x004afb80` | no RVA pointer hits (`80 fb 0a 00`) | No observed RVA table/metadata route to the standalone body. |
| `0x004afb80` | no raw-offset pointer hits (`80 ef 0a 00`) | No observed file-offset route to the standalone body. |
| `0x004afb80` | no `.text` rel32 direct call/jmp/Jcc and no short branch to target start | No direct static branch route found. |
| `0x004afb68-0x004afb78` | dwords `0x004af8fa`, `0x004af9f9`, `0x004afa3a`, `0x004afb3b` | `MixItemDialog::HandleAction` switch table; the submit case routes to `0x004afa3a`, not to `0x004afb80`. |
| `0x004afa3a` | live switch case 3 in `0x004af8b0` decompile | Contains the same mix-packet serialization and send/close semantics as the standalone target. |
| `0x0061a0d0 -> 0x004af8b0` | `MixItemDialog` vtable action slot documented in `MixItemDialogVtables.md` | Live dispatch reaches the action handler, not the standalone helper. |
| `0x004afbba -> 0x004f3bd0` | list count helper | Counts selected mix-list rows. |
| `0x004afbdb -> 0x00575380` | packet scalar byte writer | Writes opcode `0x6b` into local packet buffer. |
| `0x004afbf6 -> 0x00575380` | packet scalar byte writer | Writes item-count byte. |
| `0x004afc14 -> 0x004f3dc0` | list item by index helper | Retrieves row pointer for each selected mix-list row. |
| `0x004afc2c -> 0x00575380` | packet scalar byte writer | Writes each row item id byte. |
| `0x004afc44 -> 0x005a3870` via `dword_67A748` | item metadata lookup | Tests item metadata byte at `+0x1ec` to decide if a quantity byte is emitted. |
| `0x004afc67 -> 0x00575650` | packet cursor append byte helper | Appends the low byte of row `+0x208` quantity and advances packet length. |
| `0x004afc89 -> 0x00574bb0` via `dword_67A7EC` | queue/send packet | Sends exactly the accumulated packet length. |
| `0x004afc99 -> 0x0049eb90` | close/slide helper | Begins shared dialog close/dismiss path. |
| `0x004afca0 -> 0x0049dad0` | close/deferred delete helper | Finishes shared dialog close/deferred cleanup path. |

## Behavior Reconstruction
- The helper obtains the central mix-list control from `this + 0x1fc` using selector `5`.
- The selected list/control wrapper points to row/list storage at `+0x108`.
- It calls `0x004f3bd0` to get the selected row count.
- If `count <= 0`, it skips packet construction and still executes the close/dismiss pair.
- If `count > 0`, it creates a local packet buffer and emits:
  - opcode byte `0x6b`
  - selected-row count as a single byte
  - one item id byte for each selected row, from row offset `+0x00`
  - an optional quantity byte for rows whose item metadata byte at `+0x1ec` is nonzero; the value comes from row offset `+0x208`, but only the low byte is serialized by `PacketBufferAppendUInt8`
- It sends through `dword_67A7EC` / `0x00574bb0`, the documented `g_packetSender` / queue-send route.
- The helper does not include the spare zero bytes left by the packet byte helpers in the sent length; `packetLength` advances by one for each payload byte.
- There is no local capacity/range guard for row count or quantity. Any list-size cap is enforced by UI/list construction and selection behavior outside this helper.
- Close/dismiss always runs after packet handling, including the empty-list path.

## Packet / Field / Helper Name Resolution
| Raw name / offset | Recommended descriptive source name | Confidence | Evidence |
| --- | --- | --- | --- |
| `sub_4AFB80`, Ghidra `meth_0x4afb80` | `MixItemDialog::SubmitMixPacket()` | Medium-high | Owner, opcode, physical adjacency, duplicate action case, no compiler-wrapper shape. Original spelling is not proven; this is the strongest descriptive helper name. |
| `this+0x1fc` | `m_controlPaneList` / child-control list | Medium-high | Same selector and access path used by MixItemDialog/AddMixingItemDialog docs. |
| selector `5` | `kMixListControlId` / central mix-list selector | High | Constructor/action docs create and use selector `5` for the mix list; AddMixing confirm routes inserted rows there. |
| row/list storage `+0x108` | list row storage / `m_items` | Medium | Existing generated code and list docs model row storage here; exact class type remains descriptive. |
| `0x004f3bd0` | list count helper | High | Return controls loop bound and empty-list path. |
| `0x004f3dc0` | list entry by index helper | High | Called with index and list pointer, returns row pointer. |
| row `+0x00` | item id byte | High | Serialized as the packet item id and used for metadata lookup. |
| row `+0x208` | selected quantity / row quantity | High | Quantity callback and AddMixing confirm docs show this as the quantity payload; target appends low byte. |
| `dword_67A748` | `g_pCollectionData` | High | Existing item metadata docs use this global for item info lookup. |
| metadata `+0x1ec` | stackable/quantity flag | Medium-high | Target emits quantity only when set; sibling prompt/callback docs use metadata around `+0x1e8/+0x1ec` for stack/max-quantity behavior. |
| metadata `+0x1e8` | max stack/count metadata | Medium-high | Not read by target, but sibling quantity prompt/callback paths use it to bound quantity selection. |
| `0x00575380` | `PacketBufferWriteUInt8` | High | PacketBuffer scalar helper docs prove byte write plus spare zero; target uses it for opcode/count/item ids. |
| `0x00575650` | `PacketBufferAppendUInt8` | High | Cursor append helper docs prove byte append and cursor advance; target uses it for optional quantity. |
| `dword_67A7EC` / `0x00574bb0` | `g_packetSender->QueueAndSendPacket` | High | Queue/send docs and global page identify this route. |
| `0x0049eb90` | shared slide/close helper | Medium-high | Used by dialog close paths; exact original name remains inferred. |
| `0x0049dad0` | shared close/deferred delete helper | Medium-high | Used immediately after slide/close helper; exact original name remains inferred. |

## Heuristic / Inference Reanalysis And Validation
- Raw-helper liveness/no-xref route:
  - Evidence checked: raw VA/RVA/raw-offset pointer scans, direct `.text` rel32 and short-branch scans, switch table dwords, vtable route, exported decompile of `0x004af8b0`.
  - Best inference: `0x004afb80` is a retained/out-of-line private source helper body with no observed runtime route in the final binary, while the live `MixItemDialog::HandleAction` case 3 at `0x004afa3a` contains an inline/duplicated copy of the same logic.
  - Rejected: "case 3 directly calls the helper" is contradicted by the switch table route and no direct branch/call. "This is compiler-generated glue" is contradicted by normal packet/list/send source logic. "Merge into the dispatcher range" is rejected because the target has an independent prologue/security-cookie body and exact padding.
- Packet opcode/list semantics:
  - Evidence checked: target bytes and calls, PacketBuffer helper docs, queue-send docs, sibling AddItem/AddItemWithCount helpers, MixItemDialog core decomp.
  - Best inference: opcode `0x6b` is the mix-submit packet. Payload is one-byte count, one-byte item ids, and optional one-byte quantities for stackable/quantity-tracked items.
  - Rejected: quantity as a four-byte integer is contradicted by the append-byte helper; the raw push is a 32-bit argument but only the low byte is serialized.
- Source-facing helper name/signature:
  - Evidence checked: calling convention (`ecx=this`), class fields, source-file docs, generated `ItemDialogs.cpp` marker, neighboring helpers.
  - Best inference: `void MixItemDialog::SubmitMixPacket()` or `void MixItemDialog::SubmitMixRequestPacket()`; use `SubmitMixPacket` as the recommended descriptive name.
  - Rejected: static/global helper because the body is `thiscall` and accesses `MixItemDialog` state. Rejected `RankingDialog` from Ghidra JSON as a type-propagation error.
- Row/list fields:
  - Evidence checked: constructor/action docs, AddMixingItemDialog confirm docs, quantity prompt/callback docs, selector constants from generated/decompiled paths.
  - Best inference: `this+0x1fc` is the dialog child-control/page list, selector `5` is the mix list, row storage `+0x108` is the selected item list backing storage, row `+0x208` is selected quantity, metadata `+0x1ec` is the stackable/quantity flag.
  - Remaining uncertainty: exact original class/field names are not symbol-proven; names should be documented as descriptive/inferred. This caps confidence but does not block C++.
- Close/dismiss behavior:
  - Evidence checked: target tail and neighboring dialog helper usage.
  - Best inference: submit always dismisses the dialog, including the empty-list path. `sub_49EB90` is the shared slide/close helper; `sub_49DAD0` is a close/deferred cleanup helper.
  - Rejected: send-only helper that leaves dialog open; contradicted by unconditional tail calls.
- Owner/source placement:
  - Evidence checked: owner class docs, vtable route, physical address cluster, ItemDialogs file page, singleton globals, sibling item-dialog helpers.
  - Best inference: direct owner/emitter remains `MixItemDialog` (`00008J`), parent source file remains `ItemDialogs` (`0000KE`) under current project routing. If the project later splits item dialogs into class-specific files, this helper should move with the whole `MixItemDialog` family rather than by itself.
  - Rejected: `AddMixingItemDialog` owns row construction and quantity callback interaction, but this target reads the MixItemDialog central list and sends the mix packet. Rejected PacketBuffer/Socket/global owners because they are callees only.
- Compiler/generated names:
  - Evidence checked: raw prologue, security cookie, loop, packet writes, close tail, no thunk/delete/vtable-only shape.
  - Best inference: no compiler-generated wrapper policy applies. Raw names (`sub_4AFB80`, `meth_0x4afb80`, `dword_67A748`, `dword_67A7EC`) should be replaced in documentation with descriptive class/global/helper names and a note that exact original spelling is inferred.
- Range/split/merge:
  - Evidence checked: postpad, switch table end, next helper start, exported function size.
  - Best inference: keep the current range as the standalone helper plus pad. Add support-doc cross-links rather than splitting or merging.
- First-draft C++ blocker reanalysis:
  - Evidence checked: active code gate, owner/emitter route, behavior coverage, source names.
  - Best inference: formal C++ should be populated after acceptance. The body is source-authored and reaches the current gate; the no-xref status must be preserved as a liveness note, not used as a stale no-code blocker.
  - Remaining uncertainty: original helper spelling and exact UI/list type names remain inferred. Use descriptive names and comments rather than decompiler-shaped `sub_` names.

## Documentation Evidence And Current Gaps
- Target doc already identifies the broad behavior, owner, range, selector `5`, row storage `+0x108`, quantity offset `+0x208`, metadata `+0x1ec`, send helper, and close helpers.
- Target doc is incomplete/stale because it:
  - says no final C++ should be emitted because IDA does not model the raw helper as a function and final names are inferred
  - lacks exact raw offset, full body byte summary, postpad byte count evidence, and switch table dword evidence
  - does not document the negative route proof as strongly as needed
  - does not explicitly say the live action case 3 duplicates the helper logic at `0x004afa3a`
  - does not resolve quantity as a byte rather than a dword packet field
  - does not explain empty-list close/dismiss behavior
- `by-class/MixItemDialog.md` supports the direct owner but should add the retained-helper/inline-duplicate source policy and field semantics at target-report specificity.
- `by-memory/0x004af570-0x004afb80.MixItemDialogCore.md` should add the exact switch table entries and the fact that case 3 is the live route for the submit packet logic.
- `by-file/ItemDialogs.md` supports the file route but should explicitly list the MixItemDialog submit helper and source-split caveat.
- PacketBuffer and `g_packetSender` docs already carry enough helper/source identity and do not require mandatory changes for this target.

## Ranked Ownership / Source-Placement Analysis

### 1. [UID:00008J] `MixItemDialog` via [UID:0000KE] `ItemDialogs` - accepted
- Evidence for:
  - `thiscall` body reads dialog state at `this+0x1fc`.
  - Child selector `5` is the MixItemDialog central mix list in the existing dialog docs.
  - Opcode `0x6b`, item metadata lookup, row iteration, quantity field, and close/dismiss path match mix-submit behavior.
  - Physical placement is inside the MixItemDialog cluster, between core action handling and quantity-prompt helper.
  - Generated output already has an emitter marker under `auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp`.
- Evidence against:
  - No direct pointer/branch route to the standalone body survives.
  - Original helper spelling is not symbol-proven.
- Decision: keep owner/emitter. The route-negative finding affects liveness wording and confidence, not direct ownership.

### 2. [UID:00033U] `MixItemDialogCore` / live `HandleAction` case - support-only, not owner replacement
- Evidence for:
  - The live switch case 3 at `0x004afa3a` duplicates the target's packet serialization behavior.
  - The vtable action slot routes to the action dispatcher, not the standalone helper.
- Evidence against:
  - The target has an independent body, prologue, security cookie, and return after the switch table.
  - Merging would lose the exact standalone range/padding and overstate dispatch reachability.
- Decision: update core docs to mention the duplicate/live route, but keep `00033V` as its own source-bearing helper item.

### 3. `AddMixingItemDialog` - rejected as owner
- Evidence for:
  - AddMixing paths create or confirm rows that end up in the mix list, and quantity callback docs explain row quantity fields.
- Evidence against:
  - Target `this` is the MixItemDialog; selector `5` belongs to the MixItemDialog child list, and the target sends the final mix request.
  - AddMixingItemDialog is producer/caller context, not the submit helper owner.
- Decision: support/caller-context doc only.

### 4. PacketBuffer / network / global packet sender owners - rejected
- Evidence for:
  - Packet helper and queue/send functions are essential callees.
- Evidence against:
  - They do not own the dialog state, opcode selection, row traversal, or close behavior.
- Decision: leave as callee references only.

### 5. No-owner/non-emitting or compiler-generated no-code wrapper - rejected
- Evidence for:
  - No direct runtime xref to standalone helper start.
- Evidence against:
  - Current owner/emitter clears the gate; the body is normal source logic, not compiler glue, destructor thunk, EH cleanup, vtable table, or padding-only island.
- Decision: keep source-bearing emitter route and add first-draft C++.

## First-Draft C++ Recommendation
Populate the target's formal C++ after supervisor acceptance. Keep the source-liveness caveat in prose: this standalone body has no observed direct runtime route, and the live switch case 3 contains an inline/duplicated copy. The draft should be mid-2000s style and use descriptive names rather than raw `sub_` names.

```cpp
void MixItemDialog::SubmitMixPacket()
{
    ListPane *mixList = GetDialogPage(5)->m_list;
    int itemCount = mixList->GetCount();

    unsigned char packet[0x110];
    int packetLength = 0;

    if (itemCount > 0)
    {
        PacketBufferWriteUInt8(0x6b, packet + packetLength);
        ++packetLength;

        PacketBufferWriteUInt8((unsigned char)itemCount, packet + packetLength);
        ++packetLength;

        for (int index = 0; index < itemCount; ++index)
        {
            MixItemRow *row = (MixItemRow *)mixList->GetItem(index);

            PacketBufferWriteUInt8(row->itemId, packet + packetLength);
            ++packetLength;

            ItemInfo *itemInfo = g_pCollectionData->GetItemInfo(row->itemId);
            if (itemInfo->isStackable)
                PacketBufferAppendUInt8((unsigned char)row->quantity, packet, &packetLength);
        }

        g_packetSender->QueueAndSendPacket(packet, packetLength);
    }

    SlideClose();
    CloseDialog();
}
```

Notes for implementation:
- `ListPane`, `MixItemRow`, `ItemInfo`, `GetDialogPage`, `SlideClose`, and `CloseDialog` are source-style/descriptive names. Exact original names are not proven.
- Do not add packet-size or range guards; the binary has none in this body.
- Do not emit quantity as a dword; this body appends one byte.
- If the accepted implementation wants a more explicit name, `SubmitMixRequestPacket` is the next-best descriptive alternative.

## Score / Metadata Recommendation
- Target metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:89`
  - `CANONICAL_OWNER:00008J`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:00008J`
  - `EMITTER_POSITION_OPTIONAL:` unchanged blank
- Score rationale:
  - Raise from `85/86` to `88/89` because this pass adds exact raw bytes, raw offset, body/padding split, switch table dwords, direct no-route proof, duplicate live action case relationship, helper/callee identities, byte-order and byte-width packet semantics, field/metadata/quantity roles, owner/source route, and a first-draft C++ body under the active gate.
  - Confidence should remain below 90 because live IDA MCP was unavailable, original helper spelling is inferred, and no direct runtime route to the standalone body survives.

## Recommended Target Doc Changes
After supervisor acceptance, update `by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md` as follows:
- Change metadata to `COMPLETION:88`, `CONFIDENCE:89`; keep owner/emitter/reconstructable fields unchanged.
- Replace stale no-code wording with:
  - the active 85/85 combined-score gate result
  - statement that this is source-authored private helper logic, not compiler-generated glue
  - statement that the standalone body has no observed direct runtime route and is duplicated inline by live `HandleAction` case 3
- Add raw evidence:
  - body `0x004afb80-0x004afcb7`, size `0x137` / 311
  - whole range `0x004afb80-0x004afcc0`, size `0x140`
  - raw offset `0x000aef80`
  - postpad `0x004afcb7-0x004afcc0`, nine `0xcc`
  - full byte summary from this report
  - switch table at `0x004afb68-0x004afb78` with dwords `0x004af8fa`, `0x004af9f9`, `0x004afa3a`, `0x004afb3b`
  - no VA/RVA/raw pointer hits and no direct branch/call route to `0x004afb80`
- Add behavior details:
  - selector `5` central mix list from `this+0x1fc`
  - list row storage `+0x108`
  - count helper `0x004f3bd0`
  - row getter `0x004f3dc0`
  - opcode `0x6b`
  - count and item ids emitted as bytes
  - optional quantity emitted as one byte from row `+0x208` only when metadata `+0x1ec` is set
  - metadata lookup through `g_pCollectionData` / `0x005a3870`
  - send through `g_packetSender` / `QueueAndSendPacket`
  - close/dismiss through `0x0049eb90` and `0x0049dad0` on both send and empty-list paths
- Add first-draft C++ block above or an accepted variant with equivalent behavior.
- Add rejected alternatives:
  - not direct case target
  - not `AddMixingItemDialog` owned
  - not PacketBuffer/network owned
  - not compiler-generated/no-code wrapper
  - not merged into `MixItemDialogCore`

## Recommended Support-Doc Changes
- `by-class/MixItemDialog.md`:
  - Add `SubmitMixPacket` / submit-packet helper source policy.
  - Preserve the route-negative caveat: standalone `0x004afb80` has no observed branch/pointer route, while live `HandleAction` case 3 duplicates the submit serialization.
  - Add selector/field summary: `this+0x1fc`, selector `5`, list row storage `+0x108`, row item id `+0x00`, row quantity `+0x208`, item metadata stackable/quantity flag `+0x1ec`.
  - State that source route remains under `ItemDialogs` unless the whole MixItemDialog family is split later.
- `by-memory/0x004af570-0x004afb80.MixItemDialogCore.md`:
  - Add exact switch table dwords at `0x004afb68-0x004afb78`.
  - Add that case 3 at `0x004afa3a` is the live action route for the mix-submit packet and duplicates the standalone helper semantics.
  - Add that no switch table entry points to `0x004afb80`.
- `by-file/ItemDialogs.md`:
  - Add `00033V` to the MixItemDialog contents/source route, ideally near `00033U`, `000319`, and `00031A`.
  - Note that `MixItemDialog` submit helpers currently emit through `ItemDialogs.cpp`; future class-specific file split should move the whole family together, not this helper alone.
- `by-type/by-vtable/MixItemDialogVtables.md`:
  - Optional support update only if touched for adjacent implementation: action slot points to `0x004af8b0`; submit packet standalone helper has no vtable slot and is not directly dispatched.
- No required changes to PacketBuffer or `g_packetSender` pages unless implementation review finds their helper names missing; current docs appear sufficient.

## Exact Future Implementation Checklist
1. Lease target/support docs before editing:
   - `by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md`
   - `by-class/MixItemDialog.md`
   - `by-memory/0x004af570-0x004afb80.MixItemDialogCore.md`
   - `by-file/ItemDialogs.md`
   - optionally `by-type/by-vtable/MixItemDialogVtables.md` only if the action-slot route needs same-specificity support.
2. Do not edit `by-memory/-coverage-report.md`; supervisor owns the row update.
3. Apply the target metadata and C++ recommendation above unless new evidence contradicts this report.
4. Preserve the negative route finding. Do not rewrite the target as "called by case 3"; the case 3 path is an inline/duplicated live copy.
5. Preserve packet byte widths: opcode/count/item id/quantity are all byte writes in this target.
6. Validate each edited file from `source-3/project-documentation`.
7. If formal C++ is inserted, run an autogen refresh/validator pass as directed by supervisor and inspect generated `auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp` for the `00033V` marker/body.

## Validation Commands Needed
No validators were run during this report-only pass because no by-* docs were edited. Future implementation should run:

> Executable block R001 was removed from this report and preserved verbatim in [00033V-MixItemDialogSubmitPacketHelper-source-quality-removed.md](00033V-MixItemDialogSubmitPacketHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If `MixItemDialogVtables.md` is edited:

> Executable block R002 was removed from this report and preserved verbatim in [00033V-MixItemDialogSubmitPacketHelper-source-quality-removed.md](00033V-MixItemDialogSubmitPacketHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If C++ insertion affects generated output:

> Executable block R003 was removed from this report and preserved verbatim in [00033V-MixItemDialogSubmitPacketHelper-source-quality-removed.md](00033V-MixItemDialogSubmitPacketHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Exact Pending Coverage Row Text
Replace the `00033V` row in `by-memory/-coverage-report.md` with this supervisor-owned text if the implementation is accepted:

```markdown
        - [UID:00033V][0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper](by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md) 0x004afb80-0x004afcc0 | retained raw/private helper | MixItemDialogSubmitPacketHelper : reconstructable : 88% : strong : Assigned to [UID:00008J][MixItemDialog](by-class/MixItemDialog.md); B009 source-quality pass confirms standalone `0x004afb80-0x004afcb7` body at `.text` raw `0x000aef80`, nine-byte postpad, no VA/RVA/raw pointer hits and no direct branch/call route to the standalone start, source liveness best explained as a retained/out-of-line private submit helper duplicated inline by `MixItemDialog::HandleAction` case 3 at `0x004afa3a`, opcode `0x6b` packet over child selector `5` list storage `+0x108`, item count/id bytes, optional quantity byte from row `+0x208` when item metadata `+0x1ec` is set, send through `g_packetSender`/`QueueAndSendPacket`, close/dismiss on both send and empty-list paths, owner/emitter [UID:00008J], and first-draft `MixItemDialog::SubmitMixPacket()` C++ readiness under the active gate.
```

## IDA Rename / Type / Comment Recommendations
- If live IDA editing is later available, create or confirm the function at `0x004afb80-0x004afcb7`.
- Rename `sub_4AFB80` / `meth_0x4afb80` to `MixItemDialog::SubmitMixPacket` or `MixItemDialog_SubmitMixPacket`.
- Apply a thiscall prototype: `void __thiscall MixItemDialog_SubmitMixPacket(MixItemDialog *this)`.
- Add a function comment: `Standalone retained/out-of-line copy; no VA/RVA/raw pointer/direct branch route found. Same submit logic is inline in MixItemDialog::HandleAction case 3 at 0x004afa3a.`
- Keep the switch table at `0x004afb68` with entries `0x004af8fa`, `0x004af9f9`, `0x004afa3a`, `0x004afb3b`; do not add a fake entry to `0x004afb80`.
- Rename/comment packet helpers:
  - `0x00575380` -> `PacketBufferWriteUInt8`
  - `0x00575650` -> `PacketBufferAppendUInt8`
- Rename/comment globals:
  - `dword_67A748` -> `g_pCollectionData`
  - `dword_67A7EC` -> `g_packetSender`
- Add/infer field comments:
  - `MixItemDialog +0x1fc`: child-control/page list (`m_controlPaneList`, descriptive)
  - child selector `5`: central mix list control (`kMixListControlId`)
  - list/control `+0x108`: row storage / selected item list backing storage
  - row `+0x00`: item id byte
  - row `+0x208`: selected quantity
  - item metadata `+0x1ec`: stackable/quantity flag
  - item metadata `+0x1e8`: max-stack/count metadata used by sibling quantity helpers
- Comment close helpers:
  - `0x0049eb90`: shared slide/close helper
  - `0x0049dad0`: close/deferred deletion helper

## Open Questions And Attempted Resolution
- Exact original helper name: not symbol-proven. Evidence supports descriptive `SubmitMixPacket`; confidence impact only.
- Exact UI/list class names for selector `5` and row storage `+0x108`: not symbol-proven. Existing docs and generated output support source-style `GetDialogPage(5)->m_list` / `ListPane`; confidence impact only.
- Why the standalone helper has no route while case 3 duplicates it: not provable from binary alone. Best explanation is retained/out-of-line private helper plus inlined/duplicated submit logic in the live action handler, or a dead unused private helper retained from the same translation unit. This should be documented as source-liveness uncertainty and should not block ownership or C++ because the body itself is source-authored and exactly understood.
- Whether future source tree should split `MixItemDialog` out of `ItemDialogs.cpp`: outside this target. Current evidence supports the existing `ItemDialogs` route; any future split should move the class family together.

## Final Recommendation
- Keep [UID:00033V] assigned to [UID:00008J] `MixItemDialog`.
- Keep emitter [UID:00008J] and source route through [UID:0000KE] `ItemDialogs`.
- Raise target score to `88/89`.
- Add formal first-draft C++ for `MixItemDialog::SubmitMixPacket()` after supervisor acceptance.
- Update support docs with the exact no-route/duplicate-case relationship and field/packet semantics.
- Leave `by-memory/-coverage-report.md` untouched by B009; supervisor should apply the exact replacement row above after implementation is verified.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/00033V-MixItemDialogSubmitPacketHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"00033V"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00033V-MixItemDialogSubmitPacketHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/00033V-MixItemDialogSubmitPacketHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00033V"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
