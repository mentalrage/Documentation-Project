** TARGET-REPORT-UID:000248 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000248 TextPad Standalone File And Insert Helpers Source-Quality Report

Status: FINISHED_IMPLEMENTATION

Agent: B012
Assignment id: `B012-rework-000248-text-pad-standalone-file-and-insert-helpers-20260625`
Target: [UID:000248] `by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md`
Required report path: `tools/leaser/Agents/Agent-B012/research/000248-TextPadStandaloneFileAndInsertHelpers-source-quality.md`

## Executive Recommendation

Keep [UID:000248] as reconstructable TextPad source code owned by [UID:0000OQ] `TextPad` and emitted through `NexusTK/ui/dialogs/TextPad.cpp`. Do not split or move the helper island.

Recommended metadata after implementation:

- `COMPLETION:90`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000OQ`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OQ`

The current source page is mostly right on ownership, range, names, and source placement, but its formal C++ is not source-quality yet. Current live IDA MCP evidence proves these required C++ corrections:

- `Open` and `Save` do not check `INVALID_HANDLE_VALUE`; the current early-return guards are not in the binary.
- `Open` uses `CreateFileW(path, GENERIC_READ, 0, 0, OPEN_EXISTING, 0x08000000, 0)`, not `FILE_SHARE_READ` or `FILE_ATTRIBUTE_NORMAL`.
- `Save` uses `CreateFileW(path, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0x08000000, 0)`, also without an invalid-handle check.
- `Open` allocates through `AllocateBufferMemory`/`sub_516050`, not `new[]`, and the live terminator write is a word write at the file-size-derived wide index, not the current `bytesRead` byte offset.
- `Save` duplicates text and payload buffers and frees those duplicates after writing.
- `SetColor` must pass a format payload base where the color DWORD is at payload offset `+4`; the current `&color` pointer is behaviorally wrong.
- `SetFont` is behaviorally correct only because command/flag `1` reads a WORD at payload offset `+0`.

The score should not go above `90/90` yet because all four starts still have no direct inbound xrefs, the two insert helpers are raw starts rather than IDA functions, and exact source spellings for the helper facades remain inferred.

## Pre-Implementation Target State

Active source page before implementation:

- `COMPLETION:88`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000OQ`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OQ`
- formal C++ present for `TextPad::Open`, `TextPad::Save`, `TextPad::SetFont`, and `TextPad::SetColor`

Valid current target claims to preserve:

- Exact range remains `0x00595f30-0x00596242`.
- Direct owner remains [UID:0000OQ] `TextPad`.
- Source route remains `NexusTK/ui/dialogs/TextPad.cpp`.
- Helper names remain the best source-facing names: `TextPad::Open`, `TextPad::Save`, `TextPad::SetFont`, and `TextPad::SetColor`.
- No direct code/data xrefs are known to the standalone helper starts.
- The standalone helpers mirror the directly reached `TextPad::SendText` command branches at [UID:0001JW].

Pre-implementation target claims to correct:

- The current C++ uses `FILE_SHARE_READ` for `Open`; live code passes share mode `0`.
- The current C++ uses `FILE_ATTRIBUTE_NORMAL`; live code passes `0x08000000`.
- The current C++ adds `INVALID_HANDLE_VALUE` checks in both file helpers; live code has none.
- The current C++ normalizes open-buffer allocation/termination around `bytesRead`; live code allocates `fileSize + 1` bytes and writes the wide terminator from `fileSize`.
- The current C++ treats `SetColor` as a four-byte payload at pointer offset `0`; live `sub_58FEF0` reads command `2` color from pointer offset `+4`.

## Supervisor Active Recheck

Direct instructions followed:

- Used the project-level `ntk-b-agent-workflow` skill.
- Performed report-only work.
- Did not spawn subagents.
- Did not take leases.
- Did not edit by-* docs, generated files, project-level files, validator state/cache, IDA DB state, or any coverage report.
- Used IDA MCP endpoint `http://127.0.0.1:13337/mcp`.

MCP was available and responsive:

- JSON-RPC `initialize` succeeded.
- `tools/list` succeeded.
- `idb_list` returned active database session `80de0a67` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health database=80de0a67` returned `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, strings cache ready, and auto-analysis ready.

The prior B008 report was treated as lead material only. B008 recorded useful local PE/Capstone evidence, but its own MCP attempt was unavailable. This B012 pass rechecked the target against the current live IDA MCP session.

## Evidence Checked

Documentation read-only context:

