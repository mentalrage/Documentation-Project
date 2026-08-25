** TARGET-REPORT-UID:0001JV **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B008 Report - [UID:0001JV] TextPad Source Quality

Status: FINISHED  
Date: 2026-06-19  
Agent: B008  
Target: `source-3/project-documentation/by-memory/0x00595900-0x00596242.TextPad.md`  
Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/0001JV-TextPad-source-quality.md`

This is report-only. I did not edit any `by-*` documentation and did not edit `by-memory/-coverage-report.md`.

## Summary Recommendation

Raise [UID:0001JV] from `85/86` to `COMPLETION:88`, `CONFIDENCE:89`, keeping `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000OQ`, and `EMITTER_UIDS:0000OQ`.

The old no-code reason is stale. The active code gate is satisfied and the target has source-ready authored methods, but the aggregate overlaps two exact child pages:

- [UID:0001JW] `0x00595be0-0x00595f26.TextPadCommandHelper.md`
- [UID:000248] `0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md`

Recommended emission policy:

- [UID:0001JV] should emit the aggregate/class-facing non-child methods: `TextPad::TextPad()`, the secondary-view enter-key handler, `TextPad::OnClose()`, and the empty virtual.
- [UID:0001JW] should emit the private command dispatcher body as `TextPad::SendText(const wchar_t *commandLine)`.
- [UID:000248] should emit the retained out-of-line member helper bodies as `TextPad::Open(const wchar_t *path)`, `TextPad::Save(const wchar_t *path)`, `TextPad::SetFont(unsigned short fontId)`, and `TextPad::SetColor(unsigned int color)`.

This avoids duplicate C++ bodies while still moving all source-authored behavior out of raw decompiler status.

## Evidence Checked

Documentation read or reconciled:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B008/goal.md`
- `tools/leaser/Agents/Supervisor/inference_research.md`
- `by-memory/0x00595900-0x00596242.TextPad.md`
- `by-file/TextPad.md`
- `by-class/TextPad.md`
- `by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md`
- `by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md`
- `by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md`
- `by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md`
- `by-file/TextEditPane.md`
- `by-class/TextEditPane.md`
- `by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md`
- `by-item/EncodeTextEditState_0058E490.md`
- `by-file/TextEditControlPane.md`
- `by-memory/0x004988d0-0x00498dd0.TextEditControlPaneCore.md`
- `by-file/DialogPane.md`
- `by-type/by-struct/DialogPaneLayout.md`
- `by-class/TextEditScrap.md`
- `by-memory/0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane.md`
- `by-global/g_pScreenPane.md`
- `by-global/MainUiLayerSlots.md`
- `by-global/WideApiDispatchTable.md`
- `by-file/PlatformApi.md`
- Executed B003 Thread read-only-data report that confirms the successor boundary at `0x0062e268`.

Binary/local evidence checked:

- Local PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`.
- `.text`: `0x00401000-0x0060c600`; `.rdata`: `0x0060d000-0x0066c200`; `.data`: `0x0066d000-0x0069ce24`.
- Local Capstone disassembly and byte/xref scans for `0x00595900-0x00596242`.
- PE import scan for file APIs.
- Immediate/dword scans for vtables, command strings, and helper starts.
- IDA MCP was attempted at `http://127.0.0.1:13337/mcp` but unavailable in this session, so the report uses existing IDA-derived docs plus local PE/Capstone validation.

## Bounds, Padding, And References

Confirmed text cluster boundaries:

- Preceding padding before the target: `0x005958fe-0x00595900`, bytes `cc cc`.
- Constructor: `0x00595900-0x00595ae2`; padding to next function: `0x00595ae2-0x00595af0`, 14 `cc` bytes.
- Enter-key virtual handler: `0x00595af0-0x00595ba9`; padding: `0x00595ba9-0x00595bb0`, 7 `cc` bytes.
- Close/hide virtual handler: `0x00595bb0-0x00595bcf`; padding: `0x00595bcf-0x00595bd0`, 1 `cc` byte.
- Empty/null virtual: `0x00595bd0-0x00595bd1`; padding: `0x00595bd1-0x00595be0`, 15 `cc` bytes.
- Command helper child: `0x00595be0-0x00595f26`; padding: `0x00595f26-0x00595f30`, 10 `cc` bytes.
- Standalone open helper: `0x00595f30-0x00596065`; padding: `0x00596065-0x00596070`, 11 `cc` bytes.
- Standalone save helper: `0x00596070-0x005961c8`; padding: `0x005961c8-0x005961d0`, 8 `cc` bytes.
- Raw font insert helper: `0x005961d0-0x00596204`; padding: `0x00596204-0x00596210`, 12 `cc` bytes.
- Raw color insert helper: `0x00596210-0x00596242`; successor padding: `0x00596242-0x00596250`, 14 `cc` bytes.

