** TARGET-REPORT-UID:0002NS **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002NS-0002NU-0002NW-0002NY-0002O0-0002O2 Clan Submitters Source-Quality Report

Assignment: `B001-goal2-clan-submitters-source-quality-0002NS-0002NU-0002NW-0002NY-0002O0-0002O2-20260617`

## Finalized Report / Current Recommendation

- Current recommendation: keep all six target submitters owned and emitted through their current direct owner classes, raise each target from `82/90` to `86/91`, and populate first-draft method-body C++ in each target's formal `RECONSTRUCTION_CPP CODE` block.
- Final disposition: exact vtable-backed `ClanNameInputDialog` submit overrides in the current `social/Clan.cpp` route.
- Required action: supervisor/A-agent should update target metadata/summaries, replace stale no-code rationale, correct money amount byte-order wording from little-endian to big-endian, enter the C++ blocks below, and apply the listed supervisor-owned by-memory coverage rows.
- Confidence: high for target behavior, direct class ownership, source route, protocol bytes, and C++ readiness; medium-high for exact original helper API spellings because PacketBuffer and Socket final header names remain inferred/descriptive.

## Target

| UID | Target path | Current score | Current owner/emitter | Recommendation |
| --- | --- | ---: | --- | --- |
| [UID:0002NS] | `by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md` | `82/90` | owner/emitter [UID:00002A] | `86/91`, keep owner/emitter, add C++ |
| [UID:0002NU] | `by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md` | `82/90` | owner/emitter [UID:00002O] | `86/91`, keep owner/emitter, add C++ |
| [UID:0002NW] | `by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md` | `82/90` | owner/emitter [UID:00002D] | `86/91`, keep owner/emitter, add C++ |
| [UID:0002NY] | `by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md` | `82/90` | owner/emitter [UID:00002M] | `86/91`, keep owner/emitter, add C++ |
| [UID:0002O0] | `by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md` | `82/90` | owner/emitter [UID:000023] | `86/91`, keep owner/emitter, add C++ |
| [UID:0002O2] | `by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md` | `82/90` | owner/emitter [UID:000028] | `86/91`, keep owner/emitter, add C++ |

The current generated memory report already marks all six as `emits` and routes them to `auto-generated/NexusTK/social/Clan.cpp`, but the generated source file is currently zero bytes because the child C++ blocks are blank.

## Supporting Research

Evidence checked:

- Target pages for [UID:0002NS], [UID:0002NU], [UID:0002NW], [UID:0002NY], [UID:0002O0], and [UID:0002O2].
- Aggregate [UID:00010K] `by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md`.
- Support file/class pages: [UID:0000I8] `by-file/Clan.md`, [UID:0000IA] `by-file/ClanDialogs.md`, [UID:00002J] `ClanNameInputDialog`, and the six owner class pages.
- Support type pages: [UID:0003HE] `ClanModalDialogVtables` and [UID:0001TY] `ClanInputDialogLayouts`.
- Packet helpers: [UID:00021I] `ClanDepositMoneyRequestAndSubmitPacketHelpers`, [UID:00021L] `ClanNameActionPacketHelpers`, [UID:00021M] `ClanWithdrawAndNoticePacketHelpers`.
- PacketBuffer and sender pages: [UID:0003YJ] `PacketBufferScalarBigEndianWriteHelpers`, [UID:0003YO] `PacketBufferStringWriteHelpers`, [UID:0001HU] `QueueAndSendPacket`, [UID:0001P0] `g_packetSender`, [UID:0001O5] `CrtWtolWrapper`, [UID:0001BH] `MemmoveWrapper`, [UID:0001BC] `GetMemoryMan`.
- Current `by-memory/-coverage-report.md`, generated `auto-generated/-ag-memory-coverage.md`, generated class/file/type coverage rows, and generated output file sizes.
- Local IDA export JSON under `hooks-generation/tests/function_data/ida` and `hooks-generation/tests/function_data/raw_ida_export_data/functions` for `0x00488eb0`, `0x00488fe0`, `0x004890b0`, `0x00489180`, `0x004892b0`, `0x004893e0`, and `0x00489510`.
- Prior B001 raw-constructor report `executed/older/0002NX-0002O1-clan-name-raw-constructor-source-placement.md` as a support lead only. I did not rely on Wave2 as primary evidence in this report.

Live IDA MCP status: unavailable in this session. The endpoint returned `IDA_MCP_UNAVAILABLE: Unable to connect to the remote server`. Current conclusions therefore use existing documented live-IDA checks plus local IDA export JSON. That is enough for these targets because the target pages already contain live IDA xref/bounds evidence, and local IDA exports reproduce the exact decompiled bodies and vtable data xrefs.

