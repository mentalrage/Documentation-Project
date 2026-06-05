*** UID:0001UN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FontStyleLayout

## Status

- Confidence: strong for object size and vector triplet; medium for semantic names of scalar style fields.
- Owner: [UID:00005C][FontStyle](by-class/FontStyle.md)
- Source candidate: [UID:0000JI][FontStyle](by-file/FontStyle.md)
- Evidence: IDA MCP decompilation of `0x00499f10`, `0x00499f90`, and `0x004c6960`.
- Reconstructable: true as a source-level class-layout declaration; C++ body remains blank because final scalar field names and text-rendering consumers still need a broader audit.

## Object Layout

Recovered `FontStyle` size: 0x20 bytes.

| Offset | Size | Field | Notes |
| --- | --- | --- | --- |
| `+0x00` | 1 | `enabled` | Constructor sets `1`; `HelpPane` treats zero as "no style". |
| `+0x01` | 3 | padding | Not currently named. |
| `+0x04` | 4 | `outerOpacityOrValue` | Constructor sets `0.2f`; `HelpPane` uses it for outer opacity handling. |
| `+0x08` | 4 | `innerOpacityOrValue` | Constructor sets `0.2f`; `HelpPane` uses it for inner text-pane opacity handling. |
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
- `ClearRules` uses the same large-allocation validation pattern seen in MSVC vector destructors before calling the shared free helper.
- [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md) grows a vector of 16-byte entries and is currently called only from `FontStyle::Configure` in IDA caller output. Treat it as compiler/template support, not an extra source-facing method.
- More semantic field names should wait until `StaticTextControlPane2`, `HelpPane`, and text rendering consumers are typed together.

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
