** TARGET-REPORT-UID:0000ER **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000ER TextInputMenuDialog Class Source-Quality Report

Status: FINISHED

Agent: B010
Assignment target: [UID:0000ER] `source-3/project-documentation/by-class/TextInputMenuDialog.md`
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/0000ER-TextInputMenuDialog-class-source-quality.md`

## Recommendation Summary

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:88
CANONICAL_OWNER:0000OP
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000OP
```

Keep [UID:0000ER] `TextInputMenuDialog` under [UID:0000OP] `TextMenuDialogs`. The source route is strong: the constructor/action/update bodies are in [UID:0001BN] `0x00517ec0-0x0051a417.TextMenuDialogs`, the vtables are in the text-menu vtable family, the cancel path calls `TextMenuDialog::SendMenuRequestPacket`, and the retained raw reply helper [UID:000239] is directly class-owned by `TextInputMenuDialog`.

The current class page should no longer say that C++ is blocked by an old `95/95` bar or passive generated-name/control-character caveats. Current gate analysis is the active `85/85` source route: this class is reconstructable, owner/emitter is nonblank, and the remaining caveats are bounded. Add a first-draft class-level C++ declaration to the class page. Do not emit compiler scalar-deleting destructor or adjustor-thunk bodies.

Recommended support score changes:

```text
[UID:000239] TextInputMenuDialogReplyPacketHelper: 86/86 -> 88/88
[UID:0001BN] TextMenuDialogs aggregate: keep 86/88 unless supervisor wants a wording-only coverage refresh
Destructor thunk pages [UID:00037C]/[UID:00037D]: keep non-reconstructable/blank C++; wording update only if touched
```

## Evidence Checked

- Required workflow docs: `tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, `tools/leaser/Agents/Agent-B010/goal.md`, and the Implementation Callback Detail Contract in `goal.md`.
- Target doc [UID:0000ER] `by-class/TextInputMenuDialog.md`.
- Parent/source docs:
  - [UID:0000OP] `by-file/TextMenuDialogs.md`
  - [UID:0001BN] `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`
  - [UID:000239] `by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md`
  - [UID:00031Y] `by-type/by-vtable/TextMenuDialogVtables.md`
  - [UID:0001Y5] `by-type/by-vtable/MerchantMenuDialogVtableFamily.md`
- Sibling/relationship docs:
  - [UID:0000ES] `by-class/TextMenuDialog.md`
  - [UID:0000ET] `by-class/TextMenuItemList.md`
  - [UID:0001BX] `by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md`
  - [UID:00037C] `by-memory/0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks.md`
  - [UID:00037D] `by-memory/0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor.md`
- Callee/source-support docs:
  - [UID:0002OA] `by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md`
  - [UID:00011H] `by-memory/0x004988d0-0x00498dd0.TextEditControlPaneCore.md`
  - [UID:0000OM] `by-file/TextEditControlPane.md`
  - [UID:0003N6] `by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md`
  - [UID:0003N7] `by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md`
  - [UID:0003YM] `by-memory/0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers.md`
  - [UID:0003YO] `by-memory/0x005757d0-0x00575a07.PacketBufferStringWriteHelpers.md`
  - [UID:0003YP] `by-memory/0x00575a10-0x00575abb.PacketBufferOneByteStringReadHelpers.md`
  - [UID:0000Q5] `by-global/g_packetSender.md`
- Generated output checked as negative evidence:
  - `source-3/simroot_v2/class_TextInputMenuDialog.cpp`
  - `source-3/project-documentation/auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp`
- Coverage rows checked:
  - `by-class/-coverage-report.md` row for [UID:0000ER]
  - `by-memory/-coverage-report.md` rows for [UID:0001BN], [UID:000239], and [UID:0001BX]
- `tools/int_convert.py` was run for key constants: `0x39` = 57, `0xfc` = 252, `0x208` = 520, `0x150` = 336, `0xcd` = 205, `0x13a` = 314, `0xc5` = 197, `0xff` = 255, `0x80` = 128, `0x8f` = 143, `0x270` = 624, `0x278` = 632, `0x27a` = 634, `0x27c` = 636, and `0x280` = 640.
- Live IDA MCP was attempted at `http://127.0.0.1:13337/mcp` and was unavailable in this session: `IDA_MCP_ERROR: Unable to connect to the remote server`. I therefore used the existing live-IDA evidence recorded in by-* docs plus generated-source negative evidence.