Number conversions were verified with `tools/int_convert.py`: `0x4b` = decimal `75` / ASCII `K`; `0x82` = `130`; `0xee` = `238`; `0x100` = `256`; `0x80` = `128`; `0x04` = `4`; `0x07` = `7`; `0x08` = `8`; `0x09` = `9`; `0x0a` = `10`; `0x0b` = `11`.

## Executive Recommendation

The target pages are already owner/emitter-routed correctly. The current blocker text is stale because it cites the older `95/95` final-C++ policy. Under the active combined-score gate, each target is reconstructable, has a nonblank emitter route that surfaces through the class pages to `auto-generated/NexusTK/social/Clan.cpp`, and should clear `(COMPLETION + CONFIDENCE) / 2 > 85` after the source-quality fixes below. There is no target-specific source-shape reason to keep these method-body C++ blocks blank.

The class-level pages may keep class-level C++ blank for now because the full class declarations and raw constructor reachability are still unresolved. That class-level caveat does not block method-body C++ on these six exact, vtable-backed submitter functions. The method bodies do not depend on raw constructor entry reachability.

## Heuristic / Inference Reanalysis And Validation

### Base Dialog Callback Shape

Best defensible source-facing signature:

```cpp
int Clan...InputDialog::OnSubmitText(const wchar_t *text)
```

Evidence:

- [UID:00010J] `ClanNameInputDialogCore` documents `ClanNameInputDialog::OnButtonClick` reading text control id `4` into a 255-wide-character local buffer and dispatching primary vtable slot `+0x5c`.
- Local IDA export for `0x00488eb0` shows:
  - control lookup through `a1[127]` with control id `4`;
  - text copy through `sub_498C10(*v5, v6, 255)`;
  - virtual dispatch `(*v4)[23]`, which is primary vtable slot `23 * 4 = 0x5c`;
  - `this` passed as the object and the local wide buffer passed as the submitted text.
- The six target functions are all vtable-only callback targets at the corresponding derived vtable slots.

Rejected alternatives:

- `SubmitDepositMoney`, `SubmitWithdrawMoney`, and `SubmitName` are useful page-level role names, but they cannot be the original virtual method names for all six classes unless the base class had unrelated slots. The evidence shows one shared base submit slot.
- `OnSubmitName` is too narrow because the same slot handles money and name/text dialogs.
- `SubmitText` is plausible, but `OnSubmitText` better matches the surrounding UI method naming style (`OnButtonClick`, `OnInputEvent`) already used in docs.

Impact: recommend target titles can remain descriptive, but the formal first-draft C++ methods should use `OnSubmitText(const wchar_t *text)` for all six.

### Money Text Conversion Helper

Best source-facing name: CRT `_wtol` / `__wtol`, used as a base-10 wide-string-to-long conversion.

Evidence:

- [UID:0001O5] identifies `0x005cea43-0x005cea6d` as Microsoft CRT `__wtol`, not a NexusTK helper.
- Local IDA export for [UID:0002NS] and [UID:0002NU] calls `unknown_libname_24` at `0x005cea43`.
- The decompiler's money callback prototype is noisy because the virtual method has `this` plus a stack text argument, and the CRT helper signature is not typed cleanly. The base dispatch evidence resolves the source-facing target parameter as the submitted wide text, not the object pointer.

Rejected alternatives:

- A product helper such as `ConvertSubmittedAmount` is not evidenced. The target body directly calls a CRT runtime conversion wrapper.
- `atoi`/narrow conversion is rejected because the submitted text is wide and the runtime helper is `__wtol`.

Impact: target docs should replace "conversion helper" wording with "CRT `_wtol` / `__wtol`" where source-facing names matter.

### Packet Field Byte Order

Best decision: the 32-bit money amount at packet offsets `+3..+6` is big-endian, not little-endian.

Evidence:

- [UID:0003YJ] resolves `0x005753f0` as `PacketBufferWriteUInt32BE`.
- The money submitters call `0x005753f0` after writing opcode/subtype/action bytes.
- The same PacketBuffer scalar writer page states all scalar writer helpers store high-order bytes first and then write a spare zero outside the counted payload.

Rejected alternatives:

- The target pages currently say "Little-endian 32-bit numeric amount." That is contradicted by the current PacketBuffer child split and should be corrected.
- Raw `sub_5753F0` without endian naming is no longer the best source-facing name after the PacketBuffer split.

Impact: [UID:0002NS] and [UID:0002NU] should update their packet-field tables to say "big-endian 32-bit amount" and should use `PacketBufferWriteUInt32BE` in C++.

### Name Text Conversion And Payload Copy

Best source-facing behavior:

