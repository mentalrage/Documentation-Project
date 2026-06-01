*** UID:0000PJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CreateScreenDimmer_4A12B0

## Status

- Confidence: strong from live IDA MCP, generated recovered source, and metadata.
- Symbol kind: free helper function.
- Address range: `0x004a12b0-0x004a1360`.
- Memory doc: [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md)
- Signature: `ScreenDimmer* __cdecl CreateScreenDimmer_4A12B0(void)`.
- Likely owner: [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- Current generated source: `source-3/simroot_v2/recovered/CreateScreenDimmer_004A12B0.cpp`

## Behavior

`CreateScreenDimmer_4A12B0` chooses the parent pane for a modal dimmer, allocates 252 bytes, and constructs a level-5 [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md).

Parent selection:

- If `byte_66DA97 == 1` and `dword_67A748` is non-null, use the host pane pointer at `dword_67A748 + 0x214`.
- If `byte_66DA97 == 1` and `dword_67A748` is null, use `dword_67A7CC`.
- Otherwise use `dword_67A764`, currently typed as `MapPane*` in generated output and also used as the active map pane global elsewhere.

## Evidence

- `CreateScreenDimmer_004A12B0.meta_wave3` says the helper was restored from the missing-reference backlog and records the range `0x004a12b0-0x004a1360`.
- Live IDA MCP `lookup_funcs` reports `0x004a12b0` as a real function of size `0xb0`, ending end-exclusive at `0x004a1360`.
- Live IDA MCP decompilation shows the helper allocates 252 bytes and calls the `ScreenDimmer` constructor at `0x00559b90` with dim level `5`.
- Active `simroot_v2/recovered/CreateScreenDimmer_004A12B0.cpp` matches the live IDA behavior.
- The generated file has normalized include comments moved to the file include section; this looks clean in the current output.
- 2026-05-26 recheck: active `simroot_v2` still emits this as standalone recovered source, while IDA MCP still reports 11 direct callers plus additional xrefs across dialog/menu/session paths. This remains a shared screen-overlay factory, not a caller-local helper or independent source module.

## Ownership Guidance

Move this helper with `ScreenDimmer` rather than leaving it as a standalone recovered global. It is a constructor wrapper for the generic dim overlay and not enough evidence by itself to own the compact-display globals it reads.

Keep the raw globals provisional:

- `byte_66DA97`: compact/current asset mode flag used across multiple UI/render paths.
- `dword_67A748`: compact-display root host candidate with a parent pane at `+0x214`.
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
  - Evidence: IDA notes confirm function range/size, `ScreenDimmer` allocation and constructor call, active generated source match, and broad dialog/menu/session callers.
