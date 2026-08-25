** TARGET-REPORT-UID:00021S **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B002 Report: 00021S ClanStatusPacketDialogHandlers Source Quality

## Assignment

- Agent: `Agent-B002`
- Assignment id: `B002-goal2-clan-status-packet-dialog-handlers-source-quality-00021S-20260619`
- Target UID: `00021S`
- Target path: `source-3/project-documentation/by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/00021S-ClanStatusPacketDialogHandlers-source-quality.md`
- Current target metadata observed: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000I8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000I8`, blank formal C++.
- Task mode: report-only. I did not edit by-* docs, generated files, IDA DB, project-level reports, or `by-memory/-coverage-report.md`.

## Evidence Checked

- Read the current target page `by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md`.
- Read related source/owner docs:
  - `by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md`
  - `by-class/ClanStatusPane.md`
  - `by-file/Clan.md`
  - `by-file/ClanDialogs.md`
  - `by-class/ClanEnlistInputDialog.md`
  - `by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md`
  - `by-memory/0x0067adf0-0x0069adf0.WideCharStrGlobalBuffer.md`
  - `by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md`
  - `by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md`
- Read helper/source-family docs used by the callee analysis:
  - `by-memory/0x00516030-0x00516036.GetMemoryMan.md`
  - `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`
  - `by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md`
  - `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
  - `by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md`
  - `by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md`
  - `by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md`
- Read prior reports as leads, not as final authority:
  - `tools/leaser/Agents/Agent-B013/research/00021S-ClanStatusPacketDialogHandlers-source-quality.md`
  - `tools/leaser/Agents/Agent-B012/research/executed/00010B-00021C-ClanStatusPacketParserDispatcher-source-quality.md`
  - `tools/leaser/Agents/b-agent-rule26-incorporation-tracker.md`
  - `tools/leaser/Agents/wave3_data_issues.md`
- Rechecked local PE evidence against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA MCP was not available in this session (`Unable to connect to the remote server`), so the fresh route check was local PE/Capstone plus current docs. The current target already records prior live IDA evidence; this report separates those prior IDA facts from this session's local recheck.

## Current Target Assessment

The current target already carries the accepted `86/91` direction and most of the important B013 details. The page correctly distinguishes the three directly dispatcher-called helper bodies from the nine retained no-xref opener siblings, preserves the aggregate formal-C++ blank state, and routes the current aggregate through [UID:0000I8] `Clan`.

I do not recommend raising the target above `86/91` in this pass. The remaining blockers are real source-quality blockers, not documentation omissions: final original helper names are inferred; no-xref opener siblings have no direct branch/table route; and formal source should be emitted on child pages rather than as one monolithic aggregate.

The main implementation value from this B002 pass is:

- preserve `00021S` as a reviewed Clan helper island/index for now;
- create method-level child pages before source emission;
- use source-facing names and signatures below;
- keep no-xref opener bodies as retained source-authored helpers, not padding or compiler glue;
- update stale support text in `ClanDialogs.md` and the stale `by-memory/-coverage-report.md` row.

## Heuristic / Inference Reanalysis And Validation

### Range Inventory And Boundaries

Local PE bytes reconfirm twelve function-shaped bodies separated by `0xcc` alignment:

| Range | Size | Head bytes | Best role |
| --- | ---: | --- | --- |
| `0x004877d0-0x004879d8` | `0x208` | `55 8b ec b8 6c 00 01 00 e8 63 ff 13 00 a1 24 2f` | live `ClanStatusPane` subtype `1` request/info text handler |
| `0x004879e0-0x00487c37` | `0x257` | `55 8b ec 81 ec 24 03 00 00 a1 24 2f 67 00 33 c5` | live `ClanStatusPane` subtype `2` join-list handler |
| `0x00487c40-0x00487d61` | `0x121` | `55 8b ec 6a ff 68 84 c5 5f 00 64 a1 00 00 00 00` | retained leave-confirm opener |
| `0x00487d70-0x00487e13` | `0xa3` | `55 8b ec 6a ff 68 b7 c5 5f 00 64 a1 00 00 00 00` | retained deposit-money opener |
| `0x00487e20-0x00487e9c` | `0x7c` | `55 8b ec 6a ff 68 dd c5 5f 00 64 a1 00 00 00 00` | retained deposit-item opener |
| `0x00487ea0-0x00488167` | `0x2c7` | `55 8b ec 6a ff 68 06 c6 5f 00 64 a1 00 00 00 00` | live `ClanStatusPane` subtype `6` enlist/list/dialog handler |
| `0x00488170-0x00488213` | `0xa3` | `55 8b ec 6a ff 68 39 c6 5f 00 64 a1 00 00 00 00` | retained expel-name opener |
| `0x00488220-0x004882c3` | `0xa3` | `55 8b ec 6a ff 68 5f c6 5f 00 64 a1 00 00 00 00` | retained summon-name opener |
| `0x004882d0-0x0048836b` | `0x9b` | `55 8b ec 6a ff 68 85 c6 5f 00 64 a1 00 00 00 00` | retained appear-name opener |
| `0x00488370-0x0048845d` | `0xed` | `55 8b ec 6a ff 68 b6 c6 5f 00 64 a1 00 00 00 00` | retained change-name/change-attr opener |
| `0x00488460-0x00488503` | `0xa3` | `55 8b ec 6a ff 68 dc c6 5f 00 64 a1 00 00 00 00` | retained withdraw-money opener |
| `0x00488510-0x00488594` | `0x84` | `55 8b ec 6a ff 68 02 c7 5f 00 64 a1 00 00 00 00` | retained withdraw-item opener |

Padding gaps observed from the PE are all `0xcc`: `0x004879d8-0x004879e0` (8 bytes), `0x00487c37-0x00487c40` (9), `0x00487d61-0x00487d70` (15), `0x00487e13-0x00487e20` (13), `0x00487e9c-0x00487ea0` (4), `0x00488167-0x00488170` (9), `0x00488213-0x00488220` (13), `0x004882c3-0x004882d0` (13), `0x0048836b-0x00488370` (5), `0x0048845d-0x00488460` (3), `0x00488503-0x00488510` (13), and post-target `0x00488594-0x004885a0` (12).

The exact bytes and alignment support "real functions in one compiler/object island" over "raw padding" or "disassembly accident." Several retained opener bodies use full MSVC EH/security-cookie style prologues and derived vtable stores, which is inconsistent with compiler-generated jump-table filler.

### Route And Liveness

Fresh local section-aware rel32 scan found exactly three branch/call targets into this island:

- `0x00484fdb -> 0x004877d0`
- `0x00484fec -> 0x004879e0`
- `0x00485181 -> 0x00487ea0`

Fresh exact little-endian VA and RVA pointer scans found zero exact-start pointer hits for all twelve function starts. This independently confirms the current page's direct-call/no-pointer split.

The three direct callers are all in [UID:00021C] `ClanStatusPacketDispatcher`, opcode `0x43` cases `1`, `2`, and `6`. The dispatcher also contains inline branches for cases `3`, `4`, `5`, `7`, `8`, `9`, `10`, `11`, and `12` that duplicate the retained opener siblings' behavior instead of calling them. Therefore:

- the three direct cases are live and should be child-split as `ClanStatusPane` methods;
- the nine opener siblings are source-authored retained functions, but not proven active callbacks;
- no hidden table route should be claimed until a non-exact pointer, registration table, or object-layout route is found;
- no-owner/non-emitting is too weak for the whole target because three functions are live and all twelve are source-shaped Clan code.

### Best Source-Facing Names And Signatures

Recommended source-facing names for future exact children:

| Range | Recommended source-facing name | Signature direction | Confidence |
| --- | --- | --- | --- |
| `0x004877d0` | `ClanStatusPane::HandleClanEnlistRequestPacket` | `bool ClanStatusPane::HandleClanEnlistRequestPacket(const unsigned char *packet)` | high |
| `0x004879e0` | `ClanStatusPane::HandleClanJoinListPacket` | `bool ClanStatusPane::HandleClanJoinListPacket(const unsigned char *packet)` | high |
| `0x00487ea0` | `ClanStatusPane::HandleClanEnlistPacket` | `bool ClanStatusPane::HandleClanEnlistPacket(const unsigned char *packet)` | medium-high |
| `0x00487c40` | `OpenClanLeaveConfirmDialogFromPacket` | `static bool OpenClanLeaveConfirmDialogFromPacket(const unsigned char *packet)` | medium |
| `0x00487d70` | `OpenClanDepositMoneyDialogFromPacket` | `static bool OpenClanDepositMoneyDialogFromPacket(const unsigned char *packet)` | medium |
| `0x00487e20` | `OpenClanDepositItemDialogFromPacket` | `static bool OpenClanDepositItemDialogFromPacket(const unsigned char *packet)` | medium |
| `0x00488170` | `OpenClanExpelNameDialogFromPacket` | `static bool OpenClanExpelNameDialogFromPacket(const unsigned char *packet)` | medium |
| `0x00488220` | `OpenClanSummonNameDialogFromPacket` | `static bool OpenClanSummonNameDialogFromPacket(const unsigned char *packet)` | medium |
| `0x004882d0` | `OpenClanAppearNameDialogFromPacket` | `static bool OpenClanAppearNameDialogFromPacket(const unsigned char *packet)` | medium |
| `0x00488370` | `OpenClanChangeDialogFromPacket` | `static bool OpenClanChangeDialogFromPacket(const unsigned char *packet)` | medium |
| `0x00488460` | `OpenClanWithdrawMoneyDialogFromPacket` | `static bool OpenClanWithdrawMoneyDialogFromPacket(const unsigned char *packet)` | medium |
| `0x00488510` | `OpenClanWithdrawItemDialogFromPacket` | `static bool OpenClanWithdrawItemDialogFromPacket(const unsigned char *packet)` | medium |

For `0x00487ea0`, the current page name `ClanStatusPane::HandleClanMemberListOrEnlistDialogPacket` is behaviorally accurate but too descriptive for final source. I recommend `HandleClanEnlistPacket` as the final source-facing method name because subtype `6` corresponds to the enlist-list refresh/selection packet family, action `0` fills `m_enlistListPane`, action `1` opens `ClanEnlistInputDialog`, and action `2` is a success/no-op. `HandleClanEnlistListPacket` is an acceptable alias, but "MemberList" should be avoided in final source unless a server/protocol name proves that term.

For no-xref opener siblings, `static bool Open...FromPacket(const unsigned char *packet)` is the best source-facing shape because the bodies construct modal dialogs from packet action/text data and do not need to mutate `ClanStatusPane` fields. If future decompilation proves an unused `ecx` context parameter was part of the original helper family, the source declaration can be widened to `static bool Open...(ClanStatusPane *pane, const unsigned char *packet)` and leave `pane` unused, but current documentation should not invent that parameter.

### Packet Subtypes And Action Names

Recommended packet enum names for support docs and future C++:

```cpp
enum ClanStatusPacketSubtype {
    kClanStatusAttributes = 0,
    kClanEnlistRequest = 1,
    kClanJoinList = 2,
    kClanLeave = 3,
    kClanDepositMoney = 4,
    kClanDepositItem = 5,
    kClanEnlist = 6,
    kClanExpel = 7,
    kClanSummon = 8,
    kClanAppear = 9,
    kClanChange = 10,
    kClanWithdrawMoney = 11,
    kClanWithdrawItem = 12,
};
```

Do not introduce a single global enum name for `packet[2]` beyond `action` or `state` yet. The same byte means "open dialog" for action `0`, "success/accepted" for some action `1` paths, "open attribute dialog" for subtype `10` action `1`, and "success/no-op" for subtype `6` action `2`. Per-subtype constants are safer until protocol docs are stronger.

### ClanStatusPane Field And Helper Reconciliation

The three live handlers should reference the field names already established by `ClanStatusPane` and related parser/constructor docs:

- `this + 0xf8`: `m_currentClanStatusView`
- `this + 0xfe`: `m_statusHeaderText`
- `this + 0x2510`: `m_infoListPane`
- `this + 0x2514`: `m_joinListPane`
- `this + 0x2518`: `m_enlistListPane`

Helper/source-family names to use instead of raw labels:

- `0x00516030`: `GetMemoryMan`, not a packet helper. It appears because packet text/list handling allocates or manages copied buffers through the MemoryMan utility island.
- `0x00516220`: `MemmoveWrapper`, source-facing `memmove`/copy helper.
- `0x004f4aa0`: `operator new` wrapper backed by `MemoryMan`.
- `0x00575480`: `PacketBufferReadUInt16BE`. If the code reads a 32-bit scalar, use `0x005754c0`/`PacketBufferReadUInt32BE`; this target's visible list counts/lengths align with the packet scalar read family rather than feature-local parsers.
- `0x0058fc30`: `TextEditPane` text mutation/insert/set helper family. In `0x004877d0`, it should be described as setting or inserting the request body into the info child text control, not as a Clan-specific text helper.
- `0x00488680`: `ClanStringListPane::InsertOrReplaceText`, used at live call sites `0x00487b56` and `0x0048807b` for join/enlist child list population.
- `0x004b7c50`: `InitRectBounds`/rectangle initializer, used when configuring child pane display rectangles.
- `0x0049feb0`: `AlertPane::AlertPane`, the base constructor for `ClanLeaveConfirmDialog`.
- `0x00488b40`: `ClanNameInputDialog` base constructor shell for name/money dialogs.
- `0x00489600`: `ClanAttrInputDialog` base constructor shell for enlist/change attribute dialogs.
- `0x0048a1c0`: `ClanDepItemDialog` constructor/core.
- `0x0048a810`: `ClanWidItemDialog` constructor/core.

### Dialog Family Reconciliation

The retained opener bodies and inline dispatcher sites store the same dialog vtables documented in `ClanModalDialogVtableData` and `ClanBankVtableData`:

- `ClanLeaveConfirmDialog`: `0x00615f38`, `0x00615fa0`, `0x00615fd0`
- `ClanDepMoneyInputDialog`: `0x00615998`, `0x006159fc`, `0x00615a2c`
- `ClanExpelNameInputDialog`: `0x00615ad8`, `0x00615b3c`, `0x00615b6c`
- `ClanSummonNameInputDialog`: `0x00615b78`, `0x00615bdc`, `0x00615c0c`
- `ClanAppearNameInputDialog`: `0x00615c18`, `0x00615c7c`, `0x00615cac`
- `ClanChangeNameInputDialog`: `0x00615cb8`, `0x00615d1c`, `0x00615d4c`
- `ClanEnlistInputDialog`: `0x00615df8`, `0x00615e5c`, `0x00615e8c`
- `ClanChangeInputDialog`: `0x00615e98`, `0x00615efc`, `0x00615f2c`
- `ClanDepItemDialog`: constructor/core at `0x0048a1c0`
- `ClanWidItemDialog`: constructor/core at `0x0048a810`

These vtable stores prove dialog class identity at the opener bodies, but they do not transfer ownership of the packet handlers to the dialog classes. The packet source placement is still `social/Clan.cpp` / `ClanStatusPane` for live view-state helpers and file-local `Clan` for retained openers. `ClanDialogs.cpp` remains a split candidate for the modal class definitions and submitters, not the owner for this opcode `0x43` packet handler island.

### Rejected Alternatives