- Convert the submitted `const wchar_t *` using `WideCharToMultiByte(CP_ACP, 0, text, wcslen(text), buffer, 256, NULL, NULL)`.
- Reject converted lengths `>= 0x100` / `256` (Verified with `int_convert.py`).
- Write a one-byte converted length at packet offset `+3`.
- Copy the converted bytes to packet offset `+4`.
- Reject final packet lengths `>= 0x80` / `128` (Verified with `int_convert.py`).
- Append a local scratch NUL after the counted payload, then send exactly `convertedLength + 4`.

Evidence:

- Local IDA exports for `0x00489180`, `0x004892b0`, `0x004893e0`, and `0x00489510` all show the same `WideCharToMultiByte` pattern, `sub_575380` length write, `sub_516220` payload copy, and final `sub_574BB0` send.
- [UID:0001BH] identifies `0x00516220` as the shared `memmove` wrapper. Source C++ can use `memmove` or the final MemoryMan copy wrapper depending on final header policy.
- [UID:0003YJ] identifies `0x00575380` as `PacketBufferWriteUInt8`.

Rejected alternatives:

- Calling the higher-level PacketBuffer string append overload from [UID:0003YO] is not supported by the target bodies. These functions manually write opcode, subtype, action, length, and payload through lower-level byte/copy helpers.
- Treating the local trailing zero as a transmitted field is rejected. `QueueAndSendPacket` receives `convertedLength + 4`, so the scratch NUL is outside the counted payload.

Impact: name submitter C++ should emit the manual packet build, not call a high-level string append helper.

### Packet Opcode, Subtypes, Actions, And Field Names

Best naming direction:

```cpp
static const unsigned char kClanPacketOpcode = 0x4b;       // 75 / 'K', Verified with int_convert.py
static const unsigned char kClanActionOpenDialog = 0x00;
static const unsigned char kClanActionSubmit = 0x01;
static const unsigned char kClanSubtypeDepositMoney = 0x04;
static const unsigned char kClanSubtypeExpelName = 0x07;
static const unsigned char kClanSubtypeSummonName = 0x08;
static const unsigned char kClanSubtypeAppearName = 0x09;
static const unsigned char kClanSubtypeChangeName = 0x0a;
static const unsigned char kClanSubtypeWithdrawMoney = 0x0b;
```

Evidence:

- [UID:00021I] documents subtype `4`, action `0` as deposit-money dialog request and subtype `4`, action `1` as amount submit, mirrored by [UID:0002NS].
- [UID:00021L] documents subtype `7-10` action `0` open/request helpers and action `1` one-name submit helpers, mirrored by [UID:0002NW], [UID:0002NY], [UID:0002O0], and [UID:0002O2].
- [UID:00021M] documents subtype `11` action `0` as withdraw-money dialog request and subtype `11` action `1` as amount submit, mirrored by [UID:0002NU].
- [UID:00021C] dispatcher context maps matching inbound subtypes to the corresponding modal dialogs.

Rejected alternatives:

- A central `ProtocolSend.cpp` owner is rejected for these target bodies. The protocol helper family is feature-owned Clan code that depends on generic PacketBuffer and Socket utilities.
- A `ClanBank.cpp` owner for the money submitters is not currently strongest. The class names and source route are in the Clan modal-dialog family; ClanBank owns larger bank/item dialog classes, not these name-input dialog submit callbacks.

Impact: document opcode family under `social/Clan.cpp`; use PacketBuffer/Socket only as helper dependencies.

### Sender Global And Queue Helper

Best source-facing names/types:

- `g_packetSender`: `Socket *` with a possible future sender-interface typedef caveat.
- `QueueAndSendPacket`: `Socket::QueueAndSendPacket(const void *packet, short packetSize)` or equivalent member wrapper.

Evidence:

- [UID:0001P0] resolves `g_packetSender` at `0x0067a7ec` as Socket-owned lifetime storage and recommends `Socket *`.
- [UID:0001HU] resolves `0x00574bb0` as Socket-owned queued packet handoff, consumed by Socket command `8`.
- All six target bodies call this helper with `g_packetSender` and the exact packet length.

Rejected alternatives:

- Generated `CashShopRequest*` aliases are stale. [UID:0001P0] documents the separate real `g_pCashShopRequest` storage and rejects using generated CashShop aliases here.
- Direct Winsock send is rejected because `QueueAndSendPacket` copies/queues the packet; the transport sends later.

Impact: C++ should call `g_packetSender->QueueAndSendPacket(packet, length)` or the final equivalent Socket sender wrapper.

### Source Placement

Best current placement: direct method pages under the six owner classes, with class/file emission through [UID:0000I8] `Clan` to `NexusTK/social/Clan.cpp`.

Evidence:

- Each target has a vtable data xref from its owner class vtable slot: `0x006159f4`, `0x00615a94`, `0x00615b34`, `0x00615bd4`, `0x00615c74`, `0x00615d14`.
- The class pages all route to [UID:0000I8] `Clan`; [UID:0000I8] is `90/85` and lists the target classes in its `social/Clan.cpp` module map.
- [UID:0000IA] `ClanDialogs` is a documented split candidate, but it explicitly keeps `Clan` as the stronger current owner if final layout keeps modal dialogs in the social feature module.
- Generated memory coverage routes all six target UIDs to `auto-generated/NexusTK/social/Clan.cpp`.

Rejected alternatives:

- `ClanDialogs.cpp` as current direct emitter is rejected for these edits because it is not the active stronger owner. It remains a possible future file split.
- The aggregate [UID:00010K] is rejected as emitter because it is `RECONSTRUCTABLE:FALSE` and exact child pages carry method emission.

Impact: keep current owner/emitter UIDs.

### Range, Padding, And Split Correctness

Best decision: no split or merge is required for the six targets.

Evidence:

- [UID:0002NS] and [UID:0002NU] are exact `0x82` / `130` byte functions (Verified with `int_convert.py`), with padding after `0x00489062` and `0x00489132`.
- [UID:0002NW], [UID:0002NY], [UID:0002O0], and [UID:0002O2] are exact `0xee` / `238` byte functions (Verified with `int_convert.py`), with padding after `0x0048926e`, `0x0048939e`, `0x004894ce`, and `0x004895fe`.
- The aggregate [UID:00010K] lists exact child raw constructors, padding spans, and submitters. It should remain non-emitting.

Rejected alternatives:

- Merging submitters back into the aggregate is rejected because exact child pages already exist and carry direct owner/emitter metadata.
- Pulling raw constructors into these method pages is rejected because the constructor-shaped ranges are separate children with separate reachability/C++ policy.

Impact: targets can be scored higher without structural edits.

### Historical Assumptions Rechecked

- Old `95/95` no-C++ rationale: stale under current by-structure policy. Replace with active gate wording.
- "Little-endian amount" in the money packet tables: contradicted by current PacketBuffer split; replace with big-endian.
- Raw constructor caveat as target C++ blocker: valid for class-level constructor pages, but not a blocker for these exact vtable-backed method body pages.
- Helper placeholder names: best descriptive names now exist for PacketBuffer byte/dword writers and Socket sender. Remaining exact original spellings are not enough to block first-draft method C++ because the helper roles and source route are documented.

## First-Draft C++ Recommendation

These blocks are intended for the six target `RECONSTRUCTION_CPP CODE` sections. They use source-facing descriptive helper names that should be coordinated with PacketBuffer/Socket final headers:

- `PacketBufferWriteUInt8(unsigned char *dst, unsigned int value)`
- `PacketBufferWriteUInt32BE(unsigned char *dst, unsigned long value)`
- `g_packetSender->QueueAndSendPacket(const void *packet, short packetSize)`

If the final project keeps different helper spellings, the supervisor can mechanically rename the helper calls without changing target semantics.

### [UID:0002NS] ClanDepMoneyInputDialog Submit Deposit Money

```cpp
int ClanDepMoneyInputDialog::OnSubmitText(const wchar_t *text)
{
    unsigned char packet[8];
    unsigned long amount = _wtol(text);

    PacketBufferWriteUInt8(packet + 0, 0x4b);
    PacketBufferWriteUInt8(packet + 1, 0x04);
    PacketBufferWriteUInt8(packet + 2, 0x01);
    PacketBufferWriteUInt32BE(packet + 3, amount);
    packet[7] = 0;

    return g_packetSender->QueueAndSendPacket(packet, 7);
}
```

### [UID:0002NU] ClanWidMoneyInputDialog Submit Withdraw Money

```cpp
int ClanWidMoneyInputDialog::OnSubmitText(const wchar_t *text)
{
    unsigned char packet[8];
    unsigned long amount = _wtol(text);

    PacketBufferWriteUInt8(packet + 0, 0x4b);
    PacketBufferWriteUInt8(packet + 1, 0x0b);
    PacketBufferWriteUInt8(packet + 2, 0x01);
    PacketBufferWriteUInt32BE(packet + 3, amount);
    packet[7] = 0;

    return g_packetSender->QueueAndSendPacket(packet, 7);
}
```

### [UID:0002NW] ClanExpelNameInputDialog Submit Name

```cpp
int ClanExpelNameInputDialog::OnSubmitText(const wchar_t *text)
{
    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(packet + 0, 0x4b);
    PacketBufferWriteUInt8(packet + 1, 0x07);
    PacketBufferWriteUInt8(packet + 2, 0x01);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, text, wcslen(text), convertedName, sizeof(convertedName), NULL, NULL);
    if (convertedLength >= sizeof(convertedName)) {
        __report_rangecheckfailure();
    }

    convertedName[convertedLength] = 0;
    PacketBufferWriteUInt8(packet + 3, convertedLength);
    memmove(packet + 4, convertedName, convertedLength);

    unsigned int packetLength = convertedLength + 4;
    if (packetLength >= sizeof(packet)) {
        __report_rangecheckfailure();
    }

    packet[packetLength] = 0;
    return g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}
```

