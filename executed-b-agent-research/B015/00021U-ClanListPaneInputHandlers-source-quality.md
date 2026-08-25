** TARGET-REPORT-UID:00021U **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00021U ClanListPaneInputHandlers Source-Quality / Heuristic Research

## Finalized Report / Current Recommendation

- Current recommendation: split [UID:00021U] `ClanListPaneInputHandlers` into class-owned child method pages before formal C++ is populated. The current aggregate spans `ClanJoinListPane` and `ClanEnlistListPane`, so it is a mixed address cluster, not the narrowest source owner for its three real methods.
- Best method names/signatures:
  - `0x00488900-0x00488968`: `bool ClanJoinListPane::OnKeyEvent(const PaneKeyEvent *event)`.
  - `0x00488970-0x00488991`: `int ClanEnlistListPane::OnSelectedRowAction()`.
  - `0x004889a0-0x00488b3d`: `bool ClanEnlistListPane::OnKeyEvent(const PaneKeyEvent *event)`.
- Current aggregate disposition: keep as a reviewed mixed split/index until the children exist. Do not populate the current aggregate C++ block with all three methods because that would bypass the correct class owners.
- Immediate pre-split score recommendation: `84/90` -> `86/91`, `CANONICAL_OWNER:0000I8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000I8`, blank C++ with split-before-code rationale.
- Preferred post-split metadata: parent `00021U` becomes `RECONSTRUCTABLE:FALSE`, `EMITTER_UIDS:` blank, `88/91`; exact child pages carry reconstruction, direct class ownership, emitters, and first-draft C++.
- I did not edit `by-memory/-coverage-report.md`, target docs, support docs, or generated docs. This assignment was explicitly report-only.

## Target

- Target UID: `00021U`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00488900-0x00488b3d.ClanListPaneInputHandlers.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B015\research\00021U-ClanListPaneInputHandlers-source-quality.md`
- Current queue row: `project-level/-auto-completion-stats.md` lists `00021U` at `84/90`, average `87.0`.
- Current generated state: `auto-generated/-ag-memory-coverage.md` routes `00021U` to `auto-generated/NexusTK/social/Clan.cpp` as an empty emitter marker through [UID:0000I8][Clan].

## Executive Recommendation

Create these child pages and leave the current aggregate as a non-emitting index after the split:

| Proposed child path | Range | Direct owner | Emitter | Recommended score | C++ readiness |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x00488900-0x00488968.ClanJoinListPaneOnKeyEvent.md` | `0x00488900-0x00488968` | [UID:00002H][ClanJoinListPane] | `00002H` -> [UID:0000I8][Clan] | `87/91` | Ready after split. |
| `by-memory/0x00488970-0x00488991.ClanEnlistListPaneSelectedRowAction.md` | `0x00488970-0x00488991` | [UID:00002C][ClanEnlistListPane] | `00002C` -> [UID:0000I8][Clan] | `88/92` | Ready after split. |
| `by-memory/0x004889a0-0x00488b3d.ClanEnlistListPaneOnKeyEvent.md` | `0x004889a0-0x00488b3d` | [UID:00002C][ClanEnlistListPane] | `00002C` -> [UID:0000I8][Clan] | `87/91` | Ready after split, with `0x84` label caveat. |

The existing [UID:0000VN][-ignored] entry already documents the padding spans `0x004888f1-0x00488900`, `0x00488968-0x00488970`, `0x00488991-0x004889a0`, and `0x00488b3d-0x00488b40`. If the method split is applied, the coverage report should expose the two internal padding spans as separate ignored rows or nested rows so no executable child appears to cover them.

## Supervisor Active Recheck

