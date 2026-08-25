** TARGET-REPORT-UID:0002KE **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002KE] ParcelPaneOnMouseEvent source-quality report

**Agent:** B002  
**Mode:** Report-only research pass  
**Target:** `by-memory/0x00546610-0x00546807.ParcelPaneOnMouseEvent.md`  
**Required output:** `tools/leaser/Agents/Agent-B002/research/0002KE-ParcelPaneOnMouseEvent-source-quality.md`  
**Status:** Implementation-ready report; no by-* edits made.

## Current State

Target header before implementation:

- `COMPLETION: 85`
- `CONFIDENCE: 88`
- `CANONICAL_OWNER: 0000A6`
- `RECONSTRUCTABLE: TRUE`
- `EMITTER_UIDS: 0000A6`
- `RECONSTRUCTION_CPP:` blank

The existing target page already identifies the range as the ParcelPane secondary-vtable mouse callback and records the major behavior: event types `0`, `1`, and `3`; `g_packetSender`; packet byte `0x41`; `BulletinSession`; state bytes `+0xfc/+0xfd`; acknowledgment bytes `+0x120/+0x121`; and the secondary-this owner adjustment. The remaining source-quality gaps are narrower than the current score implies:

- The callback has enough evidence for a source-facing `ParcelPane::OnMouseEvent` first-draft C++ body.
- `sub_4B7E80` should be referenced as the existing geometry helper `PointInRect`, not as a ParcelPane-local hit-test helper.
- `sub_4F4AA0` should be represented as global `operator new`/MemoryMan allocation through the source expression `new BulletinSession(...)`, not as a manual helper call.
- `sub_574BB0` should be represented as `Socket::QueueAndSendPacket`, with the left action byte preserved as literal `0x41` because no source enum/symbol name was proven.
- The existing behavior table should be corrected so the hover/move branch explicitly checks the right slot before the left slot and does not reset button states when the cursor remains inside the pane but outside both slot rectangles.

Recommended target metadata after implementation:

- `COMPLETION: 91`
- `CONFIDENCE: 91`
- `CANONICAL_OWNER: 0000A6`
- `EMITTER_UIDS: 0000A6`
- `RECONSTRUCTABLE: TRUE`
- Add the formal C++ body below.

Do not raise higher than `91/91` in this callback: the behavior is source-ready, but original source names for the `0x41` parcel packet action and the three `BulletinSession` constructor arguments are still not independently proven.

## MCP Evidence

IDA MCP was mandatory for this report and was used. Endpoint checked: `http://127.0.0.1:13337/mcp`.

Revision pass availability check on 2026-06-26: a lightweight JSON-RPC `tools/list` call against `http://127.0.0.1:13337/mcp` succeeded before this acceptance-blocker update. No fallback-only evidence was used.

Session and health evidence:

- `idb_list` succeeded on retry after one timeout.
- Active database session: `80de0a67`.
- Input IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Filename: `NexusTK.exe.i64`.
- `is_active: true`.
- `is_analyzing: false`.
- Backend: `worker`.
- Worker PID: `26892`.
- `server_health` reported `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready: true`, `hexrays_ready: true`, and `strings_cache_ready: true`.
- Listener/process status during retry: port `127.0.0.1:13337` had listener PID `13684`; process list included `idalib-mcp` PID `17084`, listener `python` PID `13684`, and worker `python` PID `26892`.

Function lookup evidence:

- `0x00546610 -> sub_546610`, size `0x1f7` / 503 bytes. Decimal verified with `int_convert.py`.
- `0x00546807` is not a function; it is the end address before padding.
- `0x00546810 -> sub_546810`, next function.
- `0x00621c90`, `0x00621c94`, and `0x00621c98` are data/vtable entries, not functions.
- `0x004b7e80 -> sub_4B7E80`, size `0x27` / 39 bytes. Decimal verified with `int_convert.py`.
- `0x004f4aa0 -> sub_4F4AA0`, size `0x14` / 20 bytes. Decimal verified with `int_convert.py`.
- `0x00574bb0 -> sub_574BB0`, size `0x63` / 99 bytes. Decimal verified with `int_convert.py`.
- `0x00471150 -> sub_471150`, size `0x11c` / 284 bytes. Decimal verified with `int_convert.py`.

