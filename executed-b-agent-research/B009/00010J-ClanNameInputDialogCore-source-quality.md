** TARGET-REPORT-UID:00010J **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00010J ClanNameInputDialogCore Source-Quality Report

Assignment: `B009-goal2-clan-name-input-dialog-core-source-quality-00010J-20260619`  
Agent: Agent-B009  
Target: [UID:00010J] `source-3/project-documentation/by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/00010J-ClanNameInputDialogCore-source-quality.md`

Report-only pass. I did not edit target/support by-* docs, generated docs/source, IDA state, project-level coverage reports, or `by-memory/-coverage-report.md`.

## Executive Recommendation

Raise [UID:00010J] from `84/90` to `88/91`, keep owner/emitter routing unchanged, and populate the target formal C++ block with a first-draft source-shaped method cluster.

Recommended metadata:

```yaml
COMPLETION: 88
CONFIDENCE: 91
CANONICAL_OWNER: 0000I8
RECONSTRUCTABLE: TRUE
EMITTER_UIDS:
  - 0000I8
```

Rationale: the target already clears the active reconstructable/emitter/combined-score gate, and the stale no-C++ reasoning is now weaker than the evidence. The exact method bounds, internal padding, packet prompt decode, `DLGCLAN1.EPF` control layout, logical control ids, vtable dispatch, derived submit-slot identity, OK-state helper, `g_pClanStatusPane` forwarding, and current `Clan.cpp` source route are all strong enough for first-draft C++. Remaining uncertainty is limited to inherited UI helper spelling, exact event/close handler parameter types, and final `Clan.cpp` versus coordinated `ClanDialogs.cpp` split. Those do not justify keeping this exact range blank.

## Evidence Checked

Primary target and support docs:

- [UID:00010J] `by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md`
- [UID:00002J] `by-class/ClanNameInputDialog.md`
- [UID:0000I8] `by-file/Clan.md`
- [UID:0000IA] `by-file/ClanDialogs.md`
- [UID:0001TY] `by-type/by-struct/ClanInputDialogLayouts.md`
- [UID:0001X9] `by-type/by-vtable/ClanDialogVtableFamily.md`
- [UID:0003HE] `by-type/by-vtable/ClanModalDialogVtables.md`
- [UID:00010K] `by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md`
- [UID:00021C] `by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md`
- [UID:0002B5] `by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md`

Prior reports used as leads and rechecked against current docs:

- `tools/leaser/Agents/Agent-B001/research/executed/0002NS-0002NU-0002NW-0002NY-0002O0-0002O2-clan-submitters-source-quality.md`
- `tools/leaser/Agents/Agent-B002/research/00010J-ClanNameInputDialogCore-source-quality.md`

Generated/current-route checks:

- `auto-generated/-ag-memory-coverage.md` routes [UID:00010J] as `emits` through [UID:0000I8] to `auto-generated/NexusTK/social/Clan.cpp`.
- `auto-generated/-ag-class-coverage.md` routes [UID:00002J] `ClanNameInputDialog` the same way.
- `auto-generated/NexusTK/social/Clan.cpp` now contains the accepted B001 sibling `OnSubmitText` implementations but still has an empty emitter marker for [UID:00010J].
- `auto-generated/NexusTK/ui/dialogs/ClanDialogs.cpp` is still empty; `ClanDialogs` is a split candidate, not the current emitter route.

Local IDA export files checked:

- `hooks-generation/tests/function_data/raw_ida_export_data/functions/0x00488b40.json`
- `hooks-generation/tests/function_data/raw_ida_export_data/functions/0x00488eb0.json`
- `hooks-generation/tests/function_data/raw_ida_export_data/functions/0x00488f30.json`
- `hooks-generation/tests/function_data/raw_ida_export_data/functions/0x00488f70.json`

The local JSON decompilations match the target page's live-IDA evidence:

- `0x00488b40` contains the base constructor call, vtable stores, `{len, bytes}` prompt copy from `packet[3]`/`packet+4`, `MultiByteToWideChar`, and the `DLGCLAN1.EPF` control construction sequence.
- `0x00488eb0` fetches control id `4` through `this[127]` / `+0x1fc`, reads up to 255 wide characters, dispatches primary vtable slot index `23` (`+0x5c`), then runs close helpers for OK or Cancel.
- `0x00488f30` fetches controls `1` and `4`, calls the text empty helper, and jumps through OK-button state slots `+0x50` or `+0x4c`.
- `0x00488f70` checks byte `event+4` for value `3`, forwards through `g_pClanStatusPane + 0xa0` slot `+4`, and returns the base input-event handler result.

No live IDA MCP was available in this B009 pass. The current target/support docs already include prior live-IDA checks; this report revalidates them with local export data and current support-document state.

## Current State

