*** UID:0002YH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:101 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static unsigned short PackRgb555Pixel(unsigned char high,
                                      unsigned char middle,
                                      unsigned char low)
{
    return static_cast<unsigned short>(((high >> 3) << 10) |
                                       ((middle >> 3) << 5) |
                                       (low >> 3));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Surface-owned compat `dword_69B404` no-callee byte-to-RGB555 lane pack callback with initializer refs `0x00558705`/`0x00558be4`, formal `PackRgb555Pixel` C++ using inferred high/middle/low lane names, and SoftwareBlend16 retained only as related math context. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# 0x004bedb0-0x004bedde SoftwareRenderCompatRgb555PackCallback

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: RGB555 color conversion callback.
- Callback slot: `dword_69B404`.
- Containing family: [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md).

## Range And Behavior

| Range | IDA function | Behavior |
| --- | --- | --- |
| `0x004bedb0-0x004bedde` | `sub_4BEDB0`, size `0x2e` / 46 bytes (Verified with int_convert.py) | Packs three 8-bit RGB channels into one RGB555 word by shifting each channel right by three and arranging the 5-bit lanes. |

Live IDA decompilation on 2026-06-11 resolves the current signature as `__int16 __cdecl sub_4BEDB0(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3)`. The packed expression is `(a3 >> 3) | (32 * ((a2 >> 3) | (32 * (a1 >> 3))))`, matching RGB555 lane packing from three 8-bit channel inputs. The following `0x004bedde-0x004bede0` interval is two bytes of `0xcc` alignment (2 verified with int_convert.py).

## Evidence

- 2026-06-06 IDA MCP decompilation/disassembly resolved this as a no-callee leaf helper.
- No ordinary direct callers were reported.
- Data refs are recorded at `0x00558705` and `0x00558be4`, matching raw initializer-neighborhood and SurfacePresentation callback-table setup.
- 2026-06-11 A005 Batch 177 live IDA MCP `py_eval` reconfirmed `sub_4BEDB0` as `0x004bedb0-0x004bedde`, size `0x2e` / 46 bytes (Verified with int_convert.py), one basic block, no code callers, no external code targets, and target-address refs only at `0x00558705` and `0x00558be4`.
- The same live pass rechecked slot `dword_69B404`: IDA reports nine direct slot refs, including Surface initializer writes at `0x00558be4` and `0x00558f00`, plus non-target dispatch/use refs in the broader render path. This supports slot ABI ownership without turning the helper into an ordinary stateless caller-owned function.

## Assignment Decision

Assigned to [UID:0000OC][Surface](by-file/Surface.md). The child clears `90/92`, and Surface clears `88/85` as the direct parent for callback-table dispatch. IDA evidence shows callback slot `dword_69B404`, no ordinary direct callers, no callees, and target refs at `0x00558705` plus the Surface initializer reference at `0x00558be4`. [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md) is rejected as direct parent because this exact address is installed as a Surface callback-table target rather than reached as an ordinary stateless blend helper.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `90` | Exact range, byte-size conversion, callback slot, no-callee leaf status, one-block shape, no direct callers, initializer refs, RGB555 packing formula, formal `PackRgb555Pixel` C++ block, lane-name rationale, alignment boundary, and Surface ownership are documented. |
| Confidence `92` | Current live IDA MCP confirms the function size, one-block/no-callee status, target refs, slot refs, formula, and source-ready wrapper shape; remaining uncertainty is limited to exact original public/source naming. |

## Cross-References

- [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md)

## Changes

- 2026-06-29 B005 Surface empty-emitter first-batch implementation:
  - Changed to: score is `90/92`, `EMITTER_POSITION_OPTIONAL:101`, item summary now records Surface-owned source-ready status, and formal C++ emits `PackRgb555Pixel`.
  - Evidence: B005 MCP recheck in `supervisor_resume_20260629` preserves the one-block/no-callee/no-ordinary-caller formula, initializer refs `0x00558705`/`0x00558be4`, and slot `dword_69B404`; the formal expression packs the three 8-bit lanes into RGB555 exactly as the documented shift expression.
  - Source-shape rationale: `PackRgb555Pixel` is an inferred descriptive static helper name. The parameter names use `high`, `middle`, and `low` lane order to match the source-facing packing expression without asserting unrecovered original RGB channel spelling. SoftwareBlend16 remains related pixel-math context, not direct owner.
- 2026-06-07 A010 Batch049: Created exact split child for the RGB555 pack callback and recorded formula, xrefs, boundary, and no-callee evidence from the existing parent audit.
- 2026-06-10 B001-029 final gate repair:
  - Changed to: `AUTOGEN_PARENT_UID:0000OC`.
  - Evidence: rechecked callback slot `dword_69B404`, target refs `0x00558705`/`0x00558be4`, no direct callers/callees, and the Surface-vs-SoftwareBlend16 parent scope. The slot ABI makes this a Surface callback-table child.
- 2026-06-11 A005 Batch 177 evidence refresh:
  - Changed completion/confidence from `86/90` to `88/91`.
  - Evidence: live IDA MCP reconfirmed the exact `0x2e` / 46-byte size (Verified with int_convert.py), one-block no-callee shape, target refs, slot refs, decompiled RGB555 packing expression, and two-byte `0xcc` post-body alignment.
