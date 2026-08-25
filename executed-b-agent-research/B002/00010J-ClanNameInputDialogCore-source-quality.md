** TARGET-REPORT-UID:00010J **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B002 Source-Quality Report: [UID:00010J] ClanNameInputDialogCore

Date: 2026-06-19
Agent: Agent-B002
Target: `source-3/project-documentation/by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md`
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/00010J-ClanNameInputDialogCore-source-quality.md`

## Executive Recommendation

UID 00010J is ready to move from heuristic-only documentation into a first-draft source C++ block, with the current owner/emitter route unchanged:

```yaml
COMPLETION: 88
CONFIDENCE: 91
CANONICAL_OWNER: 0000I8
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: [0000I8]
```

The target currently scores 84/90, so its average is already above the draft-C++ gate. The remaining blockers are not behavior blockers; they are source-facing polish items: exact inherited helper names, final `Clan.cpp` versus future `ClanDialogs.cpp` split, and one compiler-generated input-handler signature detail. The constructor/method/helper inventory is strong enough to draft source-shaped C++ now.

No target/support by-* docs were edited for this report. No coverage report was edited.

## Evidence Checked

Primary/local evidence:

- `source-3/project-documentation/by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md`
- `source-3/project-documentation/by-class/ClanNameInputDialog.md`
- `source-3/project-documentation/by-file/Clan.md`
- `source-3/project-documentation/by-file/ClanDialogs.md`
- `source-3/project-documentation/by-type/by-struct/ClanInputDialogLayouts.md`
- `source-3/project-documentation/by-type/by-vtable/ClanDialogVtableFamily.md`
- `source-3/project-documentation/by-type/by-vtable/ClanModalDialogVtables.md`
- `source-3/project-documentation/by-memory/0x00616430-0x00616468.ClanModalDialogResourceStrings.md`
- `source-3/project-documentation/by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/executed/0002NS-0002NU-0002NW-0002NY-0002O0-0002O2-clan-submitters-source-quality.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/NexusTK/social/Clan.cpp`
- Local IDA export JSON:
  - `hooks-generation/tests/function_data/raw_ida_export_data/functions/0x00488b40.json`
  - `hooks-generation/tests/function_data/raw_ida_export_data/functions/0x00488eb0.json`
  - `hooks-generation/tests/function_data/raw_ida_export_data/functions/0x00488f30.json`
  - `hooks-generation/tests/function_data/raw_ida_export_data/functions/0x00488f70.json`

Tooling status:

- Live IDA MCP was attempted at `http://127.0.0.1:13337/mcp` and was unavailable in this session.
- Deferred tool discovery did not expose a usable IDA MCP tool.
- Numeric conversions used `source-3/project-documentation/tools/int_convert.py` for the key hex/decimal pairs below.

Decompiler-shaped generated C++ under `source-3/project-documentation/re-agent/reports/code/` was checked only as a weak lead. It contains clear wrong-class casts such as unrelated pane names, so it should not be copied into canonical docs.

## Function and Child Inventory

The range `0x00488b40-0x00488fa0` is a cohesive class-core range. No child split is required before C++ drafting.

Current internal boundaries remain correct:

| Range | Size | Recommended source-facing identity | Evidence status |
|---|---:|---|---|
| `0x00488b40-0x00488eab` | `0x36b` / 875 | `ClanNameInputDialog::ClanNameInputDialog(const unsigned char *packet)` | Strong |
| `0x00488eab-0x00488eb0` | 5 | alignment/padding | Strong |
| `0x00488eb0-0x00488f24` | `0x74` / 116 | `ClanNameInputDialog::OnButtonClick(...)` | Strong behavior, signature has one context caveat |
| `0x00488f24-0x00488f30` | 12 | alignment/padding | Strong |
| `0x00488f30-0x00488f67` | `0x37` / 55 | `ClanNameInputDialog::UpdateOkButtonState()` | Strong |
| `0x00488f67-0x00488f70` | 9 | alignment/padding | Strong |
| `0x00488f70-0x00488fa0` | `0x30` / 48 | `ClanNameInputDialog::OnInputEvent(...)` | Strong behavior, base return type inferred |

