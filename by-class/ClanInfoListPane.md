*** UID:00002E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Clan.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../ui/controls/TextEditPane.h"

class Event;

class ClanInfoListPane : public TextEditPane
{
public:
    ClanInfoListPane();

protected:
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanInfoListPane

## Status

- Confidence: strong for purpose, inline construction, embedded `TextEditPane` layout, the two event-rejection overrides and their exact vtable slots, Clan source route, and the accepted UID00021T formal no-code marker.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Memory evidence: [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md), [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md), [UID:0002NN][0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual](by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md), and [UID:0002NO][0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual](by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md)
- Parent routing: attached to the [UID:0000I8][Clan](by-file/Clan.md) source file; child memory pages now attach back to this class now that both sides meet the parent gate.
- Formal source placement: the complete ClanInfoListPane declaration emits through RECONSTRUCTION_H into NexusTK/social/Clan.h. RECONSTRUCTION_CPP includes "Clan.h" and expands [[CHILDREN]], so UID0002NN and UID0002NO remain the sole method-body owners in Clan.cpp. Inheritance requires ../ui/controls/TextEditPane.h; Event is forward-declared because it appears only as Event *.

## Class Purpose

`ClanInfoListPane` is a specialized read-only `TextEditPane` child created inline by `ClanStatusPane`. Its confirmed event overrides return false from key/text and mouse dispatch, making it a passive clan information view that declines direct event handling rather than an action-gate object.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| projected/raw constructor | [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md) | Constructor-shaped bytes that install `ClanInfoListPane` vtables; current MCP session `279422f0` reports no function object and no inbound start route, so this is resolved as a formal no-code/covered-by marker rather than a callable constructor emitter. |
| inline setup in `ClanStatusPane` constructor | `0x004840b2-0x00484135` | Allocates the 372-byte `TextEditPane` child, installs `ClanInfoListPane` vtables, stores it at `ClanStatusPane + 0x2510`, calls `Pane::SetMode(1)`, and applies the TextEditPane read-only/inactive mode setup. |
| `HandleKeyOrTextEvent(Event *)` | [UID:0002NN][0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual](by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md) | Returns false from `EventHandler` secondary-vtable slot `+0x08`; sole data/vtable xref is cell `0x00615678`. |
| `OnMouseEvent(Event *)` | [UID:0002NO][0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual](by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md) | Returns false from the primary-vtable slot `+0x60`; sole data/vtable xref is cell `0x00615658`. |

## Evidence Notes

- IDA MCP rechecked on 2026-05-24 and 2026-05-27: `0x004885a0` is not an IDA function and has no xrefs, but [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md) records the constructor-shaped byte body and vtable stores.
- `ClanStatusPane::ClanStatusPane` allocates 372 bytes, calls the `TextEditPane` constructor helper with `(156, 192, 156, 192, 128, 0, 0, 1, 2, helper-result, 1, 0)`, where the helper call is at `0x004b60b0`, and installs `ClanInfoListPane` vtables at object offsets `+0x0`, `+0xa0`, and `+0xa4`.
- IDA confirms the two false-return virtuals at `0x00488610` and `0x00488620`.
- IDA MCP recheck on 2026-05-26 reconfirms `0x00488610` and `0x00488620` as five-byte false-return functions and places them in `ClanInfoListPane` vtable cells `0x00615678` and `0x00615658`.
- 2026-05-31 IDA MCP recheck split those false-return virtuals into exact memory pages [UID:0002NN][0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual](by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md) and [UID:0002NO][0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual](by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md).
- 2026-06-05 live IDA refreshes on [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md), [UID:0002NN][0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual](by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md), and [UID:0002NO][0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual](by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md) reconfirm raw constructor-shaped bytes, exact false-return bodies, vtable-only xrefs, no direct callers for the tiny virtuals, and Clan source ownership.
- 2026-06-15 A003 refresh: Wave2 `struct ClanInfoListPane` reports a 372-byte class with `TextEditPane` at offset `0`, matching the inline allocation. Wave2 `method 0x004885a0` keeps the constructor-shaped body canonical but inactive/excluded, with zero callers and callees `0x004b60b0`/`0x0058dce0`. Live IDA lookup reconfirms no function object at the raw constructor start, and a local PE scan finds no VA/RVA pointer or relative branch/call target to `0x004885a0`.
- Historical 2026-06-17 B002 source-quality pass interpreted the two bodies as `CanExecuteAction(int)` and `CanExecuteAlternateAction(int)`. That action-gate interpretation is retained as superseded research: it correctly identified exact `xor al, al; retn 4` bodies and distinct vtable-only refs but did not identify the secondary `EventHandler` and primary mouse-event slot contracts.
- 2026-06-29 B005 UID00021T implementation callback: MCP session `279422f0` reconfirmed the raw start is not an IDA function, has no inbound route, is a 99-byte body between 12-byte and 13-byte `0xcc` padding spans, reads `0x0067ab24`, calls `0x004b60b0` and `0x0058dce0`, and stores vtables `0x006155f8`, `0x00615670`, and `0x006156a0`. Local PE scans found no VA/RVA/direct-branch route to `0x004885a0`; paired vtable xrefs tie the raw body to live inline stores in [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md).
- The projected constructor is now represented by a formal no-code marker covered by [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md) inline child construction and this class/virtual declaration. It should not be used as a callable constructor rename/source-map anchor unless a future direct route is proven.
- 2026-08-06 B010 UID0002NO callback resolves the source identities from their exact vtable contracts. UID0002NN is `HandleKeyOrTextEvent(Event *)` at `EventHandler` secondary base `0x00615670`, slot `+0x08`, cell `0x00615678`; UID0002NO is `OnMouseEvent(Event *)` at primary base `0x006155f8`, slot `+0x60`, cell `0x00615658`. Both consume one `Event *`, return false, have no code callers, and remain separate source-authored overrides despite identical five-byte bodies.
- Dated command 000000023008 first recorded the pre-repair defect: Clan.cpp contains one CPP-local ClanInfoListPane declaration and both exact child definitions, while Clan.h contains no ClanInfoListPane declaration. Commands 000000023051, 000000023075, and the 2026-08-13T08:00:06-04:00 report-only snapshot 000000023100 confirm the same disposition. The accepted formal split moves the declaration to H, includes Clan.h from CPP, and preserves the child definitions without duplication.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md)
- [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md)
- [UID:00010I][0x00488610-0x004888f1.ClanListPaneVirtuals](by-memory/0x00488610-0x004888f1.ClanListPaneVirtuals.md)
- [UID:0002NN][0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual](by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md)
- [UID:0002NO][0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual](by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md)
- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)