[UID:00010J] is currently:

- `COMPLETION:84`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000I8`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000I8`
- formal `RECONSTRUCTION_CPP` block blank

The current score rationale says completion remains below final reconstruction because final C++ is blank and some source names/source-file splits are provisional. That is now circular: the source-quality work can resolve the method names and source route well enough for a first draft, while preserving explicit caveats for helper spelling and final file split.

The current coverage row is:

```text
    - [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md) 0x00488b40-0x00488fa0 | class core | ClanNameInputDialogCore : reconstructable : 84% : strong : IDA confirms exact function bounds and internal padding, packet prompt decoding from `packet+3/+4`, `DLGCLAN1.EPF` control setup, OK/Cancel/text control ids, submit virtual dispatch, vtable-only handlers, 12 constructor refs, and `g_pClanStatusPane` input-event forwarding.
```

## Function Inventory And Boundary Decision

The range is one cohesive class-core cluster. No child split is needed before first-draft C++ because all four functions belong to `ClanNameInputDialog`, share one owner/emitter, and the internal gaps are alignment/padding.

| Range | Size | Source-facing identity | Decision |
| --- | ---: | --- | --- |
| `0x00488b40-0x00488eab` | `0x36b` / 875 | `ClanNameInputDialog::ClanNameInputDialog(const unsigned char *packet)` | Emit as constructor body in [UID:00010J]. |
| `0x00488eab-0x00488eb0` | 5 | alignment | Keep as internal padding note. |
| `0x00488eb0-0x00488f24` | `0x74` / 116 | `ClanNameInputDialog::OnButtonClick(...)` | Emit source-shaped OK/Cancel handler; exact framework parameter names remain a small caveat. |
| `0x00488f24-0x00488f30` | 12 | alignment | Keep as internal padding note. |
| `0x00488f30-0x00488f67` | `0x37` / 55 | `ClanNameInputDialog::UpdateOkButtonState()` | Emit source-shaped OK enable/disable helper. |
| `0x00488f67-0x00488f70` | 9 | alignment | Keep as internal padding note. |
| `0x00488f70-0x00488fa0` | `0x30` / 48 | `ClanNameInputDialog::OnInputEvent(...)` | Emit source-shaped input-event override; return type follows the final UI base convention. |

Rejected split alternatives:

- Splitting this target into four new by-memory child pages would add granularity but is not required for correct source emission. If a future pass requires child pages, split on the four function starts above and keep padding ignored.
- Merging the following raw constructor `0x00488fa0-0x00488fd5` is rejected. That is [UID:00021V] `ClanDepMoneyInputDialogRawConstructor`, a separate raw constructor-shaped body with its own reachability caveat.
- Routing handlers to the vtable-family page is rejected. The vtable pages document slots; source method bodies belong to the class/core page under the Clan source route.

## Constructor Source Shape

Recommended source-facing signature:

```cpp
ClanNameInputDialog::ClanNameInputDialog(const unsigned char *packet)
```

Evidence and details:

- The decompiler's `int a2` packet parameter and `std::_Narrow_char_traits<char,int>::to_char_type(a2 + 3)` are type artifacts. The source behavior is byte-oriented packet parsing.
- Prompt format is `{ len, bytes }` at `packet[3]` and `packet + 4`.
- The constructor copies `(unsigned char)packet[3]` bytes from `packet+4` to a local multibyte buffer, writes a local byte terminator, calls `MultiByteToWideChar(0, 0, promptBytes, promptLength, promptWide, 0x8000)`, range-checks the returned count against `0x8000`, and writes a wide terminator at `promptWide[wideLength]`.
- The Win32 code page argument is `0`, source-facing `CP_ACP`; do not document this as UTF-8.
- The explicit `cbMultiByte` is the packet length, not `-1`; the local byte terminator is defensive/local and is not part of the converted input length.
- The constructor calls the dialog base constructor with empty wide text and arguments matching the current docs' modal/show flags.
- It stores three vtable views:
  - primary at `this+0x000`
  - secondary/subobject view at `this+0x0a0`
  - tertiary/subobject view at `this+0x0a4`
- No class-specific persistent fields are established by this constructor beyond inherited dialog/control state. Prompt bytes and wide text are stack-local.

Control/resource inventory:

| Role | Logical id / resource | Rect | Source note |
| --- | --- | --- | --- |
| EPF background/resource pane | `DLGCLAN1.EPF` | `(0,0)-(278,161)` | Constructed first and added to the dialog. |
| OK image button | image index `14`, logical id `1` | `(65,117)-(137,133)` | Do not confuse image/resource index 14 with logical id 1. |
| Cancel image button | image index `22`, logical id `2` | `(142,117)-(214,133)` | Do not confuse image/resource index 22 with logical id 2. |
| Prompt/static text | decoded prompt | `(51,38)-(228,88)` | Uses the packet prompt after CP_ACP-to-wide conversion. |
| Text edit | logical id `4` | `(51,94)-(228,107)` | Read by OK submit and tested by OK-state refresh. |
| Dialog display rect | n/a | `(155,12)-(433,173)` | Current docs identify the final positioning/display rectangle. |