- Standing B-agent rules require resolving ownership/source-shape, helper names, packet fields, split/range decisions, and C++ blockers with evidence rather than copying old uncertainty.
- `by-structure.md` requires `CANONICAL_OWNER` to be the narrowest true owner and says mixed-owner convenience pages should become non-emitting containers after exact children carry the source ownership.
- The current target has three IDA-modeled function starts and two distinct class owners. The split is not optional cleanup if first-draft C++ is to be source-quality.
- IDA MCP was unavailable in this session: `http://127.0.0.1:13337/mcp` returned `Unable to connect to the remote server`. I used existing live-IDA evidence already written into the target/support docs and revalidated the range directly from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` with a section-mapped PE pointer/rel32/call/padding scan.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best inference / decision | Rejected alternatives and impact |
| --- | --- | --- | --- |
| `0x00488900` source name | Raw bytes show vtable-only pointer at `0x006157d4`, no direct callers, first call to `0x004f4300`, then Enter-gated call to [UID:00021G]. [UID:0003U2] names `0x004f4300` as `ListPane::OnKeyEvent`. Generated social code uses `OnKeyEvent(const PaneKeyEvent*)` for similar handlers. | `bool ClanJoinListPane::OnKeyEvent(const PaneKeyEvent *event)`. | Reject `OnKeyOrMouseEvent`: the direct base callee is `ListPane::OnKeyEvent`, and this body only consumes narrowed key bytes. Reject file-local helper names because the vtable owner is `ClanJoinListPane`. |
| `0x00488970` source name | Vtable-only pointer at `0x006158b0`; body reads `this+0x134`, calls `GetSelectedEntry`, loads `g_pClanStatusPane`, calls `ClanStatusPane::SendClanEnlistListSelectionPacket`, and preserves helper/negative-index return. Sibling [UID:0002NR] uses `OnSelectedRowAction()`. | `int ClanEnlistListPane::OnSelectedRowAction()`. | Reject `void` until later declaration proof because raw negative path returns the negative index and positive path preserves `EAX` from the helper. Reject `ClanStatusPane` ownership because receiver `ecx` at function entry is the list pane. |
| `0x004889a0` source name | Vtable-only pointer at `0x00615898`; body delegates to `0x004f4300`, narrows key bytes, handles Enter and `0x84`, and returns bool consumed/unconsumed state. | `bool ClanEnlistListPane::OnKeyEvent(const PaneKeyEvent *event)`. | Reject `OnInputEvent` for the final method name in this target because the base call is the key handler, not `ListPane::OnInputEvent` at `0x004f4190`. Keep `PaneKeyEvent` spelling descriptive until the shared event type is finalized. |
| Selected index field | Raw instructions read `this+0x134` in all three functions; [UID:000194] and [UID:00007A] identify it as the reusable `ListPane` selected index. `int_convert.py` verifies `0x134` = 308. | Use inherited `m_selectedIndex`. Negative means no selected row. | Reject feature-specific fields such as `m_selectedApplicantIndex`; the offset is inherited reusable `ListPane` state. |
| Selected-entry helper `0x004f3dc0` | Calls at `0x00488943`, `0x00488982`, and `0x004889fe`; [UID:000194] names it `ListPane::GetSelectedEntry`. | Use `GetSelectedEntry(selectedIndex)` returning selected row payload/text pointer. | Reject raw `sub_4f3dc0` and generated unrelated owner labels. |
| Base helper `0x004f4300` | Calls at `0x00488912` and `0x004889c2`; [UID:0003U2] records `0x004f4300-0x004f43ce` as the `ListPane::OnKeyEvent` body with owned switch table. | Derived handlers should call `ListPane::OnKeyEvent(event)` first and return true if it consumes the event. | Reject generic "base input" wording as final source name; it obscures the actual ListPane key-handler slot. |
| Event byte/narrowing behavior | Raw reads `event+0x10a` and `event+8`, then calls `0x004a8b10` through `dword_67a754`/ctype context. Existing generated code uses `NarrowPaneKey(event->payload[0], event->keyState)` and `NarrowEventKeyByte(event->keyByte, event->fallbackByte)`. `int_convert.py` verifies `0x10a` = 266. | Model as a narrowed key byte from the pane key event. Source-facing field names remain descriptive, not original-proof. | Reject inventing a full new event struct in this report. The shared event declaration belongs with the EventHandler/ListPane family. This caps final polish but not child C++ behavior. |
| Enter key | Raw compares to `0x0d`; `int_convert.py` verifies decimal 13. | Use `kKeyEnter` or local `0x0d` constant. | No open issue; existing source style already uses `kKeyEnter` in other generated handlers. |
| Key `0x84` semantics | Raw `0x004889a0` compares narrowed key `0x84` by subtracting `0x0d` then `0x77`, sends subtype `6`, action `3`, then calls action `0` refresh. Existing docs and `rg` search found no source-quality user-facing label; other `0x84` hits are unrelated opcodes, offsets, or stack sizes. `int_convert.py` verifies decimal 132. | Do not assign a user-facing label. Use a conservative source constant such as `kClanEnlistListAction3Key` or `kClanEnlistListAlternateActionKey`. | Reject approve/accept/reject/delete labels. The binary proves a selected-row action-3 packet, not server-side meaning. This caps score/final naming but does not block split child first-draft C++ if the constant is named descriptively. |
| Action `1` helper relationship | [UID:00021K] now names `0x004859d0` as `ClanStatusPane::SendClanEnlistListSelectionPacket(const wchar_t *applicantName)`. Call sites are `0x0048898a` and `0x00488b09` after selected-row lookup. | Use `g_pClanStatusPane->SendClanEnlistListSelectionPacket(applicantName)` in enlist child drafts. | Reject old generic `SendClanSubtype6NamePacket` and reject moving ownership of the helper to `ClanEnlistListPane`; callers pass `g_pClanStatusPane`. |
| Action `0` follow-up | [UID:00021K] now names `0x00485960` as `ClanStatusPane::SendClanEnlistListRefreshPacket()`. The key `0x84` action-3 path calls it at `0x00488aec`. | Treat the follow-up as enlist-list refresh after action `3`. | Reject `OpenRequest` for this call site because it is a refresh after an inline selected-row action. |
| Inline action `3` packet | Raw writes `{0x4b, 6, 3}`, converts selected wide row text with `WideCharToMultiByte`, writes one-byte length, copies payload, range-checks `<0x100` and `<0x80`, queues `convertedLength + 4`, then calls action `0`. | This body belongs in `ClanEnlistListPane::OnKeyEvent`; do not move it into [UID:00021K]. | Reject merging with [UID:00021L] raw action-3 helper strip because [UID:00021L] still has no live route and this target has the live inline body. |
| `PacketBufferWriteUInt8` role | [UID:0003YJ] identifies `0x00575380` as a byte writer with broad xrefs. Calls in this target at `0x00488a30`, `0x00488a3e`, `0x00488a4c`, and `0x00488aa9`. | Use `PacketBufferWriteUInt8`. | Reject raw `sub_575380` and any string-writer interpretation. |
| Queue/send and global sender | [UID:0001HU] documents `0x00574bb0` as Socket queue/send wrapper; [UID:0001P0]/[UID:0000Q5] document `0x0067a7ec` as `Socket *g_packetSender`. | Use `g_packetSender->QueueAndSendPacket(packet, length)`. | Reject generated `g_pCashShopRequest` aliases and direct-socket-write wording. |
| Copy/conversion helpers | [UID:0001BC] identifies `0x00516030` as `GetMemoryMan`; [UID:0001BH] identifies `0x00516220` as a `memmove` wrapper. This target calls `0x00516030` before payload copy and `0x00516220` at `0x00488abf`. | Draft C++ should use ordinary `memmove`; `0x00516030` is a support/context touch, not a Clan helper. | Reject packet-specific names for these helpers. |
| Non-sent terminator bytes | Raw action-3 path writes `convertedName[convertedLength] = 0` and `packet[packetLength] = 0`, then queues only `packetLength`. | Document as local terminator/padding, not protocol bytes. | Reject any packet layout that includes the zero terminator after payload. |
| Split/range status | Raw PE: functions sizes `0x68`/104, `0x21`/33, `0x19d`/413; padding bytes are `0xcc` at `0x00488968-0x00488970`, `0x00488991-0x004889a0`, and `0x00488b3d-0x00488b40`. Pointers to starts are only vtable slots `0x006157d4`, `0x006158b0`, `0x00615898`; no rel32 direct callers to starts. | Split into child method pages, parent becomes non-emitting index after split. | Reject keeping one source-bearing aggregate as the final shape. It would force file-level canonical ownership over methods whose direct owners are known classes. |
| First-draft C++ readiness | Current aggregate is numerically eligible, but source-shape is mixed. Child pages would each be reconstructable, class-owned, above gate, and have stable callees/dependencies. | Do not populate current aggregate C++; populate child pages after split using the drafts below. | The no-code proof for current target is structural, not behavioral: one `CANONICAL_OWNER` cannot correctly represent both `ClanJoinListPane` and `ClanEnlistListPane` method bodies. |

## IDA / PE Facts

### 2026-06-19 Resume Raw PE Verification

Fresh section-mapped PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirms the target still resolves in `.text` with image base `0x00400000`.

- `0x00488900-0x00488968`: 104-byte code body. Calls inside the body are `0x00488912 -> 0x004f4300`, `0x0048892e -> 0x004a8b10`, `0x00488943 -> 0x004f3dc0`, and `0x00488951 -> 0x00485590`.
- `0x00488968-0x00488970`: eight `0xcc` bytes.
- `0x00488970-0x00488991`: 33-byte code body. Calls inside the body are `0x00488982 -> 0x004f3dc0` and `0x0048898a -> 0x004859d0`.
- `0x00488991-0x004889a0`: fifteen `0xcc` bytes.
- `0x004889a0-0x00488b3d`: 413-byte code body. Calls inside the body are `0x004889c2 -> 0x004f4300`, `0x004889e2 -> 0x004a8b10`, `0x004889fe -> 0x004f3dc0`, `0x00488a20 -> 0x00516030`, `0x00488a30/0x00488a3e/0x00488a4c/0x00488aa9 -> 0x00575380`, `0x00488abf -> 0x00516220`, `0x00488ae5 -> 0x00574bb0`, `0x00488aec -> 0x00485960`, `0x00488afb/0x00488b18/0x00488b2d -> 0x005c772f`, `0x00488b09 -> 0x004859d0`, and `0x00488b38 -> 0x005c7655`.
- `0x00488b3d-0x00488b40`: three `0xcc` bytes before [UID:00010J].
- Little-endian pointer hits for the three function starts are exactly the known vtable slots: `0x00488900` at `0x006157d4`, `0x00488970` at `0x006158b0`, and `0x004889a0` at `0x00615898`.
- The same scan found zero `E8`/`E9` rel32 refs to the three function starts, preserving the no-direct-caller / virtual-dispatch conclusion.

### Function And Padding Facts

| Range | Raw fact |
| --- | --- |
| `0x00488900-0x00488968` | Modeled 104-byte `ClanJoinListPane` key handler body. |
| `0x00488968-0x00488970` | Eight `0xcc` alignment bytes. |
| `0x00488970-0x00488991` | Modeled 33-byte `ClanEnlistListPane` selected-row action. |
| `0x00488991-0x004889a0` | Fifteen `0xcc` alignment bytes. |
| `0x004889a0-0x00488b3d` | Modeled 413-byte `ClanEnlistListPane` key handler body with stack-cookie frame and inline action `3` packet. |
| `0x00488b3d-0x00488b40` | Three `0xcc` alignment bytes before [UID:00010J]. |

### Xref And Call Facts

| Address | Fact |
| --- | --- |
| `0x006157d4 -> 0x00488900` | Vtable-only pointer into `ClanJoinListPane` vtable. |
| `0x006158b0 -> 0x00488970` | Vtable-only pointer into `ClanEnlistListPane` vtable. |
| `0x00615898 -> 0x004889a0` | Vtable-only pointer into `ClanEnlistListPane` vtable. |
| direct rel32 refs to `0x00488900`, `0x00488970`, `0x004889a0` | None found in PE scan; these are virtual dispatch bodies. |
| `0x00488912`, `0x004889c2` | Calls `0x004f4300` / `ListPane::OnKeyEvent`. |
| `0x00488943`, `0x00488982`, `0x004889fe` | Calls `0x004f3dc0` / `ListPane::GetSelectedEntry`. |
| `0x00488951` | Calls [UID:00021G] `SendClanJoinListSelectionPacket`. |
| `0x0048898a`, `0x00488b09` | Calls [UID:00021K] `ClanStatusPane::SendClanEnlistListSelectionPacket`. |
| `0x00488aec` | Calls [UID:00021K] `ClanStatusPane::SendClanEnlistListRefreshPacket`. |
| `0x00488ae5` | Calls [UID:0001HU] `QueueAndSendPacket` using `g_packetSender`. |

## Ranked Ownership Analysis

### 1. Split child owners: `ClanJoinListPane` and `ClanEnlistListPane`

Evidence for:

- All three starts are vtable-only virtual methods.
- `0x00488900` has the `ClanJoinListPane` vtable pointer at `0x006157d4`.
- `0x00488970` and `0x004889a0` have `ClanEnlistListPane` vtable pointers at `0x006158b0` and `0x00615898`.
- The bodies use inherited `ListPane` state and selected-entry APIs on the incoming `this`.
- Both class pages are already above the parent gate and emit through [UID:0000I8][Clan].

Evidence against:

- The three functions are physically adjacent and all source-route to `social/Clan.cpp`.

Decision:

- Best direct ownership. Physical adjacency supports common source file placement, not one canonical direct owner.

### 2. [UID:0000I8] `Clan`

Evidence for:

- All methods and packet helpers belong to the Clan source island and generated route is `NexusTK/social/Clan.cpp`.
- Current aggregate spans two classes, so file-level routing has been used as a practical holding parent.

Evidence against:

- `by-structure.md` says not to bypass the narrow class owner just to reach a file root.
- File-level ownership prevents direct class-owned C++ and obscures the vtable slots.

Decision:

- Correct source-file route and temporary aggregate owner. Not the final direct owner for the child method bodies.

### 3. [UID:00002K] `ClanStatusPane`

Evidence for:

- `g_pClanStatusPane` is loaded before calls to subtype-6 helpers.
- `ClanStatusPane` constructs/owns child panes at runtime.
- [UID:00021K] packet helpers are correctly owned by `ClanStatusPane`.

Evidence against:

- The incoming `this` for all three target functions is a list pane, not `ClanStatusPane`.
- Vtable refs point to `ClanJoinListPane`/`ClanEnlistListPane` tables.

Decision:

- Dependency and packet-helper receiver only. Reject as direct owner for `00021U` child methods.

### 4. `ListPane`

Evidence for:

- The handlers use inherited fields and call `ListPane::OnKeyEvent` / `GetSelectedEntry`.

Evidence against:

- The methods are derived overrides installed in Clan-specific vtables and send Clan packets.

Decision:

- Dependency/base class only. Reject as owner.

## First-Draft C++ Recommendation

Do not put this code into the current `00021U` aggregate block before splitting. After the child pages are created, the following first drafts are source-ready enough for their child `RECONSTRUCTION_CPP CODE` blocks. The `PaneKeyEvent`, `NarrowPaneKey`, and `kKeyEnter` spellings follow current generated/social UI style and may be mechanically renamed if the shared EventHandler declarations are later standardized.

### `0x00488900-0x00488968` `ClanJoinListPane::OnKeyEvent`

```cpp
bool ClanJoinListPane::OnKeyEvent(const PaneKeyEvent *event)
{
    if (ListPane::OnKeyEvent(event))
        return true;

    const unsigned char key =
        static_cast<unsigned char>(NarrowPaneKey(event->payload[0], event->keyState));

    const int selectedIndex = m_selectedIndex;
    if (selectedIndex < 0)
        return false;

    const wchar_t *selectedName =
        static_cast<const wchar_t *>(GetSelectedEntry(selectedIndex));
    if (key != kKeyEnter)
        return false;

    SendClanJoinListSelectionPacket(g_pClanStatusPane, selectedName);
    return true;
}
```

### `0x00488970-0x00488991` `ClanEnlistListPane::OnSelectedRowAction`

```cpp
int ClanEnlistListPane::OnSelectedRowAction()
{
    const int selectedIndex = m_selectedIndex;
    if (selectedIndex < 0)
        return selectedIndex;

    const wchar_t *applicantName =
        static_cast<const wchar_t *>(GetSelectedEntry(selectedIndex));
    return g_pClanStatusPane->SendClanEnlistListSelectionPacket(applicantName);
}
```

### `0x004889a0-0x00488b3d` `ClanEnlistListPane::OnKeyEvent`

```cpp
bool ClanEnlistListPane::OnKeyEvent(const PaneKeyEvent *event)
{
    if (ListPane::OnKeyEvent(event))
        return true;

    const unsigned char key =
        static_cast<unsigned char>(NarrowPaneKey(event->payload[0], event->keyState));

    const int selectedIndex = m_selectedIndex;
    if (selectedIndex < 0)
        return false;

    const wchar_t *applicantName =
        static_cast<const wchar_t *>(GetSelectedEntry(selectedIndex));

    if (key == kKeyEnter) {
        g_pClanStatusPane->SendClanEnlistListSelectionPacket(applicantName);
        return true;
    }

    constexpr unsigned char kClanEnlistListAction3Key = 0x84;
    if (key != kClanEnlistListAction3Key)
        return false;

    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(packet + 0, 0x4b);
    PacketBufferWriteUInt8(packet + 1, 0x06);
    PacketBufferWriteUInt8(packet + 2, 0x03);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, applicantName, wcslen(applicantName), convertedName, sizeof(convertedName), NULL, NULL);
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
    g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
    g_pClanStatusPane->SendClanEnlistListRefreshPacket();
    return true;
}
```

## Exact No-Code Proof For Current Aggregate

The current `00021U` aggregate should not receive formal C++ as one block because:

1. `0x00488900` is directly owned by [UID:00002H][ClanJoinListPane], while `0x00488970` and `0x004889a0` are directly owned by [UID:00002C][ClanEnlistListPane].
2. A single `CANONICAL_OWNER` cannot accurately represent both classes.
3. File-level [UID:0000I8][Clan] is the correct source route but not the narrow direct owner for these vtable methods.
4. The exact function starts and padding are already known, so a split has low risk and gives each child a proper owner/emitter route.
5. Populating the aggregate block now would either duplicate source after split or preserve the current overbroad owner shortcut.

This is a structural split-before-code blocker, not a behavioral reconstruction blocker.

## Exact Implementation Checklist For Accepted Callback

Preferred implementation is a child split, not a one-block C++ update to the current aggregate.

1. Preserve the current aggregate range as the evidence/index page:
   - Path: `by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md`.
   - Metadata after split: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000I8`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
   - Status text should say this is a mixed join/enlist Clan list-pane method index. It should explicitly list code children, padding gaps, vtable refs, no-direct-caller evidence, base `ListPane::OnKeyEvent`, `m_selectedIndex`, `GetSelectedEntry`, subtype `6` action `1`/inline action `3` packet behavior, `g_pClanStatusPane`, `g_packetSender`, and the unresolved user-facing meaning of key `0x84`.
   - Retain the no-code proof: the target spans `ClanJoinListPane` and `ClanEnlistListPane`, so source C++ belongs in child method pages with class owners.
