** TARGET-REPORT-UID:0001BQ **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001BQ ClientItemMenuItemList Source-Quality Research Report

Agent: B015  
Assignment: B015-report-0001BQ-ClientItemMenuItemList-source-quality-20260627  
Amendment assignment: B015-rework-report-0001BQ-client-item-menu-item-list-20260627  
Mode: rejected report amendment; amend existing report only  
Target: [UID:0001BQ] `by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md`  
Report path: `tools/leaser/Agents/Agent-B015/research/0001BQ-ClientItemMenuItemList-source-quality.md`

## Finalized Report / Current Recommendation

The assignment-time queue entry is stale. The research tracker row used for assignment recorded [UID:0001BQ] at `82/84`, reconstructable, and report count `0`, but the target source page now carries `COMPLETION:88`, `CONFIDENCE:89`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KF`, and a nonblank formal C++ block.

The remaining source-quality issue is not "blank C++". The fresh MCP-backed reanalysis shows that the page has enough evidence for an 88/89 reconstructable item-menu-list method cluster, but the target metadata should be narrowed and the formal C++ should be replaced with the exact first-draft formal block supplied in this amendment:

- Recommended canonical owner: change `CANONICAL_OWNER` from [UID:0000KF] `ItemMenuDialogs` to [UID:00002Q] `ClientItemMenuItemList`.
- Recommended emitter/source file: keep `EMITTER_UIDS:0000KF` and generated placement under `NexusTK/ui/dialogs/ItemMenuDialogs.cpp`.
- Recommended score: keep `COMPLETION:88`, `CONFIDENCE:89`.
- Recommended code disposition: keep `RECONSTRUCTABLE:TRUE` and replace the target's formal `RECONSTRUCTION_CPP CODE` block with the exact block in `First-Draft C++ Recommendation`. Caveat-only retention is not recommended because the current block overstates behavior in `AppendAction`, `SendSelectedAction`, `SendAction`, and the packet-send length handling.

No target or support by-* page was edited in this report-only pass.

## MCP Availability And Session

Live IDA MCP was available and used for the original report and for this rejected-report amendment. The amendment started with JSON-RPC `initialize`, `tools/list`, and `idb_list` as required. `initialize` returned server `ida-pro-mcp` version `1.0.0` using protocol `2025-06-18`.

The active IDB session used for the amendment was:

- `session_id`: `b001_000241_20260627`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- input path reported by health check: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- module: `NexusTK.exe`
- imagebase: `0x400000`
- `auto_analysis_ready`: true
- `hexrays_ready`: true
- `strings_cache_ready`: true
- `strings_cache_size`: 2067
- `idb_list` returned one active worker/adopted session, PID/worker PID `23132`, `is_analyzing:false`

The earlier report session `875bf182` is stale and is not used as current proof. Current tool schemas require a `database` argument on IDB-backed calls, `disasm`/`decompile` use `addr`, `xrefs_to` uses `addrs`, and `get_bytes` uses `regions`. The amendment rechecked the listed C++ exactness concerns with `lookup_funcs`, `xrefs_to`, `disasm`, `get_bytes`, and `server_health` on session `b001_000241_20260627`.

## Supporting Research

Documents and generated inputs checked:

- Target: `by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md`
- Class support: `by-class/ClientItemMenuItemList.md`
- File support: `by-file/ItemMenuDialogs.md`
- Caller/sibling support: `by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md`
- Vtable support: `by-type/by-vtable/ItemMenuDialogVtables.md`
- Shared destructor support:
  - `by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md`
  - `by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md`
- Source-tree support: `by-project-structure/proposed-source-tree.md`
- Guidance: `by-memory/-guidance.md`, `by-structure.md`
- Assignment queue/generated state:
  - `auto-generated/-ag-research-tracker.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/-ag-coverage-report-by-memory.md`
  - `auto-generated/NexusTK/ui/dialogs/ItemMenuDialogs.cpp`
- Prior B-agent reports:
  - `executed-b-agent-research/B002/0001BO-ItemMenuDialogs-source-quality.md`
  - `executed-b-agent-research/B013/00002P-ClientItemMenuDialog-class-source-quality.md`
  - `executed-b-agent-research/B001/0001C1-SharedListPaneScalarDeletingDestructor-source-quality.md`
  - `executed-b-agent-research/B002/0001BP-ServerItemMenuItemList-source-quality.md`

IDA MCP operations used included `lookup_funcs`, `disasm`, `decompile`, `xrefs_to`, `callees`, `get_bytes`, `idb_list`, and `server_health`.

## Current Target State

The target currently documents range `0x0051c470-0x0051ca3c` as `ClientItemMenuItemList`, with these source fields:

- `COMPLETION:88`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000KF`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KF`

The formal C++ block is nonblank. It currently defines `ClientItemMenuEntry`, the `ClientItemMenuItemList` constructor, `AppendAction`, `SendSelectedAction`, `SendAction`, `NotifyOwnerItemActivated`, and `DrawListEntry`.

The target item summary still contains stale language saying final C++ was blocked by raw helper modeling and row-record/packet-helper field names. That blocker is no longer accurate after the B002/B013 incorporations and this MCP recheck.

## Supervisor Active Recheck

The target state changed after the assignment queue row was produced. The tracker and some generated reports still show the older `82/84` state, but the source page and generated `ItemMenuDialogs.cpp` now include C++ for [UID:0001BQ].

This is a source-page/generation synchronization problem, not evidence that [UID:0001BQ] is still uncovered. The implementation callback should update source docs first, then run scoped validators with generated-output refresh. B015 should not hand-edit generated reports or any `-coverage-report.md` file.

## Heuristic / Inference Reanalysis And Validation

The current project rule in `by-structure.md` says `CANONICAL_OWNER` should be the narrowest true semantic owner, while `EMITTER_UIDS` routes generated output. Applying that rule:

- [UID:0001BQ] is a `ClientItemMenuItemList` method/raw-helper cluster.
- The class owner [UID:00002Q] already exists, has `88/89`, is reconstructable, and routes to [UID:0000KF].
- [UID:0000KF] `ItemMenuDialogs` remains the correct source file/emitter, but it is a broader file-level owner than the class.

The best reanalysis is therefore `CANONICAL_OWNER:00002Q`, `EMITTER_UIDS:0000KF`. This is a metadata correction, not a source-placement change.

The reconstructed-code gate is still satisfied: `(88 + 89) / 2 = 88.5`, `RECONSTRUCTABLE:TRUE`, and a valid emitter route exists. The score should not be raised above 88/89 until formal C++ behavior is made closer to the raw helper bodies and the generated stale entries are refreshed.

## Evidence Standards Used

Direct MCP evidence was weighted above prior B-agent reports and generated summaries. Prior reports were used as historical context and to identify already-incorporated findings, but live MCP disassembly/decompilation/xrefs were used for the final facts in this report.

Generated C++ and generated coverage artifacts were treated as outputs, not authoritative source state. The source by-* documents are authoritative for implementation edits.

## Positive Evidence Summary

- The range is a tight client item-menu-list island bounded by `0xcc` padding and followed by the next function at `0x0051ca40`.
- The constructor at `0x0051c470` writes the three `ClientItemMenuItemList` vtable pointers and stores the four constructor fields used by the send and owner-notify paths.
- The raw helper at `0x0051c4e0` builds a `0x206` byte row with action id, item id, item style, and `wchar_t name[256]`.
- The raw helpers at `0x0051c550` and `0x0051c610` build the opcode `0x39` item-action packet with exact 9-byte send length.
- The virtual at `0x0051c6b0` forwards the owner pointer at `this+0x158` to shared item-state logic at `loc_49DE70`.
- The draw virtual at `0x0051c6c0` reads the documented row fields at offsets `+2`, `+4`, and `+6` and draws current/legacy item imagery plus truncated row text.
- Constructor xrefs come from the client item-menu dialog constructor range, not from unrelated file families.
- Vtable slots point directly at the activation and draw virtuals, while destructor slots point at shared compiler-generated glue already covered by support docs.
- File/class support pages already place this cluster under `NexusTK/ui/dialogs/ItemMenuDialogs.cpp`.

## IDA MCP Facts

### Function And Raw Helper Inventory

`lookup_funcs` and raw disassembly establish this inventory:

| Address | MCP result | Evidence disposition |
| --- | --- | --- |
| `0x0051c470` | `sub_51C470`, size `0x6c` | Constructor. Initializes ListPane base, fields, and vtables. |
| `0x0051c4e0` | not an IDA function | Raw append helper. Builds one row record and calls the list append helper. |
| `0x0051c550` | not an IDA function | Raw selected-action packet helper. Sends opcode `0x39` for selected row action. |
| `0x0051c610` | not an IDA function | Raw explicit-action packet helper. Sends opcode `0x39` with caller-supplied action byte. |
| `0x0051c6b0` | `sub_51C6B0`, size `0xb` | Virtual/thunk that forwards `this+0x158` to `loc_49DE70`. |
| `0x0051c6c0` | `sub_51C6C0`, size `0x37c` | Draw virtual. |
| `0x0051ca40` | `sub_51CA40`, size `0xada` | Successor outside this target. |

The raw helper starts are not IDA function objects, but their bodies disassemble cleanly and are bracketed by returns and `0xcc` padding. They are source-authored method bodies retained in the class island rather than separate ownership candidates.

### Constructor Evidence

`disasm 0x0051c470` and `decompile 0x0051c470` show:

- Base/list constructor call receives `0x206`, `0x10`, `0xe4`, `0x18`, zeros, and two `1` flags.
- Fields:
  - `[this+0x14c]` receives the byte constructor argument.
  - `[this+0x150]` receives the dword constructor argument.
  - `[this+0x154]` receives the word constructor argument.
  - `[this+0x158]` receives the owner/context pointer argument.
- Vtables:
  - `[this] = 0x0061f0a4`
  - `[this+0xa0] = 0x0061f12c`
  - `[this+0xa4] = 0x0061f15c`
- Return is `retn 10h`, matching four explicit arguments.

This supports the current constructor modeling and the `0x206` row-size evidence.

### Append Helper Evidence

`disasm 0x0051c4e0` shows a raw helper that:

- Reserves a `0x20c` stack scratch area.
- Writes the action id argument to row offset `+0`.
- Writes the item id argument to row offset `+2`.
- Writes the item style argument to row offset `+4`.
- Calls `_wcscpy_s` with destination row offset `+6`, count `0x100`, and the name pointer argument.
- Calls `sub_4F3C50` with the row pointer.
- Returns with `retn 10h`.

This validates the documented row layout:

```cpp
struct ClientItemMenuEntry {
    unsigned char actionId;
    unsigned char reserved;
    unsigned short itemId;
    unsigned char itemStyle;
    unsigned char reserved2;
    wchar_t name[256];
};
```

Negative exactness note: the raw helper passes the name pointer directly to `_wcscpy_s`. The current formal C++ adds `name != NULL ? name : L""`; that may be a defensible source-level guard, but it is not shown in the raw body.

### Selected Action Packet Evidence

`disasm 0x0051c550` shows:

- Reads selected index from `[this+0x134]`.
- If selected index is negative, returns without sending.
- Calls `sub_4F3DC0` with the selected index and reads the row action byte at row offset `+0`.
- Writes packet:
  - opcode byte `0x39`
  - subtype byte from `[this+0x14c]`
  - dword from `[this+0x150]`
  - word from `[this+0x154]`
  - selected row action byte
- Writes a local zero at the next scratch byte, but sends length `9` through `sub_574BB0` / `QueueAndSendPacket` using `dword_67A7EC` / `g_packetSender`.
- Returns normally, with no meaningful boolean return value.

This validates B013's correction: the local zero byte after the action byte is outside the sent 9-byte packet. The packet does not include a trailing null.

Negative exactness note: the current formal C++ returns `bool`, checks `m_selectedIndex >= GetItemCount()`, checks `entry == NULL`, and returns the result of `SendAction`. Those extra checks/returns are not present in the raw selected-action helper.

### Explicit Action Packet Evidence

`disasm 0x0051c610` shows the same packet shell as the selected-action helper, but the final action byte comes from the explicit action argument:

- opcode `0x39`
- subtype `[this+0x14c]`
- dword `[this+0x150]`
- word `[this+0x154]`
- caller-supplied action byte
- local-only zero byte after the sent payload
- `QueueAndSendPacket(..., 9)`
- `retn 4`

Negative exactness note: the current formal C++ returns `bool` and calls `SendGamePacket(packet)` without an explicit byte length in the visible formal body. The raw helper sends exactly 9 bytes through the queue/send helper.

### Activation Virtual Evidence

`disasm 0x0051c6b0` shows:

- `mov ecx, [ecx+158h]`
- direct jump to `loc_49DE70`

The decompiler expands the target shared helper into a larger body, but the direct fact for this target is the short thunk. This supports modeling the target method as notifying or updating the owner/context object stored at `this+0x158`, not as owning the shared item-state logic at `loc_49DE70`.

### Draw Virtual Evidence

`disasm/decompile 0x0051c6c0` show a large draw virtual with these source-relevant facts:

- Stack scratch size about `0x248`.
- Reads selected state through `sub_4F3F00` and applies selected visual state through `sub_4B9660`, `unk_69B3FC`, and `sub_4B9680`.
- Branches on `byte_66DA97`, matching current-vs-legacy asset handling.
- Reads row item id at `row+2`, item style at `row+4`, and name at `row+6`.
- Current branch uses `sub_4DF2C0`; legacy branch uses `sub_4DEE50`; both use the resource/image context at `dword_67A758`.
- Copies the row name with `_wcscpy_s(dest, 0x100, (wchar_t *)(row+6))`.
- Uses the `L"..."` literal at `0x0061066c` and `sub_4BA820` before drawing text through `sub_4BAD70`.
- Writes `byte [this+0x88] = 1`.

This supports the existing high-level draw reconstruction, but final helper names remain source-facing approximations rather than exact recovered symbols.

### Xrefs And Vtables

`xrefs_to` confirms:

- `0x0051c470` has code xrefs at `0x0051ba35` and `0x0051bf64`, both inside `sub_51B880` / `ClientItemMenuDialogMethods`.
- Raw starts `0x0051c4e0`, `0x0051c550`, and `0x0051c610` have no direct xrefs. This is expected for raw, non-function method bodies reached through local/control-flow layout rather than named direct calls in IDA.
- `0x0051c6b0` has one vtable data xref from `0x0061f120`.
- `0x0051c6c0` has one vtable data xref from `0x0061f124`.
- Vtable addresses `0x0061f0a4`, `0x0061f12c`, and `0x0061f15c` are written by the constructor.
- Shared destructor `0x00520c20` is referenced by primary item/spell list vtables and by secondary/tertiary destructor thunks.
- Thunks `0x00520ad1` and `0x00520adc` are referenced by secondary/tertiary vtable slots and are shared compiler-generated glue.

`get_bytes` at the vtables confirms:

- `0x0061f0a4` starts with little-endian `0x00520c20`, and later slots include `0x0051c6b0` and `0x0051c6c0`.
- `0x0061f12c` starts with `0x00520ad1`.
- `0x0061f15c` starts with `0x00520adc`.

### Range And Padding

`get_bytes` confirms clean boundaries:

- `0x0051c46d` has `0xcc 0xcc 0xcc` before the constructor.
- `0x0051c4dc` has `0xcc 0xcc 0xcc 0xcc` after the constructor.
- `0x0051c548` begins with `10 00` for the append helper `retn 10h`, then padding before `0x0051c550`.
- `0x0051c603` through the next start is padding.
- `0x0051c6ac` begins with `04 00` for the explicit helper `retn 4`, then padding, then the activation thunk bytes at `0x0051c6b0`.
- `0x0051ca3c` is followed by `0xcc` padding before successor function `0x0051ca40`.

The page range is therefore source-tight. No split is recommended.

## Documentation Evidence And IDA Status

The local documentation mostly matches the live IDA facts:

- `by-class/ClientItemMenuItemList.md` already records `88/89`, reconstructable true, and emitter `0000KF`.
- `by-file/ItemMenuDialogs.md` records `88/89`, proposed path `NexusTK/ui/dialogs/`, and includes `ClientItemMenuItemList` in `ItemMenuDialogs.cpp`.
- `by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md` directly constructs `ClientItemMenuItemList` and calls the append helper.
- `by-type/by-vtable/ItemMenuDialogVtables.md` records the three `ClientItemMenuItemList` vtables and the shared destructor/thunk layout.
- The shared destructor pages correctly keep destructor glue out of [UID:0001BQ]'s source ownership.

The stale pieces are:

- The target item summary still mentions a final-C++ blocker.
- Generated `auto-generated/-ag-research-tracker.md` still lists the assignment-time `82/84`, report count `0`.
- Generated `auto-generated/-ag-coverage-report-by-memory.md` still shows stale summary text and an `emits_code:false` state.
- Generated `auto-generated/NexusTK/ui/dialogs/ItemMenuDialogs.cpp` contains [UID:0001BQ] C++, but the generated comments still show `82/84` in places.

These generated artifacts should be refreshed by validator/generator flow after source edits. They should not be hand-edited.

## Ranked Ownership Analysis

1. [UID:00002Q] `ClientItemMenuItemList` as canonical owner. This is the best fit. The target is a cluster of constructor/raw methods/virtuals for that exact class, and the support class page already exists at high score with the same emitter route.
2. [UID:0000KF] `ItemMenuDialogs` as emitter/source file. This is the correct generated file and source-placement parent, but too broad for the canonical owner under current `by-structure.md` guidance.
3. [UID:00002P] `ClientItemMenuDialog`. Rejected as canonical owner. It constructs and populates the list, but the target methods operate on `ClientItemMenuItemList` state and vtables.
4. ListPane/base-list owner. Rejected. The constructor and helpers call ListPane routines, but row shape, packet action semantics, and item-menu draw behavior are derived-class code.
5. PacketBuffer/Socket/`g_packetSender`. Rejected. These are outbound packet dependencies, not feature ownership.
6. Shared destructor pages. Rejected. Destructor entries are compiler-generated vtable glue shared with other list classes.
7. `CANONICAL_OWNER:NONE`, multi-owner, or new source file. Rejected. The class and file route are already known.

Recommended metadata:

```text
CANONICAL_OWNER:00002Q
EMITTER_UIDS:0000KF
```

## Source Placement

Keep source placement under [UID:0000KF] `ItemMenuDialogs`, generated as:

```text
NexusTK/ui/dialogs/ItemMenuDialogs.cpp
```

No new file is supported. `proposed-source-tree.md`, `by-file/ItemMenuDialogs.md`, sibling server/client item-menu pages, and direct constructor/caller evidence all support the current file placement.

## Range / Split / Reclassification Analysis

No split is recommended.

The raw helper starts at `0x0051c4e0`, `0x0051c550`, and `0x0051c610` are not IDA function objects and have no direct xrefs, but their disassembly is source-shaped, internally bounded, and tightly adjacent to the constructor and virtuals for the same class. Splitting them into separate by-memory pages would make ownership worse because they are method bodies for the same class row/packet behavior.

The destructor thunks and shared scalar deleting destructor should remain in their existing support pages and not be merged into [UID:0001BQ].

## Negative Evidence Summary

- No MCP evidence supports keeping [UID:0000KF] as the canonical owner instead of the narrower class [UID:00002Q].
- No direct xrefs target the three raw helper starts, so their liveness is structural/class-island evidence rather than caller-list evidence.
- No MCP evidence supports a trailing null in the sent selected/explicit action packet. The local zero exists but send length is `9`.
- No raw selected-action evidence supports a `>= GetItemCount()` guard or null-entry guard before sending. The binary checks only for a negative selected index before retrieving the selected row.
- No raw explicit-action evidence supports a boolean source return.
- No raw append evidence supports the current null-name fallback in formal C++.
- No evidence supports moving this cluster to `ProtocolSend`, `Socket`, `ListPane`, `ClientItemMenuDialog`, or a new source file.
- Generated reports are stale relative to source docs; do not treat the stale generated `82/84` row as current source truth.

## IDA Rename / Type / Comment Recommendations

No IDA database edits were performed. If the supervisor authorizes a future IDA rename/type/comment pass, these source-facing names are supported by the evidence:

- `0x0051c4e0`: `ClientItemMenuItemList::AppendAction`
- `0x0051c550`: `ClientItemMenuItemList::SendSelectedAction`
- `0x0051c610`: `ClientItemMenuItemList::SendAction`
- Row type: `ClientItemMenuEntry`
- Field names:
  - `actionId`
  - `itemId`
  - `itemStyle`
  - `name[256]`
- Class fields:
  - `m_packetSubtype` at `+0x14c`
  - `m_menuObjectId` at `+0x150`
  - `m_menuOptionId` at `+0x154`
  - `m_owner` or equivalent owner/context pointer at `+0x158`

Keep helper names such as image draw helpers, list-base helpers, and packet writer helpers as source-facing approximations unless a later header/source recovery supplies exact names.

## First-Draft C++ Recommendation

The target is not a no-code page. It already emits formal C++ and should remain `RECONSTRUCTABLE:TRUE`.

The implementation-ready outcome is exact formal C++ replacement, not caveat-only retention. Replace the entire current [UID:0001BQ] formal multiline `RECONSTRUCTION_CPP CODE:BEGIN/END` body with this block:

```cpp
struct ClientItemMenuEntry
{
    unsigned char actionId;
    unsigned char reserved;
    unsigned short itemId;
    unsigned char itemStyle;
    unsigned char reserved2;
    wchar_t name[256];
};

