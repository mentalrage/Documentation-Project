** TARGET-REPORT-UID:0001FK **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001FK NexonclubProxyDialogConstructor Source-Quality Research

Assignment: `B008-report-0001FK-nexonclub-proxy-dialog-constructor-source-quality-20260626`

Primary target: [UID:0001FK] `by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md`

Mode: report-only. I did not edit by-* docs, generated files, project-level files, manual coverage reports, validator/tool state, IDA DB, or leases.

## Executive Recommendation

Raise [UID:0001FK] from `85/90` to `90/92`, keep `CANONICAL_OWNER:00009H`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:00009H`, and populate the formal `RECONSTRUCTION_CPP CODE` block with a first-draft constructor body. The previous final-C++ blockers are no longer acceptable as blockers for this target: live MCP confirms the constructor route, packet parse shape, field writes, callback object construction, and registration-dialog handoff strongly enough to infer source-facing field/helper names for a draft.

Recommended support sync:

- [UID:00009H] `by-class/NexonclubProxyDialog.md`: raise from `86/88` to `88/90`, add the field table, source-facing method names, callback relationship, packet parse layout, and destructor/vtable policy.
- [UID:0000LZ] `by-file/NexonclubProxyDialog.md`: raise from `85/87` to `87/90`, keep source route `NexusTK/ui/dialogs/NexonclubProxyDialog.cpp`, and clarify that this file is a private proxy adapter source unit unless a future whole-dialog source-tree pass merges it into the registration-dialog file.
- [UID:0003GL] `by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md`: raise from `86/90` to `89/92`, keep owner/emitter [UID:00009H], add source-facing name `NexonclubProxyDialog::OnReplyText`, field-name reuse, fallback-current-packet behavior, and a formal first-draft C++ block for the callback.
- [UID:0003GK], [UID:0003DE], and [UID:0003DF]: no metadata change required; add cross-link detail only if not already present. Their vtables remain source-declared/generated-binary data, not hand-authored C++ bodies.
- [UID:0001CT], [UID:00009I], and [UID:0000M0] registration-dialog docs: no metadata change required; add cross-link detail that proxy provides a `PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>` result callback and registration owns/releases/invokes it after construction.

No split is recommended. The target is exactly one modeled constructor function. The adjacent reply callback, padding, vtable data, callback vtable data, and late destructor thunks already have separate pages.

## Current Target State

Current target metadata:

```text
UID:0001FK
COMPLETION:85
CONFIDENCE:90
CANONICAL_OWNER:00009H
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00009H
formal C++: blank
Item Summary: Constructor boundary, dispatcher wrapper, vtable/callback data, touched packet/text state, and reconstruction blockers documented.
```

The current page has the correct owner, emitter, range, reconstructable state, and broad behavior. It is thin on exact packet layout, current MCP proof, source-facing field names, the parse/discard treatment for unused button captions, and draft C++. Its "Final C++ is intentionally blank" reason names issues that are now resolved enough for a first-draft formal block: packet field names, callback source name, local buffers, and destructor/base thunk relationship.

## Evidence Checked

Current docs checked:

- [UID:0001FK] target constructor page.
- [UID:00009H] `by-class/NexonclubProxyDialog.md`.
- [UID:0000LZ] `by-file/NexonclubProxyDialog.md`.
- [UID:0003GL] `by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md`.
- [UID:0003GK] `by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md`.
- [UID:0003DE] `by-memory/0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData.md`.
- [UID:0003DF] `by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md`.
- [UID:0000LZ] / [UID:0000M0] proxy and registration file pages.
- [UID:00009I] and [UID:0001CT] registration-dialog class/aggregate pages.
- [UID:00023M] `MessageDialogPacketDispatcherAndWrappers`.
- [UID:00023N] `SharedDialogDefaultDestructorThunksLate`.
- [UID:0001FG] `DialogNavigationPacketHelpers`.
- [UID:0003YJ], [UID:0003YK], and [UID:0003YO] PacketBuffer write/read/string helper docs.
- [UID:000179] `ObjectStatusBlobParsers`.
- [UID:00012R] `DialogPane`.
- Current proposed-source-tree entries for `TextDialog` and `NexonclubProxyDialog`.

Prior reports checked:

- B002 `0001CT-nexonclub-registration-dialog-source-quality.md` for registration callback ownership and generated-output caveats.
- B007 `0003VS-TextDialogUnreferencedSubmitPacketRaw-source-quality.md` for the TextDialog/proxy boundary and opcode `0x3a` packet-family facts.
- B007 `0001C0-SharedDialogDefaultScalarDestructor-source-quality.md` for shared default destructor/no-code policy.

IDA MCP evidence used:

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Live database/session: `80de0a67`, `NexusTK.exe.i64`, worker active and Hex-Rays ready during this pass.
- Availability proof before research: `tools/list`, `idb_list`, and `server_health` returned HTTP 200 in the active supervisor/session context; subsequent target requests all returned normal tool results.
- Tool requests used in this pass:
  - `lookup_funcs` id `202` for `0x00553610`, `0x005534a0`, `0x0054c9f0`, `0x0052f950`, `0x005539c3`, and `0x005539ce`.
  - `decompile` ids `207`, `208`, and `209` for `0x00553610`, `0x005534a0`, and `0x0054c9f0`.
  - `xrefs_to` id `210` for `0x00553610`, `0x005534a0`, `0x00622c58`, `0x00622cb8`, `0x00622ce8`, and `0x00622cf4`.
  - `analyze_function` id `211` for `0x00553610`.
  - `disasm` ids `212` and `215` for `0x00553610` with pagination.
  - `callees` id `214` for `0x00553610`, `0x005534a0`, and `0x0054c9f0`.
  - `xrefs_to` ids `217` and `219` for boundary/data/global support addresses.
  - `lookup_funcs` id `220` for allocation, memory, registration, DialogPane, and close helper callees.

Invalid-parameter experiments occurred while determining current MCP schemas for `decompile`, `xrefs_to`, `get_bytes`, `get_string`, and `find_bytes`. They were schema mistakes, not MCP availability failures. The valid MCP calls above prove the endpoint and IDB were usable for this report.

## Boundary And Liveness

Live MCP `lookup_funcs` reports:

| Address | Function | Size | Meaning |
| --- | --- | ---: | --- |
| `0x00553610` | `sub_553610` | `0x2ed` | [UID:0001FK] `NexonclubProxyDialog` constructor. |
| `0x005534a0` | `sub_5534A0` | `0x169` | [UID:0003GL] proxy member reply callback. |
| `0x0054c9f0` | generated name `___std_parallel_algorithms_hw_threads@0_9` | `0x59` | Message-dialog/proxy allocation wrapper; generated name is stale/polluted. |
| `0x0052f950` | `sub_52F950` | `0x64b` | `NexonclubRegistrationDialog` constructor. |
| `0x005539c3`, `0x005539ce` | two `0xb` functions | `0x0b` each | late secondary/tertiary default-destructor thunks; compiler glue. |

The constructor endpoint `0x005538fd` remains exact. Disassembly shows `retn 4` at `0x005538f5`, range-check failure tail call at `0x005538f8`, and the range ends before alignment/successor bytes. The target is not a mixed aggregate and does not need a split.

Liveness:

- `xrefs_to 0x00553610` reports one code xref at `0x0054ca33` from wrapper `0x0054c9f0`.
- The wrapper decompiles as allocation of `0x278` bytes followed by `sub_553610(result, ..., packet)`.
- `xrefs_to 0x005534a0` reports the sole data xref at `0x00553895`, inside this constructor's callback-wrapper setup.
- `xrefs_to 0x00622c58`, `0x00622cb8`, and `0x00622ce8` reports vtable stores at `0x0055366e`, `0x00553674`, and `0x0055367e`.
- `xrefs_to 0x00622cf4` reports the callback-wrapper vtable store at `0x0055388f`.

Negative boundary evidence:

- The preceding TextDialog raw island remains separate and no-route; the proxy callback begins at `0x005534a0`, padding follows at `0x00553609-0x00553610`, and the constructor begins at `0x00553610`.
- The destructor thunks at `0x005539c3` and `0x005539ce` are not constructor code. They remain non-emitting compiler glue under [UID:00023N].
- Vtable/read-only data children are not executable source bodies. They are generated from source declarations and should be documented, not hand-emitted in this target.

## Constructor Behavior

Live decompilation and paginated disassembly show this source shape:

1. Base construction:
   - Calls `DialogPane` constructor `0x0049d8a0` with empty wide title string `0x0060db20` and two `1` flags.
   - Writes `NexonclubProxyDialog` primary/secondary/tertiary vtables to `this+0x00`, `this+0xa0`, and `this+0xa4`.
2. Packet header fields:
   - Saves `packet[0]` into `this+0x26c`.
   - Reads `PacketBufferReadUInt32BE(packet + 1)` into `this+0x270`.
   - If `packet[5] == 2`, writes `packet[6] = 2` before parsing the status blob.
3. Object/status blob skip:
   - Initializes local `ObjectStatusBlob`-style storage with default/display byte `0x50` at local offset `+40`.
   - Calls `ObjectStatusBlob::ParseTaggedStatus` at `0x004d1f30` on `packet + 6`.
   - If the parser returns a negative value, the constructor returns after base/proxy vtable setup and does not launch registration.
4. Dialog reply fields and text:
   - Reads `this+0x274` from `PacketBufferReadUInt16BE(packet + statusBytes + 10)`.
   - Reads `this+0x276` from `PacketBufferReadUInt16BE(packet + statusBytes + 12)`.
   - Consumes two one-byte fields at `packet + statusBytes + 14` and `+15`; current best source-facing names are `dialogWidthByte` and `dialogHeightByte` or generic `unusedLayoutByte0/1`. They are parsed/discarded and do not affect registration construction.
   - Reads a 16-bit byte length from `packet + statusBytes + 16`, copies that many bytes into a 32768-byte ANSI buffer, NUL-terminates it, and converts it to a 32768-wide-character `messageText` buffer with `MultiByteToWideChar(0, 0, ...)`.
5. Button captions:
   - Reads one one-byte length-prefixed ANSI caption and converts it into a 256-wide-character local buffer.
   - Consumes one additional single byte between captions.
   - Reads a second one-byte length-prefixed ANSI caption and converts it into a second 256-wide-character local buffer.
   - Neither converted caption is passed to `NexonclubRegistrationDialog`. The constructor consumes these packet fields to advance through the server dialog schema but only forwards the main text to the registration dialog.
6. Callback and registration handoff:
   - Allocates `0x18` bytes for the concrete `PlainMemberFunctionObjectT` callback wrapper.
   - Initializes its base through `0x004f4a80`.
   - Stores vtable `0x00622cf4`, member target `0x005534a0`, zero adjustment, and bound proxy object.
   - Allocates `0x278` bytes for `NexonclubRegistrationDialog`.
   - Calls `NexonclubRegistrationDialog::NexonclubRegistrationDialog(registration, messageText, callback)`.

## Packet Layout And Field Names

The best current source-facing constructor input type is `unsigned char *packet`, not `const unsigned char *packet`, because the body writes `packet[6] = 2` when `packet[5] == 2`.

Recommended field names for `NexonclubProxyDialog`:

| Offset | Type direction | Recommended name | Evidence |
| --- | --- | --- | --- |
| `+0x26c` | `unsigned char` | `m_dialogType` / `m_replyType` | Constructor stores `packet[0]`; reply callback writes it as opcode `0x3a` byte after the opcode; shared dialog navigation docs call this dialog type/subtype byte. Prefer `m_dialogType` for project consistency. |
| `+0x270` | `uint32_t` | `m_dialogId` | Constructor reads `PacketBufferReadUInt32BE(packet + 1)`; reply callback writes it as big-endian dword in reply packets. |
| `+0x274` | `uint16_t` | `m_dialogState` | Constructor reads a big-endian word after the object/status blob; reply callback writes it unchanged. |
| `+0x276` | `uint16_t` | `m_dialogPageIndex` | Constructor reads a big-endian word; reply callback sends `m_dialogPageIndex + 1`, matching the one-based reply page/index convention also seen in the TextDialog raw submit-packet island. |

Recommended packet-layout description:

| Packet offset | Meaning |
| --- | --- |
| `+0` | dialog type/subtype byte saved as `m_dialogType`. |
| `+1..+4` | big-endian dialog/session/object id saved as `m_dialogId`. |
| `+5` | status/object kind byte used to force tagged-status mode `2` when it equals `2`. |
| `+6..+6+statusBytes` | tagged `ObjectStatusBlob` data parsed only to consume the embedded NPC/object status section. |
| `+statusBytes+10..+11` | big-endian dialog state word saved as `m_dialogState`. |
| `+statusBytes+12..+13` | big-endian page/index word saved as `m_dialogPageIndex`. |
| `+statusBytes+14` and `+15` | two one-byte layout/caption-related fields consumed but not otherwise used by this adapter. |
| `+statusBytes+16..+17` | big-endian main-message byte count. |
| following bytes | main message ANSI/MBCS bytes converted through `MultiByteToWideChar`. |
| next byte/string | first one-byte length-prefixed caption converted to a 256-wide-char local. |
| next byte | consumed caption/layout separator byte. |
| next byte/string | second one-byte length-prefixed caption converted to a 256-wide-char local. |

The two single-byte fields and unused captions are not open blockers. Their exact original names are not required for this constructor's first-draft C++ because the compiled function consumes but discards them. They should be documented as consumed/discarded packet fields and kept below final-audit score until the broader message-dialog packet schema names them exactly.

## Callback And Registration Relationship

Accepted source-facing callback method name: `NexonclubProxyDialog::OnReplyText`.

Evidence:

- Existing file docs already use `OnReplyText`.
- The constructor stores `0x005534a0` as the concrete member-function target at callback object offset `+0x08`.
- The callback body sends opcode `0x3a` reply packets with the proxy fields at `+0x26c/+0x270/+0x274/+0x276`.
- The callback receives a `const mystr::StringBase<wchar_t,...>&` from `NexonclubRegistrationDialog`; on empty string it falls back to `SendDialogPacketCurrent` (`0x0054cd70`) and closes, and on non-empty string it appends the text and sends it.

Rejected callback names:

- `OnRegistrationResult`: too registration-dialog-centric; the method's concrete behavior is proxy reply packet emission.
- `SendProxyReplyText`: plausible but less consistent with the bound-callback role and existing docs; it hides the empty/cancel fallback path.
- `TextDialogRegionSelectionPacket`: stale generated pollution; the only live installation is the proxy constructor.
- `NexonclubRegistrationDialogCallback`: wrong owner after construction. The registration dialog owns/releases/invokes the callback object, but the bound member target belongs to `NexonclubProxyDialog`.

Registration relationship:

- `NexonclubProxyDialog` is the provider of the callback and the source of the prompt message text.
- `NexonclubRegistrationDialog` owns the account/password form, stores/releases the callback at its `+0x26c` registration-result callback field, and invokes it on success/cancel.
- The source route should remain a separate `NexonclubProxyDialog.cpp` private adapter under `NexusTK/ui/dialogs/` unless a later source-tree pass intentionally folds the small proxy adapter into the registration-dialog source file.

## Ownership And Source Placement

Accepted owner/emitter for [UID:0001FK]: [UID:00009H] `NexonclubProxyDialog`.

Accepted source file: [UID:0000LZ] `NexonclubProxyDialog`.

Candidate ranking:

1. [UID:00009H] `NexonclubProxyDialog` class: accepted. Evidence is the constructor's own vtable stores, proxy fields, concrete member-callback object, reply callback target, and only constructor call route.
2. [UID:0000LZ] `NexonclubProxyDialog` file: accepted source root. Evidence is compact adapter role, proposed-source-tree entry, callback method and constructor sharing private class state, and read-only proxy data children.
3. [UID:00009I]/[UID:0000M0] `NexonclubRegistrationDialog`: rejected as direct owner. It is the constructed child dialog and callback consumer, not the parser/proxy adapter owner.
4. [UID:0000LA] `MessageDialogs`: rejected as direct owner. Its dispatcher wrapper allocates/calls the proxy constructor, but the constructor installs the proxy class vtables and handles private callback state.
5. [UID:0000EL]/[UID:0000OL] `TextDialog`: rejected. B007 route checks and current docs prove the adjacent `0x005534a0+` tail belongs to proxy, not TextDialog.
6. [UID:0000M8] `PacketBuffer`, [UID:00009S] `ObjectStatusBlob`, [UID:0000JO] `FunctionObjects`, and [UID:0000IT] `DialogPane`: rejected as feature owner. They own callees/templates/base behavior only.

## Heuristic / Inference Reanalysis And Validation

### Placeholder Names

Resolved source-facing names:

- `sub_553610` -> `NexonclubProxyDialog::NexonclubProxyDialog(unsigned char *packet)`.
- `sub_5534A0` -> `NexonclubProxyDialog::OnReplyText(const StringBaseW& text)`.
- `this+0x26c` -> `m_dialogType`.
- `this+0x270` -> `m_dialogId`.
- `this+0x274` -> `m_dialogState`.
- `this+0x276` -> `m_dialogPageIndex`.
- `sub_5754C0` -> `PacketBufferReadUInt32BE`.
- `sub_575480` -> `PacketBufferReadUInt16BE`.
- `sub_4D1F30` -> `ObjectStatusBlob::ParseTaggedStatus`.
- `sub_516220` -> `MemmoveWrapper` / `memmove`-style copy.
- `sub_4F4AA0` / `sub_4F4AC0` -> project allocator/delete wrappers, source-level `new`/delete behavior.
- `sub_4F4A80` -> FunctionObject base initialization.
- `sub_52F950` -> `NexonclubRegistrationDialog` constructor.

Rejected placeholder retention:

- Keeping `sub_553610`, `sub_5534A0`, `dword_67A7EC`, or `a1/a3`-style names in target formal C++ is unnecessary. Current context supports source-facing names even though exact original spelling is inferred.
- The generated wrapper name `___std_parallel_algorithms_hw_threads@0_9` at `0x0054c9f0` is false/stale. Treat it as a proxy allocation wrapper in message-dialog dispatch documentation, not as standard-library code.

### Open Blockers From Current Page

The current target page says formal C++ is blank because packet field names, local buffer naming, callback source name, and destructor/base thunk relationship are unresolved. Current-pass resolution:

- Packet fields: resolved as `m_dialogType`, `m_dialogId`, `m_dialogState`, and `m_dialogPageIndex` with exact writer/reader evidence.
- Local buffers: resolved as `messageBytes`, `messageText`, `buttonBytes`, `firstButtonText`, and `secondButtonText`; exact unused-caption behavior is documented.
- Callback source name: resolved as `OnReplyText`, with rejected alternatives.
- Destructor/base thunk relationship: resolved as a no-code/support issue. Constructor C++ should declare/default real class destructor behavior and rely on compiler-generated vtable/thunk/scalar-delete glue. [UID:00023N] and [UID:0001C0] remain non-emitting compiler artifacts.

These are not reasons to keep [UID:0001FK] at `85` or to keep target formal C++ blank.

### Positive Evidence

- Modeled function at `0x00553610`, exact size `0x2ed`.
- One live constructor call from proxy allocation wrapper `0x0054ca33`.
- Three proxy vtable stores in the constructor at `0x0055366e`, `0x00553674`, and `0x0055367e`.
- Four proxy reply fields written in constructor and consumed by reply callback.
- Object/status parse body call into [UID:000179] with consumed byte count.
- `MultiByteToWideChar` conversion for main text and two one-byte length-prefixed captions.
- Callback object allocation and `PlainMemberFunctionObjectT` vtable/member/adjustment/bound-this stores.
- Registration-dialog allocation and constructor call with main text and callback.
- Support docs align on TextDialog/proxy boundary and registration callback ownership.

### Negative Evidence

- No evidence supports TextDialog ownership of `0x00553610`.
- No evidence supports moving this constructor to registration-dialog ownership; registration dialog is callee/consumer only.
- No evidence supports hand-emitting vtable data, callback vtable data, scalar deleting destructor wrapper, or adjustor thunks in this target.
- No evidence supports treating unused button captions as absent; they are explicitly parsed and converted even though not passed onward.
- No evidence supports treating `packet[6] = 2` as a const-input parse; constructor input must remain mutable in the draft signature.

### Remaining Uncertainty

Remaining uncertainty is below first-draft-C++ blocking level:

- Exact original names for the two discarded one-byte layout/caption fields are not proven.
- Exact original packet-struct typedef is not proven; `unsigned char *packet` is the best current source-facing signature because the body mutates `packet[6]`.
- Exact final `StringBaseW`, callback template typedef, and `ObjectStatusBlob` API spellings remain project-wide type/header issues.
- Whether `NexonclubProxyDialog.cpp` was a standalone physical file or folded into another dialog source file remains a source-tree packaging question, not a target ownership or C++ blocker.

These cap the target below `95/95`, not below `90/92`.

## First-Draft C++ Recommendation For [UID:0001FK]

Insert the following exact content into [UID:0001FK]'s formal `RECONSTRUCTION_CPP CODE` block after supervisor acceptance. This is first-draft source-shaped C++ for the target constructor; it should be refined later when exact project typedefs are finalized, but it avoids IDA/decompiler labels and stays within the constructor range.

```cpp
NexonclubProxyDialog::NexonclubProxyDialog(unsigned char *packet)
    : DialogPane(L"", true, true),
      m_dialogType(packet[0]),
      m_dialogId(PacketBufferReadUInt32BE(packet + 1)),
      m_dialogState(0),
      m_dialogPageIndex(0)
{
    ObjectStatusBlob objectStatus;
    objectStatus.m_displayStatusByte = 0x50;

    if (packet[5] == 2)
        packet[6] = 2;

    int statusBytes = objectStatus.ParseTaggedStatus(packet + 6);
    if (statusBytes < 0)
        return;

    unsigned char *cursor = packet + statusBytes + 10;

    m_dialogState = PacketBufferReadUInt16BE(cursor);
    cursor += 2;

    m_dialogPageIndex = PacketBufferReadUInt16BE(cursor);
    cursor += 2;

    unsigned char dialogWidthByte = *cursor++;
    unsigned char dialogHeightByte = *cursor++;
    (void)dialogWidthByte;
    (void)dialogHeightByte;

    unsigned short messageLength = PacketBufferReadUInt16BE(cursor);
    cursor += 2;

    char messageBytes[0x8000];
    wchar_t messageText[0x8000];
    memmove(messageBytes, cursor, messageLength);
    cursor += messageLength;
    messageBytes[messageLength] = '\0';

    int messageChars = MultiByteToWideChar(
        0,
        0,
        messageBytes,
        messageLength,
        messageText,
        _countof(messageText));
    messageText[messageChars] = L'\0';

    unsigned char firstButtonLength = *cursor++;
    char buttonBytes[0x8000];
    wchar_t firstButtonText[256];
    memmove(buttonBytes, cursor, firstButtonLength);
    cursor += firstButtonLength;
    buttonBytes[firstButtonLength] = '\0';

    int firstButtonChars = MultiByteToWideChar(
        0,
        0,
        buttonBytes,
        firstButtonLength,
        firstButtonText,
        _countof(firstButtonText));
    firstButtonText[firstButtonChars] = L'\0';

    unsigned char unusedButtonSeparator = *cursor++;
    (void)unusedButtonSeparator;

    unsigned char secondButtonLength = *cursor++;
    wchar_t secondButtonText[256];
    memmove(buttonBytes, cursor, secondButtonLength);
    buttonBytes[secondButtonLength] = '\0';

    int secondButtonChars = MultiByteToWideChar(
        0,
        0,
        buttonBytes,
        secondButtonLength,
        secondButtonText,
        _countof(secondButtonText));
    secondButtonText[secondButtonChars] = L'\0';

    FunctionObjectT<const StringBaseW&> *callback =
        new PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>(
            this,
            &NexonclubProxyDialog::OnReplyText);

    new NexonclubRegistrationDialog(messageText, callback);
}
```

Notes for supervisor validation:

- The source uses direct `memmove`/array indexing instead of explicit `__report_rangecheckfailure`; the original binary's range-check calls are compiler/runtime lowering for stack-array bounds, not a hand-written game helper.
- `_countof` is source-facing Visual C++ style. If the project later standardizes on `ARRAYSIZE` or a local count macro, update during final C++ polish.
- `StringBaseW` and `FunctionObjectT` are typedef placeholders for the project's exact `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >` and FunctionObject template spelling. The target docs should document the exact concrete vtable symbol and keep final score below 95 until typedefs are finalized.
- The unused button text locals are intentionally present. They correspond to observed conversion work even though the strings are not forwarded.

## First-Draft C++ Recommendation For [UID:0003GL]

The reply callback's previous blank C++ blocker is also resolved enough for a first-draft formal block. Insert the following exact content into [UID:0003GL] only after supervisor acceptance and only if the callback page is updated in the same implementation pass.

```cpp
void NexonclubProxyDialog::OnReplyText(const StringBaseW& text)
{
    if (text.empty()) {
        SendDialogPacketCurrent(this);
        CloseDialogPane(this);
        return;
    }

    unsigned char packet[0x200];
    int packetLength = 0;

    PacketBufferWriteUInt8(0x3a, packet + packetLength);
    packetLength += 1;

    PacketBufferWriteUInt8(m_dialogType, packet + packetLength);
    packetLength += 1;

    PacketBufferWriteUInt32BE(m_dialogId, packet + packetLength);
    packetLength += 4;

    PacketBufferWriteUInt16BE(m_dialogState, packet + packetLength);
    packetLength += 2;

    PacketBufferWriteUInt16BE(m_dialogPageIndex + 1, packet + packetLength);
    packetLength += 2;

    PacketBufferWriteUInt8(2, packet + packetLength);
    packetLength += 1;

    PacketBufferAppendWideStringAsAnsi8(text.c_str(), packet, &packetLength);

    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(packet, static_cast<unsigned short>(packetLength));

    CloseDialogPane(this);
}
```

Notes for supervisor validation:

- `text.empty()` models the `0x005845f0` StringBase empty predicate.
- `text.c_str()` models `0x00584540` StringBase data-pointer access before the PacketBuffer wide-string append helper.
- `SendDialogPacketCurrent` is the source-facing role for `0x0054cd70`; it sends the current dialog reply when callback text is empty/cancelled.
- `CloseDialogPane` is the source-facing role for shared close helper `0x0049dad0`; exact final helper name may be refined by the DialogPane source pass.
- `PacketBufferAppendWideStringAsAnsi8` models `0x00575850`; if final PacketBuffer API names differ, update consistently with [UID:0003YO].

## No-Code / Non-Emitting Dispositions

Keep these related items blank formal C++:

- [UID:0003DE] `NexonclubProxyDialogVtableData`: vtable/RTTI data generated from source declarations.
- [UID:0003DF] `NexonclubProxyCallbackVtableData`: concrete function-object vtable generated from the template instantiation.
- [UID:00023N] late destructor thunks: compiler-generated `this -= 0xa0/0xa4` adjustor thunks to [UID:0001C0].
- [UID:0001C0] shared scalar deleting destructor: compiler-generated deleting destructor wrapper.
- [UID:000268] broader message-dialog read-only data aggregate: non-emitting mixed `.rdata` index.

These no-code decisions are not blockers for the constructor's formal C++.

## Metadata Recommendation

Recommended [UID:0001FK] header:

```text
COMPLETION:90
CONFIDENCE:92
CANONICAL_OWNER:00009H
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00009H
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: populated with constructor block above
Item Summary: Current MCP session 80de0a67 confirms constructor 0x00553610-0x005538fd, wrapper caller 0x0054ca33, proxy vtable stores, packet header/status/text/caption parse, reply fields +0x26c/+0x270/+0x274/+0x276, callback wrapper to OnReplyText, registration-dialog handoff, source-facing names, rejected owner alternatives, and first-draft constructor C++ readiness.
```

Score rationale:

- Completion `90`: the report resolves the former current-page blockers, provides exact behavior, source-facing names, support relationships, first-draft formal C++ content, and implementation checklist.
- Confidence `92`: current MCP decompilation/disassembly/xrefs and existing support docs agree on route and behavior. Confidence remains below 95 because exact original typedefs/source-file packaging and two consumed/discarded layout bytes are still inferred.

Recommended support metadata:

```text
[UID:00009H] by-class/NexonclubProxyDialog.md: 88/90, owner/emitter unchanged.
[UID:0000LZ] by-file/NexonclubProxyDialog.md: 87/90, source path unchanged.
[UID:0003GL] by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md: 89/92, owner/emitter unchanged, formal C++ populated with callback block above.
[UID:0003GK] callback wrapper class: keep 86/91 unless implementation adds enough typedef/source API detail to justify a small support bump.
[UID:0003DE]/[UID:0003DF] vtable data children: keep 88/92.
[UID:0001CT]/[UID:00009I]/[UID:0000M0] registration docs: keep current scores.
```

No manual `-coverage-report.md` edits are requested by this B-agent report. Generated auto coverage should update from source metadata after validators and report execution.

## Recommended Target Doc Changes

Update [UID:0001FK] `by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md`:

1. Update metadata to `90/92`, keep owner/emitter/reconstructable as above.
2. Replace the old final-C++ blocker paragraph with the first-draft C++ readiness decision and remaining below-95 caveats.
3. Insert the constructor formal C++ block exactly into the formal `RECONSTRUCTION_CPP CODE` header.
4. Add current MCP evidence:
   - `lookup_funcs` target size `0x2ed`.
   - `decompile`/`disasm` parse and callback flow.
   - `xrefs_to` constructor call at `0x0054ca33`.
   - vtable stores at `0x0055366e/0x00553674/0x0055367e`.
   - callback vtable/member/bound-this stores at `0x0055388f/0x00553895/0x0055389c/0x005538a3`.
5. Add packet-layout table from this report.
6. Add field-name table for `m_dialogType`, `m_dialogId`, `m_dialogState`, and `m_dialogPageIndex`.
7. Add consumed/discarded packet-field note for the two layout bytes and two button-caption strings.
8. Add rejected alternatives:
   - not TextDialog-owned;
   - not registration-dialog-owned;
   - not MessageDialogs-owned except dispatcher wrapper/caller;
   - not hand-emitting vtables/destructor thunks.
9. Update Item Summary to the recommended text above.

## Recommended Support Doc Changes

Update [UID:00009H] `by-class/NexonclubProxyDialog.md`:

- Raise to `88/90`.
- Add a field table with `m_dialogType`, `m_dialogId`, `m_dialogState`, `m_dialogPageIndex` at `+0x26c/+0x270/+0x274/+0x276`.
- Rename method role row for `0x005534a0` to `OnReplyText`.
- Add constructor parse summary with object-status skip, main-text conversion, button-caption consumption, callback wrapper construction, and registration handoff.
- Keep class-level formal C++ blank unless a class declaration-only pass is explicitly accepted; method-body C++ belongs in exact by-memory pages.

Update [UID:0000LZ] `by-file/NexonclubProxyDialog.md`:

- Raise to `87/90`.
- Add current-source placement rationale: compact private proxy adapter, not TextDialog; registration dialog is callee/consumer; message dialog wrapper is dispatcher/caller.
- Add that final source package may later merge with another dialog source file only in a broader source-tree pass, not as a current owner blocker.
- Add method map names `NexonclubProxyDialog::OnReplyText` and `NexonclubProxyDialog::NexonclubProxyDialog`.

Update [UID:0003GL] `by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md`:

- Raise to `89/92`.
- Add formal callback C++ block above.
- Add field name reuse and packet layout for opcode `0x3a`, subtype `2`, `m_dialogPageIndex + 1`, one-byte wide-string append, `g_packetSender`, and close.
- Add empty-string fallback to `SendDialogPacketCurrent` then close.
- Add `OnReplyText` naming rationale and rejected alternatives.

Update [UID:0003GK] `by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md`:

- Add cross-link that constructor C++ should express this as `new PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>(this, &NexonclubProxyDialog::OnReplyText)`.
- No score change required.

Update [UID:0003DE] and [UID:0003DF] vtable data pages:

- Add cross-link to the new constructor/callback first-draft C++ if not already present.
- Keep formal C++ blank/no-code generated data disposition.

Update [UID:0001CT], [UID:00009I], and [UID:0000M0] registration-dialog docs:

- Add support note that this proxy constructor provides the concrete `NexonclubProxyDialog::OnReplyText` result callback and passes it with the parsed main text to `NexonclubRegistrationDialog`.
- Do not change registration scores from this pass.

Update [UID:00023M] `MessageDialogPacketDispatcherAndWrappers`:

- Replace the stale/generated wrapper label for `0x0054c9f0` with source-facing proxy allocation wrapper wording where this wrapper is discussed.
- Keep owner/emitter unchanged.

Update [UID:00023N] `SharedDialogDefaultDestructorThunksLate`:

- No score change. Ensure it remains a no-code destructor thunk support page and is not a blocker for [UID:0001FK] constructor C++.

## Validator Commands After Accepted Implementation

Run scoped validators from `source-3/project-documentation` after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0001FK-NexonclubProxyDialogConstructor-source-quality-removed.md](0001FK-NexonclubProxyDialogConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run validators for files actually edited. If implementation leaves an optional support doc unchanged because it already has equal-or-greater detail, record that in the checklist and skip that validator.

## IDA Rename / Comment / Type Recommendations

No IDA DB edits are authorized in this report-only assignment.

If a future C-agent/IDA callback is approved, safe candidate names/comments:

- Rename `sub_553610` to `NexonclubProxyDialog_ctor` or the project's accepted C++ method naming equivalent.
- Rename `sub_5534A0` to `NexonclubProxyDialog_OnReplyText`.
- Comment `0x00553699`: `store dialog type byte at NexonclubProxyDialog+0x26c`.
- Comment `0x005536a8`: `store dialog id at +0x270 from PacketBufferReadUInt32BE(packet+1)`.
- Comment `0x005536c1`: `force tagged object/status mode 2 for item/object-kind packet`.
- Comment `0x005536d2`: `parse embedded ObjectStatusBlob to compute cursor advance`.
- Comment `0x005536ee` and `0x00553701`: `store dialog state/page reply words at +0x274/+0x276`.
- Comment `0x0055388f`: `construct PlainMemberFunctionObjectT callback vtable for OnReplyText`.
- Comment `0x00553895`: `store bound member target NexonclubProxyDialog::OnReplyText`.
- Comment `0x005538d3`: `construct NexonclubRegistrationDialog(messageText, callback)`.

These are recommendations only; do not apply them without explicit IDA-edit authorization.

## Implementation Tracking Checklist

Implementation callback status: completed by B008 on 2026-06-26.

- [x] [UID:0001FK] target metadata changed to `COMPLETION:90`, `CONFIDENCE:92`, owner/emitter/reconstructable unchanged, Item Summary updated.
  - Proof: `by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md` header now has `90/92`, `CANONICAL_OWNER:00009H`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009H`, and the new concise Item Summary.
