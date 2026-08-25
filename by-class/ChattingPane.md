*** UID:00001X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class List;
class ChattingMessage;
struct PaneKeyEvent;
struct Point;

class ChattingPane : public ScrollablePane
{
public:
    ChattingPane();
    virtual ~ChattingPane();

    void AddChattingMessage(const wchar_t *text,
                            int foregroundColor,
                            int backgroundColor,
                            unsigned char textStyleFlag,
                            int customForegroundRgb,
                            int customBackgroundRgb);
    void AddIncomingMessage(ChattingMessage *message);
    void SetVisibleRowCount(int visibleRows);
    short ComputeLineCount() const;
    void ScrollToBottom();

protected:
    virtual short GetScrollRange(char axis);
    virtual short GetOverflowCount(char axis);
    virtual short GetPageSize(char axis);
    virtual short GetScrollOffset(char axis, short units);
    virtual Point *GetContentSize(Point *outSize);
    virtual Point *GetScrollDelta(Point *outDelta,
                                  char axis,
                                  short oldPosition,
                                  short newPosition);
    virtual bool OnKeyEvent(const PaneKeyEvent *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPaint();

private:
    bool HandleServerSayPacket(const unsigned char *packet);

    List *m_pChatMessageList;
    int m_visibleChatPixelHeight;
};

extern ChattingPane *g_pChattingDisplayPane;

bool HandleChatPacketType10(ChattingPane *pane, const unsigned char *packet);

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ChattingPane

## Status

- Confidence: very strong for the complete source declaration, direct inheritance, fields, methods, singleton declaration/lifetime, List element semantics, and Chatting source route; exact historical header filename and private lexical spellings remain the confidence cap.
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md)
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- Historical generated source lead: `source-3/simroot_v2/class_ChattingPane.cpp` (context only; current score relies on IDA-backed documentation).
- Autogen status: reconstructable class attached to [UID:0000I5][Chatting](by-file/Chatting.md). The formal block supplies the source-complete current declaration surface, including direct `ScrollablePane` inheritance, six resolved scroll virtuals, emitted message/input/packet/paint methods, private `HandleServerSayPacket`, two proven fields, and the preserved free UID0002F0 prototype after class closure but before `[[CHILDREN]]` so address-ordered child definitions compile. [UID:0002ER][0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage](by-memory/0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage.md) now supplies the exact `AddIncomingMessage` definition; this owner-level declaration remains its single H declaration.

## 2026-07-21 g_pChattingDisplayPane Lifecycle Closure

- `ChattingPane` owns the source lifetime of external singleton `g_pChattingDisplayPane`, while [UID:0002WX][g_pChattingDisplayPane](by-global/g_pChattingDisplayPane.md) owns its sole definition in `NexusTK/social/Chatting.cpp` and [UID:0002WY][0x0067adcc-0x0067add0.g_pChattingDisplayPane](by-memory/0x0067adcc-0x0067add0.g_pChattingDisplayPane.md) remains marker-only.
- The formal declaration now includes exactly one `extern ChattingPane *g_pChattingDisplayPane;` after class closure. This is a declaration only; the class does not duplicate storage or initialization.
- [UID:0002EO][0x0047efb0-0x0047f1ce.ChattingPaneConstructor](by-memory/0x0047efb0-0x0047f1ce.ChattingPaneConstructor.md) derives from `ScrollablePane(false, true)`, publishes `this` unconditionally, constructs one stack `ColorStringChattingMessage` blank template with `L" "`, colors `128/143`, style `0`, and custom RGB `0/0`, allocates `List(sizeof(ColorStringChattingMessage *), 1000)`, appends 50 current-layout or 5 legacy owned clones by pointer-element address, writes `m_visibleChatPixelHeight = 104` only in the current-layout branch, then calls `SyncScrollbars()` and inferred inherited `SetSkinIndex(1)`.
- The legacy constructor branch intentionally does not initialize `m_visibleChatPixelHeight`; no source default initializer is added. The adjusted-null singleton store, vptr writes, EH state, temporary-unwind helpers, and cleanup chunks remain compiler lowering.
- [UID:0002EP][0x0047f1d0-0x0047f27e.ChattingPaneDestructor](by-memory/0x0047f1d0-0x0047f27e.ChattingPaneDestructor.md) snapshots List count, obtains each four-byte element slot through `GetElementAt(index)`, dereferences it as `ColorStringChattingMessage **`, deletes each owned message, deletes the List, nulls `m_pChatMessageList`, and unconditionally clears `g_pChattingDisplayPane`.
- Historical `GetAt`/direct-object-cast destruction is superseded by the generic List pointer-element contract. A self-equality guard is rejected because the binary performs an unconditional clear. Vptr restoration, SEH/cookie state, base teardown, scalar deleting-wrapper flags, and object-free calls remain compiler output.
- Fifteen external singleton reads in modify-height, handle, MapPane, screenshot, and user-list code corroborate this type and lifetime but do not transfer class/file/global ownership.

## 2026-07-29 AddIncomingMessage Source Closure

