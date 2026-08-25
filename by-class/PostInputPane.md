*** UID:0000AO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ID | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000ID | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class PostInputPane : public CharInputPane
{
public:
    PostInputPane();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnConfirmInput();
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PostInputPane

## Status

- Confidence: strong for behavior, vtable identity, and command-input module placement.
- Likely source file: [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- Address range: [UID:0001MK][0x005b5630-0x005b5890.PostInputPane](by-memory/0x005b5630-0x005b5890.PostInputPane.md)
- Vtable family: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)

## Class Purpose

`PostInputPane` is a single-letter post selection prompt. It formats a localized prompt with the player name, accepts a letter mapped to a post index, validates it against the active user/status pane limit, and sends post command opcode `0x34`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `PostInputPane` | `0x005b5630-0x005b56f7` | Constructs prompt with player name and installs vtables. |
| `HandleKeyOrTextEvent` | `0x005b5700-0x005b576c` | Translates the Event key/modifiers, handles the exact Shift-only `?` key-down help shortcut, and otherwise delegates to `CharInputPane`. |
| `OnConfirmInput` | `0x005b5770-0x005b5830` | Converts letter to post index and sends opcode `0x34`. |
| `SendPostPacketRawHelper` | `0x005b5830-0x005b5890` | Raw IDA-unmodeled helper that writes opcode `0x34`, one signed byte argument, and sends two bytes through `g_packetSender`; no direct xref to the raw start. |

## Evidence Notes

- 2026-06-05 IDA MCP `analyze_funcs` confirms modeled extents `0x005b5630-0x005b56f7`, `0x005b5700-0x005b576c`, and `0x005b5770-0x005b5830`.
- Raw byte/disassembly review confirms `0x005b56f7-0x005b5700` and `0x005b576c-0x005b5770` are `0xcc` alignment spans, while `0x005b5830-0x005b5890` is executable helper-shaped packet-send code.
- IDA MCP confirms three `PostInputPane` vtable views at `0x00630160`, `0x006301b0`, and `0x006301e0`, with stores from the command dispatcher `0x005a5bd0`, open helper `0x005a9a90`, and constructor `0x005b5630`.
- Vtable data xrefs put `OnConfirmInput` at slot `0x006301a8` and `OnKeyInput` at slot `0x006301b8`.
- The constructor reads local-player/name data through [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md), localized prompt id `11` through [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), then sets the prompt text through the shared input-pane helper.
- The key handler accepts only the `?` shortcut event shape, switches [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md) to tab `2`, invokes sound/effect id `0x198`, and delegates all other input to the base handler.
- The confirm handler maps `a-z` to `1-26` and `A-Z` to `27-52`, checks [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) offset `+0x284`, and queues packet bytes `{ 0x34, postIndex }` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).

## Rule 26 Inference And Source-Quality Notes

- B001 2026-06-17 rejected `InputPanes.cpp` ownership because this island installs `PostInputPane` vtables and performs Post-specific prompt/packet behavior, while shared `CharInputPane`/`LineInputPane` helpers remain dependencies only.
- B001 rejected `SpellInputPanes.cpp`: the `?` shortcut resembles nearby spell/string input panes, but the tab id, prompt id `11`, vtable slots, and opcode `0x34` behavior are Post-specific.
- B001 rejected `ItemActionInputPanes.cpp` and successor `ThrowInputPane` ownership because `0x005b5890` is the exclusive successor boundary and no Post byte overlaps the item-action range.
- A standalone `PostInputPane.cpp` is not currently supported by the project source-tree evidence; `CommandInputPanes.cpp` remains the best source-placement inference for Emotion/Group/Post command prompts.
- The raw helper at `0x005b5830` is treated as a retained source-authored file-local/private helper, not padding, a compiler runtime artifact, or an unrelated dead routine. Its body is domain-specific and repeats the Post opcode `0x34` two-byte send shape.
- Generated source names that route this behavior through `SpellStringInputPane`, `QuitInputPane`, `CashShopRequest`, `g_pPlayerData`, or `g_pLocalPlayer` are source-pollution leads. Use shared input-pane helper names, [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md), and packet sender ownership through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) unless those globals are renamed project-wide.
- The best current field inference for [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) offset `+0x284` is `activeSlotLimit` or `maxSelectableSlot`; a narrower `maxPostIndex` name is rejected because the field participates in broader active selection contexts.

## B003 2026-07-20 Event Contract Completion

- The complete source declaration now names `bool HandleKeyOrTextEvent(Event *event)` and retains the constructor and `void OnConfirmInput()` virtual. The class closes before `[[CHILDREN]]`, so [UID:0001MK][0x005b5630-0x005b5890.PostInputPane](by-memory/0x005b5630-0x005b5890.PostInputPane.md) emits its constructor, handler, packet helper, and confirm body at namespace scope.
- The corresponding child formal changes only stale shared Event vocabulary: it preserves tab `2`, `NULL`, effect `0x198` at volume 100, post letter conversion `1..52`, active-slot bound, opcode `0x34`, two-byte packet length, and retained helper source shape.
- The score rises from `87/91` to `90/92` because the complete class surface and source-facing Event signature are now closed; confidence remains below 95 because private helper and active-slot field spellings are inferred.

## Source Placement

Attach this class to [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md). Both pages meet the parent gate, and the behavior is command/post routing rather than item-action ownership. The complete class declaration now belongs in the formal H channel while CPP contains only `[[CHILDREN]]`; constructor, handler, confirmation, and helper definitions remain on [UID:0001MK][0x005b5630-0x005b5890.PostInputPane](by-memory/0x005b5630-0x005b5890.PostInputPane.md).

## 2026-08-14 RTTI, Layout, And Header Closure