- Target [UID:000248] `by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md`.
- Parent [UID:0000OQ] `by-file/TextPad.md`.
- Class [UID:0000EU] `by-class/TextPad.md`.
- Containing aggregate [UID:0001JV] `by-memory/0x00595900-0x00596242.TextPad.md`.
- Direct command helper [UID:0001JW] `by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md`.
- Command literal page [UID:0003DZ] `by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md`.
- TextEditPane support pages, including [UID:0000ON] `TextEditPane`, [UID:0000EO] `TextEditPane`, [UID:0001JN] `TextEditPaneSerialization`, and [UID:00040T] `TextEditScrapClipboardCore`.
- PlatformApi/WideApiDispatchTable pages for the `g_pfnCreateFileW` provider route.
- Generated files only as drift symptoms: `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md`.

Generated drift, read-only:

- `auto-generated/-ag-research-tracker.md` still has the stale [UID:000248] row at `76/82`, average `79.0`, not covered.
- `auto-generated/-ag-coverage-report-by-memory.md` still has stale generated coverage for [UID:000248], including old `76`-level state and `emits_code:false`.
- These generated rows should refresh only after supervisor execution and validator/generator refresh. They must not be edited manually.

## Current MCP Findings

### Function Map And Boundaries

`lookup_funcs` in session `80de0a67`:

| Address | Current MCP result | Meaning |
| --- | --- | --- |
| `0x00595f30` | `sub_595F30`, size `0x135` | Modeled `Open` helper. |
| `0x00596070` | `sub_596070`, size `0x158` | Modeled `Save` helper. |
| `0x005961d0` | Not a function | Raw `SetFont` helper start. |
| `0x00596210` | Not a function | Raw `SetColor` helper start. |
| `0x00596250` | `sub_596250`, size `0x1a2` | Successor Thread constructor area, outside this target. |

Boundary padding:

- `0x00595f26-0x00595f30`: ten `0xcc` bytes.
- `0x00596065-0x00596070`: eleven `0xcc` bytes.
- `0x005961c8-0x005961d0`: eight `0xcc` bytes.
- `0x00596204-0x00596210`: twelve `0xcc` bytes.
- `0x00596242-0x00596250`: fourteen `0xcc` bytes.

No split or merge is needed. The exact half-open target range remains stable.

### Xrefs And Pointer-Pattern Evidence

`xref_query` to the standalone helper starts:

- `0x00595f30`: zero xrefs.
- `0x00596070`: zero xrefs.
- `0x005961d0`: zero xrefs.
- `0x00596210`: zero xrefs.

`xref_query` to the command helper start:

- `0x00595be0`: one code xref at `0x00595b64` from `sub_595AF0`.

Raw little-endian VA pattern searches for `0x00595f30`, `0x00596070`, `0x005961d0`, and `0x00596210` returned zero hits. This is negative route evidence only; it supports the no-direct-pointer caveat but does not override the source-shaped helper bodies.

### Open Helper Facts

`decompile 0x00595f30` and disassembly agree on the important source-quality points:

- It constructs a local `TextEditScrap` object.
- It calls the wide API dispatch slot `unk_69BE34` / `g_pfnCreateFileW` with desired access `0x80000000`, share mode `0`, creation disposition `4`, flags `0x08000000`, and template `0`.
- It does not test the returned handle against `INVALID_HANDLE_VALUE`.
- It immediately calls `GetFileSize`, allocates through `sub_516050`, reads through `ReadFile`, writes a wide zero terminator from the file-size-derived index, and calls `CloseHandle`.
- It obtains the embedded edit control through the TextPad/DialogPane path `this+0x1fc`, control id `0`, then the editor at `+0x10c`.
- It loads text into `TextEditScrap`, conditionally loads a secondary payload, selects `0..0x7fff`, pastes the scrap into the editor, resets selection to `0..0`, frees the buffer through `sub_516170`, and destructs the scrap.

Allocator helper check:

- `decompile 0x00516050` confirms `sub_516050` is the raw `malloc(size)` wrapper that throws `Win32Error` on failure.
- `decompile 0x00516170` from existing docs confirms `sub_516170` is `free(block); return 0`.
- Therefore the current target C++ should use the established source-facing allocation helpers `AllocateBufferMemory` and `FreeBufferMemory`, not `new[]` and `delete[]`.

Open payload cursor resolution:

- `decompile 0x00595f30` with address markers reports `sub_5950A0(v7, &v4[v6 + 5], *(_DWORD *)&v4[2 * v6 + 2])` at `0x59600b`.
- The raw instruction sequence confirms the exact expression: `0x595ff9 cmp esi,[ebp+nNumberOfBytesToRead]`, `0x595ffc jnb 0x596010`, `0x595ffe push dword ptr [ebx+esi*2+2]`, `0x596002 lea eax,[ebx+5]`, `0x596005 add eax,esi`, `0x59600a push eax`, `0x59600b call sub_5950A0`.
- Therefore the formal C++ must preserve the observed behavior: after `textChars = wcslen(fileBytes as wchar_t*)`, branch only on `textChars < fileSize`, load payload size from `fileBytes + textChars * sizeof(wchar_t) + sizeof(wchar_t)`, and pass payload source `fileBytes + textChars + sizeof(int) + 1`.
- The replacement code below intentionally does not normalize this into `fileBytes + textChars * sizeof(wchar_t) + sizeof(wchar_t) + sizeof(int)` or add bounds checks. Those would be plausible source cleanup, but not the current executable behavior.

### Save Helper Facts

`decompile 0x00596070` and disassembly agree on these points:

- It constructs a local `TextEditScrap`.
- It obtains the same TextPad/DialogPane embedded edit path through `this+0x1fc`, control id `0`, editor at `+0x10c`.
- It captures selection, selects `0..0x7fff`, copies/serializes text into the scrap, and restores selection.
- It duplicates text and optional payload buffers from `TextEditScrap`.
- It calls `g_pfnCreateFileW` with desired access `0x40000000`, share mode `0`, creation disposition `2`, flags `0x08000000`, and template `0`.
- It does not test the returned handle against `INVALID_HANDLE_VALUE`.
- It writes the text buffer only when text byte count is positive.
- It always writes one zero separator byte.
- It writes the four-byte payload size and payload bytes only when payload size is positive.
- It closes the file and frees duplicated text/payload buffers when they are non-null.

The current target C++ should therefore keep the high-level `TextEditScrap` shape, but it should not omit the duplicate-buffer frees if the formal helper facade returns caller-owned copies.

### TextEditScrap Helper Contracts

Current MCP decompilation of the local TextEditScrap methods supports the helper names used in the formal block:

- `decompile 0x00595050` / `sub_595050`: if length is positive, allocates `2 * length`, stores the text pointer/count fields, and copies `2 * length` bytes. This supports source-facing `TextEditScrap::SetText`.
- `decompile 0x005950a0` / `sub_5950A0`: if size is positive, allocates `size`, stores the payload pointer/count fields, and copies `size` bytes. This supports source-facing `TextEditScrap::SetPayload`.
- `decompile 0x005950e0` / `sub_5950E0`: if text count is positive, allocates `2 * count`, copies the text buffer, writes the caller-owned pointer, and returns the stored count; otherwise writes null and returns zero. This supports source-facing `TextEditScrap::DuplicateText`.
- `decompile 0x00595140` / `sub_595140`: if payload size is positive, allocates `size`, copies the payload, writes the caller-owned pointer, and returns the stored size; otherwise writes null and returns zero. This supports source-facing `TextEditScrap::DuplicatePayload`.

The `Save` formal block intentionally uses the `DuplicateText` return value as the `WriteFile` byte count because live `0x59610a-0x596152` stores that return value as `nNumberOfBytesToWrite` and passes it directly to `WriteFile`. This preserves the existing TextEditScrap packed-length caveat rather than silently converting it to `2 * textChars`.

### Raw Format Insert Helper Facts

`insn_query` over `0x005961d0-0x00596204`:

- Standard prologue and `retn 4`.
- Loads the TextPad control manager from `this+0x1fc`.
- Calls the virtual slot `+0x10` with control id `0`.
- Loads the embedded editor pointer at `+0x10c`.
- Stores the `fontId` WORD into the local payload at offset `+0`.
- Passes command/flag `1` and the local payload base to `sub_58FEF0`.

`insn_query` over `0x00596210-0x00596242`:

- Standard prologue and `retn 4`.
- Loads the same TextPad control manager, control id `0`, and editor pointer.
- Stores the `color` DWORD into a local slot at payload offset `+4`.
- Passes command/flag `2` and the payload base four bytes before the stored color to `sub_58FEF0`.

`decompile 0x0058fef0` confirms the format payload ABI:

- If command/flag bit `1` is set, it reads a WORD at payload offset `+0`.
- If command/flag bit `2` is set, it reads a DWORD at payload offset `+4`.
- If command/flag bit `4` is set, it reads a DWORD at payload offset `+8`.