ClientItemMenuItemList::ClientItemMenuItemList(
    unsigned char packetSubtype,
    unsigned int menuObjectId,
    unsigned short menuOptionId,
    ClientItemMenuDialog* owner)
    : ListPane(sizeof(ClientItemMenuEntry), 0x10, 0xe4, 0x18, 0, true, true),
      m_packetSubtype(packetSubtype),
      m_menuObjectId(menuObjectId),
      m_menuOptionId(menuOptionId),
      m_owner(owner)
{
}

void ClientItemMenuItemList::AppendAction(
    unsigned char actionId,
    unsigned short itemId,
    unsigned char itemStyle,
    const wchar_t* name)
{
    ClientItemMenuEntry entry;

    entry.actionId = actionId;
    entry.itemId = itemId;
    entry.itemStyle = itemStyle;
    wcscpy_s(entry.name, _countof(entry.name), name);

    AddEntry(&entry);
}

void ClientItemMenuItemList::SendSelectedAction()
{
    int selectedIndex = m_selectedIndex;
    if (selectedIndex < 0)
        return;

    ClientItemMenuEntry* entry = static_cast<ClientItemMenuEntry*>(GetEntry(selectedIndex));

    unsigned char packet[0x204];
    PacketBufferWriteUInt8(packet + 0, 0x39);
    PacketBufferWriteUInt8(packet + 1, m_packetSubtype);
    PacketBufferWriteUInt32BE(packet + 2, m_menuObjectId);
    PacketBufferWriteUInt16BE(packet + 6, m_menuOptionId);
    PacketBufferWriteUInt8(packet + 8, entry->actionId);
    packet[9] = 0;

    g_packetSender->QueueAndSendPacket(packet, 9);
}