Reference evidence:

- No direct rel32 or data-pointer references were found to `0x00595900` (`TextPad::TextPad()`).
- `0x00595af0` is referenced by TextPad vtable data at `0x0062e1f8`.
- `0x00595bb0` is referenced by TextPad vtable data at `0x0062e1e0`.
- `0x00595bd0` is referenced by TextPad vtable data at `0x0062e1e4`.
- `0x00595be0` has one direct code caller at `0x00595b64`, inside the enter-key handler.
- No direct rel32 or dword references were found to the standalone helper starts `0x00595f30`, `0x00596070`, `0x005961d0`, or `0x00596210`.
- Constructor vtable stores hit `0x0062e190`, `0x0062e1f0`, and `0x0062e220` at `0x00595942`, `0x0059594c`, and `0x00595956`.
- Command strings are only consumed by the command dispatcher:
  - `0x0062e228`: `L"Open "`, referenced at `0x00595c0e`.
  - `0x0062e234`: `L"Save "`, referenced at `0x00595d36`.
  - `0x0062e240`: `L"SetFont "`, referenced at `0x00595e7a`.
  - `0x0062e254`: `L"SetColor "`, referenced at `0x00595ec6`.
- `0x0062e268` is not a TextPad tail; it starts the next read-only-data owner, Thread RTTI, as confirmed by existing executed research.

## Source Shape And Names

### Constructor

Recommended source name/signature:

```cpp
TextPad::TextPad()
```

Evidence and behavior:

- Calls `DialogPane::DialogPane` at `0x0049d8a0` with empty title string `0x0060db20`, id/config `-1`, and mode `0`.
- Stores the three TextPad vtables immediately after the base constructor call.
- Uses `g_screenWidth` at `0x0066da94` and `g_screenHeight` at `0x0066da98` to build a large top editor rectangle and a 32-pixel bottom command-input rectangle.
- Allocates two `TextEditControlPane` objects of size `0x114` and calls `TextEditControlPane` construction at `0x00498920`.
- Adds the controls through the DialogPane/control-manager helper at `0x0049dc10`.
- Sets the main editor limits to `2000` lines (`0x7d0`) and `30000` characters (`0x7530`) through `TextEditControlPane` helper calls at `0x00498be0` and `0x00498bd0`.
- Writes byte `+0x100` on the main `TextEditControlPane`; best source-facing field name is provisional `m_readOnly` or `m_acceptsInput` state. The role is a mode flag on the large editor, not a TextPad field.
- Builds a full-screen dialog rectangle and calls DialogPane lifecycle helpers including `0x0049dfd0` and `0x0049e190`, passing the main UI layer slot and `g_pScreenPane`.

Open issue resolution:

- The external constructor caller remains unresolved. Local direct rel32 and data-pointer scans did not find a caller or factory reference.
- Constructor activation is partly resolved: once a `TextPad` instance exists, the constructor itself attaches/shows the dialog through the main UI/screen route. The remaining uncertainty is the allocation/creation entrypoint, not the internal show path.

### Enter-Key Handler

Recommended source name/signature:

```cpp
bool TextPad::OnKeyInput(InputEvent *event)
```

Evidence and behavior:

- Vtable-reached through the secondary DialogPane/view subobject at `0x0062e1f8`.
- The binary's `ecx` is adjusted by `+0xa0`; offsets read as `this+0x174` and `this+0x15c` in raw disassembly are primary-object offsets `+0x214` and `+0x1fc`.
- `+0x1fc` is the inherited DialogPane control manager/control list pointer. Do not document it as a new TextPad field.
- `+0x214` is best named `DialogPane::m_activeControlId` or `DialogPane::m_currentControlId`; the handler requires it to be `1`, the bottom command input control.
- Calls EventMan key translation through `g_pEventMan` (`0x0067a754`) and checks key `13` plus event type byte `8`.
- Obtains control id `1`, calls the `TextEditControlPane` read-text forwarder at `0x00498c10` with max `0x3ff`, passes the buffer to `TextPad::SendText`, then selects `0..0x7fff` in the input editor through `TextEditPane::SetSelection` at `0x0058f2a0`.
- Falls back to `DialogPane::OnKeyInput` at `0x0049e6e0` otherwise.

### Close/Hide Handler

Recommended source name/signature:

```cpp
void TextPad::OnClose()
```

Evidence and behavior:

- Vtable-reached through primary TextPad vtable slot `0x0062e1e0`.
- Calls UI helper `0x004b9660` with argument `0x80`, clears byte `this+0x70`, then invalidates/refreshes the rectangle at `this+0x44` through indirect global slot `0x0069b3fc`.
- Best source meaning is a close/hide handler for the dialog, not a destructor and not file-save logic.

### Empty Virtual

Recommended source name/signature:

```cpp
void TextPad::OnEmptyVirtual()
```

Evidence and behavior:

- Vtable-reached through `0x0062e1e4`.
- Body is one `ret`.
- This should be documented as an intentionally empty override or placeholder vtable method. It is source-authored only in the weak sense that it occupies a TextPad virtual slot; it should not receive invented behavior.

### Command Dispatcher

Recommended source name/signature for [UID:0001JW]:

```cpp
void TextPad::SendText(const wchar_t *commandLine)
```

Rationale:

- Raw/generated name `TextPad_SendText` should not remain unresolved.
- The function is `thiscall`; `ecx` is the primary `TextPad *`.
- Its only known caller is the enter-key path at `0x00595b64`.
- It dispatches based on line-prefix commands that the bottom input control supplies, so `SendText` matches the existing label and source role better than a free helper name. `ExecuteCommand` is a reasonable descriptive alternative, but the best-supported final name is `TextPad::SendText`.

Behavior:

- Tests prefixes using `wcsstr(commandLine, prefix) == commandLine`, not arbitrary substring dispatch.
- `Open ` skips 5 UTF-16 characters and loads a file into a `TextEditScrap`, then pastes/loads it into the main editor.
- `Save ` skips 5 UTF-16 characters and serializes the full main editor contents through `TextEditScrap`.
- `SetFont ` skips 8 UTF-16 characters, parses an integer with the shared wide integer parser/format string at `0x00610660`, truncates to `unsigned short`, and inserts command id `1` through the main `TextEditPane`.
- `SetColor ` skips 9 UTF-16 characters, parses an integer, and inserts a 4-byte/two-UTF-16-unit color payload with command id `2`.

### Standalone Helper Island

Recommended source names/signatures for [UID:000248]:

```cpp
void TextPad::Open(const wchar_t *path);
void TextPad::Save(const wchar_t *path);
void TextPad::SetFont(unsigned short fontId);
void TextPad::SetColor(unsigned int color);
```

Evidence:

- `0x00595f30` is a modeled function-shaped open helper that mirrors the command helper's `Open ` branch but takes the path directly from `[ebp+8]`.
- `0x00596070` is a modeled function-shaped save helper that mirrors the command helper's `Save ` branch but takes the path directly from `[ebp+8]`.
- `0x005961d0` is a raw helper start that takes a word argument, gets main control id `0`, reaches the embedded `TextEditPane` at `+0x10c`, and calls the insert helper at `0x0058fef0` with command id `1`.
- `0x00596210` is a raw helper start that takes a dword argument, gets main control id `0`, reaches the embedded `TextEditPane` at `+0x10c`, and calls the insert helper at `0x0058fef0` with command id `2`.
- All four starts have no direct code/data xrefs in local PE scans. Therefore they are best treated as retained out-of-line TextPad member helpers whose logic is duplicated or inlined into `SendText` for this build, not as proven live routes.

Rejected alternatives:

- Generic TextEditPane ownership: rejected because each helper reaches the main control through the TextPad/DialogPane control manager at primary `+0x1fc`.
- Generic FileIO/PlatformApi ownership: rejected because `CreateFileW` is only a platform dependency. The bodies are UI/editor commands owned by TextPad.
- Exact dead-code/no-code classification: rejected as too strong. The functions are coherent source-authored TextPad methods in the same island, even though they lack direct xrefs.

## Field, Global, Helper, And Type Recommendations

TextPad/DialogPane fields:

- `DialogPane::m_controlManager` or `DialogPane::m_controls` at primary `+0x1fc`; the enter-key handler raw `this+0x15c` is this same field through the secondary adjusted `this`.
- `DialogPane::m_activeControlId` or `DialogPane::m_currentControlId` at primary `+0x214`; the enter-key handler raw `this+0x174` is this field through the secondary adjusted `this`.
- No new TextPad-owned field should be invented for either offset.

Control ids:

- Main text/editor control: id `0`.
- Bottom command-input control: id `1`.

TextEditControlPane/TextEditPane:

- `TextEditControlPane` embedded editor field remains at `+0x10c`.
- Main editor max line count is `2000`.
- Main editor max text length is `30000`.
- The main-control byte at `+0x100` is a control-mode flag; best provisional name is `TextEditControlPane::m_readOnly` or `m_acceptsInput`. Leave exact name provisional until nearby TextEditControlPane methods resolve it.