Child split recommendation:

- Do not split for this implementation pass. The range has one owner, one emitter, one class, and source C++ can be emitted as a single method cluster.
- If a future granularity pass requires child pages, split into constructor, button handler, OK-state updater, and input-event override pages. Keep the internal padding as ignored/alignment notes, not standalone source children.
- Do not route this range to `ClanDialogs.cpp` yet. The stronger current route is still `social/Clan.cpp` through UID 0000I8.

## Constructor Inventory

Recommended signature:

```cpp
ClanNameInputDialog::ClanNameInputDialog(const unsigned char *packet)
```

Binary/export evidence:

- Local IDA JSON reports function `sub_488B40`, size `0x36b` / 875.
- Constructor stores three vtable views:
  - primary vtable at object offset `+0x00`
  - secondary view at `+0xa0` / 160
  - tertiary view at `+0xa4` / 164
- Base construction call is `sub_49D8A0(this, &word_60DB20, -1, 1)`, matching a dialog-pane base construction with an empty/wide title and modal/show flags.
- Prompt payload is read from the packet as:
  - length byte: `packet[3]`
  - prompt bytes: `packet + 4`
  - copied to a stack multibyte buffer and NUL-terminated
  - converted to wide text with `MultiByteToWideChar(0, 0, bytes, length, wideBuffer, 0x8000)`
  - hard maximum `0x8000` / 32768 wide characters
  - post-conversion NUL terminator at `wideBuffer[wideLength]`

The decompiler's `std::_Narrow_char_traits<char,int>::to_char_type(a2 + 3)` expression is a compiler/generated typing artifact. The source-facing behavior should be documented as reading the one-byte prompt length at `packet[3]`.

Constructor control/resource setup:

| Role | Resource/index | Rect hex | Rect decimal | Recommended source-facing note |
|---|---:|---|---|---|
| Background/image pane | `DLGCLAN1.EPF` | `(0,0)-(0x116,0xa1)` | `(0,0)-(278,161)` | EPF background/control pane |
| OK button image | `14` | `(0x41,0x75)-(0x89,0x85)` | `(65,117)-(137,133)` | image index 14, logical control id 1 |
| Cancel button image | `22` | `(0x8e,0x75)-(0xd6,0x85)` | `(142,117)-(214,133)` | image index 22, logical control id 2 |
| Prompt/static text | prompt wide text | `(0x33,0x26)-(0xe4,0x58)` | `(51,38)-(228,88)` | static prompt text |
| Text edit | empty string | `(0x33,0x5e)-(0xe4,0x6b)` | `(51,94)-(228,107)` | logical control id 4 |
| Dialog/display rect | n/a | `(0x9b,0x0c)-(0x1b1,0xad)` | `(155,12)-(433,173)` | display/positioning rect |

Prompt/control IDs:

- OK logical id: `1`
- Cancel logical id: `2`
- Text edit logical id: `4`
- Resource string: `DLGCLAN1.EPF`, supported by UID 0003B9 with xrefs inside the constructor at `0x00488c61` and `0x00488e21`.

Constructor xrefs:

- Six direct packet-dispatch construction sites from `sub_484F70`: `0x0048511b`, `0x004851c6`, `0x00485227`, `0x0048527f`, `0x00485332`, `0x00485393`.
- Six modeled helper/open construction sites from `sub_487D70`/`sub_488170`/`sub_488220`/`sub_4882D0`/`sub_488370`/`sub_488460`: `0x00487ddf`, `0x004881df`, `0x0048828f`, `0x00488337`, `0x00488429`, `0x004884cf`.
- Six raw derived constructor calls: `0x00488fad`, `0x0048907d`, `0x0048914d`, `0x0048927d`, `0x004893ad`, `0x004894dd`.

## Method and Helper Inventory

### `OnButtonClick`

Recommended source-facing name:

```cpp
void ClanNameInputDialog::OnButtonClick(int closeContext, int controlId)
```

Signature caveat:

- The source-facing method name is stable from current class docs and family usage.
- The decompiler signature includes an extra context-like value used by the close/slide helper before closing. A final source declaration may name this as an event/context pointer, or hide it behind a framework command handler signature.
- Behavior is strong enough for first-draft C++ even if the final parameter spelling changes.

