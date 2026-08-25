*** UID:00000X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class BlockListenInputPane : public CharInputPane
{
public:
    BlockListenInputPane();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void HandleCommandSelection();
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BlockListenInputPane

## Status

- Confidence: strong for behavior and source grouping.
- Likely source file: [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- Autogen parent: [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md). Batch 298 raised this child to `85/88`, and the direct file parent remains `85/89`, so the strict child/direct-parent gate clears.
- Exact memory pages: [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md), [UID:0001MX][0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler](by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md), [UID:0001MY][0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher](by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md)
- Module index: [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md)
- Vtable family: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Documentation basis: IDA-confirmed handler boundaries, raw constructor bytes, vtable-family evidence, module-index split, and sibling add/delete class docs.

## Class Purpose

`BlockListenInputPane` is the top-level prompt for managing the client's block-listen list. It is a [UID:00001P][CharInputPane](by-class/CharInputPane.md)-style command prompt with three visible command paths: show list, add name, and delete name.

## Class Shape

- Base family: command/input pane in the [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md).
- User flow: show current block-list, open add-name input, or open delete-name input.
- Data dependencies: reads current block-list storage and validates capacity/empty-list state before opening sub-prompts.
- Source placement: [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), with possible grouping into the broader [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md).

## Source-Facing Aliases

| Alias | Value / text | Evidence and use |
| --- | --- | --- |
| `kBlockListenPromptStringId` | `0x27` / zero-based resource id `39` | [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md) pushes `0x27` before calling `LanguageMan::GetLocalizedString`; this is the source-facing id constant used by the constructor initializer. |
| Current decoded prompt text | `Ignore list - (A)dd,(D)elete,(?)List ` | Current `STR.RES` payload text for id `39` / `0x27`; source should keep the id/constant lookup through [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), not embed this English text. |

## Constructor Vtable Store Roles

The [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md) contains compiler-generated vptr stores after `CharInputPane` base construction. These stores prove the class identity and object view layout, but they are not handwritten source statements.

| Store address | Store | Role |
| --- | --- | --- |
| `0x005b68df` | `[this+0x00] = 0x0063064c` | Primary `BlockListenInputPane` view. |
| `0x005b68e7` | `[this+0xa0] = 0x0063069c` | Secondary adjusted `BlockListenInputPane` view. |
| `0x005b68f1` | `[this+0xa4] = 0x006306cc` | Tertiary adjusted `BlockListenInputPane` view. |

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md) | `BlockListenInputPane::BlockListenInputPane()` | Source-ready/applied constructor C++: initializes `CharInputPane` with `g_pLanguageMan->GetLocalizedString(kBlockListenPromptStringId)`, where `kBlockListenPromptStringId = 0x27`; subsequent primary/secondary/tertiary vptr stores are compiler output. |
| [UID:0001MX][0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler](by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md) | `BlockListenInputPane::HandleKeyOrTextEvent(Event *)` | Source-ready/applied first-draft C++: translates key/modifiers, handles exact Shift+`?` key-down, builds a newline-delimited `SimpleUString` from `g_pConfig->m_blockListenNames`, shows it in an OK `AlertPane`, returns handled, and otherwise forwards to `CharInputPane::HandleKeyOrTextEvent(event)`. Historical Ctrl/`OnKeyInput`/`InputEvent` wording is superseded. |
| [UID:0001MY][0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher](by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md) | `HandleCommandSelection()` | Source-ready/applied first-draft C++: reads one inherited line-input character with `GetTextLength()`/`CopyText(...)`; `A/a` opens `new AddToBlockListenInputPane()` while `g_pConfig->m_blockListenNames` is below `0x28` or opens localized full-list alert id `0xf2`; `D/d` opens `new DeleteFromBlockListenInputPane()` when the list is non-empty or opens localized empty-list alert id `0xf3`. |

## Evidence Notes

- IDA MCP `lookup_funcs` reports `0x005b68c0` as not defined, but a limited IDA disassembly shows a constructor-shaped body covering `0x005b68c0-0x005b6900`.
- IDA MCP confirms real functions at `0x005b6900` and `0x005b6a20`.
- IDA MCP confirms three `BlockListenInputPane` vtable views at `0x0063064c`, `0x0063069c`, and `0x006306cc`, with stores from the command dispatcher/open helper and raw constructor-shaped bytes.
- IDA MCP `xrefs_to` for `0x005b6900` and `0x005b6a20` includes vtable/data references.
- `HandleCommandSelection` constructs [UID:00000A][AddToBlockListenInputPane](by-class/AddToBlockListenInputPane.md) and [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md) directly by allocating `0x108` bytes, calling `LineInputPane`, and installing the target vtables.
- 2026-06-02 IDA MCP refresh confirms the same modeled handler starts and vtable xrefs, while raw byte/disassembly review splits adjacent switch-table and packet-helper bytes under [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md).
- 2026-06-12 Agent-A001 Batch 298 live IDA MCP session `b001_nexustk` rechecked `NexusTK.exe.i64` with auto-analysis, Hex-Rays, and string cache ready. `lookup_funcs` still reports `0x005b68c0` as `<no function>`, while `0x005b6900` is `sub_5B6900`, size `0x11b` / 283 bytes, and `0x005b6a20` is `sub_5B6A20`, size `0x1df` / 479 bytes (Verified with int_convert.py).
- Batch 298 raw-range signature for `0x005b68c0-0x005b6900` is unique and covers the constructor-shaped sequence: prompt id `0x27`, `CharInputPane` construction, vtable stores to `0x0063064c`, `0x0063069c`, and `0x006306cc`, then `retn` at the boundary before the key handler.
- Batch 298 `trace_data_flow` reconfirmed all three top-level vtable views are installed from the raw constructor (`0x005b68df/0x005b68e7/0x005b68f1`) and two modeled creation/open sites (`0x005a72af/0x005a72b7/0x005a72c1` and `0x005aa336/0x005aa33c/0x005aa346`). Secondary/tertiary stores target `this + 0xa0` / decimal 160 and `this + 0xa4` / decimal 164 (Verified with int_convert.py).
- Batch 298 decompilation reconfirmed the key handler's Ctrl+`?` path: it narrows the translated key to decimal `63`, requires key-state byte `4` and message type `8`, iterates the block-list vector at `dword_67A7C8 + 0x2918fc` through `+0x291900`, appends each entry and newline, displays an alert, and falls back to `CharInputPane` for other key events.
- Batch 298 decompilation reconfirmed the command dispatcher reads one wide command, routes `A/a` to an add subprompt when the list contains fewer than `0x28` / decimal 40 entries, shows localized alert id `0xf2` when full, routes `D/d` to a delete subprompt when non-empty, and shows localized alert id `0xf3` when empty. The add/delete subprompt allocation size is `0x108` / decimal 264 (Verified with int_convert.py), matching the sibling class pages.
- 2026-06-19 B008 [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md) source-quality support note: the raw `0x0d` / `0x01` no-payload BlockListen request is semantically top-level block-list behavior, but no constructor, vtable slot, dispatcher branch, switch-table entry, absolute pointer, or rel32 route currently reaches `0x005b6c30`. Keep [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md) as a file-level [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md) helper rather than a direct method on this class until a route is proven.
- 2026-06-26 B002 accepted source-quality implementation for [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md) used active IDA MCP session `80de0a67`: `server_health` was `ok`, `lookup_funcs` still reported `0x005b68c0` / `0x005b68ff` as `Not a function`, successor `0x005b6900` was the modeled key handler `sub_5B6900`, `get_bytes` confirmed fifteen `0xcc` bytes before the constructor and the exact 64-byte body, and `make_signature_for_range` produced a unique constructor signature beginning `55 8B EC 51 56 8B F1 8B 0D ? ? ? ? 6A 27...`. The resolved source form is a first-draft `BlockListenInputPane::BlockListenInputPane()` constructor that passes `g_pLanguageMan->GetLocalizedString(kBlockListenPromptStringId)` into `CharInputPane`.
- The same B002 pass ties prompt id `0x27` / zero-based resource id `39` to current `STR.RES` text `Ignore list - (A)dd,(D)elete,(?)List `, resolves the base constructor call as `CharInputPane::CharInputPane(const wchar_t *)`, records zero direct xrefs to raw start `0x005b68c0`, and preserves the raw-start/no-xref state as a confidence cap only. `InputPanes`, `LanguageMan`, and resource pages remain dependencies, not owners.
- 2026-06-26 B004 accepted source-quality implementation for [UID:0001MX][0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler](by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md) used the same active IDA MCP session `80de0a67`, with final health `ok`, Hex-Rays ready, and strings cache ready. MCP reconfirmed `0x005b6900` as `sub_5B6900`, size `0x11b` / 283 bytes, vtable/data slot `0x006306a4`, no direct code callers, `0x005b6a1b` as the end boundary, five `0xcc` bytes before successor `0x005b6a20`, and no IDA DB writes.
- The B004 pass resolves the class method name as `BlockListenInputPane::OnKeyInput(const InputEvent *)` by matching the accepted sibling `SpellSpellInputPane::OnKeyInput` pattern. The gate is `NarrowInputKey(event->keyCode, event->narrowFallback) == '?'`, `event->narrowFallback == 4`, and `event->type == 8`; nonmatching input falls back to `CharInputPane::OnKeyInput(event)`.
- The B004 pass resolves the show-list path as feature-owned class behavior: it reads the block-list vector at `g_pConfig + 0x2918fc/+0x291900`, source-facing `Config::m_blockListenNames`, appends each full `SimpleUString` entry plus one trailing newline, opens `new AlertPane(blockListText.c_str(), g_activeMapPane, kDialogOkButtonText, NULL)`, and returns handled. Config, StringBase, AlertPanes, EventMan/CRT, and CharInputPane are dependencies or rejected raw-label owners, not owners of this class method.
- 2026-06-27 B006 accepted source-quality implementation for [UID:0001MY][0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher](by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md) used MCP-backed report session `875bf182` plus callback probe session `b001_000241_20260627`; `server_health` was `ok`, auto-analysis/Hex-Rays/string cache were ready, and no IDA DB writes were made. `lookup_funcs` reconfirmed `0x005b6a20` as `sub_5B6A20`, size `0x1df`, while `0x005b6bff`, `0x005b6c00`, and `0x005b6c30` are not functions. `xrefs_to` reconfirmed the vtable slot at `0x00630694`, the switch-table xref from `0x005b6a7b` to `0x005b6c00`, and zero xrefs to [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md).
- The B006 pass resolves [UID:0001MY][0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher](by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md) as source-ready `BlockListenInputPane::HandleCommandSelection()` first-draft C++. The old blank-C++ blocker is closed by accepted support names: inherited `GetTextLength()` and `CopyText(...)` from [UID:00035S][0x004f2310-0x004f231b.LineInputPaneTextLength](by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md) / [UID:00035R][0x004f2300-0x004f230f.LineInputPaneCopyText](by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md), `g_pConfig->m_blockListenNames`, localized alert lookups through `g_pLanguageMan`, `AlertPane`, `g_activeMapPane`, and `kDialogOkButtonText`. Exact original resource constant names and the virtual return declaration remain inferred confidence caps, not current C++ blockers.
- [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md) remains a semantically related but separate file-level no-route helper. The switch/jump table at `0x005b6c00-0x005b6c30` belongs to [UID:0001MY][0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher](by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md), and the raw packet helper starts after it with no proven constructor, vtable, branch, absolute-pointer, or rel32 route from this class method.

## Parent-Chain Repair

## B003 2026-07-20 Event Contract Completion

- The complete class declaration supersedes the comment-only route marker. It declares the constructor, canonical `bool HandleKeyOrTextEvent(Event *event)`, and independent `void HandleCommandSelection()`, closes the class, and places `[[CHILDREN]]` after the closing brace.
- Only the shared Event surface changes: producer evidence proves modifier `0x04` is Shift, not Ctrl. The list vector, per-entry newline, `AlertPane`, add/delete command dispatch, prompt ids, capacity/empty checks, and no-route packet helper disposition remain unchanged.
- The score rises from `88/90` to `90/92` because the source declaration and shared handler contract are complete; inferred private `Config`, string, and resource spellings remain confidence caps.

Batch 298 repairs the class-side gate. The direct file parent [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md) already clears `85/89`; this page now clears `85/88`, so `AUTOGEN_PARENT_UID` is set to `0000HS`.

The exact top-level child pages now route to this class as their direct semantic parent after their own scores were refreshed: [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md) is `88/90` with first-draft constructor C++ ready/applied, [UID:0001MX][0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler](by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md) is `90/91` with first-draft `OnKeyInput` C++ ready/applied, and [UID:0001MY][0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher](by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md) is `90/91` with first-draft `HandleCommandSelection` C++ ready/applied. The broader [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md) aggregate and [UID:0002N9][0x0063064c-0x006307ec.BlockListenInputPaneVtableData](by-memory/0x0063064c-0x006307ec.BlockListenInputPaneVtableData.md) still legitimately route to the file parent because each spans multiple block-list pane classes or source-level helper islands.

## Score Rationale

The class is raised to `88/90`: it has exact top-level constructor/key/dispatcher child pages, fresh live IDA evidence for raw constructor bytes, handler sizes, vtable stores, key-command behavior, list-vector use, add/delete prompt allocation, source-file parentage, sibling-class links, first-draft constructor C++ for [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md), first-draft key-input C++ for [UID:0001MX][0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler](by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md), first-draft command-dispatcher C++ for [UID:0001MY][0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher](by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md), and a formal `[[CHILDREN]]` route marker on this class page. Broad class declaration/layout and exact project-wide event/config/resource type spellings remain later class-layout work, so this class does not duplicate child method bodies.

## Cross-References

- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:00000A][AddToBlockListenInputPane](by-class/AddToBlockListenInputPane.md)
- [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md)
- [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)