- Pure compiler-generated code: rejected. The bodies decode packet action/text, allocate concrete dialogs, call handwritten constructors, mutate `ClanStatusPane` child fields, and store concrete vtables. That is source-authored behavior, not destructor glue, EH cleanup, or switch-table support.
- Padding/alignment: rejected. All twelve bodies have coherent prologues, control flow, calls, and returns, with separate `0xcc` alignment between them.
- No-owner/non-emitting for the entire range: rejected. Three subranges are directly called from the live packet dispatcher, and all twelve are in the Clan source island.
- Route all twelve as `ClanStatusPane` methods: rejected. The nine opener siblings do not touch status-pane fields and have no proven direct dispatch route; forcing them into the class would overstate receiver ownership.
- Route all twelve to `ClanDialogs.cpp`: rejected. The modal dialogs are callees. The live helpers update `ClanStatusPane` view/list state, and the no-xref siblings are packet-to-dialog opener glue in the Clan packet island.
- Route deposit/withdraw item opener siblings to `ClanBank.cpp`: rejected for this target. The item dialog classes themselves have a stronger `ClanBank` split, but these opener bodies sit in the opcode `0x43` Clan status packet island and mirror `ClanStatusPacketDispatcher` branches.
- Treat retained opener siblings as hidden callbacks: not accepted. The PE scan found no exact VA/RVA pointer hits and no direct branch route. They may be object-file retained original helper functions, but a runtime callback route is unproven.
- Emit one monolithic formal C++ block on `00021S`: rejected. The target covers twelve functions with mixed liveness and ownership. A single C++ function would misrepresent the binary and the generated output route.

## Child Split And Emission Policy

Recommended policy:

1. Keep current `00021S` metadata at `86/91`, owner/emitter `[UID:0000I8] Clan`, blank formal C++ for now.
2. If the supervisor wants source emission, create exact child pages under the `00021S` range. Do not put formal C++ into the aggregate.
3. Split the three live direct-call functions as `ClanStatusPane` source methods:
   - `0x004877d0-0x004879d8` -> `ClanStatusPane::HandleClanEnlistRequestPacket`
   - `0x004879e0-0x00487c37` -> `ClanStatusPane::HandleClanJoinListPacket`
   - `0x00487ea0-0x00488167` -> `ClanStatusPane::HandleClanEnlistPacket`
4. Split the nine retained opener siblings either as reconstructable file-local helpers under `[UID:0000I8] Clan` with blank C++ until the retained-helper policy is accepted, or as exact no-xref child pages with source-shaped behavior and no emitted code.
5. After exact child pages exist and carry the source decisions, optionally convert `00021S` into a non-emitting split index. Until then, keeping the aggregate reconstructable with blank C++ is pragmatic because it still carries the only reviewed inventory for the cluster.

### Review-Only First-Draft C++ For Eligible Live Children

This C++ is not recommended for the aggregate page. It is first-draft source shape for future exact child pages after child creation and child-level decompilation review.

```cpp
bool ClanStatusPane::HandleClanEnlistRequestPacket(const unsigned char *packet)
{
    ClanPacketCursor cursor(packet + 2);

    wchar_t clanName[40];
    cursor.ReadLengthPrefixedWideText(clanName, 40);

    wchar_t *requestText = g_clanWideScratch;
    cursor.ReadLengthPrefixedWideText(requestText, kClanWideScratchChars);

    wcscpy_s(m_statusHeaderText, 40, clanName);
    m_infoListPane->SetText(requestText);
    ShowInfoList();
    return true;
}

bool ClanStatusPane::HandleClanJoinListPacket(const unsigned char *packet)
{
    if (packet[2] != 0) {
        return false;
    }

    ClanPacketCursor cursor(packet + 3);
    cursor.ReadLengthPrefixedWideText(m_statusHeaderText, 40);

    m_joinListPane->ClearRows();
    const int count = cursor.ReadUInt16BE();
    for (int i = 0; i < count; ++i) {
        wchar_t name[40];
        cursor.ReadLengthPrefixedWideText(name, 40);
        m_joinListPane->InsertOrReplaceText(i, name);
    }

    ShowJoinList();
    return true;
}

bool ClanStatusPane::HandleClanEnlistPacket(const unsigned char *packet)
{
    switch (packet[2]) {
    case 0: {
        ClanPacketCursor cursor(packet + 3);
        cursor.ReadLengthPrefixedWideText(m_statusHeaderText, 40);

        m_enlistListPane->ClearRows();
        const int count = cursor.ReadUInt16BE();
        for (int i = 0; i < count; ++i) {
            wchar_t name[40];
            cursor.ReadLengthPrefixedWideText(name, 40);
            m_enlistListPane->InsertOrReplaceText(i, name);
        }

        ShowEnlistList();
        return true;
    }
    case 1:
        new ClanEnlistInputDialog(packet);
        return true;
    case 2:
        return true;
    default:
        return false;
    }
}
```

