*** UID:000030 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ColorStringSystemMessage

## Status

- Confidence: strong for role and vtable membership; medium for final method names/signatures.
- Likely source file: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Main address range: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- Tiny virtual helpers: [UID:0001GG][0x0055c1b0-0x0055c1c2.SystemMessageBooleanVirtuals](by-memory/0x0055c1b0-0x0055c1c2.SystemMessageBooleanVirtuals.md)
- Current recovered file: `source-3/simroot_v2/class_ColorStringSystemMessage.cpp`

## Class Purpose

`ColorStringSystemMessage` is a system-message entry object that owns a copied wide string plus color/attribute fields. `SystemMessagePane` and `OldSystemMessagePane` clone and draw these entries while computing line counts for the scrollable message viewport.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0055c1c0-0x0055c1c2` | false boolean virtual | Returns false; vtable slot used by `ColorStringSystemMessage` and several related message/dialog classes. |
| `0x00587970-0x00587a0e` | constructor | Copies a UTF-16 string into heap-owned storage and stores color/attribute values. |
| `0x00587a70-0x00587adf` | `Clone` | Allocates a new 16-byte message object and reconstructs it from this entry's text/color/attribute. |
| `0x00587ae0-0x00587b52` | line-count helper | Calls [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) with text, length, and width, then clamps to at least one line; current helper body returns constant `1`. |
| `0x00587b60-0x00587ba3` | `Draw` | Sets the pane text/background color state and draws the stored text in the supplied rectangle. |
| `0x0058ab50-0x0058abe6` | scalar deleting destructor | Frees the text buffer, tears down `LObject`, and conditionally deletes storage. |

## Evidence Notes

- IDA names the vtable at `0x0062d6f4` as `ColorStringSystemMessage`.
- IDA `xrefs_to 0x00587970` includes construction from `SystemMessagePane` constructor, an insert/helper at `0x005854d0`, a message parsing helper at `0x00586480`, `Clone`, and `OldSystemMessagePane` constructor paths.
- IDA decompilation of `0x00587ae0` differs structurally from the active generated source: the body calls [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) with this entry's text buffer, `wcslen(text)`, and the width argument, then clamps the result to at least one line.
- 2026-05-25 recheck: `0x004bb070` itself decompiles to a literal `return 1`, so the active generated `GetLineCount` stub is behaviorally equivalent but loses the helper-call/source-structure shape. IDA `xrefs_to 0x00587ae0` still shows the method is vtable-referenced at `0x0062d70c`.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:0000EA][SystemMessagePane](by-class/SystemMessagePane.md)
- [UID:00009T][OldSystemMessagePane](by-class/OldSystemMessagePane.md)
- [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md)
- [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md)
- [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/84`.
  - Summary/evidence: the class role, vtable, construction/cloning/draw/destructor methods, helper call shape, and core cross-references are documented from IDA-backed address ranges; remaining uncertainty is mostly final source naming/signature detail and exact helper source structure.
