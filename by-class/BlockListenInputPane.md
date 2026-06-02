*** UID:00000X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BlockListenInputPane

## Status

- Confidence: strong for behavior and source grouping.
- Likely source file: [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- Exact memory pages: [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md), [UID:0001MX][0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler](by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md), [UID:0001MY][0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher](by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md)
- Module index: [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md)
- Vtable family: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_BlockListenInputPane.cpp`

## Class Purpose

`BlockListenInputPane` is the top-level prompt for managing the client's block-listen list. It is a [UID:00001P][CharInputPane](by-class/CharInputPane.md)-style command prompt with three visible command paths: show list, add name, and delete name.

## Class Shape

- Base family: command/input pane in the [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md).
- User flow: show current block-list, open add-name input, or open delete-name input.
- Data dependencies: reads current block-list storage and validates capacity/empty-list state before opening sub-prompts.
- Source placement: [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), with possible grouping into the broader [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md).

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md) | `BlockListenInputPane::BlockListenInputPane()` | Constructor-shaped bytes: localizes prompt id `0x27`, calls `CharInputPane`, and installs three vtable views. |
| [UID:0001MX][0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler](by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md) | `HandleKeyEvent(...)` | Handles Ctrl+`?` key message type `8`; builds a newline-delimited block-list string and shows it in an alert. Otherwise forwards to `CharInputPane`. |
| [UID:0001MY][0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher](by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md) | `HandleCommandSelection()` | Reads one character; `A/a` opens add prompt or capacity alert, `D/d` opens delete prompt or empty-list alert. |

## Evidence Notes

- IDA MCP `lookup_funcs` reports `0x005b68c0` as not defined, but a limited IDA disassembly shows a constructor-shaped body covering `0x005b68c0-0x005b6900`.
- IDA MCP confirms real functions at `0x005b6900` and `0x005b6a20`.
- IDA MCP confirms three `BlockListenInputPane` vtable views at `0x0063064c`, `0x0063069c`, and `0x006306cc`, with stores from the command dispatcher/open helper and raw constructor-shaped bytes.
- IDA MCP `xrefs_to` for `0x005b6900` and `0x005b6a20` includes vtable/data references.
- `HandleCommandSelection` constructs [UID:00000A][AddToBlockListenInputPane](by-class/AddToBlockListenInputPane.md) and [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md) directly by allocating `0x108` bytes, calling `LineInputPane`, and installing the target vtables.
- 2026-06-02 IDA MCP refresh confirms the same modeled handler starts and vtable xrefs, while raw byte/disassembly review splits adjacent switch-table and packet-helper bytes under [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md).

## Cross-References

- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:00000A][AddToBlockListenInputPane](by-class/AddToBlockListenInputPane.md)
- [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md)
- [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)

## Changes

- What existed before: the page documented constructor-shaped bytes, handlers, vtables, and sub-prompt construction but had unevaluated scores.
- What it was changed to: scores were set to `73/84`, and class-shape notes were added for command-input family, user flow, data dependencies, and source placement.
- Summary and evidence: real handler functions and vtable references are IDA-confirmed, while constructor start is raw/unmodeled and final source grouping remains partly open.

- 2026-06-02:
  - Before: the class was not marked reconstructable or attached to a source parent.
  - After: marked `RECONSTRUCTABLE:TRUE`, attached to [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), and raised to `78/86`.
  - Summary/evidence: source folder is now validated as `NexusTK/social/`, and fresh IDA MCP confirms the handler/vtable evidence while the aggregate records raw helper boundaries.
