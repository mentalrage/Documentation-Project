** TARGET-REPORT-UID:00025A **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00025A ExchangeItemReadOnlyData Post-Migration Split Report

Revision: B002-00025A-post-migration, 2026-06-13

## Final Recommendation

Reclassify [UID:00025A] `by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md` as a reviewed, non-emitting mixed `.rdata` split index:

```text
*** COMPLETION:90
*** CONFIDENCE:94
*** CANONICAL_OWNER:NONE
*** RECONSTRUCTABLE:FALSE
*** EMITTER_UIDS:
*** EMITTER_POSITION_OPTIONAL:
```

`CANONICAL_OWNER:NONE` remains correct for the aggregate because no single source owner covers the whole range. Blank `EMITTER_UIDS` is also correct because the aggregate itself is not a source-level declaration/object. Exact child pages now carry source routing, while the middle item/mix vtable islands are already covered by exact by-type pages. Adding multiple emitters to the aggregate would incorrectly route unrelated `ExchangeDialog`, `ItemDialogs`, `MyItemListPane`, `ExchangeAlertPane`, `ExchangeMoneyEditControlPane`, and `FunctionObjects` data into each emitter.

B002 created and validated seven exact by-memory children:

| UID | Range | Owner | Emitter | Score |
| --- | --- | --- | --- | --- |
| `0003NE` | `0x00619d28-0x00619dc4` `ExchangeDialogVtableData` | `00004R` | `00004R` | `86/91` |
| `0003NF` | `0x00619dc4-0x00619e88` `ExchangeItemListPaneVtableData` | `00004S` | `00004S` | `85/90` |
| `0003NK` | `0x0061a1bc-0x0061a1c0` `ExchangeAlertPaneRttiLocatorPointer` | `00004Q` | `00004Q` | `85/90` |
| `0003NG` | `0x0061a304-0x0061a344` `ExchangeDialogResourceStrings` | `00004R` | `00004R` | `86/91` |
| `0003NH` | `0x0061a344-0x0061a374` `AddItemDialogResourceStrings` | `000007` | `000007` | `85/90` |
| `0003NI` | `0x0061a374-0x0061a37c` `AddItemWithCountDialogQuantityFormatString` | `000008` | `000008` | `85/89` |
| `0003NJ` | `0x0061a37c-0x0061a3ac` `MixItemDialogResourceStrings` | `00008J` | `00008J` | `86/91` |

B002 also repaired [UID:00004S] `ExchangeItemListPane` from `78/84` to `85/86`, preserving `CANONICAL_OWNER:0000J9` and `EMITTER_UIDS:0000J9`, so child [UID:0003NF] can clear the strict owner/emitter gate.

No final reconstruction C++ was entered. The aggregate is non-reconstructable, and the new children are source-declared/generated-binary vtable/RTTI/string data below the active 90/90 reconstruction-code bar.

## Required Supervisor Actions

1. Accept the by-* split already applied and validated by B002.
2. Do not manually edit `auto-generated/-ag-memory-coverage.md`; the normal validator flow already reports the target as `not_reconstructable` and the new children as `emits`.
3. Apply the `by-memory/-coverage-report.md` replacement block below. B002 did not edit that manual coverage report directly.
4. Update `tools/leaser/Agents/no_owner_b-agent-tracker.md` with the tracker row below after acceptance.
5. Move this report to `tools/leaser/Agents/Agent-B002/research/executed/` after supervisor execution.

Exact tracker replacement row:

```markdown
| `00025A` | `auto-generated/-ag-memory-coverage.md` | 0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData | `by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md` | yes | Agent-B002 | 2026-06-13 | yes | yes | `CANONICAL_OWNER:NONE`; blank `EMITTER_UIDS`; `RECONSTRUCTABLE:FALSE`; exact child emitters `0003NE`, `0003NF`, `0003NK`, `0003NG`, `0003NH`, `0003NI`, `0003NJ` | yes | B002-00025A-post-migration executed on 2026-06-13. Final outcome: aggregate is a reviewed non-emitting split index at `90/94`; B002 created/validated exact by-memory children for ExchangeDialog vtables, ExchangeItemListPane vtables, ExchangeAlertPane RTTI locator, ExchangeDialog/AddItem/AddItemWithCount/MixItem resource strings, and repaired `ExchangeItemListPane` to `85/86`. Middle item/mix vtable ranges remain covered by exact by-type pages; no aggregate owner/emitter is justified. Report: `Agent-B002/research/00025A-ExchangeItemReadOnlyData-post-migration.md`. |
```