## Heuristic / Inference Reanalysis And Validation

### Source Placement And Ownership

Best conclusion: keep `TextInputMenuDialog` in `ui/dialogs/TextMenuDialogs.cpp` under [UID:0000OP].

Evidence:

- [UID:0001BN] covers `TextInputMenuDialog::TextInputMenuDialog` at `0x005198e0-0x0051a276`, `OnButtonPress` at `0x0051a280-0x0051a3d5`, and the input-state updater at `0x0051a3e0-0x0051a417`.
- [UID:00031Y] records `TextInputMenuDialog` vtable bases `0x0061ee0c`, `0x0061ee6c`, and `0x0061ee9c`, with constructor stores at `0x00519950`, `0x00519956`, and `0x00519960`.
- Constructor call refs are in the menu-dialog factory area (`0x0051757b`, `0x005175c9`, `0x00517929`, `0x005179b9`) documented by [UID:000238].
- [UID:000239] is adjacent raw code after the text-input methods, reads `TextInputMenuDialog` object fields, and is already directly owned by [UID:0000ER].

Rejected alternatives:

- `TextEditControlPane` ownership: reject; text edit helpers are callees only. The dialog stores no persistent edit-control pointer of its own.
- `PacketBuffer` or `Socket` ownership for [UID:000239]: reject; packet helpers are callees, while the opcode/field payload is dialog-specific.
- `MerchantDialogPane` ownership: reject; the base contributes inherited layout/action-string behavior but not the `DLGMERC2` text-input parser and reply fields.
- `TextMenuItemList` pollution: reject; it is a sibling list class used by `TextMenuDialog`, not the text-input owner.
- `ArgumentedMenuDialogs`, `ItemMenuDialogs`, or `SpellMenuDialogs`: reject; those share the broader merchant/menu dispatcher and opcode family but have separate class/file owner buckets.

### Constructor Source Shape And Fields

Best source-facing constructor signature:

```cpp
TextInputMenuDialog::TextInputMenuDialog(
    bool hasExtraString,
    RECT *outRect,
    const unsigned char *packet,
    unsigned char merchantDialogType);
```

The fourth argument is stored into inherited `MerchantDialogPane`/dialog-base state at `+0x26c`; it is not the same field as the packet byte stored at `+0x278`.

Recommended class field names:

| Offset | Recommended name | Type/role |
| --- | --- | --- |
| inherited `+0x26c` | `m_merchantDialogType` or inherited `m_dialogKind` | constructor argument; source should keep this on the merchant-dialog base if that layout owns the field |
| `+0x270` | `m_dialogId` | 32-bit server dialog/menu id serialized in replies |
| `+0x278` | `m_replyType` | packet byte serialized after opcode `0x39` |
| `+0x27a` | `m_selectedOptionId` | 16-bit option/choice id serialized in replies |
| `+0x27c` | `m_hasExtraString` | guard for appending the stored extra string |
| `+0x280` | `m_extraString` | `SimpleUString`/StringBase-backed optional string; initialized in ctor, released by normal destructor path |

Packet parse order:

1. Read one byte into `m_replyType` (`this + 0x278`).
2. Read one big-endian dword into `m_dialogId` (`this + 0x270`).
3. Parse the object/merchant image descriptor for the `ObjectImageControlPane`.
4. Read a 16-bit text length and convert the packet-provided multibyte prompt text to wide text for `StaticTextControlPane`.
5. If constructor `hasExtraString` is true, set `m_hasExtraString = true`, read a one-byte length-prefixed ANSI string through the PacketBuffer reader family, and store it in `m_extraString`; otherwise set the flag false.
6. Read one 16-bit option id into `m_selectedOptionId` (`this + 0x27a`).

Generated `class_TextInputMenuDialog.cpp` should not be copied literally. It uses plausible but unproven names such as `m_merchantType`, `m_merchantId`, and `m_optionIndex`; it invents source helpers (`PacketReadByte`, `CopyBytes`, `GetControlText`); and it emits a scalar deleting destructor body that the by-* docs correctly classify as compiler-generated glue. It also uses `MultiByteToWideChar(949)` while the current recorded decompile evidence does not prove that literal codepage for this constructor. Keep the constructor's text conversion as "default/multibyte packet text to wide prompt" unless a fresh IDA pass proves a specific source constant.