Boundary and vtable evidence:

- Bytes at `0x00546600` show the previous function ending with `5d c2 04 00`, followed by `0xcc` padding before the target prologue.
- Bytes at `0x00546800` show the target ending with `5d c2 04 00`, then `0xcc` padding at `0x00546807-0x00546810`, then the next function prologue at `0x00546810`.
- Bytes at `0x00621c90` decode as vtable entries:
  - `0x00621c90 -> 0x00546eb7` secondary destructor adjustor.
  - `0x00621c94 -> 0x00546610` target mouse-event slot.
  - `0x00621c98 -> 0x005465e0` neighboring key-event slot.

Target analysis evidence:

- `analyze_function 0x00546610` reported prototype-like output `char __thiscall(int this, int)`, size 503 bytes, 40 basic blocks, cyclomatic complexity 21.
- The only direct xref to the function entry is the data xref at `0x00621c94`, matching the ParcelPane secondary vtable slot.
- Callees are `sub_4B7E80`, `sub_574BB0`, `sub_4F4AA0`, `sub_471150`, and the security-cookie check.

Decoded target behavior from MCP decompile/disassembly:

- The callback receives the ParcelPane secondary-subobject `this`; the owner object is `this - 0xa0` / 160 bytes. Decimal verified with `int_convert.py`.
- It reads the event object as:
  - event type byte at `event + 4`.
  - x coordinate signed 16-bit value at `event + 8`.
  - y coordinate signed 16-bit value at `event + 12`.
- Decompiler offsets relative to secondary `this` normalize to accepted ParcelPane owner fields:
  - `this + 0x5c` -> owner `+0xfc` / `m_leftButtonState`.
  - `this + 0x5d` -> owner `+0xfd` / `m_rightButtonState`.
  - `this + 0x59` -> owner `+0xf9` / `m_leftParcelCount`.
  - `this + 0x5b` -> owner `+0xfb` / `m_rightSlotActionEnabled`.
  - `this + 0x60` -> owner `+0x100` / `m_leftButtonRect`.
  - `this + 0x70` -> owner `+0x110` / `m_rightButtonRect`.
  - `this + 0x80` -> owner `+0x120` / `m_leftSlotAcknowledged`.
  - `this + 0x81` -> owner `+0x121` / `m_rightSlotAcknowledged`.
  - `this - 0x5c` -> owner `+0x44` / Pane bounds rectangle.
- Event type `0` is the hover/move branch:
  - If the cursor is outside the pane bounds, non-animating left/right states are reset to idle and the callback returns false.
  - If inside the pane bounds, it checks the right button rect first, idles the left state unless it is animating, and sets the right state to hover unless it is pressed.
  - It then checks the left button rect, idles the right state unless it is animating, and sets the left state to hover unless it is pressed.
  - It returns true for any cursor position inside the pane bounds, including positions outside both slot rectangles.
- Event type `1` is the press branch:
  - If outside pane bounds, return false.
  - If inside right rect, set right state to pressed.
  - If inside left rect, set left state to pressed.
  - Return true for any cursor position inside pane bounds.
- Event type `3` is the release/action branch:
  - If outside pane bounds, return false.
  - Clear both button states to idle.
  - If inside the left rect, set left state to hover. If `m_leftParcelCount != 0`, send one byte `0x41` through `g_packetSender->QueueAndSendPacket(..., 1)` and set `m_leftSlotAcknowledged = true`.
  - If inside the right rect, set right state to hover. If `m_rightSlotActionEnabled` is true and `g_pBulletinSession == nullptr`, allocate/construct `BulletinSession(1, 0, true)` and set `m_rightSlotAcknowledged = true`.
  - Return true.
- Any other event type returns false.

Helper evidence:

- `sub_4B7E80` decompiles to a pure half-open rectangle test:

```cpp
return rect->left <= y && y < rect->right && rect->top <= x && x < rect->bottom;
```

The accepted support page `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` names this function `PointInRect` and records broad UI/render fan-in. MCP `xrefs_to 0x004b7e80` hit the result limit with more than 20 code xrefs. This is a generic geometry helper, not a ParcelPane-owned helper.

