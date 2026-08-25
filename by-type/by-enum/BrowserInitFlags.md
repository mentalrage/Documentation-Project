*** UID:0001SK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BrowserInitFlags

## Status

- Confidence: strong for the observed initialization value, owner function, and Browser object placement; medium for the final declaration form.
- Current evidence: live IDA MCP function lookup and disassembly of [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md), plus scoped Browser/OLE-cluster scans for the `+0x22c` field and `0x0101` immediate.
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md), likely browser-private constants.
- Reconstructable: yes if this survives as a source-level state initializer, but do not emit C++ yet because the field meaning and declaration form are still open.
- Classification: provisional constant/bitmask candidate. Keep this page in `by-enum` only as a current inventory item; the evidence now leans toward a Browser object state word rather than a complete standalone enum.

## Values

| Value | Name hypothesis | Meaning |
| --- | --- | --- |
| `0x0101` / `257` | `kBrowserInitialStateWord` or `kBrowserDefaultStateFlags` | Initial 16-bit state/flag word written to the legacy `Browser` object during `BrowserControlPaneOld` construction. Name and declaration form remain provisional. |

## Evidence

- 2026-06-05 live IDA MCP `lookup_funcs 0x0046ff50` reports the constructor as `sub_46FF50`, range `0x0046ff50-0x00470159`, size `0x209`.
- 2026-06-05 live constructor-window disassembly shows the embedded Browser subobject begins at `esi+0x10`: `0x00470024` installs the Browser vtable at `[esi+10h]`, `0x0047002b` and `0x00470032` clear `[esi+14h]` and `[esi+18h]`, `0x00470039` takes `[esi+230h]` for member construction, `0x00470043` clears `[esi+228h]`, and `0x0047004d` writes `mov word ptr [esi+22Ch], 101h`.
- A scoped live IDA scan of the Browser/OLE cluster `0x0046f010-0x004710b8` found only one `0x0101` immediate: the `0x0047004d` constructor write to `[esi+22Ch]`.
- The same scoped scan found nearby Browser-state references at `+0x222`, `+0x224`, `+0x228`, and `+0x230`: `0x0046f232` reads `+0x222`, `0x00470d45` sets `+0x222`, `0x00470d4f` sets `+0x224`, several paths use `+0x228` as a pointer/string argument, and `+0x230` is constructed/destructed as a member object. This separates the `+0x22c` word from the adjacent byte flag and pointer/string members.
- A broad text scan for `22Ch` across the executable produced 37 hits, including unrelated stack-frame offsets, other object layouts, immediates such as `push 22Ch`, and the Browser constructor write. Those broad hits are not evidence of the same Browser field and are why this page remains below final confidence.
- The same numeric value overlaps Win32 message handling in `sub_46F310`: the dispatch window around `0x0046f310` uses switch cases including `256`, `257`, `260`, and `261` from the event packet. That message-id use is separate from the Browser object initializer.
- 2026-06-14 live IDA MCP `analyze_function 0x0046ff50` reconfirmed `sub_46FF50` as size `0x209`, caller `sub_469290`. The decompile allocates the legacy Browser object with `operator new(0x234)`, installs five Browser vtable slices at offsets `+0x00` through `+0x10`, clears the nearby Browser members at `+0x14`, `+0x18`, and `+0x228`, writes `*((_WORD *)v4 + 278) = 257` at offset `+0x22c`, constructs the member at `+0x230`, and stores the Browser pointer into the old control pane at `this[68]`.
- 2026-06-16 live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed the current function object as `sub_46FF50`, size `0x209`, with one caller from `sub_469290` at `0x0046936e`.
- 2026-06-16 disassembly of the constructor window `0x00470009-0x00470056` shows the five Browser vtable stores at `[esi]`, `[esi+4]`, `[esi+8]`, `[esi+0xc]`, and `[esi+0x10]`, clears at `[esi+0x14]`, `[esi+0x18]`, and `[esi+0x228]`, takes the `+0x230` member address before `sub_582B20`, and writes `mov word ptr [esi+22Ch], 101h` at `0x0047004d`.
- 2026-06-16 `type_query`/`search_structs` for `Browser` and `BrowserInit` found no local IDA UDT or enum declaration. That keeps this as a source-level constant/bitmask candidate, not a proven recovered enum.

## Classification Decision

