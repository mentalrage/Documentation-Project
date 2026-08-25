*** UID:0000DX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "TargetSelectionInputPanes.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "InputPanes.h"

class KeyEvent;
class MouseEvent;
class PacketEvent;

class SpellWhoInputPane : public LineInputPane
{
public:
    explicit SpellWhoInputPane(char spellIndex);
    virtual ~SpellWhoInputPane();

protected:
    virtual bool OnKeyEvent(KeyEvent *event);
    virtual bool OnMouseEvent(MouseEvent *event);
    virtual bool OnObjectListMessage(const PacketEvent *event);

private:
    char m_spellIndex;
};

#endif // NEXUSTK_UI_DIALOGS_TARGETSELECTIONINPUTPANES_H
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SpellWhoInputPane
## UID0000LU Header Completion - 2026-08-15

The complete SpellWhoInputPane declaration now resides in `TargetSelectionInputPanes.h`, with the exact constructor/destructor, key/mouse/object-list overrides, event forward declarations, and one-byte spell index used by the existing children. The CPP includes its owner header and emits only established method/helper children.

## UID0001LM Signed-Index Support Synchronization - 2026-07-19

- [UID:0001KX][0x005ae2a0-0x005ae372.SpellWhoInputPaneConstructor](by-memory/0x005ae2a0-0x005ae372.SpellWhoInputPaneConstructor.md) now uses plain `char spellIndex`, matching repeated `movsx` source semantics and the shared `UserPane::GetSpellPromptText(char) const` interface. Its `m_spellIndex` byte remains at complete-object `+0x108`.
- This bounded support correction does not move the class: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) remains owner/emitter and source route. The complete target-selection body, saved-target globals, navigation/pointer methods, vtable/RTTI/destructor/compiler evidence, blank class formal policy, `87/88` metadata, and every unrelated fact remain unchanged.
- No direct private spell-table access, unsigned index, duplicate class declaration, or `SpellInputPanes.cpp` ownership is introduced.

## Status

- Confidence: strong for class behavior, vtable ownership, exact method bounds, saved spell-target state, and parent routing; medium-high for original file split because spell-cast dispatch code also constructs the pane.
- Likely source file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md); cross-referenced from [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) and spell inventory/cast dispatch paths.
- Address range: [UID:0001KY][0x005ae2a0-0x005aeb1f.SpellWhoInputPane](by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md)
- Current recovered file: `source-3/simroot_v2/class_SpellWhoInputPane.cpp`

## Class Purpose

`SpellWhoInputPane` is the spell-target line-input pane. It prompts for a target, lets the player traverse living map objects with keyboard or mouse input, tracks the selected target id in `s_spellWhoTargetId` / `s_spellWhoSavedTargetId` (`dword_69BF20`), and submits the selected target back to the spell input/dispatch flow.

It is the spell-side counterpart to [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md), [UID:0000CT][SelectObjectWithKeyboardPane](by-class/SelectObjectWithKeyboardPane.md), and [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md).

## Method Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| constructor | [UID:0001KX][0x005ae2a0-0x005ae372.SpellWhoInputPaneConstructor](by-memory/0x005ae2a0-0x005ae372.SpellWhoInputPaneConstructor.md) | Builds the [UID:000077][LineInputPane](by-class/LineInputPane.md) base, installs three vtable views, attaches the spell prompt text, stores the spell index, chooses the initial living target, and highlights it. |
| non-deleting destructor | [UID:0001KZ][0x005ae380-0x005ae403.SpellWhoInputPaneDestructor](by-memory/0x005ae380-0x005ae403.SpellWhoInputPaneDestructor.md) | Resets vtables, clears the active spell target state helper, and calls base cleanup. |
| `OnKeyEvent` | [UID:0001L0][0x005ae410-0x005ae68a.SpellWhoInputPaneKeyNavigationInput](by-memory/0x005ae410-0x005ae68a.SpellWhoInputPaneKeyNavigationInput.md) | Handles Ctrl/modifier and event-kind gates, Enter/Escape base fallback, previous/next target keys, self target, target highlight changes, and targeted-action send. |
| `OnMouseEvent` | [UID:0001L1][0x005ae730-0x005aea53.SpellWhoInputPanePointerSelectionInput](by-memory/0x005ae730-0x005aea53.SpellWhoInputPanePointerSelectionInput.md) | Converts mouse coordinates to map space, handles subtype `1`/`2`, selects/highlights hit living objects, gates immediate submit on target-click config, and queues prompt close. |
| `OnObjectListMessage` | [UID:0001L2][0x005aea60-0x005aeaf3.SpellWhoInputPaneObjectListVirtual](by-memory/0x005aea60-0x005aeaf3.SpellWhoInputPaneObjectListVirtual.md) | Parses underscore-prefixed object-id payloads; when the payload contains the current saved spell target id, it switches selection to the local player. |
| file-local `ClearSpellWhoTarget` | [UID:0001L3][0x005aeb00-0x005aeb1f.DeactivateSavedSpellWhoTarget](by-memory/0x005aeb00-0x005aeb1f.DeactivateSavedSpellWhoTarget.md) | File-local helper under [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) that clears highlight for saved target id `s_spellWhoTargetId`. |
| adjustor thunks | [UID:0001NA][0x005b78fc-0x005b7912.SpellWhoInputPaneAdjustorThunks](by-memory/0x005b78fc-0x005b7912.SpellWhoInputPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks to the scalar deleting destructor; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:0001NK][0x005b8100-0x005b81c4.SpellWhoInputPaneScalarDeletingDestructor](by-memory/0x005b8100-0x005b81c4.SpellWhoInputPaneScalarDeletingDestructor.md) | Delete wrapper; resets vtables, clears active spell target state, calls base cleanup, and frees when requested. |