Source-facing helper names remain descriptive because the UI framework pages are not all final:

- `sub_4F4AA0` is the shared allocation helper / operator-new route.
- `sub_49DC10` is the dialog add-control/control-manager helper.
- `sub_49DB60`, `sub_49DD80`, `sub_49DDD0`, `sub_49FC00`, `sub_49DFD0`, `sub_49E190`, and `sub_49EC80` are dialog setup/focus/background/display helpers. Use canonical helper names if an implementation callback finds stricter accepted names; otherwise keep source draft at the readable `AddControl`/`SetFocusedControl`/`SetDisplayRect` level.

## Handler Source Shape

### `0x00488eb0` Button Handler

Best source-facing identity:

```cpp
void ClanNameInputDialog::OnButtonClick(int closeContext, int controlId)
```

The exact framework declaration may include an unused fourth/event parameter or name the `ebx` close context differently. Behavior is not uncertain:

- `controlId == 1` is OK.
- OK fetches text edit control id `4` through inherited control-host pointer `this+0x1fc` (`this[127]` in decompiler output).
- It reads up to `0xff` / 255 wide characters into a stack buffer.
- It dispatches primary vtable slot index `23`, byte offset `+0x5c`, with `this` and the stack text buffer.
- It then runs the close animation/helper and closes the dialog.
- `controlId == 2` is Cancel and closes without submit.
- Any other id returns with no source-visible work.

B001 resolved the `+0x5c` slot across the six derived submitters as:

```cpp
virtual int OnSubmitText(const wchar_t *text);
```

This means [UID:00010J] should stop describing the submit hook as an unresolved virtual call. `OnSubmitText` is inferred/descriptive, not proved as an original symbol, but it is the highest-probability source-facing name because the slot handles both name and money/text variants and fits the surrounding `OnButtonClick`/`OnInputEvent` naming style.

### `0x00488f30` OK-State Helper

Best source-facing identity:

```cpp
void ClanNameInputDialog::UpdateOkButtonState()
```

Evidence and details:

- Fetches OK button id `1` through control host `+0x1fc`.
- Fetches text edit id `4` through the same control host.
- Calls the text edit empty/test helper (`sub_498C60`).
- Empty-text path jumps to OK button state slot `+0x50`.
- Non-empty path jumps to OK button state slot `+0x4c`.
- Source-facing expression should be `okButton->SetEnabled(!textEdit->IsEmpty())` unless the button class page later gives final names for both virtual slots.

Important correction for support docs: local decompilation of `0x00488f70` does not show a direct call to `UpdateOkButtonState()`. The refresh helper is a separate vtable-backed method likely invoked by the dialog/control framework on input changes. Support docs can say the dialog family has a refresh helper and input-event flow, but should not claim the `OnInputEvent` body directly calls this helper unless describing base-handler side effects.

### `0x00488f70` Input Event Handler

Best source-facing identity:

```cpp
bool ClanNameInputDialog::OnInputEvent(const InputEvent &event)
```

Return/signature caveat:

- The local JSON decompile returns `char`.
- Source-facing `bool` is plausible if it matches the established `DialogPane` input-event virtual. If nearby accepted docs use `char` or `int`, follow that convention during implementation.

Behavior:

- Reads event type byte at `event + 4`.
- If the type is `3`, forwards the event to the `g_pClanStatusPane` secondary view at `+0xa0`, slot `+4`.
- Always returns the base `DialogPane` input-event handler result via `sub_49E240`.

Rejected alternatives:

- Do not re-own this method to [UID:0002B5] `UiChatClanSingletonSlots` or `g_pClanStatusPane`; the singleton is a dependency, not the source owner.
- Do not inline OK-state refresh into this method's C++ unless an implementation callback finds a stronger UI-framework convention proving that source authored it there. The binary body only performs type-3 forwarding and base dispatch.

## Caller, Reachability, And Dialog Family

Constructor reachability is strong and not vtable-only:

- Six packet-dispatch construction sites inside [UID:00021C] `ClanStatusPacketDispatcher`: `0x0048511b`, `0x004851c6`, `0x00485227`, `0x0048527f`, `0x00485332`, and `0x00485393`.
- Six modeled helper/open construction sites documented on the class page: `0x00487ddf`, `0x004881df`, `0x0048828f`, `0x00488337`, `0x00488429`, and `0x004884cf`.
- Six raw derived-constructor calls: `0x00488fad`, `0x0048907d`, `0x0048914d`, `0x0048927d`, `0x004893ad`, and `0x004894dd`.