The helper names `ClanPacketCursor`, `ReadLengthPrefixedWideText`, `g_clanWideScratch`, and `ClearRows` are source-shape placeholders. Do not insert this block without converting those placeholders to the project-wide PacketBuffer/string helper style used by the exact child pages. The target aggregate should stay blank.

## Open Questions Closed Or Narrowed

| Question | Resolution |
| --- | --- |
| Are the no-xref opener siblings live? | No direct live route is proven. They have zero exact VA/RVA pointer hits and no rel32 callers in the local PE scan. Treat them as retained source functions, not active callbacks. |
| Are the no-xref opener siblings dead padding? | No. They are function-shaped, action-gated, source-authored dialog opener bodies with real constructor/vtable side effects. |
| Should the whole target route to `ClanStatusPane`? | No. Only three live bodies are `ClanStatusPane` methods. The rest are file-local `Clan` opener helpers if preserved. |
| Should the whole target route to `ClanDialogs.cpp`? | No. Dialog classes are constructed, but the packet decoding and view updates belong to Clan/ClanStatusPane. |
| Is first-draft C++ justified? | Yes for the three exact live child functions after child pages exist. No for the aggregate. No-xref opener child C++ should wait for the retained-helper emission policy. |
| What are the best names for raw helper labels? | Use `GetMemoryMan`, `MemmoveWrapper`, `operator new`, `PacketBufferReadUInt16BE`, `TextEditPane` text mutation, `ClanStringListPane::InsertOrReplaceText`, `InitRectBounds`, `AlertPane::AlertPane`, `ClanNameInputDialog`, `ClanAttrInputDialog`, `ClanDepItemDialog`, and `ClanWidItemDialog` as listed above. |
| Should `0x00487ea0` keep the long name? | The long current name is accurate, but final source should prefer `ClanStatusPane::HandleClanEnlistPacket` because subtype `6` is the enlist packet family. |

## Recommended Target Doc Changes

If the supervisor sends an implementation callback, update `by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md` as follows:

- Keep metadata unchanged: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000I8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000I8`.
- Keep formal C++ blank.
- Add B002 2026-06-19 local PE evidence:
  - PE path and MD5.
  - IDA MCP unavailable in this pass; local PE/Capstone used as fresh route validation.
  - Twelve exact function-shaped ranges and `0xcc` gaps listed above.
  - Only three direct rel32 calls: `0x00484fdb`, `0x00484fec`, `0x00485181`.
  - Zero exact VA/RVA pointer hits to all twelve starts.
- Add source-facing child split decision:
  - future child `0x004877d0`: `ClanStatusPane::HandleClanEnlistRequestPacket`;
  - future child `0x004879e0`: `ClanStatusPane::HandleClanJoinListPacket`;
  - future child `0x00487ea0`: `ClanStatusPane::HandleClanEnlistPacket`;
  - no-xref siblings: retained `Clan.cpp` file-local opener helpers, not active callback routes.
- Replace vague raw helper labels with stable helper-family names from existing docs.
- Preserve the no-monolithic-C++ proof: aggregate spans twelve functions with mixed liveness and should not emit one formal block.

## Recommended Support Doc Changes

- `by-class/ClanStatusPane.md`
  - Add a note under `OnClanStatusPacket`/dispatcher evidence that future `00021S` child split should promote only `0x004877d0`, `0x004879e0`, and `0x00487ea0` as `ClanStatusPane` methods.
  - Use final method direction `HandleClanEnlistRequestPacket`, `HandleClanJoinListPacket`, and `HandleClanEnlistPacket`.
  - Preserve fields `m_currentClanStatusView`, `m_statusHeaderText`, `m_infoListPane`, `m_joinListPane`, and `m_enlistListPane`.
- `by-file/Clan.md`
  - Add B002's child split policy: `00021S` currently routes as a Clan helper island; exact live children should route to `ClanStatusPane`, retained opener siblings stay file-local `Clan.cpp` unless a callback/table route is found.
  - Mention `ClanStringListPane::InsertOrReplaceText` call sites `0x00487b56` and `0x0048807b`.
- `by-file/ClanDialogs.md`
  - Update the `ClanEnlistInputDialog` row. Current text says "parser/handlers and submitter [UID:0002O3]" and "related clan packet handling." Replace it with "raw constructor [UID:00021W], submitter [UID:0002O3]; action `1` of [UID:00021S] subtype `6` constructs this dialog, but the packet handler itself remains `ClanStatusPane`/`social/Clan.cpp` ownership."
  - Add explicit negative route for [UID:00021S], parallel to the existing negative route for [UID:00010B] and [UID:00021C]: modal dialog classes are callees, not owners, for the opcode `0x43` packet-handler island.
- `by-class/ClanEnlistInputDialog.md`
  - If not already present after B013, keep the clarification that `0x00487ea0` is a ClanStatusPane packet handler that constructs `ClanEnlistInputDialog` on action `1`, not a direct method of the dialog class.
- `by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md`
  - Keep the direct-helper-only caveat: cases `1`, `2`, and `6` call `00021S`; cases `3`, `4`, `5`, and `7..12` inline dialog construction. If names are updated, change the review sketch case `6` helper to `HandleClanEnlistPacket`.
- `by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md`
  - Optional, only if non-duplicative: add `00021S` no-xref opener store sites as retained opener evidence, while preserving that vtables themselves are compiler/linker output.
- `by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md`
  - Optional, only if non-duplicative: cross-reference retained deposit/withdraw item opener call sites, but keep item dialog class/source ownership separate from the packet opener helper island.

## Score And Metadata Recommendation

- Target `00021S`: keep `COMPLETION:86`, `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:0000I8` and `EMITTER_UIDS:0000I8` for the aggregate until child split.
- Keep `RECONSTRUCTABLE:TRUE` on the aggregate while it remains the only page carrying the reviewed inventory. If exact children are later created and carry all source-bearing functions, supervisor may convert this page to a non-emitting split index.
- Do not add aggregate formal C++.
- Future exact live child pages should likely score at or above `85/88` after child-level decompilation because they have direct dispatcher call edges and exact field/callee behavior. No-xref opener child pages should likely be capped around `85/88` with blank C++ until retained-helper emission policy is accepted.

## Exact Supervisor-Owned Coverage Row

Do not edit `by-memory/-coverage-report.md` during this B-agent report. Replace the current stale `00021S` row, currently between the ignored jump table row `0x004877a0-0x004877d0` and the ignored padding row `0x00488594-0x004885a0`, with:

```text
    - [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) 0x004877d0-0x00488594 | packet-handler cluster | ClanStatusPacketDialogHandlers : reconstructable : 86% : strong : B002 2026-06-19 source-quality recheck independently confirms the target's 86/91 direction: local PE `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` contains twelve exact function-shaped ranges separated by `0xcc` alignment, only three direct dispatcher calls (`0x00484fdb -> 0x004877d0`, `0x00484fec -> 0x004879e0`, `0x00485181 -> 0x00487ea0`), and zero exact VA/RVA pointer hits to all twelve starts. The three live helpers are best split as `ClanStatusPane` packet/view methods for opcode `0x43` subtypes `1`, `2`, and `6`, touching `m_currentClanStatusView` `+0xf8`, `m_statusHeaderText` `+0xfe`, `m_infoListPane` `+0x2510`, `m_joinListPane` `+0x2514`, `m_enlistListPane` `+0x2518`, `WideCharStrGlobalBuffer` `0x0067adf0`, and `ClanStringListPane::InsertOrReplaceText`. The nine no-xref siblings are valid retained `social/Clan.cpp` file-local dialog opener bodies that mirror dispatcher inline branches and construct the Clan modal dialog family, but they are not proven hidden callbacks; aggregate formal C++ stays blank until method-level children carry source, or the final source model explicitly chooses static retained helper emission.
