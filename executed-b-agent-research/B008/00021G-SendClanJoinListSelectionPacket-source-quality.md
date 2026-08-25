** TARGET-REPORT-UID:00021G **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00021G SendClanJoinListSelectionPacket Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: update [UID:00021G] from a broad file-owned Clan helper to the source-facing `ClanStatusPane::SendClanJoinListSelectionPacket(const wchar_t *selectedClanName)` member/helper, emitted through [UID:00002K] `ClanStatusPane` into `NexusTK/social/Clan.cpp`.
- Final disposition: no split required. Keep exact target range `0x00485590-0x00485682`, keep `RECONSTRUCTABLE:TRUE`, change `CANONICAL_OWNER` from `0000I8` to `00002K`, change `EMITTER_UIDS` from `0000I8` to `00002K`, and populate first-draft C++.
- Recommended metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00002K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002K`, `EMITTER_POSITION_OPTIONAL:` blank.
- Confidence: high for exact boundary, padding, callers, callees, packet layout, `ClanStatusPane` receiver shape, dependency names, and first-draft C++ readiness; medium-high for original source symbol spelling and exact enum names because no debug symbols prove them.

## Target

- Assignment id: `B008-goal2-send-clan-join-list-selection-packet-source-quality-00021G-20260619`
- Target UID: `00021G`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00485590-0x00485682.SendClanJoinListSelectionPacket.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B008\research\00021G-SendClanJoinListSelectionPacket-source-quality.md`
- Current target score/owner state: `84/90`, `CANONICAL_OWNER:0000I8`, `EMITTER_UIDS:0000I8`, reconstructable, blank formal C++.
- Current coverage row: line containing `[UID:00021G]` currently says `packet helper | SendClanJoinListSelectionPacket : reconstructable : 84% : strong`.

## Report-Only Compliance

- No by-* documentation, generated reports, generated source, IDA DB state, project-level reports, or `by-memory/-coverage-report.md` were edited.
- This report supplies exact target/support changes, exact supervisor-owned coverage replacement text, and expected validation commands for a later implementation callback.
- IDA MCP was attempted through `http://127.0.0.1:13337/mcp` and was unavailable: `Unable to connect to the remote server`. I therefore rechecked the target using the local PE `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` with Capstone and compared the results against existing live IDA-backed by-* documentation.

## Executive Recommendation

The strongest source shape is a `ClanStatusPane` packet-sending member/helper:

```cpp
int ClanStatusPane::SendClanJoinListSelectionPacket(const wchar_t *selectedClanName);
```

Rationale:

- Both live callers set `ECX` to `g_pClanStatusPane` at `0x0067ade4` before calling `0x00485590`.
- The function returns with `ret 4`, so it has one explicit stack argument plus an unused receiver, matching a thiscall-like member/helper.
- The `ClanJoinListPane` callers only supply selected row text from inherited `ListPane` storage; they are callers/data sources, not the packet helper owner.
- [UID:00002K] `ClanStatusPane` already owns analogous subtype-6 packet methods after the accepted [UID:00021K] source-quality pass, including helpers whose bodies also do not read `this` but whose callers pass `g_pClanStatusPane`.
- The source route remains [UID:0000I8] `Clan` / `NexusTK/social/Clan.cpp`; this is a direct semantic owner/emitter correction, not a move out of the Clan source file.

Best source-facing name:

- Keep `SendClanJoinListSelectionPacket`.
- Reject `SendClanJoinListSelectRequest` as less precise: subtype `2`, action `0` is already the join-list refresh/request sibling [UID:00021F], while this target is subtype `2`, action `1` and carries the selected row/clan name payload.
- The argument name `selectedClanName` is high-probability and descriptive because inbound subtype `2` populates a counted clan-name list into `m_joinListPane`; `selectedRowText` is the safer generic alternative if the implementation wants to avoid naming the row content as a clan name.

## Evidence Checked

### Documentation Evidence