- Primary, EventHandler, and TimerHandler heads are `0x630160`, `0x6301b0`, and `0x6301e0`. Their COLs are `0x6533bc`, `0x653420`, and `0x653434`, selected by locator cells `0x63015c`, `0x6301ac`, and `0x6301dc` with PMD offsets `0`, `+0xa0`, and `+0xa4`.
- Type descriptor `0x67a148` is `.?AVPostInputPane@@`. CHD `0x6533d0` carries eight exact bases in order: `PostInputPane`, `CharInputPane`, `LineInputPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, and `TimerHandler`.
- The complete object is `0x108` bytes, matching the inherited prompt layout. Constructor, handler, confirmation, and helper behavior support no persistent derived field, so no speculative member is added.
- Primary slot `0x6301a8 -> 0x5b5770` proves `OnConfirmInput`. Adjusted EventHandler slot `0x6301b8 -> 0x5b5700` proves `HandleKeyOrTextEvent`; the physical receiver is the `+0xa0` EventHandler view, while the source declaration remains the natural `Event *event` class virtual. Timer slot `0x6301e4 -> 0x544e90` remains inherited.
- Shared deleting wrapper `0x5b7940` and `-0xa0`/`-0xa4` adjustors `0x5b77c8/0x5b77d3` are compiler-generated across the prompt family. They do not support a handwritten Post destructor or thunk source.
- The constructor installs all three table heads at `0x5b5677/0x5b567d/0x5b5687`; dispatcher and open-helper mirrors install them at `0x5a6718/1e/28` and `0x5a9aeb/f1/fb`. This agreement closes class identity and construction layout independently of source naming.
- Header/source order is Post declaration position `60` after Group `50`; the exact method cluster is child position `10`. ABI-data and source-local index markers follow at direct positions `70` and `80`.
- Moving the declaration out of CPP fixes the dated generated defect in which `CommandInputPanes.h` lacked Post while CPP carried the class shell. The H payload is the evidence-backed declaration; no extra field, explicit destructor, raw vtable array, or duplicate declaration is required.
- Historical alternatives remain documented: `SpellInputPanes.cpp`, `ItemActionInputPanes.cpp`, and a standalone Post file were considered and rejected from prompt id, tab/effect, opcode, boundary, vtable, and complete Emotion/Group/Post source-family evidence.

## Score Rationale

Completion `92` reflects the complete constructor/handler/confirm/helper surface, eight-base RTTI, exact three-view layout, no-field/no-destructor closure, formal H declaration, child source routing, and source order. Confidence `94` reflects agreement between slots, COL/PMD data, constructor stores and mirrors, modeled method behavior, packet shape, and exact boundaries. Remaining uncertainty concerns stripped original filename/private-helper spelling and the broader `+0x284` field name, not class behavior or emitted source structure.

## Cross-References

- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0001MK][0x005b5630-0x005b5890.PostInputPane](by-memory/0x005b5630-0x005b5890.PostInputPane.md)
- [UID:00005W][GroupInputPane](by-class/GroupInputPane.md)
- [UID:0002N6][0x006300d4-0x006301e8.GroupPostInputPaneVtableData](by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)

## Changes

- 2026-08-14 Agent-B010 UID0002N6 callback: raised `90/92 -> 92/94`, set direct file position `60`, moved the complete declaration from CPP into H, left CPP as `[[CHILDREN]]`, and added all eight RTTI bases, exact `0x108` three-view layout, no-field/no-destructor conclusions, constructor-store closure, source/header ordering, rejected alternatives, and score rationale.
- 2026-06-17 B001 source-quality execution:
  - Before: score was `82/90`, the class still linked to the stale `0x005b5630-0x005b5830` filename, and first-draft C++ readiness was deferred to final-source naming.
  - After: raised to `87/91`, corrected the backing method page link to [UID:0001MK][0x005b5630-0x005b5890.PostInputPane](by-memory/0x005b5630-0x005b5890.PostInputPane.md), kept owner/emitter [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), and kept class-level formal C++ blank because the method/helper bodies now emit from the corrected by-memory page.
  - Evidence: B001 rechecked the constructor/key/confirm/raw helper range, vtable-only reachability, prompt id `11`, local-player name helper, `?` tab-2 help shortcut/effect, `a-z`/`A-Z` index mapping, `g_activeUserStatusPane +0x284` active-slot-limit semantics, opcode `0x34` send through `g_packetSender`, and the exclusive successor boundary at `0x005b5890`.

- 2026-06-05 live IDA refresh:
  - Before: the page was scored `72/84`, class autogen parent was blank, and the method inventory stopped at `0x005b5830`.
  - After: raised to `82/90`, attached to [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), added the raw `0x005b5830-0x005b5890` post packet helper, and kept the evidence chain on IDA/project-documentation sources.
  - Evidence: IDA MCP confirms the modeled method extents, vtable slots/stores, raw helper bytes, global dependencies, post opcode `0x34`, active status-pane slot-limit check, and exclusive boundary before the item-action `ThrowInputPane` constructor at `0x005b5890`. This old no-C++ note was superseded by the 2026-06-17 source-quality pass, which emits first-draft method/helper C++ from the corrected by-memory page while keeping the class page as ownership/layout documentation.

- Earlier 2026-06-05 scoring/classification pass:
  - Before: completion/confidence metadata were `0/0` and reconstructable metadata was blank despite documented class purpose, three method starts, vtable views, packet opcode, and command-input placement.
  - After: set `COMPLETION:72`, `CONFIDENCE:84`, and `RECONSTRUCTABLE:TRUE`; parent attachment was deferred at that time because the class did not yet meet the 80/80 attach gate.
