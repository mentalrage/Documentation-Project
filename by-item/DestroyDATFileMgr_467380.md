*** UID:0000UF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DestroyDATFileMgr 0x00467380

## Status

- Confidence: strong for behavior, high for Application cleanup ownership, medium-high for original helper spelling.
- Address: `0x00467380`
- Exact memory range: [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md)
- Selected source family: [UID:0000HG][Application](by-file/Application.md) fatal resource-load cleanup.
- Related object owner: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) owns the manager class and [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) singleton that this helper deletes.
- Parent attachment: canonical reconstruction is now carried by [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md), which attaches to [UID:0000HG][Application](by-file/Application.md). This by-item page remains a name/index note and intentionally does not duplicate the autogen parent.
- Evidence basis: IDA MCP lookup/decompile/caller/callee checks through 2026-05-30.

## Behavior

`0x00467380` checks [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md). If the active [UID:00003I][DATFileMgr](by-class/DATFileMgr.md) wrapper exists, the helper calls vtable slot 0 with delete flag `1`, effectively running the manager scalar deleting destructor.

Final C++ should be expressed as `delete g_pDATFileMgr;`; the explicit vtable call is compiler output for deleting a polymorphic object. The helper does not write null back to the global.

## Evidence

- IDA MCP `lookup_funcs` reports `sub_467380` at `0x00467380` with size `0x11`.
- IDA MCP decompilation shows only a `dword_67AB40` null check and virtual deleting-destructor call with delete flag `1`.
- IDA MCP `callees 0x00467380` reports no direct callees because the destructor call is indirect through the vtable.
- IDA MCP callers are concentrated in resource/image load failure paths, including [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md), [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md), [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md), [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), and [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) loader code.
- The same caller sites immediately call [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md), making this pair fatal-load cleanup glue rather than a normal DAT API.
- B001-012 IDA MCP recheck confirms all 22 direct caller sites pair this helper with [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md) in fatal image/resource load exits. The normal `g_pDATFileMgr` constructor/destructor writes and clears live in [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md); this helper is external Application/startup cleanup policy.

## Ownership Notes

Treat this item as a name/index note for the exact [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md). The helper destroys a DAT manager object, so concrete object ownership stays with `archive/DATFileMgr.cpp`; the repeated paired fatal-load callers make [UID:0000HG][Application](by-file/Application.md) the best direct source owner for the helper body.

Do not treat this as evidence that image-library modules own the DAT manager. They only call the helper while unwinding after failed asset loads.

## Cross-References

- [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md)
- [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md)
- [UID:0001P6][0x0067ab40-0x0067ab44.g_pDATFileMgr](by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md)
- [UID:0000YR][0x00463310-0x004679be.ApplicationLifecycle](by-memory/0x00463310-0x004679be.ApplicationLifecycle.md)

## Changes

- 2026-06-10 B001-012 ownership sync:
  - What existed before: the item page still described final source ownership as deferred between DATFileMgr object ownership and Application/resource failure cleanup.
  - Changed to: selected Application fatal-load cleanup as the source family and clarified that the canonical by-memory page carries the autogen parent while this by-item remains an index note.
  - Evidence: B001-012 IDA MCP confirmed the exact deleting wrapper, all 22 paired fatal resource-load callers, normal DAT manager singleton lifetime writes/clears in the DAT manager cluster, and Application/startup neighboring helper context.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`; parent attachment remains blank.
  - Before: the tiny DAT manager deletion helper was documented but unclassified in autogen coverage.
  - After: it is marked as source-authored cleanup behavior that must be reproduced, but not attached because the final source owner is still unresolved between `DATFileMgr.cpp` object ownership and application/resource-failure glue.
  - Evidence: live IDA MCP confirms `sub_467380` at `0x00467380`, size `0x11`, no direct callees, and a broad paired caller set from image/resource failure paths.

- 2026-05-30: Raised completion/confidence from `0/0` to `84/88`. Previously the page had the right helper identity but no score; it now carries the current IDA MCP no-direct-callee result, final C++ `delete g_pDATFileMgr` form, and unchanged source-owner caveat.