Behavior:

- If `controlId == 1`:
  - fetch text edit control id `4` through control host at object offset `+0x1fc` / 508
  - read up to `0xff` / 255 wide characters into a stack buffer
  - dispatch primary vtable slot `+0x5c` / 92, slot index 23, with the text buffer
  - run close animation/helper and close the dialog
- If `controlId == 2`:
  - run the same close animation/helper and close the dialog
- Other ids return without source-visible work.

The B001 executed report resolves the `+0x5c` slot for six derived dialogs as:

```cpp
virtual int OnSubmitText(const wchar_t *text);
```

This should be reflected in 00010J. The old uncertainty about the submit virtual is no longer a blocker.

### `UpdateOkButtonState`

Recommended signature:

```cpp
void ClanNameInputDialog::UpdateOkButtonState()
```

Behavior:

- Fetches the OK button id `1` through the control host at `+0x1fc`.
- Fetches the text edit id `4` through the same control host.
- Calls the text edit emptiness/test helper.
- Calls one of two OK-button state virtuals:
  - text empty path: OK button slot `+0x50`
  - text non-empty path: OK button slot `+0x4c`

Source-facing form should prefer `okButton->SetEnabled(!textEdit->IsEmpty())` unless the button class documentation has final names for the two state slots. The exact slot polarity is known; the final names of `+0x4c` and `+0x50` are the only remaining helper-name caveat.

### `OnInputEvent`

Recommended signature:

```cpp
bool ClanNameInputDialog::OnInputEvent(const InputEvent &event)
```

Return/signature caveat:

- Local JSON decompilation returns a byte/char through the base handler.
- Source-facing docs can use `bool` if that matches the established `DialogPane` input-event virtual. If the UI framework uses `char`/`int`, preserve that local convention in implementation.

Behavior:

- Reads event type byte at `event + 4`.
- If the event type equals `3`, forwards the event to `g_pClanStatusPane` through its secondary view at `+0xa0`.
- Always returns the base `DialogPane` input-event handler result.

Global/source relationship:

- `g_pClanStatusPane` is documented by UID 0002B5 at global slot `0x0067ade4`.
- UID 0002B5 is a mixed singleton-slot aggregate and is not a better owner for this method.

### Helper Names

Confirmed or strong helper relationships:

- `sub_49DC10`: documented by UID 0003KH as dialog-pane control-manager creation/add-control helper.
- `sub_49DB60`: documented by UID 0003KG as dialog-pane background resource setter.
- `sub_49DD80`: documented by UID 0003KL as focused/current control id setter.
- `sub_49DDD0`: documented by UID 0003KM as pending control id setter.
- `sub_5446B0`: documented by UID 0002V7 as `Pane::SetMode(unsigned char mode)`.
- `sub_498C10`: text-edit read helper; source-facing use should be `GetText`/`ReadText` style.
- `sub_498C60`: text-edit emptiness/test helper; source-facing use should be `IsEmpty()` or equivalent.
- `sub_49DAD0`: dialog close/destruction/close-request helper; source-facing use should be a dialog close method.
- `sub_49E240`: base input-event handler.

Remaining helper-name caveats should not block C++:

- `sub_49FC00(this, 4)` after adding the text edit appears to select/focus/control-initialize id `4`; source name should follow the established `DialogPane` helper docs if available.
- `sub_49DFD0`, `sub_49E190`, and `sub_49EC80` configure display position/frame/show state. Source draft can describe them as high-level dialog display initialization until final helper docs are canonical.
- Button state slots `+0x4c` and `+0x50` should be named through the button-control class if/when that class is reconstructed.

## Clan Dialog Family Relationships

This target is the shared base/core for the prompt-and-text-entry clan modal family. It supplies:

- shared packet prompt decoding
- shared `DLGCLAN1.EPF` control layout
- shared OK/Cancel/text edit behavior
- shared submit dispatch at primary vtable slot `+0x5c`
- shared OK enable/disable update
- shared input-event forwarding to `g_pClanStatusPane`