### [UID:0002NY] ClanSummonNameInputDialog Submit Name

```cpp
int ClanSummonNameInputDialog::OnSubmitText(const wchar_t *text)
{
    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(packet + 0, 0x4b);
    PacketBufferWriteUInt8(packet + 1, 0x08);
    PacketBufferWriteUInt8(packet + 2, 0x01);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, text, wcslen(text), convertedName, sizeof(convertedName), NULL, NULL);
    if (convertedLength >= sizeof(convertedName)) {
        __report_rangecheckfailure();
    }

    convertedName[convertedLength] = 0;
    PacketBufferWriteUInt8(packet + 3, convertedLength);
    memmove(packet + 4, convertedName, convertedLength);

    unsigned int packetLength = convertedLength + 4;
    if (packetLength >= sizeof(packet)) {
        __report_rangecheckfailure();
    }

    packet[packetLength] = 0;
    return g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}
```

### [UID:0002O0] ClanAppearNameInputDialog Submit Name

```cpp
int ClanAppearNameInputDialog::OnSubmitText(const wchar_t *text)
{
    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(packet + 0, 0x4b);
    PacketBufferWriteUInt8(packet + 1, 0x09);
    PacketBufferWriteUInt8(packet + 2, 0x01);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, text, wcslen(text), convertedName, sizeof(convertedName), NULL, NULL);
    if (convertedLength >= sizeof(convertedName)) {
        __report_rangecheckfailure();
    }

    convertedName[convertedLength] = 0;
    PacketBufferWriteUInt8(packet + 3, convertedLength);
    memmove(packet + 4, convertedName, convertedLength);

    unsigned int packetLength = convertedLength + 4;
    if (packetLength >= sizeof(packet)) {
        __report_rangecheckfailure();
    }

    packet[packetLength] = 0;
    return g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}
```

### [UID:0002O2] ClanChangeNameInputDialog Submit Name

```cpp
int ClanChangeNameInputDialog::OnSubmitText(const wchar_t *text)
{
    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(packet + 0, 0x4b);
    PacketBufferWriteUInt8(packet + 1, 0x0a);
    PacketBufferWriteUInt8(packet + 2, 0x01);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, text, wcslen(text), convertedName, sizeof(convertedName), NULL, NULL);
    if (convertedLength >= sizeof(convertedName)) {
        __report_rangecheckfailure();
    }

    convertedName[convertedLength] = 0;
    PacketBufferWriteUInt8(packet + 3, convertedLength);
    memmove(packet + 4, convertedName, convertedLength);

    unsigned int packetLength = convertedLength + 4;
    if (packetLength >= sizeof(packet)) {
        __report_rangecheckfailure();
    }

    packet[packetLength] = 0;
    return g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}
```

## Target-By-Target Recommendations

### [UID:0002NS] `ClanDepMoneyInputDialogSubmitDepositMoney`

- Before: `82/90`, owner/emitter [UID:00002A], C++ blank.
- After: `86/91`, owner/emitter unchanged, C++ populated.
- Reason: exact vtable slot, exact `0x82` / `130` byte function, CRT `_wtol` conversion, corrected big-endian amount writer, seven-byte send, and source-facing callback signature are all resolved.
- Support doc fix: replace "Little-endian 32-bit numeric amount" with "big-endian 32-bit numeric amount written through `PacketBufferWriteUInt32BE`."

### [UID:0002NU] `ClanWidMoneyInputDialogSubmitWithdrawMoney`

- Before: `82/90`, owner/emitter [UID:00002O], C++ blank.
- After: `86/91`, owner/emitter unchanged, C++ populated.
- Reason: same money-submit pattern as [UID:0002NS], with subtype `0x0b` / `11` (Verified with `int_convert.py`) for withdraw money.
- Support doc fix: replace "Little-endian 32-bit numeric amount" with "big-endian 32-bit numeric amount written through `PacketBufferWriteUInt32BE`."

### [UID:0002NW] `ClanExpelNameInputDialogSubmitName`

- Before: `82/90`, owner/emitter [UID:00002D], C++ blank.
- After: `86/91`, owner/emitter unchanged, C++ populated.
- Reason: exact `0xee` / `238` byte vtable-backed method; subtype `0x07` / `7`; length-conversion, payload-copy, range-check, and send behavior resolved.

### [UID:0002NY] `ClanSummonNameInputDialogSubmitName`