- [UID:0002ER][0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage](by-memory/0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage.md) now emits the exact first-draft `void ChattingPane::AddIncomingMessage(ChattingMessage *message)` definition at `93/94`. Its H channel is correctly blank because this class declaration already owns the method prototype.
- Both `AddChattingMessage` branches call the same exact method body. The method reads `g_pEventMan->GetModifierState`, obtains a polymorphic heap clone through `message->Clone()`, and calls `m_pChatMessageList->Append(1, &clonedMessage)`. List argument `1` is the record count; the List owns four-byte pointer-record storage while ChattingPane owns the pointed-to messages.
- Forced bottom scrolling occurs only when `HasMouseCapture()` is false and `modifierState & kEventModifierShift` is zero. Vertical axis is `0`; the exact inherited call is `ApplyScrollPosition(0, GetScrollPosition(0), GetScrollMax(0))`, with the current position retained as the required old-position argument.
- The current-layout branch synchronizes scrollbars only inside permitted autoscroll and after trimming. The legacy branch synchronizes immediately after append, then performs the same conditional autoscroll.
- After append, count greater than `1000` deletes the object addressed by pointer-record zero and removes one record through `RemoveAt(0, 1)`. It does not reject the new message and does not loop. Current layout then synchronizes. Legacy layout reads the signed current position, decrements positive positions, or clamps nonpositive positions to zero and invalidates inherited `m_bounds`, then synchronizes.
- Exact live evidence closes `[0x0047f370,0x0047f512)`, 418 bytes, body SHA256 `FEEBAED50A1C896EADF9F7954DE9A91E2A65A303EA172D63595430A902356A00`, two caller sites at `0x0047f2d8` and `0x0047f32b`, one-byte left and fourteen-byte right alignment, message/List/Pane/ScrollablePane contracts, and direct ChattingPane/Chatting ownership.
- Historical `FolderTreePane`, index/position-one insertion, generic interaction-state bit, shallow clone, List-owned message lifetime, and unresolved ScrollablePane-helper assumptions are superseded. Event producer behavior plus [UID:00004L][Event](by-class/Event.md) proves bit `0x04` is Shift; current List and ScrollablePane pages prove the accepted helper names and argument order.

## Class Purpose

