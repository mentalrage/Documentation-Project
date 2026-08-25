** TARGET-REPORT-UID:0002JO **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID0002JO MyItemListPaneConstructor Source-Quality Report


## Target

- Agent folder: `tools/leaser/Agents/Agent-B003`
- Goal assignment: `B003-report-0002JO-MyItemListPaneConstructor-20260702`
- Target UID: `0002JO`
- Target path: `by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md`
- Target symbol/range: `MyItemListPaneConstructor`, `0x004aeb30-0x004aec77`
- Required mode: report-only research. No by-* support/target edits, no generated/coverage/project-level edits, no validator lifecycle/report execution/archive commands.

## Current Target State

- Current target score when assigned: `COMPLETION:85`, `CONFIDENCE:88`.
- Current target metadata when assigned: `CANONICAL_OWNER:0000LO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LO`.
- Current target source state: formal C++ block is blank; generated output currently has an empty UID0002JO emitter marker.
- Current target understanding: constructor has IDA-backed ListPane base construction, vtable stores, local inventory-slot enumeration, row payload construction, and append behavior, but the page still needs source-quality normalization around class ownership, ListPane argument naming, row payload support, raw global/helper recovery, and first-draft constructor C++.
- Current source-placement route: `by-file/MyItemListPane.md` (`UID0000LO`) currently owns/emits the method directly, while `by-class/MyItemListPane.md` (`UID00008W`) is the direct semantic class owner and emits to UID0000LO.

## Executive Recommendation

Raise UID0002JO from `85/88` to `88/90` after incorporation.

The constructor is now source-ready as a first-draft C++ method body if the support documentation also supplies the row payload struct and routes the method through `MyItemListPane`. Current IDA MCP evidence confirms the complete constructor range, all calls, all vtable stores, the ListPane constructor argument vector, the active inventory-slot loop, the LocalInventorySlotRecord accessor, the row payload layout, and the append helper behavior.

Recommended ownership correction:

- Set `CANONICAL_OWNER:00008W` for UID0002JO.
- Set `EMITTER_UIDS:00008W` for UID0002JO.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep source placement under `by-file/MyItemListPane.md` through class UID00008W -> file UID0000LO.

The current file-level ownership was a workable older routing shortcut, but the direct semantic owner is the class page `by-class/MyItemListPane.md` (`UID00008W`). The method is a constructor for that class, and the class already emits to `by-file/MyItemListPane.md` (`UID0000LO`). Implementation should add a class-level child marker if needed so rerouting UID0002JO through the class does not suppress child emission.

## Evidence Checked

Evidence checked for this repair report:

- Assigned `goal.md` for Agent-B003 and the project-level `ntk-b-agent-workflow` reference.
- Target page `by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md`.
- Direct class/file/container support: `by-class/MyItemListPane.md`, `by-file/MyItemListPane.md`, `by-memory/0x004aeb30-0x004af031.MyItemListPane.md`.
- Layout/vtable/global/accessor support: `by-type/by-struct/MyItemListPaneEntryLayouts.md`, `by-type/by-vtable/MyItemListPaneVtables.md`, `by-global/g_activeUserStatusPane.md`, `by-memory/0x005a3870-0x005a3889.LivingObjectPaneGetInventorySlotAddress.md`.
- ListPane support: `by-class/ListPane.md`, `by-file/ListPane.md`.
- Sibling/consumer support: `by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md`, `by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md`.
- Dialog/source-placement support: `by-file/ItemDialogs.md`, `by-class/AddItemDialog.md`, `by-class/MixItemDialog.md`.
- Generated state as read-only input: `auto-generated/NexusTK/ui/dialogs/MyItemListPane.cpp`.
- Existing-report search terms used included `0002JO`, `0x004aeb30`, `004aeb30`, `MyItemListPaneConstructor`, `MyItemListPane`, and `ItemListPane`.
- Matching executed report leads checked: B006 UID0003U9 inventory accessor, B001 item-exchange/mix dialog split, B003 UID00033R selected-slot AddItem packet use, and B009 clan-bank family dependency evidence.
- IDA MCP evidence: active `supervisor_resume_20260629` session, `lookup_funcs`, `xrefs_to`, `analyze_function`, disassembly for UID0002JO and helper functions, and MCP integer conversion for documented decimal/hex values.
- Local source check: `source-3/simroot_v2` is absent, so no original/static source tree was available as direct proof.

## Positive Evidence Summary