- Before: `82/90`, owner/emitter [UID:00002M], C++ blank.
- After: `86/91`, owner/emitter unchanged, C++ populated.
- Reason: exact `0xee` / `238` byte vtable-backed method; subtype `0x08` / `8`; all source-quality issues are resolved to the same confidence as the sibling name submitters.

### [UID:0002O0] `ClanAppearNameInputDialogSubmitName`

- Before: `82/90`, owner/emitter [UID:000023], C++ blank.
- After: `86/91`, owner/emitter unchanged, C++ populated.
- Reason: exact `0xee` / `238` byte vtable-backed method; subtype `0x09` / `9`; current target row is under-detailed compared with siblings and should gain the same source-quality naming/evidence.

### [UID:0002O2] `ClanChangeNameInputDialogSubmitName`

- Before: `82/90`, owner/emitter [UID:000028], C++ blank.
- After: `86/91`, owner/emitter unchanged, C++ populated.
- Reason: exact `0xee` / `238` byte vtable-backed method; subtype `0x0a` / `10`; successor boundary at `0x00489600` remains correct.

## Recommended By-Doc Updates

Do not edit these directly as part of this B-agent report-only assignment. Supervisor/A-agent should apply these if accepting the report.

### Target Pages

Apply to all six target pages:

- In `## Status`, replace stale "below final-source threshold" / "`95+` final-source gate" text with:

```text
Confidence: very strong for exact function bounds, vtable ownership, packet shape, sender dependencies, and source-facing method-body readiness. Remaining uncertainty is limited to final helper API spelling in PacketBuffer/Socket headers and does not block first-draft method C++ under the active combined-score/emitter gate.
```

- In `## Parent Attachment And Reconstruction Notes` or equivalent, replace "Keep final C++ blank..." with:

```text
This exact vtable-backed method body clears the active reconstruction-code gate after source-quality review. Populate the formal C++ block with the B001 first-draft method body. The raw constructor/class-declaration caveat belongs to the class/constructor pages and does not block this method body.
```

- Add source-facing method signature:

```text
Source-facing method signature: inferred/descriptive `int <OwnerClass>::OnSubmitText(const wchar_t *text)`. Evidence: `ClanNameInputDialog::OnButtonClick` reads text control id `4` and dispatches primary vtable slot `+0x5c` with `this` plus the submitted wide-text buffer.
```

Apply to [UID:0002NS] and [UID:0002NU]:

- In the packet field table, replace:

```text
Little-endian 32-bit numeric amount from the input text.
```

with:

```text
Big-endian 32-bit numeric amount from the input text, written through `0x005753f0` / `PacketBufferWriteUInt32BE`.
```

Apply to [UID:0002NW], [UID:0002NY], [UID:0002O0], and [UID:0002O2]:

- In dependency notes, prefer:

```text
`0x00575380` / `PacketBufferWriteUInt8` writes opcode, subtype, action, and converted-name length. `0x00516220` is the shared memmove wrapper used to copy the converted payload bytes. The scratch NUL after the payload is outside the counted packet length.
```

### Support Pages

Recommended support doc updates:

- `by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md`: append a change note that this aggregate remains `RECONSTRUCTABLE:FALSE`, but the exact vtable-backed submitter children now have first-draft C++ recommendations. Also correct any stale text that says the aggregate remains `76/88`.
- `by-class/ClanDepMoneyInputDialog.md`, `by-class/ClanWidMoneyInputDialog.md`, `by-class/ClanExpelNameInputDialog.md`, `by-class/ClanSummonNameInputDialog.md`, `by-class/ClanAppearNameInputDialog.md`, and `by-class/ClanChangeNameInputDialog.md`: replace class-level wording that implies child submitter C++ is blocked by the raw constructor. Keep class-level C++ blank if desired, but state that exact child submitter C++ should emit through the child pages.
- `by-file/Clan.md`: no score or route change needed. Optional wording update: under the six dialog rows, mention that the submitter child pages now use `OnSubmitText(const wchar_t *)` as the inferred shared virtual slot name and that money packets write big-endian amounts.
- `by-type/by-struct/ClanInputDialogLayouts.md`: no score change needed. Optional open-question update: the assigned six submitter overrides have been mapped to the shared base `+0x5c` submit slot; remaining derived-family work is constructor/source split, not submitter method shape.

## Supervisor-Owned Coverage Row Replacements

Placement context: replace rows in `by-memory/-coverage-report.md` around the `ClanNameDialogSubmitters` block at current lines `1001-1024`. Keep low-to-high address order and indentation as shown.

Replace the support aggregate row:

```text
    - [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md) 0x00488fe0-0x004895fe | aggregate-index | ClanNameDialogSubmitters : ignored : 85% : strong : Reviewed non-emitting aggregate/index over exact ClanNameInputDialog derived raw constructors, padding, and submitter methods; page is `RECONSTRUCTABLE:FALSE`, exact child rows carry source emission, and B001 2026-06-17 recheck confirms method-body C++ readiness for the six vtable-backed submitter children while raw constructors keep their separate reachability caveat.
```

