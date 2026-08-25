** TARGET-REPORT-UID:0001HR **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001HR ServerSelectPane Source-Quality Report

Status: FINISHED

## Recommendation Summary

- Target: [UID:0001HR] `source-3/project-documentation/by-memory/0x00573d20-0x005747df.ServerSelectPane.md`.
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0001HR-ServerSelectPane-source-quality.md`.
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000NO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NO`, blank formal C++.
- Recommended metadata after supervisor implementation: `COMPLETION:87`, `CONFIDENCE:89`, keep `CANONICAL_OWNER:0000NO`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000NO`, keep `EMITTER_POSITION_OPTIONAL` blank.
- Owner/source route: keep [UID:0000NO] `ServerSelectPane`, projected to `NexusTK/login/ServerSelectPane.cpp`.
- Formal target C++ recommendation: keep blank on this broad aggregate. Emit source from exact method/helper children or from a coordinated `ServerSelectPane.cpp` file reconstruction. The aggregate spans two classes, file-local helpers, raw no-function wrappers, vtable/destructor compiler glue, and padding; a single `RECONSTRUCTION_CPP` block on [UID:0001HR] would duplicate children and mix source-authored code with ABI material.
- Highest-value implementation changes: replace stale `dword_67A7C8` / `dword_67AB1C` language with `g_pConfig` / `g_pApplication`, document the `ServerSelectDirectory` and `ServerSelectEntry` layouts, name the raw wrappers with best-supported roles, add the no-code proof, and replace the stale `78%` coverage row.

No by-* docs, support docs, generated files, IDA database, or `by-memory/-coverage-report.md` were edited.

## Evidence Checked

- Assignment/rules: `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, and `source-3/project-documentation/tools/leaser/Agents/Agent-B013/goal.md`.
- Target/support docs: [UID:0001HR] `ServerSelectPane`, [UID:0000NO] `by-file/ServerSelectPane.md`, [UID:0000D2] `by-class/ServerSelectPane.md`, [UID:0000D1] `by-class/ServerSelectMenuItemList.md`, [UID:0000VG] `by-item/ServerSelectHelpers_574510_5745b0.md`, [UID:0000S8] `by-global/g_pServerSelectPane.md`.
- Related data/docs: [UID:0003D7] `ServerSelectPaneVtableData`, [UID:0003D9] `ServerSelectMenuItemListVtableData`, [UID:00026F] `SimpleServerSelectReadOnlyData`, [UID:0002XN] `g_pServerSelectPane`, [UID:00029W] `MainMenuDialogSingletonSlots`, [UID:0000SW] `g_useEpfAssets`, [UID:00028Q] `g_pConfig`, [UID:000294] `g_pApplication`.
- Shared helper docs: [UID:000194] `ListPane`, [UID:0003TZ] `ListPaneConstructionAndBaseDestructor`, [UID:00007A] `ListPane`, [UID:0000KT] `ListPane`, [UID:0003YJ] `PacketBufferScalarBigEndianWriteHelpers`, [UID:0001HU] `QueueAndSendPacket`, [UID:0000WO] `CrtStdioCommonSprintfGlue`.
- Reports checked: `by-memory/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, `project-level/-unresolved.md`, `project-level/-resolved.md`, `by-file/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-item/-coverage-report.md`.
- Validator baseline: `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00573d20-0x005747df.ServerSelectPane.md --uid-only`; result `ok: 1`.
- Local read-only PE evidence: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 already documented in support pages as `4247e04e20b65d6414c7238aa8ff5515`. Capstone/manual PE parsing checked exact bytes, relative call/jump refs, dword occurrences, vtable refs, strings, and caller context.
- IDA MCP was not modified. This pass used the existing live-IDA evidence already in docs plus local PE rechecks.

## Gate And Score Analysis

The target already clears the current 85/85 route gate: it is `85/86`, reconstructable, and has a valid owner/emitter [UID:0000NO]. The score issue is source quality, not reachability. The current page still carries stale `dword_67A7C8`, `dword_67AB1C`, and raw helper language, and the supervisor-owned coverage row still says `78%`.

Recommended score `87/89` is justified after implementation because this pass resolves:

- constructor caller argument shape through `g_pConfig + 0x28db10`;
- `ServerSelectDirectory` / `ServerSelectEntry` layout and list row pointer shape;
- packet helper names and owner boundaries;
- raw helper liveness/naming policy;
- compiler glue and vtable no-code policy;
- exact coverage row replacement.

Do not raise to final-audit range yet. Original field spellings, exact virtual method names, raw-wrapper reachability, and complete `ServerSelectPane.h` declaration shape remain inferred.

## Boundary And Liveness Recheck

Local PE recheck agrees with the current target boundary and support docs.

| Range | Evidence and source-quality decision |
| --- | --- |
| `0x00573d20-0x00574301` | Real constructor, `ret 4`. Caller at `0x004f70db` passes `g_pConfig + 0x28db10`. The table row can continue to summarize as `0x00573d20-0x00574300`, but exact source text should note the trailing `00` byte belongs to `ret 4` and padding starts at `0x00574301`. |
| `0x00574310-0x00574339` | Non-deleting destructor body: restores three `ServerSelectPane` vtables, clears `g_pServerSelectPane`, tail-jumps to base teardown. Source is ordinary `~ServerSelectPane()` behavior, not an independent public helper. |
| `0x00574340-0x00574431` | `ServerSelectPane::OnDialogAction(int actionId)`; vtable ref at `0x00624d70`; calls `ApplySelectedServer` from both layout branches. |
| `0x00574440-0x00574497` | `ServerSelectPane::UpdateScrollButtons()`; vtable ref at `0x00624d74`; uses child id `3` list and `ListPane::GetSelectionCount`/enablement helper at `0x004f3e20`. |
| `0x005744a0-0x005744f8` | Raw but complete `ServerSelectMenuItemList::ServerSelectMenuItemList(ServerSelectPane *owner)` body. No IDA function object or direct refs, but constructor stores `owner` at `+0x14c`, calls `ListPane` with row stride `4`, and installs `ServerSelectMenuItemList` vtables. Retain as source-shaped raw constructor evidence. |
| `0x00574500-0x0057450e` | Raw `ServerSelectMenuItemList::AddServerEntry(const ServerSelectEntry *entry)` wrapper. It takes the address of the pointer argument and calls `ListPane::AddEntry`; no direct refs found. |
| `0x00574510-0x0057454e` | Real selected-row helper. Best name: `ServerSelectMenuItemList::ApplySelectedServer()` or `ApplySelectedServerSelection()`. It reads inherited `ListPane::m_selectedIndex` at `+0x134`, fetches the row via `ListPane::GetSelectedEntry`, copies entry name to config, then calls `SendServerSelectPacket`. |
| `0x00574550-0x0057455f` | Raw virtual-dispatch wrapper. Best role: `ServerSelectMenuItemList::SelectServerEntryIndex(int index)` / selection activation helper. It calls vtable slot `+0x78` with `(index, 0)`. No direct refs found; do not promote to exact source C++ until a caller/table route appears. |
| `0x00574570-0x005745aa` | Raw selected-entry helper. Best role: `ServerSelectMenuItemList::ApplyServerEntry(const ServerSelectEntry *entry)`. It copies entry name to `g_pApplication + 0x858`, then calls `SendServerSelectPacket`. No direct refs to start found; the call to `0x005745b0` at `0x005745a1` proves body liveness as retained source-shaped code, not padding. |
| `0x005745b0-0x0057465e` | Real packet/state helper. Best source-facing name: file-local `SendServerSelectPacket` or `ApplyServerEndpoint`. It uses selected id plus entry pointer; it does not use `ecx`, so prefer file-local/static helper over a Socket/PacketBuffer method. |
| `0x00574660-0x0057466b` | `ServerSelectMenuItemList::OnItemActivated` / owner-forwarding thunk. Loads owner from `+0x14c`, then jumps to shared action logic at `0x0049de70`. |
| `0x00574670-0x00574748` | `ServerSelectMenuItemList::DrawListItem(int index, ServerSelectEntry *const *row, RectBounds *rect)`. Confirms list row is a pointer to a server entry. |
| `0x00574750-0x0057475b` | Tiny singleton-clear unwind/helper. Source role is cleanup/unwind support for `g_pServerSelectPane`, not a user-facing helper. |
| `0x0057475b-0x00574771` | Compiler adjustor thunks for secondary/tertiary destructor views. No hand-authored C++ body. |
| `0x00574780-0x005747df` | Scalar deleting destructor wrapper. Use ordinary destructor source plus compiler delete flags; do not paste ABI wrapper C++ into final source. |

Local rel32 scan found the same reachable edges documented by support pages: constructor called only from `0x004f70db`; `0x00574510` called only from `0x00574399` and `0x005743db`; `0x005745b0` called from `0x00574546` and raw wrapper site `0x005745a1`. No rel32 or absolute VA/RVA pointer route was found for raw starts `0x005744a0`, `0x00574500`, `0x00574550`, or `0x00574570`.

## Source Names, Types, And Fields

Best-supported constructor signature:

```cpp
ServerSelectPane::ServerSelectPane(ServerSelectDirectory *serverDirectory);
```

Evidence: caller `0x004f70d2-0x004f70db` passes `g_pConfig + 0x28db10`; constructor stores the argument at `this + 0x26c`; constructor loops over entries starting at the argument pointer and reads count at argument `+0x300`.

Recommended type names:

```cpp
struct ServerSelectEntry {
    unsigned char serverId;      // +0x00, sent as packet byte 2
    unsigned char reserved01[3];
    const wchar_t *name;         // +0x04, copied to selected-server buffers
    const wchar_t *description;  // +0x08, used by DrawListItem
    unsigned int reserved0c;     // +0x0c, not resolved by this pass
    unsigned char address[4];    // +0x10..+0x13
    short portOrEndpointSuffix;  // +0x14, formatted as signed decimal
    unsigned char reserved16[2]; // +0x16..+0x17
};