2. Create child page `by-memory/0x00488900-0x00488968.ClanJoinListPaneOnKeyEvent.md`:
   - Metadata: `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:00002H`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002H`.
   - Source name/signature: `bool ClanJoinListPane::OnKeyEvent(const PaneKeyEvent *event)`.
   - Include first-draft C++ from this report. Document calls to `ListPane::OnKeyEvent`, `NarrowPaneKey`, `m_selectedIndex`, `GetSelectedEntry`, and [UID:00021G] `SendClanJoinListSelectionPacket`.
   - Record vtable-only slot `0x006157d4`, zero rel32/direct callers, and padding `0x00488968-0x00488970`.
3. Create child page `by-memory/0x00488970-0x00488991.ClanEnlistListPaneSelectedRowAction.md`:
   - Metadata: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:00002C`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002C`.
   - Source name/signature: `int ClanEnlistListPane::OnSelectedRowAction()`.
   - Include first-draft C++ from this report. Preserve the `int` return rationale: negative selected index is returned on the no-selection path and the helper result is preserved on the send path.
   - Record vtable-only slot `0x006158b0`, zero rel32/direct callers, selected-index/read helper evidence, and padding `0x00488991-0x004889a0`.
4. Create child page `by-memory/0x004889a0-0x00488b3d.ClanEnlistListPaneOnKeyEvent.md`:
   - Metadata: `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:00002C`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002C`.
   - Source name/signature: `bool ClanEnlistListPane::OnKeyEvent(const PaneKeyEvent *event)`.
   - Include first-draft C++ from this report, with the conservative constant name `kClanEnlistListAction3Key = 0x84` unless better UI/event evidence is found.
   - Document that Enter sends `ClanStatusPane::SendClanEnlistListSelectionPacket(applicantName)`, while key `0x84` sends inline opcode `0x4b`, subtype `6`, action `3`, length-prefixed converted selected name, then calls `ClanStatusPane::SendClanEnlistListRefreshPacket()`.
   - Preserve the terminator-not-sent behavior: both local zero terminators are stack-buffer/local string terminators outside the queued packet length.