B001 resolved the six known derived submitters using this base slot:

- UID 0002NS
- UID 0002NU
- UID 0002NW
- UID 0002NY
- UID 0002O0
- UID 0002O2

The source-facing base method should therefore name the dispatch target `OnSubmitText(const wchar_t *text)` rather than leaving it as an unknown virtual call.

Vtable evidence:

- `by-type/by-vtable/ClanModalDialogVtables.md` (UID 0003HE) is the relevant modal-dialog vtable child for this family and routes through Clan.
- `by-type/by-vtable/ClanDialogVtableFamily.md` (UID 0001X9) is a broad aggregate and should not own or emit this target.

## Owner, Emitter, and Source-File Routing

Recommendation:

- Keep `CANONICAL_OWNER: 0000I8`.
- Keep `EMITTER_UIDS: [0000I8]`.
- Keep output under `auto-generated/NexusTK/social/Clan.cpp` for this pass.

Rationale:

- `by-file/Clan.md` currently owns the social clan module and explicitly includes `ClanNameInputDialog`.
- `auto-generated/-ag-memory-coverage.md` and class coverage already route UID 00010J / UID 00002J to `auto-generated/NexusTK/social/Clan.cpp`.
- `auto-generated/NexusTK/social/Clan.cpp` currently contains only empty emitter markers for this target/class, so adding a formal C++ block would improve generated output without changing routing.
- `by-file/ClanDialogs.md` is a plausible future split for modal dialog implementations, but it currently documents `Clan.cpp` as the stronger owner. Moving only 00010J now would create an inconsistent family split unless the supervisor separately approves a file-level migration.

Rejected current alternatives:

- `ClanDialogs.cpp`: good future source split candidate, not the current canonical emitter.
- `ClanDialogVtableFamily` UID 0001X9: aggregate vtable documentation, not a source owner.
- `UiChatClanSingletonSlots` UID 0002B5: documents `g_pClanStatusPane`, not this class method owner.

## Heuristic / Inference Reanalysis

### Heuristic issue: score already clears draft gate but C++ is blank

Direction:

- Treat this as a source-quality gap, not a confidence gap.
- Populate C++ in UID 00010J now, using source-facing names and high-level UI helper names.
- Raise completion from 84 to 88 because the method inventory and submit slot are now resolved.
- Raise confidence from 90 to 91 because B001 confirms the virtual submit slot across all six derived submitters, but keep below 95 due unavailable live IDA MCP and remaining framework helper-name caveats.

### Heuristic issue: constructor source signature

Direction:

- Prefer `const unsigned char *packet`.
- The decompiler's `int` packet parameter and `std::_Narrow_char_traits` expression are artifacts.
- The actual source-facing behavior is byte-oriented packet parsing from offsets `+3` and `+4`.

### Heuristic issue: prompt decoding

Direction:

- Document exact packet offsets and `MultiByteToWideChar(0, 0, ...)`.
- Do not infer UTF-8. Code page `0` is CP_ACP in Win32 semantics.
- Include the `0x8000` stack-buffer guard but do not overstate it as a source-level fixed protocol limit beyond the constructor's local conversion buffer.

### Heuristic issue: control IDs versus resource indices

Direction:

- Separate logical control ids from image/resource indices:
  - logical OK id `1`
  - logical Cancel id `2`
  - logical text edit id `4`
  - OK image index `14`
  - Cancel image index `22`
- Current target wording is mostly correct but should add the resource index distinction to prevent accidental renaming of id 14/22 as controls.

### Heuristic issue: `UpdateOkButtonState` polarity

Direction:

- Exact binary polarity is known:
  - empty text path calls OK-button slot `+0x50`
  - non-empty text path calls OK-button slot `+0x4c`
- Source draft can express this as `SetEnabled(!textEdit->IsEmpty())`.
- If the button class later names `+0x4c`/`+0x50` oppositely, implementation should use the class names but preserve this control-flow polarity.

### Heuristic issue: submit virtual slot

Direction:

- Use B001's resolved name/signature: `OnSubmitText(const wchar_t *text)`.
- Document the dispatch as primary vtable slot `+0x5c`, slot index 23.
- This is no longer an open blocker for 00010J.

