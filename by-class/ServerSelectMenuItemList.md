*** UID:0000D1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../app/Application.h"
#include "../app/StartupWindow.h"
#include "../network/PacketBuffer.h"
#include "../network/Socket.h"
#include "../render/Surface.h"

#include <wchar.h>

ServerSelectMenuItemList::ServerSelectMenuItemList(ServerSelectPane *owner)
    : ListPane(sizeof(ServerSelectEntry *), 16, 303, 14,
               g_useEpfAssets != 1, true, 1),
      m_owner(owner)
{
}

void ServerSelectMenuItemList::AddServerEntry(ServerSelectEntry *entry)
{
    AddEntry(&entry);
}

void ServerSelectMenuItemList::ApplySelectedServer()
{
    if (m_selectedIndex == -1)
        return;

    ServerSelectEntry *entry =
        *static_cast<ServerSelectEntry **>(GetItem(m_selectedIndex));

    wcscpy_s(g_pConfig->m_lastServerName, 16, entry->name);
    SendServerSelectPacket(entry->serverId, entry);
}

void ServerSelectMenuItemList::SelectServerEntryIndex(int index)
{
    OnItemSelected(index, 0);
}

void ServerSelectMenuItemList::ApplyServerEntry(
    const ServerSelectEntry *entry)
{
    swprintf_s(g_pApplication->m_currentServerName, 256,
               L"%s", entry->name);
    SendServerSelectPacket(entry->serverId, entry);
}

void ServerSelectMenuItemList::SendServerSelectPacket(
    unsigned int serverId, const ServerSelectEntry *entry)
{
    unsigned char packet[16];

    PacketBufferWriteUInt8(0x57, &packet[0]);
    PacketBufferWriteUInt8(0, &packet[1]);
    PacketBufferWriteUInt8((unsigned char)serverId, &packet[2]);
    g_packetSender->QueueAndSendPacket(packet, 3);

    g_pConfig->m_selectedServerId = serverId;
    if (!g_pConfig->m_alternateServerEndpointActive) {
        swprintf_s(g_pConfig->m_serverEndpointText, 64,
                   L"%d.%d.%d.%d.%d.%d",
                   g_pConfig->m_serverEndpointPrefix,
                   entry->address[0], entry->address[1],
                   entry->address[2], entry->address[3],
                   (short)entry->port);
    }
}

void ServerSelectMenuItemList::OnItemActivated()
{
    m_owner->ActivateFocusedControl();
}