5. Expose or preserve padding rows in coverage/support text:
   - `0x00488968-0x00488970`, `0x00488991-0x004889a0`, and successor `0x00488b3d-0x00488b40` remain `0xcc` alignment, not child code.
6. Update support docs:
   - `by-file/Clan.md`: replace the single `00021U` handler row with child method links once children exist; keep `social/Clan.cpp` source route.
   - `by-class/ClanJoinListPane.md`: replace key/event wording with `OnKeyEvent(const PaneKeyEvent *)` and link the new child; keep [UID:0002NR] selected-row action as sibling.
   - `by-class/ClanEnlistListPane.md`: replace stale "no split is justified" text with the accepted split-child policy; list `OnSelectedRowAction()` and `OnKeyEvent(const PaneKeyEvent *)` as child methods.
   - `by-class/ClanStatusPane.md`: add a consumer note that enlist selected-row/Enter paths call `SendClanEnlistListSelectionPacket`, while key `0x84` action `3` refreshes through `SendClanEnlistListRefreshPacket`.
   - `by-memory/0x00488610-0x004888f1.ClanListPaneVirtuals.md`: add a cross-note that the following [UID:00021U] aggregate should mirror this page's split-index policy.
   - `by-memory/0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers.md`: no rename required, but keep the call-site evidence from `0x00488970`, `0x00488aec`, and `0x00488b09`.
   - `by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md`: no immediate rename required; preserve both caller sites `0x004888ea` and `0x00488951`.
   - `by-memory/0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables.md` and `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`: no score change required, but the implementation callback may add cross-links if the new children need support references for `OnKeyEvent`, `m_selectedIndex`, and `GetSelectedEntry`.