TextEditScrap:

- Use existing `TextEditScrap` names from support docs:
  - text length at `+0x004`
  - text buffer at `+0x008`
  - payload size at `+0x00c`
  - payload buffer at `+0x010`
- TextPad Open/Save depends on `TextEditScrap` to carry both user-visible text and secondary rich-text/editor payload.

Globals and imports:

- `g_screenWidth` at `0x0066da94`.
- `g_screenHeight` at `0x0066da98`.
- `g_pEventMan` at `0x0067a754`.
- `g_pScreenPane` at `0x0067a7cc`.
- Main UI layer/context slot through `0x0069b368`.
- `0x0069be34` should be named through the existing platform support as `g_pfnCreateFileW` or `WideApiDispatchTable::CreateFileW`, not as an anonymous raw dword.
- Direct imports used by the TextPad file helpers:
  - `0x0060d1c0`: `GetFileSize`
  - `0x0060d1c4`: `ReadFile`
  - `0x0060d10c`: `WriteFile`
  - `0x0060d110`: `CloseHandle`

Text serialization:

- `TextEditPaneSerialization` at `0x0058e490` remains the owner for the rich editor state encoder.
- The serialized rich payload includes raw text data, delimiter byte `0`, marker `0x6b6f6e67` (`"kong"`), and three length-prefixed state/style payload tables from TextEditPane fields `+0x138`, `+0x13c`, and `+0x140`.
- TextPad's file format wraps the `TextEditScrap` output: visible UTF-16 text, a one-byte zero separator, optional 32-bit payload byte length, and optional payload bytes. The optional payload is the TextEditPane/TextEditScrap rich state, not a separate TextPad-native format.
- Exact byte/unit pointer math in the open branch should remain documented as decompiler-sensitive, but the source-level ownership and format relationship are resolved.

## Source Placement

Keep canonical owner/emitter [UID:0000OQ] `by-file/TextPad.md`, source route `NexusTK/ui/dialogs/TextPad.cpp`.

Do not reassign to:

- `TextEditPane.cpp`: TextEditPane supplies editor state and insertion helpers, but TextPad owns command routing and file UI.
- `TextEditControlPane.cpp`: TextPad uses controls, but this is not a control implementation body.
- `PlatformApi.cpp` or generic FileIO: the platform dispatch table is only used for file open/create.
- TextDialog, EditablePaperPane, terminal/chat, or menu files: no support evidence ties the command prefixes or vtables to those owners.

## First-Draft C++ Readiness

First-draft source is appropriate. The target is reconstructable, has a valid emitter, and is over the active score gate. The remaining uncertainty is naming/route precision, not no-code proof.

Recommended [UID:0001JV] aggregate formal C++ should avoid duplicating [UID:0001JW] and [UID:000248] child bodies. A source-style first draft for the non-child methods is:

```cpp
TextPad::TextPad()
    : DialogPane(L"", -1, 0)
{
    RectBounds mainBounds(0, 0, g_screenWidth, g_screenHeight - 32);
    TextEditControlPane *mainEdit =
        new TextEditControlPane(L"", mainBounds, 0x80, 0x8f, 1.0f);
    AddControl(0, mainEdit);
    mainEdit->SetMaxLines(2000);
    mainEdit->SetMaxLength(30000);
    mainEdit->SetReadOnly(true);

    RectBounds inputBounds(0, g_screenHeight - 32, g_screenWidth, g_screenHeight);
    TextEditControlPane *commandEdit =
        new TextEditControlPane(L"", inputBounds, 0, 0x8f, 1.0f);
    AddControl(1, commandEdit);

    RectBounds frameBounds(0, 0, g_screenWidth, g_screenHeight);
    CreateClientPane(0);
    SetBounds(frameBounds);
    OnCreate(frameBounds, 0, 0, g_mainUiLayerSlot);
    OnShow(g_pScreenPane, 0);
}

bool TextPad::OnKeyInput(InputEvent *event)
{
    if (EventMan::TranslateKey(event) == 13 &&
        m_activeControlId == 1 &&
        event->type == 8) {
        wchar_t commandLine[1024];
        TextEditControlPane *commandEdit =
            static_cast<TextEditControlPane *>(GetControl(1));

        commandEdit->GetText(commandLine, 1023);
        SendText(commandLine);
        commandEdit->GetTextEditPane()->SetSelection(0, 0x7fff);
        return true;
    }

    return DialogPane::OnKeyInput(event);
}

void TextPad::OnClose()
{
    HideChrome(0x80);
    m_visible = false;
    InvalidateRect(m_bounds);
}

void TextPad::OnEmptyVirtual()
{
}
```