void ClientItemMenuItemList::SendAction(unsigned char actionId)
{
    unsigned char packet[0x204];
    PacketBufferWriteUInt8(packet + 0, 0x39);
    PacketBufferWriteUInt8(packet + 1, m_packetSubtype);
    PacketBufferWriteUInt32BE(packet + 2, m_menuObjectId);
    PacketBufferWriteUInt16BE(packet + 6, m_menuOptionId);
    PacketBufferWriteUInt8(packet + 8, actionId);
    packet[9] = 0;

    g_packetSender->QueueAndSendPacket(packet, 9);
}

void ClientItemMenuItemList::NotifyOwnerItemActivated()
{
    m_owner->UpdateActionButtonState();
}

void ClientItemMenuItemList::DrawListEntry(
    DrawContext* dc,
    int index,
    const Rect& bounds,
    unsigned int state)
{
    ClientItemMenuEntry* entry = static_cast<ClientItemMenuEntry*>(GetEntry(index));
    if (entry == NULL)
        return;

    const bool selected = IsItemSelected(index);
    if (selected)
        dc->FillSelectedListRow(bounds);

    Rect iconRect = bounds;
    Rect nameRect = bounds;

    if (g_useEpfAssets) {
        iconRect.left += 12;
        iconRect.right = iconRect.left + 28;
        nameRect.left += 50;
        nameRect.right -= 30;
        DrawItemIconScaled(dc, entry->itemId, entry->itemStyle, iconRect);
    } else {
        iconRect.left += 12;
        iconRect.right = iconRect.left + 32;
        nameRect.left += 50;
        nameRect.right -= 2;
        DrawItemIcon(dc, entry->itemId, entry->itemStyle, iconRect);
    }

    wchar_t fittedName[256];
    wcscpy_s(fittedName, _countof(fittedName), entry->name);
    FitWideTextWithEllipsis(dc, fittedName, nameRect.Width());
    dc->DrawText(nameRect, fittedName, selected ? kSelectedTextColor : kNormalTextColor);
}
```

Evidence for this exact replacement:

- `AppendAction`: current MCP disassembly reserves stack scratch at `0x0051c4e3`, writes only the observed row fields, moves the fourth argument directly into `edx` at `0x0051c4f6`, pushes it at `0x0051c510`, and calls `_wcscpy_s` at `0x0051c523` with destination `entry.name` and count `0x100`. There is no memset/aggregate zero-initialization, null-name test, or fallback literal; the replacement uses an uninitialized local row object and removes `name != NULL ? name : L""`.
- `SendSelectedAction`: current MCP disassembly at `0x0051c566-0x0051c56e` reads `m_selectedIndex` and branches out only when it is negative. It then calls the list entry fetch helper at `0x0051c576` and reads the action byte with `mov bl, [eax]` at `0x0051c57b`. There is no upper-bound selected-index guard, no null-entry guard, no meaningful bool return, and no call to `0x0051c610`; the replacement uses `void`, preserves only the negative-index return, and duplicates the packet build.
- `SendAction`: current MCP disassembly at `0x0051c610-0x0051c6ab` builds and sends the packet, then returns with `retn 4`. There is no meaningful bool return; the replacement uses `void`.
- Packet length and terminator: current MCP disassembly writes opcode `0x39`, subtype, dword object/menu id, word option id, and action byte, writes a zero at packet offset `9` (`0x0051c5e4` / `0x0051c68e`), then pushes `9` before `QueueAndSendPacket` (`0x0051c5eb` / `0x0051c695`). The replacement keeps `packet[9] = 0` as local scratch and sends exactly length `9`, so the terminator is not protocol payload.

## Score And Metadata Recommendation

Recommended source header after callback:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:00002Q
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000KF
```