Handler reachability is virtual/vtable-only:

- `OnButtonClick` has vtable data refs at `0x00615940`, `0x006159e0`, `0x00615a80`, `0x00615b20`, `0x00615bc0`, `0x00615c60`, and `0x00615d00`.
- `UpdateOkButtonState` and `OnInputEvent` have matching entries in the same seven dialog vtable rows.
- No direct code callers are expected for these virtual handlers.

Derived dialog family:

- `ClanDepMoneyInputDialog`: raw constructor [UID:00021V], submitter [UID:0002NS].
- `ClanWidMoneyInputDialog`: raw constructor [UID:0002NT], submitter [UID:0002NU].
- `ClanExpelNameInputDialog`: raw constructor [UID:0002NV], submitter [UID:0002NW].
- `ClanSummonNameInputDialog`: raw constructor [UID:0002NX], submitter [UID:0002NY].
- `ClanAppearNameInputDialog`: raw constructor [UID:0002NZ], submitter [UID:0002O0].
- `ClanChangeNameInputDialog`: raw constructor [UID:0002O1], submitter [UID:0002O2].

B001 already implemented the six submitters as `OnSubmitText(const wchar_t *)` overrides in `auto-generated/NexusTK/social/Clan.cpp`. That current generated output confirms the submit-slot name is now part of accepted support context; [UID:00010J] is the remaining base/core blank marker in the same family.

## Owner, Emitter, And Source Placement

Recommendation: keep direct owner/emitter [UID:0000I8] `Clan`, output path `auto-generated/NexusTK/social/Clan.cpp`.

Evidence:

- [UID:0000I8] `Clan.md` is `90/85`, directly lists `ClanNameInputDialog`, documents the social clan status/dialog/packet core, and already owns this target's autogen route.
- `auto-generated/-ag-memory-coverage.md` and `auto-generated/-ag-class-coverage.md` both route [UID:00010J]/[UID:00002J] to `auto-generated/NexusTK/social/Clan.cpp`.
- [UID:0000IA] `ClanDialogs.md` is a plausible `NexusTK/ui/dialogs/ClanDialogs.cpp` split candidate, but explicitly says the current stronger owner is [UID:0000I8] because the same cluster shares clan status pane state, resources, packet helpers, and destructor/dialog-family context.
- `ClanDialogs.cpp` is empty in generated output, while `Clan.cpp` now contains the sibling submitters.

Rejected owner/source alternatives:

- `ClanDialogs.cpp`: plausible future split only. Moving this single range now would desynchronize base constructor/core, derived submitters, vtable pages, and generated route.
- `ClanDialogVtableFamily` / `ClanModalDialogVtables`: support data pages, not source owners.
- `ClanStatusPacketDispatcher`: caller/opening context, not the dialog class owner.
- `UiChatClanSingletonSlots` or `g_pClanStatusPane`: event-forwarding dependency, not owner.

If the project later commits to `ui/dialogs/ClanDialogs.cpp`, migrate the whole modal-dialog family together: [UID:00010J], [UID:00010L], raw constructor pages, derived submitters, vtable/modal resource support, and class pages. Do not move [UID:00010J] alone.

## Heuristic / Inference Reanalysis And Validation

### Stale no-C++ reasoning

The current blank C++ block is not justified under the active gate. [UID:00010J] is reconstructable, has a nonblank emitter route, already averages above 85, and source-quality evidence now supports method names and source route. The target should no longer cite unresolved submit-slot/source-placement questions as a reason to keep C++ blank.

### Constructor signature and packet parameter

Best inference: `ClanNameInputDialog::ClanNameInputDialog(const unsigned char *packet)`.

Rejected alternatives:

- `int packet` or `char *packet` as source signature: decompiler artifact / too weakly typed.
- A higher-level `PacketBuffer` reference: no object methods are called; the code directly reads raw byte offsets from the inbound packet.

Confidence: high for raw byte pointer; medium-high for exact `unsigned char` spelling versus `const char *`.

### Prompt packet decode

Best inference: prompt is a counted CP_ACP byte string from `packet[3]`/`packet+4`, converted with `MultiByteToWideChar(CP_ACP, 0, ..., promptLength, ..., 0x8000)`.

Rejected alternatives:

- NUL-terminated protocol prompt: the local byte NUL is appended, but the conversion call uses explicit `promptLength`.
- UTF-8 prompt: code page argument is `0`, source-facing CP_ACP.
- Length at `packet+4`: contradicted by decompile and target docs; `packet[3]` is the length and bytes begin at `packet+4`.

Confidence: high.

### Control ids versus image indices