Notes on this draft:

- `AddControl`, `CreateClientPane`, `SetBounds`, `OnCreate`, `OnShow`, `HideChrome`, and `InvalidateRect` are source-facing names for known DialogPane/UI helpers. Exact local naming should follow the existing DialogPane implementation when applied.
- `TextEditControlPane` constructor flags are intentionally source-style. Do not preserve raw push order as the source block.
- `m_activeControlId` is inherited DialogPane state at primary `+0x214`, not a TextPad field.
- The real handler is reached through the secondary adjusted vtable; source should still be written as a normal `TextPad` virtual override.

Recommended [UID:0001JW] child C++:

```cpp
static bool TextPadCommandStartsWith(const wchar_t *text, const wchar_t *prefix)
{
    return text != 0 && wcsstr(text, prefix) == text;
}

void TextPad::SendText(const wchar_t *commandLine)
{
    if (TextPadCommandStartsWith(commandLine, L"Open ")) {
        Open(commandLine + 5);
        return;
    }

    if (TextPadCommandStartsWith(commandLine, L"Save ")) {
        Save(commandLine + 5);
        return;
    }

    if (TextPadCommandStartsWith(commandLine, L"SetFont ")) {
        int fontId = 0;
        swscanf(commandLine + 8, L"%d", &fontId);
        SetFont(static_cast<unsigned short>(fontId));
        return;
    }

    if (TextPadCommandStartsWith(commandLine, L"SetColor ")) {
        int color = 0;
        swscanf(commandLine + 9, L"%d", &color);
        SetColor(static_cast<unsigned int>(color));
    }
}
```

Recommended [UID:000248] child C++:

```cpp
void TextPad::Open(const wchar_t *path)
{
    HANDLE file = g_pfnCreateFileW(path, GENERIC_READ, FILE_SHARE_READ,
                                   0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (file == INVALID_HANDLE_VALUE) {
        return;
    }

    DWORD fileSize = GetFileSize(file, 0);
    char *fileBytes = new char[fileSize + sizeof(wchar_t)];
    DWORD bytesRead = 0;
    ReadFile(file, fileBytes, fileSize, &bytesRead, 0);
    CloseHandle(file);

    fileBytes[bytesRead] = 0;
    fileBytes[bytesRead + 1] = 0;

    TextEditScrap scrap;
    const wchar_t *text = reinterpret_cast<const wchar_t *>(fileBytes);
    scrap.SetText(text);

    size_t textBytes = wcslen(text) * sizeof(wchar_t);
    const char *payloadCursor = fileBytes + textBytes + 1;
    if (payloadCursor + sizeof(int) <= fileBytes + bytesRead) {
        int payloadSize = *reinterpret_cast<const int *>(payloadCursor);
        payloadCursor += sizeof(int);
        if (payloadSize > 0 && payloadCursor + payloadSize <= fileBytes + bytesRead) {
            scrap.SetPayload(payloadCursor, payloadSize);
        }
    }

    TextEditPane *editor = GetMainTextEditPane();
    editor->SetSelection(0, 0x7fff);
    editor->PasteScrap(scrap);
    editor->SetSelection(0, 0);

    delete [] fileBytes;
}

void TextPad::Save(const wchar_t *path)
{
    TextEditPane *editor = GetMainTextEditPane();

    int selStart = 0;
    int selEnd = 0;
    editor->GetSelection(&selStart, &selEnd);
    editor->SetSelection(0, 0x7fff);

    TextEditScrap scrap;
    editor->CopySelectionToScrap(scrap);
    editor->SetSelection(selStart, selEnd);

    int textBytes = 0;
    const void *text = scrap.GetText(&textBytes);
    int payloadBytes = 0;
    const void *payload = scrap.GetPayload(&payloadBytes);

    HANDLE file = g_pfnCreateFileW(path, GENERIC_WRITE, 0, 0,
                                   CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
    if (file == INVALID_HANDLE_VALUE) {
        return;
    }

    DWORD written = 0;
    if (textBytes > 0) {
        WriteFile(file, text, textBytes, &written, 0);
    }

    const unsigned char separator = 0;
    WriteFile(file, &separator, sizeof(separator), &written, 0);

    if (payloadBytes > 0) {
        WriteFile(file, &payloadBytes, sizeof(payloadBytes), &written, 0);
        WriteFile(file, payload, payloadBytes, &written, 0);
    }

    CloseHandle(file);
}

void TextPad::SetFont(unsigned short fontId)
{
    GetMainTextEditPane()->InsertTextObject(1, &fontId, sizeof(fontId));
}

void TextPad::SetColor(unsigned int color)
{
    GetMainTextEditPane()->InsertTextObject(2, &color, sizeof(color));
}
```

