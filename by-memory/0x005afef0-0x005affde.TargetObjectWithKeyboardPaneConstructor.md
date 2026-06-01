*** UID:0001LI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x005afef0-0x005affde - TargetObjectWithKeyboardPane Constructor

## Status

- Confidence: strong for IDA function boundary and ownership.
- Related class: [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md)
- Related file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- IDA function: `sub_5AFEF0`, size `0xee`

## Covered Range

| Range | Owner | Role |
| --- | --- | --- |
| `0x005afef0-0x005affde` | `TargetObjectWithKeyboardPane::TargetObjectWithKeyboardPane` | Constructs the line-input base, stores singleton `dword_69BF64`, installs vtables, initializes selected target id `dword_69BF2C`, highlights the selected object, and attaches to the capture pane. |

## Cross-References

- [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md)
- [UID:0001LJ][0x005affe0-0x005b0009.TargetObjectWithKeyboardPaneDestructor](by-memory/0x005affe0-0x005b0009.TargetObjectWithKeyboardPaneDestructor.md)
- [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md)
