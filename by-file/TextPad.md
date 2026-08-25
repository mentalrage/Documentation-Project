*** UID:0000OQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TextPad

## Status

- Confidence: very strong for the complete function/data inventory, class behavior, exact ranges, command-helper ownership, vtable identity, source order, and separation from adjacent text-dialog/editor modules. The stripped external constructor caller and private spellings remain bounded confidence caps.
- Proposed module: `ui/dialogs/TextPad.cpp`
- Proposed header: `ui/dialogs/TextPad.h`
- Current recovered source: `source-3/simroot_v2/class_TextPad.cpp`
- Main memory range: [UID:0001JV][0x00595900-0x00596242.TextPad](by-memory/0x00595900-0x00596242.TextPad.md)
- Private helper doc: [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md)
- Standalone helper island: [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md)
- Vtable data: [UID:0003DY][0x0062e18c-0x0062e228.TextPadVtableData](by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md)
- Command strings: [UID:0003DZ][0x0062e228-0x0062e268.TextPadCommandStrings](by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md)

## File Role

`TextPad` is a full-screen `DialogPane`-derived local text editor with two [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md) children: control `0` is the main editor and control `1` is the bottom command bar. The constructor sets the main editor to 2000 lines, 30000 characters, and Enter-key handling, then attaches and shows the full-screen pane through `g_mainUiLayerSlots.rootPaneLayerContext` and `g_pScreenPane`. Pressing Enter in command control `1` dispatches its text through `TextPad::SendText(const wchar_t *commandLine)` at `0x00595be0`.

The command helper supports local file and formatting commands. IDA disassembly and B008 local PE/Capstone recheck show `wcsstr(commandLine, prefix) == commandLine` prefix checks for `Open `, `Save `, `SetFont `, and `SetColor `, then performs file I/O or applies formatting to the main `TextEditPane`.

The later `0x00595f30-0x00596242` island contains retained out-of-line TextPad member helpers: `TextPad::Open(const wchar_t *path)`, `TextPad::Save(const wchar_t *path)`, `TextPad::SetFont(unsigned short fontId)`, and `TextPad::SetColor(unsigned int color)`. Current IDA/local PE scans report no inbound xrefs to those starts, so keep them under TextPad with a reachability caveat; do not treat that no-xref state as enough evidence for generic dead-code/no-code classification.

The accepted reconstruction uses the shipped file behavior exactly. `Open` requests read/open-existing/sequential access, allocates `fileSize + 1`, preserves the word write at `buffer + 2 * fileSize`, reads the optional payload length at `buffer + 2 * textChars + 2`, and preserves the payload pointer expression `buffer + textChars + 5`. `Save` preserves the caret range around select-all/copy, writes text bytes, one zero byte, optional four-byte payload size, then payload bytes. Both paths omit invalid-handle guards and use `GetMemoryMan`, `AllocateBufferMemory`, and `FreeBufferMemory`. `SetFont` and `SetColor` use `TextRunFormatData` with `ApplySelectionFormat` masks `1` and `2`; the older invented payload and `InsertTextObject` API are invalid.

`TextPad.cpp` owns the UI command routing and the outer local-file format. [UID:0000ON][TextEditPane](by-file/TextEditPane.md) owns editor state and serialization internals, [UID:0000EP][TextEditScrap](by-class/TextEditScrap.md) carries the visible text plus optional payload, and [UID:0000ML][PlatformApi](by-file/PlatformApi.md) only provides the `g_pfnCreateFileW` dispatch slot at `0x0069be34`.

Keep this separate from [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md). `EditablePaperPane` is packet-opened item paper UI; `TextPad` is a local full-screen text pad/editor and currently has no confirmed constructor caller.

