*** UID:0000CJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrolledTextControlPaneForMadeBy

## Status

- Confidence: strong.
- Likely source file: [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)
- Main address ranges: `0x004ff400-0x004ff7cc` and `0x0050257c-0x00502cbd`
- Current recovered file: `source-3/simroot_v2/class_ScrolledTextControlPaneForMadeBy.cpp`

## Class Purpose

`ScrolledTextControlPaneForMadeBy` is the credits/attribution variant of [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md). It uses the same DAT-text-to-rendered-image pipeline but scrolls by two pixels and closes [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md) when the content reaches the end.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x004ff400-0x004ff643` | constructor | Load resource text, render through temporary `TextEditPane`, initialize image region and timer state. |
| `0x004ff650-0x004ff6bb` | destructor | Destroy image region and embedded render state. |
| `0x004ff6c0-0x004ff724` | `OnTimerEvent` | Increment scroll by two, close `g_pNewHistoryDialog` on end, invalidate, and notify parent. |
| `0x004ff730-0x004ff7cc` | `OnPaintFrame` | Fill background and blit rendered credits text with scroll offset. |
| `0x0050257c-0x00502586` | deleting-destructor thunk | This-adjust thunk into scalar deleting destructor. |
| `0x00502c10-0x00502cbd` | scalar deleting destructor | Deleting-destructor wrapper. IDA confirms `0x00502cbc` is the final `retn 4` immediate byte. |

## Evidence Notes

- Constructor summary identifies it as an auto-scrolling credits text control.
- IDA MCP reports one direct constructor caller at `0x0050052e`.
- 2026-05-28 IDA MCP reports `sub_502C10` as `0x00502c10-0x00502cbd`; raw bytes at `0x00502cbc-0x00502cc0` are `00 cc cc cc`, so only `0x00502cbd-0x00502cc0` is padding.
- The timer path calls close-dialog behavior through `g_pNewHistoryDialog` when the scroll reaches the end.

## Cross-References

- [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)
- [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md)
- [UID:00019X][0x004ff400-0x00502cbd.ScrolledTextControlPaneForMadeBy](by-memory/0x004ff400-0x00502cbd.ScrolledTextControlPaneForMadeBy.md)
- [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md)
- [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence were `0/0` even though the page documented the credits variant role, constructor/destructor/timer/paint families, one caller, close-on-end behavior, and corrected destructor endpoint.
  - After: changed completion/confidence to `82/86`.
  - Evidence: existing method-family table, IDA caller and endpoint evidence, `g_pNewHistoryDialog` behavior, and related text-control cross-references support high-confidence documentation.

- Before: this class page listed the destructor range and main address range ending at `0x00502cbc`.
- After: the ranges now end at `0x00502cbd`.
- Why: IDA MCP shows the byte at `0x00502cbc` belongs to the scalar deleting destructor as the immediate operand of `retn 4`.
- Evidence: 2026-05-28 IDA MCP function-boundary and raw-byte check for `0x00502c10` and `0x00502cbc-0x00502cc0`.