Best inference: logical controls are id `1` OK, id `2` Cancel, and id `4` text edit; image/resource indices are `14` and `22`.

Rejected alternatives:

- Treating `14`/`22` as logical control ids is wrong; the handlers branch on `1` and `2`, and control lookup uses `4`.

Confidence: high.

### `+0x1fc` field name/type

Best inference: inherited `DialogPane` control-host/control-list pointer, source-facing `m_controlHost` or `m_controls`.

Evidence:

- Decompiled handlers use `this[127]` (`127 * 4 = 0x1fc`) to call a virtual lookup with ids `1` and `4`.
- [UID:0001TY] already documents `+0x1fc` as inherited control-host/control-list pointer.

Rejected alternatives:

- A `ClanNameInputDialog`-specific field: no constructor store or class-specific use supports that.
- Direct array/vector of controls: vcall lookup through the object at `+0x1fc` suggests a control-host object, not raw array access.

Confidence: high for inherited control-host role; medium for final field name spelling.

### Submit virtual name and signature

Best inference: `virtual int OnSubmitText(const wchar_t *text)`.

Evidence:

- `OnButtonClick` dispatches primary vtable slot index `23` / `+0x5c` with the submitted wide text.
- B001 rechecked and implemented all six derived slot targets with this signature.
- The slot covers money and name/text variants, so `OnSubmitName` is too narrow.

Rejected alternatives:

- Raw `(*vtable)[23]`: no longer a source-facing name.
- `SubmitName`: not valid for money variants.
- `SubmitDepositMoney`/`SubmitWithdrawMoney`: role names for child pages, not one shared base virtual name.

Confidence: high for role/signature; medium-high for exact original symbol spelling.

### OK-state refresh relationship

Best inference: `UpdateOkButtonState()` is a distinct virtual/helper that toggles OK from text emptiness and is likely invoked by the dialog/control framework on edit changes.

Important validation: `0x00488f70` itself does not call `0x00488f30`. Support docs should avoid wording that implies direct call in that body. If a class overview says "input flow refreshes OK state," qualify it as dialog-family/framework behavior rather than the literal `OnInputEvent` body.

Confidence: high for method behavior; medium for exact framework trigger.

### Event type `3` forwarding

Best inference: event byte `3` is text/edit-change or input-change notification, forwarded to `g_pClanStatusPane` secondary view so the status pane receives/coordinates active dialog input events before base handling.

Rejected alternatives:

- Treating this as a source owner transition to `ClanStatusPane`: the code is a dependency call from the dialog handler.
- Treating event type `3` as a network packet subtype: this is UI/input event memory, not opcode parsing.

Confidence: high for forwarding route; medium for final event enum name.

### Source split

Best inference: keep `social/Clan.cpp` now; `ui/dialogs/ClanDialogs.cpp` only if the supervisor later migrates the full modal family together.

Rejected alternatives are listed in the owner section. Current autogen and support docs strongly favor no one-off move.

### Compiler-generated/raw names

Recommended source-facing replacements:

| Raw/generated artifact | Recommended source-facing name | Confidence |
| --- | --- | --- |
| `sub_488B40` | `ClanNameInputDialog::ClanNameInputDialog(const unsigned char *packet)` | High |
| `sub_488EB0` | `ClanNameInputDialog::OnButtonClick(...)` | High for method name/behavior, medium for exact parameter list |
| `sub_488F30` | `ClanNameInputDialog::UpdateOkButtonState()` | High |
| `sub_488F70` | `ClanNameInputDialog::OnInputEvent(...)` | High for method name/behavior, medium for return type spelling |
| `std::_Narrow_char_traits<char,int>::to_char_type(a2 + 3)` | `(unsigned char)packet[3]` | High |
| `this[127]` / `this+0x1fc` | inherited control-host/control-list pointer | High role, medium field spelling |
| `(*vtable)[23]` / slot `+0x5c` | `OnSubmitText(const wchar_t *text)` | High role/signature, medium-high exact spelling |
| `dword_67ADE4` | `g_pClanStatusPane` | High |
| `sub_49E240` | `DialogPane::OnInputEvent` / base input-event handler | High role, medium spelling |
| `sub_498C10` | text edit `GetText`/`ReadText` helper | High role, medium spelling |
| `sub_498C60` | text edit `IsEmpty` helper | High role, medium spelling |
| `sub_49DAD0` | dialog close helper | High role, medium spelling |

## First-Draft C++ Readiness