Current generated main rows:

```markdown
| [UID:0003NE][0x00619d28-0x00619dc4.ExchangeDialogVtableData](by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md) | emits | `00004R` | `00004R` |  | no | `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` | `by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md` |  |
| [UID:0003NF][0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData](by-memory/0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md) | emits | `00004S` | `00004S` |  | no | `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` | `by-memory/0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md` |  |
| [UID:0003NK][0x0061a1bc-0x0061a1c0.ExchangeAlertPaneRttiLocatorPointer](by-memory/0x0061a1bc-0x0061a1c0.ExchangeAlertPaneRttiLocatorPointer.md) | emits | `00004Q` | `00004Q` |  | no | `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` | `by-memory/0x0061a1bc-0x0061a1c0.ExchangeAlertPaneRttiLocatorPointer.md` |  |
| [UID:0003NG][0x0061a304-0x0061a344.ExchangeDialogResourceStrings](by-memory/0x0061a304-0x0061a344.ExchangeDialogResourceStrings.md) | emits | `00004R` | `00004R` |  | no | `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` | `by-memory/0x0061a304-0x0061a344.ExchangeDialogResourceStrings.md` |  |
| [UID:0003NH][0x0061a344-0x0061a374.AddItemDialogResourceStrings](by-memory/0x0061a344-0x0061a374.AddItemDialogResourceStrings.md) | emits | `000007` | `000007` |  | no | `auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp` | `by-memory/0x0061a344-0x0061a374.AddItemDialogResourceStrings.md` |  |
| [UID:0003NI][0x0061a374-0x0061a37c.AddItemWithCountDialogQuantityFormatString](by-memory/0x0061a374-0x0061a37c.AddItemWithCountDialogQuantityFormatString.md) | emits | `000008` | `000008` |  | no | `auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp` | `by-memory/0x0061a374-0x0061a37c.AddItemWithCountDialogQuantityFormatString.md` |  |
| [UID:0003NJ][0x0061a37c-0x0061a3ac.MixItemDialogResourceStrings](by-memory/0x0061a37c-0x0061a3ac.MixItemDialogResourceStrings.md) | emits | `00008J` | `00008J` |  | no | `auto-generated/NexusTK/ui/dialogs/ItemDialogs.cpp` | `by-memory/0x0061a37c-0x0061a3ac.MixItemDialogResourceStrings.md` |  |
| [UID:00025A][0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData](by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md) | not_reconstructable | `NONE` |  |  | no |  | `by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md` |  |
```

Exact `by-memory/-coverage-report.md` replacement block:

```markdown
    - [UID:00025A][0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData](by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md) 0x00619d28-0x0061a3c4 | vtable/string-data | ExchangeItemReadOnlyData : not_reconstructable : 90% : very-strong : Reviewed non-emitting mixed exchange/item/mix `.rdata` split index starting at the ExchangeDialog primary COL pointer 0x00619d28 and ending before the FieldMapPane primary COL pointer 0x0061a3c4; B002 post-migration split created exact by-memory children for ExchangeDialog vtables, ExchangeItemListPane vtables, the ExchangeAlertPane primary RTTI locator, ExchangeDialog/AddItem/AddItemWithCount/MixItem resource strings, and uses existing exact ExchangeAlertPane and ExchangeMoneyEditControlPane by-memory children plus exact item/mix by-type vtable pages. No aggregate owner or emitter is justified because the physical span is mixed across ExchangeDialog, ExchangeItemListPane, ItemDialogs, MyItemListPane, ExchangeAlertPane, ExchangeMoneyEditControlPane, and FunctionObjects.
        - [UID:0003NE][0x00619d28-0x00619dc4.ExchangeDialogVtableData](by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md) 0x00619d28-0x00619dc4 | vtable-data | ExchangeDialogVtableData : reconstructable : 86% : strong : Exact ExchangeDialog primary COL pointer and three vtable views routed to [UID:00004R][ExchangeDialog](by-class/ExchangeDialog.md); live IDA MCP and PE/raw checks prove constructor stores from `sub_4AC8A0` and successor `ExchangeItemListPane` COL at 0x00619dc4.
        - [UID:0003NF][0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData](by-memory/0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md) 0x00619dc4-0x00619e88 | vtable-data | ExchangeItemListPaneVtableData : reconstructable : 85% : strong : Exact ExchangeItemListPane COL pointer and three vtable views routed to [UID:00004S][ExchangeItemListPane](by-class/ExchangeItemListPane.md) after B002 raised the class to `85/86`; stores come from `sub_4AC8A0` and the raw constructor bytes at `0x004ae060`.
        - [UID:0003NK][0x0061a1bc-0x0061a1c0.ExchangeAlertPaneRttiLocatorPointer](by-memory/0x0061a1bc-0x0061a1c0.ExchangeAlertPaneRttiLocatorPointer.md) 0x0061a1bc-0x0061a1c0 | rtti-pointer | ExchangeAlertPaneRttiLocatorPointer : reconstructable : 85% : strong : Exact four-byte ExchangeAlertPane primary complete-object-locator pointer routed to [UID:00004Q][ExchangeAlertPane](by-class/ExchangeAlertPane.md); closes the split gap between AddMixingItemDialog vtables and the existing ExchangeAlertPane vtable-data child.
        - [UID:0002NF][0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData](by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md) 0x0061a1c0-0x0061a260 | vtable-data | ExchangeAlertPaneVtableData : reconstructable : 85% : strong : Assigned to ExchangeAlertPane; exact ExchangeAlertPane primary, secondary, and tertiary vtable data ending before ExchangeMoneyEditControlPane RTTI at 0x0061a260.
        - [UID:0003BK][0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData](by-memory/0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData.md) 0x0061a260-0x0061a304 | vtable-data | ExchangeMoneyEditControlPaneVtableData : reconstructable : 86% : strong : Exact ExchangeMoneyEditControlPane RTTI pointer and three vtable views routed to [UID:00004T][ExchangeMoneyEditControlPane](by-class/ExchangeMoneyEditControlPane.md), ending at the corrected resource-string boundary 0x0061a304.
        - [UID:0003NG][0x0061a304-0x0061a344.ExchangeDialogResourceStrings](by-memory/0x0061a304-0x0061a344.ExchangeDialogResourceStrings.md) 0x0061a304-0x0061a344 | string-data | ExchangeDialogResourceStrings : reconstructable : 86% : strong : Exact `DLGEXC1.PAL`, `DLGEXC1.EPF`, and `%s(%s)` UTF-16 resource/format strings routed to [UID:00004R][ExchangeDialog](by-class/ExchangeDialog.md); all proven xrefs are in `sub_4AC8A0`.
        - [UID:0003NH][0x0061a344-0x0061a374.AddItemDialogResourceStrings](by-memory/0x0061a344-0x0061a374.AddItemDialogResourceStrings.md) 0x0061a344-0x0061a374 | string-data | AddItemDialogResourceStrings : reconstructable : 85% : strong : Exact `DLGEXC2.EPF` and `DLGEXC2.EPD` UTF-16 strings routed to [UID:000007][AddItemDialog](by-class/AddItemDialog.md); all proven xrefs are in `sub_4AE4C0`.
        - [UID:0003NI][0x0061a374-0x0061a37c.AddItemWithCountDialogQuantityFormatString](by-memory/0x0061a374-0x0061a37c.AddItemWithCountDialogQuantityFormatString.md) 0x0061a374-0x0061a37c | string-data | AddItemWithCountDialogQuantityFormatString : reconstructable : 85% : strong : Exact `%hu` UTF-16 quantity format literal routed to [UID:000008][AddItemWithCountDialog](by-class/AddItemWithCountDialog.md), with the sole xref at `0x004af3e3` in `sub_4AF380`.
        - [UID:0003NJ][0x0061a37c-0x0061a3ac.MixItemDialogResourceStrings](by-memory/0x0061a37c-0x0061a3ac.MixItemDialogResourceStrings.md) 0x0061a37c-0x0061a3ac | string-data | MixItemDialogResourceStrings : reconstructable : 86% : strong : Exact `MIXITEM.PAL` and `MIXITEM.EPF` UTF-16 resource strings routed to [UID:00008J][MixItemDialog](by-class/MixItemDialog.md), ending before the callback RTTI/table child at 0x0061a3ac.
```

