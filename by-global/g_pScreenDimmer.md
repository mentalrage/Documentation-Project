*** UID:0000S5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pScreenDimmer

## Status

- Confidence: strong for identity and use; medium for final declaration owner.
- Symbol kind: global singleton pointer.
- Address: `0x0069ae08` (`dword_69AE08` in IDA).
- Likely owner: [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)

## Role

`g_pScreenDimmer` stores the active modal dim overlay. [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md) construction assigns it, and both the ordinary and scalar deleting destructor paths clear it after removing the dimmer from the modal list and pane hierarchy.

Live IDA also has a small helper at [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) that clears the singleton directly. The active generated class output does not currently emit that helper as part of the class file.

## Evidence

- Live IDA MCP check on 2026-05-30 confirms `0x0069ae08` is `dword_69AE08`, a 4-byte `.data` item with 40 data xrefs.
- Lifecycle writes are concentrated in the ScreenDimmer block: `0x00559be4` stores the constructed pointer, `0x00559beb` clears the null/fallback path, `0x00559d9b` clears during cleanup, `0x0055a030` is a tiny direct clear helper, and `0x0055a122` clears during the deleting-destructor path.
- Representative consumers include modal/menu/dialog flows at `0x004a0f05`, `0x004a1360`, `0x004a1380`, `0x004a1599`, `0x004f69a0`, `0x004f8a9f`, `0x004f8ebc`, `0x004fa5fd`, `0x004fab7c`, `0x004fcb57`, `0x004fec28`, `0x004fee8d`, and the `0x00502xxx`/`0x0052xxxx` dialog families.
- Later consumers at `0x0057406d`, `0x005742ca`, `0x00587eb2`, and `0x00588043` confirm the singleton remains a generic overlay dependency beyond the constructor/destructor block.
- Keep this as an alias/ownership page rather than duplicating backing-storage documentation; the backing storage is documented at [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) and the encompassing memory range.

## Ownership Guidance

Declare this with the generic screen overlay source family, likely `ui/core/ScreenDimmer.cpp` or its header. Do not give the storage to `MapRefreshDimmer`; that class is a map-specific timed dimmer companion, while this singleton represents the generic modal overlay.

## Open Questions

- Whether the original declaration used `ScreenDimmer* g_pScreenDimmer` or a broader `Pane*`/interface pointer type.
- Whether helper `0x0055a030` was a named teardown function, an inline-generated clear path, or compiler/vtable support around the dimmer singleton.

## Cross-References

- [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md)
- [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md)
- [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md)

## Changes

- 2026-05-30: What existed before: the page relied partly on generated Wave3/class output and had no completion/confidence score. What changed: set completion/confidence to `74/84` and replaced generated-output evidence with live IDA MCP storage and xref evidence. Summary/evidence: IDA reports `0x0069ae08` as a 4-byte `.data` item with 40 xrefs; the constructor/destructor/helper clear sites are identifiable, but the consumer set is broad and several references still need source-level owner names, so completion and confidence remain below the tighter singleton pages.
