*** UID:0000U0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// This by-item page is a legacy alias for the canonical by-memory
// reconstruction [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md). Emitted source is covered there; no
// standalone duplicate body is emitted for [UID:0000U0].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BlendRgb565Pair_4C60D0 0x004C60D0

## Status

- Confidence: strong for behavior, boundaries, caller family, and SoftwareBlend16 ownership; medium-high for final original name.
- Entity kind: free render helper.
- Likely source module: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- Autogen parent: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- Exact range: `0x004c60d0-0x004c6151`

## Behavior

`BlendRgb565Pair_4C60D0` blends two packed RGB565 pixels at once. The inputs are 32-bit values containing two 16-bit RGB565 colors, and the helper applies the same 0..32 weighted blend math across both packed pixels.

The third argument is an unsigned 0..32 fixed-point blend weight for the first packed input. The helper uses `(32 - weight)` for the second packed input, masks packed green and red/blue lanes separately, multiplies the lanes by their weights, shifts the products back down by five, and recombines the two 16-bit RGB565 results into one 32-bit return value.

2026-06-30 B013 implementation resolves this by-item empty marker as a duplicate alias only. The address `0x004c60d0` is the same body as canonical [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md), which now owns the formal `BlendRgb565Pair` C++ implementation; this item emits only a covered-by comment.

## Evidence

- Live IDA MCP `lookup_funcs 0x004c60d0` reports `sub_4C60D0` size `0x81`.
- Live IDA MCP reports four callers in `0x004c0850`, `0x004c0f80`, and `0x004c4380` render neighborhoods.
- It is adjacent to `BlendRgb565Pixel`, supporting a shared original helper file.
- Live IDA MCP on 2026-06-14, session `a001_goal2_class_batch`, reconfirmed `sub_4C60D0` as a one-basic-block `unsigned int __cdecl(unsigned int, unsigned int, unsigned __int8)` helper with no callees and code callers `sub_4C0850`, `sub_4C0F80`, and `sub_4C4380`.
- The 2026-06-14 decompile is a single packed arithmetic expression over masks `0x7C0F83F`, `0x7E0F81F`, and `0xFFC0F83F`, weighted by `weight` and `(32 - weight)`. This matches the detailed [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md) formula and no-global/no-callee profile.
- Generated item coverage on 2026-06-14 shows the current `EMITTER_UIDS:0000NT` route reaches `auto-generated/NexusTK/render/SoftwareBlend16.cpp` with no dead end.

## Score Rationale

| Metric | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | Exact range, pure helper signature, packed RGB565 formula, mask constants, caller family, no-callee profile, adjacent pixel helper relationship, by-memory support page, and SoftwareBlend16 owner/emitter route are documented. Still below final-code level because original helper spelling and final typedef/header placement are not proven. |
| Confidence | 90 | Live IDA reconfirms the one-block arithmetic body, no callees, RGB565 callback callers, and generated route to `SoftwareBlend16.cpp`; confidence is capped below final audit because source-level name/typedefs remain reconstructed. |

## Cross-References

- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md)
- [UID:0000U1][BlendRgb565Pixel_004C6050](by-item/BlendRgb565Pixel_004C6050.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- 2026-06-14 A003 Goal 2 low-confidence item refresh:
  - Raised completion/confidence from `80/84` to `88/90`.
  - Evidence: live IDA MCP reconfirmed `sub_4C60D0` size `0x81`, one basic block, no callees, callers in `sub_4C0850`, `sub_4C0F80`, and `sub_4C4380`, and the packed RGB565 weighted formula over masks `0x7C0F83F`, `0x7E0F81F`, and `0xFFC0F83F`.
  - Routing: owner/emitter remains [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md); generated item coverage resolves it to `auto-generated/NexusTK/render/SoftwareBlend16.cpp` with no dead end.
  - This by-item page emits a covered-by comment because the stronger exact code-bearing home is [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md), which now owns the formal C++ body; final typedef/source spelling remains a confidence cap only.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md), and stale generated-source evidence wording was replaced with live IDA evidence.
  - Before: the item was unclassified and the evidence section still cited generated import metadata.
  - After: it is marked as a NexusTK-owned packed RGB565 render helper under the validated SoftwareBlend16 file root; 2026-06-30 B013 supersedes the old 95/95 final-code blocker by moving formal C++ to canonical [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md) and leaving this by-item page as a covered-by alias.
  - Evidence: live IDA MCP confirms `sub_4C60D0` at `0x004c60d0`, size `0x81`, with direct callers in `sub_4C0850`, `sub_4C0F80`, and `sub_4C4380`; the helper has no project callees.

- 2026-05-30: Grading changed from `0/0` to `80/84`.
  - Before: page documented packed RGB565 pair blending behavior, ownership, callers, and adjacent pixel helper but remained unevaluated.
  - After: score reflects documented behavior and source placement, with remaining confidence limited by final original helper name.
  - Evidence: IDA caller notes tie the helper to software render neighborhoods and adjacency to [UID:0000U1][BlendRgb565Pixel_004C6050](by-item/BlendRgb565Pixel_004C6050.md) supports shared [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md) ownership.