### Heuristic issue: `OnInputEvent` return type

Direction:

- Behavior is clear; exact C++ return spelling depends on the framework's base virtual type.
- Recommended source-facing type is `bool` if consistent with nearby input handlers.
- If existing source convention is `char`/`int`, preserve that during implementation.

### Heuristic issue: source-file split

Direction:

- Keep `Clan.cpp` now.
- Note `ClanDialogs.cpp` only as a future split after the whole modal family is migrated together.
- Do not create a one-off emitter route for UID 00010J.

### Heuristic issue: compiler-generated names

Direction:

- Replace decompiler/generated artifacts in source docs:
  - `sub_488B40` -> constructor
  - `std::_Narrow_char_traits<char,int>::to_char_type(a2 + 3)` -> `packet[3]`
  - raw vtable slot `+0x5c` -> `OnSubmitText`
  - raw global `dword_67ADE4` -> `g_pClanStatusPane`
- Keep raw addresses/slots in evidence paragraphs, not in first-draft C++ names.

## First-Draft C++ Readiness

Recommended first-draft C++ direction for UID 00010J:

```cpp
ClanNameInputDialog::ClanNameInputDialog(const unsigned char *packet)
    : DialogPane(L"", -1, true)
{
    char promptBytes[0x8000];
    wchar_t promptText[0x8000];

    const unsigned int promptLength = packet[3];
    memmove(promptBytes, packet + 4, promptLength);
    promptBytes[promptLength] = '\0';

    const int wideLength = MultiByteToWideChar(
        CP_ACP,
        0,
        promptBytes,
        promptLength,
        promptText,
        0x8000);

    if (static_cast<unsigned int>(wideLength) >= 0x8000)
        __report_rangecheckfailure();

    promptText[wideLength] = L'\0';

    AddControl(new EPFImageControlPane(L"DLGCLAN1.EPF", Rect(0, 0, 278, 161), 0, true));
    AddControl(new ImageButtonControlPane(14, Rect(65, 117, 137, 133)));
    AddControl(new ImageButtonControlPane(22, Rect(142, 117, 214, 133)));
    AddControl(new StaticTextControlPane(promptText, true, 128, Rect(51, 38, 228, 88)));
    AddControl(new TextEditControlPane(L"", true, 128, Rect(51, 94, 228, 107)));

    SelectControl(4);
    SetFocusedControl(1);
    SetPendingControl(2);
    SetBackgroundResource(L"DLGCLAN1.EPF", 0);
    SetMode(1);
    SetDisplayRect(Rect(155, 12, 433, 173));
    ShowDialog(false);
}

void ClanNameInputDialog::OnButtonClick(int closeContext, int controlId)
{
    if (controlId == 1) {
        wchar_t text[256];
        TextEditControlPane *textEdit = FindControl<TextEditControlPane>(4);

        textEdit->GetText(text, 255);
        OnSubmitText(text);
    } else if (controlId != 2) {
        return;
    }

    StartClose(closeContext);
    Close();
}

void ClanNameInputDialog::UpdateOkButtonState()
{
    ImageButtonControlPane *okButton = FindControl<ImageButtonControlPane>(1);
    TextEditControlPane *textEdit = FindControl<TextEditControlPane>(4);

    okButton->SetEnabled(!textEdit->IsEmpty());
}

bool ClanNameInputDialog::OnInputEvent(const InputEvent &event)
{
    if (event.type == 3)
        g_pClanStatusPane->ForwardInputEvent(event);

    return DialogPane::OnInputEvent(event);
}
```

Implementation notes for the callback agent:

- Helper names in this draft are source-facing placeholders and must be aligned with canonical `DialogPane`, `ImageButtonControlPane`, `TextEditControlPane`, and input-event names already used in nearby reconstructed docs.
- If the framework does not expose template `FindControl<T>`, replace it with the local control-host helper style while preserving ids `1`, `2`, and `4`.
- The source may use a different close handler signature than `(int closeContext, int controlId)`. Preserve the binary behavior: OK submit first, then close; Cancel closes; all other ids return.
- `ShowDialog(false)`, `SetDisplayRect`, and `SelectControl` are recommended source-facing names for currently less-canonical helpers. If those helper docs are stricter, use their final names.