Do not increase above 88/89 in the same callback. The amendment supplies exact replacement C++ for the listed helper exactness issues, but the three helper starts remain raw/non-IDA functions, exact original helper spellings remain inferred, and generated outputs still need a clean validator refresh after source-doc edits.

Rationale for not decreasing:

- Live MCP validates range, row shape, packet layout, vtables, caller/source placement, and dependencies.
- Formal C++ remains appropriate for reconstructable source output once the replacement block in this report is applied.
- The remaining issues are precision/source-spelling limits, not ownership blockers.

Rationale for not increasing:

- Three source-shaped helper starts remain non-IDA functions with no direct xrefs.
- Exact original helper/function names are not recovered.
- Until implementation applies this amendment, the visible target formal C++ still contains behavior not shown in the raw binary.
- Generated reports/comments are stale and need validator refresh.

## Recommended Target Doc Changes

During implementation callback only:

- Change [UID:0001BQ] `CANONICAL_OWNER` from `0000KF` to `00002Q`.
- Keep `EMITTER_UIDS:0000KF`.
- Keep `COMPLETION:88`, `CONFIDENCE:89`, and `RECONSTRUCTABLE:TRUE`.
- Update the item summary to remove the stale "final C++ blocked" language.
- Add the fresh MCP evidence for:
  - constructor field/vtable stores,
  - append row layout,
  - selected/explicit packet length `9`,
  - local-only terminator after the action byte,
  - activation thunk shape,
  - draw virtual row-field reads,
  - exact padding/range evidence.