## Scope And Prior Evidence

| Source | Finding |
| --- | --- |
| Prior B001 report | Correctly established the current target range `0x00619d28-0x0061a3c4` after boundary repairs for `000259`, `00025A`, `00025B`, and `0003IH`, but left `00025A` `RECONSTRUCTABLE:TRUE`, no-owner/non-emitting because front source-bearing subranges were still unsplit. |
| Current target page before B002 | `88/93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`; documented the mixed exchange/item/mix/callback/string contents and no-parent gate. |
| `by-structure.md` | For reviewed mixed-owner convenience pages, use `RECONSTRUCTABLE:FALSE` when exact children carry real source ownership. `EMITTER_UIDS` is output routing, not ownership; do not route a mixed aggregate through multiple emitters unless the aggregate itself is pooled/shared source data. |
| Current owner docs | `ExchangeDialog` class/file clears gate (`00004R` -> `0000J9`), ItemDialogs classes/file clear gate (`000007`, `000008`, `00008J`, `000009` -> `0000KE`), `ExchangeAlertPane`/`ExchangeMoneyEditControlPane` clear gate (`00004Q`, `00004T` -> `0000J9`), and callback table `0003IH` routes to function-object class `000041`. |

## IDA MCP Evidence

Active IDA MCP context:

| Check | Result |
| --- | --- |
| `idb_list` | Active session `b001_0003gy` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`. |
| `server_health` | `status: ok`; IDB `NexusTK.exe.i64`; imagebase `0x400000`; auto-analysis and Hex-Rays ready. |
| `entity_query(kind=names, 0x00619d20-0x0061a3d0)` | 36 named anchors from `ExchangeDialog` table at `0x00619d2c` through successor `FieldMapPane` table at `0x0061a3c8`. |

Key xref results:

| Address/group | Xref result |
| --- | --- |
| `0x00619d2c`, `0x00619d8c`, `0x00619dbc` | Constructor stores from `sub_4AC8A0` at `0x004ac8f4`, `0x004ac8fa`, `0x004ac904`; routes to `ExchangeDialog`. |
| `0x00619dc8`, `0x00619e50`, `0x00619e80` | Stores from `sub_4AC8A0` plus raw constructor bytes `0x004ae083/0x004ae08b/0x004ae095`; routes to `ExchangeItemListPane`. |
| `0x00619e8c`, `0x00619eec`, `0x00619f1c` | Stores from `sub_4AE4C0`, `sub_4AE900`, `sub_4B0910`, `sub_4B0970`; existing `AddItemDialogVtables` route. |
| `0x00619f28`, `0x00619fb0`, `0x00619fe0` | Stores from `sub_4AEB30`; existing `MyItemListPaneVtables` route. |
| `0x00619fec`, `0x0061a04c`, `0x0061a07c` | Stores from `sub_4AF040`; existing `AddItemWithCountDialogVtables` route. |
| `0x0061a088`, `0x0061a0e8`, `0x0061a118` | Stores from `sub_4AF570`; existing `MixItemDialogVtables` route. |
| `0x0061a124`, `0x0061a184`, `0x0061a1b4` | Stores from `sub_4AF8B0`/`sub_4B0000`; existing `AddMixingItemDialogVtables` route. |
| `0x0061a1bc` | RTTI target `0x006475d0`; exact child `0003NK` routes it to `ExchangeAlertPane`. |
| `0x0061a1c0`, `0x0061a228`, `0x0061a258` | Stores from `sub_4B0490`; existing exact child `0002NF`. |
| `0x0061a264`, `0x0061a2cc`, `0x0061a2fc` | Stores from `sub_4AC8A0` and `sub_4B0A60`; existing exact child `0003BK`. |
| `0x0061a304`, `0x0061a31c`, `0x0061a334` | `DLGEXC1.PAL`, `DLGEXC1.EPF`, `%s(%s)` xrefs from `sub_4AC8A0`; child `0003NG`. |
| `0x0061a344`, `0x0061a35c` | `DLGEXC2.EPF`, `DLGEXC2.EPD` xrefs from `sub_4AE4C0`; child `0003NH`. |
| `0x0061a374` | `%hu` xref from `sub_4AF380`; child `0003NI`. |
| `0x0061a37c`, `0x0061a394` | `MIXITEM.PAL`, `MIXITEM.EPF` xrefs from `sub_4AF570`; child `0003NJ`. |
| `0x0061a3b0` | Callback table xrefs from `sub_4AFCC0` and `sub_4B0120`; existing `0003IH` route. |
| `0x0061a3c8` | Successor `FieldMapPane` vtable store from `sub_4B0BB0`; proves target exclusive end after COL `0x0061a3c4`. |

## PE And Raw Evidence

Local PE scan over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` maps `0x00619d28-0x0061a3c4` to `.rdata` file offsets `0x218728-0x218dc4`.

