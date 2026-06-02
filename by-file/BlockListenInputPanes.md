*** UID:0000HS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# BlockListenInputPanes

## Status

- Confidence: strong for class grouping, behavior, and source folder.
- Proposed module folder: `NexusTK/social/`
- Candidate file: `NexusTK/social/BlockListenInputPanes.cpp`
- Possible alternate owner: `ui/dialogs/CommandInputPanes.cpp`
- Current generated sources: `class_BlockListenInputPane.cpp`, `class_AddToBlockListenInputPane.cpp`, and `class_DeleteFromBlockListenInputPane.cpp`.
- Evidence basis: Wave3 class inspection, `simroot_v2` generated source, and targeted IDA MCP function/vtable checks on 2026-05-24 and 2026-05-26.

## Hypothesis

`BlockListenInputPanes.cpp` should own the command prompts used to view, add, and delete entries in the block-listen list. The panes are UI input prompts, but their state and packets are social/block-list feature logic, so a `social/` source is the stronger current placement.

Likely structure:

```text
social/BlockListenInputPanes.cpp
```

Possible broader placement:

```text
ui/dialogs/CommandInputPanes.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:00000X][BlockListenInputPane](by-class/BlockListenInputPane.md) | `0x005b68c0-0x005b6bff` | `class_BlockListenInputPane.cpp` | Top-level typed command prompt; `?` shows current list, `A/a` opens add prompt, and `D/d` opens delete prompt. Exact bodies: [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md), [UID:0001MX][0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler](by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md), [UID:0001MY][0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher](by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md). |
| [UID:00000A][AddToBlockListenInputPane](by-class/AddToBlockListenInputPane.md) | `0x005b6c80-0x005b700e` | `class_AddToBlockListenInputPane.cpp` | Adds a validated alphabetic name to the local block list and sends opcode `0x0d`, subcommand `0x02`. Exact bodies: [UID:0001MZ][0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor](by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md), [UID:0001N0][0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName](by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md). |
| [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md) | `0x005b7100-0x005b7354` | `class_DeleteFromBlockListenInputPane.cpp` | Removes a matching block-list entry and sends opcode `0x0d`, subcommand `0x03`. Exact bodies: [UID:0001N1][0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor](by-memory/0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor.md), [UID:0001N2][0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm](by-memory/0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm.md). |
| [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md) | `0x005b6c30-0x005b6c7c` | not modeled as current IDA function | Raw packet helper that sends opcode `0x0d`, subcommand `0x01`. |
| [UID:0002S0][0x005b7010-0x005b70f7.SendAddBlockListenPacket](by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md) | `0x005b7010-0x005b70f7` | not modeled as current IDA function | Raw packet helper that encodes opcode `0x0d`, subcommand `0x02`, and one name string. |
| [UID:0002RZ][0x005b7360-0x005b7447.SendDeleteBlockListenPacket](by-memory/0x005b7360-0x005b7447.SendDeleteBlockListenPacket.md) | `0x005b7360-0x005b7447` | not modeled as current IDA function | Raw packet helper that encodes opcode `0x0d`, subcommand `0x03`, and one name string. |
| [UID:0000PM][FindBlockListEntry_5B74E0](by-global/FindBlockListEntry_5B74E0.md) | `0x005b74e0-0x005b7553` | not emitted as active source | Private vector/string find helper used by add and delete confirmation handlers. |

## IDA MCP Evidence

Targeted checks on 2026-05-24 confirmed:

- Constructor-shaped code exists at `0x005b68c0-0x005b6900`, `0x005b6c80-0x005b6cc0`, and `0x005b7100-0x005b7140`; the current IDA function table does not define those starts as functions.
- `BlockListenInputPane` virtual handlers are exact IDA functions at `0x005b6900-0x005b6a1b` and `0x005b6a20-0x005b6bff`.
- `AddToBlockListenInputPane::SubmitBlockedName` is `0x005b6cc0-0x005b700e`.
- `DeleteFromBlockListenInputPane::OnConfirm` is `0x005b7140-0x005b7354`.
- `FindBlockListEntry_5B74E0` is a real helper at `0x005b74e0-0x005b7553`, called only by the add and delete confirmation handlers in this pass.
- Vtable/data xrefs point to `0x005b6900`, `0x005b6a20`, `0x005b6cc0`, and `0x005b7140`; direct code callers are absent because these are virtual handlers or constructor targets patched through allocation sites.
- 2026-05-26 IDA vtable pass confirms three-view table groups for `BlockListenInputPane`, `AddToBlockListenInputPane`, and `DeleteFromBlockListenInputPane`; see [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md). Current `simroot_v2` metadata for all three checked classes still reports `vtable_count: 0`.
- 2026-06-02 IDA MCP refresh confirms the same real handler boundaries and vtable references. It also identifies raw helper bodies at `0x005b6c30-0x005b6c7c`, `0x005b7010-0x005b70f7`, and `0x005b7360-0x005b7447`; all three are not modeled as functions and currently have no direct xrefs, but manual disassembly shows block-list packet construction through `sub_575380`, `WideCharToMultiByte` where applicable, and `sub_574BB0`.

## Ownership Notes

- The underlying list lives in the config/global state at `dword_67A7C8 + 0x2918fc` through `+0x291900` in IDA decompilation.
- `BlockListenInputPane::HandleCommandSelection` allows opening the add prompt while the list has fewer than `0x28` entries, but `AddToBlockListenInputPane::SubmitBlockedName` only accepts insertion when the list has fewer than `0x14` entries. This may reflect separate UI/list capacities or a recovered-data mismatch; preserve it as observed until the config layout is named.
- The add/delete handlers call shared line-input helpers `0x004f2300` and `0x004f2310`; those helpers belong to [UID:0000K7][InputPanes](by-file/InputPanes.md), not this feature file.
- `0x00680067` and `0x00690052` are not executable methods. IDA reads those bogus pointer values from UTF-16 `"Right click look :ON"` / `"Right click look :OFF"` string data at `0x006307ec`, `0x006307f0`, `0x00630818`, and `0x0063081c`; keep them out of this class/file.
- 2026-05-26 recheck: IDA MCP still reports `0x00680067` and `0x00690052` as `Not a function` with data xrefs only. They are now recorded in [UID:0000VN][-ignored](by-memory/-ignored.md) as false generated method starts.

## Cross-References

- [UID:00000X][BlockListenInputPane](by-class/BlockListenInputPane.md)
- [UID:00000A][AddToBlockListenInputPane](by-class/AddToBlockListenInputPane.md)
- [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md)
- [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md)
- [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md)
- [UID:0002S0][0x005b7010-0x005b70f7.SendAddBlockListenPacket](by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md)
- [UID:0002RZ][0x005b7360-0x005b7447.SendDeleteBlockListenPacket](by-memory/0x005b7360-0x005b7447.SendDeleteBlockListenPacket.md)
- [UID:0000PM][FindBlockListEntry_5B74E0](by-global/FindBlockListEntry_5B74E0.md)
- [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

- What existed before: the page documented block-listen prompt grouping, constructors/handlers, vtables, helper ownership, and false generated method starts but had unevaluated scores.
- What it was changed to: scores were set to `74/84`.
- Summary and evidence: behavior and grouping are strongly supported; final source folder and constructor raw-boundary caveats keep the score below higher confidence.

- 2026-06-02 path and raw-helper refresh:
  - What existed before: the page kept `PROPOSED_RECONSTRUCTION_PATH` blank and treated the broad prompt area as only the documented constructors/handlers plus unspecified interior gaps.
  - What it was changed to: the page now places the module at `NexusTK/social/`, raises the score to `82/88`, and records raw packet helpers at `0x005b6c30-0x005b6c7c`, `0x005b7010-0x005b70f7`, and `0x005b7360-0x005b7447`.
  - Summary/evidence: IDA MCP `lookup_funcs`, `xrefs_to`, `callees`, `callers`, manual disassembly, and byte reads confirm handler boundaries, vtable stores, packet opcode/subcommand writes, and alignment bytes.
