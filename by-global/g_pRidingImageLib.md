*** UID:0000S4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pRidingImageLib

## Status

- Confidence: strong for address, owner, and `RidingImageLib` spelling.
- Kind: process-wide singleton pointer.
- Backing storage: [UID:0001PO][0x0069b444-0x0069b448.g_pRidingImageLib](by-memory/0x0069b444-0x0069b448.g_pRidingImageLib.md), IDA `dword_69B444`.
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
| `0x004e6943` | `RidingImageLib::DeletingDestructor` | Clears the singleton during object destruction. |

The constructor also installs the [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md), calls `LoadRidingDefinitions`, and loads `RIDINGS.EPF` through the shared frame-table loader.
The live constructor/destructor windows include `RidingImageLib` vtable references, which removes the earlier medium-confidence spelling caveat.

## Consumer Evidence

Representative readers include:

- `0x004f6612` in `Application::Shutdown`, which checks the singleton during image-library teardown.
- `0x004e2bc1`, `0x004e3360`, `0x004e3918`, `0x004e441d`, `0x004e4b3e`, `0x004e4b4f`, and `0x004e4b72` in the human/riding sprite composition neighborhood.
- Several raw or currently unmodeled references around `0x004d5772`, `0x004d64ea`, `0x004d7591`, `0x004d8066`, `0x004d8e2b`, `0x004e3c95`, and `0x004e3fef`. Live IDA shows these are riding sprite lookup paths that call `sub_4DCA20` or bounds-check against `[g_pRidingImageLib+8]` before falling back to the adjacent definition table.

## Ownership Decision

`g_pRidingImageLib` is source-owned by `RidingImageLib`, not by `Application`, human-sprite composition callers, or the shared monster/riding animation-table helpers.

When rewriting generated source, preserve this singleton as the canonical global for `0x0069b444` and keep it distinct from the adjacent riding definition table at `0x0069b430`.

## Cross-References

- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md)
- [UID:00017F][0x004dc420-0x004e6980.RidingImageLib](by-memory/0x004dc420-0x004e6980.RidingImageLib.md)
- [UID:0001PO][0x0069b444-0x0069b448.g_pRidingImageLib](by-memory/0x0069b444-0x0069b448.g_pRidingImageLib.md)
- [UID:0001YM][RidingImageLibVtable](by-type/by-vtable/RidingImageLibVtable.md)
- [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md)
- [UID:0001VV][RidingDefinition](by-type/by-struct/RidingDefinition.md)

## Changes

- 2026-05-30: What existed before: the page marked the address and owner as strong but kept final symbol spelling at medium confidence and had no completion/confidence score. What changed: set completion/confidence to `82/88`, removed the spelling caveat, and refreshed evidence against live IDA MCP. Summary/evidence: IDA reports `0x0069b444` as a 4-byte `.data` item with 20 xrefs; constructor/destructor windows show `RidingImageLib` vtable setup/cleanup, the write/clear sites match the documented lifecycle, and representative consumers use the singleton for riding sprite table lookup. The score remains below full because several large rendering-consumer xrefs are still not individually source-named or rewritten.
