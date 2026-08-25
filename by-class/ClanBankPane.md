*** UID:000026 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../ui/dialogs/ItemDialogs.h"

class ClanBankItemListPane;

class ClanBankPane : public DialogPane
{
public:
    ClanBankPane(const unsigned char *packet, int action);
    virtual ~ClanBankPane();

protected:
    virtual void OnDialogAction(int controlId, int action, int value);

private:
    void SendClosePacket();
    unsigned char m_bankMode;     // +0x26c, 0 for item bank action 10, 1 for gold bank action 16.
};

extern ClanBankPane *g_pClanBankPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanBankPane

## UID0000LO Accepted ItemDialogs Visibility - 2026-08-14

The first ClanBankPane emitter now includes
`../ui/dialogs/ItemDialogs.h`, making the folded MyItemListPane declaration
available to the clan-deposit paths that construct/call it. This is a
declaration-visibility repair only: UID000026 remains owner/emitter UID0000I9,
position `0`, score `87/90`, and no ClanBank source or ownership is moved into
ItemDialogs.

## Status

- Confidence: strong for constructor/action/vtable singleton behavior and ClanBank ownership; medium for exact original virtual names, final widget field names, and whether the slide-close helper is shared dialog infrastructure.
- Likely source file: [UID:0000I9][ClanBank](by-file/ClanBank.md)
- Documented source grouping: [UID:0000I9][ClanBank](by-file/ClanBank.md), with a possible `ClanItemDialogs.cpp` companion split.
- 2026-06-15 live IDA status: current `NexusTK.exe` session reconfirms constructor `sub_48B1C0` size `0x433`, vtable-reset helper `sub_48B600` size `0x29`, action handler `sub_48B630` size `0x1ac`, raw packet helper starts `0x0048b7e0`/`0x0048b870` as not modeled functions, scalar deleting destructor `sub_48C410` size `0x5f`, unique signature for `0x0048b1c0-0x0048b7dc`, two constructor callers, singleton xrefs, and shared close-helper fan-in.

## Class Purpose