This proves the current target C++ `SetColor` implementation is wrong. Passing `&color` makes the color appear at offset `+0`, but the callee reads offset `+4`.

### Command Helper Corroboration

The directly reached [UID:0001JW] command helper remains the best behavioral mirror:

- `xrefs_to` on command strings:
  - `0x0062e228`: one data xref at `0x00595c0d`.
  - `0x0062e234`: one data xref at `0x00595d35`.
  - `0x0062e240`: one data xref at `0x00595e79`.
  - `0x0062e254`: one data xref at `0x00595ec5`.
- All command literal xrefs land inside `0x00595be0`.
- `analyze_function 0x00595be0` shows `Open `, `Save `, `SetFont `, and `SetColor ` branches with the same file, scrap, embedded-editor, and format-payload behavior.
- The command helper also lacks invalid-handle checks in its file branches.
- Its `SetColor ` branch stores the parsed color at payload offset `+4` before calling `sub_58FEF0` with command/flag `2`.

This supports the retained-member helper names even though the standalone starts have no direct call route.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:000248] belongs to `TextPad.cpp`. | Strong | All helpers use TextPad/DialogPane `this+0x1fc`, control id `0`, embedded editor `+0x10c`, and mirror TextPad command-helper branches. | TextEditPane, PlatformApi/FileIO, TextDialog, terminal/chat, and no-owner alternatives checked. | No direct standalone-helper xrefs cap confidence. |
| Helper names `Open`, `Save`, `SetFont`, `SetColor` remain best. | Strong | Direct command literals and `SendText` branch semantics use these command names; standalone bodies match the same behavior. | Exact symbol names are not recovered. | Source spelling could differ in capitalization or helper facade names. |
| Current formal C++ must be corrected. | Strong | Live MCP contradicts handle checks, file flags/share mode, open allocation/terminator modeling, save duplicate frees, and SetColor payload offset; B012 rework resolves the open payload cursor to exact instruction-backed offsets. | B008 first-draft code reviewed as lead material; live MCP supersedes stale parts. | Exact original helper/facade names remain inferred, but the formal block chooses source-facing names and preserves behavior. |
| No split is needed. | Strong | Modeled function sizes, raw helper starts, successor start, and `0xcc` separators all match target boundaries. | Adjacent aggregate and Thread successor checked. | None for range. |
| Generic TextEditPane ownership is rejected. | Strong | TextEditPane owns editor internals and format helper ABI; this page owns TextPad command/file methods that consume them. | `sub_58FEF0` and TextEditScrap support docs checked. | Support docs need cross-note for the format payload ABI. |
| Dead/no-code classification is rejected. | Medium-strong | Four source-shaped retained member helpers with exact bodies and valid owner/emitter route. | No xrefs and no raw VA pointer hits are real negative evidence. | Retained/no-route caveat should remain in prose and score cap. |

## Ranked Ownership Analysis

### 1. [UID:0000OQ] TextPad - accepted

Evidence for:

- Uses TextPad/DialogPane control manager at `this+0x1fc`.
- Operates on TextPad's main embedded edit pane.
- Mirrors [UID:0001JW] `TextPad::SendText` command branches.
- `by-file/TextPad.md` already owns the local TextPad command routing and file format.

Evidence against:

- No direct xrefs to any of the standalone helper starts.
- Two insert helpers are not IDA-promoted functions.

Decision: keep as canonical owner and emitter route. The negative route evidence is a score cap, not an ownership blocker.

### 2. [UID:0000ON] TextEditPane - rejected direct owner

Evidence for:

- The helpers call TextEditPane selection, paste/copy, serialization, and `sub_58FEF0` format insertion internals.

Evidence against:

- The bodies are TextPad methods that first navigate through TextPad's control manager and implement TextPad file/command behavior.
- TextEditPane owns the editor internals, not the TextPad command entry points.

Decision: support dependency only. Add a support note for the `sub_58FEF0` payload ABI in TextEditPane documentation.

### 3. PlatformApi / FileIO - rejected direct owner

Evidence for:

- Both file helpers call `g_pfnCreateFileW` through the wide API dispatch table and direct file imports.

Evidence against:

- PlatformApi only provides the dispatch slot. It does not own TextPad file format, editor paste/copy behavior, or command methods.

Decision: provider-only dependency. Existing PlatformApi/WideApiDispatchTable TextPad consumer notes are adequate.

### 4. TextDialog, terminal/chat, generic UI, or no-owner - rejected

Evidence for:

- The no-xref state could be misread as dead code.

Evidence against:

- The embedded control path, command literal mirror, TextEditScrap/TextEditPane payload use, and parent TextPad docs all point to TextPad.

Decision: reject. Preserve the no-xref caveat without downgrading to no-code.

## Range / Split / Padding Analysis

Keep the current target range table:

- `0x00595f30-0x00596065`: modeled `TextPad::Open`, size `0x135`.
- `0x00596070-0x005961c8`: modeled `TextPad::Save`, size `0x158`.
- `0x005961d0-0x00596204`: raw `TextPad::SetFont`, size `0x34`.
- `0x00596210-0x00596242`: raw `TextPad::SetColor`, size `0x32`.

No new child page is needed. No merge into the parent aggregate is needed. No generated or coverage file should be edited manually.

## C++ Readiness

The page should continue to emit first-draft child C++. The active combined-score gate is met, the owner/emitter route is valid, and the live body evidence is strong enough for source-shaped reconstruction.

The current formal block is not implementation-quality without the corrections listed in this report. The implementation callback should replace the existing formal block with the exact content below instead of leaving the B008 draft unchanged.

Important C++ policy:

- Do not introduce raw `sub_` names in the formal block.
- Prefer existing source-facing helper names already validated elsewhere: `AllocateBufferMemory`, `FreeBufferMemory`, `TextEditScrap::SetText`, `TextEditScrap::SetPayload`, and the target's existing TextPad helper facades where still provisional.
- The source-facing `InsertTextObject` facade is inferred as a two-argument wrapper over `sub_58FEF0(command, payload)`, because the live callee takes command/flag plus payload pointer and no size argument.
- The local `TextEditFormatPayload` type is source-facing inferred glue for the live 12-byte stack payload used by `SetFont` and `SetColor`. It preserves the live offsets: font at `+0`, color at `+4`, and a third DWORD-compatible field at `+8`.
- The open helper's odd payload pointer is resolved, not deferred. The formal code intentionally uses `fileBytes + textChars + sizeof(int) + 1` for the payload source because MCP disassembly builds the pointer with `lea eax,[ebx+5]` then `add eax,esi`.

Exact formal replacement for [UID:000248] `RECONSTRUCTION_CPP CODE`:

```cpp
namespace {
struct TextEditFormatPayload
{
    unsigned short fontId;
    unsigned short reserved;
    unsigned int color;
    unsigned int objectId;
};
}

void TextPad::Open(const wchar_t *path)
{
    TextEditScrap scrap;

    HANDLE file = g_pfnCreateFileW(path, GENERIC_READ, 0, 0,
                                   OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, 0);

    DWORD fileSize = GetFileSize(file, 0);
    char *fileBytes = static_cast<char *>(AllocateBufferMemory(fileSize + 1));
    DWORD bytesRead = 0;
    ReadFile(file, fileBytes, fileSize, &bytesRead, 0);
    *reinterpret_cast<wchar_t *>(fileBytes + fileSize * sizeof(wchar_t)) = L'\0';
    CloseHandle(file);

    const wchar_t *text = reinterpret_cast<const wchar_t *>(fileBytes);
    unsigned int textChars = static_cast<unsigned int>(wcslen(text));
    scrap.SetText(text, static_cast<int>(textChars));

    if (textChars < fileSize) {
        int payloadSize = *reinterpret_cast<const int *>(
            fileBytes + textChars * sizeof(wchar_t) + sizeof(wchar_t));
        const char *payload = fileBytes + textChars + sizeof(int) + 1;
        scrap.SetPayload(payload, payloadSize);
    }

    TextEditPane *editor = GetMainTextEditPane();
    editor->SetSelection(0, 0x7fff);
    editor->PasteScrap(scrap);
    editor->SetSelection(0, 0);

    FreeBufferMemory(fileBytes);
}

void TextPad::Save(const wchar_t *path)
{
    TextEditScrap scrap;
    TextEditPane *editor = GetMainTextEditPane();

    int selStart = 0;
    int selEnd = 0;
    editor->GetSelection(&selStart, &selEnd);
    editor->SetSelection(0, 0x7fff);
    editor->CopySelectionToScrap(scrap);
    editor->SetSelection(selStart, selEnd);

    wchar_t *textBuffer = 0;
    int textBytes = scrap.DuplicateText(&textBuffer);
    void *payloadBuffer = 0;
    int payloadBytes = scrap.DuplicatePayload(&payloadBuffer);

    HANDLE file = g_pfnCreateFileW(path, GENERIC_WRITE, 0, 0,
                                   CREATE_ALWAYS, FILE_FLAG_SEQUENTIAL_SCAN, 0);

    DWORD written = 0;
    if (textBytes > 0) {
        WriteFile(file, textBuffer, textBytes, &written, 0);
    }

    unsigned char separator = 0;
    WriteFile(file, &separator, 1, &written, 0);

    if (payloadBytes > 0) {
        WriteFile(file, &payloadBytes, sizeof(payloadBytes), &written, 0);
        WriteFile(file, payloadBuffer, payloadBytes, &written, 0);
    }

    CloseHandle(file);

    if (textBuffer != 0) {
        FreeBufferMemory(textBuffer);
    }
    if (payloadBuffer != 0) {
        FreeBufferMemory(payloadBuffer);
    }
}

void TextPad::SetFont(unsigned short fontId)
{
    TextEditFormatPayload format;
    format.fontId = fontId;
    GetMainTextEditPane()->InsertTextObject(1, &format);
}

void TextPad::SetColor(unsigned int color)
{
    TextEditFormatPayload format;
    format.color = color;
    GetMainTextEditPane()->InsertTextObject(2, &format);
}
```

