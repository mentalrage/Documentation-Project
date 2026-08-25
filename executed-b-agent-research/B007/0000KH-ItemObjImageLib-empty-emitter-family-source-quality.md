** TARGET-REPORT-UID:0000KH **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0000KH ItemObjImageLib Empty-Emitter Family Source-Quality Report

## Executive Recommendation

Apply a scoped first implementation batch to [UID:0000KH][ItemObjImageLib](../../../../../by-file/ItemObjImageLib.md), not to generated files or coverage reports.

Recommended by-file metadata after implementation:

```markdown
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

The first safe implementation batch should:

1. Add a durable `2026-07-01 B007 generated-output audit` section to the by-file page.
2. Preserve the accepted route: file root [UID:0000KH], class [UID:00006W], generated path `auto-generated/NexusTK/render/ItemObjImageLib.cpp`.
3. Add first-draft formal source declarations for source-bearing declaration targets:
   - [UID:0000RA] `g_pItemObjImageLib`: `ItemObjImageLib *g_pItemObjImageLib = 0;`
   - [UID:0001UT] `ItemInfo`: a 0x14-byte row struct using best current inferred field names.
   - [UID:0001UU] `ItemObjImageLibLayout`: a first-draft `ItemObjImageLib` class declaration with `ProtectedArray<ItemInfo> m_itemInfos` and method prototypes only.
4. Add formal comment-only no-code markers only for genuine duplicate/generated/ABI markers:
   - [UID:00006W] class page: duplicate class declaration route; formal declaration emitted through the layout page in this batch, while method bodies remain exact children.
   - [UID:0001XW] vtable type page: source-declared/generated-binary.
   - [UID:0001OT] singleton storage page: exact `.data` backing slot duplicate of the global declaration.
   - [UID:00017O] raw ordinary destructor page: ABI cleanup/vptr/free/base sequence, not safe handwritten source.
   - [UID:00017Y] constructor SEH singleton cleanup helper page: compiler/unwind glue.
   - [UID:0002ML] exact vtable-data page: compiler/linker output from the class declaration.
5. Leave the four draw-method markers and [UID:0000UQ] `GetItemGlyphBounds` formal C++ blank for now, with current MCP-backed proof that helper signatures, render callback types/order, `RectBounds` mutation semantics, and `drawOwner` static type are still below source-quality.

This batch removes the safest empty markers without inventing draw bodies. It does not require editing target/support docs outside the by-file and the nine directly listed support pages.

## Evidence Sources Checked

Local docs:

- [UID:0000KH][by-file/ItemObjImageLib.md](../../../../../by-file/ItemObjImageLib.md)
- [UID:00006W][by-class/ItemObjImageLib.md](../../../../../by-class/ItemObjImageLib.md)
- [UID:0002SD][0x004dec30-0x004dee1b.ItemObjImageLibConstructor](../../../../../by-memory/0x004dec30-0x004dee1b.ItemObjImageLibConstructor.md)
- [UID:0002VC][0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor](../../../../../by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md)
- [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](../../../../../by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md)
- [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper](../../../../../by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md)
- [UID:00041R], [UID:00041S], [UID:00041T], [UID:00041U] exact draw-method pages
- [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](../../../../../by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md)
- [UID:0001UU], [UID:0001XW], [UID:0001UT], [UID:0000RA], [UID:0001OT], and [UID:0002ML] support pages
- `auto-generated/-ag-research-tracker.md` row for [UID:0000KH]
- `auto-generated/NexusTK/render/ItemObjImageLib.cpp`
- Executed reports used as leads: B005 `00017N`, B005 `0002SD`, B008 `00006W`, B002 `00017O`, B013 `00017Y`, B014 `0002VC`, B002 `00027I`, and B003 `0003LZ`.

No target/support by-* docs, generated files, coverage reports, validator state, queue files, archives, supervisor ledgers, or IDA DB files were edited in this report-only pass.

## Current Generated-Output Audit

Generated header currently reports:

```text
validator-command-id: 000000003240
validator-refreshed-at: 2026-07-01T04:25:52-04:00
Source by-file UID: 0000KH
Source by-file doc: by-file/ItemObjImageLib.md
```

Tracker row:

```text
[UID:0000KH] ItemObjImageLib | 16 total emitters | 2 filled | 14 empty | 12.5% | auto-generated/NexusTK/render/ItemObjImageLib.cpp | by-file report coverage 0
```

Populated outputs:

| UID | Disposition |
| --- | --- |
| [UID:0002VC] | Formal no-code marker for compiler-generated scalar deleting destructor glue. Keep as-is. |
| [UID:0002SD] | First-draft constructor C++. Keep as-is. |

Current empty markers and disposition:

| UID | Current empty marker disposition |
| --- | --- |
| [UID:00006W] | Safe comment-only no-code marker. Class declaration is documented in prose; class-level formal C++ remains below the class-code gate and should not duplicate child bodies. |
| [UID:00041R] | Keep blank. Draw body is source-authored but still blocked by helper/callback/type proof. |
| [UID:00041S] | Keep blank. Same blocker plus legacy remap and overlay path. |
| [UID:00041T] | Keep blank. Same blocker without overlay. |
| [UID:00041U] | Keep blank. Same blocker plus crop/scale and legacy remap path. |
| [UID:0001UU] | First-draft class/layout declaration. Provisional names are acceptable here because the layout, constructor, destructor, draw pages, and `ProtectedArray<ItemInfo>` support agree on the source shape; no stronger no-code blocker remains. |
| [UID:0001XW] | Safe comment-only no-code marker. Vtable type is source-declared/generated-binary. |
| [UID:0000RA] | First-draft global declaration. The project-canonical source-facing name is already `g_pItemObjImageLib`, constructor C++ already uses it, and lifecycle/storage evidence is strong enough for `ItemObjImageLib *g_pItemObjImageLib = 0;`. |
| [UID:0001OT] | Safe comment-only no-code marker. Exact `.data` storage should not emit a second declaration. |
| [UID:00017O] | Safe comment-only no-code marker. Raw unmodeled ordinary destructor body should not be hand-written as vptr/free/base cleanup source. |
| [UID:0000UQ] | Keep blank. Free helper is source-authored, but final helper signature/archive-global names remain below source-quality. |
| [UID:00017Y] | Safe comment-only no-code marker. Constructor SEH cleanup helper is compiler/unwind glue. |
| [UID:0002ML] | Safe comment-only no-code marker. Exact vtable-data bytes are compiler/linker output from the class declaration. |
| [UID:0001UT] | First-draft `struct ItemInfo` declaration. Constructor/read-order/draw-consumer evidence proves size and offsets; best inferred field names are sufficient under current project rules. |

Why broad by-file/class C++ remains blank: [UID:0000KH] is the source root and [UID:00006W] is the class route, but exact source bodies already belong to children. Constructor C++ is emitted by [UID:0002SD]; scalar deleting destructor glue is already a no-code marker at [UID:0002VC]; draw/glyph bodies need their own helper/type source-quality pass. Adding a broad class/file body now would duplicate child output and overclaim unresolved helper declarations.

## Current MCP Evidence

MCP was available and responsive.

- Endpoint: `http://127.0.0.1:13337/mcp`
- JSON-RPC initialize request `1`: server `ida-pro-mcp`, protocol `2025-06-18`
- `idb_list` request `3`: active session `supervisor_resume_20260629`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `14860`
- `server_health` request `4`: status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready

`lookup_funcs` request `5` confirmed:

| Address | Result |
| --- | --- |
| `0x004dec30` | `sub_4DEC30`, size `0x1eb` |
| `0x004dee20` | not a function |
| `0x004dee50` | `sub_4DEE50`, size `0x16a` |
| `0x004defc0` | `sub_4DEFC0`, size `0x214` |
| `0x004df1e0` | `sub_4DF1E0`, size `0xd7` |
| `0x004df2c0` | `sub_4DF2C0`, size `0x195` |
| `0x004df455` | not a function |
| `0x004df460` | `sub_4DF460`, size `0x99` |
| `0x004df4f9` | not a function |
| `0x004df500` | `sub_4DF500`, size `0x168` |
| `0x004e6580` | `sub_4E6580`, size `0x5c` |
| `0x004e5ba0` | `sub_4E5BA0`, size `0xb` |
| `0x0061b73c` | not a function, vtable data |
| `0x0067a758` | not a function, singleton storage |

`analyze_component` request `6` over `0x004dee50`, `0x004defc0`, `0x004df1e0`, `0x004df2c0`, and `0x004df460` reported:

- `sub_4DEE50`: `__thiscall`, six stack arguments after `this`, size `362`, callees include `sub_457A60`, `sub_4D02F0`, `sub_543D20`, `sub_543E40`, `sub_462F20`, `unk_69B3E8`, and security-cookie helper.
- `sub_4DEFC0`: `__thiscall`, six stack arguments after `this`, size `532`, same overlay-capable callee set as `sub_4DEE50`.
- `sub_4DF1E0`: `__thiscall`, four stack arguments after `this`, size `215`, non-overlay callee set.
- `sub_4DF2C0`: `__thiscall`, four stack arguments after `this`, size `405`, non-overlay callee set.
- `sub_4DF460`: `__stdcall`, `int __stdcall(__int16, _DWORD *)`, size `153`, callees `sub_4D0530` and `sub_4B7E10`.
- Shared data includes `ITEM.EPF` `off_61C288`, `ITEM.EPD` `off_61C29C`, `g_useEpfAssets`/`byte_66DA97`, item remap constants `word_66DAD4/66DAD8/66DADC`, EPF library state `dword_67A744`, palette library state `dword_67A7E0`, and surface callback `unk_69B3E8`.