This target should emit source-shaped C++. The code below is a first draft for the target formal `RECONSTRUCTION_CPP` block. It intentionally uses readable UI helper names; implementation should replace those helper spellings only where the project already has canonical names.

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

    if (static_cast<unsigned int>(wideLength) >= 0x8000) {
        __report_rangecheckfailure();
    }

    promptText[wideLength] = L'\0';

    AddControl(new EPFImageControlPane(L"DLGCLAN1.EPF", Rect(0, 0, 278, 161), 0, true));
    AddControl(new ImageButtonControlPane(14, Rect(65, 117, 137, 133)));     // id 1
    AddControl(new ImageButtonControlPane(22, Rect(142, 117, 214, 133)));    // id 2
    AddControl(new StaticTextControlPane(promptText, true, 128, Rect(51, 38, 228, 88)));
    AddControl(new TextEditControlPane(L"", true, 128, Rect(51, 94, 228, 107))); // id 4

    SelectControl(4);
    SetFocusedControl(1);
    SetCancelControl(2);
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
    if (event.type == 3) {
        g_pClanStatusPane->ForwardInputEvent(event);
    }

    return DialogPane::OnInputEvent(event);
}
```

Implementation caveats for this C++:

- If accepted UI docs do not support template `FindControl<T>`, use the canonical control-host lookup helper and casts.
- If the final base type uses `char`/`int` rather than `bool` for input-event returns, use that type while preserving the exact body.
- If the final button helper names distinguish visible/enabled/active slots, preserve the binary polarity: empty text takes slot `+0x50`, non-empty takes slot `+0x4c`.
- The comments `// id 1`, `// id 2`, and `// id 4` are source-orienting comments only; if implementation keeps the formal block comment-free, move those identities to prose instead.
- Class-level declaration C++ in [UID:00002J] may remain blank until full UI base class declarations are stable. The method-body target [UID:00010J] should not remain blank.

## Recommended Target Doc Changes

For [UID:00010J] `by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md`:

1. Change metadata to `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:0000I8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000I8`.
2. Populate the formal C++ block with the first-draft method cluster above, adjusted only for already-canonical helper spellings.
3. Replace the status confidence sentence with wording like:

```text
Confidence: very strong for exact function bounds, internal padding, packet prompt decoding, vtable/control layout, control ids, derived submit-slot dispatch, and Clan owner/emitter routing; medium-high for final framework helper spellings, exact input-event return type, and the future Clan.cpp versus ClanDialogs.cpp source split.
```

4. Add a source-facing signature table:

```text
Source-facing names/signatures:
- `ClanNameInputDialog::ClanNameInputDialog(const unsigned char *packet)` reads the prompt length from `packet[3]` and bytes from `packet + 4`.
- `ClanNameInputDialog::OnButtonClick(...)` handles OK id `1`, Cancel id `2`, and submits text from control id `4` through `OnSubmitText(const wchar_t *)`.
- `ClanNameInputDialog::UpdateOkButtonState()` toggles OK id `1` from text edit id `4` emptiness.
- `ClanNameInputDialog::OnInputEvent(...)` forwards event type `3` to `g_pClanStatusPane` secondary view before calling the base input-event handler.
```

5. Add/replace prompt decode wording:

```text
The prompt packet field is counted, not NUL-terminated protocol text: `packet[3]` is a byte length and `packet + 4` is the byte payload. The constructor appends a local byte terminator but calls `MultiByteToWideChar(CP_ACP, 0, promptBytes, promptLength, promptWide, 0x8000)` with the explicit count, then writes `promptWide[wideLength] = 0`.
```

6. Add/replace control/resource wording:

```text
Logical control ids are OK `1`, Cancel `2`, and text edit `4`. The OK/Cancel image indices are `14` and `22`; those are resource/image ids, not logical control ids. The inherited control host/control-list pointer is at `this+0x1fc`.
```

7. Add a submit-slot update:

```text
B001 resolved the shared derived submit slot: primary vtable slot `+0x5c` / index `23` is the inferred/descriptive `OnSubmitText(const wchar_t *text)` override used by the six `ClanNameInputDialog` derived submitter pages. This is no longer an open blocker for [UID:00010J].
```

8. Add an OK/input-event clarification:

```text
`UpdateOkButtonState` is a distinct helper/virtual that fetches controls `1` and `4`; empty text takes OK-button slot `+0x50`, non-empty text takes slot `+0x4c`, source-facing as `SetEnabled(!textEdit->IsEmpty())`. `OnInputEvent` itself only forwards event type `3` through `g_pClanStatusPane + 0xa0` and then returns the base input-event handler result.
```

9. Update the score rationale:

```text
`88/91`: source-quality reanalysis resolves the stale blank-C++ blocker. Exact function sizes, internal padding, constructor prompt decoding, CP_ACP conversion, control ids/resources, inherited control-host offset, submit virtual slot, derived submitter evidence, OK-state helper polarity, type-3 status-pane forwarding, caller/vtable reachability, and Clan owner/emitter routing support first-draft C++. Completion stays below 90 and confidence below 95 because inherited UI helper names, final input-event return spelling, and the future Clan.cpp versus ClanDialogs.cpp split remain provisional.
```

