*** UID:0001UN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00005C | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FontStyleLayout

## Status

- Confidence: strong for object size, vector triplet, rule-record stride, constructor defaults, cleanup behavior, and direct caller fan-out; medium-high for final semantic names of scalar style fields.
- Owner: [UID:00005C][FontStyle](by-class/FontStyle.md)
- Source candidate: [UID:0000JI][FontStyle](by-file/FontStyle.md)
- Evidence: live IDA MCP decompilation/caller checks of `0x00499f10`, `0x00499f60`, `0x00499f90`, `0x004536e0`, `0x0049ac60`, and consumer setup at `0x004c6960`.
- Reconstructable: true as a source-level class-layout declaration; C++ body remains blank because final scalar field names and text-rendering consumers still need a broader audit.

## Object Layout

Recovered `FontStyle` size: 0x20 bytes.

| Offset | Size | Field | Notes |
| --- | --- | --- | --- |
| `+0x00` | 1 | `enabled` | Constructor sets `1`; `HelpPane` treats zero as "no style". |
| `+0x01` | 3 | padding | Not currently named. |
| `+0x04` | 4 | `innerOpacityOrValue` | Constructor sets `0.2f`; `HelpPane`/text-pane style propagation consumes it as one opacity or style scalar. Final semantic name remains open. |
| `+0x08` | 4 | `outerOpacityOrValue` | Constructor sets `0.2f`; `HelpPane`/text-pane style propagation consumes it as the paired opacity or style scalar. Final semantic name remains open. |
| `+0x0c` | 4 | `styleValue0` | Constructor sets `1`; `HelpPane` copies it into foreground/style state. |
| `+0x10` | 4 | `styleValue1` | Constructor sets `0x80`; `HelpPane` copies it into background/font-size style state. |
| `+0x14` | 4 | `rulesBegin` | Begin pointer for 16-byte rule records. |
| `+0x18` | 4 | `rulesEnd` | Current end pointer. |
| `+0x1c` | 4 | `rulesCapacity` | Allocation end pointer. |

## Rule Layout

Recovered rule size: 0x10 bytes.

| Offset | Size | Field | Notes |
| --- | --- | --- | --- |
| `+0x00` | 4 | `firstValue` | First `Configure` argument. |
| `+0x04` | 4 | `secondValue` | Second `Configure` argument. |
| `+0x08` | 1 | `selectorLowByte` | Third `Configure` argument; IDA only proves the low byte is explicitly written. |
| `+0x09` | 3 | `selectorPadding` | Current reconstruction should treat only the low byte as proven until rendering consumers are checked. |
| `+0x0c` | 4 | `fourthValue` | Fourth `Configure` argument. |

## Notes

- The vector entry is provisionally named `FontStyleRule`; the three pointer fields match the usual `std::vector<FontStyleRule>` storage pattern.
- Live IDA decompilation of `FontStyle::FontStyle` at `0x00499f10` writes `this[5]`, `this[6]`, and `this[7]` to zero, then writes the enabled byte, two `0.2f` values, scalar `1`, and scalar `128`. This proves the vector triplet begins at `+0x14` and the scalar header occupies the first 20 bytes.
- Live IDA decompilation of the bounded rule lookup at `0x00499f60` computes `(rulesEnd - rulesBegin) >> 4` and copies one `_OWORD` from `rulesBegin + 16 * index` when the index is in range. This proves the rule stride and copy width.
- Live IDA decompilation of `FontStyle::Configure` at `0x00499f90` builds a 16-byte stack rule from arguments `a2`, `a3`, low byte `a4`, and `a5`, then appends it at `this + 0x14`; this proves the low-byte selector caveat.
- `ClearRules` at `0x004536e0` reads and clears the same `+0x14/+0x18/+0x1c` triplet and uses the large-allocation validation pattern seen in MSVC vector destructors before calling the shared free helper.
- [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md) grows a vector of 16-byte entries and is currently called only from `FontStyle::Configure` in live IDA caller output. Treat it as compiler/template support, not an extra source-facing method.
- More semantic field names should wait until `StaticTextControlPane2`, `HelpPane`, and text rendering consumers are typed together.

## Caller Evidence

- Live IDA caller checks on 2026-06-06 show `FontStyle::FontStyle` called from UI/text setup functions at `0x00450e3e`, `0x00451f32`, `0x00452408`, `0x00452887`, `0x00452ad2`, `0x0047d0d2`, and `0x004c69d2`.
- `FontStyle::Configure` is called from the same UI/static-label families at `0x00450f22`, `0x00451f74`, `0x00451f8d`, `0x004528be`, `0x00452b09`, `0x00452c2b`, and `0x0047d3fa`.
- The bounded rule lookup at `0x00499f60` is used by [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md)'s draw path at `0x004c6723` and `0x004c67b3`.
- Cleanup at `0x004536e0` is called from `0x0045214a` and `0x00452be3`, matching local/unwind cleanup of configured style records rather than independent product behavior.

## Cross-References

- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:0000JI][FontStyle](by-file/FontStyle.md)
- [UID:0000XM][0x004536e0-0x00453732.FontStyleClearRules](by-memory/0x004536e0-0x00453732.FontStyleClearRules.md)
- [UID:00011T][0x00499f10-0x00499fda.FontStyleCore](by-memory/0x00499f10-0x00499fda.FontStyleCore.md)
- [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md)

## Changes

- 2026-05-30: Scored the layout page from 0/0 to 76/84 after rechecking the cleanup method and confirming the vector triplet offsets. Evidence: IDA MCP decompilation of `0x004536e0` reads/writes `this[5]`, `this[6]`, and `this[7]` as `+0x14/+0x18/+0x1c`; existing constructor/configure docs support the remaining scalar and 16-byte rule layout.
- 2026-06-04: Marked `RECONSTRUCTABLE:TRUE` without changing scores.
  - Reasoning: IDA-backed constructor, configure, cleanup, and vector-growth evidence proves a real source-level `FontStyle` layout and rule-record declaration; parent attachment and C++ emission stay blank because final field semantics remain below the 95/95 bar.
- 2026-06-06: Raised completion/confidence from `76/84` to `82/88` and attached the layout to [UID:00005C][FontStyle](by-class/FontStyle.md).
  - Reasoning: live IDA now records the constructor defaults, bounded rule lookup, rule append stack layout, cleanup triplet reset, vector-growth slow path, and caller fan-out directly on this page. The parent class and this layout now both meet the 80/80 attachment gate.
  - Summary and evidence: `0x00499f10` initializes the 0x20-byte object, `0x00499f60` copies one 16-byte rule by index, `0x00499f90` appends a 16-byte stack rule through the `+0x14` vector triplet, `0x004536e0` clears the same triplet, and `0x0049ac60` is the only observed vector-growth slow path. Final field names and C++ declaration emission remain below the final reconstruction gate.