7. If the supervisor chooses to defer the split, use the pre-split metadata row below (`86/91`, owner/emitter `0000I8`, blank C++) and explicitly document that C++ is blocked only by mixed-class ownership, not by stale below-95 code policy.

## Support Doc Recommendations

- Target `0x00488900-0x00488b3d.ClanListPaneInputHandlers.md`: replace `OnKeyOrMouseEvent` language with `OnKeyEvent`; record the split-before-code decision; close the open method-name question; retain only the `0x84` user-facing label caveat with the stronger `kClanEnlistListAction3Key` inference.
- [UID:00002H][ClanJoinListPane]: update method table from "key/event handler" to `OnKeyEvent`; if split is applied, link the new child page directly instead of routing through the mixed aggregate.
- [UID:00002C][ClanEnlistListPane]: update "no split justified" blocker text as stale; add `OnSelectedRowAction()` and `OnKeyEvent(const PaneKeyEvent*)` as exact child methods after split.
- [UID:00002K][ClanStatusPane]: no score change required; add a cross-note that the enlist-list selected-row and Enter paths call `SendClanEnlistListSelectionPacket`, while the `0x84` action-3 path refreshes through `SendClanEnlistListRefreshPacket`.
- [UID:0000I8][Clan]: change the `ClanJoinListPane`/`ClanEnlistListPane` rows to list the new child pages; keep `social/Clan.cpp` as the route.
- [UID:000194]/[UID:0003U2] `ListPane`: no required score change. Existing `ListPane::OnKeyEvent`, `m_selectedIndex`, and `GetSelectedEntry` names are sufficient evidence.
- [UID:00021G] `SendClanJoinListSelectionPacket`: no immediate rename required. `00021U` should continue to call the existing helper spelling until a dedicated join-list packet helper source-quality pass reclassifies it.
- [UID:00021K] `ClanEnlistListRefreshAndSelectionPacketHelpers`: no change required; current accepted helper names are validated by this pass.
- [UID:00021L] `ClanNameActionPacketHelpers`: keep separate from this target; `00021U` contains the live inline subtype `6`, action `3` path, while `00021L` remains raw/no-route duplicate-helper material.