Boundary dwords:

| VA | Dword | Meaning |
| --- | --- | --- |
| `0x00619d28` | `0x00647204` | `ExchangeDialog` COL target. |
| `0x00619dc4` | `0x0064728c` | `ExchangeItemListPane` COL target. |
| `0x00619e88` | `0x00647318` | `AddItemDialog` successor boundary. |
| `0x00619f24` | `0x00647354` | `MyItemListPane` successor boundary. |
| `0x00619fe8` | `0x006473e0` | `AddItemWithCountDialog` successor boundary. |
| `0x0061a084` | `0x00647468` | `MixItemDialog` successor boundary. |
| `0x0061a120` | `0x00647544` | `AddMixingItemDialog` successor boundary. |
| `0x0061a1bc` | `0x006475d0` | `ExchangeAlertPane` primary COL pointer. |
| `0x0061a260` | `0x006476ac` | `ExchangeMoneyEditControlPane` COL target. |
| `0x0061a304` | UTF-16 `D` | `DLGEXC1.PAL` string head. |
| `0x0061a3ac` | `0x00647738` | Callback RTTI/COL pointer. |
| `0x0061a3c4` | `0x00647788` | Successor `FieldMapPane` COL pointer. |

Decoded UTF-16 string heads:

| Address | Literal | Owner route |
| --- | --- | --- |
| `0x0061a304` | `DLGEXC1.PAL` | `00004R` |
| `0x0061a31c` | `DLGEXC1.EPF` | `00004R` |
| `0x0061a334` | `%s(%s)` | `00004R` |
| `0x0061a344` | `DLGEXC2.EPF` | `000007` |
| `0x0061a35c` | `DLGEXC2.EPD` | `000007` |
| `0x0061a374` | `%hu` | `000008` |
| `0x0061a37c` | `MIXITEM.PAL` | `00008J` |
| `0x0061a394` | `MIXITEM.EPF` | `00008J` |

## Split And Routing Inventory