Keep this separate from [UID:0000OL][TextDialog](by-file/TextDialog.md). `TextDialog` belongs to server-driven NPC/message input flows, while `TextPad` has file command behavior and no dialog packet serialization.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `TextPad` | `0x00595900-0x00595bd1` | Full-screen dialog construction plus `HandleKeyOrTextEvent`, `DrawBackground`, and `DrawBorder`. |
| `TextPad::SendText(const wchar_t *commandLine)` | [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md) | Private command dispatcher for `Open`, `Save`, `SetFont`, and `SetColor` command prefixes. |
| `TextPad::Open` / `Save` / `SetFont` / `SetColor` | [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md) | Retained out-of-line member helper island for file open/save and direct text formatting insertion. |
| `TextPad` vtables | [UID:0003DY][0x0062e18c-0x0062e228.TextPadVtableData](by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md) | Primary and adjusted vtables plus RTTI locator pointers; assigned to [UID:0000EU][TextPad](by-class/TextPad.md). |
| TextPad command strings | [UID:0003DZ][0x0062e228-0x0062e268.TextPadCommandStrings](by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md) | UTF-16 command prefixes consumed only by `TextPad::SendText`; assigned directly to this source file. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x00595900-0x00595ae2` | `TextPad::TextPad()` | Builds the full-screen dialog, main editor, bottom command editor, root-layer attachment, and screen-pane show route. |
| `0x00595af0-0x00595ba9` | `TextPad::HandleKeyOrTextEvent(Event *event)` | Requires translated key `13`, active control id `1`, and `kEventKeyDown`; reads up to 1023 characters, calls `SendText`, selects `0..0x7fff`, or delegates to `DialogPane::HandleKeyOrTextEvent`. |
| `0x00595bb0-0x00595bcf` | `TextPad::DrawBackground()` | Sets draw color `0x80`, draw mode `0`, and calls `g_pfnFillRect(this, &m_visibleBounds)`. |
| `0x00595bd0-0x00595bd1` | `TextPad::DrawBorder()` | Intentionally empty border override. |
| [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md) | `TextPad::SendText(const wchar_t *commandLine)` | Parses text commands and dispatches to file/format helpers. |
| [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md) | `TextPad::Open` / `Save` / `SetFont` / `SetColor` | File-open, file-save, and direct insert helpers with no known inbound xrefs. |

## Ownership Notes

- Older generated `class_TextPad.cpp` called generated helper `TextPad_SendText(this, textBuffer)` but did not emit the helper body. The source-facing identity is `TextPad::SendText(const wchar_t *commandLine)`, and [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md) is a real function whose only direct code caller is `0x00595b64` inside `TextPad::HandleKeyOrTextEvent`.
- 2026-05-28 IDA MCP recheck splits the former UNKNOWN range after `TextPad::SendText` into padding plus [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md). No inbound xrefs were found for the later helper starts.
- The constructor currently has no direct IDA callers. The class may be hidden, development-only, or created through a path that current function/xref recovery does not expose.
- The generated class notes describe this as terminal/chat functionality, but the `Open`/`Save`/formatting command helper makes `TextPad.cpp` a safer source name than placing it under [UID:0000OI][TerminalPane](by-file/TerminalPane.md) or chat modules.
- The `.rdata` child [UID:0003DY][0x0062e18c-0x0062e228.TextPadVtableData](by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md) contains three COL cells and exact primary/secondary/tertiary groups of 23/11/2 slots. Constructor stores occur at `0x00595940`, `0x00595946`, and `0x00595950`; the authored overrides are `DrawBackground`, `DrawBorder`, and `HandleKeyOrTextEvent`. All other cells are inherited/compiler consequences.
- 2026-06-12 A001 Batch 294 assigns [UID:0003DZ][0x0062e228-0x0062e268.TextPadCommandStrings](by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md) directly to this file. Live IDA traces `Open `, `Save `, `SetFont `, and `SetColor ` only to [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md), and the following `0x0062e268` dword is `Thread` RTTI, not a TextPad literal.
- The same pass reconfirmed no direct xrefs to `TextPad::TextPad` at `0x00595900`; that remains a reachability/activation caveat, not a blocker for keeping the full-screen local text-pad implementation in this source root.
- 2026-06-19 B008 local PE/Capstone recheck resolves stale helper naming and offset interpretation. The `0x00595af0` handler is reached through the secondary adjusted vtable; raw `this+0x15c` maps to primary `TextPad`/`DialogPane +0x1fc` (`m_controlManager` / `m_controls`) and raw `this+0x174` maps to primary `+0x214` (`m_activeControlId` / `m_currentControlId`). Neither is a new TextPad-owned field. Control id `0` is the main editor and control id `1` is the bottom command input.
- The constructor's external allocation/factory caller is still unresolved after direct rel32 and data-pointer scans, but the constructor-internal activation path is resolved: it builds both `TextEditControlPane` children, sets the main editor limits to 2000 lines and 30000 characters, constructs a full-screen dialog rectangle from `g_screenWidth`/`g_screenHeight`, and attaches/shows through the main UI layer slot and [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md).

## 2026-06-14 IDA MCP Refresh

- `lookup_funcs` reconfirms constructor `0x00595900` size `0x1e2`, key handler `0x00595af0` size `0xb9`, close handler `0x00595bb0` size `0x1f`, empty virtual `0x00595bd0` size `0x1`, command helper `0x00595be0` size `0x346`, standalone helper `0x00595f30` size `0x135`, and second standalone helper `0x00596070` size `0x158`; `0x00596242` remains a non-function boundary.
- `xrefs_to 0x00595900` reported no direct constructor refs, preserving the activation caveat. `xrefs_to 0x00595be0` reported the single command-helper caller at `0x00595b64` inside the handler then labeled `OnKeyInput` and now identified as `HandleKeyOrTextEvent`; `xrefs_to 0x00595f30` and `0x00596070` returned no inbound refs for the standalone helper island.
- Vtable refs remain source-declared/generated-binary evidence: `xrefs_to 0x0062e190` reports the constructor store at `0x00595940`, and vtable/data refs point to the close, empty, and key-input slots at `0x00595bb0`, `0x00595bd0`, and `0x00595af0`.
- `get_bytes 0x0062e228 size 64` decodes the UTF-16 command prefix sequence `Open `, `Save `, `SetFont `, and `SetColor ` ending before the `Thread` RTTI pointer at `0x0062e268`, matching the exact command-string child.
- `callees` confirms the constructor builds dialog/text-edit controls, `HandleKeyOrTextEvent` narrows Enter-key input and calls `SendText`, the command helper owns file open/read/write/close and text-formatting calls, and the standalone helper island duplicates file/format behavior without direct refs.

## Current Source Order And Dependencies

The exact emitter order is [UID:0000EU][TextPad](by-class/TextPad.md) position 10 for the preamble and complete header, [UID:0001JV][0x00595900-0x00596242.TextPad](by-memory/0x00595900-0x00596242.TextPad.md) position 20, [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md) position 30, [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md) position 40, [UID:0003DY][0x0062e18c-0x0062e228.TextPadVtableData](by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md) position 50, and [UID:0003DZ][0x0062e228-0x0062e268.TextPadCommandStrings](by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md) position 60. The last two emit only intentional covered-by comments because the compiler emits RTTI/vtables and `SendText` emits the literals.

Direct dependencies are `DialogPane`, `Event`, `TextEditControlPane`, `TextEditPane`, `TextEditScrap`, `TextRunFormatData`, `MemoryMan`, `Application`, `MainUiGraph`, `ScreenPane`, `Surface`, and `PlatformApi`. Imported/platform routines are `g_pfnCreateFileW`, `GetFileSize`, `ReadFile`, `WriteFile`, `CloseHandle`, `wcsstr`, `wcslen`, and decimal wide scanning. Globals are `g_screenWidth`, `g_screenHeight`, `g_mainUiLayerSlots.rootPaneLayerContext`, `g_pScreenPane`, `g_pEventMan`, and `g_pfnFillRect`. TextPad owns no writable global, static, resource, packet item, external asset, or data table beyond its four source literals and pooled empty string.

## Historical Superseded Identities And Generated Output

- The 2026-06 descriptions `OnKeyInput`, `OnClose`, and `OnEmptyVirtual`, plus read-only-main-editor and close/hide behavior, were provisional slot interpretations. Complete base-vtable ordering and direct body reads prove `HandleKeyOrTextEvent`, `DrawBackground`, and `DrawBorder`; the old labels are retained here only as history and are not source authority.
- Dated validator commands 26444 and 26459 produced snapshots with those old identities, abbreviated constructor APIs, nonexistent editor/memory/format helpers, and no `TextPad.h`. Those receipts are historical observations only. Current validator output must be physically reread after any callback and cannot inherit authority from either dated snapshot.

## 2026-06-21 B008 Rule 26 Source-Quality Sync

- Historical B008 source-facing method shape used `OnKeyInput`, `OnClose`, and `OnEmptyVirtual`; those names are superseded by `HandleKeyOrTextEvent`, `DrawBackground`, and `DrawBorder` for the reasons recorded above. `SendText`, `Open`, `Save`, `SetFont`, and `SetColor` remain valid.
- [UID:0001JV][0x00595900-0x00596242.TextPad](by-memory/0x00595900-0x00596242.TextPad.md) emits the aggregate/class-facing non-child methods. [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md) emits `TextPad::SendText`, and [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md) emits the retained out-of-line file/format helpers. This split avoids duplicate bodies while keeping all source-authored TextPad behavior reconstructable.
- TextPad's file format wraps [UID:0000EP][TextEditScrap](by-class/TextEditScrap.md): visible UTF-16 text, a one-byte zero separator, optional 32-bit payload byte length, and optional payload bytes. The optional payload is [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md) / [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md) rich editor state, including delimiter byte `0`, marker `0x6b6f6e67` (`"kong"` under current Encoder byte order), and three length-prefixed state/style payload tables.
- Rejected alternatives remain explicit: free `TextPad_SendText`, generic TextEditPane helper ownership, generic FileIO/PlatformApi ownership, TextDialog/EditablePaperPane/terminal/chat ownership, and proven-dead no-code treatment for the standalone helper island.

## 2026-06-25 B012 Standalone Helper Sync

- [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md) now emits the accepted current-MCP C++ for `TextPad::Open`, `TextPad::Save`, `TextPad::SetFont`, and `TextPad::SetColor`; parent score and ownership are unchanged.
- Current MCP evidence keeps the no-direct-xref caveat, confirms exact padding, and corrects the helper bodies to no invalid-handle branches, `FILE_FLAG_SEQUENTIAL_SCAN`, MemoryMan allocation/free wrappers, `TextEditScrap::DuplicateText` / `DuplicatePayload` ownership, and the instruction-backed open payload cursor (`[ebx+esi*2+2]` length, `[ebx+5]+esi` payload).
- TextPad still owns only the outer file-command format and command routing. `TextEditPane` owns editor state and the `sub_58FEF0` format application ABI; the TextPad child records the 12-byte stack payload shape because `SetFont`/`SetColor` construct it locally before calling into the editor.

## Cross-References

- [UID:0000EU][TextPad](by-class/TextPad.md)
- [UID:0001JV][0x00595900-0x00596242.TextPad](by-memory/0x00595900-0x00596242.TextPad.md)
- [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md)
- [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md)
- [UID:0003DY][0x0062e18c-0x0062e228.TextPadVtableData](by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md)
- [UID:0003DZ][0x0062e228-0x0062e268.TextPadCommandStrings](by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md)
- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000OL][TextDialog](by-file/TextDialog.md)
- [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md)

## Score Rationale

Completion `94` reflects a closed seven-method/two-raw-method whole-file inventory, exact code/data/padding boundaries, corrected class declaration and emitter order, exact file envelope, current dependency APIs, compiler/data dispositions, and no hidden TextPad-owned body or data island. Confidence `93` reflects convergent vtable, body, caller, literal, receiver-offset, dependency, and neighboring-owner evidence. The missing external constructor caller, zero inbound references to retained helpers, anomalous shipped `Open` arithmetic, and stripped private spellings prevent a higher score but are exhausted caps rather than deferred blockers.

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `76`.
  - Evidence: document captures full-screen text pad role, command helper behavior, standalone helper island, function map, ownership boundaries, IDA xref/reachability caveats, and cross-references; confidence is capped by no known constructor caller and medium original source placement.
- 2026-06-02: assigned reconstruction path and raised confidence for parent attachment.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank and confidence was capped at `76`.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` and `CONFIDENCE:80`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `TextPad.cpp` under `ui/dialogs`; existing IDA-backed docs keep `TextPad` separate from `TextDialog`, `EditablePaperPane`, terminal, and chat modules. Confidence remains capped at `80` because no constructor caller is known.
- 2026-06-12 A003 Batch 293:
  - Before: scored `84/80`; source placement and behavior were documented, but exact vtable ownership and command-string boundary evidence were not integrated.
  - After: scored `85/85`, retained `NexusTK/ui/dialogs/`.
  - Evidence: live IDA MCP reconfirmed the `TextPad` vtable child, constructor vptr stores, `OnClose`/empty/`OnKeyInput` slots, command helper string refs, and continued absence of direct constructor callers. This supports the source root while preserving the activation caveat and keeping final C++ blank.
