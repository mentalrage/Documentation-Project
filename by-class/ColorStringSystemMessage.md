*** UID:000030 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ColorStringSystemMessage

## Status

- Confidence: strong for role, vtable membership, method boundaries, and source-family ownership; medium-high for final method names/signatures.
- Likely source file: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Main address range: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- Tiny virtual helpers: [UID:0001GG][0x0055c1b0-0x0055c1c2.SystemMessageBooleanVirtuals](by-memory/0x0055c1b0-0x0055c1c2.SystemMessageBooleanVirtuals.md)
- Generated-output caveat: older recovered class output exists, but Batch 082 scoring and assignment rely on IDA MCP and existing project-documentation evidence.

## Class Purpose

`ColorStringSystemMessage` is a system-message entry object that owns a copied wide string plus color/attribute fields. `SystemMessagePane` and `OldSystemMessagePane` clone and draw these entries while computing line counts for the scrollable message viewport.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0055c1c0-0x0055c1c2` | false boolean virtual | Returns false; vtable slot used by `ColorStringSystemMessage` and several related message/dialog classes. |
| `0x00587970-0x00587a0f` | constructor | Copies a UTF-16 string into heap-owned storage and stores color/attribute values. |
| `0x00587a70-0x00587ae0` | `Clone` | Allocates a new 16-byte message object and reconstructs it from this entry's text/color/attribute. |
| `0x00587ae0-0x00587b53` | line-count helper | Calls [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) with text, length, and width, then clamps to at least one line; current helper body returns constant `1`. |
| `0x00587b60-0x00587ba4` | `Draw` | Sets the pane text/background color state and draws the stored text in the supplied rectangle. |
| `0x0058ab50-0x0058abe7` | scalar deleting destructor | Frees the text buffer, tears down `LObject`, and conditionally deletes storage. |

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md). This class is now scored `85/88`, and the direct source-file parent is scored `89/86`, so both sides satisfy the corrected 85/85 gate. The parent is direct because the file page explicitly owns the system-message pane/message-entry family, lists `ColorStringSystemMessage` in proposed contents, and documents the same constructor/clone/line-count/draw/destructor island plus shared boolean virtual helper.

## Evidence Notes

- IDA names the vtable at `0x0062d6f4` as `ColorStringSystemMessage`.
- IDA `xrefs_to 0x00587970` includes construction from `SystemMessagePane` constructor, an insert/helper at `0x005854d0`, a message parsing helper at `0x00586480`, `Clone`, and `OldSystemMessagePane` constructor paths.
- IDA decompilation of `0x00587ae0` differs structurally from the active generated source: the body calls [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) with this entry's text buffer, `wcslen(text)`, and the width argument, then clamps the result to at least one line.
- 2026-05-25 recheck: `0x004bb070` itself decompiles to a literal `return 1`, so the active generated `GetLineCount` stub is behaviorally equivalent but loses the helper-call/source-structure shape. IDA `xrefs_to 0x00587ae0` still shows the method is vtable-referenced at `0x0062d70c`.
- 2026-06-07 A008 Batch 082 IDA MCP refresh reconfirmed the exact modeled method bounds: constructor `0x00587970-0x00587a0f`, clone `0x00587a70-0x00587ae0`, line-count helper `0x00587ae0-0x00587b53`, draw `0x00587b60-0x00587ba4`, and scalar deleting destructor `0x0058ab50-0x0058abe7`.
- The same refresh found seven constructor callers from `SystemMessagePane` construction, insertion/parsing helpers, clone, and old-pane construction paths; vtable words at `0x0062d6f4` include the destructor, shared false boolean slots, clone, line-count, and draw entries.

## Score Rationale

- Completion `85`: class purpose, direct source parent, vtable membership, all current method bounds, constructor caller spread, clone/line-count/draw/destructor behavior, helper dependency, and cross-references are documented. Remaining work is final source-facing names/signatures and final C++.
- Confidence `88`: current IDA MCP evidence confirms the method boundaries, vtable slots, and source-family ownership through the `SystemMessagePanes` parent; confidence stays below final-source quality because method names and signatures are still partly descriptive.

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
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank because the class completion score is below the 80% attachment gate.
  - Evidence: live IDA MCP confirms modeled method starts at `0x00587970`, `0x00587a70`, `0x00587ae0`, `0x00587b60`, and `0x0058ab50`, with constructor callers from `SystemMessagePane` and related message insertion/parsing paths.
- 2026-06-07 A008 Batch 082 class-coverage pass:
  - Before: `78/84`, `AUTOGEN_PARENT_UID:` blank.
  - After: `85/88`, `AUTOGEN_PARENT_UID:0000OE`.
  - Evidence: current IDA MCP reconfirmed exact method half-open ranges, constructor caller spread, vtable slots, and the direct source-family parent [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) at `89/86`.