## Recommended Exact Target Doc Changes

Apply these in a later implementation callback, not in this B-agent report phase:

1. Update metadata:

```yaml
COMPLETION: 88
CONFIDENCE: 91
CANONICAL_OWNER: 0000I8
RECONSTRUCTABLE: TRUE
EMITTER_UIDS:
  - 0000I8
```

2. Populate the target `C++:` block with the first-draft method cluster above, adjusted only for canonical helper names already accepted elsewhere.

3. Replace/extend the score rationale with:

```text
Source-quality B002 pass confirms exact method boundaries, constructor packet prompt decoding, control/resource ids, vtable-slot submit dispatch, OK-state update polarity, and input-event forwarding. Completion remains below 90 because several inherited UI helper names and the final Clan.cpp versus ClanDialogs.cpp split remain provisional; confidence remains below 95 because live IDA MCP was unavailable in this pass and the input-event/close handler signatures still depend on framework conventions.
```

4. Add a source-facing signature table:

```text
Source-facing names/signatures:
- `ClanNameInputDialog::ClanNameInputDialog(const unsigned char *packet)` reads prompt length from `packet[3]` and prompt bytes from `packet + 4`.
- `ClanNameInputDialog::OnButtonClick(...)` handles OK id 1, Cancel id 2, and submit dispatch through `OnSubmitText(const wchar_t *text)`.
- `ClanNameInputDialog::UpdateOkButtonState()` toggles OK id 1 from text edit id 4 emptiness.
- `ClanNameInputDialog::OnInputEvent(...)` forwards type-3 events to `g_pClanStatusPane` secondary view before calling the base input handler.
```

5. Add a control/resource table:

```text
Control/resource inventory:
- `DLGCLAN1.EPF` background/resource pane, rect `(0,0)-(278,161)`.
- OK image button uses image/resource index 14 and logical control id 1, rect `(65,117)-(137,133)`.
- Cancel image button uses image/resource index 22 and logical control id 2, rect `(142,117)-(214,133)`.
- Prompt static text uses the decoded packet prompt, rect `(51,38)-(228,88)`.
- Text edit uses logical control id 4, rect `(51,94)-(228,107)`.
- Dialog display rect is `(155,12)-(433,173)`.
```

6. Add/adjust behavior notes:

```text
The submit virtual is no longer unknown: B001 resolved the shared slot `+0x5c`/slot 23 as `OnSubmitText(const wchar_t *text)` across the six derived ClanNameInputDialog submitters. `OnButtonClick` reads text edit id 4 into a 255-wide-character stack buffer, calls `OnSubmitText`, and then closes for OK; Cancel closes without submit.

`UpdateOkButtonState` fetches OK id 1 and text edit id 4 through the control host at object offset `+0x1fc`. The empty-text path calls the OK button state slot at `+0x50`; the non-empty path calls slot `+0x4c`, source-facing as `SetEnabled(!textEdit->IsEmpty())`.

`OnInputEvent` checks the event type byte at `event + 4`; for type 3 it forwards to `g_pClanStatusPane` through its `+0xa0` secondary view, then returns the base `DialogPane` input-event result.
```

7. Add an ownership note:

```text
Ownership/source-file routing remains `Clan.cpp` through UID 0000I8 for this pass. `ClanDialogs.cpp` is a plausible future split for the modal dialog family, but moving this single range now would desynchronize the constructor, vtable family, derived submitters, and current autogen routing.
```

8. Add an evidence note:

```text
B002 source-quality pass (2026-06-19): live IDA MCP was unavailable, but local IDA export JSON confirmed exact sizes, xrefs, vtable stores, helper calls, packet prompt offsets, control geometry, OK/Cancel/text ids, the `+0x5c` submit dispatch, the `+0x1fc` control host, and `g_pClanStatusPane` forwarding. Numeric hex/decimal conversions were verified with `tools/int_convert.py`.
```

## Recommended Support-Doc Changes