struct ServerSelectDirectory {
    ServerSelectEntry entries[32]; // 0x18 * 32 == 0x300
    int entryCount;                // +0x300
};
```

Recommended `ServerSelectMenuItemList` field:

```cpp
ServerSelectPane *m_owner; // +0x14c
```

Recommended `ServerSelectPane` field:

```cpp
ServerSelectDirectory *m_serverDirectory; // +0x26c
```

Recommended config/application field names for docs:

| Address/offset | Best current name | Evidence |
| --- | --- | --- |
| `g_pConfig + 0x28db10` | `serverSelectDirectory` / `m_serverSelectDirectory` | Main-menu caller passes this to constructor; first 32 records are 0x18-byte server entries, count at `+0x300`. |
| `g_pConfig + 0x2916d0` | `selectedServerName[16]` / `configuredServerName` | `_wcscpy_s(..., 0x10, entry->name)` in `0x00574510`; constructor compares this buffer against entry names to preselect saved server. |
| `g_pConfig + 0x28d9d8` | `selectedServerId` | `0x005745b0` stores selected id after sending opcode `0x57`. |
| `g_pConfig + 0x28d9dd` | `alternateServerEndpointActive` / `preserveExistingServerEndpoint` | If nonzero, `0x005745b0` skips endpoint string formatting. Existing "alternate-path flag" wording is defensible; original label remains unknown. |
| `g_pConfig + 0x291230` | `selectedServerEndpointText[64]` | Destination for `swprintf_s(buffer, 0x40, L"%d.%d.%d.%d.%d.%d", ...)`. |
| `g_pConfig + 0x2912b0` | `serverEndpointPrefix` / first endpoint component | First decimal argument to `"%d.%d.%d.%d.%d.%d"` before entry address bytes and port/suffix. |
| `g_pApplication + 0x858` | `currentServerName[256]` / `selectedServerNameDisplay` | Application constructor initializes this buffer to `TestServer`; row draw and raw entry helper update it with `entry->name` through the `%s` formatting wrapper. |

Avoid claiming original source spellings for these fields. The names above are behavior names with high-probability roles.

## Packet Helper Semantics

`0x005745b0` should be documented source-facing as:

```cpp
static void SendServerSelectPacket(unsigned int selectedServerId,
                                   const ServerSelectEntry *entry);
