** TARGET-REPORT-UID:0000O0 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# B002 Report - [UID:0000O0] SpellInputPanes Empty Emitter Family

## Final Recommendation

Implement the SpellInputPanes empty-emitter family as a bounded source-quality repair batch. The current generated symptom is not one missing function; it is a mix of real source-owned classes/methods, compiler data, one retained raw no-route helper, and one aggregate index page that is still marked as an emitter.

Recommended action:

- Add real source declarations/bodies for the spell argument input panes whose behavior is directly supported by MCP decompilation: class declarations, constructors, argument confirm/submit handlers, slot key/submit handlers, and destructors.
- Add short coverage comments for compiler vtable data and for the SpellString scalar deleting destructor; do not hand-author raw vtable bytes or scalar-delete mechanics.
- Remove emitter participation from the retained no-route raw helper `[UID:0002S6]` and aggregate index `[UID:0001LN]` instead of inventing fallback code.
- Do not implement or reclassify unrelated TargetSelection/PacketBuffer/Socket/ProtocolSend/SpellInventory/Command rows in this callback.

The initial research pass was report-only. The accepted bounded implementation callback has now been applied; callback results, validator proof, generated-output freshness, exclusions, and lease closure are recorded below.

## MCP Session And Evidence Quality

MCP was available and was used for this report. Live session facts used for this evidence pass:

- Session: `supervisor_resume_20260629`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Worker PID reported by `idb_list`: `17592`
- `server_health`: `status=ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Bounded memory read: `get_bytes` at `0x00401000` size 1 returned `0x8b`.

Primary MCP-backed conclusions:

- Constructors at `0x005b0780`, `0x005b0ac0`, `0x005b0da0`, `0x005b1030`, `0x005b1280`, and `0x005adf40` are real functions, not data. Each has three code xrefs from spell inventory dispatchers around `0x0057c9b0`, `0x0057e2d0`, and `0x0057f030`.
- Numeric constructors call `NumberArgsInputPane(false)`, store `m_spellIndex` at `this+0x108`, and set prompt text from `dword_67A748 + 0x13a794 + 0x148 * spellIndex`.
- Slot constructor calls `CharInputPane(false)`, stores `m_spellIndex`, and uses the same spell prompt lookup.
- String constructor calls `LineInputPane(false)`, stores `m_spellIndex`, and uses the same spell prompt lookup.
- Four/three/two/one-argument handlers all send spell opcode `0x0f`, write `m_spellIndex` as byte 1, encode parsed `_wtol` arguments as big-endian 16-bit fields through the local packet word writer, terminate the scratch buffer, and queue the exact payload lengths `10`, `8`, `6`, and `4`.
- Slot submit sends spell opcode `0x0f`, `m_spellIndex`, and one mapped letter slot, with exact payload length `3`.
- Slot key handler owns the `?` shortcut that switches the general purpose panel to tab `3`, plays effect `0x198` for `100`, and otherwise delegates to `CharInputPane::OnKeyInput`.
- Scalar deleting destructors at `0x005b7c20`, `0x005b7cf0`, `0x005b7dc0`, `0x005b7e90`, `0x005b7f60`, and `0x005b8030` are compiler wrappers. They also expose the real cleanup behavior: clear child pane index `3` input-mode state through either the EPF item-who state setter or the legacy spell state setter, then run the base destructor and optional scalar delete.
- Vtable ranges `0x0062fad0-0x0062fb58` and `0x0063041c-0x006304a4` are `.rdata` vtable/RTTI material. Their method pointers already resolve into exact child functions; the emitted C++ should not try to reproduce binary vtable arrays.
- `[UID:0002S6]` `0x005b3410-0x005b3485.ChangeSpellSlotPacketRawSender` is not a function in current MCP lookup and has no xrefs. Treat it as a retained no-route raw-helper page, not an emitter.

## Report-Time Empty Marker Inventory And Disposition

Generated file inspected: `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp`

Header command ID: `000000001286`

Refresh timestamp: `2026-06-29T22:06:24-04:00`

Report-time generated symptom before the implementation callback: 30 empty implementation markers under `[UID:0000O0]`.

| UID | Current marker | Recommended disposition |
| --- | --- | --- |
| `00001M` | `by-class/ChangeSpellSlotInputPane.md` | Add class declaration with `[[CHILDREN]]`. |
| `0002S6` | `ChangeSpellSlotPacketRawSender` | Remove `EMITTER_UIDS:0000O0`; leave retained no-route helper non-emitting. |
| `0002N5` | `ChangeSpellSlotInputPaneVtableData` | Add coverage comment only. |
| `0000DL` | `SpellFourArgsInputPane` class | Add class declaration with `[[CHILDREN]]`. |
| `0001LM` | FourArgs constructor | Add constructor body. |
| `0001LO` | FourArgs confirm | Add confirm body. |
| `0001NE` | FourArgs scalar destructor | Add source destructor body, not scalar-delete wrapper code. |
| `0000DR` | `SpellOneArgInputPane` class | Add class declaration with `[[CHILDREN]]`. |
| `0001LT` | OneArg constructor | Add constructor body. |
| `0001LU` | OneArg submit | Add submit body. |
| `0001NF` | OneArg scalar destructor | Add source destructor body, not scalar-delete wrapper code. |
| `0000DS` | `SpellSlotInputPane` class | Add class declaration with `[[CHILDREN]]`. |
| `0001LV` | Slot constructor | Add constructor body. |
| `0001LW` | Slot key | Add key handler body. |
| `0001LX` | Slot submit | Add submit body. |
| `0001NG` | Slot scalar destructor | Add source destructor body, not scalar-delete wrapper code. |
| `0000DT` | `SpellSpellInputPane` class | Add class declaration with `[[CHILDREN]]`; exact child bodies already exist. |
| `0002N7` | `SpellSpellInputPaneVtableData` | Add coverage comment only. |
| `0000DU` | `SpellStringInputPane` class | Add class declaration with `[[CHILDREN]]`. |
| `0001KU` | String constructor | Add constructor body. |
| `0001NH` | String scalar destructor | Add coverage comment pointing to direct destructor page `[UID:0003AG]`; add real destructor body there. |
| `0000DV` | `SpellThreeArgsInputPane` class | Add class declaration with `[[CHILDREN]]`. |
| `0001LP` | ThreeArgs constructor | Add constructor body. |
| `0001LQ` | ThreeArgs confirm | Add confirm body. |
| `0001NI` | ThreeArgs scalar destructor | Add source destructor body, not scalar-delete wrapper code. |
| `0000DW` | `SpellTwoArgsInputPane` class | Add class declaration with `[[CHILDREN]]`. |
| `0001LR` | TwoArgs constructor | Add constructor body. |
| `0001LS` | TwoArgs confirm | Add confirm body. |
| `0001NJ` | TwoArgs scalar destructor | Add source destructor body, not scalar-delete wrapper code. |
| `0001LN` | `SpellArgumentInputPanes` aggregate | Change to non-reconstructable aggregate: clear emitter UID and leave formal code blank. |

## Source-Quality Conclusions

### Accepted ownership

`by-file/SpellInputPanes.md` remains the correct file owner for these panes. MCP xrefs place the constructors in spell inventory dispatcher paths and the virtual slots are referenced from pane vtables. The packet opcode, prompt-record lookup, and tab shortcut all match the spell argument pane family already described in the target file.

### Raw helper family

The raw packet sender family remains split by source ownership:

- `[UID:0003VT]` four-arg raw, `[UID:0003VU]` three-arg raw, and `[UID:0003VW]` one-arg raw are ownerless/non-emitting raw helper artifacts under existing B-agent reports.
- `[UID:0003VV]` two-arg raw remains a retained no-route helper under SpellTwoArgs pending final retained-helper policy.
- `[UID:0003VX]` slot raw remains the retained slot helper documented by the B013 report.
- `[UID:0002S6]` ChangeSpellSlot packet raw sender is currently not a function and has no xrefs in MCP; it should not be emitted from SpellInputPanes.

No raw helper should be imported into `[UID:0000O0]` as invented source code during this batch.

### Class declarations

Class declaration pages can safely emit source declarations with `[[CHILDREN]]`. This matches local class-page precedent and keeps exact child method bodies on their existing by-memory pages.

Use these inheritance and member conclusions:

- `ChangeSpellSlotInputPane : public CharArgsInputPane`
- `SpellFourArgsInputPane : public NumberArgsInputPane`
- `SpellThreeArgsInputPane : public NumberArgsInputPane`
- `SpellTwoArgsInputPane : public NumberArgsInputPane`
- `SpellOneArgInputPane : public NumberArgsInputPane`
- `SpellSlotInputPane : public CharInputPane`
- `SpellStringInputPane : public LineInputPane`
- `SpellSpellInputPane : public CharInputPane`
- Spell argument classes that store the selected spell use `unsigned char m_spellIndex` for `this+0x108`.

### Constructors

Constructors should use the accepted local spell-record naming already present in earlier B-agent work:

```cpp
const UserSpellRecord& spell = g_pUserPane->GetSpellRecord(spellIndex);
SetPromptText(spell.promptText);
```

This is a source-level replacement for the raw MCP expression `dword_67A748 + 0x13a794 + 0x148 * spellIndex`. It follows existing accepted reports around SpellString/SpellSlot/SpellSpell instead of introducing a new global name.

### Packet writer naming

Use the packet helper names already accepted by the current filled generated code:

- `PacketBufferWriteUInt8`
- `PacketBufferWriteUInt16BE`
- `QueueAndSendPacket`
- `g_packetSender`

Do not import `PacketBuffer`, `Socket`, `ProtocolSend`, or generic command ownership into this file.

### Destructors

For numeric/slot scalar destructor pages, this report recommends emitting the ordinary C++ destructor body on the scalar page because no separate direct destructor by-memory pages were found for those exact source bodies. Local precedent permits source destructor bodies on scalar pages when the scalar page is the only exact page for the cleanup behavior. Do not hand-author vtable assignment, base destructor, delete-flag, or `operator delete` mechanics.

For `SpellStringInputPane`, there is already a direct destructor page `[UID:0003AG]` at `0x005adfd0-0x005ae053`. Put the real `SpellStringInputPane::~SpellStringInputPane()` body there and leave `[UID:0001NH]` as a compiler-wrapper coverage comment.

The cleanup body is the same family pattern for all spell argument panes:

```cpp
if (g_useEpfAssets) {
    static_cast<ItemWhoInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
} else {
    static_cast<SpellInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
}
```

MCP support for the state setters:

- `0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag` formal source sets `m_active = active` and returns `active`.
- `0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag` formal source sets `m_spellInputActive = active` and returns `active`.

### Aggregate page

`by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md` is an index/split container. Under the current by-structure code-entry gate, parent aggregate pages should not emit code unless they own a real source construct. This page should be `RECONSTRUCTABLE:FALSE`, `EMITTER_UIDS:` blank, and formal code blank, while preserving its evidence text and `CANONICAL_OWNER:0000O0`.

## Exact Implementation Payload

### Class declarations

Use the following class declaration shapes. Method bodies remain on exact child pages.

```cpp
class ChangeSpellSlotInputPane : public CharArgsInputPane
{
public:
    ChangeSpellSlotInputPane();
    virtual bool OnKeyInput(const InputEvent *event);
    virtual void SubmitSpellSlotChange();