- Target [UID:00021G] current page.
- [UID:0000I8] `by-file/Clan.md`: places the opcode `0x4b` clan packet helper strip in `NexusTK/social/Clan.cpp`.
- [UID:00002K] `by-class/ClanStatusPane.md`: main clan status UI, owns child list panes and accepted subtype-6 packet helper methods.
- [UID:00002H] `by-class/ClanJoinListPane.md`: caller class supplying selected join-list row text.
- [UID:00010I] `ClanListPaneVirtuals`: documents selected-row action slot and shared list-pane helper island.
- [UID:0002NR] `ClanJoinListPaneSelectedRowAction`: selected-index guard, `ListPane::GetSelectedEntry`, `g_pClanStatusPane` receiver setup, and call to this target.
- [UID:00021U] `ClanListPaneInputHandlers`: Enter-key path with the same selected-entry and `g_pClanStatusPane` receiver setup.
- [UID:00021F] `SendClanJoinListRefreshPacket`: subtype `2`, action `0` retained/no-route refresh/request sibling.
- [UID:00021K] `ClanEnlistListRefreshAndSelectionPacketHelpers`: accepted source-shape precedent for list selection packet methods routed through `ClanStatusPane`.
- [UID:00010H] `ClanStatusRowActionPacket`: row `3` sends subtype `2`, action `0`; row-action dispatcher is `ClanStatusPane` owned.
- [UID:00021S] `ClanStatusPacketDialogHandlers`: inbound opcode `0x43`, subtype `2` handler fills `m_joinListPane` and switches to join-list view.
- [UID:0003YJ] / [UID:0001HZ] / [UID:0000V1] PacketBuffer docs: `0x00575380` is `PacketBufferWriteUInt8`.
- [UID:0001HU] `QueueAndSendPacket`: `0x00574bb0` queues/sends through `Socket` request code `8`.
- [UID:0001P0] and [UID:0000Q5] `g_packetSender`: `0x0067a7ec` is best source-facing `Socket *g_packetSender`.
- [UID:0001BC] `GetMemoryMan`: `0x00516030` is `GetMemoryMan`.
- [UID:0001BH] `MemmoveWrapper`: `0x00516220` is a thin `memmove` wrapper.
- Existing B012 same-target report in another agent folder was treated as a lead only; B008 rechecked the local PE and support docs independently.

### Local PE / Capstone Evidence

- Binary checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Image base: `0x00400000`.
- `.text` section contains the target range.
- Function bytes at `0x00485590-0x00485682` disassemble as one stack-framed function ending with `ret 4`.
- `0x00485682-0x00485690` is fourteen `0xcc` bytes, followed by next helper prologue at `0x00485690`.
- A section-mapped rel32 scan found exactly two direct calls to `0x00485590`: `0x004888ea` and `0x00488951`.
- Exact VA/RVA pointer scans found zero pointer hits to `0x00485590`, `0x00085590`, `0x00485682`, or `0x00085682`.
- Positive-control rel32 scans matched documented dependency fan-in: `0x00575380` has `1114` direct calls, `0x00516220` has `604`, `0x00516030` has `612`, and `0x00574bb0` has `416`.

## IDA / Binary Facts

### Exact Function And Boundary Facts

| Fact | Evidence |
| --- | --- |
| Function start | `0x00485590`, prologue `55 8b ec`, stack allocation `0x184`. |
| Function end | `0x0048567a c2 04 00` (`ret 4`) after security-cookie check. The range end is `0x00485682` after the range-check tail call at `0x0048567d`. |
| Successor padding | `0x00485682-0x00485690` is all `0xcc`; next helper begins with `55 8b` at `0x00485690`. |
| Direct callers | Exactly two rel32 calls: `0x004888ea` and `0x00488951`. |
| Direct pointer/table refs | None found for start/end VA or RVA in local PE scan. |
| Split policy | No split needed; one modeled function with clean padding and one range-check tail. |

### Caller Facts

| Caller | Source context | Receiver and argument behavior |
| --- | --- | --- |
| `0x004888d0-0x004888f1` / call at `0x004888ea` | [UID:0002NR] `ClanJoinListPane::OnSelectedRowAction()` | Reads selected index from `this+0x134`, calls `0x004f3dc0` to get row text, loads `ESI = [0x0067ade4]`, moves `ECX = ESI`, pushes selected text, calls `0x00485590`. |
| `0x00488900-0x00488968` / call at `0x00488951` | [UID:00021U] `ClanJoinListPane` key/event handler | Delegates base input handler, narrows event key, requires Enter (`0x0d`), reads selected index `+0x134`, gets selected row through `0x004f3dc0`, moves `ECX = g_pClanStatusPane`, pushes selected text, calls `0x00485590`. |