- Replace the entire formal C++ multiline block with the exact replacement block in this report's `First-Draft C++ Recommendation`.
- Add this exact target-doc caveat near the C++/behavior discussion:

```text
First-draft C++ caveat: helper, draw-support, UI/control, and packet-writer names remain source-facing inferred names until recovered headers/source spellings prove exact identifiers. The formal C++ block is nevertheless amended to match the raw helper behavior for the current exactness concerns: `AppendAction` uses an uninitialized local row object and passes the caller's `name` pointer directly to `_wcscpy_s`; `SendSelectedAction` returns `void`, only checks for a negative selected index, fetches the row without an upper-bound/null-entry guard, and duplicates the packet build; `SendAction` returns `void`; both action send paths write a local scratch zero after the action byte and call `QueueAndSendPacket(..., 9)`, so that zero is not sent as protocol payload.
```

## Recommended Support Doc Changes

During implementation callback only:

- `by-class/ClientItemMenuItemList.md`: add this exact support-sync note under `Changes` or the nearest source-quality/status section:

```text
- 2026-06-27 B015 rejected-report amendment support sync: [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md) is the canonical owner for the client item-menu list method/raw-helper cluster, while [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) remains the generated emitter/source file route. Current MCP session `b001_000241_20260627` rechecked the formal C++ exactness issues: `AppendAction` passes the name pointer directly to `_wcscpy_s` with no null fallback; `SendSelectedAction` returns `void`, checks only negative selected index before fetching the row, has no upper-bound/null-entry guard, and duplicates the packet build; `SendAction` returns `void`; both send helpers write a local-only zero after the action byte and call `QueueAndSendPacket(..., 9)`.
```