Notes on child drafts:

- `GetMainTextEditPane`, `PasteScrap`, `CopySelectionToScrap`, and `InsertTextObject` are source-facing names for known helper roles. The final docs should tie them back to the exact existing helper addresses rather than inventing unrelated APIs.
- `new[]/delete[]` are source-style stand-ins for the allocation/free wrappers observed in the binary.
- The open helper's payload cursor logic should be documented as first-draft. The ownership and file format route are resolved; exact byte/unit math can remain a validation note against TextEditScrap support.

## Recommended Target Doc Changes

For `by-memory/0x00595900-0x00596242.TextPad.md`:

- Change metadata to `COMPLETION:88`, `CONFIDENCE:89`, keep owner/emitter [UID:0000OQ], keep `RECONSTRUCTABLE:TRUE`.
- Replace stale "no-code due 95+ threshold" language with the active source-quality decision:
  - source-authored TextPad class/helper cluster;
  - aggregate C++ ready for constructor, enter-key handler, close handler, and empty virtual;
  - command and standalone helper bodies should be emitted by child pages to avoid duplicate coverage.
- Add exact boundary/padding facts listed above.
- Add xref facts:
  - no constructor xrefs;
  - enter/close/null virtuals are vtable-routed;
  - command helper has one direct caller from enter-key;
  - standalone helper starts have no direct code/data xrefs.
- Add the adjusted-this correction:
  - raw `this+0x15c` in `0x00595af0` is primary `TextPad/DialogPane +0x1fc`;
  - raw `this+0x174` is primary `+0x214`;
  - neither is a new TextPad field.
- Add constructor activation route:
  - two `TextEditControlPane` controls;
  - main editor id `0`, input command editor id `1`;
  - max lines `2000`, max characters `30000`;
  - full-screen attach/show route via main UI layer slot and `g_pScreenPane`;
  - external allocation/caller remains unresolved after direct ref scans.
- Add source shape names for the four non-child methods and cross-link children for `SendText`, `Open`, `Save`, `SetFont`, `SetColor`.
- Add rejected alternatives:
  - free `TextPad_SendText`;
  - generic TextEditPane helper ownership;
  - generic FileIO/PlatformApi ownership;
  - TextDialog/EditablePaperPane/terminal/chat ownership;
  - proven-dead no-code treatment for standalone helpers.
- Add the first-draft aggregate C++ block above or an equivalent source-style block using existing project helper names.
- Add a `2026-06-19` changelog entry:
  - "B008 source-quality recheck resolved TextPad.cpp cluster source shape, corrected adjusted DialogPane offsets, confirmed command strings/imports/vtable refs/padding, identified `TextPad::SendText` plus retained `Open`/`Save`/`SetFont`/`SetColor` children, rejected TextEdit/FileIO ownership alternatives, and marked aggregate/child first-draft C++ ready with constructor-caller and standalone-xref caveats."

## Recommended Support Doc Changes

For `by-file/TextPad.md`:

- Raise to approximately `COMPLETION:88`, `CONFIDENCE:89`.
- Add the final method/source shape:
  - `TextPad::TextPad()`
  - `TextPad::OnKeyInput(InputEvent *event)`
  - `TextPad::OnClose()`
  - `TextPad::OnEmptyVirtual()`
  - `TextPad::SendText(const wchar_t *commandLine)`
  - `TextPad::Open(const wchar_t *path)`
  - `TextPad::Save(const wchar_t *path)`
  - `TextPad::SetFont(unsigned short fontId)`
  - `TextPad::SetColor(unsigned int color)`
- Add source placement note that `TextPad.cpp` owns UI/file command routing while `TextEditPane.cpp` owns serialization internals.
- Add no-constructor-xref and no-standalone-helper-xref caveats.

For `by-class/TextPad.md`:

- Raise to approximately `88/89`.
- Correct the stale offset interpretation:
  - `0x00595af0` raw `this+0x15c` is primary `+0x1fc`, inherited control manager.
  - raw `this+0x174` is primary `+0x214`, inherited active/current control id.
- Add control id names and roles:
  - id `0`: main text editor;
  - id `1`: bottom command input.
- Add method table rows for final names/signatures.
- Keep constructor external caller unresolved but document constructor-internal attach/show route as resolved.

For `by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md`:

- Raise to approximately `COMPLETION:88`, `CONFIDENCE:90`.
- Rename source-facing helper to `TextPad::SendText(const wchar_t *commandLine)`.
- Document one direct caller at `0x00595b64`.
- Document prefix dispatch semantics using `wcsstr(commandLine, prefix) == commandLine`.
- Add first-draft C++ block for `SendText`.
- Cross-link [UID:000248] for retained out-of-line helper bodies.