This current MCP evidence supports the existing ownership and boundary decisions. It does not close the draw/glyph source-body blockers.

## Source-Quality Decisions

### Accepted Owner / Emitter Route

Ranked route:

1. [UID:0000KH] `NexusTK/render/ItemObjImageLib.cpp` file root: accepted for generated file and by-file audit.
2. [UID:00006W] `ItemObjImageLib` class: accepted for class-owned draw methods, layout, and vtable declaration effects.
3. [UID:0000KH] file-level free-helper route: accepted for [UID:0000UQ] `GetItemGlyphBounds`, [UID:0000RA] singleton global, [UID:00017Y] cleanup glue, and [UID:0002ML] generated vtable data.

Rejected routes:

- UI pane callers: consumer-only item icon users.
- `ImageLib`, `EPFImageResources`, `ResourceLayoutTable`, `PaletteLib`, `AlphaMaskSurface`, `EPFTileContext`, and `SurfaceRenderCallbackTable`: dependencies only.
- No-owner/non-emitting for the draw/glyph functions: rejected because they have live source-authored bodies and direct ItemObjImageLib resource policy.
- Hand-written vtable, scalar deleting destructor, SEH cleanup helper, or raw ABI destructor code: rejected because those bytes are generated-binary or compiler cleanup representations of source declarations/lifecycle.

### Source-Bearing Declaration Recheck

Supervisor rejection correctly identified the original report as too conservative for declaration-bearing targets. Current project rules require best inferred human source names when original symbols are unavailable. "Exact original spelling is not 100% proven" is not enough to leave a declaration target as comment-only when current docs and MCP evidence already prove source shape.

[UID:0000RA] `g_pItemObjImageLib` should emit a normal first-draft declaration:

```cpp
ItemObjImageLib *g_pItemObjImageLib = 0;
```

Evidence: the by-file, by-global, and by-memory storage pages already use `g_pItemObjImageLib` as the project-canonical source-facing name; [UID:0002SD] constructor C++ already assigns `g_pItemObjImageLib = this;`; lifecycle writes/clears are documented at `0x004dec7b`, `0x004dec82`, `0x004dee3b`, `0x004e5ba0`, and `0x004e659e`; and current MCP request `5` confirms `0x0067a758` is data storage rather than a function. The exact storage page [UID:0001OT] should remain comment-only because it is the backing `.data` slot and would duplicate the global declaration.

[UID:0001UT] `ItemInfo` should emit a first-draft row declaration. The constructor, table-loader, layout page, and draw pages agree on a `0x14` byte row with fields at `+0x00`, `+0x04`, `+0x08`, `+0x0c`, and `+0x10`. Best current source-facing names are `itemTableId`, `paletteSlot`, `alpha`, `renderFlagsOrMode`, and `allowPaletteFilter`. `+0x00` and `+0x0c` remain inferred names, but their uncertainty is a confidence caveat, not a no-code blocker.

[UID:0001UU] `ItemObjImageLibLayout` should emit a first-draft class/layout declaration. It is the cleanest current formal place for the class member layout because [UID:00006W] remains a broader class page below the class-body gate and exact method bodies remain on child pages. The layout declaration should contain prototypes only, use `void *drawOwner` for the unused first draw parameter to avoid overclaiming a pane base type, and declare the embedded `ProtectedArray<ItemInfo> m_itemInfos`.