Both callers prove the selected row text comes from `ClanJoinListPane`/`ListPane` storage, while the packet helper receiver is `ClanStatusPane`.

### Callee / Helper Facts

| Address | Best source-facing role | Target use |
| --- | --- | --- |
| `0x00516030` | `GetMemoryMan()` | Called at function start; returned pointer is kept in `EDI` and moved to `ECX` before the memmove wrapper. Draft C++ can use ordinary `memmove` and document this as support/helper setup. |
| `0x00575380` | `PacketBufferWriteUInt8` | Writes opcode, subtype, action, and converted-length bytes. Local disassembly proves ABI order is `(value, destination)`: callee reads value from `[ebp+8]` and destination from `[ebp+0xc]`. |
| `WideCharToMultiByte` IAT `0x0060d170` | CP_ACP wide-to-multibyte conversion | Called with code page `0`, flags `0`, selected wide text, signed low-byte character count, destination `convertedName[256]`, default-char args `0`. |
| `0x00516220` | `MemmoveWrapper` / `memmove` | Copies converted payload bytes to packet offset `4`. It is a memmove wrapper and should not be given a Clan-specific helper name. |
| `0x00574bb0` | `Socket::QueueAndSendPacket` / `QueueAndSendPacket` | Queues/sends counted packet bytes through `g_packetSender`. |
| `0x0067a7ec` | `Socket *g_packetSender` | Loaded immediately before the final send call. |
| `0x005c7655` | `___report_rangecheckfailure` | Tail for converted-buffer and packet-buffer range checks. |

### Packet Layout

| Offset | Sent? | Contents |
| --- | --- | --- |
| `0` | yes | Opcode `0x4b`, Clan outbound request/action packet family. |
| `1` | yes | Subtype `2`, join-list family. |
| `2` | yes | Action `1`, selected row/clan-name submission. |
| `3` | yes | Converted multibyte payload byte length, one byte. |
| `4..(4+convertedLength-1)` | yes | CP_ACP converted selected row/clan-name bytes. |
| `4+convertedLength` | no | Local packet terminator/scratch byte; excluded from `QueueAndSendPacket` length. |