## Changes

- 2026-06-27 B006 [UID:0001MY][0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher](by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md) source-quality incorporation: no class metadata change. Updated the method map, parent-chain prose, score rationale, and evidence notes to mark the dispatcher child as `90/91` with formal first-draft `BlockListenInputPane::HandleCommandSelection()` C++ present. Preserved [UID:00000X] class ownership, [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md) source placement, the `0x005b6c00-0x005b6c30` switch-table boundary, [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md) as a separate no-route file helper, the `0x28` add-prompt threshold, localized alert ids `0xf2`/`0xf3`, and the remaining class-level caps for declaration/resource-name exactness.
- 2026-06-26 B004 [UID:0001MX][0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler](by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md) source-quality incorporation: no class metadata change. Normalized the key-handler method row to `BlockListenInputPane::OnKeyInput(const InputEvent *)`, recorded the exact Ctrl+`?`/mode/type gate, base `CharInputPane::OnKeyInput` fallback, `g_pConfig->m_blockListenNames` vector source route, `SimpleUString` per-entry newline accumulation, `AlertPane` creation path, vtable/no-direct-caller/padding evidence, and rejected Config/StringBase/AlertPanes/EventMan/CRT/CharInputPane ownership alternatives. The target child is now `90/91` with first-draft C++ present.
- 2026-06-26 B002 [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md) source-quality incorporation: no class metadata change. Updated the constructor method row to first-draft C++ ready/applied, added source-facing alias `kBlockListenPromptStringId = 0x27` with current resource text `Ignore list - (A)dd,(D)elete,(?)List `, added the constructor vptr-store role table for `0x005b68df`, `0x005b68e7`, and `0x005b68f1`, and preserved raw/no-function plus zero-start-xref evidence as a constructor confidence cap rather than a class ownership blocker.