## Exact Coverage Replacement Text

If the supervisor defers the split, replace only the existing `00021U` row with this immediate pre-split row:

```md
    - [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md) 0x00488900-0x00488b3d | mixed method cluster | ClanListPaneInputHandlers : reconstructable : 86% : strong : B015 2026-06-19 source-quality reanalysis confirms exact function ranges, vtable-only refs, no direct callers, `ListPane::OnKeyEvent` / `m_selectedIndex` / `GetSelectedEntry` roles, best child names `ClanJoinListPane::OnKeyEvent`, `ClanEnlistListPane::OnSelectedRowAction`, and `ClanEnlistListPane::OnKeyEvent`, subtype `6` action `1`/inline action `3` packet behavior, `g_pClanStatusPane`, `PacketBufferWriteUInt8`, `g_packetSender`, `memmove`, range-check, and non-sent terminator dependencies; current aggregate remains blank-C++ because it should be split into class-owned child pages before formal source emission.
```

Preferred post-split replacement block for the same coverage location, between the existing `0x004888f1-0x00488900` ignored row and [UID:00010J]:

```md
    - [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md) 0x00488900-0x00488b3d | mixed split index | ClanListPaneInputHandlers : not_reconstructable : 88% : strong : B015 2026-06-19 source-quality reanalysis reclassifies the aggregate as a non-emitting mixed join/enlist list-pane index after exact child split; child pages carry the class-owned source methods, while this parent records range, padding, vtable, event-narrowing, packet-helper, action `3`, and source-route evidence.
        - [TMP:"by-memory/0x00488900-0x00488968.ClanJoinListPaneOnKeyEvent.md"] 0x00488900-0x00488968 | virtual method | ClanJoinListPane::OnKeyEvent : reconstructable : 87% : strong : Derived `ListPane::OnKeyEvent` override at vtable slot `0x006157d4`; delegates to base key handler, narrows event bytes `+0x08/+0x10a`, checks inherited `m_selectedIndex`, fetches selected row through `GetSelectedEntry`, and sends the selected join-list row on Enter through `SendClanJoinListSelectionPacket`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00488968-0x00488970 | padding | ClanJoinListPaneOnKeyEvent/ClanEnlistListPaneSelectedRowAction alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes between the two IDA-modeled virtual method bodies.
        - [TMP:"by-memory/0x00488970-0x00488991.ClanEnlistListPaneSelectedRowAction.md"] 0x00488970-0x00488991 | virtual method | ClanEnlistListPane::OnSelectedRowAction : reconstructable : 88% : strong : Vtable slot `0x006158b0`; reads inherited `m_selectedIndex`, returns the negative index when no row is selected, fetches selected row through `GetSelectedEntry`, and preserves the return from `ClanStatusPane::SendClanEnlistListSelectionPacket(applicantName)`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00488991-0x004889a0 | padding | ClanEnlistListPaneSelectedRowAction/ClanEnlistListPaneOnKeyEvent alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes between the selected-row action and key-handler bodies.
        - [TMP:"by-memory/0x004889a0-0x00488b3d.ClanEnlistListPaneOnKeyEvent.md"] 0x004889a0-0x00488b3d | virtual method | ClanEnlistListPane::OnKeyEvent : reconstructable : 87% : strong : Derived `ListPane::OnKeyEvent` override at vtable slot `0x00615898`; Enter sends `ClanStatusPane::SendClanEnlistListSelectionPacket(applicantName)`, while key `0x84`/132 sends inline opcode `0x4b` subtype `6` action `3` selected-name packet through `g_packetSender` and then calls `ClanStatusPane::SendClanEnlistListRefreshPacket`; user-facing `0x84` label remains intentionally unresolved.
```

