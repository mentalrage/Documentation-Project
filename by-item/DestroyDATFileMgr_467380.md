*** UID:0000UF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DestroyDATFileMgr 0x00467380

## Status

- Confidence: strong for behavior, high for Application cleanup ownership, medium-high for original helper spelling.
- Address: `0x00467380`
- Exact memory range: [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md)
- Selected source family: [UID:0000HG][Application](by-file/Application.md) fatal resource-load cleanup.
- Related object owner: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) owns the manager class and [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) singleton that this helper deletes.
- Promotion status: retained by-item index only. Canonical code-bearing reconstruction is carried by [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md), which attaches to [UID:0000HG][Application](by-file/Application.md).
- Parent attachment: intentionally blank because this page no longer emits or owns source. The strict child/direct-parent gate is satisfied by the canonical by-memory child at `88/91` and [UID:0000HG][Application](by-file/Application.md) at `86/90`.
- Evidence basis: IDA MCP lookup/decompile/caller/callee checks through 2026-06-12.

This page is retained for older references and name lookup only. Do not route this by-item to Application as a duplicate source item; use the exact by-memory child for reconstruction and autogen.

## Behavior

`0x00467380` checks [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md). If the active [UID:00003I][DATFileMgr](by-class/DATFileMgr.md) wrapper exists, the helper calls vtable slot 0 with delete flag `1`, effectively running the manager scalar deleting destructor. The modeled helper is `0x11` / 17 bytes long (verified with `tools/int_convert.py`).

Final C++ should be expressed as `delete g_pDATFileMgr;`; the explicit vtable call is compiler output for deleting a polymorphic object. The helper does not write null back to the global.

## Evidence

- IDA MCP `lookup_funcs` reports `sub_467380` at `0x00467380` with size `0x11`.
- IDA MCP decompilation shows only a `dword_67AB40` null check and virtual deleting-destructor call with delete flag `1`.
- IDA MCP `callees 0x00467380` reports no direct callees because the destructor call is indirect through the vtable.
- IDA MCP callers are concentrated in resource/image load failure paths, including [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md), [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md), [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md), [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), and [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) loader code.
- The same caller sites immediately call [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md), making this pair fatal-load cleanup glue rather than a normal DAT API.
- B001-012 IDA MCP recheck confirms all 22 direct caller sites pair this helper with [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md) in fatal image/resource load exits. The normal `g_pDATFileMgr` constructor/destructor writes and clears live in [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md); this helper is external Application/startup cleanup policy.
- 2026-06-12 A003 IDA MCP session `b001_nexustk` reconfirms `sub_467380` at `0x00467380`, size `0x11`, non-function end at `0x00467391`, the seven-instruction null-check/vtable-deleting body, no direct callees, 22 xrefs to the helper, and 22 paired xrefs to [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md) five bytes later in the same caller sites.

## Ownership Notes

Treat this item as a name/index note for the exact [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md). The helper destroys a DAT manager object, so concrete object ownership stays with `archive/DATFileMgr.cpp`; the repeated paired fatal-load callers make [UID:0000HG][Application](by-file/Application.md) the best direct source owner for the helper body.

Do not treat this as evidence that image-library modules own the DAT manager. They only call the helper while unwinding after failed asset loads.

The by-structure repair is to keep this page out of item autogen. The exact [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md) page is the narrow canonical home for the executable range and already carries the reconstructable Application parent. Leaving this by-item as `RECONSTRUCTABLE:TRUE` would duplicate the same source helper and keep an artificial unassigned row in `auto-generated/-ag-item-coverage.md`.

## Cross-References

- [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md)
- [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md)
- [UID:0001P6][0x0067ab40-0x0067ab44.g_pDATFileMgr](by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md)
- [UID:0000YR][0x00463310-0x004674ed.ApplicationLifecycle](by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md)

## Changes

- 2026-06-12 A003 Batch 299 by-structure repair:
  - What existed before: this retained index was still `84/88`, `RECONSTRUCTABLE:TRUE`, and unassigned in item autogen despite the exact [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md) child already carrying canonical reconstruction at `88/91` under [UID:0000HG][Application](by-file/Application.md).
  - Changed to: `COMPLETION:-1`, `CONFIDENCE:-1`, and `RECONSTRUCTABLE:FALSE`; this page is now a promoted by-item index only.
  - Evidence: by-item guidance says promoted items should move to the more specific folder once ownership is clear. A003 live IDA MCP session `b001_nexustk` reconfirmed the exact `0x11` helper, non-function end, seven-instruction delete wrapper, empty direct-callee list, 22 direct helper xrefs, and 22 paired [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md) xrefs. The canonical child and direct parent already satisfy the strict gate, so duplicating a by-item parent would be less accurate than excluding this index from reconstruction.

- 2026-06-10 B001-012 ownership sync:
  - What existed before: the item page still described final source ownership as deferred between DATFileMgr object ownership and Application/resource failure cleanup.
  - Changed to: selected Application fatal-load cleanup as the source family and clarified that the canonical by-memory page carries the autogen parent while this by-item remains an index note.
  - Evidence: B001-012 IDA MCP confirmed the exact deleting wrapper, all 22 paired fatal resource-load callers, normal DAT manager singleton lifetime writes/clears in the DAT manager cluster, and Application/startup neighboring helper context.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`; parent attachment remains blank.
  - Before: the tiny DAT manager deletion helper was documented but unclassified in autogen coverage.
  - After: it is marked as source-authored cleanup behavior that must be reproduced, but not attached because the final source owner is still unresolved between `DATFileMgr.cpp` object ownership and application/resource-failure glue.
  - Evidence: live IDA MCP confirms `sub_467380` at `0x00467380`, size `0x11`, no direct callees, and a broad paired caller set from image/resource failure paths.

- 2026-05-30: Raised completion/confidence from `0/0` to `84/88`. Previously the page had the right helper identity but no score; it now carries the current IDA MCP no-direct-callee result, final C++ `delete g_pDATFileMgr` form, and unchanged source-owner caveat.