```

Observed body:

- Writes packet bytes `0x57`, `0`, and `selectedServerId` through [UID:0003YJ] `PacketBufferWriteUInt8` / `0x00575380`.
- Queues exactly three bytes through [UID:0001HU] `QueueAndSendPacket` / `0x00574bb0` using `g_packetSender`.
- Stores `selectedServerId` at `g_pConfig + 0x28d9d8`.
- If `g_pConfig + 0x28d9dd` is zero, formats `g_pConfig + 0x291230` with `L"%d.%d.%d.%d.%d.%d"`, using `g_pConfig + 0x2912b0`, `entry->address[0..3]`, and `entry->portOrEndpointSuffix`.

Do not route this helper to Socket, PacketBuffer, CashShopRequest, or ProtocolSend. Those are shared dependencies. The feature packet construction and server-selection state writes belong in `login/ServerSelectPane.cpp`.

## Raw Helper Policy

The raw helpers are source-shaped, not padding:

- `0x005744a0` constructs a derived list object and stores vtables.
- `0x00574500` wraps adding a pointer-row to `ListPane`.
- `0x00574550` wraps a virtual selection/activation call.
- `0x00574570` copies a selected entry name and calls the packet/state helper.

However, all four raw starts still have no direct function object, ordinary caller, vtable slot, absolute VA pointer, or RVA pointer evidence. Recommended policy:

- Document them in [UID:0001HR], [UID:0000D1], and [UID:0000VG] with best source names.
- Do not force IDA function creation or final formal child C++ solely from this report.
- If exact children are created later, keep them as raw/source-shaped children with "no direct route found" caveats until runtime or table evidence appears.

Rejected alternatives:

- `ChattingColorListPane`: rejected for `0x00574510`; both callers are inside `ServerSelectPane::OnDialogAction`, and row data/config packet behavior is server-selection-specific.
- `Socket`/`PacketBuffer`/`ProtocolSend`: rejected for `0x005745b0`; those helpers only serialize/queue a packet built by server-select source.
- `ListPane.cpp`: rejected as direct owner for `ServerSelectMenuItemList`; `ListPane` owns base storage/selection helpers, but this derived class stores a `ServerSelectPane *owner`, draws `Name : Description`, and sends server-select state.
- "Dead padding" for raw wrappers: rejected because each body has coherent prologue/body/return or constructor/vtable stores, and `0x00574570` has an interior live call to `0x005745b0`.

## First-Draft Source Shape

Do not paste this into [UID:0001HR] as formal aggregate C++. Use it as source-style guidance for future exact child/file implementation.

```cpp
ServerSelectMenuItemList::ServerSelectMenuItemList(ServerSelectPane *owner)
    : ListPane(sizeof(ServerSelectEntry *), 0x10, 0x12f, 0x0e,
               g_useEpfAssets != 1, true, true),
      m_owner(owner)
{
}