For `by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md`:

- Raise to approximately `COMPLETION:88`, `CONFIDENCE:89`.
- Rename helpers:
  - `0x00595f30`: `TextPad::Open(const wchar_t *path)`
  - `0x00596070`: `TextPad::Save(const wchar_t *path)`
  - `0x005961d0`: `TextPad::SetFont(unsigned short fontId)`
  - `0x00596210`: `TextPad::SetColor(unsigned int color)`
- Keep no-xref caveat after local scan.
- State best inference: retained out-of-line TextPad members whose logic is duplicated or inlined into `SendText` in this build.
- Add first-draft C++ block for the four helper bodies.

For `by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md`:

- Keep current high score unless implementation policy wants a small confidence bump.
- Add final method names and the adjusted-secondary-vtable note for `0x00595af0`.
- Keep successor boundary before `0x0062e228`.

For `by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md`:

- Keep current high score.
- Add that all four literals are TextPad command prefixes for `TextPad::SendText`.
- Reconfirm successor `0x0062e268` is Thread RTTI, not TextPad data.

For `by-memory/0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane.md` and `by-class/TextEditScrap.md`:

- Add cross-note that TextPad Open/Save uses `TextEditScrap` as the bridge between plain text and optional rich payload.
- Do not move ownership of TextPad file commands here.

For `by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md` and `by-item/EncodeTextEditState_0058E490.md`:

- Add cross-note that TextPad's optional payload is the editor serialization stream, including the `"kong"` marker/state tables, but TextPad owns the outer file command format.

For `by-global/WideApiDispatchTable.md`, `by-file/PlatformApi.md`, and `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`:

- Add cross-note that TextPad file helpers use the `CreateFileW` dispatch slot at `0x0069be34`.
- Keep PlatformApi as provider only; do not assign TextPad file helper ownership to it.

## Score And Metadata Recommendations

- [UID:0001JV] `TextPad`: `COMPLETION:88`, `CONFIDENCE:89`, owner/emitter [UID:0000OQ], reconstructable true, first-draft aggregate C++ ready.
- [UID:0001JW] `TextPadCommandHelper`: `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter [UID:0000OQ], reconstructable true, first-draft `TextPad::SendText` C++ ready.
- [UID:000248] `TextPadStandaloneFileAndInsertHelpers`: `COMPLETION:88`, `CONFIDENCE:89`, owner/emitter [UID:0000OQ], reconstructable true, first-draft child helper C++ ready with no-xref caveat.
- [UID:0000OQ] `by-file/TextPad.md`: recommend `88/89` after support incorporation.
- [UID:0000EU] `by-class/TextPad.md`: recommend `88/89` after offset correction and method table updates.
- Vtable and command-string support pages can keep current high scores unless local policy requires a small source-name update score bump.

Score remains capped below low 90s because:

- External allocation/caller route for `TextPad::TextPad()` is still not found.
- The standalone helper island has no direct code/data xrefs.
- Exact original names for some DialogPane helpers and TextEditControlPane constructor flags remain inferred.
- Exact open-branch payload pointer arithmetic is decompiler-sensitive.
- IDA MCP was unavailable for live renaming/xref confirmation in this session.

## Exact Pending Coverage Row Text

Do not apply these rows directly as B008; supervisor owns `by-memory/-coverage-report.md`. Exact replacement text recommended:

```markdown
    - [UID:0001JV][0x00595900-0x00596242.TextPad](by-memory/0x00595900-0x00596242.TextPad.md) 0x00595900-0x00596242 | class/helper cluster | TextPad : reconstructable : 88% : strong : B008 2026-06-19 source-quality recheck resolves the TextPad.cpp cluster as full-screen DialogPane construction plus secondary-view OnKeyInput, OnClose, empty virtual, private SendText command dispatcher, and retained Open/Save/SetFont/SetColor helper island; local PE/Capstone confirms exact padding, vtable/string refs, no constructor xrefs, one SendText caller, no standalone helper xrefs, PlatformApi CreateFileW dispatch plus GetFileSize/ReadFile/WriteFile/CloseHandle dependencies, TextEditScrap/TextEditPane serialization format, adjusted-this offset correction, rejected TextEdit/FileIO/TextDialog/terminal ownership alternatives, and first-draft C++ readiness with helper bodies emitted by exact child pages.
    - [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md) 0x00595be0-0x00595f26 | private member helper | TextPad::SendText : reconstructable : 88% : very strong : B008 2026-06-19 recheck resolves `TextPad_SendText` as `TextPad::SendText(const wchar_t *commandLine)`, verifies the sole caller at 0x00595b64 from the Enter-key path, prefix dispatch via `Open `/`Save `/`SetFont `/`SetColor `, PlatformApi `g_pfnCreateFileW` plus direct GetFileSize/ReadFile/WriteFile/CloseHandle use, TextEditScrap text/payload load-save behavior, font/color insert command ids 1/2, relationship to retained out-of-line Open/Save/SetFont/SetColor helpers, and first-draft C++ readiness.
    - [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md) 0x00595f30-0x00596242 | retained member helper island | TextPad file/format helpers : reconstructable : 88% : strong : B008 2026-06-19 recheck names the island as retained `TextPad::Open`, `TextPad::Save`, `TextPad::SetFont`, and `TextPad::SetColor` member helpers, confirms modeled open/save bodies, raw insert helper starts, exact padding, zero direct code/data xrefs to all four starts, TextPad inherited control-manager access at +0x1fc, TextEditScrap/TextEditPane serialization and formatted-insert dependencies, likely inlined/retained relationship to `SendText`, rejected generic TextEdit/FileIO ownership and dead/no-code interpretations, and first-draft child C++ readiness with no-xref caveat.