| Range | Documentation | Route decision |
| --- | --- | --- |
| `0x00619d28-0x00619dc4` | New by-memory `0003NE` | Emits through `ExchangeDialog` class `00004R`. |
| `0x00619dc4-0x00619e88` | New by-memory `0003NF` | Emits through `ExchangeItemListPane` class `00004S`; B002 repaired parent to `85/86`. |
| `0x00619e88-0x00619f24` | Existing by-type `0003ID` | Emits through `AddItemDialog` `000007`; no duplicate by-memory page created. |
| `0x00619f24-0x00619fe8` | Existing by-type `0001Y8` | Emits through `MyItemListPane` `00008W`; no duplicate by-memory page created. |
| `0x00619fe8-0x0061a084` | Existing by-type `0003IE` | Emits through `AddItemWithCountDialog` `000008`; no duplicate by-memory page created. |
| `0x0061a084-0x0061a120` | Existing by-type `0003IG` | Emits through `MixItemDialog` `00008J`; no duplicate by-memory page created. |
| `0x0061a120-0x0061a1bc` | Existing by-type `0003IF` | Emits through `AddMixingItemDialog` `000009`; no duplicate by-memory page created. |
| `0x0061a1bc-0x0061a1c0` | New by-memory `0003NK` | Emits through `ExchangeAlertPane` `00004Q`. |
| `0x0061a1c0-0x0061a260` | Existing by-memory `0002NF` | Emits through `ExchangeAlertPane` `00004Q`. |
| `0x0061a260-0x0061a304` | Existing by-memory `0003BK` | Emits through `ExchangeMoneyEditControlPane` `00004T`. |
| `0x0061a304-0x0061a344` | New by-memory `0003NG` | Emits through `ExchangeDialog` `00004R`. |
| `0x0061a344-0x0061a374` | New by-memory `0003NH` | Emits through `AddItemDialog` `000007`. |
| `0x0061a374-0x0061a37c` | New by-memory `0003NI` | Emits through `AddItemWithCountDialog` `000008`. |
| `0x0061a37c-0x0061a3ac` | New by-memory `0003NJ` | Emits through `MixItemDialog` `00008J`. |
| `0x0061a3ac-0x0061a3c4` | Existing by-type `0003IH` | Emits through function-object class `000041`; no duplicate by-memory page created. |

## Rejected Alternatives

| Alternative | Why rejected |
| --- | --- |
| `CANONICAL_OWNER:0000J9` or `EMITTER_UIDS:0000J9` on aggregate | `ExchangeDialog` owns the front vtables, ExchangeItemListPane, alert/money panes, and `DLGEXC1` strings, but not AddItemDialog, MyItemListPane, AddItemWithCountDialog, MixItemDialog, AddMixingItemDialog, or callback-template data. |
| `CANONICAL_OWNER:0000KE` or `EMITTER_UIDS:0000KE` on aggregate | `ItemDialogs` owns the item/mix dialog content, but not `ExchangeDialog`, `ExchangeItemListPane`, `ExchangeAlertPane`, or `ExchangeMoneyEditControlPane` data. |
| Multiple aggregate emitters | This is not one pooled/shared literal group. It is a physical neighborhood of unrelated source-owned children. Multiple aggregate emitters would duplicate all child data into every listed emitter. |
| Keep aggregate `RECONSTRUCTABLE:TRUE` | `by-structure.md` says reviewed mixed-owner convenience pages should become `FALSE` when exact children carry the real source ownership. |
| Create duplicate by-memory mirrors for existing by-type vtable pages | `0003ID`, `0001Y8`, `0003IE`, `0003IG`, `0003IF`, and `0003IH` already have exact ranges and owner/emitter routing. Duplicating them as emitting by-memory pages would create conflicting source-output routes without adding ownership evidence. |
| Leave `0x0061a1bc-0x0061a1c0` hidden in aggregate | Rejected after final inventory check. B002 created `0003NK` so the `ExchangeAlertPane` primary COL pointer has an exact owner/emitter child. |

## Commands And Results

IDA MCP was used through the project-stable endpoint `http://127.0.0.1:13337/mcp`. No IDA write operations were used.