`ChattingPane` is the scrollable chat display pane. It owns the chat message list, line-count and line-height calculations, high-res versus low-res layout differences, scroll input handling, and paint dispatch for `ColorStringChattingMessage` entries.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ChattingPane` | `0x0047efb0` | Constructs a `ScrollablePane`, seeds blank messages, sets `g_pChattingDisplayPane`, and initializes scroll state. |
| `~ChattingPane` | `0x0047f1d0` | Deletes owned `ColorStringChattingMessage *` entries from the generic `List *` at `this+0x130`, deletes the list, nulls the member, and clears `g_pChattingDisplayPane`; vtable/base teardown remains compiler output. |
| `AddChattingMessage` | `0x0047f280` | First-draft source-ready wrapper taking UTF-16 text, foreground/background palette ids, `unsigned char textStyleFlag`, and two custom RGB values. It preserves all fields only when `g_useEpfAssets == 1`, zeros style/RGB in legacy mode, and forwards a branch-scoped `ColorStringChattingMessage` to `AddIncomingMessage` for cloning; previous `FolderTreePane` owner was generated pollution. |
| `AddIncomingMessage` | `0x0047f370` | [UID:0002ER][0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage](by-memory/0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage.md); clones one polymorphic `ChattingMessage`, appends one pointer record, suppresses bottom autoscroll while Shift or mouse capture is active, preserves distinct current/legacy synchronization, and deletes/removes the oldest owned message only after count exceeds 1000. |
| `GetScrollRange` | `0x0047f520` | [UID:0004J8][0x0047f520-0x0047f5b7.ChattingPaneGetScrollRange](by-memory/0x0047f520-0x0047f5b7.ChattingPaneGetScrollRange.md); returns nonnegative vertical maximum from dynamic current rows or legacy five-row range. |
| `GetOverflowCount` | `0x0047f5c0` | [UID:0004J9][0x0047f5c0-0x0047f5f8.ChattingPaneGetOverflowCount](by-memory/0x0047f5c0-0x0047f5f8.ChattingPaneGetOverflowCount.md); ceiling-divides positive `m_contentRect.top - m_scrollContentRect.top` by 13. |
| `GetPageSize` | `0x0047f600` | [UID:0004JA][0x0047f600-0x0047f644.ChattingPaneGetPageSize](by-memory/0x0047f600-0x0047f644.ChattingPaneGetPageSize.md); returns current visible rows minus one, legacy seven, or one for nonvertical axes. |
| `GetScrollOffset` | `0x0047f650` | [UID:0004JB][0x0047f650-0x0047f667.ChattingPaneGetScrollOffset](by-memory/0x0047f650-0x0047f667.ChattingPaneGetScrollOffset.md); converts signed vertical units to 13-pixel offsets. |
| `GetContentSize` | `0x0047f670` | [UID:0004JC][0x0047f670-0x0047f6ae.ChattingPaneGetContentSize](by-memory/0x0047f670-0x0047f6ae.ChattingPaneGetContentSize.md); returns project `Point {y,x}` as content height and width 783/420. |
| `GetScrollDelta` | `0x0047f6b0` | [UID:0004JD][0x0047f6b0-0x0047f6e5.ChattingPaneGetScrollDelta](by-memory/0x0047f6b0-0x0047f6e5.ChattingPaneGetScrollDelta.md); returns y/x delta with vertical `13 * (oldPosition - newPosition)`. |
| `HandleInputEvent` / `OnKeyEvent` | `0x0047f6f0` | Handles keyboard scrolling with project-specific narrowed key bytes `0x81/0x83/0x93/0x94`, event kind `8`, key state `4`, inherited `ScrollablePane` current/max/apply helpers, and vslot `+0x50` page-step logic. |
| `HandlePacketEvent` | `0x0047f890` | Source-ready [UID:0002EU][0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter](by-memory/0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter.md) at `92/94`: concrete EventHandler packet-family override reads `Event::m_payload.m_packet.m_data` at Event `+0x0c`, dispatches literal byte `10` to preserved free `HandleChatPacketType10(this, packet)` and literal byte `13` to private `HandleServerSayPacket(packet)`, forwards each false-valued result, and returns false otherwise. Incoming secondary `this+0xa0` is compiler-adjusted back to ChattingPane before either helper transfer. |
| `OnPaint` | `0x0047f8d0` | Source-ready [UID:0002EV][0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint](by-memory/0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint.md) at `91/93`: current `g_useEpfAssets == 1` uses `m_bounds`, width 783, saved inherited `m_mode`, and `g_pChattingHandlePane->m_secondaryChatEnabled`; legacy uses `m_contentRect` and width 408. Both start y at `m_scrollContentRect.top`, dereference `ColorStringChattingMessage **` from generic List element storage, build full `RectBounds`, and preserve branch-level automatic Region lifetime plus the unseeded second-Region path. |
| `SetVisibleRowCount` | `0x0047fbd0-0x0047fc6b` | Source-ready [UID:0002EW][0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount](by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md) at `92/94`: copies current bounds into a distinct local, stores `13 * visibleRows` in `m_visibleChatPixelHeight`, applies current-layout viewport `(23, 710 - height, 806, 710)` by pointer, syncs scrollbars, applies vertical current/max in that order, and invalidates inherited `m_bounds`. |
| `ComputeLineCount` | `0x0047fc70` | Returns signed-short accumulated message line count, wrapping at width 783 current or 408 legacy. |
| `ScrollToBottom` raw helper | `0x0047fd40-0x0047fd68` | IDA-unmodeled helper that reads the current/max vertical scroll values and calls `ApplyScrollPosition(0, current, max)` to move the chat display to the bottom. |
| `HandleServerSayPacket` | `0x0047fd70-0x0047ff80` | Private [UID:0002EZ][0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket](by-memory/0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket.md) at `92/92`: body through `0x0047ff60` plus compiler switch/alignment tail; exact server-say object-id/length/ACP/custom-color packet layout; five subtype roles; current/legacy palettes and gates; layout-entry `GetMemoryMan`; inferred `wchar_t[256]`; active pointer load on all paths with display-byte dereference only for Normal/Shout; unchecked edges; always false. |
| `SetScrollPosition`, `SyncScrollbars`, `UpdateContentLayout` | `0x0055e7e0`, `0x0055e990`, `0x0055f250` | Later scroll helpers currently owned by `ChattingPane`. |

## Evidence Notes

- Existing IDA-backed memory pages confirm the local constructor, destructor, scroll metric virtuals, keyboard scroll handler, packet router, paint method, visible-row update, line-count helper, and raw `ScrollToBottom` helper inside the `0x0047efb0-0x0047fd68` display-pane band.
- The constructor directly creates `ColorStringChattingMessage` instances and writes `g_pChattingDisplayPane`.
- [UID:0002EY][0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw](by-memory/0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw.md) is source-authored local chat-display support even though IDA does not model it as a function start. B003 MCP session `80de0a67` records exact raw bytes, SHA16 `1094287b969ed723`, SHA256 `1094287b969ed7231c50a221a5bc1eba36f16c3307f8f1064ce3db72024071b3`, the surrounding `0xcc` padding, no direct xrefs/backward data-flow/pointer route to `0x0047fd40`, and the accepted first-draft `ChattingPane::ScrollToBottom()` C++ body.
- 2026-06-14 C001 IDA MCP recheck on `a001_goal2_class_batch`: `server_health` reports IDA 9.1 database `NexusTK.exe.i64` ready with Hex-Rays enabled; function lookup confirms modeled starts for constructor/scroll/input/paint helpers at `0x0047efb0`, `0x0047f520`, `0x0047f5c0`, `0x0047f600`, `0x0047f650`, `0x0047f6f0`, `0x0047f8d0`, `0x0047fbd0`, and `0x0047fc70`.
- The same pass confirms `SetVisibleRowCount` has callers at `0x0048094a` and `0x00480b4f`, stores `13 * visibleRows`, applies the `(23, 710 - 13*n, 806, 710)` viewport, calls `sub_55E990` / `SyncScrollbars`, then reads `GetScrollPosition(0)`, reads `GetScrollMax(0)`, and applies the maximum through `ApplyScrollPosition(0, currentPosition, maximumPosition)`.
- `GetLineCount` is still only called by the local scroll metric helpers at `0x0047f520` and `0x0047f670`; it walks the message list at `this[76]`, uses `byte_66DA97` to select 783-pixel versus 408-pixel wrapping, and sums each message object's line count.
- The raw `ScrollToBottom` helper at `0x0047fd40-0x0047fd68` remains non-modeled in IDA and has zero incoming xrefs, but B003 `get_bytes`, `find_bytes`, `xref_query`, `trace_data_flow`, and unique-signature checks confirm it is bracketed by `0xcc` padding and contains the exact calls to `GetScrollPosition`, `GetScrollMax`, and `ApplyScrollPosition`. No-function/no-xref/no-pointer-route status is a score cap, not a C++ blocker.
- 2026-06-16 B001 source-quality reanalysis correctly rejected stale generated `FolderTreePane` ownership for [UID:0002EQ][0x0047f280-0x0047f36f.ChattingPaneAddChattingMessage](by-memory/0x0047f280-0x0047f36f.ChattingPaneAddChattingMessage.md) and [UID:0002ER][0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage](by-memory/0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage.md). Its generic EventMan-state, unresolved List argument, and unresolved inherited-helper caveats are historical only: B007 now proves `kEventModifierShift`, `List::Append` count one, and exact ScrollablePane identities/order. Both are direct `ChattingPane` message-ingress methods: `AddChattingMessage` wraps text/color/style arguments into a temporary `ColorStringChattingMessage`, while `AddIncomingMessage` deep-clones, stores, scrolls, and trims the owned pointer list.
- Current UID0002EQ source-quality implementation resolves `AddChattingMessage` independently of UID0002ER's remaining helper-name blockers. MCP session `359c7886` confirms its exact `0x0047f280-0x0047f36f` body, adjacent padding, six stack arguments, `g_useEpfAssets == 1` branch, current-field preservation, legacy style/RGB zeroing, two constructor/forward paths, six packet/status xrefs, and compiler-only cleanup. Constructor/clone/draw evidence establishes `const wchar_t *`, palette ids, neutral `m_textStyleFlag`, independent custom RGB values, and deep-clone ownership. The wrapper itself never touches `m_pChatMessageList`, EventMan, or ScrollablePane helpers.
- B001 also resolves source-quality field roles for the constructor and scroll metrics: `this+0x130` is best documented as `m_chatMessageList` / `m_pChatMessageList`, `this+0x134` is visible chat pixel height, `dword_67ADCC` is the active `g_pChattingDisplayPane` sink, and the `0x0047f600` virtual returns visible/page line count rather than line height.
- Historical 2026-06-17 B003 source-quality reanalysis resolved the destructor, secondary-view packet router, and visible-row layout method to first-draft C++ readiness on their exact child pages. Its packet bytes `10`/`13`, file-local helper route, and `ecx -= 0xa0` compiler-glue findings remain valid. Its provisional `Message`/`OnChatPacketMessage` declaration is superseded by the current exact EventHandler packet contract below.
- Historical 2026-06-17 B001 source-quality reanalysis resolved the keyboard child and produced a provisional paint draft. Its UID0002EV three-int row span, private offset aliases, direct List cast, C++11 lambda/guard, and generic callback/global names are superseded by B004's 2026-07-13 live-MCP pass. Current UID0002EV uses full `RectBounds {0, oldY, width, newY}`, `m_scrollContentRect.top`, inherited `m_mode`/`SetMode`, generic List element-storage dereference, exact `g_pChattingHandlePane->m_secondaryChatEnabled`, `SetDrawColor`, `FillRect`, exact clip-helper directions, and two branch-scope automatic Regions whose second Region remains intentionally unseeded.
- B004's UID0002EV pass confirms the paint callback needs no class field or method declaration change: `m_bounds`, `m_contentRect`, `m_scrollContentRect`, and `m_mode` are inherited; `m_pChatMessageList` remains the only direct list field used by OnPaint. B004 validator `000000009429` preserved the then-current `90/92` class score and existing declaration. The later independent B001 UID0002EU callback raised the class to `91/93` and revised packet-event declarations; those B001 changes are current, unrelated to UID0002EV, and preserved.

## 2026-07-13 B005 Scroll Metric Class-Surface Resolution

- [UID:0002ES][0x0047f520-0x0047f6e5.ChattingPaneScrollMetricVirtuals](by-memory/0x0047f520-0x0047f6e5.ChattingPaneScrollMetricVirtuals.md) is now a non-emitting index. Exact source lives on registered children UID0004J8-UID0004JD; all six attach directly to this class and preserve primary-vtable slots `+0x48..+0x5c`.
- Constructor and vptr evidence establish `ChattingPane : public ScrollablePane`. Primary, secondary, and tertiary vptr stores at `+0/+0xa0/+0xa4` are compiler output; the declaration expresses only source inheritance.
- Resolved inherited signatures are four `short` scalar returns with `char axis`, one `short units`, and two `Point *` output helpers. Project `Point` is y/x; Win32 `POINT`, `SIZE`, generic pairs, and no-argument virtuals are rejected.
- `m_pChatMessageList` is the owned `List *` at `+0x130`. `m_visibleChatPixelHeight` is the `int` at `+0x134`, maintained as `13 * visibleRows`. Inherited `m_contentRect.top` at `+0x114` and `m_scrollContentRect.top` at `+0x124` are base fields, not duplicate ChattingPane members.
- Axis `0` is vertical and `1` horizontal. `GetScrollDelta` takes old/current before new/target and computes old minus new. Historical reversed ordering is corrected.
- Constants remain distinct: 13-pixel line unit; range current dynamic / legacy minus 5; page current rows minus 1 / legacy 7; content width 783/420; wrap width 783/408.
- Canonical slot `+0x5c` name is `GetScrollDelta`, supported by a base-plus-six-direct-family body audit and the surviving ListPane source inventory. Historical `ConvertScrollDelta` and descriptive `GetScrollOffsetPointForLines` are explicitly superseded.
- The formal declaration includes every currently emitted or sufficiently resolved method needed by existing exact child definitions. Constructor UID0002EO and `AddIncomingMessage` UID0002ER retain their separate body-quality dispositions; declaring them does not invent those bodies.
- Exact range/padding and negative evidence remain on UID0002ES and the children: vtable-only xrefs prove ordinary virtual liveness; all five internal gaps and the trailing gap are `0xcc`; no unrelated owner, strings, hidden function, or new source route was found.

## 2026-07-13 B001 Packet Event Contract

- Live MCP session `160045b9` confirms [UID:0002EU][0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter](by-memory/0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter.md) is the ChattingPane secondary EventHandler packet slot: its sole xref is table word `0x00614d64`, corresponding to virtual offset `+0x10` in the secondary table at `0x00614d54`.
- EventDispatcher `0x004a77d0` selects packet Event type `18` and calls handler slot `+0x10`. [UID:00004L][Event](by-class/Event.md) and packet factory `0x004a9fa0` resolve packet kind/data/size at Event `+0x08/+0x0c/+0x10`; the router reads the data pointer at `+0x0c` and then packet byte zero.
- The formal method is therefore `HandlePacketEvent(Event *)`. Historical `struct Message`, `OnChatPacketMessage`, and `HandleChatPacketEvent` are rejected current declarations because [UID:000084][Message](by-class/Message.md) is an unrelated ChangeMan/message-dialog object with no packet payload at `+0x0c`.
- The target compares pointed packet byte `10` before `13`, returns false for other bytes, and tail-jumps to [UID:0002F0][0x0047ff80-0x00480640.ChatPacketType10Handler](by-memory/0x0047ff80-0x00480640.ChatPacketType10Handler.md) or [UID:0002EZ][0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket](by-memory/0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket.md). Both accepted helper families return false after their side effects.
- The incoming EventHandler receiver is `this+0xa0`; target machine code subtracts `0xa0` before either helper transfer. This is compiler multiple-inheritance adjustment, not a class field, explicit cast, source base, or body statement.
- Generated address order places UID0002EU before both helper definitions. UID0002EZ's receiver ABI, direct member sink, and repaired source-quality pass establish a private member declaration inside the class. UID0002F0 remains an independently unresolved free helper, so only its existing prototype stays after class closure and before `[[CHILDREN]]`.
- No null/size guard, split, new child, owner move, source-file move, manual vtable, or helper-body rewrite is justified. The class remains owned/emitted by [UID:0000I5][Chatting](by-file/Chatting.md) under `NexusTK/social/Chatting.cpp`.

## 2026-07-14 B005 UID0002EZ Server-Say Member Resolution

- UID0002EZ is now the private one-argument `bool HandleServerSayPacket(const unsigned char *packet)` member. Router complete-object adjustment, ECX/`ret 4`, member sink calls, and local address band select class membership; the historical free/static Type13 prototype is superseded.
- UID0002F0 remains byte-for-byte in its existing free-helper declaration/source shape. This callback does not rename, memberize, rescore, or rewrite it, and the router deliberately retains `HandleChatPacketType10(this, packet)`.
- No shared `ServerPacketOpcode` is declared. UID00026H provides packet-name strings, not enum ownership; UID0001SO is a MapPane-scoped blank-formal inventory. The router preserves literals `10`/`13`, while `ServerSaySubtype` is local to the target method and therefore needs no class/file declaration.
- Target runtime/source evidence retained at class level: one ignored `GetMemoryMan()` call before packet reads in each layout; current subtype-4 trailer reads before the active pointer; `g_activeMapPane->m_userPane` load for all subtype/default paths; `m_sayDisplayLevel` reads only for subtype `0`/`1`; inferred `wchar_t[256]` plus four alignment bytes; no null/size/conversion/trailer guards; unconditional false return.
- The attached target switch table and alignment are compiler output retained in the target page, not class declarations, children, vtable entries, or source arrays. `[[CHILDREN]]` remains after the complete class plus free UID0002F0 prototype.
- Scores and class ownership remain `91/93`, UID0000I5, reconstructable true, blank position. The callback changes only the accepted declaration and target/router evidence; every scroll/message/input/paint method and both fields remain unchanged.

## 2026-07-13 B002 UID0002EW Visible-Row Layout Resolution

- [UID:0002EW][0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount](by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md) is now `92/94` with exact source-ready `void ChattingPane::SetVisibleRowCount(int visibleRows)` under this class and the existing [UID:0000I5][Chatting](by-file/Chatting.md) / `NexusTK/social/Chatting.cpp` route. This class remains `91/93`; its complete declaration, owner/emitter metadata, fields, sibling methods, and formal block are unchanged.
- The method has exact half-open range `0x0047fbd0-0x0047fc6b`, size `0x9b`, 58 instructions, and body SHA256 `0dcc66f6dea573c9ca76792dba4e09c47e3c9a7072a47e5c84886e050715f48f`. Eleven predecessor and five successor `0xcc` bytes remain alignment; no split, new child, or nesting change is required.
- The source body preserves two distinct automatic `RectBounds` objects. It first executes `GetBounds(&currentBounds)` even though the copied local is not subsequently read, then stores `13 * visibleRows` in final dword member `m_visibleChatPixelHeight` at `+0x134`, builds viewport `(23, 710 - m_visibleChatPixelHeight, 806, 710)`, and calls inherited `SetBounds(&viewport, false)` through primary slot `+0x2c` / `0x00544bd0`.
- Scroll order is exact: `SyncScrollbars()`, vertical `GetScrollPosition(0)`, vertical `GetScrollMax(0)`, then `ApplyScrollPosition(0, currentPosition, maximumPosition)`. The final call passes inherited `&m_bounds` at complete-object `+0x44` to `InvalidateRect` through primary slot `+0x20` / `0x00544800`.
- Exactly two callers, at `0x0048094a` in the drag-release handler and `0x00480b4f` in the line-count layout helper, pass visible-row counts through `g_pChattingDisplayPane` and ignore EAX. Caller/construction routing selects this path only for `g_useEpfAssets == 1`; the target itself has no mode-global read or branch. Clamping remains caller-owned.
- Source `void` is supported by setter declaration, absent coherent EAX result, and both callers ignoring EAX. The target has two code xrefs, zero data xrefs, and zero raw VA/RVA pointer hits. It has no null/failure branch, allocation, free, EH cleanup, or screen-global access; security-cookie and virtual-dispatch mechanics are compiler output.
- Historical generated `FolderTreePane`/BackPane ownership, `m_visibleRowCount`, `SetScrollRange`/`ResetScrollRange`, value-shaped `SetBounds`, omitted leading bounds copy, and `m_rect` invalidation are superseded only for UID0002EW. UID0002EU and UID0002EV retain their independently accepted active implementations and were not changed by this synchronization.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `92` | The class has a complete current declaration shell, direct inheritance, two proven fields, six exact split scroll children, signed-short/Point contracts, message/input/Event-packet/paint declarations, exact AddIncomingMessage source, private server-say member, preserved pre-child free Type10 prototype, external singleton declaration, complete constructor/destructor/global lifecycle, source route, raw helper liveness, and preserved child evidence. Remaining work belongs to separately scoped unrelated method bodies and final original-header polish. |
| Confidence `94` | Exact memory pages, primary/secondary vtables, constructor publication, ordinary-destructor clear, exhaustive singleton consumers, dispatcher/factory evidence, base consumers, direct-family overrides, accepted Event/Point/List types, and generated routing agree. The remaining cap is absent original symbol/header spelling and a few inferred private/helper spellings, not behavior, ownership, ABI, or declaration shape. |

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:0002EO][0x0047efb0-0x0047f1ce.ChattingPaneConstructor](by-memory/0x0047efb0-0x0047f1ce.ChattingPaneConstructor.md)
- [UID:0002EQ][0x0047f280-0x0047f36f.ChattingPaneAddChattingMessage](by-memory/0x0047f280-0x0047f36f.ChattingPaneAddChattingMessage.md)
- [UID:0002ER][0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage](by-memory/0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage.md)
- [UID:0002ES][0x0047f520-0x0047f6e5.ChattingPaneScrollMetricVirtuals](by-memory/0x0047f520-0x0047f6e5.ChattingPaneScrollMetricVirtuals.md)
- [UID:0002ET][0x0047f6f0-0x0047f890.ChattingPaneKeyboardScrollHandler](by-memory/0x0047f6f0-0x0047f890.ChattingPaneKeyboardScrollHandler.md)
- [UID:0002EU][0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter](by-memory/0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter.md)
- [UID:0002EV][0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint](by-memory/0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint.md)
- [UID:0002EW][0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount](by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md)
- [UID:0002EX][0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount](by-memory/0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount.md)
- [UID:0002EY][0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw](by-memory/0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw.md)
- [UID:0004J8][0x0047f520-0x0047f5b7.ChattingPaneGetScrollRange](by-memory/0x0047f520-0x0047f5b7.ChattingPaneGetScrollRange.md)
- [UID:0004J9][0x0047f5c0-0x0047f5f8.ChattingPaneGetOverflowCount](by-memory/0x0047f5c0-0x0047f5f8.ChattingPaneGetOverflowCount.md)
- [UID:0004JA][0x0047f600-0x0047f644.ChattingPaneGetPageSize](by-memory/0x0047f600-0x0047f644.ChattingPaneGetPageSize.md)
- [UID:0004JB][0x0047f650-0x0047f667.ChattingPaneGetScrollOffset](by-memory/0x0047f650-0x0047f667.ChattingPaneGetScrollOffset.md)
- [UID:0004JC][0x0047f670-0x0047f6ae.ChattingPaneGetContentSize](by-memory/0x0047f670-0x0047f6ae.ChattingPaneGetContentSize.md)
- [UID:0004JD][0x0047f6b0-0x0047f6e5.ChattingPaneGetScrollDelta](by-memory/0x0047f6b0-0x0047f6e5.ChattingPaneGetScrollDelta.md)
- [UID:00002Z][ColorStringChattingMessage](by-class/ColorStringChattingMessage.md)
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)

## Changes

- 2026-07-29 B007 UID0002ER support implementation:
  - Preserved `92/94`, owner/emitter [UID:0000I5][Chatting](by-file/Chatting.md), reconstructable true, the complete class declaration, fields, inheritance, sibling methods, singleton lifecycle, and `[[CHILDREN]]` order.
  - Expanded only the accepted AddIncomingMessage contract: polymorphic owned clone, List append-count semantics, Shift/capture autoscroll suppression, exact current/legacy synchronization, post-insert 1000-entry oldest delete/remove, signed legacy scroll repair, boundary/hash/caller evidence, source route, and superseded historical assumptions.
  - Kept the sole owner-level `void AddIncomingMessage(ChattingMessage *message);` declaration here while UID0002ER emits the definition and intentionally leaves its H channel blank.

- 2026-07-21 B001 UID0002WY source-quality callback:
  - Raised the class from `91/93` to `92/94`, retaining owner/emitter UID0000I5, reconstructable true, blank position, every existing method/field/history fact, and post-class `[[CHILDREN]]` placement.
  - Added the sole external `ChattingPane *g_pChattingDisplayPane` declaration and complete constructor/destructor/global lifetime, corrected List `GetElementAt` pointer-element semantics, legacy untouched-height behavior, one-definition route, compiler exclusions, consumer/non-owner evidence, and superseded `GetAt`/guard/raw-offset assumptions.
- 2026-07-14 B005 UID0002EZ support implementation:
  - Preserved class `91/93`, UID0000I5 owner/emitter, complete inheritance/virtual/message/paint/scroll surface, two fields, and `[[CHILDREN]]` placement.
  - Applied the accepted formal declaration change only: added private `HandleServerSayPacket(const unsigned char *)`, removed the obsolete free/static Type13 prototype, and preserved the free UID0002F0 prototype after class closure.
  - Synchronized mixed free/member router ABI, target runtime order, packet/state/source-local evidence, compiler-tail no-source disposition, local enum ownership, unsafe edges, scores, and rejected shared-enum/Type10-expansion alternatives without changing unrelated class content.
- 2026-07-13 B002 UID0002EW support synchronization:
  - Preserved class score `91/93`, complete formal declaration, metadata, fields, and all unrelated method dispositions.
  - Synchronized only UID0002EW's exact bounds-copy, pixel-height, viewport, scrollbar, invalidation, caller/current-layout, liveness, ABI/compiler, source-route, and superseded-history evidence.
  - UID0002EU and UID0002EV remained no-edit active scopes.
- 2026-07-13 B004 UID0002EV support synchronization:
  - At B004 validator `000000009429`, class score, metadata, complete declaration, fields, and sibling methods remained unchanged at `90/92`. The later independent B001 UID0002EU callback raised the class to `91/93` and updated packet-event declarations; this B004 entry does not supersede those later changes.
  - Corrected only the OnPaint row/evidence to UID0002EV's `91/93` source-ready model: full `RectBounds`, signed-short line count, generic List element-storage dereference, inherited bounds/mode fields, exact secondary-chat gate, current/legacy differences, exact clip-helper direction, automatic Region lifetime, and preserved unseeded nonempty-clip branch.
  - Historical B001 lambda/guard/three-int/private-alias/callback assumptions are retained only as superseded provenance.
- What existed before: the page documented the chat display pane, scroll helpers, paint path, and related classes, but metadata remained `0/0`.
- What it was changed to: scores were set to `76/86`.
- Summary and evidence: constructor, scroll calculations, input, paint, message ownership, and later scroll helpers are covered; exact fields and final source-level layout remain incomplete.
- 2026-06-03: Raised completion from `76` to `80`, marked `RECONSTRUCTABLE:TRUE`, and attached parent [UID:0000I5][Chatting](by-file/Chatting.md).
  - Evidence: the class page now links exact IDA-backed visible-row, line-count, and raw reset-scroll helper pages; [UID:0000I5][Chatting](by-file/Chatting.md) already has a valid `NexusTK/social/` projection and confidence above the attachment gate. C++ remains blank below the final-source gate.
- 2026-06-14 C001 Goal 2 refresh:
  - Before: score was `80/86`; the page depended mostly on existing child docs and still carried generated-source wording.
  - After: score is `86/88`; owner/emitter routing remains [UID:0000I5][Chatting](by-file/Chatting.md), and C++ remains blank.
  - Summary/evidence: current IDA MCP confirms the modeled method starts, the two callers of `SetVisibleRowCount`, the six local callers of `GetLineCount`, the `g_pChattingDisplayPane` reference set, and the raw reset helper's non-function/padded-byte status. Final field names and later generic scrollbar helper exposure remain the only source-quality blockers.
- 2026-06-23 B003 `ChattingPane::ScrollToBottom` raw-helper execution:
  - The exact child [UID:0002EY][0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw](by-memory/0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw.md) was renamed from stale `ResetScrollRangeRaw`, raised to `87/90`, and populated with first-draft `ChattingPane::ScrollToBottom()` C++.
  - Evidence: MCP session `80de0a67` reconfirmed no function at `0x0047fd40`/`0x0047fd68`, predecessor `sub_47FC70`, successor `sub_47FD70`, exact 40-byte body SHA16 `1094287b969ed723`, five-byte and eight-byte `0xcc` padding spans, helper roles `GetScrollPosition`, `GetScrollMax`, and `ApplyScrollPosition`, no incoming xrefs/backward data-flow/VA/RVA/raw pointer route, and unique full-body bytes. The old no-route status remains a confidence cap only.
- 2026-06-16 B001 message-ingress source-quality execution:
  - Raised from `86/88` to `87/90` after accepting B001's direct `ChattingPane` owner route for [UID:0002EQ][0x0047f280-0x0047f36f.ChattingPaneAddChattingMessage](by-memory/0x0047f280-0x0047f36f.ChattingPaneAddChattingMessage.md) and [UID:0002ER][0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage](by-memory/0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage.md), resolving `this+0x130` / `this+0x134` roles, correcting the `0x0047f600` virtual-name interpretation, and documenting the active `g_pChattingDisplayPane` route.
  - Final C++ remains blank because original field, List helper, EventMan bit, and inherited ScrollablePane virtual names are not yet source-grade.
- 2026-06-17 B003 ChattingPane core source-quality execution:
  - Scores remain `87/90` for the class while exact child pages [UID:0002EP][0x0047f1d0-0x0047f27e.ChattingPaneDestructor](by-memory/0x0047f1d0-0x0047f27e.ChattingPaneDestructor.md), [UID:0002EU][0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter](by-memory/0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter.md), and [UID:0002EW][0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount](by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md) now carry first-draft C++ at `86/90`.
  - Summary/evidence: B003 rechecked the destructor list-delete/singleton-clear route, packet-router secondary vtable callback, packet byte `10`/`13` tail targets, visible-row pixel-height field, modify-height callers, local PE padding/calls, and sibling ChattingPane field roles. The class-level C++ remains blank for full-declaration coordination only, not because these child bodies are unresolved.
- 2026-06-17 B001 ChattingPane keyboard/paint source-quality execution:
  - Scores remain `87/90` for the class while [UID:0002ET][0x0047f6f0-0x0047f890.ChattingPaneKeyboardScrollHandler](by-memory/0x0047f6f0-0x0047f890.ChattingPaneKeyboardScrollHandler.md) and [UID:0002EV][0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint](by-memory/0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint.md) now carry first-draft C++ at `86/90`.
  - Summary/evidence: B001 rechecked recovered snippets and existing IDA-backed docs, rejected Win32 VK mapping for the keyboard bytes, resolved `ScrollablePane` current/max/apply helper roles, documented the paint row-span and clip/callback helper roles, and kept exact original field/helper names as provisional role names rather than blank-code blockers.
- 2026-07-12 B005 UID0002EQ source-quality implementation:
  - Class score remains `87/90`; the exact [UID:0002EQ][0x0047f280-0x0047f36f.ChattingPaneAddChattingMessage](by-memory/0x0047f280-0x0047f36f.ChattingPaneAddChattingMessage.md) child is now `90/92` with first-draft formal C++ under this class and the [UID:0000I5][Chatting](by-file/Chatting.md) source route.
  - Accepted details are UTF-16 text and palette/style/custom RGB parameters, exact `g_useEpfAssets == 1` preservation versus legacy zeroing, branch-scoped `ColorStringChattingMessage` construction, forwarding to AddIncomingMessage for deep cloning, six packet/screenshot/user-list status callers, exact boundary/padding evidence, and compiler-only cleanup. Original spellings remain inferred confidence caps; UID0002ER's List/EventMan/ScrollablePane names remain its own separate blockers.
- 2026-07-13 B005 UID0002ES source-quality implementation:
  - Raised `87/90` to `90/92` and replaced the blank formal block with the accepted complete `ChattingPane : public ScrollablePane` declaration, including six canonical scroll virtuals, current emitted methods, two fields, and required post-class `[[CHILDREN]]` placement.
  - Registered/linked exact scroll children UID0004J8-UID0004JD and synchronized ABI, Point order, field lifecycle, axis/old-new behavior, constants, padding/liveness, sibling naming, rejected alternatives, and existing `NexusTK/social/Chatting.cpp` route without changing unrelated child dispositions.
- 2026-07-13 B001 accepted UID0002EU support implementation:
  - Raised `90/92` to `91/93`; owner/emitter UID0000I5, reconstructable true, and blank position remain unchanged.
  - Applied the complete accepted declaration block at that time: replaced the unrelated `Message` forward/type and provisional packet method with `Event` / `HandlePacketEvent(Event *)`, preserved every unrelated B005/B004 declaration and field, and added Type10/Type13 helper prototypes after class closure. B005's 2026-07-14 UID0002EZ pass supersedes only the Type13 free/static declaration with a private member while preserving the Type10 prototype and `[[CHILDREN]]` order.
  - Added direct packet Event layout, secondary slot `+0x10`, complete-object `+0xa0` adjustment, opcode/return behavior, helper order/linkage, negative evidence, and unchanged Chatting.cpp ownership. Historical B003 Message wording remains only as corrected provenance.