## Recommended Support-Doc Changes

Apply only if the supervisor sends an implementation callback.

### [UID:00002J] `by-class/ClanNameInputDialog.md`

- Keep owner/emitter [UID:0000I8].
- Recommended metadata after support update: `COMPLETION:86`, `CONFIDENCE:89`. If the supervisor wants minimal support churn, keeping `85/88` is acceptable, but the page should no longer imply the submit hook is unresolved.
- Add/update:

```text
[UID:00010J] is first-draft C++ ready as the base/core method cluster. The shared submit slot is now inferred/descriptive `OnSubmitText(const wchar_t *text)` at primary vtable `+0x5c`, validated by the six derived submitter pages. Class-level declaration C++ may remain blank until the UI base classes and final Clan.cpp/ClanDialogs.cpp split are finalized; this does not block the exact child memory page from emitting method-body C++.
```

- Correct or qualify any line saying `OnInputEvent` directly calls the refresh helper. Prefer:

```text
`UpdateOkButtonState` is the separate OK refresh method; the input-event override forwards type-3 events to `g_pClanStatusPane` and then calls the base handler, which owns the framework-level input flow.
```

### [UID:0000I8] `by-file/Clan.md`

- Keep score and path unchanged.
- Update the `ClanNameInputDialog` row to say [UID:00010J] is first-draft C++ ready and uses `OnSubmitText(const wchar_t *)` as the shared submit hook.
- Preserve the current rejection of one-off `ClanDialogs.cpp` routing.

Suggested insertion:

```text
B009 source-quality recheck: [UID:00010J] should emit the shared `ClanNameInputDialog` constructor and handlers in `social/Clan.cpp`; the packet prompt decode, controls `1`/`2`/`4`, `+0x5c` `OnSubmitText(const wchar_t *)` hook, OK-state helper, and `g_pClanStatusPane` forwarding are resolved enough for first-draft C++.
```

### [UID:0001TY] `by-type/by-struct/ClanInputDialogLayouts.md`

- No score change required.
- Add the CP_ACP prompt-decode detail and the `OnInputEvent` clarification if not already present:

```text
For `ClanNameInputDialog`, the prompt is a counted CP_ACP byte string at `packet[3]`/`packet+4`; `MultiByteToWideChar` uses the explicit byte count. `UpdateOkButtonState` owns the OK id `1` enable/disable polarity from text id `4`; `OnInputEvent` forwards type-3 events to `g_pClanStatusPane` and returns the base handler result.
```

### [UID:0000IA] `by-file/ClanDialogs.md`

- No score change required.
- Add a note that this report does not move [UID:00010J]:

```text
B009 [UID:00010J] recheck keeps the base `ClanNameInputDialog` core routed through `social/Clan.cpp` for now. `ClanDialogs.cpp` remains a coordinated modal-family split candidate; do not migrate this one target without moving the vtables, base cores, raw constructor pages, and derived submitters together.
```

### [UID:0003HE] `by-type/by-vtable/ClanModalDialogVtables.md`

- No score change required.
- Optional support note:

```text
The shared `ClanNameInputDialog` primary vtable slot `+0x5c` is now source-facing `OnSubmitText(const wchar_t *)`, based on [UID:00010J] dispatch and the six B001-derived submitter implementations.
```

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` in this B-agent report phase. If the implementation callback accepts this report, replace the current [UID:00010J] row with:

```text
    - [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md) 0x00488b40-0x00488fa0 | class core | ClanNameInputDialogCore : reconstructable : 88% : strong : B009 source-quality pass confirms exact constructor/method bounds and padding, packet prompt decode from `packet[3]`/`packet+4` through `MultiByteToWideChar(CP_ACP)` with a `0x8000` wide stack buffer, `DLGCLAN1.EPF` layout and logical ids OK `1`/Cancel `2`/text `4`, submit dispatch through `OnSubmitText(const wchar_t *)` at primary slot `+0x5c`, OK-state helper using inherited control host `+0x1fc`, type-3 forwarding through `g_pClanStatusPane`, Clan.cpp owner/emitter routing over the ClanDialogs split candidate, and first-draft C++ readiness.