- `by-file/ItemMenuDialogs.md`: add this exact support-sync note under `Rule 26 Source-Quality Notes`, `Ownership Notes`, or the nearest item-menu child-routing section:

```text
- 2026-06-27 B015 rejected-report amendment support sync for [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md): keep this child emitted through `NexusTK/ui/dialogs/ItemMenuDialogs.cpp`, but treat [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md) as the canonical semantic owner. The formal C++ replacement preserves item-menu file routing while removing raw-helper overclaims: no `AppendAction` null-name fallback, no boolean selected/explicit send return, no selected upper-bound/null-entry guard, and no sent terminator byte beyond the explicit `QueueAndSendPacket(..., 9)` length.
```

- `by-type/by-vtable/ItemMenuDialogVtables.md`: no required score/metadata change. Optional note only if the callback wants to cite the verified vtable slots `0x0061f120` and `0x0061f124`.
- Shared destructor support docs: no change required.

## Open Questions With Attempted Resolution

1. Are the raw helpers real source methods despite not being IDA functions?

Resolution: yes for source-quality purposes. They have coherent bodies, proper returns, internal padding, adjacency to the constructor/virtuals, and row/packet behavior specific to the same class. This is enough to keep them inside [UID:0001BQ].

2. Should `ItemMenuDialogs` remain canonical owner because it is the generated file?