void ServerSelectMenuItemList::AddServerEntry(const ServerSelectEntry *entry)
{
    ListPane::AddEntry(&entry);
}

void ServerSelectMenuItemList::ApplySelectedServer()
{
    if (m_selectedIndex < 0)
        return;

    const ServerSelectEntry *entry =
        *static_cast<const ServerSelectEntry *const *>(ListPane::GetSelectedEntry(m_selectedIndex));

    wcscpy_s(g_pConfig->selectedServerName, 0x10, entry->name);
    SendServerSelectPacket(entry->serverId, entry);
}

static void SendServerSelectPacket(unsigned int serverId, const ServerSelectEntry *entry)
{
    unsigned char packet[3];
    PacketBufferWriteUInt8(0x57, &packet[0]);
    PacketBufferWriteUInt8(0, &packet[1]);
    PacketBufferWriteUInt8(serverId, &packet[2]);
    QueueAndSendPacket(g_packetSender, packet, 3);

    g_pConfig->selectedServerId = serverId;

    if (!g_pConfig->alternateServerEndpointActive) {
        swprintf_s(g_pConfig->selectedServerEndpointText, 0x40,
                   L"%d.%d.%d.%d.%d.%d",
                   g_pConfig->serverEndpointPrefix,
                   entry->address[0], entry->address[1],
                   entry->address[2], entry->address[3],
                   entry->portOrEndpointSuffix);
    }
}