The current best classification is "source-level Browser initial state constant or bitmask value", not a final enum. Keep it reconstructable because the initializer likely existed in source, but do not emit a C++ enum or attach code until the Browser layout around `+0x220-+0x233` is recovered and the field name is known with higher confidence.

The 2026-06-20 Browser class layout pass names the `+0x22c` field `m_stateFlags` for documentation and first-draft declaration purposes. Keep `0x0101` as a state/initialization flag word written to `Browser::m_stateFlags`; do not promote it to a final enum or split it into named bits until bit-level evidence exists.

## Autogen Status

- Reconstructable: true, as a Browser-owned source-level initializer/constant candidate.
- Parent: [UID:0000HV][Browser](by-file/Browser.md).
- C++: intentionally blank; final declaration form and field name remain open.

## Score Rationale

Completion is `86` because live IDA now documents the constructor-window context, Browser object allocation size, vtable/subobject placement, exact `+0x22c` write, scoped cluster-only `0x0101` hit, adjacent `+0x222/+0x224/+0x228/+0x230` field separation, Browser source ownership, and the current absence of IDA local type evidence for a Browser enum/UDT. Confidence is `88` because the evidence is strong for a Browser-owned state initializer, but remains below final because the original field name and declaration form are still unknown and this may be a bitmask/state word rather than a real enum.

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

- 2026-06-16 A002 Goal 2 source-quality refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:87`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP reconfirmed `sub_46FF50` size `0x209`, caller `sub_469290`, the exact constructor disassembly that installs five Browser vtables, clears adjacent members, writes `0x0101` at Browser offset `+0x22c`, and constructs the member at `+0x230`. `type_query`/`search_structs` found no Browser-specific local enum/UDT, so the enum-vs-bitmask blocker remains real and C++ stays blank.
- 2026-06-20 B007 Browser class sync:
  - Added `m_stateFlags` as the source-facing documentation name for Browser offset `+0x22c`, while preserving the current classification as a state/initialization flag word rather than a proven enum.
- 2026-06-14 A002 Goal 2 score refresh:
  - What existed before: `82/84`, with strong constructor evidence but not enough current allocation/subobject detail for the strict score target.
  - Changed to: `85/87`.
  - Summary/evidence: live IDA MCP reconfirmed `sub_46FF50` size `0x209`, Browser object allocation `0x234`, five Browser vtable stores, nearby member clears at `+0x14/+0x18/+0x228`, the `257` write to `+0x22c`, member construction at `+0x230`, and caller `sub_469290`. C++ remains blank because the final declaration may be a bitmask or state-word constant rather than an enum.
- What existed before: the page treated `257` primarily as `kBrowserDefaultActiveFlags` with medium confidence, and it only referenced the constructor decompile at a summary level.
- What it was changed to: the page now treats `0x0101` as a provisional Browser state-word/bitmask initializer, records the exact constructor memory page, separates it from Browser offset `+0x222` and Win32 `WM_KEYUP`, and keeps C++ emission deferred.
- Summary and evidence: IDA MCP decompilation/disassembly proves the `0x0047004d` write to Browser offset `+0x22c`; local IDA scanning found no other `+0x22c` access in the browser/OLE cluster, while `+0x222` is a separate browser-host flag used by overlay/initialization paths.
- 2026-06-02:
  - What existed before: the page was `68/80`, reconstructable, but had no parent attachment.
  - Changed to: completion `72` and `AUTOGEN_PARENT_UID:0000HV`.
  - Summary/evidence: the Browser source root is already validated at `NexusTK/browser/`, and this page's own evidence identifies the initializer as Browser-object state rather than a separate message-id enum.
- 2026-06-05:
  - What existed before: the page was `72/80` and still relied on summary-level constructor evidence plus an older local scan description.
  - Changed to: completion `82`, confidence `84`, and refreshed live IDA evidence for the constructor window, Browser subobject placement, scoped `0x0101` scan, adjacent field references, and broad `22Ch` false-positive limits.
  - Summary/evidence: IDA MCP confirms `sub_46FF50` range `0x0046ff50-0x00470159`; the constructor installs the Browser vtable at `[esi+10h]`, initializes nearby Browser members, and writes `0x0101` only at `[esi+22Ch]` inside the Browser/OLE cluster. The score is capped because this still appears to be a Browser state word or bitmask candidate rather than a proven source enum.