Replace the six stale raw-constructor support rows if the supervisor wants coverage synced with current page metadata:

```text
    - [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md) 0x00488fa0-0x00488fd5 | raw constructor | ClanDepMoneyInputDialogRawConstructor : reconstructable : 85% : very strong : Current page is `85/90`; constructor-shaped raw body calls `ClanNameInputDialog` base, installs three `ClanDepMoneyInputDialog` vtables, has no modeled function/xref/pointer route at the raw start, remains class-owned/emitting as source-authored evidence, and keeps final C++ blank because active construction sites inline the equivalent sequence.
```

```text
        - [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md) 0x00489070-0x004890a5 | raw constructor | ClanWidMoneyInputDialogRawConstructor : reconstructable : 85% : very strong : Current page is `85/90`; constructor-shaped raw body calls `ClanNameInputDialog` base, installs three `ClanWidMoneyInputDialog` vtables, has no modeled function/xref/pointer route at the raw start, remains class-owned/emitting as source-authored evidence, and keeps final C++ blank because active construction sites inline the equivalent sequence.
```

```text
        - [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md) 0x00489140-0x00489175 | raw constructor | ClanExpelNameInputDialogRawConstructor : reconstructable : 85% : very strong : Current page is `85/90`; constructor-shaped raw body calls `ClanNameInputDialog` base, installs three `ClanExpelNameInputDialog` vtables, has no modeled function/xref/pointer route at the raw start, remains class-owned/emitting as source-authored evidence, and keeps final C++ blank because active construction sites inline the equivalent sequence.
```

```text
        - [UID:0002NX][0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor](by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md) 0x00489270-0x004892a5 | raw constructor | ClanSummonNameInputDialogRawConstructor : reconstructable : 85% : very strong : Current page is `85/90`; constructor-shaped raw body calls `ClanNameInputDialog` base, installs three `ClanSummonNameInputDialog` vtables, has no modeled function/xref/pointer route at the raw start, remains class-owned/emitting as source-authored evidence, and keeps final C++ blank because active construction sites inline the equivalent sequence.
```

```text
        - [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md) 0x004893a0-0x004893d5 | raw constructor | ClanAppearNameInputDialogRawConstructor : reconstructable : 85% : very strong : Current page is `85/90`; constructor-shaped raw body calls `ClanNameInputDialog` base, installs three `ClanAppearNameInputDialog` vtables, has no modeled function/xref/pointer route at the raw start, remains class-owned/emitting as source-authored evidence, and keeps final C++ blank because active construction sites inline the equivalent sequence.
```

```text
        - [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md) 0x004894d0-0x00489505 | raw constructor | ClanChangeNameInputDialogRawConstructor : reconstructable : 85% : very strong : Current page is `85/90`; constructor-shaped raw body calls `ClanNameInputDialog` base, installs three `ClanChangeNameInputDialog` vtables, has no modeled function/xref/pointer route at the raw start, remains class-owned/emitting as source-authored evidence, and keeps final C++ blank because active construction sites inline the equivalent sequence.
```

Replace the six primary target rows:

```text
        - [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md) 0x00488fe0-0x00489062 | method | ClanDepMoneyInputDialog::OnSubmitText : reconstructable : 86% : very strong : B001 2026-06-17 source-quality audit resolves this vtable-backed submitter as `ClanDepMoneyInputDialog::OnSubmitText(const wchar_t *)`, confirms exact `0x82` / 130-byte bounds, vtable slot `0x006159f4`, CRT `_wtol` amount conversion, opcode `0x4b` subtype `4` action `1`, big-endian uint32 amount via `PacketBufferWriteUInt32BE`, seven-byte Socket queue send through `g_packetSender`, class owner/emitter route, and first-draft C++ readiness.
```

```text
        - [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md) 0x004890b0-0x00489132 | method | ClanWidMoneyInputDialog::OnSubmitText : reconstructable : 86% : very strong : B001 2026-06-17 source-quality audit resolves this vtable-backed submitter as `ClanWidMoneyInputDialog::OnSubmitText(const wchar_t *)`, confirms exact `0x82` / 130-byte bounds, vtable slot `0x00615a94`, CRT `_wtol` amount conversion, opcode `0x4b` subtype `0x0b` action `1`, big-endian uint32 amount via `PacketBufferWriteUInt32BE`, seven-byte Socket queue send through `g_packetSender`, class owner/emitter route, and first-draft C++ readiness.
```