void ServerSelectMenuItemList::DrawListItem(int index,
                                            ServerSelectEntry *const *row,
                                            RectBounds *rect)
{
    const ServerSelectEntry *entry = *row;
    RectBounds drawRect = *rect;
    if (g_useEpfAssets != 1)
        drawRect.top -= 10;

    if (ListPane::IsItemSelected(index)) {
        // Existing draw-color/font helpers should replace these placeholders.
        SetSelectedRowTextStyle();
        swprintf_s(g_pApplication->currentServerName, 0x100, L"%s", entry->name);
    } else {
        SetNormalRowTextStyle();
    }

    wchar_t line[0x400];
    swprintf_s(line, 0x400, L"%s : %s", entry->name, entry->description);
    DrawText(line, wcslen(line), &drawRect);
}
```

## Exact No-Code Proof For Target Aggregate

Keep [UID:0001HR] formal C++ blank:

- The range has many independent function starts plus raw no-function bodies and padding; it is not one source body.
- It crosses `ServerSelectPane`, `ServerSelectMenuItemList`, file-local packet/state helpers, singleton cleanup, destructor thunks, scalar deleting destructor ABI code, and compiler-generated vtable references.
- Exact vtable data pages already document compiler-generated bytes; final source should recreate class declarations/destructors, not hand-author vtable or thunk bytes.
- Raw wrapper starts currently lack direct caller/table/pointer routes; formal aggregate C++ would overclaim source reachability.
- Child/file-level C++ can be emitted later using the draft shapes above once method names, field names, and helper declarations are coordinated.

## Recommended Target Doc Changes

Apply these to `by-memory/0x00573d20-0x005747df.ServerSelectPane.md` after supervisor approval:

- Metadata: set `COMPLETION:87`, `CONFIDENCE:89`; keep owner/emitter route unchanged.
- Replace `Disposition` text with: "Reconstructable login/main-menu project code. Formal C++ remains blank on this aggregate because source emission belongs to exact method/helper children or a coordinated `ServerSelectPane.cpp` file reconstruction."
- In `Covered Ranges`, update raw helper rows:
  - `0x005744a0-0x005744f8`: `ServerSelectMenuItemList::ServerSelectMenuItemList(ServerSelectPane *owner)` raw constructor-shaped bytes.
  - `0x00574500-0x0057450e`: `ServerSelectMenuItemList::AddServerEntry(const ServerSelectEntry *entry)` raw add-entry pointer-row wrapper.
  - `0x00574510-0x0057454e`: `ServerSelectMenuItemList::ApplySelectedServer()` / selected-row apply helper.
  - `0x00574550-0x0057455f`: raw selection/activation wrapper calling vtable slot `+0x78`.
  - `0x00574570-0x005745aa`: raw `ApplyServerEntry(const ServerSelectEntry *entry)` helper that updates `g_pApplication +0x858` then calls `SendServerSelectPacket`.
  - `0x005745b0-0x0057465e`: `SendServerSelectPacket(unsigned int selectedServerId, const ServerSelectEntry *entry)` / endpoint-state helper.
- Replace stale `dword_67A7C8` references with `g_pConfig` and offsets above; replace `dword_67AB1C`/`unk_67AB1C` references with `g_pApplication`.
- Add a `ServerSelectEntry And Directory Layout` section with the type layouts from this report.
- Add a `Raw Helper Policy` section stating that the raw starts are source-shaped but still have no start xrefs/function objects/pointer routes.
- Add the target aggregate no-code proof from this report.
- Add evidence that the constructor caller passes `g_pConfig + 0x28db10`, the constructor stores it at `this +0x26c`, and entry count is at argument `+0x300`.

## Recommended Support-Doc Changes

- [UID:0000NO] `by-file/ServerSelectPane.md`:
  - Update current recovered source note to include `ServerSelectDirectory` and `ServerSelectEntry`.
  - Replace stale `g_serverSelectPane` alias wording with canonical `g_pServerSelectPane`.
  - Correct old `0xffffffff` singleton byte note to current zero-initialized evidence from [UID:0002XN].
  - Add final source policy: exact children/file reconstruction should emit, broad aggregate stays blank.
- [UID:0000D2] `by-class/ServerSelectPane.md`:
  - Add field `m_serverDirectory` at `+0x26c`.
  - Add constructor signature direction `ServerSelectPane(ServerSelectDirectory *serverDirectory)`.
  - Mention `OnDialogAction(int actionId)` gets child id `3`, unwraps the list at child storage `+0x108`, and calls `ServerSelectMenuItemList::ApplySelectedServer()`.
- [UID:0000D1] `by-class/ServerSelectMenuItemList.md`:
  - Add `m_owner` at `+0x14c`.
  - Clarify that ListPane row stride is `4` and rows store `ServerSelectEntry *`, not inline server-entry records.
  - Add best names for raw constructor, add-entry wrapper, selected-entry raw helper, and `DrawListItem` signature.
  - Replace `dword_67AB1C + 2136` with `g_pApplication +0x858` / `currentServerName` behavior name.
- [UID:0000VG] `by-item/ServerSelectHelpers_574510_5745b0.md`:
  - Prefer names `ServerSelectMenuItemList::ApplySelectedServer()` and file-local `SendServerSelectPacket`.
  - Add packet opcode details using `PacketBufferWriteUInt8` and `QueueAndSendPacket`.
  - Add the `"%d.%d.%d.%d.%d.%d"` literal at `0x00624ee8`, not just the suffix/interior `0x00624ef0`.
  - State the helper is not Socket/PacketBuffer-owned despite using those helpers.
- [UID:00028Q] `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`:
  - Add a known field cluster for `+0x28db10` server-select directory, `+0x28d9d8/+0x28d9dd` selected-id/endpoint flag, and `+0x291230/+0x2912b0/+0x2916d0` server endpoint/name fields.
- [UID:000294] `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md` or Application support docs:
  - Add field note `+0x858 currentServerName[256]` initialized to `TestServer` by the constructor and updated by server-select list drawing/raw apply helper.
- [UID:00026F] `SimpleServerSelectReadOnlyData`:
  - Add exact literal `0x00624ee8` as `L"%d.%d.%d.%d.%d.%d"`.
  - Keep aggregate non-emitting.

## IDA Rename/Type/Comment Recommendations

Do not force new IDA function starts for raw wrappers from this report alone. If the IDA owner later accepts behavior-only raw functions, use these names with caveats:

| Address | Recommendation | Confidence |
| --- | --- | --- |
| `0x00573d20` | `ServerSelectPane::ServerSelectPane(ServerSelectDirectory *)` | High for role/signature shape; medium for original type spelling. |
| `0x00574310` | `ServerSelectPane::~ServerSelectPane` non-deleting body / cleanup helper | High for destructor behavior. |
| `0x00574340` | `ServerSelectPane::OnDialogAction(int actionId)` | High for handler role; medium for exact virtual name. |
| `0x00574440` | `ServerSelectPane::UpdateScrollButtons()` | High. |
| `0x005744a0` | raw `ServerSelectMenuItemList::ServerSelectMenuItemList(ServerSelectPane *)` | High behavior, medium liveness due no function object/xrefs. |
| `0x00574500` | raw `ServerSelectMenuItemList::AddServerEntry(const ServerSelectEntry *)` | Medium-high behavior, low direct liveness. |
| `0x00574510` | `ServerSelectMenuItemList::ApplySelectedServer()` | High. |
| `0x00574550` | raw `ServerSelectMenuItemList::SelectServerEntryIndex(int)` / activation wrapper | Medium behavior, low direct liveness. |
| `0x00574570` | raw `ServerSelectMenuItemList::ApplyServerEntry(const ServerSelectEntry *)` | Medium-high behavior, low direct liveness. |
| `0x005745b0` | `SendServerSelectPacket(unsigned int, const ServerSelectEntry *)` | High behavior, medium for exact source placement as file-local/static. |
| `0x00574660` | `ServerSelectMenuItemList::OnItemActivated` | High. |
| `0x00574670` | `ServerSelectMenuItemList::DrawListItem` | High. |
| `0x00574750` | `ClearServerSelectPaneSingleton` / unwind clear helper | High behavior; source name unknown. |
| `0x0057475b`, `0x00574766`, `0x00574780` | Keep compiler thunk/scalar destructor labels; do not source-name as user helpers. | High. |

Recommended type comments:

- `ServerSelectPane +0x26c`: `ServerSelectDirectory *m_serverDirectory`.
- `ServerSelectMenuItemList +0x14c`: `ServerSelectPane *m_owner`.
- `ListPane` row in `ServerSelectMenuItemList`: `ServerSelectEntry *`.
- `g_pConfig +0x28db10`: `ServerSelectDirectory`.
- `g_pApplication +0x858`: `currentServerName[256]`.

## Exact Coverage Row Replacement

Do not edit `by-memory/-coverage-report.md` directly. Supervisor-owned replacement row:

```text
    - [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md) 0x00573d20-0x005747df | login/server-select class range | ServerSelectPane : reconstructable : 87% : strong : B013 source-quality pass resolves the file route through [UID:0000NO] ServerSelectPane.cpp, constructor caller argument `g_pConfig +0x28db10`, `ServerSelectDirectory` and `ServerSelectEntry` layout, list row pointer storage, selected-server config/application fields, raw helper source roles and no-xref liveness limits, packet helper signature/opcode `0x57` semantics through PacketBufferWriteUInt8 and QueueAndSendPacket, current zero-initialized `g_pServerSelectPane` singleton ownership, compiler thunk/vtable no-code policy, and blank aggregate formal C++ pending exact child/file-level emission.