```

## IDA Rename, Type, And Comment Recommendations

These are recommendations only; this report did not edit IDA.

Rename recommendations:

- `sub_488B40` -> `ClanNameInputDialog__ctor_from_packet` or `ClanNameInputDialog::ClanNameInputDialog`.
- `sub_488EB0` -> `ClanNameInputDialog__OnButtonClick`.
- `sub_488F30` -> `ClanNameInputDialog__UpdateOkButtonState`.
- `sub_488F70` -> `ClanNameInputDialog__OnInputEvent`.
- `dword_67ADE4` -> `g_pClanStatusPane` if not already named in IDA.

Type recommendations:

- Constructor parameter: `const unsigned char *packet`.
- Submit slot type in the `ClanNameInputDialog` primary vtable: `int (__thiscall *)(ClanNameInputDialog *, const wchar_t *)`.
- Control host field at `+0x1fc`: inherited `DialogControlHost *m_controlHost` or nearest accepted project type.
- Input-event parameter for `OnInputEvent`: `const InputEvent *` / `const InputEvent &` with type byte at offset `+4`.

Comment recommendations:

- At `0x00488b40`: "ClanNameInputDialog base constructor; prompt length is `packet[3]`, bytes start at `packet+4`, converted CP_ACP -> wide for DLGCLAN1 prompt."
- At `0x00488eb0`: "OK id 1 reads text control id 4 and dispatches shared submit slot `+0x5c`; Cancel id 2 closes."
- At `0x00488f30`: "Refresh OK state from text edit emptiness; empty -> slot `+0x50`, non-empty -> slot `+0x4c`."
- At `0x00488f70`: "Forward event type 3 to `g_pClanStatusPane` secondary view, then call base input-event handler."

Confidence: high for rename roles; medium for exact original C++ spellings.

## Validation Commands For Implementation Callback

No validators were run in this report-only pass because no by-* docs were edited.

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [00010J-ClanNameInputDialogCore-source-quality-removed.md](00010J-ClanNameInputDialogCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run validators for support docs actually edited. If the callback populates C++ and the workflow requires generated-source verification, also run the scoped/autogen command the supervisor specifies; otherwise use file-mode validators as listed.

Expected results: validator completes without metadata/tag errors. If it complains about first-draft helper names in the C++ block, keep the behavior and substitute the nearest accepted UI helper spellings rather than blanking the code.

## Implementation Instructions For Supervisor Callback

If accepted, implement in this order:

1. Lease [UID:00010J] target doc and every support doc selected for editing. Do not edit `by-memory/-coverage-report.md`.
2. Update target metadata to `88/91`, keep owner/emitter [UID:0000I8].
3. Populate the target C++ block with the first-draft method cluster, aligning only helper spellings with accepted local conventions.
4. Add the target prose updates listed under "Recommended Target Doc Changes": signature table, prompt decode detail, control/resource distinction, submit-slot resolution, OK/input-event clarification, owner/source route, and score rationale.
5. Update [UID:00002J] `ClanNameInputDialog.md` with the submit-slot resolution and the direct `OnInputEvent` clarification. Consider `86/89` if the supervisor wants support score sync; otherwise leave metadata unchanged.
6. Update [UID:0000I8] `Clan.md` only with a concise row/change note that [UID:00010J] is first-draft C++ ready in `social/Clan.cpp`.
7. Update [UID:0001TY] `ClanInputDialogLayouts.md` with the counted CP_ACP prompt and OK/input-event distinction if not already present.
8. Optionally update [UID:0000IA] `ClanDialogs.md` and [UID:0003HE] `ClanModalDialogVtables.md` with the one-off migration rejection and `OnSubmitText` slot support note. Do not make score changes there unless the supervisor asks.
9. Run file-mode validators from `source-3/project-documentation` for each edited file with `--apply --queue-timeout 240`.
10. Record the exact pending coverage row above in Agent-B009 notes for supervisor-owned application. Do not edit the coverage report.

## Open Questions And Residual Risk

- Exact original UI helper spellings remain medium confidence: `AddControl`, `FindControl`, `SetFocusedControl`, `SetCancelControl`, `SetDisplayRect`, `ShowDialog`, `StartClose`, and `ForwardInputEvent` are source-facing placeholders. The behavior is stronger than the spelling.
- `OnButtonClick` exact parameter list is not fully proven. The binary uses a control id and a close-context value; implementation should follow nearby dialog callback convention if one exists.
- `OnInputEvent` exact return type may be `char`, `bool`, or `int` depending on the accepted UI base declaration. The body is exact.
- OK-button state slots `+0x4c` and `+0x50` still need final button-class names. Source-facing `SetEnabled(!IsEmpty())` is the best current human reconstruction.
- `ClanDialogs.cpp` remains plausible as a future modal-family split, but current docs and autogen route make `Clan.cpp` the correct implementation route for this pass.

None of these residual issues block first-draft C++ for [UID:00010J].

## Changed Files

Created this report only:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/00010J-ClanNameInputDialogCore-source-quality.md`

No target/support by-* docs, generated files, IDA files, project-level reports, or coverage reports were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/00010J-ClanNameInputDialogCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"00010J"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00010J-ClanNameInputDialogCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/00010J-ClanNameInputDialogCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00010J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