## B004 Source-Quality Routing

[UID:0001KY][0x005ae2a0-0x005aeb1f.SpellWhoInputPane](by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md) is now a non-emitting split index, not an emitting aggregate. Exact source C++ belongs to the child pages for the constructor, ordinary destructor, key handler, mouse handler, object-list virtual, and file-local clear helper. The broad parent keeps the class browsing/index evidence, boundary evidence, switch-support bytes, padding, and scalar/thunk support facts with a blank formal C++ block.

Source-facing names accepted by the B004 report:

- `s_spellWhoTargetId` / `s_spellWhoSavedTargetId` for `0x0069bf20`.
- `m_spellIndex` for full object offset `+0x108`.
- `SpellWhoInputPane::SpellWhoInputPane(unsigned char spellIndex)`.
- `SpellWhoInputPane::~SpellWhoInputPane()`.
- `bool SpellWhoInputPane::OnKeyEvent(KeyEvent *event)`.
- `bool SpellWhoInputPane::OnMouseEvent(MouseEvent *event)`.
- `bool SpellWhoInputPane::OnObjectListMessage(const PacketEvent *event)`.
- File-local `ClearSpellWhoTarget()` under [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md).

[UID:0001NK][0x005b8100-0x005b81c4.SpellWhoInputPaneScalarDeletingDestructor](by-memory/0x005b8100-0x005b81c4.SpellWhoInputPaneScalarDeletingDestructor.md) remains scalar deleting destructor support with blank formal C++; ordinary destructor source emits through [UID:0001KZ][0x005ae380-0x005ae403.SpellWhoInputPaneDestructor](by-memory/0x005ae380-0x005ae403.SpellWhoInputPaneDestructor.md). [UID:0001NA][0x005b78fc-0x005b7912.SpellWhoInputPaneAdjustorThunks](by-memory/0x005b78fc-0x005b7912.SpellWhoInputPaneAdjustorThunks.md) is already adequate as compiler-generated thunk output with `RECONSTRUCTABLE:FALSE`, owner `NONE`, blank emitter, blank C++, vtable refs, and disassembly proof.

## Evidence Notes