Queue length is exactly `convertedLength + 4`. The local `convertedName[convertedLength] = 0` and `packet[packetLength] = 0` writes are local scratch terminators, not protocol bytes.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best inference / decision | Rejected alternatives and impact |
| --- | --- | --- | --- |
| Exact boundary | Local PE disassembly, target docs, padding bytes. | Keep `0x00485590-0x00485682`; padding `0x00485682-0x00485690`; next helper `0x00485690`. | No split/merge needed. Do not include padding or sibling subtype `3` helper. |
| Helper source name | Packet bytes `{0x4b,2,1}`, two join-list callers, sibling [UID:00021F] action `0`, inbound subtype `2` join-list handler. | Keep `SendClanJoinListSelectionPacket`. | Reject `SendClanJoinListSelectRequest`; action `0` is the refresh/request side, while this is action `1` with a selected row payload. Reject raw `sub_485590`. |
| Source signature | `ret 4`, both callers set `ECX = g_pClanStatusPane`, one stack argument, callee ignores `this`. | `int ClanStatusPane::SendClanJoinListSelectionPacket(const wchar_t *selectedClanName)`; member/helper may not read fields. | Reject plain `__stdcall(const wchar_t*)` because it discards deliberate receiver setup. Reject `ClanJoinListPane` owner because the list pane only supplies row text. |
| Selected-row text ownership | [UID:0002NR] and [UID:00021U] both call `ListPane::GetSelectedEntry` at `0x004f3dc0` after selected index `+0x134` checks. | Borrowed `const wchar_t *` selected row/clan-name pointer from list storage; helper does not own or free it. | Reject heap-transfer, mutable output, or `ClanStatusPane` field source. |
| Owner/emitter | Current target owner file [UID:0000I8]; both callers load [UID:0002B5] singleton slot `0x0067ade4`; [UID:00021K] uses same `ClanStatusPane` receiver pattern. | Direct semantic owner/emitter should be [UID:00002K] `ClanStatusPane`; source route remains [UID:0000I8] `Clan` / `social/Clan.cpp`. | Reject direct file-owner as final source shape; keep it only as source-file route. Reject PacketBuffer/Socket utility ownership. |
| Packet protocol name | Sibling row-action/inbound docs: row `3` / subtype `2`, inbound subtype `2` fills join list, action `0` refresh/request, action `1` selection. | Opcode `0x4b` = Clan outbound request/action family; subtype `2` = join list; action `1` = selected join-list row/clan-name submission. | Reject status, enlist, leave, or inbound-opcode interpretations. |
| Byte writer helper signature | Local disassembly of `0x00575380`: reads value from `[ebp+8]`, destination from `[ebp+0xc]`; target calls push destination then value. | Document source/ABI signature as `PacketBufferWriteUInt8(unsigned char value, unsigned char *out)` or equivalent value-first helper. | Existing support drafts sometimes show destination-first calls. If those are kept for readability, they should be explicitly treated as wrapper/convenience style, not ABI-signature proof. |
| `sub_516030` role | Target calls `0x00516030`, stores returned pointer in `EDI`, sets `ECX=EDI` before `0x00516220`; MemoryMan docs identify `GetMemoryMan`. | It is MemoryMan singleton setup for the copy wrapper; source draft should use `memmove` directly unless final MemoryMan copy API is standardized. | Reject packet-specific conversion/copy helper names for `sub_516030`. |
| `sub_516220` role | Docs and disassembly confirm wrapper around `_memmove(destination, source, size)`, callee pops three stack args. | Use `memmove(packet + 4, convertedName, convertedLength)` in draft. | Reject Clan-specific or PacketBuffer-specific copy helper names. |
| `QueueAndSendPacket` role | [UID:0001HU] exact range, [UID:0001P0]/[UID:0000Q5] global type, local call with `ECX = [0x0067a7ec]`. | Use `g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength))`; it queues counted bytes and adds its own private terminator copy. | Reject stale `CashShopRequest` ownership/alias for this target. |
| Wide-to-multibyte policy | Local disassembly computes wide string length in `EBX`, then passes `movsx eax, bl` as `cchWideChar`; code page/flags/default char args are zero. | This is real legacy signed-byte length behavior, not a decompiler artifact. It likely comes from source storing the wide count in signed `char`/low-byte form because the packet uses one-byte lengths. It is a source bug/edge-case for names with wide length >= 128, practically masked by UI row widths and later `<0x80` packet guard. Preserve in first-draft C++. | Reject simplifying to full `wcslen` in the target formal draft; reject `-1`/NUL-inclusive conversion; reject UTF-8/Unicode send. |
| Converted-length guard | Disassembly checks `convertedLength >= 0x100` before writing converted NUL and length byte. | Protects `convertedName[256]` and one-byte length range. Keep as range-check failure path. | Do not treat `0x100` as sent packet cap. |
| Packet-length guard | Disassembly computes `packetLength = convertedLength + 4`, checks `>= 0x80`, then writes local packet terminator and sends exactly `packetLength`. | Protects local `packet[128]`; effective sent payload cap is `convertedLength + 4 < 128`. | Do not include packet terminator in send length. |
| C++ readiness | Current target `84/90` already clears active numeric gate; dependency names and source owner are now resolved; no split needed. | Populate first-draft C++; raise to `88/91`. | Reject old "below 95/95" blocker. Exact original enum names are not required for first-draft source under current gate. |

## Source-Level Packet Helper Draft

Populate target formal C++ with source-style code. This draft uses ABI-faithful `PacketBufferWriteUInt8(value, destination)` order; if the project elects to keep the older destination-first wrapper style in support docs, that should be a documented wrapper-style convention rather than a binary-signature claim.

```cpp
int ClanStatusPane::SendClanJoinListSelectionPacket(const wchar_t *selectedClanName)
{
    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(0x02, packet + 1);
    PacketBufferWriteUInt8(0x01, packet + 2);

    const char sourceCharCount = static_cast<char>(wcslen(selectedClanName));
    const int convertedLength = WideCharToMultiByte(
        CP_ACP,
        0,
        selectedClanName,
        sourceCharCount,
        convertedName,
        sizeof(convertedName),
        NULL,
        NULL);
    if (static_cast<unsigned int>(convertedLength) >= sizeof(convertedName)) {
        __report_rangecheckfailure();
    }

    convertedName[convertedLength] = '\0';
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + 3);
    memmove(packet + 4, convertedName, convertedLength);

    const int packetLength = convertedLength + 4;
    if (static_cast<unsigned int>(packetLength) >= sizeof(packet)) {
        __report_rangecheckfailure();
    }

    packet[packetLength] = 0;
    return g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}
```

