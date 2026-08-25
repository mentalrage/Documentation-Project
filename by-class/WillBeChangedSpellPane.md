*** UID:0000G6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
struct SpellCommandSlotRecord;

class WillBeChangedSpellPane : public Pane
{
public:
    WillBeChangedSpellPane(Pane *owner,
                           char spellSlot,
                           int y,
                           int x,
                           int pointerY,
                           int pointerX);
    virtual ~WillBeChangedSpellPane();

protected:
    virtual void OnPaintFrame();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    SpellCommandSlotRecord *m_spellRecord;
    char m_spellSlot;
    int m_initialPointerY;
    int m_initialPointerX;
    int m_drawY;
    int m_drawX;
};

typedef char WillBeChangedSpellPaneSizeMustBe272[
    sizeof(WillBeChangedSpellPane) == 0x110 ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WillBeChangedSpellPane
## UID0000LU Header Placement Synchronization - 2026-08-15

The complete accepted WillBeChangedSpellPane declaration was moved verbatim from CPP to H, including the exact six-argument constructor used by NewSpellInventoryPane. Existing constructor/destructor/paint/input children remain unchanged and continue to emit through HelpPanes.

## Status

- Source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md); a dedicated `WillBeChangedPanes.cpp` is rejected absent build/source evidence.
- Address range: [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md), with destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Documentation basis: live IDA function-boundary, decompilation, xref, vtable-slot, and boundary-byte checks through 2026-06-14.
- Confidence: very strong for direct hierarchy, complete 0x110 layout, signatures, method bodies, vtable identity, UserPane record access, compiler split, and HelpPanes placement.

## Class Purpose

`WillBeChangedSpellPane` is a temporary spell preview pane used while changing spell slots. It points into the player spell table, draws the slot key and spell name, tracks cursor-relative movement, and dismisses on relevant mouse or key input.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `WillBeChangedSpellPane` | [UID:0004V9][0x004c7f90-0x004c80c0.WillBeChangedSpellPaneConstructor](by-memory/0x004c7f90-0x004c80c0.WillBeChangedSpellPaneConstructor.md) | Position 10; resolves one-based spell record, builds 160-pixel row, attaches overlay, and localizes pointers. |
| `~WillBeChangedSpellPane` | [UID:0004VA][0x004c80c0-0x004c80df.WillBeChangedSpellPaneDestructor](by-memory/0x004c80c0-0x004c80df.WillBeChangedSpellPaneDestructor.md) | Position 20; authored empty virtual destructor with compiler Pane teardown. |
| `OnPaintFrame` | [UID:0004VB][0x004c80e0-0x004c8244.WillBeChangedSpellPaneOnPaintFrame](by-memory/0x004c80e0-0x004c8244.WillBeChangedSpellPaneOnPaintFrame.md) | Position 30; exact double-key and display-name drawing. |
| `HandlePointerOrMouseEvent` | [UID:0004VC][0x004c8250-0x004c828a.WillBeChangedSpellPaneHandlePointerOrMouseEvent](by-memory/0x004c8250-0x004c828a.WillBeChangedSpellPaneHandlePointerOrMouseEvent.md) | Position 40; dismisses or moves without invalidating. |
| `HandleKeyOrTextEvent` | [UID:0004VD][0x004c8290-0x004c82cf.WillBeChangedSpellPaneHandleKeyOrTextEvent](by-memory/0x004c8290-0x004c82cf.WillBeChangedSpellPaneHandleKeyOrTextEvent.md) | Position 50; translated key-down dismissal except `+`. |
| `ScalarDeletingDestructor` | [UID:0003Z2][0x004ce6d0-0x004ce725.WillBeChangedSpellPaneScalarDeletingDestructor](by-memory/0x004ce6d0-0x004ce725.WillBeChangedSpellPaneScalarDeletingDestructor.md) | Compiler scalar deleting destructor wrapper; tears down pane, optionally deletes storage, and keeps formal C++ blank. |