- MCP confirms UID0002JO is exactly `sub_4AEB30`, size `0x147`, and covers `0x004aeb30-0x004aec77`.
- MCP confirms constructor callers at `0x0048a50d`, `0x004ae63e`, `0x004ae7f0`, and `0x004af7a7`, matching reusable AddItem/Mix/ClanDep item-list use rather than a single dialog owner.
- MCP confirms ListPane base construction with argument vector `0x20c, 8, 205/170, 24, 0, 1, 1`.
- MCP confirms MyItemListPane vtable stores at `this+0`, `this+0xa0`, and `this+0xa4`.
- MCP and current support confirm inventory count comes from `g_activeUserStatusPane + 0x284`, best current source field `m_inventorySlotCount`.
- MCP and UID0003U9 support confirm slot lookup is `LivingObjectPane::GetInventorySlotAddress(char)`, using `this + 0x133f08 + slot * 0x1fc`.
- MCP and UID0001VE support confirm the row payload size and field flow: slot index at `+0`, item id at `+2`, icon/style byte at `+4`, and wide display text at `+6`.
- MCP confirms ListPane append helper `0x004f3c50` appends the row payload and a matching selection byte.
- The evidence supports raising UID0002JO to `88/90`, correcting ownership/emitter route to class UID00008W, and inserting a first-draft formal C++ constructor body after support scaffolding is present.

## Negative Evidence Summary

- No local `source-3/simroot_v2` source tree exists, so exact original source names are not directly proven.
- No direct evidence supports keeping UID0002JO owned by AddItemDialog, MixItemDialog, ClanBank, ClanDep, ItemDialogs, or ListPane.
- No evidence supports encoding vtable writes or EH cleanup helpers as explicit source-level constructor statements.
- No evidence supports retaining raw decompiler names such as `unk_69AE0C`, `dword_67A748`, or `sub_5A3870` in final source-facing prose/C++.
- No evidence supports the old statement that `205/170` is a visible row count; ListPane analysis shows it is better documented as a mode-dependent extent/dimension.
- No evidence supports zero-initializing the full row payload before assigning semantic fields; UID0002JO leaves padding bytes uninitialized.
- No evidence supports a split/range change for UID0002JO or merging it with UID0002JP/UID0002JQ.

## Heuristic / Inference Reanalysis And Validation

The direct binary facts validate a class-owned, source-file-emitted constructor rather than a file-owned raw helper. UID0002JO receives `this`, calls the ListPane constructor, installs MyItemListPane vtables, builds MyItemListPane row payloads, and is called by multiple dialog flows. That pattern is a normal C++ derived-class constructor for `MyItemListPane`, so the strongest owner is `by-class/MyItemListPane.md` (`UID00008W`), with source placement still under `by-file/MyItemListPane.md` (`UID0000LO`).

The earlier direct file-owner route (`CANONICAL_OWNER:0000LO`, `EMITTER_UIDS:0000LO`) is a historical generator shortcut, not the best current owner model. Rerouting UID0002JO through UID00008W is valid if the class page includes a child emission marker so generated output still reaches `MyItemListPane.cpp`.

The ListPane constructor argument reanalysis resolves a current source-quality blocker. `0x20c` is the row payload size, `8` is the ListPane/list count or capacity argument, `205/170` is a mode-dependent dimension/extent consumed with `24` by the ListPane geometry helper, and `0,1,1` are pointer/flag arguments. This repaired interpretation is evidence-backed by analyzing both UID0002JO and `0x004f3a50`.

The source-facing names remain inferred but defensible: `MyItemListEntry`, `g_useHighResLayout`, `g_activeUserStatusPane->m_inventorySlotCount`, `g_pUserPane->GetInventorySlotAddress`, and `AddEntry`. They are better than raw IDA/decompiler labels and are tied to current support docs. Exact original spellings remain unresolved, but that does not block a first-draft C++ body because behavior, layout, and helper roles are known.

## Current MCP Session And Evidence State

IDA MCP was available and used successfully.

- MCP endpoint: `http://127.0.0.1:13337/mcp`
- Active IDB session: `supervisor_resume_20260629`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Image base: `0x400000`
- Auto-analysis ready: `true`
- Hex-Rays ready: `true`
- Strings cache ready: `true`
- Strings cache size: `2067`
- MCP schema note: current `xrefs_to` requires `addrs`, not `addr`; subsequent calls used the active schema.

No MCP timeout or unavailability condition was reached.

## Documentation Reviewed

Primary target and support:

- `by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md`
- `by-class/MyItemListPane.md`
- `by-file/MyItemListPane.md`
- `by-memory/0x004aeb30-0x004af031.MyItemListPane.md`
- `by-type/by-struct/MyItemListPaneEntryLayouts.md`
- `by-type/by-vtable/MyItemListPaneVtables.md`
- `by-global/g_activeUserStatusPane.md`
- `by-memory/0x005a3870-0x005a3889.LivingObjectPaneGetInventorySlotAddress.md`
- `by-class/ListPane.md`
- `by-file/ListPane.md`
- `by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md`
- `by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md`
- `by-file/ItemDialogs.md`
- `by-class/AddItemDialog.md`
- `by-class/MixItemDialog.md`