Draft notes:

- `const char sourceCharCount = static_cast<char>(wcslen(...))` is intentional to preserve the observed `movsx eax, bl` behavior. It is not a recommended modern implementation, but it is the best first-draft reconstruction of this binary.
- The draft keeps literal opcode/subtype/action bytes because original enum names are not proven. Support docs may introduce descriptive names such as `kClanPacketOpcode = 0x4b`, `kClanJoinListSubtype = 2`, and `kClanActionSubmitSelection = 1`, but the target draft should not invent final enum declarations by itself.
- The helper returns the `QueueAndSendPacket` return value because both caller paths preserve/use the target's `EAX` shape: [UID:0002NR] returns the helper result on the positive selected-row path, while [UID:00021U] returns a boolean success after the call.

## Ranked Ownership Analysis

### 1. [UID:00002K] `ClanStatusPane`

- Evidence for: both call sites load `g_pClanStatusPane` into `ECX`; the helper is part of the clan status pane's join-list flow; `ClanStatusPane` owns `m_joinListPane`, `m_enlistListPane`, row-action dispatch, inbound clan packet parsing, and accepted subtype-6 packet methods with the same receiver pattern.
- Evidence against: the body does not dereference `this`.
- Decision: accepted. An unused `this` in a short packet sender is plausible and better explains the call ABI than a file-local function.

### 2. [UID:0000I8] `Clan` file-level helper

- Evidence for: the helper sits in the contiguous opcode `0x4b` Clan packet helper strip and emits to `NexusTK/social/Clan.cpp`.
- Evidence against: file-level ownership loses the receiver evidence and is broader than necessary under by-structure direct-owner rules.
- Decision: rejected as direct owner, retained as source-file route through `ClanStatusPane`.

### 3. [UID:00002H] `ClanJoinListPane`

- Evidence for: both live callers are `ClanJoinListPane` behavior and selected text comes from this list pane's inherited row storage.
- Evidence against: both callers change `ECX` to `g_pClanStatusPane` before calling; the helper is not invoked on the list-pane receiver.
- Decision: rejected as direct owner; keep as caller/data-source support.

### 4. PacketBuffer / Socket / protocol-only owner

- Evidence for: the helper uses PacketBuffer writes and `g_packetSender`.
- Evidence against: those are generic dependencies. They do not own feature-specific opcode `0x4b` clan semantics.
- Decision: rejected.

## Open Questions With Attempted Resolution

- Exact original method spelling: not recoverable from binary. `SendClanJoinListSelectionPacket` is the strongest descriptive name and matches current file naming plus sibling `SendClanJoinListRefreshPacket`.
- Exact argument name: `selectedClanName` is high-probability because inbound join-list handler appends counted clan-name entries; `selectedRowText` remains an acceptable conservative wording in prose.
- Exact enum names: unresolved. Use literal bytes in formal draft and document protocol names in prose.
- `PacketBufferWriteUInt8` final header order: B008 local disassembly proves ABI order `(value, destination)`. Some existing support C++ snippets use destination-first order; implementation should either correct those snippets when touched or document the destination-first call as a source wrapper convention. This uncertainty does not block 00021G C++ if the target draft uses ABI-faithful order.
- Wide count signed-byte behavior: resolved as real legacy/source-edge behavior, not decompiler artifact. It should be documented and preserved in the draft.

## Recommended Target Doc Changes

Update `by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md`:

- Metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:00002K`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:00002K`
  - `EMITTER_POSITION_OPTIONAL:` unchanged/blank
- Replace status entity kind with `ClanStatusPane packet-sending member/helper`.
- Replace "global/helper function" and "file-level Clan attachment" as the final direct source shape with the `ClanStatusPane` receiver-method decision.
- Keep source module route [UID:0000I8] `Clan` / `NexusTK/social/Clan.cpp`.
- Add caller table with `0x004888ea` and `0x00488951`, showing selected-row source and `ECX = g_pClanStatusPane`.
- Add binary recheck facts:
  - exact `0x00485590-0x00485682` range;
  - `0x00485682-0x00485690` fourteen `0xcc` bytes;
  - zero VA/RVA pointer hits to start/end;
  - exact two rel32 callers.