- `simroot_v2` emits the constructor, key handler, pointer handler, and scalar deleting destructor.
- Active generated output omits `0x005ae380`, `0x005aea60`, and `0x005aeb00` from the class file, although `0x005aeb00` exists as a recovered global helper file.
- Disabled generated output lists `0x005b7907` as missing code, but IDA confirms it is a real 0xb adjustor thunk forwarding to `0x005b8100`.
- IDA xrefs to `0x005aeb00` come from the key and pointer handlers. IDA data xrefs place `0x005aea60`, `0x005b78fc`, and `0x005b7907` in `SpellWhoInputPane` vtables.
- 2026-05-26 IDA recheck confirms `0x005b78fc` and `0x005b7907` forward to `0x005b8100` after `this - 0xa0` and `this - 0xa4`; both are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- The destructor selects [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md) or [UID:0000DM][SpellInputPaneState](by-class/SpellInputPaneState.md) flag clearing through the active spell panel state path, so those helpers belong near the target/spell input modules.
- 2026-06-13 live IDA MCP lookup reconfirmed function boundaries: constructor `0x005ae2a0` size `0xd2`, non-deleting destructor `0x005ae380` size `0x83`, key handler `0x005ae410` size `0x27a`, no function at padding `0x005ae690`, pointer handler `0x005ae730` size `0x323`, object-list virtual `0x005aea60` size `0x93`, file-scope saved-target clear helper `0x005aeb00` size `0x1f`, and scalar deleting destructor `0x005b8100` size `0xc4`.
- Live xrefs place the constructor at spell-cast/inventory call sites `0x0057cade`, `0x0057e3f8`, and `0x0057f109`; those are creation paths, not ownership evidence against the target-selection source file.
- Live vtable and RTTI evidence ties the three `SpellWhoInputPane` vtable views at `0x0062f210`, `0x0062f260`, and `0x0062f290` to the constructor/destructors and vtable-only input handlers. The main factory/selection path at `0x005a4530` also writes those vtable addresses before storing the spell index at `this+0x108`.
- Saved spell-target global [UID:0002AB][0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals](by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md) identifies `0x0069bf20` as the SpellWho saved target id; live xrefs from constructor, key, pointer, object-list, and `DeactivateSavedSpellWhoTarget` match the class behavior and separate it from numeric/string/slot spell argument panes.
- B004 2026-06-26 implementation adds the non-emitting [UID:0001KY][0x005ae2a0-0x005aeb1f.SpellWhoInputPane](by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md) split-index policy, records child-page C++ homes, preserves the direct [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) file route, and resolves raw `dword_69BF20`, `this+0x108`, key/mouse/object-list method names, scalar-wrapper policy, and adjustor-thunk policy.

## Score Rationale

- Raised from `86/80` to `87/88` after the 2026-06-13 IDA pass. Completion improves slightly because the page now records the factory path, vtable bases, padding boundary, saved-target global, and direct parent split; confidence clears the Goal 2 gate because exact method children are already `86/90` except ignored compiler thunks.
- Direct parent remains [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), which is already justified at `89/85`. [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) remains a cross-reference because its spell-dispatch and spell-inventory flows allocate or invoke the pane but do not own the target-selection family globals, keyboard/mouse target traversal, or saved-target helper.
- The broad memory index [UID:0001KY][0x005ae2a0-0x005aeb1f.SpellWhoInputPane](by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md) remains an aggregate support page. The class confidence is instead gated by exact function pages, vtable evidence, and the parent file page.

## Cross-References

- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001KY][0x005ae2a0-0x005aeb1f.SpellWhoInputPane](by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md)
- [UID:0001L3][0x005aeb00-0x005aeb1f.DeactivateSavedSpellWhoTarget](by-memory/0x005aeb00-0x005aeb1f.DeactivateSavedSpellWhoTarget.md)
- [UID:0002AB][0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals](by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md)
- [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md)
- [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md)
- [UID:0000CT][SelectObjectWithKeyboardPane](by-class/SelectObjectWithKeyboardPane.md)
- [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md)
- [UID:0000DM][SpellInputPaneState](by-class/SpellInputPaneState.md)
- [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md)

## Changes

- 2026-06-29 B005 UID0000OH direct empty-emitter callback:
  - Score unchanged at `87/88`.
  - Summary/evidence: inserted the accepted formal no-standalone class marker with `[[CHILDREN]]` so child method/helper bodies still emit through this class. This page remains the direct class owner for SpellWho method/helper children under [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md); exact source emission remains on constructor, destructor, key/mouse/object-list, clear-helper, and related child pages, while scalar deleting destructor glue is non-emitting compiler support.
- Before: completion/confidence were `86/80`.
- Changed to: completion `87`, confidence `88`.
- Evidence: added the 2026-06-13 live IDA boundary/xref/vtable pass, parent-gate rationale, saved spell-target global support, spell-dispatch separation from `SpellInputPanes`, and explicit handling of the broad aggregate memory index versus exact method children.
- 2026-06-26 B004 implementation:
  - Score unchanged at `87/88`.
  - Evidence: incorporated [UID:0001KY][0x005ae2a0-0x005aeb1f.SpellWhoInputPane](by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md) as a non-emitting split index, child-page formal C++ homes, `s_spellWhoTargetId` / `s_spellWhoSavedTargetId`, `m_spellIndex`, source-facing method names, file-local `ClearSpellWhoTarget`, scalar-wrapper no-source-C++ policy, and adjustor-thunk already-adequate confirmation.
