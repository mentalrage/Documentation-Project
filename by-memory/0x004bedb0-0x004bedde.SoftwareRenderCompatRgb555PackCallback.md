*** UID:0002YH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x004bedb0-0x004bedde SoftwareRenderCompatRgb555PackCallback

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: RGB555 color conversion callback.
- Callback slot: `dword_69B404`.
- Containing family: [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md).

## Range And Behavior

| Range | IDA function | Behavior |
| --- | --- | --- |
| `0x004bedb0-0x004bedde` | `sub_4BEDB0`, size `0x2e` | Packs three 8-bit RGB channels into one RGB555 word by shifting each channel right by three and arranging the 5-bit lanes. |

The parent decompile summary records the packed expression as `(blue >> 3) | (((green >> 3) | ((red >> 3) << 5)) << 5)`. The following `0x004bedde-0x004bede0` interval is two bytes of `0xcc` alignment.

## Evidence

- 2026-06-06 IDA MCP decompilation/disassembly resolved this as a no-callee leaf helper.
- No ordinary direct callers were reported.
- Data refs are recorded at `0x00558705` and `0x00558be4`, matching raw initializer-neighborhood and SurfacePresentation callback-table setup.

## Assignment Decision

Assigned to [UID:0000OC][Surface](by-file/Surface.md). The child clears `86/90`, and Surface clears `88/85` as the direct parent for callback-table dispatch. IDA evidence shows callback slot `dword_69B404`, no ordinary direct callers, no callees, and target refs at `0x00558705` plus the Surface initializer reference at `0x00558be4`. [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md) is rejected as direct parent because this exact address is installed as a Surface callback-table target rather than reached as an ordinary stateless blend helper.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | Exact range, callback slot, no-callee leaf status, no direct callers, initializer refs, RGB555 packing formula, alignment boundary, and Surface ownership are documented. |
| Confidence `90` | IDA MCP confirms the function size, no-callee status, target refs, and formula; remaining uncertainty is limited to final source naming. |

## Cross-References

- [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md)

## Changes

- 2026-06-07 A010 Batch049: Created exact split child for the RGB555 pack callback and recorded formula, xrefs, boundary, and no-callee evidence from the existing parent audit.
- 2026-06-10 B001-029 final gate repair:
  - Changed to: `AUTOGEN_PARENT_UID:0000OC`.
  - Evidence: rechecked callback slot `dword_69B404`, target refs `0x00558705`/`0x00558be4`, no direct callers/callees, and the Surface-vs-SoftwareBlend16 parent scope. The slot ABI makes this a Surface callback-table child.
