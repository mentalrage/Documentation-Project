*** UID:000087 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MessageShowPane;
extern MessageShowPane *g_pMessageShowPane;

class MessageShowPane : public Pane,
                        public Singleton<MessageShowPane>
{
public:
    explicit MessageShowPane(wchar_t *messageText);
    virtual ~MessageShowPane();

protected:
    virtual void OnPaint();

public:
    void SetWrappedText(wchar_t *messageText);

private:
    wchar_t m_messageText[0x8000];
    int m_lineCount;
    int m_wrappedLineCount;
    int m_maxTextWidth;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MessageShowPane

## Status

- Confidence: very strong for class role, direct bases, exact layout, three vtable views, method declarations/order, singleton lowering, packet-handler reachability, and standalone reconstruction route.
- Source file: [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md), emitted as `NexusTK/ui/dialogs/MessageShowPane.cpp`.
- Main address range: [UID:0001C3][0x00520e30-0x005227c6.MessageAndMessageShowPane](by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md)
- Generated recovered file lead: `source-3/simroot_v2/class_MessageShowPane.cpp` (not authoritative; IDA MCP is the evidence source for boundaries/behavior).
- Parent/C++ status: reconstructable and emitted through UID0000LB at position `10`. The formal block is the complete Pane plus `Singleton<MessageShowPane>` declaration and closes the class with `};` before `[[CHILDREN]]`. Exact source children are constructor UID0004HN at position 20, destructor UID000492 at 30, OnPaint UID0004HO at 40, and SetWrappedText UID0001C4 at 50. UID0002Y8 remains a non-emitting method index; UID0001C5/UID0001C6/UID0001C7 remain compiler-only support.

## Class Purpose

`MessageShowPane` is a floating message overlay pane. It copies wide text into an internal buffer, measures and wraps lines to a 288-pixel width, anchors the pane near the right edge of the play area, and paints layered shadow/face text directly through inherited GrafPort operations.

## Inheritance And Layout

- Direct source bases are `Pane` and `Singleton<MessageShowPane>`.
- EventHandler and TimerHandler views are inherited Pane subobjects at complete-object offsets `+0xa0` and `+0xa4`; they are not duplicate direct source bases.
- Pane occupies `0x00-0xf8`.
- `Singleton<MessageShowPane>` RTTI PMD is `mdisp=0xf8`, `pdisp=-1`, `vdisp=0`; EBO overlaps the empty base with the first derived field.
- `wchar_t m_messageText[0x8000]` occupies `+0xf8-+0x100f8`.
- `m_lineCount`, `m_wrappedLineCount`, and `m_maxTextWidth` occupy `+0x100f8`, `+0x100fc`, and `+0x10100`.
- Complete size is `0x10104`, independently corroborated by allocation and compiler scalar-wrapper size-guard behavior.
- [UID:0003PC][0x0061fa48-0x0061fad0.MessageShowPaneVtableData](by-memory/0x0061fa48-0x0061fad0.MessageShowPaneVtableData.md) records the primary 18-slot, EventHandler 11-slot, and TimerHandler two-slot tables.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0004HN][0x00521da0-0x00521fc0.MessageShowPaneConstructor](by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md) | `MessageShowPane::MessageShowPane(wchar_t *messageText)` | Exact constructor child at `0x00521da0-0x00521fc0`; invokes Pane and Singleton base construction, copies/wraps message text, computes bounds, and attaches to the render layer. Singleton publication is implicit base lowering. |
| [UID:000492][0x00521fc0-0x00522025.MessageShowPaneDestructor](by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md) | `MessageShowPane::~MessageShowPane()` | Authored body contains only `RemoveFromLayer()`; Singleton clear, vptr restores, and Pane destruction are implicit/compiler-generated. |
| [UID:0004HO][0x00522030-0x00522530.MessageShowPaneOnPaint](by-memory/0x00522030-0x00522530.MessageShowPaneOnPaint.md) | `OnPaint()` | Exact virtual paint override; fills inherited bounds, then draws six palette-143 shadow passes and two palette-128 face passes with exact cumulative RectBounds offsets. |
| [UID:0001C4][0x00522530-0x005226ea.MessageShowPaneSetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md) | `SetWrappedText` | Replaces overlay text, recomputes wrap metrics, reapplies bounds, and refreshes text rows; IDA verifies it is only called by external packet-helper [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md) when `g_pMessageShowPane` already exists. |
| [UID:0001C5][0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md) | Singleton constructor-unwind cleanup | Compiler duplicate of direct Singleton base cleanup; ignored as standalone source. |
| [UID:0001C6][0x005226fb-0x00522711.MessageShowPaneAdjustorThunks](by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md) | destructor adjustor thunks | Compiler secondary/tertiary thunks into scalar deleting destructor; ignore for handwritten source. |
| [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md) | scalar deleting destructor wrapper | Compiler-generated wrapper with delete-flag handling; no handwritten `ScalarDeletingDestructor` source method. |
| [UID:0002Y8][0x00521da0-0x005227c6.MessageShowPaneMethods](by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md) | `MessageShowPaneMethods` container | Reviewed non-emitting method-cluster container; exact children carry source and compiler-generated support. |

