*** UID:0000S5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pScreenDimmer

## Status

- Confidence: strong for identity, lifecycle, direct ScreenDimmer owner, and broad consumer role; medium for exact original declaration spelling.
- Symbol kind: global singleton pointer.
- Address: `0x0069ae08` (`dword_69AE08` in IDA).
- Likely owner: [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- Exact storage page: [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md), now attached to [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- Assignment status: this page now clears the strict child gate at `85/88`, and direct parent [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md) clears the parent gate at `87/86`, so `AUTOGEN_PARENT_UID:0000NA` is retained.

## Role

`g_pScreenDimmer` stores the active modal dim overlay. [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md) construction assigns it, and both the ordinary and scalar deleting destructor paths clear it after removing the dimmer from the modal list and pane hierarchy.

Live IDA also has a small helper at [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) that clears the singleton directly. Treat that helper as part of the ScreenDimmer source-boundary review even though it is separate from the main constructor/destructor block.

The exact `.data` slot is [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md). That page carries the address-range and source-declared/generated-binary reconstruction evidence; this global page remains the name/lifetime/owner summary.

## Evidence

- Live IDA MCP check on 2026-05-30 confirms `0x0069ae08` is `dword_69AE08`, a 4-byte `.data` item with 40 data xrefs.
- Live IDA MCP on 2026-06-10 reconfirms 40 direct data xrefs to `0x0069ae08`; the writer set remains the ScreenDimmer lifecycle sites while dialog/menu/session/map consumers only read or test the singleton.
- Live IDA MCP `lookup_funcs` on 2026-06-10 reports the owning lifecycle functions as `sub_559B90` size `0x156`, 342 decimal bytes (Verified with int_convert.py), ordinary destructor `sub_559CF0` size `0xd4`, 212 decimal bytes (Verified with int_convert.py), tiny clear helper `sub_55A030` size `0xb`, 11 decimal bytes (Verified with int_convert.py), scalar deleting destructor `sub_55A070` size `0x103`, 259 decimal bytes (Verified with int_convert.py), and factory `sub_4A12B0` size `0xb0`, 176 decimal bytes (Verified with int_convert.py).
- Lifecycle writes are concentrated in the ScreenDimmer block: `0x00559be4` stores the constructed pointer, `0x00559beb` clears the null/fallback path, `0x00559d9b` clears during cleanup, `0x0055a030` is a tiny direct clear helper, and `0x0055a122` clears during the deleting-destructor path.
- 2026-06-10 decompilation/disassembly confirms the constructor stores `this` to `dword_69AE08` after deriving the object base from the dim-level byte at `this+0xf8`, 248 decimal bytes (Verified with int_convert.py), installs vtables at object base, `+0xa0` / 160 decimal bytes (Verified with int_convert.py), and `+0xa4` / 164 decimal bytes (Verified with int_convert.py), then registers the `+0xa0` interface in the modal list.
- 2026-06-10 decompilation confirms `CreateScreenDimmer_4A12B0` allocates `0xfc` bytes, 252 decimal bytes (Verified with int_convert.py), and constructs a level-5 `ScreenDimmer` through `0x00559b90`; this proves factory use, not independent ownership of the singleton.
- 2026-06-10 `xrefs_to 0x0055a030` reports one cleanup/funclet jump xref at `0x006074a1`, consistent with the helper being local ScreenDimmer unwind cleanup rather than a public global API.
- Representative consumers include modal/menu/dialog flows at `0x004a0f05`, `0x004a1360`, `0x004a1380`, `0x004a1599`, `0x004f69a0`, `0x004f8a9f`, `0x004f8ebc`, `0x004fa5fd`, `0x004fab7c`, `0x004fcb57`, `0x004fec28`, `0x004fee8d`, and the `0x00502xxx`/`0x0052xxxx` dialog families.
- Later consumers at `0x0057406d`, `0x005742ca`, `0x00587eb2`, and `0x00588043` confirm the singleton remains a generic overlay dependency beyond the constructor/destructor block.
- Keep this as an alias/ownership page rather than duplicating backing-storage documentation; the exact storage is documented at [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md), while [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) documents the tiny clear helper.
- 2026-06-06 A009/A010 refresh: [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) now records exact bytes, no callees, no ordinary callers, one cleanup/funclet xref, and the lifecycle-defining `g_pScreenDimmer` refs; [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md) is attached to [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md).

## Ownership Guidance

Declare this with the generic screen overlay source family, likely `ui/core/ScreenDimmer.cpp` or its header. Do not give the storage to `MapRefreshDimmer`; that class is a map-specific timed dimmer companion, while this singleton represents the generic modal overlay.

## Open Questions

- Whether the original declaration used `ScreenDimmer* g_pScreenDimmer` or a broader `Pane*`/interface pointer type.
- Whether helper `0x0055a030` was a named teardown function, an inline clear path, or compiler/vtable support around the dimmer singleton.

## Cross-References

- [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md)
- [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md)
- [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md)
- [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md)

## Changes

- 2026-06-10 A001 live lifecycle/xref refresh:
  - Before: score `80/86` but the page was already attached to [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md), leaving the child side below the strict `85/85` gate.
  - Changed to: score `85/88`; retained `AUTOGEN_PARENT_UID:0000NA`.
  - Summary/evidence: live IDA MCP reconfirmed 40 direct xrefs to `0x0069ae08`, exact lifecycle writer sites in the constructor, ordinary destructor, tiny cleanup helper, and scalar deleting destructor, the single cleanup/funclet jump xref to `0x0055a030`, the factory allocation/constructor path, and the modal-list registration/interface offsets. The direct file parent already clears `87/86`, so the assignment now satisfies the strict child/direct-parent gate. Completion stays below final-audit because exact original declaration spelling and several broad consumer pages still retain raw `dword_69AE08` labels.
- 2026-06-05: Marked reconstructable and attached to [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs bind the singleton to the ScreenDimmer constructor, cleanup helper, direct clear helper, and deleting-destructor path; the broad consumer fan-out is overlay usage rather than ownership. No score change and no reconstruction C++ were added.
- 2026-06-06 A010 storage/owner sync:
  - Before: score `74/84`; the page summarized the singleton but did not link the exact `.data` slot as the attached storage page.
  - Changed to: score `80/86`, added [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md) as exact storage, and recorded the A009/A010 attachment evidence.
  - Summary/evidence: the exact memory slot, clear helper, and overlay aggregate pages now agree on ScreenDimmer ownership, lifecycle writes/clears, and generic UI overlay placement. Confidence remains below final-audit because several consumer pages still use raw `dword_69AE08` labels and exact original header declaration spelling remains open.
- 2026-05-30: What existed before: the page relied partly on weak source-output evidence and had no completion/confidence score. What changed: set completion/confidence to `74/84` and replaced that evidence with live IDA MCP storage and xref evidence. Summary/evidence: IDA reports `0x0069ae08` as a 4-byte `.data` item with 40 xrefs; the constructor/destructor/helper clear sites are identifiable, but the consumer set is broad and several references still need source-level owner names, so completion and confidence remain below the tighter singleton pages.