```

## IDA Rename, Type, And Comment Recommendations

Renames:

- `0x00595900`: `TextPad::TextPad()`
- `0x00595af0`: `TextPad::OnKeyInput(InputEvent *event)`
- `0x00595bb0`: `TextPad::OnClose()`
- `0x00595bd0`: `TextPad::OnEmptyVirtual()`
- `0x00595be0`: `TextPad::SendText(const wchar_t *commandLine)`
- `0x00595f30`: `TextPad::Open(const wchar_t *path)`
- `0x00596070`: `TextPad::Save(const wchar_t *path)`
- `0x005961d0`: `TextPad::SetFont(unsigned short fontId)`
- `0x00596210`: `TextPad::SetColor(unsigned int color)`
- `0x0069be34`: `g_pfnCreateFileW` or `WideApiDispatchTable::CreateFileW`.

Type/comment updates:

- Mark `0x00595af0` as a secondary-subobject virtual reached with adjusted `ecx`; document that raw `+0x15c` and `+0x174` map to primary `+0x1fc` and `+0x214`.
- Comment TextPad control ids: `0` main editor, `1` command input.
- Comment `0x00595be0` as a private TextPad command dispatcher with one direct caller.
- Comment `0x00595f30/0x00596070/0x005961d0/0x00596210` as retained out-of-line member helpers with no direct xrefs in this build.
- Comment `0x0058fef0` callers from TextPad as insert rich-text object/format commands, command ids `1` and `2`.

## Validator Needs After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the supervisor sends an implementation callback and the docs are edited:

> Executable block R001 was removed from this report and preserved verbatim in [0001JV-TextPad-source-quality-removed.md](0001JV-TextPad-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support cross-notes are edited, also run:

> Executable block R002 was removed from this report and preserved verbatim in [0001JV-TextPad-source-quality-removed.md](0001JV-TextPad-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Implementation Callback Checklist

When accepted for implementation:

1. Lease all target/support docs before editing.
2. Do not edit `by-memory/-coverage-report.md`; carry the exact replacement rows above into notes for supervisor-owned application.
3. Update [UID:0001JV] metadata to `88/89`, replace stale no-code threshold language, add boundary/xref/source-shape facts, add adjusted-this correction, add aggregate first-draft C++ for non-child methods, and add the 2026-06-19 changelog entry.
4. Update [UID:0001JW] with final `TextPad::SendText` naming, signature, one-caller evidence, command-prefix semantics, and first-draft child C++.
5. Update [UID:000248] with final `Open`/`Save`/`SetFont`/`SetColor` names/signatures, no-xref evidence, retained-helper inference, and first-draft child C++.
6. Update `by-file/TextPad.md` and `by-class/TextPad.md` with the source-shape names, corrected inherited offsets, constructor activation route, control ids, and no-xref caveats.
7. Update vtable and command-string support docs with final method names and command-prefix semantics.
8. Add cross-notes to TextEditScrap/TextEditPane serialization and PlatformApi/WideApi dispatch docs only if the implementation scope allows support cross-notes.
9. Run all scoped validators listed above for every edited file.
10. Record validation results, changed files, before/after scores, remaining unresolved issues, and pending coverage rows in `Agent-B008/notes.md`.

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0001JV-TextPad-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0001JV"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001JV-TextPad-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0001JV-TextPad-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001JV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
