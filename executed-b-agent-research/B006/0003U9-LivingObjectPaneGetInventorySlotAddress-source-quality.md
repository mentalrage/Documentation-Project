** TARGET-REPORT-UID:0003U9 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003U9 **
# B006 Source-Quality Reanalysis: UID 0003U9 - LivingObjectPaneGetInventorySlotAddress

Assignment: `B006-goal2-livingobject-inventory-slot-address-source-quality-0003U9-20260619`

Target: [UID:0003U9] `by-memory/0x005a3870-0x005a3889.LivingObjectPaneGetInventorySlotAddress.md`

Report status: report-only. I did not edit any `by-*` documentation file and did not edit `by-memory/-coverage-report.md`.

## Executive Recommendation

Promote the target from the current placeholder into a source-quality tiny accessor:

```cpp
LocalInventorySlotRecord *LivingObjectPane::GetInventorySlotAddress(char inventorySlot)
{
    return &m_inventorySlots[inventorySlot];
}
```

Recommended target metadata:

| Field | Recommended value | Rationale |
| --- | --- | --- |
| `COMPLETION` | `88` | Exact half-open range, body, caller set, slot-table base/stride, key slot fields, owner/source placement, rejected alternatives, support-doc deltas, and first-draft C++ are now source-quality. |
| `CONFIDENCE` | `91` | Local IDA exports, existing live-IDA-backed docs, and caller field usage agree. Confidence stays below final-audit level because the exact original struct typedef and original member spelling are inferred rather than recovered from symbols. |
| `CANONICAL_OWNER` | `00007B` | Keep [UID:00007B] `LivingObjectPane`; this is a `LivingObjectPane` local-player extension child, not an inventory-pane or item-dialog-owned helper. |
| `RECONSTRUCTABLE` | `TRUE` | The body is normal source-authored code and clears the project code-entry gate. |
| `EMITTER_UIDS` | `00007B` | Emit through `LivingObjectPane` and ultimately [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`. |

Best source-facing names:

| Element | Recommendation |
| --- | --- |
| Method | `LivingObjectPane::GetInventorySlotAddress` |
| Signature | `LocalInventorySlotRecord *GetInventorySlotAddress(char inventorySlot)` |
| Return type | `LocalInventorySlotRecord *` as the strongest source-facing project typedef candidate; `InventorySlotRecord *` is an acceptable shorter alias if support docs prefer that spelling. Do not leave it as `int`, `_DWORD`, or `void *`. |
| Parameter | `char inventorySlot`, not `int` or `unsigned char`; the body sign-extends the stack byte with `movsx`. |
| Backing member | `m_inventorySlots` at adjusted local-player/LivingObjectPane offset `+0x133f08`. |
| Record stride | `0x1fc` / decimal `508` bytes, verified with `tools/int_convert.py`. |

The method returns a local-player inventory slot record address. It does not return a command slot, spell slot, object entry, generic item metadata record, or broad local-player base pointer.

## Evidence Checked

Primary target and project docs:

- `by-memory/0x005a3870-0x005a3889.LivingObjectPaneGetInventorySlotAddress.md`
- `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
- `by-class/LivingObjectPane.md`
- `by-file/LivingObjectPane.md`
- `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`
- `by-global/g_pCollectionData.md`
- `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md` through search hits
- `by-type/by-struct/MyItemListPaneEntryLayouts.md`
- `by-memory/0x004ef970-0x004ef9f4.InventoryPane2VisibleIndexToInventorySlot.md`
- `by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md`
- representative caller/support docs for EmployeeDialogPane, AddEmployeeItemDialog, MyItemListPane, MixItemDialog/AddMixingItemDialog, InventoryPane/NewInventoryPane/InventoryPane2, ClientItemMenuDialog, MacroDialogs, and SystemMessagePanes.

Local IDA export files checked:

- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`
- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.c`
- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.map`

Searches/rechecks performed:

- `rg` for `0003U9`, `005a3870`, `sub_5A3870`, `GetInventorySlotAddress`, inventory slot/slot record wording across current docs and Agent research.
- Local `.lst` direct-call extraction for every `call sub_5A3870`.
- Local `.c` decompiler extraction for all `sub_5A3870(...)` occurrences.
- Local `.map` and `.lst` caller attribution for direct call sites.
- `tools/int_convert.py` conversions for `0x133f08`, `0x1fc`, `0x1e8`, `0x1ec`, and `0x1f8`.
- Scoped validator baseline commands listed near the end of this report.

## Exact Range And Body

The target half-open range remains exactly `0x005a3870-0x005a3889`.

Local `.lst` evidence:

```asm
.text:005A386A align 10h
.text:005A3870 sub_5A3870 proc near
.text:005A3870 arg_0= byte ptr  8
.text:005A3870 push    ebp
.text:005A3871 mov     ebp, esp
.text:005A3873 movsx   eax, [ebp+arg_0]
.text:005A3877 add     ecx, 133F08h
.text:005A387D imul    eax, 1FCh
.text:005A3883 add     eax, ecx
.text:005A3885 pop     ebp
.text:005A3886 retn    4
.text:005A3886 sub_5A3870 endp
.text:005A3889 align 10h
.text:005A3890 sub_5A3890 proc near
```

Body interpretation:

- `ECX` is the `this` pointer.
- The single stack argument is a byte read from `[ebp+8]`.
- The argument is sign-extended, so source should use `char inventorySlot` unless later original source evidence proves a typedef whose ABI still sign-extends.
- The table base is `this + 0x133f08`.
- The stride is `0x1fc`.
- The return is `this + 0x133f08 + 0x1fc * inventorySlot`.
- There is no bounds check, no null check, no subtraction, and no callee call.
- `retn 4` confirms a one-argument `thiscall` helper.

Local `.c` decompiler evidence:

```cpp
int __thiscall sub_5A3870(void *this, char a2)
{
  return (int)this + 508 * a2 + 1261320;
}
```

The decompiler's `int` return is not source-significant. Every meaningful caller treats the value as an address and dereferences fields.

`tools/int_convert.py` verified:

| Hex | Decimal |
| --- | ---: |
| `0x133f08` | `1261320` |
| `0x1fc` | `508` |
| `0x1e8` | `488` |
| `0x1ec` | `492` |
| `0x1f8` | `504` |

## Slot Table And Record Layout

The returned table is a local inventory slot table with one-based slot selectors in normal UI flows. The helper itself does not enforce one-based range; it returns the address for the exact signed byte argument.

Recommended backing member:

```cpp
LocalInventorySlotRecord m_inventorySlots[/* local-player inventory slots; normal validated selectors are 1..52 */];
```

Recommended partial record layout:

```cpp
struct LocalInventorySlotRecord
{
    uint8_t active;                 // +0x000
    uint8_t _pad001;                // +0x001
    uint16_t itemId;                // +0x002
    uint8_t iconStyle;              // +0x004
    uint8_t _pad005;                // +0x005
    wchar_t displayName[241];       // +0x006, inferred maximum before +0x1e8
    uint32_t quantityOrCount;       // +0x1e8
    uint8_t quantityPromptFlag;     // +0x1ec
    uint8_t _unknown1ed_1f7[0x0b];  // +0x1ed..+0x1f7
    uint8_t targetMode;             // +0x1f8
    uint8_t _unknown1f9_1fb[0x03];  // +0x1f9..+0x1fb
};
static_assert(sizeof(LocalInventorySlotRecord) == 0x1fc);
```

Evidence for known fields:

| Offset | Evidence | Best-supported meaning |
| --- | --- | --- |
| `+0x00` | MyItemListPane constructor and inventory visible-index scanners test `*record != 0`; `UseInventorySlotDispatch` also tests the selected slot record active byte. | Occupied/active/non-empty flag. |
| `+0x02` | MyItemListPane copies this word into list-row payload and item icon draw reads it. | Item id. |
| `+0x04` | MyItemListPane copies this byte into row payload and icon draw uses it. | Item style/category/icon variant byte. |
| `+0x06` | MyItemListPane, item menu, macro paint, and message helpers add `6` to the returned pointer and treat it as a wide display string. | Item display name/text. |
| `+0x1e8` | Employee and mix dialog paths push/read this dword when quantity/count behavior is not prompted or when stack counts are serialized. | Quantity/count/value payload; exact original name unresolved. |
| `+0x1ec` | Employee and mix dialog paths compare this byte to zero before opening quantity prompts; docs describe it as stack-like/quantity behavior. | Quantity prompt / stackable flag. |
| `+0x1f8` | `UseInventorySlotDispatch` reads `selectedSlot + 0x1f8` as the target-mode branch source. | Item-use target mode. |

The existing `MyItemListPaneEntryLayouts` page currently says the inventory slot record text is `wchar_t[259]`. That cannot be the exact returned slot-record field if the same record has confirmed fields at `+0x1e8`, `+0x1ec`, and `+0x1f8` inside a `0x1fc` stride. The best closure is:

- Preserve `+0x06` as the display-name pointer.
- Use `wchar_t[241]` only as an inferred maximum contiguous field bound if a C++ struct declaration is needed now.
- Keep the exact original declared text bound as "not recovered"; do not keep the `259` count as slot-record truth unless a later pass proves the support doc meant a row payload buffer, not the returned inventory slot record.

## Direct Caller Set

Local `.lst` export search found 39 direct `call sub_5A3870` sites. Grouping by modeled function start gives 25 caller functions.

| Call site | Modeled caller | Caller family / current source role | Observed use |
| --- | --- | --- | --- |
| `0x004a248c` | `0x004a2450` / [UID:0003KT] `EmployeeInventoryItemCommandHelper` | Employee dialog file-local inventory item command helper | Reads selected inventory slot record, tests `+0x1ec`, uses `+0x1e8` for direct employee command count or opens quantity input. |
| `0x004a4bf8` | `0x004a4b20` / [UID:00013A] `AddEmployeeItemDialog::OnButtonClick` | Employee add-item dialog | Same stack/quantity branch over selected slot: tests `+0x1ec`, reads `+0x1e8`. |
| `0x004aebf6` | `0x004aeb30` / `MyItemListPane` constructor | Item list pane row population | Loops one-based slots, tests `+0x00`, copies `+0x02/+0x04/+0x06` into row payload. |
| `0x004af1d0` | `0x004af040` / `AddItemWithCountDialogCore` | Add item-with-count dialog | Adds `+0x06` to format item name in prompt/display text. |
| `0x004afae6` | `0x004af8b0` / `MixItemDialogCore` | Mix item dialog action/selection logic | Tests `+0x1ec` for quantity/stack behavior. |
| `0x004afc45` | `0x004af8b0` / `MixItemDialogCore` | Mix item dialog action/selection logic | Tests `+0x1ec` in another branch. |
| `0x004afd26` | `0x004afcc0` / [UID:000319] `MixItemDialogQuantityPromptHelper` | Mix quantity prompt helper | Compares `+0x1e8` with `1` and reads count when constructing quantity behavior. |
| `0x004afea1` | `0x004afe40` / [UID:00031A] `MixItemDialogQuantityCallback` | Mix quantity callback | Reads `+0x1e8` during row/payload update. |
| `0x004b029c` | `0x004b0120` / [UID:0002U2] `AddMixingItemDialogOnConfirm` | Add-mixing confirmation dialog | Tests `+0x1ec` and uses `+0x1e8` for stack/count behavior. |
| `0x004b031c` | `0x004b0120` / [UID:0002U2] `AddMixingItemDialogOnConfirm` | Add-mixing confirmation dialog | Compares `+0x1e8` with `1` and reads count. |
| `0x004c7971` | `0x004c78e0` / `WillBeChangedItemPane` constructor/core | Temporary item preview/help pane | Reads selected inventory item record for preview state. |
| `0x004c83a3` | `0x004c82d0` / `ItemHelpPane` constructor | Rich item help pane | Reads selected inventory item record while building help/tooltip data. |
| `0x004ea368` | `0x004ea2a0` / `InventoryPane::OnPaint` | Legacy inventory rendering | Reads slot record while drawing inventory items. |
| `0x004ea3e8` | `0x004ea2a0` / `InventoryPane::OnPaint` | Legacy inventory rendering | Reads slot record while drawing inventory items. |
| `0x004ea5d8` | `0x004ea2a0` / `InventoryPane::OnPaint` | Legacy inventory rendering | Reads slot record while drawing inventory items. |
| `0x004ea61b` | `0x004ea2a0` / `InventoryPane::OnPaint` | Legacy inventory rendering | Reads slot record while drawing inventory items. |
| `0x004ea69b` | `0x004ea2a0` / `InventoryPane::OnPaint` | Legacy inventory rendering | Reads slot record while drawing inventory items. |
| `0x004ea7e8` | `0x004ea2a0` / `InventoryPane::OnPaint` | Legacy inventory rendering | Reads slot record while drawing inventory items. |
| `0x004eb3c8` | `0x004eb390` / `InventoryPane::MapVisibleSlotToInventorySlot` | Legacy visible-index mapper | Scans records, skips empty entries, maps visible ordinal to one-based physical inventory slot. |
| `0x004eb7e5` | `0x004eb6c0` / NewInventoryPane helper | New inventory helper | Reads record during inventory display/list helper path. |
| `0x004ebcee` | `0x004ebb20` / NewInventoryPane paint | New inventory rendering | Reads record while drawing list/grid inventory items. |
| `0x004ec17c` | `0x004ebb20` / NewInventoryPane paint | New inventory rendering | Reads record while drawing list/grid inventory items. |
| `0x004ec2ec` | `0x004ebb20` / NewInventoryPane paint | New inventory rendering | Reads record while drawing list/grid inventory items. |
| `0x004ed8ef` | `0x004ecb50` / NewInventoryPane mouse/input | New inventory interaction | Resolves selected/hovered inventory slots for mouse behavior. |
| `0x004ee3f5` | `0x004ee3c0` / NewInventoryPane tail helper | New inventory tail/helper path | Reads/scans inventory slot record. |
| `0x004ee425` | `0x004ee3c0` / NewInventoryPane tail helper | New inventory tail/helper path | Reads/scans inventory slot record. |
| `0x004ee7b9` | `0x004ee6f0` / `InventoryPane2::OnPaint` | Alternate inventory rendering | Reads record while drawing alternate list/grid item layouts. |
| `0x004ee843` | `0x004ee6f0` / `InventoryPane2::OnPaint` | Alternate inventory rendering | Reads record while drawing alternate list/grid item layouts. |
| `0x004eea68` | `0x004ee6f0` / `InventoryPane2::OnPaint` | Alternate inventory rendering | Reads record while drawing alternate list/grid item layouts. |
| `0x004eeaf9` | `0x004ee6f0` / `InventoryPane2::OnPaint` | Alternate inventory rendering | Reads record while drawing alternate list/grid item layouts. |
| `0x004eeb86` | `0x004ee6f0` / `InventoryPane2::OnPaint` | Alternate inventory rendering | Reads record while drawing alternate list/grid item layouts. |
| `0x004eed68` | `0x004ee6f0` / `InventoryPane2::OnPaint` | Alternate inventory rendering | Reads record while drawing alternate list/grid item layouts. |
| `0x004ef9a8` | `0x004ef970` / [UID:0003EP] `InventoryPane2VisibleIndexToInventorySlot` | Alternate visible-index mapper | Scans records, skips empty entries, maps visible ordinal to physical slot. |
| `0x0051ba9f` | `0x0051b880` / `ClientItemMenuDialog` constructor | Client item-menu dialog | Resolves packet/menu entry bytes into local inventory rows. |
| `0x0051bfce` | `0x0051b880` / `ClientItemMenuDialog` constructor | Client item-menu dialog | Resolves later menu rows or formatting through inventory record. |
| `0x0057faf4` | `0x0057faa0` / `NewMacroEditControlPane::OnPaint` | Macro editor display | Uses `+0x06` item name for inventory macro rows. |
| `0x005801b9` | `0x0057ffb0` / `IntegrateMacroEditControlPane::OnPaint` | Integrated macro editor display | Uses `+0x06` item name for inventory macro rows. |
| `0x00587766` | `0x005876e0` / `SystemMessagePane` helper | Status/system message formatting | Resolves valid inventory slot and formats localized item/status text. |
| `0x0058a966` | `0x0058a8e0` / `OldSystemMessagePane` helper | Old status/system message formatting | Resolves valid inventory slot and formats localized item/status text. |

This direct caller set supports broad shared accessor ownership. It is not local to inventory panes or item dialogs, because the same helper is also used by employee dialogs, mix dialogs, client item menus, help panes, macro painting, and system-message/status text formatting.

## Heuristic / Inference Reanalysis And Validation

### Compiler/generated name: `sub_5A3870`

Best inference: source method `LivingObjectPane::GetInventorySlotAddress`.

Evidence:

- The target page and local-player split index already use `GetInventorySlotAddress`.
- Body shape is a tiny `thiscall` address calculation over a fixed table inside the local-player/LivingObjectPane state.
- Callers dereference the result as a record, not as a computed scalar.
- The name accurately describes the operation without overclaiming that the helper validates slots or fetches item metadata by item id.

Rejected:

- `GetItemMetadata`: wrong key semantics. Callers pass inventory slot selectors, and MyItemListPane confirms row payload `+0x00` is the source inventory slot id.
- `GetItemById`: wrong because the helper performs `base + stride * slot`, not a search by item id.
- `GetObjectEntry`: wrong because callers use inventory item fields and display-name strings, not map/object entries.
- `GetCommandSlot`: wrong because command/spell slot storage is documented separately at `dword_67A748 + 0x13a6ec + slot * 0x148`.

### Decompiler return type: `int`

Best inference: pointer to `LocalInventorySlotRecord`.

Evidence:

- Decompiler returns `int` only because IDA has no struct type.
- Callers immediately use the return as an address, with dereferences at `+0x00`, `+0x02`, `+0x04`, `+0x06`, `+0x1e8`, `+0x1ec`, and `+0x1f8`.
- `MyItemListPaneEntryLayouts` already describes the relevant inventory-slot record fields.

Rejected:

- `int`: source-hostile and contradicts all callers.
- `DWORD *`: too generic and loses byte/word/string field evidence.
- `void *`: directionally possible but below source-quality because the record's major fields are known.

### Parameter type and slot indexing

Best inference: `char inventorySlot`.

Evidence:

- Local `.lst`: `arg_0= byte ptr 8`; `movsx eax, [ebp+arg_0]`.
- `UseInventorySlotDispatch` caller family validates normal selectors `1..52`.
- Inventory and item-list paths enumerate one-based physical slots, and the helper does not subtract one.
- The helper has no guard; validation is caller-owned.

Rejected:

- `unsigned char`: body uses `movsx`, not `movzx`.
- `int`: callers pass byte-sized selectors, and the body reads only one byte.
- Zero-based `slotIndex`: callers and list payload semantics use one-based inventory slots; the helper indexes the supplied byte directly.

### Global/base pointer: `dword_67A748` / `g_pCollectionData`

Best inference: broad local-player/UserPane state pointer, with `g_pCollectionData` retained only as a current typed-view alias.

Evidence:

- The global page records `0x0067a748` as a broad player-data pointer with UserPane lifetime writes and 505 direct xrefs.
- The same pointer backs collection, spell/command, item/gold, timer-owner, and inventory views.
- This target is called through `dword_67A748` in many UI paths, but that does not make the helper collection-owned.

Rejected:

- `g_pCollectionData` as final semantic owner: too narrow; this target's table is inventory/local-player state.
- `SpellManager` / `g_pSpellMan`: existing docs reject this generated interpretation for nearby spell-command slots; the inventory slot table is also on the local-player state object.
- New standalone inventory-table global: no evidence of separate storage; the helper uses `this`.

### Slot table versus command slot and object entry

Best inference: local inventory item slot record table at `this + 0x133f08`, stride `0x1fc`.

Evidence:

- Target body computes exactly that base and stride.
- `UseInventorySlotDispatch` separately documents `this[127 * slot + 315330]`; `315330 * 4 == 0x133f08` and `127 * 4 == 0x1fc`.
- `UseInventorySlotDispatch` reads `+0x1f8` as item-use target mode, matching inventory-item dispatch.
- `MyItemListPane` and inventory panes read item id/style/name from the same returned record.
- Employee/mix dialogs use `+0x1ec/+0x1e8` for stack/quantity behavior on selected inventory items.

Rejected:

- Spell/command slot table: existing docs place that at `+0x13a6ec + slot * 0x148`, not this table.
- Map/object entry table: object entries are selected through object-pane/map paths and object ids; this table is consumed by inventory UI and item dialogs.
- Generic "broader local-player slot address": true only of the containing object, too broad for this method's source-facing name.

### Field names

Best-supported current names:

- `m_inventorySlots` for the table.
- `LocalInventorySlotRecord::active` for `+0x00`.
- `LocalInventorySlotRecord::itemId` for `+0x02`.
- `LocalInventorySlotRecord::iconStyle` or `style` for `+0x04`; I prefer `iconStyle` in target docs because render callers use it for item icon selection, while item dialogs may call it category/style.
- `LocalInventorySlotRecord::displayName` for `+0x06`.
- `LocalInventorySlotRecord::quantityOrCount` for `+0x1e8`; do not over-name this as `stackCount` because some direct-add employee/mix paths use it as a count/value payload.
- `LocalInventorySlotRecord::quantityPromptFlag` for `+0x1ec`; this is stronger than generic `flags` because multiple dialog paths use it specifically to decide whether to prompt for quantity.
- `LocalInventorySlotRecord::targetMode` for `+0x1f8`; `UseInventorySlotDispatch` uses it for direct send versus selected-target versus explicit target prompt behavior.

Open-question closure:

- The exact original member spellings are not recoverable from current evidence. The report should not leave this as generic future work; use the names above as source-quality reconstruction names, with a caveat that original spelling may differ.
- Unknown bytes between `+0x1ed..+0x1f7` and `+0x1f9..+0x1fb` should be explicitly reserved/unknown. No evidence checked in this pass gave safe semantics for those bytes.

### Owner/source placement

Best inference: direct owner stays [UID:00007B] `LivingObjectPane`, source route [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`.

Evidence:

- The function is inside [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions`, whose exact source-bearing children route LivingObjectPane/UserPane/etc. by child. The target is already assigned `CANONICAL_OWNER:00007B` / `EMITTER_UIDS:00007B`.
- [UID:00007B] and [UID:0000KU] explicitly list the local-player movement/command inventory helpers as LivingObjectPane responsibilities.
- The helper has broad callers from inventory panes, item dialogs, help panes, macro controls, and system-message helpers; none of those caller families owns the table.
- `UserPane` owns the lifetime of `dword_67A748`, but project docs already distinguish local-player state pointer lifetime from `LivingObjectPane` local-player extension method ownership.

Rejected:

- `InventoryPane`/`NewInventoryPane` ownership: inventory panes are callers/consumers. They also have their own visible-index mappers that call this helper.
- `ItemDialogs` ownership: item dialogs use the selected inventory record but do not own the local-player inventory storage.
- `EmployeeDialogPane` ownership: employee helpers are consumers of item quantity fields.
- `ClientItemMenuDialog` ownership: it materializes menu rows from inventory slots but is not the storage owner.
- `UserPane` direct owner for this exact helper: plausible at the broad memory-address level, but weaker than the accepted [UID:0001KM] child routing and LivingObjectPane local-player extension docs.
- `g_pCollectionData` global owner: the global is a pointer dependency, not the method owner.

### Caller/reachability

Best inference: the helper is live and broadly reachable through ordinary direct calls.

Evidence:

- Local `.lst` contains 39 direct `call sub_5A3870` instructions.
- Local `.c` contains matching decompiler calls across employee, item, inventory, help, menu, macro, and system-message families.
- This is not a raw no-route helper, not a retained duplicate, and not compiler padding.

No-code proof is not applicable. First-draft C++ should be emitted when the target docs are implemented.

### Split/range decision

Best inference: keep `0x005a3870-0x005a3889` as an exact source-bearing child between `StartDirectionalAnimation` and successor `sub_5A3890`.

Evidence:

- Predecessor `sub_5A3770` ends at `0x005a386a`; `0x005a386a-0x005a3870` is alignment.
- The helper starts at `0x005a3870` and ends after `retn 4` at `0x005a3889`.
- `0x005a3889-0x005a3890` is alignment before successor `sub_5A3890`.
- The body is cohesive and no adjacent bytes belong to this helper.

Rejected:

- Merging into [UID:0001KM] aggregate: that page is a non-emitting split index.
- Merging with `0x005a3890` or adjacent table-copy helpers: no body fallthrough and the next function has independent logic.
- Leaving absent from coverage: current coverage skips this exact child even though the by-memory page exists and is reconstructable.

## First-Draft C++ Eligibility

The target is eligible for first-draft C++ now.

Gate check:

- Current target metadata is `RECONSTRUCTABLE:TRUE`.
- Current owner/emitter route is nonblank: `CANONICAL_OWNER:00007B`, `EMITTER_UIDS:00007B`.
- Current score average is `(85 + 87) / 2 = 86`, clearing the documented `>85` code-entry gate.
- The body is a normal modeled function with direct callers and no route-negative retained-helper issue.
- The return type and table stride are source-quality enough for a first draft.

Recommended C++ body:

```cpp
LocalInventorySlotRecord *LivingObjectPane::GetInventorySlotAddress(char inventorySlot)
{
    return &m_inventorySlots[inventorySlot];
}
```

If the implementation pass is not ready to introduce `LocalInventorySlotRecord` and `m_inventorySlots` declarations, a temporary body may document the raw offset equivalence in prose, but the formal C++ should not use `int` return or raw `void *` arithmetic unless the local class declaration cannot yet carry the field.

## Target Implementation Checklist

For `by-memory/0x005a3870-0x005a3889.LivingObjectPaneGetInventorySlotAddress.md`:

- Update metadata to `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`.
- Fill reconstruction C++ with:

```cpp
LocalInventorySlotRecord *LivingObjectPane::GetInventorySlotAddress(char inventorySlot)
{
    return &m_inventorySlots[inventorySlot];
}
```

- Document exact half-open range `0x005a3870-0x005a3889`.
- Document exact local IDA body: `movsx` stack byte, add `0x133f08`, multiply by `0x1fc`, return pointer, `retn 4`.
- Replace "inventory or slot-address style pointer" with "local-player inventory slot record pointer".
- Replace "slot-record layout unresolved" with the partial `LocalInventorySlotRecord` layout above.
- Explicitly state the helper is unguarded and caller validation owns slot bounds.
- Document the direct caller families and callsite count.
- Add rejected alternatives: command slot, spell slot, object entry, item metadata lookup, generic local-player pointer, InventoryPane/ItemDialogs/UserPane ownership.
- Add a `Changes` entry referencing B006 source-quality report-only findings.

## Support Implementation Checklist

Exact support docs to update if the report is accepted:

- `by-class/LivingObjectPane.md`
  - Add `LocalInventorySlotRecord *GetInventorySlotAddress(char inventorySlot);` to method families/local-player inventory/command section.
  - Add `m_inventorySlots` at adjusted local-player offset `+0x133f08`, with stride `0x1fc`, and preserve the caveat that large local-player offsets are not compact base-object fields.
  - Cross-reference [UID:0003U9].

- `by-file/LivingObjectPane.md`
  - Add the target to proposed contents/local player command or inventory slot helper rows.
  - Keep source route under `NexusTK/map/LivingObjectPane.cpp`.
  - State that exact child pages, not [UID:0001KM] aggregate, own C++ emission.

- `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
  - Expand the `0x005a3870-0x005a3889` row from generic `GetInventorySlotAddress` to source-quality `LocalInventorySlotRecord *GetInventorySlotAddress(char inventorySlot)`.
  - Add base `+0x133f08`, stride `0x1fc`, key fields, and child row cross-reference.
  - Keep the page non-emitting.

- `by-type/by-struct/MyItemListPaneEntryLayouts.md`
  - Clarify that the returned inventory slot record has `+0x06` display text but cannot safely be `wchar_t[259]` inside a `0x1fc` stride with late fields at `+0x1e8/+0x1ec/+0x1f8`.
  - Preserve row payload layout separately from returned slot record layout.
  - Link to [UID:0003U9] as the canonical slot-address helper.

- `by-memory/0x004ef970-0x004ef9f4.InventoryPane2VisibleIndexToInventorySlot.md`
  - Replace raw `sub_5A3870` wording with `LivingObjectPane::GetInventorySlotAddress(char inventorySlot)`.
  - State it scans `LocalInventorySlotRecord::active` records.

- `by-file/InventoryPane.md`, `by-file/NewInventoryPane.md`, and exact inventory pane memory pages if touched
  - Replace "global inventory collection" or raw `sub_5A3870` language with local-player inventory slot record lookup where current text remains generic.
  - Preserve that InventoryPane/InventoryPane2 own visible-index mapping and drawing, not the storage accessor.

- Employee and item dialog support docs:
  - `by-memory/0x004a2450-0x004a2531.EmployeeInventoryItemCommandHelper.md`
  - `by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md`
  - `by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md`
  - `by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md`
  - `by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md`
  - Replace "item metadata lookup" where present with "local inventory slot record lookup"; the selected byte is an inventory slot, not item id.
  - Name `+0x1e8` as quantity/count payload and `+0x1ec` as quantity-prompt/stack flag with caveat on exact original spelling.

- `by-class/ClientItemMenuDialog.md`, `by-file/ItemMenuDialogs.md`, and `by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md`
  - Cross-reference [UID:0003U9] for client item menu row population from local inventory slots.
  - Keep `actionId` wording from B013 for packet/list action bytes where server semantics require it; do not rename those action bytes to inventory slots globally.

- `by-class/NewMacroEditControlPane.md`, `by-class/IntegrateMacroEditControlPane.md`, `by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md`
  - Update item macro display wording to say item rows resolve `LocalInventorySlotRecord::displayName` through [UID:0003U9].

- `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md`
  - Cross-reference [UID:0003U9] for item/status message formatting when valid inventory slots are checked.

- `by-global/g_pCollectionData.md` and `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`
  - Add an "inventory slot view" row: `+0x133f08 + slot * 0x1fc` local-player inventory slot record table, source accessor [UID:0003U9].
  - Keep final global ownership as UserPane/local-player state; do not create a separate inventory global.

- `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md`
  - Cross-reference that `+0x284` supplies the current inventory slot count/limit used by callers before [UID:0003U9] lookup.

## Exact Supervisor-Owned Coverage Row

Current `by-memory/-coverage-report.md` contains the parent [UID:0001KM] row and child [UID:0002RW], then jumps to [UID:0001KN]. It does not currently include [UID:0003U9]. If the supervisor accepts this report, insert this exact child row in address order after [UID:0002RW] and before [UID:0001KN]:

```text
        - [UID:0003U9][0x005a3870-0x005a3889.LivingObjectPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.LivingObjectPaneGetInventorySlotAddress.md) 0x005a3870-0x005a3889 | helper method | LivingObjectPaneGetInventorySlotAddress : reconstructable : 88% : very-strong : B006 source-quality pass resolves the modeled 25-byte `thiscall` local-player inventory accessor as `LocalInventorySlotRecord *LivingObjectPane::GetInventorySlotAddress(char inventorySlot)`: local IDA exports confirm the exact half-open range, byte stack argument sign-extended with `movsx`, table base `this+0x133f08`, record stride `0x1fc` / 508 bytes, pointer return, and `retn 4`; direct call extraction finds 39 call sites across employee item commands, AddEmployeeItemDialog, MyItemListPane, AddItemWithCountDialog, MixItemDialog/AddMixingItemDialog, WillBeChangedItemPane, ItemHelpPane, legacy/New/InventoryPane2 rendering and visible-index mappers, ClientItemMenuDialog, macro edit-control painting, and system-message formatting; the returned record is a local inventory slot record with active byte `+0x00`, item id `+0x02`, icon/style byte `+0x04`, display text `+0x06`, quantity/count payload `+0x1e8`, quantity-prompt/stack flag `+0x1ec`, and item-use target mode `+0x1f8`; command/spell slot, object-entry, item-metadata-table, InventoryPane/ItemDialogs/UserPane direct ownership, and generic local-player pointer interpretations are rejected; owner/emitter remain [UID:00007B] `LivingObjectPane`, source route [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`, and first-draft C++ is ready.
```

## Scoped Validator Baseline

Commands run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0003U9-LivingObjectPaneGetInventorySlotAddress-source-quality-removed.md](0003U9-LivingObjectPaneGetInventorySlotAddress-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code `0`.
- `apply: False`.
- `scanned markdown files: 1`.
- `ok: 1`.
- `ok 0003U9 ... UID header exists`.
- `stats_incremental_skip` only because this was a dry run.

> Executable block R002 was removed from this report and preserved verbatim in [0003U9-LivingObjectPaneGetInventorySlotAddress-source-quality-removed.md](0003U9-LivingObjectPaneGetInventorySlotAddress-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code `0`.
- `apply: False`.
- `uid phase: True`, `reference phase: True`.
- `scanned markdown files: 1`.
- `ok: 1`.
- Target diagnostic: `ok 0003U9 ... UID header exists`.
- The full no-apply run also printed project autogen registry/noop and emitter-has-no-code lines for existing generated outputs; no target error was reported and no files were written.

## Open-Question Closure

Closed for implementation:

- Final helper role: local-player inventory slot record accessor.
- Final source-facing method name: `GetInventorySlotAddress`.
- Source-facing signature: `LocalInventorySlotRecord *LivingObjectPane::GetInventorySlotAddress(char inventorySlot)`.
- Exact half-open range: `0x005a3870-0x005a3889`.
- Table base/stride: `this + 0x133f08`, `0x1fc` bytes per record.
- Caller set: 39 direct call sites in local IDA exports, grouped above.
- Owner/source placement: [UID:00007B] `LivingObjectPane`, source route [UID:0000KU] `LivingObjectPane.cpp`.
- C++ readiness: yes, first-draft body ready.

Closed with explicit caveat, not generic future work:

- Original type/member spelling is not recovered. Use `LocalInventorySlotRecord`, `m_inventorySlots`, and the field names listed in this report as reconstruction names.
- Original display-name declared bound is not recovered. The safe implementation position is `displayName` at `+0x06` and, if a concrete partial struct is required now, an inferred maximum `wchar_t[241]` before `+0x1e8`.
- Unknown bytes inside the record are not named. Preserve them as reserved/unknown fields rather than inventing semantics.
- `g_pCollectionData` remains a view alias for broad local-player state; do not rename the global solely from this target.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003U9","source_path":"executed-b-agent-research/B006/0003U9-LivingObjectPaneGetInventorySlotAddress-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