Executed report leads checked:

- `tools/leaser/archive/executed-b-agent-research/B006/0003U9-LivingObjectPaneGetInventorySlotAddress-source-quality.md`
- `tools/leaser/archive/executed-b-agent-research/B001/00014T-ItemExchangeMixDialogs.md`
- `tools/leaser/archive/executed-b-agent-research/B003/00033R-AddItemDialogSubmitPacketHelper-source-quality.md`
- `tools/leaser/archive/executed-b-agent-research/B009/0000I9-ClanBank-empty-emitter-family-source-quality.md`

The B006 report is an older lead and its recorded validator state includes a later `target_uid_unknown` validation issue, so this report relies on the current incorporated by-* pages plus fresh MCP for final claims. Its useful incorporated facts are present in the current UID0003U9 and row-layout support docs.

Generated state checked without editing:

- `auto-generated/NexusTK/ui/dialogs/MyItemListPane.cpp`
- Current generated file was refreshed at `2026-07-02T14:16:35-04:00`.
- It currently contains empty emitter markers for UID00008W, UID0001VE, UID0001Y8, UID0002JO, UID0002JP, and UID0002JQ.
- UID0002JO is therefore currently reconstructable in metadata but still empty in generated source.

Local source search state:

- `source-3/simroot_v2` is absent in this checkout.
- No local simroot/source tree was available as source proof.

## IDA MCP Function Facts

`lookup_funcs` confirmed:

- `0x004aeb30` -> `sub_4AEB30`, size `0x147`
- `0x004aec77` -> not a function start
- `0x004aec80` -> `sub_4AEC80`, size `0xe`
- `0x004aec90` -> `sub_4AEC90`, size `0x3a1`
- `0x004af031` -> not a function start
- `0x005a3870` -> `sub_5A3870`, size `0x19`
- `0x004f3a50` -> `sub_4F3A50`, size `0x10b`
- `0x004f3c50` -> `sub_4F3C50`, size `0x54`
- `0x004f3dc0` -> `sub_4F3DC0`, size `0xf`

`xrefs_to` confirmed UID0002JO has exactly four constructor callers:

- `0x0048a50d` in `sub_48A1C0`
- `0x004ae63e` in `sub_4AE4C0`
- `0x004ae7f0` in `sub_4AE4C0`
- `0x004af7a7` in `sub_4AF570`

These callers match the existing AddItem/Mix/ClanDep-style reusable item-list usage. They do not support moving UID0002JO into a clan-only or dialog-specific owner.

## Constructor Body Facts

Fresh `analyze_function 0x004aeb30` and disassembly confirm the constructor source behavior:

- The function is `sub_4AEB30`, a `__thiscall` constructor-like function returning `this`.
- It chooses a mode-dependent dimension:
  - default `0xcd` / 205
  - `0xaa` / 170 when `byte_66DA97 == 1`
- It calls ListPane constructor helper `0x004f3a50` with arguments:
  - row payload size `0x20c` / 524
  - `8`
  - `205` or `170`
  - `0x18` / 24
  - `0`
  - `1`
  - `1`
- It stores MyItemListPane vtables:
  - primary vtable at `this+0x0` from `0x00619f28`
  - secondary vtable at `this+0xa0` from `0x00619fb0`
  - tertiary vtable at `this+0xa4` from `0x00619fe0`
- It reads inventory slot count from `unk_69AE0C + 0x284`.
- It loops 1-based slots from `1` through that count.
- For each slot, it calls `0x005a3870` with the slot byte.
- It skips records whose active byte at offset `+0` is zero.
- For active records, it builds a stack row payload:
  - payload `+0`: inventory slot index byte
  - payload `+2`: item id word from record `+2`
  - payload `+4`: style/category byte from record `+4`
  - payload `+6`: display text copied from record `+6`
- It copies display text with `wcscpy_s(destination, 0x100, source)`.
- It appends the row with ListPane append helper `0x004f3c50`.
- It returns `this`.

The disassembly also shows constructor EH/unwind support which can call `sub_4F3B60` for base cleanup on failure. That is compiler support, not a separate source-level branch that should be represented in first-draft C++.

## ListPane Parser And Dispatcher Facts

`analyze_function 0x004f3a50` clarifies the ListPane constructor call. The current UID0002JO target text describes `205`/`170` as a visible row count. That is not the best current wording.

IDA decompilation of `0x004f3a50` shows:

- The first two arguments go into a primary list allocation: `sub_4F3060(v9, a2, a3)`.
- The primary list pointer is stored at ListPane `+0x130`.
- Selected index at `+0x134` is initialized to `-1`.
- A secondary/selection list is allocated with row size/count-like arguments `1` and `a3`.
- The selection list pointer is stored at `+0x138`.
- `sub_4B7C30(this+0x140, a5, a4)` consumes the `24` and `205/170` dimensions.
- The final byte flag is stored at ListPane `+0x149`.

Therefore UID0002JO should describe the constructor argument vector as:

- `sizeof(MyItemListEntry) == 0x20c` / 524 row payload bytes
- `8` row/list count or capacity argument
- mode-dependent extent `205` default / `170` high-res
- `24` paired dimension/row extent
- null callback/context pointer
- enabled selection/list flags `1, 1`

It should avoid preserving the old "visible row count 205/170" phrasing as a settled fact.

`analyze_function 0x004f3c50` confirms the append helper:

- It reads the primary list at `this+0x130`.
- It appends the row payload at the current primary count.
- It appends a zero byte into the secondary/selection list at `this+0x138`.
- It syncs/invalidates display state through ListPane/UI helper calls.

Source-facing name `AddEntry` is acceptable as a current-pass reconstruction name for this append helper, but exact original name is not recovered.

## Inventory Slot Accessor Facts

Fresh MCP and current UID0003U9 support agree:

- `0x005a3870` is `LivingObjectPane::GetInventorySlotAddress(char inventorySlot)`.
- The function sign-extends the byte slot argument.
- It returns `this + 0x133f08 + inventorySlot * 0x1fc`.
- Current incorporated C++ for UID0003U9 uses `LocalInventorySlotRecord *LivingObjectPane::GetInventorySlotAddress(char inventorySlot)`.
- `xrefs_to 0x005a3870` returned 39 code xrefs, including UID0002JO call site `0x004aebf6`.

For UID0002JO, the raw pointer at `dword_67A748` should be treated as the canonical user/living-object pane pointer already being recovered by support docs. Existing current support names indicate `g_pUserPane` as the best source-facing global spelling, with `g_pCollectionData`/`dword_67A748` as lower-quality raw/decompiler aliases.

## Inventory Count Global Facts

Fresh MCP `xrefs_to 0x0069ae0c` returned 67 references, including UID0002JO at `0x004aebbb`.

Current support page `by-global/g_activeUserStatusPane.md` establishes:

- `unk_69AE0C` / `dword_69AE0C` should be recovered as `g_activeUserStatusPane`.
- Offset `+0x284` supplies the inventory slot count / maximum item-slot selector byte.
- Source-facing field spelling `m_inventorySlotCount` is support-backed but still name-inferred.

UID0002JO should therefore replace raw `unk_69AE0C + 0x284` prose with `g_activeUserStatusPane->m_inventorySlotCount`, while keeping the raw offset in evidence notes.

## Row Payload And Local Slot Layout

Current support page `by-type/by-struct/MyItemListPaneEntryLayouts.md` plus MCP disassembly support this split:

Local inventory slot record returned by UID0003U9:

- `+0`: active byte
- `+2`: item id word
- `+4`: category/style byte
- `+6`: display text
- overall slot stride: `0x1fc`

MyItemListPane row payload passed to ListPane:

- `+0`: inventory slot index byte
- `+1`: padding/unwritten byte
- `+2`: item id word
- `+4`: category/style byte
- `+5`: padding/unwritten byte
- `+6`: wide display text buffer
- row payload size: `0x20c` / 524

The row buffer's two padding bytes are not initialized by UID0002JO. First-draft C++ should not introduce source-visible semantics for those padding bytes. A plain local row struct with assigned semantic fields is acceptable; zero-initializing the full payload is not binary-supported by this constructor.

The binary passes `0x100` as the `wcscpy_s` element count, even though the row payload support page currently describes a `wchar_t[259]` display field. First-draft C++ should preserve the explicit `0x100` copy count rather than replacing it with `_countof(entry.displayName)`.

## Vtable Facts

Current support page `by-type/by-vtable/MyItemListPaneVtables.md` and fresh MCP agree:

- Primary vtable: `0x00619f28`, stored at `0x004aeb9a`
- Secondary vtable: `0x00619fb0`, stored at `0x004aeba5`
- Tertiary vtable: `0x00619fe0`, stored at `0x004aebb1`
- Object offsets are `+0`, `+0xa0`, and `+0xa4`.

These are constructor compiler effects and should remain in evidence prose/vtable docs, not in source-level C++.

## Caller And Source-Placement Analysis

The four constructor callers show a reusable item list pane:

- AddItem-style flow
- MixItem-style flow
- ClanDep-style flow