```text
        - [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md) 0x00489180-0x0048926e | method | ClanExpelNameInputDialog::OnSubmitText : reconstructable : 86% : very strong : B001 2026-06-17 source-quality audit resolves this vtable-backed submitter as `ClanExpelNameInputDialog::OnSubmitText(const wchar_t *)`, confirms exact `0xee` / 238-byte bounds, vtable slot `0x00615b34`, opcode `0x4b` subtype `7` action `1`, `WideCharToMultiByte` conversion into a 256-byte local buffer, one-byte length and payload copy, `0x100`/`0x80` range guards, Socket queue send through `g_packetSender`, class owner/emitter route, and first-draft C++ readiness.
```

```text
        - [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md) 0x004892b0-0x0048939e | method | ClanSummonNameInputDialog::OnSubmitText : reconstructable : 86% : very strong : B001 2026-06-17 source-quality audit resolves this vtable-backed submitter as `ClanSummonNameInputDialog::OnSubmitText(const wchar_t *)`, confirms exact `0xee` / 238-byte bounds, vtable slot `0x00615bd4`, opcode `0x4b` subtype `8` action `1`, `WideCharToMultiByte` conversion into a 256-byte local buffer, one-byte length and payload copy, `0x100`/`0x80` range guards, Socket queue send through `g_packetSender`, class owner/emitter route, and first-draft C++ readiness.
```

```text
        - [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md) 0x004893e0-0x004894ce | method | ClanAppearNameInputDialog::OnSubmitText : reconstructable : 86% : very strong : B001 2026-06-17 source-quality audit resolves this vtable-backed submitter as `ClanAppearNameInputDialog::OnSubmitText(const wchar_t *)`, confirms exact `0xee` / 238-byte bounds, vtable slot `0x00615c74`, opcode `0x4b` subtype `9` action `1`, `WideCharToMultiByte` conversion into a 256-byte local buffer, one-byte length and payload copy, `0x100`/`0x80` range guards, Socket queue send through `g_packetSender`, class owner/emitter route, and first-draft C++ readiness.
```

```text
        - [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md) 0x00489510-0x004895fe | method | ClanChangeNameInputDialog::OnSubmitText : reconstructable : 86% : very strong : B001 2026-06-17 source-quality audit resolves this vtable-backed submitter as `ClanChangeNameInputDialog::OnSubmitText(const wchar_t *)`, confirms exact `0xee` / 238-byte bounds, vtable slot `0x00615d14`, opcode `0x4b` subtype `0x0a` action `1`, `WideCharToMultiByte` conversion into a 256-byte local buffer, one-byte length and payload copy, `0x100`/`0x80` range guards, Socket queue send through `g_packetSender`, class owner/emitter route, successor boundary at `0x00489600`, and first-draft C++ readiness.
```

## Generated Output / Final-C++ Policy

- `auto-generated/-ag-memory-coverage.md` currently lists all six target UIDs as `emits` with owner/emitter routes through their class pages to `auto-generated/NexusTK/social/Clan.cpp`.
- `auto-generated/NexusTK/social/Clan.cpp` is currently zero bytes because the relevant C++ blocks are blank.
- `auto-generated/NexusTK/ui/dialogs/ClanDialogs.cpp` is also zero bytes and is not the accepted current target route.
- First-draft C++ is appropriate for the six target method bodies because each target is exact, reconstructable, emitted, and recommended above the active combined-score gate.
- Class-level C++ on the six owner class pages can remain blank until raw constructors, declarations, and final `Clan.cpp` versus `ClanDialogs.cpp` split are coordinated. The method-body child pages are the correct place for the submitted packet code.

## Validation Commands

Commands run:

> Executable block R001 was removed from this report and preserved verbatim in [0002NS-0002NU-0002NW-0002NY-0002O0-0002O2-clan-submitters-source-quality-removed.md](0002NS-0002NU-0002NW-0002NY-0002O0-0002O2-clan-submitters-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No by-* documentation, generated files, source files, IDA database, or `by-memory/-coverage-report.md` edits were made.

## Changed Files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0002NS-0002NU-0002NW-0002NY-0002O0-0002O2-clan-submitters-source-quality.md`

Modified:

- None outside this report.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `86/91`; not high enough for `95+` because exact original helper API spellings and final class header declarations remain inferred.
- Remaining uncertainty: final helper names in PacketBuffer/Socket headers and final `Clan.cpp` versus `ClanDialogs.cpp` source split. Neither uncertainty blocks the six exact method-body C++ blocks because the current owner/emitter route is valid and the method bodies are self-contained.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002NS-0002NU-0002NW-0002NY-0002O0-0002O2-clan-submitters-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002NS"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002NS-0002NU-0002NW-0002NY-0002O0-0002O2-clan-submitters-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002NS-0002NU-0002NW-0002NY-0002O0-0002O2-clan-submitters-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002NS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
