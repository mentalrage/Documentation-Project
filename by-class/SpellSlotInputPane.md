*** UID:0000DS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "SpellInputPanes.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "InputPanes.h"

class Event;

class SpellSlotInputPane : public CharInputPane
{
public:
    explicit SpellSlotInputPane(char spellIndex);
    virtual ~SpellSlotInputPane();

    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void SubmitSpellSlot();

private:
    void SendSpellUsePacket(char inventorySlot);

    char m_spellIndex;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

## UID0001LM Signed Prompt-Class Synchronization - 2026-07-19

- The complete declaration now takes plain `char spellIndex` and stores plain `char m_spellIndex` at complete-object `+0x108`. Repeated constructor/consumer `movsx` proves signed semantics; the object remains exactly `0x10c` bytes with natural tail alignment at `+0x109..+0x10b`.
- The class closes before `[[CHILDREN]]`, so exact child definitions emit at namespace scope rather than inside the class. Inheritance and every existing method declaration/access level are unchanged.
- Metadata rises `87/89 -> 89/92` because signed type, exact natural layout, complete declaration, and generated structure are closed. Exact owner/emitter/source route, unrelated method bodies, retained or ownerless no-route raw helpers, destructor/scalar/adjustor evidence, compiler exclusions, and history remain intact.
- Constructors use the shared public inline `UserPane::GetSpellPromptText(char) const`; no private cross-TU table access, `UserSpellRecord`, `GetSpellRecord`, or raw vtable/RTTI/compiler source is introduced.

# SpellSlotInputPane

## 2026-07-20 UID0001MP Shared Event Contract

- R14 provides the complete CharInputPane-derived declaration with signed spell index, constructor/destructor, canonical `HandleKeyOrTextEvent(Event *)`, submit callback, class closure, and namespace-scope children.
- UID0001LW preserves exact Shift+`?` key-down behavior, EventMan translation, tab-3/null then effect-`0x198`/100 order, true return, and UID000364 fallback. Independent constructor, submit child, no-route sender, vtable/padding/compiler evidence, and historical source split remain unchanged.
- Scores become `90/93`; owner/emitter UID0000O0, reconstructable true, blank position, layout, and source route remain unchanged. Stale `OnKeyInput`/`InputEvent` vocabulary is superseded without altering unrelated SpellSlot behavior.

## Status

- Confidence: strong for behavior and IDA boundaries.
- Likely source file: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- Address range: [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_SpellSlotInputPane.cpp`

## Class Purpose

`SpellSlotInputPane` is a spell-use inventory-slot letter prompt. It stores one plain-char spell index, maps a typed letter to a validated one-based inventory slot, and sends opcode `0x0f` with the stored spell index and selected inventory slot.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | [UID:0001LV][0x005b1280-0x005b130d.SpellSlotInputPaneConstructor](by-memory/0x005b1280-0x005b130d.SpellSlotInputPaneConstructor.md) | Builds [UID:00001P][CharInputPane](by-class/CharInputPane.md), installs vtables, sets spell prompt text, and stores the spell bar index. |
| destructor | [UID:0004UC][0x005b1310-0x005b1393.SpellSlotInputPaneDestructor](by-memory/0x005b1310-0x005b1393.SpellSlotInputPaneDestructor.md) | Sole human virtual destructor body: selects EPF/legacy child-index-3 state, clears its input-mode flag, and relies on implicit base cleanup; all compiler mechanics remain excluded. |
| `HandleKeyOrTextEvent` | [UID:0001LW][0x005b13a0-0x005b140c.SpellSlotInputPaneKeyInput](by-memory/0x005b13a0-0x005b140c.SpellSlotInputPaneKeyInput.md) | Handles the Shift+`?` key-down help/panel shortcut through canonical `Event`/EventMan translation, switches [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md) to tab `3`, plays effect `0x198` at 100, and otherwise forwards to [UID:00001P][CharInputPane](by-class/CharInputPane.md); current route is `0x0062f6c8 -> 0x005b13a0` with padding before submit. |
| `SubmitSpellSlot` | [UID:0001LX][0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot](by-memory/0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot.md) | Decodes one typed slot letter, maps `a-z` to inventory slots `1..26` and `A-Z` to `27..52`, preserves signed plain-char lower-bound behavior, checks `inventorySlot` against `g_activeUserStatusPane->m_inventorySlotCount`, then calls `SendSpellUsePacket(inventorySlot)` in source. Vtable route remains `0x0062f6b8 -> 0x005b1410`; the binary contains the helper tail inline as compiler-lowering evidence. |
| `SendSpellUsePacket` | [UID:0003VX][0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw](by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md) | Private retained/no-route source helper taking plain `char inventorySlot`; uses 300-byte packet scratch, writes opcode `0x0f`, plain-char `m_spellIndex` from `+0x108`, inventory-slot byte, and an unsent terminator, then sends exactly three bytes through `g_packetSender`. |
| adjustor thunks | [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks to `0x005b7dc0`; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:0001NG][0x005b7dc0-0x005b7e84.SpellSlotInputPaneScalarDeletingDestructor](by-memory/0x005b7dc0-0x005b7e84.SpellSlotInputPaneScalarDeletingDestructor.md) | `92/94` compiler-only wrapper: expands the source cleanup, restores all class views, runs implicit base cleanup, consumes scalar flags, optionally frees `this`, and emits no human C++. |

## Evidence Notes

- IDA confirms the constructor, key handler, submit handler, two thunks, and scalar deleting destructor.
- Constructor callers are spell inventory cast dispatch paths at `0x0057c9b0`, `0x0057e2d0`, and `0x0057f030`.
- Disabled generated output marks `0x005b78af` as missing code, but IDA confirms it as a real adjustor thunk.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x005b7dc0` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-06-19 B013 rechecked [UID:0003VX][0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw](by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md) and promoted it from ownerless no-route raw island to retained `SpellSlotInputPane` source code. No static caller/pointer route to `0x005b14f0` is proven, but the helper has `thiscall` shape, reads the constructor-initialized `+0x108` spell-index byte, duplicates the packet-send tail of `SubmitSpellSlot`, and now emits draft `SendSpellSlotPacket(signed char selectedSlot)` through this class.
- 2026-07-31 B005 current source-quality reanalysis preserved UID0003VX's zero-entry-route facts but resolved its source contract as private `SendSpellUsePacket(char inventorySlot)`. Exact target/submitter stack intervals both establish a 300-byte packet scratch; UID0001LX's letter decode and `m_inventorySlotCount` comparison establish the argument domain/type; the retained body plus exact inline duplicate establishes a source call compiled inline.
- 2026-07-07 B005 current MCP session `supervisor-nexustk-20260707` reconfirmed [UID:0001LW][0x005b13a0-0x005b140c.SpellSlotInputPaneKeyInput](by-memory/0x005b13a0-0x005b140c.SpellSlotInputPaneKeyInput.md) as the class-owned key override: exact range `0x005b13a0-0x005b140c`, vtable-only route `0x0062f6c8 -> 0x005b13a0`, predecessor padding `0x005b1393-0x005b13a0`, four-byte padding `0x005b140c-0x005b1410` before [UID:0001LX][0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot](by-memory/0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot.md), accepted `?` shortcut predicates, `SwitchActiveTab(3,false)`, `PlayEffect(0x198,100)`, and `CharInputPane::OnKeyInput` fallback.
- 2026-07-07 B007 current MCP session `supervisor-nexustk-20260707` reconfirmed [UID:0001LX][0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot](by-memory/0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot.md) as the class-owned submit handler: exact range `0x005b1410-0x005b14e6`, vtable route `0x0062f6b8 -> 0x005b1410`, target pointer bytes only at `0x62f6b8`, one-character letter-slot mapping, active-status `+0x284` max-slot check, opcode `0x0f` length `3`, and inline target packet writes preserved while [UID:0003VX][0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw](by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md) stays a separate retained no-route helper.
- 2026-07-20 B003 healthy MCP session `9b0396a3` proves UID0004UC `[0x005b1310,0x005b1393)`, size `0x83`, SHA256 `0C790092FA101DC253189374C74A67099CCD7F18B0483055A25C37D21E3F525E`, as the ordinary source destructor. UID0001NG `[0x005b7dc0,0x005b7e84)`, size `0xc4`, SHA256 `A293B245A4A4E9E98152A2AD366CA3F666BD4102DF35F1BC939FB29B947B9A28`, is the scalar compiler wrapper reached from primary cell `0x0062f670` and `-0xa0`/`-0xa4` adjustors.
- Both variants restore class views at complete-object offsets `+0x00`, `+0xa0`, and `+0xa4`, select `g_pGeneralPurposePanel` child index `3` through `g_useEpfAssets`, clear the accepted state Boolean, and lower implicit `LineInputPane` cleanup. Only UID0004UC emits the human mode branch; raw vptr/base/delete/guard/cookie/EH/adjustor/RTTI mechanics remain compiler products.
- Layout remains exact: `CharInputPane` base through `+0x107`, signed `char m_spellIndex` at `+0x108`, and natural non-member tail alignment `+0x109..+0x10b`, total `0x10c`. No synthetic layout fields or raw offset comments enter R2.
- UID0003VX emits `SpellSlotInputPane::SendSpellUsePacket(char inventorySlot)` after class closure. The formal declaration now lives in `SpellInputPanes.h`, includes the complete `CharInputPane` base through `InputPanes.h`, and keeps child definitions at namespace scope in the paired CPP channel.

## Source Placement And Compiler Separation

- Formal CPP includes `SpellInputPanes.h` and emits `[[CHILDREN]]`; it no longer contains the class declaration.
- Formal H includes `InputPanes.h`, forward-declares `Event`, and owns the complete declaration, inheritance, access levels, constructor, virtual destructor, two virtual methods, private sender, and `m_spellIndex` field.
- Natural alignment bytes `+0x109..+0x10b` are not source members. Scalar deleting destruction, `-0xa0`/`-0xa4` adjustors, raw vptr restoration, RTTI, cookies, and implicit base-cleanup lowering remain compiler artifacts and do not enter the declaration.
- Source file route remains [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) `NexusTK/ui/dialogs/SpellInputPanes.cpp` with paired generated `SpellInputPanes.h`; no packet-utility or raw-helper file owns this class behavior.

## Historical Source-Factoring Correction

- B013's `SendSpellSlotPacket(signed char selectedSlot)` declaration and B007's preserve-inline submitter source were conservative descriptive decisions made before the final type/stack/family reanalysis.
- Those decisions remain historical evidence. They are superseded by plain `char inventorySlot`, the 300-byte packet scratch, and `SendSpellUsePacket` source factoring. Exact binary ranges, inlined packet statements, no-route status, vtable routing, and sibling-helper independence are unchanged.

## Score Rationale

- Completion `93`: exact inheritance, `0x10c` layout, plain-char field, constructor, virtual destructor, canonical Event override, source-factored submitter, retained private sender, direct/scalar/adjustor/vtable provenance, complete CPP/H channels, generated closure requirements, and historical correction are documented.
- Confidence `94`: exact decorated class/vtable/RTTI evidence, constructor stores, method routes, direct/scalar normalized bodies, accepted field/helper types, and current generated union converge. Missing original source/PDB caps the score below 95.

## Cross-References

- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md)
- [UID:0004UC][0x005b1310-0x005b1393.SpellSlotInputPaneDestructor](by-memory/0x005b1310-0x005b1393.SpellSlotInputPaneDestructor.md)
- [UID:0003VX][0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw](by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md)
- [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md)
- [UID:0000DU][SpellStringInputPane](by-class/SpellStringInputPane.md)
- [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md)

## Changes

- 2026-08-01 B005 accepted UID0003VX implementation callback:
  - Raised `91/94 -> 93/94`, preserving owner/emitter UID0000O0, reconstructable true, blank position, inheritance, `0x10c` layout, direct/scalar/adjustor/vtable evidence, and compiler exclusions.
  - Moved the complete declaration from formal CPP to formal H, added `InputPanes.h` and `Event` forward declaration, changed the private contract to `SendSpellUsePacket(char inventorySlot)`, and made formal CPP include `SpellInputPanes.h` before `[[CHILDREN]]`.
  - Incorporated the 300-byte packet scratch, plain-char inventory-slot semantics, UID0001LX source-call/compiler-inline relationship, exact source placement, and dated B013/B007 historical correction without altering unrelated methods or sibling dispositions.
- 2026-07-20 Agent-B003 UID0001NG accepted callback:
  - Raised `90/93 -> 91/94`, preserving owner/emitter UID0000O0, reconstructable true, blank position, exact inheritance/layout, and class closure before `[[CHILDREN]]`.
  - Installed exact R2 by adding private `SendSpellSlotPacket(signed char selectedSlot)` for unchanged UID0003VX, and added UID0004UC direct-source/UID0001NG scalar-compiler/vtable provenance without compiler artifacts or synthetic fields.
- 2026-07-07 B007 UID0001LX implementation callback:
  - Expanded the `SubmitSpellSlot` row and evidence notes with current-session proof for [UID:0001LX][0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot](by-memory/0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot.md): route `0x0062f6b8 -> 0x005b1410`, one-character `a-z`/`A-Z` slot mapping, active-status `+0x284` check, opcode `0x0f` length `3`, and the B007 decision to preserve inline packet writes while UID0003VX remains separate retained helper source.
  - No class score, owner/emitter metadata, or declaration C++ changed under B007.
- 2026-07-07 B005 UID0001LW implementation callback:
  - Raised completion/confidence from `86/88` to `87/89` after the key-handler support row gained current-session proof for [UID:0001LW][0x005b13a0-0x005b140c.SpellSlotInputPaneKeyInput](by-memory/0x005b13a0-0x005b140c.SpellSlotInputPaneKeyInput.md): route `0x0062f6c8 -> 0x005b13a0`, exact `?` shortcut predicates, `SwitchActiveTab(3,false)`, `PlayEffect(0x198,100)`, [UID:00001P][CharInputPane](by-class/CharInputPane.md) fallback, and padding before submit.
  - Owner/emitter metadata and class declaration C++ are unchanged; broader class-wide final-audit caveats for field/layout/source-name details remain below final confidence.
- 2026-06-30 B002 SpellInputPanes implementation callback:
  - Added the accepted declaration-only `SpellSlotInputPane : public CharInputPane` formal C++ block with `m_spellIndex` and `[[CHILDREN]]`.
  - Exact constructor, key handler, submit handler, and destructor source bodies remain on the by-memory child pages; [UID:0003VX][0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw](by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md) remains retained no-route helper evidence.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `88`.
- Evidence: the page documents role, constructor/key/submit/destructor/thunk memory docs, spell-slot packet behavior, constructor callers, and ignored adjustor-thunk handling; remaining completion gap is source-ready C++ detail.
- 2026-06-05: Marked reconstructable and attached to [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md).
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, key handler, submit helper, scalar deleting destructor, and adjustor thunks at `0x005b1280`, `0x005b13a0`, `0x005b1410`, `0x005b7dc0`, `0x005b78a4`, and `0x005b78af`; both class (`86/88`) and parent file (`88/80`) meet the 80/80 gate.
- 2026-06-19 B013 retained-helper sync: added [UID:0003VX][0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw](by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md) as source-authored retained no-route `SendSpellSlotPacket`-style code. The no-route evidence remains explicit, while ownership follows the class-specific `this+0x108` field, packet-tail match with [UID:0001LX][0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot](by-memory/0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot.md), and SpellInputPanes source route.