## Score And Metadata Recommendation

Recommended target metadata after implementation:

- `COMPLETION:90`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000OQ`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OQ`

Rationale:

- Completion rises because this pass uses current live MCP, corrects concrete formal-C++ defects, records the format-payload ABI, tightens file API arguments, and clears stale generated-vs-source drift.
- Confidence rises slightly because the behavior, boundaries, and source route are now rechecked live instead of relying on B008's MCP-unavailable report.
- Confidence remains capped because direct xrefs are still absent, two helper starts remain raw, direct original symbols are not recovered, and some high-level helper facade names remain source-facing inferences.

## Recommended Target Doc Changes

Target path: `by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md`.

Required metadata/header changes:

- Change `COMPLETION:88` to `COMPLETION:90`.
- Change `CONFIDENCE:89` to `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000OQ`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000OQ`.

Required formal C++ replacement:

- Replace the entire existing [UID:000248] formal `RECONSTRUCTION_CPP CODE` body with the exact block in this report's `C++ Readiness` section.
- The replacement block is implementation-ready and resolves the prior rejection: it supplies complete formal content for `TextPad::Open`, `TextPad::Save`, `TextPad::SetFont`, and `TextPad::SetColor`.
- The `Open` body intentionally preserves the live payload behavior: payload size from `fileBytes + textChars * sizeof(wchar_t) + sizeof(wchar_t)` and payload source from `fileBytes + textChars + sizeof(int) + 1`.
- The `Save` body intentionally preserves the live duplicated text/payload buffer ownership and post-write frees.
- The `SetFont` and `SetColor` bodies intentionally use the inferred 12-byte `TextEditFormatPayload` so command/flag `1` reads font at offset `+0` and command/flag `2` reads color at offset `+4`.

Required evidence/prose additions:

- Add the B012 live MCP provenance: endpoint `http://127.0.0.1:13337/mcp`, database session `80de0a67`, Hex-Rays ready, module `NexusTK.exe`.
- Add the no-xref recheck for all four starts and the zero raw VA pointer-pattern hits.
- Add the exact `sub_58FEF0` payload ABI: bit `1` reads `WORD +0`, bit `2` reads `DWORD +4`, bit `4` reads `DWORD +8`.
- Add the current `CreateFileW` argument correction for both file helpers.
- Add a note that B008's first-draft C++ is superseded in these specific areas by B012 live MCP evidence.
- Add the open payload cursor resolution with instruction anchors `0x595ffe`, `0x596002`, `0x596005`, `0x59600a`, and `0x59600b`.
- Keep the no-direct-xref/no-direct-route caveat.
- Keep TextPad ownership and reject TextEditPane/FileIO/PlatformApi/no-code alternatives.

Recommended replacement item summary:

`Parent-attached standalone TextPad file-open/file-save/text-insert helper island; B012 live MCP confirms exact boundaries, no direct xrefs, TextPad embedded-editor ownership, file API argument details, no invalid-handle branches, TextEditScrap duplication/free behavior, and sub_58FEF0 format payload offsets requiring SetColor color at payload +4.`

## Recommended Support Doc Changes

`by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md`:

- Add a B012 source-quality sync note that live MCP confirms the same no-invalid-handle file behavior and the same `SetColor` format payload offset `+4` in the command helper.
- Keep `SendText` as the direct routed command helper; do not claim it directly calls the standalone starts.