- [x] [UID:0001FK] old final-C++ blocker paragraph replaced with current first-draft C++ readiness and below-95 caveats.
  - Proof: target `Reconstruction Notes` now says former packet/local/callback/destructor blockers are resolved for first-draft output and lists below-95 caveats for packet typedef, discarded layout bytes, typedef spelling, and source-file packaging.
- [x] [UID:0001FK] constructor formal `RECONSTRUCTION_CPP CODE` block inserted exactly from this report or with supervisor-approved typedef-only adjustments.
  - Proof: target formal block contains `NexonclubProxyDialog::NexonclubProxyDialog(unsigned char *packet)` with the accepted parse, status skip, text/caption conversions, `PlainMemberFunctionObjectT` allocation, `OnReplyText` binding, and registration handoff.
- [x] [UID:0001FK] packet-layout table, field-name table, consumed/discarded bytes/captions, MCP evidence, positive/negative evidence, and rejected owner alternatives incorporated at report-level detail.
  - Proof: target now has `Current MCP Evidence`, `Packet Layout And Field Names`, consumed/discarded caption/layout details, `OnReplyText` naming alternatives, and rejected owner alternatives for registration/message/TextDialog/utility owners.
- [x] [UID:00009H] class page raised to `88/90` with field table, method names, constructor/callback relationship, and no-code vtable/destructor policy.
  - Proof: `by-class/NexonclubProxyDialog.md` has `COMPLETION:88`, `CONFIDENCE:90`, a `Field Layout` table for `+0x26c/+0x270/+0x274/+0x276`, method rows for `OnReplyText` and constructor, constructor parse summary, callback source expression, and explicit no-code policy for vtables/destructor thunks.