This supports `by-file/MyItemListPane.md` as the source file and `by-class/MyItemListPane.md` as the semantic class owner. It rejects these alternatives:

- Not `AddItemDialog`: one AddItem caller exists, but the constructor is reused outside AddItem.
- Not `MixItemDialog`: Mix uses the pane, but the constructor is not Mix-owned.
- Not clan-bank/clan-only ownership: ClanDep use is a caller, not the type owner.
- Not `ItemDialogs.md` as the primary source file in the current documentation state: existing by-file support separates `MyItemListPane.md`, and generated output already places the empty marker in `NexusTK/ui/dialogs/MyItemListPane.cpp`.
- Not `ListPane`: UID0002JO is a derived-class constructor that calls ListPane but then installs MyItemListPane vtables and builds MyItemListPane-specific row payloads.

`by-file/ItemDialogs.md` can retain a note that MyItemListPane may have originated near item dialog code, but current target/source placement should remain `by-file/MyItemListPane.md`.

## Split And Range Analysis

The existing split remains correct:

- UID0002JO: `0x004aeb30-0x004aec77`, constructor
- UID0002JP: `0x004aec80-0x004aec8e`, selected-slot helper
- UID0002JQ: `0x004aec90-0x004af031`, DrawListEntry virtual/body
- UID00014U: `0x004aeb30-0x004af031`, parent aggregate, non-emitting

No split expansion or merge is recommended.

The constructor does not include UID0002JP or UID0002JQ logic. Conversely, UID0002JP and UID0002JQ depend on the row payload shape created by UID0002JO. Support docs should point to UID0002JO for row construction evidence and to UID0001VE for the shared row layout.

## Raw Helper Role Recovery

Raw helper names should be recovered as follows:

- `sub_4F3A50`: ListPane constructor/base initializer. It should not be documented as a MyItemListPane helper.
- `sub_4F3C50`: ListPane row append/add-entry helper. Current-pass source-facing name `AddEntry` is acceptable.
- `sub_5A3870`: `LivingObjectPane::GetInventorySlotAddress(char inventorySlot)`, already incorporated by UID0003U9.
- `_wcscpy_s`: direct CRT wide-string copy with explicit count `0x100`.
- `sub_4F3B60`: ListPane cleanup/destructor used by EH/unwind only; not source-body logic for UID0002JO.

## Negative Evidence Detail

No direct route evidence was found for these alternatives:

- No source tree or simroot file exists locally to confirm a third-party/original source body.
- No direct evidence recovers the original spelling of `MyItemListEntry`, `AddEntry`, `g_useHighResLayout`, or `m_inventorySlotCount`; these are best current source-facing names from support docs and role evidence.
- No evidence supports encoding vtable stores in source C++.
- No evidence supports emitting a generic decompiler-shaped body using raw globals `unk_69AE0C` or `dword_67A748`.
- No evidence supports zero-initializing the row payload before field assignment.
- No evidence supports folding UID0002JO into AddItemDialog, MixItemDialog, ClanBank, or ListPane ownership.

## Shared UID0002JQ / UID0002JP Separation

UID0002JO creates the row payload that UID0002JP and UID0002JQ later consume:

- UID0002JP reads the selected row payload byte at `+0` and returns the selected inventory slot.
- UID0002JQ renders the row payload fields at `+2`, `+4`, and `+6`.

This report does not recommend changing UID0002JP or UID0002JQ bodies during UID0002JO incorporation. It does recommend that support docs explicitly keep the shared row layout in UID0001VE so all three children refer to the same payload model.

If implementation decides to correct ownership routing for UID0002JO to class UID00008W, sibling UID0002JP/UID0002JQ should be audited later for the same class-route cleanup. That sibling cleanup is consistency work, not a prerequisite for the constructor score raise.

## First-Draft C++ Recommendation

UID0002JO can move from no-body marker to first-draft C++ only if the support layer provides:

- a row payload struct for `MyItemListEntry`;
- a class-level child emission marker if UID0002JO is rerouted through UID00008W;
- current source-facing names for the user pane pointer, active user status pane, inventory count field, and ListPane append helper.

The constructor's control flow itself is fully recovered. Remaining risk is naming and support declarations, not unknown binary behavior. Therefore this is not a "no C++" case; it is a "C++ body is safe with documented support scaffolding" case.

### UID0002JO RECONSTRUCTION_CPP CODE

The following is the exact formal `RECONSTRUCTION_CPP CODE` insertion text recommended for UID0002JO after support scaffolding is incorporated:

```cpp
MyItemListPane::MyItemListPane()
    : ListPane(sizeof(MyItemListEntry), 8, g_useHighResLayout ? 170 : 205, 24, 0, true, true)
{
    const unsigned char inventorySlotCount = g_activeUserStatusPane->m_inventorySlotCount;

    for (char slotIndex = 1; slotIndex <= inventorySlotCount; ++slotIndex) {
        LocalInventorySlotRecord *slot = g_pUserPane->GetInventorySlotAddress(slotIndex);
        if (!slot->active)
            continue;

        MyItemListEntry entry;
        entry.slotIndex = slotIndex;
        entry.itemId = slot->itemId;
        entry.iconStyle = slot->iconStyle;
        wcscpy_s(entry.displayName, 0x100, slot->displayName);

        AddEntry(&entry);
    }
}
```

This is not illustrative sample code. It is the proposed exact UID0002JO formal block content for supervisor-approved insertion.

### UID0001VE Support RECONSTRUCTION_CPP CODE

The row payload declaration should be emitted before UID0002JO if not already supplied elsewhere:

```cpp
struct MyItemListEntry
{
    unsigned char slotIndex;
    unsigned char reserved1;
    unsigned short itemId;
    unsigned char iconStyle;
    unsigned char reserved5;
    wchar_t displayName[259];
};
```

The reserved fields are documented padding. UID0002JO does not initialize them.

### UID00008W Support RECONSTRUCTION_CPP CODE

If UID0002JO changes `EMITTER_UIDS` from `0000LO` to `00008W`, ensure `by-class/MyItemListPane.md` can pass through child emissions:

```cpp
[[CHILDREN]]
```

No class declaration is recommended in this pass because the full field layout and declaration shape are not recovered to source quality.

## Score And Metadata Recommendation

Recommended target metadata after incorporation:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00008W`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00008W`

Score rationale:

- Completion rises because the constructor body, ListPane argument vector, inventory accessor, row payload layout, and append behavior are now fully evidenced and source-ready.
- Completion remains below 90 because support declaration placement and exact original source spellings are still reconstructed, not directly sourced.
- Confidence rises because IDA MCP independently confirmed the current incorporated support facts and corrected the ListPane argument interpretation.
- Confidence remains at 90, not higher, because no original source file or symbols were found for exact method/helper/global names.

Score/source-quality blocker disposition:

- Class owner/source placement is resolved by recommending UID00008W as canonical owner and UID0000LO as file route.
- Constructor inheritance/base-call semantics are resolved by the ListPane constructor analysis.
- Field/type names are repair-planned through UID0001VE row payload support and existing UID0003U9/UID0000PS support.
- First-draft C++ readiness is resolved by the exact UID0002JO formal block above, conditional only on support scaffolding that is included in this report's implementation plan.
- Exact original spelling of inferred names is explicitly unresolved but does not block the score raise because behavior, layout, and route are current-pass evidenced.

## Recommended Incorporation Targets

Required target:

- `by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md`
  - Update score to `88/90`.
  - Correct owner/emitter to UID00008W.
  - Keep reconstructable true.
  - Replace old "visible row count 205/170" wording with the ListPane argument analysis above.
  - Add MCP session evidence, constructor call/callee facts, caller fanout, vtable stores, row payload, inventory slot count, and no-direct-route negative evidence.
  - Insert the exact formal C++ body above only after support scaffolding is present.

Required support:

- `by-class/MyItemListPane.md`
  - Add/confirm class owns constructor UID0002JO.
  - Add a child emission marker if UID0002JO is routed through the class.
  - Note that full class declaration remains pending.

- `by-file/MyItemListPane.md`
  - Note that generated output currently has only empty markers and that UID0002JO is now first-draft C++ ready through class UID00008W.
  - Keep source placement in `NexusTK/ui/dialogs/MyItemListPane.cpp`.

- `by-type/by-struct/MyItemListPaneEntryLayouts.md`
  - Confirm row payload size `0x20c` and emit/support `MyItemListEntry` if needed by the constructor body.
  - Preserve the distinction between LocalInventorySlotRecord and MyItemListEntry row payload.

Optional consistency support:

- `by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md`
- `by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md`

These sibling pages may need later class-owner/emitter consistency and shared row-layout references, but UID0002JO does not require changing their bodies in this pass.

## Claim And Incorporation Ledger