- Add packet layout table and explicitly call the final packet byte a non-sent local terminator.
- Add helper/dependency table:
  - `0x00575380` = `PacketBufferWriteUInt8`, value-first ABI order;
  - `0x00516030` = `GetMemoryMan`;
  - `0x00516220` = `MemmoveWrapper`/`memmove`;
  - `0x00574bb0` = `QueueAndSendPacket`;
  - `0x0067a7ec` = `Socket *g_packetSender`.
- Replace old `95/95` or "final source gate" no-code blocker with active code-gate explanation and first-draft C++.
- Add a 2026-06-19 B008 change-log entry preserving:
  - owner/emitter change to `ClanStatusPane`;
  - exact boundary/padding/caller/callee evidence;
  - signed-byte wide-length caveat;
  - PacketBuffer helper ABI-order note;
  - opcode/subtype/action semantics;
  - rejected alternatives.

## Recommended Support Doc Changes

- [UID:00002K] `by-class/ClanStatusPane.md`
  - Add a method row for `SendClanJoinListSelectionPacket` at [UID:00021G] `0x00485590-0x00485682`.
  - Describe it as subtype `2`, action `1`, selected join-list row/clan-name sender.
  - Add evidence that `ClanJoinListPane` callers load `g_pClanStatusPane` before calling.
  - Recommended score after update: raise from `85/86` to `86/88` because the class gains another source-quality method and ownership resolution; keep confidence below final due full layout/source-split caveats.
- [UID:0000I8] `by-file/Clan.md`
  - Update the contents row from file-local "SendClanJoinListSelectionPacket" to `ClanStatusPane::SendClanJoinListSelectionPacket`.
  - Preserve that generated output remains in `NexusTK/social/Clan.cpp`.
  - No score change required; optional confidence `90/86` only if the implementation also updates multiple packet-helper rows consistently.
- [UID:00002H] `by-class/ClanJoinListPane.md`
  - Clarify that this class supplies selected row text and calls the `ClanStatusPane` packet helper; it is not the packet helper owner.
  - No score change required.
- [UID:0002NR] `by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md`
  - Update C++ call shape from:
    ```cpp
    return SendClanJoinListSelectionPacket(g_pClanStatusPane, selectedName);
    ```
    to:
    ```cpp
    return g_pClanStatusPane->SendClanJoinListSelectionPacket(selectedName);
    ```
  - Preserve `int` return behavior.
- [UID:00021U] `by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md`
  - Update prose for `0x00488951` to call `ClanStatusPane::SendClanJoinListSelectionPacket`.
  - Note that the Enter-key handler sets `ECX = g_pClanStatusPane` before the call.
  - No score change required unless first-draft C++ is also added for this mixed range.
- [UID:00010I] `by-memory/0x00488610-0x004888f1.ClanListPaneVirtuals.md`
  - Update selected-row action note to reflect the `ClanStatusPane` method owner.
- [UID:00021F] `by-memory/0x00485520-0x00485588.SendClanJoinListRefreshPacket.md`
  - Add cross-note that action `0` is the retained/no-route refresh/request counterpart and [UID:00021G] is the live action `1` selection method.
- [UID:00010H] `by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md`
  - Add cross-note that row `3` subtype `2` action `0` pairs with [UID:00021G] action `1`; do not emit action `1` from the row-action helper.
- [UID:00021S] `by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md`
  - Cross-link inbound subtype `2` handler as the list population path whose rows feed this selected-row sender.
- [UID:0003YJ] / [UID:0000V1] PacketBuffer support docs
  - Add or confirm `PacketBufferWriteUInt8` ABI argument order as `(value, destination)` from `0x00575380` disassembly. If support code snippets keep destination-first helper calls, document them as source-wrapper style rather than raw ABI signature.
- [UID:0001HU] `QueueAndSendPacket` and [UID:0001P0]/[UID:0000Q5] `g_packetSender`
  - Add [UID:00021G] as a caller/consumer example only; no owner changes.
- [UID:0001BC] `GetMemoryMan` and [UID:0001BH] `MemmoveWrapper`
  - Add cross-note only if touched: [UID:00021G] uses `GetMemoryMan` solely to set up the memmove wrapper; source draft can use ordinary `memmove`.

## Exact Coverage Row Text

