*** UID:0000PJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CreateScreenDimmer_4A12B0

## Status

- Confidence: strong from live IDA MCP and memory evidence.
- Symbol kind: free helper function.
- Address range: `0x004a12b0-0x004a1360`.
- Memory doc: [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md)
- Signature: recovered alias `ScreenDimmer* __cdecl CreateScreenDimmer_4A12B0(void)`; best source-facing spelling is `ScreenDimmer *CreateScreenDimmer(void)`.
- Likely owner: [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)

## Behavior

`CreateScreenDimmer_4A12B0` chooses the parent pane for a modal dimmer, allocates 252 bytes, and constructs a level-5 [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md).

Parent selection:

- If [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / IDA `byte_66DA97` is `1` and source-facing `g_pUserPane` / stable alias [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / IDA `dword_67A748` is non-null, use the active dialog host pane pointer at `g_pUserPane + 0x214` (`dword_67A748 + 0x214`), decimal `532` (Verified with int_convert.py).
- If [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / IDA `byte_66DA97` is `1` and `g_pUserPane` / `dword_67A748` is null, use [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) / IDA `dword_67A7CC`.
- Otherwise use [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) / IDA `dword_67A764`.

## Evidence

- Live IDA MCP `lookup_funcs` reports `0x004a12b0` as a real function of size `0xb0`, ending end-exclusive at `0x004a1360`.
- Live IDA MCP decompilation shows the helper allocates 252 bytes and calls the `ScreenDimmer` constructor at `0x00559b90` with dim level `5`.
- 2026-05-26 IDA MCP recheck reported 11 direct callers plus additional xrefs across dialog/menu/session paths. This remains a shared screen-overlay factory, not a caller-local helper or independent source module.
- IDA MCP recheck on 2026-06-05 confirmed `sub_4A12B0`, size `0xb0`, 11 dialog/menu/session callers, allocator `0x004f4aa0`, and `ScreenDimmer` constructor `0x00559b90`.
- 2026-06-14 live IDA MCP `analyze_function 0x004a12b0` reports `sub_4A12B0`, size `0xb0` / 176 decimal bytes (Verified with int_convert.py), 15 basic blocks, direct callees `sub_4F4AA0` and `sub_559B90`, 11 containing caller functions, and 19 code xrefs/call sites across board/article/mail/dialog/menu-flow ranges.
- The 2026-06-14 decompilation shows three equivalent allocation paths using `sub_4F4AA0(0xfc)`, decimal `252` (Verified with int_convert.py), followed by `sub_559B90(result, 5, parentPane)`. The parent operand is either `*(g_pUserPane + 0x214)` / raw `*(dword_67A748 + 0x214)`, [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), or [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md).
- The 2026-06-14 disassembly includes compiler EH cleanup funclets after the visible `0x004a12b0-0x004a1360` body; those cleanup stubs free the pending allocation through `sub_4F4AC0` and should be treated as constructor-failure/unwind support, not a separate application-level factory policy.

## Ownership Guidance

Move this helper with `ScreenDimmer` rather than leaving it as a standalone recovered global. It is a constructor wrapper for the generic dim overlay and not enough evidence by itself to own the compact-display globals it reads.

Keep the host globals provisional while normalizing the known mode/player-state globals:

- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / IDA `byte_66DA97`: compact/current asset mode flag used across multiple UI/render paths.
- Source-facing `g_pUserPane` / stable alias [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / IDA `dword_67A748`: broad local-player/UserPane state pointer; this helper treats the `+0x214` subobject/member as the active dialog host pane candidate, not as proof of ScreenDimmer ownership over the whole UserPane object.
- [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) / IDA `dword_67A7CC`: root screen pane singleton used as the fallback parent when the current asset path lacks a collection/player host.
- [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) / IDA `dword_67A764`: active map pane singleton used as the legacy/default parent.

## Score Rationale

- Completion is `87` because the page now records current MCP body metrics, caller/callee/call-site evidence, verified allocation size and host offset conversions, canonical parent globals, EH-cleanup interpretation, and ownership through `ScreenDimmer.cpp`.
- Confidence is `90` because live IDA MCP, the memory page, the `ScreenDimmer` file/class pages, and canonical global pages agree on the factory role and parent-selection state. Confidence remains below `95` because the final helper name, header exposure, and source-facing declaration spelling for the parent globals remain provisional.

## Cross-References

- [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md)
- [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md)
- [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md)
- [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `82/88`.
  - Before: page documented the dimmer factory behavior, parent selection, allocation/constructor call, ownership guidance, and provisional globals but remained unevaluated.
  - After: score reflects documented factory semantics and strong evidence, with remaining completion limited by provisional host/global names.
  - Evidence: IDA notes confirm function range/size, `ScreenDimmer` allocation and constructor call, and broad dialog/menu/session callers.
- 2026-06-05: Marked reconstructable and attached to [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md).
  - Reason: live IDA MCP recheck confirms source-authored factory behavior centered on `ScreenDimmer` construction; broad callers support a shared helper under the `ScreenDimmer` source owner rather than caller-local copies.
- 2026-06-07 A008 alias cleanup:
  - Normalized `byte_66DA97` to [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) and `dword_67A748` to [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md), while keeping the IDA aliases and the unresolved host-pane globals visible.
- 2026-06-14 A003 live MCP/global-alias refresh:
  - Before: score `82/88`; parent selection still carried raw provisional `dword_67A7CC` and `dword_67A764` labels.
  - After: score `87/90`; resolved those raw labels to canonical [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) and [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md), added current `analyze_function` metrics, verified key number conversions, and recorded the EH cleanup funclets as construction-failure support rather than separate source policy.
  - Evidence: live IDA MCP session `a001_goal2_class_batch` reported `sub_4A12B0` size `0xb0` / 176 decimal bytes (Verified with int_convert.py), 11 containing caller functions with 19 code xrefs, direct callees `sub_4F4AA0` and `sub_559B90`, allocation size `0xfc` / 252 decimal bytes (Verified with int_convert.py), and parent selection through `g_pUserPane + 0x214` / raw `dword_67A748 + 0x214`, `dword_67A7CC`, or `dword_67A764`.
- 2026-06-17 B002 source-quality audit:
  - Before/after score unchanged: `87/90`.
  - Summary/evidence: B002 validated `CreateScreenDimmer_4A12B0` as the recovered binary alias and recommends `ScreenDimmer *CreateScreenDimmer(void)` as the source-facing helper spelling. The report keeps the helper with [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md), rejects DialogSession/MapPane/caller-local ownership, and keeps final C++ blocked by exact header/source spelling and the active dialog host-pane field at `g_pUserPane + 0x214`.
- 2026-06-22 Rule 26 support sync from B001 [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md):
  - Updated the parent-selection wording from canonical `g_pCollectionData` storage to source-facing `g_pUserPane` with `g_pCollectionData` retained as the stable alias.
  - The `+0x214` operand is now documented as an active dialog host-pane view inside the broad UserPane/local-player object; ScreenDimmer remains only a consumer of that host pane.
