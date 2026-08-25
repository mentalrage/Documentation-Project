** TARGET-REPORT-UID:00005T **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00005T GiveGoldInputPane Class Source-Quality Reanalysis

Agent: B015
Assignment: B015-goal2-give-gold-input-pane-class-source-quality-00005T-20260619
Target: [UID:00005T] `by-class/GiveGoldInputPane.md`
Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B015\research\00005T-GiveGoldInputPane-class-source-quality.md`

## Final Recommendation

Keep [UID:00005T] `GiveGoldInputPane` reconstructable and attached to [UID:0000KC] `ItemActionInputPanes` / `NexusTK/ui/dialogs/ItemActionInputPanes.cpp`. Raise the class page from `85/86` to `87/89` after this source-quality pass. Keep the class page's formal C++ block blank until the exact submit method child exists and the class declaration strategy for `ItemActionInputPanes.cpp` is coordinated.

The best-supported source-facing class role is a private item-action numeric input pane opened by `GiveInputPane` when the user chooses gold rather than an inventory item. It prompts with localized string id `0x2b` / 43, parses an unsigned decimal amount, checks the local user pane's item-command busy gate at `g_pUserPane + 0x3ec0`, and queues a five-byte give-gold packet through the Socket send path: opcode `0x2a`, followed by the amount encoded big-endian.

Key source-facing names recommended for later incorporation:

- Class: `GiveGoldInputPane`.
- Constructor role: `GiveGoldInputPane::GiveGoldInputPane()`, backed by raw constructor-shaped bytes at `0x005b52b0-0x005b52f0` but live construction is currently proven through inline construction inside `GiveInputPane::OnConfirmInput`.
- Submit method role: `GiveGoldInputPane::OnSubmitGoldAmount()` as the source-quality descriptive name; preserve `OnSubmit` as the existing page/vtable role until the base virtual name is finalized.
- Raw helper role: `SendGiveGoldPacket(unsigned int amount)` for [UID:0003MW] `0x005b5390-0x005b53f9.SendGiveGoldPacketRaw`, with `SendGiveGoldAmountPacket` rejected as wordier but semantically acceptable if the project standardizes amount-suffixed packet helpers.
- Prompt id symbol: source-facing inferred constant `kGiveGoldPromptStringId` / `LANG_PROMPT_GIVE_GOLD_AMOUNT`; do not claim this as the original enum spelling because no localized text table name was recovered.
- Busy gate: canonical global `g_pUserPane`, field `m_itemCommandBusy` at `+0x3ec0`; keep `g_pCollectionData` only as a historical typed-view alias.
- Packet global: `g_packetSender`, canonical Socket-owned global.
- Packet helpers: `PacketBufferWriteUInt8`, `PacketBufferWriteUInt32BE`, `QueueAndSendPacket`.

## Target State Before This Pass

The target class page currently has:

- `COMPLETION:85`
- `CONFIDENCE:86`
- `CANONICAL_OWNER:0000KC`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KC`
- blank formal C++.

The existing class page already captures the broad behavior: the class is a numeric prompt used by give-gold flow, has a raw constructor [UID:0001MI], and submits a five-byte packet when the busy gate is clear. This pass should update source-facing names and tighten evidence around raw constructor liveness, the live vtable-routed submit method, current global names, packet helper names, and no-code policy.

## Evidence Checked

Documentation checked:

- `tools/leaser/Agents/Supervisor.md`, including Rule 26.
- `.codex/AGENTS.md` from the workspace rules.
- `tools/leaser/Agents/Agent-B015/goal.md`.
- `by-structure.md`, `inference_research.md`, `by-project-structure/proposed-source-tree.md`, and `by-class/-guidance.md`.
- Target `by-class/GiveGoldInputPane.md`.
- File owner `by-file/ItemActionInputPanes.md`.
- Creator/parent `by-class/GiveInputPane.md`.
- Numeric base `by-class/NumberInputPane.md`.
- Sibling analog `by-class/DropGoldInputPane.md`.
- Aggregate support `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md`.
- Raw constructor support `by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md`.
- Raw packet helper support `by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md`.
- Sibling raw packet helper `by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md`.
- Vtable family `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`.
- Canonical user pane/global docs `by-global/g_pCollectionData.md` and `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`.
- Packet global docs `by-global/g_packetSender.md` and `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`.
- Socket send funnel `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`.
- Packet scalar writers `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`.
- Wide scanf wrapper support `by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md`.
- Line input helpers `by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md` and `by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md`.
- Existing coverage rows in `by-class/-coverage-report.md` and the relevant `0x005b...` block of `by-memory/-coverage-report.md` were read only.

Generated and source-like leads checked:

- `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` currently contains empty emitter markers for [UID:00005T], [UID:0001MI], [UID:0003MW], and the aggregate. No generated C++ body or class declaration exists for `GiveGoldInputPane`.
- `auto-generated/-ag-class-coverage.md` shows [UID:00005T] emitted by [UID:0000KC] but `code no`.
- `auto-generated/-ag-memory-coverage.md` shows [UID:0001MI] emitted by [UID:00005T] and [UID:0003MW] emitted by [UID:0000KC], both `code no`.
- `simroot_v2/class_GiveGoldInputPane.cpp` was treated as a decompiler/simulation lead only. It captures the rough constructor and submit behavior, but uses polluted names and types such as `QuitInputPane::ReadInputText`, `g_pPlayerData`, synthetic busy structs, modern standard library style, and `PacketSender::QueueAndSend`. Those names should not be incorporated.
- `simroot_v2/class_GiveInputPane.cpp` confirms the same live gold branch shape as the docs but also has generated naming pollution.
- `simroot_v2/class_DropGoldInputPane.cpp` was used only as a sibling behavior analog.

Raw PE/binary evidence checked:

- Read-only executable: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- MD5 from the local pass: `4247e04e20b65d6414c7238aa8ff5515`.
- File size from the local pass: `2679296`.
- `.text` range: `0x00401000-0x0060c4ac`, raw `0x400`, size `0x20b600`.
- `.rdata` range: `0x0060d000-0x0066c0be`, raw `0x20ba00`, size `0x5f200`.
- `.data` range: `0x0066d000-0x0069ce24`, raw `0x26ac00`, size `0xd800`.
- `.rsrc` range: `0x0069d000-0x006b2c38`, raw `0x278400`, size `0x15e00`.

## Boundary, Padding, And Reachability Recheck

The local PE pass confirms the relevant half-open ranges and padding/alignment:

- `0x005b50b0-0x005b5223`: `GiveInputPane` confirm/gold route, size `0x173` / 371.
- `0x005b5223-0x005b5230`: 13 bytes of `0xcc` alignment.
- `0x005b5230-0x005b52ac`: adjacent `SendGiveItemRaw`, size `0x7c`.
- `0x005b52ac-0x005b52b0`: four bytes of `0xcc` alignment.
- `0x005b52b0-0x005b52f0`: `GiveGoldInputPane` raw constructor-shaped body, size `0x40` / 64.
- `0x005b52f0-0x005b538a`: `GiveGoldInputPane` submit method, size `0x9a` / 154.
- `0x005b538a-0x005b5390`: six bytes of `0xcc` alignment.
- `0x005b5390-0x005b53f9`: `SendGiveGoldPacketRaw`, size `0x69` / 105.
- `0x005b53f9-0x005b5400`: seven bytes of `0xcc` alignment.
- `0x005b5400-0x005b5440`: `GroupInputPaneRawConstructor`, size `0x40`.

Whole-file pointer/immediate checks from the local PE pass:

- `0x005b52b0` raw constructor start: zero whole-file dword/pointer hits.
- `0x005b52f0` submit method start: one dword/pointer hit at `0x00630090`, the primary vtable slot for `GiveGoldInputPane`.
- `0x005b5390` raw packet helper start: zero whole-file dword/pointer hits.
- `0x005b53f9` raw helper end: zero whole-file dword/pointer hits.
- `0x00630048` primary vtable immediate appears in two constructor sites: the live inline `GiveInputPane` branch and the raw constructor island.
- `0x00630098` secondary vtable immediate appears in the same two construction sites.
- `0x006300c8` tertiary vtable immediate appears in the same two construction sites.
- `0x0067a748` global pointer storage has many references across the program and is now canonicalized as `g_pUserPane`, not a collection-only global.
- `0x0067a7ec` global pointer storage has many references across the program and is canonicalized as Socket-owned `g_packetSender`.

The raw constructor and raw packet helper therefore have source-shaped bytes but no proven direct call, vtable, callback, data-pointer, computed-call, or encoded pointer route to their starts. The live submit method is reachable through the primary vtable at `0x00630090 -> 0x005b52f0`. The live object creation route currently proven by the binary is the inline constructor sequence inside `GiveInputPane::OnConfirmInput`, not a call to `0x005b52b0`.

## Behavior Reconstruction Evidence

### Raw constructor `0x005b52b0-0x005b52f0`

The raw constructor-shaped body:

- Uses `ecx` as `this`, saves `esi = this`, and returns `this` in `eax`.
- Reads `g_pLanguageMan` from `0x0067a750`.
- Pushes prompt id `0x2b` / 43 and calls the language lookup at `0x004f0350`.
- Passes the localized prompt to `NumberInputPane` constructor `0x004f27a0`.
- Stores `0x00630048` at `this+0x00`.
- Stores `0x00630098` at `this+0xa0`.
- Stores `0x006300c8` at `this+0xa4`.
- Ends with a plain `ret`, matching a `__thiscall` constructor.