`by-memory/0x00595900-0x00596242.TextPad.md`:

- Add a short note that [UID:000248] remains the child emitter for retained `Open`/`Save`/`SetFont`/`SetColor`, with B012 correcting the child formal C++.
- Keep split-emission policy unchanged.

`by-file/TextPad.md` and `by-class/TextPad.md`:

- Add a support note that B012 live MCP revalidated the retained helper island and corrected the formal child C++ requirements: no file-handle guards, `0x08000000` file flags, allocation/free helpers, and `SetColor` payload offset `+4`.
- Do not raise parent scores solely because of this target unless the supervisor wants a broader TextPad pass.

`by-file/TextEditPane.md` and/or `by-class/TextEditPane.md`:

- Add a concise support note for the `sub_58FEF0` format payload ABI consumed by TextPad: command/flag `1` reads font at offset `+0`, command/flag `2` reads color at offset `+4`, and command/flag `4` reads the third DWORD at offset `+8`.
- No score change is required for TextEditPane from this TextPad report.

`by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md` and `by-memory/0x00594f30-0x00595389.TextEditScrapClipboardCore.md`:

- No required ownership changes.
- Optional cross-note only if implementation wants to clarify TextPad outer-file format versus TextEditPane/TextEditScrap inner payload serialization.

PlatformApi/WideApiDispatchTable docs:

- Existing provider-only notes are adequate. No required edit unless the implementation callback wants to add the exact `0x08000000` TextPad consumer flag detail.

Generated files:

- Do not edit generated files manually.
- After source-doc implementation and scoped validation/generation, generated [UID:000248] research and coverage rows should refresh from source metadata and report execution state.

## Implementation Result

Implemented on 2026-06-25 by B012 against the accepted report. [UID:000248] is now `90/90`, the formal C++ block is replaced with the exact `C++ Readiness` reconstruction, and support notes were added to the listed TextPad/TextEditPane docs without changing parent scores.

Scoped validators were run from `source-3/project-documentation` with `--mode file --apply --wait-generated`. All returned exit code `0`, `ok: 1`, and `generated_refresh: completed`.

Note: the validator-owned memory coverage refresh reused the stale summary from forbidden manual coverage file `by-memory/-coverage-report.md` and rewrote the target `Item Summary`. B012 did not edit that `-coverage-report.md`; the accepted B012 item summary was reapplied only in the target by-* source doc after validation.

Final non-mutating target dry run after that summary reapply: command `000000001151`, timestamp `2026-06-25T03:56:51-04:00`, exit `0`, `ok: 1`, `apply: False`, `generated_refresh: would-defer`.

Correction on 2026-06-25 after supervisor verification rejection: the target `Item Summary` was replaced again with the accepted B012 summary, then scoped validation was run from `source-3/project-documentation` in non-mutating mode with generated refresh skipped to avoid reapplying the stale manual coverage default. Validator command `000000001196`, timestamp `2026-06-25T04:20:57-04:00`, exit `0`, `ok: 1`, `apply: False`, `generated_refresh: skipped`. Post-validation inspection confirmed the accepted summary remains in the target by-* doc.

## Implementation Checklist