- `sub_4F4AA0` calls `GetMemoryMan` and `AllocateBufferMemory`; the accepted support page `by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md` identifies it as the global `operator new` wrapper. MCP `xrefs_to 0x004f4aa0` hit the result limit with more than 20 code xrefs. In source reconstruction it should be represented as `new BulletinSession(1, 0, true)`.

- `sub_4F4AC0` appears only in the target's exception/unwind cleanup funclet for failed `BulletinSession` construction. It is the paired global delete/operator-delete wrapper and should not be written into source-level ParcelPane logic.

- `sub_574BB0` is the accepted `Socket::QueueAndSendPacket(const void *packetData, short packetSize)` funnel. MCP `xrefs_to 0x00574bb0` hit the result limit with more than 20 code xrefs, confirming it is a generic sender. The target uses it through `g_packetSender` with packet size `1` and packet byte `0x41`.

- `sub_471150` is the `BulletinSession` constructor. MCP xrefs show six code callers, including the target at `0x00546718`. In the target the arguments are `(1, 0, 1)`, source-facing as `new BulletinSession(1, 0, true)`.

Global evidence:

- `0x0067a7ec` is `g_packetSender` per accepted global/support docs; MCP showed broad data xrefs and the target read at the packet-send call.
- `0x0067adc0` is `g_pBulletinSession` per accepted global/support docs; MCP `xrefs_to 0x0067adc0` included constructor writes, cleanup clears, consumers, and target read at `0x005466e8`.

## Cross-Document Evidence

Accepted/strong support pages already provide most names needed for implementation:

- `by-class/ParcelPane.md` has the accepted field layout and `ParcelButtonState` values:
  - idle `0`
  - hover `1`
  - pressed `2`
  - animating `3`
- `by-type/by-struct/ParcelNotificationPaneLayouts.md` confirms the secondary callback owner adjustment `this == owner + 0xa0`, and the field names used by this function:
  - `m_leftParcelCount`
  - `m_rightSlotActionEnabled`
  - `m_leftButtonState`
  - `m_rightButtonState`
  - `m_leftButtonRect`
  - `m_rightButtonRect`
  - `m_leftSlotAcknowledged`
  - `m_rightSlotAcknowledged`
- `by-type/by-vtable/ParcelNotificationVtableFamily.md` and `by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md` place `0x00546610` at the ParcelPane secondary vtable mouse-event slot `0x00621c94`.
- `by-file/ParcelPane.md` assigns exact ParcelPane methods to the source root `NexusTK/ui/panels/ParcelPane.cpp`; the broad aggregate [UID:0001EH] is a non-emitting source-family index after the executed B007 report.
- Executed B001 slot-animation research supports the `ParcelButtonState` names and the sibling animation helpers, but does not replace this function's MCP proof.
- `by-memory/0x00546890-0x0054696f.ParcelPaneOnPaint.md` already uses the same field names and sibling frame-index helper in first-draft C++.
- `by-memory/0x00546290-0x005464aa.ParcelPaneConstructor.md` initializes the relevant fields and schedules the timer.
- `by-memory/0x005464b0-0x005465d9.ParcelPaneSetParcelSlotData.md` clears the left/right acknowledgment bytes when parcel counts change.
- `by-memory/0x005465e0-0x00546605.ParcelPaneOnKeyDown.md` is the neighboring secondary input callback and supports the same secondary-vtable/event-object context, but remains its own target and should not be rewritten for this callback.

## Positive Evidence

- Exact function boundary is proven by MCP function lookup, disassembly, and padding before/after the range.
- Exact vtable slot is proven by bytes at `0x00621c90` and the sole data xref from `0x00621c94`.
- Source owner route is coherent:
  - Class owner: `ParcelPane`.
  - Source file: `NexusTK/ui/panels/ParcelPane.cpp`.
  - Emitting owner/file UID remains `0000A6`.
  - Broad parcel-notification aggregate [UID:0001EH] is non-emitting and should not replace this exact child target.
- Field names are no longer heuristic for this function; they match accepted class/layout docs and direct secondary-this offset normalization.
- The helper names are not local guesses:
  - `PointInRect` is supported by the RectGeometryHelpers page and broad fan-in.
  - `operator new`/MemoryMan allocation is supported by the OperatorNewWrapper page and broad fan-in.
  - `Socket::QueueAndSendPacket` and `g_packetSender` are supported by accepted Socket/global docs.
  - `g_pBulletinSession` and `BulletinSession` construction are supported by accepted BulletinSession/global docs.