Apply only if the supervisor asks for implementation edits:

### `by-class/ClanNameInputDialog.md`

Recommended wording change:

```text
UID 00010J now has enough source-quality evidence for a first-draft constructor/method C++ block. Class-level declaration C++ may remain blank until the surrounding dialog framework declarations are finalized, but the child memory page should no longer block on the submit virtual: B001 resolved shared slot `+0x5c` as `OnSubmitText(const wchar_t *text)`.
```

Optional score change after body C++ is accepted:

```yaml
COMPLETION: 86
CONFIDENCE: 89
```

### `by-type/by-struct/ClanInputDialogLayouts.md`

Recommended wording change:

```text
The ClanNameInputDialog base method cluster is source-ready: controls 1/2/4, control host offset `+0x1fc`, text submit slot `+0x5c`, and the three vtable views at `+0`, `+0xa0`, and `+0xa4` are resolved. Remaining uncertainty is limited to final source-file split and inherited helper naming, not field layout.
```

No score change required.

### `by-file/Clan.md`

Recommended wording change:

```text
`ClanNameInputDialog` remains routed through `social/Clan.cpp`; UID 00010J is ready for first-draft constructor/method C++ using the shared `OnSubmitText(const wchar_t *)` virtual resolved by the derived submitter pages.
```

No score change required.

### `by-file/ClanDialogs.md`

Recommended wording change:

```text
`ClanDialogs.cpp` remains a future split candidate for the modal dialog family. UID 00010J should not be moved independently until the constructor/core, modal vtables, and derived submitters are migrated together.
```

No score change required.

## Validator Needs

No validator was run for this report-only pass because no canonical by-* docs or generated docs were edited.

When the implementation callback happens, run at minimum:

> Executable block R001 was removed from this report and preserved verbatim in [00010J-ClanNameInputDialogCore-source-quality-removed.md](00010J-ClanNameInputDialogCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support docs are edited, also run file-mode validation on each touched support doc, for example:

> Executable block R002 was removed from this report and preserved verbatim in [00010J-ClanNameInputDialogCore-source-quality-removed.md](00010J-ClanNameInputDialogCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If C++ is populated and accepted, regenerate/check autogen:

> Executable block R003 was removed from this report and preserved verbatim in [00010J-ClanNameInputDialogCore-source-quality-removed.md](00010J-ClanNameInputDialogCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` during the B-agent report phase. If the implementation callback accepts the recommendations above, replace the current UID 00010J row with:

```text
    - [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md) 0x00488b40-0x00488fa0 | class core | ClanNameInputDialogCore : reconstructable : 88% : strong : Source-quality pass confirms exact constructor/method bounds, packet prompt decoding from `packet[3]`/`packet+4`, `DLGCLAN1.EPF` layout, OK/Cancel/text ids 1/2/4, submit dispatch through `OnSubmitText(const wchar_t *)` at slot `+0x5c`, OK-state update from text emptiness, and `g_pClanStatusPane` input-event forwarding; first-draft C++ is ready with Clan.cpp emitter routing unchanged.
```

## Open Questions

- Final framework spelling for `OnButtonClick` parameters: behavior is exact, but the decompiler exposes a close-context value whose source type/name should follow nearby dialog command handlers.
- Final framework return type for `OnInputEvent`: behavior is exact; source type should match the base `DialogPane` virtual.
- Final helper names for `sub_49FC00`, `sub_49DFD0`, `sub_49E190`, and `sub_49EC80`: source draft can use high-level names, but implementation should align with any already-canonical dialog helper pages.
- Final names/polarity for the image button state slots `+0x4c` and `+0x50`: current behavior supports source-facing `SetEnabled(!textEdit->IsEmpty())`.
- Final source-file split: keep `Clan.cpp` now; revisit `ClanDialogs.cpp` only as a coordinated modal-family migration.

## Changed Files

Created this report only:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/00010J-ClanNameInputDialogCore-source-quality.md`

No target docs, support docs, generated docs, or coverage reports were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00010J-ClanNameInputDialogCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"00010J"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00010J-ClanNameInputDialogCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00010J-ClanNameInputDialogCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00010J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