This is class-identifying evidence, but it is not currently a live call route. The same base construction and vtable install sequence appears inline in the `GiveInputPane::OnConfirmInput` gold branch.

### Live creator `GiveInputPane::OnConfirmInput`

The `GiveInputPane` confirm handler has the active gold route:

- Reads/copies one character from the line input.
- Treats `0x5c` (`\`) and `0x2f` (`/`) as the gold selection branch.
- Allocates `0x108` bytes.
- Reads `g_pLanguageMan`.
- Uses prompt id `0x2b`.
- Calls the language lookup and `NumberInputPane` constructor.
- Installs the same three `GiveGoldInputPane` vtables: `0x00630048`, `0x00630098`, `0x006300c8`.

This proves the creation relationship and the prompt id, but it does not transfer source ownership of `GiveGoldInputPane` to `GiveInputPane`. It is a creator/dispatcher relationship inside the same `ItemActionInputPanes.cpp` source neighborhood.

### Submit method `0x005b52f0-0x005b538a`

The vtable-routed submit method:

- Allocates a stack frame with security cookie.
- Calls the line-input text copy helper at `0x004f2300`, copying up to 15 wide characters to a local buffer.
- Checks that the copied text length is positive before parsing/sending.
- Calls the wide `swscanf` wrapper at `0x004944f0` with format string at `0x006191b0`, `%u`, and a local unsigned amount.
- Reads `g_pUserPane` from `0x0067a748`.
- Checks byte `g_pUserPane + 0x3ec0`; nonzero skips packet send.
- Builds a packet in local stack storage:
  - byte 0: `0x2a` through `PacketBufferWriteUInt8` at `0x00575380`;
  - bytes 1-4: parsed amount through `PacketBufferWriteUInt32BE` at `0x005753f0`;
  - byte 5: local zero terminator/scratch byte, not transmitted.
- Reads Socket-owned `g_packetSender` from `0x0067a7ec`.
- Calls `QueueAndSendPacket` at `0x00574bb0` with length `5`.
- Performs security-cookie check and returns.

The method has a real source route through the primary vtable. This is the best place for the first formal method C++ once an exact by-memory child page exists.

### Raw packet helper `0x005b5390-0x005b53f9`

The adjacent raw helper:

- Has no IDA function start and no pointer/call route found to `0x005b5390`.
- Is bounded by clean `0xcc` alignment before and after.
- Takes one stack argument, the amount.
- Checks the same `g_pUserPane + 0x3ec0` busy byte.
- Builds the same five-byte packet with opcode `0x2a` and big-endian amount.
- Writes a local-only zero terminator after the five transmitted bytes.
- Sends length `5` through `g_packetSender` / `QueueAndSendPacket`.
- Returns with `ret 4`.

This is source-shaped, file-scope packet helper code. However, the live `GiveGoldInputPane` submit method emits equivalent packet logic inline and the helper has no proven caller. It should be documented as retained no-route source-shaped code with best source-facing name `SendGiveGoldPacket(unsigned int amount)`, but formal C++ should be deferred unless a source route appears or the project explicitly wants retained no-route helper bodies.

## Heuristic / Inference Reanalysis And Validation

### Class/source owner

Best inference: [UID:00005T] belongs in [UID:0000KC] `ItemActionInputPanes.cpp`.

Evidence:

- `by-file/ItemActionInputPanes.md` already owns the drop/give item-action input pane family.
- `GiveGoldInputPane` sits inside the contiguous `0x005b44b0-0x005b538a` drop/give item-action aggregate.
- The immediately adjacent sibling `DropGoldInputPane` has matching prompt/packet structure with different prompt id and opcode.
- `GiveInputPane` constructs `GiveGoldInputPane` inline inside the same source neighborhood.
- The vtable family page groups `GiveGoldInputPane` with other item-action input panes and records the three vtable views.
- Proposed source tree routes `ItemActionInputPanes.cpp` under `NexusTK/ui/dialogs/`.

Rejected alternatives:

- `GiveInputPane` as owner: rejected because it is a creator and sibling/parent workflow, not a class-source owner. It should cross-reference the gold child but not absorb it.
- `NumberInputPane` / `InputPanes.cpp`: rejected because `NumberInputPane` is only the base constructor and key-filter provider.
- `UserPane`: rejected because it is the user-state/busy-gate owner and likely command creator elsewhere, not the source file for this prompt class.
- `Socket` or `PacketBuffer`: rejected because they provide packet transport and scalar writers only.
- `CommandInputPanes.cpp` / `GroupInputPane`: rejected because `GroupInputPaneRawConstructor` starts at `0x005b5400` after clean padding; `GiveGoldInputPane` and its raw helper sit before that boundary with the drop/give item-action cluster.

### Raw constructor policy

Best inference: `0x005b52b0-0x005b52f0` is a compiler-emitted or retained constructor-shaped body for `GiveGoldInputPane::GiveGoldInputPane()`, but not currently the active source route.

Evidence:

- It has exact constructor shape: `this` in `ecx`, base constructor call, vtable installs, return `this`.
- It uses prompt id `0x2b`, matching the active `GiveInputPane` inline construction branch.
- It installs the class-identifying vtables.
- It is preceded by four bytes of `0xcc` alignment and followed immediately by the live submit method.
- No direct start xref, pointer hit, callback route, or computed route was found.
- Active creator code in `GiveInputPane` duplicates the construction sequence inline instead of calling `0x005b52b0`.

Rejected alternatives:

- Active called constructor: rejected until a call/pointer route appears.
- Pure compiler artifact with no source value: rejected because the body is source-shaped and uses class-specific prompt/vtables; it should remain reconstructable evidence even if not formal C++.
- Separate class owner/emitter from [UID:00005T]: rejected because the only class identity in the body is `GiveGoldInputPane`.

Recommendation:

- Keep [UID:0001MI] owned/emitted by [UID:00005T].
- Raise [UID:0001MI] from stale coverage row `74%` to `86/89` in docs/coverage if accepted.
- Keep formal C++ blank with a target-specific note: source reconstruction should use the class declaration and the live creator route; emitting the no-route raw constructor body would duplicate an uncalled constructor island.

### Submit method naming and child split

Best inference: `0x005b52f0-0x005b538a` is the live `GiveGoldInputPane` primary-vtable submit/accept method.

Evidence:

- Primary vtable slot at `0x00630090` points to `0x005b52f0`.
- The method reads line-input text, parses `%u`, checks the item-command busy gate, builds opcode `0x2a`, encodes amount big-endian, and sends five bytes.
- It is the only proven active code route for the give-gold packet behavior.

Name decision:

- Use `GiveGoldInputPane::OnSubmitGoldAmount()` as the best source-quality descriptive name in notes and future child naming.
- Preserve the existing `OnSubmit` page wording as a possible formal base virtual override name until the class hierarchy's virtual slot names are finalized.
- Avoid generated names such as `QuitInputPane::ReadInputText` or `PacketSender::QueueAndSend`.

Recommendation:

- Create a dedicated by-memory child during implementation callback, for example `by-memory/0x005b52f0-0x005b538a.GiveGoldInputPaneSubmitGoldAmount.md`, owned/emitted by [UID:00005T].
- This child, not the class page or aggregate, should own the first formal method C++ once created.

### Raw packet helper policy

Best inference: [UID:0003MW] `0x005b5390-0x005b53f9` is a file-scope retained source-shaped helper best named `SendGiveGoldPacket(unsigned int amount)`.

Evidence:

- No `this` use and one stack argument.
- Checks the same busy gate and sends the same opcode/amount packet.
- Adjacent to `GiveGoldInputPane` submit and before the `GroupInputPane` boundary.
- No caller, pointer, vtable, callback, or computed-call route was found.
- The live submit method has equivalent packet-building code inline.

Rejected alternatives:

- Method on `GiveGoldInputPane`: rejected because the helper has no `this` parameter or class-state access.
- Socket-owned send helper: rejected because Socket ownership starts at `QueueAndSendPacket`; this helper composes a feature packet before handing it to Socket.
- PacketBuffer-owned helper: rejected because PacketBuffer only owns scalar writer functions.
- Cash-shop request helper: rejected because opcode and creator route are item-action/give-gold, not cash-shop request flow.

Recommendation:

- Keep [UID:0003MW] owned/emitted by [UID:0000KC].
- Use source-facing name `SendGiveGoldPacket(unsigned int amount)`.
- Raise to `86/89` if accepted.
- Keep formal C++ blank until a route appears or the project elects to emit retained no-route helpers.

### Prompt id and localized string name

Best inference: prompt id `0x2b` / 43 is the give-gold amount prompt.

Evidence:

- Both the raw constructor and the live `GiveInputPane` inline branch pass `0x2b` to `g_pLanguageMan` lookup.
- The constructed class is `NumberInputPane`, and the submit handler parses an unsigned amount.
- Sibling `DropGoldInputPane` uses prompt id `7`, so `0x2b` is not the generic drop-gold prompt.

Rejected alternatives:

- Cash-shop prompt: rejected because no cash-shop source route exists; the only shared state is `g_pUserPane +0x3ec0`.
- Generic `IDS_GOLD`: too broad and not supported by a text-table name.
- Reusing DropGold prompt id/name: rejected by different prompt id and give action.

Recommendation:

- Use inferred source-facing placeholder `kGiveGoldPromptStringId` or `LANG_PROMPT_GIVE_GOLD_AMOUNT`.
- In by-* docs, explicitly mark the constant spelling as inferred unless a localized string table or enum name is later recovered.

### Busy gate global and field

Best inference: use `g_pUserPane->m_itemCommandBusy` at `g_pUserPane + 0x3ec0`.

Evidence:

- Current global docs now canonicalize `0x0067a748` as `UserPane *g_pUserPane`.
- `g_pCollectionData`, `g_pPlayerData`, and similar names are historical typed-view aliases.
- The field at `+0x3ec0` gates item/gold command packet sends in this source neighborhood.
- The give-gold code only tests the byte; it does not invoke collection-specific or cash-shop-specific code here.

Rejected alternatives:

- Canonical `g_pCollectionData`: rejected by current global source-quality docs.
- `isCashShopBusy`: rejected as over-narrow generated naming. It may be a shared busy state used by cash-shop paths elsewhere, but this target's evidence supports broader item-command busy semantics.
- Packet sender busy gate: rejected because the byte lives on `g_pUserPane`, not on Socket.

Recommendation:

- Update target/support docs to say `g_pUserPane + 0x3ec0` / `m_itemCommandBusy`, with `g_pCollectionData` only in historical alias notes.

### Packet helper and global names

Best source-facing names:

- `PacketBufferWriteUInt8` for `0x00575380`.
- `PacketBufferWriteUInt32BE` for `0x005753f0`.
- `QueueAndSendPacket` for `0x00574bb0`.
- `g_packetSender` for `0x0067a7ec`.

Evidence:

- `PacketBufferScalarBigEndianWriteHelpers.md` gives current best names for scalar writer helpers and clarifies the local spare zero terminator is not a transmitted protocol byte.
- `QueueAndSendPacket.md` documents the Socket-owned queue/copy/send funnel and its length argument.
- `g_packetSender.md` documents the Socket-owned global and rejects feature-owned packet-sender aliases.

Rejected alternatives:

- `WriteByteZ_575380`, `WriteUInt32BEZ_5753F0`, and `PacketWriteUInt32BE`: stale/transitional helper names.
- `PacketSender::QueueAndSend`: generated-source class name, not current owner/name.
- Treating the local sixth byte as packet length 6: rejected because `QueueAndSendPacket` is called with length `5`.

### Generated names and placeholder cleanup

Generated or raw names that should not be incorporated as final source names:

- `QuitInputPane::ReadInputText`: reject; the helper belongs to `LineInputPane` text copy behavior.
- `QuitInputPane::GetInputLength`: reject where it appears in generated leads; use `LineInputPane::GetTextLength` when length helper is used.
- `g_pPlayerData`: reject for this target; use canonical `g_pUserPane`.
- Synthetic struct field `isCashShopBusy`: reject as over-narrow; use `m_itemCommandBusy`.
- `PacketSender::QueueAndSend`: reject; use Socket-owned `QueueAndSendPacket` and global `g_packetSender`.
- Raw class name variants ending in `RawConstructor` should remain documentation page labels, not source-facing C++ names.

### Packet semantics and subtype/action naming

Best inference:

- Opcode `0x2a` is the give-gold action packet opcode.
- There is no additional subtype byte in this packet.
- The amount is a 32-bit unsigned quantity encoded big-endian.
- The packet send length is exactly 5.

Evidence:

- Submit method writes opcode at packet byte 0 and amount at bytes 1-4.
- Raw helper does the same.
- Both calls pass length `5`.
- The local byte after the amount is set to zero but is not included in the length.
- Sibling drop-gold flow uses the same amount shape with a different opcode.

Recommendation:

- Use wording such as `give-gold packet opcode 0x2a` or `GiveGold opcode 0x2a`.
- Do not invent a subtype/action enum beyond the opcode unless a packet table is later recovered.

### Vtable/base layout

Best inference:

- `GiveGoldInputPane` has the same three-view input-pane layout as the direct item-action input panes.
- Primary vtable: `0x00630048`.
- Secondary vtable: `0x00630098`, stored at `this+0xa0`.
- Tertiary vtable: `0x006300c8`, stored at `this+0xa4`.
- Primary slot `+0x48` / dword at `0x00630090` points to `0x005b52f0`, the submit method.
- Secondary slot includes `0x004f2820`, the `NumberInputPane` numeric key filter path.

Recommendation:

- Keep vtable evidence in the class page and vtable family page.
- Do not claim a final class declaration size or exact base-list spelling solely from this pass. The allocation site uses `0x108` bytes, but final class layout should be synchronized with `NumberInputPane`/`LineInputPane` declaration work.

## First-Draft C++ Recommendation / No-Code Proof

Do not emit formal C++ in the [UID:00005T] class page during the implementation callback unless the callback also creates/synchronizes exact child pages and class declaration scaffolding.

Target-specific no-code proof:

- Class pages should not absorb full method bodies. The source-bearing submit method `0x005b52f0-0x005b538a` currently does not have an exact by-memory child page, so there is no proper child owner for the method body.
- The class page can eventually emit declarations, but `ItemActionInputPanes.cpp` currently has only empty markers for this class family. A declaration-only class block should be coordinated with adjacent Drop/Give pane declarations, base virtual names, and existing generated marker policy.
- The raw constructor at `0x005b52b0` is source-shaped but has zero route to its start. The live construction path is an inline `GiveInputPane::OnConfirmInput` allocation/base-constructor/vtable-store sequence. Emitting the raw constructor body now risks creating an uncalled duplicate.
- The raw helper [UID:0003MW] is source-shaped but has zero route to its start, while the live submit method emits equivalent packet code inline. Emitting it now risks inventing a source route.
- The formal base virtual name for the primary slot is not fully settled (`OnSubmit` versus descriptive `OnSubmitGoldAmount` / `Accept` style naming). The behavior is clear, but exact declaration spelling should be chosen once the method child is created.
- The generated source lead contains known bad names (`QuitInputPane`, `g_pPlayerData`, synthetic `isCashShopBusy`, `PacketSender`) and should not be used verbatim.

Review-only first-draft method body for a future exact submit child, not for direct insertion in the class page:

```cpp
void GiveGoldInputPane::OnSubmitGoldAmount()
{
    wchar_t text[16];
    unsigned int amount;
    unsigned char packet[6];

    if (LineInputPane::CopyText(text, 15) <= 0)
        return;

    amount = 0;
    WideStringScanf(text, L"%u", &amount);

    if (g_pUserPane->m_itemCommandBusy != 0)
        return;

    PacketBufferWriteUInt8(0x2a, packet);
    PacketBufferWriteUInt32BE(amount, packet + 1);
    packet[5] = 0;
    QueueAndSendPacket(g_packetSender, packet, 5);
}
```

Notes on that draft:

- The binary does not null-check `g_pUserPane`; do not add one in exact C++ unless a later source-style policy requires defensive wrappers outside binary equivalence.
- `WideStringScanf` is a source-facing placeholder for the `0x004944f0` wide scanf wrapper; final naming should match the CRT/helper convention used elsewhere.
- `LineInputPane::CopyText` may need exact `this` qualification/adjustment once the class declaration is emitted.
- The local `packet[6]` expresses the non-transmitted spare terminator byte. The packet length remains 5.
- Use mid-2000s C++ style, not modern `std::array`, `std::uint32_t`, or generated simulator classes.

Review-only constructor shape for future declaration work:

```cpp
GiveGoldInputPane::GiveGoldInputPane()
    : NumberInputPane(g_pLanguageMan->GetString(kGiveGoldPromptStringId))
{
}
```

This constructor shape is behaviorally supported, but it should not be emitted from [UID:0001MI] until the no-route constructor policy is resolved or the project chooses to represent retained constructor islands as source comments/declarations rather than emitted live code.

Review-only raw helper shape if a caller/source route is later found:

```cpp
static void SendGiveGoldPacket(unsigned int amount)
{
    unsigned char packet[6];

    if (g_pUserPane->m_itemCommandBusy != 0)
        return;

    PacketBufferWriteUInt8(0x2a, packet);
    PacketBufferWriteUInt32BE(amount, packet + 1);
    packet[5] = 0;
    QueueAndSendPacket(g_packetSender, packet, 5);
}
```

This helper should remain non-emitted for now because no route to `0x005b5390` was found.

## Score, Owner, Emitter, And Reconstructable Recommendations

Target [UID:00005T] `GiveGoldInputPane`:

- Recommended completion/confidence: `87/89`.
- Reconstructable: keep `TRUE`.
- Canonical owner: keep [UID:0000KC] `ItemActionInputPanes`.
- Emitter: keep [UID:0000KC].
- Formal C++: keep blank for now with the no-code proof above.

Justification for `87/89`:

- Completion improves because this pass resolves the current source-facing global names, field name, packet helper names, prompt id policy, raw constructor policy, raw helper policy, source placement, owner/emitter, and first-draft child C++ direction.
- Confidence improves because a direct PE pass independently confirms the exact ranges, padding, vtable route, raw-constructor no-route status, raw-helper no-route status, and live inline construction route.
- Keep below 90 because the live submit method does not yet have a dedicated exact by-memory child, the class declaration/base virtual names are not finalized, and the raw constructor/helper remain source-shaped no-route islands.

Support pages:

- [UID:0001MI] `GiveGoldInputPaneRawConstructor`: recommend `86/89`, reconstructable, owner/emitter [UID:00005T], C++ blank. Update stale "95+ gate" wording to the current code-entry gate and the target-specific no-route constructor proof.
- [UID:0003MW] `SendGiveGoldPacketRaw`: recommend `86/89`, reconstructable, owner/emitter [UID:0000KC], C++ blank. Update name to best source-facing `SendGiveGoldPacket(unsigned int amount)`, use current global/helper names, and add zero pointer-route evidence.
- Aggregate [UID:0001MG] `DropGiveInputPanes`: keep as aggregate/no formal C++ owner unless split work is accepted. Update helper/global names and mention the exact submit child needed for `0x005b52f0-0x005b538a`.
- Future submit child `0x005b52f0-0x005b538a.GiveGoldInputPaneSubmitGoldAmount`: recommend creation with owner/emitter [UID:00005T], initial score about `86/90`, and first-draft method C++ after virtual name selection.

## Exact Implementation Checklist For Later Callback

Do not make these edits until supervisor acceptance/implementation callback.

1. Update `by-class/GiveGoldInputPane.md`:
   - Change metadata recommendation to `COMPLETION:87`, `CONFIDENCE:89`.
   - Keep `CANONICAL_OWNER:0000KC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KC`.
   - Keep formal C++ blank.
   - Add a `## Heuristic / Inference Reanalysis And Validation` section or equivalent target section with:
     - `g_pUserPane + 0x3ec0` / `m_itemCommandBusy` replacing canonical `g_pCollectionData` / cash-shop-only wording.
     - `g_packetSender`, `QueueAndSendPacket`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt32BE`.
     - prompt id `0x2b` as inferred `kGiveGoldPromptStringId` / `LANG_PROMPT_GIVE_GOLD_AMOUNT`.
     - raw constructor no-route policy and live inline creator route from [UID:00005U] `GiveInputPane`.
     - vtable route `0x00630090 -> 0x005b52f0`.
     - raw helper [UID:0003MW] relation and no-route policy.
     - target-specific no-code proof.

2. Update `by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md`:
   - Raise recommended metadata to `86/89` if accepted.
   - Replace stale "C++ blank under the 95+ gate" language with current code-entry/no-route policy.
   - Add exact padding `0x005b52ac-0x005b52b0`, size `0x40`, vtable stores, prompt id, `NumberInputPane` base call, and zero whole-file pointer hits from this pass.
   - Cross-reference the live inline construction sequence in [UID:00005U] `GiveInputPane`.

3. Update `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md`:
   - Replace stale global/helper names with `g_pUserPane`, `m_itemCommandBusy`, `g_packetSender`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt32BE`, and `QueueAndSendPacket`.
   - Record that `0x005b52f0-0x005b538a` is a vtable-routed submit method needing an exact child page.
   - Keep aggregate C++ blank unless child split is performed.

4. Update `by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md`:
   - Raise recommended metadata to `86/89` if accepted.
   - Use best source-facing helper name `SendGiveGoldPacket(unsigned int amount)`.
   - Replace `g_pCollectionData` and older helper names with current global/helper names.
   - Add exact pre/post padding, size `0x69`, zero whole-file pointer-hit evidence, and local terminator-not-transmitted note.
   - Keep formal C++ blank under the raw no-route helper proof.

5. Create a new by-memory child if callback includes split permission:
   - Proposed path: `by-memory/0x005b52f0-0x005b538a.GiveGoldInputPaneSubmitGoldAmount.md`.
   - Proposed owner/emitter: [UID:00005T] `GiveGoldInputPane`.
   - Proposed reconstructable status: `TRUE`.
   - Proposed initial score: `86/90`.
   - Include first-draft method C++ from this report after finalizing the base virtual spelling.

6. Update `by-type/by-vtable/ItemActionInputPaneVtableFamily.md` if needed:
   - Ensure the GiveGold row includes `0x00630090 -> 0x005b52f0` as the primary submit/action slot.
   - Keep raw constructor store sites separate from the live inline creator store sites.

7. Update `by-class/GiveInputPane.md`:
   - Clarify that its gold branch inline-constructs `GiveGoldInputPane` with prompt id `0x2b` and vtables `0x00630048/0x00630098/0x006300c8`.
   - Do not transfer ownership of `GiveGoldInputPane` to `GiveInputPane`.

8. Check `by-global/g_pCollectionData.md` and `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`:
   - These already appear updated to canonical `g_pUserPane`; only add a target cross-reference if the callback asks for support synchronization.

9. Do not hand-edit `auto-generated/*`.
   - Let validator/autogen update generated reports/files only in an apply-enabled implementation callback if supervisor permits.

10. Do not edit `by-memory/-coverage-report.md` directly in a report-only pass.
    - Use the supervisor-owned coverage text below if accepted.

## Exact Supervisor-Owned Coverage Text

Report-only pass did not edit coverage files. The following rows are proposed for supervisor-owned coverage synchronization.

Replacement row for `by-class/-coverage-report.md` [UID:00005T]:

```text
- [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md) : reconstructable : 87% : strong : B015 2026-06-19 source-quality pass keeps the class in [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), confirms raw constructor [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md), vtable-routed submit slot `0x00630090 -> 0x005b52f0`, creator inline construction in [UID:00005U][GiveInputPane](by-class/GiveInputPane.md), exact packet `[0x2a, amount:u32be]` semantics, `g_pUserPane +0x3ec0` item-command busy gate, Socket-owned `g_packetSender` / `QueueAndSendPacket`, PacketBuffer writer names, adjacent no-route [UID:0003MW][0x005b5390-0x005b53f9.SendGiveGoldPacketRaw](by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md), and blank formal C++ pending exact submit-child/declaration and raw no-route policy cleanup.
```

Replacement row for `by-memory/-coverage-report.md` [UID:0001MI]:

```text
    - [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) 0x005b52b0-0x005b52f0 | raw constructor | GiveGoldInputPaneRawConstructor : reconstructable : 86% : strong : B015 2026-06-19 source-quality recheck confirms exact `0x40` / 64-byte constructor-shaped body, prompt id `0x2b` / 43, `g_pLanguageMan` lookup, `NumberInputPane` base constructor call `0x004f27a0`, primary/secondary/tertiary vtable stores `0x00630048/0x00630098/0x006300c8` at `this+0/+0xa0/+0xa4`, preceding `0x005b52ac-0x005b52b0` padding, zero whole-file pointer hits to raw start, matching live inline construction stores in [UID:00005U][GiveInputPane](by-class/GiveInputPane.md), and blank formal C++ because source reconstruction should use declarations/live creator route rather than emitting a no-route raw constructor clone.
```

Add or replacement row for `by-memory/-coverage-report.md` [UID:0003MW], placed after the GiveGold submit/constructor coverage area and before [UID:0002SB] `GroupInputPaneRawConstructor` if no row currently exists:

```text
    - [UID:0003MW][0x005b5390-0x005b53f9.SendGiveGoldPacketRaw](by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md) 0x005b5390-0x005b53f9 | raw helper | SendGiveGoldPacketRaw : reconstructable : 86% : strong : B015 2026-06-19 source-quality recheck confirms exact `0x69` / 105-byte no-IDA file-scope give-gold packet helper, pre/post padding `0x005b538a-0x005b5390` and `0x005b53f9-0x005b5400`, best source-facing name `SendGiveGoldPacket(unsigned int amount)`, packet layout opcode `0x2a` plus amount via `PacketBufferWriteUInt32BE`, local-only spare terminator, send length `5`, `g_pUserPane +0x3ec0` item-command busy gate, Socket-owned `g_packetSender` and `QueueAndSendPacket`, zero whole-file pointer hits to `0x005b5390`, and blank formal C++ because the vtable-routed [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md) submit method emits equivalent packet logic inline while this helper has no proven caller/source route.
```

Future row template if the exact submit child is created:

```text
    - [UID:TBD][0x005b52f0-0x005b538a.GiveGoldInputPaneSubmitGoldAmount](by-memory/0x005b52f0-0x005b538a.GiveGoldInputPaneSubmitGoldAmount.md) 0x005b52f0-0x005b538a | class method | GiveGoldInputPaneSubmitGoldAmount : reconstructable : 86% : strong : Vtable-routed primary action/submit method for [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md) through `0x00630090 -> 0x005b52f0`; copies up to 15 wide chars from the LineInputPane text child, parses unsigned decimal with `%u` through the wide scanf wrapper, checks `g_pUserPane +0x3ec0` item-command busy gate, writes opcode `0x2a` and amount big-endian through PacketBuffer helpers, writes a local-only spare terminator, queues exactly five bytes through Socket-owned `g_packetSender` / `QueueAndSendPacket`, and should own first-draft method C++ after exact child creation and virtual name selection.
```

## Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00005T-GiveGoldInputPane-class-source-quality-removed.md](00005T-GiveGoldInputPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`.
- `ok: 1`.
- `mode: file`.
- `apply: False`.
- `scanned markdown files: 1`.
- Key direct result: `ok 00005T by-class/GiveGoldInputPane.md UID header exists`.
- Dry run only; validator reported generated/autogen no-op or emitter-has-no-code statuses but wrote no files.

## Non-Edits

This report-only pass did not edit any `by-*` documentation file, generated file, or coverage report. The only intended edits for this pass are this report and `tools/leaser/Agents/Agent-B015/notes.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/00005T-GiveGoldInputPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"00005T"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00005T-GiveGoldInputPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/00005T-GiveGoldInputPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00005T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