## Evidence Notes

- 2026-06-14 live IDA `lookup_funcs` confirms method boundaries: constructor `0x004c7f90-0x004c80c0`, reset body `0x004c80c0-0x004c80df`, paint `0x004c80e0-0x004c8244`, mouse input `0x004c8250-0x004c828a`, key input `0x004c8290-0x004c82cf`, and scalar deleting destructor `0x004ce6d0-0x004ce725`.
- IDA xrefs show the constructor called from `0x0057df03` inside `sub_57D9C0`. Paint/mouse/key have vtable-only data refs at `0x0061adc0`, `0x0061adcc`, and `0x0061add0`.
- Constructor decompilation installs three `WillBeChangedSpellPane` vtable views at offsets `+0x00`, `+0xa0`, and `+0xa4`; stores the spell slot byte at `+0xfc`; resolves the spell record pointer through `dword_67A748 + 0x13a78c + 328 * slot`; records position bounds at `+0x100/+0x104/+0x108/+0x10c`; and adjusts placement by current cursor/viewport state.
- Paint decompilation formats the slot key via `sub_5a4090`, draws it twice with opposite text offsets/colors, formats the spell name from the resolved spell record pointer plus `8`, and renders it inside a 160-pixel row.
- Mouse input dismisses on event type `3` through `sub_544690`; event type `0` repositions the pane relative to stored cursor anchors. Key input dismisses when event type `8` arrives and the narrowed key is not `+`.
- The scalar deleting destructor restores the three spell-pane vtable views, calls pane teardown `sub_544580`, and calls delete helper `sub_4f4ac0` only when `(flags & 1) != 0` and `(flags & 4) == 0`.
- Boundary bytes confirm `0x004c8244-0x004c8250`, `0x004c828a-0x004c8290`, `0x004c82cf-0x004c82d0`, and `0x004ce725-0x004ce730` are `0xcc` padding.
- This class is paired with [UID:0000G5][WillBeChangedItemPane](by-class/WillBeChangedItemPane.md) by purpose and memory locality.

## 2026-06-17 Scalar Destructor Wrapper Split

- B003 split [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md) and assigned the exact `0x004ce6d0-0x004ce725` wrapper to [UID:0003Z2][0x004ce6d0-0x004ce725.WillBeChangedSpellPaneScalarDeletingDestructor](by-memory/0x004ce6d0-0x004ce725.WillBeChangedSpellPaneScalarDeletingDestructor.md) at `87/92`, owner/emitter [UID:0000G6].
- Source-facing name is `virtual WillBeChangedSpellPane::~WillBeChangedSpellPane()`. The wrapper and adjustor thunks are compiler ABI output and formal wrapper C++ stays blank.
- The wrapper validates primary vtable slot `0x0061ad7c`, secondary/tertiary views `0x0061adc8/0x0061adf8`, and teardown through shared `Pane::~Pane`; B003 found no proven `WillBeChangedSpellPane` singleton analogous to `g_pWillBeChangedItemPane`.

## Reconstruction Notes

- `RECONSTRUCTABLE:TRUE` and routing through [UID:0000JU][HelpPanes](by-file/HelpPanes.md) are closed by the exact method cluster, complete class declaration, vtable refs, and sole constructor caller.
- The formal declaration is complete and closes before `[[CHILDREN]]`; exact child definitions therefore emit at namespace scope.
- Compiler vptr/base/scalar/EH lowering remains outside human source, and no spell singleton is invented.

## 2026-07-21 B003 Complete Class Closure

