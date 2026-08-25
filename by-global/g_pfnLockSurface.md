*** UID:0000QW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pfnLockSurface

## Status

- Symbol kind: recovered alias for a render callback-table slot.
- Backing storage: `0x0069b3fc` / `dword_69B3FC`.
- Likely source module: [UID:0000OC][Surface](by-file/Surface.md).
- Related global: [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md).
- Confidence: strong for address/alias relationship, broad shared ownership, installed targets, and rejection at the EPF call site; table-wide original typedef/name remains outside this alias page.

## Role

`g_pfnLockSurface` is a recovered callsite-biased name, but IDA MCP shows the call is really through [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `dword_69B3FC` at `0x0069b3fc`.

The name should be treated as a callsite-biased alias, not as an `EPFImageControlPane`-owned global. The slot is used broadly by pane paint/fill/presentation paths and is initialized by the surface render-family setup at `0x00558840`.

## EPF Call-Site Resolution

IDA decompilation of `0x00499310` shows the actual call shape as:

```cpp
dword_69B3FC(this, this + 68);
```

The exact call has a GrafPort/pane receiver and a `RectBounds` pointer. Installed targets `0x004be680` and `0x004c4380` consume draw color, clip, surface, and rectangle state as pane-region fill/presentation behavior. For [UID:0004JW][0x00499310-0x004993a5.EPFImageControlPaneOnPaint](by-memory/0x00499310-0x004993a5.EPFImageControlPaneOnPaint.md), the accepted source projection is `FillRect(&m_bounds)`, not a lock operation.

This resolves the EPF call site without claiming that all 206 slot references share one final public name or that the full table declaration is complete.

## Evidence

- IDA MCP `lookup_funcs` reports `0x0069b3fc` is not a function, matching global function-pointer storage.
- IDA MCP decompilation of virtual `EPFImageControlPane::OnPaint` at `0x00499310` calls `dword_69B3FC(this, this + 68)` before frame lookup, then calls `dword_69B3E8` for the actual valid-frame image blit.
- IDA MCP decompilation of the surface initializer at `0x00558840` assigns `dword_69B3FC` to either `0x004be680` or `0x004c4380` based on the active surface format family.
- The same callback slot appears in list, mail, map-tile, and pane paint paths, so ownership belongs with shared render infrastructure.
- 2026-05-31 IDA MCP `py_eval` recheck confirms `0x0069b3fc` is a 4-byte `.data` callback-table slot named `dword_69B3FC`, initialized to `0xffffffff`, with 206 data xrefs. The only direct writes found are initialization/reset writes at `0x00558770`, `0x00558bc6`, and `0x00558ee2`; the latter two assign `sub_4BE680` or `sub_4C4380` from the surface initializer.
- Live IDA MCP on 2026-06-04 reconfirms `0x0069b3fc` is not a function, `sub_558840` is the surface initializer at `0x00558840` with size `0x723`, `sub_499310` is the representative EPF callsite at `0x00499310` with size `0x95`, and the two assigned callback targets are `sub_4BE680` (`0x6e7` bytes) and `sub_4C4380` (`0x340` bytes).
- The 2026-06-04 xref summary again reports 206 refs across 130 containing functions for `dword_69B3FC`. Representative high-count users include `sub_484A60`, `sub_55C650`, `sub_585B80`, `sub_41DAB0`, `sub_459CE0`, and `sub_4832C0`, which reinforces that this is a shared render/presentation callback slot rather than a pane-local global.
- The same 2026-06-04 disassembly summary identifies the only direct writes as `0x00558770` (`mov dword_69B3FC, edi`), `0x00558bc6` (`mov dword_69B3FC, offset sub_4BE680`), and `0x00558ee2` (`mov dword_69B3FC, offset sub_4C4380`).
- IDA `callers` reports no ordinary direct callers for `sub_4BE680` or `sub_4C4380`, matching table-dispatched callback targets rather than standalone public functions.
- 2026-06-16 live IDA MCP reconfirmed the representative EPF-image call shape at `0x00499310` as `unk_69B3FC(this, this + 68)`, followed by the actual frame draw through `unk_69B3E8(...)`. This keeps the generated one-argument `g_pfnLockSurface(drawSurface)` projection rejected.
- The same live pass reconfirmed `sub_558840` size `0x723`, callback target sizes `sub_4BE680` size `0x6e7` and `sub_4C4380` size `0x340`, and the compat-family assignment at `0x00558bc6` (`unk_69B3FC = sub_4BE680`). The `0x0069b3fc` backward trace still shows broad pane/render dispatch fanout, including `EPFImageControlPane`, `CheckBoxControlPane_OnPaint`, `MyItemListPane_DrawListEntry`, map/image paths, and many shared UI paint paths.
- IDA DB mutation was skipped for this alias: the current slot name/signature and final declaration style belong to the parent [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md), not to this ignored generated alias.
- The EPF path sets draw color to zero immediately before the slot call and passes inherited `m_bounds`; this is the same source shape represented by accepted pane `FillRect` paint children.
- No lock token, mapped pointer, pitch, success test, or unlock operation follows the slot call. The one-argument generated lock alias is therefore behaviorally false for this consumer.

## Ownership Decision

Keep this alias documented under [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) and [UID:0000OC][Surface](by-file/Surface.md). Do not treat `class_EPFImageControlPane.cpp` as the owner of the storage or final function-pointer type.

## Cross-References

- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md)
- [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md)
- [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md)
- [UID:00011J][0x004991f0-0x004993a5.EPFImageControlPaneCore](by-memory/0x004991f0-0x004993a5.EPFImageControlPaneCore.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- 2026-07-13 B001 UID00011J accepted callback:
  - Raised `86/88 -> 90/92` while retaining `CANONICAL_OWNER:NONE`, non-reconstructable, blank emitter/position, and blank formal C++.
  - Resolved the EPF consumer from historical lock/load wording to virtual OnPaint `FillRect(&m_bounds)` using exact two-argument call shape and installed target behavior; table-wide spelling remains intentionally broader.
- 2026-05-31 reconstruction classification:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and coverage listed this alias under reconstructable rows.
  - Changed to: `COMPLETION:72`, `CONFIDENCE:84`, `RECONSTRUCTABLE:FALSE`, and coverage treats it as an ignored callback-slot alias.
  - Summary/evidence: IDA MCP confirms the address is a slot inside [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md), not a standalone EPFImageControlPane-owned source global. Reconstruction should model the callback table and surface initializer, not emit a separate `g_pfnLockSurface` global.
- 2026-06-04 live IDA refresh:
  - Before: the page had the ignored-alias classification but did not record current callback target sizes, xref breadth, direct-write disassembly, or table-dispatch caller evidence.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`, while keeping `RECONSTRUCTABLE:FALSE`.
  - Summary/evidence: live IDA MCP reconfirmed `0x0069b3fc` as data, `dword_69B3FC` initialized to `0xffffffff`, 206 xrefs across 130 functions, only three direct writes at `0x00558770`, `0x00558bc6`, and `0x00558ee2`, assigned targets `sub_4BE680` and `sub_4C4380`, the representative two-argument call at `0x00499310`, and absence of ordinary direct callers for the assigned targets. The score remains below final because the slot's source-level name and full callback signature still need a broader signature pass.
- 2026-06-16 C001 global/source-quality refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, still `RECONSTRUCTABLE:FALSE`.
  - Summary/evidence: live IDA reconfirmed the two-argument call shape at `0x00499310`, `sub_558840` callback-table initializer size `0x723`, slot-7 compat assignment at `0x00558bc6`, callback target sizes, and broad `0x0069b3fc` fanout. The page now clears the 85 completion gate as a reviewed ignored alias, but the canonical slot name/signature remains a parent-table blocker.