- [x] Update [UID:000248] header to `COMPLETION:90`, `CONFIDENCE:90`, keeping owner/emitter/reconstructable metadata unchanged. Proof: `by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md` now has `COMPLETION:90`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000OQ`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000OQ`.
- [x] Update [UID:000248] `Item Summary` with the recommended B012 summary or equivalent content. Proof: target summary now records B012 live MCP boundaries, no direct xrefs, file API details, no invalid-handle branches, TextEditScrap duplicate/free behavior, and `sub_58FEF0` offset behavior; after the 2026-06-25 correction, scoped validator command `000000001196` returned exit `0`, `ok: 1`, `generated_refresh: skipped`, and a post-validation `rg` check confirmed the accepted summary remains in `by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md`.
- [x] Update [UID:000248] MCP evidence with session `80de0a67`, endpoint `http://127.0.0.1:13337/mcp`, current function map, no-xref results, raw VA pattern negative results, and exact padding checks. Proof: target `IDA MCP Evidence` now includes endpoint/session/module/imagebase, modeled/raw function starts, zero xrefs and zero raw VA pointer-pattern hits, and exact `0xcc` padding sizes.
- [x] Replace [UID:000248] formal `RECONSTRUCTION_CPP CODE` with the exact replacement block in this report's `C++ Readiness` section. Proof: target formal block now contains `TextEditFormatPayload`, corrected `Open`, `Save`, `SetFont`, and `SetColor` bodies exactly from this report.
- [x] In [UID:000248] reconstruction notes, preserve the open-helper payload cursor resolution: `0x595ffe` length from `[ebx+esi*2+2]`, `0x596002` `lea eax,[ebx+5]`, `0x596005` `add eax,esi`, and `0x59600b` `sub_5950A0` call. Proof: target evidence and reconstruction notes record those instruction anchors and the intentionally odd pointer math.
- [x] In [UID:000248] reconstruction notes, document that the replacement block intentionally has no file-handle validity guards, uses `FILE_FLAG_SEQUENTIAL_SCAN`, uses `AllocateBufferMemory`/`FreeBufferMemory`, and keeps the TextEditScrap packed-length caveat for `Save`. Proof: target C++ and notes record no invalid-handle guards, `FILE_FLAG_SEQUENTIAL_SCAN`, MemoryMan wrappers, and direct `DuplicateText` count use in `WriteFile`.
- [x] In [UID:000248] reconstruction notes, document the TextEditScrap helper contracts verified at `0x00595050`, `0x005950a0`, `0x005950e0`, and `0x00595140`, especially that `Save` passes the `DuplicateText` return value directly to `WriteFile`. Proof: target `IDA MCP Evidence` lists each helper contract and the `DuplicateText`/`WriteFile` relationship.
- [x] In [UID:000248] reconstruction notes, document that `TextEditFormatPayload` is an inferred source-facing 12-byte payload whose offsets match `sub_58FEF0`. Proof: target evidence and notes describe the inferred 12-byte stack payload with font `+0`, color `+4`, and object/id `+8`.
- [x] Add the `sub_58FEF0` payload ABI note to [UID:000248] reconstruction notes. Proof: target notes record command bit `1` reads `WORD +0`, bit `2` reads `DWORD +4`, and bit `4` reads `DWORD +8`.
- [x] Add a B012 source-quality sync note to [UID:0001JW] `TextPadCommandHelper` for the no-invalid-handle behavior and `SetColor` payload offset `+4`. Proof: `by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md` now has a 2026-06-25 B012 sync note and change entry.
- [x] Add a B012 child-correction note to [UID:0001JV] `TextPad` aggregate while preserving split-emission policy. Proof: `by-memory/0x00595900-0x00596242.TextPad.md` now has a B012 child-correction note, updated summary wording, and unchanged `88/89` score.
- [x] Add concise support notes to `by-file/TextPad.md` and `by-class/TextPad.md`; keep parent ownership and scores unless a broader parent audit is done. Proof: both TextPad support docs now record the B012 standalone-helper sync and remain at `88/89`.
- [x] Add the `sub_58FEF0` format payload ABI support note to TextEditPane documentation, preferably `by-file/TextEditPane.md` and/or `by-class/TextEditPane.md` because there is no exact dedicated `sub_58FEF0` by-memory page. Proof: both `by-file/TextEditPane.md` and `by-class/TextEditPane.md` now record the format payload ABI and TextPad/TextEdit ownership split.
- [x] Do not manually edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, generated C++ output, manual coverage reports, validator state/cache, or IDA DB state. Proof: manual edits were limited to the seven listed by-* docs and this Agent-B012 report; generated/project/validator updates observed in command output were validator-owned side effects from required `--wait-generated` runs.
- [x] After source-doc edits, run the scoped validator/generator flow expected by the supervisor with generated refresh enabled so [UID:000248] stale generated rows update from source state. Proof: validators were run with `--mode file --apply --wait-generated`; all returned exit `0`, `ok: 1`, and `generated_refresh: completed`: target `000000001100` at `2026-06-25T03:52:14-04:00`; command helper `000000001110` at `03:52:43`; aggregate `000000001113` at `03:52:54`; `by-file/TextPad.md` `000000001114` at `03:53:04`; `by-class/TextPad.md` `000000001117` at `03:53:18`; `by-file/TextEditPane.md` `000000001119` at `03:53:31`; `by-class/TextEditPane.md` `000000001121` at `03:53:41`.
- [x] Supervisor should execute this B012 report against target `000248` so the research tracker records coverage for the exact target UID. Proof: supervisor-owned lifecycle action remains documented; B012 did not run `execute-report`. Validator-owned `research_tracker_update` entries appeared during scoped validation/generation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/000248-TextPadStandaloneFileAndInsertHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/000248-TextPadStandaloneFileAndInsertHelpers-source-quality.md","timestamp":"2026-06-25T04:24:32","uid":"000248"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