[UID:00006W] remains comment-only for this batch for a stronger target-specific reason than "names are provisional": the class declaration is emitted through [UID:0001UU] to avoid duplicate class declarations, constructor C++ is already emitted through [UID:0002SD], scalar deleting destructor glue is already emitted through [UID:0002VC], and the draw/glyph bodies remain blocked. The class page should carry the route/audit prose but not duplicate formal source.

### Draw/Glyph Formal C++ Is Not Ready

The four draw methods and `GetItemGlyphBounds` remain reconstructable and correctly routed, but formal code should stay blank because current evidence still leaves these blockers:

- `sub_457A60`, `sub_4D02F0`, `sub_543D20`, `sub_543E40`, `sub_4D0530`, `sub_4B7E10`, and `unk_69B3E8` need source-quality declarations and owner docs before final draw source can call them.
- Surface render callback table type and callback argument order are still not proven enough for copy/paste source.
- `RectBounds` mutation and draw-local temporary structure semantics are still decompiler-shaped.
- The first stack argument after `this` is consistently passed but optimized unused; `Pane *drawOwner` remains the best prose type and `void *drawOwner` remains the safer formal-code fallback.
- Overlay integration through `DrawEncodedAlphaFrame` is source-shaped but still depends on exact alpha-mask/surface helper signatures.
- `GetItemGlyphBounds` has a good source-facing name and behavior, but exact helper signature, archive-selector/global names, and final item-image helper placement remain below source-quality.

This is a target-specific no-code proof, not a generic score shortcut.

## Exact Formal Insertion Text

Use the following text exactly between each target's formal `RECONSTRUCTION_CPP CODE:BEGIN` and `END` markers during implementation callback.

[UID:00006W] `by-class/ItemObjImageLib.md`:

```cpp
// ItemObjImageLib class route is documented here; the first-draft layout declaration is emitted through ItemObjImageLibLayout, and exact method bodies remain on child pages.
```

[UID:0001UU] `by-type/by-struct/ItemObjImageLibLayout.md`:

```cpp
class ItemObjImageLib : public LObject
{
public:
    ItemObjImageLib();
    virtual ~ItemObjImageLib();

    int DrawItemImage(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength);
    int DrawItemImageIn43x43Slot(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength);
    int DrawItemImageUnscaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags);
    int DrawItemImageScaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags);

private:
    ProtectedArray<ItemInfo> m_itemInfos;
};
```

[UID:0001XW] `by-type/by-vtable/ItemObjImageLibVtable.md`:

```cpp
// ItemObjImageLib vtable is source-declared/generated-binary data emitted from the class declaration; do not hand-write vtable dwords.
```

[UID:0000RA] `by-global/g_pItemObjImageLib.md`:

```cpp
ItemObjImageLib *g_pItemObjImageLib = 0;
```

[UID:0001OT] `by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md`:

```cpp
// Backing storage for g_pItemObjImageLib is covered by the global singleton page; this exact .data slot emits no separate source declaration.
```

[UID:00017O] `by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md`:

```cpp
// ItemObjImageLib ordinary destructor cleanup is source-owned, but this raw unmodeled body remains a no-code ABI cleanup proof; do not hand-write vptr/free/base-cleanup instructions.
```

[UID:00017Y] `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md`:

```cpp
// Constructor SEH cleanup helper for g_pItemObjImageLib is compiler/unwind glue; source ownership is the ItemObjImageLib constructor singleton lifecycle.
```

[UID:0002ML] `by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md`:

```cpp
// ItemObjImageLib RTTI/vtable bytes are source-declared/generated-binary output from the class virtual method set; no handwritten table source is emitted.
```

[UID:0001UT] `by-type/by-struct/ItemInfo.md`:

```cpp
struct ItemInfo
{
    int itemTableId;
    int paletteSlot;
    float alpha;
    int renderFlagsOrMode;
    bool allowPaletteFilter;
    unsigned char reserved[3];
};
```

No formal C++ insertion is recommended for [UID:00041R], [UID:00041S], [UID:00041T], [UID:00041U], or [UID:0000UQ] in this batch.

## Recommended By-File Audit Text

Add a durable by-file section equivalent to:

```markdown
## 2026-07-01 B007 Generated-Output Audit

Generated `auto-generated/NexusTK/render/ItemObjImageLib.cpp` last observed with `validator-command-id: 000000003240` and `validator-refreshed-at: 2026-07-01T04:25:52-04:00`. Tracker row [UID:0000KH] reports 16 total emitters, 2 filled, 14 empty, 12.5%, and no by-file report coverage at the time of the B007 report.

The two populated outputs are [UID:0002VC] compiler-generated scalar deleting destructor no-code marker and [UID:0002SD] constructor C++. The 14 empty markers are [UID:00006W], [UID:00041R], [UID:00041S], [UID:00041T], [UID:00041U], [UID:0001UU], [UID:0001XW], [UID:0000RA], [UID:0001OT], [UID:00017O], [UID:0000UQ], [UID:00017Y], [UID:0002ML], and [UID:0001UT].

Safe first implementation batch: add first-draft source declarations for [UID:0000RA], [UID:0001UT], and [UID:0001UU]. `g_pItemObjImageLib` is the project-canonical singleton name and should emit `ItemObjImageLib *g_pItemObjImageLib = 0;`; `ItemInfo` should emit the current 0x14-byte row struct with best inferred field names; and `ItemObjImageLibLayout` should emit a first-draft class/layout declaration with `ProtectedArray<ItemInfo> m_itemInfos` and draw method prototypes using `void *drawOwner` as the conservative formal type.

Add formal comment-only no-code markers for [UID:00006W], [UID:0001XW], [UID:0001OT], [UID:00017O], [UID:00017Y], and [UID:0002ML]. These are duplicate class route, generated-binary vtable/type data, exact backing storage duplicate, raw-ABI cleanup, constructor unwind, or compiler/linker artifacts whose source obligations are already represented by the declarations and exact child pages.

Keep [UID:00041R], [UID:00041S], [UID:00041T], [UID:00041U], and [UID:0000UQ] formal blocks blank. Current B007 MCP session `supervisor_resume_20260629` confirmed their boundaries and roles, but helper signatures, render callback type/order, RectBounds mutation semantics, draw-local temporary structures, `drawOwner` static type, and archive/helper names remain below source-quality for formal C++.
```

## Validation Commands For Implementation Callback

