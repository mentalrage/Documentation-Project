*** UID:0002XC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MapNamePane *g_pMapNamePane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pMapNamePane

## Status

- Address: `0x0069b4b4` (`dword_69B4B4` in IDA).
- Type: `MapNamePane *`.
- Owner file: [UID:0000L2][MapNamePane](by-file/MapNamePane.md). The older possible fold into [UID:0000L3][MapPane](by-file/MapPane.md) is retained as a rejected historical alternative because MapPane is only an external consumer.
- Disposition: reconstructable NexusTK singleton global.
- Rebuild handling: `source-declared/generated-binary`.
- 2026-07-04 B012 source-quality callback: first-draft formal declaration is now emitted here as `MapNamePane *g_pMapNamePane = NULL;`; [UID:0002XD][0x0069b4b4-0x0069b4b8.g_pMapNamePane](by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md) carries only a no-duplicate marker.

## Role

`g_pMapNamePane` stores the active map-name overlay pane. It is written by `MapNamePane` construction, cleared by destructor/helper paths, and read by a map-side helper that needs the live pane/global while updating map UI state.

The first-draft declaration is intentionally non-static. Current documentation keeps [UID:0000L2][MapNamePane](by-file/MapNamePane.md) as the source-file route, while [UID:0000L3][MapPane](by-file/MapPane.md) consumes the singleton at `0x00504a43`; a file-static definition would hide the symbol from that separate consumer unless future source consolidation proves both users are in one translation unit.

## Evidence

- IDA MCP `py_eval` on 2026-06-07 reported `0x0069b4b4-0x0069b4b8` as a four-byte item named `dword_69B4B4`, with six xrefs.
- IDA MCP `get_bytes` on 2026-06-12 A003 Batch 342 supersedes the older byte note for the active `b001_nexustk` database: the exact storage slot is `00 00 00 00`.
- B012 MCP session `ddf5b602` on 2026-07-04 reconfirmed `0x0069b4b4` is non-function storage initialized to `NULL` / `00 00 00 00`; `get_global_value 0x0069b4b4` and `get_global_value dword_69B4B4` return `0x0`; active IDA name/global queries do not recover a current data symbol named `g_pMapNamePane`, so the source-facing name remains documentation/source-route backed.
- Xrefs are constructor publish/fallback writes `0x0050323b` and `0x00503242`, destructor clear `0x0050332e`, singleton helper clear `0x005037f0`, scalar deleting destructor clear `0x005038a5`, and external map-side reader `0x00504a43`.
- [UID:0000L2][MapNamePane](by-file/MapNamePane.md) and [UID:00007P][MapNamePane](by-class/MapNamePane.md) document the map-name pane construction, resource setup, vtables, update handler, and source placement.
- The exact storage split is [UID:0002XD][0x0069b4b4-0x0069b4b8.g_pMapNamePane](by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md).

## Ownership Decision

Use `g_pMapNamePane` as the canonical documentation name for the `dword_69B4B4` slot. Keep the declaration with the map-name/map UI source owner, not with the adjacent MiniMapButtonPane or game-server object table globals. MapPane is a consumer of the singleton, not the canonical owner; adjacent/sibling slots remain separated by their own xref families and direct source routes.

## 2026-08-12 B003 Definition And Source-Order Closure

- The sole source definition remains exactly `MapNamePane *g_pMapNamePane = NULL;`. It is intentionally non-static because the live read at `0x00504a43` belongs to a separate MapPane consumer route.
- `MapNamePane.h`, emitted by [UID:00007P][MapNamePane](by-class/MapNamePane.md), owns the one `extern MapNamePane *g_pMapNamePane;` declaration. This global page keeps H blank to avoid a duplicate declaration channel.
- Direct-file position is `20`, after UID00007P at position `10`. The class emitter first supplies `#include "MapNamePane.h"`, declarations, and method children; this page then supplies the global definition. The former global-first order is rejected because it produces a definition before `MapNamePane` declaration visibility.
- The exact six-reference lifecycle is constructor writes at `0x0050323b` and `0x00503242`, ordinary-destructor clear at `0x0050332e`, constructor-unwind clear at `0x005037f0`, scalar-wrapper clear at `0x005038a5`, and external MapPane read at `0x00504a43`.
- Exact storage bytes are `00 00 00 00`. The earlier `0xffffffff` statement is preserved as superseded historical evidence from an older IDA view; it is not current initialization semantics.
- [UID:0002XD][0x0069b4b4-0x0069b4b8.g_pMapNamePane](by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md) remains covered-by storage evidence and must not emit another definition.
- Final `93/95` reflects exact bytes, complete references, ownership, declaration/definition split, and compile-safe source order. Confidence remains capped because the original binary does not retain the source symbol name.

## Cross-References

- [UID:0000L2][MapNamePane](by-file/MapNamePane.md)
- [UID:00007P][MapNamePane](by-class/MapNamePane.md)
- [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- [UID:0001AK][0x005031f0-0x005038fe.MapNamePane](by-memory/0x005031f0-0x005038fe.MapNamePane.md)
- [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md)

## Changes

- 2026-06-07 Batch 043: Created canonical global page for the exact `0x0069b4b4` singleton slot. Evidence: live IDA MCP confirmed the item bounds, initial value, six xrefs, and direct ownership by `MapNamePane` constructor/destructor/helper paths.
- 2026-06-12 A003 Batch 342: Corrected the active-IDB initial storage bytes from the stale `0xffffffff` note to `0x00000000`; xrefs and ownership remain unchanged.
- 2026-07-04 B012 implementation callback: raised score from `86/88` to `88/91`, inserted the formal declaration `MapNamePane *g_pMapNamePane = NULL;`, recorded current MCP session `ddf5b602` non-function/zero-byte/value/xref/name-caveat evidence, and documented why the declaration is non-static while [UID:0002XD][0x0069b4b4-0x0069b4b8.g_pMapNamePane](by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md) remains the no-duplicate exact storage child.