```

## Validation Needed After Implementation

Run these after supervisor applies accepted doc/support changes:

> Executable block R001 was removed from this report and preserved verbatim in [0001HR-ServerSelectPane-source-quality-removed.md](0001HR-ServerSelectPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If exact children are later created, also run normal file validators on each new child and regenerate/check `auto-generated/-ag-memory-coverage.md` and `project-level/-auto-completion-stats.md` through the established supervisor workflow.

## Remaining Open Questions

- Original source spellings for `ServerSelectDirectory`, `ServerSelectEntry`, `m_serverDirectory`, `m_owner`, and config/application fields are not recovered.
- `g_pConfig +0x28d9dd` flag meaning is behaviorally known only as "skip endpoint formatting when set"; `alternateServerEndpointActive` / `preserveExistingServerEndpoint` are descriptive candidates.
- Raw wrappers have no start xrefs or pointer/table routes. Their roles are clear enough for documentation, but not enough for unconditional final child C++.
- Exact virtual names for `OnDialogAction`, `DrawListItem`, and `OnItemActivated` should be coordinated with the broader DialogPane/ListPane declaration pass.
- Constructor has two layout branches and repeated list/control setup. Final file-level C++ should factor only if source style supports it; do not invent a helper solely to reduce duplicate decompiler-looking code.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0001HR-ServerSelectPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0001HR"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001HR-ServerSelectPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0001HR-ServerSelectPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001HR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