## Evidence Notes

- Generated Wave3/simroot output has historically graded this class high and once marked `0x005226fb` as missing; treat that only as history. IDA resolves `0x005226fb-0x00522711` as adjustor thunks, so do not treat it as an unnamed project method.
- IDA MCP confirms every method listed above as an exact function start.
- Direct source dependencies are `RectBounds`, inherited GrafPort drawing/text helpers, `g_pRenderLayer1`, and `g_wszNewline`. Historical generated `g_applyMessagePaneBorder`/button-helper names are rejected as current source.
- IDA confirms `0x00522530` as a real helper called from message overlay packet handler `0x005ac070`. Generated lead material emits it under `MessageShowPane`, while older owner data under `FittingRoomDownloadControlPane` remains a data-history caveat rather than authority; IDA caller/xref evidence is the source-quality authority.
- [UID:0000RK][g_pMessageShowPane](by-global/g_pMessageShowPane.md) is the active overlay singleton at [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md).
- 2026-05-31 live IDA MCP recheck: `xrefs_to 0x0069b4f4` reports constructor, destructor, EH cleanup, scalar-deleting destructor, packet-handler, and UI cleanup references; `decompile` confirms those reads/writes and shows the constructor text-wrap/layout flow.
- 2026-06-16 A002 live IDA MCP on `b001_mappane_0001AW_20260616` reconfirmed exact function objects for constructor `0x00521da0`, destructor `0x00521fc0`, text-button builder `0x00522030`, wrapped-text updater `0x00522530`, EH singleton clear `0x005226f0`, adjustor thunk `0x005226fb`, and scalar deleting destructor `0x00522720`.
- The same pass reconfirmed eight [UID:0000RK][g_pMessageShowPane](by-global/g_pMessageShowPane.md) refs, one constructor caller at `0x005ac17e`, one wrapped-text updater caller at `0x005ac150`, and MessageShowPane vtable store refs at `0x0061fa4c`, `0x0061fa98`, and `0x0061fac8` from the constructor, destructor, and scalar deleting destructor.
- 2026-06-21 B011 rechecked [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md) and clarified that it is an external file-local packet helper, not a `MessageShowPane` method. It still remains the only direct caller for `SetWrappedText` at `0x005ac150` and the only packet-side constructor consumer at `0x005ac17e`.
- 2026-06-27 B008 implementation callback split the ordinary destructor into [UID:000492][0x00521fc0-0x00522025.MessageShowPaneDestructor](by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md) and reclassified [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md) as generated scalar-deleting destructor glue. Its earlier two-statement source model is preserved as historical; current RTTI proves the singleton clear is implicit direct-base destruction, leaving authored source `RemoveFromLayer();`.
- 2026-07-06 B004 implementation callback split exact constructor [UID:0004HN][0x00521da0-0x00521fc0.MessageShowPaneConstructor](by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md) and BuildMessageTextButtons [UID:0004HO][0x00522030-0x00522530.MessageShowPaneOnPaint](by-memory/0x00522030-0x00522530.MessageShowPaneOnPaint.md) children from aggregate [UID:0002Y8][0x00521da0-0x005227c6.MessageShowPaneMethods](by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md). Constructor, BuildMessageTextButtons, SetWrappedText, and ordinary destructor are source-bearing children; [UID:0001C5][0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md), [UID:0001C6][0x005226fb-0x00522711.MessageShowPaneAdjustorThunks](by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md), and [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md) remain generated support. [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md) remains an external packet-helper caller/dependency, not a `MessageShowPane` method.
- The former open standalone `MessageShowPane.cpp` versus compact `MessageDialogs.cpp` blocker is closed for reconstruction: the dedicated method island, singleton, generated source root, packet-consumer boundary, and no Message model field/API overlap support UID0000LB. Exact original disk spelling remains a confidence cap only.

## Compiler Exclusions

- Do not handwrite any of the three vptr stores, COL pointers, vtable arrays, destructor adjustors, scalar deleting wrapper, EH cleanup, delete flags, object-size guard, storage free, or base destructor calls.
- Constructor singleton publication and destructor singleton clear are direct `Singleton<MessageShowPane>` base lowering.
- UID0000RK emits the sole external singleton definition; exact storage UID0001PX emits no duplicate definition.
- The inherited three-argument no-op slot at `0x0041d680` is not redeclared by MessageShowPane; its descriptive lexical name remains a nonblocking evidence cap.

## Cross-References