## Score Rationale

- Historical 2026-06-15 score was `85/89`: the class had inline construction, embedded-base size, false virtuals, raw constructor evidence, source route, and no-hidden-reachability checks documented well enough to clear the strict direct-parent gate for [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md).
- 2026-06-29 B005 implementation keeps the class score unchanged but resolves the raw UID00021T empty-emitter issue: the constructor-shaped bytes remain class-owned evidence, and emitted source is covered by the inline construction route plus `ClanInfoListPane` class/virtual declarations.
- 2026-08-06 score is `90/93`: the class now has a human-source declaration for both event overrides, exact primary/secondary vtable bases and offsets, sole-cell xrefs, one-argument ABI proof, behavior, ownership, and source routing. The remaining margin reflects the historical raw/no-route constructor body and broader final class-layout polish, not unresolved identities for the two tiny virtuals.

## Changes

- 2026-06-29 B005 UID00021T implementation callback: recorded the accepted formal no-code marker for [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md). Evidence: MCP session `279422f0` and local PE scans prove no function/direct route at `0x004885a0`, while [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md) contains the live inline child construction and the same `ClanInfoListPane` vtable stores.
- 2026-05-27: The constructor entry previously described `0x004885a0` only as a projected start to avoid. Changed it to [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md): a real constructor-shaped byte body with no IDA function object or inbound xrefs. Evidence: IDA MCP raw disassembly shows `ClanInfoListPane` vtable stores at `+0x0`, `+0xa0`, and `+0xa4`, while xref/function scans remain negative.
- What existed before: the page documented inline construction, passive read-only behavior, false-return virtuals, and raw constructor caveats, but metadata still read `0/0`.
- What it was changed to: scores were set to `78/84`.
- Summary and evidence: inline allocation/setup, vtable slots, raw constructor bytes, and read-only virtual behavior are covered; source-facing declaration and standalone constructor modeling remain incomplete.
- 2026-05-31: Replaced raw false-virtual addresses with exact by-memory links. Evidence: IDA MCP `lookup_funcs`, `decompile`, and `xrefs_to` confirm the two five-byte bodies and their vtable xrefs.
- 2026-06-05: Marked reconstructable, but left `AUTOGEN_PARENT_UID` blank because the class was `78/84`, below the 80/80 parent-attachment gate, even though [UID:0000I8][Clan](by-file/Clan.md) remained the likely owner. Live IDA MCP `lookup_funcs` confirmed the false-return virtuals at `0x00488610` and `0x00488620`, and reconfirmed that `0x004885a0` is not an IDA function.
- 2026-06-05: Updated to `82/88`, attached parent `0000I8`, removed stale external recovered-file and projected-start issue references, converted helper-call evidence to address-based wording, and routed [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md), [UID:0002NN][0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual](by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md), and [UID:0002NO][0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual](by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md) under this class now that the class and children meet the parent gate. Evidence: the same-day child refreshes document the raw constructor-shaped bytes, exact false-return bodies, vtable-only xrefs, no direct callers for the tiny virtuals, and Clan source ownership.
- 2026-06-15 A003 goal2 clan-status/list pass: Raised `82/88` to `85/89` to support the current strict parent gate for [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md). Evidence: Wave2 struct/method data confirms the 372-byte `TextEditPane`-based class and inactive zero-caller raw constructor, live IDA reconfirms no function object at `0x004885a0`, local PE scans find no pointer/branch route to the raw start, and the inline `ClanStatusPane` construction path remains the primary source anchor.
- 2026-06-17 B002 source-quality pass: class score unchanged, but [UID:0002NN][0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual](by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md) and [UID:0002NO][0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual](by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md) now carry first-draft C++ and `86/91` target scores. The class-level cap remains the inactive/no-xref raw constructor and final declaration spelling, not the two tiny action-gate children.
- 2026-08-06 B010 UID0002NO implementation callback: raised `85/89` to `90/93`, replaced the superseded action-gate declarations with `HandleKeyOrTextEvent(Event *)` and `OnMouseEvent(Event *)`, and documented their exact secondary `+0x08` and primary `+0x60` vtable contracts. The UID00021T raw-constructor no-code/covered-by history and inline-construction evidence remain unchanged.
- 2026-08-13 B010 report repair: identified the formal-channel defect exposed by dated generated command 000000023008 and confirmed by commands 000000023051/000000023075/000000023100; specified the complete declaration move from CPP to H, the TextEditPane/Event dependency lines, the Clan.h include before [[CHILDREN]], declarative scoped-validator receipt requirements, and exact final Clan.h/Clan.cpp readbacks. No metadata, method body, IDA state, or raw-constructor history changes.