    [[CHILDREN]]
};
```

```cpp
class SpellFourArgsInputPane : public NumberArgsInputPane
{
public:
    explicit SpellFourArgsInputPane(unsigned char spellIndex);
    virtual ~SpellFourArgsInputPane();

protected:
    virtual void OnConfirmInput();

private:
    unsigned char m_spellIndex;

    [[CHILDREN]]
};
```

Apply the same class shape to `SpellThreeArgsInputPane` and `SpellTwoArgsInputPane`.

```cpp
class SpellOneArgInputPane : public NumberArgsInputPane
{
public:
    explicit SpellOneArgInputPane(unsigned char spellIndex);
    virtual ~SpellOneArgInputPane();

protected:
    virtual void OnSubmitInput();

private:
    unsigned char m_spellIndex;

    [[CHILDREN]]
};
```

```cpp
class SpellSlotInputPane : public CharInputPane
{
public:
    explicit SpellSlotInputPane(unsigned char spellIndex);
    virtual ~SpellSlotInputPane();

    virtual bool OnKeyInput(const InputEvent *event);
    virtual void SubmitSpellSlot();

private:
    unsigned char m_spellIndex;

    [[CHILDREN]]
};
```

```cpp
class SpellStringInputPane : public LineInputPane
{
public:
    explicit SpellStringInputPane(unsigned char spellIndex);
    virtual ~SpellStringInputPane();

protected:
    virtual void OnConfirmInput();

private:
    unsigned char m_spellIndex;

    [[CHILDREN]]
};
```

```cpp
class SpellSpellInputPane : public CharInputPane
{
public:
    SpellSpellInputPane();
    virtual ~SpellSpellInputPane();

    virtual bool OnKeyInput(const InputEvent *event);
    virtual void OnAccept();