- The class is a direct `Pane` subclass. RTTI exposes no direct Singleton descriptor or spell singleton storage; primary/secondary/tertiary compiler views do not imply three source bases.
- Exact layout is inherited Pane `+0x000..+0x0f7`; `SpellCommandSlotRecord *m_spellRecord` at `+0x0f8`; `char m_spellSlot` at `+0x0fc`; natural alignment only at `+0x0fd..+0x0ff`; then pointer Y/X and draw Y/X at `+0x100/+0x104/+0x108/+0x10c`. Total size is `0x110`.
- Sole caller `0x0057df03` allocates `0x110` and proves source arguments owner, signed/plain char spell slot, Y, X, pointer Y, pointer X. The unused owner remains in the signature because the ABI proves it.
- Address algebra `g_pUserPane + 0x13a6ec + 0x148*spellSlot` is exactly `&m_spellCommandSlots[spellSlot-1]`. `SpellCommandSlotRecord::displayName[80]` occupies `+0x08..+0xa7`; existing `prompt[80]` remains `+0xa8`.
- Vtable heads are `0x0061ad7c/0x0061adc8/0x0061adf8`; virtual method cells route UID0004VB/VC/VD at `0x0061adc0/0x0061adcc/0x0061add0`.
- UID0004V9-UID0004VD own the exact five authored definitions. UID0003Z2 remains a false/non-emitting scalar wrapper, and UID00025G remains false physical RTTI/vtable/literal output.
- Source has no explicit vptr stores, Pane destructor call, scalar flags, storage deletion, EH labels, raw record offsets, synthetic padding fields, raw RTTI/vtables, or invented `g_pWillBeChangedSpellPane`.

## Score Rationale

- Completion is `86`: the page now records the full method inventory including the reset helper, exact corrected paint extent, constructor/paint/input/destructor behavior, vtable refs, boundary padding, source placement, and C++ blockers.
- Confidence is `87`: live IDA lookup, decompilation, xrefs, vtable-slot data, and boundary bytes agree. Confidence stays below final-source quality because field/type names and original source-file granularity remain open.

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md)
- [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- [UID:0000DN][SpellInventoryPane](by-class/SpellInventoryPane.md)
- [UID:0003Z2][0x004ce6d0-0x004ce725.WillBeChangedSpellPaneScalarDeletingDestructor](by-memory/0x004ce6d0-0x004ce725.WillBeChangedSpellPaneScalarDeletingDestructor.md)

## Changes

- 2026-06-14 A001 method-boundary/evidence refresh:
  - Before: scored `80/84`; the page had stale recovered-source wording, omitted the `0x004c80c0-0x004c80df` non-deleting reset body, and still used the older `0x004c80e0-0x004c824d` paint extent.
  - After: scored `86/87`; added the reset body, corrected `OnPaint` to `0x004c80e0-0x004c8244`, expanded constructor/paint/input/destructor evidence, and documented active `90/90+` C++ blockers.
  - Evidence: live IDA MCP `lookup_funcs`, `analyze_function`, `xrefs_to`, `get_int`, and `get_bytes` confirm function boundaries, constructor caller `0x0057df03`, vtable refs at `0x0061ad7c/0x0061adc0/0x0061adcc/0x0061add0`, destructor thunk refs, behavior summaries, and padding boundaries.
- 2026-06-17 B003 destructor-wrapper split sync:
  - Added exact scalar wrapper child [UID:0003Z2][0x004ce6d0-0x004ce725.WillBeChangedSpellPaneScalarDeletingDestructor](by-memory/0x004ce6d0-0x004ce725.WillBeChangedSpellPaneScalarDeletingDestructor.md), preserved blank formal C++ policy, and recorded vtable/no-singleton evidence.
- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000JU][HelpPanes](by-file/HelpPanes.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the constructor, paint, mouse, key, and scalar deleting destructor starts at `0x004c7f90`, `0x004c80e0`, `0x004c8250`, `0x004c8290`, and `0x004ce6d0`; the class and parent both pass the 80/80 parent gate. No reconstruction C++ was emitted because the page was below the active code-entry gate.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:84`.
  - Summary/evidence: scored from the spell preview constructor/paint/mouse/key/destructor map, constructor xref, paired item-preview locality, and help/tooltip source grouping caveat.