| Claim | Destination | Action | Verification State | Callback Verification Proof |
|---|---|---|---|---|
| UID0002JO range is exactly `0x004aeb30-0x004aec77`. | `by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md` | incorporate | applied | Target IDA notes now include active B003 MCP range/function-size proof; target validator final rerun `000000004570` returned `ok: 1`. |
| Constructor calls ListPane constructor with `0x20c, 8, 205/170, 24, 0, 1, 1`. | UID0002JO target; `by-class/MyItemListPane.md` | incorporate | applied | Target behavior and class layout notes now use the exact argument vector and source call form. |
| `0x20c` is row payload size and matches MyItemListEntry layout. | UID0002JO target; `by-type/by-struct/MyItemListPaneEntryLayouts.md` | incorporate | applied | Target references UID0001VE; UID0001VE now emits `struct MyItemListEntry`; generated output places UID0001VE before UID0002JO after command `000000004571`. |
| `205/170` is a mode-dependent dimension/extent, not proven visible row count. | UID0002JO target; `by-class/MyItemListPane.md`; `by-file/MyItemListPane.md` | incorporate | applied | Old visible-row wording was replaced or corrected with mode-dependent extent wording in target/class/file notes. |
| Constructor installs three MyItemListPane vtables. | UID0002JO target; `by-type/by-vtable/MyItemListPaneVtables.md` | incorporate | applied | Target evidence notes cite the vtable stores as compiler effects and the C++ body omits explicit vtable writes; UID0001Y8 already had store/base detail. |
| Inventory count is `g_activeUserStatusPane->m_inventorySlotCount` at `+0x284`. | UID0002JO target; `by-file/MyItemListPane.md` | incorporate | applied | Target behavior/C++ and file data caveat use the source-facing status-pane field while preserving raw `+0x284` evidence. |
| Slot accessor is `LivingObjectPane::GetInventorySlotAddress(char)`. | UID0002JO target; UID0003U9 accessor page | incorporate | applied | Target behavior/C++ references UID0003U9 and `g_pUserPane->GetInventorySlotAddress`; validator reports `missing_ref_uid 0003U9` as validator-owned state, not doc omission. |
| Active slot check is record `+0`. | UID0002JO target; UID0001VE support | incorporate | applied | Target behavior and formal C++ use `slot->active`; UID0001VE preserves record `+0x00` active flag. |
| Item id/style/display text fields are record `+2/+4/+6`. | UID0002JO target; UID0001VE support | incorporate | applied | Target behavior/C++ and UID0001VE list the matching field copies and row offsets. |
| Row append helper is ListPane append/add-entry. | UID0002JO target | incorporate | applied | Target raw-helper section and formal C++ use `AddEntry(&entry)` with the `0x004f3c50` role documented. |
| Caller fanout rejects AddItem/Mix/Clan-only ownership. | UID0002JO target; `by-class/MyItemListPane.md`; `by-file/MyItemListPane.md` | incorporate | applied | Target, class, and file notes preserve the caller fanout and rejected owner alternatives. |
| Direct owner should be class UID00008W, file route UID0000LO. | UID0002JO target; `by-class/MyItemListPane.md`; `by-file/MyItemListPane.md` | incorporate | applied | Target header is `CANONICAL_OWNER:00008W`, `EMITTER_UIDS:00008W`; class has `[[CHILDREN]]`; file retains `NexusTK/ui/dialogs/MyItemListPane.cpp`. |
| First-draft C++ is safe with support scaffolding. | UID0002JO target; UID0001VE support; UID00008W support | incorporate | applied | Target has exact constructor body; UID0001VE emits row struct with `EMITTER_POSITION_OPTIONAL:0`; UID0002JO uses `EMITTER_POSITION_OPTIONAL:10`; generated output contains struct before constructor. |
| Exact original source names are not directly recovered. | UID0002JO target; relevant support notes | incorporate | applied | Target and support notes preserve naming caveats for inferred names and rejected raw/decompiler names. |

## Implementation Tracking Checklist

- [x] Applied: leased only `by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md`, `by-class/MyItemListPane.md`, `by-file/MyItemListPane.md`, and `by-type/by-struct/MyItemListPaneEntryLayouts.md` for the callback edit/validator batch.
- [x] Applied: updated UID0002JO metadata to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00008W`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008W`, plus `EMITTER_POSITION_OPTIONAL:10` for support declaration ordering.
- [x] Applied: incorporated MCP session/evidence state into UID0002JO.
- [x] Applied: corrected the ListPane constructor argument description, including row payload size `0x20c`, count/capacity argument `8`, mode-dependent extent `205/170`, dimension `24`, and pointer/flag arguments `0,1,1`.
- [x] Applied: incorporated inventory count, accessor, active-slot, row payload, `wcscpy_s(0x100)`, and append facts.
- [x] Applied: added caller fanout and rejected owner/split alternatives.
- [x] Applied: added first-draft C++ readiness proof and exact UID0002JO `RECONSTRUCTION_CPP CODE` body.
- [x] Applied: updated UID0001VE support with `MyItemListEntry`, `EMITTER_POSITION_OPTIONAL:0`, row payload size `0x20c`, LocalInventorySlotRecord distinction, padding, and explicit `0x100` copy count.
- [x] Applied: updated UID00008W support with marker-only `[[CHILDREN]]` so class routing passes child emissions.
- [x] Applied: updated UID0000LO file support with source-placement and generated-state note.
- [x] Applied: ran scoped validators for each changed by-* file from `source-3/project-documentation` using `--apply --queue-timeout 240`; command details are recorded below.
- [x] Applied: generated `auto-generated/NexusTK/ui/dialogs/MyItemListPane.cpp` refreshed to `validator-command-id: 000000004571`, `validator-refreshed-at: 2026-07-02T15:02:08-04:00`, and now emits `MyItemListEntry` before UID0002JO's constructor body.
- [x] Applied with cleanup note: B003 release command after validators found no active B003 lease on UID0002JO and reported overlapping support leases had already been acquired by B004. Current lease report shows no B003 active leases; B004 owns `by-class/MyItemListPane.md`, `by-file/MyItemListPane.md`, and `by-type/by-struct/MyItemListPaneEntryLayouts.md` until `2026-07-02T19:09:50Z`.