void ServerSelectMenuItemList::DrawListEntry(
    int rowIndex, void *rowData, RectBounds *rowBounds)
{
    ServerSelectEntry *entry =
        *static_cast<ServerSelectEntry **>(rowData);

    if (g_useEpfAssets)
        rowBounds->right -= 10;

    if (IsItemSelected(rowIndex)) {
        SetDrawColor(0x25);
        g_pfnFillRect(this, rowBounds);
        SetTextColor(0x80);
        swprintf_s(g_pApplication->m_currentServerName, 256,
                   L"%s", entry->name);
    } else {
        SetTextColor(0x25);
    }

    wchar_t text[1024];
    swprintf_s(text, 1024, L"%s : %s",
               entry->name, entry->description);
    DrawTextInRect(text, wcslen(text), rowBounds);
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../config/Config.h"
#include "../ui/controls/ListPane.h"

class ServerSelectPane;

class ServerSelectMenuItemList : public ListPane
{
public:
    ServerSelectMenuItemList(ServerSelectPane *owner);

    void AddServerEntry(ServerSelectEntry *entry);
    void ApplySelectedServer();
    void SelectServerEntryIndex(int index);
    void ApplyServerEntry(const ServerSelectEntry *entry);

protected:
    virtual void OnItemActivated();
    virtual void DrawListEntry(int rowIndex, void *rowData,
                               RectBounds *rowBounds);

private:
    void SendServerSelectPacket(unsigned int serverId,
                                const ServerSelectEntry *entry);

    ServerSelectPane *m_owner;
};

typedef char ServerSelectEntrySizeMustBe24[
    sizeof(ServerSelectEntry) == 0x18 ? 1 : -1];
typedef char ServerSelectMenuItemListSizeMustBe336[
    sizeof(ServerSelectMenuItemList) == 0x150 ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Complete ListPane-derived server-selection list with exact 0x150 layout, ServerSelectEntry pointer rows, owner field, constructor/add/apply/select/send/activate/draw behavior, opcode-0x57 state flow, full three-view RTTI/vtable proof, formal period-compatible CPP/H, and compiler-generated destructor/vtable disposition. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ServerSelectMenuItemList

## UID0003D9 Compile-Visible Dependency Closure - 2026-08-15

The formal source now consumes every non-local declaration from its evidence-backed owner. `ServerSelectPane.h` includes `Config.h`, which remains the one complete owner of `ServerSelectEntry`, `Config`, and `g_pConfig`; the former consumer-local `ServerSelectEntry` duplicate is retained below only as historical pre-closure source shape. `ListPane.h` remains the complete base and `RectBounds` declaration route. `ServerSelectPane.cpp` includes the complete `Application` owner, StartupWindow global declaration, PacketBuffer writer API, Socket class/global declaration, Surface callback declaration, and `<wchar.h>` in that order after its local header.

This closure does not alter the accepted class layout or behavior. The list still stores `ServerSelectEntry *` rows, remains exactly `0x150` bytes, writes the selected name through the owning `Application` declaration, emits packet bytes `57 00 id`, sends exactly three bytes through `g_packetSender->QueueAndSendPacket(packet, 3)`, and uses the existing Surface callback type for list-row fill. A local partial `Application`, raw `+0x858` cast, duplicate `ServerSelectEntry`, duplicate global, guessed precompiled header, or free-function Socket call remains rejected.

## Status

- Confidence: final-audit strength for the class layout, direct base, three-view ABI, constructor/store routes, complete authored method family, packet/drawing behavior, compiler/source split, and source route; original private spelling and static liveness of four retained raw starts remain bounded below certainty.
- Likely source file: [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- Address range: [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md)
- Parent attachment: [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md) is the `91/94` `NexusTK/login/` source owner. This class is `93/95`, position 30, and owns complete formal CPP/H plus the UID0003D9 compiler-ABI marker child.

## Class Purpose

`ServerSelectMenuItemList` is the list-pane widget used by `ServerSelectPane`. It forwards row activation to the owner pane and draws each server row as `Name : Description`, updating the selected server name in the application/session buffer when a row is highlighted.

## Layout Notes

| Offset or inherited layout | Best current name | Evidence |
| --- | --- | --- |
| `+0x14c` | `ServerSelectPane *m_owner` | Raw constructor stores the owner pointer here; `0x00574660` loads this field and jumps to shared owner activation logic. |
| ListPane row stride `4` | `ServerSelectEntry *` row pointer | Raw constructor passes row stride `4`; add-entry wrapper passes the address of an entry pointer; draw/selection helpers dereference row data before reading `ServerSelectEntry` fields. |

`ServerSelectEntry` is a behavior name. The row points to records with `serverId` at `+0x00`, `name` at `+0x04`, `description` at `+0x08`, endpoint bytes at `+0x10..+0x13`, and port/suffix at `+0x14`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ServerSelectMenuItemList(ServerSelectPane *owner)` raw constructor-shaped bytes | `0x005744a0-0x005744f8` | Builds the direct `ListPane`-derived object, passes row stride `4`, stores `owner` at `+0x14c`, and installs the three `ServerSelectMenuItemList` vtables at `0x00624dc4`, `0x00624e4c`, and `0x00624e7c`. IDA still does not model this start as a function. |
| `AddServerEntry(ServerSelectEntry *entry)` raw wrapper | `0x00574500-0x0057450e` | Takes the address of the non-const entry pointer and calls `ListPane::AddEntry`; no direct refs to the raw start were found. The former `const ServerSelectEntry *` prose was inconsistent with the accepted formal CPP/H signature and is superseded. |
| `ApplySelectedServer()` | `0x00574510-0x0057454e` | Reads selected index, fetches the row pointer, copies `entry->name` to `g_pConfig + 0x2916d0`, and calls the file-local packet/state helper. |
| `SelectServerEntryIndex(int index)` / activation wrapper | `0x00574550-0x0057455f` | Raw wrapper calling vtable slot `+0x78` with `(index, 0)`; no direct refs to the raw start were found. |
| `ApplyServerEntry(const ServerSelectEntry *entry)` raw helper | `0x00574570-0x005745aa` | Updates `g_pApplication + 0x858` / current-server display state and calls `SendServerSelectPacket`; no direct refs to the raw start were found. |
| `OnItemActivated` | `0x00574660-0x0057466b` | Two-instruction owner-forwarding thunk: loads `[this + 0x14c]` and jumps to shared activation logic at `0x0049de70`. |
| `DrawListEntry(int rowIndex, void *rowData, RectBounds *rowBounds)` | `0x00574670-0x00574748` | Primary slot `+0x80`; draws selected/unselected rows, formats `Name : Description`, copies the selected server name to `g_pApplication + 0x858`, and in EPF mode subtracts 10 from `rowBounds->right`. |

## Evidence Notes

- 2026-06-04 live IDA MCP confirms no function object at `0x005744a0`, real modeled virtuals at `0x00574660-0x0057466b` and `0x00574670-0x00574748`, the server-selection helper at `0x00574510-0x0057454e`, and the packet/helper body at `0x005745b0-0x0057465e`.
- Raw constructor disassembly at `0x005744a0` checks [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`, calls the `ListPane` constructor at `0x005744c7 -> 0x004f3a50`, stores the owner pointer from `[ebp+8]` to `[this + 0x14c]`, and writes vtables `0x00624dc4`, `0x00624e4c`, and `0x00624e7c`.
- Parent `ServerSelectPane` construction also installs the primary `ServerSelectMenuItemList` vtable at `0x00573f0b` and `0x005741c8`, matching the inline/class-local construction path documented by [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md).
- Vtable slots confirm `0x00624e40 -> 0x00574660` and `0x00624e44 -> 0x00574670`; `xrefs_to` for those methods are vtable data refs, not ordinary code calls.
- `0x00574660` is a compact activation thunk (`mov ecx, [ecx+0x14c]; jmp 0x0049de70`), proving that row activation forwards to the owning server-select context.
- 2026-06-04 live decompilation of `0x00574670` confirms the row-entry layout used by the selection helpers: `[entry + 4]` is the server name, `[entry + 8]` is the description, selected rows copy the name into `g_pApplication + 0x858` / current-server display state, and drawing formats `"%s : %s"` before calling the text draw helper.
- Selection helper `0x00574510` uses the same entry pointer family and forwards the selected id plus entry pointer to `0x005745b0`, which keeps the list class tied to `ServerSelectPane.cpp` rather than a generic list/control module.
- 2026-06-12 A005 Batch267 live IDA MCP refresh:
  - `idb_meta` confirmed `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - `py_eval` verified the exact vtable child [UID:0003D9][0x00624dc0-0x00624e84.ServerSelectMenuItemListVtableData](by-memory/0x00624dc0-0x00624e84.ServerSelectMenuItemListVtableData.md): RTTI dwords at `0x00624dc0`, `0x00624e48`, and `0x00624e78`; vtable bases at `0x00624dc4`, `0x00624e4c`, and `0x00624e7c`; function slots `0x00624e40 -> 0x00574660` and `0x00624e44 -> 0x00574670`; and the `0x00624e84` `Select Server` string successor.
  - `xrefs_to` reconfirmed table-base refs from parent constructor/list-building stores `0x00573f0b/0x00573f11/0x00573f1b` and `0x005741c8/0x005741ce/0x005741d8`, plus the raw constructor stores `0x005744d7/0x005744dd/0x005744e7`.
  - `lookup_funcs` reconfirmed `0x005744a0` is not an IDA function, `0x00574660` is `0x0b` / 11 bytes (Verified with int_convert.py), `0x00574670` is `0xd8` / 216 bytes (Verified with int_convert.py), `0x00574510` is `0x3e` / 62 bytes (Verified with int_convert.py), and `0x005745b0` is `0xae` / 174 bytes (Verified with int_convert.py).
  - `disasm` reconfirmed the raw constructor stores the owner pointer at `+0x14c` / 332 (Verified with int_convert.py), installs adjusted vtables at `+0xa0` / 160 and `+0xa4` / 164 (Verified with int_convert.py), and passes list constructor constants `0x12f` / 303, `0x0e` / 14, `0x10` / 16, and `0x04` / 4 (Verified with int_convert.py).
- Remaining uncertainty is limited to original private spelling/access and static liveness of the raw starts, not class ownership, behavior, source shape, or emission. Complete formal CPP/H is now installed above using human, period-compatible names.
- B013 source-quality recheck keeps the raw starts as source-shaped but no-route: `0x005744a0`, `0x00574500`, `0x00574550`, and `0x00574570` have coherent constructor/wrapper/helper bodies, but no direct function object, caller, start xref, vtable slot, absolute VA pointer, or RVA pointer route was found. Do not force standalone final C++ for those helpers until exact child/file-level emission is coordinated.

## Cross-References

- [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md)
- [UID:0000D2][ServerSelectPane](by-class/ServerSelectPane.md)
- [UID:0000VG][ServerSelectHelpers_574510_5745b0](by-item/ServerSelectHelpers_574510_5745b0.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)

## UID0003D9 Accepted Source-Quality Closure

### Direct inheritance, ABI, and layout

- Exact RTTI type descriptor `[0x6791f4,0x67921c)` names `ServerSelectMenuItemList`. Its BCA order is self, `ListPane`, `ScrollablePane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, and `TimerHandler`; there is no `SimpleListPane` node.
- The primary, EventHandler, and TimerHandler object views begin at `0x624dc4`, `0x624e4c`, and `0x624e7c`. Their COL complete-object offsets are `0`, `0xa0`, and `0xa4`, exactly matching inherited handler subobjects.
- `ListPane` is `0x14c` bytes. The raw constructor stores `ServerSelectPane *m_owner` at `+0x14c`, and the activation thunk loads that pointer. Natural total size is `0x150`; no explicit padding or hidden derived field is required.
- List entry size is four bytes because rows hold `ServerSelectEntry *`. The natural 0x18-byte record is `serverId`, aligned wide-string pointers for name/description/agreement text, four address bytes, and unsigned-short port.
- Exact ABI data and all 49 cells are documented by [UID:0003D9][0x00624dc0-0x00624e84.ServerSelectMenuItemListVtableData](by-memory/0x00624dc0-0x00624e84.ServerSelectMenuItemListVtableData.md). UID0003D9 emits only a compiler-generation marker through this class.

### Complete authored method evidence

| Range | Source identity | SHA256 | Evidence and behavior |
| --- | --- | --- | --- |
| `0x5744a0-0x5744f8` | constructor | `33B52EB198759B733A68BA5F9FCF1CB47B23D1EF97A1A0524552F3ABA4D3CF8A` | Calls the ListPane constructor with row size 4 and constants 16/303/14, installs all three vptrs, and stores `m_owner`. |
| `0x574500-0x57450e` | `AddServerEntry` | `886AD26E93528F55E3566C3C759EFF70D8AF52AC1607E00E5E120F6D31BBA458` | Passes the address of the entry pointer to `ListPane::AddEntry`. |
| `0x574510-0x57454e` | `ApplySelectedServer` | `16EB3EFBB21760F6CA7894F0F99CF9B7867A5229C457FE803E4C6889D870650C` | Two `OnControlCommand` callers, selected-index guard, current `GetItem`, 16-wide-character config name copy, then member packet helper. |
| `0x574550-0x574561` | `SelectServerEntryIndex` | `561A9B169FC69F1118B225C80C6D232CBC9CD0356C16853EAA43880851B30233` | Calls the inherited item-selection virtual with `(index,0)`. |
| `0x574570-0x5745ac` | `ApplyServerEntry` | `BE5DEA2A3BB6610B5C72D6EC42D6256355BC73C5B40290BB6FCD3D0F928E240D` | Copies the name to application current-server state and calls the same member packet helper. |
| `0x5745b0-0x57465e` | private member `SendServerSelectPacket` | `E888F2CA0129A9D67D1E45111FDC3E84E8F649E22386A8B77BF28268386EDBB5` | Both callers carry the list instance in ECX; emits packet bytes `57 00 id`, dispatches exactly three bytes through the Socket receiver call `g_packetSender->QueueAndSendPacket(packet, 3)`, stores selected id, and conditionally formats endpoint state. |
| `0x574660-0x57466b` | virtual `OnItemActivated` | `0DC893A29B224721AF27EC45D6D8FEB036A65DD8964B43109FF3E6D6A588224D` | Primary slot `+0x7c`; loads `m_owner` and forwards to inherited protected owner activation. |
| `0x574670-0x574748` | virtual `DrawListEntry` | `2895FFC3C48C81351F93BF8D5EE7732DD7F709897374E9B8C6377D1BD0601B2A` | Primary slot `+0x80`; exact selected colors/fill/name write, right-edge EPF adjustment, 1024-wide-character `Name : Description` formatting and draw. |

Modeled `ApplySelectedServer` has two callers at `0x574399` and `0x5743db`. The member packet helper has callers at `0x574546` and raw `0x5745a1`. The two virtual methods have sole data xrefs at `0x624e40` and `0x624e44`.

### Frame, type, and source-shape evidence

- Report-time `ApplySelectedServer` frame was return-only; the behavior and ignored return support `void __thiscall(ServerSelectMenuItemList *)`.
- `SendServerSelectPacket` preserved locals `Src` byte at `+0xc`, destination byte at `+0xd`, a 14-byte tail at `+0xe`, `var_4` at `+0x1c`, saved registers at `+0x20`, and return address at `+0x24`. Source arguments are `unsigned int serverId` at `+0x28` and `const ServerSelectEntry *entry` at `+0x2c`. The 16-byte local packet is intentional even though only three bytes are sent.
- `OnItemActivated` is return-only and source-void. `DrawListEntry` preserves a two-byte `wchar_t` buffer start at `+0xc`, a four-byte local at `+0x80c`, saved/return rows at `+0x810/+0x814`, and arguments at `+0x818/+0x81c/+0x820`; its source virtual returns void.
- The formal source preserves exact constructor constants, capacities 16/64/256/1024, packet opcode and length, Socket receiver dispatch `g_packetSender->QueueAndSendPacket(packet, 3)`, selected-id write, alternate-endpoint flag, six-component endpoint format, four address bytes, signed interpretation of the 16-bit port for `%d`, virtual order, colors, fill, and right-edge mutation.
- The class declaration uses C++98-era `virtual` syntax, natural alignment, and source-facing names. It does not expose IDA addresses, `sub_` names, `_DWORD` placeholders, manual vptr stores, or raw ABI arrays.

### Raw-start and compiler-lowering disposition

- The constructor, AddServerEntry, SelectServerEntryIndex, and ApplyServerEntry starts have no modeled function, inbound start xref, rel32 route, or absolute VA/RVA pointer pattern. Those searches were repeated with positive controls against the modeled functions and table refs.
- Their bodies are nevertheless complete, source-shaped, and coherent with the live family; ApplyServerEntry calls the modeled packet helper. They remain documented and emitted as reconstructed methods, while the static-route gap caps confidence.
- Shared folded wrapper `[0x47e9d0,0x47ea0b)` and adjustors `[0x47e881,0x47e88c)` / `[0x47e88c,0x47e897)` are compiler-generated and table-shared. No explicit derived destructor is emitted because the class owns no resource teardown beyond virtual base destruction.

### Rejected historical assumptions

- Direct `SimpleListPane` inheritance is rejected by the exact RTTI graph.
- `DrawListItem` and top-edge subtraction are historical descriptive assumptions; the accepted slot name is `DrawListEntry`, and the body modifies `rowBounds->right`.
- A static/file-local packet helper is rejected by the ECX/member calling sequence. [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) independently proves that the sender is the ECX receiver, so the free-function-shaped `QueueAndSendPacket(g_packetSender, packet, 3)` form is rejected in favor of `g_packetSender->QueueAndSendPacket(packet, 3)`.
- `GetSelectedEntry` is superseded by the observed `GetItem(m_selectedIndex)` path.
- The old rule that uncertain private spellings or raw-start reachability required blank final C++ is rejected. Source names are inferred at high probability, while the negative evidence remains documented instead of leaking decompiler names into emitted source.

### Score rationale

- Completion `93` reflects complete formal CPP/H, direct inheritance, exact layout, all eight authored methods, three-view ABI cause, packet/draw behavior, compiler split, source placement, negative evidence, and rejected alternatives.
- Confidence `95` is justified by exact bytes/hashes, RTTI PMDs, vtable slots, constructor stores, callers, frames, and data flow. The only residual limits are original private spelling/access and the four raw-start static routes.

## Changes

- 2026-06-07 A008 alias cleanup: normalized the raw constructor's `byte_66DA97` layout branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `78`, confidence `76`.
- Evidence: the page documents active list behavior, owner/file grouping, by-memory range, confirmed virtual methods, entry layout, and helper relationship; confidence is limited by the projected constructor boundary.
- 2026-06-04: raised from `78/76` to `82/84`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md).
  - Summary/evidence: live IDA MCP confirms modeled virtual boundaries, the raw constructor-shaped byte range, vtable installs, vtable slot refs, owner-forwarding activation, row-entry name/description layout, selected-name display write, selected-helper relationship, and valid login parent placement.
  - Remaining gaps: final C++ remains blank because the raw constructor is still unmodeled and source-level names for the owner pointer, row-entry type, and selected-server display state are below the 95/95 threshold.
- 2026-06-12 A005 Batch267 direct-parent gate repair:
  - Before: `82/84`; parent was already `0000NO`, but stale text still cited the file parent as `84/80` and listed obsolete adjusted-vtable addresses.
  - Changed to: `85/88`; parent remains [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md).
  - Evidence: live IDA MCP reconfirmed the exact vtable child, constructor/list-building vtable-store triads, modeled virtual method slots, selected-server helper relationship, current file-parent score/path, and int-convert-verified constructor offsets/sizes. Final C++ remains blank because owner/entry/session field names are not final-source quality.
- 2026-06-22 B013 Rule 26 support sync:
  - Score unchanged at `85/88`.
  - Added `m_owner`, pointer-row layout, `ServerSelectEntry` field roles, raw add/select/apply helper names, current `g_pApplication + 0x858` display-state behavior, and the no-route policy for raw helper starts.
- 2026-08-15 B010 UID0003D9 accepted implementation callback:
  - Raised `85/88` to `93/95`, retained UID0000NO owner/emitter, and set position 30.
  - Installed the complete formal CPP/H, direct `ListPane` declaration, natural entry/class size guards, one constructor plus seven methods, owner field, and child expansion marker.
  - Incorporated exact hashes/ranges, frames, callers, three-view RTTI/layout proof, no-route evidence, compiler-wrapper disposition, packet/draw semantics, source rationale, score proof, and historical corrections at report depth.
