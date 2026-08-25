*** UID:0000DQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
struct RectBounds;

class SpellMacroEditControlPane : public ControlPane
{
public:
    SpellMacroEditControlPane(wchar_t spellKey, const RectBounds &bounds);

    wchar_t GetSpellKey() const;

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    wchar_t m_spellKey;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SpellMacroEditControlPane

## Status

- Confidence: very strong for behavior, exact `0x10c` layout, three inherited vtable views, source-module ownership, source declaration, and compiler-only destructor/thunk exclusions.
- Likely source file: [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- Main address doc: [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- Historical generated-source lead: `source-3/simroot_v2/class_SpellMacroEditControlPane.cpp`; stale simroot output is behavior lead material only, not current source authority after the UID0001IK split.
- IDA MCP rechecked: 2026-05-25.
- Vtable family: [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md), rechecked on 2026-06-01.

## Functionality

`SpellMacroEditControlPane` is the spell macro row control used by [UID:0000DP][SpellMacroDialog](by-class/SpellMacroDialog.md). It stores the selected spell key at offset `+0x108`, paints the spell icon/name row, handles EventHandler pointer/mouse and key/text events through its inherited secondary interface, and returns true for every pointer/mouse event.

## Layout

| Offset | Size | Meaning / evidence |
| --- | ---: | --- |
| `+0x000..+0x107` | `0x108` | Inherited `ControlPane` object, including the EventHandler secondary view at `+0xa0`, the tertiary inherited facet at `+0xa4`, and `m_controlFlags` byte at inherited `+0xff`. |
| `+0x108..+0x109` | `0x2` | `wchar_t m_spellKey`; initialized from a persisted legacy-shortcut text row, rewritten by the key/text handler, normalized for display by `OnPaint`, and returned by `GetSpellKey` for direct persistence back to the same wide-character row. |
| `+0x10a..+0x10b` | `0x2` | Natural tail alignment only; not an explicit source member. |

- `SpellMacroDialog` allocates decimal 268 / `0x10c` bytes before both constructor calls, independently closing the layout.
- RTTI complete-object locators encode primary offset `0`, EventHandler secondary offset `+0xa0`, and tertiary offset `+0xa4`; constructor/destructor glue stores the corresponding tables at those inherited positions.
- Multiple inheritance/vtable layout is compiler output from `ControlPane`; R2 uses ordinary single source inheritance and does not declare raw vptrs, synthetic base subobjects, or a padding field.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| `GetSpellKey` | [UID:0004A1][0x0057f750-0x0057f758.SpellMacroEditControlPaneGetSpellKey](by-memory/0x0057f750-0x0057f758.SpellMacroEditControlPaneGetSpellKey.md) | Returns the `wchar_t` field at `+0x108`; the sole caller is `SpellMacroDialog::OnControlCommand`, which stores the result unchanged into `Config::m_legacyShortcutText[row][0]` and writes zero to `[row][1]`. |
| constructor | [UID:0004A2][0x0057f760-0x0057f7a9.SpellMacroEditControlPaneConstructor](by-memory/0x0057f760-0x0057f7a9.SpellMacroEditControlPaneConstructor.md) | Builds a `ControlPane(8)`-derived row and initializes `m_spellKey` from `Config::m_legacyShortcutText[row][0]`. |
| compiler-retained complete-object destructor artifact | [UID:0001IL][0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper](by-memory/0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md) | Reinstalls the three `SpellMacroEditControlPane` vtable pointers and tail-jumps to `Pane::~Pane()` at `0x00544580`; no inbound code/data xrefs, no row behavior, and no standalone source body. |
| `OnPaint` | [UID:0004A3][0x0057f7d0-0x0057f927.SpellMacroEditControlPaneOnPaint](by-memory/0x0057f7d0-0x0057f927.SpellMacroEditControlPaneOnPaint.md) | Draws the spell macro row using player spell data and selection state. |
| `HandleKeyOrTextEvent` | [UID:0004A4][0x0057f930-0x0057f998.SpellMacroEditControlPaneHandleKeyOrTextEvent](by-memory/0x0057f930-0x0057f998.SpellMacroEditControlPaneHandleKeyOrTextEvent.md) | EventHandler `+0x08`: accepts ASCII-letter key-down, stores `m_spellKey`, invalidates this pane, consumes text input, and rejects key-up/nonletter events. |
| `HandlePointerOrMouseEvent` | [UID:0004A5][0x0057f9a0-0x0057f9a5.SpellMacroEditControlPaneHandlePointerOrMouseEvent](by-memory/0x0057f9a0-0x0057f9a5.SpellMacroEditControlPaneHandlePointerOrMouseEvent.md) | EventHandler `+0x04`: unconditional true override with one `Event *` argument. |
| adjustor thunks | [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md) | Secondary/tertiary vtable thunks to `0x00580770`. |
| scalar deleting destructor | [UID:0004AW][0x00580770-0x005807c5.SpellMacroEditControlPaneScalarDeletingDestructor](by-memory/0x00580770-0x005807c5.SpellMacroEditControlPaneScalarDeletingDestructor.md) | Compiler ABI scalar deleting wrapper; non-emitting no-code child. |

## Spell-Key Type And Lifecycle

- Both direct constructor sites load the first `wchar_t` from one of the ten fixed `Config::m_legacyShortcutText` rows and pass that two-byte value with the row rectangle. The constructor stores the value directly at `this+0x108`; no numeric key-index conversion occurs.
- `HandleKeyOrTextEvent` accepts ASCII-letter key-down input, widens the accepted character to the same two-byte field, stores it at `+0x108`, and invalidates the pane. Key-up and nonletter key-down do not modify the field; text input is consumed without inventing another storage representation.
- `OnPaint` reads the same two-byte value, applies the recovered case/letter normalization used by the row display path, and formats the visible shortcut text as a wide character. The display behavior is character semantics, not arithmetic key-index semantics.
- `GetSpellKey` returns the field through AX. `SpellMacroDialog::OnControlCommand` writes that result unchanged to `m_legacyShortcutText[row][0]`, then writes a wide zero terminator to `[row][1]`.
- `SaveUserSettings` persists the legacy shortcut section as ten first-wide-character values through `fputwc`; [UID:0003UJ][0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut](by-memory/0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut.md) reads the same table at runtime as wide-character shortcut state.
- `wchar_t` is therefore the strongest source-facing type for the constructor parameter, getter result, and field. It preserves the observed two-byte x86 layout and AX ABI exactly, while expressing the complete edit/display/save/load/runtime lifecycle. The earlier `unsigned short`/`uint16_t` spellings were reasonable width-only placeholders but are superseded by the character-semantic evidence.

## Evidence Notes

- IDA MCP confirms all listed function starts.
- IDA decompiles `0x0057f750` as a two-byte load from `this+0x108` returned through AX. That width-only decompiler expression is consistent with, but does not override, the stronger `wchar_t` lifecycle evidence.
- `0x0057f7b0` is a destructor-shaped helper rather than behavior unique to spell macro painting or input.
- Historical disabled generated-output/simroot limitation: stale output included only the adjustor thunk at `0x0058067c`, while the paired `0x00580671` lacked body text. Current authority is [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md), the scalar wrapper [UID:0004AW][0x00580770-0x005807c5.SpellMacroEditControlPaneScalarDeletingDestructor](by-memory/0x00580770-0x005807c5.SpellMacroEditControlPaneScalarDeletingDestructor.md), and MCP/vtable evidence confirming both thunks forward to the Spell scalar deleting destructor.
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md) verifies the `SpellMacroEditControlPane` primary/secondary/tertiary vtable views at `0x0062d1e4-0x0062d284`, including `OnPaint`, `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, the scalar deleting destructor, and two adjustor-thunk slots.
- [UID:0001IL][0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper](by-memory/0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md) records raw-byte, vtable-store, no-xref, and tail-jump evidence for a compiler-retained complete-object destructor artifact, resolving the prior open source-facing helper question with a no-code disposition.
- [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md) records the secondary/tertiary adjustor thunk pair for this class as compiler/vtable support, not independent source behavior.
- 2026-06-16 A001 live IDA MCP refresh on database `c001_midiplayer_rdata_20260615` reconfirmed the class-local method set: constructor `0x0057f760` size `0x49` / 73 bytes, `GetSpellKey` size `0x8` / 8 bytes, `OnPaint` size `0x157` / 343 bytes, the method now identified as `HandleKeyOrTextEvent` size `0x68` / 104 bytes, the method now identified as `HandlePointerOrMouseEvent` size `0x5` / 5 bytes, teardown helper size `0x1f` / 31 bytes, and scalar deleting destructor size `0x55` / 85 bytes.
- 2026-07-14 B003 live MCP session `6b2e78f3` fixed the inherited-interface source cause: target bytes `b0 01 c2 04 00`, sole target xref `0x0062d250`, EventHandler secondary COL offset `+0xa0`, and EventDispatcher calls at interface `+0x04/+0x08/+0x0c` prove the pointer/mouse, key/text, and IME declaration order. The key/text body uses event types 8 and 10, writes `m_spellKey`, and calls primary `InvalidateRect(NULL)`; event type 9 returns false.
- The constructor is `0x49` bytes, returns with `ret 8`, receives a `wchar_t` code unit plus rectangle address, calls `ControlPane(8, &bounds)`, stores `m_spellKey`, and initializes inherited `m_controlFlags` to `1`. Its three vptr stores are compiler-generated and intentionally absent from R2/R3.
- The same live pass confirmed direct constructor calls from [UID:0000DP][SpellMacroDialog](by-class/SpellMacroDialog.md) at `0x0053eac5` and `0x0053ec1d`, the sole `GetSpellKey` call at `0x0053ed27`, no direct xrefs to teardown helper `0x0057f7b0`, and scalar deleting destructor xrefs from the two adjustor thunks plus the primary vtable data.
- Live `analyze_component` grouped the three `SpellMacroEditControlPane` vtable globals `0x0062d1e4`, `0x0062d24c`, and `0x0062d27c` as shared constructor/teardown/scalar-destructor state, matching [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md).
- 2026-06-27 B004 accepted review resolves [UID:0001IL][0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper](by-memory/0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md) as non-reconstructable compiler-retained destructor glue owned by this class: `xrefs_to 0x0057f7b0` count `0`; bytes are the exact `0x1f` vtable-store/tail-jump body; and the vtable constants match constructor refs `0x0057f781/0x0057f787/0x0057f791` and scalar-destructor refs `0x00580776/0x0058077c/0x00580786`.
- 2026-06-28 B010 UID0001DR implementation ties [UID:00049H][0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand](by-memory/0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand.md) directly to `GetSpellKey`: the confirm loop reads row controls `2..11`, writes each wide key into [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) `m_legacyShortcutText` at `g_pConfig + 0x28e89c + row * 0x100`, and writes a zero terminator word. The older shorthand that described a generic dirty-save call is superseded: the recovered callback invokes `SaveUserSettings()` only under its separate active-MapPane gate.

## Source-Quality Decision

The class is source-ready through exact R2. Constructor allocation/access evidence closes the `0x10c` layout; EventHandler vtable/dispatcher evidence fixes both inherited override declarations; the constructor/edit/display/save/load/runtime chain closes the `wchar_t` field and API type; and exact child pages supply constructor, paint, getter, pointer/mouse, and key/text definitions through `[[CHILDREN]]`. Public constructor/getter, protected virtual overrides, and private field are conventional source access choices that satisfy all known callers without exposing event implementation as public API. Exact header/access lexical spellings remain inferred and cap the score, but no behavior/layout/emitter/type blocker remains. Historical `unsigned short`, `uint16_t`, `IsSelectable`, `OnKeyEvent`, `SetSelectable`, and blank-class conclusions are retained only as superseded provenance. Destructor helper, adjustor thunks, scalar deleting wrapper, vptr stores, RTTI, and vtables remain compiler-generated no-code consequences rather than declarations/bodies to handwrite.

## Score Rationale

| Metric | Score | Rationale |
| --- | ---: | --- |
| Completion | `92` | The page records purpose, exact `0x10c` layout, inherited facet offsets, complete source declaration, access model, renamed method inventory, child routes, callers, the full `wchar_t` edit/display/persistence/runtime lifecycle, vtable source cause, and compiler-only destructor/thunk exclusions. |
| Confidence | `94` | Allocation, field accesses, constructor stores, AX return, fixed wide-row consumers, `fputwc` persistence, runtime shortcut reads, RTTI/vtables, dispatcher ABI, and exact method bodies converge. Original header placement, access labels, and some lexical spellings remain inferred. |

## Autogen Handling

Attach this class to [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md). R2 emits the complete declaration and places `[[CHILDREN]]` only after the closing `};`, so qualified child definitions remain at namespace scope. Do not emit UID0001IL, UID0001IN, UID0004AW, handwritten vtable/RTTI arrays, or explicit destructor ABI mechanics.

## Cross References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:0000DP][SpellMacroDialog](by-class/SpellMacroDialog.md)
- [UID:00049H][0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand](by-memory/0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand.md)
- [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- [UID:0001IL][0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper](by-memory/0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md)
- [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md)
- [UID:0004A1][0x0057f750-0x0057f758.SpellMacroEditControlPaneGetSpellKey](by-memory/0x0057f750-0x0057f758.SpellMacroEditControlPaneGetSpellKey.md)
- [UID:0004A2][0x0057f760-0x0057f7a9.SpellMacroEditControlPaneConstructor](by-memory/0x0057f760-0x0057f7a9.SpellMacroEditControlPaneConstructor.md)
- [UID:0004A3][0x0057f7d0-0x0057f927.SpellMacroEditControlPaneOnPaint](by-memory/0x0057f7d0-0x0057f927.SpellMacroEditControlPaneOnPaint.md)
- [UID:0004A4][0x0057f930-0x0057f998.SpellMacroEditControlPaneHandleKeyOrTextEvent](by-memory/0x0057f930-0x0057f998.SpellMacroEditControlPaneHandleKeyOrTextEvent.md)
- [UID:0004A5][0x0057f9a0-0x0057f9a5.SpellMacroEditControlPaneHandlePointerOrMouseEvent](by-memory/0x0057f9a0-0x0057f9a5.SpellMacroEditControlPaneHandlePointerOrMouseEvent.md)
- [UID:0004AW][0x00580770-0x005807c5.SpellMacroEditControlPaneScalarDeletingDestructor](by-memory/0x00580770-0x005807c5.SpellMacroEditControlPaneScalarDeletingDestructor.md)
- [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Changes

- 2026-07-16 B005 UID0004A1 implementation callback: raised `91/93` to `92/94`; replaced the provisional `unsigned short` constructor/getter/field declaration with lifecycle-backed `wchar_t`; corrected the sole getter caller to `SpellMacroDialog::OnControlCommand`; documented constructor input, key/text editing, paint normalization, direct legacy-row save, `fputwc` persistence, runtime consumption, and the layout-neutral two-byte ABI; and retained all compiler-only destructor/thunk/vtable exclusions.
- 2026-07-14 B003 UID0004A5 implementation callback: raised `86/88` to `91/93`; installed exact R2; documented the inherited `0x108` span, `m_spellKey` at `+0x108`, natural tail alignment, total `0x10c`, EventHandler `+0xa0` source cause, corrected method names/contracts, access rationale, compiler exclusions, and class-close-before-`[[CHILDREN]]` requirement.
- 2026-06-29 B001 UID0001IK implementation callback: historicalized the active simroot recovered-file line and disabled generated-output thunk wording as stale generated lead material. Linked exact source children [UID:0004A1][0x0057f750-0x0057f758.SpellMacroEditControlPaneGetSpellKey](by-memory/0x0057f750-0x0057f758.SpellMacroEditControlPaneGetSpellKey.md)-[UID:0004A5][0x0057f9a0-0x0057f9a5.SpellMacroEditControlPaneHandlePointerOrMouseEvent](by-memory/0x0057f9a0-0x0057f9a5.SpellMacroEditControlPaneHandlePointerOrMouseEvent.md), kept [UID:0001IL][0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper](by-memory/0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md) no-code complete-object destructor glue, and added scalar deleting wrapper [UID:0004AW][0x00580770-0x005807c5.SpellMacroEditControlPaneScalarDeletingDestructor](by-memory/0x00580770-0x005807c5.SpellMacroEditControlPaneScalarDeletingDestructor.md) as a non-emitting compiler ABI child.
- 2026-06-28 B010 UID0001DR support sync: linked [UID:00049H][0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand](by-memory/0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand.md) to `GetSpellKey` and `RegistryConfigUserProfileBlock::m_legacyShortcutText` storage.
- 2026-06-27 B004 implementation callback: updated [UID:0001IL][0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper](by-memory/0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md) from unresolved teardown-helper source shape to non-emitting complete-object destructor artifact owned by this class. Evidence: exact `0x1f` body, no inbound xrefs, constructor/scalar-destructor vtable-store parity, and tail jump to `Pane::~Pane()` from live IDA MCP session `80de0a67`. Class C++ remains blank only for broader class/source-audit reasons.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Evidence: the page documents row-control behavior, field offset, constructor, paint/key/selectable methods, teardown helper, thunk/scalar-destructor ranges, vtable family, and IDA-confirmed thunk caveats; confidence remains capped by helper/thunk completeness and final teardown ownership.
- 2026-06-05: Marked reconstructable and left unassigned.
- Evidence: live IDA MCP `lookup_funcs` confirms the spell-key getter, constructor, teardown helper, paint, key, selectable, thunk, and scalar deleting destructor anchors from `0x0057f750` through `0x00580770`. The likely parent [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) meets 80/80, but this class confidence is `78`, so the parent UID stays blank.
- 2026-06-06: Raised confidence to `84` and attached the class to [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) under the current canonical-owner/emitter route. Evidence: the MacroDialogs parent is `88/82`, the 2026-06-01 vtable-family page verifies the `SpellMacroEditControlPane` vtable views and destructor/adjustor slots, the teardown helper page records raw-byte/vtable-store evidence, and the thunk page classifies the `0x00580671`/`0x0058067c` pair as compiler/vtable support. Final C++ stays blank because the exact source-facing destructor/helper shape remains below the final-source gate.
- 2026-06-16 A001 class low-confidence refresh: raised from `84/84` to `86/88`. Live IDA MCP reconfirmed method sizes, constructor/getter/destructor xrefs, vtable shared globals, absence of direct teardown-helper callers, and MacroDialogs parent support. Owner/emitter remain [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md); final C++ remains blank pending final destructor-helper representation and class layout names.
