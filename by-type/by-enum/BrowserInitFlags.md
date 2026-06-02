*** UID:0001SK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserInitFlags

## Status

- Confidence: strong for the observed initialization value and owner function, medium for the final declaration form.
- Current source evidence: IDA MCP decompilation/disassembly of [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md); generated source names are lead material only.
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md), likely browser-private constants.
- Reconstructable: yes if this survives as a source-level state initializer, but do not emit C++ yet because the field meaning and declaration form are still open.
- Classification: provisional constant/bitmask candidate. Keep this page in `by-enum` only as a current inventory item; the evidence now leans toward a Browser object state word rather than a complete standalone enum.

## Values

| Value | Name hypothesis | Meaning |
| --- | --- | --- |
| `0x0101` / `257` | `kBrowserInitialStateWord` or `kBrowserDefaultStateFlags` | Initial 16-bit state/flag word written to the legacy `Browser` object during `BrowserControlPaneOld` construction. Name and declaration form remain provisional. |

## Evidence

- IDA MCP `lookup_funcs 0x0046ff50` reports the constructor as `sub_46FF50`, range `0x0046ff50-0x00470159`, size `0x209`.
- IDA MCP decompilation of [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) shows the embedded `Browser` object allocation/initialization path.
- Disassembly at `0x0047004d` is `mov word ptr [esi+22Ch], 101h`, equivalent to Browser object offset `+0x22c`.
- A local IDA scan of the browser/OLE cluster `0x0046f010-0x004710b7` found no other `+0x22c` access. This suggests the value is an initial state word, but it does not yet prove the original source declaration.
- The same object has nearby initialization of fields at `+0x228` and `+0x230`; `+0x228` is the copied URL pointer and `+0x230` is a constructed string/container member. This placement supports an internal Browser state-field interpretation.
- The old control-pane overlay path at `0x0046f232` reads Browser offset `+0x222`, and `BrowserThread::InitializeBrowserHost` sets `+0x222` at `0x00470d45`. That is a separate byte flag and should not be merged with this `+0x22c` word.
- The same numeric value overlaps Win32 `WM_KEYUP` in `BrowserControlPaneOld::HandleBrowserMessage` at `0x0046f310`, but that message-id use comes from the event packet switch and is unrelated to the Browser object initializer.

## Classification Decision

The current best classification is "source-level Browser initial state constant or bitmask value", not a final enum. Keep it reconstructable because the initializer likely existed in source, but do not emit a C++ enum or attach code until the Browser layout around `+0x220-+0x233` is recovered and the field name is known with higher confidence.

## Autogen Status

- Reconstructable: true, as a Browser-owned source-level initializer/constant candidate.
- Parent: [UID:0000HV][Browser](by-file/Browser.md).
- C++: intentionally blank; final declaration form and field name remain open.

## Score Rationale

Completion is raised for the parent attachment and clearer classification: the initializer value, exact write address, object offset, owner function, and non-overlap with the separate `+0x222` flag and `WM_KEYUP` message use are documented. Confidence stays at `80` because this may ultimately be a field initializer or bitmask constant rather than an enum declaration.

## Open Questions

- Decide whether this is really an enum, a bitmask, or a packed state word once the `Browser` object layout is recovered.
- Identify the field at browser-object offset `+0x22c`.
- If later layout work proves the value is just `0x0101` bit flags, move this page or reclassify it under bitfield/field documentation instead of keeping it as an enum.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md)
- [UID:000013][Browser](by-class/Browser.md)
- [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md)

## Changes

- What existed before: the page treated `257` primarily as `kBrowserDefaultActiveFlags` with medium confidence, and it only referenced the constructor decompile at a summary level.
- What it was changed to: the page now treats `0x0101` as a provisional Browser state-word/bitmask initializer, records the exact constructor memory page, separates it from Browser offset `+0x222` and Win32 `WM_KEYUP`, and keeps C++ emission deferred.
- Summary and evidence: IDA MCP decompilation/disassembly proves the `0x0047004d` write to Browser offset `+0x22c`; local IDA scanning found no other `+0x22c` access in the browser/OLE cluster, while `+0x222` is a separate browser-host flag used by overlay/initialization paths.
- 2026-06-02:
  - What existed before: the page was `68/80`, reconstructable, but had no parent attachment.
  - Changed to: completion `72` and `AUTOGEN_PARENT_UID:0000HV`.
  - Summary/evidence: the Browser source root is already validated at `NexusTK/browser/`, and this page's own evidence identifies the initializer as Browser-object state rather than a separate message-id enum.