- 2026-06-12 A001 Batch 294:
  - Score unchanged at `85/85`; added the corrected command-string child [UID:0003DZ][0x0062e228-0x0062e268.TextPadCommandStrings](by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md).
  - Evidence: live IDA MCP traced all command-prefix xrefs to `TextPadCommandHelper`; byte-range/signature and data-flow checks moved the following `Thread` RTTI pointer out of the TextPad string child.
- 2026-06-14 C001 Goal2 score refresh:
  - Before: score `85/85`.
  - Changed to: score `86/87`.
  - Summary/evidence: live IDA MCP reconfirmed constructor/handler/helper sizes, no direct constructor refs, the single private command-helper caller, no inbound refs to standalone helpers, command-string bytes, vtable-slot refs, and file/text-formatting callee sets. No owner/emitter routing changed; constructor activation and standalone-helper reachability remain the main blockers to a higher score.
- 2026-06-21 B008 Rule 26 source-quality incorporation:
  - Before: `COMPLETION:86`, `CONFIDENCE:87`, with stale generated helper naming and no explicit split-emission policy for child helper bodies.
  - After: `COMPLETION:88`, `CONFIDENCE:89`.
  - Summary/evidence: B008 recheck resolved final method/source-shape names, corrected adjusted secondary-vtable offsets to inherited DialogPane state, documented constructor-internal attach/show route, named retained helper island methods, connected TextPad file commands to TextEditScrap/TextEditPane serialization and PlatformApi `g_pfnCreateFileW`, rejected alternate owners, and recorded which exact by-memory children emit each first-draft C++ body.
- 2026-06-25 B012 standalone helper implementation sync:
  - Score unchanged at `88/89`.
  - Summary/evidence: [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md) is raised to `90/90` with accepted formal C++ and current MCP evidence for file API arguments, no invalid-handle branches, MemoryMan allocation/free wrappers, TextEditScrap duplicate/free behavior, the resolved open-helper payload cursor, zero raw VA pointer-pattern hits, and `sub_58FEF0` format payload offsets. Parent source placement and split-emission policy are unchanged.
- 2026-08-22 B003 UID0000OQ whole-file implementation callback:
  - Before: `88/89`, active prose still used provisional virtual names and dated generated APIs.
  - After: `94/93`, with the complete function/data/padding inventory, corrected three virtual identities, exact emitter order, current dependency/file-format contracts, historical generated comparison, negative evidence, and closed residual caps.