Run only after the supervisor sends an implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [0000KH-ItemObjImageLib-empty-emitter-family-source-quality-removed.md](0000KH-ItemObjImageLib-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After validation, inspect `auto-generated/NexusTK/render/ItemObjImageLib.cpp`. Expected result: generated header refreshed at or after the last validator command metadata, and empty markers for [UID:00006W], [UID:0001UU], [UID:0001XW], [UID:0000RA], [UID:0001OT], [UID:00017O], [UID:00017Y], [UID:0002ML], and [UID:0001UT] no longer appear. Empty markers for [UID:00041R], [UID:00041S], [UID:00041T], [UID:00041U], and [UID:0000UQ] are expected to remain.

## Claim And Incorporation Ledger

| Claim / report fact | Destination | Action | Verification state | Evidence / implementation note |
| --- | --- | --- | --- | --- |
| [UID:0000KH] remains the file root for `NexusTK/render/ItemObjImageLib.cpp`; metadata should become `90/88`, path unchanged, owner `FILE`. | `by-file/ItemObjImageLib.md` | incorporate | applied | Header is now `COMPLETION:90`, `CONFIDENCE:88`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, `CANONICAL_OWNER:FILE`; validator `000000003281` returned exit `0`, `ok: 1`. |
| Generated-output audit must record `validator-command-id: 000000003240`, `validator-refreshed-at: 2026-07-01T04:25:52-04:00`, 16 total emitters, 2 filled, 14 empty, 12.5%, and by-file report coverage `0`. | `by-file/ItemObjImageLib.md` | incorporate | applied | Added durable 2026-07-01 B007 generated-output audit with header proof, tracker row, populated outputs, empty-marker triage, accepted/rejected routes, and draw/glyph blocker dispositions. |
| [UID:0002SD] constructor C++ and [UID:0002VC] scalar deleting destructor no-code marker are already populated and should not be changed in this callback. | `by-memory/0x004dec30-0x004dee1b.ItemObjImageLibConstructor.md`; `by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md` | already-present | already-present | Not edited. Generated `ItemObjImageLib.cpp` after validator `000000003290` still contains constructor C++ and no stale empty marker for either UID. |
| Earlier B007 recommendation to make [UID:0000RA] comment-only was too conservative. | This report revision and callback result | reject-stale | applied | Superseded by formal singleton declaration in `by-global/g_pItemObjImageLib.md`; generated output now emits `ItemObjImageLib *g_pItemObjImageLib = 0;`. |
| [UID:0000RA] should emit `ItemObjImageLib *g_pItemObjImageLib = 0;`. | `by-global/g_pItemObjImageLib.md` | incorporate | applied | Formal block populated exactly; validator `000000003285` returned exit `0`, `ok: 1`; generated output includes the declaration. |
| [UID:0001OT] should stay comment-only because it is the backing `.data` storage duplicate for [UID:0000RA]. | `by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md` | incorporate | applied | Formal block contains the storage-duplicate no-code marker; validator `000000003286` returned exit `0`, `ok: 1`. |
| Earlier B007 recommendation to make [UID:0001UT] comment-only because names/header placement were provisional is invalid under current source-shape rules. | This report revision and callback result | reject-invalid | applied | Superseded by first-draft `struct ItemInfo` in `by-type/by-struct/ItemInfo.md`; provisional names remain caveats only. |
| [UID:0001UT] should emit a first-draft `struct ItemInfo` with fields `itemTableId`, `paletteSlot`, `alpha`, `renderFlagsOrMode`, `allowPaletteFilter`, and three padding bytes. | `by-type/by-struct/ItemInfo.md` | incorporate | applied | Formal block populated exactly; validator `000000003290` returned exit `0`, `ok: 1`; generated output includes the struct and no empty marker. |
| Earlier B007 recommendation to make [UID:0001UU] comment-only because it is "layout evidence" was too conservative. | This report revision and callback result | reject-stale | applied | Superseded by first-draft `ItemObjImageLib` class/layout declaration in `by-type/by-struct/ItemObjImageLibLayout.md`. |
| [UID:0001UU] should emit a first-draft `ItemObjImageLib` declaration with method prototypes and `ProtectedArray<ItemInfo> m_itemInfos`. | `by-type/by-struct/ItemObjImageLibLayout.md` | incorporate | applied | Formal block populated exactly; validator `000000003283` returned exit `0`, `ok: 1`; generated output has no stale empty marker for UID0001UU. |
| [UID:00006W] should remain comment-only in this batch because class route prose is needed but formal declaration should be emitted through [UID:0001UU] to avoid duplicate class declarations. | `by-class/ItemObjImageLib.md` | incorporate | applied | Formal block contains the duplicate-route no-code marker; validator `000000003282` returned exit `0`, `ok: 1`; generated output includes the marker and no empty marker. |
| [UID:0001XW] and [UID:0002ML] should stay comment-only generated-binary vtable/type artifacts. | `by-type/by-vtable/ItemObjImageLibVtable.md`; `by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md` | incorporate | applied | Formal blocks contain generated-binary no-code markers; validators `000000003284` and `000000003289` returned exit `0`, `ok: 1`; generated output has no stale empty marker for either UID. |
| [UID:00017O] should stay comment-only because its raw ordinary destructor bytes are ABI cleanup/vptr/free/base sequence, not safe handwritten source. | `by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md` | incorporate | applied | Formal block contains ABI-cleanup no-code marker; validator `000000003287` returned exit `0`, `ok: 1`; generated output includes the marker. |
| [UID:00017Y] should stay comment-only because it is constructor SEH/unwind cleanup glue. | `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md` | incorporate | applied | Formal block contains constructor-SEH cleanup no-code marker; validator `000000003288` returned exit `0`, `ok: 1`; generated output includes the marker. |
| Draw/glyph bodies [UID:00041R/S/T/U] and [UID:0000UQ] remain source-authored but not formal-C++ ready in this callback. | `by-file/ItemObjImageLib.md`; no formal edit to draw/glyph pages | incorporate | applied | By-file audit records their investigated blockers. Draw/glyph pages were not edited; generated output after `000000003290` still has the expected empty-marker disposition for [UID:0000UQ], and no new draw/glyph C++ was introduced. |
| A formal C++ edit to draw/glyph pages during this first batch is not applicable. | `by-memory/0x004dee50-0x004defba...`; `0x004defc0...`; `0x004df1e0...`; `0x004df2c0...`; `0x004df460...` | not-applicable | excluded-with-reason | Supervisor scope was declaration/no-code cleanup only; no draw/glyph by-memory pages were leased or edited. |
| UI panes and shared helper libraries are not owners of ItemObjImageLib source. | `by-file/ItemObjImageLib.md` audit/rejected routes | incorporate | applied | By-file audit records rejected UI/shared-helper routes and accepted file/class/layout/global route. |
| Generated-binary artifacts should not become hand-written C++. | Relevant support pages | incorporate | applied | Vtable type/data, singleton storage duplicate, raw destructor body, and SEH helper all now have comment-only formal markers instead of handwritten table/helper/ABI code. |
| No target/support by-* docs were edited in this report-first revision. | This report-only pass | not-applicable | already-present | Historical report-first statement preserved as no longer active callback work; implementation edits were performed only after supervisor acceptance and only in the scoped by-* targets. |

## Implementation Tracking Checklist

- [x] Update [UID:0000KH] metadata to `COMPLETION:90`, `CONFIDENCE:88`; preserve path and owner. Proof: validator `000000003281`, exit `0`, `ok: 1`.
- [x] Add the B007 generated-output audit to [UID:0000KH], including generated header proof, tracker row, 2 populated outputs, 14 empty markers, accepted route, rejected routes, source-declaration decisions, no-code dispositions, and draw/glyph blocker dispositions.
- [x] Insert exact no-code marker for [UID:00006W]. Proof: validator `000000003282`, exit `0`, `ok: 1`.
- [x] Insert exact first-draft class/layout declaration for [UID:0001UU]. Proof: validator `000000003283`, exit `0`, `ok: 1`.
- [x] Insert exact no-code marker for [UID:0001XW]. Proof: validator `000000003284`, exit `0`, `ok: 1`.
- [x] Insert exact first-draft global declaration for [UID:0000RA]. Proof: validator `000000003285`, exit `0`, `ok: 1`.
- [x] Insert exact no-code marker for [UID:0001OT]. Proof: validator `000000003286`, exit `0`, `ok: 1`.
- [x] Insert exact no-code marker for [UID:00017O]. Proof: validator `000000003287`, exit `0`, `ok: 1`.
- [x] Insert exact no-code marker for [UID:00017Y]. Proof: validator `000000003288`, exit `0`, `ok: 1`.
- [x] Insert exact no-code marker for [UID:0002ML]. Proof: validator `000000003289`, exit `0`, `ok: 1`.
- [x] Insert exact first-draft `struct ItemInfo` declaration for [UID:0001UT]. Proof: validator `000000003290`, exit `0`, `ok: 1`.
- [x] During implementation callback, update the ledger rows for the stale original B007 comment-only recommendations: [UID:0000RA] as `reject-stale`, [UID:0001UU] as `reject-stale`, and [UID:0001UT] as `reject-invalid`, with callback verification state updated from `proposed`.
- [x] Update the Claim And Incorporation Ledger verification states from `proposed` to `applied`, `already-present`, `excluded-with-reason`, or `blocked` during implementation callback.
- [x] Do not edit [UID:00041R], [UID:00041S], [UID:00041T], [UID:00041U], or [UID:0000UQ] in the first callback unless the supervisor explicitly expands scope to a draw/glyph source-quality pass.
- [x] Run the scoped validators with `--wait-generated`. Proof: validators `000000003281` through `000000003290`, all exit `0`, all `ok: 1`.
- [x] Inspect `auto-generated/NexusTK/render/ItemObjImageLib.cpp` and report header freshness plus remaining expected empty markers. Proof: header `validator-command-id: 000000003290`, `validator-refreshed-at: 2026-07-01T04:46:53-04:00`; no stale empty markers for [UID:00006W], [UID:0001UU], [UID:0001XW], [UID:0000RA], [UID:0001OT], [UID:00017O], [UID:00017Y], [UID:0002ML], or [UID:0001UT].
- [x] Do not edit generated reports, project-level reports, manual `-coverage-report.md` files, validator/tool state, queue files, archives, supervisor ledgers, or IDA DB.

## Blockers / Open Issues

No MCP availability blocker. MCP was available and current evidence was collected.

No in-scope issue is left as "needs investigation." The draw/glyph blockers were investigated and remain real: helper declarations, render callback order/type, `RectBounds` mutation semantics, draw-local structure names, and `drawOwner` static type are not source-quality yet. The correct current disposition is no draw/glyph formal C++ in the first implementation batch.

FINISHED implementation callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000KH-ItemObjImageLib-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000KH-ItemObjImageLib-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T04:52:21","uid":"0000KH"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000KH-ItemObjImageLib-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0000KH-ItemObjImageLib-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000KH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