If the preferred block is applied, also keep or expose the existing [UID:0000VN] successor padding row for `0x00488b3d-0x00488b40` before [UID:00010J] if the coverage format requires every padding span to be separately visible after the parent stops covering bytes.

## Recommended Metadata Changes

Pre-split target-only metadata:

```text
COMPLETION:86
CONFIDENCE:91
CANONICAL_OWNER:0000I8
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000I8
RECONSTRUCTION_CPP CODE: blank
```

Preferred post-split parent metadata:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:0000I8
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE: blank
```

Preferred child metadata:

```text
0x00488900-0x00488968.ClanJoinListPaneOnKeyEvent.md:
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:00002H
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00002H

0x00488970-0x00488991.ClanEnlistListPaneSelectedRowAction.md:
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:00002C
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00002C

0x004889a0-0x00488b3d.ClanEnlistListPaneOnKeyEvent.md:
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:00002C
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00002C
```

## IDA Rename / Type / Comment Recommendations

Use descriptive IDA names as evidence aids only; do not let generated raw labels leak into source-facing docs.

| Address / item | Recommended IDA action | Confidence / caveat |
| --- | --- | --- |
| `0x00488900` | Rename `sub_488900` to `ClanJoinListPane__OnKeyEvent`. Type as `bool __thiscall ClanJoinListPane::OnKeyEvent(ClanJoinListPane *this, const PaneKeyEvent *event)`. | High for class and role; `PaneKeyEvent` field names remain descriptive until the shared event struct is finalized. |
| `0x00488970` | Rename `sub_488970` to `ClanEnlistListPane__OnSelectedRowAction`. Type as `int __thiscall ClanEnlistListPane::OnSelectedRowAction(ClanEnlistListPane *this)`. | High. Keep `int` return unless later vtable declaration proof shows the return is ignored. |
| `0x004889a0` | Rename `sub_4889A0` to `ClanEnlistListPane__OnKeyEvent`. Type as `bool __thiscall ClanEnlistListPane::OnKeyEvent(ClanEnlistListPane *this, const PaneKeyEvent *event)`. | High for role; key `0x84` user-facing label remains unresolved. |
| `0x004f4300` | If not already named, use `ListPane__OnKeyEvent`. | High, supported by [UID:0003U2]. |
| `0x004f3dc0` | If not already named, use `ListPane__GetSelectedEntry`. Return should be documented as selected row payload/text pointer; this target treats it as `const wchar_t *`. | High for role, medium for exact return typedef. |
| `0x00485590` | Keep or rename to `SendClanJoinListSelectionPacket`. | High for packet layout and callers; direct owner/name could be refined by a dedicated [UID:00021G] pass. |
| `0x00485960` | Rename/comment as `ClanStatusPane__SendClanEnlistListRefreshPacket`. | High after [UID:00021K] reanalysis and call sites. |
| `0x004859d0` | Rename/comment as `ClanStatusPane__SendClanEnlistListSelectionPacket`. | High after [UID:00021K] reanalysis; parameter is selected enlist/applicant wide string. |
| `0x0067ade4` | Name as `g_pClanStatusPane` if not already applied. | High; part of [UID:0002B5]. |
| `0x0067a7ec` | Name as `g_packetSender` / `Socket *g_packetSender`; suppress generated `g_pCashShopRequest` aliasing. | High for current project docs; final typedef/interface caveat belongs in Socket/global docs. |
| `0x006157d4`, `0x006158b0`, `0x00615898` | Add vtable comments pointing to the three methods above. | High. These are the only current pointer hits for the starts. |
| `0x00488a2e-0x00488ae5` inline branch | Add a function comment that key `0x84` serializes opcode `0x4b`, subtype `6`, action `3`, selected-name length/payload, and sends only `convertedLength + 4` bytes. | High for protocol bytes; unknown for user-facing key label. |
| local buffers in `0x004889a0` | Comment `convertedName[256]` and `packet[128]`, including `<0x100` conversion and `<0x80` packet-length range guards. | High from stack sizes/range checks. |

## Validation Commands Recommended

This report-only pass did not run documentation validators because no by-* files were edited. For an accepted implementation callback, run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00021U-ClanListPaneInputHandlers-source-quality-removed.md](00021U-ClanListPaneInputHandlers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the split is accepted, also validate each new child page immediately after creation:

> Executable block R002 was removed from this report and preserved verbatim in [00021U-ClanListPaneInputHandlers-source-quality-removed.md](00021U-ClanListPaneInputHandlers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: all edited/new files validate cleanly; autogen should route the child emitters through `ClanJoinListPane` / `ClanEnlistListPane` into `social/Clan.cpp`, while the parent `00021U` remains a non-emitting index if the preferred split is applied.

## Evidence Standards Used

- Existing supervisor-executed support docs, including the accepted [UID:00021K] helper rename and current `Clan`, `ClanJoinListPane`, `ClanEnlistListPane`, `ClanStatusPane`, `ListPane`, packet helper, sender/global, and memory-copy docs.
- Direct raw PE revalidation of `NexusTK.exe` for alignment bytes, rel32 call refs, intra-function call targets, and vtable pointer hits.
- Generated source style from `project-documentation/auto-generated/NexusTK/social/Clan.cpp`, `Chatting.cpp`, `FittingRoom.cpp`, `CommandInputPanes.cpp`, and `SpellInputPanes.cpp`.
- `rg` searches over project docs for `0x84` and related action-3 wording. The search found no safe user-facing `0x84` label for this target.
- `tools/int_convert.py` for constants: `0x4b` = 75 / ASCII `K`, `0x84` = 132, `0x0d` = 13, `0x100` = 256, `0x80` = 128, `0x134` = 308, `0x10a` = 266, function sizes `0x68` = 104, `0x21` = 33, and `0x19d` = 413.

## Final Confidence

The split/source-shape recommendation is high confidence. The remaining uncertainty is not range, owner, packet layout, or call behavior; those are strongly supported. The only meaningful unresolved source-quality point is the user-facing meaning of key `0x84`. That uncertainty should cap the affected child below final-audit levels but should not prevent split child first-draft C++ using a conservative action-3 key constant.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/00021U-ClanListPaneInputHandlers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"00021U"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00021U-ClanListPaneInputHandlers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/00021U-ClanListPaneInputHandlers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00021U"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