Resolution: no. Current project guidance separates canonical ownership from emitter routing. The class is the narrowest semantic owner; the file remains the emitter.

3. Should the page be split around `0x0051c4e0`, `0x0051c550`, or `0x0051c610`?

Resolution: no. Splitting would create no-owner raw helpers for methods that are clearly part of the same list class and source island.

4. Is the packet action send 9 bytes or 10 bytes with a trailing zero?

Resolution: 9 bytes. MCP disassembly shows a local zero after the action byte, but the send length argument is `9`. The zero is local scratch/terminator only.

5. Is the current generated tracker state authoritative?

Resolution: no. It is stale relative to source docs and generated `ItemMenuDialogs.cpp`. Refresh through validator/generator flow after source edits.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage or tracker text is recommended. This target does not need a manual override. Let the validator regenerate `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, generated source comments, and generated coverage summaries from the updated by-* source docs.

## Follow-Up Actions

Recommended validator flow after implementation callback edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001BQ-ClientItemMenuItemList-source-quality-removed.md](0001BQ-ClientItemMenuItemList-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Adjust the support-doc validator list if the callback edits fewer support docs.

## Validator Results

Implementation callback validator batch, run from `source-3/project-documentation` after the accepted by-* edits:

| Target | Command | command_id | command_timestamp | Exit | Result |
| --- | --- | --- | --- | ---: | --- |
| `by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md` | `python .\tools\validator.py --mode file --file by-memory\0x0051c470-0x0051ca3c.ClientItemMenuItemList.md --apply --queue-timeout 240 --wait-generated` | `000000004770` | `2026-06-27T23:14:15-04:00` | `0` | `ok: 1`; `canonical_owner_update 0001BQ ... 00002Q`; `completion_update 88`; `confidence_update 89`; `generated_refresh: completed`; `generated_refresh_command_id: 000000004770`. |
| `by-class/ClientItemMenuItemList.md` | `python .\tools\validator.py --mode file --file by-class\ClientItemMenuItemList.md --apply --queue-timeout 240 --wait-generated` | `000000004775` | `2026-06-27T23:14:43-04:00` | `0` | `ok: 1`; `completion_update 00002Q ... 88`; `confidence_update ... 89`; `canonical_owner_update 00002Q ... 0000KF`; `generated_refresh: completed`; `generated_refresh_command_id: 000000004775`. Nonfatal existing validator note: `missing_ref_uid 00040E`. |
| `by-file/ItemMenuDialogs.md` | `python .\tools\validator.py --mode file --file by-file\ItemMenuDialogs.md --apply --queue-timeout 240 --wait-generated` | `000000004779` | `2026-06-27T23:15:01-04:00` | `0` | `ok: 1`; `completion_update 0000KF ... 88`; `confidence_update ... 89`; `canonical_owner_update 0000KF ... FILE`; `generated_refresh: completed`; `generated_refresh_command_id: 000000004779`. Nonfatal existing validator notes: `missing_ref_uid 00040D`, `00040E`, and `0003U9`. |

Post-edit proof:

- MCP availability was rechecked before implementation: session `b001_000241_20260627`, `server_health` `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- Leases were taken for `by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md`, `by-class/ClientItemMenuItemList.md`, and `by-file/ItemMenuDialogs.md`, then released immediately after the validator batch; post-release `current_leases.md` scan showed no `Agent-B015`/target/support-file matches.
- Target scan after validation confirms `CANONICAL_OWNER:00002Q`, `EMITTER_UIDS:0000KF`, `COMPLETION:88`, `CONFIDENCE:89`, `RECONSTRUCTABLE:TRUE`, inline `RECONSTRUCTION_CPP CODE:[[[]]]` remains blank, the formal C++ block contains `void SendSelectedAction`, direct `_wcscpy_s(..., name)`, and `QueueAndSendPacket(packet, 9)`, and no old `bool Send*`, null-fallback, upper-bound selected guard, `PacketBuffer packet`, `SendGamePacket`, or stale "final C++ blocked" wording remains.
- Optional `by-type/by-vtable/ItemMenuDialogVtables.md` was explicitly excluded from this implementation batch: the accepted details required no additional vtable-doc text beyond the target/class/file support notes, and no optional vtable-specific validator was needed.
- Generated reports/generated C++/project-level/tool-state changes were not manually edited by B015; any such diffs are validator-owned side effects from the required `--apply --wait-generated` commands above.