## Validator And Lifecycle Status

Scoped validators run during implementation callback:

- `python .\tools\validator.py --mode file --file by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md --apply --queue-timeout 240`
  - Initial command `000000004566`, timestamp `2026-07-02T15:00:50-04:00`, exit code `0`, `ok: 1`; applied completion/confidence/canonical owner/emitter registry updates; warning `missing_ref_uid 0003U9`.
  - Final rerun command `000000004570`, timestamp `2026-07-02T15:02:03-04:00`, exit code `0`, `ok: 1`; applied `EMITTER_POSITION_OPTIONAL:10`; warning `missing_ref_uid 0003U9`.
- `python .\tools\validator.py --mode file --file by-class/MyItemListPane.md --apply --queue-timeout 240`
  - Command `000000004567`, timestamp `2026-07-02T15:01:00-04:00`, exit code `0`, `ok: 1`; registered nonblank class child-marker block; no target-specific warning.
- `python .\tools\validator.py --mode file --file by-file/MyItemListPane.md --apply --queue-timeout 240`
  - Command `000000004568`, timestamp `2026-07-02T15:01:10-04:00`, exit code `0`, `ok: 1`; no target-specific warning.
- `python .\tools\validator.py --mode file --file by-type/by-struct/MyItemListPaneEntryLayouts.md --apply --queue-timeout 240`
  - Initial command `000000004569`, timestamp `2026-07-02T15:01:17-04:00`, exit code `0`, `ok: 1`; registered nonblank row-layout block; warnings `missing_ref_uid 0003U9` twice.
  - Final rerun command `000000004571`, timestamp `2026-07-02T15:02:08-04:00`, exit code `0`, `ok: 1`; applied `EMITTER_POSITION_OPTIONAL:0`; warnings `missing_ref_uid 0003U9` twice.

Generated-refresh state:

- Generated refresh was initially deferred by each validator command.
- Read-only generated check confirms `auto-generated/NexusTK/ui/dialogs/MyItemListPane.cpp` caught up to `validator-command-id: 000000004571`, `validator-refreshed-at: 2026-07-02T15:02:08-04:00`.
- Generated output now contains UID0001VE `struct MyItemListEntry` before UID0002JO `MyItemListPane::MyItemListPane()` and leaves UID0001Y8, UID0002JP, and UID0002JQ as empty markers.

Validator-owned diagnostics:

- `missing_ref_uid 0003U9` remains reported for target/struct pages because UID0003U9 is not present in `validator.ini`. This callback did not edit validator state or run registry lifecycle repair commands.

Lease cleanup:

- Initial B003 leases succeeded for the four edited by-* files: UID0002JO target, `by-class/MyItemListPane.md`, `by-file/MyItemListPane.md`, and `by-type/by-struct/MyItemListPaneEntryLayouts.md`.
- Release command after the edit/validator batch returned: target `Rejected[No active lease]`; class/file/struct `Rejected[Lease owned by B004]`.
- Current `tools/leaser/Agents/current_leases.md` shows no B003 active leases. B004 holds overlapping support leases created `2026-07-02T19:04:50Z`, expiring `2026-07-02T19:09:50Z`. No B004 leases were modified.

No report execution, report lifecycle, archive, registry lifecycle, manual report move, generated/coverage manual edit, queue edit, validator state edit, or supervisor-ledger edit was performed.

## Report-Only Changed File

- `tools/leaser/Agents/Agent-B003/research/0002JO-MyItemListPaneConstructor-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004585","destination_path":"executed-b-agent-research/B003/0002JO-MyItemListPaneConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002JO-MyItemListPaneConstructor-source-quality.md","timestamp":"2026-07-02T15:10:54-04:00","uid":"0002JO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