- [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0002Y8][0x00521da0-0x005227c6.MessageShowPaneMethods](by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md)
- [UID:0004HN][0x00521da0-0x00521fc0.MessageShowPaneConstructor](by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md)
- [UID:0004HO][0x00522030-0x00522530.MessageShowPaneOnPaint](by-memory/0x00522030-0x00522530.MessageShowPaneOnPaint.md)
- [UID:0001C4][0x00522530-0x005226ea.MessageShowPaneSetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md)
- [UID:0001C5][0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md)
- [UID:0001C6][0x005226fb-0x00522711.MessageShowPaneAdjustorThunks](by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md)
- [UID:000492][0x00521fc0-0x00522025.MessageShowPaneDestructor](by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md)
- [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md)
- [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md)
- [UID:0003PC][0x0061fa48-0x0061fad0.MessageShowPaneVtableData](by-memory/0x0061fa48-0x0061fad0.MessageShowPaneVtableData.md)
- [UID:000084][Message](by-class/Message.md)

## Changes

- 2026-07-16 B002 UID0003PC implementation callback:
  - Raised `86/88` to `92/94`, retained owner/emitter UID0000LB and reconstructable true, and set emitter position `10`.
  - Installed the complete Pane plus `Singleton<MessageShowPane>` formal declaration, with `};` before `[[CHILDREN]]`.
  - Added exact `0x10104` EBO layout, primary/EventHandler/TimerHandler view evidence, final method order, direct OnPaint identity, Singleton lowering, source route closure, packet dependency, compiler exclusions, and historicalized stale helper/split assumptions.
- 2026-07-06 B004 implementation callback:
  - Added exact constructor child [UID:0004HN][0x00521da0-0x00521fc0.MessageShowPaneConstructor](by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md) and exact text-row builder child [UID:0004HO][0x00522030-0x00522530.MessageShowPaneOnPaint](by-memory/0x00522030-0x00522530.MessageShowPaneOnPaint.md) to the method map.
  - Added [UID:0002Y8][0x00521da0-0x005227c6.MessageShowPaneMethods](by-memory/0x00521da0-0x005227c6.MessageShowPaneMethods.md) as the reviewed non-emitting method-cluster container.
  - Preserved destructor source, generated support dispositions, and [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md) as an external packet-helper dependency.
- 2026-06-27 B008 implementation callback:
  - Added exact ordinary destructor child [UID:000492][0x00521fc0-0x00522025.MessageShowPaneDestructor](by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md) as the source-ready `MessageShowPane::~MessageShowPane()` body and reworded [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md) as generated scalar-deleting destructor support.
  - Evidence: live IDA/MCP confirmed the ordinary destructor range and the scalar wrapper's duplicate body plus delete-flag/OperatorDeleteWrapper/guard behavior.
- 2026-06-21 Rule 26 support sync from B011 [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md):
  - Clarified that [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md) is an external local-player packet helper and not a `MessageShowPane` method, while preserving it as the direct caller/consumer for constructor and `SetWrappedText`.
- 2026-06-16 A002 class-confidence refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:85`.
  - After: `COMPLETION:86`, `CONFIDENCE:88`; owner/emitter unchanged at [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md).
  - Evidence: live IDA MCP reconfirmed exact method starts, the single packet-handler callers for constructor and wrapped-text update, eight singleton refs, and the three MessageShowPane vtable store triads through [UID:0003PC][0x0061fa48-0x0061fad0.MessageShowPaneVtableData](by-memory/0x0061fa48-0x0061fad0.MessageShowPaneVtableData.md).
  - Blockers checked: standalone source-file split, inherited base/interface names, and text-builder helper name remain unresolved because the current evidence proves behavior/reachability but not original declaration spelling.
- 2026-06-06 A008:
  - Before: the class was reconstructable but unassigned even though its exact methods, singleton lifecycle, and packet-handler consumer path were documented.
  - After: changed completion/confidence to `85/85`, set `AUTOGEN_PARENT_UID` to [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md), and kept final C++ blank under the documented final-source gate.
  - Evidence: the file page now clears the 80/80 parent gate at `85/80` with exact method, destructor, vtable/read-only, singleton, and packet-handler evidence while preserving the open final split caveat.
- Completion/confidence score update: existed before as `0/0`; changed to `84/82`. Summary: the floating message overlay has detailed construction, wrapping, redraw, singleton, layer, text-button, helper, thunk, and global evidence, but final source-file grouping remains medium confidence. Evidence: linked `MessageAndMessageShowPane` range, exact helper/destructor memory pages, IDA-confirmed starts, `g_pMessageShowPane`, `g_pRenderLayer1`, and corrected ownership of `SetWrappedText`.
- 2026-05-31 metadata/evidence update: changed `RECONSTRUCTABLE` from blank to `TRUE` and confidence from `82` to `84`. Summary/evidence: live IDA MCP xrefs/decompilation verified the class-owned singleton lifecycle and packet-handler consumer path. Parent/code autogen fields remain blank because the final source-file split and final C++ source shape are not at the `95+` gate.
- 2026-05-31 SetWrappedText ownership clarification: updated the method row to rely on IDA caller/xref evidence instead of generated owner output. Summary/evidence: [UID:0001C4][0x00522530-0x005226ea.MessageShowPaneSetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md) now records live IDA `lookup_funcs`, `callers`, `xrefs_to`, `callees`, and `decompile` evidence.