Do not edit `by-memory/-coverage-report.md` during this report pass. Replace the existing [UID:00021G] row with:

```markdown
    - [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md) 0x00485590-0x00485682 | ClanStatusPane packet helper/method | ClanStatusPane::SendClanJoinListSelectionPacket : reconstructable : 88% : very strong : B008 2026-06-19 source-quality reanalysis resolves the live subtype-2 action-1 join-list selection sender as a ClanStatusPane receiver helper emitted through social/Clan.cpp; local PE/Capstone recheck confirms exact bounds, `0x00485682-0x00485690` padding, exactly two callers at `0x004888ea` and `0x00488951`, zero start/end VA/RVA pointer hits, caller `ECX = g_pClanStatusPane` setup, selected text borrowed from ClanJoinListPane/ListPane row storage, opcode `0x4b` subtype `2` action `1`, CP_ACP WideCharToMultiByte conversion using the real signed low-byte source character count (`movsx eax, bl`), one-byte converted-length and `<0x80` packet-length guards, local-only non-sent terminators, PacketBufferWriteUInt8 value-first ABI, MemmoveWrapper/memmove payload copy, QueueAndSendPacket through `Socket *g_packetSender`, owner/emitter change to [UID:00002K], and first-draft C++ readiness.
```

Placement context: replace current line in `by-memory/-coverage-report.md` containing `[UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket]`.

## IDA Rename / Type / Comment Recommendations

- Rename/comment `0x00485590` as `ClanStatusPane::SendClanJoinListSelectionPacket`.
- Function type:
  ```cpp
  int __thiscall ClanStatusPane::SendClanJoinListSelectionPacket(const wchar_t *selectedClanName);
  ```
- Comment `0x00485601` / `movsx eax, bl`: "source count is signed low byte of wcslen result; preserve legacy signed-byte behavior".
- Comment `0x00485620`: "terminates local converted-name scratch buffer, not sent".
- Comment `0x00485659`: "terminates local packet scratch buffer after counted span, not sent".
- Comment `0x00485668`: "QueueAndSendPacket(g_packetSender, packet, convertedLength + 4)".
- Normalize `dword_67A7EC` use as `g_packetSender`.
- Normalize `sub_575380` comments to `PacketBufferWriteUInt8(value, destination)`.
- Normalize `sub_516220` comments to `memmove(destination, source, size)`.

## Validation Commands Expected After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00021G-SendClanJoinListSelectionPacket-source-quality-removed.md](00021G-SendClanJoinListSelectionPacket-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If PacketBuffer helper signature comments are updated during implementation, also validate:

> Executable block R002 was removed from this report and preserved verbatim in [00021G-SendClanJoinListSelectionPacket-source-quality-removed.md](00021G-SendClanJoinListSelectionPacket-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No validators were run during this report-only pass.

## Implementation Callback Checklist

1. Lease target [UID:00021G] and all support docs before editing.
2. Apply target metadata `88/91`, owner/emitter `00002K`, reconstructable true.
3. Replace file-helper status text with `ClanStatusPane` packet-helper/member status while preserving `social/Clan.cpp` source route.
4. Insert the first-draft C++ block from this report, including signed-byte source count and value-first `PacketBufferWriteUInt8` calls.
5. Add the caller/callee/boundary/packet-layout tables at report-level detail.
6. Preserve and mark superseded:
   - old `95/95` no-code wording;
   - broad file-local helper-only owner claim;
   - any raw helper names `sub_575380`, `sub_516220`, `sub_574BB0`, `dword_67A7EC` not yet normalized.
7. Update support docs listed above, especially [UID:0002NR] formal C++ call shape.
8. Do not edit `by-memory/-coverage-report.md`; carry the exact replacement row in implementation notes for supervisor.
9. Run validators and record exact output.

## Final Recommendation

[UID:00021G] is implementation-ready. It should be raised to `88/91`, rerouted to [UID:00002K] `ClanStatusPane`, and given formal first-draft C++. The only remaining uncertainty is original spelling of helper/enum names, which should cap confidence below final audit but no longer blocks source reconstruction.

FINISHED report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/00021G-SendClanJoinListSelectionPacket-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/00021G-SendClanJoinListSelectionPacket-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"00021G"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00021G-SendClanJoinListSelectionPacket-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/00021G-SendClanJoinListSelectionPacket-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00021G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