    [[CHILDREN]]
};
```

### Constructor bodies

Use this body for four/three/two/one-argument panes, with the class name changed.

```cpp
SpellFourArgsInputPane::SpellFourArgsInputPane(unsigned char spellIndex)
    : NumberArgsInputPane(false),
      m_spellIndex(spellIndex)
{
    const UserSpellRecord& spell = g_pUserPane->GetSpellRecord(spellIndex);
    SetPromptText(spell.promptText);
}
```

Slot constructor:

```cpp
SpellSlotInputPane::SpellSlotInputPane(unsigned char spellIndex)
    : CharInputPane(false),
      m_spellIndex(spellIndex)
{
    const UserSpellRecord& spell = g_pUserPane->GetSpellRecord(spellIndex);
    SetPromptText(spell.promptText);
}
```

String constructor:

```cpp
SpellStringInputPane::SpellStringInputPane(unsigned char spellIndex)
    : LineInputPane(false),
      m_spellIndex(spellIndex)
{
    const UserSpellRecord& spell = g_pUserPane->GetSpellRecord(spellIndex);
    SetPromptText(spell.promptText);
}
```

### Argument packet handlers

Four arguments:

```cpp
void SpellFourArgsInputPane::OnConfirmInput()
{
    if (GetTextLength() <= 0) {
        return;
    }

    wchar_t text[256];
    CopyText(text, 255);

    wchar_t *firstComma = wcschr(text, L',');
    if (firstComma == NULL) {
        return;
    }

    wchar_t *secondComma = wcschr(firstComma + 1, L',');
    if (secondComma == NULL) {
        return;
    }

    wchar_t *thirdComma = wcschr(secondComma + 1, L',');
    if (thirdComma == NULL) {
        return;
    }

    const short firstArgument = static_cast<short>(_wtol(text));
    const short secondArgument = static_cast<short>(_wtol(firstComma + 1));
    const short thirdArgument = static_cast<short>(_wtol(secondComma + 1));
    const short fourthArgument = static_cast<short>(_wtol(thirdComma + 1));

    unsigned char packet[11];
    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(m_spellIndex, packet + 1);
    PacketBufferWriteUInt16BE(firstArgument, packet + 2);
    PacketBufferWriteUInt16BE(secondArgument, packet + 4);
    PacketBufferWriteUInt16BE(thirdArgument, packet + 6);
    PacketBufferWriteUInt16BE(fourthArgument, packet + 8);
    packet[10] = 0;

    QueueAndSendPacket(g_packetSender, packet, 10);
}
```

Three arguments: same structure, require two commas, parse three arguments, write bytes at offsets `2`, `4`, and `6`, set `packet[8] = 0`, and send length `8`.

Two arguments: same structure, require one comma, parse two arguments, write bytes at offsets `2` and `4`, set `packet[6] = 0`, and send length `6`.

One argument:

```cpp
void SpellOneArgInputPane::OnSubmitInput()
{
    if (GetTextLength() <= 0) {
        return;
    }

    wchar_t text[256];
    CopyText(text, 255);

    const short argument = static_cast<short>(_wtol(text));

    unsigned char packet[5];
    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(m_spellIndex, packet + 1);
    PacketBufferWriteUInt16BE(argument, packet + 2);
    packet[4] = 0;

    QueueAndSendPacket(g_packetSender, packet, 4);
}
```

### Slot handlers

```cpp
bool SpellSlotInputPane::OnKeyInput(const InputEvent *event)
{
    const char key = NarrowInputKey(event->keyCode, event->narrowFallback);

    if (key == '?' &&
        event->narrowFallback == 4 &&
        event->type == 8) {
        g_pGeneralPurposePanel->SwitchActiveTab(3, false);
        g_pSoundManager->PlayEffect(0x198, 100);
        return true;
    }

    return CharInputPane::OnKeyInput(event);
}
```

```cpp
void SpellSlotInputPane::SubmitSpellSlot()
{
    if (GetTextLength() != 1) {
        return;
    }

    wchar_t ch = 0;
    CopyText(&ch, 1);

    unsigned char selectedSlot = 0xff;
    if (ch >= L'a' && ch <= L'z') {
        selectedSlot = static_cast<unsigned char>(ch - L'a' + 1);
    } else if (ch >= L'A' && ch <= L'Z') {
        selectedSlot = static_cast<unsigned char>(ch - L'A' + 27);
    } else {
        return;
    }

    if (selectedSlot < 1 ||
        selectedSlot > g_activeUserStatusPane->m_inventorySlotCount) {
        return;
    }

    unsigned char packet[4];
    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(m_spellIndex, packet + 1);
    PacketBufferWriteUInt8(selectedSlot, packet + 2);
    packet[3] = 0;

    QueueAndSendPacket(g_packetSender, packet, 3);
}
```

The field spelling `m_inventorySlotCount` follows existing local documentation for the `g_activeUserStatusPane + 0x284` byte; if the implementation target already uses a different accepted field name, keep the local accepted name and retain the `+0x284` evidence note.

### Destructor bodies

Use this source-level destructor body for `SpellFourArgsInputPane`, `SpellThreeArgsInputPane`, `SpellTwoArgsInputPane`, `SpellOneArgInputPane`, `SpellSlotInputPane`, and `SpellStringInputPane` direct destructor `[UID:0003AG]`, changing only the class name.

```cpp
SpellFourArgsInputPane::~SpellFourArgsInputPane()
{
    if (g_useEpfAssets) {
        static_cast<ItemWhoInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
    } else {
        static_cast<SpellInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
    }
}
```

For `[UID:0001NH]` `SpellStringInputPaneScalarDeletingDestructor`, use only this coverage comment:

```cpp
// Compiler-generated scalar deleting destructor for SpellStringInputPane.
// Source cleanup is represented by SpellStringInputPane::~SpellStringInputPane()
// at [UID:0003AG][0x005adfd0-0x005ae053.SpellStringInputPaneDirectDestructor](by-memory/0x005adfd0-0x005ae053.SpellStringInputPaneDirectDestructor.md).
```

### Vtable coverage comments

For `[UID:0002N5]`:

```cpp
// Emitted code for this ChangeSpellSlotInputPane vtable/RTTI range is covered by
// [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md)
// and exact virtual method children [UID:0001M9] and [UID:0001MA].
// Do not hand-emit raw .rdata vtable bytes.
```

For `[UID:0002N7]`:

```cpp
// Emitted code for this SpellSpellInputPane vtable/RTTI range is covered by
// [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md)
// and exact virtual method children [UID:0001MP] and [UID:0001MQ].
// Do not hand-emit raw .rdata vtable bytes.
```

### Metadata-only repairs

For `[UID:0002S6]` `ChangeSpellSlotPacketRawSender`:

- Keep `CANONICAL_OWNER:00001M`.
- Clear `EMITTER_UIDS:` so it no longer creates an empty marker under SpellInputPanes.
- Keep formal C++ blank.
- Add/update evidence note: current MCP lookup for `0x005b3410` found no function and no xrefs; retained as no-route raw helper only.

For `[UID:0001LN]` `SpellArgumentInputPanes`:

- Keep `CANONICAL_OWNER:0000O0`.
- Set `RECONSTRUCTABLE:FALSE`.
- Clear `EMITTER_UIDS:`.
- Keep formal C++ blank.
- Add/update evidence note: aggregate/index page only; exact child pages own reconstructable source.

## Rejected Alternatives And Blocker Closure

- Reject emitting raw helper bodies for `[UID:0002S6]`: current MCP does not identify a function or live xrefs at `0x005b3410`.
- Reject emitting `.rdata` vtable arrays: by-structure source-entry rules prefer source declarations and exact method children over compiler data.
- Reject assigning packet sending to PacketBuffer/Socket/ProtocolSend owners: accepted generated code and target-file evidence already route packet writes through source-level spell pane handlers.
- Reject treating `[UID:0001LN]` as a source function: it is an aggregate index page and should not be an emitter.
- Reject leaving the numeric/slot scalar destructor markers blank: current MCP exposes repeated source cleanup semantics and there are no separate direct destructor pages for those classes.
- Reject fallback-only research: MCP was available and the findings above are MCP-backed.

## Implementation Callback Results - 2026-06-29

- Applied only the supervisor-accepted bounded SpellInputPanes batch. No unrelated TargetSelection, PacketBuffer, Socket, ProtocolSend, SpellInventory, Command, or raw-helper follow-up rows were implemented.
- Edited the accepted target/support by-* docs at report-level specificity: class declarations, constructors, packet handlers, slot handlers, destructor source bodies, compiler-data coverage comments, retained-helper metadata repair, and aggregate non-emitter repair.
- Ran scoped file validators for every edited by-* doc. Validator command IDs `000000001418` through `000000001449` all exited `0` with `ok=1`; generated refreshes were deferred by the validator queue.
- Validator warnings were non-blocking `missing_ref_uid` link warnings for existing/adjacent UID references not present in `validator.ini`; no metadata repair was rejected by validator/by-structure.
- The validator-owned generated refresh queue was inspected until the callback batch drained. Queue checkpoint `000000001455` at `2026-06-29T23:02:19-04:00` reported `queued generated refresh jobs: 0` and `processing generated refresh jobs: 0`.
- The callback batch first refreshed `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp` through `validator-command-id: 000000001448`, refreshed at `2026-06-29T22:56:18-04:00`. The final scoped validator `000000001449` was the non-emitting aggregate metadata page, so it produced no further callback-generated header change. A later read-only checkpoint showed validator-owned header `000000001482`, refreshed at `2026-06-29T23:05:49-04:00` with `validator-refresh-source: foreground-generated-refresh`, still preserving the accepted marker-free output.
- Generated inspection found no `Empty Emitter Marker` matches, no `0002S6`/`ChangeSpellSlotPacketRawSender` emission, and no `0001LN`/`SpellArgumentInputPanes` emission. It did show accepted emitted bodies including `SpellFourArgsInputPane::OnConfirmInput`, `SpellSlotInputPane::SubmitSpellSlot`, `SpellStringInputPane::~SpellStringInputPane`, and the `SpellStringInputPane` scalar-wrapper coverage comment.
- B002 leases were released with `python leaser.py B002 unlease`; `tools/leaser/Agents/current_leases.md` then reported `No active leases.`

## Implementation Tracking Checklist

- [x] Acquire short leases only immediately before editing by-* docs, then release them after the edit/validator batch. Proof: B002 held the accepted by-* docs during edits/validators and released them successfully; current lease report says no active leases.
- [x] Add class declarations with `[[CHILDREN]]` to `00001M`, `0000DL`, `0000DR`, `0000DS`, `0000DT`, `0000DU`, `0000DV`, and `0000DW`. Proof: class validators `000000001419` through `000000001426` covered these docs; generated file contains class declarations instead of empty markers.
- [x] Add constructor bodies to `0001LM`, `0001LP`, `0001LR`, `0001LT`, `0001LV`, and `0001KU`. Proof: validators `000000001430`, `000000001433`, `000000001436`, `000000001439`, `000000001442`, and `000000001446` passed.
- [x] Add argument handler bodies to `0001LO`, `0001LQ`, `0001LS`, and `0001LU`. Proof: validators `000000001431`, `000000001434`, `000000001437`, and `000000001440` passed; generated output contains the packet-handler bodies.
- [x] Add slot handler bodies to `0001LW` and `0001LX`. Proof: validators `000000001443` and `000000001444` passed; generated output contains `SpellSlotInputPane::SubmitSpellSlot`.
- [x] Add destructor bodies to `0001NE`, `0001NF`, `0001NG`, `0001NI`, `0001NJ`, and direct destructor `[UID:0003AG]`. Proof: validators `000000001432`, `000000001441`, `000000001445`, `000000001435`, `000000001438`, and `000000001447` passed.
- [x] Add coverage comments to `0001NH`, `0002N5`, and `0002N7`. Proof: validators `000000001448`, `000000001428`, and `000000001429` passed; generated output contains the `SpellStringInputPane` scalar-wrapper coverage comment.
- [x] Clear emitter participation for retained helper `0002S6` without adding source code. Proof: validator `000000001427` passed; generated output has no `0002S6` or `ChangeSpellSlotPacketRawSender` emission.
- [x] Convert aggregate/index page `0001LN` to non-reconstructable/non-emitting without adding source code. Proof: validator `000000001449` passed; generated output has no `0001LN` or `SpellArgumentInputPanes` emission.
- [x] Do not implement the raw helper follow-up inventory rows `0003VT`, `0003VU`, `0003VV`, `0003VW`, or `0003VX` in this batch. Proof: those follow-up rows were not edited; only accepted handler/source pages were changed.
- [x] Do not edit generated files, coverage reports, validator/tool state, IDA DB, executed archives, lock files, or supervisor ledgers. Proof: generated file was inspected only after validator-owned refresh; leaser state was changed only through `leaser.py`.
- [x] Run scoped validators for every edited by-* doc. Proof: validator command IDs `000000001418` through `000000001449`, all exit `0`, `ok=1`.
- [x] Regenerate or inspect the scoped generated `NexusTK/ui/dialogs/SpellInputPanes.cpp` output through the project-approved validator/generator flow, and confirm the generated SpellInputPanes freshness target described in the active callback goal. Proof: queue status `000000001455` showed the callback batch had no queued/processing generated refresh jobs; latest read-only generated checkpoint is validator-owned header `000000001482`.
- [x] Confirm the generated file no longer contains empty markers for the accepted rows and still preserves already-filled SpellString/ChangeSpellSlot/SpellSpell child code. Proof: generated search found no `Empty Emitter Marker` and did find accepted existing/new child bodies.
- [x] Release all leases or allow them to expire before returning implementation completion. Proof: `python leaser.py B002 unlease` succeeded for all B002 leases and the current lease report says no active leases.

## Claim And Incorporation Ledger

| Claim | Target/support doc | Required incorporation | Proof to verify | Status |
| --- | --- | --- | --- | --- |
| `ChangeSpellSlotInputPane` class is source-owned and can emit a declaration. | `by-class/ChangeSpellSlotInputPane.md` | Add class declaration with `[[CHILDREN]]`. | Validator `000000001419`; latest generated header `000000001482` contains the declaration and existing child methods. | applied |
| `SpellFourArgsInputPane` class is source-owned and can emit a declaration. | `by-class/SpellFourArgsInputPane.md` | Add class declaration with `[[CHILDREN]]`. | Validator `000000001420`; generated output contains the class and child bodies. | applied |
| `SpellOneArgInputPane` class is source-owned and can emit a declaration. | `by-class/SpellOneArgInputPane.md` | Add class declaration with `[[CHILDREN]]`. | Validator `000000001421`; generated output contains the class and child bodies. | applied |
| `SpellSlotInputPane` class is source-owned and can emit a declaration. | `by-class/SpellSlotInputPane.md` | Add class declaration with `[[CHILDREN]]`. | Validator `000000001422`; generated output contains the class and child bodies. | applied |
| `SpellSpellInputPane` class can emit declaration while exact children emit behavior. | `by-class/SpellSpellInputPane.md` | Add class declaration with `[[CHILDREN]]`. | Validator `000000001423`; generated output keeps existing constructor/key/accept bodies. | applied; child bodies already-present |
| `SpellStringInputPane` class is source-owned and can emit a declaration. | `by-class/SpellStringInputPane.md` | Add class declaration with `[[CHILDREN]]`. | Validator `000000001424`; generated output contains the class, constructor, destructor, and scalar-wrapper comment. | applied |
| `SpellThreeArgsInputPane` class is source-owned and can emit a declaration. | `by-class/SpellThreeArgsInputPane.md` | Add class declaration with `[[CHILDREN]]`. | Validator `000000001425`; generated output contains the class and child bodies. | applied |
| `SpellTwoArgsInputPane` class is source-owned and can emit a declaration. | `by-class/SpellTwoArgsInputPane.md` | Add class declaration with `[[CHILDREN]]`. | Validator `000000001426`; generated output contains the class and child bodies. | applied |
| `0002S6` is not a live source function in current MCP. | `by-memory/0x005b3410-0x005b3485.ChangeSpellSlotPacketRawSender.md` | Clear `EMITTER_UIDS:` and keep formal code blank. | Validator `000000001427`; generated output has no `0002S6` or `ChangeSpellSlotPacketRawSender` marker/emission. | applied |
| ChangeSpellSlot vtable data should not emit raw bytes. | `by-memory/0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md` | Add coverage comment only. | Validator `000000001428`; generated output has comment coverage, not raw vtable bytes or an empty marker. | applied |
| SpellSpell vtable data should not emit raw bytes. | `by-memory/0x0063041c-0x006304a4.SpellSpellInputPaneVtableData.md` | Add coverage comment only. | Validator `000000001429`; generated output has comment coverage, not raw vtable bytes or an empty marker. | applied |
| Four-arg pane constructor uses `NumberArgsInputPane(false)` and spell prompt record. | `by-memory/0x005b0780-0x005b080d.SpellFourArgsInputPaneConstructor.md` | Add constructor body. | Validator `000000001430`; generated body sets `m_spellIndex` and prompt text. | applied |
| Four-arg confirm sends opcode `0x0f` with four 16-bit args, length `10`. | `by-memory/0x005b08a0-0x005b0a02.SpellFourArgsInputPaneConfirmInput.md` | Add confirm body. | Validator `000000001431`; generated body requires three commas and sends length `10`. | applied |
| Four-arg destructor clears child index 3 input-mode state. | `by-memory/0x005b7c20-0x005b7ce4.SpellFourArgsInputPaneScalarDeletingDestructor.md` | Add source destructor body only. | Validator `000000001432`; generated body has source cleanup only, no scalar-delete mechanics. | applied |
| Three-arg pane constructor uses `NumberArgsInputPane(false)` and spell prompt record. | `by-memory/0x005b0ac0-0x005b0b4d.SpellThreeArgsInputPaneConstructor.md` | Add constructor body. | Validator `000000001433`; generated body sets `m_spellIndex` and prompt text. | applied |
| Three-arg confirm sends opcode `0x0f` with three 16-bit args, length `8`. | `by-memory/0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput.md` | Add confirm body. | Validator `000000001434`; generated body requires two commas and sends length `8`. | applied |
| Three-arg destructor clears child index 3 input-mode state. | `by-memory/0x005b7f60-0x005b8024.SpellThreeArgsInputPaneScalarDeletingDestructor.md` | Add source destructor body only. | Validator `000000001435`; generated body has source cleanup only, no scalar-delete mechanics. | applied |
| Two-arg pane constructor uses `NumberArgsInputPane(false)` and spell prompt record. | `by-memory/0x005b0da0-0x005b0e2d.SpellTwoArgsInputPaneConstructor.md` | Add constructor body. | Validator `000000001436`; generated body sets `m_spellIndex` and prompt text. | applied |
| Two-arg confirm sends opcode `0x0f` with two 16-bit args, length `6`. | `by-memory/0x005b0ec0-0x005b0f9e.SpellTwoArgsInputPaneConfirmInput.md` | Add confirm body. | Validator `000000001437`; generated body requires one comma and sends length `6`. | applied |
| Two-arg destructor clears child index 3 input-mode state. | `by-memory/0x005b8030-0x005b80f4.SpellTwoArgsInputPaneScalarDeletingDestructor.md` | Add source destructor body only. | Validator `000000001438`; generated body has source cleanup only, no scalar-delete mechanics. | applied |
| One-arg pane constructor uses `NumberArgsInputPane(false)` and spell prompt record. | `by-memory/0x005b1030-0x005b10bd.SpellOneArgInputPaneConstructor.md` | Add constructor body. | Validator `000000001439`; generated body sets `m_spellIndex` and prompt text. | applied |
| One-arg submit sends opcode `0x0f` with one 16-bit arg, length `4`. | `by-memory/0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput.md` | Add submit body. | Validator `000000001440`; generated body parses `_wtol` and sends length `4`. | applied |
| One-arg destructor clears child index 3 input-mode state. | `by-memory/0x005b7cf0-0x005b7db4.SpellOneArgInputPaneScalarDeletingDestructor.md` | Add source destructor body only. | Validator `000000001441`; generated body has source cleanup only, no scalar-delete mechanics. | applied |
| Slot constructor uses `CharInputPane(false)` and spell prompt record. | `by-memory/0x005b1280-0x005b130d.SpellSlotInputPaneConstructor.md` | Add constructor body. | Validator `000000001442`; generated body sets `m_spellIndex` and prompt text. | applied |
| Slot key owns the `?` general-purpose tab shortcut. | `by-memory/0x005b13a0-0x005b140c.SpellSlotInputPaneKeyInput.md` | Add key handler body. | Validator `000000001443`; generated body switches tab `3`, plays `0x198`, and delegates otherwise. | applied |
| Slot submit maps letters to slots and sends opcode `0x0f`, length `3`. | `by-memory/0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot.md` | Add submit body. | Validator `000000001444`; generated body maps `a-z`/`A-Z`, bounds-checks, and sends length `3`. | applied |
| Slot destructor clears child index 3 input-mode state. | `by-memory/0x005b7dc0-0x005b7e84.SpellSlotInputPaneScalarDeletingDestructor.md` | Add source destructor body only. | Validator `000000001445`; generated body has source cleanup only, no scalar-delete mechanics. | applied |
| String constructor uses `LineInputPane(false)` and spell prompt record. | `by-memory/0x005adf40-0x005adfcd.SpellStringInputPaneConstructor.md` | Add constructor body. | Validator `000000001446`; generated body sets `m_spellIndex` and prompt text. | applied |
| String destructor source body belongs on direct destructor support page. | `by-memory/0x005adfd0-0x005ae053.SpellStringInputPaneDirectDestructor.md` | Add destructor body. | Validator `000000001447`; generated output contains `SpellStringInputPane::~SpellStringInputPane`. | applied |
| String scalar deleting destructor is compiler wrapper only. | `by-memory/0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor.md` | Add coverage comment only. | Validator `000000001448`; generated output contains scalar-wrapper coverage comment pointing to `0003AG`. | applied |
| SpellArgumentInputPanes aggregate is an index/split container. | `by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md` | Set non-reconstructable, clear emitter, keep code blank. | Validator `000000001449`; generated output has no `0001LN` or `SpellArgumentInputPanes` marker/emission. | applied |
| Raw helper follow-up inventory rows remain out of this callback. | `0003VT`, `0003VU`, `0003VV`, `0003VW`, `0003VX` | Do not implement or add no-code markers in this bounded batch. | No edits were made to those follow-up rows; accepted source handlers now own this callback's emitted behavior. | excluded-with-reason: outside accepted bounded batch |
| Generated files, coverage reports, validator/tool state, IDA DB, executed archives, lock files, and supervisor ledgers are out of scope for manual edits. | Project generated/state files | Inspect validator-owned generated output only; do not manually edit. | Generated file changed only through validator-owned refresh; `lease.lock`, validator state, IDA DB, and supervisor ledgers were not manually edited. | excluded-with-reason: prohibited by goal |

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0000O0-SpellInputPanes-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0000O0-SpellInputPanes-empty-emitter-family-source-quality.md","timestamp":"2026-06-29T23:08:27","uid":"0000O0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