- The target's full behavior can be reconstructed without decompiler temporaries, raw helper names, or unresolved ownership.

## Negative Evidence And Limits

- No source symbol was found for the one-byte left-slot packet action `0x41`. It should be described as the left-slot parcel action/request byte and kept as a literal in the first-draft C++ rather than promoted to an unsupported enum name.
- No independent source names were proven for the three `BulletinSession` constructor arguments `(1, 0, true)`. The first-draft C++ should preserve the argument values rather than inventing symbolic names.
- The source event type names are inferred from branch behavior and established UI callback pattern. `kPaneMouseMove`, `kPaneMouseDown`, and `kPaneMouseUp` are suitable formal names, but the raw values must remain recorded as `0`, `1`, and `3`.
- The target contains SEH/unwind cleanup around `BulletinSession` construction, but this is compiler-generated support for the source-level `new BulletinSession(...)` expression. It should not become explicit source code in `ParcelPane::OnMouseEvent`.
- The hover/move branch's "inside pane but outside both slot rectangles" behavior is unusual but directly supported by MCP: it returns true and leaves states unchanged. Do not simplify it into an else-reset.

## Heuristic And Inference Reanalysis

Rejected weaker interpretations:

- `sub_4B7E80` as `ParcelPaneHitTest*`: rejected. MCP and support docs show a generic half-open rectangle helper with broad UI/render fan-in.
- `sub_4F4AA0` as a ParcelPane allocation helper: rejected. MCP and support docs show global `operator new`/MemoryMan allocation.
- `sub_574BB0` as a parcel-specific send routine: rejected. It is the generic Socket send funnel; the parcel-specific part in this target is only the one-byte payload `0x41`.
- Raw secondary `this + 0x5c`/`+0x5d` field names: rejected. Layout docs and `this - 0xa0` normalization prove owner fields `+0xfc/+0xfd`.
- Treating `+0x120/+0x121` as generic consumed flags: weaker. Existing layout and SetParcelSlotData support the clearer names `m_leftSlotAcknowledged` and `m_rightSlotAcknowledged`.
- Manual source calls to `operator new`, constructor, and operator delete: rejected. Disassembly shows compiler output for a normal `new BulletinSession(1, 0, true)` expression with cleanup.

Source-ready inferences that should be used:

- Source signature: `bool ParcelPane::OnMouseEvent(const PaneMouseEvent& event)`.
- Helper call form: `PointInRect(event.x, event.y, &rect)`.
- Packet call form: `g_packetSender->QueueAndSendPacket(&packet, 1)`.
- Right-slot action form: `new BulletinSession(1, 0, true)`.
- State enum names: `kParcelButtonIdle`, `kParcelButtonHover`, `kParcelButtonPressed`, `kParcelButtonAnimating`, matching accepted values `0`, `1`, `2`, `3`.

## Owner And Source Disposition

Ranked disposition:

1. **ParcelPane / UID 0000A6 / `NexusTK/ui/panels/ParcelPane.cpp` / emitting exact child.** This is the correct owner and emitter. The function is a ParcelPane secondary-vtable input callback with exact class fields, sibling callbacks, and direct vtable slot evidence.
2. **Parcel notification aggregate [UID:0001EH] / non-emitting source-family index.** Useful for grouping, not for ownership override.
3. **RectGeometryHelpers / MemoryMan / Socket / BulletinSession support owners.** These own helper implementations called by the target. They do not own this callback.
4. **No-owner/raw-helper disposition.** Rejected. The target has a source class, source file, exact owner route, and source-ready body.

No split/range change is recommended.

## Recommended Target Update

Update `by-memory/0x00546610-0x00546807.ParcelPaneOnMouseEvent.md` to:

- Raise metadata to `COMPLETION: 91`, `CONFIDENCE: 91`.
- Keep `CANONICAL_OWNER: 0000A6`, `EMITTER_UIDS: 0000A6`, and `RECONSTRUCTABLE: TRUE`.
- Insert the exact formal `RECONSTRUCTION_CPP CODE` block below; this is target insertion content, not illustrative sample code.
- Replace the target `Item Summary`; the current summary is stale because it still says helper/action names remain provisional and describes `+0x120/+0x121` as consumed bytes. Use this exact replacement:

```text
*** Item Summary: MCP-backed ParcelPane secondary mouse-event virtual at `0x00621c94`; formal `ParcelPane::OnMouseEvent(const PaneMouseEvent& event)` covers event type `0/1/3` move/press/release behavior, `PointInRect` hit tests, normalized owner offsets, left action byte `0x41` sent through `g_packetSender->QueueAndSendPacket`, right `new BulletinSession(1, 0, true)` gate through `g_pBulletinSession`, and acknowledgment bytes `+0x120/+0x121`; packet byte and constructor argument symbol names remain intentionally literal. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Rewrite the behavior table to reflect:
  - Event type `0` move/hover: outside pane clears non-animating states and returns false; inside pane checks right rect then left rect; inside but no slot still returns true and leaves states unchanged.
  - Event type `1` press: inside right/left rect sets pressed state; inside pane returns true even if neither slot hit.
  - Event type `3` release/action: inside pane clears both states, left rect can send packet byte `0x41` and set left acknowledgment, right rect can open `BulletinSession` and set right acknowledgment.
- Replace raw helper/decompiler names with:
  - `PointInRect`
  - `g_packetSender->QueueAndSendPacket`
  - `new BulletinSession(1, 0, true)`
  - `g_pBulletinSession`
- Preserve a note that the packet action byte and `BulletinSession` constructor argument names are not yet symbolically proven.

## RECONSTRUCTION_CPP CODE

Exact formal target insertion content. The marker lines are included to identify the target formal field; during implementation, keep the target's existing `BEGIN`/`END` marker lines and place the function body between them.

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ParcelPane::OnMouseEvent(const PaneMouseEvent& event)
{
    const int x = event.x;
    const int y = event.y;

    switch (event.type) {
    case kPaneMouseMove:
        if (!PointInRect(x, y, &m_bounds)) {
            if (m_leftButtonState != kParcelButtonAnimating) {
                m_leftButtonState = kParcelButtonIdle;
            }
            if (m_rightButtonState != kParcelButtonAnimating) {
                m_rightButtonState = kParcelButtonIdle;
            }
            return false;
        }

        if (PointInRect(x, y, &m_rightButtonRect)) {
            if (m_leftButtonState != kParcelButtonAnimating) {
                m_leftButtonState = kParcelButtonIdle;
            }
            if (m_rightButtonState != kParcelButtonPressed) {
                m_rightButtonState = kParcelButtonHover;
            }
        }

        if (PointInRect(x, y, &m_leftButtonRect)) {
            if (m_rightButtonState != kParcelButtonAnimating) {
                m_rightButtonState = kParcelButtonIdle;
            }
            if (m_leftButtonState != kParcelButtonPressed) {
                m_leftButtonState = kParcelButtonHover;
            }
        }
        return true;

    case kPaneMouseDown:
        if (!PointInRect(x, y, &m_bounds)) {
            return false;
        }
        if (PointInRect(x, y, &m_rightButtonRect)) {
            m_rightButtonState = kParcelButtonPressed;
        }
        if (PointInRect(x, y, &m_leftButtonRect)) {
            m_leftButtonState = kParcelButtonPressed;
        }
        return true;

    case kPaneMouseUp:
        if (!PointInRect(x, y, &m_bounds)) {
            return false;
        }

        m_leftButtonState = kParcelButtonIdle;
        m_rightButtonState = kParcelButtonIdle;

        if (PointInRect(x, y, &m_leftButtonRect)) {
            m_leftButtonState = kParcelButtonHover;
            if (m_leftParcelCount != 0) {
                unsigned char packet = 0x41;
                g_packetSender->QueueAndSendPacket(&packet, 1);
                m_leftSlotAcknowledged = true;
            }
        }

        if (PointInRect(x, y, &m_rightButtonRect)) {
            m_rightButtonState = kParcelButtonHover;
            if (m_rightSlotActionEnabled && g_pBulletinSession == nullptr) {
                new BulletinSession(1, 0, true);
                m_rightSlotAcknowledged = true;
            }
        }
        return true;

    default:
        return false;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Support Document Updates

Callback-safe support disposition:

| Support doc | Callback action | Exact disposition |
| --- | --- | --- |
| `by-class/ParcelPane.md` | Inspect, then edit only if weaker. | If the method row/open notes do not identify [UID:0002KE] as source-ready `ParcelPane::OnMouseEvent(const PaneMouseEvent& event)` at `91/91` with `PointInRect`, `Socket::QueueAndSendPacket`, `g_packetSender`, `g_pBulletinSession`, and `new BulletinSession(1, 0, true)` no longer unresolved for this method, edit those lines. If already equal/stronger, mark already present. Leave class-level score unchanged. |
| `by-file/ParcelPane.md` | Inspect, then edit only if weaker. | If the [UID:0002KE] child row/evidence does not reflect source-ready `ParcelPane::OnMouseEvent` and the formal C++ route through `NexusTK/ui/panels/ParcelPane.cpp`, edit that row/evidence note. If already equal/stronger, mark already present. Leave file-level score unchanged and preserve the B007 aggregate/non-emitting disposition. |
| `by-type/by-struct/ParcelNotificationPaneLayouts.md` | Inspect, then edit only if weaker. | If it does not connect [UID:0002KE] to `m_leftSlotAcknowledged` and `m_rightSlotAcknowledged` being set by left packet action/right BulletinSession action while `SetParcelSlotData` clears them on count changes, add that support note. If already equal/stronger, mark already present. No score change. |
| `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` | Inspect/mark already-present; leave untouched unless contradiction. | It already names `sub_4B7E80` as `PointInRect` and records broad fan-in. Do not edit unless a direct contradiction is found. |
| `by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md` | Inspect/mark already-present; leave untouched unless contradiction. | It already names `sub_4F4AA0` as global `operator new`/MemoryMan allocation. Do not edit unless a direct contradiction is found. |
| `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md` | Inspect/mark already-present; leave untouched unless contradiction. | It already names `Socket::QueueAndSendPacket`. Do not edit unless a direct contradiction is found. |
| `by-global/g_packetSender.md` | Inspect/mark already-present; leave untouched unless contradiction. | It already supports `Socket *g_packetSender`. Do not edit unless a direct contradiction is found. |
| `by-global/g_pBulletinSession.md` | Inspect/mark already-present; leave untouched unless contradiction. | It already supports `BulletinSession *g_pBulletinSession`. Do not edit unless a direct contradiction is found. |
| `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md` | Inspect/mark already-present; leave untouched unless contradiction. | It already supports the `BulletinSession` constructor/publication route used by this target. Do not edit unless a direct contradiction is found. |
| `by-class/BulletinSession.md` | Inspect/mark already-present; leave untouched unless contradiction. | It already supports the `BulletinSession` class route. Do not edit unless a direct contradiction is found. |
| `by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md` | Leave untouched unless contradiction. | Sibling input callback; no edit for this report unless direct contradiction to the OnMouseEvent source/event route is found. |
| `by-memory/0x00546810-0x00546888.ParcelPaneProcessSlotAnimations.md` | Leave untouched unless contradiction. | Sibling animation callback; no edit for this report unless direct contradiction to `ParcelButtonState` usage is found. |
| `by-memory/0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter.md` | Leave untouched unless contradiction. | Sibling animation helper; no edit for this report unless direct contradiction to `ParcelButtonState` usage is found. |
| `by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md` | Leave untouched unless contradiction. | Sibling frame-index helper; no edit for this report unless direct contradiction to `ParcelButtonState` usage is found. |

Manual/project-level/generated/tool-state/IDA DB files must not be edited by B002.

## Implementation Checklist

When supervisor validation accepts this report and issues an implementation callback:

- [x] Lease only the by-* file(s) that will be edited immediately, then release the leases immediately after the edit/validator batch.
  - Proof: B002 leased the four immediate edit files only: `by-memory/0x00546610-0x00546807.ParcelPaneOnMouseEvent.md`, `by-class/ParcelPane.md`, `by-file/ParcelPane.md`, and `by-type/by-struct/ParcelNotificationPaneLayouts.md`.
  - Release proof: after the edit/validator batch, `python .\tools\leaser\leaser.py B002 unlease ...` returned `Rejected[No active lease]` for those four paths; `tools/leaser/Agents/current_leases.md` then showed no B002 active leases.
- [x] Update `by-memory/0x00546610-0x00546807.ParcelPaneOnMouseEvent.md` metadata to `91/91`.
  - Proof: target header now has `COMPLETION:91` and `CONFIDENCE:91`; scoped validator command `000000003201` reported `ok: 1`.
- [x] Replace the stale target `Item Summary` with the exact `Item Summary` line from this report.
  - Proof: target summary now identifies the MCP-backed secondary mouse-event virtual, vtable slot `0x00621c94`, formal `ParcelPane::OnMouseEvent(const PaneMouseEvent& event)`, event types `0/1/3`, `PointInRect`, packet byte `0x41`, right `new BulletinSession(1, 0, true)`, and acknowledgment bytes `+0x120/+0x121`; validator `000000003201` reported `ok: 1`.
- [x] Insert the exact C++ function body shown between this report's `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` marker lines into the target's formal `RECONSTRUCTION_CPP CODE` section.
  - Proof: formal C++ was inserted between the existing target markers with signature `bool ParcelPane::OnMouseEvent(const PaneMouseEvent& event)`, no stale helper names, left packet byte `0x41`, and right `new BulletinSession(1, 0, true)`; validator `000000003201` reported `ok: 1`.
- [x] Update the target evidence/body text to preserve the MCP session evidence, vtable-slot evidence, helper naming, secondary-this owner adjustment, event type behavior, packet byte `0x41`, `BulletinSession` construction, and acknowledgment-byte details at report-level detail.
  - Proof: target now records MCP session `80de0a67`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend worker PID `26892`, exact range `0x00546610-0x00546807`, vtable slot `0x00621c94`, secondary-this `+0xa0` normalization, helper dispositions, literal naming limits, and target-level changes entry; validator `000000003201` reported `ok: 1`.
- [x] Correct the target behavior table for hover/move ordering and the inside-pane/no-slot-hit return behavior.
  - Proof: target table now states outside-pane move clears non-animating states and returns false, inside-pane move checks right before left, inside/no-slot returns true with no state change, press inside/no-slot returns true, and release/action clears both states before left/right action checks; validator `000000003201` reported `ok: 1`.
- [x] Inspect `by-class/ParcelPane.md`; edit only if weaker as specified in the support table, otherwise check as already present at same-or-greater detail. Leave class-level score unchanged.
  - Proof: edited because the method row/open notes were weaker; [UID:0002KE] now appears as source-ready `91/91` with `PointInRect`, `Socket::QueueAndSendPacket`, `g_packetSender`, `g_pBulletinSession`, and `new BulletinSession(1,0,true)` no longer unresolved for this method. Class-level score was left unchanged. Validator `000000003202` reported `ok: 1`.
- [x] Inspect `by-file/ParcelPane.md`; edit only if weaker as specified in the support table, otherwise check as already present at same-or-greater detail. Leave file-level score unchanged.
  - Proof: edited because file-level evidence was weaker; the file doc now records [UID:0002KE] as source-ready `ParcelPane::OnMouseEvent` through `NexusTK/ui/panels/ParcelPane.cpp` while preserving the B007 aggregate/non-emitting disposition and file-level score. Validator `000000003203` reported `ok: 1`.
- [x] Inspect `by-type/by-struct/ParcelNotificationPaneLayouts.md`; edit only if weaker as specified in the support table, otherwise check as already present at same-or-greater detail. No score change.
  - Proof: edited because the acknowledgment-byte action-side details were weaker; the struct doc now connects [UID:0002KE] to `m_leftSlotAcknowledged` and `m_rightSlotAcknowledged` being set by the left packet/right BulletinSession actions while `SetParcelSlotData` clears them on count changes. Validator `000000003204` reported `ok: 1`.
- [x] Inspect/mark already-present `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`; leave untouched unless direct contradiction is found.
  - Proof: inspected and already present at same-or-greater detail; it names `PointInRect` at `0x004b7e80` and records broad fan-in. No contradiction; untouched.
- [x] Inspect/mark already-present `by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md`; leave untouched unless direct contradiction is found.
  - Proof: inspected and already present at same-or-greater detail; it names `sub_4F4AA0` as global `operator new`/MemoryMan allocation. No contradiction; untouched.
- [x] Inspect/mark already-present `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`; leave untouched unless direct contradiction is found.
  - Proof: inspected and already present at same-or-greater detail; it records source-facing `Socket::QueueAndSendPacket(const void *packetData, short packetSize)`. No contradiction; untouched.
- [x] Inspect/mark already-present `by-global/g_packetSender.md`; leave untouched unless direct contradiction is found.
  - Proof: inspected and already present at same-or-greater detail; it supports `Socket *g_packetSender` and rejects the weaker CashShopRequest alias. No contradiction; untouched.
- [x] Inspect/mark already-present `by-global/g_pBulletinSession.md`; leave untouched unless direct contradiction is found.
  - Proof: inspected and already present at same-or-greater detail; it supports `BulletinSession *g_pBulletinSession` and records the consumer at `0x005466e8`. No contradiction; untouched.
- [x] Inspect/mark already-present `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md`; leave untouched unless direct contradiction is found.
  - Proof: inspected and already present at same-or-greater detail; it records constructor/publication support and caller `0x00546718`. No contradiction; untouched.
- [x] Inspect/mark already-present `by-class/BulletinSession.md`; leave untouched unless direct contradiction is found.
  - Proof: inspected and already present at same-or-greater detail; it supports the `BulletinSession` class/singleton route. No contradiction; untouched.
- [x] Leave `by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md`, `by-memory/0x00546810-0x00546888.ParcelPaneProcessSlotAnimations.md`, `by-memory/0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter.md`, and `by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md` untouched unless a direct contradiction is found.
  - Proof: inspected the sibling targets; no direct contradiction requiring this implementation was found, so all four remained untouched.
- [x] Do not edit generated coverage, project-level/manual coverage, validator/tool state, or IDA database files.
  - Proof: B002 made no manual edits to generated coverage, project-level/manual coverage, validator/tool state, or IDA DB files. Scoped validator `--apply` runs reported their own generated/projected stats side effects as command output, including `generated_refresh: deferred`.
- [x] From `source-3/project-documentation`, run scoped validators for every changed by-* file.
  - Proof: `python .\tools\validator.py --mode file --file by-memory\0x00546610-0x00546807.ParcelPaneOnMouseEvent.md --apply --queue-timeout 240` -> command `000000003201`, timestamp `2026-06-26T19:31:40-04:00`, `ok: 1`.
  - Proof: `python .\tools\validator.py --mode file --file by-class\ParcelPane.md --apply --queue-timeout 240` -> command `000000003202`, timestamp `2026-06-26T19:31:50-04:00`, `ok: 1`.
  - Proof: `python .\tools\validator.py --mode file --file by-file\ParcelPane.md --apply --queue-timeout 240` -> command `000000003203`, timestamp `2026-06-26T19:31:59-04:00`, `ok: 1`.
  - Proof: `python .\tools\validator.py --mode file --file by-type\by-struct\ParcelNotificationPaneLayouts.md --apply --queue-timeout 240` -> command `000000003204`, timestamp `2026-06-26T19:33:18-04:00`, `ok: 1`.
- [x] Update this report checklist with proof of applied items, validator commands/results, lease acquire/release evidence, and any explicitly excluded support edits with concrete reasons.
  - Proof: this checklist was updated after all scoped validators completed and after confirming no B002 active lease entries remained.
- [x] Return `FINISHED_IMPLEMENTATION` only after every accepted item is applied, already present at same-or-greater detail, or explicitly excluded with a concrete reason.
  - Proof: ready for `FINISHED_IMPLEMENTATION`; all accepted target/support edits were applied, same-or-greater support docs were left untouched with reasons, sibling targets were untouched with no contradiction found, and validators passed for every changed by-* file.

## Report-Only Validation

No by-* files were edited in this report-only pass, no leases were acquired, and no scoped by-* validators were run. This report is ready for supervisor validation under Rule 26.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002KE-ParcelPaneOnMouseEvent-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002KE-ParcelPaneOnMouseEvent-source-quality.md","timestamp":"2026-06-26T19:40:19","uid":"0002KE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