## Changed Files

Manual by-* implementation edits:

```text
by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md
by-class/ClientItemMenuItemList.md
by-file/ItemMenuDialogs.md
```

Manual report tracking update:

```text
tools/leaser/Agents/Agent-B015/research/0001BQ-ClientItemMenuItemList-source-quality.md
```

Not manually edited: generated reports, generated C++ files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, leases, or IDA DB.

## Implementation Tracking Checklist

- [x] Supervisor validates this B015 report. Proof: supervisor accepted this report for implementation in the 2026-06-27 implementation callback.
- [x] Implementation callback authorizes by-* source edits. Proof: callback explicitly authorized target/support by-* edits for [UID:0001BQ].
- [x] Update [UID:0001BQ] metadata to `CANONICAL_OWNER:00002Q`, keeping `EMITTER_UIDS:0000KF`, `88/89`, and `RECONSTRUCTABLE:TRUE`. Proof: post-validation target scan confirms those header values, and validator command `000000004770` reported `canonical_owner_update 0001BQ ... 00002Q`.
- [x] Remove stale target summary wording that says final C++ is blocked by raw helper modeling/field names. Proof: post-validation scan finds no `final C++ blocked` string in the target/support files.
- [x] Add fresh MCP evidence for constructor, append, selected send, explicit send, activation thunk, draw virtual, vtables, xrefs, and padding. Proof: target `Evidence` section now records 2026-06-27 B015 session `b001_000241_20260627` evidence covering those items.
- [x] Replace [UID:0001BQ]'s entire formal multiline `RECONSTRUCTION_CPP CODE:BEGIN/END` body with the exact replacement block in this report's `First-Draft C++ Recommendation`; keep the inline `RECONSTRUCTION_CPP CODE:[[[]]]` value blank. Proof: normalized block comparison matched the accepted replacement exactly and post-validation scan confirms inline C++ remains blank.
- [x] Add the exact first-draft C++ caveat text from `Recommended Target Doc Changes`, preserving the raw-behavior decisions: direct `_wcscpy_s` name pointer, `void` send helpers, selected negative-index-only guard, duplicated packet build, local-only `packet[9] = 0`, and explicit send length `9`. Proof: target `Generated Data Caveats` contains the exact accepted caveat text.
- [x] Add the exact support-sync notes from `Recommended Support Doc Changes` to `by-class/ClientItemMenuItemList.md` and `by-file/ItemMenuDialogs.md`, unless the implementation callback verifies the same facts are already present at equal-or-greater detail. Proof: both support docs now contain the 2026-06-27 B015 support-sync notes verbatim.
- [x] Run scoped validators with `--wait-generated`. Proof: validator commands `000000004770`, `000000004775`, and `000000004779` all exited `0` with `ok: 1` and `generated_refresh: completed`.
- [x] Confirm generated tracker/coverage/generated-source comments refresh away from stale `82/84`/`emits_code:false` state. Proof: validator output reported `research_tracker_update`, coverage refresh, generated metadata refresh, and generated refresh completion for all three commands; target/class/file validators recorded current `88/89` updates.
- [x] Supervisor executes the report through `validator.py execute_report` after implementation verification. Explicit exclusion: this is supervisor-owned post-verification work and was not run by B015 during the accepted implementation callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/0001BQ-ClientItemMenuItemList-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B015/research/0001BQ-ClientItemMenuItemList-source-quality.md","timestamp":"2026-06-27T23:34:22","uid":"0001BQ"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001BQ-ClientItemMenuItemList-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/0001BQ-ClientItemMenuItemList-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001BQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
