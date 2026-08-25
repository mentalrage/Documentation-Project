*** UID:000095 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
struct Rect;

class NewMacroEditControlPane : public ControlPane
{
public:
    NewMacroEditControlPane(wchar_t key, int shortcutIndex, unsigned char spellMode, const Rect &bounds);

    wchar_t GetKey() const;
    unsigned char GetSpellMode() const;
    void SetShortcutIndex(int shortcutIndex);
    void SetKey(wchar_t key);
    void SetSpellMode(unsigned char spellMode);
    void Refresh();

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    int m_shortcutIndex;
    wchar_t m_key;
    unsigned char m_spellMode;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewMacroEditControlPane

## Status

- Confidence: very strong for behavior, vtable identity, natural `0x110` layout, source-module ownership, and [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md) as non-emitting compiler destructor glue.
- EventHandler interface status: secondary `+0x04/+0x08` are source-ready `HandlePointerOrMouseEvent(Event *)` and `HandleKeyOrTextEvent(Event *)`; the complete class declaration now includes both and all other qualified definitions.
- Likely source file: [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- Main address doc: [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- Historical generated-source lead: `source-3/simroot_v2/class_NewMacroEditControlPane.cpp`; stale simroot output is behavior lead material only, not current source authority after the UID0001IK split.
- IDA MCP rechecked: 2026-07-19 direct UID0004AC source-quality pass on evidence session `9b0396a3`, preserving the 2026-07-16 UID0004A6 and earlier class/compiler checks as historical evidence.
- Vtable family: [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md), rechecked on 2026-06-01.

## Functionality

`NewMacroEditControlPane` is the row control used by [UID:000094][NewMacroDialog](by-class/NewMacroDialog.md) for configured number/Ctrl-number shortcut key and item/spell bindings. It stores the signed shortcut ordinal, a `wchar_t` key code unit, and an `unsigned char` spell-mode byte, exposes getter/setter helpers for page load/save, redraws itself after state changes, handles EventHandler key/text assignment, and explicitly returns true for every pointer/mouse event.

## State Fields

| Offset | Meaning |
| --- | --- |
| `+0x108` | `int m_shortcutIndex`, initialized with first-page ordinal `0..9` and rewritten by `SetShortcutIndex` as `page * 10 + row`; signed values `0..19` select number versus Ctrl-number labels. |
| `+0x10c` | `wchar_t m_key`, read by `GetKey` and copied to/from `CompactShortcutRecord::code`. |
| `+0x10e` | `unsigned char m_spellMode`, copied to/from `CompactShortcutRecord::isSpellMode`; zero means item/inventory and any nonzero value means spell/command. |
| `+0x10f-0x110` | natural class-tail alignment; no source padding member. |

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| `GetKey` | [UID:0004A6][0x0057f9b0-0x0057f9b8.NewMacroEditControlPaneGetKey](by-memory/0x0057f9b0-0x0057f9b8.NewMacroEditControlPaneGetKey.md) | Returns the `wchar_t` field at `+0x10c` through AX; sole direct caller `NewMacroDialog::SaveMacroEntries` stores it unchanged into `CompactShortcutRecord::code`. Historical `GetKeyBinding` is a superseded descriptive alias. |
| `GetSpellMode` | [UID:0004A7][0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetSpellMode](by-memory/0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetSpellMode.md) | Exact seven-byte getter returning `m_spellMode` unchanged through AL; sole caller `NewMacroDialog::SaveMacroEntries` stores it into `CompactShortcutRecord::isSpellMode`. Historical `GetMode` and `GetModifier` are superseded aliases. |
| constructor | [UID:0004A8][0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor](by-memory/0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor.md) | Builds a `ControlPane(8)`-derived row and initializes the first-page signed shortcut ordinal `0..9`, `wchar_t` key, and raw unsigned-char spell-mode state from the compact record. |
| `SetShortcutIndex` | [UID:0004A9][0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetShortcutIndex](by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetShortcutIndex.md) | Stores the signed configured-shortcut ordinal `0..19` at `+0x108`; historical `SetRecordIndex` and `SetIndex` are superseded aliases. |
| `SetKey` | [UID:0004AA][0x0057fa40-0x0057fa52.NewMacroEditControlPaneSetKey](by-memory/0x0057fa40-0x0057fa52.NewMacroEditControlPaneSetKey.md) | Stores the `wchar_t` compact-record code at `+0x10c`. Historical `SetKeyBinding` is a superseded descriptive alias. |
| `SetSpellMode` | [UID:0004AB][0x0057fa60-0x0057fa70.NewMacroEditControlPaneSetSpellMode](by-memory/0x0057fa60-0x0057fa70.NewMacroEditControlPaneSetSpellMode.md) | Stores the raw low argument byte unchanged in `m_spellMode`; sole load-page caller performs no bool normalization. Historical `SetMode` and `SetModifier` are superseded aliases. |
| `Refresh` | [UID:0004AC][0x0057fa70-0x0057fa7a.NewMacroEditControlPaneRefresh](by-memory/0x0057fa70-0x0057fa7a.NewMacroEditControlPaneRefresh.md) | Exact ten-byte public source member called once by `NewMacroDialog::LoadMacroPage` after shortcut-index/key/spell-mode updates; it passes inherited `GrafPort::m_visibleBounds` at complete-object `+0x44` to `Pane::InvalidateRect` primary slot `+0x20`. |
| complete-object destructor artifact | [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md) | Non-emitting compiler-retained vtable-restore tail jump to `Pane::~Pane()` at `0x00544580`; no inbound xrefs, no standalone source body, and tied to class declaration/destructor semantics. |
| `OnPaint` | [UID:0004AD][0x0057faa0-0x0057fc76.NewMacroEditControlPaneOnPaint](by-memory/0x0057faa0-0x0057fc76.NewMacroEditControlPaneOnPaint.md) | Paints shortcut label, macro type, display name, and selection frame. |
| `HandleKeyOrTextEvent` | [UID:0004AE][0x0057fc80-0x0057fcff.NewMacroEditControlPaneHandleKeyOrTextEvent](by-memory/0x0057fc80-0x0057fcff.NewMacroEditControlPaneHandleKeyOrTextEvent.md) | EventHandler secondary `+0x08`; in active child 2/3 it accepts ASCII letters, stores key/mode, invalidates this pane, consumes text input, and rejects key-up/nonletter events. |
| `HandlePointerOrMouseEvent` | [UID:0004AF][0x0057fd00-0x0057fd05.NewMacroEditControlPaneHandlePointerOrMouseEvent](by-memory/0x0057fd00-0x0057fd05.NewMacroEditControlPaneHandlePointerOrMouseEvent.md) | EventHandler secondary `+0x04`; five-byte unconditional-true override with one `Event *` argument. |
| adjustor thunks | [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md) | Secondary/tertiary vtable thunks to `0x00580710`. |
| scalar deleting destructor | [UID:0004AV][0x00580710-0x00580765.NewMacroEditControlPaneScalarDeletingDestructor](by-memory/0x00580710-0x00580765.NewMacroEditControlPaneScalarDeletingDestructor.md) | Compiler ABI scalar deleting wrapper; non-emitting no-code child. |

## Evidence Notes

- IDA MCP confirms all listed function starts.
- IDA decompiles `0x0057f9b0` as `return this[134]` and `0x0057f9c0` as `return this[270]`, matching offsets `+0x10c` and `+0x10e`.
- The 2026-07-16 direct getter pass establishes exact UID0004A6 bytes `66 8b 81 0c 01 00 00 c3`, target-byte SHA256 `E530E57FAAED293FEF0A8B0145F6234BED015D7389F78441F4D4C8EB713A3885`, a unique no-wildcard signature, one two-instruction/one-block function, one direct NewMacroDialog save caller at `0x0053f1d2`, and zero target data/vtable xrefs.
- The 2026-07-19 direct UID0004AA setter pass establishes exact bytes `55 8b ec 66 8b 45 08 66 89 81 0c 01 00 00 5d c2 04 00`, byte SHA256 `2302B4D77D447E4A40092F0762F0FF0C3936FD897C4C4B662B67FC9CA4CD7F1D`, a unique six-instruction/one-block body, and the sole NewMacroDialog load call at `0x0053f27e`. It loads the argument's low word, stores exactly two bytes at complete-object `+0x10c`, and returns with `retn 4`.
- UID0004AA's apparent AX result is incidental argument liveness: the sole caller ignores it and overwrites EAX at `0x0053f283` while loading `record.isSpellMode`. The source declaration therefore remains `void SetKey(wchar_t key)`.
- UID0004AA has no alternate caller, target-end xref, callee, data xref, vtable slot, absolute VA/RVA pointer occurrence, or duplicate body. UID0004A9 ends at its start; fourteen `0xcc` bytes at `[0x0057fa52,0x0057fa60)` remain external ignored alignment before UID0004AB.
- `0x0057fa80` is a compiler-retained complete-object destructor artifact for vtable reset/base teardown, not a row behavior method and not a source-authored helper body.
- Historical disabled generated-output/simroot limitation: stale output included only the `0x00580666` adjustor thunk, while the paired `0x0058065b` lacked body text. Current authority is [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md), scalar wrapper [UID:0004AV][0x00580710-0x00580765.NewMacroEditControlPaneScalarDeletingDestructor](by-memory/0x00580710-0x00580765.NewMacroEditControlPaneScalarDeletingDestructor.md), and MCP/vtable evidence confirming both thunks forward to the New scalar deleting destructor.
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md) verifies the `NewMacroEditControlPane` primary/secondary/tertiary vtable views at `0x0062d288-0x0062d328`, including `OnPaint`, `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, the scalar deleting destructor, and the two adjustor-thunk slots.
- [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md) records raw-byte and vtable-store evidence for the non-emitting complete-object destructor artifact, resolving the prior open question about source shape: the exact helper is compiler-generated destructor glue, not row behavior and not standalone MacroDialogs-emitting source C++.
- [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md) records the secondary/tertiary adjustor thunk pair for this class as compiler/vtable support, not independent source behavior.
- 2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed local function sizes for getters, constructor, setters, refresh, teardown helper, `OnPaint`, the methods now identified as `HandleKeyOrTextEvent` and `HandlePointerOrMouseEvent`, and deleting destructor; constructor `0x0057f9d0` is code-referenced by [UID:000094][NewMacroDialog](by-class/NewMacroDialog.md) construction at `0x0053ef2c`.
- Constructor decompilation writes the initial signed shortcut ordinal at `+0x108`, key binding at `+0x10c`, raw spell-mode byte at `+0x10e`, three vtable heads `0x0062d288`, `0x0062d2f0`, `0x0062d320`, and selectable/focus byte `+0xff = 1`, matching the field table and the MacroDialogs owner.
- `OnPaint` decompilation resolves the branch between item and spell macro rows: item rows use [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md) and read `LocalInventorySlotRecord::displayName` at `+0x06`, spell rows use the spell-record table from `dword_67A748`, and the control draws shortcut/type/name text plus the selection frame.
- The method now identified as `HandleKeyOrTextEvent` is secondary cell `0x0062d2f8`: event type 8 queries active child 2/3, narrows A-Z/a-z key values, stores the key at `+0x10c`, writes canonical zero/one to `m_spellMode` with `setz`, invalidates this pane, and returns true; type 10 returns true, while type 9/other non-key events return false. This one canonical writer does not narrow the raw unsigned-byte constructor/load/getter/setter/save contract.
- The method now identified as `HandlePointerOrMouseEvent` is secondary cell `0x0062d2f4`, has exact bytes `b0 01 c2 04 00`, accepts one Event pointer, and always returns true. Historical `IsSelectable() const` and `OnKeyEvent(const KeyEvent &)` names are retained only as superseded provenance.
- EventHandler table order and dispatcher behavior fix these declarations. Allocation, constructor writes, and accessor widths resolve the complete natural class layout; member lexical names remain inferred but no longer justify a blank class marker.
- Xrefs to vtable heads `0x0062d288`, `0x0062d2f0`, and `0x0062d320` are limited to constructor, teardown helper, and deleting destructor vtable restoration, confirming this is a coherent class-local row-control island.
- 2026-06-28 B002 live MCP session `supervisor_20260628_resume` resolved [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md) as class-specific non-emitting destructor glue. Current MCP `lookup_funcs` request `10` reports `0x0057fa80` size `0x1f`/31 bytes, constructor `0x0057f9d0` size `0x5b`, scalar deleting destructor `0x00580710` size `0x55`, `Pane::~Pane()` at `0x00544580` size `0x107`, and same-shape Spell sibling `0x0057f7b0` size `0x1f`.
- Current MCP decompile/disasm for [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md) shows only three vtable stores at `+0x00/+0xa0/+0xa4` to `0x0062d288`, `0x0062d2f0`, and `0x0062d320`, followed by a tail jump to `0x00544580`. `analyze_function` reports no strings, no constants, no callers, no normal callees, and complexity `1`; `xrefs_to 0x0057fa80` reports zero inbound xrefs. `get_bytes` confirms the exact body bytes plus six `0xcc` bytes before the helper and one `0xcc` byte before `OnPaint`.
- Current MCP `xrefs_to` maps each NewMacro vtable view to exactly three stores: constructor stores at `0x0057fa03/0x0057fa09/0x0057fa13`, [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md) stores at `0x0057fa80/0x0057fa86/0x0057fa90`, and scalar deleting destructor stores at `0x00580716/0x0058071c/0x00580726`. The scalar deleting destructor owns delete-flag behavior and is reached by adjustor thunks `0x0058065b` and `0x00580666`, while [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md) has no delete branch.
- `0x00544580` is inherited `Pane::~Pane()` behavior, so `Pane` is the tail callee, not the owner. The accepted [UID:0001IL][0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper](by-memory/0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md) sibling has the same no-route, vtable-restore, tail-jump shape and is already non-emitting compiler-retained complete-object destructor glue.
- Historical 2026-06-28 B010 UID0001DR work tied [UID:00049N][0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries](by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md) and [UID:00049O][0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage](by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md) directly to this row-control API and [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) `m_compactShortcutRecords[20]`. Its generic `GetMode`/`SetMode` and modifier aliases are superseded by `GetSpellMode`/`SetSpellMode`/`m_spellMode`; its historical `SetRecordIndex`/`m_recordIndex` names are superseded by `SetShortcutIndex`/`m_shortcutIndex`. Do not route these NewMacroDialog save/load methods through [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md); that table belongs to `IntegrateMacroDialog` and runtime macro execution.

## Refresh Source Behavior

- UID0004AC is exactly `[0x0057fa70,0x0057fa7a)`, ten bytes `8b 11 8d 41 44 50 ff 52 20 c3`, with target-byte SHA256 `B84326BE49B27E28BFE460034B009BF9787976F75422D964A6ED9ABC0501E4E8`. It is one basic block of complexity one with no frame, branch, EH, explicit result construction, or stack argument.
- The member loads the complete object's primary vptr, forms `this+0x44`, pushes that address, invokes slot `+0x20`, and returns. New primary cell `0x0062d2a8` and Pane base cell `0x00621a08` both resolve the slot to `0x00544800`, current `Pane::InvalidateRect(const RectBounds *)`.
- Current [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md) assigns complete-object `+0x44` to inherited `GrafPort::m_visibleBounds`. The exact source behavior is therefore invalidation of this row's own visible bounds, not a parent refresh.
- UID00049O supplies the sole code xref at `0x0053f294`, immediately after the three state setters. It does not consume EAX; loop bookkeeping overwrites the incidental virtual-call result. The accepted source contract remains public `void Refresh()`.
- There is no target data/vtable xref, endpoint xref, alternate caller, parent-pointer read, alternate receiver, field write, string/global access, direct callee record, null rectangle, branch, allocator, exception, packet, destructor, or resource behavior.
- The same ten bytes occur at seven additional addresses, but their contexts include vtable-only compiler forwarders, owner-specific tails, unreferenced raw ABI evidence, `Pane::Show`, direct-call [UID:0004AK][0x0057ffa0-0x0057ffaa.IntegrateMacroEditControlPaneRefreshDisplay](by-memory/0x0057ffa0-0x0057ffaa.IntegrateMacroEditControlPaneRefreshDisplay.md), and a separate vtable-only comparator. UID0004AC's direct caller and absence from the class vtable establish an ordinary source-authored out-of-line member.
- Six `0xcc` bytes at `[0x0057fa7a,0x0057fa80)` separate this source member from compiler-retained UID0001IM. The target is not merged with its predecessor, padding, or destructor artifact.
- Historical `RequestParentRefresh`, parent-redraw wording, and inherited `m_bounds`/`m_localBounds` aliases are superseded. No parent is read, and current layout authority names `m_visibleBounds`. Raw vtable-call C++, `InvalidateRect(NULL)`, an integer source return, compiler-forwarder/no-code treatment, and Pane/GrafPort ownership transfer are rejected by the complete receiver/argument/caller/source-route evidence.
- `Refresh` remains the highest-probability source spelling from the complete class/caller union and parallel `RefreshDisplay` name. Original symbols are stripped, so lexical uncertainty is reflected in confidence `94`; it does not block the behavior-identical source body or public declaration.

## Wchar Key Type And Compact-Record Lifecycle

- Current [UID:000031][Config](by-class/Config.md) declares each exact four-byte `CompactShortcutRecord` as `wchar_t code`, `unsigned char isSpellMode`, and one byte of natural tail alignment. The twenty-row table begins at Config `+0x28f29c`.
- [UID:00049J][0x0053ed90-0x0053f07f.NewMacroDialogConstructor](by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md) zero-extends `record.code` and supplies it as the first New row constructor argument.
- [UID:00049O][0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage](by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md) loads `record.code`, calls `SetKey`, then loads `isSpellMode`, calls `SetSpellMode`, and refreshes the row.
- The exact page-load call order is `SetShortcutIndex` at `0x0053f26f`, zero-extended `record.code`, UID0004AA `SetKey` at `0x0053f27e`, zero-extended `record.isSpellMode`, `SetSpellMode` at `0x0053f28d`, and `Refresh` at `0x0053f294`. This proves the key setter is the direct storage-to-row boundary and that its return is not source-visible.
- [UID:0004AE][0x0057fc80-0x0057fcff.NewMacroEditControlPaneHandleKeyOrTextEvent](by-memory/0x0057fc80-0x0057fcff.NewMacroEditControlPaneHandleKeyOrTextEvent.md) narrows accepted ASCII input and widens it into `m_key`; [UID:0004AD][0x0057faa0-0x0057fc76.NewMacroEditControlPaneOnPaint](by-memory/0x0057faa0-0x0057fc76.NewMacroEditControlPaneOnPaint.md) zero-extends the same field before normalization.
- [UID:00049N][0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries](by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md) calls `GetKey` and stores returned AX unchanged into `record.code`.
- Profile defaults/load/save and [UID:0003UA][0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey](by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md) preserve the same code-unit field. The source-facing `wchar_t` declaration therefore closes the full storage/UI/runtime lifecycle without changing the two-byte ABI.
- The compact record remains distinct from the thirty `0x108`-byte [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) rows at Config `+0x28f2ec`, which belong to IntegrateMacroDialog and integrated runtime macro execution.

## Spell Mode Byte Lifecycle And Value Domain

- Current [UID:000031][Config](by-class/Config.md) and
  [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md)
  declare `CompactShortcutRecord::isSpellMode` as `unsigned char`.
- NewMacroDialog construction and page load zero-extend that byte and pass it
  unchanged to the constructor or `SetSpellMode`; neither route normalizes to
  `bool`.
- [UID:0004A7][0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetSpellMode](by-memory/0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetSpellMode.md)
  returns the field unchanged, and `SaveMacroEntries` stores returned AL
  unchanged back to `record.isSpellMode`.
- `OnPaint`, profile persistence, and UID0003UA runtime dispatch test zero
  versus nonzero. Zero selects item/inventory; any nonzero value selects
  spell/command.
- The key/text handler's `setz` produces canonical zero/one for interactive
  edits, but arbitrary nonzero values loaded from storage remain preserved.
- `bool`, plain `char`, and an enum are rejected by raw byte transport and the
  absence of normalization, signed use, enum range checks, or one-byte enum
  proof. Historical `uint8_t` is ABI-compatible but source-inferior to the
  existing project-era `unsigned char` record declaration.
- `GetSpellMode`, `SetSpellMode`, and `m_spellMode` distinguish this semantic
  field from inherited Pane render mode and Event keyboard modifiers.

## Shortcut Index Lifecycle And Value Domain

- UID0004A8 receives the row ordinal `0..9` as its second argument and initializes `m_shortcutIndex` directly. UID00049O later computes `page * 10 + row` and calls `SetShortcutIndex` before SetKey, SetSpellMode, and Refresh, closing the signed live domain `0..19`.
- UID0004AD reads the field three times. Values below 10 produce `1..9,0`; values 10 or greater select the Ctrl-number bank and produce `Ctrl+1..Ctrl+9,Ctrl+0`. The field does not identify or point to a `CompactShortcutRecord`; that record is only the load caller's key/spell-mode storage source.
- Exact target bytes, signed caller arithmetic, and signed paint comparison establish an `int`. Byte, word, unsigned, enum, pointer, packed-field, macro-slot, and record-identity alternatives are rejected.
- UID0004A9 has one page-load caller and no vtable, data, pointer, adjustor, or compiler-only route. It is an ordinary public source setter because the caller is the distinct `NewMacroDialog` class and no friendship evidence exists.

## Complete Source Declaration And Layout

- Allocation size is exactly `0x110`. Inherited `ControlPane` ends at `0x108`; `int m_shortcutIndex` at `+0x108`, `wchar_t m_key` at `+0x10c`, and `unsigned char m_spellMode` at `+0x10e` plus natural tail alignment close exactly at `0x110`.
- The declaration contains all ten current qualified source definitions: constructor, two getters, three setters, `Refresh`, `OnPaint`, and the two Event handlers.
- The constructor at [UID:0004A8][0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor](by-memory/0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor.md) writes all three fields and the three class vtable heads and marks the control selectable. The getter/setter widths and complete NewMacroDialog/Config lifecycle independently confirm `int`, `wchar_t`, and `unsigned char`.
- Primary/secondary/tertiary tables at `0x0062d288/0x0062d2f0/0x0062d320` and the constructor allocation prove one coherent `ControlPane`-derived source class.
- The declaration intentionally omits an explicit destructor. [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md) is zero-inbound compiler-retained complete-object glue containing only class-vptr restoration and inherited `Pane` teardown; [UID:0004AV][0x00580710-0x00580765.NewMacroEditControlPaneScalarDeletingDestructor](by-memory/0x00580710-0x00580765.NewMacroEditControlPaneScalarDeletingDestructor.md) is the separate scalar deleting wrapper. With no derived cleanup, inherited virtual destruction is the source cause.
- Source order position `50` follows NewMacroDialog `40` and precedes SpellMacroDialog `60`; the class closes before `[[CHILDREN]]` so its ten definitions emit at namespace scope.

## Autogen Handling

Attach this class to [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) at position `50`. The complete class declaration emits once and child pages own the ten qualified bodies.

[UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md) is excluded from class/file emission as a target-local body. Its formal C++ stays blank by no-code proof: the exact range contains only compiler vptr stores and implicit inherited base destruction, has no inbound route, and the deleting behavior is in the separate scalar deleting destructor wrapper.

## Rejected Alternatives And Score Rationale

- An explicit empty destructor, standalone teardown helper, raw vptr members, explicit padding byte, handwritten scalar/adjustor code, and blank class marker are rejected by the no-derived-cleanup and compiler-glue evidence.
- `GetKeyBinding`/`GetModifier`/`GetMode` and `SetIndex`/`SetKeyBinding`/`SetModifier`/`SetMode` remain historical role aliases. The accepted current names are `GetKey`, `GetSpellMode`, `SetShortcutIndex`, `SetKey`, and `SetSpellMode`. Historical `SetRecordIndex`/`m_recordIndex` is superseded because `+0x108` selects a configured number/Ctrl-number shortcut rather than identifying a compact record; `macroSlot` and `hotkeyIndex` are weaker source spellings.
- Historical `uint16_t` and alternative `unsigned short` key spellings are ABI-compatible but source-inferior to `wchar_t` because direct constructor/load/save/default/persistence/runtime evidence identifies the field as `CompactShortcutRecord::code`. `char`, `int`, enum, pointer, packed-field, raw-offset, and wrapper-accessor alternatives are rejected by the exact two-byte field and ordinary member-call shape.
- Historical `uint8_t m_mode` is ABI-compatible but source-inferior to
  `unsigned char m_spellMode`; `bool`, plain `char`, and enum replacements are
  rejected by the complete raw-byte lifecycle and zero/nonzero consumers.
- `m_key` remains the source-facing row-control field name; `code` remains the storage-record field name. Renaming the row field to `m_code` would discard the UI class vocabulary without stronger evidence.
- `IsSelectable() const` and `OnKeyEvent(const KeyEvent &)` are rejected by the exact EventHandler cells and bodies.
- `RequestParentRefresh`, parent-redraw semantics, `m_bounds`, and `m_localBounds` are retained only as historical rejected assumptions. UID0004AC reads no parent and calls inherited `InvalidateRect` on `m_visibleBounds`.
- Completion `92` reflects complete `0x110` layout, ten declarations, child inventory, source order, exact `wchar_t` compact-record lifecycle, compiler/source destructor split, and exact UID0004AC body/caller/slot/field/source-disposition closure. Confidence `94` reflects exact allocation, writes, widths, target bytes/hash/caller/xrefs, vtables, and independent constructor/load/input/paint/save/runtime consumers; access/member spelling and machine-equivalent private type spellings retain a small inference cap.

## Cross References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:000094][NewMacroDialog](by-class/NewMacroDialog.md)
- [UID:00049N][0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries](by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md)
- [UID:00049O][0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage](by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md)
- [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md)
- [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md)
- [UID:0004A6][0x0057f9b0-0x0057f9b8.NewMacroEditControlPaneGetKey](by-memory/0x0057f9b0-0x0057f9b8.NewMacroEditControlPaneGetKey.md)
- [UID:0004A7][0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetSpellMode](by-memory/0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetSpellMode.md)
- [UID:0004A8][0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor](by-memory/0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor.md)
- [UID:0004A9][0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetShortcutIndex](by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetShortcutIndex.md)
- [UID:0004AA][0x0057fa40-0x0057fa52.NewMacroEditControlPaneSetKey](by-memory/0x0057fa40-0x0057fa52.NewMacroEditControlPaneSetKey.md)
- [UID:0004AB][0x0057fa60-0x0057fa70.NewMacroEditControlPaneSetSpellMode](by-memory/0x0057fa60-0x0057fa70.NewMacroEditControlPaneSetSpellMode.md)
- [UID:0004AC][0x0057fa70-0x0057fa7a.NewMacroEditControlPaneRefresh](by-memory/0x0057fa70-0x0057fa7a.NewMacroEditControlPaneRefresh.md)
- [UID:0004AD][0x0057faa0-0x0057fc76.NewMacroEditControlPaneOnPaint](by-memory/0x0057faa0-0x0057fc76.NewMacroEditControlPaneOnPaint.md)
- [UID:0004AE][0x0057fc80-0x0057fcff.NewMacroEditControlPaneHandleKeyOrTextEvent](by-memory/0x0057fc80-0x0057fcff.NewMacroEditControlPaneHandleKeyOrTextEvent.md)
- [UID:0004AF][0x0057fd00-0x0057fd05.NewMacroEditControlPaneHandlePointerOrMouseEvent](by-memory/0x0057fd00-0x0057fd05.NewMacroEditControlPaneHandlePointerOrMouseEvent.md)
- [UID:0004AV][0x00580710-0x00580765.NewMacroEditControlPaneScalarDeletingDestructor](by-memory/0x00580710-0x00580765.NewMacroEditControlPaneScalarDeletingDestructor.md)
- [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Changes

- 2026-07-19 B005 UID0004AA implementation callback:
  - Preserved `92/94`, UID0000KY owner/emitter, position `50`, the complete executed B003 signed shortcut-index union, the complete B001 unsigned-char spell-mode union, the complete class formal byte-for-byte, exact `0x110` layout, all methods, vtable/compiler evidence, and unrelated history.
  - Added UID0004AA exact bytes/hash, unique six-instruction body, sole load caller and order, ignored-result/source-void proof, no-data/vtable/pointer/duplicate negatives, predecessor/successor alignment, and complete `CompactShortcutRecord::code` load/edit/paint/getter/save/persistence/runtime lifecycle.
  - Retained `SetKey`/`m_key`/`wchar_t` as current source vocabulary; historical integer and key-binding aliases remain explicitly superseded without adding raw offsets, padding members, wrappers, or compiler ABI source.

- 2026-07-16 B001 UID0004A7 implementation callback:
  - Preserved `92/94`, UID0000KY owner/emitter, position `50`,
    reconstructable true, the complete executed B005 `wchar_t` key union,
    `SetRecordIndex`/`m_recordIndex`, every unrelated method, class closure
    before `[[CHILDREN]]`, vtable/compiler support, and prior history.
  - Installed the accepted complete declaration with
    `unsigned char GetSpellMode() const`,
    `void SetSpellMode(unsigned char spellMode)`, and
    `unsigned char m_spellMode`.
  - Added the exact getter/setter/constructor/load/input/paint/save/persistence/
    runtime value-domain union, historicalized generic mode/modifier aliases,
    and preserved arbitrary nonzero byte transport without a bool rewrite.

- 2026-07-16 B003 UID0004A9 implementation callback:
  - Preserved `92/94`, UID0000KY owner/emitter, position `50`, reconstructable true, the complete executed B005 `wchar_t` key union, the executed B001 `GetSpellMode`/`SetSpellMode`/`m_spellMode` unsigned-char union, every unrelated method, class closure before `[[CHILDREN]]`, exact `0x110` layout, vtable/compiler support, and prior history.
  - Replaced the historical record-index vocabulary with public `SetShortcutIndex(int shortcutIndex)` and private `int m_shortcutIndex` at `+0x108`; renamed the constructor parameter without changing ABI or layout.
  - Added the exact constructor/page-load/OnPaint lifecycle, signed `0..19` domain, number/Ctrl-number display semantics, public-access cause, target negative routes, rejected alternatives, and source-placement evidence.

- 2026-07-16 B005 UID0004A6 implementation callback:
  - Raised `91/93` to `92/94`, preserved UID0000KY owner/emitter, position `50`, true, all ten declarations, exact `0x110` layout, class closure before `[[CHILDREN]]`, vtables, implicit virtual-destructor source cause, compiler teardown/scalar/thunk separation, and all unrelated class history.
  - Replaced the provisional `uint16_t` key API/field with layout-neutral `wchar_t`, added the exact target bytes/hash/sole-caller/no-vtable evidence, and synchronized constructor/load/input/paint/save/persistence/runtime `CompactShortcutRecord::code` lifecycle while retaining `GetKey`, `SetKey`, and `m_key`.

- 2026-07-15 B003 UID00049G callback:
  - Raised `85/87` to `91/93`, set position `50`, and installed the complete natural `0x110` declaration with all ten methods and closure before `[[CHILDREN]]`.
  - Added exact field widths/order, natural tail alignment, primary/secondary/tertiary routes, compact-record consumers, and implicit inherited-destructor cause while preserving zero-route compiler glue/scalar/thunk evidence.

- 2026-07-14 B003 UID0004A5 implementation callback: synchronized UID0004AE/UID0004AF validator-renamed links and exact EventHandler `+0x08/+0x04` roles, corrected text/key-up/invalidation behavior, and historicalized `OnKeyEvent`/`IsSelectable` without changing the `85/87` score, UID0000KY route, blank formal, or unrelated New class evidence.
- 2026-06-29 B001 UID0001IK implementation callback: historicalized the active simroot recovered-file line and disabled generated-output thunk wording as stale generated lead material. Linked exact source children [UID:0004A6][0x0057f9b0-0x0057f9b8.NewMacroEditControlPaneGetKey](by-memory/0x0057f9b0-0x0057f9b8.NewMacroEditControlPaneGetKey.md)-[UID:0004AF][0x0057fd00-0x0057fd05.NewMacroEditControlPaneHandlePointerOrMouseEvent](by-memory/0x0057fd00-0x0057fd05.NewMacroEditControlPaneHandlePointerOrMouseEvent.md), kept [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md) no-code complete-object destructor glue, and added scalar deleting wrapper [UID:0004AV][0x00580710-0x00580765.NewMacroEditControlPaneScalarDeletingDestructor](by-memory/0x00580710-0x00580765.NewMacroEditControlPaneScalarDeletingDestructor.md) as a non-emitting compiler ABI child.
- 2026-06-28 B002 implementation callback: incorporated the accepted [UID:0001IM][0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper](by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md) no-code disposition. The method map and evidence now classify the exact range as non-emitting compiler-retained `NewMacroEditControlPane` complete-object destructor glue tied to class declaration/destructor semantics. Constructor, getter, setter, refresh, paint, key, selectable, adjustor thunk, and scalar deleting destructor relationships are preserved.
- 2026-06-28 B010 UID0001DR support sync: linked NewMacroDialog save/load children [UID:00049N][0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries](by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md)-[UID:00049O][0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage](by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md), mapped the accepted child C++ getter/setter names to this page's existing row-control roles, and clarified that compact-record save/load targets `RegistryConfigUserProfileBlock::m_compactShortcutRecords`, not `MacroHotkeyRecord`.
- 2026-06-21 Rule 26 support sync from B006 [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md):
  - Named the item macro display dependency as `LocalInventorySlotRecord::displayName` through `LivingObjectPane::GetInventorySlotAddress`.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed getter/setter/constructor/paint/input/thunk/deleting-destructor starts at `0x0057f9b0`, `0x0057f9c0`, `0x0057f9d0`, `0x0057fa30`, `0x0057fa40`, `0x0057fa60`, `0x0057fa70`, `0x0057fa80`, `0x0057faa0`, `0x0057fc80`, `0x0057fd00`, `0x00580640`, `0x0058065b`, `0x00580666`, and `0x00580710`. Left `AUTOGEN_PARENT_UID` blank because this class confidence is below the 80 attachment gate even though [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) is the likely source-module parent.
- Before: completion/confidence metadata were `0/0` despite detailed behavior, field-offset, method, thunk, and IDA evidence notes.
- Changed to: `COMPLETION:80` and `CONFIDENCE:78`.
- Evidence: the page documents row-control purpose, known state offsets, getter/setter/paint/input methods, teardown helper, adjustor thunks, and vtable family; confidence remains medium because helper/thunk completeness and final handwritten-source boundaries are not fully resolved.
- 2026-06-06: Raised to `82/84` and attached `AUTOGEN_PARENT_UID:0000KY`. Evidence: the MacroDialogs parent is `88/82`, the 2026-06-01 vtable-family page verifies the `NewMacroEditControlPane` vtable views and destructor/adjustor slots, the teardown helper page records raw-byte/vtable-store evidence, and the thunk page classifies the `0x0058065b`/`0x00580666` pair as compiler/vtable support. Final C++ stays blank because the exact source-facing destructor/helper shape remains below the final-source gate.
- 2026-06-14: raised from `82/84` to `85/87` after live IDA MCP session `a001_goal2_class_batch` reconfirmed direct `NewMacroDialog` constructor reachability, constructor field/vtable stores, item-versus-spell paint behavior, key-binding event behavior, vtable restoration xrefs, and destructor/thunk routing. Final C++ stays blank because exact class declaration, member names, and source-facing helper/destructor representation are not yet source-quality.
