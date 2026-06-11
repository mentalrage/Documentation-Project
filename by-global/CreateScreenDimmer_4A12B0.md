*** UID:0000PJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CreateScreenDimmer_4A12B0

## Status

- Confidence: strong from live IDA MCP and memory evidence.
- Symbol kind: free helper function.
- Address range: `0x004a12b0-0x004a1360`.
- Memory doc: [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md)
- Signature: `ScreenDimmer* __cdecl CreateScreenDimmer_4A12B0(void)`.
- Likely owner: [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)

## Behavior

`CreateScreenDimmer_4A12B0` chooses the parent pane for a modal dimmer, allocates 252 bytes, and constructs a level-5 [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md).

Parent selection:

- If [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / IDA `byte_66DA97` is `1` and [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / IDA `dword_67A748` is non-null, use the host pane pointer at `dword_67A748 + 0x214`.
- If [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / IDA `byte_66DA97` is `1` and `dword_67A748` is null, use `dword_67A7CC`.
- Otherwise use `dword_67A764`, currently typed as `MapPane*` in generated output and also used as the active map pane global elsewhere.

## Evidence

- Live IDA MCP `lookup_funcs` reports `0x004a12b0` as a real function of size `0xb0`, ending end-exclusive at `0x004a1360`.
- Live IDA MCP decompilation shows the helper allocates 252 bytes and calls the `ScreenDimmer` constructor at `0x00559b90` with dim level `5`.
- 2026-05-26 IDA MCP recheck reported 11 direct callers plus additional xrefs across dialog/menu/session paths. This remains a shared screen-overlay factory, not a caller-local helper or independent source module.
- IDA MCP recheck on 2026-06-05 confirmed `sub_4A12B0`, size `0xb0`, 11 dialog/menu/session callers, allocator `0x004f4aa0`, and `ScreenDimmer` constructor `0x00559b90`.

## Ownership Guidance

Move this helper with `ScreenDimmer` rather than leaving it as a standalone recovered global. It is a constructor wrapper for the generic dim overlay and not enough evidence by itself to own the compact-display globals it reads.

Keep the host globals provisional while normalizing the known mode/player-state globals:

- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / IDA `byte_66DA97`: compact/current asset mode flag used across multiple UI/render paths.
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / IDA `dword_67A748`: broad local-player/client-state pointer; this helper treats it as a compact-display root host candidate with a parent pane at `+0x214`.
- `dword_67A764`: active map pane/global UI host candidate.
- `dword_67A7CC`: back/root pane candidate used by several UI paths.

## Cross-References

- [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md)
- [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md)
- [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `82/88`.
  - Before: page documented the dimmer factory behavior, parent selection, allocation/constructor call, ownership guidance, and provisional globals but remained unevaluated.
  - After: score reflects documented factory semantics and strong evidence, with remaining completion limited by provisional host/global names.
  - Evidence: IDA notes confirm function range/size, `ScreenDimmer` allocation and constructor call, and broad dialog/menu/session callers.
- 2026-06-05: Marked reconstructable and attached to [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md).
  - Reason: live IDA MCP recheck confirms source-authored factory behavior centered on `ScreenDimmer` construction; broad callers support a shared helper under the `ScreenDimmer` source owner rather than caller-local copies.
- 2026-06-07 A008 alias cleanup:
  - Normalized `byte_66DA97` to [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) and `dword_67A748` to [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md), while keeping the IDA aliases and the unresolved host-pane globals visible.
