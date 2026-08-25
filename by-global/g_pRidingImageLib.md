*** UID:0000S4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
RidingImageLib *g_pRidingImageLib = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pRidingImageLib

## Status

- Confidence: strong for address, owner, and `RidingImageLib` spelling.
- Kind: process-wide singleton pointer.
- Backing storage: [UID:0001PO][0x0069b444-0x0069b448.g_pRidingImageLib](by-memory/0x0069b444-0x0069b448.g_pRidingImageLib.md), currently IDA `dword_69B444` with physical type `_DWORD *`, a zero initializer, and exactly 20 references.
- Canonical owner: [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md) in [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md).
- Current documentation alias: `g_pRidingImageLib`.

## Meaning

`g_pRidingImageLib` is the global pointer to the riding/mount sprite library. Riding-aware render paths read it to find the loaded `RIDINGS.DNA` animation definitions and the `RIDINGS.EPF` frame table.

Keep this global with `render/RidingImageLib.cpp`. Consumers should not adopt it just because they render mount/riding sprites.

## Write Evidence

Live IDA MCP on 2026-05-30 confirms `0x0069b444` is `dword_69B444`, a 4-byte `.data` item with 20 data xrefs. The write/clear sites are:

| Address | Function | Meaning |
| --- | --- | --- |
| `0x004dc6c4` | `RidingImageLib::RidingImageLib` | Stores the constructed `RidingImageLib*` singleton. |
| `0x004dc6cb` | `RidingImageLib::RidingImageLib` | Constructor fallback/guard path clears the singleton. |
| `0x004dc7bc` | [UID:00017G][0x004dc730-0x004dc7d8.RidingImageLibDestructor](by-memory/0x004dc730-0x004dc7d8.RidingImageLibDestructor.md) | Clears the singleton during non-deleting cleanup. |
| `0x004e5bf0` | [UID:000183][0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper](by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md) | Tiny cleanup helper that clears the singleton. |
| `0x004e6943` | Compiler-generated RidingImageLib scalar deleting wrapper (`0x004e68b0-0x004e6981`) | Clears the singleton while duplicating the ordinary cleanup inline; the wrapper is false/non-emitting and has no separate source body. |

The constructor also installs the [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md), calls `LoadRidingDefinitions`, and loads `RIDINGS.EPF` through the shared frame-table loader.
The live constructor/destructor windows include `RidingImageLib` vtable references, which removes the earlier medium-confidence spelling caveat.

2026-06-14 A003 live IDA MCP refresh reconfirmed the lifecycle functions and sizes: constructor `sub_4DC690` is `0x92` / `146` bytes (Verified with int_convert.py), ordinary destructor `sub_4DC730` is `0xa8` / `168` bytes (Verified with int_convert.py), singleton clear helper `sub_4E5BF0` is `0xb` / `11` bytes (Verified with int_convert.py), and scalar deleting destructor `sub_4E68B0` is `0xd1` / `209` bytes (Verified with int_convert.py). The decompilation still shows constructor publish/fallback clear, `RidingImageLib` vtable installation, `LoadRidingDefinitions`, `RIDINGS.EPF` loading, ordinary/scalar destructor resource cleanup, and final singleton clearing.

## Consumer Evidence

Representative readers include:

- `0x004f6612` in `Application::Shutdown`, which checks the singleton during image-library teardown.
- `0x004e2bc1`, `0x004e3360`, `0x004e3918`, `0x004e441d`, `0x004e4b3e`, `0x004e4b4f`, and `0x004e4b72` in the human/riding sprite composition neighborhood.
- Several raw or currently unmodeled references around `0x004d5772`, `0x004d64ea`, `0x004d7591`, `0x004d8066`, `0x004d8e2b`, `0x004e3c95`, and `0x004e3fef`. Live IDA shows these are riding sprite lookup paths that call `sub_4DCA20` or bounds-check against `[g_pRidingImageLib+8]` before falling back to the adjacent definition table.
- 2026-06-14 `xrefs_to 0x0069b444` reconfirmed exactly 20 refs: five lifecycle write/clear refs, the shutdown-sweep read at `0x004f6612`, and fourteen riding-aware lookup/composition reads split between modeled functions and raw inline neighborhoods. The modeled reader functions include `sub_4E21D0` (`0xb23` / `2851` bytes; Verified with int_convert.py), `sub_4E31F0` (`0x83e` / `2110` bytes; Verified with int_convert.py), `sub_4E4280` (`0xaf9` / `2809` bytes; Verified with int_convert.py), and shutdown helper `sub_4F6490` (`0x215` / `533` bytes; Verified with int_convert.py).

## Ownership Decision

`g_pRidingImageLib` is source-owned by `RidingImageLib`, not by `Application`, human-sprite composition callers, or the shared monster/riding animation-table helpers.

When rebuilding source, preserve this singleton as the canonical global for `0x0069b444` and keep it distinct from the adjacent riding definition table at `0x0069b430`.

## Autogen And Score Rationale

