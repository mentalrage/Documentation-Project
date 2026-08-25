*** UID:0000RA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "EPFTileContext.h"
#include "ImageLib.h"
#include "Surface.h"

class ItemObjImageLib;

ItemObjImageLib *g_pItemObjImageLib = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pItemObjImageLib

## UID0000LO MyItemListPane Consumer Link - 2026-08-14

[UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md)
uses the singleton receiver for `GetItemGlyphBounds`, `DrawItemImageScaled`, and
`DrawItemImage`. The accepted source preserves those as ItemObjImageLib member
calls. This adds no target ownership: the singleton's declaration, definition,
storage page, score, and emitter remain unchanged.

## UID00041S Position-0 Compile-Visibility Integration - 2026-08-11

- This position-0 source emitter now supplies the exact accepted include preamble `EPFTileContext.h`, `ImageLib.h`, and `Surface.h` before its existing `ItemObjImageLib` forward declaration and sole singleton definition. The includes make the later UID00041S body compile-visible without transferring ownership of any shared type or callback into this global page.
- `EPFTileContext.h` provides the decoded sprite context used by the target local and callback; `ImageLib.h` provides the image-library/global declarations used by the ItemObjImageLib source family; `Surface.h` provides the sole complete [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) declaration of `SurfaceSpriteBlitOptions`, `SurfaceSpriteBlitProc`, and `g_pfnBlitSprite` plus its GrafPort/EPFTileContext/RectBounds/DLPalette forward routes.
- The existing one-definition contract is unchanged: this page emits exactly one `ItemObjImageLib *g_pItemObjImageLib = 0;`, UID0001UU emits the matching header `extern`, and physical UID0001OT remains false/non-emitting. No callback variable, support struct, method body, or duplicate global is introduced here.
- Position `0`, metadata `92/94`, owner/emitter UID0000KH, the 65-reference/five-write lifecycle proof, direct Singleton lowering, and canonical-name history all remain intact.

## UID0001OT Sole Definition And Direct Singleton Source Route - 2026-07-20

- This page emits the sole externally linked module definition in `NexusTK/render/ItemObjImageLib.cpp` at position `0`. The local class forward declaration makes the definition compile-visible regardless of generated ordering; [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md) carries the one matching header-facing `extern` declaration after the complete class.
- [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md) is the exact four-byte zero-initialized physical slot and is now false/non-emitting. No by-memory declaration, duplicate definition, function-local static, internal-linkage copy, or additional template static definition is permitted.
- Live MCP session `9b0396a3` returned exactly 65 refs with `more:false`: five lifetime writes and 60 reads. Reader counts by complete source group are `3,3,3,1,2,2,2,4,4,1,3,4,4,4,1,1,4,4,2,2,1,1,1,1,1,1`; they cover fitting-room, ranking/reward, clan, employee, exchange, list, inventory, Application shutdown, MapPane, item-menu, object-image, ItemObjectPane, FlyingObjectPane, SelfLook, and UserLook paths. Exact addresses are retained on UID0001OT.
- The five writes are constructor publication/null-adjustment stores at `0x004dec7b/0x004dec82`, ordinary-destructor clear `0x004dee3b`, constructor-EH base-destructor clear `0x004e5ba0`, and scalar-wrapper clear `0x004e659e`.
- RTTI directly proves `ItemObjImageLib : LObject, Singleton<ItemObjImageLib>` with Singleton PMD `{4,-1,0}`. The empty base overlaps `ProtectedArray<ItemInfo> m_itemInfos` at `+0x04`; direct base construction/destruction owns publication/clear.
- The constructor source therefore initializes `Singleton<ItemObjImageLib>()` and contains no explicit assignment. The empty ordinary destructor relies on implicit member, Singleton, and LObject destruction. UID00017Y, UID0002VC, UID0001XW, and UID0002ML are compiler/generated-binary support and emit no C++.
- `g_pItemObjImageLib` is the accepted project-canonical typed name. Historical `g_pItemObjectImageLib`, `g_pItemImageLib`, current raw `dword_67A758`, and `DAT_0067a758` all denote the same slot and are not alternate definitions. Exact source/PDB spelling remains the confidence cap.
- The binary could have expressed this storage through an internal template static-member spelling, but that lexical form is unrecovered. The one observed slot and current source contract reject a second explicit specialization/definition because it would violate one-definition behavior.