| Command/tool | Result summary |
| --- | --- |
| IDA MCP `idb_list` / `server_health` | Active `NexusTK.exe.i64` session ready; imagebase `0x400000`. |
| IDA MCP `entity_query` names over `0x00619d20-0x0061a3d0` | Reconfirmed vtable/RTTI sequence from `ExchangeDialog` through successor `FieldMapPane`. |
| IDA MCP `xrefs_to` for all table/string heads | Proved child source-use contexts and owner routes listed above. |
| IDA MCP `lookup_funcs` / decompilation snippets | Reconfirmed relevant constructors/helpers: `sub_4AC8A0`, raw `0x004ae060` constructor bytes, `sub_4AE4C0`, `sub_4AF380`, `sub_4AF570`, `sub_4AFCC0`, `sub_4B0120`, `sub_4B0490`, `sub_4B0A60`, and `sub_4B0BB0`. |
| IDA MCP `get_bytes` and local PE decode | Reconfirmed dword boundaries, string heads, and `.rdata` file offsets. |
| `python tools\leaser\leaser.py B002 lease ...` | Leased existing target/class pages before editing; created new pages only after parent lease; leased new pages before validator metadata writes. |
| Failed validator path attempt | `python tools\validator\validator.py ...` failed because that path does not exist; no files were validated or changed by that failed command. |
| `python tools\validator.py --mode file --file <new child> --apply` | Assigned UIDs `0003NE` through `0003NJ`, then `0003NK`. |
| `python tools\validator.py --mode file --file ... --apply` on modified target/class/children | Passed; updated validator-managed metadata/autogen. Generated memory coverage now reports `00025A` as `not_reconstructable` and child pages as `emits`. |

Dry-run validator mode was not used. Memory-range validator mode was not used.

## Validation And Lease Status

Validated with normal `--mode file --apply`:

```text
by-class\ExchangeItemListPane.md
by-memory\0x00619d28-0x00619dc4.ExchangeDialogVtableData.md
by-memory\0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md
by-memory\0x0061a1bc-0x0061a1c0.ExchangeAlertPaneRttiLocatorPointer.md
by-memory\0x0061a304-0x0061a344.ExchangeDialogResourceStrings.md
by-memory\0x0061a344-0x0061a374.AddItemDialogResourceStrings.md
by-memory\0x0061a374-0x0061a37c.AddItemWithCountDialogQuantityFormatString.md
by-memory\0x0061a37c-0x0061a3ac.MixItemDialogResourceStrings.md
by-memory\0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md
```

Validator-managed state updated during the normal flow:

```text
auto-generated/-ag-memory-coverage.md
tools/validator.ini
project-level/-auto-completion-stats.md
```

No unresolved validator errors remain from this work. Validator reports many `autogen_cpp_noop` messages because these pages have no reconstruction C++ blocks; that is expected.

## Changed Files

Direct documentation edits:

```text
by-class/ExchangeItemListPane.md
by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md
by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md
by-memory/0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md
by-memory/0x0061a1bc-0x0061a1c0.ExchangeAlertPaneRttiLocatorPointer.md
by-memory/0x0061a304-0x0061a344.ExchangeDialogResourceStrings.md
by-memory/0x0061a344-0x0061a374.AddItemDialogResourceStrings.md
by-memory/0x0061a374-0x0061a37c.AddItemWithCountDialogQuantityFormatString.md
by-memory/0x0061a37c-0x0061a3ac.MixItemDialogResourceStrings.md
tools/leaser/Agents/Agent-B002/research/00025A-ExchangeItemReadOnlyData-post-migration.md
```

Validator-managed/generated state:

```text
auto-generated/-ag-memory-coverage.md
tools/validator.ini
project-level/-auto-completion-stats.md
```

The broader worktree had many pre-existing dirty/untracked files unrelated to this assignment; B002 did not revert or modify them.

## Blockers

No external blocker remains. The only intentional non-ownership result is the aggregate itself: `00025A` must stay `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and `RECONSTRUCTABLE:FALSE` because it is a mixed physical index whose children now carry the source routes.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00025A-ExchangeItemReadOnlyData-post-migration.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00025A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
