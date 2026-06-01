*** UID:0000S9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pSimpleHelpPane

## Status

- Address: [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md)
- Symbol kind: process-wide singleton pointer.
- Likely owner file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- Current generated names: `g_pSimpleHelpPane`, `dword_69AE00`
- Confidence: strong.

## Purpose

`g_pSimpleHelpPane` points to the active [UID:0000D6][SimpleHelpPane](by-class/SimpleHelpPane.md), the older timed text tooltip popup. The constructor writes it, teardown clears it, and feature callers use it to avoid overlapping simple help popups.

## Evidence Notes

- 2026-05-30 live IDA MCP storage check reports `0x0069ae00` as a 4-byte `.data` item named `dword_69AE00` with 23 data references.
- [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) contains the core lifetime sites: constructor-like code at `0x004c6ff1` writes the active pointer, the same path clears it on null fallback at `0x004c6ff8`, and teardown/helper paths clear it at `0x004c72e8`, `0x004ce330`, and `0x004ce5bf`.
- [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md) includes a singleton close helper at `0x004a0d60` that reads this pointer and closes the active pane when present.
- Feature/UI callers read the pointer before opening or updating simple help popups, including `0x0049e5bd`, `0x004cef6c`, `0x004ead71`, `0x004eafca`, `0x004edad1`, `0x004edf2a`, `0x004ef368`, `0x004ef5b1`, `0x004fc7cc`, `0x00568d2e`, `0x00568d41`, `0x00568e03`, `0x00569892`, `0x00571d25`, `0x005a15e5`, `0x005b8a4b`, and `0x005bdff4`.
- The live xref set supports `g_pSimpleHelpPane` as the canonical singleton pointer; no separate storage was observed for the generated name variants.

## Cross-References

- [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md)
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:0000D6][SimpleHelpPane](by-class/SimpleHelpPane.md)
- [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md)
- [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md)
- [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md)

## Changes

- What existed before: the page had correct address and role notes but still had unevaluated completion/confidence metadata and one generated-output evidence bullet.
- What changed to: the page now uses the live IDA MCP xref set for storage shape, lifetime writes, close-helper reads, and feature callers. Completion/confidence were set to `78/88`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `0x0069ae00` / `dword_69AE00` as a 4-byte `.data` singleton pointer with 23 xrefs, constructor assignment at `0x004c6ff1`, fallback clear at `0x004c6ff8`, destructor/cleanup clears at `0x004c72e8`, `0x004ce330`, and `0x004ce5bf`, and close-helper read at `0x004a0d60`.