## Status

- Confidence: strong for address, owner, lifecycle/storage evidence, and project-canonical source-facing singleton name; medium-high for exact original symbol spelling.
- Kind: process-wide singleton pointer.
- Backing storage: [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md), current MCP disassembly label `dword_67A758`; this page keeps `g_pItemObjImageLib` as the source-facing documentation name.
- Canonical owner: [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md) in [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md).
- Observed aliases: `g_pItemObjectImageLib`, `g_pItemImageLib`, and raw `dword_67A758`.

## Meaning

`g_pItemObjImageLib` is the global pointer to the item sprite library. UI item rows, item menus, look panes, inventory/fitting panes, and item-preview dialogs read this pointer before calling the shared item draw routines.

Keep this global with `render/ItemObjImageLib.cpp`. Consumers should not adopt it just because they draw item icons.

## Write Evidence

IDA MCP on 2026-05-25 reports 65 xrefs to `0x0067a758` across 29 recognized functions. The write sites are:

| Address | Function | Meaning |
| --- | --- | --- |
| `0x004dec7b` | `ItemObjImageLib::ItemObjImageLib` | Stores the constructed `ItemObjImageLib*` singleton. |
| `0x004dec82` | `ItemObjImageLib::ItemObjImageLib` | Compiler null-adjustment side of direct Singleton-base publication, not a handwritten fallback branch. |
| `0x004dee3b` | [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md) | Implicit `Singleton<ItemObjImageLib>` base destruction after member cleanup. |
| `0x004e5ba0` | [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md) | Constructor-EH-only Singleton base-destructor instantiation. |
| `0x004e659e` | `ItemObjImageLib::ScalarDeletingDestructor` | Compiler scalar-wrapper copy of implicit Singleton-base destruction. |

The constructor at `0x004dec30` also chooses `ITEM.TBL` versus `ITEM.TBD`, installs the `ItemObjImageLib` and `ProtectedArray<ItemInfo>` vtables, and loads the item metadata rows.

Live IDA MCP decompilation confirms the constructor, ordinary destructor, constructor SEH cleanup helper, and scalar deleting destructor references to `g_pItemObjImageLib`; use that storage/xref evidence as the ownership basis.

2026-06-16 C001 live IDA refresh reconfirmed 65 direct refs to `0x0067a758`, including constructor publish/guard clear at `0x004dec7b`/`0x004dec82`, raw ordinary-destructor clear at `0x004dee3b`, constructor cleanup helper clear at `0x004e5ba0`, scalar deleting destructor clear at `0x004e659e`, startup/shutdown refs, and broad UI consumers. The IDA data label was safely renamed from `dword_67A758` to `g_pItemObjImageLib`, and related function labels `sub_4DEC30`, `sub_4DF500`, and `sub_4E6580` were renamed to the documented ItemObjImageLib names; the IDB was saved.

2026-06-19 B008 local PE/Capstone recheck reconfirmed 65 direct operand hits for `0x0067a758`. Representative draw consumers set up calls to `DrawItemImage`, `DrawItemImageIn43x43Slot`, `DrawItemImageUnscaled`, and `DrawItemImageScaled` after loading the singleton, which supports keeping this storage with the item image-library module rather than any UI consumer.

2026-06-23 B002 MCP session `261fb29b` revalidated the ordinary destructor clear at [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md). Current disassembly still prints `mov dword_67A758, 0` at `0x004dee3b`; `xrefs_to 0x0067a758` still reports 65 refs with lifecycle writes at `0x004dec7b`, `0x004dec82`, `0x004dee3b`, `0x004e5ba0`, and `0x004e659e`. No code/data/VA/RVA pointer route to the raw ordinary destructor start was found, so this global remains support evidence for `ItemObjImageLib` ownership rather than an owner of the destructor body.

2026-06-27 B013 current MCP session `b001_000241_20260627` revalidated the [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md) write site. Current evidence still reports 65 refs to `0x0067a758`; the `0x004e5ba0` writer is reached by the constructor SEH cleanup jump at `0x00600158`, has exact `mov dword_67A758, 0; retn` bytes, has no ordinary callers/callees, and has no data/VA/RVA pointer route. This page remains support state under [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md), not an owner of the generated cleanup helper.