`ClanBankPane` is the main clan bank dialog. It selects item-bank or gold-bank mode from the server action type, creates the `cl` dialog resource, embeds a `ClanBankItemListPane`, tracks quantity input, sends close/submit packets, and clears the singleton `g_pClanBankPane` during destruction.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanBankPane` | `0x0048b1c0-0x0048b5f3` | Constructs the dialog, installs vtables, selects bank mode from packet action `10` or `16`, creates buttons, quantity edit, item list, scroll wrapper, and count/gold label. |
| vtable-reset helper | `0x0048b600-0x0048b629` | Real IDA function with no direct xrefs; writes `ClanBankPane` vtables at object offsets `+0x0/+0xa0/+0xa4`, clears the bank singleton, then tail-calls base teardown. |
| `OnDialogAction` | `0x0048b630-0x0048b7dc` | Vtable-reached action handler; action `1` sends close packet `0x36/0x0b`, and action `2` submits opcode `0x36` subtype `0x0d` or `0x0c` from the `+0x26c` mode field, serializes the selected slot as a zero-extended UInt16BE value, writes the multi-count flag and UInt32BE amount, then sends the close packet. |
| raw packet helpers | [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md) | Two function-shaped opcode `0x36` packet helpers without IDA function objects or inbound xrefs. |
| destructor/thunks | `0x0048c2bd`, `0x0048c2c8`, `0x0048c410-0x0048c46f` | Generated secondary/tertiary adjustor thunks and scalar deleting destructor wrapper. |
| singleton cleanup support | `0x0048c260-0x0048c26b` | Compiler cleanup helper that clears `g_pClanBankPane`; not a source method and not an adjustor thunk. |
| `AnimateDialogClose` | `0x0049ed60-0x0049ee41` | Sliding close animation currently owned by `ClanBankPane`, but likely shared with dialog pane behavior. |

## Evidence Notes

- IDA confirms real starts at `0x0048b1c0`, `0x0048b600`, `0x0048b630`, `0x0048c410`, and `0x0049ed60`.
- 2026-05-27 boundary pass corrected `OnDialogAction` to end at `0x0048b7dc`, then documented raw packet helpers at [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md).
- `g_pClanBankPane`, `g_pBackPane`, `g_pDisplayContext`, and `g_pNetConnection` tie the class to live UI/dialog and packet send state.
- The packet opcode `0x36` path in `OnDialogAction` is distinct from the `0x4b` item deposit/withdraw dialogs but still clan-bank feature owned.
- 2026-06-05 live IDA MCP `lookup_funcs` reports modeled functions at `0x0048b1c0` size `0x433`, `0x0048b600` size `0x29`, and `0x0048b630` size `0x1ac`; `xrefs_to` reports constructor code xrefs at `0x00508739` and `0x00513b2f`, no direct vtable-reset xrefs, and the action handler vtable data xref at `0x006162c8`.
- Constructor decompilation writes the `g_pClanBankPane` singleton at `0x0067ade8`, installs three ClanBankPane vtables, stores mode at object offset `+0x26c`, returns early unless action is `10` or `16`, creates the `cl` dialog, button IDs `30` plus mode-specific `53` or `23`, quantity edit default `L"1"`, a child [UID:00010S][0x0048b8c0-0x0048c251.ClanBankItemListPane](by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md), and a count/gold label before attaching to the back pane/display context.
- Action handler decompilation reads list control `4` and quantity edit control `3`; valid submit sends opcode `0x36`, subtype `13 - (mode != 0)`, selected slot zero-extended through `PacketBufferWriteUInt16BE`, a multi-count flag, and parsed amount through `PacketBufferWriteUInt32BE` as a length-`9` packet, then sends the length-`2` close packet `0x36, 11`.
- 2026-06-26 B010 [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md) source-quality implementation: the raw helpers at `0x0048b7e0` and `0x0048b870` remain retained raw helper bodies, not callable modeled methods. Live MCP session `819053f8-f934-49a3-8cef-6cd17f369ff2` / database `80de0a67` reports no function objects, zero xrefs to both starts, no incoming data-flow, and only successor `0x0048b8c0` in the local function query; the PE scan adds no absolute VA, RVA, raw-file-offset, or direct `E8/E9` rel32 route to either start or internal `0x0048b850`. The constructor mode mapping is action `10 -> mode 0 -> submit subtype 0x0d` and action `16 -> mode 1 -> submit subtype 0x0c`; close remains subtype `0x0b`. Because `OnDialogAction` already emits equivalent submit/close packets inline, [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md) keeps blank formal C++ under the target-specific no-code proof.
- 2026-06-15 live IDA recheck:
  - `lookup_funcs` reports modeled sizes `0x433`, `0x29`, `0x1ac`, and `0x5f` for constructor, vtable reset, action handler, and scalar deleting destructor; raw packet helper starts `0x0048b7e0` and `0x0048b870` still report not-a-function.
  - `make_signature_for_range 0x0048b1c0-0x0048b7dc` returns `unique:true`.
  - `xrefs_to` reports constructor callers at `0x00508739` and `0x00513b2f`, action handler vtable data at `0x006162c8`, scalar deleting destructor refs from adjustor thunks and vtable data, seven `g_pClanBankPane` slot refs at `0x0067ade8`, and shared close helper `0x0049ed60` refs from this class plus sibling clan dialogs.
  - `analyze_component` reports the constructor calls [UID:000025][ClanBankItemListPane](by-class/ClanBankItemListPane.md) at `0x0048b8c0`, the vtable-reset helper has no callees, and the action handler calls packet send, quantity/text helpers, and the shared slide-close helper.
- 2026-06-22 B014 destructor-band recheck corrects the scalar-deleting destructor wrapper endpoint to `0x0048c410-0x0048c46f` and classifies `0x0048c260-0x0048c26b` as compiler cleanup support that clears `g_pClanBankPane`, not handwritten ClanBankPane source.
- 2026-07-07 B007 UID0002XK support sync reconfirmed current session `supervisor-nexustk-20260707`: the `g_pClanBankPane` storage at `0x0067ade8` has seven refs with constructor publish/fallback clear at `0x0048b224`/`0x0048b22b`, duplicate-open/action guards at `0x00508706` and `0x00513b07`, and cleanup/destructor clears at `0x0048b61a`, `0x0048c260`, and `0x0048c430`. The `0x0048c260` clear remains lifecycle support, not a `ClanBankPane` source method.

## Score Rationale

Completion is now above the low-score queue because the class page records current method sizes, raw helper non-function status, unique range signature, constructor callers, singleton lifecycle refs, vtable-only dispatch, child list construction, close/submit packet bytes, shared slide-close fan-in, and source-owner routing. Confidence is strong for ClanBank ownership and class behavior; it stays below final-source quality because original virtual names, widget member names, and shared slide helper placement remain provisional.

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md)
- [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md)
- [UID:00012V][0x0049ec80-0x0049ee42.ClanDialogSlideAnimation](by-memory/0x0049ec80-0x0049ee42.ClanDialogSlideAnimation.md)
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)
- [UID:000025][ClanBankItemListPane](by-class/ClanBankItemListPane.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)
- [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md)

## Changes

- 2026-06-30 B009 empty-emitter implementation callback: inserted the accepted declaration-level `ClanBankPane` shell with `m_bankMode`, `SendClosePacket`, `OnDialogAction`, external `g_pClanBankPane`, and `[[CHILDREN]]`; set `EMITTER_POSITION_OPTIONAL:0` and raised score to `87/90`. The B010 selected-slot UInt16BE correction and raw helper no-route proof remain authoritative support evidence for the child method block.
- 2026-05-27: Corrected constructor and `OnDialogAction` exclusive ends to `0x0048b5f3` and `0x0048b7dc`, then added raw packet helpers [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md). Evidence: IDA MCP reports the constructor at `0x0048b1c0-0x0048b5f3`, action handler at `0x0048b630-0x0048b7dc`, and helper-shaped opcode `0x36` packet bodies at `0x0048b7e0` and `0x0048b870`.
- What existed before: the page documented local methods, packet helpers, singleton/global ties, and boundary corrections, but metadata remained `0/0`.
- What it was changed to: scores were set to `76/80`.
- Summary and evidence: dialog construction, action packet behavior, raw helper span, destructor, and clan-bank state ownership are covered; shared slide-close ownership and exact widget/layout fields remain open.
- 2026-06-05: Initially marked reconstructable but left `AUTOGEN_PARENT_UID` blank because the class was still `76/80`, below the 80/80 parent-attachment gate, even though [UID:0000I9][ClanBank](by-file/ClanBank.md) was the likely owner. Live IDA MCP `lookup_funcs` confirmed exact starts at `0x0048b1c0`, `0x0048b600`, `0x0048b630`, `0x0048c2bd`, `0x0048c2c8`, `0x0048c410`, and `0x0049ed60`, while `0x0048b7e0` and `0x0048b870` remained non-function raw packet-helper bodies.
- 2026-06-05: Raised scores to `82/86` and attached parent [UID:0000I9][ClanBank](by-file/ClanBank.md) after live IDA MCP decompilation/caller/callee/xref review documented constructor mode selection, child list construction, singleton writes/clears, vtable-only action dispatch, opcode `0x36` close/submit packet bytes, and caller ties from the map packet/clan-bank routing paths. Final C++ remains blank because original method names, widget member names, and shared slide-helper placement are still not final.
- 2026-06-05: Removed stale recovered-source/global/offset wording while preserving the `82/86` score.
- 2026-06-15 A002 Goal 2 by-class refresh: raised to `86/89` after live IDA reconfirmed modeled method sizes, raw packet helper non-functions, unique class-range signature, two constructor callers, action-handler vtable anchor, singleton refs, child list construction edge, scalar deleting destructor refs, and shared close-helper fan-in. Owner/emitter route remains [UID:0000I9][ClanBank](by-file/ClanBank.md); final C++ remains blank pending source-quality method/widget names and shared helper placement.
- 2026-06-22 B014 Rule 26 support sync: corrected the destructor wrapper half-open range to `0x0048c410-0x0048c46f` and added the `0x0048c260` singleton-clear cleanup helper as non-emitting lifecycle support; scores and owner/emitter are unchanged.
- 2026-06-26 B010 [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md) support sync: corrected the `OnDialogAction` selected-slot packet field from a byte to a zero-extended UInt16BE value, preserved the raw helper no-route/no-code status, recorded the constructor mode/subtype mapping, and kept ClanBank ownership unchanged.
- 2026-07-07 B007 UID0002XK implementation support sync: added current-session seven-ref role detail for `g_pClanBankPane`, including duplicate-open guards and cleanup clears; no metadata or formal C++ change.