- [x] [UID:0000LZ] file page raised to `87/90` with source-placement rationale and method map/source role updates.
  - Proof: `by-file/NexonclubProxyDialog.md` has `COMPLETION:87`, `CONFIDENCE:90`, compact private proxy adapter rationale, proxy-vs-registration-vs-message-dispatch separation, and method/source names for `OnReplyText` and constructor.
- [x] [UID:0003GL] reply callback page raised to `89/92`, formal callback C++ block inserted, field names and callback-name rationale added.
  - Proof: `by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md` has `89/92`, formal `void NexonclubProxyDialog::OnReplyText(const StringBaseW& text)` block, opcode `0x3a` packet layout table, empty-text fallback, field reuse, and rejected name alternatives.
- [x] [UID:0003GK] callback-wrapper class cross-link updated.
  - Proof: `by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md` now records the source expression `new PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>(this, &NexonclubProxyDialog::OnReplyText)` and keeps no formal C++ / no score change.
- [x] [UID:0003DE] proxy vtable data page cross-link/no-code support updated.
  - Proof: `by-memory/0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData.md` now has `No-Code / Source Linkage` tying the generated table to the exact constructor/callback pages and keeping blank formal C++.
- [x] [UID:0003DF] callback vtable data page cross-link/no-code support updated.
  - Proof: `by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md` now records the accepted `OnReplyText` allocation expression and keeps blank formal C++.