- Owner/emitter route remains [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md), which has a valid `NexusTK/render/` reconstruction path and surfaces this global to `auto-generated/NexusTK/render/RidingImageLib.cpp` without a dead end.
- Completion is raised to `90` because this page now records the exact singleton slot, all 20 refs, lifecycle write/clear functions, constructor resource loads, shutdown read, representative consumer function windows, adjacent-table distinction, route support, and formal global declaration.
- Confidence is raised to `91` because current IDA decompilation of the constructor/destructor/clear helper and the exact storage child [UID:0001PO][0x0069b444-0x0069b448.g_pRidingImageLib](by-memory/0x0069b444-0x0069b448.g_pRidingImageLib.md) agree on the lifecycle and ownership. It remains below final audit because several consumer reads are still raw/unmodeled neighborhoods and final field/helper names are not source-quality.

## 2026-06-30 B008 Source-Quality Callback

B008's accepted report resolves the blank global-emitter marker by emitting `RidingImageLib *g_pRidingImageLib = NULL;` through this page. Current MCP reads storage at `0x0069b444` as NULL/zero-filled `.data`; older `0xffffffff` initializer wording on the storage child is stale and has been historicalized there.

Ownership remains [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md), not Application or consumer render pages. Constructor, ordinary destructor, scalar wrapper, singleton clear support, shutdown, and riding-aware consumers all use this same global lifecycle.

## 2026-08-11 B006 Current IDA And Scalar-Wrapper Synchronization

- Fresh report-time inspection preserves one 4-byte data item at `0x0069b444-0x0069b448`, current IDA name `dword_69B444`, physical type `_DWORD *`, initial value zero, blank address comments, and exactly 20 references. No item recreation, width change, initializer change, or xref change is warranted.
- The evidence-backed source-quality IDA handoff is to rename the existing item to `g_pRidingImageLib`, type it `RidingImageLib *`, and add a regular address comment identifying the process-wide singleton lifecycle. Those proposed IDA changes are supervisor-owned; this documentation callback does not claim they have been applied.
- UID0002Y4 clears this same slot at `0x004e6943`, but the wrapper is now `93/96`, compiler-generated, false, and non-emitting. It duplicates UID00017G cleanup inline and does not create a second source definition. The existing formal global `RidingImageLib *g_pRidingImageLib = NULL;` remains the correct authored source output.
- The source owner remains UID0000N6. Application shutdown and rendering consumers are lifecycle users, while the adjacent riding definition table remains a distinct object at `0x0069b430`.

## Cross-References

- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md)
- [UID:00017F][0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster](by-memory/0x004dc420-0x004dca14.RidingImageLibEarlyMethodCluster.md)
- [UID:0001PO][0x0069b444-0x0069b448.g_pRidingImageLib](by-memory/0x0069b444-0x0069b448.g_pRidingImageLib.md)
- [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md)
- [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md)
- [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md)

## Changes

- 2026-08-11 B006 UID0002Y4 support synchronization:
  - Added the fresh literal IDA prestate `dword_69B444`, `_DWORD *`, zero, 20 refs, and blank comments, plus the supervisor-owned source-quality rename/type/comment disposition.
  - Recorded the target wrapper's exact singleton clear and false/non-emitting status while preserving this page's existing global definition and source ownership.

- 2026-06-06: Synced the scalar deleting destructor writer to the exact `0x004e68b0-0x004e6981` range and updated the RidingImageLib aggregate reference.
  - Evidence: A002 IDA MCP `lookup_funcs` and `xrefs_to` checks confirmed `0x004e6943` sits inside `sub_4E68B0` and the exclusive function end is `0x004e6981`.

- 2026-06-05: Marked reconstructable and attached to [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs bind the singleton to `RidingImageLib` constructor/destructor writes and render-library consumers, and the proposed source tree places the owner under `render/RidingImageLib.cpp`. No score change and no reconstruction C++ were added.
- 2026-05-30: What existed before: the page marked the address and owner as strong but kept final symbol spelling at medium confidence and had no completion/confidence score. What changed: set completion/confidence to `82/88`, removed the spelling caveat, and refreshed evidence against live IDA MCP. Summary/evidence: IDA reports `0x0069b444` as a 4-byte `.data` item with 20 xrefs; constructor/destructor windows show `RidingImageLib` vtable setup/cleanup, the write/clear sites match the documented lifecycle, and representative consumers use the singleton for riding sprite table lookup. The score remains below full because several large rendering-consumer xrefs are still not individually source-named or rewritten.
- 2026-06-14 A003 goal2 score pass: raised `82/88` to `86/90`.
  - Evidence: live IDA MCP reconfirmed the 20-ref singleton map, constructor `0x004dc690`, ordinary destructor `0x004dc730`, clear helper `0x004e5bf0`, scalar deleting destructor `0x004e68b0`, shutdown read `0x004f6612`, and representative riding-render consumers.
  - Code-entry decision: no reconstruction C++ was added; the emitted route and score gate are present, but final global declaration spelling, consumer field names, and several raw lookup neighborhoods are not final-source quality.