- What existed before: the page documented constructor-shaped bytes, handlers, vtables, and sub-prompt construction but had unevaluated scores.
- What it was changed to: scores were set to `73/84`, and class-shape notes were added for command-input family, user flow, data dependencies, and source placement.
- Summary and evidence: real handler functions and vtable references are IDA-confirmed, while constructor start is raw/unmodeled and final source grouping remains partly open.

- 2026-06-02:
  - Before: the class was not marked reconstructable or attached to a source parent.
  - After: marked `RECONSTRUCTABLE:TRUE`, attached to [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), and raised to `78/86`.
  - Summary/evidence: source folder is now validated as `NexusTK/social/`, and fresh IDA MCP confirms the handler/vtable evidence while the aggregate records raw helper boundaries.

- 2026-06-06 provenance cleanup:
  - Before: the status still described the class through a direct recovered-source path while the sibling add/delete panes already used IDA/by-* evidence.
  - After: replaced the recovered-path status with the documented IDA, vtable, module-index, and sibling-class evidence basis; scores, parent attachment, and blank final C++ were unchanged.
  - Summary/evidence: [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md), [UID:0001MX][0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler](by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md), [UID:0001MY][0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher](by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md), and [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md) already carry the authoritative evidence.

- 2026-06-10 A002 strict-gate repair:
  - Before: `AUTOGEN_PARENT_UID:0000HS` attached this class to [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md).
  - After: `AUTOGEN_PARENT_UID:` is blank; score remains `78/86`.
  - Summary/evidence: the direct file parent is now `85/89`, but the child page is below the required child completion threshold. Keep the source-owner cross-reference and evidence, but do not emit this class through validator autogen until the child page reaches `85/85`.
- 2026-06-12 Agent-A001 Batch 298 parent-chain repair:
  - Before: `78/86`, `AUTOGEN_PARENT_UID:` blank.
  - After: `85/88`, `AUTOGEN_PARENT_UID:0000HS`.
  - Summary/evidence: live IDA MCP reconfirmed ready IDB state, raw constructor unique bytes and vtable installs, modeled key/command handler sizes, vtable slots, creation/open sites, Ctrl+`?` list-display behavior, `A/a` and `D/d` command routing, list-vector offsets, alert ids, add/delete subprompt allocation size, and direct exact-child routing through this class.
- 2026-06-19 B008 [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md) support sync: no score change. Added the class-routing caveat for the semantically top-level but no-route raw `0x0d/0x01` helper.
- 2026-07-01 B007 empty-emitter implementation callback: raised `85/88` to `88/90` and inserted the formal `[[CHILDREN]]` class-route marker. The exact source bodies already live on [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md), [UID:0001MX][0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler](by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md), and [UID:0001MY][0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher](by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md); this class page stays a route/ownership page and preserves `NexusTK/social/BlockListenInputPanes.cpp` as stronger than `CommandInputPanes.cpp`.