- [x] [UID:0001CT], [UID:00009I], and [UID:0000M0] registration-dialog support pages updated with the proxy callback provider/registration consumer relationship.
  - Proof: the aggregate, class, and file pages now say the proxy constructor provides the decoded prompt plus `PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>(this, &NexonclubProxyDialog::OnReplyText)`, while registration stores/releases/invokes the result callback after construction. Registration scores stayed unchanged.
- [x] [UID:00023M] message-dialog dispatcher/wrapper page updated to reject the stale wrapper function label for `0x0054c9f0`.
  - Proof: `by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md` now names the `0x0054c9f0-0x0054ca49` range as a proxy allocation wrapper / `CreateNexonclubProxyDialog`, rejects `___std_parallel_algorithms_hw_threads@0_9`-style pollution, and keeps owner/emitter unchanged.
- [x] [UID:00023N] late destructor thunk page confirmed still no-code support and not a constructor-C++ blocker.
  - Proof: read-only confirmation from `by-memory/0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate.md`: it is already `88/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/C++, and explicitly documents the two `this -= 0xa0/0xa4` thunks as compiler glue. No edit was needed.
- [x] Scoped validators run for every edited by-* doc from `source-3/project-documentation`.
  - Proof: all commands below exited `0` with `ok: 1`; each reported `generated_refresh: deferred` and `projected_stats_update: 1` unless otherwise noted.

| File | command_id | command_timestamp | Exit | ok | Noted warnings/side effects |
| --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md` | `000000002825` | `2026-06-26T15:31:03-04:00` | `0` | `1` | Existing missing UID/path refs for some support pages and stale [UID:0001FJ] target path; validator added UID links for PacketBuffer/ObjectStatusBlob; projected stats updated. |
| `by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md` | `000000002826` | `2026-06-26T15:31:08-04:00` | `0` | `1` | Path mapping for [UID:0003GL] added; existing stale [UID:0001FJ] target path warnings; projected stats updated. |
| `by-class/NexonclubProxyDialog.md` | `000000002827` | `2026-06-26T15:31:09-04:00` | `0` | `1` | Existing missing UID warnings for support pages; projected stats updated. |
| `by-file/NexonclubProxyDialog.md` | `000000002829` | `2026-06-26T15:31:11-04:00` | `0` | `1` | Existing missing UID warnings; stats row removed and rescore recommended for generated stats; projected stats updated. |
| `by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md` | `000000002830` | `2026-06-26T15:31:14-04:00` | `0` | `1` | Path mapping for [UID:0003GK] added; existing missing [UID:0003DF] refs; projected stats updated. |
| `by-memory/0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData.md` | `000000002831` | `2026-06-26T15:31:15-04:00` | `0` | `1` | Path mapping for [UID:0003DE] added; projected stats updated. |
| `by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md` | `000000002832` | `2026-06-26T15:31:17-04:00` | `0` | `1` | Path mapping for [UID:0003DF] added; projected stats updated. |
| `by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md` | `000000002833` | `2026-06-26T15:31:18-04:00` | `0` | `1` | Existing stale [UID:0001FJ] target path warning; projected stats updated. |
| `by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md` | `000000002834` | `2026-06-26T15:31:25-04:00` | `0` | `1` | Projected stats updated. |
| `by-class/NexonclubRegistrationDialog.md` | `000000002835` | `2026-06-26T15:31:35-04:00` | `0` | `1` | Existing missing [UID:0003C7] refs; stats row removed and rescore recommended; projected stats updated. |
| `by-file/NexonclubRegistrationDialog.md` | `000000002836` | `2026-06-26T15:31:36-04:00` | `0` | `1` | Existing missing [UID:0003C7] refs; projected stats updated. |

