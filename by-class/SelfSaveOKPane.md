*** UID:0000CX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "SelfSaveOKPane.h"

#include "../../localization/LanguageMan.h"
#include "../../map/BackPane.h"
#include "../MainUiGraph.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_DIALOGS_SELFSAVEOKPANE_H
#define NEXUSTK_UI_DIALOGS_SELFSAVEOKPANE_H

#include "../controls/TextEditPane.h"

class SelfSaveOKPane : public TextBoxPane
{
public:
    SelfSaveOKPane();

protected:
    virtual bool OnTimer(int timerId, int, int);
};

typedef char SelfSaveOKPaneSizeMustBe174[
    (sizeof(SelfSaveOKPane) == 0x174) ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SelfSaveOKPane

## Status

- Current accepted source file: [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md), `NexusTK/ui/dialogs/SelfSaveOKPane.cpp`.
- This position-1 owning channel emits one guarded `SelfSaveOKPane.h`, includes the complete `TextEditPane.h` before deriving from `TextBoxPane`, and includes `SelfSaveOKPane.h`, `LanguageMan.h`, `BackPane.h`, and `MainUiGraph.h` before exact CPP children. The class adds no fields and preserves the `0x174` size assertion.
- Confirmed local range: [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md)
- Exact source literal: [UID:0003JL][0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString](by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md)
- Current generated destinations: `auto-generated/NexusTK/ui/dialogs/SelfSaveOKPane.cpp` and `.h`.
- Confidence is very strong for inheritance, fieldless size, constructor, sole override, three ABI facets, source ownership, and compile-visible CPP/H dependencies. Original local factory spelling remains a file-level confidence cap.

## Class Purpose

`SelfSaveOKPane` is a fieldless `TextBoxPane`-derived confirmation/status pane. Its constructor builds a fixed-size text box, loads localized string id `61`, inserts the spacer/caption/spacer text sequence, attaches the pane to `g_pBackPane` through `g_mainUiLayerSlots.rootPaneLayerContext`, and schedules a one-second timer that dismisses and deletes the pane.

IDA shows the SelfSaveOKPane construction sequence in three places: the standalone constructor at `0x005147d0`, an inline block in [UID:0000L3][MapPane](by-file/MapPane.md) packet case `0x21`, and a retained no-route helper at [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md).

The accepted source-facing role for [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md) remains `CreateSelfSaveOKPane(int unusedPacket)`. The helper's binary body inlines the constructor work, but class documentation treats the source as `new SelfSaveOKPane` plus success return while keeping constructor and timer body ownership on [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md). Current route evidence does not support moving that helper to MapPane or to the packet dispatcher.

The current generated file is not a safe source-ownership guide. It also emits [UID:0000DK][SpelledPane](by-class/SpelledPane.md) entry-list methods and broad text-edit control methods that have many non-SelfSave callers.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SelfSaveOKPane::SelfSaveOKPane` | `0x005147d0-0x005148d5` | Formal C++ lives on [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md). It emits `TextBoxPane(408, 12, false, 143, 1, NULL)`, three `InsertText` calls in spacer/localized-id-`61`/spacer order, bounds `(14,456)-(422,468)`, attach to `g_pBackPane` / `g_mainUiLayerSlots.rootPaneLayerContext`, and timer id `0` for `1000` ms. |
| `SelfSaveOKPane::OnTimer` | `0x005148e0-0x00514913` | Timer-handler facet method; vtable slot `0x0061e850` points here. It returns `true`; when timer id is zero, it calls inherited `RemoveFromLayer()` through primary slot `+0x38` and scalar-deletes the owner. |
| `CreateSelfSaveOKPane(int unusedPacket)` retained helper | [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md) | Allocates and constructs the same pane sequence in the binary, but is represented source-shaped as `new SelfSaveOKPane` and `return true`; no direct caller/xref/table/pointer route is currently reported. |

## UID0000NN Class And ABI Closure - 2026-08-17

### Fieldless Layout And Source Surface

- Allocation size `0x174` equals the complete `TextBoxPane` base size. Constructor evidence, vtable comparison, and absence of any derived-member access support no additional fields.
- The formal H channel is complete and preserved: one guarded declaration, `TextBoxPane` base visibility through `../controls/TextEditPane.h`, public constructor, protected `virtual bool OnTimer(int,int,int)`, and compile-time `0x174` assertion.
- No explicit derived destructor body is supported. Base destruction is implicit; `delete this` in `OnTimer` uses normal C++ destruction rather than a handwritten scalar-deleting wrapper.

### Vtable And Override Proof

- Primary, secondary, and timer facet bases are `0x0061e7a4`, `0x0061e81c`, and `0x0061e84c`, installed at object offsets `+0`, `+0xa0`, and `+0xa4` by all three construction sites.
- The SelfSaveOKPane facets match `TextBoxPane` target-for-target except timer slot `0x0061e850 -> 0x005148e0`. That one difference proves `OnTimer` is the sole source-authored override.
- Constructor stores occur at MapPane `0x0050855b/61/6b`, factory `0x00513871/77/81`, and standalone constructor `0x00514829/2f/39`. These are compiler vptr writes, not source statements.
- Exact physical RTTI/COL/vtable data belongs to UID0002OU and is regenerated from this class. UID0001YV and UID0002OU carry non-empty covered-by markers instead of raw arrays.

### Construction And Dependencies

- The standalone constructor is `[0x005147d0,0x005148d6)`, SHA256 `AE290E92245D415756A550A0671630670956BEE9FD57A1BBF002E952B00B0FF5`; `OnTimer` is `[0x005148e0,0x00514914)`, SHA256 `0822F38CBBDAF7A51559F3C230B3184409A687DFAD79F35785EC3460850FB0BA`.
- `InsertText` remains owned by TextEditPane, `g_pLanguageMan` by LanguageMan, `g_pBackPane` by BackPane, `rootPaneLayerContext` by MainUiLayerSlots, `AddToLayer`/`RemoveFromLayer` by Pane, and timer scheduling by TimerMgr/TimerHandler. This class only consumes those declarations.
- UID0001AY is a file-local allocation callback; MapPane opcode `0x21` owns only its inline byte duplicate. Neither route changes this class or method ownership.

### Rejected And Historical Routes

The generated SpelledPane aggregation, broad TextEditPane helper ownership, MapPane-child-class theory, extra derived fields, explicit destructor, additional overrides, raw vtable arrays, and raw spacer global are rejected. Existing historical notes remain as provenance, but current class truth is the fieldless declaration and sole timer override above.

### Score Rationale

`94/95` reflects complete compile-visible CPP/H, exact fieldless layout, all three facets and construction groups, sole-override proof, complete child routing, and stable source placement. Completion remains below 95 pending final full-project source audit; confidence reaches 95 because independent layout, vtable, body, and provider evidence agree.

## 2026-06-26 B002 Source-Readiness Sync

- Live MCP session `80de0a67` confirmed the constructor at `0x005147d0` size `0x106`, timer callback at `0x005148e0` size `0x34`, no function at `0x00514914`, next function `sub_514920` at `0x00514920`, and padding bytes before/inside/after the island.
- The accepted [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md) child now carries first-draft source for both `SelfSaveOKPane::SelfSaveOKPane()` and `bool SelfSaveOKPane::OnTimer(int timerId, int, int)`. The stale blanket no-code/95-gate wording no longer applies to this class; remaining caps are exact wrapper/global spelling and final source-placement polish.
- Constructor helper mapping is stable at source level: `TextBoxPane` ctor `0x00595390`, text wrapper `0x0058e270`, language lookup `0x004f0350`, bounds helper `0x004b7c50`, inherited layer attach slot `+0x30` / `0x0055ee10`, and timer scheduling helper `0x005975e0`.
- Vtable bytes and slot data correct the older timer name from `OnTimerExpired` to source-facing `OnTimer`: `0x0061e850` stores `e0 48 51 00` and points at `0x005148e0`; primary slot `0x0061e7dc -> 0x0055ef10` provides the owner detach/remove call used before `delete this`.
- [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md) remains a factory/trigger wrapper, and the `MapPane::HandlePacket` packet case `0x21` inline construction block remains consumer/sibling evidence. Neither is merged into [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md).

## Excluded Generated Ownership

Do not migrate the following ranges as `SelfSaveOKPane` source solely because they appear in `class_SelfSaveOKPane.cpp`:

- `0x0056bca0-0x0056c0da`: entry add/remove/rebuild/parse helpers. IDA callers and the `SpelledPane::UpdateEntriesAndScheduleRefresh` offset adjustment tie these to [UID:0000DK][SpelledPane](by-class/SpelledPane.md) entry storage.
- `0x00572fd0-0x00573231` and `0x00573900-0x00573961`: vector insert/erase machinery for the same SpelledPane entry records. Keep these non-source-facing helpers.
- `0x0058e270-0x005905f0`: broad text-edit/text-box methods with many callers across UI controls. These belong with [UID:0000EO][TextEditPane](by-class/TextEditPane.md), [UID:0000EI][TextBoxPane](by-class/TextBoxPane.md), or a shared text-control source family, not with this class. The constructor may call a source-facing text setter wrapper, but the broad helper family is not owned here.

## Evidence Notes

- IDA MCP on 2026-05-26 confirmed `0x005147d0` and `0x005148e0` as real functions, and still reported no direct executable callers for either in that database snapshot.
- IDA `list_globals` and `xrefs_to` identify [UID:0001YV][SelfSaveOKPane_vtables](by-type/by-vtable/SelfSaveOKPane_vtables.md) at `0x0061e7a4`, `0x0061e81c`, and `0x0061e84c`.
- IDA `xrefs_to 0x005148e0` reports a vtable data reference at `0x0061e850`, matching the timer-handler facet installed at object offset `+0xa4`.
- IDA `xrefs_to` for the SelfSaveOKPane vtable bases reports construction writes from the standalone constructor, [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md), and [UID:0000L3][MapPane](by-file/MapPane.md) packet case `0x21` inline construction.
- 2026-06-23 B004 source-quality implementation: IDA MCP endpoint `http://127.0.0.1:13337/mcp`, session `0b5e057e`, reconfirmed [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md) as `sub_513800`, `char __stdcall(int)`, size `0x120` / 288 bytes (Verified with `int_convert.py`), empty caller list, empty entry xrefs, callee set for allocation/TextBoxPane/text/localization/attach/timer/security-cookie support, and the same construction facts as this class: `0x174` / 372-byte allocation (Verified with `int_convert.py`), vtable stores at `0x00513871`/`0x00513877`/`0x00513881`, spacer refs at `0x00513866`/`0x005138a9`, localized string id `0x3d` / 61 (Verified with `int_convert.py`), rect `(14,456)-(422,468)`, attach through `g_pBackPane` / `g_mainUiLayerSlots[1]`, and 1000 ms timer at object offset `+0xa4`. The read-only PE route scan found zero branch or pointer hits to `0x00513800` while positive controls found live MapPane dispatcher calls and SelfSaveOKPane vtable/string routes, so the helper's first-draft C++ is allowed but capped below final source certainty.
- 2026-06-12 A002 Batch 346 split exact spacer literal [UID:0003JL][0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString](by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md) from the mixed MapPane/resource string island. Live IDA xrefs show the literal used twice in the standalone constructor, twice in the factory/helper, and twice in the MapPane packet-case inline construction block; all six uses implement the same SelfSaveOKPane text-box setup around localized string id `61`.
- 2026-05-26 IDA `py_eval` recheck confirms `0x00508516` is inside `MapPane::HandlePacket` (`0x00507c90`), and the inline block writes vtables at `0x0050855b`, `0x00508561`, and `0x0050856b` before setting localized string id `61`.
- 2026-06-07 A008 IDA `py_eval` enumerated the exact [UID:0002OU][0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData](by-memory/0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData.md) child: primary/secondary/timer RTTI words, all three vtable view starts, the one-slot timer facet at `0x0061e850 -> 0x005148e0`, and the same three construction store groups from `MapPane::HandlePacket`, the factory helper, and the standalone constructor.
- `0x005147d0` calls the [UID:0000EI][TextBoxPane](by-class/TextBoxPane.md) constructor, localized string lookup at `0x004f0350`, and shared text-set helpers.
- IDA caller checks show `0x0056bca0`, `0x0056be20`, and `0x0056c0e0` are called from self-look and system-message paths that use [UID:0000DK][SpelledPane](by-class/SpelledPane.md), not from the `0x005147d0` constructor island.
- 2026-05-26 IDA `py_eval` recheck shows `0x0056bca0` has seven non-SelfSave caller refs and `0x0058e270` has broad UI caller fanout across at least 18 refs, so their current `SelfSaveOKPane` owner is a generated-data artifact.

## Cross-References

- [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md)
- [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md)
- [UID:0003JL][0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString](by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md)
- [UID:0000DK][SpelledPane](by-class/SpelledPane.md)
- [UID:0000EI][TextBoxPane](by-class/TextBoxPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:0001YV][SelfSaveOKPane_vtables](by-type/by-vtable/SelfSaveOKPane_vtables.md)
- [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)

## Changes

- 2026-08-17 B007 UID0000NN accepted callback: raised `92/94` to `94/95`, installed the exact four-include CPP prologue, preserved the complete H payload byte-for-byte, documented the fieldless layout and sole-override proof, and synchronized `InsertText` plus `rootPaneLayerContext` dependencies without re-owning provider APIs.
- 2026-06-26 B002 implementation sync for [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md): raised to `89/88`, recorded that the constructor/timer child now owns first-draft C++, replaced stale `OnTimerExpired` and screen/render-layer wording with `OnTimer`, `g_pBackPane`, and `g_mainUiLayerSlots[1]`, and preserved [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md) factory plus MapPane inline-construction boundaries.
- 2026-06-23 B004 [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md) implementation support sync:
  - Added the accepted `CreateSelfSaveOKPane(int unusedPacket)` helper/factory relationship. The helper may now be represented as `new SelfSaveOKPane` and `return true`, while constructor-detail ownership remains with `SelfSaveOKPane::SelfSaveOKPane`.
  - Preserved the first-draft/no-route cap: fresh MCP and PE scans found no caller/xref/table/pointer route to `0x00513800`, and the live MapPane packet case `0x21` remains a sibling inline construction route rather than this helper's owner.
- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and assigned parent `0000NN`.
  - Before: The compact self-save confirmation pane remained unclassified in autogen coverage even though the class and parent file both met the 80/80 attach gate.
  - After: The class contributes to `SelfSaveOKPane.cpp` as a reconstructable child without emitting final C++ yet.
  - Evidence: Live IDA MCP lookup confirms constructor `0x005147d0`, timer handler `0x005148e0`, and factory/helper `0x00513800`; parent [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md) records the same compact pane island and generated-owner exclusions.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Evidence: the page documents the narrow constructor/timer/factory island, inline construction evidence, vtable references, and polluted generated ownership exclusions; confidence remains medium-high because final source placement is still provisional.
- 2026-06-07 A008 Batch 013 parent-gate refresh:
  - Before: `86/80`, with strong class-island evidence but confidence still capped too low for the corrected vtable-data parent gate.
  - Changed to: `88/86`.
  - Evidence: live IDA re-enumerated the exact SelfSaveOKPane vtable-data child and construction store groups, while existing class/file docs already exclude the generated SpelledPane/TextBoxPane ownership pollution. Final source-file placement remains below final-source quality, but direct class ownership for the vtable-data child is now strong enough for the 85/85 assignment gate.
- 2026-06-12 A002 Batch 346:
  - Score unchanged at `88/86`.
  - Added exact spacer literal [UID:0003JL][0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString](by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md) as class-owned source data. Live IDA confirmed all six xrefs are SelfSaveOKPane construction uses, including the MapPane packet-case inline construction block.