### Controls And Edit-Control Names

Best source-facing control IDs:

| ID | Recommended name | Role |
| --- | --- | --- |
| `0` | `kBackgroundControlId` | `DLGMERC2` background image |
| `1` | `kSubmitButtonId` / `kOkButtonId` | submit typed text |
| `2` | `kCancelButtonId` | sends the shared cancel/request packet through `TextMenuDialog::SendMenuRequestPacket` |
| `3` | `kCloseButtonId` | closes the dialog without sending input |
| `4` | `kObjectImageControlId` | merchant/object image control |
| `5` | `kPromptTextControlId` | static prompt text |
| `6` | `kInputEditControlId` | text edit control |

There is no evidence for a persistent `m_inputEditControl` member in `TextInputMenuDialog`. The constructor creates and adds a `TextEditControlPane`, then later methods fetch control id `6` from the inherited `DialogPane` child-control host. Document it as a child control id and local variable, not as a class member.

The edit text reader is the existing [UID:0002OA] `TextEditControlPaneReadTextForwarder` at `0x00498c10`, which loads the embedded editor pointer from wrapper offset `+0x10c` and forwards to `TextEditPaneCopyWideText`. The validation method uses the `0x00498c60` empty-text predicate from the `TextEditControlPane` core. The submit button is toggled through inherited [UID:0003N6] `ControlPaneDeactivate` at vslot `+0x50` and [UID:0003N7] `ControlPaneActivate` at vslot `+0x4c`.

### Method Names

Recommended documentation/source names:

| Address | Current/common name | Recommended source-facing role |
| --- | --- | --- |
| `0x005198e0` | `TextInputMenuDialog` | constructor described above |
| `0x0051a280` | `OnButtonPress` | keep `OnButtonPress(int controlId)` as the class-page name; it handles control ids `1`, `2`, and `3` |
| `0x0051a3e0` | `ValidateInput` | use `UpdateSubmitButtonState()` as the clearer source role, with `ValidateInput` retained as current alias if broader DialogPane naming wants stable old names |
| `0x0051a420` | `SendInputReply` | retained raw helper; best type is `void TextInputMenuDialog::SendInputReply(const char *inputTextAnsi)` |

`OnButtonPress` behavior:

- `controlId == 1`: fetch control `6`, copy up to `0xff` / 255 wide characters, serialize opcode `0x39` inline, append optional stored extra string, append typed input through the wide-to-ANSI PacketBuffer writer, send through `g_packetSender`, then close.
- `controlId == 2`: call `TextMenuDialog::SendMenuRequestPacket`, which sends the shared cancel/request opcode `0x43`, then closes.
- `controlId == 3`: close without a text reply.

`UpdateSubmitButtonState` / `ValidateInput` behavior:

- Fetch submit button control `1`.
- Fetch edit control `6`.
- If edit text is empty, deactivate/disable control `1` through `ControlPaneDeactivate` (`+0x50`).
- If edit text is non-empty, activate/enable control `1` through `ControlPaneActivate` (`+0x4c`).

### Opcode 0x39 Reply Helper Shape

[UID:000239] is source-shaped project code, not padding or a compiler wrapper. Keep it class-owned and reconstructable, but retain the no-direct-xref score cap.

Best source-facing signature:

```cpp
void TextInputMenuDialog::SendInputReply(const char *inputTextAnsi);
```

Reason for `const char *` rather than `const wchar_t *`: [UID:000239] records the raw helper appending its argument through `0x005757d0`, which [UID:0003YO] names `PacketBufferAppendAnsiString8`. The submit-button path reads wide text from `TextEditControlPane` and is represented in generated output as a wide-string packet writer, matching [UID:0003YO] `0x00575850` / `PacketBufferAppendWideStringAsAnsi8`. Therefore the raw helper is best treated as an ANSI-string reply helper, while `OnButtonPress` has an inline wide-to-ANSI serialization path. Do not rewrite `OnButtonPress` to call [UID:000239] unless future route evidence proves that call or proves an inline wrapper/source macro shape.

Packet order for [UID:000239]:

1. `PacketBufferAppendUInt8(0x39)`.
2. `PacketBufferAppendUInt8(m_replyType)`.
3. `PacketBufferAppendUInt32BE(m_dialogId)`.
4. `PacketBufferAppendUInt16BE(m_selectedOptionId)`.
5. If `m_hasExtraString`, append `m_extraString.c_str()` through `PacketBufferAppendAnsiString8`.
6. Append `inputTextAnsi` through `PacketBufferAppendAnsiString8`.
7. Send through [UID:0000Q5] `g_packetSender` / `QueueAndSendPacket`.

This resolves the stale "packet-writer type not final" blocker enough for first-draft helper C++. The remaining caveat is reachability: current docs report no IDA function object and no direct xrefs to `0x0051a420`.

### Destructor Glue No-Code Policy

Best conclusion: class-level source should declare/define the ordinary `virtual ~TextInputMenuDialog()` as needed by the class, but [UID:00037C] and [UID:00037D] must not emit standalone C++ bodies.

Evidence:

- [UID:00037C] records two compiler-generated destructor adjustor thunks with vtable refs at `0x0061ee6c` and `0x0061ee9c`, forwarding to `0x00520d50`.
- [UID:00037D] records the scalar deleting destructor wrapper at `0x00520d50-0x00520d98`, with code refs from the thunks and primary vtable ref `0x0061ee0c`.
- [UID:0001BX] classifies the broader island as mixed compiler-generated destructor/thunk glue.

Generated `ScalarDeletingDestructor(int flags)` from `simroot_v2/class_TextInputMenuDialog.cpp` is a compiler artifact. Do not paste it into the class page or by-memory C++.

## First-Draft C++ Readiness

Class-page `RECONSTRUCTION_CPP` should be a first-draft class declaration, not a full method-body dump. Method bodies belong on exact by-memory pages or future exact child splits.

Recommended class-level draft:

```cpp
class TextInputMenuDialog : public MerchantDialogPane {
public:
    TextInputMenuDialog(bool hasExtraString,
                        RECT *outRect,
                        const unsigned char *packet,
                        unsigned char merchantDialogType);
    virtual ~TextInputMenuDialog();

protected:
    virtual void OnButtonPress(int controlId);
    virtual void UpdateSubmitButtonState(); // current docs alias: ValidateInput

private:
    enum ControlId {
        kBackgroundControlId = 0,
        kSubmitButtonId = 1,
        kCancelButtonId = 2,
        kCloseButtonId = 3,
        kObjectImageControlId = 4,
        kPromptTextControlId = 5,
        kInputEditControlId = 6
    };

    void SendInputReply(const char *inputTextAnsi);

    // Documented offsets are from the complete TextInputMenuDialog object.
    std::uint32_t m_dialogId;          // +0x270
    std::uint8_t  m_replyType;         // +0x278
    std::uint16_t m_selectedOptionId;  // +0x27a
    bool          m_hasExtraString;    // +0x27c
    SimpleUString m_extraString;       // +0x280, StringBase/LObject-backed
};
```

Recommended [UID:000239] by-memory first-draft body:

```cpp
void TextInputMenuDialog::SendInputReply(const char *inputTextAnsi)
{
    unsigned char packet[0x208];
    int cursor = 0;

    PacketBufferAppendUInt8(packet, &cursor, 0x39);
    PacketBufferAppendUInt8(packet, &cursor, m_replyType);
    PacketBufferAppendUInt32BE(packet, &cursor, m_dialogId);
    PacketBufferAppendUInt16BE(packet, &cursor, m_selectedOptionId);

    if (m_hasExtraString) {
        PacketBufferAppendAnsiString8(packet, &cursor, m_extraString.c_str());
    }

    PacketBufferAppendAnsiString8(packet, &cursor, inputTextAnsi);
    QueueAndSendPacket(g_packetSender, packet, static_cast<short>(cursor));
}
```

Recommended method-body notes for [UID:0001BN] if the supervisor later wants exact body work:

- Keep `OnButtonPress`'s submit path inline, or explicitly note that the observed binary inlines the same opcode `0x39` serialization rather than directly calling [UID:000239].
- Use `TextEditControlPane::GetText` / [UID:0002OA] for control `6`, then `PacketBufferAppendWideStringAsAnsi8` for typed user input.
- Use `TextMenuDialog::SendMenuRequestPacket` for control `2`.
- Use the `DialogPane` close helper for controls `1` after send and `3` directly.
- Use `TextEditControlPane::IsEmpty` plus `ControlPaneDeactivate`/`ControlPaneActivate` for `UpdateSubmitButtonState`.