- [x] No manual generated files, project-level files, manual `-coverage-report.md`, validator/tool state, or IDA DB edits.
  - Proof: manual edits were limited to listed by-* docs and this B008 report. Validator commands reported projected stats updates and deferred generated refresh, which are validator-owned side effects, not manual edits.
- [x] Implementation leases used only for the immediate edit/validator batch and released immediately after validators.
  - Proof: `python .\leaser.py B008 lease ...` succeeded for the 11 edited by-* files; `python .\leaser.py B008 unlease` succeeded for all 11 files; `tools/leaser/Agents/current_leases.md` then reported `No active leases.`
- [x] Supervisor executes this report through the validator only after claim-by-claim implementation verification.
  - Proof: B008 did not execute/archive this report. It is ready for supervisor verification and validator `execute_report` lifecycle handling.

## Blockers

No blocker remains for report acceptance or for [UID:0001FK] first-draft constructor C++.

Remaining below-final blockers:

- Exact original packet struct/typedef spelling remains inferred.
- Two consumed/discarded layout/caption bytes need broader message-dialog schema naming before final audit.
- Exact final `StringBaseW` and callback template typedef spelling must be synchronized with FunctionObjects/StringBase source policy.
- Physical source-file packaging could later merge the small private adapter into another dialog source file, but the current owner/emitter route remains valid.

These are score caps below `95/95`; they are not reasons to keep the current page at `85` or to leave formal draft C++ blank.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B008/research/0001FK-NexonclubProxyDialogConstructor-source-quality.md`

Implementation callback edits:

- `by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md`
- `by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md`
- `by-class/NexonclubProxyDialog.md`
- `by-file/NexonclubProxyDialog.md`
- `by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md`
- `by-memory/0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData.md`
- `by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md`
- `by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md`
- `by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md`
- `by-class/NexonclubRegistrationDialog.md`
- `by-file/NexonclubRegistrationDialog.md`

Support reviewed but not edited:

- `by-memory/0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate.md` already had the accepted no-code compiler-glue disposition at same-or-greater detail.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0001FK-NexonclubProxyDialogConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0001FK-NexonclubProxyDialogConstructor-source-quality.md","timestamp":"2026-06-26T15:44:51","uid":"0001FK"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001FK-NexonclubProxyDialogConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0001FK-NexonclubProxyDialogConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001FK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