## Consumer Evidence

Known readers include:

- [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md) draw path `0x004aec90`, which calls `ItemObjImageLib::DrawItemImage` or `DrawItemImageScaled` after `GetItemGlyphBounds`.
- item context menu row lists around `0x0051b3e0`, `0x0051c6c0`, and related server/client item menu draw paths.
- clan item list, fitting/inventory, look-pane, ranking-reward, item-preview, and exchange/mix UI paths documented in the item rendering and dialog clusters.

## Ownership Decision

`g_pItemObjImageLib` is source-owned by `ItemObjImageLib`, not by `MyItemListPane`, `ArgumentedMenuMenuItemList`, `ClientItemMenuItemList`, `Application`, or any caller that only consumes item icons.

When rewriting source, normalize noncanonical aliases back to this canonical global unless stronger original-name evidence appears.

The formal C++ block emits one local forward declaration followed by the sole module definition. Exact original spelling remains a confidence caveat only; the project-canonical name is already used by target/support docs and consumers, and lifecycle/storage evidence is strong enough for a source definition plus separate header declaration.

## Cross-References

- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md)
- [UID:00017N][0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster](by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md)
- [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md)
- [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md)
- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md)
- [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md)
- [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md)

## Changes

### 2026-07-20 B002 UID0001OT accepted source-quality callback

- Raised `88/89 -> 92/94`, set position `0`, added the local class forward declaration, and retained exactly one zero-initialized module definition.
- Incorporated the complete 65-ref/five-write/60-read inventory, direct Singleton RTTI/PMD/EBO lowering, source/header one-definition policy, compiler-artifact exclusions, canonical alias disposition, and physical UID0001OT false/non-emitting route.
- Historicalized the constructor fallback and free/static cleanup interpretations; direct base construction/destruction now owns the same binary effects.

### 2026-07-01 B007 accepted ItemObjImageLib empty-emitter implementation

- What changed: added the formal first-draft singleton declaration `ItemObjImageLib *g_pItemObjImageLib = 0;`.
- Summary and evidence: the docs and constructor C++ already use `g_pItemObjImageLib` as the canonical source-facing name; 65-ref lifecycle evidence, constructor publish, destructor/helper/scalar clears, and exact storage page [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md) support emitting the global here while keeping the exact storage page comment-only.

### 2026-05-30 completion/confidence evidence pass

- What existed before: the page had `0` completion/confidence header values while already carrying detailed IDA-backed address, owner, write-site, and consumer evidence.
- What changed: completion/confidence were raised to `88/88`, and the evidence notes now include lifecycle writes/clears and ownership caveats.
- Summary and evidence: existing by-memory notes independently record the IDA xrefs and write addresses. The score remains below complete because not all 65 reader xrefs are enumerated and the final original spelling remains slightly caveated by older aliases.
- 2026-06-05: Marked reconstructable under [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md). Evidence: live IDA MCP reports 65 xrefs to `0x0067a758`; decompilation confirms constructor `0x004dec30`, clear helper `0x004e5ba0`, and scalar deleting destructor `0x004e6580` write/clear `dword_67A758`.
- 2026-06-16 C001 type/layout support refresh: confidence `88 -> 89` after live IDA reconfirmed the 65-ref lifecycle/consumer map and the backing storage was safely renamed in IDA to `g_pItemObjImageLib`. Completion remains `88` because not all reader xrefs are individually enumerated and final original symbol spelling remains slightly caveated by older generated aliases.
- 2026-06-19 B008 source-quality sync: no score change; added local PE/Capstone reconfirmation of the 65 direct operand hits and representative draw-call consumer evidence.
- 2026-06-23 B002 ordinary destructor sync: no score change; current MCP session `261fb29b` reconfirmed the destructor clear at `0x004dee3b`, the 65-ref lifecycle set, and current IDA label `dword_67A758`, while preserving `g_pItemObjImageLib` as the source-facing name and rejecting global ownership of the raw destructor body.
- 2026-06-27 B013 singleton cleanup helper sync: no score change; current MCP session `b001_000241_20260627` reconfirmed the 65-ref lifecycle set and rewrote the `0x004e5ba0` write-site description as constructor SEH/unwind cleanup helper evidence, not source-authored global-owned helper code.