```

## Validation Commands For Implementation Callback

Expected scoped validators from `source-3/project-documentation` after any accepted doc implementation:

> Executable block R001 was removed from this report and preserved verbatim in [00021S-ClanStatusPacketDialogHandlers-source-quality-removed.md](00021S-ClanStatusPacketDialogHandlers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional vtable support docs are edited:

> Executable block R002 was removed from this report and preserved verbatim in [00021S-ClanStatusPacketDialogHandlers-source-quality-removed.md](00021S-ClanStatusPacketDialogHandlers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If only this report is created, no by-* validation is required.

## IDA Rename, Type, And Comment Recommendations

Rename recommendations, high confidence unless noted:

- `sub_4877D0` -> `ClanStatusPane_HandleClanEnlistRequestPacket`
- `sub_4879E0` -> `ClanStatusPane_HandleClanJoinListPacket`
- `sub_487EA0` -> `ClanStatusPane_HandleClanEnlistPacket` (medium-high; alias current long name in comments)
- `sub_487C40` -> `OpenClanLeaveConfirmDialogFromPacket` (medium)
- `sub_487D70` -> `OpenClanDepositMoneyDialogFromPacket` (medium)
- `sub_487E20` -> `OpenClanDepositItemDialogFromPacket` (medium)
- `sub_488170` -> `OpenClanExpelNameDialogFromPacket` (medium)
- `sub_488220` -> `OpenClanSummonNameDialogFromPacket` (medium)
- `sub_4882D0` -> `OpenClanAppearNameDialogFromPacket` (medium)
- `sub_488370` -> `OpenClanChangeDialogFromPacket` (medium)
- `sub_488460` -> `OpenClanWithdrawMoneyDialogFromPacket` (medium)
- `sub_488510` -> `OpenClanWithdrawItemDialogFromPacket` (medium)

Type recommendations:

- For live children: `bool __thiscall ClanStatusPane_Handle...(ClanStatusPane *this, const unsigned char *packet)`.
- For no-xref opener siblings: source-facing `static bool Open...(const unsigned char *packet)`; IDA ABI type should be confirmed in IDA before applying because no direct caller fixes the calling convention.

Comments to add if IDA DB edits are later authorized:

- At `0x004877d0`, `0x004879e0`, `0x00487ea0`: "directly called by ClanStatusPane opcode 0x43 dispatcher; future exact child should route to ClanStatusPane."
- At all no-xref opener starts: "retained source-shaped dialog opener; mirrors dispatcher inline branch; no rel32/VA/RVA route found in B002 PE scan."
- On padding gaps: "0xcc alignment between functions; not source."
- On vtable stores inside opener bodies: "dialog class identity anchor only; packet helper ownership remains Clan/ClanStatusPane."

## Implementation Checklist For Supervisor Callback

1. Patch target doc only if supervisor wants B002's fresh evidence incorporated:
   - keep metadata at `86/91`;
   - add local PE/Capstone route evidence and helper-name table;
   - add recommended child split policy and final source-facing names;
   - keep aggregate formal C++ blank.
2. Patch support docs with report-level detail, especially `ClanDialogs.md` stale `ClanEnlistInputDialog` row and negative route for `00021S`.
3. Do not edit generated files unless a validator/autogen workflow requires it after support-doc changes. This report does not recommend adding aggregate C++, so autogen should not produce new source for `00021S`.
4. Do not edit `by-memory/-coverage-report.md`; supervisor should apply the exact row above.
5. Run scoped validators listed above and record results.

## Final Recommendation

Implementation is ready for documentation updates, but not for aggregate formal C++ emission. The best current direction is "source-quality reviewed Clan helper island, `86/91`, child-split before code." The three live direct handlers have enough evidence for future exact child C++ after child pages are created. The nine retained opener siblings should remain documented as source-authored no-xref Clan file-local helpers with blank C++ until the project decides whether retained helper bodies may emit source without active route proof.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00021S-ClanStatusPacketDialogHandlers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00021S"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00021S-ClanStatusPacketDialogHandlers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00021S-ClanStatusPacketDialogHandlers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00021S"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