## Open Questions Closed Or Capped

- Exact original method spelling: not symbol-proven, but `OnButtonPress`, `UpdateSubmitButtonState`/`ValidateInput`, and `SendInputReply` are strong source-facing names. This is not a blocker.
- Reply helper reachability: searched through existing [UID:000239] evidence; current IDB reports no direct xrefs and no function object. Treat as retained raw class helper and score cap, not as reason to clear ownership or drop C++ readiness.
- Edit-control member name: no persistent member is proven. Use control id `6` and local `TextEditControlPane *editControl`.
- Extra string concrete type: `+0x280` is a string object initialized and later accessed through the StringBase/SimpleUString `c_str`/data-pointer helper. Use `SimpleUString m_extraString` as the draft type with a caveat that the exact StringBase/LObject wrapper spelling is final-header work.
- Control constructor flag bytes (`0x01`, `0x80`, `0x8f`, zero flags): these are child-control constructor parameters. Do not promote them to `TextInputMenuDialog` fields or leave class C++ blocked on their final names.
- Destructor source shape: exact no-body proof applies only to [UID:00037C]/[UID:00037D]. The class should still declare a normal virtual destructor.

## Exact Recommended Implementation Callback

When supervisor accepts this report, implement these doc changes under leases and validation.

1. Update [UID:0000ER] `by-class/TextInputMenuDialog.md`.
   - Change metadata to `COMPLETION:88`, `CONFIDENCE:88`; keep `CANONICAL_OWNER:0000OP`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OP`.
   - Replace old `95/95` no-C++ wording with current `85/85` gate analysis and first-draft class declaration.
   - Add field table for `+0x26c`, `+0x270`, `+0x278`, `+0x27a`, `+0x27c`, and `+0x280`.
   - Add control-id table for ids `0` through `6`; explicitly say the edit control is fetched by id, not stored as a `TextInputMenuDialog` member.
   - Rename/clarify `ValidateInput` as `UpdateSubmitButtonState` with current-name alias if preserving method-map stability.
   - Document `OnButtonPress` submit/cancel/close behavior and the relationship to `TextMenuDialog::SendMenuRequestPacket`.
   - Document destructor glue policy: ordinary virtual destructor declaration only; no scalar deleting destructor body.
   - Add the class-level C++ declaration above to the formal C++ block.

2. Update [UID:000239] `by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md`.
   - Change metadata to `COMPLETION:88`, `CONFIDENCE:88`; keep owner/emitter [UID:0000ER].
   - Replace "field names and packet-writer type not final-source quality" with resolved source shape.
   - Use `TextInputMenuDialog::SendInputReply(const char *inputTextAnsi)` as the recommended signature.
   - Record the ANSI argument evidence from `0x005757d0` / `PacketBufferAppendAnsiString8`.
   - Contrast with `OnButtonPress`'s inline wide-to-ANSI path; do not claim a direct call.
   - Add first-draft helper C++ if supervisor wants this page to emit retained raw helper bodies despite no xref. If implementation policy is conservative, keep formal C++ blank but include this report's body draft in prose and state why no-xref retained helper emission is deferred.

3. Update [UID:0001BN] `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`.
   - Keep metadata unless doing broader method-body cleanup.
   - Replace old final-C++ gate language with current gate policy.
   - Update the text-input rows to use `UpdateSubmitButtonState` alias and control ids.
   - Add the distinction between the observed inline submit packet path and adjacent raw [UID:000239] helper.

4. Update [UID:0000OP] `by-file/TextMenuDialogs.md`.
   - In proposed contents, say `TextInputMenuDialog` has source-ready class declaration and [UID:000239] is a retained raw `SendInputReply(const char *)` helper.
   - Keep ArgumentedMenu split policy unchanged.
   - Explicitly reject moving the text-input helper to `PacketBuffer`, `TextEditControlPane`, or network/socket source files.

5. Optional support wording if touched:
   - [UID:00037C], [UID:00037D], and [UID:0001BX]: add a back-reference that `TextInputMenuDialog` class source declares only the normal destructor and these pages remain non-reconstructable compiler glue.
   - [UID:0002OA], [UID:00011H], [UID:0003N6], [UID:0003N7], [UID:0003YM], and [UID:0003YO] already contain the needed helper names; no edit required unless adding cross-references.

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md` during this B-report. Supervisor-owned replacement rows if implementation changes the by-memory docs:

```text
    - [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md) 0x00517ec0-0x0051a417 | class-method/raw-helper aggregate | TextMenuDialogs : reconstructable : 86% : strong : Text-menu dialog aggregate with request packet helper, constructor, paint, action, scroll-button updater, TextMenuItemList constructor/row/draw helpers, TextInputMenuDialog constructor/button/update paths, resolved TextInput field/control naming, raw opcode `0x39` helper ownership, factory/vtable evidence, and aggregate/no-body policy documented.
    - [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md) 0x0051a420-0x0051a51c | helper | TextInputMenuDialogReplyPacketHelper : reconstructable : 88% : strong : TextInputMenuDialog-owned retained raw `SendInputReply(const char *)` serializer for opcode `0x39`; B010 source-quality pass resolves PacketBuffer append helper names, fields `+0x278/+0x270/+0x27a/+0x27c/+0x280`, optional stored ANSI string, caller ANSI string argument, `g_packetSender` send, no-direct-xref/no-IDA-function score cap, and distinction from the submit-button path's inline wide-to-ANSI serialization.
```

Recommended `by-class/-coverage-report.md` replacement row for [UID:0000ER]:

```text
- [UID:0000ER][TextInputMenuDialog](by-class/TextInputMenuDialog.md) : reconstructable : 88% : strong : Text input menu dialog attached to [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md); B010 source-quality pass resolves constructor packet fields (`m_replyType`, `m_dialogId`, `m_selectedOptionId`, `m_hasExtraString`, `m_extraString`), control ids `1/2/3/4/5/6`, edit-control access through `TextEditControlPane`, opcode `0x39` reply-helper shape, `TextMenuDialog` cancel relation, vtable/destructor no-code policy, and first-draft class/source C++ readiness with remaining no-direct-xref/helper-spelling caveat.
```

## Validation Commands For Implementation

Run from `source-3/project-documentation` after every accepted edit:

> Executable block R001 was removed from this report and preserved verbatim in [0000ER-TextInputMenuDialog-class-source-quality-removed.md](0000ER-TextInputMenuDialog-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional destructor support pages are edited:

> Executable block R002 was removed from this report and preserved verbatim in [0000ER-TextInputMenuDialog-class-source-quality-removed.md](0000ER-TextInputMenuDialog-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After validation, report whether `project-level/-auto-completion-stats.md`, `tools/validator.ini`, or generated files under `auto-generated/` changed.

## IDA Rename / Type / Comment Recommendations

If live IDA is available later:

| Address | Recommendation | Confidence |
| --- | --- | --- |
| `0x005198e0` | Name/type as `TextInputMenuDialog::TextInputMenuDialog(bool hasExtraString, RECT *outRect, const unsigned char *packet, unsigned char merchantDialogType)` | high for role, medium-high for exact parameter names |
| `0x0051a280` | Name as `TextInputMenuDialog::OnButtonPress`; comment controls `1` submit, `2` cancel request, `3` close | high |
| `0x0051a3e0` | Name as `TextInputMenuDialog::UpdateSubmitButtonState` with alias/comment `ValidateInput`; comment empty text -> deactivate submit, non-empty -> activate submit | high for role, medium-high for exact original name |
| `0x0051a420` | If raw function creation is allowed, create/name as `TextInputMenuDialog::SendInputReply` and type as `void __thiscall(TextInputMenuDialog *this, const char *inputTextAnsi)`; otherwise add a range comment only | high for owner/body, medium for raw function promotion |
| `this+0x270` | `m_dialogId` | high |
| `this+0x278` | `m_replyType` | medium-high |
| `this+0x27a` | `m_selectedOptionId` | medium-high |
| `this+0x27c` | `m_hasExtraString` | high |
| `this+0x280` | `m_extraString` / `SimpleUString m_extraString` | medium-high |

Do not rename [UID:00037C]/[UID:00037D] to source methods beyond compiler-generated thunk/destructor labels, and do not emit `ScalarDeletingDestructor` as source.

FINISHED report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/0000ER-TextInputMenuDialog-class-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0000ER-TextInputMenuDialog-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"0000ER"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000ER-TextInputMenuDialog-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/0000ER-TextInputMenuDialog-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000ER"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
